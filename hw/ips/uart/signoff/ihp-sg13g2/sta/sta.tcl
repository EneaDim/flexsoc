# =============================================================================
# AUTO-GENERATED FLEXSOC OPENSTA ANALYSIS
#
# Analysis : sta
# Design   : uart
# Variant  : dev
# PDK      : ihp-sg13g2
# Stage    : post_syn
# Corner   : ff
# Mode     : hold
# Workload : not applicable
# Top      : uart
#
# Inputs:
#   Liberty       : /home/eneadim/github/flexsoc/.flexsoc/pdks/ihp-sg13g2/ihp-sg13g2/libs.ref/sg13g2_stdcell/lib/sg13g2_stdcell_fast_1p65V_m40C.lib
#   Macro Liberty : not used
#   Netlist       : /home/eneadim/github/flexsoc/workspace/runs/uart/dev/syn/ihp-sg13g2/uart_synth.v
#   SDC           : /home/eneadim/github/flexsoc/workspace/runs/uart/dev/signoff/ihp-sg13g2/uart.sdc
#   SPEF          : not used
#   VCD or SAIF   : not used
#   Activity scope: not used
#   GLS report    : not used
#   Report dir    : /home/eneadim/github/flexsoc/workspace/runs/uart/dev/signoff/ihp-sg13g2/sta/ff/hold
#
# Limitations:
#   - Violating, near-critical and unconstrained paths are separate sections of one report.
#   - Post-synthesis capacitance excludes routed parasitics unless an explicit SPEF is supplied.
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
set report_dir {/home/eneadim/github/flexsoc/workspace/runs/uart/dev/signoff/ihp-sg13g2/sta/ff/hold}
file mkdir $report_dir
set liberty {/home/eneadim/github/flexsoc/.flexsoc/pdks/ihp-sg13g2/ihp-sg13g2/libs.ref/sg13g2_stdcell/lib/sg13g2_stdcell_fast_1p65V_m40C.lib}
set macro_liberties {}
set netlist {/home/eneadim/github/flexsoc/workspace/runs/uart/dev/syn/ihp-sg13g2/uart_synth.v}
set sdc {/home/eneadim/github/flexsoc/workspace/runs/uart/dev/signoff/ihp-sg13g2/uart.sdc}
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

set delay_type min
set endpoint_group_limit 10000
set endpoint_path_limit 10
set near_critical_limit 0.100000
# Create one compact timing report for this corner/mode and write its analysis context first.
set report [file join $report_dir timing.rpt]
set fp [open $report w]
puts $fp "analysis=sta corner=ff mode=hold stage=post_syn"
puts $fp "liberty=$liberty"
puts $fp "netlist=$netlist"
puts $fp "sdc=$sdc"
puts $fp "spef=$spef"
close $fp
flexsoc_section $report Units
# Record the unit system used by all timing, slew, and capacitance values below.
flexsoc_append_opensta $report report_units
flexsoc_section $report {Timing summary}
flexsoc_label $report "wns $delay_type"
# Report worst negative slack for the selected max/setup or min/hold analysis.
flexsoc_append_opensta $report report_wns -$delay_type
flexsoc_label $report "tns $delay_type"
# Report total negative slack across all violating endpoints for this analysis type.
flexsoc_append_opensta $report report_tns -$delay_type
flexsoc_section $report {Constraint validation}
# Append setup diagnostics so missing clocks, unconstrained endpoints, or invalid constraints stay visible.
flexsoc_append_opensta $report check_setup -verbose
# Append electrical and sequential timing checks such as slew, capacitance, fanout, recovery, and removal.
flexsoc_append_opensta $report report_check_types -max_slew -max_capacitance -max_fanout -recovery -removal -min_pulse_width -min_period -min_delay -max_delay
flexsoc_section $report {Violating paths}
# Report the worst violating paths first, including gate slew, capacitance, net, and fanout fields.
flexsoc_append_opensta $report report_checks -path_delay $delay_type -group_path_count $endpoint_group_limit -endpoint_path_count $endpoint_path_limit -unique_paths_to_endpoint -sort_by_slack -slack_max 0.0 -format full_clock_expanded -fields {slew capacitance input_pin net fanout} -digits 6
flexsoc_section $report {Near-critical paths}
# Report met paths close to zero slack so timing margin is visible before it becomes a violation.
flexsoc_append_opensta $report report_checks -path_delay $delay_type -group_path_count 3000 -endpoint_path_count 3 -unique_paths_to_endpoint -sort_by_slack -slack_min 0.0 -slack_max $near_critical_limit -format full_clock_expanded -fields {slew capacitance input_pin net fanout} -digits 6
flexsoc_section $report {Unconstrained paths}
# Report paths with no valid timing requirement; review these instead of treating them as passing timing.
flexsoc_append_opensta $report report_checks -unconstrained -path_delay $delay_type -group_path_count $endpoint_group_limit -endpoint_path_count 1 -sort_by_slack -format full_clock_expanded -fields {slew capacitance input_pin net fanout} -digits 6
puts "report=$report"
puts {FLEXSOC_SIGNOFF_COMPLETE analysis=sta corner=ff mode=hold workload=n/a}
