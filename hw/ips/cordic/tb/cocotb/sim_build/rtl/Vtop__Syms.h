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
#include "Vtop_prim_alert_pkg.h"
#include "Vtop_cordic_lut_pkg.h"
#include "Vtop_cordic_reg_pkg.h"
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
    Vtop_cordic_lut_pkg            TOP__cordic_lut_pkg;
    Vtop_cordic_reg_pkg            TOP__cordic_reg_pkg;
    Vtop_prim_alert_pkg            TOP__prim_alert_pkg;
    Vtop_prim_mubi_pkg             TOP__prim_mubi_pkg;
    Vtop_prim_secded_pkg           TOP__prim_secded_pkg;
    Vtop_tlul_pkg                  TOP__tlul_pkg;
    Vtop_top_pkg                   TOP__top_pkg;

    // SCOPE NAMES
    VerilatedScope* __Vscopep_cordic_lut_pkg;
    VerilatedScope* __Vscopep_cordic_reg_pkg;
    VerilatedScope* __Vscopep_cordic_tb;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_core;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_core__u_start_edge_detect;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_core__u_start_edge_detect__u_sync_1;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_core__unnamedblk1;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_core__unnamedblk2;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_cfg_data_width;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_cfg_frac_width;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_cfg_max_iter;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_cfg_rsvd;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_mode;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_mode__wr_en_data_arb;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_mode__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_n_iter;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_n_iter__wr_en_data_arb;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_n_iter__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_rsvd;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_rsvd2;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_rsvd2__wr_en_data_arb;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_rsvd2__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_rsvd__wr_en_data_arb;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_rsvd__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_soft_rst;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_soft_rst__wr_en_data_arb;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_soft_rst__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_start;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_start__wr_en_data_arb;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_ctrl_start__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_reg_if;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_reg_if__u_err;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_reg_if__u_rsp_intg_gen;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_rsp_intg_gen;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_status_busy;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_status_error;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_status_rsvd;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_status_valid;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_x_in;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_x_in__wr_en_data_arb;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_x_in__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_x_out;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_y_in;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_y_in__wr_en_data_arb;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_y_in__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_y_out;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_z_in;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_z_in__wr_en_data_arb;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_z_in__wr_en_data_arb__gen_w;
    VerilatedScope* __Vscopep_cordic_tb__u_cordic__u_cordic_reg__u_z_out;
    VerilatedScope* __Vscopep_cordic_tb__unnamedblk1;
    VerilatedScope* __Vscopep_prim_alert_pkg;
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
