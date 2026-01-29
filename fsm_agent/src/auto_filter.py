from __future__ import annotations
import re
from typing import List

# Pack di keyword (trigger -> parole correlate)
PACKS = {
    "dma": ["dma","burst","beat","bus","grant","irq","interrupt","descriptor","scatter","gather"],
    "ecc": ["ecc","scrub","scrubber","syndrome","correct","correction","uncorrectable","uncorr","parity","sbe","dbe"],
    "axi": ["axi","axil","axi-lite","aw","w","b","ar","r","ready","valid","handshake","write","read"],
    "csr": ["csr","register","reg","decode","exec","execute","resp","response","illegal","address","opcode"],
    "stream": ["stream","ready","valid","stall","backpressure","fifo","last","tlast","tkeep"],
    "arbiter": ["arbiter","arbitration","grant","gnt","req","request","round","robin","rr","priority"],
    "power": ["low","power","sleep","wakeup","wake","clock","gate","gating","standby"],
    "flush": ["flush","invalidate","prefetch","pipeline"],
    "error": ["error","fault","fatal","shutdown","clear","recovery"],
}

# Parole tecniche singole che vale sempre includere se presenti
ALWAYS = ["error", "timeout", "retry", "flush", "prefetch", "stall", "interrupt", "low_power", "shutdown"]

def infer_gold_filter(spec_text: str) -> str:
    """
    Ritorna una stringa tipo: 'dma,burst,bus,irq,...' oppure '' se non trova nulla.
    """
    t = spec_text.lower()
    # tokenizza in modo semplice
    tokens = set(re.findall(r"[a-z0-9_\-]+", t))

    kws: List[str] = []

    # trigger packs
    for trigger, pack in PACKS.items():
        if trigger in tokens:
            for w in pack:
                kws.append(w)

    # heuristics per casi comuni (anche senza trigger esatto)
    if ("ready" in tokens and "valid" in tokens) or ("handshake" in tokens):
        for w in PACKS["stream"]:
            kws.append(w)

    if ("aw" in tokens or "ar" in tokens) and ("w" in tokens or "r" in tokens):
        for w in PACKS["axi"]:
            kws.append(w)

    # always if present
    for w in ALWAYS:
        if w in tokens:
            kws.append(w)

    # dedup preservando ordine
    seen = set()
    out = []
    for w in kws:
        if w not in seen:
            seen.add(w)
            out.append(w)

    return ",".join(out)
