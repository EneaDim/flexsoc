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
#include "Vtop_prim_util_pkg.h"
#include "Vtop_gpio_reg_pkg.h"
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
    Vtop_gpio_reg_pkg              TOP__gpio_reg_pkg;
    Vtop_prim_mubi_pkg             TOP__prim_mubi_pkg;
    Vtop_prim_secded_pkg           TOP__prim_secded_pkg;
    Vtop_tlul_pkg                  TOP__tlul_pkg;
    Vtop_top_pkg                   TOP__top_pkg;

    // COVERAGE
    uint32_t __Vcoverage[9049];

    // SCOPE NAMES
    VerilatedScope* __Vscopep_gpio_reg_pkg;
    VerilatedScope* __Vscopep_gpio_tb;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_core_reset_sync;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_core_reset_sync__u_sync_1;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_core_reset_sync__u_sync_2;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__0__KET__;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__0__KET____u_filter;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__0__KET____u_filter__gen_async;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__0__KET____u_filter__gen_async__prim_flop_2sync;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__0__KET____u_filter__gen_async__prim_flop_2sync__u_sync_1;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__0__KET____u_filter__gen_async__prim_flop_2sync__u_sync_2;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__1__KET__;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__1__KET____u_filter;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__1__KET____u_filter__gen_async;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__1__KET____u_filter__gen_async__prim_flop_2sync;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__1__KET____u_filter__gen_async__prim_flop_2sync__u_sync_1;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__1__KET____u_filter__gen_async__prim_flop_2sync__u_sync_2;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__2__KET__;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__2__KET____u_filter;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__2__KET____u_filter__gen_async;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__2__KET____u_filter__gen_async__prim_flop_2sync;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__2__KET____u_filter__gen_async__prim_flop_2sync__u_sync_1;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__2__KET____u_filter__gen_async__prim_flop_2sync__u_sync_2;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__3__KET__;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__3__KET____u_filter;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__3__KET____u_filter__gen_async;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__3__KET____u_filter__gen_async__prim_flop_2sync;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__3__KET____u_filter__gen_async__prim_flop_2sync__u_sync_1;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__gen_input_filter__BRA__3__KET____u_filter__gen_async__prim_flop_2sync__u_sync_2;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__u_filter_reset_branch;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_core__u_state_reset_branch;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_flexsoc_tlul_to_reg;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_flexsoc_tlul_to_reg__u_err;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_flexsoc_tlul_to_reg__u_rsp_intg_gen;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_data_in;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_data_in__wr_en_data_arb;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_data_in__wr_en_data_arb__gen_ro;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_direct_gpio_o;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_direct_gpio_oe;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_intr_ctrl_en_falling;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_intr_ctrl_en_falling__wr_en_data_arb;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_intr_ctrl_en_falling__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_intr_ctrl_en_input_filter;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_intr_ctrl_en_input_filter__wr_en_data_arb;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_intr_ctrl_en_input_filter__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_intr_ctrl_en_lvlhigh;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_intr_ctrl_en_lvlhigh__wr_en_data_arb;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_intr_ctrl_en_lvlhigh__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_intr_ctrl_en_lvllow;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_intr_ctrl_en_lvllow__wr_en_data_arb;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_intr_ctrl_en_lvllow__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_intr_ctrl_en_rising;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_intr_ctrl_en_rising__wr_en_data_arb;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_intr_ctrl_en_rising__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_prim_reg_we_check;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_prim_reg_we_check__u_prim_buf;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__0__KET__;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__0__KET____gen_level__BRA__0__KET__;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__1__KET__;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__1__KET____gen_level__BRA__0__KET__;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__1__KET____gen_level__BRA__1__KET__;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__2__KET__;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__2__KET____gen_level__BRA__0__KET__;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__2__KET____gen_level__BRA__1__KET__;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__2__KET____gen_level__BRA__2__KET__;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_gpio_reg__u_reg_core__u_prim_reg_we_check__u_prim_onehot_check__gen_tree__BRA__2__KET____gen_level__BRA__3__KET__;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_reg_reset_sync;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_reg_reset_sync__u_sync_1;
    VerilatedScope* __Vscopep_gpio_tb__u_gpio__u_reg_reset_sync__u_sync_2;
    VerilatedScope* __Vscopep_prim_mubi_pkg;
    VerilatedScope* __Vscopep_prim_secded_pkg;
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
