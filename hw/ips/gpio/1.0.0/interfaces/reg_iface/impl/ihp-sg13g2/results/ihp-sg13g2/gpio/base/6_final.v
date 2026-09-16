module gpio (clk_i,
    rst_ni,
    cio_gpio_en_o,
    cio_gpio_i,
    cio_gpio_o,
    intr_gpio_o,
    reg_req_i,
    reg_rsp_o);
 input clk_i;
 input rst_ni;
 output [3:0] cio_gpio_en_o;
 input [3:0] cio_gpio_i;
 output [3:0] cio_gpio_o;
 output [3:0] intr_gpio_o;
 input [41:0] reg_req_i;
 output [33:0] reg_rsp_o;

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
 wire clknet_4_10_0_clk_i;
 wire _048_;
 wire _049_;
 wire _050_;
 wire _051_;
 wire _052_;
 wire clknet_4_9_0_clk_i;
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
 wire net74;
 wire net75;
 wire net76;
 wire net77;
 wire net40;
 wire net41;
 wire net42;
 wire net43;
 wire net78;
 wire net79;
 wire net80;
 wire net81;
 wire core_rst_ni;
 wire hw2reg_10_;
 wire hw2reg_11_;
 wire hw2reg_12_;
 wire hw2reg_9_;
 wire net82;
 wire net83;
 wire net84;
 wire net85;
 wire net;
 wire net37;
 wire net38;
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
 wire net44;
 wire net45;
 wire net46;
 wire net47;
 wire net48;
 wire net49;
 wire net50;
 wire net51;
 wire net52;
 wire net53;
 wire net54;
 wire net55;
 wire net56;
 wire net57;
 wire net58;
 wire net59;
 wire net60;
 wire net61;
 wire net62;
 wire net63;
 wire net64;
 wire net65;
 wire net66;
 wire net67;
 wire net68;
 wire net69;
 wire net70;
 wire net71;
 wire net72;
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
 wire reg_rst_ni;
 wire net73;
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
 wire net36;
 wire net162;
 wire net161;
 wire clknet_4_2_0_clk_i;
 wire clknet_4_11_0_clk_i;
 wire net165;
 wire net163;
 wire net170;
 wire net164;
 wire net167;
 wire net166;
 wire net173;
 wire net172;
 wire net171;
 wire clknet_4_1_0_clk_i;
 wire clknet_4_8_0_clk_i;
 wire clknet_4_6_0_clk_i;
 wire clknet_4_5_0_clk_i;
 wire clknet_4_7_0_clk_i;
 wire clknet_0_clk_i;
 wire clknet_4_0_0_clk_i;
 wire net158;
 wire net157;
 wire net156;
 wire net155;
 wire clknet_4_4_0_clk_i;
 wire net159;
 wire net160;
 wire clknet_4_3_0_clk_i;
 wire net168;
 wire net169;
 wire clknet_4_12_0_clk_i;
 wire clknet_4_13_0_clk_i;
 wire clknet_4_14_0_clk_i;
 wire clknet_4_15_0_clk_i;
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
 wire net207;
 wire net208;
 wire net209;
 wire net210;

 sg13g2_mux2_1 _157_ (.A0(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .A1(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .S(reg2hw_17_),
    .X(hw2reg_10_));
 sg13g2_mux2_1 _158_ (.A0(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .A1(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .S(reg2hw_16_),
    .X(hw2reg_9_));
 sg13g2_mux2_1 _159_ (.A0(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .A1(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .S(reg2hw_18_),
    .X(hw2reg_11_));
 sg13g2_inv_1 _160_ (.Y(_032_),
    .A(u_gpio_core_data_in_q_2_));
 sg13g2_a21oi_1 _161_ (.A1(_032_),
    .A2(reg2hw_2_),
    .Y(_033_),
    .B1(reg2hw_10_));
 sg13g2_inv_1 _162_ (.Y(_034_),
    .A(reg2hw_14_));
 sg13g2_a21oi_1 _163_ (.A1(u_gpio_core_data_in_q_2_),
    .A2(reg2hw_6_),
    .Y(_035_),
    .B1(hw2reg_11_));
 sg13g2_a22oi_1 _164_ (.Y(net84),
    .B1(_034_),
    .B2(_035_),
    .A2(_033_),
    .A1(hw2reg_11_));
 sg13g2_inv_1 _165_ (.Y(_036_),
    .A(u_gpio_core_data_in_q_1_));
 sg13g2_a21oi_1 _166_ (.A1(_036_),
    .A2(reg2hw_1_),
    .Y(_037_),
    .B1(reg2hw_9_));
 sg13g2_inv_1 _167_ (.Y(_038_),
    .A(reg2hw_13_));
 sg13g2_a21oi_1 _168_ (.A1(u_gpio_core_data_in_q_1_),
    .A2(reg2hw_5_),
    .Y(_039_),
    .B1(hw2reg_10_));
 sg13g2_a22oi_1 _169_ (.Y(net83),
    .B1(_038_),
    .B2(_039_),
    .A2(_037_),
    .A1(hw2reg_10_));
 sg13g2_inv_1 _170_ (.Y(_040_),
    .A(u_gpio_core_data_in_q_0_));
 sg13g2_a21oi_1 _171_ (.A1(_040_),
    .A2(reg2hw_0_),
    .Y(_041_),
    .B1(reg2hw_8_));
 sg13g2_inv_1 _172_ (.Y(_042_),
    .A(reg2hw_12_));
 sg13g2_a21oi_1 _173_ (.A1(u_gpio_core_data_in_q_0_),
    .A2(reg2hw_4_),
    .Y(_043_),
    .B1(hw2reg_9_));
 sg13g2_a22oi_1 _174_ (.Y(net82),
    .B1(_042_),
    .B2(_043_),
    .A2(_041_),
    .A1(hw2reg_9_));
 sg13g2_nor2_1 _175_ (.A(net61),
    .B(net62),
    .Y(_044_));
 sg13g2_inv_1 _176_ (.Y(_045_),
    .A(net63));
 sg13g2_nand3_1 _177_ (.B(_045_),
    .C(net64),
    .A(_044_),
    .Y(_046_));
 sg13g2_inv_2 _179_ (.Y(_048_),
    .A(_046_));
 sg13g2_nand2b_2 _180_ (.Y(_049_),
    .B(_044_),
    .A_N(net64));
 sg13g2_nor2_1 _181_ (.A(_045_),
    .B(_049_),
    .Y(_050_));
 sg13g2_a22oi_1 _182_ (.Y(_051_),
    .B1(net76),
    .B2(net163),
    .A2(reg2hw_6_),
    .A1(_048_));
 sg13g2_nand2_1 _183_ (.Y(_052_),
    .A(_046_),
    .B(_049_));
 sg13g2_nand2_1 _185_ (.Y(net106),
    .A(_051_),
    .B(net162));
 sg13g2_inv_1 _186_ (.Y(_054_),
    .A(reg2hw_5_));
 sg13g2_inv_1 _187_ (.Y(net100),
    .A(_052_));
 sg13g2_a21oi_1 _188_ (.A1(net163),
    .A2(net75),
    .Y(_055_),
    .B1(net160));
 sg13g2_o21ai_1 _189_ (.B1(_055_),
    .Y(net105),
    .A1(_054_),
    .A2(net164));
 sg13g2_inv_1 _190_ (.Y(_056_),
    .A(reg2hw_4_));
 sg13g2_a21oi_1 _191_ (.A1(net163),
    .A2(net74),
    .Y(_057_),
    .B1(net160));
 sg13g2_o21ai_1 _192_ (.B1(_057_),
    .Y(net104),
    .A1(_056_),
    .A2(net164));
 sg13g2_inv_1 _193_ (.Y(_058_),
    .A(reg2hw_18_));
 sg13g2_o21ai_1 _194_ (.B1(net161),
    .Y(net97),
    .A1(_058_),
    .A2(net165));
 sg13g2_inv_1 _195_ (.Y(_059_),
    .A(reg2hw_17_));
 sg13g2_o21ai_1 _196_ (.B1(net161),
    .Y(net95),
    .A1(_059_),
    .A2(net164));
 sg13g2_inv_1 _197_ (.Y(_060_),
    .A(reg2hw_16_));
 sg13g2_o21ai_1 _198_ (.B1(net161),
    .Y(net94),
    .A1(_060_),
    .A2(net164));
 sg13g2_inv_1 _199_ (.Y(_061_),
    .A(reg2hw_15_));
 sg13g2_o21ai_1 _200_ (.B1(_052_),
    .Y(net93),
    .A1(_061_),
    .A2(net165));
 sg13g2_o21ai_1 _201_ (.B1(_052_),
    .Y(net92),
    .A1(_034_),
    .A2(net165));
 sg13g2_o21ai_1 _202_ (.B1(net161),
    .Y(net91),
    .A1(_038_),
    .A2(net164));
 sg13g2_o21ai_1 _203_ (.B1(net162),
    .Y(net90),
    .A1(_042_),
    .A2(net164));
 sg13g2_inv_1 _204_ (.Y(_062_),
    .A(reg2hw_11_));
 sg13g2_o21ai_1 _205_ (.B1(_052_),
    .Y(net89),
    .A1(_062_),
    .A2(net165));
 sg13g2_inv_1 _206_ (.Y(_063_),
    .A(reg2hw_10_));
 sg13g2_o21ai_1 _207_ (.B1(net161),
    .Y(net88),
    .A1(_063_),
    .A2(net165));
 sg13g2_inv_1 _208_ (.Y(_064_),
    .A(reg2hw_9_));
 sg13g2_o21ai_1 _209_ (.B1(net161),
    .Y(net87),
    .A1(_064_),
    .A2(net164));
 sg13g2_inv_1 _210_ (.Y(_065_),
    .A(reg2hw_8_));
 sg13g2_o21ai_1 _211_ (.B1(net162),
    .Y(net86),
    .A1(_065_),
    .A2(net164));
 sg13g2_nor2_2 _212_ (.A(net63),
    .B(_049_),
    .Y(_066_));
 sg13g2_a22oi_1 _213_ (.Y(_067_),
    .B1(u_gpio_reg_u_reg_core_data_in_qs_2_),
    .B2(_066_),
    .A2(reg2hw_2_),
    .A1(_048_));
 sg13g2_nand2_1 _214_ (.Y(_068_),
    .A(net163),
    .B(net80));
 sg13g2_nand3_1 _215_ (.B(net162),
    .C(_068_),
    .A(_067_),
    .Y(net102));
 sg13g2_a22oi_1 _216_ (.Y(_069_),
    .B1(u_gpio_reg_u_reg_core_data_in_qs_1_),
    .B2(_066_),
    .A2(reg2hw_1_),
    .A1(_048_));
 sg13g2_nand2_1 _217_ (.Y(_070_),
    .A(net163),
    .B(net79));
 sg13g2_nand3_1 _218_ (.B(net162),
    .C(_070_),
    .A(_069_),
    .Y(net101));
 sg13g2_a22oi_1 _219_ (.Y(_071_),
    .B1(u_gpio_reg_u_reg_core_data_in_qs_0_),
    .B2(_066_),
    .A2(reg2hw_0_),
    .A1(_048_));
 sg13g2_nand2_1 _220_ (.Y(_072_),
    .A(net163),
    .B(net78));
 sg13g2_nand3_1 _221_ (.B(net162),
    .C(_072_),
    .A(_071_),
    .Y(net99));
 sg13g2_nand3_1 _222_ (.B(net66),
    .C(net65),
    .A(_048_),
    .Y(_073_));
 sg13g2_a21oi_1 _223_ (.A1(net55),
    .A2(net60),
    .Y(_074_),
    .B1(_073_));
 sg13g2_nor2b_1 _224_ (.A(net44),
    .B_N(net65),
    .Y(_075_));
 sg13g2_o21ai_1 _225_ (.B1(net66),
    .Y(_076_),
    .A1(_075_),
    .A2(net100));
 sg13g2_nor2b_1 _226_ (.A(net208),
    .B_N(_076_),
    .Y(_077_));
 sg13g2_inv_1 _227_ (.Y(net96),
    .A(_077_));
 sg13g2_nor2_2 _228_ (.A(_073_),
    .B(net96),
    .Y(_078_));
 sg13g2_mux2_1 _230_ (.A0(reg2hw_2_),
    .A1(net69),
    .S(_078_),
    .X(_000_));
 sg13g2_mux2_1 _231_ (.A0(reg2hw_1_),
    .A1(net68),
    .S(net156),
    .X(_001_));
 sg13g2_mux2_1 _232_ (.A0(reg2hw_0_),
    .A1(net67),
    .S(net156),
    .X(_002_));
 sg13g2_nand2_1 _233_ (.Y(_080_),
    .A(net157),
    .B(net53));
 sg13g2_o21ai_1 _234_ (.B1(_080_),
    .Y(_003_),
    .A1(_034_),
    .A2(net157));
 sg13g2_nand2_1 _235_ (.Y(_081_),
    .A(net155),
    .B(net52));
 sg13g2_o21ai_1 _236_ (.B1(_081_),
    .Y(_004_),
    .A1(_038_),
    .A2(net155));
 sg13g2_nand2_1 _237_ (.Y(_082_),
    .A(_078_),
    .B(net51));
 sg13g2_o21ai_1 _238_ (.B1(net201),
    .Y(_005_),
    .A1(_042_),
    .A2(_078_));
 sg13g2_nand2_1 _239_ (.Y(_083_),
    .A(net158),
    .B(net49));
 sg13g2_o21ai_1 _240_ (.B1(_083_),
    .Y(_006_),
    .A1(_063_),
    .A2(net158));
 sg13g2_nand2_1 _241_ (.Y(_084_),
    .A(net155),
    .B(net48));
 sg13g2_o21ai_1 _242_ (.B1(_084_),
    .Y(_007_),
    .A1(_064_),
    .A2(net155));
 sg13g2_nand2_1 _243_ (.Y(_085_),
    .A(_078_),
    .B(net47));
 sg13g2_o21ai_1 _244_ (.B1(net196),
    .Y(_008_),
    .A1(_065_),
    .A2(_078_));
 sg13g2_nand2_1 _245_ (.Y(_086_),
    .A(net158),
    .B(net58));
 sg13g2_o21ai_1 _246_ (.B1(_086_),
    .Y(_009_),
    .A1(_058_),
    .A2(net158));
 sg13g2_nand2_1 _247_ (.Y(_087_),
    .A(net155),
    .B(net57));
 sg13g2_o21ai_1 _248_ (.B1(_087_),
    .Y(_010_),
    .A1(_059_),
    .A2(net155));
 sg13g2_nand2_1 _249_ (.Y(_088_),
    .A(net155),
    .B(net56));
 sg13g2_o21ai_1 _250_ (.B1(_088_),
    .Y(_011_),
    .A1(_060_),
    .A2(net155));
 sg13g2_mux2_1 _251_ (.A0(reg2hw_6_),
    .A1(net45),
    .S(_078_),
    .X(_012_));
 sg13g2_nand2_1 _252_ (.Y(_089_),
    .A(net156),
    .B(net72));
 sg13g2_o21ai_1 _253_ (.B1(_089_),
    .Y(_013_),
    .A1(_054_),
    .A2(net156));
 sg13g2_nand2_1 _254_ (.Y(_090_),
    .A(net156),
    .B(net71));
 sg13g2_o21ai_1 _255_ (.B1(_090_),
    .Y(_014_),
    .A1(_056_),
    .A2(net156));
 sg13g2_nand4_1 _256_ (.B(net66),
    .C(net65),
    .A(_077_),
    .Y(_091_),
    .D(net163));
 sg13g2_mux2_1 _258_ (.A0(net45),
    .A1(net76),
    .S(_091_),
    .X(_015_));
 sg13g2_mux2_1 _259_ (.A0(net72),
    .A1(net75),
    .S(_091_),
    .X(_016_));
 sg13g2_mux2_1 _260_ (.A0(net71),
    .A1(net74),
    .S(_091_),
    .X(_017_));
 sg13g2_mux2_1 _261_ (.A0(net69),
    .A1(net80),
    .S(_091_),
    .X(_018_));
 sg13g2_mux2_1 _262_ (.A0(net68),
    .A1(net79),
    .S(_091_),
    .X(_019_));
 sg13g2_mux2_1 _263_ (.A0(net67),
    .A1(net78),
    .S(_091_),
    .X(_020_));
 sg13g2_xnor2_1 _264_ (.Y(_093_),
    .A(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_2__u_filter_filter_q));
 sg13g2_inv_2 _265_ (.Y(_094_),
    .A(_093_));
 sg13g2_inv_1 _266_ (.Y(_095_),
    .A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_2_));
 sg13g2_nand2_1 _267_ (.Y(_096_),
    .A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_));
 sg13g2_nor2_1 _268_ (.A(_095_),
    .B(_096_),
    .Y(_097_));
 sg13g2_inv_1 _269_ (.Y(_098_),
    .A(_097_));
 sg13g2_nor2_1 _270_ (.A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
    .B(_098_),
    .Y(_099_));
 sg13g2_a21oi_1 _271_ (.A1(_095_),
    .A2(_096_),
    .Y(_100_),
    .B1(_099_));
 sg13g2_nor2b_1 _272_ (.A(_094_),
    .B_N(_100_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_2_));
 sg13g2_nand2_1 _273_ (.Y(_101_),
    .A(_097_),
    .B(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_));
 sg13g2_xnor2_1 _274_ (.Y(_102_),
    .A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_));
 sg13g2_a21oi_1 _275_ (.A1(_101_),
    .A2(_102_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_),
    .B1(_094_));
 sg13g2_xnor2_1 _276_ (.Y(_103_),
    .A(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_0__u_filter_filter_q));
 sg13g2_inv_2 _277_ (.Y(_104_),
    .A(_103_));
 sg13g2_inv_1 _278_ (.Y(_105_),
    .A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_));
 sg13g2_nand2_1 _279_ (.Y(_106_),
    .A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_));
 sg13g2_nor2_1 _280_ (.A(_105_),
    .B(_106_),
    .Y(_107_));
 sg13g2_inv_1 _281_ (.Y(_108_),
    .A(_107_));
 sg13g2_nor2_1 _282_ (.A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
    .B(_108_),
    .Y(_109_));
 sg13g2_a21oi_1 _283_ (.A1(_105_),
    .A2(_106_),
    .Y(_110_),
    .B1(_109_));
 sg13g2_nor2b_1 _284_ (.A(_104_),
    .B_N(_110_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_2_));
 sg13g2_a21oi_1 _285_ (.A1(_101_),
    .A2(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_0_),
    .B1(_094_));
 sg13g2_nand2_1 _286_ (.Y(_111_),
    .A(_107_),
    .B(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_));
 sg13g2_xnor2_1 _287_ (.Y(_112_),
    .A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_));
 sg13g2_a21oi_1 _288_ (.A1(_111_),
    .A2(_112_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_),
    .B1(_104_));
 sg13g2_a21oi_1 _289_ (.A1(_111_),
    .A2(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_0_),
    .B1(_104_));
 sg13g2_inv_1 _290_ (.Y(_113_),
    .A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_));
 sg13g2_a21oi_1 _291_ (.A1(_108_),
    .A2(_113_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_3_),
    .B1(_104_));
 sg13g2_inv_1 _292_ (.Y(_114_),
    .A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_));
 sg13g2_a21oi_1 _293_ (.A1(_098_),
    .A2(_114_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_3_),
    .B1(_094_));
 sg13g2_and2_1 _294_ (.A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_),
    .X(_115_));
 sg13g2_nand2_1 _295_ (.Y(_116_),
    .A(_115_),
    .B(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_2_));
 sg13g2_inv_1 _296_ (.Y(_117_),
    .A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_));
 sg13g2_xnor2_1 _297_ (.Y(_118_),
    .A(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_3__u_filter_filter_q));
 sg13g2_inv_1 _298_ (.Y(_119_),
    .A(_118_));
 sg13g2_a21oi_1 _299_ (.A1(_116_),
    .A2(_117_),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_3_),
    .B1(_119_));
 sg13g2_inv_1 _300_ (.Y(_120_),
    .A(_116_));
 sg13g2_nand2_1 _301_ (.Y(_121_),
    .A(_120_),
    .B(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_));
 sg13g2_xnor2_1 _302_ (.Y(_122_),
    .A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_));
 sg13g2_a21oi_1 _303_ (.A1(_121_),
    .A2(_122_),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_1_),
    .B1(_119_));
 sg13g2_xnor2_1 _304_ (.Y(_123_),
    .A(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_1__u_filter_filter_q));
 sg13g2_inv_2 _305_ (.Y(_124_),
    .A(_123_));
 sg13g2_inv_1 _306_ (.Y(_125_),
    .A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_2_));
 sg13g2_nand2_1 _307_ (.Y(_126_),
    .A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_));
 sg13g2_nor2_1 _308_ (.A(_125_),
    .B(_126_),
    .Y(_127_));
 sg13g2_inv_1 _309_ (.Y(_128_),
    .A(_127_));
 sg13g2_nor2_1 _310_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_),
    .B(_128_),
    .Y(_129_));
 sg13g2_a21oi_1 _311_ (.A1(_125_),
    .A2(_126_),
    .Y(_130_),
    .B1(_129_));
 sg13g2_nor2b_1 _312_ (.A(_124_),
    .B_N(_130_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_2_));
 sg13g2_nand2_1 _313_ (.Y(_131_),
    .A(_127_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_));
 sg13g2_xnor2_1 _314_ (.Y(_132_),
    .A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_));
 sg13g2_a21oi_1 _315_ (.A1(_131_),
    .A2(_132_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_1_),
    .B1(_124_));
 sg13g2_a21oi_1 _316_ (.A1(_131_),
    .A2(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_0_),
    .B1(_124_));
 sg13g2_inv_1 _317_ (.Y(_133_),
    .A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_));
 sg13g2_a21oi_1 _318_ (.A1(_128_),
    .A2(_133_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_),
    .B1(_124_));
 sg13g2_o21ai_1 _319_ (.B1(_118_),
    .Y(_134_),
    .A1(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_2_),
    .A2(_115_));
 sg13g2_a21oi_1 _320_ (.A1(_120_),
    .A2(_117_),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_2_),
    .B1(_134_));
 sg13g2_a21oi_1 _321_ (.A1(_121_),
    .A2(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_0_),
    .B1(_119_));
 sg13g2_mux2_1 _322_ (.A0(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .A1(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .S(reg2hw_19_),
    .X(hw2reg_12_));
 sg13g2_inv_1 _323_ (.Y(_135_),
    .A(u_gpio_core_data_in_q_3_));
 sg13g2_a21oi_1 _324_ (.A1(_135_),
    .A2(reg2hw_3_),
    .Y(_136_),
    .B1(reg2hw_11_));
 sg13g2_a21oi_1 _325_ (.A1(reg2hw_7_),
    .A2(u_gpio_core_data_in_q_3_),
    .Y(_137_),
    .B1(hw2reg_12_));
 sg13g2_a22oi_1 _326_ (.Y(net85),
    .B1(_061_),
    .B2(_137_),
    .A2(_136_),
    .A1(hw2reg_12_));
 sg13g2_nand2_1 _327_ (.Y(_138_),
    .A(_111_),
    .B(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_));
 sg13g2_nand4_1 _328_ (.B(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_),
    .C(_138_),
    .A(_110_),
    .Y(_139_),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_3_));
 sg13g2_mux2_1 _329_ (.A0(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .A1(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .S(_139_),
    .X(_021_));
 sg13g2_nand2_1 _330_ (.Y(_140_),
    .A(_131_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_));
 sg13g2_nand4_1 _331_ (.B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_1_),
    .C(_140_),
    .A(_130_),
    .Y(_141_),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_));
 sg13g2_mux2_1 _332_ (.A0(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .A1(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .S(_141_),
    .X(_022_));
 sg13g2_nand2_1 _333_ (.Y(_142_),
    .A(_101_),
    .B(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_));
 sg13g2_nand4_1 _334_ (.B(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_),
    .C(_142_),
    .A(_100_),
    .Y(_143_),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_3_));
 sg13g2_mux2_1 _335_ (.A0(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .A1(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .S(_143_),
    .X(_023_));
 sg13g2_nand2_1 _336_ (.Y(_144_),
    .A(_121_),
    .B(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_));
 sg13g2_nor2_1 _337_ (.A(_117_),
    .B(_134_),
    .Y(_145_));
 sg13g2_nand3_1 _338_ (.B(_144_),
    .C(_145_),
    .A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_1_),
    .Y(_146_));
 sg13g2_mux2_1 _339_ (.A0(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .A1(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .S(_146_),
    .X(_024_));
 sg13g2_mux2_1 _340_ (.A0(net70),
    .A1(net81),
    .S(_091_),
    .X(_025_));
 sg13g2_mux2_1 _341_ (.A0(net46),
    .A1(net77),
    .S(_091_),
    .X(_026_));
 sg13g2_inv_1 _342_ (.Y(_147_),
    .A(reg2hw_7_));
 sg13g2_nand2_1 _343_ (.Y(_148_),
    .A(net158),
    .B(net46));
 sg13g2_o21ai_1 _344_ (.B1(_148_),
    .Y(_027_),
    .A1(_147_),
    .A2(net158));
 sg13g2_inv_1 _345_ (.Y(_149_),
    .A(reg2hw_19_));
 sg13g2_nand2_1 _346_ (.Y(_150_),
    .A(net157),
    .B(net59));
 sg13g2_o21ai_1 _347_ (.B1(_150_),
    .Y(_028_),
    .A1(_149_),
    .A2(net157));
 sg13g2_nand2_1 _348_ (.Y(_151_),
    .A(net157),
    .B(net50));
 sg13g2_o21ai_1 _349_ (.B1(_151_),
    .Y(_029_),
    .A1(_062_),
    .A2(net157));
 sg13g2_nand2_1 _350_ (.Y(_152_),
    .A(net157),
    .B(net54));
 sg13g2_o21ai_1 _351_ (.B1(_152_),
    .Y(_030_),
    .A1(_061_),
    .A2(net157));
 sg13g2_mux2_1 _352_ (.A0(reg2hw_3_),
    .A1(net70),
    .S(net158),
    .X(_031_));
 sg13g2_a21oi_1 _353_ (.A1(_050_),
    .A2(net77),
    .Y(_153_),
    .B1(net160));
 sg13g2_o21ai_1 _354_ (.B1(_153_),
    .Y(net107),
    .A1(_147_),
    .A2(net165));
 sg13g2_o21ai_1 _355_ (.B1(_052_),
    .Y(net98),
    .A1(_149_),
    .A2(net165));
 sg13g2_a22oi_1 _356_ (.Y(_154_),
    .B1(u_gpio_reg_u_reg_core_data_in_qs_3_),
    .B2(_066_),
    .A2(reg2hw_3_),
    .A1(_048_));
 sg13g2_nand2_1 _357_ (.Y(_155_),
    .A(net163),
    .B(net81));
 sg13g2_nand3_1 _358_ (.B(net162),
    .C(_155_),
    .A(_154_),
    .Y(net103));
 sg13g2_dfrbpq_1 _359_ (.RESET_B(u_gpio_core_filter_rst_ni),
    .D(_021_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .CLK(clknet_4_4_0_clk_i));
 sg13g2_dfrbpq_1 _360_ (.RESET_B(net168),
    .D(_022_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .CLK(clknet_4_1_0_clk_i));
 sg13g2_dfrbpq_1 _361_ (.RESET_B(net167),
    .D(_023_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .CLK(clknet_4_9_0_clk_i));
 sg13g2_dfrbpq_1 _362_ (.RESET_B(net167),
    .D(_024_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .CLK(clknet_4_11_0_clk_i));
 sg13g2_dfrbpq_1 _363_ (.RESET_B(net170),
    .D(_020_),
    .Q(net78),
    .CLK(clknet_4_13_0_clk_i));
 sg13g2_dfrbpq_1 _364_ (.RESET_B(net170),
    .D(_019_),
    .Q(net79),
    .CLK(clknet_4_7_0_clk_i));
 sg13g2_dfrbpq_1 _365_ (.RESET_B(net170),
    .D(_018_),
    .Q(net80),
    .CLK(clknet_4_13_0_clk_i));
 sg13g2_dfrbpq_1 _366_ (.RESET_B(net170),
    .D(_025_),
    .Q(net81),
    .CLK(clknet_4_15_0_clk_i));
 sg13g2_dfrbpq_1 _367_ (.RESET_B(u_gpio_core_state_rst_ni),
    .D(_017_),
    .Q(net74),
    .CLK(clknet_4_5_0_clk_i));
 sg13g2_dfrbpq_1 _368_ (.RESET_B(u_gpio_core_state_rst_ni),
    .D(_016_),
    .Q(net75),
    .CLK(clknet_4_5_0_clk_i));
 sg13g2_dfrbpq_1 _369_ (.RESET_B(net170),
    .D(_015_),
    .Q(net76),
    .CLK(clknet_4_13_0_clk_i));
 sg13g2_dfrbpq_1 _370_ (.RESET_B(net170),
    .D(_026_),
    .Q(net77),
    .CLK(clknet_4_15_0_clk_i));
 sg13g2_dfrbpq_1 _371_ (.RESET_B(net173),
    .D(_014_),
    .Q(reg2hw_4_),
    .CLK(clknet_4_6_0_clk_i));
 sg13g2_dfrbpq_1 _372_ (.RESET_B(net172),
    .D(_013_),
    .Q(reg2hw_5_),
    .CLK(clknet_4_5_0_clk_i));
 sg13g2_dfrbpq_1 _373_ (.RESET_B(reg_rst_ni),
    .D(_012_),
    .Q(reg2hw_6_),
    .CLK(clknet_4_12_0_clk_i));
 sg13g2_dfrbpq_1 _374_ (.RESET_B(net171),
    .D(_027_),
    .Q(reg2hw_7_),
    .CLK(clknet_4_15_0_clk_i));
 sg13g2_dfrbpq_1 _375_ (.RESET_B(net172),
    .D(_011_),
    .Q(reg2hw_16_),
    .CLK(clknet_4_4_0_clk_i));
 sg13g2_dfrbpq_1 _376_ (.RESET_B(net172),
    .D(_010_),
    .Q(reg2hw_17_),
    .CLK(clknet_4_1_0_clk_i));
 sg13g2_dfrbpq_1 _377_ (.RESET_B(net171),
    .D(_009_),
    .Q(reg2hw_18_),
    .CLK(clknet_4_6_0_clk_i));
 sg13g2_dfrbpq_1 _378_ (.RESET_B(net171),
    .D(_028_),
    .Q(reg2hw_19_),
    .CLK(clknet_4_11_0_clk_i));
 sg13g2_dfrbpq_1 _379_ (.RESET_B(net173),
    .D(net197),
    .Q(reg2hw_8_),
    .CLK(clknet_4_12_0_clk_i));
 sg13g2_dfrbpq_1 _380_ (.RESET_B(net172),
    .D(_007_),
    .Q(reg2hw_9_),
    .CLK(clknet_4_4_0_clk_i));
 sg13g2_dfrbpq_1 _381_ (.RESET_B(net171),
    .D(_006_),
    .Q(reg2hw_10_),
    .CLK(clknet_4_14_0_clk_i));
 sg13g2_dfrbpq_1 _382_ (.RESET_B(net171),
    .D(_029_),
    .Q(reg2hw_11_),
    .CLK(clknet_4_14_0_clk_i));
 sg13g2_dfrbpq_1 _383_ (.RESET_B(net173),
    .D(net202),
    .Q(reg2hw_12_),
    .CLK(clknet_4_12_0_clk_i));
 sg13g2_dfrbpq_1 _384_ (.RESET_B(net172),
    .D(_004_),
    .Q(reg2hw_13_),
    .CLK(clknet_4_4_0_clk_i));
 sg13g2_dfrbpq_1 _385_ (.RESET_B(net171),
    .D(_003_),
    .Q(reg2hw_14_),
    .CLK(clknet_4_11_0_clk_i));
 sg13g2_dfrbpq_1 _386_ (.RESET_B(net171),
    .D(_030_),
    .Q(reg2hw_15_),
    .CLK(clknet_4_14_0_clk_i));
 sg13g2_dfrbpq_1 _387_ (.RESET_B(net173),
    .D(_002_),
    .Q(reg2hw_0_),
    .CLK(clknet_4_7_0_clk_i));
 sg13g2_dfrbpq_1 _388_ (.RESET_B(net173),
    .D(_001_),
    .Q(reg2hw_1_),
    .CLK(clknet_4_7_0_clk_i));
 sg13g2_dfrbpq_1 _389_ (.RESET_B(reg_rst_ni),
    .D(_000_),
    .Q(reg2hw_2_),
    .CLK(clknet_4_12_0_clk_i));
 sg13g2_dfrbpq_1 _390_ (.RESET_B(reg_rst_ni),
    .D(_031_),
    .Q(reg2hw_3_),
    .CLK(clknet_4_13_0_clk_i));
 sg13g2_dfrbpq_1 _391_ (.RESET_B(net73),
    .D(u_reg_reset_sync_intq),
    .Q(reg_rst_ni),
    .CLK(clknet_4_8_0_clk_i));
 sg13g2_dfrbpq_1 _392_ (.RESET_B(net73),
    .D(net36),
    .Q(u_reg_reset_sync_intq),
    .CLK(clknet_4_8_0_clk_i));
 sg13g2_tiehi _392__2 (.L_HI(net36));
 sg13g2_dfrbpq_1 _393_ (.RESET_B(net173),
    .D(hw2reg_9_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_0_),
    .CLK(clknet_4_7_0_clk_i));
 sg13g2_dfrbpq_1 _394_ (.RESET_B(net173),
    .D(hw2reg_10_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_1_),
    .CLK(clknet_4_5_0_clk_i));
 sg13g2_dfrbpq_1 _395_ (.RESET_B(net171),
    .D(hw2reg_11_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_2_),
    .CLK(clknet_4_14_0_clk_i));
 sg13g2_dfrbpq_1 _396_ (.RESET_B(reg_rst_ni),
    .D(hw2reg_12_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_3_),
    .CLK(clknet_4_15_0_clk_i));
 sg13g2_dfrbpq_1 _397_ (.RESET_B(core_rst_ni),
    .D(net),
    .Q(u_gpio_core_state_rst_ni),
    .CLK(clknet_4_3_0_clk_i));
 sg13g2_tiehi _397__3 (.L_HI(net));
 sg13g2_dfrbpq_1 _398_ (.RESET_B(core_rst_ni),
    .D(net37),
    .Q(u_gpio_core_filter_rst_ni),
    .CLK(clknet_4_2_0_clk_i));
 sg13g2_tiehi _398__4 (.L_HI(net37));
 sg13g2_dfrbpq_1 _399_ (.RESET_B(net166),
    .D(u_gpio_core_gen_input_filter_3__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .CLK(clknet_4_8_0_clk_i));
 sg13g2_dfrbpq_1 _400_ (.RESET_B(net166),
    .D(net175),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_gen_async_prim_flop_2sync_intq),
    .CLK(clknet_4_10_0_clk_i));
 sg13g2_dfrbpq_1 _401_ (.RESET_B(net167),
    .D(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_filter_q),
    .CLK(clknet_4_11_0_clk_i));
 sg13g2_dfrbpq_1 _402_ (.RESET_B(net167),
    .D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_),
    .CLK(clknet_4_10_0_clk_i));
 sg13g2_dfrbpq_1 _403_ (.RESET_B(net167),
    .D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_1_),
    .CLK(clknet_4_10_0_clk_i));
 sg13g2_dfrbpq_1 _404_ (.RESET_B(net166),
    .D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_2_),
    .CLK(clknet_4_10_0_clk_i));
 sg13g2_dfrbpq_1 _405_ (.RESET_B(net166),
    .D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_),
    .CLK(clknet_4_10_0_clk_i));
 sg13g2_dfrbpq_1 _406_ (.RESET_B(net166),
    .D(u_gpio_core_gen_input_filter_2__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .CLK(clknet_4_8_0_clk_i));
 sg13g2_dfrbpq_1 _407_ (.RESET_B(net166),
    .D(net177),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_gen_async_prim_flop_2sync_intq),
    .CLK(clknet_4_8_0_clk_i));
 sg13g2_dfrbpq_1 _408_ (.RESET_B(net166),
    .D(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_filter_q),
    .CLK(clknet_4_9_0_clk_i));
 sg13g2_dfrbpq_1 _409_ (.RESET_B(net167),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .CLK(clknet_4_9_0_clk_i));
 sg13g2_dfrbpq_1 _410_ (.RESET_B(net167),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_),
    .CLK(clknet_4_9_0_clk_i));
 sg13g2_dfrbpq_1 _411_ (.RESET_B(u_gpio_core_filter_rst_ni),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_2_),
    .CLK(clknet_4_3_0_clk_i));
 sg13g2_dfrbpq_1 _412_ (.RESET_B(net166),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
    .CLK(clknet_4_9_0_clk_i));
 sg13g2_dfrbpq_1 _413_ (.RESET_B(net168),
    .D(u_gpio_core_gen_input_filter_1__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .CLK(clknet_4_0_0_clk_i));
 sg13g2_dfrbpq_1 _414_ (.RESET_B(net169),
    .D(net179),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_gen_async_prim_flop_2sync_intq),
    .CLK(clknet_4_0_0_clk_i));
 sg13g2_dfrbpq_1 _415_ (.RESET_B(net168),
    .D(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_filter_q),
    .CLK(clknet_4_0_0_clk_i));
 sg13g2_dfrbpq_1 _416_ (.RESET_B(net169),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .CLK(clknet_4_2_0_clk_i));
 sg13g2_dfrbpq_1 _417_ (.RESET_B(net169),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .CLK(clknet_4_2_0_clk_i));
 sg13g2_dfrbpq_1 _418_ (.RESET_B(net169),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_2_),
    .CLK(clknet_4_3_0_clk_i));
 sg13g2_dfrbpq_1 _419_ (.RESET_B(net169),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_),
    .CLK(clknet_4_0_0_clk_i));
 sg13g2_dfrbpq_1 _420_ (.RESET_B(net168),
    .D(u_gpio_core_gen_input_filter_0__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .CLK(clknet_4_1_0_clk_i));
 sg13g2_dfrbpq_1 _421_ (.RESET_B(net168),
    .D(net181),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_gen_async_prim_flop_2sync_intq),
    .CLK(clknet_4_0_0_clk_i));
 sg13g2_dfrbpq_1 _422_ (.RESET_B(net168),
    .D(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_filter_q),
    .CLK(clknet_4_1_0_clk_i));
 sg13g2_dfrbpq_1 _423_ (.RESET_B(u_gpio_core_filter_rst_ni),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .CLK(clknet_4_6_0_clk_i));
 sg13g2_dfrbpq_1 _424_ (.RESET_B(u_gpio_core_filter_rst_ni),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .CLK(clknet_4_6_0_clk_i));
 sg13g2_dfrbpq_1 _425_ (.RESET_B(u_gpio_core_filter_rst_ni),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_),
    .CLK(clknet_4_3_0_clk_i));
 sg13g2_dfrbpq_1 _426_ (.RESET_B(u_gpio_core_filter_rst_ni),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
    .CLK(clknet_4_1_0_clk_i));
 sg13g2_dfrbpq_1 _427_ (.RESET_B(u_gpio_core_state_rst_ni),
    .D(hw2reg_9_),
    .Q(u_gpio_core_data_in_q_0_),
    .CLK(clknet_4_6_0_clk_i));
 sg13g2_dfrbpq_1 _428_ (.RESET_B(u_gpio_core_state_rst_ni),
    .D(hw2reg_10_),
    .Q(u_gpio_core_data_in_q_1_),
    .CLK(clknet_4_4_0_clk_i));
 sg13g2_dfrbpq_1 _429_ (.RESET_B(net170),
    .D(hw2reg_11_),
    .Q(u_gpio_core_data_in_q_2_),
    .CLK(clknet_4_12_0_clk_i));
 sg13g2_dfrbpq_1 _430_ (.RESET_B(net170),
    .D(hw2reg_12_),
    .Q(u_gpio_core_data_in_q_3_),
    .CLK(clknet_4_14_0_clk_i));
 sg13g2_dfrbpq_1 _431_ (.RESET_B(net73),
    .D(u_core_reset_sync_intq),
    .Q(core_rst_ni),
    .CLK(clknet_4_2_0_clk_i));
 sg13g2_dfrbpq_1 _432_ (.RESET_B(net73),
    .D(net38),
    .Q(u_core_reset_sync_intq),
    .CLK(clknet_4_2_0_clk_i));
 sg13g2_tiehi _432__5 (.L_HI(net38));
 sg13g2_tiehi _434__6 (.L_HI(reg_rsp_o[0]));
 sg13g2_buf_4 clkbuf_0_clk_i (.X(clknet_0_clk_i),
    .A(clk_i));
 sg13g2_buf_8 clkbuf_4_0_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_0_0_clk_i));
 sg13g2_buf_8 clkbuf_4_10_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_10_0_clk_i));
 sg13g2_buf_8 clkbuf_4_11_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_11_0_clk_i));
 sg13g2_buf_8 clkbuf_4_12_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_12_0_clk_i));
 sg13g2_buf_8 clkbuf_4_13_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_13_0_clk_i));
 sg13g2_buf_8 clkbuf_4_14_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_14_0_clk_i));
 sg13g2_buf_8 clkbuf_4_15_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_15_0_clk_i));
 sg13g2_buf_8 clkbuf_4_1_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_1_0_clk_i));
 sg13g2_buf_8 clkbuf_4_2_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_2_0_clk_i));
 sg13g2_buf_8 clkbuf_4_3_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_3_0_clk_i));
 sg13g2_buf_8 clkbuf_4_4_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_4_0_clk_i));
 sg13g2_buf_8 clkbuf_4_5_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_5_0_clk_i));
 sg13g2_buf_8 clkbuf_4_6_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_6_0_clk_i));
 sg13g2_buf_8 clkbuf_4_7_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_7_0_clk_i));
 sg13g2_buf_8 clkbuf_4_8_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_8_0_clk_i));
 sg13g2_buf_8 clkbuf_4_9_0_clk_i (.A(clknet_0_clk_i),
    .X(clknet_4_9_0_clk_i));
 sg13g2_inv_1 clkload0 (.A(clknet_4_3_0_clk_i));
 sg13g2_inv_1 clkload1 (.A(clknet_4_5_0_clk_i));
 sg13g2_inv_1 clkload2 (.A(clknet_4_7_0_clk_i));
 sg13g2_inv_1 clkload3 (.A(clknet_4_11_0_clk_i));
 sg13g2_inv_1 clkload4 (.A(clknet_4_13_0_clk_i));
 sg13g2_inv_1 clkload5 (.A(clknet_4_15_0_clk_i));
 sg13g2_dlygate4sd3_1 hold152 (.A(cio_gpio_i[3]),
    .X(net174));
 sg13g2_dlygate4sd3_1 hold153 (.A(net43),
    .X(net175));
 sg13g2_dlygate4sd3_1 hold154 (.A(cio_gpio_i[2]),
    .X(net176));
 sg13g2_dlygate4sd3_1 hold155 (.A(net42),
    .X(net177));
 sg13g2_dlygate4sd3_1 hold156 (.A(cio_gpio_i[1]),
    .X(net178));
 sg13g2_dlygate4sd3_1 hold157 (.A(net41),
    .X(net179));
 sg13g2_dlygate4sd3_1 hold158 (.A(cio_gpio_i[0]),
    .X(net180));
 sg13g2_dlygate4sd3_1 hold159 (.A(net40),
    .X(net181));
 sg13g2_dlygate4sd3_1 hold160 (.A(reg_req_i[17]),
    .X(net182));
 sg13g2_dlygate4sd3_1 hold161 (.A(reg_req_i[20]),
    .X(net183));
 sg13g2_dlygate4sd3_1 hold162 (.A(reg_req_i[13]),
    .X(net184));
 sg13g2_dlygate4sd3_1 hold163 (.A(reg_req_i[15]),
    .X(net185));
 sg13g2_dlygate4sd3_1 hold164 (.A(reg_req_i[21]),
    .X(net186));
 sg13g2_dlygate4sd3_1 hold165 (.A(reg_req_i[23]),
    .X(net187));
 sg13g2_dlygate4sd3_1 hold166 (.A(reg_req_i[19]),
    .X(net188));
 sg13g2_dlygate4sd3_1 hold167 (.A(reg_req_i[18]),
    .X(net189));
 sg13g2_dlygate4sd3_1 hold168 (.A(reg_req_i[22]),
    .X(net190));
 sg13g2_dlygate4sd3_1 hold169 (.A(reg_req_i[11]),
    .X(net191));
 sg13g2_dlygate4sd3_1 hold170 (.A(reg_req_i[9]),
    .X(net192));
 sg13g2_dlygate4sd3_1 hold171 (.A(reg_req_i[14]),
    .X(net193));
 sg13g2_dlygate4sd3_1 hold172 (.A(reg_req_i[8]),
    .X(net194));
 sg13g2_dlygate4sd3_1 hold173 (.A(reg_req_i[12]),
    .X(net195));
 sg13g2_dlygate4sd3_1 hold174 (.A(_085_),
    .X(net196));
 sg13g2_dlygate4sd3_1 hold175 (.A(_008_),
    .X(net197));
 sg13g2_dlygate4sd3_1 hold176 (.A(reg_req_i[40]),
    .X(net198));
 sg13g2_dlygate4sd3_1 hold177 (.A(reg_req_i[6]),
    .X(net199));
 sg13g2_dlygate4sd3_1 hold178 (.A(reg_req_i[16]),
    .X(net200));
 sg13g2_dlygate4sd3_1 hold179 (.A(_082_),
    .X(net201));
 sg13g2_dlygate4sd3_1 hold180 (.A(_005_),
    .X(net202));
 sg13g2_dlygate4sd3_1 hold181 (.A(reg_req_i[10]),
    .X(net203));
 sg13g2_dlygate4sd3_1 hold182 (.A(reg_req_i[4]),
    .X(net204));
 sg13g2_dlygate4sd3_1 hold183 (.A(reg_req_i[5]),
    .X(net205));
 sg13g2_dlygate4sd3_1 hold184 (.A(reg_req_i[41]),
    .X(net206));
 sg13g2_dlygate4sd3_1 hold185 (.A(reg_req_i[1]),
    .X(net207));
 sg13g2_dlygate4sd3_1 hold186 (.A(_074_),
    .X(net208));
 sg13g2_dlygate4sd3_1 hold187 (.A(reg_req_i[7]),
    .X(net209));
 sg13g2_dlygate4sd3_1 hold188 (.A(rst_ni),
    .X(net210));
 sg13g2_buf_1 input10 (.A(net174),
    .X(net43));
 sg13g2_buf_1 input11 (.A(reg_req_i[0]),
    .X(net44));
 sg13g2_buf_1 input12 (.A(net203),
    .X(net45));
 sg13g2_buf_1 input13 (.A(net191),
    .X(net46));
 sg13g2_buf_1 input14 (.A(net195),
    .X(net47));
 sg13g2_buf_1 input15 (.A(net184),
    .X(net48));
 sg13g2_buf_1 input16 (.A(net193),
    .X(net49));
 sg13g2_buf_1 input17 (.A(net185),
    .X(net50));
 sg13g2_buf_1 input18 (.A(net200),
    .X(net51));
 sg13g2_buf_1 input19 (.A(net182),
    .X(net52));
 sg13g2_buf_1 input20 (.A(net189),
    .X(net53));
 sg13g2_buf_1 input21 (.A(net188),
    .X(net54));
 sg13g2_buf_1 input22 (.A(net207),
    .X(net55));
 sg13g2_buf_1 input23 (.A(net183),
    .X(net56));
 sg13g2_buf_1 input24 (.A(net186),
    .X(net57));
 sg13g2_buf_1 input25 (.A(net190),
    .X(net58));
 sg13g2_buf_1 input26 (.A(net187),
    .X(net59));
 sg13g2_buf_1 input27 (.A(reg_req_i[2]),
    .X(net60));
 sg13g2_buf_1 input28 (.A(reg_req_i[36]),
    .X(net61));
 sg13g2_buf_1 input29 (.A(reg_req_i[37]),
    .X(net62));
 sg13g2_buf_1 input30 (.A(reg_req_i[38]),
    .X(net63));
 sg13g2_buf_1 input31 (.A(reg_req_i[39]),
    .X(net64));
 sg13g2_buf_1 input32 (.A(net198),
    .X(net65));
 sg13g2_buf_1 input33 (.A(net206),
    .X(net66));
 sg13g2_buf_1 input34 (.A(net204),
    .X(net67));
 sg13g2_buf_1 input35 (.A(net205),
    .X(net68));
 sg13g2_buf_1 input36 (.A(net199),
    .X(net69));
 sg13g2_buf_1 input37 (.A(net209),
    .X(net70));
 sg13g2_buf_1 input38 (.A(net194),
    .X(net71));
 sg13g2_buf_1 input39 (.A(net192),
    .X(net72));
 sg13g2_buf_1 input40 (.A(net210),
    .X(net73));
 sg13g2_buf_1 input7 (.A(net180),
    .X(net40));
 sg13g2_buf_1 input8 (.A(net178),
    .X(net41));
 sg13g2_buf_1 input9 (.A(net176),
    .X(net42));
 sg13g2_buf_1 output41 (.A(net74),
    .X(cio_gpio_en_o[0]));
 sg13g2_buf_1 output42 (.A(net75),
    .X(cio_gpio_en_o[1]));
 sg13g2_buf_1 output43 (.A(net76),
    .X(cio_gpio_en_o[2]));
 sg13g2_buf_1 output44 (.A(net77),
    .X(cio_gpio_en_o[3]));
 sg13g2_buf_1 output45 (.A(net78),
    .X(cio_gpio_o[0]));
 sg13g2_buf_1 output46 (.A(net79),
    .X(cio_gpio_o[1]));
 sg13g2_buf_1 output47 (.A(net80),
    .X(cio_gpio_o[2]));
 sg13g2_buf_1 output48 (.A(net81),
    .X(cio_gpio_o[3]));
 sg13g2_buf_1 output49 (.A(net82),
    .X(intr_gpio_o[0]));
 sg13g2_buf_1 output50 (.A(net83),
    .X(intr_gpio_o[1]));
 sg13g2_buf_1 output51 (.A(net84),
    .X(intr_gpio_o[2]));
 sg13g2_buf_1 output52 (.A(net85),
    .X(intr_gpio_o[3]));
 sg13g2_buf_1 output53 (.A(net86),
    .X(reg_rsp_o[10]));
 sg13g2_buf_1 output54 (.A(net87),
    .X(reg_rsp_o[11]));
 sg13g2_buf_1 output55 (.A(net88),
    .X(reg_rsp_o[12]));
 sg13g2_buf_1 output56 (.A(net89),
    .X(reg_rsp_o[13]));
 sg13g2_buf_1 output57 (.A(net90),
    .X(reg_rsp_o[14]));
 sg13g2_buf_1 output58 (.A(net91),
    .X(reg_rsp_o[15]));
 sg13g2_buf_1 output59 (.A(net92),
    .X(reg_rsp_o[16]));
 sg13g2_buf_1 output60 (.A(net93),
    .X(reg_rsp_o[17]));
 sg13g2_buf_1 output61 (.A(net94),
    .X(reg_rsp_o[18]));
 sg13g2_buf_1 output62 (.A(net95),
    .X(reg_rsp_o[19]));
 sg13g2_buf_1 output63 (.A(net96),
    .X(reg_rsp_o[1]));
 sg13g2_buf_1 output64 (.A(net97),
    .X(reg_rsp_o[20]));
 sg13g2_buf_1 output65 (.A(net98),
    .X(reg_rsp_o[21]));
 sg13g2_buf_1 output66 (.A(net159),
    .X(reg_rsp_o[22]));
 sg13g2_buf_1 output67 (.A(net159),
    .X(reg_rsp_o[23]));
 sg13g2_buf_1 output68 (.A(net159),
    .X(reg_rsp_o[24]));
 sg13g2_buf_1 output69 (.A(net159),
    .X(reg_rsp_o[25]));
 sg13g2_buf_1 output70 (.A(net159),
    .X(reg_rsp_o[26]));
 sg13g2_buf_1 output71 (.A(net159),
    .X(reg_rsp_o[27]));
 sg13g2_buf_1 output72 (.A(net159),
    .X(reg_rsp_o[28]));
 sg13g2_buf_1 output73 (.A(net159),
    .X(reg_rsp_o[29]));
 sg13g2_buf_1 output74 (.A(net99),
    .X(reg_rsp_o[2]));
 sg13g2_buf_1 output75 (.A(net160),
    .X(reg_rsp_o[30]));
 sg13g2_buf_1 output76 (.A(net160),
    .X(reg_rsp_o[31]));
 sg13g2_buf_1 output77 (.A(net160),
    .X(reg_rsp_o[32]));
 sg13g2_buf_1 output78 (.A(net160),
    .X(reg_rsp_o[33]));
 sg13g2_buf_1 output79 (.A(net101),
    .X(reg_rsp_o[3]));
 sg13g2_buf_1 output80 (.A(net102),
    .X(reg_rsp_o[4]));
 sg13g2_buf_1 output81 (.A(net103),
    .X(reg_rsp_o[5]));
 sg13g2_buf_1 output82 (.A(net104),
    .X(reg_rsp_o[6]));
 sg13g2_buf_1 output83 (.A(net105),
    .X(reg_rsp_o[7]));
 sg13g2_buf_1 output84 (.A(net106),
    .X(reg_rsp_o[8]));
 sg13g2_buf_1 output85 (.A(net107),
    .X(reg_rsp_o[9]));
 sg13g2_buf_1 place133 (.A(net156),
    .X(net155));
 sg13g2_buf_1 place134 (.A(_078_),
    .X(net156));
 sg13g2_buf_1 place135 (.A(net158),
    .X(net157));
 sg13g2_buf_1 place136 (.A(_078_),
    .X(net158));
 sg13g2_buf_1 place137 (.A(net160),
    .X(net159));
 sg13g2_buf_1 place138 (.A(net100),
    .X(net160));
 sg13g2_buf_1 place139 (.A(_052_),
    .X(net161));
 sg13g2_buf_1 place140 (.A(_052_),
    .X(net162));
 sg13g2_buf_1 place141 (.A(_050_),
    .X(net163));
 sg13g2_buf_1 place142 (.A(net165),
    .X(net164));
 sg13g2_buf_1 place143 (.A(_046_),
    .X(net165));
 sg13g2_buf_1 place144 (.A(net167),
    .X(net166));
 sg13g2_buf_1 place145 (.A(u_gpio_core_filter_rst_ni),
    .X(net167));
 sg13g2_buf_1 place146 (.A(net169),
    .X(net168));
 sg13g2_buf_1 place147 (.A(u_gpio_core_filter_rst_ni),
    .X(net169));
 sg13g2_buf_1 place148 (.A(u_gpio_core_state_rst_ni),
    .X(net170));
 sg13g2_buf_1 place149 (.A(net172),
    .X(net171));
 sg13g2_buf_1 place150 (.A(reg_rst_ni),
    .X(net172));
 sg13g2_buf_1 place151 (.A(reg_rst_ni),
    .X(net173));
endmodule
