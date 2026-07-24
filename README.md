<p align="center">
  <img src="assets/open-IP-SoC-logo.png" alt="Open IP SoC logo" width="280"/>
</p>

# FlexSoC


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

FlexSoC is a lightweight hardware development flow for building, verifying and
signing off IP blocks and small SoCs from a single `fx` command-line interface.

The goal is simple: generate the boring project scaffolding, keep the generated
files readable, and let the designer focus on architecture, RTL, verification
and constraints.

## ✨ Features

- 🧩 **IP development flow**: register map generation, documentation, RTL stub,
  filelists, lint, model-based vectors, SystemVerilog simulation, cocotb,
  synthesis, SDF, STA and power.
- 🏗️ **SoC development flow**: load existing IPs, stage their metadata, generate
  SoC-level structure and build on top of UART or Ibex-hosted systems.
- 🔁 **Model-driven verification**: generate `config.regs`, `data_in.vec` and
  `data_out.vec` from a Python model, then run the same tests with SV or cocotb.
- ⏱️ **Multi-clock IP scaffolding**: generate a coherent starting point for IPs
  with multiple clock domains, multiple regmaps, clock gating, async FIFOs and
  multi-corner signoff constraints.
- 🧹 **Focused linting**: run full lint or specific checks such as latch, width,
  unconnected, undriven and unused diagnostics.

## 🛠️ Tools

FlexSoC orchestrates common open-source RTL and physical-design tools:

- `slang` and `verible` for SystemVerilog parsing/formatting/lint support;
- `verilator` for lint and fast simulation;
- `cocotb` for Python-driven verification;
- `yosys` for synthesis;
- `OpenSTA` for timing analysis;
- `OpenROAD` for physical-design oriented setup and collateral.

## 🚀 Minimal quickstart

```bash
uv sync
fx --help
fx settings TOP=test RUN_TOP=test RUN_ID=dev HOST=uart
fx setup hjson reg doc rtl_stub lint setup_model setup_tb setup_cocotb sim cocotb --force
fx syn sdf sta power --force
```

List generated tests and run one by name:

```bash
fx tests
fx sim --set TEST_NAME=smoke
fx cocotb --set TEST_NAME=smoke
```

## 📚 Documentation

Start here:

- [Quickstart](docs/quickstart.md) — install, configure and run the basic flow.
- [Folder structure](docs/folder_structure.md) — understand what FlexSoC creates.
- [IP development guide](docs/guide_ip_dev.md) — complete single-clock IP flow.
- [SoC development guide](docs/guide_soc_dev.md) — load IPs and build a SoC on top.
- [Multi-clock IP guide](docs/guide_multiclock_ip_dev.md) — advanced IPs with
  multiple clock domains, multiple regmaps, CDC and multi-corner signoff.

## 🧭 Design philosophy

FlexSoC intentionally keeps the generated files explicit. Generated RTL, models,
test vectors and constraints are meant to be read, edited and reviewed. The tool
should accelerate setup without hiding design intent.

- Signoff produces setup/hold STA and power logs per corner, plus a compact Markdown report under `logs/`.
