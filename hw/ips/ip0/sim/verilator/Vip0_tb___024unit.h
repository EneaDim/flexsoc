// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vip0_tb.h for the primary calling header

#ifndef VERILATED_VIP0_TB___024UNIT_H_
#define VERILATED_VIP0_TB___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vip0_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vip0_tb___024unit final {
  public:

    // INTERNAL VARIABLES
    Vip0_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vip0_tb___024unit() = default;
    ~Vip0_tb___024unit() = default;
    void ctor(Vip0_tb__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vip0_tb___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
