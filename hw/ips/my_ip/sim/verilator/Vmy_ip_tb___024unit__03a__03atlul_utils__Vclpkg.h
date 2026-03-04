// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmy_ip_tb.h for the primary calling header

#ifndef VERILATED_VMY_IP_TB___024UNIT__03A__03ATLUL_UTILS__VCLPKG_H_
#define VERILATED_VMY_IP_TB___024UNIT__03A__03ATLUL_UTILS__VCLPKG_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vmy_ip_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmy_ip_tb___024unit__03a__03atlul_utils__Vclpkg final {
  public:

    // INTERNAL VARIABLES
    Vmy_ip_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vmy_ip_tb___024unit__03a__03atlul_utils__Vclpkg() = default;
    ~Vmy_ip_tb___024unit__03a__03atlul_utils__Vclpkg() = default;
    void ctor(Vmy_ip_tb__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vmy_ip_tb___024unit__03a__03atlul_utils__Vclpkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


class Vmy_ip_tb__Syms;

class Vmy_ip_tb___024unit__03a__03atlul_utils : public virtual VlClass {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __Vtrigprevexpr_h27d7793b__0;
    CData/*0:0*/ __Vtrigprevexpr_h27d7793b__1;
    CData/*0:0*/ __Vtrigprevexpr_h27d7793b__2;
    CData/*0:0*/ __Vtrigprevexpr_h27d7793b__3;
    Vmy_ip_tb_tlul_if* __PVT__drv_if;
    VlCoroutine __VnoInFunc_tlul_read(Vmy_ip_tb__Syms* __restrict vlSymsp, IData/*31:0*/ addr, IData/*31:0*/ &data, CData/*7:0*/ source);
    VlCoroutine __VnoInFunc_tlul_write(Vmy_ip_tb__Syms* __restrict vlSymsp, IData/*31:0*/ addr, IData/*31:0*/ data, CData/*7:0*/ source);
  private:
    void _ctor_var_reset(Vmy_ip_tb__Syms* __restrict vlSymsp);
  public:
    Vmy_ip_tb___024unit__03a__03atlul_utils(Vmy_ip_tb__Syms* __restrict vlSymsp, Vmy_ip_tb_tlul_if* drv_if);
    std::string to_string() const;
    std::string to_string_middle() const;
    ~Vmy_ip_tb___024unit__03a__03atlul_utils() {}
};

std::string VL_TO_STRING(const VlClassRef<Vmy_ip_tb___024unit__03a__03atlul_utils>& obj);

#endif  // guard
