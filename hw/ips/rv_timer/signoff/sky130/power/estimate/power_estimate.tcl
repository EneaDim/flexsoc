puts ""
puts "=== flexsoc OpenSTA init ==="
puts "read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}"
read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}
puts "read_verilog {/home/eneadim/github/flexsoc/workspace/runs/rv_timer/dev/syn/rv_timer_synth.v}"
read_verilog {/home/eneadim/github/flexsoc/workspace/runs/rv_timer/dev/syn/rv_timer_synth.v}
puts "link_design rv_timer"
link_design rv_timer
puts "read_sdc {/home/eneadim/github/flexsoc/workspace/runs/rv_timer/dev/signoff/sky130/rv_timer.sdc}"
read_sdc {/home/eneadim/github/flexsoc/workspace/runs/rv_timer/dev/signoff/sky130/rv_timer.sdc}

puts "=== Power ==="
puts "set_power_activity -global -activity 10.0"
set_power_activity -global -activity 10.0
puts "report_power"
report_power
