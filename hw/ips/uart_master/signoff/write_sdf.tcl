puts ""
puts "=== flexsoc OpenSTA init ==="
puts "read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}"
read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}
puts "read_verilog {/home/eneadim/github/flexsoc/workspace/runs/uart_master/dev/syn/uart_synth.v}"
read_verilog {/home/eneadim/github/flexsoc/workspace/runs/uart_master/dev/syn/uart_synth.v}
puts "link_design uart_master"
link_design uart_master
puts "read_sdc {/home/eneadim/github/flexsoc/workspace/runs/uart_master/dev/pnr_openroad/uart_master.sdc}"
read_sdc {/home/eneadim/github/flexsoc/workspace/runs/uart_master/dev/pnr_openroad/uart_master.sdc}

puts "=== Write SDF ==="
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/uart_master/dev/signoff/sdf/uart_tt.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/uart_master/dev/signoff/sdf/uart_tt.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/uart_master/dev/signoff/sdf/uart_ss.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/uart_master/dev/signoff/sdf/uart_ss.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/uart_master/dev/signoff/sdf/uart_ff.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/uart_master/dev/signoff/sdf/uart_ff.sdf
