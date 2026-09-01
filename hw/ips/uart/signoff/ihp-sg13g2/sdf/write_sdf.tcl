# =============================================================================
# AUTO-GENERATED FLEXSOC OPENSTA ANALYSIS
#
# Analysis : sdf
# Design   : uart
# Variant  : dev
# PDK      : ihp-sg13g2
# Stage    : post_syn
# Corner   : tt
# Mode     : not applicable
# Workload : not applicable
# Top      : uart
#
# Inputs:
#   Liberty       : /home/eneadim/github/flexsoc/.flexsoc/pdks/ihp-sg13g2/ihp-sg13g2/libs.ref/sg13g2_stdcell/lib/sg13g2_stdcell_typ_1p50V_25C.lib
#   Macro Liberty : not used
#   Netlist       : /tmp/flexsoc-repack/uart/runs/uart/dev/syn/ihp-sg13g2/uart_synth.v
#   SDC           : /tmp/flexsoc-repack/uart/runs/uart/dev/constraints/uart.sdc
#   SPEF          : not used
#   VCD or SAIF   : not used
#   Activity scope: not used
#   GLS report    : not used
#   Report dir    : /tmp/flexsoc-repack/uart/runs/uart/dev/signoff/ihp-sg13g2/sdf/template_reports
#
# Limitations:
#   - SDF reflects the linked netlist and timing model for the selected corner.
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
set report_dir {/tmp/flexsoc-repack/uart/runs/uart/dev/signoff/ihp-sg13g2/sdf/template_reports}
file mkdir $report_dir
set liberty {/home/eneadim/github/flexsoc/.flexsoc/pdks/ihp-sg13g2/ihp-sg13g2/libs.ref/sg13g2_stdcell/lib/sg13g2_stdcell_typ_1p50V_25C.lib}
set macro_liberties {}
set netlist {/tmp/flexsoc-repack/uart/runs/uart/dev/syn/ihp-sg13g2/uart_synth.v}
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

# write_sdf serializes the linked timing model for gate-level simulation.
set sdf_file {/tmp/flexsoc-repack/uart/runs/uart/dev/signoff/ihp-sg13g2/sdf/template_reports/uart_tt.sdf}
puts "sdf=$sdf_file"
write_sdf -divider . -include_typ -no_timestamp -no_version $sdf_file
proc flexsoc_complete_sdf_typ_header {path} {
  set fp [open $path r]
  set text [read $fp]
  close $fp
  # OpenSTA 3.1 leaves PVT header typ empty even with -include_typ.
  regsub -all {(\(VOLTAGE[ \t]+)([-+0-9.eE]+)::([-+0-9.eE]+)(\))} $text {\1\2:\2:\3\4} text
  regsub -all {(\(PROCESS[ \t]+")([-+0-9.eE]+)::([-+0-9.eE]+)("\))} $text {\1\2:\2:\3\4} text
  regsub -all {(\(TEMPERATURE[ \t]+)([-+0-9.eE]+)::([-+0-9.eE]+)(\))} $text {\1\2:\2:\3\4} text
  set fp [open $path w]
  puts -nonewline $fp $text
  close $fp
}
flexsoc_complete_sdf_typ_header $sdf_file
proc flexsoc_strip_sdf_interconnect_cell {path} {
  set fp [open $path r]
  set lines [split [read $fp] "
"]
  close $fp
  set out {}
  set skipping 0
  set skipped 0
  set depth 0
  set removed 0
  foreach line $lines {
  if {!$skipped && !$skipping && [string trim $line] eq "(CELL"} {set skipping 1}
  if {$skipping} {
    incr removed [regexp -all {\(INTERCONNECT[ 	]} $line]
    set opens [regexp -all {\(} $line]
    set closes [regexp -all {\)} $line]
    incr depth [expr {$opens - $closes}]
    if {$depth == 0} {set skipping 0; set skipped 1}
    continue
  }
  lappend out $line
  }
  if {!$skipped} {puts stderr "ERROR: OpenSTA SDF interconnect cell not found: $path"; exit 2}
  set fp [open $path w]
  puts -nonewline $fp [join $out "
"]
  close $fp
  puts "sdf_interconnect=omitted count=$removed stage=post_syn"
}
if {$stage eq "post_syn"} {
  # Pre-implementation timing intentionally has no extracted interconnect model.
  flexsoc_strip_sdf_interconnect_cell $sdf_file
} else {
  puts "sdf_interconnect=retained stage=post_route"
}
puts {FLEXSOC_SIGNOFF_COMPLETE analysis=sdf corner=tt mode=n/a workload=n/a}
