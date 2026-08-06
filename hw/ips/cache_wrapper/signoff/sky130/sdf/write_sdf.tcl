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

puts "=== Write SDF ==="
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/cache_wrapper/dev/signoff/sdf/cache_wrapper_tt.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/cache_wrapper/dev/signoff/sdf/cache_wrapper_tt.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/cache_wrapper/dev/signoff/sdf/cache_wrapper_ss.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/cache_wrapper/dev/signoff/sdf/cache_wrapper_ss.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/cache_wrapper/dev/signoff/sdf/cache_wrapper_ff.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/cache_wrapper/dev/signoff/sdf/cache_wrapper_ff.sdf
