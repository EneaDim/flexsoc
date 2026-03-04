// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMY_IP_TB__SYMS_H_
#define VERILATED_VMY_IP_TB__SYMS_H_  // guard

#include "verilated.h"
#include "verilated_vcd_c.h"

// INCLUDE MODEL CLASS

#include "Vmy_ip_tb.h"

// INCLUDE MODULE CLASSES
#include "Vmy_ip_tb___024root.h"
#include "Vmy_ip_tb_my_ip_tb.h"
#include "Vmy_ip_tb___024unit.h"
#include "Vmy_ip_tb_tlul_if.h"
#include "Vmy_ip_tb_my_ip_reg_pkg.h"
#include "Vmy_ip_tb___024unit__03a__03atlul_utils__Vclpkg.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vmy_ip_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vmy_ip_tb* const __Vm_modelp;
    bool __Vm_dumping = false;  // Dumping is active
    VerilatedMutex __Vm_dumperMutex;  // Protect __Vm_dumperp
    VerilatedVcdC* __Vm_dumperp VL_GUARDED_BY(__Vm_dumperMutex) = nullptr;  /// Trace class for $dump*
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vmy_ip_tb___024root            TOP;
    Vmy_ip_tb___024unit__03a__03atlul_utils__Vclpkg TOP____024unit__03a__03atlul_utils__Vclpkg;
    Vmy_ip_tb___024unit            TOP____024unit;
    Vmy_ip_tb_my_ip_reg_pkg        TOP__my_ip_reg_pkg;
    Vmy_ip_tb_my_ip_tb             TOP__my_ip_tb;
    Vmy_ip_tb_tlul_if              TOP__my_ip_tb__tl_if;

    // SCOPE NAMES
    VerilatedScope* __Vscopep_my_ip_tb__tl_if;
    VerilatedScope* __Vscopep_my_ip_tb__u_my_ip__u_my_ip_reg;
    VerilatedScope* __Vscopep_my_ip_tb__u_my_ip__u_my_ip_reg__u_reg_if__u_err;

    // CONSTRUCTORS
    Vmy_ip_tb__Syms(VerilatedContext* contextp, const char* namep, Vmy_ip_tb* modelp);
    ~Vmy_ip_tb__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
};

#endif  // guard
