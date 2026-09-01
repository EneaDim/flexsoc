// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"
#include "verilated_fst_c.h"

// INCLUDE MODEL CLASS

#include "Vtop.h"

// INCLUDE MODULE CLASSES
#include "Vtop___024root.h"
#include "Vtop_top_pkg.h"
#include "Vtop_prim_secded_pkg.h"
#include "Vtop_rv_timer_reg_pkg.h"
#include "Vtop_prim_mubi_pkg.h"
#include "Vtop_tlul_pkg.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop* const __Vm_modelp;
    bool __Vm_dumping = false;  // Dumping is active
    VerilatedMutex __Vm_dumperMutex;  // Protect __Vm_dumperp
    VerilatedFstC* __Vm_dumperp VL_GUARDED_BY(__Vm_dumperMutex) = nullptr;  /// Trace class for $dump*
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;
    Vtop_prim_mubi_pkg             TOP__prim_mubi_pkg;
    Vtop_prim_secded_pkg           TOP__prim_secded_pkg;
    Vtop_rv_timer_reg_pkg          TOP__rv_timer_reg_pkg;
    Vtop_tlul_pkg                  TOP__tlul_pkg;
    Vtop_top_pkg                   TOP__top_pkg;

    // COVERAGE
    uint32_t __Vcoverage[11008];

    // SCOPE NAMES
    VerilatedScope* __Vscopep_prim_mubi_pkg;
    VerilatedScope* __Vscopep_prim_secded_pkg;
    VerilatedScope* __Vscopep_rv_timer_reg_pkg;
    VerilatedScope* __Vscopep_rv_timer_tb;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__gen_harts__BRA__0__KET__;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__gen_harts__BRA__0__KET____u_core;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__gen_harts__BRA__0__KET____u_intr_hw;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__gen_harts__BRA__0__KET____u_intr_hw__g_intr_event;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_cfg0_prescale;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_cfg0_prescale__wr_en_data_arb;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_cfg0_prescale__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_cfg0_step;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_cfg0_step__wr_en_data_arb;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_cfg0_step__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_compare_v0;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_compare_v00_qe;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_compare_v0__wr_en_data_arb;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_compare_v0__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_ctrl_active_0;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_ctrl_active_0__wr_en_data_arb;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_ctrl_active_0__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_ctrl_gpio_intr_0_0;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_ctrl_gpio_intr_0_0__wr_en_data_arb;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_ctrl_gpio_intr_0_0__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_ctrl_gpio_intr_1_0;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_ctrl_gpio_intr_1_0__wr_en_data_arb;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_ctrl_gpio_intr_1_0__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_intr_enable0;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_intr_enable0__wr_en_data_arb;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_intr_enable0__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_intr_state0;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_intr_state0__wr_en_data_arb;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_intr_test0;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_reg_if;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_reg_if__u_err;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_reg_if__u_rsp_intg_gen;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_rsp_intg_gen;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_timer_v0;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_timer_v0__wr_en_data_arb;
    VerilatedScope* __Vscopep_rv_timer_tb__u_rv_timer__u_reg__u_timer_v0__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_tlul_pkg;
    VerilatedScope* __Vscopep_top_pkg;

    // SCOPE HIERARCHY
    VerilatedHierarchy __Vhier;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
};

#endif  // guard
