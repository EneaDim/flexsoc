// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VPWM_RAMP_TB_H_
#define VERILATED_VPWM_RAMP_TB_H_  // guard

#include "verilated.h"

class Vpwm_ramp_tb__Syms;
class Vpwm_ramp_tb___024root;
class VerilatedVcdC;
class Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vpwm_ramp_tb VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vpwm_ramp_tb__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = true;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
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
    VL_IN8(&prim_subreg__02Eclk_i,0,0);
    VL_IN8(&prim_subreg__02Erst_ni,0,0);
    VL_IN8(&tlul_adapter_host__02Eclk_i,0,0);
    VL_IN8(&tlul_adapter_host__02Erst_ni,0,0);
    VL_IN8(&tlul_adapter_reg__02Eclk_i,0,0);
    VL_IN8(&tlul_adapter_reg__02Erst_ni,0,0);
    VL_IN8(&tlul_adapter_sram__02Eclk_i,0,0);
    VL_IN8(&tlul_adapter_sram__02Erst_ni,0,0);
    VL_IN8(&tlul_assert_multiple__02Eclk_i,0,0);
    VL_IN8(&tlul_assert_multiple__02Erst_ni,0,0);
    VL_IN8(&clk_h_i,0,0);
    VL_IN8(&rst_h_ni,0,0);
    VL_IN8(&clk_d_i,0,0);
    VL_IN8(&rst_d_ni,0,0);
    VL_IN8(&tlul_socket_1n__02Eclk_i,0,0);
    VL_IN8(&tlul_socket_1n__02Erst_ni,0,0);
    VL_IN8(&tlul_socket_m1__02Eclk_i,0,0);
    VL_IN8(&tlul_socket_m1__02Erst_ni,0,0);
    VL_IN8(&multiple_pwm_ramp__02Eclk_i,0,0);
    VL_IN8(&multiple_pwm_ramp__02Erst_ni,0,0);
    VL_IN8(&prim_cdc_rand_delay__02Eclk_i,0,0);
    VL_IN8(&prim_cdc_rand_delay__02Erst_ni,0,0);
    VL_IN8(&prev_data_i,0,0);
    VL_IN8(&src_data_i,0,0);
    VL_OUT8(&dst_data_o,0,0);
    VL_IN8(&re,0,0);
    VL_IN8(&prim_subreg_ext__02Ewe,0,0);
    VL_OUT8(&prim_subreg_ext__02Eqe,0,0);
    VL_OUT8(&qre,0,0);
    VL_IN8(&sram2tlul__02Eclk_i,0,0);
    VL_IN8(&sram2tlul__02Erst_ni,0,0);
    VL_IN8(&mem_req_i,0,0);
    VL_IN8(&mem_write_i,0,0);
    VL_OUT8(&mem_rvalid_o,0,0);
    VL_OUT8(&mem_error_o,1,0);
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
    VL_IN8(&prim_subreg__02Ewe,0,0);
    VL_IN8(&de,0,0);
    VL_OUT8(&prim_subreg__02Eqe,0,0);
    VL_IN8(&req_i,0,0);
    VL_OUT8(&gnt_o,0,0);
    VL_IN8(&we_i,0,0);
    VL_IN8(&wdata_intg_i,6,0);
    VL_IN8(&be_i,3,0);
    VL_IN8(&instr_type_i,3,0);
    VL_OUT8(&valid_o,0,0);
    VL_OUT8(&rdata_intg_o,6,0);
    VL_OUT8(&err_o,0,0);
    VL_OUT8(&intg_err_o,0,0);
    VL_IN8(&tlul_adapter_reg__02Een_ifetch_i,3,0);
    VL_OUT8(&tlul_adapter_reg__02Eintg_error_o,0,0);
    VL_OUT8(&re_o,0,0);
    VL_OUT8(&tlul_adapter_reg__02Ewe_o,0,0);
    VL_OUT8(&tlul_adapter_reg__02Eaddr_o,7,0);
    VL_OUT8(&be_o,3,0);
    VL_IN8(&busy_i,0,0);
    VL_IN8(&error_i,0,0);
    VL_IN8(&tlul_adapter_sram__02Een_ifetch_i,3,0);
    VL_OUT8(&req_o,0,0);
    VL_OUT8(&req_type_o,3,0);
    VL_IN8(&gnt_i,0,0);
    VL_OUT8(&tlul_adapter_sram__02Ewe_o,0,0);
    VL_OUT8(&tlul_adapter_sram__02Eintg_error_o,0,0);
    VL_IN8(&rvalid_i,0,0);
    VL_IN8(&rerror_i,1,0);
    VL_OUT8(&compound_txn_in_progress_o,0,0);
    VL_IN8(&readback_en_i,3,0);
    VL_OUT8(&readback_error_o,0,0);
    VL_IN8(&wr_collision_i,0,0);
    VL_IN8(&write_pending_i,0,0);
    VL_IN8(&dev_select_i,2,0);
    VL_IN8(&multiple_pwm_ramp__02Eenable_i,0,0);
    VL_IN8(&step_i,7,0);
    VL_IN8(&lvds_0_i,0,0);
    VL_IN8(&lvds_1_i,0,0);
    VL_OUT8(&pwm_0_o,0,0);
    VL_OUT8(&pwm_1_o,0,0);
    VL_OUT8(&adc_value_o,7,0);
    VL_OUT8(&adc_valid_o,0,0);
    VL_IN16(&mem_addr_i,11,0);
    VL_IN16(&prim_fifo_async_simple__02Ewdata_i,15,0);
    VL_OUT16(&prim_fifo_async_simple__02Erdata_o,15,0);
    VL_OUT16(&w_sram_addr_o,15,0);
    VL_OUT16(&r_sram_addr_o,15,0);
    VL_OUT16(&tlul_adapter_sram__02Eaddr_o,11,0);
    VL_IN(&prim_subreg_ext__02Ewd,31,0);
    VL_IN(&prim_subreg_ext__02Ed,31,0);
    VL_OUT(&prim_subreg_ext__02Eq,31,0);
    VL_OUT(&prim_subreg_ext__02Eds,31,0);
    VL_OUT(&prim_subreg_ext__02Eqs,31,0);
    VL_OUTW(&sram2tlul__02Etl_o,108,0,4);
    VL_INW(&sram2tlul__02Etl_i,65,0,3);
    VL_IN(&mem_wdata_i,31,0);
    VL_OUT(&mem_rdata_o,31,0);
    VL_IN(&prim_fifo_async_sram_adapter__02Ewdata_i,31,0);
    VL_OUT(&prim_fifo_async_sram_adapter__02Erdata_o,31,0);
    VL_OUT(&w_sram_wdata_o,31,0);
    VL_OUT(&w_sram_wmask_o,31,0);
    VL_IN(&w_sram_rdata_i,31,0);
    VL_OUT(&r_sram_wdata_o,31,0);
    VL_OUT(&r_sram_wmask_o,31,0);
    VL_IN(&r_sram_rdata_i,31,0);
    VL_IN(&prim_subreg__02Ewd,31,0);
    VL_IN(&prim_subreg__02Ed,31,0);
    VL_OUT(&prim_subreg__02Eq,31,0);
    VL_OUT(&prim_subreg__02Eds,31,0);
    VL_OUT(&prim_subreg__02Eqs,31,0);
    VL_IN(&addr_i,31,0);
    VL_IN(&tlul_adapter_host__02Ewdata_i,31,0);
    VL_OUT(&tlul_adapter_host__02Erdata_o,31,0);
    VL_OUTW(&tlul_adapter_host__02Etl_o,108,0,4);
    VL_INW(&tlul_adapter_host__02Etl_i,65,0,3);
    VL_INW(&tlul_adapter_reg__02Etl_i,108,0,4);
    VL_OUTW(&tlul_adapter_reg__02Etl_o,65,0,3);
    VL_OUT(&tlul_adapter_reg__02Ewdata_o,31,0);
    VL_IN(&tlul_adapter_reg__02Erdata_i,31,0);
    VL_INW(&tlul_adapter_sram__02Etl_i,108,0,4);
    VL_OUTW(&tlul_adapter_sram__02Etl_o,65,0,3);
    VL_OUT(&tlul_adapter_sram__02Ewdata_o,31,0);
    VL_OUT(&wmask_o,31,0);
    VL_IN(&tlul_adapter_sram__02Erdata_i,31,0);
    VL_INW(&h2d,217,0,7);
    VL_INW(&d2h,131,0,5);
    VL_INW(&tlul_fifo_async__02Etl_h_i,108,0,4);
    VL_OUTW(&tlul_fifo_async__02Etl_h_o,65,0,3);
    VL_OUTW(&tlul_fifo_async__02Etl_d_o,108,0,4);
    VL_INW(&tlul_fifo_async__02Etl_d_i,65,0,3);
    VL_INW(&tlul_socket_1n__02Etl_h_i,108,0,4);
    VL_OUTW(&tlul_socket_1n__02Etl_h_o,65,0,3);
    VL_OUTW(&tlul_socket_1n__02Etl_d_o,435,0,14);
    VL_INW(&tlul_socket_1n__02Etl_d_i,263,0,9);
    VL_INW(&tlul_socket_m1__02Etl_h_i,435,0,14);
    VL_OUTW(&tlul_socket_m1__02Etl_h_o,263,0,9);
    VL_OUTW(&tlul_socket_m1__02Etl_d_o,108,0,4);
    VL_INW(&tlul_socket_m1__02Etl_d_i,65,0,3);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6* const __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d;
    Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6* const __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d;
    Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6* const __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d;
    Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6* const __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d;
    Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6* const __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo;
    Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6* const __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo;
    Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6* const __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo;
    Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6* const __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vpwm_ramp_tb___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vpwm_ramp_tb(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vpwm_ramp_tb(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vpwm_ramp_tb();
  private:
    VL_UNCOPYABLE(Vpwm_ramp_tb);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); eval_end_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step();
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
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
