# CORDIC workspace model

This directory is the editable workspace model for the CORDIC existing-IP flow.

- `cordic_float_model.py`: readable mathematical reference.
- `cordic_fixed_model.py`: RTL-like fixed-point model using the CORDIC CSR formats.
- `model_cordic.py`: generator used by `fx tests_gen` and `fx test_gen`.
- `regmap_cordic.py`: small Python mirror of the CORDIC CSR map.

Generated tests use the standard FlexSoC layout: `config.regs`, `data_in.vec`,
and `data_out.vec`.
