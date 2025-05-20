// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_host.h for the primary calling header

#include "Vspi_host__pch.h"
#include "Vspi_host__Syms.h"
#include "Vspi_host_tlul_fifo_sync__RCz6_RDz6.h"

VL_ATTR_COLD void Vspi_host_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
    __PVT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
    __PVT__rspfifo__DOT__full_o = 0;
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
    __PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (0xfffeU 
                                                     & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
                                                        >> 6U)));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[8U] 
                                                           >> 4U)))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[7U] 
                                                        << 0xaU) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
                                                          >> 0x16U))
                                                       : 0U) 
                                                     << 0x10U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[8U] 
                                                           >> 4U)))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[7U] 
                                                        << 0xaU) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
                                                          >> 0x16U))
                                                       : 0U) 
                                                     >> 0x10U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (0xffff0000U 
                                                     & ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[8U] 
                                                         << 0x1aU) 
                                                        | (0x3ff0000U 
                                                           & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[7U] 
                                                              >> 6U)))));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[8U] 
                                                     >> 6U));
    __PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
               [0U][3U] >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[8U] 
               >> 7U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[8U] 
            >> 7U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
            [0U][3U] >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                                 & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
                 >> 6U)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
              [0U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_ATTR_COLD void Vspi_host_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
    __PVT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
    __PVT__rspfifo__DOT__full_o = 0;
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
    __PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (0xfffeU 
                                                     & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U] 
                                                        >> 4U)));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
                                                           >> 2U)))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[5U] 
                                                        << 0xcU) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U] 
                                                          >> 0x14U))
                                                       : 0U) 
                                                     << 0x10U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
                                                           >> 2U)))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[5U] 
                                                        << 0xcU) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U] 
                                                          >> 0x14U))
                                                       : 0U) 
                                                     >> 0x10U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (0xffff0000U 
                                                     & ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
                                                         << 0x1cU) 
                                                        | (0xfff0000U 
                                                           & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[5U] 
                                                              >> 4U)))));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
                                                     >> 4U));
    __PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
               [1U][3U] >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
               >> 5U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
            >> 5U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
            [1U][3U] >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                                 & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U] 
                 >> 4U)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
              [1U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_ATTR_COLD void Vspi_host_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
    __PVT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
    __PVT__rspfifo__DOT__full_o = 0;
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
    __PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (0xfffeU 
                                                     & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U] 
                                                        >> 2U)));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U]))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[3U] 
                                                        << 0xeU) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U] 
                                                          >> 0x12U))
                                                       : 0U) 
                                                     << 0x10U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U]))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[3U] 
                                                        << 0xeU) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U] 
                                                          >> 0x12U))
                                                       : 0U) 
                                                     >> 0x10U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (0xffff0000U 
                                                     & ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U] 
                                                         << 0x1eU) 
                                                        | (0x3fff0000U 
                                                           & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[3U] 
                                                              >> 2U)))));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U] 
                                                     >> 2U));
    __PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
               [2U][3U] >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U] 
               >> 3U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U] 
            >> 3U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
            [2U][3U] >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                                 & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U] 
                 >> 2U)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
              [2U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_ATTR_COLD void Vspi_host_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
    __PVT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
    __PVT__rspfifo__DOT__full_o = 0;
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
    __PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (0xfffeU 
                                                     & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[0U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[1U] 
                                                              >> 0x1eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[1U] 
                                                        << 0x10U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[0U] 
                                                          >> 0x10U))
                                                       : 0U) 
                                                     << 0x10U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[1U] 
                                                              >> 0x1eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[1U] 
                                                        << 0x10U) 
                                                       | (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[0U] 
                                                          >> 0x10U))
                                                       : 0U) 
                                                     >> 0x10U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (0xffff0000U 
                                                     & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[1U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U]);
    __PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
               [3U][3U] >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U] 
               >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
            [3U][3U] >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                                 & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
              [3U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_ATTR_COLD void Vspi_host_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
    __PVT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
    __PVT__rspfifo__DOT__full_o = 0;
    VlWide<4>/*127:0*/ __Vtemp_10;
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
    __PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    __PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tl_d_o[0U] = ((0xfffffffeU & vlSelfRef.tl_d_o[0U]) 
                            | (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o));
    __Vtemp_10[1U] = ((((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
                                     >> 0xcU)) ? ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]))
                                  : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                       << 0x1fU) | (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]))
                                               : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                    >> 1U));
    __Vtemp_10[2U] = ((((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
                                     >> 0xcU)) ? ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]) 
                                                  | (0xffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]))
                                  : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                       << 0x1fU) | (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]))
                                               : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                    >> 1U));
    vlSelfRef.tl_d_o[0U] = ((1U & vlSelfRef.tl_d_o[0U]) 
                            | ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                ? 0U : (0xfffffffeU 
                                        & (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                            & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
                                               >> 0xcU))
                                            ? (0xfffffffeU 
                                               & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U])
                                            : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tl_d_o[1U] = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
                                                >> 0xcU))
                                             ? ((1U 
                                                 & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]) 
                                                | (0xfffffffeU 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]))
                                             : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
                            | (__Vtemp_10[1U] << 1U));
    vlSelfRef.tl_d_o[2U] = ((__Vtemp_10[1U] >> 0x1fU) 
                            | (__Vtemp_10[2U] << 1U));
    vlSelfRef.tl_d_o[3U] = ((0x1000U & vlSelfRef.tl_d_o[3U]) 
                            | (0x1fffU & ((__Vtemp_10[2U] 
                                           >> 0x1fU) 
                                          | ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                              ? 0U : 
                                             (0xffeU 
                                              & (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                  & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
                                                     >> 0xcU))
                                                  ? 
                                                 ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]) 
                                                  | (0xffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]))
                                                  : 
                                                 vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tl_d_o[3U] = ((0xfffU & vlSelfRef.tl_d_o[3U]) 
                            | (0x1fffU & ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
                                          << 0xcU)));
}

VL_ATTR_COLD void Vspi_host_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
    __PVT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
    __PVT__rspfifo__DOT__full_o = 0;
    VlWide<4>/*127:0*/ __Vtemp_10;
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
    __PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    __PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tl_d_o[0U] = ((0xfffffffeU & vlSelfRef.tl_d_o[0U]) 
                            | (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o));
    __Vtemp_10[1U] = ((((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
                                     >> 0xcU)) ? ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]))
                                  : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                       << 0x1fU) | (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]))
                                               : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                    >> 1U));
    __Vtemp_10[2U] = ((((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
                                     >> 0xcU)) ? ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]) 
                                                  | (0xffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]))
                                  : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                       << 0x1fU) | (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]))
                                               : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                    >> 1U));
    vlSelfRef.tl_d_o[0U] = ((1U & vlSelfRef.tl_d_o[0U]) 
                            | ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                ? 0U : (0xfffffffeU 
                                        & (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                            & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
                                               >> 0xcU))
                                            ? (0xfffffffeU 
                                               & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U])
                                            : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tl_d_o[1U] = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
                                                >> 0xcU))
                                             ? ((1U 
                                                 & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]) 
                                                | (0xfffffffeU 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]))
                                             : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
                            | (__Vtemp_10[1U] << 1U));
    vlSelfRef.tl_d_o[2U] = ((__Vtemp_10[1U] >> 0x1fU) 
                            | (__Vtemp_10[2U] << 1U));
    vlSelfRef.tl_d_o[3U] = ((0x1000U & vlSelfRef.tl_d_o[3U]) 
                            | (0x1fffU & ((__Vtemp_10[2U] 
                                           >> 0x1fU) 
                                          | ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                              ? 0U : 
                                             (0xffeU 
                                              & (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                  & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
                                                     >> 0xcU))
                                                  ? 
                                                 ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]) 
                                                  | (0xffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]))
                                                  : 
                                                 vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tl_d_o[3U] = ((0xfffU & vlSelfRef.tl_d_o[3U]) 
                            | (0x1fffU & ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
                                          << 0xcU)));
}

VL_ATTR_COLD void Vspi_host_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
    __PVT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
    __PVT__rspfifo__DOT__full_o = 0;
    VlWide<4>/*127:0*/ __Vtemp_10;
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
    __PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    __PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tl_d_o[0U] = ((0xfffffffeU & vlSelfRef.tl_d_o[0U]) 
                            | (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o));
    __Vtemp_10[1U] = ((((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
                                     >> 0xcU)) ? ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]))
                                  : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                       << 0x1fU) | (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]))
                                               : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                    >> 1U));
    __Vtemp_10[2U] = ((((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
                                     >> 0xcU)) ? ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]) 
                                                  | (0xffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]))
                                  : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                       << 0x1fU) | (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]))
                                               : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                    >> 1U));
    vlSelfRef.tl_d_o[0U] = ((1U & vlSelfRef.tl_d_o[0U]) 
                            | ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                ? 0U : (0xfffffffeU 
                                        & (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                            & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
                                               >> 0xcU))
                                            ? (0xfffffffeU 
                                               & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U])
                                            : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tl_d_o[1U] = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
                                                >> 0xcU))
                                             ? ((1U 
                                                 & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]) 
                                                | (0xfffffffeU 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]))
                                             : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
                            | (__Vtemp_10[1U] << 1U));
    vlSelfRef.tl_d_o[2U] = ((__Vtemp_10[1U] >> 0x1fU) 
                            | (__Vtemp_10[2U] << 1U));
    vlSelfRef.tl_d_o[3U] = ((0x1000U & vlSelfRef.tl_d_o[3U]) 
                            | (0x1fffU & ((__Vtemp_10[2U] 
                                           >> 0x1fU) 
                                          | ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                              ? 0U : 
                                             (0xffeU 
                                              & (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                  & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
                                                     >> 0xcU))
                                                  ? 
                                                 ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]) 
                                                  | (0xffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]))
                                                  : 
                                                 vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tl_d_o[3U] = ((0xfffU & vlSelfRef.tl_d_o[3U]) 
                            | (0x1fffU & ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
                                          << 0xcU)));
}

VL_ATTR_COLD void Vspi_host_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
    __PVT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
    __PVT__rspfifo__DOT__full_o = 0;
    VlWide<4>/*127:0*/ __Vtemp_10;
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
    __PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    __PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tl_d_o[0U] = ((0xfffffffeU & vlSelfRef.tl_d_o[0U]) 
                            | (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o));
    __Vtemp_10[1U] = ((((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
                                     >> 0xcU)) ? ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]))
                                  : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                       << 0x1fU) | (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]))
                                               : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                    >> 1U));
    __Vtemp_10[2U] = ((((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
                                     >> 0xcU)) ? ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]) 
                                                  | (0xffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]))
                                  : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                       << 0x1fU) | (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]))
                                               : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                    >> 1U));
    vlSelfRef.tl_d_o[0U] = ((1U & vlSelfRef.tl_d_o[0U]) 
                            | ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                ? 0U : (0xfffffffeU 
                                        & (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                            & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
                                               >> 0xcU))
                                            ? (0xfffffffeU 
                                               & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U])
                                            : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tl_d_o[1U] = (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
                                                >> 0xcU))
                                             ? ((1U 
                                                 & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]) 
                                                | (0xfffffffeU 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]))
                                             : vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
                            | (__Vtemp_10[1U] << 1U));
    vlSelfRef.tl_d_o[2U] = ((__Vtemp_10[1U] >> 0x1fU) 
                            | (__Vtemp_10[2U] << 1U));
    vlSelfRef.tl_d_o[3U] = ((0x1000U & vlSelfRef.tl_d_o[3U]) 
                            | (0x1fffU & ((__Vtemp_10[2U] 
                                           >> 0x1fU) 
                                          | ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                              ? 0U : 
                                             (0xffeU 
                                              & (((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                  & (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
                                                     >> 0xcU))
                                                  ? 
                                                 ((1U 
                                                   & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]) 
                                                  | (0xffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]))
                                                  : 
                                                 vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tl_d_o[3U] = ((0xfffU & vlSelfRef.tl_d_o[3U]) 
                            | (0x1fffU & ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
                                          << 0xcU)));
}
