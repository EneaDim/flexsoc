# FlexSoC Make Agent — Execution Guide

This document explains **what each script does** and **how to run every step**, from intent definition to interactive usage (CLI, REPL, Web UI).

The goal is to make the flow **explicit, reproducible, deterministic, and debuggable**.

---

## 0. High-level Architecture

FlexSoC Make Agent is built around a **strict separation of concerns**:

* **Intent definition** (what the user *means*)
* **Routing** (which Make target matches that intent)
* **Authorization** (what is allowed to run)
* **Execution** (running `make` safely)

There are **two independent routing backends**:

1. **Embedding Router (deterministic, default)**

   * Uses text embeddings + deterministic rules
   * No conversational reasoning
   * Stable and reproducible

2. **LLM JSON Router (generative, optional)**

   * Uses an Ollama chat model defined in `Modelfile.make`
   * The LLM directly emits a JSON command
   * More flexible, less deterministic

`agent_repl.py` and `webapp.py` are **frontends only**. They never execute Make directly.

---

## 1. targets.json — Intent Definition

**File:** `flexsoc_make_agent/data/targets.json`

This file defines the **entire intent space** of the agent.

Each entry corresponds to **one Makefile target** and describes how natural language should map to it.

### Fields

* `target` — exact Makefile target name
* `risk` — informational risk level (`low`, `medium`, `high`)
* `depends_on` — prerequisite targets (informational)
* `embedding_text`

  * `title` — short, precise description
  * `summary` — what this target uniquely does
  * `queries` — example user utterances
  * `keywords` — strong anchor terms
  * `negative` — sibling targets that must NOT be confused

⚠️ **Important:** Similar targets (e.g. `setup`, `setup_tb`, `setup_model`) must be semantically distinguishable **by meaning**, not just by name.

### When to edit

* Adding a new Makefile target
* Improving routing accuracy
* Fixing collisions between similar targets

---

## 2. Build Embeddings Database

### Script

**`router.py build`**

### Purpose

Generates `targets_embeddings.json` from `targets.json` using a fixed Ollama embedding model.

Each target is embedded **twice**:

* English (`embedding_en`)
* Italian (`embedding_it`)

The embedding text is built from:

* target name + risk
* title and summary
* example queries
* keywords
* negative anchors

### Run

```bash
python3 flexsoc_make_agent/router.py build \
  --targets flexsoc_make_agent/data/targets.json \
  --out flexsoc_make_agent/data/targets_embeddings.json \
  --embed-model nomic-embed-text
```

### Rules

* The embedding model **must stay fixed**
* If you change `targets.json`, you **must rebuild embeddings**

---

## 3. Build Catalog — Safety Allowlist

### Script

**`build_catalog.py`**

### Purpose

Generates `catalog.json`, the **hard execution allowlist**.

The catalog defines:

* allowed Make targets
* allowed variables
* allowed make flags

Anything not present here **cannot be executed**, regardless of routing.

### Run

```bash
python3 flexsoc_make_agent/build_catalog.py \
  --targets flexsoc_make_agent/data/targets.json \
  --out flexsoc_make_agent/catalog.json
```

---

## 4. Router — Debug & Inspection

### Script

**`router.py route`**

### Purpose

Inspects how user text is routed **without executing anything**.

It shows:

* chosen target
* similarity score
* top-k alternatives
* deterministic override reason (explicit / clean / help)

### Run

```bash
python3 flexsoc_make_agent/router.py route "help me"
```

This is the primary tool for:

* tuning embeddings
* validating `targets.json`
* diagnosing routing bugs

---

## 5. Runner — Make Execution Engine

### Script

**`runner.py`**

### Purpose

The **only component allowed to run Make**.

Responsibilities:

* Validate commands against `catalog.json`
* Enforce allowlists
* Execute `make <target>`
* Handle timeouts, logging, dry-run, tee

### Internal invocation example

```bash
python3 runner.py run --json '{"action":"make","target":"lint"}'
```

You normally do **not** call this directly.

---

## 6. End-to-End Execution — Embedding Backend

### Script

**`router.py serve`**

### Purpose

Implements the full deterministic agent pipeline:

```
user text → embeddings → routing rules → catalog → runner → make
```

### Run

```bash
python3 flexsoc_make_agent/router.py serve \
  --catalog flexsoc_make_agent/catalog.json
```

### Raw terminal mode

```bash
python3 flexsoc_make_agent/serve_ollama.py --raw "quickstart"
```

Raw mode streams Make output directly.

---

## 7. Modelfile.make — LLM Definition

### File

**`Modelfile.make`**

### Purpose

Defines a constrained Ollama chat model that:

* Outputs JSON only
* Does not hallucinate targets
* Respects execution boundaries

### Build

```bash
ollama create flexsoc-make -f flexsoc_make_agent/Modelfile.make
```

---

## 8. serve_ollama.py — LLM JSON Router

### Script

**`serve_ollama.py`**

### Purpose

Uses an LLM to **directly generate the execution JSON**:

```
user text → LLM → JSON → runner → make
```

### Run

```bash
python3 flexsoc_make_agent/serve_ollama.py \
  --model flexsoc-make \
  --repo-root . \
  "fai lint"
```

### Notes

* No embeddings involved
* Less deterministic
* Useful for explanation or complex reasoning

---

## 9. agent_repl.py — Interactive CLI

### Script

**`agent_repl.py`**

### Purpose

Interactive terminal interface.

### Run

```bash
make agent
```

or

```bash
python3 flexsoc_make_agent/agent_repl.py
```

### Behavior

* Reads user input
* Routes via embedding or LLM backend
* Streams Make output live

Exit with:

```text
/exit
```

---

## 10. webapp.py — Browser UI

### Script

**`webapp.py`**

### Purpose

Streamlit-based UI to:

* send natural language commands
* execute flows
* inspect logs and outputs

### Run

```bash
streamlit run flexsoc_make_agent/webapp.py
```

---

## 11. Logs & Debugging

All executions are logged under:

```
flexsoc_make_agent/logs/
```

Files include:

* `.tee.log` — full tool output
* `.route.json` — routing decision
* `.cmd.json` — executed command

---

## Mental Model

> **targets.json defines intent → embeddings select intent → catalog authorizes intent → runner executes intent**

---

## Design Principle

> **Make remains the source of truth.**
> **AI only decides *which* Make target to run — never *how*.**

