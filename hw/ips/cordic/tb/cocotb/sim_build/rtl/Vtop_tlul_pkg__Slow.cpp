// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_tlul_pkg
constexpr SData/*13:0*/ Vtop_tlul_pkg::TL_D_USER_DEFAULT;
constexpr IData/*23:0*/ Vtop_tlul_pkg::ArbiterImpl;
constexpr IData/*31:0*/ Vtop_tlul_pkg::H2DCmdMaxWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::H2DCmdIntgWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::H2DCmdFullWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::D2HRspMaxWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::D2HRspIntgWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::D2HRspFullWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::DataMaxWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::DataIntgWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::DataFullWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::DataWhenInstrError;
constexpr IData/*31:0*/ Vtop_tlul_pkg::DataWhenError;
constexpr IData/*22:0*/ Vtop_tlul_pkg::TL_A_USER_DEFAULT;
constexpr IData/*31:0*/ Vtop_tlul_pkg::BlankedAData;
constexpr VlWide<4>/*108:0*/ Vtop_tlul_pkg::TL_H2D_DEFAULT;
constexpr VlWide<3>/*65:0*/ Vtop_tlul_pkg::TL_D2H_DEFAULT;


void Vtop_tlul_pkg___ctor_var_reset(Vtop_tlul_pkg* vlSelf);

void Vtop_tlul_pkg::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_tlul_pkg___ctor_var_reset(this);
}

void Vtop_tlul_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_tlul_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
