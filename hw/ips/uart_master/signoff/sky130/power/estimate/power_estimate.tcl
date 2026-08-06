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

puts "=== Power ==="
puts "set_power_activity -global -activity 10.0"
set_power_activity -global -activity 10.0
puts "report_power"
report_power
