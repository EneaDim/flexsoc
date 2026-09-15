// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree;
    vlSelfRef.__VactTriggered[0U] = (1ULL | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__VactTriggered[0U] = (2ULL | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__VactTriggered[0U] = (4ULL | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__VactTriggered[0U] = (8ULL | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__VactTriggered[0U] = (0x0000000000000010ULL 
                                     | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we__1 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re__1 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree__1 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree__1 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree__1 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni;
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((1U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_tb__DOT__rx_i = 1U;
    ++(vlSelf->__Vcoverage[609]);
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__devmode_i = 1U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__devmode_i = 1U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__shadow_busy = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_busy = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__we = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__wd = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__q = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qe = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__we = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__wd = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__q = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qe = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__we = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__wd = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__q = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qe = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__we = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__wd = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__q = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qe = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__we = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__wd = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__q = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qe = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__we = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__wd = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__q = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qe = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__addr_i = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__we = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__wd = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__q = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qe = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__we = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__wd = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__q = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qe = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__we = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__wd = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__q = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qe = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__de = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__en_ifetch_i = 9U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__intg_error = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__intg_error_o = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_enable = 1U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__unused_sig = 1U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__d_i = 1U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__d_i = 1U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__d_i = 1U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__err_o = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__err_o = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__err_o = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__err_o = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_enable = 1U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__d_i = 1U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__d_i = 1U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__d_i = 1U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__d_i = 1U;
    ++(vlSelf->__Vcoverage[607]);
    ++(vlSelf->__Vcoverage[606]);
    ++(vlSelf->__Vcoverage[608]);
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__devmode_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1681, 1U, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__devmode_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__devmode_i = 1U;
    }
    ++(vlSelf->__Vcoverage[2519]);
    ++(vlSelf->__Vcoverage[2732]);
    ++(vlSelf->__Vcoverage[2738]);
    ++(vlSelf->__Vcoverage[2763]);
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_busy) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2480, 0U, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_busy);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_busy = 0U;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__d) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2800, 0U, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__d = 0U;
    }
    if ((0U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__addr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3271, 0U, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__addr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__addr_i = 0U;
    }
    if ((0U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3598, 0U, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__wd = 0U;
    }
    if ((0U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3981, 0U, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__d = 0U;
    }
    if ((0U != (9U ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__en_ifetch_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4648, 9U, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__en_ifetch_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__en_ifetch_i = 9U;
    }
    ++(vlSelf->__Vcoverage[6433]);
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__d_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6464, 1U, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__d_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__d_i = 1U;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = (0x007fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree));
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/uart-tlul/runs/uart/release/dv/functional/tb/cocotb/uart_tb.sv", 2, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtop___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @([hybrid] uart_tb.u_uart.u_uart_reg.flexsoc_tlul_we)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([hybrid] uart_tb.u_uart.u_uart_reg.flexsoc_tlul_re)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([hybrid] uart_tb.u_uart.u_uart_reg.u_reg_core.u_prim_reg_we_check.u_prim_onehot_check.or_tree)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @([hybrid] uart_tb.u_uart.u_uart_reg.u_reg_core.u_prim_reg_we_check.u_prim_onehot_check.err_tree)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @([hybrid] uart_tb.u_uart.u_uart_reg.u_reg_core.u_prim_reg_we_check.u_prim_onehot_check.and_tree)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h51485532__0;
    uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h51485532__0 = 0;
    CData/*0:0*/ uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h9250fec5__0;
    uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h9250fec5__0 = 0;
    CData/*0:0*/ uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VExpr_h9250fec5__0;
    uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VExpr_h9250fec5__0 = 0;
    CData/*3:0*/ __Vfunc_mubi4_test_invalid__3__val;
    __Vfunc_mubi4_test_invalid__3__val = 0;
    CData/*3:0*/ __Vfunc_mubi4_test_true_strict__4__val;
    __Vfunc_mubi4_test_true_strict__4__val = 0;
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
    CData/*3:0*/ __Vfunc_mubi4_test_true_strict__8__val;
    __Vfunc_mubi4_test_true_strict__8__val = 0;
    CData/*0:0*/ __Vfunc_mubi4_test_invalid__9__Vfuncout;
    __Vfunc_mubi4_test_invalid__9__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_mubi4_test_invalid__9__val;
    __Vfunc_mubi4_test_invalid__9__val = 0;
    QData/*38:0*/ __VdfgRegularize_h6e95ff9d_0_1;
    __VdfgRegularize_h6e95ff9d_0_1 = 0;
    QData/*57:0*/ __VdfgRegularize_h6e95ff9d_0_2;
    __VdfgRegularize_h6e95ff9d_0_2 = 0;
    QData/*58:0*/ __VdfgRegularize_h6e95ff9d_0_3;
    __VdfgRegularize_h6e95ff9d_0_3 = 0;
    QData/*59:0*/ __VdfgRegularize_h6e95ff9d_0_4;
    __VdfgRegularize_h6e95ff9d_0_4 = 0;
    QData/*60:0*/ __VdfgRegularize_h6e95ff9d_0_5;
    __VdfgRegularize_h6e95ff9d_0_5 = 0;
    QData/*61:0*/ __VdfgRegularize_h6e95ff9d_0_6;
    __VdfgRegularize_h6e95ff9d_0_6 = 0;
    QData/*62:0*/ __VdfgRegularize_h6e95ff9d_0_7;
    __VdfgRegularize_h6e95ff9d_0_7 = 0;
    QData/*32:0*/ __VdfgRegularize_h6e95ff9d_0_8;
    __VdfgRegularize_h6e95ff9d_0_8 = 0;
    QData/*33:0*/ __VdfgRegularize_h6e95ff9d_0_9;
    __VdfgRegularize_h6e95ff9d_0_9 = 0;
    QData/*34:0*/ __VdfgRegularize_h6e95ff9d_0_10;
    __VdfgRegularize_h6e95ff9d_0_10 = 0;
    QData/*35:0*/ __VdfgRegularize_h6e95ff9d_0_11;
    __VdfgRegularize_h6e95ff9d_0_11 = 0;
    QData/*36:0*/ __VdfgRegularize_h6e95ff9d_0_12;
    __VdfgRegularize_h6e95ff9d_0_12 = 0;
    QData/*37:0*/ __VdfgRegularize_h6e95ff9d_0_13;
    __VdfgRegularize_h6e95ff9d_0_13 = 0;
    // Body
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q) 
         & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
               >> 0x0aU)))) {
        ++(vlSelf->__Vcoverage[7555]);
    }
    if ((0x00000400U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q))) {
        ++(vlSelf->__Vcoverage[7556]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q)))) {
        ++(vlSelf->__Vcoverage[7557]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__clk_i) ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 0, vlSelfRef.uart_tb__DOT__clk_i, vlSelfRef.uart_tb__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT____Vtogcov__clk_i = vlSelfRef.uart_tb__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__rst_ni) ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2, vlSelfRef.uart_tb__DOT__rst_ni, vlSelfRef.uart_tb__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT____Vtogcov__rst_ni = vlSelfRef.uart_tb__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__rx_i) ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__rx_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4, vlSelfRef.uart_tb__DOT__rx_i, vlSelfRef.uart_tb__DOT____Vtogcov__rx_i);
        vlSelfRef.uart_tb__DOT____Vtogcov__rx_i = vlSelfRef.uart_tb__DOT__rx_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_valid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 8, vlSelfRef.uart_tb__DOT__tl_i_a_valid, vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_valid);
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_valid 
            = vlSelfRef.uart_tb__DOT__tl_i_a_valid;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_opcode) 
                ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_opcode)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 10, vlSelfRef.uart_tb__DOT__tl_i_a_opcode, vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_opcode);
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_opcode 
            = vlSelfRef.uart_tb__DOT__tl_i_a_opcode;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_param) 
                ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_param)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 16, vlSelfRef.uart_tb__DOT__tl_i_a_param, vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_param);
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_param 
            = vlSelfRef.uart_tb__DOT__tl_i_a_param;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_size) 
                ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_size)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 22, vlSelfRef.uart_tb__DOT__tl_i_a_size, vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_size);
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_size 
            = vlSelfRef.uart_tb__DOT__tl_i_a_size;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_source) 
                ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_source)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 26, vlSelfRef.uart_tb__DOT__tl_i_a_source, vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_source);
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_source 
            = vlSelfRef.uart_tb__DOT__tl_i_a_source;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__tl_i_a_address 
                ^ vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_address))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 42, vlSelfRef.uart_tb__DOT__tl_i_a_address, vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_address);
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_address 
            = vlSelfRef.uart_tb__DOT__tl_i_a_address;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_mask) 
                ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_mask)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 106, vlSelfRef.uart_tb__DOT__tl_i_a_mask, vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_mask);
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_mask 
            = vlSelfRef.uart_tb__DOT__tl_i_a_mask;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__tl_i_a_data 
                ^ vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_data))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 114, vlSelfRef.uart_tb__DOT__tl_i_a_data, vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_data);
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_a_data 
            = vlSelfRef.uart_tb__DOT__tl_i_a_data;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__tl_i_d_ready) 
         ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_d_ready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 178, vlSelfRef.uart_tb__DOT__tl_i_d_ready, vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_d_ready);
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_i_d_ready 
            = vlSelfRef.uart_tb__DOT__tl_i_d_ready;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__err_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2496, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__err_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__err_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2804, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2853, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2902, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2951, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3000, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3049, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3098, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3143, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3156, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3279, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3508, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3557, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3740, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 4015, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__outstanding_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4810, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__outstanding_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__outstanding_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_q))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4880, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4944, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqid_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4958, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqid_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqid_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqsz_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4974, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqsz_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqsz_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rspop_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4978, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rspop_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rspop_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_val_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_val_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 5939, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_val_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_val_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_val_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_val_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_prev_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth_prev_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 6009, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_prev_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth_prev_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth_prev_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_prev_q;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_d 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_timeout_count_d))) {
        VL_COV_TOGGLE_CHG_ST_I(24, vlSelf->__Vcoverage + 6019, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_timeout_count_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_timeout_count_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_d;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_q 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_timeout_count_q))) {
        VL_COV_TOGGLE_CHG_ST_I(24, vlSelf->__Vcoverage + 6067, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_timeout_count_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_timeout_count_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_q;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_val 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rxto_val))) {
        VL_COV_TOGGLE_CHG_ST_I(24, vlSelf->__Vcoverage + 6115, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_val, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rxto_val);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rxto_val 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_val;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_changed) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth_changed))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6163, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_changed, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth_changed);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth_changed 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_changed;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rxto_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6165, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rxto_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rxto_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_en;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6205, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__break_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__break_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6237, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__break_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__break_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__break_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__break_err;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_cnt_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 6239, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_cnt_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_cnt_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_d;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 6249, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6259, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_err;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__not_allzero_char) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__not_allzero_char))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6261, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__not_allzero_char, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__not_allzero_char);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__not_allzero_char 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__not_allzero_char;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_watermark) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_watermark))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6263, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_watermark, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_watermark);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_watermark 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_watermark;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_empty) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_empty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6265, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_empty, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_empty);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_empty 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_empty;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_watermark) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_watermark))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6267, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_watermark, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_watermark);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_watermark 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_watermark;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_done) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_done))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6269, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_done, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_done);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_done 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_done;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_overflow) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_overflow))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6271, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_overflow, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_overflow);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_overflow 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_overflow;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_break_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_break_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6275, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_break_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_break_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_break_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_break_err;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_timeout) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_timeout))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6277, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_timeout, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_timeout);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_timeout 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_timeout;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6281, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle_q;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__nco_sum_q))) {
        VL_COV_TOGGLE_CHG_ST_I(17, vlSelf->__Vcoverage + 6326, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__nco_sum_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__nco_sum_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q1))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6383, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q1);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q1 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q2))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6385, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q2);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q2 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6440, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6453, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6466, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6477, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6488, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifounder_rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6575, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifounder_rst);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifounder_rst 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 6936, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 6956, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifounder_rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7090, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifounder_rst);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifounder_rst 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7317, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7333, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7427, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(11, vlSelf->__Vcoverage + 7429, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7473, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7489, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7507, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7511, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__baud_div_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7592, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__baud_div_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__baud_div_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7600, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7602, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(11, vlSelf->__Vcoverage + 7618, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7662, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__d_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__d_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7704, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__d_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__d_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__d_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__d_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7714, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7725, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__d_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__d_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7738, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__d_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__d_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__d_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__d_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7748, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7759, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o;
    if ((0U != (0x000000ffU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage) 
                               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7116, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0xffffffffffffff00ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | (IData)((IData)((0x000000ffU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage)))));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                        >> 8U)) ^ (IData)(
                                                          (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                           >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7132, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                                       >> 8U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                                                >> 8U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0xffffffffffff00ffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                          >> 8U))))) 
                  << 8U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                        >> 0x00000010U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                          >> 0x00000010U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7148, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                                       >> 0x00000010U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                                                >> 0x00000010U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0xffffffffff00ffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                          >> 0x00000010U))))) 
                  << 0x00000010U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                        >> 0x00000018U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                          >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7164, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                                       >> 0x00000018U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                                                >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0xffffffff00ffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                          >> 0x00000018U))))) 
                  << 0x00000018U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                        >> 0x00000020U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                          >> 0x00000020U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7180, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                                       >> 0x00000020U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                                                >> 0x00000020U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0xffffff00ffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                          >> 0x00000020U))))) 
                  << 0x00000020U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                        >> 0x00000028U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                          >> 0x00000028U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7196, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                                       >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                                                >> 0x00000028U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0xffff00ffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                          >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                        >> 0x00000030U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                          >> 0x00000030U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7212, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                                       >> 0x00000030U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                                                >> 0x00000030U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0xff00ffffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                          >> 0x00000030U))))) 
                  << 0x00000030U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                        >> 0x00000038U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                          >> 0x00000038U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7228, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                                       >> 0x00000038U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                                                >> 0x00000038U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0x00ffffffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                          >> 0x00000038U))))) 
                  << 0x00000038U));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q;
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U])))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6601, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
            = ((0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U]) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 >> 8U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6617, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 >> 8U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                              >> 8U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
            = ((0xffff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U]) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 >> 0x00000010U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                 >> 0x00000010U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6633, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
            = ((0xff00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U]) 
               | (0x00ff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                           >> 0x00000018U)) 
                               ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                   << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                             >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6649, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                           >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
            = ((0x00ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U]) 
               | (0xff000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U]));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U])))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6665, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
            = ((0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U]) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 >> 8U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6681, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 >> 8U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                              >> 8U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
            = ((0xffff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U]) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 >> 0x00000010U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                 >> 0x00000010U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6697, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                 >> 0x00000010U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
            = ((0xff00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U]) 
               | (0x00ff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                           >> 0x00000018U)) 
                               ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                   << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                             >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6713, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                           >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
            = ((0x00ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U]) 
               | (0xff000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U]));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U])))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6729, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
            = ((0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U]) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 >> 8U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6745, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 >> 8U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                              >> 8U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
            = ((0xffff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U]) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 >> 0x00000010U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                 >> 0x00000010U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6761, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                 >> 0x00000010U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
            = ((0xff00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U]) 
               | (0x00ff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                           >> 0x00000018U)) 
                               ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                   << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                             >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6777, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                           >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
            = ((0x00ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U]) 
               | (0xff000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U]));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U])))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6793, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
            = ((0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U]) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 >> 8U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6809, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 >> 8U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                              >> 8U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
            = ((0xffff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U]) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 >> 0x00000010U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                 >> 0x00000010U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6825, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                 >> 0x00000010U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
            = ((0xff00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U]) 
               | (0x00ff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                           >> 0x00000018U)) 
                               ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                   << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                             >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6841, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                           >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
            = ((0x00ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U]) 
               | (0xff000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U]));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__rst_ni = vlSelfRef.uart_tb__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__rx_i = vlSelfRef.uart_tb__DOT__rx_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q 
                 >> 0x00000010U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err 
        = ((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
               >> 0x0000000aU)) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__clk_i = vlSelfRef.uart_tb__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 4U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 4U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 3U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 3U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o 
        = (0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o 
        = (7U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o 
        = (7U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o 
        = (0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (0x10U ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (8U ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    __VdfgRegularize_h6e95ff9d_0_8 = (((QData)((IData)(
                                                       (1U 
                                                        & VL_REDXOR_32(
                                                                       (0x2606bd25U 
                                                                        & vlSelfRef.uart_tb__DOT__tl_i_a_data))))) 
                                       << 0x00000020U) 
                                      | (QData)((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_data)));
    __VdfgRegularize_h6e95ff9d_0_1 = (((QData)((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_address)) 
                                       << 7U) | (QData)((IData)(
                                                                (((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_opcode) 
                                                                  << 4U) 
                                                                 | (IData)(vlSelfRef.uart_tb__DOT__tl_i_a_mask)))));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__timing_rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6283, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__timing_rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__timing_rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2828, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2877, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2926, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2975, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3024, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3073, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3122, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3532, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3581, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3834, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 4189, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7399, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__intq))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6431, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__intq);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__intq 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__intq))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7706, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__intq);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__intq 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__intq))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7740, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__intq);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__intq 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3512, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3561, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3772, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__err_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3241, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__err_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__err_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6285, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7702, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 619, vlSelfRef.uart_tb__DOT__u_uart__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6287, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__rx_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__rx_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 621, vlSelfRef.uart_tb__DOT__u_uart__DOT__rx_i, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__rx_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__rx_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__rx_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__rx_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tick_baud_x16))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5987, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tick_baud_x16);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tick_baud_x16 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7401, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__frame_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7421, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__frame_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__frame_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7590, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7736, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6427, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 617, vlSelfRef.uart_tb__DOT__u_uart__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__clk_i;
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4816, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4946, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2808, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2857, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2906, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2955, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3004, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3053, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3102, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 4079, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7419, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle;
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)))) {
        ++(vlSelf->__Vcoverage[6990]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) {
        ++(vlSelf->__Vcoverage[6991]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6976, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (0x00000010U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                          << 4U));
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)))) {
        ++(vlSelf->__Vcoverage[6992]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb) {
        ++(vlSelf->__Vcoverage[6993]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6978, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (0x00000010U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                          << 4U));
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)))) {
        ++(vlSelf->__Vcoverage[7363]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) {
        ++(vlSelf->__Vcoverage[7364]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7349, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (8U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                 << 3U));
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)))) {
        ++(vlSelf->__Vcoverage[7365]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb) {
        ++(vlSelf->__Vcoverage[7366]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7351, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (8U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                 << 3U));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 6906, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 7293, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 7299, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7307, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2710, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_qe);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_qe 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2714, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_qe);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_qe 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 6914, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6924, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6922, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o) {
        ++(vlSelf->__Vcoverage[6996]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_1 = 0x10U;
    } else {
        ++(vlSelf->__Vcoverage[6999]);
        if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) 
             == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb))) {
            ++(vlSelf->__Vcoverage[6997]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_0 
                = (0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o) 
                                  - (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)));
        } else {
            ++(vlSelf->__Vcoverage[6998]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_0 
                = (0x0000001fU & (((IData)(0x10U) - (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)) 
                                  + (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o)));
        }
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_1 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_0;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_1;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o) {
        ++(vlSelf->__Vcoverage[6994]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o)))) {
        ++(vlSelf->__Vcoverage[6995]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7305, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o) {
        ++(vlSelf->__Vcoverage[7369]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_1 = 8U;
    } else {
        ++(vlSelf->__Vcoverage[7372]);
        if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) 
             == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb))) {
            ++(vlSelf->__Vcoverage[7370]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_0 
                = (0x0000000fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o) 
                                  - (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)));
        } else {
            ++(vlSelf->__Vcoverage[7371]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_0 
                = (0x0000000fU & (((IData)(8U) - (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)) 
                                  + (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o)));
        }
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_1 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_0;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_1;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o) {
        ++(vlSelf->__Vcoverage[7367]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o)))) {
        ++(vlSelf->__Vcoverage[7368]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o;
    __VdfgRegularize_h6e95ff9d_0_9 = (((QData)((IData)(
                                                       (1U 
                                                        & VL_REDXOR_64(
                                                                       (0x00000000deba8050ULL 
                                                                        & __VdfgRegularize_h6e95ff9d_0_8))))) 
                                       << 0x00000021U) 
                                      | __VdfgRegularize_h6e95ff9d_0_8);
    __VdfgRegularize_h6e95ff9d_0_2 = (0x0000048000000000ULL 
                                      | (((QData)((IData)(
                                                          (1U 
                                                           & VL_REDXOR_64(
                                                                          (0x0000007800007fffULL 
                                                                           & __VdfgRegularize_h6e95ff9d_0_1))))) 
                                          << 0x00000039U) 
                                         | __VdfgRegularize_h6e95ff9d_0_1));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2841, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2890, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2939, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2988, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3037, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3086, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3135, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3545, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3594, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3875, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 4262, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_tick_baud))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5989, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_tick_baud);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_tick_baud 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6438, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__d_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__d_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7712, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7746, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err) {
        ++(vlSelf->__Vcoverage[2507]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q) {
        ++(vlSelf->__Vcoverage[2509]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err))))) {
        ++(vlSelf->__Vcoverage[2510]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2482, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q) 
           | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7560, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7018, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__core_rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1151, vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__core_rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__core_rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7700, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7734, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7391, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6497, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6423, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5935, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_x16))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7564, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_x16);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_x16 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_x16))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7393, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_x16);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_x16 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6223, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_valid);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_valid 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_frame_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6273, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_frame_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_frame_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6203, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1149, vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1) 
         & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))) {
        ++(vlSelf->__Vcoverage[6396]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync) 
         & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))) {
        ++(vlSelf->__Vcoverage[6397]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync) 
         & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1))) {
        ++(vlSelf->__Vcoverage[6398]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
        ++(vlSelf->__Vcoverage[6399]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
        ++(vlSelf->__Vcoverage[6400]);
    }
    if ((1U & (((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1)) 
                & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync))) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
        ++(vlSelf->__Vcoverage[6401]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync))))) {
        ++(vlSelf->__Vcoverage[6402]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
        ++(vlSelf->__Vcoverage[6403]);
    }
    if ((1U & (((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync)) 
                & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1))))) {
        ++(vlSelf->__Vcoverage[6404]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
        ++(vlSelf->__Vcoverage[6405]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1))))) {
        ++(vlSelf->__Vcoverage[6406]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6233, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj 
        = (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync) 
            & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1) 
               | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))) 
           | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1) 
              & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2)));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7698, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__clk_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7732, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__clk_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5757, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1153, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__clk_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2552, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2548, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2544, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2540, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2536, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2532, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2528, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 2556, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_uart_idle))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6231, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_uart_idle);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_uart_idle 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 6946, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 6966, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7325, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7341, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 6553, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 7072, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 7078, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata 
        = (0x000000ffU & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                  >> ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                                      << 3U))));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_empty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7088, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_empty);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_empty 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 6561, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata 
        = (0x000000ffU & (((0U == (0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                                                  << 3U)))
                            ? 0U : (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage
                                    [(((IData)(7U) 
                                       + ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                                          << 3U)) >> 5U)] 
                                    << ((IData)(0x00000020U) 
                                        - (0x0000001fU 
                                           & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                                              << 3U))))) 
                          | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage
                             [(0x07ffffffU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                                              >> 2U))] 
                             >> (0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                                                << 3U)))));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_empty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6573, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_empty);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_empty 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 6926, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o;
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst))))) {
        ++(vlSelf->__Vcoverage[6587]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
        ++(vlSelf->__Vcoverage[6588]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o) {
        ++(vlSelf->__Vcoverage[6589]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__full_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6541, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__full_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__full_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o 
        = (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o) 
                    | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7309, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o;
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst))))) {
        ++(vlSelf->__Vcoverage[7102]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
        ++(vlSelf->__Vcoverage[7103]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o) {
        ++(vlSelf->__Vcoverage[7104]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__full_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7062, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__full_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__full_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o 
        = (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o) 
                    | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    __VdfgRegularize_h6e95ff9d_0_10 = (((QData)((IData)(
                                                        (1U 
                                                         & VL_REDXOR_64(
                                                                        (0x00000000413d89aaULL 
                                                                         & __VdfgRegularize_h6e95ff9d_0_9))))) 
                                        << 0x00000022U) 
                                       | __VdfgRegularize_h6e95ff9d_0_9);
    __VdfgRegularize_h6e95ff9d_0_3 = (((QData)((IData)(
                                                       (1U 
                                                        & VL_REDXOR_64(
                                                                       (0x017c1ff801ff801fULL 
                                                                        & __VdfgRegularize_h6e95ff9d_0_2))))) 
                                       << 0x0000003aU) 
                                      | __VdfgRegularize_h6e95ff9d_0_2);
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2258, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7285, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5759, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7710, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7723, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7744, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7757, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6898, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6436, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6449, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6425, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__d_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__d_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1155, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_maj))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6389, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_maj);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_maj 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7708, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7721, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7742, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7755, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6460, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6473, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6484, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7389, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7558, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6495, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7016, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6421, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__clk_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4294, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1926, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7244, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata;
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst))))) {
        ++(vlSelf->__Vcoverage[7105]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
        ++(vlSelf->__Vcoverage[7106]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty) {
        ++(vlSelf->__Vcoverage[7107]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifoempty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7100, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifoempty);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifoempty 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o 
        = (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) 
                    | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty))));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6857, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata;
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst))))) {
        ++(vlSelf->__Vcoverage[6590]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
        ++(vlSelf->__Vcoverage[6591]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty) {
        ++(vlSelf->__Vcoverage[6592]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifoempty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6585, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifoempty);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifoempty 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o 
        = (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) 
                    | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty))));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__depth_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 6543, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__depth_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__depth_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wready_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6503, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wready_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wready_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__depth_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7064, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__depth_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__depth_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wready_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7024, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wready_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wready_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o;
    __VdfgRegularize_h6e95ff9d_0_11 = (((QData)((IData)(
                                                        (1U 
                                                         & VL_REDXOR_64(
                                                                        (0x0000000031234ed1ULL 
                                                                         & __VdfgRegularize_h6e95ff9d_0_10))))) 
                                        << 0x00000023U) 
                                       | __VdfgRegularize_h6e95ff9d_0_10);
    __VdfgRegularize_h6e95ff9d_0_4 = (((QData)((IData)(
                                                       (1U 
                                                        & VL_REDXOR_64(
                                                                       (0x01bde1f87e0781e1ULL 
                                                                        & __VdfgRegularize_h6e95ff9d_0_3))))) 
                                       << 0x0000003bU) 
                                      | __VdfgRegularize_h6e95ff9d_0_3);
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6462, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6475, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6486, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__d_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6429, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__d_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__d_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__d_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4296, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1928, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6896, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7283, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6434, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6447, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5185, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2792, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2843, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2892, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2941, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2990, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3039, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3088, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3137, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3150, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3498, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3547, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3716, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3943, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3223, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifordata_int)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7263, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifordata_int);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifordata_int 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty) {
        ++(vlSelf->__Vcoverage[7281]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____VlemCond_0 = 0U;
    } else {
        ++(vlSelf->__Vcoverage[7282]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty) {
        ++(vlSelf->__Vcoverage[7279]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty)))) {
        ++(vlSelf->__Vcoverage[7280]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rvalid_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7042, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rvalid_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rvalid_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifordata_int)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6876, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifordata_int);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifordata_int 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty) {
        ++(vlSelf->__Vcoverage[6894]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____VlemCond_0 = 0U;
    } else {
        ++(vlSelf->__Vcoverage[6895]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty) {
        ++(vlSelf->__Vcoverage[6892]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty)))) {
        ++(vlSelf->__Vcoverage[6893]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rvalid_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6521, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rvalid_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rvalid_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 5999, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready)))) {
        ++(vlSelf->__Vcoverage[6322]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready) {
        ++(vlSelf->__Vcoverage[6323]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6229, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wready);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wready 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_depth)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5991, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_depth);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_depth 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready)))) {
        ++(vlSelf->__Vcoverage[6324]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready) {
        ++(vlSelf->__Vcoverage[6325]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6199, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wready);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wready 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready;
    }
    __VdfgRegularize_h6e95ff9d_0_12 = (((QData)((IData)(
                                                        (1U 
                                                         & VL_REDXOR_64(
                                                                        (0x00000000c2c1323bULL 
                                                                         & __VdfgRegularize_h6e95ff9d_0_11))))) 
                                        << 0x00000024U) 
                                       | __VdfgRegularize_h6e95ff9d_0_11);
    __VdfgRegularize_h6e95ff9d_0_5 = (((QData)((IData)(
                                                       (1U 
                                                        & VL_REDXOR_64(
                                                                       (0x01deee3b8e388e22ULL 
                                                                        & __VdfgRegularize_h6e95ff9d_0_4))))) 
                                       << 0x0000003cU) 
                                      | __VdfgRegularize_h6e95ff9d_0_4);
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__d_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6451, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__d_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__d_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__d_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5187, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2794, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2845, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2894, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2943, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2992, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3041, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3090, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3139, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3152, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3500, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3549, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3718, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3945, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3225, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3255, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rdata_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7046, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rdata_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rdata_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o;
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)))) {
        ++(vlSelf->__Vcoverage[6320]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid) {
        ++(vlSelf->__Vcoverage[6321]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rvalid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6197, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rvalid);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rvalid 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rdata_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6525, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rdata_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rdata_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o;
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid)))) {
        ++(vlSelf->__Vcoverage[6315]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid) {
        ++(vlSelf->__Vcoverage[6316]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_rvalid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6227, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_rvalid);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_rvalid 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid;
    }
    __VdfgRegularize_h6e95ff9d_0_13 = (((QData)((IData)(
                                                        (1U 
                                                         & VL_REDXOR_64(
                                                                        (0x000000002dcc624cULL 
                                                                         & __VdfgRegularize_h6e95ff9d_0_12))))) 
                                        << 0x00000025U) 
                                       | __VdfgRegularize_h6e95ff9d_0_12);
    __VdfgRegularize_h6e95ff9d_0_6 = (((QData)((IData)(
                                                       (1U 
                                                        & VL_REDXOR_64(
                                                                       (0x01ef76cdb2c93244ULL 
                                                                        & __VdfgRegularize_h6e95ff9d_0_5))))) 
                                       << 0x0000003dU) 
                                      | __VdfgRegularize_h6e95ff9d_0_5);
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3257, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6179, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rdata)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5971, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rdata);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rdata 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata;
    }
    __VdfgRegularize_h6e95ff9d_0_7 = (((QData)((IData)(
                                                       (1U 
                                                        & VL_REDXOR_64(
                                                                       (0x01f7bb56d5525488ULL 
                                                                        & __VdfgRegularize_h6e95ff9d_0_6))))) 
                                       << 0x0000003eU) 
                                      | __VdfgRegularize_h6e95ff9d_0_6);
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7572, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data;
    }
    vlSelfRef.uart_tb__DOT__tl_i[0U] = (0x00048000U 
                                        | ((0xff000000U 
                                            & vlSelfRef.uart_tb__DOT__tl_i[0U]) 
                                           | ((0x00002a00U 
                                               ^ ((
                                                   (0x00000040U 
                                                    & (VL_REDXOR_64(
                                                                    (0x01fbdda769a46910ULL 
                                                                     & __VdfgRegularize_h6e95ff9d_0_7)) 
                                                       << 6U)) 
                                                   | (0x0000003fU 
                                                      & (IData)(
                                                                (__VdfgRegularize_h6e95ff9d_0_7 
                                                                 >> 0x00000039U)))) 
                                                  << 8U)) 
                                              | ((0x00000054U 
                                                  ^ 
                                                  (((0x00000040U 
                                                     & (VL_REDXOR_64(
                                                                     (0x0000000098505586ULL 
                                                                      & __VdfgRegularize_h6e95ff9d_0_13)) 
                                                        << 6U)) 
                                                    | (0x0000003fU 
                                                       & (IData)(
                                                                 (__VdfgRegularize_h6e95ff9d_0_13 
                                                                  >> 0x00000020U)))) 
                                                   << 1U)) 
                                                 | (IData)(vlSelfRef.uart_tb__DOT__tl_i_d_ready)))));
    vlSelfRef.uart_tb__DOT__tl_i[0U] = ((0x00ffffffU 
                                         & vlSelfRef.uart_tb__DOT__tl_i[0U]) 
                                        | ((IData)(
                                                   (((QData)((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_mask)) 
                                                     << 0x00000020U) 
                                                    | (QData)((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_data)))) 
                                           << 0x00000018U));
    vlSelfRef.uart_tb__DOT__tl_i[1U] = (((IData)((((QData)((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_mask)) 
                                                   << 0x00000020U) 
                                                  | (QData)((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_data)))) 
                                         >> 8U) | (
                                                   (vlSelfRef.uart_tb__DOT__tl_i_a_address 
                                                    << 0x0000001cU) 
                                                   | ((IData)(
                                                              ((((QData)((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_mask)) 
                                                                 << 0x00000020U) 
                                                                | (QData)((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_data))) 
                                                               >> 0x00000020U)) 
                                                      << 0x00000018U)));
    vlSelfRef.uart_tb__DOT__tl_i[2U] = (((0x00ffffffU 
                                          & (vlSelfRef.uart_tb__DOT__tl_i_a_address 
                                             >> 4U)) 
                                         | ((IData)(
                                                    ((((QData)((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_mask)) 
                                                       << 0x00000020U) 
                                                      | (QData)((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_data))) 
                                                     >> 0x00000020U)) 
                                            >> 8U)) 
                                        | (((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_source) 
                                            << 0x0000001cU) 
                                           | (0x0f000000U 
                                              & (vlSelfRef.uart_tb__DOT__tl_i_a_address 
                                                 >> 4U))));
    vlSelfRef.uart_tb__DOT__tl_i[3U] = ((0x00001ff0U 
                                         & vlSelfRef.uart_tb__DOT__tl_i[3U]) 
                                        | (0x00001fffU 
                                           & ((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_source) 
                                              >> 4U)));
    vlSelfRef.uart_tb__DOT__tl_i[3U] = ((0x0000000fU 
                                         & vlSelfRef.uart_tb__DOT__tl_i[3U]) 
                                        | (0x00001fffU 
                                           & (((((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_valid) 
                                                 << 8U) 
                                                | ((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_opcode) 
                                                   << 5U)) 
                                               | (((IData)(vlSelfRef.uart_tb__DOT__tl_i_a_param) 
                                                   << 2U) 
                                                  | (IData)(vlSelfRef.uart_tb__DOT__tl_i_a_size))) 
                                              << 4U)));
    if ((0U != ((((vlSelfRef.uart_tb__DOT__tl_i[0U] 
                   ^ vlSelfRef.uart_tb__DOT____Vtogcov__tl_i[0U]) 
                  | (vlSelfRef.uart_tb__DOT__tl_i[1U] 
                     ^ vlSelfRef.uart_tb__DOT____Vtogcov__tl_i[1U])) 
                 | (vlSelfRef.uart_tb__DOT__tl_i[2U] 
                    ^ vlSelfRef.uart_tb__DOT____Vtogcov__tl_i[2U])) 
                | (vlSelfRef.uart_tb__DOT__tl_i[3U] 
                   ^ vlSelfRef.uart_tb__DOT____Vtogcov__tl_i[3U])))) {
        VL_COV_TOGGLE_CHG_ST_W(109, vlSelf->__Vcoverage + 256, vlSelfRef.uart_tb__DOT__tl_i, vlSelfRef.uart_tb__DOT____Vtogcov__tl_i);
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_i[0U] 
            = vlSelfRef.uart_tb__DOT__tl_i[0U];
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_i[1U] 
            = vlSelfRef.uart_tb__DOT__tl_i[1U];
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_i[2U] 
            = vlSelfRef.uart_tb__DOT__tl_i[2U];
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_i[3U] 
            = vlSelfRef.uart_tb__DOT__tl_i[3U];
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] = vlSelfRef.uart_tb__DOT__tl_i[0U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[1U] = vlSelfRef.uart_tb__DOT__tl_i[1U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[2U] = vlSelfRef.uart_tb__DOT__tl_i[2U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] = vlSelfRef.uart_tb__DOT__tl_i[3U];
    if ((0x00001000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 625, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                >> 0x0000000cU), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
                                                  >> 0x0000000cU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
            = ((0x00000fffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U]) 
               | (0x00001000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                        << 0x00000017U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                           >> 9U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
                          << 0x00000017U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
                                             >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 627, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                 >> 9U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
                                              >> 9U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
            = ((0x000011ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U]) 
               | (0x00000e00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                        << 0x0000001aU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                           >> 6U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
                          << 0x0000001aU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
                                             >> 6U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 633, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                 << 0x0000001aU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                 >> 6U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
                                            << 0x0000001aU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
                                              >> 6U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001e3fU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U]) 
               | (0x000001c0U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U]));
    }
    if ((0U != (3U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                        << 0x0000001cU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                           >> 4U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
                          << 0x0000001cU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
                                             >> 4U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 639, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                 << 0x0000001cU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                 >> 4U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
                                            << 0x0000001cU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
                                              >> 4U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001fcfU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U]) 
               | (0x00000030U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[2U] 
                                           >> 0x0000001cU)) 
                               ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
                                   << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[2U] 
                                             >> 0x0000001cU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 643, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[2U] 
                                           >> 0x0000001cU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[2U] 
                                           >> 0x0000001cU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[2U] 
            = ((0x0fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[2U]) 
               | (0xf0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[2U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001ff0U & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[3U]) 
               | (0x0000000fU & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U]));
    }
    if ((0U != (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[2U] 
                  << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[1U] 
                            >> 0x0000001cU)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[2U] 
                                                 << 4U) 
                                                | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[1U] 
                                                   >> 0x0000001cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 659, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[2U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[1U] 
                                           >> 0x0000001cU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[2U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001cU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[1U] 
            = ((0x0fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[1U]) 
               | (0xf0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[1U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[2U] 
            = ((0xf0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[2U]) 
               | (0x0fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[2U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[1U] 
                                           >> 0x00000018U)) 
                               ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[1U] 
                                   << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[1U] 
                                             >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 723, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[1U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[1U] 
            = ((0xf0ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[1U]) 
               | (0x0f000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[1U]));
    }
    if ((0U != (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[1U] 
                  << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                            >> 0x00000018U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[1U] 
                                                 << 8U) 
                                                | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                                   >> 0x00000018U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 731, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                           >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
            = ((0x00ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U]) 
               | (0xff000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[1U] 
            = ((0xff000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[1U]) 
               | (0x00ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[1U]));
    }
    if ((0U != (0x0000001fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                 >> 0x00000013U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000013U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 795, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                 >> 0x00000013U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000013U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
            = ((0xff07ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U]) 
               | (0x00f80000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                 >> 0x0000000fU)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x0000000fU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 805, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                 >> 0x0000000fU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x0000000fU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
            = ((0xfff87fffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U]) 
               | (0x00078000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                 >> 8U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 813, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                 >> 8U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                              >> 8U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
            = ((0xffff80ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U]) 
               | (0x00007f00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                 >> 1U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                             << 0x0000001fU) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                               >> 1U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 827, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                 >> 1U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                            << 0x0000001fU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
                                              >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
            = ((0xffffff01U & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U]) 
               | (0x000000feU & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U]));
    }
    if ((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 841, vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U], vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffeU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i[0U]) 
               | (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U]));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[1U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[1U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[2U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[2U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U];
    if ((0x00001000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1157, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                >> 0x0000000cU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
                                                  >> 0x0000000cU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x00000fffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x00001000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                        << 0x00000017U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                           >> 9U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
                          << 0x00000017U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
                                             >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 1159, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                 >> 9U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
                                              >> 9U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x000011ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x00000e00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                        << 0x0000001aU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                           >> 6U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
                          << 0x0000001aU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
                                             >> 6U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 1165, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                 << 0x0000001aU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                 >> 6U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
                                            << 0x0000001aU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
                                              >> 6U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001e3fU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x000001c0U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U]));
    }
    if ((0U != (3U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                        << 0x0000001cU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                           >> 4U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
                          << 0x0000001cU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
                                             >> 4U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 1171, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                 << 0x0000001cU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                 >> 4U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
                                            << 0x0000001cU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
                                              >> 4U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001fcfU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x00000030U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[2U] 
                                           >> 0x0000001cU)) 
                               ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
                                   << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[2U] 
                                             >> 0x0000001cU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1175, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[2U] 
                                           >> 0x0000001cU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[2U] 
                                           >> 0x0000001cU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[2U] 
            = ((0x0fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[2U]) 
               | (0xf0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[2U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001ff0U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x0000000fU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U]));
    }
    if ((0U != (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[2U] 
                  << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[1U] 
                            >> 0x0000001cU)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[2U] 
                                                 << 4U) 
                                                | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[1U] 
                                                   >> 0x0000001cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1191, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[2U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[1U] 
                                           >> 0x0000001cU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[2U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001cU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[1U] 
            = ((0x0fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[1U]) 
               | (0xf0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[1U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[2U] 
            = ((0xf0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[2U]) 
               | (0x0fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[2U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[1U] 
                                           >> 0x00000018U)) 
                               ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[1U] 
                                   << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[1U] 
                                             >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1255, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[1U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[1U] 
            = ((0xf0ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[1U]) 
               | (0x0f000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[1U]));
    }
    if ((0U != (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[1U] 
                  << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                            >> 0x00000018U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[1U] 
                                                 << 8U) 
                                                | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                                   >> 0x00000018U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1263, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                           >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0x00ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0xff000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[1U] 
            = ((0xff000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[1U]) 
               | (0x00ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[1U]));
    }
    if ((0U != (0x0000001fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                 >> 0x00000013U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000013U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 1327, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                 >> 0x00000013U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000013U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xff07ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0x00f80000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                 >> 0x0000000fU)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x0000000fU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1337, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                 >> 0x0000000fU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x0000000fU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xfff87fffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0x00078000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                 >> 8U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 1345, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                 >> 8U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                              >> 8U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xffff80ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0x00007f00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                 >> 1U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                             << 0x0000001fU) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                               >> 1U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 1359, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                 >> 1U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                            << 0x0000001fU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
                                              >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xffffff01U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0x000000feU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U]));
    }
    if ((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1373, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffeU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i[0U]) 
               | (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U]));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[1U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[2U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U];
    __Vfunc_mubi4_test_invalid__3__val = (0x0000000fU 
                                          & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                             >> 0x0000000fU));
    uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h51485532__0 
        = (1U & (~ ((6U == (IData)(__Vfunc_mubi4_test_invalid__3__val)) 
                    | (9U == (IData)(__Vfunc_mubi4_test_invalid__3__val)))));
    if (((6U != (IData)(__Vfunc_mubi4_test_invalid__3__val)) 
         & (9U != (IData)(__Vfunc_mubi4_test_invalid__3__val)))) {
        ++(vlSymsp->__Vcoverage[10970]);
    }
    if ((9U == (IData)(__Vfunc_mubi4_test_invalid__3__val))) {
        ++(vlSymsp->__Vcoverage[10971]);
    }
    if ((6U == (IData)(__Vfunc_mubi4_test_invalid__3__val))) {
        ++(vlSymsp->__Vcoverage[10972]);
    }
    ++(vlSymsp->__Vcoverage[10973]);
    __Vfunc_mubi4_test_true_strict__4__val = (0x0000000fU 
                                              & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                                 >> 0x0000000fU));
    uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h9250fec5__0 
        = (6U == (IData)(__Vfunc_mubi4_test_true_strict__4__val));
    ++(vlSymsp->__Vcoverage[10977]);
    ++(vlSymsp->__Vcoverage[10980]);
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__instr_error 
        = ((IData)(uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h51485532__0) 
           | (IData)(uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h9250fec5__0));
    if (uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h9250fec5__0) {
        ++(vlSelf->__Vcoverage[5175]);
    }
    if (uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h51485532__0) {
        ++(vlSelf->__Vcoverage[5176]);
    }
    if ((1U & ((~ (IData)(uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h51485532__0)) 
               & (~ (IData)(uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VExpr_h9250fec5__0))))) {
        ++(vlSelf->__Vcoverage[5178]);
    }
    if ((0x00001000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4298, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                >> 0x0000000cU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                                  >> 0x0000000cU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x00000fffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x00001000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                        << 0x00000017U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                           >> 9U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                          << 0x00000017U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                             >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4300, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                 >> 9U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                              >> 9U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x000011ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x00000e00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                        << 0x0000001aU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                           >> 6U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                          << 0x0000001aU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                             >> 6U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4306, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                 << 0x0000001aU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                 >> 6U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                            << 0x0000001aU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                              >> 6U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001e3fU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x000001c0U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U]));
    }
    if ((0U != (3U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                        << 0x0000001cU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                           >> 4U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                          << 0x0000001cU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                             >> 4U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4312, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                 << 0x0000001cU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                 >> 4U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                            << 0x0000001cU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                              >> 4U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001fcfU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x00000030U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                                           >> 0x0000001cU)) 
                               ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                   << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[2U] 
                                             >> 0x0000001cU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4316, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                                           >> 0x0000001cU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[2U] 
                                           >> 0x0000001cU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[2U] 
            = ((0x0fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[2U]) 
               | (0xf0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001ff0U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[3U]) 
               | (0x0000000fU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U]));
    }
    if ((0U != (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                  << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                            >> 0x0000001cU)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[2U] 
                                                 << 4U) 
                                                | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
                                                   >> 0x0000001cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4332, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                           >> 0x0000001cU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[2U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001cU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
            = ((0x0fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U]) 
               | (0xf0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[2U] 
            = ((0xf0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[2U]) 
               | (0x0fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                           >> 0x00000018U)) 
                               ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
                                   << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
                                             >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4396, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
            = ((0xf0ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U]) 
               | (0x0f000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U]));
    }
    if ((0U != (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                  << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                            >> 0x00000018U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
                                                 << 8U) 
                                                | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                                   >> 0x00000018U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4404, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                           >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0x00ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0xff000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U] 
            = ((0xff000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[1U]) 
               | (0x00ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U]));
    }
    if ((0U != (0x0000001fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 >> 0x00000013U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000013U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 4468, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 >> 0x00000013U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000013U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xff07ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0x00f80000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 >> 0x0000000fU)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x0000000fU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4478, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 >> 0x0000000fU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x0000000fU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xfff87fffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0x00078000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 >> 8U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4486, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 >> 8U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                              >> 8U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xffff80ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0x00007f00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 >> 1U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                             << 0x0000001fU) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                               >> 1U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4500, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                 >> 1U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                            << 0x0000001fU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
                                              >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xffffff01U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U]) 
               | (0x000000feU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]));
    }
    if ((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4514, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffeU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i[0U]) 
               | (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]));
    }
    __Vfunc_tl_a_user_chk__6__user = (0x007fffffU & 
                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
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
    if (((6U != (IData)(__Vfunc_mubi4_test_invalid__7__val)) 
         & (9U != (IData)(__Vfunc_mubi4_test_invalid__7__val)))) {
        ++(vlSymsp->__Vcoverage[10970]);
    }
    if ((9U == (IData)(__Vfunc_mubi4_test_invalid__7__val))) {
        ++(vlSymsp->__Vcoverage[10971]);
    }
    if ((6U == (IData)(__Vfunc_mubi4_test_invalid__7__val))) {
        ++(vlSymsp->__Vcoverage[10972]);
    }
    ++(vlSymsp->__Vcoverage[10973]);
    __Vfunc_tl_a_user_chk__6__malformed_err = __Vfunc_mubi4_test_invalid__7__Vfuncout;
    __Vfunc_tl_a_user_chk__6__Vfuncout = __Vfunc_tl_a_user_chk__6__malformed_err;
    if ((0x00400000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11257]);
    }
    if ((0x00200000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11258]);
    }
    if ((0x00100000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11259]);
    }
    if ((0x00080000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11260]);
    }
    if ((0x00040000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11261]);
    }
    if ((0x00020000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11262]);
    }
    if ((0x00010000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11263]);
    }
    if ((0x00008000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11264]);
    }
    if ((0x00004000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11265]);
    }
    if ((0x00002000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11266]);
    }
    if ((0x00001000U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11267]);
    }
    if ((0x00000800U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11268]);
    }
    if ((0x00000400U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11269]);
    }
    if ((0x00000200U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11270]);
    }
    if ((0x00000100U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11271]);
    }
    if ((0x00000080U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11272]);
    }
    if ((0x00000040U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11273]);
    }
    if ((0x00000020U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11274]);
    }
    if ((0x00000010U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11275]);
    }
    if ((8U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11276]);
    }
    if ((4U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11277]);
    }
    if ((2U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11278]);
    }
    if ((1U & __Vfunc_tl_a_user_chk__6__user)) {
        ++(vlSymsp->__Vcoverage[11279]);
    }
    if ((IData)((0U == __Vfunc_tl_a_user_chk__6__user))) {
        ++(vlSymsp->__Vcoverage[11280]);
    }
    ++(vlSymsp->__Vcoverage[11281]);
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__malformed_meta_err 
        = __Vfunc_tl_a_user_chk__6__Vfuncout;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_o 
        = (0x0000001cU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                           << 4U) | (0x0000000cU & 
                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                      >> 0x0000001cU))));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wdata_o 
        = ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
            << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                      >> 0x00000018U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__be_o 
        = (0x0000000fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                          >> 0x00000018U));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__instr_error) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__instr_error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4950, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__instr_error, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__instr_error);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__instr_error 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__instr_error;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__malformed_meta_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__malformed_meta_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4954, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__malformed_meta_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__malformed_meta_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__malformed_meta_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__malformed_meta_err;
    }
    if ((4U == (7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                      >> 9U)))) {
        ++(vlSelf->__Vcoverage[5432]);
    }
    if ((1U == (7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                      >> 9U)))) {
        ++(vlSelf->__Vcoverage[5433]);
    }
    if ((0U == (7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                      >> 9U)))) {
        ++(vlSelf->__Vcoverage[5434]);
    }
    if ((((0U != (7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                        >> 9U))) & (1U != (7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                                 >> 9U)))) 
         & (4U != (7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                         >> 9U))))) {
        ++(vlSelf->__Vcoverage[5435]);
    }
    if ((0x00001000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5189, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                >> 0x0000000cU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                                  >> 0x0000000cU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
            = ((0x00000fffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U]) 
               | (0x00001000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                        << 0x00000017U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                           >> 9U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                          << 0x00000017U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                             >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5191, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 >> 9U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                              >> 9U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
            = ((0x000011ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U]) 
               | (0x00000e00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                        << 0x0000001aU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                           >> 6U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                          << 0x0000001aU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                             >> 6U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5197, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 << 0x0000001aU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 >> 6U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                            << 0x0000001aU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                              >> 6U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001e3fU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U]) 
               | (0x000001c0U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U]));
    }
    if ((0U != (3U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                        << 0x0000001cU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                           >> 4U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                          << 0x0000001cU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                             >> 4U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 5203, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 << 0x0000001cU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 >> 4U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                            << 0x0000001cU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                              >> 4U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001fcfU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U]) 
               | (0x00000030U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U] 
                                           >> 0x0000001cU)) 
                               ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                   << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[2U] 
                                             >> 0x0000001cU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5207, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U] 
                                           >> 0x0000001cU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[2U] 
                                           >> 0x0000001cU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[2U] 
            = ((0x0fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[2U]) 
               | (0xf0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U] 
            = ((0x00001ff0U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[3U]) 
               | (0x0000000fU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U]));
    }
    if ((0U != (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U] 
                  << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                            >> 0x0000001cU)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[2U] 
                                                 << 4U) 
                                                | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
                                                   >> 0x0000001cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5223, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                           >> 0x0000001cU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[2U] 
                                 << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001cU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
            = ((0x0fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U]) 
               | (0xf0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[2U] 
            = ((0xf0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[2U]) 
               | (0x0fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                           >> 0x00000018U)) 
                               ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
                                   << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
                                             >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5287, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
            = ((0xf0ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U]) 
               | (0x0f000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U]));
    }
    if ((0U != (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                  << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                            >> 0x00000018U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
                                                 << 8U) 
                                                | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                                   >> 0x00000018U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5295, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                           >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
            = ((0x00ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U]) 
               | (0xff000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U] 
            = ((0xff000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[1U]) 
               | (0x00ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U]));
    }
    if ((0U != (0x0000001fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 >> 0x00000013U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000013U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 5359, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 >> 0x00000013U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                 << 0x0000000dU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000013U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
            = ((0xff07ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U]) 
               | (0x00f80000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 >> 0x0000000fU)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x0000000fU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5369, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 >> 0x0000000fU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                 << 0x00000011U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x0000000fU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
            = ((0xfff87fffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U]) 
               | (0x00078000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 >> 8U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5377, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 >> 8U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                              >> 8U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
            = ((0xffff80ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U]) 
               | (0x00007f00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 >> 1U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                             << 0x0000001fU) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                               >> 1U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5391, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                 >> 1U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                            << 0x0000001fU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
                                              >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
            = ((0xffffff01U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U]) 
               | (0x000000feU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U]));
    }
    if ((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5405, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffeU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i[0U]) 
               | (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U]));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed 
        = ((0U == (7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                         >> 9U))) | ((1U == (7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                                   >> 9U))) 
                                     | (4U == (7U & 
                                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                                >> 9U)))));
    __Vfunc_mubi4_test_invalid__9__val = (0x0000000fU 
                                          & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                             >> 0x0000000fU));
    __Vfunc_mubi4_test_invalid__9__Vfuncout = (1U & 
                                               (~ (
                                                   (6U 
                                                    == (IData)(__Vfunc_mubi4_test_invalid__9__val)) 
                                                   | (9U 
                                                      == (IData)(__Vfunc_mubi4_test_invalid__9__val)))));
    if (((6U != (IData)(__Vfunc_mubi4_test_invalid__9__val)) 
         & (9U != (IData)(__Vfunc_mubi4_test_invalid__9__val)))) {
        ++(vlSymsp->__Vcoverage[10970]);
    }
    if ((9U == (IData)(__Vfunc_mubi4_test_invalid__9__val))) {
        ++(vlSymsp->__Vcoverage[10971]);
    }
    if ((6U == (IData)(__Vfunc_mubi4_test_invalid__9__val))) {
        ++(vlSymsp->__Vcoverage[10972]);
    }
    ++(vlSymsp->__Vcoverage[10973]);
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err 
        = __Vfunc_mubi4_test_invalid__9__Vfuncout;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full 
        = (0U == (7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                        >> 9U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get 
        = (4U == (7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                        >> 9U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial 
        = (1U == (7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                        >> 9U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask 
        = (0x0000000fU & ((IData)(1U) << (3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                                >> 0x0000001cU))));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 4660, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_addr 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_o;
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wdata_o 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wdata_o))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4670, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wdata_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wdata_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wdata_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wdata_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_wdata 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wdata_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__be_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__be_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4734, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__be_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__be_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__be_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__be_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_be 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__be_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__opcode_allowed))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5409, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__opcode_allowed);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__opcode_allowed 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__instr_type_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5425, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__instr_type_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__instr_type_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_full))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5413, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_full);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_full 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_get))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5417, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_get);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_get 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_partial))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5415, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_partial);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_partial 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial;
    }
    __Vfunc_mubi4_test_true_strict__8__val = (0x0000000fU 
                                              & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                                 >> 0x0000000fU));
    uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VExpr_h9250fec5__0 
        = (6U == (IData)(__Vfunc_mubi4_test_true_strict__8__val));
    ++(vlSymsp->__Vcoverage[10977]);
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err 
        = ((IData)(uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VExpr_h9250fec5__0) 
           & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full) 
              | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial)));
    if (((IData)(uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VExpr_h9250fec5__0) 
         & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial))) {
        ++(vlSelf->__Vcoverage[5421]);
    }
    if (((IData)(uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VExpr_h9250fec5__0) 
         & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full))) {
        ++(vlSelf->__Vcoverage[5422]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial))))) {
        ++(vlSelf->__Vcoverage[5423]);
    }
    if ((1U & (~ (IData)(uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VExpr_h9250fec5__0)))) {
        ++(vlSelf->__Vcoverage[5424]);
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__mask)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5442, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__mask);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__mask 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk = 0U;
    if ((0x00001000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U])) {
        if ((0U == (3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                          >> 4U)))) {
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk = 1U;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk 
                = (1U & (~ (0U != (0x0000000fU & ((
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                                    << 8U) 
                                                   | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                                      >> 0x00000018U)) 
                                                  & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask)))))));
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk 
                = (0U != (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                            << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                      >> 0x00000018U)) 
                          & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask)));
            if ((1U & ((((~ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                              >> 0x00000018U) & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask)))) 
                         & (~ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                >> 0x00000019U) & (~ 
                                                   ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                                    >> 1U))))) 
                        & (~ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                               >> 0x0000001aU) & (~ 
                                                  ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                                   >> 2U))))) 
                       & (~ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                              >> 0x0000001bU) & (~ 
                                                 ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                                  >> 3U))))))) {
                ++(vlSelf->__Vcoverage[5450]);
            }
            if ((1U & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                        >> 0x0000001bU) & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                              >> 3U))))) {
                ++(vlSelf->__Vcoverage[5451]);
            }
            if ((1U & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                        >> 0x0000001aU) & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                              >> 2U))))) {
                ++(vlSelf->__Vcoverage[5452]);
            }
            if ((1U & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                        >> 0x00000019U) & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                              >> 1U))))) {
                ++(vlSelf->__Vcoverage[5453]);
            }
            if ((1U & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                        >> 0x00000018U) & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask))))) {
                ++(vlSelf->__Vcoverage[5454]);
            }
            if (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                  >> 0x0000001bU) & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                     >> 3U))) {
                ++(vlSelf->__Vcoverage[5455]);
            }
            if ((1U & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                        >> 0x0000001aU) & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                           >> 2U)))) {
                ++(vlSelf->__Vcoverage[5456]);
            }
            if ((1U & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                        >> 0x00000019U) & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                           >> 1U)))) {
                ++(vlSelf->__Vcoverage[5457]);
            }
            if ((1U & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                        >> 0x00000018U) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask)))) {
                ++(vlSelf->__Vcoverage[5458]);
            }
            if ((1U & ((((~ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                              >> 0x00000018U) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask))) 
                         & (~ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                >> 0x00000019U) & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                                   >> 1U)))) 
                        & (~ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                               >> 0x0000001aU) & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                                  >> 2U)))) 
                       & (~ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                              >> 0x0000001bU) & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask) 
                                                 >> 3U)))))) {
                ++(vlSelf->__Vcoverage[5459]);
            }
            ++(vlSelf->__Vcoverage[5460]);
        } else if ((1U == (3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 >> 4U)))) {
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk 
                = (1U & (~ (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                            >> 0x0000001cU)));
            if ((0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])) {
                ++(vlSelf->__Vcoverage[5465]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VlemCond_0 
                    = (1U & (~ (0U != (3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                             >> 0x00000018U)))));
            } else {
                ++(vlSelf->__Vcoverage[5466]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VlemCond_0 
                    = (1U & (~ (0U != (0x0cU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                                >> 0x00000018U)))));
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VlemCond_0;
            if ((0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])) {
                ++(vlSelf->__Vcoverage[5469]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VlemCond_1 
                    = (3U == (3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                    >> 0x0000001aU)));
            } else {
                ++(vlSelf->__Vcoverage[5470]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VlemCond_1 
                    = (3U == (3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                    >> 0x00000018U)));
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____VlemCond_1;
            if ((1U & (~ (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                          >> 0x0000001cU)))) {
                ++(vlSelf->__Vcoverage[5461]);
            }
            if ((0x10000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])) {
                ++(vlSelf->__Vcoverage[5462]);
            }
            if ((0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])) {
                ++(vlSelf->__Vcoverage[5463]);
            }
            if ((1U & (~ (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                          >> 0x0000001dU)))) {
                ++(vlSelf->__Vcoverage[5464]);
            }
            if ((0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])) {
                ++(vlSelf->__Vcoverage[5467]);
            }
            if ((1U & (~ (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                          >> 0x0000001dU)))) {
                ++(vlSelf->__Vcoverage[5468]);
            }
            ++(vlSelf->__Vcoverage[5471]);
        } else if ((2U == (3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                 >> 4U)))) {
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk 
                = (1U & (~ (0U != (3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                         >> 0x0000001cU)))));
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk = 1U;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk 
                = (0x0000000fU == (0x0000000fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                                  >> 0x00000018U)));
            if ((IData)((0U == (0x30000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])))) {
                ++(vlSelf->__Vcoverage[5472]);
            }
            if ((0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])) {
                ++(vlSelf->__Vcoverage[5473]);
            }
            if ((0x10000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])) {
                ++(vlSelf->__Vcoverage[5474]);
            }
            if ((IData)((0x0f000000U == (0x0f000000U 
                                         & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U])))) {
                ++(vlSelf->__Vcoverage[5475]);
            }
            if ((1U & (~ (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                          >> 0x0000001bU)))) {
                ++(vlSelf->__Vcoverage[5476]);
            }
            if ((1U & (~ (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                          >> 0x0000001aU)))) {
                ++(vlSelf->__Vcoverage[5477]);
            }
            if ((1U & (~ (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                          >> 0x00000019U)))) {
                ++(vlSelf->__Vcoverage[5478]);
            }
            if ((1U & (~ (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                          >> 0x00000018U)))) {
                ++(vlSelf->__Vcoverage[5479]);
            }
            ++(vlSelf->__Vcoverage[5480]);
        } else {
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk = 0U;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk = 0U;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk = 0U;
            ++(vlSelf->__Vcoverage[5481]);
        }
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((2U 
                                                 == 
                                                 (3U 
                                                  & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                                     >> 4U))) 
                                                << 2U) 
                                               | (((1U 
                                                    == 
                                                    (3U 
                                                     & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                                        >> 4U))) 
                                                   << 1U) 
                                                  | (0U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                                         >> 4U))))))))))) {
            if ((0U != (((2U == (3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                       >> 4U))) << 2U) 
                        | (((1U == (3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                          >> 4U))) 
                            << 1U) | (0U == (3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                                   >> 4U))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: tlul_err.sv:62: Assertion failed in %m: unique case, but multiple matches found for '32'h%X'\n",4, 'M',vlSymsp->name(),"uart_tb.u_uart.u_uart_reg.u_flexsoc_tlul_to_reg.u_err", 'T',-9
                                 , '#',64,VL_TIME_UNITED_Q(1000)
                                 , '#',32,(3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                                 >> 4U)));
                    VL_STOP_MT("/home/eneadim/github/flexsoc/vendor/lowrisc_ip/ip/tlul/rtl/tlul_err.sv", 62, "");
                }
            }
        }
        ++(vlSelf->__Vcoverage[5482]);
    } else {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk = 0U;
        ++(vlSelf->__Vcoverage[5483]);
    }
    ++(vlSelf->__Vcoverage[5484]);
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_addr) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_addr)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 1687, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_addr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_addr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_addr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_addr;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_wdata 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_wdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1697, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_wdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_wdata);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_wdata 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_wdata;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_be) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_be)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1761, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_be, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_be);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_be 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_be;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__instr_wr_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5419, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__instr_wr_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__instr_wr_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__addr_sz_chk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5436, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__addr_sz_chk);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__addr_sz_chk 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__mask_chk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5438, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__mask_chk);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__mask_chk 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__fulldata_chk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5440, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__fulldata_chk);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__fulldata_chk 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk;
    }
    if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk) 
          & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk)) 
         & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk))) {
        ++(vlSelf->__Vcoverage[5485]);
    }
    if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk) 
          & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk)) 
         & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial))) {
        ++(vlSelf->__Vcoverage[5486]);
    }
    if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk) 
          & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk)) 
         & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get))) {
        ++(vlSelf->__Vcoverage[5487]);
    }
    if ((1U & (((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get)) 
                & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial))) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk))))) {
        ++(vlSelf->__Vcoverage[5488]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk)))) {
        ++(vlSelf->__Vcoverage[5489]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk)))) {
        ++(vlSelf->__Vcoverage[5490]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk) 
           & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk) 
              & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get) 
                 | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial) 
                    | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk)))));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__a_config_allowed))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5411, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__a_config_allowed);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__a_config_allowed 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err) {
        ++(vlSelf->__Vcoverage[5427]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err) {
        ++(vlSelf->__Vcoverage[5428]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed)))) {
        ++(vlSelf->__Vcoverage[5429]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed)))) {
        ++(vlSelf->__Vcoverage[5430]);
    }
    if (((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed) 
           & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed)) 
          & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err))) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err)))) {
        ++(vlSelf->__Vcoverage[5431]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__err_o 
        = (1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err) 
                 | ((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed) 
                        & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed))) 
                    | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err))));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__err_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__err_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5407, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__err_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__err_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__err_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__err_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_err 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__err_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4956, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_err;
    }
}

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7ffeU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (1U & (IData)(((0U != (6U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                            | (6U == (6U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)))))));
    if ((4U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3379]);
    }
    if ((2U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3380]);
    }
    if ((IData)((6U == (6U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[3381]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 2U)) & (0U == (6U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3382]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 1U)) & (0U == (6U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3383]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7ffdU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (2U & ((IData)(((0U != (0x0018U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                             | (0x0018U == (0x0018U 
                                            & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) 
                    << 1U)));
    if ((0x00000010U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3392]);
    }
    if ((8U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3393]);
    }
    if ((IData)((0x0018U == (0x0018U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[3394]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 4U)) & (0U == (0x0018U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3395]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 3U)) & (0U == (0x0018U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3396]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7ffbU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (4U & ((IData)(((0U != (0x0060U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                             | (0x0060U == (0x0060U 
                                            & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) 
                    << 2U)));
    if ((0x00000040U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3405]);
    }
    if ((0x00000020U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3406]);
    }
    if ((IData)((0x0060U == (0x0060U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[3407]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 6U)) & (0U == (0x0060U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3408]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 5U)) & (0U == (0x0060U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3409]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7ff7U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (8U & ((IData)(((0U != (0x0180U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                             | (0x0180U == (0x0180U 
                                            & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) 
                    << 3U)));
    if ((0x00000100U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3418]);
    }
    if ((0x00000080U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3419]);
    }
    if ((IData)((0x0180U == (0x0180U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[3420]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 8U)) & (0U == (0x0180U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3421]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 7U)) & (0U == (0x0180U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3422]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7fefU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (0x00000010U & ((IData)(((0U != (0x0600U 
                                              & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                                      | (0x0600U == 
                                         (0x0600U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) 
                             << 4U)));
    if ((0x00000400U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3431]);
    }
    if ((0x00000200U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3432]);
    }
    if ((IData)((0x0600U == (0x0600U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[3433]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 0x0000000aU)) & (0U == (0x0600U 
                                                & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3434]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 9U)) & (0U == (0x0600U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3435]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7fdfU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (0x00000020U & ((IData)(((0U != (0x1800U 
                                              & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                                      | (0x1800U == 
                                         (0x1800U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) 
                             << 5U)));
    if ((0x00001000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3444]);
    }
    if ((0x00000800U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3445]);
    }
    if ((IData)((0x1800U == (0x1800U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[3446]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 0x0000000cU)) & (0U == (0x1800U 
                                                & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3447]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 0x0000000bU)) & (0U == (0x1800U 
                                                & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3448]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7fbfU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (0x00000040U & ((IData)(((0U != (0x6000U 
                                              & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                                      | (0x6000U == 
                                         (0x6000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) 
                             << 6U)));
    if ((0x00004000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3457]);
    }
    if ((0x00002000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3458]);
    }
    if ((IData)((0x6000U == (0x6000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[3459]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 0x0000000eU)) & (0U == (0x6000U 
                                                & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3460]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 0x0000000dU)) & (0U == (0x6000U 
                                                & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3461]);
    }
}

void Vtop___024root___act_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop___024root___act_sequent__TOP__2(Vtop___024root* vlSelf);
void Vtop___024root___act_sequent__TOP__3(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__stl
        vlSelfRef.__VstlTriggered[1U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VstlTriggered[1U]) 
                                         | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
        vlSelfRef.__VstlTriggered[0U] = (QData)((IData)(
                                                        ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                                                           != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree__0)) 
                                                          << 4U) 
                                                         | (((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree__0)) 
                                                              << 3U) 
                                                             | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                                                                 != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree__0)) 
                                                                << 2U)) 
                                                            | ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re) 
                                                                 != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re__0)) 
                                                                << 1U) 
                                                               | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we) 
                                                                  != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we__0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we;
        vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re__0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re;
        vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree__0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree;
        vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree__0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree;
        vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree__0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree;
        if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VstlDidInit)))))) {
            vlSelfRef.__VstlDidInit = 1U;
            vlSelfRef.__VstlTriggered[0U] = (1ULL | vlSelfRef.__VstlTriggered[0U]);
            vlSelfRef.__VstlTriggered[0U] = (2ULL | vlSelfRef.__VstlTriggered[0U]);
            vlSelfRef.__VstlTriggered[0U] = (4ULL | vlSelfRef.__VstlTriggered[0U]);
            vlSelfRef.__VstlTriggered[0U] = (8ULL | vlSelfRef.__VstlTriggered[0U]);
            vlSelfRef.__VstlTriggered[0U] = (0x0000000000000010ULL 
                                             | vlSelfRef.__VstlTriggered[0U]);
        }
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_stl
            if ((1ULL & vlSelfRef.__VstlTriggered[1U])) {
                Vtop___024root___stl_sequent__TOP__0(vlSelf);
            }
            if ((0x000000000000000cULL & vlSelfRef.__VstlTriggered[0U])) {
                Vtop___024root___stl_sequent__TOP__1(vlSelf);
            }
            if ((4ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vtop___024root___act_sequent__TOP__1(vlSelf);
            }
            if ((0x0000000000000010ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vtop___024root___act_sequent__TOP__2(vlSelf);
            }
            if (((1ULL & vlSelfRef.__VstlTriggered[1U]) 
                 | (3ULL & vlSelfRef.__VstlTriggered[0U]))) {
                Vtop___024root___act_sequent__TOP__3(vlSelf);
            }
            if (((1ULL & vlSelfRef.__VstlTriggered[1U]) 
                 | (0x000000000000000cULL & vlSelfRef.__VstlTriggered[0U]))) {
                {
                    // Inlined CFunc: _stl_comb__TOP__1
                    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree) 
                                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_tree)))) {
                        VL_COV_TOGGLE_CHG_ST_I(15, vlSelf->__Vcoverage + 3341, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_tree);
                        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_tree 
                            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree;
                    }
                }
            }
            if (((1ULL & vlSelfRef.__VstlTriggered[1U]) 
                 | (7ULL & vlSelfRef.__VstlTriggered[0U]))) {
                {
                    // Inlined CFunc: _act_comb__TOP__0
                    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree)))) {
                        VL_COV_TOGGLE_CHG_ST_I(15, vlSelf->__Vcoverage + 3281, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree);
                        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree 
                            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree;
                    }
                }
            }
            if (((1ULL & vlSelfRef.__VstlTriggered[1U]) 
                 | (0x0000000000000013ULL & vlSelfRef.__VstlTriggered[0U]))) {
                {
                    // Inlined CFunc: _act_comb__TOP__1
                    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree)))) {
                        VL_COV_TOGGLE_CHG_ST_I(15, vlSelf->__Vcoverage + 3311, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree);
                        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree 
                            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree;
                    }
                }
            }
        }
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @([hybrid] uart_tb.u_uart.u_uart_reg.flexsoc_tlul_we)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([hybrid] uart_tb.u_uart.u_uart_reg.flexsoc_tlul_re)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @([hybrid] uart_tb.u_uart.u_uart_reg.flexsoc_tlul_we)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([hybrid] uart_tb.u_uart.u_uart_reg.flexsoc_tlul_re)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([hybrid] uart_tb.u_uart.u_uart_reg.u_reg_core.u_prim_reg_we_check.u_prim_onehot_check.or_tree)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @([hybrid] uart_tb.u_uart.u_uart_reg.u_reg_core.u_prim_reg_we_check.u_prim_onehot_check.err_tree)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @([hybrid] uart_tb.u_uart.u_uart_reg.u_reg_core.u_prim_reg_we_check.u_prim_onehot_check.and_tree)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(posedge uart_tb.u_uart.u_uart_reg.u_reg_core.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @(negedge uart_tb.u_uart.u_uart_reg.u_reg_core.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @(posedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_ctrl_parity_odd.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 8 is active: @(negedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_ctrl_parity_odd.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 9 is active: @(posedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_ctrl_parity_en.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 10 is active: @(negedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_ctrl_parity_en.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 11 is active: @(posedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_ctrl_llpbk.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 12 is active: @(negedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_ctrl_llpbk.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 13 is active: @(posedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_ctrl_slpbk.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 14 is active: @(negedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_ctrl_slpbk.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 15 is active: @(posedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_ctrl_nf.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000010U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 16 is active: @(negedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_ctrl_nf.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000011U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 17 is active: @(posedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_ctrl_rx.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000012U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 18 is active: @(negedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_ctrl_rx.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000013U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 19 is active: @(posedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_ctrl_tx.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000014U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 20 is active: @(negedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_ctrl_tx.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000015U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 21 is active: @(posedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_fifo_ctrl0_qe.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000016U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 22 is active: @(negedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_fifo_ctrl0_qe.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000017U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 23 is active: @(posedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_wdata0_qe.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000018U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 24 is active: @(negedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_wdata0_qe.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000019U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 25 is active: @(posedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_fifo_ctrl_txrst.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000001aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 26 is active: @(negedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_fifo_ctrl_txrst.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000001bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 27 is active: @(posedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_fifo_ctrl_rxrst.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000001cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 28 is active: @(negedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_fifo_ctrl_rxrst.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000001dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 29 is active: @(posedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_wdata.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000001eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 30 is active: @(negedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_wdata.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000001fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 31 is active: @(posedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_ctrl_nco.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000020U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 32 is active: @(negedge uart_tb.u_uart.u_uart_reg.u_reg_core.u_ctrl_nco.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000021U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 33 is active: @(posedge uart_tb.u_uart.u_uart_reg.u_flexsoc_tlul_to_reg.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000022U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 34 is active: @(negedge uart_tb.u_uart.u_uart_reg.u_flexsoc_tlul_to_reg.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000023U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 35 is active: @(posedge uart_tb.u_uart.u_uart_core.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000024U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 36 is active: @(negedge uart_tb.u_uart.u_uart_core.timing_rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000025U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 37 is active: @(negedge uart_tb.u_uart.u_uart_core.tx_rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000026U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 38 is active: @(negedge uart_tb.u_uart.u_uart_core.rx_rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000027U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 39 is active: @(posedge uart_tb.u_uart.u_uart_core.sync_rx.u_sync_2.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000028U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 40 is active: @(negedge uart_tb.u_uart.u_uart_core.sync_rx.u_sync_2.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000029U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 41 is active: @(posedge uart_tb.u_uart.u_uart_core.sync_rx.u_sync_1.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000002aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 42 is active: @(negedge uart_tb.u_uart.u_uart_core.sync_rx.u_sync_1.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000002bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 43 is active: @(posedge uart_tb.u_uart.u_uart_core.u_rx_reset_branch.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000002cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 44 is active: @(negedge uart_tb.u_uart.u_uart_core.u_rx_reset_branch.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000002dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 45 is active: @(posedge uart_tb.u_uart.u_uart_core.u_tx_reset_branch.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000002eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 46 is active: @(negedge uart_tb.u_uart.u_uart_core.u_tx_reset_branch.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000002fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 47 is active: @(posedge uart_tb.u_uart.u_uart_core.u_timing_reset_branch.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000030U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 48 is active: @(negedge uart_tb.u_uart.u_uart_core.u_timing_reset_branch.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000031U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 49 is active: @(posedge uart_tb.u_uart.u_uart_core.u_uart_rxfifo.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000032U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 50 is active: @(negedge uart_tb.u_uart.u_uart_core.u_uart_rxfifo.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000033U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 51 is active: @(posedge uart_tb.u_uart.u_uart_core.u_uart_rxfifo.gen_normal_fifo.u_fifo_cnt.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000034U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 52 is active: @(negedge uart_tb.u_uart.u_uart_core.u_uart_rxfifo.gen_normal_fifo.u_fifo_cnt.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000035U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 53 is active: @(posedge uart_tb.u_uart.u_uart_core.u_uart_txfifo.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000036U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 54 is active: @(negedge uart_tb.u_uart.u_uart_core.u_uart_txfifo.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000037U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 55 is active: @(posedge uart_tb.u_uart.u_uart_core.u_uart_txfifo.gen_normal_fifo.u_fifo_cnt.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000038U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 56 is active: @(negedge uart_tb.u_uart.u_uart_core.u_uart_txfifo.gen_normal_fifo.u_fifo_cnt.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000039U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 57 is active: @(posedge uart_tb.u_uart.u_uart_core.uart_rx.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000003aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 58 is active: @(negedge uart_tb.u_uart.u_uart_core.uart_rx.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000003bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 59 is active: @(posedge uart_tb.u_uart.u_uart_core.uart_tx.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000003cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 60 is active: @(negedge uart_tb.u_uart.u_uart_core.uart_tx.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000003dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 61 is active: @(posedge uart_tb.u_uart.u_core_reset_sync.u_sync_2.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000003eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 62 is active: @(negedge uart_tb.u_uart.u_core_reset_sync.u_sync_2.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000003fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 63 is active: @(posedge uart_tb.u_uart.u_core_reset_sync.u_sync_1.clk_i)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: @(negedge uart_tb.u_uart.u_core_reset_sync.u_sync_1.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[1U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 65 is active: @(posedge uart_tb.u_uart.u_reg_reset_sync.u_sync_2.clk_i)\n");
    }
    if ((1U & (IData)((triggers[1U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 66 is active: @(negedge uart_tb.u_uart.u_reg_reset_sync.u_sync_2.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[1U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 67 is active: @(posedge uart_tb.u_uart.u_reg_reset_sync.u_sync_1.clk_i)\n");
    }
    if ((1U & (IData)((triggers[1U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 68 is active: @(negedge uart_tb.u_uart.u_reg_reset_sync.u_sync_1.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[1U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 69 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->uart_tb__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6480447040330586719ull);
    vlSelf->uart_tb__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4555623571075219510ull);
    vlSelf->uart_tb__DOT__rx_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6635424889456572476ull);
    vlSelf->uart_tb__DOT__tx_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11737196236284880681ull);
    vlSelf->uart_tb__DOT__tl_i_a_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4130645447212817453ull);
    vlSelf->uart_tb__DOT__tl_i_a_opcode = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17554213701227288352ull);
    vlSelf->uart_tb__DOT__tl_i_a_param = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6643798511836796552ull);
    vlSelf->uart_tb__DOT__tl_i_a_size = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 293302313683980942ull);
    vlSelf->uart_tb__DOT__tl_i_a_source = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 744535119523309292ull);
    vlSelf->uart_tb__DOT__tl_i_a_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16965528148422612752ull);
    vlSelf->uart_tb__DOT__tl_i_a_mask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8665087884611458101ull);
    vlSelf->uart_tb__DOT__tl_i_a_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16105193417391689725ull);
    vlSelf->uart_tb__DOT__tl_i_d_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4104414573424792842ull);
    vlSelf->uart_tb__DOT__tl_o_d_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6807321223891775135ull);
    vlSelf->uart_tb__DOT__tl_o_d_opcode = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18052687718927991085ull);
    vlSelf->uart_tb__DOT__tl_o_d_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16465327364602503040ull);
    vlSelf->uart_tb__DOT__tl_o_d_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7860208179214051108ull);
    vlSelf->uart_tb__DOT__tl_o_a_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4437642236268013105ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->uart_tb__DOT__tl_i, __VscopeHash, 3156883820538632636ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->uart_tb__DOT__tl_o, __VscopeHash, 3225584687665651513ull);
    vlSelf->uart_tb__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT____Vtogcov__rx_i = 0;
    vlSelf->uart_tb__DOT____Vtogcov__tx_o = 0;
    vlSelf->uart_tb__DOT____Vtogcov__tl_i_a_valid = 0;
    vlSelf->uart_tb__DOT____Vtogcov__tl_i_a_opcode = 0;
    vlSelf->uart_tb__DOT____Vtogcov__tl_i_a_param = 0;
    vlSelf->uart_tb__DOT____Vtogcov__tl_i_a_size = 0;
    vlSelf->uart_tb__DOT____Vtogcov__tl_i_a_source = 0;
    vlSelf->uart_tb__DOT____Vtogcov__tl_i_a_address = 0;
    vlSelf->uart_tb__DOT____Vtogcov__tl_i_a_mask = 0;
    vlSelf->uart_tb__DOT____Vtogcov__tl_i_a_data = 0;
    vlSelf->uart_tb__DOT____Vtogcov__tl_i_d_ready = 0;
    vlSelf->uart_tb__DOT____Vtogcov__tl_o_d_valid = 0;
    vlSelf->uart_tb__DOT____Vtogcov__tl_o_d_opcode = 0;
    vlSelf->uart_tb__DOT____Vtogcov__tl_o_d_data = 0;
    vlSelf->uart_tb__DOT____Vtogcov__tl_o_d_error = 0;
    vlSelf->uart_tb__DOT____Vtogcov__tl_o_a_ready = 0;
    VL_ZERO_RESET_W(109, vlSelf->uart_tb__DOT____Vtogcov__tl_i);
    VL_ZERO_RESET_W(66, vlSelf->uart_tb__DOT____Vtogcov__tl_o);
    vlSelf->uart_tb__DOT__u_uart__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7702570960820415159ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14793835694556304188ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__rx_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6313273318046040590ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__tx_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16024859491801214352ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->uart_tb__DOT__u_uart__DOT__tl_i, __VscopeHash, 11466721673772849838ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->uart_tb__DOT__u_uart__DOT__tl_o, __VscopeHash, 8206365888856543008ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__reg2hw = VL_SCOPED_RAND_RESET_Q(57, __VscopeHash, 1439068460872395296ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__hw2reg = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 6252393835893573519ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__reg_rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8402007870504476016ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__core_rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3232068797416963164ull);
    vlSelf->uart_tb__DOT__u_uart__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT____Vtogcov__rx_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT____Vtogcov__tx_o = 0;
    VL_ZERO_RESET_W(109, vlSelf->uart_tb__DOT__u_uart__DOT____Vtogcov__tl_i);
    VL_ZERO_RESET_W(66, vlSelf->uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o);
    vlSelf->uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT____Vtogcov__core_rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 760239562877338150ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5889763379568758699ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i, __VscopeHash, 3660895901443630784ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o, __VscopeHash, 13865008911184917374ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw = VL_SCOPED_RAND_RESET_Q(57, __VscopeHash, 2643309682608164089ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 15768886074355009751ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__devmode_i = 1U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12830313650930950156ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3515276140525183641ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3803628277099471959ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11217145539712581273ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17057657292757063545ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_req = VL_SCOPED_RAND_RESET_Q(43, __VscopeHash, 14277070653560673827ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 18404489723878037327ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__rst_ni = 0;
    VL_ZERO_RESET_W(109, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_i);
    VL_ZERO_RESET_W(66, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__devmode_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_re = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_addr = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_wdata = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_be = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_reg_req = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11649327856322972398ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 689066087732413975ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i = VL_SCOPED_RAND_RESET_Q(43, __VscopeHash, 8353605544566055905ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 8942361115315070705ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw = VL_SCOPED_RAND_RESET_Q(57, __VscopeHash, 6230970769209773477ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 16483476309034023161ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__devmode_i = 1U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17293530785435513444ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5613984115911880480ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14469277615899422231ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1620311814598147965ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7875318923535446003ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8183828507364940098ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4676861489784524365ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12283370237012005848ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addrmiss = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11530874410314620137ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wr_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2614539617059282286ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9860001994602378191ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_busy = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6249915178129892198ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_check = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 6648254060881529009ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18102400582581888688ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7300159225390607112ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2684224995466943120ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9973865196261096404ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10904754995071681269ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15745259194736968638ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12938274489044222023ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1781170616128943907ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 204634483803003108ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17867269175240940030ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12244729880958595445ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12126697383598027304ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6317966348762712349ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7590599979576092856ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 901495724690765244ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7609044647218073108ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1224915520687294507ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_wd = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9117147886630831669ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10697999519681381363ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3802807167369605407ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15113422334605984730ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11983700793876485883ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17544999657097605788ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2910579892390244074ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3294017095796212149ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17909603871066728730ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6283525617250985382ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13142558831023253247ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_wd = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4409490700439703143ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9912935070339928014ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_rxrst_wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6838970517039644361ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_txrst_wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17381396048526432073ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9045208373529267483ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6292140722433248162ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9644467188741854517ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3555791055649425302ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_flds_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5283026083934216898ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10831948456219566283ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_flds_we = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13421828775015918854ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 2201001903044192410ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__shadow_busy = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_wdata = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11688684732480591131ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_be = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15884690623193541152ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_re = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_addr = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_wdata = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_be = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_error = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__addrmiss = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wr_err = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_busy = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_err = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_check = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__err_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_re = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txfull_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxfull_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txempty_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txidle_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxidle_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxempty_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rdata_re = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rdata_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_rxrst_wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_txrst_wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_re = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_txlvl_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_rxlvl_qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_qe = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_flds_we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_qe = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_flds_we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__addr_hit = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__unused_wdata = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__unused_be = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2352509382781287336ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1550289500660781654ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4940178616769485889ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13663993140703650329ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13444551113332449313ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 701681774169864228ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12999576356168083487ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2026068992724198677ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11807204669635813047ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15237684710538944180ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qe = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2655215322510701140ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14772539898523281115ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15742631199248361467ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14553166350445309113ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13156040328252302684ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16049729325385195107ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 561539622030757630ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10070904738940669589ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12952285322666615876ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14350211556523167694ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15775808873035455207ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8118116063811496602ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13858509192878165578ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14501016361592638700ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7756489299921847977ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7814535707452495958ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qe = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14471421127214988737ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12844083945944916996ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7730199013430221989ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8266976237139941089ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9896641452578685078ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3185312077663607828ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1031541286846462632ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9555170275243344841ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14372852571879933927ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17348458923949546742ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9037572626538675397ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16867113351017744531ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1361969850849823533ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 454935804555686283ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13327025412041740432ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3301609290234659498ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qe = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3920685011290003084ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15233495609273826561ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15224462872081203194ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2344362746823508723ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8402896046219806219ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12188759680063160736ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4982255508027080178ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16366334674341845892ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1293941916035667186ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14229749560280708609ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5393174909044327435ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1765520484771407533ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5885221842283035161ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17757812030872762391ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7713608590429678372ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3870656171712223665ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qe = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 72244337620329446ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 712113556341499043ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5955577615188596628ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17642312933369887977ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5227158387312715339ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18211292069026496839ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8589453394173396033ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17755841886290215313ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1682254776520042024ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16469874686008086987ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8914348430420838342ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1310339194875007875ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14420867991648173141ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12900450440358177178ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3310498630181660556ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9703215376165708524ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qe = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17219764634584081780ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14416145386021370520ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16621417407420997694ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6802250213119095810ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8626123923202165267ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17692281005206890039ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2889547703673460155ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13142355311744020695ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14935430575745636585ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15512664321291252484ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11126380042524870092ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15175015069152728344ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16529488158163169264ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1695570152165275604ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1328240159068213422ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1417852885380040319ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qe = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10673356180904592669ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14147990988745574795ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14971809002603681774ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5554807658921340111ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5710582274350279243ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9024291959356475363ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4054979361782275487ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6001827478796675372ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15173972345942282611ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15332825786757581580ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 608788977041844170ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6284880365879060659ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9364863154264796113ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16422467609021551448ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3825791427368627342ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12045038033894704253ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qe = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13464383294205247652ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13584519179540588851ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12977234624125972642ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5895673100691959261ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1922600984671243113ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7323757647157839082ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11699620394181327411ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13117327915489172720ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__d_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 247737535369442594ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7095291968907846753ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__d_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__q_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 527677917135506923ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11810850461041514969ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__d_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7986181142470912845ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12708706325739755484ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__d_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__q_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16546842851463236821ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__we = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__wd = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14878576917359360527ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qe = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13617721207057202760ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__q = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9495676298968978573ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17147554804633514012ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__re = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__qre = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3645495813960157270ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__we = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__wd = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14570969649035163926ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qe = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16224967932181636536ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__q = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11530428911667800446ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1473326686657899966ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__re = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__qre = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8367244111254415634ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__we = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__wd = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12637072604117065135ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qe = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5460577263460873684ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__q = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8212286723069589130ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17974092332039019104ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__re = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__qre = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9458392441679345738ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__we = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__wd = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2884005179087995813ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qe = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13311063560729468281ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__q = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8198954203896002185ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3142027255374039972ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__re = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__qre = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16620783677518779297ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__we = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__wd = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5309557124526353712ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qe = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17233937001864190930ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__q = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12320361288427938927ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6397136934414367568ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__re = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__qre = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 358184996901745410ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__we = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__wd = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4821722033375728285ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qe = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8034354964762154011ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__q = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13508775687259058493ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7952446520208405745ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__re = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__qre = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12650719280068995302ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12671243283703999051ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 7570268079367506480ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17484352791613993339ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5519568618069943477ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 14095329602892330378ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__en_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__err_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_buf = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7568663104263340778ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12632907795110395331ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 11612450677094107814ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__addr_i = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12819706996177824698ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 616158144581043965ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 8025805576536591381ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 11575997374179134220ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 8586983973799193073ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__oh_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__addr_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__en_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_tree = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 17144264554650496086ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 17341211588618180453ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 8848219960676419378ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__in_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__out_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__inv = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5899540903792570962ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1194535888523437780ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12535935333793637028ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4038651585243774991ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6854463230873010313ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16039447163667785976ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11751862545139621948ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17558867199783068554ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2195865007055610775ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8521617239134795199ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qe = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13188565859542177536ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5342537280469593604ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13269269668428174224ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17524832338106693823ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2547528816110041405ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3111311734809164849ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10468069789261698187ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9624440290207131337ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12773349917038269012ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6572782819551080638ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 539222120258631669ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9327349652016794050ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13669410817626134457ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10023465523664464321ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9957877652904763865ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11374759473862052942ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qe = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12504702514616278795ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13360287101773439662ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4831192949612901417ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9727911212795112104ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4599852653693364926ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15509339292794254603ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16079229569344552235ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__we = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__wd = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11951521203949670307ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qe = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15711751786749945656ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__q = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8753636731335425923ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9605048948418338952ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__re = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__qre = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11914136913908687961ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__we = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__wd = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13096512140404323101ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qe = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8424272504436101295ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__q = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 802146486282984111ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15697653195856455345ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__re = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__qre = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10801191808061870969ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15513541671740989007ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7492539037945002363ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wd = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14173739357510023434ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4108702203300978499ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15691987095709876386ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17083081552276198797ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9016294304652791445ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4979779633703637496ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3533764217998966927ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qe = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8130816254002016674ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4908185259952388229ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15963938488641730230ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8015072428688274547ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2775248490740436090ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15297570453710029405ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__re = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15139945117557868870ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__we = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__wd = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1038071976894637299ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qe = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qre = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15024876000047271259ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__q = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8428499703690367556ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9885231179299532470ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__re = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__qre = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16618720623611961777ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3356291229429635196ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6089964650198678661ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wd = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 62287043554012259ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12272815337437935463ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17070301080780848680ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 652001183200852229ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16776996400608251438ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17874320631386022788ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1459644822570354231ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qe = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__ds = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qs = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7999722300290880893ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wd = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9814445253128104535ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__de = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__d = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1293165830804667134ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14988567222044527397ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4873429577501212742ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__we = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__wd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12434592985973798261ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10419062826021713067ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2003717604394729247ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i, __VscopeHash, 9404745378790518611ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o, __VscopeHash, 12524623175539765733ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__en_ifetch_i = 9U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__intg_error_o = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9338807731197213536ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15265170720163521644ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9137230146046111731ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wdata_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10989979766698354804ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__be_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10388534119096523435ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18142721904901482012ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17871437902292252089ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5263367625053237955ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15309668886674094760ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11986285408579862871ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14389809296123459770ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8270739779795642040ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3711413664574532258ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4183707943677914330ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3193269255238844695ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14703838896828119640ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__instr_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10918042111420807576ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__intg_error = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18053958843424986000ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__malformed_meta_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10620959571483967902ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15859640908286821036ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10893200321109113502ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1147140905210114708ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13538772578142324702ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 809717239811761359ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15737005569488133232ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre, __VscopeHash, 5014633293989456982ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rst_ni = 0;
    VL_ZERO_RESET_W(109, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_i);
    VL_ZERO_RESET_W(66, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__en_ifetch_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__re_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__we_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wdata_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__be_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__busy_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__outstanding_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__a_ack = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__d_ack = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__err_internal = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__instr_error = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_align_err = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__malformed_meta_err = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_err = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqid_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqsz_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rspop_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rd_req = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wr_req = 0;
    VL_ZERO_RESET_W(66, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8317390134177763639ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5192780908362048977ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i, __VscopeHash, 8450108817053731294ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14900298380383732008ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9667318891872187338ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2293587838201002082ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16204498386117143123ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9708360881947816081ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2134491301818857481ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16478707247581977304ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11659724229798379821ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1700608510361256450ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1195752226971511460ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18214196162956452618ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6800174209655592146ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__rst_ni = 0;
    VL_ZERO_RESET_W(109, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__tl_i);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__err_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__opcode_allowed = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__a_config_allowed = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_full = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_partial = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__op_get = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__instr_wr_err = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__instr_type_err = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__addr_sz_chk = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__mask_chk = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__fulldata_chk = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__mask = 0;
    VL_SCOPED_RAND_RESET_W(66, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i, __VscopeHash, 5700130523590092137ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o, __VscopeHash, 14978114116020996114ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8298992534325817981ull);
    VL_ZERO_RESET_W(66, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i);
    VL_ZERO_RESET_W(66, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10171825616702157852ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1676553432385016018ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw = VL_SCOPED_RAND_RESET_Q(57, __VscopeHash, 7661361253582196123ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 8420855289376036577ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15874820860234325365ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13052138312667191465ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_val_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7152639492658934162ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6591001420823559119ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13639971660000685785ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11422780897181629335ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9005275648766176039ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17228221994488617617ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_prev_q = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10692442064294698168ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_d = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 7594991617319545131ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_q = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5991469047921687557ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_val = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13207924113482475484ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_changed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9887886588115572831ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15525226612235907291ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18179200697255587108ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_enable = 1U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2485112930639852322ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10259642761907476248ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9518521753933378074ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7690132163245702399ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18327963698283645318ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1173354654189446065ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2711326752131783244ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2386751615810417596ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5647916794744070629ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11595696357815756951ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10849596235002042926ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5224431038009010334ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11869340823227686706ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13460646187315776602ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6127158678482274252ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 964960997559933066ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16521013650083583070ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14540769315310112615ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1863023438175295873ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1788076069333805091ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__break_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13560374721957348658ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_d = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5613718764692679012ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_q = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1969443992489607760ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17658063066955664743ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__not_allzero_char = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12646840337663179356ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_watermark = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1292783025297670586ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17444442685686761936ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_watermark = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10855140678247792552ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 633452245384306823ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_overflow = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13701774859694437041ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17452661114331033855ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_break_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9959529329674133138ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_timeout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14278108220981987888ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12999227418982859478ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13596787837197651596ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17642067318006302686ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18097468635994560968ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18024565474688444010ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18262261929281132688ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17313830220341816497ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16818838599594836204ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 9524107675074023447ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14826960786764122268ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8662858575590964446ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8785102177409583688ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18277413935401718506ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_val_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rdata = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tick_baud_x16 = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_tick_baud = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_depth = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth_prev_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_timeout_count_d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_timeout_count_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rxto_val = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth_changed = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rxto_en = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_enable = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__sys_loopback = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__line_loopback = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rxnf_enable = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_rxrst = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_txrst = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rready = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rvalid = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wready = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_valid = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wvalid = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_rvalid = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wready = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_uart_idle = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__break_err = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_cnt_d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_cnt_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_err = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__not_allzero_char = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_watermark = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_empty = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_watermark = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_done = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_overflow = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_frame_err = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_break_err = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_timeout = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_parity_err = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__timing_rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_pop = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wdata = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wvalid = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__nco_sum_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q1 = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q2 = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_mx = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_maj = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16987478689473854652ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2334900109304452377ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3898402130945295888ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7150009837482030363ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17722446401636369297ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7783597192538076708ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__unused_sig = 1U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__d_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__q_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__d_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__intq = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12356096971604029086ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3600478408568454745ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11962025936848870406ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 803160207669396136ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__d_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__q_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 116875509266911231ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5786275910376920429ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__d_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5774497264586863303ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16190984906806339037ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__d_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__q_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8232720233261036621ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12325861774670719330ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__d_i = 1U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14842667822249367854ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__d_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__q_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11432788897325528488ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18321782715102253621ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__d_i = 1U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11034589527268722133ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__q_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9652091923467754229ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13751556695947226823ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__d_i = 1U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14234590935694268788ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__q_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2564748015621478120ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6725875375278725812ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5034670724357150149ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 71219108915587697ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3347332146293512982ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13659404666477519088ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16289400375639217374ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16565254083585795873ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5616714126808633829ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2549530115105334145ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13336641499197396748ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__err_o = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clr_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wvalid_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wready_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wdata_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rvalid_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rready_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rdata_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__full_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__depth_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_empty = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifounder_rst = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifoempty = 0;
    VL_ZERO_RESET_W(128, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifordata_int = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5960438929425355916ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14937680917332423622ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8457229103862680686ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12587482373033334558ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2440964806809554452ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9606789174013880683ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1504111440202204276ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage, __VscopeHash, 17522919438168847833ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17244077226884248825ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13393400057168491074ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3078856360166944199ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18379789271608208408ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12448351581769921634ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9059091639961648007ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6444265879420349350ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5075430393923146938ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8872106178353585493ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14844767782627843858ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10538950037521179690ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17430986452743642959ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__err_o = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5290903160001805678ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7897365862384045971ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10109277225377713031ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5855240680318387124ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16033066050428031962ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14863029189372303659ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3369629147715648380ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4340650972493136953ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10031645017530212085ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5717988634746085594ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11606360143857074813ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14531061944509342204ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2463191527490291341ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16258998697446206356ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2960909206613815109ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15099949622180372009ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7755174679391334974ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6823114240929070869ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5650507411884712741ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__err_o = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clr_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wvalid_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wready_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wdata_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rvalid_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rready_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rdata_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__full_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__depth_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_empty = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifounder_rst = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifoempty = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifordata_int = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2398900222784548298ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5244929909421175505ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3826653932181819396ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14097791642944772943ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10739912082621289462ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12758068991748577923ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14091727448671053598ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16868590976775130377ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3903290067870943730ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16497275051545801109ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4719471021352110107ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9484339510455511778ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15499362769243750325ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9420387032263818929ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14789738381902086528ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1580794043680766917ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15211034331238799477ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16105630495364128197ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5781230490475376547ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11522453881044561367ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__err_o = 0U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10196315948247597784ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5922219619018604777ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5871673445225010012ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6388034261202232783ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6178816414305270195ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6678047755697088053ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5918301427778219971ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3246497008556403195ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3888884041165441099ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9450697898201930678ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_enable = 1U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7600992057872530250ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16411904267425599449ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13815275839735161501ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15071627542103952768ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11621987963155289392ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2333954304946005823ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1255244293488540910ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2068211116839265092ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7192075895545305360ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16173616163212411373ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 360331263815309511ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 13731576588629204498ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 10322081242739549654ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9058216921848952995ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13265553564385914969ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7087116848877394067ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 187820969267670010ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14847239530377666680ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5124949698946406012ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 766501394850196665ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6992839428628796106ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_x16 = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_enable = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_odd = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__frame_err = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_parity_err = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3614749483025935106ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 290216885581034844ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15435193147336519241ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11285079428986743353ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7364538260223084326ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16890929579786689320ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14940119813671702696ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 958051820148443742ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4091723418929088990ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8441637861015990378ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9510578874937352535ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4555342317225337671ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7339803614551692700ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15930585865223475740ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 7742169018649102469ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 9693413783023003067ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10314184738463958054ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13057905404349158711ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_enable = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_x16 = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__parity_enable = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_parity = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_data = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__idle = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__baud_div_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_q = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_d = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 858997743085379924ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4812915927571580254ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__d_i = 1U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11602969378903585303ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__d_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3977109743361821149ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6375074710870827665ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__q_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__d_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__intq = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6403037426910352110ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14594769344080062635ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3585613251595835086ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2943866973042367603ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3628492742776728515ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14871495545040890164ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__d_i = 1U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17386683424449136125ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10959023364014163882ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8739793730688128431ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__d_i = 1U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16685406206505857295ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__d_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2653535254110079206ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5421873547627024261ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__d_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__intq = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4816997290799622227ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11379375113346943412ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1531776749637867607ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9096802047456469988ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14187774575947175659ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14336027688604382844ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__d_i = 1U;
    ;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17414078062896946309ull);
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni = 0;
    vlSelf->uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree__0 = 0;
    vlSelf->__VstlDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    vlSelf->__VicoDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
