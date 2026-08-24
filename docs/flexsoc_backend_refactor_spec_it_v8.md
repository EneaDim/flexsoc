# FlexSoC backend refactor specification — v8 reusable package interfaces

**Status:** specifica architetturale vincolante per il refactoring  
**Scope:** `src/flexsoc`, con focus su `src/flexsoc/backend`  
**Principio guida:** pochi file, ordine identico al flow, granularità operativa completa.

---

# 1. Correzioni rispetto alla v6

La v7 mantiene `core`, `design`, `dv`, `syn`, ma separa definitivamente **sign-off** e **implementation**.

1. `signoff/` è un dominio autonomo con `sta.py`, `gls.py`, `power.py`, `fusion.py`.
2. `impl/` contiene per ora soltanto `impl.py` oltre a `__init__.py`.
3. Pre- e post-implementation sign-off sono due configurazioni dello stesso `SignoffFlow`.
4. `impl/impl.py` prepara/esegue/raccoglie ORFS/OpenROAD e non contiene analisi di sign-off.
5. La physical closure post-route viene orchestrata dal facade `signoff.post` senza creare, per ora, un ulteriore `physical.py`.
6. Restano valide le operazioni pubbliche esplicite con parametri propri e la macro canonica `.flow()`.

Il lifecycle leggibile diventa:

```text
design
→ dv
→ syn
→ equivalence
→ signoff.pre
→ impl.pnr
→ signoff.post
→ reporting
```

Questa separazione evita di legare il motore di sign-off a ORFS e rende possibile sostituire o aggiungere in futuro un backend di implementation senza riscrivere STA/GLS/power/fusion.

# 2. Lifecycle autorevole

Il flow deve risultare leggibile sia dall'albero dei file sia dalle facade Python.

```text
0. Core
   workspace / run layout
   PDK catalogue / fetch / use / views
   clock intent
   execution target
   toolchain / doctor
        │
1. Design — register description
   HJSON scaffold
        │
2. Design — register collateral
   CSR RTL
   docs
   C driver
   Python regmap
        │
3. Design — RTL
   core scaffold
   top scaffold/regeneration
   hierarchy / ordered filelists
        │
4. Design — model
   Python reference model scaffold
   model test scaffold
   regmap test scaffold
        │
5. DV
   lint
   CDC/RDC
   testbench scaffold
   functional test generation
   SystemVerilog
   cocotb
   coverage
   formal
        │
6. Synthesis
   Yosys / ABC
        │
7. Equivalence
   EQY
        │
8. Sign-off — pre implementation
   canonical SDC
   STA
   SDF
   GLS
   vectorless power
   activity power
   fusion
        │
9. Implementation
   ORFS / OpenROAD
   floorplan / PDN / placement / CTS / route
        │
10. Sign-off — post implementation
    routed STA
    routed SDF
    routed GLS
    vectorless power
    activity power
    fusion
    route DRC
    antenna
    final GDS DRC
    LVS
    IR / PDN
        │
11. Core qualification
    metrics
    manifest
    check
        │
12. Core package
    ip_save / ip_load
```

SoC e FSM sono subflow di **design**. Tutorial, cleanup e orchestration globale non diventano nuovi package.

# 3. Albero finale target

```text
src/flexsoc/
├── __init__.py
├── __main__.py
├── api.py
├── cli.py
└── backend/
    ├── __init__.py
    ├── Makefile
    │
    ├── core/
    │   ├── __init__.py
    │   ├── core.py
    │   ├── execution.py
    │   ├── package.py
    │   ├── reporting.py
    │   ├── toolchain.py
    │   ├── deps.sh
    │   └── toolchain.lock
    │
    ├── design/
    │   ├── __init__.py
    │   ├── regs.py
    │   ├── rtl.py
    │   ├── model.py
    │   ├── soc.py
    │   └── fsm_gen/
    │       ├── __init__.py
    │       ├── generator.py
    │       ├── Makefile
    │       ├── README.md
    │       └── examples/
    │
    ├── dv/
    │   ├── __init__.py
    │   ├── dv.py
    │   ├── testbench.py
    │   ├── functional.py
    │   ├── coverage.py
    │   ├── cdc.py
    │   └── formal.py
    │
    ├── syn/
    │   ├── __init__.py
    │   ├── syn.py
    │   └── eqy.py
    │
    ├── signoff/
    │   ├── __init__.py
    │   ├── sta.py
    │   ├── gls.py
    │   ├── power.py
    │   └── fusion.py
    │
    └── impl/
        ├── __init__.py
        └── impl.py
```

Le responsabilità sono ora visibili direttamente:

```text
signoff/   analizza e qualifica il design prima/dopo PnR
impl/      costruisce fisicamente il design
```

`signoff/__init__.py` è una facade leggera: espone `pre` e `post`, orchestra i quattro motori e raccoglie/qualifica la physical closure post-route.

Non si crea per ora `signoff/physical.py`: DRC/LVS/antenna/IR sono un blocco piccolo rispetto ai quattro motori principali e possono restare nella facade finché la loro implementazione non giustifica un file autonomo.


## 3.1 Regola `__init__.py`

Ogni directory che contiene codice Python riutilizzabile è un package esplicito e contiene `__init__.py`.

Quindi devono esistere:

```text
backend/__init__.py

backend/core/__init__.py
backend/design/__init__.py
backend/design/fsm_gen/__init__.py

backend/dv/__init__.py

backend/syn/__init__.py

backend/signoff/__init__.py

backend/impl/__init__.py
```

Directory di soli dati/esempi, come `fsm_gen/examples/`, non richiedono `__init__.py` finché non contengono codice Python importabile.

Gli `__init__.py` hanno tre responsabilità:

1. esporre la facade pubblica del package;
2. re-esportare value object realmente riutilizzabili;
3. nascondere la disposizione interna dei moduli al chiamante.

Esempio:

```python
# backend/signoff/__init__.py
from .sta import StaAnalysis
from .gls import GateLevelSimulation
from .power import PowerAnalysis
from .fusion import FusionAnalysis

__all__ = [
    "Signoff",
    "SignoffStage",
    "StaAnalysis",
    "GateLevelSimulation",
    "PowerAnalysis",
    "FusionAnalysis",
]
```

Il chiamante deve poter scrivere:

```python
from flexsoc.backend.signoff import PowerAnalysis, SignoffStage
```

senza dipendere da:

```python
from flexsoc.backend.signoff.power import PowerAnalysis
```

quando non è necessario.

### Regola di dimensione

`__init__.py` deve restare piccolo:

```text
re-export
facade wiring
piccoli enum/value object
```

Non deve contenere:

```text
renderer lunghi
subprocess
parser di report
algoritmi CDC
Tcl generation
ORFS execution
```

Queste responsabilità restano nei moduli del package.

### Stabilità API

Gli import esposti dagli `__init__.py` costituiscono il boundary Python riutilizzabile.

Durante il refactor è quindi preferibile cambiare la disposizione interna dei file senza rompere:

```python
from flexsoc.backend.design import RegsFlow, RtlFlow, ModelFlow
from flexsoc.backend.dv import DvFlow
from flexsoc.backend.syn import SynthesisFlow, EquivalenceFlow
from flexsoc.backend.signoff import Signoff, SignoffStage
from flexsoc.backend.impl import ImplementationFlow
```

Questo rende possibile riusare le stesse strutture in futuro per:

```text
DFT
macro/SRAM integration
remote execution
alternative implementation backend
custom application API
```

# 4. Contratto comune: operazioni esplicite + macro `flow()`

La facade deve dare libertà senza costringere ogni operazione dentro un generico:

```python
flow.setup("x", ...)
flow.run("y", ...)
```

L'API primaria usa invece **metodi espliciti**.

## 4.1 Metodo specifico

Ogni setup/run realmente diverso ha una firma propria.

Esempio registers:

```python
regs.setup_hjson(
    path=None,
    *,
    regmap=None,
    force=False,
)

regs.generate_rtl(
    *,
    regmap=None,
)

regs.generate_docs(
    *,
    regmap=None,
)

regs.generate_driver(
    *,
    regmap=None,
    language="c",
)

regs.generate_regmap_py(
    *,
    regmap=None,
)
```

Esempio DV:

```python
dv.testbench.setup_systemverilog(
    *,
    simulator="iverilog",
    force=False,
)

dv.testbench.setup_cocotb(
    *,
    simulator="iverilog",
    force=False,
)

dv.functional.generate_test(
    name,
    *,
    seed=None,
    overwrite=False,
)

dv.functional.run_systemverilog(
    name,
    *,
    waves=False,
    coverage=False,
)

dv.functional.run_cocotb(
    name,
    *,
    waves=False,
    coverage=False,
)
```

Questo permette a ogni operazione di avere parametri coerenti col proprio dominio.

## 4.2 Macro `flow()`

Ogni facade può avere:

```python
flow(...)
```

che esegue il percorso canonico del dominio.

Esempi:

```python
regs.flow(...)
dv.flow(...)
syn.flow(...)
impl.pre.flow(...)
impl.pnr.flow(...)
impl.post.flow(...)
```

`.flow()`:

- usa i default/config già presenti nel `BackendContext`;
- può ricevere opzioni di alto livello pertinenti all'intero flow;
- chiama internamente i metodi specifici;
- non contiene una seconda implementazione;
- non equivale a “esegui letteralmente ogni metodo disponibile”;
- esclude viewer, cleanup, debug distruttivi o operazioni opzionali non canoniche.

## 4.3 Perché non `.all()`

`.all()` suggerisce che debbano essere eseguite tutte le capability del modulo.

Non è corretto per FlexSoC perché alcuni metodi sono:

```text
viewer
debug
coverage detail
cleanup
optional backend
single-test helpers
alternative simulators
```

`flow()` significa invece:

> esegui il percorso standard approvato per questo dominio.

## 4.4 Compatibility layer

I 191 target storici possono continuare a essere risolti tramite un registry:

```python
TARGET_ALIASES = {
    "setup_cocotb": dv.testbench.setup_cocotb,
    "test_gen": dv.functional.generate_test,
    ...
}
```

Questo mapping serve a CLI/Makefile compatibility.

**Non deve essere l'API OO interna primaria.**

## 4.5 Dipendenze

Un metodo specifico dichiara in modo semplice i prerequisite.

Esempio:

```python
def run_cocotb(...):
    self._require_model()
    self._require_cocotb_tb()
    ...
```

Quando `auto_setup=True`, il prerequisite mancante può essere preparato automaticamente.

Con `auto_setup=False`, il metodo fallisce indicando precisamente quale setup manca.

I preflight tecnologia/tool devono avvenire prima di modifiche parziali.

## 4.6 Pianificazione e dry-run

I metodi che lanciano tool devono accettare, quando utile:

```python
dry_run=True
on="server-name"
```

e restituire un piano/risultato strutturato.

La pianificazione include:

```text
operation
dependencies
execution target
cwd
main inputs
main outputs
log
```

Non serve una gerarchia astratta di flow.

# 5. `core/`

`core/__init__.py` espone le strutture pubbliche di contesto, execution, package, reporting e toolchain senza duplicarne la logica.


`core` contiene infrastruttura trasversale e contratti globali.

## 5.1 `core/core.py`

Owner di:

```text
BackendContext
RunLayout
ClockDomain
ClockRelationship
ClockConfig
PDKSpec
PDKViews
PdkManager
Action / Actions
CleanupFlow
Tutorial orchestration helpers
BackendError / ToolError
```

Assorbe:

```text
src/flexsoc/clocking.py
src/flexsoc/pdk.py
src/flexsoc/run_layout.py
parti globali di backend/common.py
```

### PDK lifecycle — obbligatorio

API interna target:

```python
fx.pdk.list()
fx.pdk.info("sky130")
fx.pdk.fetch("sky130")
fx.pdk.fetch("sky130", version="<40-char-commit>")
fx.pdk.use("sky130")
fx.pdk.use("ihp-sg13g2", root="/opt/pdks/ihp")
fx.pdk.views("sky130")
```

CLI compatibile:

```bash
fx pdk list
fx pdk info sky130
fx pdk fetch sky130
fx pdk use sky130
```

#### Catalogue da preservare

```text
sky130       Ciel   ORFS sky130hd      aliases sky130hd/sky130hs
gf180mcu     Ciel   ORFS gf180         alias gf180
ihp-sg13g2   Git    ORFS ihp-sg13g2    aliases ihp/sg13g2
asap7        Git    ORFS asap7
nangate45    Git    ORFS nangate45     alias freepdk45
```

Preservare classificazioni real-preview/predictive/reference.

#### Fetch Ciel

Per SKY130/GF180:

```text
ciel ls-remote
    ↓
revision
    ↓
ciel enable
    ↓
Open-PDKs variant
    ↓
.flexsoc/pdks/<family> → variant
```

Preservare:

- `PDK_VERSION` opzionale;
- validazione 40-char commit;
- variant `sky130A` / `gf180mcuD`;
- `--force`;
- metadata sidecar per symlink;
- errore azionabile se Ciel manca.

#### Fetch Git

Preservare shallow clone e shallow/recurse submodules dove già richiesto.

#### Formal adapter

Preservare il fetch pinned dell'adapter formal SKY130 e `FORMAL_PDK_PROC`.

#### View discovery

Preservare:

```text
Liberty typ
Liberty slow
Liberty fast
functional gate-level Verilog
```

`usable` richiede almeno typical Liberty + Verilog funzionale.

#### Derived technology variables

Preservare:

```text
PDK
PDK_ROOT
PDK_CLASS
ORS_TECH
DRIVING_CELL
TIEHI_CELL_AND_PORT
TIELO_CELL_AND_PORT
MIN_BUF_CELL_AND_PORTS
LIB_SYN
LIBS
PRIM
FORMAL_PDK_PROC
```

#### No legacy fallback

Non reintrodurre auto-discovery da `repo/pdks/<name>`.

Usare `.flexsoc/pdks/<name>` o `PDK_ROOT` esplicito.

#### PDK remoto

I PDK non vengono rsyncati automaticamente con ogni stage.

Un execution target remoto può dichiarare root installati:

```python
pdks={
    "sky130": "/opt/pdks/sky130",
    "ihp-sg13g2": "/opt/pdks/ihp-sg13g2",
}
```

Il fetch locale corrente resta il default.

## 5.2 `core/execution.py`

Owner di:

```text
ExecutionTarget
ExecutionPlan
CommandRequest
CommandResult
Executor Protocol
LocalExecutor
SshExecutor
ToolRunner
```

```python
@dataclass(frozen=True, slots=True)
class CommandRequest:
    argv: tuple[str, ...]
    cwd: Path
    env: Mapping[str, str]
    log: Path
    inputs: tuple[Path, ...] = ()
    outputs: tuple[Path, ...] = ()
```

Execution target può dichiarare host, work root, sync mode, PDK map, ORFS root e env overrides.

Mai `if remote:` negli stage.

## 5.3 `core/package.py`

Owner di `ip_load` / `ip_save` e saved-IP validation.

```python
fx.package.run("load")
fx.package.run("save")
```

Preservare canonical sign-off Tcl e tutti i collateral salvati.

## 5.4 `core/reporting.py`

Unifica metrics + manifest + check.

```python
fx.reporting.run("metrics")
fx.reporting.run("manifest")
fx.reporting.run("metrics", "manifest", "check")
fx.reporting.show("manifest")
fx.reporting.show("check")
```

Default:

```text
metrics → manifest → check
```

## 5.5 `core/toolchain.py`

Assorbe `doctor.py` e orchestration di `deps.sh`/`toolchain.lock`.

```python
fx.toolchain.setup("bootstrap")
fx.toolchain.run("deps")
fx.toolchain.run("doctor", "versions", "status")
fx.toolchain.run("env")
fx.toolchain.run("prune", apply=True)
```

`prune` non è default.

`deps.sh` e `toolchain.lock` si spostano in `core/` insieme all'owner Python.

---

# 6. `design/`

`design/__init__.py` costruisce/esporta la facade `Design` e re-esporta i flow riutilizzabili del dominio.


`design` possiede tutto ciò che costruisce design e collateral prima della DV.

`design/__init__.py` espone:

```python
fx.design.regs
fx.design.rtl
fx.design.model
fx.design.soc
fx.design.fsm
```

Non serve un generico `design.setup("...")` come API primaria.

## 6.1 `design/regs.py`

Assorbe:

```text
hjson_gen.py
driver_gen.py
setup_model_regmap.py
reg/doc recipes del Makefile
```

`regmap_py` è qui perché è collateral CSR derivato dall'HJSON.

### API target

```python
regs.setup_hjson(
    *,
    path=None,
    regmap=None,
    force=False,
)

regs.generate_rtl(
    *,
    regmap=None,
)

regs.generate_docs(
    *,
    regmap=None,
)

regs.generate_driver(
    *,
    regmap=None,
    language="c",
)

regs.generate_regmap_py(
    *,
    regmap=None,
)

regs.flow(
    *,
    regmap=None,
    force=False,
)
```

`flow()` chiama il percorso canonico:

```text
setup_hjson
→ generate_rtl
→ generate_docs
→ generate_driver
→ generate_regmap_py
```

ma non impedisce di usare ogni step singolarmente.

Preservare HJSON multipli `<top>_*.hjson` e `REGMAP` filtering.

## 6.2 `design/rtl.py`

Assorbe:

```text
rtl_stub_gen.py
top_from_core.py
source/filelist part of slang_tools.py
vendor fetch recipe
RTL-specific helpers from common.py
```

### API target

```python
rtl.setup_scaffold(
    *,
    multi_clock=None,
    force=False,
)

rtl.fetch_vendor(
    name=None,
    *,
    update=False,
)

rtl.generate_top(
    *,
    force=False,
)

rtl.generate_filelists()

rtl.show_hierarchy(...)
rtl.show_ast(...)
rtl.show_slang_filelist(...)

rtl.flow(...)
```

Preservare:

```text
single-clock scaffold
multi-clock scaffold
register windows
clock/reset ports
CDC primitives
top regeneration
ordered rtl_common.f
ordered rtl_ip.f
```

`fetch_vendor()` è distinto da `fx.pdk.fetch()`.

## 6.3 `design/model.py`

Assorbe la parte reference-model di `setup_model.py`.

### API target

```python
model.setup_reference(
    *,
    force=False,
)

model.setup_model_tests(
    *,
    force=False,
)

model.setup_regmap_tests(
    *,
    force=False,
)

model.flow(
    *,
    force=False,
)
```

Output:

```text
dv/functional/model/<top>_model.py
dv/functional/model/<top>_tests.py
dv/functional/model/<top>_regmap_tests.py
dv/functional/model/README.md
```

`<top>_regmap.py` appartiene a `regs.generate_regmap_py()`.

La materializzazione dei test concreti appartiene a `dv/functional.py`.

## 6.4 `design/soc.py`

Il SoC subflow conserva metodi specifici, non string selectors come API primaria.

Esempi:

```python
soc.setup_config(...)
soc.init_xbar(...)
soc.setup_fusesoc(...)
soc.generate_uart(...)
soc.generate_ibex(...)
soc.prepare(...)
soc.generate(...)
soc.generate_software(...)
soc.build_software(...)
soc.simulate(...)
soc.run(...)
soc.view(...)
soc.flow(...)
```

Gli alias storici dei target SoC rimangono nel compatibility registry.

## 6.5 `design/fsm_gen/`

Sposta integralmente il sottosistema corrente sotto `design`.

API concettuale:

```python
fsm.init(...)
fsm.setup(...)
fsm.example(...)
fsm.generate(...)
fsm.plot(...)
fsm.flow(...)
fsm.install(...)
```

Preservare Makefile, README, esempi e output correnti.

# 7. `dv/`

`dv/__init__.py` espone `DvFlow`, testbench, functional, coverage, CDC e formal come API del package.


La DV non viene compressa in un solo modulo.

```text
dv/
├── __init__.py
├── dv.py
├── testbench.py
├── functional.py
├── coverage.py
├── cdc.py
└── formal.py
```

Ogni file ha una responsabilità leggibile.

## 7.1 `dv/dv.py`

Facade e lint orchestration.

Contiene:

```text
DvFlow
Slang lint orchestration
Verilator lint orchestration
focused lint checks
high-level DV flow
```

API:

```python
dv.lint(...)
dv.lint_slang(...)
dv.lint_verilator(...)
dv.lint_suite(...)
dv.flow(...)
```

`dv.flow()` orchestri il percorso DV canonico, richiamando `functional`, `testbench`, `coverage`, `cdc`, `formal`.

Non reimplementa i sottostage.

## 7.2 `dv/testbench.py`

Crea **la struttura di testbench**, non i test funzionali.

Assorbe la parte scaffold di:

```text
setup_tb.py
setup_cocotb.py
```

### SystemVerilog

```python
testbench.setup_systemverilog(
    *,
    simulator="iverilog",
    force=False,
    include_tlul=True,
)
```

Genera/preserva concettualmente:

```text
<top>_tb.sv
include_<top>_tb.sv
tlul_if.sv
reg_if.sv
reg_utils.sv
drivers/<top>_reg_driver.svh
drivers/<top>_vec_driver.svh
drivers/<top>_vec_monitor.svh
drivers/<top>_tlul_driver.svh
```

### cocotb

```python
testbench.setup_cocotb(
    *,
    simulator="iverilog",
    force=False,
)
```

Genera/preserva:

```text
<top>_tb.py
<top>_tb.sv
drivers/__init__.py
drivers/reg_driver.py
drivers/vec_driver.py
drivers/vec_monitor.py
```

### Compile helpers

Se serve conservare la granularità storica:

```python
testbench.compile_systemverilog(...)
testbench.compile_verilog(...)
testbench.compile_cocotb(...)
```

Il testbench non chiama il reference model per generare expected vectors.

## 7.3 `dv/functional.py`

È owner del **functional test intent**.

Assorbe:

- materializzazione test/scenario da `setup_model.py`;
- semantica condivisa oggi dispersa in `setup_tb.py`;
- orchestration delle simulazioni funzionali.

### Input contract

```text
config.regs
data_in.vec
data_out.vec
@write
@read
@reset
@cfg
interface input transactions
expected output transactions
```

### API generation

```python
functional.generate_tests(
    *,
    seed=None,
    overwrite=False,
)

functional.generate_test(
    name,
    *,
    seed=None,
    overwrite=False,
)

functional.generate_expected(
    name,
    *,
    model=None,
)
```

`generate_expected()` richiama il reference model e aggiorna/materializza gli expected output secondo il contract corrente.

### API execution

```python
functional.run_systemverilog(
    name=None,
    *,
    waves=False,
    coverage=False,
    strict=True,
)

functional.run_cocotb(
    name=None,
    *,
    waves=False,
    coverage=False,
)

functional.run_regression(
    *,
    engines=("sv", "cocotb"),
    coverage=False,
)

functional.flow(...)
```

La struttura resta UVM-like:

```text
scenario / sequencer-like input
        ↓
driver
        ↓
DUT
        ↓
monitor
        ↓
scoreboard
        ↑
reference model / expected
```

SV e cocotb condividono la stessa semantica; cambiano renderer/runtime.

## 7.4 `dv/coverage.py`

Owner esclusivo di coverage collection e rendering.

Assorbe `coverage_report.py` e la parte coverage orchestration dispersa altrove.

API:

```python
coverage.collect(
    *,
    engine=None,
)

coverage.merge(
    inputs=None,
)

coverage.report(
    *,
    detail=False,
)

coverage.annotate(...)

coverage.flow(...)
```

Preservare:

```text
coverage
coverage_detail
Verilator coverage
merge
annotated/detail reports
```

Coverage non deve essere nascosta dentro `functional.py`.

## 7.5 `dv/cdc.py`

Assorbe `cdc_rdc.py`.

API:

```python
cdc.setup(
    *,
    strict=None,
)

cdc.run(
    *,
    strict=None,
)

cdc.report(...)
```

Preservare integralmente:

```text
Yosys design IR
clock/reset-domain extraction
crossings
synchronizer detection
multi-bit coherency
FIFO/handshake recognition
reconvergence
glitch/setup/reset obligations
PASS/REVIEW/FAIL qualification
```

## 7.6 `dv/formal.py`

Assorbe `setup_formal.py`.

Metodi specifici:

```python
formal.setup_csr(...)
formal.run_csr_bmc(...)
formal.run_csr_prove(...)
formal.run_csr_cover(...)

formal.setup_design(...)
formal.run_bmc(...)
formal.run_prove(...)
formal.run_cover(...)

formal.flow(...)
```

Ogni metodo mantiene parametri propri per depth, engine, mode, timeout e property selection dove già applicabile.

Preservare BMC/PDR/SMTBMC/cover e authored properties.

# 8. `syn/`

`syn/__init__.py` espone synthesis ed equivalence come due componenti dello stesso macro-stage post-DV.


```text
syn/
├── __init__.py
├── syn.py
└── eqy.py
```

## 8.1 `syn/syn.py`

API esplicita:

```python
syn.setup_asic(
    *,
    strategy=None,
    force=False,
)

syn.run_asic(
    *,
    strategy=None,
    on=None,
)

syn.setup_xilinx(...)
syn.run_xilinx(...)

syn.setup_ice40(...)
syn.run_ice40(...)

syn.run_yosys_vgen(...)
syn.run_sv2v(...)

syn.flow(
    *,
    target="asic",
    strategy=None,
    on=None,
)
```

Preservare:

```text
syn / syn_v / syn_sv
ASIC Yosys
Xilinx
iCE40
ABC area/delay/none
abc.constr
.ys
mapped netlist
RTLIL
statistics
yosys-vgen
sv2v
Vivado handoff esistente
```

Il timing contract resta:

```text
ClockConfig
   ├── ABC synthesis hint
   └── canonical SDC → implementation/sign-off
```

## 8.2 `syn/eqy.py`

API:

```python
eqy.setup(
    *,
    strategy=None,
    force=False,
)

eqy.run(
    *,
    strategy=None,
    engine=None,
    on=None,
)

eqy.debug(
    *,
    partition=None,
    trace=True,
)

eqy.flow(...)
```

Preservare:

```text
gold/gate model
protocol normalization
reset normalization
formal-cell preprocessing
SKY130 adapter
IHP handling
SAT/PDR/SMT strategies
partition evidence
counterexample/VCD diagnostics
```

Il compatibility registry conserva `setup_eqy`, `eqy`, `eqy_debug`.

# 9. `signoff/`

`signoff/__init__.py` è anche il boundary pubblico stabile del package e re-esporta le analisi riutilizzabili.


```text
signoff/
├── __init__.py
├── sta.py
├── gls.py
├── power.py
└── fusion.py
```

`signoff` è un dominio autonomo e non dipende concettualmente da ORFS.

La facade espone due viste dello stesso motore:

```python
fx.signoff.pre
fx.signoff.post
```

La differenza è il `SignoffStage`, non una duplicazione dell'implementazione.

## 9.1 `signoff/__init__.py`

Contiene soltanto orchestration e oggetti di dominio piccoli:

```text
SignoffStage
SignoffContext
SignoffFlow
PreSignoff
PostSignoff
PhysicalSignoff summary/qualification
```

Non deve diventare un quinto file monolitico.

API:

```python
fx.signoff.pre.flow(...)
fx.signoff.post.flow(...)
```

e accesso ai metodi specifici descritti sotto.

### Stage model

Pre:

```text
netlist          synthesized
SDC              canonical FlexSoC
SPEF             none
clock network    ideal
GLS interconnect none
physical         N/A
```

Post:

```text
netlist          6_final.v
SDC              6_final.sdc
SPEF             6_final.spef
clock network    propagated
GLS interconnect enabled
physical         enabled
```

### Physical closure

Solo `post` espone:

```python
post.run_gds_drc(...)
post.run_lvs(...)

post.collect_route_drc(...)
post.collect_antenna(...)
post.collect_ir_pdn(...)

post.run_physical(...)
```

`run_physical()` orchestra i target ORFS finali realmente eseguibili e poi raccoglie tutti i report fisici.

Non inventare run separati per route DRC/antenna/IR quando questi sono report già prodotti dal PnR.

## 9.2 `signoff/sta.py`

Owner di:

```text
canonical SDC generation
OpenSTA setup
pre-implementation STA
post-route STA
SPEF read/annotation
ideal clock model
propagated clock model
timing report parsing
path-viewer data
SDF generation
SDF header normalization
```

API esposta tramite `pre`/`post`:

```python
pre.setup_sdc(...)
pre.setup_sta(...)
pre.run_sta(...)
pre.write_sdf(...)

post.setup_sta(...)
post.run_sta(...)
post.write_sdf(...)
```

`post` usa `6_final.sdc` e `6_final.spef`; non rigenera un falso SDC routed.

## 9.3 `signoff/gls.py`

Owner esclusivo della gate-level simulation.

Assorbe la parte GLS di `post_sim.py` e la relativa orchestration.

API:

```python
pre.run_gls(
    *,
    mode="all",
    strict=True,
)

post.run_gls(
    *,
    mode="all",
    strict=True,
)
```

Preservare:

```text
zero delay
unit delay
SDF min
SDF typ
SDF max
all timing modes
strict SDF evidence
TIMINGCHECK unsupported filtering
Icarus 13
post-syn cell-delay-only behavior
post-route -ginterconnect
IHP model/cleanup behavior
```

Il motore seleziona il delay model dal `SignoffStage`, non da branch duplicati sparsi.

## 9.4 `signoff/power.py`

Owner di power estimate e activity power.

Oggetti concreti:

```text
ActivitySpec
PowerAnalysis
```

API tramite `pre`/`post`:

```python
pre.run_power_estimate(...)
pre.run_power_activity(...)

post.run_power_estimate(...)
post.run_power_activity(...)
```

Preservare:

```text
vectorless power
VCD/FST discovery
fst2vcd
scope resolution
DUT instance resolution
OpenSTA power Tcl
corner/scenario qualification
instance hotspots
power summary JSON/report
```

## 9.5 `signoff/fusion.py`

Fusion rimane un file autonomo e un'operazione pubblica esplicita.

Oggetto:

```text
FusionAnalysis
```

API:

```python
pre.run_fusion(...)
post.run_fusion(...)
```

Preservare:

```text
timing/power scenario alignment
critical timing-path correlation
workload power correlation
fusion Tcl
fusion tables
fusion report
fusion summary JSON
enrichment/qualification
```

Fusion legge gli output normalizzati di `sta.py` e `power.py`; non rilancia quei tool.

## 9.6 Macro canoniche

`pre.flow()` esegue il percorso approvato:

```text
setup SDC/Tcl
→ STA
→ SDF
→ GLS
→ vectorless power
→ activity power
→ fusion
```

`post.flow()`:

```text
routed STA
→ routed SDF
→ routed GLS
→ vectorless power
→ activity power
→ fusion
→ GDS DRC
→ LVS
→ collect route DRC
→ collect antenna
→ collect IR/PDN
```

L'ordine concreto resta quello validato dagli E2E.

---

# 10. `impl/`

`impl/__init__.py` espone la facade di implementation senza incorporare sign-off o tool execution logic.


Per ora `impl` resta volutamente minimo:

```text
impl/
├── __init__.py
└── impl.py
```

Non contiene STA, GLS, power, fusion o physical report qualification.

## 10.1 `impl/impl.py`

Assorbe esclusivamente:

```text
setup_pnr.py
pnr_run.py
ORFS/PnR business logic del Makefile
```

Facade:

```python
fx.impl.pnr
```

API:

```python
pnr.setup(
    *,
    pdk=None,
    orfs_root=None,
    force=False,
)

pnr.run(
    *,
    target="all",
    on=None,
)

pnr.collect()

pnr.view(
    *,
    stage=None,
)

pnr.flow(
    *,
    on=None,
)
```

Responsabilità:

```text
ORFS config.mk
physical-only handoff
active OpenROAD/Yosys/KLayout path contract
floorplan
PDN
placement
timing repair
CTS
global route
detailed route
finish
parasitic extraction
final artifact discovery
```

Artifact finali canonici:

```text
6_final.v
6_final.sdc
6_final.spef
6_final.odb
6_final.gds
```

`pnr.collect()` restituisce questi artifact e i report ORFS necessari al successivo `signoff.post`.

`impl.py` non interpreta DRC/LVS/power/STA come closure globale; il loro owner è `signoff/`.

## 10.2 Boundary fra implementation e sign-off

Il contratto deve essere netto:

```text
signoff.pre
    │
    │ synth netlist + canonical SDC
    ▼
impl.pnr
    │
    │ 6_final.v + 6_final.sdc + 6_final.spef + reports
    ▼
signoff.post
```

Questo permette in futuro:

```text
ORFS implementation
commercial implementation
alternative OpenROAD wrapper
```

senza duplicare il sign-off.

# 11. Backend facade

```python
class Backend:
    def __init__(self, ctx):
        self.pdk = PdkManager(ctx)
        self.design = Design(ctx)
        self.dv = Dv(ctx)
        self.syn = Syn(ctx)
        self.signoff = Signoff(ctx)
        self.impl = Impl(ctx)
        self.reporting = Reporting(ctx)
        self.package = Package(ctx)
        self.toolchain = Toolchain(ctx)
```

Le facade aggregate espongono oggetti concreti:

```python
fx.design.regs
fx.design.rtl
fx.design.model

fx.dv.testbench
fx.dv.functional
fx.dv.coverage
fx.dv.cdc
fx.dv.formal

fx.syn.synthesis
fx.syn.eqy

fx.signoff.pre
fx.impl.pnr
fx.signoff.post
```

Esempio end-to-end esplicito:

```python
fx.design.regs.setup_hjson(...)
fx.design.regs.generate_rtl(...)
fx.design.regs.generate_docs(...)
fx.design.regs.generate_driver(...)
fx.design.regs.generate_regmap_py(...)

fx.design.rtl.setup_scaffold(...)
fx.design.rtl.generate_top(...)
fx.design.rtl.generate_filelists(...)

fx.design.model.setup_reference(...)
fx.design.model.setup_model_tests(...)
fx.design.model.setup_regmap_tests(...)

fx.dv.lint_suite(...)
fx.dv.cdc.setup(...)
fx.dv.cdc.run(...)

fx.dv.testbench.setup_systemverilog(...)
fx.dv.testbench.setup_cocotb(...)
fx.dv.functional.generate_tests(...)
fx.dv.functional.run_regression(...)
fx.dv.coverage.report(...)

fx.dv.formal.setup_design(...)
fx.dv.formal.run_prove(...)
fx.dv.formal.setup_csr(...)
fx.dv.formal.run_csr_prove(...)

fx.syn.synthesis.setup_asic(...)
fx.syn.synthesis.run_asic(...)
fx.syn.eqy.setup(...)
fx.syn.eqy.run(...)

fx.signoff.pre.flow(...)
fx.impl.pnr.setup(...)
fx.impl.pnr.run(on="pnr-server")
fx.impl.pnr.collect()
fx.signoff.post.flow(on="pnr-server")

fx.reporting.flow(...)
```

Per il percorso convenzionale, ogni dominio può essere ridotto a:

```python
fx.design.regs.flow(...)
fx.design.rtl.flow(...)
fx.design.model.flow(...)
fx.dv.flow(...)
fx.syn.flow(...)
fx.signoff.pre.flow(...)
fx.impl.pnr.flow(...)
fx.signoff.post.flow(...)
fx.reporting.flow(...)
```

Questo dà sia granularità sia una API breve per l'uso normale.

# 12. Preservation matrix dei file correnti

| File corrente | Owner finale | Responsabilità |
|---|---|---|
| `clocking.py` | `core/core.py` | clock intent |
| `pdk.py` | `core/core.py` | catalogue/fetch/views/use/formal adapter |
| `run_layout.py` | `core/core.py` | canonical run paths |
| `doctor.py` | `core/toolchain.py` | tool/capability checks |
| `backend/common.py` | `core/core.py` + `design/rtl.py` | split per dominio |
| `backend/output.py` | `core/execution.py` + CLI | execution/result rendering |
| `hjson_gen.py` | `design/regs.py` | HJSON scaffold |
| `driver_gen.py` | `design/regs.py` | C driver |
| `setup_model_regmap.py` | `design/regs.py` | Python regmap |
| `rtl_stub_gen.py` | `design/rtl.py` | RTL scaffold |
| `top_from_core.py` | `design/rtl.py` | top regeneration |
| `slang_tools.py` | `design/rtl.py` + `dv/dv.py` | source inspection vs lint |
| `setup_model.py` | `design/model.py` + `dv/dv.py` | model scaffold vs scenario generation |
| `setup_tb.py` | `dv/dv.py` | functional semantics/SV |
| `setup_cocotb.py` | `dv/dv.py` | cocotb |
| `coverage_report.py` | `dv/dv.py` | coverage |
| `cdc_rdc.py` | `dv/cdc.py` | CDC/RDC |
| `setup_formal.py` | `dv/formal.py` | property formal |
| `setup_syn.py` | `syn/syn.py` | synthesis |
| `setup_eqy.py` | `syn/eqy.py` | equivalence setup |
| `eqy_debug.py` | `syn/eqy.py` | equivalence debug |
| `setup_sdc.py` | `signoff/*` | SDC |
| `setup_signoff.py` | `signoff/*` + `impl/power.py` | timing/GLS vs power/fusion |
| `post_sim.py` | `signoff/*` | gate simulation |
| `setup_pnr.py` | `impl/impl.py` | ORFS config |
| `pnr_run.py` | `impl/impl.py` | ORFS execution |
| `physical_signoff.py` | `signoff/*` | physical closure |
| `metrics.py` | `core/reporting.py` | metrics/check |
| `manifest.py` | `core/reporting.py` | manifest/show |
| `soc_*.py`, `xbar_init.py`, `setup_fsoc.py`, `sw_soc_gen.py` | `design/soc.py` | SoC subflow |
| `fsm_gen/*` | `design/fsm_gen/*` | FSM subflow |
| `deps.sh` | `core/deps.sh` | managed dependencies |
| `toolchain.lock` | `core/toolchain.lock` | pinned toolchain |
| `Makefile` | backend root shim | compatibility only |

---

# 13. Artifact preservation

## Registers/design

```text
data/<top>.hjson
rtl/<top>_reg_pkg.sv
rtl/<top>_reg_top.sv
doc/<top>.md
doc/<top>_interfaces.md
drivers/<top>.c
drivers/<top>.h
dv/functional/model/<top>_regmap.py
rtl/<top>_core.sv
rtl/<top>.sv
rtl/rtl_common.f
rtl/rtl_ip.f
```

## Model

```text
dv/functional/model/<top>_model.py
dv/functional/model/<top>_tests.py
dv/functional/model/<top>_regmap_tests.py
dv/functional/model/README.md
```

## Functional DV

```text
dv/functional/tests/<test>/config.regs
dv/functional/tests/<test>/data_in.vec
dv/functional/tests/<test>/data_out.vec
```

Preservare tutti gli scaffold SV/cocotb correnti, drivers/monitor/interfaces e coverage output.

## Sign-off Tcl

```text
signoff/<pdk>/sta/sta.tcl
signoff/<pdk>/sdf/write_sdf.tcl
signoff/<pdk>/power/estimate/power_estimate.tcl
signoff/<pdk>/power/analysis/power_analysis.tcl
signoff/<pdk>/fusion/fusion_analysis.tcl
```

## ORFS

```text
6_final.v
6_final.sdc
6_final.spef
6_final.odb
6_final.gds
```

Preservare physical summary/report e metrics/manifest JSON.

---

# 14. Remote execution

La run tree locale resta canonica.

```text
local inputs
  → path map / rsync
  → remote command
  → declared outputs
  → local run tree
```

PDK e ORFS sono normalmente installazioni remote dichiarate, non payload da copiare.

Esempio:

```yaml
pnr-server:
  kind: ssh
  host: eda@server
  work_root: /scratch/flexsoc
  orfs_root: /opt/orfs/flow
  pdks:
    sky130: /opt/pdks/sky130
```

---

# 15. Cleanup, viewer, tutorial

Non creare nuovi file.

`CleanupFlow` vive in `core/core.py`.

Viewer restano presso il dominio owner:

```text
DV waveform/TB         dv/dv.py
post-syn               syn/*
STA path               signoff/sta.py
OpenROAD GUI           impl/impl.py
SoC                    design/soc.py
FSM plot               design/fsm_gen
```

Tutorial orchestration resta in `backend/__init__.py`/API e chiama i flow reali.

---

# 16. High-level compatibility flows

Preservare `ip_start`, `ip_flow`, `ip_flow_noreg`, `ip_flow_all` componendo le nuove facade.

Non duplicare business logic nel Makefile.

Gli IP-load E2E mantengono l'attuale stop pre-PnR e l'attuale policy EQY fino a modifica esplicita.

---

# 17. Style contract

```text
module docstring            <= 8 righe
function/method docstring   <= 2 righe
comment block               <= 2 righe
```

Indicativamente:

```text
core/core.py         900–1200
core/execution.py    350–550
core/package.py      400–700
core/reporting.py    900–1200
core/toolchain.py    450–700

design/regs.py       600–900
design/rtl.py        700–1000
design/model.py      700–1000
design/soc.py        900–1200

dv/dv.py             300–500
dv/testbench.py      700–1000
dv/functional.py     800–1100
dv/coverage.py       350–600
dv/cdc.py            900–1200
dv/formal.py         600–900

syn/syn.py           700–1000
syn/eqy.py           900–1200

signoff/sta.py       700–1000
signoff/gls.py       600–900
signoff/power.py     700–1000
signoff/fusion.py    450–700
signoff/__init__.py  300–500

impl/impl.py         600–900
```

Sono compromessi fra pochi file e leggibilità, non obiettivi di code golf.

---

# 18. Regole vietate

```text
utils/helpers/manager generici
abstract hierarchy profonde
factory/DI framework
global mutable state
os.environ sparso
subprocess sparso
argparse/main nei moduli finali
if remote nei flow
SV/cocotb semantics duplicate
string-selector come unica API per operazioni parametrizzabili
pre/post signoff duplicati
```

---

# 19. Sequenza di migrazione

## Phase 0 — baseline

API/E2E/CI verdi.

## Phase 1 — core

Creare `core/`; migrare clocking, PDK, RunLayout, doctor.

Testare nella stessa patch:

```text
pdk list
pdk info
pdk fetch provider planning/mock
pdk view discovery
pdk use
technology overrides
execution local planning
```

## Phase 2 — design/regs

HJSON, reg, doc, driver, regmap_py.

## Phase 3 — design/rtl

RTL scaffold/top/filelist/vendor fetch.

## Phase 4 — design/model

Reference model/test scaffolds.

## Phase 5 — syn

Synthesis + EQY.

## Phase 6 — impl/impl

ORFS come pilot del ToolRunner.

## Phase 7 — impl signoff/power

Pre/post closure e physical sign-off.

## Phase 8 — core reporting/package

Metrics/manifest/check + IP load/save.

## Phase 10 — DV facade / testbench / formal

Migrare lint orchestration e separare chiaramente gli scaffold SystemVerilog/cocotb in `dv/testbench.py`.

Migrare formal con metodi espliciti per setup/run e parametri propri.

## Phase 11 — CDC/RDC

Algoritmo invariato; API esplicita `setup()/run()/report()`.

## Phase 12 — functional DV + coverage

Migrare scenario generation e shared functional semantics in `dv/functional.py`.

Poi collegare i testbench SV/cocotb già migrati e portare coverage in `dv/coverage.py`.

Eliminare le definizioni/rendering duplicate oggi presenti in `setup_tb.py`.

## Phase 13 — SoC/FSM

Spostare sotto design.

## Phase 14 — API/CLI/Makefile

Dispatch Python diretto e Makefile shim.

## Phase 15 — test cleanup

Solo a refactor stabilizzato.

---

# 20. Acceptance criteria per patch

Ogni patch dichiara:

1. file migrati;
2. action setup/run/collect coinvolte;
3. alias legacy;
4. dipendenze auto-setup;
5. artifact preservati;
6. PDK/tool preflight;
7. execution target;
8. test eseguiti;
9. hash pre/post;
10. nessun cambio Docker/toolchain non dedicato.

---

# 21. Definition of done

- albero uguale alla sezione 3;
- ogni directory Python del backend ha `__init__.py` e un boundary di import esplicito;
- PDK/clocking/layout/doctor dentro backend/core;
- PDK fetch/use/discovery completamente preservato;
- ogni operazione parametrizzabile ha un metodo esplicito con firma propria;
- granularità dei 191 target preservata tramite compatibility registry/alias;
- `regmap_py` in `design/regs.py`;
- model scaffold in `design/model.py`;
- `dv/testbench.py`, `dv/functional.py` e `dv/coverage.py` hanno owner distinti;
- SV e cocotb condividono la stessa functional semantics senza condividere forzatamente lo scaffold;
- synthesis+EQY sotto `syn/`;
- pre/post sign-off sotto `signoff/`;
- `impl/` contiene per ora soltanto `impl.py` oltre alla facade;
- `sta.py`, `gls.py`, `power.py`, `fusion.py` hanno owner espliciti;
- physical closure parte di `signoff.post`;
- reporting/package/toolchain sotto `core/`;
- SoC/FSM sotto `design/`;
- local/SSH ortogonale agli stage;
- Makefile non owner della business logic;
- single-clock, multi-clock e IP-load E2E invariati.

---

# 22. Regola finale

> **La cartella dice la macro-fase; `__init__.py` ne definisce l'API riutilizzabile; il file dice il dominio; il metodo dice l'operazione concreta e ne possiede i parametri; `.flow()` compone il percorso canonico.**

Ridurre i file non significa ridurre le capability.


---

# 23. Inventario completo dei target pubblici correnti

Generato dal registry `TARGETS` dello stato auditato; è una preservation checklist vincolante.

## Help — owner finale: `api.py / cli.py`

**5 target:**

- `help` — Show backend target help
- `help_ip` — Show IP-flow help
- `help_soc` — Show SoC-flow help
- `help_doc` — Show documentation-flow help
- `help_fsm` — Show FSM-flow help

## Setup — owner finale: `core/core.py + design/soc.py`

**3 target:**

- `setup` — Create the run directory tree
- `soc_cfg` — Render SoC configuration variables
- `soc_start` — Initialize a SoC run from loaded IPs

## Signoff — owner finale: `syn/eqy.py + signoff/*`

**17 target:**

- `sta_corners` — Run STA setup/hold for each configured corner
- `power_estimate_corners` — Estimate power for each corner using global activity
- `signoff_corners` — Run SDF, multi-corner STA and estimated power
- `setup_eqy` — Generate RTL-vs-post-synthesis EQY configuration
- `eqy` — Prove RTL equivalent to the post-synthesis netlist with EQY
- `setup_signoff` — Generate PDK-scoped SDC and signoff scripts
- `compile_syn` — Compile post-synthesis simulation
- `sim_syn` — Run post-synthesis simulation
- `sta` — Run static timing analysis
- `sdf` — Write SDF timing files
- `power_estimate` — Estimate power using global switching activity
- `power_analysis` — Analyze power in the GLS trace aligned signoff scenario
- `power_analysis_all` — Analyze power for all matching aligned GLS scenarios
- `fusion_analysis` — Correlate timing and power in one aligned GLS scenario
- `fusion_analysis_all` — Correlate timing and power for all aligned GLS scenarios
- `sta_violators` — Report timing violators
- `path_view` — Build interactive STA path view

## IP flow — owner finale: `backend/__init__.py + design/*`

**13 target:**

- `hjson` — Generate an HJSON register template
- `hjson_gen` — Compatibility alias for HJSON generation
- `reg` — Generate register RTL from HJSON
- `doc` — Generate register documentation
- `rtl_stub` — Generate RTL core and aligned top wrapper
- `top_from_core` — Regenerate top wrapper from edited core ports
- `flist` — Generate Slang-ordered common/IP RTL filelists
- `driver` — Generate C driver files from HJSON
- `fetch` — Fetch or update a vendored dependency
- `ip_start` — Bootstrap a complete IP run
- `ip_flow` — Run regression, formal, synthesis, signoff, and final reports
- `ip_flow_noreg` — Run full closure without regenerating registers
- `ip_flow_all` — Run full IP flow including PnR

## Linting — owner finale: `dv/dv.py`

**17 target:**

- `lint` — Run Slang lint first, then Verilator lint
- `lint_slang` — Run Slang HDL lint
- `lint_verilator` — Run Verilator HDL lint
- `lint_slang_suite` — Run the full Slang lint suite
- `lint_verilator_suite` — Run the full Verilator lint suite
- `lint_suite` — Run full Slang suite, then full Verilator suite
- `lint_v` — Run Verilog lint checks
- `lint_sv` — Run SystemVerilog lint checks
- `lint_latch` — Run latch-focused HDL lint diagnostics
- `lint_undriven` — Run undriven-signal HDL lint diagnostics
- `lint_width` — Run width-focused HDL lint diagnostics
- `lint_unconnected` — Run unconnected-port HDL lint diagnostics
- `lint_unused` — Run unused-object HDL lint diagnostics
- `_lint_run` — Internal lint dispatcher
- `slang_hier` — Generate hierarchy text with slang-hier
- `slang_ast` — Generate Slang AST JSON
- `slang_flist` — Generate a trimmed topological RTL filelist with Slang

## Domain analysis — owner finale: `dv/cdc.py`

**2 target:**

- `setup_cdc_rdc` — Generate pre-technology CDC/RDC structural extraction
- `cdc_rdc` — Run structural CDC/RDC, protocol, reset, setup, and glitch checks

## DV functional — owner finale: `design/model.py + dv/dv.py`

**19 target:**

- `setup_tb` — Generate a SystemVerilog testbench scaffold
- `setup_cocotb` — Generate a cocotb scaffold
- `setup_model` — Generate Python model, CSR regmap, and test scaffolds
- `regmap_py` — Regenerate only <top>_regmap.py from HJSON
- `tests_gen` — Generate all vector tests from <top>_tests.py
- `test_gen` — Generate one vector test selected by TEST_NAME
- `tests` — List generated vector tests
- `compile` — Compile the current testbench
- `compile_v` — Compile Verilog simulation
- `compile_sv` — Compile SystemVerilog simulation
- `sim` — Run simulation
- `sim_v` — Run Verilog simulation
- `sim_sv` — Run SystemVerilog simulation
- `sim_tests` — Run every generated SystemVerilog vector test
- `cocotb` — Run cocotb tests
- `cocotb_tests` — Run every generated cocotb vector test
- `regression` — Run all tests on selected backends with Verilator coverage
- `coverage` — Merge and report existing Verilator coverage data
- `coverage_detail` — Show uncovered Verilator coverage points

## Viewing — owner finale: `dv/dv.py + syn/syn.py + impl/*`

**9 target:**

- `view` — Open latest waveform
- `view_cocotb` — Open latest cocotb waveform
- `view_syn` — Reserved synthesis waveform viewer target
- `plot_postsyn` — Open post-synthesis graph
- `view_presyn` — Open pre-synthesis graph
- `view_presyn_v` — Open pre-synthesis graph from Verilog
- `view_presyn_sv` — Open pre-synthesis graph from SV
- `tb_save` — Save testbench regression artifacts
- `tb_view` — Open saved testbench waveform

## Synthesis — owner finale: `syn/syn.py`

**6 target:**

- `setup_syn` — Generate Yosys synthesis scripts
- `syn` — Run synthesis
- `syn_v` — Run Verilog synthesis
- `syn_sv` — Run SystemVerilog synthesis
- `yosys-vgen` — Convert SV to Verilog with Yosys
- `sv2v` — Convert SV to Verilog with sv2v

## DV formal — owner finale: `dv/formal.py`

**13 target:**

- `setup_formal` — Create or preserve starter design assertions and covers
- `setup_formal_csr_prove` — Generate shared CSR BMC/prove configuration
- `setup_formal_csr_cover` — Generate automatic CSR cover configuration
- `formal_csr_bmc` — Bounded-check automatic CSR assertions
- `formal_csr_prove` — Prove automatic CSR semantics with SymbiYosys
- `formal_csr_cover` — Reach automatic CSR cover points with SymbiYosys
- `formal_csr` — Run CSR BMC, prove, then cover
- `formal` — Run all formal stages BMC, prove, then cover
- `setup_formal_prove` — Generate shared design BMC/prove configuration
- `setup_formal_cover` — Generate authored-property cover configuration
- `formal_bmc` — Bounded-check authored design assertions
- `formal_prove` — Prove authored properties with SymbiYosys
- `formal_cover` — Reach authored cover properties with SymbiYosys

## Gate simulation — owner finale: `signoff/*`

**6 target:**

- `compile_post_syn` — Compile post-synthesis gate-level simulation with Icarus
- `sim_post_syn` — Run post-synthesis gate-level simulation with optional SDF
- `sim_post_syn_all` — Run every selected post-synthesis GLS test/timing combination with one backend
- `compile_post_pnr` — Compile post-PnR gate-level simulation with Icarus
- `sim_post_pnr` — Run post-PnR gate-level simulation with optional SDF
- `sim_post_pnr_all` — Run every selected post-PnR GLS test/timing combination

## Post-PnR signoff — owner finale: `signoff/*`

**9 target:**

- `setup_signoff_post_pnr` — Generate post-PnR OpenSTA scripts from final ORFS artifacts
- `signoff_post_pnr` — Run post-PnR SDF, STA and vectorless power
- `sdf_post_pnr` — Write post-PnR SDF from final netlist, SDC and SPEF
- `sta_post_pnr` — Run SPEF-aware STA with propagated clock reporting
- `power_estimate_post_pnr` — Estimate post-PnR power with extracted parasitics
- `power_analysis_post_pnr` — Analyze post-PnR power for one GLS workload
- `power_analysis_post_pnr_all` — Analyze post-PnR power for all matching GLS workloads
- `fusion_analysis_post_pnr` — Correlate routed timing and power for one GLS workload
- `fusion_analysis_post_pnr_all` — Correlate routed timing and power for all GLS workloads

## Run metadata — owner finale: `core/reporting.py`

**4 target:**

- `metrics` — Collect functional/formal/synthesis/signoff metrics
- `manifest` — Collect automatic run identity into meta/manifest.json
- `manifest_show` — Show the current run manifest in color
- `check` — Show existing complete run closure status and metrics

## Implementation — owner finale: `impl/impl.py`

**3 target:**

- `setup_pnr` — Generate OpenROAD implementation config
- `pnr` — Run OpenROAD implementation
- `pnr_gui` — Open OpenROAD GUI

## Physical signoff — owner finale: `signoff/*`

**1 target:**

- `physical_signoff` — Run ORFS DRC/LVS and qualify physical sign-off

## IP load/save — owner finale: `core/package.py`

**2 target:**

- `ip_load` — Load the complete IP package into a run workspace
- `ip_save` — Save reusable current-PDK collateral and qualification metadata

## SoC flow — owner finale: `design/soc.py`

**19 target:**

- `soc_vendor_deps` — Fetch pinned lowRISC dependencies required by SoC simulation
- `fsoc_init` — Initialize FuseSoC metadata
- `fsoc` — Generate FuseSoC core file
- `xbar` — Generate crossbar artifacts
- `xbar_init` — Generate crossbar input config
- `xbar_build` — Run tlgen for crossbar RTL
- `soc` — Generate SoC RTL
- `soc_stage_tops` — Stage SoC top-level files
- `soc_flist` — Generate Slang-ordered SoC common/IP filelists
- `soc_flow` — Generate crossbar, SoC RTL and filelist
- `soc_uart_gen` — Generate UART-host SoC artifacts
- `soc_ibex_gen` — Generate Ibex-host SoC artifacts
- `sw_soc` — Generate SoC software scaffold
- `soc_prepare` — Prepare SoC build directory
- `soc_build_sw` — Build SoC software
- `soc_sim` — Build SoC simulator
- `soc_run` — Run SoC simulation
- `soc_run_only` — Alias for SoC simulation run
- `soc_view` — Open SoC waveform

## FSM flow — owner finale: `design/fsm_gen/*`

**8 target:**

- `fsm_init` — Create FSM workspace directories
- `fsm_setup` — Set up the FSM generator
- `fsm_example_load` — Load the FSM example inputs
- `fsm_gen` — Generate FSM RTL
- `fsm_plot` — Plot FSM diagrams
- `fsm_flow` — Generate and plot FSM artifacts
- `fsm_install` — Install FSM artifacts into the IP run
- `fsm2rtl` — Alias for FSM RTL installation

## Tutorials — owner finale: `backend/__init__.py orchestration`

**7 target:**

- `soc_uart_tutorial` — Run UART-host SoC tutorial
- `soc_ibex_fetch` — Fetch Ibex tutorial dependencies
- `soc_ibex_tutorial` — Run Ibex-host SoC tutorial
- `full_tutorial` — Run the full IP tutorial flow
- `fsm_tutorial` — Run the FSM tutorial flow
- `ip_tutorial` — Run the IP tutorial flow
- `soc_pless` — Run the tiny SoC tutorial flow

## Dependencies — owner finale: `core/toolchain.py + core/deps.sh`

**7 target:**

- `deps-bootstrap` — Check/install prerequisites for a dependency profile
- `deps` — Install pinned base, impl, or riscv profile
- `deps-doctor` — Verify the selected pinned dependency profile
- `deps-versions` — Show pinned tool versions and revisions
- `deps-env` — Print shell exports for the pinned toolchain
- `deps-status` — Show managed toolchains, disk use, and command duplicates
- `deps-prune` — Prune obsolete managed toolchains and optional build caches

## Cleanup — owner finale: `core/core.py`

**21 target:**

- `clean-pyc` — Remove Python caches
- `clean_doc` — Remove generated docs
- `clean_log` — Remove logs
- `clean_rtl` — Remove generated RTL
- `clean_sim` — Remove simulation outputs
- `clean_cocotb` — Remove cocotb outputs
- `clean_formal` — Remove property-formal proof outputs
- `clean_syn` — Remove synthesis outputs
- `clean_signoff` — Remove signoff outputs
- `clean_meta` — Remove run metadata
- `clean_pnr` — Remove PnR outputs
- `clean_fsm` — Clean FSM generator outputs
- `clean_fsm_all` — Deep-clean FSM generator outputs
- `clean_agent` — Remove old agent outputs
- `clean_fsoc` — Remove FuseSoC build outputs
- `clean_soc` — Remove SoC build outputs
- `clean_sw` — Clean SoC software outputs
- `clean_vendor` — Remove vendored IP checkouts
- `clean_subdir` — Clean helper subdirectories
- `clean` — Clean generated flow outputs
- `clean_all` — Remove all generated run outputs

**Totale target backend censiti: 191.**
