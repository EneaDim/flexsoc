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
    // Locals
    IData/*31:0*/ gpio_tb__DOT____VlemExpr_0;
    // Body
    gpio_tb__DOT____VlemExpr_0 = VL_VALUEPLUSARGS_INN(64, "WAVE=%s"s, 
                                                      vlSelfRef.gpio_tb__DOT__wave_path);
    if (gpio_tb__DOT____VlemExpr_0) {
        ++(vlSelf->__Vcoverage[641]);
    } else {
        vlSelfRef.gpio_tb__DOT____VlemExpr_1 = VL_VALUEPLUSARGS_INN(64, "VCD=%s"s, 
                                                                    vlSelfRef.gpio_tb__DOT__wave_path);
        if (vlSelfRef.gpio_tb__DOT____VlemExpr_1) {
            ++(vlSelf->__Vcoverage[639]);
        } else {
            vlSelfRef.gpio_tb__DOT__wave_path = ""s;
            ++(vlSelf->__Vcoverage[638]);
        }
        ++(vlSelf->__Vcoverage[640]);
    }
    if (VL_UNLIKELY(((""s != vlSelfRef.gpio_tb__DOT__wave_path)))) {
        VL_WRITEF_NX("[TB] dumpfile = %s owner=wrapper\n",1
                     , 'S',&(vlSelfRef.gpio_tb__DOT__wave_path));
        vlSymsp->_vm_contextp__->dumpfile(vlSelfRef.gpio_tb__DOT__wave_path);
        vlSymsp->_traceDumpOpen();
        ++(vlSelf->__Vcoverage[642]);
    } else {
        ++(vlSelf->__Vcoverage[643]);
    }
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "/tmp/flexsoc-ip-v1-release-20260914/gpio-tlul/runs/gpio/release/dv/functional/tb/cocotb/gpio_tb.sv", 
                                         127);
    ++(vlSelf->__Vcoverage[644]);
    co_return;
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in) {
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
    } while ((2U > n));
    return (0U);
}

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h51485532__0;
    gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h51485532__0 = 0;
    CData/*0:0*/ gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h9250fec5__0;
    gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h9250fec5__0 = 0;
    CData/*0:0*/ gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VExpr_h9250fec5__0;
    gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VExpr_h9250fec5__0 = 0;
    CData/*3:0*/ __Vfunc_mubi4_test_invalid__3__val;
    __Vfunc_mubi4_test_invalid__3__val = 0;
    CData/*3:0*/ __Vfunc_mubi4_test_true_strict__4__val;
    __Vfunc_mubi4_test_true_strict__4__val = 0;
    CData/*0:0*/ __Vfunc_tl_a_user_chk__6__Vfuncout;
    __Vfunc_tl_a_user_chk__6__Vfuncout = 0;
    IData/*22:0*/ __Vfunc_tl_a_user_chk__6__user;
    __Vfunc_tl_a_user_chk__6__user = 0;
    CData/*0:0*/ __Vfunc_tl_a_user_chk__6__malformed_err;
    __Vfunc_tl_a_user_chk__6__malformed_err = 0;
    CData/*0:0*/ __Vfunc_mubi4_test_invalid__7__Vfuncout;
    __Vfunc_mubi4_test_invalid__7__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_mubi4_test_invalid__7__val;
    __Vfunc_mubi4_test_invalid__7__val = 0;
    CData/*3:0*/ __Vfunc_mubi4_test_true_strict__8__val;
    __Vfunc_mubi4_test_true_strict__8__val = 0;
    CData/*0:0*/ __Vfunc_mubi4_test_invalid__9__Vfuncout;
    __Vfunc_mubi4_test_invalid__9__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_mubi4_test_invalid__9__val;
    __Vfunc_mubi4_test_invalid__9__val = 0;
    QData/*38:0*/ __VdfgRegularize_h6e95ff9d_0_1;
    __VdfgRegularize_h6e95ff9d_0_1 = 0;
    QData/*57:0*/ __VdfgRegularize_h6e95ff9d_0_2;
    __VdfgRegularize_h6e95ff9d_0_2 = 0;
    QData/*58:0*/ __VdfgRegularize_h6e95ff9d_0_3;
    __VdfgRegularize_h6e95ff9d_0_3 = 0;
    QData/*59:0*/ __VdfgRegularize_h6e95ff9d_0_4;
    __VdfgRegularize_h6e95ff9d_0_4 = 0;
    QData/*60:0*/ __VdfgRegularize_h6e95ff9d_0_5;
    __VdfgRegularize_h6e95ff9d_0_5 = 0;
    QData/*61:0*/ __VdfgRegularize_h6e95ff9d_0_6;
    __VdfgRegularize_h6e95ff9d_0_6 = 0;
    QData/*62:0*/ __VdfgRegularize_h6e95ff9d_0_7;
    __VdfgRegularize_h6e95ff9d_0_7 = 0;
    QData/*32:0*/ __VdfgRegularize_h6e95ff9d_0_8;
    __VdfgRegularize_h6e95ff9d_0_8 = 0;
    QData/*33:0*/ __VdfgRegularize_h6e95ff9d_0_9;
    __VdfgRegularize_h6e95ff9d_0_9 = 0;
    QData/*34:0*/ __VdfgRegularize_h6e95ff9d_0_10;
    __VdfgRegularize_h6e95ff9d_0_10 = 0;
    QData/*35:0*/ __VdfgRegularize_h6e95ff9d_0_11;
    __VdfgRegularize_h6e95ff9d_0_11 = 0;
    QData/*36:0*/ __VdfgRegularize_h6e95ff9d_0_12;
    __VdfgRegularize_h6e95ff9d_0_12 = 0;
    QData/*37:0*/ __VdfgRegularize_h6e95ff9d_0_13;
    __VdfgRegularize_h6e95ff9d_0_13 = 0;
    // Body
    if (((IData)(vlSelfRef.gpio_tb__DOT__clk_i) ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 0, vlSelfRef.gpio_tb__DOT__clk_i, vlSelfRef.gpio_tb__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT____Vtogcov__clk_i = vlSelfRef.gpio_tb__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__rst_ni) ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2, vlSelfRef.gpio_tb__DOT__rst_ni, vlSelfRef.gpio_tb__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT____Vtogcov__rst_ni = vlSelfRef.gpio_tb__DOT__rst_ni;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__cio_gpio_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__cio_gpio_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4, vlSelfRef.gpio_tb__DOT__cio_gpio_i, vlSelfRef.gpio_tb__DOT____Vtogcov__cio_gpio_i);
        vlSelfRef.gpio_tb__DOT____Vtogcov__cio_gpio_i 
            = vlSelfRef.gpio_tb__DOT__cio_gpio_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_valid) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 36, vlSelfRef.gpio_tb__DOT__tl_i_a_valid, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_valid);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_valid 
            = vlSelfRef.gpio_tb__DOT__tl_i_a_valid;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_opcode) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_opcode)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 38, vlSelfRef.gpio_tb__DOT__tl_i_a_opcode, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_opcode);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_opcode 
            = vlSelfRef.gpio_tb__DOT__tl_i_a_opcode;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_param) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_param)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 44, vlSelfRef.gpio_tb__DOT__tl_i_a_param, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_param);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_param 
            = vlSelfRef.gpio_tb__DOT__tl_i_a_param;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_size) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_size)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 50, vlSelfRef.gpio_tb__DOT__tl_i_a_size, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_size);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_size 
            = vlSelfRef.gpio_tb__DOT__tl_i_a_size;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_source) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_source)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 54, vlSelfRef.gpio_tb__DOT__tl_i_a_source, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_source);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_source 
            = vlSelfRef.gpio_tb__DOT__tl_i_a_source;
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__tl_i_a_address 
                ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_address))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 70, vlSelfRef.gpio_tb__DOT__tl_i_a_address, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_address);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_address 
            = vlSelfRef.gpio_tb__DOT__tl_i_a_address;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_mask) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_mask)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 134, vlSelfRef.gpio_tb__DOT__tl_i_a_mask, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_mask);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_mask 
            = vlSelfRef.gpio_tb__DOT__tl_i_a_mask;
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__tl_i_a_data 
                ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_data))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 142, vlSelfRef.gpio_tb__DOT__tl_i_a_data, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_data);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_a_data 
            = vlSelfRef.gpio_tb__DOT__tl_i_a_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__tl_i_d_ready) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_d_ready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 206, vlSelfRef.gpio_tb__DOT__tl_i_d_ready, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_d_ready);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i_d_ready 
            = vlSelfRef.gpio_tb__DOT__tl_i_d_ready;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1251, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_o_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1259, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_o_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_o_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_oe_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1267, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_oe_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_oe_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1346, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1362, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1364, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1417, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1430, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1447, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1463, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1465, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1516, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1529, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1546, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1562, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1564, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1615, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1628, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1645, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1661, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1663, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1714, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1727, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1740, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1751, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__err_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2909, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__err_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__err_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3170, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3273, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3376, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3479, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3582, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3705, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_tree)))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 3735, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_tree);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_tree 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3822, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__outstanding_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4512, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__outstanding_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__outstanding_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q;
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_q))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4582, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4646, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqid_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4660, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqid_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqid_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqsz_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4676, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqsz_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqsz_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rspop_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4680, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rspop_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rspop_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__d_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__d_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5465, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__d_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__d_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__d_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__d_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5475, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5486, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__d_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__d_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5499, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__d_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__d_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__d_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__d_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5509, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5520, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__rst_ni = vlSelfRef.gpio_tb__DOT__rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_i 
        = vlSelfRef.gpio_tb__DOT__cio_gpio_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__clk_i = vlSelfRef.gpio_tb__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
    __VdfgRegularize_h6e95ff9d_0_8 = (((QData)((IData)(
                                                       (1U 
                                                        & VL_REDXOR_32(
                                                                       (0x2606bd25U 
                                                                        & vlSelfRef.gpio_tb__DOT__tl_i_a_data))))) 
                                       << 0x00000020U) 
                                      | (QData)((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_data)));
    __VdfgRegularize_h6e95ff9d_0_1 = (((QData)((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_address)) 
                                       << 7U) | (QData)((IData)(
                                                                (((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_opcode) 
                                                                  << 4U) 
                                                                 | (IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_mask)))));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__state_rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1309, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__state_rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__state_rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3224, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3327, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3430, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3533, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3636, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1406, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1507, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1606, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1705, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3876, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__intq))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5467, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__intq);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__intq 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__intq))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5501, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__intq);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__intq 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1219, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_en_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1227, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_en_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_en_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__err_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3681, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__err_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__err_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5463, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 647, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5497, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__filter_rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1307, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__filter_rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__filter_rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 649, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 645, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__clk_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__clk_i;
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4518, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4648, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3186, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3289, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3392, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3495, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3598, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3838, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1402, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1503, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1602, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1701, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
    __VdfgRegularize_h6e95ff9d_0_9 = (((QData)((IData)(
                                                       (1U 
                                                        & VL_REDXOR_64(
                                                                       (0x00000000deba8050ULL 
                                                                        & __VdfgRegularize_h6e95ff9d_0_8))))) 
                                       << 0x00000021U) 
                                      | __VdfgRegularize_h6e95ff9d_0_8);
    __VdfgRegularize_h6e95ff9d_0_2 = (0x0000048000000000ULL 
                                      | (((QData)((IData)(
                                                          (1U 
                                                           & VL_REDXOR_64(
                                                                          (0x0000007800007fffULL 
                                                                           & __VdfgRegularize_h6e95ff9d_0_1))))) 
                                          << 0x00000039U) 
                                         | __VdfgRegularize_h6e95ff9d_0_1));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3249, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3352, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3455, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3558, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3661, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1415, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1514, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1613, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1712, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__gen_rounused_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3894, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__gen_rounused_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__gen_rounused_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5473, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5507, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 657, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o;
    }
    vlSelfRef.gpio_tb__DOT__cio_gpio_o = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_en_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 665, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_en_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_en_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o;
    }
    vlSelfRef.gpio_tb__DOT__cio_gpio_en_o = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err) {
        ++(vlSelf->__Vcoverage[2920]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q) {
        ++(vlSelf->__Vcoverage[2922]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q)) 
               & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err))))) {
        ++(vlSelf->__Vcoverage[2923]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2901, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_err);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_err 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q) 
           | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__core_rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1119, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__core_rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__core_rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5461, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5495, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg_rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1117, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg_rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg_rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1330, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1439, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1538, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1637, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1211, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_i 
        = (1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_i) 
                 >> 3U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_i 
        = (1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_i) 
                 >> 2U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_i 
        = (1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_i) 
                 >> 1U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_i 
        = (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_i));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5459, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__clk_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__clk_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5493, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__clk_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__clk_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1758, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__clk_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__clk_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1121, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3049, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3033, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3017, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3001, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2985, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__data_in_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2939, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__data_in_qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__data_in_qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_synced))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1368, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_synced);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_synced 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced) 
         != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q))) {
        ++(vlSelf->__Vcoverage[1388]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_1 = 0U;
    } else {
        ++(vlSelf->__Vcoverage[1391]);
        if ((0x0fU <= (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q))) {
            ++(vlSelf->__Vcoverage[1389]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_0 = 0x0fU;
        } else {
            ++(vlSelf->__Vcoverage[1390]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_0 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q)));
        }
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_1 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_0;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_1;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced) 
         != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q))) {
        ++(vlSelf->__Vcoverage[1386]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced) 
         == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q))) {
        ++(vlSelf->__Vcoverage[1387]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_synced))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1469, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_synced);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_synced 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced) 
         != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q))) {
        ++(vlSelf->__Vcoverage[1489]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_1 = 0U;
    } else {
        ++(vlSelf->__Vcoverage[1492]);
        if ((0x0fU <= (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q))) {
            ++(vlSelf->__Vcoverage[1490]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_0 = 0x0fU;
        } else {
            ++(vlSelf->__Vcoverage[1491]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_0 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q)));
        }
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_1 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_0;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_1;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced) 
         != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q))) {
        ++(vlSelf->__Vcoverage[1487]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced) 
         == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q))) {
        ++(vlSelf->__Vcoverage[1488]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_synced))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1568, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_synced);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_synced 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced) 
         != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q))) {
        ++(vlSelf->__Vcoverage[1588]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_1 = 0U;
    } else {
        ++(vlSelf->__Vcoverage[1591]);
        if ((0x0fU <= (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q))) {
            ++(vlSelf->__Vcoverage[1589]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_0 = 0x0fU;
        } else {
            ++(vlSelf->__Vcoverage[1590]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_0 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q)));
        }
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_1 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_0;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_1;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced) 
         != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q))) {
        ++(vlSelf->__Vcoverage[1586]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced) 
         == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q))) {
        ++(vlSelf->__Vcoverage[1587]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_synced))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1667, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_synced);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_synced 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced) 
         != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q))) {
        ++(vlSelf->__Vcoverage[1687]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_1 = 0U;
    } else {
        ++(vlSelf->__Vcoverage[1690]);
        if ((0x0fU <= (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q))) {
            ++(vlSelf->__Vcoverage[1688]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_0 = 0x0fU;
        } else {
            ++(vlSelf->__Vcoverage[1689]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_0 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q)));
        }
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_1 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_0;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_1;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced) 
         != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q))) {
        ++(vlSelf->__Vcoverage[1685]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced) 
         == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q))) {
        ++(vlSelf->__Vcoverage[1686]);
    }
    __VdfgRegularize_h6e95ff9d_0_10 = (((QData)((IData)(
                                                        (1U 
                                                         & VL_REDXOR_64(
                                                                        (0x00000000413d89aaULL 
                                                                         & __VdfgRegularize_h6e95ff9d_0_9))))) 
                                        << 0x00000022U) 
                                       | __VdfgRegularize_h6e95ff9d_0_9);
    __VdfgRegularize_h6e95ff9d_0_3 = (((QData)((IData)(
                                                       (1U 
                                                        & VL_REDXOR_64(
                                                                       (0x017c1ff801ff801fULL 
                                                                        & __VdfgRegularize_h6e95ff9d_0_2))))) 
                                       << 0x0000003aU) 
                                      | __VdfgRegularize_h6e95ff9d_0_2);
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__cio_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__cio_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 12, vlSelfRef.gpio_tb__DOT__cio_gpio_o, vlSelfRef.gpio_tb__DOT____Vtogcov__cio_gpio_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__cio_gpio_o 
            = vlSelfRef.gpio_tb__DOT__cio_gpio_o;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__cio_gpio_en_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__cio_gpio_en_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 20, vlSelfRef.gpio_tb__DOT__cio_gpio_en_o, vlSelfRef.gpio_tb__DOT____Vtogcov__cio_gpio_en_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__cio_gpio_en_o 
            = vlSelfRef.gpio_tb__DOT__cio_gpio_en_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2679, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1123, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5471, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5484, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5505, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5518, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1760, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1398, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1499, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1598, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1697, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1334, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1443, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1542, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1641, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5469, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5482, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5503, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5516, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3998, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2437, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1734, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1747, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1328, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__clk_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__clk_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1437, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__clk_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__clk_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1536, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__clk_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__clk_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1635, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__clk_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__clk_i;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1354, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value 
        = (0x0fU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1455, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value 
        = (0x0fU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1554, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value 
        = (0x0fU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1653, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value 
        = (0x0fU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d));
    __VdfgRegularize_h6e95ff9d_0_11 = (((QData)((IData)(
                                                        (1U 
                                                         & VL_REDXOR_64(
                                                                        (0x0000000031234ed1ULL 
                                                                         & __VdfgRegularize_h6e95ff9d_0_10))))) 
                                        << 0x00000023U) 
                                       | __VdfgRegularize_h6e95ff9d_0_10);
    __VdfgRegularize_h6e95ff9d_0_4 = (((QData)((IData)(
                                                       (1U 
                                                        & VL_REDXOR_64(
                                                                       (0x01bde1f87e0781e1ULL 
                                                                        & __VdfgRegularize_h6e95ff9d_0_3))))) 
                                       << 0x0000003bU) 
                                      | __VdfgRegularize_h6e95ff9d_0_3);
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1736, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1749, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4000, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2439, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1413, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1426, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1512, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1525, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1611, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1624, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1710, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1723, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1400, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1501, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1600, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1699, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4887, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3146, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3257, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3360, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3463, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3566, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3806, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3669, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1396, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1497, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1596, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1695, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1366, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1467, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1566, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1665, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value;
    }
    __VdfgRegularize_h6e95ff9d_0_12 = (((QData)((IData)(
                                                        (1U 
                                                         & VL_REDXOR_64(
                                                                        (0x00000000c2c1323bULL 
                                                                         & __VdfgRegularize_h6e95ff9d_0_11))))) 
                                        << 0x00000024U) 
                                       | __VdfgRegularize_h6e95ff9d_0_11);
    __VdfgRegularize_h6e95ff9d_0_5 = (((QData)((IData)(
                                                       (1U 
                                                        & VL_REDXOR_64(
                                                                       (0x01deee3b8e388e22ULL 
                                                                        & __VdfgRegularize_h6e95ff9d_0_4))))) 
                                       << 0x0000003cU) 
                                      | __VdfgRegularize_h6e95ff9d_0_4);
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4889, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3148, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3259, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3362, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3465, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3568, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3808, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3671, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1404, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1505, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1604, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1703, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__d_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3689, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1411, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1424, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1510, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1523, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1609, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1622, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1708, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1721, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__clk_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__clk_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i;
    }
    __VdfgRegularize_h6e95ff9d_0_13 = (((QData)((IData)(
                                                        (1U 
                                                         & VL_REDXOR_64(
                                                                        (0x000000002dcc624cULL 
                                                                         & __VdfgRegularize_h6e95ff9d_0_12))))) 
                                        << 0x00000025U) 
                                       | __VdfgRegularize_h6e95ff9d_0_12);
    __VdfgRegularize_h6e95ff9d_0_6 = (((QData)((IData)(
                                                       (1U 
                                                        & VL_REDXOR_64(
                                                                       (0x01ef76cdb2c93244ULL 
                                                                        & __VdfgRegularize_h6e95ff9d_0_5))))) 
                                       << 0x0000003dU) 
                                      | __VdfgRegularize_h6e95ff9d_0_5);
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3691, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1428, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__d_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__d_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1527, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__d_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__d_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1626, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__d_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__d_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1725, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__d_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__d_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i;
    }
    __VdfgRegularize_h6e95ff9d_0_7 = (((QData)((IData)(
                                                       (1U 
                                                        & VL_REDXOR_64(
                                                                       (0x01f7bb56d5525488ULL 
                                                                        & __VdfgRegularize_h6e95ff9d_0_6))))) 
                                       << 0x0000003eU) 
                                      | __VdfgRegularize_h6e95ff9d_0_6);
    vlSelfRef.gpio_tb__DOT__tl_i[0U] = (0x00048000U 
                                        | ((0xff000000U 
                                            & vlSelfRef.gpio_tb__DOT__tl_i[0U]) 
                                           | ((0x00002a00U 
                                               ^ ((
                                                   (0x00000040U 
                                                    & (VL_REDXOR_64(
                                                                    (0x01fbdda769a46910ULL 
                                                                     & __VdfgRegularize_h6e95ff9d_0_7)) 
                                                       << 6U)) 
                                                   | (0x0000003fU 
                                                      & (IData)(
                                                                (__VdfgRegularize_h6e95ff9d_0_7 
                                                                 >> 0x00000039U)))) 
                                                  << 8U)) 
                                              | ((0x00000054U 
                                                  ^ 
                                                  (((0x00000040U 
                                                     & (VL_REDXOR_64(
                                                                     (0x0000000098505586ULL 
                                                                      & __VdfgRegularize_h6e95ff9d_0_13)) 
                                                        << 6U)) 
                                                    | (0x0000003fU 
                                                       & (IData)(
                                                                 (__VdfgRegularize_h6e95ff9d_0_13 
                                                                  >> 0x00000020U)))) 
                                                   << 1U)) 
                                                 | (IData)(vlSelfRef.gpio_tb__DOT__tl_i_d_ready)))));
    vlSelfRef.gpio_tb__DOT__tl_i[0U] = ((0x00ffffffU 
                                         & vlSelfRef.gpio_tb__DOT__tl_i[0U]) 
                                        | ((IData)(
                                                   (((QData)((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_mask)) 
                                                     << 0x00000020U) 
                                                    | (QData)((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_data)))) 
                                           << 0x00000018U));
    vlSelfRef.gpio_tb__DOT__tl_i[1U] = (((IData)((((QData)((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_mask)) 
                                                   << 0x00000020U) 
                                                  | (QData)((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_data)))) 
                                         >> 8U) | (
                                                   (vlSelfRef.gpio_tb__DOT__tl_i_a_address 
                                                    << 0x0000001cU) 
                                                   | ((IData)(
                                                              ((((QData)((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_mask)) 
                                                                 << 0x00000020U) 
                                                                | (QData)((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_data))) 
                                                               >> 0x00000020U)) 
                                                      << 0x00000018U)));
    vlSelfRef.gpio_tb__DOT__tl_i[2U] = (((0x00ffffffU 
                                          & (vlSelfRef.gpio_tb__DOT__tl_i_a_address 
                                             >> 4U)) 
                                         | ((IData)(
                                                    ((((QData)((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_mask)) 
                                                       << 0x00000020U) 
                                                      | (QData)((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_data))) 
                                                     >> 0x00000020U)) 
                                            >> 8U)) 
                                        | (((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_source) 
                                            << 0x0000001cU) 
                                           | (0x0f000000U 
                                              & (vlSelfRef.gpio_tb__DOT__tl_i_a_address 
                                                 >> 4U))));
    vlSelfRef.gpio_tb__DOT__tl_i[3U] = ((0x00001ff0U 
                                         & vlSelfRef.gpio_tb__DOT__tl_i[3U]) 
                                        | (0x00001fffU 
                                           & ((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_source) 
                                              >> 4U)));
    vlSelfRef.gpio_tb__DOT__tl_i[3U] = ((0x0000000fU 
                                         & vlSelfRef.gpio_tb__DOT__tl_i[3U]) 
                                        | (0x00001fffU 
                                           & (((((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_valid) 
                                                 << 8U) 
                                                | ((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_opcode) 
                                                   << 5U)) 
                                               | (((IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_param) 
                                                   << 2U) 
                                                  | (IData)(vlSelfRef.gpio_tb__DOT__tl_i_a_size))) 
                                              << 4U)));
    if ((0U != ((((vlSelfRef.gpio_tb__DOT__tl_i[0U] 
                   ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i[0U]) 
                  | (vlSelfRef.gpio_tb__DOT__tl_i[1U] 
                     ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i[1U])) 
                 | (vlSelfRef.gpio_tb__DOT__tl_i[2U] 
                    ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i[2U])) 
                | (vlSelfRef.gpio_tb__DOT__tl_i[3U] 
                   ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i[3U])))) {
        VL_COV_TOGGLE_CHG_ST_W(109, vlSelf->__Vcoverage + 284, vlSelfRef.gpio_tb__DOT__tl_i, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i[0U] 
            = vlSelfRef.gpio_tb__DOT__tl_i[0U];
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i[1U] 
            = vlSelfRef.gpio_tb__DOT__tl_i[1U];
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i[2U] 
            = vlSelfRef.gpio_tb__DOT__tl_i[2U];
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_i[3U] 
            = vlSelfRef.gpio_tb__DOT__tl_i[3U];
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] = vlSelfRef.gpio_tb__DOT__tl_i[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U] = vlSelfRef.gpio_tb__DOT__tl_i[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[2U] = vlSelfRef.gpio_tb__DOT__tl_i[2U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] = vlSelfRef.gpio_tb__DOT__tl_i[3U];
    if ((0x00001000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 681, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                >> 0x0000000cU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
                                                  >> 0x0000000cU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
            = ((0x00000fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U]) 
               | (0x00001000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                        << 0x00000017U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                           >> 9U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
                          << 0x00000017U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
                                             >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 683, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
            = ((0x000011ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U]) 
               | (0x00000e00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                        << 0x0000001aU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                           >> 6U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
                          << 0x0000001aU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
                                             >> 6U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 689, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                 << 0x0000001aU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                 >> 6U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
                                            << 0x0000001aU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
                                              >> 6U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001e3fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U]) 
               | (0x000001c0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                        << 0x0000001cU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                           >> 4U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
                          << 0x0000001cU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
                                             >> 4U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 695, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                 << 0x0000001cU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                 >> 4U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
                                            << 0x0000001cU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
                                              >> 4U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001fcfU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U]) 
               | (0x00000030U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[2U] 
                                           >> 0x0000001cU)) 
                               ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
                                   << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[2U] 
                                             >> 0x0000001cU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 699, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[2U] 
                                           >> 0x0000001cU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[2U] 
                                           >> 0x0000001cU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[2U] 
            = ((0x0fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[2U]) 
               | (0xf0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[2U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001ff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[3U]) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[2U] 
                  << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U] 
                            >> 0x0000001cU)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[2U] 
                                                 << 4U) 
                                                | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[1U] 
                                                   >> 0x0000001cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 715, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[2U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U] 
                                           >> 0x0000001cU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[2U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001cU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[1U] 
            = ((0x0fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[1U]) 
               | (0xf0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[2U] 
            = ((0xf0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[2U]) 
               | (0x0fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[2U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U] 
                                           >> 0x00000018U)) 
                               ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[1U] 
                                   << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[1U] 
                                             >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 779, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x00000018U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[1U] 
            = ((0xf0ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[1U]) 
               | (0x0f000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U] 
                  << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                            >> 0x00000018U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[1U] 
                                                 << 8U) 
                                                | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                                   >> 0x00000018U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 787, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                           >> 0x00000018U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
            = ((0x00ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U]) 
               | (0xff000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[1U] 
            = ((0xff000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[1U]) 
               | (0x00ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U]));
    }
    if ((0U != (0x0000001fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                 >> 0x00000013U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000013U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 851, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                 >> 0x00000013U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000013U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
            = ((0xff07ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U]) 
               | (0x00f80000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                 >> 0x0000000fU)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x0000000fU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 861, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                 >> 0x0000000fU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x0000000fU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
            = ((0xfff87fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U]) 
               | (0x00078000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                 >> 8U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 869, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                 >> 8U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                              >> 8U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
            = ((0xffff80ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U]) 
               | (0x00007f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                 >> 1U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                             << 0x0000001fU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                               >> 1U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 883, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                 >> 1U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                            << 0x0000001fU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
                                              >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
            = ((0xffffff01U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U]) 
               | (0x000000feU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 897, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_i[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[2U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U];
    if ((0x00001000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1762, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                >> 0x0000000cU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
                                                  >> 0x0000000cU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x00000fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x00001000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                        << 0x00000017U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                           >> 9U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
                          << 0x00000017U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
                                             >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 1764, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x000011ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x00000e00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                        << 0x0000001aU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                           >> 6U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
                          << 0x0000001aU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
                                             >> 6U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 1770, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                 << 0x0000001aU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                 >> 6U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
                                            << 0x0000001aU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
                                              >> 6U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001e3fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x000001c0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                        << 0x0000001cU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                           >> 4U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
                          << 0x0000001cU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
                                             >> 4U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 1776, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                 << 0x0000001cU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                 >> 4U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
                                            << 0x0000001cU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
                                              >> 4U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001fcfU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x00000030U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[2U] 
                                           >> 0x0000001cU)) 
                               ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
                                   << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[2U] 
                                             >> 0x0000001cU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1780, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[2U] 
                                           >> 0x0000001cU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[2U] 
                                           >> 0x0000001cU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[2U] 
            = ((0x0fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[2U]) 
               | (0xf0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[2U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001ff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[2U] 
                  << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U] 
                            >> 0x0000001cU)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[2U] 
                                                 << 4U) 
                                                | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[1U] 
                                                   >> 0x0000001cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1796, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[2U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U] 
                                           >> 0x0000001cU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[2U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001cU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[1U] 
            = ((0x0fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[1U]) 
               | (0xf0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[2U] 
            = ((0xf0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[2U]) 
               | (0x0fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[2U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U] 
                                           >> 0x00000018U)) 
                               ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[1U] 
                                   << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[1U] 
                                             >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1860, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x00000018U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[1U] 
            = ((0xf0ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[1U]) 
               | (0x0f000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U] 
                  << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                            >> 0x00000018U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[1U] 
                                                 << 8U) 
                                                | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                                   >> 0x00000018U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1868, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                           >> 0x00000018U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0x00ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0xff000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[1U] 
            = ((0xff000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[1U]) 
               | (0x00ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U]));
    }
    if ((0U != (0x0000001fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                 >> 0x00000013U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000013U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 1932, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                 >> 0x00000013U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000013U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xff07ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0x00f80000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                 >> 0x0000000fU)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x0000000fU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1942, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                 >> 0x0000000fU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x0000000fU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xfff87fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0x00078000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                 >> 8U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 1950, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                 >> 8U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                              >> 8U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xffff80ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0x00007f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                 >> 1U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                             << 0x0000001fU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                               >> 1U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 1964, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                 >> 1U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                            << 0x0000001fU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
                                              >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xffffff01U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0x000000feU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1978, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_i[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[2U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U];
    __Vfunc_mubi4_test_invalid__3__val = (0x0000000fU 
                                          & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                             >> 0x0000000fU));
    gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h51485532__0 
        = (1U & (~ ((6U == (IData)(__Vfunc_mubi4_test_invalid__3__val)) 
                    | (9U == (IData)(__Vfunc_mubi4_test_invalid__3__val)))));
    if (((6U != (IData)(__Vfunc_mubi4_test_invalid__3__val)) 
         & (9U != (IData)(__Vfunc_mubi4_test_invalid__3__val)))) {
        ++(vlSymsp->__Vcoverage[8731]);
    }
    if ((9U == (IData)(__Vfunc_mubi4_test_invalid__3__val))) {
        ++(vlSymsp->__Vcoverage[8732]);
    }
    if ((6U == (IData)(__Vfunc_mubi4_test_invalid__3__val))) {
        ++(vlSymsp->__Vcoverage[8733]);
    }
    ++(vlSymsp->__Vcoverage[8734]);
    __Vfunc_mubi4_test_true_strict__4__val = (0x0000000fU 
                                              & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                                 >> 0x0000000fU));
    gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h9250fec5__0 
        = (6U == (IData)(__Vfunc_mubi4_test_true_strict__4__val));
    ++(vlSymsp->__Vcoverage[8738]);
    ++(vlSymsp->__Vcoverage[8741]);
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__instr_error 
        = ((IData)(gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h51485532__0) 
           | (IData)(gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h9250fec5__0));
    if (gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h9250fec5__0) {
        ++(vlSelf->__Vcoverage[4877]);
    }
    if (gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h51485532__0) {
        ++(vlSelf->__Vcoverage[4878]);
    }
    if ((1U & ((~ (IData)(gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h51485532__0)) 
               & (~ (IData)(gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h9250fec5__0))))) {
        ++(vlSelf->__Vcoverage[4880]);
    }
    if ((0x00001000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4002, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                >> 0x0000000cU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                                  >> 0x0000000cU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x00000fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x00001000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                        << 0x00000017U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                           >> 9U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                          << 0x00000017U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                             >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4004, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x000011ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x00000e00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                        << 0x0000001aU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                           >> 6U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                          << 0x0000001aU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                             >> 6U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4010, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                 << 0x0000001aU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                 >> 6U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                            << 0x0000001aU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                              >> 6U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001e3fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x000001c0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                        << 0x0000001cU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                           >> 4U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                          << 0x0000001cU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                             >> 4U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4016, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                 << 0x0000001cU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                 >> 4U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                            << 0x0000001cU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                              >> 4U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001fcfU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x00000030U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                                           >> 0x0000001cU)) 
                               ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                   << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[2U] 
                                             >> 0x0000001cU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4020, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                                           >> 0x0000001cU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[2U] 
                                           >> 0x0000001cU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[2U] 
            = ((0x0fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[2U]) 
               | (0xf0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001ff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                  << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                            >> 0x0000001cU)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[2U] 
                                                 << 4U) 
                                                | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
                                                   >> 0x0000001cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4036, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                           >> 0x0000001cU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[2U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001cU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
            = ((0x0fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U]) 
               | (0xf0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[2U] 
            = ((0xf0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[2U]) 
               | (0x0fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                           >> 0x00000018U)) 
                               ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
                                   << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
                                             >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4100, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x00000018U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
            = ((0xf0ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U]) 
               | (0x0f000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                  << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                            >> 0x00000018U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
                                                 << 8U) 
                                                | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                                   >> 0x00000018U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4108, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                           >> 0x00000018U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0x00ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0xff000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
            = ((0xff000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U]) 
               | (0x00ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U]));
    }
    if ((0U != (0x0000001fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 >> 0x00000013U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000013U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 4172, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 >> 0x00000013U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000013U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xff07ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0x00f80000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 >> 0x0000000fU)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x0000000fU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4182, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 >> 0x0000000fU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x0000000fU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xfff87fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0x00078000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 >> 8U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4190, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 >> 8U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                              >> 8U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xffff80ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0x00007f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 >> 1U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                             << 0x0000001fU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                               >> 1U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4204, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 >> 1U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                            << 0x0000001fU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                              >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xffffff01U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0x000000feU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4218, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]));
    }
    __Vfunc_tl_a_user_chk__6__user = (0x007fffffU & 
                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                       >> 1U));
    __Vfunc_mubi4_test_invalid__7__val = (0x0000000fU 
                                          & (__Vfunc_tl_a_user_chk__6__user 
                                             >> 0x0000000eU));
    __Vfunc_mubi4_test_invalid__7__Vfuncout = (1U & 
                                               (~ (
                                                   (6U 
                                                    == (IData)(__Vfunc_mubi4_test_invalid__7__val)) 
                                                   | (9U 
                                                      == (IData)(__Vfunc_mubi4_test_invalid__7__val)))));
    if (((6U != (IData)(__Vfunc_mubi4_test_invalid__7__val)) 
         & (9U != (IData)(__Vfunc_mubi4_test_invalid__7__val)))) {
        ++(vlSymsp->__Vcoverage[8731]);
    }
    if ((9U == (IData)(__Vfunc_mubi4_test_invalid__7__val))) {
        ++(vlSymsp->__Vcoverage[8732]);
    }
    if ((6U == (IData)(__Vfunc_mubi4_test_invalid__7__val))) {
        ++(vlSymsp->__Vcoverage[8733]);
    }
    ++(vlSymsp->__Vcoverage[8734]);
    __Vfunc_tl_a_user_chk__6__malformed_err = __Vfunc_mubi4_test_invalid__7__Vfuncout;
    __Vfunc_tl_a_user_chk__6__Vfuncout = __Vfunc_tl_a_user_chk__6__malformed_err;
    if ((0x00400000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9018]);
    }
    if ((0x00200000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9019]);
    }
    if ((0x00100000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9020]);
    }
    if ((0x00080000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9021]);
    }
    if ((0x00040000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9022]);
    }
    if ((0x00020000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9023]);
    }
    if ((0x00010000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9024]);
    }
    if ((0x00008000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9025]);
    }
    if ((0x00004000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9026]);
    }
    if ((0x00002000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9027]);
    }
    if ((0x00001000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9028]);
    }
    if ((0x00000800U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9029]);
    }
    if ((0x00000400U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9030]);
    }
    if ((0x00000200U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9031]);
    }
    if ((0x00000100U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9032]);
    }
    if ((0x00000080U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9033]);
    }
    if ((0x00000040U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9034]);
    }
    if ((0x00000020U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9035]);
    }
    if ((0x00000010U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9036]);
    }
    if ((8U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9037]);
    }
    if ((4U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9038]);
    }
    if ((2U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9039]);
    }
    if ((1U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[9040]);
    }
    if ((IData)((0U == __Vfunc_tl_a_user_chk__6__user))) {
        ++(vlSymsp->__Vcoverage[9041]);
    }
    ++(vlSymsp->__Vcoverage[9042]);
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__malformed_meta_err 
        = __Vfunc_tl_a_user_chk__6__Vfuncout;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_o 
        = (0x0000000cU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                          >> 0x0000001cU));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wdata_o 
        = ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
            << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                      >> 0x00000018U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__be_o 
        = (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                          >> 0x00000018U));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__instr_error) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__instr_error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4652, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__instr_error, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__instr_error);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__instr_error 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__instr_error;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__malformed_meta_err) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__malformed_meta_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4656, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__malformed_meta_err, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__malformed_meta_err);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__malformed_meta_err 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__malformed_meta_err;
    }
    if ((4U == (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                      >> 9U)))) {
        ++(vlSelf->__Vcoverage[5134]);
    }
    if ((1U == (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                      >> 9U)))) {
        ++(vlSelf->__Vcoverage[5135]);
    }
    if ((0U == (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                      >> 9U)))) {
        ++(vlSelf->__Vcoverage[5136]);
    }
    if ((((0U != (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                        >> 9U))) & (1U != (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                                 >> 9U)))) 
         & (4U != (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                         >> 9U))))) {
        ++(vlSelf->__Vcoverage[5137]);
    }
    if ((0x00001000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4891, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                >> 0x0000000cU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                                  >> 0x0000000cU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
            = ((0x00000fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U]) 
               | (0x00001000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                        << 0x00000017U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                           >> 9U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                          << 0x00000017U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                             >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4893, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
            = ((0x000011ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U]) 
               | (0x00000e00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                        << 0x0000001aU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                           >> 6U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                          << 0x0000001aU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                             >> 6U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4899, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 << 0x0000001aU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 >> 6U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                            << 0x0000001aU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                              >> 6U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001e3fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U]) 
               | (0x000001c0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                        << 0x0000001cU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                           >> 4U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                          << 0x0000001cU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                             >> 4U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4905, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 << 0x0000001cU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 >> 4U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                            << 0x0000001cU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                              >> 4U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001fcfU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U]) 
               | (0x00000030U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U] 
                                           >> 0x0000001cU)) 
                               ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                   << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[2U] 
                                             >> 0x0000001cU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4909, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U] 
                                           >> 0x0000001cU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[2U] 
                                           >> 0x0000001cU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[2U] 
            = ((0x0fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[2U]) 
               | (0xf0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001ff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U]) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U] 
                  << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                            >> 0x0000001cU)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[2U] 
                                                 << 4U) 
                                                | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
                                                   >> 0x0000001cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4925, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                           >> 0x0000001cU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[2U] 
                                 << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001cU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
            = ((0x0fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U]) 
               | (0xf0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[2U] 
            = ((0xf0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[2U]) 
               | (0x0fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                           >> 0x00000018U)) 
                               ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
                                   << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
                                             >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4989, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x00000018U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
            = ((0xf0ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U]) 
               | (0x0f000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                  << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                            >> 0x00000018U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
                                                 << 8U) 
                                                | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                                   >> 0x00000018U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4997, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
                                 << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                           >> 0x00000018U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
            = ((0x00ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U]) 
               | (0xff000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
            = ((0xff000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U]) 
               | (0x00ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U]));
    }
    if ((0U != (0x0000001fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 >> 0x00000013U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000013U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 5061, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 >> 0x00000013U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000013U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
            = ((0xff07ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U]) 
               | (0x00f80000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 >> 0x0000000fU)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x0000000fU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5071, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 >> 0x0000000fU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x0000000fU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
            = ((0xfff87fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U]) 
               | (0x00078000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 >> 8U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5079, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 >> 8U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                              >> 8U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
            = ((0xffff80ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U]) 
               | (0x00007f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 >> 1U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                             << 0x0000001fU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                               >> 1U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5093, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 >> 1U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                            << 0x0000001fU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                              >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
            = ((0xffffff01U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U]) 
               | (0x000000feU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5107, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed 
        = ((0U == (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                         >> 9U))) | ((1U == (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                                   >> 9U))) 
                                     | (4U == (7U & 
                                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                                >> 9U)))));
    __Vfunc_mubi4_test_invalid__9__val = (0x0000000fU 
                                          & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                             >> 0x0000000fU));
    __Vfunc_mubi4_test_invalid__9__Vfuncout = (1U & 
                                               (~ (
                                                   (6U 
                                                    == (IData)(__Vfunc_mubi4_test_invalid__9__val)) 
                                                   | (9U 
                                                      == (IData)(__Vfunc_mubi4_test_invalid__9__val)))));
    if (((6U != (IData)(__Vfunc_mubi4_test_invalid__9__val)) 
         & (9U != (IData)(__Vfunc_mubi4_test_invalid__9__val)))) {
        ++(vlSymsp->__Vcoverage[8731]);
    }
    if ((9U == (IData)(__Vfunc_mubi4_test_invalid__9__val))) {
        ++(vlSymsp->__Vcoverage[8732]);
    }
    if ((6U == (IData)(__Vfunc_mubi4_test_invalid__9__val))) {
        ++(vlSymsp->__Vcoverage[8733]);
    }
    ++(vlSymsp->__Vcoverage[8734]);
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err 
        = __Vfunc_mubi4_test_invalid__9__Vfuncout;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full 
        = (0U == (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                        >> 9U)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get 
        = (4U == (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                        >> 9U)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial 
        = (1U == (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                        >> 9U)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask 
        = (0x0000000fU & ((IData)(1U) << (3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                                >> 0x0000001cU))));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4364, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_addr 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_o;
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wdata_o 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wdata_o))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4372, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wdata_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wdata_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wdata_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wdata_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_wdata 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wdata_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__be_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__be_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4436, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__be_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__be_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__be_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__be_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_be 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__be_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__opcode_allowed))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5111, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__opcode_allowed);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__opcode_allowed 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__instr_type_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5127, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__instr_type_err);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__instr_type_err 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_full))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5115, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_full);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_full 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_get))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5119, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_get);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_get 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_partial))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5117, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_partial);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_partial 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial;
    }
    __Vfunc_mubi4_test_true_strict__8__val = (0x0000000fU 
                                              & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                                 >> 0x0000000fU));
    gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VExpr_h9250fec5__0 
        = (6U == (IData)(__Vfunc_mubi4_test_true_strict__8__val));
    ++(vlSymsp->__Vcoverage[8738]);
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err 
        = ((IData)(gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VExpr_h9250fec5__0) 
           & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full) 
              | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial)));
    if (((IData)(gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VExpr_h9250fec5__0) 
         & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial))) {
        ++(vlSelf->__Vcoverage[5123]);
    }
    if (((IData)(gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VExpr_h9250fec5__0) 
         & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full))) {
        ++(vlSelf->__Vcoverage[5124]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full)) 
               & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial))))) {
        ++(vlSelf->__Vcoverage[5125]);
    }
    if ((1U & (~ (IData)(gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VExpr_h9250fec5__0)))) {
        ++(vlSelf->__Vcoverage[5126]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__mask)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5144, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__mask);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__mask 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk = 0U;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk = 0U;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk = 0U;
    if ((0x00001000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U])) {
        if ((0U == (3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                          >> 4U)))) {
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk = 1U;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk 
                = (1U & (~ (0U != (0x0000000fU & ((
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                                    << 8U) 
                                                   | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                                      >> 0x00000018U)) 
                                                  & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask)))))));
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk 
                = (0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                            << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                      >> 0x00000018U)) 
                          & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask)));
            if ((1U & ((((~ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                              >> 0x00000018U) & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask)))) 
                         & (~ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                >> 0x00000019U) & (~ 
                                                   ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                                    >> 1U))))) 
                        & (~ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                               >> 0x0000001aU) & (~ 
                                                  ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                                   >> 2U))))) 
                       & (~ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                              >> 0x0000001bU) & (~ 
                                                 ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                                  >> 3U))))))) {
                ++(vlSelf->__Vcoverage[5152]);
            }
            if ((1U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                        >> 0x0000001bU) & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                              >> 3U))))) {
                ++(vlSelf->__Vcoverage[5153]);
            }
            if ((1U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                        >> 0x0000001aU) & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                              >> 2U))))) {
                ++(vlSelf->__Vcoverage[5154]);
            }
            if ((1U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                        >> 0x00000019U) & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                              >> 1U))))) {
                ++(vlSelf->__Vcoverage[5155]);
            }
            if ((1U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                        >> 0x00000018U) & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask))))) {
                ++(vlSelf->__Vcoverage[5156]);
            }
            if (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                  >> 0x0000001bU) & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                     >> 3U))) {
                ++(vlSelf->__Vcoverage[5157]);
            }
            if ((1U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                        >> 0x0000001aU) & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                           >> 2U)))) {
                ++(vlSelf->__Vcoverage[5158]);
            }
            if ((1U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                        >> 0x00000019U) & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                           >> 1U)))) {
                ++(vlSelf->__Vcoverage[5159]);
            }
            if ((1U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                        >> 0x00000018U) & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask)))) {
                ++(vlSelf->__Vcoverage[5160]);
            }
            if ((1U & ((((~ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                              >> 0x00000018U) & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask))) 
                         & (~ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                >> 0x00000019U) & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                                   >> 1U)))) 
                        & (~ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                               >> 0x0000001aU) & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                                  >> 2U)))) 
                       & (~ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                              >> 0x0000001bU) & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                                 >> 3U)))))) {
                ++(vlSelf->__Vcoverage[5161]);
            }
            ++(vlSelf->__Vcoverage[5162]);
        } else if ((1U == (3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 >> 4U)))) {
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk 
                = (1U & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                            >> 0x0000001cU)));
            if ((0x20000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])) {
                ++(vlSelf->__Vcoverage[5167]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VlemCond_0 
                    = (1U & (~ (0U != (3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                             >> 0x00000018U)))));
            } else {
                ++(vlSelf->__Vcoverage[5168]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VlemCond_0 
                    = (1U & (~ (0U != (0x0cU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                                >> 0x00000018U)))));
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VlemCond_0;
            if ((0x20000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])) {
                ++(vlSelf->__Vcoverage[5171]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VlemCond_1 
                    = (3U == (3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                    >> 0x0000001aU)));
            } else {
                ++(vlSelf->__Vcoverage[5172]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VlemCond_1 
                    = (3U == (3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                    >> 0x00000018U)));
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VlemCond_1;
            if ((1U & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                          >> 0x0000001cU)))) {
                ++(vlSelf->__Vcoverage[5163]);
            }
            if ((0x10000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])) {
                ++(vlSelf->__Vcoverage[5164]);
            }
            if ((0x20000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])) {
                ++(vlSelf->__Vcoverage[5165]);
            }
            if ((1U & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                          >> 0x0000001dU)))) {
                ++(vlSelf->__Vcoverage[5166]);
            }
            if ((0x20000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])) {
                ++(vlSelf->__Vcoverage[5169]);
            }
            if ((1U & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                          >> 0x0000001dU)))) {
                ++(vlSelf->__Vcoverage[5170]);
            }
            ++(vlSelf->__Vcoverage[5173]);
        } else if ((2U == (3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 >> 4U)))) {
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk 
                = (1U & (~ (0U != (3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                         >> 0x0000001cU)))));
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk = 1U;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk 
                = (0x0000000fU == (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                                  >> 0x00000018U)));
            if ((IData)((0U == (0x30000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])))) {
                ++(vlSelf->__Vcoverage[5174]);
            }
            if ((0x20000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])) {
                ++(vlSelf->__Vcoverage[5175]);
            }
            if ((0x10000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])) {
                ++(vlSelf->__Vcoverage[5176]);
            }
            if ((IData)((0x0f000000U == (0x0f000000U 
                                         & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])))) {
                ++(vlSelf->__Vcoverage[5177]);
            }
            if ((1U & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                          >> 0x0000001bU)))) {
                ++(vlSelf->__Vcoverage[5178]);
            }
            if ((1U & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                          >> 0x0000001aU)))) {
                ++(vlSelf->__Vcoverage[5179]);
            }
            if ((1U & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                          >> 0x00000019U)))) {
                ++(vlSelf->__Vcoverage[5180]);
            }
            if ((1U & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                          >> 0x00000018U)))) {
                ++(vlSelf->__Vcoverage[5181]);
            }
            ++(vlSelf->__Vcoverage[5182]);
        } else {
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk = 0U;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk = 0U;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk = 0U;
            ++(vlSelf->__Vcoverage[5183]);
        }
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((2U 
                                                 == 
                                                 (3U 
                                                  & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                                     >> 4U))) 
                                                << 2U) 
                                               | (((1U 
                                                    == 
                                                    (3U 
                                                     & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                                        >> 4U))) 
                                                   << 1U) 
                                                  | (0U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                                         >> 4U))))))))))) {
            if ((0U != (((2U == (3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                       >> 4U))) << 2U) 
                        | (((1U == (3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                          >> 4U))) 
                            << 1U) | (0U == (3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                                   >> 4U))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: tlul_err.sv:62: Assertion failed in %m: unique case, but multiple matches found for '32'h%X'\n",4, 'M',vlSymsp->name(),"gpio_tb.u_gpio.u_gpio_reg.u_flexsoc_tlul_to_reg.u_err", 'T',-9
                                 , '#',64,VL_TIME_UNITED_Q(1000)
                                 , '#',32,(3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                                 >> 4U)));
                    VL_STOP_MT("/home/eneadim/github/flexsoc/vendor/lowrisc_ip/ip/tlul/rtl/tlul_err.sv", 62, "");
                }
            }
        }
        ++(vlSelf->__Vcoverage[5184]);
    } else {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk = 0U;
        ++(vlSelf->__Vcoverage[5185]);
    }
    ++(vlSelf->__Vcoverage[5186]);
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_addr) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_addr)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2202, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_addr, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_addr);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_addr 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_addr;
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_wdata 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_wdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2210, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_wdata, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_wdata);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_wdata 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_wdata;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_be) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_be)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2274, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_be, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_be);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_be 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_be;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__instr_wr_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5121, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__instr_wr_err);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__instr_wr_err 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__addr_sz_chk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5138, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__addr_sz_chk);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__addr_sz_chk 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__mask_chk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5140, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__mask_chk);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__mask_chk 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__fulldata_chk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5142, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__fulldata_chk);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__fulldata_chk 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk;
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk) 
          & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk)) 
         & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk))) {
        ++(vlSelf->__Vcoverage[5187]);
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk) 
          & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk)) 
         & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial))) {
        ++(vlSelf->__Vcoverage[5188]);
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk) 
          & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk)) 
         & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get))) {
        ++(vlSelf->__Vcoverage[5189]);
    }
    if ((1U & (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get)) 
                & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial))) 
               & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk))))) {
        ++(vlSelf->__Vcoverage[5190]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk)))) {
        ++(vlSelf->__Vcoverage[5191]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk)))) {
        ++(vlSelf->__Vcoverage[5192]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk) 
           & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk) 
              & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get) 
                 | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial) 
                    | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk)))));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__a_config_allowed))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5113, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__a_config_allowed);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__a_config_allowed 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err) {
        ++(vlSelf->__Vcoverage[5129]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err) {
        ++(vlSelf->__Vcoverage[5130]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed)))) {
        ++(vlSelf->__Vcoverage[5131]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed)))) {
        ++(vlSelf->__Vcoverage[5132]);
    }
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed) 
           & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed)) 
          & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err))) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err)))) {
        ++(vlSelf->__Vcoverage[5133]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__err_o 
        = (1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err) 
                 | ((~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed) 
                        & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed))) 
                    | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err))));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__err_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__err_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5109, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__err_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__err_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__err_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__err_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_err 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__err_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_err) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4658, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_err, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_err);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_err 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_err;
    }
}

void Vtop___024root___ico_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
        = (((QData)((IData)(((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re) 
                               | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we)) 
                              << 5U) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we) 
                                         << 4U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_addr))))) 
            << 0x00000024U) | (((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_wdata)) 
                                << 4U) | (QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_be))));
    if ((IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                  ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req) 
                 >> 0x00000029U))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2282, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                                                       >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
                                                                                >> 0x00000029U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
            = ((0x000001ffffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                                 >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                        >> 0x00000028U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
                                                    >> 0x00000028U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2284, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                                                       >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
                                                                                >> 0x00000028U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
            = ((0x000002ffffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((0U != (0x0000000fU & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                        >> 0x00000024U)) 
                               ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
                                          >> 0x00000024U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2286, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
                                                                                >> 0x00000024U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
            = ((0x0000030fffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req) 
               | ((QData)((IData)((0x0000000fU & (IData)(
                                                         (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                                          >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                         >> 4U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
                                            >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2294, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                                                        >> 4U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
                                                                                >> 4U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
            = ((0x000003f00000000fULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                           >> 4U)))) 
                  << 4U));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2358, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
            = ((0x000003fffffffff0ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req) 
               | (IData)((IData)((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req;
    if ((IData)((0x0000030000000000ULL == (0x0000030000000000ULL 
                                           & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i)))) {
        ++(vlSelf->__Vcoverage[2924]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                          >> 0x00000028U))))) {
        ++(vlSelf->__Vcoverage[2926]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                          >> 0x00000029U))))) {
        ++(vlSelf->__Vcoverage[2927]);
    }
    if ((IData)((0x0000020000000000ULL == (0x0000030000000000ULL 
                                           & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i)))) {
        ++(vlSelf->__Vcoverage[2928]);
    }
    if ((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                       >> 0x00000028U)))) {
        ++(vlSelf->__Vcoverage[2930]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                          >> 0x00000029U))))) {
        ++(vlSelf->__Vcoverage[2931]);
    }
    if ((IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                  ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
                 >> 0x00000029U))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2441, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                                       >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x00000029U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
            = ((0x000001ffffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                 >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                        >> 0x00000028U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                                    >> 0x00000028U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2443, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                                       >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x00000028U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
            = ((0x000002ffffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((0U != (0x0000000fU & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                        >> 0x00000024U)) 
                               ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                          >> 0x00000024U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2445, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x00000024U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
            = ((0x0000030fffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((0x0000000fU & (IData)(
                                                         (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                          >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                         >> 4U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                            >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2453, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                                        >> 4U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                                                                >> 4U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
            = ((0x000003f00000000fULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                           >> 4U)))) 
                  << 4U));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2517, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
            = ((0x000003fffffffff0ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
               | (IData)((IData)((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata 
        = (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                   >> 4U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be 
        = (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re 
        = (IData)((0x0000020000000000ULL == (0x0000030000000000ULL 
                                             & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we 
        = (IData)((0x0000030000000000ULL == (0x0000030000000000ULL 
                                             & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr 
        = (0x0000000fU & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                  >> 0x00000024U)));
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_wdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2693, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_wdata);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_wdata 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_wdata 
        = (1U & VL_REDXOR_32(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd 
        = (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata);
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd 
        = (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata 
                          >> 4U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd 
        = (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata 
                          >> 8U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd 
        = (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata 
                          >> 0x0000000cU));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd 
        = (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata 
                          >> 0x00000010U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd 
        = (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata);
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd 
        = (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata 
                          >> 4U));
    if ((IData)((7U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3130]);
    }
    if ((IData)((0x0bU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3131]);
    }
    if ((IData)((0x0dU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3132]);
    }
    if ((IData)((1U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3133]);
    }
    if ((IData)((0x0eU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3134]);
    }
    if ((IData)((2U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3135]);
    }
    if ((IData)((4U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3136]);
    }
    if ((IData)((8U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3137]);
    }
    if ((IData)((0x0fU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3138]);
    }
    if ((IData)((3U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3139]);
    }
    if ((IData)((5U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3140]);
    }
    if ((IData)((9U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3141]);
    }
    if ((IData)((6U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3142]);
    }
    if ((IData)((0x0aU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3143]);
    }
    if ((IData)((0x0cU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3144]);
    }
    if ((IData)((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3145]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_be)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2757, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_be);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_be 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be 
        = (1U & VL_REDXOR_4(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2683, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_re);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_re 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2681, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_addr)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2685, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_addr);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_addr 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit 
        = (((8U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr)) 
            << 2U) | (((4U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr)) 
                       << 1U) | (0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr))));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_wdata) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_wdata))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3126, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_wdata, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_wdata);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_wdata 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_wdata;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2993, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3009, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3025, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3041, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3057, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2959, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2975, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_be))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3128, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_be);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_be 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be;
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
          & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
             >> 2U)) & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be) 
                           >> 2U)))) {
        ++(vlSelf->__Vcoverage[3087]);
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
          & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
             >> 2U)) & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be) 
                           >> 1U)))) {
        ++(vlSelf->__Vcoverage[3088]);
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
          & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
             >> 2U)) & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3089]);
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
          & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
             >> 1U)) & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3093]);
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
          & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3097]);
    }
    if ((IData)((7U == (7U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be))))) {
        ++(vlSelf->__Vcoverage[3098]);
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be) 
               & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                     >> 2U))))) {
        ++(vlSelf->__Vcoverage[3099]);
    }
    if ((IData)(((7U == (7U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be))) 
                 & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                       >> 1U))))) {
        ++(vlSelf->__Vcoverage[3100]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be) 
         & (0U == (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))))) {
        ++(vlSelf->__Vcoverage[3101]);
    }
    if (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit)) 
         & (7U == (7U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be))))) {
        ++(vlSelf->__Vcoverage[3102]);
    }
    if ((IData)(((0U == (5U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) 
                 & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3103]);
    }
    if ((IData)(((0U == (3U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) 
                 & (7U == (7U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))))) {
        ++(vlSelf->__Vcoverage[3104]);
    }
    if ((IData)((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit)))) {
        ++(vlSelf->__Vcoverage[3105]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[3106]);
    }
    ++(vlSelf->__Vcoverage[3107]);
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addr_hit)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3074, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addr_hit);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addr_hit 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
           & ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                & (0U != (1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be))))) 
               | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                   >> 1U) & (0U != (1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))))) 
              | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                  >> 2U) & (0U != (7U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))))));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re) 
         | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we))) {
        ++(vlSelf->__Vcoverage[3084]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____VlemCond_0 
            = (1U & (~ (0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))));
    } else {
        ++(vlSelf->__Vcoverage[3085]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) {
        ++(vlSelf->__Vcoverage[3081]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re) {
        ++(vlSelf->__Vcoverage[3082]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re)) 
               & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we))))) {
        ++(vlSelf->__Vcoverage[3083]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3572, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3469, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3366, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3263, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3152, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3954, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3906, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__wr_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2833, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__wr_err);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__wr_err 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err) {
        ++(vlSelf->__Vcoverage[2935]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss) {
        ++(vlSelf->__Vcoverage[2936]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss)) 
               & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err))))) {
        ++(vlSelf->__Vcoverage[2937]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addrmiss))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2831, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addrmiss);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addrmiss 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i 
        = ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss)) 
           & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss) 
           | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3628, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3525, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3422, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3319, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3216, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3974, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3926, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__en_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3679, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__en_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__en_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i;
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
           >> 1U) & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[3108]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[3109]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re)))) {
        ++(vlSelf->__Vcoverage[3110]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[3111]);
    }
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
           >> 1U) & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[3112]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[3113]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[3114]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[3115]);
    }
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
           >> 2U) & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[3116]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[3117]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[3118]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                  >> 2U)))) {
        ++(vlSelf->__Vcoverage[3119]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2829, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_error);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_error 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re 
        = (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
            >> 1U) & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)) 
                      & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
           & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)) 
              & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                 >> 2U)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we 
        = (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
            >> 1U) & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)) 
                      & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__en_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3703, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__en_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__en_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2947, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_re);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_re 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2983, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2949, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check 
        = (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we) 
            << 2U) | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we) 
                      << 1U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3902, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__re);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__re 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3950, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__re);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__re 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3150, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3261, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3364, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3467, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3570, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_check)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 2903, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_check);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_check 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3904, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3952, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qre))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3924, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qre);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qre 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qre))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3972, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qre);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qre 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3243]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3244]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3214, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3247]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[3248]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3245]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3246]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3346]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3347]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3317, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3350]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[3351]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3348]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3349]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3449]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3450]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3420, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3453]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[3454]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3451]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3452]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3552]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3553]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3523, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3556]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[3557]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3554]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3555]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3655]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3656]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3626, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3659]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[3660]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3657]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3658]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3673, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3922, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3970, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we 
        = (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe) 
            << 1U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3234, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3232, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3337, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3335, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3440, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3438, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3543, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3541, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3646, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3644, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__in_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3788, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__in_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__in_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv 
        = (7U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i)));
    if ((IData)((3U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we)))) {
        ++(vlSelf->__Vcoverage[3071]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we) 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[3072]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we)))) {
        ++(vlSelf->__Vcoverage[3073]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_flds_we)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 3067, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_flds_we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_flds_we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe 
        = (3U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3196, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3194, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3212]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[3213]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3210]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[3211]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3299, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3297, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3315]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[3316]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3313]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[3314]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3402, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3400, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3418]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[3419]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3416]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[3417]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3505, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3503, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3521]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[3522]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3519]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[3520]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3608, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3606, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3624]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[3625]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3622]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[3623]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__inv)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3800, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__inv);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__inv 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o 
        = (7U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv)));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3065, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
        = ((((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q) 
               << 0x0000000aU) | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe) 
                                  << 9U)) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q) 
                                              << 5U) 
                                             | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe) 
                                                 << 4U) 
                                                | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q)))) 
            << 0x00000010U) | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q) 
                                 << 0x0000000cU) | 
                                ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q) 
                                 << 8U)) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q) 
                                             << 4U) 
                                            | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q))));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3168, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3178, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3271, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3281, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3374, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3384, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3477, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3487, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3580, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3590, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__out_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3794, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__out_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__out_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o;
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 0x0000001aU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2593, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x0000001aU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000001aU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x03ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x3c000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0x02000000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2601, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x00000019U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000019U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3dffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x02000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 0x00000015U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2603, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x00000015U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000015U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3e1fffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x01e00000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0x00100000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2611, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x00000014U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000014U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3fefffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x00100000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2613, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3ff0ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x000f0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 0x0000000cU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2621, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x0000000cU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000000cU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3fff0fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x0000f000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2629, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 8U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3ffff0ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x00000f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2637, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 4U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3fffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2645, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3ffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_buf)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3683, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_buf);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_buf 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf;
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 0x0000001aU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2112, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x0000001aU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000001aU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x03ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x3c000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0x02000000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2120, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x00000019U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000019U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3dffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x02000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 0x00000015U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2122, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x00000015U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000015U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3e1fffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x01e00000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0x00100000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2130, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x00000014U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000014U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3fefffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x00100000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2132, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3ff0ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x000f0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 0x0000000cU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2140, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x0000000cU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000000cU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3fff0fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x0000f000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2148, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 8U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3ffff0ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x00000f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2156, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 4U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3fffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2164, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3ffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__oh_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3693, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__oh_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__oh_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree 
        = ((7U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)) 
           | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i) 
              << 3U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree 
        = ((7U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree)) 
           | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i) 
              << 3U));
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 0x0000001aU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1031, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x0000001aU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000001aU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x03ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x3c000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0x02000000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1039, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x00000019U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000019U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3dffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x02000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 0x00000015U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1041, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x00000015U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000015U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3e1fffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x01e00000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0x00100000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1049, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x00000014U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000014U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3fefffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x00100000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1051, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3ff0ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x000f0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 0x0000000cU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1059, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x0000000cU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000000cU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3fff0fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x0000f000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1067, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 8U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3ffff0ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x00000f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1075, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 4U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3fffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1083, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3ffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree)))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 3707, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree)))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 3721, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree;
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 0x0000001aU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1125, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x0000001aU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000001aU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x03ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x3c000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0x02000000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1133, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x00000019U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000019U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3dffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x02000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 0x00000015U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1135, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x00000015U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000015U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3e1fffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x01e00000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0x00100000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1143, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x00000014U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000014U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3fefffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x00100000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1145, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3ff0ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x000f0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 0x0000000cU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1153, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x0000000cU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000000cU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3fff0fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x0000f000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1161, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 8U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3ffff0ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x00000f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1169, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 4U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3fffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1177, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3ffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i 
        = (1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                 >> 0x00000013U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i 
        = (1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                 >> 0x00000012U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i 
        = (1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                 >> 0x00000011U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i 
        = (1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                 >> 0x00000010U));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__enable_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1332, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__enable_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__enable_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i) {
        ++(vlSelf->__Vcoverage[1394]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_2 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q;
    } else {
        ++(vlSelf->__Vcoverage[1395]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_2 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_2;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i) {
        ++(vlSelf->__Vcoverage[1392]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i)))) {
        ++(vlSelf->__Vcoverage[1393]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__enable_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1441, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__enable_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__enable_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i) {
        ++(vlSelf->__Vcoverage[1495]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_2 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q;
    } else {
        ++(vlSelf->__Vcoverage[1496]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_2 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_2;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i) {
        ++(vlSelf->__Vcoverage[1493]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i)))) {
        ++(vlSelf->__Vcoverage[1494]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__enable_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1540, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__enable_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__enable_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i) {
        ++(vlSelf->__Vcoverage[1594]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_2 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q;
    } else {
        ++(vlSelf->__Vcoverage[1595]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_2 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_2;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i) {
        ++(vlSelf->__Vcoverage[1592]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i)))) {
        ++(vlSelf->__Vcoverage[1593]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__enable_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1639, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__enable_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__enable_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i) {
        ++(vlSelf->__Vcoverage[1693]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_2 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q;
    } else {
        ++(vlSelf->__Vcoverage[1694]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_2 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_2;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i) {
        ++(vlSelf->__Vcoverage[1691]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i)))) {
        ++(vlSelf->__Vcoverage[1692]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1344, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1445, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1544, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1643, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d 
        = ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o) 
             << 3U) | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o) 
                       << 2U)) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o) 
                                   << 1U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o)));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1243, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d) 
           & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
              >> 8U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low 
        = (0x0000000fU & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d)) 
                          & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                             >> 0x0000000cU)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d) 
           & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q)) 
              & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q) 
           & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d)) 
              & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                 >> 4U)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg 
        = (0x00000100U | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d) 
                           << 9U) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q) 
                                      << 4U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q))));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_high)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1291, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_high);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_high 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_low)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1299, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_low);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_low 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_rise)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1275, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_rise);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_rise 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_fall)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1283, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_fall);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_fall 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise) 
           | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall) 
              | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high) 
                 | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low))));
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
                               >> 9U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1185, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                >> 9U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg) 
                                         >> 9U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg 
            = ((0x01ffU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
               | (0x00001e00U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg)));
    }
    if ((0x00000100U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1193, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                >> 8U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg) 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg 
            = ((0x1effU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
               | (0x00000100U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1195, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg 
            = ((0x1f0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1203, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg 
            = ((0x1ff0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
               | (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__intr_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1235, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__intr_gpio_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__intr_gpio_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o;
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
                               >> 9U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1091, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                >> 9U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg) 
                                         >> 9U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg 
            = ((0x01ffU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
               | (0x00001e00U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg)));
    }
    if ((0x00000100U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1099, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                >> 8U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg) 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg 
            = ((0x1effU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
               | (0x00000100U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1101, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg 
            = ((0x1f0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1109, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg 
            = ((0x1ff0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
               | (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__intr_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 673, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__intr_gpio_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__intr_gpio_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o;
    }
    vlSelfRef.gpio_tb__DOT__intr_gpio_o = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o;
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
                               >> 9U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2172, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                >> 9U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg) 
                                         >> 9U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg 
            = ((0x01ffU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
               | (0x00001e00U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg)));
    }
    if ((0x00000100U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2180, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                >> 8U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg) 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg 
            = ((0x1effU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
               | (0x00000100U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2182, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg 
            = ((0x1f0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2190, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg 
            = ((0x1ff0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
               | (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__intr_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__intr_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 28, vlSelfRef.gpio_tb__DOT__intr_gpio_o, vlSelfRef.gpio_tb__DOT____Vtogcov__intr_gpio_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__intr_gpio_o 
            = vlSelfRef.gpio_tb__DOT__intr_gpio_o;
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
                               >> 9U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2653, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                >> 9U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
                                         >> 9U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x01ffU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
               | (0x00001e00U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg)));
    }
    if ((0x00000100U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2661, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                >> 8U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x1effU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
               | (0x00000100U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2663, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x1f0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2671, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x1ff0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
               | (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d 
        = (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                          >> 9U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de 
        = (1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                 >> 8U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d 
        = (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                          >> 4U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d 
        = (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3812, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__de))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3810, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__de);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__de 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3914, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3962, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3868, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__de))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3866, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__de);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__de 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3934, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3942, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3982, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3990, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3886, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3884, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2967, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2951, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next = 0U;
    if ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xfffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs));
        ++(vlSelf->__Vcoverage[3121]);
    } else if ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffffff00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs) 
                   << 4U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs)));
        ++(vlSelf->__Vcoverage[3122]);
    } else if ((4U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs) 
                    << 0x0000000cU) | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs) 
                                       << 8U)) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs) 
                                                   << 4U) 
                                                  | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs))));
        ++(vlSelf->__Vcoverage[3123]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xfff0ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs) 
                  << 0x00000010U));
    } else {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next = 0xffffffffU;
        ++(vlSelf->__Vcoverage[3124]);
    }
    if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))))))) {
        if ((0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: gpio_reg_core.sv:362: Assertion failed in %m: unique case, but multiple matches found for '1'h1'\n",3, 'M',vlSymsp->name(),"gpio_tb.u_gpio.u_gpio_reg.u_reg_core", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("/tmp/flexsoc-ip-v1-release-20260914/gpio-tlul/runs/gpio/release/rtl/gpio_reg_core.sv", 362, "");
            }
        }
    }
    ++(vlSelf->__Vcoverage[3125]);
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3848, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3846, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3864]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[3865]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3862]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[3863]);
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2835, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3820, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3830, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds;
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2765, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
        = (((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata)) 
            << 2U) | (QData)((IData)((1U | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error) 
                                            << 1U)))));
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                         >> 2U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2525, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                                                        >> 2U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((3ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                        >> 1U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2589, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffdULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2591, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o;
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                         >> 2U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2366, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                                                                        >> 2U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
                                                                                >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
            = ((3ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                        >> 1U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2430, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
                                                                                >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
            = ((0x00000003fffffffdULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2432, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
            = ((0x00000003fffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i 
        = (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                   >> 2U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i 
        = (1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                         >> 1U)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i 
        = (1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp)));
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_i))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4446, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4510, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i;
    }
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q)) 
               & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i))))) {
        ++(vlSelf->__Vcoverage[4873]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q)) 
               & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                     >> 0x0000000cU))))) {
        ++(vlSelf->__Vcoverage[4874]);
    }
    if (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
          >> 0x0000000cU) & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i))) {
        ++(vlSelf->__Vcoverage[4875]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q) {
        ++(vlSelf->__Vcoverage[4876]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__busy_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4444, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__busy_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__busy_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
        = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]) 
           | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error) 
               << 1U) | (1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q) 
                                  | ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                      >> 0x0000000cU) 
                                     & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i)))))));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
        = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]) 
           | ((IData)((((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q)) 
                        << 0x00000029U) | (((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q)) 
                                            << 0x00000021U) 
                                           | (QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata))))) 
              << 0x00000010U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
        = ((0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]) 
           | (((IData)((((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q)) 
                         << 0x00000029U) | (((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q)) 
                                             << 0x00000021U) 
                                            | (QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata))))) 
               >> 0x00000010U) | ((IData)(((((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q)) 
                                             << 0x00000029U) 
                                            | (((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q)) 
                                                << 0x00000021U) 
                                               | (QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata)))) 
                                           >> 0x00000020U)) 
                                  << 0x00000010U)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
        = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]) 
           | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q) 
              << 0x0000001eU));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
        = (3U & ((0x3ffffffeU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q) 
                                 << 1U)) | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q) 
                                            >> 2U)));
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4741, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4743, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4749, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4755, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4759, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4775, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4777, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4841, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4855, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4869, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4871, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl 
        = (1U & VL_REDXOR_32(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]) 
                              ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U])));
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5193, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5195, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5201, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 5207, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5211, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5227, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5229, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5293, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5307, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5321, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5323, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U];
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5457, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl;
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5325, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5327, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5333, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 5339, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5343, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5359, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5361, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5425, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5439, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5453, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5455, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U];
    if ((IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                  >> 0x0000000cU) & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]))) {
        ++(vlSelf->__Vcoverage[4690]);
    }
    if ((1U & (~ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]))) {
        ++(vlSelf->__Vcoverage[4691]);
    }
    if ((1U & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                  >> 0x0000000cU)))) {
        ++(vlSelf->__Vcoverage[4692]);
    }
    if ((IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                  >> 1U) & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]))) {
        ++(vlSelf->__Vcoverage[4693]);
    }
    if ((1U & (~ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]))) {
        ++(vlSelf->__Vcoverage[4694]);
    }
    if ((1U & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[4695]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack 
        = (IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                    >> 1U) & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]));
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4220, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4222, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4228, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4234, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4238, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4254, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4256, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4320, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4334, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4348, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4350, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack 
        = (IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                    >> 0x0000000cU) & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U];
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__d_ack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4516, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__d_ack);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__d_ack 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
         & (0x0200U == (0x0e00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U])))) {
        ++(vlSelf->__Vcoverage[4696]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
         & (0U == (0x0e00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U])))) {
        ++(vlSelf->__Vcoverage[4697]);
    }
    if (((0U != (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                       >> 9U))) & (1U != (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                                >> 9U))))) {
        ++(vlSelf->__Vcoverage[4698]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack)))) {
        ++(vlSelf->__Vcoverage[4699]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
         & (0x0800U == (0x0e00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U])))) {
        ++(vlSelf->__Vcoverage[4700]);
    }
    if ((4U != (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                      >> 9U)))) {
        ++(vlSelf->__Vcoverage[4701]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack)))) {
        ++(vlSelf->__Vcoverage[4702]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__a_ack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4514, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__a_ack);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__a_ack 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
           & (0x0800U == (0x0e00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U])));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
           & ((0U == (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                                >> 9U)))));
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1980, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 1982, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 1988, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 1994, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1998, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2014, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2016, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 2080, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 2094, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2108, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2110, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U];
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rd_req))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4686, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rd_req);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rd_req 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wr_req))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4688, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wr_req);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wr_req 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err 
            = (0U != (3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                            >> 0x0000001cU)));
        if ((0x20000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U])) {
            ++(vlSelf->__Vcoverage[4881]);
        }
        if ((0x10000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U])) {
            ++(vlSelf->__Vcoverage[4882]);
        }
        if ((IData)((0U == (0x30000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U])))) {
            ++(vlSelf->__Vcoverage[4883]);
        }
        ++(vlSelf->__Vcoverage[4884]);
    } else {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err = 0U;
        ++(vlSelf->__Vcoverage[4885]);
    }
    ++(vlSelf->__Vcoverage[4886]);
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 899, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 901, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 907, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 913, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 917, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 933, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 935, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 999, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 1013, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1027, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1029, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U]));
    }
    vlSelfRef.gpio_tb__DOT__tl_o[0U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U];
    vlSelfRef.gpio_tb__DOT__tl_o[1U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U];
    vlSelfRef.gpio_tb__DOT__tl_o[2U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U];
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_align_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4654, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_align_err);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_align_err 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err;
    if ((0U != (((vlSelfRef.gpio_tb__DOT__tl_o[0U] 
                  ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[0U]) 
                 | (vlSelfRef.gpio_tb__DOT__tl_o[1U] 
                    ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[1U])) 
                | (vlSelfRef.gpio_tb__DOT__tl_o[2U] 
                   ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[2U])))) {
        VL_COV_TOGGLE_CHG_ST_W(66, vlSelf->__Vcoverage + 502, vlSelfRef.gpio_tb__DOT__tl_o, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[0U] 
            = vlSelfRef.gpio_tb__DOT__tl_o[0U];
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[1U] 
            = vlSelfRef.gpio_tb__DOT__tl_o[1U];
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[2U] 
            = vlSelfRef.gpio_tb__DOT__tl_o[2U];
    }
    vlSelfRef.gpio_tb__DOT__tl_o_d_valid = (1U & (vlSelfRef.gpio_tb__DOT__tl_o[2U] 
                                                  >> 1U));
    vlSelfRef.gpio_tb__DOT__tl_o_d_opcode = (7U & (
                                                   (vlSelfRef.gpio_tb__DOT__tl_o[2U] 
                                                    << 2U) 
                                                   | (vlSelfRef.gpio_tb__DOT__tl_o[1U] 
                                                      >> 0x0000001eU)));
    vlSelfRef.gpio_tb__DOT__tl_o_d_data = ((vlSelfRef.gpio_tb__DOT__tl_o[1U] 
                                            << 0x00000010U) 
                                           | (vlSelfRef.gpio_tb__DOT__tl_o[0U] 
                                              >> 0x00000010U));
    vlSelfRef.gpio_tb__DOT__tl_o_d_error = (1U & (vlSelfRef.gpio_tb__DOT__tl_o[0U] 
                                                  >> 1U));
    vlSelfRef.gpio_tb__DOT__tl_o_a_ready = (1U & vlSelfRef.gpio_tb__DOT__tl_o[0U]);
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)))) {
        ++(vlSelf->__Vcoverage[4703]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal) {
        ++(vlSelf->__Vcoverage[4704]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req)))) {
        ++(vlSelf->__Vcoverage[4705]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)))) {
        ++(vlSelf->__Vcoverage[4706]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal) {
        ++(vlSelf->__Vcoverage[4707]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req)))) {
        ++(vlSelf->__Vcoverage[4708]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__err_internal))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4650, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__err_internal);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__err_internal 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req) 
           & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) 
           & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)));
    if (((IData)(vlSelfRef.gpio_tb__DOT__tl_o_d_valid) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 208, vlSelfRef.gpio_tb__DOT__tl_o_d_valid, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_valid);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_valid 
            = vlSelfRef.gpio_tb__DOT__tl_o_d_valid;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__tl_o_d_opcode) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_opcode)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 210, vlSelfRef.gpio_tb__DOT__tl_o_d_opcode, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_opcode);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_opcode 
            = vlSelfRef.gpio_tb__DOT__tl_o_d_opcode;
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__tl_o_d_data 
                ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_data))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 216, vlSelfRef.gpio_tb__DOT__tl_o_d_data, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_data);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_data 
            = vlSelfRef.gpio_tb__DOT__tl_o_d_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__tl_o_d_error) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 280, vlSelfRef.gpio_tb__DOT__tl_o_d_error, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_error);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_error 
            = vlSelfRef.gpio_tb__DOT__tl_o_d_error;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__tl_o_a_ready) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_a_ready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 282, vlSelfRef.gpio_tb__DOT__tl_o_a_ready, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_a_ready);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_a_ready 
            = vlSelfRef.gpio_tb__DOT__tl_o_a_ready;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__re_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4360, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__re_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__re_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__we_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4362, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__we_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__we_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2198, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_re);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_re 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we) {
        ++(vlSelf->__Vcoverage[2434]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re) {
        ++(vlSelf->__Vcoverage[2435]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re)) 
               & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we))))) {
        ++(vlSelf->__Vcoverage[2436]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2200, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[1U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VicoTriggered[1U]) 
                                         | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
        vlSelfRef.__VicoTriggered[0U] = (QData)((IData)(
                                                        ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re) 
                                                           != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re__0)) 
                                                          << 1U) 
                                                         | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we) 
                                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we__0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we;
        vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re__0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re;
        if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VicoDidInit)))))) {
            vlSelfRef.__VicoDidInit = 1U;
            vlSelfRef.__VicoTriggered[0U] = (1ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (2ULL | vlSelfRef.__VicoTriggered[0U]);
        }
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
            if ((1ULL & vlSelfRef.__VicoTriggered[1U])) {
                Vtop___024root___ico_sequent__TOP__0(vlSelf);
            }
            if (((1ULL & vlSelfRef.__VicoTriggered[1U]) 
                 | (3ULL & vlSelfRef.__VicoTriggered[0U]))) {
                Vtop___024root___ico_comb__TOP__0(vlSelf);
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
    vlSelfRef.__VactTriggered[0U] = (((QData)((IData)(
                                                      ((((((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                            << 3U) 
                                                           | (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni)) 
                                                               & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni__0)) 
                                                              << 2U)) 
                                                          | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i__0))) 
                                                              << 1U) 
                                                             | ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni__0)))) 
                                                         << 0x00000018U) 
                                                        | (((((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i__0))) 
                                                               << 3U) 
                                                              | (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni__0)) 
                                                                 << 2U)) 
                                                             | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i__0))) 
                                                                 << 1U) 
                                                                | ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni)) 
                                                                   & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni__0)))) 
                                                            << 0x00000014U) 
                                                           | ((((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i__0))) 
                                                                 << 3U) 
                                                                | (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni)) 
                                                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni__0)) 
                                                                   << 2U)) 
                                                               | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i__0))) 
                                                                   << 1U) 
                                                                  | ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni)) 
                                                                     & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni__0)))) 
                                                              << 0x00000010U))) 
                                                       | ((((((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__clk_i) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__clk_i__0))) 
                                                               << 3U) 
                                                              | (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni__0)) 
                                                                 << 2U)) 
                                                             | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__clk_i__0))) 
                                                                 << 1U) 
                                                                | ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni)) 
                                                                   & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni__0)))) 
                                                            << 0x0000000cU) 
                                                           | ((((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__clk_i__0))) 
                                                                 << 3U) 
                                                                | (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni)) 
                                                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni__0)) 
                                                                   << 2U)) 
                                                               | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__clk_i) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__clk_i__0))) 
                                                                   << 1U) 
                                                                  | ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni)) 
                                                                     & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni__0)))) 
                                                              << 8U)) 
                                                          | (((((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__clk_i__0))) 
                                                                 << 3U) 
                                                                | (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni)) 
                                                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni__0)) 
                                                                   << 2U)) 
                                                               | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__clk_i) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__clk_i__0))) 
                                                                   << 1U) 
                                                                  | ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni)) 
                                                                     & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni__0)))) 
                                                              << 4U) 
                                                             | (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i__0))) 
                                                                  << 3U) 
                                                                 | (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni)) 
                                                                     & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni__0)) 
                                                                    << 2U)) 
                                                                | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__clk_i) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__clk_i__0))) 
                                                                    << 1U) 
                                                                   | ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni)) 
                                                                      & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni__0))))))))) 
                                      << 0x00000020U) 
                                     | (QData)((IData)(
                                                       ((((((((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__clk_i) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__clk_i__0))) 
                                                               << 3U) 
                                                              | (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni__0)) 
                                                                 << 2U)) 
                                                             | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i__0))) 
                                                                 << 1U) 
                                                                | ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni)) 
                                                                   & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni__0)))) 
                                                            << 0x0000000cU) 
                                                           | ((((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i__0))) 
                                                                 << 3U) 
                                                                | (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni)) 
                                                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni__0)) 
                                                                   << 2U)) 
                                                               | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__clk_i) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__clk_i__0))) 
                                                                   << 1U) 
                                                                  | ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni)) 
                                                                     & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni__0)))) 
                                                              << 8U)) 
                                                          | (((((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i__0))) 
                                                                 << 3U) 
                                                                | (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni)) 
                                                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni__0)) 
                                                                   << 2U)) 
                                                               | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i__0))) 
                                                                   << 1U) 
                                                                  | ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni)) 
                                                                     & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni__0)))) 
                                                              << 4U) 
                                                             | (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__clk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__clk_i__0))) 
                                                                  << 3U) 
                                                                 | (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni)) 
                                                                     & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni__0)) 
                                                                    << 2U)) 
                                                                | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i__0))) 
                                                                    << 1U) 
                                                                   | ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni)) 
                                                                      & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni__0)))))) 
                                                         << 0x00000010U) 
                                                        | ((((((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i__0))) 
                                                                << 3U) 
                                                               | (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni)) 
                                                                   & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni__0)) 
                                                                  << 2U)) 
                                                              | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__clk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__clk_i__0))) 
                                                                  << 1U) 
                                                                 | ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni)) 
                                                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni__0)))) 
                                                             << 0x0000000cU) 
                                                            | ((((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i__0))) 
                                                                  << 3U) 
                                                                 | (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni)) 
                                                                     & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni__0)) 
                                                                    << 2U)) 
                                                                | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i__0))) 
                                                                    << 1U) 
                                                                   | ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni)) 
                                                                      & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni__0)))) 
                                                               << 8U)) 
                                                           | (((((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__clk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__clk_i__0))) 
                                                                  << 3U) 
                                                                 | (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni)) 
                                                                     & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni__0)) 
                                                                    << 2U)) 
                                                                | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i__0))) 
                                                                    << 1U) 
                                                                   | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                                                                      != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree__1)))) 
                                                               << 4U) 
                                                              | (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree) 
                                                                    != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree__1)) 
                                                                   << 3U) 
                                                                  | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                                                                      != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree__1)) 
                                                                     << 2U)) 
                                                                 | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re) 
                                                                      != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re__1)) 
                                                                     << 1U) 
                                                                    | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we) 
                                                                       != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we__1))))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we__1 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re__1 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree__1 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree__1 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree__1 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni__0 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni;
}
