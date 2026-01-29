from __future__ import annotations
import os, json, urllib.request

class LLMError(RuntimeError): pass

def llm_complete(prompt: str, *, timeout_s: int = 180) -> str:
    url = os.environ.get("OLLAMA_URL", "http://127.0.0.1:11434").rstrip("/") + "/api/generate"
    payload = {
        "model": os.environ.get("OLLAMA_MODEL", "qwen2.5:3b-instruct"),
        "prompt": prompt,
        "stream": False,
        "options": {
            "temperature": float(os.environ.get("FSM_TEMPERATURE", "0.0")),
            "top_p": float(os.environ.get("FSM_TOP_P", "0.4")),
            "top_k": int(os.environ.get("FSM_TOP_K", "20")),
            "repeat_penalty": float(os.environ.get("FSM_REPEAT_PENALTY", "1.15")),
            "num_predict": int(os.environ.get("FSM_NUM_PREDICT", "2048")),
        },
    }
    req = urllib.request.Request(
        url, data=json.dumps(payload).encode("utf-8"),
        headers={"Content-Type": "application/json"}, method="POST"
    )
    try:
        with urllib.request.urlopen(req, timeout=timeout_s) as resp:
            body = resp.read().decode("utf-8")
        j = json.loads(body)
        out = j.get("response", "")
        if not isinstance(out, str):
            raise LLMError("Ollama response field is not a string")
        return out
    except Exception as e:
        raise LLMError(repr(e))
