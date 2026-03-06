# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vip1_tb.mk for the caller.

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
  Vip1_tb \
  Vip1_tb___024root__0 \
  Vip1_tb_ip1_tb__0 \
  Vip1_tb_tlul_if__0 \
  Vip1_tb___024unit__03a__03atlul_utils__Vclpkg__0 \
  Vip1_tb__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
  Vip1_tb___024root__Slow \
  Vip1_tb___024root__0__Slow \
  Vip1_tb_ip1_tb__Slow \
  Vip1_tb_ip1_tb__0__Slow \
  Vip1_tb___024unit__Slow \
  Vip1_tb___024unit__0__Slow \
  Vip1_tb_tlul_if__Slow \
  Vip1_tb_tlul_if__0__Slow \
  Vip1_tb_ip1_reg_pkg__Slow \
  Vip1_tb_ip1_reg_pkg__0__Slow \
  Vip1_tb___024unit__03a__03atlul_utils__Vclpkg__Slow \
  Vip1_tb___024unit__03a__03atlul_utils__Vclpkg__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
  Vip1_tb__Dpi \
  Vip1_tb__Trace__0 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
  Vip1_tb__Syms__Slow \
  Vip1_tb__Trace__0__Slow \
  Vip1_tb__TraceDecls__0__Slow \

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
