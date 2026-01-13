# FlexSoC Make Agent

This project provides a **local agent** that allows you to control a large Makefile-based hardware flow (FlexSoC) using **natural language**, without model training and without a GPU.

The agent:

* interprets a natural language request
* selects the correct `make` target (via embeddings + rules)
* validates the command (safety)
* executes `make` **for real**
* streams live output to the terminal
* automatically saves **structured logs**
* optionally exposes everything via **Streamlit (browser UI)**

---

## High-level architecture

```
User (CLI / Browser)
        │
        ▼
serve_embed.py
  ├─ explicit overrides ("lancia view", "make view")
  ├─ embedding router (Ollama)
  ▼
runner.py
  ├─ validate (catalog.json)
  ├─ real make execution
  ├─ tee output (stdout + log)
  ▼
FlexSoC Makefile + toolchain
```

Key components:

* **Ollama** → embeddings (`nomic-embed-text`)
* **targets.json** → semantic description of Make targets
* **targets_embeddings.json** → fast routing database
* **catalog.json** → security allowlist
* **runner.py** → real execution + live logging
* **serve_embed.py** → agent brain
* **webapp.py** → browser UI

---

## Why embeddings instead of fine-tuning

* No GPU required
* Fully debuggable and deterministic
* Interpretable routing (scores + top-k)
* Incremental, low-risk improvements

The LLM **does not decide what to execute**. The router does.

---

## Full execution flow

### 1. User request

Valid examples:

* `avvia il quickstart dell'IP`
* `fai lint`
* `lancia view`

---

### 2. Explicit overrides (deterministic)

Implemented in `serve_embed.py`:

If the user writes:

* `make <target>`
* `lancia <target>`
* `esegui <target>`
* `run <target>`

👉 that target **always wins** over embedding routing.

Special handling:

* `view` vs `path_view`
* presence of keywords like `path`, `timing`

This removes critical ambiguities.

---

### 3. Embedding-based routing

If no explicit override is found:

1. embed the user query (Ollama)
2. cosine similarity against `targets_embeddings.json`
3. select best target
4. apply tie-break rules (`help_ip`, `ip_start`, …)

Debug tool:

```bash
python3 flexsoc_make_agent/embed_router.py "your query"
```

---

### 4. Validation (safety layer)

Before execution:

* target must be allowed by `catalog.json`
* variables must match regex constraints
* only whitelisted make flags are allowed

If validation fails → **nothing is executed**.

---

### 5. Real execution (`runner.py`)

**TEE mode**:

* live output streamed to terminal
* same output written to a log file
* GUI tools (e.g. `gtkwave`) are launched for real

Example:

```bash
python3 serve_embed.py "lancia view"
```

---

### 6. Automatic logging

Each run produces:

```
flexsoc_make_agent/logs/
  ├─ <timestamp>.tee.log      ← full execution output
  ├─ <timestamp>.route.json   ← router decision
  ├─ <timestamp>.cmd.json     ← validated make command
  ├─ <timestamp>.run.out
  └─ <timestamp>.run.err
```

Every run is **reproducible and auditable**.

---

## Browser usage (Streamlit)

Start UI:

```bash
streamlit run flexsoc_make_agent/webapp.py
```

Features:

* natural language input box
* dry-run / real execution toggle
* log viewer
* repository file browser (`rtl/`, `tb/`, `sim/`, `log/`, `doc/`, …)

⚠️ Intended for **local use only** (executes real commands).

---

## Debugging guide

### ❌ Wrong target selected

* inspect `embed_router.py`
* add synonyms/examples to `targets.json`
* rebuild embeddings

```bash
python3 tools/build_embeddings_ollama.py nomic-embed-text
```

---

### ❌ No live output / GUI not shown

* ensure runner is using `--tee`
* verify `DISPLAY` is set (GUI environment)

---

### ❌ JSON parsing issues in webapp

* stdout must contain **only JSON**
* informational messages must go to stderr

---

## Improving the system incrementally

### Improve routing quality

* enrich `targets.json` descriptions
* increase `topk`
* reduce `soft_gap`

### Improve UX

* disambiguation dropdowns
* auto-suggestions
* artifact previews (VCD, markdown, logs)

### Future extensions

* second agent for RTL generation
* multi-step workflows (command chaining)
* stricter safety policies for risky targets

---

## Project philosophy

* **Determinism over magic**
* **Inspectability over end-to-end LLMs**
* **Makefile as a stable API**

This system is designed for **hardware engineers**, not LLM demos.

---

## TL;DR

* no training
* no GPU
* natural language → make
* real execution + logs
* optional browser UI

👉 An agent you can **trust on a real hardware repository**.

