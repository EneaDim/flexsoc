# Folder structure 📁

FlexSoC keeps generated work under `workspace/runs/<RUN_TOP>/<RUN_ID>`.

Example:

```text
workspace/runs/test/dev/
├── data/          # HJSON register-map sources
├── doc/           # generated documentation
├── logs/          # lint, sim, synth, STA and power logs
├── model/         # editable Python models that generate tests
├── pnr_openroad/  # SDC and OpenROAD-related collateral
├── rtl/           # generated and edited SystemVerilog RTL
├── signoff/       # STA, SDF and power scripts/reports
├── sim/           # simulation outputs, VCDs and executables
├── syn/           # synthesis scripts and netlists
└── tb/            # SV/cocotb testbench and generated vector tests
```

## Important directories

### `data/`

Contains HJSON register-map sources. For a simple IP there is usually one file:

```text
data/<top>.hjson
```

For a multi-clock or multi-regmap IP there may be several files:

```text
data/<top>_cfg.hjson
data/<top>_dsp.hjson
```

### `rtl/`

Contains RTL and filelists. FlexSoC keeps filelists simple:

```text
rtl_common.f
rtl_ip.f
```

Avoid adding duplicate filelists unless there is a clear reason.

### `model/`

Contains the Python model that generates tests. The model is not used directly
by the simulator after vectors are generated. The simulator consumes only:

```text
tb/tests/<test>/config.regs
tb/tests/<test>/data_in.vec
tb/tests/<test>/data_out.vec
```

### `tb/tests/`

Each test has its own self-contained directory:

```text
tb/tests/smoke/
├── config.regs
├── data_in.vec
└── data_out.vec
```

Run a test by name:

```bash
uv run fx sim --set TEST_NAME=smoke
uv run fx cocotb --set TEST_NAME=smoke
```

### `pnr_openroad/`

The IP-level SDC lives here:

```text
pnr_openroad/<top>.sdc
```

This is the canonical constraint source used by synthesis/signoff setup.

### `signoff/`

Contains generated scripts and reports for SDF, STA and power. The signoff
scripts read the relevant synthesized netlist and constraints; they should not
be treated as the primary source of design constraints.

## SoC staging

When building a SoC, loaded IPs are staged under the SoC run. The SoC has its
own top-level RTL, address map, verification layout and SDC. Do not blindly reuse
an IP SDC as the SoC SDC: clock ports, generated clocks and hierarchy change at
SoC level.
