// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmy_ip_tb.h for the primary calling header

#include "Vmy_ip_tb__pch.h"

void Vmy_ip_tb___024unit___ctor_var_reset(Vmy_ip_tb___024unit* vlSelf);

void Vmy_ip_tb___024unit::ctor(Vmy_ip_tb__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vmy_ip_tb___024unit___ctor_var_reset(this);
}

void Vmy_ip_tb___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vmy_ip_tb___024unit::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
