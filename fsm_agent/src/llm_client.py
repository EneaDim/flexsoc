from __future__ import annotations
import json
import os
import urllib.request
import urllib.error

from .json_guard import extract_first_json

class LLMClient:
    def __init__(self, host: str | None = None, model: str | None = None, timeout_s: int = 600):
        self.host = host or os.environ.get("OLLAMA_HOST", "http://localhost:11434")
        self.model = model or os.environ.get("OLLAMA_MODEL", "qwen2.5:3b-instruct")
        self.timeout_s = timeout_s

        # dove salvare SEMPRE l'ultimo raw (così debug non dipende dal return)
        self._raw_debug_path = os.path.abspath(
            os.path.join(os.path.dirname(__file__), "..", "data", "inbox", "out.raw_llm.txt")
        )

    def complete(self, prompt: str) -> str:
        url = self.host.rstrip("/") + "/api/generate"
        payload = {
            "model": self.model,
            "prompt": prompt,
            "stream": False,
            "format": "json",
            "options": {
                "temperature": 0.0,
                "top_p": 1.0,
                "num_ctx": 2048,
                "num_predict": 2500
            },
        }

        req = urllib.request.Request(
            url=url,
            data=json.dumps(payload).encode("utf-8"),
            headers={"Content-Type": "application/json"},
            method="POST",
        )

        try:
            with urllib.request.urlopen(req, timeout=self.timeout_s) as resp:
                body = resp.read().decode("utf-8")
        except urllib.error.URLError as e:
            raise RuntimeError(
                f"Errore chiamando Ollama a {url}. "
                f"Assicurati che 'ollama serve' sia in esecuzione. Dettagli: {e}"
            )

        data = json.loads(body)
        text = (data.get("response", "") or "")

        # DEBUG: salva sempre la risposta raw (anche se poi il parser fallisce a valle)
        try:
            os.makedirs(os.path.dirname(self._raw_debug_path), exist_ok=True)
            with open(self._raw_debug_path, "w", encoding="utf-8") as f:
                f.write(text)
        except Exception:
            pass

        return extract_first_json(text.strip())
