// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_host_tb.h for the primary calling header

#include "Vspi_host_tb__pch.h"
#include "Vspi_host_tb__Syms.h"
#include "Vspi_host_tb_spi_host_tb.h"

VL_INLINE_OPT VlCoroutine Vspi_host_tb_spi_host_tb___eval_initial__TOP__spi_host_tb__Vtiming__0(Vspi_host_tb_spi_host_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vspi_host_tb_spi_host_tb___eval_initial__TOP__spi_host_tb__Vtiming__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__clk_i = 0U;
    while (1U) {
        co_await vlSymsp->TOP.__VdlySched.delay(0x1388ULL, 
                                                nullptr, 
                                                "tb/spi_host_tb.sv", 
                                                51);
        vlSelfRef.__PVT__clk_i = (1U & (~ (IData)(vlSelfRef.__PVT__clk_i)));
    }
}

VL_INLINE_OPT void Vspi_host_tb_spi_host_tb___ico_comb__TOP__spi_host_tb__0(Vspi_host_tb_spi_host_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vspi_host_tb_spi_host_tb___ico_comb__TOP__spi_host_tb__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__Vfuncout;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__Vfuncout = 0;
    IData/*22:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__user;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__user = 0;
    CData/*0:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__malformed_err;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__malformed_err = 0;
    CData/*0:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__Vfuncout;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__val;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__val = 0;
    CData/*0:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__Vfuncout;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__val;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__val = 0;
    // Body
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk 
        = ((1U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                  >> 0xcU)) && ((0U == (3U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                              >> 4U))) 
                                || (1U & ((1U == (3U 
                                                  & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                     >> 4U)))
                                           ? (~ (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                 >> 0x1cU))
                                           : ((2U == 
                                               (3U 
                                                & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                   >> 4U))) 
                                              && (1U 
                                                  & (~ (IData)(
                                                               (0U 
                                                                != 
                                                                (3U 
                                                                 & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                                    >> 0x1cU)))))))))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk 
        = ((1U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                  >> 0xcU)) && (1U & ((0U == (3U & 
                                              (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                               >> 4U)))
                                       ? (~ (IData)(
                                                    (0U 
                                                     != 
                                                     (0xfU 
                                                      & (((vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                           << 8U) 
                                                          | (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                             >> 0x18U)) 
                                                         & (~ 
                                                            ((IData)(1U) 
                                                             << 
                                                             (3U 
                                                              & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                                 >> 0x1cU)))))))))
                                       : ((1U == (3U 
                                                  & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                     >> 4U)))
                                           ? ((0x20000000U 
                                               & vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U])
                                               ? (~ (IData)(
                                                            (0U 
                                                             != 
                                                             (3U 
                                                              & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                                 >> 0x18U)))))
                                               : (~ (IData)(
                                                            (0U 
                                                             != 
                                                             (0xcU 
                                                              & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                                 >> 0x18U))))))
                                           : (2U == 
                                              (3U & 
                                               (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                >> 4U)))))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk 
        = ((1U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                  >> 0xcU)) && ((0U == (3U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                              >> 4U)))
                                 ? (0U != (0xfU & (
                                                   ((vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                     << 8U) 
                                                    | (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                       >> 0x18U)) 
                                                   & ((IData)(1U) 
                                                      << 
                                                      (3U 
                                                       & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                          >> 0x1cU))))))
                                 : ((1U == (3U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                  >> 4U)))
                                     ? ((0x20000000U 
                                         & vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U])
                                         ? (3U == (3U 
                                                   & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                      >> 0x1aU)))
                                         : (3U == (3U 
                                                   & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                      >> 0x18U))))
                                     : ((2U == (3U 
                                                & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                   >> 4U))) 
                                        && (0xfU == 
                                            (0xfU & 
                                             (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                              >> 0x18U)))))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err 
        = (([&]() {
                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__46__val 
                    = (0xfU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                               >> 0xfU));
                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__46__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__46__val));
            }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__46__Vfuncout)) 
           & ((0U == (7U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                >> 9U)))));
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__val 
        = (0xfU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                   >> 0xfU));
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__Vfuncout 
        = (1U & (~ ((6U == (IData)(__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__val)) 
                    | (9U == (IData)(__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__val)))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err 
        = __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__Vfuncout;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__user 
        = (0x7fffffU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                        >> 1U));
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__val 
        = (0xfU & (__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__user 
                   >> 0xeU));
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__Vfuncout 
        = (1U & (~ ((6U == (IData)(__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__val)) 
                    | (9U == (IData)(__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__val)))));
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__malformed_err 
        = __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__Vfuncout;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__Vfuncout 
        = __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__malformed_err;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__malformed_meta_err 
        = __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__Vfuncout;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__instr_error 
        = (([&]() {
                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__11__val 
                    = (0xfU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                               >> 0xfU));
                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__11__Vfuncout 
                    = (1U & (~ ((6U == (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__11__val)) 
                                | (9U == (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__11__val)))));
            }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__11__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_true_strict__26__val 
                    = (0xfU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                               >> 0xfU));
                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_true_strict__26__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_true_strict__26__val));
            }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_true_strict__26__Vfuncout)));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit = 0U;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit 
        = ((8U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit)) 
           | (((8U == (0xcU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                               >> 0x1cU))) << 2U) | 
              (((4U == (0xcU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                >> 0x1cU))) << 1U) 
               | (0U == (0xcU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                 >> 0x1cU))))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit 
        = ((7U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit)) 
           | ((0xcU == (0xcU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                >> 0x1cU))) << 3U));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__a_ack 
        = (IData)(((vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                    >> 0xcU) & vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre[0U]));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next = 0U;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next 
        = ((1U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit))
            ? ((0xfffffff8U & vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_rxrst__q) 
                   << 2U) | (((IData)(vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_txrst__q) 
                              << 1U) | (IData)(vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q))))
            : ((2U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit))
                ? ((0xfffffff0U & vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next) 
                   | (((8U & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_rvalid)) 
                              << 3U)) | (4U & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wready)) 
                                               << 2U))) 
                      | ((2U & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid)) 
                                << 1U)) | (1U & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready))))))
                : ((4U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit))
                    ? ((0xffffff00U & vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next) 
                       | ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
                           ? 0U : ((0x17U >= (0x1fU 
                                              & VL_SHIFTL_III(5,5,32, 
                                                              (3U 
                                                               & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U)))
                                    ? (0xffU & (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__storage 
                                                >> 
                                                (0x1fU 
                                                 & VL_SHIFTL_III(5,5,32, 
                                                                 (3U 
                                                                  & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U))))
                                    : 0U))) : ((8U 
                                                & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit))
                                                ? (0xffffff00U 
                                                   & vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next)
                                                : 0xffffffffU))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rd_req 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__a_ack) 
           & (0x800U == (0xe00U & vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U])));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__wr_req 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__a_ack) 
           & ((0U == (7U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                >> 9U)))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__wr_req) 
           & (0U != (3U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                           >> 0x1cU))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_re 
        = ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rd_req));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_we 
        = ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__wr_req));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error 
        = (((~ (IData)((0U != (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit)))) 
            & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_re) 
               | (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_we))) 
           | ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_we) 
              & ((IData)((0U != (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit))) 
                 & (0U != (1U & (~ ((vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                     << 8U) | (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                               >> 0x18U))))))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_rvalid) 
           & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
                  >> 2U) & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error)) 
                            & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_re)))));
    vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____VdfgRegularize_h533b1fce_2_6 
        = ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error)) 
           & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_we));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (2U == (3U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
           & (IData)(vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____VdfgRegularize_h533b1fce_2_6));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_wdata__DOT__wr_en 
        = (((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
            >> 3U) & (IData)(vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____VdfgRegularize_h533b1fce_2_6));
}

VL_INLINE_OPT void Vspi_host_tb_spi_host_tb___act_sequent__TOP__spi_host_tb__0(Vspi_host_tb_spi_host_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vspi_host_tb_spi_host_tb___act_sequent__TOP__spi_host_tb__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__spi_host_tb__tl_if.__PVT__clk_i = vlSelfRef.__PVT__clk_i;
    vlSymsp->TOP.__VvifTrigger_h100a9299__0 = 1U;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
        = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_q;
    if ((0U == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        if ((((IData)(vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q) 
              & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__wdata_qe)) 
             & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready))) {
            if ((2U == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
                vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                    = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rdata;
            }
        }
    } else if ((1U == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        if ((1U < (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
            if ((8U > (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                if ((1U & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk)))) {
                    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                        = (0xfeU & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_q) 
                                    << 1U));
                }
            } else if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid) {
                vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                    = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rdata;
            }
        } else if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__r_wn_q) {
            if ((8U > (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk) {
                    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                        = ((0xfeU & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_q) 
                                     << 1U)) | (IData)(vlSelfRef.__PVT__spi_sdio_i));
                }
            } else {
                vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                    = ((0xfeU & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_q) 
                                 << 1U)) | (IData)(vlSelfRef.__PVT__spi_sdio_i));
            }
        } else if ((8U > (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk)))) {
                vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                    = (0xfeU & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_q) 
                                << 1U));
            }
        } else if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid) {
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rdata;
        }
    }
}

VL_INLINE_OPT void Vspi_host_tb_spi_host_tb___nba_sequent__TOP__spi_host_tb__0(Vspi_host_tb_spi_host_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vspi_host_tb_spi_host_tb___nba_sequent__TOP__spi_host_tb__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*2:0*/ __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    vlSelfRef.__Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    if (vlSelfRef.__PVT__rst_ni) {
        if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_rxrst__q) {
            vlSelfRef.__Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
            __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        } else {
            if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
                vlSelfRef.__Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                    = (4U & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                             << 2U));
            } else if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
                vlSelfRef.__Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
            }
            if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
                __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                    = (4U & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                             << 2U));
            } else if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
                __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
            }
        }
        if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_txrst__q) {
            vlSelfRef.__Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
            __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        } else {
            if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
                vlSelfRef.__Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                    = (4U & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                             << 2U));
            } else if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
                vlSelfRef.__Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
            }
            if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
                __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                    = (4U & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                             << 2U));
            } else if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
                __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
            }
        }
        if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en) {
            vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q 
                = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en) 
                   & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                      >> 0x18U));
            vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_rxrst__q 
                = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en) 
                   & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                      >> 0x1aU));
            vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_txrst__q 
                = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en) 
                   & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                      >> 0x19U));
        }
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q 
            = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d;
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q 
            = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_d;
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state 
            = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__next_state;
        if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__a_ack) {
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__reqid_q 
                = (0xffU & ((vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                             << 4U) | (vlSymsp->TOP__spi_host_tb__tl_if.h2d[2U] 
                                       >> 0x1cU)));
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__reqsz_q 
                = (3U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                         >> 4U));
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rspop_q 
                = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rd_req)
                    ? 1U : 0U);
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__error_q 
                = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error) 
                   | (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal));
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__outstanding_q = 1U;
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rdata_q 
                = ((((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error) 
                     | (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal)) 
                    | (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__wr_req))
                    ? 0xffffffffU : vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next);
        } else if ((IData)(((vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
                             >> 1U) & vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U]))) {
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__outstanding_q = 0U;
        }
    } else {
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        vlSelfRef.__Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        vlSelfRef.__Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q = 0U;
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q = 0U;
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q = 0U;
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state = 0U;
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__reqid_q = 0U;
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__reqsz_q = 0U;
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rspop_q = 0U;
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__error_q = 0U;
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__outstanding_q = 0U;
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rdata_q = 0U;
        vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_rxrst__q = 0U;
        vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_txrst__q = 0U;
    }
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdioz_q 
        = ((IData)(vlSelfRef.__PVT__rst_ni) && (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdioz_d));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wvalid_q 
        = ((IData)(vlSelfRef.__PVT__rst_ni) && (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wvalid_d));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdio_q 
        = ((IData)(vlSelfRef.__PVT__rst_ni) && (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdio_d));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_q 
        = ((IData)(vlSelfRef.__PVT__rst_ni) && (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_d));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__wdata_qe 
        = ((IData)(vlSelfRef.__PVT__rst_ni) & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_wdata__DOT__wr_en));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__r_wn_q 
        = ((IData)(vlSelfRef.__PVT__rst_ni) && (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__r_wn_d));
    vlSelfRef.__PVT__spi_sclk_o = ((IData)(vlSelfRef.__PVT__rst_ni) 
                                   & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__cs_q)) 
                                      & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk)));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 2U));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 2U));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdioz_d = 0U;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wvalid_d = 0U;
    if ((0U != (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        if ((1U == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state))) {
            if ((1U >= (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
                if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__r_wn_q) {
                    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdioz_d = 1U;
                    if ((8U <= (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wvalid_d = 1U;
                    }
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state))) {
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdioz_d = 0U;
        }
    }
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__cs_q 
        = ((1U & (~ (IData)(vlSelfRef.__PVT__rst_ni))) 
           || (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__cs_d));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk 
        = ((IData)(vlSelfRef.__PVT__rst_ni) & (IData)(vlSelfRef.u_spi_host__DOT__u_spi_host_core__DOT____Vcellinp__u_clk_div2__d_i));
    VL_CONCAT_WQI(66,64,2, vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre, 
                  (((QData)((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__outstanding_q)) 
                    << 0x3fU) | (((QData)((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rspop_q)) 
                                  << 0x3cU) | VL_EXTEND_QQ(60,57, 
                                                           (((QData)((IData)(
                                                                             ([&]() {
                                            vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_FDEB5__5__inp 
                                                = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__reqsz_q;
                                            vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_FDEB5__5__Vfuncout 
                                                = vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_FDEB5__5__inp;
                                        }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_FDEB5__5__Vfuncout)))) 
                                                             << 0x37U) 
                                                            | (((QData)((IData)(
                                                                                ([&]() {
                                                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_15E34__6__inp 
                                                    = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__reqid_q;
                                                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_15E34__6__Vfuncout 
                                                    = vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_15E34__6__inp;
                                            }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_15E34__6__Vfuncout)))) 
                                                                << 0x2fU) 
                                                               | VL_EXTEND_QQ(47,46, 
                                                                              ((QData)((IData)(
                                                                                ([&]() {
                                                    vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_9783B__8__inp 
                                                        = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rdata_q;
                                                    vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_9783B__8__Vfuncout 
                                                        = vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_9783B__8__inp;
                                                }(), vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_9783B__8__Vfuncout))) 
                                                                               << 0xeU))))))), 
                  (((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__error_q) 
                    << 1U) | ([&]() {
                    vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_1__10__inp 
                        = (1U & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__outstanding_q)));
                    vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_1__10__Vfuncout 
                        = vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_1__10__inp;
                }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_1__10__Vfuncout))));
    vlSymsp->TOP__spi_host_tb__tl_if.d2h[0U] = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre[0U];
    vlSymsp->TOP__spi_host_tb__tl_if.d2h[1U] = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre[1U];
    vlSymsp->TOP__spi_host_tb__tl_if.d2h[2U] = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre[2U];
    vlSymsp->TOP.__VvifTrigger_h100a9299__0 = 1U;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__cs_d 
        = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__cs_q;
    if ((0U == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__cs_d = 1U;
    } else if ((1U == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__cs_d = 0U;
    } else if ((2U == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__cs_d = 1U;
    }
}

VL_INLINE_OPT void Vspi_host_tb_spi_host_tb___nba_sequent__TOP__spi_host_tb__1(Vspi_host_tb_spi_host_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vspi_host_tb_spi_host_tb___nba_sequent__TOP__spi_host_tb__1\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__Vfuncout;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__Vfuncout = 0;
    IData/*22:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__user;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__user = 0;
    CData/*0:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__malformed_err;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__malformed_err = 0;
    CData/*0:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__Vfuncout;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__val;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__val = 0;
    CData/*0:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__Vfuncout;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__val;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__val = 0;
    // Body
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk 
        = ((1U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                  >> 0xcU)) && ((0U == (3U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                              >> 4U))) 
                                || (1U & ((1U == (3U 
                                                  & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                     >> 4U)))
                                           ? (~ (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                 >> 0x1cU))
                                           : ((2U == 
                                               (3U 
                                                & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                   >> 4U))) 
                                              && (1U 
                                                  & (~ (IData)(
                                                               (0U 
                                                                != 
                                                                (3U 
                                                                 & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                                    >> 0x1cU)))))))))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk 
        = ((1U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                  >> 0xcU)) && (1U & ((0U == (3U & 
                                              (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                               >> 4U)))
                                       ? (~ (IData)(
                                                    (0U 
                                                     != 
                                                     (0xfU 
                                                      & (((vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                           << 8U) 
                                                          | (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                             >> 0x18U)) 
                                                         & (~ 
                                                            ((IData)(1U) 
                                                             << 
                                                             (3U 
                                                              & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                                 >> 0x1cU)))))))))
                                       : ((1U == (3U 
                                                  & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                     >> 4U)))
                                           ? ((0x20000000U 
                                               & vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U])
                                               ? (~ (IData)(
                                                            (0U 
                                                             != 
                                                             (3U 
                                                              & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                                 >> 0x18U)))))
                                               : (~ (IData)(
                                                            (0U 
                                                             != 
                                                             (0xcU 
                                                              & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                                 >> 0x18U))))))
                                           : (2U == 
                                              (3U & 
                                               (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                >> 4U)))))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk 
        = ((1U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                  >> 0xcU)) && ((0U == (3U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                              >> 4U)))
                                 ? (0U != (0xfU & (
                                                   ((vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                     << 8U) 
                                                    | (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                       >> 0x18U)) 
                                                   & ((IData)(1U) 
                                                      << 
                                                      (3U 
                                                       & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                          >> 0x1cU))))))
                                 : ((1U == (3U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                  >> 4U)))
                                     ? ((0x20000000U 
                                         & vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U])
                                         ? (3U == (3U 
                                                   & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                      >> 0x1aU)))
                                         : (3U == (3U 
                                                   & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                      >> 0x18U))))
                                     : ((2U == (3U 
                                                & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                   >> 4U))) 
                                        && (0xfU == 
                                            (0xfU & 
                                             (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                              >> 0x18U)))))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err 
        = (([&]() {
                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__46__val 
                    = (0xfU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                               >> 0xfU));
                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__46__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__46__val));
            }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__46__Vfuncout)) 
           & ((0U == (7U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                >> 9U)))));
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__val 
        = (0xfU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                   >> 0xfU));
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__Vfuncout 
        = (1U & (~ ((6U == (IData)(__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__val)) 
                    | (9U == (IData)(__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__val)))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err 
        = __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__48__Vfuncout;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__user 
        = (0x7fffffU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                        >> 1U));
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__val 
        = (0xfU & (__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__user 
                   >> 0xeU));
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__Vfuncout 
        = (1U & (~ ((6U == (IData)(__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__val)) 
                    | (9U == (IData)(__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__val)))));
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__malformed_err 
        = __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__31__Vfuncout;
    __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__Vfuncout 
        = __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__malformed_err;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__malformed_meta_err 
        = __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tlul_pkg_tl_a_user_chk__30__Vfuncout;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__instr_error 
        = (([&]() {
                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__11__val 
                    = (0xfU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                               >> 0xfU));
                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__11__Vfuncout 
                    = (1U & (~ ((6U == (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__11__val)) 
                                | (9U == (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__11__val)))));
            }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__11__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_true_strict__26__val 
                    = (0xfU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                               >> 0xfU));
                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_true_strict__26__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_true_strict__26__val));
            }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_true_strict__26__Vfuncout)));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit = 0U;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit 
        = ((8U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit)) 
           | (((8U == (0xcU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                               >> 0x1cU))) << 2U) | 
              (((4U == (0xcU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                >> 0x1cU))) << 1U) 
               | (0U == (0xcU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                 >> 0x1cU))))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit 
        = ((7U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit)) 
           | ((0xcU == (0xcU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                >> 0x1cU))) << 3U));
}

VL_INLINE_OPT void Vspi_host_tb_spi_host_tb___nba_sequent__TOP__spi_host_tb__2(Vspi_host_tb_spi_host_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vspi_host_tb_spi_host_tb___nba_sequent__TOP__spi_host_tb__2\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__spi_host_tb__tl_if.__PVT__clk_i = vlSelfRef.__PVT__clk_i;
    vlSymsp->TOP.__VvifTrigger_h100a9299__0 = 1U;
}

VL_INLINE_OPT void Vspi_host_tb_spi_host_tb___nba_comb__TOP__spi_host_tb__0(Vspi_host_tb_spi_host_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vspi_host_tb_spi_host_tb___nba_comb__TOP__spi_host_tb__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__a_ack 
        = (IData)(((vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                    >> 0xcU) & vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre[0U]));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rd_req 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__a_ack) 
           & (0x800U == (0xe00U & vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U])));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__wr_req 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__a_ack) 
           & ((0U == (7U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                >> 9U)))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__wr_req) 
           & (0U != (3U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                           >> 0x1cU))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_re 
        = ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rd_req));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_we 
        = ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__wr_req));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error 
        = (((~ (IData)((0U != (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit)))) 
            & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_re) 
               | (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_we))) 
           | ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_we) 
              & ((IData)((0U != (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit))) 
                 & (0U != (1U & (~ ((vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                     << 8U) | (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                               >> 0x18U))))))));
    vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____VdfgRegularize_h533b1fce_2_6 
        = ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error)) 
           & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_we));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
           & (IData)(vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____VdfgRegularize_h533b1fce_2_6));
}

VL_INLINE_OPT void Vspi_host_tb_spi_host_tb___nba_sequent__TOP__spi_host_tb__4(Vspi_host_tb_spi_host_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vspi_host_tb_spi_host_tb___nba_sequent__TOP__spi_host_tb__4\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 2U));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__full_o 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (4U ^ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    if (vlSelfRef.__PVT__rst_ni) {
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_q 
            = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_d;
        if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_wdata__DOT__wr_en) {
            vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_wdata__q 
                = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_wdata__DOT__wr_en)
                    ? (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                       >> 0x18U) : 0U);
        }
    } else {
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_q = 0U;
        vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_wdata__q = 0U;
    }
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 2U));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__full_o 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (4U ^ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_rvalid 
        = (1U & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
                 & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_depth 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__full_o)
            ? 3U : (3U & (((1U & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                  >> 2U)) == (1U & 
                                              ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                               >> 2U)))
                           ? (([&]() {
                            vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__76__inp 
                                = (3U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__76__Vfuncout 
                                = vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__76__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__76__Vfuncout)) 
                              - ([&]() {
                            vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__77__inp 
                                = (3U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__77__Vfuncout 
                                = vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__77__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__77__Vfuncout)))
                           : (((IData)(3U) - ([&]() {
                                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__79__inp 
                                    = (3U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__79__Vfuncout 
                                    = vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__79__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__79__Vfuncout))) 
                              + ([&]() {
                            vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__80__inp 
                                = (3U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__80__Vfuncout 
                                = vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__80__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__80__Vfuncout))))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wready 
        = (1U & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_depth 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__full_o)
            ? 3U : (3U & (((1U & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                  >> 2U)) == (1U & 
                                              ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                               >> 2U)))
                           ? (([&]() {
                            vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__67__inp 
                                = (3U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__67__Vfuncout 
                                = vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__67__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__67__Vfuncout)) 
                              - ([&]() {
                            vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__68__inp 
                                = (3U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__68__Vfuncout 
                                = vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__68__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__68__Vfuncout)))
                           : (((IData)(3U) - ([&]() {
                                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__70__inp 
                                    = (3U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__70__Vfuncout 
                                    = vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__70__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__70__Vfuncout))) 
                              + ([&]() {
                            vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__71__inp 
                                = (3U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__71__Vfuncout 
                                = vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__71__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__71__Vfuncout))))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready 
        = (1U & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid 
        = (1U & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
                 & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wvalid_q) 
           & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wready)));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdio_d 
        = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdio_q;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__wdata_qe) 
           & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready)));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d 
        = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid) 
           & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_q)));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_d = 0U;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__next_state 
        = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state;
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_d 
        = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q;
    if ((0U == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        if ((((IData)(vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q) 
              & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__wdata_qe)) 
             & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready))) {
            if ((2U == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
                vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_d = 1U;
                vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__next_state = 1U;
            }
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_d 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q)));
        }
    } else if ((1U == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        if ((1U < (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
            if ((8U <= (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid) {
                    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_d = 1U;
                    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_d 
                        = (7U & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q) 
                                 - (IData)(1U)));
                }
            }
        } else if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__r_wn_q) {
            if ((8U <= (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid) {
                    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_d = 1U;
                    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_d 
                        = (7U & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q) 
                                 - (IData)(1U)));
                }
            }
        } else if ((8U <= (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
            if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid) {
                vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_d = 1U;
                vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_d 
                    = (7U & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q) 
                             - (IData)(1U)));
            }
        }
        if ((1U >= (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
            if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__r_wn_q) {
                if ((8U <= (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid)))) {
                        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__next_state = 2U;
                    }
                }
            } else if ((8U <= (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                if ((1U & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid)))) {
                    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__next_state = 2U;
                }
            }
        }
    } else {
        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__next_state = 0U;
        if ((2U == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state))) {
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_d = 0U;
        }
    }
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk_en = 0U;
    if ((0U != (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        if ((1U == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state))) {
            if ((1U < (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
                if ((8U > (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk)))) {
                        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdio_d 
                            = (1U & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_q) 
                                     >> 7U));
                        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q)));
                    }
                } else if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid) {
                    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d = 0U;
                }
            } else {
                if ((1U & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__r_wn_q)))) {
                    if ((8U > (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                        if ((1U & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk)))) {
                            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdio_d 
                                = (1U & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_q) 
                                         >> 7U));
                        }
                    }
                }
                if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__r_wn_q) {
                    if ((8U > (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                        if ((1U & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk)))) {
                            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d 
                                = (0xfU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q)));
                        }
                    } else {
                        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d = 0U;
                    }
                } else if ((8U > (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk)))) {
                        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q)));
                    }
                } else {
                    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d = 0U;
                }
            }
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk_en = 1U;
            if ((1U >= (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
                if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__r_wn_q) {
                    if ((8U <= (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                        if ((1U & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid)))) {
                            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk_en = 0U;
                        }
                    }
                } else if ((8U <= (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid)))) {
                        vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk_en = 0U;
                    }
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state))) {
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdio_d = 0U;
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d = 0U;
        }
    }
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (2U == (3U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (2U == (3U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (2U == (3U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    vlSelfRef.u_spi_host__DOT__u_spi_host_core__DOT____Vcellinp__u_clk_div2__d_i 
        = ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk)) 
           & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk_en));
}
