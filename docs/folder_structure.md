# 🗂️ Folder structure and ownership

FlexSoC separates **versioned reusable source** from **generated/working run
state**. This boundary is central to safe regeneration and IP reuse.

## ♻️ Reusable source IP library

Versioned IP source lives under:

```text
hw/ips/<top>/
```

A mature IP can contain:

```text
hw/ips/<top>/
├── data/      # HJSON source register maps
├── doc/       # source/retained documentation
├── model/     # behavioral model + generated regmap + test catalogue
├── rtl/       # RTL implementation/top
├── tb/        # source verification collateral where intentionally retained
├── syn/       # retained synthesis collateral when relevant
└── signoff/   # retained signoff collateral when relevant
```

`fx ip_load` copies source collateral into a run workspace. The source tree is
what can later be reused in a SoC/system.

## 🏃 Run workspaces

The default workspace root is `workspace/`, but every command can target another
root with `--workdir`.

```text
<WORKDIR>/runs/<RUN_TOP>/<RUN_ID>/
```

Examples:

```text
workspace/runs/uart/dev/
/tmp/flexsoc-uart-e2e-XXXXXX/runs/uart/dev/
~/projects/runs/soc/dev/
```

A typical run contains:

```text
runs/<RUN_TOP>/<RUN_ID>/
├── analysis/      # Slang AST/hierarchy and other analysis outputs
├── data/          # HJSON register specifications
├── doc/           # generated register documentation
├── logs/          # tool logs grouped by responsibility
├── model/         # behavioral model, generated regmap, test catalogue
├── pnr_openroad/  # physical-design collateral
├── rtl/           # RTL implementation + canonical filelists
├── signoff/       # SDF/STA/power collateral
├── sim/           # simulation outputs and waveforms
├── syn/           # synthesis scripts/results
└── tb/            # vectors + SV/cocotb infrastructure
```

## 🧠 Model ownership

Single- and multi-clock flows use the same split:

```text
model/
├── <top>_model.py   # authored behavioral/reference model
├── <top>_regmap.py  # generated from one or more HJSON maps
└── <top>_tests.py   # authored scenario catalogue + vector generation
```

### 🧠 `<top>_model.py`

Owns behavioral transformation and model-owned state. A simple pipeline can
also declare a transaction latency used by tests.

### 🧾 `<top>_regmap.py`

Owns generated register/domain metadata:

- register/domain names;
- offsets and reset values;
- field positions and access modes;
- encoding and masks;
- `config.regs` serialization;
- CSR `@write` / `@read` serialization.

Refresh it independently with:

```bash
fx regmap_py --force
```

### 🧪 `<top>_tests.py`

Owns:

- test catalogue/scenarios;
- initial CSR configuration;
- functional input stimulus;
- functional output expectations;
- CSR write/read timing;
- fixed-latency or valid-driven check policy.

`fx setup_model --force` rewrites all three files and should be treated as an
intentional scaffold reset after model/test customization.

## 🧭 Canonical RTL filelists

`fx flist` uses Slang hierarchy elaboration and produces:

```text
rtl/
├── rtl_common.f
└── rtl_ip.f
```

`rtl_common.f` contains reachable shared FlexSoC infrastructure such as
packages/primitives/TL-UL. `rtl_ip.f` contains reachable IP/run sources.

The split is project ownership; the ordering/reachability comes from Slang.
These command files include required `+incdir+...` entries and are consumed by
lint, simulation, and synthesis.

## 🧪 Vector tests

```text
tb/tests/<TEST_NAME>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

Semantics:

- `config.regs`: initial CSR configuration;
- `data_in.vec`: direct input drives and/or CSR `@write` operations;
- `data_out.vec`: direct output checks and/or CSR `@read` expectations.

Both SystemVerilog and cocotb consume these files; simulators do not import the
behavioral model directly.

## 🧰 Generated verification infrastructure

Typical SystemVerilog layout:

```text
tb/sv/
├── <top>_tb.sv
├── include_<top>_tb.sv
└── drivers/
    ├── <top>_reg_driver.svh
    ├── <top>_vec_driver.svh
    └── <top>_vec_monitor.svh
```

Typical cocotb layout:

```text
tb/cocotb/
├── Makefile
├── <top>_cocotb_tb.sv
├── <top>_test.py
└── drivers/
    ├── __init__.py
    ├── reg_driver.py
    ├── vec_driver.py
    └── vec_monitor.py
```

Exact names can vary by flow; ownership stays stable: infrastructure is derived,
behavioral expectations live in the model/test/vector layer.

## 🪵 Logs

```text
logs/
├── lint/
├── verification/
├── synthesis/
└── signoff/
```

The terminal shows compact progress by default. Add `--live` when full tool
output is required.

## 🔗 SoC staging

When an IP is loaded into a larger `RUN_TOP`, reusable source can be staged
below the SoC run rather than replacing it. The system then resolves one
reachable hierarchy across top-level RTL plus staged IPs.

The source/run separation is what allows the same IP to be tested standalone
and reused in multiple larger systems.

## 🧪 E2E workspace policy

`tests/test_e2e_fx.py` never uses the repository `workspace/` tree. By default it
creates isolated directories under `/tmp`:

```text
/tmp/flexsoc-full-e2e-XXXXXX/
/tmp/flexsoc-cordic-e2e-XXXXXX/
/tmp/flexsoc-uart-e2e-XXXXXX/
```

Select another base directory with either:

```bash
pytest -s tests/test_e2e_fx.py --e2e-root /path/to/e2e
FLEXSOC_E2E_ROOT=/path/to/e2e pytest -s tests/test_e2e_fx.py
```

Successful directories are deleted. Failed directories are retained for
inspection.
