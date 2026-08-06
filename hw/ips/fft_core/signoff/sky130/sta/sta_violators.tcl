puts ""
puts "=== flexsoc OpenSTA init ==="
puts "read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}"
read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}
puts "read_verilog {/home/eneadim/github/flexsoc/workspace/runs/fft_core/dev/syn/fft_core_synth.v}"
read_verilog {/home/eneadim/github/flexsoc/workspace/runs/fft_core/dev/syn/fft_core_synth.v}
puts "link_design fft_core"
link_design fft_core
puts "read_sdc {/home/eneadim/github/flexsoc/workspace/runs/fft_core/dev/pnr_openroad/fft_core.sdc}"
read_sdc {/home/eneadim/github/flexsoc/workspace/runs/fft_core/dev/pnr_openroad/fft_core.sdc}

puts "=== Violators ==="
report_check_types -max_slew -max_cap -max_fanout -violators
report_checks -path_delay max -slack_max 0.0
report_checks -path_delay min -slack_max 0.0
