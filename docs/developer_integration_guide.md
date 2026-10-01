# FlexSoC Developer Integration Guide

Questa guida spiega **come estendere FlexSoC senza rompere ordine, ownership e semplicità**.

Non è una descrizione generale dell'architettura: per quella resta `docs/architecture.md`.
Qui l'obiettivo è pratico:

- voglio aggiungere un'opzione a un comando `fx`;
- voglio aggiungere un nuovo comando;
- voglio aggiungere una nuova analisi EDA;
- voglio generare un nuovo scaffold;
- voglio aggiungere un template;
- voglio supportare una nuova register interface;
- voglio capire quando FlexSoC può generare qualcosa automaticamente;
- voglio capire quando invece deve intervenire il designer;
- voglio aggiungere summary, show, debug, provenance, test ed E2E;
- voglio sapere quali file toccare e quali **non** toccare.

La regola principale è:

> **Prima ownership, poi leggibilità, poi minimalismo.**

Se una feature può essere implementata correttamente con poche righe nel suo owner naturale, non creare una nuova architettura.

---

## 1. Modello mentale

Il percorso pubblico normale è:

```text
utente
  ↓
fx <domain> [options]
  ↓
cli.py
  ↓
api.py
  ↓
TargetSession
  ↓
domain owner
  ↓
target operation
  ↓
CommandRequest
  ↓
ToolRunner
  ↓
Executor
  ↓
tool EDA
  ↓
native evidence
  ↓
summary.json
  ↓
show / debug / qualification
```

Esempio:

```text
fx sta --post-impl
  ↓
CLI interpreta --post-impl
  ↓
API risolve l'operation interna
  ↓
TargetSession applica lifecycle/provenance
  ↓
SignoffFlow / Sta
  ↓
OpenSTA via CommandRequest → ToolRunner → Executor
  ↓
timing.rpt + summary.json
```

L'utente deve pensare in termini di:

```text
dominio + opzioni
```

non in termini di operation ID interni.

Operation ID come:

```text
sta_post_impl
formal_csr_bmc
sim_post_impl_all
```

possono esistere internamente quando servono a:

- provenance;
- parent lineage;
- dependency graph;
- evidence ownership;
- target dispatch.

Non devono diventare automaticamente nuovi comandi pubblici.

---

# 2. Prima domanda: che tipo di modifica sto facendo?

Usa questo ordine.

```text
È una variante di una responsabilità già esistente?
        │
        ├─ sì → aggiungi un'opzione al comando esistente
        │
        └─ no
             │
             ├─ è una nuova operazione dello stesso dominio?
             │      └─ usa lo stesso owner; nuovo operation ID solo se serve
             │
             └─ è una responsabilità realmente nuova?
                    └─ valuta un nuovo target/domain owner
```

Esempi.

```text
STA post-synthesis vs post-implementation
→ stessa analisi
→ opzione --post-syn / --post-impl
→ stessa classe Sta
```

```text
Formal CSR vs formal design properties
→ stesso dominio formal
→ suite diverse
→ stessa classe FormalFlow
```

```text
Power analysis vs STA
→ responsabilità diverse
→ owner distinti nel dominio signoff
```

Non usare una nuova classe soltanto perché compare una nuova opzione CLI.

---

# 3. Aggiungere un'opzione a un comando esistente

Esempio desiderato:

```bash
fx sta --post-impl
```

invece di introdurre:

```bash
fx sta_post_impl
```

## 3.1 Percorso

Normalmente devi controllare:

```text
src/flexsoc/cli.py
src/flexsoc/api.py
src/flexsoc/backend/core/flow/target.py
owner del dominio
tests/test_api.py
tests/test_e2e_fx.py
docs/command_reference.md
```

Non significa che devi modificare tutti questi file ogni volta.

La modifica minima dipende da dove esiste già l'informazione.

## 3.2 CLI

La CLI deve soltanto:

- dichiarare l'opzione;
- validarne le combinazioni;
- passarla all'API;
- renderizzare output CLI-specifico.

Non deve implementare la semantica EDA.

Esempio concettuale:

```python
parser.add_argument("--post-impl", action="store_true")
```

Poi la CLI passa l'intento all'API.

Non scrivere in `cli.py`:

```python
if post_impl:
    crea_tcl()
    trova_spef()
    lancia_opensta()
```

Questa logica appartiene al backend.

## 3.3 API

L'API traduce l'intento pubblico in un'operazione interna.

```text
fx sta --post-impl
          ↓
target = sta_post_impl
```

L'operation ID interno è un dettaglio implementativo.

La API non deve contenere grandi blocchi di logica specifica STA.

## 3.4 Backend owner

L'owner deve ricevere parametri semplici:

```python
class Sta:
    def setup(self, *, stage: str):
        ...

    def run(self, *, stage: str):
        ...

    def debug(self, *, stage: str):
        ...

    def show(self, *, stage: str):
        ...
```

Non creare:

```text
StaPostSyn
StaPostImpl
StaFactory
StaStrategy
```

se la differenza è soltanto `stage`.

---

# 4. Aggiungere un nuovo comando pubblico

Un nuovo comando pubblico ha senso solo quando introduce una responsabilità che l'utente deve poter invocare direttamente.

Prima chiediti:

```text
È davvero un nuovo owner?
```

Se sì, il percorso normale è:

```text
1. definire il contract pubblico
2. individuare il domain owner
3. aggiungere il target
4. aggiungere il dispatch API
5. implementare setup/run/show/debug necessari
6. aggiungere StageContract se partecipa al lifecycle
7. aggiungere test
8. documentare il comando
```

Esempio:

```text
fx fusion
```

ha senso come comando distinto perché fusion analysis ha:

- input propri;
- tool invocation propria;
- evidence propria;
- summary proprio.

Al contrario:

```text
fx sta-post-impl
```

non dovrebbe essere un nuovo comando perché è sempre STA.

---

# 5. Quando serve un operation ID interno

Un operation ID interno è utile quando due operazioni dello stesso comando devono essere distinguibili da:

- provenance;
- StageContract;
- parent lineage;
- qualification;
- evidence paths;
- setup/run dependency.

Esempio:

```text
public:
fx sta --post-impl

internal:
sta_post_impl
```

Questo non è legacy se ha valore nel lifecycle.

Diventa legacy quando:

- viene esposto all'utente senza necessità;
- duplica un altro operation ID equivalente;
- serve soltanto per conservare una vecchia spelling CLI.

In development, elimina questi alias.

---

# 6. Aggiungere o integrare un tool EDA

Un backend EDA decide **cosa** eseguire.

L'Executor decide **dove e come** eseguirlo.

Il percorso obbligatorio è:

```text
CommandRequest
→ ToolRunner
→ Executor
```

Il domain backend non deve usare direttamente:

```python
subprocess.run(...)
```

## 6.1 Il backend prepara

- argv;
- cwd;
- env;
- input;
- output attesi;
- log path;
- collateral del tool.

## 6.2 ToolRunner / Executor possiedono

- local execution;
- SSH;
- exit code;
- stdout/stderr;
- execution transport.

Non aggiungere SSH/grid/Slurm logic al dominio.

## 6.3 Non implementare executor futuri prima che servano

Se oggi serve soltanto local:

```text
implementa local bene
```

non:

```text
ExecutorFactory
GridExecutorBase
SlurmExecutor
LsfExecutor
CloudExecutor
```

senza un caso reale.

---

# 7. Come funziona uno scaffold

Uno scaffold FlexSoC è collateral materializzato nel workspace.

Esempi:

- HJSON;
- RTL;
- top wrapper;
- filelist;
- reference model;
- test Python;
- SDC;
- Tcl;
- SBY;
- testbench;
- driver;
- monitor;
- formal property di un example design.

Il percorso concettuale è:

```text
source facts / model
        ↓
domain owner
        ↓
rendering data
        ↓
Templates.write(...)
        ↓
workspace file
```

Il backend Python possiede:

- parsing;
- semantica;
- scelta del template;
- dati da renderizzare;
- orchestration.

Il template possiede:

- testo statico significativo.

---

# 8. Esempio reale: `fx rtl_stub`

Il percorso è:

```text
fx rtl_stub
    ↓
cli.py
    ↓
api.py
    ↓
TargetSession
    ↓
Target(action="rtl_scaffold", domain="design")
    ↓
IpDesign.run_target()
    ↓
RtlFlow.init_scaffold()
    ↓
RTL collateral
```

`IpDesign` è l'owner del design IP.

`RtlFlow` è l'owner del collateral RTL dello scaffold.

La CLI non conosce i template.

---

# 9. Come vengono caricati i template

Il servizio è:

```text
src/flexsoc/backend/core/render/templates.py
```

e deve restare piccolo.

Uso:

```python
Templates.render(...)
Templates.write(...)
```

I template veri vivono sotto:

```text
src/flexsoc/templates/
├── design/
├── dv/
├── syn/
├── impl/
└── signoff/
```

Il loader Jinja usa il package `flexsoc` come source.

Concettualmente:

```python
PackageLoader("flexsoc", "templates")
```

quindi:

```python
templates.render(
    "design/rtl/example.sv.j2",
    top=top,
)
```

carica:

```text
src/flexsoc/templates/design/rtl/example.sv.j2
```

Lo stesso meccanismo deve funzionare dal wheel installato.

Per questo:

> ogni nuovo template richiede un package/wheel audit.

---

# 10. `Templates.write()` e ownership del file

Il comportamento normale è:

```text
file assente
→ render + write

file presente, force=False
→ preserva

file presente, force=True
→ rigenera
```

Ma non tutti gli artifact devono usare `force` nello stesso modo.

## Machine-owned

Esempio:

```text
script generato integralmente dal contract
```

può essere rigenerato con `--force`.

## Designer-owned dopo la creazione

Esempio:

```text
design-specific formal properties
authored SDC
custom test
```

lo scaffold iniziale può essere creato una volta, poi deve essere preservato.

L'owner deve scegliere intenzionalmente se propagare `force`.

Non aggiungere un framework separato per "authored scaffold" e "generated scaffold".

Usa il normale lifecycle/provenance.

---

# 11. Regola template: Python vs testo statico

Questa è una regola importante.

```text
Python
→ dati
→ semantica
→ parsing
→ orchestration

Template
→ testo statico generato
```

Esempio corretto:

```python
registers = self._register_data(spec)

templates.write(
    "design/rtl/core.sv.j2",
    path,
    registers=registers,
    clocks=clocks,
)
```

Evita grandi blocchi:

```python
lines = [
    "module ...",
    "always_ff ...",
    "assign ...",
    ...
]
```

quando il contenuto è principalmente SystemVerilog statico.

Viceversa, non spostare in Jinja un algoritmo solo per eliminare Python.

La regola è:

> **semantica in Python, testo statico nel template.**

---

# 12. Nota sullo scaffold RTL corrente

Nel codice storico possono ancora esistere percorsi non completamente uniformi.

In particolare, una parte della generazione single-clock può ancora costruire testo SystemVerilog in Python, mentre il multi-clock usa già template Jinja.

Questo non è il modello da replicare nelle nuove feature.

Per nuovo codice, la direzione deve essere:

```text
un modello
→ clocks come dati
→ template condiviso quando leggibile
```

e non:

```text
backend single-clock
backend multi-clock
```

Non unificare però due template se il risultato diventa pieno di branching illeggibile.

L'obiettivo è ridurre complessità reale, non il numero di file a tutti i costi.

---

# 13. FlexSoC-owned vs designer-owned

Questa distinzione decide quando automatizzare e quando fermarsi.

| Area | Owner normale | Automatica? | Integrazione manuale |
|---|---|---:|---|
| CSR/register RTL | FlexSoC | sì | solo se il contract non è rappresentabile |
| CSR docs/driver/model | FlexSoC | sì | raramente |
| CSR formal semantics | FlexSoC | sì | no per semantica standard supportata |
| Design functional formal | Designer | no | sì |
| RTL example scaffold | FlexSoC | sì | designer modifica dopo scaffold |
| Testbench structure | FlexSoC | sì | protocol/design stimulus può essere authored |
| Register adapter | FlexSoC | sì per adapter supportati | nuovo protocollo richiede implementazione |
| Clock/reset topology | FlexSoC quando derivabile | parziale | designer specifica ciò che non è affidabilmente deducibile |
| SDC | FlexSoC quando derivabile | parziale | constraints design-specific restano authored |
| Synthesis scripts | FlexSoC | sì | custom tool features solo se realmente richieste |
| Implementation config | FlexSoC + PDK data | sì quando derivabile | eccezioni PDK/design motivate |
| STA | FlexSoC | sì | timing intent deve essere reale, non inventato |
| Power workloads | Framework + designer | parziale | workload semanticamente design-specific |
| Qualification | FlexSoC | sì su evidence | waiver/review sono decisioni esplicite |
| Release package | FlexSoC | sì | contenuto authored viene incluso secondo contract |

---

# 14. Quando l'integrazione manuale è obbligatoria

FlexSoC deve fermarsi quando non può dedurre una decisione in modo affidabile.

## 14.1 Proprietà formal funzionali

FlexSoC può generare automaticamente:

```text
register semantics
```

perché conosce la regmap.

Non può inventare automaticamente:

```text
"questo DSP deve produrre Y entro tre cicli"
```

se quella semantica non è nel contract.

Queste property sono designer-owned.

## 14.2 Timing intent

FlexSoC può derivare:

- clock dichiarati;
- period;
- reset;
- relazioni esplicite;
- port ownership noto.

Non deve inventare:

- false path;
- multicycle path;
- asynchronous exceptions;
- generated-clock semantics non rappresentate.

Se non è deducibile:

```text
lascia collateral authored
```

## 14.3 Workload funzionali

Un power analysis può essere automatico nel flow.

Ma:

```text
quale workload rappresenta il caso reale?
```

può essere una decisione del designer.

## 14.4 IP esterni

Per un vendor IP FlexSoC può possedere:

- discovery;
- filelist;
- wrapper;
- integration metadata.

Non deve riscrivere semanticamente il vendor RTL per uniformarlo.

---

# 15. Formal: automatico vs authored

Il modello desiderato è:

```text
Formal
├── CSR
│   └── automatico / FlexSoC-owned
└── properties
    └── design-specific / designer-owned
```

CSR formal può essere algoritmico perché nasce da:

```text
HJSON / regmap
```

Design formal deve consumare property vere.

Non creare un file vuoto soltanto perché il lifecycle si aspetta un file.

```text
assenza di property
≠ property UNKNOWN
≠ property PASS
```

Una suite non applicabile deve essere distinta da una suite eseguita senza outcome valido.

---

# 16. Aggiungere una nuova register interface

Prima domanda:

```text
la differenza è protocollo o architettura del testbench?
```

La register interface è un adapter.

Esempi:

```text
tlul
reg_iface
axi_lite
```

Non deve decidere:

- single vs multiclock;
- struttura del test lifecycle;
- vector semantics;
- design behavior.

Percorso tipico:

```text
1. aggiungi il protocol adapter
2. aggiorna metadata/config
3. aggiorna RTL/top generation
4. aggiorna TB register transport
5. aggiorna filelist/vendor deps
6. testala sugli stessi scaffold
7. non duplicare il testbench
```

Non creare:

```text
TlulTestbench
AxiTestbench
RegIfaceTestbench
```

se la differenza è solo register transport.

---

# 17. Aggiungere summary / show / debug

Il contract è:

```text
run
→ native evidence
→ summary.json

show
→ legge summary.json

debug
→ show + diagnostica runtime
```

## Run

Può:

- eseguire il tool;
- raccogliere evidence;
- normalizzare;
- scrivere `summary.json`.

Non deve fare presentation.

## Show

Non deve:

- rieseguire;
- riparsare il main log;
- rifare setup.

## Debug

Può aggiungere:

- command;
- log path;
- raw artifact;
- report;
- excerpt mirato;
- hint supportato dall'evidence.

Non deve inventare la causa.

---

# 18. Aggiungere provenance

Non ogni helper interno richiede provenance.

Usala quando esiste un artifact/lifecycle FlexSoC-owned che deve essere:

- generato;
- consumato;
- invalidato;
- riprodotto;
- qualificato.

Uno strumento interno usato soltanto durante un'altra analisi può non avere un lifecycle autonomo.

Esempio:

```text
hierarchy extraction usata internamente da CDC
```

non deve automaticamente diventare:

```text
setup/run/show/debug + StageContract
```

Se non è un target reale, non fingere che lo sia.

---

# 19. StageContract

Aggiungi/modifica un `StageContract` solo quando il target partecipa realmente al dependency graph.

Deve descrivere almeno:

- scope;
- input;
- output/evidence;
- parent lineage;
- tool fingerprint;
- semantic configuration.

Non mettere configurazione irrilevante nel fingerprint.

Altrimenti invalidi stage senza motivo.

---

# 20. Aggiungere un nuovo scaffold

Checklist:

```text
1. chi possiede semanticamente lo scaffold?
2. quali input reali lo determinano?
3. contiene testo statico significativo?
4. deve essere editabile?
5. force deve sovrascriverlo?
6. deve partecipare alla provenance?
7. deve entrare nel package?
8. esistono test sul rendering?
```

Esempio:

```text
nuovo testbench monitor
```

Owner:

```text
DV / Testbench
```

non:

```text
Core
```

Template:

```text
templates/dv/...
```

non:

```text
templates/common/everything/
```

---

# 21. Aggiungere un template

Percorso:

```text
src/flexsoc/templates/<domain>/...
```

Backend:

```python
templates.write(
    "<domain>/path/template.ext.j2",
    output,
    ...
)
```

Dopo la modifica verifica sempre:

```bash
uv build --wheel
```

e controlla che il file sia nel wheel.

Un template che esiste nel source tree ma manca nel wheel è un bug.

---

# 22. Aggiungere un E2E

Un E2E deve verificare un contract importante.

Non deve verificare:

- stringhe fragili del log;
- dettagli interni irrilevanti;
- ordine accidentale di file non contrattuale.

Preferire:

```text
exit outcome
summary.json
artifact canonici
provenance state
real EDA result
```

Gli E2E devono essere parametrizzati sui dati quando la struttura è la stessa.

Esempio:

```text
single/multi
×
tlul/reg_iface/axi_lite
```

non sei funzioni duplicate.

---

# 23. Modalità E2E

Le modalità servono a fermare il flow a confini architetturali reali.

Esempio:

```text
formal
→ DV + formal

pre-pnr
→ synthesis + post-synthesis signoff
→ stop prima di implementation

full
→ flow completo
```

Non creare un flag per ogni singolo comando soltanto per abbreviare un test.

---

# 24. Come aggiungere una feature senza overengineering

Prima prova questa forma:

```python
class Owner:
    def existing_operation(self, *, new_option=False):
        if new_option:
            ...
```

Se resta leggibile, fermati lì.

Estrarre un nuovo metodo ha senso quando:

- possiede un concetto leggibile;
- riduce davvero il corpo principale;
- viene riusato;
- ha un contract proprio.

Creare una nuova classe ha senso quando:

- esiste una nuova responsabilità;
- ha stato/ownership propri;
- rende più chiaro il modulo.

Non creare classi solo per ridurre il numero di righe di un'altra classe.

---

# 25. Anti-pattern

Evita:

```text
Utils
Helpers
Manager
Factory
Strategy
Registry
Plugin
Provider
```

se il nome serve soltanto a spostare codice.

Evita:

```python
def run_sta(...):
    return Sta(...).run(...)
```

come funzione applicativa di modulo senza motivo.

Preferire:

```python
class Sta:
    def run(self):
        ...
```

---

# 26. File map per developer

## CLI

```text
src/flexsoc/cli.py
```

Parsing, frontend rendering, exit code.

## API

```text
src/flexsoc/api.py
```

Facade, target resolution, session creation.

## Lifecycle

```text
src/flexsoc/backend/core/flow/
```

TargetSession, target contract, lifecycle, provenance.

## Runtime

```text
src/flexsoc/backend/core/runtime/
```

CommandRequest, ToolRunner, Executor.

## Template service

```text
src/flexsoc/backend/core/render/templates.py
```

Jinja only.

## Templates

```text
src/flexsoc/templates/
```

Static generated text.

## Design

```text
src/flexsoc/backend/design/
```

IP/FSM/SoC design collateral.

## DV

```text
src/flexsoc/backend/dv/
```

TB, functional, formal, lint, CDC/RDC.

## Synthesis

```text
src/flexsoc/backend/syn/
```

Synthesis + EQY.

## Implementation

```text
src/flexsoc/backend/impl/
```

PnR.

## Signoff

```text
src/flexsoc/backend/signoff/
```

STA, GLS, power, fusion, SDC.

## Release

```text
src/flexsoc/backend/release/
```

Qualification, package, reporting, release lifecycle.

---

# 27. Checklist: nuova opzione CLI

```text
[ ] appartiene davvero a un comando esistente
[ ] parsing in cli.py
[ ] mapping API semplice
[ ] nessuna EDA logic in CLI/API
[ ] owner backend esistente
[ ] operation ID interno solo se necessario
[ ] callsite aggiornati
[ ] niente alias legacy
[ ] test API
[ ] E2E solo se cambia un contract reale
[ ] docs aggiornate
```

---

# 28. Checklist: nuovo comando

```text
[ ] nuova responsabilità reale
[ ] nome pubblico semplice
[ ] owner chiaro
[ ] Target definito
[ ] setup/run/debug/show solo se supportati
[ ] StageContract se necessario
[ ] CommandRequest → ToolRunner → Executor
[ ] summary.json se è un run EDA
[ ] show legge summary
[ ] debug usa evidence runtime
[ ] tests
[ ] docs
```

---

# 29. Checklist: nuovo scaffold/template

```text
[ ] owner del dominio corretto
[ ] semantic data in Python
[ ] static text nel template
[ ] Templates.write()
[ ] comportamento force deciso esplicitamente
[ ] nessun placeholder senza valore
[ ] nessun hardcode demo-specific nel backend generico
[ ] test rendering
[ ] package-data / wheel audit
```

---

# 30. Checklist: nuovo run EDA

```text
[ ] setup separato dal run
[ ] no subprocess nel backend
[ ] CommandRequest
[ ] ToolRunner
[ ] Executor
[ ] raw/native evidence
[ ] summary.json
[ ] outcome separato da freshness
[ ] show dal summary
[ ] debug diagnostico
[ ] failure tool con evidence ancora normalizzata quando possibile
[ ] EDA PASS dichiarato solo dopo vero run
```

---

# 31. Checklist finale prima del commit

```bash
git diff --check
uv run python -m compileall -q src tests
uv run ruff check src tests
uv run pytest -q tests/test_api.py
uv run pytest --collect-only -q tests/test_e2e_fx.py
uv build --wheel
```

Poi, solo quando necessario:

```text
E2E interessato
→ vero tool EDA
→ downstream realmente invalidato
```

Non rilanciare una matrice EDA intera senza motivo.

---

# 32. Regola conclusiva

Quando non sai dove aggiungere qualcosa, chiediti:

```text
Chi possiede questa decisione?
```

Poi:

```text
CLI      possiede l'intento dell'utente
API      possiede la facade
Session  possiede lifecycle/provenance comune
Domain   possiede la semantica
Target   possiede setup/run/debug/show
Runtime  possiede l'esecuzione
Template possiede testo statico
User     possiede ciò che FlexSoC non può dedurre affidabilmente
```

Se questa ownership è chiara, normalmente anche l'implementazione resta piccola.
