// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VIP0_TB__SYMS_H_
#define VERILATED_VIP0_TB__SYMS_H_  // guard

#include "verilated.h"
#include "verilated_vcd_c.h"

// INCLUDE MODEL CLASS

#include "Vip0_tb.h"

// INCLUDE MODULE CLASSES
#include "Vip0_tb___024root.h"
#include "Vip0_tb_ip0_tb.h"
#include "Vip0_tb___024unit.h"
#include "Vip0_tb_tlul_if.h"
#include "Vip0_tb_ip0_reg_pkg.h"
#include "Vip0_tb___024unit__03a__03atlul_utils__Vclpkg.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vip0_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vip0_tb* const __Vm_modelp;
    bool __Vm_dumping = false;  // Dumping is active
    VerilatedMutex __Vm_dumperMutex;  // Protect __Vm_dumperp
    VerilatedVcdC* __Vm_dumperp VL_GUARDED_BY(__Vm_dumperMutex) = nullptr;  /// Trace class for $dump*
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vip0_tb___024root              TOP;
    Vip0_tb___024unit__03a__03atlul_utils__Vclpkg TOP____024unit__03a__03atlul_utils__Vclpkg;
    Vip0_tb___024unit              TOP____024unit;
    Vip0_tb_ip0_reg_pkg            TOP__ip0_reg_pkg;
    Vip0_tb_ip0_tb                 TOP__ip0_tb;
    Vip0_tb_tlul_if                TOP__ip0_tb__tl_if;

    // SCOPE NAMES
    VerilatedScope* __Vscopep_ip0_tb__tl_if;
    VerilatedScope* __Vscopep_ip0_tb__u_ip0__u_ip0_reg;
    VerilatedScope* __Vscopep_ip0_tb__u_ip0__u_ip0_reg__u_reg_if__u_err;

    // CONSTRUCTORS
    Vip0_tb__Syms(VerilatedContext* contextp, const char* namep, Vip0_tb* modelp);
    ~Vip0_tb__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
};

#endif  // guard
