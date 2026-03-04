// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_pkg.h for the primary calling header

#include "Vtop_pkg__pch.h"

VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
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
    vlSelfRef.__PVT__reqfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
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
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[0U][2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
               [0U][2U] >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
              [0U][0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
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
    vlSelfRef.__PVT__reqfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
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
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[1U][2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
               [1U][2U] >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
              [1U][0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
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
    vlSelfRef.__PVT__reqfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
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
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U][2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
               [2U][2U] >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
              [2U][0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
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
    vlSelfRef.__PVT__reqfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
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
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[3U][2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
               [3U][2U] >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__rspfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSymsp->TOP.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i
              [3U][0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
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
    vlSelfRef.__PVT__rspfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
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
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__02Etl_h_i[0U][3U] 
            >> 0x0000000cU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
               [0U][3U] >> 0x0000000cU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
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

VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
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
    vlSelfRef.__PVT__rspfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
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
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__02Etl_h_i[1U][3U] 
            >> 0x0000000cU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
               [1U][3U] >> 0x0000000cU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
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

VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
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
    vlSelfRef.__PVT__rspfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
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
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__02Etl_h_i[2U][3U] 
            >> 0x0000000cU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
               [2U][3U] >> 0x0000000cU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
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

VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
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
    vlSelfRef.__PVT__rspfifo__DOT__wready_o = (((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                != 
                                                (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
                                               & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
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
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__02Etl_h_i[3U][3U] 
            >> 0x0000000cU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.__PVT__reqfifo__DOT__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__02Etl_h_i
               [3U][3U] >> 0x0000000cU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.__PVT__rspfifo__DOT__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.__PVT__reqfifo__DOT__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
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

VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ctor_var_reset(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ctor_var_reset\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11908517815223722933ull);
    vlSelf->rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3161515032326629241ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->tl_h_i, __VscopeHash, 2122476622687747023ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->tl_h_o, __VscopeHash, 6319575076937490387ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->tl_d_o, __VscopeHash, 11368034984740101998ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->tl_d_i, __VscopeHash, 13014753160808655041ull);
    vlSelf->spare_req_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 493429523236848428ull);
    vlSelf->__PVT__spare_req_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17173196022936639056ull);
    vlSelf->spare_rsp_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7475389204376298809ull);
    vlSelf->__PVT__spare_rsp_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13721876725535676424ull);
    VL_ZERO_RESET_W(108, vlSelf->__Vcellinp__reqfifo__wdata_i);
    VL_ZERO_RESET_W(65, vlSelf->__Vcellinp__rspfifo__wdata_i);
    vlSelf->__PVT__reqfifo__DOT__wvalid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18365709856125344263ull);
    vlSelf->__PVT__reqfifo__DOT__wready_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15538047954568321559ull);
    vlSelf->__PVT__reqfifo__DOT__rvalid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2064312904666954584ull);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5130701150261327694ull);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10430996046153060385ull);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3226906574595694669ull);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8907569739664665041ull);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15620909623587686632ull);
    VL_SCOPED_RAND_RESET_W(108, vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage, __VscopeHash, 5873882789090298157ull);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11370457135292088079ull);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7557678519982975210ull);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17749440174660132112ull);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17872277107725323438ull);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4191010221194684668ull);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15397128089286485403ull);
    vlSelf->__PVT__rspfifo__DOT__wvalid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7229493255230154855ull);
    vlSelf->__PVT__rspfifo__DOT__wready_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15846776984431348694ull);
    vlSelf->__PVT__rspfifo__DOT__rvalid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12574283212020970889ull);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11521188058062879315ull);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14691227834855784361ull);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2466675324023737270ull);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6600937043242058448ull);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2500767738549133001ull);
    VL_SCOPED_RAND_RESET_W(65, vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage, __VscopeHash, 531045417871525204ull);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 18024640858804351495ull);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9833853706210209881ull);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16388049326786612678ull);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16177684286361184965ull);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 567007954842101868ull);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8733501046532237499ull);
}
