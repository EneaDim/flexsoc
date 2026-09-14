// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_prim_secded_pkg
constexpr CData/*5:0*/ Vtop_prim_secded_pkg::Secded2216ZeroEcc;
constexpr CData/*5:0*/ Vtop_prim_secded_pkg::Secded2822ZeroEcc;
constexpr CData/*6:0*/ Vtop_prim_secded_pkg::Secded3932ZeroEcc;
constexpr CData/*6:0*/ Vtop_prim_secded_pkg::Secded6457ZeroEcc;
constexpr CData/*7:0*/ Vtop_prim_secded_pkg::Secded7264ZeroEcc;
constexpr CData/*5:0*/ Vtop_prim_secded_pkg::SecdedHamming2216ZeroEcc;
constexpr CData/*6:0*/ Vtop_prim_secded_pkg::SecdedHamming3932ZeroEcc;
constexpr CData/*7:0*/ Vtop_prim_secded_pkg::SecdedHamming7264ZeroEcc;
constexpr CData/*7:0*/ Vtop_prim_secded_pkg::SecdedHamming7668ZeroEcc;
constexpr CData/*5:0*/ Vtop_prim_secded_pkg::SecdedInv2216ZeroEcc;
constexpr CData/*5:0*/ Vtop_prim_secded_pkg::SecdedInv2822ZeroEcc;
constexpr CData/*6:0*/ Vtop_prim_secded_pkg::SecdedInv3932ZeroEcc;
constexpr CData/*6:0*/ Vtop_prim_secded_pkg::SecdedInv6457ZeroEcc;
constexpr CData/*7:0*/ Vtop_prim_secded_pkg::SecdedInv7264ZeroEcc;
constexpr CData/*5:0*/ Vtop_prim_secded_pkg::SecdedInvHamming2216ZeroEcc;
constexpr CData/*6:0*/ Vtop_prim_secded_pkg::SecdedInvHamming3932ZeroEcc;
constexpr CData/*7:0*/ Vtop_prim_secded_pkg::SecdedInvHamming7264ZeroEcc;
constexpr CData/*7:0*/ Vtop_prim_secded_pkg::SecdedInvHamming7668ZeroEcc;
constexpr IData/*21:0*/ Vtop_prim_secded_pkg::Secded2216ZeroWord;
constexpr IData/*27:0*/ Vtop_prim_secded_pkg::Secded2822ZeroWord;
constexpr VlWide<3>/*71:0*/ Vtop_prim_secded_pkg::Secded7264ZeroWord;
constexpr IData/*21:0*/ Vtop_prim_secded_pkg::SecdedHamming2216ZeroWord;
constexpr VlWide<3>/*71:0*/ Vtop_prim_secded_pkg::SecdedHamming7264ZeroWord;
constexpr VlWide<3>/*75:0*/ Vtop_prim_secded_pkg::SecdedHamming7668ZeroWord;
constexpr IData/*21:0*/ Vtop_prim_secded_pkg::SecdedInv2216ZeroWord;
constexpr IData/*27:0*/ Vtop_prim_secded_pkg::SecdedInv2822ZeroWord;
constexpr VlWide<3>/*71:0*/ Vtop_prim_secded_pkg::SecdedInv7264ZeroWord;
constexpr IData/*21:0*/ Vtop_prim_secded_pkg::SecdedInvHamming2216ZeroWord;
constexpr VlWide<3>/*71:0*/ Vtop_prim_secded_pkg::SecdedInvHamming7264ZeroWord;
constexpr VlWide<3>/*75:0*/ Vtop_prim_secded_pkg::SecdedInvHamming7668ZeroWord;
constexpr QData/*38:0*/ Vtop_prim_secded_pkg::Secded3932ZeroWord;
constexpr QData/*63:0*/ Vtop_prim_secded_pkg::Secded6457ZeroWord;
constexpr QData/*38:0*/ Vtop_prim_secded_pkg::SecdedHamming3932ZeroWord;
constexpr QData/*38:0*/ Vtop_prim_secded_pkg::SecdedInv3932ZeroWord;
constexpr QData/*63:0*/ Vtop_prim_secded_pkg::SecdedInv6457ZeroWord;
constexpr QData/*38:0*/ Vtop_prim_secded_pkg::SecdedInvHamming3932ZeroWord;



Vtop_prim_secded_pkg::Vtop_prim_secded_pkg() = default;
Vtop_prim_secded_pkg::~Vtop_prim_secded_pkg() = default;

void Vtop_prim_secded_pkg::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
}

void Vtop_prim_secded_pkg___configure_coverage(Vtop_prim_secded_pkg* vlSelf, bool first);

void Vtop_prim_secded_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
    Vtop_prim_secded_pkg___configure_coverage(this, first);
}

void Vtop_prim_secded_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}

// Coverage
void Vtop_prim_secded_pkg::__vlCoverInsert(uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
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
void Vtop_prim_secded_pkg::__vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
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
