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
puts "read_liberty -corner Slowest lib/sky130_fd_sc_hd__ss_100C_1v40.lib"
read_liberty -corner Slowest lib/sky130_fd_sc_hd__ss_100C_1v40.lib
puts "read_liberty -corner Typical lib/sky130_fd_sc_hd__tt_025C_1v80.lib"
read_liberty -corner Typical lib/sky130_fd_sc_hd__tt_025C_1v80.lib
puts "read_liberty -corner Fastest lib/sky130_fd_sc_hd__ff_n40C_1v95.lib"
read_liberty -corner Fastest lib/sky130_fd_sc_hd__ff_n40C_1v95.lib
puts ""
puts "==========================================================================="
puts "Read verilog and link top module"
puts "==========================================================================="
puts ""
puts "read_verilog syn/pwm_ramp_synth.v"
puts "link_design pwm_ramp"
read_verilog syn/pwm_ramp_synth.v
link_design pwm_ramp
puts ""
puts "==========================================================================="
puts "Read SDC"
puts "==========================================================================="
puts ""
puts "read_sdc signoff/pwm_ramp.sdc"
read_sdc signoff/pwm_ramp.sdc
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
puts "read_vcd -scope pwm_ramp_tb/u_pwm_ramp sim/dump_pwm_ramp.vcd"
read_vcd -scope pwm_ramp_tb/u_pwm_ramp sim/dump_pwm_ramp.vcd
foreach corner [sta::corners] {
    puts ""
    puts "======================= [$corner name] Corner ==================================="
    report_power -corner [$corner name]
    puts ""
}
