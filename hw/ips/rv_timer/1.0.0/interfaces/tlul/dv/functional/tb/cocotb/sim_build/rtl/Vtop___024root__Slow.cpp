// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop___024root
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__FLEXSOC_TL_PUT_FULL;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__FLEXSOC_TL_PUT_PARTIAL;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__FLEXSOC_TL_GET;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__RESVAL;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__Mubi;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__Mubi;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__RESVAL;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__Mubi;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__Mubi;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__RESVAL;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__Mubi;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__Mubi;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__RESVAL;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__Mubi;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__Mubi;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__CmdIntgCheck;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__EnableRspIntgGen;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__EnableDataIntgGen;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__EnableRspIntgGen;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__EnableDataIntgGen;
constexpr CData/*3:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__MaskOne;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__Mubi;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__Mubi;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__Mubi;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__Mubi;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__SwAccess;
constexpr CData/*7:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__RESVAL;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__Mubi;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__Mubi;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__Mubi;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__Mubi;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__RESVAL;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__Mubi;
constexpr CData/*2:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__SwAccess;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__Mubi;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__EnableRspIntgGen;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__EnableDataIntgGen;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__ResetValue;
constexpr CData/*0:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__FlopOutput;
constexpr SData/*11:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__RESVAL;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__AW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__DBW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__RegAw;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__RegDw;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__AccessLatency;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__RegBw;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__IW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__SZW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__IW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__SZW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__MW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__SubAW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__RESVAL;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__RESVAL;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__Width;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__DW;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__N;
constexpr IData/*31:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__Width;
constexpr QData/*39:0*/ Vtop___024root::rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__IntrT;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root___configure_coverage(Vtop___024root* vlSelf, bool first);

void Vtop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
    Vtop___024root___configure_coverage(this, first);
}

Vtop___024root::~Vtop___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}

// Coverage
void Vtop___024root::__vlCoverInsert(uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp,
    const char* fsmVarp, const char* fsmFromp, const char* fsmTop, const char* fsmTagp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    std::string fullhier = std::string{vlNamep} + hierp;
    if (!fullhier.empty() && fullhier[0] == '.') fullhier = fullhier.substr(1);
    if (!enable && !localCounter) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(vlSymsp->_vm_contextp__->coveragep(), vlNamep, count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",fullhier.c_str(),  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp,  (fsmVarp[0] ? "fsm_var" : ""), fsmVarp,  (fsmFromp[0] ? "fsm_from" : ""), fsmFromp,  (fsmTop[0] ? "fsm_to" : ""), fsmTop,  (fsmTagp[0] ? "fsm_tag" : ""), fsmTagp);
}

// Toggle Coverage
void Vtop___024root::__vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp) {
    int step = (end >= begin) ? 1 : -1;
    for (int i = begin; i != end + step; i += step) {
        for (int j = 0; j < 2; j++) {
            uint32_t* count32p = countp;
            static uint32_t fake_zero_count = 0;
            std::string fullhier = std::string{vlNamep} + hierp;
            if (!fullhier.empty() && fullhier[0] == '.') fullhier = fullhier.substr(1);
            std::string commentWithIndex = commentp;
            if (ranged) commentWithIndex += '[' + std::to_string(i) + ']';
            commentWithIndex += j ? ":0->1" : ":1->0";
            if (!enable && !localCounter) count32p = &fake_zero_count;
            *count32p = 0;
            VL_COVER_INSERT(vlSymsp->_vm_contextp__->coveragep(), vlNamep, count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
                "hier",fullhier.c_str(),  "page",pagep,  "comment",commentWithIndex.c_str(),  "", "");
            ++countp;
        }
    }
}
