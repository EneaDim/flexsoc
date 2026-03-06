// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vip1_tb.h for the primary calling header

#ifndef VERILATED_VIP1_TB_IP1_REG_PKG_H_
#define VERILATED_VIP1_TB_IP1_REG_PKG_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vip1_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vip1_tb_ip1_reg_pkg final {
  public:

    // INTERNAL VARIABLES
    Vip1_tb__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr VlUnpacked<CData/*3:0*/, 4> __PVT__IP1_PERMIT = {{
        0x0fU, 1U, 1U, 1U
    }};

    // CONSTRUCTORS
    Vip1_tb_ip1_reg_pkg() = default;
    ~Vip1_tb_ip1_reg_pkg() = default;
    void ctor(Vip1_tb__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vip1_tb_ip1_reg_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
