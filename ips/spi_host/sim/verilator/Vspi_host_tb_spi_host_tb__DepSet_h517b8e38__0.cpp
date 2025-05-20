// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_host_tb.h for the primary calling header

#include "Vspi_host_tb__pch.h"
#include "Vspi_host_tb_spi_host_tb.h"

VL_INLINE_OPT void Vspi_host_tb_spi_host_tb___nba_sequent__TOP__spi_host_tb__3(Vspi_host_tb_spi_host_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vspi_host_tb_spi_host_tb___nba_sequent__TOP__spi_host_tb__3\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT____Vlvbound_hda94dff7__0 
            = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_q;
        if ((0x17U >= (0x1fU & VL_SHIFTL_III(5,32,32, 
                                             (3U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)), 3U)))) {
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__storage 
                = (((~ ((IData)(0xffU) << (0x1fU & 
                                           VL_SHIFTL_III(5,32,32, 
                                                         (3U 
                                                          & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)), 3U)))) 
                    & vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__storage) 
                   | (0xffffffU & ((IData)(vlSelfRef.u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT____Vlvbound_hda94dff7__0) 
                                   << (0x1fU & VL_SHIFTL_III(5,32,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)), 3U)))));
        }
    }
    if (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT____Vlvbound_hda94dff7__0 
            = vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_wdata__q;
        if ((0x17U >= (0x1fU & VL_SHIFTL_III(5,32,32, 
                                             (3U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)), 3U)))) {
            vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__storage 
                = (((~ ((IData)(0xffU) << (0x1fU & 
                                           VL_SHIFTL_III(5,32,32, 
                                                         (3U 
                                                          & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)), 3U)))) 
                    & vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__storage) 
                   | (0xffffffU & ((IData)(vlSelfRef.u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT____Vlvbound_hda94dff7__0) 
                                   << (0x1fU & VL_SHIFTL_III(5,32,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)), 3U)))));
        }
    }
}

VL_INLINE_OPT void Vspi_host_tb_spi_host_tb___nba_comb__TOP__spi_host_tb__1(Vspi_host_tb_spi_host_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vspi_host_tb_spi_host_tb___nba_comb__TOP__spi_host_tb__1\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_wdata__DOT__wr_en 
        = (((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
            >> 3U) & (IData)(vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____VdfgRegularize_h533b1fce_2_6));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_rvalid) 
           & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
                  >> 2U) & ((~ (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error)) 
                            & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_re)))));
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
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (2U == (3U & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
}

VL_INLINE_OPT void Vspi_host_tb_spi_host_tb___nba_comb__TOP__spi_host_tb__2(Vspi_host_tb_spi_host_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vspi_host_tb_spi_host_tb___nba_comb__TOP__spi_host_tb__2\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rdata 
        = ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
            ? 0U : ((0x17U >= (0x1fU & VL_SHIFTL_III(5,5,32, 
                                                     (3U 
                                                      & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U)))
                     ? (0xffU & (vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                 >> (0x1fU & VL_SHIFTL_III(5,5,32, 
                                                           (3U 
                                                            & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U))))
                     : 0U));
    vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__r_wn_d 
        = vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__r_wn_q;
    if ((0U == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        if ((((IData)(vlSelfRef.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q) 
              & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__wdata_qe)) 
             & (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready))) {
            if ((2U == (IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
                vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__r_wn_d 
                    = (1U & ((IData)(vlSelfRef.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rdata) 
                             >> 7U));
            }
        }
    }
}

VL_INLINE_OPT void Vspi_host_tb_spi_host_tb___nba_comb__TOP__spi_host_tb__3(Vspi_host_tb_spi_host_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vspi_host_tb_spi_host_tb___nba_comb__TOP__spi_host_tb__3\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
