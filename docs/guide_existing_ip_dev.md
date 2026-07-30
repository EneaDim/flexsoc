# ♻️ Existing IP development and reuse guide

An existing IP is a **reusable, versioned source block** stored under:

```text
hw/ips/<top>/
```

The purpose of this flow is not to regenerate a mature IP from scratch. It is to
preserve its authored implementation/model/tests, regression-test it with the
same open-source flow, and make it easy to stage into a larger SoC or system.

## 1. 📚 Source library versus run copy

The versioned source lives under `hw/ips/<top>/`. `ip_load` copies it into an
isolated run:

```text
hw/ips/<top>/
        │
        └── fx ip_load
              ↓
<WORKDIR>/runs/<RUN_TOP>/<RUN_ID>/
```

The run is disposable working state. The source IP is the reusable artifact.

When `RUN_TOP == TOP`, the IP is being regression-tested standalone. When a
larger `RUN_TOP` owns the run, the IP can be staged below that system instead of
replacing the system run.

## 2. ⚙️ Configure and load standalone

UART example:

```bash
fx settings TOP=uart RUN_TOP=uart RUN_ID=dev HOST=uart CLOCK_MODE=single
fx setup --force
fx ip_load --force
```

CORDIC example:

```bash
fx settings TOP=cordic RUN_TOP=cordic RUN_ID=dev HOST=uart CLOCK_MODE=single
fx setup --force
fx ip_load --force
```

## 3. 🛡️ Preserve source-owned collateral

The standard existing-IP regression does **not** run:

```text
hjson
rtl_stub
top_from_core
setup_model
```

Those commands can overwrite authored intent.

An existing IP may deliberately own:

- its HJSON register specification;
- hand-written/custom RTL organization;
- a custom top wrapper;
- `<top>_model.py`;
- `<top>_tests.py`;
- IP-specific verification and implementation collateral.

Regenerate one of those only when replacement is intentional.

## 4. 🧾 Regenerate register-derived collateral

HJSON remains the register-map source of truth. In the loaded run:

```bash
fx reg doc --force
fx regmap_py --force
```

This refreshes derived register RTL/docs and:

```text
model/<top>_regmap.py
```

while preserving:

```text
model/<top>_model.py
model/<top>_tests.py
```

Model/test code should obtain register names, fields, masks, access modes, and
serialization from `<top>_regmap.py` rather than hardcoding HJSON layout.

## 5. 🧭 Resolve the loaded hierarchy

```bash
fx flist --force
```

Slang elaborates the loaded top, trims unreachable sources, and regenerates:

```text
rtl/rtl_common.f
rtl/rtl_ip.f
```

Shared FlexSoC infrastructure stays in the common file; the reachable IP/run
hierarchy stays in the IP file. Downstream lint/simulation/synthesis all consume
this same representation.

## 6. 🔍 Lint

```bash
fx lint_suite
```

Choose the frontend if needed:

```bash
fx lint_suite --set LINT_TOOL=verilator
fx lint_suite --set LINT_TOOL=slang
```

Focused diagnostics are still available individually.

## 7. 🧪 Verification patterns

### 📡 Mixed pins + CSR: UART

A reusable UART can configure/control itself through CSRs while serial traffic
uses functional pins. Its test catalogue can therefore combine rows such as:

```python
import uart_regmap as regmap

CSR = regmap.PRIMARY

rows_in = [
    drive(0, "cio_rx_i", 1),
    CSR.WDATA.vector_write(8, WDATA=0x5A),
]

rows_out = [
    check(16, "cio_tx_o", 1),
    CSR.STATUS.vector_read(400, TXIDLE=1, RXIDLE=1),
]
```

### 🧮 CSR-only: CORDIC

A CSR-driven block can express the entire transaction through generated register
objects:

```python
import cordic_regmap as regmap

CSR = regmap.PRIMARY

CSR.X_IN.vector_write(cycle, VALUE=x)
CSR.Y_IN.vector_write(cycle, VALUE=y)
CSR.Z_IN.vector_write(cycle, VALUE=z)
CSR.CTRL.vector_write(cycle + 3, START=1, MODE=mode, N_ITER=n_iter)

CSR.STATUS.vector_read(read_cycle, BUSY=0, VALID=1, ERROR=0)
CSR.X_OUT.vector_read(read_cycle, VALUE=expected_x)
```

Different IPs can have different behavioral models while sharing the same
project contract: model behavior, generated regmap, test catalogue, materialized
vectors.

## 8. 🔁 Regenerate vectors and infrastructure

```bash
fx tests_gen --force
fx tests
fx setup_tb --force
fx setup_cocotb --force
fx sim_tests
fx cocotb_tests
```

The loaded source model/test catalogue remains untouched; only derived vectors
and generated TB infrastructure are refreshed.

## 9. 🏗️ Synthesis/signoff regression

```bash
fx syn sdf sta power_estimate --force
```

This allows a reusable IP to be validated through the same frontend,
verification, and implementation stack as a newly generated IP.

## 10. 🔗 Reuse the IP in a larger SoC

The important next step is composition, not copying code manually.

A SoC run can stage validated IP source below its own run tree. The SoC then owns:

- top-level integration RTL;
- the system hierarchy/filelist;
- host/software integration;
- top-level constraints;
- SoC verification;
- system-level synthesis/signoff assumptions.

The IP continues to own its internal implementation and source collateral.
See [SoC development](guide_soc_dev.md).

## 11. 💾 Save authored changes deliberately

If development in a run intentionally changes reusable source collateral, use
the IP save flow deliberately rather than treating all run artifacts as source.
`ip_save` filters transient simulation/cache outputs while preserving authored
IP collateral.

## 12. ✅ Standard standalone regression

```text
settings
setup
ip_load
reg + doc
flist
lint_suite
regmap_py
tests_gen + tests
setup_tb + setup_cocotb
sim_tests + cocotb_tests
synthesis/signoff as needed
```

The central rule is preservation: derived collateral can be refreshed, authored
IP intent is not silently replaced.

## 13. 🧪 E2E regressions

```bash
pytest -s tests/test_e2e_fx.py::test_fx_cordic_ip_load_debug --no-signoff
pytest -s tests/test_e2e_fx.py::test_fx_uart_ip_load_debug --no-signoff
```

Use a custom E2E base when desired:

```bash
pytest -s tests/test_e2e_fx.py --e2e-root ~/flexsoc-e2e --no-signoff
```
