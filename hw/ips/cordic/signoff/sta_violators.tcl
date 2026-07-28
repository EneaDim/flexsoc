puts ""
puts "=== flexsoc OpenSTA init ==="
if {[info exists ::env(STA_CORNER)]} {set sta_corner $::env(STA_CORNER)} else {set sta_corner "default"}
set liberty_files {{ss /home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib} {tt /home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__tt_025C_1v80.lib} {ff /home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ff_n40C_1v95.lib}}
set selected_lib ""
foreach item $liberty_files {
  lassign $item corner path
  if {$corner == $sta_corner} {set selected_lib $path}
}
if {$selected_lib == ""} {set selected_lib "/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib"}
puts "corner=$sta_corner liberty=$selected_lib"
read_liberty $selected_lib
puts "read_verilog {/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/syn/cordic_synth.v}"
read_verilog {/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/syn/cordic_synth.v}
puts "link_design cordic"
link_design cordic
puts "read_sdc {/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/pnr_openroad/cordic.sdc}"
read_sdc {/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/pnr_openroad/cordic.sdc}

puts "=== Violators ==="
report_check_types -max_slew -max_cap -max_fanout -violators
report_checks -path_delay max -slack_max 0.0
report_checks -path_delay min -slack_max 0.0
