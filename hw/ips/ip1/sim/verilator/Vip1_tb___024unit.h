// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vip1_tb.h for the primary calling header

#ifndef VERILATED_VIP1_TB___024UNIT_H_
#define VERILATED_VIP1_TB___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vip1_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vip1_tb___024unit final {
  public:

    // INTERNAL VARIABLES
    Vip1_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vip1_tb___024unit() = default;
    ~Vip1_tb___024unit() = default;
    void ctor(Vip1_tb__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vip1_tb___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
