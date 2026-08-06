puts ""
puts "=== flexsoc OpenSTA init ==="
puts "read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}"
read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}
puts "read_verilog {/home/eneadim/github/flexsoc/workspace/runs/cache_wrapper/dev/syn/cache_wrapper_synth.v}"
read_verilog {/home/eneadim/github/flexsoc/workspace/runs/cache_wrapper/dev/syn/cache_wrapper_synth.v}
puts "link_design cache_wrapper"
link_design cache_wrapper
puts "read_sdc {/home/eneadim/github/flexsoc/workspace/runs/cache_wrapper/dev/pnr_openroad/cache_wrapper.sdc}"
read_sdc {/home/eneadim/github/flexsoc/workspace/runs/cache_wrapper/dev/pnr_openroad/cache_wrapper.sdc}

puts "=== Violators ==="
report_check_types -max_slew -max_cap -max_fanout -violators
report_checks -path_delay max -slack_max 0.0
report_checks -path_delay min -slack_max 0.0
