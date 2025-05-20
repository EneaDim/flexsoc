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
puts "==========================================================================="
puts "Write SDF files for each corner"
puts "==========================================================================="
puts ""
puts "write_sdf -corner Typical -divider . -include_typ signoff/sdf/pwm_ramp_tt.sdf"
puts "write_sdf -corner Slowest -divider . -include_typ signoff/sdf/pwm_ramp_ss.sdf"
puts "write_sdf -corner Fastest -divider . -include_typ signoff/sdf/pwm_ramp_ff.sdf"
puts ""
write_sdf -corner Typical -divider . -include_typ signoff/sdf/pwm_ramp_tt.sdf
write_sdf -corner Slowest -divider . -include_typ signoff/sdf/pwm_ramp_ss.sdf
write_sdf -corner Fastest -divider . -include_typ signoff/sdf/pwm_ramp_ff.sdf
