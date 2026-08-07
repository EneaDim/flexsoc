puts ""
puts "=== flexsoc OpenSTA init ==="
puts "read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}"
read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}
puts "read_verilog {/home/eneadim/github/flexsoc/workspace/runs/pwm/dev/syn/pwm_synth.v}"
read_verilog {/home/eneadim/github/flexsoc/workspace/runs/pwm/dev/syn/pwm_synth.v}
puts "link_design pwm"
link_design pwm
puts "read_sdc {/home/eneadim/github/flexsoc/workspace/runs/pwm/dev/signoff/sky130/pwm.sdc}"
read_sdc {/home/eneadim/github/flexsoc/workspace/runs/pwm/dev/signoff/sky130/pwm.sdc}

puts "=== Write SDF ==="
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/pwm/dev/signoff/sdf/pwm_tt.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/pwm/dev/signoff/sdf/pwm_tt.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/pwm/dev/signoff/sdf/pwm_ss.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/pwm/dev/signoff/sdf/pwm_ss.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/pwm/dev/signoff/sdf/pwm_ff.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/pwm/dev/signoff/sdf/pwm_ff.sdf
