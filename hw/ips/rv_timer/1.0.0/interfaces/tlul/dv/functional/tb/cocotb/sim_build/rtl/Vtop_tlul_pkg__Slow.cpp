// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_tlul_pkg
constexpr SData/*13:0*/ Vtop_tlul_pkg::TL_D_USER_DEFAULT;
constexpr IData/*23:0*/ Vtop_tlul_pkg::ArbiterImpl;
constexpr IData/*31:0*/ Vtop_tlul_pkg::H2DCmdMaxWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::H2DCmdIntgWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::H2DCmdFullWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::D2HRspMaxWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::D2HRspIntgWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::D2HRspFullWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::DataMaxWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::DataIntgWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::DataFullWidth;
constexpr IData/*31:0*/ Vtop_tlul_pkg::DataWhenInstrError;
constexpr IData/*31:0*/ Vtop_tlul_pkg::DataWhenError;
constexpr IData/*22:0*/ Vtop_tlul_pkg::TL_A_USER_DEFAULT;
constexpr IData/*31:0*/ Vtop_tlul_pkg::BlankedAData;
constexpr VlWide<4>/*108:0*/ Vtop_tlul_pkg::TL_H2D_DEFAULT;
constexpr VlWide<3>/*65:0*/ Vtop_tlul_pkg::TL_D2H_DEFAULT;



Vtop_tlul_pkg::Vtop_tlul_pkg() = default;
Vtop_tlul_pkg::~Vtop_tlul_pkg() = default;

void Vtop_tlul_pkg::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
}

void Vtop_tlul_pkg___configure_coverage(Vtop_tlul_pkg* vlSelf, bool first);

void Vtop_tlul_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
    Vtop_tlul_pkg___configure_coverage(this, first);
}

void Vtop_tlul_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}

// Coverage
void Vtop_tlul_pkg::__vlCoverInsert(uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
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
void Vtop_tlul_pkg::__vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
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
