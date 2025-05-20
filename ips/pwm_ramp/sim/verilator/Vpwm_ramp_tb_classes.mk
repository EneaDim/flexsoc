# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vpwm_ramp_tb.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 1
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 0
# Tracing output mode?  0/1 (from --trace-fst/--trace-saif/--trace-vcd)
VM_TRACE = 1
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0
# Tracing output mode in SAIF format?  0/1 (from --trace-saif)
VM_TRACE_SAIF = 0
# Tracing output mode in VCD format?  0/1 (from --trace-vcd)
VM_TRACE_VCD = 1

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vpwm_ramp_tb \
	Vpwm_ramp_tb___024root__DepSet_h50cbdf05__0 \
	Vpwm_ramp_tb___024root__DepSet_heeec2741__0 \
	Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6__DepSet_he49adf2b__0 \
	Vpwm_ramp_tb__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vpwm_ramp_tb__ConstPool_0 \
	Vpwm_ramp_tb___024root__Slow \
	Vpwm_ramp_tb___024root__DepSet_h50cbdf05__0__Slow \
	Vpwm_ramp_tb___024root__DepSet_heeec2741__0__Slow \
	Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6__Slow \
	Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6__DepSet_he49adf2b__0__Slow \
	Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6__DepSet_h82bd276b__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Vpwm_ramp_tb__Trace__0 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vpwm_ramp_tb__Syms \
	Vpwm_ramp_tb__Trace__0__Slow \
	Vpwm_ramp_tb__TraceDecls__0__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_vcd_c \
	verilated_timing \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
