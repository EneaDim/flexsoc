// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpwm_ramp_tb.h for the primary calling header

#ifndef VERILATED_VPWM_RAMP_TB_PWM_RAMP_TB_H_
#define VERILATED_VPWM_RAMP_TB_PWM_RAMP_TB_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vpwm_ramp_tb_tlul_if;


class Vpwm_ramp_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vpwm_ramp_tb_pwm_ramp_tb final : public VerilatedModule {
  public:
    // CELLS
    Vpwm_ramp_tb_tlul_if* tl_if;

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __PVT__clk_i;
    CData/*0:0*/ __PVT__rst_ni;
    CData/*0:0*/ __PVT__pwm_out;
    CData/*5:0*/ __PVT__duty_cycle;
    CData/*5:0*/ __PVT__u_pwm_ramp__DOT__pwm_counter;
    CData/*5:0*/ __Vdly__u_pwm_ramp__DOT__pwm_counter;
    CData/*5:0*/ __Vdly__duty_cycle;
    double __PVT__dut__DOT__y_prev;

    // INTERNAL VARIABLES
    Vpwm_ramp_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpwm_ramp_tb_pwm_ramp_tb(Vpwm_ramp_tb__Syms* symsp, const char* v__name);
    ~Vpwm_ramp_tb_pwm_ramp_tb();
    VL_UNCOPYABLE(Vpwm_ramp_tb_pwm_ramp_tb);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
