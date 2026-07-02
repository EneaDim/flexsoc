#!/usr/bin/env python3
# Copyright 2025 Enea Dimroci
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""
@file interface.py
@brief Core FSM interface representation and algorithms used by the generator.

This module defines the Transition dataclass and the Interface class, which
store and manipulate FSM descriptions (states, transitions, signals, outputs)
and provide helper data structures such as adjacency graphs and testbench
generation support.
"""

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
    """Transition of FSM: source, destination and condition."""
    src: str
    dst: str
    cond: str


class Interface:
    def __init__(
        self,
        name: str,
        *,
        inputs_dir: Path | None = None,
        outputs_dir: Path | None = None,
    ) -> None:
        """!
        @brief Construct a new Interface.

        @param name Human-readable name/label for this interface instance.
        @param inputs_dir Optional directory containing <fsm>.txt and <fsm>.csv.
                          If omitted, falls back to the bundled repo-local inputs dir.
        @param outputs_dir Optional directory where generated artifacts are written.
                           If omitted, falls back to the bundled repo-local outputs dir.
        """
        self.name: str = name
        self.fsm_name: str | None = None
        # Signals used in each transition
        self._signals: Set[str] = set()
        # States
        self.states: List[str] = []
        # Output names
        self.output_names: List[str] = []
        # Output values in each state
        self.outputs_by_state: Dict[str, Dict[str, str]] = {}
        # Dict of transitions: src, dst, cond
        self.transitions_from: Dict[str, List[Transition]] = defaultdict(list)
        # Map src -> next_states
        self.graph: Dict[str, Set[str]] = defaultdict(set)
        # TB lines generated
        self.functb: List[str] = []

        # Repository-local default layout used when directories are omitted
        root_dir = Path(__file__).resolve().parents[1]
        default_inputs_dir = root_dir / "inputs"
        default_outputs_dir = root_dir / "outputs"

        self.inputs_dir: Path = (
            Path(inputs_dir).expanduser().resolve()
            if inputs_dir is not None
            else default_inputs_dir.resolve()
        )
        self.outputs_dir: Path = (
            Path(outputs_dir).expanduser().resolve()
            if outputs_dir is not None
            else default_outputs_dir.resolve()
        )

    # ------------------------------------------------------------------ #
    # Proprietà helper
    # ------------------------------------------------------------------ #

    @property
    def signals(self) -> List[str]:
        """Segnali di ingresso ordinati (solo lettura)."""
        return sorted(self._signals)

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
          - `<fsm_name>.txt` from inputs_dir as transition description.
          - `<fsm_name>.csv` from inputs_dir as state/output table.
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
        self.states.clear()
        self.output_names.clear()
        self.outputs_by_state.clear()
        self.transitions_from.clear()
        self.graph.clear()

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

        cond = re.sub(r"\bnot\b", "~", cond)
        cond = re.sub(r"\band\b", "&", cond)
        cond = re.sub(r"\bor\b", "|", cond)
        cond = re.sub(r"\bnand\b", "%", cond)
        cond = re.sub(r"\bnor\b", "*", cond)
        cond = re.sub(r"\bxor\b", "^", cond)

        cond = re.sub(r"!\s*", "~", cond)

        for ch in "()[]":
            cond = cond.replace(ch, f" {ch} ")

        for op in ["&", "|", "~", "%", "*", "^"]:
            cond = cond.replace(op, f" {op} ")

        tokens = cond.split()
        cond = " ".join(tokens)
        cond = cond.replace("~ ", "~")

        return cond

    def _parse_txt_file(self, txt_path: Path) -> None:
        """!
        @brief Parse the FSM TXT file.

        Formato generico:
          SRC_STATE -> DST_STATE : "espressione_logica";
        """
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

                t = Transition(src=src, dst=dst, cond=cond)
                self.transitions_from[src].append(t)

                for token in identifier_re.findall(cond):
                    if token in forbidden_tokens:
                        continue
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

        self.output_names = raw_lines[0][1:]

        for row in raw_lines[1:]:
            state_name = row[0]
            out_vals = row[1:]

            if len(out_vals) != len(self.output_names):
                raise ValueError(
                    f"Row for state '{state_name}' has "
                    f"{len(out_vals)} outputs but header has "
                    f"{len(self.output_names)}"
                )

            self.states.append(state_name)
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

        num_states = max(1, len(self.states))
        dim = max(1, math.ceil(math.log2(num_states)))
        msb_index = dim - 1

        lines: List[str] = []

        lines.append(f"package {self.fsm_name}_pkg;")
        lines.append("")
        lines.append(f"typedef enum logic [{msb_index}:0] ")
        lines.append("{")

        for i, state in enumerate(self.states):
            dim_format = "0" + str(dim) + "b"
            myformat = format(i, dim_format)
            sep = "," if i != len(self.states) - 1 else ""
            lines.append(f"  {state} = {dim}'b{myformat}{sep}")

        lines.append("} state_fsm;")
        lines.append("")
        lines.append("endpackage;")
        lines.append("")

        sv_path_pkg.write_text("\n".join(lines), encoding="utf-8")

        lines = []
        for i, state in enumerate(self.states):
            dim_format = "0" + str(dim) + "b"
            myformat = format(i, dim_format)
            lines.append(f"{myformat} {state}")
        lines.append("")

        gtkw_path.write_text("\n".join(lines), encoding="utf-8")
        gtkw_path_tb.write_text("", encoding="utf-8")

        lines = []
        lines.append(f"module {self.fsm_name} import {self.fsm_name}_pkg::*; (")
        lines.append("  input  logic clk_i,")

        if "rst_ni" not in self.signals:
            lines.append("  input  logic rst_ni,")

        for sig in self.signals:
            if sig != "1":
                lines.append(f"  input  logic {sig},")

        for out_name in self.output_names:
            lines.append(f"  output logic {out_name},")
        lines.append("  output state_fsm state_o")
        lines.append(");")
        lines.append("")

        for out_name in self.output_names:
            lines.append(f"  logic {out_name}_d;")
        lines.append("")

        lines.append("  state_fsm current_state, next_state;")
        lines.append("")
        lines.append("  assign state_o = current_state;")
        lines.append("")

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

        lines.append("  // OUTPUT LATCHING")
        lines.append("  always_ff @(posedge clk_i or negedge rst_ni)")
        lines.append("    begin: output_latching")
        lines.append("      if (~rst_ni) begin")

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

        lines.append("  // STATE TRANSITION AND OUTPUT DEFINITION")
        lines.append("  always_comb begin")
        lines.append("    next_state = current_state;")

        for out_name in self.output_names:
            lines.append(f"    {out_name}_d = 1'b0; // overwritten below per-state")

        lines.append("    unique case (current_state)")

        for state in self.states:
            lines.append(f"      {state}: begin")

            t_list = self.transitions_from.get(state, [])
            current_outputs = self.outputs_by_state[state]

            if not t_list:
                lines.append(f"        next_state = {state};")
                for out_name in self.output_names:
                    val = current_outputs[out_name]
                    lines.append(f"        {out_name}_d = 1'b{val};")
                lines.append("      end")
                continue

            unconditional = None
            conditional_list: List[Transition] = []
            for t in t_list:
                if t.cond == "1" and unconditional is None:
                    unconditional = t
                else:
                    conditional_list.append(t)

            if unconditional is not None:
                dst = unconditional.dst
                dst_outputs = self.outputs_by_state[dst]
                lines.append(f"        next_state = {dst};")
                for out_name in self.output_names:
                    val = dst_outputs[out_name]
                    lines.append(f"        {out_name}_d = 1'b{val};")
                lines.append("      end")
                continue

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

            lines.append("        else begin")
            lines.append(f"          next_state = {state};")
            for out_name in self.output_names:
                val = current_outputs[out_name]
                lines.append(f"          {out_name}_d = 1'b{val};")
            lines.append("        end")
            lines.append("      end")

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

        sv_path.write_text("\n".join(lines), encoding="utf-8")

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

        for sig in self.signals:
            if sig != "1":
                lines.append(f"  logic {sig};")

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

        lines.append("  // Dump VCD")
        lines.append("  string vcd_path;")
        lines.append("  initial begin")
        lines.append('    if (!$value$plusargs("VCD=%s", vcd_path)) begin')
        lines.append("      `ifndef SYN")
        lines.append('        vcd_path = "";')
        lines.append("      `else")
        lines.append('        vcd_path = "";')
        lines.append("      `endif")
        lines.append("    end")
        lines.append('    $display("[TB] dumpfile = %s", vcd_path);')
        lines.append("    $dumpfile(vcd_path);")
        lines.append(f"    $dumpvars(0, {self.fsm_name}_tb);")
        lines.append("  end\n")

        # SDF annotate (disabled for Verilator)
        lines.append("  // SDF backannotation")
        lines.append("  `ifndef VERILATOR")
        lines.append("    string sdf_path;")
        lines.append("    initial begin")
        lines.append('      if (!$value$plusargs("SDF=%s", sdf_path)) begin')
        lines.append('        sdf_path = "";')
        lines.append("      end")
        lines.append('      $display("[TB] sdf = %s", sdf_path);')
        lines.append(f'      $sdf_annotate(sdf_path, {self.fsm_name}_tb.u_{self.fsm_name}, , , "MAXIMUM");')
        lines.append("    end")
        lines.append("  `endif\n")

        lines.append("  // Clock generation")
        lines.append("  initial begin")
        lines.append("    forever #(CLK_PERIOD/2) clk_i = ~clk_i;")
        lines.append("  end")
        lines.append("")

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

        tb_path.write_text("\n".join(lines), encoding="utf-8")

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
                label = t.cond.replace('"', '\\"')
                lines.append(f'  {src} -> {t.dst} [ label = "{label}" ];\n')

        lines.append("}\n")
        gv_path.write_text("".join(lines), encoding="utf-8")

    ########
    # ATPG #
    ########

    def extract_signals(self, expr: str) -> list[str]:
        tokens = re.findall(r"\b[a-zA-Z_]\w*\b", expr)
        return sorted(set(tokens))

    def to_python_expr(self, expr: str) -> str:
        py = expr
        py = re.sub(r"~", " not ", py)
        py = re.sub(r"!", " not ", py)
        py = py.replace("&", " and ")
        py = py.replace("|", " or ")
        py = py.replace("^", " != ")
        return py

    def print_truth_table(self, expr: str) -> None:
        signals, rows = self._truth_table_full(expr)
        header = " | ".join(signals) + " || OUT"
        print(header)
        print("-" * len(header))
        for env, res in rows:
            vals = " | ".join("1" if env[s] else "0" for s in signals)
            out = "1" if res else "0"
            print(f"{vals} || {out}")

    def _truth_table_full(self, expr: str):
        signals = self.extract_signals(expr)
        py_expr = self.to_python_expr(expr)

        rows = []
        for combo in itertools.product([False, True], repeat=len(signals)):
            env = dict(zip(signals, combo))
            result = eval(py_expr, {"__builtins__": None}, env)
            rows.append((env, bool(result)))
        return signals, rows

    def truth_table(self, expr: str, want_true: bool):
        signals = self.extract_signals(expr)
        py_expr = self.to_python_expr(expr)

        for combo in itertools.product([False, True], repeat=len(signals)):
            env = dict(zip(signals, combo))
            result = bool(eval(py_expr, {"__builtins__": None}, env))
            if (want_true and result) or (not want_true and not result):
                vals = ["1" if env[s] else "0" for s in signals]
                return signals, vals

        return signals, ["0"] * len(signals)

    def choose_edge(self, actual_state: str) -> tuple[str, int, list[int]]:
        t_list = self.transitions_from.get(actual_state, [])
        print
        if not t_list:
            raise RuntimeError(f"No outgoing transitions from state '{actual_state}'")

        chosen_t = random.choice(t_list)
        chosen_dst = chosen_t.dst

        chosen_idx = None
        other_indices: list[int] = []

        for idx, t in enumerate(self.transitions):
            if t.src != actual_state:
                continue
            if t.dst == chosen_dst and t.cond == chosen_t.cond and chosen_idx is None:
                chosen_idx = idx
            elif t.dst != chosen_dst:
                other_indices.append(idx)

        if chosen_idx is None:
            raise RuntimeError("Internal error: chosen transition index not found.")

        self.arcs[chosen_idx] = 1
        return chosen_t.dst, chosen_idx, other_indices

    def set_inputs(self, idx: int, idxs: list[int]) -> tuple[dict, list[dict]]:
        expr_trigger = self.transitions[idx].cond
        signals, vals = self.truth_table(expr_trigger, True)
        mydict_trigger = dict(zip(signals, vals))

        mydict_notrigger_list: list[dict] = []
        for i in idxs:
            expr_notrig = self.transitions[i].cond
            signals_nt, vals_nt = self.truth_table(expr_notrig, False)
            mydict_notrigger = dict(zip(signals_nt, vals_nt))
            mydict_notrigger_list.append(mydict_notrigger)

        return mydict_trigger, mydict_notrigger_list

    def merge_input_setting(self, input_setting_trig: dict, input_setting_notrig: list[dict]) -> dict:
        not_in_target = [
            {k: v for k, v in d.items() if k not in input_setting_trig}
            for d in input_setting_notrig
        ]
        merged = input_setting_trig.copy()
        for d in not_in_target:
            merged.update(d)
        return merged

    def append_func_tb(self, sig_dict: dict, idx: int) -> None:
        t = self.transitions[idx]
        mystr = f'    // {t.src} -> {t.dst} : "{t.cond}"\n'
        for k, v in sig_dict.items():
            mystr += f"    {k} = 1'b{v};\n"
        mystr += "    #(CLK_PERIOD);\n"
        mystr += f"    assert (u_{self.fsm_name}.state_o == {t.dst})\n"
        mystr += f'      else $fatal(1, "{t.src} -> {t.dst} failed: state_o=%0d", u_{self.fsm_name}.state_o);\n'
        self.functb.append(mystr)

    def eulerian_tour(self, adj, start):
        local = {u: list(vs) for u, vs in adj.items()}
        stack = [start]
        circuit = []
        while stack:
            v = stack[-1]
            if local[v]:
                u = local[v].pop()
                stack.append(u)
            else:
                circuit.append(stack.pop())

        circuit.reverse()
        return circuit

    def reconstruct_path(self, src, dst, parent):
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
        dist = {v: float("inf") for v in self.states}
        parent = {v: None for v in self.states}
        dist[src] = 0
        q = deque([src])
        while q:
            u = q.popleft()
            for v in self.graph[u]:
                if dist[v] == float("inf"):
                    dist[v] = dist[u] + 1
                    parent[v] = u
                    q.append(v)
        return dist, parent

    def chineese_postman(self, start_state):
        outdeg = {v: len(self.graph.get(v, ())) for v in self.states}

        indeg = defaultdict(int)
        for u, targets in self.graph.items():
            for v in targets:
                indeg[v] += 1

        b = {v: indeg[v] - outdeg[v] for v in self.states}
        P = [v for v in self.states if b[v] > 0]
        N = [v for v in self.states if b[v] < 0]

        cost = {}
        parents = {}
        for p in P:
            dist, parent = self.bfs(p)
            parents[p] = parent
            for n in N:
                cost[(p, n)] = dist[n]

        pos_units = []
        for s in P:
            for _ in range(0, abs(b[s])):
                pos_units.append(s)

        neg_units = []
        for s in N:
            for _ in range(0, abs(b[s])):
                neg_units.append(s)

        assert len(pos_units) == len(neg_units)

        cost_matrix = np.zeros((len(pos_units), len(neg_units)), dtype=int)
        for i, p in enumerate(pos_units):
            for j, n in enumerate(neg_units):
                cost_matrix[i, j] = cost[(p, n)]

        row_ind, col_ind = linear_sum_assignment(cost_matrix)

        assignments = []
        for i, j in zip(row_ind, col_ind):
            p = pos_units[i]
            n = neg_units[j]
            assignments.append((p, n))

        edges_mult = defaultdict(int)
        for u in self.states:
            for v in self.graph[u]:
                edges_mult[(u, v)] += 1

        for p, n in assignments:
            parent = parents[p]
            path = self.reconstruct_path(p, n, parent)
            for u, v in zip(path, path[1:]):
                edges_mult[(u, v)] += 1

        multi_adj = defaultdict(list)
        for (u, v), k in edges_mult.items():
            multi_adj[u].extend([v] * k)

        self.tour = self.eulerian_tour(multi_adj, start=start_state)
        print("\033[93mChinese Postman tour:")
        print(" -> ".join(self.tour))
        print(f"Number of iterations: {len(self.tour)}\033[0m")

    def get_indexes(self, actual_state, next_state):
        idxs = []
        idx = None
        for i, t in enumerate(self.transitions):
            if t.src == actual_state and t.dst == next_state and idx is None:
                idx = i
            else:
                if t.src == actual_state:
                    idxs.append(i)
        if idx is None:
            raise RuntimeError(f"No transition found from {actual_state} to {next_state}")
        return idx, idxs

    def states_walkthrough(self) -> None:
        """
        Genera una sequenza di stimoli che prova a percorrere tutti gli archi
        (transizioni) della FSM almeno una volta.
        """
        actual_state = self.states[0]
        self.chineese_postman(actual_state)

        for i in range(0, len(self.tour) - 1):
            actual_state = self.tour[i]
            next_state = self.tour[i + 1]
            idx, idxs = self.get_indexes(actual_state, next_state)
            input_setting_trig, input_setting_notrig = self.set_inputs(idx, idxs)
            input_setting = self.merge_input_setting(input_setting_trig, input_setting_notrig)
            self.append_func_tb(input_setting, idx)
