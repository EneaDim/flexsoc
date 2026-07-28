// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_CORDIC_REG_PKG_H_
#define VERILATED_VTOP_CORDIC_REG_PKG_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_cordic_reg_pkg final {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr CData/*5:0*/ CORDIC_CTRL_OFFSET = 0U;
    static constexpr CData/*5:0*/ CORDIC_STATUS_OFFSET = 4U;
    static constexpr CData/*5:0*/ CORDIC_X_IN_OFFSET = 8U;
    static constexpr CData/*5:0*/ CORDIC_Y_IN_OFFSET = 0x0cU;
    static constexpr CData/*5:0*/ CORDIC_Z_IN_OFFSET = 0x10U;
    static constexpr CData/*5:0*/ CORDIC_X_OUT_OFFSET = 0x14U;
    static constexpr CData/*5:0*/ CORDIC_Y_OUT_OFFSET = 0x18U;
    static constexpr CData/*5:0*/ CORDIC_Z_OUT_OFFSET = 0x1cU;
    static constexpr CData/*5:0*/ CORDIC_CFG_OFFSET = 0x20U;
    static constexpr IData/*31:0*/ BlockAw = 6U;
    static constexpr IData/*31:0*/ AW = 6U;
    static constexpr IData/*31:0*/ DW = 0x00000020U;
    static constexpr IData/*31:0*/ DBW = 4U;
    static constexpr IData/*31:0*/ CORDIC_STATUS_RESVAL = 0U;
    static constexpr IData/*31:0*/ CORDIC_X_OUT_RESVAL = 0U;
    static constexpr IData/*31:0*/ CORDIC_Y_OUT_RESVAL = 0U;
    static constexpr IData/*31:0*/ CORDIC_Z_OUT_RESVAL = 0U;
    static constexpr IData/*31:0*/ CORDIC_CFG_RESVAL = 0U;
    static constexpr VlUnpacked<CData/*3:0*/, 9> CORDIC_PERMIT = {{
        0x0fU, 0x0fU, 0x0fU, 0x0fU, 0x0fU, 0x0fU, 0x0fU, 0x0fU,
        0x0fU
    }};

    // CONSTRUCTORS
    Vtop_cordic_reg_pkg() = default;
    ~Vtop_cordic_reg_pkg() = default;
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_cordic_reg_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
