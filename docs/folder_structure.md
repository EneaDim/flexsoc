# 🗂️ FlexSoC folder structure

FlexSoC keeps **reusable source**, **generated collateral**, **run results**, and
**tool orchestration** deliberately separate. That separation is what makes it
possible to regenerate one layer without accidentally overwriting authored
intent somewhere else.

> 🔑 **Rule of thumb:** `hw/ips/<top>/` is reusable design source;
> `<WORKDIR>/runs/<RUN_TOP>/<RUN_ID>/` is disposable run state;
> `src/flexsoc/backend/` is the orchestration implementation behind `fx`.

## 📚 Reusable IP source

```text
hw/ips/<top>/
├── data/                 # HJSON and other design source metadata
├── doc/                  # retained documentation
├── rtl/                  # reusable RTL
├── dv/
│   ├── functional/
│   │   ├── model/        # model, generated regmap API, test catalogue
│   │   ├── tests/        # retained vectors when intentionally versioned
│   │   ├── tb/           # retained SV/cocotb verification collateral
│   │   └── sim/
│   │       └── rtl/      # retained simulation configuration, e.g. .gtkw
│   └── formal/
│       └── properties/   # authored assertions/covers when intentionally saved
├── syn/                  # retained synthesis collateral when source-owned
├── signoff/              # retained signoff collateral when source-owned
├── pnr_openroad/         # retained physical-design configuration/results
└── qualification/        # future selected release/qualification evidence
```

Run-only databases are not reusable IP source. Coverage databases, simulator
scratch, generated proof traces, transient waveforms, `results.xml`, caches, and
one-off logs stay out of `hw/ips/<top>/`.

## 🧪 Generated run workspace

A normal run is isolated by `RUN_TOP` and `RUN_ID`:

```text
<WORKDIR>/runs/<RUN_TOP>/<RUN_ID>/
├── data/
│   └── <top>.hjson               # or one HJSON per register domain
├── doc/                          # generated register documentation
├── rtl/
│   ├── <top>.sv
│   ├── <top>_core.sv
│   ├── rtl_common.f              # shared reachable infrastructure
│   └── rtl_ip.f                  # reachable IP/run hierarchy
├── dv/
│   ├── functional/
│   │   ├── model/
│   │   │   ├── <top>_model.py
│   │   │   ├── <top>_regmap.py
│   │   │   └── <top>_tests.py
│   │   ├── tests/
│   │   │   └── <TEST_NAME>/
│   │   │       ├── config.regs
│   │   │       ├── data_in.vec
│   │   │       └── data_out.vec
│   │   ├── tb/
│   │   │   ├── sv/
│   │   │   └── cocotb/
│   │   ├── sim/
│   │   │   ├── rtl/
│   │   │   ├── post_syn/
│   │   │   └── post_layout/      # only when that flow exists
│   │   ├── coverage/
│   │   │   ├── sv/
│   │   │   ├── cocotb/
│   │   │   ├── merged.dat
│   │   │   ├── summary.txt
│   │   │   ├── summary.json
│   │   │   └── annotated/
│   │   └── saved/                # deliberately retained functional artifacts
│   └── formal/
│       ├── csr/
│       │   ├── generated/        # generated CSR properties/bind collateral
│       │   ├── prove/            # SymbiYosys proof work/results
│       │   └── cover/            # SymbiYosys reachability work/results
│       ├── properties/
│       │   ├── prove/            # authored assertions + BMC/proof work/results
│       │   └── cover/            # authored covers + reachability work/results
│       └── equivalence/
│           └── rtl_vs_syn/       # EQY RTL ↔ mapped-netlist closure
├── analysis/
│   ├── slang/                    # AST/hierarchy/debug artifacts
│   ├── cdc/                      # planned structural CDC analysis
│   └── rdc/                      # planned structural RDC analysis
├── syn/                          # synthesis scripts/netlists/results
├── signoff/
│   ├── sdf/                      # timing back-annotation files
│   └── ...                       # STA / power scripts and reports
├── pnr_openroad/                 # physical-design workspace/collateral
├── logs/
│   ├── dv/
│   │   ├── functional/
│   │   └── formal/
│   ├── lint/
│   ├── synthesis/
│   └── signoff/
└── meta/
    ├── manifest.json
    └── metrics.json
```

Directories for optional or future flows are created only when needed. For
example, `analysis/cdc/`, `analysis/rdc/`, and `sim/post_layout/` should not be
empty placeholders in every run.

## 🧪 Design-verification ownership

FlexSoC treats verification as three different closure axes rather than one
number.

### 🟠 Functional verification

```text
dv/functional/
├── model/       # expected behavior + generated CSR API + test catalogue
├── tests/       # materialized reusable stimulus/expectations
├── tb/          # SV and cocotb execution infrastructure
├── sim/         # simulator outputs per DUT representation
└── coverage/    # Verilator code/toggle/expression/branch/FSM/user coverage
```

`fx regression` runs the generated catalogue on both SystemVerilog and cocotb
backends and merges Verilator coverage. The human and machine-readable reports
use the same scope × type model:

```text
Scope          line   toggle   expr   branch   fsm   user   total
design          ...     ...     ...      ...    ...    ...     ...
registers       ...     ...     ...      ...    ...    ...     ...
common          ...     ...     ...      ...    ...    ...     ...
other           ...     ...     ...      ...    ...    ...     ...
all             ...     ...     ...      ...    ...    ...     ...
```

`summary.txt` is for people; `summary.json` is the stable machine-readable
contract consumed by metrics/reporting.

### 🧠 Formal verification

```text
dv/formal/
├── csr/          # automatically generated register semantic checks
└── properties/   # authored design assertions and cover properties
```

Formal closure has different semantics from code coverage:

- **BMC** finds shallow assertion failures quickly;
- **PROVE** attempts unbounded/inductive proof;
- **COVER** checks whether interesting states/sequences are reachable.

These results are kept as proof/reachability status and are **not added to code
coverage percentages**.

### 🔁 RTL ↔ synthesis equivalence

```text
dv/formal/equivalence/rtl_vs_syn/
```

`fx equiv` uses EQY to compare RTL against the mapped post-synthesis netlist.
The useful closure metric is the number and percentage of EQY partitions proven
equivalent, with failures, engine errors, timeouts, and unknown partitions kept
separate.

Equivalence is downstream of synthesis: a netlist change invalidates the EQY
result even when the functional vectors did not change.

### 🌐 CDC / RDC analysis — next step

CDC and RDC are intentionally modeled under `analysis/`, not under functional
coverage. They are planned structural/static analyses for multi-clock and reset
architectures and will complement simulation, formal proof, and equivalence
rather than being folded into any of those percentages.

## 🧠 Generated model and tests

`fx setup_model` creates the bootstrap split:

```text
dv/functional/model/
├── <top>_model.py
├── <top>_regmap.py
└── <top>_tests.py
```

Ownership after bootstrap:

- `<top>_model.py` — authored behavioral/reference model;
- `<top>_regmap.py` — generated from HJSON; regenerate with `fx regmap_py --force`;
- `<top>_tests.py` — authored scenarios and vector-generation policy.

`fx tests_gen --force` materializes those scenarios under
`dv/functional/tests/<TEST_NAME>/` without changing the authored model.

## 🧰 Backend implementation map

`src/flexsoc/backend/` contains the Python implementation behind the stable
Make/`fx` target surface. The files are intentionally split by responsibility.

| File | Responsibility |
| --- | --- |
| `common.py` | Shared filesystem, source-ordering, and backend helper functions. |
| `hjson_gen.py` | Starter HJSON/register specification generation. |
| `driver_gen.py` | Small software driver helpers derived from register metadata. |
| `rtl_stub_gen.py` | Starter RTL core and wrapper generation. |
| `top_from_core.py` | Refresh a still-generated top wrapper after core-port changes. |
| `slang_tools.py` | Slang hierarchy, AST, reachability, and ordered filelist utilities. |
| `setup_model.py` | Single-clock behavioral model/test scaffold bootstrap. |
| `setup_model_regmap.py` | Generated Python CSR/regmap API from HJSON. |
| `setup_multiclock.py` | Multi-clock HJSON/RTL/model/TB scaffold generation. |
| `setup_tb.py` | SystemVerilog vector-testbench generation. |
| `setup_cocotb.py` | cocotb runner/scaffold generation and Verilator integration. |
| `coverage_report.py` | Coverage merge/report normalization, scope × type summary, detail output. |
| `setup_formal.py` | SymbiYosys CSR/property configs and EQY equivalence configuration. |
| `setup_sdc.py` | Single-clock timing-constraint generation. |
| `setup_syn.py` | Yosys synthesis-script generation. |
| `setup_signoff.py` | OpenSTA SDF, STA, and power-estimate script generation. |
| `setup_pnr.py` | OpenROAD-flow-scripts configuration generation. |
| `metrics.py` | Machine-readable run metrics and human `fx check` reporting. |
| `manifest.py` | Run identity/tool/version manifest collection. |
| `setup_fsoc.py` | FuseSoC core-file generation from ordered RTL. |
| `soc_cfg.py` | Resolve SoC host/device configuration. |
| `soc_start.py` | Stage reusable IP bundles into a SoC run. |
| `soc_gen.py` | SoC top RTL/FuseSoC/Verilator-wrapper generation. |
| `sw_soc_gen.py` | SoC C software scaffold generation. |
| `xbar_init.py` | OpenTitan-style crossbar configuration generation. |
| `__init__.py` | Backend package marker/documentation. |

Two non-Python files complete the backend surface:

| File | Responsibility |
| --- | --- |
| `Makefile` | Stable target vocabulary and orchestration entry point used by `fx`. |
| `deps.sh` | Shell-side dependency bootstrap/install helper used by the backend. |
| `toolchain.lock` | Reproducible external-tool revision/version contract. |

The intended layering is:

```text
fx CLI
  ↓
Make target                 stable, readable user surface
  ↓
Python backend flow         project semantics / generators / reporting
  ↓
EDA tool adapter            Slang / Verilator / Yosys / SBY / EQY / OpenSTA / ...
  ↓
executor                    local today; scheduler backends can sit below later
```

## 🪵 Logs and metadata

Logs are grouped by responsibility so failures are diagnosable without searching
the whole workspace. Cross-flow machine-readable state stays under `meta/`:

```text
meta/
├── manifest.json    # run identity and tool versions
└── metrics.json     # lint / DV / formal / equivalence / implementation closure
```

Neither logs nor metadata are a second source of design intent.
