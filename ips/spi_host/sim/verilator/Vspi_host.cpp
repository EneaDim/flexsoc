// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vspi_host__pch.h"

//============================================================
// Constructors

Vspi_host::Vspi_host(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vspi_host__Syms(contextp(), _vcname__, this)}
    , prim_fifo_async_simple__02Eclk_wr_i{vlSymsp->TOP.prim_fifo_async_simple__02Eclk_wr_i}
    , prim_fifo_async_simple__02Erst_wr_ni{vlSymsp->TOP.prim_fifo_async_simple__02Erst_wr_ni}
    , prim_fifo_async_simple__02Eclk_rd_i{vlSymsp->TOP.prim_fifo_async_simple__02Eclk_rd_i}
    , prim_fifo_async_simple__02Erst_rd_ni{vlSymsp->TOP.prim_fifo_async_simple__02Erst_rd_ni}
    , prim_fifo_async_sram_adapter__02Eclk_wr_i{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Eclk_wr_i}
    , prim_fifo_async_sram_adapter__02Erst_wr_ni{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Erst_wr_ni}
    , prim_fifo_async_sram_adapter__02Eclk_rd_i{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Eclk_rd_i}
    , prim_fifo_async_sram_adapter__02Erst_rd_ni{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Erst_rd_ni}
    , prim_filter__02Eclk_i{vlSymsp->TOP.prim_filter__02Eclk_i}
    , prim_filter__02Erst_ni{vlSymsp->TOP.prim_filter__02Erst_ni}
    , prim_filter_ctr__02Eclk_i{vlSymsp->TOP.prim_filter_ctr__02Eclk_i}
    , prim_filter_ctr__02Erst_ni{vlSymsp->TOP.prim_filter_ctr__02Erst_ni}
    , tlul_adapter_host__02Eclk_i{vlSymsp->TOP.tlul_adapter_host__02Eclk_i}
    , tlul_adapter_host__02Erst_ni{vlSymsp->TOP.tlul_adapter_host__02Erst_ni}
    , tlul_adapter_sram__02Eclk_i{vlSymsp->TOP.tlul_adapter_sram__02Eclk_i}
    , tlul_adapter_sram__02Erst_ni{vlSymsp->TOP.tlul_adapter_sram__02Erst_ni}
    , tlul_assert_multiple__02Eclk_i{vlSymsp->TOP.tlul_assert_multiple__02Eclk_i}
    , tlul_assert_multiple__02Erst_ni{vlSymsp->TOP.tlul_assert_multiple__02Erst_ni}
    , clk_h_i{vlSymsp->TOP.clk_h_i}
    , rst_h_ni{vlSymsp->TOP.rst_h_ni}
    , clk_d_i{vlSymsp->TOP.clk_d_i}
    , rst_d_ni{vlSymsp->TOP.rst_d_ni}
    , tlul_socket_1n__02Eclk_i{vlSymsp->TOP.tlul_socket_1n__02Eclk_i}
    , tlul_socket_1n__02Erst_ni{vlSymsp->TOP.tlul_socket_1n__02Erst_ni}
    , tlul_socket_m1__02Eclk_i{vlSymsp->TOP.tlul_socket_m1__02Eclk_i}
    , tlul_socket_m1__02Erst_ni{vlSymsp->TOP.tlul_socket_m1__02Erst_ni}
    , spi_host__02Eclk_i{vlSymsp->TOP.spi_host__02Eclk_i}
    , spi_host__02Erst_ni{vlSymsp->TOP.spi_host__02Erst_ni}
    , prim_cdc_rand_delay__02Eclk_i{vlSymsp->TOP.prim_cdc_rand_delay__02Eclk_i}
    , prim_cdc_rand_delay__02Erst_ni{vlSymsp->TOP.prim_cdc_rand_delay__02Erst_ni}
    , prev_data_i{vlSymsp->TOP.prev_data_i}
    , src_data_i{vlSymsp->TOP.src_data_i}
    , dst_data_o{vlSymsp->TOP.dst_data_o}
    , sram2tlul__02Eclk_i{vlSymsp->TOP.sram2tlul__02Eclk_i}
    , sram2tlul__02Erst_ni{vlSymsp->TOP.sram2tlul__02Erst_ni}
    , mem_req_i{vlSymsp->TOP.mem_req_i}
    , mem_write_i{vlSymsp->TOP.mem_write_i}
    , mem_rvalid_o{vlSymsp->TOP.mem_rvalid_o}
    , mem_error_o{vlSymsp->TOP.mem_error_o}
    , prim_fifo_async_simple__02Ewvalid_i{vlSymsp->TOP.prim_fifo_async_simple__02Ewvalid_i}
    , prim_fifo_async_simple__02Ewready_o{vlSymsp->TOP.prim_fifo_async_simple__02Ewready_o}
    , prim_fifo_async_simple__02Ervalid_o{vlSymsp->TOP.prim_fifo_async_simple__02Ervalid_o}
    , prim_fifo_async_simple__02Erready_i{vlSymsp->TOP.prim_fifo_async_simple__02Erready_i}
    , prim_fifo_async_sram_adapter__02Ewvalid_i{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Ewvalid_i}
    , prim_fifo_async_sram_adapter__02Ewready_o{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Ewready_o}
    , wdepth_o{vlSymsp->TOP.wdepth_o}
    , prim_fifo_async_sram_adapter__02Ervalid_o{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Ervalid_o}
    , prim_fifo_async_sram_adapter__02Erready_i{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Erready_i}
    , rdepth_o{vlSymsp->TOP.rdepth_o}
    , r_full_o{vlSymsp->TOP.r_full_o}
    , r_notempty_o{vlSymsp->TOP.r_notempty_o}
    , w_full_o{vlSymsp->TOP.w_full_o}
    , w_sram_req_o{vlSymsp->TOP.w_sram_req_o}
    , w_sram_gnt_i{vlSymsp->TOP.w_sram_gnt_i}
    , w_sram_write_o{vlSymsp->TOP.w_sram_write_o}
    , w_sram_rvalid_i{vlSymsp->TOP.w_sram_rvalid_i}
    , w_sram_rerror_i{vlSymsp->TOP.w_sram_rerror_i}
    , r_sram_req_o{vlSymsp->TOP.r_sram_req_o}
    , r_sram_gnt_i{vlSymsp->TOP.r_sram_gnt_i}
    , r_sram_write_o{vlSymsp->TOP.r_sram_write_o}
    , r_sram_rvalid_i{vlSymsp->TOP.r_sram_rvalid_i}
    , r_sram_rerror_i{vlSymsp->TOP.r_sram_rerror_i}
    , prim_filter__02Eenable_i{vlSymsp->TOP.prim_filter__02Eenable_i}
    , prim_filter__02Efilter_i{vlSymsp->TOP.prim_filter__02Efilter_i}
    , prim_filter__02Efilter_o{vlSymsp->TOP.prim_filter__02Efilter_o}
    , prim_filter_ctr__02Eenable_i{vlSymsp->TOP.prim_filter_ctr__02Eenable_i}
    , prim_filter_ctr__02Efilter_i{vlSymsp->TOP.prim_filter_ctr__02Efilter_i}
    , thresh_i{vlSymsp->TOP.thresh_i}
    , prim_filter_ctr__02Efilter_o{vlSymsp->TOP.prim_filter_ctr__02Efilter_o}
    , req_i{vlSymsp->TOP.req_i}
    , gnt_o{vlSymsp->TOP.gnt_o}
    , we_i{vlSymsp->TOP.we_i}
    , wdata_intg_i{vlSymsp->TOP.wdata_intg_i}
    , be_i{vlSymsp->TOP.be_i}
    , instr_type_i{vlSymsp->TOP.instr_type_i}
    , valid_o{vlSymsp->TOP.valid_o}
    , rdata_intg_o{vlSymsp->TOP.rdata_intg_o}
    , err_o{vlSymsp->TOP.err_o}
    , intg_err_o{vlSymsp->TOP.intg_err_o}
    , en_ifetch_i{vlSymsp->TOP.en_ifetch_i}
    , req_o{vlSymsp->TOP.req_o}
    , req_type_o{vlSymsp->TOP.req_type_o}
    , gnt_i{vlSymsp->TOP.gnt_i}
    , we_o{vlSymsp->TOP.we_o}
    , intg_error_o{vlSymsp->TOP.intg_error_o}
    , rvalid_i{vlSymsp->TOP.rvalid_i}
    , rerror_i{vlSymsp->TOP.rerror_i}
    , compound_txn_in_progress_o{vlSymsp->TOP.compound_txn_in_progress_o}
    , readback_en_i{vlSymsp->TOP.readback_en_i}
    , readback_error_o{vlSymsp->TOP.readback_error_o}
    , wr_collision_i{vlSymsp->TOP.wr_collision_i}
    , write_pending_i{vlSymsp->TOP.write_pending_i}
    , dev_select_i{vlSymsp->TOP.dev_select_i}
    , spi_cs_o{vlSymsp->TOP.spi_cs_o}
    , spi_sclk_o{vlSymsp->TOP.spi_sclk_o}
    , spi_sdioz_o{vlSymsp->TOP.spi_sdioz_o}
    , spi_sdio_i{vlSymsp->TOP.spi_sdio_i}
    , spi_sdio_o{vlSymsp->TOP.spi_sdio_o}
    , mem_addr_i{vlSymsp->TOP.mem_addr_i}
    , prim_fifo_async_simple__02Ewdata_i{vlSymsp->TOP.prim_fifo_async_simple__02Ewdata_i}
    , prim_fifo_async_simple__02Erdata_o{vlSymsp->TOP.prim_fifo_async_simple__02Erdata_o}
    , w_sram_addr_o{vlSymsp->TOP.w_sram_addr_o}
    , r_sram_addr_o{vlSymsp->TOP.r_sram_addr_o}
    , addr_o{vlSymsp->TOP.addr_o}
    , sram2tlul__02Etl_o{vlSymsp->TOP.sram2tlul__02Etl_o}
    , sram2tlul__02Etl_i{vlSymsp->TOP.sram2tlul__02Etl_i}
    , mem_wdata_i{vlSymsp->TOP.mem_wdata_i}
    , mem_rdata_o{vlSymsp->TOP.mem_rdata_o}
    , prim_fifo_async_sram_adapter__02Ewdata_i{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Ewdata_i}
    , prim_fifo_async_sram_adapter__02Erdata_o{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Erdata_o}
    , w_sram_wdata_o{vlSymsp->TOP.w_sram_wdata_o}
    , w_sram_wmask_o{vlSymsp->TOP.w_sram_wmask_o}
    , w_sram_rdata_i{vlSymsp->TOP.w_sram_rdata_i}
    , r_sram_wdata_o{vlSymsp->TOP.r_sram_wdata_o}
    , r_sram_wmask_o{vlSymsp->TOP.r_sram_wmask_o}
    , r_sram_rdata_i{vlSymsp->TOP.r_sram_rdata_i}
    , addr_i{vlSymsp->TOP.addr_i}
    , tlul_adapter_host__02Ewdata_i{vlSymsp->TOP.tlul_adapter_host__02Ewdata_i}
    , tlul_adapter_host__02Erdata_o{vlSymsp->TOP.tlul_adapter_host__02Erdata_o}
    , tlul_adapter_host__02Etl_o{vlSymsp->TOP.tlul_adapter_host__02Etl_o}
    , tlul_adapter_host__02Etl_i{vlSymsp->TOP.tlul_adapter_host__02Etl_i}
    , tlul_adapter_sram__02Etl_i{vlSymsp->TOP.tlul_adapter_sram__02Etl_i}
    , tlul_adapter_sram__02Etl_o{vlSymsp->TOP.tlul_adapter_sram__02Etl_o}
    , wdata_o{vlSymsp->TOP.wdata_o}
    , wmask_o{vlSymsp->TOP.wmask_o}
    , rdata_i{vlSymsp->TOP.rdata_i}
    , h2d{vlSymsp->TOP.h2d}
    , d2h{vlSymsp->TOP.d2h}
    , tlul_fifo_async__02Etl_h_i{vlSymsp->TOP.tlul_fifo_async__02Etl_h_i}
    , tlul_fifo_async__02Etl_h_o{vlSymsp->TOP.tlul_fifo_async__02Etl_h_o}
    , tlul_fifo_async__02Etl_d_o{vlSymsp->TOP.tlul_fifo_async__02Etl_d_o}
    , tlul_fifo_async__02Etl_d_i{vlSymsp->TOP.tlul_fifo_async__02Etl_d_i}
    , tlul_socket_1n__02Etl_h_i{vlSymsp->TOP.tlul_socket_1n__02Etl_h_i}
    , tlul_socket_1n__02Etl_h_o{vlSymsp->TOP.tlul_socket_1n__02Etl_h_o}
    , tlul_socket_1n__02Etl_d_o{vlSymsp->TOP.tlul_socket_1n__02Etl_d_o}
    , tlul_socket_1n__02Etl_d_i{vlSymsp->TOP.tlul_socket_1n__02Etl_d_i}
    , tlul_socket_m1__02Etl_h_i{vlSymsp->TOP.tlul_socket_m1__02Etl_h_i}
    , tlul_socket_m1__02Etl_h_o{vlSymsp->TOP.tlul_socket_m1__02Etl_h_o}
    , tlul_socket_m1__02Etl_d_o{vlSymsp->TOP.tlul_socket_m1__02Etl_d_o}
    , tlul_socket_m1__02Etl_d_i{vlSymsp->TOP.tlul_socket_m1__02Etl_d_i}
    , spi_host__02Etl_i{vlSymsp->TOP.spi_host__02Etl_i}
    , spi_host__02Etl_o{vlSymsp->TOP.spi_host__02Etl_o}
    , __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d{vlSymsp->TOP.__PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d}
    , __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d{vlSymsp->TOP.__PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d}
    , __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d{vlSymsp->TOP.__PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d}
    , __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d{vlSymsp->TOP.__PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d}
    , __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo{vlSymsp->TOP.__PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo}
    , __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo{vlSymsp->TOP.__PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo}
    , __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo{vlSymsp->TOP.__PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo}
    , __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo{vlSymsp->TOP.__PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vspi_host::Vspi_host(const char* _vcname__)
    : Vspi_host(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vspi_host::~Vspi_host() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vspi_host___024root___eval_debug_assertions(Vspi_host___024root* vlSelf);
#endif  // VL_DEBUG
void Vspi_host___024root___eval_static(Vspi_host___024root* vlSelf);
void Vspi_host___024root___eval_initial(Vspi_host___024root* vlSelf);
void Vspi_host___024root___eval_settle(Vspi_host___024root* vlSelf);
void Vspi_host___024root___eval(Vspi_host___024root* vlSelf);

void Vspi_host::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vspi_host::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vspi_host___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vspi_host___024root___eval_static(&(vlSymsp->TOP));
        Vspi_host___024root___eval_initial(&(vlSymsp->TOP));
        Vspi_host___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vspi_host___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vspi_host::eventsPending() { return false; }

uint64_t Vspi_host::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vspi_host::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vspi_host___024root___eval_final(Vspi_host___024root* vlSelf);

VL_ATTR_COLD void Vspi_host::final() {
    Vspi_host___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vspi_host::hierName() const { return vlSymsp->name(); }
const char* Vspi_host::modelName() const { return "Vspi_host"; }
unsigned Vspi_host::threads() const { return 1; }
void Vspi_host::prepareClone() const { contextp()->prepareClone(); }
void Vspi_host::atClone() const {
    contextp()->threadPoolpOnClone();
}
