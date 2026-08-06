puts ""
puts "=== flexsoc OpenSTA init ==="
puts "read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}"
read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}
puts "read_verilog {/home/eneadim/github/flexsoc/workspace/runs/tiny-soc/dev/syn/soc_synth.v}"
read_verilog {/home/eneadim/github/flexsoc/workspace/runs/tiny-soc/dev/syn/soc_synth.v}
puts "link_design soc"
link_design soc
puts "read_sdc {/home/eneadim/github/flexsoc/workspace/runs/tiny-soc/dev/pnr_openroad/soc.sdc}"
read_sdc {/home/eneadim/github/flexsoc/workspace/runs/tiny-soc/dev/pnr_openroad/soc.sdc}

puts "=== Violators ==="
report_check_types -max_slew -max_cap -max_fanout -violators
report_checks -path_delay max -slack_max 0.0
report_checks -path_delay min -slack_max 0.0
