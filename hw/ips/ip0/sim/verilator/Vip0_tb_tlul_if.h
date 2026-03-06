// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vip0_tb.h for the primary calling header

#ifndef VERILATED_VIP0_TB_TLUL_IF_H_
#define VERILATED_VIP0_TB_TLUL_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vip0_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vip0_tb_tlul_if final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__clk_i,0,0);
    VL_IN8(__PVT__rst_ni,0,0);
    VlWide<4>/*108:0*/ h2d;
    VlWide<3>/*65:0*/ d2h;

    // INTERNAL VARIABLES
    Vip0_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vip0_tb_tlul_if() = default;
    ~Vip0_tb_tlul_if() = default;
    void ctor(Vip0_tb__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vip0_tb_tlul_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vip0_tb_tlul_if* obj);

#endif  // guard
