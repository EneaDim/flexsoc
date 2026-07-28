// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_cordic_reg_pkg
constexpr CData/*5:0*/ Vtop_cordic_reg_pkg::CORDIC_CTRL_OFFSET;
constexpr CData/*5:0*/ Vtop_cordic_reg_pkg::CORDIC_STATUS_OFFSET;
constexpr CData/*5:0*/ Vtop_cordic_reg_pkg::CORDIC_X_IN_OFFSET;
constexpr CData/*5:0*/ Vtop_cordic_reg_pkg::CORDIC_Y_IN_OFFSET;
constexpr CData/*5:0*/ Vtop_cordic_reg_pkg::CORDIC_Z_IN_OFFSET;
constexpr CData/*5:0*/ Vtop_cordic_reg_pkg::CORDIC_X_OUT_OFFSET;
constexpr CData/*5:0*/ Vtop_cordic_reg_pkg::CORDIC_Y_OUT_OFFSET;
constexpr CData/*5:0*/ Vtop_cordic_reg_pkg::CORDIC_Z_OUT_OFFSET;
constexpr CData/*5:0*/ Vtop_cordic_reg_pkg::CORDIC_CFG_OFFSET;
constexpr IData/*31:0*/ Vtop_cordic_reg_pkg::BlockAw;
constexpr IData/*31:0*/ Vtop_cordic_reg_pkg::AW;
constexpr IData/*31:0*/ Vtop_cordic_reg_pkg::DW;
constexpr IData/*31:0*/ Vtop_cordic_reg_pkg::DBW;
constexpr IData/*31:0*/ Vtop_cordic_reg_pkg::CORDIC_STATUS_RESVAL;
constexpr IData/*31:0*/ Vtop_cordic_reg_pkg::CORDIC_X_OUT_RESVAL;
constexpr IData/*31:0*/ Vtop_cordic_reg_pkg::CORDIC_Y_OUT_RESVAL;
constexpr IData/*31:0*/ Vtop_cordic_reg_pkg::CORDIC_Z_OUT_RESVAL;
constexpr IData/*31:0*/ Vtop_cordic_reg_pkg::CORDIC_CFG_RESVAL;
constexpr VlUnpacked<CData/*3:0*/, 9> Vtop_cordic_reg_pkg::CORDIC_PERMIT;


void Vtop_cordic_reg_pkg___ctor_var_reset(Vtop_cordic_reg_pkg* vlSelf);

void Vtop_cordic_reg_pkg::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_cordic_reg_pkg___ctor_var_reset(this);
}

void Vtop_cordic_reg_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_cordic_reg_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
