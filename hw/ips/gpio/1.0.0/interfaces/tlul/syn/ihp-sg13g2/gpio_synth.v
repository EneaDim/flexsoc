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

 sg13g2_mux2_1 _256_ (.A0(net42),
    .A1(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .S(reg2hw_18_),
    .X(hw2reg_11_));
 sg13g2_mux2_1 _257_ (.A0(net40),
    .A1(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .S(reg2hw_17_),
    .X(hw2reg_10_));
 sg13g2_mux2_1 _258_ (.A0(net39),
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
    .Y(u_gpio_core_intr_gpio_o_2_),
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
    .Y(u_gpio_core_intr_gpio_o_1_),
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
    .Y(u_gpio_core_intr_gpio_o_0_),
    .B1(_088_));
 sg13g2_xnor2_1 _274_ (.Y(_089_),
    .A(net40),
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
 sg13g2_inv_1 _286_ (.Y(u_gpio_reg_tl_o_0_),
    .A(u_gpio_reg_tl_o_65_));
 sg13g2_nand2_2 _287_ (.Y(_099_),
    .A(u_gpio_reg_tl_o_0_),
    .B(tl_i[108]));
 sg13g2_nor3_1 _288_ (.A(tl_i[106]),
    .B(tl_i[107]),
    .C(_099_),
    .Y(_100_));
 sg13g2_inv_1 _289_ (.Y(_101_),
    .A(tl_i[60]));
 sg13g2_inv_1 _290_ (.Y(_102_),
    .A(tl_i[61]));
 sg13g2_nand3_1 _291_ (.B(_101_),
    .C(_102_),
    .A(_100_),
    .Y(_103_));
 sg13g2_inv_2 _292_ (.Y(_104_),
    .A(tl_i[63]));
 sg13g2_nor2_1 _293_ (.A(tl_i[62]),
    .B(_104_),
    .Y(_105_));
 sg13g2_nand2_1 _294_ (.Y(_106_),
    .A(tl_i[57]),
    .B(tl_i[58]));
 sg13g2_inv_1 _295_ (.Y(_107_),
    .A(tl_i[56]));
 sg13g2_a21oi_1 _296_ (.A1(_105_),
    .A2(_106_),
    .Y(_108_),
    .B1(_107_));
 sg13g2_nand2_1 _297_ (.Y(_109_),
    .A(tl_i[63]),
    .B(tl_i[62]));
 sg13g2_o21ai_1 _298_ (.B1(_109_),
    .Y(_110_),
    .A1(_108_),
    .A2(_103_));
 sg13g2_nor2_1 _299_ (.A(_103_),
    .B(_110_),
    .Y(_111_));
 sg13g2_nand2_1 _300_ (.Y(_112_),
    .A(_111_),
    .B(_105_));
 sg13g2_buf_8 _301_ (.A(_112_),
    .X(_113_));
 sg13g2_nor2_1 _302_ (.A(tl_i[26]),
    .B(net27),
    .Y(_114_));
 sg13g2_a21oi_1 _303_ (.A1(_098_),
    .A2(net27),
    .Y(_000_),
    .B1(_114_));
 sg13g2_mux2_1 _304_ (.A0(tl_i[25]),
    .A1(reg2hw_1_),
    .S(net27),
    .X(_001_));
 sg13g2_mux2_1 _305_ (.A0(tl_i[24]),
    .A1(reg2hw_0_),
    .S(net27),
    .X(_002_));
 sg13g2_mux2_1 _306_ (.A0(tl_i[38]),
    .A1(reg2hw_14_),
    .S(net27),
    .X(_003_));
 sg13g2_mux2_1 _307_ (.A0(tl_i[37]),
    .A1(reg2hw_13_),
    .S(net27),
    .X(_004_));
 sg13g2_mux2_1 _308_ (.A0(tl_i[36]),
    .A1(reg2hw_12_),
    .S(net27),
    .X(_005_));
 sg13g2_mux2_1 _309_ (.A0(tl_i[34]),
    .A1(reg2hw_10_),
    .S(net27),
    .X(_006_));
 sg13g2_mux2_1 _310_ (.A0(tl_i[33]),
    .A1(reg2hw_9_),
    .S(net28),
    .X(_007_));
 sg13g2_mux2_1 _311_ (.A0(tl_i[32]),
    .A1(reg2hw_8_),
    .S(net28),
    .X(_008_));
 sg13g2_mux2_1 _312_ (.A0(tl_i[42]),
    .A1(reg2hw_18_),
    .S(net28),
    .X(_009_));
 sg13g2_mux2_1 _313_ (.A0(tl_i[41]),
    .A1(reg2hw_17_),
    .S(net28),
    .X(_010_));
 sg13g2_mux2_1 _314_ (.A0(tl_i[40]),
    .A1(reg2hw_16_),
    .S(net28),
    .X(_011_));
 sg13g2_mux2_1 _315_ (.A0(tl_i[30]),
    .A1(reg2hw_6_),
    .S(net28),
    .X(_012_));
 sg13g2_mux2_1 _316_ (.A0(tl_i[29]),
    .A1(reg2hw_5_),
    .S(net28),
    .X(_013_));
 sg13g2_mux2_1 _317_ (.A0(tl_i[28]),
    .A1(reg2hw_4_),
    .S(net28),
    .X(_014_));
 sg13g2_buf_1 _318_ (.A(_099_),
    .X(_115_));
 sg13g2_mux2_1 _319_ (.A0(tl_i[100]),
    .A1(u_gpio_reg_tl_o_57_),
    .S(net36),
    .X(_015_));
 sg13g2_mux2_1 _320_ (.A0(tl_i[98]),
    .A1(u_gpio_reg_tl_o_55_),
    .S(net36),
    .X(_016_));
 sg13g2_mux2_1 _321_ (.A0(tl_i[97]),
    .A1(u_gpio_reg_tl_o_54_),
    .S(net37),
    .X(_017_));
 sg13g2_mux2_1 _322_ (.A0(tl_i[96]),
    .A1(u_gpio_reg_tl_o_53_),
    .S(net37),
    .X(_018_));
 sg13g2_mux2_1 _323_ (.A0(tl_i[95]),
    .A1(u_gpio_reg_tl_o_52_),
    .S(net37),
    .X(_019_));
 sg13g2_mux2_1 _324_ (.A0(tl_i[94]),
    .A1(u_gpio_reg_tl_o_51_),
    .S(net37),
    .X(_020_));
 sg13g2_mux2_1 _325_ (.A0(tl_i[93]),
    .A1(u_gpio_reg_tl_o_50_),
    .S(net37),
    .X(_021_));
 sg13g2_mux2_1 _326_ (.A0(tl_i[92]),
    .A1(u_gpio_reg_tl_o_49_),
    .S(net37),
    .X(_022_));
 sg13g2_inv_1 _327_ (.Y(_116_),
    .A(u_gpio_reg_tl_o_46_));
 sg13g2_inv_1 _328_ (.Y(_117_),
    .A(_099_));
 sg13g2_inv_1 _329_ (.Y(_118_),
    .A(_100_));
 sg13g2_nor2_1 _330_ (.A(tl_i[105]),
    .B(tl_i[106]),
    .Y(_119_));
 sg13g2_nand3_1 _331_ (.B(tl_i[107]),
    .C(_119_),
    .A(_117_),
    .Y(_120_));
 sg13g2_a21oi_1 _332_ (.A1(_101_),
    .A2(_102_),
    .Y(_121_),
    .B1(_118_));
 sg13g2_a21oi_1 _333_ (.A1(_118_),
    .A2(_120_),
    .Y(_122_),
    .B1(_121_));
 sg13g2_nand2_1 _334_ (.Y(_123_),
    .A(_122_),
    .B(_110_));
 sg13g2_nand3_1 _335_ (.B(_118_),
    .C(_109_),
    .A(_123_),
    .Y(_124_));
 sg13g2_nand2_1 _336_ (.Y(_125_),
    .A(_124_),
    .B(net33));
 sg13g2_buf_1 _337_ (.A(_125_),
    .X(_126_));
 sg13g2_o21ai_1 _338_ (.B1(net25),
    .Y(_023_),
    .A1(_116_),
    .A2(net32));
 sg13g2_inv_1 _339_ (.Y(_127_),
    .A(u_gpio_reg_tl_o_45_));
 sg13g2_o21ai_1 _340_ (.B1(net25),
    .Y(_024_),
    .A1(_127_),
    .A2(net32));
 sg13g2_inv_1 _341_ (.Y(_128_),
    .A(u_gpio_reg_tl_o_44_));
 sg13g2_o21ai_1 _342_ (.B1(net25),
    .Y(_025_),
    .A1(_128_),
    .A2(net32));
 sg13g2_inv_1 _343_ (.Y(_129_),
    .A(u_gpio_reg_tl_o_43_));
 sg13g2_o21ai_1 _344_ (.B1(net25),
    .Y(_026_),
    .A1(_129_),
    .A2(net32));
 sg13g2_inv_1 _345_ (.Y(_130_),
    .A(u_gpio_reg_tl_o_42_));
 sg13g2_o21ai_1 _346_ (.B1(net26),
    .Y(_027_),
    .A1(_130_),
    .A2(net32));
 sg13g2_inv_1 _347_ (.Y(_131_),
    .A(u_gpio_reg_tl_o_41_));
 sg13g2_o21ai_1 _348_ (.B1(net26),
    .Y(_028_),
    .A1(_131_),
    .A2(net32));
 sg13g2_inv_1 _349_ (.Y(_132_),
    .A(u_gpio_reg_tl_o_40_));
 sg13g2_o21ai_1 _350_ (.B1(net26),
    .Y(_029_),
    .A1(_132_),
    .A2(net32));
 sg13g2_inv_1 _351_ (.Y(_133_),
    .A(u_gpio_reg_tl_o_39_));
 sg13g2_o21ai_1 _352_ (.B1(net26),
    .Y(_030_),
    .A1(_133_),
    .A2(net32));
 sg13g2_inv_1 _353_ (.Y(_134_),
    .A(u_gpio_reg_tl_o_38_));
 sg13g2_o21ai_1 _354_ (.B1(net26),
    .Y(_031_),
    .A1(_134_),
    .A2(net33));
 sg13g2_inv_1 _355_ (.Y(_135_),
    .A(u_gpio_reg_tl_o_37_));
 sg13g2_o21ai_1 _356_ (.B1(net26),
    .Y(_032_),
    .A1(_135_),
    .A2(net33));
 sg13g2_inv_1 _357_ (.Y(_136_),
    .A(u_gpio_reg_tl_o_36_));
 sg13g2_o21ai_1 _358_ (.B1(net26),
    .Y(_033_),
    .A1(_136_),
    .A2(net33));
 sg13g2_nor3_2 _359_ (.A(_104_),
    .B(tl_i[62]),
    .C(_099_),
    .Y(_137_));
 sg13g2_a22oi_1 _360_ (.Y(_138_),
    .B1(reg2hw_19_),
    .B2(net31),
    .A2(net35),
    .A1(u_gpio_reg_tl_o_35_));
 sg13g2_nand2_1 _361_ (.Y(_034_),
    .A(net24),
    .B(_138_));
 sg13g2_a22oi_1 _362_ (.Y(_139_),
    .B1(reg2hw_18_),
    .B2(net31),
    .A2(net35),
    .A1(u_gpio_reg_tl_o_34_));
 sg13g2_nand2_1 _363_ (.Y(_035_),
    .A(net24),
    .B(_139_));
 sg13g2_a22oi_1 _364_ (.Y(_140_),
    .B1(reg2hw_17_),
    .B2(net31),
    .A2(net35),
    .A1(u_gpio_reg_tl_o_33_));
 sg13g2_nand2_1 _365_ (.Y(_036_),
    .A(net24),
    .B(_140_));
 sg13g2_a22oi_1 _366_ (.Y(_141_),
    .B1(reg2hw_16_),
    .B2(net31),
    .A2(net35),
    .A1(u_gpio_reg_tl_o_32_));
 sg13g2_nand2_1 _367_ (.Y(_037_),
    .A(net24),
    .B(_141_));
 sg13g2_a22oi_1 _368_ (.Y(_142_),
    .B1(reg2hw_15_),
    .B2(net31),
    .A2(net35),
    .A1(u_gpio_reg_tl_o_31_));
 sg13g2_nand2_1 _369_ (.Y(_038_),
    .A(net24),
    .B(_142_));
 sg13g2_a22oi_1 _370_ (.Y(_143_),
    .B1(reg2hw_14_),
    .B2(net31),
    .A2(net35),
    .A1(u_gpio_reg_tl_o_30_));
 sg13g2_nand2_1 _371_ (.Y(_039_),
    .A(net24),
    .B(_143_));
 sg13g2_a22oi_1 _372_ (.Y(_144_),
    .B1(reg2hw_13_),
    .B2(net31),
    .A2(net36),
    .A1(u_gpio_reg_tl_o_29_));
 sg13g2_nand2_1 _373_ (.Y(_040_),
    .A(net24),
    .B(_144_));
 sg13g2_a22oi_1 _374_ (.Y(_145_),
    .B1(reg2hw_12_),
    .B2(net31),
    .A2(net36),
    .A1(u_gpio_reg_tl_o_28_));
 sg13g2_nand2_1 _375_ (.Y(_041_),
    .A(net24),
    .B(_145_));
 sg13g2_a22oi_1 _376_ (.Y(_146_),
    .B1(reg2hw_11_),
    .B2(_137_),
    .A2(net36),
    .A1(u_gpio_reg_tl_o_27_));
 sg13g2_nand2_1 _377_ (.Y(_042_),
    .A(net25),
    .B(_146_));
 sg13g2_a22oi_1 _378_ (.Y(_147_),
    .B1(reg2hw_10_),
    .B2(_137_),
    .A2(net36),
    .A1(u_gpio_reg_tl_o_26_));
 sg13g2_nand2_1 _379_ (.Y(_043_),
    .A(net25),
    .B(_147_));
 sg13g2_a22oi_1 _380_ (.Y(_148_),
    .B1(reg2hw_9_),
    .B2(_137_),
    .A2(net36),
    .A1(u_gpio_reg_tl_o_25_));
 sg13g2_nand2_1 _381_ (.Y(_044_),
    .A(net25),
    .B(_148_));
 sg13g2_a22oi_1 _382_ (.Y(_149_),
    .B1(reg2hw_8_),
    .B2(_137_),
    .A2(net36),
    .A1(u_gpio_reg_tl_o_24_));
 sg13g2_nand2_1 _383_ (.Y(_045_),
    .A(net25),
    .B(_149_));
 sg13g2_inv_1 _384_ (.Y(_150_),
    .A(u_gpio_reg_tl_o_23_));
 sg13g2_inv_1 _385_ (.Y(_151_),
    .A(hw2reg_7_));
 sg13g2_inv_1 _386_ (.Y(_152_),
    .A(tl_i[62]));
 sg13g2_o21ai_1 _387_ (.B1(net62),
    .Y(_153_),
    .A1(_151_),
    .A2(net61));
 sg13g2_o21ai_1 _388_ (.B1(_153_),
    .Y(_154_),
    .A1(reg2hw_7_),
    .A2(tl_i[62]));
 sg13g2_and3_1 _389_ (.X(_155_),
    .A(_123_),
    .B(net33),
    .C(_118_));
 sg13g2_buf_4 _390_ (.X(_156_),
    .A(_155_));
 sg13g2_a22oi_1 _391_ (.Y(_046_),
    .B1(_154_),
    .B2(_156_),
    .A2(net34),
    .A1(_150_));
 sg13g2_inv_1 _392_ (.Y(_157_),
    .A(u_gpio_reg_tl_o_22_));
 sg13g2_inv_1 _393_ (.Y(_158_),
    .A(hw2reg_6_));
 sg13g2_o21ai_1 _394_ (.B1(net62),
    .Y(_159_),
    .A1(_158_),
    .A2(net61));
 sg13g2_o21ai_1 _395_ (.B1(_159_),
    .Y(_160_),
    .A1(reg2hw_6_),
    .A2(tl_i[62]));
 sg13g2_a22oi_1 _396_ (.Y(_047_),
    .B1(_160_),
    .B2(_156_),
    .A2(net34),
    .A1(_157_));
 sg13g2_inv_1 _397_ (.Y(_161_),
    .A(u_gpio_reg_tl_o_21_));
 sg13g2_inv_1 _398_ (.Y(_162_),
    .A(hw2reg_5_));
 sg13g2_o21ai_1 _399_ (.B1(net62),
    .Y(_163_),
    .A1(_162_),
    .A2(net61));
 sg13g2_o21ai_1 _400_ (.B1(_163_),
    .Y(_164_),
    .A1(reg2hw_5_),
    .A2(tl_i[62]));
 sg13g2_a22oi_1 _401_ (.Y(_048_),
    .B1(_164_),
    .B2(_156_),
    .A2(net34),
    .A1(_161_));
 sg13g2_inv_1 _402_ (.Y(_165_),
    .A(u_gpio_reg_tl_o_20_));
 sg13g2_inv_1 _403_ (.Y(_166_),
    .A(hw2reg_4_));
 sg13g2_o21ai_1 _404_ (.B1(net62),
    .Y(_167_),
    .A1(net61),
    .A2(_166_));
 sg13g2_o21ai_1 _405_ (.B1(_167_),
    .Y(_168_),
    .A1(reg2hw_4_),
    .A2(tl_i[62]));
 sg13g2_a22oi_1 _406_ (.Y(_049_),
    .B1(_168_),
    .B2(_156_),
    .A2(net34),
    .A1(_165_));
 sg13g2_inv_1 _407_ (.Y(_169_),
    .A(u_gpio_reg_tl_o_19_));
 sg13g2_nor2_1 _408_ (.A(tl_i[63]),
    .B(tl_i[62]),
    .Y(_170_));
 sg13g2_nand2b_1 _409_ (.Y(_171_),
    .B(net61),
    .A_N(reg2hw_3_));
 sg13g2_inv_1 _410_ (.Y(_172_),
    .A(hw2reg_3_));
 sg13g2_o21ai_1 _411_ (.B1(net62),
    .Y(_173_),
    .A1(net61),
    .A2(_172_));
 sg13g2_a22oi_1 _412_ (.Y(_174_),
    .B1(_171_),
    .B2(_173_),
    .A2(_170_),
    .A1(u_gpio_reg_u_reg_core_data_in_qs_3_));
 sg13g2_a22oi_1 _413_ (.Y(_050_),
    .B1(_174_),
    .B2(_156_),
    .A2(net34),
    .A1(_169_));
 sg13g2_inv_1 _414_ (.Y(_175_),
    .A(u_gpio_reg_tl_o_18_));
 sg13g2_nand2_1 _415_ (.Y(_176_),
    .A(_098_),
    .B(net61));
 sg13g2_inv_1 _416_ (.Y(_177_),
    .A(hw2reg_2_));
 sg13g2_o21ai_1 _417_ (.B1(net62),
    .Y(_178_),
    .A1(net61),
    .A2(_177_));
 sg13g2_a22oi_1 _418_ (.Y(_179_),
    .B1(_176_),
    .B2(_178_),
    .A2(_170_),
    .A1(u_gpio_reg_u_reg_core_data_in_qs_2_));
 sg13g2_a22oi_1 _419_ (.Y(_051_),
    .B1(_179_),
    .B2(_156_),
    .A2(net34),
    .A1(_175_));
 sg13g2_inv_1 _420_ (.Y(_180_),
    .A(u_gpio_reg_tl_o_17_));
 sg13g2_inv_1 _421_ (.Y(_181_),
    .A(hw2reg_1_));
 sg13g2_nand3_1 _422_ (.B(_181_),
    .C(tl_i[62]),
    .A(net62),
    .Y(_182_));
 sg13g2_a21o_1 _423_ (.A2(u_gpio_reg_u_reg_core_data_in_qs_1_),
    .A1(_104_),
    .B1(tl_i[62]),
    .X(_183_));
 sg13g2_a22oi_1 _424_ (.Y(_184_),
    .B1(_182_),
    .B2(_183_),
    .A2(_105_),
    .A1(reg2hw_1_));
 sg13g2_a22oi_1 _425_ (.Y(_052_),
    .B1(_184_),
    .B2(_156_),
    .A2(net34),
    .A1(_180_));
 sg13g2_inv_1 _426_ (.Y(_185_),
    .A(u_gpio_reg_tl_o_16_));
 sg13g2_inv_1 _427_ (.Y(_186_),
    .A(hw2reg_0_));
 sg13g2_nand3_1 _428_ (.B(_186_),
    .C(tl_i[62]),
    .A(net62),
    .Y(_187_));
 sg13g2_a21o_1 _429_ (.A2(u_gpio_reg_u_reg_core_data_in_qs_0_),
    .A1(_104_),
    .B1(tl_i[62]),
    .X(_188_));
 sg13g2_a22oi_1 _430_ (.Y(_189_),
    .B1(_187_),
    .B2(_188_),
    .A2(_105_),
    .A1(reg2hw_0_));
 sg13g2_a22oi_1 _431_ (.Y(_053_),
    .B1(_189_),
    .B2(_156_),
    .A2(net35),
    .A1(_185_));
 sg13g2_nor4_1 _432_ (.A(tl_i[63]),
    .B(_152_),
    .C(_103_),
    .D(_110_),
    .Y(_190_));
 sg13g2_buf_1 _433_ (.A(_190_),
    .X(_191_));
 sg13g2_nand2_1 _434_ (.Y(_192_),
    .A(net30),
    .B(tl_i[30]));
 sg13g2_o21ai_1 _435_ (.B1(_192_),
    .Y(_054_),
    .A1(_158_),
    .A2(net29));
 sg13g2_nand2_1 _436_ (.Y(_193_),
    .A(net30),
    .B(tl_i[29]));
 sg13g2_o21ai_1 _437_ (.B1(_193_),
    .Y(_055_),
    .A1(_162_),
    .A2(net29));
 sg13g2_nand2_1 _438_ (.Y(_194_),
    .A(net30),
    .B(tl_i[28]));
 sg13g2_o21ai_1 _439_ (.B1(_194_),
    .Y(_056_),
    .A1(_166_),
    .A2(net29));
 sg13g2_nand2_1 _440_ (.Y(_195_),
    .A(net30),
    .B(tl_i[26]));
 sg13g2_o21ai_1 _441_ (.B1(_195_),
    .Y(_057_),
    .A1(_177_),
    .A2(net29));
 sg13g2_nand2_1 _442_ (.Y(_196_),
    .A(net30),
    .B(tl_i[25]));
 sg13g2_o21ai_1 _443_ (.B1(_196_),
    .Y(_058_),
    .A1(_181_),
    .A2(net29));
 sg13g2_nand2_1 _444_ (.Y(_197_),
    .A(net30),
    .B(tl_i[24]));
 sg13g2_o21ai_1 _445_ (.B1(_197_),
    .Y(_059_),
    .A1(_186_),
    .A2(net29));
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
    .A(net43),
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
    .A(net38));
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
    .A(net39),
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
    .B(net38));
 sg13g2_inv_1 _470_ (.Y(_219_),
    .A(_215_));
 sg13g2_a21oi_1 _471_ (.A1(_217_),
    .A2(_218_),
    .Y(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_),
    .B1(_219_));
 sg13g2_a21oi_1 _472_ (.A1(_217_),
    .A2(net38),
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
    .A(net41));
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
    .A(net42),
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
    .A(net41),
    .B(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_));
 sg13g2_inv_1 _488_ (.Y(_232_),
    .A(_228_));
 sg13g2_a21oi_1 _489_ (.A1(_230_),
    .A2(_231_),
    .Y(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_),
    .B1(_232_));
 sg13g2_a21oi_1 _490_ (.A1(_230_),
    .A2(net41),
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
 sg13g2_mux2_1 _499_ (.A0(net43),
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
    .Y(u_gpio_core_intr_gpio_o_3_),
    .B1(_240_));
 sg13g2_o21ai_1 _505_ (.B1(_217_),
    .Y(_241_),
    .A1(_209_),
    .A2(net38));
 sg13g2_nand3b_1 _506_ (.B(_241_),
    .C(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
    .Y(_242_),
    .A_N(_216_));
 sg13g2_mux2_1 _507_ (.A0(net39),
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
 sg13g2_mux2_1 _510_ (.A0(net40),
    .A1(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .S(_244_),
    .X(_061_));
 sg13g2_o21ai_1 _511_ (.B1(_230_),
    .Y(_245_),
    .A1(net41),
    .A2(_223_));
 sg13g2_nand3b_1 _512_ (.B(_245_),
    .C(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
    .Y(_246_),
    .A_N(_229_));
 sg13g2_mux2_1 _513_ (.A0(net42),
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
 sg13g2_mux2_1 _516_ (.A0(net43),
    .A1(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .S(_248_),
    .X(_063_));
 sg13g2_nand2_1 _517_ (.Y(_249_),
    .A(net30),
    .B(tl_i[27]));
 sg13g2_o21ai_1 _518_ (.B1(_249_),
    .Y(_064_),
    .A1(_172_),
    .A2(net29));
 sg13g2_nand2_1 _519_ (.Y(_250_),
    .A(net30),
    .B(tl_i[31]));
 sg13g2_o21ai_1 _520_ (.B1(_250_),
    .Y(_065_),
    .A1(_151_),
    .A2(net29));
 sg13g2_nand2_1 _521_ (.Y(_251_),
    .A(net35),
    .B(u_gpio_reg_tl_o_1_));
 sg13g2_nand3b_1 _522_ (.B(_123_),
    .C(_251_),
    .Y(_066_),
    .A_N(_121_));
 sg13g2_o21ai_1 _523_ (.B1(net34),
    .Y(_067_),
    .A1(u_gpio_reg_tl_o_0_),
    .A2(tl_i[0]));
 sg13g2_inv_1 _524_ (.Y(_252_),
    .A(u_gpio_reg_tl_o_47_));
 sg13g2_o21ai_1 _525_ (.B1(net26),
    .Y(_068_),
    .A1(_252_),
    .A2(net33));
 sg13g2_mux2_1 _526_ (.A0(tl_i[99]),
    .A1(u_gpio_reg_tl_o_56_),
    .S(net37),
    .X(_069_));
 sg13g2_mux2_1 _527_ (.A0(tl_i[101]),
    .A1(u_gpio_reg_tl_o_58_),
    .S(net37),
    .X(_070_));
 sg13g2_mux2_1 _528_ (.A0(tl_i[31]),
    .A1(reg2hw_7_),
    .S(_113_),
    .X(_071_));
 sg13g2_mux2_1 _529_ (.A0(tl_i[43]),
    .A1(reg2hw_19_),
    .S(_113_),
    .X(_072_));
 sg13g2_mux2_1 _530_ (.A0(tl_i[35]),
    .A1(reg2hw_11_),
    .S(_113_),
    .X(_073_));
 sg13g2_mux2_1 _531_ (.A0(tl_i[39]),
    .A1(reg2hw_15_),
    .S(_113_),
    .X(_074_));
 sg13g2_mux2_1 _532_ (.A0(tl_i[27]),
    .A1(reg2hw_3_),
    .S(_113_),
    .X(_075_));
 sg13g2_inv_1 _533_ (.Y(_253_),
    .A(u_gpio_reg_tl_o_62_));
 sg13g2_o21ai_1 _534_ (.B1(_120_),
    .Y(_076_),
    .A1(_253_),
    .A2(net33));
 sg13g2_dfrbpq_1 _535_ (.RESET_B(net51),
    .D(_076_),
    .Q(u_gpio_reg_tl_o_62_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _536_ (.RESET_B(net44),
    .D(_060_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_stored_value_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _537_ (.RESET_B(net44),
    .D(_061_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_stored_value_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _538_ (.RESET_B(net44),
    .D(_062_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_stored_value_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _539_ (.RESET_B(net44),
    .D(_063_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_stored_value_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _540_ (.RESET_B(net49),
    .D(_059_),
    .Q(hw2reg_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _541_ (.RESET_B(net49),
    .D(_058_),
    .Q(hw2reg_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _542_ (.RESET_B(net49),
    .D(_057_),
    .Q(hw2reg_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _543_ (.RESET_B(net49),
    .D(_064_),
    .Q(hw2reg_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _544_ (.RESET_B(net49),
    .D(_056_),
    .Q(hw2reg_4_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _545_ (.RESET_B(net49),
    .D(_055_),
    .Q(hw2reg_5_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _546_ (.RESET_B(net49),
    .D(_054_),
    .Q(hw2reg_6_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _547_ (.RESET_B(net49),
    .D(_065_),
    .Q(hw2reg_7_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _548_ (.RESET_B(net51),
    .D(_066_),
    .Q(u_gpio_reg_tl_o_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _549_ (.RESET_B(net51),
    .D(_067_),
    .Q(u_gpio_reg_tl_o_65_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _550_ (.RESET_B(net51),
    .D(_053_),
    .Q(u_gpio_reg_tl_o_16_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _551_ (.RESET_B(net51),
    .D(_052_),
    .Q(u_gpio_reg_tl_o_17_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _552_ (.RESET_B(net51),
    .D(_051_),
    .Q(u_gpio_reg_tl_o_18_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _553_ (.RESET_B(net51),
    .D(_050_),
    .Q(u_gpio_reg_tl_o_19_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _554_ (.RESET_B(net51),
    .D(_049_),
    .Q(u_gpio_reg_tl_o_20_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _555_ (.RESET_B(net52),
    .D(_048_),
    .Q(u_gpio_reg_tl_o_21_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _556_ (.RESET_B(net52),
    .D(_047_),
    .Q(u_gpio_reg_tl_o_22_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _557_ (.RESET_B(net52),
    .D(_046_),
    .Q(u_gpio_reg_tl_o_23_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _558_ (.RESET_B(net52),
    .D(_045_),
    .Q(u_gpio_reg_tl_o_24_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _559_ (.RESET_B(net52),
    .D(_044_),
    .Q(u_gpio_reg_tl_o_25_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _560_ (.RESET_B(net52),
    .D(_043_),
    .Q(u_gpio_reg_tl_o_26_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _561_ (.RESET_B(net52),
    .D(_042_),
    .Q(u_gpio_reg_tl_o_27_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _562_ (.RESET_B(net52),
    .D(_041_),
    .Q(u_gpio_reg_tl_o_28_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _563_ (.RESET_B(net53),
    .D(_040_),
    .Q(u_gpio_reg_tl_o_29_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _564_ (.RESET_B(net53),
    .D(_039_),
    .Q(u_gpio_reg_tl_o_30_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _565_ (.RESET_B(net53),
    .D(_038_),
    .Q(u_gpio_reg_tl_o_31_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _566_ (.RESET_B(net53),
    .D(_037_),
    .Q(u_gpio_reg_tl_o_32_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _567_ (.RESET_B(net53),
    .D(_036_),
    .Q(u_gpio_reg_tl_o_33_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _568_ (.RESET_B(net53),
    .D(_035_),
    .Q(u_gpio_reg_tl_o_34_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _569_ (.RESET_B(net53),
    .D(_034_),
    .Q(u_gpio_reg_tl_o_35_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _570_ (.RESET_B(net53),
    .D(_033_),
    .Q(u_gpio_reg_tl_o_36_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _571_ (.RESET_B(net54),
    .D(_032_),
    .Q(u_gpio_reg_tl_o_37_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _572_ (.RESET_B(net54),
    .D(_031_),
    .Q(u_gpio_reg_tl_o_38_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _573_ (.RESET_B(net54),
    .D(_030_),
    .Q(u_gpio_reg_tl_o_39_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _574_ (.RESET_B(net54),
    .D(_029_),
    .Q(u_gpio_reg_tl_o_40_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _575_ (.RESET_B(net54),
    .D(_028_),
    .Q(u_gpio_reg_tl_o_41_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _576_ (.RESET_B(net54),
    .D(_027_),
    .Q(u_gpio_reg_tl_o_42_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _577_ (.RESET_B(net54),
    .D(_026_),
    .Q(u_gpio_reg_tl_o_43_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _578_ (.RESET_B(net54),
    .D(_025_),
    .Q(u_gpio_reg_tl_o_44_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _579_ (.RESET_B(net55),
    .D(_024_),
    .Q(u_gpio_reg_tl_o_45_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _580_ (.RESET_B(net55),
    .D(_023_),
    .Q(u_gpio_reg_tl_o_46_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _581_ (.RESET_B(net55),
    .D(_068_),
    .Q(u_gpio_reg_tl_o_47_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _582_ (.RESET_B(net55),
    .D(_022_),
    .Q(u_gpio_reg_tl_o_49_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _583_ (.RESET_B(net55),
    .D(_021_),
    .Q(u_gpio_reg_tl_o_50_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _584_ (.RESET_B(net55),
    .D(_020_),
    .Q(u_gpio_reg_tl_o_51_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _585_ (.RESET_B(net55),
    .D(_019_),
    .Q(u_gpio_reg_tl_o_52_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _586_ (.RESET_B(net55),
    .D(_018_),
    .Q(u_gpio_reg_tl_o_53_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _587_ (.RESET_B(net56),
    .D(_017_),
    .Q(u_gpio_reg_tl_o_54_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _588_ (.RESET_B(net56),
    .D(_016_),
    .Q(u_gpio_reg_tl_o_55_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _589_ (.RESET_B(net56),
    .D(_069_),
    .Q(u_gpio_reg_tl_o_56_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _590_ (.RESET_B(net56),
    .D(_015_),
    .Q(u_gpio_reg_tl_o_57_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _591_ (.RESET_B(net56),
    .D(_070_),
    .Q(u_gpio_reg_tl_o_58_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _592_ (.RESET_B(net56),
    .D(_014_),
    .Q(reg2hw_4_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _593_ (.RESET_B(net56),
    .D(_013_),
    .Q(reg2hw_5_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _594_ (.RESET_B(net56),
    .D(_012_),
    .Q(reg2hw_6_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _595_ (.RESET_B(net57),
    .D(_071_),
    .Q(reg2hw_7_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _596_ (.RESET_B(net57),
    .D(_011_),
    .Q(reg2hw_16_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _597_ (.RESET_B(net57),
    .D(_010_),
    .Q(reg2hw_17_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _598_ (.RESET_B(net57),
    .D(_009_),
    .Q(reg2hw_18_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _599_ (.RESET_B(net57),
    .D(_072_),
    .Q(reg2hw_19_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _600_ (.RESET_B(net57),
    .D(_008_),
    .Q(reg2hw_8_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _601_ (.RESET_B(net57),
    .D(_007_),
    .Q(reg2hw_9_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _602_ (.RESET_B(net57),
    .D(_006_),
    .Q(reg2hw_10_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _603_ (.RESET_B(net58),
    .D(_073_),
    .Q(reg2hw_11_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _604_ (.RESET_B(net58),
    .D(_005_),
    .Q(reg2hw_12_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _605_ (.RESET_B(net58),
    .D(_004_),
    .Q(reg2hw_13_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _606_ (.RESET_B(net58),
    .D(_003_),
    .Q(reg2hw_14_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _607_ (.RESET_B(net58),
    .D(_074_),
    .Q(reg2hw_15_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _608_ (.RESET_B(net58),
    .D(_002_),
    .Q(reg2hw_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _609_ (.RESET_B(net58),
    .D(_001_),
    .Q(reg2hw_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _610_ (.RESET_B(net58),
    .D(_000_),
    .Q(reg2hw_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _611_ (.RESET_B(net59),
    .D(_075_),
    .Q(reg2hw_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _612_ (.RESET_B(rst_ni),
    .D(u_reg_reset_sync_intq),
    .Q(reg_rst_ni),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _613_ (.RESET_B(rst_ni),
    .D(net20),
    .Q(u_reg_reset_sync_intq),
    .CLK(clk_i));
 sg13g2_tiehi _613__21 (.L_HI(net20));
 sg13g2_dfrbpq_1 _614_ (.RESET_B(net59),
    .D(hw2reg_9_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _615_ (.RESET_B(net59),
    .D(hw2reg_10_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _616_ (.RESET_B(net59),
    .D(hw2reg_11_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _617_ (.RESET_B(net59),
    .D(hw2reg_12_),
    .Q(u_gpio_reg_u_reg_core_data_in_qs_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _618_ (.RESET_B(core_rst_ni),
    .D(net21),
    .Q(u_gpio_core_state_rst_ni),
    .CLK(clk_i));
 sg13g2_tiehi _618__22 (.L_HI(net21));
 sg13g2_dfrbpq_1 _619_ (.RESET_B(core_rst_ni),
    .D(net22),
    .Q(u_gpio_core_filter_rst_ni),
    .CLK(clk_i));
 sg13g2_tiehi _619__23 (.L_HI(net22));
 sg13g2_dfrbpq_1 _620_ (.RESET_B(net44),
    .D(u_gpio_core_gen_input_filter_3__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _621_ (.RESET_B(net44),
    .D(cio_gpio_i[3]),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_gen_async_prim_flop_2sync_intq),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _622_ (.RESET_B(net44),
    .D(net43),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_filter_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _623_ (.RESET_B(net44),
    .D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _624_ (.RESET_B(net45),
    .D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _625_ (.RESET_B(net45),
    .D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _626_ (.RESET_B(net45),
    .D(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_3__u_filter_diff_ctr_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _627_ (.RESET_B(net45),
    .D(u_gpio_core_gen_input_filter_2__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _628_ (.RESET_B(net45),
    .D(cio_gpio_i[2]),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_gen_async_prim_flop_2sync_intq),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _629_ (.RESET_B(net45),
    .D(net42),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_filter_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _630_ (.RESET_B(net45),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _631_ (.RESET_B(net45),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _632_ (.RESET_B(net46),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _633_ (.RESET_B(net46),
    .D(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _634_ (.RESET_B(net46),
    .D(u_gpio_core_gen_input_filter_1__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _635_ (.RESET_B(net46),
    .D(cio_gpio_i[1]),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_gen_async_prim_flop_2sync_intq),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _636_ (.RESET_B(net46),
    .D(net40),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_filter_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _637_ (.RESET_B(net46),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _638_ (.RESET_B(net46),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _639_ (.RESET_B(net46),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _640_ (.RESET_B(net47),
    .D(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_1__u_filter_diff_ctr_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _641_ (.RESET_B(net47),
    .D(u_gpio_core_gen_input_filter_0__u_filter_gen_async_prim_flop_2sync_intq),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _642_ (.RESET_B(net47),
    .D(cio_gpio_i[0]),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_gen_async_prim_flop_2sync_intq),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _643_ (.RESET_B(net47),
    .D(net39),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_filter_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _644_ (.RESET_B(net47),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_0_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _645_ (.RESET_B(net47),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_1_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _646_ (.RESET_B(net47),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_2_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _647_ (.RESET_B(net47),
    .D(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_d_3_),
    .Q(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _648_ (.RESET_B(net50),
    .D(hw2reg_9_),
    .Q(u_gpio_core_data_in_q_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _649_ (.RESET_B(net50),
    .D(hw2reg_10_),
    .Q(u_gpio_core_data_in_q_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _650_ (.RESET_B(net50),
    .D(hw2reg_11_),
    .Q(u_gpio_core_data_in_q_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _651_ (.RESET_B(net50),
    .D(hw2reg_12_),
    .Q(u_gpio_core_data_in_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _652_ (.RESET_B(rst_ni),
    .D(u_core_reset_sync_intq),
    .Q(core_rst_ni),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _653_ (.RESET_B(rst_ni),
    .D(net23),
    .Q(u_core_reset_sync_intq),
    .CLK(clk_i));
 sg13g2_tiehi _653__24 (.L_HI(net23));
 sg13g2_buf_1 _656_ (.A(u_gpio_reg_tl_o_0_),
    .X(tl_o[0]));
 sg13g2_buf_1 _657_ (.A(u_gpio_reg_tl_o_1_),
    .X(tl_o[1]));
 sg13g2_buf_1 _658_ (.A(net),
    .X(tl_o[2]));
 sg13g2_tielo _658__1 (.L_LO(net));
 sg13g2_buf_1 _659_ (.A(net1),
    .X(tl_o[3]));
 sg13g2_tielo _659__2 (.L_LO(net1));
 sg13g2_buf_1 _660_ (.A(net2),
    .X(tl_o[4]));
 sg13g2_tielo _660__3 (.L_LO(net2));
 sg13g2_buf_1 _661_ (.A(net3),
    .X(tl_o[5]));
 sg13g2_tielo _661__4 (.L_LO(net3));
 sg13g2_buf_1 _662_ (.A(net4),
    .X(tl_o[6]));
 sg13g2_tielo _662__5 (.L_LO(net4));
 sg13g2_buf_1 _663_ (.A(net5),
    .X(tl_o[7]));
 sg13g2_tielo _663__6 (.L_LO(net5));
 sg13g2_buf_1 _664_ (.A(net6),
    .X(tl_o[8]));
 sg13g2_tielo _664__7 (.L_LO(net6));
 sg13g2_buf_1 _665_ (.A(net7),
    .X(tl_o[9]));
 sg13g2_tielo _665__8 (.L_LO(net7));
 sg13g2_buf_1 _666_ (.A(net8),
    .X(tl_o[10]));
 sg13g2_tielo _666__9 (.L_LO(net8));
 sg13g2_buf_1 _667_ (.A(net9),
    .X(tl_o[11]));
 sg13g2_tielo _667__10 (.L_LO(net9));
 sg13g2_buf_1 _668_ (.A(net10),
    .X(tl_o[12]));
 sg13g2_tielo _668__11 (.L_LO(net10));
 sg13g2_buf_1 _669_ (.A(net11),
    .X(tl_o[13]));
 sg13g2_tielo _669__12 (.L_LO(net11));
 sg13g2_buf_1 _670_ (.A(net12),
    .X(tl_o[14]));
 sg13g2_tielo _670__13 (.L_LO(net12));
 sg13g2_buf_1 _671_ (.A(net13),
    .X(tl_o[15]));
 sg13g2_tielo _671__14 (.L_LO(net13));
 sg13g2_buf_1 _672_ (.A(u_gpio_reg_tl_o_16_),
    .X(tl_o[16]));
 sg13g2_buf_1 _673_ (.A(u_gpio_reg_tl_o_17_),
    .X(tl_o[17]));
 sg13g2_buf_1 _674_ (.A(u_gpio_reg_tl_o_18_),
    .X(tl_o[18]));
 sg13g2_buf_1 _675_ (.A(u_gpio_reg_tl_o_19_),
    .X(tl_o[19]));
 sg13g2_buf_1 _676_ (.A(u_gpio_reg_tl_o_20_),
    .X(tl_o[20]));
 sg13g2_buf_1 _677_ (.A(u_gpio_reg_tl_o_21_),
    .X(tl_o[21]));
 sg13g2_buf_1 _678_ (.A(u_gpio_reg_tl_o_22_),
    .X(tl_o[22]));
 sg13g2_buf_1 _679_ (.A(u_gpio_reg_tl_o_23_),
    .X(tl_o[23]));
 sg13g2_buf_1 _680_ (.A(u_gpio_reg_tl_o_24_),
    .X(tl_o[24]));
 sg13g2_buf_1 _681_ (.A(u_gpio_reg_tl_o_25_),
    .X(tl_o[25]));
 sg13g2_buf_1 _682_ (.A(u_gpio_reg_tl_o_26_),
    .X(tl_o[26]));
 sg13g2_buf_1 _683_ (.A(u_gpio_reg_tl_o_27_),
    .X(tl_o[27]));
 sg13g2_buf_1 _684_ (.A(u_gpio_reg_tl_o_28_),
    .X(tl_o[28]));
 sg13g2_buf_1 _685_ (.A(u_gpio_reg_tl_o_29_),
    .X(tl_o[29]));
 sg13g2_buf_1 _686_ (.A(u_gpio_reg_tl_o_30_),
    .X(tl_o[30]));
 sg13g2_buf_1 _687_ (.A(u_gpio_reg_tl_o_31_),
    .X(tl_o[31]));
 sg13g2_buf_1 _688_ (.A(u_gpio_reg_tl_o_32_),
    .X(tl_o[32]));
 sg13g2_buf_1 _689_ (.A(u_gpio_reg_tl_o_33_),
    .X(tl_o[33]));
 sg13g2_buf_1 _690_ (.A(u_gpio_reg_tl_o_34_),
    .X(tl_o[34]));
 sg13g2_buf_1 _691_ (.A(u_gpio_reg_tl_o_35_),
    .X(tl_o[35]));
 sg13g2_buf_1 _692_ (.A(u_gpio_reg_tl_o_36_),
    .X(tl_o[36]));
 sg13g2_buf_1 _693_ (.A(u_gpio_reg_tl_o_37_),
    .X(tl_o[37]));
 sg13g2_buf_1 _694_ (.A(u_gpio_reg_tl_o_38_),
    .X(tl_o[38]));
 sg13g2_buf_1 _695_ (.A(u_gpio_reg_tl_o_39_),
    .X(tl_o[39]));
 sg13g2_buf_1 _696_ (.A(u_gpio_reg_tl_o_40_),
    .X(tl_o[40]));
 sg13g2_buf_1 _697_ (.A(u_gpio_reg_tl_o_41_),
    .X(tl_o[41]));
 sg13g2_buf_1 _698_ (.A(u_gpio_reg_tl_o_42_),
    .X(tl_o[42]));
 sg13g2_buf_1 _699_ (.A(u_gpio_reg_tl_o_43_),
    .X(tl_o[43]));
 sg13g2_buf_1 _700_ (.A(u_gpio_reg_tl_o_44_),
    .X(tl_o[44]));
 sg13g2_buf_1 _701_ (.A(u_gpio_reg_tl_o_45_),
    .X(tl_o[45]));
 sg13g2_buf_1 _702_ (.A(u_gpio_reg_tl_o_46_),
    .X(tl_o[46]));
 sg13g2_buf_1 _703_ (.A(u_gpio_reg_tl_o_47_),
    .X(tl_o[47]));
 sg13g2_buf_1 _704_ (.A(net14),
    .X(tl_o[48]));
 sg13g2_tielo _704__15 (.L_LO(net14));
 sg13g2_buf_1 _705_ (.A(u_gpio_reg_tl_o_49_),
    .X(tl_o[49]));
 sg13g2_buf_1 _706_ (.A(u_gpio_reg_tl_o_50_),
    .X(tl_o[50]));
 sg13g2_buf_1 _707_ (.A(u_gpio_reg_tl_o_51_),
    .X(tl_o[51]));
 sg13g2_buf_1 _708_ (.A(u_gpio_reg_tl_o_52_),
    .X(tl_o[52]));
 sg13g2_buf_1 _709_ (.A(u_gpio_reg_tl_o_53_),
    .X(tl_o[53]));
 sg13g2_buf_1 _710_ (.A(u_gpio_reg_tl_o_54_),
    .X(tl_o[54]));
 sg13g2_buf_1 _711_ (.A(u_gpio_reg_tl_o_55_),
    .X(tl_o[55]));
 sg13g2_buf_1 _712_ (.A(u_gpio_reg_tl_o_56_),
    .X(tl_o[56]));
 sg13g2_buf_1 _713_ (.A(u_gpio_reg_tl_o_57_),
    .X(tl_o[57]));
 sg13g2_buf_1 _714_ (.A(u_gpio_reg_tl_o_58_),
    .X(tl_o[58]));
 sg13g2_buf_1 _715_ (.A(net15),
    .X(tl_o[59]));
 sg13g2_tielo _715__16 (.L_LO(net15));
 sg13g2_buf_1 _716_ (.A(net16),
    .X(tl_o[60]));
 sg13g2_tielo _716__17 (.L_LO(net16));
 sg13g2_buf_1 _717_ (.A(net17),
    .X(tl_o[61]));
 sg13g2_tielo _717__18 (.L_LO(net17));
 sg13g2_buf_1 _718_ (.A(u_gpio_reg_tl_o_62_),
    .X(tl_o[62]));
 sg13g2_buf_1 _719_ (.A(net18),
    .X(tl_o[63]));
 sg13g2_tielo _719__19 (.L_LO(net18));
 sg13g2_buf_1 _720_ (.A(net19),
    .X(tl_o[64]));
 sg13g2_tielo _720__20 (.L_LO(net19));
 sg13g2_buf_1 _721_ (.A(u_gpio_reg_tl_o_65_),
    .X(tl_o[65]));
 sg13g2_buf_1 _722_ (.A(u_gpio_core_intr_gpio_o_0_),
    .X(intr_gpio_o[0]));
 sg13g2_buf_1 _723_ (.A(u_gpio_core_intr_gpio_o_1_),
    .X(intr_gpio_o[1]));
 sg13g2_buf_1 _724_ (.A(u_gpio_core_intr_gpio_o_2_),
    .X(intr_gpio_o[2]));
 sg13g2_buf_1 _725_ (.A(u_gpio_core_intr_gpio_o_3_),
    .X(intr_gpio_o[3]));
 sg13g2_buf_1 _726_ (.A(hw2reg_0_),
    .X(cio_gpio_o[0]));
 sg13g2_buf_1 _727_ (.A(hw2reg_1_),
    .X(cio_gpio_o[1]));
 sg13g2_buf_1 _728_ (.A(hw2reg_2_),
    .X(cio_gpio_o[2]));
 sg13g2_buf_1 _729_ (.A(hw2reg_3_),
    .X(cio_gpio_o[3]));
 sg13g2_buf_1 _730_ (.A(hw2reg_4_),
    .X(cio_gpio_en_o[0]));
 sg13g2_buf_1 _731_ (.A(hw2reg_5_),
    .X(cio_gpio_en_o[1]));
 sg13g2_buf_1 _732_ (.A(hw2reg_6_),
    .X(cio_gpio_en_o[2]));
 sg13g2_buf_1 _733_ (.A(hw2reg_7_),
    .X(cio_gpio_en_o[3]));
 sg13g2_buf_4 gain25 (.X(net24),
    .A(_126_));
 sg13g2_buf_4 gain26 (.X(net25),
    .A(_126_));
 sg13g2_buf_4 gain27 (.X(net26),
    .A(_126_));
 sg13g2_buf_8 gain28 (.A(_113_),
    .X(net27));
 sg13g2_buf_8 gain29 (.A(_113_),
    .X(net28));
 sg13g2_buf_4 gain30 (.X(net29),
    .A(_191_));
 sg13g2_buf_4 gain31 (.X(net30),
    .A(_191_));
 sg13g2_buf_4 gain32 (.X(net31),
    .A(_137_));
 sg13g2_buf_4 gain33 (.X(net32),
    .A(net33));
 sg13g2_buf_4 gain34 (.X(net33),
    .A(_117_));
 sg13g2_buf_4 gain35 (.X(net34),
    .A(_115_));
 sg13g2_buf_4 gain36 (.X(net35),
    .A(_115_));
 sg13g2_buf_4 gain37 (.X(net36),
    .A(_115_));
 sg13g2_buf_8 gain38 (.A(_115_),
    .X(net37));
 sg13g2_buf_1 gain39 (.A(u_gpio_core_gen_input_filter_0__u_filter_diff_ctr_q_0_),
    .X(net38));
 sg13g2_buf_1 gain40 (.A(u_gpio_core_gen_input_filter_0__u_filter_filter_synced),
    .X(net39));
 sg13g2_buf_1 gain41 (.A(u_gpio_core_gen_input_filter_1__u_filter_filter_synced),
    .X(net40));
 sg13g2_buf_1 gain42 (.A(u_gpio_core_gen_input_filter_2__u_filter_diff_ctr_q_0_),
    .X(net41));
 sg13g2_buf_1 gain43 (.A(u_gpio_core_gen_input_filter_2__u_filter_filter_synced),
    .X(net42));
 sg13g2_buf_1 gain44 (.A(u_gpio_core_gen_input_filter_3__u_filter_filter_synced),
    .X(net43));
 sg13g2_buf_8 gain45 (.A(net48),
    .X(net44));
 sg13g2_buf_8 gain46 (.A(net48),
    .X(net45));
 sg13g2_buf_8 gain47 (.A(net48),
    .X(net46));
 sg13g2_buf_8 gain48 (.A(net48),
    .X(net47));
 sg13g2_buf_8 gain49 (.A(u_gpio_core_filter_rst_ni),
    .X(net48));
 sg13g2_buf_8 gain50 (.A(net50),
    .X(net49));
 sg13g2_buf_4 gain51 (.X(net50),
    .A(u_gpio_core_state_rst_ni));
 sg13g2_buf_8 gain52 (.A(net59),
    .X(net51));
 sg13g2_buf_8 gain53 (.A(net59),
    .X(net52));
 sg13g2_buf_8 gain54 (.A(net59),
    .X(net53));
 sg13g2_buf_8 gain55 (.A(net60),
    .X(net54));
 sg13g2_buf_8 gain56 (.A(net60),
    .X(net55));
 sg13g2_buf_8 gain57 (.A(net60),
    .X(net56));
 sg13g2_buf_8 gain58 (.A(net60),
    .X(net57));
 sg13g2_buf_8 gain59 (.A(net60),
    .X(net58));
 sg13g2_buf_8 gain60 (.A(net60),
    .X(net59));
 sg13g2_buf_8 gain61 (.A(reg_rst_ni),
    .X(net60));
 sg13g2_buf_4 gain62 (.X(net61),
    .A(_152_));
 sg13g2_buf_4 gain63 (.X(net62),
    .A(_104_));
endmodule
