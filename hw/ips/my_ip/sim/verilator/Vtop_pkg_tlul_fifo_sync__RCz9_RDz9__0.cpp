// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_pkg.h for the primary calling header

#include "Vtop_pkg__pch.h"

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[0U][2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (0x0000fffeU 
                                                     & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                     [0U][0U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0x0000ffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                            [0U][2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                              [0U][1U] 
                                                              >> 0x0000001eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                        [0U][1U] 
                                                        << 0x00000010U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                          [0U][0U] 
                                                          >> 0x00000010U))
                                                       : 0U) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                            [0U][2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                              [0U][1U] 
                                                              >> 0x0000001eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                        [0U][1U] 
                                                        << 0x00000010U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                          [0U][0U] 
                                                          >> 0x00000010U))
                                                       : 0U) 
                                                     >> 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0x0000ffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (0xffff0000U 
                                                     & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                     [0U][1U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                  [0U][2U]);
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
               [0U][2U] >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__wvalid_i = ((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                               & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((0xff000000U 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (0x00fffffeU 
                                                     & (((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select)
                                                          ? 
                                                         ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                           << 0x0000001dU) 
                                                          | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                             >> 3U))
                                                          : vlSymsp->TOP.tlul_socket_1n__DOT__blanked_auser) 
                                                        << 1U)));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((0x00ffffffU 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select)
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                        << 6U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                          >> 0x0000001aU))
                                                       : 0xffffffffU) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[1U] = ((
                                                   ((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select)
                                                     ? 
                                                    ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                      << 6U) 
                                                     | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                        >> 0x0000001aU))
                                                     : 0xffffffffU) 
                                                   >> 8U) 
                                                  | ((IData)(
                                                             (0x000fffffffffffffULL 
                                                              & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                  << 0x00000026U) 
                                                                 | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                     << 6U) 
                                                                    | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                       >> 0x0000001aU))))) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U] = (((IData)(
                                                           (0x000fffffffffffffULL 
                                                            & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                << 0x00000026U) 
                                                               | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                   << 6U) 
                                                                  | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                     >> 0x0000001aU))))) 
                                                   >> 8U) 
                                                  | ((IData)(
                                                             ((0x000fffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                   << 0x00000026U) 
                                                                  | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                      << 6U) 
                                                                     | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                        >> 0x0000001aU)))) 
                                                              >> 0x00000020U)) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U] = (0x00000fffU 
                                                  & ((IData)(
                                                             ((0x000fffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                   << 0x00000026U) 
                                                                  | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                      << 6U) 
                                                                     | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                        >> 0x0000001aU)))) 
                                                              >> 0x00000020U)) 
                                                     >> 8U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
              [0U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    if (vlSymsp->TOP.tlul_socket_1n__02Erst_ni) {
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
    } else {
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
    }
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
               [0U][2U] >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__1\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__2(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__2\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
            = vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U];
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = vlSelfRef.__Vcellinp__reqfifo__wdata_i[1U];
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U];
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
            = vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U];
    }
    if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
            = vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U];
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U];
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U];
    }
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__3(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__3\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[0U][2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__wvalid_i = ((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                               & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((0xff000000U 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (0x00fffffeU 
                                                     & (((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select)
                                                          ? 
                                                         ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                           << 0x0000001dU) 
                                                          | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                             >> 3U))
                                                          : vlSymsp->TOP.tlul_socket_1n__DOT__blanked_auser) 
                                                        << 1U)));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((0x00ffffffU 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select)
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                        << 6U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                          >> 0x0000001aU))
                                                       : 0xffffffffU) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[1U] = ((
                                                   ((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select)
                                                     ? 
                                                    ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                      << 6U) 
                                                     | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                        >> 0x0000001aU))
                                                     : 0xffffffffU) 
                                                   >> 8U) 
                                                  | ((IData)(
                                                             (0x000fffffffffffffULL 
                                                              & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                  << 0x00000026U) 
                                                                 | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                     << 6U) 
                                                                    | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                       >> 0x0000001aU))))) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U] = (((IData)(
                                                           (0x000fffffffffffffULL 
                                                            & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                << 0x00000026U) 
                                                               | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                   << 6U) 
                                                                  | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                     >> 0x0000001aU))))) 
                                                   >> 8U) 
                                                  | ((IData)(
                                                             ((0x000fffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                   << 0x00000026U) 
                                                                  | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                      << 6U) 
                                                                     | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                        >> 0x0000001aU)))) 
                                                              >> 0x00000020U)) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U] = (0x00000fffU 
                                                  & ((IData)(
                                                             ((0x000fffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                   << 0x00000026U) 
                                                                  | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                      << 6U) 
                                                                     | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                        >> 0x0000001aU)))) 
                                                              >> 0x00000020U)) 
                                                     >> 8U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
              [0U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[1U][2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (0x0000fffeU 
                                                     & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                     [1U][0U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0x0000ffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                            [1U][2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                              [1U][1U] 
                                                              >> 0x0000001eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                        [1U][1U] 
                                                        << 0x00000010U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                          [1U][0U] 
                                                          >> 0x00000010U))
                                                       : 0U) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                            [1U][2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                              [1U][1U] 
                                                              >> 0x0000001eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                        [1U][1U] 
                                                        << 0x00000010U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                          [1U][0U] 
                                                          >> 0x00000010U))
                                                       : 0U) 
                                                     >> 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0x0000ffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (0xffff0000U 
                                                     & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                     [1U][1U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                  [1U][2U]);
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
               [1U][2U] >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__wvalid_i = ((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                               & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((0xff000000U 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (0x00fffffeU 
                                                     & (((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select)
                                                          ? 
                                                         ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                           << 0x0000001dU) 
                                                          | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                             >> 3U))
                                                          : vlSymsp->TOP.tlul_socket_1n__DOT__blanked_auser) 
                                                        << 1U)));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((0x00ffffffU 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select)
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                        << 6U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                          >> 0x0000001aU))
                                                       : 0xffffffffU) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[1U] = ((
                                                   ((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select)
                                                     ? 
                                                    ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                      << 6U) 
                                                     | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                        >> 0x0000001aU))
                                                     : 0xffffffffU) 
                                                   >> 8U) 
                                                  | ((IData)(
                                                             (0x000fffffffffffffULL 
                                                              & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                  << 0x00000026U) 
                                                                 | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                     << 6U) 
                                                                    | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                       >> 0x0000001aU))))) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U] = (((IData)(
                                                           (0x000fffffffffffffULL 
                                                            & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                << 0x00000026U) 
                                                               | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                   << 6U) 
                                                                  | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                     >> 0x0000001aU))))) 
                                                   >> 8U) 
                                                  | ((IData)(
                                                             ((0x000fffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                   << 0x00000026U) 
                                                                  | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                      << 6U) 
                                                                     | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                        >> 0x0000001aU)))) 
                                                              >> 0x00000020U)) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U] = (0x00000fffU 
                                                  & ((IData)(
                                                             ((0x000fffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                   << 0x00000026U) 
                                                                  | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                      << 6U) 
                                                                     | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                        >> 0x0000001aU)))) 
                                                              >> 0x00000020U)) 
                                                     >> 8U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
              [1U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    if (vlSymsp->TOP.tlul_socket_1n__02Erst_ni) {
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
    } else {
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
    }
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
               [1U][2U] >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__3(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__3\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[1U][2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__wvalid_i = ((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                               & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((0xff000000U 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (0x00fffffeU 
                                                     & (((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select)
                                                          ? 
                                                         ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                           << 0x0000001dU) 
                                                          | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                             >> 3U))
                                                          : vlSymsp->TOP.tlul_socket_1n__DOT__blanked_auser) 
                                                        << 1U)));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((0x00ffffffU 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select)
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                        << 6U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                          >> 0x0000001aU))
                                                       : 0xffffffffU) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[1U] = ((
                                                   ((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select)
                                                     ? 
                                                    ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                      << 6U) 
                                                     | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                        >> 0x0000001aU))
                                                     : 0xffffffffU) 
                                                   >> 8U) 
                                                  | ((IData)(
                                                             (0x000fffffffffffffULL 
                                                              & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                  << 0x00000026U) 
                                                                 | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                     << 6U) 
                                                                    | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                       >> 0x0000001aU))))) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U] = (((IData)(
                                                           (0x000fffffffffffffULL 
                                                            & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                << 0x00000026U) 
                                                               | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                   << 6U) 
                                                                  | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                     >> 0x0000001aU))))) 
                                                   >> 8U) 
                                                  | ((IData)(
                                                             ((0x000fffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                   << 0x00000026U) 
                                                                  | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                      << 6U) 
                                                                     | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                        >> 0x0000001aU)))) 
                                                              >> 0x00000020U)) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U] = (0x00000fffU 
                                                  & ((IData)(
                                                             ((0x000fffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                   << 0x00000026U) 
                                                                  | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                      << 6U) 
                                                                     | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                        >> 0x0000001aU)))) 
                                                              >> 0x00000020U)) 
                                                     >> 8U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
              [1U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U][2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (0x0000fffeU 
                                                     & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                     [2U][0U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0x0000ffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                            [2U][2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                              [2U][1U] 
                                                              >> 0x0000001eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                        [2U][1U] 
                                                        << 0x00000010U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                          [2U][0U] 
                                                          >> 0x00000010U))
                                                       : 0U) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                            [2U][2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                              [2U][1U] 
                                                              >> 0x0000001eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                        [2U][1U] 
                                                        << 0x00000010U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                          [2U][0U] 
                                                          >> 0x00000010U))
                                                       : 0U) 
                                                     >> 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0x0000ffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (0xffff0000U 
                                                     & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                     [2U][1U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                  [2U][2U]);
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
               [2U][2U] >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__wvalid_i = ((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                               & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((0xff000000U 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (0x00fffffeU 
                                                     & (((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select)
                                                          ? 
                                                         ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                           << 0x0000001dU) 
                                                          | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                             >> 3U))
                                                          : vlSymsp->TOP.tlul_socket_1n__DOT__blanked_auser) 
                                                        << 1U)));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((0x00ffffffU 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select)
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                        << 6U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                          >> 0x0000001aU))
                                                       : 0xffffffffU) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[1U] = ((
                                                   ((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select)
                                                     ? 
                                                    ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                      << 6U) 
                                                     | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                        >> 0x0000001aU))
                                                     : 0xffffffffU) 
                                                   >> 8U) 
                                                  | ((IData)(
                                                             (0x000fffffffffffffULL 
                                                              & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                  << 0x00000026U) 
                                                                 | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                     << 6U) 
                                                                    | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                       >> 0x0000001aU))))) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U] = (((IData)(
                                                           (0x000fffffffffffffULL 
                                                            & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                << 0x00000026U) 
                                                               | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                   << 6U) 
                                                                  | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                     >> 0x0000001aU))))) 
                                                   >> 8U) 
                                                  | ((IData)(
                                                             ((0x000fffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                   << 0x00000026U) 
                                                                  | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                      << 6U) 
                                                                     | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                        >> 0x0000001aU)))) 
                                                              >> 0x00000020U)) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U] = (0x00000fffU 
                                                  & ((IData)(
                                                             ((0x000fffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                   << 0x00000026U) 
                                                                  | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                      << 6U) 
                                                                     | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                        >> 0x0000001aU)))) 
                                                              >> 0x00000020U)) 
                                                     >> 8U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
              [2U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    if (vlSymsp->TOP.tlul_socket_1n__02Erst_ni) {
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
    } else {
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
    }
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
               [2U][2U] >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__3(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__3\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U][2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__wvalid_i = ((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                               & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((0xff000000U 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (0x00fffffeU 
                                                     & (((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select)
                                                          ? 
                                                         ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                           << 0x0000001dU) 
                                                          | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                             >> 3U))
                                                          : vlSymsp->TOP.tlul_socket_1n__DOT__blanked_auser) 
                                                        << 1U)));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((0x00ffffffU 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select)
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                        << 6U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                          >> 0x0000001aU))
                                                       : 0xffffffffU) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[1U] = ((
                                                   ((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select)
                                                     ? 
                                                    ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                      << 6U) 
                                                     | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                        >> 0x0000001aU))
                                                     : 0xffffffffU) 
                                                   >> 8U) 
                                                  | ((IData)(
                                                             (0x000fffffffffffffULL 
                                                              & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                  << 0x00000026U) 
                                                                 | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                     << 6U) 
                                                                    | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                       >> 0x0000001aU))))) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U] = (((IData)(
                                                           (0x000fffffffffffffULL 
                                                            & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                << 0x00000026U) 
                                                               | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                   << 6U) 
                                                                  | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                     >> 0x0000001aU))))) 
                                                   >> 8U) 
                                                  | ((IData)(
                                                             ((0x000fffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                   << 0x00000026U) 
                                                                  | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                      << 6U) 
                                                                     | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                        >> 0x0000001aU)))) 
                                                              >> 0x00000020U)) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U] = (0x00000fffU 
                                                  & ((IData)(
                                                             ((0x000fffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                   << 0x00000026U) 
                                                                  | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                      << 6U) 
                                                                     | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                        >> 0x0000001aU)))) 
                                                              >> 0x00000020U)) 
                                                     >> 8U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
              [2U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[3U][2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (0x0000fffeU 
                                                     & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                     [3U][0U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0x0000ffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                            [3U][2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                              [3U][1U] 
                                                              >> 0x0000001eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                        [3U][1U] 
                                                        << 0x00000010U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                          [3U][0U] 
                                                          >> 0x00000010U))
                                                       : 0U) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                            [3U][2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                              [3U][1U] 
                                                              >> 0x0000001eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                        [3U][1U] 
                                                        << 0x00000010U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                          [3U][0U] 
                                                          >> 0x00000010U))
                                                       : 0U) 
                                                     >> 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0x0000ffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (0xffff0000U 
                                                     & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                     [3U][1U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
                                                  [3U][2U]);
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
               [3U][2U] >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__wvalid_i = ((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                               & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((0xff000000U 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (0x00fffffeU 
                                                     & (((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select)
                                                          ? 
                                                         ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                           << 0x0000001dU) 
                                                          | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                             >> 3U))
                                                          : vlSymsp->TOP.tlul_socket_1n__DOT__blanked_auser) 
                                                        << 1U)));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((0x00ffffffU 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select)
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                        << 6U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                          >> 0x0000001aU))
                                                       : 0xffffffffU) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[1U] = ((
                                                   ((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select)
                                                     ? 
                                                    ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                      << 6U) 
                                                     | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                        >> 0x0000001aU))
                                                     : 0xffffffffU) 
                                                   >> 8U) 
                                                  | ((IData)(
                                                             (0x000fffffffffffffULL 
                                                              & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                  << 0x00000026U) 
                                                                 | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                     << 6U) 
                                                                    | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                       >> 0x0000001aU))))) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U] = (((IData)(
                                                           (0x000fffffffffffffULL 
                                                            & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                << 0x00000026U) 
                                                               | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                   << 6U) 
                                                                  | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                     >> 0x0000001aU))))) 
                                                   >> 8U) 
                                                  | ((IData)(
                                                             ((0x000fffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                   << 0x00000026U) 
                                                                  | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                      << 6U) 
                                                                     | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                        >> 0x0000001aU)))) 
                                                              >> 0x00000020U)) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U] = (0x00000fffU 
                                                  & ((IData)(
                                                             ((0x000fffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                   << 0x00000026U) 
                                                                  | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                      << 6U) 
                                                                     | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                        >> 0x0000001aU)))) 
                                                              >> 0x00000020U)) 
                                                     >> 8U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
              [3U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    if (vlSymsp->TOP.tlul_socket_1n__02Erst_ni) {
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
    } else {
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
    }
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
               [3U][2U] >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__3(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__3\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[3U][2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__wvalid_i = ((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                               & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((0xff000000U 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (0x00fffffeU 
                                                     & (((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select)
                                                          ? 
                                                         ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                           << 0x0000001dU) 
                                                          | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                             >> 3U))
                                                          : vlSymsp->TOP.tlul_socket_1n__DOT__blanked_auser) 
                                                        << 1U)));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((0x00ffffffU 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select)
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                        << 6U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                          >> 0x0000001aU))
                                                       : 0xffffffffU) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[1U] = ((
                                                   ((IData)(vlSymsp->TOP.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select)
                                                     ? 
                                                    ((vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                      << 6U) 
                                                     | (vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                        >> 0x0000001aU))
                                                     : 0xffffffffU) 
                                                   >> 8U) 
                                                  | ((IData)(
                                                             (0x000fffffffffffffULL 
                                                              & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                  << 0x00000026U) 
                                                                 | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                     << 6U) 
                                                                    | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                       >> 0x0000001aU))))) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U] = (((IData)(
                                                           (0x000fffffffffffffULL 
                                                            & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                << 0x00000026U) 
                                                               | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                   << 6U) 
                                                                  | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                     >> 0x0000001aU))))) 
                                                   >> 8U) 
                                                  | ((IData)(
                                                             ((0x000fffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                   << 0x00000026U) 
                                                                  | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                      << 6U) 
                                                                     | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                        >> 0x0000001aU)))) 
                                                              >> 0x00000020U)) 
                                                     << 0x00000018U));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U] = (0x00000fffU 
                                                  & ((IData)(
                                                             ((0x000fffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U])) 
                                                                   << 0x00000026U) 
                                                                  | (((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U])) 
                                                                      << 6U) 
                                                                     | ((QData)((IData)(
                                                                                vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U])) 
                                                                        >> 0x0000001aU)))) 
                                                              >> 0x00000020U)) 
                                                     >> 8U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
              [3U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__02Etl_h_i[0U][3U] 
            >> 0x0000000cU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = (0xfffffffeU 
                                                  & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]);
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = ((1U 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                     [0U][0U]));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[1U] = ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                   [0U][1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                     [0U][1U]));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U] = ((0xc0000000U 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U]) 
                                                  | ((1U 
                                                      & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                      [0U][2U]) 
                                                     | (0x0ffffffeU 
                                                        & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                        [0U][2U])));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U] = ((0x3fffffffU 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U]) 
                                                  | (((0x00003fc0U 
                                                       & (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                          [0U][3U] 
                                                          << 2U)) 
                                                      | (0x0000003fU 
                                                         & ((vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                             [0U][3U] 
                                                             << 4U) 
                                                            | (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                               [0U][2U] 
                                                               >> 0x0000001cU)))) 
                                                     << 0x0000001eU));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U] = (0x00000fffU 
                                                  & (((0x00003fc0U 
                                                       & (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                          [0U][3U] 
                                                          << 2U)) 
                                                      | (0x0000003fU 
                                                         & ((vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                             [0U][3U] 
                                                             << 4U) 
                                                            | (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                               [0U][2U] 
                                                               >> 0x0000001cU)))) 
                                                     >> 2U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
               [0U][3U] >> 0x0000000cU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__wvalid_i = ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
                                               & (0U 
                                                  == 
                                                  (0x00060000U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | ((0x0000fffcU 
                                                      & ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4) 
                                                         << 2U)) 
                                                     | (2U 
                                                        & vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0x0000ffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | ((IData)(
                                                             (((QData)((IData)(
                                                                               (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                               << 0x00000020U) 
                                                              | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3)))) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = (((IData)(
                                                           (((QData)((IData)(
                                                                             (0x0001ffffU 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3)))) 
                                                   >> 0x00000010U) 
                                                  | ((IData)(
                                                             ((((QData)((IData)(
                                                                                (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3))) 
                                                              >> 0x00000020U)) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & ((IData)(
                                                             ((((QData)((IData)(
                                                                                (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3))) 
                                                              >> 0x00000020U)) 
                                                     >> 0x00000010U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
              [0U][0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSymsp->TOP.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gnt_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    if (vlSymsp->TOP.tlul_socket_m1__02Erst_ni) {
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
    } else {
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
    }
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
               [0U][3U] >> 0x0000000cU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__2(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__2\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
            = vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U];
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U];
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U];
    }
    if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
            = vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U];
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = vlSelfRef.__Vcellinp__reqfifo__wdata_i[1U];
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U];
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
            = vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U];
    }
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__3(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__3\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__02Etl_h_i[0U][3U] 
            >> 0x0000000cU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__wvalid_i = ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
                                               & (0U 
                                                  == 
                                                  (0x00060000U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | ((0x0000fffcU 
                                                      & ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4) 
                                                         << 2U)) 
                                                     | (2U 
                                                        & vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0x0000ffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | ((IData)(
                                                             (((QData)((IData)(
                                                                               (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                               << 0x00000020U) 
                                                              | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3)))) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = (((IData)(
                                                           (((QData)((IData)(
                                                                             (0x0001ffffU 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3)))) 
                                                   >> 0x00000010U) 
                                                  | ((IData)(
                                                             ((((QData)((IData)(
                                                                                (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3))) 
                                                              >> 0x00000020U)) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & ((IData)(
                                                             ((((QData)((IData)(
                                                                                (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3))) 
                                                              >> 0x00000020U)) 
                                                     >> 0x00000010U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
              [0U][0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__02Etl_h_i[1U][3U] 
            >> 0x0000000cU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = (0xfffffffeU 
                                                  & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                  [1U][0U]);
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[1U] = ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                   [1U][1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                     [1U][1U]));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U] = ((0xf0000000U 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U]) 
                                                  | ((1U 
                                                      & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                      [1U][2U]) 
                                                     | (0x0ffffffeU 
                                                        & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                        [1U][2U])));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U] = ((0x0fffffffU 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U]) 
                                                  | (0xf0000000U 
                                                     & (0x10000000U 
                                                        | (0xc0000000U 
                                                           & (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                              [1U][2U] 
                                                              << 2U)))));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U] = ((0x00000ff0U 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U]) 
                                                  | (0x0000000fU 
                                                     & ((0x0ffffffcU 
                                                         & (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                            [1U][3U] 
                                                            << 2U)) 
                                                        | (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                           [1U][2U] 
                                                           >> 0x0000001eU))));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U] = ((0x0000000fU 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U]) 
                                                  | (0x00000ff0U 
                                                     & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                     [1U][3U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
               [1U][3U] >> 0x0000000cU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__wvalid_i = ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
                                               & (0x00020000U 
                                                  == 
                                                  (0x00060000U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | ((0x0000fffcU 
                                                      & ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4) 
                                                         << 2U)) 
                                                     | (2U 
                                                        & vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0x0000ffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | ((IData)(
                                                             (((QData)((IData)(
                                                                               (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                               << 0x00000020U) 
                                                              | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3)))) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = (((IData)(
                                                           (((QData)((IData)(
                                                                             (0x0001ffffU 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3)))) 
                                                   >> 0x00000010U) 
                                                  | ((IData)(
                                                             ((((QData)((IData)(
                                                                                (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3))) 
                                                              >> 0x00000020U)) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & ((IData)(
                                                             ((((QData)((IData)(
                                                                                (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3))) 
                                                              >> 0x00000020U)) 
                                                     >> 0x00000010U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
              [1U][0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gnt_o) 
                 >> 1U)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    if (vlSymsp->TOP.tlul_socket_m1__02Erst_ni) {
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
    } else {
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
    }
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
               [1U][3U] >> 0x0000000cU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__3(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__3\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__02Etl_h_i[1U][3U] 
            >> 0x0000000cU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__wvalid_i = ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
                                               & (0x00020000U 
                                                  == 
                                                  (0x00060000U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | ((0x0000fffcU 
                                                      & ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4) 
                                                         << 2U)) 
                                                     | (2U 
                                                        & vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0x0000ffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | ((IData)(
                                                             (((QData)((IData)(
                                                                               (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                               << 0x00000020U) 
                                                              | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3)))) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = (((IData)(
                                                           (((QData)((IData)(
                                                                             (0x0001ffffU 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3)))) 
                                                   >> 0x00000010U) 
                                                  | ((IData)(
                                                             ((((QData)((IData)(
                                                                                (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3))) 
                                                              >> 0x00000020U)) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & ((IData)(
                                                             ((((QData)((IData)(
                                                                                (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3))) 
                                                              >> 0x00000020U)) 
                                                     >> 0x00000010U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
              [1U][0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__02Etl_h_i[2U][3U] 
            >> 0x0000000cU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = (0xfffffffeU 
                                                  & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                  [2U][0U]);
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[1U] = ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                   [2U][1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                     [2U][1U]));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U] = ((0xf0000000U 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U]) 
                                                  | ((1U 
                                                      & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                      [2U][2U]) 
                                                     | (0x0ffffffeU 
                                                        & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                        [2U][2U])));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U] = ((0x0fffffffU 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U]) 
                                                  | (0xf0000000U 
                                                     & (0x20000000U 
                                                        | (0xc0000000U 
                                                           & (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                              [2U][2U] 
                                                              << 2U)))));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U] = ((0x00000ff0U 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U]) 
                                                  | (0x0000000fU 
                                                     & ((0x0ffffffcU 
                                                         & (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                            [2U][3U] 
                                                            << 2U)) 
                                                        | (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                           [2U][2U] 
                                                           >> 0x0000001eU))));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U] = ((0x0000000fU 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U]) 
                                                  | (0x00000ff0U 
                                                     & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                     [2U][3U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
               [2U][3U] >> 0x0000000cU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__wvalid_i = ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
                                               & (0x00040000U 
                                                  == 
                                                  (0x00060000U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | ((0x0000fffcU 
                                                      & ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4) 
                                                         << 2U)) 
                                                     | (2U 
                                                        & vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0x0000ffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | ((IData)(
                                                             (((QData)((IData)(
                                                                               (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                               << 0x00000020U) 
                                                              | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3)))) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = (((IData)(
                                                           (((QData)((IData)(
                                                                             (0x0001ffffU 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3)))) 
                                                   >> 0x00000010U) 
                                                  | ((IData)(
                                                             ((((QData)((IData)(
                                                                                (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3))) 
                                                              >> 0x00000020U)) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & ((IData)(
                                                             ((((QData)((IData)(
                                                                                (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3))) 
                                                              >> 0x00000020U)) 
                                                     >> 0x00000010U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
              [2U][0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gnt_o) 
                 >> 2U)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    if (vlSymsp->TOP.tlul_socket_m1__02Erst_ni) {
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
    } else {
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
    }
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
               [2U][3U] >> 0x0000000cU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__3(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__3\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__02Etl_h_i[2U][3U] 
            >> 0x0000000cU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__wvalid_i = ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
                                               & (0x00040000U 
                                                  == 
                                                  (0x00060000U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | ((0x0000fffcU 
                                                      & ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4) 
                                                         << 2U)) 
                                                     | (2U 
                                                        & vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0x0000ffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | ((IData)(
                                                             (((QData)((IData)(
                                                                               (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                               << 0x00000020U) 
                                                              | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3)))) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = (((IData)(
                                                           (((QData)((IData)(
                                                                             (0x0001ffffU 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3)))) 
                                                   >> 0x00000010U) 
                                                  | ((IData)(
                                                             ((((QData)((IData)(
                                                                                (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3))) 
                                                              >> 0x00000020U)) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & ((IData)(
                                                             ((((QData)((IData)(
                                                                                (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3))) 
                                                              >> 0x00000020U)) 
                                                     >> 0x00000010U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
              [2U][0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__02Etl_h_i[3U][3U] 
            >> 0x0000000cU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[0U] = (0xfffffffeU 
                                                  & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                  [3U][0U]);
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[1U] = ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                   [3U][1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                     [3U][1U]));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U] = ((0xf0000000U 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U]) 
                                                  | ((1U 
                                                      & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                      [3U][2U]) 
                                                     | (0x0ffffffeU 
                                                        & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                        [3U][2U])));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U] = ((0x0fffffffU 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[2U]) 
                                                  | (0xf0000000U 
                                                     & (0x30000000U 
                                                        | (0xc0000000U 
                                                           & (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                              [3U][2U] 
                                                              << 2U)))));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U] = ((0x00000ff0U 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U]) 
                                                  | (0x0000000fU 
                                                     & ((0x0ffffffcU 
                                                         & (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                            [3U][3U] 
                                                            << 2U)) 
                                                        | (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                           [3U][2U] 
                                                           >> 0x0000001eU))));
    vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U] = ((0x0000000fU 
                                                   & vlSelfRef.__Vcellinp__reqfifo__wdata_i[3U]) 
                                                  | (0x00000ff0U 
                                                     & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
                                                     [3U][3U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
               [3U][3U] >> 0x0000000cU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__wvalid_i = ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
                                               & (0x00060000U 
                                                  == 
                                                  (0x00060000U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | ((0x0000fffcU 
                                                      & ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4) 
                                                         << 2U)) 
                                                     | (2U 
                                                        & vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0x0000ffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | ((IData)(
                                                             (((QData)((IData)(
                                                                               (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                               << 0x00000020U) 
                                                              | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3)))) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = (((IData)(
                                                           (((QData)((IData)(
                                                                             (0x0001ffffU 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3)))) 
                                                   >> 0x00000010U) 
                                                  | ((IData)(
                                                             ((((QData)((IData)(
                                                                                (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3))) 
                                                              >> 0x00000020U)) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & ((IData)(
                                                             ((((QData)((IData)(
                                                                                (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3))) 
                                                              >> 0x00000020U)) 
                                                     >> 0x00000010U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
              [3U][0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gnt_o) 
                 >> 3U)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    if (vlSymsp->TOP.tlul_socket_m1__02Erst_ni) {
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
    } else {
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
    }
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
               [3U][3U] >> 0x0000000cU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__3(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__3\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__02Etl_h_i[3U][3U] 
            >> 0x0000000cU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__wvalid_i = ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
                                               & (0x00060000U 
                                                  == 
                                                  (0x00060000U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | ((0x0000fffcU 
                                                      & ((IData)(vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4) 
                                                         << 2U)) 
                                                     | (2U 
                                                        & vlSymsp->TOP.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0x0000ffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | ((IData)(
                                                             (((QData)((IData)(
                                                                               (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                               << 0x00000020U) 
                                                              | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3)))) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = (((IData)(
                                                           (((QData)((IData)(
                                                                             (0x0001ffffU 
                                                                              & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3)))) 
                                                   >> 0x00000010U) 
                                                  | ((IData)(
                                                             ((((QData)((IData)(
                                                                                (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3))) 
                                                              >> 0x00000020U)) 
                                                     << 0x00000010U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & ((IData)(
                                                             ((((QData)((IData)(
                                                                                (0x0001ffffU 
                                                                                & (IData)(
                                                                                (vlSymsp->TOP.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
                                                                                >> 0x0000002eU))))) 
                                                                << 0x00000020U) 
                                                               | (QData)((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_3))) 
                                                              >> 0x00000020U)) 
                                                     >> 0x00000010U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
              [3U][0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}
