module my_ip (clk_i,
    port_i,
    port_o,
    rst_ni,
    tl_i,
    tl_o);
 input clk_i;
 input port_i;
 output port_o;
 input rst_ni;
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
 wire net53;
 wire _057_;
 wire _058_;
 wire _059_;
 wire _060_;
 wire _061_;
 wire _062_;
 wire _063_;
 wire _064_;
 wire net52;
 wire _066_;
 wire _067_;
 wire _068_;
 wire _069_;
 wire net51;
 wire _071_;
 wire net50;
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
 wire net49;
 wire _128_;
 wire net48;
 wire net47;
 wire _131_;
 wire _132_;
 wire _133_;
 wire _134_;
 wire _135_;
 wire _136_;
 wire _137_;
 wire net46;
 wire net45;
 wire net44;
 wire _141_;
 wire net43;
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
 wire net42;
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
 wire net63;
 wire \reg2hw[22] ;
 wire \reg2hw[23] ;
 wire \reg2hw[24] ;
 wire \reg2hw[25] ;
 wire \reg2hw[26] ;
 wire \reg2hw[27] ;
 wire \reg2hw[28] ;
 wire \reg2hw[29] ;
 wire \reg2hw[30] ;
 wire \reg2hw[31] ;
 wire \reg2hw[32] ;
 wire \reg2hw[33] ;
 wire \reg2hw[34] ;
 wire \reg2hw[35] ;
 wire \reg2hw[36] ;
 wire \reg2hw[37] ;
 wire \reg2hw[38] ;
 wire \reg2hw[39] ;
 wire net64;
 wire net65;
 wire net66;
 wire net69;
 wire net73;
 wire clknet_2_3__leaf_clk_i;
 wire clknet_2_2__leaf_clk_i;
 wire clknet_2_1__leaf_clk_i;
 wire clknet_2_0__leaf_clk_i;
 wire net113;
 wire clknet_0_clk_i;
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
 wire net108;
 wire net109;
 wire \u_my_ip_core.u_sync_name.intq ;
 wire net41;
 wire net20;
 wire net40;
 wire net39;
 wire net38;
 wire net37;
 wire net36;
 wire net35;
 wire net34;
 wire net33;
 wire net32;
 wire net31;
 wire net30;
 wire net29;
 wire net28;
 wire net27;
 wire net26;
 wire net25;
 wire net24;
 wire net23;
 wire net22;
 wire net21;
 wire net54;
 wire net55;
 wire net56;
 wire net57;
 wire net58;
 wire net59;
 wire net60;
 wire net61;
 wire net62;
 wire net112;

 sky130_fd_sc_hd__inv_1 _203_ (.A(net28),
    .Y(_051_));
 sky130_fd_sc_hd__nor2_4 _204_ (.A(net109),
    .B(_051_),
    .Y(_052_));
 sky130_fd_sc_hd__nor2_8 _205_ (.A(net54),
    .B(net53),
    .Y(_053_));
 sky130_fd_sc_hd__nor2_1 _206_ (.A(net27),
    .B(net26),
    .Y(_054_));
 sky130_fd_sc_hd__nand3_4 _207_ (.A(_052_),
    .B(_053_),
    .C(_054_),
    .Y(_055_));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input54 (.A(tl_i[62]),
    .X(net53));
 sky130_fd_sc_hd__inv_1 _209_ (.A(net47),
    .Y(_057_));
 sky130_fd_sc_hd__inv_1 _210_ (.A(net52),
    .Y(_058_));
 sky130_fd_sc_hd__inv_1 _211_ (.A(net51),
    .Y(_059_));
 sky130_fd_sc_hd__nand2_1 _212_ (.A(_058_),
    .B(_059_),
    .Y(_060_));
 sky130_fd_sc_hd__nor2_1 _213_ (.A(_057_),
    .B(_060_),
    .Y(_061_));
 sky130_fd_sc_hd__nand3_1 _214_ (.A(net48),
    .B(net50),
    .C(net49),
    .Y(_062_));
 sky130_fd_sc_hd__nand2_2 _215_ (.A(_062_),
    .B(_053_),
    .Y(_063_));
 sky130_fd_sc_hd__nand2_4 _216_ (.A(_061_),
    .B(_063_),
    .Y(_064_));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input53 (.A(tl_i[61]),
    .X(net52));
 sky130_fd_sc_hd__inv_1 _218_ (.A(\reg2hw[22] ),
    .Y(_066_));
 sky130_fd_sc_hd__o21bai_1 _219_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_066_),
    .Y(_067_));
 sky130_fd_sc_hd__nand3_1 _220_ (.A(_058_),
    .B(_059_),
    .C(net47),
    .Y(_068_));
 sky130_fd_sc_hd__a21oi_4 _221_ (.A1(_062_),
    .A2(_053_),
    .B1(_068_),
    .Y(_069_));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input52 (.A(tl_i[60]),
    .X(net51));
 sky130_fd_sc_hd__clkinv_4 _223_ (.A(_055_),
    .Y(_071_));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input51 (.A(tl_i[59]),
    .X(net50));
 sky130_fd_sc_hd__nand3_1 _225_ (.A(_069_),
    .B(net29),
    .C(_071_),
    .Y(_073_));
 sky130_fd_sc_hd__nand2_1 _226_ (.A(_067_),
    .B(_073_),
    .Y(_000_));
 sky130_fd_sc_hd__inv_1 _227_ (.A(\reg2hw[23] ),
    .Y(_074_));
 sky130_fd_sc_hd__o21bai_1 _228_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_074_),
    .Y(_075_));
 sky130_fd_sc_hd__nand3_1 _229_ (.A(_069_),
    .B(net30),
    .C(_071_),
    .Y(_076_));
 sky130_fd_sc_hd__nand2_1 _230_ (.A(_075_),
    .B(_076_),
    .Y(_001_));
 sky130_fd_sc_hd__inv_1 _231_ (.A(\reg2hw[24] ),
    .Y(_077_));
 sky130_fd_sc_hd__o21bai_1 _232_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_077_),
    .Y(_078_));
 sky130_fd_sc_hd__nand3_1 _233_ (.A(_069_),
    .B(net31),
    .C(_071_),
    .Y(_079_));
 sky130_fd_sc_hd__nand2_1 _234_ (.A(_078_),
    .B(_079_),
    .Y(_002_));
 sky130_fd_sc_hd__inv_1 _235_ (.A(\reg2hw[34] ),
    .Y(_080_));
 sky130_fd_sc_hd__o21bai_1 _236_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_080_),
    .Y(_081_));
 sky130_fd_sc_hd__nand3_1 _237_ (.A(_069_),
    .B(net41),
    .C(_071_),
    .Y(_082_));
 sky130_fd_sc_hd__nand2_1 _238_ (.A(_081_),
    .B(_082_),
    .Y(_003_));
 sky130_fd_sc_hd__inv_1 _239_ (.A(\reg2hw[35] ),
    .Y(_083_));
 sky130_fd_sc_hd__o21bai_1 _240_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_083_),
    .Y(_084_));
 sky130_fd_sc_hd__nand3_1 _241_ (.A(_069_),
    .B(net42),
    .C(_071_),
    .Y(_085_));
 sky130_fd_sc_hd__nand2_1 _242_ (.A(_084_),
    .B(_085_),
    .Y(_004_));
 sky130_fd_sc_hd__inv_1 _243_ (.A(\reg2hw[36] ),
    .Y(_086_));
 sky130_fd_sc_hd__o21bai_1 _244_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_086_),
    .Y(_087_));
 sky130_fd_sc_hd__nand3_1 _245_ (.A(_069_),
    .B(net43),
    .C(_071_),
    .Y(_088_));
 sky130_fd_sc_hd__nand2_1 _246_ (.A(_087_),
    .B(_088_),
    .Y(_005_));
 sky130_fd_sc_hd__inv_1 _247_ (.A(\reg2hw[37] ),
    .Y(_089_));
 sky130_fd_sc_hd__o21bai_1 _248_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_089_),
    .Y(_090_));
 sky130_fd_sc_hd__nand3_1 _249_ (.A(_069_),
    .B(net44),
    .C(_071_),
    .Y(_091_));
 sky130_fd_sc_hd__nand2_1 _250_ (.A(_090_),
    .B(_091_),
    .Y(_006_));
 sky130_fd_sc_hd__inv_1 _251_ (.A(\reg2hw[38] ),
    .Y(_092_));
 sky130_fd_sc_hd__o21bai_1 _252_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_092_),
    .Y(_093_));
 sky130_fd_sc_hd__nand3_1 _253_ (.A(_069_),
    .B(net45),
    .C(_071_),
    .Y(_094_));
 sky130_fd_sc_hd__nand2_1 _254_ (.A(_093_),
    .B(_094_),
    .Y(_007_));
 sky130_fd_sc_hd__inv_1 _255_ (.A(\reg2hw[39] ),
    .Y(_095_));
 sky130_fd_sc_hd__o21bai_1 _256_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_095_),
    .Y(_096_));
 sky130_fd_sc_hd__nand3_1 _257_ (.A(_069_),
    .B(net46),
    .C(_071_),
    .Y(_097_));
 sky130_fd_sc_hd__nand2_1 _258_ (.A(_096_),
    .B(_097_),
    .Y(_008_));
 sky130_fd_sc_hd__inv_1 _259_ (.A(\reg2hw[25] ),
    .Y(_098_));
 sky130_fd_sc_hd__o21bai_1 _260_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_098_),
    .Y(_099_));
 sky130_fd_sc_hd__nand3_1 _261_ (.A(_069_),
    .B(net32),
    .C(_071_),
    .Y(_100_));
 sky130_fd_sc_hd__nand2_1 _262_ (.A(_099_),
    .B(_100_),
    .Y(_009_));
 sky130_fd_sc_hd__inv_1 _263_ (.A(\reg2hw[26] ),
    .Y(_101_));
 sky130_fd_sc_hd__o21bai_1 _264_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_101_),
    .Y(_102_));
 sky130_fd_sc_hd__nand3_1 _265_ (.A(_069_),
    .B(net33),
    .C(_071_),
    .Y(_103_));
 sky130_fd_sc_hd__nand2_1 _266_ (.A(_102_),
    .B(_103_),
    .Y(_010_));
 sky130_fd_sc_hd__inv_1 _267_ (.A(\reg2hw[27] ),
    .Y(_104_));
 sky130_fd_sc_hd__o21bai_1 _268_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_104_),
    .Y(_105_));
 sky130_fd_sc_hd__nand3_1 _269_ (.A(_069_),
    .B(net34),
    .C(_071_),
    .Y(_106_));
 sky130_fd_sc_hd__nand2_1 _270_ (.A(_105_),
    .B(_106_),
    .Y(_011_));
 sky130_fd_sc_hd__inv_1 _271_ (.A(\reg2hw[28] ),
    .Y(_107_));
 sky130_fd_sc_hd__o21bai_1 _272_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_107_),
    .Y(_108_));
 sky130_fd_sc_hd__nand3_1 _273_ (.A(_069_),
    .B(net35),
    .C(_071_),
    .Y(_109_));
 sky130_fd_sc_hd__nand2_1 _274_ (.A(_108_),
    .B(_109_),
    .Y(_012_));
 sky130_fd_sc_hd__inv_1 _275_ (.A(\reg2hw[29] ),
    .Y(_110_));
 sky130_fd_sc_hd__o21bai_1 _276_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_110_),
    .Y(_111_));
 sky130_fd_sc_hd__nand3_1 _277_ (.A(_069_),
    .B(net36),
    .C(_071_),
    .Y(_112_));
 sky130_fd_sc_hd__nand2_1 _278_ (.A(_111_),
    .B(_112_),
    .Y(_013_));
 sky130_fd_sc_hd__inv_1 _279_ (.A(\reg2hw[30] ),
    .Y(_113_));
 sky130_fd_sc_hd__o21bai_1 _280_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_113_),
    .Y(_114_));
 sky130_fd_sc_hd__nand3_1 _281_ (.A(_069_),
    .B(net37),
    .C(_071_),
    .Y(_115_));
 sky130_fd_sc_hd__nand2_1 _282_ (.A(_114_),
    .B(_115_),
    .Y(_014_));
 sky130_fd_sc_hd__inv_1 _283_ (.A(\reg2hw[31] ),
    .Y(_116_));
 sky130_fd_sc_hd__o21bai_1 _284_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_116_),
    .Y(_117_));
 sky130_fd_sc_hd__nand3_1 _285_ (.A(_069_),
    .B(net38),
    .C(_071_),
    .Y(_118_));
 sky130_fd_sc_hd__nand2_1 _286_ (.A(_117_),
    .B(_118_),
    .Y(_015_));
 sky130_fd_sc_hd__inv_1 _287_ (.A(\reg2hw[32] ),
    .Y(_119_));
 sky130_fd_sc_hd__o21bai_1 _288_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_119_),
    .Y(_120_));
 sky130_fd_sc_hd__nand3_1 _289_ (.A(_069_),
    .B(net39),
    .C(_071_),
    .Y(_121_));
 sky130_fd_sc_hd__nand2_1 _290_ (.A(_120_),
    .B(_121_),
    .Y(_016_));
 sky130_fd_sc_hd__inv_1 _291_ (.A(\reg2hw[33] ),
    .Y(_122_));
 sky130_fd_sc_hd__o21bai_1 _292_ (.A1(_055_),
    .A2(_064_),
    .B1_N(_122_),
    .Y(_123_));
 sky130_fd_sc_hd__nand3_1 _293_ (.A(_069_),
    .B(net40),
    .C(_071_),
    .Y(_124_));
 sky130_fd_sc_hd__nand2_1 _294_ (.A(_123_),
    .B(_124_),
    .Y(_017_));
 sky130_fd_sc_hd__nand2_1 _295_ (.A(_052_),
    .B(_054_),
    .Y(_125_));
 sky130_fd_sc_hd__inv_1 _296_ (.A(_052_),
    .Y(_126_));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input50 (.A(tl_i[58]),
    .X(net49));
 sky130_fd_sc_hd__nand2_1 _298_ (.A(net112),
    .B(net69),
    .Y(_128_));
 sky130_fd_sc_hd__o21ai_0 _299_ (.A1(_125_),
    .A2(_069_),
    .B1(_128_),
    .Y(_018_));
 sky130_fd_sc_hd__inv_1 _300_ (.A(net109),
    .Y(net64));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input49 (.A(tl_i[57]),
    .X(net48));
 sky130_fd_sc_hd__o21ai_0 _302_ (.A1(net22),
    .A2(net64),
    .B1(_126_),
    .Y(_019_));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input48 (.A(tl_i[56]),
    .X(net47));
 sky130_fd_sc_hd__nor2_1 _304_ (.A(net65),
    .B(_052_),
    .Y(_131_));
 sky130_fd_sc_hd__inv_1 _305_ (.A(net53),
    .Y(_132_));
 sky130_fd_sc_hd__a21oi_1 _306_ (.A1(_132_),
    .A2(_066_),
    .B1(net54),
    .Y(_133_));
 sky130_fd_sc_hd__nand2_1 _307_ (.A(_132_),
    .B(net54),
    .Y(_134_));
 sky130_fd_sc_hd__nand3_1 _308_ (.A(_125_),
    .B(_134_),
    .C(_052_),
    .Y(_135_));
 sky130_fd_sc_hd__nor2_1 _309_ (.A(_133_),
    .B(_135_),
    .Y(_136_));
 sky130_fd_sc_hd__nor2_1 _310_ (.A(_131_),
    .B(_136_),
    .Y(_020_));
 sky130_fd_sc_hd__nand2_1 _311_ (.A(_126_),
    .B(net81),
    .Y(_137_));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input47 (.A(tl_i[55]),
    .X(net46));
 sky130_fd_sc_hd__nand2_1 _313_ (.A(_137_),
    .B(_125_),
    .Y(_021_));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input46 (.A(tl_i[54]),
    .X(net45));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input45 (.A(tl_i[53]),
    .X(net44));
 sky130_fd_sc_hd__nand3_1 _316_ (.A(_052_),
    .B(\reg2hw[24] ),
    .C(_053_),
    .Y(_141_));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input44 (.A(tl_i[52]),
    .X(net43));
 sky130_fd_sc_hd__nand2_1 _318_ (.A(net112),
    .B(net82),
    .Y(_143_));
 sky130_fd_sc_hd__nand3_1 _319_ (.A(_141_),
    .B(_143_),
    .C(_125_),
    .Y(_022_));
 sky130_fd_sc_hd__nand3_1 _320_ (.A(_052_),
    .B(\reg2hw[25] ),
    .C(_053_),
    .Y(_144_));
 sky130_fd_sc_hd__nand2_1 _321_ (.A(net112),
    .B(net83),
    .Y(_145_));
 sky130_fd_sc_hd__nand3_1 _322_ (.A(_144_),
    .B(_145_),
    .C(_125_),
    .Y(_023_));
 sky130_fd_sc_hd__nand3_1 _323_ (.A(_052_),
    .B(\reg2hw[26] ),
    .C(_053_),
    .Y(_146_));
 sky130_fd_sc_hd__nand2_1 _324_ (.A(net112),
    .B(net84),
    .Y(_147_));
 sky130_fd_sc_hd__nand3_1 _325_ (.A(_146_),
    .B(_147_),
    .C(_125_),
    .Y(_024_));
 sky130_fd_sc_hd__nand3_1 _326_ (.A(_052_),
    .B(\reg2hw[27] ),
    .C(_053_),
    .Y(_148_));
 sky130_fd_sc_hd__nand2_1 _327_ (.A(net112),
    .B(net85),
    .Y(_149_));
 sky130_fd_sc_hd__nand3_1 _328_ (.A(_148_),
    .B(_149_),
    .C(_125_),
    .Y(_025_));
 sky130_fd_sc_hd__nor2_1 _329_ (.A(net66),
    .B(_052_),
    .Y(_150_));
 sky130_fd_sc_hd__a21oi_1 _330_ (.A1(_132_),
    .A2(_074_),
    .B1(net54),
    .Y(_151_));
 sky130_fd_sc_hd__nor2_1 _331_ (.A(_151_),
    .B(_135_),
    .Y(_152_));
 sky130_fd_sc_hd__nor2_1 _332_ (.A(_150_),
    .B(_152_),
    .Y(_026_));
 sky130_fd_sc_hd__nand3_1 _333_ (.A(_052_),
    .B(\reg2hw[28] ),
    .C(_053_),
    .Y(_153_));
 sky130_fd_sc_hd__nand2_1 _334_ (.A(net112),
    .B(net86),
    .Y(_154_));
 sky130_fd_sc_hd__nand3_1 _335_ (.A(_153_),
    .B(_154_),
    .C(_125_),
    .Y(_027_));
 sky130_fd_sc_hd__nand3_1 _336_ (.A(_052_),
    .B(\reg2hw[29] ),
    .C(_053_),
    .Y(_155_));
 sky130_fd_sc_hd__nand2_1 _337_ (.A(net112),
    .B(net87),
    .Y(_156_));
 sky130_fd_sc_hd__nand3_1 _338_ (.A(_155_),
    .B(_156_),
    .C(_125_),
    .Y(_028_));
 sky130_fd_sc_hd__nand3_1 _339_ (.A(_052_),
    .B(\reg2hw[30] ),
    .C(_053_),
    .Y(_157_));
 sky130_fd_sc_hd__nand2_1 _340_ (.A(net112),
    .B(net88),
    .Y(_158_));
 sky130_fd_sc_hd__nand3_1 _341_ (.A(_157_),
    .B(_158_),
    .C(_125_),
    .Y(_029_));
 sky130_fd_sc_hd__nand3_1 _342_ (.A(_052_),
    .B(\reg2hw[31] ),
    .C(_053_),
    .Y(_159_));
 sky130_fd_sc_hd__nand2_1 _343_ (.A(net112),
    .B(net89),
    .Y(_160_));
 sky130_fd_sc_hd__nand3_1 _344_ (.A(_159_),
    .B(_160_),
    .C(_125_),
    .Y(_030_));
 sky130_fd_sc_hd__nand3_1 _345_ (.A(_052_),
    .B(\reg2hw[32] ),
    .C(_053_),
    .Y(_161_));
 sky130_fd_sc_hd__nand2_1 _346_ (.A(net112),
    .B(net90),
    .Y(_162_));
 sky130_fd_sc_hd__nand3_1 _347_ (.A(_161_),
    .B(_162_),
    .C(_125_),
    .Y(_031_));
 sky130_fd_sc_hd__nand3_1 _348_ (.A(_052_),
    .B(\reg2hw[33] ),
    .C(_053_),
    .Y(_163_));
 sky130_fd_sc_hd__nand2_1 _349_ (.A(net112),
    .B(net91),
    .Y(_164_));
 sky130_fd_sc_hd__nand3_1 _350_ (.A(_163_),
    .B(_164_),
    .C(_125_),
    .Y(_032_));
 sky130_fd_sc_hd__nand3_1 _351_ (.A(_052_),
    .B(\reg2hw[34] ),
    .C(_053_),
    .Y(_165_));
 sky130_fd_sc_hd__nand2_1 _352_ (.A(net112),
    .B(net92),
    .Y(_166_));
 sky130_fd_sc_hd__nand3_1 _353_ (.A(_165_),
    .B(_166_),
    .C(_125_),
    .Y(_033_));
 sky130_fd_sc_hd__nand3_1 _354_ (.A(_052_),
    .B(\reg2hw[35] ),
    .C(_053_),
    .Y(_167_));
 sky130_fd_sc_hd__nand2_1 _355_ (.A(net112),
    .B(net93),
    .Y(_168_));
 sky130_fd_sc_hd__nand3_1 _356_ (.A(_167_),
    .B(_168_),
    .C(_125_),
    .Y(_034_));
 sky130_fd_sc_hd__nand3_1 _357_ (.A(_052_),
    .B(\reg2hw[36] ),
    .C(_053_),
    .Y(_169_));
 sky130_fd_sc_hd__nand2_1 _358_ (.A(net112),
    .B(net94),
    .Y(_170_));
 sky130_fd_sc_hd__nand3_1 _359_ (.A(_169_),
    .B(_170_),
    .C(_125_),
    .Y(_035_));
 sky130_fd_sc_hd__nand3_1 _360_ (.A(_052_),
    .B(\reg2hw[37] ),
    .C(_053_),
    .Y(_171_));
 sky130_fd_sc_hd__nand2_1 _361_ (.A(net112),
    .B(net95),
    .Y(_172_));
 sky130_fd_sc_hd__nand3_1 _362_ (.A(_171_),
    .B(_172_),
    .C(_125_),
    .Y(_036_));
 sky130_fd_sc_hd__nand3_1 _363_ (.A(_052_),
    .B(\reg2hw[38] ),
    .C(_053_),
    .Y(_173_));
 sky130_fd_sc_hd__nand2_1 _364_ (.A(net112),
    .B(net96),
    .Y(_174_));
 sky130_fd_sc_hd__nand3_1 _365_ (.A(_173_),
    .B(_174_),
    .C(_125_),
    .Y(_037_));
 sky130_fd_sc_hd__nand3_1 _366_ (.A(_052_),
    .B(\reg2hw[39] ),
    .C(_053_),
    .Y(_175_));
 sky130_fd_sc_hd__nand2_1 _367_ (.A(net112),
    .B(net97),
    .Y(_176_));
 sky130_fd_sc_hd__nand3_1 _368_ (.A(_175_),
    .B(_176_),
    .C(_125_),
    .Y(_038_));
 sky130_fd_sc_hd__o21ai_0 _369_ (.A1(net73),
    .A2(_052_),
    .B1(_135_),
    .Y(_177_));
 sky130_fd_sc_hd__inv_1 _370_ (.A(_177_),
    .Y(_039_));
 sky130_fd_sc_hd__nand2_1 _371_ (.A(_126_),
    .B(net98),
    .Y(_178_));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input43 (.A(tl_i[51]),
    .X(net42));
 sky130_fd_sc_hd__nand2_1 _373_ (.A(_052_),
    .B(net55),
    .Y(_180_));
 sky130_fd_sc_hd__nand2_1 _374_ (.A(_178_),
    .B(_180_),
    .Y(_040_));
 sky130_fd_sc_hd__nand2_1 _375_ (.A(_126_),
    .B(net99),
    .Y(_181_));
 sky130_fd_sc_hd__nand2_1 _376_ (.A(_052_),
    .B(net56),
    .Y(_182_));
 sky130_fd_sc_hd__nand2_1 _377_ (.A(_181_),
    .B(_182_),
    .Y(_041_));
 sky130_fd_sc_hd__nand2_1 _378_ (.A(_126_),
    .B(net100),
    .Y(_183_));
 sky130_fd_sc_hd__nand2_1 _379_ (.A(_052_),
    .B(net57),
    .Y(_184_));
 sky130_fd_sc_hd__nand2_1 _380_ (.A(_183_),
    .B(_184_),
    .Y(_042_));
 sky130_fd_sc_hd__nand2_1 _381_ (.A(_126_),
    .B(net101),
    .Y(_185_));
 sky130_fd_sc_hd__nand2_1 _382_ (.A(_052_),
    .B(net58),
    .Y(_186_));
 sky130_fd_sc_hd__nand2_1 _383_ (.A(_185_),
    .B(_186_),
    .Y(_043_));
 sky130_fd_sc_hd__nand2_1 _384_ (.A(_126_),
    .B(net102),
    .Y(_187_));
 sky130_fd_sc_hd__nand2_1 _385_ (.A(_052_),
    .B(net59),
    .Y(_188_));
 sky130_fd_sc_hd__nand2_1 _386_ (.A(_187_),
    .B(_188_),
    .Y(_044_));
 sky130_fd_sc_hd__nand2_1 _387_ (.A(_126_),
    .B(net103),
    .Y(_189_));
 sky130_fd_sc_hd__nand2_1 _388_ (.A(_052_),
    .B(net60),
    .Y(_190_));
 sky130_fd_sc_hd__nand2_1 _389_ (.A(_189_),
    .B(_190_),
    .Y(_045_));
 sky130_fd_sc_hd__nand2_1 _390_ (.A(_126_),
    .B(net104),
    .Y(_191_));
 sky130_fd_sc_hd__nand2_1 _391_ (.A(_052_),
    .B(net61),
    .Y(_192_));
 sky130_fd_sc_hd__nand2_1 _392_ (.A(_191_),
    .B(_192_),
    .Y(_046_));
 sky130_fd_sc_hd__nand2_1 _393_ (.A(_126_),
    .B(net105),
    .Y(_193_));
 sky130_fd_sc_hd__nand2_1 _394_ (.A(_052_),
    .B(net62),
    .Y(_194_));
 sky130_fd_sc_hd__nand2_1 _395_ (.A(_193_),
    .B(_194_),
    .Y(_047_));
 sky130_fd_sc_hd__nand2_1 _396_ (.A(_126_),
    .B(net106),
    .Y(_195_));
 sky130_fd_sc_hd__nand2_1 _397_ (.A(_052_),
    .B(net23),
    .Y(_196_));
 sky130_fd_sc_hd__nand2_1 _398_ (.A(_195_),
    .B(_196_),
    .Y(_048_));
 sky130_fd_sc_hd__nand2_1 _399_ (.A(_126_),
    .B(net107),
    .Y(_197_));
 sky130_fd_sc_hd__nand2_1 _400_ (.A(_052_),
    .B(net24),
    .Y(_198_));
 sky130_fd_sc_hd__nand2_1 _401_ (.A(_197_),
    .B(_198_),
    .Y(_049_));
 sky130_fd_sc_hd__nor2_1 _402_ (.A(net26),
    .B(net25),
    .Y(_199_));
 sky130_fd_sc_hd__nand3_1 _403_ (.A(_052_),
    .B(net27),
    .C(_199_),
    .Y(_200_));
 sky130_fd_sc_hd__nand2_1 _404_ (.A(_126_),
    .B(net108),
    .Y(_201_));
 sky130_fd_sc_hd__nand2_1 _405_ (.A(_200_),
    .B(_201_),
    .Y(_050_));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input42 (.A(tl_i[50]),
    .X(net41));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input41 (.A(tl_i[49]),
    .X(net40));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input40 (.A(tl_i[48]),
    .X(net39));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input39 (.A(tl_i[47]),
    .X(net38));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input38 (.A(tl_i[46]),
    .X(net37));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input37 (.A(tl_i[45]),
    .X(net36));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input36 (.A(tl_i[44]),
    .X(net35));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input35 (.A(tl_i[43]),
    .X(net34));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input34 (.A(tl_i[42]),
    .X(net33));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input33 (.A(tl_i[41]),
    .X(net32));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input32 (.A(tl_i[40]),
    .X(net31));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input31 (.A(tl_i[25]),
    .X(net30));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input30 (.A(tl_i[24]),
    .X(net29));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input29 (.A(tl_i[108]),
    .X(net28));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input28 (.A(tl_i[107]),
    .X(net27));
 sky130_fd_sc_hd__clkbuf_8 clkload2 (.A(clknet_2_3__leaf_clk_i));
 sky130_fd_sc_hd__clkinv_2 clkload1 (.A(clknet_2_2__leaf_clk_i));
 sky130_fd_sc_hd__clkbuf_8 clkload0 (.A(clknet_2_0__leaf_clk_i));
 sky130_fd_sc_hd__clkbuf_8 clkbuf_2_3__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_2_3__leaf_clk_i));
 sky130_fd_sc_hd__clkbuf_8 clkbuf_2_2__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_2_2__leaf_clk_i));
 sky130_fd_sc_hd__clkbuf_8 clkbuf_2_1__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_2_1__leaf_clk_i));
 sky130_fd_sc_hd__clkbuf_8 clkbuf_2_0__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_2_0__leaf_clk_i));
 sky130_fd_sc_hd__buf_4 place114 (.A(net21),
    .X(net113));
 sky130_fd_sc_hd__clkbuf_8 clkbuf_0_clk_i (.A(clk_i),
    .X(clknet_0_clk_i));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input27 (.A(tl_i[106]),
    .X(net26));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input26 (.A(tl_i[105]),
    .X(net25));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input25 (.A(tl_i[101]),
    .X(net24));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input24 (.A(tl_i[100]),
    .X(net23));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input23 (.A(tl_i[0]),
    .X(net22));
 sky130_fd_sc_hd__buf_2 input22 (.A(rst_ni),
    .X(net21));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input21 (.A(port_i),
    .X(net20));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_core.u_sync_name.u_sync_1.q_o$_DFF_PN0_  (.D(net20),
    .Q(\u_my_ip_core.u_sync_name.intq ),
    .RESET_B(net113),
    .CLK(clknet_2_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_core.u_sync_name.u_sync_2.q_o$_DFF_PN0_  (.D(\u_my_ip_core.u_sync_name.intq ),
    .Q(net63),
    .RESET_B(net113),
    .CLK(clknet_2_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_en.q$_DFFE_PN0P_  (.D(_000_),
    .Q(\reg2hw[22] ),
    .RESET_B(net113),
    .CLK(clknet_2_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_rst.q$_DFFE_PN0P_  (.D(_001_),
    .Q(\reg2hw[23] ),
    .RESET_B(net113),
    .CLK(clknet_2_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_setting.q[0]$_DFFE_PN0P_  (.D(_002_),
    .Q(\reg2hw[24] ),
    .RESET_B(net113),
    .CLK(clknet_2_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_setting.q[10]$_DFFE_PN0P_  (.D(_003_),
    .Q(\reg2hw[34] ),
    .RESET_B(net113),
    .CLK(clknet_2_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_setting.q[11]$_DFFE_PN0P_  (.D(_004_),
    .Q(\reg2hw[35] ),
    .RESET_B(net113),
    .CLK(clknet_2_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_setting.q[12]$_DFFE_PN0P_  (.D(_005_),
    .Q(\reg2hw[36] ),
    .RESET_B(net113),
    .CLK(clknet_2_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_setting.q[13]$_DFFE_PN0P_  (.D(_006_),
    .Q(\reg2hw[37] ),
    .RESET_B(net113),
    .CLK(clknet_2_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_setting.q[14]$_DFFE_PN0P_  (.D(_007_),
    .Q(\reg2hw[38] ),
    .RESET_B(net113),
    .CLK(clknet_2_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_setting.q[15]$_DFFE_PN0P_  (.D(_008_),
    .Q(\reg2hw[39] ),
    .RESET_B(net113),
    .CLK(clknet_2_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_setting.q[1]$_DFFE_PN0P_  (.D(_009_),
    .Q(\reg2hw[25] ),
    .RESET_B(net113),
    .CLK(clknet_2_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_setting.q[2]$_DFFE_PN0P_  (.D(_010_),
    .Q(\reg2hw[26] ),
    .RESET_B(net113),
    .CLK(clknet_2_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_setting.q[3]$_DFFE_PN0P_  (.D(_011_),
    .Q(\reg2hw[27] ),
    .RESET_B(net113),
    .CLK(clknet_2_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_setting.q[4]$_DFFE_PN0P_  (.D(_012_),
    .Q(\reg2hw[28] ),
    .RESET_B(net113),
    .CLK(clknet_2_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_setting.q[5]$_DFFE_PN0P_  (.D(_013_),
    .Q(\reg2hw[29] ),
    .RESET_B(net113),
    .CLK(clknet_2_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_setting.q[6]$_DFFE_PN0P_  (.D(_014_),
    .Q(\reg2hw[30] ),
    .RESET_B(net113),
    .CLK(clknet_2_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_setting.q[7]$_DFFE_PN0P_  (.D(_015_),
    .Q(\reg2hw[31] ),
    .RESET_B(net113),
    .CLK(clknet_2_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_setting.q[8]$_DFFE_PN0P_  (.D(_016_),
    .Q(\reg2hw[32] ),
    .RESET_B(net113),
    .CLK(clknet_2_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_ctrl_setting.q[9]$_DFFE_PN0P_  (.D(_017_),
    .Q(\reg2hw[33] ),
    .RESET_B(net113),
    .CLK(clknet_2_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.error$_DFFE_PN0P_  (.D(_018_),
    .Q(net69),
    .RESET_B(net113),
    .CLK(clknet_2_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.outstanding_q$_DFFE_PN0P_  (.D(_019_),
    .Q(net109),
    .RESET_B(net113),
    .CLK(clknet_2_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[0]$_DFFE_PN0P_  (.D(_020_),
    .Q(net65),
    .RESET_B(net113),
    .CLK(clknet_2_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[15]$_DFFE_PN0P_  (.D(_021_),
    .Q(net81),
    .RESET_B(net113),
    .CLK(clknet_2_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[16]$_DFFE_PN0P_  (.D(_022_),
    .Q(net82),
    .RESET_B(net113),
    .CLK(clknet_2_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[17]$_DFFE_PN0P_  (.D(_023_),
    .Q(net83),
    .RESET_B(net113),
    .CLK(clknet_2_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[18]$_DFFE_PN0P_  (.D(_024_),
    .Q(net84),
    .RESET_B(net113),
    .CLK(clknet_2_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[19]$_DFFE_PN0P_  (.D(_025_),
    .Q(net85),
    .RESET_B(net113),
    .CLK(clknet_2_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[1]$_DFFE_PN0P_  (.D(_026_),
    .Q(net66),
    .RESET_B(net113),
    .CLK(clknet_2_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[20]$_DFFE_PN0P_  (.D(_027_),
    .Q(net86),
    .RESET_B(net113),
    .CLK(clknet_2_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[21]$_DFFE_PN0P_  (.D(_028_),
    .Q(net87),
    .RESET_B(net113),
    .CLK(clknet_2_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[22]$_DFFE_PN0P_  (.D(_029_),
    .Q(net88),
    .RESET_B(net113),
    .CLK(clknet_2_1__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[23]$_DFFE_PN0P_  (.D(_030_),
    .Q(net89),
    .RESET_B(net113),
    .CLK(clknet_2_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[24]$_DFFE_PN0P_  (.D(_031_),
    .Q(net90),
    .RESET_B(net113),
    .CLK(clknet_2_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[25]$_DFFE_PN0P_  (.D(_032_),
    .Q(net91),
    .RESET_B(net113),
    .CLK(clknet_2_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[26]$_DFFE_PN0P_  (.D(_033_),
    .Q(net92),
    .RESET_B(net113),
    .CLK(clknet_2_0__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[27]$_DFFE_PN0P_  (.D(_034_),
    .Q(net93),
    .RESET_B(net113),
    .CLK(clknet_2_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[28]$_DFFE_PN0P_  (.D(_035_),
    .Q(net94),
    .RESET_B(net113),
    .CLK(clknet_2_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[29]$_DFFE_PN0P_  (.D(_036_),
    .Q(net95),
    .RESET_B(net113),
    .CLK(clknet_2_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[30]$_DFFE_PN0P_  (.D(_037_),
    .Q(net96),
    .RESET_B(net113),
    .CLK(clknet_2_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[31]$_DFFE_PN0P_  (.D(_038_),
    .Q(net97),
    .RESET_B(net113),
    .CLK(clknet_2_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rdata[7]$_DFFE_PN0P_  (.D(_039_),
    .Q(net73),
    .RESET_B(net113),
    .CLK(clknet_2_2__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.reqid_q[0]$_DFFE_PN0P_  (.D(_040_),
    .Q(net98),
    .RESET_B(net113),
    .CLK(clknet_2_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.reqid_q[1]$_DFFE_PN0P_  (.D(_041_),
    .Q(net99),
    .RESET_B(net113),
    .CLK(clknet_2_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.reqid_q[2]$_DFFE_PN0P_  (.D(_042_),
    .Q(net100),
    .RESET_B(net113),
    .CLK(clknet_2_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.reqid_q[3]$_DFFE_PN0P_  (.D(_043_),
    .Q(net101),
    .RESET_B(net113),
    .CLK(clknet_2_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.reqid_q[4]$_DFFE_PN0P_  (.D(_044_),
    .Q(net102),
    .RESET_B(net113),
    .CLK(clknet_2_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.reqid_q[5]$_DFFE_PN0P_  (.D(_045_),
    .Q(net103),
    .RESET_B(net113),
    .CLK(clknet_2_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.reqid_q[6]$_DFFE_PN0P_  (.D(_046_),
    .Q(net104),
    .RESET_B(net113),
    .CLK(clknet_2_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.reqid_q[7]$_DFFE_PN0P_  (.D(_047_),
    .Q(net105),
    .RESET_B(net113),
    .CLK(clknet_2_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.reqsz_q[0]$_DFFE_PN0P_  (.D(_048_),
    .Q(net106),
    .RESET_B(net113),
    .CLK(clknet_2_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.reqsz_q[1]$_DFFE_PN0P_  (.D(_049_),
    .Q(net107),
    .RESET_B(net113),
    .CLK(clknet_2_3__leaf_clk_i));
 sky130_fd_sc_hd__dfrtp_1 \u_my_ip_reg.u_reg_if.rspop_q[0]$_DFFE_PN0P_  (.D(_050_),
    .Q(net108),
    .RESET_B(net113),
    .CLK(clknet_2_1__leaf_clk_i));
 sky130_fd_sc_hd__conb_1 _408__1 (.LO(tl_o[2]));
 sky130_fd_sc_hd__conb_1 _409__2 (.LO(tl_o[3]));
 sky130_fd_sc_hd__conb_1 _410__3 (.LO(tl_o[4]));
 sky130_fd_sc_hd__conb_1 _411__4 (.LO(tl_o[5]));
 sky130_fd_sc_hd__conb_1 _412__5 (.LO(tl_o[6]));
 sky130_fd_sc_hd__conb_1 _413__6 (.LO(tl_o[7]));
 sky130_fd_sc_hd__conb_1 _414__7 (.LO(tl_o[8]));
 sky130_fd_sc_hd__conb_1 _415__8 (.LO(tl_o[9]));
 sky130_fd_sc_hd__conb_1 _416__9 (.LO(tl_o[10]));
 sky130_fd_sc_hd__conb_1 _417__10 (.LO(tl_o[11]));
 sky130_fd_sc_hd__conb_1 _418__11 (.LO(tl_o[12]));
 sky130_fd_sc_hd__conb_1 _419__12 (.LO(tl_o[13]));
 sky130_fd_sc_hd__conb_1 _420__13 (.LO(tl_o[14]));
 sky130_fd_sc_hd__conb_1 _421__14 (.LO(tl_o[15]));
 sky130_fd_sc_hd__conb_1 _434__15 (.LO(tl_o[48]));
 sky130_fd_sc_hd__conb_1 _435__16 (.LO(tl_o[59]));
 sky130_fd_sc_hd__conb_1 _436__17 (.LO(tl_o[60]));
 sky130_fd_sc_hd__conb_1 _437__18 (.LO(tl_o[61]));
 sky130_fd_sc_hd__conb_1 _438__19 (.LO(tl_o[63]));
 sky130_fd_sc_hd__conb_1 _439__20 (.LO(tl_o[64]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input55 (.A(tl_i[63]),
    .X(net54));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input56 (.A(tl_i[92]),
    .X(net55));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input57 (.A(tl_i[93]),
    .X(net56));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input58 (.A(tl_i[94]),
    .X(net57));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input59 (.A(tl_i[95]),
    .X(net58));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input60 (.A(tl_i[96]),
    .X(net59));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input61 (.A(tl_i[97]),
    .X(net60));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input62 (.A(tl_i[98]),
    .X(net61));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input63 (.A(tl_i[99]),
    .X(net62));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output64 (.A(net63),
    .X(port_o));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output65 (.A(net64),
    .X(tl_o[0]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output66 (.A(net65),
    .X(tl_o[16]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output67 (.A(net66),
    .X(tl_o[17]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output68 (.A(net73),
    .X(tl_o[18]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output69 (.A(net73),
    .X(tl_o[19]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output70 (.A(net69),
    .X(tl_o[1]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output71 (.A(net73),
    .X(tl_o[20]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output72 (.A(net73),
    .X(tl_o[21]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output73 (.A(net73),
    .X(tl_o[22]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output74 (.A(net73),
    .X(tl_o[23]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output75 (.A(net81),
    .X(tl_o[24]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output76 (.A(net81),
    .X(tl_o[25]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output77 (.A(net81),
    .X(tl_o[26]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output78 (.A(net81),
    .X(tl_o[27]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output79 (.A(net81),
    .X(tl_o[28]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output80 (.A(net81),
    .X(tl_o[29]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output81 (.A(net81),
    .X(tl_o[30]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output82 (.A(net81),
    .X(tl_o[31]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output83 (.A(net82),
    .X(tl_o[32]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output84 (.A(net83),
    .X(tl_o[33]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output85 (.A(net84),
    .X(tl_o[34]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output86 (.A(net85),
    .X(tl_o[35]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output87 (.A(net86),
    .X(tl_o[36]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output88 (.A(net87),
    .X(tl_o[37]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output89 (.A(net88),
    .X(tl_o[38]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output90 (.A(net89),
    .X(tl_o[39]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output91 (.A(net90),
    .X(tl_o[40]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output92 (.A(net91),
    .X(tl_o[41]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output93 (.A(net92),
    .X(tl_o[42]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output94 (.A(net93),
    .X(tl_o[43]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output95 (.A(net94),
    .X(tl_o[44]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output96 (.A(net95),
    .X(tl_o[45]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output97 (.A(net96),
    .X(tl_o[46]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output98 (.A(net97),
    .X(tl_o[47]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output99 (.A(net98),
    .X(tl_o[49]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output100 (.A(net99),
    .X(tl_o[50]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output101 (.A(net100),
    .X(tl_o[51]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output102 (.A(net101),
    .X(tl_o[52]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output103 (.A(net102),
    .X(tl_o[53]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output104 (.A(net103),
    .X(tl_o[54]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output105 (.A(net104),
    .X(tl_o[55]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output106 (.A(net105),
    .X(tl_o[56]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output107 (.A(net106),
    .X(tl_o[57]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output108 (.A(net107),
    .X(tl_o[58]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output109 (.A(net108),
    .X(tl_o[62]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output110 (.A(net109),
    .X(tl_o[65]));
 sky130_fd_sc_hd__buf_4 place113 (.A(_126_),
    .X(net112));
endmodule
