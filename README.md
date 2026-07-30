<p align="center">
  <img src="assets/open-IP-SoC-logo.png" alt="FlexSoC — Open IP SoC" width="520"/>
</p>

# ⚡ FlexSoC

FlexSoC is an open-source **digital-design orchestration framework** for speeding
up ASIC IP and small-SoC development from one command-line interface: `fx`.

The value of FlexSoC is not one individual generator or EDA command. It is the
layer that keeps **specifications, RTL, generated collateral, verification,
filelists, constraints, logs, and external tools connected as the design
changes**.

A real hardware project rarely moves in a straight line. A register map changes,
a port is added, a block becomes multi-clock, a test exposes a bug, or an IP is
reused inside a larger SoC. Each change can invalidate several downstream
artifacts. FlexSoC gives those dependencies an explicit workflow so the designer
can regenerate what is derived, preserve what is authored, and rerun the right
checks without rebuilding the project flow by hand.

## 🚀 Why FlexSoC

Digital-design work spans several interfaces at once:

```text
specification
    ↓
register maps ──→ register RTL / docs / software-visible metadata
    ↓
RTL hierarchy ──→ ordered filelists ──→ lint / simulation / synthesis
    ↓
reference model ──→ reusable test vectors ──→ SV + cocotb
    ↓
constraints ──→ synthesis / SDF / STA / power / PnR
    ↓
validated IP ──→ reusable source block ──→ larger SoC/system
```

Without an orchestration layer, the interfaces between those stages become
project-specific shell scripts, copied filelists, duplicated register offsets,
stale generated files, and different assumptions in each tool. FlexSoC turns
those interfaces into named targets and explicit source/generated ownership.

The goal is simple: **spend time on architecture, RTL, verification, and design
trade-offs instead of repeatedly wiring tools and collateral together.**

> 💡 **FlexSoC is the glue layer:** open-source EDA tools stay visible and
> replaceable, while the project structure, generated collateral, and hand-authored
> design intent stay synchronized.

## 🧩 Core features

### 1. 🗂️ Reproducible run workspaces

A design run is isolated by `RUN_TOP` and `RUN_ID`, with a predictable tree for
register data, RTL, models, tests, simulation, synthesis, signoff, and logs.
The workspace can live in the repository or anywhere else with `--workdir`.

### 2. 🧾 Register-map-driven collateral

HJSON is the source of truth for software-visible registers. FlexSoC connects it
to:

- generated register RTL;
- register documentation;
- model-side CSR objects and field encoding;
- software driver generation where used;
- single- or multi-domain register maps.

A register change therefore does not require copying offsets and masks into the
model or tests. Regenerate the derived collateral instead.

### 3. 🧱 RTL scaffold and hierarchy management

FlexSoC can bootstrap editable RTL cores and wrappers for new IPs, refresh a
generated wrapper after port changes, and preserve deliberately custom RTL for
existing IPs.

The canonical `fx flist` flow uses **Slang** to elaborate downward from the
selected top, trim unreachable RTL, and topologically order the reachable
sources. FlexSoC then preserves the useful project split:

```text
rtl_common.f   # shared packages, primitives and TL-UL infrastructure
rtl_ip.f       # reachable IP/run hierarchy
```

Both are real command files, including the include paths required by downstream
tools.

### 4. 🔍 Selectable lint backend and focused diagnostics

Run the complete suite:

```bash
fx lint_suite
```

or choose the frontend without changing the project flow:

```bash
fx lint_suite --set LINT_TOOL=verilator
fx lint_suite --set LINT_TOOL=slang
```

Focused latch, width, unconnected, undriven, and unused diagnostics remain
available as separate targets. Tool output is retained under `logs/lint/` while
the terminal stays compact.

### 5. 🧠 Behavioral model, CSR API, and tests are separate

Single- and multi-clock model workspaces use the same ownership contract:

```text
dv/functional/model/
├── <top>_model.py   # editable behavioral/reference model
├── <top>_regmap.py  # generated from HJSON; do not hand-edit
└── <top>_tests.py   # editable scenarios + vector generation
```

This matters during development: tests can grow without changing the reference
model, and an HJSON-only change can refresh the CSR API without overwriting
behavioral code.

### 6. 🧪 Simulator-independent vector tests

Every generated scenario becomes explicit files:

```text
dv/functional/tests/<TEST_NAME>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

The same vectors are consumed by the generated SystemVerilog and cocotb
infrastructure. Tests can mix direct pins with CSR writes/reads. Single-clock
flows can check outputs at a fixed model latency or on a named output-valid
event; multi-clock flows can use event-driven completion across asynchronous
domains.

### 7. ⏱️ Single-clock and multi-clock development

`CLOCK_MODE=single` and `CLOCK_MODE=multi` keep the high-level command vocabulary
consistent while selecting the appropriate register, RTL, model, testbench, and
constraint behavior underneath.

### 8. 🏗️ Synthesis, timing, power, and PnR

The same run can continue into:

- Yosys synthesis;
- SDF generation;
- OpenSTA timing analysis and explicit global-activity power estimates;
- corner-oriented STA plus explicit `power_estimate` targets;
- OpenROAD-oriented PnR collateral and runs.

Logs are separated by responsibility:

```text
logs/
├── dv/functional/
├── lint/
├── synthesis/
└── signoff/
```

### 9. ♻️ Reusable existing IPs

`hw/ips/<top>/` is the versioned library of reusable IP source collateral.
Existing IP support is not a separate end goal: it lets a validated block keep
its custom RTL/model/tests, be regression-tested standalone, and then be staged
unchanged into a larger SoC or system.

This is the bridge from **IP development** to **IP reuse**.

### 10. 🔗 SoC composition

SoC runs stage reusable IPs, generate top-level integration collateral, build a
Slang-resolved SoC filelist, and own their own top-level verification,
constraints, software, and signoff assumptions.

### 11. 🧭 Analysis and debug utilities

Slang-backed analysis targets can inspect an arbitrary hierarchy from a top file
and search root:

```bash
fx slang_hier --set SLANG_TOP_FILE=/path/top.sv --set SLANG_ROOT=/path/rtl
fx slang_ast  --set SLANG_TOP_FILE=/path/top.sv --set SLANG_ROOT=/path/rtl
fx slang_flist --set SLANG_TOP_FILE=/path/top.sv --set SLANG_ROOT=/path/rtl
```

These complement the canonical flow without replacing its `rtl_common.f` /
`rtl_ip.f` outputs.

## 🔄 The development loop

FlexSoC is designed for iteration, not only first-time generation. For example,
if a project changes its register map:

```text
edit <top>.hjson
    │
    ├── fx reg doc --force
    │      ├── register RTL
    │      └── register documentation
    │
    ├── fx regmap_py --force
    │      └── <top>_regmap.py
    │
    ├── adapt RTL/model/tests only if semantics changed
    │
    ├── fx tests_gen --force
    │      └── regenerated vector tests
    │
    ├── fx flist --force
    ├── fx lint_suite
    ├── fx sim_tests
    ├── fx cocotb_tests
    └── fx syn sdf sta power_estimate --force   # when implementation/signoff must be rechecked
```

The important distinction is between **authored source** and **derived
collateral**. FlexSoC makes that boundary explicit so a local change does not
require blindly regenerating everything or accidentally overwriting custom
work.

See [Project lifecycle and change propagation](docs/project_lifecycle.md) for
concrete change scenarios such as register-map edits, port changes, behavioral
changes, and IP-to-SoC reuse.

## 🛠️ Open-source toolchain integration

FlexSoC orchestrates open-source tools rather than hiding them behind a closed
flow. Depending on the target, the current backend integrates tools including:

- **Slang** for hierarchy elaboration, dependency/filelist generation, AST and
  hierarchy analysis, and optionally lint;
- **Verilator** for lint and SystemVerilog simulation;
- **cocotb** for Python-driven verification over the same generated vectors;
- **lowRISC reggen** for HJSON register collateral;
- **Yosys** and its Slang frontend for synthesis;
- **sv2v** where Verilog conversion is useful;
- **OpenSTA** for static timing and global-activity power estimates;
- **OpenROAD** for physical-design-oriented flows.

FlexSoC's job is to keep the project representation and assumptions consistent
between those tools.

## 📦 Install

```bash
uv sync
source .venv/bin/activate
fx --help
fx commands
```

## 🚀 Quick single-clock example

```bash
fx settings TOP=test RUN_TOP=test RUN_ID=dev HOST=uart CLOCK_MODE=single

fx setup --force
fx hjson --force
fx reg doc --force
fx rtl_stub --force
fx top_from_core --force

fx flist --force
fx lint_suite

fx setup_model --force
fx tests_gen --force
fx setup_tb --force
fx setup_cocotb --force
fx sim_tests
fx cocotb_tests

fx syn sdf sta power_estimate --force
```

`setup_model --force` is a bootstrap/reset operation. Once `<top>_model.py` and
`<top>_tests.py` contain authored work, use selective regeneration such as
`regmap_py --force` for HJSON-only changes instead of resetting the whole model
workspace.

## ♻️ Existing IP and reuse

A reusable IP lives under:

```text
hw/ips/<top>/
```

For standalone regression it is copied into an isolated run with `fx ip_load`.
The standard existing-IP flow intentionally preserves source-owned HJSON, custom
RTL/top, behavioral model, and tests while regenerating explicitly derived
collateral such as register RTL/docs, filelists, and `<top>_regmap.py`.

When `RUN_TOP` is a larger SoC, the same source IP can be staged under that SoC
run instead of replacing the run itself. See
[Existing IP development](docs/guide_existing_ip_dev.md) and
[SoC development](docs/guide_soc_dev.md).

## 🗂️ Project layout

A run normally looks like:

```text
<WORKDIR>/runs/<RUN_TOP>/<RUN_ID>/
├── data/          # HJSON register specifications
├── doc/           # generated register documentation
├── dv/            # functional/formal design verification collateral
├── rtl/           # RTL implementation and Slang-ordered filelists
├── logs/          # lint / DV / synthesis / signoff
├── syn/           # synthesis collateral/results
├── signoff/       # SDF / STA / power collateral
└── pnr_openroad/  # physical-design collateral
```

See [Folder structure and ownership](docs/folder_structure.md) for the full
source-versus-generated contract.

## 📚 Documentation

Read the docs by intent:

- [Quickstart](docs/quickstart.md) — shortest runnable paths.
- [Project lifecycle and change propagation](docs/project_lifecycle.md) — how
  changes propagate and which targets to rerun.
- [Single-clock IP development](docs/guide_ip_dev.md) — detailed generated-IP
  workflow.
- [Existing IP development](docs/guide_existing_ip_dev.md) — preserve and
  regression-test reusable source IPs.
- [Multi-clock IP development](docs/guide_multiclock_ip_dev.md) — domain-specific
  register, verification, and timing behavior.
- [SoC development](docs/guide_soc_dev.md) — reuse validated IPs in larger
  systems.
- [Folder structure and ownership](docs/folder_structure.md) — where source,
  generated collateral, logs, and run outputs belong.

## 🧪 End-to-end regression

Run the real command/tool regression:

```bash
pytest -s tests/test_e2e_fx.py
```

Skip synthesis/signoff while iterating on frontend or verification changes:

```bash
pytest -s tests/test_e2e_fx.py --no-signoff
```

Use another E2E workspace base when needed:

```bash
pytest -s tests/test_e2e_fx.py --e2e-root ~/flexsoc-e2e
```

or:

```bash
FLEXSOC_E2E_ROOT=~/flexsoc-e2e pytest -s tests/test_e2e_fx.py
```

Successful temporary workspaces are removed automatically. Failed workspaces
are retained for debugging.
