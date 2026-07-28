// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing declarations

#include "verilated_fst_c.h"


void Vtop___024root__traceDeclTypesSub0(VerilatedFst* tracep) {
    {
        const char* __VenumItemNames[]
        = {"PutFullData", "PutPartialData", "Get"};
        const char* __VenumItemValues[]
        = {"0", "1", "100"};
        tracep->declDTypeEnum(1, "tlul_pkg::tl_a_op_e", 3, 3, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"AccessAck", "AccessAckData"};
        const char* __VenumItemValues[]
        = {"0", "1"};
        tracep->declDTypeEnum(2, "tlul_pkg::tl_d_op_e", 2, 3, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"MuBi4True", "MuBi4False"};
        const char* __VenumItemValues[]
        = {"110", "1001"};
        tracep->declDTypeEnum(3, "prim_mubi_pkg::mubi4_t", 2, 4, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"StIdle", "StRun"};
        const char* __VenumItemValues[]
        = {"0", "1"};
        tracep->declDTypeEnum(4, "cordic_core.cordic_state_e", 2, 1, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"SwAccessRW", "SwAccessRO", "SwAccessWO", 
                                "SwAccessW1C", "SwAccessW1S", 
                                "SwAccessW0C", "SwAccessRC"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101", "110"};
        tracep->declDTypeEnum(5, "prim_subreg_pkg::sw_access_e", 7, 3, __VenumItemNames, __VenumItemValues);
    }
}

void Vtop___024root__trace_decl_types(VerilatedFst* tracep) {
    Vtop___024root__traceDeclTypesSub0(tracep);
}
