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
 wire net5;
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
 wire u_gpio_reg_reg_rsp_o_10_;
 wire u_gpio_reg_reg_rsp_o_11_;
 wire u_gpio_reg_reg_rsp_o_12_;
 wire u_gpio_reg_reg_rsp_o_13_;
 wire u_gpio_reg_reg_rsp_o_14_;
 wire u_gpio_reg_reg_rsp_o_15_;
 wire u_gpio_reg_reg_rsp_o_16_;
 wire u_gpio_reg_reg_rsp_o_17_;
 wire u_gpio_reg_reg_rsp_o_18_;
 wire u_gpio_reg_reg_rsp_o_19_;
 wire u_gpio_reg_reg_rsp_o_1_;
 wire u_gpio_reg_reg_rsp_o_20_;
 wire u_gpio_reg_reg_rsp_o_21_;
 wire u_gpio_reg_reg_rsp_o_22_;
 wire u_gpio_reg_reg_rsp_o_2_;
 wire u_gpio_reg_reg_rsp_o_3_;
 wire u_gpio_reg_reg_rsp_o_4_;
 wire u_gpio_reg_reg_rsp_o_5_;
 wire u_gpio_reg_reg_rsp_o_6_;
 wire u_gpio_reg_reg_rsp_o_7_;
 wire u_gpio_reg_reg_rsp_o_8_;
 wire u_gpio_reg_reg_rsp_o_9_;
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
 wire net20;
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

 sg13g2_mux2_1 _157_ (.A0(net20),
    .A1(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .S(reg2hw_17_),
    .X(hw2reg_10_));
 sg13g2_mux2_1 _158_ (.A0(net18),
    .A1(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .S(reg2hw_16_),
    .X(hw2reg_9_));
 sg13g2_mux2_1 _159_ (.A0(net22),
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
 sg13g2_a22oi_1 _164_ (.Y(u_gpio_core_intr_gpio_o_2_),
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
 sg13g2_a22oi_1 _169_ (.Y(u_gpio_core_intr_gpio_o_1_),
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
 sg13g2_a22oi_1 _174_ (.Y(u_gpio_core_intr_gpio_o_0_),
    .B1(_042_),
    .B2(_043_),
    .A2(_041_),
    .A1(hw2reg_9_));
 sg13g2_nor2_1 _175_ (.A(reg_req_i[36]),
    .B(reg_req_i[37]),
    .Y(_044_));
 sg13g2_inv_1 _176_ (.Y(_045_),
    .A(reg_req_i[38]));
 sg13g2_nand3_1 _177_ (.B(_045_),
    .C(reg_req_i[39]),
    .A(_044_),
    .Y(_046_));
 sg13g2_buf_1 _178_ (.A(_046_),
    .X(_047_));
 sg13g2_inv_2 _179_ (.Y(_048_),
    .A(_047_));
 sg13g2_nand2b_2 _180_ (.Y(_049_),
    .B(_044_),
    .A_N(reg_req_i[39]));
 sg13g2_nor2_1 _181_ (.A(_045_),
    .B(_049_),
    .Y(_050_));
 sg13g2_a22oi_1 _182_ (.Y(_051_),
    .B1(hw2reg_6_),
    .B2(net14),
    .A2(reg2hw_6_),
    .A1(_048_));
 sg13g2_nand2_1 _183_ (.Y(_052_),
    .A(_047_),
    .B(_049_));
 sg13g2_buf_1 _184_ (.A(_052_),
    .X(_053_));
 sg13g2_nand2_1 _185_ (.Y(u_gpio_reg_reg_rsp_o_8_),
    .A(_051_),
    .B(net13));
 sg13g2_inv_1 _186_ (.Y(_054_),
    .A(reg2hw_5_));
 sg13g2_inv_1 _187_ (.Y(u_gpio_reg_reg_rsp_o_22_),
    .A(_053_));
 sg13g2_a21oi_1 _188_ (.A1(net14),
    .A2(hw2reg_5_),
    .Y(_055_),
    .B1(net11));
 sg13g2_o21ai_1 _189_ (.B1(_055_),
    .Y(u_gpio_reg_reg_rsp_o_7_),
    .A1(_054_),
    .A2(net15));
 sg13g2_inv_1 _190_ (.Y(_056_),
    .A(reg2hw_4_));
 sg13g2_a21oi_1 _191_ (.A1(net14),
    .A2(hw2reg_4_),
    .Y(_057_),
    .B1(net11));
 sg13g2_o21ai_1 _192_ (.B1(_057_),
    .Y(u_gpio_reg_reg_rsp_o_6_),
    .A1(_056_),
    .A2(net15));
 sg13g2_inv_1 _193_ (.Y(_058_),
    .A(reg2hw_18_));
 sg13g2_o21ai_1 _194_ (.B1(net12),
    .Y(u_gpio_reg_reg_rsp_o_20_),
    .A1(_058_),
    .A2(net15));
 sg13g2_inv_1 _195_ (.Y(_059_),
    .A(reg2hw_17_));
 sg13g2_o21ai_1 _196_ (.B1(net12),
    .Y(u_gpio_reg_reg_rsp_o_19_),
    .A1(_059_),
    .A2(net15));
 sg13g2_inv_1 _197_ (.Y(_060_),
    .A(reg2hw_16_));
 sg13g2_o21ai_1 _198_ (.B1(net12),
    .Y(u_gpio_reg_reg_rsp_o_18_),
    .A1(_060_),
    .A2(net15));
 sg13g2_inv_1 _199_ (.Y(_061_),
    .A(reg2hw_15_));
 sg13g2_o21ai_1 _200_ (.B1(net12),
    .Y(u_gpio_reg_reg_rsp_o_17_),
    .A1(_061_),
    .A2(net15));
 sg13g2_o21ai_1 _201_ (.B1(net12),
    .Y(u_gpio_reg_reg_rsp_o_16_),
    .A1(_034_),
    .A2(net15));
 sg13g2_o21ai_1 _202_ (.B1(net12),
    .Y(u_gpio_reg_reg_rsp_o_15_),
    .A1(_038_),
    .A2(net15));
 sg13g2_o21ai_1 _203_ (.B1(net12),
    .Y(u_gpio_reg_reg_rsp_o_14_),
    .A1(_042_),
    .A2(net16));
 sg13g2_inv_1 _204_ (.Y(_062_),
    .A(reg2hw_11_));
 sg13g2_o21ai_1 _205_ (.B1(net12),
    .Y(u_gpio_reg_reg_rsp_o_13_),
    .A1(_062_),
    .A2(net16));
 sg13g2_inv_1 _206_ (.Y(_063_),
    .A(reg2hw_10_));
 sg13g2_o21ai_1 _207_ (.B1(net13),
    .Y(u_gpio_reg_reg_rsp_o_12_),
    .A1(_063_),
    .A2(net16));
 sg13g2_inv_1 _208_ (.Y(_064_),
    .A(reg2hw_9_));
 sg13g2_o21ai_1 _209_ (.B1(net13),
    .Y(u_gpio_reg_reg_rsp_o_11_),
    .A1(_064_),
    .A2(net16));
 sg13g2_inv_1 _210_ (.Y(_065_),
    .A(reg2hw_8_));
 sg13g2_o21ai_1 _211_ (.B1(net13),
    .Y(u_gpio_reg_reg_rsp_o_10_),
    .A1(_065_),
    .A2(net16));
 sg13g2_nor2_2 _212_ (.A(reg_req_i[38]),
    .B(_049_),
    .Y(_066_));
 sg13g2_a22oi_1 _213_ (.Y(_067_),
    .B1(u_gpio_reg_u_reg_core_data_in_qs_2_),
    .B2(_066_),
    .A2(reg2hw_2_),
    .A1(_048_));
 sg13g2_nand2_1 _214_ (.Y(_068_),
    .A(net14),
    .B(hw2reg_2_));
 sg13g2_nand3_1 _215_ (.B(net13),
    .C(_068_),
    .A(_067_),
    .Y(u_gpio_reg_reg_rsp_o_4_));
 sg13g2_a22oi_1 _216_ (.Y(_069_),
    .B1(u_gpio_reg_u_reg_core_data_in_qs_1_),
    .B2(_066_),
    .A2(reg2hw_1_),
    .A1(_048_));
 sg13g2_nand2_1 _217_ (.Y(_070_),
    .A(net14),
    .B(hw2reg_1_));
 sg13g2_nand3_1 _218_ (.B(net13),
    .C(_070_),
    .A(_069_),
    .Y(u_gpio_reg_reg_rsp_o_3_));
 sg13g2_a22oi_1 _219_ (.Y(_071_),
    .B1(u_gpio_reg_u_reg_core_data_in_qs_0_),
    .B2(_066_),
    .A2(reg2hw_0_),
    .A1(_048_));
 sg13g2_nand2_1 _220_ (.Y(_072_),
    .A(net14),
    .B(hw2reg_0_));
 sg13g2_nand3_1 _221_ (.B(net13),
    .C(_072_),
    .A(_071_),
    .Y(u_gpio_reg_reg_rsp_o_2_));
 sg13g2_nand3_1 _222_ (.B(reg_req_i[41]),
    .C(reg_req_i[40]),
    .A(_048_),
    .Y(_073_));
 sg13g2_a21oi_1 _223_ (.A1(reg_req_i[1]),
    .A2(reg_req_i[2]),
    .Y(_074_),
    .B1(_073_));
 sg13g2_nor2b_1 _224_ (.A(reg_req_i[0]),
    .B_N(reg_req_i[40]),
    .Y(_075_));
 sg13g2_o21ai_1 _225_ (.B1(reg_req_i[41]),
    .Y(_076_),
    .A1(_075_),
    .A2(u_gpio_reg_reg_rsp_o_22_));
 sg13g2_nor2b_1 _226_ (.A(_074_),
    .B_N(_076_),
    .Y(_077_));
 sg13g2_inv_1 _227_ (.Y(u_gpio_reg_reg_rsp_o_1_),
    .A(_077_));
 sg13g2_nor2_2 _228_ (.A(_073_),
    .B(u_gpio_reg_reg_rsp_o_1_),
    .Y(_078_));
 sg13g2_buf_1 _229_ (.A(_078_),
    .X(_079_));
 sg13g2_mux2_1 _230_ (.A0(reg2hw_2_),
    .A1(reg_req_i[6]),
    .S(net8),
    .X(_000_));
 sg13g2_mux2_1 _231_ (.A0(reg2hw_1_),
    .A1(reg_req_i[5]),
    .S(net8),
    .X(_001_));
 sg13g2_mux2_1 _232_ (.A0(reg2hw_0_),
    .A1(reg_req_i[4]),
    .S(_078_),
    .X(_002_));
 sg13g2_nand2_1 _233_ (.Y(_080_),
    .A(net6),
    .B(reg_req_i[18]));
 sg13g2_o21ai_1 _234_ (.B1(_080_),
    .Y(_003_),
    .A1(_034_),
    .A2(net5));
 sg13g2_nand2_1 _235_ (.Y(_081_),
    .A(net7),
    .B(reg_req_i[17]));
 sg13g2_o21ai_1 _236_ (.B1(_081_),
    .Y(_004_),
    .A1(_038_),
    .A2(net5));
 sg13g2_nand2_1 _237_ (.Y(_082_),
    .A(net7),
    .B(reg_req_i[16]));
 sg13g2_o21ai_1 _238_ (.B1(_082_),
    .Y(_005_),
    .A1(_042_),
    .A2(net5));
 sg13g2_nand2_1 _239_ (.Y(_083_),
    .A(net7),
    .B(reg_req_i[14]));
 sg13g2_o21ai_1 _240_ (.B1(_083_),
    .Y(_006_),
    .A1(_063_),
    .A2(net5));
 sg13g2_nand2_1 _241_ (.Y(_084_),
    .A(net7),
    .B(reg_req_i[13]));
 sg13g2_o21ai_1 _242_ (.B1(_084_),
    .Y(_007_),
    .A1(_064_),
    .A2(net5));
 sg13g2_nand2_1 _243_ (.Y(_085_),
    .A(net7),
    .B(reg_req_i[12]));
 sg13g2_o21ai_1 _244_ (.B1(_085_),
    .Y(_008_),
    .A1(_065_),
    .A2(net5));
 sg13g2_nand2_1 _245_ (.Y(_086_),
    .A(net7),
    .B(reg_req_i[22]));
 sg13g2_o21ai_1 _246_ (.B1(_086_),
    .Y(_009_),
    .A1(_058_),
    .A2(net5));
 sg13g2_nand2_1 _247_ (.Y(_087_),
    .A(net7),
    .B(reg_req_i[21]));
 sg13g2_o21ai_1 _248_ (.B1(_087_),
    .Y(_010_),
    .A1(_059_),
    .A2(net5));
 sg13g2_nand2_1 _249_ (.Y(_088_),
    .A(net7),
    .B(reg_req_i[20]));
 sg13g2_o21ai_1 _250_ (.B1(_088_),
    .Y(_011_),
    .A1(_060_),
    .A2(net6));
 sg13g2_mux2_1 _251_ (.A0(reg2hw_6_),
    .A1(reg_req_i[10]),
    .S(_078_),
    .X(_012_));
 sg13g2_nand2_1 _252_ (.Y(_089_),
    .A(net8),
    .B(reg_req_i[9]));
 sg13g2_o21ai_1 _253_ (.B1(_089_),
    .Y(_013_),
    .A1(_054_),
    .A2(net6));
 sg13g2_nand2_1 _254_ (.Y(_090_),
    .A(net8),
    .B(reg_req_i[8]));
 sg13g2_o21ai_1 _255_ (.B1(_090_),
    .Y(_014_),
    .A1(_056_),
    .A2(net6));
 sg13g2_nand4_1 _256_ (.B(reg_req_i[41]),
    .C(reg_req_i[40]),
    .A(_077_),
    .Y(_091_),
    .D(net14));
 sg13g2_buf_1 _257_ (.A(_091_),
    .X(_092_));
 sg13g2_mux2_1 _258_ (.A0(reg_req_i[10]),
    .A1(hw2reg_6_),
    .S(net9),
    .X(_015_));
 sg13g2_mux2_1 _259_ (.A0(reg_req_i[9]),
    .A1(hw2reg_5_),
    .S(net9),
    .X(_016_));
 sg13g2_mux2_1 _260_ (.A0(reg_req_i[8]),
    .A1(hw2reg_4_),
    .S(net9),
    .X(_017_));
 sg13g2_mux2_1 _261_ (.A0(reg_req_i[6]),
    .A1(hw2reg_2_),
    .S(net9),
    .X(_018_));
 sg13g2_mux2_1 _262_ (.A0(reg_req_i[5]),
    .A1(hw2reg_1_),
    .S(net9),
    .X(_019_));
 sg13g2_mux2_1 _263_ (.A0(reg_req_i[4]),
    .A1(hw2reg_0_),
    .S(net9),
    .X(_020_));
 sg13g2_xnor2_1 _264_ (.Y(_093_),
    .A(net22),
    .B(u_gpio_core_gen_input_filter_2__u_filter_filter_q));
 sg13g2_inv_2 _265_ (.Y(_094_),
    .A(_093_));
 sg13g2_inv_1 _266_ (.Y(_095_),
    .A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_2_));
 sg13g2_nand2_1 _267_ (.Y(_096_),
    .A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_),
    .B(net21));
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
    .B(net21));
 sg13g2_a21oi_1 _275_ (.A1(_101_),
    .A2(_102_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_),
    .B1(_094_));
 sg13g2_xnor2_1 _276_ (.Y(_103_),
    .A(net18),
    .B(u_gpio_core_gen_input_filter_0__u_filter_filter_q));
 sg13g2_inv_2 _277_ (.Y(_104_),
    .A(_103_));
 sg13g2_inv_1 _278_ (.Y(_105_),
    .A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_));
 sg13g2_nand2_1 _279_ (.Y(_106_),
    .A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .B(net17));
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
    .A2(net21),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_0_),
    .B1(_094_));
 sg13g2_nand2_1 _286_ (.Y(_111_),
    .A(_107_),
    .B(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_));
 sg13g2_xnor2_1 _287_ (.Y(_112_),
    .A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .B(net17));
 sg13g2_a21oi_1 _288_ (.A1(_111_),
    .A2(_112_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_),
    .B1(_104_));
 sg13g2_a21oi_1 _289_ (.A1(_111_),
    .A2(net17),
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
    .B(net23),
    .X(_115_));
 sg13g2_nand2_1 _295_ (.Y(_116_),
    .A(_115_),
    .B(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_2_));
 sg13g2_inv_1 _296_ (.Y(_117_),
    .A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_));
 sg13g2_xnor2_1 _297_ (.Y(_118_),
    .A(net24),
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
    .B(net23));
 sg13g2_a21oi_1 _303_ (.A1(_121_),
    .A2(_122_),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_1_),
    .B1(_119_));
 sg13g2_xnor2_1 _304_ (.Y(_123_),
    .A(net20),
    .B(u_gpio_core_gen_input_filter_1__u_filter_filter_q));
 sg13g2_inv_2 _305_ (.Y(_124_),
    .A(_123_));
 sg13g2_inv_1 _306_ (.Y(_125_),
    .A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_2_));
 sg13g2_nand2_1 _307_ (.Y(_126_),
    .A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .B(net19));
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
    .B(net19));
 sg13g2_a21oi_1 _315_ (.A1(_131_),
    .A2(_132_),
    .Y(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_1_),
    .B1(_124_));
 sg13g2_a21oi_1 _316_ (.A1(_131_),
    .A2(net19),
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
    .A2(net23),
    .Y(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_0_),
    .B1(_119_));
 sg13g2_mux2_1 _322_ (.A0(net24),
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
 sg13g2_a22oi_1 _326_ (.Y(u_gpio_core_intr_gpio_o_3_),
    .B1(_061_),
    .B2(_137_),
    .A2(_136_),
    .A1(hw2reg_12_));
 sg13g2_nand2_1 _327_ (.Y(_138_),
    .A(_111_),
    .B(net17));
 sg13g2_nand4_1 _328_ (.B(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_),
    .C(_138_),
    .A(_110_),
    .Y(_139_),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_3_));
 sg13g2_mux2_1 _329_ (.A0(net18),
    .A1(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .S(_139_),
    .X(_021_));
 sg13g2_nand2_1 _330_ (.Y(_140_),
    .A(_131_),
    .B(net19));
 sg13g2_nand4_1 _331_ (.B(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_1_),
    .C(_140_),
    .A(_130_),
    .Y(_141_),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_));
 sg13g2_mux2_1 _332_ (.A0(net20),
    .A1(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .S(_141_),
    .X(_022_));
 sg13g2_nand2_1 _333_ (.Y(_142_),
    .A(_101_),
    .B(net21));
 sg13g2_nand4_1 _334_ (.B(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_),
    .C(_142_),
    .A(_100_),
    .Y(_143_),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_3_));
 sg13g2_mux2_1 _335_ (.A0(net22),
    .A1(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .S(_143_),
    .X(_023_));
 sg13g2_nand2_1 _336_ (.Y(_144_),
    .A(_121_),
    .B(net23));
 sg13g2_nor2_1 _337_ (.A(_117_),
    .B(_134_),
    .Y(_145_));
 sg13g2_nand3_1 _338_ (.B(_144_),
    .C(_145_),
    .A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_1_),
    .Y(_146_));
 sg13g2_mux2_1 _339_ (.A0(net24),
    .A1(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .S(_146_),
    .X(_024_));
 sg13g2_mux2_1 _340_ (.A0(reg_req_i[7]),
    .A1(hw2reg_3_),
    .S(net9),
    .X(_025_));
 sg13g2_mux2_1 _341_ (.A0(reg_req_i[11]),
    .A1(hw2reg_7_),
    .S(net9),
    .X(_026_));
 sg13g2_inv_1 _342_ (.Y(_147_),
    .A(reg2hw_7_));
 sg13g2_nand2_1 _343_ (.Y(_148_),
    .A(net8),
    .B(reg_req_i[11]));
 sg13g2_o21ai_1 _344_ (.B1(_148_),
    .Y(_027_),
    .A1(_147_),
    .A2(net6));
 sg13g2_inv_1 _345_ (.Y(_149_),
    .A(reg2hw_19_));
 sg13g2_nand2_1 _346_ (.Y(_150_),
    .A(net8),
    .B(reg_req_i[23]));
 sg13g2_o21ai_1 _347_ (.B1(_150_),
    .Y(_028_),
    .A1(_149_),
    .A2(net6));
 sg13g2_nand2_1 _348_ (.Y(_151_),
    .A(net8),
    .B(reg_req_i[15]));
 sg13g2_o21ai_1 _349_ (.B1(_151_),
    .Y(_029_),
    .A1(_062_),
    .A2(net6));
 sg13g2_nand2_1 _350_ (.Y(_152_),
    .A(net8),
    .B(reg_req_i[19]));
 sg13g2_o21ai_1 _351_ (.B1(_152_),
    .Y(_030_),
    .A1(_061_),
    .A2(net6));
 sg13g2_mux2_1 _352_ (.A0(reg2hw_3_),
    .A1(reg_req_i[7]),
    .S(_078_),
    .X(_031_));
 sg13g2_a21oi_1 _353_ (.A1(_050_),
    .A2(hw2reg_7_),
    .Y(_153_),
    .B1(net11));
 sg13g2_o21ai_1 _354_ (.B1(_153_),
    .Y(u_gpio_reg_reg_rsp_o_9_),
    .A1(_147_),
    .A2(net16));
 sg13g2_o21ai_1 _355_ (.B1(net13),
    .Y(u_gpio_reg_reg_rsp_o_21_),
    .A1(_149_),
    .A2(net16));
 sg13g2_a22oi_1 _356_ (.Y(_154_),
    .B1(u_gpio_reg_u_reg_core_data_in_qs_3_),
    .B2(_066_),
    .A2(reg2hw_3_),
    .A1(_048_));
 sg13g2_nand2_1 _357_ (.Y(_155_),
    .A(net14),
    .B(hw2reg_3_));
 sg13g2_nand3_1 _358_ (.B(_053_),
    .C(_155_),
    .A(_154_),
    .Y(u_gpio_reg_reg_rsp_o_5_));
 sg13g2_dfrbpq_1 _359_ (.RESET_B(net25),
    .D(_021_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _360_ (.RESET_B(net25),
    .D(_022_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _361_ (.RESET_B(net25),
    .D(_023_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _362_ (.RESET_B(net25),
    .D(_024_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _363_ (.RESET_B(net30),
    .D(_020_),
    .Q(hw2reg_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _364_ (.RESET_B(net30),
    .D(_019_),
    .Q(hw2reg_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _365_ (.RESET_B(net30),
    .D(_018_),
    .Q(hw2reg_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _366_ (.RESET_B(net30),
    .D(_025_),
    .Q(hw2reg_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _367_ (.RESET_B(net30),
    .D(_017_),
    .Q(hw2reg_4_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _368_ (.RESET_B(net30),
    .D(_016_),
    .Q(hw2reg_5_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _369_ (.RESET_B(net30),
    .D(_015_),
    .Q(hw2reg_6_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _370_ (.RESET_B(net30),
    .D(_026_),
    .Q(hw2reg_7_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _371_ (.RESET_B(net32),
    .D(_014_),
    .Q(reg2hw_4_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _372_ (.RESET_B(net32),
    .D(_013_),
    .Q(reg2hw_5_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _373_ (.RESET_B(net32),
    .D(_012_),
    .Q(reg2hw_6_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _374_ (.RESET_B(net32),
    .D(_027_),
    .Q(reg2hw_7_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _375_ (.RESET_B(net32),
    .D(_011_),
    .Q(reg2hw_16_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _376_ (.RESET_B(net32),
    .D(_010_),
    .Q(reg2hw_17_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _377_ (.RESET_B(net32),
    .D(_009_),
    .Q(reg2hw_18_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _378_ (.RESET_B(net32),
    .D(_028_),
    .Q(reg2hw_19_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _379_ (.RESET_B(net33),
    .D(_008_),
    .Q(reg2hw_8_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _380_ (.RESET_B(net33),
    .D(_007_),
    .Q(reg2hw_9_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _381_ (.RESET_B(net33),
    .D(_006_),
    .Q(reg2hw_10_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _382_ (.RESET_B(net33),
    .D(_029_),
    .Q(reg2hw_11_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _383_ (.RESET_B(net33),
    .D(_005_),
    .Q(reg2hw_12_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _384_ (.RESET_B(net33),
    .D(_004_),
    .Q(reg2hw_13_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _385_ (.RESET_B(net33),
    .D(_003_),
    .Q(reg2hw_14_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _386_ (.RESET_B(net33),
    .D(_030_),
    .Q(reg2hw_15_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _387_ (.RESET_B(net34),
    .D(_002_),
    .Q(reg2hw_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _388_ (.RESET_B(net34),
    .D(_001_),
    .Q(reg2hw_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _389_ (.RESET_B(net34),
    .D(_000_),
    .Q(reg2hw_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _390_ (.RESET_B(net34),
    .D(_031_),
    .Q(reg2hw_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _391_ (.RESET_B(rst_ni),
    .D(u_reg_reset_sync_intq),
    .Q(reg_rst_ni),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _392_ (.RESET_B(rst_ni),
    .D(net),
    .Q(u_reg_reset_sync_intq),
    .CLK(clk_i));
 sg13g2_tiehi _392__1 (.L_HI(net));
 sg13g2_dfrbpq_1 _393_ (.RESET_B(net34),
    .D(hw2reg_9_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _394_ (.RESET_B(net34),
    .D(hw2reg_10_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _395_ (.RESET_B(net34),
    .D(hw2reg_11_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _396_ (.RESET_B(net34),
    .D(hw2reg_12_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _397_ (.RESET_B(core_rst_ni),
    .D(net1),
    .Q(u_gpio_core_state_rst_ni),
    .CLK(clk_i));
 sg13g2_tiehi _397__2 (.L_HI(net1));
 sg13g2_dfrbpq_1 _398_ (.RESET_B(core_rst_ni),
    .D(net2),
    .Q(u_gpio_core_filter_rst_ni),
    .CLK(clk_i));
 sg13g2_tiehi _398__3 (.L_HI(net2));
 sg13g2_dfrbpq_1 _399_ (.RESET_B(net25),
    .D(u_gpio_core_gen_input_filter_3__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _400_ (.RESET_B(net25),
    .D(cio_gpio_i[3]),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_gen_async_prim_flop_2sync_intq),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _401_ (.RESET_B(net25),
    .D(net24),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_filter_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _402_ (.RESET_B(net25),
    .D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _403_ (.RESET_B(net26),
    .D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _404_ (.RESET_B(net26),
    .D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _405_ (.RESET_B(net26),
    .D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _406_ (.RESET_B(net26),
    .D(u_gpio_core_gen_input_filter_2__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _407_ (.RESET_B(net26),
    .D(cio_gpio_i[2]),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_gen_async_prim_flop_2sync_intq),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _408_ (.RESET_B(net26),
    .D(net22),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_filter_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _409_ (.RESET_B(net26),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _410_ (.RESET_B(net26),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _411_ (.RESET_B(net27),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _412_ (.RESET_B(net27),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _413_ (.RESET_B(net27),
    .D(u_gpio_core_gen_input_filter_1__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _414_ (.RESET_B(net27),
    .D(cio_gpio_i[1]),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_gen_async_prim_flop_2sync_intq),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _415_ (.RESET_B(net27),
    .D(net20),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_filter_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _416_ (.RESET_B(net27),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _417_ (.RESET_B(net27),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _418_ (.RESET_B(net27),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _419_ (.RESET_B(net28),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _420_ (.RESET_B(net28),
    .D(u_gpio_core_gen_input_filter_0__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _421_ (.RESET_B(net28),
    .D(cio_gpio_i[0]),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_gen_async_prim_flop_2sync_intq),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _422_ (.RESET_B(net28),
    .D(net18),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_filter_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _423_ (.RESET_B(net28),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _424_ (.RESET_B(net28),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _425_ (.RESET_B(net28),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _426_ (.RESET_B(net28),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _427_ (.RESET_B(net31),
    .D(hw2reg_9_),
    .Q(u_gpio_core_data_in_q_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _428_ (.RESET_B(net31),
    .D(hw2reg_10_),
    .Q(u_gpio_core_data_in_q_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _429_ (.RESET_B(net31),
    .D(hw2reg_11_),
    .Q(u_gpio_core_data_in_q_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _430_ (.RESET_B(net31),
    .D(hw2reg_12_),
    .Q(u_gpio_core_data_in_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _431_ (.RESET_B(rst_ni),
    .D(u_core_reset_sync_intq),
    .Q(core_rst_ni),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _432_ (.RESET_B(rst_ni),
    .D(net3),
    .Q(u_core_reset_sync_intq),
    .CLK(clk_i));
 sg13g2_tiehi _432__4 (.L_HI(net3));
 sg13g2_buf_1 _434_ (.A(net4),
    .X(reg_rsp_o[0]));
 sg13g2_tiehi _434__5 (.L_HI(net4));
 sg13g2_buf_1 _435_ (.A(u_gpio_reg_reg_rsp_o_1_),
    .X(reg_rsp_o[1]));
 sg13g2_buf_1 _436_ (.A(u_gpio_reg_reg_rsp_o_2_),
    .X(reg_rsp_o[2]));
 sg13g2_buf_1 _437_ (.A(u_gpio_reg_reg_rsp_o_3_),
    .X(reg_rsp_o[3]));
 sg13g2_buf_1 _438_ (.A(u_gpio_reg_reg_rsp_o_4_),
    .X(reg_rsp_o[4]));
 sg13g2_buf_1 _439_ (.A(u_gpio_reg_reg_rsp_o_5_),
    .X(reg_rsp_o[5]));
 sg13g2_buf_1 _440_ (.A(u_gpio_reg_reg_rsp_o_6_),
    .X(reg_rsp_o[6]));
 sg13g2_buf_1 _441_ (.A(u_gpio_reg_reg_rsp_o_7_),
    .X(reg_rsp_o[7]));
 sg13g2_buf_1 _442_ (.A(u_gpio_reg_reg_rsp_o_8_),
    .X(reg_rsp_o[8]));
 sg13g2_buf_1 _443_ (.A(u_gpio_reg_reg_rsp_o_9_),
    .X(reg_rsp_o[9]));
 sg13g2_buf_1 _444_ (.A(u_gpio_reg_reg_rsp_o_10_),
    .X(reg_rsp_o[10]));
 sg13g2_buf_1 _445_ (.A(u_gpio_reg_reg_rsp_o_11_),
    .X(reg_rsp_o[11]));
 sg13g2_buf_1 _446_ (.A(u_gpio_reg_reg_rsp_o_12_),
    .X(reg_rsp_o[12]));
 sg13g2_buf_1 _447_ (.A(u_gpio_reg_reg_rsp_o_13_),
    .X(reg_rsp_o[13]));
 sg13g2_buf_1 _448_ (.A(u_gpio_reg_reg_rsp_o_14_),
    .X(reg_rsp_o[14]));
 sg13g2_buf_1 _449_ (.A(u_gpio_reg_reg_rsp_o_15_),
    .X(reg_rsp_o[15]));
 sg13g2_buf_1 _450_ (.A(u_gpio_reg_reg_rsp_o_16_),
    .X(reg_rsp_o[16]));
 sg13g2_buf_1 _451_ (.A(u_gpio_reg_reg_rsp_o_17_),
    .X(reg_rsp_o[17]));
 sg13g2_buf_1 _452_ (.A(u_gpio_reg_reg_rsp_o_18_),
    .X(reg_rsp_o[18]));
 sg13g2_buf_1 _453_ (.A(u_gpio_reg_reg_rsp_o_19_),
    .X(reg_rsp_o[19]));
 sg13g2_buf_1 _454_ (.A(u_gpio_reg_reg_rsp_o_20_),
    .X(reg_rsp_o[20]));
 sg13g2_buf_1 _455_ (.A(u_gpio_reg_reg_rsp_o_21_),
    .X(reg_rsp_o[21]));
 sg13g2_buf_1 _456_ (.A(net10),
    .X(reg_rsp_o[22]));
 sg13g2_buf_1 _457_ (.A(net10),
    .X(reg_rsp_o[23]));
 sg13g2_buf_1 _458_ (.A(net10),
    .X(reg_rsp_o[24]));
 sg13g2_buf_1 _459_ (.A(net10),
    .X(reg_rsp_o[25]));
 sg13g2_buf_1 _460_ (.A(net10),
    .X(reg_rsp_o[26]));
 sg13g2_buf_1 _461_ (.A(net10),
    .X(reg_rsp_o[27]));
 sg13g2_buf_1 _462_ (.A(net10),
    .X(reg_rsp_o[28]));
 sg13g2_buf_1 _463_ (.A(net10),
    .X(reg_rsp_o[29]));
 sg13g2_buf_1 _464_ (.A(net11),
    .X(reg_rsp_o[30]));
 sg13g2_buf_1 _465_ (.A(net11),
    .X(reg_rsp_o[31]));
 sg13g2_buf_1 _466_ (.A(net11),
    .X(reg_rsp_o[32]));
 sg13g2_buf_1 _467_ (.A(net11),
    .X(reg_rsp_o[33]));
 sg13g2_buf_1 _468_ (.A(u_gpio_core_intr_gpio_o_0_),
    .X(intr_gpio_o[0]));
 sg13g2_buf_1 _469_ (.A(u_gpio_core_intr_gpio_o_1_),
    .X(intr_gpio_o[1]));
 sg13g2_buf_1 _470_ (.A(u_gpio_core_intr_gpio_o_2_),
    .X(intr_gpio_o[2]));
 sg13g2_buf_1 _471_ (.A(u_gpio_core_intr_gpio_o_3_),
    .X(intr_gpio_o[3]));
 sg13g2_buf_1 _472_ (.A(hw2reg_0_),
    .X(cio_gpio_o[0]));
 sg13g2_buf_1 _473_ (.A(hw2reg_1_),
    .X(cio_gpio_o[1]));
 sg13g2_buf_1 _474_ (.A(hw2reg_2_),
    .X(cio_gpio_o[2]));
 sg13g2_buf_1 _475_ (.A(hw2reg_3_),
    .X(cio_gpio_o[3]));
 sg13g2_buf_1 _476_ (.A(hw2reg_4_),
    .X(cio_gpio_en_o[0]));
 sg13g2_buf_1 _477_ (.A(hw2reg_5_),
    .X(cio_gpio_en_o[1]));
 sg13g2_buf_1 _478_ (.A(hw2reg_6_),
    .X(cio_gpio_en_o[2]));
 sg13g2_buf_1 _479_ (.A(hw2reg_7_),
    .X(cio_gpio_en_o[3]));
 sg13g2_buf_8 gain10 (.A(_092_),
    .X(net9));
 sg13g2_buf_1 gain11 (.A(net11),
    .X(net10));
 sg13g2_buf_2 gain12 (.A(u_gpio_reg_reg_rsp_o_22_),
    .X(net11));
 sg13g2_buf_4 gain13 (.X(net12),
    .A(_053_));
 sg13g2_buf_4 gain14 (.X(net13),
    .A(_053_));
 sg13g2_buf_4 gain15 (.X(net14),
    .A(_050_));
 sg13g2_buf_4 gain16 (.X(net15),
    .A(net16));
 sg13g2_buf_4 gain17 (.X(net16),
    .A(_047_));
 sg13g2_buf_1 gain18 (.A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .X(net17));
 sg13g2_buf_1 gain19 (.A(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .X(net18));
 sg13g2_buf_1 gain20 (.A(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .X(net19));
 sg13g2_buf_1 gain21 (.A(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .X(net20));
 sg13g2_buf_1 gain22 (.A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .X(net21));
 sg13g2_buf_1 gain23 (.A(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .X(net22));
 sg13g2_buf_1 gain24 (.A(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_),
    .X(net23));
 sg13g2_buf_1 gain25 (.A(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .X(net24));
 sg13g2_buf_8 gain26 (.A(net29),
    .X(net25));
 sg13g2_buf_8 gain27 (.A(net29),
    .X(net26));
 sg13g2_buf_8 gain28 (.A(net29),
    .X(net27));
 sg13g2_buf_8 gain29 (.A(net29),
    .X(net28));
 sg13g2_buf_8 gain30 (.A(u_gpio_core_filter_rst_ni),
    .X(net29));
 sg13g2_buf_8 gain31 (.A(net31),
    .X(net30));
 sg13g2_buf_4 gain32 (.X(net31),
    .A(u_gpio_core_state_rst_ni));
 sg13g2_buf_8 gain33 (.A(net35),
    .X(net32));
 sg13g2_buf_8 gain34 (.A(net35),
    .X(net33));
 sg13g2_buf_8 gain35 (.A(net35),
    .X(net34));
 sg13g2_buf_4 gain36 (.X(net35),
    .A(reg_rst_ni));
 sg13g2_buf_4 gain6 (.X(net5),
    .A(_079_));
 sg13g2_buf_4 gain7 (.X(net6),
    .A(_079_));
 sg13g2_buf_4 gain8 (.X(net7),
    .A(_079_));
 sg13g2_buf_4 gain9 (.X(net8),
    .A(_079_));
endmodule
