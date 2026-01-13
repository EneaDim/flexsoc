# Dataset definition (flexsoc make orchestrator)

## Format: JSONL
Each line is a JSON object:
- id: unique string
- messages: list of {role, content}
  - roles: system, user, assistant
- meta: optional

Assistant content MUST be ONLY JSON, matching:

Single-step:
{"action":"make","target":"<TARGET>","vars":{...},"make_flags":[...],"cwd":"."}

Or multi-step plan (max 3):
{"plan":[{...},{...}]}

## Why this works
You are training an SLM/LLM to perform *tool calling* (choose a make target + params),
not to write prose. The runner enforces the policy at execution time.

## Sources for training data
1) seed dataset (synthetic paraphrases per target)
2) gold dataset from logs (real requests + validated outputs + success)
3) repair dataset (validation failures -> corrected JSON)
