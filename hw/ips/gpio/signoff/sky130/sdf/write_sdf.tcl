puts ""
puts "=== flexsoc OpenSTA init ==="
puts "read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}"
read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}
puts "read_verilog {/home/eneadim/github/flexsoc/workspace/runs/gpio/dev/syn/gpio_synth.v}"
read_verilog {/home/eneadim/github/flexsoc/workspace/runs/gpio/dev/syn/gpio_synth.v}
puts "link_design gpio"
link_design gpio
puts "read_sdc {/home/eneadim/github/flexsoc/workspace/runs/gpio/dev/signoff/sky130/gpio.sdc}"
read_sdc {/home/eneadim/github/flexsoc/workspace/runs/gpio/dev/signoff/sky130/gpio.sdc}

puts "=== Write SDF ==="
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/gpio/dev/signoff/sdf/gpio_tt.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/gpio/dev/signoff/sdf/gpio_tt.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/gpio/dev/signoff/sdf/gpio_ss.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/gpio/dev/signoff/sdf/gpio_ss.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/gpio/dev/signoff/sdf/gpio_ff.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/gpio/dev/signoff/sdf/gpio_ff.sdf
