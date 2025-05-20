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
puts "read_verilog syn/cache_wrapper_synth.v"
puts "link_design cache_wrapper"
read_verilog syn/cache_wrapper_synth.v
link_design cache_wrapper
puts ""
puts "==========================================================================="
puts "Read SDC"
puts "==========================================================================="
puts ""
puts "read_sdc signoff/cache_wrapper.sdc"
read_sdc signoff/cache_wrapper.sdc
puts ""
puts "==========================================================================="
puts "Write SDF files for each corner"
puts "==========================================================================="
puts ""
puts "write_sdf -corner Typical -divider . -include_typ signoff/sdf/cache_wrapper_tt.sdf"
puts "write_sdf -corner Slowest -divider . -include_typ signoff/sdf/cache_wrapper_ss.sdf"
puts "write_sdf -corner Fastest -divider . -include_typ signoff/sdf/cache_wrapper_ff.sdf"
puts ""
write_sdf -corner Typical -divider . -include_typ signoff/sdf/cache_wrapper_tt.sdf
write_sdf -corner Slowest -divider . -include_typ signoff/sdf/cache_wrapper_ss.sdf
write_sdf -corner Fastest -divider . -include_typ signoff/sdf/cache_wrapper_ff.sdf
