// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_host_tb.h for the primary calling header

#include "Vspi_host_tb__pch.h"
#include "Vspi_host_tb__Syms.h"
#include "Vspi_host_tb___024unit__03a__03atlul_utils__Vclpkg.h"

Vspi_host_tb___024unit__03a__03atlul_utils::Vspi_host_tb___024unit__03a__03atlul_utils(Vspi_host_tb__Syms* __restrict vlSymsp, Vspi_host_tb_tlul_if* drv_if) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vspi_host_tb___024unit__03a__03atlul_utils::new\n"); );
    // Init
    _ctor_var_reset(vlSymsp);
    // Body
    this->__PVT__drv_if = drv_if;
}

VlCoroutine Vspi_host_tb___024unit__03a__03atlul_utils::__VnoInFunc_tlul_write(Vspi_host_tb__Syms* __restrict vlSymsp, IData/*31:0*/ addr, IData/*31:0*/ data, CData/*7:0*/ source) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vspi_host_tb___024unit__03a__03atlul_utils::__VnoInFunc_tlul_write\n"); );
    // Init
    VL_KEEP_THIS;
    CData/*0:0*/ __Vtrigprevexpr_h649c8c8d__0;
    __Vtrigprevexpr_h649c8c8d__0 = 0;
    CData/*0:0*/ __Vtrigprevexpr_h649c8c8d__2;
    __Vtrigprevexpr_h649c8c8d__2 = 0;
    // Body
    VL_WRITEF_NX("[%0t] TLUL WRITE: Addr = 0x%08x, Data = 0x%08x\n",0,
                 64,VL_TIME_UNITED_Q(1000),-9,32,addr,
                 32,data);
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 18)->h2d[0U] 
        = (1U | VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 18)
           ->h2d[0U]);
    vlSymsp->TOP.__VvifTrigger_h100a9299__0 = 1U;
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 19)->h2d[3U] 
        = (0x1000U | VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 19)
           ->h2d[3U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 20)->h2d[3U] 
        = (0x11ffU & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 20)
           ->h2d[3U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 21)->h2d[3U] 
        = (0x1e3fU & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 21)
           ->h2d[3U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 22)->h2d[3U] 
        = (0x20U | (0x1fcfU & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 22)
                    ->h2d[3U]));
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 23)->h2d[2U] 
        = ((0xfffffffU & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 23)
            ->h2d[2U]) | ((IData)(source) << 0x1cU));
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 23)->h2d[3U] 
        = ((0x1ff0U & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 23)
            ->h2d[3U]) | (0x1fffU & ((IData)(source) 
                                     >> 4U)));
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 24)->h2d[1U] 
        = ((0xfffffffU & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 24)
            ->h2d[1U]) | (addr << 0x1cU));
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 24)->h2d[2U] 
        = ((0xf0000000U & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 24)
            ->h2d[2U]) | (addr >> 4U));
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 25)->h2d[1U] 
        = (0xf000000U | VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 25)
           ->h2d[1U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 26)->h2d[0U] 
        = ((0xffffffU & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 26)
            ->h2d[0U]) | (data << 0x18U));
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 26)->h2d[1U] 
        = ((0xff000000U & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 26)
            ->h2d[1U]) | (data >> 8U));
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 27)->h2d[0U] 
        = (0xff000001U & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 27)
           ->h2d[0U]);
    CData/*0:0*/ __VdynTrigger_h5ee3a870__0;
    __VdynTrigger_h5ee3a870__0 = 0;
    __VdynTrigger_h5ee3a870__0 = 0U;
    __Vtrigprevexpr_h649c8c8d__0 = VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 29)
        ->__PVT__clk_i;
    while ((1U & (~ (IData)(__VdynTrigger_h5ee3a870__0)))) {
        co_await vlSymsp->TOP.__VdynSched.evaluation(
                                                     nullptr, 
                                                     "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                     "tb/tlul_utils.sv", 
                                                     29);
        __VdynTrigger_h5ee3a870__0 = (VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 29)
                                      ->__PVT__clk_i 
                                      & (~ (IData)(__Vtrigprevexpr_h649c8c8d__0)));
        vlSymsp->TOP.__VdynSched.anyTriggered(__VdynTrigger_h5ee3a870__0);
        __Vtrigprevexpr_h649c8c8d__0 = VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 29)
            ->__PVT__clk_i;
    }
    co_await vlSymsp->TOP.__VdynSched.resumption(nullptr, 
                                                 "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                 "tb/tlul_utils.sv", 
                                                 29);
    while ((1U & (~ (IData)(VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 29)
                            ->d2h[0U])))) {
        CData/*0:0*/ __VdynTrigger_h5ee3a870__1;
        __VdynTrigger_h5ee3a870__1 = 0;
        __VdynTrigger_h5ee3a870__1 = 0U;
        this->__Vtrigprevexpr_h649c8c8d__1 = VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 29)
            ->__PVT__clk_i;
        while ((1U & (~ (IData)(__VdynTrigger_h5ee3a870__1)))) {
            co_await vlSymsp->TOP.__VdynSched.evaluation(
                                                         nullptr, 
                                                         "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                         "tb/tlul_utils.sv", 
                                                         29);
            __VdynTrigger_h5ee3a870__1 = (VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 29)
                                          ->__PVT__clk_i 
                                          & (~ (IData)(this->__Vtrigprevexpr_h649c8c8d__1)));
            vlSymsp->TOP.__VdynSched.anyTriggered(__VdynTrigger_h5ee3a870__1);
            this->__Vtrigprevexpr_h649c8c8d__1 = VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 29)
                ->__PVT__clk_i;
        }
        co_await vlSymsp->TOP.__VdynSched.resumption(
                                                     nullptr, 
                                                     "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                     "tb/tlul_utils.sv", 
                                                     29);
    }
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 30)->h2d[3U] 
        = (0xfffU & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 30)
           ->h2d[3U]);
    vlSymsp->TOP.__VvifTrigger_h100a9299__0 = 1U;
    CData/*0:0*/ __VdynTrigger_h5ee3a870__2;
    __VdynTrigger_h5ee3a870__2 = 0;
    __VdynTrigger_h5ee3a870__2 = 0U;
    __Vtrigprevexpr_h649c8c8d__2 = VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 32)
        ->__PVT__clk_i;
    while ((1U & (~ (IData)(__VdynTrigger_h5ee3a870__2)))) {
        co_await vlSymsp->TOP.__VdynSched.evaluation(
                                                     nullptr, 
                                                     "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                     "tb/tlul_utils.sv", 
                                                     32);
        __VdynTrigger_h5ee3a870__2 = (VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 32)
                                      ->__PVT__clk_i 
                                      & (~ (IData)(__Vtrigprevexpr_h649c8c8d__2)));
        vlSymsp->TOP.__VdynSched.anyTriggered(__VdynTrigger_h5ee3a870__2);
        __Vtrigprevexpr_h649c8c8d__2 = VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 32)
            ->__PVT__clk_i;
    }
    co_await vlSymsp->TOP.__VdynSched.resumption(nullptr, 
                                                 "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                 "tb/tlul_utils.sv", 
                                                 32);
    while ((1U & (~ (IData)((VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 32)
                             ->d2h[2U] >> 1U))))) {
        CData/*0:0*/ __VdynTrigger_h5ee3a870__3;
        __VdynTrigger_h5ee3a870__3 = 0;
        __VdynTrigger_h5ee3a870__3 = 0U;
        this->__Vtrigprevexpr_h649c8c8d__3 = VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 32)
            ->__PVT__clk_i;
        while ((1U & (~ (IData)(__VdynTrigger_h5ee3a870__3)))) {
            co_await vlSymsp->TOP.__VdynSched.evaluation(
                                                         nullptr, 
                                                         "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                         "tb/tlul_utils.sv", 
                                                         32);
            __VdynTrigger_h5ee3a870__3 = (VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 32)
                                          ->__PVT__clk_i 
                                          & (~ (IData)(this->__Vtrigprevexpr_h649c8c8d__3)));
            vlSymsp->TOP.__VdynSched.anyTriggered(__VdynTrigger_h5ee3a870__3);
            this->__Vtrigprevexpr_h649c8c8d__3 = VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 32)
                ->__PVT__clk_i;
        }
        co_await vlSymsp->TOP.__VdynSched.resumption(
                                                     nullptr, 
                                                     "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                     "tb/tlul_utils.sv", 
                                                     32);
    }
    if ((2U & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 34)
         ->d2h[0U])) {
        VL_WRITEF_NX("[%0t] TLUL WRITE ERROR: Addr = 0x%08x, d_error = 1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,32,
                     addr);
    } else {
        VL_WRITEF_NX("[%0t] TLUL WRITE DONE: Addr = 0x%08x\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,32,
                     addr);
    }
    co_await vlSymsp->TOP.__VdlySched.delay(0x3e8ULL, 
                                            nullptr, 
                                            "tb/tlul_utils.sv", 
                                            39);
}

VlCoroutine Vspi_host_tb___024unit__03a__03atlul_utils::__VnoInFunc_tlul_read(Vspi_host_tb__Syms* __restrict vlSymsp, IData/*31:0*/ addr, IData/*31:0*/ data, CData/*7:0*/ source) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vspi_host_tb___024unit__03a__03atlul_utils::__VnoInFunc_tlul_read\n"); );
    // Init
    VL_KEEP_THIS;
    CData/*0:0*/ __Vtrigprevexpr_h649c8c8d__4;
    __Vtrigprevexpr_h649c8c8d__4 = 0;
    CData/*0:0*/ __Vtrigprevexpr_h649c8c8d__6;
    __Vtrigprevexpr_h649c8c8d__6 = 0;
    // Body
    VL_WRITEF_NX("[%0t] TLUL READ: Addr = 0x%08x\n",0,
                 64,VL_TIME_UNITED_Q(1000),-9,32,addr);
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 48)->h2d[0U] 
        = (1U | VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 48)
           ->h2d[0U]);
    vlSymsp->TOP.__VvifTrigger_h100a9299__0 = 1U;
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 49)->h2d[3U] 
        = (0x1000U | VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 49)
           ->h2d[3U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 50)->h2d[3U] 
        = (0x800U | (0x11ffU & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 50)
                     ->h2d[3U]));
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 51)->h2d[3U] 
        = (0x1e3fU & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 51)
           ->h2d[3U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 52)->h2d[3U] 
        = (0x20U | (0x1fcfU & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 52)
                    ->h2d[3U]));
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 53)->h2d[2U] 
        = ((0xfffffffU & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 53)
            ->h2d[2U]) | ((IData)(source) << 0x1cU));
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 53)->h2d[3U] 
        = ((0x1ff0U & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 53)
            ->h2d[3U]) | (0x1fffU & ((IData)(source) 
                                     >> 4U)));
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 54)->h2d[1U] 
        = ((0xfffffffU & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 54)
            ->h2d[1U]) | (addr << 0x1cU));
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 54)->h2d[2U] 
        = ((0xf0000000U & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 54)
            ->h2d[2U]) | (addr >> 4U));
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 55)->h2d[1U] 
        = (0xf000000U | VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 55)
           ->h2d[1U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 56)->h2d[0U] 
        = (0xffffffU & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 56)
           ->h2d[0U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 56)->h2d[1U] 
        = (0xff000000U & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 56)
           ->h2d[1U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 57)->h2d[0U] 
        = (0xff000001U & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 57)
           ->h2d[0U]);
    CData/*0:0*/ __VdynTrigger_h5ee3a870__4;
    __VdynTrigger_h5ee3a870__4 = 0;
    __VdynTrigger_h5ee3a870__4 = 0U;
    __Vtrigprevexpr_h649c8c8d__4 = VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 59)
        ->__PVT__clk_i;
    while ((1U & (~ (IData)(__VdynTrigger_h5ee3a870__4)))) {
        co_await vlSymsp->TOP.__VdynSched.evaluation(
                                                     nullptr, 
                                                     "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                     "tb/tlul_utils.sv", 
                                                     59);
        __VdynTrigger_h5ee3a870__4 = (VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 59)
                                      ->__PVT__clk_i 
                                      & (~ (IData)(__Vtrigprevexpr_h649c8c8d__4)));
        vlSymsp->TOP.__VdynSched.anyTriggered(__VdynTrigger_h5ee3a870__4);
        __Vtrigprevexpr_h649c8c8d__4 = VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 59)
            ->__PVT__clk_i;
    }
    co_await vlSymsp->TOP.__VdynSched.resumption(nullptr, 
                                                 "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                 "tb/tlul_utils.sv", 
                                                 59);
    while ((1U & (~ (IData)(VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 59)
                            ->d2h[0U])))) {
        CData/*0:0*/ __VdynTrigger_h5ee3a870__5;
        __VdynTrigger_h5ee3a870__5 = 0;
        __VdynTrigger_h5ee3a870__5 = 0U;
        this->__Vtrigprevexpr_h649c8c8d__5 = VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 59)
            ->__PVT__clk_i;
        while ((1U & (~ (IData)(__VdynTrigger_h5ee3a870__5)))) {
            co_await vlSymsp->TOP.__VdynSched.evaluation(
                                                         nullptr, 
                                                         "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                         "tb/tlul_utils.sv", 
                                                         59);
            __VdynTrigger_h5ee3a870__5 = (VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 59)
                                          ->__PVT__clk_i 
                                          & (~ (IData)(this->__Vtrigprevexpr_h649c8c8d__5)));
            vlSymsp->TOP.__VdynSched.anyTriggered(__VdynTrigger_h5ee3a870__5);
            this->__Vtrigprevexpr_h649c8c8d__5 = VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 59)
                ->__PVT__clk_i;
        }
        co_await vlSymsp->TOP.__VdynSched.resumption(
                                                     nullptr, 
                                                     "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                     "tb/tlul_utils.sv", 
                                                     59);
    }
    VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 60)->h2d[3U] 
        = (0xfffU & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 60)
           ->h2d[3U]);
    vlSymsp->TOP.__VvifTrigger_h100a9299__0 = 1U;
    CData/*0:0*/ __VdynTrigger_h5ee3a870__6;
    __VdynTrigger_h5ee3a870__6 = 0;
    __VdynTrigger_h5ee3a870__6 = 0U;
    __Vtrigprevexpr_h649c8c8d__6 = VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 62)
        ->__PVT__clk_i;
    while ((1U & (~ (IData)(__VdynTrigger_h5ee3a870__6)))) {
        co_await vlSymsp->TOP.__VdynSched.evaluation(
                                                     nullptr, 
                                                     "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                     "tb/tlul_utils.sv", 
                                                     62);
        __VdynTrigger_h5ee3a870__6 = (VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 62)
                                      ->__PVT__clk_i 
                                      & (~ (IData)(__Vtrigprevexpr_h649c8c8d__6)));
        vlSymsp->TOP.__VdynSched.anyTriggered(__VdynTrigger_h5ee3a870__6);
        __Vtrigprevexpr_h649c8c8d__6 = VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 62)
            ->__PVT__clk_i;
    }
    co_await vlSymsp->TOP.__VdynSched.resumption(nullptr, 
                                                 "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                 "tb/tlul_utils.sv", 
                                                 62);
    while ((1U & (~ (IData)((VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 62)
                             ->d2h[2U] >> 1U))))) {
        CData/*0:0*/ __VdynTrigger_h5ee3a870__7;
        __VdynTrigger_h5ee3a870__7 = 0;
        __VdynTrigger_h5ee3a870__7 = 0U;
        this->__Vtrigprevexpr_h649c8c8d__7 = VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 62)
            ->__PVT__clk_i;
        while ((1U & (~ (IData)(__VdynTrigger_h5ee3a870__7)))) {
            co_await vlSymsp->TOP.__VdynSched.evaluation(
                                                         nullptr, 
                                                         "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                         "tb/tlul_utils.sv", 
                                                         62);
            __VdynTrigger_h5ee3a870__7 = (VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 62)
                                          ->__PVT__clk_i 
                                          & (~ (IData)(this->__Vtrigprevexpr_h649c8c8d__7)));
            vlSymsp->TOP.__VdynSched.anyTriggered(__VdynTrigger_h5ee3a870__7);
            this->__Vtrigprevexpr_h649c8c8d__7 = VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 62)
                ->__PVT__clk_i;
        }
        co_await vlSymsp->TOP.__VdynSched.resumption(
                                                     nullptr, 
                                                     "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                     "tb/tlul_utils.sv", 
                                                     62);
    }
    data = (((IData)(VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 63)
                     ->d2h[1U]) << 0x10U) | (VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 63)
                                             ->d2h[0U] 
                                             >> 0x10U));
    if ((2U & VL_NULL_CHECK(this->__PVT__drv_if, "tb/tlul_utils.sv", 65)
         ->d2h[0U])) {
        VL_WRITEF_NX("[%0t] TLUL READ ERROR: Addr = 0x%08x, d_error = 1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,32,
                     addr);
    } else {
        VL_WRITEF_NX("[%0t] TLUL READ DONE: Addr = 0x%08x, Data = 0x%08x\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,32,
                     addr,32,data);
    }
    co_await vlSymsp->TOP.__VdlySched.delay(0x3e8ULL, 
                                            nullptr, 
                                            "tb/tlul_utils.sv", 
                                            70);
}

void Vspi_host_tb___024unit__03a__03atlul_utils::_ctor_var_reset(Vspi_host_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vspi_host_tb___024unit__03a__03atlul_utils::_ctor_var_reset\n"); );
    // Body
    (void)vlSymsp;  // Prevent unused variable warning
    __PVT__drv_if = nullptr;
    __Vtrigprevexpr_h649c8c8d__1 = VL_RAND_RESET_I(1);
    __Vtrigprevexpr_h649c8c8d__3 = VL_RAND_RESET_I(1);
    __Vtrigprevexpr_h649c8c8d__5 = VL_RAND_RESET_I(1);
    __Vtrigprevexpr_h649c8c8d__7 = VL_RAND_RESET_I(1);
}
