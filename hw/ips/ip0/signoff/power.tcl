puts ""
puts "=== flexsoc OpenSTA init ==="
puts "read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}"
read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}
puts "read_verilog {/home/eneadim/github/flexsoc/workspace/runs/ip0/dev/syn/ip0_synth.v}"
read_verilog {/home/eneadim/github/flexsoc/workspace/runs/ip0/dev/syn/ip0_synth.v}
puts "link_design ip0"
link_design ip0
puts "read_sdc {/home/eneadim/github/flexsoc/workspace/runs/ip0/dev/openroad/ip0.sdc}"
read_sdc {/home/eneadim/github/flexsoc/workspace/runs/ip0/dev/openroad/ip0.sdc}

puts "=== Power ==="
puts "set_power_activity -global -activity 10.0"
set_power_activity -global -activity 10.0
puts "report_power"
report_power
