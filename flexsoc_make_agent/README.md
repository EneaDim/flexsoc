# FlexSoC Make Agent

FlexSoC Make Agent is a **local, deterministic execution agent** that lets you control a large Makefile‑based hardware flow (FlexSoC) using **natural language**.

It is designed to be:

* 🔒 **Safe** — only whitelisted Make targets can run
* 🔁 **Deterministic** — routing is inspectable and reproducible
* 🧠 **Model‑light** — no training, no GPU required
* 🛠 **Debuggable** — every decision and execution is logged

The agent:

* interprets a natural‑language request
* selects the correct `make` target (embeddings + deterministic rules)
* validates the command (safety layer)
* executes `make` **for real**
* streams live output to the terminal
* stores **structured logs** for every run
* optionally exposes everything via a **browser UI (Streamlit)**

---

## High‑level architecture

```
User (CLI / REPL / Browser)
        │
        ▼
router.py (serve / route)
  ├─ explicit overrides ("make lint", "lancia view")
  ├─ deterministic rules (help / clean / view)
  ├─ embedding router (Ollama)
  ▼
runner.py
  ├─ validation (catalog.json)
  ├─ real make execution
  ├─ tee output (terminal + logs)
  ▼
FlexSoC Makefile + toolchain
```

### Core components

* **Ollama** — local embedding + chat models
* **`targets.json`** — semantic definition of Make targets
* **`targets_embeddings.json`** — fast routing database
* **`catalog.json`** — execution allowlist (hard safety boundary)
* **`router.py`** — routing + orchestration
* **`runner.py`** — the *only* executor of Make
* **`agent_repl.py`** — interactive CLI
* **`webapp.py`** — Streamlit browser UI

---

## Why embeddings instead of fine‑tuning

* No GPU required
* No training data collection
* Fully inspectable routing (scores + top‑k)
* Deterministic fallbacks and overrides
* Incremental, low‑risk improvements

⚠️ The LLM (when used) **never decides what to execute**.
Only the router + catalog do.

---

## Full execution flow

### 1. User request

Examples:

* `avvia il quickstart dell'IP`
* `fai lint`
* `lancia view`
* `help me`

---

### 2. Deterministic overrides (highest priority)

Implemented in `router.py`.

If the user explicitly names a target:

* `make <target>`
* `lancia <target>`
* `esegui <target>`
* `run <target>`

👉 that target **always wins**.

Additional deterministic intents:

* **help** → routes to `help` unless a scope is explicit (`help_ip`, `help_soc`, …)
* **clean** → routes to `clean_*` only if a clean verb is present
* **view** → prefers `view` unless timing/path keywords imply `path_view`

This guarantees that:

* `doc` never becomes `clean_doc`
* `help me` never becomes `help_fsm`

---

### 3. Embedding‑based routing

If no deterministic rule fires:

1. detect language (EN / IT)
2. embed user text via Ollama
3. cosine similarity against `targets_embeddings.json`
4. select best target
5. apply soft tie‑break rules

### Debug routing (no execution)

```bash
python3 flexsoc_make_agent/router.py route "your query"
```

This prints:

* chosen target
* similarity score
* top‑k alternatives
* override reason (if any)

---

### 4. Validation — safety layer

Before execution, `runner.py` enforces:

* target must exist in `catalog.json`
* only allowed variables are passed
* only whitelisted make flags are used

If validation fails → **nothing runs**.

---

### 5. Real execution (`runner.py`)

`runner.py` is the **only component** that can execute Make.

Features:

* real `make <target>` execution
* live stdout streaming
* tee to log files
* timeout handling
* raw terminal mode (for GUIs like GTKWave)

You normally do **not** invoke it directly.

---

### 6. Automatic logging

Each run produces:

```
flexsoc_make_agent/logs/
  ├─ <ts>.tee.log     ← full execution output
  ├─ <ts>.route.json  ← routing decision
  ├─ <ts>.cmd.json    ← validated command
  ├─ <ts>.run.out
  └─ <ts>.run.err
```

Every run is **auditable and reproducible**.

---

## Using the agent

### Interactive CLI (recommended)

```bash
make agent
```

or

```bash
python3 flexsoc_make_agent/agent_repl.py
```

Type natural language commands and see Make run live.

Exit with:

```text
/exit
```

---

### Direct CLI execution

```bash
python3 flexsoc_make_agent/router.py serve \
  --catalog flexsoc_make_agent/catalog.json \
  "fai lint"
```

Raw terminal mode (GUI‑friendly):

```bash
python3 flexsoc_make_agent/serve_ollama.py --raw "view"
```

---

## Browser UI (Streamlit)

Start the web interface:

```bash
streamlit run flexsoc_make_agent/webapp.py
```

Features:

* natural language input
* dry‑run / real execution toggle
* routing inspection
* log viewer
* repository file browser

⚠️ Intended for **local use only** (executes real commands).

---

## Debugging guide

### ❌ Wrong target selected

* run `router.py route`
* inspect `topk` results
* refine `targets.json`
* rebuild embeddings

```bash
python3 flexsoc_make_agent/router.py build
```

---

### ❌ GUI tools not opening

* ensure raw / tee mode is enabled
* verify `DISPLAY` is set

---

### ❌ Webapp JSON errors

* stdout must contain **only JSON**
* debug prints must go to stderr

---

## Design principles

> **Make is the source of truth.**
> **The agent only decides *which* Make target to run — never *how*.**

> **Determinism first, intelligence second.**

