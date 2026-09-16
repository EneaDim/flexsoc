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
 wire net290;
 wire _114_;
 wire net289;
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
 wire net292;
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
 wire net286;
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
 wire net285;
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
 wire net133;
 wire net134;
 wire net135;
 wire net136;
 wire net86;
 wire net87;
 wire net88;
 wire net89;
 wire net137;
 wire net138;
 wire net139;
 wire net140;
 wire core_rst_ni;
 wire hw2reg_10_;
 wire hw2reg_11_;
 wire hw2reg_12_;
 wire hw2reg_9_;
 wire net141;
 wire net142;
 wire net143;
 wire net144;
 wire net284;
 wire net277;
 wire net82;
 wire net293;
 wire net83;
 wire net84;
 wire net85;
 wire net278;
 wire net276;
 wire clknet_4_5_0_clk_i;
 wire net275;
 wire clknet_4_9_0_clk_i;
 wire net274;
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
 wire net108;
 wire net109;
 wire net110;
 wire net111;
 wire net112;
 wire net113;
 wire net114;
 wire net115;
 wire net116;
 wire net117;
 wire net118;
 wire net119;
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
 wire net166;
 wire net167;
 wire net168;
 wire net169;
 wire net170;
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
 wire net283;
 wire net280;
 wire u_gpio_reg_u_reg_core_data_in_qs_0_;
 wire u_gpio_reg_u_reg_core_data_in_qs_1_;
 wire u_gpio_reg_u_reg_core_data_in_qs_2_;
 wire u_gpio_reg_u_reg_core_data_in_qs_3_;
 wire u_reg_reset_sync_intq;
 wire net279;
 wire net287;
 wire net291;
 wire clknet_4_2_0_clk_i;
 wire net288;
 wire clknet_4_8_0_clk_i;
 wire clknet_4_7_0_clk_i;
 wire clknet_4_1_0_clk_i;
 wire net298;
 wire clknet_4_4_0_clk_i;
 wire clknet_4_3_0_clk_i;
 wire net295;
 wire net282;
 wire clknet_4_0_0_clk_i;
 wire net299;
 wire net294;
 wire clknet_4_13_0_clk_i;
 wire clknet_4_11_0_clk_i;
 wire net296;
 wire net297;
 wire clknet_4_10_0_clk_i;
 wire clknet_4_12_0_clk_i;
 wire net300;
 wire net271;
 wire clknet_0_clk_i;
 wire net270;
 wire net269;
 wire net281;
 wire net272;
 wire net273;
 wire clknet_4_6_0_clk_i;
 wire clknet_4_14_0_clk_i;
 wire clknet_4_15_0_clk_i;
 wire clknet_5_0__leaf_clk_i;
 wire clknet_5_1__leaf_clk_i;
 wire clknet_5_2__leaf_clk_i;
 wire clknet_5_3__leaf_clk_i;
 wire clknet_5_4__leaf_clk_i;
 wire clknet_5_5__leaf_clk_i;
 wire clknet_5_6__leaf_clk_i;
 wire clknet_5_7__leaf_clk_i;
 wire clknet_5_8__leaf_clk_i;
 wire clknet_5_9__leaf_clk_i;
 wire clknet_5_10__leaf_clk_i;
 wire clknet_5_11__leaf_clk_i;
 wire clknet_5_12__leaf_clk_i;
 wire clknet_5_13__leaf_clk_i;
 wire clknet_5_14__leaf_clk_i;
 wire clknet_5_15__leaf_clk_i;
 wire clknet_5_16__leaf_clk_i;
 wire clknet_5_17__leaf_clk_i;
 wire clknet_5_18__leaf_clk_i;
 wire clknet_5_19__leaf_clk_i;
 wire clknet_5_20__leaf_clk_i;
 wire clknet_5_21__leaf_clk_i;
 wire clknet_5_22__leaf_clk_i;
 wire clknet_5_23__leaf_clk_i;
 wire clknet_5_24__leaf_clk_i;
 wire clknet_5_25__leaf_clk_i;
 wire clknet_5_26__leaf_clk_i;
 wire clknet_5_27__leaf_clk_i;
 wire clknet_5_28__leaf_clk_i;
 wire clknet_5_29__leaf_clk_i;
 wire clknet_5_30__leaf_clk_i;
 wire clknet_5_31__leaf_clk_i;
 wire net301;
 wire net302;
 wire net303;
 wire net304;
 wire net305;
 wire net306;
 wire net307;
 wire net308;
 wire net309;
 wire net310;
 wire net311;
 wire net312;
 wire net313;
 wire net314;
 wire net315;
 wire net316;
 wire net317;
 wire net318;
 wire net319;
 wire net320;
 wire net321;
 wire net322;
 wire net323;
 wire net324;
 wire net325;
 wire net326;
 wire net327;
 wire net328;
 wire net329;
 wire net330;
 wire net331;
 wire net332;
 wire net333;
 wire net334;
 wire net335;
 wire net336;
 wire net337;
 wire net338;
 wire net339;
 wire net340;
 wire net341;
 wire net342;
 wire net343;
 wire net344;
 wire net345;
 wire net346;
 wire net347;
 wire net348;
 wire net349;
 wire net350;
 wire net351;
 wire net352;
 wire net353;
 wire net354;
 wire net355;
 wire net356;
 wire net357;
 wire net358;
 wire net359;
 wire net360;
 wire net361;
 wire net362;
 wire net363;
 wire net364;
 wire net365;
 wire net366;
 wire net367;

 sg13g2_mux2_1 _256_ (.A0(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .A1(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .S(reg2hw_18_),
    .X(hw2reg_11_));
 sg13g2_mux2_1 _257_ (.A0(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .A1(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .S(reg2hw_17_),
    .X(hw2reg_10_));
 sg13g2_mux2_1 _258_ (.A0(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .A1(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .S(reg2hw_16_),
    .X(hw2reg_9_));
 sg13g2_inv_1 _259_ (.Y(_077_),
    .A(u_gpio_core_data_in_q_2_));
 sg13g2_a21oi_1 _260_ (.A1(_077_),
    .A2(reg2hw_2_),
    .Y(_078_),
    .B1(reg2hw_10_));
 sg13g2_nor2b_1 _261_ (.A(_077_),
    .B_N(reg2hw_6_),
    .Y(_079_));
 sg13g2_nor3_1 _262_ (.A(reg2hw_14_),
    .B(_079_),
    .C(hw2reg_11_),
    .Y(_080_));
 sg13g2_a21oi_1 _263_ (.A1(hw2reg_11_),
    .A2(_078_),
    .Y(net143),
    .B1(_080_));
 sg13g2_inv_1 _264_ (.Y(_081_),
    .A(u_gpio_core_data_in_q_1_));
 sg13g2_a21oi_1 _265_ (.A1(_081_),
    .A2(reg2hw_1_),
    .Y(_082_),
    .B1(reg2hw_9_));
 sg13g2_nor2b_1 _266_ (.A(_081_),
    .B_N(reg2hw_5_),
    .Y(_083_));
 sg13g2_nor3_1 _267_ (.A(reg2hw_13_),
    .B(_083_),
    .C(hw2reg_10_),
    .Y(_084_));
 sg13g2_a21oi_1 _268_ (.A1(hw2reg_10_),
    .A2(_082_),
    .Y(net142),
    .B1(_084_));
 sg13g2_inv_1 _269_ (.Y(_085_),
    .A(u_gpio_core_data_in_q_0_));
 sg13g2_a21oi_1 _270_ (.A1(_085_),
    .A2(reg2hw_0_),
    .Y(_086_),
    .B1(reg2hw_8_));
 sg13g2_nor2b_1 _271_ (.A(_085_),
    .B_N(reg2hw_4_),
    .Y(_087_));
 sg13g2_nor3_1 _272_ (.A(reg2hw_12_),
    .B(_087_),
    .C(hw2reg_9_),
    .Y(_088_));
 sg13g2_a21oi_1 _273_ (.A1(hw2reg_9_),
    .A2(_086_),
    .Y(net141),
    .B1(_088_));
 sg13g2_xnor2_1 _274_ (.Y(_089_),
    .A(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_1__u_filter_filter_q));
 sg13g2_inv_1 _275_ (.Y(_090_),
    .A(_089_));
 sg13g2_nand2_1 _276_ (.Y(_091_),
    .A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_));
 sg13g2_inv_1 _277_ (.Y(_092_),
    .A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_));
 sg13g2_nand2b_1 _278_ (.Y(_093_),
    .B(_092_),
    .A_N(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_));
 sg13g2_inv_1 _279_ (.Y(_094_),
    .A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_2_));
 sg13g2_nor2_1 _280_ (.A(_094_),
    .B(_091_),
    .Y(_095_));
 sg13g2_a22oi_1 _281_ (.Y(_096_),
    .B1(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_),
    .B2(_095_),
    .A2(_093_),
    .A1(_091_));
 sg13g2_nor2_1 _282_ (.A(_090_),
    .B(_096_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_1_));
 sg13g2_a21oi_1 _283_ (.A1(_095_),
    .A2(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_),
    .Y(_097_),
    .B1(_092_));
 sg13g2_nor2_1 _284_ (.A(_090_),
    .B(_097_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_0_));
 sg13g2_inv_1 _285_ (.Y(_098_),
    .A(reg2hw_2_));
 sg13g2_inv_1 _286_ (.Y(net145),
    .A(net190));
 sg13g2_nand2_2 _287_ (.Y(_099_),
    .A(net145),
    .B(net97));
 sg13g2_nor3_1 _288_ (.A(net95),
    .B(net96),
    .C(_099_),
    .Y(_100_));
 sg13g2_inv_1 _289_ (.Y(_101_),
    .A(net121));
 sg13g2_inv_1 _290_ (.Y(_102_),
    .A(net122));
 sg13g2_nand3_1 _291_ (.B(_101_),
    .C(_102_),
    .A(_100_),
    .Y(_103_));
 sg13g2_inv_2 _292_ (.Y(_104_),
    .A(net124));
 sg13g2_nor2_1 _293_ (.A(net123),
    .B(_104_),
    .Y(_105_));
 sg13g2_nand2_1 _294_ (.Y(_106_),
    .A(net119),
    .B(net120));
 sg13g2_inv_1 _295_ (.Y(_107_),
    .A(net118));
 sg13g2_a21oi_1 _296_ (.A1(_105_),
    .A2(_106_),
    .Y(_108_),
    .B1(_107_));
 sg13g2_nand2_1 _297_ (.Y(_109_),
    .A(net124),
    .B(net123));
 sg13g2_o21ai_1 _298_ (.B1(_109_),
    .Y(_110_),
    .A1(_108_),
    .A2(net354));
 sg13g2_nor2_1 _299_ (.A(_103_),
    .B(_110_),
    .Y(_111_));
 sg13g2_nand2_1 _300_ (.Y(_112_),
    .A(_111_),
    .B(_105_));
 sg13g2_nor2_1 _302_ (.A(net100),
    .B(net273),
    .Y(_114_));
 sg13g2_a21oi_1 _303_ (.A1(_098_),
    .A2(net273),
    .Y(_000_),
    .B1(_114_));
 sg13g2_mux2_1 _304_ (.A0(net99),
    .A1(reg2hw_1_),
    .S(net273),
    .X(_001_));
 sg13g2_mux2_1 _305_ (.A0(net98),
    .A1(reg2hw_0_),
    .S(net273),
    .X(_002_));
 sg13g2_mux2_1 _306_ (.A0(net112),
    .A1(reg2hw_14_),
    .S(net272),
    .X(_003_));
 sg13g2_mux2_1 _307_ (.A0(net111),
    .A1(reg2hw_13_),
    .S(net272),
    .X(_004_));
 sg13g2_mux2_1 _308_ (.A0(net110),
    .A1(reg2hw_12_),
    .S(net272),
    .X(_005_));
 sg13g2_mux2_1 _309_ (.A0(net108),
    .A1(reg2hw_10_),
    .S(net272),
    .X(_006_));
 sg13g2_mux2_1 _310_ (.A0(net107),
    .A1(reg2hw_9_),
    .S(_112_),
    .X(_007_));
 sg13g2_mux2_1 _311_ (.A0(net106),
    .A1(reg2hw_8_),
    .S(_112_),
    .X(_008_));
 sg13g2_mux2_1 _312_ (.A0(net116),
    .A1(reg2hw_18_),
    .S(net272),
    .X(_009_));
 sg13g2_mux2_1 _313_ (.A0(net115),
    .A1(reg2hw_17_),
    .S(net272),
    .X(_010_));
 sg13g2_mux2_1 _314_ (.A0(net114),
    .A1(reg2hw_16_),
    .S(net272),
    .X(_011_));
 sg13g2_mux2_1 _315_ (.A0(net104),
    .A1(reg2hw_6_),
    .S(net273),
    .X(_012_));
 sg13g2_mux2_1 _316_ (.A0(net103),
    .A1(reg2hw_5_),
    .S(net273),
    .X(_013_));
 sg13g2_mux2_1 _317_ (.A0(net102),
    .A1(reg2hw_4_),
    .S(net273),
    .X(_014_));
 sg13g2_mux2_1 _319_ (.A0(net92),
    .A1(net187),
    .S(net279),
    .X(_015_));
 sg13g2_mux2_1 _320_ (.A0(net131),
    .A1(net185),
    .S(net279),
    .X(_016_));
 sg13g2_mux2_1 _321_ (.A0(net130),
    .A1(net184),
    .S(_099_),
    .X(_017_));
 sg13g2_mux2_1 _322_ (.A0(net129),
    .A1(net183),
    .S(net279),
    .X(_018_));
 sg13g2_mux2_1 _323_ (.A0(net128),
    .A1(net182),
    .S(net279),
    .X(_019_));
 sg13g2_mux2_1 _324_ (.A0(net127),
    .A1(net181),
    .S(net279),
    .X(_020_));
 sg13g2_mux2_1 _325_ (.A0(net126),
    .A1(net180),
    .S(net279),
    .X(_021_));
 sg13g2_mux2_1 _326_ (.A0(net125),
    .A1(net179),
    .S(net279),
    .X(_022_));
 sg13g2_inv_1 _327_ (.Y(_116_),
    .A(net177));
 sg13g2_inv_1 _328_ (.Y(_117_),
    .A(_099_));
 sg13g2_inv_1 _329_ (.Y(_118_),
    .A(_100_));
 sg13g2_nor2_1 _330_ (.A(net94),
    .B(net95),
    .Y(_119_));
 sg13g2_nand3_1 _331_ (.B(net96),
    .C(_119_),
    .A(_117_),
    .Y(_120_));
 sg13g2_a21oi_1 _332_ (.A1(_101_),
    .A2(_102_),
    .Y(_121_),
    .B1(_118_));
 sg13g2_a21oi_1 _333_ (.A1(_118_),
    .A2(net332),
    .Y(_122_),
    .B1(net358));
 sg13g2_nand2_1 _334_ (.Y(_123_),
    .A(_122_),
    .B(_110_));
 sg13g2_nand3_1 _335_ (.B(_118_),
    .C(_109_),
    .A(_123_),
    .Y(_124_));
 sg13g2_nand2_1 _336_ (.Y(_125_),
    .A(net366),
    .B(net278));
 sg13g2_o21ai_1 _338_ (.B1(net271),
    .Y(_023_),
    .A1(_116_),
    .A2(net278));
 sg13g2_inv_1 _339_ (.Y(_127_),
    .A(net176));
 sg13g2_o21ai_1 _340_ (.B1(net271),
    .Y(_024_),
    .A1(_127_),
    .A2(net278));
 sg13g2_inv_1 _341_ (.Y(_128_),
    .A(net175));
 sg13g2_o21ai_1 _342_ (.B1(net270),
    .Y(_025_),
    .A1(_128_),
    .A2(net277));
 sg13g2_inv_1 _343_ (.Y(_129_),
    .A(net174));
 sg13g2_o21ai_1 _344_ (.B1(net270),
    .Y(_026_),
    .A1(_129_),
    .A2(net277));
 sg13g2_inv_1 _345_ (.Y(_130_),
    .A(net173));
 sg13g2_o21ai_1 _346_ (.B1(net270),
    .Y(_027_),
    .A1(_130_),
    .A2(net277));
 sg13g2_inv_1 _347_ (.Y(_131_),
    .A(net172));
 sg13g2_o21ai_1 _348_ (.B1(net270),
    .Y(_028_),
    .A1(_131_),
    .A2(net277));
 sg13g2_inv_1 _349_ (.Y(_132_),
    .A(net171));
 sg13g2_o21ai_1 _350_ (.B1(net270),
    .Y(_029_),
    .A1(_132_),
    .A2(net277));
 sg13g2_inv_1 _351_ (.Y(_133_),
    .A(net170));
 sg13g2_o21ai_1 _352_ (.B1(net270),
    .Y(_030_),
    .A1(_133_),
    .A2(net277));
 sg13g2_inv_1 _353_ (.Y(_134_),
    .A(net169));
 sg13g2_o21ai_1 _354_ (.B1(net270),
    .Y(_031_),
    .A1(_134_),
    .A2(net277));
 sg13g2_inv_1 _355_ (.Y(_135_),
    .A(net168));
 sg13g2_o21ai_1 _356_ (.B1(net270),
    .Y(_032_),
    .A1(_135_),
    .A2(net277));
 sg13g2_inv_1 _357_ (.Y(_136_),
    .A(net167));
 sg13g2_o21ai_1 _358_ (.B1(net271),
    .Y(_033_),
    .A1(_136_),
    .A2(net278));
 sg13g2_nor3_2 _359_ (.A(_104_),
    .B(net123),
    .C(_099_),
    .Y(_137_));
 sg13g2_a22oi_1 _360_ (.Y(_138_),
    .B1(reg2hw_19_),
    .B2(net276),
    .A2(net281),
    .A1(net166));
 sg13g2_nand2_1 _361_ (.Y(_034_),
    .A(net269),
    .B(_138_));
 sg13g2_a22oi_1 _362_ (.Y(_139_),
    .B1(reg2hw_18_),
    .B2(net276),
    .A2(net281),
    .A1(net165));
 sg13g2_nand2_1 _363_ (.Y(_035_),
    .A(net269),
    .B(_139_));
 sg13g2_a22oi_1 _364_ (.Y(_140_),
    .B1(reg2hw_17_),
    .B2(net276),
    .A2(net281),
    .A1(net164));
 sg13g2_nand2_1 _365_ (.Y(_036_),
    .A(net269),
    .B(_140_));
 sg13g2_a22oi_1 _366_ (.Y(_141_),
    .B1(reg2hw_16_),
    .B2(net276),
    .A2(net281),
    .A1(net163));
 sg13g2_nand2_1 _367_ (.Y(_037_),
    .A(net269),
    .B(_141_));
 sg13g2_a22oi_1 _368_ (.Y(_142_),
    .B1(reg2hw_15_),
    .B2(net276),
    .A2(net281),
    .A1(net162));
 sg13g2_nand2_1 _369_ (.Y(_038_),
    .A(net269),
    .B(_142_));
 sg13g2_a22oi_1 _370_ (.Y(_143_),
    .B1(reg2hw_14_),
    .B2(net276),
    .A2(net281),
    .A1(net161));
 sg13g2_nand2_1 _371_ (.Y(_039_),
    .A(net269),
    .B(_143_));
 sg13g2_a22oi_1 _372_ (.Y(_144_),
    .B1(reg2hw_13_),
    .B2(net276),
    .A2(net281),
    .A1(net160));
 sg13g2_nand2_1 _373_ (.Y(_040_),
    .A(net269),
    .B(_144_));
 sg13g2_a22oi_1 _374_ (.Y(_145_),
    .B1(reg2hw_12_),
    .B2(net276),
    .A2(net281),
    .A1(net159));
 sg13g2_nand2_1 _375_ (.Y(_041_),
    .A(net269),
    .B(_145_));
 sg13g2_a22oi_1 _376_ (.Y(_146_),
    .B1(reg2hw_11_),
    .B2(net363),
    .A2(net282),
    .A1(net158));
 sg13g2_nand2_1 _377_ (.Y(_042_),
    .A(_125_),
    .B(_146_));
 sg13g2_a22oi_1 _378_ (.Y(_147_),
    .B1(reg2hw_10_),
    .B2(net363),
    .A2(net282),
    .A1(net157));
 sg13g2_nand2_1 _379_ (.Y(_043_),
    .A(net271),
    .B(_147_));
 sg13g2_a22oi_1 _380_ (.Y(_148_),
    .B1(reg2hw_9_),
    .B2(net363),
    .A2(net282),
    .A1(net156));
 sg13g2_nand2_1 _381_ (.Y(_044_),
    .A(_125_),
    .B(_148_));
 sg13g2_a22oi_1 _382_ (.Y(_149_),
    .B1(reg2hw_8_),
    .B2(net363),
    .A2(net282),
    .A1(net155));
 sg13g2_nand2_1 _383_ (.Y(_045_),
    .A(net271),
    .B(_149_));
 sg13g2_inv_1 _384_ (.Y(_150_),
    .A(net154));
 sg13g2_inv_1 _385_ (.Y(_151_),
    .A(net136));
 sg13g2_inv_1 _386_ (.Y(_152_),
    .A(net123));
 sg13g2_o21ai_1 _387_ (.B1(_104_),
    .Y(_153_),
    .A1(_151_),
    .A2(net298));
 sg13g2_o21ai_1 _388_ (.B1(_153_),
    .Y(_154_),
    .A1(reg2hw_7_),
    .A2(net123));
 sg13g2_and3_1 _389_ (.X(_155_),
    .A(_123_),
    .B(net278),
    .C(_118_));
 sg13g2_a22oi_1 _391_ (.Y(_046_),
    .B1(net361),
    .B2(_155_),
    .A2(net280),
    .A1(_150_));
 sg13g2_inv_1 _392_ (.Y(_157_),
    .A(net153));
 sg13g2_inv_1 _393_ (.Y(_158_),
    .A(net135));
 sg13g2_o21ai_1 _394_ (.B1(_104_),
    .Y(_159_),
    .A1(_158_),
    .A2(net298));
 sg13g2_o21ai_1 _395_ (.B1(_159_),
    .Y(_160_),
    .A1(reg2hw_6_),
    .A2(net300));
 sg13g2_a22oi_1 _396_ (.Y(_047_),
    .B1(_160_),
    .B2(_155_),
    .A2(net280),
    .A1(_157_));
 sg13g2_inv_1 _397_ (.Y(_161_),
    .A(net152));
 sg13g2_inv_1 _398_ (.Y(_162_),
    .A(net134));
 sg13g2_o21ai_1 _399_ (.B1(_104_),
    .Y(_163_),
    .A1(_162_),
    .A2(net298));
 sg13g2_o21ai_1 _400_ (.B1(_163_),
    .Y(_164_),
    .A1(reg2hw_5_),
    .A2(net300));
 sg13g2_a22oi_1 _401_ (.Y(_048_),
    .B1(_164_),
    .B2(_155_),
    .A2(net280),
    .A1(_161_));
 sg13g2_inv_1 _402_ (.Y(_165_),
    .A(net151));
 sg13g2_inv_1 _403_ (.Y(_166_),
    .A(net133));
 sg13g2_o21ai_1 _404_ (.B1(_104_),
    .Y(_167_),
    .A1(net298),
    .A2(_166_));
 sg13g2_o21ai_1 _405_ (.B1(_167_),
    .Y(_168_),
    .A1(reg2hw_4_),
    .A2(net300));
 sg13g2_a22oi_1 _406_ (.Y(_049_),
    .B1(_168_),
    .B2(_155_),
    .A2(net280),
    .A1(_165_));
 sg13g2_inv_1 _407_ (.Y(_169_),
    .A(net149));
 sg13g2_nor2_1 _408_ (.A(net124),
    .B(net300),
    .Y(_170_));
 sg13g2_nand2b_1 _409_ (.Y(_171_),
    .B(net298),
    .A_N(reg2hw_3_));
 sg13g2_inv_1 _410_ (.Y(_172_),
    .A(net140));
 sg13g2_o21ai_1 _411_ (.B1(_104_),
    .Y(_173_),
    .A1(net298),
    .A2(_172_));
 sg13g2_a22oi_1 _412_ (.Y(_174_),
    .B1(_171_),
    .B2(_173_),
    .A2(_170_),
    .A1(u_gpio_reg_u_reg_core_data_in_qs_3_));
 sg13g2_a22oi_1 _413_ (.Y(_050_),
    .B1(_174_),
    .B2(_155_),
    .A2(net280),
    .A1(_169_));
 sg13g2_inv_1 _414_ (.Y(_175_),
    .A(net148));
 sg13g2_nand2_1 _415_ (.Y(_176_),
    .A(_098_),
    .B(net298));
 sg13g2_inv_1 _416_ (.Y(_177_),
    .A(net139));
 sg13g2_o21ai_1 _417_ (.B1(net299),
    .Y(_178_),
    .A1(net298),
    .A2(_177_));
 sg13g2_a22oi_1 _418_ (.Y(_179_),
    .B1(_176_),
    .B2(_178_),
    .A2(_170_),
    .A1(u_gpio_reg_u_reg_core_data_in_qs_2_));
 sg13g2_a22oi_1 _419_ (.Y(_051_),
    .B1(_179_),
    .B2(_155_),
    .A2(net280),
    .A1(_175_));
 sg13g2_inv_1 _420_ (.Y(_180_),
    .A(net147));
 sg13g2_inv_1 _421_ (.Y(_181_),
    .A(net138));
 sg13g2_nand3_1 _422_ (.B(_181_),
    .C(net300),
    .A(net299),
    .Y(_182_));
 sg13g2_a21o_1 _423_ (.A2(u_gpio_reg_u_reg_core_data_in_qs_1_),
    .A1(net299),
    .B1(net300),
    .X(_183_));
 sg13g2_a22oi_1 _424_ (.Y(_184_),
    .B1(_182_),
    .B2(_183_),
    .A2(_105_),
    .A1(reg2hw_1_));
 sg13g2_a22oi_1 _425_ (.Y(_052_),
    .B1(_184_),
    .B2(_155_),
    .A2(net280),
    .A1(_180_));
 sg13g2_inv_1 _426_ (.Y(_185_),
    .A(net146));
 sg13g2_inv_1 _427_ (.Y(_186_),
    .A(net137));
 sg13g2_nand3_1 _428_ (.B(_186_),
    .C(net300),
    .A(net299),
    .Y(_187_));
 sg13g2_a21o_1 _429_ (.A2(u_gpio_reg_u_reg_core_data_in_qs_0_),
    .A1(net299),
    .B1(net300),
    .X(_188_));
 sg13g2_a22oi_1 _430_ (.Y(_189_),
    .B1(_187_),
    .B2(_188_),
    .A2(_105_),
    .A1(reg2hw_0_));
 sg13g2_a22oi_1 _431_ (.Y(_053_),
    .B1(_189_),
    .B2(_155_),
    .A2(net280),
    .A1(_185_));
 sg13g2_nor4_1 _432_ (.A(net124),
    .B(_152_),
    .C(_103_),
    .D(_110_),
    .Y(_190_));
 sg13g2_nand2_1 _434_ (.Y(_192_),
    .A(net274),
    .B(net104));
 sg13g2_o21ai_1 _435_ (.B1(_192_),
    .Y(_054_),
    .A1(_158_),
    .A2(net274));
 sg13g2_nand2_1 _436_ (.Y(_193_),
    .A(net275),
    .B(net103));
 sg13g2_o21ai_1 _437_ (.B1(net318),
    .Y(_055_),
    .A1(_162_),
    .A2(net275));
 sg13g2_nand2_1 _438_ (.Y(_194_),
    .A(net275),
    .B(net102));
 sg13g2_o21ai_1 _439_ (.B1(net328),
    .Y(_056_),
    .A1(_166_),
    .A2(net275));
 sg13g2_nand2_1 _440_ (.Y(_195_),
    .A(net274),
    .B(net100));
 sg13g2_o21ai_1 _441_ (.B1(_195_),
    .Y(_057_),
    .A1(_177_),
    .A2(net274));
 sg13g2_nand2_1 _442_ (.Y(_196_),
    .A(net274),
    .B(net99));
 sg13g2_o21ai_1 _443_ (.B1(_196_),
    .Y(_058_),
    .A1(_181_),
    .A2(net274));
 sg13g2_nand2_1 _444_ (.Y(_197_),
    .A(net274),
    .B(net98));
 sg13g2_o21ai_1 _445_ (.B1(_197_),
    .Y(_059_),
    .A1(_186_),
    .A2(net274));
 sg13g2_inv_1 _446_ (.Y(_198_),
    .A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_2_));
 sg13g2_inv_1 _447_ (.Y(_199_),
    .A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_));
 sg13g2_inv_1 _448_ (.Y(_200_),
    .A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_1_));
 sg13g2_nor2_1 _449_ (.A(_199_),
    .B(_200_),
    .Y(_201_));
 sg13g2_inv_1 _450_ (.Y(_202_),
    .A(_201_));
 sg13g2_nor2_1 _451_ (.A(_198_),
    .B(_202_),
    .Y(_203_));
 sg13g2_nand2_1 _452_ (.Y(_204_),
    .A(_203_),
    .B(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_));
 sg13g2_xnor2_1 _453_ (.Y(_205_),
    .A(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_3__u_filter_filter_q));
 sg13g2_inv_1 _454_ (.Y(_206_),
    .A(_205_));
 sg13g2_a21oi_1 _455_ (.A1(_204_),
    .A2(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_0_),
    .B1(_206_));
 sg13g2_inv_1 _456_ (.Y(_207_),
    .A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_));
 sg13g2_o21ai_1 _457_ (.B1(_205_),
    .Y(_208_),
    .A1(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_2_),
    .A2(_201_));
 sg13g2_a21oi_1 _458_ (.A1(_203_),
    .A2(_207_),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_2_),
    .B1(_208_));
 sg13g2_inv_1 _459_ (.Y(_209_),
    .A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_));
 sg13g2_inv_1 _460_ (.Y(_210_),
    .A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_));
 sg13g2_nor2_1 _461_ (.A(_209_),
    .B(_210_),
    .Y(_211_));
 sg13g2_nand2_1 _462_ (.Y(_212_),
    .A(_211_),
    .B(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_));
 sg13g2_inv_1 _463_ (.Y(_213_),
    .A(_212_));
 sg13g2_inv_1 _464_ (.Y(_214_),
    .A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_));
 sg13g2_xnor2_1 _465_ (.Y(_215_),
    .A(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_0__u_filter_filter_q));
 sg13g2_o21ai_1 _466_ (.B1(_215_),
    .Y(_216_),
    .A1(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_),
    .A2(_211_));
 sg13g2_a21oi_1 _467_ (.A1(_213_),
    .A2(_214_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_2_),
    .B1(_216_));
 sg13g2_nand2_1 _468_ (.Y(_217_),
    .A(_213_),
    .B(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_));
 sg13g2_xnor2_1 _469_ (.Y(_218_),
    .A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_));
 sg13g2_inv_1 _470_ (.Y(_219_),
    .A(_215_));
 sg13g2_a21oi_1 _471_ (.A1(_217_),
    .A2(_218_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_),
    .B1(_219_));
 sg13g2_a21oi_1 _472_ (.A1(_217_),
    .A2(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_0_),
    .B1(_219_));
 sg13g2_a21oi_1 _473_ (.A1(_212_),
    .A2(_214_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_3_),
    .B1(_219_));
 sg13g2_nand2_1 _474_ (.Y(_220_),
    .A(_199_),
    .B(_200_));
 sg13g2_a22oi_1 _475_ (.Y(_221_),
    .B1(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_),
    .B2(_203_),
    .A2(_220_),
    .A1(_202_));
 sg13g2_nor2_1 _476_ (.A(_206_),
    .B(_221_),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_1_));
 sg13g2_inv_1 _477_ (.Y(_222_),
    .A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_));
 sg13g2_inv_1 _478_ (.Y(_223_),
    .A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_));
 sg13g2_nor2_1 _479_ (.A(_222_),
    .B(_223_),
    .Y(_224_));
 sg13g2_nand2_1 _480_ (.Y(_225_),
    .A(_224_),
    .B(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_2_));
 sg13g2_inv_1 _481_ (.Y(_226_),
    .A(_225_));
 sg13g2_inv_1 _482_ (.Y(_227_),
    .A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_));
 sg13g2_xnor2_1 _483_ (.Y(_228_),
    .A(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_2__u_filter_filter_q));
 sg13g2_o21ai_1 _484_ (.B1(_228_),
    .Y(_229_),
    .A1(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_2_),
    .A2(_224_));
 sg13g2_a21oi_1 _485_ (.A1(_226_),
    .A2(_227_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_2_),
    .B1(_229_));
 sg13g2_nand2_1 _486_ (.Y(_230_),
    .A(_226_),
    .B(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_));
 sg13g2_xnor2_1 _487_ (.Y(_231_),
    .A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .B(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_));
 sg13g2_inv_1 _488_ (.Y(_232_),
    .A(_228_));
 sg13g2_a21oi_1 _489_ (.A1(_230_),
    .A2(_231_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_),
    .B1(_232_));
 sg13g2_a21oi_1 _490_ (.A1(_230_),
    .A2(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_0_),
    .B1(_232_));
 sg13g2_a21oi_1 _491_ (.A1(_225_),
    .A2(_227_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_3_),
    .B1(_232_));
 sg13g2_inv_1 _492_ (.Y(_233_),
    .A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_));
 sg13g2_a21o_1 _493_ (.A2(_091_),
    .A1(_094_),
    .B1(_090_),
    .X(_234_));
 sg13g2_a21oi_1 _494_ (.A1(_233_),
    .A2(_095_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_2_),
    .B1(_234_));
 sg13g2_inv_1 _495_ (.Y(_235_),
    .A(_203_));
 sg13g2_a21oi_1 _496_ (.A1(_235_),
    .A2(_207_),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_3_),
    .B1(_206_));
 sg13g2_inv_1 _497_ (.Y(_236_),
    .A(_095_));
 sg13g2_a21oi_1 _498_ (.A1(_236_),
    .A2(_233_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_),
    .B1(_090_));
 sg13g2_mux2_1 _499_ (.A0(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .A1(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .S(reg2hw_19_),
    .X(hw2reg_12_));
 sg13g2_inv_1 _500_ (.Y(_237_),
    .A(u_gpio_core_data_in_q_3_));
 sg13g2_a21oi_1 _501_ (.A1(_237_),
    .A2(reg2hw_3_),
    .Y(_238_),
    .B1(reg2hw_11_));
 sg13g2_nor2b_1 _502_ (.A(_237_),
    .B_N(reg2hw_7_),
    .Y(_239_));
 sg13g2_nor3_1 _503_ (.A(reg2hw_15_),
    .B(_239_),
    .C(hw2reg_12_),
    .Y(_240_));
 sg13g2_a21oi_1 _504_ (.A1(hw2reg_12_),
    .A2(_238_),
    .Y(net144),
    .B1(_240_));
 sg13g2_o21ai_1 _505_ (.B1(_217_),
    .Y(_241_),
    .A1(_209_),
    .A2(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_));
 sg13g2_nand3b_1 _506_ (.B(_241_),
    .C(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
    .Y(_242_),
    .A_N(_216_));
 sg13g2_mux2_1 _507_ (.A0(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .A1(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .S(_242_),
    .X(_060_));
 sg13g2_nor2_1 _508_ (.A(_097_),
    .B(_096_),
    .Y(_243_));
 sg13g2_nand3_1 _509_ (.B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_),
    .C(_243_),
    .A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_2_),
    .Y(_244_));
 sg13g2_mux2_1 _510_ (.A0(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .A1(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .S(_244_),
    .X(_061_));
 sg13g2_o21ai_1 _511_ (.B1(_230_),
    .Y(_245_),
    .A1(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .A2(_223_));
 sg13g2_nand3b_1 _512_ (.B(_245_),
    .C(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
    .Y(_246_),
    .A_N(_229_));
 sg13g2_mux2_1 _513_ (.A0(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .A1(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .S(_246_),
    .X(_062_));
 sg13g2_nor3_1 _514_ (.A(_207_),
    .B(_208_),
    .C(_221_),
    .Y(_247_));
 sg13g2_nand2_1 _515_ (.Y(_248_),
    .A(_247_),
    .B(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_0_));
 sg13g2_mux2_1 _516_ (.A0(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .A1(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .S(_248_),
    .X(_063_));
 sg13g2_nand2_1 _517_ (.Y(_249_),
    .A(_190_),
    .B(net101));
 sg13g2_o21ai_1 _518_ (.B1(net351),
    .Y(_064_),
    .A1(_172_),
    .A2(net275));
 sg13g2_nand2_1 _519_ (.Y(_250_),
    .A(_190_),
    .B(net105));
 sg13g2_o21ai_1 _520_ (.B1(net344),
    .Y(_065_),
    .A1(_151_),
    .A2(net275));
 sg13g2_nand2_1 _521_ (.Y(_251_),
    .A(net282),
    .B(net150));
 sg13g2_nand3b_1 _522_ (.B(_123_),
    .C(_251_),
    .Y(_066_),
    .A_N(net358));
 sg13g2_o21ai_1 _523_ (.B1(_099_),
    .Y(_067_),
    .A1(net145),
    .A2(net310));
 sg13g2_inv_1 _524_ (.Y(_252_),
    .A(net178));
 sg13g2_o21ai_1 _525_ (.B1(net271),
    .Y(_068_),
    .A1(_252_),
    .A2(net278));
 sg13g2_mux2_1 _526_ (.A0(net132),
    .A1(net186),
    .S(net279),
    .X(_069_));
 sg13g2_mux2_1 _527_ (.A0(net93),
    .A1(net188),
    .S(_099_),
    .X(_070_));
 sg13g2_mux2_1 _528_ (.A0(net105),
    .A1(reg2hw_7_),
    .S(net273),
    .X(_071_));
 sg13g2_mux2_1 _529_ (.A0(net117),
    .A1(reg2hw_19_),
    .S(net272),
    .X(_072_));
 sg13g2_mux2_1 _530_ (.A0(net109),
    .A1(reg2hw_11_),
    .S(_112_),
    .X(_073_));
 sg13g2_mux2_1 _531_ (.A0(net113),
    .A1(reg2hw_15_),
    .S(_112_),
    .X(_074_));
 sg13g2_mux2_1 _532_ (.A0(net101),
    .A1(reg2hw_3_),
    .S(_112_),
    .X(_075_));
 sg13g2_inv_1 _533_ (.Y(_253_),
    .A(net189));
 sg13g2_o21ai_1 _534_ (.B1(net332),
    .Y(_076_),
    .A1(_253_),
    .A2(net278));
 sg13g2_dfrbpq_1 _535_ (.RESET_B(net293),
    .D(_076_),
    .Q(net189),
    .CLK(clknet_5_14__leaf_clk_i));
 sg13g2_dfrbpq_1 _536_ (.RESET_B(net283),
    .D(_060_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .CLK(clknet_5_22__leaf_clk_i));
 sg13g2_dfrbpq_1 _537_ (.RESET_B(u_gpio_core_filter_rst_ni),
    .D(_061_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .CLK(clknet_5_7__leaf_clk_i));
 sg13g2_dfrbpq_1 _538_ (.RESET_B(net286),
    .D(_062_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .CLK(clknet_5_5__leaf_clk_i));
 sg13g2_dfrbpq_1 _539_ (.RESET_B(net286),
    .D(_063_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .CLK(clknet_5_1__leaf_clk_i));
 sg13g2_dfrbpq_1 _540_ (.RESET_B(net287),
    .D(_059_),
    .Q(net137),
    .CLK(clknet_5_29__leaf_clk_i));
 sg13g2_dfrbpq_1 _541_ (.RESET_B(net287),
    .D(_058_),
    .Q(net138),
    .CLK(clknet_5_29__leaf_clk_i));
 sg13g2_dfrbpq_1 _542_ (.RESET_B(net287),
    .D(_057_),
    .Q(net139),
    .CLK(clknet_5_28__leaf_clk_i));
 sg13g2_dfrbpq_1 _543_ (.RESET_B(net287),
    .D(net352),
    .Q(net140),
    .CLK(clknet_5_31__leaf_clk_i));
 sg13g2_dfrbpq_1 _544_ (.RESET_B(net287),
    .D(net329),
    .Q(net133),
    .CLK(clknet_5_31__leaf_clk_i));
 sg13g2_dfrbpq_1 _545_ (.RESET_B(net287),
    .D(net319),
    .Q(net134),
    .CLK(clknet_5_31__leaf_clk_i));
 sg13g2_dfrbpq_1 _546_ (.RESET_B(net287),
    .D(_054_),
    .Q(net135),
    .CLK(clknet_5_28__leaf_clk_i));
 sg13g2_dfrbpq_1 _547_ (.RESET_B(net287),
    .D(net345),
    .Q(net136),
    .CLK(clknet_5_30__leaf_clk_i));
 sg13g2_dfrbpq_1 _548_ (.RESET_B(net293),
    .D(net359),
    .Q(net150),
    .CLK(clknet_5_14__leaf_clk_i));
 sg13g2_dfrbpq_1 _549_ (.RESET_B(net293),
    .D(net311),
    .Q(net190),
    .CLK(clknet_5_14__leaf_clk_i));
 sg13g2_dfrbpq_1 _550_ (.RESET_B(net288),
    .D(_053_),
    .Q(net146),
    .CLK(clknet_5_26__leaf_clk_i));
 sg13g2_dfrbpq_1 _551_ (.RESET_B(net288),
    .D(_052_),
    .Q(net147),
    .CLK(clknet_5_27__leaf_clk_i));
 sg13g2_dfrbpq_1 _552_ (.RESET_B(net288),
    .D(_051_),
    .Q(net148),
    .CLK(clknet_5_26__leaf_clk_i));
 sg13g2_dfrbpq_1 _553_ (.RESET_B(net288),
    .D(_050_),
    .Q(net149),
    .CLK(clknet_5_26__leaf_clk_i));
 sg13g2_dfrbpq_1 _554_ (.RESET_B(net288),
    .D(_049_),
    .Q(net151),
    .CLK(clknet_5_27__leaf_clk_i));
 sg13g2_dfrbpq_1 _555_ (.RESET_B(net288),
    .D(_048_),
    .Q(net152),
    .CLK(clknet_5_30__leaf_clk_i));
 sg13g2_dfrbpq_1 _556_ (.RESET_B(net288),
    .D(_047_),
    .Q(net153),
    .CLK(clknet_5_30__leaf_clk_i));
 sg13g2_dfrbpq_1 _557_ (.RESET_B(net288),
    .D(_046_),
    .Q(net154),
    .CLK(clknet_5_26__leaf_clk_i));
 sg13g2_dfrbpq_1 _558_ (.RESET_B(net297),
    .D(_045_),
    .Q(net155),
    .CLK(clknet_5_12__leaf_clk_i));
 sg13g2_dfrbpq_1 _559_ (.RESET_B(net293),
    .D(net364),
    .Q(net156),
    .CLK(clknet_5_15__leaf_clk_i));
 sg13g2_dfrbpq_1 _560_ (.RESET_B(net292),
    .D(_043_),
    .Q(net157),
    .CLK(clknet_5_13__leaf_clk_i));
 sg13g2_dfrbpq_1 _561_ (.RESET_B(net293),
    .D(_042_),
    .Q(net158),
    .CLK(clknet_5_15__leaf_clk_i));
 sg13g2_dfrbpq_1 _562_ (.RESET_B(net292),
    .D(_041_),
    .Q(net159),
    .CLK(clknet_5_12__leaf_clk_i));
 sg13g2_dfrbpq_1 _563_ (.RESET_B(net292),
    .D(_040_),
    .Q(net160),
    .CLK(clknet_5_12__leaf_clk_i));
 sg13g2_dfrbpq_1 _564_ (.RESET_B(net292),
    .D(_039_),
    .Q(net161),
    .CLK(clknet_5_6__leaf_clk_i));
 sg13g2_dfrbpq_1 _565_ (.RESET_B(net292),
    .D(_038_),
    .Q(net162),
    .CLK(clknet_5_6__leaf_clk_i));
 sg13g2_dfrbpq_1 _566_ (.RESET_B(net291),
    .D(_037_),
    .Q(net163),
    .CLK(clknet_5_3__leaf_clk_i));
 sg13g2_dfrbpq_1 _567_ (.RESET_B(net291),
    .D(_036_),
    .Q(net164),
    .CLK(clknet_5_18__leaf_clk_i));
 sg13g2_dfrbpq_1 _568_ (.RESET_B(net291),
    .D(_035_),
    .Q(net165),
    .CLK(clknet_5_1__leaf_clk_i));
 sg13g2_dfrbpq_1 _569_ (.RESET_B(net291),
    .D(_034_),
    .Q(net166),
    .CLK(clknet_5_6__leaf_clk_i));
 sg13g2_dfrbpq_1 _570_ (.RESET_B(net296),
    .D(_033_),
    .Q(net167),
    .CLK(clknet_5_9__leaf_clk_i));
 sg13g2_dfrbpq_1 _571_ (.RESET_B(net294),
    .D(_032_),
    .Q(net168),
    .CLK(clknet_5_8__leaf_clk_i));
 sg13g2_dfrbpq_1 _572_ (.RESET_B(net294),
    .D(_031_),
    .Q(net169),
    .CLK(clknet_5_8__leaf_clk_i));
 sg13g2_dfrbpq_1 _573_ (.RESET_B(net294),
    .D(_030_),
    .Q(net170),
    .CLK(clknet_5_2__leaf_clk_i));
 sg13g2_dfrbpq_1 _574_ (.RESET_B(net294),
    .D(_029_),
    .Q(net171),
    .CLK(clknet_5_2__leaf_clk_i));
 sg13g2_dfrbpq_1 _575_ (.RESET_B(net294),
    .D(_028_),
    .Q(net172),
    .CLK(clknet_5_2__leaf_clk_i));
 sg13g2_dfrbpq_1 _576_ (.RESET_B(net294),
    .D(_027_),
    .Q(net173),
    .CLK(clknet_5_2__leaf_clk_i));
 sg13g2_dfrbpq_1 _577_ (.RESET_B(net294),
    .D(_026_),
    .Q(net174),
    .CLK(clknet_5_8__leaf_clk_i));
 sg13g2_dfrbpq_1 _578_ (.RESET_B(net294),
    .D(_025_),
    .Q(net175),
    .CLK(clknet_5_8__leaf_clk_i));
 sg13g2_dfrbpq_1 _579_ (.RESET_B(net295),
    .D(_024_),
    .Q(net176),
    .CLK(clknet_5_9__leaf_clk_i));
 sg13g2_dfrbpq_1 _580_ (.RESET_B(net296),
    .D(_023_),
    .Q(net177),
    .CLK(clknet_5_15__leaf_clk_i));
 sg13g2_dfrbpq_1 _581_ (.RESET_B(net296),
    .D(_068_),
    .Q(net178),
    .CLK(clknet_5_12__leaf_clk_i));
 sg13g2_dfrbpq_1 _582_ (.RESET_B(net295),
    .D(_022_),
    .Q(net179),
    .CLK(clknet_5_10__leaf_clk_i));
 sg13g2_dfrbpq_1 _583_ (.RESET_B(net295),
    .D(_021_),
    .Q(net180),
    .CLK(clknet_5_9__leaf_clk_i));
 sg13g2_dfrbpq_1 _584_ (.RESET_B(net295),
    .D(_020_),
    .Q(net181),
    .CLK(clknet_5_10__leaf_clk_i));
 sg13g2_dfrbpq_1 _585_ (.RESET_B(net295),
    .D(_019_),
    .Q(net182),
    .CLK(clknet_5_11__leaf_clk_i));
 sg13g2_dfrbpq_1 _586_ (.RESET_B(net295),
    .D(_018_),
    .Q(net183),
    .CLK(clknet_5_10__leaf_clk_i));
 sg13g2_dfrbpq_1 _587_ (.RESET_B(net293),
    .D(net326),
    .Q(net184),
    .CLK(clknet_5_14__leaf_clk_i));
 sg13g2_dfrbpq_1 _588_ (.RESET_B(net295),
    .D(_016_),
    .Q(net185),
    .CLK(clknet_5_9__leaf_clk_i));
 sg13g2_dfrbpq_1 _589_ (.RESET_B(net293),
    .D(_069_),
    .Q(net186),
    .CLK(clknet_5_11__leaf_clk_i));
 sg13g2_dfrbpq_1 _590_ (.RESET_B(net295),
    .D(_015_),
    .Q(net187),
    .CLK(clknet_5_10__leaf_clk_i));
 sg13g2_dfrbpq_1 _591_ (.RESET_B(net293),
    .D(net336),
    .Q(net188),
    .CLK(clknet_5_11__leaf_clk_i));
 sg13g2_dfrbpq_1 _592_ (.RESET_B(net290),
    .D(_014_),
    .Q(reg2hw_4_),
    .CLK(clknet_5_30__leaf_clk_i));
 sg13g2_dfrbpq_1 _593_ (.RESET_B(net290),
    .D(_013_),
    .Q(reg2hw_5_),
    .CLK(clknet_5_28__leaf_clk_i));
 sg13g2_dfrbpq_1 _594_ (.RESET_B(net290),
    .D(_012_),
    .Q(reg2hw_6_),
    .CLK(clknet_5_27__leaf_clk_i));
 sg13g2_dfrbpq_1 _595_ (.RESET_B(net289),
    .D(_071_),
    .Q(reg2hw_7_),
    .CLK(clknet_5_25__leaf_clk_i));
 sg13g2_dfrbpq_1 _596_ (.RESET_B(net291),
    .D(_011_),
    .Q(reg2hw_16_),
    .CLK(clknet_5_18__leaf_clk_i));
 sg13g2_dfrbpq_1 _597_ (.RESET_B(net291),
    .D(_010_),
    .Q(reg2hw_17_),
    .CLK(clknet_5_7__leaf_clk_i));
 sg13g2_dfrbpq_1 _598_ (.RESET_B(net291),
    .D(_009_),
    .Q(reg2hw_18_),
    .CLK(clknet_5_1__leaf_clk_i));
 sg13g2_dfrbpq_1 _599_ (.RESET_B(net291),
    .D(_072_),
    .Q(reg2hw_19_),
    .CLK(clknet_5_7__leaf_clk_i));
 sg13g2_dfrbpq_1 _600_ (.RESET_B(net292),
    .D(_008_),
    .Q(reg2hw_8_),
    .CLK(clknet_5_24__leaf_clk_i));
 sg13g2_dfrbpq_1 _601_ (.RESET_B(net292),
    .D(_007_),
    .Q(reg2hw_9_),
    .CLK(clknet_5_13__leaf_clk_i));
 sg13g2_dfrbpq_1 _602_ (.RESET_B(net297),
    .D(_006_),
    .Q(reg2hw_10_),
    .CLK(clknet_5_18__leaf_clk_i));
 sg13g2_dfrbpq_1 _603_ (.RESET_B(net289),
    .D(_073_),
    .Q(reg2hw_11_),
    .CLK(clknet_5_13__leaf_clk_i));
 sg13g2_dfrbpq_1 _604_ (.RESET_B(reg_rst_ni),
    .D(_005_),
    .Q(reg2hw_12_),
    .CLK(clknet_5_19__leaf_clk_i));
 sg13g2_dfrbpq_1 _605_ (.RESET_B(net297),
    .D(_004_),
    .Q(reg2hw_13_),
    .CLK(clknet_5_19__leaf_clk_i));
 sg13g2_dfrbpq_1 _606_ (.RESET_B(net297),
    .D(_003_),
    .Q(reg2hw_14_),
    .CLK(clknet_5_18__leaf_clk_i));
 sg13g2_dfrbpq_1 _607_ (.RESET_B(net292),
    .D(_074_),
    .Q(reg2hw_15_),
    .CLK(clknet_5_13__leaf_clk_i));
 sg13g2_dfrbpq_1 _608_ (.RESET_B(net290),
    .D(_002_),
    .Q(reg2hw_0_),
    .CLK(clknet_5_29__leaf_clk_i));
 sg13g2_dfrbpq_1 _609_ (.RESET_B(net290),
    .D(_001_),
    .Q(reg2hw_1_),
    .CLK(clknet_5_28__leaf_clk_i));
 sg13g2_dfrbpq_1 _610_ (.RESET_B(net289),
    .D(_000_),
    .Q(reg2hw_2_),
    .CLK(clknet_5_25__leaf_clk_i));
 sg13g2_dfrbpq_1 _611_ (.RESET_B(net289),
    .D(_075_),
    .Q(reg2hw_3_),
    .CLK(clknet_5_24__leaf_clk_i));
 sg13g2_dfrbpq_1 _612_ (.RESET_B(net90),
    .D(u_reg_reset_sync_intq),
    .Q(reg_rst_ni),
    .CLK(clknet_5_22__leaf_clk_i));
 sg13g2_dfrbpq_1 _613_ (.RESET_B(net90),
    .D(net82),
    .Q(u_reg_reset_sync_intq),
    .CLK(clknet_5_20__leaf_clk_i));
 sg13g2_tiehi _613__22 (.L_HI(net82));
 sg13g2_dfrbpq_1 _614_ (.RESET_B(net290),
    .D(hw2reg_9_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_0_),
    .CLK(clknet_5_22__leaf_clk_i));
 sg13g2_dfrbpq_1 _615_ (.RESET_B(net289),
    .D(hw2reg_10_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_1_),
    .CLK(clknet_5_25__leaf_clk_i));
 sg13g2_dfrbpq_1 _616_ (.RESET_B(net289),
    .D(hw2reg_11_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_2_),
    .CLK(clknet_5_25__leaf_clk_i));
 sg13g2_dfrbpq_1 _617_ (.RESET_B(net289),
    .D(hw2reg_12_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_3_),
    .CLK(clknet_5_24__leaf_clk_i));
 sg13g2_dfrbpq_1 _618_ (.RESET_B(core_rst_ni),
    .D(net83),
    .Q(u_gpio_core_state_rst_ni),
    .CLK(clknet_5_19__leaf_clk_i));
 sg13g2_tiehi _618__23 (.L_HI(net83));
 sg13g2_dfrbpq_1 _619_ (.RESET_B(core_rst_ni),
    .D(net84),
    .Q(u_gpio_core_filter_rst_ni),
    .CLK(clknet_5_17__leaf_clk_i));
 sg13g2_tiehi _619__24 (.L_HI(net84));
 sg13g2_dfrbpq_1 _620_ (.RESET_B(net285),
    .D(u_gpio_core_gen_input_filter_3__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .CLK(clknet_5_1__leaf_clk_i));
 sg13g2_dfrbpq_1 _621_ (.RESET_B(net285),
    .D(net306),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_gen_async_prim_flop_2sync_intq),
    .CLK(clknet_5_0__leaf_clk_i));
 sg13g2_dfrbpq_1 _622_ (.RESET_B(net285),
    .D(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_filter_q),
    .CLK(clknet_5_4__leaf_clk_i));
 sg13g2_dfrbpq_1 _623_ (.RESET_B(net286),
    .D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_),
    .CLK(clknet_5_3__leaf_clk_i));
 sg13g2_dfrbpq_1 _624_ (.RESET_B(net286),
    .D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_1_),
    .CLK(clknet_5_3__leaf_clk_i));
 sg13g2_dfrbpq_1 _625_ (.RESET_B(net286),
    .D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_2_),
    .CLK(clknet_5_0__leaf_clk_i));
 sg13g2_dfrbpq_1 _626_ (.RESET_B(net286),
    .D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_),
    .CLK(clknet_5_0__leaf_clk_i));
 sg13g2_dfrbpq_1 _627_ (.RESET_B(net285),
    .D(u_gpio_core_gen_input_filter_2__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .CLK(clknet_5_5__leaf_clk_i));
 sg13g2_dfrbpq_1 _628_ (.RESET_B(net285),
    .D(net304),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_gen_async_prim_flop_2sync_intq),
    .CLK(clknet_5_0__leaf_clk_i));
 sg13g2_dfrbpq_1 _629_ (.RESET_B(net285),
    .D(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_filter_q),
    .CLK(clknet_5_4__leaf_clk_i));
 sg13g2_dfrbpq_1 _630_ (.RESET_B(net284),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .CLK(clknet_5_16__leaf_clk_i));
 sg13g2_dfrbpq_1 _631_ (.RESET_B(net284),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_),
    .CLK(clknet_5_16__leaf_clk_i));
 sg13g2_dfrbpq_1 _632_ (.RESET_B(net284),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_2_),
    .CLK(clknet_5_4__leaf_clk_i));
 sg13g2_dfrbpq_1 _633_ (.RESET_B(net284),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
    .CLK(clknet_5_5__leaf_clk_i));
 sg13g2_dfrbpq_1 _634_ (.RESET_B(net285),
    .D(u_gpio_core_gen_input_filter_1__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .CLK(clknet_5_4__leaf_clk_i));
 sg13g2_dfrbpq_1 _635_ (.RESET_B(net285),
    .D(net302),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_gen_async_prim_flop_2sync_intq),
    .CLK(clknet_5_5__leaf_clk_i));
 sg13g2_dfrbpq_1 _636_ (.RESET_B(net284),
    .D(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_filter_q),
    .CLK(clknet_5_16__leaf_clk_i));
 sg13g2_dfrbpq_1 _637_ (.RESET_B(net284),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .CLK(clknet_5_17__leaf_clk_i));
 sg13g2_dfrbpq_1 _638_ (.RESET_B(net284),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .CLK(clknet_5_16__leaf_clk_i));
 sg13g2_dfrbpq_1 _639_ (.RESET_B(u_gpio_core_filter_rst_ni),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_2_),
    .CLK(clknet_5_17__leaf_clk_i));
 sg13g2_dfrbpq_1 _640_ (.RESET_B(net284),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_),
    .CLK(clknet_5_17__leaf_clk_i));
 sg13g2_dfrbpq_1 _641_ (.RESET_B(net283),
    .D(u_gpio_core_gen_input_filter_0__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .CLK(clknet_5_21__leaf_clk_i));
 sg13g2_dfrbpq_1 _642_ (.RESET_B(net283),
    .D(net308),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_gen_async_prim_flop_2sync_intq),
    .CLK(clknet_5_20__leaf_clk_i));
 sg13g2_dfrbpq_1 _643_ (.RESET_B(net283),
    .D(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_filter_q),
    .CLK(clknet_5_23__leaf_clk_i));
 sg13g2_dfrbpq_1 _644_ (.RESET_B(net283),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .CLK(clknet_5_21__leaf_clk_i));
 sg13g2_dfrbpq_1 _645_ (.RESET_B(net283),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .CLK(clknet_5_23__leaf_clk_i));
 sg13g2_dfrbpq_1 _646_ (.RESET_B(net283),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_),
    .CLK(clknet_5_21__leaf_clk_i));
 sg13g2_dfrbpq_1 _647_ (.RESET_B(net283),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
    .CLK(clknet_5_21__leaf_clk_i));
 sg13g2_dfrbpq_1 _648_ (.RESET_B(u_gpio_core_state_rst_ni),
    .D(hw2reg_9_),
    .Q(u_gpio_core_data_in_q_0_),
    .CLK(clknet_5_23__leaf_clk_i));
 sg13g2_dfrbpq_1 _649_ (.RESET_B(u_gpio_core_state_rst_ni),
    .D(hw2reg_10_),
    .Q(u_gpio_core_data_in_q_1_),
    .CLK(clknet_5_22__leaf_clk_i));
 sg13g2_dfrbpq_1 _650_ (.RESET_B(u_gpio_core_state_rst_ni),
    .D(hw2reg_11_),
    .Q(u_gpio_core_data_in_q_2_),
    .CLK(clknet_5_6__leaf_clk_i));
 sg13g2_dfrbpq_1 _651_ (.RESET_B(u_gpio_core_state_rst_ni),
    .D(hw2reg_12_),
    .Q(u_gpio_core_data_in_q_3_),
    .CLK(clknet_5_24__leaf_clk_i));
 sg13g2_dfrbpq_1 _652_ (.RESET_B(net90),
    .D(u_core_reset_sync_intq),
    .Q(core_rst_ni),
    .CLK(clknet_5_20__leaf_clk_i));
 sg13g2_dfrbpq_1 _653_ (.RESET_B(net90),
    .D(net85),
    .Q(u_core_reset_sync_intq),
    .CLK(clknet_5_20__leaf_clk_i));
 sg13g2_tiehi _653__25 (.L_HI(net85));
 sg13g2_tielo _658__2 (.L_LO(tl_o[2]));
 sg13g2_tielo _659__3 (.L_LO(tl_o[3]));
 sg13g2_tielo _660__4 (.L_LO(tl_o[4]));
 sg13g2_tielo _661__5 (.L_LO(tl_o[5]));
 sg13g2_tielo _662__6 (.L_LO(tl_o[6]));
 sg13g2_tielo _663__7 (.L_LO(tl_o[7]));
 sg13g2_tielo _664__8 (.L_LO(tl_o[8]));
 sg13g2_tielo _665__9 (.L_LO(tl_o[9]));
 sg13g2_tielo _666__10 (.L_LO(tl_o[10]));
 sg13g2_tielo _667__11 (.L_LO(tl_o[11]));
 sg13g2_tielo _668__12 (.L_LO(tl_o[12]));
 sg13g2_tielo _669__13 (.L_LO(tl_o[13]));
 sg13g2_tielo _670__14 (.L_LO(tl_o[14]));
 sg13g2_tielo _671__15 (.L_LO(tl_o[15]));
 sg13g2_tielo _704__16 (.L_LO(tl_o[48]));
 sg13g2_tielo _715__17 (.L_LO(tl_o[59]));
 sg13g2_tielo _716__18 (.L_LO(tl_o[60]));
 sg13g2_tielo _717__19 (.L_LO(tl_o[61]));
 sg13g2_tielo _719__20 (.L_LO(tl_o[63]));
 sg13g2_tielo _720__21 (.L_LO(tl_o[64]));
 sg13g2_buf_8 clkbuf_0_clk_i (.A(clk_i),
    .X(clknet_0_clk_i));
 sg13g2_buf_16 clkbuf_4_0_0_clk_i (.X(clknet_4_0_0_clk_i),
    .A(clknet_0_clk_i));
 sg13g2_buf_16 clkbuf_4_10_0_clk_i (.X(clknet_4_10_0_clk_i),
    .A(clknet_0_clk_i));
 sg13g2_buf_16 clkbuf_4_11_0_clk_i (.X(clknet_4_11_0_clk_i),
    .A(clknet_0_clk_i));
 sg13g2_buf_16 clkbuf_4_12_0_clk_i (.X(clknet_4_12_0_clk_i),
    .A(clknet_0_clk_i));
 sg13g2_buf_16 clkbuf_4_13_0_clk_i (.X(clknet_4_13_0_clk_i),
    .A(clknet_0_clk_i));
 sg13g2_buf_16 clkbuf_4_14_0_clk_i (.X(clknet_4_14_0_clk_i),
    .A(clknet_0_clk_i));
 sg13g2_buf_16 clkbuf_4_15_0_clk_i (.X(clknet_4_15_0_clk_i),
    .A(clknet_0_clk_i));
 sg13g2_buf_16 clkbuf_4_1_0_clk_i (.X(clknet_4_1_0_clk_i),
    .A(clknet_0_clk_i));
 sg13g2_buf_16 clkbuf_4_2_0_clk_i (.X(clknet_4_2_0_clk_i),
    .A(clknet_0_clk_i));
 sg13g2_buf_16 clkbuf_4_3_0_clk_i (.X(clknet_4_3_0_clk_i),
    .A(clknet_0_clk_i));
 sg13g2_buf_16 clkbuf_4_4_0_clk_i (.X(clknet_4_4_0_clk_i),
    .A(clknet_0_clk_i));
 sg13g2_buf_16 clkbuf_4_5_0_clk_i (.X(clknet_4_5_0_clk_i),
    .A(clknet_0_clk_i));
 sg13g2_buf_16 clkbuf_4_6_0_clk_i (.X(clknet_4_6_0_clk_i),
    .A(clknet_0_clk_i));
 sg13g2_buf_16 clkbuf_4_7_0_clk_i (.X(clknet_4_7_0_clk_i),
    .A(clknet_0_clk_i));
 sg13g2_buf_16 clkbuf_4_8_0_clk_i (.X(clknet_4_8_0_clk_i),
    .A(clknet_0_clk_i));
 sg13g2_buf_16 clkbuf_4_9_0_clk_i (.X(clknet_4_9_0_clk_i),
    .A(clknet_0_clk_i));
 sg13g2_buf_8 clkbuf_5_0__f_clk_i (.A(clknet_4_0_0_clk_i),
    .X(clknet_5_0__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_10__f_clk_i (.A(clknet_4_5_0_clk_i),
    .X(clknet_5_10__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_11__f_clk_i (.A(clknet_4_5_0_clk_i),
    .X(clknet_5_11__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_12__f_clk_i (.A(clknet_4_6_0_clk_i),
    .X(clknet_5_12__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_13__f_clk_i (.A(clknet_4_6_0_clk_i),
    .X(clknet_5_13__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_14__f_clk_i (.A(clknet_4_7_0_clk_i),
    .X(clknet_5_14__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_15__f_clk_i (.A(clknet_4_7_0_clk_i),
    .X(clknet_5_15__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_16__f_clk_i (.A(clknet_4_8_0_clk_i),
    .X(clknet_5_16__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_17__f_clk_i (.A(clknet_4_8_0_clk_i),
    .X(clknet_5_17__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_18__f_clk_i (.A(clknet_4_9_0_clk_i),
    .X(clknet_5_18__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_19__f_clk_i (.A(clknet_4_9_0_clk_i),
    .X(clknet_5_19__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_1__f_clk_i (.A(clknet_4_0_0_clk_i),
    .X(clknet_5_1__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_20__f_clk_i (.A(clknet_4_10_0_clk_i),
    .X(clknet_5_20__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_21__f_clk_i (.A(clknet_4_10_0_clk_i),
    .X(clknet_5_21__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_22__f_clk_i (.A(clknet_4_11_0_clk_i),
    .X(clknet_5_22__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_23__f_clk_i (.A(clknet_4_11_0_clk_i),
    .X(clknet_5_23__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_24__f_clk_i (.A(clknet_4_12_0_clk_i),
    .X(clknet_5_24__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_25__f_clk_i (.A(clknet_4_12_0_clk_i),
    .X(clknet_5_25__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_26__f_clk_i (.A(clknet_4_13_0_clk_i),
    .X(clknet_5_26__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_27__f_clk_i (.A(clknet_4_13_0_clk_i),
    .X(clknet_5_27__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_28__f_clk_i (.A(clknet_4_14_0_clk_i),
    .X(clknet_5_28__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_29__f_clk_i (.A(clknet_4_14_0_clk_i),
    .X(clknet_5_29__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_2__f_clk_i (.A(clknet_4_1_0_clk_i),
    .X(clknet_5_2__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_30__f_clk_i (.A(clknet_4_15_0_clk_i),
    .X(clknet_5_30__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_31__f_clk_i (.A(clknet_4_15_0_clk_i),
    .X(clknet_5_31__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_3__f_clk_i (.A(clknet_4_1_0_clk_i),
    .X(clknet_5_3__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_4__f_clk_i (.A(clknet_4_2_0_clk_i),
    .X(clknet_5_4__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_5__f_clk_i (.A(clknet_4_2_0_clk_i),
    .X(clknet_5_5__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_6__f_clk_i (.A(clknet_4_3_0_clk_i),
    .X(clknet_5_6__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_7__f_clk_i (.A(clknet_4_3_0_clk_i),
    .X(clknet_5_7__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_8__f_clk_i (.A(clknet_4_4_0_clk_i),
    .X(clknet_5_8__leaf_clk_i));
 sg13g2_buf_8 clkbuf_5_9__f_clk_i (.A(clknet_4_4_0_clk_i),
    .X(clknet_5_9__leaf_clk_i));
 sg13g2_inv_1 clkload0 (.A(clknet_5_3__leaf_clk_i));
 sg13g2_inv_1 clkload1 (.A(clknet_5_7__leaf_clk_i));
 sg13g2_inv_1 clkload2 (.A(clknet_5_11__leaf_clk_i));
 sg13g2_inv_1 clkload3 (.A(clknet_5_15__leaf_clk_i));
 sg13g2_inv_1 clkload4 (.A(clknet_5_19__leaf_clk_i));
 sg13g2_inv_1 clkload5 (.A(clknet_5_23__leaf_clk_i));
 sg13g2_inv_1 clkload6 (.A(clknet_5_27__leaf_clk_i));
 sg13g2_inv_1 clkload7 (.A(clknet_5_29__leaf_clk_i));
 sg13g2_inv_1 clkload8 (.A(clknet_5_31__leaf_clk_i));
 sg13g2_dlygate4sd3_1 hold241 (.A(cio_gpio_i[1]),
    .X(net301));
 sg13g2_dlygate4sd3_1 hold242 (.A(net87),
    .X(net302));
 sg13g2_dlygate4sd3_1 hold243 (.A(cio_gpio_i[2]),
    .X(net303));
 sg13g2_dlygate4sd3_1 hold244 (.A(net88),
    .X(net304));
 sg13g2_dlygate4sd3_1 hold245 (.A(cio_gpio_i[3]),
    .X(net305));
 sg13g2_dlygate4sd3_1 hold246 (.A(net89),
    .X(net306));
 sg13g2_dlygate4sd3_1 hold247 (.A(cio_gpio_i[0]),
    .X(net307));
 sg13g2_dlygate4sd3_1 hold248 (.A(net86),
    .X(net308));
 sg13g2_dlygate4sd3_1 hold249 (.A(tl_i[0]),
    .X(net309));
 sg13g2_dlygate4sd3_1 hold250 (.A(net91),
    .X(net310));
 sg13g2_dlygate4sd3_1 hold251 (.A(_067_),
    .X(net311));
 sg13g2_dlygate4sd3_1 hold252 (.A(tl_i[96]),
    .X(net312));
 sg13g2_dlygate4sd3_1 hold253 (.A(tl_i[98]),
    .X(net313));
 sg13g2_dlygate4sd3_1 hold254 (.A(tl_i[100]),
    .X(net314));
 sg13g2_dlygate4sd3_1 hold255 (.A(tl_i[94]),
    .X(net315));
 sg13g2_dlygate4sd3_1 hold256 (.A(tl_i[30]),
    .X(net316));
 sg13g2_dlygate4sd3_1 hold257 (.A(tl_i[29]),
    .X(net317));
 sg13g2_dlygate4sd3_1 hold258 (.A(_193_),
    .X(net318));
 sg13g2_dlygate4sd3_1 hold259 (.A(_055_),
    .X(net319));
 sg13g2_dlygate4sd3_1 hold260 (.A(tl_i[99]),
    .X(net320));
 sg13g2_dlygate4sd3_1 hold261 (.A(tl_i[95]),
    .X(net321));
 sg13g2_dlygate4sd3_1 hold262 (.A(tl_i[92]),
    .X(net322));
 sg13g2_dlygate4sd3_1 hold263 (.A(tl_i[24]),
    .X(net323));
 sg13g2_dlygate4sd3_1 hold264 (.A(tl_i[25]),
    .X(net324));
 sg13g2_dlygate4sd3_1 hold265 (.A(tl_i[97]),
    .X(net325));
 sg13g2_dlygate4sd3_1 hold266 (.A(_017_),
    .X(net326));
 sg13g2_dlygate4sd3_1 hold267 (.A(tl_i[28]),
    .X(net327));
 sg13g2_dlygate4sd3_1 hold268 (.A(_194_),
    .X(net328));
 sg13g2_dlygate4sd3_1 hold269 (.A(_056_),
    .X(net329));
 sg13g2_dlygate4sd3_1 hold270 (.A(tl_i[93]),
    .X(net330));
 sg13g2_dlygate4sd3_1 hold271 (.A(tl_i[107]),
    .X(net331));
 sg13g2_dlygate4sd3_1 hold272 (.A(_120_),
    .X(net332));
 sg13g2_dlygate4sd3_1 hold273 (.A(tl_i[42]),
    .X(net333));
 sg13g2_dlygate4sd3_1 hold274 (.A(tl_i[43]),
    .X(net334));
 sg13g2_dlygate4sd3_1 hold275 (.A(tl_i[101]),
    .X(net335));
 sg13g2_dlygate4sd3_1 hold276 (.A(_070_),
    .X(net336));
 sg13g2_dlygate4sd3_1 hold277 (.A(tl_i[26]),
    .X(net337));
 sg13g2_dlygate4sd3_1 hold278 (.A(tl_i[33]),
    .X(net338));
 sg13g2_dlygate4sd3_1 hold279 (.A(tl_i[32]),
    .X(net339));
 sg13g2_dlygate4sd3_1 hold280 (.A(tl_i[41]),
    .X(net340));
 sg13g2_dlygate4sd3_1 hold281 (.A(tl_i[35]),
    .X(net341));
 sg13g2_dlygate4sd3_1 hold282 (.A(tl_i[37]),
    .X(net342));
 sg13g2_dlygate4sd3_1 hold283 (.A(tl_i[31]),
    .X(net343));
 sg13g2_dlygate4sd3_1 hold284 (.A(_250_),
    .X(net344));
 sg13g2_dlygate4sd3_1 hold285 (.A(_065_),
    .X(net345));
 sg13g2_dlygate4sd3_1 hold286 (.A(tl_i[36]),
    .X(net346));
 sg13g2_dlygate4sd3_1 hold287 (.A(tl_i[39]),
    .X(net347));
 sg13g2_dlygate4sd3_1 hold288 (.A(tl_i[40]),
    .X(net348));
 sg13g2_dlygate4sd3_1 hold289 (.A(tl_i[38]),
    .X(net349));
 sg13g2_dlygate4sd3_1 hold290 (.A(tl_i[27]),
    .X(net350));
 sg13g2_dlygate4sd3_1 hold291 (.A(_249_),
    .X(net351));
 sg13g2_dlygate4sd3_1 hold292 (.A(_064_),
    .X(net352));
 sg13g2_dlygate4sd3_1 hold293 (.A(tl_i[60]),
    .X(net353));
 sg13g2_dlygate4sd3_1 hold294 (.A(_103_),
    .X(net354));
 sg13g2_dlygate4sd3_1 hold295 (.A(tl_i[34]),
    .X(net355));
 sg13g2_dlygate4sd3_1 hold296 (.A(rst_ni),
    .X(net356));
 sg13g2_dlygate4sd3_1 hold297 (.A(tl_i[61]),
    .X(net357));
 sg13g2_dlygate4sd3_1 hold298 (.A(_121_),
    .X(net358));
 sg13g2_dlygate4sd3_1 hold299 (.A(_066_),
    .X(net359));
 sg13g2_dlygate4sd3_1 hold300 (.A(tl_i[62]),
    .X(net360));
 sg13g2_dlygate4sd3_1 hold301 (.A(_154_),
    .X(net361));
 sg13g2_dlygate4sd3_1 hold302 (.A(tl_i[108]),
    .X(net362));
 sg13g2_dlygate4sd3_1 hold303 (.A(_137_),
    .X(net363));
 sg13g2_dlygate4sd3_1 hold304 (.A(_044_),
    .X(net364));
 sg13g2_dlygate4sd3_1 hold305 (.A(tl_i[63]),
    .X(net365));
 sg13g2_dlygate4sd3_1 hold306 (.A(_124_),
    .X(net366));
 sg13g2_dlygate4sd3_1 hold307 (.A(tl_i[106]),
    .X(net367));
 sg13g2_buf_1 input26 (.A(net307),
    .X(net86));
 sg13g2_buf_1 input27 (.A(net301),
    .X(net87));
 sg13g2_buf_1 input28 (.A(net303),
    .X(net88));
 sg13g2_buf_1 input29 (.A(net305),
    .X(net89));
 sg13g2_buf_1 input30 (.A(net356),
    .X(net90));
 sg13g2_buf_1 input31 (.A(net309),
    .X(net91));
 sg13g2_buf_1 input32 (.A(net314),
    .X(net92));
 sg13g2_buf_1 input33 (.A(net335),
    .X(net93));
 sg13g2_buf_1 input34 (.A(tl_i[105]),
    .X(net94));
 sg13g2_buf_1 input35 (.A(net367),
    .X(net95));
 sg13g2_buf_1 input36 (.A(net331),
    .X(net96));
 sg13g2_buf_1 input37 (.A(net362),
    .X(net97));
 sg13g2_buf_1 input38 (.A(net323),
    .X(net98));
 sg13g2_buf_1 input39 (.A(net324),
    .X(net99));
 sg13g2_buf_1 input40 (.A(net337),
    .X(net100));
 sg13g2_buf_1 input41 (.A(net350),
    .X(net101));
 sg13g2_buf_1 input42 (.A(net327),
    .X(net102));
 sg13g2_buf_1 input43 (.A(net317),
    .X(net103));
 sg13g2_buf_1 input44 (.A(net316),
    .X(net104));
 sg13g2_buf_1 input45 (.A(net343),
    .X(net105));
 sg13g2_buf_1 input46 (.A(net339),
    .X(net106));
 sg13g2_buf_1 input47 (.A(net338),
    .X(net107));
 sg13g2_buf_1 input48 (.A(net355),
    .X(net108));
 sg13g2_buf_1 input49 (.A(net341),
    .X(net109));
 sg13g2_buf_1 input50 (.A(net346),
    .X(net110));
 sg13g2_buf_1 input51 (.A(net342),
    .X(net111));
 sg13g2_buf_1 input52 (.A(net349),
    .X(net112));
 sg13g2_buf_1 input53 (.A(net347),
    .X(net113));
 sg13g2_buf_1 input54 (.A(net348),
    .X(net114));
 sg13g2_buf_1 input55 (.A(net340),
    .X(net115));
 sg13g2_buf_1 input56 (.A(net333),
    .X(net116));
 sg13g2_buf_1 input57 (.A(net334),
    .X(net117));
 sg13g2_buf_1 input58 (.A(tl_i[56]),
    .X(net118));
 sg13g2_buf_1 input59 (.A(tl_i[57]),
    .X(net119));
 sg13g2_buf_1 input60 (.A(tl_i[58]),
    .X(net120));
 sg13g2_buf_1 input61 (.A(net353),
    .X(net121));
 sg13g2_buf_1 input62 (.A(net357),
    .X(net122));
 sg13g2_buf_1 input63 (.A(net360),
    .X(net123));
 sg13g2_buf_1 input64 (.A(net365),
    .X(net124));
 sg13g2_buf_1 input65 (.A(net322),
    .X(net125));
 sg13g2_buf_1 input66 (.A(net330),
    .X(net126));
 sg13g2_buf_1 input67 (.A(net315),
    .X(net127));
 sg13g2_buf_1 input68 (.A(net321),
    .X(net128));
 sg13g2_buf_1 input69 (.A(net312),
    .X(net129));
 sg13g2_buf_1 input70 (.A(net325),
    .X(net130));
 sg13g2_buf_1 input71 (.A(net313),
    .X(net131));
 sg13g2_buf_1 input72 (.A(net320),
    .X(net132));
 sg13g2_buf_1 output100 (.A(net160),
    .X(tl_o[29]));
 sg13g2_buf_1 output101 (.A(net161),
    .X(tl_o[30]));
 sg13g2_buf_1 output102 (.A(net162),
    .X(tl_o[31]));
 sg13g2_buf_1 output103 (.A(net163),
    .X(tl_o[32]));
 sg13g2_buf_1 output104 (.A(net164),
    .X(tl_o[33]));
 sg13g2_buf_1 output105 (.A(net165),
    .X(tl_o[34]));
 sg13g2_buf_1 output106 (.A(net166),
    .X(tl_o[35]));
 sg13g2_buf_1 output107 (.A(net167),
    .X(tl_o[36]));
 sg13g2_buf_1 output108 (.A(net168),
    .X(tl_o[37]));
 sg13g2_buf_1 output109 (.A(net169),
    .X(tl_o[38]));
 sg13g2_buf_1 output110 (.A(net170),
    .X(tl_o[39]));
 sg13g2_buf_1 output111 (.A(net171),
    .X(tl_o[40]));
 sg13g2_buf_1 output112 (.A(net172),
    .X(tl_o[41]));
 sg13g2_buf_1 output113 (.A(net173),
    .X(tl_o[42]));
 sg13g2_buf_1 output114 (.A(net174),
    .X(tl_o[43]));
 sg13g2_buf_1 output115 (.A(net175),
    .X(tl_o[44]));
 sg13g2_buf_1 output116 (.A(net176),
    .X(tl_o[45]));
 sg13g2_buf_1 output117 (.A(net177),
    .X(tl_o[46]));
 sg13g2_buf_1 output118 (.A(net178),
    .X(tl_o[47]));
 sg13g2_buf_1 output119 (.A(net179),
    .X(tl_o[49]));
 sg13g2_buf_1 output120 (.A(net180),
    .X(tl_o[50]));
 sg13g2_buf_1 output121 (.A(net181),
    .X(tl_o[51]));
 sg13g2_buf_1 output122 (.A(net182),
    .X(tl_o[52]));
 sg13g2_buf_1 output123 (.A(net183),
    .X(tl_o[53]));
 sg13g2_buf_1 output124 (.A(net184),
    .X(tl_o[54]));
 sg13g2_buf_1 output125 (.A(net185),
    .X(tl_o[55]));
 sg13g2_buf_1 output126 (.A(net186),
    .X(tl_o[56]));
 sg13g2_buf_1 output127 (.A(net187),
    .X(tl_o[57]));
 sg13g2_buf_1 output128 (.A(net188),
    .X(tl_o[58]));
 sg13g2_buf_1 output129 (.A(net189),
    .X(tl_o[62]));
 sg13g2_buf_1 output130 (.A(net190),
    .X(tl_o[65]));
 sg13g2_buf_1 output73 (.A(net133),
    .X(cio_gpio_en_o[0]));
 sg13g2_buf_1 output74 (.A(net134),
    .X(cio_gpio_en_o[1]));
 sg13g2_buf_1 output75 (.A(net135),
    .X(cio_gpio_en_o[2]));
 sg13g2_buf_1 output76 (.A(net136),
    .X(cio_gpio_en_o[3]));
 sg13g2_buf_1 output77 (.A(net137),
    .X(cio_gpio_o[0]));
 sg13g2_buf_1 output78 (.A(net138),
    .X(cio_gpio_o[1]));
 sg13g2_buf_1 output79 (.A(net139),
    .X(cio_gpio_o[2]));
 sg13g2_buf_1 output80 (.A(net140),
    .X(cio_gpio_o[3]));
 sg13g2_buf_1 output81 (.A(net141),
    .X(intr_gpio_o[0]));
 sg13g2_buf_1 output82 (.A(net142),
    .X(intr_gpio_o[1]));
 sg13g2_buf_1 output83 (.A(net143),
    .X(intr_gpio_o[2]));
 sg13g2_buf_1 output84 (.A(net144),
    .X(intr_gpio_o[3]));
 sg13g2_buf_1 output85 (.A(net145),
    .X(tl_o[0]));
 sg13g2_buf_1 output86 (.A(net146),
    .X(tl_o[16]));
 sg13g2_buf_1 output87 (.A(net147),
    .X(tl_o[17]));
 sg13g2_buf_1 output88 (.A(net148),
    .X(tl_o[18]));
 sg13g2_buf_1 output89 (.A(net149),
    .X(tl_o[19]));
 sg13g2_buf_1 output90 (.A(net150),
    .X(tl_o[1]));
 sg13g2_buf_1 output91 (.A(net151),
    .X(tl_o[20]));
 sg13g2_buf_1 output92 (.A(net152),
    .X(tl_o[21]));
 sg13g2_buf_1 output93 (.A(net153),
    .X(tl_o[22]));
 sg13g2_buf_1 output94 (.A(net154),
    .X(tl_o[23]));
 sg13g2_buf_1 output95 (.A(net155),
    .X(tl_o[24]));
 sg13g2_buf_1 output96 (.A(net156),
    .X(tl_o[25]));
 sg13g2_buf_1 output97 (.A(net157),
    .X(tl_o[26]));
 sg13g2_buf_1 output98 (.A(net158),
    .X(tl_o[27]));
 sg13g2_buf_1 output99 (.A(net159),
    .X(tl_o[28]));
 sg13g2_buf_1 place209 (.A(net271),
    .X(net269));
 sg13g2_buf_1 place210 (.A(net271),
    .X(net270));
 sg13g2_buf_1 place211 (.A(_125_),
    .X(net271));
 sg13g2_buf_1 place212 (.A(_112_),
    .X(net272));
 sg13g2_buf_1 place213 (.A(_112_),
    .X(net273));
 sg13g2_buf_1 place214 (.A(net275),
    .X(net274));
 sg13g2_buf_1 place215 (.A(_190_),
    .X(net275));
 sg13g2_buf_1 place216 (.A(_137_),
    .X(net276));
 sg13g2_buf_1 place217 (.A(net278),
    .X(net277));
 sg13g2_buf_1 place218 (.A(_117_),
    .X(net278));
 sg13g2_buf_1 place219 (.A(_099_),
    .X(net279));
 sg13g2_buf_1 place220 (.A(net282),
    .X(net280));
 sg13g2_buf_1 place221 (.A(net282),
    .X(net281));
 sg13g2_buf_1 place222 (.A(_099_),
    .X(net282));
 sg13g2_buf_1 place223 (.A(u_gpio_core_filter_rst_ni),
    .X(net283));
 sg13g2_buf_1 place224 (.A(net286),
    .X(net284));
 sg13g2_buf_1 place225 (.A(net286),
    .X(net285));
 sg13g2_buf_1 place226 (.A(u_gpio_core_filter_rst_ni),
    .X(net286));
 sg13g2_buf_1 place227 (.A(u_gpio_core_state_rst_ni),
    .X(net287));
 sg13g2_buf_1 place228 (.A(net289),
    .X(net288));
 sg13g2_buf_1 place229 (.A(net290),
    .X(net289));
 sg13g2_buf_1 place230 (.A(reg_rst_ni),
    .X(net290));
 sg13g2_buf_1 place231 (.A(net297),
    .X(net291));
 sg13g2_buf_1 place232 (.A(net297),
    .X(net292));
 sg13g2_buf_1 place233 (.A(net297),
    .X(net293));
 sg13g2_buf_1 place234 (.A(net296),
    .X(net294));
 sg13g2_buf_1 place235 (.A(net296),
    .X(net295));
 sg13g2_buf_1 place236 (.A(net297),
    .X(net296));
 sg13g2_buf_1 place237 (.A(reg_rst_ni),
    .X(net297));
 sg13g2_buf_1 place238 (.A(_152_),
    .X(net298));
 sg13g2_buf_1 place239 (.A(_104_),
    .X(net299));
 sg13g2_buf_1 place240 (.A(net123),
    .X(net300));
endmodule
