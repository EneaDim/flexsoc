# Formal verification methodology

This guide describes the preferred way to write and maintain **design-specific
formal verification collateral** in a FlexSoC IP.

It focuses on the part that remains under designer control: properties that
express architectural invariants and reachability goals for the IP itself.

Automatic CSR formal verification is generated from the register description
and is intentionally kept separate from these authored design properties.

---

## 1. What belongs in authored formal collateral

For a FlexSoC IP named `<top>`, design-specific formal collateral lives under:

```text
dv/formal/properties/
├── prove/
│   └── <top>_prove.sv
└── cover/
    └── <top>_cover.sv
```

These two files are **authored source**.

They should be reviewed and maintained like RTL or a reference model.

Generated SymbiYosys configuration, solver work directories, traces, and logs
are build artifacts and should not contain the architectural intent of the
design.

A useful ownership rule is:

```text
designer
    owns assertions and covers

FlexSoC
    owns formal setup and orchestration

formal engines
    produce proof results and counterexamples
```

---

## 2. Keep CSR formal and design formal separate

FlexSoC has two complementary formal tracks.

### Automatic CSR formal

This checks semantics derived from HJSON, such as generated register behavior.

Typical targets are:

```bash
fx formal_csr_prove --setup --workdir "$WORKSPACE"
fx formal_csr_bmc --workdir "$WORKSPACE"
fx formal_csr_prove --workdir "$WORKSPACE"

fx formal_csr_cover --setup --workdir "$WORKSPACE"
fx formal_csr_cover --workdir "$WORKSPACE"
```

### Authored design formal

This checks behavior that cannot be inferred from the register description.

Typical targets are:

```bash
fx formal_prove --setup --workdir "$WORKSPACE"
fx formal_bmc --workdir "$WORKSPACE"
fx formal_prove --workdir "$WORKSPACE"

fx formal_cover --setup --workdir "$WORKSPACE"
fx formal_cover --workdir "$WORKSPACE"
```

A CSR proof does not prove a protocol bridge, datapath, handshake, arbitration
rule, or control FSM.

Likewise, a design-level proof should not duplicate automatically generated CSR
semantics unless there is a design-specific reason to do so.

---

## 3. Prefer architectural properties over implementation properties

A good property describes a contract that should remain true even if the RTL is
refactored.

Prefer:

```text
a request remains stable until accepted
an address is aligned
an output enable is always active
a granted request is removed
a FIFO never underflows
a response cannot appear without a request
```

Avoid properties that merely restate internal implementation details:

```text
state_q must equal STATE_3 here
internal_pipe_q1 must copy internal_pipe_q0
temporary counter X must have implementation-specific value Y
```

Internal-state properties can still be useful, but they should exist because
that internal state is itself part of the verification strategy, not because it
is easy to assert.

The goal is to prove **design behavior**, not freeze one RTL implementation.

---

## 4. Bind properties to the boundary that owns the behavior

When an invariant belongs to the authored design core, bind the property module
to that core.

Example:

```systemverilog
module example_design_prove (
  input logic        clk_i,
  input logic        rst_ni,
  input logic        req_o,
  input logic        gnt_i,
  input logic [31:0] addr_o
);

  // assertions

endmodule

bind example_core example_design_prove example_design_prove_i (
  .clk_i  (clk_i),
  .rst_ni (rst_ni),
  .req_o  (req_o),
  .gnt_i  (gnt_i),
  .addr_o (addr_o)
);
```

This has an important consequence:

```text
generated top wrapper may change
        ↓
authored core contract remains stable
        ↓
formal properties remain valid
```

Bind to the generated top only when the property is genuinely about the
top-level generated integration boundary.

---

## 5. Use one sampled clock for temporal history

The preferred pattern for temporal design properties is:

```systemverilog
logic past_valid = 1'b0;

always_ff @(posedge clk_i) begin
  if (past_valid) begin
    // temporal assertions using $past(...)
  end

  past_valid <= 1'b1;
end
```

Use `$past()` from a block with one explicit sampled clock.

Do not write the temporal-history block as:

```systemverilog
always_ff @(posedge clk_i or negedge rst_ni)
```

when it contains `$past()`.

The current formal frontend expects `$past()` to be evaluated from a
clocked procedural block with explicit timing.

Keep asynchronous reset behavior in the DUT; qualify the property logic
synchronously.

---

## 6. Never use `$past()` before history exists

At the first sampled clock, there is no meaningful previous sampled state.

Always guard temporal assertions.

Minimal pattern:

```systemverilog
logic past_valid = 1'b0;

always_ff @(posedge clk_i) begin
  if (past_valid) begin
    if ($past(req_o)) begin
      assert (req_o);
    end
  end

  past_valid <= 1'b1;
end
```

Without the guard, a proof can fail because the formal engine is free to choose
an arbitrary value for the nonexistent history.

`past_valid` is not a design assumption. It is bookkeeping for the property
itself.

---

## 7. Do not assume reset through an initialization read

Avoid this pattern:

```systemverilog
initial assume (!rst_ni);
```

The current formal frontend does not support reading design net state during
design initialization in this form.

More importantly, design properties should be explicit about when reset has
actually established a known architectural state.

A robust pattern is to observe reset:

```systemverilog
logic reset_seen = 1'b0;

always_ff @(posedge clk_i) begin
  if (!rst_ni) begin
    reset_seen <= 1'b1;
  end else if (reset_seen) begin
    // post-reset design properties
  end
end
```

This gives the proof a clear phase distinction:

```text
arbitrary formal startup
        ↓
reset observed
        ↓
post-reset architectural state
        ↓
temporal design properties enabled
```

---

## 8. Guard temporal assertions across reset

Do not compare a post-reset cycle with a pre-reset cycle.

A useful guard is:

```systemverilog
logic past_valid = 1'b0;
logic reset_seen = 1'b0;

always_ff @(posedge clk_i) begin
  past_valid <= 1'b1;

  if (!rst_ni) begin
    reset_seen <= 1'b1;
  end else if (reset_seen) begin
    if (past_valid && $past(reset_seen && rst_ni)) begin
      // temporal assertions
    end
  end
end
```

This means:

- a previous sample exists;
- reset has already been observed;
- both the current and previous sampled cycles are active cycles.

That prevents false counterexamples caused by arbitrary power-up state or a
reset transition.

---

## 9. Assert reset behavior directly when it is architectural

If reset defines externally visible behavior, assert it explicitly.

Example:

```systemverilog
always_ff @(posedge clk_i) begin
  if (!rst_ni) begin
    assert (!req_o);
    assert (!we_o);
  end
end
```

This is different from assuming reset.

```text
assume reset
    constrains the environment

assert reset behavior
    checks the design response
```

Use assumptions only for real environmental constraints.

---

## 10. Example: stable-until-grant protocol property

For a request/grant interface, a strong reusable invariant is:

```text
if a request was pending and not granted,
then on the next sampled cycle:

    request is still asserted
    address is unchanged
    operation type is unchanged
    write data is unchanged
    byte enable is unchanged
```

SystemVerilog pattern:

```systemverilog
if ($past(req_o && !gnt_i)) begin
  assert (req_o);
  assert (addr_o  == $past(addr_o));
  assert (we_o    == $past(we_o));
  assert (wdata_o == $past(wdata_o));
  assert (be_o    == $past(be_o));
end
```

This verifies back-pressure behavior without mentioning FSM state names.

It directly proves something an integrating SoC can rely on.

---

## 11. Example: granted request must be removed

Another useful protocol invariant is:

```systemverilog
if ($past(req_o && gnt_i)) begin
  assert (!req_o);
end
```

This property is only meaningful after the design has entered a valid
post-reset operating state.

Therefore it belongs inside the reset/history guard described earlier.

A failure on this property before reset is not evidence of an RTL bug; it is
usually evidence that the property became active on arbitrary formal startup
state.

---

## 12. Structural assertions can be simpler

Not every property needs temporal history.

Examples:

```systemverilog
assert (addr_o[1:0] == 2'b00);
assert (tx_en_o == 1'b1);
```

These can be checked in the active post-reset phase without `$past()`.

Structural invariants are valuable because they are:

- cheap to prove;
- easy to understand;
- stable across RTL refactoring;
- directly useful at integration boundaries.

---

## 13. Write cover properties separately from safety properties

`<top>_prove.sv` should contain invariants.

`<top>_cover.sv` should contain reachability goals.

Do not mix the two concepts.

### Prove asks

```text
Can this bad behavior ever happen?
```

### Cover asks

```text
Can this interesting behavior ever be reached?
```

A cover PASS is not a safety proof.

---

## 14. Keep the default qualification cover shallow

Some protocols need hundreds or thousands of cycles before an interesting
transaction completes.

Do not force every normal qualification run to reach the deepest protocol path.

A useful default cover file can establish basic reachability:

```systemverilog
always_ff @(posedge clk_i) begin
  if (!rst_ni) begin
    reset_seen <= 1'b1;
  end else if (reset_seen) begin
    cover (interface_enabled_o);
    cover (!req_o);
  end
end
```

Use a separate deeper formal task when the design needs goals such as:

```text
complete serialized frame received
full request generated
response serialized
rare recovery state reached
```

This gives two useful levels:

```text
qualification cover
    fast
    deterministic
    always run

deep design cover
    larger depth
    protocol-specific
    run when needed
```

---

## 15. Run BMC before prove

The preferred order for authored design formal is:

```bash
fx formal_prove --setup --workdir "$WORKSPACE"

fx formal_bmc \
  --workdir "$WORKSPACE"

fx formal_prove \
  --workdir "$WORKSPACE"
```

Why BMC first?

Because it quickly exposes:

- syntax/integration mistakes;
- assertions active before reset;
- incorrect assumptions;
- shallow RTL bugs;
- properties that are stronger than the intended contract.

A short counterexample is usually easier to understand than a failed unbounded
proof.

---

## 16. Run cover after the safety properties are clean

After BMC and prove:

```bash
fx formal_cover --setup \
  --workdir "$WORKSPACE"

fx formal_cover \
  --workdir "$WORKSPACE"
```

This keeps the reasoning clean:

```text
first:
    prove bad things cannot happen

then:
    demonstrate useful states are reachable
```

A reachable state does not compensate for a failed assertion.

---

## 17. Read failures in layers

Formal failures can occur at different layers.

### Layer 1 — FlexSoC task

Example:

```text
formal task failed
```

This tells you which lifecycle target failed, not necessarily why.

### Layer 2 — SymbiYosys task log

Typical path:

```text
logs/dv/formal/properties/<top>_bmc.log
```

This shows whether the failure happened during:

```text
base
prep
solver
assertion checking
witness generation
```

### Layer 3 — Yosys design compilation log

If the task says:

```text
base: ERROR: Compilation failed
```

inspect the generated `model/design.log` below the formal run directory.

That log usually contains the actionable frontend error:

```text
source file
line number
unsupported construct
syntax or bind problem
```

### Layer 4 — counterexample

A real assertion failure identifies the authored property and line:

```text
Assert failed in <top>: .../<top>_prove.sv:<line>
```

At this point, inspect:

1. whether reset/history guards are correct;
2. whether the property matches the architectural contract;
3. whether the counterexample is a reachable post-reset design behavior.

Only then decide whether the defect is in the property or RTL.

---

## 18. Distinguish proof failure from witness-tool failure

Some proof flows use one engine to find a failure and another tool to convert or
replay the counterexample.

For example:

```text
proof engine finds FAIL
        ↓
witness replay starts
        ↓
secondary solver missing
```

The missing secondary solver is not necessarily the root cause.

Always read the log in chronological order.

If the proof engine already reported an assertion failure, fix or understand
that counterexample first.

Treat solver/replay availability as the root cause only when the actual proof
has not already failed for a design reason.

---

## 19. Property modules should remain small

Prefer several clear assertions over a large verification framework.

A good property module should normally contain:

- the signals needed for the contract;
- minimal property-local history state;
- reset qualification;
- assertions;
- no unnecessary abstraction.

Example structure:

```systemverilog
module <top>_design_prove (...);
  logic past_valid = 1'b0;
  logic reset_seen = 1'b0;

  always_ff @(posedge clk_i) begin
    // reset observation
    // structural checks
    // temporal checks
  end
endmodule

bind <top>_core <top>_design_prove ...
```

Add helper logic only when it makes the property easier to understand.

---

## 20. Do not regenerate over authored properties

Once `<top>_prove.sv` and `<top>_cover.sv` contain real design properties, they
are source files.

Do not routinely run a command that recreates starter properties over them.

The normal workflow is:

```text
edit authored property
        ↓
regenerate formal configuration
        ↓
BMC
        ↓
prove
        ↓
cover
```

Generated setup is disposable.

Authored property intent is not.

---

## 21. Recommended design-formal checklist

Before calling design formal complete, verify:

```text
[ ] properties are bound to the correct design boundary
[ ] no starter/scaffold signals remain
[ ] $past() is used only from a single sampled clock block
[ ] $past() is guarded by valid history
[ ] temporal properties do not cross reset
[ ] arbitrary startup state is not mistaken for post-reset behavior
[ ] reset behavior is asserted where architecturally relevant
[ ] assumptions model only real environment constraints
[ ] protocol payload remains stable under back-pressure where required
[ ] BMC passes
[ ] prove passes
[ ] cover passes
[ ] counterexample and solver logs contain no unexplained failure
```

---

## 22. Design principle

The most useful formal property is one that another engineer can read and say:

> “Yes, this is a behavior the rest of the SoC is allowed to rely on.”

That is the target.

Formal collateral should make the IP contract more explicit, not merely make a
formal tool report green.
