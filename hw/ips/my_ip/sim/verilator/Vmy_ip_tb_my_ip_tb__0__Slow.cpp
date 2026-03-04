// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmy_ip_tb.h for the primary calling header

#include "Vmy_ip_tb__pch.h"

VL_ATTR_COLD void Vmy_ip_tb_my_ip_tb___eval_initial__TOP__my_ip_tb(Vmy_ip_tb_my_ip_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vmy_ip_tb_my_ip_tb___eval_initial__TOP__my_ip_tb\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/sim/my_ip_tb.vcd"s);
    vlSymsp->_traceDumpOpen();
}

VL_ATTR_COLD void Vmy_ip_tb_my_ip_tb___stl_sequent__TOP__my_ip_tb__0(Vmy_ip_tb_my_ip_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vmy_ip_tb_my_ip_tb___stl_sequent__TOP__my_ip_tb__0\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ u_my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7;
    u_my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7 = 0;
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
    CData/*0:0*/ __Vfunc_mubi4_test_invalid__9__Vfuncout;
    __Vfunc_mubi4_test_invalid__9__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_mubi4_test_invalid__9__val;
    __Vfunc_mubi4_test_invalid__9__val = 0;
    // Body
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__d_ack 
        = ((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q) 
           & vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U]);
    vlSymsp->TOP__my_ip_tb__tl_if.__PVT__clk_i = vlSelfRef.__PVT__clk_i;
    vlSymsp->TOP.__VvifTrigger_h100a9949__0_Vtrigm___PVT__clk_i = 1U;
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err 
        = (([&]() {
                vlSelfRef.__Vfunc_mubi4_test_true_strict__8__val 
                    = (0x0000000fU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                      >> 0x0000000fU));
                vlSelfRef.__Vfunc_mubi4_test_true_strict__8__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__8__val));
            }(), (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__8__Vfuncout)) 
           & ((0U == (7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                >> 9U)))));
    __Vfunc_mubi4_test_invalid__9__val = (0x0000000fU 
                                          & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                             >> 0x0000000fU));
    __Vfunc_mubi4_test_invalid__9__Vfuncout = (1U & 
                                               (~ (
                                                   (6U 
                                                    == (IData)(__Vfunc_mubi4_test_invalid__9__val)) 
                                                   | (9U 
                                                      == (IData)(__Vfunc_mubi4_test_invalid__9__val)))));
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err 
        = __Vfunc_mubi4_test_invalid__9__Vfuncout;
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk = 0U;
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk = 0U;
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk = 0U;
    if ((0x00001000U & vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U])) {
        if ((0U == (3U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                          >> 4U)))) {
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk = 1U;
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk 
                = (1U & (~ (0U != (0x0000000fU & ((
                                                   (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                    << 8U) 
                                                   | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                      >> 0x00000018U)) 
                                                  & (~ 
                                                     ((IData)(1U) 
                                                      << 
                                                      (3U 
                                                       & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                          >> 0x0000001cU)))))))));
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk 
                = (0U != (0x0000000fU & (((vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                           << 8U) | 
                                          (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                           >> 0x00000018U)) 
                                         & ((IData)(1U) 
                                            << (3U 
                                                & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                   >> 0x0000001cU))))));
        } else if ((1U == (3U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                 >> 4U)))) {
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk 
                = (1U & (~ (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                            >> 0x0000001cU)));
            if ((0x20000000U & vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U])) {
                vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk 
                    = (1U & (~ (0U != (3U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                             >> 0x00000018U)))));
                vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk 
                    = (3U == (3U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                    >> 0x0000001aU)));
            } else {
                vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk 
                    = (1U & (~ (0U != (0x0cU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                >> 0x00000018U)))));
                vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk 
                    = (3U == (3U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                    >> 0x00000018U)));
            }
        } else if ((2U == (3U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                 >> 4U)))) {
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk 
                = (1U & (~ (0U != (3U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                         >> 0x0000001cU)))));
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk = 1U;
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk 
                = (0x0000000fU == (0x0000000fU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                  >> 0x00000018U)));
        } else {
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk = 0U;
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk = 0U;
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk = 0U;
        }
        if ((1U & (~ VL_ONEHOT_I((((2U == (3U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                 >> 4U))) 
                                   << 2U) | (((1U == 
                                               (3U 
                                                & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                   >> 4U))) 
                                              << 1U) 
                                             | (0U 
                                                == 
                                                (3U 
                                                 & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                    >> 4U))))))))) {
            if ((0U != (((2U == (3U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                       >> 4U))) << 2U) 
                        | (((1U == (3U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                          >> 4U))) 
                            << 1U) | (0U == (3U & (
                                                   vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                   >> 4U))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: tlul_err.sv:62: Assertion failed in %Nmy_ip_tb.u_my_ip.u_my_ip_reg.u_reg_if.u_err: unique case, but multiple matches found for '32'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 32,(3U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                           >> 4U)));
                    VL_STOP_MT("/home/eneadim/github/flexsoc/hw/ips/tlul/tlul_err.sv", 62, "");
                }
            }
        }
    } else {
        vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk = 0U;
        vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk = 0U;
        vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk = 0U;
    }
    vlSymsp->TOP__my_ip_tb__tl_if.d2h[0U] = (IData)(
                                                    (((QData)((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                                      << 0x00000039U) 
                                                     | (((QData)((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                         << 0x00000031U) 
                                                        | (((QData)((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                            << 0x00000010U) 
                                                           | (QData)((IData)(
                                                                             (((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                               << 1U) 
                                                                              | (1U 
                                                                                & (~ (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q))))))))));
    vlSymsp->TOP__my_ip_tb__tl_if.d2h[1U] = ((0xc0000000U 
                                              & vlSymsp->TOP__my_ip_tb__tl_if.d2h[1U]) 
                                             | (IData)(
                                                       ((((QData)((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                                          << 0x00000039U) 
                                                         | (((QData)((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                             << 0x00000031U) 
                                                            | (((QData)((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                                << 0x00000010U) 
                                                               | (QData)((IData)(
                                                                                (((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                                << 1U) 
                                                                                | (1U 
                                                                                & (~ (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q))))))))) 
                                                        >> 0x00000020U)));
    vlSymsp->TOP__my_ip_tb__tl_if.d2h[1U] = ((0x3fffffffU 
                                              & vlSymsp->TOP__my_ip_tb__tl_if.d2h[1U]) 
                                             | ((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rspop_q) 
                                                << 0x0000001eU));
    vlSymsp->TOP__my_ip_tb__tl_if.d2h[2U] = (3U & (
                                                   (0x3ffffffeU 
                                                    & ((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q) 
                                                       << 1U)) 
                                                   | ((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rspop_q) 
                                                      >> 2U)));
    vlSymsp->TOP.__VvifTrigger_h100a9949__1_Vtrigm_d2h = 1U;
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__instr_error 
        = (([&]() {
                vlSelfRef.__Vfunc_mubi4_test_invalid__3__val 
                    = (0x0000000fU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                      >> 0x0000000fU));
                vlSelfRef.__Vfunc_mubi4_test_invalid__3__Vfuncout 
                    = (1U & (~ ((6U == (IData)(vlSelfRef.__Vfunc_mubi4_test_invalid__3__val)) 
                                | (9U == (IData)(vlSelfRef.__Vfunc_mubi4_test_invalid__3__val)))));
            }(), (IData)(vlSelfRef.__Vfunc_mubi4_test_invalid__3__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_mubi4_test_true_strict__4__val 
                    = (0x0000000fU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                      >> 0x0000000fU));
                vlSelfRef.__Vfunc_mubi4_test_true_strict__4__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__4__val));
            }(), (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__4__Vfuncout)));
    __Vfunc_tl_a_user_chk__6__user = (0x007fffffU & 
                                      (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
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
    __Vfunc_tl_a_user_chk__6__malformed_err = __Vfunc_mubi4_test_invalid__7__Vfuncout;
    __Vfunc_tl_a_user_chk__6__Vfuncout = __Vfunc_tl_a_user_chk__6__malformed_err;
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__malformed_meta_err 
        = __Vfunc_tl_a_user_chk__6__Vfuncout;
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__addr_hit 
        = ((((3U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                     >> 0x0000001eU)) << 3U) | ((2U 
                                                 == 
                                                 (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                  >> 0x0000001eU)) 
                                                << 2U)) 
           | (((1U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                       >> 0x0000001eU)) << 1U) | (0U 
                                                  == 
                                                  (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                   >> 0x0000001eU))));
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack 
        = ((~ (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)) 
           & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
              >> 0x0000000cU));
    if ((1U & (~ VL_ONEHOT_I((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__addr_hit))))) {
        if ((0U != (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__addr_hit))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: my_ip_reg_top.sv:319: Assertion failed in %Nmy_ip_tb.u_my_ip.u_my_ip_reg: unique case, but multiple matches found for '1'h1'\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name());
                VL_STOP_MT("/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/rtl/my_ip_reg_top.sv", 319, "");
            }
        }
    }
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next = 0U;
    if ((1U & (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__addr_hit))) {
        vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next 
            = ((0xfffffffcU & vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q) 
                   << 1U) | (IData)(vlSelfRef.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q)));
        vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next 
            = ((0x0000ffffU & vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next) 
               | ((IData)(vlSelfRef.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_setting__q) 
                  << 0x00000010U));
    } else {
        vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next 
            = ((2U & (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__addr_hit))
                ? ((0xfffffffcU & vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next) 
                   | (((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_core__DOT__status_empty) 
                       << 1U) | (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_core__DOT__status_full)))
                : ((4U & (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__addr_hit))
                    ? ((0xffffff00U & vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next) 
                       | (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_core__DOT__rdata))
                    : ((8U & (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__addr_hit))
                        ? (0xffffff00U & vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next)
                        : 0xffffffffU)));
    }
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rd_req 
        = ((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack) 
           & (0x0800U == (0x0e00U & vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U])));
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req 
        = ((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack) 
           & ((0U == (7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                >> 9U)))));
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal 
        = ((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req) 
           & (0U != (3U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                           >> 0x0000001cU))));
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o 
        = ((~ (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rd_req));
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o 
        = ((~ (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req));
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i 
        = (((~ (0U != (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__addr_hit))) 
            & ((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o) 
               | (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o))) 
           | ((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o) 
              & (((0U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                          >> 0x0000001eU)) & (0U != 
                                              (0x0000000fU 
                                               & (~ 
                                                  ((vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                    << 8U) 
                                                   | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                      >> 0x00000018U)))))) 
                 | ((0U != (1U & (~ ((vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                      << 8U) | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                >> 0x00000018U))))) 
                    & ((1U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                               >> 0x0000001eU)) | (
                                                   (2U 
                                                    == 
                                                    (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                     >> 0x0000001eU)) 
                                                   | (3U 
                                                      == 
                                                      (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                       >> 0x0000001eU))))))));
    u_my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7 
        = ((~ (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
           & (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o));
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we 
        = ((0U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                   >> 0x0000001eU)) & (IData)(u_my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7));
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_wdata0_qe__DOT__d_i 
        = ((3U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                   >> 0x0000001eU)) & (IData)(u_my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7));
}

VL_ATTR_COLD void Vmy_ip_tb_my_ip_tb___ctor_var_reset(Vmy_ip_tb_my_ip_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vmy_ip_tb_my_ip_tb___ctor_var_reset\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->__PVT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11908517815223722933ull);
    vlSelf->__PVT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3161515032326629241ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->__PVT__tl_i, __VscopeHash, 717864233454436411ull);
    vlSelf->__PVT__port_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 313071210505319004ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->__PVT__tl_o, __VscopeHash, 14475261017617439938ull);
    vlSelf->__PVT__port_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5055776756475145770ull);
    vlSelf->__PVT__error_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1309902949917203758ull);
    vlSelf->__PVT__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10065165116613087284ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5284052613844625815ull);
    vlSelf->u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q = 0;
    vlSelf->u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q = 0;
    vlSelf->u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_setting__q = 0;
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11908215068332467597ull);
    vlSelf->u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_wdata__q = 0;
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__addr_hit = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 748630745741158958ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11898800959143372271ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12094072439087850275ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10703209180048213189ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 456909554786089240ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16301921264010618114ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__d_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2080486100710150601ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16028904277031829577ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15336501834781355457ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18308130631457107821ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__instr_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1802908335918682628ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__malformed_meta_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9250916404506056595ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13368522450371813535ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14144207340756228571ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rspop_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9529516056544775060ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rd_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14425336365055215001ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15785859277197564885ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3940621119329812427ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4135335539834549137ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7951288538626761586ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6762997301304925215ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5577934247658676982ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1258219461415040873ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_wdata0_qe__DOT__d_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1352191586748735856ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_core__DOT__status_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2497052706383881505ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_core__DOT__status_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13846998542631862777ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_core__DOT__rdata = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2834706400821838943ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_core__DOT__u_sync_name__DOT__d_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14133207308844455655ull);
    vlSelf->__PVT__u_my_ip__DOT__u_my_ip_core__DOT__u_sync_name__DOT__intq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1686606358764050626ull);
    vlSelf->__Vfunc_mubi4_test_invalid__3__Vfuncout = 0;
    vlSelf->__Vfunc_mubi4_test_invalid__3__val = 0;
    vlSelf->__Vfunc_mubi4_test_true_strict__4__Vfuncout = 0;
    vlSelf->__Vfunc_mubi4_test_true_strict__4__val = 0;
    vlSelf->__Vfunc_mubi4_test_true_strict__8__Vfuncout = 0;
    vlSelf->__Vfunc_mubi4_test_true_strict__8__val = 0;
}
