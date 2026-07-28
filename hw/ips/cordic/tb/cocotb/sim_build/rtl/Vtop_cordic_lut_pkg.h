// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_CORDIC_LUT_PKG_H_
#define VERILATED_VTOP_CORDIC_LUT_PKG_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_cordic_lut_pkg final {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr SData/*15:0*/ PI_Q = 0x6488U;
    static constexpr SData/*15:0*/ HALF_PI_Q = 0x3244U;
    static constexpr VlUnpacked<SData/*15:0*/, 16> AtanLut = {{
        0x1922U, 0x0ed6U, 0x07d7U, 0x03fbU, 0x01ffU, 0x0100U, 0x0080U, 0x0040U,
        0x0020U, 0x0010U, 8U, 4U, 2U, 1U, 0U, 0U
    }};

    // CONSTRUCTORS
    Vtop_cordic_lut_pkg() = default;
    ~Vtop_cordic_lut_pkg() = default;
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_cordic_lut_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
