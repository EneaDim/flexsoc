<p align="center">
  <img src="assets/open-IP-SoC-logo.png" alt="Open IP SoC logo" width="280"/>
</p>

# FlexSoC

FlexSoC is a compact IP and SoC development flow for register-driven hardware.
It creates a clean run directory, generates register RTL from HJSON, scaffolds
RTL and verification, runs lint and simulations, and then drives synthesis,
timing, and power analysis.

The flow is intentionally explicit. You run the stage you need, inspect the
files it generated, edit the source-of-truth file, and rerun only the affected
stage.

## Main ideas

- **One command-line interface:** `fx`.
- **One run tree:** `workspace/runs/<TOP>/<RUN_ID>/`.
- **One selected design top:** `TOP=<top>`.
- **One clock-mode switch:** `CLOCK_MODE=single` or `CLOCK_MODE=multi`.
- **Model-driven vector tests:** the Python model generates `config.regs`,
  `data_in.vec`, and `data_out.vec`.
- **Testbenches consume vectors only:** SystemVerilog and cocotb do not import
  the model during simulation.
- **Lint before verification:** filelists and lint come before model/testbench
  work.
- **Top-level verification:** testbenches instantiate `<top>.sv`. To test a
  core directly, set `TOP=<top>_core` explicitly.

## Install

```bash
uv sync
source .venv/bin/activate
fx --help
```

## Single-clock full flow

```bash
fx settings TOP=test RUN_TOP=test RUN_ID=dev HOST=uart CLOCK_MODE=single

fx setup --force
fx hjson --force
fx reg doc --force
fx rtl_stub --force
fx top_from_core --force

fx flist --force
fx lint
fx lint_latch
fx lint_width
fx lint_unconnected
fx lint_undriven
fx lint_unused

fx setup_model --force
fx tests_gen
fx tests

fx setup_tb --force
fx setup_cocotb --force

fx sim_tests
fx cocotb_tests

fx syn sdf sta power --force
```

## Multi-clock full flow

```bash
fx settings TOP=tri_stream_dsp RUN_TOP=tri_stream_dsp RUN_ID=dev HOST=uart CLOCK_MODE=multi

fx setup --force
fx hjson --force
fx reg doc --force
fx rtl_stub --force
fx top_from_core --force

fx flist --force
fx lint
fx lint_latch
fx lint_width
fx lint_unconnected
fx lint_undriven
fx lint_unused

fx setup_model --force
fx tests_gen
fx tests

fx setup_tb --force
fx setup_cocotb --force

fx sim_tests
fx cocotb_tests

fx sdc_multi --force
fx syn sdf sta power --force
```

The `_multi` target names are still available for direct use, but the preferred
workflow is to set `CLOCK_MODE=multi` once and then use the normal targets.

## Useful guides

- [Quickstart](docs/quickstart.md)
- [Folder structure](docs/folder_structure.md)
- [Single-clock IP development guide](docs/guide_ip_dev.md)
- [Multi-clock IP development guide](docs/guide_multiclock_ip_dev.md)
- [SoC development guide](docs/guide_soc_dev.md)

## Tooling

FlexSoC is designed to sit on top of standard open-source tooling such as
regtool, slang, Verible, Verilator, cocotb, Yosys, OpenSTA, and OpenROAD.
