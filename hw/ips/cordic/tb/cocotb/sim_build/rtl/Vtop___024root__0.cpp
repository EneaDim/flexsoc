// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);
VlCoroutine Vtop___024root___eval_initial__TOP__Vtiming__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    Vtop___024root___eval_initial__TOP__Vtiming__0(vlSelf);
}

VlCoroutine Vtop___024root___eval_initial__TOP__Vtiming__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("cordic_tb.vcd"s);
    vlSymsp->_traceDumpOpen();
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/tb/cocotb/cordic_tb.sv", 
                                         78);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
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

extern const VlUnpacked<CData/*0:0*/, 2048> Vtop__ConstPool__TABLE_he7e48997_0;

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_2;
    cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_2 = 0;
    CData/*0:0*/ cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_3;
    cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_3 = 0;
    IData/*18:0*/ cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h6234dd4b__0;
    cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h6234dd4b__0 = 0;
    IData/*18:0*/ cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h1b1e1e5a__0;
    cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h1b1e1e5a__0 = 0;
    SData/*15:0*/ cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h30a90f11__0;
    cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h30a90f11__0 = 0;
    CData/*6:0*/ __Vfunc_get_cmd_intg__0__Vfuncout;
    __Vfunc_get_cmd_intg__0__Vfuncout = 0;
    VlWide<4>/*108:0*/ __Vfunc_get_cmd_intg__0__tl;
    VL_ZERO_W(109, __Vfunc_get_cmd_intg__0__tl);
    CData/*6:0*/ __Vfunc_get_cmd_intg__0__cmd_intg;
    __Vfunc_get_cmd_intg__0__cmd_intg = 0;
    QData/*56:0*/ __Vfunc_get_cmd_intg__0__unused_cmd_payload;
    __Vfunc_get_cmd_intg__0__unused_cmd_payload = 0;
    QData/*42:0*/ __Vfunc_get_cmd_intg__0__cmd;
    __Vfunc_get_cmd_intg__0__cmd = 0;
    QData/*42:0*/ __Vfunc_extract_h2d_cmd_intg__1__Vfuncout;
    __Vfunc_extract_h2d_cmd_intg__1__Vfuncout = 0;
    VlWide<4>/*108:0*/ __Vfunc_extract_h2d_cmd_intg__1__tl;
    VL_ZERO_W(109, __Vfunc_extract_h2d_cmd_intg__1__tl);
    CData/*6:0*/ __Vfunc_get_data_intg__4__Vfuncout;
    __Vfunc_get_data_intg__4__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_get_data_intg__4__data;
    __Vfunc_get_data_intg__4__data = 0;
    CData/*6:0*/ __Vfunc_get_data_intg__4__data_intg;
    __Vfunc_get_data_intg__4__data_intg = 0;
    QData/*38:0*/ __Vfunc_get_data_intg__4__enc_data;
    __Vfunc_get_data_intg__4__enc_data = 0;
    QData/*38:0*/ __Vfunc_prim_secded_inv_39_32_enc__5__Vfuncout;
    __Vfunc_prim_secded_inv_39_32_enc__5__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_prim_secded_inv_39_32_enc__5__data_i;
    __Vfunc_prim_secded_inv_39_32_enc__5__data_i = 0;
    QData/*38:0*/ __Vfunc_prim_secded_inv_39_32_enc__5__data_o;
    __Vfunc_prim_secded_inv_39_32_enc__5__data_o = 0;
    CData/*0:0*/ __Vfunc_tl_a_user_chk__9__Vfuncout;
    __Vfunc_tl_a_user_chk__9__Vfuncout = 0;
    IData/*22:0*/ __Vfunc_tl_a_user_chk__9__user;
    __Vfunc_tl_a_user_chk__9__user = 0;
    CData/*0:0*/ __Vfunc_tl_a_user_chk__9__malformed_err;
    __Vfunc_tl_a_user_chk__9__malformed_err = 0;
    CData/*0:0*/ __Vfunc_mubi4_test_invalid__10__Vfuncout;
    __Vfunc_mubi4_test_invalid__10__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_mubi4_test_invalid__10__val;
    __Vfunc_mubi4_test_invalid__10__val = 0;
    CData/*0:0*/ __Vfunc_mubi4_test_invalid__12__Vfuncout;
    __Vfunc_mubi4_test_invalid__12__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_mubi4_test_invalid__12__val;
    __Vfunc_mubi4_test_invalid__12__val = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__Vfuncout = 0;
    IData/*18:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__value_i;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__value_i = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__Vfuncout = 0;
    IData/*18:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__value_i;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__value_i = 0;
    IData/*31:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__value_i;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__value_i = 0;
    IData/*31:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__value_i;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__value_i = 0;
    IData/*31:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__value_i;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__value_i = 0;
    IData/*18:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__csr_word;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__csr_word = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__narrow_value;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__narrow_value = 0;
    IData/*18:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__csr_word;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__csr_word = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__narrow_value;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__narrow_value = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__csr_word;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__csr_word = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__narrow_value;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__narrow_value = 0;
    SData/*10:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    if ((1U & (~ VL_ONEHOT_I((((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q) 
                               << 1U) | (1U & (~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q)))))))) {
        if ((0U != (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q) 
                     << 1U) | (1U & (~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q)))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: cordic_core.sv:360: Assertion failed in %Ncordic_tb.u_cordic.u_cordic_core: unique case, but multiple matches found for '1'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),1,(IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q));
                VL_STOP_MT("/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl/cordic_core.sv", 360, "");
            }
        }
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__de 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__de;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__de 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__de;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__de 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__de;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__de 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__de;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__de 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__de;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__de 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__de;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__de 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__de;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__de 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__de;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__de 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__de;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_shift 
        = (0x0007ffffU & VL_SHIFTRS_III(19,19,5, vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q, (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_shift 
        = (0x0007ffffU & VL_SHIFTRS_III(19,19,5, vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q, (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q;
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_q) {
        if (VL_LTES_III(32, 0U, VL_EXTENDS_II(32,19, vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q))) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step 
                = (0x0000ffffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q) 
                                  + vlSymsp->TOP__cordic_lut_pkg.AtanLut
                                  [(0x0000000fU & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q))]));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step 
                = (0x0007ffffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q 
                                  - vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_shift));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step 
                = (0x0007ffffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q 
                                  + vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_shift));
        } else {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step 
                = (0x0000ffffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q) 
                                  - vlSymsp->TOP__cordic_lut_pkg.AtanLut
                                  [(0x0000000fU & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q))]));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step 
                = (0x0007ffffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q 
                                  + vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_shift));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step 
                = (0x0007ffffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q 
                                  - vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_shift));
        }
    } else if (VL_LTES_III(32, 0U, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q)))) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step 
            = (0x0000ffffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q) 
                              - vlSymsp->TOP__cordic_lut_pkg.AtanLut
                              [(0x0000000fU & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q))]));
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step 
            = (0x0007ffffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q 
                              + vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_shift));
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step 
            = (0x0007ffffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q 
                              - vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_shift));
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step 
            = (0x0000ffffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q) 
                              + vlSymsp->TOP__cordic_lut_pkg.AtanLut
                              [(0x0000000fU & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q))]));
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step 
            = (0x0007ffffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q 
                              - vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_shift));
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step 
            = (0x0007ffffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q 
                              + vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_shift));
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__clk_i 
        = vlSelfRef.cordic_tb__DOT__clk_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__rst_ni 
        = vlSelfRef.cordic_tb__DOT__rst_ni;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__q_o;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_busy 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata_q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error_q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_busy 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__shadow_busy;
    vlSelfRef.cordic_tb__DOT__tl_i[0U] = ((0x00ffffffU 
                                           & vlSelfRef.cordic_tb__DOT__tl_i[0U]) 
                                          | ((IData)(
                                                     (((QData)((IData)(vlSelfRef.cordic_tb__DOT__tl_i_a_mask)) 
                                                       << 0x00000020U) 
                                                      | (QData)((IData)(vlSelfRef.cordic_tb__DOT__tl_i_a_data)))) 
                                             << 0x00000018U));
    vlSelfRef.cordic_tb__DOT__tl_i[1U] = (((IData)(
                                                   (((QData)((IData)(vlSelfRef.cordic_tb__DOT__tl_i_a_mask)) 
                                                     << 0x00000020U) 
                                                    | (QData)((IData)(vlSelfRef.cordic_tb__DOT__tl_i_a_data)))) 
                                           >> 8U) | 
                                          ((vlSelfRef.cordic_tb__DOT__tl_i_a_address 
                                            << 0x0000001cU) 
                                           | ((IData)(
                                                      ((((QData)((IData)(vlSelfRef.cordic_tb__DOT__tl_i_a_mask)) 
                                                         << 0x00000020U) 
                                                        | (QData)((IData)(vlSelfRef.cordic_tb__DOT__tl_i_a_data))) 
                                                       >> 0x00000020U)) 
                                              << 0x00000018U)));
    vlSelfRef.cordic_tb__DOT__tl_i[2U] = (((0x00ffffffU 
                                            & (vlSelfRef.cordic_tb__DOT__tl_i_a_address 
                                               >> 4U)) 
                                           | ((IData)(
                                                      ((((QData)((IData)(vlSelfRef.cordic_tb__DOT__tl_i_a_mask)) 
                                                         << 0x00000020U) 
                                                        | (QData)((IData)(vlSelfRef.cordic_tb__DOT__tl_i_a_data))) 
                                                       >> 0x00000020U)) 
                                              >> 8U)) 
                                          | (((IData)(vlSelfRef.cordic_tb__DOT__tl_i_a_source) 
                                              << 0x0000001cU) 
                                             | (0x0f000000U 
                                                & (vlSelfRef.cordic_tb__DOT__tl_i_a_address 
                                                   >> 4U))));
    vlSelfRef.cordic_tb__DOT__tl_i[3U] = ((0x00001ff0U 
                                           & vlSelfRef.cordic_tb__DOT__tl_i[3U]) 
                                          | (0x00001fffU 
                                             & ((IData)(vlSelfRef.cordic_tb__DOT__tl_i_a_source) 
                                                >> 4U)));
    vlSelfRef.cordic_tb__DOT__tl_i[3U] = ((0x0000000fU 
                                           & vlSelfRef.cordic_tb__DOT__tl_i[3U]) 
                                          | (0x00001fffU 
                                             & (((((IData)(vlSelfRef.cordic_tb__DOT__tl_i_a_valid) 
                                                   << 8U) 
                                                  | ((IData)(vlSelfRef.cordic_tb__DOT__tl_i_a_opcode) 
                                                     << 5U)) 
                                                 | (((IData)(vlSelfRef.cordic_tb__DOT__tl_i_a_param) 
                                                     << 2U) 
                                                    | (IData)(vlSelfRef.cordic_tb__DOT__tl_i_a_size))) 
                                                << 4U)));
    __Vfunc_get_data_intg__4__data = vlSelfRef.cordic_tb__DOT__tl_i_a_data;
    __Vfunc_prim_secded_inv_39_32_enc__5__data_i = __Vfunc_get_data_intg__4__data;
    __Vfunc_prim_secded_inv_39_32_enc__5__data_o = (QData)((IData)(__Vfunc_prim_secded_inv_39_32_enc__5__data_i));
    __Vfunc_prim_secded_inv_39_32_enc__5__data_o = 
        ((0x0000007effffffffULL & __Vfunc_prim_secded_inv_39_32_enc__5__data_o) 
         | ((QData)((IData)((1U & VL_REDXOR_64((0x000000002606bd25ULL 
                                                & __Vfunc_prim_secded_inv_39_32_enc__5__data_o))))) 
            << 0x00000020U));
    __Vfunc_prim_secded_inv_39_32_enc__5__data_o = 
        ((0x0000007dffffffffULL & __Vfunc_prim_secded_inv_39_32_enc__5__data_o) 
         | ((QData)((IData)((1U & VL_REDXOR_64((0x00000000deba8050ULL 
                                                & __Vfunc_prim_secded_inv_39_32_enc__5__data_o))))) 
            << 0x00000021U));
    __Vfunc_prim_secded_inv_39_32_enc__5__data_o = 
        ((0x0000007bffffffffULL & __Vfunc_prim_secded_inv_39_32_enc__5__data_o) 
         | ((QData)((IData)((1U & VL_REDXOR_64((0x00000000413d89aaULL 
                                                & __Vfunc_prim_secded_inv_39_32_enc__5__data_o))))) 
            << 0x00000022U));
    __Vfunc_prim_secded_inv_39_32_enc__5__data_o = 
        ((0x00000077ffffffffULL & __Vfunc_prim_secded_inv_39_32_enc__5__data_o) 
         | ((QData)((IData)((1U & VL_REDXOR_64((0x0000000031234ed1ULL 
                                                & __Vfunc_prim_secded_inv_39_32_enc__5__data_o))))) 
            << 0x00000023U));
    __Vfunc_prim_secded_inv_39_32_enc__5__data_o = 
        ((0x0000006fffffffffULL & __Vfunc_prim_secded_inv_39_32_enc__5__data_o) 
         | ((QData)((IData)((1U & VL_REDXOR_64((0x00000000c2c1323bULL 
                                                & __Vfunc_prim_secded_inv_39_32_enc__5__data_o))))) 
            << 0x00000024U));
    __Vfunc_prim_secded_inv_39_32_enc__5__data_o = 
        ((0x0000005fffffffffULL & __Vfunc_prim_secded_inv_39_32_enc__5__data_o) 
         | ((QData)((IData)((1U & VL_REDXOR_64((0x000000002dcc624cULL 
                                                & __Vfunc_prim_secded_inv_39_32_enc__5__data_o))))) 
            << 0x00000025U));
    __Vfunc_prim_secded_inv_39_32_enc__5__data_o = 
        ((0x0000003fffffffffULL & __Vfunc_prim_secded_inv_39_32_enc__5__data_o) 
         | ((QData)((IData)((1U & VL_REDXOR_64((0x0000000098505586ULL 
                                                & __Vfunc_prim_secded_inv_39_32_enc__5__data_o))))) 
            << 0x00000026U));
    __Vfunc_prim_secded_inv_39_32_enc__5__data_o = 
        (0x0000002a00000000ULL ^ __Vfunc_prim_secded_inv_39_32_enc__5__data_o);
    __Vfunc_prim_secded_inv_39_32_enc__5__Vfuncout 
        = __Vfunc_prim_secded_inv_39_32_enc__5__data_o;
    __Vfunc_get_data_intg__4__enc_data = __Vfunc_prim_secded_inv_39_32_enc__5__Vfuncout;
    __Vfunc_get_data_intg__4__data_intg = (0x0000007fU 
                                           & (IData)(
                                                     (__Vfunc_get_data_intg__4__enc_data 
                                                      >> 0x20U)));
    __Vfunc_get_data_intg__4__Vfuncout = __Vfunc_get_data_intg__4__data_intg;
    vlSelfRef.cordic_tb__DOT__data_intg_calc = __Vfunc_get_data_intg__4__Vfuncout;
    vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[0U] = 0U;
    vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[1U] = 0U;
    vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[2U] = 0U;
    vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[3U] = 0U;
    vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[1U] 
        = ((0x0fffffffU & vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[1U]) 
           | (vlSelfRef.cordic_tb__DOT__tl_i_a_address 
              << 0x0000001cU));
    vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[2U] 
        = ((0xf0000000U & vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[2U]) 
           | (vlSelfRef.cordic_tb__DOT__tl_i_a_address 
              >> 4U));
    vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[3U] 
        = ((0x000011ffU & vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[3U]) 
           | (0x00001fffU & ((IData)(vlSelfRef.cordic_tb__DOT__tl_i_a_opcode) 
                             << 9U)));
    vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[1U] 
        = ((0xf0ffffffU & vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[1U]) 
           | ((IData)(vlSelfRef.cordic_tb__DOT__tl_i_a_mask) 
              << 0x00000018U));
    vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[0U] 
        = (0x00048000U | (0xfff87fffU & vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[0U]));
    __Vfunc_get_cmd_intg__0__tl[0U] = vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[0U];
    __Vfunc_get_cmd_intg__0__tl[1U] = vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[1U];
    __Vfunc_get_cmd_intg__0__tl[2U] = vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[2U];
    __Vfunc_get_cmd_intg__0__tl[3U] = vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[3U];
    __Vfunc_extract_h2d_cmd_intg__1__tl[0U] = __Vfunc_get_cmd_intg__0__tl[0U];
    __Vfunc_extract_h2d_cmd_intg__1__tl[1U] = __Vfunc_get_cmd_intg__0__tl[1U];
    __Vfunc_extract_h2d_cmd_intg__1__tl[2U] = __Vfunc_get_cmd_intg__0__tl[2U];
    __Vfunc_extract_h2d_cmd_intg__1__tl[3U] = __Vfunc_get_cmd_intg__0__tl[3U];
    vlSelf->__Vfunc_extract_h2d_cmd_intg__1__payload = 0;
    vlSelfRef.__Vfunc_extract_h2d_cmd_intg__1__payload 
        = ((0x0000078000000000ULL & vlSelfRef.__Vfunc_extract_h2d_cmd_intg__1__payload) 
           | (((QData)((IData)(((__Vfunc_extract_h2d_cmd_intg__1__tl[2U] 
                                 << 4U) | (__Vfunc_extract_h2d_cmd_intg__1__tl[1U] 
                                           >> 0x0000001cU)))) 
               << 7U) | (QData)((IData)(((0x00000070U 
                                          & (__Vfunc_extract_h2d_cmd_intg__1__tl[3U] 
                                             >> 5U)) 
                                         | (0x0000000fU 
                                            & (__Vfunc_extract_h2d_cmd_intg__1__tl[1U] 
                                               >> 0x00000018U)))))));
    vlSelfRef.__Vfunc_extract_h2d_cmd_intg__1__payload 
        = ((0x0000007fffffffffULL & vlSelfRef.__Vfunc_extract_h2d_cmd_intg__1__payload) 
           | ((QData)((IData)((0x0000000fU & (__Vfunc_extract_h2d_cmd_intg__1__tl[0U] 
                                              >> 0x0000000fU)))) 
              << 0x00000027U));
    __Vfunc_extract_h2d_cmd_intg__1__Vfuncout = vlSelfRef.__Vfunc_extract_h2d_cmd_intg__1__payload;
    __Vfunc_get_cmd_intg__0__cmd = __Vfunc_extract_h2d_cmd_intg__1__Vfuncout;
    __Vfunc_get_cmd_intg__0__cmd_intg = (0x0000007fU 
                                         & (IData)(
                                                   (([&]() {
                        vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_i 
                            = __Vfunc_get_cmd_intg__0__cmd;
                        vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o 
                            = vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_i;
                        vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o 
                            = ((0xfdffffffffffffffULL 
                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x0103fff800007fffULL 
                                                                   & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o))))) 
                                  << 0x00000039U));
                        vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o 
                            = ((0xfbffffffffffffffULL 
                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x017c1ff801ff801fULL 
                                                                   & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o))))) 
                                  << 0x0000003aU));
                        vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o 
                            = ((0xf7ffffffffffffffULL 
                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x01bde1f87e0781e1ULL 
                                                                   & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o))))) 
                                  << 0x0000003bU));
                        vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o 
                            = ((0xefffffffffffffffULL 
                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x01deee3b8e388e22ULL 
                                                                   & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o))))) 
                                  << 0x0000003cU));
                        vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o 
                            = ((0xdfffffffffffffffULL 
                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x01ef76cdb2c93244ULL 
                                                                   & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o))))) 
                                  << 0x0000003dU));
                        vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o 
                            = ((0xbfffffffffffffffULL 
                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x01f7bb56d5525488ULL 
                                                                   & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o))))) 
                                  << 0x0000003eU));
                        vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o 
                            = ((0x7fffffffffffffffULL 
                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x01fbdda769a46910ULL 
                                                                   & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o))))) 
                                  << 0x0000003fU));
                        vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o 
                            = (0x5400000000000000ULL 
                               ^ vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o);
                        vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__Vfuncout 
                            = vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__data_o;
                    }(), vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__2__Vfuncout) 
                                                    >> 0x00000039U)));
    __Vfunc_get_cmd_intg__0__unused_cmd_payload = (0x01ffffffffffffffULL 
                                                   & ([&]() {
                vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_i 
                    = __Vfunc_get_cmd_intg__0__cmd;
                vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o 
                    = vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_i;
                vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o 
                    = ((0xfdffffffffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o) 
                       | ((QData)((IData)((1U & VL_REDXOR_64(
                                                             (0x0103fff800007fffULL 
                                                              & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o))))) 
                          << 0x00000039U));
                vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o 
                    = ((0xfbffffffffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o) 
                       | ((QData)((IData)((1U & VL_REDXOR_64(
                                                             (0x017c1ff801ff801fULL 
                                                              & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o))))) 
                          << 0x0000003aU));
                vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o 
                    = ((0xf7ffffffffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o) 
                       | ((QData)((IData)((1U & VL_REDXOR_64(
                                                             (0x01bde1f87e0781e1ULL 
                                                              & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o))))) 
                          << 0x0000003bU));
                vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o 
                    = ((0xefffffffffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o) 
                       | ((QData)((IData)((1U & VL_REDXOR_64(
                                                             (0x01deee3b8e388e22ULL 
                                                              & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o))))) 
                          << 0x0000003cU));
                vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o 
                    = ((0xdfffffffffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o) 
                       | ((QData)((IData)((1U & VL_REDXOR_64(
                                                             (0x01ef76cdb2c93244ULL 
                                                              & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o))))) 
                          << 0x0000003dU));
                vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o 
                    = ((0xbfffffffffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o) 
                       | ((QData)((IData)((1U & VL_REDXOR_64(
                                                             (0x01f7bb56d5525488ULL 
                                                              & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o))))) 
                          << 0x0000003eU));
                vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o 
                    = ((0x7fffffffffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o) 
                       | ((QData)((IData)((1U & VL_REDXOR_64(
                                                             (0x01fbdda769a46910ULL 
                                                              & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o))))) 
                          << 0x0000003fU));
                vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o 
                    = (0x5400000000000000ULL ^ vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o);
                vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__Vfuncout 
                    = vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__data_o;
            }(), vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__3__Vfuncout));
    __Vfunc_get_cmd_intg__0__Vfuncout = __Vfunc_get_cmd_intg__0__cmd_intg;
    vlSelfRef.cordic_tb__DOT__cmd_intg_calc = __Vfunc_get_cmd_intg__0__Vfuncout;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__q;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__value_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__Vfuncout 
        = (((- (IData)((1U & ((IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__value_i) 
                              >> 0x0fU)))) << 0x00000010U) 
           | (IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__value_i));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_out_next_32 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__value_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__Vfuncout 
        = (VL_LTS_III(19, 0x00007fffU, __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__value_i)
            ? 0x00007fffU : (VL_GTS_III(19, 0x00078000U, __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__value_i)
                              ? 0x00008000U : (0x0000ffffU 
                                               & __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__value_i)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk2__DOT__y_final_visible 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__value_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk2__DOT__y_final_visible;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__Vfuncout 
        = (((- (IData)((1U & ((IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__value_i) 
                              >> 0x0fU)))) << 0x00000010U) 
           | (IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__value_i));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_out_next_32 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__value_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__Vfuncout 
        = (VL_LTS_III(19, 0x00007fffU, __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__value_i)
            ? 0x00007fffU : (VL_GTS_III(19, 0x00078000U, __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__value_i)
                              ? 0x00008000U : (0x0000ffffU 
                                               & __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__value_i)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk2__DOT__x_final_visible 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__value_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk2__DOT__x_final_visible;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__Vfuncout 
        = (((- (IData)((1U & ((IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__value_i) 
                              >> 0x0fU)))) << 0x00000010U) 
           | (IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__value_i));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_out_next_32 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__Vfuncout;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_start_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_mode_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_soft_rst_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_n_iter_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd2_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__clk_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__clk_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__clk_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__clk_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__rst_ni 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__rst_ni;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__rst_ni 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__rst_ni;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[0U] 
        = (IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_out_value)) 
                    << 0x00000020U) | (QData)((IData)(
                                                      ((((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_data_width) 
                                                         << 0x00000018U) 
                                                        | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_frac_width) 
                                                           << 0x00000010U)) 
                                                       | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_max_iter) 
                                                           << 8U) 
                                                          | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_rsvd)))))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[1U] 
        = (IData)(((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_out_value)) 
                     << 0x00000020U) | (QData)((IData)(
                                                       ((((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_data_width) 
                                                          << 0x00000018U) 
                                                         | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_frac_width) 
                                                            << 0x00000010U)) 
                                                        | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_max_iter) 
                                                            << 8U) 
                                                           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_rsvd)))))) 
                   >> 0x00000020U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[2U] 
        = (IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_out_value)) 
                    << 0x00000020U) | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_out_value))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[3U] 
        = (IData)(((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_out_value)) 
                     << 0x00000020U) | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_out_value))) 
                   >> 0x00000020U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[4U] 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_busy) 
            << 0x0000001fU) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid) 
                                << 0x0000001eU) | (
                                                   ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error) 
                                                    << 0x0000001dU) 
                                                   | vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_rsvd)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__busy_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_busy;
    vlSelfRef.cordic_tb__DOT__tl_i[0U] = (0x00048000U 
                                          | ((0xfff80000U 
                                              & vlSelfRef.cordic_tb__DOT__tl_i[0U]) 
                                             | (((IData)(vlSelfRef.cordic_tb__DOT__cmd_intg_calc) 
                                                 << 8U) 
                                                | (((IData)(vlSelfRef.cordic_tb__DOT__data_intg_calc) 
                                                    << 1U) 
                                                   | (IData)(vlSelfRef.cordic_tb__DOT__tl_i_d_ready)))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__clk_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__clk_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__clk_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__clk_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__clk_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__clk_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__clk_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__clk_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__clk_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__clk_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__clk_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__clk_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__clk_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__clk_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__clk_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__clk_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__clk_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__clk_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__clk_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__clk_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__clk_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__clk_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__rst_ni 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__rst_ni;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__rst_ni 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__rst_ni;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__rst_ni 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__rst_ni;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__rst_ni 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__rst_ni;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__rst_ni 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__rst_ni;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__rst_ni 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__rst_ni;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__rst_ni 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__rst_ni;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__rst_ni 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__rst_ni;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__rst_ni 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__rst_ni;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__rst_ni 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__rst_ni;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rst_ni 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__rst_ni;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[3U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[3U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[4U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[4U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[0U] 
        = vlSelfRef.cordic_tb__DOT__tl_i[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[1U] 
        = vlSelfRef.cordic_tb__DOT__tl_i[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[2U] 
        = vlSelfRef.cordic_tb__DOT__tl_i[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[3U] 
        = vlSelfRef.cordic_tb__DOT__tl_i[3U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__clk_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__clk_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__clk_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__clk_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__rst_ni 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__rst_ni;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__rst_ni 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rst_ni;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[3U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[3U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[4U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[3U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[3U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__d 
        = (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U] 
           >> 0x0000001fU);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__d 
        = (1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U] 
                 >> 0x0000001eU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__d 
        = (1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U] 
                 >> 0x0000001dU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__d 
        = (0x1fffffffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U]);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[3U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__d 
        = (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U] 
           >> 0x00000018U);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__d 
        = (0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U] 
                          >> 0x00000010U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__d 
        = (0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U] 
                          >> 8U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__d 
        = (0x000000ffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U]);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[3U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[3U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[3U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_busy_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_valid_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_error_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_rsvd_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_out_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_out_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_out_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_data_width_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_frac_width_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_max_iter_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_rsvd_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qs;
    __Vfunc_tl_a_user_chk__9__user = (0x007fffffU & 
                                      (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                       >> 1U));
    __Vfunc_mubi4_test_invalid__10__val = (0x0000000fU 
                                           & (__Vfunc_tl_a_user_chk__9__user 
                                              >> 0x0000000eU));
    __Vfunc_mubi4_test_invalid__10__Vfuncout = (1U 
                                                & (~ 
                                                   ((6U 
                                                     == (IData)(__Vfunc_mubi4_test_invalid__10__val)) 
                                                    | (9U 
                                                       == (IData)(__Vfunc_mubi4_test_invalid__10__val)))));
    __Vfunc_tl_a_user_chk__9__malformed_err = __Vfunc_mubi4_test_invalid__10__Vfuncout;
    __Vfunc_tl_a_user_chk__9__Vfuncout = __Vfunc_tl_a_user_chk__9__malformed_err;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__malformed_meta_err 
        = __Vfunc_tl_a_user_chk__9__Vfuncout;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__instr_error 
        = (([&]() {
                vlSelfRef.__Vfunc_mubi4_test_invalid__6__val 
                    = (0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                      >> 0x0000000fU));
                vlSelfRef.__Vfunc_mubi4_test_invalid__6__Vfuncout 
                    = (1U & (~ ((6U == (IData)(vlSelfRef.__Vfunc_mubi4_test_invalid__6__val)) 
                                | (9U == (IData)(vlSelfRef.__Vfunc_mubi4_test_invalid__6__val)))));
            }(), (IData)(vlSelfRef.__Vfunc_mubi4_test_invalid__6__Vfuncout)) 
           | (([&]() {
                    vlSelfRef.__Vfunc_mubi4_test_true_strict__7__val 
                        = (0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                          >> 0x0000000fU));
                    vlSelfRef.__Vfunc_mubi4_test_true_strict__7__Vfuncout 
                        = (6U == (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__7__val));
                }(), (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__7__Vfuncout)) 
              & ([&]() {
                    vlSelfRef.__Vfunc_mubi4_test_false_loose__8__val 
                        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__en_ifetch_i;
                    vlSelfRef.__Vfunc_mubi4_test_false_loose__8__Vfuncout 
                        = (6U != (IData)(vlSelfRef.__Vfunc_mubi4_test_false_loose__8__val));
                }(), (IData)(vlSelfRef.__Vfunc_mubi4_test_false_loose__8__Vfuncout))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__wdata_o 
        = ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[1U] 
            << 8U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                      >> 0x00000018U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__be_o 
        = (0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                          >> 0x00000018U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__addr_o 
        = (0x0000003cU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[2U] 
                           << 4U) | (0x0000000cU & 
                                     (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                                      >> 0x0000001cU))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
        = (IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                    << 0x00000039U) | (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                        << 0x00000031U) 
                                       | (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata)) 
                                           << 0x00000010U) 
                                          | (QData)((IData)(
                                                            (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error) 
                                                              << 1U) 
                                                             | (1U 
                                                                & (~ 
                                                                   ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__outstanding_q) 
                                                                    | ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                                                        >> 0x0000000cU) 
                                                                       & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__busy_i))))))))))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
        = ((0xc0000000U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U]) 
           | (IData)(((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                        << 0x00000039U) | (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                            << 0x00000031U) 
                                           | (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata)) 
                                               << 0x00000010U) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error) 
                                                                  << 1U) 
                                                                 | (1U 
                                                                    & (~ 
                                                                       ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__outstanding_q) 
                                                                        | ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                                                            >> 0x0000000cU) 
                                                                           & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__busy_i))))))))))) 
                      >> 0x00000020U)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
        = ((0x3fffffffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U]) 
           | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rspop_q) 
              << 0x0000001eU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
        = (3U & ((0x3ffffffeU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__outstanding_q) 
                                 << 1U)) | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rspop_q) 
                                            >> 2U)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_wdata 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__wdata_o;
    __Vfunc_mubi4_test_invalid__12__val = (0x0000000fU 
                                           & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                              >> 0x0000000fU));
    __Vfunc_mubi4_test_invalid__12__Vfuncout = (1U 
                                                & (~ 
                                                   ((6U 
                                                     == (IData)(__Vfunc_mubi4_test_invalid__12__val)) 
                                                    | (9U 
                                                       == (IData)(__Vfunc_mubi4_test_invalid__12__val)))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err 
        = __Vfunc_mubi4_test_invalid__12__Vfuncout;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_get 
        = (4U == (7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                        >> 9U)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_full 
        = (0U == (7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                        >> 9U)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_partial 
        = (1U == (7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                        >> 9U)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask 
        = (0x0000000fU & ((IData)(1U) << (3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                                >> 0x0000001cU))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_be 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__be_o;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_addr 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__addr_o;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__unused_wdata 
        = (1U & VL_REDXOR_32(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_wdata));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_start_wd 
        = (1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_wdata);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_mode_wd 
        = (1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_wdata 
                 >> 1U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_soft_rst_wd 
        = (1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_wdata 
                 >> 2U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd_wd 
        = (0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_wdata 
                          >> 3U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_n_iter_wd 
        = (0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_wdata 
                          >> 8U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd2_wd 
        = (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_wdata 
           >> 0x00000010U);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_wdata;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_wdata;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_wdata;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__opcode_allowed 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_full) 
           | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_get) 
              | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_partial)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err 
        = (([&]() {
                vlSelfRef.__Vfunc_mubi4_test_true_strict__11__val 
                    = (0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                      >> 0x0000000fU));
                vlSelfRef.__Vfunc_mubi4_test_true_strict__11__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__11__val));
            }(), (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__11__Vfuncout)) 
           & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_full) 
              | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_partial)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk = 0U;
    if ((0x00001000U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U])) {
        if ((0U == (3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                          >> 4U)))) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk = 1U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk 
                = (1U & (~ (0U != (0x0000000fU & ((
                                                   (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                                    << 8U) 
                                                   | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                                      >> 0x00000018U)) 
                                                  & (~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask)))))));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk 
                = (0U != (((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                            << 8U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                      >> 0x00000018U)) 
                          & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask)));
        } else if ((1U == (3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                 >> 4U)))) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk 
                = (1U & (~ (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                            >> 0x0000001cU)));
            if ((0x20000000U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U])) {
                vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk 
                    = (1U & (~ (0U != (3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                             >> 0x00000018U)))));
                vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk 
                    = (3U == (3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                    >> 0x0000001aU)));
            } else {
                vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk 
                    = (1U & (~ (0U != (0x0cU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                                >> 0x00000018U)))));
                vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk 
                    = (3U == (3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                    >> 0x00000018U)));
            }
        } else if ((2U == (3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                 >> 4U)))) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk 
                = (1U & (~ (0U != (3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                         >> 0x0000001cU)))));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk = 1U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk 
                = (0x0000000fU == (0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                                  >> 0x00000018U)));
        } else {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk = 0U;
        }
        if ((1U & (~ VL_ONEHOT_I((((2U == (3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                                 >> 4U))) 
                                   << 2U) | (((1U == 
                                               (3U 
                                                & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                                   >> 4U))) 
                                              << 1U) 
                                             | (0U 
                                                == 
                                                (3U 
                                                 & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                                    >> 4U))))))))) {
            if ((0U != (((2U == (3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                       >> 4U))) << 2U) 
                        | (((1U == (3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                          >> 4U))) 
                            << 1U) | (0U == (3U & (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                                   >> 4U))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: tlul_err.sv:62: Assertion failed in %Ncordic_tb.u_cordic.u_cordic_reg.u_reg_if.u_err: unique case, but multiple matches found for '32'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 32,(3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                           >> 4U)));
                    VL_STOP_MT("/home/eneadim/github/flexsoc/hw/ips/tlul/tlul_err.sv", 62, "");
                }
            }
        }
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk = 0U;
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__unused_be 
        = (1U & VL_REDXOR_4(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_be));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit 
        = ((0x01f8U & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit)) 
           | (((8U == (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_addr)) 
               << 2U) | (((4U == (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_addr)) 
                          << 1U) | (0U == (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_addr)))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit 
        = ((0x01c7U & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit)) 
           | (((0x14U == (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_addr)) 
               << 5U) | (((0x10U == (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_addr)) 
                          << 4U) | ((0x0cU == (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_addr)) 
                                    << 3U))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit 
        = ((0x003fU & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit)) 
           | (((0x20U == (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_addr)) 
               << 8U) | (((0x1cU == (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_addr)) 
                          << 7U) | ((0x18U == (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_addr)) 
                                    << 6U))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__unused_tl 
        = (1U & VL_REDXOR_32(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                               ^ vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U]) 
                              ^ vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U])));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_start_wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_mode_wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_soft_rst_wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd_wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_n_iter_wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd2_wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__a_config_allowed 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk) 
           & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk) 
              & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_get) 
                 | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk) 
                    | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_partial)))));
    if ((1U & (~ VL_ONEHOT_I((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))))) {
        if ((0U != (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: cordic_reg_top.sv:617: Assertion failed in %Ncordic_tb.u_cordic.u_cordic_reg: unique case, but multiple matches found for '1'h1'\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name());
                VL_STOP_MT("/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl/cordic_reg_top.sv", 617, "");
            }
        }
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next = 0U;
    if ((IData)((0U != (0x00ffU & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))))) {
        if ((1U & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next 
                = ((0xffffff00U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next) 
                   | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd_qs) 
                       << 3U) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_soft_rst_qs) 
                                  << 2U) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_mode_qs) 
                                             << 1U) 
                                            | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_start_qs)))));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next 
                = ((0x000000ffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next) 
                   | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd2_qs) 
                       << 0x00000010U) | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_n_iter_qs) 
                                          << 8U)));
        } else {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next 
                = ((2U & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))
                    ? ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_rsvd_qs 
                        << 3U) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_error_qs) 
                                   << 2U) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_valid_qs) 
                                              << 1U) 
                                             | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_busy_qs))))
                    : ((4U & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))
                        ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_qs
                        : ((8U & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))
                            ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_qs
                            : ((0x00000010U & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))
                                ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_qs
                                : ((0x00000020U & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))
                                    ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_out_qs
                                    : ((0x00000040U 
                                        & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))
                                        ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_out_qs
                                        : vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_out_qs))))));
        }
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next 
            = ((0x00000100U & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))
                ? ((((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_rsvd_qs) 
                     << 0x00000018U) | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_max_iter_qs) 
                                        << 0x00000010U)) 
                   | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_frac_width_qs) 
                       << 8U) | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_data_width_qs)))
                : 0xffffffffU);
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wd;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__err_o 
        = (1U & ((~ ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__a_config_allowed) 
                     & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__opcode_allowed))) 
                 | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err) 
                    | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__d_ack 
        = (IData)(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[2U] 
                    >> 1U) & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U]));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__a_ack 
        = (IData)(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                    >> 0x0000000cU) & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[0U]));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_err 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__err_o;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rd_req 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__a_ack) 
           & (0x0800U == (0x0e00U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U])));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__wr_req 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__a_ack) 
           & ((0U == (7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                                >> 9U)))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__addr_align_err 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__wr_req) 
           & (0U != (3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                           >> 0x0000001cU))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__unused_tl 
        = (1U & VL_REDXOR_32(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                               ^ vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]) 
                              ^ vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U])));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__err_internal 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__addr_align_err;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__re_o 
        = ((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rd_req));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__we_o 
        = ((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__wr_req));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__re_o;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__we_o;
    vlSelfRef.cordic_tb__DOT__tl_o[0U] = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[0U];
    vlSelfRef.cordic_tb__DOT__tl_o[1U] = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[1U];
    vlSelfRef.cordic_tb__DOT__tl_o[2U] = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addrmiss 
        = ((~ (0U != (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))) 
           & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_re) 
              | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_we)));
    __Vtableidx1 = (((0U != (0x0000000fU & (~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_be)))) 
                     << 0x0000000aU) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
                                         << 1U) | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_we)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__wr_err 
        = Vtop__ConstPool__TABLE_he7e48997_0[__Vtableidx1];
    vlSelfRef.cordic_tb__DOT__tl_o_d_valid = (1U & 
                                              (vlSelfRef.cordic_tb__DOT__tl_o[2U] 
                                               >> 1U));
    vlSelfRef.cordic_tb__DOT__tl_o_d_opcode = (7U & 
                                               ((vlSelfRef.cordic_tb__DOT__tl_o[2U] 
                                                 << 2U) 
                                                | (vlSelfRef.cordic_tb__DOT__tl_o[1U] 
                                                   >> 0x0000001eU)));
    vlSelfRef.cordic_tb__DOT__tl_o_d_data = ((vlSelfRef.cordic_tb__DOT__tl_o[1U] 
                                              << 0x00000010U) 
                                             | (vlSelfRef.cordic_tb__DOT__tl_o[0U] 
                                                >> 0x00000010U));
    vlSelfRef.cordic_tb__DOT__tl_o_d_error = (1U & 
                                              (vlSelfRef.cordic_tb__DOT__tl_o[0U] 
                                               >> 1U));
    vlSelfRef.cordic_tb__DOT__tl_o_a_ready = (1U & 
                                              vlSelfRef.cordic_tb__DOT__tl_o[0U]);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_error 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addrmiss) 
            & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__devmode_i)) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__wr_err));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_error;
    cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_3 
        = ((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_error)) 
           & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_we));
    cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_2 
        = ((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_error)) 
           & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_re));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_we 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
            >> 2U) & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_3));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_we 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
            >> 3U) & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_3));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_we 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
            >> 4U) & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_3));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
           & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_3));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_out_re 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
            >> 5U) & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_2));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_out_re 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
            >> 6U) & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_2));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_out_re 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
            >> 7U) & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_2));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_re 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
            >> 1U) & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_2));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_re 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
            >> 8U) & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_2));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_out_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_out_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_out_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__we)
            ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wd
            : vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__d);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__we)
            ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wd
            : vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__d);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__we)
            ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wd
            : vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__d);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__we)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wd)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__d));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__we)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wd)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__d));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__we)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wd)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__d));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__we)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wd)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__d));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__we)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wd)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__d));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__we)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wd)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__d));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
        = ((0xf8000000U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U]) 
           | ((((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__q) 
                << 0x00000013U) | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qre) 
                                   << 0x00000012U)) 
              | ((((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__q) 
                   << 0x0000000aU) | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qre) 
                                      << 9U)) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__q) 
                                                  << 1U) 
                                                 | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qre)))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
        = ((0x07ffffffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U]) 
           | ((IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__q)) 
                        << 0x0000000aU) | (QData)((IData)(
                                                          (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qre) 
                                                            << 9U) 
                                                           | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__q) 
                                                               << 1U) 
                                                              | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qre))))))) 
              << 0x0000001bU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[1U] 
        = (((IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__q)) 
                      << 0x0000000aU) | (QData)((IData)(
                                                        (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qre) 
                                                          << 9U) 
                                                         | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__q) 
                                                             << 1U) 
                                                            | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qre))))))) 
            >> 5U) | ((IData)(((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__q)) 
                                 << 0x0000000aU) | (QData)((IData)(
                                                                   (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qre) 
                                                                     << 9U) 
                                                                    | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__q) 
                                                                        << 1U) 
                                                                       | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qre)))))) 
                               >> 0x00000020U)) << 0x0000001bU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[2U] 
        = ((0xffffffe0U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[2U]) 
           | ((IData)(((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__q)) 
                         << 0x0000000aU) | (QData)((IData)(
                                                           (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qre) 
                                                             << 9U) 
                                                            | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__q) 
                                                                << 1U) 
                                                               | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qre)))))) 
                       >> 0x00000020U)) >> 5U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[2U] 
        = ((0x0000001fU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[2U]) 
           | ((IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qre)) 
                        << 0x00000021U) | (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__q)) 
                                            << 1U) 
                                           | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qre))))) 
              << 5U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[3U] 
        = (((IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qre)) 
                      << 0x00000021U) | (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__q)) 
                                          << 1U) | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qre))))) 
            >> 0x0000001bU) | ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__q 
                                << 7U) | ((IData)((
                                                   (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qre)) 
                                                     << 0x00000021U) 
                                                    | (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__q)) 
                                                        << 1U) 
                                                       | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qre)))) 
                                                   >> 0x00000020U)) 
                                          << 5U)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[4U] 
        = ((0xffffff80U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[4U]) 
           | (((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__q 
                               >> 0x00000019U)) | ((IData)(
                                                           ((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qre)) 
                                                              << 0x00000021U) 
                                                             | (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__q)) 
                                                                 << 1U) 
                                                                | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qre)))) 
                                                            >> 0x00000020U)) 
                                                   >> 0x0000001bU)) 
              | (0x00000060U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__q 
                                >> 0x00000019U))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[4U] 
        = ((0x0000007fU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[4U]) 
           | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__q 
              << 7U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[5U] 
        = ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__q 
            >> 0x00000019U) | ((IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q)) 
                                         << 0x00000020U) 
                                        | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q)))) 
                               << 7U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[6U] 
        = (((IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q)) 
                      << 0x00000020U) | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q)))) 
            >> 0x00000019U) | ((IData)(((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q)) 
                                          << 0x00000020U) 
                                         | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q))) 
                                        >> 0x00000020U)) 
                               << 7U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
        = ((0xfffffe00U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U]) 
           | (((IData)(((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q)) 
                          << 0x00000020U) | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q))) 
                        >> 0x00000020U)) >> 0x00000019U) 
              | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__q) 
                  << 8U) | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qre) 
                            << 7U))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
        = ((0xffffc1ffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U]) 
           | (((((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qre) 
                 << 4U) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__q) 
                            << 3U) | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qre) 
                                      << 2U))) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__q) 
                                                   << 1U) 
                                                  | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qre))) 
              << 9U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
        = ((0x00003fffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U]) 
           | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__q 
              << 0x0000000eU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
        = ((0xfffff800U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U]) 
           | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__q 
              >> 0x00000012U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
        = ((0xf80007ffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U]) 
           | (0xfffff800U & (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__q) 
                              << 0x00000013U) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__q) 
                                                  << 0x0000000eU) 
                                                 | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__q) 
                                                     << 0x0000000dU) 
                                                    | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__q) 
                                                        << 0x0000000cU) 
                                                       | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__q) 
                                                          << 0x0000000bU)))))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
        = ((0x07ffffffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U]) 
           | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__q) 
              << 0x0000001bU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[9U] 
        = (0x000007ffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__q) 
                          >> 5U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[3U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[3U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[4U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[4U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[5U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[5U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[6U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[6U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[9U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[9U];
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__qe = 1U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_data;
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__qe = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__qs;
    }
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__qe = 1U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_data;
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__qe = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__qs;
    }
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__qe = 1U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_data;
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__qe = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__qs;
    }
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__qe = 1U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_data;
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__qe = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__qs;
    }
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__qe = 1U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_data;
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__qe = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__qs;
    }
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__qe = 1U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_data;
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__qe = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__qs;
    }
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__qe = 1U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_data;
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__qe = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__qs;
    }
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__qe = 1U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_data;
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__qe = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__qs;
    }
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__qe = 1U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_data;
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__qe = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__ds 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__qs;
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[3U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[3U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[4U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[4U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[5U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[5U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[6U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[6U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[9U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[9U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_soft_rst 
        = (1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                 >> 0x0000000dU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_rsvd 
        = (0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                          >> 0x0000000eU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_rsvd2 
        = (0x0000ffffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[9U] 
                           << 5U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                                     >> 0x0000001bU)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_n_iter 
        = (0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                          >> 0x00000013U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_mode 
        = (1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                 >> 0x0000000cU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_in_value 
        = ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
            << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[6U] 
                               >> 7U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_in_value 
        = ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[6U] 
            << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[5U] 
                               >> 7U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_in_value 
        = ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[5U] 
            << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[4U] 
                               >> 7U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_start 
        = (1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                 >> 0x0000000bU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_eff = 0x10U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_eff 
        = ((0U == (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_n_iter))
            ? 0x10U : ((0x10U < (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_n_iter))
                        ? 0x10U : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_n_iter)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_invalid = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_invalid 
        = ((0U != (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_n_iter)) 
           && (0x10U < (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_n_iter)));
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__csr_word 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_in_value;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__narrow_value 
        = (0x0000ffffU & __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__csr_word);
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__Vfuncout 
        = ((0x00070000U & ((- (IData)((1U & ((IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__narrow_value) 
                                             >> 0x0fU)))) 
                           << 0x00000010U)) | (IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__narrow_value));
    cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h6234dd4b__0 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__csr_word 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_in_value;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__narrow_value 
        = (0x0000ffffU & __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__csr_word);
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__Vfuncout 
        = ((0x00070000U & ((- (IData)((1U & ((IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__narrow_value) 
                                             >> 0x0fU)))) 
                           << 0x00000010U)) | (IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__narrow_value));
    cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h1b1e1e5a__0 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__csr_word 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_in_value;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__narrow_value 
        = (0x0000ffffU & __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__csr_word);
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__Vfuncout 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__narrow_value;
    cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h30a90f11__0 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__Vfuncout;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_start;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int 
        = cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h6234dd4b__0;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int 
        = cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h1b1e1e5a__0;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__z_in_int 
        = cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h30a90f11__0;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_init 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_init 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__z_in_int;
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_mode) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init = 0U;
        if (((0U == VL_EXTENDS_II(32,19, vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int)) 
             & (0U == VL_EXTENDS_II(32,19, vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int)))) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_init = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_init = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init = 0U;
        } else if (VL_GTS_III(32, 0U, VL_EXTENDS_II(32,19, vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int))) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_init 
                = (0x0007ffffU & (- vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_init 
                = (0x0007ffffU & (- vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init 
                = (VL_LTES_III(32, 0U, VL_EXTENDS_II(32,19, vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int))
                    ? 0x6488U : 0x9b78U);
        }
    } else if (VL_LTS_III(16, 0x3244U, (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__z_in_int))) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_init 
            = (0x0007ffffU & (- vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int));
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_init 
            = (0x0007ffffU & (- vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int));
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init 
            = (0x0000ffffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__z_in_int) 
                              - (IData)(0x6488U)));
    } else if (VL_GTS_III(16, 0xcdbcU, (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__z_in_int))) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_init 
            = (0x0007ffffU & (- vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int));
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_init 
            = (0x0007ffffU & (- vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int));
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init 
            = (0x0000ffffU & ((IData)(0x6488U) + (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__z_in_int)));
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__d_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_i;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__f_edge_o 
        = ((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_i)) 
           & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_q));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__r_edge_o 
        = ((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_q)) 
           & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_i));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__start_fall_unused 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__f_edge_o;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__start_rise 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__r_edge_o;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error_d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error;
    if (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__start_rise) 
         & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q))) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error_d = 1U;
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q;
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_d = 1U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid_d 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_d 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_d 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_d 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q;
        if ((1U & (~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q)))) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error_d = 1U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_d = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_d = 0x10U;
        }
        if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_d 
                = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q) 
                    == (0x000000ffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_q) 
                                       - (IData)(1U))))
                    ? 0U : (0x0000001fU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q))));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step;
        } else {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_d = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_d = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_d = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_d = 0U;
        }
        if (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q) 
             == (0x000000ffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_q) 
                                - (IData)(1U))))) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_d = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid_d = 1U;
        }
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_d = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid_d 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_d 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_d 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_d 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q;
        if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__start_rise) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_invalid;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_mode;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_eff;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_d = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_d = 1U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid_d = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_init;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_init;
        }
    }
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                       << 0x00000018U) 
                                                      | (((((((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__rst_ni)) 
                                                              & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__rst_ni__0)) 
                                                             << 3U) 
                                                            | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__clk_i) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__clk_i__0))) 
                                                               << 2U)) 
                                                           | ((((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__rst_ni)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__rst_ni__0)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__clk_i) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__clk_i__0))))) 
                                                          << 0x00000014U) 
                                                         | ((((((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__rst_ni)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__rst_ni__0)) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__clk_i__0))) 
                                                                 << 2U)) 
                                                             | ((((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__rst_ni)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__rst_ni__0)) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__clk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__clk_i__0))))) 
                                                            << 0x00000010U))) 
                                                     | ((((((((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__rst_ni)) 
                                                              & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__rst_ni__0)) 
                                                             << 3U) 
                                                            | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__clk_i) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__clk_i__0))) 
                                                               << 2U)) 
                                                           | ((((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__rst_ni)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__rst_ni__0)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__clk_i) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__clk_i__0))))) 
                                                          << 0x0000000cU) 
                                                         | ((((((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__rst_ni)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__rst_ni__0)) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__clk_i__0))) 
                                                                 << 2U)) 
                                                             | ((((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__rst_ni)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__rst_ni__0)) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__clk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__clk_i__0))))) 
                                                            << 8U)) 
                                                        | (((((((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__rst_ni)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__rst_ni__0)) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__clk_i__0))) 
                                                                 << 2U)) 
                                                             | ((((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__rst_ni)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__rst_ni__0)) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__clk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__clk_i__0))))) 
                                                            << 4U) 
                                                           | (((((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__rst_ni)) 
                                                                 & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__rst_ni__0)) 
                                                                << 3U) 
                                                               | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__clk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__clk_i__0))) 
                                                                  << 2U)) 
                                                              | ((((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rst_ni)) 
                                                                   & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rst_ni__0)) 
                                                                  << 1U) 
                                                                 | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__clk_i) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__clk_i__0))))))))));
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
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
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

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__q_o 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__rst_ni) 
           && (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__d_i));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__q_o;
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__Vfuncout = 0;
    IData/*18:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__value_i;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__value_i = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__Vfuncout = 0;
    IData/*18:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__value_i;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__value_i = 0;
    IData/*31:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__value_i;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__value_i = 0;
    IData/*31:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__value_i;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__value_i = 0;
    IData/*31:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__value_i;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__value_i = 0;
    // Body
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__rst_ni) {
        if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_soft_rst) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_out_value = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_out_value = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_out_value = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_q = 0x10U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q = 0U;
        } else {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_d;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_d;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_d;
            if (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q) 
                 & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q) 
                    == (0x000000ffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_q) 
                                       - (IData)(1U)))))) {
                vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_out_value 
                    = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_out_next_32;
                vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_out_value 
                    = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_out_next_32;
                vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_out_value 
                    = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_out_next_32;
            }
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_q 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_d;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_d;
        }
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_out_value = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_out_value = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_out_value = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_q = 0x10U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q = 0U;
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_q 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__rst_ni) 
           && ((1U & (~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_soft_rst))) 
               && (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_d)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__rst_ni) 
           && ((1U & (~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_soft_rst))) 
               && (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error_d)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__rst_ni) 
           && ((1U & (~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_soft_rst))) 
               && (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid_d)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__rst_ni) 
           && ((1U & (~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_soft_rst))) 
               && (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_d)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_shift 
        = (0x0007ffffU & VL_SHIFTRS_III(19,19,5, vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q, (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_shift 
        = (0x0007ffffU & VL_SHIFTRS_III(19,19,5, vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q, (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q;
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_q) {
        if (VL_LTES_III(32, 0U, VL_EXTENDS_II(32,19, vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q))) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step 
                = (0x0000ffffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q) 
                                  + vlSymsp->TOP__cordic_lut_pkg.AtanLut
                                  [(0x0000000fU & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q))]));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step 
                = (0x0007ffffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q 
                                  - vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_shift));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step 
                = (0x0007ffffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q 
                                  + vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_shift));
        } else {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step 
                = (0x0000ffffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q) 
                                  - vlSymsp->TOP__cordic_lut_pkg.AtanLut
                                  [(0x0000000fU & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q))]));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step 
                = (0x0007ffffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q 
                                  + vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_shift));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step 
                = (0x0007ffffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q 
                                  - vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_shift));
        }
    } else if (VL_LTES_III(32, 0U, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q)))) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step 
            = (0x0000ffffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q) 
                              - vlSymsp->TOP__cordic_lut_pkg.AtanLut
                              [(0x0000000fU & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q))]));
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step 
            = (0x0007ffffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q 
                              + vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_shift));
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step 
            = (0x0007ffffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q 
                              - vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_shift));
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step 
            = (0x0000ffffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q) 
                              + vlSymsp->TOP__cordic_lut_pkg.AtanLut
                              [(0x0000000fU & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q))]));
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step 
            = (0x0007ffffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q 
                              - vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_shift));
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step 
            = (0x0007ffffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q 
                              + vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_shift));
    }
    if ((1U & (~ VL_ONEHOT_I((((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q) 
                               << 1U) | (1U & (~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q)))))))) {
        if ((0U != (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q) 
                     << 1U) | (1U & (~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q)))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: cordic_core.sv:360: Assertion failed in %Ncordic_tb.u_cordic.u_cordic_core: unique case, but multiple matches found for '1'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),1,(IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q));
                VL_STOP_MT("/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/rtl/cordic_core.sv", 360, "");
            }
        }
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_busy 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__value_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__Vfuncout 
        = (((- (IData)((1U & ((IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__value_i) 
                              >> 0x0fU)))) << 0x00000010U) 
           | (IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__value_i));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_out_next_32 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__angle_visible_to_csr32__17__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__value_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__Vfuncout 
        = (VL_LTS_III(19, 0x00007fffU, __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__value_i)
            ? 0x00007fffU : (VL_GTS_III(19, 0x00078000U, __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__value_i)
                              ? 0x00008000U : (0x0000ffffU 
                                               & __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__value_i)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk2__DOT__y_final_visible 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__14__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__value_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk2__DOT__y_final_visible;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__Vfuncout 
        = (((- (IData)((1U & ((IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__value_i) 
                              >> 0x0fU)))) << 0x00000010U) 
           | (IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__value_i));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_out_next_32 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__16__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__value_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__Vfuncout 
        = (VL_LTS_III(19, 0x00007fffU, __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__value_i)
            ? 0x00007fffU : (VL_GTS_III(19, 0x00078000U, __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__value_i)
                              ? 0x00008000U : (0x0000ffffU 
                                               & __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__value_i)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk2__DOT__x_final_visible 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__sat_data_to_visible__13__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__value_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk2__DOT__x_final_visible;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__Vfuncout 
        = (((- (IData)((1U & ((IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__value_i) 
                              >> 0x0fU)))) << 0x00000010U) 
           | (IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__value_i));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_out_next_32 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__data_visible_to_csr32__15__Vfuncout;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[0U] 
        = (IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_out_value)) 
                    << 0x00000020U) | (QData)((IData)(
                                                      ((((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_data_width) 
                                                         << 0x00000018U) 
                                                        | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_frac_width) 
                                                           << 0x00000010U)) 
                                                       | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_max_iter) 
                                                           << 8U) 
                                                          | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_rsvd)))))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[1U] 
        = (IData)(((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_out_value)) 
                     << 0x00000020U) | (QData)((IData)(
                                                       ((((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_data_width) 
                                                          << 0x00000018U) 
                                                         | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_frac_width) 
                                                            << 0x00000010U)) 
                                                        | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_max_iter) 
                                                            << 8U) 
                                                           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_rsvd)))))) 
                   >> 0x00000020U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[2U] 
        = (IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_out_value)) 
                    << 0x00000020U) | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_out_value))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[3U] 
        = (IData)(((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_out_value)) 
                     << 0x00000020U) | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_out_value))) 
                   >> 0x00000020U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[4U] 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_busy) 
            << 0x0000001fU) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid) 
                                << 0x0000001eU) | (
                                                   ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error) 
                                                    << 0x0000001dU) 
                                                   | vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_rsvd)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[3U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[3U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[4U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[4U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[3U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[3U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[4U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__d 
        = (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U] 
           >> 0x0000001fU);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__d 
        = (1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U] 
                 >> 0x0000001eU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__d 
        = (1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U] 
                 >> 0x0000001dU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__d 
        = (0x1fffffffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U]);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[3U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__d 
        = (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U] 
           >> 0x00000018U);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__d 
        = (0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U] 
                          >> 0x00000010U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__d 
        = (0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U] 
                          >> 8U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__d 
        = (0x000000ffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U]);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__ds 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__d;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_busy_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_valid_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_error_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_rsvd_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_out_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_out_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_out_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_data_width_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_frac_width_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_max_iter_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qs;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_rsvd_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qs;
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__rst_ni) {
        if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__q 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_data;
        }
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__q = 0U;
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_start_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__qs;
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__rst_ni) {
        if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__q 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_data;
        }
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__q = 0U;
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_mode_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__qs;
}

void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__rst_ni) {
        if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__q 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_data;
        }
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__q = 0U;
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_soft_rst_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__qs;
}

void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__rst_ni) {
        if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__q 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_data;
        }
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__q = 0U;
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__qs;
}

void Vtop___024root___nba_sequent__TOP__6(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__6\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__rst_ni) {
        if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__q 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_data;
        }
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__q = 0U;
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_n_iter_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__qs;
}

void Vtop___024root___nba_sequent__TOP__7(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__7\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__rst_ni) {
        if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__q 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_data;
        }
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__q = 0U;
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd2_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__qs;
}

void Vtop___024root___nba_sequent__TOP__8(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__8\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__rst_ni) {
        if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_data;
        }
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q = 0U;
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__qs;
}

void Vtop___024root___nba_sequent__TOP__9(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__9\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__rst_ni) {
        if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_data;
        }
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q = 0U;
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__qs;
}

void Vtop___024root___nba_sequent__TOP__10(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__10\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__rst_ni) {
        if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__q 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_data;
        }
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__q = 0U;
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_qs 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__qs;
}

void Vtop___024root___nba_sequent__TOP__11(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__11\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_2;
    cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_2 = 0;
    CData/*0:0*/ cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_3;
    cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_3 = 0;
    SData/*10:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rst_ni) {
        if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__a_ack) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__outstanding_q = 1U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rspop_q 
                = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rd_req)
                    ? 1U : 0U);
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error_q 
                = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error_i) 
                   | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__err_internal));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata_q 
                = ((((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error_i) 
                     | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__err_internal)) 
                    | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__wr_req))
                    ? 0xffffffffU : vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata_i);
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqid_q 
                = (0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                   << 4U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[2U] 
                                             >> 0x0000001cU)));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqsz_q 
                = (3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                         >> 4U));
        } else if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__d_ack) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__outstanding_q = 0U;
        }
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__outstanding_q = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rspop_q = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error_q = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata_q = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqid_q = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqsz_q = 0U;
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error_q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata_q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
        = (IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                    << 0x00000039U) | (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                        << 0x00000031U) 
                                       | (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata)) 
                                           << 0x00000010U) 
                                          | (QData)((IData)(
                                                            (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error) 
                                                              << 1U) 
                                                             | (1U 
                                                                & (~ 
                                                                   ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__outstanding_q) 
                                                                    | ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                                                        >> 0x0000000cU) 
                                                                       & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__busy_i))))))))))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
        = ((0xc0000000U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U]) 
           | (IData)(((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                        << 0x00000039U) | (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                            << 0x00000031U) 
                                           | (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata)) 
                                               << 0x00000010U) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error) 
                                                                  << 1U) 
                                                                 | (1U 
                                                                    & (~ 
                                                                       ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__outstanding_q) 
                                                                        | ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                                                            >> 0x0000000cU) 
                                                                           & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__busy_i))))))))))) 
                      >> 0x00000020U)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
        = ((0x3fffffffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U]) 
           | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rspop_q) 
              << 0x0000001eU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
        = (3U & ((0x3ffffffeU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__outstanding_q) 
                                 << 1U)) | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rspop_q) 
                                            >> 2U)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__unused_tl 
        = (1U & VL_REDXOR_32(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                               ^ vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U]) 
                              ^ vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U])));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__d_ack 
        = (IData)(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[2U] 
                    >> 1U) & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U]));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__a_ack 
        = (IData)(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                    >> 0x0000000cU) & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[0U]));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rd_req 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__a_ack) 
           & (0x0800U == (0x0e00U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U])));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__wr_req 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__a_ack) 
           & ((0U == (7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                                >> 9U)))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__addr_align_err 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__wr_req) 
           & (0U != (3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                           >> 0x0000001cU))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__unused_tl 
        = (1U & VL_REDXOR_32(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                               ^ vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]) 
                              ^ vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U])));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__err_internal 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__addr_align_err;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__re_o 
        = ((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rd_req));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__we_o 
        = ((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__wr_req));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__re_o;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__we_o;
    vlSelfRef.cordic_tb__DOT__tl_o[0U] = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[0U];
    vlSelfRef.cordic_tb__DOT__tl_o[1U] = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[1U];
    vlSelfRef.cordic_tb__DOT__tl_o[2U] = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addrmiss 
        = ((~ (0U != (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))) 
           & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_re) 
              | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_we)));
    __Vtableidx1 = (((0U != (0x0000000fU & (~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_be)))) 
                     << 0x0000000aU) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
                                         << 1U) | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_we)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__wr_err 
        = Vtop__ConstPool__TABLE_he7e48997_0[__Vtableidx1];
    vlSelfRef.cordic_tb__DOT__tl_o_d_valid = (1U & 
                                              (vlSelfRef.cordic_tb__DOT__tl_o[2U] 
                                               >> 1U));
    vlSelfRef.cordic_tb__DOT__tl_o_d_opcode = (7U & 
                                               ((vlSelfRef.cordic_tb__DOT__tl_o[2U] 
                                                 << 2U) 
                                                | (vlSelfRef.cordic_tb__DOT__tl_o[1U] 
                                                   >> 0x0000001eU)));
    vlSelfRef.cordic_tb__DOT__tl_o_d_data = ((vlSelfRef.cordic_tb__DOT__tl_o[1U] 
                                              << 0x00000010U) 
                                             | (vlSelfRef.cordic_tb__DOT__tl_o[0U] 
                                                >> 0x00000010U));
    vlSelfRef.cordic_tb__DOT__tl_o_d_error = (1U & 
                                              (vlSelfRef.cordic_tb__DOT__tl_o[0U] 
                                               >> 1U));
    vlSelfRef.cordic_tb__DOT__tl_o_a_ready = (1U & 
                                              vlSelfRef.cordic_tb__DOT__tl_o[0U]);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_error 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addrmiss) 
            & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__devmode_i)) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__wr_err));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_error;
    cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_3 
        = ((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_error)) 
           & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_we));
    cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_2 
        = ((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_error)) 
           & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_re));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_we 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
            >> 2U) & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_3));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_we 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
            >> 3U) & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_3));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_we 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
            >> 4U) & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_3));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
           & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_3));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_out_re 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
            >> 5U) & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_2));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_out_re 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
            >> 6U) & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_2));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_out_re 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
            >> 7U) & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_2));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_re 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
            >> 1U) & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_2));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_re 
        = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit) 
            >> 8U) & (IData)(cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT____VdfgRegularize_h0d2953c5_0_2));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_out_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_out_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_out_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__re 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__we;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qre 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__re;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__we)
            ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wd
            : vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__d);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__we)
            ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wd
            : vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__d);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__we)
            ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wd
            : vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__d);
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__we)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wd)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__d));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__we)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wd)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__d));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__we)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wd)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__d));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__we)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wd)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__d));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__we)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wd)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__d));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wr_data 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__we)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wd)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__d));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wr_en 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__de) 
           | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__we));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_data 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wr_data;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__qe 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en;
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next = 0U;
    if ((IData)((0U != (0x00ffU & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))))) {
        if ((1U & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next 
                = ((0xffffff00U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next) 
                   | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd_qs) 
                       << 3U) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_soft_rst_qs) 
                                  << 2U) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_mode_qs) 
                                             << 1U) 
                                            | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_start_qs)))));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next 
                = ((0x000000ffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next) 
                   | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd2_qs) 
                       << 0x00000010U) | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_n_iter_qs) 
                                          << 8U)));
        } else {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next 
                = ((2U & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))
                    ? ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_rsvd_qs 
                        << 3U) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_error_qs) 
                                   << 2U) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_valid_qs) 
                                              << 1U) 
                                             | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_busy_qs))))
                    : ((4U & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))
                        ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_qs
                        : ((8U & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))
                            ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_qs
                            : ((0x00000010U & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))
                                ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_qs
                                : ((0x00000020U & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))
                                    ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_out_qs
                                    : ((0x00000040U 
                                        & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))
                                        ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_out_qs
                                        : vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_out_qs))))));
        }
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next 
            = ((0x00000100U & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit))
                ? ((((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_rsvd_qs) 
                     << 0x00000018U) | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_max_iter_qs) 
                                        << 0x00000010U)) 
                   | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_frac_width_qs) 
                       << 8U) | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_data_width_qs)))
                : 0xffffffffU);
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata;
}

void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*18:0*/ cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h6234dd4b__0;
    cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h6234dd4b__0 = 0;
    IData/*18:0*/ cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h1b1e1e5a__0;
    cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h1b1e1e5a__0 = 0;
    SData/*15:0*/ cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h30a90f11__0;
    cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h30a90f11__0 = 0;
    IData/*18:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__csr_word;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__csr_word = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__narrow_value;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__narrow_value = 0;
    IData/*18:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__csr_word;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__csr_word = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__narrow_value;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__narrow_value = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__csr_word;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__csr_word = 0;
    SData/*15:0*/ __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__narrow_value;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__narrow_value = 0;
    // Body
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
        = ((0xf8000000U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U]) 
           | ((((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__q) 
                << 0x00000013U) | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qre) 
                                   << 0x00000012U)) 
              | ((((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__q) 
                   << 0x0000000aU) | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qre) 
                                      << 9U)) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__q) 
                                                  << 1U) 
                                                 | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qre)))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
        = ((0x07ffffffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U]) 
           | ((IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__q)) 
                        << 0x0000000aU) | (QData)((IData)(
                                                          (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qre) 
                                                            << 9U) 
                                                           | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__q) 
                                                               << 1U) 
                                                              | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qre))))))) 
              << 0x0000001bU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[1U] 
        = (((IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__q)) 
                      << 0x0000000aU) | (QData)((IData)(
                                                        (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qre) 
                                                          << 9U) 
                                                         | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__q) 
                                                             << 1U) 
                                                            | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qre))))))) 
            >> 5U) | ((IData)(((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__q)) 
                                 << 0x0000000aU) | (QData)((IData)(
                                                                   (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qre) 
                                                                     << 9U) 
                                                                    | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__q) 
                                                                        << 1U) 
                                                                       | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qre)))))) 
                               >> 0x00000020U)) << 0x0000001bU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[2U] 
        = ((0xffffffe0U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[2U]) 
           | ((IData)(((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__q)) 
                         << 0x0000000aU) | (QData)((IData)(
                                                           (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qre) 
                                                             << 9U) 
                                                            | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__q) 
                                                                << 1U) 
                                                               | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qre)))))) 
                       >> 0x00000020U)) >> 5U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[2U] 
        = ((0x0000001fU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[2U]) 
           | ((IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qre)) 
                        << 0x00000021U) | (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__q)) 
                                            << 1U) 
                                           | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qre))))) 
              << 5U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[3U] 
        = (((IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qre)) 
                      << 0x00000021U) | (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__q)) 
                                          << 1U) | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qre))))) 
            >> 0x0000001bU) | ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__q 
                                << 7U) | ((IData)((
                                                   (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qre)) 
                                                     << 0x00000021U) 
                                                    | (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__q)) 
                                                        << 1U) 
                                                       | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qre)))) 
                                                   >> 0x00000020U)) 
                                          << 5U)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[4U] 
        = ((0xffffff80U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[4U]) 
           | (((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__q 
                               >> 0x00000019U)) | ((IData)(
                                                           ((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qre)) 
                                                              << 0x00000021U) 
                                                             | (((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__q)) 
                                                                 << 1U) 
                                                                | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qre)))) 
                                                            >> 0x00000020U)) 
                                                   >> 0x0000001bU)) 
              | (0x00000060U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__q 
                                >> 0x00000019U))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[4U] 
        = ((0x0000007fU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[4U]) 
           | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__q 
              << 7U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[5U] 
        = ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__q 
            >> 0x00000019U) | ((IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q)) 
                                         << 0x00000020U) 
                                        | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q)))) 
                               << 7U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[6U] 
        = (((IData)((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q)) 
                      << 0x00000020U) | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q)))) 
            >> 0x00000019U) | ((IData)(((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q)) 
                                          << 0x00000020U) 
                                         | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q))) 
                                        >> 0x00000020U)) 
                               << 7U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
        = ((0xfffffe00U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U]) 
           | (((IData)(((((QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q)) 
                          << 0x00000020U) | (QData)((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q))) 
                        >> 0x00000020U)) >> 0x00000019U) 
              | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__q) 
                  << 8U) | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qre) 
                            << 7U))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
        = ((0xffffc1ffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U]) 
           | (((((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qre) 
                 << 4U) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__q) 
                            << 3U) | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qre) 
                                      << 2U))) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__q) 
                                                   << 1U) 
                                                  | (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qre))) 
              << 9U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
        = ((0x00003fffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U]) 
           | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__q 
              << 0x0000000eU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
        = ((0xfffff800U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U]) 
           | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__q 
              >> 0x00000012U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
        = ((0xf80007ffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U]) 
           | (0xfffff800U & (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__q) 
                              << 0x00000013U) | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__q) 
                                                  << 0x0000000eU) 
                                                 | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__q) 
                                                     << 0x0000000dU) 
                                                    | (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__q) 
                                                        << 0x0000000cU) 
                                                       | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__q) 
                                                          << 0x0000000bU)))))));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
        = ((0x07ffffffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U]) 
           | ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__q) 
              << 0x0000001bU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[9U] 
        = (0x000007ffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__q) 
                          >> 5U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[3U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[3U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[4U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[4U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[5U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[5U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[6U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[6U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[9U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[9U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[1U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[1U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[2U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[2U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[3U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[3U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[4U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[4U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[5U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[5U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[6U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[6U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[9U] 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[9U];
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_soft_rst 
        = (1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                 >> 0x0000000dU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_rsvd 
        = (0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                          >> 0x0000000eU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_rsvd2 
        = (0x0000ffffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[9U] 
                           << 5U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                                     >> 0x0000001bU)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_n_iter 
        = (0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                          >> 0x00000013U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_mode 
        = (1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                 >> 0x0000000cU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_in_value 
        = ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
            << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[6U] 
                               >> 7U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_in_value 
        = ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[6U] 
            << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[5U] 
                               >> 7U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_in_value 
        = ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[5U] 
            << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[4U] 
                               >> 7U));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_start 
        = (1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                 >> 0x0000000bU));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_eff = 0x10U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_eff 
        = ((0U == (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_n_iter))
            ? 0x10U : ((0x10U < (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_n_iter))
                        ? 0x10U : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_n_iter)));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_invalid = 0U;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_invalid 
        = ((0U != (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_n_iter)) 
           && (0x10U < (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_n_iter)));
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__csr_word 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_in_value;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__narrow_value 
        = (0x0000ffffU & __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__csr_word);
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__Vfuncout 
        = ((0x00070000U & ((- (IData)((1U & ((IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__narrow_value) 
                                             >> 0x0fU)))) 
                           << 0x00000010U)) | (IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__narrow_value));
    cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h6234dd4b__0 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__18__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__csr_word 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_in_value;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__narrow_value 
        = (0x0000ffffU & __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__csr_word);
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__Vfuncout 
        = ((0x00070000U & ((- (IData)((1U & ((IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__narrow_value) 
                                             >> 0x0fU)))) 
                           << 0x00000010U)) | (IData)(__Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__narrow_value));
    cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h1b1e1e5a__0 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_data_int__19__Vfuncout;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__csr_word 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_in_value;
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__narrow_value 
        = (0x0000ffffU & __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__csr_word);
    __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__Vfuncout 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__narrow_value;
    cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h30a90f11__0 
        = __Vfunc_cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__csr_to_angle_int__20__Vfuncout;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_start;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int 
        = cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h6234dd4b__0;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int 
        = cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h1b1e1e5a__0;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__z_in_int 
        = cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT____VdfgExtracted_h30a90f11__0;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_init 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_init 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__z_in_int;
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_mode) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init = 0U;
        if (((0U == VL_EXTENDS_II(32,19, vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int)) 
             & (0U == VL_EXTENDS_II(32,19, vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int)))) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_init = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_init = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init = 0U;
        } else if (VL_GTS_III(32, 0U, VL_EXTENDS_II(32,19, vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int))) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_init 
                = (0x0007ffffU & (- vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_init 
                = (0x0007ffffU & (- vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init 
                = (VL_LTES_III(32, 0U, VL_EXTENDS_II(32,19, vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int))
                    ? 0x6488U : 0x9b78U);
        }
    } else if (VL_LTS_III(16, 0x3244U, (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__z_in_int))) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_init 
            = (0x0007ffffU & (- vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int));
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_init 
            = (0x0007ffffU & (- vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int));
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init 
            = (0x0000ffffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__z_in_int) 
                              - (IData)(0x6488U)));
    } else if (VL_GTS_III(16, 0xcdbcU, (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__z_in_int))) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_init 
            = (0x0007ffffU & (- vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int));
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_init 
            = (0x0007ffffU & (- vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int));
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init 
            = (0x0000ffffU & ((IData)(0x6488U) + (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__z_in_int)));
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__d_i 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_i;
}

void Vtop___024root___nba_comb__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__ds 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en)
            ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_data
            : vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__qs);
}

void Vtop___024root___nba_comb__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__ds 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en)
            ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_data
            : vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__qs);
}

void Vtop___024root___nba_comb__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__ds 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en)
            ? vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_data
            : vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__qs);
}

void Vtop___024root___nba_comb__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__ds 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_data)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__qs));
}

void Vtop___024root___nba_comb__TOP__6(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__6\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__ds 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_data)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__qs));
}

void Vtop___024root___nba_comb__TOP__7(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__7\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__ds 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_data)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__qs));
}

void Vtop___024root___nba_comb__TOP__8(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__8\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__ds 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_data)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__qs));
}

void Vtop___024root___nba_comb__TOP__9(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__9\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__ds 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_data)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__qs));
}

void Vtop___024root___nba_comb__TOP__10(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__10\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__ds 
        = ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en)
            ? (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_data)
            : (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__qs));
}

void Vtop___024root___nba_comb__TOP__11(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__11\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__f_edge_o 
        = ((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_i)) 
           & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_q));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__r_edge_o 
        = ((~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_q)) 
           & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_i));
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__start_fall_unused 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__f_edge_o;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__start_rise 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__r_edge_o;
}

void Vtop___024root___nba_comb__TOP__12(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__12\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error_d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error;
    if (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__start_rise) 
         & (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q))) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error_d = 1U;
    }
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_q;
    vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_d 
        = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q;
    if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q) {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_d = 1U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid_d 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_d 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_d 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_d 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q;
        if ((1U & (~ (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q)))) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error_d = 1U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_d = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_d = 0x10U;
        }
        if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_d 
                = (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q) 
                    == (0x000000ffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_q) 
                                       - (IData)(1U))))
                    ? 0U : (0x0000001fU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q))));
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step;
        } else {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_d = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_d = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_d = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_d = 0U;
        }
        if (((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q) 
             == (0x000000ffU & ((IData)(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_q) 
                                - (IData)(1U))))) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_d = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid_d = 1U;
        }
    } else {
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_d = 0U;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid_d 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_d 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_d 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q;
        vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_d 
            = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q;
        if (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__start_rise) {
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_invalid;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_mode;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_eff;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_d = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_d = 1U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid_d = 0U;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_init;
            vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_d 
                = vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_init;
        }
    }
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x0000000000c00000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x0000000000300000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0x0000000000000030ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x00000000000000c0ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((0x0000000000000300ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((0x0000000000000c00ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__6(vlSelf);
    }
    if ((0x0000000000003000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__7(vlSelf);
    }
    if ((0x000000000000c000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__8(vlSelf);
    }
    if ((0x0000000000030000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__9(vlSelf);
    }
    if ((0x00000000000c0000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__10(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__11(vlSelf);
    }
    if ((0x00000000003ffffcULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x00000000000fffffULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((0x000000000000c003ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__2(vlSelf);
    }
    if ((0x0000000000030003ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__3(vlSelf);
    }
    if ((0x00000000000c0003ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__4(vlSelf);
    }
    if ((0x000000000000000fULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__5(vlSelf);
    }
    if ((0x0000000000000033ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__6(vlSelf);
    }
    if ((0x00000000000000c3ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__7(vlSelf);
    }
    if ((0x0000000000000303ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__8(vlSelf);
    }
    if ((0x0000000000000c03ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__9(vlSelf);
    }
    if ((0x0000000000003003ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__10(vlSelf);
    }
    if ((0x0000000000cfffffULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__11(vlSelf);
    }
    if ((0x0000000000ffffffULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__12(vlSelf);
    }
}

void Vtop___024root___timing_resume(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___timing_resume\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x0000000001000000ULL & vlSelfRef.__VactTriggered
         [0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtop___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    Vtop___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        Vtop___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
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
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/tb/cocotb/cordic_tb.sv", 5, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/tb/cocotb/cordic_tb.sv", 5, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/tb/cocotb/cordic_tb.sv", 5, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtop___024root___eval_phase__act(vlSelf));
    } while (Vtop___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
