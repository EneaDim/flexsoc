// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_RV_TIMER_REG_PKG_H_
#define VERILATED_VTOP_RV_TIMER_REG_PKG_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"
#include "verilated_covergroup.h"
#include "verilated_timing.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_rv_timer_reg_pkg final {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr CData/*4:0*/ RV_TIMER_CTRL_OFFSET = 0U;
    static constexpr CData/*4:0*/ RV_TIMER_INTR_ENABLE0_OFFSET = 4U;
    static constexpr CData/*4:0*/ RV_TIMER_INTR_STATE0_OFFSET = 8U;
    static constexpr CData/*4:0*/ RV_TIMER_INTR_TEST0_OFFSET = 0x0cU;
    static constexpr CData/*4:0*/ RV_TIMER_CFG0_OFFSET = 0x10U;
    static constexpr CData/*4:0*/ RV_TIMER_TIMER_V0_OFFSET = 0x14U;
    static constexpr CData/*4:0*/ RV_TIMER_COMPARE_V0_OFFSET = 0x18U;
    static constexpr CData/*0:0*/ RV_TIMER_INTR_TEST0_RESVAL = 0U;
    static constexpr IData/*31:0*/ N_HARTS = 1U;
    static constexpr IData/*31:0*/ N_TIMERS = 1U;
    static constexpr IData/*31:0*/ BlockAw = 5U;
    static constexpr IData/*31:0*/ AW = 5U;
    static constexpr IData/*31:0*/ DW = 0x00000020U;
    static constexpr IData/*31:0*/ DBW = 4U;
    static constexpr VlUnpacked<CData/*3:0*/, 7> RV_TIMER_PERMIT = {{
        1U, 1U, 1U, 1U, 7U, 0x0fU, 0x0fU
    }};

    // CONSTRUCTORS
    Vtop_rv_timer_reg_pkg();
    ~Vtop_rv_timer_reg_pkg();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_rv_timer_reg_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp,
        const char* fsmVarp, const char* fsmFromp, const char* fsmTop, const char* fsmTagp);
    void __vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp);
};


#endif  // guard
