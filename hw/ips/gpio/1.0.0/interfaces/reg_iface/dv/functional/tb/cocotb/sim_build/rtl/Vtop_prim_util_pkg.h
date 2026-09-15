// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_PRIM_UTIL_PKG_H_
#define VERILATED_VTOP_PRIM_UTIL_PKG_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"
#include "verilated_covergroup.h"
#include "verilated_timing.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_prim_util_pkg final {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;
    uint32_t __Vcoverage[5]{};

    // CONSTRUCTORS
    Vtop_prim_util_pkg();
    ~Vtop_prim_util_pkg();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_prim_util_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp,
        const char* fsmVarp, const char* fsmFromp, const char* fsmTop, const char* fsmTagp);
    void __vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp);
};


#endif  // guard
