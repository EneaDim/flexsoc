puts ""
puts "=== flexsoc OpenSTA init ==="
puts "read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}"
read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}
puts "read_verilog {/home/eneadim/github/flexsoc/workspace/runs/rv_timer/dev/syn/rv_timer_synth.v}"
read_verilog {/home/eneadim/github/flexsoc/workspace/runs/rv_timer/dev/syn/rv_timer_synth.v}
puts "link_design rv_timer"
link_design rv_timer
puts "read_sdc {/home/eneadim/github/flexsoc/workspace/runs/rv_timer/dev/pnr_openroad/rv_timer.sdc}"
read_sdc {/home/eneadim/github/flexsoc/workspace/runs/rv_timer/dev/pnr_openroad/rv_timer.sdc}

puts "=== Write SDF ==="
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/rv_timer/dev/signoff/sdf/rv_timer_tt.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/rv_timer/dev/signoff/sdf/rv_timer_tt.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/rv_timer/dev/signoff/sdf/rv_timer_ss.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/rv_timer/dev/signoff/sdf/rv_timer_ss.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/rv_timer/dev/signoff/sdf/rv_timer_ff.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/rv_timer/dev/signoff/sdf/rv_timer_ff.sdf
