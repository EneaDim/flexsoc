// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vip1_tb.h for the primary calling header

#include "Vip1_tb__pch.h"

VL_ATTR_COLD void Vip1_tb_ip1_tb___eval_initial__TOP__ip1_tb(Vip1_tb_ip1_tb* vlSelf);
VlCoroutine Vip1_tb_ip1_tb___eval_initial__TOP__ip1_tb__Vtiming__0(Vip1_tb_ip1_tb* vlSelf);
VlCoroutine Vip1_tb_ip1_tb___eval_initial__TOP__ip1_tb__Vtiming__1(Vip1_tb_ip1_tb* vlSelf);

void Vip1_tb___024root___eval_initial(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval_initial\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vip1_tb_ip1_tb___eval_initial__TOP__ip1_tb((&vlSymsp->TOP__ip1_tb));
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vip1_tb_ip1_tb___eval_initial__TOP__ip1_tb__Vtiming__0((&vlSymsp->TOP__ip1_tb));
    Vip1_tb_ip1_tb___eval_initial__TOP__ip1_tb__Vtiming__1((&vlSymsp->TOP__ip1_tb));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vip1_tb___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vip1_tb___024root___eval_triggers__ico(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval_triggers__ico\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffff7ULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | ((QData)((IData)(vlSelfRef.__VvifTrigger_h100a9949__2_Vtrigm_h2d)) 
                                               << 3U));
    vlSelfRef.__VvifTrigger_h100a9949__2_Vtrigm_h2d = 0U;
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffbULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | ((QData)((IData)(vlSelfRef.__VvifTrigger_h100a9949__1_Vtrigm_d2h)) 
                                               << 2U));
    vlSelfRef.__VvifTrigger_h100a9949__1_Vtrigm_d2h = 0U;
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffdULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | ((QData)((IData)(vlSelfRef.__VvifTrigger_h100a9949__0_Vtrigm___PVT__clk_i)) 
                                               << 1U));
    vlSelfRef.__VvifTrigger_h100a9949__0_Vtrigm___PVT__clk_i = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vip1_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vip1_tb___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___trigger_anySet__ico\n"); );
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

void Vip1_tb_ip1_tb___ico_comb__TOP__ip1_tb__0(Vip1_tb_ip1_tb* vlSelf);

void Vip1_tb___024root___eval_ico(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval_ico\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x000000000000000fULL & vlSelfRef.__VicoTriggered
         [0U])) {
        Vip1_tb_ip1_tb___ico_comb__TOP__ip1_tb__0((&vlSymsp->TOP__ip1_tb));
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
}

bool Vip1_tb___024root___eval_phase__ico(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval_phase__ico\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vip1_tb___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vip1_tb___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vip1_tb___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vip1_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vip1_tb___024root___eval_triggers__act(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval_triggers__act\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[1U] = ((0xfffffffffffffffbULL 
                                      & vlSelfRef.__VactTriggered
                                      [1U]) | ((QData)((IData)(vlSelfRef.__VvifTrigger_h100a9949__2_Vtrigm_h2d)) 
                                               << 2U));
    vlSelfRef.__VvifTrigger_h100a9949__2_Vtrigm_h2d = 0U;
    vlSelfRef.__VactTriggered[1U] = ((0xfffffffffffffffdULL 
                                      & vlSelfRef.__VactTriggered
                                      [1U]) | ((QData)((IData)(vlSelfRef.__VvifTrigger_h100a9949__1_Vtrigm_d2h)) 
                                               << 1U));
    vlSelfRef.__VvifTrigger_h100a9949__1_Vtrigm_d2h = 0U;
    vlSelfRef.__VactTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VactTriggered
                                      [1U]) | (IData)((IData)(vlSelfRef.__VvifTrigger_h100a9949__0_Vtrigm___PVT__clk_i)));
    vlSelfRef.__VvifTrigger_h100a9949__0_Vtrigm___PVT__clk_i = 0U;
    vlSelfRef.__VactTriggered[0U] = VL_EXTEND_QI(64,4, 
                                                 (((vlSelfRef.__VdynSched.evaluate() 
                                                    << 3U) 
                                                   | (vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                      << 2U)) 
                                                  | ((((~ (IData)(vlSymsp->TOP__ip1_tb.__PVT__rst_ni)) 
                                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ip1_tb____PVT__rst_ni__0)) 
                                                      << 1U) 
                                                     | ((IData)(vlSymsp->TOP__ip1_tb.__PVT__clk_i) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ip1_tb____PVT__clk_i__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__ip1_tb____PVT__clk_i__0 
        = vlSymsp->TOP__ip1_tb.__PVT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__ip1_tb____PVT__rst_ni__0 
        = vlSymsp->TOP__ip1_tb.__PVT__rst_ni;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vip1_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    vlSelfRef.__VdynSched.doPostUpdates();
}

bool Vip1_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

void Vip1_tb_ip1_tb___act_sequent__TOP__ip1_tb__0(Vip1_tb_ip1_tb* vlSelf);

void Vip1_tb___024root___eval_act(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval_act\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        Vip1_tb_ip1_tb___act_sequent__TOP__ip1_tb__0((&vlSymsp->TOP__ip1_tb));
    }
}

void Vip1_tb_ip1_tb___nba_comb__TOP__ip1_tb__0(Vip1_tb_ip1_tb* vlSelf);
void Vip1_tb_ip1_tb___nba_sequent__TOP__ip1_tb__1(Vip1_tb_ip1_tb* vlSelf);
void Vip1_tb_ip1_tb___nba_comb__TOP__ip1_tb__1(Vip1_tb_ip1_tb* vlSelf);

void Vip1_tb___024root___eval_nba(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval_nba\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vip1_tb_ip1_tb___act_sequent__TOP__ip1_tb__0((&vlSymsp->TOP__ip1_tb));
    }
    if ((7ULL & vlSelfRef.__VnbaTriggered[1U])) {
        Vip1_tb_ip1_tb___nba_comb__TOP__ip1_tb__0((&vlSymsp->TOP__ip1_tb));
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vip1_tb_ip1_tb___nba_sequent__TOP__ip1_tb__1((&vlSymsp->TOP__ip1_tb));
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if (((7ULL & vlSelfRef.__VnbaTriggered[1U]) | (3ULL 
                                                   & vlSelfRef.__VnbaTriggered
                                                   [0U]))) {
        Vip1_tb_ip1_tb___nba_comb__TOP__ip1_tb__1((&vlSymsp->TOP__ip1_tb));
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

void Vip1_tb___024root___timing_resume(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___timing_resume\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdynSched.resume();
    }
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vip1_tb___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 2> &out, const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((2U > n));
}

bool Vip1_tb___024root___eval_phase__act(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval_phase__act\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vip1_tb___024root___eval_triggers__act(vlSelf);
    Vip1_tb___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vip1_tb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        Vip1_tb___024root___timing_resume(vlSelf);
        Vip1_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vip1_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 2> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((2U > n));
}

bool Vip1_tb___024root___eval_phase__nba(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval_phase__nba\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vip1_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vip1_tb___024root___eval_nba(vlSelf);
        Vip1_tb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vip1_tb___024root___eval(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vip1_tb___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/ip1_tb.sv", 6, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vip1_tb___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vip1_tb___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/ip1_tb.sv", 6, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vip1_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/ip1_tb.sv", 6, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vip1_tb___024root___eval_phase__act(vlSelf));
    } while (Vip1_tb___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vip1_tb___024root___eval_debug_assertions(Vip1_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root___eval_debug_assertions\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
