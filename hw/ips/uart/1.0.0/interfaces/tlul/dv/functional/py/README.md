# UART functional Python

- `uart_model.py`: independent functional reference model.
- `scenarios.py`: semantic configurations, stimuli and independent expected values.
- `uart_model_tests.py`: pytest checks of the model against known answers.
- `uart_tests.py`: projects the same scenarios through CSR to RTL vectors.
- `uart_regmap.py`: generated CSR API from HJSON (never a model dependency).
- `uart_regmap_tests.py`: machine-generated CSR stress-vector producer.

`fx tests_gen` produces vectors in `../tests/`; `fx model_tests` writes
`../model_tests/summary.json` for an active run. Logs live under `logs/dv/functional/`.
The two test executors report independent outcomes; no EDA PASS is inferred.
