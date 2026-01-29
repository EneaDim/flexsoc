# FSM Agent

**FSM Agent** is a tool that compiles a **natural language (NL) specification** into a **finite state machine (FSM)** that is structured, validated, and ready to be consumed by downstream RTL tools (e.g. SystemVerilog generators).

The goal is to enable a reliable and repeatable *NL → formal FSM* flow, even when using **small LLMs (3B–7B) on CPU**.

> **Language support**: at the moment, FSM Agent is tuned and validated for **Italian natural language specifications**. English support is partial and not yet optimized.

---

## What it does

Given a natural-language description of an RTL-style controller, FSM Agent:

* generates a **structured JSON representation** of the FSM
* enforces **strong RTL-oriented constraints** (no self-loops, error/done priority, reset handling, etc.)
* validates **schema, semantics, and graph structure**
* renders machine-readable artifacts:

  * `*.txt` with FSM transitions
  * `*.csv` with per-state outputs
* automatically exports results to a directory ready for RTL backends

---

## Project structure

```
fsm_agent/
├── data/
│   ├── gold/           # golden examples (NL + JSON)
│   └── inbox/          # input NL specs and generated outputs
├── prompts/
│   ├── extract_json.txt     # main NL → JSON prompt
│   └── fix_from_errors.txt  # correction / repair prompt
├── scripts/
│   ├── repl.py         # interactive REPL
│   ├── run_inbox.py    # batch execution on spec.txt
│   └── test_all_gold.py
├── src/
│   ├── pipeline.py    # end-to-end orchestration
│   ├── llm_client.py  # Ollama client
│   ├── validate.py    # FSM validation logic
│   ├── json_coerce.py # deterministic JSON coercion
│   ├── render.py      # text / CSV rendering
│   └── model.py       # FSM data model (Pydantic)
└── requirements.txt
```

---

## Core concepts

### Implicit stay semantics

If **no transition condition is true**, the FSM **remains in the current state**.

As a consequence:

* **self-loops (S → S) are forbidden**
* **artificial WAIT / HOLD states are forbidden**

This matches the standard RTL pattern where the state register holds its value unless explicitly changed.

---

### Graph closure (FSM Agent definition)

A valid FSM must satisfy:

* every state has **at least one outgoing transition**
* every state has **at least one incoming transition**

If the initial state (e.g. `IDLE` / `READY`) has no incoming transitions, a dedicated reset state is introduced:

```
RESET -> IDLE : "1"
```

This transition represents an unconditional transition at the next clock edge and is explicitly documented in `assumptions`.

---

## RTL-oriented constraints (enforced)

FSM Agent enforces the following constraints both in prompts and validators:

* no self-loops (`from == to`)
* `reset_i` is used **only** to define the initial state, never in guards
* `done_i` and `error_i` must **never appear in the same condition**
* `error_i` has priority over `done_i`
* transitions triggered by `error_i` go **only** to `ERROR`
* transitions triggered by `done_i` go **only** to `IDLE` / `READY`
* conditions may use **only**: `! & | ( )` and constant `"1"`
* outputs are **constants only (0 or 1)**, never expressions or signals

If a constraint is violated:

* it is reported explicitly
* the fix-loop attempts a minimal correction

---

## Interactive usage (REPL)

```bash
make repl FSM=test
```

REPL commands:

* write the NL specification (multi-line)
* `.` → generate FSM
* `:name my_fsm` → change export name
* `:show` → show buffered NL spec
* `:clear` → clear NL buffer
* `:q` → exit

Generated files are automatically copied to:

```
fsm_gen/inputs/
  ├── test.txt   # transitions
  └── test.csv   # per-state outputs
```

---

## Example (Italian NL input)

```
Controller sincrono con reset.
Dopo il reset il blocco è pronto.
Quando arriva start_i entra in esecuzione.
Rimane occupato finché done_i.
Se arriva error_i va in errore.
In errore resta finché clear_error_i.
Dopo clear torna pronto.
```

Resulting FSM (logical form):

* READY → BUSY : start_i
* BUSY → ERROR : error_i
* BUSY → READY : done_i & !error_i
* ERROR → READY : clear_error_i

(No self-loops; stay is implicit.)

---

## Supported LLMs

FSM Agent is designed for **Ollama** with small instruction-tuned models:

* `qwen2.5:3b-instruct` — fast iteration, CPU-friendly
* `qwen2.5:7b-instruct` — more robust constraint compliance

Model selection via environment variable:

```bash
export OLLAMA_MODEL=qwen2.5:3b-instruct
```

---

## Design philosophy

FSM Agent is **not** a creative generator; it behaves like a **compiler**:

* ambiguous input → minimal explicit assumptions
* invalid output → deterministic validation errors
* corrections → constrained and local

If an FSM passes validation, it is **structurally and semantically sound** for RTL usage.

---

## Project status

* ✔ stable end-to-end pipeline
* ✔ usable REPL on CPU
* ✔ strong RTL constraints
* ✔ automated export for backend tools

Typical future extensions:

* multi-clock FSMs
* hierarchical FSMs
* direct SystemVerilog emission

---

**FSM Agent = Natural language → FSM, without magic.**

