// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_PRIM_ALERT_PKG_H_
#define VERILATED_VTOP_PRIM_ALERT_PKG_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_prim_alert_pkg final {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr CData/*1:0*/ ALERT_TX_DEFAULT = 1U;
    static constexpr CData/*3:0*/ ALERT_RX_DEFAULT = 5U;

    // CONSTRUCTORS
    Vtop_prim_alert_pkg() = default;
    ~Vtop_prim_alert_pkg() = default;
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_prim_alert_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
