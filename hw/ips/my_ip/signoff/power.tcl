puts ""
puts "==========================================================================="
puts "Define corners Slowest Typical Fastest"
puts "==========================================================================="
puts ""
puts "define_corners Slowest Typical Fastest"
define_corners Slowest Typical Fastest

puts ""
puts "==========================================================================="
puts "Read liberty files"
puts "==========================================================================="
puts ""
puts "read_liberty -corner Slowest /home/eneadim/github/flexsoc/lib/sky130_fd_sc_hd__ss_100C_1v40.lib"
read_liberty -corner Slowest /home/eneadim/github/flexsoc/lib/sky130_fd_sc_hd__ss_100C_1v40.lib
puts "read_liberty -corner Typical /home/eneadim/github/flexsoc/lib/sky130_fd_sc_hd__tt_025C_1v80.lib"
read_liberty -corner Typical /home/eneadim/github/flexsoc/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
puts "read_liberty -corner Fastest /home/eneadim/github/flexsoc/lib/sky130_fd_sc_hd__ff_n40C_1v95.lib"
read_liberty -corner Fastest /home/eneadim/github/flexsoc/lib/sky130_fd_sc_hd__ff_n40C_1v95.lib

puts ""
puts "==========================================================================="
puts "Read verilog and link top module"
puts "==========================================================================="
puts ""
puts "read_verilog /home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/syn/my_ip_synth.v"
puts "link_design my_ip"
read_verilog /home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/syn/my_ip_synth.v
link_design my_ip

puts ""
puts "==========================================================================="
puts "Read SDC"
puts "==========================================================================="
puts ""
puts "read_sdc /home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/openroad/my_ip.sdc"
read_sdc /home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/openroad/my_ip.sdc
puts ""

puts ""
puts "==========================================================================="
puts "(Probability Power Analysis) report_power"
puts "============================================================================"
puts "set_power_activity -input -activity .10"
puts "set_power_activity -input_port rst_ni -activity 0"
set_power_activity -input -activity .10
set_power_activity -input_port rst_ni -activity 0
foreach corner [sta::corners] {
    puts ""
    puts "======================= [$corner name] Corner ==================================="
    report_power -corner [$corner name]
    puts ""
}

puts "==========================================================================="
puts "(VCD Power Analysis) report_power"
puts "============================================================================"
puts "read_vcd -scope my_ip_tb/u_my_ip /home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/sim/my_ip_tb.vcd"
read_vcd -scope my_ip_tb/u_my_ip /home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/sim/my_ip_tb.vcd
foreach corner [sta::corners] {
    puts ""
    puts "======================= [$corner name] Corner ==================================="
    report_power -corner [$corner name]
    puts ""
}