// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vip0_tb.h for the primary calling header

#include "Vip0_tb__pch.h"

void Vip0_tb___024root___ctor_var_reset(Vip0_tb___024root* vlSelf);

Vip0_tb___024root::Vip0_tb___024root(Vip0_tb__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vip0_tb___024root___ctor_var_reset(this);
}

void Vip0_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vip0_tb___024root::~Vip0_tb___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
