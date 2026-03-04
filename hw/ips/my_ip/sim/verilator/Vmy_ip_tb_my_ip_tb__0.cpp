// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmy_ip_tb.h for the primary calling header

#include "Vmy_ip_tb__pch.h"

VlCoroutine Vmy_ip_tb_my_ip_tb___eval_initial__TOP__my_ip_tb__Vtiming__0(Vmy_ip_tb_my_ip_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vmy_ip_tb_my_ip_tb___eval_initial__TOP__my_ip_tb__Vtiming__0\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__clk_i = 0U;
    while (true) {
        co_await vlSymsp->TOP.__VdlySched.delay(0x0000000000002710ULL, 
                                                nullptr, 
                                                "/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/tb/my_ip_tb.sv", 
                                                37);
        vlSelfRef.__PVT__clk_i = (1U & (~ (IData)(vlSelfRef.__PVT__clk_i)));
    }
}

VlCoroutine Vmy_ip_tb_my_ip_tb___eval_initial__TOP__my_ip_tb__Vtiming__1(Vmy_ip_tb_my_ip_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vmy_ip_tb_my_ip_tb___eval_initial__TOP__my_ip_tb__Vtiming__1\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlClassRef<Vmy_ip_tb___024unit__03a__03atlul_utils> __PVT__tl_utils_inst;
    IData/*31:0*/ __Vtask_tlul_read__2__data;
    __Vtask_tlul_read__2__data = 0;
    // Body
    vlSelfRef.__PVT__error_count = 0U;
    vlSelfRef.__PVT__rst_ni = 0U;
    vlSelfRef.__PVT__tl_i[0U] = 0U;
    vlSelfRef.__PVT__tl_i[1U] = 0U;
    vlSelfRef.__PVT__tl_i[2U] = 0U;
    vlSelfRef.__PVT__tl_i[3U] = 0U;
    vlSelfRef.__PVT__port_i = 0U;
    co_await vlSymsp->TOP.__VdlySched.delay(0x0000000000004e20ULL, 
                                            nullptr, 
                                            "/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/tb/my_ip_tb.sv", 
                                            63);
    vlSymsp->TOP.__Vm_traceActivity[6U] = 1U;
    vlSelfRef.__PVT__rst_ni = 1U;
    co_await vlSymsp->TOP.__VdlySched.delay(0x0000000000004e20ULL, 
                                            nullptr, 
                                            "/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/tb/my_ip_tb.sv", 
                                            65);
    vlSymsp->TOP.__Vm_traceActivity[6U] = 1U;
    VL_WRITEF_NX("\nRunning...\n\n",0);
    __PVT__tl_utils_inst = VL_NEW(Vmy_ip_tb___024unit__03a__03atlul_utils, vlSymsp, (&vlSymsp->TOP__my_ip_tb__tl_if));
    co_await vlSymsp->TOP.__VdlySched.delay(0x0000000000030d40ULL, 
                                            nullptr, 
                                            "/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/tb/my_ip_tb.sv", 
                                            68);
    vlSymsp->TOP.__Vm_traceActivity[6U] = 1U;
    co_await VL_NULL_CHECK(__PVT__tl_utils_inst, "/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/tb/my_ip_tb.sv", 69)->__VnoInFunc_tlul_write(vlSymsp, 0U, 1U, 0U);
    vlSymsp->TOP.__Vm_traceActivity[6U] = 1U;
    co_await vlSymsp->TOP.__VdlySched.delay(0x0000000000030d40ULL, 
                                            nullptr, 
                                            "/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/tb/my_ip_tb.sv", 
                                            70);
    vlSymsp->TOP.__Vm_traceActivity[6U] = 1U;
    co_await VL_NULL_CHECK(__PVT__tl_utils_inst, "/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/tb/my_ip_tb.sv", 71)->__VnoInFunc_tlul_read(vlSymsp, 0U, __Vtask_tlul_read__2__data, 0U);
    vlSymsp->TOP.__Vm_traceActivity[6U] = 1U;
    vlSelfRef.__PVT__rdata = __Vtask_tlul_read__2__data;
    VL_WRITEF_NX("Read data: %x\n",0,32,vlSelfRef.__PVT__rdata);
    co_await vlSymsp->TOP.__VdlySched.delay(0x0000000000030d40ULL, 
                                            nullptr, 
                                            "/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/tb/my_ip_tb.sv", 
                                            73);
    vlSymsp->TOP.__Vm_traceActivity[6U] = 1U;
    if (VL_UNLIKELY(((0U == vlSelfRef.__PVT__error_count)))) {
        VL_WRITEF_NX("Coverage: 100%%\n",0);
    }
    VL_WRITEF_NX("\nEnd.\n\n",0);
    VL_FINISH_MT("/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/tb/my_ip_tb.sv", 77, "");
    vlSymsp->TOP.__Vm_traceActivity[6U] = 1U;
}

void Vmy_ip_tb_my_ip_tb___ico_comb__TOP__my_ip_tb__0(Vmy_ip_tb_my_ip_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vmy_ip_tb_my_ip_tb___ico_comb__TOP__my_ip_tb__0\n"); );
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

void Vmy_ip_tb_my_ip_tb___act_sequent__TOP__my_ip_tb__0(Vmy_ip_tb_my_ip_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vmy_ip_tb_my_ip_tb___act_sequent__TOP__my_ip_tb__0\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__my_ip_tb__tl_if.__PVT__clk_i = vlSelfRef.__PVT__clk_i;
    vlSymsp->TOP.__VvifTrigger_h100a9949__0_Vtrigm___PVT__clk_i = 1U;
}

void Vmy_ip_tb_my_ip_tb___nba_comb__TOP__my_ip_tb__0(Vmy_ip_tb_my_ip_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vmy_ip_tb_my_ip_tb___nba_comb__TOP__my_ip_tb__0\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
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
}

void Vmy_ip_tb_my_ip_tb___nba_sequent__TOP__my_ip_tb__1(Vmy_ip_tb_my_ip_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vmy_ip_tb_my_ip_tb___nba_sequent__TOP__my_ip_tb__1\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe 
        = ((IData)(vlSelfRef.__PVT__rst_ni) && (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_wdata0_qe__DOT__d_i));
    if (vlSelfRef.__PVT__rst_ni) {
        if (vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_wdata0_qe__DOT__d_i) {
            vlSelfRef.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_wdata__q 
                = ((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_wdata0_qe__DOT__d_i)
                    ? (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                       >> 0x00000018U) : 0U);
        }
        if (vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we) {
            if (vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we) {
                vlSelfRef.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q 
                    = (1U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                             >> 0x00000018U));
                vlSelfRef.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q 
                    = (1U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                             >> 0x00000019U));
                vlSelfRef.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_setting__q 
                    = (0x0000ffffU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                      >> 8U));
            } else {
                vlSelfRef.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q = 0U;
                vlSelfRef.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q = 0U;
                vlSelfRef.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_setting__q = 0U;
            }
        }
        if (vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack) {
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q 
                = (0x000000ffU & ((vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                   << 4U) | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[2U] 
                                             >> 0x0000001cU)));
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q 
                = (3U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                         >> 4U));
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rspop_q 
                = ((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rd_req)
                    ? 1U : 0U);
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q 
                = ((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i) 
                   | (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal));
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q 
                = ((((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i) 
                     | (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal)) 
                    | (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req))
                    ? 0xffffffffU : vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next);
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q = 1U;
        } else if (vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__d_ack) {
            vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q = 0U;
        }
    } else {
        vlSelfRef.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_wdata__q = 0U;
        vlSelfRef.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q = 0U;
        vlSelfRef.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q = 0U;
        vlSelfRef.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_setting__q = 0U;
        vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q = 0U;
        vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q = 0U;
        vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rspop_q = 0U;
        vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q = 0U;
        vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q = 0U;
        vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q = 0U;
    }
    vlSelfRef.__PVT__port_o = ((IData)(vlSelfRef.__PVT__rst_ni) 
                               && (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_core__DOT__u_sync_name__DOT__intq));
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_core__DOT__u_sync_name__DOT__intq 
        = ((IData)(vlSelfRef.__PVT__rst_ni) && (IData)(vlSelfRef.__PVT__port_i));
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
}

void Vmy_ip_tb_my_ip_tb___nba_comb__TOP__my_ip_tb__1(Vmy_ip_tb_my_ip_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vmy_ip_tb_my_ip_tb___nba_comb__TOP__my_ip_tb__1\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ u_my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7;
    u_my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7 = 0;
    // Body
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
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__d_ack 
        = ((IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q) 
           & vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U]);
    vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack 
        = ((~ (IData)(vlSelfRef.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)) 
           & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
              >> 0x0000000cU));
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
