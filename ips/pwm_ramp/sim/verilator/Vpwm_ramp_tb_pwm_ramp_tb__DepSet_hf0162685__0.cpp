// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpwm_ramp_tb.h for the primary calling header

#include "Vpwm_ramp_tb__pch.h"
#include "Vpwm_ramp_tb__Syms.h"
#include "Vpwm_ramp_tb_pwm_ramp_tb.h"

VL_INLINE_OPT VlCoroutine Vpwm_ramp_tb_pwm_ramp_tb___eval_initial__TOP__pwm_ramp_tb__Vtiming__0(Vpwm_ramp_tb_pwm_ramp_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vpwm_ramp_tb_pwm_ramp_tb___eval_initial__TOP__pwm_ramp_tb__Vtiming__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__clk_i = 0U;
    while (1U) {
        co_await vlSymsp->TOP.__VdlySched.delay(0x1388ULL, 
                                                nullptr, 
                                                "tb/pwm_ramp_tb.sv", 
                                                48);
        vlSelfRef.__PVT__clk_i = (1U & (~ (IData)(vlSelfRef.__PVT__clk_i)));
    }
}

VL_INLINE_OPT VlCoroutine Vpwm_ramp_tb_pwm_ramp_tb___eval_initial__TOP__pwm_ramp_tb__Vtiming__1(Vpwm_ramp_tb_pwm_ramp_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vpwm_ramp_tb_pwm_ramp_tb___eval_initial__TOP__pwm_ramp_tb__Vtiming__1\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rst_ni = 0U;
    co_await vlSymsp->TOP.__VdlySched.delay(0x2710ULL, 
                                            nullptr, 
                                            "tb/pwm_ramp_tb.sv", 
                                            70);
    vlSelfRef.__PVT__rst_ni = 1U;
    co_await vlSymsp->TOP.__VdlySched.delay(0x2710ULL, 
                                            nullptr, 
                                            "tb/pwm_ramp_tb.sv", 
                                            72);
    VL_WRITEF_NX("\nRunning...\n\n",0);
    co_await vlSymsp->TOP.__VdlySched.delay(0x3b9aca00ULL, 
                                            nullptr, 
                                            "tb/pwm_ramp_tb.sv", 
                                            89);
    VL_WRITEF_NX("Coverage: 100%%\n\nEnd.\n\n",0);
    VL_FINISH_MT("tb/pwm_ramp_tb.sv", 96, "");
}

VL_INLINE_OPT void Vpwm_ramp_tb_pwm_ramp_tb___act_sequent__TOP__pwm_ramp_tb__0(Vpwm_ramp_tb_pwm_ramp_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vpwm_ramp_tb_pwm_ramp_tb___act_sequent__TOP__pwm_ramp_tb__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__pwm_ramp_tb__tl_if.__PVT__clk_i = vlSelfRef.__PVT__clk_i;
    vlSymsp->TOP.__VvifTrigger_h100a9299__0 = 1U;
}
