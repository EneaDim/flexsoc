// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vip1_tb.h for the primary calling header

#include "Vip1_tb__pch.h"

VL_ATTR_COLD void Vip1_tb___024root___eval_static(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval_static\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__ip1_tb____PVT__clk_i__0 
        = vlSymsp->TOP__ip1_tb.__PVT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__ip1_tb____PVT__rst_ni__0 
        = vlSymsp->TOP__ip1_tb.__PVT__rst_ni;
}

VL_ATTR_COLD void Vip1_tb___024root___eval_final(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval_final\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vip1_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vip1_tb___024root___eval_phase__stl(Vip1_tb___024root* vlSelf);

VL_ATTR_COLD void Vip1_tb___024root___eval_settle(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval_settle\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vip1_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/ip1_tb.sv", 6, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vip1_tb___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vip1_tb___024root___eval_triggers__stl(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval_triggers__stl\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vip1_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vip1_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vip1_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vip1_tb___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vip1_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

VL_ATTR_COLD void Vip1_tb_ip1_tb___stl_sequent__TOP__ip1_tb__0(Vip1_tb_ip1_tb* vlSelf);
VL_ATTR_COLD void Vip1_tb___024root____Vm_traceActivitySetAll(Vip1_tb___024root* vlSelf);

VL_ATTR_COLD void Vip1_tb___024root___eval_stl(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval_stl\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vip1_tb_ip1_tb___stl_sequent__TOP__ip1_tb__0((&vlSymsp->TOP__ip1_tb));
        Vip1_tb___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vip1_tb___024root___eval_phase__stl(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval_phase__stl\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vip1_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vip1_tb___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vip1_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vip1_tb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vip1_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vip1_tb___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: Internal 'ico' trigger - virtual interface member: tlul_if.__PVT__clk_i\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: Internal 'ico' trigger - virtual interface member: tlul_if.d2h\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: Internal 'ico' trigger - virtual interface member: tlul_if.h2d\n");
    }
}
#endif  // VL_DEBUG

bool Vip1_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vip1_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vip1_tb___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge ip1_tb.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge ip1_tb.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @([true] __VdynSched.evaluate())\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'act' trigger - virtual interface member: tlul_if.__PVT__clk_i\n");
    }
    if ((1U & (IData)((triggers[1U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 65 is active: Internal 'act' trigger - virtual interface member: tlul_if.d2h\n");
    }
    if ((1U & (IData)((triggers[1U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 66 is active: Internal 'act' trigger - virtual interface member: tlul_if.h2d\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vip1_tb___024root____Vm_traceActivitySetAll(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root____Vm_traceActivitySetAll\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
    vlSelfRef.__Vm_traceActivity[6U] = 1U;
}

VL_ATTR_COLD void Vip1_tb___024root___ctor_var_reset(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___ctor_var_reset\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__VvifTrigger_h100a9949__0_Vtrigm___PVT__clk_i = 0;
    vlSelf->__VvifTrigger_h100a9949__1_Vtrigm_d2h = 0;
    vlSelf->__VvifTrigger_h100a9949__2_Vtrigm_h2d = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__ip1_tb____PVT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ip1_tb____PVT__rst_ni__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
