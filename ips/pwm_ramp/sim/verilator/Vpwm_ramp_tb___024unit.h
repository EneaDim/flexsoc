// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpwm_ramp_tb.h for the primary calling header

#ifndef VERILATED_VPWM_RAMP_TB___024UNIT_H_
#define VERILATED_VPWM_RAMP_TB___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vpwm_ramp_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vpwm_ramp_tb___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vpwm_ramp_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpwm_ramp_tb___024unit(Vpwm_ramp_tb__Syms* symsp, const char* v__name);
    ~Vpwm_ramp_tb___024unit();
    VL_UNCOPYABLE(Vpwm_ramp_tb___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
