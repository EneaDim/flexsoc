// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree;
    vlSelfRef.__Vtrigprevexpr___TOP__uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree__0 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree;
    vlSelfRef.__VactTriggered[0U] = (1ULL | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__VactTriggered[0U] = (2ULL | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__VactTriggered[0U] = (4ULL | vlSelfRef.__VactTriggered[0U]);
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
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__devmode_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 996, 1U, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__devmode_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__devmode_i = 1U;
    }
    ++(vlSelf->__Vcoverage[1591]);
    ++(vlSelf->__Vcoverage[1804]);
    ++(vlSelf->__Vcoverage[1810]);
    ++(vlSelf->__Vcoverage[1835]);
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_busy) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1552, 0U, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_busy);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_busy = 0U;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__d) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1872, 0U, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__d = 0U;
    }
    if ((0U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__addr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 2343, 0U, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__addr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__addr_i = 0U;
    }
    if ((0U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2670, 0U, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__wd = 0U;
    }
    if ((0U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3053, 0U, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__d = 0U;
    }
    ++(vlSelf->__Vcoverage[4042]);
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__d_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4073, 1U, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__d_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__d_i = 1U;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = (0x007fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree));
    vlSelfRef.uart_tb__DOT__rx_i = 1U;
    vlSelfRef.uart_tb__DOT__reg_req_valid = 0U;
    vlSelfRef.uart_tb__DOT__reg_req_write = 0U;
    vlSelfRef.uart_tb__DOT__reg_req_addr = 0U;
    vlSelfRef.uart_tb__DOT__reg_req_wdata = 0U;
    vlSelfRef.uart_tb__DOT__reg_req_wstrb = 0U;
    ++(vlSelf->__Vcoverage[316]);
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
            VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/uart-reg_iface/runs/uart/release/dv/functional/tb/cocotb/uart_tb.sv", 2, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @([hybrid] uart_tb.u_uart.u_uart_reg.u_reg_core.u_prim_reg_we_check.u_prim_onehot_check.or_tree)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([hybrid] uart_tb.u_uart.u_uart_reg.u_reg_core.u_prim_reg_we_check.u_prim_onehot_check.err_tree)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([hybrid] uart_tb.u_uart.u_uart_reg.u_reg_core.u_prim_reg_we_check.u_prim_onehot_check.and_tree)\n");
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
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_2;
    __VdfgRegularize_h6e95ff9d_0_2 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_3;
    __VdfgRegularize_h6e95ff9d_0_3 = 0;
    // Body
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q) 
         & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
               >> 0x0aU)))) {
        ++(vlSelf->__Vcoverage[5164]);
    }
    if ((0x00000400U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q))) {
        ++(vlSelf->__Vcoverage[5165]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q)))) {
        ++(vlSelf->__Vcoverage[5166]);
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
    if (((IData)(vlSelfRef.uart_tb__DOT__reg_req_valid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 162, vlSelfRef.uart_tb__DOT__reg_req_valid, vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_valid);
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_valid 
            = vlSelfRef.uart_tb__DOT__reg_req_valid;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__reg_req_write) 
         ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 164, vlSelfRef.uart_tb__DOT__reg_req_write, vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_write);
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_write 
            = vlSelfRef.uart_tb__DOT__reg_req_write;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__reg_req_addr) 
                ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_addr)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 166, vlSelfRef.uart_tb__DOT__reg_req_addr, vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_addr);
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_addr 
            = vlSelfRef.uart_tb__DOT__reg_req_addr;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__reg_req_wdata 
                ^ vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_wdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 176, vlSelfRef.uart_tb__DOT__reg_req_wdata, vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_wdata);
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_wdata 
            = vlSelfRef.uart_tb__DOT__reg_req_wdata;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__reg_req_wstrb) 
                ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_wstrb)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 240, vlSelfRef.uart_tb__DOT__reg_req_wstrb, vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_wstrb);
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_wstrb 
            = vlSelfRef.uart_tb__DOT__reg_req_wstrb;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__err_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1568, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__err_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__err_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1876, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1925, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1974, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2023, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2072, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2121, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2170, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2215, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2228, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2351, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2580, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2629, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2812, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3087, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_val_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_val_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3548, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_val_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_val_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_val_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_val_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_prev_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth_prev_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 3618, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_prev_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth_prev_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth_prev_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_prev_q;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_d 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_timeout_count_d))) {
        VL_COV_TOGGLE_CHG_ST_I(24, vlSelf->__Vcoverage + 3628, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_timeout_count_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_timeout_count_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_d;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_q 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_timeout_count_q))) {
        VL_COV_TOGGLE_CHG_ST_I(24, vlSelf->__Vcoverage + 3676, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_timeout_count_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_timeout_count_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_q;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_val 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rxto_val))) {
        VL_COV_TOGGLE_CHG_ST_I(24, vlSelf->__Vcoverage + 3724, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_val, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rxto_val);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rxto_val 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_val;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_changed) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth_changed))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3772, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_changed, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth_changed);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth_changed 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_changed;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rxto_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3774, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rxto_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rxto_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_en;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3814, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__break_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__break_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3846, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__break_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__break_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__break_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__break_err;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_cnt_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 3848, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_cnt_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_cnt_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_d;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 3858, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3868, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__allzero_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_err;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__not_allzero_char) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__not_allzero_char))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3870, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__not_allzero_char, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__not_allzero_char);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__not_allzero_char 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__not_allzero_char;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_watermark) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_watermark))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3872, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_watermark, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_watermark);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_watermark 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_watermark;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_empty) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_empty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3874, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_empty, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_empty);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_empty 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_empty;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_watermark) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_watermark))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3876, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_watermark, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_watermark);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_watermark 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_watermark;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_done) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_done))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3878, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_done, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_done);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_tx_done 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_done;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_overflow) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_overflow))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3880, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_overflow, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_overflow);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_overflow 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_overflow;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_break_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_break_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3884, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_break_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_break_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_break_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_break_err;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_timeout) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_timeout))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3886, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_timeout, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_timeout);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_timeout 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_timeout;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3890, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle_q;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__nco_sum_q))) {
        VL_COV_TOGGLE_CHG_ST_I(17, vlSelf->__Vcoverage + 3935, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__nco_sum_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__nco_sum_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q1))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3992, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q1);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q1 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q2))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3994, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q2);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q2 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4049, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4062, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4075, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4086, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4097, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifounder_rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4184, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifounder_rst);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifounder_rst 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 4545, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 4565, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifounder_rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4699, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifounder_rst);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifounder_rst 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4926, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4942, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5036, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(11, vlSelf->__Vcoverage + 5038, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5082, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5098, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5116, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5120, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__baud_div_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5201, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__baud_div_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__baud_div_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5209, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5211, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(11, vlSelf->__Vcoverage + 5227, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5271, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__d_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__d_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5313, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__d_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__d_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__d_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__d_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5323, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5334, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__d_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__d_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5347, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__d_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__d_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__d_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__d_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5357, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5368, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o;
    if ((0U != (0x000000ffU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage) 
                               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4725, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0xffffffffffffff00ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | (IData)((IData)((0x000000ffU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage)))));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                        >> 8U)) ^ (IData)(
                                                          (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                           >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4741, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4757, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4773, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4789, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4805, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4821, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4837, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4210, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U]);
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4226, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4242, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4258, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4274, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U]);
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4290, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4306, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4322, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4338, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U]);
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4354, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4370, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4386, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4402, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U]);
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4418, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4434, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4450, 
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
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__clk_i = vlSelfRef.uart_tb__DOT__clk_i;
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
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o;
    vlSelfRef.uart_tb__DOT__reg_req_i = (((QData)((IData)(
                                                          (((IData)(vlSelfRef.uart_tb__DOT__reg_req_valid) 
                                                            << 6U) 
                                                           | (((IData)(vlSelfRef.uart_tb__DOT__reg_req_write) 
                                                               << 5U) 
                                                              | (IData)(vlSelfRef.uart_tb__DOT__reg_req_addr))))) 
                                          << 0x00000024U) 
                                         | (((QData)((IData)(vlSelfRef.uart_tb__DOT__reg_req_wdata)) 
                                             << 4U) 
                                            | (QData)((IData)(vlSelfRef.uart_tb__DOT__reg_req_wstrb))));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__timing_rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3892, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__timing_rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__timing_rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1900, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1949, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1998, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2047, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2096, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2145, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2194, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2604, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2653, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2906, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3261, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5008, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__intq))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4040, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__intq);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__intq 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__intq))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5315, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__intq);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__intq 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__intq))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5349, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__intq);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__intq 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2584, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2633, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2844, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__err_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2313, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__err_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__err_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3894, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5311, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 326, vlSelfRef.uart_tb__DOT__u_uart__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3896, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_rst_ni);
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 328, vlSelfRef.uart_tb__DOT__u_uart__DOT__rx_i, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__rx_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__rx_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__rx_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__rx_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tick_baud_x16))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3596, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tick_baud_x16);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tick_baud_x16 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5010, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__frame_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5030, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__frame_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__frame_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5199, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5345, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1880, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1929, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1978, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2027, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2076, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2125, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2174, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3151, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__q_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4036, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__q_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__q_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 324, vlSelfRef.uart_tb__DOT__u_uart__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__clk_i);
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
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5028, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle;
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)))) {
        ++(vlSelf->__Vcoverage[4599]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) {
        ++(vlSelf->__Vcoverage[4600]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4585, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (0x00000010U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                          << 4U));
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)))) {
        ++(vlSelf->__Vcoverage[4601]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb) {
        ++(vlSelf->__Vcoverage[4602]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4587, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (0x00000010U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                          << 4U));
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)))) {
        ++(vlSelf->__Vcoverage[4972]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) {
        ++(vlSelf->__Vcoverage[4973]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4958, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (8U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                 << 3U));
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)))) {
        ++(vlSelf->__Vcoverage[4974]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb) {
        ++(vlSelf->__Vcoverage[4975]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4960, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (8U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                 << 3U));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4515, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4902, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4908, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4916, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4523, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4533, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4531, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o) {
        ++(vlSelf->__Vcoverage[4605]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_1 = 0x10U;
    } else {
        ++(vlSelf->__Vcoverage[4608]);
        if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) 
             == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb))) {
            ++(vlSelf->__Vcoverage[4606]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_0 
                = (0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o) 
                                  - (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)));
        } else {
            ++(vlSelf->__Vcoverage[4607]);
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
        ++(vlSelf->__Vcoverage[4603]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o)))) {
        ++(vlSelf->__Vcoverage[4604]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4914, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o) {
        ++(vlSelf->__Vcoverage[4978]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_1 = 8U;
    } else {
        ++(vlSelf->__Vcoverage[4981]);
        if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) 
             == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb))) {
            ++(vlSelf->__Vcoverage[4979]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_0 
                = (0x0000000fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o) 
                                  - (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)));
        } else {
            ++(vlSelf->__Vcoverage[4980]);
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
        ++(vlSelf->__Vcoverage[4976]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o)))) {
        ++(vlSelf->__Vcoverage[4977]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1782, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_qe);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_qe 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1786, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_qe);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_qe 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe;
    }
    if ((IData)(((vlSelfRef.uart_tb__DOT__reg_req_i 
                  ^ vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i) 
                 >> 0x0000002aU))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 8, (IData)(
                                                                   (vlSelfRef.uart_tb__DOT__reg_req_i 
                                                                    >> 0x0000002aU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x0000002aU)));
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i 
            = ((0x000003ffffffffffULL & vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__reg_req_i 
                                                 >> 0x0000002aU))))) 
                  << 0x0000002aU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__reg_req_i 
                        >> 0x00000029U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i 
                                                    >> 0x00000029U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 10, (IData)(
                                                                    (vlSelfRef.uart_tb__DOT__reg_req_i 
                                                                     >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x00000029U)));
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i 
            = ((0x000005ffffffffffULL & vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__reg_req_i 
                                                 >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((0U != (0x0000001fU & ((IData)((vlSelfRef.uart_tb__DOT__reg_req_i 
                                        >> 0x00000024U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i 
                                          >> 0x00000024U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 12, (IData)(
                                                                    (vlSelfRef.uart_tb__DOT__reg_req_i 
                                                                     >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x00000024U)));
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i 
            = ((0x0000060fffffffffULL & vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((0x0000001fU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__reg_req_i 
                                                          >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((0U != ((IData)((vlSelfRef.uart_tb__DOT__reg_req_i 
                         >> 4U)) ^ (IData)((vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i 
                                            >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 22, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__reg_req_i 
                                                                      >> 4U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i 
                                                                                >> 4U)));
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i 
            = ((0x000007f00000000fULL & vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((IData)((vlSelfRef.uart_tb__DOT__reg_req_i 
                                           >> 4U)))) 
                  << 4U));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.uart_tb__DOT__reg_req_i) 
                               ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 86, (IData)(vlSelfRef.uart_tb__DOT__reg_req_i), (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i));
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i 
            = ((0x000007fffffffff0ULL & vlSelfRef.uart_tb__DOT____Vtogcov__reg_req_i) 
               | (IData)((IData)((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__reg_req_i)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
        = vlSelfRef.uart_tb__DOT__reg_req_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1913, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1962, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2011, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2060, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2109, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2158, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2207, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2617, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2666, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2947, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3334, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_tick_baud))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3598, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_tick_baud);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_tick_baud 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4047, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__d_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__d_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5321, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5355, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err) {
        ++(vlSelf->__Vcoverage[1579]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q) {
        ++(vlSelf->__Vcoverage[1581]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err))))) {
        ++(vlSelf->__Vcoverage[1582]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1554, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q) 
           | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5169, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4627, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__core_rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 662, vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__core_rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__core_rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5309, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5343, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5000, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4106, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4032, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3544, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_x16))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5173, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_x16);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_x16 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_x16))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5002, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_x16);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_x16 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3832, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_valid);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_valid 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_frame_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3882, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_frame_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_frame_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3812, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 660, vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1624, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1620, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1616, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1612, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1608, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1604, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1600, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 1628, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1) 
         & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))) {
        ++(vlSelf->__Vcoverage[4005]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync) 
         & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))) {
        ++(vlSelf->__Vcoverage[4006]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync) 
         & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1))) {
        ++(vlSelf->__Vcoverage[4007]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
        ++(vlSelf->__Vcoverage[4008]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
        ++(vlSelf->__Vcoverage[4009]);
    }
    if ((1U & (((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1)) 
                & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync))) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
        ++(vlSelf->__Vcoverage[4010]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync))))) {
        ++(vlSelf->__Vcoverage[4011]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
        ++(vlSelf->__Vcoverage[4012]);
    }
    if ((1U & (((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync)) 
                & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1))))) {
        ++(vlSelf->__Vcoverage[4013]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
        ++(vlSelf->__Vcoverage[4014]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1))))) {
        ++(vlSelf->__Vcoverage[4015]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3842, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync);
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5307, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__clk_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5341, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__clk_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3366, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__clk_i);
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 664, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__clk_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_uart_idle))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3840, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_uart_idle);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_uart_idle 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 4555, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 4575, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4934, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4950, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4162, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4681, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4687, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata 
        = (0x000000ffU & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                  >> ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                                      << 3U))));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_empty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4697, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_empty);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_empty 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4170, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr);
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4182, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_empty);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_empty 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 4535, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o;
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst))))) {
        ++(vlSelf->__Vcoverage[4196]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
        ++(vlSelf->__Vcoverage[4197]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o) {
        ++(vlSelf->__Vcoverage[4198]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__full_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4150, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__full_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__full_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o 
        = (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o) 
                    | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4918, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o;
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst))))) {
        ++(vlSelf->__Vcoverage[4711]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
        ++(vlSelf->__Vcoverage[4712]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o) {
        ++(vlSelf->__Vcoverage[4713]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__full_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4671, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__full_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__full_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o 
        = (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o) 
                    | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    if ((IData)(((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
                  ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i) 
                 >> 0x0000002aU))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 332, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
                                                                      >> 0x0000002aU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x0000002aU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i 
            = ((0x000003ffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
                                                 >> 0x0000002aU))))) 
                  << 0x0000002aU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
                        >> 0x00000029U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i 
                                                    >> 0x00000029U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 334, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
                                                                      >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x00000029U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i 
            = ((0x000005ffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
                                                 >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((0U != (0x0000001fU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
                                        >> 0x00000024U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i 
                                          >> 0x00000024U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 336, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
                                                                      >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x00000024U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i 
            = ((0x0000060fffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((0x0000001fU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
                                                          >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((0U != ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
                         >> 4U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i 
                                            >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 346, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
                                                                       >> 4U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i 
                                                                                >> 4U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i 
            = ((0x000007f00000000fULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
                                           >> 4U)))) 
                  << 4U));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i) 
                               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 410, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i 
            = ((0x000007fffffffff0ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_req_i) 
               | (IData)((IData)((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1330, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4894, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3368, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rst_ni);
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5319, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5332, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5353, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5366, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4507, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4045, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4058, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4034, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__d_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__d_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 666, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_maj))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3998, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_maj);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_maj 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5317, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5330, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5351, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5364, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4069, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4082, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4093, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4998, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5167, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4104, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4625, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4030, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__clk_i;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__clk_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 998, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__clk_i);
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4853, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata;
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst))))) {
        ++(vlSelf->__Vcoverage[4714]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
        ++(vlSelf->__Vcoverage[4715]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty) {
        ++(vlSelf->__Vcoverage[4716]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifoempty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4709, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifoempty);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifoempty 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o 
        = (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) 
                    | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty))));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4466, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata;
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst))))) {
        ++(vlSelf->__Vcoverage[4199]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
        ++(vlSelf->__Vcoverage[4200]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty) {
        ++(vlSelf->__Vcoverage[4201]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifoempty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4194, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifoempty);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifoempty 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o 
        = (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) 
                    | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty))));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__depth_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 4152, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__depth_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__depth_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wready_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4112, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wready_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wready_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__depth_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4673, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__depth_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__depth_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wready_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4633, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wready_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wready_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o;
    if ((IData)(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
                  ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i) 
                 >> 0x0000002aU))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 668, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
                                                                      >> 0x0000002aU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x0000002aU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i 
            = ((0x000003ffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
                                                 >> 0x0000002aU))))) 
                  << 0x0000002aU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
                        >> 0x00000029U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i 
                                                    >> 0x00000029U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 670, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
                                                                      >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x00000029U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i 
            = ((0x000005ffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
                                                 >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((0U != (0x0000001fU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
                                        >> 0x00000024U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i 
                                          >> 0x00000024U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 672, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
                                                                      >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x00000024U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i 
            = ((0x0000060fffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((0x0000001fU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
                                                          >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((0U != ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
                         >> 4U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i 
                                            >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 682, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
                                                                       >> 4U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i 
                                                                                >> 4U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i 
            = ((0x000007f00000000fULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
                                           >> 4U)))) 
                  << 4U));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i) 
                               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 746, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i 
            = ((0x000007fffffffff0ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_req_i) 
               | (IData)((IData)((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4071, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4084, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4095, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__d_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4038, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__d_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__d_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__d_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1000, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni);
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4505, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4892, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4043, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4056, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1864, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1915, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1964, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2013, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2062, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2111, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2160, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2209, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2222, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2570, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2619, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2788, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3015, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__clk_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2295, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifordata_int)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4872, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifordata_int);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifordata_int 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty) {
        ++(vlSelf->__Vcoverage[4890]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____VlemCond_0 = 0U;
    } else {
        ++(vlSelf->__Vcoverage[4891]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty) {
        ++(vlSelf->__Vcoverage[4888]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty)))) {
        ++(vlSelf->__Vcoverage[4889]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rvalid_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4651, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rvalid_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rvalid_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifordata_int)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4485, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifordata_int);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifordata_int 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty) {
        ++(vlSelf->__Vcoverage[4503]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____VlemCond_0 = 0U;
    } else {
        ++(vlSelf->__Vcoverage[4504]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty) {
        ++(vlSelf->__Vcoverage[4501]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty)))) {
        ++(vlSelf->__Vcoverage[4502]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rvalid_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4130, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rvalid_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rvalid_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 3608, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready)))) {
        ++(vlSelf->__Vcoverage[3931]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready) {
        ++(vlSelf->__Vcoverage[3932]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3838, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wready);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wready 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_depth)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3600, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_depth);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_depth 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready)))) {
        ++(vlSelf->__Vcoverage[3933]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready) {
        ++(vlSelf->__Vcoverage[3934]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3808, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wready);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wready 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready;
    }
    if ((IData)((0x0000060000000000ULL == (0x0000060000000000ULL 
                                           & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i)))) {
        ++(vlSelf->__Vcoverage[1583]);
    }
    if ((1U & (~ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                          >> 0x00000029U))))) {
        ++(vlSelf->__Vcoverage[1585]);
    }
    if ((1U & (~ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                          >> 0x0000002aU))))) {
        ++(vlSelf->__Vcoverage[1586]);
    }
    if ((IData)((0x0000040000000000ULL == (0x0000060000000000ULL 
                                           & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i)))) {
        ++(vlSelf->__Vcoverage[1587]);
    }
    if ((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                       >> 0x00000029U)))) {
        ++(vlSelf->__Vcoverage[1589]);
    }
    if ((1U & (~ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                          >> 0x0000002aU))))) {
        ++(vlSelf->__Vcoverage[1590]);
    }
    if ((IData)(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                  ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
                 >> 0x0000002aU))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1002, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                                       >> 0x0000002aU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x0000002aU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
            = ((0x000003ffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                 >> 0x0000002aU))))) 
                  << 0x0000002aU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                        >> 0x00000029U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                                    >> 0x00000029U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1004, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                                       >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x00000029U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
            = ((0x000005ffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                 >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((0U != (0x0000001fU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                        >> 0x00000024U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                          >> 0x00000024U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 1006, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x00000024U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
            = ((0x0000060fffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((0x0000001fU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                          >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((0U != ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                         >> 4U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                            >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1016, (IData)(
                                                                       (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                                        >> 4U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                                                                >> 4U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
            = ((0x000007f00000000fULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                           >> 4U)))) 
                  << 4U));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i) 
                               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1080, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
            = ((0x000007fffffffff0ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
               | (IData)((IData)((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata 
        = (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                   >> 4U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be 
        = (0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re 
        = (IData)((0x0000040000000000ULL == (0x0000060000000000ULL 
                                             & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we 
        = (3U == (3U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                >> 0x00000029U))));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_addr 
        = (0x0000001fU & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                  >> 0x00000024U)));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__d_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4060, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__d_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__d_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__d_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1866, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1917, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1966, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2015, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2064, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2113, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2162, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2211, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2224, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2572, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2621, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2790, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3017, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2297, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__clk_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2327, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__clk_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__clk_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rdata_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4655, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rdata_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rdata_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o;
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)))) {
        ++(vlSelf->__Vcoverage[3929]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid) {
        ++(vlSelf->__Vcoverage[3930]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rvalid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3806, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rvalid);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rvalid 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rdata_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4134, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rdata_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rdata_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o;
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid)))) {
        ++(vlSelf->__Vcoverage[3924]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid) {
        ++(vlSelf->__Vcoverage[3925]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_rvalid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3836, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_rvalid);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_rvalid 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_wdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1346, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_wdata);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_wdata 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_wdata 
        = (1U & VL_REDXOR_32(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_wd 
        = (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata);
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_wd 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata 
                 >> 1U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_wd 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata 
                 >> 2U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_wd 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata 
                 >> 4U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_wd 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata 
                 >> 5U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_wd 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata 
                 >> 6U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_wd 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata 
                 >> 7U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_wd 
        = (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata 
           >> 0x00000010U);
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_wd 
        = (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata);
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_rxrst_wd 
        = (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata);
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_txrst_wd 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata 
                 >> 1U));
    if ((IData)((7U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[1848]);
    }
    if ((IData)((0x0bU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[1849]);
    }
    if ((IData)((0x0dU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[1850]);
    }
    if ((IData)((1U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[1851]);
    }
    if ((IData)((0x0eU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[1852]);
    }
    if ((IData)((2U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[1853]);
    }
    if ((IData)((4U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[1854]);
    }
    if ((IData)((8U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[1855]);
    }
    if ((IData)((0x0fU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[1856]);
    }
    if ((IData)((3U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[1857]);
    }
    if ((IData)((5U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[1858]);
    }
    if ((IData)((9U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[1859]);
    }
    if ((IData)((6U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[1860]);
    }
    if ((IData)((0x0aU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[1861]);
    }
    if ((IData)((0x0cU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[1862]);
    }
    if ((IData)((0U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[1863]);
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_be)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1410, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_be);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_be 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_be 
        = (1U & VL_REDXOR_4(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1334, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_re);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_re 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1332, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_addr) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_addr)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 1336, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_addr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_addr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_addr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_addr;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit 
        = ((0x38U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit)) 
           | (((8U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_addr)) 
               << 2U) | (((4U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_addr)) 
                          << 1U) | (0U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_addr)))));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit 
        = ((7U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit)) 
           | (((0x14U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_addr)) 
               << 5U) | (((0x10U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_addr)) 
                          << 4U) | ((0x0cU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_addr)) 
                                    << 3U))));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2329, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3788, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rdata)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3580, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rdata);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rdata 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_wdata) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__unused_wdata))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1844, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_wdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__unused_wdata);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__unused_wdata 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_wdata;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1602, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1606, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1610, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1614, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1618, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1622, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1626, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_wd;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_wd) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 1660, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_wd;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_wd) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1726, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_rxrst_wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_rxrst_wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1744, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_rxrst_wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_rxrst_wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_rxrst_wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_rxrst_wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_rxrst_wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_txrst_wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_txrst_wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1746, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_txrst_wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_txrst_wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_txrst_wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_txrst_wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_txrst_wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_be) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__unused_be))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1846, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_be, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__unused_be);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__unused_be 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_be;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__addr_hit)))) {
        VL_COV_TOGGLE_CHG_ST_I(6, vlSelf->__Vcoverage + 1792, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__addr_hit);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__addr_hit 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wr_err 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we) 
           & (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
               & (0U != (0x0000000fU & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be))))) 
              | ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
                   >> 1U) & (0U != (1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be))))) 
                 | (((0U != (1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) 
                     & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
                        >> 2U)) | (((0U != (1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) 
                                    & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
                                       >> 3U)) | ((
                                                   ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
                                                    >> 5U) 
                                                   & (0U 
                                                      != 
                                                      (7U 
                                                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be))))) 
                                                  | ((0U 
                                                      != 
                                                      (1U 
                                                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be)))) 
                                                     & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
                                                        >> 4U))))))));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re) 
         | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we))) {
        ++(vlSelf->__Vcoverage[1808]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____VlemCond_0 
            = (1U & (~ (0U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))));
    } else {
        ++(vlSelf->__Vcoverage[1809]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addrmiss 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we) {
        ++(vlSelf->__Vcoverage[1805]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re) {
        ++(vlSelf->__Vcoverage[1806]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we))))) {
        ++(vlSelf->__Vcoverage[1807]);
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5181, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2166, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2117, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2068, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2019, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1970, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1921, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1870, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wd) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3021, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wd) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2794, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2625, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2576, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wd;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wd;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wr_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wr_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1486, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wr_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wr_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wr_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wr_err;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wr_err) {
        ++(vlSelf->__Vcoverage[1594]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addrmiss) {
        ++(vlSelf->__Vcoverage[1595]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addrmiss)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wr_err))))) {
        ++(vlSelf->__Vcoverage[1596]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addrmiss) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__addrmiss))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1484, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addrmiss, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__addrmiss);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__addrmiss 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addrmiss;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i 
        = ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addrmiss)) 
           & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addrmiss) 
           | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wr_err));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2192, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wd;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2143, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wd;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2094, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wd;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2045, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wd;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1996, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wd;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1947, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wd;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1898, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wd) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3229, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wd) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2890, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wd;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2651, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wd;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__wd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2602, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wd;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__en_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2311, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__en_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__en_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i;
    if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
          & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we)) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[1811]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[1812]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[1813]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit)))) {
        ++(vlSelf->__Vcoverage[1814]);
    }
    if (((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
           >> 1U) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re)) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[1815]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[1816]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re)))) {
        ++(vlSelf->__Vcoverage[1817]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[1818]);
    }
    if (((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
           >> 2U) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re)) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[1819]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[1820]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re)))) {
        ++(vlSelf->__Vcoverage[1821]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
                  >> 2U)))) {
        ++(vlSelf->__Vcoverage[1822]);
    }
    if (((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
           >> 3U) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we)) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[1823]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[1824]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[1825]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
                  >> 3U)))) {
        ++(vlSelf->__Vcoverage[1826]);
    }
    if (((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
           >> 4U) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we)) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[1827]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[1828]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[1829]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
                  >> 4U)))) {
        ++(vlSelf->__Vcoverage[1830]);
    }
    if (((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
           >> 5U) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re)) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[1831]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[1832]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re)))) {
        ++(vlSelf->__Vcoverage[1833]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
                  >> 5U)))) {
        ++(vlSelf->__Vcoverage[1834]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1482, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_error);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_error 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error;
    }
    __VdfgRegularize_h6e95ff9d_0_3 = ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error)) 
                                      & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we));
    __VdfgRegularize_h6e95ff9d_0_2 = ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error)) 
                                      & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__en_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2349, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__en_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__en_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_we 
        = (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
            >> 3U) & (IData)(__VdfgRegularize_h6e95ff9d_0_3));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_we 
        = (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
            >> 4U) & (IData)(__VdfgRegularize_h6e95ff9d_0_3));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
           & (IData)(__VdfgRegularize_h6e95ff9d_0_3));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_re 
        = (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
            >> 5U) & (IData)(__VdfgRegularize_h6e95ff9d_0_2));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_re 
        = (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
            >> 2U) & (IData)(__VdfgRegularize_h6e95ff9d_0_2));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_re 
        = (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit) 
            >> 1U) & (IData)(__VdfgRegularize_h6e95ff9d_0_2));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1724, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_we;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_we;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1742, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_we;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_we;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_we;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1598, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_check 
        = ((0x20U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_check)) 
           | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_we) 
               << 4U) | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_we) 
                          << 3U) | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we))));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_check 
        = (0x1fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_check));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_re) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1748, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_re, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_re);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_re 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_re;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__re 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_re;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__re 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_re;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_re) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rdata_re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1706, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_re, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rdata_re);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rdata_re 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_re;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__re 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_re;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_re) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1692, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_re, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_re);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_re 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_re;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__re 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_re;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__re 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_re;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__re 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_re;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__re 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_re;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__re 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_re;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__re 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_re;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2792, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__we;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__we;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2574, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__we;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__we;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2623, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__we;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__we;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1868, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__we;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__we;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1919, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__we;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__we;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1968, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__we;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__we;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2017, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__we;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__we;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2066, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__we;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__we;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2115, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__we;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__we;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2164, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__we;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__we;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3019, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__we;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__we;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_check) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_check)))) {
        VL_COV_TOGGLE_CHG_ST_I(6, vlSelf->__Vcoverage + 1556, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_check, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_check);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_check 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_check;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_check;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__re) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2668, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__re, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__re);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__re 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__re;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qre 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__re;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__re) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2736, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__re, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__re);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__re 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__re;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qre 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__re;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__re) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2963, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__re, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__re);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__re 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__re;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qre 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__re;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__re) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2235, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__re, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__re);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__re 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__re;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qre 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__re;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__re) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2245, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__re, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__re);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__re 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__re;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qre 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__re;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__re) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2255, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__re, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__re);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__re 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__re;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qre 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__re;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__re) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2265, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__re, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__re);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__re 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__re;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qre 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__re;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__re) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2275, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__re, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__re);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__re 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__re;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qre 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__re;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__re) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2285, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__re, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__re);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__re 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__re;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qre 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__re;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2941]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2942]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2888, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2945]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[2946]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2943]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2944]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2611]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2612]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2600, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2615]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[2616]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2613]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2614]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2660]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2661]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2649, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2664]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[2665]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2662]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2663]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[1907]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[1908]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1896, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[1911]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[1912]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[1909]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[1910]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[1956]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[1957]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1945, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[1960]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[1961]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[1958]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[1959]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2005]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2006]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1994, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2009]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[2010]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2007]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2008]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2054]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2055]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2043, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2058]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[2059]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2056]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2057]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2103]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2104]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2092, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2107]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[2108]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2105]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2106]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2152]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2153]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2141, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2156]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[2157]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2154]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2155]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2201]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2202]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2190, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2205]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[2206]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2203]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2204]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3328]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3329]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3227, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3332]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[3333]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3330]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3331]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__we;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(6, vlSelf->__Vcoverage + 2299, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qre) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__qre))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2702, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qre, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__qre);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__qre 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qre;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qre) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__qre))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2754, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qre, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__qre);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__qre 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qre;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qre) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__qre))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2981, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qre, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__qre);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__qre 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qre;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qre) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__qre))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2239, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qre, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__qre);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__qre 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qre;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qre) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__qre))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2249, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qre, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__qre);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__qre 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qre;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qre) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__qre))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2259, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qre, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__qre);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__qre 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qre;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qre) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__qre))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2269, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qre, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__qre);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__qre 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qre;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qre) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__qre))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2279, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qre, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__qre);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__qre 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qre;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qre) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__qre))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2289, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qre, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__qre);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__qre 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qre;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
        = (((QData)((IData)((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q) 
                              << 9U) | ((((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q) 
                                            << 4U) 
                                           | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q) 
                                               << 3U) 
                                              | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q) 
                                                 << 2U))) 
                                          | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q) 
                                              << 1U) 
                                             | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q))) 
                                         << 4U) | (
                                                   ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q) 
                                                    << 3U) 
                                                   | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q) 
                                                       << 2U) 
                                                      | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qre))))))) 
            << 0x00000020U) | (QData)((IData)(((((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qre) 
                                                   << 8U) 
                                                  | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qre) 
                                                     << 6U)) 
                                                 | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qre) 
                                                     << 4U) 
                                                    | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qre) 
                                                        << 2U) 
                                                       | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qre)))) 
                                                << 0x00000016U) 
                                               | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qre) 
                                                   << 0x0000000dU) 
                                                  | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q) 
                                                      << 5U) 
                                                     | ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe) 
                                                          << 4U) 
                                                         | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q) 
                                                             << 3U) 
                                                            | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe) 
                                                               << 2U))) 
                                                        | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q) 
                                                            << 1U) 
                                                           | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe)))))))));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2924, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2922, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_en;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2608, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2606, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_en;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2657, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2655, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_en;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1904, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1902, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_en;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1953, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1951, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_en;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2002, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2000, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_en;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2051, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2049, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_en;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2100, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2098, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_en;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2149, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2147, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_en;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2198, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2196, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3295, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3293, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__in_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(6, vlSelf->__Vcoverage + 2534, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__in_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__in_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv 
        = (0x0000003fU & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i)));
    if ((0U != (0x0000ffffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                        >> 0x00000029U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                          >> 0x00000029U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 1156, (IData)(
                                                                       (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                        >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000029U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x000001ffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x0000ffffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                          >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000028U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000028U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1188, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000028U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffeffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000027U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000027U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1190, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000027U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000027U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffff7fffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000027U))))) 
                  << 0x00000027U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000026U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000026U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1192, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000026U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000026U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffbfffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000026U))))) 
                  << 0x00000026U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000025U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000025U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1194, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000025U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000025U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffdfffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000025U))))) 
                  << 0x00000025U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000024U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000024U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1196, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000024U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffefffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000023U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000023U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1198, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000023U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000023U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffff7ffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000023U))))) 
                  << 0x00000023U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000022U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000022U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1200, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000022U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000022U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffbffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000022U))))) 
                  << 0x00000022U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000021U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000021U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1202, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000021U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000021U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffdffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000021U))))) 
                  << 0x00000021U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000020U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000020U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1204, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000020U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000020U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffeffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000020U))))) 
                  << 0x00000020U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x0000001fU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001fU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1206, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x0000001fU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001fU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffff7fffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x0000001fU))))) 
                  << 0x0000001fU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x0000001eU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001eU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1208, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x0000001eU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffbfffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x0000001eU))))) 
                  << 0x0000001eU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x0000001dU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001dU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1210, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x0000001dU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001dU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffdfffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x0000001dU))))) 
                  << 0x0000001dU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x0000001cU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1212, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x0000001cU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001cU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffefffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x0000001cU))))) 
                  << 0x0000001cU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x0000001bU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001bU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1214, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x0000001bU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001bU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffff7ffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x0000001bU))))) 
                  << 0x0000001bU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x0000001aU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001aU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1216, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x0000001aU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001aU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffbffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x0000001aU))))) 
                  << 0x0000001aU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000019U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000019U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1218, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000019U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000019U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffdffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000019U))))) 
                  << 0x00000019U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000018U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000018U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1220, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000018U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffeffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000018U))))) 
                  << 0x00000018U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000017U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000017U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1222, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000017U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000017U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffff7fffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000017U))))) 
                  << 0x00000017U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000016U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000016U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1224, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000016U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000016U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffbfffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000016U))))) 
                  << 0x00000016U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                        >> 0x0000000eU)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                          >> 0x0000000eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1226, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x0000000eU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000000eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffc03fffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                          >> 0x0000000eU))))) 
                  << 0x0000000eU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x0000000dU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000000dU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1242, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x0000000dU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000000dU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffdfffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x0000000dU))))) 
                  << 0x0000000dU));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                        >> 5U)) ^ (IData)(
                                                          (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                           >> 5U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1244, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 5U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 5U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffe01fULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                          >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 4U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                           >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1260, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 4U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 4U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffffefULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 3U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                           >> 3U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1262, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 3U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 3U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffff7ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                           >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1264, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffbULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1266, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffdULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw) 
               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1268, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_data) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2862, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2860, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[2886]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[2887]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[2884]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[2885]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qe 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2588, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2586, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[2598]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[2599]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[2596]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[2597]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qe 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2637, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2635, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[2647]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[2648]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[2645]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[2646]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qe 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1884, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1882, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qe 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[1894]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[1895]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[1892]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[1893]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1933, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1931, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qe 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[1943]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[1944]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[1941]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[1942]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1982, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1980, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qe 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[1992]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[1993]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[1990]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[1991]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2031, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2029, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qe 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[2041]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[2042]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[2039]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[2040]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2080, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2078, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qe 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[2090]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[2091]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[2088]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[2089]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2129, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2127, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qe 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[2139]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[2140]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[2137]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[2138]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_data) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__wr_data))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2178, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2176, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qe 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[2188]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[2189]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[2186]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[2187]);
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_data) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3185, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__wr_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__wr_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3183, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__wr_en);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__wr_en 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qe 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3225]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[3226]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3223]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[3224]);
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__inv)))) {
        VL_COV_TOGGLE_CHG_ST_I(6, vlSelf->__Vcoverage + 2558, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__inv);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__inv 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o 
        = (0x0000003fU & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv)));
    if ((0U != (0x0000ffffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                        >> 0x00000029U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                          >> 0x00000029U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 822, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000029U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x000001ffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x0000ffffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                          >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000028U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000028U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 854, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000028U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffeffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000027U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000027U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 856, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x00000027U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000027U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffff7fffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000027U))))) 
                  << 0x00000027U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000026U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000026U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 858, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x00000026U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000026U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffbfffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000026U))))) 
                  << 0x00000026U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000025U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000025U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 860, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x00000025U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000025U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffdfffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000025U))))) 
                  << 0x00000025U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000024U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000024U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 862, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000024U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffefffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000023U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000023U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 864, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x00000023U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000023U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffff7ffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000023U))))) 
                  << 0x00000023U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000022U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000022U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 866, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x00000022U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000022U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffbffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000022U))))) 
                  << 0x00000022U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000021U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000021U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 868, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x00000021U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000021U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffdffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000021U))))) 
                  << 0x00000021U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000020U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000020U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 870, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x00000020U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000020U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffeffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000020U))))) 
                  << 0x00000020U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x0000001fU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001fU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 872, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x0000001fU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001fU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffff7fffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x0000001fU))))) 
                  << 0x0000001fU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x0000001eU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001eU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 874, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x0000001eU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffbfffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x0000001eU))))) 
                  << 0x0000001eU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x0000001dU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001dU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 876, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x0000001dU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001dU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffdfffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x0000001dU))))) 
                  << 0x0000001dU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x0000001cU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 878, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x0000001cU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001cU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffefffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x0000001cU))))) 
                  << 0x0000001cU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x0000001bU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001bU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 880, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x0000001bU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001bU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffff7ffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x0000001bU))))) 
                  << 0x0000001bU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x0000001aU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001aU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 882, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x0000001aU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001aU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffbffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x0000001aU))))) 
                  << 0x0000001aU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000019U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000019U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 884, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x00000019U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000019U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffdffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000019U))))) 
                  << 0x00000019U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000018U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000018U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 886, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x00000018U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffeffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000018U))))) 
                  << 0x00000018U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000017U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000017U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 888, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x00000017U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000017U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffff7fffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000017U))))) 
                  << 0x00000017U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000016U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000016U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 890, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x00000016U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000016U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffbfffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000016U))))) 
                  << 0x00000016U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                        >> 0x0000000eU)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                          >> 0x0000000eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 892, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x0000000eU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000000eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffc03fffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                          >> 0x0000000eU))))) 
                  << 0x0000000eU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x0000000dU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000000dU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 908, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 0x0000000dU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000000dU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffdfffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x0000000dU))))) 
                  << 0x0000000dU));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                        >> 5U)) ^ (IData)(
                                                          (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                           >> 5U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 910, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 5U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 5U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffe01fULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                          >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 4U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                           >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 926, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 4U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 4U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffffefULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 3U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                           >> 3U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 928, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 3U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 3U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffff7ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                           >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 930, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffbULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 932, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                      >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffdULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw) 
               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 934, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2828, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qe) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2810, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qe);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qe 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qe;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_flds_we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qe;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2582, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qe) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2578, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qe);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qe 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qe;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2631, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qe) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2627, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qe);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qe 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qe;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_flds_we 
        = (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qe) 
            << 1U) | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qe));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qe) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1874, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qe);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qe 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qe;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1878, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qe) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1923, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qe);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qe 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qe;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1927, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qe) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1972, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qe);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qe 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qe;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1976, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qe) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2021, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qe);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qe 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qe;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2025, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qe) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2070, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qe);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qe 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qe;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2074, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qe) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2119, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qe);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qe 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qe;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2123, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qe) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2168, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qe);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qe 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qe;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2172, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qe) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3085, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qe);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qe 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qe;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3119, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__out_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(6, vlSelf->__Vcoverage + 2546, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__out_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__out_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o;
    if ((0U != (0x0000ffffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                        >> 0x00000029U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                          >> 0x00000029U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 486, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000029U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x000001ffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x0000ffffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                          >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000028U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000028U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 518, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000028U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffeffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000027U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000027U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 520, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x00000027U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000027U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffff7fffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000027U))))) 
                  << 0x00000027U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000026U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000026U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 522, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x00000026U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000026U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffbfffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000026U))))) 
                  << 0x00000026U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000025U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000025U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 524, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x00000025U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000025U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffdfffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000025U))))) 
                  << 0x00000025U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000024U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000024U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 526, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000024U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffefffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000023U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000023U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 528, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x00000023U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000023U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffff7ffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000023U))))) 
                  << 0x00000023U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000022U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000022U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 530, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x00000022U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000022U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffbffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000022U))))) 
                  << 0x00000022U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000021U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000021U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 532, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x00000021U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000021U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffdffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000021U))))) 
                  << 0x00000021U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000020U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000020U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 534, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x00000020U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000020U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffeffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000020U))))) 
                  << 0x00000020U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x0000001fU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001fU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 536, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x0000001fU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001fU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffff7fffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x0000001fU))))) 
                  << 0x0000001fU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x0000001eU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001eU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 538, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x0000001eU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffbfffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x0000001eU))))) 
                  << 0x0000001eU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x0000001dU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001dU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 540, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x0000001dU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001dU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffdfffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x0000001dU))))) 
                  << 0x0000001dU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x0000001cU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 542, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x0000001cU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001cU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffefffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x0000001cU))))) 
                  << 0x0000001cU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x0000001bU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001bU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 544, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x0000001bU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001bU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffff7ffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x0000001bU))))) 
                  << 0x0000001bU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x0000001aU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001aU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 546, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x0000001aU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001aU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffbffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x0000001aU))))) 
                  << 0x0000001aU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000019U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000019U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 548, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x00000019U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000019U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffdffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000019U))))) 
                  << 0x00000019U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000018U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000018U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 550, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x00000018U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffeffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000018U))))) 
                  << 0x00000018U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000017U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000017U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 552, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x00000017U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000017U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffff7fffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000017U))))) 
                  << 0x00000017U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000016U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000016U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 554, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x00000016U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000016U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffbfffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000016U))))) 
                  << 0x00000016U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                        >> 0x0000000eU)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                          >> 0x0000000eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 556, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x0000000eU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000000eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffc03fffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                          >> 0x0000000eU))))) 
                  << 0x0000000eU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x0000000dU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000000dU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 572, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 0x0000000dU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000000dU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffdfffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x0000000dU))))) 
                  << 0x0000000dU));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                        >> 5U)) ^ (IData)(
                                                          (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                           >> 5U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 574, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 5U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 5U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffe01fULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                          >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 4U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                           >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 590, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 4U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 4U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffffefULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 3U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                           >> 3U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 592, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 3U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 3U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffff7ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                           >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 594, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffbULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 596, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                      >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffdULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw) 
               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 598, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_flds_we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_flds_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1784, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_flds_we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_flds_we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_flds_we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_flds_we;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__d_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_flds_we;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_flds_we) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_flds_we)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 1788, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_flds_we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_flds_we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_flds_we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_flds_we;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__d_i 
        = (3U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_flds_we));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_buf)))) {
        VL_COV_TOGGLE_CHG_ST_I(6, vlSelf->__Vcoverage + 2315, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_buf);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_buf 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf;
    if ((IData)((3ULL == (3ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw)))) {
        ++(vlSelf->__Vcoverage[3918]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw)))) {
        ++(vlSelf->__Vcoverage[3919]);
    }
    if ((1U & (~ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                          >> 1U))))) {
        ++(vlSelf->__Vcoverage[3920]);
    }
    if ((IData)((0x000000000000000cULL == (0x000000000000000cULL 
                                           & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw)))) {
        ++(vlSelf->__Vcoverage[3921]);
    }
    if ((1U & (~ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                          >> 2U))))) {
        ++(vlSelf->__Vcoverage[3922]);
    }
    if ((1U & (~ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                          >> 3U))))) {
        ++(vlSelf->__Vcoverage[3923]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata 
        = (0x000000ffU & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                  >> 5U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst 
        = (3U == (3U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst 
        = (3U == (3U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                >> 2U))));
    if ((0U != (0x0000ffffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                        >> 0x00000029U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                          >> 0x00000029U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3370, (IData)(
                                                                       (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                        >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000029U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x000001ffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x0000ffffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                          >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000028U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000028U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3402, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000028U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffeffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000027U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000027U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3404, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000027U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000027U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffff7fffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000027U))))) 
                  << 0x00000027U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000026U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000026U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3406, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000026U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000026U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffbfffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000026U))))) 
                  << 0x00000026U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000025U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000025U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3408, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000025U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000025U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffdfffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000025U))))) 
                  << 0x00000025U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000024U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000024U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3410, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000024U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffefffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000023U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000023U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3412, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000023U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000023U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffff7ffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000023U))))) 
                  << 0x00000023U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000022U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000022U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3414, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000022U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000022U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffbffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000022U))))) 
                  << 0x00000022U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000021U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000021U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3416, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000021U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000021U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffdffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000021U))))) 
                  << 0x00000021U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000020U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000020U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3418, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000020U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000020U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffeffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000020U))))) 
                  << 0x00000020U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x0000001fU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001fU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3420, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x0000001fU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001fU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffff7fffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x0000001fU))))) 
                  << 0x0000001fU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x0000001eU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001eU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3422, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x0000001eU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffbfffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x0000001eU))))) 
                  << 0x0000001eU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x0000001dU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001dU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3424, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x0000001dU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001dU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffdfffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x0000001dU))))) 
                  << 0x0000001dU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x0000001cU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3426, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x0000001cU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001cU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffefffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x0000001cU))))) 
                  << 0x0000001cU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x0000001bU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001bU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3428, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x0000001bU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001bU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffff7ffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x0000001bU))))) 
                  << 0x0000001bU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x0000001aU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001aU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3430, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x0000001aU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001aU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffbffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x0000001aU))))) 
                  << 0x0000001aU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000019U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000019U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3432, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000019U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000019U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffdffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000019U))))) 
                  << 0x00000019U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000018U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000018U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3434, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000018U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffeffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000018U))))) 
                  << 0x00000018U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000017U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000017U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3436, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000017U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000017U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffff7fffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000017U))))) 
                  << 0x00000017U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000016U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000016U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3438, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000016U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000016U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffbfffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000016U))))) 
                  << 0x00000016U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                        >> 0x0000000eU)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                          >> 0x0000000eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3440, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x0000000eU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000000eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffc03fffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                          >> 0x0000000eU))))) 
                  << 0x0000000eU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x0000000dU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000000dU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3456, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x0000000dU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000000dU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffdfffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x0000000dU))))) 
                  << 0x0000000dU));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                        >> 5U)) ^ (IData)(
                                                          (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                           >> 5U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3458, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 5U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 5U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffe01fULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                          >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 4U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                           >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3474, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 4U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 4U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffffefULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 3U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                           >> 3U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3476, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 3U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 3U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffff7ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                           >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3478, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffbULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3480, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffdULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw) 
               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3482, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 0x00000027U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity 
        = (1U & (VL_REDXOR_8(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data) 
                 ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                            >> 0x00000028U))));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 4U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 0x0000000dU)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 0x00000025U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 0x00000028U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 0x00000024U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 0x00000026U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 0x00000027U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 0x00000022U)));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__d_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2226, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__d_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__d_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__d_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__d_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__d_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2213, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__d_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__d_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__d_i;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__oh_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(6, vlSelf->__Vcoverage + 2331, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__oh_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__oh_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree 
        = ((0x007fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)) 
           | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i) 
              << 7U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree 
        = ((0x007fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree)) 
           | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i) 
              << 7U));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wdata)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3900, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wdata);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wdata 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_rxrst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3784, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_rxrst);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_rxrst 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_txrst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3786, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_txrst);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_txrst 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__parity_enable))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5175, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__parity_enable);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__parity_enable 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_parity))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5179, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_parity);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_parity 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wvalid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3916, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wvalid);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wvalid 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_pop))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3898, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_pop);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_pop 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__sys_loopback))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3778, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__sys_loopback);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__sys_loopback 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_odd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5006, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_odd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_odd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rxnf_enable))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3782, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rxnf_enable);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rxnf_enable 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable) {
        ++(vlSelf->__Vcoverage[4018]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_1 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj;
    } else {
        ++(vlSelf->__Vcoverage[4019]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_1 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_1;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable) {
        ++(vlSelf->__Vcoverage[4016]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable)))) {
        ++(vlSelf->__Vcoverage[4017]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__line_loopback))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3780, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__line_loopback);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__line_loopback 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback) {
        ++(vlSelf->__Vcoverage[3984]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i;
    } else {
        ++(vlSelf->__Vcoverage[3985]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_0 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_0;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback) {
        ++(vlSelf->__Vcoverage[3982]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback)))) {
        ++(vlSelf->__Vcoverage[3983]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_enable))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5004, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_enable);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_enable 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) {
        ++(vlSelf->__Vcoverage[5162]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_1 
            = (0x000000ffU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
                              >> 1U));
    } else {
        ++(vlSelf->__Vcoverage[5163]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_1 
            = (0x000000ffU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
                              >> 2U));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_1;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) {
        ++(vlSelf->__Vcoverage[5160]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable)))) {
        ++(vlSelf->__Vcoverage[5161]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) 
           & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q) 
              & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd) 
                 ^ VL_REDXOR_32((0x000001ffU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
                                                >> 1U))))));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_enable))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3776, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_enable);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_enable 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wdata_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4635, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wdata_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wdata_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4108, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4629, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i;
    if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i) 
          & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o)) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst)))) {
        ++(vlSelf->__Vcoverage[4717]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
        ++(vlSelf->__Vcoverage[4718]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o)))) {
        ++(vlSelf->__Vcoverage[4719]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i)))) {
        ++(vlSelf->__Vcoverage[4720]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wvalid_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4631, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wvalid_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wvalid_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o)));
    if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o) 
          & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i)) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)))) {
        ++(vlSelf->__Vcoverage[4206]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
        ++(vlSelf->__Vcoverage[4207]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i)))) {
        ++(vlSelf->__Vcoverage[4208]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o)))) {
        ++(vlSelf->__Vcoverage[4209]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rready_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4132, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rready_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rready_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i)));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_mx))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3996, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_mx);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_mx 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback) {
        ++(vlSelf->__Vcoverage[4022]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_2 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out;
    } else {
        ++(vlSelf->__Vcoverage[4025]);
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback) {
            ++(vlSelf->__Vcoverage[4023]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_2 = 1U;
        } else {
            ++(vlSelf->__Vcoverage[4024]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_2 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx;
        }
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_2;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback) {
        ++(vlSelf->__Vcoverage[4020]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback)))) {
        ++(vlSelf->__Vcoverage[4021]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3546, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5012, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_parity_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5032, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_parity_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_parity_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_enable))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5171, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_enable);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_enable 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable) {
        ++(vlSelf->__Vcoverage[5305]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_1 
            = (0U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q));
    } else {
        ++(vlSelf->__Vcoverage[5306]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_1 = 1U;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_1;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable) {
        ++(vlSelf->__Vcoverage[5303]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable)))) {
        ++(vlSelf->__Vcoverage[5304]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4509, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4896, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4693, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4180, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3844, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tx_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 330, vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tx_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tx_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o;
    }
    vlSelfRef.uart_tb__DOT__tx_o = vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3816, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_data);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_data 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data;
    if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid) 
          & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err))) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err)))) {
        ++(vlSelf->__Vcoverage[4026]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err) {
        ++(vlSelf->__Vcoverage[4027]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err) {
        ++(vlSelf->__Vcoverage[4028]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid)))) {
        ++(vlSelf->__Vcoverage[4029]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_parity_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3888, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_parity_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_parity_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid 
        = ((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err) 
               | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err))) 
           & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__idle))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5197, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__idle);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__idle 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
         & (7U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o)))) {
        ++(vlSelf->__Vcoverage[4966]);
    }
    if ((7U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o))) {
        ++(vlSelf->__Vcoverage[4967]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i)))) {
        ++(vlSelf->__Vcoverage[4968]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4898, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
           & (7U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o)));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
         & (0x0fU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)))) {
        ++(vlSelf->__Vcoverage[4596]);
    }
    if ((0x0fU != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o))) {
        ++(vlSelf->__Vcoverage[4597]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i)))) {
        ++(vlSelf->__Vcoverage[4598]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4513, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
           & (0x0fU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5034, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d 
            = (1U & (((IData)(1U) + (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q)) 
                     >> 4U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d 
            = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q)));
        ++(vlSelf->__Vcoverage[5127]);
    } else {
        ++(vlSelf->__Vcoverage[5128]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx)))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d = 8U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d = 0U;
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) {
            ++(vlSelf->__Vcoverage[5131]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_0 = 0x0bU;
        } else {
            ++(vlSelf->__Vcoverage[5132]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_0 = 0x0aU;
        }
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_0;
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) {
            ++(vlSelf->__Vcoverage[5129]);
        }
        if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable)))) {
            ++(vlSelf->__Vcoverage[5130]);
        }
        ++(vlSelf->__Vcoverage[5143]);
    } else {
        if (((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q)) 
             & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q))) {
            if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q) 
                  == ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable)
                       ? 0x0bU : 0x0aU)) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx))) {
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d = 1U;
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d = 0U;
                ++(vlSelf->__Vcoverage[5133]);
            } else {
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d 
                    = (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx) 
                        << 0x0000000aU) | (0x000003ffU 
                                           & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
                                              >> 1U)));
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d 
                    = (0x0000000fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q) 
                                      - (IData)(1U)));
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d 
                    = (1U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q));
                ++(vlSelf->__Vcoverage[5134]);
            }
            if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q) 
                  == ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable)
                       ? 0x0bU : 0x0aU)) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx))) {
                ++(vlSelf->__Vcoverage[5135]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx)))) {
                ++(vlSelf->__Vcoverage[5136]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q) 
                 != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable)
                      ? 0x0bU : 0x0aU))) {
                ++(vlSelf->__Vcoverage[5137]);
            }
            ++(vlSelf->__Vcoverage[5138]);
        } else {
            ++(vlSelf->__Vcoverage[5139]);
        }
        if (((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q)) 
             & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q))) {
            ++(vlSelf->__Vcoverage[5140]);
        }
        if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q)))) {
            ++(vlSelf->__Vcoverage[5141]);
        }
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q) {
            ++(vlSelf->__Vcoverage[5142]);
        }
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx)))) {
        ++(vlSelf->__Vcoverage[5144]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx) {
        ++(vlSelf->__Vcoverage[5145]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q)))) {
        ++(vlSelf->__Vcoverage[5146]);
    }
    ++(vlSelf->__Vcoverage[5148]);
    ++(vlSelf->__Vcoverage[5150]);
    ++(vlSelf->__Vcoverage[5151]);
    if (((IData)(vlSelfRef.uart_tb__DOT__tx_o) ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__tx_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6, vlSelfRef.uart_tb__DOT__tx_o, vlSelfRef.uart_tb__DOT____Vtogcov__tx_o);
        vlSelfRef.uart_tb__DOT____Vtogcov__tx_o = vlSelfRef.uart_tb__DOT__tx_o;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wdata_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4114, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wdata_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wdata_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wvalid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3834, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wvalid);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wvalid 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)))) {
        ++(vlSelf->__Vcoverage[3926]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid) {
        ++(vlSelf->__Vcoverage[3927]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle)))) {
        ++(vlSelf->__Vcoverage[3928]);
    }
    if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle) 
          & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)) 
         & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable))) {
        ++(vlSelf->__Vcoverage[3978]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable)))) {
        ++(vlSelf->__Vcoverage[3979]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)))) {
        ++(vlSelf->__Vcoverage[3980]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle)))) {
        ++(vlSelf->__Vcoverage[3981]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3810, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle) 
           & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable) 
              & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
        = (((((4U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid)) 
                     << 2U)) | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle) 
                                 << 1U) | ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)) 
                                           & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle)))) 
             << 0x0000001bU) | (((0x00000400U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)) 
                                                 << 0x0000000aU)) 
                                 | ((0x00000200U & 
                                     ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready)) 
                                      << 9U)) | ((0x00000100U 
                                                  & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready)) 
                                                     << 8U)) 
                                                 | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata)))) 
                                << 0x00000010U)) | 
           (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth) 
             << 8U) | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth)));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4962, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4591, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5114, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(11, vlSelf->__Vcoverage + 5060, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5090, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5106, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5118, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d;
    }
    if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i) 
          & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o)) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)))) {
        ++(vlSelf->__Vcoverage[4202]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
        ++(vlSelf->__Vcoverage[4203]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o)))) {
        ++(vlSelf->__Vcoverage[4204]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i)))) {
        ++(vlSelf->__Vcoverage[4205]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wvalid_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4110, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wvalid_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wvalid_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o)));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3804, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rready);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rready 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready;
    if ((0x20000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3484, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x0000001dU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001dU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x1fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0x10000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3486, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x0000001cU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001cU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x2fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x10000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0x08000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3488, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x0000001bU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001bU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x37ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x08000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0x04000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3490, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x0000001aU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001aU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x3bffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x04000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0x02000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3492, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x00000019U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000019U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x3dffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x02000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0x01000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3494, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x00000018U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000018U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x3effffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x01000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3496, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x00000010U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000010U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x3f00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x00ff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3512, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 8U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                         >> 8U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x3fff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3528, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x3fffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4178, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
    if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o) 
          & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i)) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst)))) {
        ++(vlSelf->__Vcoverage[4721]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
        ++(vlSelf->__Vcoverage[4722]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i)))) {
        ++(vlSelf->__Vcoverage[4723]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o)))) {
        ++(vlSelf->__Vcoverage[4724]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rready_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4653, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rready_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rready_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i)));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5177, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q;
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr) {
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d 
                = (0x00000400U | ((0x00000200U & ((
                                                   (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable)) 
                                                   | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity)) 
                                                  << 9U)) 
                                  | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data) 
                                     << 1U)));
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable) {
                ++(vlSelf->__Vcoverage[5290]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_0 = 0x0bU;
            } else {
                ++(vlSelf->__Vcoverage[5291]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_0 = 0x0aU;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable) {
                ++(vlSelf->__Vcoverage[5286]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable)))) {
                ++(vlSelf->__Vcoverage[5287]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable) {
                ++(vlSelf->__Vcoverage[5288]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable)))) {
                ++(vlSelf->__Vcoverage[5289]);
            }
            ++(vlSelf->__Vcoverage[5297]);
        } else {
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q) 
                 & (0U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q)))) {
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d 
                    = (0x00000400U | (0x000003ffU & 
                                      ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q) 
                                       >> 1U)));
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d 
                    = (1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q));
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d 
                    = (0x0000000fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q) 
                                      - (IData)(1U)));
                ++(vlSelf->__Vcoverage[5292]);
            } else {
                ++(vlSelf->__Vcoverage[5293]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q) 
                 & (0U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q)))) {
                ++(vlSelf->__Vcoverage[5294]);
            }
            if ((0U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q))) {
                ++(vlSelf->__Vcoverage[5295]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q)))) {
                ++(vlSelf->__Vcoverage[5296]);
            }
        }
        ++(vlSelf->__Vcoverage[5299]);
    } else {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d = 0x07ffU;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d = 1U;
        ++(vlSelf->__Vcoverage[5298]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable)))) {
        ++(vlSelf->__Vcoverage[5300]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable) {
        ++(vlSelf->__Vcoverage[5301]);
    }
    ++(vlSelf->__Vcoverage[5302]);
    if ((0x20000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 600, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x0000001dU), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001dU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x1fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0x10000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 602, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x0000001cU), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001cU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x2fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x10000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0x08000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 604, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x0000001bU), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001bU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x37ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x08000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0x04000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 606, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x0000001aU), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001aU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x3bffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x04000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0x02000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 608, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x00000019U), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000019U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x3dffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x02000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0x01000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 610, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x00000018U), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000018U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x3effffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x01000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 612, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x00000010U), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000010U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x3f00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x00ff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 628, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 8U), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                         >> 8U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x3fff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 644, vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg);
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x3fffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
         & (0x0fU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o)))) {
        ++(vlSelf->__Vcoverage[4593]);
    }
    if ((0x0fU != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o))) {
        ++(vlSelf->__Vcoverage[4594]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i)))) {
        ++(vlSelf->__Vcoverage[4595]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4511, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
           & (0x0fU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o)));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4695, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5219, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(11, vlSelf->__Vcoverage + 5249, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5273, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d;
    }
    if ((0x20000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 936, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x0000001dU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001dU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x1fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0x10000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 938, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x0000001cU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001cU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x2fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x10000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0x08000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 940, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x0000001bU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001bU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x37ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x08000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0x04000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 942, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x0000001aU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001aU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x3bffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x04000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0x02000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 944, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x00000019U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000019U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x3dffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x02000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0x01000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 946, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x00000018U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000018U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x3effffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x01000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 948, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x00000010U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000010U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x3f00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x00ff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 964, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 8U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                         >> 8U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x3fff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 980, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x3fffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4589, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
         & (7U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)))) {
        ++(vlSelf->__Vcoverage[4969]);
    }
    if ((7U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o))) {
        ++(vlSelf->__Vcoverage[4970]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i)))) {
        ++(vlSelf->__Vcoverage[4971]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4900, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
           & (7U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)));
    if ((0x20000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1270, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x0000001dU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001dU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x1fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0x10000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1272, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x0000001cU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001cU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x2fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x10000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0x08000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1274, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x0000001bU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001bU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x37ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x08000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0x04000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1276, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x0000001aU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001aU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x3bffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x04000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0x02000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1278, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x00000019U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000019U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x3dffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x02000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0x01000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1280, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x00000018U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000018U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x3effffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x01000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1282, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x00000010U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000010U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x3f00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x00ff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1298, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 8U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                         >> 8U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x3fff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1314, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x3fffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                 >> 0x0000001dU));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                 >> 0x0000001cU));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                 >> 0x0000001bU));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                 >> 0x0000001aU));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                 >> 0x00000019U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                 >> 0x00000018U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d 
        = (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                          >> 8U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d 
        = (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg);
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d 
        = (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                          >> 0x00000010U));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4964, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2237, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2247, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2257, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2267, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2277, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2287, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2686, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2738, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2965, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2241, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2243, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2251, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2253, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2261, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2263, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2271, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2273, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2281, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2283, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2291, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2293, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2704, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2720, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2756, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2772, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2983, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2999, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxempty_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1704, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxempty_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxempty_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxidle_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1702, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxidle_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxidle_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txidle_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1700, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txidle_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txidle_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txempty_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1698, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txempty_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txempty_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxfull_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1696, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxfull_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxfull_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txfull_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1694, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txfull_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txfull_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_rxlvl_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1766, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_rxlvl_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_rxlvl_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_txlvl_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1750, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_txlvl_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_txlvl_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rdata_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1708, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rdata_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rdata_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next = 0U;
    if ((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xfffffff8U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs) 
                   << 2U) | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs) 
                              << 1U) | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs))));
        ++(vlSelf->__Vcoverage[1836]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffffff0fU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs) 
                     << 3U) | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs) 
                               << 2U)) | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs) 
                                           << 1U) | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs))) 
                  << 4U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0x0000ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs) 
                  << 0x00000010U));
    } else if ((2U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xfffffff0U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs) 
                    << 3U) | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs) 
                              << 2U)) | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs) 
                                          << 1U) | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs))));
        ++(vlSelf->__Vcoverage[1837]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffffffcfU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs) 
                   << 5U) | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs) 
                             << 4U)));
    } else if ((4U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs));
        ++(vlSelf->__Vcoverage[1838]);
    } else if ((8U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = (0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next);
        ++(vlSelf->__Vcoverage[1839]);
    } else if ((0x00000010U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = (0xfffffffcU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next);
        ++(vlSelf->__Vcoverage[1840]);
    } else if ((0x00000020U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs));
        ++(vlSelf->__Vcoverage[1841]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xff00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs) 
                  << 0x00000010U));
    } else {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next = 0xffffffffU;
        ++(vlSelf->__Vcoverage[1842]);
    }
    if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))))))) {
        if ((0U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: uart_reg_core.sv:663: Assertion failed in %m: unique case, but multiple matches found for '1'h1'\n",3, 'M',vlSymsp->name(),"uart_tb.u_uart.u_uart_reg.u_reg_core", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("/tmp/flexsoc-ip-v1-release-20260914/uart-reg_iface/runs/uart/release/rtl/uart_reg_core.sv", 663, "");
            }
        }
    }
    ++(vlSelf->__Vcoverage[1843]);
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1488, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next;
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1418, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
        = (((QData)((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata)) 
            << 2U) | (QData)((IData)((1U | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error) 
                                            << 1U)))));
    if ((0U != ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                         >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1088, (IData)(
                                                                       (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                                                        >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((3ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1152, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffdULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o) 
               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1154, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o;
    if ((0U != ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o 
                         >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 754, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o 
                                                                       >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o 
            = ((3ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 818, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o 
                                                                      >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffdULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o) 
               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 820, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o;
    if ((0U != ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o 
                         >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 418, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o 
                                                                       >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o 
            = ((3ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 482, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o 
                                                                      >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffdULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o) 
               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 484, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o)))));
    }
    vlSelfRef.uart_tb__DOT__reg_rsp_o = vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o;
    if ((0U != ((IData)((vlSelfRef.uart_tb__DOT__reg_rsp_o 
                         >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 94, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__reg_rsp_o 
                                                                      >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o 
            = ((3ULL & vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((IData)((vlSelfRef.uart_tb__DOT__reg_rsp_o 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__reg_rsp_o 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 158, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__reg_rsp_o 
                                                                      >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffdULL & vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__reg_rsp_o 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__reg_rsp_o) 
               ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 160, (IData)(vlSelfRef.uart_tb__DOT__reg_rsp_o), (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o));
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffeULL & vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__reg_rsp_o)))));
    }
    vlSelfRef.uart_tb__DOT__reg_rsp_ready = (1U & (IData)(vlSelfRef.uart_tb__DOT__reg_rsp_o));
    vlSelfRef.uart_tb__DOT__reg_rsp_error = (1U & (IData)(
                                                          (vlSelfRef.uart_tb__DOT__reg_rsp_o 
                                                           >> 1U)));
    vlSelfRef.uart_tb__DOT__reg_rsp_rdata = (IData)(
                                                    (vlSelfRef.uart_tb__DOT__reg_rsp_o 
                                                     >> 2U));
    if (((IData)(vlSelfRef.uart_tb__DOT__reg_rsp_ready) 
         ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_ready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 248, vlSelfRef.uart_tb__DOT__reg_rsp_ready, vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_ready);
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_ready 
            = vlSelfRef.uart_tb__DOT__reg_rsp_ready;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__reg_rsp_error) 
         ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 250, vlSelfRef.uart_tb__DOT__reg_rsp_error, vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_error);
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_error 
            = vlSelfRef.uart_tb__DOT__reg_rsp_error;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__reg_rsp_rdata 
                ^ vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_rdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 252, vlSelfRef.uart_tb__DOT__reg_rsp_rdata, vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_rdata);
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_rdata 
            = vlSelfRef.uart_tb__DOT__reg_rsp_rdata;
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
        ++(vlSelf->__Vcoverage[2451]);
    }
    if ((2U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[2452]);
    }
    if ((IData)((6U == (6U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[2453]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 2U)) & (0U == (6U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[2454]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 1U)) & (0U == (6U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[2455]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7ffdU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (2U & ((IData)(((0U != (0x0018U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                             | (0x0018U == (0x0018U 
                                            & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) 
                    << 1U)));
    if ((0x00000010U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[2464]);
    }
    if ((8U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[2465]);
    }
    if ((IData)((0x0018U == (0x0018U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[2466]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 4U)) & (0U == (0x0018U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[2467]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 3U)) & (0U == (0x0018U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[2468]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7ffbU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (4U & ((IData)(((0U != (0x0060U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                             | (0x0060U == (0x0060U 
                                            & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) 
                    << 2U)));
    if ((0x00000040U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[2477]);
    }
    if ((0x00000020U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[2478]);
    }
    if ((IData)((0x0060U == (0x0060U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[2479]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 6U)) & (0U == (0x0060U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[2480]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 5U)) & (0U == (0x0060U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[2481]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7ff7U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (8U & ((IData)(((0U != (0x0180U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                             | (0x0180U == (0x0180U 
                                            & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) 
                    << 3U)));
    if ((0x00000100U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[2490]);
    }
    if ((0x00000080U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[2491]);
    }
    if ((IData)((0x0180U == (0x0180U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[2492]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 8U)) & (0U == (0x0180U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[2493]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 7U)) & (0U == (0x0180U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[2494]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7fefU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (0x00000010U & ((IData)(((0U != (0x0600U 
                                              & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                                      | (0x0600U == 
                                         (0x0600U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) 
                             << 4U)));
    if ((0x00000400U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[2503]);
    }
    if ((0x00000200U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[2504]);
    }
    if ((IData)((0x0600U == (0x0600U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[2505]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 0x0000000aU)) & (0U == (0x0600U 
                                                & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[2506]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 9U)) & (0U == (0x0600U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[2507]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7fdfU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (0x00000020U & ((IData)(((0U != (0x1800U 
                                              & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                                      | (0x1800U == 
                                         (0x1800U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) 
                             << 5U)));
    if ((0x00001000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[2516]);
    }
    if ((0x00000800U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[2517]);
    }
    if ((IData)((0x1800U == (0x1800U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[2518]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 0x0000000cU)) & (0U == (0x1800U 
                                                & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[2519]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 0x0000000bU)) & (0U == (0x1800U 
                                                & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[2520]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7fbfU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (0x00000040U & ((IData)(((0U != (0x6000U 
                                              & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                                      | (0x6000U == 
                                         (0x6000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) 
                             << 6U)));
    if ((0x00004000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[2529]);
    }
    if ((0x00002000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[2530]);
    }
    if ((IData)((0x6000U == (0x6000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[2531]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 0x0000000eU)) & (0U == (0x6000U 
                                                & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[2532]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 0x0000000dU)) & (0U == (0x6000U 
                                                & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[2533]);
    }
}
