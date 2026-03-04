// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_pkg.h for the primary calling header

#include "Vtop_pkg__pch.h"

void Vtop_pkg___024root___ctor_var_reset(Vtop_pkg___024root* vlSelf);

Vtop_pkg___024root::Vtop_pkg___024root(Vtop_pkg__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtop_pkg___024root___ctor_var_reset(this);
}

void Vtop_pkg___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_pkg___024root::~Vtop_pkg___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
