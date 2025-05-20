# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vpwm_ramp.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 0
# Tracing output mode?  0/1 (from --trace-fst/--trace-saif/--trace-vcd)
VM_TRACE = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0
# Tracing output mode in SAIF format?  0/1 (from --trace-saif)
VM_TRACE_SAIF = 0
# Tracing output mode in VCD format?  0/1 (from --trace-vcd)
VM_TRACE_VCD = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vpwm_ramp \
	Vpwm_ramp___024root__DepSet_ha4ca8807__0 \
	Vpwm_ramp___024root__DepSet_h24c76655__0 \
	Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6__DepSet_hd80b497c__0 \
	Vpwm_ramp__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vpwm_ramp___024root__Slow \
	Vpwm_ramp___024root__DepSet_ha4ca8807__0__Slow \
	Vpwm_ramp___024root__DepSet_h24c76655__0__Slow \
	Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6__Slow \
	Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6__DepSet_hd80b497c__0__Slow \
	Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6__DepSet_he886254e__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vpwm_ramp__Syms \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
