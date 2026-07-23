# 📁 FlexSoC Folder Structure

FlexSoC keeps source IPs, generated runs, backend scripts, and tests separate.
That makes it easier to delete generated data without losing reusable sources.

```text
flexsoc/
├── README.md                  # short project overview
├── pyproject.toml             # uv package + dependency definition
├── Makefile                   # developer shortcuts
├── docs/
│   ├── QUICKSTART.md          # practical flow commands
│   └── FOLDER_STRUCTURE.md    # this guide
├── src/flexsoc/
│   ├── api.py                 # minimal Python API layer
│   ├── cli.py                 # minimal Typer/Rich fx CLI
│   └── backend/
│       ├── Makefile           # canonical flow implementation
│       └── *.py               # small generators and setup helpers
├── hw/ips/
│   └── <ip>/                  # reusable checked-in IP sources
├── workspace/
│   └── runs/<RUN_TOP>/<RUN_ID>/# generated run artifacts
└── tests/                     # pytest API and end-to-end checks
```

## 🧩 Source IP folders

A reusable IP under `hw/ips/<ip>/` may contain:

```text
<ip>/
├── data/          # HJSON register map and IP metadata
├── rtl/           # source RTL
├── tb/            # reusable testbench sources and tests
├── model/         # Python model templates
├── doc/           # generated or hand-written IP documentation
├── syn/           # synthesis scripts
├── signoff/       # STA, SDF, and power scripts
├── pnr_openroad/  # OpenROAD configuration
└── *.core         # optional FuseSoC core description
```

## 🏃 Run folders

A generated run lives in:

```text
workspace/runs/<RUN_TOP>/<RUN_ID>/
```

Typical content:

```text
rtl/             # generated RTL, reg package/top, and filelists
tb/              # SystemVerilog testbench and vector tests
tb/cocotb/       # cocotb runner, drivers, monitors, results, waves
model/           # Python model that can generate tests
logs/            # lint and flow logs
syn/             # synthesis outputs
signoff/         # SDF, STA, and power outputs
pnr_openroad/    # backend config and OpenROAD outputs
ips/             # IPs copied into a SoC integration run
```

## ✅ Verification layout

Generated tests are intentionally simple:

```text
tb/tests/<test>/
├── config.regs   # register writes; keyword `write` is implicit
├── data_in.vec   # cycle-based input stimulus
└── data_out.vec  # cycle-based expected outputs
```

You can select a test by name or by zero-based index:

```bash
uv run fx sim --set TEST_NAME=smoke
uv run fx sim --set TEST_ID=1
uv run fx cocotb --set TEST_NAME=smoke
uv run fx cocotb --set TEST_ID=1
```

Run every generated test for the active IP:

```bash
uv run fx sim_tests
uv run fx cocotb_tests
```

## 🌐 SoC folders

A SoC run keeps integrated IPs inside the run folder:

```text
workspace/runs/soc_uart/dev/
├── ips/              # loaded IP snapshots for this SoC
├── rtl/              # generated SoC RTL
├── sw/               # generated/compiled software
├── tb/               # SoC testbench
└── fusesoc/          # local FuseSoC build layout
```

This keeps per-SoC integration reproducible and avoids mutating the checked-in
IP sources while building a system.
