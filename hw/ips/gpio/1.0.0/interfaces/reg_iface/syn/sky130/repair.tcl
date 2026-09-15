# FlexSoC post-synthesis electrical repair; no placement/CTS/routing
read_liberty $::env(FLEXSOC_REPAIR_LIBERTY)
read_db $::env(FLEXSOC_REPAIR_ODB)
read_sdc $::env(FLEXSOC_REPAIR_SDC)

puts {=== FLEXSOC BEFORE REPAIR ===}
report_wns
report_tns

repair_design -pre_placement -slew_margin 10 -cap_margin 10 -verbose

puts {=== FLEXSOC AFTER REPAIR ===}
report_wns
report_tns
write_verilog $::env(FLEXSOC_REPAIR_OUT)
