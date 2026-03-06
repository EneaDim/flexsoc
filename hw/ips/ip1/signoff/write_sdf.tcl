puts ""
puts "=== flexsoc OpenSTA init ==="
puts "read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}"
read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}
puts "read_verilog {/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/syn/ip1_synth.v}"
read_verilog {/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/syn/ip1_synth.v}
puts "link_design ip1"
link_design ip1
puts "read_sdc {/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/openroad/ip1.sdc}"
read_sdc {/home/eneadim/github/flexsoc/workspace/runs/ip1/dev/openroad/ip1.sdc}

puts "=== Write SDF ==="
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/ip1/dev/signoff/sdf/ip1_tt.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/ip1/dev/signoff/sdf/ip1_tt.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/ip1/dev/signoff/sdf/ip1_ss.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/ip1/dev/signoff/sdf/ip1_ss.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/ip1/dev/signoff/sdf/ip1_ff.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/ip1/dev/signoff/sdf/ip1_ff.sdf
