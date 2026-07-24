# SoC development guide 🏗️

This guide explains how to build a small SoC on top of existing FlexSoC IPs.
The recommended approach is IP-first: validate each IP alone, then stage it into
the SoC run.

## 1. Validate IPs first

For each IP, run at least:

```bash
uv run fx settings TOP=<ip> RUN_TOP=<ip> RUN_ID=dev HOST=uart
uv run fx lint sim_tests cocotb_tests syn sdf sta power --force
```

A SoC is easier to debug when each IP already has passing standalone tests.

## 2. Create a SoC run

```bash
uv run fx settings TOP=soc RUN_TOP=soc RUN_ID=dev HOST=uart
uv run fx setup
```

Use `HOST=uart` for a UART-hosted system, or `HOST=ibex` when the system is
CPU-hosted.

## 3. Load existing IPs

Stage IPs into the SoC workspace with `ip_load`:

```bash
uv run fx ip_load --set IP=uart_master
uv run fx ip_load --set IP=stream_accel
```

The SoC run should collect:

- RTL/filelist metadata for each IP;
- register-map information;
- software-visible base addresses;
- verification assets where applicable.

## 4. SoC workspace structure

A SoC run keeps top-level artifacts separate from per-IP artifacts:

```text
workspace/runs/soc/dev/
├── ips/                 # staged IP collateral
├── rtl/                 # SoC top and integration RTL
├── data/                # SoC-level config/address information
├── tb/                  # SoC-level tests
├── model/               # SoC-level or staged IP models
├── pnr_openroad/soc.sdc # SoC-level constraints
├── syn/                 # SoC synthesis scripts/netlists
└── signoff/             # SoC STA/power/SDF reports
```

## 5. Build the SoC top

For a UART-hosted system, generate and prepare the SoC wrapper:

```bash
uv run fx soc_uart_gen soc_prepare --force
```

The generated top should instantiate the host and the loaded IPs, connect address
maps and expose only SoC-level ports.

## 6. Verification strategy

Keep two levels of tests:

1. **IP tests**: generated from each IP model and run standalone.
2. **SoC tests**: exercise the integrated address map and host access path.

For IP-level regression:

```bash
uv run fx settings TOP=<ip> RUN_TOP=<ip> RUN_ID=dev HOST=uart
uv run fx sim_tests
uv run fx cocotb_tests
```

For SoC-level verification, generate SoC tests that write/read through the host
interface and check visible behavior. Do not assume that standalone IP vectors
can be reused unchanged at SoC level; the access path and timing are different.

## 7. Constraints and signoff

The SoC must have its own SDC:

```text
workspace/runs/soc/dev/pnr_openroad/soc.sdc
```

Do not blindly reuse an IP-level SDC. At SoC level:

- clock ports may have different names;
- hierarchy has changed;
- generated clocks may come from the host or clocking fabric;
- async clock groups must be declared from the SoC top view;
- false paths must refer to SoC-level paths.

Then run:

```bash
uv run fx syn --force
uv run fx sdf
uv run fx sta
uv run fx power
```

## 8. Software flow

When available, build and run software with:

```bash
uv run fx soc_build_sw
uv run fx soc_run
```

Use this once the hardware top and address map are stable.

## 9. Recommended SoC checklist

Before calling a SoC flow stable, check:

- every IP passes standalone lint and regression;
- SoC address map is documented;
- top-level ports are intentional;
- SoC SDC is reviewed from the SoC hierarchy;
- synthesis uses the SoC filelist, not stale IP-only lists;
- STA and power reports are generated from the SoC netlist;
- host tests can access all expected IP registers.
