// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vip0_tb.h for the primary calling header

#include "Vip0_tb__pch.h"

// Parameter definitions for Vip0_tb_ip0_reg_pkg
constexpr VlUnpacked<CData/*3:0*/, 4> Vip0_tb_ip0_reg_pkg::__PVT__IP0_PERMIT;


void Vip0_tb_ip0_reg_pkg___ctor_var_reset(Vip0_tb_ip0_reg_pkg* vlSelf);

void Vip0_tb_ip0_reg_pkg::ctor(Vip0_tb__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vip0_tb_ip0_reg_pkg___ctor_var_reset(this);
}

void Vip0_tb_ip0_reg_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vip0_tb_ip0_reg_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
