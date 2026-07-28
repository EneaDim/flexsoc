// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_prim_alert_pkg
constexpr CData/*1:0*/ Vtop_prim_alert_pkg::ALERT_TX_DEFAULT;
constexpr CData/*3:0*/ Vtop_prim_alert_pkg::ALERT_RX_DEFAULT;


void Vtop_prim_alert_pkg___ctor_var_reset(Vtop_prim_alert_pkg* vlSelf);

void Vtop_prim_alert_pkg::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_prim_alert_pkg___ctor_var_reset(this);
}

void Vtop_prim_alert_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_prim_alert_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
