// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_host_tb.h for the primary calling header

#include "Vspi_host_tb__pch.h"
#include "Vspi_host_tb__Syms.h"
#include "Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6.h"

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
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
                = (2U & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                         << 1U));
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
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             == (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             == (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__depth_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__full_o) 
                                              || (1U 
                                                  & (((1U 
                                                       & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                          >> 1U)) 
                                                      == 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                                          >> 1U)))
                                                      ? 
                                                     (([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__4__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__4__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__4__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__4__Vfuncout)) 
                                                      - 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__5__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__5__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__5__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__5__Vfuncout)))
                                                      : 
                                                     (((IData)(1U) 
                                                       - 
                                                       ([&]() {
                                vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__7__inp 
                                    = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__7__Vfuncout 
                                    = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__7__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__7__Vfuncout))) 
                                                      + 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__8__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__8__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__8__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__8__Vfuncout))))));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__depth_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__full_o) 
                                              || (1U 
                                                  & (((1U 
                                                       & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                          >> 1U)) 
                                                      == 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                                          >> 1U)))
                                                      ? 
                                                     (([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__13__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__13__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__13__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__13__Vfuncout)) 
                                                      - 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__14__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__14__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__14__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__14__Vfuncout)))
                                                      : 
                                                     (((IData)(1U) 
                                                       - 
                                                       ([&]() {
                                vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__16__inp 
                                    = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__16__Vfuncout 
                                    = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__16__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__16__Vfuncout))) 
                                                      + 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__17__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__17__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__17__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__17__Vfuncout))))));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[8U] 
               >> 7U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__1(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__1\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__2(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__2\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
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
                = (2U & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                         << 1U));
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
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             == (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             == (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__depth_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__full_o) 
                                              || (1U 
                                                  & (((1U 
                                                       & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                          >> 1U)) 
                                                      == 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                                          >> 1U)))
                                                      ? 
                                                     (([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__22__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__22__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__22__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__22__Vfuncout)) 
                                                      - 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__23__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__23__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__23__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__23__Vfuncout)))
                                                      : 
                                                     (((IData)(1U) 
                                                       - 
                                                       ([&]() {
                                vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__25__inp 
                                    = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__25__Vfuncout 
                                    = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__25__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__25__Vfuncout))) 
                                                      + 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__26__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__26__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__26__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__26__Vfuncout))))));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__depth_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__full_o) 
                                              || (1U 
                                                  & (((1U 
                                                       & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                          >> 1U)) 
                                                      == 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                                          >> 1U)))
                                                      ? 
                                                     (([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__31__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__31__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__31__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__31__Vfuncout)) 
                                                      - 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__32__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__32__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__32__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__32__Vfuncout)))
                                                      : 
                                                     (((IData)(1U) 
                                                       - 
                                                       ([&]() {
                                vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__34__inp 
                                    = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__34__Vfuncout 
                                    = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__34__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__34__Vfuncout))) 
                                                      + 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__35__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__35__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__35__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__35__Vfuncout))))));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[6U] 
               >> 5U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__1(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__1\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__2(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__2\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
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
                = (2U & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                         << 1U));
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
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             == (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             == (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__depth_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__full_o) 
                                              || (1U 
                                                  & (((1U 
                                                       & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                          >> 1U)) 
                                                      == 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                                          >> 1U)))
                                                      ? 
                                                     (([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__40__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__40__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__40__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__40__Vfuncout)) 
                                                      - 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__41__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__41__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__41__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__41__Vfuncout)))
                                                      : 
                                                     (((IData)(1U) 
                                                       - 
                                                       ([&]() {
                                vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__43__inp 
                                    = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__43__Vfuncout 
                                    = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__43__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__43__Vfuncout))) 
                                                      + 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__44__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__44__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__44__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__44__Vfuncout))))));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__depth_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__full_o) 
                                              || (1U 
                                                  & (((1U 
                                                       & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                          >> 1U)) 
                                                      == 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                                          >> 1U)))
                                                      ? 
                                                     (([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__49__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__49__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__49__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__49__Vfuncout)) 
                                                      - 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__50__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__50__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__50__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__50__Vfuncout)))
                                                      : 
                                                     (((IData)(1U) 
                                                       - 
                                                       ([&]() {
                                vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__52__inp 
                                    = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__52__Vfuncout 
                                    = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__52__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__52__Vfuncout))) 
                                                      + 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__53__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__53__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__53__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__53__Vfuncout))))));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[4U] 
               >> 3U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__1(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__1\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__2(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__2\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
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
                = (2U & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                         << 1U));
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
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             == (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             == (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__reqfifo__DOT__depth_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__full_o) 
                                              || (1U 
                                                  & (((1U 
                                                       & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                          >> 1U)) 
                                                      == 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                                          >> 1U)))
                                                      ? 
                                                     (([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__58__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__58__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__58__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__58__Vfuncout)) 
                                                      - 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__59__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__59__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__59__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__59__Vfuncout)))
                                                      : 
                                                     (((IData)(1U) 
                                                       - 
                                                       ([&]() {
                                vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__61__inp 
                                    = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__61__Vfuncout 
                                    = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__61__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__61__Vfuncout))) 
                                                      + 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__62__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__62__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__62__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__62__Vfuncout))))));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__depth_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__full_o) 
                                              || (1U 
                                                  & (((1U 
                                                       & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                          >> 1U)) 
                                                      == 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                                          >> 1U)))
                                                      ? 
                                                     (([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__67__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__67__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__67__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__67__Vfuncout)) 
                                                      - 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__68__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__68__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__68__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__68__Vfuncout)))
                                                      : 
                                                     (((IData)(1U) 
                                                       - 
                                                       ([&]() {
                                vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__70__inp 
                                    = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__70__Vfuncout 
                                    = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__70__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__70__Vfuncout))) 
                                                      + 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__71__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__71__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__71__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__71__Vfuncout))))));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_1n__02Etl_d_i[2U] 
               >> 1U)) & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__rspfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__1(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__1\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__2(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__2\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
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
                = (2U & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                         << 1U));
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
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             == (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             == (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__rspfifo__DOT__depth_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__full_o) 
                                              || (1U 
                                                  & (((1U 
                                                       & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                          >> 1U)) 
                                                      == 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                                          >> 1U)))
                                                      ? 
                                                     (([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__85__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__85__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__85__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__85__Vfuncout)) 
                                                      - 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__86__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__86__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__86__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__86__Vfuncout)))
                                                      : 
                                                     (((IData)(1U) 
                                                       - 
                                                       ([&]() {
                                vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__88__inp 
                                    = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__88__Vfuncout 
                                    = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__88__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__88__Vfuncout))) 
                                                      + 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__89__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__89__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__89__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__89__Vfuncout))))));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__depth_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__full_o) 
                                              || (1U 
                                                  & (((1U 
                                                       & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                          >> 1U)) 
                                                      == 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                                          >> 1U)))
                                                      ? 
                                                     (([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__76__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__76__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__76__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__76__Vfuncout)) 
                                                      - 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__77__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__77__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__77__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__77__Vfuncout)))
                                                      : 
                                                     (((IData)(1U) 
                                                       - 
                                                       ([&]() {
                                vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__79__inp 
                                    = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__79__Vfuncout 
                                    = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__79__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__79__Vfuncout))) 
                                                      + 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__80__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__80__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__80__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__80__Vfuncout))))));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__2(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__2\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
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
                = (2U & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                         << 1U));
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
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             == (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             == (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__rspfifo__DOT__depth_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__full_o) 
                                              || (1U 
                                                  & (((1U 
                                                       & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                          >> 1U)) 
                                                      == 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                                          >> 1U)))
                                                      ? 
                                                     (([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__103__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__103__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__103__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__103__Vfuncout)) 
                                                      - 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__104__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__104__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__104__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__104__Vfuncout)))
                                                      : 
                                                     (((IData)(1U) 
                                                       - 
                                                       ([&]() {
                                vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__106__inp 
                                    = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__106__Vfuncout 
                                    = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__106__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__106__Vfuncout))) 
                                                      + 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__107__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__107__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__107__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__107__Vfuncout))))));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__depth_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__full_o) 
                                              || (1U 
                                                  & (((1U 
                                                       & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                          >> 1U)) 
                                                      == 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                                          >> 1U)))
                                                      ? 
                                                     (([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__94__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__94__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__94__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__94__Vfuncout)) 
                                                      - 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__95__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__95__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__95__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__95__Vfuncout)))
                                                      : 
                                                     (((IData)(1U) 
                                                       - 
                                                       ([&]() {
                                vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__97__inp 
                                    = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__97__Vfuncout 
                                    = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__97__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__97__Vfuncout))) 
                                                      + 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__98__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__98__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__98__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__98__Vfuncout))))));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__2(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__2\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
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
                = (2U & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                         << 1U));
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
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             == (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             == (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__rspfifo__DOT__depth_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__full_o) 
                                              || (1U 
                                                  & (((1U 
                                                       & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                          >> 1U)) 
                                                      == 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                                          >> 1U)))
                                                      ? 
                                                     (([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__121__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__121__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__121__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__121__Vfuncout)) 
                                                      - 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__122__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__122__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__122__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__122__Vfuncout)))
                                                      : 
                                                     (((IData)(1U) 
                                                       - 
                                                       ([&]() {
                                vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__124__inp 
                                    = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__124__Vfuncout 
                                    = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__124__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__124__Vfuncout))) 
                                                      + 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__125__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__125__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__125__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__125__Vfuncout))))));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__depth_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__full_o) 
                                              || (1U 
                                                  & (((1U 
                                                       & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                          >> 1U)) 
                                                      == 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                                          >> 1U)))
                                                      ? 
                                                     (([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__112__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__112__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__112__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__112__Vfuncout)) 
                                                      - 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__113__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__113__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__113__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__113__Vfuncout)))
                                                      : 
                                                     (((IData)(1U) 
                                                       - 
                                                       ([&]() {
                                vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__115__inp 
                                    = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__115__Vfuncout 
                                    = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__115__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__115__Vfuncout))) 
                                                      + 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__116__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__116__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__116__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__116__Vfuncout))))));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__2(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__2\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
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
                = (2U & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                         << 1U));
        } else if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (2U & ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                         << 1U));
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
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__rspfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             == (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 1U));
    vlSelfRef.__PVT__reqfifo__DOT__full_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             == (2U 
                                                 ^ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.__PVT__rspfifo__DOT__depth_o = ((IData)(vlSelfRef.__PVT__rspfifo__DOT__full_o) 
                                              || (1U 
                                                  & (((1U 
                                                       & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                          >> 1U)) 
                                                      == 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                                          >> 1U)))
                                                      ? 
                                                     (([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__139__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__139__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__139__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__139__Vfuncout)) 
                                                      - 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__140__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__140__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__140__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__140__Vfuncout)))
                                                      : 
                                                     (((IData)(1U) 
                                                       - 
                                                       ([&]() {
                                vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__142__inp 
                                    = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__142__Vfuncout 
                                    = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__142__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__142__Vfuncout))) 
                                                      + 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__143__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__143__Vfuncout 
                                = vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__143__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__143__Vfuncout))))));
    vlSelfRef.__Vcellout__rspfifo__wready_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__depth_o = ((IData)(vlSelfRef.__PVT__reqfifo__DOT__full_o) 
                                              || (1U 
                                                  & (((1U 
                                                       & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                                          >> 1U)) 
                                                      == 
                                                      (1U 
                                                       & ((IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                                          >> 1U)))
                                                      ? 
                                                     (([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__130__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__130__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__130__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__130__Vfuncout)) 
                                                      - 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__131__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__131__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__131__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__131__Vfuncout)))
                                                      : 
                                                     (((IData)(1U) 
                                                       - 
                                                       ([&]() {
                                vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__133__inp 
                                    = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__133__Vfuncout 
                                    = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__133__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__133__Vfuncout))) 
                                                      + 
                                                      ([&]() {
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__134__inp 
                                = (1U & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__134__Vfuncout 
                                = vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__134__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__134__Vfuncout))))));
    vlSelfRef.__Vcellout__reqfifo__wready_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__full_o)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSymsp->TOP.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.__Vcellout__reqfifo__rvalid_o = (1U & 
                                               ((~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                                                & (~ (IData)(vlSelfRef.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__2(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__2\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_INLINE_OPT void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
