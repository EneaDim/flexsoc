# FlexSoC backend map

This document maps the current backend modules before deeper file-by-file cleanup. It is intentionally descriptive rather than normative: public workflows and advanced steps will be frozen after each core module is reviewed.

## Classification legend

| Class | Meaning |
| --- | --- |
| `PUBLIC_WORKFLOW` | Candidate for a stable `FlexSoC` workflow method or workflow name. |
| `ADVANCED_STEP` | Useful as a direct expert step, but not the main user-facing API. |
| `INTERNAL` | Helper implementation detail that should remain behind the API layer. |
| `UTILITY` | Standalone helper that may remain callable through an advanced step. |

## Module inventory

| Module | Current role | Likely inputs | Likely outputs | Future API class |
| --- | --- | --- | --- | --- |
| `common.py` | Shared filesystem, RTL discovery, and SystemVerilog parsing helpers. | RTL directory, top name, path values. | Parsed signatures, ordered file lists, helper side effects. | `INTERNAL` |
| `driver_gen.py` | Generates simple software driver sources for peripherals. | IP/device metadata, output path. | C driver/source artifacts. | `ADVANCED_STEP` |
| `gen_filelist.py` | Builds RTL filelists for IP and SoC flows. | Top name, RTL directory, workspace/run id. | `rtl_list.f`-style filelists. | `ADVANCED_STEP` |
| `hjson_gen.py` | Renders HJSON metadata used by downstream tooling. | IP/top configuration values. | HJSON files. | `ADVANCED_STEP` |
| `regression.py` | Runs simulation regression targets over discovered testbenches. | `tb/regression/*.sv`, Make targets. | Make-driven simulation runs. | `ADVANCED_STEP` |
| `rtl_stub_gen.py` | Generates RTL wrappers and stubs from module signatures. | Top RTL module and output paths. | SystemVerilog stub/wrapper files. | `ADVANCED_STEP` |
| `setup_cocotb.py` | Generates cocotb scaffolding through `CocotbConfig`. | RTL filelists, top module, simulator choices. | cocotb Makefile, Python smoke test, SV wrapper. | `ADVANCED_STEP` |
| `setup_fsoc.py` | Prepares FuseSoC-related setup or ordering data. | RTL/IP metadata. | FuseSoC support files. | `ADVANCED_STEP` |
| `setup_model.py` | Emits a small Python reference model template. | Top name, optional output directory. | `model.py`. | `UTILITY` |
| `setup_pnr.py` | Prepares place-and-route scripts/configuration. | Filelists, constraints, technology/workspace values. | PnR scripts and run assets. | `ADVANCED_STEP` |
| `setup_sdc.py` | Generates a compact timing constraint file. | Top name, clock period, clock names. | SDC file. | `UTILITY` |
| `setup_signoff.py` | Prepares OpenSTA/signoff scripts. | Netlist, libraries, constraints, output paths. | STA/power/SDF Tcl scripts. | `ADVANCED_STEP` |
| `setup_syn.py` | Prepares synthesis scripts for ASIC/FPGA targets. | Top, RTL/filelist, technology, output options. | Yosys/Vivado/ABC scripts. | `ADVANCED_STEP` |
| `setup_tb.py` | Generates testbench scaffolding through `TestbenchConfig`. | Parsed RTL signature, top module, simulator choices. | SV testbench, include shim, optional bus helper files. | `ADVANCED_STEP` |
| `soc_cfg.py` | Resolves SoC host and memory-map configuration through `SoCConfig`. | Workspace, run top/id, devices, host. | Make fragments/arguments for SoC generation. | `PUBLIC_WORKFLOW` candidate |
| `soc_gen.py` | Generates top-level SoC RTL and integration wrappers. | IP list, xbar data, run configuration. | SoC RTL and top-level generated files. | `PUBLIC_WORKFLOW` candidate |
| `soc_start.py` | Initializes SoC run folders through `SoCStartConfig`. | Workspace/run identifiers, staged IP bundles. | Run directory, loaded IP list, merged RTL filelist, summary. | `PUBLIC_WORKFLOW` candidate |
| `sw_soc_gen.py` | Generates software project scaffolding for the SoC. | Run directory, devices/drivers. | C sources and Makefile. | `ADVANCED_STEP` |
| `xbar_init.py` | Builds crossbar JSON configuration. | Host and device address ranges. | JSON xbar configuration. | `UTILITY` |
| `fsm_gen/` | Bundled FSM generator utility. | FSM text/CSV input. | Generated FSM artifacts. | `UTILITY` / advanced step |

## First workflow hypothesis

| Workflow | Candidate backend sequence | Notes |
| --- | --- | --- |
| `prepare` | `setup_fsoc`, `setup_model`, `setup_tb`, selected setup helpers. | Needs validation against `mk/` and existing Make targets. |
| `soc` | `soc_start`, `soc_cfg`, `xbar_init`, `soc_gen`, `sw_soc_gen`, `gen_filelist`. | Strongest candidate for a public workflow. |
| `verify` | `setup_cocotb`, `regression`. | Should stay advanced until backend contracts are clearer. |
| `implementation` | `setup_syn`, `setup_pnr`, `setup_signoff`, `setup_sdc`. | Likely public later, but currently technology-specific. |
| `fsm` | `fsm_gen/`. | Utility workflow already preserved in backend. |

## Refactor order

1. Stabilize small utility modules first: `setup_sdc.py`, `setup_model.py`, `xbar_init.py`, `regression.py`.
2. Review filelist and metadata generators: `gen_filelist.py` and `hjson_gen.py` are now import-safe; `setup_fsoc.py` is now import-safe; setup generators continue next.
3. Review setup generators: `setup_tb.py`, `setup_syn.py`, and `setup_cocotb.py` now expose config-based writers; continue with remaining setup helpers.
4. Review SoC workflow modules last: `soc_start.py` and `soc_cfg.py` now have config-based entrypoints; continue with `soc_gen.py` and `sw_soc_gen.py`.

## Rules for each backend cleanup

- Use current canonical names only; do not add aliases for removed APIs or old paths.
- Add a short module docstring, plus concise docstrings for public functions.
- Prefer pure helper functions plus a small `main()` entrypoint.
- Avoid classes unless state or polymorphism clearly reduces complexity.
- Keep backend modules import-safe: no argument parsing or file writes at import time.

## Patch 0014 notes

- `hjson_gen.py` now exposes `write_hjson()` as a small pure backend helper for future API calls.
- `gen_filelist.py` now has concise docstrings and emits the new `flexsoc.backend` namespace in generated headers.
- The next low-risk candidates are `driver_gen.py` and `rtl_stub_gen.py`, followed by setup generators.


### Patch 0015 notes

- `driver_gen.py` now exposes pure render helpers and a small `generate_driver()` entrypoint.
- `driver_gen.py` can now be called directly by API integration without shelling out.

## Patch 0016 note

`rtl_stub_gen.py` now exposes `generate_rtl_stubs()` as a pure backend API entrypoint. This keeps generated RTL preview/generation callable from `FlexSoC` later without shelling out.


## Patch 0017 note

`setup_fsoc.py` now exposes `list_rtl_sources()`, `render_core()`, and `write_core()` so FuseSoC core generation can be called directly from the API layer.


## Patch 0018 note

`setup_pnr.py` now exposes `parse_filelist()`, `render_config()`, and `write_config()` so OpenROAD `config.mk` generation can be called directly from the API layer.


## Patch 0019 note

`setup_signoff.py` now exposes `STAConfig`, render helpers, and `write_signoff_scripts()` so OpenSTA script generation can be called directly from the API layer.

## Patch 0020 note

The Make flow and reviewed backend parsers now use one canonical naming style for current entrypoints. Old import aliases and compatibility-only Make aliases were removed so the development tree stays coherent while the API layer becomes the only stable boundary.

## Patch 0031 note

`setup_syn.py` now exposes `SynthesisConfig` and `generate_synthesis_scripts()` so ASIC/FPGA synthesis script generation can be called directly from the API layer without duplicating Makefile logic.

## Patch 0032 note

`setup_cocotb.py` now exposes `CocotbConfig` and `write_cocotb_scaffold()` so cocotb Makefile/test generation can be called directly from the API layer.

## Patch 0033 note

`soc_start.py` now exposes `SoCStartConfig` and `initialize_soc_run()` so SoC run staging can be called directly from the API layer.


## Patch 0034 note

`soc_cfg.py` now exposes `SoCConfig`, `SoCDevice`, and `resolve_soc_config()` so host/device memory-map resolution can be called directly from the API layer.

## Patch 0035 note

`soc_gen.py` now exposes `SoCGenerationConfig`, `SoCModule`, render helpers, and `generate_soc()` so top-level SoC RTL generation can be called directly from the API layer without duplicating CLI argument handling.
