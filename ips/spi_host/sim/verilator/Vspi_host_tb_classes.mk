# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vspi_host_tb.mk for the caller.

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
	Vspi_host_tb \
	Vspi_host_tb___024root__DepSet_h87d1c6d7__0 \
	Vspi_host_tb___024root__DepSet_h5ceb7a50__0 \
	Vspi_host_tb_spi_host_tb__DepSet_h9338b19c__0 \
	Vspi_host_tb_spi_host_tb__DepSet_h92a1b2bf__0 \
	Vspi_host_tb_spi_host_tb__DepSet_h517b8e38__0 \
	Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6__DepSet_hdc468bf6__0 \
	Vspi_host_tb_tlul_if__DepSet_hce916581__0 \
	Vspi_host_tb___024unit__03a__03atlul_utils__Vclpkg__DepSet_he398f9ef__0 \
	Vspi_host_tb___024unit__03a__03atlul_utils__Vclpkg__DepSet_h80b24568__0 \
	Vspi_host_tb__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vspi_host_tb__ConstPool_0 \
	Vspi_host_tb___024root__Slow \
	Vspi_host_tb___024root__DepSet_h87d1c6d7__0__Slow \
	Vspi_host_tb___024root__DepSet_h5ceb7a50__0__Slow \
	Vspi_host_tb_spi_host_tb__Slow \
	Vspi_host_tb_spi_host_tb__DepSet_h92a1b2bf__0__Slow \
	Vspi_host_tb_spi_host_tb__DepSet_h517b8e38__0__Slow \
	Vspi_host_tb___024unit__Slow \
	Vspi_host_tb___024unit__DepSet_hff98b17e__0__Slow \
	Vspi_host_tb_spi_host_reg_pkg__Slow \
	Vspi_host_tb_spi_host_reg_pkg__DepSet_h2c537287__0__Slow \
	Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6__Slow \
	Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6__DepSet_hdc468bf6__0__Slow \
	Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6__DepSet_h935cb76f__0__Slow \
	Vspi_host_tb_tlul_if__Slow \
	Vspi_host_tb_tlul_if__DepSet_hce916581__0__Slow \
	Vspi_host_tb___024unit__03a__03atlul_utils__Vclpkg__Slow \
	Vspi_host_tb___024unit__03a__03atlul_utils__Vclpkg__DepSet_h80b24568__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Vspi_host_tb__Dpi \
	Vspi_host_tb__Trace__0 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vspi_host_tb__Syms \
	Vspi_host_tb__Trace__0__Slow \
	Vspi_host_tb__TraceDecls__0__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_dpi \
	verilated_vcd_c \
	verilated_timing \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
