// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpwm_ramp_tb.h for the primary calling header

#include "Vpwm_ramp_tb__pch.h"
#include "Vpwm_ramp_tb_pwm_ramp_tb.h"

VL_INLINE_OPT void Vpwm_ramp_tb_pwm_ramp_tb___nba_sequent__TOP__pwm_ramp_tb__0(Vpwm_ramp_tb_pwm_ramp_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vpwm_ramp_tb_pwm_ramp_tb___nba_sequent__TOP__pwm_ramp_tb__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__u_pwm_ramp__DOT__pwm_counter 
        = vlSelfRef.__PVT__u_pwm_ramp__DOT__pwm_counter;
    vlSelfRef.__Vdly__duty_cycle = vlSelfRef.__PVT__duty_cycle;
    if (vlSelfRef.__PVT__rst_ni) {
        vlSelfRef.__Vdly__u_pwm_ramp__DOT__pwm_counter 
            = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_pwm_ramp__DOT__pwm_counter)));
        if ((0x3fU == (IData)(vlSelfRef.__PVT__u_pwm_ramp__DOT__pwm_counter))) {
            vlSelfRef.__Vdly__duty_cycle = (0x3fU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelfRef.__PVT__duty_cycle)));
        }
        vlSelfRef.__PVT__dut__DOT__y_prev = ((5.00000000000000010e-03 
                                              * VL_ITOR_D_I(1, (IData)(vlSelfRef.__PVT__pwm_out))) 
                                             + (9.94999999999999996e-01 
                                                * vlSelfRef.__PVT__dut__DOT__y_prev));
    } else {
        vlSelfRef.__Vdly__u_pwm_ramp__DOT__pwm_counter = 0U;
        vlSelfRef.__Vdly__duty_cycle = 0U;
        vlSelfRef.__PVT__dut__DOT__y_prev = 0.0;
    }
}

VL_INLINE_OPT void Vpwm_ramp_tb_pwm_ramp_tb___nba_sequent__TOP__pwm_ramp_tb__2(Vpwm_ramp_tb_pwm_ramp_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vpwm_ramp_tb_pwm_ramp_tb___nba_sequent__TOP__pwm_ramp_tb__2\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__pwm_out = ((IData)(vlSelfRef.__PVT__u_pwm_ramp__DOT__pwm_counter) 
                                < (IData)(vlSelfRef.__PVT__duty_cycle));
}

VL_INLINE_OPT void Vpwm_ramp_tb_pwm_ramp_tb___nba_sequent__TOP__pwm_ramp_tb__3(Vpwm_ramp_tb_pwm_ramp_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vpwm_ramp_tb_pwm_ramp_tb___nba_sequent__TOP__pwm_ramp_tb__3\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_pwm_ramp__DOT__pwm_counter = vlSelfRef.__Vdly__u_pwm_ramp__DOT__pwm_counter;
    vlSelfRef.__PVT__duty_cycle = vlSelfRef.__Vdly__duty_cycle;
}
