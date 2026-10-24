# Parallel DSP · packed + unpacked stress test

Two **authored** SystemVerilog modules, `DSP_parallel.sv` and `DSP_parallel_lane.sv`, with 64 generated MAC lanes (configurable via `LANES`) and unpacked arrays of signed packed words.

Build **from Slang**, never from regex or a generated mock:

```bash
python scripts/rtl_viewer.py \
  --root examples/rtl_schematic_dsp_parallel \
  --top DSP_parallel \
  --file DSP_parallel.sv \
  --file DSP_parallel_lane.sv
```

Navigate into the generated stack, expand it by right-click and inspect the `sample_i[lane]`, `coeff_i[lane]` and `product_o[lane]` bindings. A partial bus binding is a dependency, **not** a proven bit-accurate mapping. Slang is required; the repository does **not** include a fabricated precompiled AST for this example.
