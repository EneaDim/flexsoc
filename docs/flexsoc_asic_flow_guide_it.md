# Guida al flow ASIC di FlexSoC

> **Scopo.** Questo documento descrive il ciclo di vita digital-ASIC attualmente implementato da FlexSoC come un unico flusso ingegneristico coerente: dall'intento dei registri di controllo e stato e dalla generazione automatica del collateral RTL, passando per verifica strutturale e funzionale, sintesi, equivalence checking, sign-off timing/power, implementazione fisica con OpenROAD, gate-level verification sul netlist routed e sign-off fisico finale. Definisce inoltre i due principali blocchi di roadmap che non fanno ancora parte del flow qualificato: DFT e integrazione delle hard memory.
>
> L'obiettivo è spiegare **cosa fa FlexSoC, perché esiste ogni stage, quali script e tool vengono coinvolti, quali evidenze produce e cosa significa realmente un PASS**. Non è un tutorial di progettazione RTL e non è il riferimento completo di ogni opzione CLI. Per la sintassi esatta dei comandi usare `docs/command_reference.md`; per ownership e policy di rigenerazione usare `docs/project_lifecycle.md` e `docs/ip_development_guide.md`.

---

## 1. Il flow in una pagina

FlexSoC tratta una build ASIC come una catena di contratti. Ogni stage consuma pochi input espliciti e produce artifact che vengono qualificati prima di considerare affidabile lo stage successivo.

```text
Architettura / intent clock-reset / intent CSR
                    │
                    ▼
       Generazione CSR e interfacce
       HJSON → reg RTL/docs/regmap/driver
                    │
                    ▼
               RTL scaffold
        struttura single-clock o N-clock
                    │
                    ▼
          elaborazione RTL ordinata
                    │
       ┌────────────┼─────────────┐
       ▼            ▼             ▼
     Lint        CDC / RDC       Formal
 Slang+Verilator strutturale     BMC / prove / cover
       │            │             │
       └────────────┼─────────────┘
                    ▼
          Verifica funzionale
        scenario/vector DSL condiviso
          ┌──────────┴──────────┐
          ▼                     ▼
     SystemVerilog            cocotb
          │                     │
          └──────────┬──────────┘
                     ▼
                  Coverage
                     │
                     ▼
                  Sintesi
            Yosys + ABC + Liberty
                     │
                     ▼
          RTL ↔ synthesis EQY
                     │
                     ▼
       Sign-off pre-implementation
         STA + SDF + power estimate
         + post-syn GLS/activity/fusion
                     │
                     ▼
           Implementazione fisica
                  ORFS/OpenROAD
 floorplan → PDN → placement → CTS → routing → finish/extraction
                     │
                     ▼
       Sign-off post-implementation
 SPEF STA + routed SDF + GLS + power + fusion
                     │
                     ▼
              Physical sign-off
 route DRC + antenna + GDS DRC + LVS + IR/PDN
                     │
                     ▼
          metrics / manifest / check
```

Lo stesso macro-flow vale per uno o più clock. La topologia dei clock è configurazione del design, non un backend separato.

### Come leggere questa guida

Per una prima lettura conviene seguire le sezioni in ordine. Per lavorare sul codice, questa tabella collega direttamente i concetti del flow ai file backend che li generano o li qualificano.

| Responsabilità nel flow | Implementazione FlexSoC principale |
| --- | --- |
| template CSR HJSON | `src/flexsoc/backend/design/regs.py` |
| helper Python CSR/regmap | `src/flexsoc/backend/design/regs.py` |
| collateral driver software | `src/flexsoc/backend/design/regs.py` |
| starter RTL single/N-clock | `src/flexsoc/backend/design/rtl.py` |
| orchestrazione lint | `src/flexsoc/backend/dv/dv.py` |
| estrazione e qualification CDC/RDC | `src/flexsoc/backend/dv/cdc.py` |
| generazione scenari/vettori | `src/flexsoc/backend/design/model.py`, `src/flexsoc/backend/dv/functional.py`, `dv/testbench.py`, `dv/functional.py` |
| generazione testbench cocotb | `src/flexsoc/backend/dv/testbench.py` |
| generazione formal CSR/design | `src/flexsoc/backend/dv/formal.py` |
| script Yosys/ABC | `src/flexsoc/backend/syn/syn.py` |
| equivalence RTL↔synthesis | `src/flexsoc/backend/syn/eqy.py` |
| SDC/STA/SDF/power/fusion OpenSTA | `src/flexsoc/backend/signoff/sta.py`, `power.py`, `fusion.py` |
| GLS post-syn/post-PnR | `src/flexsoc/backend/signoff/gls.py` |
| configurazione fisica ORFS | `src/flexsoc/backend/impl/impl.py` |
| esecuzione ORFS/tool resolution | `src/flexsoc/backend/impl/impl.py` |
| DRC/LVS/antenna/IR finali | `src/flexsoc/backend/signoff/__init__.py` |
| lifecycle metrics/check | `src/flexsoc/backend/core/reporting.py` |
| manifest artifact/tool | `src/flexsoc/backend/core/reporting.py` |

### Contenuto compatto

- **Parte I:** generazione CSR, scaffold RTL multi-clock, elaborazione ordinata.
- **Parte II:** lint, CDC/RDC, verifica funzionale SV+cocotb, coverage, formal.
- **Parte III:** sintesi Yosys/ABC ed equivalence logica EQY.
- **Parte IV:** STA/SDF/power pre-implementation e gate verification sul mapped netlist.
- **Parte V:** ORFS/OpenROAD: floorplan, PDN, placement, CTS, routing, finish/extraction.
- **Parte VI:** STA/SDF/GLS/power/fusion routed.
- **Parte VII:** route DRC, antenna, GDS DRC, LVS, IR/PDN.
- **Parte VIII–IX:** metrics/manifest/check e flow eseguibile completo corrente.
- **Parte X–XI:** roadmap DFT e SRAM/hard macro.
- **Parte XII–XIII:** temi full-chip e ordine di implementazione consigliato.

### Modello di stato del lifecycle

FlexSoC distingue intenzionalmente tre risultati:

- **PASS** — l'evidenza esiste e i check pertinenti sono puliti;
- **REVIEW** — il flow è stato eseguito, ma rimane una obligation ingegneristica o una capability mancante/non supportata da approvare manualmente;
- **FAIL** — esiste una violazione reale di verifica/sign-off o un errore tool.

Questa distinzione è particolarmente importante per CDC/RDC e physical sign-off. Un check non eseguibile non deve diventare un falso PASS.

---

## 2. Principi di progetto che tengono insieme il flow

### 2.1 Una source of truth per ogni informazione di progetto

FlexSoC cerca di evitare il classico problema dei flow ASIC in cui lo stesso dato viene copiato a mano in RTL, testbench, header software, constraint e script.

| Informazione | Source of truth | Collateral derivato |
| --- | --- | --- |
| indirizzi CSR, campi, reset, policy di accesso | HJSON | register RTL, docs, Python regmap, driver, CSR formal |
| domini clock/reset | `N_CLOCKS`, `CLOCK_DOMAINS`, `CLOCK_RELATIONSHIPS` | scaffold RTL, CDC/RDC, formal mode, SDC, clock di simulazione |
| scenario funzionale | scenario/model generato o authored | `config.regs`, `data_in.vec`, `data_out.vec` |
| mapping di sintesi | Liberty PDK + config sintesi | mapped netlist, checkpoint, report area/stat |
| timing intent | SDC canonico FlexSoC | OpenSTA sign-off e ORFS implementation |
| implementazione fisica | mapped netlist + SDC + piattaforma ORFS | final netlist, SDC, SPEF, ODB, GDS |
| qualification della run | report/artifact generati | `metrics.json`, manifest, `fx check` |

Regola ingegneristica:

```text
modifica l'intento
→ rigenera solo il collateral derivato
→ riesegui tutti i gate downstream le cui assunzioni sono cambiate
```

### 2.2 Codice generato e codice di proprietà del designer

I file generati possono essere sovrascritti. I file di proprietà del designer vengono preservati.

Collateral tipicamente generato:

- mappe HJSON starter;
- register RTL e documentazione registri;
- helper Python per la regmap;
- starter RTL top/core;
- filelist ordinate;
- scaffold dei testbench e scenari generati;
- script/config di sintesi, equivalence, OpenSTA e ORFS;
- metrics e manifest.

Collateral tipicamente designer-owned:

- comportamento RTL reale dopo l'adozione dello scaffold;
- protocolli CDC specifici dell'architettura;
- proprietà formal scritte per il design;
- comportamento del modello/reference model;
- catalogo di scenari significativo e criteri di accettazione;
- constraint di integrazione custom.

### 2.3 Single-clock e multi-clock sono lo stesso flow

Il clocking viene descritto strutturalmente. Esempio:

```text
single clock:
  N_CLOCKS=1
  core:clk_i:rst_ni:10ns:active-low

multi clock:
  cfg:cfg_clk_i:cfg_rst_ni:20ns:active-low
  rx:rx_clk_i:rx_rst_ni:16ns:active-low
  dsp:dsp_clk_i:dsp_rst_ni:30ns:active-low
  cfg ↔ rx  asynchronous
  cfg ↔ dsp asynchronous
  rx  ↔ dsp asynchronous
```

I tool downstream usano la stessa pipeline. Cambiano il contesto clock/reset generato e la policy di analisi.

---

## Parte I — Design entry e collateral generato

## 3. Generazione automatica dei control/status register

Il flow CSR è il primo grande confine di automazione. La register map visibile al software viene descritta una volta in HJSON e propagata in modo coerente nell'hardware e nella verifica.

### 3.1 HJSON come source of truth dei CSR

Una register map descrive almeno:

- nome dei registri e ordine/indirizzi;
- posizione dei field;
- policy di accesso software (`rw`, `ro`, write-one, ecc.);
- direzione di accesso hardware;
- valori di reset;
- eventuali field di stato controllati dall'hardware;
- metadati dell'interfaccia bus.

I register block generati usano una device interface TL-UL e registri a 32 bit.

Flow concettuale:

```text
HJSON
  │
  ├─ valida semantica registri
  ├─ genera register RTL sintetizzabile
  ├─ genera documentazione leggibile
  ├─ genera oggetti Python per registri/indirizzi
  ├─ genera collateral driver software
  └─ espone le primitive register ai check formal automatici
```

Target principali:

```bash
fx hjson --force
fx reg doc --force
fx regmap_py --force
fx driver --force
```

Internamente FlexSoC riusa il register tooling incluso sotto `src/util/regtool.py` / `reggen`, evitando di mantenere un secondo generatore CSR indipendente.

### 3.2 Esempio di register map multi-clock

Lo scaffold N-clock separa un dominio di configurazione da un dominio datapath.

**Mappa del dominio configuration** (`<top>_cfg.hjson`):

- `CTRL.ENABLE` — enable globale distribuito ai domini datapath;
- `CTRL.SOFT_RESET` — richiesta software di clear/reset del datapath;
- `CTRL.CLK_GATE_EN` — bit di policy per clock gating;
- `GAIN.VALUE` — coefficiente signed del datapath;
- `CFG_STATUS.BUSY` — status sincronizzato verso il dominio di configurazione;
- `CFG_STATUS.OVERFLOW` — indicazione overflow sincronizzata.

**Mappa del dominio DSP** (`<top>_dsp.hjson`):

- `DSP_CTRL.OP` — selezione operazione;
- `DSP_CTRL.SATURATE` — enable saturazione;
- `THRESHOLD.VALUE` — soglia di confronto;
- `RESULT.VALUE` — ultimo risultato;
- `DSP_STATUS.VALID`;
- `DSP_STATUS.ABOVE_THRESHOLD`;
- `DSP_STATUS.FIFO_EMPTY`;
- `DSP_STATUS.OVERFLOW`.

La separazione non è solo documentazione: rende esplicita l'ownership del clock già in fase iniziale e alimenta successivamente CDC/RDC e verification planning.

### 3.3 Register RTL generato

Il register RTL traduce transazioni bus in strutture tipizzate rivolte all'hardware. Il datapath dovrebbe consumare quelle strutture invece di decodificare manualmente indirizzi.

Pseudocodice naturale:

```text
su TL-UL write:
  decodifica indirizzo
  applica le regole di accesso software
  aggiorna solo i field legalmente scrivibili
  esponi q / qe / segnali hardware correlati

su TL-UL read:
  decodifica indirizzo
  seleziona il valore visibile al software
  inserisci i field di stato hardware quando richiesto
  restituisci la risposta di protocollo
```

Benefici principali:

1. l'address decode non viene riscritto a mano;
2. semantica software e documentazione derivano dalla stessa specifica;
3. la semantica delle primitive register può essere verificata formalmente indipendentemente dal datapath.

### 3.4 Python regmap e test interface

`design/regs.py` analizza lo stesso HJSON con `reggen` e genera helper Python per nomi di registri/field, mask, valori, read e write.

L'astrazione importante non è "Python controlla l'RTL", ma **i test non duplicano più indirizzi CSR e mask numeriche**.

Un test può esprimere logicamente:

```text
write CFG.CTRL.ENABLE = 1
write CFG.GAIN.VALUE  = 0x0100
poi read DSP.DSP_STATUS e confronta solo i bit VALID/OVERFLOW
```

e la regmap generata traduce l'intento nei valori numerici consumati dai file vettore del simulatore.

### 3.5 Collateral C/software

Il path di generazione driver deriva costanti register e helper software dalla stessa mappa. Il contratto hardware/software rimane quindi legato all'HJSON invece di richiedere header sincronizzati manualmente.

---

## 4. RTL scaffold: esempio multi-clock

FlexSoC può generare uno starter RTL. È uno scaffold architetturale, non un sostituto dell'RTL scritto dal designer.

Il caso multi-clock è utile perché mostra strutture che gli stage di analisi downstream sono progettati per riconoscere.

### 4.1 Struttura dei domini

```text
cfg domain          rx domain             dsp domain
-----------         ---------             ----------
CSR control ──────► synchronized enable
     │                                      ▲
     ├────────────────────────────────────► synchronized enable/reset/gate control
     │                                      │
     │             async FIFO ──────────────┤
     │            rx → dsp data             │
     │                                      ▼
     └◄──────────────────────── synchronized status
```

### 4.2 Controlli CDC single-bit

Segnali level single-bit come enable, soft-reset request e clock-gate enable usano primitive di sincronizzazione esplicite:

```systemverilog
prim_flop_2sync #(.Width(1)) u_enable_dsp_sync (
  .clk_i  (dsp_clk_i),
  .rst_ni (dsp_rst_ni),
  .d_i    (cfg_enable),
  .q_o    (enable_dsp)
);
```

La regola importante non è il nome esatto del modulo, ma la struttura:

- sorgente asincrona;
- primo flop di ricezione;
- secondo flop di stabilizzazione;
- nessuna logica combinatoria tra gli stage;
- fanout controllato del primo stage esposto alla metastabilità.

### 4.3 Policy per configurazioni multi-bit

Un bus multi-bit non può essere considerato sicuro usando N synchronizer indipendenti. Lo starter adotta una policy conservativa per `GAIN`: il dominio DSP aggiorna la copia solo quando il datapath è disabilitato.

```text
se il dominio DSP è in reset:
  gain_dsp = valore reset
altrimenti se il datapath è disabilitato:
  cattura il bus di configurazione
altrimenti:
  mantieni il valore coerente precedentemente catturato
```

È una policy scaffold, non una soluzione CDC universale. Un design produttivo può usare handshake, shadow register, toggle protocol, Gray code, async FIFO o altri meccanismi di coherency.

### 4.4 FIFO asincrona RX→DSP

L'esempio attraversa dati streaming tramite `prim_fifo_async`:

```text
lato RX clock:
  valid + ready
  impacchetta sample/coeff nel write data FIFO

lato DSP clock:
  read valid della FIFO
  consuma solo quando il pipeline può accettare
  ready separato nel read domain
```

La FIFO mostra un protocollo multi-bit coerente. CDC non deve classificare il payload come un insieme di bit indipendenti, ma riconoscere che l'obbligo di correttezza appartiene al protocollo pointer/storage della FIFO.

### 4.5 Intent di clock gating

Lo scaffold istanzia una primitive di clock gating in modo che l'intento sia visibile a lint e timing review. Il datapath generato mantiene intenzionalmente il calcolo sul clock DSP non gated fino a quando i constraint timing/GLS di un'implementazione completamente gated non vengono adottati consapevolmente.

```text
esiste l'intento architetturale
≠
si assume implicitamente che il clock gating sia sempre sicuro
```

---

## 5. Elaborazione RTL ordinata e filelist

Prima di ogni analisi FlexSoC crea filelist common/IP ordinate. È uno stage semplice ma fondamentale: tutti i tool downstream devono vedere gerarchia, package order e include path compatibili.

```text
raccogli package/primitive comuni
+ raccogli RTL IP
+ risolvi dipendenze SystemVerilog con Slang
+ emetti filelist ordinate
→ riusa lo stesso design raggiungibile in lint, sintesi, formal e analisi
```

In questo modo si riducono i casi in cui "tool A" e "tool B" analizzano universi RTL differenti.

---

## Parte II — Verifica pre-synthesis

## 6. RTL linting: Slang + Verilator

> **Nota terminologica:** il lint HDL corrente usa **Slang e Verilator**, non ESLint. ESLint è un linter JavaScript/TypeScript e non fa parte di questo flow RTL.

Ordine predefinito:

```text
Slang per primo
→ parsing SystemVerilog / type checking / static analysis
→ diagnostica gerarchica e di linguaggio

Verilator per secondo
→ frontend HDL indipendente
→ warning strutturali/stilistici aggiuntivi
```

Due frontend indipendenti danno diversity diagnostica: un costrutto accettato da uno può comunque evidenziare un problema di width, connessione o coding nell'altro.

### 6.1 Ruolo di Slang

Slang esegue compilazione/elaborazione SystemVerilog e static analysis in lint mode con top e define coerenti con sintesi.

Check particolarmente utili:

- correttezza sintattica e semantica del linguaggio;
- type checking;
- uso invalido o ambiguo di espressioni;
- truncation/extension di width;
- dichiarazioni inutilizzate;
- porte non connesse o connessioni vuote;
- latch inferiti;
- coerenza dell'elaborazione.

### 6.2 Ruolo di Verilator

Verilator viene invocato con base `--lint-only --sv -Wno-fatal`. I warning rimangono visibili ma non terminano automaticamente la run; FlexSoC può quindi raccoglierli e classificarli.

Diagnostiche tipiche:

- `LATCH` — assegnamento combinatorio incompleto che può inferire stato;
- `UNDRIVEN` — segnale/porta senza driver;
- `WIDTH`, `WIDTHEXPAND`, `WIDTHTRUNC` — mismatch/conversioni di ampiezza;
- `PINMISSING`, `PINCONNECTEMPTY`, `PINNOCONNECT` — problemi di connessione;
- `UNUSEDSIGNAL`, `UNUSEDPARAM` — dichiarazioni morte/non usate;
- diagnostiche più ampie di `-Wall` nello stage completo.

### 6.3 Focused lint suite

`fx lint_suite` esegue categorie mirate con entrambi i tool:

| Categoria | Domanda posta da FlexSoC |
| --- | --- |
| `all` | L'RTL raggiungibile è globalmente lint-clean? |
| `latch` | Il combinatorio ha inferito storage accidentalmente? |
| `undriven` | Esistono segnali osservati ma non pilotati? |
| `width` | Ci sono mismatch/truncation/extension di width? |
| `unconnected` | Mancano porte o sono vuote intenzionalmente? |
| `unused` | Esiste logica/configurazione presente ma inutilizzata? |

I log raw vengono preservati per distinguere warning legittimi di primitive/library da warning di proprietà dell'IP. Obiettivo: **zero warning inspiegati nell'RTL designer-owned**, non "zero warning a qualsiasi costo".

### 6.4 Cosa non dimostra il lint

Il lint non dimostra:

- sicurezza di un crossing asincrono;
- correttezza del protocollo;
- timing closure;
- correttezza dei risultati funzionali;
- preservazione del comportamento dopo sintesi.

Sono gate separati per scelta architetturale.

---

## 7. CDC/RDC: analisi strutturale clock/reset-domain

FlexSoC implementa un pass CDC/RDC strutturale e technology-neutral, invece di affidarsi a semplici pattern testuali.

### 7.1 Stage di estrazione

`setup_cdc_rdc` crea una vista JSON Yosys flattened usando il frontend Slang/Yosys:

```text
leggi RTL ordinato
→ hierarchy / lowering dei processi
→ ottimizzazione sufficiente all'analisi strutturale
→ flatten
→ write JSON
→ costruisci FlexSoC DesignIR
```

`DesignIR` cattura:

- porte top-level;
- elementi sequenziali;
- associazione clock;
- associazione reset e polarità;
- archi di dipendenza combinatori/sequenziali;
- domini source/destination.

È intenzionalmente **pre-technology**: l'obiettivo è ragionare sull'intento architetturale di clock/reset, non sui dettagli delle celle standard.

### 7.2 Synchronizer CDC scalari

Per un crossing scalare FlexSoC tenta di riconoscere una catena N-flop e ne verifica l'integrità.

Check principali:

- domini source/destination riconosciuti;
- numero sufficiente di stage sequenziali;
- assenza di logica combinatoria prima dello stage ricevente quando invaliderebbe la struttura attesa;
- assenza di combinatorio tra gli stage;
- disciplina di fanout del primo stage;
- semantica reset coerente tra gli stage;
- relazione tra clock dichiarata.

Una struttura sana viene classificata `nff_synchronizer` e può essere `SAFE` o `WARN` a seconda dell'evidenza e delle assunzioni di sampling residue.

Un crossing senza protezione riconosciuta produce evidenza `missing_synchronizer` / error-class.

### 7.3 CDC multi-bit volutamente più severo

FlexSoC **non** dichiara sicuro un bus solo perché ogni bit attraversa un synchronizer scalare.

Classificazioni possibili:

- `qualified_multibit` — dati associati a un controllo sincronizzato; richiede proof di stabilità/polarità/sampling;
- `multibit_nff_bus` — synchronizer bitwise presenti, coherency non dimostrata;
- `multibit_nff_integrity` — struttura dei synchronizer rotta;
- `unsynchronized_multibit` — nessun meccanismo di coherency riconosciuto;
- `async_fifo_candidate` — strutture cross-domain compatibili con FIFO asincrona e relative proof obligations;
- `closed_loop_handshake` — percorsi forward/back sincronizzati compatibili con request/ack;
- `synchronized_reconvergence` — segnali sincronizzati indipendentemente riconvergono creando potenziali hazard di sampling coerente.

Obligation tipiche:

```text
prova che i dati siano stabili prima del controllo sincronizzato
prova che restino stabili dopo il controllo sincronizzato
prova che il Gray pointer cambi con Hamming distance 1
prova la safety di full/empty pointer dell'async FIFO
prova liveness e ordering del request/ack
prova che i controlli riconvergenti siano coerenti a destinazione
```

L'idea chiave: un tool CDC deve dire **cosa resta da dimostrare**, non solo contare i crossing.

### 7.4 Check di Reset Domain Crossing

RDC cerca interazioni di stato tra reset domain differenti.

Classificazioni correnti:

- `rdc_via_data_synchronizer` — interazione reset protetta da synchronizer dati riconosciuto;
- `rdc_control_candidate` — un protocollo di controllo può bloccare effetti unsafe, ma richiede proof;
- `rdc_via_multibit_protocol` — interazione reset incorporata in un protocollo CDC multi-bit;
- `uncontrolled_rdc` — stato interagisce tra reset domain differenti senza protezione riconosciuta;
- `reset_synchronizer` — struttura di reset synchronization riconosciuta;
- `async_reset_release` — assertion/release asincrona da revisionare/provare;
- `reset_sequence_or_control_required` — architettura multi-reset che richiede sequencing/blocking esplicito.

### 7.5 Setup quality e glitch check

La stessa analisi verifica anche la qualità del modello clock/reset:

- elemento sequenziale senza clock domain dichiarato → error;
- polarità reset incompatibile con la dichiarazione → error;
- relazione clock non dichiarata → warning;
- più reset domain nello stesso clock domain → review;
- percorso combinatorio sul clock → error;
- percorso combinatorio sul reset → error.

### 7.6 PASS, REVIEW e obligations

Un conteggio strutturale pulito non implica automaticamente PASS. Per esempio, una release asincrona del reset apparentemente sana può mantenere lo stage in `REVIEW` finché l'architettura di reset non viene giustificata formalmente o manualmente.

Per questo `fx check` può mostrare:

```text
CDC / RDC   REVIEW
```

anche con zero errori CDC raw.

---

## 8. Verifica funzionale: un linguaggio di scenario, due backend testbench

FlexSoC usa gli stessi dati di scenario per SystemVerilog e cocotb. L'intento di verifica è quindi indipendente dal linguaggio con cui è scritto il testbench.

### 8.1 Modello mentale UVM-like

L'ambiente generato **non è UVM completo**, ma le responsabilità corrispondono bene ai concetti UVM:

| Responsabilità stile UVM | Equivalente FlexSoC |
| --- | --- |
| sequence / sequence item | scenario + righe `config.regs`, `data_in.vec`, `data_out.vec` |
| sequencer | scheduler cycle-indexed / ordering scenario |
| driver | task SV vector/TL-UL o driver cocotb vector/register |
| monitor | output monitor SV o cocotb `LatencyMonitor` |
| scoreboard | confronto expected da `data_out.vec` e CSR read |
| register model | alias/mask regmap Python + driver TL-UL |
| test | directory scenario come `smoke`, `corners`, `reconfig` |

Non implementa volutamente factory UVM, phase mechanism, class hierarchy, objections, TLM, ecc.

Il concetto utile è più semplice:

```text
intento scenario
→ serializza le operazioni in una piccola DSL deterministica
→ esegui lo stesso scenario con SV e cocotb
→ confronta output/stato register con gli stessi expected data
```

### 8.2 Catalogo scenari

Gli scenari starter condivisi includono:

- `smoke` — funzionalità base + trasporto CSR;
- `corners` — valori 0/1, boundary-style e check CSR;
- `random_seed_1`, `random_seed_2` — random deterministico;
- `reconfig` — cambio configurazione runtime;
- `auto_toggle` — alta attività/toggle per coverage/power;
- scenari specifici N-clock come MAC, absolute-difference ed energy operation.

Sono starter. La qualification reale di un IP deve sostituire i "vettori interessanti" con scenari guidati dai requisiti.

### 8.2.1 Relazione con model/reference layer

Il model layer prepara l'intento di verifica, non nasconde il comportamento atteso dentro al processo del simulatore.

```text
model + definizione scenario
→ calcola/configura transazioni e risultati attesi
→ serializza in config.regs / data_in.vec / data_out.vec
→ SV e cocotb consumano gli stessi file indipendentemente
```

Questo permette di riusare esattamente lo stesso contratto contro RTL, post-synthesis netlist e routed final netlist senza importare il modello high-level dentro al gate-level simulator.

### 8.3 `config.regs`: programmazione iniziale dei registri

Formato logico:

```text
<REGISTER> <DATA> [MASK] [WAIT_CYCLES] [NOTE]
```

Esempio:

```text
CFG.CTRL 0x00000001 0x00000001 1 enable_datapath
CFG.GAIN 0x00000100 0x0000ffff 1 program_gain
```

I nomi dei registri vengono risolti tramite la regmap generata, evitando indirizzi numerici duplicati nel test.

### 8.4 `data_in.vec`: stimulus di interfaccia e controllo runtime

Drive ordinario:

```text
<CYCLE> <SIGNAL> <VALUE> [<SIGNAL> <VALUE> ...]
```

Esempio:

```text
0 valid_i 0 data_i 0x00000000 coeff_i 0x00000000
4 valid_i 1 data_i 0x00000010 coeff_i 0x00000003
5 valid_i 0
```

Più coppie signal/value sulla stessa riga vengono applicate come batch nello stesso ciclo.

Comandi runtime:

```text
<CYCLE> @write <REGISTER_OR_ADDRESS> <DATA> [MASK]
<CYCLE> @cfg   <PATH_TO_CONFIG.REGS>
<CYCLE> @reset [DOMAIN_OR_RESET] <CYCLES>
```

Questa è una proprietà forte del flow: **lo stesso scenario può combinare stimulus sul datapath e modifiche software-visible della regmap**.

```text
0  @write CFG.CTRL 0x1 0x1
4  rx_valid_i 1 rx_sample_i 0x0123 rx_coeff_i 0x0040
12 @write DSP.DSP_CTRL 0x2 0x3
20 @reset dsp 2
```

### 8.5 `data_out.vec`: check output e register read

Check a ciclo fisso:

```text
<CYCLE> <SIGNAL> <EXPECTED> [<SIGNAL> <EXPECTED> ...]
```

Read/check register:

```text
<CYCLE> @read <REGISTER_OR_ADDRESS> <EXPECTED> [MASK]
```

Check valid-guarded:

```text
<VALID_SIGNAL> <SIGNAL> <EXPECTED> [<SIGNAL> <EXPECTED> ...]
```

La forma guarded è utile quando il timing di output è event-oriented invece che vincolato a un ciclo assoluto: ogni assertion del valid consuma la successiva riga expected.

### 8.6 Backend SystemVerilog

Il testbench SV generato svolge responsabilità equivalenti a:

```text
inizializzazione
→ clock/reset
→ helper accesso register TL-UL
→ applica config.regs
→ parse e drive data_in.vec
→ monitora output fixed-cycle / valid-guarded
→ emette transazioni @read
→ confronta gli expected
→ conta errori / termina
```

Driver e monitor producono transcript leggibili: segnale pilotato, accesso TL-UL, confronto PASS/FAIL. Lo stesso test serve quindi sia alla regressione sia al debug.

### 8.7 Backend cocotb

L'ambiente cocotb consuma gli stessi file e ha le stesse responsabilità concettuali:

- register driver / proxy TL-UL;
- vector driver;
- callback runtime per reset e configurazione;
- `LatencyMonitor` per gli output;
- callback register-reader per gli expected `@read`;
- waveform tramite il simulatore selezionato.

`LatencyMonitor` carica righe expected a ciclo fisso e guarded-valid, quindi esegue confronti di signal e register con mask.

Avere implementazioni SV e Python non è duplicazione fine a se stessa: sono due execution backend indipendenti dello stesso scenario contract.

### 8.8 Coverage

La simulazione funzionale è accompagnata da coverage HDL. FlexSoC consolida coverage per scope e tipo:

- line;
- toggle;
- expression;
- branch;
- FSM/user coverage se disponibile.

Il report separa RTL designer-owned da register/common/other infrastructure, così una grande libreria generata non nasconde coverage debole nell'IP reale.

Coverage è evidenza di esercizio della struttura, non prova di correttezza. Formal e scenari requirement-driven restano gate distinti.

---

## 9. Formal verification

FlexSoC ha due suite complementari:

```text
CSR formal             design/property formal
----------             ----------------------
derivata automaticamente starter + assert/cover designer-owned
dal register RTL        sull'architettura reale dell'IP
```

Ogni suite esegue bounded check, prove e cover.

### 9.1 Engine e struttura predefinita

Configurazione attuale approssimativa:

```text
BMC:
  engine  = smtbmc bitwuzla
  depth   = 30
  append  = 5

PROVE:
  engine  = abc pdr
  depth   = 20 framework context

COVER:
  engine  = btor btormc
```

La scelta del solver appartiene alla configurazione SymbiYosys generata. Nei design multi-clock gli SBY abilitano `multiclock on`.

### 9.2 Perché BMC viene prima della proof

Sequenza pratica:

```text
BMC
→ trova bug shallow rapidamente e genera counterexample corti
→ se pulito, esegui motore unbounded/inductive
→ esegui separatamente cover per mostrare raggiungibilità di stati utili
```

Una proof che passa ma rende irraggiungibile ogni comportamento interessante non è sufficiente; per questo cover è uno stage di prima classe.

### 9.3 CSR formal automatico

La suite CSR bind-a checker direttamente alle primitive register.

Primitive incluse:

- `prim_subreg_arb`;
- `prim_subreg`;
- `prim_subreg_ext`.

Concetti verificati:

- arbitration di software write enable/data;
- comportamento corretto di `q`/effective value;
- reset value;
- coerenza dell'update rispetto al ciclo precedente;
- handshake read/write per registri external;
- semantiche SW come RW/RO/WO e write-one/clear/set/read-clear rappresentate dai parametri;
- semantica di primitive MuBi dove applicabile.

La suite cover richiede inoltre al solver di raggiungere write su primitive software-writable, così si controlla anche la reachability del path register.

### 9.4 Starter di proprietà design-level

Per scaffold single-clock, gli assertion starter legano output architetturali allo stato del pipeline e verificano output puliti dopo reset.

Per lo scaffold multi-clock, gli assertion generati verificano contratti strutturali come:

```text
rx_ready == enable_rx AND fifo_write_ready

fifo_read_ready ==
  enable_dsp AND fifo_read_valid AND pipeline_can_accept

dsp_clock_active ==
  enable_dsp AND (gate_disabled OR pending_work)

se reset DSP o software reset sono stati assertiti:
  output valid/result/status tornano a valori reset-safe
```

Cover tipici:

- configuration enable raggiunto;
- handshake RX valid/ready;
- dati async FIFO diventano leggibili;
- DSP output valid;
- output valid e downstream ready simultaneamente.

### 9.5 Ownership del designer

Lo scaffold delle proprietà viene creato solo se assente. Dopo la creazione è designer-owned e non viene sovrascritto silenziosamente.

È intenzionale: le proprietà significative devono evolvere con l'architettura, non essere rigenerate per sempre da un template generico.

---

## Parte III — Sintesi ed equivalence logica

## 10. Timing intent canonico: perché l'SDC non entra nella sintesi Yosys

FlexSoC separa intenzionalmente **technology mapping** e **timing constraint/sign-off**. Il timing intent nasce una sola volta dal modello canonico dei clock, ma viene tradotto in due forme diverse perché Yosys/ABC e OpenSTA/OpenROAD svolgono lavori differenti.

```text
ClockConfig FlexSoC
  ├─ hint di sintesi
  │    ├─ Liberty target
  │    ├─ clock period più veloce, dove serve come target ABC
  │    └─ abc.constr: driving cell + output load
  │
  └─ SDC canonico
       ├─ OpenSTA pre-implementation
       ├─ ORFS/OpenROAD implementation
       └─ 6_final.sdc → OpenSTA post-implementation
```

Il punto importante è che **l'SDC non viene letto dagli script ASIC Yosys generati oggi da FlexSoC**. Questa non è una dimenticanza: è una scelta architetturale del flow corrente.

### 10.1 Source of truth: il modello clock di FlexSoC

La configurazione canonica viene costruita da `clock_config()` a partire da:

- `N_CLOCKS`;
- `CLOCK_DOMAINS`;
- `CLOCK_RELATIONSHIPS`;
- `CLK_PERIOD` per il caso single-clock/default;
- per ogni dominio: nome, segnale clock, reset, periodo e polarità del reset.

Esempio concettuale multi-clock:

```text
CLOCK_DOMAINS =
  cfg:clk_cfg_i:rst_cfg_ni:10:low,
  rx:clk_rx_i:rst_rx_ni:8:low,
  dsp:clk_dsp_i:rst_dsp_ni:5:low

CLOCK_RELATIONSHIPS =
  async:cfg:rx,
  async:cfg:dsp,
  async:rx:dsp
```

Lo stesso oggetto `ClockConfig` alimenta CDC/RDC, generazione SDC e contesto di sintesi. I reset appartengono al modello canonico perché servono a CDC/RDC e agli altri backend; **l'SDC generato oggi non inventa automaticamente reset exceptions o recovery/removal policies** che non siano state esplicitamente modellate.

### 10.2 Cosa riceve davvero la sintesi

`syn/syn.py` non emette `read_sdc` dentro `synth.ys` o `synth_sv.ys`. La sintesi ASIC riceve invece un sottoinsieme volutamente semplice del timing intent:

```text
RTL/SystemVerilog
+ Liberty
+ optimization strategy
+ fastest_period_ns
+ PDK driving-cell/load assumptions
        ↓
Yosys + ABC technology mapping
```

In particolare:

- con strategia `delay`, FlexSoC passa ad ABC `-D <fastest_period_ps>` e `-constr abc.constr`;
- con strategia `area`, usa la recipe `area.abc` più `abc.constr`, senza trasformare l'SDC in un timing graph di sintesi;
- con strategia `none`, usa il mapping ABC diretto con `-D <fastest_period_ps>`;
- `abc.constr` contiene solo `set_driving_cell` e `set_load`.

Il parametro `sdcdir` esiste ancora nel contratto Python di `SynthesisConfig`, ma **nel renderer ASIC corrente non viene consumato e non implica che Yosys stia leggendo un SDC**.

### 10.3 Perché questa separazione è voluta

Yosys/ABC in FlexSoC viene usato per **ottimizzare e mappare la logica**, non come timing sign-off engine. Per questo il mapper riceve hint sufficienti a prendere decisioni sensate sulle celle, mentre la semantica completa del timing viene lasciata a OpenSTA/OpenROAD.

La separazione evita quattro problemi:

- **duplicazione della semantica timing** — generated clocks, gruppi asincroni, I/O delays ed eventuali eccezioni devono avere una sola interpretazione autorevole;
- **falsa precisione pre-layout** — prima di placement, CTS e routing non esistono ancora clock insertion delay e parassitiche routed;
- **drift tra tool** — una traduzione parziale dell'SDC dentro la sintesi potrebbe divergere da ciò che OpenSTA e OpenROAD usano davvero;
- **accoppiamento inutile** — la sintesi deve produrre un buon mapped netlist, mentre timing repair fisico, CTS e routing timing-driven appartengono all'implementation.

Questa è una scelta del **flow FlexSoC attuale**, non un'affermazione che Yosys in assoluto non possa essere integrato con flow che usano timing constraint più ricchi.

### 10.4 `abc.constr` non è un SDC

È importante non confondere i due file. Il formato `-constr` del pass ABC di Yosys è volutamente minimale:

```text
set_driving_cell <cell_name>
set_load <load_ff>
```

Serve a dire al mapper, in modo approssimato:

- quanto è forte il driver esterno dei primary input;
- quale carico vede ciascun primary output.

Non contiene:

- `create_clock`;
- generated clocks;
- asynchronous clock groups;
- input/output delay associati ai clock;
- false path o multicycle path;
- propagated clock latency;
- parassitiche.

Questi concetti appartengono all'SDC/STA e, più avanti, al modello fisico.

### 10.5 Come FlexSoC autogenera l'SDC canonico

Il proprietario dell'SDC canonico è `signoff/sta.py`, esposto tramite `signoff.pre.setup_sdc()`. Il flusso è concettualmente:

```text
clock_config(values)
    ↓
render_clock_config_sdc(top, cfg, SDC_IO_DELAY_PCT)
    ↓
write_sdc(signoff/<pdk>/<top>.sdc)
```

Per un **single-clock** il file contiene almeno:

```tcl
current_design test
create_clock -name core -period 10 [get_ports clk_i]

set non_clock_inputs [all_inputs -no_clocks]
set_input_delay  [expr 10 * 0.2] -clock core $non_clock_inputs
set_output_delay [expr 10 * 0.2] -clock core [all_outputs]
```

`0.2` deriva dal default `SDC_IO_DELAY_PCT=0.2`: è un'assunzione di integrazione modificabile, non una proprietà fisica universale del chip.

Per un **multi-clock** FlexSoC genera invece, in base alle relationship dichiarate:

- `create_clock` per i primary clock;
- `create_generated_clock` per relationship `generated`;
- `set_clock_groups -asynchronous` per relationship `async`;
- nessuna falsa inferenza di I/O delay multi-clock: l'associazione porta→clock è integration-specific e deve essere dichiarata esplicitamente quando il flow verrà esteso in quella direzione.

Una relationship `sync` viene oggi registrata senza introdurre automaticamente un'eccezione timing aggiuntiva.

### 10.6 Dove entra l'SDC nel flow reale

Una volta generato, l'SDC diventa l'autorità temporale pre-layout:

```text
mapped netlist FlexSoC
        +
canonical <top>.sdc
        ↓
OpenSTA pre-implementation
        ↓
impl/impl.py
        ↓
ORFS config.mk
  SYNTH_NETLIST_FILES := <top>_synth.v
  SDC_FILE             := <top>.sdc
        ↓
OpenROAD physical implementation
```

Quindi ORFS **non risintetizza** il design: riceve il mapped netlist di FlexSoC e l'SDC canonico separatamente. Da quel momento OpenROAD può usare il timing intent durante placement timing-driven, timing repair, CTS e routing.

Al termine dell'implementation ORFS produce anche:

```text
6_final.v
6_final.sdc
6_final.spef
```

Il sign-off post-implementation non torna al vecchio modello pre-layout: FlexSoC consuma **`6_final.sdc` + final netlist + SPEF**, abilita i propagated clocks e misura il design fisico realmente routed.

### 10.7 Il modello mentale corretto

La relazione completa è quindi:

```text
                  ┌─→ Yosys/ABC
                  │    coarse mapping hints
ClockConfig ──────┤    Liberty + period + driver/load
                  │
                  └─→ canonical SDC
                       ↓
                  OpenSTA pre-impl
                       ↓
                  ORFS/OpenROAD
                       ↓
                  6_final.sdc + SPEF
                       ↓
                  OpenSTA post-impl
```

In altre parole: **il clock intent è condiviso; il file SDC no, perché non tutti gli stage hanno bisogno della stessa rappresentazione**. La sintesi usa hint sufficienti al mapping; STA e implementation usano il contratto temporale completo.

---

## 11. Sintesi con Yosys e ABC

FlexSoC possiede la sintesi. ORFS riceve il netlist già mapped da FlexSoC invece di lanciare una seconda sintesi indipendente.

### 11.1 Input

La sintesi ASIC consuma:

- filelist RTL ordinate;
- top selezionato;
- Liberty target;
- periodo del clock più veloce come hint di ottimizzazione ABC dove applicabile, **non l'SDC**;
- tie cell e minimum-buffer del PDK quando disponibili;
- modalità `area`, `delay` o `none`.

### 11.2 File generati

`syn/syn.py` genera:

```text
synth.ys / synth_sv.ys   programma Yosys
abc.constr               assunzioni timing I/O per ABC
area.abc                 recipe ABC area-oriented
delay.abc                recipe ABC delay-oriented
```

> Il file si chiama **`abc.constr`**, non `.const`. Yosys lo passa ad ABC tramite `-constr`.

### 11.3 Significato di `abc.constr`

Il file constraint ABC è volutamente piccolo e **non va confuso con l'SDC canonico**:

```text
set_driving_cell <PDK_INPUT_DRIVER_CELL>
set_load 10
```

Concettualmente:

- `set_driving_cell` modella la cella che guida i primary input;
- `set_load` modella il carico di output in femtofarad per le decisioni timing di ABC.

Il driver cell arriva dal profilo PDK attivo: FlexSoC non inietta una cella SKY130 dentro a un altro PDK.

### 11.4 Struttura dello script `.ys`

Lo script Yosys è una sequenza di trasformazioni e validation boundary:

```text
1. Read Liberty target come library cells
2. Read/elaborate SystemVerilog con frontend Slang/Yosys
3. Sintesi generic logic senza final ABC mapping
4. Salva checkpoint RTLIL generico
5. Prepara mapping FF con dfflibmap
6. Salva checkpoint FF-prepared
7. Mappa combinatorio tramite ABC
8. Salva checkpoint post-ABC
9. Finalizza FF verso celle library
10. check -assert
11. split/clean net e inserimento tie/min-buffer se necessario
12. check -assert -mapped
13. statistiche
14. final mapped Verilog + JSON
```

I checkpoint RTLIL permettono di localizzare un problema al confine generic, FF mapping, ABC o cleanup.

### 11.5 Mapping FF e combinatorio

```text
dfflibmap
→ associa celle sequenziali astratte alle possibilità della target library

ABC
→ ottimizza/mappa il combinatorio in celle Liberty

dfflibmap -map-only
→ finalizza la technology mapping sequenziale preparata
```

Sequential e combinational mapping hanno vincoli differenti ed è più semplice ragionarci separatamente.

### 11.6 Recipe ABC orientata all'area

La recipe `area.abc` segue una sequenza portabile di restructuring AIG e area mapping:

```text
strash
→ dch
→ balance
→ rewrite / refactor / rewrite -z
→ balance / dch
→ map -a
→ topology cleanup
→ downsize
→ static timing estimate
→ stats
```

Intent:

- semplificare e ristrutturare la logica;
- privilegiare area-aware mapping;
- recuperare area con downsizing;
- mantenere una stima timing ABC.

### 11.7 Recipe ABC orientata al delay

```text
strash
→ balance
→ rewrite / refactor
→ dch
→ map con delay target
→ topology cleanup
→ upsize
→ buffer
→ static timing estimate
→ stats
```

Yosys passa `-D <period_ps>` nel mapping delay-oriented.

Intent:

- bilanciare la profondità logica;
- mappare sotto timing pressure;
- usare upsizing/buffering sui path critici;
- accettare un possibile incremento di area.

### 11.8 Modalità `none`

`none` usa un direct Liberty mapping più semplice con target basato sul clock period invece delle recipe custom area/delay.

### 11.9 Cosa non fa ancora FlexSoC: portfolio di strategie

FlexSoC espone oggi `area`, `delay` e `none`. Non esegue automaticamente un grande portfolio di script.

LibreLane è un riferimento utile per una futura exploration layer: offre più strategie `AREA 0..3` e `DELAY 0..4`, perché non esiste una recipe ABC universalmente ottima.

Possibile estensione futura:

```text
per ogni strategy selezionata:
  sintetizza
  esegui quick STA / estrazione area
  registra area, cell count, proxy WNS/TNS

rank dei candidati Pareto
→ seleziona una strategy esplicita
→ riesegui il normale downstream flow qualificato
```

È **roadmap**, non feature corrente.

### 11.10 Output finali di sintesi

Artifact principali:

- `<top>_synth.v` — mapped implementation netlist;
- `<top>_synth.json` — design mapped machine-readable;
- checkpoint RTLIL;
- log sintesi;
- estratti warning/error;
- statistiche Liberty-based di celle/area.

Il mapped netlist è l'esatto input logico consegnato a EQY e physical implementation.

---

## 12. Equivalence RTL ↔ synthesis con EQY

La sintesi può cambiare radicalmente la struttura. EQY risponde a una domanda diversa dalla simulazione:

> Per tutti gli input/stati ammessi dal modello di equivalenza, il netlist sintetizzato mapped implementa lo stesso comportamento osservabile esternamente dell'RTL?

### 12.1 Lati gold e gate

```text
gold:
  RTL authored
  letto tramite frontend formal Slang/Yosys

gate:
  mapped synthesis netlist
  + semantica celle target da Liberty o functional model
```

Gli assertion vengono ignorati mentre si legge il design per EQY: l'obiettivo è confrontare il comportamento del design, non riprovare la property suite.

### 12.2 Semantica delle technology cell

Il gate netlist contiene celle standard reali. EQY deve conoscere la loro funzione booleana.

FlexSoC sceglie per tecnologia:

- functional Verilog delle standard cell quando compatibile con il frontend formal Yosys;
- semantica Liberty come fallback;
- handling SKY130 dedicato per clock-gating cell quando necessario;
- per IHP preferenza Liberty quando i modelli Verilog aggregati contengono `specify` poco adatti a EQY/Yosys.

### 12.3 Normalizzazione output protocol-aware

Un confronto raw dei bus può complicarsi inutilmente quando alcuni bit sono don't-care fuori dalle condizioni di validità del protocollo.

Per TL-UL FlexSoC può creare witness canonici come:

```text
handshake
control/status witness
data witness
metadata witness
```

e normalizzare field don't-care quando valid/error li rende semanticamente irrilevanti.

Non significa indebolire l'equivalenza: significa confrontare il **contratto di protocollo**, non bit privi di significato.

### 12.4 Normalizzazione reset

Il flow può normalizzare reset per pochi cicli configurati prima del confronto, così da allineare rappresentazioni di storage che la technology mapping può aver trasformato.

### 12.5 Strategia single-clock vs multi-clock

Single-clock: portfolio con SAT, PDR e strategie SMT-oriented.

Multi-clock: SAT disabilitato; si usano PDR/SMT più adatti al modello multi-clock.

`async2sync` viene applicato solo nel single-clock; FlexSoC non finge che un design genuinamente asincrono multi-clock sia un unico dominio sincrono.

### 12.6 Cosa viene dimostrato

EQY qualifica:

```text
RTL
↕ behavioral equivalence
mapped post-synthesis netlist
```

Non dimostra:

- equivalenza del layout routed;
- timing analogico;
- DRC/LVS;
- completezza dell'SDC;
- timing closure.

Sono gate distinti.

## Parte IV — Sign-off pre-implementation

## 13. Setup OpenSTA condiviso tra gli stage di sign-off

FlexSoC usa un unico framework Python per generare gli script OpenSTA sia pre-implementation sia post-implementation. Cambia il modello timing, non la struttura fondamentale dell'analisi.

Inizializzazione concettuale:

```text
leggi le Liberty del corner
+ leggi le Liberty delle macro se presenti
→ leggi mapped/final netlist
→ link design
→ leggi SDC canonico
→ check setup

se post-route:
  read SPEF
  propagate clocks
altrimenti:
  nessun SPEF
  clock network ideale
```

Distinzione centrale:

| Stage | Clock network | Modello interconnect |
| --- | --- | --- |
| post-synthesis | ideal | none |
| post-implementation | propagated | SPEF |

---

## 14. STA pre-implementation

La STA pre-implementation risponde a:

> Il design logico mapped rispetta i timing constraint **prima** che esistano parasitiche routed e clock tree fisica?

Per ogni corner e modalità setup/hold configurata FlexSoC registra:

- WNS/TNS;
- setup/hold o min/max timing checks;
- max slew;
- max capacitance;
- max fanout;
- recovery/removal;
- minimum pulse width / minimum period;
- path unconstrained espliciti;
- path in violazione;
- path met ma near-critical.

Il report dichiara esplicitamente:

```text
clock_network=ideal
interconnect=none
```

Un path unconstrained non diventa PASS solo perché non ha slack negativo: viene riportato separatamente per review.

---

## 15. SDF pre-implementation

FlexSoC chiede a OpenSTA di serializzare il timing model linkato con:

```text
write_sdf
  include valore typ
  header deterministico senza timestamp/version noise
```

### 15.1 Completezza min / typ / max

OpenSTA 3.1 può lasciare vuoto il valore `typ` nelle triple PVT dell'header anche quando i delay timing includono il typ. Il Tcl generato normalizza solo quei field dell'header, così l'SDF è accettato in modo consistente dai timing simulator.

### 15.2 Perché l'SDF post-synthesis non contiene `INTERCONNECT`

OpenSTA scrive inizialmente un blocco SDF `CELL` contenente `INTERCONNECT` anche quando non esiste un modello SPEF routed.

Il contratto pre-implementation di FlexSoC è invece esplicito:

```text
clock = ideal
physical interconnect = none
```

Per questo il Tcl post-synthesis rimuove quel blocco iniziale interconnect-only mantenendo `IOPATH` e timing-check delle celle.

Questo evita due problemi:

- non si spaccia un wire delay pre-layout per un vero delay fisico routed;
- si evitano problemi simulator-specific su inter-module path che non hanno significato fisico in questa fase.

---

## 16. Power estimate pre-implementation

Il primo stage power è vectorless, basato su assunzioni di activity.

```text
link del mapped design per corner
→ applica switching activity globale/input
→ calcolo power OpenSTA
→ report internal + switching + leakage + total power
```

È una stima PDK-aware precoce, utile prima che esistano PnR e waveform workload-derived.

Serve per:

- confronto fra corner;
- confronto fra strategy di sintesi;
- sanity check di ordine di grandezza.

Non è ancora il risultato power finale legato a un workload reale.

---

## 17. Gate-level verification post-synthesis nel contesto del sign-off

Anche se il blocco pre-implementation si può riassumere con STA + SDF + power estimate, FlexSoC qualifica dinamicamente il mapped netlist **prima** del PnR.

Gli stessi test funzionali vengono ripetuti in modalità:

```text
zero
unit
ff / min SDF
tt / typ SDF
ss / max SDF
```

Per le modalità SDF post-synthesis:

- vengono annotati i cell/path delay;
- il physical interconnect rimane intenzionalmente `none`;
- `-ginterconnect` non serve perché il blocco SDF `INTERCONNECT` viene rimosso.

Questo stage esiste prima dell'implementation per evitare di scoprire un problema dinamico sul netlist tecnologico solo dopo un PnR costoso.

---

## Parte V — Implementazione fisica con ORFS/OpenROAD

## 18. Handoff FlexSoC → ORFS

FlexSoC possiede sintesi e timing intent. ORFS viene usato come **controller dell'implementazione fisica**, non come seconda pipeline logica indipendente.

Il `config.mk` generato punta quindi a:

```text
SYNTH_NETLIST_FILES = FlexSoC <top>_synth.v
SDC_FILE             = FlexSoC canonical SDC
PLATFORM             = selected ORFS technology platform
```

Default fisici correnti, tra gli altri:

- core utilization circa 50%;
- placement density circa 0.58;
- timing-driven global placement abilitato;
- routability-driven global placement abilitato;
- limite detailed routing 64 iterazioni;
- nessun margine extra setup/hold;
- metriche dettagliate e report clock skew attivi.

**Dettaglio corrente importante:** la configurazione generata imposta `USE_FILL=0`. ORFS/OpenROAD supporta metal fill, ma FlexSoC non lo rende ancora obbligatorio. Una futura tapeout policy dovrà decidere quando inserire fill e se richiedere re-extraction/sign-off post-fill.

### 18.1 Determinismo dei path dei tool

`impl/impl.py` risolve `openroad`, `yosys` e `klayout` dal `PATH` FlexSoC attivo e passa quei path a ORFS.

In questo modo una variabile host stale come:

```text
OPENROAD_EXE=/some/old/path
```

non può sovrascrivere silenziosamente la toolchain selezionata dall'ambiente o dal container corrente.

---

## 19. Stage di implementazione OpenROAD

ORFS presenta l'implementation in sei macro-stage:

```text
1 import
2 floorplan
3 placement
4 CTS
5 routing
6 finish
```

FlexSoC conserva i checkpoint e qualifica gli artifact finali.

### 19.1 Import e setup database

OpenROAD carica dati di tecnologia/library della piattaforma, mapped netlist e constraint timing nelle rappresentazioni interne OpenDB/OpenSTA.

Contratto:

```text
logical design = FlexSoC mapped netlist
constraints    = FlexSoC canonical SDC
technology     = ORFS platform
```

Qui non deve partire una seconda sintesi indipendente che cambi l'implementazione logica.

### 19.2 Floorplan

Il floorplan definisce la geometria entro cui dovranno entrare tutte le decisioni fisiche successive.

Responsabilità tipiche:

- dimensioni die/core da area/utilization policy;
- standard-cell rows e placement sites;
- routing layer context;
- policy di placement pin I/O del core;
- tap/welltie/endcap secondo la piattaforma;
- region macro quando esistono hard macro;
- prime assunzioni su congestion e fattibilità fisica.

Pseudocodice naturale:

```text
stima area standard cell necessaria
→ scegli dimensioni core da utilization/aspect ratio
→ crea rows/sites
→ riserva blockage / macro region / boundary
→ posiziona o vincola top-level pin
→ rendi il floorplan legale per PDN e placement
```

### 19.3 PDN generation: power prima del placement standard-cell

La power distribution non viene aggiunta alla fine come decorazione. La PDN nasce dalla policy di piattaforma prima del placement, così il resto del flow lavora in un floorplan che contiene già l'infrastruttura di alimentazione reale.

Il PDN generator di OpenROAD applica policy come:

- net power/ground;
- layer per rail/strap;
- width degli strap;
- pitch/spacing;
- via fra grid layer;
- std-cell grid e macro grid quando presenti.

```text
platform power policy
→ std-cell rails
→ vertical/horizontal straps
→ via connections
→ power grid che occupa risorse reali di routing
→ celle e segnali vengono poi piazzati/routati attorno a questa realtà
```

È fondamentale per avere congestion e IR analysis sensate.

### 19.4 Global placement

Il global placement OpenROAD è basato su un approccio analitico RePlAce-style con ottimizzazione non lineare.

A livello intuitivo:

- la wirelength tende a tirare vicine celle connesse;
- forze di density impediscono di collassare tutte le celle nella stessa zona;
- un'ottimizzazione Nesterov-like cerca iterativamente un placement a costo più basso.

FlexSoC abilita sia timing-driven sia routability-driven placement.

**Timing-driven:**

```text
stima timing
→ trova net con slack basso
→ aumenta il loro peso nel placement
→ favorisce geometrie più corte/favorevoli
```

**Routability-driven:**

```text
stima congestion (RUDY / routing demand)
→ trova bin congestionati
→ aumenta localmente effective cell area
→ allontana le celle dagli hot spot di routing
```

Il risultato non è ancora un placement legale site-by-site, ma una soluzione globalmente ottimizzata.

### 19.5 Detailed placement / legalization

Il detailed placement trasforma la soluzione globale in layout standard-cell legale:

- allinea celle a row/site;
- rimuove overlap;
- rispetta padding/blockage;
- minimizza displacement mantenendo la legalità.

È il confine fra "buona soluzione geometrica continua" e "celle con coordinate fisiche legali".

### 19.6 Timing repair e resizing

Il resizer/timing repair di OpenROAD modifica l'implementazione attorno alle stime fisiche con operazioni come buffering e gate sizing.

Problemi tipici corretti:

- transition eccessivo;
- capacitance/fanout eccessivi;
- pressione setup/hold;
- net lunghe o ad alto carico.

È physical optimization: cambiano celle e net fisiche, ma il comportamento logico deve rimanere equivalente.

### 19.7 Clock Tree Synthesis (CTS)

Prima della CTS il clock è concettualmente ideal. La CTS inserisce una distribuzione fisica reale del clock.

OpenROAD usa TritonCTS 2.0 con costruzione tree e inserimento buffer tramite characterization on-the-fly.

```text
raccogli clock sink
→ cluster/partition della geometria sink
→ scegli stage di clock buffer
→ costruisci distribution tree
→ bilancia insertion delay/skew
→ riconnetti sink con real clock buffer/net
→ ripara timing attorno alla nuova clock network
```

Dopo CTS, clock latency e skew sono quantità fisiche invece di assunzioni ideali.

### 19.8 Global routing

Il global routing decide **dove** le connessioni dovrebbero passare grossolanamente nella routing grid, senza ancora disegnare ogni wire/via finale.

Il motore OpenROAD è basato su FastRoute.

Responsabilità:

- stima domanda/capacità routing;
- crea route guide;
- identifica congestion;
- interagisce con timing/repair;
- rileva/ripara antenna risk se configurato, incluse diode repair dove supportate.

### 19.9 Detailed routing

Il detailed routing usa TritonRoute.

Blocchi principali:

```text
pin access analysis
→ track assignment
→ initial detailed route
→ DRC-aware search and repair
→ iterative cleanup
```

Qui vengono prodotte geometrie wire/via realmente legali rispetto alle design rule della tecnologia rappresentate dalla piattaforma.

La config FlexSoC permette fino a 64 iterazioni di detailed routing, lasciando spazio alla ricerca/riparazione iterativa.

### 19.10 Antenna handling

Conduttori lunghi parzialmente fabbricati possono accumulare carica durante la produzione e danneggiare il gate oxide. Il flow antenna verifica ratio/rule e può riparare violazioni, ad esempio aggiungendo diodi quando la piattaforma li supporta.

FlexSoC usa poi il report antenna ORFS come evidenza di physical sign-off: non assume che "routing completato" significhi automaticamente antenna-clean.

### 19.11 Finish ed extraction

Lo stage finish produce gli artifact usati dal sign-off downstream:

```text
6_final.v      final implementation netlist
6_final.sdc    final implementation constraints
6_final.spef   extracted routed parasitics
6_final.odb    OpenDB database
6_final.gds    final layout stream
```

OpenRCX esegue la routed RC extraction da cui nasce lo SPEF.

Questi artifact definiscono il modello post-implementation. FlexSoC non rigenera uno SPEF indipendente: `6_final.spef` è l'artifact parasitico routed canonico.

---

## Parte VI — Sign-off post-implementation

## 20. Routed STA: final netlist + final SDC + SPEF

La STA post-implementation passa dal modello ideal/pre-layout al modello fisico/routed:

```text
read final Liberty corner
→ read 6_final.v
→ link design
→ read 6_final.sdc
→ read 6_final.spef
→ set clocks propagated
→ analyze setup/hold/electrical constraints
```

Il report dichiara:

```text
clock_network=propagated
interconnect=spef
```

Sezioni routed aggiuntive:

- coverage dell'annotazione SPEF / net non annotate;
- clock latency;
- setup/hold clock skew;
- worst routed paths anche se timing-met;
- path report espanso con slew, capacitance, net e fanout.

È la differenza quantitativa principale rispetto alla STA post-synthesis: cell delay, wire delay routed e comportamento fisico della clock tree vengono analizzati insieme.

---

## 21. Routed SDF

L'SDF post-route viene generato dallo stesso timing model OpenSTA linkato dopo `read_spef` e clock propagation.

A differenza dell'SDF post-synthesis, FlexSoC **mantiene gli `INTERCONNECT`**.

```text
Liberty cell delay
+ parasitiche network da SPEF routed
→ calcolo delay OpenSTA
→ timing SDF IOPATH + INTERCONNECT
```

L'SDF contiene delay temporali, non valori raw di resistenza/capacità. SPEF è l'input RC; SDF è la rappresentazione dei delay risultanti per la simulazione.

---

## 22. GLS post-implementation

FlexSoC riusa lo stesso scenario contract funzionale sul final netlist.

Modalità timing:

```text
zero             no SDF
unit             unit-delay style
ff / min         fast-corner SDF
tt / typ         typical-corner SDF
ss / max         slow-corner SDF
```

Per Icarus, le modalità timing routed compilano con:

```text
-gspecify
-ginterconnect
-Tmin / -Ttyp / -Tmax
```

`-ginterconnect` serve perché l'SDF routed contiene path `INTERCONNECT`.

Il JSON di risultato registra esplicitamente:

```text
stage=post_pnr
netlist=.../6_final.v
sdf=.../post_pnr/sdf/<corner>/...
interconnect_delays=enabled
```

### 22.1 Diagnostica SDF strict

`SDF_STRICT=1` trasforma i veri problemi di annotation in failure.

Icarus emette ancora `TIMINGCHECK not supported` per check SDF non implementati. FlexSoC ignora **solo questo warning di capability noto**, preservando come fatal gli errori SDF reali.

```text
feature timing-check Icarus non supportata
→ limitazione nota, riportata

missing cell / bad path / annotation error / SDF incompatibile
→ failure reale
```

STA rimane il checker autoritativo di setup/hold/recovery/removal; GLS esercita il comportamento dinamico del netlist con delay.

---

## 23. Power post-implementation

FlexSoC mantiene due viste complementari.

### 23.1 Power vectorless / assumed-activity

Stesso concetto del pre-implementation ma sul design context finale routed.

Utile per:

- confronto corner;
- baseline power sanity;
- report consistente anche senza workload waveform.

### 23.2 Workload activity power

Una GLS qualificata può fornire switching activity reale.

```text
seleziona waveform GLS PASS
→ converti FST→VCD se necessario
→ read VCD/SAIF in OpenSTA
→ valida coverage dell'activity annotation
→ report internal/switching/leakage/total power
```

Workload e timing corner vengono mantenuti allineati, così una run `tt` viene correlata con il relativo contesto di sign-off e non con artifact di corner diversi.

---

## 24. Timing / power fusion analysis

Fusion analysis correla due viste dello stesso implementation context:

```text
timing:
  critical / near-critical paths

power:
  average instance power sotto l'activity selezionata
```

Domande utili:

- celle molto attive/high-power sono concentrate vicino alla logica timing-critical?
- quali instance sono insieme timing-sensitive e power-relevant?
- un'ottimizzazione migliora una metrica creando pressione sull'altra?

È **correlazione**, non una transient path-energy analysis completa. FlexSoC mantiene esplicita questa distinzione.

---

## Parte VII — Physical sign-off

## 25. Perché physical sign-off è separato da “PnR completato”

Il fatto che il router arrivi a finish dimostra che è stato costruito un layout. Non dimostra automaticamente che ogni check finale di manufacturability sia clean.

Per questo FlexSoC ha `fx physical_signoff` dopo il sign-off post-implementation.

```text
ORFS implementation ha già prodotto artifact route/final
→ esegui esplicitamente target ORFS `drc` e `lvs`
→ raccogli route DRC
→ raccogli antenna
→ raccogli final GDS DRC
→ raccogli LVS
→ raccogli IR/PDN
→ classifica PASS / REVIEW / FAIL
```

FlexSoC non implementa propri engine DRC/LVS: orchestra e qualifica i check della piattaforma ORFS.

---

## 26. Route DRC

Il detailed router produce `5_route_drc.rpt`.

FlexSoC considera una lista non vuota di violazioni come failure.

Domanda verificata:

> La geometria detailed-routed è clean secondo il DRC in-flow del router?

È utile ma non identico al final GDS DRC: entrambi vengono mantenuti.

---

## 27. Antenna sign-off

FlexSoC legge `antenna.log` ORFS ed estrae i conteggi finali net/pin.

```text
0 net violation AND 0 pin violation → PASS
conteggio positivo                  → FAIL
report mancante/non riconosciuto    → REVIEW
```

In questo modo il semplice return code zero del target route non viene scambiato per prova automatica di antenna-clean.

---

## 28. Final GDS DRC

FlexSoC chiede esplicitamente a ORFS il target `drc` sul layout finale e raccoglie:

- `6_drc.lyrdb`;
- `6_drc_count.rpt`.

Qualification:

```text
violation count == 0 → PASS
violation count > 0  → FAIL
DRC non supportato dalla piattaforma → REVIEW/unsupported
output mancante/sconosciuto          → REVIEW
```

È il check più vicino a "il layout streamed finale è rule-clean" con il deck open disponibile.

---

## 29. LVS

Il target ORFS `lvs` confronta la connectivity fisica finale con la rappresentazione circuit/netlist attesa usando il flow LVS configurato dalla piattaforma.

FlexSoC raccoglie:

- `6_lvs.lvsdb`;
- `6_lvs.log`.

Pattern noti di mismatch/error sono failure. Capability assente/non supportata diventa review, non PASS.

EQY e LVS proteggono confini diversi:

```text
EQY:
  comportamento RTL == comportamento logico sintetizzato

LVS:
  connectivity estratta dal layout == connectivity circuit/netlist attesa
```

Servono entrambi.

---

## 30. Evidenza IR-drop / PDN

Quando la piattaforma ORFS produce `VDD.rpt` / `VSS.rpt`, FlexSoC li raccoglie e registra il worst-case IR drop disponibile.

PDNSim/OpenROAD può riportare:

- worst IR drop;
- current density su nodi/segmenti PDN;
- floating PDN stripes;
- dati per-segment current utili ad analisi EM-oriented.

Il physical sign-off corrente raccoglie report/error IR disponibili. **Soglie EM dedicate non sono ancora un gate FlexSoC obbligatorio separato.**

Questo rimane un elemento di tapeout hardening, non qualcosa che il report corrente deve fingere già signed-off.

---

## 31. Metal fill / density: stato corrente

OpenROAD/ORFS supporta metal fill, ma la configurazione FlexSoC corrente usa:

```text
USE_FILL=0
```

Quindi il documento **non** considera final metal fill/density uno stage obbligatorio già qualificato.

Una futura tapeout policy dovrebbe definire:

```text
layout route-clean
→ inserisci fill secondo regole platform/foundry
→ rigenera final GDS
→ riesegui extraction se il fill cambia materialmente le parasitiche
→ riesegui final STA quando richiesto
→ esegui final DRC/density sul vero layout di tapeout
```

---

## Parte VIII — Qualification della run e tracciabilità

## 32. `metrics`, `manifest` e `check`

Un flow ASIC complesso non è utile se il successo può essere dedotto solo aprendo decine di directory di log. FlexSoC raccoglie quindi l'evidenza degli stage in una vista orientata al lifecycle.

Ordine previsto:

```text
RTL lint
CDC / RDC
Functional verification
Formal verification
Synthesis
RTL ↔ synthesis equivalence
Pre-implementation sign-off
Implementation / PnR
Post-implementation sign-off
Physical sign-off
```

### 32.1 `metrics`

Le metrics sono evidenza machine-readable:

- conteggi di verifica;
- coverage;
- area/cell count di sintesi;
- risultati timing;
- conteggi GLS pass/missing/fail;
- riepiloghi power;
- presenza degli artifact di implementation;
- dettagli physical-signoff.

### 32.2 `manifest`

Il manifest collega la run a:

- identità della run;
- contesto PDK/tool selezionato;
- artifact generati importanti;
- output di sign-off;
- file finali di implementation.

È l'inizio di una bill of materials di release/tapeout.

### 32.3 `check`

`fx check` è la vista human-readable della closure.

Non deve riversare ogni report a terminale; deve rispondere in ordine logico:

```text
cosa è PASS?
cosa è FAIL?
cosa richiede REVIEW?
dove si trova l'evidenza a supporto?
```

Esempio: la routed GLS è fully qualified solo se il report dimostra che il supporto SDF interconnect era realmente abilitato. La GLS post-synthesis dichiara `interconnect none`; quella routed dichiara `interconnect enabled`.

---

## Parte IX — Flow FlexSoC corrente completo

## 33. Macro-flow con input e output

### Stage A — CSR e design entry

**Input**

- architettura;
- configurazione clock/reset;
- intent register HJSON.

**FlexSoC fa**

- genera collateral CSR RTL/docs/regmap/driver;
- genera starter RTL/top;
- genera filelist ordinate.

**Output**

- contratto register hardware/software coerente;
- gerarchia RTL elaborabile.

---

### Stage B — Verifica strutturale

**Input**

- RTL ordinato;
- relazioni clock/reset.

**FlexSoC fa**

- lint Slang + Verilator;
- estrazione/classificazione CDC/RDC;
- verification obligations esplicite.

**Output**

- report lint;
- evidenza CDC/RDC PASS/REVIEW/FAIL.

---

### Stage C — Verifica funzionale e formal

**Input**

- RTL;
- intent scenario/model;
- regmap generata;
- property authored.

**FlexSoC fa**

- genera scenari vettore condivisi;
- esegue backend SystemVerilog e cocotb;
- raccoglie HDL coverage;
- esegue CSR BMC/prove/cover;
- esegue design BMC/prove/cover.

**Output**

- evidenza deterministica di regressione funzionale;
- counterexample oppure formal PASS;
- reachability/cover trace;
- report coverage.

---

### Stage D — Sintesi ed equivalence logica

**Input**

- RTL verificato;
- contesto Liberty/PDK;
- target timing.

**FlexSoC fa**

- sintesi generic Yosys;
- `dfflibmap`;
- mapping ABC secondo policy area/delay;
- check sul mapped netlist;
- proof EQY RTL↔netlist.

**Output**

- mapped netlist;
- statistiche di sintesi;
- partition/proof result dell'equivalence.

---

### Stage E — Sign-off pre-implementation

**Input**

- mapped netlist;
- Liberty corner;
- SDC canonico.

**FlexSoC fa**

- STA ideal-clock/no-SPEF;
- generazione SDF cell-delay;
- power estimate vectorless;
- GLS post-synthesis e qualification activity/fusion **prima** del PnR.

**Output**

- prova che il design logico technology-mapped è sufficientemente qualificato per spendere runtime nell'implementation fisica.

---

### Stage F — Implementazione fisica

**Input**

- mapped netlist FlexSoC;
- SDC canonico;
- piattaforma ORFS.

**ORFS/OpenROAD fa**

- import/floorplan;
- setup PDN;
- placement e timing/routability optimization;
- CTS;
- global/detailed routing;
- antenna repair/check;
- finish/extraction.

**Output**

- `6_final.v`;
- `6_final.sdc`;
- `6_final.spef`;
- `6_final.odb`;
- `6_final.gds`.

---

### Stage G — Sign-off post-implementation

**Input**

- final netlist/SDC/SPEF;
- final corner library;
- scenari funzionali.

**FlexSoC fa**

- STA propagated-clock/SPEF;
- generazione routed SDF;
- GLS sul final netlist con SDF `INTERCONNECT`;
- power vectorless e workload;
- timing/power fusion.

**Output**

- routed timing/dynamic/power closure.

---

### Stage H — Physical sign-off

**Input**

- database/GDS/report finali ORFS.

**FlexSoC fa**

- chiama i target ORFS finali DRC/LVS;
- raccoglie route DRC;
- raccoglie antenna;
- qualifica final GDS DRC;
- qualifica LVS;
- raccoglie evidenza IR/PDN.

**Output**

- summary physical-signoff PASS/REVIEW/FAIL.

---

## 34. Flow corrente come pseudocodice eseguibile

```text
configura clock / reset / PDK / identità run

genera HJSON
edita intent CSR
genera register RTL + docs + regmap + driver

genera/adotta RTL scaffold
genera filelist ordinate

esegui lint suite
esegui CDC/RDC
esegui CSR + design formal
esegui regressione funzionale SV + cocotb
raccogli coverage

costruisci contesto canonico sign-off/SDC
sintetizza con Yosys/ABC
prova equivalence RTL ↔ synthesis

esegui STA pre-implementation
scrivi SDF pre-implementation
stima power pre-implementation
esegui tutte le GLS post-synthesis prima del PnR
esegui activity power / timing-power correlation

esegui physical implementation ORFS

usando final netlist + SDC + SPEF ORFS:
  esegui routed STA
  scrivi routed SDF
  esegui post-PnR GLS
  esegui power/activity/fusion

esegui physical sign-off:
  ORFS GDS DRC
  ORFS LVS
  raccogli route DRC / antenna / IR

raccogli metrics
scrivi manifest
stampa lifecycle check
```

---

## 35. Cosa dimostra il flow corrente — e cosa non dimostra

### Evidenza attualmente qualificata

Una run completamente positiva può dimostrare che:

- l'RTL si elabora ed è lint-reviewed da due frontend HDL;
- clock/reset crossing sono classificati strutturalmente con obligations residue esplicite;
- gli scenari funzionali passano su due implementazioni testbench;
- la coverage HDL viene misurata;
- CSR e property authored passano gli stage formal configurati;
- il mapped netlist sintetizzato è behaviorally equivalent all'RTL nel modello EQY;
- le assunzioni timing/power pre-layout sono esplicite;
- il design viene implementato fisicamente da ORFS/OpenROAD;
- il timing finale usa SPEF routed e propagated clocks;
- l'SDF finale contiene routed interconnect delay ed è esercitato dinamicamente in gate-level simulation;
- sono disponibili power vectorless e workload-activity;
- route DRC, antenna, final GDS DRC, LVS ed evidenza IR disponibile entrano nella closure finale.

### Non è ancora un contratto completo di production tapeout

Il flow non rende ancora obbligatori e qualificati:

- scan/DFT insertion e manufacturing test coverage;
- ATPG;
- integrazione compiler SRAM/hard-memory come first-class IP view set;
- policy obbligatoria metal fill + post-fill re-extraction;
- criteri di accettazione EM dedicati;
- integrazione package/pad-ring/full-chip ESD;
- analog/mixed-signal sign-off.

Per un FlexSoC orientato al digital core, i due prossimi grandi blocchi sono DFT e hard memory.

---

## Parte X — Roadmap: DFT

## 36. Perché la DFT appartiene prima del PnR, non dopo il sign-off

Il manufacturing test cambia il circuito implementato. Scan flop occupano area, aggiungono porte/net e creano catene lunghe che influenzano placement e routing.

Il lifecycle target dovrebbe quindi diventare:

```text
RTL
→ synthesis
→ DFT scan replacement / test-mode insertion
→ DFT structural checks
→ pre-implementation sign-off sul netlist DFT-aware
→ placement
→ scan-chain stitching fisicamente informato
→ CTS / routing
→ post-implementation sign-off
→ ATPG / test coverage qualification
→ physical sign-off
```

Il modulo DFT OpenROAD fornisce già primitive utili di scan insertion/planning, ma FlexSoC non le orchestra ancora come stage qualificato.

---

## 37. Building block DFT da aggiungere

### 37.1 Scan-cell replacement

I flop funzionali vengono sostituiti, dove supportato, da flop equivalenti scan-capable.

Un scan flop seleziona concettualmente fra:

```text
functional mode:
  D = normale next-state funzionale

test shift mode:
  D = bit precedente della scan chain
```

`scan_replace` OpenROAD si esegue normalmente prima del placement perché cambiano area e topologia dell'implementazione.

### 37.2 Scan port

Architettura DFT minima:

- `scan_in` — input seriale degli stimulus di test;
- `scan_out` — output seriale dello stato osservato;
- `scan_enable` — selezione shift vs functional/capture;
- opzionalmente test clock e test-mode control secondo l'architettura.

Con più catene:

```text
scan_in[0..N-1]
scan_out[0..N-1]
scan_enable condiviso o partizionato
```

### 37.3 Scan-chain planning

Dopo scan replacement i flop devono essere partizionati in chain.

Policy:

- lunghezza massima catena;
- numero massimo catene;
- possibilità o meno di mischiare clock domain/edge;
- bilanciamento delle lunghezze;
- trade-off test-access bandwidth vs routing cost.

OpenROAD espone `set_dft_config` per lunghezza/numero massimo e clock-mixing policy.

### 37.4 Stitching fisicamente informato

Un ordine logico deciso prima del placement può produrre wire scan enormemente lunghe.

Sequenza preferibile:

```text
sostituisci flop con scan cell
→ esegui placement
→ analizza il DFT chain plan proposto
→ stitch usando le location fisiche per ridurre wirelength
```

`report_dft_plan` e `execute_dft_plan` seguono questo concetto.

### 37.5 Modalità shift e capture

Il timing DFT deve considerare almeno due contesti operativi.

**Shift mode**

```text
scan_enable = 1
scan clock sposta lo stato serialmente
la frequenza può essere inferiore al functional clock
sono importanti le relazioni hold fra elementi adiacenti della chain
```

**Capture mode**

```text
scan_enable = 0 o stato definito per capture
applica uno o più impulsi di test functional-speed / at-speed
cattura la risposta combinatoria nei scan flop
```

FlexSoC dovrebbe generare mode SDC DFT espliciti invece di riutilizzare ciecamente l'SDC funzionale.

### 37.6 Check formal/equivalence DFT

Un flow DFT-aware dovrebbe verificare:

```text
functional mode (scan_enable=0):
  il netlist DFT si comporta come il design sintetizzato pre-DFT

shift mode:
  ordering/connectivity delle scan chain è strutturalmente corretto

interazione reset/test-mode:
  i test control non possono corrompere accidentalmente il funzionamento normale
```

Può essere necessario un ulteriore confine di logical equivalence attorno alla DFT insertion.

### 37.7 ATPG

Scan insertion e generazione dei manufacturing pattern non sono la stessa cosa.

ATPG dovrebbe generare pattern per fault model come:

- stuck-at fault;
- transition/delay fault;
- eventualmente bridging/cell-aware in base a tool e supporto library.

Un futuro stage FlexSoC dovrebbe registrare:

```text
fault targeted
fault detected
fault untestable
fault aborted/unknown
fault coverage
pattern count
shift/capture cycles
```

Il modulo DFT OpenROAD corrente è soprattutto supporto a scan architecture/insertion; non è una soluzione completa di ATPG sign-off. Servirà una strategy/tool integration dedicata.

### 37.8 Contratto di accettazione DFT

Un futuro `fx dft_check` dovrebbe poter riportare:

```text
scan replacement       PASS
scan chain count        N
max/min chain length    ...
scan connectivity       PASS
functional equivalence PASS
shift-mode STA          PASS
capture-mode STA        PASS
ATPG stuck-at coverage  >= target
ATPG transition cov.    >= target
```

Solo a quel punto "DFT complete" ha un significato concreto.

---

## Parte XI — Roadmap: SRAM e hard macro

## 38. Perché una SRAM non dovrebbe essere sintetizzata in flop

Una memoria non banale implementata con standard cell è normalmente molto più grande e power-hungry di una SRAM dedicata. I flow ASIC trattano quindi SRAM e molti altri blocchi come hard macro.

Esempi:

- SRAM / ROM;
- PLL / oscillator;
- analog front-end;
- regulator / power-management block;
- custom datapath macro.

Per FlexSoC la SRAM è il primo target pratico di hard-macro integration.

---

## 39. View richieste per una macro

Una hard macro è un singolo blocco logico rappresentato diversamente a seconda dello stage.

| View | Usata da |
| --- | --- |
| functional Verilog / simulation model | RTL simulation, integrazione GLS |
| black-box/module declaration | gerarchia di sintesi |
| Liberty `.lib` | STA, timing boundary di sintesi, power |
| LEF | floorplan, placement, obstruction/pin routing |
| GDS/OASIS | merge layout finale / physical sign-off |
| CDL/SPICE | LVS / connectivity circuit-level |
| characterization opzionale | power/timing/variation workflow |

La stessa instance deve mantenere naming e connectivity coerenti tra tutte le view.

### 39.1 Comportamento in sintesi

La sintesi deve preservare l'istanza memoria come boundary macro, non flattenarla in logica generica.

```text
RTL memory wrapper
→ riconosci hard macro configurata
→ mantieni cell/interfaccia black-box
→ mappa normalmente la logica circostante
```

### 39.2 Comportamento in STA

La Liberty della macro fornisce:

- timing arc input/output;
- setup/hold constraint;
- clock-to-output delay;
- capacitance/load model;
- power information se caratterizzata.

### 39.3 Comportamento nell'implementazione fisica

La LEF fornisce:

- dimensioni fisiche;
- regole di origin/orientation;
- geometria signal pin;
- geometria power pin;
- routing obstruction.

Il floorplan diventa macro-aware:

```text
posiziona grandi blocchi SRAM
→ riserva halo/channel
→ costruisci/connetti PDN macro
→ piazza standard cell attorno alle macro
→ route delle connessioni signal e power
```

### 39.4 Comportamento LVS/final layout

Il final GDS deve contenere il layout reale della macro e LVS deve avere una rappresentazione circuit/transistor compatibile, normalmente CDL/SPICE o la view richiesta dal vendor/PDK.

---

## 40. OpenRAM come possibile percorso open-source

OpenRAM è un compiler SRAM open source. Può generare view utili, ma il supporto dipende dalla tecnologia.

Un'integrazione responsabile FlexSoC **non** deve assumere "OpenRAM supporta questo PDK" solo perché il tool è open source. Ogni PDK richiede technology file, base cell, model e supporto DRC/LVS.

Una possibile integrazione futura:

```text
macro specification:
  depth
  width
  ports
  PDK/compiler profile

OpenRAM o altro compiler
→ genera implementazione SRAM e view di characterization
→ valida il set di view richiesto
→ registra la macro nella configurazione PDK/IP FlexSoC
→ usa coerentemente la stessa macro in synth / STA / ORFS / LVS
```

### 40.1 Qualification della macro prima dell'uso

Prima che una RAM compilata diventi IP trusted, FlexSoC dovrebbe verificare:

- simulazione funzionale read/write/mask;
- presenza timing model e coverage corner;
- coerenza pin LEF/GDS;
- connectivity power pin;
- DRC/LVS standalone quando possibile;
- pin name Liberty coerenti con RTL/LEF;
- integration smoke PnR.

---

## Parte XII — Elementi full-chip di più lungo termine

## 41. IO/pad ring e confine di package

Per un **core digitale hardened**, il flow corrente può fermarsi al sign-off del core GDS. Un die completo richiede però un ulteriore livello di integrazione:

- signal pad / bump;
- VDD/VSS pad o bump grid;
- strutture/policy ESD;
- pad-ring/corner/filler cell richieste dal PDK;
- assunzioni package/bond;
- constraint timing/load sugli I/O esterni.

È intenzionalmente fuori dalla qualification corrente del core flow.

---

## 42. Blocchi analog e mixed-signal

L'analogico non deve essere aggiunto solo per poter chiamare il core "ASIC". Diventa necessario quando l'architettura richiede PLL, ADC/DAC, oscillator, regulator, analog PHY, ecc.

La responsabilità probabile di FlexSoC non è progettare questi blocchi, ma integrare coerentemente le loro view digital/physical/timing/circuit come hard macro.

---

## Parte XIII — Ordine di implementazione consigliato

## 43. Roadmap pratica dal repository corrente

Il flow copre già gran parte del percorso open digital implementation/sign-off. L'ordine successivo dovrebbe quindi essere mirato.

### 1. Stabilizzare il physical sign-off in CI

- eseguire il nuovo stage ORFS DRC/LVS su E2E single-clock e multi-clock;
- qualificare esplicitamente le differenze capability SKY130/IHP;
- mantenere capability deck assente/non supportata come REVIEW, mai falso PASS;
- decidere policy finale metal fill e post-fill timing;
- decidere se EM/current-density diventa gate obbligatorio.

### 2. Aggiungere DFT come prossimo grande stage funzionale

- discovery delle scan-capable cell;
- scan replacement;
- definizione scan port/test-mode;
- chain planning/stitching placement-aware;
- functional-mode equivalence post insertion;
- timing mode shift/capture;
- integrazione ATPG e manufacturing coverage report.

### 3. Integrare SRAM/hard macro

- definire un contratto generico macro manifest/view;
- integrare inizialmente un solo RAM compiler/profile;
- insegnare a synthesis/STA/ORFS/LVS a usare la stessa definizione macro;
- aggiungere un piccolo E2E single/multi-clock con memoria.

### 4. Passare da core hardening a full-chip quando serve

- pad ring / bump;
- ESD e package assumption;
- full-chip PDN/IR;
- integrazione hard macro analogiche.

---

## Parte XIV — Sequenza comandi di riferimento

## 44. Sequenza di sviluppo rappresentativa

Le opzioni CLI esatte dipendono dalla run, ma il lifecycle è visibile in questa sequenza:

```bash
# Collateral design-entry
fx setup --force
fx hjson --force
fx reg doc --force
fx regmap_py --force
fx rtl_stub --force
fx flist --force

# Verifica pre-synthesis
fx lint_suite
fx cdc_rdc
fx formal
fx tests_gen --force
fx setup_tb setup_cocotb --force
fx regression
fx coverage_detail

# Technology mapping e proof logica
fx setup_signoff --force
fx syn --force
fx eqy --force

# Sign-off pre-implementation / gate verification
fx sta
fx sdf
fx power_estimate
fx sim_post_syn_all
fx power_analysis_all
fx fusion_analysis_all

# Implementation
fx pnr --set ORS=/path/to/OpenROAD-flow-scripts/flow

# Routed sign-off
fx setup_signoff_post_pnr --force
fx sta_post_pnr
fx sdf_post_pnr
fx power_estimate_post_pnr
fx sim_post_pnr_all
fx power_analysis_post_pnr_all
fx fusion_analysis_post_pnr_all

# Final physical sign-off
fx physical_signoff --set ORS=/path/to/OpenROAD-flow-scripts/flow

# Qualification / traceability
fx metrics
fx manifest
fx check
fx manifest_show
```

Regola di ordering fondamentale: **tutta la verifica/sign-off post-synthesis deve completarsi prima del PnR**, mentre il routed sign-off parte solo quando gli artifact finali di implementation esistono.

---

## Parte XV — Riferimenti tecnici esterni

Il comportamento FlexSoC descritto sopra deriva principalmente dal codice del repository. Questi riferimenti upstream descrivono algoritmi e capability dei tool esterni.

### Lint / elaborazione SystemVerilog

- documentazione Slang: <https://www.sv-lang.com/>
- manuale Slang: <https://www.sv-lang.com/user-manual.html>
- CLI Slang: <https://sv-lang.com/command-line-ref.html>
- warning Verilator: <https://verilator.org/guide/latest/warnings.html>
- command reference Verilator: <https://verilator.org/guide/latest/exe_verilator.html>

### Yosys / sintesi

- Yosys technology mapping e ABC: <https://yosyshq.readthedocs.io/projects/yosys/en/latest/cmd/index_passes_techmap.html>
- ORFS `SDC_FILE` e variabili di timing/sintesi: <https://openroad-flow-scripts.readthedocs.io/en/latest/user/FlowVariables.html>
- OpenSTA e semantica SDC/SPEF: <https://openroad.readthedocs.io/en/latest/main/src/sta/README.html>
- overview Yosys technology mapping: <https://yosyshq.readthedocs.io/projects/yosys/en/v0.55/using_yosys/synthesis/techmap_synth.html>
- strategy di sintesi LibreLane: <https://librelane.readthedocs.io/en/latest/reference/step_config_vars.html>
- synthesis exploration LibreLane: <https://librelane.readthedocs.io/en/latest/usage/writing_custom_flows.html>

### OpenROAD / implementazione fisica

- overview OpenROAD: <https://openroad.readthedocs.io/en/latest/main/README2.html>
- global placement / RePlAce: <https://openroad.readthedocs.io/en/latest/main/src/gpl/README.html>
- PDN generation: <https://openroad.readthedocs.io/en/latest/main/src/pdn/README.html>
- CTS / TritonCTS: <https://openroad.readthedocs.io/en/latest/main/src/cts/README.html>
- detailed routing / TritonRoute: <https://openroad.readthedocs.io/en/latest/main/src/drt/README.html>
- IR-drop / PDNSim: <https://openroad.readthedocs.io/en/latest/main/src/psm/README.html>
- DFT: <https://openroad.readthedocs.io/en/latest/main/src/dft/README.html>

### Roadmap SRAM

- OpenRAM: <https://openram.org/>
- porting technology OpenRAM: <https://openram.org/PORTING.html>

---

## 45. Modello mentale finale

FlexSoC può essere letto come una sequenza di rappresentazioni sempre più concrete dello stesso design intent:

```text
intent register / architetturale
        ↓
comportamento RTL
        ↓
RTL qualificato strutturalmente e formalmente
        ↓
RTL qualificato funzionalmente
        ↓
netlist technology-mapped ma ancora logico
        ↓
mapped netlist logicamente equivalente
        ↓
netlist qualificato timing/power pre-layout
        ↓
implementazione fisica placed/clocked/routed
        ↓
final netlist con timing SPEF-aware e delay dinamici
        ↓
artifact fisico qualificato DRC/LVS/antenna/IR
        ↓
manifest di release tracciabile
```

Ogni stage risponde a una classe diversa di domande. La forza del flow deriva dal **non permettere che il PASS di un tool sostituisca il lavoro di un altro**:

- lint non sostituisce CDC;
- CDC non sostituisce formal;
- simulation non sostituisce equivalence;
- equivalence non sostituisce STA;
- STA non sostituisce GLS;
- PnR completion non sostituisce DRC/LVS;
- physical sign-off non sostituisce manufacturing test.

Il prossimo confine è quindi chiaro: aggiungere **DFT/testability** e **hard-memory integration** mantenendo la stessa disciplina di input espliciti, script generati, evidenza machine-readable e lifecycle closure.
