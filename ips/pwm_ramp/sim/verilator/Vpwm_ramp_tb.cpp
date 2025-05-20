// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpwm_ramp_tb__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vpwm_ramp_tb::Vpwm_ramp_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vpwm_ramp_tb__Syms(contextp(), _vcname__, this)}
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
    , prim_subreg__02Eclk_i{vlSymsp->TOP.prim_subreg__02Eclk_i}
    , prim_subreg__02Erst_ni{vlSymsp->TOP.prim_subreg__02Erst_ni}
    , tlul_adapter_host__02Eclk_i{vlSymsp->TOP.tlul_adapter_host__02Eclk_i}
    , tlul_adapter_host__02Erst_ni{vlSymsp->TOP.tlul_adapter_host__02Erst_ni}
    , tlul_adapter_reg__02Eclk_i{vlSymsp->TOP.tlul_adapter_reg__02Eclk_i}
    , tlul_adapter_reg__02Erst_ni{vlSymsp->TOP.tlul_adapter_reg__02Erst_ni}
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
    , multiple_pwm_ramp__02Eclk_i{vlSymsp->TOP.multiple_pwm_ramp__02Eclk_i}
    , multiple_pwm_ramp__02Erst_ni{vlSymsp->TOP.multiple_pwm_ramp__02Erst_ni}
    , prim_cdc_rand_delay__02Eclk_i{vlSymsp->TOP.prim_cdc_rand_delay__02Eclk_i}
    , prim_cdc_rand_delay__02Erst_ni{vlSymsp->TOP.prim_cdc_rand_delay__02Erst_ni}
    , prev_data_i{vlSymsp->TOP.prev_data_i}
    , src_data_i{vlSymsp->TOP.src_data_i}
    , dst_data_o{vlSymsp->TOP.dst_data_o}
    , re{vlSymsp->TOP.re}
    , prim_subreg_ext__02Ewe{vlSymsp->TOP.prim_subreg_ext__02Ewe}
    , prim_subreg_ext__02Eqe{vlSymsp->TOP.prim_subreg_ext__02Eqe}
    , qre{vlSymsp->TOP.qre}
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
    , prim_subreg__02Ewe{vlSymsp->TOP.prim_subreg__02Ewe}
    , de{vlSymsp->TOP.de}
    , prim_subreg__02Eqe{vlSymsp->TOP.prim_subreg__02Eqe}
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
    , tlul_adapter_reg__02Een_ifetch_i{vlSymsp->TOP.tlul_adapter_reg__02Een_ifetch_i}
    , tlul_adapter_reg__02Eintg_error_o{vlSymsp->TOP.tlul_adapter_reg__02Eintg_error_o}
    , re_o{vlSymsp->TOP.re_o}
    , tlul_adapter_reg__02Ewe_o{vlSymsp->TOP.tlul_adapter_reg__02Ewe_o}
    , tlul_adapter_reg__02Eaddr_o{vlSymsp->TOP.tlul_adapter_reg__02Eaddr_o}
    , be_o{vlSymsp->TOP.be_o}
    , busy_i{vlSymsp->TOP.busy_i}
    , error_i{vlSymsp->TOP.error_i}
    , tlul_adapter_sram__02Een_ifetch_i{vlSymsp->TOP.tlul_adapter_sram__02Een_ifetch_i}
    , req_o{vlSymsp->TOP.req_o}
    , req_type_o{vlSymsp->TOP.req_type_o}
    , gnt_i{vlSymsp->TOP.gnt_i}
    , tlul_adapter_sram__02Ewe_o{vlSymsp->TOP.tlul_adapter_sram__02Ewe_o}
    , tlul_adapter_sram__02Eintg_error_o{vlSymsp->TOP.tlul_adapter_sram__02Eintg_error_o}
    , rvalid_i{vlSymsp->TOP.rvalid_i}
    , rerror_i{vlSymsp->TOP.rerror_i}
    , compound_txn_in_progress_o{vlSymsp->TOP.compound_txn_in_progress_o}
    , readback_en_i{vlSymsp->TOP.readback_en_i}
    , readback_error_o{vlSymsp->TOP.readback_error_o}
    , wr_collision_i{vlSymsp->TOP.wr_collision_i}
    , write_pending_i{vlSymsp->TOP.write_pending_i}
    , dev_select_i{vlSymsp->TOP.dev_select_i}
    , multiple_pwm_ramp__02Eenable_i{vlSymsp->TOP.multiple_pwm_ramp__02Eenable_i}
    , step_i{vlSymsp->TOP.step_i}
    , lvds_0_i{vlSymsp->TOP.lvds_0_i}
    , lvds_1_i{vlSymsp->TOP.lvds_1_i}
    , pwm_0_o{vlSymsp->TOP.pwm_0_o}
    , pwm_1_o{vlSymsp->TOP.pwm_1_o}
    , adc_value_o{vlSymsp->TOP.adc_value_o}
    , adc_valid_o{vlSymsp->TOP.adc_valid_o}
    , mem_addr_i{vlSymsp->TOP.mem_addr_i}
    , prim_fifo_async_simple__02Ewdata_i{vlSymsp->TOP.prim_fifo_async_simple__02Ewdata_i}
    , prim_fifo_async_simple__02Erdata_o{vlSymsp->TOP.prim_fifo_async_simple__02Erdata_o}
    , w_sram_addr_o{vlSymsp->TOP.w_sram_addr_o}
    , r_sram_addr_o{vlSymsp->TOP.r_sram_addr_o}
    , tlul_adapter_sram__02Eaddr_o{vlSymsp->TOP.tlul_adapter_sram__02Eaddr_o}
    , prim_subreg_ext__02Ewd{vlSymsp->TOP.prim_subreg_ext__02Ewd}
    , prim_subreg_ext__02Ed{vlSymsp->TOP.prim_subreg_ext__02Ed}
    , prim_subreg_ext__02Eq{vlSymsp->TOP.prim_subreg_ext__02Eq}
    , prim_subreg_ext__02Eds{vlSymsp->TOP.prim_subreg_ext__02Eds}
    , prim_subreg_ext__02Eqs{vlSymsp->TOP.prim_subreg_ext__02Eqs}
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
    , prim_subreg__02Ewd{vlSymsp->TOP.prim_subreg__02Ewd}
    , prim_subreg__02Ed{vlSymsp->TOP.prim_subreg__02Ed}
    , prim_subreg__02Eq{vlSymsp->TOP.prim_subreg__02Eq}
    , prim_subreg__02Eds{vlSymsp->TOP.prim_subreg__02Eds}
    , prim_subreg__02Eqs{vlSymsp->TOP.prim_subreg__02Eqs}
    , addr_i{vlSymsp->TOP.addr_i}
    , tlul_adapter_host__02Ewdata_i{vlSymsp->TOP.tlul_adapter_host__02Ewdata_i}
    , tlul_adapter_host__02Erdata_o{vlSymsp->TOP.tlul_adapter_host__02Erdata_o}
    , tlul_adapter_host__02Etl_o{vlSymsp->TOP.tlul_adapter_host__02Etl_o}
    , tlul_adapter_host__02Etl_i{vlSymsp->TOP.tlul_adapter_host__02Etl_i}
    , tlul_adapter_reg__02Etl_i{vlSymsp->TOP.tlul_adapter_reg__02Etl_i}
    , tlul_adapter_reg__02Etl_o{vlSymsp->TOP.tlul_adapter_reg__02Etl_o}
    , tlul_adapter_reg__02Ewdata_o{vlSymsp->TOP.tlul_adapter_reg__02Ewdata_o}
    , tlul_adapter_reg__02Erdata_i{vlSymsp->TOP.tlul_adapter_reg__02Erdata_i}
    , tlul_adapter_sram__02Etl_i{vlSymsp->TOP.tlul_adapter_sram__02Etl_i}
    , tlul_adapter_sram__02Etl_o{vlSymsp->TOP.tlul_adapter_sram__02Etl_o}
    , tlul_adapter_sram__02Ewdata_o{vlSymsp->TOP.tlul_adapter_sram__02Ewdata_o}
    , wmask_o{vlSymsp->TOP.wmask_o}
    , tlul_adapter_sram__02Erdata_i{vlSymsp->TOP.tlul_adapter_sram__02Erdata_i}
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
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vpwm_ramp_tb::Vpwm_ramp_tb(const char* _vcname__)
    : Vpwm_ramp_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vpwm_ramp_tb::~Vpwm_ramp_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vpwm_ramp_tb___024root___eval_debug_assertions(Vpwm_ramp_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vpwm_ramp_tb___024root___eval_static(Vpwm_ramp_tb___024root* vlSelf);
void Vpwm_ramp_tb___024root___eval_initial(Vpwm_ramp_tb___024root* vlSelf);
void Vpwm_ramp_tb___024root___eval_settle(Vpwm_ramp_tb___024root* vlSelf);
void Vpwm_ramp_tb___024root___eval(Vpwm_ramp_tb___024root* vlSelf);

void Vpwm_ramp_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpwm_ramp_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vpwm_ramp_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vpwm_ramp_tb___024root___eval_static(&(vlSymsp->TOP));
        Vpwm_ramp_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vpwm_ramp_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vpwm_ramp_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vpwm_ramp_tb::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vpwm_ramp_tb::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vpwm_ramp_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vpwm_ramp_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vpwm_ramp_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vpwm_ramp_tb___024root___eval_final(Vpwm_ramp_tb___024root* vlSelf);

VL_ATTR_COLD void Vpwm_ramp_tb::final() {
    Vpwm_ramp_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpwm_ramp_tb::hierName() const { return vlSymsp->name(); }
const char* Vpwm_ramp_tb::modelName() const { return "Vpwm_ramp_tb"; }
unsigned Vpwm_ramp_tb::threads() const { return 1; }
void Vpwm_ramp_tb::prepareClone() const { contextp()->prepareClone(); }
void Vpwm_ramp_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vpwm_ramp_tb::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vpwm_ramp_tb___024root__trace_decl_types(VerilatedVcd* tracep);

void Vpwm_ramp_tb___024root__trace_init_top(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vpwm_ramp_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpwm_ramp_tb___024root*>(voidSelf);
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vpwm_ramp_tb___024root__trace_decl_types(tracep);
    Vpwm_ramp_tb___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_register(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vpwm_ramp_tb::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vpwm_ramp_tb::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vpwm_ramp_tb___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
