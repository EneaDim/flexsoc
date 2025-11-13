# FSM Generator – TXT/CSV → SystemVerilog & Graphviz

This project converts a simple text/CSV description of a finite state machine (FSM) into:

- a **SystemVerilog FSM module** (`.sv`)
- a **Graphviz DOT file** (`.gv`)
- optionally a **SystemVerilog testbench** (`_tb.sv`)

It is intended as a lightweight tool for **digital design** and **education**, where FSMs can be prototyped with simple text files and quickly turned into synthesizable RTL.

## Repository Structure

```text
.
├── Makefile
├── README.md
├── examples
│   ├── fsm_example.csv
│   └── fsm_example.txt
├── inputs
├── outputs
└── scripts
    ├── Interface.py
    ├── Main.py
    └── help.py
```

## FSM Description Format

### Transitions (`<fsm_name>.txt`)

Describe states, next states, and Boolean conditions:

```
STATE_A -> STATE_B "cond_expr"
```

### State/Output Table (`<fsm_name>.csv`)

```
state_name, out_valid, out_error
IDLE,       0,        0
BUSY,       1,        0
DONE,       1,        1
```

## Generated Files

- `<fsm_name>.sv` — SystemVerilog FSM
- `<fsm_name>.gv` — Graphviz DOT
- `<fsm_name>_tb.sv` — optional testbench

## Usage

```
python3 scripts/Main.py --fsm_name fsm_example --f_clk 100
```

## License

Apache License 2.0.
