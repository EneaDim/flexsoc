// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vip1_tb.h for the primary calling header

#include "Vip1_tb__pch.h"

void Vip1_tb___024root___ctor_var_reset(Vip1_tb___024root* vlSelf);

Vip1_tb___024root::Vip1_tb___024root(Vip1_tb__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vip1_tb___024root___ctor_var_reset(this);
}

void Vip1_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vip1_tb___024root::~Vip1_tb___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
