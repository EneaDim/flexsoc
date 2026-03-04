// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_pkg.h for the primary calling header

#include "Vtop_pkg__pch.h"

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ctor_var_reset(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9::ctor(Vtop_pkg__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ctor_var_reset(this);
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
