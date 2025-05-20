// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_host_tb.h for the primary calling header

#include "Vspi_host_tb__pch.h"
#include "Vspi_host_tb__Syms.h"
#include "Vspi_host_tb___024root.h"

void Vspi_host_tb___024root___ctor_var_reset(Vspi_host_tb___024root* vlSelf);

Vspi_host_tb___024root::Vspi_host_tb___024root(Vspi_host_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vspi_host_tb___024root___ctor_var_reset(this);
}

void Vspi_host_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vspi_host_tb___024root::~Vspi_host_tb___024root() {
}
