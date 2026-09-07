# =============================================================================
# AUTO-GENERATED FLEXSOC OPENSTA ANALYSIS
#
# Analysis : power_analysis
# Design   : gpio
# Variant  : dev
# PDK      : ihp-sg13g2
# Stage    : post_syn
# Corner   : tt
# Mode     : not applicable
# Workload : GLS_WORKLOAD_REQUIRED
# Top      : gpio
#
# Inputs:
#   Liberty       : /home/eneadim/github/flexsoc/.flexsoc/pdks/ihp-sg13g2/ihp-sg13g2/libs.ref/sg13g2_stdcell/lib/sg13g2_stdcell_typ_1p50V_25C.lib
#   Macro Liberty : not used
#   Netlist       : /tmp/flexsoc-repack/gpio/runs/gpio/dev/syn/ihp-sg13g2/gpio_synth.v
#   SDC           : /tmp/flexsoc-repack/gpio/runs/gpio/dev/constraints/gpio.sdc
#   SPEF          : not used
#   VCD or SAIF   : /tmp/flexsoc-repack/gpio/runs/gpio/dev/signoff/ihp-sg13g2/power/activity/ACTIVITY_REQUIRED.vcd
#   Activity scope: DUT_SCOPE_REQUIRED
#   GLS report    : /tmp/flexsoc-repack/gpio/runs/gpio/dev/signoff/ihp-sg13g2/power/activity/GLS_REPORT_REQUIRED.json
#   Report dir    : /tmp/flexsoc-repack/gpio/runs/gpio/dev/signoff/ihp-sg13g2/power/analysis/template_reports
#
# Limitations:
#   - Power is average cell power derived from the selected Liberty models and annotated activity.
#   - Unannotated objects and scope mismatches remain visible in the activity section.
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
set report_dir {/tmp/flexsoc-repack/gpio/runs/gpio/dev/signoff/ihp-sg13g2/power/analysis/template_reports}
file mkdir $report_dir
set liberty {/home/eneadim/github/flexsoc/.flexsoc/pdks/ihp-sg13g2/ihp-sg13g2/libs.ref/sg13g2_stdcell/lib/sg13g2_stdcell_typ_1p50V_25C.lib}
set macro_liberties {}
set netlist {/tmp/flexsoc-repack/gpio/runs/gpio/dev/syn/ihp-sg13g2/gpio_synth.v}
set sdc {/tmp/flexsoc-repack/gpio/runs/gpio/dev/constraints/gpio.sdc}
set spef {}
set top {gpio}
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
proc flexsoc_append_activity_coverage {path} {
  # Keep activity evidence compact: percentage plus only the pins that were not annotated.
  set capture [file join [file dirname $path] .flexsoc_activity_annotation.rpt]
  file delete -force $capture
  log_begin $capture
  set code [catch {report_activity_annotation -report_unannotated} result options]
  log_end
  if {$code != 0} {
    file delete -force $capture
    return -options $options $result
  }
  if {![file exists $capture]} {error {activity annotation report was not captured}}
  set src [open $capture r]
  set text [read $src]
  close $src
  file delete -force $capture
  set annotated 0
  set unannotated 0
  set have_annotated 0
  set have_unannotated 0
  set in_unannotated 0
  set unannotated_pins {}
  foreach line [split $text "\n"] {
    if {[regexp {^[[:space:]]*(vcd|saif|input)[[:space:]]+([0-9]+)[[:space:]]*$} $line -> origin count]} {
      incr annotated $count
      set have_annotated 1
      continue
    }
    if {[regexp {^[[:space:]]*unannotated[[:space:]]+([0-9]+)[[:space:]]*$} $line -> count]} {
      set unannotated $count
      set have_unannotated 1
      continue
    }
    if {[regexp -nocase {^[[:space:]]*Annotated[[:space:]]+([0-9]+).*activities} $line -> count]} {
      set annotated $count
      set have_annotated 1
      continue
    }
    if {[regexp -nocase {^[[:space:]]*Unannotated[[:space:]]+([0-9]+).*activities} $line -> count]} {
      set unannotated $count
      set have_unannotated 1
      continue
    }
    if {[regexp {^Unannotated pins:[[:space:]]*$} $line]} {
      set in_unannotated 1
      continue
    }
    if {$in_unannotated && [string trim $line] ne ""} {lappend unannotated_pins [string trim $line]}
  }
  if {!$have_annotated || !$have_unannotated} {error {could not parse OpenSTA activity annotation summary}}
  set total [expr {$annotated + $unannotated}]
  set percent [expr {$total > 0 ? 100.0 * $annotated / $total : 0.0}]
  set dst [open $path a]
  puts $dst [format {annotated_percent=%.2f%%} $percent]
  if {[llength $unannotated_pins] == 0} {
    puts $dst {Unannotated pins: none}
  } else {
    puts $dst {Unannotated pins:}
    foreach pin $unannotated_pins {puts $dst " $pin"}
  }
  close $dst
}

puts "=== Step 7/7: Read activity ==="
set activity_file {/tmp/flexsoc-repack/gpio/runs/gpio/dev/signoff/ihp-sg13g2/power/activity/ACTIVITY_REQUIRED.vcd}
set activity_scope {DUT_SCOPE_REQUIRED}
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

# Create one compact workload-driven power report after GLS activity has been annotated.
set report [file join $report_dir power.rpt]
set fp [open $report w]
puts $fp "analysis=power_analysis corner=tt stage=post_syn"
puts $fp "workload=GLS_WORKLOAD_REQUIRED"
puts $fp "gls_report=/tmp/flexsoc-repack/gpio/runs/gpio/dev/signoff/ihp-sg13g2/power/activity/GLS_REPORT_REQUIRED.json"
puts $fp "activity_file=/tmp/flexsoc-repack/gpio/runs/gpio/dev/signoff/ihp-sg13g2/power/activity/ACTIVITY_REQUIRED.vcd"
puts $fp "activity_scope=DUT_SCOPE_REQUIRED"
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
flexsoc_section $report {Activity annotation}
# Report annotation coverage as one percentage and list only pins missing direct VCD/SAIF activity.
flexsoc_append_activity_coverage $report
flexsoc_section $report {Power summary}
# Report average internal, switching, leakage, and total cell power for the complete design.
flexsoc_append_opensta $report report_power
puts "report=$report"
puts {FLEXSOC_SIGNOFF_COMPLETE analysis=power_analysis corner=tt mode=n/a workload=GLS_WORKLOAD_REQUIRED}
