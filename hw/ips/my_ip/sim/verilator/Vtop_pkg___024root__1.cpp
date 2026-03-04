// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_pkg.h for the primary calling header

#include "Vtop_pkg__pch.h"

void Vtop_pkg___024root___nba_comb__TOP__2(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_comb__TOP__2\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0U][0U] = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [0U][0U]) 
                                                   | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0U][0U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [0U][0U]) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[0U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0U][1U] = (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[1U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[1U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0U][2U] = (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[2U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0U][3U] = (
                                                   (0x00001000U 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [0U][3U]) 
                                                   | (0x00001fffU 
                                                      & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                           ? 0U
                                                           : 
                                                          (1U 
                                                           & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                               & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                               ? 
                                                              vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[3U]
                                                               : 
                                                              vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                                         | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (0x00000ffeU 
                                                             & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                 & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                                 ? 
                                                                vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[3U]
                                                                 : 
                                                                vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0U][3U] = (
                                                   (0x00000fffU 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [0U][3U]) 
                                                   | (0x00001fffU 
                                                      & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__rvalid_o) 
                                                         << 0x0000000cU)));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[1U][0U] = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [1U][0U]) 
                                                   | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[1U][0U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [1U][0U]) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[0U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[1U][1U] = (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[1U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[1U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[1U][2U] = (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[2U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[1U][3U] = (
                                                   (0x00001000U 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [1U][3U]) 
                                                   | (0x00001fffU 
                                                      & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                           ? 0U
                                                           : 
                                                          (1U 
                                                           & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                               & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                               ? 
                                                              vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[3U]
                                                               : 
                                                              vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                                         | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (0x00000ffeU 
                                                             & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                 & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                                 ? 
                                                                vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[3U]
                                                                 : 
                                                                vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[1U][3U] = (
                                                   (0x00000fffU 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [1U][3U]) 
                                                   | (0x00001fffU 
                                                      & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__rvalid_o) 
                                                         << 0x0000000cU)));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[2U][0U] = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [2U][0U]) 
                                                   | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[2U][0U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [2U][0U]) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[0U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[2U][1U] = (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[1U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[1U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[2U][2U] = (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[2U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[2U][3U] = (
                                                   (0x00001000U 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [2U][3U]) 
                                                   | (0x00001fffU 
                                                      & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                           ? 0U
                                                           : 
                                                          (1U 
                                                           & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                               & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                               ? 
                                                              vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[3U]
                                                               : 
                                                              vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                                         | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (0x00000ffeU 
                                                             & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                 & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                                 ? 
                                                                vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[3U]
                                                                 : 
                                                                vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[2U][3U] = (
                                                   (0x00000fffU 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [2U][3U]) 
                                                   | (0x00001fffU 
                                                      & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__rvalid_o) 
                                                         << 0x0000000cU)));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U][0U] = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [3U][0U]) 
                                                   | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U][0U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [3U][0U]) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[0U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U][1U] = (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[1U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[1U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U][2U] = (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[2U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U][3U] = (
                                                   (0x00001000U 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [3U][3U]) 
                                                   | (0x00001fffU 
                                                      & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                           ? 0U
                                                           : 
                                                          (1U 
                                                           & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                               & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                               ? 
                                                              vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[3U]
                                                               : 
                                                              vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                                         | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (0x00000ffeU 
                                                             & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                 & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                                 ? 
                                                                vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[3U]
                                                                 : 
                                                                vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U][3U] = (
                                                   (0x00000fffU 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [3U][3U]) 
                                                   | (0x00001fffU 
                                                      & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__rvalid_o) 
                                                         << 0x0000000cU)));
}

void Vtop_pkg___024root___nba_sequent__TOP__43(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__43\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((0U != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)) 
           & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
}

void Vtop_pkg___024root___nba_comb__TOP__3(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_comb__TOP__3\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U] = 0U;
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] = 0U;
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U] = 0U;
    } else if (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
                   >> 1U))) {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[2U];
    } else {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0U][0U] 
        = ((0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [0U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0U][0U] 
        = ((1U & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [0U][0U]) | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                          ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                     [0U][3U] 
                                                     >> 0x0000000cU))
                                                  ? 
                                                 vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[0U]
                                                  : 
                                                 vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0U][1U] 
        = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
             ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                            & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                               [0U][3U] >> 0x0000000cU))
                            ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[1U]
                            : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
           | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
               ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                          [0U][3U] 
                                          >> 0x0000000cU))
                                       ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[1U]
                                       : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0U][2U] 
        = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
             ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                            & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                               [0U][3U] >> 0x0000000cU))
                            ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[2U]
                            : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
           | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
               ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                          [0U][3U] 
                                          >> 0x0000000cU))
                                       ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[2U]
                                       : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0U][3U] 
        = ((0x00001000U & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [0U][3U]) | (0x00001fffU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                          ? 0U : (1U 
                                                  & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                      & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                         [0U][3U] 
                                                         >> 0x0000000cU))
                                                      ? 
                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[3U]
                                                      : 
                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                        | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                            ? 0U : 
                                           (0x00000ffeU 
                                            & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                   [0U][3U] 
                                                   >> 0x0000000cU))
                                                ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[3U]
                                                : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0U][3U] 
        = ((0x00000fffU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [0U][3U]) | (0x00001fffU & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__rvalid_o) 
                                        << 0x0000000cU)));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[1U][0U] 
        = ((0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [1U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[1U][0U] 
        = ((1U & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [1U][0U]) | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                          ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                     [1U][3U] 
                                                     >> 0x0000000cU))
                                                  ? 
                                                 vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[0U]
                                                  : 
                                                 vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[1U][1U] 
        = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
             ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                            & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                               [1U][3U] >> 0x0000000cU))
                            ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[1U]
                            : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
           | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
               ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                          [1U][3U] 
                                          >> 0x0000000cU))
                                       ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[1U]
                                       : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[1U][2U] 
        = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
             ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                            & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                               [1U][3U] >> 0x0000000cU))
                            ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[2U]
                            : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
           | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
               ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                          [1U][3U] 
                                          >> 0x0000000cU))
                                       ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[2U]
                                       : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[1U][3U] 
        = ((0x00001000U & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [1U][3U]) | (0x00001fffU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                          ? 0U : (1U 
                                                  & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                      & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                         [1U][3U] 
                                                         >> 0x0000000cU))
                                                      ? 
                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[3U]
                                                      : 
                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                        | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                            ? 0U : 
                                           (0x00000ffeU 
                                            & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                   [1U][3U] 
                                                   >> 0x0000000cU))
                                                ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[3U]
                                                : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[1U][3U] 
        = ((0x00000fffU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [1U][3U]) | (0x00001fffU & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__rvalid_o) 
                                        << 0x0000000cU)));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[2U][0U] 
        = ((0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [2U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[2U][0U] 
        = ((1U & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [2U][0U]) | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                          ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                     [2U][3U] 
                                                     >> 0x0000000cU))
                                                  ? 
                                                 vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[0U]
                                                  : 
                                                 vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[2U][1U] 
        = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
             ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                            & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                               [2U][3U] >> 0x0000000cU))
                            ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[1U]
                            : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
           | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
               ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                          [2U][3U] 
                                          >> 0x0000000cU))
                                       ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[1U]
                                       : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[2U][2U] 
        = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
             ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                            & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                               [2U][3U] >> 0x0000000cU))
                            ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[2U]
                            : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
           | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
               ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                          [2U][3U] 
                                          >> 0x0000000cU))
                                       ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[2U]
                                       : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[2U][3U] 
        = ((0x00001000U & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [2U][3U]) | (0x00001fffU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                          ? 0U : (1U 
                                                  & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                      & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                         [2U][3U] 
                                                         >> 0x0000000cU))
                                                      ? 
                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[3U]
                                                      : 
                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                        | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                            ? 0U : 
                                           (0x00000ffeU 
                                            & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                   [2U][3U] 
                                                   >> 0x0000000cU))
                                                ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[3U]
                                                : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[2U][3U] 
        = ((0x00000fffU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [2U][3U]) | (0x00001fffU & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__rvalid_o) 
                                        << 0x0000000cU)));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[3U][0U] 
        = ((0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [3U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[3U][0U] 
        = ((1U & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [3U][0U]) | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                          ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                     [3U][3U] 
                                                     >> 0x0000000cU))
                                                  ? 
                                                 vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[0U]
                                                  : 
                                                 vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[3U][1U] 
        = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
             ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                            & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                               [3U][3U] >> 0x0000000cU))
                            ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[1U]
                            : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
           | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
               ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                          [3U][3U] 
                                          >> 0x0000000cU))
                                       ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[1U]
                                       : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[3U][2U] 
        = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
             ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                            & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                               [3U][3U] >> 0x0000000cU))
                            ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[2U]
                            : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
           | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
               ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                          [3U][3U] 
                                          >> 0x0000000cU))
                                       ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[2U]
                                       : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[3U][3U] 
        = ((0x00001000U & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [3U][3U]) | (0x00001fffU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                          ? 0U : (1U 
                                                  & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                      & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                         [3U][3U] 
                                                         >> 0x0000000cU))
                                                      ? 
                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[3U]
                                                      : 
                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                        | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                            ? 0U : 
                                           (0x00000ffeU 
                                            & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                   [3U][3U] 
                                                   >> 0x0000000cU))
                                                ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[3U]
                                                : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[3U][3U] 
        = ((0x00000fffU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [3U][3U]) | (0x00001fffU & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__rvalid_o) 
                                        << 0x0000000cU)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wready_o) 
                  & (IData)(((0x00060000U == (0x00060000U 
                                              & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                             & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                 | (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wready_o) 
                     & (IData)(((0x00040000U == (0x00060000U 
                                                 & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                    | (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wready_o) 
                        & (IData)(((0x00020000U == 
                                    (0x00060000U & 
                                     vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                   & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                       | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wready_o) 
                          & (IData)(((0U == (0x00060000U 
                                             & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                     & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))))))));
    vlSelfRef.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
        = (((QData)((IData)((0x000000ffU & ((vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U] 
                                             << 7U) 
                                            | (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
                                               >> 0x00000019U))))) 
            << 0x00000037U) | (((QData)((IData)((0x0000003fU 
                                                 & (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
                                                    >> 0x00000013U)))) 
                                << 0x0000002fU) | (0x00007fffffffffffULL 
                                                   & (((QData)((IData)(
                                                                       vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                                       << 0x0000001eU) 
                                                      | ((QData)((IData)(
                                                                         vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])) 
                                                         >> 2U)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3 = ((1U 
                                                 == 
                                                 (7U 
                                                  & ((vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U] 
                                                      << 2U) 
                                                     | (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
                                                        >> 0x0000001eU))))
                                                 ? 
                                                ((vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
                                                  << 0x00000010U) 
                                                 | (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U] 
                                                    >> 0x00000010U))
                                                 : 0U);
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[0U][0U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [0U][0U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[0U][1U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [0U][1U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[0U][2U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [0U][2U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[0U][3U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [0U][3U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[1U][0U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [1U][0U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[1U][1U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [1U][1U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[1U][2U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [1U][2U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[1U][3U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [1U][3U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[2U][0U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [2U][0U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[2U][1U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [2U][1U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[2U][2U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [2U][2U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[2U][3U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [2U][3U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[3U][0U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [3U][0U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[3U][1U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [3U][1U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[3U][2U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [3U][2U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[3U][3U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [3U][3U];
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[0U] = 0U;
    vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U] = 0U;
    vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U] = 0U;
    vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U] = 0U;
    if ((1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[0U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [0U][0U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [0U][1U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [0U][2U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [0U][3U];
    }
    if ((2U & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[0U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [1U][0U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [1U][1U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [1U][2U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [1U][3U];
    }
    if ((4U & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[0U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [2U][0U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [2U][1U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [2U][2U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [2U][3U];
    }
    if ((8U & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[0U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [3U][0U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [3U][1U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [3U][2U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [3U][3U];
    }
    vlSelfRef.tlul_socket_m1__02Etl_d_o[0U] = ((0xfffffffeU 
                                                & vlSelfRef.tlul_socket_m1__02Etl_d_o[0U]) 
                                               | (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[0U] = ((1U 
                                                & vlSelfRef.tlul_socket_m1__02Etl_d_o[0U]) 
                                               | ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (0xfffffffeU 
                                                   & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                       & (0U 
                                                          != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)))
                                                       ? 
                                                      (0xfffffffeU 
                                                       & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[0U])
                                                       : 
                                                      vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[1U] = (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                 ? 0U
                                                 : 
                                                (1U 
                                                 & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (0U 
                                                        != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)))
                                                     ? 
                                                    ((1U 
                                                      & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U]) 
                                                     | (0xfffffffeU 
                                                        & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U]))
                                                     : 
                                                    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
                                               | ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (0xfffffffeU 
                                                   & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                       & (0U 
                                                          != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)))
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U]) 
                                                       | (0xfffffffeU 
                                                          & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U]))
                                                       : 
                                                      vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[2U] = (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                 ? 0U
                                                 : 
                                                (1U 
                                                 & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (0U 
                                                        != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)))
                                                     ? 
                                                    ((1U 
                                                      & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U]) 
                                                     | (0xfffffffeU 
                                                        & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U]))
                                                     : 
                                                    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
                                               | ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (0xfffffffeU 
                                                   & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                       & (0U 
                                                          != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)))
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U]) 
                                                       | (0xfffffffeU 
                                                          & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U]))
                                                       : 
                                                      vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[3U] = ((0x00001000U 
                                                & vlSelfRef.tlul_socket_m1__02Etl_d_o[3U]) 
                                               | (0x00001fffU 
                                                  & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (1U 
                                                       & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (0U 
                                                              != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)))
                                                           ? 
                                                          ((1U 
                                                            & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U]) 
                                                           | (0x00000ffeU 
                                                              & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U]))
                                                           : 
                                                          vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                                     | ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                         ? 0U
                                                         : 
                                                        (0x00000ffeU 
                                                         & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                             & (0U 
                                                                != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)))
                                                             ? 
                                                            ((1U 
                                                              & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U]) 
                                                             | (0x00000ffeU 
                                                                & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U]))
                                                             : 
                                                            vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[3U] = ((0x00000fffU 
                                                & vlSelfRef.tlul_socket_m1__02Etl_d_o[3U]) 
                                               | (0x00001fffU 
                                                  & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o) 
                                                     << 0x0000000cU)));
}

void Vtop_pkg___024root___nba_comb__TOP__4(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_comb__TOP__4\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_socket_m1__02Etl_h_o[0U][0U] = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [0U][0U]) 
                                                   | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[0U][0U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [0U][0U]) 
                                                   | ((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                << 0x0000003fU) 
                                                               | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                   << 0x0000001fU) 
                                                                  | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                     >> 1U)))) 
                                                      << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[0U][1U] = (
                                                   ((IData)(
                                                            (((QData)((IData)(
                                                                              ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                ? 0U
                                                                                : 
                                                                               (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                              << 0x0000003fU) 
                                                             | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                 << 0x0000001fU) 
                                                                | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                   >> 1U)))) 
                                                    >> 0x0000001fU) 
                                                   | ((IData)(
                                                              ((((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                 << 0x0000003fU) 
                                                                | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                    << 0x0000001fU) 
                                                                   | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                      >> 1U))) 
                                                               >> 0x00000020U)) 
                                                      << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[0U][2U] = (
                                                   (2U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [0U][2U]) 
                                                   | (3U 
                                                      & ((IData)(
                                                                 ((((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                    << 0x0000003fU) 
                                                                   | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                       << 0x0000001fU) 
                                                                      | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                         >> 1U))) 
                                                                  >> 0x00000020U)) 
                                                         >> 0x0000001fU)));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[0U][2U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [0U][2U]) 
                                                   | (3U 
                                                      & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__rvalid_o) 
                                                         << 1U)));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[1U][0U] = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [1U][0U]) 
                                                   | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[1U][0U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [1U][0U]) 
                                                   | ((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                << 0x0000003fU) 
                                                               | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                   << 0x0000001fU) 
                                                                  | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                     >> 1U)))) 
                                                      << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[1U][1U] = (
                                                   ((IData)(
                                                            (((QData)((IData)(
                                                                              ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                ? 0U
                                                                                : 
                                                                               (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                              << 0x0000003fU) 
                                                             | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                 << 0x0000001fU) 
                                                                | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                   >> 1U)))) 
                                                    >> 0x0000001fU) 
                                                   | ((IData)(
                                                              ((((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                 << 0x0000003fU) 
                                                                | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                    << 0x0000001fU) 
                                                                   | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                      >> 1U))) 
                                                               >> 0x00000020U)) 
                                                      << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[1U][2U] = (
                                                   (2U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [1U][2U]) 
                                                   | (3U 
                                                      & ((IData)(
                                                                 ((((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                    << 0x0000003fU) 
                                                                   | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                       << 0x0000001fU) 
                                                                      | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                         >> 1U))) 
                                                                  >> 0x00000020U)) 
                                                         >> 0x0000001fU)));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[1U][2U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [1U][2U]) 
                                                   | (3U 
                                                      & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__rvalid_o) 
                                                         << 1U)));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[2U][0U] = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [2U][0U]) 
                                                   | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[2U][0U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [2U][0U]) 
                                                   | ((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                << 0x0000003fU) 
                                                               | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                   << 0x0000001fU) 
                                                                  | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                     >> 1U)))) 
                                                      << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[2U][1U] = (
                                                   ((IData)(
                                                            (((QData)((IData)(
                                                                              ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                ? 0U
                                                                                : 
                                                                               (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                              << 0x0000003fU) 
                                                             | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                 << 0x0000001fU) 
                                                                | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                   >> 1U)))) 
                                                    >> 0x0000001fU) 
                                                   | ((IData)(
                                                              ((((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                 << 0x0000003fU) 
                                                                | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                    << 0x0000001fU) 
                                                                   | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                      >> 1U))) 
                                                               >> 0x00000020U)) 
                                                      << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[2U][2U] = (
                                                   (2U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [2U][2U]) 
                                                   | (3U 
                                                      & ((IData)(
                                                                 ((((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                    << 0x0000003fU) 
                                                                   | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                       << 0x0000001fU) 
                                                                      | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                         >> 1U))) 
                                                                  >> 0x00000020U)) 
                                                         >> 0x0000001fU)));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[2U][2U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [2U][2U]) 
                                                   | (3U 
                                                      & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__rvalid_o) 
                                                         << 1U)));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[3U][0U] = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [3U][0U]) 
                                                   | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[3U][0U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [3U][0U]) 
                                                   | ((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                << 0x0000003fU) 
                                                               | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                   << 0x0000001fU) 
                                                                  | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                     >> 1U)))) 
                                                      << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[3U][1U] = (
                                                   ((IData)(
                                                            (((QData)((IData)(
                                                                              ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                ? 0U
                                                                                : 
                                                                               (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                              << 0x0000003fU) 
                                                             | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                 << 0x0000001fU) 
                                                                | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                   >> 1U)))) 
                                                    >> 0x0000001fU) 
                                                   | ((IData)(
                                                              ((((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                 << 0x0000003fU) 
                                                                | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                    << 0x0000001fU) 
                                                                   | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                      >> 1U))) 
                                                               >> 0x00000020U)) 
                                                      << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[3U][2U] = (
                                                   (2U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [3U][2U]) 
                                                   | (3U 
                                                      & ((IData)(
                                                                 ((((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                    << 0x0000003fU) 
                                                                   | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                       << 0x0000001fU) 
                                                                      | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                         >> 1U))) 
                                                                  >> 0x00000020U)) 
                                                         >> 0x0000001fU)));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[3U][2U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [3U][2U]) 
                                                   | (3U 
                                                      & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__rvalid_o) 
                                                         << 1U)));
}

void Vtop_pkg___024root___nba_comb__TOP__5(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_comb__TOP__5\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_fifo_async__02Etl_h_o[0U] = ((0xfffffffeU 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_h_o[0U]) 
                                                | (IData)(vlSelfRef.tlul_fifo_async__DOT____Vcellout__reqfifo__wready_o));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[0U] = ((1U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_h_o[0U]) 
                                                | ((IData)(
                                                           ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                                             ? 0ULL
                                                             : 
                                                            vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                                            [
                                                            (3U 
                                                             & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))])) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[1U] = (((IData)(
                                                         ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                                           ? 0ULL
                                                           : 
                                                          vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                                          [
                                                          (3U 
                                                           & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))])) 
                                                 >> 0x0000001fU) 
                                                | ((IData)(
                                                           (((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                                              ? 0ULL
                                                              : 
                                                             vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                                             [
                                                             (3U 
                                                              & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))]) 
                                                            >> 0x00000020U)) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[2U] = ((2U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_h_o[2U]) 
                                                | (3U 
                                                   & ((IData)(
                                                              (((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                                                 ? 0ULL
                                                                 : 
                                                                vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                                                [
                                                                (3U 
                                                                 & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))]) 
                                                               >> 0x00000020U)) 
                                                      >> 0x0000001fU)));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[2U] = ((1U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_h_o[2U]) 
                                                | (2U 
                                                   & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)) 
                                                      << 1U)));
}

void Vtop_pkg___024root___nba_sequent__TOP__44(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__44\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_in = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_in = 0;
    // Body
    if (vlSelfRef.rst_h_ni) {
        if (vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr) {
            vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_q 
                = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_d;
        }
        if (vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr) {
            vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_q 
                = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_d;
        }
    } else {
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_q = 0U;
    }
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr 
        = (1U & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)) 
                 & vlSelfRef.tlul_fifo_async__02Etl_h_i[0U]));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_in));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__Vfuncout;
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT____Vcellout__reqfifo__wready_o) 
           & (vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
              >> 0x0000000cU));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_in));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval)));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__Vfuncout;
}

void Vtop_pkg___024root___nba_comb__TOP__6(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_comb__TOP__6\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_fifo_async__02Etl_d_o[0U] = ((0xfffffffeU 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_d_o[0U]) 
                                                | (IData)(vlSelfRef.tlul_fifo_async__DOT____Vcellout__rspfifo__wready_o));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[0U] = ((1U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_d_o[0U]) 
                                                | (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                     ? 0U
                                                     : 
                                                    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][0U]) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[1U] = ((((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                   ? 0U
                                                   : 
                                                  vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                  [
                                                  (3U 
                                                   & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][0U]) 
                                                 >> 0x0000001fU) 
                                                | (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                     ? 0U
                                                     : 
                                                    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][1U]) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[2U] = ((((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                   ? 0U
                                                   : 
                                                  vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                  [
                                                  (3U 
                                                   & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][1U]) 
                                                 >> 0x0000001fU) 
                                                | (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                     ? 0U
                                                     : 
                                                    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][2U]) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[3U] = ((0x00001000U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_d_o[3U]) 
                                                | (0x00001fffU 
                                                   & ((((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                         ? 0U
                                                         : 
                                                        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                        [
                                                        (3U 
                                                         & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][2U]) 
                                                       >> 0x0000001fU) 
                                                      | (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                           ? 0U
                                                           : 
                                                          vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                          [
                                                          (3U 
                                                           & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][3U]) 
                                                         << 1U))));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[3U] = ((0x00000fffU 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_d_o[3U]) 
                                                | (0x00001000U 
                                                   & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)) 
                                                      << 0x0000000cU)));
}

void Vtop_pkg___024root___nba_sequent__TOP__45(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__45\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_sub = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_in = 0;
    // Body
    if (vlSelfRef.prim_fifo_async_sram_adapter__02Erst_rd_ni) {
        if (vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_q 
                = vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_d;
        }
    } else {
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_q = 0U;
    }
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval 
        = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_sub 
        = (0x0000001fU & (((IData)(0x10U) - (0x0000000fU 
                                             & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval))) 
                          - (IData)(1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_in 
        = ((0x00000010U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval))
            ? (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_sub)
            : (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_in 
        = (0x0fU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_in));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__Vfuncout 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__Vfuncout 
        = (0x0000001fU & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__Vfuncout) 
                          ^ VL_SHIFTR_III(5,5,32, (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_in), 1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__Vfuncout 
        = ((0x0fU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__Vfuncout)) 
           | (0x00000010U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval)));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_d 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__Vfuncout;
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Erready_i) 
           & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__store_en 
        = ((~ ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) 
               ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))) 
           & (IData)(vlSelfRef.r_sram_rvalid_i));
    vlSelfRef.r_sram_req_o = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored)
                               ? ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT____VdfgRegularize_h1c658b81_0_1) 
                                  & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))
                               : ((~ ((IData)(vlSelfRef.r_sram_rvalid_i) 
                                      ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))) 
                                  & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT____VdfgRegularize_h1c658b81_0_1)));
}

void Vtop_pkg___024root___nba_sequent__TOP__46(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__46\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((~ (IData)(vlSelfRef.we_o)) & ((IData)(vlSelfRef.gnt_i) 
                                           & (IData)(vlSelfRef.req_o))) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__wready_o)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 != (2U ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
             >> 0x0000000cU) & (IData)(vlSelfRef.tlul_adapter_sram__DOT____VdfgRegularize_hb17975a6_0_0)) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__wready_o)));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
}

void Vtop_pkg___024root___nba_comb__TOP__7(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_comb__TOP__7\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ tlul_adapter_sram__DOT__d_valid;
    tlul_adapter_sram__DOT__d_valid = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__d_error;
    tlul_adapter_sram__DOT__d_error = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__vld_rd_rsp;
    tlul_adapter_sram__DOT__vld_rd_rsp = 0;
    QData/*39:0*/ tlul_adapter_sram__DOT____Vcellout__u_rspfifo__rdata_o;
    tlul_adapter_sram__DOT____Vcellout__u_rspfifo__rdata_o = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__u_reqfifo__DOT__rready_i;
    tlul_adapter_sram__DOT__u_reqfifo__DOT__rready_i = 0;
    // Body
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_sramreqfifo__rdata_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
            ? 0U : (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__storage));
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
            ? 0U : vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__storage);
    vlSelfRef.tlul_adapter_sram__DOT____Vcellinp__u_rspfifo__wdata_i 
        = (((QData)((IData)((vlSelfRef.rdata_i & ((
                                                   ((0x0000ff00U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & ((IData)(vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_sramreqfifo__rdata_o) 
                                                                       >> 4U)))) 
                                                        << 8U)) 
                                                    | (0x000000ffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & ((IData)(vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_sramreqfifo__rdata_o) 
                                                                        >> 3U)))))) 
                                                   << 0x00000010U) 
                                                  | ((0x0000ff00U 
                                                      & ((- (IData)(
                                                                    (1U 
                                                                     & ((IData)(vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_sramreqfifo__rdata_o) 
                                                                        >> 2U)))) 
                                                         << 8U)) 
                                                     | (0x000000ffU 
                                                        & (- (IData)(
                                                                     (1U 
                                                                      & ((IData)(vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_sramreqfifo__rdata_o) 
                                                                         >> 1U)))))))))) 
            << 8U) | (QData)((IData)((1U & ((IData)(vlSelfRef.rerror_i) 
                                            >> 1U)))));
    vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data 
        = (([&]() {
                vlSelfRef.__Vfunc_mubi4_test_true_strict__7__val 
                    = (0x0000000fU & (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                      >> 0x0000000aU));
                vlSelfRef.__Vfunc_mubi4_test_true_strict__7__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__7__val));
            }(), (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__7__Vfuncout))
            ? 0U : 0xffffffffU);
    tlul_adapter_sram__DOT__d_valid = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__rvalid_o) 
                                       & (IData)(((0x00008000U 
                                                   != 
                                                   (0x0001c000U 
                                                    & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o)) 
                                                  | (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__rvalid_o))));
    tlul_adapter_sram__DOT____Vcellout__u_rspfifo__rdata_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty)
            ? 0ULL : (((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                       & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__wvalid_i))
                       ? vlSelfRef.tlul_adapter_sram__DOT____Vcellinp__u_rspfifo__wdata_i
                       : vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage));
    tlul_adapter_sram__DOT__vld_rd_rsp = ((IData)(tlul_adapter_sram__DOT__d_valid) 
                                          & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__rvalid_o) 
                                             & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__rvalid_o) 
                                                & (0x00008000U 
                                                   == 
                                                   (0x00018000U 
                                                    & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o)))));
    tlul_adapter_sram__DOT__u_reqfifo__DOT__rready_i 
        = ((IData)(tlul_adapter_sram__DOT__d_valid) 
           & vlSelfRef.tlul_adapter_sram__02Etl_i[0U]);
    tlul_adapter_sram__DOT__d_error = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__rvalid_o) 
                                       & ((1U == (3U 
                                                  & (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                                     >> 0x0000000fU)))
                                           ? ((IData)(tlul_adapter_sram__DOT____Vcellout__u_rspfifo__rdata_o) 
                                              | (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                                 >> 0x0000000eU))
                                           : (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                              >> 0x0000000eU)));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(tlul_adapter_sram__DOT__u_reqfifo__DOT__rready_i)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(((0x00008000U == (0x0001c000U 
                                          & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o)) 
                         & (IData)(tlul_adapter_sram__DOT__u_reqfifo__DOT__rready_i)))));
    vlSelfRef.tlul_adapter_sram__02Etl_o[0U] = (IData)(
                                                       (((QData)((IData)(
                                                                         ((IData)(tlul_adapter_sram__DOT__d_valid)
                                                                           ? 
                                                                          (3U 
                                                                           & (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                                                              >> 8U))
                                                                           : 0U))) 
                                                         << 0x00000039U) 
                                                        | (((QData)((IData)(
                                                                            ((IData)(tlul_adapter_sram__DOT__d_valid)
                                                                              ? 
                                                                             (0x000000ffU 
                                                                              & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o)
                                                                              : 0U))) 
                                                            << 0x00000031U) 
                                                           | (((QData)((IData)(
                                                                               (((~ (IData)(tlul_adapter_sram__DOT__d_error)) 
                                                                                & (IData)(tlul_adapter_sram__DOT__vld_rd_rsp))
                                                                                 ? (IData)(
                                                                                (tlul_adapter_sram__DOT____Vcellout__u_rspfifo__rdata_o 
                                                                                >> 8U))
                                                                                 : vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data))) 
                                                               << 0x00000010U) 
                                                              | (QData)((IData)(
                                                                                (((((IData)(tlul_adapter_sram__DOT__vld_rd_rsp) 
                                                                                & (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                                                                >> 0x0000000eU))
                                                                                 ? 0x0000002aU
                                                                                 : 
                                                                                ((IData)(tlul_adapter_sram__DOT__vld_rd_rsp)
                                                                                 ? 
                                                                                (0x0000007fU 
                                                                                & (IData)(
                                                                                (tlul_adapter_sram__DOT____Vcellout__u_rspfifo__rdata_o 
                                                                                >> 1U)))
                                                                                 : 0x0000002aU)) 
                                                                                << 2U) 
                                                                                | ((((IData)(tlul_adapter_sram__DOT__d_error) 
                                                                                & (IData)(tlul_adapter_sram__DOT__d_valid)) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelfRef.tlul_adapter_sram__DOT____VdfgRegularize_hb17975a6_0_0)))))))));
    vlSelfRef.tlul_adapter_sram__02Etl_o[1U] = ((0xc0000000U 
                                                 & vlSelfRef.tlul_adapter_sram__02Etl_o[1U]) 
                                                | (IData)(
                                                          ((((QData)((IData)(
                                                                             ((IData)(tlul_adapter_sram__DOT__d_valid)
                                                                               ? 
                                                                              (3U 
                                                                               & (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                                                                >> 8U))
                                                                               : 0U))) 
                                                             << 0x00000039U) 
                                                            | (((QData)((IData)(
                                                                                ((IData)(tlul_adapter_sram__DOT__d_valid)
                                                                                 ? 
                                                                                (0x000000ffU 
                                                                                & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o)
                                                                                 : 0U))) 
                                                                << 0x00000031U) 
                                                               | (((QData)((IData)(
                                                                                (((~ (IData)(tlul_adapter_sram__DOT__d_error)) 
                                                                                & (IData)(tlul_adapter_sram__DOT__vld_rd_rsp))
                                                                                 ? (IData)(
                                                                                (tlul_adapter_sram__DOT____Vcellout__u_rspfifo__rdata_o 
                                                                                >> 8U))
                                                                                 : vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data))) 
                                                                   << 0x00000010U) 
                                                                  | (QData)((IData)(
                                                                                (((((IData)(tlul_adapter_sram__DOT__vld_rd_rsp) 
                                                                                & (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                                                                >> 0x0000000eU))
                                                                                 ? 0x0000002aU
                                                                                 : 
                                                                                ((IData)(tlul_adapter_sram__DOT__vld_rd_rsp)
                                                                                 ? 
                                                                                (0x0000007fU 
                                                                                & (IData)(
                                                                                (tlul_adapter_sram__DOT____Vcellout__u_rspfifo__rdata_o 
                                                                                >> 1U)))
                                                                                 : 0x0000002aU)) 
                                                                                << 2U) 
                                                                                | ((((IData)(tlul_adapter_sram__DOT__d_error) 
                                                                                & (IData)(tlul_adapter_sram__DOT__d_valid)) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelfRef.tlul_adapter_sram__DOT____VdfgRegularize_hb17975a6_0_0)))))))) 
                                                           >> 0x00000020U)));
    vlSelfRef.tlul_adapter_sram__02Etl_o[1U] = ((0x3fffffffU 
                                                 & vlSelfRef.tlul_adapter_sram__02Etl_o[1U]) 
                                                | ((((IData)(tlul_adapter_sram__DOT__d_valid) 
                                                     & (1U 
                                                        != 
                                                        (3U 
                                                         & (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                                            >> 0x0000000fU))))
                                                     ? 0U
                                                     : 1U) 
                                                   << 0x0000001eU));
    vlSelfRef.tlul_adapter_sram__02Etl_o[2U] = ((2U 
                                                 & vlSelfRef.tlul_adapter_sram__02Etl_o[2U]) 
                                                | (3U 
                                                   & ((((IData)(tlul_adapter_sram__DOT__d_valid) 
                                                        & (1U 
                                                           != 
                                                           (3U 
                                                            & (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                                               >> 0x0000000fU))))
                                                        ? 0U
                                                        : 1U) 
                                                      >> 2U)));
    vlSelfRef.tlul_adapter_sram__02Etl_o[2U] = ((1U 
                                                 & vlSelfRef.tlul_adapter_sram__02Etl_o[2U]) 
                                                | (3U 
                                                   & ((IData)(tlul_adapter_sram__DOT__d_valid) 
                                                      << 1U)));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg___024root___nba_sequent__TOP__47(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__47\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake;
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake = 0;
    // Body
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_q 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni) 
           && (1U & ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs)
                      ? (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_req))
                      : (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_req))));
    vlSelfRef.prim_fifo_async_simple__DOT__src_req 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i) 
           | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns));
    if ((1U & (~ VL_ONEHOT_I((((IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) 
                               << 1U) | (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs)))))))) {
        if ((0U != (((IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) 
                     << 1U) | (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs)))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: prim_sync_reqack.sv:225: Assertion failed in %Nprim_fifo_async_simple.u_prim_sync_reqack.gen_nrz_hs_protocol.src_fsm: unique case, but multiple matches found for '1'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name(),1,
                             (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs));
                VL_STOP_MT("/home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_sync_reqack.sv", 225, "");
            }
        }
    }
    vlSelfRef.prim_fifo_async_simple__DOT__src_ack 
        = (1U & ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs)
                  ? (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack))
                  : (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack)));
    vlSelfRef.prim_fifo_async_simple__DOT__pending_d 
        = ((~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack)) 
           & ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__wr_en) 
              | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q)));
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_req));
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 1U;
        if (prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 0U;
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 0U;
        if (prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 1U;
        }
    }
}

void Vtop_pkg___024root___nba_sequent__TOP__0(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__1(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__2(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__3(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__4(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__5(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__6(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__7(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__8(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__9(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__10(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__11(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__12(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__13(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__14(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__15(Vtop_pkg___024root* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__16(Vtop_pkg___024root* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__17(Vtop_pkg___024root* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__18(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__19(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__20(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__21(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__22(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__23(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__24(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__25(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__26(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__27(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__28(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__29(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__30(Vtop_pkg___024root* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__2(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__31(Vtop_pkg___024root* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__2(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__32(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__33(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__34(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__35(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__36(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__37(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__38(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_comb__TOP__0(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__39(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__40(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__41(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___nba_sequent__TOP__42(Vtop_pkg___024root* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__3(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__3(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__3(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__3(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg___024root___nba_comb__TOP__1(Vtop_pkg___024root* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__3(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__3(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__3(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__3(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);

void Vtop_pkg___024root___eval_nba(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval_nba\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x0000000000060000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x0000000000000040ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0x0000030000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x00000c0000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((0x0000000000001800ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__6(vlSelf);
    }
    if ((0x0000000000006000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__7(vlSelf);
    }
    if ((0x0000000c00000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__8(vlSelf);
    }
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__9(vlSelf);
    }
    if ((0x0004000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__10(vlSelf);
    }
    if ((0x0010000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__11(vlSelf);
    }
    if ((0x0000000000600000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__12(vlSelf);
    }
    if ((0x0003000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__13(vlSelf);
    }
    if ((0x0000000000a00000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__14(vlSelf);
    }
    if ((0x0300000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__15(vlSelf);
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
        Vtop_pkg___024root___nba_sequent__TOP__16(vlSelf);
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
    }
    if ((0x00c0000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d));
        Vtop_pkg___024root___nba_sequent__TOP__17(vlSelf);
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__1((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__1((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__1((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__1((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d));
    }
    if ((0x0000000000000020ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__18(vlSelf);
    }
    if ((0x0000000000000600ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__19(vlSelf);
    }
    if ((0x0000000000000180ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__20(vlSelf);
    }
    if ((0x0000000010000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__21(vlSelf);
    }
    if ((0x0000000000180000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__22(vlSelf);
    }
    if ((0x0000003000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__23(vlSelf);
    }
    if ((0x000000c000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__24(vlSelf);
    }
    if ((0x000000000c000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__25(vlSelf);
    }
    if ((0x0000000030000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__26(vlSelf);
    }
    if ((0x0000000000018000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__27(vlSelf);
    }
    if ((0x0000c00000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__28(vlSelf);
    }
    if ((0x0000000003000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__29(vlSelf);
    }
    if ((0x0040000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__30(vlSelf);
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__2((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__2((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__2((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__2((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d));
    }
    if ((0x0100000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__31(vlSelf);
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__2((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__2((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__2((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__2((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
    }
    if ((0x0c00000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__32(vlSelf);
    }
    if ((0x000c000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__33(vlSelf);
    }
    if ((0x0030000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__34(vlSelf);
    }
    if ((0x0000000300000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__35(vlSelf);
    }
    if ((0x0001000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__36(vlSelf);
    }
    if ((0x0000300000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__37(vlSelf);
    }
    if ((0x00000000c0000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__38(vlSelf);
    }
    if ((0x00000f0000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x0000030000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__39(vlSelf);
    }
    if ((0x0000000000001800ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__40(vlSelf);
    }
    if ((0x0000000000600000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__41(vlSelf);
    }
    if ((0x00c0000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__42(vlSelf);
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__3((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__3((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__3((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__3((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d));
    }
    if ((0x00c0000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_comb__TOP__1(vlSelf);
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d));
        Vtop_pkg___024root___nba_comb__TOP__2(vlSelf);
    }
    if ((0x0300000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__43(vlSelf);
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__3((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__3((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__3((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__3((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
    }
    if ((0x0300000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_comb__TOP__3(vlSelf);
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
        Vtop_pkg___024root___nba_comb__TOP__4(vlSelf);
    }
    if ((0x001c000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_comb__TOP__5(vlSelf);
    }
    if ((0x000c000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__44(vlSelf);
    }
    if ((0x0034000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_comb__TOP__6(vlSelf);
    }
    if ((0x0000000c00000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__45(vlSelf);
    }
    if ((0x0003000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__46(vlSelf);
    }
    if ((0x0003000000000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_comb__TOP__7(vlSelf);
    }
    if ((0x0000000030000000ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop_pkg___024root___nba_sequent__TOP__47(vlSelf);
    }
}

void Vtop_pkg___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vtop_pkg___024root___eval_triggers__act(Vtop_pkg___024root* vlSelf);

bool Vtop_pkg___024root___eval_phase__act(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval_phase__act\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_pkg___024root___eval_triggers__act(vlSelf);
    Vtop_pkg___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop_pkg___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop_pkg___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

bool Vtop_pkg___024root___eval_phase__nba(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval_phase__nba\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop_pkg___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop_pkg___024root___eval_nba(vlSelf);
        Vtop_pkg___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_pkg___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vtop_pkg___024root___eval_phase__ico(Vtop_pkg___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_pkg___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop_pkg___024root___eval(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtop_pkg___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/eneadim/github/flexsoc/hw/ips/prim/prim_clk_div.sv", 5, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop_pkg___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop_pkg___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/eneadim/github/flexsoc/hw/ips/prim/prim_clk_div.sv", 5, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop_pkg___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/eneadim/github/flexsoc/hw/ips/prim/prim_clk_div.sv", 5, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtop_pkg___024root___eval_phase__act(vlSelf));
    } while (Vtop_pkg___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtop_pkg___024root___eval_debug_assertions(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval_debug_assertions\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.prim_clk_div__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_clk_div.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_clk_div__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_clk_div.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.testmode_i & 0xfeU)))) {
        Verilated::overWidthError("testmode_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_clk_div__02Een_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_clk_div.en_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_clk_gate__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_clk_gate.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_clk_gate__02Een_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_clk_gate.en_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.test_en_i & 0xfeU)))) {
        Verilated::overWidthError("test_en_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.A & 0xf8U)))) {
        Verilated::overWidthError("A");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_lifo__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_lifo.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_lifo__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_lifo.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_lifo__02Ewvalid_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_lifo.wvalid_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_lifo__02Erready_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_lifo.rready_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_ram__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_ram.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_ram__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_ram.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_ram__02Een_i & 0xfeU)))) {
        Verilated::overWidthError("prim_ram.en_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_ram__02Ewe_i & 0xfeU)))) {
        Verilated::overWidthError("prim_ram.we_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_rom__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_rom.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_rom__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_rom.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_shreg__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_shreg.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_shreg__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_shreg.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_shreg__02Een_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_shreg.en_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_shreg__02Eserial_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_shreg.serial_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_cdc_rand_delay__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_cdc_rand_delay.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_cdc_rand_delay__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_cdc_rand_delay.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.prev_data_i & 0xfeU)))) {
        Verilated::overWidthError("prev_data_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_cdc_rand_delay__02Esrc_data_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_cdc_rand_delay.src_data_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_intr_hw__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_intr_hw.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_intr_hw__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_intr_hw.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.event_intr_i & 0xfeU)))) {
        Verilated::overWidthError("event_intr_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.reg2hw_intr_enable_q_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("reg2hw_intr_enable_q_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.reg2hw_intr_test_q_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("reg2hw_intr_test_q_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.reg2hw_intr_test_qe_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("reg2hw_intr_test_qe_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.reg2hw_intr_state_q_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("reg2hw_intr_state_q_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.src_clk_i & 0xfeU)))) {
        Verilated::overWidthError("src_clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.src_rst_ni & 0xfeU)))) {
        Verilated::overWidthError("src_rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.cdc_2phase__02Esrc_data_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("cdc_2phase.src_data_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.src_valid_i & 0xfeU)))) {
        Verilated::overWidthError("src_valid_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.dst_clk_i & 0xfeU)))) {
        Verilated::overWidthError("dst_clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.dst_rst_ni & 0xfeU)))) {
        Verilated::overWidthError("dst_rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.dst_ready_i & 0xfeU)))) {
        Verilated::overWidthError("dst_ready_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_counter__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_counter.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_counter__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_counter.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_counter__02Een_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_counter.en_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.clr_i & 0xfeU)))) {
        Verilated::overWidthError("clr_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.up_down_i & 0xfeU)))) {
        Verilated::overWidthError("up_down_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.step_i & 0xf0U)))) {
        Verilated::overWidthError("step_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.tc_val_i & 0xf0U)))) {
        Verilated::overWidthError("tc_val_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_deglitch__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_deglitch.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_deglitch__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_deglitch.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_deglitch__02Een_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_deglitch.en_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.d_i & 0xfeU)))) {
        Verilated::overWidthError("d_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_edge_detect__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_edge_detect.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_edge_detect__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_edge_detect.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_edge_detect__02Een_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_edge_detect.en_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_edge_detect__02Eserial_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_edge_detect.serial_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.rd_clk_i & 0xfeU)))) {
        Verilated::overWidthError("rd_clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.wr_clk_i & 0xfeU)))) {
        Verilated::overWidthError("wr_clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo__02Ewvalid_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo.wvalid_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo__02Erready_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo.rready_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_reg__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_reg.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_reg__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_reg.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.we & 0xfeU)))) {
        Verilated::overWidthError("we");
    }
    if (VL_UNLIKELY(((vlSelfRef.de & 0xfeU)))) {
        Verilated::overWidthError("de");
    }
    if (VL_UNLIKELY(((vlSelfRef.rrarbiter__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("rrarbiter.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.rrarbiter__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("rrarbiter.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.flush_i & 0xfeU)))) {
        Verilated::overWidthError("flush_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.rrarbiter__02Een_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("rrarbiter.en_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.rrarbiter__02Ereq_i 
                      & 0xe000U)))) {
        Verilated::overWidthError("rrarbiter.req_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Eclk_wr_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.clk_wr_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.rst_wr_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Ewvalid_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.wvalid_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Eclk_rd_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.clk_rd_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.rst_rd_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Erready_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.rready_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_wr_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.clk_wr_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Erst_wr_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.rst_wr_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.wvalid_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_rd_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.clk_rd_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Erst_rd_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.rst_rd_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Erready_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.rready_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.w_sram_gnt_i & 0xfeU)))) {
        Verilated::overWidthError("w_sram_gnt_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.w_sram_rvalid_i & 0xfeU)))) {
        Verilated::overWidthError("w_sram_rvalid_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.w_sram_rerror_i & 0xfcU)))) {
        Verilated::overWidthError("w_sram_rerror_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.r_sram_gnt_i & 0xfeU)))) {
        Verilated::overWidthError("r_sram_gnt_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.r_sram_rvalid_i & 0xfeU)))) {
        Verilated::overWidthError("r_sram_rvalid_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.r_sram_rerror_i & 0xfcU)))) {
        Verilated::overWidthError("r_sram_rerror_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_filter__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_filter__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_filter__02Eenable_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter.enable_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_filter__02Efilter_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter.filter_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_filter_ctr__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter_ctr.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_filter_ctr__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter_ctr.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_filter_ctr__02Eenable_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter_ctr.enable_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_filter_ctr__02Efilter_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter_ctr.filter_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.thresh_i & 0xfcU)))) {
        Verilated::overWidthError("thresh_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.clk_src_i & 0xfeU)))) {
        Verilated::overWidthError("clk_src_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_src_ni & 0xfeU)))) {
        Verilated::overWidthError("rst_src_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.clk_dst_i & 0xfeU)))) {
        Verilated::overWidthError("clk_dst_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_dst_ni & 0xfeU)))) {
        Verilated::overWidthError("rst_dst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.src_regwen_i & 0xfeU)))) {
        Verilated::overWidthError("src_regwen_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.src_we_i & 0xfeU)))) {
        Verilated::overWidthError("src_we_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.src_re_i & 0xfeU)))) {
        Verilated::overWidthError("src_re_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.dst_update_i & 0xfeU)))) {
        Verilated::overWidthError("dst_update_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_reg_we_check__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_reg_we_check.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_reg_we_check__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_reg_we_check.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_reg_we_check__02Een_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_reg_we_check.en_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_alert_sender__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_alert_sender.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.prim_alert_sender__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_alert_sender.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.alert_test_i & 0xfeU)))) {
        Verilated::overWidthError("alert_test_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.alert_req_i & 0xfeU)))) {
        Verilated::overWidthError("alert_req_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.sram2tlul__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("sram2tlul.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.sram2tlul__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("sram2tlul.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.mem_req_i & 0xfeU)))) {
        Verilated::overWidthError("mem_req_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.mem_write_i & 0xfeU)))) {
        Verilated::overWidthError("mem_write_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.mem_addr_i & 0xf000U)))) {
        Verilated::overWidthError("mem_addr_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_host__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_adapter_host.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_host__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_adapter_host.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_host__02Ereq_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_adapter_host.req_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_host__02Ewe_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_adapter_host.we_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.wdata_intg_i & 0x80U)))) {
        Verilated::overWidthError("wdata_intg_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.be_i & 0xf0U)))) {
        Verilated::overWidthError("be_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.instr_type_i & 0xf0U)))) {
        Verilated::overWidthError("instr_type_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_sram__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_adapter_sram.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_sram__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_adapter_sram.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.en_ifetch_i & 0xf0U)))) {
        Verilated::overWidthError("en_ifetch_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.gnt_i & 0xfeU)))) {
        Verilated::overWidthError("gnt_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.rvalid_i & 0xfeU)))) {
        Verilated::overWidthError("rvalid_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.rerror_i & 0xfcU)))) {
        Verilated::overWidthError("rerror_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.readback_en_i & 0xf0U)))) {
        Verilated::overWidthError("readback_en_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.wr_collision_i & 0xfeU)))) {
        Verilated::overWidthError("wr_collision_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.write_pending_i & 0xfeU)))) {
        Verilated::overWidthError("write_pending_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.tlul_assert_multiple__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_assert_multiple.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.tlul_assert_multiple__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_assert_multiple.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.clk_h_i & 0xfeU)))) {
        Verilated::overWidthError("clk_h_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_h_ni & 0xfeU)))) {
        Verilated::overWidthError("rst_h_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.clk_d_i & 0xfeU)))) {
        Verilated::overWidthError("clk_d_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_d_ni & 0xfeU)))) {
        Verilated::overWidthError("rst_d_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_1n__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_socket_1n.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_1n__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_socket_1n.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.dev_select_i & 0xf8U)))) {
        Verilated::overWidthError("dev_select_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_m1__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_socket_m1.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_m1__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_socket_m1.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.my_ip__02Eclk_i & 0xfeU)))) {
        Verilated::overWidthError("my_ip.clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.my_ip__02Erst_ni & 0xfeU)))) {
        Verilated::overWidthError("my_ip.rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.port_i & 0xfeU)))) {
        Verilated::overWidthError("port_i");
    }
}
#endif  // VL_DEBUG
