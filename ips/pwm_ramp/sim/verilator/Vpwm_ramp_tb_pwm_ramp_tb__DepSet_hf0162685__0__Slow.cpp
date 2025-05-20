// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpwm_ramp_tb.h for the primary calling header

#include "Vpwm_ramp_tb__pch.h"
#include "Vpwm_ramp_tb__Syms.h"
#include "Vpwm_ramp_tb_pwm_ramp_tb.h"

VL_ATTR_COLD void Vpwm_ramp_tb_pwm_ramp_tb___eval_initial__TOP__pwm_ramp_tb(Vpwm_ramp_tb_pwm_ramp_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vpwm_ramp_tb_pwm_ramp_tb___eval_initial__TOP__pwm_ramp_tb\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<6>/*191:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x72616d70U;
    __Vtemp_1[2U] = 0x70776d5fU;
    __Vtemp_1[3U] = 0x756d705fU;
    __Vtemp_1[4U] = 0x696d2f64U;
    __Vtemp_1[5U] = 0x73U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(6, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
}
