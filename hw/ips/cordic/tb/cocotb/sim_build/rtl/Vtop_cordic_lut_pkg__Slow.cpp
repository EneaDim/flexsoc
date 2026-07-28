// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_cordic_lut_pkg
constexpr SData/*15:0*/ Vtop_cordic_lut_pkg::PI_Q;
constexpr SData/*15:0*/ Vtop_cordic_lut_pkg::HALF_PI_Q;
constexpr VlUnpacked<SData/*15:0*/, 16> Vtop_cordic_lut_pkg::AtanLut;


void Vtop_cordic_lut_pkg___ctor_var_reset(Vtop_cordic_lut_pkg* vlSelf);

void Vtop_cordic_lut_pkg::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_cordic_lut_pkg___ctor_var_reset(this);
}

void Vtop_cordic_lut_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_cordic_lut_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
