// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmy_ip_tb.h for the primary calling header

#ifndef VERILATED_VMY_IP_TB_TLUL_IF_H_
#define VERILATED_VMY_IP_TB_TLUL_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vmy_ip_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmy_ip_tb_tlul_if final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__clk_i,0,0);
    VL_IN8(__PVT__rst_ni,0,0);
    VlWide<4>/*108:0*/ h2d;
    VlWide<3>/*65:0*/ d2h;

    // INTERNAL VARIABLES
    Vmy_ip_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vmy_ip_tb_tlul_if() = default;
    ~Vmy_ip_tb_tlul_if() = default;
    void ctor(Vmy_ip_tb__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vmy_ip_tb_tlul_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vmy_ip_tb_tlul_if* obj);

#endif  // guard
