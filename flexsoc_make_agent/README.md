# flexsoc_make_agent (complete project)

This folder is meant to live inside your `flexsoc/` repo:

```
flexsoc/
  Makefile
  config.mk
  flexsoc_make_agent/
    tools/
    runner.py
    serve_ollama.py
    Modelfile.make
    catalog.json  (generated)
```

## Step 1 — Generate the catalog (targets/vars policy)
From `flexsoc/` root:

```bash
python flexsoc_make_agent/tools/build_catalog.py --makefile ./Makefile --config ./config.mk --out flexsoc_make_agent/catalog.json
python flexsoc_make_agent/runner.py catalog --catalog flexsoc_make_agent/catalog.json
```

## Step 2 — Create the Ollama router model
Pick a base model:

```bash
ollama pull qwen2.5:3b-instruct
ollama create flexsoc-make -f flexsoc_make_agent/Modelfile.make
```

## Step 3 — Run requests (dry-run first)
```bash
python flexsoc_make_agent/serve_ollama.py --repo-root . --dry-run "mostrami i comandi disponibili"
python flexsoc_make_agent/serve_ollama.py --repo-root . --dry-run "avvia il quickstart per l'IP"
```

If you want it to auto-fix invalid JSON/policy issues:
```bash
python flexsoc_make_agent/serve_ollama.py --repo-root . --dry-run --repair "installa le dipendenze"
```

## Step 4 — Execute for real (remove --dry-run)
```bash
python flexsoc_make_agent/serve_ollama.py --repo-root . "mostrami i comandi disponibili"
```

## Step 5 — Build datasets
Seed dataset (synthetic):
```bash
python flexsoc_make_agent/tools/make_seed_dataset.py --catalog flexsoc_make_agent/catalog.json --out flexsoc_make_agent/data/seed_train.jsonl --n-per-target 40
```

Gold dataset from logs (real usage):
```bash
python flexsoc_make_agent/tools/logs_to_jsonl.py --logs flexsoc_make_agent/logs --out flexsoc_make_agent/data/gold_train.jsonl --require-success
```

## Step 6 — Evaluate
Create `flexsoc_make_agent/data/eval.jsonl` (same format as train, but only user prompts matter).
Then:

```bash
python flexsoc_make_agent/tools/eval_json_only.py   --model flexsoc-make   --catalog flexsoc_make_agent/catalog.json   --runner flexsoc_make_agent/runner.py   --eval flexsoc_make_agent/data/eval.jsonl
```

## Safety notes
- Targets classified **HIGH risk** require `"risk_ack": true` or they are blocked.
- You can tighten/loosen policy in `catalog.json`.
