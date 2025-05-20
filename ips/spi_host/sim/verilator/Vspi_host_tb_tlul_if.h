// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vspi_host_tb.h for the primary calling header

#ifndef VERILATED_VSPI_HOST_TB_TLUL_IF_H_
#define VERILATED_VSPI_HOST_TB_TLUL_IF_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vspi_host_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vspi_host_tb_tlul_if final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__clk_i,0,0);
    VL_IN8(__PVT__rst_ni,0,0);
    VlWide<4>/*108:0*/ h2d;
    VlWide<3>/*65:0*/ d2h;

    // INTERNAL VARIABLES
    Vspi_host_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vspi_host_tb_tlul_if(Vspi_host_tb__Syms* symsp, const char* v__name);
    ~Vspi_host_tb_tlul_if();
    VL_UNCOPYABLE(Vspi_host_tb_tlul_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vspi_host_tb_tlul_if* obj);

#endif  // guard
