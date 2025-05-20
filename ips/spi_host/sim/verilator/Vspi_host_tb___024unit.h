// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vspi_host_tb.h for the primary calling header

#ifndef VERILATED_VSPI_HOST_TB___024UNIT_H_
#define VERILATED_VSPI_HOST_TB___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vspi_host_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vspi_host_tb___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vspi_host_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vspi_host_tb___024unit(Vspi_host_tb__Syms* symsp, const char* v__name);
    ~Vspi_host_tb___024unit();
    VL_UNCOPYABLE(Vspi_host_tb___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
