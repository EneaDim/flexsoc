# HJSON register-description methodology

This guide describes the preferred way to author a FlexSoC register description.

The HJSON file is **design intent**. It defines the software-visible register
contract that FlexSoC uses to generate register RTL, documentation, a Python
register map, and C driver collateral.

For an IP named `<top>`, the authored file is:

```text
data/<top>.hjson
```

Once the scaffold has been replaced with the real register description, treat
that file like RTL source. Do not regenerate over it during normal development.

---

## 1. Start from the FlexSoC scaffold

Create the workspace and initial register description with the normal setup:

```bash
fx setup hjson --force --workdir "$WORKSPACE"
```

Then edit:

```text
runs/<top>/<run-id>/data/<top>.hjson
```

The scaffold is important because it captures the HJSON shape accepted by the
current FlexSoC/regtool integration.

Prefer extending that structure instead of assembling a new file from unrelated
examples.

---

## 2. Keep the top-level structure explicit

A normal single-clock FlexSoC HJSON starts with the IP identity and descriptive
metadata:

```hjson
{
  name:               "example",
  human_name:         "Example IP",
  one_line_desc:      "Short software-visible description.",
  one_paragraph_desc: '''
    Longer description of the IP and its register-facing role.
  '''

  cip_id:             "1",
  design_spec:        "",
  dv_doc:             "",
  hw_checklist:       "",
  sw_checklist:       "",

  revisions: [{
    version:            "1.0.0",
    life_stage:         "L0",
    design_stage:       "D0",
    verification_stage: "V0",
    commit_id:          "",
    notes:              "Initial definition."
  }]

  clocking: [{ clock: "clk_i", reset: "rst_ni" }]
  bus_interfaces: [{ protocol: "tlul", direction: "device" }]
  regwidth: "32"

  registers: [
    ...
  ]
}
```

`cip_id` is required by the current register-map parser. Do not remove it when
simplifying the scaffold.

Use the project-assigned/known CIP identifier when one exists. Otherwise keep
the scaffold value until the project establishes the intended identifier rather
than inventing metadata casually.

The documentation/checklist paths may remain empty while an IP is being
developed.

---

## 3. Follow the scaffold source-file form

The canonical FlexSoC scaffold begins directly with:

```hjson
{
```

Use that form for authored register descriptions.

Do not add a partial source-license comment preamble above the HJSON merely for
style. In the current regtool integration, some output paths process source
license comments differently from RTL generation.

In particular, a file containing only an SPDX comment before the HJSON can be
accepted by register RTL generation while failing documentation or C-header
generation.

The important engineering rule is:

```text
one HJSON source
must pass every consumer
```

not merely `fx reg`.

---

## 4. Describe one clear register contract

Avoid encoding the same control in multiple registers.

If one per-pin field controls input filtering, keep one canonical field such as:

```hjson
{
  name: "INTR_CTRL",
  swaccess: "rw",
  hwaccess: "hro",
  fields: [
    {
      bits: "19:16",
      name: "EN_INPUT_FILTER",
      desc: "Enable the input filter independently for GPIO[3:0]."
    }
  ]
}
```

Do not introduce a second register carrying the same filter enable unless there
is a real architectural distinction.

Duplicated intent makes generated software APIs ambiguous and forces RTL to
choose which copy is authoritative.

---

## 5. Name every meaningful field

Prefer:

```hjson
{
  bits: "3:0",
  name: "GPIO_IN",
  desc: "Filtered input value for GPIO[3:0]."
}
```

over an unnamed multi-bit field.

Named fields give stable generated paths such as:

```systemverilog
hw2reg.data_in.gpio_in.d
reg2hw.intr_ctrl.en_rising.q
```

and stable Python/C register-map identifiers.

The HJSON field names therefore become part of the integration contract.

Choose names that remain meaningful outside the generated RTL.

---

## 6. Keep bit allocation simple and non-overlapping

Express each field with its real software-visible width.

For a four-bit GPIO:

```hjson
fields: [
  { bits: "3:0", name: "GPIO_O"  },
  { bits: "7:4", name: "GPIO_OE" }
]
```

For four independent interrupt modes:

```text
3:0    EN_RISING
7:4    EN_FALLING
11:8   EN_LVLHIGH
15:12  EN_LVLLOW
19:16  EN_INPUT_FILTER
```

Do not preserve old field widths simply because an earlier implementation used
a different GPIO width.

The register map should describe the current IP contract.

---

## 7. Choose access modes from ownership

The most useful way to select `swaccess`, `hwaccess`, and `hwext` is to ask who
owns the state.

### Software-owned configuration

Software writes the value and hardware consumes it:

```hjson
{
  name: "INTR_CTRL",
  swaccess: "rw",
  hwaccess: "hro"
}
```

Generated RTL provides hardware-facing values such as:

```systemverilog
reg2hw.intr_ctrl.en_rising.q
```

This is the normal pattern for configuration fields.

### Hardware-owned readback/status

Hardware drives a value that software reads:

```hjson
{
  name: "DATA_IN",
  swaccess: "ro",
  hwaccess: "hwo",
  fields: [...]
}
```

The authored core drives the generated `hw2reg` path:

```systemverilog
assign hw2reg.data_in.gpio_in.de = 1'b1;
assign hw2reg.data_in.gpio_in.d  = filtered_gpio;
```

Use this pattern when the software-visible value is live hardware state.

### Writable state stored in the authored core

Sometimes software writes a register, but the actual state is deliberately
stored/controlled by authored RTL.

A validated FlexSoC pattern is:

```hjson
{
  name: "DIRECT",
  swaccess: "rw",
  hwaccess: "hrw",
  hwext: "true",
  hwqe: "true",
  fields: [...]
}
```

The generated register interface then exposes the write value and write event:

```systemverilog
if (reg2hw.direct.gpio_o.qe)
  gpio_o_q <= reg2hw.direct.gpio_o.q;
```

and the authored core reports the live state back:

```systemverilog
assign hw2reg.direct.gpio_o.d = gpio_o_q;
```

Use this only when external/authored storage is intentional.

---

## 8. Use `hwqe` when the core needs a write event

A configuration value and a write event are different concepts.

For normal persistent configuration:

```systemverilog
reg2hw.cfg.enable.q
```

is often sufficient.

When the authored core must know that software wrote the field in the current
cycle, the generated interface needs the write-enable event:

```systemverilog
reg2hw.direct.gpio_o.qe
```

Declare that requirement in HJSON with the supported `hwqe` pattern.

Do not infer a write pulse by comparing old and new register values. Software is
allowed to write the same value again.

---

## 9. Write descriptions as interface documentation

The generated register documentation comes directly from HJSON.

A useful field description should answer what software needs to know:

```hjson
{
  bits: "3:0",
  name: "EN_RISING",
  desc: "Enable rising-edge interrupt detection for GPIO[3:0]."
}
```

Avoid descriptions that merely repeat the field name.

Prefer architectural meaning over implementation details.

The same HJSON is consumed by documentation and driver generation, so naming and
descriptions are part of the public engineering interface.

---

## 10. Do not over-specify reset metadata

When the normal generated reset value is sufficient, keep the field definition
small.

Example:

```hjson
{
  bits: "3:0",
  name: "GPIO_O",
  desc: "Output value for GPIO[3:0]."
}
```

Add an explicit reset value only when that reset value is part of the intended
software/hardware contract.

Do not carry old `resval` values forward mechanically.

---

## 11. Single-clock and multi-clock projects use the same local rule

A single-clock register block declares its clock/reset pair explicitly:

```hjson
clocking: [{ clock: "clk_i", reset: "rst_ni" }]
```

In the generated multi-clock FlexSoC scaffold, each register block/domain has
its own HJSON and declares the clock/reset pair relevant to that block.

The local rule remains:

```text
HJSON register block
    ↓
explicit owning clock/reset domain
```

Do not hide clock ownership inside RTL after the register contract has already
been defined.

---

## 12. Validate HJSON through all generated consumers

The minimum HJSON gate is:

```bash
fx reg doc regmap_py driver --force \
  --workdir "$WORKSPACE"
```

All four matter.

### `reg`

Checks that regtool can elaborate the register description and generate the RTL
register package/top.

Expected outputs include:

```text
rtl/<top>_reg_pkg.sv
rtl/<top>_reg_top.sv
```

### `doc`

Checks documentation generation and exercises metadata/description paths that
RTL generation alone may not exercise.

### `regmap_py`

Checks the FlexSoC HJSON parser and generates the Python register-map contract
used by functional test generation.

Expected output:

```text
dv/functional/model/<top>_regmap.py
```

### `driver`

Checks C-header generation and the FlexSoC driver-generation boundary.

Expected outputs:

```text
drivers/<top>.h
drivers/<top>.c
```

A HJSON file is not considered validated merely because `fx reg` passes.

---

## 13. Treat asymmetric failures as useful diagnostics

Different HJSON consumers exercise different parts of the toolchain.

Examples:

```text
reg fails
    → basic regtool/schema/register problem

reg passes, regmap_py fails
    → FlexSoC parser/schema contract problem

reg passes, doc/driver fail
    → metadata/source-preamble or non-RTL regtool path problem

driver alone fails
    → C-header/driver generation boundary
```

Always inspect the first actionable error from the failing consumer.

Do not rewrite the register map blindly when another consumer has already shown
that the register structure itself is valid.

---

## 14. Stop regenerating HJSON once it becomes authored

The normal lifecycle is:

```text
fx hjson / scaffold
        ↓
designer edits data/<top>.hjson
        ↓
HJSON becomes authored intent
        ↓
reg/doc/regmap/driver regenerate from it
```

After that point, do not run:

```bash
fx hjson --force
```

unless you intentionally want to discard and recreate the authored register
description.

Generated collateral is disposable.

The HJSON intent is not.

---

## 15. Recommended HJSON checklist

Before moving to authored RTL:

```text
[ ] file follows the FlexSoC scaffold top-level shape
[ ] cip_id is present
[ ] clock/reset ownership is explicit
[ ] bus interface is explicit
[ ] register width is explicit
[ ] every meaningful field is named
[ ] field ranges match the actual IP width
[ ] fields do not overlap
[ ] no duplicated controls exist
[ ] software-owned configuration uses an appropriate reg2hw pattern
[ ] hardware-owned readback has an explicit hw2reg pattern
[ ] write-event semantics use qe only when needed
[ ] descriptions explain the interface contract
[ ] fx reg passes
[ ] fx doc passes
[ ] fx regmap_py passes
[ ] fx driver passes
```

When this checklist is green, the HJSON boundary is closed and authored RTL can
be written against the generated `reg2hw`/`hw2reg` contract.

---

## 16. Design principle

A good HJSON file lets three different readers agree on the IP:

```text
software engineer
    sees a clear register API

RTL engineer
    sees a clear reg2hw/hw2reg ownership contract

verification engineer
    sees a deterministic generated register map
```

If those three interpretations differ, fix the HJSON before adding more RTL.
