// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__clk_i__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rst_ni__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__clk_i__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__rst_ni__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__clk_i__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__rst_ni__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__clk_i__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__rst_ni__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__clk_i__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__rst_ni__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__clk_i__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__rst_ni__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__clk_i__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__rst_ni__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__clk_i__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__rst_ni__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__clk_i__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__rst_ni__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__clk_i__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__rst_ni__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__clk_i__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__rst_ni__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__clk_i__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__rst_ni__0 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__rst_ni;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__shadow_busy = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__intg_error = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__intg_error_o = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_data_width = 0x10U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_frac_width = 0x0eU;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_max_iter = 0x10U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_rsvd = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_rsvd = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__devmode_i = 1U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__de = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__d = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__de = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__d = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__de = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__d = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__de = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__d = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__de = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__d = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__de = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__d = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__wd = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__wd = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__wd = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__wd = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__de = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__d = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__de = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__d = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__de = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__d = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__wd = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__wd = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__wd = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__wd = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__wd = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__wd = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__wd = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__en_ifetch_i = 9U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__we = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__we = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__we = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__we = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__we = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__we = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__we = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__we = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__we = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__we = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__we = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__en_i = 1U;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/tb/cocotb/cordic_tb.sv", 5, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vtop___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge cordic_tb.u_cordic.u_cordic_reg.u_reg_if.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge cordic_tb.u_cordic.u_cordic_reg.u_reg_if.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge cordic_tb.u_cordic.u_cordic_reg.u_ctrl_start.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(negedge cordic_tb.u_cordic.u_cordic_reg.u_ctrl_start.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge cordic_tb.u_cordic.u_cordic_reg.u_ctrl_mode.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(negedge cordic_tb.u_cordic.u_cordic_reg.u_ctrl_mode.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @(posedge cordic_tb.u_cordic.u_cordic_reg.u_ctrl_soft_rst.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @(negedge cordic_tb.u_cordic.u_cordic_reg.u_ctrl_soft_rst.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 8 is active: @(posedge cordic_tb.u_cordic.u_cordic_reg.u_ctrl_rsvd.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 9 is active: @(negedge cordic_tb.u_cordic.u_cordic_reg.u_ctrl_rsvd.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 10 is active: @(posedge cordic_tb.u_cordic.u_cordic_reg.u_ctrl_n_iter.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 11 is active: @(negedge cordic_tb.u_cordic.u_cordic_reg.u_ctrl_n_iter.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 12 is active: @(posedge cordic_tb.u_cordic.u_cordic_reg.u_ctrl_rsvd2.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 13 is active: @(negedge cordic_tb.u_cordic.u_cordic_reg.u_ctrl_rsvd2.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 14 is active: @(posedge cordic_tb.u_cordic.u_cordic_reg.u_x_in.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 15 is active: @(negedge cordic_tb.u_cordic.u_cordic_reg.u_x_in.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000010U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 16 is active: @(posedge cordic_tb.u_cordic.u_cordic_reg.u_y_in.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000011U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 17 is active: @(negedge cordic_tb.u_cordic.u_cordic_reg.u_y_in.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000012U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 18 is active: @(posedge cordic_tb.u_cordic.u_cordic_reg.u_z_in.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000013U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 19 is active: @(negedge cordic_tb.u_cordic.u_cordic_reg.u_z_in.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000014U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 20 is active: @(posedge cordic_tb.u_cordic.u_cordic_core.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000015U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 21 is active: @(negedge cordic_tb.u_cordic.u_cordic_core.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000016U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 22 is active: @(posedge cordic_tb.u_cordic.u_cordic_core.u_start_edge_detect.u_sync_1.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000017U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 23 is active: @(negedge cordic_tb.u_cordic.u_cordic_core.u_start_edge_detect.u_sync_1.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000018U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 24 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->cordic_tb__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6735956319256138963ull);
    vlSelf->cordic_tb__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1025198360778527103ull);
    vlSelf->cordic_tb__DOT__tl_i_a_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11637289707001611844ull);
    vlSelf->cordic_tb__DOT__tl_i_a_opcode = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11874097941539681935ull);
    vlSelf->cordic_tb__DOT__tl_i_a_param = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9777940468562153182ull);
    vlSelf->cordic_tb__DOT__tl_i_a_size = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14170288673523855237ull);
    vlSelf->cordic_tb__DOT__tl_i_a_source = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6462098650315036966ull);
    vlSelf->cordic_tb__DOT__tl_i_a_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2238180611824269073ull);
    vlSelf->cordic_tb__DOT__tl_i_a_mask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1826395113212692191ull);
    vlSelf->cordic_tb__DOT__tl_i_a_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8852015192371920249ull);
    vlSelf->cordic_tb__DOT__tl_i_d_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3536226788928743741ull);
    vlSelf->cordic_tb__DOT__tl_o_d_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6695649204650314591ull);
    vlSelf->cordic_tb__DOT__tl_o_d_opcode = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5411638367528459124ull);
    vlSelf->cordic_tb__DOT__tl_o_d_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11358683523337313614ull);
    vlSelf->cordic_tb__DOT__tl_o_d_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2903530908119415188ull);
    vlSelf->cordic_tb__DOT__tl_o_a_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2274751896810664136ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->cordic_tb__DOT__tl_i, __VscopeHash, 9592408971627892002ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->cordic_tb__DOT__tl_o, __VscopeHash, 15180404483383826301ull);
    vlSelf->cordic_tb__DOT__cmd_intg_calc = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 4318930157373316548ull);
    vlSelf->cordic_tb__DOT__data_intg_calc = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 184535441604412040ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->cordic_tb__DOT__unnamedblk1__DOT__t, __VscopeHash, 13057269903248592517ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5759925584833853963ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8567367620103098509ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->cordic_tb__DOT__u_cordic__DOT__tl_i, __VscopeHash, 6859964941318988699ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->cordic_tb__DOT__u_cordic__DOT__tl_o, __VscopeHash, 15380371906024719069ull);
    VL_SCOPED_RAND_RESET_W(299, vlSelf->cordic_tb__DOT__u_cordic__DOT__reg2hw, __VscopeHash, 18357637142092813695ull);
    VL_SCOPED_RAND_RESET_W(160, vlSelf->cordic_tb__DOT__u_cordic__DOT__hw2reg, __VscopeHash, 13632984207790086892ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13153976358769387723ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3780380894223388063ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i, __VscopeHash, 4716070033233996995ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o, __VscopeHash, 1907849780478099349ull);
    VL_SCOPED_RAND_RESET_W(299, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw, __VscopeHash, 12673226072276979502ull);
    VL_SCOPED_RAND_RESET_W(160, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg, __VscopeHash, 15883906682345555102ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__devmode_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2770007987258663867ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16281708009387615651ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18325403223178530387ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_addr = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 6168021565312205305ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 695873745361983865ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6623968620292541522ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1444563834220206156ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2302456468424070085ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addrmiss = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5623418163709608841ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__wr_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5702617443764084428ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14297063867891561346ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1691781343543180227ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d, __VscopeHash, 3274263585851391663ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h, __VscopeHash, 15079959113044134939ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre, __VscopeHash, 8187138180914065303ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12093480756288151057ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_start_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18173241614599889502ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_start_wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14107387511722534602ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_mode_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5069519979037447448ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_mode_wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10630985086006483024ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_soft_rst_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12366336197810793385ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_soft_rst_wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3956675983987989908ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd_qs = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15082646079696008238ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd_wd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7561015203439016015ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_n_iter_qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 956691005256510183ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_n_iter_wd = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18169576307741266659ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd2_qs = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3669709189248194663ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd2_wd = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8136337614478282091ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15711814360044984829ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_busy_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14973646550554599082ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_valid_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12510605685014611179ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_error_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5682264746090092043ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_rsvd_qs = VL_SCOPED_RAND_RESET_I(29, __VscopeHash, 4157014152123802048ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14384246869976556544ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_qs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9330080421839013867ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11255377025781184762ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6353480448158960001ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_qs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6895930595439833181ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 858699198700089458ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13842107472109143925ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_qs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1024657302827828005ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10554987208134127772ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_out_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13351610468698165384ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_out_qs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12134115906229911803ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_out_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15222517978662515546ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_out_qs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4524968371477151953ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_out_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10521498218861097891ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_out_qs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14682713984887258538ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 620013688954243848ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_data_width_qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7202584933400536820ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_frac_width_qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2883906755547236980ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_max_iter_qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4306636104876393641ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_rsvd_qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1085610167678889863ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 1765083263541805921ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__shadow_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5436168337237412984ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__unused_wdata = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11821789377377993181ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__unused_be = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 214920647070688144ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i, __VscopeHash, 4087428442043913785ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o, __VscopeHash, 8864603815861123583ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__unused_tl = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8418571255829778181ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6743504532686622089ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15080887196621739807ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i, __VscopeHash, 4579119445804761828ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o, __VscopeHash, 2122652411071875261ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__en_ifetch_i = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5492739404976701203ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__intg_error_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3810225350908119285ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__re_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18097569387779351312ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__we_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2674232220280960701ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__addr_o = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 3860268868380331644ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__wdata_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10850931857434629396ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__be_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13006514368009904356ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__busy_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3691876424363769397ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1317550384543712110ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14081072472950222553ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__outstanding_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1834184613489284145ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__a_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18377879615909926075ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__d_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 533162504347444477ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11070079179236195299ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11386237517256136334ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7949250096912336061ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13909430537988679758ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__err_internal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1943627485065918989ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__instr_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15925017687979126265ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__intg_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17184699415462145629ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__addr_align_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18050350025893044682ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__malformed_meta_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6454133338737609927ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3553783722920741152ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqid_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12649263069213115888ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqsz_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4247365806255559744ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rspop_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9923498408162294939ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rd_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17527615238144425278ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__wr_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12360313289961915237ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre, __VscopeHash, 7166728259720883313ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i, __VscopeHash, 6688397758670553041ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o, __VscopeHash, 10837928343665594652ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__unused_tl = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3402184788727731544ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3691412989429693649ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13255308200080933496ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i, __VscopeHash, 8798442253922130519ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3738847035553811610ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__opcode_allowed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15692916965691909986ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__a_config_allowed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6793688763129267371ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10842705996528497849ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_partial = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17728459087444018141ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_get = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10260936427671253541ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7093772731793891213ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2430443243941090671ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 261394793304841545ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17186786580857904209ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10392967373783959546ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12694349405854141852ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15287953083520607745ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11608773042793498298ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12494708187831834971ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6615150069587302666ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3947489658211657297ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11470938357376946598ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 907574960918729526ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6884574698767879828ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15062912693438577753ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5985450004627880627ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5648129353859762490ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12472094626651117129ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7607030217412889216ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8384553990753112712ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6888208599566698369ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17361728821756038695ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10249973859115091443ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17979826448490814086ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15474389605079216890ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10524958890541137620ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4821126139824116400ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5931547591669788828ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5313674402481814058ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14326193990662332707ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12462712595836255820ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13818359057174655042ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3395075050004205797ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12753752929880128007ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12407570181598418900ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12672998479191668453ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4145962255775528582ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14142120002391795168ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16175514163494743398ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3729809142003786610ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9336559207576840862ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5180173226375367391ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6287480031557234023ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17723755854909487006ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2506377840030002688ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9088500407135738897ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10995276045088072919ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17596779941636553866ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4276346848293470314ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5557359128230842759ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9774690417204505688ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15156666911804019021ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6945060950454163894ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15856735543280917119ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16745697697954838347ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 878252562343476920ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13565970464846285023ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6100617348419655838ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2546870492499915544ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17216209066534769692ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13985278798339625357ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2525314477467676112ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16311979011426853248ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1023200357875858647ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9548525191330985626ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11406992862677644028ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13995718289426033332ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1962813332581296231ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5760361096722082723ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5441933392023527074ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1562816929571694871ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__d = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15439172737957217317ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7631878877079767385ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__q = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6794282580999242607ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__ds = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9597711179095681364ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__qs = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15666773126603639197ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8881369132588798754ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_data = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6985843762728728574ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17815058476472661689ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16133995297443093908ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6814223267981216674ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__d = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7331713178630819678ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 199510772202714826ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16282239442514601083ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6513282914347531394ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9473836701835005136ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6141517071661191341ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16563707662329090774ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8121285647258784889ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wd = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1381813362452154033ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11480608159757842448ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__d = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2301164293541491460ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3523786477523179271ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11481531242898441085ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__ds = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3382452530594162816ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9671032249864868599ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1554545050358126821ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11992256678763352ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10783011789795912291ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 853639640807451893ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15131862103619137861ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__d = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7772471750326574050ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8659459180847438717ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 934489286075827593ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4177529806119663112ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16438511337761948377ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6148768143415738770ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1205807402971192434ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11832229924044959668ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wd = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2289542983593797427ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13401662707207772662ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__d = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12272113774371484457ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3504147773085102969ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7245284137848804550ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__ds = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2500874130582696451ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__qs = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4907314170085892643ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4602596616359919364ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10681385019325433460ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1704017531114430101ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15950393358627949711ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4556667217674665370ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__d = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3726722311535910984ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2788274059033056283ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6444391604564649706ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15306184234055898288ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17677494911868547534ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12996475480648751571ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1543989563462078741ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4528380507136508316ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15508029358872878861ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10107627438059813246ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6232555958365373798ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 521420591414513168ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 719053093782497159ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17262616613420114258ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15889044681403509813ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12289664381186270809ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4663889051561021767ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4899510389164511251ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17910494122274575057ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3681149244119511768ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14057270347431021317ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 584630809679821754ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8418448466132239637ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9604458093276654663ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15164306727391208839ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14843143252100390370ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8974932439955457743ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15839532740470102450ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7889512789681877830ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15529999174544963925ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6960351221796727228ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15940378796317888328ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1579741753466228124ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9111968801166767652ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__wd = VL_SCOPED_RAND_RESET_I(29, __VscopeHash, 9641653114743972874ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__d = VL_SCOPED_RAND_RESET_I(29, __VscopeHash, 13661833231689054638ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12370186903444065230ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5564963235240788492ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__q = VL_SCOPED_RAND_RESET_I(29, __VscopeHash, 18244634882380278918ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__ds = VL_SCOPED_RAND_RESET_I(29, __VscopeHash, 18200682325179403964ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qs = VL_SCOPED_RAND_RESET_I(29, __VscopeHash, 12620404075930222106ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1057963160864908800ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6773709451378122936ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2773621292074983576ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16372313218105538149ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10660263789870361373ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7343096364541686027ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17371283617005793601ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3240626524370924054ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__ds = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18172757032515414950ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__qs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3441865491259944481ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7024330924468560704ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1021331952511164863ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9648988473441710132ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9364484373775001787ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16366046846182283146ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3443003888778675719ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11480658051272138479ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13214739917745181942ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1086401321466058389ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11394790864662380245ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11860644451394863540ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9668328327943351591ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13196681109121791074ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3266520608772768676ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14077086253659424100ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2561830143256647693ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8196620113674749987ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7129771862004222556ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__ds = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13393200617733383236ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__qs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15357299294351958493ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11356100874412815708ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9030456792571526151ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12748636094482386619ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6846782639371319699ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17261197117377410520ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18028568707032951527ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11254513113509051789ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13902973185102762676ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1835348356555423926ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11896561839927941833ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4951980977128463777ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12894300786226804665ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2757390348331831865ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13610160239067258116ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15110022804653576881ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16838348730038934609ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16347069035707914023ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4474969294335664606ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__ds = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5226927134173089711ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__qs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6679721239127179778ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3497551757257655108ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6752743153539623421ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13029742620452967379ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12427790955913433838ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17717951611772028498ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15832548783256718845ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16149329166817466157ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5359359848956191163ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14636218452864464725ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13651003446741713160ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12865316312281430898ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14328256037427402895ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6612387284614461243ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7454518123986237075ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12095022668939723621ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15910180245950465245ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14182858752295017428ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__ds = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12416062525227822678ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5906279548896951832ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18380532793120418739ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17168516692189002184ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1936939203136784618ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3778905917545262594ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16664084726867430368ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3309180901302759905ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2124108597656599994ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__ds = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1288941835844358057ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16472439079617672350ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13203962414585894875ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17421870782149209700ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9803772627983687221ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12513411816583830374ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11045350402263357576ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1263983070522948367ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1576256257175606344ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__ds = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9966085795181810441ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14484538946880600914ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14325587628024823216ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7808061437488434515ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__wd = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4146096066646581634ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__d = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14206532967257043401ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11029281727515536433ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2332473878314732599ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8687992898565313600ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__ds = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15193796835826022745ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6667768524430544153ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6980149109353217908ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11884729625353594751ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__wd = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9280794877461483675ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__d = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10150740006722464517ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16542063408628483893ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1285251655983994404ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3257327818300202173ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__ds = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6368164178256987075ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12771049775012773592ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7410411068595584659ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11326036058063477355ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__wd = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12053184566702295419ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__d = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8891252222915494805ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4268414102652882884ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7535339423269182366ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1110936900863763190ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__ds = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2294347930535605791ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17478859605968515690ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8638604869334415045ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8931058464004908288ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__wd = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6610844384770143442ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__d = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2309730601809702746ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 136317188624085051ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6069213808326137620ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17820863297707234300ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__ds = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9350691994767231986ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2661244210267412418ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8694344156469869964ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13243434850791274134ull);
    VL_SCOPED_RAND_RESET_W(299, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw, __VscopeHash, 11970617371540365772ull);
    VL_SCOPED_RAND_RESET_W(160, vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg, __VscopeHash, 15010096583699832552ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1659891517492563412ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_mode = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10869461260836988701ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_soft_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2285134452130171379ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_rsvd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8233141868678630410ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_n_iter = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17600258787842530729ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_rsvd2 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16773098173267723702ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14865783236137485468ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17385882830826600724ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8649955283557579651ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_rsvd = VL_SCOPED_RAND_RESET_I(29, __VscopeHash, 9166344107914407136ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_in_value = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10066584337719395337ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_in_value = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12278211466090531094ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_in_value = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4139733841494569096ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_out_value = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2080707272919456615ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_out_value = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8017796407674940033ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_out_value = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12558679581810537981ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_data_width = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3638637833647677970ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_frac_width = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3252134324941401453ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_max_iter = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13577701228329198956ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_rsvd = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12745746884529636303ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16141562044391911933ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8222147480046828017ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q = VL_SCOPED_RAND_RESET_I(19, __VscopeHash, 1143619205333259300ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_d = VL_SCOPED_RAND_RESET_I(19, __VscopeHash, 13056908579869598403ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q = VL_SCOPED_RAND_RESET_I(19, __VscopeHash, 1474796724046140077ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_d = VL_SCOPED_RAND_RESET_I(19, __VscopeHash, 17300738337995004367ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6360463235989706958ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_d = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7545516879352955949ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11697718755187227543ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_d = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15143928343858749056ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14719779220377673761ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_d = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 917840154928275346ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13121133010392516764ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15677987658971356843ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 655775854742656668ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10510058950081484761ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__start_rise = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3170601259497289183ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__start_fall_unused = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10888059989209194724ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_eff = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6564006150498820187ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_invalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13465089851170573050ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_init = VL_SCOPED_RAND_RESET_I(19, __VscopeHash, 17632468262221921008ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_init = VL_SCOPED_RAND_RESET_I(19, __VscopeHash, 15698240079760105971ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14173279031480834902ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_shift = VL_SCOPED_RAND_RESET_I(19, __VscopeHash, 3524963411964625821ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_shift = VL_SCOPED_RAND_RESET_I(19, __VscopeHash, 18029283920169371210ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step = VL_SCOPED_RAND_RESET_I(19, __VscopeHash, 48508317382171638ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step = VL_SCOPED_RAND_RESET_I(19, __VscopeHash, 16310820168742599658ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12576254634573193719ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_out_next_32 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12208125656493762800ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_out_next_32 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7220965807579264072ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_out_next_32 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15853654050298351828ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int = VL_SCOPED_RAND_RESET_I(19, __VscopeHash, 17817434022080953737ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int = VL_SCOPED_RAND_RESET_I(19, __VscopeHash, 13947790062268515444ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__z_in_int = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13647054162479217069ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk2__DOT__x_final_visible = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15388572720509246059ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk2__DOT__y_final_visible = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9481145235124903456ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16330332729736761364ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12799614488502253096ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4953712307342043053ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17770246308181645796ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__r_edge_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2677450817052601575ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__f_edge_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16121761107956014425ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6078487597744624309ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7275348838547035017ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1471527353618551148ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__d_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 893302482776546216ull);
    vlSelf->cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__q_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 925071017822138290ull);
    vlSelf->__Vfunc_extract_h2d_cmd_intg__1__payload = 0;
    vlSelf->__Vfunc_prim_secded_inv_64_57_enc__2__Vfuncout = 0;
    vlSelf->__Vfunc_prim_secded_inv_64_57_enc__2__data_i = 0;
    vlSelf->__Vfunc_prim_secded_inv_64_57_enc__2__data_o = 0;
    vlSelf->__Vfunc_prim_secded_inv_64_57_enc__3__Vfuncout = 0;
    vlSelf->__Vfunc_prim_secded_inv_64_57_enc__3__data_i = 0;
    vlSelf->__Vfunc_prim_secded_inv_64_57_enc__3__data_o = 0;
    vlSelf->__Vfunc_mubi4_test_invalid__6__Vfuncout = 0;
    vlSelf->__Vfunc_mubi4_test_invalid__6__val = 0;
    vlSelf->__Vfunc_mubi4_test_true_strict__7__Vfuncout = 0;
    vlSelf->__Vfunc_mubi4_test_true_strict__7__val = 0;
    vlSelf->__Vfunc_mubi4_test_false_loose__8__Vfuncout = 0;
    vlSelf->__Vfunc_mubi4_test_false_loose__8__val = 0;
    vlSelf->__Vfunc_mubi4_test_true_strict__11__Vfuncout = 0;
    vlSelf->__Vfunc_mubi4_test_true_strict__11__val = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__rst_ni__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
