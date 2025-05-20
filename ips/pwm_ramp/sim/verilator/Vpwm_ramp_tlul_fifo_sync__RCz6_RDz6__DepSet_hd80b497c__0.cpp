// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpwm_ramp.h for the primary calling header

#include "Vpwm_ramp__pch.h"
#include "Vpwm_ramp__Syms.h"
#include "Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6.h"

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[8U] 
            >> 7U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o)));
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
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[8U] 
               >> 7U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
            [0U][3U] >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                                 & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
               [0U][3U] >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
              [0U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
                 >> 6U)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
    __PVT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
    __PVT__rspfifo__DOT__full_o = 0;
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
    __PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    __PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[8U] 
               >> 7U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__1(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__1\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            = (0xfffffffeU & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
               [0U][0U]);
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = ((1U & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                [0U][1U]) | (0xfffffffeU & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                             [0U][1U]));
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = ((1U & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                [0U][2U]) | (0xfffffffeU & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                             [0U][2U]));
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
            = ((1U & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                [0U][3U]) | (0xffeU & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                             [0U][3U]));
    }
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__2(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__2\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[8U] 
            >> 7U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
            [0U][3U] >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                                 & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
              [0U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
               [0U][3U] >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
                 >> 6U)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
            >> 5U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o)));
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
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
               >> 5U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
            [1U][3U] >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                                 & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
               [1U][3U] >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
              [1U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U] 
                 >> 4U)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
    __PVT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
    __PVT__rspfifo__DOT__full_o = 0;
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
    __PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    __PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
               >> 5U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__1(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__1\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            = (0xfffffffeU & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
               [1U][0U]);
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = ((1U & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                [1U][1U]) | (0xfffffffeU & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                             [1U][1U]));
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = ((1U & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                [1U][2U]) | (0xfffffffeU & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                             [1U][2U]));
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
            = ((1U & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                [1U][3U]) | (0xffeU & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                             [1U][3U]));
    }
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__2(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__2\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
            >> 5U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
            [1U][3U] >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                                 & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
              [1U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
               [1U][3U] >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U] 
                 >> 4U)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U] 
            >> 3U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o)));
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
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U] 
               >> 3U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
            [2U][3U] >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                                 & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
               [2U][3U] >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
              [2U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U] 
                 >> 2U)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
    __PVT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
    __PVT__rspfifo__DOT__full_o = 0;
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
    __PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    __PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U] 
               >> 3U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__1(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__1\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            = (0xfffffffeU & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
               [2U][0U]);
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = ((1U & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                [2U][1U]) | (0xfffffffeU & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                             [2U][1U]));
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = ((1U & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                [2U][2U]) | (0xfffffffeU & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                             [2U][2U]));
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
            = ((1U & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                [2U][3U]) | (0xffeU & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                             [2U][3U]));
    }
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__2(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__2\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U] 
            >> 3U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
            [2U][3U] >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                                 & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
              [2U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
               [2U][3U] >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U] 
                 >> 2U)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o)));
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
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U] 
               >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
            [3U][3U] >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                                 & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
               [3U][3U] >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
              [3U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
    __PVT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
    __PVT__rspfifo__DOT__full_o = 0;
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
    __PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    __PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U] 
               >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__1(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__1\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            = (0xfffffffeU & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
               [3U][0U]);
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = ((1U & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                [3U][1U]) | (0xfffffffeU & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                             [3U][1U]));
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = ((1U & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                [3U][2U]) | (0xfffffffeU & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                             [3U][2U]));
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
            = ((1U & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                [3U][3U]) | (0xffeU & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
                             [3U][3U]));
    }
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__2(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__2\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
            [3U][3U] >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                                 & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
              [3U][0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__DOT__tl_u_o
               [3U][3U] >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[0U]));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_10;
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
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

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
              [0U][0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
            [0U][2U] >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o)));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (0xfffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                     [0U][0U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                            [0U][2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                              [0U][1U] 
                                                              >> 0x1eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                        [0U][1U] 
                                                        << 0x10U) 
                                                       | (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                          [0U][0U] 
                                                          >> 0x10U))
                                                       : 0U) 
                                                     << 0x10U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                            [0U][2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                              [0U][1U] 
                                                              >> 0x1eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                        [0U][1U] 
                                                        << 0x10U) 
                                                       | (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                          [0U][0U] 
                                                          >> 0x10U))
                                                       : 0U) 
                                                     >> 0x10U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (0xffff0000U 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                     [0U][1U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                  [0U][2U]);
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
               [0U][2U] >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
    __PVT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
    __PVT__rspfifo__DOT__full_o = 0;
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
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
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
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
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
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    __PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    __PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            = (0xfffffffeU & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U]);
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = ((1U & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]) 
               | (0xfffffffeU & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]));
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = ((1U & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]) 
               | (0xfffffffeU & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]));
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
            = ((1U & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]) 
               | (0xffeU & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]));
    }
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__2(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__2\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_10;
    // Body
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

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_10;
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
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

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
              [1U][0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
            [1U][2U] >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o)));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (0xfffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                     [1U][0U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                            [1U][2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                              [1U][1U] 
                                                              >> 0x1eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                        [1U][1U] 
                                                        << 0x10U) 
                                                       | (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                          [1U][0U] 
                                                          >> 0x10U))
                                                       : 0U) 
                                                     << 0x10U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                            [1U][2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                              [1U][1U] 
                                                              >> 0x1eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                        [1U][1U] 
                                                        << 0x10U) 
                                                       | (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                          [1U][0U] 
                                                          >> 0x10U))
                                                       : 0U) 
                                                     >> 0x10U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (0xffff0000U 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                     [1U][1U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                  [1U][2U]);
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
               [1U][2U] >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
    __PVT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
    __PVT__rspfifo__DOT__full_o = 0;
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
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
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
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
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
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    __PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    __PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            = (0xfffffffeU & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U]);
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = ((1U & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]) 
               | (0xfffffffeU & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]));
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = ((1U & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]) 
               | (0xfffffffeU & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]));
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
            = ((1U & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]) 
               | (0xffeU & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]));
    }
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__2(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__2\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_10;
    // Body
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

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_10;
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
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

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
              [2U][0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
            [2U][2U] >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o)));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (0xfffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                     [2U][0U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                            [2U][2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                              [2U][1U] 
                                                              >> 0x1eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                        [2U][1U] 
                                                        << 0x10U) 
                                                       | (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                          [2U][0U] 
                                                          >> 0x10U))
                                                       : 0U) 
                                                     << 0x10U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                            [2U][2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                              [2U][1U] 
                                                              >> 0x1eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                        [2U][1U] 
                                                        << 0x10U) 
                                                       | (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                          [2U][0U] 
                                                          >> 0x10U))
                                                       : 0U) 
                                                     >> 0x10U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (0xffff0000U 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                     [2U][1U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                  [2U][2U]);
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
               [2U][2U] >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
    __PVT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
    __PVT__rspfifo__DOT__full_o = 0;
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
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
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
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
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
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    __PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    __PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            = (0xfffffffeU & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U]);
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = ((1U & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]) 
               | (0xfffffffeU & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]));
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = ((1U & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]) 
               | (0xfffffffeU & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]));
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
            = ((1U & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]) 
               | (0xffeU & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]));
    }
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__2(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__2\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_10;
    // Body
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

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_10;
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
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

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
              [3U][0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
            [3U][2U] >> 1U) & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.__Vcellout__rspfifo__wready_o)));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (0xfffeU 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                     [3U][0U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U] = ((0xffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[0U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                            [3U][2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                              [3U][1U] 
                                                              >> 0x1eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                        [3U][1U] 
                                                        << 0x10U) 
                                                       | (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                          [3U][0U] 
                                                          >> 0x10U))
                                                       : 0U) 
                                                     << 0x10U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffff0000U 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (((1U 
                                                       == 
                                                       (7U 
                                                        & ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                            [3U][2U] 
                                                            << 2U) 
                                                           | (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                              [3U][1U] 
                                                              >> 0x1eU))))
                                                       ? 
                                                      ((vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                        [3U][1U] 
                                                        << 0x10U) 
                                                       | (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                          [3U][0U] 
                                                          >> 0x10U))
                                                       : 0U) 
                                                     >> 0x10U));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U] = ((0xffffU 
                                                   & vlSelfRef.__Vcellinp__rspfifo__wdata_i[1U]) 
                                                  | (0xffff0000U 
                                                     & vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                     [3U][1U]));
    vlSelfRef.__Vcellinp__rspfifo__wdata_i[2U] = (1U 
                                                  & vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
                                                  [3U][2U]);
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__hrsp_fifo_i
               [3U][2U] >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U]));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
    __PVT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
    __PVT__rspfifo__DOT__full_o = 0;
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
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
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
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
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
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    __PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    __PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   == (2U ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            = (0xfffffffeU & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U]);
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = ((1U & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]) 
               | (0xfffffffeU & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]));
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = ((1U & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]) 
               | (0xfffffffeU & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]));
        vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
            = ((1U & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]) 
               | (0xffeU & vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]));
    }
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__2(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__2\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.__Vcellout__reqfifo__wready_o)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_10;
    // Body
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
