# =============================================================================
# AUTO-GENERATED FLEXSOC OPENSTA ANALYSIS
#
# Analysis : fusion_analysis
# Design   : cordic
# Variant  : dev
# PDK      : ihp-sg13g2
# Stage    : post_syn
# Corner   : ff
# Mode     : hold
# Workload : smoke_zero_sv_typ
# Top      : cordic
#
# Inputs:
#   Liberty       : /home/eneadim/github/flexsoc/.flexsoc/pdks/ihp-sg13g2/ihp-sg13g2/libs.ref/sg13g2_stdcell/lib/sg13g2_stdcell_fast_1p65V_m40C.lib
#   Macro Liberty : not used
#   Netlist       : /home/eneadim/github/flexsoc/workspace/cordic-full-flow/runs/cordic/dev/syn/ihp-sg13g2/cordic_synth.v
#   SDC           : /home/eneadim/github/flexsoc/workspace/cordic-full-flow/runs/cordic/dev/signoff/ihp-sg13g2/cordic.sdc
#   SPEF          : not used
#   VCD or SAIF   : /home/eneadim/github/flexsoc/workspace/cordic-full-flow/runs/cordic/dev/signoff/ihp-sg13g2/power/activity/captures/cordic_ihp-sg13g2_smoke_zero_sv_typ.vcd
#   Activity scope: cordic_tb/u_cordic
#   GLS report    : /home/eneadim/github/flexsoc/workspace/cordic-full-flow/runs/cordic/dev/dv/functional/sim/post_syn/ihp-sg13g2/cordic_post_syn_smoke_zero_sv_typ.json
#   Report dir    : /home/eneadim/github/flexsoc/workspace/cordic-full-flow/runs/cordic/dev/signoff/ihp-sg13g2/fusion/smoke_zero_sv_typ/ff/hold
#
# Limitations:
#   - Timing and average power use the same netlist, corner, mode and activity trace.
#   - Per-cell values are average instance power, not incremental path energy.
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
set report_dir {/home/eneadim/github/flexsoc/workspace/cordic-full-flow/runs/cordic/dev/signoff/ihp-sg13g2/fusion/smoke_zero_sv_typ/ff/hold}
file mkdir $report_dir
set liberty {/home/eneadim/github/flexsoc/.flexsoc/pdks/ihp-sg13g2/ihp-sg13g2/libs.ref/sg13g2_stdcell/lib/sg13g2_stdcell_fast_1p65V_m40C.lib}
set macro_liberties {}
set netlist {/home/eneadim/github/flexsoc/workspace/cordic-full-flow/runs/cordic/dev/syn/ihp-sg13g2/cordic_synth.v}
set sdc {/home/eneadim/github/flexsoc/workspace/cordic-full-flow/runs/cordic/dev/signoff/ihp-sg13g2/cordic.sdc}
set spef {}
set top {cordic}
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

puts "=== Step 7/7: Read activity ==="
set activity_file {/home/eneadim/github/flexsoc/workspace/cordic-full-flow/runs/cordic/dev/signoff/ihp-sg13g2/power/activity/captures/cordic_ihp-sg13g2_smoke_zero_sv_typ.vcd}
set activity_scope {cordic_tb/u_cordic}
flexsoc_require_readable "activity VCD/SAIF" $activity_file
puts "activity_file=$activity_file"
puts "activity_scope=$activity_scope"
# Select the public activity reader from the trace extension.
set activity_ext [string tolower [file extension $activity_file]]
if {$activity_ext eq ".saif"} {
  # Annotate averaged switching activity from SAIF at the GLS hierarchy scope.
  read_saif -scope $activity_scope $activity_file
} elseif {$activity_ext eq ".vcd"} {
  # Annotate signal transitions from the GLS VCD at the matching hierarchy scope.
  read_vcd -scope $activity_scope $activity_file
} else {
  puts stderr "ERROR: activity file must be VCD or SAIF: $activity_file"
  exit 2
}

set delay_type min
set endpoint_path_limit 10
# Create the discovery report that keeps timing and power in the same netlist/corner/mode/activity context.
set report [file join $report_dir fusion.rpt]
set fp [open $report w]
puts $fp "analysis=fusion_analysis corner=ff mode=hold stage=post_syn"
puts $fp "workload=smoke_zero_sv_typ"
puts $fp "methodology=staged_public_opensta"
puts $fp "path_power_semantics=average_instance_power_in_same_analysis_context"
puts $fp "activity_file=/home/eneadim/github/flexsoc/workspace/cordic-full-flow/runs/cordic/dev/signoff/ihp-sg13g2/power/activity/captures/cordic_ihp-sg13g2_smoke_zero_sv_typ.vcd"
puts $fp "activity_scope=cordic_tb/u_cordic"
puts $fp "liberty=$liberty"
puts $fp "netlist=$netlist"
puts $fp "sdc=$sdc"
puts $fp "spef=$spef"
close $fp
flexsoc_section $report Units
# Record units once so timing and power values can be interpreted together.
flexsoc_append_opensta $report report_units
flexsoc_section $report {Constraint validation}
# Re-check the timing setup before correlating paths with power.
flexsoc_append_opensta $report check_setup -verbose
flexsoc_section $report {Timing summary}
flexsoc_label $report "wns $delay_type"
# Record worst negative slack for this setup/hold mode.
flexsoc_append_opensta $report report_wns -$delay_type
flexsoc_label $report "tns $delay_type"
# Record total negative slack for the same mode and corner.
flexsoc_append_opensta $report report_tns -$delay_type
flexsoc_section $report {Power summary}
# Report design-average power using the already annotated GLS activity trace.
flexsoc_append_opensta $report report_power
flexsoc_section $report {Worst timing paths (violated or met)}
# Discover the worst paths even when timing is met; Python later correlates their gates with instance power.
flexsoc_append_opensta $report report_checks -path_delay $delay_type -group_path_count $endpoint_path_limit -endpoint_path_count 1 -unique_paths_to_endpoint -sort_by_slack -format full_clock_expanded -fields {slew capacitance input_pin net fanout} -digits 6
# Discover the highest-power instances into a transient machine-parsed report used by the second fusion pass.
set highest_power_report [file join $report_dir .highest_power.rpt]
file delete -force $highest_power_report
flexsoc_append_opensta $highest_power_report report_power -highest_power_instances 20 -digits 12
puts "report=$report"
puts {FLEXSOC_SIGNOFF_COMPLETE analysis=fusion_analysis corner=ff mode=hold workload=smoke_zero_sv_typ}
