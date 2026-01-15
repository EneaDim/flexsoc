<p align="center">
<img src="assets/open-IP-SoC-logo.png" alt="Digital IP SoC Dev Env Logo" width="300"/>
</p>

<a id="setup"></a>

## 🚀 **Open-Source Environment for Digital IP Development & SoC Integration**

This repository provides a modular and open-source environment designed to **simplify the development, verification, and integration of digital IPs into a System-on-Chip (SoC)**. It supports the **entire IP development lifecycle**, making it easy to adopt modern, collaborative hardware design practices.

In addition to the traditional Makefile-based flow, the repository includes a retrieval-style, embedding-based agent that enables natural-language interaction (English or Italian) with the hardware flow via the terminal or a web UI.

## [![Ask DeepWiki](https://deepwiki.com/badge.svg)](https://deepwiki.com/EneaDim/flexsoc)

---

## Table of Contents

* [Project Objectives](#project-objectives)
* [Key Features](#key-features)
* [Dependencies](#dependencies)
* [Usage](#usage)
* [Folder Structure](#folder-structure)
* [Tutorial 0](#tutorial-0)
* [Tutorial 1](#tutorial-1)
* [Tutorial 2](#tutorial-2)
* [Tutorial 3](#tutorial-3)
* [Tutorial 4](#tutorial-4)
* [Flow Overview](#flow-overview)
* [SoC Composition](#soc-composition)
* [Natural Language Make Agent](#natural-language-make-agent)
* [Next Steps](#next-steps)
* [Environment Details](#environment-details)
* [License](#license)

---

<a id="project-objectives"></a>

## 🎯 Project Objectives

* Enable digital designers to **develop, document, validate and integrate IPs** with minimal setup and focus on the core features.
* Make **open-source EDA tools** accessible and practical for real-world hardware projects.
* Provide a seamless **integration path into SoCs**, including those built with the [lowRISC](https://github.com/lowRISC) ecosystem.
* Serve as a launchpad for **future IP contributions to the lowRISC ecosystem**, following its Comportable IP principles, coding standards, and tooling flow.
* Experiment with natural-language–driven hardware workflows, fully backed by deterministic Makefile execution.

---

<a id="key-features"></a>

## 📦 Key Features

✔️ **Complete IP Development Flow**
All based on open-source tooling:

* 📁 Automatic hjson configuration file generation
* 📄 Automatic documentation generation
* 🧠 Automatic CSR generation via lowRISC regtool with two options:

  * TLUL interface (lowRISC)
  * Register Interface (PULP)
* 🛠️ Automatic RTL stub and wrapper generation from hjson
* 🔍 RTL linting and formatting
* 🔬 Functional simulation

  * SystemVerilog Testbench
  * Cocotb
* 🏗️ Synthesis trials (PPA)
* ⏱️ Static Timing Analysis
* 🔌 Power estimation and analysis
* 🧱 Physical implementation from RTL to GDS (OpenROAD-based)
* 🌐 IP fetching and dependency management via GitHub
* 🔀 XBAR interconnect generation
* 🧩 SoC integration with modular IPs (TLUL Interface)

> **Why dual support?** Some projects target OpenTitan/lowRISC SoCs (TL-UL, regtool), others the PULP ecosystem. This environment lets you prototype and verify IPs in **both** styles without switching repositories.

---

<a id="dependencies"></a>
## 📦 Dependencies

You can **use a prebuilt Docker image** (fastest) or install everything locally with `make deps`.
The FlexSoC environment is typically used **inside a Docker container**, ensuring toolchain reproducibility.
The Natural Language Make Agent relies on **Ollama** for both LLM inference and text embeddings.

### ✅ Prerequisites (host)

- **Docker**
  - **Ubuntu/Debian (quick way)**:
    ```bash
    curl -fsSL https://get.docker.com | sh
    sudo groupadd docker
    sudo usermod -aG docker $USER
    newgrp docker  # re-evaluate groups so 'docker' works without sudo
    docker version
    ```

### 🚀 Try via Docker (no local install)

- **ghcr.io/eneadim/flexsoc:latest** → ~7 GB, toolchain base with IP development flow.

  ```bash
  # pull the prebuilt image
  docker pull ghcr.io/eneadim/flexsoc:latest
  
  # start the container in the current repo (mounts your workspace)
  docker run --rm -it \
    -e DISPLAY=$DISPLAY \
    -e GDK_BACKEND=x11 -e QT_X11_NO_MITSHM=1 -e NO_AT_BRIDGE=1 \
    -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
    ghcr.io/eneadim/flexsoc:latest bash
  # Then you go under flexsoc
  cd /opt/flexsoc
  ```

### 🤖 Ollama Installation (Embedding-only Mode)

FlexSoC Make Agent currently uses **Ollama only for text embeddings**.

There is **no chat / reasoning model in the execution path**:

* Ollama is used **only** to convert user text into vectors
* Routing is deterministic (rules first, embeddings second)
* Make execution is always explicit and validated

If Ollama is **not already available** on your system (host or container), install it as follows.

---

### 📦 Install Ollama

```bash
curl -fsSL https://ollama.com/install.sh | sh
```

Verify installation:

```bash
ollama --version
```

Start the Ollama service (if not already running):

```bash
nohup ollama serve > /tmp/ollama.log 2>&1 &
```

---

### 🧠 Required Model (Embeddings Only)

At this stage, the agent requires **one model only**:

* **Embedding model** — used for semantic intent routing

Pull it once:

```bash
ollama pull nomic-embed-text
```

⚠️ No chat / LLM model is required to run Make targets.

The embedding model:

* does **not** generate commands
* does **not** reason about execution
* only helps classify *which existing Make target* best matches the user intent

---

### 🧪 Quick Test

Start the interactive agent:

```bash
make agent
```

Example commands:

```text
help me
start
lint
run view
pulisci la simulazione
```

Each command is deterministically resolved to **one explicit `make <target>`**, validated, executed, and fully logged.

---

> **Note**
>
> LLM-based JSON routing (chat models) may be added later for explanation or advanced workflows, but **execution will remain embedding-driven and deterministic by default**.

---

<a id="usage"></a>
## ⚙️ Usage

- Run `make help` to see the different guides of the environment.

- Run `make ip_start` to start:
    - Hjson definition.
    - Register Map generation.
    - Documentation generation.
    - RTL stub definition.
    - RTL wrapper definition.
    - Testbench generation.
    - Linting the design.
    - Simulation of the testbench.
- After `ip_start` you can populate the `module`_core.sv file with the core funtionalities.

---

<a id="folder-structure"></a>
## 📁 Folder Structure

- `scripts`: Python scripts to setup the environment and facilitate the steps of designing digital IPs and integrate them into an SoC. 
- `util`: lowRISC utility scripts to build documentation, regmap and use vendor functionality to fetch other repositories from github.
- `fsm_gen`: Environment to generate SystemVerilog RTL FSMs from `.txt` and `.csv` files. The `.txt` file describes the state transitions and the `.csv` file describe the outputs for each state. It supports only Moore FSMs.
- `lib`: SKY130 `.lib` files for each corner. (IHP130 to be added)
- `verilog`: Verilog models of SKY130 standard cells primitives for post-syn simulation.
- `ips`: ips collection, packages and primitives.
- `vendor`: hjson files for fetching lowrisc\_ip and lowrisc\_ibex, and patch files.
- `sw`: software for driving the ibex core in a SoC.

#### Folder generated by the SETUP step

- `data`: `.hjson` file describing the IPs. This file is also used to generate documentation and register map.
- `doc`: IP documentation.
- `model`: SystemVerilog models of other IPs of the system (ADC, DAC, Memory, ...).
- `py`: Python scripsìts folder to support the modelling of the system IPs.
- `rtl`: RTL files describing the IP submodules.
- `lint`: lint waivers.
- `tb`: Testbenches created to perform design verification of the IP.
- `sim`: `.vcd`, `.gtkw` and verilator files used to simulate and view the waveforms of the simulations.
- `syn`: Synthesis flow results.
- `signoff`: TCL scripts for Static Timing Analysis and Power Analysis.
- `ors`: OpenROAD flow input files.
- `log`: Log of the output of each step.

---

<a id="tutorial-0"></a>
## 🧪 Tutorial 0 - Whole flow

It generate an example IP, and perform the whole flow.

- `make full_tutorial`
1. Runs setup
2. Generate HJSON configurations 
3. Generate CSR registers
4. Generate documentation
5. Generate RTL core of the IP
6. Generate RTL wrapper with core and CSRs.
7. Generate a simple testbench.
8. Run lint checks.
9. Compile.
10. Simulate RTL.
11. Run synthesis trial.
12. Static Timing Analysis (STA)
13. Report STA violations
14. Estimate power
15. Run PnR flow with OpenROAD
16. Show final GDS.

Then `make clean_all` to completely clean the environment and restart from scratch.

---

<a id="tutorial-1"></a>
## 🧪 Tutorial 1 - Basic FSM

It generate an FSM example, and perform the whole flow.

- `make fsm_tutorial`
1. Runs setup
2. Copies example input files
3. Generates the FSM `.sv` and `.gv` files
4. Plots the FSM diagram
5. Copies generated `.sv` files to rtl/ folder
6. Sets up testbench
7. Generate HJSON configurations 
8. Generate documentation
9. Generate unique `.v` file
10. Run lint checks
11. Compile
12. Simulate RTL
13. View pre-synthesis
14. Run synthesis
15. Backannotate SDF
16. Perform static timing analysis (STA)
17. Report STA violations
18. Estimate power

Then `make clean_all` to completely clean the environment and restart from scratch.

---

<a id="tutorial-2"></a>
## 🧪 Tutorial 2 - Ramp ADC 

It loads a custom digital IP to implement the Ramp ADC, it uses also systemverilog analog models for the system verification.

- `make ip_tutorial TOP=pwm_ramp`
1. Load pwm\_ramp IP
2. Generate HJSON configurations 
3. Generate documentation
4. Generate unique `.v` file
5. Run lint checks
6. Compile
7. Simulate RTL with an already defined testbench
8. Plot the simulation waveforms
9. View pre-synthesis
10. Run synthesis
11. Backannotate SDF
12. Perform static timing analysis (STA)
13. Report STA violations
14. Estimate power

Then `make clean_all` to completely clean the environment and restart from scratch.

---

<a id="tutorial-3"></a>
## 🧪 Tutorial 3 - Processor-Less System On Chip

It loads a custom Processor-Less SoC, it uses the UART to configure all other peripherals. Up to now it has: UART, PWM, GPIOs and TIMERs.

- `make soc_pless TOP=tiny-soc`
1. Load soc from ips folder.
2. Generate xbar
3. Generate SoC with all IPs under rtl folder
4. Copy all the results under rtl
5. Run lint checks
6. Compile
7. Simulate RTL with a custom testbench
8. Run synthesis trial
9. Static Timing Analysis (STA)
10. Report STA violations
11. Estimate power

Then `make clean_all` to completely clean the environment and restart from scratch.

---

<a id="tutorial-4"></a>
## 🛠 Tutorial 4 - SoC flow with IBEX core

Running `make deps-soc` will automate the installation process for SoC integration.

**SoC Integration Tools**

- `riscv-toolchain`: The RISC-V compiler and toolchain required to build and run software on the IBEX core.

Then to run the tutorial:

- `make soc_ibex_tutorial`

Runs the complete top-level SoC integration and build process. This is the recommended end-to-end target for preparing and simulating the SoC.
The IP used is a custom and simple SPI\_HOST.
Steps performed:
1. **Fetch LowRISC IPs:**
 `make fetch VENDOR=lowrisc_ip`
2. **Fetch Ibex core:**
 `make fetch VENDOR=lowrisc_ibex`
3. **Generate XBAR interconnect:**
 `make xbar`
4. **Generate SoC:**
 `make soc`
5. **Run the full SoC development flow:**
 `make soc_sim soc_run`

Then CTRL-C and:

- `make soc_view TOP=spi_host`

View the waveforms. You should see 2 drivings of spi\_host signals: spi\_cs\_o, spi\_sclk\_o, spi\_sdio\_o. 

---

<a id="flow-overview"></a>
## 🔁 Flow Overview

This environment supports a complete and repeatable hardware development lifecycle, from individual IP design to full SoC integration and simulation:

1. 🧾 **CSR Definition & Documentation**
 Define Control and Status Registers using hjson, enabling auto-generation of both RTL and user-friendly documentation.

2. 🛠 **RTL Development**
 Implement hardware modules using SystemVerilog, following lowRISC coding style and modular design principles.

3. ✅ **Linting Checks**
 Automatically verify RTL quality and compliance using linting tools and formatting scripts.

4. 🔬 **Testbench Definition**
 Create module-level testbenches for simulation, supporting unit-level verification with realistic stimuli.

5. 🧪 **Functional Simulation**
 Simulate individual IPs and subsystems using open-source simulators to ensure correctness and expected behavior.

6. 🔁 **Regression Suite Definition**
 Define and run regression tests to catch functional regressions across different development stages.

7. 🏗️ **Synthesis Trials**
 Run synthesis experiments using tools like Yosys to estimate area, gate count, and synthesis feasibility.

8. ⏱ **Static Timing Analysis (STA)**
 Perform STA to evaluate setup/hold timing, slack margins, and timing closure.

9. ⚡ **Power Estimation & Analysis**
 Analyze switching activity and perform early-stage power estimation.

10. ⚡ **Place&Route with OpenROAD flow scripts**
 Perform the implementation using OpenROAD flow scripts.

11. 🧩 **SoC Integration**
Integrate verified IPs into a System-on-Chip design using a TLUL (TileLink UL) interconnect and autogenerated crossbar.

12. 🧰 **Software Driver Definition**
Define corresponding software-accessible register maps and drivers for each IP to ensure firmware interaction.

13. 🧪 **SoC Simulation**
Simulate the complete SoC to validate hardware/software co-design and system-level behavior.

---

<a id="soc-composition"></a>
## 🧩 SoC Composition

You can assemble a minimal SoC using:

- [Ibex RISC-V Core](https://github.com/lowRISC/ibex)
- RAM primitives
- UART module
- TileLink-based interconnect
- Custom or external IPs

All components are integrated with automation scripts and can be expanded or replaced as needed.

---

<a id="natural-language-make-agent"></a>

## 🤖 Natural Language Make Agent

FlexSoC includes an optional **Natural Language Make Agent** (`flexsoc_make_agent`) that provides a **single, deterministic interface** for running existing Makefile targets using natural language.

The agent does **not** replace Make and does **not** generate commands. Instead, it performs one well-defined task:

> **map a natural-language request to exactly one explicit, validated `make <target>` invocation**.

At the current stage, the agent uses **embeddings only** (no LLM reasoning in the loop) and follows a **fully auditable, rule-first pipeline**.

### What happens when you type a command

For any user input (short or verbose, English or Italian), the agent executes a **single merged flow**:

1. **Deterministic intent rules (highest priority)**
   Explicit target mentions (`make lint`, `run view`, `lancia syn`) and hard intents (`help`, `clean`, `view`) are resolved first. This guarantees predictable behavior such as:

   * `help me` → `help` (not `help_fsm`)
   * `doc` → `doc` (never `clean_doc`)
   * `pulisci la simulazione` → `clean_sim`

2. **Embedding-based intent classification (fallback)**
   If no deterministic rule applies, the user text is embedded (Ollama) and compared against the semantic definitions in `targets.json`. The best-matching target is selected using similarity scores and soft tie-breaking rules.

3. **Safety validation and execution**
   The resolved target is validated against `catalog.json`. If allowed, the agent executes **exactly one** real command:

   ```bash
   make <target>
   ```

   All executions are logged and streamed live.

### How you can use the agent

The same unified flow is exposed through multiple frontends:

* **Interactive REPL**

  ```bash
  make agent
  ```

* **Direct CLI invocation**

  ```bash
  python3 flexsoc_make_agent/router.py serve "fai lint"
  ```

* **Browser UI (Streamlit)** for local exploration

Regardless of the frontend, the internal behavior is identical.

### Design guarantees

* ❌ No arbitrary shell execution
* ❌ No probabilistic command generation
* ✅ Only predefined Make targets can run
* ✅ Deterministic routing before similarity
* ✅ Full reproducibility: every decision and execution is logged

> **Design principle**: natural language is treated as *intent*, not as code.
> The agent decides *which* Make target to run — **Make decides everything else**.

---

<a id="next-steps"></a>
## 📈 Next Steps

- Align with dvsim flow of lowRISC.
- Formal Verification with SymbiYosys.
- Support other register interface like AXI4 and AXI-Lite.
- Enhance synthesis trials with different targets (PPA).
- Better alignment in general to lowRISC flow to easisy export the result of this IP develpment flow.

---

<a id="environment-details"></a>
## 🧬 Environment Details

#### Configuration description (`config.mk`): 

#### Python interpreter version
- `PYTHON` : This line sets the Python interpreter to be used in the project. If not specified, it defaults to `python3`.

#### Project and Top Module Names

- `PRJ`: The name of the project, default is `prj`.
- `TOP`: The name of the top module in the design, default is `spi_host`.

#### Directory Structure

- `RTLDIR`: Directory for RTL (Register Transfer Level) files.
- `TBDIR`: Directory for testbench files.
- `LINTDIR`: Directory for lint waiver files.
- `REGRESSIONDIR`: Directory for testbench files ussed for regression.
- `SIMDIR`: Directory for simulation files.
- `SYNDIR`: Directory for synthesis files.
- `SIGNOFFDIR`: Directory for sign-off files.
- `MODELDIR`: Directory for model files.
- `LOGDIR`: Directory for log files.
- `DOCDIR`: Directory for documentation.
- `DATADIR`: Directory for data files.
- `VENDORDIR`: Directory for vendor hjson files and patches.
- `UTILDIR`: Directory for utility scripts.
- `SCRIPTSDIR`: Directory for additional scripts.

#### Register interface

- `REG_ITF`: Register interface, can be `tlul` or `reg_iface`.

#### Compile Tools

- `SV2V`: Tool for converting SystemVerilog to Verilog.
- `LINTER`: Tool for linting the code, default is `verilator`.
- `COMPILER`: Tool for compiling the Verilog code, default is `verilator`.
For SoC integration only `verilator`is supported.
`iverilog` can be used for the core features of the IP, without the gerister interface.

#### Linting Configuration

- `LINT_FLAGS` : This variable defines the flags used for linting the code. It includes:
- `-Wall`: Enable all warnings.
- `-Wno-fatal`: Do not treat warnings as errors.
- `--lint-only`: Only perform linting without compiling.
- `--top-module $(TOP)`: Specify the top module for linting.

#### Simulation Configuration

- `TESTBENCHES` : This variable automatically collects all SystemVerilog testbench files from the specified testbench directory.

#### Waveform Viewer Configuration

- `VIEWER`: The waveform viewer to be used, default is `gtkwave`.
- `VIEWER_FLAGS`: Flags for configuring the waveform viewer's appearance.
- `VIEWER_CONF`: Configuration file for the waveform viewer (`.gtkw` file).

#### Synthesis and Sign-off Configuration

- `YOSYS`: Tool for synthesis.
- `STA`: Static Timing Analysis tool.
- `CLK_PERIOD`: Clock period, default is to 10 time units (ns).
- `TARGET_SYN`: Target technology, default is `asic`.
- `ACTIVITY`: Activity factor for Static Power Analysis, default is 10 (10%).
- `MODULE`: The module name, default is the top module.
- `PATH_VIEW _FILE`: File for viewing path violations, default is the top module's static timing analysis results.
- `NPATHS`: Number of paths to analyze, default is 20.

#### SKY130 Libraries

- `LIBS`: A list of library files for the SKY130 technology. These libraries include:
- `sky130_fd_sc_hd__ss_100C_1v40.lib`: Fast-slow corner library at 100°C and 1.4V.
- `sky130_fd_sc_hd__tt_025C_1v80.lib`: Typical-typical corner library at 25°C and 1.8V.
- `sky130_fd_sc_hd__ff_n40C_1v95.lib`: Fast-fast corner library at -40°C and 1.95V.
- `LIB_SYN`: The library file used for synthesis, default is the typical-typical corner library at 25°C and 1.8V.
- `PRIM`: A list of Verilog primitive files used in the design. This includes:
- `primitives.v`: Standard Verilog primitives.
- `sky130_fd_sc_hd.v`: SKY130 specific primitives.

#### SoC Integration

- `VENDOR`: Vendor target to be fetched through hjson file

- `FUSESOC`: The tool used for managing and building hardware designs, specifically for the project.

- `SOC_MEMORY_MAP`: device memory map for SoC integration

#### Shell Functions

- `ECHO`: Command for printing text to the terminal.
- `MKDIR`: Command for creating directories.
- `GREP`: Command for searching text using patterns.
- `CP`: Command for copying files.
- `RM`: Command for removing files and directories.
- `FIND`: Command for searching for files in a directory hierarchy.
- `CLEAR`: Command for clearing the terminal screen.

#### Color Codes

- `ORANGE`: Color code for orange text.
- `RED`: Color code for red text.
- `GREEN`: Color code for green text.
- `YELLOW`: Color code for yellow text.
- `BLUE`: Color code for blue text.
- `RESET`: Resets the text color to default.


#### Flow description (`Makefile`): 

#### Help target

- `help`

Run a Python script to display help information about the Makefile targets related to both IP development and SoC integration.

- `help_ip`

Run a Python script to display help information about the Makefile targets related to IP development.

- `help_soc`

Run a Python script to display help information about the Makefile targets related to SoC integration.

- `help_doc`

Run a Python script to display help informations regarding the documentation generation.

- `help_fsm`

Run a Python script to display informations on how to generate systemverilog FSMs from configuration files.

#### Setup Folder Structure

- `setup`

Create the necessary directory structure for the project, including directories forconfiguration files, documentation, logs, RTL files, testbenches, simulations, synthesis, sign-off and models.

#### HJSON Template Generation

- `hjson`

Generate an HJSON template file using a Python script.

#### SystemVerilog Register Generator

- `reg`

Generate a register map from the HJSON description.

#### Markdown Generator

- `doc`

Generate Markdown files documentation from the HJSON description using a utility script.

#### IP skeleton

- `ip_start`

Generate all previous files, the core and the wrapper of a general IP.

#### Fetch vendor repo

- `fetch`

Fetch the repo defined in the hjson file under vendor folder.
Usage: make fetch VENDOR=lowrisc\_ip

#### SystemVerilog2Verilog

- `sv2v`

Perform the conversion of multiple systemverilog files into a single verilog file.

#### Linting

- `lint`

Perform linting on the generated Verilog file and logs the output.

- `lint_sv`

Perform linting on a SystemVerilog file under rtl/ directory. If the file is somewhere else you have to add RTLDIR=other\_dir. Because as default it keeps the file under the RTLDIR.
Usage: make lint\_sv TOP=filename

#### Setup testbench

- `setup_tb`

Generate the systemverilog testbench template.

#### Compilation Targets

- `compile`

Compile the testbench and the RTL files.

#### Simulation Targets

- `sim`

Simulate the testbench after compilation.

#### Viewing Waveforms

- `view`
Open the waveform viewer to visualize the simulation results.

#### Cocotb Integration

- `cocotb`

Run the Cocotb testbench located in the testbench directory.

#### Regression Testing

- `regression`

Run a Python script to perform regression tests.

#### Synthesis Targets

- `syn`

Run synthesis using Yosys and logs the output, including any warnings or errors.

- `compile_syn`

Compile the post-synthesis netlist for simulation.

- `sim_syn`

Simulate the post-synthesis netlist.

#### Static Timing Analysis (STA)

- `sta`

Perform static timing analysis and logs the results, including any warnings or errors.

#### Power Analysis

- `power`

Perform power analysis, both static and dynamic, and logs the results.

#### Path View Generation

- `path_view`

Generate a path view of the STA report.

#### SDF File Generation

- `sdf`

Generate SDF files for timing information.

#### Testbench Management

- `save_tb`

Save the current testbench file for future reference.

#### IP management

- `ip_save`

Save all files related to the ip developed under ips/ folder.

- `ip_load`

Load back in the environment the ip under ips/ folder.

#### FSM generator

- `fsm_gen`

Generate `.sv` and `.gv` files of the FSM described with `.txt` and `.csv` files under the folder `fsm_gen/inputs/`.

- `fsm_plot`

Plot the `.gv` file generated by the previous step.

#### SoC Integration

- `fsoc_init`

Initializes FuseSoC core file for the ip.

- `fsoc`

Run fusesoc.
Usage: make fsoc TARGET=lint

- `xbar_init`

Initialize the the XBAR hjson file assuming IBEX as host.

- `xbar_build`

Build the XBAR systemverilog file using tlgen.py

- `xbar`

Run xbar\_init && xbar\_build.

- `soc_build`

Generate the top-level SoC SystemVerilog file using `soc_gen.py` with `uart` as a module.

- `soc_sim`

Sets up and builds the SoC simulation environment using **FuseSoC** with **Verilator**.

- `soc_run`

Compile the `hello_world.c` using **GCC** and runs the Verilator simulation.

- `soc_view`

Open the simulation waveform (`sim.fst`) using the waveform viewer.

- `soc_flow`

Run the complete SoC development flow: build, simulate, and execute.
Equivalent to running: `make soc_build soc_sim soc_run`.

#### Basic Flow

- `ip_flow`

Run almost the whole flow, inculding reg, doc, lint, sim, syn, sdf, sta, power and view the simulation.

- `ip_flow_all`

Run the complete flow adding to `ip_flow` the generation of the hjson.

#### Cleaning Targets

- `clean_doc`

Clean up documentation files.

- `clean_log`

Clean up log files generated during the build process.

- `clean_rtl`

Remove generated `.v` RTL files.

- `clean_sim`

Remove simulation files, including VVP, VCD files and verilator directory.

- `clean_syn`

Clean up synthesis output files.

- `clean_signoff`

Remove sign-off related files.

- `clean_fsm`

Clean up files generated fsm\_gen step.

- `clean_subdir`

Clean up subdirectories related to the FSM generator.

- `clean`

Perform a comprehensive clean-up of all generated files and directories.

- `clean_all`

Remove all project directories and files, effectively resetting the project.

---

<a id="license"></a>
## 📜 License

Unless otherwise noted, everything in the repository is covered by the [Apache License](https://www.apache.org/licenses/LICENSE-2.0.html), Version 2.0.
