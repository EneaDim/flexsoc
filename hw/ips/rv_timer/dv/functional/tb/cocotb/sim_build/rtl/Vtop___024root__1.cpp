// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VicoTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_ico
            if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
                Vtop___024root___ico_sequent__TOP__0(vlSelf);
            }
        }
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_triggers_vec__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                         << 0x0000000cU) 
                                                        | ((((((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__rst_ni)) 
                                                               & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__rst_ni__0)) 
                                                              << 3U) 
                                                             | (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__clk_i) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__clk_i__0))) 
                                                                << 2U)) 
                                                            | ((((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__rst_ni)) 
                                                                 & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__rst_ni__0)) 
                                                                << 1U) 
                                                               | ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__clk_i__0))))) 
                                                           << 8U)) 
                                                       | (((((((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__rst_ni)) 
                                                               & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__rst_ni__0)) 
                                                              << 3U) 
                                                             | (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__clk_i) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__clk_i__0))) 
                                                                << 2U)) 
                                                            | ((((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__rst_ni)) 
                                                                 & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__rst_ni__0)) 
                                                                << 1U) 
                                                               | ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__clk_i__0))))) 
                                                           << 4U) 
                                                          | (((((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__rst_ni)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__rst_ni__0)) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__clk_i__0))) 
                                                                 << 2U)) 
                                                             | ((((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__rst_ni)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__rst_ni__0)) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__clk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__clk_i__0))))))) 
                                                      << 0x00000010U) 
                                                     | ((((((((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__rst_ni)) 
                                                              & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__rst_ni__0)) 
                                                             << 3U) 
                                                            | (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__clk_i) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__clk_i__0))) 
                                                               << 2U)) 
                                                           | ((((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__rst_ni)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__rst_ni__0)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__clk_i) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__clk_i__0))))) 
                                                          << 0x0000000cU) 
                                                         | ((((((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rst_ni)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rst_ni__0)) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__clk_i__0))) 
                                                                 << 2U)) 
                                                             | ((((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__rst_ni)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__rst_ni__0)) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__clk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__clk_i__0))))) 
                                                            << 8U)) 
                                                        | (((((((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__rst_ni)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__rst_ni__0)) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__clk_i__0))) 
                                                                 << 2U)) 
                                                             | ((((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__rst_ni)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__rst_ni__0)) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__clk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__clk_i__0))))) 
                                                            << 4U) 
                                                           | (((((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__rst_ni)) 
                                                                 & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__rst_ni__0)) 
                                                                << 3U) 
                                                               | (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__clk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__clk_i__0))) 
                                                                  << 2U)) 
                                                              | ((((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__rst_ni)) 
                                                                   & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__rst_ni__0)) 
                                                                  << 1U) 
                                                                 | ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__clk_i) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__clk_i__0))))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__clk_i__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__rst_ni__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__clk_i__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__rst_ni__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__clk_i__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__rst_ni__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__clk_i__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__rst_ni__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__clk_i__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__rst_ni__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__clk_i__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rst_ni__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__clk_i__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__rst_ni__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__clk_i__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__rst_ni__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__clk_i__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__rst_ni__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__clk_i__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__rst_ni__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__clk_i__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__rst_ni__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__clk_i__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__rst_ni__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__clk_i__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__rst_ni__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__clk_i__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__rst_ni__0 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__rst_ni;
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
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

void Vtop___024root___nba_sequent__TOP__13(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__13\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_0;
    __VdfgRegularize_h6e95ff9d_0_0 = 0;
    // Body
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rst_ni) {
        if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__a_ack) {
            ++(vlSelf->__Vcoverage[4213]);
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__outstanding_q = 1U;
        } else if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__d_ack) {
            ++(vlSelf->__Vcoverage[4211]);
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__outstanding_q = 0U;
        } else {
            ++(vlSelf->__Vcoverage[4212]);
        }
    } else {
        ++(vlSelf->__Vcoverage[4214]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__outstanding_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[4215]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[4216]);
    }
    ++(vlSelf->__Vcoverage[4217]);
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rst_ni) {
        if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__a_ack) {
            if ((((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_i) 
                  | (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal)) 
                 | (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__wr_req))) {
                ++(vlSelf->__Vcoverage[4232]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____VlemCond_1 = 0xffffffffU;
            } else {
                ++(vlSelf->__Vcoverage[4233]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____VlemCond_1 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata_i;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata_q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____VlemCond_1;
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_q 
                = ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_i) 
                   | (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal));
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__wr_req) {
                ++(vlSelf->__Vcoverage[4228]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal) {
                ++(vlSelf->__Vcoverage[4229]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_i) {
                ++(vlSelf->__Vcoverage[4230]);
            }
            if ((1U & (((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_i)) 
                        & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal))) 
                       & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__wr_req))))) {
                ++(vlSelf->__Vcoverage[4231]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal) {
                ++(vlSelf->__Vcoverage[4234]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_i) {
                ++(vlSelf->__Vcoverage[4235]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_i)) 
                       & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal))))) {
                ++(vlSelf->__Vcoverage[4236]);
            }
            ++(vlSelf->__Vcoverage[4237]);
        } else {
            ++(vlSelf->__Vcoverage[4238]);
        }
    } else {
        ++(vlSelf->__Vcoverage[4239]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata_q = 0U;
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[4240]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[4241]);
    }
    ++(vlSelf->__Vcoverage[4242]);
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rst_ni) {
        if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__a_ack) {
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rd_req) {
                ++(vlSelf->__Vcoverage[4220]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____VlemCond_0 = 1U;
            } else {
                ++(vlSelf->__Vcoverage[4221]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____VlemCond_0 = 0U;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqid_q 
                = (0x000000ffU & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                   << 4U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[2U] 
                                             >> 0x0000001cU)));
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqsz_q 
                = (3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                         >> 4U));
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rspop_q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____VlemCond_0;
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rd_req) {
                ++(vlSelf->__Vcoverage[4218]);
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rd_req)))) {
                ++(vlSelf->__Vcoverage[4219]);
            }
            ++(vlSelf->__Vcoverage[4222]);
        } else {
            ++(vlSelf->__Vcoverage[4223]);
        }
    } else {
        ++(vlSelf->__Vcoverage[4224]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqid_q = 0U;
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqsz_q = 0U;
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rspop_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[4225]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[4226]);
    }
    ++(vlSelf->__Vcoverage[4227]);
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__outstanding_q) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__outstanding_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4014, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__outstanding_q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__outstanding_q);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__outstanding_q 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__outstanding_q;
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__outstanding_q)))) {
        ++(vlSelf->__Vcoverage[4375]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__outstanding_q)) 
               & (~ (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                     >> 0x0000000cU))))) {
        ++(vlSelf->__Vcoverage[4376]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__outstanding_q) {
        ++(vlSelf->__Vcoverage[4378]);
    }
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata_q 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__rdata_q))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4084, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata_q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__rdata_q);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__rdata_q 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata_q;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata_q;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_q) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__error_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4148, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__error_q);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__error_q 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_q;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_q;
    if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqid_q) 
                ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__reqid_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4162, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqid_q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__reqid_q);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__reqid_q 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqid_q;
    }
    if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqsz_q) 
                ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__reqsz_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4178, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqsz_q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__reqsz_q);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__reqsz_q 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqsz_q;
    }
    if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rspop_q) 
                ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__rspop_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4182, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rspop_q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__rspop_q);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__rspop_q 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rspop_q;
    }
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__rdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4020, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__rdata);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__rdata 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4150, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__error);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__error 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
        = ((0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U]) 
           | (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error) 
               << 1U) | (1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__outstanding_q)))));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
        = ((0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U]) 
           | ((IData)((((QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                        << 0x00000029U) | (((QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                            << 0x00000021U) 
                                           | (QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata))))) 
              << 0x00000010U));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
        = ((0xc0000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U]) 
           | (((IData)((((QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                         << 0x00000029U) | (((QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                             << 0x00000021U) 
                                            | (QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata))))) 
               >> 0x00000010U) | ((IData)(((((QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                             << 0x00000029U) 
                                            | (((QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                << 0x00000021U) 
                                               | (QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata)))) 
                                           >> 0x00000020U)) 
                                  << 0x00000010U)));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
        = ((0x3fffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U]) 
           | ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rspop_q) 
              << 0x0000001eU));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
        = (3U & ((0x3ffffffeU & ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__outstanding_q) 
                                 << 1U)) | ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rspop_q) 
                                            >> 2U)));
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4243, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[2U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[2U] 
            = ((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[2U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
                        << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[2U] 
                          << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4245, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0x3fffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0xc0000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[2U] 
            = ((2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[2U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                        << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                          << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4251, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xc7ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x38000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                        << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                          << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4257, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xf9ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x06000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4261, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xfe01ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x01fe0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U]));
    }
    if ((0x00010000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4277, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                >> 0x00000010U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xfffeffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x00010000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U]));
    }
    if ((0U != (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                  << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                    << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4279, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                 >> 9U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4343, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                 >> 9U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U] 
                                              >> 9U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xffff01ffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0x0000fe00U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                 >> 2U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4357, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                 >> 2U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U] 
                                              >> 2U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffe03U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0x000001fcU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U]));
    }
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4371, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffffdU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U]));
    }
    if ((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4373, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o_pre[0U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U]));
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[2U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__unused_tl 
        = (1U & VL_REDXOR_32(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U]) 
                              ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U])));
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4389, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
            = ((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                        << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                          << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4391, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0x3fffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0xc0000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
            = ((2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                          << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4397, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xc7ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x38000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                          << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4403, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xf9ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x06000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4407, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xfe01ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x01fe0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0x00010000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4423, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                >> 0x00000010U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xfffeffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x00010000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                  << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                    << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4425, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 9U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4489, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 9U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                              >> 9U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xffff01ffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0x0000fe00U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 2U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4503, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 2U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                              >> 2U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffe03U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0x000001fcU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4517, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffdU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4519, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U];
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__unused_tl) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4653, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__unused_tl, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__unused_tl;
    }
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4521, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4523, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4529, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4535, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4539, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4555, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4557, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4621, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4635, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4649, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4651, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[2U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U];
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[2U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3722, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3724, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3730, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 3736, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3740, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3756, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 3758, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 3822, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 3836, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3850, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3852, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U]));
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[2U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[2U];
    if ((IData)(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                  >> 0x0000000cU) & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U]))) {
        ++(vlSelf->__Vcoverage[4192]);
    }
    if ((1U & (~ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U]))) {
        ++(vlSelf->__Vcoverage[4193]);
    }
    if ((1U & (~ (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                  >> 0x0000000cU)))) {
        ++(vlSelf->__Vcoverage[4194]);
    }
    if ((IData)(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[2U] 
                  >> 1U) & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[0U]))) {
        ++(vlSelf->__Vcoverage[4195]);
    }
    if ((1U & (~ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[0U]))) {
        ++(vlSelf->__Vcoverage[4196]);
    }
    if ((1U & (~ (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[2U] 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[4197]);
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__d_ack 
        = (IData)(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[2U] 
                    >> 1U) & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[0U]));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__a_ack 
        = (IData)(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                    >> 0x0000000cU) & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U]));
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[2U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2576, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[2U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[2U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[2U] 
            = ((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[2U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[2U] 
                        << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[2U] 
                          << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 2578, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
            = ((0x3fffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U]) 
               | (0xc0000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[2U] 
            = ((2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[2U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                        << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                          << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 2584, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
            = ((0xc7ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U]) 
               | (0x38000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                        << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                          << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 2590, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
            = ((0xf9ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U]) 
               | (0x06000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2594, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
            = ((0xfe01ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U]) 
               | (0x01fe0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U]));
    }
    if ((0x00010000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2610, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                >> 0x00000010U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
            = ((0xfffeffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U]) 
               | (0x00010000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U]));
    }
    if ((0U != (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                  << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                    << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2612, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U] 
            = ((0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U]) 
               | (0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U] 
            = ((0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[1U]) 
               | (0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                 >> 9U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 2676, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                 >> 9U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U] 
                                              >> 9U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U] 
            = ((0xffff01ffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U]) 
               | (0x0000fe00U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                 >> 2U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 2690, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                 >> 2U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U] 
                                              >> 2U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U] 
            = ((0xfffffe03U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U]) 
               | (0x000001fcU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U]));
    }
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2704, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U] 
            = ((0xfffffffdU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U]));
    }
    if ((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2706, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U] 
            = ((0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_reg_d2h[0U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U]));
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[2U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[2U];
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__d_ack) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__d_ack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4018, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__d_ack, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__d_ack);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__d_ack 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__d_ack;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__a_ack) 
         & (0x0200U == (0x0e00U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U])))) {
        ++(vlSelf->__Vcoverage[4198]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__a_ack) 
         & (0U == (0x0e00U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U])))) {
        ++(vlSelf->__Vcoverage[4199]);
    }
    if (((0U != (7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                       >> 9U))) & (1U != (7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                                >> 9U))))) {
        ++(vlSelf->__Vcoverage[4200]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__a_ack)))) {
        ++(vlSelf->__Vcoverage[4201]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__a_ack) 
         & (0x0800U == (0x0e00U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U])))) {
        ++(vlSelf->__Vcoverage[4202]);
    }
    if ((4U != (7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                      >> 9U)))) {
        ++(vlSelf->__Vcoverage[4203]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__a_ack)))) {
        ++(vlSelf->__Vcoverage[4204]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__a_ack) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__a_ack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4016, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__a_ack, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__a_ack);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__a_ack 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__a_ack;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rd_req 
        = ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__a_ack) 
           & (0x0800U == (0x0e00U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U])));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__wr_req 
        = ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__a_ack) 
           & ((0U == (7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                                >> 9U)))));
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[2U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2708, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[2U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[2U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[2U] 
            = ((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[2U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[2U] 
                        << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[2U] 
                          << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 2710, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0x3fffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0xc0000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[2U] 
            = ((2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[2U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                        << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                          << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 2716, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xc7ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x38000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                        << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                          << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 2722, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xf9ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x06000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2726, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xfe01ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x01fe0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U]));
    }
    if ((0x00010000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2742, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                >> 0x00000010U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xfffeffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x00010000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                  << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                    << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2744, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                 >> 9U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 2808, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                 >> 9U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                              >> 9U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xffff01ffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0x0000fe00U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                 >> 2U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 2822, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                 >> 2U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                              >> 2U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffe03U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0x000001fcU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U]));
    }
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2836, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffffdU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U]));
    }
    if ((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2838, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U]));
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[2U];
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rd_req) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__rd_req))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4188, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rd_req, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__rd_req);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__rd_req 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rd_req;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__wr_req) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__wr_req))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4190, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__wr_req, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__wr_req);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__wr_req 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__wr_req;
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__wr_req) {
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__addr_align_err 
            = (0U != (3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                            >> 0x0000001cU)));
        if ((0x20000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[1U])) {
            ++(vlSelf->__Vcoverage[4383]);
        }
        if ((0x10000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[1U])) {
            ++(vlSelf->__Vcoverage[4384]);
        }
        if ((IData)((0U == (0x30000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[1U])))) {
            ++(vlSelf->__Vcoverage[4385]);
        }
        ++(vlSelf->__Vcoverage[4386]);
    } else {
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__addr_align_err = 0U;
        ++(vlSelf->__Vcoverage[4387]);
    }
    ++(vlSelf->__Vcoverage[4388]);
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__unused_tl 
        = (1U & VL_REDXOR_32(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]) 
                              ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U])));
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6884, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
            = ((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                        << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                          << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 6886, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0x3fffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0xc0000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
            = ((2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                          << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 6892, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xc7ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x38000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                          << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 6898, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xf9ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x06000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6902, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xfe01ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x01fe0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0x00010000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6918, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                >> 0x00000010U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xfffeffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x00010000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                  << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                    << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 6920, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 9U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 6984, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 9U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                              >> 9U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xffff01ffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0x0000fe00U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 2U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 6998, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 2U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                              >> 2U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffe03U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0x000001fcU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7012, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffdU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7014, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U];
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__addr_align_err) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__addr_align_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4156, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__addr_align_err, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__addr_align_err);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__addr_align_err 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__addr_align_err;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__addr_align_err;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__unused_tl) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7148, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__unused_tl, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__unused_tl;
    }
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7016, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 7018, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 7024, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 7030, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7034, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7050, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 7052, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 7116, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 7130, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7144, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7146, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[2U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U];
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__wr_req) 
         & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal)))) {
        ++(vlSelf->__Vcoverage[4205]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal) {
        ++(vlSelf->__Vcoverage[4206]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__wr_req)))) {
        ++(vlSelf->__Vcoverage[4207]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rd_req) 
         & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal)))) {
        ++(vlSelf->__Vcoverage[4208]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal) {
        ++(vlSelf->__Vcoverage[4209]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rd_req)))) {
        ++(vlSelf->__Vcoverage[4210]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__err_internal))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4152, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__err_internal);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__err_internal 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__re_o 
        = ((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rd_req));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__we_o 
        = ((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__wr_req));
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[2U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1748, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 1750, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 1756, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 1762, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1766, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1782, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1784, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 1848, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 1862, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1876, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1878, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U]));
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[2U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[2U];
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__re_o) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__re_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3862, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__re_o, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__re_o);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__re_o 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__re_o;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_re 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__re_o;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__we_o) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__we_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3864, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__we_o, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__we_o);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__we_o 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__we_o;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__we_o;
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[2U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 845, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 847, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 853, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 859, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 863, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 879, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 881, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 945, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 959, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 973, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 975, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U]));
    }
    vlSelfRef.rv_timer_tb__DOT__tl_o[0U] = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U];
    vlSelfRef.rv_timer_tb__DOT__tl_o[1U] = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U];
    vlSelfRef.rv_timer_tb__DOT__tl_o[2U] = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[2U];
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_re) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg_re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2138, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_re, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg_re);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg_re 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_re;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2136, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg_we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg_we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__wr_err 
        = ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we) 
           & (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
               & (0U != (1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_be))))) 
              | (((0U != (1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_be)))) 
                  & ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
                     >> 1U)) | (((0U != (1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_be)))) 
                                 & ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
                                    >> 2U)) | (((0U 
                                                 != 
                                                 (1U 
                                                  & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_be)))) 
                                                & ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
                                                   >> 3U)) 
                                               | ((((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
                                                    >> 4U) 
                                                   & (0U 
                                                      != 
                                                      (7U 
                                                       & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_be))))) 
                                                  | ((0U 
                                                      != 
                                                      (0x0000000fU 
                                                       & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_be)))) 
                                                     & (0U 
                                                        != 
                                                        (3U 
                                                         & ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
                                                            >> 5U))))))))));
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_re) 
         | (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we))) {
        ++(vlSelf->__Vcoverage[3242]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____VlemCond_0 
            = (1U & (~ (0U != (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit))));
    } else {
        ++(vlSelf->__Vcoverage[3243]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addrmiss 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____VlemCond_0;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we) {
        ++(vlSelf->__Vcoverage[3239]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_re) {
        ++(vlSelf->__Vcoverage[3240]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_re)) 
               & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we))))) {
        ++(vlSelf->__Vcoverage[3241]);
    }
    if ((0U != (((vlSelfRef.rv_timer_tb__DOT__tl_o[0U] 
                  ^ vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o[0U]) 
                 | (vlSelfRef.rv_timer_tb__DOT__tl_o[1U] 
                    ^ vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o[1U])) 
                | (vlSelfRef.rv_timer_tb__DOT__tl_o[2U] 
                   ^ vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o[2U])))) {
        VL_COV_TOGGLE_CHG_ST_W(66, vlSelf->__Vcoverage + 476, vlSelfRef.rv_timer_tb__DOT__tl_o, vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o);
        vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o[0U] 
            = vlSelfRef.rv_timer_tb__DOT__tl_o[0U];
        vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o[1U] 
            = vlSelfRef.rv_timer_tb__DOT__tl_o[1U];
        vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o[2U] 
            = vlSelfRef.rv_timer_tb__DOT__tl_o[2U];
    }
    vlSelfRef.rv_timer_tb__DOT__tl_o_d_valid = (1U 
                                                & (vlSelfRef.rv_timer_tb__DOT__tl_o[2U] 
                                                   >> 1U));
    vlSelfRef.rv_timer_tb__DOT__tl_o_d_opcode = (7U 
                                                 & ((vlSelfRef.rv_timer_tb__DOT__tl_o[2U] 
                                                     << 2U) 
                                                    | (vlSelfRef.rv_timer_tb__DOT__tl_o[1U] 
                                                       >> 0x0000001eU)));
    vlSelfRef.rv_timer_tb__DOT__tl_o_d_data = ((vlSelfRef.rv_timer_tb__DOT__tl_o[1U] 
                                                << 0x00000010U) 
                                               | (vlSelfRef.rv_timer_tb__DOT__tl_o[0U] 
                                                  >> 0x00000010U));
    vlSelfRef.rv_timer_tb__DOT__tl_o_d_error = (1U 
                                                & (vlSelfRef.rv_timer_tb__DOT__tl_o[0U] 
                                                   >> 1U));
    vlSelfRef.rv_timer_tb__DOT__tl_o_a_ready = (1U 
                                                & vlSelfRef.rv_timer_tb__DOT__tl_o[0U]);
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__wr_err) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__wr_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2290, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__wr_err, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__wr_err);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__wr_err 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__wr_err;
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__wr_err) {
        ++(vlSelf->__Vcoverage[2840]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addrmiss) {
        ++(vlSelf->__Vcoverage[2841]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addrmiss)) 
               & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__wr_err))))) {
        ++(vlSelf->__Vcoverage[2842]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addrmiss) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__addrmiss))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2288, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addrmiss, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__addrmiss);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__addrmiss 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addrmiss;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error 
        = ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addrmiss) 
           | (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__wr_err));
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__tl_o_d_valid) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o_d_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 182, vlSelfRef.rv_timer_tb__DOT__tl_o_d_valid, vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o_d_valid);
        vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o_d_valid 
            = vlSelfRef.rv_timer_tb__DOT__tl_o_d_valid;
    }
    if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__tl_o_d_opcode) 
                ^ (IData)(vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o_d_opcode)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 184, vlSelfRef.rv_timer_tb__DOT__tl_o_d_opcode, vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o_d_opcode);
        vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o_d_opcode 
            = vlSelfRef.rv_timer_tb__DOT__tl_o_d_opcode;
    }
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__tl_o_d_data 
                ^ vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o_d_data))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 190, vlSelfRef.rv_timer_tb__DOT__tl_o_d_data, vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o_d_data);
        vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o_d_data 
            = vlSelfRef.rv_timer_tb__DOT__tl_o_d_data;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__tl_o_d_error) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o_d_error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 254, vlSelfRef.rv_timer_tb__DOT__tl_o_d_error, vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o_d_error);
        vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o_d_error 
            = vlSelfRef.rv_timer_tb__DOT__tl_o_d_error;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__tl_o_a_ready) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o_a_ready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 256, vlSelfRef.rv_timer_tb__DOT__tl_o_a_ready, vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o_a_ready);
        vlSelfRef.rv_timer_tb__DOT____Vtogcov__tl_o_a_ready 
            = vlSelfRef.rv_timer_tb__DOT__tl_o_a_ready;
    }
    if ((((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
          & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we)) 
         & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[3245]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[3246]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[3247]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit)))) {
        ++(vlSelf->__Vcoverage[3248]);
    }
    if (((((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
           >> 1U) & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we)) 
         & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[3249]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[3250]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[3251]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[3252]);
    }
    if (((((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
           >> 2U) & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we)) 
         & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[3253]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[3254]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[3255]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
                  >> 2U)))) {
        ++(vlSelf->__Vcoverage[3256]);
    }
    if (((((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
           >> 3U) & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we)) 
         & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[3257]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[3258]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[3259]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
                  >> 3U)))) {
        ++(vlSelf->__Vcoverage[3260]);
    }
    if (((((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
           >> 4U) & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we)) 
         & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[3261]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[3262]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[3263]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
                  >> 4U)))) {
        ++(vlSelf->__Vcoverage[3264]);
    }
    if (((((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
           >> 5U) & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we)) 
         & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[3265]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[3266]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[3267]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
                  >> 5U)))) {
        ++(vlSelf->__Vcoverage[3268]);
    }
    if (((((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
           >> 6U) & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we)) 
         & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[3269]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[3270]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[3271]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
                  >> 6U)))) {
        ++(vlSelf->__Vcoverage[3272]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg_error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2286, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg_error);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg_error 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_i 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error;
    __VdfgRegularize_h6e95ff9d_0_0 = ((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error)) 
                                      & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we));
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_i) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__error_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4012, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_i, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__error_i);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__error_i 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_i;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_enable0_we 
        = (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
            >> 1U) & (IData)(__VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_state0_we 
        = (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
            >> 2U) & (IData)(__VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__timer_v0_we 
        = (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
            >> 5U) & (IData)(__VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_we 
        = (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
            >> 6U) & (IData)(__VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_we 
        = (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
            >> 4U) & (IData)(__VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_we 
        = ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
           & (IData)(__VdfgRegularize_h6e95ff9d_0_0));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_we 
        = (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit) 
            >> 3U) & (IData)(__VdfgRegularize_h6e95ff9d_0_0));
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_enable0_we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_enable0_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2858, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_enable0_we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_enable0_we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_enable0_we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_enable0_we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_enable0_we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_state0_we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_state0_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2864, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_state0_we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_state0_we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_state0_we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_state0_we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_state0_we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__timer_v0_we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__timer_v0_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2956, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__timer_v0_we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__timer_v0_we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__timer_v0_we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__timer_v0_we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__timer_v0_we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__compare_v0_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3086, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__compare_v0_we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__compare_v0_we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__cfg0_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2874, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__cfg0_we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__cfg0_we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_we;
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__ctrl_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2844, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__ctrl_we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__ctrl_we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_we;
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_we;
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_test0_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2870, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_test0_we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_test0_we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3306, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6837, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5636, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4965, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6375, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6566, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3357, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3406, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3455, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7163, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__qe 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__we;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3345]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3346]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3334, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3349]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[3350]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3347]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3348]);
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6867, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__we;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6038, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[5562]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[5563]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5365, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[5566]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[5567]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[5564]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[5565]);
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[6540]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[6541]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6487, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[6544]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[6545]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[6542]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[6543]);
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[6803]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[6804]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6726, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[6807]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[6808]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[6805]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[6806]);
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3394]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3395]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3383, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3398]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[3399]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3396]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3397]);
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3443]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3444]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3432, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3447]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[3448]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3445]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3446]);
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3492]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3493]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3481, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3496]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[3497]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3494]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3495]);
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__qe) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7167, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__qe, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT____Vtogcov__qe);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT____Vtogcov__qe 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__qe;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_flds_we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__qe;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wr_data) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3342, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3340, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wr_data 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5497, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5495, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6523, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6521, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(12, vlSelf->__Vcoverage + 6778, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6776, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wr_en;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wr_data) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3391, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3389, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wr_en;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wr_data) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3440, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3438, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wr_en;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wr_data) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3489, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3487, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wr_en;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_flds_we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_test0_flds_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3218, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_flds_we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_test0_flds_we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_test0_flds_we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_flds_we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_qe 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_flds_we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_data) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3322, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3320, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__qe 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en;
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_data 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5291, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5289, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__qe 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_data) 
                ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6461, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6459, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__qe 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_data) 
                ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(12, vlSelf->__Vcoverage + 6692, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6690, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__qe 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_data) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3371, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3369, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__qe 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_data) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3420, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3418, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__qe 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_data) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3469, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3467, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__qe 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_qe) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_test0_qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3216, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_qe, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_test0_qe);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_test0_qe 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_qe;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__qe) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3312, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__qe, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__qe);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__qe 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__qe;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__qe) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5095, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__qe, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__qe);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__qe 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__qe;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_flds_we 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__qe;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__qe) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6409, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__qe, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__qe);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__qe 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__qe;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__qe) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6616, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__qe, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__qe);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__qe 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__qe;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__qe) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3361, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__qe, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__qe);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__qe 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__qe;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__qe) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3410, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__qe, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__qe);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__qe 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__qe;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__qe) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3459, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__qe, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__qe);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__qe 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__qe;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_flds_we) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__compare_v0_flds_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3222, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_flds_we, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__compare_v0_flds_we);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__compare_v0_flds_we 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_flds_we;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__d_i 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_flds_we;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__d_i) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7154, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__d_i, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT____Vtogcov__d_i);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT____Vtogcov__d_i 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__d_i;
    }
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next = 0U;
    if ((1U & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit))) {
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next 
            = ((0xfffffff8U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_1_0_qs) 
                   << 2U) | (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_0_0_qs) 
                              << 1U) | (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_active_0_qs))));
        ++(vlSelf->__Vcoverage[3273]);
    } else if ((2U & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit))) {
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next 
            = ((0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next) 
               | (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_enable0_qs));
        ++(vlSelf->__Vcoverage[3274]);
    } else if ((4U & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit))) {
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next 
            = ((0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next) 
               | (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_state0_qs));
        ++(vlSelf->__Vcoverage[3275]);
    } else if ((8U & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit))) {
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next 
            = (0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next);
        ++(vlSelf->__Vcoverage[3276]);
    } else if ((0x00000010U & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit))) {
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next 
            = ((0xfffff000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next) 
               | (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_prescale_qs));
        ++(vlSelf->__Vcoverage[3277]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next 
            = ((0xff00ffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next) 
               | ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_step_qs) 
                  << 0x00000010U));
    } else if ((0x00000020U & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit))) {
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__timer_v0_qs;
        ++(vlSelf->__Vcoverage[3278]);
    } else if ((0x00000040U & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit))) {
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_qs;
        ++(vlSelf->__Vcoverage[3279]);
    } else {
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next = 0xffffffffU;
        ++(vlSelf->__Vcoverage[3280]);
    }
    if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit))))))) {
        if ((0U != (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: rv_timer_reg_top.sv:468: Assertion failed in %m: unique case, but multiple matches found for '1'h1'\n",3, 'M',vlSymsp->name(),"rv_timer_tb.u_rv_timer.u_reg", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("/tmp/flexsoc-repack/rv_timer/runs/rv_timer/dev/rtl/rv_timer_reg_top.sv", 468, "");
            }
        }
    }
    ++(vlSelf->__Vcoverage[3281]);
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg_rdata_next))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2292, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg_rdata_next);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg_rdata_next 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next;
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg_rdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2222, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg_rdata);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg_rdata 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata_i 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata;
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata_i 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__rdata_i))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 3948, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata_i, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__rdata_i);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT____Vtogcov__rdata_i 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata_i;
    }
}

void Vtop___024root___nba_comb__TOP__8(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__8\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[0U] 
        = (((IData)((((QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__q)) 
                      << 0x00000020U) | (QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__q)))) 
            << 1U) | (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_qe));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[1U] 
        = (((IData)((((QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__q)) 
                      << 0x00000020U) | (QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__q)))) 
            >> 0x0000001fU) | ((IData)(((((QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__q)) 
                                          << 0x00000020U) 
                                         | (QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__q))) 
                                        >> 0x00000020U)) 
                               << 1U));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
        = ((0x0ffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U]) 
           | (0x0fffffffU & ((IData)(((((QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__q)) 
                                        << 0x00000020U) 
                                       | (QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__q))) 
                                      >> 0x00000020U)) 
                             >> 0x0000001fU)));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
        = ((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U]) 
           | (0x0fffffffU & ((((((((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__q) 
                                   << 3U) | ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__q) 
                                             << 2U)) 
                                 | (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__q) 
                                     << 1U) | (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__q))) 
                                << 0x00000017U) | (
                                                   ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__q) 
                                                    << 0x00000016U) 
                                                   | (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__q) 
                                                       << 0x00000015U) 
                                                      | ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_qe) 
                                                         << 0x00000014U)))) 
                              | (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__q) 
                                  << 0x0000000cU) | (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__q))) 
                             << 1U)));
    if ((0x08000000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1880, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                >> 0x0000001bU), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                                  >> 0x0000001bU));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
            = ((0x07ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]) 
               | (0x08000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U]));
    }
    if ((0x04000000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1882, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                >> 0x0000001aU), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                                  >> 0x0000001aU));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0bffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]) 
               | (0x04000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U]));
    }
    if ((0x02000000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1884, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                >> 0x00000019U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                                  >> 0x00000019U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0dffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]) 
               | (0x02000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U]));
    }
    if ((0x01000000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1886, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                >> 0x00000018U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                                  >> 0x00000018U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0effffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]) 
               | (0x01000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U]));
    }
    if ((0x00800000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1888, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                >> 0x00000017U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                                  >> 0x00000017U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0f7fffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]) 
               | (0x00800000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U]));
    }
    if ((0x00400000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1890, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                >> 0x00000016U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                                  >> 0x00000016U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0fbfffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]) 
               | (0x00400000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U]));
    }
    if ((0x00200000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1892, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                >> 0x00000015U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                                  >> 0x00000015U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0fdfffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]) 
               | (0x00200000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                 << 0x00000013U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                 >> 0x0000000dU)) ^ 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                 << 0x00000013U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                 >> 0x0000000dU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1894, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                 << 0x00000013U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                 >> 0x0000000dU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                 << 0x00000013U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                 >> 0x0000000dU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0fe01fffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]) 
               | (0x001fe000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U]));
    }
    if ((0U != (0x00000fffU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                 >> 1U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                             << 0x0000001fU) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                               >> 1U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(12, vlSelf->__Vcoverage + 1910, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                 >> 1U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                            << 0x0000001fU) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                              >> 1U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0fffe001U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]) 
               | (0x00001ffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U]));
    }
    if ((0U != (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                  << 0x0000001fU) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[1U] 
                                     >> 1U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                                 << 0x0000001fU) 
                                                | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[1U] 
                                                   >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1934, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[1U] 
                                 >> 1U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
                                            << 0x0000001fU) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[1U] 
                                              >> 1U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[1U] 
            = ((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[1U]) 
               | (0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[1U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0ffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[2U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U]));
    }
    if ((0U != (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[1U] 
                  << 0x0000001fU) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[0U] 
                                     >> 1U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[1U] 
                                                 << 0x0000001fU) 
                                                | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[0U] 
                                                   >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1998, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[1U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[0U] 
                                 >> 1U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[1U] 
                                            << 0x0000001fU) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[0U] 
                                              >> 1U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[0U] 
            = ((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[0U]) 
               | (0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[0U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[1U] 
            = ((0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[1U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[1U]));
    }
    if ((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2062, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[0U] 
            = ((0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__reg2hw[0U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[0U]));
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[0U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[0U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[1U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[1U];
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U];
    if ((IData)((0x04000000U == (0x0c000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U])))) {
        ++(vlSelf->__Vcoverage[1504]);
    }
    if ((1U & (~ (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                  >> 0x0000001aU)))) {
        ++(vlSelf->__Vcoverage[1505]);
    }
    if ((0x08000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U])) {
        ++(vlSelf->__Vcoverage[1506]);
    }
    if ((IData)((0x08000000U == (0x0c000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U])))) {
        ++(vlSelf->__Vcoverage[1507]);
    }
    if ((0x04000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U])) {
        ++(vlSelf->__Vcoverage[1508]);
    }
    if ((1U & (~ (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                  >> 0x0000001bU)))) {
        ++(vlSelf->__Vcoverage[1509]);
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_en 
        = (1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                 >> 0x00000018U));
    if ((0x08000000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 979, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                >> 0x0000001bU), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                                  >> 0x0000001bU));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
            = ((0x07ffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]) 
               | (0x08000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U]));
    }
    if ((0x04000000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 981, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                >> 0x0000001aU), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                                  >> 0x0000001aU));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0bffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]) 
               | (0x04000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U]));
    }
    if ((0x02000000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 983, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                >> 0x00000019U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                                  >> 0x00000019U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0dffffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]) 
               | (0x02000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U]));
    }
    if ((0x01000000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 985, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                >> 0x00000018U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                                  >> 0x00000018U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0effffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]) 
               | (0x01000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U]));
    }
    if ((0x00800000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 987, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                >> 0x00000017U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                                  >> 0x00000017U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0f7fffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]) 
               | (0x00800000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U]));
    }
    if ((0x00400000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 989, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                >> 0x00000016U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                                  >> 0x00000016U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0fbfffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]) 
               | (0x00400000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U]));
    }
    if ((0x00200000U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 991, 
                               (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                >> 0x00000015U), (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                                  >> 0x00000015U));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0fdfffffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]) 
               | (0x00200000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                 << 0x00000013U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                 >> 0x0000000dU)) ^ 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                 << 0x00000013U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                 >> 0x0000000dU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 993, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                 << 0x00000013U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                 >> 0x0000000dU)), 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                 << 0x00000013U) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                 >> 0x0000000dU)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0fe01fffU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]) 
               | (0x001fe000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U]));
    }
    if ((0U != (0x00000fffU & (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                 >> 1U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                             << 0x0000001fU) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                               >> 1U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(12, vlSelf->__Vcoverage + 1009, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                 >> 1U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                            << 0x0000001fU) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                              >> 1U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0fffe001U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]) 
               | (0x00001ffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U]));
    }
    if ((0U != (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                  << 0x0000001fU) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[1U] 
                                     >> 1U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                                 << 0x0000001fU) 
                                                | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[1U] 
                                                   >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1033, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[1U] 
                                 >> 1U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
                                            << 0x0000001fU) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[1U] 
                                              >> 1U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[1U] 
            = ((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[1U]) 
               | (0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[1U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U] 
            = ((0x0ffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[2U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U]));
    }
    if ((0U != (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[1U] 
                  << 0x0000001fU) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[0U] 
                                     >> 1U)) ^ ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[1U] 
                                                 << 0x0000001fU) 
                                                | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[0U] 
                                                   >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1097, 
                               ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[1U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[0U] 
                                 >> 1U)), ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[1U] 
                                            << 0x0000001fU) 
                                           | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[0U] 
                                              >> 1U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[0U] 
            = ((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[0U]) 
               | (0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[0U]));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[1U] 
            = ((0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[1U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[1U]));
    }
    if ((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[0U] 
               ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1161, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[0U] 
            = ((0xfffffffeU & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__reg2hw[0U]) 
               | (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[0U]));
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_0 
        = (IData)((0x04000000U == (0x0c000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U])));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_1 
        = (IData)((0x08000000U == (0x0c000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U])));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__step[0U] 
        = (0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                          >> 0x0000000dU));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__prescaler[0U] 
        = (0x00000fffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                          >> 1U));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_q 
        = (1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                 >> 0x00000017U));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp_update[0U][0U] 
        = (1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[0U]);
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_test_q 
        = (1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                 >> 0x00000016U));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_test_qe 
        = (1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                 >> 0x00000015U));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp[0U][0U] 
        = ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[1U] 
            << 0x0000001fU) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[0U] 
                               >> 1U));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtime[0U] 
        = ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
            << 0x0000001fU) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[1U] 
                               >> 1U));
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1473, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_enable_q_i 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_en;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_0) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__sel_gpio_intr_0))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1491, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_0, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__sel_gpio_intr_0);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__sel_gpio_intr_0 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_0;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_1) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__sel_gpio_intr_1))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1493, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_1, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__sel_gpio_intr_1);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__sel_gpio_intr_1 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_1;
    }
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__step[0U] 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__step[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1259, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__step[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__step[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__step[0U] 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__step[0U];
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__step 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__step[0U];
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__prescaler[0U] 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__prescaler[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(12, vlSelf->__Vcoverage + 1235, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__prescaler[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__prescaler[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__prescaler[0U] 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__prescaler[0U];
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__prescaler 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__prescaler[0U];
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_q) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_state_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1479, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_state_q);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_state_q 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_q;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_state_q_i 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_q;
    if ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp_update[0U][0U] 
         ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__mtimecmp_update[0U][0U])) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1469, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp_update[0U][0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__mtimecmp_update[0U][0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__mtimecmp_update[0U][0U] 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp_update[0U][0U];
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_test_q) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_test_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1475, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_test_q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_test_q);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_test_q 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_test_q;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_q_i 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_test_q;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_test_qe) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_test_qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1477, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_test_qe, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_test_qe);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_test_qe 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_test_qe;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_qe_i 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_test_qe;
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp[0U][0U] 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__mtimecmp[0U][0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1405, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp[0U][0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__mtimecmp[0U][0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__mtimecmp[0U][0U] 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp[0U][0U];
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vcellinp__gen_harts__BRA__0__KET____DOT__u_core__mtimecmp[0U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp[0U][0U];
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtime[0U] 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__mtime[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1341, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtime[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__mtime[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__mtime[0U] 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtime[0U];
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtime[0U];
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_enable_q_i) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__reg2hw_intr_enable_q_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7458, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_enable_q_i, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__reg2hw_intr_enable_q_i);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__reg2hw_intr_enable_q_i 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_enable_q_i;
    }
    if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__step) 
                ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__step)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7201, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__step, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__step);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__step 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__step;
    }
    if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__prescaler) 
                ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__prescaler)))) {
        VL_COV_TOGGLE_CHG_ST_I(12, vlSelf->__Vcoverage + 7177, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__prescaler, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__prescaler);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__prescaler 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__prescaler;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_state_q_i) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__reg2hw_intr_state_q_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7464, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_state_q_i, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__reg2hw_intr_state_q_i);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__reg2hw_intr_state_q_i 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_state_q_i;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__status 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_state_q_i;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_q_i) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__reg2hw_intr_test_q_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7460, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_q_i, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__reg2hw_intr_test_q_i);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__reg2hw_intr_test_q_i 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_q_i;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_qe_i) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__reg2hw_intr_test_qe_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7462, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_qe_i, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__reg2hw_intr_test_qe_i);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__reg2hw_intr_test_qe_i 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_qe_i;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtimecmp 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vcellinp__gen_harts__BRA__0__KET____DOT__u_core__mtimecmp;
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__mtime))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 7283, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__mtime);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__mtime 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime_d 
        = (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime 
           + (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__step));
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__status) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__status))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7472, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__status, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__status);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__status 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__status;
    }
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtimecmp[0U] 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__mtimecmp[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 7347, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtimecmp[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__mtimecmp[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__mtimecmp[0U] 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtimecmp[0U];
    }
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime_d 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__mtime_d))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 7219, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime_d, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__mtime_d);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__mtime_d 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime_d;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtime_d[0U] 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime_d;
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtime_d[0U] 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__mtime_d[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1277, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtime_d[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__mtime_d[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__mtime_d[0U] 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtime_d[0U];
    }
}

void Vtop___024root___nba_comb__TOP__9(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__9\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U]) {
        ++(vlSelf->__Vcoverage[1495]);
    }
    if ((0x02000000U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U])) {
        ++(vlSelf->__Vcoverage[1496]);
    }
    if ((1U & ((~ (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                   >> 0x00000019U)) & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U]))))) {
        ++(vlSelf->__Vcoverage[1497]);
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__active 
        = (1U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                  >> 0x00000019U) | vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U]));
    if ((((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_1) 
          & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U]) 
         & (~ ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gpio_intr_i) 
               >> 1U)))) {
        ++(vlSelf->__Vcoverage[1510]);
    }
    if ((((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_1) 
          & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U]))) 
         & ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gpio_intr_i) 
            >> 1U))) {
        ++(vlSelf->__Vcoverage[1511]);
    }
    if ((((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_0) 
          & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U]) 
         & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gpio_intr_i)))) {
        ++(vlSelf->__Vcoverage[1512]);
    }
    if ((((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_0) 
          & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U]))) 
         & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gpio_intr_i))) {
        ++(vlSelf->__Vcoverage[1513]);
    }
    if ((IData)(((3U == (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gpio_intr_i)) 
                 & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U]))) {
        ++(vlSelf->__Vcoverage[1514]);
    }
    if (((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U] 
          & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gpio_intr_i)) 
         & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_1)))) {
        ++(vlSelf->__Vcoverage[1515]);
    }
    if ((IData)(((0U == (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gpio_intr_i)) 
                 & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U]))))) {
        ++(vlSelf->__Vcoverage[1516]);
    }
    if ((1U & (((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U])) 
                & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gpio_intr_i))) 
               & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_1))))) {
        ++(vlSelf->__Vcoverage[1517]);
    }
    if ((((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_0)) 
          & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U]) 
         & ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gpio_intr_i) 
            >> 1U))) {
        ++(vlSelf->__Vcoverage[1518]);
    }
    if ((1U & (((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_0)) 
                & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U]))) 
               & (~ ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gpio_intr_i) 
                     >> 1U))))) {
        ++(vlSelf->__Vcoverage[1519]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_0)) 
               & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_1))))) {
        ++(vlSelf->__Vcoverage[1520]);
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_d[0U] 
        = (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_0) 
            & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U] 
               ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gpio_intr_i))) 
           | ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_1) 
              & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U] 
                 ^ ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gpio_intr_i) 
                    >> 1U))));
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__active) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__active))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1233, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__active, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__active);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__active 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__active;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__active 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__active;
    if ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_d[0U] 
         ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__input_capture_active_d[0U])) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1487, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_d[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__input_capture_active_d[0U]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__input_capture_active_d[0U] 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_d[0U];
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__active) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__active))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7175, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__active, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__active);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__active 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__active;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__active) 
         & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime 
            >= vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtimecmp[0U]))) {
        ++(vlSelf->__Vcoverage[7449]);
    }
    if ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime 
         < vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtimecmp[0U])) {
        ++(vlSelf->__Vcoverage[7450]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__active)))) {
        ++(vlSelf->__Vcoverage[7451]);
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__intr 
        = ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__active) 
           & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime 
              >= vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtimecmp[0U]));
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__intr) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__intr))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7411, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__intr, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__intr);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__intr 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__intr;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_set 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__intr;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_set) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_set))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1471, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_set, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_set);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_set 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_set;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__event_intr_i 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_set;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__event_intr_i) {
        ++(vlSelf->__Vcoverage[7476]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_qe_i) 
         & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_q_i))) {
        ++(vlSelf->__Vcoverage[7477]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_q_i)) 
               & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__event_intr_i))))) {
        ++(vlSelf->__Vcoverage[7478]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_qe_i)) 
               & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__event_intr_i))))) {
        ++(vlSelf->__Vcoverage[7479]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__event_intr_i) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__event_intr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7456, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__event_intr_i, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__event_intr_i);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__event_intr_i 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__event_intr_i;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__g_intr_event__DOT__new_event 
        = ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__event_intr_i) 
           | ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_q_i) 
              & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_qe_i)));
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_state_q_i) {
        ++(vlSelf->__Vcoverage[7480]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__g_intr_event__DOT__new_event) {
        ++(vlSelf->__Vcoverage[7481]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__g_intr_event__DOT__new_event)) 
               & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_state_q_i))))) {
        ++(vlSelf->__Vcoverage[7482]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__g_intr_event__DOT__new_event) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__g_intr_eventnew_event))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7474, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__g_intr_event__DOT__new_event, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__g_intr_eventnew_event);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__g_intr_eventnew_event 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__g_intr_event__DOT__new_event;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__hw2reg_intr_state_de_o 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__g_intr_event__DOT__new_event;
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__hw2reg_intr_state_d_o 
        = ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_state_q_i) 
           | (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__g_intr_event__DOT__new_event));
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__hw2reg_intr_state_de_o) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__hw2reg_intr_state_de_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7466, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__hw2reg_intr_state_de_o, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__hw2reg_intr_state_de_o);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__hw2reg_intr_state_de_o 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__hw2reg_intr_state_de_o;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_de 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__hw2reg_intr_state_de_o;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__hw2reg_intr_state_d_o) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__hw2reg_intr_state_d_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7468, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__hw2reg_intr_state_d_o, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__hw2reg_intr_state_d_o);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__hw2reg_intr_state_d_o 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__hw2reg_intr_state_d_o;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_d 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__hw2reg_intr_state_d_o;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp_update[0U][0U]) {
        ++(vlSelf->__Vcoverage[1498]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_de) {
        ++(vlSelf->__Vcoverage[1499]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_de)) 
               & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp_update[0U][0U]))))) {
        ++(vlSelf->__Vcoverage[1500]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_de) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_state_de))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1481, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_de, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_state_de);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_state_de 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_de;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
        = ((0x00000005ffffffffULL & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg) 
           | ((QData)((IData)(((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_de) 
                               | vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp_update[0U][0U]))) 
              << 0x00000021U));
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_d) 
         & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp_update[0U][0U])))) {
        ++(vlSelf->__Vcoverage[1501]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp_update[0U][0U]) {
        ++(vlSelf->__Vcoverage[1502]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_d)))) {
        ++(vlSelf->__Vcoverage[1503]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_d) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_state_d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1483, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_d, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_state_d);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_state_d 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_d;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
        = ((0x00000003ffffffffULL & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg) 
           | ((QData)((IData)(((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_d) 
                               & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp_update[0U][0U]))))) 
              << 0x00000022U));
}

void Vtop___024root___nba_comb__TOP__10(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__10\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__active) 
         & ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count) 
            >= (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__prescaler)))) {
        ++(vlSelf->__Vcoverage[7446]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count) 
         < (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__prescaler))) {
        ++(vlSelf->__Vcoverage[7447]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__active)))) {
        ++(vlSelf->__Vcoverage[7448]);
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick 
        = ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__active) 
           & ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count) 
              >= (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__prescaler)));
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__tick))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7217, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__tick);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__tick 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tick 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tick) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tick))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1275, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tick, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tick);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__tick 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tick;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
        = ((0x0000000600000000ULL & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg) 
           | (((QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtime_d[0U])) 
               << 1U) | (QData)((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tick))));
    if ((IData)(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
                  ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__hw2reg) 
                 >> 0x00000022U))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1163, (IData)(
                                                                      (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
                                                                       >> 0x00000022U)), (IData)(
                                                                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__hw2reg 
                                                                                >> 0x00000022U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__hw2reg 
            = ((0x00000003ffffffffULL & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__hw2reg) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
                                                 >> 0x00000022U))))) 
                  << 0x00000022U));
    }
    if ((1U & ((IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
                        >> 0x00000021U)) ^ (IData)(
                                                   (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__hw2reg 
                                                    >> 0x00000021U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1165, (IData)(
                                                                      (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
                                                                       >> 0x00000021U)), (IData)(
                                                                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__hw2reg 
                                                                                >> 0x00000021U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__hw2reg 
            = ((0x00000005ffffffffULL & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__hw2reg) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
                                                 >> 0x00000021U))))) 
                  << 0x00000021U));
    }
    if ((0U != ((IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
                         >> 1U)) ^ (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__hw2reg 
                                            >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1167, (IData)(
                                                                       (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
                                                                        >> 1U)), (IData)(
                                                                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__hw2reg 
                                                                                >> 1U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__hw2reg 
            = ((0x0000000600000001ULL & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__hw2reg) 
               | ((QData)((IData)((IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
                                           >> 1U)))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg) 
               ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1231, (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg), (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__hw2reg));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__hw2reg 
            = ((0x00000007fffffffeULL & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__hw2reg) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg)))));
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg;
    if ((IData)(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                  ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__hw2reg) 
                 >> 0x00000022U))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2064, (IData)(
                                                                      (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                                                                       >> 0x00000022U)), (IData)(
                                                                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__hw2reg 
                                                                                >> 0x00000022U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__hw2reg 
            = ((0x00000003ffffffffULL & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__hw2reg) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                                                 >> 0x00000022U))))) 
                  << 0x00000022U));
    }
    if ((1U & ((IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                        >> 0x00000021U)) ^ (IData)(
                                                   (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__hw2reg 
                                                    >> 0x00000021U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2066, (IData)(
                                                                      (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                                                                       >> 0x00000021U)), (IData)(
                                                                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__hw2reg 
                                                                                >> 0x00000021U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__hw2reg 
            = ((0x00000005ffffffffULL & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__hw2reg) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                                                 >> 0x00000021U))))) 
                  << 0x00000021U));
    }
    if ((0U != ((IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                         >> 1U)) ^ (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__hw2reg 
                                            >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2068, (IData)(
                                                                       (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                                                                        >> 1U)), (IData)(
                                                                                (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__hw2reg 
                                                                                >> 1U)));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__hw2reg 
            = ((0x0000000600000001ULL & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__hw2reg) 
               | ((QData)((IData)((IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                                           >> 1U)))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg) 
               ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2132, (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg), (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__hw2reg));
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__hw2reg 
            = ((0x00000007fffffffeULL & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__hw2reg) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg)))));
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__d 
        = (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                   >> 1U));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__d 
        = (1U & (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                         >> 0x00000022U)));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__de 
        = (1U & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__de 
        = (1U & (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                         >> 0x00000021U)));
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__d 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5704, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__d, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__d);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__d 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__d;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__d 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__d;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__d) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6843, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__d, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__d);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__d 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__d;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__d 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__d;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__de) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__de))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5702, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__de, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__de);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__de 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__de;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__de 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__de;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__de) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__de))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6841, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__de, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__de);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__de 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__de;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__de 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__de;
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__d 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 6106, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__d, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__d);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__d 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__d;
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[6305]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[6306]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__d;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[6303]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[6304]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__d) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6873, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__d, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__d);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__d 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__d;
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__de) {
        ++(vlSelf->__Vcoverage[6300]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[6301]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__we)) 
               & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__de))))) {
        ++(vlSelf->__Vcoverage[6302]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__de) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__de))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6104, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__de, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__de);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__de 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__de;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__we) 
           | (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__de));
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__de) {
        ++(vlSelf->__Vcoverage[6881]);
    }
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[6882]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__we)) 
               & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__de))))) {
        ++(vlSelf->__Vcoverage[6883]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__de) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__de))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6871, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__de, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__de);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__de 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__de;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wr_data 
        = ((~ ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__we) 
               & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wd))) 
           & ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__de)
               ? (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__d)
               : (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__q)));
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__we) 
           | (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__de));
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wr_data 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 6236, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6234, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wr_en;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wr_data) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6879, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_data 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6877, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_data 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5964, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5962, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__qe 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[6036]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____VlemCond_0 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[6037]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____VlemCond_0 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__qs;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__ds 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____VlemCond_0;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[6034]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[6035]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_data) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6855, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_data, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__wr_data);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__wr_data 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6853, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__wr_en);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__wr_en 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__qe 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[6865]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____VlemCond_0 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[6866]);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____VlemCond_0 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__qs;
    }
    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__ds 
        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____VlemCond_0;
    if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[6863]);
    }
    if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[6864]);
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__qe) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5768, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__qe, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__qe);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__qe 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__qe;
    }
    if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__ds 
                ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5834, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__ds, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__ds);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__ds 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__ds;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__qe) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6845, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__qe, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__qe);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__qe 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__qe;
    }
    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__ds) 
         ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6849, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__ds, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__ds);
        vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__ds 
            = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__ds;
    }
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x0000000003000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__0
            SData/*11:0*/ __Vinline_0__nba_sequent__TOP__0___Vdly__rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count;
            __Vinline_0__nba_sequent__TOP__0___Vdly__rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count = 0;
            __Vinline_0__nba_sequent__TOP__0___Vdly__rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count;
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__rst_ni) {
                if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__active) {
                    if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count) 
                         == (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__prescaler))) {
                        ++(vlSelf->__Vcoverage[7437]);
                        __Vinline_0__nba_sequent__TOP__0___Vdly__rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count = 0U;
                    } else {
                        __Vinline_0__nba_sequent__TOP__0___Vdly__rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count 
                            = (0x00000fffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count)));
                        ++(vlSelf->__Vcoverage[7438]);
                    }
                } else {
                    ++(vlSelf->__Vcoverage[7439]);
                    __Vinline_0__nba_sequent__TOP__0___Vdly__rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count = 0U;
                }
                if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__active)))) {
                    ++(vlSelf->__Vcoverage[7440]);
                }
                if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__active) {
                    ++(vlSelf->__Vcoverage[7441]);
                }
            } else {
                __Vinline_0__nba_sequent__TOP__0___Vdly__rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count = 0U;
                ++(vlSelf->__Vcoverage[7442]);
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[7443]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[7444]);
            }
            ++(vlSelf->__Vcoverage[7445]);
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count 
                = __Vinline_0__nba_sequent__TOP__0___Vdly__rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count;
            if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count) 
                        ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__tick_count)))) {
                VL_COV_TOGGLE_CHG_ST_I(12, vlSelf->__Vcoverage + 7413, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__tick_count);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT____Vtogcov__tick_count 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count;
            }
        }
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__1
            CData/*0:0*/ __Vinline_0__nba_sequent__TOP__1___VdlyVal__rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q__v0;
            __Vinline_0__nba_sequent__TOP__1___VdlyVal__rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q__v0 = 0;
            CData/*0:0*/ __Vinline_0__nba_sequent__TOP__1___VdlySet__rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q__v0;
            __Vinline_0__nba_sequent__TOP__1___VdlySet__rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q__v0 = 0;
            CData/*0:0*/ __Vinline_0__nba_sequent__TOP__1___VdlySet__rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q__v1;
            __Vinline_0__nba_sequent__TOP__1___VdlySet__rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q__v1 = 0;
            __Vinline_0__nba_sequent__TOP__1___VdlySet__rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q__v0 = 0U;
            __Vinline_0__nba_sequent__TOP__1___VdlySet__rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q__v1 = 0U;
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1522]);
                __Vinline_0__nba_sequent__TOP__1___VdlyVal__rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q__v0 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_d[0U];
                __Vinline_0__nba_sequent__TOP__1___VdlySet__rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q__v0 = 1U;
            } else {
                ++(vlSelf->__Vcoverage[1521]);
                __Vinline_0__nba_sequent__TOP__1___VdlySet__rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q__v1 = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1523]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1524]);
            }
            ++(vlSelf->__Vcoverage[1525]);
            if (__Vinline_0__nba_sequent__TOP__1___VdlySet__rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q__v0) {
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U] 
                    = __Vinline_0__nba_sequent__TOP__1___VdlyVal__rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q__v0;
            }
            if (__Vinline_0__nba_sequent__TOP__1___VdlySet__rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q__v1) {
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U] = 0U;
            }
            if ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U] 
                 ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__input_capture_active_q[0U])) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1489, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U], vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__input_capture_active_q[0U]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__input_capture_active_q[0U] 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q[0U];
            }
        }
    }
    if ((0x000000000c000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__2
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__rst_ni) {
                if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__status) 
                     & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_enable_q_i))) {
                    ++(vlSelf->__Vcoverage[7483]);
                }
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__intr_o 
                    = ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__status) 
                       & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_enable_q_i));
                if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_enable_q_i)))) {
                    ++(vlSelf->__Vcoverage[7484]);
                }
                if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__status)))) {
                    ++(vlSelf->__Vcoverage[7485]);
                }
                ++(vlSelf->__Vcoverage[7487]);
            } else {
                ++(vlSelf->__Vcoverage[7486]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__intr_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[7488]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[7489]);
            }
            ++(vlSelf->__Vcoverage[7490]);
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__intr_o) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__intr_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7470, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__intr_o, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__intr_o);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT____Vtogcov__intr_o 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__intr_o;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_out 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__intr_o;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_out) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_out))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1485, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_out, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_out);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_out 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_out;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_expired_hart0_timer0_o 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_out;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_expired_hart0_timer0_o) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_expired_hart0_timer0_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 977, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_expired_hart0_timer0_o, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_expired_hart0_timer0_o);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT____Vtogcov__intr_timer_expired_hart0_timer0_o 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_expired_hart0_timer0_o;
            }
            vlSelfRef.rv_timer_tb__DOT__intr_timer_expired_hart0_timer0_o 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_expired_hart0_timer0_o;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__intr_timer_expired_hart0_timer0_o) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT____Vtogcov__intr_timer_expired_hart0_timer0_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 8, vlSelfRef.rv_timer_tb__DOT__intr_timer_expired_hart0_timer0_o, vlSelfRef.rv_timer_tb__DOT____Vtogcov__intr_timer_expired_hart0_timer0_o);
                vlSelfRef.rv_timer_tb__DOT____Vtogcov__intr_timer_expired_hart0_timer0_o 
                    = vlSelfRef.rv_timer_tb__DOT__intr_timer_expired_hart0_timer0_o;
            }
        }
    }
    if ((0x0000000000c00000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__3
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[7159]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__q_o 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[7158]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[7160]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[7161]);
            }
            ++(vlSelf->__Vcoverage[7162]);
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__q_o) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7156, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__q_o, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT____Vtogcov__q_o);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT____Vtogcov__q_o 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__q_o;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_qe 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__q_o;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_qe) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__compare_v0_qe))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3220, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_qe, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__compare_v0_qe);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__compare_v0_qe 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_qe;
            }
        }
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__4
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__rst_ni) {
                if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3324]);
                    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__q 
                        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3325]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3326]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3327]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3328]);
            }
            ++(vlSelf->__Vcoverage[3329]);
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__q) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3314, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__q;
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__q;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3338, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__qs) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3318, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__qs;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_enable0_qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__qs;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3351, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_enable0_qs) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_enable0_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2860, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_enable0_qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_enable0_qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_enable0_qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_enable0_qs;
            }
        }
    }
    if ((0x0000000000000030ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__5
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__rst_ni) {
                if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3373]);
                    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__q 
                        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3374]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3375]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3376]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3377]);
            }
            ++(vlSelf->__Vcoverage[3378]);
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__q) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3363, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__q;
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__q;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3387, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__qs) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3367, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__qs;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_1_0_qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__qs;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3400, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_1_0_qs) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__ctrl_gpio_intr_1_0_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2854, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_1_0_qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__ctrl_gpio_intr_1_0_qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__ctrl_gpio_intr_1_0_qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_1_0_qs;
            }
        }
    }
    if ((0x00000000000000c0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__6
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__rst_ni) {
                if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3422]);
                    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__q 
                        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3423]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3424]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3425]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3426]);
            }
            ++(vlSelf->__Vcoverage[3427]);
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__q) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3412, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__q;
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__q;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3436, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__qs) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3416, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__qs;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_0_0_qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__qs;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3449, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_0_0_qs) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__ctrl_gpio_intr_0_0_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2850, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_0_0_qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__ctrl_gpio_intr_0_0_qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__ctrl_gpio_intr_0_0_qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_0_0_qs;
            }
        }
    }
    if ((0x0000000000000300ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__7
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__rst_ni) {
                if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3471]);
                    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__q 
                        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3472]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3473]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3474]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3475]);
            }
            ++(vlSelf->__Vcoverage[3476]);
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__q) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3461, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__q;
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__q;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3485, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__qs) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3465, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__qs;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_active_0_qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__qs;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3498, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_active_0_qs) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__ctrl_active_0_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2846, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_active_0_qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__ctrl_active_0_qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__ctrl_active_0_qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_active_0_qs;
            }
        }
    }
    if ((0x000000000000c000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__8
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__rst_ni) {
                if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[6028]);
                    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__q 
                        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[6029]);
                }
            } else {
                ++(vlSelf->__Vcoverage[6030]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[6031]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[6032]);
            }
            ++(vlSelf->__Vcoverage[6033]);
            if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__q 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5770, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__q;
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__q;
            if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__q 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 6170, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__q;
            if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__qs 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5898, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT____Vtogcov__qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__qs;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__timer_v0_qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__qs;
            if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 6307, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__timer_v0_qs 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__timer_v0_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2958, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__timer_v0_qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__timer_v0_qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__timer_v0_qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__timer_v0_qs;
            }
        }
    }
    if ((0x0000000000030000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__9
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__rst_ni) {
                if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[6477]);
                    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__q 
                        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[6478]);
                }
            } else {
                ++(vlSelf->__Vcoverage[6479]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__q = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[6480]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[6481]);
            }
            ++(vlSelf->__Vcoverage[6482]);
            if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__q) 
                        ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6411, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__q;
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__q;
            if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6505, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__qs) 
                        ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6443, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__qs;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_step_qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__qs;
            if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6546, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_step_qs) 
                        ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__cfg0_step_qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2924, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_step_qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__cfg0_step_qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__cfg0_step_qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_step_qs;
            }
        }
    }
    if ((0x00000000000c0000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__10
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__rst_ni) {
                if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[6716]);
                    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__q 
                        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[6717]);
                }
            } else {
                ++(vlSelf->__Vcoverage[6718]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[6719]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[6720]);
            }
            ++(vlSelf->__Vcoverage[6721]);
            if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__q) 
                        ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(12, vlSelf->__Vcoverage + 6618, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__q;
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__q;
            if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(12, vlSelf->__Vcoverage + 6752, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__qs) 
                        ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(12, vlSelf->__Vcoverage + 6666, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__qs;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_prescale_qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__qs;
            if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(12, vlSelf->__Vcoverage + 6809, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_prescale_qs) 
                        ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__cfg0_prescale_qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(12, vlSelf->__Vcoverage + 2876, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_prescale_qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__cfg0_prescale_qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__cfg0_prescale_qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_prescale_qs;
            }
        }
    }
    if ((0x0000000000003000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__11
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__rst_ni) {
                if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[5355]);
                    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__q 
                        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[5356]);
                }
            } else {
                ++(vlSelf->__Vcoverage[5357]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__q = 0xffffffffU;
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[5358]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5359]);
            }
            ++(vlSelf->__Vcoverage[5360]);
            if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__q 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5097, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__q;
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__q;
            if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__q 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5431, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__q;
            if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__qs 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5225, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__qs;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__qs;
            if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5568, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_qs 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__compare_v0_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 3088, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__compare_v0_qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__compare_v0_qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_qs;
            }
        }
    }
    if ((0x0000000000300000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__12
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__rst_ni) {
                if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[6857]);
                    vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__q 
                        = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[6858]);
                }
            } else {
                ++(vlSelf->__Vcoverage[6859]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[6860]);
            }
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[6861]);
            }
            ++(vlSelf->__Vcoverage[6862]);
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__q) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6847, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__q;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__q;
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__q;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6875, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__q, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__q;
            }
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__qs) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6851, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT____Vtogcov__qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__qs;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_state0_qs 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__qs;
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_state0_qs) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_state0_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2866, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_state0_qs, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_state0_qs);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT____Vtogcov__intr_state0_qs 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_state0_qs;
            }
        }
    }
    if ((0x0000000000000c00ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__13(vlSelf);
    }
    if ((0x00000000003ff3fcULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x0000000000000c0cULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__1
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3332]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____VlemCond_0 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3333]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____VlemCond_0 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__qs;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__ds 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____VlemCond_0;
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3330]);
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3331]);
            }
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__ds) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3316, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__ds, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__ds);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT____Vtogcov__ds 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__ds;
            }
        }
    }
    if ((0x0000000000003c00ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__2
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[5363]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____VlemCond_0 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[5364]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____VlemCond_0 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__qs;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__ds 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____VlemCond_0;
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[5361]);
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[5362]);
            }
            if ((0U != (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__ds 
                        ^ vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5161, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__ds, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__ds);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT____Vtogcov__ds 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__ds;
            }
        }
    }
    if ((0x0000000000030c00ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__3
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[6485]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____VlemCond_0 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[6486]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____VlemCond_0 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__qs;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__ds 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____VlemCond_0;
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[6483]);
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[6484]);
            }
            if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__ds) 
                        ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__ds)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6427, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__ds, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__ds);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT____Vtogcov__ds 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__ds;
            }
        }
    }
    if ((0x00000000000c0c00ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__4
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[6724]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____VlemCond_0 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[6725]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____VlemCond_0 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__qs;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__ds 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____VlemCond_0;
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[6722]);
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[6723]);
            }
            if ((0U != ((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__ds) 
                        ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__ds)))) {
                VL_COV_TOGGLE_CHG_ST_I(12, vlSelf->__Vcoverage + 6642, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__ds, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__ds);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT____Vtogcov__ds 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__ds;
            }
        }
    }
    if ((0x0000000000000c30ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__5
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3381]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____VlemCond_0 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3382]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____VlemCond_0 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__qs;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__ds 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____VlemCond_0;
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3379]);
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3380]);
            }
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__ds) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3365, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__ds, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__ds);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT____Vtogcov__ds 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__ds;
            }
        }
    }
    if ((0x0000000000000cc0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__6
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3430]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____VlemCond_0 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3431]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____VlemCond_0 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__qs;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__ds 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____VlemCond_0;
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3428]);
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3429]);
            }
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__ds) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3414, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__ds, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__ds);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT____Vtogcov__ds 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__ds;
            }
        }
    }
    if ((0x0000000000000f00ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__7
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3479]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____VlemCond_0 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3480]);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____VlemCond_0 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__qs;
            }
            vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__ds 
                = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____VlemCond_0;
            if (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3477]);
            }
            if ((1U & (~ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3478]);
            }
            if (((IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__ds) 
                 ^ (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3463, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__ds, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__ds);
                vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT____Vtogcov__ds 
                    = vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__ds;
            }
        }
    }
    if ((0x0000000000fffffcULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__8(vlSelf);
    }
    if ((0x0000000000ffffffULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__9(vlSelf);
    }
    if ((0x0000000003ffffffULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__10(vlSelf);
    }
}

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers_vec__act(vlSelf);
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        {
            // Inlined CFunc: _timing_resume
            if ((0x0000000010000000ULL & vlSelfRef.__VactTriggered[0U])) {
                vlSelfRef.__VdlySched.resume();
            }
        }
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__inact(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__inact\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("/tmp/flexsoc-repack/rv_timer/runs/rv_timer/dev/dv/functional/tb/cocotb/rv_timer_tb.sv", 2, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/tmp/flexsoc-repack/rv_timer/runs/rv_timer/dev/dv/functional/tb/cocotb/rv_timer_tb.sv", 2, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/tmp/flexsoc-repack/rv_timer/runs/rv_timer/dev/dv/functional/tb/cocotb/rv_timer_tb.sv", 2, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("/tmp/flexsoc-repack/rv_timer/runs/rv_timer/dev/dv/functional/tb/cocotb/rv_timer_tb.sv", 2, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("/tmp/flexsoc-repack/rv_timer/runs/rv_timer/dev/dv/functional/tb/cocotb/rv_timer_tb.sv", 2, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtop___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtop___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
