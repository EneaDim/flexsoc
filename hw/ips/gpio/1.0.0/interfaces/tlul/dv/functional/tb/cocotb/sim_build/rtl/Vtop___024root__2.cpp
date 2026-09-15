// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vtop___024root___eval_triggers_vec__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vtop___024root___eval_act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers_vec__act(vlSelf);
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        {
            // Inlined CFunc: _timing_resume
            if ((0x0800000000000000ULL & vlSelfRef.__VactTriggered[0U])) {
                vlSelfRef.__VdlySched.resume();
            }
        }
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__inact(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__inact\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/gpio-tlul/runs/gpio/release/dv/functional/tb/cocotb/gpio_tb.sv", 2, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf);

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/gpio-tlul/runs/gpio/release/dv/functional/tb/cocotb/gpio_tb.sv", 2, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/gpio-tlul/runs/gpio/release/dv/functional/tb/cocotb/gpio_tb.sv", 2, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/gpio-tlul/runs/gpio/release/dv/functional/tb/cocotb/gpio_tb.sv", 2, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/gpio-tlul/runs/gpio/release/dv/functional/tb/cocotb/gpio_tb.sv", 2, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtop___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtop___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
