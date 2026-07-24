# SoC development guide 🏗️


> 🧰 **Shell setup used in this guide**
>
> Install/sync dependencies once, then activate the project environment:
>
> ```bash
> uv sync
> source .venv/bin/activate
> ```
>
> After activation, run commands directly with `fx ...`.

This guide explains how to build a small SoC on top of existing FlexSoC IPs.
The recommended approach is IP-first: validate each IP alone, then stage it into
the SoC run.

## 1. Validate IPs first

For each IP, run lint first, then verification and backend signoff:

```bash
fx settings TOP=<ip> RUN_TOP=<ip> RUN_ID=dev HOST=uart
fx flist lint --force
fx sim_tests cocotb_tests
fx syn sdf sta power --force
```

A SoC is easier to debug when every IP has clean lint before its standalone
regression and signoff steps.

## 2. Create a SoC run

```bash
fx settings TOP=soc RUN_TOP=soc RUN_ID=dev HOST=uart
fx setup
```

Use `HOST=uart` for a UART-hosted system, or `HOST=ibex` when the system is
CPU-hosted.

## 3. Load existing IPs

Stage IPs into the SoC workspace with `ip_load`:

```bash
fx ip_load --set IP=uart_master
fx ip_load --set IP=stream_accel
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
fx soc_uart_gen soc_prepare --force
```

The generated top should instantiate the host and the loaded IPs, connect address
maps and expose only SoC-level ports.

## 6. Lint the integrated SoC

Lint the SoC before writing or running SoC-level tests. At this point the host,
loaded IPs, filelists and generated top are connected, so lint catches integration
issues before the verification layer adds more variables.

```bash
fx flist lint --force
fx lint_latch lint_width lint_unconnected lint_undriven lint_unused
```

Review focused lint logs before moving to SoC-level modelling or regression.

## 7. Verification strategy

Keep two levels of tests:

1. **IP tests**: generated from each IP model and run standalone.
2. **SoC tests**: exercise the integrated address map and host access path.

For IP-level regression:

```bash
fx settings TOP=<ip> RUN_TOP=<ip> RUN_ID=dev HOST=uart
fx sim_tests
fx cocotb_tests
```

For SoC-level verification, generate SoC tests that write/read through the host
interface and check visible behavior. Do not assume that standalone IP vectors
can be reused unchanged at SoC level; the access path and timing are different.

## 8. Constraints and signoff

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
fx syn --force
fx sdf
fx sta
fx power
```

## 9. Software flow

When available, build and run software with:

```bash
fx soc_build_sw
fx soc_run
```

Use this once the hardware top and address map are stable.

## 10. Recommended SoC checklist

Before calling a SoC flow stable, check:

- every IP passes standalone lint and regression;
- SoC address map is documented;
- top-level ports are intentional;
- SoC SDC is reviewed from the SoC hierarchy;
- synthesis uses the SoC filelist, not stale IP-only lists;
- STA and power reports are generated from the SoC netlist;
- host tests can access all expected IP registers.
