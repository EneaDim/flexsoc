# CORDIC verification model

The built IP package keeps both editable sources and ready-to-run DV collateral:

- `cordic_model.py`: fixed-point behavioral reference;
- `cordic_regmap.py`: CSR API generated from `cordic.hjson`;
- `cordic_tests.py`: editable functional catalogue;
- `cordic_float_model.py`: optional mathematical cross-check;
- `../tests/`: generated vector tests consumed by SV and cocotb testbenches.

The shared catalogue is `smoke`, `corners`, `random_seed_1`, `random_seed_2`,
`reconfig`, and `auto_toggle`. CORDIC additionally provides `smoke_zero`,
`rotate_45deg`, `quadrant_sweep`, and `random_small`.

`fx tests_gen` refreshes vectors in the active run. Use `fx regmap_py --force`
to refresh only the generated CSR API.
