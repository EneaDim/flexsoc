// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_axi_pkg
constexpr CData/*1:0*/ Vtop_axi_pkg::BURST_FIXED;
constexpr CData/*1:0*/ Vtop_axi_pkg::BURST_INCR;
constexpr CData/*1:0*/ Vtop_axi_pkg::BURST_WRAP;
constexpr CData/*1:0*/ Vtop_axi_pkg::RESP_OKAY;
constexpr CData/*1:0*/ Vtop_axi_pkg::RESP_EXOKAY;
constexpr CData/*1:0*/ Vtop_axi_pkg::RESP_SLVERR;
constexpr CData/*1:0*/ Vtop_axi_pkg::RESP_DECERR;
constexpr CData/*3:0*/ Vtop_axi_pkg::CACHE_BUFFERABLE;
constexpr CData/*3:0*/ Vtop_axi_pkg::CACHE_MODIFIABLE;
constexpr CData/*3:0*/ Vtop_axi_pkg::CACHE_RD_ALLOC;
constexpr CData/*3:0*/ Vtop_axi_pkg::CACHE_WR_ALLOC;
constexpr CData/*5:0*/ Vtop_axi_pkg::ATOP_ATOMICSWAP;
constexpr CData/*5:0*/ Vtop_axi_pkg::ATOP_ATOMICCMP;
constexpr CData/*1:0*/ Vtop_axi_pkg::ATOP_NONE;
constexpr CData/*1:0*/ Vtop_axi_pkg::ATOP_ATOMICSTORE;
constexpr CData/*1:0*/ Vtop_axi_pkg::ATOP_ATOMICLOAD;
constexpr CData/*0:0*/ Vtop_axi_pkg::ATOP_LITTLE_END;
constexpr CData/*0:0*/ Vtop_axi_pkg::ATOP_BIG_END;
constexpr CData/*2:0*/ Vtop_axi_pkg::ATOP_ADD;
constexpr CData/*2:0*/ Vtop_axi_pkg::ATOP_CLR;
constexpr CData/*2:0*/ Vtop_axi_pkg::ATOP_EOR;
constexpr CData/*2:0*/ Vtop_axi_pkg::ATOP_SET;
constexpr CData/*2:0*/ Vtop_axi_pkg::ATOP_SMAX;
constexpr CData/*2:0*/ Vtop_axi_pkg::ATOP_SMIN;
constexpr CData/*2:0*/ Vtop_axi_pkg::ATOP_UMAX;
constexpr CData/*2:0*/ Vtop_axi_pkg::ATOP_UMIN;
constexpr SData/*9:0*/ Vtop_axi_pkg::DemuxAw;
constexpr SData/*9:0*/ Vtop_axi_pkg::DemuxW;
constexpr SData/*9:0*/ Vtop_axi_pkg::DemuxB;
constexpr SData/*9:0*/ Vtop_axi_pkg::DemuxAr;
constexpr SData/*9:0*/ Vtop_axi_pkg::DemuxR;
constexpr SData/*9:0*/ Vtop_axi_pkg::MuxAw;
constexpr SData/*9:0*/ Vtop_axi_pkg::MuxW;
constexpr SData/*9:0*/ Vtop_axi_pkg::MuxB;
constexpr SData/*9:0*/ Vtop_axi_pkg::MuxAr;
constexpr SData/*9:0*/ Vtop_axi_pkg::MuxR;
constexpr IData/*31:0*/ Vtop_axi_pkg::BurstWidth;
constexpr IData/*31:0*/ Vtop_axi_pkg::RespWidth;
constexpr IData/*31:0*/ Vtop_axi_pkg::CacheWidth;
constexpr IData/*31:0*/ Vtop_axi_pkg::ProtWidth;
constexpr IData/*31:0*/ Vtop_axi_pkg::QosWidth;
constexpr IData/*31:0*/ Vtop_axi_pkg::RegionWidth;
constexpr IData/*31:0*/ Vtop_axi_pkg::LenWidth;
constexpr IData/*31:0*/ Vtop_axi_pkg::SizeWidth;
constexpr IData/*31:0*/ Vtop_axi_pkg::LockWidth;
constexpr IData/*31:0*/ Vtop_axi_pkg::AtopWidth;
constexpr IData/*31:0*/ Vtop_axi_pkg::NsaidWidth;
constexpr IData/*31:0*/ Vtop_axi_pkg::ATOP_R_RESP;



Vtop_axi_pkg::Vtop_axi_pkg() = default;
Vtop_axi_pkg::~Vtop_axi_pkg() = default;

void Vtop_axi_pkg::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
}

void Vtop_axi_pkg___configure_coverage(Vtop_axi_pkg* vlSelf, bool first);

void Vtop_axi_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
    Vtop_axi_pkg___configure_coverage(this, first);
}

void Vtop_axi_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}

// Coverage
void Vtop_axi_pkg::__vlCoverInsert(uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
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
void Vtop_axi_pkg::__vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
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
