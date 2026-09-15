// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_GPIO_REG_PKG_H_
#define VERILATED_VTOP_GPIO_REG_PKG_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"
#include "verilated_covergroup.h"
#include "verilated_timing.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_gpio_reg_pkg final {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr CData/*3:0*/ GPIO_DATA_IN_OFFSET = 0U;
    static constexpr CData/*3:0*/ GPIO_DIRECT_OFFSET = 4U;
    static constexpr CData/*3:0*/ GPIO_INTR_CTRL_OFFSET = 8U;
    static constexpr CData/*7:0*/ GPIO_DIRECT_RESVAL = 0U;
    static constexpr IData/*31:0*/ BlockAw = 4U;
    static constexpr IData/*31:0*/ NumRegs = 3U;
    static constexpr IData/*31:0*/ AW = 4U;
    static constexpr IData/*31:0*/ DW = 0x00000020U;
    static constexpr IData/*31:0*/ DBW = 4U;
    static constexpr VlUnpacked<CData/*3:0*/, 3> GPIO_PERMIT = {{
        1U, 1U, 7U
    }};

    // CONSTRUCTORS
    Vtop_gpio_reg_pkg();
    ~Vtop_gpio_reg_pkg();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_gpio_reg_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp,
        const char* fsmVarp, const char* fsmFromp, const char* fsmTop, const char* fsmTagp);
    void __vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp);
};


#endif  // guard
