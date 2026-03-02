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
puts "read_verilog syn/rv_timer_synth.v"
puts "link_design rv_timer"
read_verilog syn/rv_timer_synth.v
link_design rv_timer

puts ""
puts "==========================================================================="
puts "Read SDC"
puts "==========================================================================="
puts ""
puts "read_sdc ors/rv_timer.sdc"
read_sdc ors/rv_timer.sdc
puts ""

puts "==========================================================================="
puts "Write SDF files for each corner"
puts "==========================================================================="
puts ""
puts "write_sdf -corner Typical -divider . -include_typ signoff/sdf/rv_timer_tt.sdf"
write_sdf -corner Typical -divider . -include_typ signoff/sdf/rv_timer_tt.sdf
puts "write_sdf -corner Slowest -divider . -include_typ signoff/sdf/rv_timer_ss.sdf"
write_sdf -corner Slowest -divider . -include_typ signoff/sdf/rv_timer_ss.sdf
puts "write_sdf -corner Fastest -divider . -include_typ signoff/sdf/rv_timer_ff.sdf"
write_sdf -corner Fastest -divider . -include_typ signoff/sdf/rv_timer_ff.sdf
