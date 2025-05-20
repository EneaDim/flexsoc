// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpwm_ramp_tb.h for the primary calling header

#include "Vpwm_ramp_tb__pch.h"
#include "Vpwm_ramp_tb_pwm_ramp_tb.h"

VL_ATTR_COLD void Vpwm_ramp_tb_pwm_ramp_tb___ctor_var_reset(Vpwm_ramp_tb_pwm_ramp_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vpwm_ramp_tb_pwm_ramp_tb___ctor_var_reset\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__clk_i = VL_RAND_RESET_I(1);
    vlSelf->__PVT__rst_ni = VL_RAND_RESET_I(1);
    vlSelf->__PVT__pwm_out = VL_RAND_RESET_I(1);
    vlSelf->__PVT__duty_cycle = VL_RAND_RESET_I(6);
    vlSelf->__PVT__u_pwm_ramp__DOT__pwm_counter = VL_RAND_RESET_I(6);
    vlSelf->__PVT__dut__DOT__y_prev = 0;
    vlSelf->__Vdly__u_pwm_ramp__DOT__pwm_counter = VL_RAND_RESET_I(6);
    vlSelf->__Vdly__duty_cycle = VL_RAND_RESET_I(6);
}
