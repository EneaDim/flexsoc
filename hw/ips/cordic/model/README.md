# CORDIC model

The CORDIC verification collateral follows the standard FlexSoC three-file split:

- `cordic_model.py`: canonical RTL-like fixed-point behavioral model used by the tests.
- `cordic_regmap.py`: generated CSR metadata/API derived from `cordic.hjson`.
- `cordic_tests.py`: editable test catalogue and vector generator.

`cordic_float_model.py` is kept as an optional high-level mathematical reference. It is useful for analysis and cross-checks, but the generated RTL-facing expectations come from `cordic_model.py` so they match the fixed-point implementation.

`fx regmap_py --force` refreshes only `cordic_regmap.py`. `fx tests_gen` executes
`cordic_tests.py`, which imports the canonical behavioral model and the regmap.
