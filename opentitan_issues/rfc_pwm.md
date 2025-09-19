# RFC: Phase-Aligned PWM Disable via Registered Enable

## Summary
This RFC proposes making PWM disable **phase-aligned** by **registering** the software enable input and sampling it only when the PWM is **idle**. Instead of letting the pulse-generation logic react immediately to the raw enable input, an internal registered enable is updated only during idle time. This prevents **mid-pulse truncation** when firmware clears the enable, ensuring the last active cycle completes cleanly before the output is driven to a defined safe state.

---

## 1. Problem Statement
Today the PWM output logic depends directly on the software enable input. If firmware deasserts that input during the high phase, the combinational path collapses immediately and the pulse is **cut short**, yielding an effective duty smaller than programmed. The truncated energy can disturb downstream analog filters, power stages (including complementary outputs with dead-time), and synchronized multi-channel systems. It also breaks temporal consistency across grouped channels.

---

## 2. Proposed Solution
Introduce a **registered enable** that:
- Updates on the system clock **only when the PWM is idle** (i.e., not actively asserting a pulse).
- Drives the internal “PWM active” logic in place of the raw enable input.

**Behavioral effects:**
- Disable requests arriving mid-cycle are **deferred** to the next idle boundary (end of the ongoing pulse or period, depending on topology).
- The last active period maintains the **exact programmed duty** (no short tail).
- Steady-state operation is unchanged.

Optional modes may align disable to specific boundaries (e.g., end of period, next natural toggle for center-aligned, or dead-time-safe closure for complementary outputs).

### Proposed RTL

- The modification is on **pwm_chan** module.
- 3 approaches:
    - Can become the default
    - For backwards compatibility:
        - Can be used a parameter
        - Can be used a configuration bit.
- The following code provides the solution where it becomes the default behavior.


```systemverilog
// Sample pwm_en_i only when idle
logic pwm_en_q;

always_ff @(posedge clk_i or negedge rst_ni) begin
  if (~rst_ni) begin
    pwm_en_q <= 1'b0;
  end else begin
    if (!pwm_int) begin
      pwm_en_q <= pwm_en_i; // update only when idle
    end
  end
end

assign pwm_int = (!pwm_en_q) ? 1'b0 :
                 phase_wrap ? (on_phase_exceeded | ~off_phase_exceeded) :
                               (on_phase_exceeded & ~off_phase_exceeded);
```

### Baseline (Current) RTL
```systemverilog
assign pwm_int = (!pwm_en_i) ? 1'b0 :
                 phase_wrap ? (on_phase_exceeded | ~off_phase_exceeded) :
                               (on_phase_exceeded & ~off_phase_exceeded);
```


---


## 3. Documentation Updates
- Specify that, when phase-aligned mode is selected, the enable is **sampled only when idle** and disable requests take effect at the next idle boundary.
- Describe available **alignment policies** (e.g., end-of-period, next natural toggle, dead-time-safe for complementary outputs).
- Document the **mode selector** (parameter or configuration bit), its reset value (legacy), and the **kill/fault** behavior.

---

## 4. Verification Plan

### Directed Tests
- Deassert enable at multiple phases within the high pulse; confirm no truncation in phase-aligned mode and unchanged legacy behavior when not enabled.
- Assert enable while busy; confirm effect occurs at the next idle boundary in phase-aligned mode.
- Exercise edge-aligned and center-aligned operation with and without phase wrapping.
- Validate complementary outputs with dead-time: phase-aligned closure yields the intended brake/coast behavior.

### Randomized Tests
- Sweep duty (e.g., 1%, 50%, 99%) with randomized enable/disable phases and long run sequences.
- Vary period, dead-time, and alignment modes across seeds.

### Assertions (SVA/Formal)
- **No-short-pulse:** When a disable request occurs mid-pulse under phase-aligned mode, the active pulse does not shorten relative to the programmed duty.
- **Idle-update-only:** The registered enable changes state only while the PWM is idle.
- **Legacy equivalence:** With legacy mode selected, internal behavior matches the current implementation.

---

## 5. Benefits
- Preserves **last-cycle energy**, reducing analog disturbances and avoiding unexpected ripple.
- Provides **predictable, phase-aligned** shutdown without firmware timing tricks.
- Supports **multi-channel coherence** and complementary outputs with dead-time.
- Adds minimal hardware cost and maintains a **kill/fault** path for safety.

---

## 6. Example Timing (Conceptual)
- **Legacy behavior:** Disabling during the high phase immediately truncates the current pulse, creating a shorter-than-programmed last pulse.

clk:      |‾|_|‾|_|‾|_|‾|_|‾|_|‾|_|‾|_|‾|_|‾|_|‾|_
pwm_en_i: _________________________|________________
pwm_int:  ____|‾‾‾‾‾‾‾‾ |_________|‾|_______________ (truncated)

- **Phase-aligned behavior:** Disabling during the high phase leaves the current pulse intact; the output transitions to the safe state only at the next idle point (end of pulse or end of period), then remains safe.

clk:      |‾|_|‾|_|‾|_|‾|_|‾|_|‾|_|‾|_|‾|_|‾|_|‾|_
pwm_en_i: _________________________|________________
pwm_en_q: _____________________________|____________ (updates later when idle)
pwm_int:  ____|‾‾‾‾‾‾‾‾ |_________|‾‾‾ ‾‾‾‾‾|________ (completes pulse, then idle)

---

## 7. Acceptance Criteria
- No pulse narrower than the programmed width when a disable request occurs mid-pulse (phase-aligned mode).
- The registered enable updates **only** while the PWM is idle (phase-aligned mode).
- Functional equivalence to the baseline when legacy mode is selected or when enable/disable operations occur during idle.
- Immediate safe state when the kill/fault path is asserted, independent of mode.

---

## 8. Risks & Mitigations
- **Extra latency to disable:** In phase-aligned mode, disable takes effect at the next idle boundary.  
  **Mitigation:** Keep the independent kill/fault path for emergency stop.
- **Corner cases at 0% or 100% duty:** Natural idle may not occur promptly.  
  **Mitigation:** Provide a documented alignment policy and, if needed, a watchdog/timeout to force a transition to safe.

---

## 9. Open Questions
- Should phase-aligned mode be controlled per channel or globally?
- Should be used always, with parameter setting or with configuration bit?
- What is the default **safe level** after disable for various board topologies? (It seems to be DGND as default)

