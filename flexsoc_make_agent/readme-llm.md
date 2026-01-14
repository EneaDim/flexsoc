# readme-llm.md — FlexSoC (EneaDim/flexsoc)

> **Scopo**: questo è l’UNICO documento su cui un LLM/agent deve fare affidamento per capire come usare correttamente questo repo e, in particolare, come tradurre richieste in linguaggio naturale in comandi `make <target>` **senza inventare** target, file o flussi.
>
> Questo repo è un **ambiente open-source modulare** per sviluppo di IP digitali e integrazione SoC, ispirato anche allo stile lowRISC/OpenTitan (hjson + regtool + doc generation) ma con flussi che supportano anche ecosistemi tipo PULP.

---

## 0) Regola d’oro per l’LLM

**Non indovinare**.

Se devi rispondere:

* **con un comando**: scegli un `make <target>` che esiste davvero.
* **con una spiegazione (“come faccio…?”)**: fonda la spiegazione su:

  1. cosa fanno i target (dalla conoscenza di questo documento e dall’output `make -n` / help),
  2. prerequisiti (file attesi, step prima/dopo),
  3. path e artefatti realmente prodotti.

Quando sei incerto:

* proponi `make help` o la guida specifica (`help_ip`, `help_soc`, `help_doc`, `help_fsm`).

---

## 1) Entrypoint e filosofia del repo

### 1.1 Entrypoint principale: Makefile

La UX principale è un Makefile ricco di target che:

* prepara la struttura cartelle (`setup`),
* genera template/config (hjson),
* genera register map (regtool),
* genera documentazione (Markdown generator),
* prepara testbench e simulazioni,
* visualizza waveform (GTKWave),
* supporta cocotb + regressioni,
* supporta sintesi (Yosys), STA (OpenSTA), power, PnR (OpenROAD),
* supporta flusso SoC (xbar + fusesoc + ibex/SoC flow),
* include tool di generazione FSM.

### 1.2 Dipendenze tool (concetto)

Il repo usa tool open-source tipici:

* `gtkwave` (waveform)
* `iverilog` / `verilator` (sim)
* `yosys` (synth)
* `OpenSTA` (sta/power)
* `OpenROAD` (pnr)
* tool lowRISC (regtool)

*Nota agent*: non serve elencare tutti i pacchetti in risposta; serve sapere **quale target li usa** e **cosa succede se mancano**.

---

## 2) Struttura repo (high level)

Cartelle top-level (vista sintetica):

* `ips/` — IP riusabili / esempi
* `verilog/` — RTL / top
* `sw/` — software / drivers
* `scripts/` — script Python e helper per generazione/flow
* `util/` — tool (es. regtool vendorizzato, helper)
* `vendor/` — dipendenze esterne fetchate
* `fsm_gen/` — generatore FSM
* `flexsoc_make_agent/` — agent che fa routing NL→make

File importanti:

* `Makefile` — principale
* `config.mk` — configurazione del progetto (top/module, interfaccia reg, path)
* `deps.sh` / `requirements.txt` — setup dipendenze

---

## 3) Convenzioni: directory di lavoro e artefatti

Il Makefile crea (o usa) directory standard. Concettualmente:

* `rtl/` — generated RTL / wrapper / stub
* `tb/` — testbench
* `sim/` — output simulazione (VCD/FST, log)
* `syn/` — output sintesi (netlist)
* `signoff/` — report finali (STA/power/sdf)
* `doc/` — documentazione generata
* `data/` — hjson/config
* `lint/` — output lint
* `logs/` — log di flow
* `ors/` — OpenROAD scripts/output

*Nota agent*: se un utente chiede “dove trovo X?” rispondi con:

1. target che genera X,
2. directory tipica in cui finisce (sim/syn/signoff/doc/logs),
3. se necessario: "prima fai setup/sim/syn".

---

## 4) Makefile: guida completa ai target (per intent routing)

Questa sezione è organizzata come nel Makefile, per “intento”.

### 4.1 Help / guide

Target:

* `help` — entrypoint: mostra le guide disponibili
* `help_ip` — guida IP flow
* `help_soc` — guida SoC flow
* `help_doc` — guida documentazione
* `help_fsm` — guida FSM generator

**Quando usarli** (LLM policy):

* se l’utente chiede “cosa posso fare?” → `make help`
* se l’utente è nel contesto IP (“voglio creare un IP”, “regmap”, “tb”, “lint”, “sim”) → `make help_ip`
* se chiede SoC / bus / xbar / ibex / fusesoc → `make help_soc`
* se chiede doc → `make help_doc`
* se chiede FSM → `make help_fsm`

### 4.2 Setup folder structure

Target:

* `setup` — crea cartelle necessarie.

**Tipico prerequisito**: molti target dipendono da `setup` direttamente o indirettamente.

### 4.3 Generazione template HJSON

Target:

* `hjson` — genera template `.hjson` per IP/top.

**Quando**: se l’utente vuole iniziare un IP partendo da definizione HJSON.

### 4.4 Generazione register map (regtool)

Target:

* `reg` — genera register map e/o RTL correlato a partire da HJSON.

**Quando**: richieste tipo “genera CSR/regmap”, “voglio l’interfaccia TL-UL o register interface PULP”.

### 4.5 Generazione documentazione Markdown

Target:

* `doc` (o target di doc generation; in alcuni progetti può avere varianti)

**Quando**: “genera documentazione IP”, “aggiorna la doc”, “dammi il markdown”.

### 4.6 Fetch vendor da HJSON

Target:

* (target fetch vendor, dipende dalla nomenclatura; nel Makefile esiste una sezione dedicata)

**Quando**: “scarica dipendenze”, “vendor fetch”, “prendi IP da GitHub”

### 4.7 Setup SystemVerilog testbench

Target:

* (target per generare TB, spesso parte di ip_start o step esplicito)

**Quando**: “genera testbench”, “crea skeleton TB”.

### 4.8 Simulazione RTL

Target tipici:

* `sim` (o equivalente)
* `compile` (se separato)

**Quando**: “lancia simulazione”, “esegui testbench”, “voglio un VCD”.

**Prerequisito**: spesso serve TB configurato e design generato.

### 4.9 Viewing waveforms (RTL sim)

Target:

* `view` — **target standard per vedere waveform senza specificare altro**.

Varianti possibili (esempi frequenti nel repo):

* `view_cocotb` — view waveform da cocotb
* `tb_view` — view wave della regression TB (path predefiniti)
* `view_presyn` / `view_syn` — view waveform in contesti pre/post-synth
* `path_view` — view (o analisi) del timing path/critical path

**Policy per l’LLM**:

* Se l’utente chiede genericamente “vedere waveform” → proponi `make view`.
* Se l’utente chiede waveform della regression TB o cita `tb/regression` → proponi `make tb_view`.
* Se chiede post-synth → `make view_syn` (o `view_presyn` se esplicitamente pre-synth).

**Prerequisito**:

* serve un dump (VCD/FST). Se manca, la risposta deve dire: "prima fai `make sim` (o target di sim)".

### 4.10 Cocotb

Sezione cocotb include:

* target di setup cocotb
* target di esecuzione test cocotb
* `view_cocotb`

**Quando**: “voglio usare cocotb”, “test python”, “pytest + sim”, ecc.

### 4.11 Regression

Target:

* `regression` — esegue regressione test.

Altri target correlati (spesso presenti):

* varianti per sinth (`syn`, `syn_v`, `syn_sv`)
* `plot_postsyn` (grafici/plot post-synth)
* `view_presyn*`

**Quando**: “run regression”, “esegui tutti i test”.

### 4.12 Simulazione post-synthesis netlist

Target:

* `sim_syn` — sim su netlist post-synth.

**Quando**: “simula la netlist”, “post-synthesis simulation”.

### 4.13 SW drivers

Target:

* target driver/firmware (dipende dal repo; esiste sezione dedicata)

**Quando**: “genera driver”, “compila sw”, “integrazione sw”.

### 4.14 FSM flow

Target tipici:

* `fsm_setup`, `fsm_tutorial`, `fsm_load`, `fsm_plot`, `fsm_save`, `clean_fsm`, `clean_fsm_all`

**Quando**: “generare FSM”, “visualizzare FSM”, “import/export FSM”.

### 4.15 FuseSoC

Target:

* `fsoc_init` — inizializza fusesoc
* `fsoc` — esegue fusesoc flow

**Quando**: “fusesoc”, “build core”, “simulate core via fusesoc”.

### 4.16 XBAR + SoC integration

Target (indicativi, presenti nel Makefile):

* `xbar`, `xbar_init`, `xbar_build`
* `soc_ibex_fetch`, `soc_ibex`
* `soc`, `soc_flow`, `soc_sim`, `soc_run`, `soc_view`

**Quando**:

* “genera interconnect”, “xbar”, “TL-UL crossbar” → `make xbar` (o init/build se necessario)
* “ibex”, “fetch ibex” → `make soc_ibex_fetch`
* “integra SoC”, “build SoC” → `make soc` / `make soc_flow`
* “sim SoC” → `make soc_sim`
* “run SoC” → `make soc_run`
* “view SoC waves” → `make soc_view`

### 4.17 SDC, Synthesis, STA, Power, Signoff

Target/Sezioni:

* `setup_sdc` (setup SDC)
* `setup_syn` (setup synthesis Yosys)
* target `syn`/`synth` (a seconda del Makefile)
* target STA: `sta`, `sta_violators` (per report violazioni)
* target power: `power`
* target SDF: `sdf`

**Quando**:

* “voglio un primo PPA / synth trial” → `make syn`
* “voglio timing report” → `make sta`
* “fammi vedere i violators” → `make sta_violators`
* “power estimate” → `make power`
* “genera SDF” → `make sdf`

### 4.18 PnR (OpenROAD)

Target tipici:

* `pnr` — esegue physical implementation
* `pnr_gui` — esegue con GUI

**Quando**:

* “RTL-to-GDS”, “openroad flow”, “place & route” → `make pnr`
* “apri GUI OpenROAD” → `make pnr_gui`

### 4.19 Cleaning

Target:

* `clean` e molte varianti: `clean_rtl`, `clean_sim`, `clean_syn`, `clean_signoff`, `clean_doc`, `clean_sw`, `clean_soc`, `clean_pnr`, `clean_log`, `clean_all`, ecc.

**Quando**:

* “ripulisci sim” → `make clean_sim`
* “ripulisci tutto” → `make clean_all`

---

## 5) Flussi consigliati (playbook operativo)

### 5.1 Quickstart IP (high level)

Target chiave:

* `ip_start`

Cosa fa (concettualmente):

1. setup struttura
2. genera HJSON
3. genera regmap/CSR
4. genera doc
5. genera stub/wrapper RTL
6. genera testbench
7. lint
8. sim

**Risposte dell’LLM**:

* Se l’utente dice “voglio iniziare un IP” → suggerisci `make ip_start` e spiega che poi deve riempire il file `*_core.sv` con la logica.

### 5.2 Flow “manuale” (step-by-step)

Quando l’utente vuole controllo:

1. `make setup`
2. `make hjson`
3. `make reg`
4. `make doc`
5. (scrivi logica core)
6. `make lint` (se presente)
7. `make sim`
8. `make view`

### 5.3 Debug waveform

* Se l’utente chiede “come vedere waveform?”

  * spiegazione: serve un dump (`.vcd`/`.fst`) prodotto da sim
  * comando: `make view`
* Se l’utente vede un path specifico tipo `tb/regression/sim/*.vcd`:

  * suggerisci `make tb_view`

### 5.4 Post-synth

1. `make syn`
2. `make sim_syn` (se serve)
3. `make view_syn` (se disponibile)
4. `make sta` / `make power`

### 5.5 PnR

1. `make pnr` (batch)
2. `make pnr_gui` (debug interattivo)

### 5.6 SoC

1. `make help_soc` (per capire la guida)
2. `make soc_ibex_fetch` (se necessario)
3. `make xbar` / `make xbar_build`
4. `make soc_flow`
5. `make soc_sim` / `make soc_run`
6. `make soc_view`

---

## 6) flexsoc_make_agent: comportamento e contratti

### 6.1 Cosa fa

È un layer che:

* riceve una richiesta NL (IT/EN)
* sceglie un `target` (deterministic override o embedding)
* produce un JSON comando (azione `make`)
* valida con runner
* esegue (o fa dry-run)

### 6.2 Override esplicito (massima priorità)

Se l’utente scrive:

* “make view”
* “esegui view”
* “run pnr_gui”

Allora **non fare routing semantico**: esegui quel target, se esiste.

### 6.3 Routing embedding (seconda priorità)

* Query → embedding
* Similarità coseno con DB `targets_embeddings.json`
* Scelta best se score ≥ soglia (`min-score`), altrimenti fallback `help`.

**Con DB bilingue**:

* `embedding_it` per query IT
* `embedding_en` per query EN
* se lingua incerta: valuta entrambe e prendi max.

### 6.4 Tie-break rules (rule-based)

Esistono regole “soft” per preferire certi target se sono “quasi pari”:

* quickstart → `ip_start`
* ip+help → `help_ip`

**Raccomandazione**: aggiungi una regola “waveform generic → view” solo se non riesci a far vincere `view` migliorando i testi di embedding.

### 6.5 Output e JSON discipline

Se l’agent è usato da una webapp che pretende JSON-only, allora:

* stdout deve essere **solo JSON**
* log/diagnostica va su file o stderr

---

## 7) Come far sì che l’LLM risponda bene alle domande “come…?”

### 7.1 Problema

Il router può scegliere il target giusto, ma l’utente spesso vuole una **spiegazione**.

### 7.2 Soluzione robusta: RAG + introspezione dei comandi

Per risposte accurate senza testo statico:

1. **RAG su documentazione repo**

   * `README.md`, `flow.md`, guide, tutorial, sezioni help
2. **Introspezione “ground truth”**

   * `make -n <target>` per vedere cosa succede davvero
   * opzionale: controlli file (esistenza `.vcd`, report)

L’LLM riceve come contesto:

* richiesta utente
* target scelto
* output `make -n` del target
* chunk doc rilevanti

e produce una spiegazione concreta:

* prerequisiti
* step
* comando finale

### 7.3 Heuristica di intent

Se la frase è interrogativa ("come", "how", "?", "spiegami"):

* non eseguire direttamente (o al massimo dry-run)
* genera risposta explain-first (LLM)

Se è imperativa ("esegui", "make", "run"):

* esegui o dry-run.

---

## 8) targets.json (schema raccomandato per embedding)

Per avere routing stabile e bilingue, usare uno schema “ricco”, per target:

* `target` (string)
* `risk` (low/medium/high)
* `depends_on` (lista)
* `embedding_text`:

  * `it`: title/summary/queries/keywords/negative
  * `en`: title/summary/queries/keywords/negative

**Linee guida**:

* `title`: 3–8 parole
* `summary`: 1–3 frasi
* `queries`: 6–15 query naturali (domande reali)
* `keywords`: 10–30 keyword tecniche
* `negative`: 6–15 “non questo” per disambiguare

Esempio: per `view` includere keywords `waveform, gtkwave, vcd, fst, signals, trace` e query italiane tipo “come faccio a vedere le waveform?”.

---

## 9) Risposte modello (stile consigliato)

### 9.1 Richiesta: “come faccio a vedere le waveform?”

Risposta (explain-first):

1. Spiega prerequisito: serve dump `.vcd`/`.fst` prodotto dalla simulazione.
2. Spiega cosa fa `make view`: apre GTKWave sul dump generato.
3. Se non esiste dump, suggerisci `make sim` prima.
4. Chiudi con comando copiabile: `make view`.

### 9.2 Richiesta: “run pnr gui” / “make pnr_gui”

* Esegui direttamente `make pnr_gui` (override).

### 9.3 Richiesta: “voglio iniziare un IP”

* Suggerisci `make ip_start`, spiega che genera hjson/regmap/doc/stub/wrapper/tb e poi si implementa `*_core.sv`.

### 9.4 Richiesta: “non so cosa fare / quali comandi ci sono?”

* Suggerisci `make help` e, se contesto IP, `make help_ip`.

---

## 10) Checklist anti-allucinazione (da seguire sempre)

1. Il target esiste? (deve essere in `targets_embeddings.json` / Makefile)
2. L’utente vuole spiegazione o esecuzione?
3. Hai citato prerequisiti? (setup/sim/syn)
4. Hai indicato output/artefatti? (sim/, syn/, signoff/, doc/)
5. Hai dato un comando copiabile (`make <target>`)?

---

## 11) Appendice: target list (auto-derivabile)

Il repo contiene molte decine di target; l’agent deve far affidamento sul proprio DB embeddings.
Comunque, categorie di target molto comuni includono:

* help: `help`, `help_ip`, `help_soc`, `help_doc`, `help_fsm`
* setup: `setup`
* hjson/reg/doc: `hjson`, `reg`, `doc`
* sim/view: `sim`, `view`, `tb_view`, `view_syn`, `sim_syn`
* cocotb: target cocotb + `view_cocotb`
* regression: `regression`
* sta/power/signoff: `sta`, `sta_violators`, `power`, `sdf`
* openroad/pnr: `pnr`, `pnr_gui`
* fusesoc/soc: `fsoc_init`, `fsoc`, `xbar*`, `soc*`
* fsm: `fsm_*`
* clean: `clean*`

---

## 12) Come aggiornare questo documento

Ogni volta che aggiungi o rinomini target nel Makefile:

1. aggiorna `targets.json` (title/summary/queries/keywords IT+EN)
2. rigenera `targets_embeddings.json`
3. aggiorna eventuale doc RAG
4. aggiorna questa guida se cambiano concetti/flow (non solo nomi).

