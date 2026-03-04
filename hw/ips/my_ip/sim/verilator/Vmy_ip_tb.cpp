// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmy_ip_tb__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vmy_ip_tb::Vmy_ip_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmy_ip_tb__Syms(contextp(), _vcname__, this)}
    , my_ip_tb{vlSymsp->TOP.my_ip_tb}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , __PVT__my_ip_reg_pkg{vlSymsp->TOP.__PVT__my_ip_reg_pkg}
    , __024unit__03a__03atlul_utils__Vclpkg{vlSymsp->TOP.__024unit__03a__03atlul_utils__Vclpkg}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vmy_ip_tb::Vmy_ip_tb(const char* _vcname__)
    : Vmy_ip_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmy_ip_tb::~Vmy_ip_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmy_ip_tb___024root___eval_debug_assertions(Vmy_ip_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vmy_ip_tb___024root___eval_static(Vmy_ip_tb___024root* vlSelf);
void Vmy_ip_tb___024root___eval_initial(Vmy_ip_tb___024root* vlSelf);
void Vmy_ip_tb___024root___eval_settle(Vmy_ip_tb___024root* vlSelf);
void Vmy_ip_tb___024root___eval(Vmy_ip_tb___024root* vlSelf);

void Vmy_ip_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmy_ip_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmy_ip_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmy_ip_tb___024root___eval_static(&(vlSymsp->TOP));
        Vmy_ip_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vmy_ip_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmy_ip_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vmy_ip_tb::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vmy_ip_tb::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vmy_ip_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vmy_ip_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vmy_ip_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmy_ip_tb___024root___eval_final(Vmy_ip_tb___024root* vlSelf);

VL_ATTR_COLD void Vmy_ip_tb::final() {
    Vmy_ip_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmy_ip_tb::hierName() const { return vlSymsp->name(); }
const char* Vmy_ip_tb::modelName() const { return "Vmy_ip_tb"; }
unsigned Vmy_ip_tb::threads() const { return 1; }
void Vmy_ip_tb::prepareClone() const { contextp()->prepareClone(); }
void Vmy_ip_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vmy_ip_tb::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vmy_ip_tb___024root__trace_decl_types(VerilatedVcd* tracep);

void Vmy_ip_tb___024root__trace_init_top(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmy_ip_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmy_ip_tb___024root*>(voidSelf);
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vmy_ip_tb___024root__trace_decl_types(tracep);
    Vmy_ip_tb___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_register(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmy_ip_tb::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmy_ip_tb::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmy_ip_tb___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
