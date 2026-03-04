// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTOP_PKG_H_
#define VERILATED_VTOP_PKG_H_  // guard

#include "verilated.h"

class Vtop_pkg__Syms;
class Vtop_pkg___024root;
class Vtop_pkg_tlul_fifo_sync__RCz9_RDz9;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vtop_pkg VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vtop_pkg__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = false;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&prim_clk_div__02Eclk_i,0,0);
    VL_IN8(&prim_clk_div__02Erst_ni,0,0);
    VL_IN8(&prim_lifo__02Eclk_i,0,0);
    VL_IN8(&prim_lifo__02Erst_ni,0,0);
    VL_IN8(&prim_ram__02Eclk_i,0,0);
    VL_IN8(&prim_rom__02Eclk_i,0,0);
    VL_IN8(&prim_shreg__02Eclk_i,0,0);
    VL_IN8(&prim_cdc_rand_delay__02Eclk_i,0,0);
    VL_IN8(&prim_cdc_rand_delay__02Erst_ni,0,0);
    VL_IN8(&prim_intr_hw__02Eclk_i,0,0);
    VL_IN8(&prim_intr_hw__02Erst_ni,0,0);
    VL_IN8(&src_clk_i,0,0);
    VL_IN8(&src_rst_ni,0,0);
    VL_IN8(&dst_clk_i,0,0);
    VL_IN8(&dst_rst_ni,0,0);
    VL_IN8(&prim_counter__02Eclk_i,0,0);
    VL_IN8(&prim_counter__02Erst_ni,0,0);
    VL_IN8(&prim_deglitch__02Eclk_i,0,0);
    VL_IN8(&prim_deglitch__02Erst_ni,0,0);
    VL_IN8(&prim_edge_detect__02Eclk_i,0,0);
    VL_IN8(&prim_edge_detect__02Erst_ni,0,0);
    VL_IN8(&rd_clk_i,0,0);
    VL_IN8(&wr_clk_i,0,0);
    VL_IN8(&prim_fifo__02Erst_ni,0,0);
    VL_IN8(&prim_reg__02Eclk_i,0,0);
    VL_IN8(&prim_reg__02Erst_ni,0,0);
    VL_IN8(&rrarbiter__02Eclk_i,0,0);
    VL_IN8(&rrarbiter__02Erst_ni,0,0);
    VL_IN8(&prim_fifo_async_simple__02Eclk_wr_i,0,0);
    VL_IN8(&prim_fifo_async_simple__02Erst_wr_ni,0,0);
    VL_IN8(&prim_fifo_async_simple__02Eclk_rd_i,0,0);
    VL_IN8(&prim_fifo_async_simple__02Erst_rd_ni,0,0);
    VL_IN8(&prim_fifo_async_sram_adapter__02Eclk_wr_i,0,0);
    VL_IN8(&prim_fifo_async_sram_adapter__02Erst_wr_ni,0,0);
    VL_IN8(&prim_fifo_async_sram_adapter__02Eclk_rd_i,0,0);
    VL_IN8(&prim_fifo_async_sram_adapter__02Erst_rd_ni,0,0);
    VL_IN8(&prim_filter__02Eclk_i,0,0);
    VL_IN8(&prim_filter__02Erst_ni,0,0);
    VL_IN8(&prim_filter_ctr__02Eclk_i,0,0);
    VL_IN8(&prim_filter_ctr__02Erst_ni,0,0);
    VL_IN8(&clk_src_i,0,0);
    VL_IN8(&rst_src_ni,0,0);
    VL_IN8(&clk_dst_i,0,0);
    VL_IN8(&rst_dst_ni,0,0);
    VL_IN8(&prim_alert_sender__02Eclk_i,0,0);
    VL_IN8(&prim_alert_sender__02Erst_ni,0,0);
    VL_IN8(&tlul_adapter_host__02Eclk_i,0,0);
    VL_IN8(&tlul_adapter_host__02Erst_ni,0,0);
    VL_IN8(&tlul_adapter_sram__02Eclk_i,0,0);
    VL_IN8(&tlul_adapter_sram__02Erst_ni,0,0);
    VL_IN8(&clk_h_i,0,0);
    VL_IN8(&rst_h_ni,0,0);
    VL_IN8(&clk_d_i,0,0);
    VL_IN8(&rst_d_ni,0,0);
    VL_IN8(&tlul_socket_1n__02Eclk_i,0,0);
    VL_IN8(&tlul_socket_1n__02Erst_ni,0,0);
    VL_IN8(&tlul_socket_m1__02Eclk_i,0,0);
    VL_IN8(&tlul_socket_m1__02Erst_ni,0,0);
    VL_IN8(&my_ip__02Eclk_i,0,0);
    VL_IN8(&my_ip__02Erst_ni,0,0);
    VL_IN8(&testmode_i,0,0);
    VL_IN8(&prim_clk_div__02Een_i,0,0);
    VL_OUT8(&prim_clk_div__02Eclk_o,0,0);
    VL_IN8(&prim_clk_gate__02Eclk_i,0,0);
    VL_IN8(&prim_clk_gate__02Een_i,0,0);
    VL_IN8(&test_en_i,0,0);
    VL_OUT8(&prim_clk_gate__02Eclk_o,0,0);
    VL_IN8(&A,0,-2);
    VL_OUT8(&Z,0,-2);
    VL_IN8(&prim_lifo__02Ewdata_i,7,0);
    VL_IN8(&prim_lifo__02Ewvalid_i,0,0);
    VL_OUT8(&prim_lifo__02Ewready_o,0,0);
    VL_OUT8(&prim_lifo__02Erdata_o,7,0);
    VL_OUT8(&prim_lifo__02Ervalid_o,0,0);
    VL_IN8(&prim_lifo__02Erready_i,0,0);
    VL_OUT8(&lifo_full_o,0,0);
    VL_OUT8(&lifo_empty_o,0,0);
    VL_IN8(&prim_ram__02Erst_ni,0,0);
    VL_IN8(&prim_ram__02Een_i,0,0);
    VL_IN8(&prim_ram__02Ewe_i,0,0);
    VL_IN8(&prim_rom__02Erst_ni,0,0);
    VL_IN8(&prim_shreg__02Erst_ni,0,0);
    VL_IN8(&prim_shreg__02Een_i,0,0);
    VL_IN8(&prim_shreg__02Eserial_i,0,0);
    VL_OUT8(&pdata_o,7,0);
    VL_OUT8(&serial_o,0,0);
    VL_IN8(&prev_data_i,0,0);
    VL_IN8(&prim_cdc_rand_delay__02Esrc_data_i,0,0);
    VL_OUT8(&prim_cdc_rand_delay__02Edst_data_o,0,0);
    VL_IN8(&event_intr_i,0,0);
    VL_IN8(&reg2hw_intr_enable_q_i,0,0);
    VL_IN8(&reg2hw_intr_test_q_i,0,0);
    VL_IN8(&reg2hw_intr_test_qe_i,0,0);
    VL_IN8(&reg2hw_intr_state_q_i,0,0);
    VL_OUT8(&hw2reg_intr_state_de_o,0,0);
    VL_OUT8(&hw2reg_intr_state_d_o,0,0);
    VL_OUT8(&intr_o,0,0);
    VL_IN8(&cdc_2phase__02Esrc_data_i,0,0);
    VL_IN8(&src_valid_i,0,0);
    VL_OUT8(&src_ready_o,0,0);
    VL_OUT8(&cdc_2phase__02Edst_data_o,0,0);
    VL_OUT8(&dst_valid_o,0,0);
    VL_IN8(&dst_ready_i,0,0);
    VL_IN8(&prim_counter__02Een_i,0,0);
    VL_IN8(&clr_i,0,0);
    VL_IN8(&up_down_i,0,0);
    VL_IN8(&step_i,3,0);
    VL_IN8(&tc_val_i,3,0);
    VL_OUT8(&val_o,3,0);
    VL_OUT8(&tc_o,0,0);
    VL_IN8(&prim_deglitch__02Een_i,0,0);
    VL_IN8(&d_i,0,0);
    VL_OUT8(&q_o,0,0);
    VL_IN8(&prim_edge_detect__02Een_i,0,0);
    VL_IN8(&prim_edge_detect__02Eserial_i,0,0);
    VL_OUT8(&r_edge_o,0,0);
    VL_OUT8(&f_edge_o,0,0);
    VL_IN8(&prim_fifo__02Ewdata_i,7,0);
    VL_IN8(&prim_fifo__02Ewvalid_i,0,0);
    VL_OUT8(&prim_fifo__02Ewready_o,0,0);
    VL_OUT8(&prim_fifo__02Erdata_o,7,0);
    VL_OUT8(&prim_fifo__02Ervalid_o,0,0);
    VL_IN8(&prim_fifo__02Erready_i,0,0);
    VL_OUT8(&fifo_full,0,0);
    VL_OUT8(&fifo_empty,0,0);
    VL_IN8(&we,0,0);
    VL_IN8(&de,0,0);
    VL_OUT8(&qe,0,0);
    VL_IN8(&flush_i,0,0);
    VL_IN8(&rrarbiter__02Een_i,0,0);
    VL_OUT8(&vld_o,0,0);
    VL_OUT8(&idx_o,3,0);
    VL_IN8(&prim_fifo_async_simple__02Ewvalid_i,0,0);
    VL_OUT8(&prim_fifo_async_simple__02Ewready_o,0,0);
    VL_OUT8(&prim_fifo_async_simple__02Ervalid_o,0,0);
    VL_IN8(&prim_fifo_async_simple__02Erready_i,0,0);
    VL_IN8(&prim_fifo_async_sram_adapter__02Ewvalid_i,0,0);
    VL_OUT8(&prim_fifo_async_sram_adapter__02Ewready_o,0,0);
    VL_OUT8(&wdepth_o,4,0);
    VL_OUT8(&prim_fifo_async_sram_adapter__02Ervalid_o,0,0);
    VL_IN8(&prim_fifo_async_sram_adapter__02Erready_i,0,0);
    VL_OUT8(&rdepth_o,4,0);
    VL_OUT8(&r_full_o,0,0);
    VL_OUT8(&r_notempty_o,0,0);
    VL_OUT8(&w_full_o,0,0);
    VL_OUT8(&w_sram_req_o,0,0);
    VL_IN8(&w_sram_gnt_i,0,0);
    VL_OUT8(&w_sram_write_o,0,0);
    VL_IN8(&w_sram_rvalid_i,0,0);
    VL_IN8(&w_sram_rerror_i,1,0);
    VL_OUT8(&r_sram_req_o,0,0);
    VL_IN8(&r_sram_gnt_i,0,0);
    VL_OUT8(&r_sram_write_o,0,0);
    VL_IN8(&r_sram_rvalid_i,0,0);
    VL_IN8(&r_sram_rerror_i,1,0);
    VL_IN8(&prim_filter__02Eenable_i,0,0);
    VL_IN8(&prim_filter__02Efilter_i,0,0);
    VL_OUT8(&prim_filter__02Efilter_o,0,0);
    VL_IN8(&prim_filter_ctr__02Eenable_i,0,0);
    VL_IN8(&prim_filter_ctr__02Efilter_i,0,0);
    VL_IN8(&thresh_i,1,0);
    VL_OUT8(&prim_filter_ctr__02Efilter_o,0,0);
    VL_IN8(&src_regwen_i,0,0);
    VL_IN8(&src_we_i,0,0);
    VL_IN8(&src_re_i,0,0);
    VL_OUT8(&src_busy_o,0,0);
    VL_IN8(&dst_update_i,0,0);
    VL_OUT8(&dst_we_o,0,0);
    VL_OUT8(&dst_re_o,0,0);
    VL_OUT8(&dst_regwen_o,0,0);
    VL_IN8(&prim_reg_we_check__02Eclk_i,0,0);
    VL_IN8(&prim_reg_we_check__02Erst_ni,0,0);
    VL_IN8(&prim_reg_we_check__02Een_i,0,0);
    VL_OUT8(&prim_reg_we_check__02Eerr_o,0,0);
    VL_IN8(&alert_test_i,0,0);
    VL_IN8(&alert_req_i,0,0);
    VL_OUT8(&alert_ack_o,0,0);
    VL_OUT8(&alert_state_o,0,0);
    VL_IN8(&alert_rx_i,3,0);
    VL_OUT8(&alert_tx_o,1,0);
    VL_IN8(&sram2tlul__02Eclk_i,0,0);
    VL_IN8(&sram2tlul__02Erst_ni,0,0);
    VL_IN8(&mem_req_i,0,0);
    VL_IN8(&mem_write_i,0,0);
    VL_OUT8(&mem_rvalid_o,0,0);
    VL_OUT8(&mem_error_o,1,0);
    VL_IN8(&tlul_adapter_host__02Ereq_i,0,0);
    VL_OUT8(&gnt_o,0,0);
    VL_IN8(&tlul_adapter_host__02Ewe_i,0,0);
    VL_IN8(&wdata_intg_i,6,0);
    VL_IN8(&be_i,3,0);
    VL_IN8(&instr_type_i,3,0);
    VL_OUT8(&valid_o,0,0);
    VL_OUT8(&rdata_intg_o,6,0);
    VL_OUT8(&tlul_adapter_host__02Eerr_o,0,0);
    VL_OUT8(&intg_err_o,0,0);
    VL_IN8(&en_ifetch_i,3,0);
    VL_OUT8(&req_o,0,0);
    VL_OUT8(&req_type_o,3,0);
    VL_IN8(&gnt_i,0,0);
    VL_OUT8(&we_o,0,0);
    VL_OUT8(&intg_error_o,0,0);
    VL_IN8(&rvalid_i,0,0);
    VL_IN8(&rerror_i,1,0);
    VL_OUT8(&compound_txn_in_progress_o,0,0);
    VL_IN8(&readback_en_i,3,0);
    VL_OUT8(&readback_error_o,0,0);
    VL_IN8(&wr_collision_i,0,0);
    VL_IN8(&write_pending_i,0,0);
    VL_IN8(&tlul_assert_multiple__02Eclk_i,0,0);
    VL_IN8(&tlul_assert_multiple__02Erst_ni,0,0);
    VL_IN8(&dev_select_i,2,0);
    VL_IN8(&port_i,0,0);
    VL_OUT8(&port_o,0,0);
    VL_IN16(&prim_ram__02Eaddr_i,15,0);
    VL_IN16(&prim_rom__02Eaddr_i,15,0);
    VL_IN16(&rrarbiter__02Ereq_i,12,0);
    VL_OUT16(&ack_o,12,0);
    VL_IN16(&prim_fifo_async_simple__02Ewdata_i,15,0);
    VL_OUT16(&prim_fifo_async_simple__02Erdata_o,15,0);
    VL_OUT16(&w_sram_addr_o,15,0);
    VL_OUT16(&r_sram_addr_o,15,0);
    VL_IN16(&mem_addr_i,11,0);
    VL_OUT16(&addr_o,11,0);
    VL_IN(&prim_ram__02Ewdata_i,31,0);
    VL_OUT(&prim_ram__02Erdata_o,31,0);
    VL_OUT(&prim_rom__02Erdata_o,31,0);
    VL_IN(&wd,31,0);
    VL_OUT(&ds,31,0);
    VL_OUT(&qs,31,0);
    VL_IN(&d,31,0);
    VL_OUT(&q,31,0);
    VL_IN(&prim_fifo_async_sram_adapter__02Ewdata_i,31,0);
    VL_OUT(&prim_fifo_async_sram_adapter__02Erdata_o,31,0);
    VL_OUT(&w_sram_wdata_o,31,0);
    VL_OUT(&w_sram_wmask_o,31,0);
    VL_IN(&w_sram_rdata_i,31,0);
    VL_OUT(&r_sram_wdata_o,31,0);
    VL_OUT(&r_sram_wmask_o,31,0);
    VL_IN(&r_sram_rdata_i,31,0);
    VL_IN(&src_wd_i,31,0);
    VL_OUT(&src_qs_o,31,0);
    VL_IN(&dst_ds_i,31,0);
    VL_IN(&dst_qs_i,31,0);
    VL_OUT(&dst_wd_o,31,0);
    VL_IN(&oh_i,31,0);
    VL_IN(&mem_wdata_i,31,0);
    VL_OUT(&mem_rdata_o,31,0);
    VL_IN(&tlul_adapter_host__02Eaddr_i,31,0);
    VL_IN(&tlul_adapter_host__02Ewdata_i,31,0);
    VL_OUT(&tlul_adapter_host__02Erdata_o,31,0);
    VL_OUT(&wdata_o,31,0);
    VL_OUT(&wmask_o,31,0);
    VL_IN(&rdata_i,31,0);
    VL_OUTW(&sram2tlul__02Etl_o,108,0,4);
    VL_INW(&sram2tlul__02Etl_i,65,0,3);
    VL_OUTW(&tlul_adapter_host__02Etl_o,108,0,4);
    VL_INW(&tlul_adapter_host__02Etl_i,65,0,3);
    VL_INW(&tlul_adapter_sram__02Etl_i,108,0,4);
    VL_OUTW(&tlul_adapter_sram__02Etl_o,65,0,3);
    VL_INW(&tlul_fifo_async__02Etl_h_i,108,0,4);
    VL_OUTW(&tlul_fifo_async__02Etl_h_o,65,0,3);
    VL_OUTW(&tlul_fifo_async__02Etl_d_o,108,0,4);
    VL_INW(&tlul_fifo_async__02Etl_d_i,65,0,3);
    VL_INW(&tlul_socket_1n__02Etl_h_i,108,0,4);
    VL_OUTW(&tlul_socket_1n__02Etl_h_o,65,0,3);
    VL_OUTW(&tlul_socket_m1__02Etl_d_o,108,0,4);
    VL_INW(&tlul_socket_m1__02Etl_d_i,65,0,3);
    VL_INW(&my_ip__02Etl_i,108,0,4);
    VL_OUTW(&my_ip__02Etl_o,65,0,3);
    VL_INW((&h2d)[2],108,0,4);
    VL_INW((&d2h)[2],65,0,3);
    VL_OUTW((&tlul_socket_1n__02Etl_d_o)[4],108,0,4);
    VL_INW((&tlul_socket_1n__02Etl_d_i)[4],65,0,3);
    VL_INW((&tlul_socket_m1__02Etl_h_i)[4],108,0,4);
    VL_OUTW((&tlul_socket_m1__02Etl_h_o)[4],65,0,3);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* const __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d;
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* const __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d;
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* const __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d;
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* const __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d;
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* const __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo;
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* const __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo;
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* const __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo;
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* const __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vtop_pkg___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vtop_pkg(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vtop_pkg(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vtop_pkg();
  private:
    VL_UNCOPYABLE(Vtop_pkg);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
