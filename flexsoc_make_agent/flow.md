# FlexSoC Make Agent — Complete Workflow Summary

This document is a **compact but complete guide** to understand, use, debug, and extend the FlexSoC Make Agent.

The goal is to control a **real hardware Makefile flow** using **natural language**, in a way that is:

* deterministic
* safe
* debuggable
* GPU-free
* suitable for real repositories

---

## 1. Goal

Translate natural language requests into **real `make` executions** on the FlexSoC repository, with:

* explicit safety validation
* live terminal output
* persistent logs
* optional browser UI

---

## 2. Technology stack

* **Ollama**

  * `nomic-embed-text` for embeddings
* **Python**
* **Make** (FlexSoC Makefile)
* **Streamlit** (optional UI)

---

## 3. High-level architecture

```
User (CLI / Browser)
        │
        ▼
serve_embed.py
  ├─ explicit overrides (verbs + target)
  ├─ embedding router
  ├─ safety validation
  ▼
runner.py
  ├─ real make execution
  ├─ tee (stdout → terminal + log)
  ▼
FlexSoC Makefile + tools
```

---

## 4. One-time setup

```bash
cd ~/github/flexsoc
python3 -m venv .venv
source .venv/bin/activate
pip install streamlit

ollama pull nomic-embed-text
```

---

## 5. Targets definition (semantic layer)

**File:**

```
flexsoc_make_agent/data/targets.json
```

Each entry defines:

* `target` → make target name
* `text` → natural language description + synonyms
* `risk` → informational (low / medium / high)

👉 This file is the **main lever** to improve routing quality.

---

## 6. Embedding generation (one time or after edits)

```bash
python3 flexsoc_make_agent/tools/build_embeddings_ollama.py nomic-embed-text
```

Produces:

```
flexsoc_make_agent/data/targets_embeddings.json
```

---

## 7. Security catalog

**File:**

```
flexsoc_make_agent/catalog.json
```

Defines:

* allowed `make` targets
* allowed variables + regex
* allowed make flags

If validation fails → **nothing is executed**.

---

## 8. Routing and override logic

### 8.1 Explicit overrides (highest priority)

If the user writes any of:

```
make <target>
lancia <target>
esegui <target>
run <target>
avvia <target>
```

👉 That target is executed **deterministically**, without embeddings.

Special handling:

* `view` vs `path_view`
* presence of words like `path`, `timing`, `critical`

---

### 8.2 Embedding-based routing

If no explicit override exists:

1. embed the user query
2. cosine similarity vs `targets_embeddings.json`
3. pick best target
4. apply tie-break rules (e.g. `help_ip`, `ip_start`)

Debug routing:

```bash
python3 flexsoc_make_agent/embed_router.py "your query"
```

---

## 9. Executing commands (CLI)

### Dry-run

```bash
python3 flexsoc_make_agent/serve_embed.py \
  --repo-root . \
  --catalog flexsoc_make_agent/catalog.json \
  --dry-run \
  "lancia view"
```

### Real execution

```bash
python3 flexsoc_make_agent/serve_embed.py \
  --repo-root . \
  --catalog flexsoc_make_agent/catalog.json \
  "lancia view"
```

✔ live terminal output
✔ GUI tools (e.g. `gtkwave`) are launched

---

## 10. Logging model

Each execution produces:

```
flexsoc_make_agent/logs/
  ├─ <ts>.tee.log      # full live output
  ├─ <ts>.route.json  # routing decision
  ├─ <ts>.cmd.json    # validated make command
  ├─ <ts>.run.out
  └─ <ts>.run.err
```

All runs are **reproducible and auditable**.

---

## 11. Browser UI (Streamlit)

```bash
streamlit run flexsoc_make_agent/webapp.py
```

Features:

* natural language command box
* dry-run / real execution toggle
* log viewer
* repository file browser (`rtl/`, `tb/`, `sim/`, `log/`, `doc/`, ...)

⚠️ Intended for local use only.

---

## 12. Mapping phrases to specific commands (important)

This system intentionally **does NOT rely on guessing**.

To map phrases or keywords to specific commands, you have **three clean options**.

---

### 12.1 Mapping via `targets.json` (recommended)

Example: map the concept of *place & route* to both `pnr` and `pnr_gui`.

```json
{
  "target": "pnr",
  "text": "place and route | pnr | physical design | backend flow"
}
```

```json
{
  "target": "pnr_gui",
  "text": "place and route gui | pnr gui | openroad gui | interactive pnr"
}
```

Then regenerate embeddings:

```bash
python3 tools/build_embeddings_ollama.py nomic-embed-text
```

Natural phrases like:

* `run pnr`
* `start place and route`
* `open pnr gui`

will route correctly.

---

### 12.2 Explicit multi-command mapping (advanced)

If you want **one phrase to trigger multiple make commands**, e.g.:

> "run full pnr"

→

```
make pnr
make pnr_gui
```

Do **not** overload a single target.

Instead:

1. create a **virtual target** in `targets.json`
2. expand it inside `serve_embed.py`

Example virtual target:

```json
{
  "target": "pnr_flow",
  "text": "full pnr | place and route flow | backend flow"
}
```

Then, in `serve_embed.py`, expand:

```python
if chosen == "pnr_flow":
    sequence = ["pnr", "pnr_gui"]
```

This keeps execution explicit and debuggable.

---

### 12.3 Hard override rules (last resort)

For extremely critical mappings:

```python
if "pnr" in user_text.lower():
    chosen = "pnr"
```

⚠️ Use sparingly — this bypasses semantic routing.

---

## 13. Debugging checklist

### Wrong target selected

* inspect `embed_router.py`
* improve `targets.json`
* regenerate embeddings

### GUI not launching

* verify `$DISPLAY`
* ensure runner uses tee mode

### Web UI parsing issues

* stdout must contain only JSON
* informational text → stderr

---

## 14. Improvement strategy

* prefer **data (targets.json)** over code changes
* keep overrides explicit
* avoid magic heuristics
* add new functionality via virtual targets

---

## 15. Philosophy

* **Determinism over magic**
* **Inspectability over end-to-end LLMs**
* **Makefile as a stable API**

This agent is meant for **real hardware work**, not demos.

---

## TL;DR

* natural language → make
* real execution
* live output + logs
* no training, no GPU
* optional browser UI

👉 A Makefile agent you can actually trust.

