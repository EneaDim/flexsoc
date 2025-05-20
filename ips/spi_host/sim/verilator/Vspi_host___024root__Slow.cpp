// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_host.h for the primary calling header

#include "Vspi_host__pch.h"
#include "Vspi_host__Syms.h"
#include "Vspi_host___024root.h"

void Vspi_host___024root___ctor_var_reset(Vspi_host___024root* vlSelf);

Vspi_host___024root::Vspi_host___024root(Vspi_host__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vspi_host___024root___ctor_var_reset(this);
}

void Vspi_host___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vspi_host___024root::~Vspi_host___024root() {
}
