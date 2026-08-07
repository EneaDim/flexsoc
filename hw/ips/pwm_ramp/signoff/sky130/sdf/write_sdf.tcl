puts ""
puts "=== flexsoc OpenSTA init ==="
puts "read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}"
read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}
puts "read_verilog {/home/eneadim/github/flexsoc/workspace/runs/pwm_ramp/dev/syn/pwm_ramp_synth.v}"
read_verilog {/home/eneadim/github/flexsoc/workspace/runs/pwm_ramp/dev/syn/pwm_ramp_synth.v}
puts "link_design pwm_ramp"
link_design pwm_ramp
puts "read_sdc {/home/eneadim/github/flexsoc/workspace/runs/pwm_ramp/dev/signoff/sky130/pwm_ramp.sdc}"
read_sdc {/home/eneadim/github/flexsoc/workspace/runs/pwm_ramp/dev/signoff/sky130/pwm_ramp.sdc}

puts "=== Write SDF ==="
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/pwm_ramp/dev/signoff/sdf/pwm_ramp_tt.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/pwm_ramp/dev/signoff/sdf/pwm_ramp_tt.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/pwm_ramp/dev/signoff/sdf/pwm_ramp_ss.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/pwm_ramp/dev/signoff/sdf/pwm_ramp_ss.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/pwm_ramp/dev/signoff/sdf/pwm_ramp_ff.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/pwm_ramp/dev/signoff/sdf/pwm_ramp_ff.sdf
