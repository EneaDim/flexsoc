// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vip1_tb.h for the primary calling header

#include "Vip1_tb__pch.h"

// Parameter definitions for Vip1_tb_ip1_reg_pkg
constexpr VlUnpacked<CData/*3:0*/, 4> Vip1_tb_ip1_reg_pkg::__PVT__IP1_PERMIT;


void Vip1_tb_ip1_reg_pkg___ctor_var_reset(Vip1_tb_ip1_reg_pkg* vlSelf);

void Vip1_tb_ip1_reg_pkg::ctor(Vip1_tb__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vip1_tb_ip1_reg_pkg___ctor_var_reset(this);
}

void Vip1_tb_ip1_reg_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vip1_tb_ip1_reg_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
