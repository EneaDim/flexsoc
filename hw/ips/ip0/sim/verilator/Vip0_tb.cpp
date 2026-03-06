// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vip0_tb__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vip0_tb::Vip0_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vip0_tb__Syms(contextp(), _vcname__, this)}
    , ip0_tb{vlSymsp->TOP.ip0_tb}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , __PVT__ip0_reg_pkg{vlSymsp->TOP.__PVT__ip0_reg_pkg}
    , __024unit__03a__03atlul_utils__Vclpkg{vlSymsp->TOP.__024unit__03a__03atlul_utils__Vclpkg}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vip0_tb::Vip0_tb(const char* _vcname__)
    : Vip0_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vip0_tb::~Vip0_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vip0_tb___024root___eval_debug_assertions(Vip0_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vip0_tb___024root___eval_static(Vip0_tb___024root* vlSelf);
void Vip0_tb___024root___eval_initial(Vip0_tb___024root* vlSelf);
void Vip0_tb___024root___eval_settle(Vip0_tb___024root* vlSelf);
void Vip0_tb___024root___eval(Vip0_tb___024root* vlSelf);

void Vip0_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vip0_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vip0_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vip0_tb___024root___eval_static(&(vlSymsp->TOP));
        Vip0_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vip0_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vip0_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vip0_tb::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vip0_tb::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vip0_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vip0_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vip0_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vip0_tb___024root___eval_final(Vip0_tb___024root* vlSelf);

VL_ATTR_COLD void Vip0_tb::final() {
    Vip0_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vip0_tb::hierName() const { return vlSymsp->name(); }
const char* Vip0_tb::modelName() const { return "Vip0_tb"; }
unsigned Vip0_tb::threads() const { return 1; }
void Vip0_tb::prepareClone() const { contextp()->prepareClone(); }
void Vip0_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vip0_tb::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vip0_tb___024root__trace_decl_types(VerilatedVcd* tracep);

void Vip0_tb___024root__trace_init_top(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vip0_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vip0_tb___024root*>(voidSelf);
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vip0_tb___024root__trace_decl_types(tracep);
    Vip0_tb___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vip0_tb___024root__trace_register(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vip0_tb::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vip0_tb::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vip0_tb___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
