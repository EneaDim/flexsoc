# UART model

The UART verification model follows the standard FlexSoC three-file split:

- `uart_model.py`: behavioral serial framing/timing reference.
- `uart_regmap.py`: generated CSR metadata/API derived from `uart.hjson`.
- `uart_tests.py`: editable test catalogue and vector generator.

`fx regmap_py --force` refreshes only `uart_regmap.py`. `fx tests_gen` executes
`uart_tests.py`, which imports both the behavioral model and the regmap.
