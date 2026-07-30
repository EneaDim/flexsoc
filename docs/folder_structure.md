# FlexSoC folder structure

FlexSoC separates reusable design sources from run outputs. Design verification
collateral lives under `dv/`; static structural analysis lives under `analysis/`.

## Reusable IP

```text
hw/ips/<top>/
├── data/                 # HJSON and other design source metadata
├── doc/                  # retained documentation
├── rtl/                  # reusable RTL
├── dv/
│   ├── functional/
│   │   ├── model/        # reference model, generated regmap API, test catalogue
│   │   ├── tests/        # retained vector tests when intentionally saved
│   │   ├── tb/           # retained SV/cocotb testbench collateral
│   │   └── sim/
│   │       └── rtl/      # retained simulation configuration such as .gtkw
│   └── formal/
│       └── properties/   # authored formal properties when present
├── syn/                  # retained synthesis collateral
├── signoff/              # retained signoff collateral
├── pnr_openroad/         # retained implementation configuration/results
└── qualification/        # future selected release evidence
```

Run-only databases are not reusable IP sources. Coverage databases, simulator
scratch, generated proof traces, transient waveforms, `results.xml`, and Python
cache files therefore stay out of `hw/ips/<top>/`.

## Run workspace

```text
workspace/runs/<top>/<run_id>/
├── data/
├── doc/
├── rtl/
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
│   │   │   └── post_layout/        # created only when that flow exists
│   │   ├── coverage/
│   │   │   ├── sv/
│   │   │   ├── cocotb/
│   │   │   ├── merged.dat
│   │   │   ├── summary.txt
│   │   │   └── annotated/
│   │   └── saved/                  # intentionally saved functional artifacts
│   └── formal/                     # created only by formal flows
│       ├── csr/
│       │   ├── generated/
│       │   ├── prove/
│       │   └── cover/
│       ├── properties/
│       │   ├── prove/
│       │   └── cover/
│       └── equivalence/
│           └── rtl_vs_syn/
├── analysis/
│   ├── slang/
│   ├── cdc/                        # future structural CDC analysis
│   └── rdc/                        # future structural RDC analysis
├── syn/
├── signoff/
├── pnr_openroad/
├── logs/
│   ├── dv/functional/
│   ├── lint/
│   ├── synthesis/
│   └── signoff/
└── meta/
    ├── manifest.json
    └── metrics.json
```

Directories that belong to future flows are not created as empty placeholders.
For example `dv/formal/`, `sim/post_layout/`, `analysis/cdc/`, and
`analysis/rdc/` appear only after the corresponding flow runs.

## Functional verification ownership

The functional branch separates four different concepts:

- `model/` describes expected behavior and test intent;
- `tests/` contains concrete generated or retained test vectors;
- `tb/` contains the machinery that drives and observes the DUT;
- `sim/` contains simulator outputs for a specific representation of the DUT.

RTL, post-synthesis, and post-layout simulations therefore share the same test
intent and testbench structure while keeping their scratch/results separate.

## Formal verification ownership

Formal verification is separate from functional simulation:

- `formal/csr/` is generated from register semantics;
- `formal/properties/` is for authored design properties;
- `formal/equivalence/` contains RTL/netlist equivalence runs.

Formal `prove` results and formal `cover` reachability are not numerically merged
with simulation code coverage. They are separate verification-closure signals.

## Static analysis

`analysis/` is not under `dv/`. Slang hierarchy/AST, CDC, and RDC consume static
or structural representations rather than functional stimulus or formal proof
runs. Keeping them separate makes that boundary explicit.

## Generated model and tests

`fx setup_model` creates:

```text
dv/functional/model/
├── <top>_model.py
├── <top>_regmap.py
└── <top>_tests.py
```

`<top>_model.py` and `<top>_tests.py` become authored collateral once customized.
`<top>_regmap.py` remains derived from HJSON and is refreshed with:

```bash
fx regmap_py --force
```

`fx tests_gen` materializes the test catalogue under:

```text
dv/functional/tests/<TEST_NAME>/
```

## Generated testbenches

SystemVerilog collateral lives in:

```text
dv/functional/tb/sv/
```

and cocotb collateral in:

```text
dv/functional/tb/cocotb/
```

Both consume the same `dv/functional/tests/<TEST_NAME>/` vectors.

## Regression and coverage

`fx regression` runs the complete generated test catalogue on the selected
functional backends. Verilator coverage is collected under:

```text
dv/functional/coverage/
```

Use:

```bash
fx coverage
fx coverage_detail
```

for the summary and uncovered-point views respectively. Coverage databases are
run artifacts and are never copied into reusable IP sources by `fx ip_save`.

## Logs and metadata

Tool logs stay under `logs/` so every flow has one predictable diagnostic root.
Cross-flow machine-readable run state stays under `meta/`:

```text
meta/
├── manifest.json
└── metrics.json
```

Neither directory is a second source of design intent.
