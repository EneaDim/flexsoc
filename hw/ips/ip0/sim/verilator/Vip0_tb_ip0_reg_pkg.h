// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vip0_tb.h for the primary calling header

#ifndef VERILATED_VIP0_TB_IP0_REG_PKG_H_
#define VERILATED_VIP0_TB_IP0_REG_PKG_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vip0_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vip0_tb_ip0_reg_pkg final {
  public:

    // INTERNAL VARIABLES
    Vip0_tb__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr VlUnpacked<CData/*3:0*/, 4> __PVT__IP0_PERMIT = {{
        0x0fU, 1U, 1U, 1U
    }};

    // CONSTRUCTORS
    Vip0_tb_ip0_reg_pkg() = default;
    ~Vip0_tb_ip0_reg_pkg() = default;
    void ctor(Vip0_tb__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vip0_tb_ip0_reg_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
