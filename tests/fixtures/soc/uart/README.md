# UART CPU-driven SoC functional fixture

This directory is a complete `dv/functional/` example that can be copied into an active SoC run.

- `model/tests.py` is the single Python catalogue for all UART SoC scenarios and generates only `config.regs`, `data_in.vec`, and `data_out.vec`.
- `tests/uart_smoke/sw/` is real firmware source owned by `uart_smoke`; its Makefile decides which `.c`, `.h`, and assembly files belong to that firmware.
- `tests/uart_smoke/tb/` owns UART-specific observation and the firmware-event bridge.
- The firmware publishes `READY_RX`; `data_in.vec` waits on that event and then injects an RX frame using cycles relative to the barrier. The firmware echoes the byte and publishes PASS.

For development:

```bash
RUN="$HOME/flexsoc-workspace/runs/soc/dev"
cp -a tests/fixtures/soc/uart/. "$RUN/dv/functional/"
fx test_gen --workdir "$HOME/flexsoc-workspace" --set TEST_NAME=uart_smoke
```
