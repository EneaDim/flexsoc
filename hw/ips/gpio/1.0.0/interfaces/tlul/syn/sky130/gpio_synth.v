module gpio (clk_i,
    rst_ni,
    cio_gpio_en_o,
    cio_gpio_i,
    cio_gpio_o,
    intr_gpio_o,
    tl_i,
    tl_o);
 input clk_i;
 input rst_ni;
 output [3:0] cio_gpio_en_o;
 input [3:0] cio_gpio_i;
 output [3:0] cio_gpio_o;
 output [3:0] intr_gpio_o;
 input [108:0] tl_i;
 output [65:0] tl_o;

 wire _000_;
 wire _001_;
 wire _002_;
 wire _003_;
 wire _004_;
 wire _005_;
 wire _006_;
 wire _007_;
 wire _008_;
 wire _009_;
 wire _010_;
 wire _011_;
 wire _012_;
 wire _013_;
 wire _014_;
 wire _015_;
 wire _016_;
 wire _017_;
 wire _018_;
 wire _019_;
 wire _020_;
 wire _021_;
 wire _022_;
 wire _023_;
 wire _024_;
 wire _025_;
 wire _026_;
 wire _027_;
 wire _028_;
 wire _029_;
 wire _030_;
 wire _031_;
 wire _032_;
 wire _033_;
 wire _034_;
 wire _035_;
 wire _036_;
 wire _037_;
 wire _038_;
 wire _039_;
 wire _040_;
 wire _041_;
 wire _042_;
 wire _043_;
 wire _044_;
 wire _045_;
 wire _046_;
 wire _047_;
 wire _048_;
 wire _049_;
 wire _050_;
 wire _051_;
 wire _052_;
 wire _053_;
 wire _054_;
 wire _055_;
 wire _056_;
 wire _057_;
 wire _058_;
 wire _059_;
 wire _060_;
 wire _061_;
 wire _062_;
 wire _063_;
 wire _064_;
 wire _065_;
 wire _066_;
 wire _067_;
 wire _068_;
 wire _069_;
 wire _070_;
 wire _071_;
 wire _072_;
 wire _073_;
 wire _074_;
 wire _075_;
 wire _076_;
 wire _077_;
 wire _078_;
 wire _079_;
 wire _080_;
 wire _081_;
 wire _082_;
 wire _083_;
 wire _084_;
 wire _085_;
 wire _086_;
 wire _087_;
 wire _088_;
 wire _089_;
 wire _090_;
 wire _091_;
 wire _092_;
 wire _093_;
 wire _094_;
 wire _095_;
 wire _096_;
 wire _097_;
 wire _098_;
 wire _099_;
 wire _100_;
 wire _101_;
 wire _102_;
 wire _103_;
 wire _104_;
 wire _105_;
 wire _106_;
 wire _107_;
 wire _108_;
 wire _109_;
 wire _110_;
 wire _111_;
 wire _112_;
 wire _113_;
 wire _114_;
 wire _115_;
 wire _116_;
 wire _117_;
 wire _118_;
 wire _119_;
 wire _120_;
 wire _121_;
 wire _122_;
 wire _123_;
 wire _124_;
 wire _125_;
 wire _126_;
 wire _127_;
 wire _128_;
 wire _129_;
 wire _130_;
 wire _131_;
 wire _132_;
 wire _133_;
 wire _134_;
 wire _135_;
 wire _136_;
 wire _137_;
 wire _138_;
 wire _139_;
 wire _140_;
 wire _141_;
 wire _142_;
 wire _143_;
 wire _144_;
 wire _145_;
 wire _146_;
 wire _147_;
 wire _148_;
 wire _149_;
 wire _150_;
 wire _151_;
 wire _152_;
 wire _153_;
 wire _154_;
 wire _155_;
 wire _156_;
 wire _157_;
 wire _158_;
 wire _159_;
 wire _160_;
 wire _161_;
 wire _162_;
 wire _163_;
 wire _164_;
 wire _165_;
 wire _166_;
 wire _167_;
 wire _168_;
 wire _169_;
 wire _170_;
 wire _171_;
 wire _172_;
 wire _173_;
 wire _174_;
 wire _175_;
 wire _176_;
 wire _177_;
 wire _178_;
 wire _179_;
 wire _180_;
 wire _181_;
 wire _182_;
 wire _183_;
 wire _184_;
 wire _185_;
 wire _186_;
 wire _187_;
 wire _188_;
 wire _189_;
 wire _190_;
 wire _191_;
 wire _192_;
 wire _193_;
 wire _194_;
 wire _195_;
 wire _196_;
 wire _197_;
 wire _198_;
 wire _199_;
 wire _200_;
 wire _201_;
 wire _202_;
 wire _203_;
 wire _204_;
 wire _205_;
 wire _206_;
 wire _207_;
 wire _208_;
 wire _209_;
 wire _210_;
 wire _211_;
 wire _212_;
 wire _213_;
 wire _214_;
 wire _215_;
 wire _216_;
 wire _217_;
 wire _218_;
 wire _219_;
 wire _220_;
 wire _221_;
 wire _222_;
 wire _223_;
 wire _224_;
 wire _225_;
 wire _226_;
 wire _227_;
 wire _228_;
 wire _229_;
 wire _230_;
 wire _231_;
 wire _232_;
 wire _233_;
 wire _234_;
 wire _235_;
 wire _236_;
 wire _237_;
 wire _238_;
 wire _239_;
 wire _240_;
 wire _241_;
 wire _242_;
 wire _243_;
 wire _244_;
 wire _245_;
 wire _246_;
 wire _247_;
 wire _248_;
 wire _249_;
 wire _250_;
 wire _251_;
 wire _252_;
 wire _253_;
 wire _254_;
 wire _255_;
 wire _256_;
 wire _257_;
 wire _258_;
 wire _259_;
 wire _260_;
 wire _261_;
 wire _262_;
 wire _263_;
 wire _264_;
 wire _265_;
 wire _266_;
 wire _267_;
 wire _268_;
 wire _269_;
 wire _270_;
 wire _271_;
 wire _272_;
 wire _273_;
 wire _274_;
 wire _275_;
 wire _276_;
 wire _277_;
 wire _278_;
 wire _279_;
 wire _280_;
 wire _281_;
 wire _282_;
 wire _283_;
 wire _284_;
 wire _285_;
 wire _286_;
 wire _287_;
 wire _288_;
 wire _289_;
 wire _290_;
 wire _291_;
 wire _292_;
 wire _293_;
 wire _294_;
 wire _295_;
 wire _296_;
 wire _297_;
 wire _298_;
 wire _299_;
 wire _300_;
 wire net24;
 wire net20;
 wire core_rst_ni;
 wire hw2reg_0_;
 wire hw2reg_10_;
 wire hw2reg_11_;
 wire hw2reg_12_;
 wire hw2reg_1_;
 wire hw2reg_2_;
 wire hw2reg_3_;
 wire hw2reg_4_;
 wire hw2reg_5_;
 wire hw2reg_6_;
 wire hw2reg_7_;
 wire hw2reg_9_;
 wire reg2hw_0_;
 wire reg2hw_10_;
 wire reg2hw_11_;
 wire reg2hw_12_;
 wire reg2hw_13_;
 wire reg2hw_14_;
 wire reg2hw_15_;
 wire reg2hw_16_;
 wire reg2hw_17_;
 wire reg2hw_18_;
 wire reg2hw_19_;
 wire reg2hw_1_;
 wire reg2hw_2_;
 wire reg2hw_3_;
 wire reg2hw_4_;
 wire reg2hw_5_;
 wire reg2hw_6_;
 wire reg2hw_7_;
 wire reg2hw_8_;
 wire reg2hw_9_;
 wire reg_rst_ni;
 wire u_core_reset_sync_intq;
 wire u_gpio_core_data_in_q_0_;
 wire u_gpio_core_data_in_q_1_;
 wire u_gpio_core_data_in_q_2_;
 wire u_gpio_core_data_in_q_3_;
 wire u_gpio_core_filter_rst_ni;
 wire u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_0_;
 wire u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_;
 wire u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_2_;
 wire u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_3_;
 wire u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_;
 wire u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_;
 wire u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_;
 wire u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_;
 wire u_gpio_core_gen_input_filter_0__u_filter_filter_q;
 wire u_gpio_core_gen_input_filter_0__u_filter_filter_synced;
 wire u_gpio_core_gen_input_filter_0__u_filter_gen_async_prim_flop_2sync_intq;
 wire u_gpio_core_gen_input_filter_0__u_filter_stored_value_q;
 wire u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_0_;
 wire u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_1_;
 wire u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_2_;
 wire u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_;
 wire u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_;
 wire u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_;
 wire u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_2_;
 wire u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_;
 wire u_gpio_core_gen_input_filter_1__u_filter_filter_q;
 wire u_gpio_core_gen_input_filter_1__u_filter_filter_synced;
 wire u_gpio_core_gen_input_filter_1__u_filter_gen_async_prim_flop_2sync_intq;
 wire u_gpio_core_gen_input_filter_1__u_filter_stored_value_q;
 wire u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_0_;
 wire u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_;
 wire u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_2_;
 wire u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_3_;
 wire u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_;
 wire u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_;
 wire u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_2_;
 wire u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_;
 wire u_gpio_core_gen_input_filter_2__u_filter_filter_q;
 wire u_gpio_core_gen_input_filter_2__u_filter_filter_synced;
 wire u_gpio_core_gen_input_filter_2__u_filter_gen_async_prim_flop_2sync_intq;
 wire u_gpio_core_gen_input_filter_2__u_filter_stored_value_q;
 wire u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_0_;
 wire u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_1_;
 wire u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_2_;
 wire u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_3_;
 wire u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_;
 wire u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_1_;
 wire u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_2_;
 wire u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_;
 wire u_gpio_core_gen_input_filter_3__u_filter_filter_q;
 wire u_gpio_core_gen_input_filter_3__u_filter_filter_synced;
 wire u_gpio_core_gen_input_filter_3__u_filter_gen_async_prim_flop_2sync_intq;
 wire u_gpio_core_gen_input_filter_3__u_filter_stored_value_q;
 wire u_gpio_core_intr_gpio_o_0_;
 wire u_gpio_core_intr_gpio_o_1_;
 wire u_gpio_core_intr_gpio_o_2_;
 wire u_gpio_core_intr_gpio_o_3_;
 wire u_gpio_core_state_rst_ni;
 wire u_gpio_reg_tl_o_0_;
 wire u_gpio_reg_tl_o_16_;
 wire u_gpio_reg_tl_o_17_;
 wire u_gpio_reg_tl_o_18_;
 wire u_gpio_reg_tl_o_19_;
 wire u_gpio_reg_tl_o_1_;
 wire u_gpio_reg_tl_o_20_;
 wire u_gpio_reg_tl_o_21_;
 wire u_gpio_reg_tl_o_22_;
 wire u_gpio_reg_tl_o_23_;
 wire u_gpio_reg_tl_o_24_;
 wire u_gpio_reg_tl_o_25_;
 wire u_gpio_reg_tl_o_26_;
 wire u_gpio_reg_tl_o_27_;
 wire u_gpio_reg_tl_o_28_;
 wire u_gpio_reg_tl_o_29_;
 wire u_gpio_reg_tl_o_30_;
 wire u_gpio_reg_tl_o_31_;
 wire u_gpio_reg_tl_o_32_;
 wire u_gpio_reg_tl_o_33_;
 wire u_gpio_reg_tl_o_34_;
 wire u_gpio_reg_tl_o_35_;
 wire u_gpio_reg_tl_o_36_;
 wire u_gpio_reg_tl_o_37_;
 wire u_gpio_reg_tl_o_38_;
 wire u_gpio_reg_tl_o_39_;
 wire u_gpio_reg_tl_o_40_;
 wire u_gpio_reg_tl_o_41_;
 wire u_gpio_reg_tl_o_42_;
 wire u_gpio_reg_tl_o_43_;
 wire u_gpio_reg_tl_o_44_;
 wire u_gpio_reg_tl_o_45_;
 wire u_gpio_reg_tl_o_46_;
 wire u_gpio_reg_tl_o_47_;
 wire u_gpio_reg_tl_o_49_;
 wire u_gpio_reg_tl_o_50_;
 wire u_gpio_reg_tl_o_51_;
 wire u_gpio_reg_tl_o_52_;
 wire u_gpio_reg_tl_o_53_;
 wire u_gpio_reg_tl_o_54_;
 wire u_gpio_reg_tl_o_55_;
 wire u_gpio_reg_tl_o_56_;
 wire u_gpio_reg_tl_o_57_;
 wire u_gpio_reg_tl_o_58_;
 wire u_gpio_reg_tl_o_62_;
 wire u_gpio_reg_tl_o_65_;
 wire u_gpio_reg_u_reg_core_data_in_qs_0_;
 wire u_gpio_reg_u_reg_core_data_in_qs_1_;
 wire u_gpio_reg_u_reg_core_data_in_qs_2_;
 wire u_gpio_reg_u_reg_core_data_in_qs_3_;
 wire u_reg_reset_sync_intq;
 wire net;
 wire net1;
 wire net2;
 wire net3;
 wire net4;
 wire net5;
 wire net6;
 wire net7;
 wire net8;
 wire net9;
 wire net10;
 wire net11;
 wire net12;
 wire net13;
 wire net14;
 wire net15;
 wire net16;
 wire net17;
 wire net18;
 wire net19;
 wire net21;
 wire net22;
 wire net23;
 wire net25;
 wire net26;
 wire net27;
 wire net28;
 wire net29;
 wire net30;
 wire net31;
 wire net32;
 wire net33;
 wire net34;
 wire net35;
 wire net36;
 wire net37;

 sky130_fd_sc_hd__inv_1 _303_ (.A(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .Y(_077_));
 sky130_fd_sc_hd__nand2_1 _304_ (.A(reg2hw_18_),
    .B(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .Y(_078_));
 sky130_fd_sc_hd__o21ai_1 _305_ (.A1(reg2hw_18_),
    .A2(_077_),
    .B1(_078_),
    .Y(hw2reg_11_));
 sky130_fd_sc_hd__inv_1 _306_ (.A(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .Y(_079_));
 sky130_fd_sc_hd__nand2_1 _307_ (.A(reg2hw_17_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .Y(_080_));
 sky130_fd_sc_hd__o21ai_1 _308_ (.A1(reg2hw_17_),
    .A2(_079_),
    .B1(_080_),
    .Y(hw2reg_10_));
 sky130_fd_sc_hd__inv_1 _309_ (.A(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .Y(_081_));
 sky130_fd_sc_hd__nand2_1 _310_ (.A(reg2hw_16_),
    .B(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .Y(_082_));
 sky130_fd_sc_hd__o21ai_1 _311_ (.A1(reg2hw_16_),
    .A2(_081_),
    .B1(_082_),
    .Y(hw2reg_9_));
 sky130_fd_sc_hd__inv_1 _312_ (.A(reg2hw_2_),
    .Y(_083_));
 sky130_fd_sc_hd__nor2_1 _313_ (.A(u_gpio_core_data_in_q_2_),
    .B(_083_),
    .Y(_084_));
 sky130_fd_sc_hd__nor2_1 _314_ (.A(reg2hw_10_),
    .B(_084_),
    .Y(_085_));
 sky130_fd_sc_hd__a21oi_1 _315_ (.A1(u_gpio_core_data_in_q_2_),
    .A2(reg2hw_6_),
    .B1(hw2reg_11_),
    .Y(_086_));
 sky130_fd_sc_hd__inv_1 _316_ (.A(reg2hw_14_),
    .Y(_087_));
 sky130_fd_sc_hd__a22oi_1 _317_ (.A1(_085_),
    .A2(hw2reg_11_),
    .B1(_086_),
    .B2(_087_),
    .Y(u_gpio_core_intr_gpio_o_2_));
 sky130_fd_sc_hd__inv_1 _318_ (.A(u_gpio_core_data_in_q_1_),
    .Y(_088_));
 sky130_fd_sc_hd__a21oi_1 _319_ (.A1(_088_),
    .A2(reg2hw_1_),
    .B1(reg2hw_9_),
    .Y(_089_));
 sky130_fd_sc_hd__a21oi_1 _320_ (.A1(u_gpio_core_data_in_q_1_),
    .A2(reg2hw_5_),
    .B1(hw2reg_10_),
    .Y(_090_));
 sky130_fd_sc_hd__inv_1 _321_ (.A(reg2hw_13_),
    .Y(_091_));
 sky130_fd_sc_hd__a22oi_1 _322_ (.A1(hw2reg_10_),
    .A2(_089_),
    .B1(_090_),
    .B2(_091_),
    .Y(u_gpio_core_intr_gpio_o_1_));
 sky130_fd_sc_hd__inv_1 _323_ (.A(u_gpio_core_data_in_q_0_),
    .Y(_092_));
 sky130_fd_sc_hd__a21oi_1 _324_ (.A1(_092_),
    .A2(reg2hw_0_),
    .B1(reg2hw_8_),
    .Y(_093_));
 sky130_fd_sc_hd__a21oi_1 _325_ (.A1(u_gpio_core_data_in_q_0_),
    .A2(reg2hw_4_),
    .B1(hw2reg_9_),
    .Y(_094_));
 sky130_fd_sc_hd__inv_1 _326_ (.A(reg2hw_12_),
    .Y(_095_));
 sky130_fd_sc_hd__a22oi_1 _327_ (.A1(hw2reg_9_),
    .A2(_093_),
    .B1(_094_),
    .B2(_095_),
    .Y(u_gpio_core_intr_gpio_o_0_));
 sky130_fd_sc_hd__xor2_1 _328_ (.A(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_1__u_filter_filter_q),
    .X(_096_));
 sky130_fd_sc_hd__or2_0 _329_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .B(net28),
    .X(_097_));
 sky130_fd_sc_hd__nand2_1 _330_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .B(net28),
    .Y(_098_));
 sky130_fd_sc_hd__inv_1 _331_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_),
    .Y(_099_));
 sky130_fd_sc_hd__nand3_1 _332_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_2_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .C(net28),
    .Y(_100_));
 sky130_fd_sc_hd__nor2_1 _333_ (.A(_099_),
    .B(_100_),
    .Y(_101_));
 sky130_fd_sc_hd__a21oi_1 _334_ (.A1(_097_),
    .A2(_098_),
    .B1(_101_),
    .Y(_102_));
 sky130_fd_sc_hd__nor2_1 _335_ (.A(_096_),
    .B(_102_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_1_));
 sky130_fd_sc_hd__inv_1 _336_ (.A(net28),
    .Y(_103_));
 sky130_fd_sc_hd__nor2_1 _337_ (.A(_103_),
    .B(_101_),
    .Y(_104_));
 sky130_fd_sc_hd__nor2_1 _338_ (.A(_096_),
    .B(_104_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_0_));
 sky130_fd_sc_hd__clkinv_2 _339_ (.A(u_gpio_reg_tl_o_65_),
    .Y(u_gpio_reg_tl_o_0_));
 sky130_fd_sc_hd__nand2_8 _340_ (.A(u_gpio_reg_tl_o_0_),
    .B(tl_i[108]),
    .Y(_105_));
 sky130_fd_sc_hd__nor3_1 _341_ (.A(tl_i[106]),
    .B(tl_i[107]),
    .C(_105_),
    .Y(_106_));
 sky130_fd_sc_hd__inv_1 _342_ (.A(tl_i[60]),
    .Y(_107_));
 sky130_fd_sc_hd__inv_1 _343_ (.A(tl_i[61]),
    .Y(_108_));
 sky130_fd_sc_hd__nand3_2 _344_ (.A(_106_),
    .B(_107_),
    .C(_108_),
    .Y(_109_));
 sky130_fd_sc_hd__inv_4 _345_ (.A(tl_i[63]),
    .Y(_110_));
 sky130_fd_sc_hd__nor2_4 _346_ (.A(tl_i[62]),
    .B(_110_),
    .Y(_111_));
 sky130_fd_sc_hd__nand2_1 _347_ (.A(tl_i[57]),
    .B(tl_i[58]),
    .Y(_112_));
 sky130_fd_sc_hd__a21boi_0 _348_ (.A1(_111_),
    .A2(_112_),
    .B1_N(tl_i[56]),
    .Y(_113_));
 sky130_fd_sc_hd__nand2_1 _349_ (.A(tl_i[63]),
    .B(tl_i[62]),
    .Y(_114_));
 sky130_fd_sc_hd__o21ai_2 _350_ (.A1(_113_),
    .A2(_109_),
    .B1(_114_),
    .Y(_115_));
 sky130_fd_sc_hd__nor2_1 _351_ (.A(_109_),
    .B(_115_),
    .Y(_116_));
 sky130_fd_sc_hd__nand2_1 _352_ (.A(_116_),
    .B(_111_),
    .Y(_117_));
 sky130_fd_sc_hd__buf_2 _353_ (.A(_117_),
    .X(_118_));
 sky130_fd_sc_hd__nor2_1 _354_ (.A(tl_i[26]),
    .B(net25),
    .Y(_119_));
 sky130_fd_sc_hd__a21oi_1 _355_ (.A1(_083_),
    .A2(net25),
    .B1(_119_),
    .Y(_000_));
 sky130_fd_sc_hd__mux2_1 _356_ (.A0(tl_i[25]),
    .A1(reg2hw_1_),
    .S(net25),
    .X(_001_));
 sky130_fd_sc_hd__mux2_1 _357_ (.A0(tl_i[24]),
    .A1(reg2hw_0_),
    .S(net25),
    .X(_002_));
 sky130_fd_sc_hd__nor2_1 _358_ (.A(tl_i[38]),
    .B(net25),
    .Y(_120_));
 sky130_fd_sc_hd__a21oi_1 _359_ (.A1(_087_),
    .A2(net25),
    .B1(_120_),
    .Y(_003_));
 sky130_fd_sc_hd__nor2_1 _360_ (.A(tl_i[37]),
    .B(net25),
    .Y(_121_));
 sky130_fd_sc_hd__a21oi_1 _361_ (.A1(_091_),
    .A2(net25),
    .B1(_121_),
    .Y(_004_));
 sky130_fd_sc_hd__nor2_1 _362_ (.A(tl_i[36]),
    .B(net25),
    .Y(_122_));
 sky130_fd_sc_hd__a21oi_1 _363_ (.A1(_095_),
    .A2(net25),
    .B1(_122_),
    .Y(_005_));
 sky130_fd_sc_hd__inv_1 _364_ (.A(reg2hw_10_),
    .Y(_123_));
 sky130_fd_sc_hd__nor2_1 _365_ (.A(tl_i[34]),
    .B(net25),
    .Y(_124_));
 sky130_fd_sc_hd__a21oi_1 _366_ (.A1(_123_),
    .A2(net25),
    .B1(_124_),
    .Y(_006_));
 sky130_fd_sc_hd__inv_1 _367_ (.A(reg2hw_9_),
    .Y(_125_));
 sky130_fd_sc_hd__nor2_1 _368_ (.A(tl_i[33]),
    .B(net25),
    .Y(_126_));
 sky130_fd_sc_hd__a21oi_1 _369_ (.A1(_125_),
    .A2(net25),
    .B1(_126_),
    .Y(_007_));
 sky130_fd_sc_hd__inv_1 _370_ (.A(reg2hw_8_),
    .Y(_127_));
 sky130_fd_sc_hd__nor2_1 _371_ (.A(tl_i[32]),
    .B(net25),
    .Y(_128_));
 sky130_fd_sc_hd__a21oi_1 _372_ (.A1(_127_),
    .A2(net25),
    .B1(_128_),
    .Y(_008_));
 sky130_fd_sc_hd__inv_1 _373_ (.A(reg2hw_18_),
    .Y(_129_));
 sky130_fd_sc_hd__nor2_1 _374_ (.A(tl_i[42]),
    .B(net25),
    .Y(_130_));
 sky130_fd_sc_hd__a21oi_1 _375_ (.A1(_129_),
    .A2(net25),
    .B1(_130_),
    .Y(_009_));
 sky130_fd_sc_hd__inv_1 _376_ (.A(reg2hw_17_),
    .Y(_131_));
 sky130_fd_sc_hd__nor2_1 _377_ (.A(tl_i[41]),
    .B(net25),
    .Y(_132_));
 sky130_fd_sc_hd__a21oi_1 _378_ (.A1(_131_),
    .A2(net25),
    .B1(_132_),
    .Y(_010_));
 sky130_fd_sc_hd__inv_1 _379_ (.A(reg2hw_16_),
    .Y(_133_));
 sky130_fd_sc_hd__nor2_1 _380_ (.A(tl_i[40]),
    .B(net25),
    .Y(_134_));
 sky130_fd_sc_hd__a21oi_1 _381_ (.A1(_133_),
    .A2(net25),
    .B1(_134_),
    .Y(_011_));
 sky130_fd_sc_hd__mux2_1 _382_ (.A0(tl_i[30]),
    .A1(reg2hw_6_),
    .S(net25),
    .X(_012_));
 sky130_fd_sc_hd__mux2_1 _383_ (.A0(tl_i[29]),
    .A1(reg2hw_5_),
    .S(net25),
    .X(_013_));
 sky130_fd_sc_hd__mux2_1 _384_ (.A0(tl_i[28]),
    .A1(reg2hw_4_),
    .S(net25),
    .X(_014_));
 sky130_fd_sc_hd__inv_12 _385_ (.A(_105_),
    .Y(_135_));
 sky130_fd_sc_hd__nand2_1 _386_ (.A(_135_),
    .B(tl_i[100]),
    .Y(_136_));
 sky130_fd_sc_hd__buf_2 _387_ (.A(_105_),
    .X(_137_));
 sky130_fd_sc_hd__nand2_1 _388_ (.A(net26),
    .B(u_gpio_reg_tl_o_57_),
    .Y(_138_));
 sky130_fd_sc_hd__nand2_1 _389_ (.A(_136_),
    .B(_138_),
    .Y(_015_));
 sky130_fd_sc_hd__nand2_1 _390_ (.A(_135_),
    .B(tl_i[98]),
    .Y(_139_));
 sky130_fd_sc_hd__nand2_1 _391_ (.A(net26),
    .B(u_gpio_reg_tl_o_55_),
    .Y(_140_));
 sky130_fd_sc_hd__nand2_1 _392_ (.A(_139_),
    .B(_140_),
    .Y(_016_));
 sky130_fd_sc_hd__nand2_1 _393_ (.A(_135_),
    .B(tl_i[97]),
    .Y(_141_));
 sky130_fd_sc_hd__nand2_1 _394_ (.A(net26),
    .B(u_gpio_reg_tl_o_54_),
    .Y(_142_));
 sky130_fd_sc_hd__nand2_1 _395_ (.A(_141_),
    .B(_142_),
    .Y(_017_));
 sky130_fd_sc_hd__nand2_1 _396_ (.A(_135_),
    .B(tl_i[96]),
    .Y(_143_));
 sky130_fd_sc_hd__nand2_1 _397_ (.A(net26),
    .B(u_gpio_reg_tl_o_53_),
    .Y(_144_));
 sky130_fd_sc_hd__nand2_1 _398_ (.A(_143_),
    .B(_144_),
    .Y(_018_));
 sky130_fd_sc_hd__nand2_1 _399_ (.A(_135_),
    .B(tl_i[95]),
    .Y(_145_));
 sky130_fd_sc_hd__nand2_1 _400_ (.A(net26),
    .B(u_gpio_reg_tl_o_52_),
    .Y(_146_));
 sky130_fd_sc_hd__nand2_1 _401_ (.A(_145_),
    .B(_146_),
    .Y(_019_));
 sky130_fd_sc_hd__nand2_1 _402_ (.A(_135_),
    .B(tl_i[94]),
    .Y(_147_));
 sky130_fd_sc_hd__nand2_1 _403_ (.A(net26),
    .B(u_gpio_reg_tl_o_51_),
    .Y(_148_));
 sky130_fd_sc_hd__nand2_1 _404_ (.A(_147_),
    .B(_148_),
    .Y(_020_));
 sky130_fd_sc_hd__nand2_1 _405_ (.A(_135_),
    .B(tl_i[93]),
    .Y(_149_));
 sky130_fd_sc_hd__nand2_1 _406_ (.A(net26),
    .B(u_gpio_reg_tl_o_50_),
    .Y(_150_));
 sky130_fd_sc_hd__nand2_1 _407_ (.A(_149_),
    .B(_150_),
    .Y(_021_));
 sky130_fd_sc_hd__nand2_1 _408_ (.A(_135_),
    .B(tl_i[92]),
    .Y(_151_));
 sky130_fd_sc_hd__nand2_1 _409_ (.A(net26),
    .B(u_gpio_reg_tl_o_49_),
    .Y(_152_));
 sky130_fd_sc_hd__nand2_1 _410_ (.A(_151_),
    .B(_152_),
    .Y(_022_));
 sky130_fd_sc_hd__clkinv_1 _411_ (.A(_106_),
    .Y(_153_));
 sky130_fd_sc_hd__nor2_1 _412_ (.A(tl_i[105]),
    .B(tl_i[106]),
    .Y(_154_));
 sky130_fd_sc_hd__nand3_1 _413_ (.A(_135_),
    .B(tl_i[107]),
    .C(_154_),
    .Y(_155_));
 sky130_fd_sc_hd__a21oi_1 _414_ (.A1(_107_),
    .A2(_108_),
    .B1(_153_),
    .Y(_156_));
 sky130_fd_sc_hd__a21oi_1 _415_ (.A1(_153_),
    .A2(_155_),
    .B1(_156_),
    .Y(_157_));
 sky130_fd_sc_hd__nand2_1 _416_ (.A(_157_),
    .B(_115_),
    .Y(_158_));
 sky130_fd_sc_hd__nand3_1 _417_ (.A(_158_),
    .B(_153_),
    .C(_114_),
    .Y(_159_));
 sky130_fd_sc_hd__nand2_8 _418_ (.A(net24),
    .B(_135_),
    .Y(_160_));
 sky130_fd_sc_hd__nand2_1 _419_ (.A(net26),
    .B(u_gpio_reg_tl_o_46_),
    .Y(_161_));
 sky130_fd_sc_hd__nand2_1 _420_ (.A(_160_),
    .B(_161_),
    .Y(_023_));
 sky130_fd_sc_hd__nand2_1 _421_ (.A(net26),
    .B(u_gpio_reg_tl_o_45_),
    .Y(_162_));
 sky130_fd_sc_hd__nand2_1 _422_ (.A(_160_),
    .B(_162_),
    .Y(_024_));
 sky130_fd_sc_hd__nand2_1 _423_ (.A(net26),
    .B(u_gpio_reg_tl_o_44_),
    .Y(_163_));
 sky130_fd_sc_hd__nand2_1 _424_ (.A(_160_),
    .B(_163_),
    .Y(_025_));
 sky130_fd_sc_hd__nand2_1 _425_ (.A(net26),
    .B(u_gpio_reg_tl_o_43_),
    .Y(_164_));
 sky130_fd_sc_hd__nand2_1 _426_ (.A(_160_),
    .B(_164_),
    .Y(_026_));
 sky130_fd_sc_hd__nand2_1 _427_ (.A(net26),
    .B(u_gpio_reg_tl_o_42_),
    .Y(_165_));
 sky130_fd_sc_hd__nand2_1 _428_ (.A(_160_),
    .B(_165_),
    .Y(_027_));
 sky130_fd_sc_hd__nand2_1 _429_ (.A(net26),
    .B(u_gpio_reg_tl_o_41_),
    .Y(_166_));
 sky130_fd_sc_hd__nand2_1 _430_ (.A(_160_),
    .B(_166_),
    .Y(_028_));
 sky130_fd_sc_hd__nand2_1 _431_ (.A(net26),
    .B(u_gpio_reg_tl_o_40_),
    .Y(_167_));
 sky130_fd_sc_hd__nand2_1 _432_ (.A(_160_),
    .B(_167_),
    .Y(_029_));
 sky130_fd_sc_hd__nand2_1 _433_ (.A(net26),
    .B(u_gpio_reg_tl_o_39_),
    .Y(_168_));
 sky130_fd_sc_hd__nand2_1 _434_ (.A(_160_),
    .B(_168_),
    .Y(_030_));
 sky130_fd_sc_hd__nand2_1 _435_ (.A(net26),
    .B(u_gpio_reg_tl_o_38_),
    .Y(_169_));
 sky130_fd_sc_hd__nand2_1 _436_ (.A(_160_),
    .B(_169_),
    .Y(_031_));
 sky130_fd_sc_hd__nand2_1 _437_ (.A(net26),
    .B(u_gpio_reg_tl_o_37_),
    .Y(_170_));
 sky130_fd_sc_hd__nand2_1 _438_ (.A(_160_),
    .B(_170_),
    .Y(_032_));
 sky130_fd_sc_hd__nand2_1 _439_ (.A(net26),
    .B(u_gpio_reg_tl_o_36_),
    .Y(_171_));
 sky130_fd_sc_hd__nand2_1 _440_ (.A(_160_),
    .B(_171_),
    .Y(_033_));
 sky130_fd_sc_hd__nand2_1 _441_ (.A(net26),
    .B(u_gpio_reg_tl_o_35_),
    .Y(_172_));
 sky130_fd_sc_hd__nand3_1 _442_ (.A(_135_),
    .B(reg2hw_19_),
    .C(_111_),
    .Y(_173_));
 sky130_fd_sc_hd__nand3_1 _443_ (.A(_160_),
    .B(_172_),
    .C(_173_),
    .Y(_034_));
 sky130_fd_sc_hd__nand2_4 _444_ (.A(_135_),
    .B(_111_),
    .Y(_174_));
 sky130_fd_sc_hd__nand2_1 _445_ (.A(net26),
    .B(u_gpio_reg_tl_o_34_),
    .Y(_175_));
 sky130_fd_sc_hd__o211ai_1 _446_ (.A1(_129_),
    .A2(_174_),
    .B1(_175_),
    .C1(_160_),
    .Y(_035_));
 sky130_fd_sc_hd__nand2_1 _447_ (.A(net26),
    .B(u_gpio_reg_tl_o_33_),
    .Y(_176_));
 sky130_fd_sc_hd__o211ai_1 _448_ (.A1(_131_),
    .A2(_174_),
    .B1(_176_),
    .C1(_160_),
    .Y(_036_));
 sky130_fd_sc_hd__nand2_1 _449_ (.A(net26),
    .B(u_gpio_reg_tl_o_32_),
    .Y(_177_));
 sky130_fd_sc_hd__o211ai_1 _450_ (.A1(_133_),
    .A2(_174_),
    .B1(_177_),
    .C1(_160_),
    .Y(_037_));
 sky130_fd_sc_hd__nand2_1 _451_ (.A(net26),
    .B(u_gpio_reg_tl_o_31_),
    .Y(_178_));
 sky130_fd_sc_hd__nand3_1 _452_ (.A(_135_),
    .B(reg2hw_15_),
    .C(_111_),
    .Y(_179_));
 sky130_fd_sc_hd__nand3_1 _453_ (.A(_160_),
    .B(_178_),
    .C(_179_),
    .Y(_038_));
 sky130_fd_sc_hd__nand2_1 _454_ (.A(net26),
    .B(u_gpio_reg_tl_o_30_),
    .Y(_180_));
 sky130_fd_sc_hd__o211ai_1 _455_ (.A1(_087_),
    .A2(_174_),
    .B1(_180_),
    .C1(_160_),
    .Y(_039_));
 sky130_fd_sc_hd__nand2_1 _456_ (.A(net26),
    .B(u_gpio_reg_tl_o_29_),
    .Y(_181_));
 sky130_fd_sc_hd__o211ai_1 _457_ (.A1(_091_),
    .A2(_174_),
    .B1(_181_),
    .C1(_160_),
    .Y(_040_));
 sky130_fd_sc_hd__nand2_1 _458_ (.A(_105_),
    .B(u_gpio_reg_tl_o_28_),
    .Y(_182_));
 sky130_fd_sc_hd__o211ai_1 _459_ (.A1(_095_),
    .A2(_174_),
    .B1(_182_),
    .C1(_160_),
    .Y(_041_));
 sky130_fd_sc_hd__inv_1 _460_ (.A(reg2hw_11_),
    .Y(_183_));
 sky130_fd_sc_hd__nand2_1 _461_ (.A(_105_),
    .B(u_gpio_reg_tl_o_27_),
    .Y(_184_));
 sky130_fd_sc_hd__o211ai_1 _462_ (.A1(_183_),
    .A2(_174_),
    .B1(_184_),
    .C1(_160_),
    .Y(_042_));
 sky130_fd_sc_hd__nand2_1 _463_ (.A(_105_),
    .B(u_gpio_reg_tl_o_26_),
    .Y(_185_));
 sky130_fd_sc_hd__o211ai_1 _464_ (.A1(_123_),
    .A2(_174_),
    .B1(_185_),
    .C1(_160_),
    .Y(_043_));
 sky130_fd_sc_hd__nand2_1 _465_ (.A(_105_),
    .B(u_gpio_reg_tl_o_25_),
    .Y(_186_));
 sky130_fd_sc_hd__o211ai_1 _466_ (.A1(_125_),
    .A2(_174_),
    .B1(_186_),
    .C1(_160_),
    .Y(_044_));
 sky130_fd_sc_hd__nand2_1 _467_ (.A(_105_),
    .B(u_gpio_reg_tl_o_24_),
    .Y(_187_));
 sky130_fd_sc_hd__o211ai_1 _468_ (.A1(_127_),
    .A2(_174_),
    .B1(_187_),
    .C1(_160_),
    .Y(_045_));
 sky130_fd_sc_hd__nand2_1 _469_ (.A(_158_),
    .B(_153_),
    .Y(_188_));
 sky130_fd_sc_hd__nor2_4 _470_ (.A(_105_),
    .B(_188_),
    .Y(_189_));
 sky130_fd_sc_hd__inv_1 _471_ (.A(hw2reg_7_),
    .Y(_190_));
 sky130_fd_sc_hd__lpflow_clkinvkapwr_1 _472_ (.A(tl_i[62]),
    .Y(_191_));
 sky130_fd_sc_hd__o21ai_0 _473_ (.A1(_190_),
    .A2(net37),
    .B1(_110_),
    .Y(_192_));
 sky130_fd_sc_hd__o21ai_0 _474_ (.A1(reg2hw_7_),
    .A2(tl_i[62]),
    .B1(_192_),
    .Y(_193_));
 sky130_fd_sc_hd__nor2_1 _475_ (.A(u_gpio_reg_tl_o_23_),
    .B(_135_),
    .Y(_194_));
 sky130_fd_sc_hd__a21oi_1 _476_ (.A1(_189_),
    .A2(_193_),
    .B1(_194_),
    .Y(_046_));
 sky130_fd_sc_hd__inv_1 _477_ (.A(hw2reg_6_),
    .Y(_195_));
 sky130_fd_sc_hd__o21ai_0 _478_ (.A1(_195_),
    .A2(net37),
    .B1(_110_),
    .Y(_196_));
 sky130_fd_sc_hd__o21ai_0 _479_ (.A1(reg2hw_6_),
    .A2(tl_i[62]),
    .B1(_196_),
    .Y(_197_));
 sky130_fd_sc_hd__nor2_1 _480_ (.A(u_gpio_reg_tl_o_22_),
    .B(_135_),
    .Y(_198_));
 sky130_fd_sc_hd__a21oi_1 _481_ (.A1(_189_),
    .A2(_197_),
    .B1(_198_),
    .Y(_047_));
 sky130_fd_sc_hd__inv_1 _482_ (.A(hw2reg_5_),
    .Y(_199_));
 sky130_fd_sc_hd__o21ai_0 _483_ (.A1(_199_),
    .A2(net37),
    .B1(_110_),
    .Y(_200_));
 sky130_fd_sc_hd__o21ai_0 _484_ (.A1(reg2hw_5_),
    .A2(tl_i[62]),
    .B1(_200_),
    .Y(_201_));
 sky130_fd_sc_hd__nor2_1 _485_ (.A(u_gpio_reg_tl_o_21_),
    .B(_135_),
    .Y(_202_));
 sky130_fd_sc_hd__a21oi_1 _486_ (.A1(_189_),
    .A2(_201_),
    .B1(_202_),
    .Y(_048_));
 sky130_fd_sc_hd__inv_1 _487_ (.A(hw2reg_4_),
    .Y(_203_));
 sky130_fd_sc_hd__o21ai_0 _488_ (.A1(net37),
    .A2(_203_),
    .B1(_110_),
    .Y(_204_));
 sky130_fd_sc_hd__o21ai_0 _489_ (.A1(reg2hw_4_),
    .A2(tl_i[62]),
    .B1(_204_),
    .Y(_205_));
 sky130_fd_sc_hd__nor2_1 _490_ (.A(u_gpio_reg_tl_o_20_),
    .B(_135_),
    .Y(_206_));
 sky130_fd_sc_hd__a21oi_1 _491_ (.A1(_189_),
    .A2(_205_),
    .B1(_206_),
    .Y(_049_));
 sky130_fd_sc_hd__inv_1 _492_ (.A(hw2reg_3_),
    .Y(_207_));
 sky130_fd_sc_hd__a21oi_1 _493_ (.A1(tl_i[63]),
    .A2(reg2hw_3_),
    .B1(tl_i[62]),
    .Y(_208_));
 sky130_fd_sc_hd__a21oi_1 _494_ (.A1(_110_),
    .A2(_207_),
    .B1(_208_),
    .Y(_209_));
 sky130_fd_sc_hd__a31oi_1 _495_ (.A1(_110_),
    .A2(net37),
    .A3(u_gpio_reg_u_reg_core_data_in_qs_3_),
    .B1(_209_),
    .Y(_210_));
 sky130_fd_sc_hd__nor2_1 _496_ (.A(u_gpio_reg_tl_o_19_),
    .B(_135_),
    .Y(_211_));
 sky130_fd_sc_hd__a21oi_1 _497_ (.A1(_189_),
    .A2(_210_),
    .B1(_211_),
    .Y(_050_));
 sky130_fd_sc_hd__inv_1 _498_ (.A(hw2reg_2_),
    .Y(_212_));
 sky130_fd_sc_hd__o21ai_0 _499_ (.A1(net37),
    .A2(_212_),
    .B1(_110_),
    .Y(_213_));
 sky130_fd_sc_hd__nand2_1 _500_ (.A(_083_),
    .B(net37),
    .Y(_214_));
 sky130_fd_sc_hd__a32oi_1 _501_ (.A1(_110_),
    .A2(net37),
    .A3(u_gpio_reg_u_reg_core_data_in_qs_2_),
    .B1(_213_),
    .B2(_214_),
    .Y(_215_));
 sky130_fd_sc_hd__nor2_1 _502_ (.A(u_gpio_reg_tl_o_18_),
    .B(_135_),
    .Y(_216_));
 sky130_fd_sc_hd__a21oi_1 _503_ (.A1(_189_),
    .A2(_215_),
    .B1(_216_),
    .Y(_051_));
 sky130_fd_sc_hd__nor3_1 _504_ (.A(tl_i[63]),
    .B(hw2reg_1_),
    .C(net37),
    .Y(_217_));
 sky130_fd_sc_hd__a21oi_1 _505_ (.A1(_110_),
    .A2(u_gpio_reg_u_reg_core_data_in_qs_1_),
    .B1(tl_i[62]),
    .Y(_218_));
 sky130_fd_sc_hd__nor2_1 _506_ (.A(_217_),
    .B(_218_),
    .Y(_219_));
 sky130_fd_sc_hd__a21oi_1 _507_ (.A1(reg2hw_1_),
    .A2(_111_),
    .B1(_219_),
    .Y(_220_));
 sky130_fd_sc_hd__nor2_1 _508_ (.A(u_gpio_reg_tl_o_17_),
    .B(_135_),
    .Y(_221_));
 sky130_fd_sc_hd__a21oi_1 _509_ (.A1(_189_),
    .A2(_220_),
    .B1(_221_),
    .Y(_052_));
 sky130_fd_sc_hd__nor3_1 _510_ (.A(tl_i[63]),
    .B(hw2reg_0_),
    .C(net37),
    .Y(_222_));
 sky130_fd_sc_hd__a21oi_1 _511_ (.A1(_110_),
    .A2(u_gpio_reg_u_reg_core_data_in_qs_0_),
    .B1(tl_i[62]),
    .Y(_223_));
 sky130_fd_sc_hd__nor2_1 _512_ (.A(_222_),
    .B(_223_),
    .Y(_224_));
 sky130_fd_sc_hd__a21oi_1 _513_ (.A1(reg2hw_0_),
    .A2(_111_),
    .B1(_224_),
    .Y(_225_));
 sky130_fd_sc_hd__nor2_1 _514_ (.A(u_gpio_reg_tl_o_16_),
    .B(_135_),
    .Y(_226_));
 sky130_fd_sc_hd__a21oi_1 _515_ (.A1(_189_),
    .A2(_225_),
    .B1(_226_),
    .Y(_053_));
 sky130_fd_sc_hd__nor4_4 _516_ (.A(tl_i[63]),
    .B(net37),
    .C(_109_),
    .D(_115_),
    .Y(_227_));
 sky130_fd_sc_hd__nand2_1 _517_ (.A(_227_),
    .B(tl_i[30]),
    .Y(_228_));
 sky130_fd_sc_hd__o21ai_0 _518_ (.A1(_195_),
    .A2(_227_),
    .B1(_228_),
    .Y(_054_));
 sky130_fd_sc_hd__nand2_1 _519_ (.A(_227_),
    .B(tl_i[29]),
    .Y(_229_));
 sky130_fd_sc_hd__o21ai_0 _520_ (.A1(_199_),
    .A2(_227_),
    .B1(_229_),
    .Y(_055_));
 sky130_fd_sc_hd__nand2_1 _521_ (.A(_227_),
    .B(tl_i[28]),
    .Y(_230_));
 sky130_fd_sc_hd__o21ai_0 _522_ (.A1(_203_),
    .A2(_227_),
    .B1(_230_),
    .Y(_056_));
 sky130_fd_sc_hd__nand2_1 _523_ (.A(_227_),
    .B(tl_i[26]),
    .Y(_231_));
 sky130_fd_sc_hd__o21ai_0 _524_ (.A1(_212_),
    .A2(_227_),
    .B1(_231_),
    .Y(_057_));
 sky130_fd_sc_hd__mux2_1 _525_ (.A0(hw2reg_1_),
    .A1(tl_i[25]),
    .S(_227_),
    .X(_058_));
 sky130_fd_sc_hd__mux2_1 _526_ (.A0(hw2reg_0_),
    .A1(tl_i[24]),
    .S(_227_),
    .X(_059_));
 sky130_fd_sc_hd__clkinv_1 _527_ (.A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_),
    .Y(_232_));
 sky130_fd_sc_hd__inv_1 _528_ (.A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_2_),
    .Y(_233_));
 sky130_fd_sc_hd__inv_1 _529_ (.A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_),
    .Y(_234_));
 sky130_fd_sc_hd__inv_1 _530_ (.A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_1_),
    .Y(_235_));
 sky130_fd_sc_hd__nor2_1 _531_ (.A(_234_),
    .B(_235_),
    .Y(_236_));
 sky130_fd_sc_hd__inv_1 _532_ (.A(_236_),
    .Y(_237_));
 sky130_fd_sc_hd__nor2_1 _533_ (.A(_233_),
    .B(_237_),
    .Y(_238_));
 sky130_fd_sc_hd__inv_1 _534_ (.A(_238_),
    .Y(_239_));
 sky130_fd_sc_hd__nor2_1 _535_ (.A(_232_),
    .B(_239_),
    .Y(_240_));
 sky130_fd_sc_hd__inv_1 _536_ (.A(_240_),
    .Y(_241_));
 sky130_fd_sc_hd__xnor2_1 _537_ (.A(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_3__u_filter_filter_q),
    .Y(_242_));
 sky130_fd_sc_hd__inv_1 _538_ (.A(_242_),
    .Y(_243_));
 sky130_fd_sc_hd__a21oi_1 _539_ (.A1(_241_),
    .A2(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_),
    .B1(_243_),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_0_));
 sky130_fd_sc_hd__o21ai_0 _540_ (.A1(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_2_),
    .A2(_236_),
    .B1(_242_),
    .Y(_244_));
 sky130_fd_sc_hd__a21oi_1 _541_ (.A1(_238_),
    .A2(_232_),
    .B1(_244_),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_2_));
 sky130_fd_sc_hd__inv_1 _542_ (.A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_),
    .Y(_245_));
 sky130_fd_sc_hd__inv_1 _543_ (.A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .Y(_246_));
 sky130_fd_sc_hd__inv_1 _544_ (.A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .Y(_247_));
 sky130_fd_sc_hd__nor2_1 _545_ (.A(_246_),
    .B(_247_),
    .Y(_248_));
 sky130_fd_sc_hd__clkinv_1 _546_ (.A(_248_),
    .Y(_249_));
 sky130_fd_sc_hd__xnor2_1 _547_ (.A(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_0__u_filter_filter_q),
    .Y(_250_));
 sky130_fd_sc_hd__clkinv_1 _548_ (.A(_250_),
    .Y(_251_));
 sky130_fd_sc_hd__a21oi_1 _549_ (.A1(_245_),
    .A2(_249_),
    .B1(_251_),
    .Y(_252_));
 sky130_fd_sc_hd__o31a_1 _550_ (.A1(net27),
    .A2(_245_),
    .A3(_249_),
    .B1(_252_),
    .X(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_2_));
 sky130_fd_sc_hd__nor2_1 _551_ (.A(_245_),
    .B(_249_),
    .Y(_253_));
 sky130_fd_sc_hd__nand2_1 _552_ (.A(_253_),
    .B(net27),
    .Y(_254_));
 sky130_fd_sc_hd__nand2_1 _553_ (.A(_246_),
    .B(_247_),
    .Y(_255_));
 sky130_fd_sc_hd__nand2_1 _554_ (.A(_249_),
    .B(_255_),
    .Y(_256_));
 sky130_fd_sc_hd__a21oi_1 _555_ (.A1(_254_),
    .A2(_256_),
    .B1(_251_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_));
 sky130_fd_sc_hd__a21oi_1 _556_ (.A1(_254_),
    .A2(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .B1(_251_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_0_));
 sky130_fd_sc_hd__nor2_1 _557_ (.A(net27),
    .B(_253_),
    .Y(_257_));
 sky130_fd_sc_hd__nor2_1 _558_ (.A(_251_),
    .B(_257_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_3_));
 sky130_fd_sc_hd__nor2_1 _559_ (.A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_),
    .B(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_1_),
    .Y(_258_));
 sky130_fd_sc_hd__o21ai_0 _560_ (.A1(_236_),
    .A2(_258_),
    .B1(_241_),
    .Y(_259_));
 sky130_fd_sc_hd__inv_1 _561_ (.A(_259_),
    .Y(_260_));
 sky130_fd_sc_hd__nor2_1 _562_ (.A(_243_),
    .B(_260_),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_1_));
 sky130_fd_sc_hd__inv_1 _563_ (.A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_2_),
    .Y(_261_));
 sky130_fd_sc_hd__inv_1 _564_ (.A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .Y(_262_));
 sky130_fd_sc_hd__inv_1 _565_ (.A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_),
    .Y(_263_));
 sky130_fd_sc_hd__nor2_1 _566_ (.A(_262_),
    .B(_263_),
    .Y(_264_));
 sky130_fd_sc_hd__clkinv_1 _567_ (.A(_264_),
    .Y(_265_));
 sky130_fd_sc_hd__xnor2_1 _568_ (.A(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_2__u_filter_filter_q),
    .Y(_266_));
 sky130_fd_sc_hd__clkinv_1 _569_ (.A(_266_),
    .Y(_267_));
 sky130_fd_sc_hd__a21oi_1 _570_ (.A1(_261_),
    .A2(_265_),
    .B1(_267_),
    .Y(_268_));
 sky130_fd_sc_hd__o31a_1 _571_ (.A1(_261_),
    .A2(net29),
    .A3(_265_),
    .B1(_268_),
    .X(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_2_));
 sky130_fd_sc_hd__nor2_1 _572_ (.A(_261_),
    .B(_265_),
    .Y(_269_));
 sky130_fd_sc_hd__nand2_1 _573_ (.A(_269_),
    .B(net29),
    .Y(_270_));
 sky130_fd_sc_hd__nand2_1 _574_ (.A(_262_),
    .B(_263_),
    .Y(_271_));
 sky130_fd_sc_hd__nand2_1 _575_ (.A(_265_),
    .B(_271_),
    .Y(_272_));
 sky130_fd_sc_hd__a21oi_1 _576_ (.A1(_270_),
    .A2(_272_),
    .B1(_267_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_));
 sky130_fd_sc_hd__a21oi_1 _577_ (.A1(_270_),
    .A2(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .B1(_267_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_0_));
 sky130_fd_sc_hd__nor2_1 _578_ (.A(net29),
    .B(_269_),
    .Y(_273_));
 sky130_fd_sc_hd__nor2_1 _579_ (.A(_267_),
    .B(_273_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_3_));
 sky130_fd_sc_hd__nor2_1 _580_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_),
    .B(_100_),
    .Y(_274_));
 sky130_fd_sc_hd__a21oi_1 _581_ (.A1(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .A2(net28),
    .B1(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_2_),
    .Y(_275_));
 sky130_fd_sc_hd__nor3_1 _582_ (.A(_274_),
    .B(_275_),
    .C(_096_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_2_));
 sky130_fd_sc_hd__a21oi_1 _583_ (.A1(_239_),
    .A2(_232_),
    .B1(_243_),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_3_));
 sky130_fd_sc_hd__a21oi_1 _584_ (.A1(_099_),
    .A2(_100_),
    .B1(_096_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_));
 sky130_fd_sc_hd__inv_1 _585_ (.A(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .Y(_276_));
 sky130_fd_sc_hd__nand2_1 _586_ (.A(reg2hw_19_),
    .B(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .Y(_277_));
 sky130_fd_sc_hd__o21ai_1 _587_ (.A1(reg2hw_19_),
    .A2(_276_),
    .B1(_277_),
    .Y(hw2reg_12_));
 sky130_fd_sc_hd__inv_1 _588_ (.A(u_gpio_core_data_in_q_3_),
    .Y(_278_));
 sky130_fd_sc_hd__a21oi_1 _589_ (.A1(_278_),
    .A2(reg2hw_3_),
    .B1(reg2hw_11_),
    .Y(_279_));
 sky130_fd_sc_hd__a211oi_1 _590_ (.A1(reg2hw_7_),
    .A2(u_gpio_core_data_in_q_3_),
    .B1(reg2hw_15_),
    .C1(hw2reg_12_),
    .Y(_280_));
 sky130_fd_sc_hd__a21oi_1 _591_ (.A1(hw2reg_12_),
    .A2(_279_),
    .B1(_280_),
    .Y(u_gpio_core_intr_gpio_o_3_));
 sky130_fd_sc_hd__o2111ai_1 _592_ (.A1(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_),
    .A2(_247_),
    .B1(net27),
    .C1(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .D1(_252_),
    .Y(_281_));
 sky130_fd_sc_hd__nand2_1 _593_ (.A(_281_),
    .B(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .Y(_282_));
 sky130_fd_sc_hd__o21ai_0 _594_ (.A1(_081_),
    .A2(_281_),
    .B1(_282_),
    .Y(_060_));
 sky130_fd_sc_hd__nor2_1 _595_ (.A(_104_),
    .B(_102_),
    .Y(_283_));
 sky130_fd_sc_hd__nand3_1 _596_ (.A(_283_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_2_),
    .C(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_),
    .Y(_284_));
 sky130_fd_sc_hd__nand2_1 _597_ (.A(_284_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .Y(_285_));
 sky130_fd_sc_hd__o21ai_0 _598_ (.A1(_079_),
    .A2(_284_),
    .B1(_285_),
    .Y(_061_));
 sky130_fd_sc_hd__o2111ai_1 _599_ (.A1(_262_),
    .A2(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_2_),
    .B1(net29),
    .C1(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_),
    .D1(_268_),
    .Y(_286_));
 sky130_fd_sc_hd__nand2_1 _600_ (.A(_286_),
    .B(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .Y(_287_));
 sky130_fd_sc_hd__o21ai_0 _601_ (.A1(_077_),
    .A2(_286_),
    .B1(_287_),
    .Y(_062_));
 sky130_fd_sc_hd__nor2_1 _602_ (.A(_232_),
    .B(_244_),
    .Y(_288_));
 sky130_fd_sc_hd__nand3_1 _603_ (.A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_0_),
    .B(_259_),
    .C(_288_),
    .Y(_289_));
 sky130_fd_sc_hd__nand2_1 _604_ (.A(_289_),
    .B(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .Y(_290_));
 sky130_fd_sc_hd__o21ai_0 _605_ (.A1(_276_),
    .A2(_289_),
    .B1(_290_),
    .Y(_063_));
 sky130_fd_sc_hd__nand2_1 _606_ (.A(_227_),
    .B(tl_i[27]),
    .Y(_291_));
 sky130_fd_sc_hd__o21ai_0 _607_ (.A1(_207_),
    .A2(_227_),
    .B1(_291_),
    .Y(_064_));
 sky130_fd_sc_hd__nand2_1 _608_ (.A(_227_),
    .B(tl_i[31]),
    .Y(_292_));
 sky130_fd_sc_hd__o21ai_0 _609_ (.A1(_190_),
    .A2(_227_),
    .B1(_292_),
    .Y(_065_));
 sky130_fd_sc_hd__a21oi_1 _610_ (.A1(u_gpio_reg_tl_o_1_),
    .A2(net26),
    .B1(_156_),
    .Y(_293_));
 sky130_fd_sc_hd__nand2_1 _611_ (.A(_158_),
    .B(_293_),
    .Y(_066_));
 sky130_fd_sc_hd__o21ai_0 _612_ (.A1(u_gpio_reg_tl_o_0_),
    .A2(tl_i[0]),
    .B1(net26),
    .Y(_067_));
 sky130_fd_sc_hd__nand2_1 _613_ (.A(net26),
    .B(u_gpio_reg_tl_o_47_),
    .Y(_294_));
 sky130_fd_sc_hd__nand2_1 _614_ (.A(_160_),
    .B(_294_),
    .Y(_068_));
 sky130_fd_sc_hd__nand2_1 _615_ (.A(_135_),
    .B(tl_i[99]),
    .Y(_295_));
 sky130_fd_sc_hd__nand2_1 _616_ (.A(net26),
    .B(u_gpio_reg_tl_o_56_),
    .Y(_296_));
 sky130_fd_sc_hd__nand2_1 _617_ (.A(_295_),
    .B(_296_),
    .Y(_069_));
 sky130_fd_sc_hd__nand2_1 _618_ (.A(_135_),
    .B(tl_i[101]),
    .Y(_297_));
 sky130_fd_sc_hd__nand2_1 _619_ (.A(net26),
    .B(u_gpio_reg_tl_o_58_),
    .Y(_298_));
 sky130_fd_sc_hd__nand2_1 _620_ (.A(_297_),
    .B(_298_),
    .Y(_070_));
 sky130_fd_sc_hd__mux2_1 _621_ (.A0(tl_i[31]),
    .A1(reg2hw_7_),
    .S(net25),
    .X(_071_));
 sky130_fd_sc_hd__mux2_1 _622_ (.A0(tl_i[43]),
    .A1(reg2hw_19_),
    .S(net25),
    .X(_072_));
 sky130_fd_sc_hd__nor2_1 _623_ (.A(tl_i[35]),
    .B(net25),
    .Y(_299_));
 sky130_fd_sc_hd__a21oi_1 _624_ (.A1(_183_),
    .A2(net25),
    .B1(_299_),
    .Y(_073_));
 sky130_fd_sc_hd__mux2_1 _625_ (.A0(tl_i[39]),
    .A1(reg2hw_15_),
    .S(net25),
    .X(_074_));
 sky130_fd_sc_hd__mux2_1 _626_ (.A0(tl_i[27]),
    .A1(reg2hw_3_),
    .S(net25),
    .X(_075_));
 sky130_fd_sc_hd__nand2_1 _627_ (.A(net26),
    .B(u_gpio_reg_tl_o_62_),
    .Y(_300_));
 sky130_fd_sc_hd__nand2_1 _628_ (.A(_155_),
    .B(_300_),
    .Y(_076_));
 sky130_fd_sc_hd__dfrtp_1 _629_ (.D(_076_),
    .Q(u_gpio_reg_tl_o_62_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _630_ (.D(_060_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _631_ (.D(_061_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _632_ (.D(_062_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _633_ (.D(_063_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _634_ (.D(_059_),
    .Q(hw2reg_0_),
    .RESET_B(net32),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _635_ (.D(_058_),
    .Q(hw2reg_1_),
    .RESET_B(net32),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _636_ (.D(_057_),
    .Q(hw2reg_2_),
    .RESET_B(net32),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _637_ (.D(_064_),
    .Q(hw2reg_3_),
    .RESET_B(net32),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _638_ (.D(_056_),
    .Q(hw2reg_4_),
    .RESET_B(net32),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _639_ (.D(_055_),
    .Q(hw2reg_5_),
    .RESET_B(net32),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _640_ (.D(_054_),
    .Q(hw2reg_6_),
    .RESET_B(net32),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _641_ (.D(_065_),
    .Q(hw2reg_7_),
    .RESET_B(net32),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _642_ (.D(_066_),
    .Q(u_gpio_reg_tl_o_1_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _643_ (.D(_067_),
    .Q(u_gpio_reg_tl_o_65_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _644_ (.D(_053_),
    .Q(u_gpio_reg_tl_o_16_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _645_ (.D(_052_),
    .Q(u_gpio_reg_tl_o_17_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _646_ (.D(_051_),
    .Q(u_gpio_reg_tl_o_18_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _647_ (.D(_050_),
    .Q(u_gpio_reg_tl_o_19_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _648_ (.D(_049_),
    .Q(u_gpio_reg_tl_o_20_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _649_ (.D(_048_),
    .Q(u_gpio_reg_tl_o_21_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _650_ (.D(_047_),
    .Q(u_gpio_reg_tl_o_22_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _651_ (.D(_046_),
    .Q(u_gpio_reg_tl_o_23_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _652_ (.D(_045_),
    .Q(u_gpio_reg_tl_o_24_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _653_ (.D(_044_),
    .Q(u_gpio_reg_tl_o_25_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _654_ (.D(_043_),
    .Q(u_gpio_reg_tl_o_26_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _655_ (.D(_042_),
    .Q(u_gpio_reg_tl_o_27_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _656_ (.D(_041_),
    .Q(u_gpio_reg_tl_o_28_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _657_ (.D(_040_),
    .Q(u_gpio_reg_tl_o_29_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _658_ (.D(_039_),
    .Q(u_gpio_reg_tl_o_30_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _659_ (.D(_038_),
    .Q(u_gpio_reg_tl_o_31_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _660_ (.D(_037_),
    .Q(u_gpio_reg_tl_o_32_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _661_ (.D(_036_),
    .Q(u_gpio_reg_tl_o_33_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _662_ (.D(_035_),
    .Q(u_gpio_reg_tl_o_34_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _663_ (.D(_034_),
    .Q(u_gpio_reg_tl_o_35_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _664_ (.D(_033_),
    .Q(u_gpio_reg_tl_o_36_),
    .RESET_B(net33),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _665_ (.D(_032_),
    .Q(u_gpio_reg_tl_o_37_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _666_ (.D(_031_),
    .Q(u_gpio_reg_tl_o_38_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _667_ (.D(_030_),
    .Q(u_gpio_reg_tl_o_39_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _668_ (.D(_029_),
    .Q(u_gpio_reg_tl_o_40_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _669_ (.D(_028_),
    .Q(u_gpio_reg_tl_o_41_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _670_ (.D(_027_),
    .Q(u_gpio_reg_tl_o_42_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _671_ (.D(_026_),
    .Q(u_gpio_reg_tl_o_43_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _672_ (.D(_025_),
    .Q(u_gpio_reg_tl_o_44_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _673_ (.D(_024_),
    .Q(u_gpio_reg_tl_o_45_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _674_ (.D(_023_),
    .Q(u_gpio_reg_tl_o_46_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _675_ (.D(_068_),
    .Q(u_gpio_reg_tl_o_47_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _676_ (.D(_022_),
    .Q(u_gpio_reg_tl_o_49_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _677_ (.D(_021_),
    .Q(u_gpio_reg_tl_o_50_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _678_ (.D(_020_),
    .Q(u_gpio_reg_tl_o_51_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _679_ (.D(_019_),
    .Q(u_gpio_reg_tl_o_52_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _680_ (.D(_018_),
    .Q(u_gpio_reg_tl_o_53_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _681_ (.D(_017_),
    .Q(u_gpio_reg_tl_o_54_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _682_ (.D(_016_),
    .Q(u_gpio_reg_tl_o_55_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _683_ (.D(_069_),
    .Q(u_gpio_reg_tl_o_56_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _684_ (.D(_015_),
    .Q(u_gpio_reg_tl_o_57_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _685_ (.D(_070_),
    .Q(u_gpio_reg_tl_o_58_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _686_ (.D(_014_),
    .Q(reg2hw_4_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _687_ (.D(_013_),
    .Q(reg2hw_5_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _688_ (.D(_012_),
    .Q(reg2hw_6_),
    .RESET_B(net34),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _689_ (.D(_071_),
    .Q(reg2hw_7_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _690_ (.D(_011_),
    .Q(reg2hw_16_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _691_ (.D(_010_),
    .Q(reg2hw_17_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _692_ (.D(_009_),
    .Q(reg2hw_18_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _693_ (.D(_072_),
    .Q(reg2hw_19_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _694_ (.D(_008_),
    .Q(reg2hw_8_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _695_ (.D(_007_),
    .Q(reg2hw_9_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _696_ (.D(_006_),
    .Q(reg2hw_10_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _697_ (.D(_073_),
    .Q(reg2hw_11_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _698_ (.D(_005_),
    .Q(reg2hw_12_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _699_ (.D(_004_),
    .Q(reg2hw_13_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _700_ (.D(_003_),
    .Q(reg2hw_14_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _701_ (.D(_074_),
    .Q(reg2hw_15_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _702_ (.D(_002_),
    .Q(reg2hw_0_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _703_ (.D(_001_),
    .Q(reg2hw_1_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _704_ (.D(_000_),
    .Q(reg2hw_2_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _705_ (.D(_075_),
    .Q(reg2hw_3_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _706_ (.D(u_reg_reset_sync_intq),
    .Q(reg_rst_ni),
    .RESET_B(rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _707_ (.D(net20),
    .Q(u_reg_reset_sync_intq),
    .RESET_B(rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _707__21 (.HI(net20));
 sky130_fd_sc_hd__dfrtp_1 _708_ (.D(hw2reg_9_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_0_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _709_ (.D(hw2reg_10_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_1_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _710_ (.D(hw2reg_11_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_2_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _711_ (.D(hw2reg_12_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_3_),
    .RESET_B(net35),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _712_ (.D(net21),
    .Q(u_gpio_core_state_rst_ni),
    .RESET_B(core_rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _712__22 (.HI(net21));
 sky130_fd_sc_hd__dfrtp_1 _713_ (.D(net22),
    .Q(u_gpio_core_filter_rst_ni),
    .RESET_B(core_rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _713__23 (.HI(net22));
 sky130_fd_sc_hd__dfrtp_1 _714_ (.D(u_gpio_core_gen_input_filter_3__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _715_ (.D(cio_gpio_i[3]),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_gen_async_prim_flop_2sync_intq),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _716_ (.D(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_filter_q),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _717_ (.D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _718_ (.D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_1_),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _719_ (.D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_2_),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _720_ (.D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _721_ (.D(u_gpio_core_gen_input_filter_2__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _722_ (.D(cio_gpio_i[2]),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_gen_async_prim_flop_2sync_intq),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _723_ (.D(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_filter_q),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _724_ (.D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _725_ (.D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _726_ (.D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_2_),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _727_ (.D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _728_ (.D(u_gpio_core_gen_input_filter_1__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _729_ (.D(cio_gpio_i[1]),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_gen_async_prim_flop_2sync_intq),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _730_ (.D(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_filter_q),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _731_ (.D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _732_ (.D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _733_ (.D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_2_),
    .RESET_B(net30),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _734_ (.D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_),
    .RESET_B(net31),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _735_ (.D(u_gpio_core_gen_input_filter_0__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .RESET_B(net31),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _736_ (.D(cio_gpio_i[0]),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_gen_async_prim_flop_2sync_intq),
    .RESET_B(net31),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _737_ (.D(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_filter_q),
    .RESET_B(net31),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _738_ (.D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .RESET_B(net31),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _739_ (.D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .RESET_B(net31),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _740_ (.D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_),
    .RESET_B(net31),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _741_ (.D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
    .RESET_B(net31),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _742_ (.D(hw2reg_9_),
    .Q(u_gpio_core_data_in_q_0_),
    .RESET_B(net32),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _743_ (.D(hw2reg_10_),
    .Q(u_gpio_core_data_in_q_1_),
    .RESET_B(net32),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _744_ (.D(hw2reg_11_),
    .Q(u_gpio_core_data_in_q_2_),
    .RESET_B(net32),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _745_ (.D(hw2reg_12_),
    .Q(u_gpio_core_data_in_q_3_),
    .RESET_B(net32),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _746_ (.D(u_core_reset_sync_intq),
    .Q(core_rst_ni),
    .RESET_B(rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _747_ (.D(net23),
    .Q(u_core_reset_sync_intq),
    .RESET_B(rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _747__24 (.HI(net23));
 sky130_fd_sc_hd__buf_2 _750_ (.A(u_gpio_reg_tl_o_0_),
    .X(tl_o[0]));
 sky130_fd_sc_hd__buf_2 _751_ (.A(u_gpio_reg_tl_o_1_),
    .X(tl_o[1]));
 sky130_fd_sc_hd__buf_4 _752_ (.A(net),
    .X(tl_o[2]));
 sky130_fd_sc_hd__conb_1 _752__1 (.LO(net));
 sky130_fd_sc_hd__buf_4 _753_ (.A(net1),
    .X(tl_o[3]));
 sky130_fd_sc_hd__conb_1 _753__2 (.LO(net1));
 sky130_fd_sc_hd__buf_4 _754_ (.A(net2),
    .X(tl_o[4]));
 sky130_fd_sc_hd__conb_1 _754__3 (.LO(net2));
 sky130_fd_sc_hd__buf_4 _755_ (.A(net3),
    .X(tl_o[5]));
 sky130_fd_sc_hd__conb_1 _755__4 (.LO(net3));
 sky130_fd_sc_hd__buf_4 _756_ (.A(net4),
    .X(tl_o[6]));
 sky130_fd_sc_hd__conb_1 _756__5 (.LO(net4));
 sky130_fd_sc_hd__buf_4 _757_ (.A(net5),
    .X(tl_o[7]));
 sky130_fd_sc_hd__conb_1 _757__6 (.LO(net5));
 sky130_fd_sc_hd__buf_4 _758_ (.A(net6),
    .X(tl_o[8]));
 sky130_fd_sc_hd__conb_1 _758__7 (.LO(net6));
 sky130_fd_sc_hd__buf_4 _759_ (.A(net7),
    .X(tl_o[9]));
 sky130_fd_sc_hd__conb_1 _759__8 (.LO(net7));
 sky130_fd_sc_hd__buf_4 _760_ (.A(net8),
    .X(tl_o[10]));
 sky130_fd_sc_hd__conb_1 _760__9 (.LO(net8));
 sky130_fd_sc_hd__buf_4 _761_ (.A(net9),
    .X(tl_o[11]));
 sky130_fd_sc_hd__conb_1 _761__10 (.LO(net9));
 sky130_fd_sc_hd__buf_4 _762_ (.A(net10),
    .X(tl_o[12]));
 sky130_fd_sc_hd__conb_1 _762__11 (.LO(net10));
 sky130_fd_sc_hd__buf_4 _763_ (.A(net11),
    .X(tl_o[13]));
 sky130_fd_sc_hd__conb_1 _763__12 (.LO(net11));
 sky130_fd_sc_hd__buf_4 _764_ (.A(net12),
    .X(tl_o[14]));
 sky130_fd_sc_hd__conb_1 _764__13 (.LO(net12));
 sky130_fd_sc_hd__buf_4 _765_ (.A(net13),
    .X(tl_o[15]));
 sky130_fd_sc_hd__conb_1 _765__14 (.LO(net13));
 sky130_fd_sc_hd__buf_2 _766_ (.A(u_gpio_reg_tl_o_16_),
    .X(tl_o[16]));
 sky130_fd_sc_hd__buf_2 _767_ (.A(u_gpio_reg_tl_o_17_),
    .X(tl_o[17]));
 sky130_fd_sc_hd__buf_2 _768_ (.A(u_gpio_reg_tl_o_18_),
    .X(tl_o[18]));
 sky130_fd_sc_hd__buf_2 _769_ (.A(u_gpio_reg_tl_o_19_),
    .X(tl_o[19]));
 sky130_fd_sc_hd__buf_2 _770_ (.A(u_gpio_reg_tl_o_20_),
    .X(tl_o[20]));
 sky130_fd_sc_hd__buf_2 _771_ (.A(u_gpio_reg_tl_o_21_),
    .X(tl_o[21]));
 sky130_fd_sc_hd__buf_2 _772_ (.A(u_gpio_reg_tl_o_22_),
    .X(tl_o[22]));
 sky130_fd_sc_hd__buf_2 _773_ (.A(u_gpio_reg_tl_o_23_),
    .X(tl_o[23]));
 sky130_fd_sc_hd__buf_2 _774_ (.A(u_gpio_reg_tl_o_24_),
    .X(tl_o[24]));
 sky130_fd_sc_hd__buf_2 _775_ (.A(u_gpio_reg_tl_o_25_),
    .X(tl_o[25]));
 sky130_fd_sc_hd__buf_2 _776_ (.A(u_gpio_reg_tl_o_26_),
    .X(tl_o[26]));
 sky130_fd_sc_hd__buf_2 _777_ (.A(u_gpio_reg_tl_o_27_),
    .X(tl_o[27]));
 sky130_fd_sc_hd__buf_2 _778_ (.A(u_gpio_reg_tl_o_28_),
    .X(tl_o[28]));
 sky130_fd_sc_hd__buf_2 _779_ (.A(u_gpio_reg_tl_o_29_),
    .X(tl_o[29]));
 sky130_fd_sc_hd__buf_2 _780_ (.A(u_gpio_reg_tl_o_30_),
    .X(tl_o[30]));
 sky130_fd_sc_hd__buf_2 _781_ (.A(u_gpio_reg_tl_o_31_),
    .X(tl_o[31]));
 sky130_fd_sc_hd__buf_2 _782_ (.A(u_gpio_reg_tl_o_32_),
    .X(tl_o[32]));
 sky130_fd_sc_hd__buf_2 _783_ (.A(u_gpio_reg_tl_o_33_),
    .X(tl_o[33]));
 sky130_fd_sc_hd__buf_2 _784_ (.A(u_gpio_reg_tl_o_34_),
    .X(tl_o[34]));
 sky130_fd_sc_hd__buf_2 _785_ (.A(u_gpio_reg_tl_o_35_),
    .X(tl_o[35]));
 sky130_fd_sc_hd__buf_2 _786_ (.A(u_gpio_reg_tl_o_36_),
    .X(tl_o[36]));
 sky130_fd_sc_hd__buf_2 _787_ (.A(u_gpio_reg_tl_o_37_),
    .X(tl_o[37]));
 sky130_fd_sc_hd__buf_2 _788_ (.A(u_gpio_reg_tl_o_38_),
    .X(tl_o[38]));
 sky130_fd_sc_hd__buf_2 _789_ (.A(u_gpio_reg_tl_o_39_),
    .X(tl_o[39]));
 sky130_fd_sc_hd__buf_2 _790_ (.A(u_gpio_reg_tl_o_40_),
    .X(tl_o[40]));
 sky130_fd_sc_hd__buf_2 _791_ (.A(u_gpio_reg_tl_o_41_),
    .X(tl_o[41]));
 sky130_fd_sc_hd__buf_2 _792_ (.A(u_gpio_reg_tl_o_42_),
    .X(tl_o[42]));
 sky130_fd_sc_hd__buf_2 _793_ (.A(u_gpio_reg_tl_o_43_),
    .X(tl_o[43]));
 sky130_fd_sc_hd__buf_2 _794_ (.A(u_gpio_reg_tl_o_44_),
    .X(tl_o[44]));
 sky130_fd_sc_hd__buf_2 _795_ (.A(u_gpio_reg_tl_o_45_),
    .X(tl_o[45]));
 sky130_fd_sc_hd__buf_2 _796_ (.A(u_gpio_reg_tl_o_46_),
    .X(tl_o[46]));
 sky130_fd_sc_hd__buf_2 _797_ (.A(u_gpio_reg_tl_o_47_),
    .X(tl_o[47]));
 sky130_fd_sc_hd__buf_4 _798_ (.A(net14),
    .X(tl_o[48]));
 sky130_fd_sc_hd__conb_1 _798__15 (.LO(net14));
 sky130_fd_sc_hd__buf_2 _799_ (.A(u_gpio_reg_tl_o_49_),
    .X(tl_o[49]));
 sky130_fd_sc_hd__buf_2 _800_ (.A(u_gpio_reg_tl_o_50_),
    .X(tl_o[50]));
 sky130_fd_sc_hd__buf_2 _801_ (.A(u_gpio_reg_tl_o_51_),
    .X(tl_o[51]));
 sky130_fd_sc_hd__buf_2 _802_ (.A(u_gpio_reg_tl_o_52_),
    .X(tl_o[52]));
 sky130_fd_sc_hd__buf_2 _803_ (.A(u_gpio_reg_tl_o_53_),
    .X(tl_o[53]));
 sky130_fd_sc_hd__buf_2 _804_ (.A(u_gpio_reg_tl_o_54_),
    .X(tl_o[54]));
 sky130_fd_sc_hd__buf_2 _805_ (.A(u_gpio_reg_tl_o_55_),
    .X(tl_o[55]));
 sky130_fd_sc_hd__buf_2 _806_ (.A(u_gpio_reg_tl_o_56_),
    .X(tl_o[56]));
 sky130_fd_sc_hd__buf_2 _807_ (.A(u_gpio_reg_tl_o_57_),
    .X(tl_o[57]));
 sky130_fd_sc_hd__buf_2 _808_ (.A(u_gpio_reg_tl_o_58_),
    .X(tl_o[58]));
 sky130_fd_sc_hd__buf_4 _809_ (.A(net15),
    .X(tl_o[59]));
 sky130_fd_sc_hd__conb_1 _809__16 (.LO(net15));
 sky130_fd_sc_hd__buf_4 _810_ (.A(net16),
    .X(tl_o[60]));
 sky130_fd_sc_hd__conb_1 _810__17 (.LO(net16));
 sky130_fd_sc_hd__buf_4 _811_ (.A(net17),
    .X(tl_o[61]));
 sky130_fd_sc_hd__conb_1 _811__18 (.LO(net17));
 sky130_fd_sc_hd__buf_2 _812_ (.A(u_gpio_reg_tl_o_62_),
    .X(tl_o[62]));
 sky130_fd_sc_hd__buf_4 _813_ (.A(net18),
    .X(tl_o[63]));
 sky130_fd_sc_hd__conb_1 _813__19 (.LO(net18));
 sky130_fd_sc_hd__buf_4 _814_ (.A(net19),
    .X(tl_o[64]));
 sky130_fd_sc_hd__conb_1 _814__20 (.LO(net19));
 sky130_fd_sc_hd__buf_2 _815_ (.A(u_gpio_reg_tl_o_65_),
    .X(tl_o[65]));
 sky130_fd_sc_hd__buf_2 _816_ (.A(u_gpio_core_intr_gpio_o_0_),
    .X(intr_gpio_o[0]));
 sky130_fd_sc_hd__buf_2 _817_ (.A(u_gpio_core_intr_gpio_o_1_),
    .X(intr_gpio_o[1]));
 sky130_fd_sc_hd__buf_2 _818_ (.A(u_gpio_core_intr_gpio_o_2_),
    .X(intr_gpio_o[2]));
 sky130_fd_sc_hd__buf_2 _819_ (.A(u_gpio_core_intr_gpio_o_3_),
    .X(intr_gpio_o[3]));
 sky130_fd_sc_hd__buf_2 _820_ (.A(hw2reg_0_),
    .X(cio_gpio_o[0]));
 sky130_fd_sc_hd__buf_2 _821_ (.A(hw2reg_1_),
    .X(cio_gpio_o[1]));
 sky130_fd_sc_hd__buf_2 _822_ (.A(hw2reg_2_),
    .X(cio_gpio_o[2]));
 sky130_fd_sc_hd__buf_2 _823_ (.A(hw2reg_3_),
    .X(cio_gpio_o[3]));
 sky130_fd_sc_hd__buf_2 _824_ (.A(hw2reg_4_),
    .X(cio_gpio_en_o[0]));
 sky130_fd_sc_hd__buf_2 _825_ (.A(hw2reg_5_),
    .X(cio_gpio_en_o[1]));
 sky130_fd_sc_hd__buf_2 _826_ (.A(hw2reg_6_),
    .X(cio_gpio_en_o[2]));
 sky130_fd_sc_hd__buf_2 _827_ (.A(hw2reg_7_),
    .X(cio_gpio_en_o[3]));
 sky130_fd_sc_hd__buf_4 gain25 (.A(_159_),
    .X(net24));
 sky130_fd_sc_hd__buf_12 gain26 (.A(_118_),
    .X(net25));
 sky130_fd_sc_hd__buf_12 gain27 (.A(_137_),
    .X(net26));
 sky130_fd_sc_hd__buf_2 gain28 (.A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
    .X(net27));
 sky130_fd_sc_hd__buf_2 gain29 (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .X(net28));
 sky130_fd_sc_hd__buf_2 gain30 (.A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
    .X(net29));
 sky130_fd_sc_hd__buf_12 gain31 (.A(net31),
    .X(net30));
 sky130_fd_sc_hd__buf_12 gain32 (.A(u_gpio_core_filter_rst_ni),
    .X(net31));
 sky130_fd_sc_hd__buf_12 gain33 (.A(u_gpio_core_state_rst_ni),
    .X(net32));
 sky130_fd_sc_hd__buf_12 gain34 (.A(net35),
    .X(net33));
 sky130_fd_sc_hd__buf_12 gain35 (.A(net36),
    .X(net34));
 sky130_fd_sc_hd__buf_12 gain36 (.A(net36),
    .X(net35));
 sky130_fd_sc_hd__buf_4 gain37 (.A(reg_rst_ni),
    .X(net36));
 sky130_fd_sc_hd__buf_12 gain38 (.A(_191_),
    .X(net37));
endmodule
