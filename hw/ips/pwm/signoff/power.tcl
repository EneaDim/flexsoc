puts ""
puts "=== flexsoc OpenSTA init ==="
puts "read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}"
read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}
puts "read_verilog {/home/eneadim/github/flexsoc/workspace/runs/pwm/dev/syn/pwm_synth.v}"
read_verilog {/home/eneadim/github/flexsoc/workspace/runs/pwm/dev/syn/pwm_synth.v}
puts "link_design pwm"
link_design pwm
puts "read_sdc {/home/eneadim/github/flexsoc/workspace/runs/pwm/dev/pnr_openroad/pwm.sdc}"
read_sdc {/home/eneadim/github/flexsoc/workspace/runs/pwm/dev/pnr_openroad/pwm.sdc}

puts "=== Power ==="
puts "set_power_activity -global -activity 10.0"
set_power_activity -global -activity 10.0
puts "report_power"
report_power
