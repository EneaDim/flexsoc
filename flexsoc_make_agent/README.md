# FlexSoC Make Agent

Questo progetto fornisce un **agente locale** che permette di controllare un grande Makefile (FlexSoC) usando **linguaggio naturale**, senza addestrare modelli e senza GPU.

L’agente:

* interpreta una richiesta in linguaggio naturale
* seleziona il target `make` corretto (via embedding + regole)
* valida il comando (sicurezza)
* esegue `make` **realmente**
* mostra output live a terminale
* salva automaticamente **log strutturati**
* opzionalmente espone tutto via **Streamlit (browser)**

---

## Architettura ad alto livello

```
User (CLI / Browser)
        │
        ▼
serve_embed.py
  ├─ override espliciti ("lancia view")
  ├─ embedding router (Ollama)
  ▼
runner.py
  ├─ validate (catalog.json)
  ├─ make execution
  ├─ tee output (stdout + log)
  ▼
FlexSoC Makefile + toolchain
```

Componenti chiave:

* **Ollama** → embedding (nomic-embed-text)
* **targets.json** → descrizione semantica dei target
* **targets_embeddings.json** → routing veloce
* **catalog.json** → allowlist di sicurezza
* **runner.py** → esecuzione reale + logging
* **serve_embed.py** → cervello dell’agente
* **webapp.py** → interfaccia browser

---

## Perché embedding e non fine‑tuning

* Nessuna GPU richiesta
* Debuggabile e deterministico
* Routing interpretabile (score + top‑k)
* Facile miglioramento incrementale

L’LLM **non decide cosa eseguire**: lo fa il router.

---

## Flusso completo di esecuzione

### 1. Richiesta utente

Esempi validi:

* `avvia il quickstart dell'IP`
* `fai lint`
* `lancia view`

---

### 2. Override espliciti (deterministici)

In `serve_embed.py`:

* Se l’utente scrive:

  * `make <target>`
  * `lancia <target>`
  * `esegui <target>`

👉 **vince sempre** quel target

Gestione speciale:

* `view` vs `path_view`
* presenza di parole chiave come `path`, `timing`

Questo elimina ambiguità critiche.

---

### 3. Routing a embedding

Se non c’è override:

1. embedding della query (Ollama)
2. cosine similarity con `targets_embeddings.json`
3. selezione best target
4. tie‑break rules (es. help_ip, ip_start)

Debug disponibile via:

```bash
python3 flexsoc_make_agent/embed_router.py "query"
```

---

### 4. Validazione (sicurezza)

Prima di eseguire:

* target ∈ catalog.json
* variabili matchano regex
* make flags consentiti

Se fallisce → **nessun comando eseguito**.

---

### 5. Esecuzione reale (`runner.py`)

Modalità **TEE**:

* output live su terminale
* stesso output salvato in log
* GUI tools (es. gtkwave) partono realmente

Esempio:

```bash
python3 serve_embed.py "lancia view"
```

---

### 6. Logging automatico

Per ogni run:

```
flexsoc_make_agent/logs/
  ├─ <timestamp>.tee.log      ← output completo
  ├─ <timestamp>.route.json   ← decisione router
  ├─ <timestamp>.cmd.json     ← comando make
  ├─ <timestamp>.run.out
  └─ <timestamp>.run.err
```

Questo rende ogni run **riproducibile e auditabile**.

---

## Uso via Streamlit (browser)

Avvio:

```bash
streamlit run flexsoc_make_agent/webapp.py
```

Funzionalità:

* textbox linguaggio naturale
* toggle dry‑run / real execution
* viewer log
* file browser (rtl/, tb/, sim/, log/, doc/…)

⚠️ Da usare **solo localmente** (esegue comandi reali).

---

## Debug: problemi comuni

### ❌ Target sbagliato

* controlla `embed_router.py`
* aggiungi sinonimi in `targets.json`
* rigenera embedding

```bash
python3 tools/build_embeddings_ollama.py nomic-embed-text
```

---

### ❌ Output non visibile

* assicurati che runner usi `--tee`
* verifica che `DISPLAY` sia settato (GUI)

---

### ❌ Parsing JSON in webapp

* stdout deve contenere **solo JSON**
* messaggi informativi vanno su stderr

---

## Miglioramento incrementale del sistema

### Migliorare il routing

* aggiungere esempi testuali in `targets.json`
* aumentare `topk`
* ridurre `soft_gap`

### Migliorare UX

* dropdown di disambiguazione
* suggerimenti automatici
* preview artefatti (VCD, markdown)

### Estensioni future

* secondo agente per RTL generation
* chaining di comandi (workflow)
* policy di sicurezza per target "rischiosi"

---

## Filosofia del progetto

* **Determinismo > magia**
* **Ispezionabile > end‑to‑end LLM**
* **Makefile come API**

Questo sistema è pensato per **hardware designer**, non per demo LLM.

---

## TL;DR

* nessun training
* nessuna GPU
* linguaggio naturale → make
* output reale + log
* browser opzionale

👉 Un agente che puoi **fidarti di usare su un repo reale**.

