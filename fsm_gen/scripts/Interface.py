from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from typing import List, Dict, Set
from collections import defaultdict
from collections import deque
import math
import re
import itertools
import random
import numpy as np
from scipy.optimize import linear_sum_assignment

@dataclass
class Transition:
    """Transizione di FSM: stato sorgente, destinazione, condizione logica."""
    src: str
    dst: str
    cond: str   # es: "cmd_valid_i & ~flush_req_i" o "1" per incondizionata


class Interface:
    # ------------------------------------------------------------------ #
    # Costruttore
    # ------------------------------------------------------------------ #
    def __init__(self, name: str) -> None:
        """!
        @brief Construct a new Interface.

        @param name Human-readable name/label for this interface instance.
        """
        self.name: str = name

        # Nome base della FSM (nome file)
        self.fsm_name: str | None = None

        # --- Nuove strutture dati principali ---

        # Ingress (input) signals usati nelle condizioni delle transizioni
        self._signals: Set[str] = set()

        # Ordine degli stati (così come nel CSV)
        self.state_order: List[str] = []

        # Nomi dei segnali di uscita (dal CSV)
        self.output_names: List[str] = []

        # Mappa stato -> {out_name: out_value}
        self.outputs_by_state: Dict[str, Dict[str, str]] = {}

        # Mappa sorgente -> lista di transizioni da quello stato
        self.transitions_from: Dict[str, List[Transition]] = defaultdict(list)

        # Mappa stato -> insieme di stati raggiungibili (next states)
        self.graph: Dict[str, Set[str]] = defaultdict(set)

        # Righe di test custom per la testbench (se le usi altrove)
        self.functb: List[str] = []

        # Derived paths (based on repository layout)
        root_dir = Path(__file__).resolve().parents[1]
        self.inputs_dir: Path = root_dir / "inputs"
        self.outputs_dir: Path = root_dir / "outputs"

    # ------------------------------------------------------------------ #
    # Proprietà helper
    # ------------------------------------------------------------------ #

    @property
    def signals(self) -> List[str]:
        """Segnali di ingresso ordinati (solo lettura)."""
        return sorted(self._signals)

    @property
    def states(self) -> List[str]:
        """Lista di stati nell'ordine definito dal CSV."""
        return list(self.state_order)

    @property
    def transitions(self) -> List[Transition]:
        """Tutte le transizioni come lista piatta (solo lettura)."""
        all_t: List[Transition] = []
        for lst in self.transitions_from.values():
            all_t.extend(lst)
        return all_t

    # ------------------------------------------------------------------ #
    # Public API
    # ------------------------------------------------------------------ #

    def read_inputs(self, fsm_name: str) -> None:
        """!
        @brief Read and parse FSM input files.

        This method reads:
          - `<fsm_name>.txt` from `inputs/` as transition description.
          - `<fsm_name>.csv` from `inputs/` as state/output table.
        """
        self.fsm_name = fsm_name

        txt_path = self.inputs_dir / f"{fsm_name}.txt"
        csv_path = self.inputs_dir / f"{fsm_name}.csv"

        if not txt_path.is_file():
            raise FileNotFoundError(f"FSM transition file not found: {txt_path}")
        if not csv_path.is_file():
            raise FileNotFoundError(f"FSM CSV file not found: {csv_path}")

        # Pulisci strutture dati
        self._signals.clear()
        self.state_order.clear()
        self.output_names.clear()
        self.outputs_by_state.clear()
        self.transitions_from.clear()
        self.graph.clear()
        # self.functb la lascio com'è, di solito la compili altrove

        # 1) Transizioni + segnali
        self._parse_txt_file(txt_path)

        # 2) Stati + uscite
        self._parse_csv_file(csv_path)

        # 3) Adjacency (graph)
        self._build_graph()

    # ------------------------------------------------------------------ #
    # Private helpers: parsing TXT/CSV
    # ------------------------------------------------------------------ #

    @staticmethod
    def _normalize_condition(raw_cond: str) -> str:
        """Normalizza operatori logici e spaziatura in una condizione."""
        cond = raw_cond.strip()

        # Parole chiave testuali -> operatori simbolici
        cond = re.sub(r"\bnot\b",  "~", cond)
        cond = re.sub(r"\band\b",  "&", cond)
        cond = re.sub(r"\bor\b",   "|", cond)
        cond = re.sub(r"\bnand\b", "%", cond)
        cond = re.sub(r"\bnor\b",  "*", cond)
        cond = re.sub(r"\bxor\b",  "^", cond)

        # '!' -> '~'
        cond = re.sub(r"!\s*", "~", cond)

        # Spazia parentesi
        for ch in "()[]":
            cond = cond.replace(ch, f" {ch} ")

        # Spazia operatori
        for op in ["&", "|", "~", "%", "*", "^"]:
            cond = cond.replace(op, f" {op} ")

        # Collassa spazi multipli
        tokens = cond.split()
        cond = " ".join(tokens)

        # "~ signal" -> "~signal"
        cond = cond.replace("~ ", "~")

        return cond

    def _parse_txt_file(self, txt_path: Path) -> None:
        """!
        @brief Parse the FSM TXT file.

        Formato generico:
          SRC_STATE -> DST_STATE : "espressione_logica";
        """
        # Regex: SRC -> DST : "COND";
        line_re = re.compile(
            r"""^\s*
                (?P<src>\w+)
                \s*->\s*
                (?P<dst>\w+)
                \s*:\s*
                " (?P<cond> .*? ) "
                \s*;?\s*$
            """,
            re.X,
        )

        identifier_re = re.compile(r"[A-Za-z_]\w*")
        forbidden_tokens = {"not", "and", "or", "nand", "nor", "xor"}

        with txt_path.open("r", encoding="utf-8") as f:
            for line in f:
                stripped = line.strip()
                if not stripped:
                    continue
                if stripped.startswith("#") or stripped.startswith("//"):
                    continue

                m = line_re.match(stripped)
                if not m:
                    raise ValueError(f"Invalid transition line in {txt_path}: {line!r}")
                src = m.group("src")
                dst = m.group("dst")
                raw_cond = m.group("cond")

                cond = self._normalize_condition(raw_cond)

                # Crea Transition e memorizzala
                t = Transition(src=src, dst=dst, cond=cond)
                self.transitions_from[src].append(t)

                # Aggiorna set di segnali
                for token in identifier_re.findall(cond):
                    if token in forbidden_tokens:
                        continue
                    # Dopo normalizzazione, operatori sono (&, |, ~, etc), quindi
                    # tutto ciò che matcha l'identifier è un segnale.
                    self._signals.add(token)

    def _parse_csv_file(self, csv_path: Path) -> None:
        """!
        @brief Parse the FSM CSV file.

        Formato:
            state_name, out0, out1, ...
        Prima riga: header delle uscite.
        """
        raw_lines: List[List[str]] = []

        with csv_path.open("r", encoding="utf-8") as f:
            for line in f:
                parts = re.split(r",|;|\n", line)
                parts = [p.strip() for p in parts if p.strip() != ""]
                if parts:
                    raw_lines.append(parts)

        if not raw_lines:
            raise ValueError(f"CSV file appears to be empty: {csv_path}")

        # Intestazioni: nomi segnali di uscita
        self.output_names = raw_lines[0][1:]

        # Stato -> dizionario uscite
        for row in raw_lines[1:]:
            state_name = row[0]
            out_vals = row[1:]

            if len(out_vals) != len(self.output_names):
                raise ValueError(
                    f"Row for state '{state_name}' has "
                    f"{len(out_vals)} outputs but header has "
                    f"{len(self.output_names)}"
                )

            self.state_order.append(state_name)
            self.outputs_by_state[state_name] = {
                name: val for name, val in zip(self.output_names, out_vals)
            }

    def _build_graph(self) -> None:
        """!
        @brief Build next-states adjacency from transitions_from.
        """
        self.graph.clear()
        for src, t_list in self.transitions_from.items():
            for t in t_list:
                self.graph[src].add(t.dst)

    # ------------------------------------------------------------------ #
    # SystemVerilog generation
    # ------------------------------------------------------------------ #

    def write_sv(self) -> None:
        """!
        @brief Generate a SystemVerilog FSM module + package + gtkw file.
        """
        if self.fsm_name is None:
            raise RuntimeError("read_inputs() must be called before write_sv().")

        self.outputs_dir.mkdir(parents=True, exist_ok=True)
        sv_path = self.outputs_dir / f"{self.fsm_name}.sv"
        sv_path_pkg = self.outputs_dir / f"{self.fsm_name}_pkg.sv"
        gtkw_path = self.outputs_dir / f"{self.fsm_name}.gtkw"
        gtkw_path_tb = self.outputs_dir / f"{self.fsm_name}_tb.gtkw"

        # ------------------------------------------------------------------ #
        #  Package: typedef enum
        # ------------------------------------------------------------------ #
        num_states = max(1, len(self.states))
        dim = max(1, math.ceil(math.log2(num_states)))  # almeno 1 bit
        msb_index = dim - 1

        lines: List[str] = []

        lines.append(f"package {self.fsm_name}_pkg;")
        lines.append("")
        lines.append(f"typedef enum logic [{msb_index}:0] ")
        lines.append("{")

        # Codifica esplicita (0,1,2,..) in binario
        for i, state in enumerate(self.states):
            dim_format = "0" + str(dim) + "b"
            myformat = format(i, dim_format)
            sep = "," if i != len(self.states) - 1 else ""
            lines.append(f"  {state} = {dim}'b{myformat}{sep}")

        lines.append("} state_fsm;")
        lines.append("")
        lines.append("endpackage;")
        lines.append("")

        sv_path_pkg.write_text("\n".join(lines))

        # ------------------------------------------------------------------ #
        #  GTKWave state name mapping (binary -> state_name)
        # ------------------------------------------------------------------ #
        lines = []
        for i, state in enumerate(self.states):
            dim_format = "0" + str(dim) + "b"
            myformat = format(i, dim_format)
            lines.append(f"{myformat} {state}")
        lines.append("")

        gtkw_path.write_text("\n".join(lines))

        #lines = ['[timestart] 0']
        #lines.append('[size] 1241 600 ')
        #lines.append('[pos] -241 -1 ')
        #lines.append('*-20.136848 2265625 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 ')
        #lines.append(f'[treeopen] {self.fsm_name}_tb. ')
        #lines.append('[sst_width] 276 ')
        #lines.append('[signals_width] 198 ')
        #lines.append('[sst_expanded] 1 ')
        #lines.append('[sst_vpaned_height] 157 ')
        #lines.append('@28 ')
        #lines.append(f'{self.fsm_name}_tb.u_{self.fsm_name}.clk_i ')
        #lines.append(f'{self.fsm_name}_tb.u_{self.fsm_name}.rst_ni ')
        #lines.append('@2029 ')
        #lines.append(f'^1 ./sim/{self.fsm_name}.gtkw ')
        #lines.append(f'{self.fsm_name}_tb.u_{self.fsm_name}.state_o[3:0] ')
        #lines.append('[pattern_trace] 1 ')
        #lines.append('[pattern_trace] 0 ')
        #gtkw_path_tb.write_text("\n".join(lines))

        # ------------------------------------------------------------------ #
        #  Module
        # ------------------------------------------------------------------ #
        lines = []

        # Module header
        lines.append(f"module {self.fsm_name} import {self.fsm_name}_pkg::*; (")
        lines.append("  input  logic clk_i,")

        # Add reset only if not already a user signal
        if "rst_ni" not in self.signals:
            lines.append("  input  logic rst_ni,")

        # Input signals (skip constant '1')
        for sig in self.signals:
            if sig != "1":
                lines.append(f"  input  logic {sig},")

        # Output ports
        for out_name in self.output_names:
            lines.append(f"  output logic {out_name},")
        lines.append("  output state_fsm state_o")
        lines.append(");")
        lines.append("")

        # Registered version of each output
        for out_name in self.output_names:
            lines.append(f"  logic {out_name}_d;")
        lines.append("")

        # State registers
        lines.append("  state_fsm current_state, next_state;")
        lines.append("")
        lines.append("  assign state_o = current_state;")
        lines.append("")

        # ------------------------------------------------------------------ #
        # State latching
        # ------------------------------------------------------------------ #
        reset_state = self.states[0]

        lines.append("  // STATE LATCHING")
        lines.append("  always_ff @(posedge clk_i or negedge rst_ni)")
        lines.append("    begin: state_latching")
        lines.append("      if (~rst_ni) begin")
        lines.append(f"        current_state <= {reset_state};")
        lines.append("      end else begin")
        lines.append("        current_state <= next_state;")
        lines.append("      end")
        lines.append("    end")
        lines.append("")

        # ------------------------------------------------------------------ #
        # Output latching
        # ------------------------------------------------------------------ #
        lines.append("  // OUTPUT LATCHING")
        lines.append("  always_ff @(posedge clk_i or negedge rst_ni)")
        lines.append("    begin: output_latching")
        lines.append("      if (~rst_ni) begin")

        # On reset, use the outputs of the reset state
        reset_outputs = self.outputs_by_state[reset_state]
        for out_name in self.output_names:
            reset_val = reset_outputs[out_name]
            lines.append(f"        {out_name} <= 1'b{reset_val};")

        lines.append("      end else begin")
        for out_name in self.output_names:
            lines.append(f"        {out_name} <= {out_name}_d;")
        lines.append("      end")
        lines.append("    end")
        lines.append("")

        # ------------------------------------------------------------------ #
        # Next-state and output logic
        # ------------------------------------------------------------------ #
        lines.append("  // STATE TRANSITION AND OUTPUT DEFINITION")
        lines.append("  always_comb begin")
        lines.append("    next_state = current_state;")

        # default: mantieni gli output dell'attuale stato
        for out_name in self.output_names:
            lines.append(f"    {out_name}_d = 1'b0; // overwritten below per-state")

        lines.append("    unique case (current_state)")

        # Un case-item per stato
        for state in self.states:
            lines.append(f"      {state}: begin")

            t_list = self.transitions_from.get(state, [])
            current_outputs = self.outputs_by_state[state]

            if not t_list:
                # Nessuna transizione: self-loop e outputs dello stato stesso
                lines.append(f"        next_state = {state};")
                for out_name in self.output_names:
                    val = current_outputs[out_name]
                    lines.append(f"        {out_name}_d = 1'b{val};")
                lines.append("      end")
                continue

            # Verifica se esiste una transizione incondizionata (cond == "1")
            unconditional = None
            conditional_list: List[Transition] = []
            for t in t_list:
                if t.cond == "1" and unconditional is None:
                    unconditional = t
                else:
                    conditional_list.append(t)

            if unconditional is not None:
                # Transizione incondizionata: ignora le altre
                dst = unconditional.dst
                dst_outputs = self.outputs_by_state[dst]
                lines.append(f"        next_state = {dst};")
                for out_name in self.output_names:
                    val = dst_outputs[out_name]
                    lines.append(f"        {out_name}_d = 1'b{val};")
                lines.append("      end")
                continue

            # Catena if / else-if / else con le transizioni condizionali
            first = True
            for t in conditional_list:
                dst = t.dst
                dst_outputs = self.outputs_by_state[dst]
                cond = t.cond

                if first:
                    lines.append(f"        if ({cond}) begin")
                else:
                    lines.append(f"        else if ({cond}) begin")

                lines.append(f"          next_state = {dst};")
                for out_name in self.output_names:
                    val = dst_outputs[out_name]
                    lines.append(f"          {out_name}_d = 1'b{val};")
                lines.append("        end")
                first = False

            # Default: rimani nello stesso stato, outputs dello stato
            lines.append("        else begin")
            lines.append(f"          next_state = {state};")
            for out_name in self.output_names:
                val = current_outputs[out_name]
                lines.append(f"          {out_name}_d = 1'b{val};")
            lines.append("        end")
            lines.append("      end")

        # Default case: vai allo stato di reset
        lines.append("      default: begin")
        lines.append(f"        next_state = {reset_state};")
        reset_outputs = self.outputs_by_state[reset_state]
        for out_name in self.output_names:
            val = reset_outputs[out_name]
            lines.append(f"        {out_name}_d = 1'b{val};")
        lines.append("      end")
        lines.append("    endcase")
        lines.append("  end")
        lines.append("")
        lines.append("endmodule")
        lines.append("")

        sv_path.write_text("\n".join(lines))

    # ------------------------------------------------------------------ #
    # Testbench generation
    # ------------------------------------------------------------------ #

    def write_tb(self, f_CLK: int) -> None:
        """!
        @brief Generate a simple SystemVerilog testbench for the FSM.
        """
        if self.fsm_name is None:
            raise RuntimeError("read_inputs() must be called before write_tb().")

        self.outputs_dir.mkdir(parents=True, exist_ok=True)
        tb_path = self.outputs_dir / f"{self.fsm_name}_tb.sv"

        if f_CLK <= 0:
            raise ValueError("f_CLK must be a positive integer (MHz).")

        period_ns = 1000.0 / float(f_CLK)

        lines: List[str] = []

        lines.append("// Timescale")
        lines.append("`timescale 1ns/1ps")
        lines.append("")
        lines.append(f"import {self.fsm_name}_pkg::*;")
        lines.append("")
        lines.append(f"module {self.fsm_name}_tb;")
        lines.append("")
        lines.append(f"  parameter real CLK_PERIOD = {period_ns};")
        lines.append("")
        lines.append("  logic clk_i;")
        lines.append("  logic rst_ni;")

        # Input stimuli (skip constant '1')
        for sig in self.signals:
            if sig != "1":
                lines.append(f"  logic {sig};")

        # Outputs
        for out_name in self.output_names:
            lines.append(f"  logic {out_name};")

        lines.append("  state_fsm state_o;")
        lines.append("")
        lines.append(f"  {self.fsm_name} u_{self.fsm_name} (")
        lines.append("    .clk_i,")
        lines.append("    .rst_ni,")
        for sig in self.signals:
            if sig != "1":
                lines.append(f"    .{sig},")
        for out_name in self.output_names:
            lines.append(f"    .{out_name},")
        lines.append("    .state_o")
        lines.append("  );")
        lines.append("")

        # Dump VCD
        lines.append("  // Dump VCD")
        lines.append("  initial begin")
        lines.append("    `ifndef SYN")
        lines.append(f'      $dumpfile("sim/{self.fsm_name}_tb.vcd");')
        lines.append("    `else")
        lines.append(f'      $dumpfile("sim/{self.fsm_name}_syn_tb.vcd");')
        lines.append("    `endif")
        lines.append(f"    $dumpvars(0, {self.fsm_name}_tb);")
        lines.append("  end\n")

        # Clock generation
        lines.append("  // Clock generation")
        lines.append("  initial begin")
        lines.append("    forever #(CLK_PERIOD/2) clk_i = ~clk_i;")
        lines.append("  end")
        lines.append("")

        # Simple reset + stop sequence
        lines.append("  initial begin")
        lines.append("    clk_i = 1'b0;")
        lines.append("    rst_ni = 1'b0;")
        for sig in self.signals:
            if sig != "1":
                lines.append(f"    {sig} = 1'b0;")
        lines.append("")
        lines.append("    // Apply reset and basic stimulus here as needed.")
        lines.append("    #(CLK_PERIOD*8);")
        lines.append("    rst_ni = 1'b1;")
        lines.append("    #(CLK_PERIOD*1.5);\n")

        for line in self.functb:
            lines.append(line)

        lines.append("    #(CLK_PERIOD) $finish;")
        lines.append("")
        lines.append("  end")
        lines.append("")
        lines.append("endmodule")
        lines.append("")

        tb_path.write_text("\n".join(lines))

    # ------------------------------------------------------------------ #
    # Graphviz DOT generation
    # ------------------------------------------------------------------ #

    def write_gv(self) -> None:
        """!
        @brief Generate a Graphviz DOT file from the parsed FSM.
        """
        if self.fsm_name is None:
            raise RuntimeError("read_inputs() must be called before write_gv().")

        self.outputs_dir.mkdir(parents=True, exist_ok=True)
        gv_path = self.outputs_dir / f"{self.fsm_name}.gv"

        lines: List[str] = []
        lines.append(f"digraph {self.fsm_name} ")
        lines.append("{\n")

        for src, t_list in self.transitions_from.items():
            for t in t_list:
                # Escapa eventuali doppi apici nella condizione
                label = t.cond.replace('"', '\\"')
                lines.append(
                    f'  {src} -> {t.dst} [ label = "{label}" ];\n'
                )

        lines.append("}\n")

        gv_path.write_text("".join(lines))
    ########
    # ATPG #
    ########
    def extract_signals(self, expr: str) -> list[str]:
        """
        Find all unique signal names in the boolean expression.
        Signal names are assumed to be identifiers: [a-zA-Z_][a-zA-Z0-9_]*
        """
        tokens = re.findall(r'\b[a-zA-Z_]\w*\b', expr)
        return sorted(set(tokens))

    def to_python_expr(self, expr: str) -> str:
        """
        Convert HDL-style boolean expr to a safe Python expression using booleans.
        Supported ops:
            &  -> and
            |  -> or
            ^  -> !=  (xor for booleans)
            !, ~ -> not
        """
        py = expr

        # NOT first, to avoid messing replacements that introduce !
        py = re.sub(r'~', ' not ', py)
        py = re.sub(r'!', ' not ', py)

        # Binary operators
        py = py.replace('&', ' and ')
        py = py.replace('|', ' or ')
        # XOR: boolean xor is same as != for True/False
        py = py.replace('^', ' != ')

        return py

    def print_truth_table(self, expr: str) -> None:
        signals, rows = self._truth_table_full(expr)
        # Header
        header = " | ".join(signals) + " || OUT"
        print(header)
        print("-" * len(header))
        for env, res in rows:
            vals = " | ".join("1" if env[s] else "0" for s in signals)
            out  = "1" if res else "0"
            print(f"{vals} || {out}")

    def _truth_table_full(self, expr: str):
        """
        Versione completa: restituisce tutte le combinazioni per debug/print.
        """
        signals = self.extract_signals(expr)
        py_expr = self.to_python_expr(expr)

        rows = []
        for combo in itertools.product([False, True], repeat=len(signals)):
            env = dict(zip(signals, combo))
            result = eval(py_expr, {"__builtins__": None}, env)
            rows.append((env, bool(result)))
        return signals, rows

    def truth_table(self, expr: str, want_true: bool):
        """
        Trova UNA combinazione di ingressi che rende l'espressione vera o falsa.

        Args:
            expr: espressione booleana (stile HDL/normalized).
            want_true: se True, cerca una combinazione con risultato 1;
                       se False, cerca una combinazione con risultato 0.

        Returns:
            signals: lista dei nomi dei segnali
            vals: lista di '0'/'1' per ciascun segnale (una sola riga)
        """
        signals = self.extract_signals(expr)
        py_expr = self.to_python_expr(expr)

        for combo in itertools.product([False, True], repeat=len(signals)):
            env = dict(zip(signals, combo))
            result = bool(eval(py_expr, {"__builtins__": None}, env))
            if (want_true and result) or (not want_true and not result):
                vals = ["1" if env[s] else "0" for s in signals]
                return signals, vals

        # Nessuna combinazione soddisfa il criterio: fallback tutto a 0
        return signals, ["0"] * len(signals)

    def choose_edge(self, actual_state: str) -> tuple[str, int, list[int]]:
        """
        Sceglie in modo random una transizione USCENTE dallo stato corrente.

        Ritorna:
            - stato di destinazione scelto,
            - indice globale della transizione scelta (nella lista self.transitions),
            - lista di indici globali delle altre transizioni con stessa sorgente
              ma destinazione diversa (usate per "no trigger").
        """
        t_list = self.transitions_from.get(actual_state, [])
        if not t_list:
            raise RuntimeError(f"No outgoing transitions from state '{actual_state}'")

        # Scegli una transizione random come "trigger"
        chosen_t = random.choice(t_list)
        chosen_dst = chosen_t.dst

        # Trova indice globale della transizione scelta
        chosen_idx = None
        other_indices: list[int] = []

        for idx, t in enumerate(self.transitions):
            if t.src != actual_state:
                continue
            if t.dst == chosen_dst and t.cond == chosen_t.cond and chosen_idx is None:
                chosen_idx = idx
            elif t.dst != chosen_dst:
                # altre destinazioni dalla stessa sorgente: "no trigger"
                other_indices.append(idx)

        if chosen_idx is None:
            raise RuntimeError("Internal error: chosen transition index not found.")

        # Marca l'arco come preso
        self.arcs[chosen_idx] = 1

        #print(actual_state, chosen_t.dst, chosen_idx, other_indices)
        return chosen_t.dst, chosen_idx, other_indices

    def set_inputs(self, idx: int, idxs: list[int]) -> tuple[dict, list[dict]]:
        """
        Calcola una configurazione di ingressi che:
          - ATTIVA la transizione idx (trigger)
          - DISATTIVA ciascuna transizione in idxs (no-trigger).
        """
        # Trigger: espressione della transizione scelta
        expr_trigger = self.transitions[idx].cond
        signals, vals = self.truth_table(expr_trigger, True)
        mydict_trigger = dict(zip(signals, vals))

        # No trigger: per ogni altra transizione, una combinazione che la rende falsa
        mydict_notrigger_list: list[dict] = []
        for i in idxs:
            expr_notrig = self.transitions[i].cond
            signals_nt, vals_nt = self.truth_table(expr_notrig, False)
            mydict_notrigger = dict(zip(signals_nt, vals_nt))
            mydict_notrigger_list.append(mydict_notrigger)

        return mydict_trigger, mydict_notrigger_list

    def merge_input_setting(self, input_setting_trig: dict, input_setting_notrig: list[dict]) -> dict:
        """
        Merge tra:
          - dizionario che soddisfa la transizione target
          - lista di dizionari che disattivano altre transizioni.
        In caso di conflitti vince input_setting_trig.
        """
        not_in_target = [
            {k: v for k, v in d.items() if k not in input_setting_trig}
            for d in input_setting_notrig
        ]
        merged = input_setting_trig.copy()
        for d in not_in_target:
            merged.update(d)
        return merged

    def append_func_tb(self, sig_dict: dict, idx: int) -> None:
        """
        Aggiunge al testbench una sequenza che applica gli ingressi
        e verifica che la FSM passi alla destinazione prevista.
        """
        t = self.transitions[idx]
        mystr  = f'    // {t.src} -> {t.dst} : "{t.cond}"\n'
        for k, v in sig_dict.items():
            mystr += f"    {k} = 1'b{v};\n"
        mystr += "    #(CLK_PERIOD);\n"
        mystr += f"    assert (u_{self.fsm_name}.state_o == {t.dst})\n"
        mystr += f'      else $fatal(1, "{t.src} -> {t.dst} failed: state_o=%0d", u_{self.fsm_name}.state_o);\n'
        self.functb.append(mystr)

    def eulerian_tour(self, adj, start):
        local = {u: list(vs) for u, vs in adj.items()}  # copia mutabile
        stack = [start]
        circuit = []

        while stack:
            v = stack[-1]
            if local[v]:
                u = local[v].pop()   # consuma un arco v->u
                stack.append(u)
            else:
                circuit.append(stack.pop())

        circuit.reverse()
        return circuit    # lista di stati

    def reconstruct_path(self, src, dst, parent):
        """Ricostruisce il cammino minimo src→dst usando il dizionario parent della BFS da src."""
        if src == dst:
            return [src]
        if parent[dst] is None:
            raise ValueError(f"Nessun path da {src} a {dst}")
    
        path = [dst]
        v = dst
        while v != src:
            v = parent[v]
            if v is None:
                raise ValueError(f"Nessun path da {src} a {dst}")
            path.append(v)
    
        path.reverse()
        return path
    
    def bfs(self, src):
        dist   = {v: float("inf") for v in self.states}
        parent = {v: None           for v in self.states}
        dist[src] = 0
        q = deque([src])
        while q:
            #print(q)
            u = q.popleft()
            for v in self.graph[u]:
                if dist[v] == float("inf"):   # non ancora visitato
                    dist[v] = dist[u] + 1
                    parent[v] = u
                    q.append(v)
        return dist, parent
    
    def chineese_postman(self):
        """TODO: Docstring for chineese_postman.
        :returns: TODO

        """
        #print(self.graph)
        # outdeg
        outdeg = {v: len(self.graph.get(v, ())) for v in self.states}
        # indeg
        indeg = defaultdict(int)
        for u, targets in self.graph.items():   # per ogni stato sorgente u
            for v in targets:              # per ogni stato di arrivo v
                indeg[v] += 1              # c'è un arco u -> v, quindi indeg(v)++
        # Balance
        b = {v: indeg[v] - outdeg[v] for v in self.states}
        #for v in self.states:
        #    print(f"{v:10s} indeg={indeg[v]}  outdeg={outdeg[v]}  b={b[v]}")        
        # Understand the path to computr bfs
        P = [v for v in self.states if b[v] > 0]
        N = [v for v in self.states if b[v] < 0]
        #print(P)
        #print(N)
        # matrice dei costi: distanza minimo cammino da p a n
        cost = {}
        parents = {}
         
        for p in P:
            dist, parent = self.bfs(p)   # BFS da p
            parents[p] = parent
            for n in N:
                cost[(p, n)] = dist[n]   # potrebbe essere inf se non raggiungibile
        positives = {}
        for s in P:
            positives[s] = b[s]
        negatives = {}
        for s in N:
            negatives[s] = b[s]
        # 3) Esplodi i nodi positivi in "unità"
        pos_units = []  # es: [("IDLE",0), ("IDLE",1), ("IDLE",2), ("WAIT_CMD",0)]
        for p, cap in positives.items():
            for _ in range(cap):
                pos_units.append(p)
        neg_units = []
        for n, cap in negatives.items():
            for _ in range(-cap):
                neg_units.append(n)
        
        # Controllo: dobbiamo avere tante unità quanti negativi
        assert len(pos_units) == len(negatives)
        
        # 4) Costruiamo la matrice dei costi (righe = pos_units, colonne = negatives)
        cost_matrix = np.zeros((len(pos_units), len(negatives)), dtype=int)
        
        for i, p in enumerate(pos_units):
            for j, n in enumerate(negatives):
                cost_matrix[i, j] = cost[(p, n)]
        
        # 5) Risolviamo il problema di assegnamento (Hungarian)
        row_ind, col_ind = linear_sum_assignment(cost_matrix)
        
       # 6) Costruisci la lista di assegnamenti (p -> n)
        assignments = []
        for i, j in zip(row_ind, col_ind):
            p = pos_units[i]      # nome del nodo positivo
            n = neg_units[j]      # nome del nodo negativo
            assignments.append((p, n))
        #print(assignments)
        
        # Debug
        print("Assegnamenti minimi:")
        total_cost = 0
        for p, n in assignments:
            c = cost[(p, n)]
            total_cost += c
            print(f"{p} -> {n}, costo {c}") 
       # 1. inizializza il multigrafo con 1 per ogni arco originale
        edges_mult = defaultdict(int)
        
        for u in self.states:
            for v in self.graph[u]:
                edges_mult[(u, v)] += 1
        
        # 2. per ogni assegnamento p->n, ricostruisci path e duplica archi
        for p, n in assignments:
            parent = parents[p]
            path = self.reconstruct_path(p, n, parent)
            # duplica tutti gli archi del path
            for u, v in zip(path, path[1:]):
                edges_mult[(u, v)] += 1 
        multi_adj = defaultdict(list)

        for (u, v), k in edges_mult.items():
            multi_adj[u].extend([v] * k)
        
        # assicurati che ogni stato esista come chiave, anche se senza uscite
        for s in self.states:
            multi_adj.setdefault(s, [])

        self.tour = self.eulerian_tour(multi_adj, start="RESET")  # o lo stato iniziale che vuoi
        print("Chinese Postman tour:")
        print(" -> ".join(self.tour))
        

    def states_walkthrough(self) -> None:
        """
        Genera una sequenza di stimoli che prova a percorrere tutti gli archi
        (transizioni) della FSM almeno una volta.
        """
        self.functb = []
        self.all_arcs_taken = False

        # Un bit per ogni transizione globale
        num_arcs = len(self.transitions)
        self.arcs = [0] * num_arcs

        # Stato iniziale: il primo in self.states (stato di reset)
        actual_state = self.states[0]
        iterations = 0
        #self.chineese_postman()

        while not self.all_arcs_taken:
            idx_state = self.states.index(actual_state)  # se ti serve per debug
            # Scegli un arco in uscita dallo stato corrente
            next_state, idx, idxs = self.choose_edge(actual_state)
            # Calcola configurazioni di input per trigger/no-trigger
            input_setting_trig, input_setting_notrig = self.set_inputs(idx, idxs)
            input_setting = self.merge_input_setting(input_setting_trig, input_setting_notrig)
            # Appendi al testbench
            self.append_func_tb(input_setting, idx)

            # Aggiorna stato corrente
            actual_state = next_state
            iterations += 1

            if self.arcs == [1] * num_arcs:
                self.all_arcs_taken = True
                print(f"Number of iterations: {iterations}")

