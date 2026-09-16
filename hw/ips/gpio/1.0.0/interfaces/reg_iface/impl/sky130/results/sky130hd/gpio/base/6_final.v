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
 wire net51;
 wire net52;
 wire net53;
 wire net54;
 wire net17;
 wire net18;
 wire net19;
 wire net20;
 wire net55;
 wire net56;
 wire net57;
 wire net58;
 wire core_rst_ni;
 wire hw2reg_10_;
 wire hw2reg_11_;
 wire hw2reg_12_;
 wire hw2reg_9_;
 wire net59;
 wire net60;
 wire net61;
 wire net62;
 wire net;
 wire net14;
 wire net15;
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
 wire net21;
 wire net22;
 wire net23;
 wire net24;
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
 wire net38;
 wire net39;
 wire net40;
 wire net41;
 wire net42;
 wire net43;
 wire net44;
 wire net45;
 wire net46;
 wire net47;
 wire net48;
 wire net49;
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
 wire reg_rst_ni;
 wire net50;
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
 wire net13;
 wire net87;
 wire net86;
 wire clknet_0_clk_i;
 wire clknet_3_0__leaf_clk_i;
 wire clknet_3_1__leaf_clk_i;
 wire clknet_3_2__leaf_clk_i;
 wire clknet_3_3__leaf_clk_i;
 wire clknet_3_4__leaf_clk_i;
 wire clknet_3_5__leaf_clk_i;
 wire clknet_3_6__leaf_clk_i;
 wire clknet_3_7__leaf_clk_i;
 wire net88;
 wire net89;
 wire net90;
 wire net91;
 wire net92;

 sky130_fd_sc_hd__inv_1 _185_ (.A(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .Y(_032_));
 sky130_fd_sc_hd__nand2_1 _186_ (.A(reg2hw_17_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .Y(_033_));
 sky130_fd_sc_hd__o21ai_1 _187_ (.A1(reg2hw_17_),
    .A2(_032_),
    .B1(_033_),
    .Y(hw2reg_10_));
 sky130_fd_sc_hd__inv_1 _188_ (.A(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .Y(_034_));
 sky130_fd_sc_hd__nand2_1 _189_ (.A(reg2hw_16_),
    .B(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .Y(_035_));
 sky130_fd_sc_hd__o21ai_1 _190_ (.A1(reg2hw_16_),
    .A2(_034_),
    .B1(_035_),
    .Y(hw2reg_9_));
 sky130_fd_sc_hd__inv_1 _191_ (.A(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .Y(_036_));
 sky130_fd_sc_hd__nand2_1 _192_ (.A(reg2hw_18_),
    .B(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .Y(_037_));
 sky130_fd_sc_hd__o21ai_1 _193_ (.A1(reg2hw_18_),
    .A2(_036_),
    .B1(_037_),
    .Y(hw2reg_11_));
 sky130_fd_sc_hd__inv_1 _194_ (.A(u_gpio_core_data_in_q_2_),
    .Y(_038_));
 sky130_fd_sc_hd__a21oi_1 _195_ (.A1(_038_),
    .A2(reg2hw_2_),
    .B1(reg2hw_10_),
    .Y(_039_));
 sky130_fd_sc_hd__a211oi_1 _196_ (.A1(u_gpio_core_data_in_q_2_),
    .A2(reg2hw_6_),
    .B1(reg2hw_14_),
    .C1(hw2reg_11_),
    .Y(_040_));
 sky130_fd_sc_hd__a21oi_1 _197_ (.A1(hw2reg_11_),
    .A2(_039_),
    .B1(_040_),
    .Y(net61));
 sky130_fd_sc_hd__inv_1 _198_ (.A(u_gpio_core_data_in_q_1_),
    .Y(_041_));
 sky130_fd_sc_hd__a21oi_1 _199_ (.A1(_041_),
    .A2(reg2hw_1_),
    .B1(reg2hw_9_),
    .Y(_042_));
 sky130_fd_sc_hd__a211oi_1 _200_ (.A1(u_gpio_core_data_in_q_1_),
    .A2(reg2hw_5_),
    .B1(reg2hw_13_),
    .C1(hw2reg_10_),
    .Y(_043_));
 sky130_fd_sc_hd__a21oi_1 _201_ (.A1(hw2reg_10_),
    .A2(_042_),
    .B1(_043_),
    .Y(net60));
 sky130_fd_sc_hd__inv_1 _202_ (.A(u_gpio_core_data_in_q_0_),
    .Y(_044_));
 sky130_fd_sc_hd__a21oi_1 _203_ (.A1(_044_),
    .A2(reg2hw_0_),
    .B1(reg2hw_8_),
    .Y(_045_));
 sky130_fd_sc_hd__a211oi_1 _204_ (.A1(u_gpio_core_data_in_q_0_),
    .A2(reg2hw_4_),
    .B1(reg2hw_12_),
    .C1(hw2reg_9_),
    .Y(_046_));
 sky130_fd_sc_hd__a21oi_1 _205_ (.A1(hw2reg_9_),
    .A2(_045_),
    .B1(_046_),
    .Y(net59));
 sky130_fd_sc_hd__clkinv_1 _206_ (.A(net40),
    .Y(_047_));
 sky130_fd_sc_hd__nor2_2 _207_ (.A(net38),
    .B(net39),
    .Y(_048_));
 sky130_fd_sc_hd__inv_1 _208_ (.A(net41),
    .Y(_049_));
 sky130_fd_sc_hd__nand2_4 _209_ (.A(_048_),
    .B(_049_),
    .Y(_050_));
 sky130_fd_sc_hd__nor2_4 _210_ (.A(_047_),
    .B(_050_),
    .Y(_051_));
 sky130_fd_sc_hd__nand3_1 _211_ (.A(_048_),
    .B(_047_),
    .C(net41),
    .Y(_052_));
 sky130_fd_sc_hd__inv_6 _212_ (.A(_052_),
    .Y(_053_));
 sky130_fd_sc_hd__a22oi_1 _213_ (.A1(_051_),
    .A2(net53),
    .B1(reg2hw_6_),
    .B2(_053_),
    .Y(_054_));
 sky130_fd_sc_hd__nand2_8 _214_ (.A(_052_),
    .B(_050_),
    .Y(_055_));
 sky130_fd_sc_hd__nand2_1 _215_ (.A(_054_),
    .B(_055_),
    .Y(net83));
 sky130_fd_sc_hd__inv_4 _216_ (.A(_055_),
    .Y(net76));
 sky130_fd_sc_hd__a221o_1 _217_ (.A1(reg2hw_5_),
    .A2(_053_),
    .B1(net52),
    .B2(_051_),
    .C1(net76),
    .X(net82));
 sky130_fd_sc_hd__a221o_1 _218_ (.A1(reg2hw_4_),
    .A2(_053_),
    .B1(net51),
    .B2(_051_),
    .C1(net76),
    .X(net81));
 sky130_fd_sc_hd__nand2_1 _219_ (.A(_053_),
    .B(reg2hw_18_),
    .Y(_056_));
 sky130_fd_sc_hd__nand2_1 _220_ (.A(_056_),
    .B(_055_),
    .Y(net74));
 sky130_fd_sc_hd__nand2_1 _221_ (.A(_053_),
    .B(reg2hw_17_),
    .Y(_057_));
 sky130_fd_sc_hd__nand2_1 _222_ (.A(_057_),
    .B(_055_),
    .Y(net72));
 sky130_fd_sc_hd__nand2_1 _223_ (.A(_053_),
    .B(reg2hw_16_),
    .Y(_058_));
 sky130_fd_sc_hd__nand2_1 _224_ (.A(_058_),
    .B(_055_),
    .Y(net71));
 sky130_fd_sc_hd__nand2_1 _225_ (.A(_053_),
    .B(reg2hw_15_),
    .Y(_059_));
 sky130_fd_sc_hd__nand2_1 _226_ (.A(_059_),
    .B(_055_),
    .Y(net70));
 sky130_fd_sc_hd__nand2_1 _227_ (.A(_053_),
    .B(reg2hw_14_),
    .Y(_060_));
 sky130_fd_sc_hd__nand2_1 _228_ (.A(_060_),
    .B(_055_),
    .Y(net69));
 sky130_fd_sc_hd__nand2_1 _229_ (.A(_053_),
    .B(reg2hw_13_),
    .Y(_061_));
 sky130_fd_sc_hd__nand2_1 _230_ (.A(_061_),
    .B(_055_),
    .Y(net68));
 sky130_fd_sc_hd__nand2_1 _231_ (.A(_053_),
    .B(reg2hw_12_),
    .Y(_062_));
 sky130_fd_sc_hd__nand2_1 _232_ (.A(_062_),
    .B(_055_),
    .Y(net67));
 sky130_fd_sc_hd__inv_1 _233_ (.A(reg2hw_11_),
    .Y(_063_));
 sky130_fd_sc_hd__o21ai_0 _234_ (.A1(_063_),
    .A2(_052_),
    .B1(_055_),
    .Y(net66));
 sky130_fd_sc_hd__nand2_1 _235_ (.A(_053_),
    .B(reg2hw_10_),
    .Y(_064_));
 sky130_fd_sc_hd__nand2_1 _236_ (.A(_064_),
    .B(_055_),
    .Y(net65));
 sky130_fd_sc_hd__nand2_1 _237_ (.A(_053_),
    .B(reg2hw_9_),
    .Y(_065_));
 sky130_fd_sc_hd__nand2_1 _238_ (.A(_065_),
    .B(_055_),
    .Y(net64));
 sky130_fd_sc_hd__nand2_1 _239_ (.A(_053_),
    .B(reg2hw_8_),
    .Y(_066_));
 sky130_fd_sc_hd__nand2_1 _240_ (.A(_066_),
    .B(_055_),
    .Y(net63));
 sky130_fd_sc_hd__nor2_1 _241_ (.A(net40),
    .B(_050_),
    .Y(_067_));
 sky130_fd_sc_hd__a22oi_1 _242_ (.A1(_067_),
    .A2(u_gpio_reg_u_reg_core_data_in_qs_2_),
    .B1(reg2hw_2_),
    .B2(_053_),
    .Y(_068_));
 sky130_fd_sc_hd__nand2_1 _243_ (.A(_051_),
    .B(net57),
    .Y(_069_));
 sky130_fd_sc_hd__nand3_1 _244_ (.A(_068_),
    .B(_055_),
    .C(_069_),
    .Y(net79));
 sky130_fd_sc_hd__a22oi_1 _245_ (.A1(_067_),
    .A2(u_gpio_reg_u_reg_core_data_in_qs_1_),
    .B1(reg2hw_1_),
    .B2(_053_),
    .Y(_070_));
 sky130_fd_sc_hd__nand2_1 _246_ (.A(_051_),
    .B(net56),
    .Y(_071_));
 sky130_fd_sc_hd__nand3_1 _247_ (.A(_070_),
    .B(_055_),
    .C(_071_),
    .Y(net78));
 sky130_fd_sc_hd__a22oi_1 _248_ (.A1(_067_),
    .A2(u_gpio_reg_u_reg_core_data_in_qs_0_),
    .B1(reg2hw_0_),
    .B2(_053_),
    .Y(_072_));
 sky130_fd_sc_hd__nand2_1 _249_ (.A(_051_),
    .B(net55),
    .Y(_073_));
 sky130_fd_sc_hd__nand3_1 _250_ (.A(_072_),
    .B(_055_),
    .C(_073_),
    .Y(net77));
 sky130_fd_sc_hd__inv_1 _251_ (.A(net46),
    .Y(_074_));
 sky130_fd_sc_hd__inv_1 _252_ (.A(net42),
    .Y(_075_));
 sky130_fd_sc_hd__o21ai_0 _253_ (.A1(net21),
    .A2(_075_),
    .B1(_055_),
    .Y(_076_));
 sky130_fd_sc_hd__nand2_1 _254_ (.A(_076_),
    .B(net43),
    .Y(_077_));
 sky130_fd_sc_hd__nand2_1 _255_ (.A(net43),
    .B(net42),
    .Y(_078_));
 sky130_fd_sc_hd__nor2_1 _256_ (.A(_078_),
    .B(_052_),
    .Y(_079_));
 sky130_fd_sc_hd__nand2_1 _257_ (.A(net32),
    .B(net37),
    .Y(_080_));
 sky130_fd_sc_hd__nand2_1 _258_ (.A(_079_),
    .B(_080_),
    .Y(_081_));
 sky130_fd_sc_hd__nand3_1 _259_ (.A(_077_),
    .B(_079_),
    .C(_081_),
    .Y(_082_));
 sky130_fd_sc_hd__nand2_1 _261_ (.A(net86),
    .B(reg2hw_2_),
    .Y(_084_));
 sky130_fd_sc_hd__o21ai_0 _262_ (.A1(_074_),
    .A2(net86),
    .B1(_084_),
    .Y(_000_));
 sky130_fd_sc_hd__inv_1 _263_ (.A(net45),
    .Y(_085_));
 sky130_fd_sc_hd__nand2_1 _264_ (.A(net86),
    .B(reg2hw_1_),
    .Y(_086_));
 sky130_fd_sc_hd__o21ai_0 _265_ (.A1(_085_),
    .A2(net86),
    .B1(_086_),
    .Y(_001_));
 sky130_fd_sc_hd__inv_1 _266_ (.A(net44),
    .Y(_087_));
 sky130_fd_sc_hd__nand2_1 _267_ (.A(net86),
    .B(reg2hw_0_),
    .Y(_088_));
 sky130_fd_sc_hd__o21ai_0 _268_ (.A1(_087_),
    .A2(net86),
    .B1(_088_),
    .Y(_002_));
 sky130_fd_sc_hd__mux2_1 _269_ (.A0(net30),
    .A1(reg2hw_14_),
    .S(net86),
    .X(_003_));
 sky130_fd_sc_hd__mux2_1 _270_ (.A0(net29),
    .A1(reg2hw_13_),
    .S(net86),
    .X(_004_));
 sky130_fd_sc_hd__mux2_1 _271_ (.A0(net28),
    .A1(reg2hw_12_),
    .S(net86),
    .X(_005_));
 sky130_fd_sc_hd__mux2_1 _272_ (.A0(net26),
    .A1(reg2hw_10_),
    .S(net86),
    .X(_006_));
 sky130_fd_sc_hd__mux2_1 _273_ (.A0(net25),
    .A1(reg2hw_9_),
    .S(net86),
    .X(_007_));
 sky130_fd_sc_hd__mux2_1 _274_ (.A0(net24),
    .A1(reg2hw_8_),
    .S(net86),
    .X(_008_));
 sky130_fd_sc_hd__mux2_1 _275_ (.A0(net35),
    .A1(reg2hw_18_),
    .S(net86),
    .X(_009_));
 sky130_fd_sc_hd__mux2_1 _276_ (.A0(net34),
    .A1(reg2hw_17_),
    .S(net86),
    .X(_010_));
 sky130_fd_sc_hd__mux2_1 _277_ (.A0(net33),
    .A1(reg2hw_16_),
    .S(net86),
    .X(_011_));
 sky130_fd_sc_hd__inv_1 _278_ (.A(net22),
    .Y(_089_));
 sky130_fd_sc_hd__nand2_1 _279_ (.A(net86),
    .B(reg2hw_6_),
    .Y(_090_));
 sky130_fd_sc_hd__o21ai_0 _280_ (.A1(_089_),
    .A2(net86),
    .B1(_090_),
    .Y(_012_));
 sky130_fd_sc_hd__inv_1 _281_ (.A(net49),
    .Y(_091_));
 sky130_fd_sc_hd__nand2_1 _282_ (.A(net86),
    .B(reg2hw_5_),
    .Y(_092_));
 sky130_fd_sc_hd__o21ai_0 _283_ (.A1(_091_),
    .A2(net86),
    .B1(_092_),
    .Y(_013_));
 sky130_fd_sc_hd__inv_1 _284_ (.A(net48),
    .Y(_093_));
 sky130_fd_sc_hd__nand2_1 _285_ (.A(net86),
    .B(reg2hw_4_),
    .Y(_094_));
 sky130_fd_sc_hd__o21ai_0 _286_ (.A1(_093_),
    .A2(net86),
    .B1(_094_),
    .Y(_014_));
 sky130_fd_sc_hd__nand2_1 _287_ (.A(_077_),
    .B(_081_),
    .Y(net73));
 sky130_fd_sc_hd__or3b_1 _288_ (.A(_078_),
    .B(net73),
    .C_N(_051_),
    .X(_095_));
 sky130_fd_sc_hd__nand2_1 _290_ (.A(_095_),
    .B(net53),
    .Y(_097_));
 sky130_fd_sc_hd__o21ai_0 _291_ (.A1(_089_),
    .A2(_095_),
    .B1(_097_),
    .Y(_015_));
 sky130_fd_sc_hd__nand2_1 _292_ (.A(_095_),
    .B(net52),
    .Y(_098_));
 sky130_fd_sc_hd__o21ai_0 _293_ (.A1(_091_),
    .A2(_095_),
    .B1(_098_),
    .Y(_016_));
 sky130_fd_sc_hd__nand2_1 _294_ (.A(_095_),
    .B(net51),
    .Y(_099_));
 sky130_fd_sc_hd__o21ai_0 _295_ (.A1(_093_),
    .A2(_095_),
    .B1(_099_),
    .Y(_017_));
 sky130_fd_sc_hd__nand2_1 _296_ (.A(_095_),
    .B(net57),
    .Y(_100_));
 sky130_fd_sc_hd__o21ai_0 _297_ (.A1(_074_),
    .A2(_095_),
    .B1(_100_),
    .Y(_018_));
 sky130_fd_sc_hd__nand2_1 _298_ (.A(_095_),
    .B(net56),
    .Y(_101_));
 sky130_fd_sc_hd__o21ai_0 _299_ (.A1(_085_),
    .A2(_095_),
    .B1(_101_),
    .Y(_019_));
 sky130_fd_sc_hd__nand2_1 _300_ (.A(_095_),
    .B(net55),
    .Y(_102_));
 sky130_fd_sc_hd__o21ai_0 _301_ (.A1(_087_),
    .A2(_095_),
    .B1(_102_),
    .Y(_020_));
 sky130_fd_sc_hd__nand3_1 _302_ (.A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .C(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_2_),
    .Y(_103_));
 sky130_fd_sc_hd__nand2_1 _303_ (.A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .Y(_104_));
 sky130_fd_sc_hd__inv_1 _304_ (.A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_2_),
    .Y(_105_));
 sky130_fd_sc_hd__nand2_1 _305_ (.A(_104_),
    .B(_105_),
    .Y(_106_));
 sky130_fd_sc_hd__o21ai_0 _306_ (.A1(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
    .A2(_103_),
    .B1(_106_),
    .Y(_107_));
 sky130_fd_sc_hd__xnor2_1 _307_ (.A(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_2__u_filter_filter_q),
    .Y(_108_));
 sky130_fd_sc_hd__clkinv_1 _308_ (.A(_108_),
    .Y(_109_));
 sky130_fd_sc_hd__nor2_1 _309_ (.A(_107_),
    .B(_109_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_2_));
 sky130_fd_sc_hd__or2_0 _310_ (.A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .X(_110_));
 sky130_fd_sc_hd__inv_1 _311_ (.A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
    .Y(_111_));
 sky130_fd_sc_hd__nor2_1 _312_ (.A(_111_),
    .B(_103_),
    .Y(_112_));
 sky130_fd_sc_hd__a21oi_1 _313_ (.A1(_110_),
    .A2(_104_),
    .B1(_112_),
    .Y(_113_));
 sky130_fd_sc_hd__nor2_1 _314_ (.A(_113_),
    .B(_109_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_));
 sky130_fd_sc_hd__nand3_1 _315_ (.A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .C(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_),
    .Y(_114_));
 sky130_fd_sc_hd__nand2_1 _316_ (.A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .Y(_115_));
 sky130_fd_sc_hd__inv_1 _317_ (.A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_),
    .Y(_116_));
 sky130_fd_sc_hd__nand2_1 _318_ (.A(_115_),
    .B(_116_),
    .Y(_117_));
 sky130_fd_sc_hd__o21ai_0 _319_ (.A1(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
    .A2(_114_),
    .B1(_117_),
    .Y(_118_));
 sky130_fd_sc_hd__xnor2_1 _320_ (.A(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_0__u_filter_filter_q),
    .Y(_119_));
 sky130_fd_sc_hd__clkinv_1 _321_ (.A(_119_),
    .Y(_120_));
 sky130_fd_sc_hd__nor2_1 _322_ (.A(_118_),
    .B(_120_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_2_));
 sky130_fd_sc_hd__inv_1 _323_ (.A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .Y(_121_));
 sky130_fd_sc_hd__nor2_1 _324_ (.A(_121_),
    .B(_112_),
    .Y(_122_));
 sky130_fd_sc_hd__nor2_1 _325_ (.A(_122_),
    .B(_109_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_0_));
 sky130_fd_sc_hd__or2_0 _326_ (.A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .X(_123_));
 sky130_fd_sc_hd__inv_1 _327_ (.A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
    .Y(_124_));
 sky130_fd_sc_hd__nor2_1 _328_ (.A(_124_),
    .B(_114_),
    .Y(_125_));
 sky130_fd_sc_hd__a21oi_1 _329_ (.A1(_123_),
    .A2(_115_),
    .B1(_125_),
    .Y(_126_));
 sky130_fd_sc_hd__nor2_1 _330_ (.A(_126_),
    .B(_120_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_));
 sky130_fd_sc_hd__inv_1 _331_ (.A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .Y(_127_));
 sky130_fd_sc_hd__nor2_1 _332_ (.A(_127_),
    .B(_125_),
    .Y(_128_));
 sky130_fd_sc_hd__nor2_1 _333_ (.A(_128_),
    .B(_120_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_0_));
 sky130_fd_sc_hd__a21oi_1 _334_ (.A1(_124_),
    .A2(_114_),
    .B1(_120_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_3_));
 sky130_fd_sc_hd__a21oi_1 _335_ (.A1(_111_),
    .A2(_103_),
    .B1(_109_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_3_));
 sky130_fd_sc_hd__xnor2_1 _336_ (.A(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_3__u_filter_filter_q),
    .Y(_129_));
 sky130_fd_sc_hd__clkinv_1 _337_ (.A(_129_),
    .Y(_130_));
 sky130_fd_sc_hd__inv_1 _338_ (.A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_2_),
    .Y(_131_));
 sky130_fd_sc_hd__inv_1 _339_ (.A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_1_),
    .Y(_132_));
 sky130_fd_sc_hd__inv_1 _340_ (.A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_),
    .Y(_133_));
 sky130_fd_sc_hd__nor2_1 _341_ (.A(_132_),
    .B(_133_),
    .Y(_134_));
 sky130_fd_sc_hd__clkinv_1 _342_ (.A(_134_),
    .Y(_135_));
 sky130_fd_sc_hd__nor2_1 _343_ (.A(_131_),
    .B(_135_),
    .Y(_136_));
 sky130_fd_sc_hd__nor2_1 _344_ (.A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_),
    .B(_136_),
    .Y(_137_));
 sky130_fd_sc_hd__nor2_1 _345_ (.A(_130_),
    .B(_137_),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_3_));
 sky130_fd_sc_hd__nand2_1 _346_ (.A(_136_),
    .B(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_),
    .Y(_138_));
 sky130_fd_sc_hd__nand2_1 _347_ (.A(_132_),
    .B(_133_),
    .Y(_139_));
 sky130_fd_sc_hd__nand2_1 _348_ (.A(_135_),
    .B(_139_),
    .Y(_140_));
 sky130_fd_sc_hd__a21oi_1 _349_ (.A1(_138_),
    .A2(_140_),
    .B1(_130_),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_1_));
 sky130_fd_sc_hd__nand3_1 _350_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .C(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_2_),
    .Y(_141_));
 sky130_fd_sc_hd__nand2_1 _351_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .Y(_142_));
 sky130_fd_sc_hd__inv_1 _352_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_2_),
    .Y(_143_));
 sky130_fd_sc_hd__nand2_1 _353_ (.A(_142_),
    .B(_143_),
    .Y(_144_));
 sky130_fd_sc_hd__o21ai_0 _354_ (.A1(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_),
    .A2(_141_),
    .B1(_144_),
    .Y(_145_));
 sky130_fd_sc_hd__xnor2_1 _355_ (.A(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .B(u_gpio_core_gen_input_filter_1__u_filter_filter_q),
    .Y(_146_));
 sky130_fd_sc_hd__clkinv_1 _356_ (.A(_146_),
    .Y(_147_));
 sky130_fd_sc_hd__nor2_1 _357_ (.A(_145_),
    .B(_147_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_2_));
 sky130_fd_sc_hd__or2_0 _358_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .X(_148_));
 sky130_fd_sc_hd__inv_1 _359_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_),
    .Y(_149_));
 sky130_fd_sc_hd__nor2_1 _360_ (.A(_149_),
    .B(_141_),
    .Y(_150_));
 sky130_fd_sc_hd__a21oi_1 _361_ (.A1(_148_),
    .A2(_142_),
    .B1(_150_),
    .Y(_151_));
 sky130_fd_sc_hd__nor2_1 _362_ (.A(_151_),
    .B(_147_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_1_));
 sky130_fd_sc_hd__inv_1 _363_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .Y(_152_));
 sky130_fd_sc_hd__nor2_1 _364_ (.A(_152_),
    .B(_150_),
    .Y(_153_));
 sky130_fd_sc_hd__nor2_1 _365_ (.A(_153_),
    .B(_147_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_0_));
 sky130_fd_sc_hd__a21oi_1 _366_ (.A1(_149_),
    .A2(_141_),
    .B1(_147_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_));
 sky130_fd_sc_hd__a21oi_1 _367_ (.A1(_131_),
    .A2(_135_),
    .B1(_130_),
    .Y(_154_));
 sky130_fd_sc_hd__o31a_1 _368_ (.A1(_131_),
    .A2(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_),
    .A3(_135_),
    .B1(_154_),
    .X(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_2_));
 sky130_fd_sc_hd__a21oi_1 _369_ (.A1(_136_),
    .A2(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_),
    .B1(_133_),
    .Y(_155_));
 sky130_fd_sc_hd__nor2_1 _370_ (.A(_130_),
    .B(_155_),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_0_));
 sky130_fd_sc_hd__inv_1 _371_ (.A(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .Y(_156_));
 sky130_fd_sc_hd__nand2_1 _372_ (.A(reg2hw_19_),
    .B(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .Y(_157_));
 sky130_fd_sc_hd__o21ai_1 _373_ (.A1(reg2hw_19_),
    .A2(_156_),
    .B1(_157_),
    .Y(hw2reg_12_));
 sky130_fd_sc_hd__inv_1 _374_ (.A(u_gpio_core_data_in_q_3_),
    .Y(_158_));
 sky130_fd_sc_hd__a21oi_1 _375_ (.A1(_158_),
    .A2(reg2hw_3_),
    .B1(reg2hw_11_),
    .Y(_159_));
 sky130_fd_sc_hd__a211oi_1 _376_ (.A1(reg2hw_7_),
    .A2(u_gpio_core_data_in_q_3_),
    .B1(reg2hw_15_),
    .C1(hw2reg_12_),
    .Y(_160_));
 sky130_fd_sc_hd__a21oi_1 _377_ (.A1(hw2reg_12_),
    .A2(_159_),
    .B1(_160_),
    .Y(net62));
 sky130_fd_sc_hd__nand2_1 _378_ (.A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_3_),
    .B(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_),
    .Y(_161_));
 sky130_fd_sc_hd__nor3_1 _379_ (.A(_118_),
    .B(_128_),
    .C(_161_),
    .Y(_162_));
 sky130_fd_sc_hd__nor2_1 _380_ (.A(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .B(_162_),
    .Y(_163_));
 sky130_fd_sc_hd__a21oi_1 _381_ (.A1(_034_),
    .A2(_162_),
    .B1(_163_),
    .Y(_021_));
 sky130_fd_sc_hd__nand2_1 _382_ (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_),
    .B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_1_),
    .Y(_164_));
 sky130_fd_sc_hd__nor3_1 _383_ (.A(_145_),
    .B(_153_),
    .C(_164_),
    .Y(_165_));
 sky130_fd_sc_hd__nor2_1 _384_ (.A(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .B(_165_),
    .Y(_166_));
 sky130_fd_sc_hd__a21oi_1 _385_ (.A1(_032_),
    .A2(_165_),
    .B1(_166_),
    .Y(_022_));
 sky130_fd_sc_hd__nand2_1 _386_ (.A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_3_),
    .B(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_),
    .Y(_167_));
 sky130_fd_sc_hd__nor3_1 _387_ (.A(_107_),
    .B(_122_),
    .C(_167_),
    .Y(_168_));
 sky130_fd_sc_hd__nor2_1 _388_ (.A(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .B(_168_),
    .Y(_169_));
 sky130_fd_sc_hd__a21oi_1 _389_ (.A1(_036_),
    .A2(_168_),
    .B1(_169_),
    .Y(_023_));
 sky130_fd_sc_hd__nand2_1 _390_ (.A(_154_),
    .B(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_),
    .Y(_170_));
 sky130_fd_sc_hd__nor3b_1 _391_ (.A(_155_),
    .B(_170_),
    .C_N(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_1_),
    .Y(_171_));
 sky130_fd_sc_hd__nor2_1 _392_ (.A(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .B(_171_),
    .Y(_172_));
 sky130_fd_sc_hd__a21oi_1 _393_ (.A1(_156_),
    .A2(_171_),
    .B1(_172_),
    .Y(_024_));
 sky130_fd_sc_hd__inv_1 _394_ (.A(net47),
    .Y(_173_));
 sky130_fd_sc_hd__nand2_1 _395_ (.A(_095_),
    .B(net58),
    .Y(_174_));
 sky130_fd_sc_hd__o21ai_0 _396_ (.A1(_173_),
    .A2(_095_),
    .B1(_174_),
    .Y(_025_));
 sky130_fd_sc_hd__inv_1 _397_ (.A(net23),
    .Y(_175_));
 sky130_fd_sc_hd__nand2_1 _398_ (.A(_095_),
    .B(net54),
    .Y(_176_));
 sky130_fd_sc_hd__o21ai_0 _399_ (.A1(_175_),
    .A2(_095_),
    .B1(_176_),
    .Y(_026_));
 sky130_fd_sc_hd__nand2_1 _400_ (.A(net86),
    .B(reg2hw_7_),
    .Y(_177_));
 sky130_fd_sc_hd__o21ai_0 _401_ (.A1(_175_),
    .A2(net86),
    .B1(_177_),
    .Y(_027_));
 sky130_fd_sc_hd__inv_1 _402_ (.A(reg2hw_19_),
    .Y(_178_));
 sky130_fd_sc_hd__nor2_1 _403_ (.A(net36),
    .B(net86),
    .Y(_179_));
 sky130_fd_sc_hd__a21oi_1 _404_ (.A1(_178_),
    .A2(net86),
    .B1(_179_),
    .Y(_028_));
 sky130_fd_sc_hd__nor2_1 _405_ (.A(net27),
    .B(net86),
    .Y(_180_));
 sky130_fd_sc_hd__a21oi_1 _406_ (.A1(_063_),
    .A2(net86),
    .B1(_180_),
    .Y(_029_));
 sky130_fd_sc_hd__mux2_1 _407_ (.A0(net31),
    .A1(reg2hw_15_),
    .S(net86),
    .X(_030_));
 sky130_fd_sc_hd__nand2_1 _408_ (.A(net86),
    .B(reg2hw_3_),
    .Y(_181_));
 sky130_fd_sc_hd__o21ai_0 _409_ (.A1(_173_),
    .A2(net86),
    .B1(_181_),
    .Y(_031_));
 sky130_fd_sc_hd__a221o_1 _410_ (.A1(net54),
    .A2(_051_),
    .B1(reg2hw_7_),
    .B2(_053_),
    .C1(net76),
    .X(net84));
 sky130_fd_sc_hd__o21ai_0 _411_ (.A1(_178_),
    .A2(_052_),
    .B1(_055_),
    .Y(net75));
 sky130_fd_sc_hd__a22oi_1 _412_ (.A1(_067_),
    .A2(u_gpio_reg_u_reg_core_data_in_qs_3_),
    .B1(reg2hw_3_),
    .B2(_053_),
    .Y(_182_));
 sky130_fd_sc_hd__nand2_1 _413_ (.A(_051_),
    .B(net58),
    .Y(_183_));
 sky130_fd_sc_hd__nand3_1 _414_ (.A(_182_),
    .B(_055_),
    .C(_183_),
    .Y(net80));
 sky130_fd_sc_hd__dfrtp_1 _415_ (.D(_021_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .RESET_B(u_gpio_core_filter_rst_ni),
    .CLK(clknet_3_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _416_ (.D(_022_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .RESET_B(net87),
    .CLK(clknet_3_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _417_ (.D(_023_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .RESET_B(net87),
    .CLK(clknet_3_5__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _418_ (.D(_024_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .RESET_B(net87),
    .CLK(clknet_3_7__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _419_ (.D(_020_),
    .Q(net55),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_3_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _420_ (.D(_019_),
    .Q(net56),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_3_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _421_ (.D(_018_),
    .Q(net57),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_3_7__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _422_ (.D(_025_),
    .Q(net58),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_3_6__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _423_ (.D(_017_),
    .Q(net51),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_3_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _424_ (.D(_016_),
    .Q(net52),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_3_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _425_ (.D(_015_),
    .Q(net53),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_3_7__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _426_ (.D(_026_),
    .Q(net54),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_3_6__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _427_ (.D(_014_),
    .Q(reg2hw_4_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _428_ (.D(_013_),
    .Q(reg2hw_5_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _429_ (.D(_012_),
    .Q(reg2hw_6_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_5__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _430_ (.D(_027_),
    .Q(reg2hw_7_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_6__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _431_ (.D(_011_),
    .Q(reg2hw_16_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _432_ (.D(_010_),
    .Q(reg2hw_17_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _433_ (.D(_009_),
    .Q(reg2hw_18_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_4__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _434_ (.D(_028_),
    .Q(reg2hw_19_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_7__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _435_ (.D(_008_),
    .Q(reg2hw_8_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _436_ (.D(_007_),
    .Q(reg2hw_9_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _437_ (.D(_006_),
    .Q(reg2hw_10_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_5__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _438_ (.D(_029_),
    .Q(reg2hw_11_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_7__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _439_ (.D(_005_),
    .Q(reg2hw_12_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _440_ (.D(_004_),
    .Q(reg2hw_13_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _441_ (.D(_003_),
    .Q(reg2hw_14_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_4__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _442_ (.D(_030_),
    .Q(reg2hw_15_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_7__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _443_ (.D(_002_),
    .Q(reg2hw_0_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _444_ (.D(_001_),
    .Q(reg2hw_1_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _445_ (.D(_000_),
    .Q(reg2hw_2_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_5__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _446_ (.D(_031_),
    .Q(reg2hw_3_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_7__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _447_ (.D(u_reg_reset_sync_intq),
    .Q(reg_rst_ni),
    .RESET_B(net50),
    .CLK(clknet_3_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _448_ (.D(net13),
    .Q(u_reg_reset_sync_intq),
    .RESET_B(net50),
    .CLK(clknet_3_0__leaf_clk_i));
 sky130_fd_sc_hd__conb_1 _448__2 (.HI(net13));
 sky130_fd_sc_hd__dfrtp_1 _449_ (.D(hw2reg_9_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_0_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _450_ (.D(hw2reg_10_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_1_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _451_ (.D(hw2reg_11_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_2_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_5__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _452_ (.D(hw2reg_12_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_3_),
    .RESET_B(reg_rst_ni),
    .CLK(clknet_3_7__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _453_ (.D(net),
    .Q(u_gpio_core_state_rst_ni),
    .RESET_B(net89),
    .CLK(clknet_3_0__leaf_clk_i));
 sky130_fd_sc_hd__conb_1 _453__3 (.HI(net));
 sky130_fd_sc_hd__dfrtp_1 _454_ (.D(net14),
    .Q(u_gpio_core_filter_rst_ni),
    .RESET_B(net89),
    .CLK(clknet_3_0__leaf_clk_i));
 sky130_fd_sc_hd__conb_1 _454__4 (.HI(net14));
 sky130_fd_sc_hd__dfrtp_1 _455_ (.D(u_gpio_core_gen_input_filter_3__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .RESET_B(net87),
    .CLK(clknet_3_5__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _456_ (.D(net20),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_gen_async_prim_flop_2sync_intq),
    .RESET_B(net87),
    .CLK(clknet_3_5__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _457_ (.D(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_filter_q),
    .RESET_B(net87),
    .CLK(clknet_3_7__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _458_ (.D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_),
    .RESET_B(u_gpio_core_filter_rst_ni),
    .CLK(clknet_3_6__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _459_ (.D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_1_),
    .RESET_B(u_gpio_core_filter_rst_ni),
    .CLK(clknet_3_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _460_ (.D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_2_),
    .RESET_B(u_gpio_core_filter_rst_ni),
    .CLK(clknet_3_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _461_ (.D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_),
    .RESET_B(u_gpio_core_filter_rst_ni),
    .CLK(clknet_3_6__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _462_ (.D(u_gpio_core_gen_input_filter_2__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .RESET_B(net87),
    .CLK(clknet_3_4__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _463_ (.D(net19),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_gen_async_prim_flop_2sync_intq),
    .RESET_B(net87),
    .CLK(clknet_3_4__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _464_ (.D(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_filter_q),
    .RESET_B(net87),
    .CLK(clknet_3_4__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _465_ (.D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .RESET_B(net87),
    .CLK(clknet_3_4__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _466_ (.D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_),
    .RESET_B(net87),
    .CLK(clknet_3_4__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _467_ (.D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_2_),
    .RESET_B(net87),
    .CLK(clknet_3_4__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _468_ (.D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
    .RESET_B(net87),
    .CLK(clknet_3_4__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _469_ (.D(u_gpio_core_gen_input_filter_1__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .RESET_B(net87),
    .CLK(clknet_3_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _470_ (.D(net18),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_gen_async_prim_flop_2sync_intq),
    .RESET_B(net87),
    .CLK(clknet_3_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _471_ (.D(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_filter_q),
    .RESET_B(net87),
    .CLK(clknet_3_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _472_ (.D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .RESET_B(net87),
    .CLK(clknet_3_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _473_ (.D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .RESET_B(net87),
    .CLK(clknet_3_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _474_ (.D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_2_),
    .RESET_B(net87),
    .CLK(clknet_3_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _475_ (.D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_),
    .RESET_B(net87),
    .CLK(clknet_3_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _476_ (.D(u_gpio_core_gen_input_filter_0__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .RESET_B(u_gpio_core_filter_rst_ni),
    .CLK(clknet_3_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _477_ (.D(net17),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_gen_async_prim_flop_2sync_intq),
    .RESET_B(u_gpio_core_filter_rst_ni),
    .CLK(clknet_3_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _478_ (.D(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_filter_q),
    .RESET_B(u_gpio_core_filter_rst_ni),
    .CLK(clknet_3_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _479_ (.D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .RESET_B(u_gpio_core_filter_rst_ni),
    .CLK(clknet_3_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _480_ (.D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .RESET_B(u_gpio_core_filter_rst_ni),
    .CLK(clknet_3_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _481_ (.D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_),
    .RESET_B(u_gpio_core_filter_rst_ni),
    .CLK(clknet_3_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _482_ (.D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
    .RESET_B(u_gpio_core_filter_rst_ni),
    .CLK(clknet_3_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _483_ (.D(hw2reg_9_),
    .Q(u_gpio_core_data_in_q_0_),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_3_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _484_ (.D(hw2reg_10_),
    .Q(u_gpio_core_data_in_q_1_),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_3_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _485_ (.D(hw2reg_11_),
    .Q(u_gpio_core_data_in_q_2_),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_3_5__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _486_ (.D(hw2reg_12_),
    .Q(u_gpio_core_data_in_q_3_),
    .RESET_B(u_gpio_core_state_rst_ni),
    .CLK(clknet_3_6__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _487_ (.D(u_core_reset_sync_intq),
    .Q(core_rst_ni),
    .RESET_B(net50),
    .CLK(clknet_3_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 _488_ (.D(net15),
    .Q(u_core_reset_sync_intq),
    .RESET_B(net50),
    .CLK(clknet_3_0__leaf_clk_i));
 sky130_fd_sc_hd__conb_1 _488__5 (.HI(net15));
 sky130_fd_sc_hd__conb_1 _490__6 (.HI(reg_rsp_o[0]));
 sky130_fd_sc_hd__clkbuf_8 clkbuf_0_clk_i (.A(clk_i),
    .X(clknet_0_clk_i));
 sky130_fd_sc_hd__clkbuf_8 clkbuf_3_0__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_3_0__leaf_clk_i));
 sky130_fd_sc_hd__clkbuf_8 clkbuf_3_1__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_3_1__leaf_clk_i));
 sky130_fd_sc_hd__clkbuf_8 clkbuf_3_2__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_3_2__leaf_clk_i));
 sky130_fd_sc_hd__clkbuf_8 clkbuf_3_3__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_3_3__leaf_clk_i));
 sky130_fd_sc_hd__clkbuf_8 clkbuf_3_4__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_3_4__leaf_clk_i));
 sky130_fd_sc_hd__clkbuf_8 clkbuf_3_5__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_3_5__leaf_clk_i));
 sky130_fd_sc_hd__clkbuf_8 clkbuf_3_6__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_3_6__leaf_clk_i));
 sky130_fd_sc_hd__clkbuf_8 clkbuf_3_7__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_3_7__leaf_clk_i));
 sky130_fd_sc_hd__clkbuf_8 clkload0 (.A(clknet_3_1__leaf_clk_i));
 sky130_fd_sc_hd__bufinv_16 clkload1 (.A(clknet_3_3__leaf_clk_i));
 sky130_fd_sc_hd__clkinv_2 clkload2 (.A(clknet_3_4__leaf_clk_i));
 sky130_fd_sc_hd__bufinv_16 clkload3 (.A(clknet_3_5__leaf_clk_i));
 sky130_fd_sc_hd__clkinv_4 clkload4 (.A(clknet_3_6__leaf_clk_i));
 sky130_fd_sc_hd__clkinv_2 clkload5 (.A(clknet_3_7__leaf_clk_i));
 sky130_fd_sc_hd__dlygate4sd3_1 hold89 (.A(rst_ni),
    .X(net88));
 sky130_fd_sc_hd__dlygate4sd3_1 hold90 (.A(core_rst_ni),
    .X(net89));
 sky130_fd_sc_hd__dlygate4sd3_1 hold91 (.A(cio_gpio_i[1]),
    .X(net90));
 sky130_fd_sc_hd__dlygate4sd3_1 hold92 (.A(cio_gpio_i[0]),
    .X(net91));
 sky130_fd_sc_hd__dlygate4sd3_1 hold93 (.A(cio_gpio_i[2]),
    .X(net92));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input10 (.A(cio_gpio_i[3]),
    .X(net20));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input11 (.A(reg_req_i[0]),
    .X(net21));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input12 (.A(reg_req_i[10]),
    .X(net22));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input13 (.A(reg_req_i[11]),
    .X(net23));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input14 (.A(reg_req_i[12]),
    .X(net24));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input15 (.A(reg_req_i[13]),
    .X(net25));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input16 (.A(reg_req_i[14]),
    .X(net26));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input17 (.A(reg_req_i[15]),
    .X(net27));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input18 (.A(reg_req_i[16]),
    .X(net28));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input19 (.A(reg_req_i[17]),
    .X(net29));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input20 (.A(reg_req_i[18]),
    .X(net30));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input21 (.A(reg_req_i[19]),
    .X(net31));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input22 (.A(reg_req_i[1]),
    .X(net32));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input23 (.A(reg_req_i[20]),
    .X(net33));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input24 (.A(reg_req_i[21]),
    .X(net34));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input25 (.A(reg_req_i[22]),
    .X(net35));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input26 (.A(reg_req_i[23]),
    .X(net36));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input27 (.A(reg_req_i[2]),
    .X(net37));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input28 (.A(reg_req_i[36]),
    .X(net38));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input29 (.A(reg_req_i[37]),
    .X(net39));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input30 (.A(reg_req_i[38]),
    .X(net40));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input31 (.A(reg_req_i[39]),
    .X(net41));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input32 (.A(reg_req_i[40]),
    .X(net42));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input33 (.A(reg_req_i[41]),
    .X(net43));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input34 (.A(reg_req_i[4]),
    .X(net44));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input35 (.A(reg_req_i[5]),
    .X(net45));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input36 (.A(reg_req_i[6]),
    .X(net46));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input37 (.A(reg_req_i[7]),
    .X(net47));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input38 (.A(reg_req_i[8]),
    .X(net48));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input39 (.A(reg_req_i[9]),
    .X(net49));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input40 (.A(net88),
    .X(net50));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input7 (.A(net91),
    .X(net17));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input8 (.A(net90),
    .X(net18));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input9 (.A(net92),
    .X(net19));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output41 (.A(net51),
    .X(cio_gpio_en_o[0]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output42 (.A(net52),
    .X(cio_gpio_en_o[1]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output43 (.A(net53),
    .X(cio_gpio_en_o[2]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output44 (.A(net54),
    .X(cio_gpio_en_o[3]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output45 (.A(net55),
    .X(cio_gpio_o[0]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output46 (.A(net56),
    .X(cio_gpio_o[1]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output47 (.A(net57),
    .X(cio_gpio_o[2]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output48 (.A(net58),
    .X(cio_gpio_o[3]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output49 (.A(net59),
    .X(intr_gpio_o[0]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output50 (.A(net60),
    .X(intr_gpio_o[1]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output51 (.A(net61),
    .X(intr_gpio_o[2]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output52 (.A(net62),
    .X(intr_gpio_o[3]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output53 (.A(net63),
    .X(reg_rsp_o[10]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output54 (.A(net64),
    .X(reg_rsp_o[11]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output55 (.A(net65),
    .X(reg_rsp_o[12]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output56 (.A(net66),
    .X(reg_rsp_o[13]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output57 (.A(net67),
    .X(reg_rsp_o[14]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output58 (.A(net68),
    .X(reg_rsp_o[15]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output59 (.A(net69),
    .X(reg_rsp_o[16]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output60 (.A(net70),
    .X(reg_rsp_o[17]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output61 (.A(net71),
    .X(reg_rsp_o[18]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output62 (.A(net72),
    .X(reg_rsp_o[19]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output63 (.A(net73),
    .X(reg_rsp_o[1]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output64 (.A(net74),
    .X(reg_rsp_o[20]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output65 (.A(net75),
    .X(reg_rsp_o[21]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output66 (.A(net76),
    .X(reg_rsp_o[22]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output67 (.A(net76),
    .X(reg_rsp_o[23]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output68 (.A(net76),
    .X(reg_rsp_o[24]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output69 (.A(net76),
    .X(reg_rsp_o[25]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output70 (.A(net76),
    .X(reg_rsp_o[26]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output71 (.A(net76),
    .X(reg_rsp_o[27]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output72 (.A(net76),
    .X(reg_rsp_o[28]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output73 (.A(net76),
    .X(reg_rsp_o[29]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output74 (.A(net77),
    .X(reg_rsp_o[2]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output75 (.A(net76),
    .X(reg_rsp_o[30]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output76 (.A(net76),
    .X(reg_rsp_o[31]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output77 (.A(net76),
    .X(reg_rsp_o[32]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output78 (.A(net76),
    .X(reg_rsp_o[33]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output79 (.A(net78),
    .X(reg_rsp_o[3]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output80 (.A(net79),
    .X(reg_rsp_o[4]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output81 (.A(net80),
    .X(reg_rsp_o[5]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output82 (.A(net81),
    .X(reg_rsp_o[6]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output83 (.A(net82),
    .X(reg_rsp_o[7]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output84 (.A(net83),
    .X(reg_rsp_o[8]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output85 (.A(net84),
    .X(reg_rsp_o[9]));
 sky130_fd_sc_hd__buf_4 place87 (.A(_082_),
    .X(net86));
 sky130_fd_sc_hd__buf_4 place88 (.A(u_gpio_core_filter_rst_ni),
    .X(net87));
endmodule
