// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_top_pkg
constexpr IData/*31:0*/ Vtop_top_pkg::TL_AW;
constexpr IData/*31:0*/ Vtop_top_pkg::TL_DW;
constexpr IData/*31:0*/ Vtop_top_pkg::TL_AIW;
constexpr IData/*31:0*/ Vtop_top_pkg::TL_DIW;
constexpr IData/*31:0*/ Vtop_top_pkg::TL_AUW;
constexpr IData/*31:0*/ Vtop_top_pkg::TL_DUW;
constexpr IData/*31:0*/ Vtop_top_pkg::TL_DBW;
constexpr IData/*31:0*/ Vtop_top_pkg::TL_SZW;
constexpr IData/*31:0*/ Vtop_top_pkg::SecVolatileRawUnlockEn;


void Vtop_top_pkg___ctor_var_reset(Vtop_top_pkg* vlSelf);

void Vtop_top_pkg::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_top_pkg___ctor_var_reset(this);
}

void Vtop_top_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_top_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
