// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpwm_ramp_tb.h for the primary calling header

#ifndef VERILATED_VPWM_RAMP_TB___024UNIT__03A__03ATLUL_UTILS__VCLPKG_H_
#define VERILATED_VPWM_RAMP_TB___024UNIT__03A__03ATLUL_UTILS__VCLPKG_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vpwm_ramp_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vpwm_ramp_tb___024unit__03a__03atlul_utils__Vclpkg final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vpwm_ramp_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpwm_ramp_tb___024unit__03a__03atlul_utils__Vclpkg(Vpwm_ramp_tb__Syms* symsp, const char* v__name);
    ~Vpwm_ramp_tb___024unit__03a__03atlul_utils__Vclpkg();
    VL_UNCOPYABLE(Vpwm_ramp_tb___024unit__03a__03atlul_utils__Vclpkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


class Vpwm_ramp_tb__Syms;

class Vpwm_ramp_tb___024unit__03a__03atlul_utils : public VlClass {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __Vtrigprevexpr_h649c8c8d__1;
    CData/*0:0*/ __Vtrigprevexpr_h649c8c8d__3;
    CData/*0:0*/ __Vtrigprevexpr_h649c8c8d__5;
    CData/*0:0*/ __Vtrigprevexpr_h649c8c8d__7;
    Vpwm_ramp_tb_tlul_if* __PVT__drv_if;
    VlCoroutine __VnoInFunc_tlul_read(Vpwm_ramp_tb__Syms* __restrict vlSymsp, IData/*31:0*/ addr, IData/*31:0*/ data, CData/*7:0*/ source);
    VlCoroutine __VnoInFunc_tlul_write(Vpwm_ramp_tb__Syms* __restrict vlSymsp, IData/*31:0*/ addr, IData/*31:0*/ data, CData/*7:0*/ source);
  private:
    void _ctor_var_reset(Vpwm_ramp_tb__Syms* __restrict vlSymsp);
  public:
    Vpwm_ramp_tb___024unit__03a__03atlul_utils(Vpwm_ramp_tb__Syms* __restrict vlSymsp, Vpwm_ramp_tb_tlul_if* drv_if);
    std::string to_string() const;
    std::string to_string_middle() const;
    ~Vpwm_ramp_tb___024unit__03a__03atlul_utils() {}
};

std::string VL_TO_STRING(const VlClassRef<Vpwm_ramp_tb___024unit__03a__03atlul_utils>& obj);

#endif  // guard
