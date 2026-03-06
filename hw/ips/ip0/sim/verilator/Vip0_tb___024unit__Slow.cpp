// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vip0_tb.h for the primary calling header

#include "Vip0_tb__pch.h"

void Vip0_tb___024unit___ctor_var_reset(Vip0_tb___024unit* vlSelf);

void Vip0_tb___024unit::ctor(Vip0_tb__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vip0_tb___024unit___ctor_var_reset(this);
}

void Vip0_tb___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vip0_tb___024unit::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
