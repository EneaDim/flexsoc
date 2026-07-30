# 🔗 SoC development guide

The SoC flow is where reusable IP becomes a larger system. FlexSoC treats IP
validation and SoC integration as different ownership levels: an IP owns its
internal implementation; the SoC owns composition, top-level interfaces,
software/host integration, constraints, and system-level verification/signoff.

## 1. ✅ Validate reusable IPs first

Before integration, develop or regression-test each block with the appropriate
IP guide:

- [Single-clock IP development](guide_ip_dev.md) for a new generated IP;
- [Multi-clock IP development](guide_multiclock_ip_dev.md) for domain-aware IP;
- [Existing IP development](guide_existing_ip_dev.md) for a mature reusable IP
  under `hw/ips/<top>/`.

The point of `hw/ips/` is reuse: a block that has already been verified should
not need to be reconstructed when it becomes part of a system.

## 2. ⚙️ Configure the SoC run

```bash
fx settings TOP=soc RUN_TOP=soc RUN_ID=dev HOST=uart CLOCK_MODE=single
```

The SoC run has independent top-level RTL, filelists, constraints, verification,
software, and signoff state.

## 3. ♻️ Stage reusable IPs

Use the IP-loading targets required by the system configuration. A direct load
uses:

```bash
fx ip_load --force
```

When `RUN_TOP` differs from the loaded IP `TOP`, FlexSoC stages that IP below the
SoC run's `ips/` area rather than replacing the SoC run itself.

Conceptually:

```text
hw/ips/uart/        hw/ips/cordic/
      │                    │
      └────────┬───────────┘
               ↓
        runs/soc/dev/ips/
               ↓
          SoC integration
```

## 4. 🧩 Generate SoC integration collateral

Depending on the system, the SoC flow can generate/stage crossbar, top-level,
FuseSoC, host, and software collateral. The relevant targets include:

```text
soc_start
xbar / xbar_init / xbar_build
soc / soc_stage_tops
soc_flist / soc_flow
soc_uart_gen / soc_ibex_gen
fsoc / fsoc_init
sw_soc
```

Use `fx commands` to inspect the current target set and descriptions.

## 5. 🧭 Resolve the complete SoC hierarchy

```bash
fx soc_flist --force
```

The SoC filelist uses the same Slang dependency engine as the IP flow. Starting
from the SoC top, it searches staged run IPs plus explicit shared RTL roots,
trims unreachable sources, and emits:

```text
rtl/rtl_common.f
rtl/rtl_ip.f
```

This is important for reuse: the system filelist is derived from the actual
instantiated hierarchy rather than manually concatenating every source file
from every IP.

## 6. 🔍 Lint integration

```bash
fx lint_suite
```

At SoC level, lint is checking the integration boundary as well as the blocks:
package visibility, missing connections, widths, undriven/unconnected signals,
and hierarchy consistency.

Select Slang or Verilator as required:

```bash
fx lint_suite --set LINT_TOOL=slang
fx lint_suite --set LINT_TOOL=verilator
```

## 7. 🧪 System-level verification

When the SoC uses the generated model/test flow:

```bash
fx setup_model --force
fx tests_gen --force
fx tests
fx setup_tb --force
fx setup_cocotb --force
fx sim_tests
fx cocotb_tests
```

The SoC test catalogue can combine top-level functional I/O and CSR
transactions. Its expected behavior belongs to the system, even if individual
IP internals were already tested separately.

For an HJSON-only SoC register change after model/test customization:

```bash
fx reg doc --force
fx regmap_py --force
fx tests_gen --force
```

## 8. 💻 Host/software flow

For UART-hosted SoC flows, applicable targets include:

```bash
fx soc_uart_gen
fx soc_prepare
fx soc_build_sw
fx soc_run
```

Other configurations can use the corresponding SoC generators/build steps.

## 9. 🏗️ Constraints and signoff belong to the SoC

Do not blindly reuse an IP constraint file at system level. The SoC owns the
actual clocking, integration paths, external assumptions, and system timing
budget.

```bash
fx syn sdf sta power --force
```

OpenROAD-oriented PnR can be run when required by the project.

## 10. 🔄 How IP changes propagate into a SoC

If a reusable IP changes:

```text
update and regression-test hw/ips/<ip>/
        ↓
reload/restage it into the SoC run
        ↓
regenerate soc_flist
        ↓
rerun integration lint
        ↓
rerun affected SoC verification
        ↓
rerun synthesis/signoff when implementation/timing changed
```

This is the key reuse benefit: the SoC consumes validated IP source while
FlexSoC rebuilds the integration boundary around the changed hierarchy.

See [Project lifecycle and change propagation](project_lifecycle.md) for the
same pattern across register, RTL, model, and test changes.
