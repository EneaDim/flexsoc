# =============================================================================
# AUTO-GENERATED FLEXSOC OPENSTA ANALYSIS
#
# Analysis : power_estimate
# Design   : uart
# Variant  : dev
# PDK      : sky130
# Stage    : post_syn
# Corner   : tt
# Mode     : not applicable
# Workload : not applicable
# Top      : uart
#
# Inputs:
#   Liberty       : /home/eneadim/github/flexsoc/.flexsoc/pdks/ciel/sky130/versions/f6eeac7dad085ffcc829ccfd721f7b4ce39edcf7/sky130A/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_100C_1v80.lib
#   Macro Liberty : not used
#   Netlist       : /tmp/flexsoc-repack/uart/runs/uart/dev/syn/sky130/uart_synth.v
#   SDC           : /tmp/flexsoc-repack/uart/runs/uart/dev/constraints/uart.sdc
#   SPEF          : not used
#   VCD or SAIF   : not used
#   Activity scope: not used
#   GLS report    : not used
#   Report dir    : /tmp/flexsoc-repack/uart/runs/uart/dev/signoff/sky130/power/estimate/template_reports
#
# Limitations:
#   - This is a vectorless estimate; it does not represent a simulated workload.
#   - Activity is assigned to primary inputs and propagated unless global activity is requested.
#
# Generated baseline: review or edit as needed; regeneration replaces this file.
# =============================================================================

# -----------------------------------------------------------------------------
# Runtime validation and common OpenSTA initialization
#
# Each required input is checked before OpenSTA reads it.  The resulting linked
# network associates netlist instances and pins with Liberty timing arcs,
# sequential checks and power models.  A link failure normally identifies a
# missing standard-cell or macro Liberty view.
# -----------------------------------------------------------------------------
proc flexsoc_require_readable {label path} {
  if {![file exists $path] || ![file readable $path]} {
    puts stderr "ERROR: missing or unreadable $label: $path"
    exit 2
  }
}
set report_dir {/tmp/flexsoc-repack/uart/runs/uart/dev/signoff/sky130/power/estimate/template_reports}
file mkdir $report_dir
set liberty {/home/eneadim/github/flexsoc/.flexsoc/pdks/ciel/sky130/versions/f6eeac7dad085ffcc829ccfd721f7b4ce39edcf7/sky130A/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_100C_1v80.lib}
set macro_liberties {}
set netlist {/tmp/flexsoc-repack/uart/runs/uart/dev/syn/sky130/uart_synth.v}
set sdc {/tmp/flexsoc-repack/uart/runs/uart/dev/constraints/uart.sdc}
set spef {}
set top {uart}
set stage {post_syn}
# Validate every file referenced by this script before building the timing graph.
flexsoc_require_readable "standard-cell Liberty" $liberty
flexsoc_require_readable "gate-level netlist" $netlist
flexsoc_require_readable "SDC constraints" $sdc
foreach macro_lib $macro_liberties {flexsoc_require_readable "macro Liberty" $macro_lib}
if {$spef ne ""} {flexsoc_require_readable "SPEF parasitics" $spef}

puts "=== Step 1/7: Read Liberty ==="
puts "liberty=$liberty"
# Load the standard-cell Liberty view for this PVT corner; it supplies timing arcs, checks, and cell power data.
read_liberty $liberty
foreach macro_lib $macro_liberties {
  puts "macro_liberty=$macro_lib"
  # Load each macro Liberty view so hard macros participate in timing and power analysis.
  read_liberty $macro_lib
}

puts "=== Step 2/7: Read netlist ==="
puts "netlist=$netlist"
# Read the mapped gate-level Verilog netlist that will be analyzed.
read_verilog $netlist

puts "=== Step 3/7: Link design ==="
puts "top=$top"
# Link the selected top and resolve every netlist cell against the loaded Liberty views.
link_design $top

puts "=== Step 4/7: Read SDC ==="
puts "sdc=$sdc"
# Apply clocks, I/O delays, uncertainties, exceptions, and electrical constraints from the SDC.
read_sdc $sdc

puts "=== Step 5/7: Read parasitics / establish clock model ==="
if {$spef ne ""} {
  puts "spef=$spef"
  # Annotate extracted RC parasitics so interconnect delay and capacitance are included.
  read_spef $spef
} else {
  puts "spef=not_used"
}
if {$stage eq "post_route"} {
  # Collect all SDC clocks before switching post-route analysis to propagated clock latency.
  set clocks [get_clocks *]
  if {[llength $clocks] > 0} {
    # Propagate clock-tree delay through the linked network instead of assuming ideal clocks.
    set_propagated_clock $clocks
  }
  puts "clock_model=propagated"
} else {
  puts "clock_model=ideal post_synthesis"
}
proc flexsoc_section {path title} {
  set fp [open $path a]
  puts $fp ""
  puts $fp "=== $title ==="
  close $fp
}
proc flexsoc_label {path label} {
  set fp [open $path a]
  puts -nonewline $fp "$label "
  close $fp
}
proc flexsoc_append_opensta {path args} {
  # Capture one public OpenSTA report command without relying on command-specific > / >> support.
  set capture [file join [file dirname $path] .flexsoc_opensta_capture.rpt]
  file delete -force $capture
  log_begin $capture
  set code [catch {uplevel 1 $args} result options]
  log_end
  if {[file exists $capture]} {
    set src [open $capture r]
    set dst [open $path a]
    fcopy $src $dst
    close $src
    close $dst
    file delete -force $capture
  }
  if {$code != 0} {return -options $options $result}
  return $result
}

puts "=== Step 6/7: Validate timing setup ==="
# Validate clocks, endpoints, constraints, and timing relationships before generating reports.
check_setup -verbose

puts "=== Step 7/7: Analysis-specific reporting ==="

# Seed vectorless switching activity on primary inputs (or globally) and let OpenSTA propagate it through the design.
set_power_activity -input -activity 0.1 -duty 0.5
# Create one compact vectorless power report and record the assumptions used to produce it.
set report [file join $report_dir power.rpt]
set fp [open $report w]
puts $fp "analysis=power_estimate activity_source=input_assumption"
puts $fp "activity_model=input"
puts $fp "activity=0.1"
puts $fp "duty=0.5"
puts $fp "corner=tt stage=post_syn"
puts $fp "liberty=$liberty"
puts $fp "netlist=$netlist"
puts $fp "sdc=$sdc"
puts $fp "spef=$spef"
close $fp
flexsoc_section $report Units
# Record the unit system used by the power and activity values below.
flexsoc_append_opensta $report report_units
flexsoc_section $report {Constraint validation}
# Append timing-setup diagnostics because power must use the same correctly linked and constrained design.
flexsoc_append_opensta $report check_setup -verbose
flexsoc_section $report {Power summary}
# Report average internal, switching, leakage, and total cell power for the complete design.
flexsoc_append_opensta $report report_power
puts "report=$report"
puts {FLEXSOC_SIGNOFF_COMPLETE analysis=power_estimate corner=tt mode=n/a workload=n/a}
