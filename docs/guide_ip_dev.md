# 🧱 Single-clock IP development guide

This guide covers a new IP whose initial register, RTL, model, and verification
scaffolds are created by FlexSoC. The important idea is not to regenerate
blindly: bootstrap once, then propagate later design changes only through the
derived artifacts that depend on them.

For the change-oriented view, see
[Project lifecycle and change propagation](project_lifecycle.md). For a mature
block already stored under `hw/ips/`, use
[Existing IP development](guide_existing_ip_dev.md).

## 1. ⚙️ Configure the run

```bash
fx settings TOP=test RUN_TOP=test RUN_ID=dev HOST=uart CLOCK_MODE=single
```

`TOP` is the selected design top. `RUN_TOP` identifies the run owner and becomes
important when an IP is later staged inside a larger SoC run.

## 2. 🧾 Create the run and register specification

```bash
fx setup --force
fx hjson --force
```

Edit:

```text
workspace/runs/test/dev/data/test.hjson
```

Generate the derived register RTL and documentation:

```bash
fx reg doc --force
```

The HJSON file is the source of truth for software-visible register structure.
Register offsets, fields, masks, access modes, and reset values should not be
copied manually into model/test code.

## 3. 🛠️ Create and edit the RTL

```bash
fx rtl_stub --force
```

The run now contains an editable RTL core and a generated top wrapper. Edit the
implementation. If the core port list changes while the wrapper is still
generated collateral, refresh it with:

```bash
fx top_from_core --force
```

Once a wrapper contains deliberate adaptation/integration logic, treat it as
authored source and stop regenerating it. That is the ownership model used by
existing IPs.

## 4. 🧭 Resolve the hierarchy and generate canonical filelists

```bash
fx flist --force
```

FlexSoC uses Slang to elaborate downward from `<top>.sv`, load reachable
dependencies, trim unrelated RTL, and topologically order the closure. It emits:

```text
rtl/rtl_common.f
rtl/rtl_ip.f
```

`rtl_common.f` contains shared FlexSoC packages/primitives/TL-UL infrastructure.
`rtl_ip.f` contains the reachable run/IP hierarchy. Include paths required by
downstream tools are carried in the command files.

This pair is the project representation consumed by lint, simulation, and
synthesis.

## 5. 🔍 Lint

Run the complete diagnostic suite:

```bash
fx lint_suite
```

Select the lint frontend without changing the flow:

```bash
fx lint_suite --set LINT_TOOL=verilator
fx lint_suite --set LINT_TOOL=slang
```

Focused checks remain available:

```bash
fx lint
fx lint_latch
fx lint_width
fx lint_unconnected
fx lint_undriven
fx lint_unused
```

Detailed logs live under `logs/lint/`.

### 🧠 Slang analysis outside the canonical flow

For hierarchy/AST/filelist exploration from an arbitrary source tree:

```bash
fx slang_hier \
  --set SLANG_TOP_FILE=/path/to/rtl/top.sv \
  --set SLANG_ROOT=/path/to/rtl

fx slang_ast \
  --set SLANG_TOP_FILE=/path/to/rtl/top.sv \
  --set SLANG_ROOT=/path/to/rtl

fx slang_flist \
  --set SLANG_TOP_FILE=/path/to/rtl/top.sv \
  --set SLANG_ROOT=/path/to/rtl
```

`slang_ast` writes native Slang AST JSON under `analysis/slang/`.
`slang_flist` writes a portable single command file at `rtl/rtl_slang.f`.
These are analysis/debug utilities; the normal flow still consumes
`rtl_common.f` and `rtl_ip.f` from `fx flist`.

## 6. 🧠 Bootstrap the model/test workspace

```bash
fx setup_model --force
```

This creates the canonical three-file split:

```text
dv/functional/model/
├── test_model.py
├── test_regmap.py
└── test_tests.py
```

Ownership is strict:

- `test_model.py` is editable behavioral/reference-model code;
- `test_regmap.py` is generated from HJSON and should not be hand-edited;
- `test_tests.py` is editable scenario/vector-generation code.

`setup_model --force` intentionally rewrites all three files. Use it for initial
bootstrap or an intentional scaffold reset, not for routine iteration after the
model/tests contain authored work.

## 7. 🧾 Use the generated CSR API

A single-clock test catalogue can import:

```python
import test_regmap as regmap

CSR = regmap.PRIMARY
```

Each HJSON register is a generated object:

```python
CSR.CTRL(EN=1)
CSR.CTRL.write(EN=1)
CSR.CTRL.vector_write(8, EN=1)
CSR.STATUS.vector_read(32, BUSY=0, VALID=1)
```

For multiple register domains:

```python
regmap.domain("domain_name")
```

The generated API owns register/domain names, offsets, fields, reset values,
access properties, masks, and vector/config serialization.

## 8. ⏱️ Model behavior and test timing

`<top>_model.py` owns what one transaction means. `<top>_tests.py` owns how that
behavior is stimulated and checked.

A simple single-clock pipeline can expose:

```python
LATENCY = 2
```

and tests can check an expected output at:

```text
drive_cycle + LATENCY
```

When the output latency is variable or protocol-driven, tests can instead use a
named output-valid signal and check data only when that signal asserts.

This keeps timing policy in the test layer while the behavioral model stays a
reference for the transaction itself.

## 9. 🧪 Generate vector tests

Generate all scenarios:

```bash
fx tests_gen --force
```

Generate one:

```bash
fx test_gen --set TEST_NAME=my_case
```

List them:

```bash
fx tests
```

Each scenario becomes:

```text
dv/functional/tests/<TEST_NAME>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

The test catalogue can mix:

- direct DUT input drives;
- direct DUT output checks;
- CSR `@write` operations;
- CSR `@read` expectations.

A mixed-interface IP can therefore configure control/status through CSRs while
stimulating protocol pins directly. A CSR-only IP can leave direct functional
vectors empty.

## 10. 🧰 Generate verification infrastructure

```bash
fx setup_tb setup_cocotb --force
```

These targets generate execution infrastructure only. Expected behavior remains
owned by `<top>_model.py` and `<top>_tests.py`; both SystemVerilog and cocotb
consume the same materialized vectors.

Regenerate the TB infrastructure after a DUT port change. A pure behavioral
change normally needs new vectors, not a new testbench scaffold.

## 11. ✅ Functional verification and coverage

Run one selected test while debugging:

```bash
fx sim --set TEST_NAME=smoke
fx cocotb --set TEST_NAME=smoke
```

For normal closure, use the complete generated catalogue:

```bash
fx regression
fx coverage_detail
```

`regression` runs every generated scenario on the selected SystemVerilog and
cocotb backends and merges Verilator coverage. The main report is intentionally
read as a matrix:

```text
Scope          line   toggle   expr   branch   fsm   user   total
design          ...     ...     ...      ...    ...    ...     ...
registers       ...     ...     ...      ...    ...    ...     ...
common          ...     ...     ...      ...    ...    ...     ...
other           ...     ...     ...      ...    ...    ...     ...
all             ...     ...     ...      ...    ...    ...     ...
```

The scopes answer **where** coverage came from; the columns answer **what type**
of structural/code coverage Verilator measured. `coverage_detail` keeps the
uncovered authored-RTL points available for inspection rather than reducing the
run to one global percentage.

Waveforms remain available when debugging individual tests:

```bash
fx view --set TEST_NAME=smoke
fx view_cocotb --set TEST_NAME=smoke
```

Functional logs live under `logs/dv/functional/`.

## 12. 🧠 Formal verification

Functional regression and code coverage do not replace proof. FlexSoC keeps
formal closure under `dv/formal/` and divides it into two sources of intent.

### 🧾 Automatic CSR semantics

CSR formal collateral is generated from the register implementation semantics.
The generated SystemVerilog binds checker modules onto the reggen primitives
(`prim_subreg`, `prim_subreg_arb`, `prim_subreg_ext`) instead of modifying the
DUT RTL.

The two generated intents are deliberately different:

- **assertions** check register update/reset/write-enable/data semantics and are
  used by BMC/PROVE;
- **cover statements** ask whether software-writable register activity is
  reachable and are used by COVER.

```text
BMC   → shallow assertion checking / counterexample search
PROVE → proof of the generated + authored assertions
COVER → reachability of generated + authored cover goals
```

So a generated `bind` is only the attachment mechanism. Whether the attached
property is a proof obligation or a reachability goal depends on whether that
formal source contains `assert` or `cover`.

### ✍️ Authored design properties

Design-specific assertions and covers belong under the formal properties branch
and are kept separate from generated CSR checks.

Run the complete formal stage with:

```bash
fx formal
```

or individual stages while debugging:

```bash
fx formal_csr_bmc
fx formal_csr_prove
fx formal_csr_cover
fx formal_bmc
fx formal_prove
fx formal_cover
```

Formal status is **not** added to Verilator coverage percentages. It is a
separate closure axis in `metrics.json` / `fx check`.

## 13. 🔄 Iterate after changes

### 🧾 HJSON / register-map change

```bash
fx reg doc --force
fx regmap_py --force
fx tests_gen --force
fx flist --force
fx lint_suite
fx regression
fx coverage_detail
fx formal
```

The formal rerun matters because automatic CSR assertions/covers are derived
from the same register semantics as the RTL and Python regmap API.

Do not reset `<top>_model.py` or `<top>_tests.py` unless their authored behavior
actually needs to change.

### 🛠️ RTL behavior change

```bash
fx flist --force      # when hierarchy/dependencies changed
fx lint_suite
fx tests_gen --force  # when expected behavior/scenarios changed
fx regression
fx coverage_detail
fx formal
```

If the RTL changed, synthesis and EQY closure are stale even when regression is
still green.

### 🔌 Port/interface change

A port edit has a wider blast radius:

```text
core port list
  ├── generated wrapper, if still flow-owned
  ├── model/test transaction shape
  ├── SV/cocotb testbench wiring
  ├── authored formal signal references/binds
  └── constraints, when clock/reset/I/O timing changed
```

Typical propagation:

```bash
fx top_from_core --force      # only if wrapper is still generated
fx tests_gen --force
fx setup_tb setup_cocotb --force
fx flist --force
fx lint_suite
fx regression
fx formal
```

For the complete change-impact matrix, see
[Project lifecycle and change propagation](project_lifecycle.md).

## 14. 🏗️ Synthesis and RTL ↔ synthesis equivalence

Synthesize first:

```bash
fx syn --force
```

Then prove that the mapped netlist still represents the RTL behavior:

```bash
fx equiv --force
```

`fx equiv` uses EQY and reports closure by partition. The useful result is not a
single boolean only; FlexSoC keeps apart:

- proven partitions and percentage;
- real failed partitions;
- solver/engine errors;
- timeouts;
- unknown/incomplete partitions.

This distinction is especially useful when a solver cannot close one partition:
a partial EQY percentage is not the same thing as a demonstrated functional
mismatch.

Synthesis logs live under `logs/synthesis/`; EQY logs/results live under the
formal equivalence branch.

## 15. 📐 SDF, STA, power, and implementation signoff

After synthesis/equivalence:

```bash
fx sdf sta power_estimate --force
```

`power_estimate` is intentionally a heuristic estimate, not workload-driven
power. It applies global switching activity (`POWER_ACTIVITY=0.1` transitions
per clock cycle) and duty (`POWER_DUTY=0.5`) unless overridden with `--set`.

The current implementation/signoff chain is therefore:

```text
RTL
 ↓
synthesis
 ↓
EQY equivalence
 ↓
SDF / post-synthesis representation
 ↓
STA + power
 ↓
PnR / post-layout closure as the physical flow is extended
```

Use `--live` when full tool output is useful:

```bash
fx formal --live
fx syn equiv sdf sta power_estimate --force --live
```

## 16. 📊 Consolidated run status

After the closure stages:

```bash
fx manifest metrics check --force
```

The reporting intentionally keeps separate:

```text
functional regression + code coverage
formal BMC / PROVE / COVER
EQY partition closure
synthesis statistics
SDF / STA / power
```

That gives one project status without pretending that all verification evidence
has the same semantics.

## 17. 🧪 E2E regression

Run the complete single-clock project path with:

```bash
make test E2E_ROOT=work
```

or directly:

```bash
pytest -s tests/test_e2e_fx.py --e2e-root work
```

Use `--no-signoff` while iterating on frontend/DV-only changes. With signoff
enabled, the single-clock E2E continues through formal, synthesis, EQY, SDF,
STA, power, and metrics.
