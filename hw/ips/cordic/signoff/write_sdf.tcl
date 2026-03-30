puts ""
puts "=== flexsoc OpenSTA init ==="
puts "read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}"
read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}
puts "read_verilog {/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/syn/cordic_synth.v}"
read_verilog {/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/syn/cordic_synth.v}
puts "link_design cordic"
link_design cordic
puts "read_sdc {/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/pnr_openroad/cordic.sdc}"
read_sdc {/home/eneadim/github/flexsoc/workspace/runs/cordic/dev/pnr_openroad/cordic.sdc}

puts "=== Write SDF ==="
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/signoff/sdf/cordic_tt.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/signoff/sdf/cordic_tt.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/signoff/sdf/cordic_ss.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/signoff/sdf/cordic_ss.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/signoff/sdf/cordic_ff.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/cordic/dev/signoff/sdf/cordic_ff.sdf
