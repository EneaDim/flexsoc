# Existing IP development guide

Use this flow when the IP already exists under:

```text
hw/ips/<top>/
```

An existing IP may contain a custom top wrapper, RTL organization, behavioral
model, generated CSR helper, test vectors, and verification collateral. The
standard flow preserves those source artifacts and regenerates only the parts
that are explicitly derived.

## 1. Source versus run copy

`ip_load` copies the IP into the selected run:

```text
hw/ips/<top>/
        │
        └── fx ip_load
              ↓
<WORKDIR>/runs/<RUN_TOP>/<RUN_ID>/
```

Edit and version the source IP under `hw/ips/<top>/`. Treat the loaded run as a
working copy used by the flow.

## 2. Configure and load

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

## 3. Preserve source-owned collateral

The standard existing-IP flow does **not** run:

```text
hjson
rtl_stub
top_from_core
setup_model
```

Reasons:

- the HJSON already exists in the IP;
- RTL may be hand-written rather than generated;
- the top wrapper may contain deliberate adaptation or integration logic;
- the behavioral model may contain IP-specific scenarios and reference checks.

Run these generation commands only when you explicitly intend to replace the
corresponding source artifact.

## 4. Regenerate register-derived collateral

The HJSON remains the register-map source of truth. Regenerate register RTL and
documentation in the loaded run with:

```bash
fx reg doc --force
```

Refresh only the model-side CSR API with:

```bash
fx regmap_py --force
```

This rewrites:

```text
model/regmap_<top>.py
```

and preserves:

```text
model/model_<top>.py
```

The model should therefore obtain register names, fields, masks, access modes,
and serialization from `regmap_<top>.py` instead of hardcoding the HJSON
layout.

## 5. Regenerate filelists and lint

```bash
fx flist --force
fx lint
fx lint_latch
fx lint_width
fx lint_unconnected
fx lint_undriven
fx lint_unused
```

## 6. Model patterns

### Mixed port + CSR IP

UART is a mixed-interface example:

- `cio_rx_i` is driven directly;
- `cio_tx_o` and `cio_tx_en_o` are checked directly;
- `CTRL`, FIFO data, FIFO status, and `RDATA` are accessed through generated CSR
  objects.

Typical model code:

```python
import regmap_uart as regmap

CSR = regmap.PRIMARY

rows_in = [
    drive(0, "cio_rx_i", 1),
    CSR.WDATA.vector_write(8, WDATA=0x5A),
]

rows_out = [
    check(16, "cio_tx_o", 1),
    CSR.STATUS.vector_read(400, TXIDLE=1, RXIDLE=1),
    CSR.RDATA.vector_read(400, RDATA=0x5A),
]
```

### CSR-only IP

CORDIC has no functional data pins at the top level. Operands and results are
entirely software-visible:

```python
CSR.X_IN.vector_write(cycle, VALUE=x)
CSR.Y_IN.vector_write(cycle, VALUE=y)
CSR.Z_IN.vector_write(cycle, VALUE=z)
CSR.CTRL.vector_write(cycle + 3, START=1, MODE=mode, N_ITER=n_iter)

CSR.STATUS.vector_read(read_cycle, BUSY=0, VALID=1, ERROR=0)
CSR.X_OUT.vector_read(read_cycle, VALUE=expected_x)
```

Both patterns use the same model/regmap contract.

## 7. Regenerate vectors and testbench infrastructure

```bash
fx tests_gen --force
fx tests
fx setup_tb --force
fx setup_cocotb --force
```

Then run:

```bash
fx sim_tests
fx cocotb_tests
```

## 8. Synthesis and signoff

```bash
fx syn sdf sta power --force
```

## 9. Standard existing-IP regression

The regression sequence is intentionally:

```text
settings
setup
ip_load
reg + doc
flist
lint + focused lint
regmap_py
tests_gen + tests
setup_tb + setup_cocotb
sim_tests + cocotb_tests
synthesis/signoff
```

It deliberately preserves the loaded top wrapper and behavioral model.

## 10. Isolated E2E tests

The repository contains existing-IP regressions for CORDIC and UART:

```bash
pytest -s tests/test_e2e_fx.py::test_fx_cordic_ip_load_debug --no-signoff
pytest -s tests/test_e2e_fx.py::test_fx_uart_ip_load_debug --no-signoff
```

Every E2E test runs under an isolated `/tmp/flexsoc-...` workspace. Successful
runs are removed automatically. Failed workspaces are retained and printed so
logs and generated collateral can be inspected directly.
