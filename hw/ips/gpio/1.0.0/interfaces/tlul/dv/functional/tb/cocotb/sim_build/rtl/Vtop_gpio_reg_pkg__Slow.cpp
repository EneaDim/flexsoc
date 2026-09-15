// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_gpio_reg_pkg
constexpr CData/*3:0*/ Vtop_gpio_reg_pkg::GPIO_DATA_IN_OFFSET;
constexpr CData/*3:0*/ Vtop_gpio_reg_pkg::GPIO_DIRECT_OFFSET;
constexpr CData/*3:0*/ Vtop_gpio_reg_pkg::GPIO_INTR_CTRL_OFFSET;
constexpr CData/*7:0*/ Vtop_gpio_reg_pkg::GPIO_DIRECT_RESVAL;
constexpr IData/*31:0*/ Vtop_gpio_reg_pkg::BlockAw;
constexpr IData/*31:0*/ Vtop_gpio_reg_pkg::NumRegs;
constexpr IData/*31:0*/ Vtop_gpio_reg_pkg::AW;
constexpr IData/*31:0*/ Vtop_gpio_reg_pkg::DW;
constexpr IData/*31:0*/ Vtop_gpio_reg_pkg::DBW;
constexpr VlUnpacked<CData/*3:0*/, 3> Vtop_gpio_reg_pkg::GPIO_PERMIT;



Vtop_gpio_reg_pkg::Vtop_gpio_reg_pkg() = default;
Vtop_gpio_reg_pkg::~Vtop_gpio_reg_pkg() = default;

void Vtop_gpio_reg_pkg::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
}

void Vtop_gpio_reg_pkg___configure_coverage(Vtop_gpio_reg_pkg* vlSelf, bool first);

void Vtop_gpio_reg_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
    Vtop_gpio_reg_pkg___configure_coverage(this, first);
}

void Vtop_gpio_reg_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}

// Coverage
void Vtop_gpio_reg_pkg::__vlCoverInsert(uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
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
void Vtop_gpio_reg_pkg::__vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
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
