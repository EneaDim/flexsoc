// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"
#include "verilated_fst_c.h"

// INCLUDE MODEL CLASS

#include "Vtop.h"

// INCLUDE MODULE CLASSES
#include "Vtop___024root.h"
#include "Vtop_cf_math_pkg.h"
#include "Vtop_axi_pkg.h"
#include "Vtop_prim_util_pkg.h"
#include "Vtop_uart_reg_pkg.h"
#include "Vtop_prim_mubi_pkg.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop* const __Vm_modelp;
    bool __Vm_dumping = false;  // Dumping is active
    VerilatedMutex __Vm_dumperMutex;  // Protect __Vm_dumperp
    VerilatedFstC* __Vm_dumperp VL_GUARDED_BY(__Vm_dumperMutex) = nullptr;  /// Trace class for $dump*
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;
    Vtop_axi_pkg                   TOP__axi_pkg;
    Vtop_prim_mubi_pkg             TOP__prim_mubi_pkg;
    Vtop_uart_reg_pkg              TOP__uart_reg_pkg;

    // COVERAGE
    uint32_t __Vcoverage[8550];

    // SCOPE NAMES
    VerilatedScope* __Vscopep_axi_pkg;
    VerilatedScope* __Vscopep_prim_mubi_pkg;
    VerilatedScope* __Vscopep_uart_reg_pkg;
    VerilatedScope* __Vscopep_uart_tb;
    VerilatedScope* __Vscopep_uart_tb__u_uart;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_core_reset_sync;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_core_reset_sync__u_sync_1;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_core_reset_sync__u_sync_2;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_reg_reset_sync;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_reg_reset_sync__u_sync_1;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_reg_reset_sync__u_sync_2;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_core;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_core__sync_rx;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_core__sync_rx__u_sync_1;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_core__sync_rx__u_sync_2;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_core__u_rx_reset_branch;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_core__u_timing_reset_branch;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_core__u_tx_reset_branch;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_core__u_uart_rxfifo;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_core__u_uart_rxfifo__gen_normal_fifo;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_core__u_uart_rxfifo__gen_normal_fifo__u_fifo_cnt;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_core__u_uart_txfifo;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_core__u_uart_txfifo__gen_normal_fifo;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_core__u_uart_txfifo__gen_normal_fifo__u_fifo_cnt;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_core__uart_rx;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_core__uart_tx;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_fifo_read;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_fifo_read_resp;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_fifo_write_req;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_fifo_write_resp;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb__gen_rr_arb;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb__gen_rr_arb__i_arbiter;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb__gen_rr_arb__i_arbiter__gen_arbiter;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb__gen_rr_arb__i_arbiter__gen_arbiter__gen_int_rr;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb__gen_rr_arb__i_arbiter__gen_arbiter__gen_int_rr__gen_fair_arb;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb__gen_rr_arb__i_arbiter__gen_arbiter__gen_int_rr__gen_fair_arb__i_lzc_lower;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb__gen_rr_arb__i_arbiter__gen_arbiter__gen_int_rr__gen_fair_arb__i_lzc_lower__gen_lzc;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb__gen_rr_arb__i_arbiter__gen_arbiter__gen_int_rr__gen_fair_arb__i_lzc_lower__gen_lzc__flip_vector;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb__gen_rr_arb__i_arbiter__gen_arbiter__gen_int_rr__gen_fair_arb__i_lzc_lower__gen_lzc__flip_vector__unnamedblk1;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb__gen_rr_arb__i_arbiter__gen_arbiter__gen_int_rr__gen_fair_arb__i_lzc_upper;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb__gen_rr_arb__i_arbiter__gen_arbiter__gen_int_rr__gen_fair_arb__i_lzc_upper__gen_lzc;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb__gen_rr_arb__i_arbiter__gen_arbiter__gen_int_rr__gen_fair_arb__i_lzc_upper__gen_lzc__flip_vector;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb__gen_rr_arb__i_arbiter__gen_arbiter__gen_int_rr__gen_fair_arb__i_lzc_upper__gen_lzc__flip_vector__unnamedblk1;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb__gen_rr_arb__i_arbiter__gen_arbiter__gen_int_rr__gen_lock;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb__gen_rr_arb__i_arbiter__gen_arbiter__gen_levels__BRA__0__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_flexsoc_axi_to_reg__i_stream_arbiter__i_arb__gen_rr_arb__i_arbiter__gen_arbiter__gen_levels__BRA__0__KET____gen_level__BRA__0__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_llpbk;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_llpbk__wr_en_data_arb;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_llpbk__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_nco;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_nco__wr_en_data_arb;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_nco__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_nf;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_nf__wr_en_data_arb;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_nf__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_parity_en;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_parity_en__wr_en_data_arb;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_parity_en__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_parity_odd;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_parity_odd__wr_en_data_arb;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_parity_odd__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_rx;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_rx__wr_en_data_arb;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_rx__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_slpbk;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_slpbk__wr_en_data_arb;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_slpbk__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_tx;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_tx__wr_en_data_arb;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_ctrl_tx__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_fifo_ctrl0_qe;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_fifo_ctrl_rxrst;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_fifo_ctrl_rxrst__wr_en_data_arb;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_fifo_ctrl_rxrst__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_fifo_ctrl_txrst;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_fifo_ctrl_txrst__wr_en_data_arb;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_fifo_ctrl_txrst__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_fifo_status_rxlvl;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_fifo_status_txlvl;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_buf;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__0__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__0__KET____gen_level__BRA__0__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__1__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__1__KET____gen_level__BRA__0__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__1__KET____gen_level__BRA__1__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__2__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__2__KET____gen_level__BRA__0__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__2__KET____gen_level__BRA__1__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__2__KET____gen_level__BRA__2__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__2__KET____gen_level__BRA__3__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__3__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__3__KET____gen_level__BRA__0__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__3__KET____gen_level__BRA__1__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__3__KET____gen_level__BRA__2__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__3__KET____gen_level__BRA__3__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__3__KET____gen_level__BRA__4__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__3__KET____gen_level__BRA__5__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__3__KET____gen_level__BRA__6__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__3__KET____gen_level__BRA__7__KET__;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_rdata;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_status_rxempty;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_status_rxfull;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_status_rxidle;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_status_txempty;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_status_txfull;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_status_txidle;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_wdata;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_wdata0_qe;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_wdata__wr_en_data_arb;
    VerilatedScope* __Vscopep_uart_tb__u_uart__u_uart_reg__u_reg_core__u_wdata__wr_en_data_arb__gen_w;

    // SCOPE HIERARCHY
    VerilatedHierarchy __Vhier;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
};

#endif  // guard
