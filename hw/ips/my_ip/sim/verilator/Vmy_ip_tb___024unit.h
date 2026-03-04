// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmy_ip_tb.h for the primary calling header

#ifndef VERILATED_VMY_IP_TB___024UNIT_H_
#define VERILATED_VMY_IP_TB___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vmy_ip_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmy_ip_tb___024unit final {
  public:

    // INTERNAL VARIABLES
    Vmy_ip_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vmy_ip_tb___024unit() = default;
    ~Vmy_ip_tb___024unit() = default;
    void ctor(Vmy_ip_tb__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vmy_ip_tb___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
