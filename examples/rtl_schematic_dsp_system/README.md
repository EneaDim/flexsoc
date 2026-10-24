# FlexSoC multi-file DSP schematic validation

**This is a SystemVerilog example, not a synthetic graph.** The viewer must
compile **all eight** `.sv` files with upstream `slang`, elaborate top
`dsp_system`, then derive its hierarchy, pins, dependencies and source links
from that elaborated AST. No instance-name matching or RTL regex is used.

The package file is not an instance and must not be shown as a schematic block.

| File | What it tests |
|---|---|
| `dsp_ops_pkg.sv` | Imported package enums, parameterized port type |
| `dsp_coeff_bank.sv` | Indexed coefficient register file, packed words/unpacked arrays, read generate |
| `dsp_mul_lane.sv` | Signed multiply, registered product and valid/clock/reset/enable |
| `dsp_mac_array.sv` | Eight parallel generated instances, indexed arrays, reduction loop |
| `dsp_alu.sv` | Add/sub/negate, case decision, mux with distinct A/B/S/Y pins |
| `dsp_round_sat.sv` | Saturation comparisons, sequential output stage |
| `dsp_control.sv` | Typed FSM, frame counter, control fanout |
| `dsp_system.sv` | Five interconnected child modules with differently named signals and ports |

## Elaborate and audit **all** scopes (not only top)

From the FlexSoC repository root (WSL/Linux, with `slang` installed):

```bash
python scripts/rtl_viewer.py \
  --root examples/rtl_schematic_dsp_system \
  --top dsp_system \
  --file dsp_ops_pkg.sv \
  --file dsp_coeff_bank.sv \
  --file dsp_mul_lane.sv \
  --file dsp_mac_array.sv \
  --file dsp_alu.sv \
  --file dsp_round_sat.sv \
  --file dsp_control.sv \
  --file dsp_system.sv \
  --expand-cached-instances \
  --check --strict --report workspace/reports/dsp_rtl_schematic.json
```

`--strict` fails when any elaborated module definition is not mapped to a
project-local source, any child port is unbound/unresolved, or any graph is
truncated. A pass is **structural viewer validation**, **not** simulation,
formal equivalence or bit-exact synthesis-netlist validation.

Then remove `--check --strict --report ...` and open
`http://127.0.0.1:8765` to explore. Inside `u_parallel` use the context menu
to expand the eight generated `u_mac` instances. Right-click `u_arithmetic`
to open **its own file** (`dsp_alu.sv`) in the inspector. Browse the hierarchy
via the top breadcrumb. Observe input-select `S` entering the MUX from its
**bottom** side; `A` and `B` must enter from the left, `Y` must leave right.

`rtl_viewer_mockup.html` is an **offline AST-contract fixture**, intentionally
not marked Slang-verified; only a subset of the full project is included to
exercise source links and pins without a compiler. Do not use the mockup as
proof of real RTL connectivity.

## Deliberate limitations

The graph is a **source-level RTL dependency graph**. Dynamic indices,
concatenations and casted port expressions can yield **partial** or
**unresolved** dependencies. A `case` / FSM *candidate* is not automatically
a recognized gate-level FSM. The viewer does not infer connectivity by names,
therefore an unknown port binding remains visible as unknown rather than a
fabricated wire. Tool correctness for this demo requires a real Slang run.
