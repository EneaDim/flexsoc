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
 wire net108;
 wire net109;
 wire net110;
 wire net111;
 wire net61;
 wire net62;
 wire net63;
 wire net64;
 wire net112;
 wire net113;
 wire net114;
 wire net115;
 wire core_rst_ni;
 wire hw2reg_10_;
 wire hw2reg_11_;
 wire hw2reg_12_;
 wire hw2reg_9_;
 wire net116;
 wire net117;
 wire net118;
 wire net119;
 wire net57;
 wire net58;
 wire net59;
 wire net60;
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
 wire net65;
 wire net66;
 wire net67;
 wire net68;
 wire net69;
 wire net70;
 wire net71;
 wire net72;
 wire net73;
 wire net74;
 wire net75;
 wire net76;
 wire net77;
 wire net78;
 wire net79;
 wire net80;
 wire net81;
 wire net82;
 wire net83;
 wire net84;
 wire net85;
 wire net86;
 wire net87;
 wire net88;
 wire net89;
 wire net90;
 wire net91;
 wire net92;
 wire net93;
 wire net94;
 wire net95;
 wire net96;
 wire net97;
 wire net98;
 wire net99;
 wire net100;
 wire net101;
 wire net102;
 wire net103;
 wire net104;
 wire net105;
 wire net106;
 wire net107;
 wire net120;
 wire net121;
 wire net122;
 wire net123;
 wire net124;
 wire net125;
 wire net126;
 wire net127;
 wire net128;
 wire net129;
 wire net130;
 wire net131;
 wire net132;
 wire net133;
 wire net134;
 wire net135;
 wire net136;
 wire net137;
 wire net138;
 wire net139;
 wire net140;
 wire net141;
 wire net142;
 wire net143;
 wire net144;
 wire net145;
 wire net146;
 wire net147;
 wire net148;
 wire net149;
 wire net150;
 wire net151;
 wire net152;
 wire net153;
 wire net154;
 wire net155;
 wire net156;
 wire net157;
 wire net158;
 wire net159;
 wire net160;
 wire net161;
 wire net162;
 wire net163;
 wire net164;
 wire net165;
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
 wire u_gpio_core_state_rst_ni;
 wire u_gpio_reg_u_reg_core_data_in_qs_0_;
 wire u_gpio_reg_u_reg_core_data_in_qs_1_;
 wire u_gpio_reg_u_reg_core_data_in_qs_2_;
 wire u_gpio_reg_u_reg_core_data_in_qs_3_;
 wire u_reg_reset_sync_intq;
 wire net168;
 wire clknet_0_clk_i;
 wire net169;
 wire net170;
 wire clknet_4_0_0_clk_i;
 wire clknet_4_1_0_clk_i;
 wire clknet_4_2_0_clk_i;
 wire clknet_4_3_0_clk_i;
 wire clknet_4_4_0_clk_i;
 wire clknet_4_5_0_clk_i;
 wire clknet_4_6_0_clk_i;
 wire clknet_4_7_0_clk_i;
 wire clknet_4_8_0_clk_i;
 wire clknet_4_9_0_clk_i;
 wire clknet_4_10_0_clk_i;
 wire clknet_4_11_0_clk_i;
 wire clknet_4_12_0_clk_i;
 wire clknet_4_13_0_clk_i;
 wire clknet_4_14_0_clk_i;
 wire clknet_4_15_0_clk_i;
 wire net171;
 wire net172;
 wire net173;
 wire net174;
 wire net175;
 wire net176;
 wire net177;
 wire net178;
 wire net179;
 wire net180;
 wire net181;
 wire net182;
 wire net183;
 wire net184;
 wire net185;
 wire net186;
 wire net187;
 wire net188;
 wire net189;
 wire net190;
 wire net191;
 wire net192;
 wire net193;
 wire net194;
 wire net195;
 wire net196;
 wire net197;
 wire net198;
 wire net199;
 wire net200;
 wire net201;
 wire net202;
 wire net203;
 wire net204;
 wire net205;
 wire net206;

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
    .Y(net118));
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
    .Y(net117));
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
    .Y(net116));
 sky130_fd_sc_hd__xor2_1 _328_ (.A(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_1__u_filter_filter_q),
    .X(_096_));
 sky130_fd_sc_hd__or2_0 _329_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .X(_097_));
 sky130_fd_sc_hd__nand2_1 _330_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .Y(_098_));
 sky130_fd_sc_hd__inv_1 _331_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_),
    .Y(_099_));
 sky130_fd_sc_hd__nand3_1 _332_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_2_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .C(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
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
 sky130_fd_sc_hd__inv_1 _336_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .Y(_103_));
 sky130_fd_sc_hd__nor2_1 _337_ (.A(_103_),
    .B(_101_),
    .Y(_104_));
 sky130_fd_sc_hd__nor2_1 _338_ (.A(_096_),
    .B(_104_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_0_));
 sky130_fd_sc_hd__clkinv_2 _339_ (.A(net165),
    .Y(net120));
 sky130_fd_sc_hd__nand2_8 _340_ (.A(net120),
    .B(net72),
    .Y(_105_));
 sky130_fd_sc_hd__nor3_1 _341_ (.A(net70),
    .B(net71),
    .C(_105_),
    .Y(_106_));
 sky130_fd_sc_hd__inv_1 _342_ (.A(net96),
    .Y(_107_));
 sky130_fd_sc_hd__inv_1 _343_ (.A(net97),
    .Y(_108_));
 sky130_fd_sc_hd__nand3_2 _344_ (.A(_106_),
    .B(_107_),
    .C(_108_),
    .Y(_109_));
 sky130_fd_sc_hd__inv_4 _345_ (.A(net99),
    .Y(_110_));
 sky130_fd_sc_hd__nor2_4 _346_ (.A(net98),
    .B(_110_),
    .Y(_111_));
 sky130_fd_sc_hd__nand2_1 _347_ (.A(net94),
    .B(net95),
    .Y(_112_));
 sky130_fd_sc_hd__a21boi_0 _348_ (.A1(_111_),
    .A2(_112_),
    .B1_N(net93),
    .Y(_113_));
 sky130_fd_sc_hd__nand2_1 _349_ (.A(net99),
    .B(net98),
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
 sky130_fd_sc_hd__nor2_1 _354_ (.A(net75),
    .B(net168),
    .Y(_119_));
 sky130_fd_sc_hd__a21oi_1 _355_ (.A1(_083_),
    .A2(net168),
    .B1(_119_),
    .Y(_000_));
 sky130_fd_sc_hd__mux2_1 _356_ (.A0(net74),
    .A1(reg2hw_1_),
    .S(net168),
    .X(_001_));
 sky130_fd_sc_hd__mux2_1 _357_ (.A0(net73),
    .A1(reg2hw_0_),
    .S(net168),
    .X(_002_));
 sky130_fd_sc_hd__nor2_1 _358_ (.A(net87),
    .B(net168),
    .Y(_120_));
 sky130_fd_sc_hd__a21oi_1 _359_ (.A1(_087_),
    .A2(net168),
    .B1(_120_),
    .Y(_003_));
 sky130_fd_sc_hd__nor2_1 _360_ (.A(net86),
    .B(net168),
    .Y(_121_));
 sky130_fd_sc_hd__a21oi_1 _361_ (.A1(_091_),
    .A2(net168),
    .B1(_121_),
    .Y(_004_));
 sky130_fd_sc_hd__nor2_1 _362_ (.A(net85),
    .B(net168),
    .Y(_122_));
 sky130_fd_sc_hd__a21oi_1 _363_ (.A1(_095_),
    .A2(net168),
    .B1(_122_),
    .Y(_005_));
 sky130_fd_sc_hd__inv_1 _364_ (.A(reg2hw_10_),
    .Y(_123_));
 sky130_fd_sc_hd__nor2_1 _365_ (.A(net83),
    .B(net168),
    .Y(_124_));
 sky130_fd_sc_hd__a21oi_1 _366_ (.A1(_123_),
    .A2(net168),
    .B1(_124_),
    .Y(_006_));
 sky130_fd_sc_hd__inv_1 _367_ (.A(reg2hw_9_),
    .Y(_125_));
 sky130_fd_sc_hd__nor2_1 _368_ (.A(net82),
    .B(net168),
    .Y(_126_));
 sky130_fd_sc_hd__a21oi_1 _369_ (.A1(_125_),
    .A2(net168),
    .B1(_126_),
    .Y(_007_));
 sky130_fd_sc_hd__inv_1 _370_ (.A(reg2hw_8_),
    .Y(_127_));
 sky130_fd_sc_hd__nor2_1 _371_ (.A(net81),
    .B(net168),
    .Y(_128_));
 sky130_fd_sc_hd__a21oi_1 _372_ (.A1(_127_),
    .A2(net168),
    .B1(_128_),
    .Y(_008_));
 sky130_fd_sc_hd__inv_1 _373_ (.A(reg2hw_18_),
    .Y(_129_));
 sky130_fd_sc_hd__nor2_1 _374_ (.A(net91),
    .B(net168),
    .Y(_130_));
 sky130_fd_sc_hd__a21oi_1 _375_ (.A1(_129_),
    .A2(net168),
    .B1(_130_),
    .Y(_009_));
 sky130_fd_sc_hd__inv_1 _376_ (.A(reg2hw_17_),
    .Y(_131_));
 sky130_fd_sc_hd__nor2_1 _377_ (.A(net90),
    .B(net168),
    .Y(_132_));
 sky130_fd_sc_hd__a21oi_1 _378_ (.A1(_131_),
    .A2(net168),
    .B1(_132_),
    .Y(_010_));
 sky130_fd_sc_hd__inv_1 _379_ (.A(reg2hw_16_),
    .Y(_133_));
 sky130_fd_sc_hd__nor2_1 _380_ (.A(net89),
    .B(net168),
    .Y(_134_));
 sky130_fd_sc_hd__a21oi_1 _381_ (.A1(_133_),
    .A2(net168),
    .B1(_134_),
    .Y(_011_));
 sky130_fd_sc_hd__mux2_1 _382_ (.A0(net79),
    .A1(reg2hw_6_),
    .S(net168),
    .X(_012_));
 sky130_fd_sc_hd__mux2_1 _383_ (.A0(net78),
    .A1(reg2hw_5_),
    .S(net168),
    .X(_013_));
 sky130_fd_sc_hd__mux2_1 _384_ (.A0(net77),
    .A1(reg2hw_4_),
    .S(net168),
    .X(_014_));
 sky130_fd_sc_hd__inv_12 _385_ (.A(_105_),
    .Y(_135_));
 sky130_fd_sc_hd__nand2_1 _386_ (.A(_135_),
    .B(net67),
    .Y(_136_));
 sky130_fd_sc_hd__nand2_1 _388_ (.A(_105_),
    .B(net162),
    .Y(_138_));
 sky130_fd_sc_hd__nand2_1 _389_ (.A(_136_),
    .B(_138_),
    .Y(_015_));
 sky130_fd_sc_hd__nand2_1 _390_ (.A(_135_),
    .B(net106),
    .Y(_139_));
 sky130_fd_sc_hd__nand2_1 _391_ (.A(_105_),
    .B(net160),
    .Y(_140_));
 sky130_fd_sc_hd__nand2_1 _392_ (.A(_139_),
    .B(_140_),
    .Y(_016_));
 sky130_fd_sc_hd__nand2_1 _393_ (.A(_135_),
    .B(net105),
    .Y(_141_));
 sky130_fd_sc_hd__nand2_1 _394_ (.A(_105_),
    .B(net159),
    .Y(_142_));
 sky130_fd_sc_hd__nand2_1 _395_ (.A(_141_),
    .B(_142_),
    .Y(_017_));
 sky130_fd_sc_hd__nand2_1 _396_ (.A(_135_),
    .B(net104),
    .Y(_143_));
 sky130_fd_sc_hd__nand2_1 _397_ (.A(_105_),
    .B(net158),
    .Y(_144_));
 sky130_fd_sc_hd__nand2_1 _398_ (.A(_143_),
    .B(_144_),
    .Y(_018_));
 sky130_fd_sc_hd__nand2_1 _399_ (.A(_135_),
    .B(net103),
    .Y(_145_));
 sky130_fd_sc_hd__nand2_1 _400_ (.A(_105_),
    .B(net157),
    .Y(_146_));
 sky130_fd_sc_hd__nand2_1 _401_ (.A(_145_),
    .B(_146_),
    .Y(_019_));
 sky130_fd_sc_hd__nand2_1 _402_ (.A(_135_),
    .B(net102),
    .Y(_147_));
 sky130_fd_sc_hd__nand2_1 _403_ (.A(_105_),
    .B(net156),
    .Y(_148_));
 sky130_fd_sc_hd__nand2_1 _404_ (.A(_147_),
    .B(_148_),
    .Y(_020_));
 sky130_fd_sc_hd__nand2_1 _405_ (.A(_135_),
    .B(net101),
    .Y(_149_));
 sky130_fd_sc_hd__nand2_1 _406_ (.A(_105_),
    .B(net155),
    .Y(_150_));
 sky130_fd_sc_hd__nand2_1 _407_ (.A(_149_),
    .B(_150_),
    .Y(_021_));
 sky130_fd_sc_hd__nand2_1 _408_ (.A(_135_),
    .B(net100),
    .Y(_151_));
 sky130_fd_sc_hd__nand2_1 _409_ (.A(_105_),
    .B(net154),
    .Y(_152_));
 sky130_fd_sc_hd__nand2_1 _410_ (.A(_151_),
    .B(_152_),
    .Y(_022_));
 sky130_fd_sc_hd__clkinv_1 _411_ (.A(_106_),
    .Y(_153_));
 sky130_fd_sc_hd__nor2_1 _412_ (.A(net69),
    .B(net70),
    .Y(_154_));
 sky130_fd_sc_hd__nand3_1 _413_ (.A(_135_),
    .B(net71),
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
 sky130_fd_sc_hd__nand2_8 _418_ (.A(_159_),
    .B(_135_),
    .Y(_160_));
 sky130_fd_sc_hd__nand2_1 _419_ (.A(_105_),
    .B(net152),
    .Y(_161_));
 sky130_fd_sc_hd__nand2_1 _420_ (.A(_160_),
    .B(_161_),
    .Y(_023_));
 sky130_fd_sc_hd__nand2_1 _421_ (.A(_105_),
    .B(net151),
    .Y(_162_));
 sky130_fd_sc_hd__nand2_1 _422_ (.A(_160_),
    .B(_162_),
    .Y(_024_));
 sky130_fd_sc_hd__nand2_1 _423_ (.A(_105_),
    .B(net150),
    .Y(_163_));
 sky130_fd_sc_hd__nand2_1 _424_ (.A(_160_),
    .B(_163_),
    .Y(_025_));
 sky130_fd_sc_hd__nand2_1 _425_ (.A(_105_),
    .B(net149),
    .Y(_164_));
 sky130_fd_sc_hd__nand2_1 _426_ (.A(_160_),
    .B(_164_),
    .Y(_026_));
 sky130_fd_sc_hd__nand2_1 _427_ (.A(_105_),
    .B(net148),
    .Y(_165_));
 sky130_fd_sc_hd__nand2_1 _428_ (.A(_160_),
    .B(_165_),
    .Y(_027_));
 sky130_fd_sc_hd__nand2_1 _429_ (.A(_105_),
    .B(net147),
    .Y(_166_));
 sky130_fd_sc_hd__nand2_1 _430_ (.A(_160_),
    .B(_166_),
    .Y(_028_));
 sky130_fd_sc_hd__nand2_1 _431_ (.A(_105_),
    .B(net146),
    .Y(_167_));
 sky130_fd_sc_hd__nand2_1 _432_ (.A(_160_),
    .B(_167_),
    .Y(_029_));
 sky130_fd_sc_hd__nand2_1 _433_ (.A(_105_),
    .B(net145),
    .Y(_168_));
 sky130_fd_sc_hd__nand2_1 _434_ (.A(_160_),
    .B(_168_),
    .Y(_030_));
 sky130_fd_sc_hd__nand2_1 _435_ (.A(_105_),
    .B(net144),
    .Y(_169_));
 sky130_fd_sc_hd__nand2_1 _436_ (.A(_160_),
    .B(_169_),
    .Y(_031_));
 sky130_fd_sc_hd__nand2_1 _437_ (.A(_105_),
    .B(net143),
    .Y(_170_));
 sky130_fd_sc_hd__nand2_1 _438_ (.A(_160_),
    .B(_170_),
    .Y(_032_));
 sky130_fd_sc_hd__nand2_1 _439_ (.A(_105_),
    .B(net142),
    .Y(_171_));
 sky130_fd_sc_hd__nand2_1 _440_ (.A(_160_),
    .B(_171_),
    .Y(_033_));
 sky130_fd_sc_hd__nand2_1 _441_ (.A(_105_),
    .B(net141),
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
 sky130_fd_sc_hd__nand2_1 _445_ (.A(_105_),
    .B(net140),
    .Y(_175_));
 sky130_fd_sc_hd__o211ai_1 _446_ (.A1(_129_),
    .A2(_174_),
    .B1(_175_),
    .C1(_160_),
    .Y(_035_));
 sky130_fd_sc_hd__nand2_1 _447_ (.A(_105_),
    .B(net139),
    .Y(_176_));
 sky130_fd_sc_hd__o211ai_1 _448_ (.A1(_131_),
    .A2(_174_),
    .B1(_176_),
    .C1(_160_),
    .Y(_036_));
 sky130_fd_sc_hd__nand2_1 _449_ (.A(_105_),
    .B(net138),
    .Y(_177_));
 sky130_fd_sc_hd__o211ai_1 _450_ (.A1(_133_),
    .A2(_174_),
    .B1(_177_),
    .C1(_160_),
    .Y(_037_));
 sky130_fd_sc_hd__nand2_1 _451_ (.A(_105_),
    .B(net137),
    .Y(_178_));
 sky130_fd_sc_hd__nand3_1 _452_ (.A(_135_),
    .B(reg2hw_15_),
    .C(_111_),
    .Y(_179_));
 sky130_fd_sc_hd__nand3_1 _453_ (.A(_160_),
    .B(_178_),
    .C(_179_),
    .Y(_038_));
 sky130_fd_sc_hd__nand2_1 _454_ (.A(_105_),
    .B(net136),
    .Y(_180_));
 sky130_fd_sc_hd__o211ai_1 _455_ (.A1(_087_),
    .A2(_174_),
    .B1(_180_),
    .C1(_160_),
    .Y(_039_));
 sky130_fd_sc_hd__nand2_1 _456_ (.A(_105_),
    .B(net135),
    .Y(_181_));
 sky130_fd_sc_hd__o211ai_1 _457_ (.A1(_091_),
    .A2(_174_),
    .B1(_181_),
    .C1(_160_),
    .Y(_040_));
 sky130_fd_sc_hd__nand2_1 _458_ (.A(_105_),
    .B(net134),
    .Y(_182_));
 sky130_fd_sc_hd__o211ai_1 _459_ (.A1(_095_),
    .A2(_174_),
    .B1(_182_),
    .C1(_160_),
    .Y(_041_));
 sky130_fd_sc_hd__inv_1 _460_ (.A(reg2hw_11_),
    .Y(_183_));
 sky130_fd_sc_hd__nand2_1 _461_ (.A(_105_),
    .B(net133),
    .Y(_184_));
 sky130_fd_sc_hd__o211ai_1 _462_ (.A1(_183_),
    .A2(_174_),
    .B1(_184_),
    .C1(_160_),
    .Y(_042_));
 sky130_fd_sc_hd__nand2_1 _463_ (.A(_105_),
    .B(net132),
    .Y(_185_));
 sky130_fd_sc_hd__o211ai_1 _464_ (.A1(_123_),
    .A2(_174_),
    .B1(_185_),
    .C1(_160_),
    .Y(_043_));
 sky130_fd_sc_hd__nand2_1 _465_ (.A(_105_),
    .B(net131),
    .Y(_186_));
 sky130_fd_sc_hd__o211ai_1 _466_ (.A1(_125_),
    .A2(_174_),
    .B1(_186_),
    .C1(_160_),
    .Y(_044_));
 sky130_fd_sc_hd__nand2_1 _467_ (.A(_105_),
    .B(net130),
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
 sky130_fd_sc_hd__inv_1 _471_ (.A(net111),
    .Y(_190_));
 sky130_fd_sc_hd__lpflow_clkinvkapwr_1 _472_ (.A(net98),
    .Y(_191_));
 sky130_fd_sc_hd__o21ai_0 _473_ (.A1(_190_),
    .A2(_191_),
    .B1(_110_),
    .Y(_192_));
 sky130_fd_sc_hd__o21ai_0 _474_ (.A1(reg2hw_7_),
    .A2(net98),
    .B1(_192_),
    .Y(_193_));
 sky130_fd_sc_hd__nor2_1 _475_ (.A(net129),
    .B(_135_),
    .Y(_194_));
 sky130_fd_sc_hd__a21oi_1 _476_ (.A1(_189_),
    .A2(_193_),
    .B1(_194_),
    .Y(_046_));
 sky130_fd_sc_hd__inv_1 _477_ (.A(net110),
    .Y(_195_));
 sky130_fd_sc_hd__o21ai_0 _478_ (.A1(_195_),
    .A2(_191_),
    .B1(_110_),
    .Y(_196_));
 sky130_fd_sc_hd__o21ai_0 _479_ (.A1(reg2hw_6_),
    .A2(net98),
    .B1(_196_),
    .Y(_197_));
 sky130_fd_sc_hd__nor2_1 _480_ (.A(net128),
    .B(_135_),
    .Y(_198_));
 sky130_fd_sc_hd__a21oi_1 _481_ (.A1(_189_),
    .A2(_197_),
    .B1(_198_),
    .Y(_047_));
 sky130_fd_sc_hd__inv_1 _482_ (.A(net109),
    .Y(_199_));
 sky130_fd_sc_hd__o21ai_0 _483_ (.A1(_199_),
    .A2(_191_),
    .B1(_110_),
    .Y(_200_));
 sky130_fd_sc_hd__o21ai_0 _484_ (.A1(reg2hw_5_),
    .A2(net98),
    .B1(_200_),
    .Y(_201_));
 sky130_fd_sc_hd__nor2_1 _485_ (.A(net127),
    .B(_135_),
    .Y(_202_));
 sky130_fd_sc_hd__a21oi_1 _486_ (.A1(_189_),
    .A2(_201_),
    .B1(_202_),
    .Y(_048_));
 sky130_fd_sc_hd__inv_1 _487_ (.A(net108),
    .Y(_203_));
 sky130_fd_sc_hd__o21ai_0 _488_ (.A1(_191_),
    .A2(_203_),
    .B1(_110_),
    .Y(_204_));
 sky130_fd_sc_hd__o21ai_0 _489_ (.A1(reg2hw_4_),
    .A2(net98),
    .B1(_204_),
    .Y(_205_));
 sky130_fd_sc_hd__nor2_1 _490_ (.A(net126),
    .B(_135_),
    .Y(_206_));
 sky130_fd_sc_hd__a21oi_1 _491_ (.A1(_189_),
    .A2(_205_),
    .B1(_206_),
    .Y(_049_));
 sky130_fd_sc_hd__inv_1 _492_ (.A(net115),
    .Y(_207_));
 sky130_fd_sc_hd__a21oi_1 _493_ (.A1(net99),
    .A2(reg2hw_3_),
    .B1(net98),
    .Y(_208_));
 sky130_fd_sc_hd__a21oi_1 _494_ (.A1(_110_),
    .A2(_207_),
    .B1(_208_),
    .Y(_209_));
 sky130_fd_sc_hd__a31oi_1 _495_ (.A1(_110_),
    .A2(_191_),
    .A3(u_gpio_reg_u_reg_core_data_in_qs_3_),
    .B1(_209_),
    .Y(_210_));
 sky130_fd_sc_hd__nor2_1 _496_ (.A(net124),
    .B(_135_),
    .Y(_211_));
 sky130_fd_sc_hd__a21oi_1 _497_ (.A1(_189_),
    .A2(_210_),
    .B1(_211_),
    .Y(_050_));
 sky130_fd_sc_hd__inv_1 _498_ (.A(net114),
    .Y(_212_));
 sky130_fd_sc_hd__o21ai_0 _499_ (.A1(_191_),
    .A2(_212_),
    .B1(_110_),
    .Y(_213_));
 sky130_fd_sc_hd__nand2_1 _500_ (.A(_083_),
    .B(_191_),
    .Y(_214_));
 sky130_fd_sc_hd__a32oi_1 _501_ (.A1(_110_),
    .A2(_191_),
    .A3(u_gpio_reg_u_reg_core_data_in_qs_2_),
    .B1(_213_),
    .B2(_214_),
    .Y(_215_));
 sky130_fd_sc_hd__nor2_1 _502_ (.A(net123),
    .B(_135_),
    .Y(_216_));
 sky130_fd_sc_hd__a21oi_1 _503_ (.A1(_189_),
    .A2(_215_),
    .B1(_216_),
    .Y(_051_));
 sky130_fd_sc_hd__nor3_1 _504_ (.A(net99),
    .B(net113),
    .C(_191_),
    .Y(_217_));
 sky130_fd_sc_hd__a21oi_1 _505_ (.A1(_110_),
    .A2(u_gpio_reg_u_reg_core_data_in_qs_1_),
    .B1(net98),
    .Y(_218_));
 sky130_fd_sc_hd__nor2_1 _506_ (.A(_217_),
    .B(_218_),
    .Y(_219_));
 sky130_fd_sc_hd__a21oi_1 _507_ (.A1(reg2hw_1_),
    .A2(_111_),
    .B1(_219_),
    .Y(_220_));
 sky130_fd_sc_hd__nor2_1 _508_ (.A(net122),
    .B(_135_),
    .Y(_221_));
 sky130_fd_sc_hd__a21oi_1 _509_ (.A1(_189_),
    .A2(_220_),
    .B1(_221_),
    .Y(_052_));
 sky130_fd_sc_hd__nor3_1 _510_ (.A(net99),
    .B(net112),
    .C(_191_),
    .Y(_222_));
 sky130_fd_sc_hd__a21oi_1 _511_ (.A1(_110_),
    .A2(u_gpio_reg_u_reg_core_data_in_qs_0_),
    .B1(net98),
    .Y(_223_));
 sky130_fd_sc_hd__nor2_1 _512_ (.A(_222_),
    .B(_223_),
    .Y(_224_));
 sky130_fd_sc_hd__a21oi_1 _513_ (.A1(reg2hw_0_),
    .A2(_111_),
    .B1(_224_),
    .Y(_225_));
 sky130_fd_sc_hd__nor2_1 _514_ (.A(net121),
    .B(_135_),
    .Y(_226_));
 sky130_fd_sc_hd__a21oi_1 _515_ (.A1(_189_),
    .A2(_225_),
    .B1(_226_),
    .Y(_053_));
 sky130_fd_sc_hd__nor4_4 _516_ (.A(net99),
    .B(_191_),
    .C(_109_),
    .D(_115_),
    .Y(_227_));
 sky130_fd_sc_hd__nand2_1 _517_ (.A(_227_),
    .B(net79),
    .Y(_228_));
 sky130_fd_sc_hd__o21ai_0 _518_ (.A1(_195_),
    .A2(_227_),
    .B1(_228_),
    .Y(_054_));
 sky130_fd_sc_hd__nand2_1 _519_ (.A(_227_),
    .B(net78),
    .Y(_229_));
 sky130_fd_sc_hd__o21ai_0 _520_ (.A1(_199_),
    .A2(_227_),
    .B1(_229_),
    .Y(_055_));
 sky130_fd_sc_hd__nand2_1 _521_ (.A(_227_),
    .B(net77),
    .Y(_230_));
 sky130_fd_sc_hd__o21ai_0 _522_ (.A1(_203_),
    .A2(_227_),
    .B1(_230_),
    .Y(_056_));
 sky130_fd_sc_hd__nand2_1 _523_ (.A(_227_),
    .B(net75),
    .Y(_231_));
 sky130_fd_sc_hd__o21ai_0 _524_ (.A1(_212_),
    .A2(_227_),
    .B1(_231_),
    .Y(_057_));
 sky130_fd_sc_hd__mux2_1 _525_ (.A0(net113),
    .A1(net74),
    .S(_227_),
    .X(_058_));
 sky130_fd_sc_hd__mux2_1 _526_ (.A0(net112),
    .A1(net73),
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
 sky130_fd_sc_hd__o31a_1 _550_ (.A1(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
    .A2(_245_),
    .A3(_249_),
    .B1(_252_),
    .X(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_2_));
 sky130_fd_sc_hd__nor2_1 _551_ (.A(_245_),
    .B(_249_),
    .Y(_253_));
 sky130_fd_sc_hd__nand2_1 _552_ (.A(_253_),
    .B(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
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
 sky130_fd_sc_hd__nor2_1 _557_ (.A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
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
    .A2(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
    .A3(_265_),
    .B1(_268_),
    .X(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_2_));
 sky130_fd_sc_hd__nor2_1 _572_ (.A(_261_),
    .B(_265_),
    .Y(_269_));
 sky130_fd_sc_hd__nand2_1 _573_ (.A(_269_),
    .B(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
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
 sky130_fd_sc_hd__nor2_1 _578_ (.A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
    .B(_269_),
    .Y(_273_));
 sky130_fd_sc_hd__nor2_1 _579_ (.A(_267_),
    .B(_273_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_3_));
 sky130_fd_sc_hd__nor2_1 _580_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_),
    .B(_100_),
    .Y(_274_));
 sky130_fd_sc_hd__a21oi_1 _581_ (.A1(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .A2(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
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
    .Y(net119));
 sky130_fd_sc_hd__o2111ai_1 _592_ (.A1(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_),
    .A2(_247_),
    .B1(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
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
    .B1(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
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
    .B(net76),
    .Y(_291_));
 sky130_fd_sc_hd__o21ai_0 _607_ (.A1(_207_),
    .A2(_227_),
    .B1(_291_),
    .Y(_064_));
 sky130_fd_sc_hd__nand2_1 _608_ (.A(_227_),
    .B(net80),
    .Y(_292_));
 sky130_fd_sc_hd__o21ai_0 _609_ (.A1(_190_),
    .A2(_227_),
    .B1(_292_),
    .Y(_065_));
 sky130_fd_sc_hd__a21oi_1 _610_ (.A1(net125),
    .A2(_105_),
    .B1(_156_),
    .Y(_293_));
 sky130_fd_sc_hd__nand2_1 _611_ (.A(_158_),
    .B(_293_),
    .Y(_066_));
 sky130_fd_sc_hd__o21ai_0 _612_ (.A1(net120),
    .A2(net66),
    .B1(_105_),
    .Y(_067_));
 sky130_fd_sc_hd__nand2_1 _613_ (.A(_105_),
    .B(net153),
    .Y(_294_));
 sky130_fd_sc_hd__nand2_1 _614_ (.A(_160_),
    .B(_294_),
    .Y(_068_));
 sky130_fd_sc_hd__nand2_1 _615_ (.A(_135_),
    .B(net107),
    .Y(_295_));
 sky130_fd_sc_hd__nand2_1 _616_ (.A(_105_),
    .B(net161),
    .Y(_296_));
 sky130_fd_sc_hd__nand2_1 _617_ (.A(_295_),
    .B(_296_),
    .Y(_069_));
 sky130_fd_sc_hd__nand2_1 _618_ (.A(_135_),
    .B(net68),
    .Y(_297_));
 sky130_fd_sc_hd__nand2_1 _619_ (.A(_105_),
    .B(net163),
    .Y(_298_));
 sky130_fd_sc_hd__nand2_1 _620_ (.A(_297_),
    .B(_298_),
    .Y(_070_));
 sky130_fd_sc_hd__mux2_1 _621_ (.A0(net80),
    .A1(reg2hw_7_),
    .S(net168),
    .X(_071_));
 sky130_fd_sc_hd__mux2_1 _622_ (.A0(net92),
    .A1(reg2hw_19_),
    .S(net168),
    .X(_072_));
 sky130_fd_sc_hd__nor2_1 _623_ (.A(net84),
    .B(net168),
    .Y(_299_));
 sky130_fd_sc_hd__a21oi_1 _624_ (.A1(_183_),
    .A2(net168),
    .B1(_299_),
    .Y(_073_));
 sky130_fd_sc_hd__mux2_1 _625_ (.A0(net88),
    .A1(reg2hw_15_),
    .S(net168),
    .X(_074_));
 sky130_fd_sc_hd__mux2_1 _626_ (.A0(net76),
    .A1(reg2hw_3_),
    .S(net168),
    .X(_075_));
 sky130_fd_sc_hd__nand2_1 _627_ (.A(_105_),
    .B(net164),
    .Y(_300_));
 sky130_fd_sc_hd__nand2_1 _628_ (.A(_155_),
    .B(_300_),
    .Y(_076_));
 sky130_fd_sc_hd__dfrtp_1 _629_ (.D(_076_),
    .Q(net164),
    .RESET_B(net170),
    .CLK(clknet_4_7_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _630_ (.D(_060_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .RESET_B(net169),
    .CLK(clknet_4_3_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _631_ (.D(_061_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .RESET_B(net169),
    .CLK(clknet_4_3_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _632_ (.D(_062_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .RESET_B(net169),
    .CLK(clknet_4_10_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _633_ (.D(_063_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .RESET_B(net169),
    .CLK(clknet_4_9_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _634_ (.D(_059_),
    .Q(net112),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_4_4_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _635_ (.D(_058_),
    .Q(net113),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_4_6_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _636_ (.D(_057_),
    .Q(net114),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_4_7_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _637_ (.D(_064_),
    .Q(net115),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_4_12_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _638_ (.D(_056_),
    .Q(net108),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_4_4_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _639_ (.D(_055_),
    .Q(net109),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_4_4_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _640_ (.D(_054_),
    .Q(net110),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_4_5_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _641_ (.D(_065_),
    .Q(net111),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_4_5_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _642_ (.D(_066_),
    .Q(net125),
    .RESET_B(net170),
    .CLK(clknet_4_13_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _643_ (.D(_067_),
    .Q(net165),
    .RESET_B(net170),
    .CLK(clknet_4_13_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _644_ (.D(_053_),
    .Q(net121),
    .RESET_B(net170),
    .CLK(clknet_4_7_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _645_ (.D(_052_),
    .Q(net122),
    .RESET_B(net170),
    .CLK(clknet_4_7_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _646_ (.D(_051_),
    .Q(net123),
    .RESET_B(net170),
    .CLK(clknet_4_7_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _647_ (.D(_050_),
    .Q(net124),
    .RESET_B(net170),
    .CLK(clknet_4_7_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _648_ (.D(_049_),
    .Q(net126),
    .RESET_B(net170),
    .CLK(clknet_4_5_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _649_ (.D(_048_),
    .Q(net127),
    .RESET_B(net170),
    .CLK(clknet_4_7_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _650_ (.D(_047_),
    .Q(net128),
    .RESET_B(net170),
    .CLK(clknet_4_5_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _651_ (.D(_046_),
    .Q(net129),
    .RESET_B(net170),
    .CLK(clknet_4_5_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _652_ (.D(_045_),
    .Q(net130),
    .RESET_B(net170),
    .CLK(clknet_4_3_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _653_ (.D(_044_),
    .Q(net131),
    .RESET_B(net170),
    .CLK(clknet_4_11_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _654_ (.D(_043_),
    .Q(net132),
    .RESET_B(net170),
    .CLK(clknet_4_15_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _655_ (.D(_042_),
    .Q(net133),
    .RESET_B(net170),
    .CLK(clknet_4_11_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _656_ (.D(_041_),
    .Q(net134),
    .RESET_B(net170),
    .CLK(clknet_4_1_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _657_ (.D(_040_),
    .Q(net135),
    .RESET_B(net170),
    .CLK(clknet_4_8_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _658_ (.D(_039_),
    .Q(net136),
    .RESET_B(net170),
    .CLK(clknet_4_14_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _659_ (.D(_038_),
    .Q(net137),
    .RESET_B(net170),
    .CLK(clknet_4_13_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _660_ (.D(_037_),
    .Q(net138),
    .RESET_B(net170),
    .CLK(clknet_4_2_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _661_ (.D(_036_),
    .Q(net139),
    .RESET_B(net170),
    .CLK(clknet_4_3_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _662_ (.D(_035_),
    .Q(net140),
    .RESET_B(net170),
    .CLK(clknet_4_10_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _663_ (.D(_034_),
    .Q(net141),
    .RESET_B(net170),
    .CLK(clknet_4_13_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _664_ (.D(_033_),
    .Q(net142),
    .RESET_B(net170),
    .CLK(clknet_4_13_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _665_ (.D(_032_),
    .Q(net143),
    .RESET_B(net170),
    .CLK(clknet_4_11_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _666_ (.D(_031_),
    .Q(net144),
    .RESET_B(net170),
    .CLK(clknet_4_10_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _667_ (.D(_030_),
    .Q(net145),
    .RESET_B(net170),
    .CLK(clknet_4_14_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _668_ (.D(_029_),
    .Q(net146),
    .RESET_B(net170),
    .CLK(clknet_4_15_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _669_ (.D(_028_),
    .Q(net147),
    .RESET_B(net170),
    .CLK(clknet_4_10_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _670_ (.D(_027_),
    .Q(net148),
    .RESET_B(net170),
    .CLK(clknet_4_14_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _671_ (.D(_026_),
    .Q(net149),
    .RESET_B(net170),
    .CLK(clknet_4_11_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _672_ (.D(_025_),
    .Q(net150),
    .RESET_B(net170),
    .CLK(clknet_4_10_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _673_ (.D(_024_),
    .Q(net151),
    .RESET_B(net170),
    .CLK(clknet_4_14_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _674_ (.D(_023_),
    .Q(net152),
    .RESET_B(net170),
    .CLK(clknet_4_10_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _675_ (.D(_068_),
    .Q(net153),
    .RESET_B(net170),
    .CLK(clknet_4_11_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _676_ (.D(_022_),
    .Q(net154),
    .RESET_B(net170),
    .CLK(clknet_4_15_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _677_ (.D(_021_),
    .Q(net155),
    .RESET_B(net170),
    .CLK(clknet_4_15_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _678_ (.D(_020_),
    .Q(net156),
    .RESET_B(net170),
    .CLK(clknet_4_13_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _679_ (.D(_019_),
    .Q(net157),
    .RESET_B(net170),
    .CLK(clknet_4_14_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _680_ (.D(_018_),
    .Q(net158),
    .RESET_B(net170),
    .CLK(clknet_4_15_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _681_ (.D(_017_),
    .Q(net159),
    .RESET_B(net170),
    .CLK(clknet_4_15_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _682_ (.D(_016_),
    .Q(net160),
    .RESET_B(net170),
    .CLK(clknet_4_15_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _683_ (.D(_069_),
    .Q(net161),
    .RESET_B(net170),
    .CLK(clknet_4_15_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _684_ (.D(_015_),
    .Q(net162),
    .RESET_B(net170),
    .CLK(clknet_4_15_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _685_ (.D(_070_),
    .Q(net163),
    .RESET_B(net170),
    .CLK(clknet_4_15_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _686_ (.D(_014_),
    .Q(reg2hw_4_),
    .RESET_B(net170),
    .CLK(clknet_4_4_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _687_ (.D(_013_),
    .Q(reg2hw_5_),
    .RESET_B(net170),
    .CLK(clknet_4_6_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _688_ (.D(_012_),
    .Q(reg2hw_6_),
    .RESET_B(net170),
    .CLK(clknet_4_5_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _689_ (.D(_071_),
    .Q(reg2hw_7_),
    .RESET_B(net170),
    .CLK(clknet_4_5_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _690_ (.D(_011_),
    .Q(reg2hw_16_),
    .RESET_B(net170),
    .CLK(clknet_4_2_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _691_ (.D(_010_),
    .Q(reg2hw_17_),
    .RESET_B(net170),
    .CLK(clknet_4_2_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _692_ (.D(_009_),
    .Q(reg2hw_18_),
    .RESET_B(net170),
    .CLK(clknet_4_10_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _693_ (.D(_072_),
    .Q(reg2hw_19_),
    .RESET_B(net170),
    .CLK(clknet_4_8_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _694_ (.D(_008_),
    .Q(reg2hw_8_),
    .RESET_B(net170),
    .CLK(clknet_4_1_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _695_ (.D(_007_),
    .Q(reg2hw_9_),
    .RESET_B(net170),
    .CLK(clknet_4_9_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _696_ (.D(_006_),
    .Q(reg2hw_10_),
    .RESET_B(net170),
    .CLK(clknet_4_14_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _697_ (.D(_073_),
    .Q(reg2hw_11_),
    .RESET_B(net170),
    .CLK(clknet_4_11_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _698_ (.D(_005_),
    .Q(reg2hw_12_),
    .RESET_B(net170),
    .CLK(clknet_4_1_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _699_ (.D(_004_),
    .Q(reg2hw_13_),
    .RESET_B(net170),
    .CLK(clknet_4_2_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _700_ (.D(_003_),
    .Q(reg2hw_14_),
    .RESET_B(net170),
    .CLK(clknet_4_14_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _701_ (.D(_074_),
    .Q(reg2hw_15_),
    .RESET_B(net170),
    .CLK(clknet_4_12_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _702_ (.D(_002_),
    .Q(reg2hw_0_),
    .RESET_B(net170),
    .CLK(clknet_4_6_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _703_ (.D(_001_),
    .Q(reg2hw_1_),
    .RESET_B(net170),
    .CLK(clknet_4_6_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _704_ (.D(_000_),
    .Q(reg2hw_2_),
    .RESET_B(net170),
    .CLK(clknet_4_12_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _705_ (.D(_075_),
    .Q(reg2hw_3_),
    .RESET_B(net170),
    .CLK(clknet_4_12_0_clk_i));
 sky130_fd_sc_hd__dfrtp_2 _706_ (.D(u_reg_reset_sync_intq),
    .Q(reg_rst_ni),
    .RESET_B(net65),
    .CLK(clknet_4_1_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _707_ (.D(net57),
    .Q(u_reg_reset_sync_intq),
    .RESET_B(net65),
    .CLK(clknet_4_0_0_clk_i));
 sky130_fd_sc_hd__conb_1 _707__22 (.HI(net57));
 sky130_fd_sc_hd__dfrtp_1 _708_ (.D(hw2reg_9_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_0_),
    .RESET_B(net170),
    .CLK(clknet_4_6_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _709_ (.D(hw2reg_10_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_1_),
    .RESET_B(net170),
    .CLK(clknet_4_6_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _710_ (.D(hw2reg_11_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_2_),
    .RESET_B(net170),
    .CLK(clknet_4_13_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _711_ (.D(hw2reg_12_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_3_),
    .RESET_B(net170),
    .CLK(clknet_4_6_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _712_ (.D(net58),
    .Q(u_gpio_core_state_rst_ni),
    .RESET_B(net186),
    .CLK(clknet_4_1_0_clk_i));
 sky130_fd_sc_hd__conb_1 _712__23 (.HI(net58));
 sky130_fd_sc_hd__dfrtp_1 _713_ (.D(net59),
    .Q(u_gpio_core_filter_rst_ni),
    .RESET_B(net186),
    .CLK(clknet_4_1_0_clk_i));
 sky130_fd_sc_hd__conb_1 _713__24 (.HI(net59));
 sky130_fd_sc_hd__dfrtp_1 _714_ (.D(u_gpio_core_gen_input_filter_3__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .RESET_B(net169),
    .CLK(clknet_4_9_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _715_ (.D(net64),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_gen_async_prim_flop_2sync_intq),
    .RESET_B(net169),
    .CLK(clknet_4_8_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _716_ (.D(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_filter_q),
    .RESET_B(net169),
    .CLK(clknet_4_9_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _717_ (.D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_),
    .RESET_B(net169),
    .CLK(clknet_4_9_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _718_ (.D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_1_),
    .RESET_B(net169),
    .CLK(clknet_4_9_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _719_ (.D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_2_),
    .RESET_B(net169),
    .CLK(clknet_4_9_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _720_ (.D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_),
    .RESET_B(net169),
    .CLK(clknet_4_9_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _721_ (.D(u_gpio_core_gen_input_filter_2__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .RESET_B(net169),
    .CLK(clknet_4_8_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _722_ (.D(net63),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_gen_async_prim_flop_2sync_intq),
    .RESET_B(net169),
    .CLK(clknet_4_10_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _723_ (.D(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_filter_q),
    .RESET_B(net169),
    .CLK(clknet_4_8_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _724_ (.D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .RESET_B(net169),
    .CLK(clknet_4_8_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _725_ (.D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_),
    .RESET_B(net169),
    .CLK(clknet_4_8_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _726_ (.D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_2_),
    .RESET_B(net169),
    .CLK(clknet_4_8_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _727_ (.D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
    .RESET_B(net169),
    .CLK(clknet_4_8_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _728_ (.D(u_gpio_core_gen_input_filter_1__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .RESET_B(net169),
    .CLK(clknet_4_2_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _729_ (.D(net62),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_gen_async_prim_flop_2sync_intq),
    .RESET_B(net169),
    .CLK(clknet_4_2_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _730_ (.D(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_filter_q),
    .RESET_B(net169),
    .CLK(clknet_4_2_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _731_ (.D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .RESET_B(net169),
    .CLK(clknet_4_3_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _732_ (.D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .RESET_B(net169),
    .CLK(clknet_4_3_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _733_ (.D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_2_),
    .RESET_B(net169),
    .CLK(clknet_4_3_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _734_ (.D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_),
    .RESET_B(net169),
    .CLK(clknet_4_3_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _735_ (.D(u_gpio_core_gen_input_filter_0__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .RESET_B(net169),
    .CLK(clknet_4_2_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _736_ (.D(net61),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_gen_async_prim_flop_2sync_intq),
    .RESET_B(net169),
    .CLK(clknet_4_2_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _737_ (.D(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_filter_q),
    .RESET_B(net169),
    .CLK(clknet_4_2_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _738_ (.D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .RESET_B(net169),
    .CLK(clknet_4_0_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _739_ (.D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .RESET_B(net169),
    .CLK(clknet_4_0_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _740_ (.D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_),
    .RESET_B(net169),
    .CLK(clknet_4_0_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _741_ (.D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
    .RESET_B(net169),
    .CLK(clknet_4_0_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _742_ (.D(hw2reg_9_),
    .Q(u_gpio_core_data_in_q_0_),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_4_4_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _743_ (.D(hw2reg_10_),
    .Q(u_gpio_core_data_in_q_1_),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_4_3_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _744_ (.D(hw2reg_11_),
    .Q(u_gpio_core_data_in_q_2_),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_4_12_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _745_ (.D(hw2reg_12_),
    .Q(u_gpio_core_data_in_q_3_),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_4_9_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _746_ (.D(u_core_reset_sync_intq),
    .Q(core_rst_ni),
    .RESET_B(net65),
    .CLK(clknet_4_0_0_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _747_ (.D(net60),
    .Q(u_core_reset_sync_intq),
    .RESET_B(net65),
    .CLK(clknet_4_0_0_clk_i));
 sky130_fd_sc_hd__conb_1 _747__25 (.HI(net60));
 sky130_fd_sc_hd__conb_1 _752__2 (.LO(tl_o[2]));
 sky130_fd_sc_hd__conb_1 _753__3 (.LO(tl_o[3]));
 sky130_fd_sc_hd__conb_1 _754__4 (.LO(tl_o[4]));
 sky130_fd_sc_hd__conb_1 _755__5 (.LO(tl_o[5]));
 sky130_fd_sc_hd__conb_1 _756__6 (.LO(tl_o[6]));
 sky130_fd_sc_hd__conb_1 _757__7 (.LO(tl_o[7]));
 sky130_fd_sc_hd__conb_1 _758__8 (.LO(tl_o[8]));
 sky130_fd_sc_hd__conb_1 _759__9 (.LO(tl_o[9]));
 sky130_fd_sc_hd__conb_1 _760__10 (.LO(tl_o[10]));
 sky130_fd_sc_hd__conb_1 _761__11 (.LO(tl_o[11]));
 sky130_fd_sc_hd__conb_1 _762__12 (.LO(tl_o[12]));
 sky130_fd_sc_hd__conb_1 _763__13 (.LO(tl_o[13]));
 sky130_fd_sc_hd__conb_1 _764__14 (.LO(tl_o[14]));
 sky130_fd_sc_hd__conb_1 _765__15 (.LO(tl_o[15]));
 sky130_fd_sc_hd__conb_1 _798__16 (.LO(tl_o[48]));
 sky130_fd_sc_hd__conb_1 _809__17 (.LO(tl_o[59]));
 sky130_fd_sc_hd__conb_1 _810__18 (.LO(tl_o[60]));
 sky130_fd_sc_hd__conb_1 _811__19 (.LO(tl_o[61]));
 sky130_fd_sc_hd__conb_1 _813__20 (.LO(tl_o[63]));
 sky130_fd_sc_hd__conb_1 _814__21 (.LO(tl_o[64]));
 sky130_fd_sc_hd__clkbuf_8 clkbuf_0_clk_i (.A(clk_i),
    .X(clknet_0_clk_i));
 sky130_fd_sc_hd__clkbuf_16 clkbuf_4_0_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_0_0_clk_i));
 sky130_fd_sc_hd__clkbuf_16 clkbuf_4_10_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_10_0_clk_i));
 sky130_fd_sc_hd__clkbuf_16 clkbuf_4_11_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_11_0_clk_i));
 sky130_fd_sc_hd__clkbuf_16 clkbuf_4_12_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_12_0_clk_i));
 sky130_fd_sc_hd__clkbuf_16 clkbuf_4_13_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_13_0_clk_i));
 sky130_fd_sc_hd__clkbuf_16 clkbuf_4_14_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_14_0_clk_i));
 sky130_fd_sc_hd__clkbuf_16 clkbuf_4_15_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_15_0_clk_i));
 sky130_fd_sc_hd__clkbuf_16 clkbuf_4_1_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_1_0_clk_i));
 sky130_fd_sc_hd__clkbuf_16 clkbuf_4_2_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_2_0_clk_i));
 sky130_fd_sc_hd__clkbuf_16 clkbuf_4_3_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_3_0_clk_i));
 sky130_fd_sc_hd__clkbuf_16 clkbuf_4_4_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_4_0_clk_i));
 sky130_fd_sc_hd__clkbuf_16 clkbuf_4_5_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_5_0_clk_i));
 sky130_fd_sc_hd__clkbuf_16 clkbuf_4_6_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_6_0_clk_i));
 sky130_fd_sc_hd__clkbuf_16 clkbuf_4_7_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_7_0_clk_i));
 sky130_fd_sc_hd__clkbuf_16 clkbuf_4_8_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_8_0_clk_i));
 sky130_fd_sc_hd__clkbuf_16 clkbuf_4_9_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_9_0_clk_i));
 sky130_fd_sc_hd__clkinv_2 clkload0 (.A(clknet_4_0_0_clk_i));
 sky130_fd_sc_hd__bufinv_16 clkload1 (.A(clknet_4_1_0_clk_i));
 sky130_fd_sc_hd__bufinv_16 clkload10 (.A(clknet_4_11_0_clk_i));
 sky130_fd_sc_hd__clkinvlp_4 clkload11 (.A(clknet_4_12_0_clk_i));
 sky130_fd_sc_hd__clkinv_2 clkload12 (.A(clknet_4_13_0_clk_i));
 sky130_fd_sc_hd__clkinv_2 clkload13 (.A(clknet_4_14_0_clk_i));
 sky130_fd_sc_hd__clkbuf_1 clkload2 (.A(clknet_4_3_0_clk_i));
 sky130_fd_sc_hd__clkinvlp_4 clkload3 (.A(clknet_4_4_0_clk_i));
 sky130_fd_sc_hd__clkinv_2 clkload4 (.A(clknet_4_5_0_clk_i));
 sky130_fd_sc_hd__clkinv_2 clkload5 (.A(clknet_4_6_0_clk_i));
 sky130_fd_sc_hd__clkinv_2 clkload6 (.A(clknet_4_7_0_clk_i));
 sky130_fd_sc_hd__clkbuf_1 clkload7 (.A(clknet_4_8_0_clk_i));
 sky130_fd_sc_hd__clkbuf_1 clkload8 (.A(clknet_4_9_0_clk_i));
 sky130_fd_sc_hd__clkbuf_8 clkload9 (.A(clknet_4_10_0_clk_i));
 sky130_fd_sc_hd__dlygate4sd3_1 hold136 (.A(rst_ni),
    .X(net171));
 sky130_fd_sc_hd__dlygate4sd3_1 hold137 (.A(cio_gpio_i[0]),
    .X(net172));
 sky130_fd_sc_hd__dlygate4sd3_1 hold138 (.A(cio_gpio_i[3]),
    .X(net173));
 sky130_fd_sc_hd__dlygate4sd3_1 hold139 (.A(cio_gpio_i[2]),
    .X(net174));
 sky130_fd_sc_hd__dlygate4sd3_1 hold140 (.A(cio_gpio_i[1]),
    .X(net175));
 sky130_fd_sc_hd__dlygate4sd3_1 hold141 (.A(tl_i[101]),
    .X(net176));
 sky130_fd_sc_hd__dlygate4sd3_1 hold142 (.A(tl_i[93]),
    .X(net177));
 sky130_fd_sc_hd__dlygate4sd3_1 hold143 (.A(tl_i[100]),
    .X(net178));
 sky130_fd_sc_hd__dlygate4sd3_1 hold144 (.A(tl_i[94]),
    .X(net179));
 sky130_fd_sc_hd__dlygate4sd3_1 hold145 (.A(tl_i[97]),
    .X(net180));
 sky130_fd_sc_hd__dlygate4sd3_1 hold146 (.A(tl_i[99]),
    .X(net181));
 sky130_fd_sc_hd__dlygate4sd3_1 hold147 (.A(tl_i[92]),
    .X(net182));
 sky130_fd_sc_hd__dlygate4sd3_1 hold148 (.A(tl_i[98]),
    .X(net183));
 sky130_fd_sc_hd__dlygate4sd3_1 hold149 (.A(tl_i[96]),
    .X(net184));
 sky130_fd_sc_hd__dlygate4sd3_1 hold150 (.A(tl_i[95]),
    .X(net185));
 sky130_fd_sc_hd__dlygate4sd3_1 hold151 (.A(core_rst_ni),
    .X(net186));
 sky130_fd_sc_hd__dlygate4sd3_1 hold152 (.A(tl_i[0]),
    .X(net187));
 sky130_fd_sc_hd__dlygate4sd3_1 hold153 (.A(tl_i[41]),
    .X(net188));
 sky130_fd_sc_hd__dlygate4sd3_1 hold154 (.A(tl_i[40]),
    .X(net189));
 sky130_fd_sc_hd__dlygate4sd3_1 hold155 (.A(tl_i[37]),
    .X(net190));
 sky130_fd_sc_hd__dlygate4sd3_1 hold156 (.A(tl_i[34]),
    .X(net191));
 sky130_fd_sc_hd__dlygate4sd3_1 hold157 (.A(tl_i[32]),
    .X(net192));
 sky130_fd_sc_hd__dlygate4sd3_1 hold158 (.A(tl_i[43]),
    .X(net193));
 sky130_fd_sc_hd__dlygate4sd3_1 hold159 (.A(tl_i[38]),
    .X(net194));
 sky130_fd_sc_hd__dlygate4sd3_1 hold160 (.A(tl_i[27]),
    .X(net195));
 sky130_fd_sc_hd__dlygate4sd3_1 hold161 (.A(tl_i[42]),
    .X(net196));
 sky130_fd_sc_hd__dlygate4sd3_1 hold162 (.A(tl_i[31]),
    .X(net197));
 sky130_fd_sc_hd__dlygate4sd3_1 hold163 (.A(tl_i[36]),
    .X(net198));
 sky130_fd_sc_hd__dlygate4sd3_1 hold164 (.A(tl_i[35]),
    .X(net199));
 sky130_fd_sc_hd__dlygate4sd3_1 hold165 (.A(tl_i[39]),
    .X(net200));
 sky130_fd_sc_hd__dlygate4sd3_1 hold166 (.A(tl_i[28]),
    .X(net201));
 sky130_fd_sc_hd__dlygate4sd3_1 hold167 (.A(tl_i[30]),
    .X(net202));
 sky130_fd_sc_hd__dlygate4sd3_1 hold168 (.A(tl_i[107]),
    .X(net203));
 sky130_fd_sc_hd__dlygate4sd3_1 hold169 (.A(tl_i[33]),
    .X(net204));
 sky130_fd_sc_hd__dlygate4sd3_1 hold170 (.A(tl_i[24]),
    .X(net205));
 sky130_fd_sc_hd__dlygate4sd3_1 hold171 (.A(tl_i[26]),
    .X(net206));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input26 (.A(net172),
    .X(net61));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input27 (.A(net175),
    .X(net62));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input28 (.A(net174),
    .X(net63));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input29 (.A(net173),
    .X(net64));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input30 (.A(net171),
    .X(net65));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input31 (.A(net187),
    .X(net66));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input32 (.A(net178),
    .X(net67));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input33 (.A(net176),
    .X(net68));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input34 (.A(tl_i[105]),
    .X(net69));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input35 (.A(tl_i[106]),
    .X(net70));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input36 (.A(net203),
    .X(net71));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input37 (.A(tl_i[108]),
    .X(net72));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input38 (.A(net205),
    .X(net73));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input39 (.A(tl_i[25]),
    .X(net74));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input40 (.A(net206),
    .X(net75));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input41 (.A(net195),
    .X(net76));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input42 (.A(net201),
    .X(net77));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input43 (.A(tl_i[29]),
    .X(net78));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input44 (.A(net202),
    .X(net79));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input45 (.A(net197),
    .X(net80));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input46 (.A(net192),
    .X(net81));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input47 (.A(net204),
    .X(net82));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input48 (.A(net191),
    .X(net83));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input49 (.A(net199),
    .X(net84));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input50 (.A(net198),
    .X(net85));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input51 (.A(net190),
    .X(net86));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input52 (.A(net194),
    .X(net87));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input53 (.A(net200),
    .X(net88));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input54 (.A(net189),
    .X(net89));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input55 (.A(net188),
    .X(net90));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input56 (.A(net196),
    .X(net91));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input57 (.A(net193),
    .X(net92));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input58 (.A(tl_i[56]),
    .X(net93));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input59 (.A(tl_i[57]),
    .X(net94));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input60 (.A(tl_i[58]),
    .X(net95));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input61 (.A(tl_i[60]),
    .X(net96));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input62 (.A(tl_i[61]),
    .X(net97));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input63 (.A(tl_i[62]),
    .X(net98));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input64 (.A(tl_i[63]),
    .X(net99));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input65 (.A(net182),
    .X(net100));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input66 (.A(net177),
    .X(net101));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input67 (.A(net179),
    .X(net102));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input68 (.A(net185),
    .X(net103));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input69 (.A(net184),
    .X(net104));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input70 (.A(net180),
    .X(net105));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input71 (.A(net183),
    .X(net106));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input72 (.A(net181),
    .X(net107));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output100 (.A(net135),
    .X(tl_o[29]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output101 (.A(net136),
    .X(tl_o[30]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output102 (.A(net137),
    .X(tl_o[31]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output103 (.A(net138),
    .X(tl_o[32]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output104 (.A(net139),
    .X(tl_o[33]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output105 (.A(net140),
    .X(tl_o[34]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output106 (.A(net141),
    .X(tl_o[35]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output107 (.A(net142),
    .X(tl_o[36]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output108 (.A(net143),
    .X(tl_o[37]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output109 (.A(net144),
    .X(tl_o[38]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output110 (.A(net145),
    .X(tl_o[39]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output111 (.A(net146),
    .X(tl_o[40]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output112 (.A(net147),
    .X(tl_o[41]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output113 (.A(net148),
    .X(tl_o[42]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output114 (.A(net149),
    .X(tl_o[43]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output115 (.A(net150),
    .X(tl_o[44]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output116 (.A(net151),
    .X(tl_o[45]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output117 (.A(net152),
    .X(tl_o[46]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output118 (.A(net153),
    .X(tl_o[47]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output119 (.A(net154),
    .X(tl_o[49]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output120 (.A(net155),
    .X(tl_o[50]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output121 (.A(net156),
    .X(tl_o[51]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output122 (.A(net157),
    .X(tl_o[52]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output123 (.A(net158),
    .X(tl_o[53]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output124 (.A(net159),
    .X(tl_o[54]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output125 (.A(net160),
    .X(tl_o[55]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output126 (.A(net161),
    .X(tl_o[56]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output127 (.A(net162),
    .X(tl_o[57]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output128 (.A(net163),
    .X(tl_o[58]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output129 (.A(net164),
    .X(tl_o[62]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output130 (.A(net165),
    .X(tl_o[65]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output73 (.A(net108),
    .X(cio_gpio_en_o[0]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output74 (.A(net109),
    .X(cio_gpio_en_o[1]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output75 (.A(net110),
    .X(cio_gpio_en_o[2]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output76 (.A(net111),
    .X(cio_gpio_en_o[3]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output77 (.A(net112),
    .X(cio_gpio_o[0]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output78 (.A(net113),
    .X(cio_gpio_o[1]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output79 (.A(net114),
    .X(cio_gpio_o[2]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output80 (.A(net115),
    .X(cio_gpio_o[3]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output81 (.A(net116),
    .X(intr_gpio_o[0]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output82 (.A(net117),
    .X(intr_gpio_o[1]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output83 (.A(net118),
    .X(intr_gpio_o[2]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output84 (.A(net119),
    .X(intr_gpio_o[3]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output85 (.A(net120),
    .X(tl_o[0]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output86 (.A(net121),
    .X(tl_o[16]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output87 (.A(net122),
    .X(tl_o[17]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output88 (.A(net123),
    .X(tl_o[18]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output89 (.A(net124),
    .X(tl_o[19]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output90 (.A(net125),
    .X(tl_o[1]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output91 (.A(net126),
    .X(tl_o[20]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output92 (.A(net127),
    .X(tl_o[21]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output93 (.A(net128),
    .X(tl_o[22]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output94 (.A(net129),
    .X(tl_o[23]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output95 (.A(net130),
    .X(tl_o[24]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output96 (.A(net131),
    .X(tl_o[25]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output97 (.A(net132),
    .X(tl_o[26]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output98 (.A(net133),
    .X(tl_o[27]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output99 (.A(net134),
    .X(tl_o[28]));
 sky130_fd_sc_hd__buf_4 place133 (.A(_117_),
    .X(net168));
 sky130_fd_sc_hd__buf_4 place134 (.A(u_gpio_core_filter_rst_ni),
    .X(net169));
 sky130_fd_sc_hd__buf_4 place135 (.A(reg_rst_ni),
    .X(net170));
endmodule
