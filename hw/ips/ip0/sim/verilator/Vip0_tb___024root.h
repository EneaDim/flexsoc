// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vip0_tb.h for the primary calling header

#ifndef VERILATED_VIP0_TB___024ROOT_H_
#define VERILATED_VIP0_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vip0_tb___024unit;
class Vip0_tb___024unit__03a__03atlul_utils__Vclpkg;
class Vip0_tb_ip0_reg_pkg;
class Vip0_tb_ip0_tb;


class Vip0_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vip0_tb___024root final {
  public:
    // CELLS
    Vip0_tb_ip0_tb* ip0_tb;
    Vip0_tb___024unit* __PVT____024unit;
    Vip0_tb_ip0_reg_pkg* __PVT__ip0_reg_pkg;
    Vip0_tb___024unit__03a__03atlul_utils__Vclpkg* __024unit__03a__03atlul_utils__Vclpkg;

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __VvifTrigger_h100a9949__0_Vtrigm___PVT__clk_i;
    CData/*0:0*/ __VvifTrigger_h100a9949__1_Vtrigm_d2h;
    CData/*0:0*/ __VvifTrigger_h100a9949__2_Vtrigm_h2d;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__ip0_tb____PVT__clk_i__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__ip0_tb____PVT__rst_ni__0;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 2> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 2> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 7> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlDynamicTriggerScheduler __VdynSched;

    // INTERNAL VARIABLES
    Vip0_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vip0_tb___024root(Vip0_tb__Syms* symsp, const char* namep);
    ~Vip0_tb___024root();
    VL_UNCOPYABLE(Vip0_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
