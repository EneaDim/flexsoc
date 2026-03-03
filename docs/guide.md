# flexsoc — Guides

This document replaces legacy `make help*` banners with **CLI-first** instructions.
The backend Makefile targets still exist, but users should primarily use the **flexsoc CLI**.

**Key idea**
- Use `flexsoc run <action>` for *registry actions* (stable API).
- Use `flexsoc make <target> [-- <extra make args>]` as an *escape hatch* for any Makefile target.
- All outputs are **workspace-based**:
  - **Flow dir**: `workspace/runs/<top>/<run_id>/...` (artifacts produced by the flow)
  - **Runner dir**: `workspace/runs/<timestamp>_<action>/...` (logs + runner manifest)

---

## 0) Start here

### Environment / Toolchain check
Run:

```bash
flexsoc doctor
```

Useful flags:
```bash
FLEXSOC_LOG_LEVEL=DEBUG flexsoc ...
FLEXSOC_PROFILE=1 flexsoc ...
```

### Discoverability
```bash
flexsoc                # UI hub
flexsoc help topics    # navigation
flexsoc actions        # registry actions
flexsoc action ip_start
flexsoc make --list    # list available flow/ Make targets (best effort)
```

---

# 1) Control And Status Register + Documentation Guide

## HJSON setup
Create the `.hjson` template used to generate documentation and regmap.

**CLI-first recommendation**
- If you are creating a new IP: do **bootstrap** (`ip_start`) and then adjust the generated `data/*.hjson`.

Bootstrap (creates an IP run and generates initial scaffolding):
```bash
flexsoc run ip_start --top my_ip --run-id dev1 --reg-itf tlul --overwrite --force
```

If you want to run the backend step directly:
```bash
flexsoc make hjson --top my_ip --run-id dev1
```
and then adjust the generated `data/*.hjson`.

## Documentation
Generate Markdown documentation from the `.hjson`.

```bash
flexsoc make doc --top my_ip --run-id dev1
```

## Regmap
Generate the regmap for SoC integration (TL-UL interface-based).

```bash
flexsoc make reg --top my_ip --run-id dev1 -- -- REG_ITF=tlul
```

Artifacts (typical):
- `workspace/runs/my_ip/dev1/data/` (hjson + generated files)
- `workspace/runs/my_ip/dev1/docs/` or `workspace/runs/my_ip/dev1/doc/` (generated docs, depending on backend)
- `workspace/runs/my_ip/dev1/rtl/` (generated reg RTL, if applicable)

---

# 2) IP DEVELOPMENT GUIDE  (legacy: help_ip.py order)

## CONFIG
- Define parameters under `config.mk` (backend config).
- For flexsoc runs, you typically set:
  - `--top <ip_name>`
  - `--run-id <id>`

Example:
```bash
flexsoc run ip_start --top my_ip --run-id dev1 --reg-itf tlul --overwrite --force
```

## SETUP
Workspace/run dirs are created automatically by the CLI.
If you need to execute the backend setup explicitly:

```bash
flexsoc make setup --top my_ip --run-id dev1
```

## HJSON
Initialize or regenerate CSR/doc configuration under the run directory:

```bash
flexsoc make hjson --top my_ip --run-id dev1
```

## DOC
Generate documentation from HJSON:

```bash
flexsoc make doc --top my_ip --run-id dev1
```

## REG
Generate CSR registers (TL-UL interface) from HJSON:

```bash
flexsoc make reg --top my_ip --run-id dev1 -- -- REG_ITF=tlul
```

## RTL SKELETON
Generate the RTL core and wrapper skeleton:

```bash
flexsoc make rtl_stub --top my_ip --run-id dev1
```

## RTL CODING
Edit SystemVerilog RTL under:
- `workspace/runs/my_ip/dev1/rtl/`

## SV2V
Generate a single Verilog file from all RTL sources:

```bash
flexsoc make sv2v --top my_ip --run-id dev1
```

## LINTING
Run linting:

```bash
flexsoc run lint --top my_ip --workspace workspace --run-id dev1
# or backend target:
flexsoc make lint --top my_ip --run-id dev1
```

## TESTBENCH SETUP
Setup the Verilog/SystemVerilog testbench:

```bash
flexsoc make setup_tb --top my_ip --run-id dev1
```

## COMPILE
Compile testbench and DUT:

```bash
flexsoc make compile --top my_ip --run-id dev1
```

## SIMULATION RUN
Run simulation (Verilator fast path):

```bash
flexsoc run sim --top my_ip --workspace workspace --run-id dev1
# or backend target:
flexsoc make sim --top my_ip --run-id dev1
```

Expected CLI output includes a **Coverage:** line (contracted by E2E tests).

## SIMULATION VIEW
View waveforms (if supported by backend):

```bash
flexsoc make view --top my_ip --run-id dev1
```

## TESTBENCH UPDATE
Iterate on testbench sources under:
- `workspace/runs/my_ip/dev1/tb/`

Re-run:
```bash
flexsoc make sim --top my_ip --run-id dev1
```

## VIEW PRE-SYN with YOSYS
Visualize pre-synthesis design graph (if supported):

```bash
flexsoc make view_presyn --top my_ip --run-id dev1
```

## SYNTHESIS
Run synthesis:

```bash
flexsoc run synth --top my_ip --workspace workspace --run-id dev1
# or backend target:
flexsoc make syn --top my_ip --run-id dev1
```

Artifacts:
- `workspace/runs/my_ip/dev1/syn/` (netlist, reports)

## SDF
Generate SDF:

```bash
flexsoc make sdf --top my_ip --run-id dev1
```

Artifacts:
- `workspace/runs/my_ip/dev1/signoff/` (SDF output, depending on backend)

## STATIC TIMING ANALYSIS
Run STA:

```bash
flexsoc run sta --top my_ip --workspace workspace --run-id dev1
# or backend target:
flexsoc make sta --top my_ip --run-id dev1
```

Artifacts:
- `workspace/runs/my_ip/dev1/signoff/` (timing reports)

## PATH VIEW
Generate path visualization (if supported):

```bash
flexsoc make path --top my_ip --run-id dev1 -- -- view
```

## POWER ANALYSIS
Run static + VCD-based power analysis:

```bash
flexsoc make power --top my_ip --run-id dev1
```

Artifacts:
- `workspace/runs/my_ip/dev1/signoff/` (power reports)

## SYNTHESIS SIMULATION RUN
Run post-synthesis simulation (if supported):

```bash
flexsoc make sim_syn --top my_ip --run-id dev1
```

## SYNTHESIS SIMULATION VIEW
View post-synthesis waveforms (if supported):

```bash
flexsoc make view_syn --top my_ip --run-id dev1
```

## REGRESSION
Run regression suites (if supported):

```bash
flexsoc make regression --top my_ip --run-id dev1
```

## FUSESOC
Initialize a FuseSoC `.core` file for the IP (if supported):

```bash
flexsoc make fsoc_init --top my_ip --run-id dev1
```

## DRIVER
Generate driver `.h`/`.c` files (if supported):

```bash
flexsoc make driver --top my_ip --run-id dev1 -- -- MOD_ADD=0x<base_addr>
```

## SAVE IP
Save/export IP into `ips/` (if supported):

```bash
flexsoc make ip_save --top my_ip --run-id dev1
```

---

# 3) SoC INTEGRATION GUIDE  (legacy: help_soc.py order)

## CONFIG
- Verify memory mapping and SoC-related parameters in `config.mk` (backend config).
- Ensure IPs are generated/available.

## FETCH IPs
Fetch IPs via vendor mechanism (examples):

```bash
flexsoc make fetch -- -- VENDOR=lowrisc_ip
flexsoc make fetch -- -- VENDOR=lowrisc_ibex
```

## LOAD IPs
Load each internal IP you need:

```bash
flexsoc make ip_load -- -- TOP=<ip_name>
```

## XBAR
Define and build the crossbar:

```bash
flexsoc make xbar
```

(Under the hood some backends run `xbar_init` and `xbar_build`.)

## SoC BUILD
Generate SoC wrapper/config:

```bash
flexsoc make soc
```

## SoC SIM
Setup testbench and run simulation for SoC:

```bash
flexsoc make setup_tb -- -- TOP=soc
flexsoc make sim -- -- TOP=soc
flexsoc make view -- -- TOP=soc
```

## SoC SIM with IBEX
Run SoC simulation target with FuseSoC (if supported):

```bash
flexsoc make soc_sim
```

## SoC RUN with IBEX
Compile SW and start Verilator (if supported):

```bash
flexsoc make soc_run
```

## SoC VIEW with IBEX
View waveforms (if supported):

```bash
flexsoc make soc_view
```

---

# 4) Debugging cheat-sheet ✅

### Where do I look when something fails?
1) Runner logs (always):
- `workspace/runs/<timestamp>_<action>/stdout.log`
- `workspace/runs/<timestamp>_<action>/stderr.log`
- `workspace/runs/<timestamp>_<action>/manifest.json`

2) Flow logs (per run):
- `workspace/runs/<top>/<run_id>/logs/`

### What’s the difference between runner dir and flow dir?
- **Runner dir**: execution wrapper for a single CLI call (good for debugging command invocation).
- **Flow dir**: produced artifacts for the actual hardware flow run.

---

# 5) Suggested next commands

- Discover available actions:
```bash
flexsoc actions
```

- Inspect action metadata/params:
```bash
flexsoc action ip_start
```

- Run a plan:
```bash
flexsoc plan "create ip" --out plan.json
flexsoc exec plan.json --workspace workspace --run-id dev2 --top my_ip --reg-itf tlul --overwrite --force
```
