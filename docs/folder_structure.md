# 🗂️ FlexSoC folder structure

FlexSoC separates **reusable source**, **logical run state**, and
**technology-dependent implementation results**. The PDK name appears only at
the leaf where an artifact actually depends on that technology.

> 🔑 **Rule:** describe the flow first, then the PDK. Use `syn/sky130`, not
> `tech/sky130/syn`.

## 1. 📚 Reusable IP source

```text
hw/ips/<top>/
├── data/                 # HJSON and source metadata
├── doc/                  # retained documentation
├── rtl/                  # reusable RTL
├── dv/
│   ├── functional/       # retained model/tests/TB when intentionally saved
│   └── formal/           # authored assertions/covers
├── syn/                  # optional retained synthesis collateral
├── signoff/              # optional retained sign-off collateral
├── pnr_openroad/         # optional retained physical-design collateral
└── qualification/        # future selected release evidence
```

Run-only databases, waveforms, coverage databases, proof traces, simulator
scratch and temporary tool outputs do not belong in reusable IP source.

## 2. 🧪 Generated run workspace

One logical run is selected by `RUN_TOP` and `RUN_ID`:

```text
<WORKDIR>/runs/<RUN_TOP>/<RUN_ID>/
├── data/
├── doc/
├── rtl/
├── constraints/
├── lint/
├── dv/
│   ├── functional/
│   │   ├── model/
│   │   ├── tests/
│   │   ├── tb/
│   │   ├── sim/
│   │   │   ├── rtl/
│   │   │   ├── post_syn/
│   │   │   │   ├── ihp-sg13g2/
│   │   │   │   └── sky130/
│   │   │   └── post_pnr/
│   │   │       ├── ihp-sg13g2/
│   │   │       └── sky130/
│   │   └── coverage/
│   └── formal/
│       ├── csr/
│       ├── properties/
│       └── runs/
├── analysis/
│   ├── slang/
│   ├── cdc/                         # planned
│   └── rdc/                         # planned
├── syn/
│   ├── ihp-sg13g2/
│   └── sky130/
├── pnr_openroad/
│   ├── ihp-sg13g2/
│   └── sky130/
├── signoff/
│   ├── equivalence/
│   │   ├── ihp-sg13g2/rtl_vs_syn/
│   │   └── sky130/rtl_vs_syn/
│   ├── sta/
│   │   ├── ihp-sg13g2/
│   │   └── sky130/
│   ├── power/
│   │   ├── ihp-sg13g2/
│   │   └── sky130/
│   └── sdf/
│       ├── ihp-sg13g2/
│       └── sky130/
├── logs/
│   ├── dv/                           # shared RTL/property-formal logs
│   ├── synthesis/<pdk>/
│   ├── pnr/<pdk>/
│   └── signoff/
│       ├── equivalence/<pdk>/
│       ├── sta/<pdk>/
│       ├── power/<pdk>/
│       └── sdf/<pdk>/
└── meta/
    ├── ihp-sg13g2/
    │   ├── manifest.json
    │   └── metrics.json
    └── sky130/
        ├── manifest.json
        └── metrics.json
```

The hierarchy answers two different questions in a stable order:

1. **What flow produced this artifact?** `syn`, `equivalence`, `sta`, `power`, …
2. **Which PDK produced this implementation?** `sky130`, `ihp-sg13g2`, …

There is deliberately no parallel `tech/<pdk>/...` tree.

## 3. 🟠 Functional DV ownership

```text
dv/functional/
├── model/       # expected behavior + generated CSR API + test catalogue
├── tests/       # materialized simulator-independent vectors
├── tb/          # SystemVerilog and cocotb infrastructure
├── sim/
│   ├── rtl/             # PDK-independent RTL simulation
│   ├── post_syn/<pdk>/  # mapped-netlist GLS
│   └── post_pnr/<pdk>/  # final-netlist/SDF GLS
└── coverage/    # Verilator line/toggle/expr/branch/FSM/user coverage
```

`fx regression` and RTL coverage never consume a PDK. Only gate-level
simulation leaves are technology dependent.

See [Design verification](design_verification.md).

## 4. 🧠 Property-formal ownership

```text
dv/formal/
├── csr/          # generated CSR semantic assertions/covers
├── properties/   # authored design assertions/covers
└── runs/          # BMC / PROVE / COVER workdirs
```

This branch is PDK-independent. RTL ↔ mapped-netlist equivalence is **not**
stored here; it belongs to `signoff/equivalence/<pdk>/`.

## 5. ✅ Sign-off ownership

```text
signoff/
├── equivalence/<pdk>/rtl_vs_syn/
├── sta/<pdk>/
├── power/<pdk>/
└── sdf/<pdk>/
```

- `equivalence` owns EQY configuration, partitions, strategies and traces;
- `sta` owns OpenSTA timing scripts/reports;
- `power` owns power-estimate scripts/reports;
- `sdf` owns SDF generation and timing files.

See [Design sign-off](design_signoff.md).

## 6. 🏗️ Synthesis and PnR ownership

Mapped synthesis:

```text
syn/<pdk>/
├── synth*.ys
├── <top>_synth.v
└── plots/
```

OpenROAD:

```text
pnr_openroad/<pdk>/
├── config.mk
├── results/
├── objects/
└── reports/
```

Changing the active PDK selects a different local subdirectory; it never
requires copying or archiving the previous implementation.

## 7. 📐 Constraints

Logical clock/timing intent is kept once per run:

```text
constraints/
└── <top>.sdc
```

The selected synthesis/sign-off/PnR implementation consumes these constraints.
PDK-specific derived timing results remain under the corresponding PDK leaf.

## 8. 🧠 Generated model and tests

`fx setup_model` creates:

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
`dv/functional/tests/<TEST_NAME>/`.

## 9. 🧰 Backend implementation map

`src/flexsoc/backend/` contains the implementation behind the stable `fx` / Make
target surface.

| File | Responsibility |
| --- | --- |
| `common.py` | Shared filesystem, source-ordering and backend helpers. |
| `hjson_gen.py` | Starter HJSON/register specification generation. |
| `driver_gen.py` | Software-driver helpers derived from register metadata. |
| `rtl_stub_gen.py` | Starter RTL core and wrapper generation. |
| `top_from_core.py` | Refresh a generated top wrapper after core-port changes. |
| `slang_tools.py` | Slang hierarchy, AST, reachability and ordered filelists. |
| `setup_model.py` | Single-clock behavioral model/test scaffold bootstrap. |
| `setup_model_regmap.py` | Generated Python CSR/regmap API from HJSON. |
| `setup_multiclock.py` | Multi-clock HJSON/RTL/model/TB scaffold generation. |
| `setup_tb.py` | SystemVerilog vector-testbench generation. |
| `setup_cocotb.py` | cocotb scaffold and Verilator integration. |
| `coverage_report.py` | Coverage merge, normalization and scope × type reporting. |
| `setup_formal.py` | PDK-independent SymbiYosys CSR/property BMC/PROVE/COVER configs. |
| `setup_sdc.py` | Logical timing-constraint generation. |
| `setup_syn.py` | Yosys mapped-synthesis script generation. |
| `setup_signoff.py` | EQY equivalence plus OpenSTA STA/SDF/power configuration. |
| `post_sim.py` | PDK-scoped post-synthesis/post-PnR Icarus GLS orchestration. |
| `eqy_debug.py` | EQY result scanning, trace analysis, reset-state probe, and waveform sessions. |
| `setup_pnr.py` | OpenROAD-flow-scripts configuration generation. |
| `metrics.py` | Shared DV + selected-PDK implementation closure metrics. |
| `manifest.py` | Run/tool/PDK identity manifest. |
| `setup_fsoc.py` | FuseSoC core generation from ordered RTL. |
| `soc_cfg.py` | Resolve SoC host/device configuration. |
| `soc_start.py` | Stage reusable IP bundles into a SoC run. |
| `soc_gen.py` | SoC top RTL/FuseSoC/Verilator-wrapper generation. |
| `sw_soc_gen.py` | SoC C software scaffold generation. |
| `xbar_init.py` | OpenTitan-style crossbar configuration generation. |
| `__init__.py` | Backend package marker/documentation. |

Non-Python backend surface:

| File | Responsibility |
| --- | --- |
| `Makefile` | Stable target vocabulary and orchestration entry point used by `fx`. |
| `deps.sh` | Dependency bootstrap/install helper. |
| `toolchain.lock` | Reproducible external-tool revision/version contract. |

The intended layering is:

```text
fx CLI
  ↓
Make target                 stable user-facing vocabulary
  ↓
Python backend flow         orchestration / project semantics
  ↓
EDA tool adapter            Slang / Verilator / Yosys / SBY / EQY / OpenSTA / ...
  ↓
executor                    local today; scheduler backend later
```

## 10. 🪵 Logs and metadata

PDK-independent logs stay shared. Technology-dependent logs put the flow first
and PDK second:

```text
logs/
├── dv/...
├── synthesis/<pdk>/
├── pnr/<pdk>/
└── signoff/
    ├── equivalence/<pdk>/
    ├── sta/<pdk>/
    ├── power/<pdk>/
    └── sdf/<pdk>/
```

Machine-readable closure is similarly scoped:

```text
meta/<pdk>/
├── manifest.json
└── metrics.json
```

Neither logs nor metadata are a source of design intent.
