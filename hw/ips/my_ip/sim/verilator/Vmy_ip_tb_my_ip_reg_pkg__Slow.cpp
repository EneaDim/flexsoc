// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmy_ip_tb.h for the primary calling header

#include "Vmy_ip_tb__pch.h"

// Parameter definitions for Vmy_ip_tb_my_ip_reg_pkg
constexpr VlUnpacked<CData/*3:0*/, 4> Vmy_ip_tb_my_ip_reg_pkg::__PVT__MY_IP_PERMIT;


void Vmy_ip_tb_my_ip_reg_pkg___ctor_var_reset(Vmy_ip_tb_my_ip_reg_pkg* vlSelf);

void Vmy_ip_tb_my_ip_reg_pkg::ctor(Vmy_ip_tb__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vmy_ip_tb_my_ip_reg_pkg___ctor_var_reset(this);
}

void Vmy_ip_tb_my_ip_reg_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vmy_ip_tb_my_ip_reg_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
