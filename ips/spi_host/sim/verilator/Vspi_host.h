// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VSPI_HOST_H_
#define VERILATED_VSPI_HOST_H_  // guard

#include "verilated.h"

class Vspi_host__Syms;
class Vspi_host___024root;
class Vspi_host_tlul_fifo_sync__RCz6_RDz6;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vspi_host VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vspi_host__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = false;

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
    VL_IN8(&tlul_adapter_host__02Eclk_i,0,0);
    VL_IN8(&tlul_adapter_host__02Erst_ni,0,0);
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
    VL_IN8(&spi_host__02Eclk_i,0,0);
    VL_IN8(&spi_host__02Erst_ni,0,0);
    VL_IN8(&prim_cdc_rand_delay__02Eclk_i,0,0);
    VL_IN8(&prim_cdc_rand_delay__02Erst_ni,0,0);
    VL_IN8(&prev_data_i,0,0);
    VL_IN8(&src_data_i,0,0);
    VL_OUT8(&dst_data_o,0,0);
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
    VL_IN8(&dev_select_i,2,0);
    VL_OUT8(&spi_cs_o,0,0);
    VL_OUT8(&spi_sclk_o,0,0);
    VL_OUT8(&spi_sdioz_o,0,0);
    VL_IN8(&spi_sdio_i,0,0);
    VL_OUT8(&spi_sdio_o,0,0);
    VL_IN16(&mem_addr_i,11,0);
    VL_IN16(&prim_fifo_async_simple__02Ewdata_i,15,0);
    VL_OUT16(&prim_fifo_async_simple__02Erdata_o,15,0);
    VL_OUT16(&w_sram_addr_o,15,0);
    VL_OUT16(&r_sram_addr_o,15,0);
    VL_OUT16(&addr_o,11,0);
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
    VL_IN(&addr_i,31,0);
    VL_IN(&tlul_adapter_host__02Ewdata_i,31,0);
    VL_OUT(&tlul_adapter_host__02Erdata_o,31,0);
    VL_OUTW(&tlul_adapter_host__02Etl_o,108,0,4);
    VL_INW(&tlul_adapter_host__02Etl_i,65,0,3);
    VL_INW(&tlul_adapter_sram__02Etl_i,108,0,4);
    VL_OUTW(&tlul_adapter_sram__02Etl_o,65,0,3);
    VL_OUT(&wdata_o,31,0);
    VL_OUT(&wmask_o,31,0);
    VL_IN(&rdata_i,31,0);
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
    VL_INW(&spi_host__02Etl_i,108,0,4);
    VL_OUTW(&spi_host__02Etl_o,65,0,3);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vspi_host_tlul_fifo_sync__RCz6_RDz6* const __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d;
    Vspi_host_tlul_fifo_sync__RCz6_RDz6* const __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d;
    Vspi_host_tlul_fifo_sync__RCz6_RDz6* const __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d;
    Vspi_host_tlul_fifo_sync__RCz6_RDz6* const __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d;
    Vspi_host_tlul_fifo_sync__RCz6_RDz6* const __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo;
    Vspi_host_tlul_fifo_sync__RCz6_RDz6* const __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo;
    Vspi_host_tlul_fifo_sync__RCz6_RDz6* const __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo;
    Vspi_host_tlul_fifo_sync__RCz6_RDz6* const __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vspi_host___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vspi_host(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vspi_host(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vspi_host();
  private:
    VL_UNCOPYABLE(Vspi_host);  ///< Copying not allowed

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
