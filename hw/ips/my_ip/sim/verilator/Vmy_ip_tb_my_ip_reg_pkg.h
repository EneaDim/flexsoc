// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmy_ip_tb.h for the primary calling header

#ifndef VERILATED_VMY_IP_TB_MY_IP_REG_PKG_H_
#define VERILATED_VMY_IP_TB_MY_IP_REG_PKG_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vmy_ip_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmy_ip_tb_my_ip_reg_pkg final {
  public:

    // INTERNAL VARIABLES
    Vmy_ip_tb__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr VlUnpacked<CData/*3:0*/, 4> __PVT__MY_IP_PERMIT = {{
        0x0fU, 1U, 1U, 1U
    }};

    // CONSTRUCTORS
    Vmy_ip_tb_my_ip_reg_pkg() = default;
    ~Vmy_ip_tb_my_ip_reg_pkg() = default;
    void ctor(Vmy_ip_tb__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vmy_ip_tb_my_ip_reg_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
