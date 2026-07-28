// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_prim_mubi_pkg
constexpr IData/*31:0*/ Vtop_prim_mubi_pkg::MuBi4Width;
constexpr IData/*31:0*/ Vtop_prim_mubi_pkg::MuBi8Width;
constexpr IData/*31:0*/ Vtop_prim_mubi_pkg::MuBi12Width;
constexpr IData/*31:0*/ Vtop_prim_mubi_pkg::MuBi16Width;
constexpr IData/*31:0*/ Vtop_prim_mubi_pkg::MuBi20Width;
constexpr IData/*31:0*/ Vtop_prim_mubi_pkg::MuBi24Width;
constexpr IData/*31:0*/ Vtop_prim_mubi_pkg::MuBi28Width;
constexpr IData/*31:0*/ Vtop_prim_mubi_pkg::MuBi32Width;


void Vtop_prim_mubi_pkg___ctor_var_reset(Vtop_prim_mubi_pkg* vlSelf);

void Vtop_prim_mubi_pkg::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_prim_mubi_pkg___ctor_var_reset(this);
}

void Vtop_prim_mubi_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_prim_mubi_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
