// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpwm_ramp_tb.h for the primary calling header

#include "Vpwm_ramp_tb__pch.h"
#include "Vpwm_ramp_tb__Syms.h"
#include "Vpwm_ramp_tb___024root.h"

void Vpwm_ramp_tb___024root___ctor_var_reset(Vpwm_ramp_tb___024root* vlSelf);

Vpwm_ramp_tb___024root::Vpwm_ramp_tb___024root(Vpwm_ramp_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vpwm_ramp_tb___024root___ctor_var_reset(this);
}

void Vpwm_ramp_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vpwm_ramp_tb___024root::~Vpwm_ramp_tb___024root() {
}
