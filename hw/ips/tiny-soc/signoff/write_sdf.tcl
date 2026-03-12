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

puts "=== Write SDF ==="
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/tiny-soc/dev/signoff/sdf/soc_tt.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/tiny-soc/dev/signoff/sdf/soc_tt.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/tiny-soc/dev/signoff/sdf/soc_ss.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/tiny-soc/dev/signoff/sdf/soc_ss.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/tiny-soc/dev/signoff/sdf/soc_ff.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/tiny-soc/dev/signoff/sdf/soc_ff.sdf
