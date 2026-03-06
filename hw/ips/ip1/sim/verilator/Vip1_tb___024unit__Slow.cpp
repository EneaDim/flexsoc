// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vip1_tb.h for the primary calling header

#include "Vip1_tb__pch.h"

void Vip1_tb___024unit___ctor_var_reset(Vip1_tb___024unit* vlSelf);

void Vip1_tb___024unit::ctor(Vip1_tb__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vip1_tb___024unit___ctor_var_reset(this);
}

void Vip1_tb___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vip1_tb___024unit::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
