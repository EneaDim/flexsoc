# UART verification model

The built IP package keeps both editable sources and ready-to-run DV collateral:

- `uart_model.py`: serial framing and timing reference;
- `uart_regmap.py`: CSR API generated from `uart.hjson`;
- `uart_tests.py`: editable functional catalogue;
- `../tests/`: generated vector tests consumed by SV and cocotb testbenches.

The shared catalogue is `smoke`, `corners`, `random_seed_1`, `random_seed_2`,
`reconfig`, and `auto_toggle`. UART additionally provides `line_loopback`,
`rx_fifo`, `noise_filter`, and `parity_reconfig`.

`fx tests_gen` refreshes vectors in the active run. Use `fx regmap_py --force`
to refresh only the generated CSR API.
