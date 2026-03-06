// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vip1_tb.h for the primary calling header

#include "Vip1_tb__pch.h"

Vip1_tb___024unit__03a__03atlul_utils::Vip1_tb___024unit__03a__03atlul_utils(Vip1_tb__Syms* __restrict vlSymsp, Vip1_tb_tlul_if* drv_if) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vip1_tb___024unit__03a__03atlul_utils::new\n"); );
    // Body
    _ctor_var_reset(vlSymsp);
    this->__PVT__drv_if = drv_if;
}

VlCoroutine Vip1_tb___024unit__03a__03atlul_utils::__VnoInFunc_tlul_write(Vip1_tb__Syms* __restrict vlSymsp, IData/*31:0*/ addr, IData/*31:0*/ data, CData/*7:0*/ source) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vip1_tb___024unit__03a__03atlul_utils::__VnoInFunc_tlul_write\n"); );
    // Body
    VL_KEEP_THIS;
    VL_WRITEF_NX("[%0t] TLUL WRITE: Addr = 0x%08x, Data = 0x%08x\n",0,
                 64,VL_TIME_UNITED_Q(1000),-9,32,addr,
                 32,data);
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 15)->h2d[0U] 
        = (1U | VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 15)
           ->h2d[0U]);
    vlSymsp->TOP.__VvifTrigger_h100a9949__2_Vtrigm_h2d = 1U;
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 16)->h2d[3U] 
        = (0x00001000U | VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 16)
           ->h2d[3U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 17)->h2d[3U] 
        = (0x000011ffU & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 17)
           ->h2d[3U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 18)->h2d[3U] 
        = (0x00001e3fU & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 18)
           ->h2d[3U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 19)->h2d[3U] 
        = (0x00000020U | (0x00001fcfU & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 19)
                          ->h2d[3U]));
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 20)->h2d[2U] 
        = ((0x0fffffffU & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 20)
            ->h2d[2U]) | ((IData)(source) << 0x0000001cU));
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 20)->h2d[3U] 
        = ((0x00001ff0U & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 20)
            ->h2d[3U]) | (0x00001fffU & ((IData)(source) 
                                         >> 4U)));
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 21)->h2d[1U] 
        = ((0x0fffffffU & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 21)
            ->h2d[1U]) | (addr << 0x0000001cU));
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 21)->h2d[2U] 
        = ((0xf0000000U & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 21)
            ->h2d[2U]) | (addr >> 4U));
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 22)->h2d[1U] 
        = (0x0f000000U | VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 22)
           ->h2d[1U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 23)->h2d[0U] 
        = ((0x00ffffffU & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 23)
            ->h2d[0U]) | (data << 0x00000018U));
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 23)->h2d[1U] 
        = ((0xff000000U & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 23)
            ->h2d[1U]) | (data >> 8U));
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 24)->h2d[0U] 
        = (0xff000001U & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 24)
           ->h2d[0U]);
    do {
        CData/*0:0*/ __VdynTrigger_h1e17fa69__0;
        __VdynTrigger_h1e17fa69__0 = 0;
        __VdynTrigger_h1e17fa69__0 = 0U;
        this->__Vtrigprevexpr_h27d7793b__0 = VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 26)
            ->__PVT__clk_i;
        while ((1U & (~ (IData)(__VdynTrigger_h1e17fa69__0)))) {
            co_await vlSymsp->TOP.__VdynSched.evaluation(
                                                         nullptr, 
                                                         "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                         "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 
                                                         26);
            __VdynTrigger_h1e17fa69__0 = (VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 26)
                                          ->__PVT__clk_i 
                                          & (~ (IData)(this->__Vtrigprevexpr_h27d7793b__0)));
            vlSymsp->TOP.__VdynSched.anyTriggered(__VdynTrigger_h1e17fa69__0);
            this->__Vtrigprevexpr_h27d7793b__0 = VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 26)
                ->__PVT__clk_i;
        }
        co_await vlSymsp->TOP.__VdynSched.resumption(
                                                     nullptr, 
                                                     "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                     "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 
                                                     26);
    } while ((1U & (~ VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 26)
                    ->d2h[0U])));
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 27)->h2d[3U] 
        = (0x00000fffU & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 27)
           ->h2d[3U]);
    vlSymsp->TOP.__VvifTrigger_h100a9949__2_Vtrigm_h2d = 1U;
    do {
        CData/*0:0*/ __VdynTrigger_h1e17fa69__1;
        __VdynTrigger_h1e17fa69__1 = 0;
        __VdynTrigger_h1e17fa69__1 = 0U;
        this->__Vtrigprevexpr_h27d7793b__1 = VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 29)
            ->__PVT__clk_i;
        while ((1U & (~ (IData)(__VdynTrigger_h1e17fa69__1)))) {
            co_await vlSymsp->TOP.__VdynSched.evaluation(
                                                         nullptr, 
                                                         "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                         "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 
                                                         29);
            __VdynTrigger_h1e17fa69__1 = (VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 29)
                                          ->__PVT__clk_i 
                                          & (~ (IData)(this->__Vtrigprevexpr_h27d7793b__1)));
            vlSymsp->TOP.__VdynSched.anyTriggered(__VdynTrigger_h1e17fa69__1);
            this->__Vtrigprevexpr_h27d7793b__1 = VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 29)
                ->__PVT__clk_i;
        }
        co_await vlSymsp->TOP.__VdynSched.resumption(
                                                     nullptr, 
                                                     "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                     "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 
                                                     29);
    } while ((1U & (~ (VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 29)
                       ->d2h[2U] >> 1U))));
    if ((2U & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 31)
         ->d2h[0U])) {
        VL_WRITEF_NX("[%0t] TLUL WRITE ERROR: Addr = 0x%08x, d_error = 1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,32,
                     addr);
    } else {
        VL_WRITEF_NX("[%0t] TLUL WRITE DONE: Addr = 0x%08x\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,32,
                     addr);
    }
    co_await vlSymsp->TOP.__VdlySched.delay(0x00000000000003e8ULL, 
                                            nullptr, 
                                            "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 
                                            36);
}

VlCoroutine Vip1_tb___024unit__03a__03atlul_utils::__VnoInFunc_tlul_read(Vip1_tb__Syms* __restrict vlSymsp, IData/*31:0*/ addr, IData/*31:0*/ &data, CData/*7:0*/ source) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vip1_tb___024unit__03a__03atlul_utils::__VnoInFunc_tlul_read\n"); );
    // Body
    VL_KEEP_THIS;
    VL_WRITEF_NX("[%0t] TLUL READ: Addr = 0x%08x\n",0,
                 64,VL_TIME_UNITED_Q(1000),-9,32,addr);
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 45)->h2d[0U] 
        = (1U | VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 45)
           ->h2d[0U]);
    vlSymsp->TOP.__VvifTrigger_h100a9949__2_Vtrigm_h2d = 1U;
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 46)->h2d[3U] 
        = (0x00001000U | VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 46)
           ->h2d[3U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 47)->h2d[3U] 
        = (0x00000800U | (0x000011ffU & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 47)
                          ->h2d[3U]));
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 48)->h2d[3U] 
        = (0x00001e3fU & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 48)
           ->h2d[3U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 49)->h2d[3U] 
        = (0x00000020U | (0x00001fcfU & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 49)
                          ->h2d[3U]));
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 50)->h2d[2U] 
        = ((0x0fffffffU & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 50)
            ->h2d[2U]) | ((IData)(source) << 0x0000001cU));
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 50)->h2d[3U] 
        = ((0x00001ff0U & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 50)
            ->h2d[3U]) | (0x00001fffU & ((IData)(source) 
                                         >> 4U)));
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 51)->h2d[1U] 
        = ((0x0fffffffU & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 51)
            ->h2d[1U]) | (addr << 0x0000001cU));
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 51)->h2d[2U] 
        = ((0xf0000000U & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 51)
            ->h2d[2U]) | (addr >> 4U));
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 52)->h2d[1U] 
        = (0x0f000000U | VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 52)
           ->h2d[1U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 53)->h2d[0U] 
        = (0x00ffffffU & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 53)
           ->h2d[0U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 53)->h2d[1U] 
        = (0xff000000U & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 53)
           ->h2d[1U]);
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 54)->h2d[0U] 
        = (0xff000001U & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 54)
           ->h2d[0U]);
    do {
        CData/*0:0*/ __VdynTrigger_h1e17fa69__2;
        __VdynTrigger_h1e17fa69__2 = 0;
        __VdynTrigger_h1e17fa69__2 = 0U;
        this->__Vtrigprevexpr_h27d7793b__2 = VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 56)
            ->__PVT__clk_i;
        while ((1U & (~ (IData)(__VdynTrigger_h1e17fa69__2)))) {
            co_await vlSymsp->TOP.__VdynSched.evaluation(
                                                         nullptr, 
                                                         "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                         "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 
                                                         56);
            __VdynTrigger_h1e17fa69__2 = (VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 56)
                                          ->__PVT__clk_i 
                                          & (~ (IData)(this->__Vtrigprevexpr_h27d7793b__2)));
            vlSymsp->TOP.__VdynSched.anyTriggered(__VdynTrigger_h1e17fa69__2);
            this->__Vtrigprevexpr_h27d7793b__2 = VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 56)
                ->__PVT__clk_i;
        }
        co_await vlSymsp->TOP.__VdynSched.resumption(
                                                     nullptr, 
                                                     "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                     "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 
                                                     56);
    } while ((1U & (~ VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 56)
                    ->d2h[0U])));
    VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 57)->h2d[3U] 
        = (0x00000fffU & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 57)
           ->h2d[3U]);
    vlSymsp->TOP.__VvifTrigger_h100a9949__2_Vtrigm_h2d = 1U;
    do {
        CData/*0:0*/ __VdynTrigger_h1e17fa69__3;
        __VdynTrigger_h1e17fa69__3 = 0;
        __VdynTrigger_h1e17fa69__3 = 0U;
        this->__Vtrigprevexpr_h27d7793b__3 = VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 59)
            ->__PVT__clk_i;
        while ((1U & (~ (IData)(__VdynTrigger_h1e17fa69__3)))) {
            co_await vlSymsp->TOP.__VdynSched.evaluation(
                                                         nullptr, 
                                                         "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                         "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 
                                                         59);
            __VdynTrigger_h1e17fa69__3 = (VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 59)
                                          ->__PVT__clk_i 
                                          & (~ (IData)(this->__Vtrigprevexpr_h27d7793b__3)));
            vlSymsp->TOP.__VdynSched.anyTriggered(__VdynTrigger_h1e17fa69__3);
            this->__Vtrigprevexpr_h27d7793b__3 = VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 59)
                ->__PVT__clk_i;
        }
        co_await vlSymsp->TOP.__VdynSched.resumption(
                                                     nullptr, 
                                                     "@(posedge $unit::tlul_utils.drv_if.clk_i)", 
                                                     "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 
                                                     59);
    } while ((1U & (~ (VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 59)
                       ->d2h[2U] >> 1U))));
    data = ((VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 60)
             ->d2h[1U] << 0x00000010U) | (VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 60)
                                          ->d2h[0U] 
                                          >> 0x00000010U));
    if ((2U & VL_NULL_CHECK(this->__PVT__drv_if, "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 62)
         ->d2h[0U])) {
        VL_WRITEF_NX("[%0t] TLUL READ ERROR: Addr = 0x%08x, d_error = 1\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,32,
                     addr);
    } else {
        VL_WRITEF_NX("[%0t] TLUL READ DONE: Addr = 0x%08x, Data = 0x%08x\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,32,
                     addr,32,data);
    }
    co_await vlSymsp->TOP.__VdlySched.delay(0x00000000000003e8ULL, 
                                            nullptr, 
                                            "/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/tb/tlul_utils.sv", 
                                            67);
}

void Vip1_tb___024unit__03a__03atlul_utils::_ctor_var_reset(Vip1_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vip1_tb___024unit__03a__03atlul_utils::_ctor_var_reset\n"); );
    // Body
    (void)vlSymsp;  // Prevent unused variable warning
    __PVT__drv_if = nullptr;
    __Vtrigprevexpr_h27d7793b__0 = 0;
    __Vtrigprevexpr_h27d7793b__1 = 0;
    __Vtrigprevexpr_h27d7793b__2 = 0;
    __Vtrigprevexpr_h27d7793b__3 = 0;
}

std::string VL_TO_STRING(const VlClassRef<Vip1_tb___024unit__03a__03atlul_utils>& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vip1_tb___024unit__03a__03atlul_utils::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->to_string() : "null");
}

std::string Vip1_tb___024unit__03a__03atlul_utils::to_string() const {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vip1_tb___024unit__03a__03atlul_utils::to_string\n"); );
    // Body
    return ("'{"s + to_string_middle() + "}");
}

std::string Vip1_tb___024unit__03a__03atlul_utils::to_string_middle() const {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vip1_tb___024unit__03a__03atlul_utils::to_string_middle\n"); );
    // Body
    std::string out;
    out += "drv_if:" + VL_TO_STRING(__PVT__drv_if);
    return (out);
}
