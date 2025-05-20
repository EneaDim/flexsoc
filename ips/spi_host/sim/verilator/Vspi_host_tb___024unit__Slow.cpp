// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_host_tb.h for the primary calling header

#include "Vspi_host_tb__pch.h"
#include "Vspi_host_tb__Syms.h"
#include "Vspi_host_tb___024unit.h"

void Vspi_host_tb___024unit___ctor_var_reset(Vspi_host_tb___024unit* vlSelf);

Vspi_host_tb___024unit::Vspi_host_tb___024unit(Vspi_host_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vspi_host_tb___024unit___ctor_var_reset(this);
}

void Vspi_host_tb___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vspi_host_tb___024unit::~Vspi_host_tb___024unit() {
}
