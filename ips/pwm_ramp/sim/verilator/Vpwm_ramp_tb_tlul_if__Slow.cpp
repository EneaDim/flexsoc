// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpwm_ramp_tb.h for the primary calling header

#include "Vpwm_ramp_tb__pch.h"
#include "Vpwm_ramp_tb__Syms.h"
#include "Vpwm_ramp_tb_tlul_if.h"

void Vpwm_ramp_tb_tlul_if___ctor_var_reset(Vpwm_ramp_tb_tlul_if* vlSelf);

Vpwm_ramp_tb_tlul_if::Vpwm_ramp_tb_tlul_if(Vpwm_ramp_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vpwm_ramp_tb_tlul_if___ctor_var_reset(this);
}

void Vpwm_ramp_tb_tlul_if::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vpwm_ramp_tb_tlul_if::~Vpwm_ramp_tb_tlul_if() {
}
