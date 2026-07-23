<p align="center">
  <img src="assets/open-IP-SoC-logo.png" alt="Open IP SoC logo" width="280"/>
</p>

# FlexSoC

FlexSoC is a compact Python-driven flow for building, checking, and integrating
SystemVerilog IPs and small SoCs. The main entry point is `fx`: a thin CLI over a
single backend Makefile.

## ✨ What it does

- 🧩 **IP development flow**: create the run folder, generate HJSON/register RTL,
  documentation, RTL stubs, filelists, testbenches, cocotb scaffolds, and models.
- ✅ **Verification flow**: run SystemVerilog vector tests, cocotb tests, and full
  per-IP regressions.
- 🔍 **Lint flow**: run broad and focused lint checks, including latch, width,
  unconnected, undriven, and unused diagnostics.
- 🏗️ **Implementation flow**: run synthesis, SDF generation, static timing
  analysis, power analysis, and OpenROAD backend preparation.
- 🌐 **SoC development flow**: load reusable IPs, generate UART-host or Ibex-host
  SoCs, build software, and run simulation flows.

## 🛠️ Tools used

FlexSoC coordinates common open-source EDA tools instead of hiding them:

- **slang** and **sv2v** for SystemVerilog front-end handling;
- **verible** and **verilator** for formatting, linting, and simulation checks;
- **cocotb** for Python-based verification;
- **yosys** for synthesis;
- **OpenSTA** for timing and power signoff scripts;
- **OpenROAD** for physical implementation flows.

## 🚀 Quick start

```bash
uv sync
uv run fx --help
uv run fx commands
```

Create and validate a scratch IP:

```bash
uv run fx settings TOP=test RUN_TOP=test RUN_ID=dev HOST=uart
uv run fx setup hjson reg doc rtl_stub flist setup_tb setup_cocotb setup_model --force
uv run fx sim --set TEST_NAME=smoke
uv run fx cocotb --set TEST_NAME=smoke
uv run fx lint lint_latch lint_width lint_unconnected lint_undriven lint_unused
uv run fx syn sdf sta power
```

Run all generated tests for the active IP:

```bash
uv run fx sim_tests
uv run fx cocotb_tests
```

## 📚 Documentation

Keep it simple:

- [`docs/quickstart.md`](docs/quickstart.md) — practical commands for IP and SoC flows.
- [`docs/folder_structure.md`](docs/folder_structure.md) — what each folder is for.
