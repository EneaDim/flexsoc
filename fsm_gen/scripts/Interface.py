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
@file Interface.py
@brief Core logic for parsing FSM descriptions and generating SystemVerilog and
       Graphviz outputs.

This module exposes the Interface class, which:
  - reads FSM descriptions from:
      * <fsm_name>.txt (graph/transition description)
      * <fsm_name>.csv (state/output encoding)
  - generates:
      * <fsm_name>.sv   : SystemVerilog FSM module
      * <fsm_name>.gv   : Graphviz DOT file
      * <fsm_name>_tb.sv (optional): SystemVerilog testbench
"""

from __future__ import annotations

import math
import random
import re
import itertools
from pathlib import Path
from typing import List
    


class Interface:
    """!
    @class Interface
    @brief High-level FSM interface.

    This class encapsulates:
      - parsing of FSM description files,
      - internal representation (states, transitions, outputs),
      - generation of SystemVerilog and Graphviz files.

    Typical usage:
    @code{.py}
    interface = Interface("My FSM Interface")
    interface.read_inputs("fsm_example")
    interface.write_sv()
    interface.write_gv()
    # interface.write_tb(100)  # Example: 100 MHz clock
    @endcode
    """

    # --------------------------------------------------------------------- #
    # Construction
    # --------------------------------------------------------------------- #

    def __init__(self, name: str) -> None:
        """!
        @brief Construct a new Interface.

        @param name Human-readable name/label for this interface instance.
        """
        self.name: str = name

        # Public-ish attributes filled after read_inputs().
        self.fsm_name: str | None = None
        self.signals: List[str] = []
        self.states: List[str] = []
        self.out_names: List[str] = []
        self.out_values: List[list[str]] = []
        self.source: List[str] = []
        self.dest: List[str] = []
        self.edges: List[str] = []
        self.next_states: List[List[str]] = []

        # Derived paths (based on repository layout)
        # scripts/Interface.py -> root_dir = scripts/..
        root_dir = Path(__file__).resolve().parents[1]
        self.inputs_dir: Path = root_dir / "inputs"
        self.outputs_dir: Path = root_dir / "outputs"

    # --------------------------------------------------------------------- #
    # Public API
    # --------------------------------------------------------------------- #

    def read_inputs(self, fsm_name: str) -> None:
        """!
        @brief Read and parse FSM input files.

        This method reads:
          - `<fsm_name>.txt` from the `inputs/` directory as the transition
            description.
          - `<fsm_name>.csv` from the `inputs/` directory as the state/output
            table.

        It populates the internal data structures:
          - states
          - output names/values
          - signals (input conditions)
          - transition edges and next-state mapping.

        @param fsm_name Base name of the FSM (without extension).
        """
        self.fsm_name = fsm_name

        txt_path = self.inputs_dir / f"{fsm_name}.txt"
        csv_path = self.inputs_dir / f"{fsm_name}.csv"

        if not txt_path.is_file():
            raise FileNotFoundError(
                f"FSM transition file not found: {txt_path}"
            )

        if not csv_path.is_file():
            raise FileNotFoundError(
                f"FSM CSV file not found: {csv_path}"
            )

        # 1) Parse the TEXT file containing transitions/conditions.
        self._parse_txt_file(txt_path)

        # 2) Parse the CSV file containing states and output encodings.
        self._parse_csv_file(csv_path)

        # 3) Connect states to their possible next states based on the source/
        #    destination lists extracted from the TXT file.
        self._build_next_states()

    def write_sv(self) -> None:
        """!
        @brief Generate a SystemVerilog FSM module.

        The module is written to `outputs/<fsm_name>.sv`.

        The generated module includes:
          - input declarations for `clk_i`, `rst_ni` (if not already present),
            and all input signals derived from the transition expressions.
          - output declarations and registered outputs.
          - enumerated state type (`typedef enum logic [...] state_fsm`).
          - synchronous state and output registers.
          - combinational next-state and next-output logic.
        """
        if self.fsm_name is None:
            raise RuntimeError("read_inputs() must be called before write_sv().")

        self.outputs_dir.mkdir(parents=True, exist_ok=True)
        sv_path = self.outputs_dir / f"{self.fsm_name}.sv"
        sv_path_pkg = self.outputs_dir / f"{self.fsm_name}_pkg.sv"
        gtkw_path = self.outputs_dir / f"{self.fsm_name}.gtkw"

        # Determine the number of bits required to encode the states.
        num_states = max(1, len(self.states))
        state_width = max(1, math.ceil(math.log2(num_states)))
        msb_index = state_width - 1

        lines: List[str] = []

        # ------------------------------------------------------------------ #
        #  Package
        # ------------------------------------------------------------------ #
        lines.append(f"package {self.fsm_name}_pkg;")
        lines.append("")
        lines.append(f"typedef enum logic [{msb_index}:0] {{")
        i = 0
        dim = math.ceil(math.log2(len(self.states)))
        for state in self.states[:-1]:
            dim_format = '0'+str(dim)+'b'
            myformat = format(i, dim_format)
            lines.append(f"  {state} = {dim}'b{myformat},")
            i += 1
        myformat = format(i, dim_format)
        lines.append(f"  {self.states[-1]} = {dim}'b{myformat}")
        lines.append("} state_fsm;")
        lines.append("")
        lines.append(f"endpackage;")
        lines.append("")

        sv_path_pkg.write_text("\n".join(lines))

        lines: List[str] = []

        # ------------------------------------------------------------------ #
        #  State name on waveform
        # ------------------------------------------------------------------ #
        i = 0
        dim = math.ceil(math.log2(len(self.states)))
        for state in self.states:
            dim_format = '0'+str(dim)+'b'
            myformat = format(i, dim_format)
            lines.append(f"{myformat} {state}")
            i += 1
        lines.append("")

        gtkw_path.write_text("\n".join(lines))

        lines: List[str] = []

        # ------------------------------------------------------------------ #
        # Module header
        # ------------------------------------------------------------------ #
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
        for out_name in self.out_names:
            lines.append(f"  output logic {out_name},")
        lines.append(f"  output state_fsm state_o")
        lines.append(");")
        lines.append("")

        # ------------------------------------------------------------------ #
        # Internal signals and state type
        # ------------------------------------------------------------------ #

        # Registered version of each output
        for out_name in self.out_names:
            lines.append(f"  logic {out_name}_d;")
        lines.append("")


        # Enumerated type for states
        lines.append("  state_fsm current_state, next_state;")
        lines.append("")
        lines.append("  assign state_o = current_state;")
        lines.append("")

        # ------------------------------------------------------------------ #
        # State latching
        # ------------------------------------------------------------------ #
        lines.append("  // STATE LATCHING")
        lines.append("  always_ff @(posedge clk_i or negedge rst_ni)")
        lines.append("    begin: state_latching")
        lines.append("      if (~rst_ni) begin")
        lines.append(f"        current_state <= {self.states[0]};")
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
        # On reset, use the outputs of the first state
        for idx, out_name in enumerate(self.out_names):
            reset_val = self.out_values[0][idx]
            lines.append(f"        {out_name} <= 1'b{reset_val};")
        lines.append("      end else begin")
        for out_name in self.out_names:
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
        lines.append("    unique case (current_state)")

        # One case-item per state
        for state_index, state in enumerate(self.states):
            lines.append(f"      {state}: begin")

            # For this state, examine all transitions
            default_line_start = len(lines)
            first_condition = True

            # Next-state list for this state
            for dest_state in self.next_states[state_index]:
                # Find the edge condition for (state -> dest_state)
                for i in range(len(self.source)):
                    if self.source[i] == state and self.dest[i] == dest_state:
                        break
                condition = self.edges[i]

                # Unconditional transition
                if condition == "1":
                    lines.append(f"        next_state = {self.dest[i]};")

                    # Find index of destination state to pick output values
                    dest_index = self.states.index(self.dest[i])
                    for out_idx, out_name in enumerate(self.out_names):
                        val = self.out_values[dest_index][out_idx]
                        lines.append(f"        {out_name}_d = 1'b{val};")
                    lines.append("      end")
                    break

                # Conditional transitions chain: if / else if
                if first_condition:
                    lines.append(f"        if ({condition}) begin")
                    lines.append(f"          next_state = {self.dest[i]};")
                else:
                    lines.append(f"        else if ({condition}) begin")
                    lines.append(f"          next_state = {self.dest[i]};")

                dest_index = self.states.index(self.dest[i])
                for out_idx, out_name in enumerate(self.out_names):
                    val = self.out_values[dest_index][out_idx]
                    lines.append(f"          {out_name}_d = 1'b{val};")
                lines.append("        end")
                first_condition = False

            # If none of the conditions matched, remain in the same state
            # and keep its outputs.
            if self.next_states[state_index]:
                # Only add the default branch if there was at least one edge.
                if self.edges[i] != "1":
                    lines.append("        else begin")
                    lines.append(f"          next_state = {state};")
                    for out_idx, out_name in enumerate(self.out_names):
                        val = self.out_values[state_index][out_idx]
                        lines.append(f"          {out_name}_d = 1'b{val};")
                    lines.append("        end")
                    lines.append("      end")
            else:
                # No outgoing transitions: self-loop
                lines.append(f"        next_state = {state};")
                for out_idx, out_name in enumerate(self.out_names):
                    val = self.out_values[state_index][out_idx]
                    lines.append(f"        {out_name}_d = 1'b{val};")
                lines.append("      end")

        # Default case: go to reset state and apply its outputs.
        lines.append("      default: begin")
        lines.append(f"        next_state = {self.states[0]};")
        for out_idx, out_name in enumerate(self.out_names):
            val = self.out_values[0][out_idx]
            lines.append(f"        {out_name}_d = 1'b{val};")
        lines.append("      end")
        lines.append("    endcase")
        lines.append("  end")
        lines.append("")
        lines.append("endmodule")
        lines.append("")

        sv_path.write_text("\n".join(lines))

    def write_tb(self, f_CLK: int) -> None:
        """!
        @brief Generate a simple SystemVerilog testbench for the FSM.

        The testbench is written to `outputs/<fsm_name>_tb.sv`.

        @param f_CLK Clock frequency in MHz (used to compute the clock period).
        """
        if self.fsm_name is None:
            raise RuntimeError("read_inputs() must be called before write_tb().")

        self.outputs_dir.mkdir(parents=True, exist_ok=True)
        tb_path = self.outputs_dir / f"{self.fsm_name}_tb.sv"

        # Clock period (ns) for a given frequency in MHz:
        #   T(ns) = 1000 / f_CLK
        # We generate a clock with half-period delays (#T/2).
        if f_CLK <= 0:
            raise ValueError("f_CLK must be a positive integer (MHz).")

        period_ns = 1000.0 / float(f_CLK)
        half_period_ns = period_ns / 2.0

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
        for out_name in self.out_names:
            lines.append(f"  logic {out_name};")

        lines.append("  state_fsm state_o;")
        lines.append("")
        lines.append(f"  {self.fsm_name} u_{self.fsm_name} (")
        lines.append("    .clk_i,")
        lines.append("    .rst_ni,")
        for sig in self.signals:
            if sig != "1":
                lines.append(f"    .{sig},")
        for out_name in self.out_names:
            lines.append(f"    .{out_name},")
        lines.append(f"    .state_o")
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
        lines.append(f"    forever #(CLK_PERIOD/2) clk_i = ~clk_i;")
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

    def write_gv(self) -> None:
        """!
        @brief Generate a Graphviz DOT file from the FSM text description.

        The DOT file is written to `outputs/<fsm_name>.gv`.

        The method performs a light transformation on the original TXT file,
        converting transitions of the form:

        @code
        STATE_A : condition ; STATE_B
        @endcode

        into Graphviz edges with labels:

        @code
        STATE_A -> STATE_B [ label = "condition" ];
        @endcode
        """
        if self.fsm_name is None:
            raise RuntimeError("read_inputs() must be called before write_gv().")

        txt_path = self.inputs_dir / f"{self.fsm_name}.txt"
        if not txt_path.is_file():
            raise FileNotFoundError(
                f"FSM transition file not found: {txt_path}"
            )

        self.outputs_dir.mkdir(parents=True, exist_ok=True)
        gv_path = self.outputs_dir / f"{self.fsm_name}.gv"

        lines: List[str] = []

        # Transform each line to Graphviz syntax
        with txt_path.open("r", encoding="utf-8") as f_r:
            for line in f_r:
                line = line.replace(":", "[ label =")
                line = line.replace(";", " ] ;")
                lines.append(line)

        gv_lines: List[str] = []
        gv_lines.append(f"digraph {self.fsm_name} ")
        gv_lines.append("{\n")
        gv_lines.extend(lines)
        gv_lines.append("}")

        gv_path.write_text("".join(gv_lines))

    # --------------------------------------------------------------------- #
    # Private helpers
    # --------------------------------------------------------------------- #

    def _parse_txt_file(self, txt_path: Path) -> None:
        """!
        @brief Internal helper to parse the FSM TXT file.

        This method:
          - normalizes logical operators and symbols,
          - extracts source states, destination states and edge conditions,
          - builds the list of input signals used in the conditions.
        """
        raw_lines: List[str] = []

        # Read & normalize text lines
        with txt_path.open("r", encoding="utf-8") as f:
            for line in f:
                # Normalize logical operators and symbols
                line = line.replace("!", "~ ")
                line = line.replace("~", "~ ")
                line = line.replace(" not ", " ~ ")
                line = line.replace(" and ", " & ")
                line = line.replace(" or ", " | ")
                line = line.replace(" nand ", " % ")
                line = line.replace(" nor ", " * ")
                line = line.replace(" xor ", " ^ ")
                line = line.replace("(", " ( ")
                line = line.replace(")", " ) ")
                line = line.replace("[", " [ ")
                line = line.replace("]", " ] ")
                line = line.replace("->", " -> ")
                line = line.replace(" 1 ", "1")
                line = line.replace("  1  ", "1")
                # Collapse multiple spaces
                line = line.replace("  ", " ")
                line = line.replace("   ", " ")
                line = line.replace("  ", " ")

                # Split, then re-join with single spaces
                tokens = line.strip().split()
                if tokens:
                    raw_lines.append(" ".join(tokens))

        # Tokenize again line-by-line
        token_lines = [l.strip().split() for l in raw_lines]

        self.source = []
        self.dest = []
        self.edges = []

        # Temporary list for collecting characters inside quotes
        logic_chars: List[str] = []
        inside_quotes = False

        # Iterate over rows to extract source, destination and condition
        for elements in token_lines:
            # Skip comments
            if not elements:
                continue
            if elements[0] == "#" or (elements[0] == "/" and len(elements) > 1 and elements[1] == "/"):
                continue

            if len(elements) > 3:
                # Example of expected format:
                #   STATE_A -> STATE_B "condition"
                self.source.append(elements[0])
                self.dest.append(elements[2])

                line = " ".join(elements)
                logic_chars.clear()
                inside_quotes = False

                for ch in line:
                    if ch == '"':
                        if inside_quotes:
                            # Closing quote
                            break
                        inside_quotes = True
                        continue
                    if inside_quotes:
                        logic_chars.append(ch)

                logic_expr = "".join(logic_chars)
                self.edges.append(logic_expr)

        if not (len(self.edges) == len(self.source) == len(self.dest)):
            raise ValueError(
                "Inconsistent transition information: "
                "source, dest and edges lengths differ."
            )

        # Extract unique input signals from the edge expressions
        self.signals = []
        forbidden_tokens = {
            "(", "((", "(((", ")))", "))", ")", "not", "and", "or",
            "xor", "|", "&", "~", "%", "^", "*", ""
        }

        for edge in self.edges:
            for token in edge.split():
                if token not in forbidden_tokens and token not in self.signals:
                    self.signals.append(token)

        # Clean up spaces after negation
        for idx, e in enumerate(self.edges):
            self.edges[idx] = e.replace("~ ", "~")

    def _parse_csv_file(self, csv_path: Path) -> None:
        """!
        @brief Internal helper to parse the FSM CSV file.

        This method:
          - extracts state names,
          - extracts output signal names,
          - extracts output values for each state.
        """
        self.states = []
        self.out_values = []

        raw_lines: List[list[str]] = []

        with csv_path.open("r", encoding="utf-8") as f:
            for line in f:
                # Split on comma, semicolon or newline
                parts = re.split(r",|;|\n", line)
                parts = parts[:-1]  # remove trailing empty element after split
                if parts:
                    raw_lines.append(parts)

        if not raw_lines:
            raise ValueError(f"CSV file appears to be empty: {csv_path}")

        # First row contains output names (columns after the first)
        header = [c.strip() for c in raw_lines[0][1:]]
        self.out_names = header

        # Remaining rows: [state_name, out0, out1, ...]
        for row in raw_lines[1:]:
            if not row:
                continue
            state_name = row[0].strip()
            outputs = [v.strip() for v in row[1:]]
            self.states.append(state_name)
            self.out_values.append(outputs)

    def _build_next_states(self) -> None:
        """!
        @brief Internal helper to build next-states for each state.

        For each state in `self.states`, this method collects all destination
        states reachable from it, based on `self.source` and `self.dest`.
        """
        self.next_states = []
        for state in self.states:
            dest_states: List[str] = []
            for src, dst in zip(self.source, self.dest):
                if state == src:
                    dest_states.append(dst)
            self.next_states.append(dest_states)

    ########
    # ATPG #
    ########
    def extract_signals(self, expr: str):
        """
        Find all unique signal names in the boolean expression.
        Signal names are assumed to be identifiers: [a-zA-Z_][a-zA-Z0-9_]*
        """
        # All word-like tokens
        tokens = re.findall(r'\b[a-zA-Z_]\w*\b', expr)
        # If you had keywords, you could filter them out here
        # (e.g. if you later allow 'and', 'or', etc. in input)
        return sorted(set(tokens))
    
    def to_python_expr(self, expr: str):
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
    
    def print_truth_table(self, expr: str):
        signals, rows = self.truth_table(expr)
        # Header
        header = " | ".join(signals) + " || OUT"
        print(header)
        print("-" * len(header))
        for env, res in rows:
            vals = " | ".join("1" if env[s] else "0" for s in signals)
            out  = "1" if res else "0"
            print(f"{vals} || {out}")
    
    def truth_table(self, expr: str, flag: bool):
        """
        Build a truth table for the boolean expression.
        Returns:
            signals: list of signal names
            rows: list of (values_dict, result)
        """
        #print(expr)
        signals = self.extract_signals(expr)
        py_expr = self.to_python_expr(expr)
    
        rows = []
        for combo in itertools.product([False, True], repeat=len(signals)):
            env = dict(zip(signals, combo))
            # Eval in restricted environment
            result = eval(py_expr, {"__builtins__": None}, env)
            rows.append((env, bool(result)))
        for env, res in rows:
            vals = " | ".join("1" if env[s] else "0" for s in signals)
            if flag:
                if res:
                    break
            else:
                if not res:
                    break

        vals = vals.split(' | ')
        return signals, vals
    
    
    def check_data(self) -> None:
        """TODO: Just a check.
        :returns: TODO

        """
        #print(self.states)
        #print(self.next_states)
        #print(self.source)
        #print(self.dest)
        #print(self.edges)
        #print(self.signals)
        #for edge in self.edges:
        #    print("Expression:", edge)
        #    self.print_truth_table(edge)

    def choose_edge(self, actual_state, start_index) -> str:
        # Trigger
        end_index = random.randint(0, len(self.next_states[start_index])-1)
        end = self.next_states[start_index][end_index]
        i = 0
        while True:
            if self.source[i] == actual_state and self.dest[i] == end:
                break
            i += 1
        # No trigger
        indexs = []
        for dest in self.next_states[start_index]:
            if not dest == end:
                j = 0 
                while True:
                    if self.source[j] == actual_state and self.dest[j] == dest:
                        indexs.append(j)
                        break
                    j += 1
        #print(self.source[i], self.dest[i], i, indexs)
        self.arcs[i] = 1
        return self.dest[i], i, indexs

    def set_inputs(self, idx, idxs) -> dict:
        signals, vals = self.truth_table(self.edges[idx], True)
        mydict_trigger = dict(zip(signals, vals))
        mydict_notrigger_list = []
        if not idxs == []:
            for i in idxs:
                signals, vals = self.truth_table(self.edges[i], False)
                mydict_notrigger = dict(zip(signals, vals))
                mydict_notrigger_list.append(mydict_notrigger)
        return mydict_trigger, mydict_notrigger_list

    def merge_input_setting(self, input_setting_trig, input_setting_notrig):
        not_in_target = [
            {k: v for k, v in d.items() if k not in input_setting_trig}
            for d in input_setting_notrig
        ]
        merged = input_setting_trig.copy()
        for d in not_in_target:
            merged.update(d)
        return merged

    def append_func_tb(self, sig_dict, idx) -> None:
        mystr = f'    // {self.source[idx]} -> {self.dest[idx]} : "{self.edges[idx]}"\n'
        for k, v in sig_dict.items():
            mystr += f"    {k} = 1'b{v};\n"
        mystr += '    #(CLK_PERIOD);\n'
        mystr += f'    assert (u_{self.fsm_name}.state_o == {self.dest[idx]})\n'
        mystr += f'      else $fatal(1, "{self.source[idx]} -> {self.dest[idx]} failed: state_o=%0d", u_{self.fsm_name}.state_o);\n'
        self.functb.append(mystr)

    def states_walkthrough(self) -> None:
        """High level implementation
        :returns: TODO

        """
        self.functb = []
        self.all_arcs_taken = False
        self.arcs = [0]*len(self.edges)
        actual_state = self.states[0]
        j = 0
        while self.all_arcs_taken == False:
            #print('\nStart While')
            idx_next = self.states.index(actual_state)
            actual_state, idx, idxs = self.choose_edge(actual_state, idx_next)
            input_setting_trig, input_setting_notrig = self.set_inputs(idx, idxs)
            input_setting = self.merge_input_setting(input_setting_trig, input_setting_notrig)
            self.append_func_tb(input_setting, idx)
            j += 1
            if self.arcs == [1]*len(self.arcs):
                self.all_arcs_taken= True
                print(f'Numer of iterations: {j}')


