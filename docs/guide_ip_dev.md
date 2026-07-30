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
model/
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
tb/tests/<TEST_NAME>/
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
fx setup_tb --force
fx setup_cocotb --force
```

These targets generate transport/infrastructure only. They do not own expected
behavior; SystemVerilog and cocotb both consume the same vector-test directories.

## 11. ✅ Run verification

One test:

```bash
fx sim --set TEST_NAME=smoke
fx cocotb --set TEST_NAME=smoke
```

All generated tests:

```bash
fx sim_tests
fx cocotb_tests
```

Waveforms:

```bash
fx view --set TEST_NAME=smoke
fx view_cocotb --set TEST_NAME=smoke
```

Verification logs live under `logs/verification/`.

## 12. 🔄 Iterate after changes

### 🧾 HJSON-only structural change

```bash
fx reg doc --force
fx regmap_py --force
fx tests_gen --force
fx flist --force
fx lint_suite
fx sim_tests
fx cocotb_tests
```

Do not reset `<top>_model.py` or `<top>_tests.py` unless their behavior must
actually change.

### 🛠️ RTL implementation change

Usually:

```bash
fx flist --force      # when hierarchy/dependencies changed
fx lint_suite
fx tests_gen --force  # when expected behavior/scenarios changed
fx sim_tests
fx cocotb_tests
```

### 🔌 Port/interface change

Refresh the generated wrapper only if it is still flow-owned, update model/test
code, regenerate TB infrastructure, then rerun lint and verification.

For a larger propagation matrix, see
[Project lifecycle and change propagation](project_lifecycle.md).

## 13. 🏗️ Synthesis and signoff

```bash
fx syn sdf sta power_estimate --force
```

Synthesis logs are under `logs/synthesis/`; SDF/STA/power-estimate logs are under
`logs/signoff/`.

`power_estimate` is intentionally a heuristic estimate, not workload-driven power.
It applies a global switching activity (`POWER_ACTIVITY=0.1` transitions per clock
cycle) and duty (`POWER_DUTY=0.5`) unless overridden with `--set`.

Use `--live` when full tool output is useful in the terminal:

```bash
fx syn sdf sta power_estimate --force --live
```

## 14. 🧪 E2E regression

```bash
pytest -s tests/test_e2e_fx.py::test_fx_full_flow_debug --no-signoff
```

Include synthesis/signoff by removing `--no-signoff`. E2E workspaces default to
`/tmp`, or select another base with:

```bash
pytest -s tests/test_e2e_fx.py --e2e-root ~/flexsoc-e2e
```
