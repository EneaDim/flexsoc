# FlexSoC Quick Flow Guide (`fx`)

This guide assumes the M1→M4 patches plus the small M6 CLI patch are applied.
It shows the commands a normal user would run after activating the virtual environment.

## 1. Activate the environment

```bash
cd ~/github/flexsoc
make install
source .venv/bin/activate

export RUN_ID="quick_$(date +%Y%m%d_%H%M%S)"
fx settings --reset
fx settings --set RUN_ID="$RUN_ID" --set HOST=uart
fx smoke --json
```

Use dry-run first when you want to preview a flow:

```bash
fx setup hjson reg --dry-run --script --set TOP=demo
```

## 2. IP development from scratch

```bash
fx settings --set TOP=quick_ip --set RUN_TOP=quick_ip
fx setup hjson reg doc rtl_stub flist setup_tb --force
```

Optional EDA steps, if the tools are installed:

```bash
fx lint sim
fx syn sta power
fx setup_pnr pnr
```

## 3. Load an existing IP and run the flow

Example with `cordic` from `hw/ips/cordic`:

```bash
fx settings --set TOP=cordic --set RUN_TOP=cordic
fx ip_load flist setup_tb --force
```

Optional EDA steps:

```bash
fx lint sim
fx syn sta power
fx setup_pnr pnr
```

## 4. Build a UART-host SoC

Load the IPs into the `soc_uart` run:

```bash
fx ip_load --force --set TOP=uart-master --set LOAD_AS=uart --set RUN_TOP=soc_uart
fx ip_load --force --set TOP=gpio        --set RUN_TOP=soc_uart
fx ip_load --force --set TOP=rv_timer    --set RUN_TOP=soc_uart
fx ip_load --force --set TOP=pwm         --set RUN_TOP=soc_uart
```

Generate the SoC:

```bash
fx soc_uart_gen \
  --set TOP=soc \
  --set RUN_TOP=soc_uart \
  --set HOST=uart \
  --set SOC_CFG_MODE=builtin
```

Build software, build the simulator, and run it:

```bash
fx soc_build_sw soc_sim soc_run \
  --set TOP=soc \
  --set RUN_TOP=soc_uart \
  --set HOST=uart \
  --set SOC_CFG_MODE=builtin
```

View the waveform, if generated:

```bash
fx soc_view --set TOP=soc --set RUN_TOP=soc_uart --set HOST=uart
```

## 5. Build an Ibex-host SoC

Fetch the required vendor dependencies:

```bash
fx fetch --set VENDOR=lowrisc_ip
fx fetch --set VENDOR=lowrisc_ibex
```

Load the IPs into the `soc_ibex` run:

```bash
fx ip_load --force --set TOP=uart     --set RUN_TOP=soc_ibex
fx ip_load --force --set TOP=gpio     --set RUN_TOP=soc_ibex
fx ip_load --force --set TOP=rv_timer --set RUN_TOP=soc_ibex
fx ip_load --force --set TOP=pwm      --set RUN_TOP=soc_ibex
fx ip_load --force --set TOP=spi_host --set RUN_TOP=soc_ibex
```

Generate the SoC:

```bash
fx soc_ibex_gen \
  --set TOP=soc \
  --set RUN_TOP=soc_ibex \
  --set HOST=ibex \
  --set SOC_CFG_MODE=builtin
```

Build software, build the simulator, and run it:

```bash
fx soc_build_sw soc_sim soc_run \
  --set TOP=soc \
  --set RUN_TOP=soc_ibex \
  --set HOST=ibex \
  --set SOC_CFG_MODE=builtin
```

View the waveform, if generated:

```bash
fx soc_view --set TOP=soc --set RUN_TOP=soc_ibex --set HOST=ibex
```

## 6. Useful checks

```bash
fx commands
fx soc_uart_gen --info
fx soc_ibex_gen --info
fx setup hjson reg --dry-run --script --set TOP=demo
```

If a command fails, rerun it with captured output:

```bash
fx sim --capture
fx soc_run --capture --set TOP=soc --set RUN_TOP=soc_uart --set HOST=uart
```
