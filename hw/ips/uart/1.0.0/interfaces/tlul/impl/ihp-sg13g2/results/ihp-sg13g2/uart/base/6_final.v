module uart (clk_i,
    rst_ni,
    rx_i,
    tx_o,
    tl_i,
    tl_o);
 input clk_i;
 input rst_ni;
 input rx_i;
 output tx_o;
 input [108:0] tl_i;
 output [65:0] tl_o;

 wire _0000_;
 wire _0001_;
 wire _0002_;
 wire _0003_;
 wire _0004_;
 wire _0005_;
 wire _0006_;
 wire _0007_;
 wire _0008_;
 wire _0009_;
 wire _0010_;
 wire _0011_;
 wire _0012_;
 wire _0013_;
 wire _0014_;
 wire _0015_;
 wire _0016_;
 wire _0017_;
 wire _0018_;
 wire _0019_;
 wire _0020_;
 wire _0021_;
 wire _0022_;
 wire _0023_;
 wire _0024_;
 wire _0025_;
 wire _0026_;
 wire _0027_;
 wire _0028_;
 wire _0029_;
 wire _0030_;
 wire _0031_;
 wire _0032_;
 wire _0033_;
 wire _0034_;
 wire _0035_;
 wire _0036_;
 wire _0037_;
 wire _0038_;
 wire _0039_;
 wire _0040_;
 wire _0041_;
 wire _0042_;
 wire _0043_;
 wire _0044_;
 wire _0045_;
 wire _0046_;
 wire _0047_;
 wire clknet_3_7__leaf_clk_i;
 wire net1253;
 wire _0050_;
 wire net1254;
 wire _0052_;
 wire _0053_;
 wire _0054_;
 wire _0055_;
 wire _0056_;
 wire _0057_;
 wire _0058_;
 wire _0059_;
 wire _0060_;
 wire _0061_;
 wire _0062_;
 wire _0063_;
 wire _0064_;
 wire _0065_;
 wire _0066_;
 wire _0067_;
 wire _0068_;
 wire _0069_;
 wire _0070_;
 wire _0071_;
 wire _0072_;
 wire _0073_;
 wire _0074_;
 wire _0075_;
 wire _0076_;
 wire _0077_;
 wire _0078_;
 wire _0079_;
 wire _0080_;
 wire _0081_;
 wire _0082_;
 wire _0083_;
 wire _0084_;
 wire _0085_;
 wire _0086_;
 wire _0087_;
 wire _0088_;
 wire _0089_;
 wire _0090_;
 wire _0091_;
 wire _0092_;
 wire _0093_;
 wire _0094_;
 wire _0095_;
 wire _0096_;
 wire _0097_;
 wire _0098_;
 wire _0099_;
 wire _0100_;
 wire _0101_;
 wire _0102_;
 wire _0103_;
 wire _0104_;
 wire _0105_;
 wire _0106_;
 wire _0107_;
 wire _0108_;
 wire _0109_;
 wire _0110_;
 wire _0111_;
 wire _0112_;
 wire _0113_;
 wire _0114_;
 wire _0115_;
 wire _0116_;
 wire _0117_;
 wire _0118_;
 wire _0119_;
 wire _0120_;
 wire _0121_;
 wire _0122_;
 wire _0123_;
 wire _0124_;
 wire _0125_;
 wire _0126_;
 wire _0127_;
 wire _0128_;
 wire _0129_;
 wire _0130_;
 wire _0131_;
 wire _0132_;
 wire _0133_;
 wire _0134_;
 wire _0135_;
 wire _0136_;
 wire _0137_;
 wire _0138_;
 wire _0139_;
 wire _0140_;
 wire _0141_;
 wire _0142_;
 wire _0143_;
 wire _0144_;
 wire _0145_;
 wire _0146_;
 wire _0147_;
 wire _0148_;
 wire _0149_;
 wire _0150_;
 wire _0151_;
 wire _0152_;
 wire _0153_;
 wire _0154_;
 wire _0155_;
 wire _0156_;
 wire _0157_;
 wire _0158_;
 wire _0159_;
 wire _0160_;
 wire _0161_;
 wire _0162_;
 wire _0163_;
 wire _0164_;
 wire _0165_;
 wire _0166_;
 wire _0167_;
 wire _0168_;
 wire _0169_;
 wire _0170_;
 wire _0171_;
 wire _0172_;
 wire _0173_;
 wire _0174_;
 wire _0175_;
 wire _0176_;
 wire _0177_;
 wire _0178_;
 wire _0179_;
 wire _0180_;
 wire _0181_;
 wire _0182_;
 wire _0183_;
 wire _0184_;
 wire _0185_;
 wire _0186_;
 wire _0187_;
 wire _0188_;
 wire _0189_;
 wire _0190_;
 wire _0191_;
 wire _0192_;
 wire _0193_;
 wire _0194_;
 wire _0195_;
 wire _0196_;
 wire _0197_;
 wire _0198_;
 wire _0199_;
 wire _0200_;
 wire _0201_;
 wire _0202_;
 wire _0203_;
 wire _0204_;
 wire _0205_;
 wire _0206_;
 wire _0207_;
 wire _0208_;
 wire _0209_;
 wire _0210_;
 wire _0211_;
 wire _0212_;
 wire _0213_;
 wire _0214_;
 wire _0215_;
 wire _0216_;
 wire _0217_;
 wire _0218_;
 wire _0219_;
 wire _0220_;
 wire _0221_;
 wire _0222_;
 wire _0223_;
 wire _0224_;
 wire _0225_;
 wire _0226_;
 wire _0227_;
 wire _0228_;
 wire _0229_;
 wire _0230_;
 wire _0231_;
 wire _0232_;
 wire _0233_;
 wire _0234_;
 wire _0235_;
 wire _0236_;
 wire _0237_;
 wire _0238_;
 wire _0239_;
 wire _0240_;
 wire _0241_;
 wire _0242_;
 wire _0243_;
 wire _0244_;
 wire _0245_;
 wire _0246_;
 wire _0247_;
 wire _0248_;
 wire _0249_;
 wire _0250_;
 wire _0251_;
 wire _0252_;
 wire _0253_;
 wire _0254_;
 wire _0255_;
 wire _0256_;
 wire _0257_;
 wire _0258_;
 wire _0259_;
 wire _0260_;
 wire _0261_;
 wire _0262_;
 wire _0263_;
 wire _0264_;
 wire _0265_;
 wire _0266_;
 wire _0267_;
 wire _0268_;
 wire _0269_;
 wire _0270_;
 wire _0271_;
 wire _0272_;
 wire _0273_;
 wire _0274_;
 wire _0275_;
 wire _0276_;
 wire _0277_;
 wire _0278_;
 wire _0279_;
 wire _0280_;
 wire _0281_;
 wire _0282_;
 wire _0283_;
 wire _0284_;
 wire _0285_;
 wire _0286_;
 wire _0287_;
 wire _0288_;
 wire _0289_;
 wire _0290_;
 wire _0291_;
 wire _0292_;
 wire _0293_;
 wire _0294_;
 wire _0295_;
 wire _0296_;
 wire _0297_;
 wire _0298_;
 wire _0299_;
 wire _0300_;
 wire _0301_;
 wire _0302_;
 wire _0303_;
 wire _0304_;
 wire _0305_;
 wire _0306_;
 wire _0307_;
 wire _0308_;
 wire _0309_;
 wire _0310_;
 wire _0311_;
 wire _0312_;
 wire _0313_;
 wire _0314_;
 wire _0315_;
 wire _0316_;
 wire _0317_;
 wire _0318_;
 wire _0319_;
 wire _0320_;
 wire _0321_;
 wire _0322_;
 wire _0323_;
 wire _0324_;
 wire _0325_;
 wire _0326_;
 wire _0327_;
 wire _0328_;
 wire _0329_;
 wire _0330_;
 wire _0331_;
 wire _0332_;
 wire _0333_;
 wire _0334_;
 wire _0335_;
 wire _0336_;
 wire _0337_;
 wire _0338_;
 wire _0339_;
 wire _0340_;
 wire _0341_;
 wire _0342_;
 wire _0343_;
 wire _0344_;
 wire _0345_;
 wire _0346_;
 wire _0347_;
 wire _0348_;
 wire _0349_;
 wire _0350_;
 wire _0351_;
 wire _0352_;
 wire _0353_;
 wire _0354_;
 wire _0355_;
 wire _0356_;
 wire _0357_;
 wire _0358_;
 wire _0359_;
 wire _0360_;
 wire _0361_;
 wire _0362_;
 wire _0363_;
 wire _0364_;
 wire _0365_;
 wire _0366_;
 wire _0367_;
 wire _0368_;
 wire _0369_;
 wire _0370_;
 wire _0371_;
 wire _0372_;
 wire _0373_;
 wire _0374_;
 wire _0375_;
 wire _0376_;
 wire _0377_;
 wire _0378_;
 wire _0379_;
 wire _0380_;
 wire _0381_;
 wire _0382_;
 wire _0383_;
 wire _0384_;
 wire _0385_;
 wire _0386_;
 wire _0387_;
 wire _0388_;
 wire _0389_;
 wire _0390_;
 wire _0391_;
 wire _0392_;
 wire _0393_;
 wire _0394_;
 wire clknet_leaf_44_clk_i;
 wire _0396_;
 wire _0397_;
 wire _0398_;
 wire _0399_;
 wire _0400_;
 wire _0401_;
 wire _0402_;
 wire _0403_;
 wire _0404_;
 wire _0405_;
 wire _0406_;
 wire _0407_;
 wire _0408_;
 wire _0409_;
 wire _0410_;
 wire _0411_;
 wire _0412_;
 wire _0413_;
 wire _0414_;
 wire _0415_;
 wire _0416_;
 wire _0417_;
 wire _0418_;
 wire _0419_;
 wire _0420_;
 wire _0421_;
 wire _0422_;
 wire _0423_;
 wire _0424_;
 wire _0425_;
 wire _0426_;
 wire clknet_leaf_43_clk_i;
 wire clknet_leaf_42_clk_i;
 wire _0429_;
 wire _0430_;
 wire _0431_;
 wire _0432_;
 wire clknet_leaf_41_clk_i;
 wire _0434_;
 wire clknet_leaf_40_clk_i;
 wire _0436_;
 wire _0437_;
 wire _0438_;
 wire _0439_;
 wire _0440_;
 wire _0441_;
 wire _0442_;
 wire _0443_;
 wire _0444_;
 wire _0445_;
 wire _0446_;
 wire _0447_;
 wire _0448_;
 wire _0449_;
 wire _0450_;
 wire _0451_;
 wire _0452_;
 wire _0453_;
 wire _0454_;
 wire _0455_;
 wire _0456_;
 wire _0457_;
 wire _0458_;
 wire _0459_;
 wire _0460_;
 wire _0461_;
 wire _0462_;
 wire _0463_;
 wire _0464_;
 wire _0465_;
 wire _0466_;
 wire _0467_;
 wire _0468_;
 wire _0469_;
 wire _0470_;
 wire _0471_;
 wire _0472_;
 wire _0473_;
 wire _0474_;
 wire _0475_;
 wire _0476_;
 wire _0477_;
 wire _0478_;
 wire _0479_;
 wire _0480_;
 wire _0481_;
 wire _0482_;
 wire _0483_;
 wire _0484_;
 wire _0485_;
 wire _0486_;
 wire _0487_;
 wire _0488_;
 wire _0489_;
 wire _0490_;
 wire _0491_;
 wire _0492_;
 wire _0493_;
 wire _0494_;
 wire _0495_;
 wire _0496_;
 wire _0497_;
 wire _0498_;
 wire _0499_;
 wire _0500_;
 wire _0501_;
 wire _0502_;
 wire _0503_;
 wire _0504_;
 wire _0505_;
 wire _0506_;
 wire _0507_;
 wire _0508_;
 wire _0509_;
 wire _0510_;
 wire _0511_;
 wire _0512_;
 wire _0513_;
 wire _0514_;
 wire _0515_;
 wire _0516_;
 wire _0517_;
 wire _0518_;
 wire _0519_;
 wire _0520_;
 wire _0521_;
 wire _0522_;
 wire _0523_;
 wire _0524_;
 wire _0525_;
 wire _0526_;
 wire _0527_;
 wire _0528_;
 wire _0529_;
 wire _0530_;
 wire _0531_;
 wire _0532_;
 wire _0533_;
 wire _0534_;
 wire _0535_;
 wire _0536_;
 wire _0537_;
 wire _0538_;
 wire _0539_;
 wire _0540_;
 wire _0541_;
 wire _0542_;
 wire _0543_;
 wire _0544_;
 wire _0545_;
 wire _0546_;
 wire _0547_;
 wire _0548_;
 wire _0549_;
 wire _0550_;
 wire _0551_;
 wire _0552_;
 wire _0553_;
 wire _0554_;
 wire _0555_;
 wire _0556_;
 wire _0557_;
 wire _0558_;
 wire _0559_;
 wire _0560_;
 wire _0561_;
 wire _0562_;
 wire _0563_;
 wire _0564_;
 wire _0565_;
 wire _0566_;
 wire _0567_;
 wire _0568_;
 wire _0569_;
 wire _0570_;
 wire _0571_;
 wire _0572_;
 wire _0573_;
 wire _0574_;
 wire _0575_;
 wire _0576_;
 wire _0577_;
 wire _0578_;
 wire _0579_;
 wire _0580_;
 wire _0581_;
 wire _0582_;
 wire _0583_;
 wire _0584_;
 wire _0585_;
 wire _0586_;
 wire _0587_;
 wire _0588_;
 wire _0589_;
 wire _0590_;
 wire _0591_;
 wire _0592_;
 wire _0593_;
 wire _0594_;
 wire _0595_;
 wire _0596_;
 wire _0597_;
 wire _0598_;
 wire _0599_;
 wire _0600_;
 wire _0601_;
 wire _0602_;
 wire _0603_;
 wire _0604_;
 wire _0605_;
 wire _0606_;
 wire _0607_;
 wire _0608_;
 wire _0609_;
 wire _0610_;
 wire _0611_;
 wire _0612_;
 wire _0613_;
 wire _0614_;
 wire _0615_;
 wire _0616_;
 wire _0617_;
 wire _0618_;
 wire _0619_;
 wire _0620_;
 wire _0621_;
 wire _0622_;
 wire _0623_;
 wire _0624_;
 wire _0625_;
 wire _0626_;
 wire _0627_;
 wire _0628_;
 wire _0629_;
 wire _0630_;
 wire _0631_;
 wire _0632_;
 wire _0633_;
 wire _0634_;
 wire _0635_;
 wire _0636_;
 wire _0637_;
 wire _0638_;
 wire _0639_;
 wire _0640_;
 wire _0641_;
 wire _0642_;
 wire _0643_;
 wire _0644_;
 wire _0645_;
 wire _0646_;
 wire _0647_;
 wire _0648_;
 wire _0649_;
 wire _0650_;
 wire _0651_;
 wire _0652_;
 wire _0653_;
 wire _0654_;
 wire _0655_;
 wire _0656_;
 wire _0657_;
 wire _0658_;
 wire _0659_;
 wire _0660_;
 wire _0661_;
 wire _0662_;
 wire _0663_;
 wire _0664_;
 wire _0665_;
 wire _0666_;
 wire _0667_;
 wire _0668_;
 wire _0669_;
 wire _0670_;
 wire _0671_;
 wire _0672_;
 wire _0673_;
 wire _0674_;
 wire _0675_;
 wire _0676_;
 wire _0677_;
 wire _0678_;
 wire _0679_;
 wire _0680_;
 wire _0681_;
 wire _0682_;
 wire _0683_;
 wire _0684_;
 wire _0685_;
 wire _0686_;
 wire clknet_leaf_39_clk_i;
 wire _0688_;
 wire _0689_;
 wire clknet_leaf_38_clk_i;
 wire _0691_;
 wire _0692_;
 wire _0693_;
 wire _0694_;
 wire _0695_;
 wire _0696_;
 wire _0697_;
 wire _0698_;
 wire _0699_;
 wire _0700_;
 wire _0701_;
 wire _0702_;
 wire _0703_;
 wire _0704_;
 wire _0705_;
 wire _0706_;
 wire _0707_;
 wire _0708_;
 wire _0709_;
 wire _0710_;
 wire _0711_;
 wire _0712_;
 wire _0713_;
 wire _0714_;
 wire _0715_;
 wire _0716_;
 wire _0717_;
 wire _0718_;
 wire _0719_;
 wire _0720_;
 wire _0721_;
 wire _0722_;
 wire _0723_;
 wire _0724_;
 wire _0725_;
 wire _0726_;
 wire clknet_leaf_37_clk_i;
 wire _0728_;
 wire _0729_;
 wire clknet_leaf_36_clk_i;
 wire _0731_;
 wire _0732_;
 wire _0733_;
 wire _0734_;
 wire _0735_;
 wire _0736_;
 wire _0737_;
 wire _0738_;
 wire _0739_;
 wire _0740_;
 wire _0741_;
 wire _0742_;
 wire _0743_;
 wire _0744_;
 wire _0745_;
 wire _0746_;
 wire _0747_;
 wire _0748_;
 wire _0749_;
 wire _0750_;
 wire _0751_;
 wire _0752_;
 wire _0753_;
 wire _0754_;
 wire _0755_;
 wire _0756_;
 wire _0757_;
 wire _0758_;
 wire _0759_;
 wire _0760_;
 wire _0761_;
 wire _0762_;
 wire _0763_;
 wire _0764_;
 wire _0765_;
 wire _0766_;
 wire _0767_;
 wire _0768_;
 wire _0769_;
 wire _0770_;
 wire _0771_;
 wire _0772_;
 wire _0773_;
 wire _0774_;
 wire clknet_leaf_35_clk_i;
 wire _0776_;
 wire clknet_leaf_34_clk_i;
 wire _0778_;
 wire _0779_;
 wire _0780_;
 wire _0781_;
 wire _0782_;
 wire _0783_;
 wire _0784_;
 wire _0785_;
 wire _0786_;
 wire _0787_;
 wire _0788_;
 wire _0789_;
 wire clknet_leaf_33_clk_i;
 wire _0791_;
 wire _0792_;
 wire _0793_;
 wire _0794_;
 wire _0795_;
 wire _0796_;
 wire _0797_;
 wire _0798_;
 wire _0799_;
 wire _0800_;
 wire clknet_leaf_32_clk_i;
 wire _0802_;
 wire _0803_;
 wire _0804_;
 wire _0805_;
 wire _0806_;
 wire _0807_;
 wire _0808_;
 wire _0809_;
 wire _0810_;
 wire _0811_;
 wire _0812_;
 wire _0813_;
 wire _0814_;
 wire _0815_;
 wire _0816_;
 wire clknet_leaf_31_clk_i;
 wire _0818_;
 wire _0819_;
 wire _0820_;
 wire _0821_;
 wire _0822_;
 wire _0823_;
 wire _0824_;
 wire _0825_;
 wire clknet_leaf_30_clk_i;
 wire _0827_;
 wire _0828_;
 wire _0829_;
 wire _0830_;
 wire _0831_;
 wire _0832_;
 wire _0833_;
 wire _0834_;
 wire net1094;
 wire _0836_;
 wire _0837_;
 wire _0838_;
 wire _0839_;
 wire _0840_;
 wire _0841_;
 wire _0842_;
 wire _0843_;
 wire _0844_;
 wire _0845_;
 wire net1092;
 wire _0847_;
 wire _0848_;
 wire _0849_;
 wire _0850_;
 wire _0851_;
 wire _0852_;
 wire _0853_;
 wire _0854_;
 wire _0855_;
 wire _0856_;
 wire _0857_;
 wire _0858_;
 wire _0859_;
 wire _0860_;
 wire net1150;
 wire _0862_;
 wire _0863_;
 wire _0864_;
 wire _0865_;
 wire _0866_;
 wire _0867_;
 wire _0868_;
 wire _0869_;
 wire _0870_;
 wire _0871_;
 wire _0872_;
 wire _0873_;
 wire _0874_;
 wire _0875_;
 wire _0876_;
 wire _0877_;
 wire _0878_;
 wire _0879_;
 wire _0880_;
 wire _0881_;
 wire _0882_;
 wire _0883_;
 wire _0884_;
 wire _0885_;
 wire _0886_;
 wire _0887_;
 wire _0888_;
 wire _0889_;
 wire _0890_;
 wire _0891_;
 wire _0892_;
 wire _0893_;
 wire _0894_;
 wire _0895_;
 wire _0896_;
 wire net1091;
 wire _0898_;
 wire _0899_;
 wire _0900_;
 wire _0901_;
 wire _0902_;
 wire _0903_;
 wire _0904_;
 wire _0905_;
 wire _0906_;
 wire _0907_;
 wire _0908_;
 wire net1090;
 wire _0910_;
 wire _0911_;
 wire net1151;
 wire _0913_;
 wire _0914_;
 wire _0915_;
 wire clknet_leaf_2_clk_i;
 wire _0917_;
 wire _0918_;
 wire _0919_;
 wire clknet_leaf_1_clk_i;
 wire _0921_;
 wire _0922_;
 wire _0923_;
 wire clknet_leaf_0_clk_i;
 wire _0925_;
 wire _0926_;
 wire _0927_;
 wire clknet_leaf_3_clk_i;
 wire _0929_;
 wire _0930_;
 wire _0931_;
 wire net1252;
 wire _0933_;
 wire _0934_;
 wire _0935_;
 wire net1237;
 wire _0937_;
 wire _0938_;
 wire _0939_;
 wire net1152;
 wire _0941_;
 wire _0942_;
 wire _0943_;
 wire _0944_;
 wire _0945_;
 wire _0946_;
 wire _0947_;
 wire _0948_;
 wire _0949_;
 wire _0950_;
 wire net1247;
 wire _0952_;
 wire _0953_;
 wire _0954_;
 wire _0955_;
 wire _0956_;
 wire _0957_;
 wire _0958_;
 wire _0959_;
 wire _0960_;
 wire clknet_leaf_4_clk_i;
 wire _0962_;
 wire _0963_;
 wire _0964_;
 wire _0965_;
 wire _0966_;
 wire _0967_;
 wire _0968_;
 wire _0969_;
 wire net1251;
 wire _0971_;
 wire _0972_;
 wire _0973_;
 wire _0974_;
 wire _0975_;
 wire _0976_;
 wire _0977_;
 wire _0978_;
 wire net1248;
 wire _0980_;
 wire _0981_;
 wire _0982_;
 wire _0983_;
 wire _0984_;
 wire _0985_;
 wire _0986_;
 wire _0987_;
 wire _0988_;
 wire clknet_leaf_20_clk_i;
 wire _0990_;
 wire _0991_;
 wire _0992_;
 wire _0993_;
 wire _0994_;
 wire _0995_;
 wire _0996_;
 wire _0997_;
 wire clknet_leaf_19_clk_i;
 wire _0999_;
 wire _1000_;
 wire _1001_;
 wire _1002_;
 wire _1003_;
 wire _1004_;
 wire _1005_;
 wire _1006_;
 wire clknet_leaf_5_clk_i;
 wire _1008_;
 wire _1009_;
 wire _1010_;
 wire _1011_;
 wire _1012_;
 wire _1013_;
 wire _1014_;
 wire _1015_;
 wire _1016_;
 wire _1017_;
 wire _1018_;
 wire _1019_;
 wire _1020_;
 wire _1021_;
 wire _1022_;
 wire _1023_;
 wire clknet_leaf_18_clk_i;
 wire _1025_;
 wire _1026_;
 wire _1027_;
 wire _1028_;
 wire _1029_;
 wire _1030_;
 wire _1031_;
 wire _1032_;
 wire net1249;
 wire _1034_;
 wire _1035_;
 wire _1036_;
 wire _1037_;
 wire _1038_;
 wire _1039_;
 wire _1040_;
 wire _1041_;
 wire net1245;
 wire _1043_;
 wire _1044_;
 wire _1045_;
 wire _1046_;
 wire _1047_;
 wire _1048_;
 wire _1049_;
 wire _1050_;
 wire net1246;
 wire _1052_;
 wire _1053_;
 wire _1054_;
 wire _1055_;
 wire _1056_;
 wire _1057_;
 wire _1058_;
 wire _1059_;
 wire clknet_leaf_17_clk_i;
 wire _1061_;
 wire _1062_;
 wire _1063_;
 wire _1064_;
 wire _1065_;
 wire _1066_;
 wire _1067_;
 wire _1068_;
 wire clknet_leaf_16_clk_i;
 wire _1070_;
 wire _1071_;
 wire _1072_;
 wire _1073_;
 wire _1074_;
 wire _1075_;
 wire _1076_;
 wire _1077_;
 wire _1078_;
 wire _1079_;
 wire _1080_;
 wire _1081_;
 wire _1082_;
 wire _1083_;
 wire _1084_;
 wire _1085_;
 wire _1086_;
 wire _1087_;
 wire _1088_;
 wire _1089_;
 wire _1090_;
 wire _1091_;
 wire _1092_;
 wire _1093_;
 wire _1094_;
 wire _1095_;
 wire _1096_;
 wire _1097_;
 wire _1098_;
 wire _1099_;
 wire _1100_;
 wire _1101_;
 wire _1102_;
 wire _1103_;
 wire _1104_;
 wire _1105_;
 wire _1106_;
 wire _1107_;
 wire _1108_;
 wire _1109_;
 wire _1110_;
 wire _1111_;
 wire _1112_;
 wire _1113_;
 wire _1114_;
 wire _1115_;
 wire _1116_;
 wire _1117_;
 wire _1118_;
 wire _1119_;
 wire _1120_;
 wire _1121_;
 wire _1122_;
 wire _1123_;
 wire _1124_;
 wire _1125_;
 wire _1126_;
 wire _1127_;
 wire _1128_;
 wire _1129_;
 wire _1130_;
 wire _1131_;
 wire _1132_;
 wire _1133_;
 wire _1134_;
 wire _1135_;
 wire _1136_;
 wire _1137_;
 wire _1138_;
 wire _1139_;
 wire _1140_;
 wire _1141_;
 wire _1142_;
 wire _1143_;
 wire _1144_;
 wire _1145_;
 wire _1146_;
 wire _1147_;
 wire _1148_;
 wire _1149_;
 wire _1150_;
 wire _1151_;
 wire _1152_;
 wire _1153_;
 wire _1154_;
 wire _1155_;
 wire _1156_;
 wire _1157_;
 wire _1158_;
 wire _1159_;
 wire _1160_;
 wire _1161_;
 wire _1162_;
 wire _1163_;
 wire _1164_;
 wire _1165_;
 wire _1166_;
 wire _1167_;
 wire _1168_;
 wire _1169_;
 wire _1170_;
 wire _1171_;
 wire _1172_;
 wire _1173_;
 wire _1174_;
 wire _1175_;
 wire _1176_;
 wire _1177_;
 wire _1178_;
 wire _1179_;
 wire _1180_;
 wire _1181_;
 wire _1182_;
 wire _1183_;
 wire _1184_;
 wire _1185_;
 wire _1186_;
 wire _1187_;
 wire _1188_;
 wire _1189_;
 wire _1190_;
 wire _1191_;
 wire _1192_;
 wire _1193_;
 wire _1194_;
 wire _1195_;
 wire _1196_;
 wire _1197_;
 wire _1198_;
 wire _1199_;
 wire _1200_;
 wire _1201_;
 wire _1202_;
 wire _1203_;
 wire _1204_;
 wire _1205_;
 wire _1206_;
 wire _1207_;
 wire _1208_;
 wire _1209_;
 wire _1210_;
 wire _1211_;
 wire _1212_;
 wire _1213_;
 wire _1214_;
 wire _1215_;
 wire _1216_;
 wire _1217_;
 wire _1218_;
 wire _1219_;
 wire _1220_;
 wire _1221_;
 wire _1222_;
 wire _1223_;
 wire _1224_;
 wire _1225_;
 wire _1226_;
 wire _1227_;
 wire _1228_;
 wire _1229_;
 wire _1230_;
 wire _1231_;
 wire _1232_;
 wire _1233_;
 wire _1234_;
 wire _1235_;
 wire _1236_;
 wire _1237_;
 wire _1238_;
 wire net1250;
 wire _1240_;
 wire _1241_;
 wire _1242_;
 wire _1243_;
 wire _1244_;
 wire _1245_;
 wire _1246_;
 wire _1247_;
 wire _1248_;
 wire _1249_;
 wire _1250_;
 wire _1251_;
 wire _1252_;
 wire _1253_;
 wire _1254_;
 wire _1255_;
 wire _1256_;
 wire _1257_;
 wire _1258_;
 wire _1259_;
 wire _1260_;
 wire _1261_;
 wire _1262_;
 wire _1263_;
 wire _1264_;
 wire _1265_;
 wire _1266_;
 wire _1267_;
 wire _1268_;
 wire _1269_;
 wire _1270_;
 wire _1271_;
 wire _1272_;
 wire _1273_;
 wire _1274_;
 wire _1275_;
 wire _1276_;
 wire _1277_;
 wire _1278_;
 wire _1279_;
 wire _1280_;
 wire _1281_;
 wire _1282_;
 wire _1283_;
 wire _1284_;
 wire _1285_;
 wire _1286_;
 wire _1287_;
 wire _1288_;
 wire _1289_;
 wire _1290_;
 wire _1291_;
 wire _1292_;
 wire _1293_;
 wire _1294_;
 wire _1295_;
 wire _1296_;
 wire _1297_;
 wire _1298_;
 wire _1299_;
 wire _1300_;
 wire _1301_;
 wire _1302_;
 wire _1303_;
 wire _1304_;
 wire _1305_;
 wire _1306_;
 wire _1307_;
 wire _1308_;
 wire _1309_;
 wire _1310_;
 wire _1311_;
 wire _1312_;
 wire _1313_;
 wire _1314_;
 wire _1315_;
 wire _1316_;
 wire _1317_;
 wire _1318_;
 wire _1319_;
 wire _1320_;
 wire _1321_;
 wire _1322_;
 wire _1323_;
 wire _1324_;
 wire _1325_;
 wire _1326_;
 wire _1327_;
 wire _1328_;
 wire _1329_;
 wire _1330_;
 wire _1331_;
 wire _1332_;
 wire _1333_;
 wire _1334_;
 wire _1335_;
 wire _1336_;
 wire _1337_;
 wire _1338_;
 wire _1339_;
 wire _1340_;
 wire _1341_;
 wire _1342_;
 wire _1343_;
 wire _1344_;
 wire _1345_;
 wire _1346_;
 wire _1347_;
 wire _1348_;
 wire _1349_;
 wire _1350_;
 wire _1351_;
 wire _1352_;
 wire _1353_;
 wire _1354_;
 wire _1355_;
 wire _1356_;
 wire _1357_;
 wire _1358_;
 wire _1359_;
 wire _1360_;
 wire _1361_;
 wire _1362_;
 wire _1363_;
 wire _1364_;
 wire _1365_;
 wire _1366_;
 wire _1367_;
 wire _1368_;
 wire _1369_;
 wire _1370_;
 wire _1371_;
 wire _1372_;
 wire _1373_;
 wire _1374_;
 wire _1375_;
 wire _1376_;
 wire _1377_;
 wire _1378_;
 wire _1379_;
 wire _1380_;
 wire _1381_;
 wire _1382_;
 wire _1383_;
 wire _1384_;
 wire _1385_;
 wire clknet_3_6__leaf_clk_i;
 wire _1387_;
 wire _1388_;
 wire _1389_;
 wire _1390_;
 wire _1391_;
 wire _1392_;
 wire _1393_;
 wire _1394_;
 wire _1395_;
 wire clknet_3_5__leaf_clk_i;
 wire _1397_;
 wire clknet_3_4__leaf_clk_i;
 wire _1399_;
 wire _1400_;
 wire _1401_;
 wire _1402_;
 wire _1403_;
 wire _1404_;
 wire _1405_;
 wire _1406_;
 wire _1407_;
 wire _1408_;
 wire _1409_;
 wire _1410_;
 wire _1411_;
 wire _1412_;
 wire _1413_;
 wire _1414_;
 wire _1415_;
 wire _1416_;
 wire _1417_;
 wire _1418_;
 wire _1419_;
 wire clknet_3_2__leaf_clk_i;
 wire clknet_3_1__leaf_clk_i;
 wire _1422_;
 wire _1423_;
 wire _1424_;
 wire _1425_;
 wire _1426_;
 wire _1427_;
 wire _1428_;
 wire _1429_;
 wire _1430_;
 wire _1431_;
 wire _1432_;
 wire _1433_;
 wire _1434_;
 wire _1435_;
 wire _1436_;
 wire _1437_;
 wire _1438_;
 wire clknet_3_0__leaf_clk_i;
 wire _1440_;
 wire _1441_;
 wire _1442_;
 wire clknet_0_clk_i;
 wire _1444_;
 wire _1445_;
 wire _1446_;
 wire _1447_;
 wire _1448_;
 wire _1449_;
 wire _1450_;
 wire _1451_;
 wire _1452_;
 wire _1453_;
 wire _1454_;
 wire _1455_;
 wire _1456_;
 wire _1457_;
 wire _1458_;
 wire _1459_;
 wire _1460_;
 wire _1461_;
 wire _1462_;
 wire _1463_;
 wire _1464_;
 wire _1465_;
 wire _1466_;
 wire _1467_;
 wire _1468_;
 wire _1469_;
 wire _1470_;
 wire clknet_leaf_45_clk_i;
 wire _1472_;
 wire _1473_;
 wire core_rst_ni;
 wire clknet_leaf_7_clk_i;
 wire clknet_leaf_13_clk_i;
 wire net1223;
 wire net515;
 wire net516;
 wire net517;
 wire net518;
 wire net519;
 wire net520;
 wire net521;
 wire net522;
 wire net523;
 wire net524;
 wire net1222;
 wire net525;
 wire net526;
 wire net527;
 wire net528;
 wire net529;
 wire net530;
 wire net531;
 wire net532;
 wire net533;
 wire net534;
 wire clknet_leaf_12_clk_i;
 wire net535;
 wire net536;
 wire net537;
 wire net538;
 wire net539;
 wire net540;
 wire net541;
 wire net542;
 wire net543;
 wire net544;
 wire net1195;
 wire net545;
 wire net546;
 wire net547;
 wire net548;
 wire net549;
 wire net550;
 wire net551;
 wire net552;
 wire net553;
 wire net554;
 wire net1193;
 wire net555;
 wire net556;
 wire net557;
 wire net558;
 wire net559;
 wire net560;
 wire net561;
 wire net562;
 wire net563;
 wire net564;
 wire net1192;
 wire net565;
 wire net566;
 wire net567;
 wire net568;
 wire net569;
 wire net570;
 wire net571;
 wire net572;
 wire net573;
 wire net574;
 wire net1199;
 wire net575;
 wire net576;
 wire net577;
 wire net578;
 wire net579;
 wire net580;
 wire net581;
 wire net582;
 wire net583;
 wire net584;
 wire net1190;
 wire net585;
 wire net586;
 wire net587;
 wire net588;
 wire net589;
 wire net590;
 wire net591;
 wire net592;
 wire net593;
 wire net594;
 wire net1236;
 wire net595;
 wire net596;
 wire net597;
 wire net598;
 wire net599;
 wire net600;
 wire net601;
 wire net602;
 wire net603;
 wire net604;
 wire net434;
 wire net605;
 wire net606;
 wire net607;
 wire net608;
 wire net609;
 wire net610;
 wire net611;
 wire net612;
 wire net613;
 wire net614;
 wire net1241;
 wire net435;
 wire net615;
 wire net616;
 wire net617;
 wire net618;
 wire net619;
 wire net620;
 wire net621;
 wire net622;
 wire net623;
 wire net624;
 wire net436;
 wire net625;
 wire net626;
 wire net627;
 wire net628;
 wire net629;
 wire net630;
 wire net631;
 wire net632;
 wire net1186;
 wire net437;
 wire net1183;
 wire net1184;
 wire net1182;
 wire net1185;
 wire net1187;
 wire net1181;
 wire net1174;
 wire net1173;
 wire net1172;
 wire net1171;
 wire net438;
 wire net1170;
 wire net1169;
 wire net1168;
 wire net1167;
 wire net1166;
 wire net1165;
 wire net1164;
 wire net1163;
 wire net1162;
 wire net1161;
 wire net439;
 wire net1179;
 wire net1178;
 wire net1159;
 wire net1160;
 wire net1157;
 wire clknet_leaf_26_clk_i;
 wire net1180;
 wire net1175;
 wire net1154;
 wire net1158;
 wire net440;
 wire clknet_leaf_25_clk_i;
 wire net1200;
 wire net1191;
 wire net1188;
 wire net1153;
 wire net1148;
 wire net1147;
 wire net1145;
 wire net1156;
 wire net1155;
 wire net441;
 wire net1177;
 wire net1144;
 wire net1143;
 wire net1146;
 wire net1141;
 wire net1149;
 wire net1142;
 wire net1140;
 wire net1139;
 wire net1138;
 wire net442;
 wire net1137;
 wire net1136;
 wire net1135;
 wire net1134;
 wire net1133;
 wire net1132;
 wire net1131;
 wire net1130;
 wire clknet_leaf_27_clk_i;
 wire net1176;
 wire net443;
 wire net1128;
 wire clknet_leaf_28_clk_i;
 wire net1129;
 wire net1127;
 wire net1126;
 wire net1125;
 wire net1124;
 wire net1123;
 wire net1122;
 wire net1121;
 wire net444;
 wire net1120;
 wire net1119;
 wire net1118;
 wire net1117;
 wire net1116;
 wire net1115;
 wire net1114;
 wire net1113;
 wire net1112;
 wire net1111;
 wire net1240;
 wire net445;
 wire net1110;
 wire net1109;
 wire net1108;
 wire net1107;
 wire net1106;
 wire net1105;
 wire net1104;
 wire net1103;
 wire net1102;
 wire net1101;
 wire net446;
 wire net1100;
 wire net1099;
 wire net1098;
 wire net1097;
 wire net1095;
 wire clknet_leaf_29_clk_i;
 wire net1096;
 wire net1093;
 wire net447;
 wire net448;
 wire net449;
 wire net450;
 wire net451;
 wire net452;
 wire net453;
 wire net454;
 wire net1231;
 wire net455;
 wire net456;
 wire net457;
 wire net458;
 wire net459;
 wire net460;
 wire net461;
 wire net462;
 wire net463;
 wire net464;
 wire net1230;
 wire net465;
 wire net466;
 wire net467;
 wire net468;
 wire net469;
 wire net470;
 wire net471;
 wire net472;
 wire net473;
 wire net474;
 wire net1229;
 wire net475;
 wire net476;
 wire net477;
 wire net478;
 wire net479;
 wire net480;
 wire net481;
 wire net482;
 wire net483;
 wire net484;
 wire net1232;
 wire net485;
 wire net486;
 wire net487;
 wire net488;
 wire net489;
 wire net490;
 wire net491;
 wire net492;
 wire net493;
 wire net494;
 wire net1226;
 wire net495;
 wire net496;
 wire net497;
 wire net498;
 wire net499;
 wire net500;
 wire net501;
 wire net502;
 wire net503;
 wire net504;
 wire net1225;
 wire net505;
 wire net506;
 wire net507;
 wire net508;
 wire net509;
 wire net510;
 wire net511;
 wire net512;
 wire net513;
 wire net514;
 wire reg2hw_0_;
 wire reg2hw_10_;
 wire reg2hw_11_;
 wire reg2hw_12_;
 wire reg2hw_1_;
 wire reg2hw_34_;
 wire reg2hw_35_;
 wire reg2hw_36_;
 wire reg2hw_37_;
 wire reg2hw_38_;
 wire reg2hw_39_;
 wire reg2hw_3_;
 wire reg2hw_40_;
 wire reg2hw_48_;
 wire reg2hw_4_;
 wire reg2hw_51_;
 wire reg2hw_53_;
 wire reg2hw_54_;
 wire reg2hw_56_;
 wire reg2hw_5_;
 wire reg2hw_6_;
 wire reg2hw_7_;
 wire reg2hw_8_;
 wire reg2hw_9_;
 wire reg_rst_ni;
 wire net633;
 wire net634;
 wire net635;
 wire net636;
 wire net637;
 wire net638;
 wire net639;
 wire net640;
 wire net641;
 wire net642;
 wire net643;
 wire net644;
 wire net645;
 wire net646;
 wire net647;
 wire net648;
 wire net649;
 wire net650;
 wire net651;
 wire net652;
 wire net653;
 wire net654;
 wire net655;
 wire net656;
 wire net657;
 wire net658;
 wire net659;
 wire net660;
 wire net661;
 wire net662;
 wire net663;
 wire net664;
 wire net665;
 wire net666;
 wire net667;
 wire net668;
 wire net669;
 wire net670;
 wire net671;
 wire net672;
 wire net673;
 wire net674;
 wire net675;
 wire net676;
 wire net677;
 wire net678;
 wire net679;
 wire net680;
 wire net681;
 wire net682;
 wire net683;
 wire net684;
 wire net685;
 wire net686;
 wire net687;
 wire net688;
 wire net689;
 wire net690;
 wire net691;
 wire net692;
 wire net693;
 wire net694;
 wire net695;
 wire net696;
 wire net697;
 wire net698;
 wire net699;
 wire net700;
 wire net701;
 wire net702;
 wire net703;
 wire net704;
 wire net705;
 wire net706;
 wire net707;
 wire net708;
 wire net709;
 wire net710;
 wire net711;
 wire net712;
 wire net713;
 wire net714;
 wire net715;
 wire net716;
 wire net717;
 wire net718;
 wire net719;
 wire net720;
 wire net721;
 wire net722;
 wire net723;
 wire net724;
 wire net725;
 wire net726;
 wire net727;
 wire net728;
 wire net729;
 wire u_core_reset_sync_intq;
 wire u_reg_reset_sync_intq;
 wire u_uart_core_nco_sum_q_0_;
 wire u_uart_core_nco_sum_q_10_;
 wire u_uart_core_nco_sum_q_11_;
 wire u_uart_core_nco_sum_q_12_;
 wire u_uart_core_nco_sum_q_13_;
 wire u_uart_core_nco_sum_q_14_;
 wire u_uart_core_nco_sum_q_15_;
 wire u_uart_core_nco_sum_q_16_;
 wire u_uart_core_nco_sum_q_1_;
 wire u_uart_core_nco_sum_q_2_;
 wire u_uart_core_nco_sum_q_3_;
 wire u_uart_core_nco_sum_q_4_;
 wire u_uart_core_nco_sum_q_5_;
 wire u_uart_core_nco_sum_q_6_;
 wire u_uart_core_nco_sum_q_7_;
 wire u_uart_core_nco_sum_q_8_;
 wire u_uart_core_nco_sum_q_9_;
 wire u_uart_core_rx_rst_ni;
 wire u_uart_core_rx_tick_baud;
 wire u_uart_core_rx_valid;
 wire u_uart_core_timing_rst_ni;
 wire u_uart_core_tx_rst_ni;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_0_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_1_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_0_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_0_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_100_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_101_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_102_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_103_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_104_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_105_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_106_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_107_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_108_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_109_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_10_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_110_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_111_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_112_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_113_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_114_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_115_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_116_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_117_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_118_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_119_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_11_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_120_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_121_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_122_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_123_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_124_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_125_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_126_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_127_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_12_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_13_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_14_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_15_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_16_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_17_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_18_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_19_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_1_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_20_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_21_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_22_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_23_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_24_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_25_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_26_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_27_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_28_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_29_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_2_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_30_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_31_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_32_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_33_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_34_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_35_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_36_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_37_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_38_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_39_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_3_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_40_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_41_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_42_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_43_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_44_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_45_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_46_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_47_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_48_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_49_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_4_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_50_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_51_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_52_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_53_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_54_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_55_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_56_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_57_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_58_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_59_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_5_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_60_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_61_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_62_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_63_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_64_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_65_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_66_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_67_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_68_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_69_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_6_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_70_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_71_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_72_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_73_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_74_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_75_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_76_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_77_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_78_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_79_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_7_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_80_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_81_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_82_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_83_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_84_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_85_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_86_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_87_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_88_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_89_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_8_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_90_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_91_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_92_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_93_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_94_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_95_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_96_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_97_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_98_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_99_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_9_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_;
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_2_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_0_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_0_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_10_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_11_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_12_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_13_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_14_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_15_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_16_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_17_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_18_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_19_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_1_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_20_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_21_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_22_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_23_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_24_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_25_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_26_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_27_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_28_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_29_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_2_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_30_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_31_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_32_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_33_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_34_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_35_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_36_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_37_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_38_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_39_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_3_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_40_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_41_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_42_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_43_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_44_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_45_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_46_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_47_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_48_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_49_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_4_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_50_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_51_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_52_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_53_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_54_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_55_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_56_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_57_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_58_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_59_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_5_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_60_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_61_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_62_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_63_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_6_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_7_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_8_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_9_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_;
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_;
 wire u_uart_core_uart_rx_baud_div_q_0_;
 wire u_uart_core_uart_rx_baud_div_q_1_;
 wire u_uart_core_uart_rx_baud_div_q_2_;
 wire u_uart_core_uart_rx_baud_div_q_3_;
 wire u_uart_core_uart_rx_bit_cnt_q_0_;
 wire u_uart_core_uart_rx_bit_cnt_q_1_;
 wire u_uart_core_uart_rx_bit_cnt_q_2_;
 wire u_uart_core_uart_rx_bit_cnt_q_3_;
 wire u_uart_core_uart_rx_sreg_q_10_;
 wire u_uart_core_uart_rx_sreg_q_1_;
 wire u_uart_core_uart_rx_sreg_q_2_;
 wire u_uart_core_uart_rx_sreg_q_3_;
 wire u_uart_core_uart_rx_sreg_q_4_;
 wire u_uart_core_uart_rx_sreg_q_5_;
 wire u_uart_core_uart_rx_sreg_q_6_;
 wire u_uart_core_uart_rx_sreg_q_7_;
 wire u_uart_core_uart_rx_sreg_q_8_;
 wire u_uart_core_uart_rx_sreg_q_9_;
 wire u_uart_core_uart_rx_tick_baud_d;
 wire u_uart_core_uart_tx_baud_div_q_0_;
 wire u_uart_core_uart_tx_baud_div_q_1_;
 wire u_uart_core_uart_tx_baud_div_q_2_;
 wire u_uart_core_uart_tx_baud_div_q_3_;
 wire u_uart_core_uart_tx_bit_cnt_q_0_;
 wire u_uart_core_uart_tx_bit_cnt_q_1_;
 wire u_uart_core_uart_tx_bit_cnt_q_2_;
 wire u_uart_core_uart_tx_bit_cnt_q_3_;
 wire u_uart_core_uart_tx_tick_baud_q;
 wire clknet_leaf_14_clk_i;
 wire net1244;
 wire net1243;
 wire clknet_leaf_11_clk_i;
 wire clknet_leaf_6_clk_i;
 wire net1239;
 wire net1220;
 wire net1242;
 wire clknet_leaf_10_clk_i;
 wire clknet_leaf_9_clk_i;
 wire clknet_leaf_8_clk_i;
 wire net1224;
 wire net1234;
 wire net1233;
 wire net1219;
 wire net1228;
 wire net1221;
 wire net1215;
 wire net1214;
 wire net1212;
 wire net1208;
 wire net1213;
 wire net1209;
 wire net1207;
 wire net1205;
 wire clknet_leaf_21_clk_i;
 wire net1235;
 wire net1227;
 wire net1210;
 wire net1206;
 wire net1202;
 wire net1216;
 wire net1218;
 wire net1201;
 wire net1217;
 wire net1194;
 wire net1203;
 wire net1196;
 wire clknet_leaf_24_clk_i;
 wire clknet_leaf_23_clk_i;
 wire clknet_leaf_22_clk_i;
 wire net1211;
 wire net1204;
 wire net1197;
 wire net1198;
 wire net1189;
 wire clknet_leaf_15_clk_i;
 wire clknet_3_3__leaf_clk_i;
 wire net1238;
 wire net1255;
 wire net1256;
 wire net1257;
 wire net1258;
 wire net1259;
 wire net1260;
 wire net1261;
 wire net1262;
 wire net1263;
 wire net1264;
 wire net1265;
 wire net1266;
 wire net1267;
 wire net1268;
 wire net1269;
 wire net1270;
 wire net1271;
 wire net1272;
 wire net1273;
 wire net1274;
 wire net1275;
 wire net1276;
 wire net1277;
 wire net1278;
 wire net1279;
 wire net1280;
 wire net1281;
 wire net1282;
 wire net1283;
 wire net1284;
 wire net1285;
 wire net1286;
 wire net1287;
 wire net1288;
 wire net1289;
 wire net1290;
 wire net1291;
 wire net1292;
 wire net1293;
 wire net1294;
 wire net1295;
 wire net1296;
 wire net1297;
 wire net1298;
 wire net1299;
 wire net1300;
 wire net1301;
 wire net1302;
 wire net1303;
 wire net1304;
 wire net1305;
 wire net1306;
 wire net1307;
 wire net1308;
 wire net1309;
 wire net1310;
 wire net1311;
 wire net1312;
 wire net1313;
 wire net1314;
 wire net1315;
 wire net1316;

 sg13g2_inv_1 _1476_ (.Y(_1297_),
    .A(_0047_));
 sg13g2_nor2_1 _1477_ (.A(reg2hw_37_),
    .B(_1297_),
    .Y(_0052_));
 sg13g2_inv_1 _1479_ (.Y(_0050_),
    .A(net634));
 sg13g2_nor2b_1 _1482_ (.A(_0019_),
    .B_N(u_uart_core_nco_sum_q_11_),
    .Y(_1298_));
 sg13g2_inv_1 _1483_ (.Y(_1299_),
    .A(_0019_));
 sg13g2_nor2_1 _1484_ (.A(u_uart_core_nco_sum_q_11_),
    .B(_1299_),
    .Y(_1300_));
 sg13g2_nor2_1 _1485_ (.A(_1298_),
    .B(_1300_),
    .Y(_1301_));
 sg13g2_inv_1 _1486_ (.Y(_1302_),
    .A(reg2hw_51_));
 sg13g2_nor2b_1 _1487_ (.A(_1302_),
    .B_N(u_uart_core_nco_sum_q_10_),
    .Y(_1303_));
 sg13g2_inv_2 _1488_ (.Y(_1304_),
    .A(_0023_));
 sg13g2_nor2_1 _1489_ (.A(u_uart_core_nco_sum_q_5_),
    .B(_1304_),
    .Y(_1305_));
 sg13g2_inv_1 _1490_ (.Y(_1306_),
    .A(_0024_));
 sg13g2_inv_1 _1491_ (.Y(_1307_),
    .A(_0026_));
 sg13g2_nor2b_1 _1492_ (.A(_0027_),
    .B_N(u_uart_core_nco_sum_q_1_),
    .Y(_1308_));
 sg13g2_inv_1 _1493_ (.Y(_1309_),
    .A(_0027_));
 sg13g2_nor2_1 _1494_ (.A(u_uart_core_nco_sum_q_1_),
    .B(_1309_),
    .Y(_1310_));
 sg13g2_nor2_1 _1495_ (.A(_1308_),
    .B(_1310_),
    .Y(_1311_));
 sg13g2_inv_1 _1496_ (.Y(_1312_),
    .A(_0028_));
 sg13g2_nand2_1 _1497_ (.Y(_1313_),
    .A(_1312_),
    .B(u_uart_core_nco_sum_q_0_));
 sg13g2_inv_1 _1498_ (.Y(_1314_),
    .A(_1313_));
 sg13g2_a21oi_1 _1499_ (.A1(_1311_),
    .A2(_1314_),
    .Y(_1315_),
    .B1(_1308_));
 sg13g2_xnor2_1 _1500_ (.Y(_1316_),
    .A(_0026_),
    .B(u_uart_core_nco_sum_q_2_));
 sg13g2_nor2b_1 _1501_ (.A(_1315_),
    .B_N(_1316_),
    .Y(_1317_));
 sg13g2_a21o_1 _1502_ (.A2(u_uart_core_nco_sum_q_2_),
    .A1(_1307_),
    .B1(_1317_),
    .X(_1318_));
 sg13g2_inv_1 _1503_ (.Y(_1319_),
    .A(u_uart_core_nco_sum_q_3_));
 sg13g2_nand2_1 _1504_ (.Y(_1320_),
    .A(_1319_),
    .B(_0025_));
 sg13g2_nor2_1 _1505_ (.A(_0025_),
    .B(_1319_),
    .Y(_1321_));
 sg13g2_a21oi_1 _1506_ (.A1(_1318_),
    .A2(_1320_),
    .Y(_1322_),
    .B1(_1321_));
 sg13g2_xnor2_1 _1507_ (.Y(_1323_),
    .A(_0024_),
    .B(u_uart_core_nco_sum_q_4_));
 sg13g2_nor2b_1 _1508_ (.A(_1322_),
    .B_N(_1323_),
    .Y(_1324_));
 sg13g2_a21oi_1 _1509_ (.A1(_1306_),
    .A2(u_uart_core_nco_sum_q_4_),
    .Y(_1325_),
    .B1(_1324_));
 sg13g2_nand2_1 _1510_ (.Y(_1326_),
    .A(_1304_),
    .B(u_uart_core_nco_sum_q_5_));
 sg13g2_o21ai_1 _1511_ (.B1(_1326_),
    .Y(_1327_),
    .A1(_1305_),
    .A2(_1325_));
 sg13g2_nor2_1 _1512_ (.A(reg2hw_48_),
    .B(u_uart_core_nco_sum_q_7_),
    .Y(_1328_));
 sg13g2_inv_1 _1513_ (.Y(_1329_),
    .A(reg2hw_48_));
 sg13g2_nor2b_1 _1514_ (.A(_1329_),
    .B_N(u_uart_core_nco_sum_q_7_),
    .Y(_1330_));
 sg13g2_nor2_1 _1515_ (.A(_1328_),
    .B(_1330_),
    .Y(_1331_));
 sg13g2_xnor2_1 _1516_ (.Y(_1332_),
    .A(_0022_),
    .B(u_uart_core_nco_sum_q_6_));
 sg13g2_nand3_1 _1517_ (.B(_1331_),
    .C(_1332_),
    .A(_1327_),
    .Y(_1333_));
 sg13g2_inv_1 _1518_ (.Y(_1334_),
    .A(_0022_));
 sg13g2_nand2_1 _1519_ (.Y(_1335_),
    .A(_1334_),
    .B(u_uart_core_nco_sum_q_6_));
 sg13g2_inv_1 _1520_ (.Y(_1336_),
    .A(_1335_));
 sg13g2_inv_1 _1521_ (.Y(_1337_),
    .A(_1328_));
 sg13g2_a21oi_1 _1522_ (.A1(_1336_),
    .A2(_1337_),
    .Y(_1338_),
    .B1(_1330_));
 sg13g2_nand2_1 _1523_ (.Y(_1339_),
    .A(_1333_),
    .B(_1338_));
 sg13g2_inv_1 _1524_ (.Y(_1340_),
    .A(u_uart_core_nco_sum_q_9_));
 sg13g2_nor2_1 _1525_ (.A(_0020_),
    .B(_1340_),
    .Y(_1341_));
 sg13g2_inv_1 _1526_ (.Y(_1342_),
    .A(_0020_));
 sg13g2_nor2_1 _1527_ (.A(u_uart_core_nco_sum_q_9_),
    .B(_1342_),
    .Y(_1343_));
 sg13g2_xnor2_1 _1528_ (.Y(_1344_),
    .A(_0021_),
    .B(u_uart_core_nco_sum_q_8_));
 sg13g2_inv_1 _1529_ (.Y(_1345_),
    .A(_1344_));
 sg13g2_nor3_1 _1530_ (.A(_1341_),
    .B(_1343_),
    .C(_1345_),
    .Y(_1346_));
 sg13g2_inv_1 _1531_ (.Y(_1347_),
    .A(_0021_));
 sg13g2_nand2_1 _1532_ (.Y(_1348_),
    .A(_1347_),
    .B(u_uart_core_nco_sum_q_8_));
 sg13g2_inv_1 _1533_ (.Y(_1349_),
    .A(_1341_));
 sg13g2_o21ai_1 _1534_ (.B1(_1349_),
    .Y(_1350_),
    .A1(_1348_),
    .A2(_1343_));
 sg13g2_a21oi_1 _1535_ (.A1(_1339_),
    .A2(_1346_),
    .Y(_1351_),
    .B1(_1350_));
 sg13g2_xor2_1 _1536_ (.B(u_uart_core_nco_sum_q_10_),
    .A(reg2hw_51_),
    .X(_1352_));
 sg13g2_nor2b_1 _1537_ (.A(_1351_),
    .B_N(_1352_),
    .Y(_1353_));
 sg13g2_nor2_1 _1538_ (.A(_1303_),
    .B(_1353_),
    .Y(_1354_));
 sg13g2_xnor2_1 _1539_ (.Y(_0004_),
    .A(_1301_),
    .B(_1354_));
 sg13g2_inv_1 _1540_ (.Y(_1355_),
    .A(reg2hw_54_));
 sg13g2_inv_1 _1541_ (.Y(_1356_),
    .A(u_uart_core_nco_sum_q_13_));
 sg13g2_nor2_1 _1542_ (.A(_1355_),
    .B(_1356_),
    .Y(_1357_));
 sg13g2_nand2_1 _1543_ (.Y(_1358_),
    .A(_1355_),
    .B(_1356_));
 sg13g2_nor2b_1 _1544_ (.A(_1357_),
    .B_N(_1358_),
    .Y(_1359_));
 sg13g2_inv_1 _1545_ (.Y(_1360_),
    .A(reg2hw_53_));
 sg13g2_nor2b_1 _1546_ (.A(_1360_),
    .B_N(u_uart_core_nco_sum_q_12_),
    .Y(_1361_));
 sg13g2_and3_1 _1547_ (.X(_1362_),
    .A(_1350_),
    .B(_1352_),
    .C(_1301_));
 sg13g2_nor2b_1 _1548_ (.A(_1300_),
    .B_N(_1303_),
    .Y(_1363_));
 sg13g2_and4_1 _1549_ (.A(_1346_),
    .B(_1339_),
    .C(_1352_),
    .D(_1301_),
    .X(_1364_));
 sg13g2_nor4_1 _1550_ (.A(_1298_),
    .B(_1362_),
    .C(_1363_),
    .D(_1364_),
    .Y(_1365_));
 sg13g2_xor2_1 _1551_ (.B(u_uart_core_nco_sum_q_12_),
    .A(reg2hw_53_),
    .X(_1366_));
 sg13g2_nor2b_1 _1552_ (.A(_1365_),
    .B_N(_1366_),
    .Y(_1367_));
 sg13g2_nor2_1 _1553_ (.A(_1361_),
    .B(_1367_),
    .Y(_1368_));
 sg13g2_xnor2_1 _1554_ (.Y(_0006_),
    .A(_1359_),
    .B(_1368_));
 sg13g2_a21oi_1 _1555_ (.A1(_1327_),
    .A2(_1332_),
    .Y(_1369_),
    .B1(_1336_));
 sg13g2_xnor2_1 _1556_ (.Y(_0015_),
    .A(_1331_),
    .B(_1369_));
 sg13g2_xnor2_1 _1557_ (.Y(_0002_),
    .A(_0028_),
    .B(u_uart_core_nco_sum_q_0_));
 sg13g2_a21oi_1 _1558_ (.A1(_1333_),
    .A2(_1338_),
    .Y(_1370_),
    .B1(_1345_));
 sg13g2_nor2_1 _1559_ (.A(_1344_),
    .B(_1339_),
    .Y(_1371_));
 sg13g2_nor2_1 _1560_ (.A(_1370_),
    .B(_1371_),
    .Y(_0016_));
 sg13g2_nor2_1 _1561_ (.A(reg2hw_56_),
    .B(u_uart_core_nco_sum_q_15_),
    .Y(_1372_));
 sg13g2_nand2_1 _1562_ (.Y(_1373_),
    .A(reg2hw_56_),
    .B(u_uart_core_nco_sum_q_15_));
 sg13g2_nor2b_1 _1563_ (.A(_1372_),
    .B_N(_1373_),
    .Y(_1374_));
 sg13g2_nand2_1 _1564_ (.Y(_1375_),
    .A(_1359_),
    .B(_1366_));
 sg13g2_o21ai_1 _1565_ (.B1(_1358_),
    .Y(_1376_),
    .A1(_1361_),
    .A2(_1357_));
 sg13g2_o21ai_1 _1566_ (.B1(_1376_),
    .Y(_1377_),
    .A1(_1375_),
    .A2(_1365_));
 sg13g2_xnor2_1 _1567_ (.Y(_1378_),
    .A(_0018_),
    .B(u_uart_core_nco_sum_q_14_));
 sg13g2_nor2b_1 _1568_ (.A(_0018_),
    .B_N(u_uart_core_nco_sum_q_14_),
    .Y(_1379_));
 sg13g2_a21oi_1 _1569_ (.A1(_1377_),
    .A2(_1378_),
    .Y(_1380_),
    .B1(_1379_));
 sg13g2_xnor2_1 _1570_ (.Y(_0008_),
    .A(_1374_),
    .B(_1380_));
 sg13g2_nor2b_1 _1571_ (.A(_1305_),
    .B_N(_1326_),
    .Y(_1381_));
 sg13g2_xnor2_1 _1572_ (.Y(_0013_),
    .A(_1381_),
    .B(_1325_));
 sg13g2_xor2_1 _1573_ (.B(_1377_),
    .A(_1378_),
    .X(_0007_));
 sg13g2_a21oi_1 _1574_ (.A1(_1380_),
    .A2(_1373_),
    .Y(_0001_),
    .B1(_1372_));
 sg13g2_xnor2_1 _1575_ (.Y(_0009_),
    .A(_1313_),
    .B(_1311_));
 sg13g2_xnor2_1 _1576_ (.Y(_0005_),
    .A(_1366_),
    .B(_1365_));
 sg13g2_inv_2 _1577_ (.Y(_1382_),
    .A(net672));
 sg13g2_nor2_1 _1578_ (.A(net672),
    .B(net673),
    .Y(_1383_));
 sg13g2_inv_1 _1579_ (.Y(_1384_),
    .A(_1383_));
 sg13g2_nor2_1 _1580_ (.A(net674),
    .B(_1384_),
    .Y(_1385_));
 sg13g2_inv_2 _1582_ (.Y(_1387_),
    .A(net1191));
 sg13g2_a21oi_1 _1583_ (.A1(_1384_),
    .A2(net674),
    .Y(_1388_),
    .B1(net666));
 sg13g2_inv_2 _1584_ (.Y(_1389_),
    .A(net674));
 sg13g2_nor3_2 _1585_ (.A(net673),
    .B(_1389_),
    .C(_1382_),
    .Y(_1390_));
 sg13g2_nand3_1 _1586_ (.B(net667),
    .C(net666),
    .A(net668),
    .Y(_1391_));
 sg13g2_o21ai_1 _1587_ (.B1(_1391_),
    .Y(_1392_),
    .A1(_1390_),
    .A2(net1191));
 sg13g2_nor2b_1 _1588_ (.A(_1388_),
    .B_N(_1392_),
    .Y(_1393_));
 sg13g2_o21ai_1 _1589_ (.B1(_1393_),
    .Y(_1394_),
    .A1(net669),
    .A2(_1387_));
 sg13g2_or2_1 _1590_ (.X(_1395_),
    .B(net671),
    .A(net670));
 sg13g2_inv_1 _1592_ (.Y(net683),
    .A(net728));
 sg13g2_nand2_1 _1593_ (.Y(_1397_),
    .A(net683),
    .B(net641));
 sg13g2_nor3_1 _1595_ (.A(net640),
    .B(net639),
    .C(_1397_),
    .Y(_1399_));
 sg13g2_inv_1 _1596_ (.Y(_1400_),
    .A(net1313));
 sg13g2_nor2_1 _1597_ (.A(net1285),
    .B(_1400_),
    .Y(_1401_));
 sg13g2_nand3_1 _1598_ (.B(_1389_),
    .C(net673),
    .A(_1401_),
    .Y(_1402_));
 sg13g2_nor3_1 _1599_ (.A(_1382_),
    .B(_1394_),
    .C(_1402_),
    .Y(_1403_));
 sg13g2_inv_2 _1601_ (.Y(_1404_),
    .A(reg2hw_11_));
 sg13g2_nand2_1 _1602_ (.Y(_1405_),
    .A(net1145),
    .B(net648));
 sg13g2_o21ai_1 _1603_ (.B1(_1405_),
    .Y(_0053_),
    .A1(_1404_),
    .A2(net1146));
 sg13g2_inv_2 _1604_ (.Y(_1406_),
    .A(reg2hw_10_));
 sg13g2_nand2_1 _1605_ (.Y(_1407_),
    .A(net1304),
    .B(net647));
 sg13g2_o21ai_1 _1606_ (.B1(_1407_),
    .Y(_0054_),
    .A1(_1406_),
    .A2(net1146));
 sg13g2_inv_2 _1607_ (.Y(_1408_),
    .A(reg2hw_9_));
 sg13g2_nand2_1 _1608_ (.Y(_1409_),
    .A(net1145),
    .B(net646));
 sg13g2_o21ai_1 _1609_ (.B1(_1409_),
    .Y(_0055_),
    .A1(_1408_),
    .A2(net1146));
 sg13g2_inv_2 _1610_ (.Y(_1410_),
    .A(reg2hw_8_));
 sg13g2_nand2_1 _1611_ (.Y(_1411_),
    .A(net1146),
    .B(net645));
 sg13g2_o21ai_1 _1612_ (.B1(net1276),
    .Y(_0056_),
    .A1(_1410_),
    .A2(net1146));
 sg13g2_inv_2 _1613_ (.Y(_1412_),
    .A(reg2hw_7_));
 sg13g2_nand2_1 _1614_ (.Y(_1413_),
    .A(net1304),
    .B(net644));
 sg13g2_o21ai_1 _1615_ (.B1(_1413_),
    .Y(_0057_),
    .A1(_1412_),
    .A2(net1146));
 sg13g2_inv_2 _1616_ (.Y(_1414_),
    .A(reg2hw_6_));
 sg13g2_nand2_1 _1617_ (.Y(_1415_),
    .A(net1145),
    .B(net643));
 sg13g2_o21ai_1 _1618_ (.B1(_1415_),
    .Y(_0058_),
    .A1(_1414_),
    .A2(net1145));
 sg13g2_inv_2 _1619_ (.Y(_1416_),
    .A(reg2hw_5_));
 sg13g2_nand2_1 _1620_ (.Y(_1417_),
    .A(net1145),
    .B(net642));
 sg13g2_o21ai_1 _1621_ (.B1(_1417_),
    .Y(_0059_),
    .A1(_1416_),
    .A2(net1145));
 sg13g2_inv_1 _1622_ (.Y(_1418_),
    .A(_0018_));
 sg13g2_nor4_1 _1623_ (.A(_1387_),
    .B(_1400_),
    .C(_1395_),
    .D(_1394_),
    .Y(_1419_));
 sg13g2_nand2b_1 _1626_ (.Y(_1422_),
    .B(_1419_),
    .A_N(net664));
 sg13g2_o21ai_1 _1627_ (.B1(net1273),
    .Y(_0060_),
    .A1(_1418_),
    .A2(net1147));
 sg13g2_nand2_1 _1628_ (.Y(_1423_),
    .A(_1419_),
    .B(net663));
 sg13g2_o21ai_1 _1629_ (.B1(net1263),
    .Y(_0061_),
    .A1(_1355_),
    .A2(net1147));
 sg13g2_nand2_1 _1630_ (.Y(_1424_),
    .A(_1419_),
    .B(net662));
 sg13g2_o21ai_1 _1631_ (.B1(net1258),
    .Y(_0062_),
    .A1(_1360_),
    .A2(net1147));
 sg13g2_nand2b_1 _1632_ (.Y(_1425_),
    .B(net1147),
    .A_N(net661));
 sg13g2_o21ai_1 _1633_ (.B1(_1425_),
    .Y(_0063_),
    .A1(_1299_),
    .A2(net1147));
 sg13g2_nand2_1 _1634_ (.Y(_1426_),
    .A(net1147),
    .B(net660));
 sg13g2_o21ai_1 _1635_ (.B1(_1426_),
    .Y(_0064_),
    .A1(_1302_),
    .A2(net1147));
 sg13g2_nand2b_1 _1636_ (.Y(_1427_),
    .B(net1150),
    .A_N(net659));
 sg13g2_o21ai_1 _1637_ (.B1(_1427_),
    .Y(_0065_),
    .A1(_1342_),
    .A2(net1150));
 sg13g2_nand2b_1 _1638_ (.Y(_1428_),
    .B(net1150),
    .A_N(net658));
 sg13g2_o21ai_1 _1639_ (.B1(_1428_),
    .Y(_0066_),
    .A1(_1347_),
    .A2(net1150));
 sg13g2_nand2_1 _1640_ (.Y(_1429_),
    .A(net1150),
    .B(net657));
 sg13g2_o21ai_1 _1641_ (.B1(_1429_),
    .Y(_0067_),
    .A1(_1329_),
    .A2(net1150));
 sg13g2_nand2b_1 _1642_ (.Y(_1430_),
    .B(net1149),
    .A_N(net656));
 sg13g2_o21ai_1 _1643_ (.B1(_1430_),
    .Y(_0068_),
    .A1(_1334_),
    .A2(net1149));
 sg13g2_nand2b_1 _1644_ (.Y(_1431_),
    .B(net1149),
    .A_N(net655));
 sg13g2_o21ai_1 _1645_ (.B1(_1431_),
    .Y(_0069_),
    .A1(_1304_),
    .A2(net1149));
 sg13g2_nand2b_1 _1646_ (.Y(_1432_),
    .B(net1149),
    .A_N(net654));
 sg13g2_o21ai_1 _1647_ (.B1(_1432_),
    .Y(_0070_),
    .A1(_1306_),
    .A2(net1148));
 sg13g2_inv_1 _1648_ (.Y(_1433_),
    .A(_0025_));
 sg13g2_nand2b_1 _1649_ (.Y(_1434_),
    .B(net1148),
    .A_N(net653));
 sg13g2_o21ai_1 _1650_ (.B1(_1434_),
    .Y(_0071_),
    .A1(_1433_),
    .A2(net1148));
 sg13g2_nand2b_1 _1651_ (.Y(_1435_),
    .B(net1148),
    .A_N(net652));
 sg13g2_o21ai_1 _1652_ (.B1(_1435_),
    .Y(_0072_),
    .A1(_1307_),
    .A2(net1148));
 sg13g2_nand2b_1 _1653_ (.Y(_1436_),
    .B(net1148),
    .A_N(net651));
 sg13g2_o21ai_1 _1654_ (.B1(_1436_),
    .Y(_0073_),
    .A1(_1309_),
    .A2(net1148));
 sg13g2_nand2b_1 _1655_ (.Y(_1437_),
    .B(net1149),
    .A_N(net650));
 sg13g2_o21ai_1 _1656_ (.B1(_1437_),
    .Y(_0074_),
    .A1(_1312_),
    .A2(net1148));
 sg13g2_mux2_1 _1657_ (.A0(net636),
    .A1(net725),
    .S(net1186),
    .X(_0075_));
 sg13g2_mux2_1 _1658_ (.A0(net681),
    .A1(net723),
    .S(net1187),
    .X(_0076_));
 sg13g2_mux2_1 _1659_ (.A0(net680),
    .A1(net722),
    .S(net1186),
    .X(_0077_));
 sg13g2_mux2_1 _1660_ (.A0(net679),
    .A1(net721),
    .S(net1186),
    .X(_0078_));
 sg13g2_mux2_1 _1661_ (.A0(net678),
    .A1(net720),
    .S(net1186),
    .X(_0079_));
 sg13g2_mux2_1 _1662_ (.A0(net677),
    .A1(net719),
    .S(net1186),
    .X(_0080_));
 sg13g2_mux2_1 _1663_ (.A0(net676),
    .A1(net718),
    .S(net1186),
    .X(_0081_));
 sg13g2_mux2_1 _1664_ (.A0(net675),
    .A1(net717),
    .S(net1186),
    .X(_0082_));
 sg13g2_inv_1 _1665_ (.Y(_1438_),
    .A(net715));
 sg13g2_nand2_1 _1667_ (.Y(_1440_),
    .A(net1189),
    .B(_1418_));
 sg13g2_nor2b_1 _1668_ (.A(_1389_),
    .B_N(net673),
    .Y(_1441_));
 sg13g2_nor3_1 _1669_ (.A(net1188),
    .B(_1441_),
    .C(_1399_),
    .Y(_1442_));
 sg13g2_a22oi_1 _1671_ (.Y(_0083_),
    .B1(_1440_),
    .B2(net1156),
    .A2(net1185),
    .A1(_1438_));
 sg13g2_inv_1 _1672_ (.Y(_1444_),
    .A(net714));
 sg13g2_nand2_1 _1673_ (.Y(_1445_),
    .A(net1189),
    .B(reg2hw_54_));
 sg13g2_a22oi_1 _1674_ (.Y(_0084_),
    .B1(_1445_),
    .B2(net1156),
    .A2(net1187),
    .A1(_1444_));
 sg13g2_inv_1 _1675_ (.Y(_1446_),
    .A(net713));
 sg13g2_nand2_1 _1676_ (.Y(_1447_),
    .A(net1189),
    .B(reg2hw_53_));
 sg13g2_a22oi_1 _1677_ (.Y(_0085_),
    .B1(_1447_),
    .B2(net1156),
    .A2(net1185),
    .A1(_1446_));
 sg13g2_inv_1 _1678_ (.Y(_1448_),
    .A(net712));
 sg13g2_nand2_1 _1679_ (.Y(_1449_),
    .A(net1189),
    .B(_1299_));
 sg13g2_a22oi_1 _1680_ (.Y(_0086_),
    .B1(_1449_),
    .B2(net1156),
    .A2(net1185),
    .A1(_1448_));
 sg13g2_inv_1 _1681_ (.Y(_1450_),
    .A(net711));
 sg13g2_nand2_1 _1682_ (.Y(_1451_),
    .A(net1189),
    .B(reg2hw_51_));
 sg13g2_a22oi_1 _1683_ (.Y(_0087_),
    .B1(_1451_),
    .B2(net1156),
    .A2(net1185),
    .A1(_1450_));
 sg13g2_inv_1 _1684_ (.Y(_1452_),
    .A(net710));
 sg13g2_nand2_1 _1685_ (.Y(_1453_),
    .A(_1385_),
    .B(_1342_));
 sg13g2_a22oi_1 _1686_ (.Y(_0088_),
    .B1(_1453_),
    .B2(net1156),
    .A2(_1397_),
    .A1(_1452_));
 sg13g2_inv_1 _1687_ (.Y(_1454_),
    .A(net709));
 sg13g2_nand2_1 _1688_ (.Y(_1455_),
    .A(net1310),
    .B(_1347_));
 sg13g2_a22oi_1 _1689_ (.Y(_0089_),
    .B1(_1455_),
    .B2(net1155),
    .A2(_1397_),
    .A1(_1454_));
 sg13g2_inv_1 _1690_ (.Y(_1456_),
    .A(net708));
 sg13g2_nand2_1 _1691_ (.Y(_1457_),
    .A(net1310),
    .B(reg2hw_48_));
 sg13g2_a22oi_1 _1692_ (.Y(_0090_),
    .B1(_1457_),
    .B2(net1155),
    .A2(net1184),
    .A1(_1456_));
 sg13g2_inv_1 _1693_ (.Y(_1458_),
    .A(net707));
 sg13g2_nand2_1 _1694_ (.Y(_1459_),
    .A(net1310),
    .B(_1334_));
 sg13g2_a22oi_1 _1695_ (.Y(_0091_),
    .B1(_1459_),
    .B2(net1155),
    .A2(net1184),
    .A1(_1458_));
 sg13g2_inv_1 _1696_ (.Y(_1460_),
    .A(net706));
 sg13g2_nand2_1 _1697_ (.Y(_1461_),
    .A(net1310),
    .B(_1304_));
 sg13g2_a22oi_1 _1698_ (.Y(_0092_),
    .B1(_1461_),
    .B2(net1155),
    .A2(net1184),
    .A1(_1460_));
 sg13g2_inv_1 _1699_ (.Y(_1462_),
    .A(net705));
 sg13g2_inv_1 _1700_ (.Y(_1463_),
    .A(_1442_));
 sg13g2_a21oi_1 _1701_ (.A1(_1306_),
    .A2(net1190),
    .Y(_1464_),
    .B1(net1153));
 sg13g2_xnor2_1 _1702_ (.Y(_1465_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_));
 sg13g2_inv_1 _1703_ (.Y(_1466_),
    .A(_1465_));
 sg13g2_inv_1 _1704_ (.Y(_1467_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_));
 sg13g2_xnor2_1 _1705_ (.Y(_1468_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_));
 sg13g2_inv_1 _1706_ (.Y(_1469_),
    .A(_1468_));
 sg13g2_inv_1 _1707_ (.Y(_1470_),
    .A(net1224));
 sg13g2_inv_2 _1709_ (.Y(_1472_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_0_));
 sg13g2_xnor2_1 _1710_ (.Y(_0379_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_1_));
 sg13g2_inv_1 _1711_ (.Y(_0380_),
    .A(_0379_));
 sg13g2_a21oi_1 _1712_ (.A1(_1472_),
    .A2(net1227),
    .Y(_0381_),
    .B1(_0380_));
 sg13g2_a21oi_1 _1713_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_),
    .A2(net1202),
    .Y(_0382_),
    .B1(_0381_));
 sg13g2_nor2_1 _1714_ (.A(_1469_),
    .B(_0382_),
    .Y(_0383_));
 sg13g2_a21oi_1 _1715_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_),
    .A2(_1467_),
    .Y(_0384_),
    .B1(_0383_));
 sg13g2_inv_1 _1716_ (.Y(_0385_),
    .A(_0384_));
 sg13g2_inv_2 _1717_ (.Y(_0386_),
    .A(net1219));
 sg13g2_nor2_1 _1718_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_),
    .B(_0386_),
    .Y(_0387_));
 sg13g2_inv_1 _1719_ (.Y(_0388_),
    .A(_0387_));
 sg13g2_inv_2 _1720_ (.Y(_0389_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_));
 sg13g2_nor2_1 _1721_ (.A(net1219),
    .B(_0389_),
    .Y(_0390_));
 sg13g2_a21oi_1 _1722_ (.A1(_0385_),
    .A2(_0388_),
    .Y(_0391_),
    .B1(_0390_));
 sg13g2_nor2_1 _1723_ (.A(_0390_),
    .B(_0387_),
    .Y(_0392_));
 sg13g2_xnor2_1 _1724_ (.Y(_0393_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_0_),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_0_));
 sg13g2_and4_1 _1725_ (.A(_1468_),
    .B(_0392_),
    .C(_0379_),
    .D(_0393_),
    .X(_0394_));
 sg13g2_nor2_1 _1727_ (.A(_1465_),
    .B(_0394_),
    .Y(_0396_));
 sg13g2_inv_2 _1728_ (.Y(_0397_),
    .A(_1390_));
 sg13g2_a21oi_1 _1729_ (.A1(_0391_),
    .A2(_0396_),
    .Y(_0398_),
    .B1(_0397_));
 sg13g2_o21ai_1 _1730_ (.B1(_0398_),
    .Y(_0399_),
    .A1(_1466_),
    .A2(_0391_));
 sg13g2_a22oi_1 _1731_ (.Y(_0093_),
    .B1(_1464_),
    .B2(_0399_),
    .A2(net1184),
    .A1(_1462_));
 sg13g2_inv_1 _1732_ (.Y(_0400_),
    .A(net704));
 sg13g2_a21oi_1 _1733_ (.A1(_1433_),
    .A2(net1190),
    .Y(_0401_),
    .B1(net1153));
 sg13g2_a21oi_1 _1734_ (.A1(_0394_),
    .A2(_1466_),
    .Y(_0402_),
    .B1(_0397_));
 sg13g2_o21ai_1 _1735_ (.B1(_0402_),
    .Y(_0403_),
    .A1(_0392_),
    .A2(_0385_));
 sg13g2_a21o_1 _1736_ (.A2(_0392_),
    .A1(_0385_),
    .B1(_0403_),
    .X(_0404_));
 sg13g2_a22oi_1 _1737_ (.Y(_0094_),
    .B1(_0401_),
    .B2(_0404_),
    .A2(net1183),
    .A1(_0400_));
 sg13g2_inv_1 _1738_ (.Y(_0405_),
    .A(net703));
 sg13g2_a21oi_1 _1739_ (.A1(_1307_),
    .A2(net1190),
    .Y(_0406_),
    .B1(net1153));
 sg13g2_nand2_1 _1740_ (.Y(_0407_),
    .A(_0382_),
    .B(_1469_));
 sg13g2_nand3b_1 _1741_ (.B(_0402_),
    .C(_0407_),
    .Y(_0408_),
    .A_N(_0383_));
 sg13g2_a22oi_1 _1742_ (.Y(_0095_),
    .B1(_0406_),
    .B2(_0408_),
    .A2(net1183),
    .A1(_0405_));
 sg13g2_inv_1 _1743_ (.Y(_0409_),
    .A(net702));
 sg13g2_a21oi_1 _1744_ (.A1(_1309_),
    .A2(net1190),
    .Y(_0410_),
    .B1(net1153));
 sg13g2_nand3_1 _1745_ (.B(_1472_),
    .C(net1227),
    .A(_0380_),
    .Y(_0411_));
 sg13g2_nand3b_1 _1746_ (.B(_0402_),
    .C(_0411_),
    .Y(_0412_),
    .A_N(_0381_));
 sg13g2_a22oi_1 _1747_ (.Y(_0096_),
    .B1(_0410_),
    .B2(_0412_),
    .A2(net1183),
    .A1(_0409_));
 sg13g2_inv_1 _1748_ (.Y(_0413_),
    .A(net701));
 sg13g2_inv_1 _1749_ (.Y(_0414_),
    .A(_0393_));
 sg13g2_a22oi_1 _1750_ (.Y(_0415_),
    .B1(_1390_),
    .B2(_0414_),
    .A2(_1312_),
    .A1(net1190));
 sg13g2_a22oi_1 _1751_ (.Y(_0097_),
    .B1(net1154),
    .B2(_0415_),
    .A2(net1182),
    .A1(_0413_));
 sg13g2_inv_1 _1752_ (.Y(_0416_),
    .A(net700));
 sg13g2_a21oi_1 _1753_ (.A1(_0416_),
    .A2(net1182),
    .Y(_0098_),
    .B1(net1154));
 sg13g2_inv_1 _1754_ (.Y(_0417_),
    .A(net699));
 sg13g2_a21oi_1 _1755_ (.A1(_0417_),
    .A2(net1182),
    .Y(_0099_),
    .B1(net1154));
 sg13g2_inv_1 _1756_ (.Y(_0418_),
    .A(net698));
 sg13g2_a21oi_1 _1757_ (.A1(_0418_),
    .A2(net1184),
    .Y(_0100_),
    .B1(net1155));
 sg13g2_inv_1 _1758_ (.Y(_0419_),
    .A(net697));
 sg13g2_a21oi_1 _1759_ (.A1(_0419_),
    .A2(net1184),
    .Y(_0101_),
    .B1(net1155));
 sg13g2_inv_1 _1760_ (.Y(_0420_),
    .A(net696));
 sg13g2_a21oi_1 _1761_ (.A1(_0420_),
    .A2(net1184),
    .Y(_0102_),
    .B1(net1155));
 sg13g2_inv_1 _1762_ (.Y(_0421_),
    .A(net695));
 sg13g2_a21oi_1 _1763_ (.A1(_0421_),
    .A2(net1182),
    .Y(_0103_),
    .B1(net1154));
 sg13g2_inv_1 _1764_ (.Y(_0422_),
    .A(net694));
 sg13g2_a21oi_1 _1765_ (.A1(_0422_),
    .A2(net1182),
    .Y(_0104_),
    .B1(net1154));
 sg13g2_inv_1 _1766_ (.Y(_0423_),
    .A(net693));
 sg13g2_a21oi_1 _1767_ (.A1(_0423_),
    .A2(net1182),
    .Y(_0105_),
    .B1(net1154));
 sg13g2_inv_1 _1768_ (.Y(_0424_),
    .A(net692));
 sg13g2_a21oi_1 _1769_ (.A1(reg2hw_40_),
    .A2(net1190),
    .Y(_0425_),
    .B1(net1153));
 sg13g2_inv_1 _1770_ (.Y(_0426_),
    .A(net1228));
 sg13g2_inv_1 _1773_ (.Y(_0429_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_71_));
 sg13g2_o21ai_1 _1774_ (.B1(net1204),
    .Y(_0430_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_79_),
    .A2(net1198));
 sg13g2_a21o_1 _1775_ (.A2(_0429_),
    .A1(net1198),
    .B1(_0430_),
    .X(_0431_));
 sg13g2_nor2_1 _1776_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_0_),
    .B(_1470_),
    .Y(_0432_));
 sg13g2_nor2_2 _1778_ (.A(net1204),
    .B(_0426_),
    .Y(_0434_));
 sg13g2_a221oi_1 _1780_ (.B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_95_),
    .C1(net1221),
    .B1(net1173),
    .A1(net1179),
    .Y(_0436_),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_87_));
 sg13g2_a221oi_1 _1781_ (.B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_127_),
    .C1(net1206),
    .B1(net1175),
    .A1(net1180),
    .Y(_0437_),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_119_));
 sg13g2_inv_1 _1782_ (.Y(_0438_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_103_));
 sg13g2_o21ai_1 _1783_ (.B1(net1204),
    .Y(_0439_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_111_),
    .A2(net1198));
 sg13g2_a21o_1 _1784_ (.A2(_0438_),
    .A1(net1198),
    .B1(_0439_),
    .X(_0440_));
 sg13g2_a22oi_1 _1785_ (.Y(_0441_),
    .B1(_0437_),
    .B2(_0440_),
    .A2(_0436_),
    .A1(_0431_));
 sg13g2_nand2b_1 _1786_ (.Y(_0442_),
    .B(net1219),
    .A_N(_0441_));
 sg13g2_nand2b_1 _1787_ (.Y(_0443_),
    .B(net1200),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_7_));
 sg13g2_inv_1 _1788_ (.Y(_0444_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_15_));
 sg13g2_a21oi_1 _1789_ (.A1(_0444_),
    .A2(net1226),
    .Y(_0445_),
    .B1(net1222));
 sg13g2_a21o_1 _1790_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_23_),
    .A1(net1178),
    .B1(net1220),
    .X(_0446_));
 sg13g2_a221oi_1 _1791_ (.B2(_0445_),
    .C1(_0446_),
    .B1(_0443_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_31_),
    .Y(_0447_),
    .A2(net1174));
 sg13g2_nand2b_1 _1792_ (.Y(_0448_),
    .B(net1225),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_47_));
 sg13g2_inv_1 _1793_ (.Y(_0449_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_39_));
 sg13g2_a21oi_1 _1794_ (.A1(net1199),
    .A2(_0449_),
    .Y(_0450_),
    .B1(net1223));
 sg13g2_a21o_1 _1795_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_63_),
    .A1(net1175),
    .B1(net1206),
    .X(_0451_));
 sg13g2_a221oi_1 _1796_ (.B2(_0450_),
    .C1(_0451_),
    .B1(_0448_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_55_),
    .Y(_0452_),
    .A2(net1180));
 sg13g2_o21ai_1 _1797_ (.B1(net1201),
    .Y(_0453_),
    .A1(_0447_),
    .A2(_0452_));
 sg13g2_nand3_1 _1798_ (.B(_1382_),
    .C(net673),
    .A(_1389_),
    .Y(_0454_));
 sg13g2_a21oi_2 _1799_ (.B1(_0454_),
    .Y(_0455_),
    .A2(_1465_),
    .A1(_0394_));
 sg13g2_nand3_1 _1800_ (.B(_0453_),
    .C(_0455_),
    .A(_0442_),
    .Y(_0456_));
 sg13g2_a22oi_1 _1801_ (.Y(_0106_),
    .B1(_0425_),
    .B2(_0456_),
    .A2(net1183),
    .A1(_0424_));
 sg13g2_inv_1 _1802_ (.Y(_0457_),
    .A(net691));
 sg13g2_a21oi_1 _1803_ (.A1(reg2hw_39_),
    .A2(net1190),
    .Y(_0458_),
    .B1(net1153));
 sg13g2_nand2b_1 _1804_ (.Y(_0459_),
    .B(net1228),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_78_));
 sg13g2_inv_1 _1805_ (.Y(_0460_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_70_));
 sg13g2_a21oi_1 _1806_ (.A1(net1198),
    .A2(_0460_),
    .Y(_0461_),
    .B1(net1223));
 sg13g2_a21o_1 _1807_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_86_),
    .A1(net1179),
    .B1(net1221),
    .X(_0462_));
 sg13g2_a221oi_1 _1808_ (.B2(_0461_),
    .C1(_0462_),
    .B1(_0459_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_94_),
    .Y(_0463_),
    .A2(net1173));
 sg13g2_inv_1 _1809_ (.Y(_0464_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_102_));
 sg13g2_o21ai_1 _1810_ (.B1(net1204),
    .Y(_0465_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_110_),
    .A2(net1199));
 sg13g2_a21o_1 _1811_ (.A2(_0464_),
    .A1(net1199),
    .B1(_0465_),
    .X(_0466_));
 sg13g2_a22oi_1 _1812_ (.Y(_0467_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_126_),
    .B2(net1174),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_118_),
    .A1(net1178));
 sg13g2_and3_1 _1813_ (.X(_0468_),
    .A(_0466_),
    .B(net1220),
    .C(_0467_));
 sg13g2_o21ai_1 _1814_ (.B1(net1219),
    .Y(_0469_),
    .A1(_0463_),
    .A2(_0468_));
 sg13g2_nand2b_1 _1815_ (.Y(_0470_),
    .B(net1226),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_14_));
 sg13g2_inv_1 _1816_ (.Y(_0471_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_6_));
 sg13g2_a21oi_1 _1817_ (.A1(net1200),
    .A2(_0471_),
    .Y(_0472_),
    .B1(net1222));
 sg13g2_a21o_1 _1818_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_22_),
    .A1(net1178),
    .B1(net1220),
    .X(_0473_));
 sg13g2_a221oi_1 _1819_ (.B2(_0472_),
    .C1(_0473_),
    .B1(_0470_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_30_),
    .Y(_0474_),
    .A2(net1174));
 sg13g2_inv_1 _1820_ (.Y(_0475_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_46_));
 sg13g2_a21oi_1 _1821_ (.A1(_0475_),
    .A2(net1225),
    .Y(_0476_),
    .B1(net1223));
 sg13g2_nand2b_1 _1822_ (.Y(_0477_),
    .B(net1199),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_38_));
 sg13g2_a21o_1 _1823_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_62_),
    .A1(net1175),
    .B1(net1206),
    .X(_0478_));
 sg13g2_a221oi_1 _1824_ (.B2(_0477_),
    .C1(_0478_),
    .B1(_0476_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_54_),
    .Y(_0479_),
    .A2(net1178));
 sg13g2_o21ai_1 _1825_ (.B1(net1201),
    .Y(_0480_),
    .A1(_0474_),
    .A2(_0479_));
 sg13g2_nand3_1 _1826_ (.B(_0480_),
    .C(_0455_),
    .A(_0469_),
    .Y(_0481_));
 sg13g2_a22oi_1 _1827_ (.Y(_0107_),
    .B1(_0458_),
    .B2(_0481_),
    .A2(net1183),
    .A1(_0457_));
 sg13g2_inv_1 _1828_ (.Y(_0482_),
    .A(net690));
 sg13g2_nand2b_1 _1829_ (.Y(_0483_),
    .B(net1225),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_109_));
 sg13g2_inv_1 _1830_ (.Y(_0484_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_101_));
 sg13g2_a21oi_1 _1831_ (.A1(net1199),
    .A2(_0484_),
    .Y(_0485_),
    .B1(net1223));
 sg13g2_a21o_1 _1832_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_117_),
    .A1(net1180),
    .B1(net1206),
    .X(_0486_));
 sg13g2_a221oi_1 _1833_ (.B2(_0485_),
    .C1(_0486_),
    .B1(_0483_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_125_),
    .Y(_0487_),
    .A2(net1175));
 sg13g2_nand2b_1 _1834_ (.Y(_0488_),
    .B(net1198),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_69_));
 sg13g2_inv_1 _1835_ (.Y(_0489_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_77_));
 sg13g2_a21oi_1 _1836_ (.A1(_0489_),
    .A2(net1228),
    .Y(_0490_),
    .B1(net1223));
 sg13g2_a21o_1 _1837_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_85_),
    .A1(net1179),
    .B1(net1221),
    .X(_0491_));
 sg13g2_a221oi_1 _1838_ (.B2(_0490_),
    .C1(_0491_),
    .B1(_0488_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_93_),
    .Y(_0492_),
    .A2(net1173));
 sg13g2_o21ai_1 _1839_ (.B1(net1219),
    .Y(_0493_),
    .A1(_0487_),
    .A2(_0492_));
 sg13g2_nand2b_1 _1840_ (.Y(_0494_),
    .B(net1225),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_45_));
 sg13g2_inv_1 _1841_ (.Y(_0495_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_37_));
 sg13g2_a21oi_1 _1842_ (.A1(net1199),
    .A2(_0495_),
    .Y(_0496_),
    .B1(net1223));
 sg13g2_a21o_1 _1843_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_53_),
    .A1(net1178),
    .B1(net1206),
    .X(_0497_));
 sg13g2_a221oi_1 _1844_ (.B2(_0496_),
    .C1(_0497_),
    .B1(_0494_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_61_),
    .Y(_0498_),
    .A2(net1175));
 sg13g2_nand2b_1 _1845_ (.Y(_0499_),
    .B(net1226),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_13_));
 sg13g2_inv_1 _1846_ (.Y(_0500_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_5_));
 sg13g2_a21oi_1 _1847_ (.A1(net1200),
    .A2(_0500_),
    .Y(_0501_),
    .B1(net1222));
 sg13g2_a21o_1 _1848_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_21_),
    .A1(net1178),
    .B1(net1220),
    .X(_0502_));
 sg13g2_a221oi_1 _1849_ (.B2(_0501_),
    .C1(_0502_),
    .B1(_0499_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_29_),
    .Y(_0503_),
    .A2(net1174));
 sg13g2_o21ai_1 _1850_ (.B1(net1201),
    .Y(_0504_),
    .A1(_0498_),
    .A2(_0503_));
 sg13g2_nand3_1 _1851_ (.B(_0504_),
    .C(_0455_),
    .A(_0493_),
    .Y(_0505_));
 sg13g2_inv_1 _1852_ (.Y(_0506_),
    .A(_0394_));
 sg13g2_o21ai_1 _1853_ (.B1(_0044_),
    .Y(_0507_),
    .A1(_1466_),
    .A2(_0506_));
 sg13g2_nor3_2 _1854_ (.A(net674),
    .B(net673),
    .C(_1382_),
    .Y(_0508_));
 sg13g2_a221oi_1 _1855_ (.B2(_0508_),
    .C1(net1153),
    .B1(_0507_),
    .A1(reg2hw_38_),
    .Y(_0509_),
    .A2(net1191));
 sg13g2_a22oi_1 _1856_ (.Y(_0108_),
    .B1(_0505_),
    .B2(_0509_),
    .A2(net1183),
    .A1(_0482_));
 sg13g2_inv_1 _1857_ (.Y(_0510_),
    .A(net689));
 sg13g2_inv_1 _1858_ (.Y(_0511_),
    .A(_0046_));
 sg13g2_a221oi_1 _1859_ (.B2(net1190),
    .C1(net1153),
    .B1(reg2hw_37_),
    .A1(_0511_),
    .Y(_0512_),
    .A2(_0508_));
 sg13g2_inv_1 _1860_ (.Y(_0513_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_68_));
 sg13g2_o21ai_1 _1861_ (.B1(net1204),
    .Y(_0514_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_76_),
    .A2(net1198));
 sg13g2_a21o_1 _1862_ (.A2(_0513_),
    .A1(net1198),
    .B1(_0514_),
    .X(_0515_));
 sg13g2_a22oi_1 _1863_ (.Y(_0516_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_92_),
    .B2(net1173),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_84_),
    .A1(net1179));
 sg13g2_a21oi_1 _1864_ (.A1(_0515_),
    .A2(_0516_),
    .Y(_0517_),
    .B1(net1221));
 sg13g2_inv_1 _1865_ (.Y(_0518_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_108_));
 sg13g2_o21ai_1 _1866_ (.B1(net1204),
    .Y(_0519_),
    .A1(net1225),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_100_));
 sg13g2_a21oi_1 _1867_ (.A1(net1225),
    .A2(_0518_),
    .Y(_0520_),
    .B1(_0519_));
 sg13g2_a221oi_1 _1868_ (.B2(net1174),
    .C1(_0520_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_124_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_116_),
    .Y(_0521_),
    .A2(net1180));
 sg13g2_o21ai_1 _1869_ (.B1(net1219),
    .Y(_0522_),
    .A1(net1206),
    .A2(_0521_));
 sg13g2_nor2_1 _1870_ (.A(_0517_),
    .B(_0522_),
    .Y(_0523_));
 sg13g2_nand2b_1 _1871_ (.Y(_0524_),
    .B(net1226),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_12_));
 sg13g2_inv_1 _1872_ (.Y(_0525_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_4_));
 sg13g2_a21oi_1 _1873_ (.A1(net1200),
    .A2(_0525_),
    .Y(_0526_),
    .B1(net1222));
 sg13g2_a21o_1 _1874_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_20_),
    .A1(net1178),
    .B1(net1220),
    .X(_0527_));
 sg13g2_a221oi_1 _1875_ (.B2(_0526_),
    .C1(_0527_),
    .B1(_0524_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_28_),
    .Y(_0528_),
    .A2(net1174));
 sg13g2_nand2b_1 _1876_ (.Y(_0529_),
    .B(net1199),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_36_));
 sg13g2_inv_1 _1877_ (.Y(_0530_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_44_));
 sg13g2_a21oi_1 _1878_ (.A1(_0530_),
    .A2(net1225),
    .Y(_0531_),
    .B1(net1223));
 sg13g2_a21o_1 _1879_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_52_),
    .A1(net1178),
    .B1(net1206),
    .X(_0532_));
 sg13g2_a221oi_1 _1880_ (.B2(_0531_),
    .C1(_0532_),
    .B1(_0529_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_60_),
    .Y(_0533_),
    .A2(net1175));
 sg13g2_o21ai_1 _1881_ (.B1(net1201),
    .Y(_0534_),
    .A1(_0528_),
    .A2(_0533_));
 sg13g2_nand3b_1 _1882_ (.B(_0455_),
    .C(_0534_),
    .Y(_0535_),
    .A_N(_0523_));
 sg13g2_a22oi_1 _1883_ (.Y(_0109_),
    .B1(_0512_),
    .B2(_0535_),
    .A2(net1183),
    .A1(_0510_));
 sg13g2_inv_1 _1884_ (.Y(_0536_),
    .A(net687));
 sg13g2_inv_1 _1885_ (.Y(_0537_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_3_));
 sg13g2_o21ai_1 _1886_ (.B1(net1202),
    .Y(_0538_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_11_),
    .A2(net1200));
 sg13g2_a21o_1 _1887_ (.A2(_0537_),
    .A1(_0426_),
    .B1(_0538_),
    .X(_0539_));
 sg13g2_a22oi_1 _1888_ (.Y(_0540_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_27_),
    .B2(net1176),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_19_),
    .A1(_0432_));
 sg13g2_a21oi_1 _1889_ (.A1(_0539_),
    .A2(_0540_),
    .Y(_0541_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_));
 sg13g2_inv_1 _1890_ (.Y(_0542_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_35_));
 sg13g2_o21ai_1 _1891_ (.B1(net1203),
    .Y(_0543_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_43_),
    .A2(net1197));
 sg13g2_a21o_1 _1892_ (.A2(_0542_),
    .A1(net1197),
    .B1(_0543_),
    .X(_0544_));
 sg13g2_a22oi_1 _1893_ (.Y(_0545_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_59_),
    .B2(net1177),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_51_),
    .A1(net1181));
 sg13g2_a21oi_1 _1894_ (.A1(_0544_),
    .A2(_0545_),
    .Y(_0546_),
    .B1(net1205));
 sg13g2_nor3_1 _1895_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_),
    .B(_0541_),
    .C(_0546_),
    .Y(_0547_));
 sg13g2_inv_1 _1896_ (.Y(_0548_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_67_));
 sg13g2_o21ai_1 _1897_ (.B1(net1203),
    .Y(_0549_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_75_),
    .A2(net1196));
 sg13g2_a21o_1 _1898_ (.A2(_0548_),
    .A1(net1196),
    .B1(_0549_),
    .X(_0550_));
 sg13g2_a22oi_1 _1899_ (.Y(_0551_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_91_),
    .B2(net1173),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_83_),
    .A1(net1179));
 sg13g2_a21oi_1 _1900_ (.A1(_0550_),
    .A2(_0551_),
    .Y(_0552_),
    .B1(net1221));
 sg13g2_inv_1 _1901_ (.Y(_0553_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_99_));
 sg13g2_o21ai_1 _1902_ (.B1(net1203),
    .Y(_0554_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_107_),
    .A2(net1195));
 sg13g2_a21o_1 _1903_ (.A2(_0553_),
    .A1(net1195),
    .B1(_0554_),
    .X(_0555_));
 sg13g2_a22oi_1 _1904_ (.Y(_0556_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_123_),
    .B2(net1177),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_115_),
    .A1(net1181));
 sg13g2_a21oi_1 _1905_ (.A1(_0555_),
    .A2(_0556_),
    .Y(_0557_),
    .B1(net1205));
 sg13g2_or3_1 _1906_ (.A(net1201),
    .B(_0552_),
    .C(_0557_),
    .X(_0558_));
 sg13g2_nand3b_1 _1907_ (.B(_0558_),
    .C(_0455_),
    .Y(_0559_),
    .A_N(_0547_));
 sg13g2_inv_1 _1908_ (.Y(_0560_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_));
 sg13g2_inv_2 _1909_ (.Y(_0561_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_0_));
 sg13g2_xnor2_1 _1910_ (.Y(_0562_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_));
 sg13g2_inv_1 _1911_ (.Y(_0563_),
    .A(_0562_));
 sg13g2_a21oi_1 _1912_ (.A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .A2(_0561_),
    .Y(_0564_),
    .B1(_0563_));
 sg13g2_a21oi_1 _1913_ (.A1(_0560_),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_),
    .Y(_0565_),
    .B1(_0564_));
 sg13g2_inv_2 _1914_ (.Y(_0566_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_));
 sg13g2_nor2_1 _1915_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_2_),
    .B(_0566_),
    .Y(_0567_));
 sg13g2_inv_1 _1916_ (.Y(_0568_),
    .A(_0567_));
 sg13g2_inv_1 _1917_ (.Y(_0569_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_2_));
 sg13g2_nor2_1 _1918_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_),
    .B(_0569_),
    .Y(_0570_));
 sg13g2_a21oi_1 _1919_ (.A1(_0565_),
    .A2(_0568_),
    .Y(_0571_),
    .B1(_0570_));
 sg13g2_xnor2_1 _1920_ (.Y(_0572_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_));
 sg13g2_inv_1 _1921_ (.Y(_0573_),
    .A(_0572_));
 sg13g2_xnor2_1 _1922_ (.Y(_0574_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_0_));
 sg13g2_inv_1 _1923_ (.Y(_0575_),
    .A(_0574_));
 sg13g2_nor2_1 _1924_ (.A(_0570_),
    .B(_0567_),
    .Y(_0576_));
 sg13g2_inv_1 _1925_ (.Y(_0577_),
    .A(_0576_));
 sg13g2_nor3_1 _1926_ (.A(_0563_),
    .B(_0575_),
    .C(_0577_),
    .Y(_0578_));
 sg13g2_inv_1 _1927_ (.Y(_0579_),
    .A(_0578_));
 sg13g2_nand3b_1 _1928_ (.B(_0573_),
    .C(_0579_),
    .Y(_0580_),
    .A_N(_0571_));
 sg13g2_a21oi_1 _1929_ (.A1(_0571_),
    .A2(_0572_),
    .Y(_0581_),
    .B1(_0397_));
 sg13g2_nor2_1 _1930_ (.A(_0573_),
    .B(_0579_),
    .Y(_0582_));
 sg13g2_inv_1 _1931_ (.Y(_0583_),
    .A(_0582_));
 sg13g2_inv_1 _1932_ (.Y(_0584_),
    .A(_0508_));
 sg13g2_a21oi_1 _1933_ (.A1(_0583_),
    .A2(_0045_),
    .Y(_0585_),
    .B1(_0584_));
 sg13g2_nor2_2 _1934_ (.A(u_uart_core_uart_tx_bit_cnt_q_0_),
    .B(u_uart_core_uart_tx_bit_cnt_q_1_),
    .Y(_0586_));
 sg13g2_inv_2 _1935_ (.Y(_0587_),
    .A(u_uart_core_uart_tx_bit_cnt_q_2_));
 sg13g2_inv_1 _1936_ (.Y(_0588_),
    .A(u_uart_core_uart_tx_bit_cnt_q_3_));
 sg13g2_nand3_1 _1937_ (.B(_0587_),
    .C(_0588_),
    .A(_0586_),
    .Y(_0589_));
 sg13g2_nand2_1 _1938_ (.Y(_0590_),
    .A(_0589_),
    .B(reg2hw_34_));
 sg13g2_a221oi_1 _1939_ (.B2(_0590_),
    .C1(_1463_),
    .B1(_0585_),
    .A1(_0580_),
    .Y(_0591_),
    .A2(_0581_));
 sg13g2_a22oi_1 _1940_ (.Y(_0110_),
    .B1(_0559_),
    .B2(_0591_),
    .A2(net1188),
    .A1(_0536_));
 sg13g2_inv_1 _1941_ (.Y(_0592_),
    .A(net686));
 sg13g2_inv_1 _1942_ (.Y(_0593_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_66_));
 sg13g2_o21ai_1 _1943_ (.B1(net1203),
    .Y(_0594_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_74_),
    .A2(net1196));
 sg13g2_a21o_1 _1944_ (.A2(_0593_),
    .A1(net1196),
    .B1(_0594_),
    .X(_0595_));
 sg13g2_a22oi_1 _1945_ (.Y(_0596_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_90_),
    .B2(net1173),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_82_),
    .A1(net1179));
 sg13g2_a21oi_1 _1946_ (.A1(_0595_),
    .A2(_0596_),
    .Y(_0597_),
    .B1(net1221));
 sg13g2_inv_1 _1947_ (.Y(_0598_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_98_));
 sg13g2_o21ai_1 _1948_ (.B1(net1203),
    .Y(_0599_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_106_),
    .A2(net1195));
 sg13g2_a21o_1 _1949_ (.A2(_0598_),
    .A1(net1195),
    .B1(_0599_),
    .X(_0600_));
 sg13g2_a22oi_1 _1950_ (.Y(_0601_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_122_),
    .B2(net1177),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_114_),
    .A1(net1181));
 sg13g2_a21oi_1 _1951_ (.A1(_0600_),
    .A2(_0601_),
    .Y(_0602_),
    .B1(net1205));
 sg13g2_nor3_1 _1952_ (.A(net1201),
    .B(_0597_),
    .C(_0602_),
    .Y(_0603_));
 sg13g2_inv_1 _1953_ (.Y(_0604_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_34_));
 sg13g2_o21ai_1 _1954_ (.B1(net1203),
    .Y(_0605_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_42_),
    .A2(net1197));
 sg13g2_a21o_1 _1955_ (.A2(_0604_),
    .A1(net1197),
    .B1(_0605_),
    .X(_0606_));
 sg13g2_a22oi_1 _1956_ (.Y(_0607_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_58_),
    .B2(net1177),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_50_),
    .A1(net1181));
 sg13g2_a21oi_1 _1957_ (.A1(_0606_),
    .A2(_0607_),
    .Y(_0608_),
    .B1(net1205));
 sg13g2_inv_1 _1958_ (.Y(_0609_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_2_));
 sg13g2_o21ai_1 _1959_ (.B1(net1202),
    .Y(_0610_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_10_),
    .A2(net1200));
 sg13g2_a21o_1 _1960_ (.A2(_0609_),
    .A1(_0426_),
    .B1(_0610_),
    .X(_0611_));
 sg13g2_a22oi_1 _1961_ (.Y(_0612_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_26_),
    .B2(net1176),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_18_),
    .A1(_0432_));
 sg13g2_a21oi_1 _1962_ (.A1(_0611_),
    .A2(_0612_),
    .Y(_0613_),
    .B1(net1220));
 sg13g2_or3_1 _1963_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_),
    .B(_0608_),
    .C(_0613_),
    .X(_0614_));
 sg13g2_nand3b_1 _1964_ (.B(_0614_),
    .C(_0455_),
    .Y(_0615_),
    .A_N(_0603_));
 sg13g2_o21ai_1 _1965_ (.B1(_1390_),
    .Y(_0616_),
    .A1(_0577_),
    .A2(_0565_));
 sg13g2_a221oi_1 _1966_ (.B2(_0578_),
    .C1(_0616_),
    .B1(_0573_),
    .A1(_0565_),
    .Y(_0617_),
    .A2(_0577_));
 sg13g2_inv_1 _1967_ (.Y(_0618_),
    .A(reg2hw_36_));
 sg13g2_o21ai_1 _1968_ (.B1(_1442_),
    .Y(_0619_),
    .A1(_0618_),
    .A2(_1387_));
 sg13g2_nor3_1 _1969_ (.A(_0617_),
    .B(_0619_),
    .C(_0585_),
    .Y(_0620_));
 sg13g2_a22oi_1 _1970_ (.Y(_0111_),
    .B1(_0615_),
    .B2(_0620_),
    .A2(net1188),
    .A1(_0592_));
 sg13g2_inv_1 _1971_ (.Y(_0621_),
    .A(net685));
 sg13g2_nand2b_1 _1972_ (.Y(_0622_),
    .B(net1228),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_41_));
 sg13g2_inv_1 _1973_ (.Y(_0623_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_33_));
 sg13g2_a21oi_1 _1974_ (.A1(net1197),
    .A2(_0623_),
    .Y(_0624_),
    .B1(net1224));
 sg13g2_a21o_1 _1975_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_49_),
    .A1(net1181),
    .B1(net1205),
    .X(_0625_));
 sg13g2_a221oi_1 _1976_ (.B2(_0624_),
    .C1(_0625_),
    .B1(_0622_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_57_),
    .Y(_0626_),
    .A2(net1176));
 sg13g2_inv_1 _1977_ (.Y(_0627_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_9_));
 sg13g2_o21ai_1 _1978_ (.B1(net1202),
    .Y(_0628_),
    .A1(net1226),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_1_));
 sg13g2_a21oi_1 _1979_ (.A1(net1227),
    .A2(_0627_),
    .Y(_0629_),
    .B1(_0628_));
 sg13g2_a221oi_1 _1980_ (.B2(net1176),
    .C1(_0629_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_25_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_17_),
    .Y(_0630_),
    .A2(_0432_));
 sg13g2_nor2b_1 _1981_ (.A(net1220),
    .B_N(_0630_),
    .Y(_0631_));
 sg13g2_o21ai_1 _1982_ (.B1(net1201),
    .Y(_0632_),
    .A1(_0626_),
    .A2(_0631_));
 sg13g2_nand2b_1 _1983_ (.Y(_0633_),
    .B(net1228),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_73_));
 sg13g2_inv_1 _1984_ (.Y(_0634_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_65_));
 sg13g2_a21oi_1 _1985_ (.A1(net1196),
    .A2(_0634_),
    .Y(_0635_),
    .B1(net1224));
 sg13g2_a21o_1 _1986_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_81_),
    .A1(net1179),
    .B1(net1221),
    .X(_0636_));
 sg13g2_a221oi_1 _1987_ (.B2(_0635_),
    .C1(_0636_),
    .B1(_0633_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_89_),
    .Y(_0637_),
    .A2(net1173));
 sg13g2_nand2b_1 _1988_ (.Y(_0638_),
    .B(net1228),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_105_));
 sg13g2_inv_1 _1989_ (.Y(_0639_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_97_));
 sg13g2_a21oi_1 _1990_ (.A1(net1195),
    .A2(_0639_),
    .Y(_0640_),
    .B1(net1224));
 sg13g2_a21o_1 _1991_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_113_),
    .A1(net1181),
    .B1(net1205),
    .X(_0641_));
 sg13g2_a221oi_1 _1992_ (.B2(_0640_),
    .C1(_0641_),
    .B1(_0638_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_121_),
    .Y(_0642_),
    .A2(net1177));
 sg13g2_o21ai_1 _1993_ (.B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_),
    .Y(_0643_),
    .A1(_0637_),
    .A2(_0642_));
 sg13g2_nand3_1 _1994_ (.B(_0643_),
    .C(_0455_),
    .A(_0632_),
    .Y(_0644_));
 sg13g2_nand3_1 _1995_ (.B(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .C(_0561_),
    .A(_0563_),
    .Y(_0645_));
 sg13g2_nor2_1 _1996_ (.A(_0397_),
    .B(_0564_),
    .Y(_0646_));
 sg13g2_o21ai_1 _1997_ (.B1(_0044_),
    .Y(_0647_),
    .A1(_1465_),
    .A2(_0506_));
 sg13g2_inv_1 _1998_ (.Y(_0648_),
    .A(reg2hw_35_));
 sg13g2_o21ai_1 _1999_ (.B1(_1442_),
    .Y(_0649_),
    .A1(_0648_),
    .A2(_1387_));
 sg13g2_a221oi_1 _2000_ (.B2(_0508_),
    .C1(_0649_),
    .B1(_0647_),
    .A1(_0645_),
    .Y(_0650_),
    .A2(_0646_));
 sg13g2_a22oi_1 _2001_ (.Y(_0112_),
    .B1(_0644_),
    .B2(_0650_),
    .A2(net1188),
    .A1(_0621_));
 sg13g2_inv_1 _2002_ (.Y(_0651_),
    .A(net684));
 sg13g2_o21ai_1 _2003_ (.B1(_0045_),
    .Y(_0652_),
    .A1(_0572_),
    .A2(_0579_));
 sg13g2_a22oi_1 _2004_ (.Y(_0653_),
    .B1(_1390_),
    .B2(_0575_),
    .A2(reg2hw_34_),
    .A1(net1191));
 sg13g2_nand2_1 _2005_ (.Y(_0654_),
    .A(_0653_),
    .B(_1442_));
 sg13g2_a21oi_1 _2006_ (.A1(_0652_),
    .A2(_0508_),
    .Y(_0655_),
    .B1(_0654_));
 sg13g2_inv_1 _2007_ (.Y(_0656_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_8_));
 sg13g2_o21ai_1 _2008_ (.B1(net1202),
    .Y(_0657_),
    .A1(net1227),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_0_));
 sg13g2_a21oi_1 _2009_ (.A1(net1227),
    .A2(_0656_),
    .Y(_0658_),
    .B1(_0657_));
 sg13g2_inv_1 _2010_ (.Y(_0659_),
    .A(net1176));
 sg13g2_nor2b_1 _2011_ (.A(_0659_),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_24_),
    .Y(_0660_));
 sg13g2_a21o_1 _2012_ (.A2(_0432_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_16_),
    .B1(_0660_),
    .X(_0661_));
 sg13g2_o21ai_1 _2013_ (.B1(_1467_),
    .Y(_0662_),
    .A1(_0658_),
    .A2(_0661_));
 sg13g2_inv_1 _2014_ (.Y(_0663_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_32_));
 sg13g2_o21ai_1 _2015_ (.B1(net1203),
    .Y(_0664_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_40_),
    .A2(net1195));
 sg13g2_a21o_1 _2016_ (.A2(_0663_),
    .A1(net1195),
    .B1(_0664_),
    .X(_0665_));
 sg13g2_a22oi_1 _2017_ (.Y(_0666_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_56_),
    .B2(net1177),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_48_),
    .A1(net1181));
 sg13g2_a21o_1 _2018_ (.A2(_0666_),
    .A1(_0665_),
    .B1(net1205),
    .X(_0667_));
 sg13g2_nand3_1 _2019_ (.B(net1201),
    .C(_0667_),
    .A(_0662_),
    .Y(_0668_));
 sg13g2_nand2b_1 _2020_ (.Y(_0669_),
    .B(net1228),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_72_));
 sg13g2_inv_1 _2021_ (.Y(_0670_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_64_));
 sg13g2_a21oi_1 _2022_ (.A1(net1196),
    .A2(_0670_),
    .Y(_0671_),
    .B1(net1224));
 sg13g2_a21o_1 _2023_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_80_),
    .A1(net1179),
    .B1(net1221),
    .X(_0672_));
 sg13g2_a221oi_1 _2024_ (.B2(_0671_),
    .C1(_0672_),
    .B1(_0669_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_88_),
    .Y(_0673_),
    .A2(net1173));
 sg13g2_nand2b_1 _2025_ (.Y(_0674_),
    .B(net1195),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_96_));
 sg13g2_inv_1 _2026_ (.Y(_0675_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_104_));
 sg13g2_a21oi_1 _2027_ (.A1(_0675_),
    .A2(net1228),
    .Y(_0676_),
    .B1(net1224));
 sg13g2_a21o_1 _2028_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_112_),
    .A1(net1181),
    .B1(net1205),
    .X(_0677_));
 sg13g2_a221oi_1 _2029_ (.B2(_0676_),
    .C1(_0677_),
    .B1(_0674_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_120_),
    .Y(_0678_),
    .A2(net1177));
 sg13g2_o21ai_1 _2030_ (.B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_),
    .Y(_0679_),
    .A1(_0673_),
    .A2(_0678_));
 sg13g2_nand3_1 _2031_ (.B(_0455_),
    .C(_0679_),
    .A(_0668_),
    .Y(_0680_));
 sg13g2_a22oi_1 _2032_ (.Y(_0113_),
    .B1(_0655_),
    .B2(_0680_),
    .A2(net1188),
    .A1(_0651_));
 sg13g2_inv_2 _2033_ (.Y(_0681_),
    .A(reg2hw_34_));
 sg13g2_nand2_1 _2034_ (.Y(_0682_),
    .A(_0589_),
    .B(u_uart_core_uart_tx_tick_baud_q));
 sg13g2_inv_1 _2035_ (.Y(_0683_),
    .A(_0682_));
 sg13g2_nor2_1 _2036_ (.A(_0681_),
    .B(_0683_),
    .Y(_0684_));
 sg13g2_inv_1 _2037_ (.Y(_0685_),
    .A(_0684_));
 sg13g2_nand3_1 _2038_ (.B(_0045_),
    .C(_0590_),
    .A(_0583_),
    .Y(_0686_));
 sg13g2_inv_1 _2040_ (.Y(_0688_),
    .A(_0686_));
 sg13g2_nor2_1 _2041_ (.A(_0685_),
    .B(_0688_),
    .Y(_0689_));
 sg13g2_inv_1 _2043_ (.Y(_0691_),
    .A(_0689_));
 sg13g2_nor2_1 _2044_ (.A(_0681_),
    .B(_0689_),
    .Y(_0692_));
 sg13g2_xnor2_1 _2045_ (.Y(_0693_),
    .A(_0587_),
    .B(_0586_));
 sg13g2_nand3_1 _2046_ (.B(_0686_),
    .C(_0693_),
    .A(_0692_),
    .Y(_0694_));
 sg13g2_o21ai_1 _2047_ (.B1(_0694_),
    .Y(_0114_),
    .A1(_0587_),
    .A2(_0691_));
 sg13g2_inv_1 _2048_ (.Y(_0695_),
    .A(u_uart_core_uart_tx_bit_cnt_q_1_));
 sg13g2_a21oi_1 _2049_ (.A1(u_uart_core_uart_tx_bit_cnt_q_0_),
    .A2(reg2hw_34_),
    .Y(_0696_),
    .B1(_0689_));
 sg13g2_nand2_1 _2050_ (.Y(_0697_),
    .A(_0692_),
    .B(_0586_));
 sg13g2_o21ai_1 _2051_ (.B1(_0697_),
    .Y(_0115_),
    .A1(_0695_),
    .A2(_0696_));
 sg13g2_inv_1 _2052_ (.Y(_0698_),
    .A(_0692_));
 sg13g2_inv_1 _2053_ (.Y(_0699_),
    .A(u_uart_core_uart_tx_bit_cnt_q_0_));
 sg13g2_nor2_1 _2054_ (.A(_0681_),
    .B(_0686_),
    .Y(_0700_));
 sg13g2_inv_2 _2055_ (.Y(_0701_),
    .A(_0700_));
 sg13g2_inv_1 _2056_ (.Y(_0702_),
    .A(reg2hw_39_));
 sg13g2_nor2_1 _2057_ (.A(_0702_),
    .B(_0701_),
    .Y(_0703_));
 sg13g2_a21oi_1 _2058_ (.A1(_0699_),
    .A2(_0701_),
    .Y(_0704_),
    .B1(_0703_));
 sg13g2_nand2_1 _2059_ (.Y(_0705_),
    .A(_0689_),
    .B(u_uart_core_uart_tx_bit_cnt_q_0_));
 sg13g2_o21ai_1 _2060_ (.B1(_0705_),
    .Y(_0116_),
    .A1(_0698_),
    .A2(_0704_));
 sg13g2_nand2_1 _2061_ (.Y(_0706_),
    .A(u_uart_core_uart_tx_baud_div_q_0_),
    .B(u_uart_core_nco_sum_q_16_));
 sg13g2_nor2b_1 _2062_ (.A(_0706_),
    .B_N(u_uart_core_uart_tx_baud_div_q_1_),
    .Y(_0707_));
 sg13g2_xor2_1 _2063_ (.B(_0707_),
    .A(u_uart_core_uart_tx_baud_div_q_2_),
    .X(_0117_));
 sg13g2_xnor2_1 _2064_ (.Y(_0118_),
    .A(u_uart_core_uart_tx_baud_div_q_1_),
    .B(_0706_));
 sg13g2_xor2_1 _2065_ (.B(u_uart_core_nco_sum_q_16_),
    .A(u_uart_core_uart_tx_baud_div_q_0_),
    .X(_0119_));
 sg13g2_inv_1 _2066_ (.Y(_0708_),
    .A(u_uart_core_uart_rx_sreg_q_9_));
 sg13g2_inv_1 _2067_ (.Y(_0709_),
    .A(u_uart_core_rx_tick_baud));
 sg13g2_nor2_1 _2068_ (.A(_0511_),
    .B(_0709_),
    .Y(_0710_));
 sg13g2_inv_1 _2069_ (.Y(_0711_),
    .A(reg2hw_37_));
 sg13g2_o21ai_1 _2070_ (.B1(_0042_),
    .Y(_0712_),
    .A1(_0039_),
    .A2(_0618_));
 sg13g2_nand2b_1 _2071_ (.Y(_0713_),
    .B(_0712_),
    .A_N(_0040_));
 sg13g2_inv_1 _2072_ (.Y(_0714_),
    .A(reg2hw_38_));
 sg13g2_a21o_1 _2073_ (.A2(_0039_),
    .A1(reg2hw_36_),
    .B1(_0042_),
    .X(_0715_));
 sg13g2_nand4_1 _2074_ (.B(_0714_),
    .C(_0711_),
    .A(_0713_),
    .Y(_0716_),
    .D(_0715_));
 sg13g2_o21ai_1 _2075_ (.B1(_0716_),
    .Y(_0717_),
    .A1(_1297_),
    .A2(_0711_));
 sg13g2_nand2_1 _2076_ (.Y(_0718_),
    .A(_0717_),
    .B(_0511_));
 sg13g2_inv_2 _2077_ (.Y(_0719_),
    .A(_0718_));
 sg13g2_nor2_1 _2078_ (.A(_0710_),
    .B(_0719_),
    .Y(_0720_));
 sg13g2_inv_1 _2079_ (.Y(_0721_),
    .A(u_uart_core_uart_rx_bit_cnt_q_1_));
 sg13g2_inv_2 _2080_ (.Y(_0722_),
    .A(u_uart_core_uart_rx_bit_cnt_q_3_));
 sg13g2_xor2_1 _2081_ (.B(reg2hw_39_),
    .A(u_uart_core_uart_rx_bit_cnt_q_0_),
    .X(_0723_));
 sg13g2_nor4_1 _2082_ (.A(u_uart_core_uart_rx_bit_cnt_q_2_),
    .B(_0721_),
    .C(_0722_),
    .D(_0723_),
    .Y(_0724_));
 sg13g2_nand2b_1 _2083_ (.Y(_0725_),
    .B(_0724_),
    .A_N(_0717_));
 sg13g2_nor2b_1 _2084_ (.A(_0720_),
    .B_N(_0725_),
    .Y(_0726_));
 sg13g2_inv_1 _2086_ (.Y(_0728_),
    .A(_0710_));
 sg13g2_nor2b_1 _2087_ (.A(_0728_),
    .B_N(_0725_),
    .Y(_0729_));
 sg13g2_nand2_1 _2089_ (.Y(_0731_),
    .A(_0729_),
    .B(u_uart_core_uart_rx_sreg_q_10_));
 sg13g2_o21ai_1 _2090_ (.B1(_0731_),
    .Y(_0120_),
    .A1(_0708_),
    .A2(_0726_));
 sg13g2_inv_1 _2091_ (.Y(_0732_),
    .A(u_uart_core_uart_rx_sreg_q_8_));
 sg13g2_nand2_1 _2092_ (.Y(_0733_),
    .A(net1144),
    .B(u_uart_core_uart_rx_sreg_q_9_));
 sg13g2_o21ai_1 _2093_ (.B1(_0733_),
    .Y(_0121_),
    .A1(_0732_),
    .A2(net1140));
 sg13g2_inv_1 _2094_ (.Y(_0734_),
    .A(u_uart_core_uart_rx_sreg_q_7_));
 sg13g2_nand2_1 _2095_ (.Y(_0735_),
    .A(net1144),
    .B(u_uart_core_uart_rx_sreg_q_8_));
 sg13g2_o21ai_1 _2096_ (.B1(_0735_),
    .Y(_0122_),
    .A1(_0734_),
    .A2(net1140));
 sg13g2_inv_1 _2097_ (.Y(_0736_),
    .A(u_uart_core_uart_rx_sreg_q_6_));
 sg13g2_nand2_1 _2098_ (.Y(_0737_),
    .A(net1144),
    .B(u_uart_core_uart_rx_sreg_q_7_));
 sg13g2_o21ai_1 _2099_ (.B1(_0737_),
    .Y(_0123_),
    .A1(_0736_),
    .A2(net1140));
 sg13g2_inv_1 _2100_ (.Y(_0738_),
    .A(u_uart_core_uart_rx_sreg_q_5_));
 sg13g2_nand2_1 _2101_ (.Y(_0739_),
    .A(net1144),
    .B(u_uart_core_uart_rx_sreg_q_6_));
 sg13g2_o21ai_1 _2102_ (.B1(_0739_),
    .Y(_0124_),
    .A1(_0738_),
    .A2(net1140));
 sg13g2_inv_1 _2103_ (.Y(_0740_),
    .A(u_uart_core_uart_rx_sreg_q_4_));
 sg13g2_nand2_1 _2104_ (.Y(_0741_),
    .A(net1144),
    .B(u_uart_core_uart_rx_sreg_q_5_));
 sg13g2_o21ai_1 _2105_ (.B1(_0741_),
    .Y(_0125_),
    .A1(_0740_),
    .A2(net1140));
 sg13g2_inv_1 _2106_ (.Y(_0742_),
    .A(u_uart_core_uart_rx_sreg_q_3_));
 sg13g2_nand2_1 _2107_ (.Y(_0743_),
    .A(net1144),
    .B(u_uart_core_uart_rx_sreg_q_4_));
 sg13g2_o21ai_1 _2108_ (.B1(_0743_),
    .Y(_0126_),
    .A1(_0742_),
    .A2(net1140));
 sg13g2_inv_1 _2109_ (.Y(_0744_),
    .A(u_uart_core_uart_rx_sreg_q_2_));
 sg13g2_nand2_1 _2110_ (.Y(_0745_),
    .A(net1144),
    .B(u_uart_core_uart_rx_sreg_q_3_));
 sg13g2_o21ai_1 _2111_ (.B1(_0745_),
    .Y(_0127_),
    .A1(_0744_),
    .A2(net1140));
 sg13g2_inv_1 _2112_ (.Y(_0746_),
    .A(u_uart_core_uart_rx_sreg_q_1_));
 sg13g2_nand2_1 _2113_ (.Y(_0747_),
    .A(net1144),
    .B(u_uart_core_uart_rx_sreg_q_2_));
 sg13g2_o21ai_1 _2114_ (.B1(_0747_),
    .Y(_0128_),
    .A1(_0746_),
    .A2(net1140));
 sg13g2_inv_1 _2115_ (.Y(_0748_),
    .A(u_uart_core_uart_rx_bit_cnt_q_2_));
 sg13g2_inv_1 _2116_ (.Y(_0749_),
    .A(_0720_));
 sg13g2_nor3_1 _2117_ (.A(u_uart_core_uart_rx_bit_cnt_q_2_),
    .B(u_uart_core_uart_rx_bit_cnt_q_0_),
    .C(u_uart_core_uart_rx_bit_cnt_q_1_),
    .Y(_0750_));
 sg13g2_inv_2 _2118_ (.Y(_0751_),
    .A(u_uart_core_uart_rx_bit_cnt_q_0_));
 sg13g2_a21oi_1 _2119_ (.A1(_0751_),
    .A2(_0721_),
    .Y(_0752_),
    .B1(_0748_));
 sg13g2_o21ai_1 _2120_ (.B1(_0729_),
    .Y(_0753_),
    .A1(_0750_),
    .A2(_0752_));
 sg13g2_o21ai_1 _2121_ (.B1(_0753_),
    .Y(_0129_),
    .A1(_0748_),
    .A2(_0749_));
 sg13g2_nor2_1 _2122_ (.A(u_uart_core_uart_rx_bit_cnt_q_1_),
    .B(_0751_),
    .Y(_0754_));
 sg13g2_inv_1 _2123_ (.Y(_0755_),
    .A(_0754_));
 sg13g2_nand2_1 _2124_ (.Y(_0756_),
    .A(_0751_),
    .B(u_uart_core_uart_rx_bit_cnt_q_1_));
 sg13g2_nand3_1 _2125_ (.B(_0755_),
    .C(_0756_),
    .A(_0729_),
    .Y(_0757_));
 sg13g2_a21oi_1 _2126_ (.A1(u_uart_core_uart_rx_bit_cnt_q_1_),
    .A2(_0728_),
    .Y(_0758_),
    .B1(_0719_));
 sg13g2_nand2_1 _2127_ (.Y(_0130_),
    .A(_0757_),
    .B(_0758_));
 sg13g2_a22oi_1 _2128_ (.Y(_0759_),
    .B1(_0751_),
    .B2(_0729_),
    .A2(_0719_),
    .A1(reg2hw_39_));
 sg13g2_o21ai_1 _2129_ (.B1(_0759_),
    .Y(_0131_),
    .A1(_0751_),
    .A2(_0749_));
 sg13g2_inv_1 _2130_ (.Y(_0760_),
    .A(u_uart_core_uart_rx_baud_div_q_2_));
 sg13g2_and2_1 _2131_ (.A(u_uart_core_uart_rx_baud_div_q_0_),
    .B(u_uart_core_nco_sum_q_16_),
    .X(_0761_));
 sg13g2_nand2_2 _2132_ (.Y(_0762_),
    .A(_0761_),
    .B(u_uart_core_uart_rx_baud_div_q_1_));
 sg13g2_nor2_1 _2133_ (.A(_0760_),
    .B(_0762_),
    .Y(_0763_));
 sg13g2_nor2_1 _2134_ (.A(_0763_),
    .B(_0719_),
    .Y(_0764_));
 sg13g2_inv_1 _2135_ (.Y(_0765_),
    .A(_0764_));
 sg13g2_a21oi_1 _2136_ (.A1(_0760_),
    .A2(_0762_),
    .Y(_0132_),
    .B1(_0765_));
 sg13g2_inv_1 _2137_ (.Y(_0766_),
    .A(_0762_));
 sg13g2_nor2_1 _2138_ (.A(u_uart_core_uart_rx_baud_div_q_1_),
    .B(_0761_),
    .Y(_0767_));
 sg13g2_nor3_1 _2139_ (.A(_0766_),
    .B(_0767_),
    .C(_0719_),
    .Y(_0133_));
 sg13g2_nor2_1 _2140_ (.A(u_uart_core_uart_rx_baud_div_q_0_),
    .B(u_uart_core_nco_sum_q_16_),
    .Y(_0768_));
 sg13g2_nor3_1 _2141_ (.A(_0761_),
    .B(_0768_),
    .C(_0719_),
    .Y(_0134_));
 sg13g2_inv_1 _2142_ (.Y(_0769_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_));
 sg13g2_nor2b_1 _2143_ (.A(_0652_),
    .B_N(reg2hw_4_),
    .Y(_0770_));
 sg13g2_nand2_2 _2144_ (.Y(_0771_),
    .A(_0770_),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_0_));
 sg13g2_nor2_1 _2145_ (.A(_0769_),
    .B(_0771_),
    .Y(_0772_));
 sg13g2_nor2_1 _2146_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_),
    .B(_0772_),
    .Y(_0773_));
 sg13g2_and2_1 _2147_ (.A(reg2hw_0_),
    .B(reg2hw_3_),
    .X(_0774_));
 sg13g2_nand2_1 _2149_ (.Y(_0776_),
    .A(_0772_),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_));
 sg13g2_inv_1 _2151_ (.Y(_0778_),
    .A(_0776_));
 sg13g2_nor3_1 _2152_ (.A(_0773_),
    .B(_0774_),
    .C(_0778_),
    .Y(_0135_));
 sg13g2_inv_1 _2153_ (.Y(_0779_),
    .A(_0771_));
 sg13g2_nor2_1 _2154_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_),
    .B(_0779_),
    .Y(_0780_));
 sg13g2_nor3_1 _2155_ (.A(_0772_),
    .B(_0774_),
    .C(_0780_),
    .Y(_0136_));
 sg13g2_nor2_1 _2156_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_0_),
    .B(_0770_),
    .Y(_0781_));
 sg13g2_nor3_1 _2157_ (.A(_0774_),
    .B(_0781_),
    .C(_0779_),
    .Y(_0137_));
 sg13g2_nand2_1 _2158_ (.Y(_0782_),
    .A(net1125),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_62_));
 sg13g2_o21ai_1 _2159_ (.B1(_0782_),
    .Y(_0138_),
    .A1(_1404_),
    .A2(net1125));
 sg13g2_nand2_1 _2160_ (.Y(_0783_),
    .A(net1126),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_61_));
 sg13g2_o21ai_1 _2161_ (.B1(_0783_),
    .Y(_0139_),
    .A1(_1406_),
    .A2(net1126));
 sg13g2_nand2_1 _2162_ (.Y(_0784_),
    .A(net1125),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_60_));
 sg13g2_o21ai_1 _2163_ (.B1(_0784_),
    .Y(_0140_),
    .A1(_1408_),
    .A2(net1125));
 sg13g2_nand2_1 _2164_ (.Y(_0785_),
    .A(_0776_),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_59_));
 sg13g2_o21ai_1 _2165_ (.B1(_0785_),
    .Y(_0141_),
    .A1(_1410_),
    .A2(net1126));
 sg13g2_nand2_1 _2166_ (.Y(_0786_),
    .A(net1125),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_58_));
 sg13g2_o21ai_1 _2167_ (.B1(_0786_),
    .Y(_0142_),
    .A1(_1412_),
    .A2(net1125));
 sg13g2_nand2_1 _2168_ (.Y(_0787_),
    .A(net1126),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_57_));
 sg13g2_o21ai_1 _2169_ (.B1(_0787_),
    .Y(_0143_),
    .A1(_1414_),
    .A2(net1126));
 sg13g2_nand2_1 _2170_ (.Y(_0788_),
    .A(net1126),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_56_));
 sg13g2_o21ai_1 _2171_ (.B1(_0788_),
    .Y(_0144_),
    .A1(_1416_),
    .A2(net1126));
 sg13g2_nand4_1 _2172_ (.B(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_),
    .C(_0561_),
    .A(_0770_),
    .Y(_0789_),
    .D(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_));
 sg13g2_nand2_1 _2174_ (.Y(_0791_),
    .A(net1139),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_54_));
 sg13g2_o21ai_1 _2175_ (.B1(_0791_),
    .Y(_0145_),
    .A1(_1404_),
    .A2(net1139));
 sg13g2_nand2_1 _2176_ (.Y(_0792_),
    .A(net1138),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_53_));
 sg13g2_o21ai_1 _2177_ (.B1(_0792_),
    .Y(_0146_),
    .A1(_1406_),
    .A2(net1138));
 sg13g2_nand2_1 _2178_ (.Y(_0793_),
    .A(net1139),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_52_));
 sg13g2_o21ai_1 _2179_ (.B1(_0793_),
    .Y(_0147_),
    .A1(_1408_),
    .A2(net1139));
 sg13g2_nand2_1 _2180_ (.Y(_0794_),
    .A(net1139),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_51_));
 sg13g2_o21ai_1 _2181_ (.B1(_0794_),
    .Y(_0148_),
    .A1(_1410_),
    .A2(net1139));
 sg13g2_nand2_1 _2182_ (.Y(_0795_),
    .A(net1138),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_50_));
 sg13g2_o21ai_1 _2183_ (.B1(_0795_),
    .Y(_0149_),
    .A1(_1412_),
    .A2(net1138));
 sg13g2_nand2_1 _2184_ (.Y(_0796_),
    .A(net1138),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_49_));
 sg13g2_o21ai_1 _2185_ (.B1(_0796_),
    .Y(_0150_),
    .A1(_1414_),
    .A2(net1138));
 sg13g2_nand2_1 _2186_ (.Y(_0797_),
    .A(net1138),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_48_));
 sg13g2_o21ai_1 _2187_ (.B1(_0797_),
    .Y(_0151_),
    .A1(_1416_),
    .A2(net1138));
 sg13g2_inv_1 _2188_ (.Y(_0798_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_46_));
 sg13g2_nand2_1 _2189_ (.Y(_0799_),
    .A(_0769_),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_));
 sg13g2_nor2_1 _2190_ (.A(_0799_),
    .B(_0771_),
    .Y(_0800_));
 sg13g2_nand2_1 _2192_ (.Y(_0802_),
    .A(net1135),
    .B(reg2hw_11_));
 sg13g2_o21ai_1 _2193_ (.B1(_0802_),
    .Y(_0152_),
    .A1(_0798_),
    .A2(net1135));
 sg13g2_inv_1 _2194_ (.Y(_0803_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_45_));
 sg13g2_nand2_1 _2195_ (.Y(_0804_),
    .A(net1134),
    .B(reg2hw_10_));
 sg13g2_o21ai_1 _2196_ (.B1(_0804_),
    .Y(_0153_),
    .A1(_0803_),
    .A2(net1134));
 sg13g2_inv_1 _2197_ (.Y(_0805_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_44_));
 sg13g2_nand2_1 _2198_ (.Y(_0806_),
    .A(net1135),
    .B(reg2hw_9_));
 sg13g2_o21ai_1 _2199_ (.B1(_0806_),
    .Y(_0154_),
    .A1(_0805_),
    .A2(net1135));
 sg13g2_inv_1 _2200_ (.Y(_0807_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_43_));
 sg13g2_nand2_1 _2201_ (.Y(_0808_),
    .A(net1134),
    .B(reg2hw_8_));
 sg13g2_o21ai_1 _2202_ (.B1(_0808_),
    .Y(_0155_),
    .A1(_0807_),
    .A2(net1134));
 sg13g2_inv_1 _2203_ (.Y(_0809_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_42_));
 sg13g2_nand2_1 _2204_ (.Y(_0810_),
    .A(net1134),
    .B(reg2hw_7_));
 sg13g2_o21ai_1 _2205_ (.B1(_0810_),
    .Y(_0156_),
    .A1(_0809_),
    .A2(net1134));
 sg13g2_inv_1 _2206_ (.Y(_0811_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_41_));
 sg13g2_nand2_1 _2207_ (.Y(_0812_),
    .A(net1135),
    .B(reg2hw_6_));
 sg13g2_o21ai_1 _2208_ (.B1(_0812_),
    .Y(_0157_),
    .A1(_0811_),
    .A2(net1135));
 sg13g2_inv_1 _2209_ (.Y(_0813_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_40_));
 sg13g2_nand2_1 _2210_ (.Y(_0814_),
    .A(_0800_),
    .B(reg2hw_5_));
 sg13g2_o21ai_1 _2211_ (.B1(_0814_),
    .Y(_0158_),
    .A1(_0813_),
    .A2(_0800_));
 sg13g2_nand2_1 _2212_ (.Y(_0815_),
    .A(_0770_),
    .B(_0561_));
 sg13g2_nor2_1 _2213_ (.A(_0799_),
    .B(_0815_),
    .Y(_0816_));
 sg13g2_nor2_1 _2215_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_38_),
    .B(net1132),
    .Y(_0818_));
 sg13g2_a21oi_1 _2216_ (.A1(_1404_),
    .A2(net1132),
    .Y(_0159_),
    .B1(_0818_));
 sg13g2_nor2_1 _2217_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_37_),
    .B(net1133),
    .Y(_0819_));
 sg13g2_a21oi_1 _2218_ (.A1(_1406_),
    .A2(_0816_),
    .Y(_0160_),
    .B1(_0819_));
 sg13g2_nor2_1 _2219_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_36_),
    .B(net1133),
    .Y(_0820_));
 sg13g2_a21oi_1 _2220_ (.A1(_1408_),
    .A2(net1133),
    .Y(_0161_),
    .B1(_0820_));
 sg13g2_nor2_1 _2221_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_35_),
    .B(net1133),
    .Y(_0821_));
 sg13g2_a21oi_1 _2222_ (.A1(_1410_),
    .A2(net1133),
    .Y(_0162_),
    .B1(_0821_));
 sg13g2_nor2_1 _2223_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_34_),
    .B(net1133),
    .Y(_0822_));
 sg13g2_a21oi_1 _2224_ (.A1(_1412_),
    .A2(net1133),
    .Y(_0163_),
    .B1(_0822_));
 sg13g2_nor2_1 _2225_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_33_),
    .B(net1132),
    .Y(_0823_));
 sg13g2_a21oi_1 _2226_ (.A1(_1414_),
    .A2(net1132),
    .Y(_0164_),
    .B1(_0823_));
 sg13g2_nor2_1 _2227_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_32_),
    .B(net1132),
    .Y(_0824_));
 sg13g2_a21oi_1 _2228_ (.A1(_1416_),
    .A2(net1132),
    .Y(_0165_),
    .B1(_0824_));
 sg13g2_nand2_1 _2229_ (.Y(_0825_),
    .A(_0772_),
    .B(_0566_));
 sg13g2_nand2_1 _2231_ (.Y(_0827_),
    .A(net1124),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_30_));
 sg13g2_o21ai_1 _2232_ (.B1(_0827_),
    .Y(_0166_),
    .A1(_1404_),
    .A2(net1124));
 sg13g2_nand2_1 _2233_ (.Y(_0828_),
    .A(net1123),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_29_));
 sg13g2_o21ai_1 _2234_ (.B1(_0828_),
    .Y(_0167_),
    .A1(_1406_),
    .A2(net1123));
 sg13g2_nand2_1 _2235_ (.Y(_0829_),
    .A(net1124),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_28_));
 sg13g2_o21ai_1 _2236_ (.B1(_0829_),
    .Y(_0168_),
    .A1(_1408_),
    .A2(net1124));
 sg13g2_nand2_1 _2237_ (.Y(_0830_),
    .A(net1124),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_27_));
 sg13g2_o21ai_1 _2238_ (.B1(_0830_),
    .Y(_0169_),
    .A1(_1410_),
    .A2(net1124));
 sg13g2_nand2_1 _2239_ (.Y(_0831_),
    .A(net1124),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_26_));
 sg13g2_o21ai_1 _2240_ (.B1(_0831_),
    .Y(_0170_),
    .A1(_1412_),
    .A2(net1124));
 sg13g2_nand2_1 _2241_ (.Y(_0832_),
    .A(_0825_),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_25_));
 sg13g2_o21ai_1 _2242_ (.B1(_0832_),
    .Y(_0171_),
    .A1(_1414_),
    .A2(_0825_));
 sg13g2_nand2_1 _2243_ (.Y(_0833_),
    .A(_0825_),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_24_));
 sg13g2_o21ai_1 _2244_ (.B1(_0833_),
    .Y(_0172_),
    .A1(_1416_),
    .A2(net1123));
 sg13g2_nand4_1 _2245_ (.B(_0566_),
    .C(_0561_),
    .A(_0770_),
    .Y(_0834_),
    .D(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_));
 sg13g2_nand2_1 _2247_ (.Y(_0836_),
    .A(net1136),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_22_));
 sg13g2_o21ai_1 _2248_ (.B1(_0836_),
    .Y(_0173_),
    .A1(_1404_),
    .A2(net1136));
 sg13g2_nand2_1 _2249_ (.Y(_0837_),
    .A(net1137),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_21_));
 sg13g2_o21ai_1 _2250_ (.B1(_0837_),
    .Y(_0174_),
    .A1(_1406_),
    .A2(net1137));
 sg13g2_nand2_1 _2251_ (.Y(_0838_),
    .A(net1136),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_20_));
 sg13g2_o21ai_1 _2252_ (.B1(_0838_),
    .Y(_0175_),
    .A1(_1408_),
    .A2(net1136));
 sg13g2_nand2_1 _2253_ (.Y(_0839_),
    .A(net1136),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_19_));
 sg13g2_o21ai_1 _2254_ (.B1(_0839_),
    .Y(_0176_),
    .A1(_1410_),
    .A2(net1136));
 sg13g2_nand2_1 _2255_ (.Y(_0840_),
    .A(net1136),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_18_));
 sg13g2_o21ai_1 _2256_ (.B1(_0840_),
    .Y(_0177_),
    .A1(_1412_),
    .A2(net1136));
 sg13g2_nand2_1 _2257_ (.Y(_0841_),
    .A(net1137),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_17_));
 sg13g2_o21ai_1 _2258_ (.B1(_0841_),
    .Y(_0178_),
    .A1(_1414_),
    .A2(net1137));
 sg13g2_nand2_1 _2259_ (.Y(_0842_),
    .A(net1137),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_16_));
 sg13g2_o21ai_1 _2260_ (.B1(_0842_),
    .Y(_0179_),
    .A1(_1416_),
    .A2(net1137));
 sg13g2_inv_1 _2261_ (.Y(_0843_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_14_));
 sg13g2_nand2_1 _2262_ (.Y(_0844_),
    .A(_0566_),
    .B(_0769_));
 sg13g2_nor2_1 _2263_ (.A(_0844_),
    .B(_0771_),
    .Y(_0845_));
 sg13g2_nand2_1 _2265_ (.Y(_0847_),
    .A(net1131),
    .B(reg2hw_11_));
 sg13g2_o21ai_1 _2266_ (.B1(_0847_),
    .Y(_0180_),
    .A1(_0843_),
    .A2(net1131));
 sg13g2_inv_1 _2267_ (.Y(_0848_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_13_));
 sg13g2_nand2_1 _2268_ (.Y(_0849_),
    .A(net1130),
    .B(reg2hw_10_));
 sg13g2_o21ai_1 _2269_ (.B1(_0849_),
    .Y(_0181_),
    .A1(_0848_),
    .A2(net1130));
 sg13g2_inv_1 _2270_ (.Y(_0850_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_12_));
 sg13g2_nand2_1 _2271_ (.Y(_0851_),
    .A(net1130),
    .B(reg2hw_9_));
 sg13g2_o21ai_1 _2272_ (.B1(_0851_),
    .Y(_0182_),
    .A1(_0850_),
    .A2(net1131));
 sg13g2_inv_1 _2273_ (.Y(_0852_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_11_));
 sg13g2_nand2_1 _2274_ (.Y(_0853_),
    .A(net1130),
    .B(reg2hw_8_));
 sg13g2_o21ai_1 _2275_ (.B1(_0853_),
    .Y(_0183_),
    .A1(_0852_),
    .A2(net1131));
 sg13g2_inv_1 _2276_ (.Y(_0854_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_10_));
 sg13g2_nand2_1 _2277_ (.Y(_0855_),
    .A(net1130),
    .B(reg2hw_7_));
 sg13g2_o21ai_1 _2278_ (.B1(_0855_),
    .Y(_0184_),
    .A1(_0854_),
    .A2(net1130));
 sg13g2_inv_1 _2279_ (.Y(_0856_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_9_));
 sg13g2_nand2_1 _2280_ (.Y(_0857_),
    .A(net1131),
    .B(reg2hw_6_));
 sg13g2_o21ai_1 _2281_ (.B1(_0857_),
    .Y(_0185_),
    .A1(_0856_),
    .A2(net1131));
 sg13g2_inv_1 _2282_ (.Y(_0858_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_8_));
 sg13g2_nand2_1 _2283_ (.Y(_0859_),
    .A(_0845_),
    .B(reg2hw_5_));
 sg13g2_o21ai_1 _2284_ (.B1(_0859_),
    .Y(_0186_),
    .A1(_0858_),
    .A2(_0845_));
 sg13g2_nor2_1 _2285_ (.A(_0844_),
    .B(_0815_),
    .Y(_0860_));
 sg13g2_nor2_1 _2287_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_6_),
    .B(net1129),
    .Y(_0862_));
 sg13g2_a21oi_1 _2288_ (.A1(_1404_),
    .A2(net1129),
    .Y(_0187_),
    .B1(_0862_));
 sg13g2_nor2_1 _2289_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_5_),
    .B(net1128),
    .Y(_0863_));
 sg13g2_a21oi_1 _2290_ (.A1(_1406_),
    .A2(net1128),
    .Y(_0188_),
    .B1(_0863_));
 sg13g2_nor2_1 _2291_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_4_),
    .B(net1129),
    .Y(_0864_));
 sg13g2_a21oi_1 _2292_ (.A1(_1408_),
    .A2(net1129),
    .Y(_0189_),
    .B1(_0864_));
 sg13g2_nor2_1 _2293_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_3_),
    .B(net1129),
    .Y(_0865_));
 sg13g2_a21oi_1 _2294_ (.A1(_1410_),
    .A2(net1129),
    .Y(_0190_),
    .B1(_0865_));
 sg13g2_nor2_1 _2295_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_2_),
    .B(net1128),
    .Y(_0866_));
 sg13g2_a21oi_1 _2296_ (.A1(_1412_),
    .A2(net1128),
    .Y(_0191_),
    .B1(_0866_));
 sg13g2_nor2_1 _2297_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_1_),
    .B(net1129),
    .Y(_0867_));
 sg13g2_a21oi_1 _2298_ (.A1(_1414_),
    .A2(net1129),
    .Y(_0192_),
    .B1(_0867_));
 sg13g2_nor2_1 _2299_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_0_),
    .B(_0860_),
    .Y(_0868_));
 sg13g2_a21oi_1 _2300_ (.A1(_1416_),
    .A2(_0860_),
    .Y(_0193_),
    .B1(_0868_));
 sg13g2_inv_4 _2301_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .Y(_0869_));
 sg13g2_nor2_1 _2302_ (.A(_0869_),
    .B(_0701_),
    .Y(_0870_));
 sg13g2_nand2_1 _2303_ (.Y(_0871_),
    .A(_0870_),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_));
 sg13g2_nor2_1 _2304_ (.A(_0569_),
    .B(_0871_),
    .Y(_0872_));
 sg13g2_inv_1 _2305_ (.Y(_0873_),
    .A(_0871_));
 sg13g2_nor2_1 _2306_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_2_),
    .B(_0873_),
    .Y(_0874_));
 sg13g2_nor3_1 _2307_ (.A(_0774_),
    .B(_0872_),
    .C(_0874_),
    .Y(_0194_));
 sg13g2_nor2_1 _2308_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_),
    .B(_0870_),
    .Y(_0875_));
 sg13g2_nor3_1 _2309_ (.A(_0774_),
    .B(_0875_),
    .C(_0873_),
    .Y(_0195_));
 sg13g2_nor2_1 _2310_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .B(_0700_),
    .Y(_0876_));
 sg13g2_nor3_1 _2311_ (.A(_0774_),
    .B(_0876_),
    .C(_0870_),
    .Y(_0196_));
 sg13g2_inv_1 _2312_ (.Y(_0877_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_));
 sg13g2_xnor2_1 _2313_ (.Y(_0878_),
    .A(u_uart_core_uart_rx_sreg_q_2_),
    .B(u_uart_core_uart_rx_sreg_q_1_));
 sg13g2_xnor2_1 _2314_ (.Y(_0879_),
    .A(reg2hw_40_),
    .B(u_uart_core_uart_rx_sreg_q_3_));
 sg13g2_xnor2_1 _2315_ (.Y(_0880_),
    .A(_0878_),
    .B(_0879_));
 sg13g2_xnor2_1 _2316_ (.Y(_0881_),
    .A(u_uart_core_uart_rx_sreg_q_8_),
    .B(u_uart_core_uart_rx_sreg_q_9_));
 sg13g2_xnor2_1 _2317_ (.Y(_0882_),
    .A(u_uart_core_uart_rx_sreg_q_5_),
    .B(u_uart_core_uart_rx_sreg_q_4_));
 sg13g2_xnor2_1 _2318_ (.Y(_0883_),
    .A(u_uart_core_uart_rx_sreg_q_7_),
    .B(u_uart_core_uart_rx_sreg_q_6_));
 sg13g2_xnor2_1 _2319_ (.Y(_0884_),
    .A(_0882_),
    .B(_0883_));
 sg13g2_xnor2_1 _2320_ (.Y(_0885_),
    .A(_0881_),
    .B(_0884_));
 sg13g2_a21oi_1 _2321_ (.A1(_0885_),
    .A2(_0880_),
    .Y(_0886_),
    .B1(_0702_));
 sg13g2_o21ai_1 _2322_ (.B1(_0886_),
    .Y(_0887_),
    .A1(_0880_),
    .A2(_0885_));
 sg13g2_inv_1 _2323_ (.Y(_0888_),
    .A(u_uart_core_uart_rx_sreg_q_10_));
 sg13g2_inv_1 _2324_ (.Y(_0889_),
    .A(u_uart_core_rx_valid));
 sg13g2_nor3_1 _2325_ (.A(_0888_),
    .B(_0889_),
    .C(_0647_),
    .Y(_0890_));
 sg13g2_nand2_1 _2326_ (.Y(_0891_),
    .A(_0887_),
    .B(_0890_));
 sg13g2_nor2_1 _2327_ (.A(_1472_),
    .B(_0891_),
    .Y(_0892_));
 sg13g2_inv_1 _2328_ (.Y(_0893_),
    .A(_0892_));
 sg13g2_nor2_2 _2329_ (.A(_0877_),
    .B(_0893_),
    .Y(_0894_));
 sg13g2_nand2_1 _2330_ (.Y(_0895_),
    .A(_0894_),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_));
 sg13g2_nor2_1 _2331_ (.A(_0389_),
    .B(_0895_),
    .Y(_0896_));
 sg13g2_nand2_2 _2333_ (.Y(_0898_),
    .A(reg2hw_1_),
    .B(reg2hw_0_));
 sg13g2_inv_2 _2334_ (.Y(_0899_),
    .A(_0898_));
 sg13g2_inv_1 _2335_ (.Y(_0900_),
    .A(_0895_));
 sg13g2_nor2_1 _2336_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_),
    .B(_0900_),
    .Y(_0901_));
 sg13g2_nor3_1 _2337_ (.A(_0896_),
    .B(_0899_),
    .C(_0901_),
    .Y(_0197_));
 sg13g2_o21ai_1 _2338_ (.B1(_0898_),
    .Y(_0902_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_),
    .A2(_0894_));
 sg13g2_nor2_1 _2339_ (.A(_0902_),
    .B(_0900_),
    .Y(_0198_));
 sg13g2_nor2_1 _2340_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_),
    .B(_0892_),
    .Y(_0903_));
 sg13g2_nor3_1 _2341_ (.A(_0899_),
    .B(_0903_),
    .C(_0894_),
    .Y(_0199_));
 sg13g2_inv_1 _2342_ (.Y(_0904_),
    .A(_0891_));
 sg13g2_nor2_1 _2343_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_0_),
    .B(_0904_),
    .Y(_0905_));
 sg13g2_nor3_1 _2344_ (.A(_0892_),
    .B(_0899_),
    .C(_0905_),
    .Y(_0200_));
 sg13g2_nor2_1 _2345_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_),
    .B(_0893_),
    .Y(_0906_));
 sg13g2_nor2_1 _2346_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_),
    .B(_0389_),
    .Y(_0907_));
 sg13g2_nand2_1 _2347_ (.Y(_0908_),
    .A(_0906_),
    .B(_0907_));
 sg13g2_nand2_1 _2349_ (.Y(_0910_),
    .A(_0734_),
    .B(net1251));
 sg13g2_o21ai_1 _2350_ (.B1(_0910_),
    .Y(_0911_),
    .A1(net1251),
    .A2(u_uart_core_uart_rx_sreg_q_8_));
 sg13g2_nand2_1 _2352_ (.Y(_0913_),
    .A(_0908_),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_78_));
 sg13g2_o21ai_1 _2353_ (.B1(_0913_),
    .Y(_0201_),
    .A1(net1106),
    .A2(net1171));
 sg13g2_nand2_1 _2354_ (.Y(_0914_),
    .A(_0736_),
    .B(net1251));
 sg13g2_o21ai_1 _2355_ (.B1(_0914_),
    .Y(_0915_),
    .A1(net1251),
    .A2(u_uart_core_uart_rx_sreg_q_7_));
 sg13g2_nand2_1 _2357_ (.Y(_0917_),
    .A(net1106),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_77_));
 sg13g2_o21ai_1 _2358_ (.B1(_0917_),
    .Y(_0202_),
    .A1(net1106),
    .A2(net1169));
 sg13g2_nand2_1 _2359_ (.Y(_0918_),
    .A(_0738_),
    .B(net1251));
 sg13g2_o21ai_1 _2360_ (.B1(_0918_),
    .Y(_0919_),
    .A1(net1251),
    .A2(u_uart_core_uart_rx_sreg_q_6_));
 sg13g2_nand2_1 _2362_ (.Y(_0921_),
    .A(net1106),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_76_));
 sg13g2_o21ai_1 _2363_ (.B1(_0921_),
    .Y(_0203_),
    .A1(net1106),
    .A2(net1167));
 sg13g2_nand2_1 _2364_ (.Y(_0922_),
    .A(_0740_),
    .B(net1252));
 sg13g2_o21ai_1 _2365_ (.B1(_0922_),
    .Y(_0923_),
    .A1(net1252),
    .A2(u_uart_core_uart_rx_sreg_q_5_));
 sg13g2_nand2_1 _2367_ (.Y(_0925_),
    .A(net1105),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_75_));
 sg13g2_o21ai_1 _2368_ (.B1(_0925_),
    .Y(_0204_),
    .A1(net1105),
    .A2(net1165));
 sg13g2_nand2_1 _2369_ (.Y(_0926_),
    .A(_0742_),
    .B(net1252));
 sg13g2_o21ai_1 _2370_ (.B1(_0926_),
    .Y(_0927_),
    .A1(net1252),
    .A2(u_uart_core_uart_rx_sreg_q_4_));
 sg13g2_nand2_1 _2372_ (.Y(_0929_),
    .A(net1105),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_74_));
 sg13g2_o21ai_1 _2373_ (.B1(_0929_),
    .Y(_0205_),
    .A1(net1105),
    .A2(net1163));
 sg13g2_nand2_1 _2374_ (.Y(_0930_),
    .A(_0744_),
    .B(net1252));
 sg13g2_o21ai_1 _2375_ (.B1(_0930_),
    .Y(_0931_),
    .A1(net1252),
    .A2(u_uart_core_uart_rx_sreg_q_3_));
 sg13g2_nand2_1 _2377_ (.Y(_0933_),
    .A(net1105),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_73_));
 sg13g2_o21ai_1 _2378_ (.B1(_0933_),
    .Y(_0206_),
    .A1(net1105),
    .A2(net1161));
 sg13g2_nand2_1 _2379_ (.Y(_0934_),
    .A(_0746_),
    .B(net1252));
 sg13g2_o21ai_1 _2380_ (.B1(_0934_),
    .Y(_0935_),
    .A1(net1252),
    .A2(u_uart_core_uart_rx_sreg_q_2_));
 sg13g2_nand2_1 _2382_ (.Y(_0937_),
    .A(net1105),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_72_));
 sg13g2_o21ai_1 _2383_ (.B1(_0937_),
    .Y(_0207_),
    .A1(net1105),
    .A2(net1159));
 sg13g2_nand3_1 _2384_ (.B(_0877_),
    .C(_1472_),
    .A(_0904_),
    .Y(_0938_));
 sg13g2_nand2b_1 _2385_ (.Y(_0939_),
    .B(_0907_),
    .A_N(_0938_));
 sg13g2_nand2_1 _2387_ (.Y(_0941_),
    .A(_0939_),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_70_));
 sg13g2_o21ai_1 _2388_ (.B1(_0941_),
    .Y(_0208_),
    .A1(net1171),
    .A2(_0939_));
 sg13g2_nand2_1 _2389_ (.Y(_0942_),
    .A(_0939_),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_69_));
 sg13g2_o21ai_1 _2390_ (.B1(_0942_),
    .Y(_0209_),
    .A1(net1169),
    .A2(_0939_));
 sg13g2_nand2_1 _2391_ (.Y(_0943_),
    .A(net1122),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_68_));
 sg13g2_o21ai_1 _2392_ (.B1(_0943_),
    .Y(_0210_),
    .A1(net1167),
    .A2(net1122));
 sg13g2_nand2_1 _2393_ (.Y(_0944_),
    .A(net1121),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_67_));
 sg13g2_o21ai_1 _2394_ (.B1(_0944_),
    .Y(_0211_),
    .A1(net1165),
    .A2(net1121));
 sg13g2_nand2_1 _2395_ (.Y(_0945_),
    .A(net1121),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_66_));
 sg13g2_o21ai_1 _2396_ (.B1(_0945_),
    .Y(_0212_),
    .A1(net1163),
    .A2(net1121));
 sg13g2_nand2_1 _2397_ (.Y(_0946_),
    .A(net1121),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_65_));
 sg13g2_o21ai_1 _2398_ (.B1(_0946_),
    .Y(_0213_),
    .A1(net1161),
    .A2(net1121));
 sg13g2_nand2_1 _2399_ (.Y(_0947_),
    .A(net1121),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_64_));
 sg13g2_o21ai_1 _2400_ (.B1(_0947_),
    .Y(_0214_),
    .A1(net1159),
    .A2(net1121));
 sg13g2_inv_1 _2401_ (.Y(_0948_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_));
 sg13g2_nor2_1 _2402_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_),
    .B(_0948_),
    .Y(_0949_));
 sg13g2_nand2_1 _2403_ (.Y(_0950_),
    .A(_0894_),
    .B(_0949_));
 sg13g2_nand2_1 _2405_ (.Y(_0952_),
    .A(net1103),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_62_));
 sg13g2_o21ai_1 _2406_ (.B1(_0952_),
    .Y(_0215_),
    .A1(net1172),
    .A2(net1103));
 sg13g2_nand2_1 _2407_ (.Y(_0953_),
    .A(net1103),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_61_));
 sg13g2_o21ai_1 _2408_ (.B1(_0953_),
    .Y(_0216_),
    .A1(net1170),
    .A2(net1103));
 sg13g2_nand2_1 _2409_ (.Y(_0954_),
    .A(net1103),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_60_));
 sg13g2_o21ai_1 _2410_ (.B1(_0954_),
    .Y(_0217_),
    .A1(net1168),
    .A2(net1103));
 sg13g2_nand2_1 _2411_ (.Y(_0955_),
    .A(net1104),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_59_));
 sg13g2_o21ai_1 _2412_ (.B1(_0955_),
    .Y(_0218_),
    .A1(net1166),
    .A2(net1104));
 sg13g2_nand2_1 _2413_ (.Y(_0956_),
    .A(net1104),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_58_));
 sg13g2_o21ai_1 _2414_ (.B1(_0956_),
    .Y(_0219_),
    .A1(net1164),
    .A2(net1104));
 sg13g2_nand2_1 _2415_ (.Y(_0957_),
    .A(net1104),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_57_));
 sg13g2_o21ai_1 _2416_ (.B1(_0957_),
    .Y(_0220_),
    .A1(net1162),
    .A2(net1104));
 sg13g2_nand2_1 _2417_ (.Y(_0958_),
    .A(net1104),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_56_));
 sg13g2_o21ai_1 _2418_ (.B1(_0958_),
    .Y(_0221_),
    .A1(net1160),
    .A2(net1104));
 sg13g2_nand3_1 _2419_ (.B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_),
    .C(_1472_),
    .A(_0904_),
    .Y(_0959_));
 sg13g2_nand2b_1 _2420_ (.Y(_0960_),
    .B(_0949_),
    .A_N(_0959_));
 sg13g2_nand2_1 _2422_ (.Y(_0962_),
    .A(net1119),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_54_));
 sg13g2_o21ai_1 _2423_ (.B1(_0962_),
    .Y(_0222_),
    .A1(net1172),
    .A2(net1119));
 sg13g2_nand2_1 _2424_ (.Y(_0963_),
    .A(net1119),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_53_));
 sg13g2_o21ai_1 _2425_ (.B1(_0963_),
    .Y(_0223_),
    .A1(net1170),
    .A2(net1119));
 sg13g2_nand2_1 _2426_ (.Y(_0964_),
    .A(net1119),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_52_));
 sg13g2_o21ai_1 _2427_ (.B1(_0964_),
    .Y(_0224_),
    .A1(net1168),
    .A2(net1119));
 sg13g2_nand2_1 _2428_ (.Y(_0965_),
    .A(net1120),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_51_));
 sg13g2_o21ai_1 _2429_ (.B1(_0965_),
    .Y(_0225_),
    .A1(net1166),
    .A2(net1120));
 sg13g2_nand2_1 _2430_ (.Y(_0966_),
    .A(net1120),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_50_));
 sg13g2_o21ai_1 _2431_ (.B1(_0966_),
    .Y(_0226_),
    .A1(net1164),
    .A2(net1120));
 sg13g2_nand2_1 _2432_ (.Y(_0967_),
    .A(net1120),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_49_));
 sg13g2_o21ai_1 _2433_ (.B1(_0967_),
    .Y(_0227_),
    .A1(net1162),
    .A2(net1120));
 sg13g2_nand2_1 _2434_ (.Y(_0968_),
    .A(net1120),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_48_));
 sg13g2_o21ai_1 _2435_ (.B1(_0968_),
    .Y(_0228_),
    .A1(net1160),
    .A2(net1120));
 sg13g2_nand2_1 _2436_ (.Y(_0969_),
    .A(_0906_),
    .B(_0949_));
 sg13g2_nand2_1 _2438_ (.Y(_0971_),
    .A(net1101),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_46_));
 sg13g2_o21ai_1 _2439_ (.B1(_0971_),
    .Y(_0229_),
    .A1(net1171),
    .A2(net1101));
 sg13g2_nand2_1 _2440_ (.Y(_0972_),
    .A(net1101),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_45_));
 sg13g2_o21ai_1 _2441_ (.B1(_0972_),
    .Y(_0230_),
    .A1(net1170),
    .A2(net1101));
 sg13g2_nand2_1 _2442_ (.Y(_0973_),
    .A(net1101),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_44_));
 sg13g2_o21ai_1 _2443_ (.B1(_0973_),
    .Y(_0231_),
    .A1(net1167),
    .A2(net1101));
 sg13g2_nand2_1 _2444_ (.Y(_0974_),
    .A(net1102),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_43_));
 sg13g2_o21ai_1 _2445_ (.B1(_0974_),
    .Y(_0232_),
    .A1(net1165),
    .A2(net1102));
 sg13g2_nand2_1 _2446_ (.Y(_0975_),
    .A(net1102),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_42_));
 sg13g2_o21ai_1 _2447_ (.B1(_0975_),
    .Y(_0233_),
    .A1(net1163),
    .A2(net1102));
 sg13g2_nand2_1 _2448_ (.Y(_0976_),
    .A(net1102),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_41_));
 sg13g2_o21ai_1 _2449_ (.B1(_0976_),
    .Y(_0234_),
    .A1(net1161),
    .A2(net1102));
 sg13g2_nand2_1 _2450_ (.Y(_0977_),
    .A(net1102),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_40_));
 sg13g2_o21ai_1 _2451_ (.B1(_0977_),
    .Y(_0235_),
    .A1(net1159),
    .A2(net1102));
 sg13g2_nand2b_1 _2452_ (.Y(_0978_),
    .B(_0949_),
    .A_N(_0938_));
 sg13g2_nand2_1 _2454_ (.Y(_0980_),
    .A(net1117),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_38_));
 sg13g2_o21ai_1 _2455_ (.B1(_0980_),
    .Y(_0236_),
    .A1(net1171),
    .A2(net1117));
 sg13g2_nand2_1 _2456_ (.Y(_0981_),
    .A(net1117),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_37_));
 sg13g2_o21ai_1 _2457_ (.B1(_0981_),
    .Y(_0237_),
    .A1(net1170),
    .A2(net1117));
 sg13g2_nand2_1 _2458_ (.Y(_0982_),
    .A(net1117),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_36_));
 sg13g2_o21ai_1 _2459_ (.B1(_0982_),
    .Y(_0238_),
    .A1(net1167),
    .A2(net1117));
 sg13g2_nand2_1 _2460_ (.Y(_0983_),
    .A(net1118),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_35_));
 sg13g2_o21ai_1 _2461_ (.B1(_0983_),
    .Y(_0239_),
    .A1(net1165),
    .A2(net1118));
 sg13g2_nand2_1 _2462_ (.Y(_0984_),
    .A(net1118),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_34_));
 sg13g2_o21ai_1 _2463_ (.B1(_0984_),
    .Y(_0240_),
    .A1(net1163),
    .A2(net1118));
 sg13g2_nand2_1 _2464_ (.Y(_0985_),
    .A(net1118),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_33_));
 sg13g2_o21ai_1 _2465_ (.B1(_0985_),
    .Y(_0241_),
    .A1(net1161),
    .A2(net1118));
 sg13g2_nand2_1 _2466_ (.Y(_0986_),
    .A(net1118),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_32_));
 sg13g2_o21ai_1 _2467_ (.B1(_0986_),
    .Y(_0242_),
    .A1(net1159),
    .A2(net1118));
 sg13g2_nor2_1 _2468_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_),
    .Y(_0987_));
 sg13g2_nand2_1 _2469_ (.Y(_0988_),
    .A(_0894_),
    .B(_0987_));
 sg13g2_nand2_1 _2471_ (.Y(_0990_),
    .A(net1100),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_30_));
 sg13g2_o21ai_1 _2472_ (.B1(_0990_),
    .Y(_0243_),
    .A1(net1172),
    .A2(net1100));
 sg13g2_nand2_1 _2473_ (.Y(_0991_),
    .A(net1100),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_29_));
 sg13g2_o21ai_1 _2474_ (.B1(_0991_),
    .Y(_0244_),
    .A1(_0915_),
    .A2(net1100));
 sg13g2_nand2_1 _2475_ (.Y(_0992_),
    .A(net1100),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_28_));
 sg13g2_o21ai_1 _2476_ (.B1(_0992_),
    .Y(_0245_),
    .A1(_0919_),
    .A2(net1100));
 sg13g2_nand2_1 _2477_ (.Y(_0993_),
    .A(net1099),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_27_));
 sg13g2_o21ai_1 _2478_ (.B1(_0993_),
    .Y(_0246_),
    .A1(net1166),
    .A2(net1099));
 sg13g2_nand2_1 _2479_ (.Y(_0994_),
    .A(net1099),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_26_));
 sg13g2_o21ai_1 _2480_ (.B1(_0994_),
    .Y(_0247_),
    .A1(net1164),
    .A2(net1099));
 sg13g2_nand2_1 _2481_ (.Y(_0995_),
    .A(net1099),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_25_));
 sg13g2_o21ai_1 _2482_ (.B1(_0995_),
    .Y(_0248_),
    .A1(net1162),
    .A2(net1099));
 sg13g2_nand2_1 _2483_ (.Y(_0996_),
    .A(net1099),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_24_));
 sg13g2_o21ai_1 _2484_ (.B1(_0996_),
    .Y(_0249_),
    .A1(net1160),
    .A2(net1099));
 sg13g2_nand2b_1 _2485_ (.Y(_0997_),
    .B(_0987_),
    .A_N(_0959_));
 sg13g2_nand2_1 _2487_ (.Y(_0999_),
    .A(net1115),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_22_));
 sg13g2_o21ai_1 _2488_ (.B1(_0999_),
    .Y(_0250_),
    .A1(net1172),
    .A2(net1115));
 sg13g2_nand2_1 _2489_ (.Y(_1000_),
    .A(net1115),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_21_));
 sg13g2_o21ai_1 _2490_ (.B1(_1000_),
    .Y(_0251_),
    .A1(_0915_),
    .A2(net1115));
 sg13g2_nand2_1 _2491_ (.Y(_1001_),
    .A(net1115),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_20_));
 sg13g2_o21ai_1 _2492_ (.B1(_1001_),
    .Y(_0252_),
    .A1(net1168),
    .A2(net1115));
 sg13g2_nand2_1 _2493_ (.Y(_1002_),
    .A(net1116),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_19_));
 sg13g2_o21ai_1 _2494_ (.B1(_1002_),
    .Y(_0253_),
    .A1(net1166),
    .A2(net1116));
 sg13g2_nand2_1 _2495_ (.Y(_1003_),
    .A(net1116),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_18_));
 sg13g2_o21ai_1 _2496_ (.B1(_1003_),
    .Y(_0254_),
    .A1(net1164),
    .A2(net1116));
 sg13g2_nand2_1 _2497_ (.Y(_1004_),
    .A(net1116),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_17_));
 sg13g2_o21ai_1 _2498_ (.B1(_1004_),
    .Y(_0255_),
    .A1(net1162),
    .A2(net1116));
 sg13g2_nand2_1 _2499_ (.Y(_1005_),
    .A(net1116),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_16_));
 sg13g2_o21ai_1 _2500_ (.B1(_1005_),
    .Y(_0256_),
    .A1(net1160),
    .A2(net1116));
 sg13g2_nand2_1 _2501_ (.Y(_1006_),
    .A(_0906_),
    .B(_0987_));
 sg13g2_nand2_1 _2503_ (.Y(_1008_),
    .A(net1098),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_14_));
 sg13g2_o21ai_1 _2504_ (.B1(_1008_),
    .Y(_0257_),
    .A1(_0911_),
    .A2(net1098));
 sg13g2_nand2_1 _2505_ (.Y(_1009_),
    .A(net1098),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_13_));
 sg13g2_o21ai_1 _2506_ (.B1(_1009_),
    .Y(_0258_),
    .A1(_0915_),
    .A2(net1098));
 sg13g2_nand2_1 _2507_ (.Y(_1010_),
    .A(net1098),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_12_));
 sg13g2_o21ai_1 _2508_ (.B1(_1010_),
    .Y(_0259_),
    .A1(_0919_),
    .A2(net1098));
 sg13g2_nand2_1 _2509_ (.Y(_1011_),
    .A(net1097),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_11_));
 sg13g2_o21ai_1 _2510_ (.B1(_1011_),
    .Y(_0260_),
    .A1(_0923_),
    .A2(net1097));
 sg13g2_nand2_1 _2511_ (.Y(_1012_),
    .A(net1097),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_10_));
 sg13g2_o21ai_1 _2512_ (.B1(_1012_),
    .Y(_0261_),
    .A1(_0927_),
    .A2(net1097));
 sg13g2_nand2_1 _2513_ (.Y(_1013_),
    .A(net1097),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_9_));
 sg13g2_o21ai_1 _2514_ (.B1(_1013_),
    .Y(_0262_),
    .A1(_0931_),
    .A2(_1006_));
 sg13g2_nand2_1 _2515_ (.Y(_1014_),
    .A(net1097),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_8_));
 sg13g2_o21ai_1 _2516_ (.B1(_1014_),
    .Y(_0263_),
    .A1(_0935_),
    .A2(net1097));
 sg13g2_nor2_1 _2517_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_126_),
    .B(net1091),
    .Y(_1015_));
 sg13g2_a21oi_1 _2518_ (.A1(net1091),
    .A2(net1172),
    .Y(_0264_),
    .B1(_1015_));
 sg13g2_nor2_1 _2519_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_125_),
    .B(net1091),
    .Y(_1016_));
 sg13g2_a21oi_1 _2520_ (.A1(net1091),
    .A2(net1169),
    .Y(_0265_),
    .B1(_1016_));
 sg13g2_nor2_1 _2521_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_124_),
    .B(net1091),
    .Y(_1017_));
 sg13g2_a21oi_1 _2522_ (.A1(net1091),
    .A2(net1168),
    .Y(_0266_),
    .B1(_1017_));
 sg13g2_nor2_1 _2523_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_123_),
    .B(net1090),
    .Y(_1018_));
 sg13g2_a21oi_1 _2524_ (.A1(net1090),
    .A2(net1166),
    .Y(_0267_),
    .B1(_1018_));
 sg13g2_nor2_1 _2525_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_122_),
    .B(net1090),
    .Y(_1019_));
 sg13g2_a21oi_1 _2526_ (.A1(net1090),
    .A2(net1164),
    .Y(_0268_),
    .B1(_1019_));
 sg13g2_nor2_1 _2527_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_121_),
    .B(net1090),
    .Y(_1020_));
 sg13g2_a21oi_1 _2528_ (.A1(net1090),
    .A2(net1162),
    .Y(_0269_),
    .B1(_1020_));
 sg13g2_nor2_1 _2529_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_120_),
    .B(net1090),
    .Y(_1021_));
 sg13g2_a21oi_1 _2530_ (.A1(net1090),
    .A2(net1160),
    .Y(_0270_),
    .B1(_1021_));
 sg13g2_nor2_1 _2531_ (.A(_0389_),
    .B(_0948_),
    .Y(_1022_));
 sg13g2_nand2b_1 _2532_ (.Y(_1023_),
    .B(_1022_),
    .A_N(_0959_));
 sg13g2_nand2_1 _2534_ (.Y(_1025_),
    .A(net1113),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_118_));
 sg13g2_o21ai_1 _2535_ (.B1(_1025_),
    .Y(_0271_),
    .A1(net1172),
    .A2(net1113));
 sg13g2_nand2_1 _2536_ (.Y(_1026_),
    .A(net1113),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_117_));
 sg13g2_o21ai_1 _2537_ (.B1(_1026_),
    .Y(_0272_),
    .A1(net1169),
    .A2(net1113));
 sg13g2_nand2_1 _2538_ (.Y(_1027_),
    .A(net1113),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_116_));
 sg13g2_o21ai_1 _2539_ (.B1(_1027_),
    .Y(_0273_),
    .A1(net1168),
    .A2(net1113));
 sg13g2_nand2_1 _2540_ (.Y(_1028_),
    .A(net1114),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_115_));
 sg13g2_o21ai_1 _2541_ (.B1(_1028_),
    .Y(_0274_),
    .A1(net1166),
    .A2(net1114));
 sg13g2_nand2_1 _2542_ (.Y(_1029_),
    .A(net1114),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_114_));
 sg13g2_o21ai_1 _2543_ (.B1(_1029_),
    .Y(_0275_),
    .A1(net1164),
    .A2(net1114));
 sg13g2_nand2_1 _2544_ (.Y(_1030_),
    .A(net1114),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_113_));
 sg13g2_o21ai_1 _2545_ (.B1(_1030_),
    .Y(_0276_),
    .A1(net1162),
    .A2(net1114));
 sg13g2_nand2_1 _2546_ (.Y(_1031_),
    .A(net1114),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_112_));
 sg13g2_o21ai_1 _2547_ (.B1(_1031_),
    .Y(_0277_),
    .A1(net1160),
    .A2(net1114));
 sg13g2_nand2_1 _2548_ (.Y(_1032_),
    .A(_0906_),
    .B(_1022_));
 sg13g2_nand2_1 _2550_ (.Y(_1034_),
    .A(net1095),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_110_));
 sg13g2_o21ai_1 _2551_ (.B1(_1034_),
    .Y(_0278_),
    .A1(net1171),
    .A2(net1095));
 sg13g2_nand2_1 _2552_ (.Y(_1035_),
    .A(net1095),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_109_));
 sg13g2_o21ai_1 _2553_ (.B1(_1035_),
    .Y(_0279_),
    .A1(net1170),
    .A2(net1095));
 sg13g2_nand2_1 _2554_ (.Y(_1036_),
    .A(net1095),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_108_));
 sg13g2_o21ai_1 _2555_ (.B1(_1036_),
    .Y(_0280_),
    .A1(net1167),
    .A2(net1095));
 sg13g2_nand2_1 _2556_ (.Y(_1037_),
    .A(net1096),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_107_));
 sg13g2_o21ai_1 _2557_ (.B1(_1037_),
    .Y(_0281_),
    .A1(net1165),
    .A2(net1096));
 sg13g2_nand2_1 _2558_ (.Y(_1038_),
    .A(net1096),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_106_));
 sg13g2_o21ai_1 _2559_ (.B1(_1038_),
    .Y(_0282_),
    .A1(net1164),
    .A2(net1096));
 sg13g2_nand2_1 _2560_ (.Y(_1039_),
    .A(net1096),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_105_));
 sg13g2_o21ai_1 _2561_ (.B1(_1039_),
    .Y(_0283_),
    .A1(net1161),
    .A2(net1096));
 sg13g2_nand2_1 _2562_ (.Y(_1040_),
    .A(net1096),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_104_));
 sg13g2_o21ai_1 _2563_ (.B1(_1040_),
    .Y(_0284_),
    .A1(net1160),
    .A2(net1096));
 sg13g2_nand2b_1 _2564_ (.Y(_1041_),
    .B(_1022_),
    .A_N(_0938_));
 sg13g2_nand2_1 _2566_ (.Y(_1043_),
    .A(net1111),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_102_));
 sg13g2_o21ai_1 _2567_ (.B1(_1043_),
    .Y(_0285_),
    .A1(net1171),
    .A2(net1111));
 sg13g2_nand2_1 _2568_ (.Y(_1044_),
    .A(net1111),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_101_));
 sg13g2_o21ai_1 _2569_ (.B1(_1044_),
    .Y(_0286_),
    .A1(net1170),
    .A2(net1111));
 sg13g2_nand2_1 _2570_ (.Y(_1045_),
    .A(net1111),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_100_));
 sg13g2_o21ai_1 _2571_ (.B1(_1045_),
    .Y(_0287_),
    .A1(net1167),
    .A2(net1111));
 sg13g2_nand2_1 _2572_ (.Y(_1046_),
    .A(net1112),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_99_));
 sg13g2_o21ai_1 _2573_ (.B1(_1046_),
    .Y(_0288_),
    .A1(net1165),
    .A2(net1112));
 sg13g2_nand2_1 _2574_ (.Y(_1047_),
    .A(net1112),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_98_));
 sg13g2_o21ai_1 _2575_ (.B1(_1047_),
    .Y(_0289_),
    .A1(net1163),
    .A2(net1112));
 sg13g2_nand2_1 _2576_ (.Y(_1048_),
    .A(net1112),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_97_));
 sg13g2_o21ai_1 _2577_ (.B1(_1048_),
    .Y(_0290_),
    .A1(net1161),
    .A2(net1112));
 sg13g2_nand2_1 _2578_ (.Y(_1049_),
    .A(net1112),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_96_));
 sg13g2_o21ai_1 _2579_ (.B1(_1049_),
    .Y(_0291_),
    .A1(net1159),
    .A2(net1112));
 sg13g2_nand2_1 _2580_ (.Y(_1050_),
    .A(_0894_),
    .B(_0907_));
 sg13g2_nand2_1 _2582_ (.Y(_1052_),
    .A(net1094),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_94_));
 sg13g2_o21ai_1 _2583_ (.B1(_1052_),
    .Y(_0292_),
    .A1(net1171),
    .A2(_1050_));
 sg13g2_nand2_1 _2584_ (.Y(_1053_),
    .A(net1094),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_93_));
 sg13g2_o21ai_1 _2585_ (.B1(_1053_),
    .Y(_0293_),
    .A1(net1169),
    .A2(net1094));
 sg13g2_nand2_1 _2586_ (.Y(_1054_),
    .A(net1094),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_92_));
 sg13g2_o21ai_1 _2587_ (.B1(_1054_),
    .Y(_0294_),
    .A1(net1167),
    .A2(net1094));
 sg13g2_nand2_1 _2588_ (.Y(_1055_),
    .A(net1093),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_91_));
 sg13g2_o21ai_1 _2589_ (.B1(_1055_),
    .Y(_0295_),
    .A1(net1165),
    .A2(net1093));
 sg13g2_nand2_1 _2590_ (.Y(_1056_),
    .A(net1093),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_90_));
 sg13g2_o21ai_1 _2591_ (.B1(_1056_),
    .Y(_0296_),
    .A1(net1163),
    .A2(net1093));
 sg13g2_nand2_1 _2592_ (.Y(_1057_),
    .A(net1093),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_89_));
 sg13g2_o21ai_1 _2593_ (.B1(_1057_),
    .Y(_0297_),
    .A1(net1161),
    .A2(net1093));
 sg13g2_nand2_1 _2594_ (.Y(_1058_),
    .A(net1093),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_88_));
 sg13g2_o21ai_1 _2595_ (.B1(_1058_),
    .Y(_0298_),
    .A1(net1159),
    .A2(net1093));
 sg13g2_nand2b_1 _2596_ (.Y(_1059_),
    .B(_0907_),
    .A_N(_0959_));
 sg13g2_nand2_1 _2598_ (.Y(_1061_),
    .A(net1110),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_86_));
 sg13g2_o21ai_1 _2599_ (.B1(_1061_),
    .Y(_0299_),
    .A1(net1171),
    .A2(_1059_));
 sg13g2_nand2_1 _2600_ (.Y(_1062_),
    .A(_1059_),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_85_));
 sg13g2_o21ai_1 _2601_ (.B1(_1062_),
    .Y(_0300_),
    .A1(net1169),
    .A2(_1059_));
 sg13g2_nand2_1 _2602_ (.Y(_1063_),
    .A(net1110),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_84_));
 sg13g2_o21ai_1 _2603_ (.B1(_1063_),
    .Y(_0301_),
    .A1(net1167),
    .A2(net1110));
 sg13g2_nand2_1 _2604_ (.Y(_1064_),
    .A(net1109),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_83_));
 sg13g2_o21ai_1 _2605_ (.B1(_1064_),
    .Y(_0302_),
    .A1(net1165),
    .A2(net1109));
 sg13g2_nand2_1 _2606_ (.Y(_1065_),
    .A(net1109),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_82_));
 sg13g2_o21ai_1 _2607_ (.B1(_1065_),
    .Y(_0303_),
    .A1(net1163),
    .A2(net1109));
 sg13g2_nand2_1 _2608_ (.Y(_1066_),
    .A(net1109),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_81_));
 sg13g2_o21ai_1 _2609_ (.B1(_1066_),
    .Y(_0304_),
    .A1(net1161),
    .A2(net1109));
 sg13g2_nand2_1 _2610_ (.Y(_1067_),
    .A(net1109),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_80_));
 sg13g2_o21ai_1 _2611_ (.B1(_1067_),
    .Y(_0305_),
    .A1(net1159),
    .A2(net1109));
 sg13g2_nand2b_1 _2612_ (.Y(_1068_),
    .B(_0987_),
    .A_N(_0938_));
 sg13g2_nand2_1 _2614_ (.Y(_1070_),
    .A(net1108),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_6_));
 sg13g2_o21ai_1 _2615_ (.B1(_1070_),
    .Y(_0306_),
    .A1(_0911_),
    .A2(net1108));
 sg13g2_nand2_1 _2616_ (.Y(_1071_),
    .A(net1108),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_5_));
 sg13g2_o21ai_1 _2617_ (.B1(_1071_),
    .Y(_0307_),
    .A1(_0915_),
    .A2(net1108));
 sg13g2_nand2_1 _2618_ (.Y(_1072_),
    .A(net1108),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_4_));
 sg13g2_o21ai_1 _2619_ (.B1(_1072_),
    .Y(_0308_),
    .A1(_0919_),
    .A2(net1108));
 sg13g2_nand2_1 _2620_ (.Y(_1073_),
    .A(net1107),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_3_));
 sg13g2_o21ai_1 _2621_ (.B1(_1073_),
    .Y(_0309_),
    .A1(net1166),
    .A2(net1107));
 sg13g2_nand2_1 _2622_ (.Y(_1074_),
    .A(net1107),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_2_));
 sg13g2_o21ai_1 _2623_ (.B1(_1074_),
    .Y(_0310_),
    .A1(_0927_),
    .A2(net1107));
 sg13g2_nand2_1 _2624_ (.Y(_1075_),
    .A(net1107),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_1_));
 sg13g2_o21ai_1 _2625_ (.B1(_1075_),
    .Y(_0311_),
    .A1(_0931_),
    .A2(_1068_));
 sg13g2_nand2_1 _2626_ (.Y(_1076_),
    .A(net1107),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_0_));
 sg13g2_o21ai_1 _2627_ (.B1(_1076_),
    .Y(_0312_),
    .A1(_0935_),
    .A2(net1107));
 sg13g2_inv_1 _2628_ (.Y(_1077_),
    .A(net640));
 sg13g2_nor4_1 _2629_ (.A(_1077_),
    .B(net638),
    .C(net639),
    .D(net1187),
    .Y(_1078_));
 sg13g2_inv_1 _2630_ (.Y(_1079_),
    .A(net1296));
 sg13g2_nor3_1 _2631_ (.A(_0454_),
    .B(_1079_),
    .C(_0507_),
    .Y(_1080_));
 sg13g2_inv_1 _2632_ (.Y(_1081_),
    .A(_1080_));
 sg13g2_nor2_1 _2633_ (.A(_0659_),
    .B(_1081_),
    .Y(_1082_));
 sg13g2_nand2_1 _2634_ (.Y(_1083_),
    .A(_1082_),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_));
 sg13g2_nor2_2 _2635_ (.A(_0386_),
    .B(_1083_),
    .Y(_1084_));
 sg13g2_inv_1 _2636_ (.Y(_1085_),
    .A(_1083_));
 sg13g2_nor2_1 _2637_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_),
    .B(_1085_),
    .Y(_1086_));
 sg13g2_nor3_1 _2638_ (.A(_0899_),
    .B(_1084_),
    .C(_1086_),
    .Y(_0313_));
 sg13g2_nor2_1 _2639_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_),
    .B(_1082_),
    .Y(_1087_));
 sg13g2_nor3_1 _2640_ (.A(_0899_),
    .B(_1087_),
    .C(_1085_),
    .Y(_0314_));
 sg13g2_inv_1 _2641_ (.Y(_1088_),
    .A(_1084_));
 sg13g2_a21oi_1 _2642_ (.A1(net1202),
    .A2(_0426_),
    .Y(_1089_),
    .B1(_0899_));
 sg13g2_nand4_1 _2643_ (.B(_0659_),
    .C(_1080_),
    .A(_1088_),
    .Y(_1090_),
    .D(_1089_));
 sg13g2_nand3_1 _2644_ (.B(net1222),
    .C(_0898_),
    .A(_1081_),
    .Y(_1091_));
 sg13g2_nand2_1 _2645_ (.Y(_0315_),
    .A(_1090_),
    .B(_1091_));
 sg13g2_a21oi_1 _2646_ (.A1(_1088_),
    .A2(_1080_),
    .Y(_1092_),
    .B1(net1227));
 sg13g2_a221oi_1 _2647_ (.B2(reg2hw_0_),
    .C1(_1092_),
    .B1(reg2hw_1_),
    .A1(net1227),
    .Y(_0316_),
    .A2(_1080_));
 sg13g2_xnor2_1 _2648_ (.Y(_0010_),
    .A(_1316_),
    .B(_1315_));
 sg13g2_xnor2_1 _2649_ (.Y(_0012_),
    .A(_1323_),
    .B(_1322_));
 sg13g2_nand2b_1 _2650_ (.Y(_1093_),
    .B(_1320_),
    .A_N(_1321_));
 sg13g2_xnor2_1 _2651_ (.Y(_0011_),
    .A(_1093_),
    .B(_1318_));
 sg13g2_inv_1 _2652_ (.Y(_1094_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_15_));
 sg13g2_a21oi_1 _2653_ (.A1(_1094_),
    .A2(net1214),
    .Y(_1095_),
    .B1(net1210));
 sg13g2_o21ai_1 _2654_ (.B1(_1095_),
    .Y(_1096_),
    .A1(net1213),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_7_));
 sg13g2_inv_1 _2655_ (.Y(_1097_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_31_));
 sg13g2_a21oi_1 _2656_ (.A1(_1097_),
    .A2(net1212),
    .Y(_1098_),
    .B1(_0560_));
 sg13g2_o21ai_1 _2657_ (.B1(_1098_),
    .Y(_1099_),
    .A1(net1212),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_23_));
 sg13g2_nand3_1 _2658_ (.B(_1099_),
    .C(net1194),
    .A(_1096_),
    .Y(_1100_));
 sg13g2_inv_1 _2659_ (.Y(_1101_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_47_));
 sg13g2_a21oi_1 _2660_ (.A1(_1101_),
    .A2(net1214),
    .Y(_1102_),
    .B1(net1210));
 sg13g2_o21ai_1 _2661_ (.B1(_1102_),
    .Y(_1103_),
    .A1(net1213),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_39_));
 sg13g2_inv_1 _2662_ (.Y(_1104_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_63_));
 sg13g2_a21oi_1 _2663_ (.A1(_1104_),
    .A2(net1218),
    .Y(_1105_),
    .B1(_0560_));
 sg13g2_o21ai_1 _2664_ (.B1(_1105_),
    .Y(_1106_),
    .A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_55_));
 sg13g2_nand3_1 _2665_ (.B(_1106_),
    .C(net1207),
    .A(_1103_),
    .Y(_1107_));
 sg13g2_nand3_1 _2666_ (.B(_1100_),
    .C(_1107_),
    .A(net1143),
    .Y(_1108_));
 sg13g2_inv_1 _2667_ (.Y(_1109_),
    .A(_0038_));
 sg13g2_nand2_1 _2668_ (.Y(_1110_),
    .A(net1141),
    .B(_1109_));
 sg13g2_o21ai_1 _2669_ (.B1(_1110_),
    .Y(_1111_),
    .A1(_0686_),
    .A2(_1108_));
 sg13g2_nand2_1 _2670_ (.Y(_1112_),
    .A(net1127),
    .B(_0029_));
 sg13g2_o21ai_1 _2671_ (.B1(_1112_),
    .Y(_0317_),
    .A1(_1111_),
    .A2(net1092));
 sg13g2_a21oi_1 _2672_ (.A1(_0843_),
    .A2(net1215),
    .Y(_1113_),
    .B1(net1211));
 sg13g2_o21ai_1 _2673_ (.B1(_1113_),
    .Y(_1114_),
    .A1(net1215),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_6_));
 sg13g2_nand2b_1 _2674_ (.Y(_1115_),
    .B(net1193),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_22_));
 sg13g2_nand2b_1 _2675_ (.Y(_1116_),
    .B(net1218),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_30_));
 sg13g2_nand3_1 _2676_ (.B(_1116_),
    .C(net1209),
    .A(_1115_),
    .Y(_1117_));
 sg13g2_nand3_1 _2677_ (.B(_1117_),
    .C(net1194),
    .A(_1114_),
    .Y(_1118_));
 sg13g2_a21oi_1 _2678_ (.A1(_0798_),
    .A2(net1215),
    .Y(_1119_),
    .B1(net1211));
 sg13g2_o21ai_1 _2679_ (.B1(_1119_),
    .Y(_1120_),
    .A1(net1216),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_38_));
 sg13g2_nand2b_1 _2680_ (.Y(_1121_),
    .B(net1193),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_54_));
 sg13g2_nand2b_1 _2681_ (.Y(_1122_),
    .B(net1217),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_62_));
 sg13g2_nand3_1 _2682_ (.B(_1122_),
    .C(net1209),
    .A(_1121_),
    .Y(_1123_));
 sg13g2_nand3_1 _2683_ (.B(_1123_),
    .C(net1207),
    .A(_1120_),
    .Y(_1124_));
 sg13g2_nand3_1 _2684_ (.B(_1118_),
    .C(_1124_),
    .A(net1143),
    .Y(_1125_));
 sg13g2_nand2b_1 _2685_ (.Y(_1126_),
    .B(_0686_),
    .A_N(_0029_));
 sg13g2_o21ai_1 _2686_ (.B1(_1126_),
    .Y(_1127_),
    .A1(_0686_),
    .A2(_1125_));
 sg13g2_nand2_1 _2687_ (.Y(_1128_),
    .A(net1127),
    .B(_0030_));
 sg13g2_o21ai_1 _2688_ (.B1(_1128_),
    .Y(_0318_),
    .A1(_1127_),
    .A2(net1092));
 sg13g2_a21oi_1 _2689_ (.A1(_0848_),
    .A2(net1214),
    .Y(_1129_),
    .B1(net1210));
 sg13g2_o21ai_1 _2690_ (.B1(_1129_),
    .Y(_1130_),
    .A1(net1214),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_5_));
 sg13g2_nand2b_1 _2691_ (.Y(_1131_),
    .B(net1192),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_21_));
 sg13g2_nand2b_1 _2692_ (.Y(_1132_),
    .B(net1217),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_29_));
 sg13g2_nand3_1 _2693_ (.B(_1132_),
    .C(net1208),
    .A(_1131_),
    .Y(_1133_));
 sg13g2_nand3_1 _2694_ (.B(_1133_),
    .C(net1194),
    .A(_1130_),
    .Y(_1134_));
 sg13g2_a21oi_1 _2695_ (.A1(_0803_),
    .A2(net1214),
    .Y(_1135_),
    .B1(net1210));
 sg13g2_o21ai_1 _2696_ (.B1(_1135_),
    .Y(_1136_),
    .A1(net1213),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_37_));
 sg13g2_nand2b_1 _2697_ (.Y(_1137_),
    .B(net1192),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_53_));
 sg13g2_nand2b_1 _2698_ (.Y(_1138_),
    .B(net1217),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_61_));
 sg13g2_nand3_1 _2699_ (.B(_1138_),
    .C(net1208),
    .A(_1137_),
    .Y(_1139_));
 sg13g2_nand3_1 _2700_ (.B(_1139_),
    .C(net1207),
    .A(_1136_),
    .Y(_1140_));
 sg13g2_nand3_1 _2701_ (.B(_1134_),
    .C(_1140_),
    .A(net1143),
    .Y(_1141_));
 sg13g2_nand2b_1 _2702_ (.Y(_1142_),
    .B(net1142),
    .A_N(_0030_));
 sg13g2_o21ai_1 _2703_ (.B1(_1142_),
    .Y(_1143_),
    .A1(net1142),
    .A2(_1141_));
 sg13g2_nand2_1 _2704_ (.Y(_1144_),
    .A(net1127),
    .B(_0031_));
 sg13g2_o21ai_1 _2705_ (.B1(_1144_),
    .Y(_0319_),
    .A1(_1143_),
    .A2(net1092));
 sg13g2_a21oi_1 _2706_ (.A1(_0850_),
    .A2(net1215),
    .Y(_1145_),
    .B1(net1211));
 sg13g2_o21ai_1 _2707_ (.B1(_1145_),
    .Y(_1146_),
    .A1(net1215),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_4_));
 sg13g2_nand2b_1 _2708_ (.Y(_1147_),
    .B(net1193),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_20_));
 sg13g2_nand2b_1 _2709_ (.Y(_1148_),
    .B(net1218),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_28_));
 sg13g2_nand3_1 _2710_ (.B(_1148_),
    .C(net1209),
    .A(_1147_),
    .Y(_1149_));
 sg13g2_nand3_1 _2711_ (.B(_1149_),
    .C(net1194),
    .A(_1146_),
    .Y(_1150_));
 sg13g2_a21oi_1 _2712_ (.A1(_0805_),
    .A2(net1216),
    .Y(_1151_),
    .B1(net1210));
 sg13g2_o21ai_1 _2713_ (.B1(_1151_),
    .Y(_1152_),
    .A1(net1213),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_36_));
 sg13g2_nand2b_1 _2714_ (.Y(_1153_),
    .B(net1192),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_52_));
 sg13g2_nand2b_1 _2715_ (.Y(_1154_),
    .B(net1217),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_60_));
 sg13g2_nand3_1 _2716_ (.B(_1154_),
    .C(net1209),
    .A(_1153_),
    .Y(_1155_));
 sg13g2_nand3_1 _2717_ (.B(_1155_),
    .C(net1207),
    .A(_1152_),
    .Y(_1156_));
 sg13g2_nand3_1 _2718_ (.B(_1150_),
    .C(_1156_),
    .A(net1143),
    .Y(_1157_));
 sg13g2_nand2b_1 _2719_ (.Y(_1158_),
    .B(net1142),
    .A_N(_0031_));
 sg13g2_o21ai_1 _2720_ (.B1(_1158_),
    .Y(_1159_),
    .A1(net1142),
    .A2(_1157_));
 sg13g2_nand2_1 _2721_ (.Y(_1160_),
    .A(net1127),
    .B(_0032_));
 sg13g2_o21ai_1 _2722_ (.B1(_1160_),
    .Y(_0320_),
    .A1(_1159_),
    .A2(net1092));
 sg13g2_a21oi_1 _2723_ (.A1(_0852_),
    .A2(net1215),
    .Y(_1161_),
    .B1(net1211));
 sg13g2_o21ai_1 _2724_ (.B1(_1161_),
    .Y(_1162_),
    .A1(net1215),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_3_));
 sg13g2_nand2b_1 _2725_ (.Y(_1163_),
    .B(net1193),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_19_));
 sg13g2_nand2b_1 _2726_ (.Y(_1164_),
    .B(net1218),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_27_));
 sg13g2_nand3_1 _2727_ (.B(_1164_),
    .C(net1209),
    .A(_1163_),
    .Y(_1165_));
 sg13g2_nand3_1 _2728_ (.B(_1165_),
    .C(net1194),
    .A(_1162_),
    .Y(_1166_));
 sg13g2_a21oi_1 _2729_ (.A1(_0807_),
    .A2(net1216),
    .Y(_1167_),
    .B1(net1210));
 sg13g2_o21ai_1 _2730_ (.B1(_1167_),
    .Y(_1168_),
    .A1(net1213),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_35_));
 sg13g2_nand2b_1 _2731_ (.Y(_1169_),
    .B(net1193),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_51_));
 sg13g2_nand2b_1 _2732_ (.Y(_1170_),
    .B(net1218),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_59_));
 sg13g2_nand3_1 _2733_ (.B(_1170_),
    .C(net1209),
    .A(_1169_),
    .Y(_1171_));
 sg13g2_nand3_1 _2734_ (.B(_1171_),
    .C(net1207),
    .A(_1168_),
    .Y(_1172_));
 sg13g2_nand3_1 _2735_ (.B(_1166_),
    .C(_1172_),
    .A(net1143),
    .Y(_1173_));
 sg13g2_nand2b_1 _2736_ (.Y(_1174_),
    .B(net1142),
    .A_N(_0032_));
 sg13g2_o21ai_1 _2737_ (.B1(_1174_),
    .Y(_1175_),
    .A1(net1142),
    .A2(_1173_));
 sg13g2_nand2_1 _2738_ (.Y(_1176_),
    .A(net1127),
    .B(_0033_));
 sg13g2_o21ai_1 _2739_ (.B1(_1176_),
    .Y(_0321_),
    .A1(_1175_),
    .A2(net1092));
 sg13g2_a21oi_1 _2740_ (.A1(_0854_),
    .A2(net1214),
    .Y(_1177_),
    .B1(net1210));
 sg13g2_o21ai_1 _2741_ (.B1(_1177_),
    .Y(_1178_),
    .A1(net1214),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_2_));
 sg13g2_nand2b_1 _2742_ (.Y(_1179_),
    .B(net1193),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_18_));
 sg13g2_nand2b_1 _2743_ (.Y(_1180_),
    .B(net1218),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_26_));
 sg13g2_nand3_1 _2744_ (.B(_1180_),
    .C(net1209),
    .A(_1179_),
    .Y(_1181_));
 sg13g2_nand3_1 _2745_ (.B(_1181_),
    .C(net1194),
    .A(_1178_),
    .Y(_1182_));
 sg13g2_a21oi_1 _2746_ (.A1(_0809_),
    .A2(net1214),
    .Y(_1183_),
    .B1(net1210));
 sg13g2_o21ai_1 _2747_ (.B1(_1183_),
    .Y(_1184_),
    .A1(net1213),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_34_));
 sg13g2_nand2b_1 _2748_ (.Y(_1185_),
    .B(net1192),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_50_));
 sg13g2_nand2b_1 _2749_ (.Y(_1186_),
    .B(net1217),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_58_));
 sg13g2_nand3_1 _2750_ (.B(_1186_),
    .C(net1208),
    .A(_1185_),
    .Y(_1187_));
 sg13g2_nand3_1 _2751_ (.B(_1187_),
    .C(net1207),
    .A(_1184_),
    .Y(_1188_));
 sg13g2_nand3_1 _2752_ (.B(_1182_),
    .C(_1188_),
    .A(net1143),
    .Y(_1189_));
 sg13g2_nand2b_1 _2753_ (.Y(_1190_),
    .B(net1142),
    .A_N(_0033_));
 sg13g2_o21ai_1 _2754_ (.B1(_1190_),
    .Y(_1191_),
    .A1(net1142),
    .A2(_1189_));
 sg13g2_nand2_1 _2755_ (.Y(_1192_),
    .A(net1127),
    .B(_0034_));
 sg13g2_o21ai_1 _2756_ (.B1(_1192_),
    .Y(_0322_),
    .A1(_1191_),
    .A2(net1092));
 sg13g2_a21oi_1 _2757_ (.A1(_0856_),
    .A2(net1215),
    .Y(_1193_),
    .B1(net1211));
 sg13g2_o21ai_1 _2758_ (.B1(_1193_),
    .Y(_1194_),
    .A1(net1216),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_1_));
 sg13g2_nand2b_1 _2759_ (.Y(_1195_),
    .B(net1193),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_17_));
 sg13g2_nand2b_1 _2760_ (.Y(_1196_),
    .B(net1218),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_25_));
 sg13g2_nand3_1 _2761_ (.B(_1196_),
    .C(net1209),
    .A(_1195_),
    .Y(_1197_));
 sg13g2_nand3_1 _2762_ (.B(_1197_),
    .C(net1194),
    .A(_1194_),
    .Y(_1198_));
 sg13g2_a21oi_1 _2763_ (.A1(_0811_),
    .A2(net1213),
    .Y(_1199_),
    .B1(net1211));
 sg13g2_o21ai_1 _2764_ (.B1(_1199_),
    .Y(_1200_),
    .A1(net1212),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_33_));
 sg13g2_nand2b_1 _2765_ (.Y(_1201_),
    .B(net1192),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_49_));
 sg13g2_nand2b_1 _2766_ (.Y(_1202_),
    .B(net1217),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_57_));
 sg13g2_nand3_1 _2767_ (.B(_1202_),
    .C(net1208),
    .A(_1201_),
    .Y(_1203_));
 sg13g2_nand3_1 _2768_ (.B(_1203_),
    .C(net1207),
    .A(_1200_),
    .Y(_1204_));
 sg13g2_nand3_1 _2769_ (.B(_1198_),
    .C(_1204_),
    .A(net1143),
    .Y(_1205_));
 sg13g2_nand2b_1 _2770_ (.Y(_1206_),
    .B(net1141),
    .A_N(_0034_));
 sg13g2_o21ai_1 _2771_ (.B1(_1206_),
    .Y(_1207_),
    .A1(net1141),
    .A2(_1205_));
 sg13g2_nand2_1 _2772_ (.Y(_1208_),
    .A(net1127),
    .B(_0035_));
 sg13g2_o21ai_1 _2773_ (.B1(_1208_),
    .Y(_0323_),
    .A1(_1207_),
    .A2(net1092));
 sg13g2_a21oi_1 _2774_ (.A1(_0858_),
    .A2(net1212),
    .Y(_1209_),
    .B1(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_));
 sg13g2_o21ai_1 _2775_ (.B1(_1209_),
    .Y(_1210_),
    .A1(net1212),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_0_));
 sg13g2_nand2b_1 _2776_ (.Y(_1211_),
    .B(net1192),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_16_));
 sg13g2_nand2b_1 _2777_ (.Y(_1212_),
    .B(net1217),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_24_));
 sg13g2_nand3_1 _2778_ (.B(_1212_),
    .C(net1208),
    .A(_1211_),
    .Y(_1213_));
 sg13g2_nand3_1 _2779_ (.B(_1213_),
    .C(net1194),
    .A(_1210_),
    .Y(_1214_));
 sg13g2_a21oi_1 _2780_ (.A1(_0813_),
    .A2(net1212),
    .Y(_1215_),
    .B1(net1208));
 sg13g2_o21ai_1 _2781_ (.B1(_1215_),
    .Y(_1216_),
    .A1(net1212),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_32_));
 sg13g2_nand2b_1 _2782_ (.Y(_1217_),
    .B(net1192),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_48_));
 sg13g2_nand2b_1 _2783_ (.Y(_1218_),
    .B(net1217),
    .A_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_56_));
 sg13g2_nand3_1 _2784_ (.B(_1218_),
    .C(net1208),
    .A(_1217_),
    .Y(_1219_));
 sg13g2_nand3_1 _2785_ (.B(_1219_),
    .C(net1207),
    .A(_1216_),
    .Y(_1220_));
 sg13g2_nand3_1 _2786_ (.B(_1214_),
    .C(_1220_),
    .A(net1143),
    .Y(_1221_));
 sg13g2_nand2b_1 _2787_ (.Y(_1222_),
    .B(net1141),
    .A_N(_0035_));
 sg13g2_o21ai_1 _2788_ (.B1(_1222_),
    .Y(_1223_),
    .A1(net1141),
    .A2(_1221_));
 sg13g2_nand2_1 _2789_ (.Y(_1224_),
    .A(net1127),
    .B(_0036_));
 sg13g2_o21ai_1 _2790_ (.B1(_1224_),
    .Y(_0324_),
    .A1(_1223_),
    .A2(net1092));
 sg13g2_inv_1 _2791_ (.Y(_1225_),
    .A(_0037_));
 sg13g2_o21ai_1 _2792_ (.B1(_0692_),
    .Y(_1226_),
    .A1(_0036_),
    .A2(_0688_));
 sg13g2_o21ai_1 _2793_ (.B1(_1226_),
    .Y(_0325_),
    .A1(_1225_),
    .A2(_0691_));
 sg13g2_xnor2_1 _2794_ (.Y(_1227_),
    .A(_1173_),
    .B(_1189_));
 sg13g2_xnor2_1 _2795_ (.Y(_1228_),
    .A(_1205_),
    .B(_1221_));
 sg13g2_xnor2_1 _2796_ (.Y(_1229_),
    .A(_1227_),
    .B(_1228_));
 sg13g2_xnor2_1 _2797_ (.Y(_1230_),
    .A(_1108_),
    .B(_1125_));
 sg13g2_xnor2_1 _2798_ (.Y(_1231_),
    .A(_1141_),
    .B(_1157_));
 sg13g2_xnor2_1 _2799_ (.Y(_1232_),
    .A(_1230_),
    .B(_1231_));
 sg13g2_xnor2_1 _2800_ (.Y(_1233_),
    .A(_1229_),
    .B(_1232_));
 sg13g2_o21ai_1 _2801_ (.B1(_0703_),
    .Y(_1234_),
    .A1(reg2hw_40_),
    .A2(_1233_));
 sg13g2_a21o_1 _2802_ (.A2(_1233_),
    .A1(reg2hw_40_),
    .B1(_1234_),
    .X(_1235_));
 sg13g2_o21ai_1 _2803_ (.B1(_1235_),
    .Y(_0326_),
    .A1(_1109_),
    .A2(_0691_));
 sg13g2_a21o_1 _2804_ (.A2(net1185),
    .A1(net727),
    .B1(net1296),
    .X(_0327_));
 sg13g2_o21ai_1 _2805_ (.B1(_0898_),
    .Y(_1236_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .A2(_1084_));
 sg13g2_a21oi_1 _2806_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .A2(_1084_),
    .Y(_0328_),
    .B1(_1236_));
 sg13g2_nand2_1 _2807_ (.Y(_1237_),
    .A(_0732_),
    .B(net1251));
 sg13g2_o21ai_1 _2808_ (.B1(_1237_),
    .Y(_1238_),
    .A1(reg2hw_39_),
    .A2(u_uart_core_uart_rx_sreg_q_9_));
 sg13g2_nand2_1 _2810_ (.Y(_1240_),
    .A(net1108),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_7_));
 sg13g2_o21ai_1 _2811_ (.B1(_1240_),
    .Y(_0329_),
    .A1(net1108),
    .A2(_1238_));
 sg13g2_nand2_1 _2812_ (.Y(_1241_),
    .A(net1110),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_87_));
 sg13g2_o21ai_1 _2813_ (.B1(_1241_),
    .Y(_0330_),
    .A1(net1110),
    .A2(net1157));
 sg13g2_nand2_1 _2814_ (.Y(_1242_),
    .A(net1094),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_95_));
 sg13g2_o21ai_1 _2815_ (.B1(_1242_),
    .Y(_0331_),
    .A1(net1094),
    .A2(net1157));
 sg13g2_nand2_1 _2816_ (.Y(_1243_),
    .A(net1111),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_103_));
 sg13g2_o21ai_1 _2817_ (.B1(_1243_),
    .Y(_0332_),
    .A1(net1111),
    .A2(net1157));
 sg13g2_nand2_1 _2818_ (.Y(_1244_),
    .A(net1095),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_111_));
 sg13g2_o21ai_1 _2819_ (.B1(_1244_),
    .Y(_0333_),
    .A1(net1095),
    .A2(net1157));
 sg13g2_nand2_1 _2820_ (.Y(_1245_),
    .A(net1113),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_119_));
 sg13g2_o21ai_1 _2821_ (.B1(_1245_),
    .Y(_0334_),
    .A1(net1113),
    .A2(net1158));
 sg13g2_nor2_1 _2822_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_127_),
    .B(net1091),
    .Y(_1246_));
 sg13g2_a21oi_1 _2823_ (.A1(net1091),
    .A2(net1158),
    .Y(_0335_),
    .B1(_1246_));
 sg13g2_nand2_1 _2824_ (.Y(_1247_),
    .A(net1098),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_15_));
 sg13g2_o21ai_1 _2825_ (.B1(_1247_),
    .Y(_0336_),
    .A1(net1098),
    .A2(_1238_));
 sg13g2_nand2_1 _2826_ (.Y(_1248_),
    .A(net1115),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_23_));
 sg13g2_o21ai_1 _2827_ (.B1(_1248_),
    .Y(_0337_),
    .A1(net1115),
    .A2(net1158));
 sg13g2_nand2_1 _2828_ (.Y(_1249_),
    .A(net1100),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_31_));
 sg13g2_o21ai_1 _2829_ (.B1(_1249_),
    .Y(_0338_),
    .A1(net1100),
    .A2(net1158));
 sg13g2_nand2_1 _2830_ (.Y(_1250_),
    .A(net1117),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_39_));
 sg13g2_o21ai_1 _2831_ (.B1(_1250_),
    .Y(_0339_),
    .A1(net1117),
    .A2(net1157));
 sg13g2_nand2_1 _2832_ (.Y(_1251_),
    .A(net1101),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_47_));
 sg13g2_o21ai_1 _2833_ (.B1(_1251_),
    .Y(_0340_),
    .A1(net1101),
    .A2(net1157));
 sg13g2_nand2_1 _2834_ (.Y(_1252_),
    .A(net1119),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_55_));
 sg13g2_o21ai_1 _2835_ (.B1(_1252_),
    .Y(_0341_),
    .A1(net1119),
    .A2(net1158));
 sg13g2_nand2_1 _2836_ (.Y(_1253_),
    .A(net1103),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_63_));
 sg13g2_o21ai_1 _2837_ (.B1(_1253_),
    .Y(_0342_),
    .A1(net1103),
    .A2(net1158));
 sg13g2_nand2_1 _2838_ (.Y(_1254_),
    .A(net1122),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_71_));
 sg13g2_o21ai_1 _2839_ (.B1(_1254_),
    .Y(_0343_),
    .A1(net1122),
    .A2(net1157));
 sg13g2_nand2_1 _2840_ (.Y(_1255_),
    .A(net1106),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_79_));
 sg13g2_o21ai_1 _2841_ (.B1(_1255_),
    .Y(_0344_),
    .A1(net1106),
    .A2(net1157));
 sg13g2_o21ai_1 _2842_ (.B1(_0898_),
    .Y(_1256_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .A2(_0896_));
 sg13g2_a21oi_1 _2843_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .A2(_0896_),
    .Y(_0345_),
    .B1(_1256_));
 sg13g2_nor2_1 _2844_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .B(_0872_),
    .Y(_1257_));
 sg13g2_and2_1 _2845_ (.A(_0872_),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .X(_1258_));
 sg13g2_nor3_1 _2846_ (.A(_0774_),
    .B(_1257_),
    .C(_1258_),
    .Y(_0346_));
 sg13g2_inv_2 _2847_ (.Y(_1259_),
    .A(reg2hw_12_));
 sg13g2_nor2_1 _2848_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_7_),
    .B(net1128),
    .Y(_1260_));
 sg13g2_a21oi_1 _2849_ (.A1(_1259_),
    .A2(net1128),
    .Y(_0347_),
    .B1(_1260_));
 sg13g2_nand2_1 _2850_ (.Y(_1261_),
    .A(net1130),
    .B(reg2hw_12_));
 sg13g2_o21ai_1 _2851_ (.B1(_1261_),
    .Y(_0348_),
    .A1(_1094_),
    .A2(net1130));
 sg13g2_nand2_1 _2852_ (.Y(_1262_),
    .A(net1137),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_23_));
 sg13g2_o21ai_1 _2853_ (.B1(_1262_),
    .Y(_0349_),
    .A1(_1259_),
    .A2(_0834_));
 sg13g2_nand2_1 _2854_ (.Y(_1263_),
    .A(net1123),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_31_));
 sg13g2_o21ai_1 _2855_ (.B1(_1263_),
    .Y(_0350_),
    .A1(_1259_),
    .A2(net1123));
 sg13g2_nor2_1 _2856_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_39_),
    .B(net1133),
    .Y(_1264_));
 sg13g2_a21oi_1 _2857_ (.A1(_1259_),
    .A2(net1132),
    .Y(_0351_),
    .B1(_1264_));
 sg13g2_nand2_1 _2858_ (.Y(_1265_),
    .A(net1134),
    .B(reg2hw_12_));
 sg13g2_o21ai_1 _2859_ (.B1(_1265_),
    .Y(_0352_),
    .A1(_1101_),
    .A2(net1134));
 sg13g2_nand2_1 _2860_ (.Y(_1266_),
    .A(net1139),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_55_));
 sg13g2_o21ai_1 _2861_ (.B1(_1266_),
    .Y(_0353_),
    .A1(_1259_),
    .A2(_0789_));
 sg13g2_nand2_1 _2862_ (.Y(_1267_),
    .A(_0776_),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_63_));
 sg13g2_o21ai_1 _2863_ (.B1(_1267_),
    .Y(_0354_),
    .A1(_1259_),
    .A2(_0776_));
 sg13g2_nor2b_1 _2864_ (.A(_0776_),
    .B_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .Y(_1268_));
 sg13g2_nor2_1 _2865_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .B(_0778_),
    .Y(_1269_));
 sg13g2_nor3_1 _2866_ (.A(_0774_),
    .B(_1268_),
    .C(_1269_),
    .Y(_0355_));
 sg13g2_inv_1 _2867_ (.Y(_1270_),
    .A(u_uart_core_uart_rx_baud_div_q_3_));
 sg13g2_nor4_1 _2868_ (.A(_1270_),
    .B(_0760_),
    .C(_0762_),
    .D(_0719_),
    .Y(u_uart_core_uart_rx_tick_baud_d));
 sg13g2_a21oi_1 _2869_ (.A1(_1270_),
    .A2(_0764_),
    .Y(_0356_),
    .B1(u_uart_core_uart_rx_tick_baud_d));
 sg13g2_xnor2_1 _2870_ (.Y(_1271_),
    .A(_0722_),
    .B(_0750_));
 sg13g2_a21oi_1 _2871_ (.A1(_0718_),
    .A2(_0722_),
    .Y(_1272_),
    .B1(_0710_));
 sg13g2_a21o_1 _2872_ (.A2(_1271_),
    .A1(_0729_),
    .B1(_1272_),
    .X(_0357_));
 sg13g2_nor4_1 _2873_ (.A(u_uart_core_uart_rx_bit_cnt_q_2_),
    .B(u_uart_core_uart_rx_bit_cnt_q_3_),
    .C(_0709_),
    .D(_0755_),
    .Y(_0000_));
 sg13g2_nor2_1 _2874_ (.A(_0511_),
    .B(_0000_),
    .Y(_1273_));
 sg13g2_o21ai_1 _2875_ (.B1(_1273_),
    .Y(_1274_),
    .A1(_0709_),
    .A2(_0725_));
 sg13g2_nand2_1 _2876_ (.Y(_0358_),
    .A(_1274_),
    .B(_0718_));
 sg13g2_nand2b_1 _2877_ (.Y(_1275_),
    .B(_0729_),
    .A_N(_0717_));
 sg13g2_o21ai_1 _2878_ (.B1(_1275_),
    .Y(_0359_),
    .A1(_0888_),
    .A2(_0726_));
 sg13g2_nand2_1 _2879_ (.Y(_1276_),
    .A(_0707_),
    .B(u_uart_core_uart_tx_baud_div_q_2_));
 sg13g2_xnor2_1 _2880_ (.Y(_0360_),
    .A(u_uart_core_uart_tx_baud_div_q_3_),
    .B(_1276_));
 sg13g2_a21oi_1 _2881_ (.A1(_0586_),
    .A2(_0587_),
    .Y(_1277_),
    .B1(_0681_));
 sg13g2_o21ai_1 _2882_ (.B1(u_uart_core_uart_tx_bit_cnt_q_3_),
    .Y(_1278_),
    .A1(_1277_),
    .A2(_0689_));
 sg13g2_nand2_1 _2883_ (.Y(_0361_),
    .A(_1278_),
    .B(_0701_));
 sg13g2_nand3_1 _2884_ (.B(_0037_),
    .C(reg2hw_34_),
    .A(_0683_),
    .Y(_1279_));
 sg13g2_o21ai_1 _2885_ (.B1(_1279_),
    .Y(_0362_),
    .A1(_1297_),
    .A2(_0685_));
 sg13g2_inv_1 _2886_ (.Y(_1280_),
    .A(net688));
 sg13g2_a21oi_1 _2887_ (.A1(net1313),
    .A2(net1285),
    .Y(_1281_),
    .B1(net1188));
 sg13g2_o21ai_1 _2888_ (.B1(_1079_),
    .Y(_1282_),
    .A1(net1285),
    .A2(_1400_));
 sg13g2_a22oi_1 _2889_ (.Y(_1283_),
    .B1(_1441_),
    .B2(_1282_),
    .A2(_1401_),
    .A1(net1316));
 sg13g2_a22oi_1 _2890_ (.Y(_0363_),
    .B1(_1281_),
    .B2(_1283_),
    .A2(net1188),
    .A1(_1280_));
 sg13g2_o21ai_1 _2891_ (.B1(net1182),
    .Y(_0364_),
    .A1(net683),
    .A2(net1254));
 sg13g2_inv_1 _2892_ (.Y(_1284_),
    .A(net716));
 sg13g2_nand2_1 _2893_ (.Y(_1285_),
    .A(net1189),
    .B(reg2hw_56_));
 sg13g2_a22oi_1 _2894_ (.Y(_0365_),
    .B1(_1285_),
    .B2(net1156),
    .A2(net1185),
    .A1(_1284_));
 sg13g2_mux2_1 _2895_ (.A0(net682),
    .A1(net724),
    .S(net1187),
    .X(_0366_));
 sg13g2_mux2_1 _2896_ (.A0(net637),
    .A1(net726),
    .S(net1186),
    .X(_0367_));
 sg13g2_nand2_1 _2897_ (.Y(_1286_),
    .A(net1151),
    .B(net647));
 sg13g2_o21ai_1 _2898_ (.B1(_1286_),
    .Y(_0368_),
    .A1(_0714_),
    .A2(net1151));
 sg13g2_mux2_1 _2899_ (.A0(reg2hw_56_),
    .A1(net665),
    .S(_1419_),
    .X(_0369_));
 sg13g2_nand2_1 _2900_ (.Y(_1287_),
    .A(net1151),
    .B(net644));
 sg13g2_o21ai_1 _2901_ (.B1(_1287_),
    .Y(_0370_),
    .A1(_0618_),
    .A2(net1151));
 sg13g2_nand2_1 _2902_ (.Y(_1288_),
    .A(net1152),
    .B(net648));
 sg13g2_o21ai_1 _2903_ (.B1(net1288),
    .Y(_0371_),
    .A1(_0702_),
    .A2(net1152));
 sg13g2_mux2_1 _2904_ (.A0(reg2hw_40_),
    .A1(net649),
    .S(net1152),
    .X(_0372_));
 sg13g2_nand2_1 _2905_ (.Y(_1289_),
    .A(net1152),
    .B(net643));
 sg13g2_o21ai_1 _2906_ (.B1(_1289_),
    .Y(_0373_),
    .A1(_0648_),
    .A2(net1151));
 sg13g2_nand2_1 _2907_ (.Y(_1290_),
    .A(net1151),
    .B(net646));
 sg13g2_o21ai_1 _2908_ (.B1(_1290_),
    .Y(_0374_),
    .A1(_0711_),
    .A2(net1151));
 sg13g2_nand2_1 _2909_ (.Y(_1291_),
    .A(net1287),
    .B(net642));
 sg13g2_o21ai_1 _2910_ (.B1(_1291_),
    .Y(_0375_),
    .A1(_0681_),
    .A2(net1152));
 sg13g2_and4_1 _2911_ (.A(net674),
    .B(_1283_),
    .C(_1383_),
    .D(_1401_),
    .X(_1292_));
 sg13g2_mux2_1 _2913_ (.A0(reg2hw_1_),
    .A1(net642),
    .S(_1292_),
    .X(_0376_));
 sg13g2_mux2_1 _2914_ (.A0(reg2hw_3_),
    .A1(net643),
    .S(_1292_),
    .X(_0377_));
 sg13g2_nand2_1 _2915_ (.Y(_1293_),
    .A(net1145),
    .B(net649));
 sg13g2_o21ai_1 _2916_ (.B1(_1293_),
    .Y(_0378_),
    .A1(_1259_),
    .A2(net1146));
 sg13g2_nand2_1 _2917_ (.Y(_1294_),
    .A(net634),
    .B(reg2hw_38_));
 sg13g2_o21ai_1 _2918_ (.B1(_1294_),
    .Y(net729),
    .A1(reg2hw_38_),
    .A2(_0043_));
 sg13g2_xnor2_1 _2919_ (.Y(_0003_),
    .A(_1352_),
    .B(_1351_));
 sg13g2_xor2_1 _2920_ (.B(_1327_),
    .A(_1332_),
    .X(_0014_));
 sg13g2_nor2_1 _2921_ (.A(_1341_),
    .B(_1343_),
    .Y(_1295_));
 sg13g2_nor2b_1 _2922_ (.A(_1370_),
    .B_N(_1348_),
    .Y(_1296_));
 sg13g2_xnor2_1 _2923_ (.Y(_0017_),
    .A(_1295_),
    .B(_1296_));
 sg13g2_nor2b_1 _2924_ (.A(_1276_),
    .B_N(u_uart_core_uart_tx_baud_div_q_3_),
    .Y(_1473_));
 sg13g2_dfrbpq_1 _2925_ (.RESET_B(net1250),
    .D(_0136_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_),
    .CLK(clknet_leaf_30_clk_i));
 sg13g2_dfrbpq_1 _2926_ (.RESET_B(net1250),
    .D(_0135_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_),
    .CLK(clknet_leaf_31_clk_i));
 sg13g2_dfrbpq_1 _2927_ (.RESET_B(net1250),
    .D(_0355_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .CLK(clknet_leaf_19_clk_i));
 sg13g2_dfrbpq_1 _2928_ (.RESET_B(net1240),
    .D(_0134_),
    .Q(u_uart_core_uart_rx_baud_div_q_0_),
    .CLK(clknet_leaf_17_clk_i));
 sg13g2_dfrbpq_1 _2929_ (.RESET_B(net1240),
    .D(_0133_),
    .Q(u_uart_core_uart_rx_baud_div_q_1_),
    .CLK(clknet_leaf_14_clk_i));
 sg13g2_dfrbpq_1 _2930_ (.RESET_B(net1241),
    .D(_0132_),
    .Q(u_uart_core_uart_rx_baud_div_q_2_),
    .CLK(clknet_leaf_14_clk_i));
 sg13g2_dfrbpq_1 _2931_ (.RESET_B(net1240),
    .D(_0356_),
    .Q(u_uart_core_uart_rx_baud_div_q_3_),
    .CLK(clknet_leaf_14_clk_i));
 sg13g2_dfrbpq_1 _2932_ (.RESET_B(net1241),
    .D(_0131_),
    .Q(u_uart_core_uart_rx_bit_cnt_q_0_),
    .CLK(clknet_leaf_10_clk_i));
 sg13g2_dfrbpq_1 _2933_ (.RESET_B(net1241),
    .D(_0130_),
    .Q(u_uart_core_uart_rx_bit_cnt_q_1_),
    .CLK(clknet_leaf_10_clk_i));
 sg13g2_dfrbpq_1 _2934_ (.RESET_B(net1241),
    .D(_0129_),
    .Q(u_uart_core_uart_rx_bit_cnt_q_2_),
    .CLK(clknet_leaf_10_clk_i));
 sg13g2_dfrbpq_1 _2935_ (.RESET_B(net1241),
    .D(_0357_),
    .Q(u_uart_core_uart_rx_bit_cnt_q_3_),
    .CLK(clknet_leaf_14_clk_i));
 sg13g2_dfrbpq_1 _2936_ (.RESET_B(net1241),
    .D(_0358_),
    .Q(_0046_),
    .CLK(clknet_leaf_6_clk_i));
 sg13g2_dfrbpq_1 _2937_ (.RESET_B(net1243),
    .D(_0128_),
    .Q(u_uart_core_uart_rx_sreg_q_1_),
    .CLK(clknet_leaf_6_clk_i));
 sg13g2_dfrbpq_1 _2938_ (.RESET_B(net1243),
    .D(_0127_),
    .Q(u_uart_core_uart_rx_sreg_q_2_),
    .CLK(clknet_leaf_7_clk_i));
 sg13g2_dfrbpq_1 _2939_ (.RESET_B(net1243),
    .D(_0126_),
    .Q(u_uart_core_uart_rx_sreg_q_3_),
    .CLK(clknet_leaf_6_clk_i));
 sg13g2_dfrbpq_1 _2940_ (.RESET_B(net1242),
    .D(_0125_),
    .Q(u_uart_core_uart_rx_sreg_q_4_),
    .CLK(clknet_leaf_7_clk_i));
 sg13g2_dfrbpq_1 _2941_ (.RESET_B(net1242),
    .D(_0124_),
    .Q(u_uart_core_uart_rx_sreg_q_5_),
    .CLK(clknet_leaf_8_clk_i));
 sg13g2_dfrbpq_1 _2942_ (.RESET_B(net1242),
    .D(_0123_),
    .Q(u_uart_core_uart_rx_sreg_q_6_),
    .CLK(clknet_leaf_8_clk_i));
 sg13g2_dfrbpq_1 _2943_ (.RESET_B(net1242),
    .D(_0122_),
    .Q(u_uart_core_uart_rx_sreg_q_7_),
    .CLK(clknet_leaf_9_clk_i));
 sg13g2_dfrbpq_1 _2944_ (.RESET_B(net1242),
    .D(_0121_),
    .Q(u_uart_core_uart_rx_sreg_q_8_),
    .CLK(clknet_leaf_10_clk_i));
 sg13g2_dfrbpq_1 _2945_ (.RESET_B(net1242),
    .D(_0120_),
    .Q(u_uart_core_uart_rx_sreg_q_9_),
    .CLK(clknet_leaf_9_clk_i));
 sg13g2_dfrbpq_1 _2946_ (.RESET_B(net1243),
    .D(_0359_),
    .Q(u_uart_core_uart_rx_sreg_q_10_),
    .CLK(clknet_leaf_6_clk_i));
 sg13g2_dfrbpq_1 _2947_ (.RESET_B(net1247),
    .D(_0119_),
    .Q(u_uart_core_uart_tx_baud_div_q_0_),
    .CLK(clknet_leaf_18_clk_i));
 sg13g2_dfrbpq_1 _2948_ (.RESET_B(net1247),
    .D(_0118_),
    .Q(u_uart_core_uart_tx_baud_div_q_1_),
    .CLK(clknet_leaf_18_clk_i));
 sg13g2_dfrbpq_1 _2949_ (.RESET_B(net1247),
    .D(_0117_),
    .Q(u_uart_core_uart_tx_baud_div_q_2_),
    .CLK(clknet_leaf_17_clk_i));
 sg13g2_dfrbpq_1 _2950_ (.RESET_B(net1247),
    .D(_0360_),
    .Q(u_uart_core_uart_tx_baud_div_q_3_),
    .CLK(clknet_leaf_19_clk_i));
 sg13g2_dfrbpq_1 _2951_ (.RESET_B(net1249),
    .D(_0116_),
    .Q(u_uart_core_uart_tx_bit_cnt_q_0_),
    .CLK(clknet_leaf_5_clk_i));
 sg13g2_dfrbpq_1 _2952_ (.RESET_B(net1249),
    .D(_0115_),
    .Q(u_uart_core_uart_tx_bit_cnt_q_1_),
    .CLK(clknet_leaf_5_clk_i));
 sg13g2_dfrbpq_1 _2953_ (.RESET_B(net1249),
    .D(_0114_),
    .Q(u_uart_core_uart_tx_bit_cnt_q_2_),
    .CLK(clknet_leaf_32_clk_i));
 sg13g2_dfrbpq_1 _2954_ (.RESET_B(net1249),
    .D(_0361_),
    .Q(u_uart_core_uart_tx_bit_cnt_q_3_),
    .CLK(clknet_leaf_19_clk_i));
 sg13g2_dfrbpq_1 _2955_ (.RESET_B(u_uart_core_tx_rst_ni),
    .D(_0362_),
    .Q(_0047_),
    .CLK(clknet_leaf_18_clk_i));
 sg13g2_dfrbpq_1 _2956_ (.RESET_B(net1232),
    .D(_0363_),
    .Q(net688),
    .CLK(clknet_leaf_21_clk_i));
 sg13g2_dfrbpq_1 _2957_ (.RESET_B(net1230),
    .D(_0364_),
    .Q(net728),
    .CLK(clknet_leaf_11_clk_i));
 sg13g2_dfrbpq_1 _2958_ (.RESET_B(net1237),
    .D(_0113_),
    .Q(net684),
    .CLK(clknet_leaf_18_clk_i));
 sg13g2_dfrbpq_1 _2959_ (.RESET_B(net1238),
    .D(_0112_),
    .Q(net685),
    .CLK(clknet_leaf_20_clk_i));
 sg13g2_dfrbpq_1 _2960_ (.RESET_B(net1239),
    .D(_0111_),
    .Q(net686),
    .CLK(clknet_leaf_21_clk_i));
 sg13g2_dfrbpq_1 _2961_ (.RESET_B(net1238),
    .D(_0110_),
    .Q(net687),
    .CLK(clknet_leaf_20_clk_i));
 sg13g2_dfrbpq_1 _2962_ (.RESET_B(net1229),
    .D(_0109_),
    .Q(net689),
    .CLK(clknet_leaf_9_clk_i));
 sg13g2_dfrbpq_1 _2963_ (.RESET_B(net1229),
    .D(_0108_),
    .Q(net690),
    .CLK(clknet_leaf_8_clk_i));
 sg13g2_dfrbpq_1 _2964_ (.RESET_B(net1229),
    .D(_0107_),
    .Q(net691),
    .CLK(clknet_leaf_9_clk_i));
 sg13g2_dfrbpq_1 _2965_ (.RESET_B(net1229),
    .D(_0106_),
    .Q(net692),
    .CLK(clknet_leaf_9_clk_i));
 sg13g2_dfrbpq_1 _2966_ (.RESET_B(net1230),
    .D(_0105_),
    .Q(net693),
    .CLK(clknet_leaf_9_clk_i));
 sg13g2_dfrbpq_1 _2967_ (.RESET_B(net1230),
    .D(_0104_),
    .Q(net694),
    .CLK(clknet_leaf_11_clk_i));
 sg13g2_dfrbpq_1 _2968_ (.RESET_B(net1230),
    .D(_0103_),
    .Q(net695),
    .CLK(clknet_leaf_11_clk_i));
 sg13g2_dfrbpq_1 _2969_ (.RESET_B(net1231),
    .D(_0102_),
    .Q(net696),
    .CLK(clknet_leaf_13_clk_i));
 sg13g2_dfrbpq_1 _2970_ (.RESET_B(net1231),
    .D(_0101_),
    .Q(net697),
    .CLK(clknet_leaf_13_clk_i));
 sg13g2_dfrbpq_1 _2971_ (.RESET_B(net1231),
    .D(_0100_),
    .Q(net698),
    .CLK(clknet_leaf_12_clk_i));
 sg13g2_dfrbpq_1 _2972_ (.RESET_B(net1230),
    .D(_0099_),
    .Q(net699),
    .CLK(clknet_leaf_11_clk_i));
 sg13g2_dfrbpq_1 _2973_ (.RESET_B(net1230),
    .D(_0098_),
    .Q(net700),
    .CLK(clknet_leaf_11_clk_i));
 sg13g2_dfrbpq_1 _2974_ (.RESET_B(net1229),
    .D(_0097_),
    .Q(net701),
    .CLK(clknet_leaf_9_clk_i));
 sg13g2_dfrbpq_1 _2975_ (.RESET_B(net1229),
    .D(_0096_),
    .Q(net702),
    .CLK(clknet_leaf_9_clk_i));
 sg13g2_dfrbpq_1 _2976_ (.RESET_B(net1229),
    .D(_0095_),
    .Q(net703),
    .CLK(clknet_leaf_11_clk_i));
 sg13g2_dfrbpq_1 _2977_ (.RESET_B(net1229),
    .D(_0094_),
    .Q(net704),
    .CLK(clknet_leaf_10_clk_i));
 sg13g2_dfrbpq_1 _2978_ (.RESET_B(net1230),
    .D(_0093_),
    .Q(net705),
    .CLK(clknet_leaf_10_clk_i));
 sg13g2_dfrbpq_1 _2979_ (.RESET_B(net1232),
    .D(_0092_),
    .Q(net706),
    .CLK(clknet_leaf_15_clk_i));
 sg13g2_dfrbpq_1 _2980_ (.RESET_B(net1232),
    .D(_0091_),
    .Q(net707),
    .CLK(clknet_leaf_15_clk_i));
 sg13g2_dfrbpq_1 _2981_ (.RESET_B(net1232),
    .D(_0090_),
    .Q(net708),
    .CLK(clknet_leaf_15_clk_i));
 sg13g2_dfrbpq_1 _2982_ (.RESET_B(net1232),
    .D(_0089_),
    .Q(net709),
    .CLK(clknet_leaf_15_clk_i));
 sg13g2_dfrbpq_1 _2983_ (.RESET_B(net1232),
    .D(net1308),
    .Q(net710),
    .CLK(clknet_leaf_15_clk_i));
 sg13g2_dfrbpq_1 _2984_ (.RESET_B(net1236),
    .D(_0087_),
    .Q(net711),
    .CLK(clknet_leaf_22_clk_i));
 sg13g2_dfrbpq_1 _2985_ (.RESET_B(net1236),
    .D(_0086_),
    .Q(net712),
    .CLK(clknet_leaf_22_clk_i));
 sg13g2_dfrbpq_1 _2986_ (.RESET_B(net1235),
    .D(_0085_),
    .Q(net713),
    .CLK(clknet_leaf_24_clk_i));
 sg13g2_dfrbpq_1 _2987_ (.RESET_B(net1233),
    .D(_0084_),
    .Q(net714),
    .CLK(clknet_leaf_24_clk_i));
 sg13g2_dfrbpq_1 _2988_ (.RESET_B(net1235),
    .D(_0083_),
    .Q(net715),
    .CLK(clknet_leaf_24_clk_i));
 sg13g2_dfrbpq_1 _2989_ (.RESET_B(net1235),
    .D(_0365_),
    .Q(net716),
    .CLK(clknet_leaf_22_clk_i));
 sg13g2_dfrbpq_1 _2990_ (.RESET_B(net1234),
    .D(_0082_),
    .Q(net717),
    .CLK(clknet_leaf_27_clk_i));
 sg13g2_dfrbpq_1 _2991_ (.RESET_B(net1234),
    .D(_0081_),
    .Q(net718),
    .CLK(clknet_leaf_26_clk_i));
 sg13g2_dfrbpq_1 _2992_ (.RESET_B(net1234),
    .D(_0080_),
    .Q(net719),
    .CLK(clknet_leaf_26_clk_i));
 sg13g2_dfrbpq_1 _2993_ (.RESET_B(net1234),
    .D(_0079_),
    .Q(net720),
    .CLK(clknet_leaf_26_clk_i));
 sg13g2_dfrbpq_1 _2994_ (.RESET_B(net1234),
    .D(_0078_),
    .Q(net721),
    .CLK(clknet_leaf_25_clk_i));
 sg13g2_dfrbpq_1 _2995_ (.RESET_B(net1234),
    .D(_0077_),
    .Q(net722),
    .CLK(clknet_leaf_26_clk_i));
 sg13g2_dfrbpq_1 _2996_ (.RESET_B(net1233),
    .D(_0076_),
    .Q(net723),
    .CLK(clknet_leaf_24_clk_i));
 sg13g2_dfrbpq_1 _2997_ (.RESET_B(net1235),
    .D(_0366_),
    .Q(net724),
    .CLK(clknet_leaf_24_clk_i));
 sg13g2_dfrbpq_1 _2998_ (.RESET_B(net1234),
    .D(_0075_),
    .Q(net725),
    .CLK(clknet_leaf_25_clk_i));
 sg13g2_dfrbpq_1 _2999_ (.RESET_B(net1234),
    .D(_0367_),
    .Q(net726),
    .CLK(clknet_leaf_25_clk_i));
 sg13g2_dfrbpq_1 _3000_ (.RESET_B(net1239),
    .D(_0368_),
    .Q(reg2hw_38_),
    .CLK(clknet_leaf_16_clk_i));
 sg13g2_dfrbpq_1 _3001_ (.RESET_B(reg_rst_ni),
    .D(_0074_),
    .Q(_0028_),
    .CLK(clknet_leaf_13_clk_i));
 sg13g2_dfrbpq_1 _3002_ (.RESET_B(reg_rst_ni),
    .D(_0073_),
    .Q(_0027_),
    .CLK(clknet_leaf_13_clk_i));
 sg13g2_dfrbpq_1 _3003_ (.RESET_B(net1231),
    .D(_0072_),
    .Q(_0026_),
    .CLK(clknet_leaf_12_clk_i));
 sg13g2_dfrbpq_1 _3004_ (.RESET_B(net1231),
    .D(_0071_),
    .Q(_0025_),
    .CLK(clknet_leaf_12_clk_i));
 sg13g2_dfrbpq_1 _3005_ (.RESET_B(reg_rst_ni),
    .D(_0070_),
    .Q(_0024_),
    .CLK(clknet_leaf_13_clk_i));
 sg13g2_dfrbpq_1 _3006_ (.RESET_B(net1231),
    .D(_0069_),
    .Q(_0023_),
    .CLK(clknet_leaf_15_clk_i));
 sg13g2_dfrbpq_1 _3007_ (.RESET_B(net1231),
    .D(_0068_),
    .Q(_0022_),
    .CLK(clknet_leaf_15_clk_i));
 sg13g2_dfrbpq_1 _3008_ (.RESET_B(net1239),
    .D(_0067_),
    .Q(reg2hw_48_),
    .CLK(clknet_leaf_15_clk_i));
 sg13g2_dfrbpq_1 _3009_ (.RESET_B(net1239),
    .D(_0066_),
    .Q(_0021_),
    .CLK(clknet_leaf_16_clk_i));
 sg13g2_dfrbpq_1 _3010_ (.RESET_B(net1239),
    .D(_0065_),
    .Q(_0020_),
    .CLK(clknet_leaf_16_clk_i));
 sg13g2_dfrbpq_1 _3011_ (.RESET_B(net1232),
    .D(_0064_),
    .Q(reg2hw_51_),
    .CLK(clknet_leaf_21_clk_i));
 sg13g2_dfrbpq_1 _3012_ (.RESET_B(net1232),
    .D(_0063_),
    .Q(_0019_),
    .CLK(clknet_leaf_21_clk_i));
 sg13g2_dfrbpq_1 _3013_ (.RESET_B(net1236),
    .D(_0062_),
    .Q(reg2hw_53_),
    .CLK(clknet_leaf_23_clk_i));
 sg13g2_dfrbpq_1 _3014_ (.RESET_B(net1236),
    .D(_0061_),
    .Q(reg2hw_54_),
    .CLK(clknet_leaf_22_clk_i));
 sg13g2_dfrbpq_1 _3015_ (.RESET_B(net1236),
    .D(_0060_),
    .Q(_0018_),
    .CLK(clknet_leaf_22_clk_i));
 sg13g2_dfrbpq_1 _3016_ (.RESET_B(net1236),
    .D(net1267),
    .Q(reg2hw_56_),
    .CLK(clknet_leaf_22_clk_i));
 sg13g2_dfrbpq_1 _3017_ (.RESET_B(net1237),
    .D(_0370_),
    .Q(reg2hw_36_),
    .CLK(clknet_leaf_16_clk_i));
 sg13g2_dfrbpq_1 _3018_ (.RESET_B(net1237),
    .D(_0371_),
    .Q(reg2hw_39_),
    .CLK(clknet_leaf_18_clk_i));
 sg13g2_dfrbpq_1 _3019_ (.RESET_B(net1239),
    .D(_0372_),
    .Q(reg2hw_40_),
    .CLK(clknet_leaf_21_clk_i));
 sg13g2_dfrbpq_1 _3020_ (.RESET_B(net1237),
    .D(_0373_),
    .Q(reg2hw_35_),
    .CLK(clknet_leaf_16_clk_i));
 sg13g2_dfrbpq_1 _3021_ (.RESET_B(net1237),
    .D(_0374_),
    .Q(reg2hw_37_),
    .CLK(clknet_leaf_16_clk_i));
 sg13g2_dfrbpq_1 _3022_ (.RESET_B(net1237),
    .D(_0375_),
    .Q(reg2hw_34_),
    .CLK(clknet_leaf_18_clk_i));
 sg13g2_dfrbpq_1 _3023_ (.RESET_B(net1237),
    .D(_0376_),
    .Q(reg2hw_1_),
    .CLK(clknet_leaf_19_clk_i));
 sg13g2_dfrbpq_1 _3024_ (.RESET_B(net1238),
    .D(_0377_),
    .Q(reg2hw_3_),
    .CLK(clknet_leaf_21_clk_i));
 sg13g2_dfrbpq_1 _3025_ (.RESET_B(net1238),
    .D(_0059_),
    .Q(reg2hw_5_),
    .CLK(clknet_leaf_20_clk_i));
 sg13g2_dfrbpq_1 _3026_ (.RESET_B(net1238),
    .D(_0058_),
    .Q(reg2hw_6_),
    .CLK(clknet_leaf_20_clk_i));
 sg13g2_dfrbpq_1 _3027_ (.RESET_B(net1233),
    .D(_0057_),
    .Q(reg2hw_7_),
    .CLK(clknet_leaf_24_clk_i));
 sg13g2_dfrbpq_1 _3028_ (.RESET_B(net1233),
    .D(_0056_),
    .Q(reg2hw_8_),
    .CLK(clknet_leaf_23_clk_i));
 sg13g2_dfrbpq_1 _3029_ (.RESET_B(net1233),
    .D(_0055_),
    .Q(reg2hw_9_),
    .CLK(clknet_leaf_27_clk_i));
 sg13g2_dfrbpq_1 _3030_ (.RESET_B(net1233),
    .D(_0054_),
    .Q(reg2hw_10_),
    .CLK(clknet_leaf_24_clk_i));
 sg13g2_dfrbpq_1 _3031_ (.RESET_B(net1238),
    .D(net1283),
    .Q(reg2hw_11_),
    .CLK(clknet_leaf_20_clk_i));
 sg13g2_dfrbpq_1 _3032_ (.RESET_B(net1233),
    .D(_0378_),
    .Q(reg2hw_12_),
    .CLK(clknet_leaf_23_clk_i));
 sg13g2_dfrbpq_1 _3033_ (.RESET_B(net1238),
    .D(net1145),
    .Q(reg2hw_4_),
    .CLK(clknet_leaf_20_clk_i));
 sg13g2_dfrbpq_1 _3034_ (.RESET_B(net1237),
    .D(net1314),
    .Q(reg2hw_0_),
    .CLK(clknet_leaf_18_clk_i));
 sg13g2_dfrbpq_1 _3035_ (.RESET_B(net1247),
    .D(_1473_),
    .Q(u_uart_core_uart_tx_tick_baud_q),
    .CLK(clknet_leaf_19_clk_i));
 sg13g2_dfrbpq_1 _3036_ (.RESET_B(net1241),
    .D(u_uart_core_uart_rx_tick_baud_d),
    .Q(u_uart_core_rx_tick_baud),
    .CLK(clknet_leaf_14_clk_i));
 sg13g2_dfrbpq_1 _3037_ (.RESET_B(net1243),
    .D(_0000_),
    .Q(u_uart_core_rx_valid),
    .CLK(clknet_leaf_6_clk_i));
 sg13g2_dfrbpq_1 _3038_ (.RESET_B(u_uart_core_tx_rst_ni),
    .D(net434),
    .Q(_0045_),
    .CLK(clknet_leaf_19_clk_i));
 sg13g2_tiehi _3038__22 (.L_HI(net434));
 sg13g2_dfrbpq_1 _3039_ (.RESET_B(net1240),
    .D(net435),
    .Q(_0044_),
    .CLK(clknet_leaf_17_clk_i));
 sg13g2_tiehi _3039__23 (.L_HI(net435));
 sg13g2_dfrbpq_1 _3040_ (.RESET_B(core_rst_ni),
    .D(net436),
    .Q(u_uart_core_tx_rst_ni),
    .CLK(clknet_leaf_14_clk_i));
 sg13g2_tiehi _3040__24 (.L_HI(net436));
 sg13g2_dfrbpq_1 _3041_ (.RESET_B(core_rst_ni),
    .D(net437),
    .Q(u_uart_core_timing_rst_ni),
    .CLK(clknet_leaf_13_clk_i));
 sg13g2_tiehi _3041__25 (.L_HI(net437));
 sg13g2_dfrbpq_1 _3042_ (.RESET_B(core_rst_ni),
    .D(net438),
    .Q(u_uart_core_rx_rst_ni),
    .CLK(clknet_leaf_10_clk_i));
 sg13g2_tiehi _3042__26 (.L_HI(net438));
 sg13g2_dfrbpq_1 _3043_ (.RESET_B(net1247),
    .D(_0052_),
    .Q(_0043_),
    .CLK(clknet_leaf_18_clk_i));
 sg13g2_dfrbpq_1 _3044_ (.RESET_B(net1240),
    .D(_0041_),
    .Q(_0042_),
    .CLK(clknet_leaf_17_clk_i));
 sg13g2_dfrbpq_1 _3045_ (.RESET_B(net1240),
    .D(_0050_),
    .Q(_0041_),
    .CLK(clknet_leaf_17_clk_i));
 sg13g2_dfrbpq_1 _3046_ (.RESET_B(net1240),
    .D(_0039_),
    .Q(_0040_),
    .CLK(clknet_leaf_17_clk_i));
 sg13g2_dfrbpq_1 _3047_ (.RESET_B(net1240),
    .D(_0042_),
    .Q(_0039_),
    .CLK(clknet_leaf_17_clk_i));
 sg13g2_dfrbpq_1 _3048_ (.RESET_B(net1245),
    .D(_0002_),
    .Q(u_uart_core_nco_sum_q_0_),
    .CLK(clknet_leaf_13_clk_i));
 sg13g2_dfrbpq_1 _3049_ (.RESET_B(net1245),
    .D(_0009_),
    .Q(u_uart_core_nco_sum_q_1_),
    .CLK(clknet_leaf_10_clk_i));
 sg13g2_dfrbpq_1 _3050_ (.RESET_B(net1245),
    .D(_0010_),
    .Q(u_uart_core_nco_sum_q_2_),
    .CLK(clknet_leaf_11_clk_i));
 sg13g2_dfrbpq_1 _3051_ (.RESET_B(net1245),
    .D(_0011_),
    .Q(u_uart_core_nco_sum_q_3_),
    .CLK(clknet_leaf_12_clk_i));
 sg13g2_dfrbpq_1 _3052_ (.RESET_B(net1245),
    .D(_0012_),
    .Q(u_uart_core_nco_sum_q_4_),
    .CLK(clknet_leaf_12_clk_i));
 sg13g2_dfrbpq_1 _3053_ (.RESET_B(net1245),
    .D(_0013_),
    .Q(u_uart_core_nco_sum_q_5_),
    .CLK(clknet_leaf_13_clk_i));
 sg13g2_dfrbpq_1 _3054_ (.RESET_B(net1245),
    .D(_0014_),
    .Q(u_uart_core_nco_sum_q_6_),
    .CLK(clknet_leaf_14_clk_i));
 sg13g2_dfrbpq_1 _3055_ (.RESET_B(net1245),
    .D(_0015_),
    .Q(u_uart_core_nco_sum_q_7_),
    .CLK(clknet_leaf_14_clk_i));
 sg13g2_dfrbpq_1 _3056_ (.RESET_B(u_uart_core_timing_rst_ni),
    .D(_0016_),
    .Q(u_uart_core_nco_sum_q_8_),
    .CLK(clknet_leaf_16_clk_i));
 sg13g2_dfrbpq_1 _3057_ (.RESET_B(net1246),
    .D(_0017_),
    .Q(u_uart_core_nco_sum_q_9_),
    .CLK(clknet_leaf_16_clk_i));
 sg13g2_dfrbpq_1 _3058_ (.RESET_B(net1246),
    .D(_0003_),
    .Q(u_uart_core_nco_sum_q_10_),
    .CLK(clknet_leaf_21_clk_i));
 sg13g2_dfrbpq_1 _3059_ (.RESET_B(net1246),
    .D(_0004_),
    .Q(u_uart_core_nco_sum_q_11_),
    .CLK(clknet_leaf_21_clk_i));
 sg13g2_dfrbpq_1 _3060_ (.RESET_B(net1246),
    .D(_0005_),
    .Q(u_uart_core_nco_sum_q_12_),
    .CLK(clknet_leaf_23_clk_i));
 sg13g2_dfrbpq_1 _3061_ (.RESET_B(net1246),
    .D(_0006_),
    .Q(u_uart_core_nco_sum_q_13_),
    .CLK(clknet_leaf_22_clk_i));
 sg13g2_dfrbpq_1 _3062_ (.RESET_B(net1246),
    .D(_0007_),
    .Q(u_uart_core_nco_sum_q_14_),
    .CLK(clknet_leaf_23_clk_i));
 sg13g2_dfrbpq_1 _3063_ (.RESET_B(net1246),
    .D(_0008_),
    .Q(u_uart_core_nco_sum_q_15_),
    .CLK(clknet_leaf_23_clk_i));
 sg13g2_dfrbpq_1 _3064_ (.RESET_B(net1246),
    .D(_0001_),
    .Q(u_uart_core_nco_sum_q_16_),
    .CLK(clknet_leaf_20_clk_i));
 sg13g2_dfrbpq_1 _3065_ (.RESET_B(net633),
    .D(u_reg_reset_sync_intq),
    .Q(reg_rst_ni),
    .CLK(clknet_leaf_12_clk_i));
 sg13g2_dfrbpq_1 _3066_ (.RESET_B(net633),
    .D(net439),
    .Q(u_reg_reset_sync_intq),
    .CLK(clknet_leaf_11_clk_i));
 sg13g2_tiehi _3066__27 (.L_HI(net439));
 sg13g2_dfrbpq_1 _3067_ (.RESET_B(net633),
    .D(u_core_reset_sync_intq),
    .Q(core_rst_ni),
    .CLK(clknet_leaf_12_clk_i));
 sg13g2_dfrbpq_1 _3068_ (.RESET_B(net633),
    .D(net440),
    .Q(u_core_reset_sync_intq),
    .CLK(clknet_leaf_12_clk_i));
 sg13g2_tiehi _3068__28 (.L_HI(net440));
 sg13g2_dfrbpq_1 _3069_ (.RESET_B(net441),
    .D(_0354_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_63_),
    .CLK(clknet_leaf_30_clk_i));
 sg13g2_tiehi _3069__29 (.L_HI(net441));
 sg13g2_dfrbpq_1 _3070_ (.RESET_B(net442),
    .D(_0353_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_55_),
    .CLK(clknet_leaf_30_clk_i));
 sg13g2_tiehi _3070__30 (.L_HI(net442));
 sg13g2_dfrbpq_1 _3071_ (.RESET_B(net443),
    .D(_0352_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_47_),
    .CLK(clknet_leaf_25_clk_i));
 sg13g2_tiehi _3071__31 (.L_HI(net443));
 sg13g2_dfrbpq_1 _3072_ (.RESET_B(net444),
    .D(_0351_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_39_),
    .CLK(clknet_leaf_27_clk_i));
 sg13g2_tiehi _3072__32 (.L_HI(net444));
 sg13g2_dfrbpq_1 _3073_ (.RESET_B(net445),
    .D(_0350_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_31_),
    .CLK(clknet_leaf_31_clk_i));
 sg13g2_tiehi _3073__33 (.L_HI(net445));
 sg13g2_dfrbpq_1 _3074_ (.RESET_B(net446),
    .D(_0349_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_23_),
    .CLK(clknet_leaf_31_clk_i));
 sg13g2_tiehi _3074__34 (.L_HI(net446));
 sg13g2_dfrbpq_1 _3075_ (.RESET_B(net447),
    .D(_0348_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_15_),
    .CLK(clknet_leaf_25_clk_i));
 sg13g2_tiehi _3075__35 (.L_HI(net447));
 sg13g2_dfrbpq_1 _3076_ (.RESET_B(net448),
    .D(_0347_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_7_),
    .CLK(clknet_leaf_23_clk_i));
 sg13g2_tiehi _3076__36 (.L_HI(net448));
 sg13g2_dfrbpq_1 _3077_ (.RESET_B(net449),
    .D(_0344_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_79_),
    .CLK(clknet_leaf_44_clk_i));
 sg13g2_tiehi _3077__37 (.L_HI(net449));
 sg13g2_dfrbpq_1 _3078_ (.RESET_B(net450),
    .D(_0343_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_71_),
    .CLK(clknet_leaf_42_clk_i));
 sg13g2_tiehi _3078__38 (.L_HI(net450));
 sg13g2_dfrbpq_1 _3079_ (.RESET_B(net451),
    .D(_0342_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_63_),
    .CLK(clknet_leaf_1_clk_i));
 sg13g2_tiehi _3079__39 (.L_HI(net451));
 sg13g2_dfrbpq_1 _3080_ (.RESET_B(net452),
    .D(_0341_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_55_),
    .CLK(clknet_leaf_0_clk_i));
 sg13g2_tiehi _3080__40 (.L_HI(net452));
 sg13g2_dfrbpq_1 _3081_ (.RESET_B(net453),
    .D(_0340_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_47_),
    .CLK(clknet_leaf_43_clk_i));
 sg13g2_tiehi _3081__41 (.L_HI(net453));
 sg13g2_dfrbpq_1 _3082_ (.RESET_B(net454),
    .D(_0339_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_39_),
    .CLK(clknet_leaf_44_clk_i));
 sg13g2_tiehi _3082__42 (.L_HI(net454));
 sg13g2_dfrbpq_1 _3083_ (.RESET_B(net455),
    .D(_0338_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_31_),
    .CLK(clknet_leaf_3_clk_i));
 sg13g2_tiehi _3083__43 (.L_HI(net455));
 sg13g2_dfrbpq_1 _3084_ (.RESET_B(net456),
    .D(_0337_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_23_),
    .CLK(clknet_leaf_3_clk_i));
 sg13g2_tiehi _3084__44 (.L_HI(net456));
 sg13g2_dfrbpq_1 _3085_ (.RESET_B(net457),
    .D(_0336_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_15_),
    .CLK(clknet_leaf_7_clk_i));
 sg13g2_tiehi _3085__45 (.L_HI(net457));
 sg13g2_dfrbpq_1 _3086_ (.RESET_B(net458),
    .D(_0335_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_127_),
    .CLK(clknet_leaf_3_clk_i));
 sg13g2_tiehi _3086__46 (.L_HI(net458));
 sg13g2_dfrbpq_1 _3087_ (.RESET_B(net459),
    .D(_0334_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_119_),
    .CLK(clknet_leaf_4_clk_i));
 sg13g2_tiehi _3087__47 (.L_HI(net459));
 sg13g2_dfrbpq_1 _3088_ (.RESET_B(net460),
    .D(_0333_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_111_),
    .CLK(clknet_leaf_44_clk_i));
 sg13g2_tiehi _3088__48 (.L_HI(net460));
 sg13g2_dfrbpq_1 _3089_ (.RESET_B(net461),
    .D(_0332_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_103_),
    .CLK(clknet_leaf_43_clk_i));
 sg13g2_tiehi _3089__49 (.L_HI(net461));
 sg13g2_dfrbpq_1 _3090_ (.RESET_B(net462),
    .D(_0331_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_95_),
    .CLK(clknet_leaf_43_clk_i));
 sg13g2_tiehi _3090__50 (.L_HI(net462));
 sg13g2_dfrbpq_1 _3091_ (.RESET_B(net463),
    .D(_0330_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_87_),
    .CLK(clknet_leaf_42_clk_i));
 sg13g2_tiehi _3091__51 (.L_HI(net463));
 sg13g2_dfrbpq_1 _3092_ (.RESET_B(net464),
    .D(_0329_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_7_),
    .CLK(clknet_leaf_7_clk_i));
 sg13g2_tiehi _3092__52 (.L_HI(net464));
 sg13g2_dfrbpq_1 _3093_ (.RESET_B(net465),
    .D(_0312_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_0_),
    .CLK(clknet_leaf_3_clk_i));
 sg13g2_tiehi _3093__53 (.L_HI(net465));
 sg13g2_dfrbpq_1 _3094_ (.RESET_B(net466),
    .D(_0311_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_1_),
    .CLK(clknet_leaf_7_clk_i));
 sg13g2_tiehi _3094__54 (.L_HI(net466));
 sg13g2_dfrbpq_1 _3095_ (.RESET_B(net467),
    .D(_0310_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_2_),
    .CLK(clknet_leaf_3_clk_i));
 sg13g2_tiehi _3095__55 (.L_HI(net467));
 sg13g2_dfrbpq_1 _3096_ (.RESET_B(net468),
    .D(_0309_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_3_),
    .CLK(clknet_leaf_3_clk_i));
 sg13g2_tiehi _3096__56 (.L_HI(net468));
 sg13g2_dfrbpq_1 _3097_ (.RESET_B(net469),
    .D(_0308_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_4_),
    .CLK(clknet_leaf_8_clk_i));
 sg13g2_tiehi _3097__57 (.L_HI(net469));
 sg13g2_dfrbpq_1 _3098_ (.RESET_B(net470),
    .D(_0307_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_5_),
    .CLK(clknet_leaf_7_clk_i));
 sg13g2_tiehi _3098__58 (.L_HI(net470));
 sg13g2_dfrbpq_1 _3099_ (.RESET_B(net471),
    .D(_0306_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_6_),
    .CLK(clknet_leaf_8_clk_i));
 sg13g2_tiehi _3099__59 (.L_HI(net471));
 sg13g2_dfrbpq_1 _3100_ (.RESET_B(net472),
    .D(_0305_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_80_),
    .CLK(clknet_leaf_36_clk_i));
 sg13g2_tiehi _3100__60 (.L_HI(net472));
 sg13g2_dfrbpq_1 _3101_ (.RESET_B(net473),
    .D(_0304_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_81_),
    .CLK(clknet_leaf_36_clk_i));
 sg13g2_tiehi _3101__61 (.L_HI(net473));
 sg13g2_dfrbpq_1 _3102_ (.RESET_B(net474),
    .D(_0303_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_82_),
    .CLK(clknet_leaf_41_clk_i));
 sg13g2_tiehi _3102__62 (.L_HI(net474));
 sg13g2_dfrbpq_1 _3103_ (.RESET_B(net475),
    .D(_0302_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_83_),
    .CLK(clknet_leaf_42_clk_i));
 sg13g2_tiehi _3103__63 (.L_HI(net475));
 sg13g2_dfrbpq_1 _3104_ (.RESET_B(net476),
    .D(_0301_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_84_),
    .CLK(clknet_leaf_42_clk_i));
 sg13g2_tiehi _3104__64 (.L_HI(net476));
 sg13g2_dfrbpq_1 _3105_ (.RESET_B(net477),
    .D(_0300_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_85_),
    .CLK(clknet_leaf_40_clk_i));
 sg13g2_tiehi _3105__65 (.L_HI(net477));
 sg13g2_dfrbpq_1 _3106_ (.RESET_B(net478),
    .D(_0299_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_86_),
    .CLK(clknet_leaf_43_clk_i));
 sg13g2_tiehi _3106__66 (.L_HI(net478));
 sg13g2_dfrbpq_1 _3107_ (.RESET_B(net479),
    .D(_0298_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_88_),
    .CLK(clknet_leaf_37_clk_i));
 sg13g2_tiehi _3107__67 (.L_HI(net479));
 sg13g2_dfrbpq_1 _3108_ (.RESET_B(net480),
    .D(_0297_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_89_),
    .CLK(clknet_leaf_36_clk_i));
 sg13g2_tiehi _3108__68 (.L_HI(net480));
 sg13g2_dfrbpq_1 _3109_ (.RESET_B(net481),
    .D(_0296_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_90_),
    .CLK(clknet_leaf_41_clk_i));
 sg13g2_tiehi _3109__69 (.L_HI(net481));
 sg13g2_dfrbpq_1 _3110_ (.RESET_B(net482),
    .D(_0295_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_91_),
    .CLK(clknet_leaf_41_clk_i));
 sg13g2_tiehi _3110__70 (.L_HI(net482));
 sg13g2_dfrbpq_1 _3111_ (.RESET_B(net483),
    .D(_0294_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_92_),
    .CLK(clknet_leaf_42_clk_i));
 sg13g2_tiehi _3111__71 (.L_HI(net483));
 sg13g2_dfrbpq_1 _3112_ (.RESET_B(net484),
    .D(_0293_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_93_),
    .CLK(clknet_leaf_40_clk_i));
 sg13g2_tiehi _3112__72 (.L_HI(net484));
 sg13g2_dfrbpq_1 _3113_ (.RESET_B(net485),
    .D(_0292_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_94_),
    .CLK(clknet_leaf_43_clk_i));
 sg13g2_tiehi _3113__73 (.L_HI(net485));
 sg13g2_dfrbpq_1 _3114_ (.RESET_B(net486),
    .D(_0291_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_96_),
    .CLK(clknet_leaf_37_clk_i));
 sg13g2_tiehi _3114__74 (.L_HI(net486));
 sg13g2_dfrbpq_1 _3115_ (.RESET_B(net487),
    .D(_0290_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_97_),
    .CLK(clknet_leaf_37_clk_i));
 sg13g2_tiehi _3115__75 (.L_HI(net487));
 sg13g2_dfrbpq_1 _3116_ (.RESET_B(net488),
    .D(_0289_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_98_),
    .CLK(clknet_leaf_36_clk_i));
 sg13g2_tiehi _3116__76 (.L_HI(net488));
 sg13g2_dfrbpq_1 _3117_ (.RESET_B(net489),
    .D(_0288_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_99_),
    .CLK(clknet_leaf_37_clk_i));
 sg13g2_tiehi _3117__77 (.L_HI(net489));
 sg13g2_dfrbpq_1 _3118_ (.RESET_B(net490),
    .D(_0287_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_100_),
    .CLK(clknet_leaf_44_clk_i));
 sg13g2_tiehi _3118__78 (.L_HI(net490));
 sg13g2_dfrbpq_1 _3119_ (.RESET_B(net491),
    .D(_0286_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_101_),
    .CLK(clknet_leaf_0_clk_i));
 sg13g2_tiehi _3119__79 (.L_HI(net491));
 sg13g2_dfrbpq_1 _3120_ (.RESET_B(net492),
    .D(_0285_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_102_),
    .CLK(clknet_leaf_45_clk_i));
 sg13g2_tiehi _3120__80 (.L_HI(net492));
 sg13g2_dfrbpq_1 _3121_ (.RESET_B(net493),
    .D(_0284_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_104_),
    .CLK(clknet_leaf_37_clk_i));
 sg13g2_tiehi _3121__81 (.L_HI(net493));
 sg13g2_dfrbpq_1 _3122_ (.RESET_B(net494),
    .D(_0283_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_105_),
    .CLK(clknet_leaf_39_clk_i));
 sg13g2_tiehi _3122__82 (.L_HI(net494));
 sg13g2_dfrbpq_1 _3123_ (.RESET_B(net495),
    .D(_0282_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_106_),
    .CLK(clknet_leaf_37_clk_i));
 sg13g2_tiehi _3123__83 (.L_HI(net495));
 sg13g2_dfrbpq_1 _3124_ (.RESET_B(net496),
    .D(_0281_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_107_),
    .CLK(clknet_leaf_38_clk_i));
 sg13g2_tiehi _3124__84 (.L_HI(net496));
 sg13g2_dfrbpq_1 _3125_ (.RESET_B(net497),
    .D(_0280_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_108_),
    .CLK(clknet_leaf_44_clk_i));
 sg13g2_tiehi _3125__85 (.L_HI(net497));
 sg13g2_dfrbpq_1 _3126_ (.RESET_B(net498),
    .D(_0279_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_109_),
    .CLK(clknet_leaf_0_clk_i));
 sg13g2_tiehi _3126__86 (.L_HI(net498));
 sg13g2_dfrbpq_1 _3127_ (.RESET_B(net499),
    .D(_0278_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_110_),
    .CLK(clknet_leaf_44_clk_i));
 sg13g2_tiehi _3127__87 (.L_HI(net499));
 sg13g2_dfrbpq_1 _3128_ (.RESET_B(net500),
    .D(_0277_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_112_),
    .CLK(clknet_leaf_38_clk_i));
 sg13g2_tiehi _3128__88 (.L_HI(net500));
 sg13g2_dfrbpq_1 _3129_ (.RESET_B(net501),
    .D(_0276_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_113_),
    .CLK(clknet_leaf_39_clk_i));
 sg13g2_tiehi _3129__89 (.L_HI(net501));
 sg13g2_dfrbpq_1 _3130_ (.RESET_B(net502),
    .D(_0275_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_114_),
    .CLK(clknet_leaf_38_clk_i));
 sg13g2_tiehi _3130__90 (.L_HI(net502));
 sg13g2_dfrbpq_1 _3131_ (.RESET_B(net503),
    .D(_0274_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_115_),
    .CLK(clknet_leaf_38_clk_i));
 sg13g2_tiehi _3131__91 (.L_HI(net503));
 sg13g2_dfrbpq_1 _3132_ (.RESET_B(net504),
    .D(_0273_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_116_),
    .CLK(clknet_leaf_1_clk_i));
 sg13g2_tiehi _3132__92 (.L_HI(net504));
 sg13g2_dfrbpq_1 _3133_ (.RESET_B(net505),
    .D(_0272_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_117_),
    .CLK(clknet_leaf_1_clk_i));
 sg13g2_tiehi _3133__93 (.L_HI(net505));
 sg13g2_dfrbpq_1 _3134_ (.RESET_B(net506),
    .D(_0271_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_118_),
    .CLK(clknet_leaf_2_clk_i));
 sg13g2_tiehi _3134__94 (.L_HI(net506));
 sg13g2_dfrbpq_1 _3135_ (.RESET_B(net507),
    .D(_0270_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_120_),
    .CLK(clknet_leaf_38_clk_i));
 sg13g2_tiehi _3135__95 (.L_HI(net507));
 sg13g2_dfrbpq_1 _3136_ (.RESET_B(net508),
    .D(_0269_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_121_),
    .CLK(clknet_leaf_38_clk_i));
 sg13g2_tiehi _3136__96 (.L_HI(net508));
 sg13g2_dfrbpq_1 _3137_ (.RESET_B(net509),
    .D(_0268_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_122_),
    .CLK(clknet_leaf_38_clk_i));
 sg13g2_tiehi _3137__97 (.L_HI(net509));
 sg13g2_dfrbpq_1 _3138_ (.RESET_B(net510),
    .D(_0267_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_123_),
    .CLK(clknet_leaf_38_clk_i));
 sg13g2_tiehi _3138__98 (.L_HI(net510));
 sg13g2_dfrbpq_1 _3139_ (.RESET_B(net511),
    .D(_0266_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_124_),
    .CLK(clknet_leaf_1_clk_i));
 sg13g2_tiehi _3139__99 (.L_HI(net511));
 sg13g2_dfrbpq_1 _3140_ (.RESET_B(net512),
    .D(_0265_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_125_),
    .CLK(clknet_leaf_1_clk_i));
 sg13g2_tiehi _3140__100 (.L_HI(net512));
 sg13g2_dfrbpq_1 _3141_ (.RESET_B(net513),
    .D(_0264_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_126_),
    .CLK(clknet_leaf_2_clk_i));
 sg13g2_tiehi _3141__101 (.L_HI(net513));
 sg13g2_dfrbpq_1 _3142_ (.RESET_B(net514),
    .D(_0263_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_8_),
    .CLK(clknet_leaf_7_clk_i));
 sg13g2_tiehi _3142__102 (.L_HI(net514));
 sg13g2_dfrbpq_1 _3143_ (.RESET_B(net515),
    .D(_0262_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_9_),
    .CLK(clknet_leaf_7_clk_i));
 sg13g2_tiehi _3143__103 (.L_HI(net515));
 sg13g2_dfrbpq_1 _3144_ (.RESET_B(net516),
    .D(_0261_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_10_),
    .CLK(clknet_leaf_3_clk_i));
 sg13g2_tiehi _3144__104 (.L_HI(net516));
 sg13g2_dfrbpq_1 _3145_ (.RESET_B(net517),
    .D(_0260_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_11_),
    .CLK(clknet_leaf_3_clk_i));
 sg13g2_tiehi _3145__105 (.L_HI(net517));
 sg13g2_dfrbpq_1 _3146_ (.RESET_B(net518),
    .D(_0259_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_12_),
    .CLK(clknet_leaf_8_clk_i));
 sg13g2_tiehi _3146__106 (.L_HI(net518));
 sg13g2_dfrbpq_1 _3147_ (.RESET_B(net519),
    .D(_0258_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_13_),
    .CLK(clknet_leaf_8_clk_i));
 sg13g2_tiehi _3147__107 (.L_HI(net519));
 sg13g2_dfrbpq_1 _3148_ (.RESET_B(net520),
    .D(_0257_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_14_),
    .CLK(clknet_leaf_8_clk_i));
 sg13g2_tiehi _3148__108 (.L_HI(net520));
 sg13g2_dfrbpq_1 _3149_ (.RESET_B(net521),
    .D(_0256_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_16_),
    .CLK(clknet_leaf_4_clk_i));
 sg13g2_tiehi _3149__109 (.L_HI(net521));
 sg13g2_dfrbpq_1 _3150_ (.RESET_B(net522),
    .D(_0255_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_17_),
    .CLK(clknet_leaf_4_clk_i));
 sg13g2_tiehi _3150__110 (.L_HI(net522));
 sg13g2_dfrbpq_1 _3151_ (.RESET_B(net523),
    .D(_0254_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_18_),
    .CLK(clknet_leaf_39_clk_i));
 sg13g2_tiehi _3151__111 (.L_HI(net523));
 sg13g2_dfrbpq_1 _3152_ (.RESET_B(net524),
    .D(_0253_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_19_),
    .CLK(clknet_leaf_4_clk_i));
 sg13g2_tiehi _3152__112 (.L_HI(net524));
 sg13g2_dfrbpq_1 _3153_ (.RESET_B(net525),
    .D(_0252_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_20_),
    .CLK(clknet_leaf_2_clk_i));
 sg13g2_tiehi _3153__113 (.L_HI(net525));
 sg13g2_dfrbpq_1 _3154_ (.RESET_B(net526),
    .D(_0251_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_21_),
    .CLK(clknet_leaf_2_clk_i));
 sg13g2_tiehi _3154__114 (.L_HI(net526));
 sg13g2_dfrbpq_1 _3155_ (.RESET_B(net527),
    .D(_0250_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_22_),
    .CLK(clknet_leaf_2_clk_i));
 sg13g2_tiehi _3155__115 (.L_HI(net527));
 sg13g2_dfrbpq_1 _3156_ (.RESET_B(net528),
    .D(_0249_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_24_),
    .CLK(clknet_leaf_4_clk_i));
 sg13g2_tiehi _3156__116 (.L_HI(net528));
 sg13g2_dfrbpq_1 _3157_ (.RESET_B(net529),
    .D(_0248_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_25_),
    .CLK(clknet_leaf_4_clk_i));
 sg13g2_tiehi _3157__117 (.L_HI(net529));
 sg13g2_dfrbpq_1 _3158_ (.RESET_B(net530),
    .D(_0247_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_26_),
    .CLK(clknet_leaf_4_clk_i));
 sg13g2_tiehi _3158__118 (.L_HI(net530));
 sg13g2_dfrbpq_1 _3159_ (.RESET_B(net531),
    .D(_0246_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_27_),
    .CLK(clknet_leaf_4_clk_i));
 sg13g2_tiehi _3159__119 (.L_HI(net531));
 sg13g2_dfrbpq_1 _3160_ (.RESET_B(net532),
    .D(_0245_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_28_),
    .CLK(clknet_leaf_2_clk_i));
 sg13g2_tiehi _3160__120 (.L_HI(net532));
 sg13g2_dfrbpq_1 _3161_ (.RESET_B(net533),
    .D(_0244_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_29_),
    .CLK(clknet_leaf_2_clk_i));
 sg13g2_tiehi _3161__121 (.L_HI(net533));
 sg13g2_dfrbpq_1 _3162_ (.RESET_B(net534),
    .D(_0243_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_30_),
    .CLK(clknet_leaf_2_clk_i));
 sg13g2_tiehi _3162__122 (.L_HI(net534));
 sg13g2_dfrbpq_1 _3163_ (.RESET_B(net535),
    .D(_0242_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_32_),
    .CLK(clknet_leaf_40_clk_i));
 sg13g2_tiehi _3163__123 (.L_HI(net535));
 sg13g2_dfrbpq_1 _3164_ (.RESET_B(net536),
    .D(_0241_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_33_),
    .CLK(clknet_leaf_39_clk_i));
 sg13g2_tiehi _3164__124 (.L_HI(net536));
 sg13g2_dfrbpq_1 _3165_ (.RESET_B(net537),
    .D(_0240_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_34_),
    .CLK(clknet_leaf_41_clk_i));
 sg13g2_tiehi _3165__125 (.L_HI(net537));
 sg13g2_dfrbpq_1 _3166_ (.RESET_B(net538),
    .D(_0239_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_35_),
    .CLK(clknet_leaf_40_clk_i));
 sg13g2_tiehi _3166__126 (.L_HI(net538));
 sg13g2_dfrbpq_1 _3167_ (.RESET_B(net539),
    .D(_0238_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_36_),
    .CLK(clknet_leaf_45_clk_i));
 sg13g2_tiehi _3167__127 (.L_HI(net539));
 sg13g2_dfrbpq_1 _3168_ (.RESET_B(net540),
    .D(_0237_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_37_),
    .CLK(clknet_leaf_0_clk_i));
 sg13g2_tiehi _3168__128 (.L_HI(net540));
 sg13g2_dfrbpq_1 _3169_ (.RESET_B(net541),
    .D(_0236_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_38_),
    .CLK(clknet_leaf_44_clk_i));
 sg13g2_tiehi _3169__129 (.L_HI(net541));
 sg13g2_dfrbpq_1 _3170_ (.RESET_B(net542),
    .D(_0235_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_40_),
    .CLK(clknet_leaf_39_clk_i));
 sg13g2_tiehi _3170__130 (.L_HI(net542));
 sg13g2_dfrbpq_1 _3171_ (.RESET_B(net543),
    .D(_0234_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_41_),
    .CLK(clknet_leaf_40_clk_i));
 sg13g2_tiehi _3171__131 (.L_HI(net543));
 sg13g2_dfrbpq_1 _3172_ (.RESET_B(net544),
    .D(_0233_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_42_),
    .CLK(clknet_leaf_41_clk_i));
 sg13g2_tiehi _3172__132 (.L_HI(net544));
 sg13g2_dfrbpq_1 _3173_ (.RESET_B(net545),
    .D(_0232_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_43_),
    .CLK(clknet_leaf_40_clk_i));
 sg13g2_tiehi _3173__133 (.L_HI(net545));
 sg13g2_dfrbpq_1 _3174_ (.RESET_B(net546),
    .D(_0231_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_44_),
    .CLK(clknet_leaf_45_clk_i));
 sg13g2_tiehi _3174__134 (.L_HI(net546));
 sg13g2_dfrbpq_1 _3175_ (.RESET_B(net547),
    .D(_0230_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_45_),
    .CLK(clknet_leaf_0_clk_i));
 sg13g2_tiehi _3175__135 (.L_HI(net547));
 sg13g2_dfrbpq_1 _3176_ (.RESET_B(net548),
    .D(_0229_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_46_),
    .CLK(clknet_leaf_44_clk_i));
 sg13g2_tiehi _3176__136 (.L_HI(net548));
 sg13g2_dfrbpq_1 _3177_ (.RESET_B(net549),
    .D(_0228_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_48_),
    .CLK(clknet_leaf_37_clk_i));
 sg13g2_tiehi _3177__137 (.L_HI(net549));
 sg13g2_dfrbpq_1 _3178_ (.RESET_B(net550),
    .D(_0227_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_49_),
    .CLK(clknet_leaf_39_clk_i));
 sg13g2_tiehi _3178__138 (.L_HI(net550));
 sg13g2_dfrbpq_1 _3179_ (.RESET_B(net551),
    .D(_0226_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_50_),
    .CLK(clknet_leaf_32_clk_i));
 sg13g2_tiehi _3179__139 (.L_HI(net551));
 sg13g2_dfrbpq_1 _3180_ (.RESET_B(net552),
    .D(_0225_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_51_),
    .CLK(clknet_leaf_39_clk_i));
 sg13g2_tiehi _3180__140 (.L_HI(net552));
 sg13g2_dfrbpq_1 _3181_ (.RESET_B(net553),
    .D(_0224_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_52_),
    .CLK(clknet_leaf_1_clk_i));
 sg13g2_tiehi _3181__141 (.L_HI(net553));
 sg13g2_dfrbpq_1 _3182_ (.RESET_B(net554),
    .D(_0223_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_53_),
    .CLK(clknet_leaf_0_clk_i));
 sg13g2_tiehi _3182__142 (.L_HI(net554));
 sg13g2_dfrbpq_1 _3183_ (.RESET_B(net555),
    .D(_0222_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_54_),
    .CLK(clknet_leaf_1_clk_i));
 sg13g2_tiehi _3183__143 (.L_HI(net555));
 sg13g2_dfrbpq_1 _3184_ (.RESET_B(net556),
    .D(_0221_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_56_),
    .CLK(clknet_leaf_37_clk_i));
 sg13g2_tiehi _3184__144 (.L_HI(net556));
 sg13g2_dfrbpq_1 _3185_ (.RESET_B(net557),
    .D(_0220_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_57_),
    .CLK(clknet_leaf_40_clk_i));
 sg13g2_tiehi _3185__145 (.L_HI(net557));
 sg13g2_dfrbpq_1 _3186_ (.RESET_B(net558),
    .D(_0219_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_58_),
    .CLK(clknet_leaf_33_clk_i));
 sg13g2_tiehi _3186__146 (.L_HI(net558));
 sg13g2_dfrbpq_1 _3187_ (.RESET_B(net559),
    .D(_0218_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_59_),
    .CLK(clknet_leaf_39_clk_i));
 sg13g2_tiehi _3187__147 (.L_HI(net559));
 sg13g2_dfrbpq_1 _3188_ (.RESET_B(net560),
    .D(_0217_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_60_),
    .CLK(clknet_leaf_0_clk_i));
 sg13g2_tiehi _3188__148 (.L_HI(net560));
 sg13g2_dfrbpq_1 _3189_ (.RESET_B(net561),
    .D(_0216_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_61_),
    .CLK(clknet_leaf_0_clk_i));
 sg13g2_tiehi _3189__149 (.L_HI(net561));
 sg13g2_dfrbpq_1 _3190_ (.RESET_B(net562),
    .D(_0215_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_62_),
    .CLK(clknet_leaf_1_clk_i));
 sg13g2_tiehi _3190__150 (.L_HI(net562));
 sg13g2_dfrbpq_1 _3191_ (.RESET_B(net563),
    .D(_0214_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_64_),
    .CLK(clknet_leaf_36_clk_i));
 sg13g2_tiehi _3191__151 (.L_HI(net563));
 sg13g2_dfrbpq_1 _3192_ (.RESET_B(net564),
    .D(_0213_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_65_),
    .CLK(clknet_leaf_36_clk_i));
 sg13g2_tiehi _3192__152 (.L_HI(net564));
 sg13g2_dfrbpq_1 _3193_ (.RESET_B(net565),
    .D(_0212_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_66_),
    .CLK(clknet_leaf_41_clk_i));
 sg13g2_tiehi _3193__153 (.L_HI(net565));
 sg13g2_dfrbpq_1 _3194_ (.RESET_B(net566),
    .D(_0211_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_67_),
    .CLK(clknet_leaf_41_clk_i));
 sg13g2_tiehi _3194__154 (.L_HI(net566));
 sg13g2_dfrbpq_1 _3195_ (.RESET_B(net567),
    .D(_0210_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_68_),
    .CLK(clknet_leaf_42_clk_i));
 sg13g2_tiehi _3195__155 (.L_HI(net567));
 sg13g2_dfrbpq_1 _3196_ (.RESET_B(net568),
    .D(_0209_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_69_),
    .CLK(clknet_leaf_43_clk_i));
 sg13g2_tiehi _3196__156 (.L_HI(net568));
 sg13g2_dfrbpq_1 _3197_ (.RESET_B(net569),
    .D(_0208_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_70_),
    .CLK(clknet_leaf_43_clk_i));
 sg13g2_tiehi _3197__157 (.L_HI(net569));
 sg13g2_dfrbpq_1 _3198_ (.RESET_B(net570),
    .D(_0207_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_72_),
    .CLK(clknet_leaf_36_clk_i));
 sg13g2_tiehi _3198__158 (.L_HI(net570));
 sg13g2_dfrbpq_1 _3199_ (.RESET_B(net571),
    .D(_0206_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_73_),
    .CLK(clknet_leaf_36_clk_i));
 sg13g2_tiehi _3199__159 (.L_HI(net571));
 sg13g2_dfrbpq_1 _3200_ (.RESET_B(net572),
    .D(_0205_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_74_),
    .CLK(clknet_leaf_41_clk_i));
 sg13g2_tiehi _3200__160 (.L_HI(net572));
 sg13g2_dfrbpq_1 _3201_ (.RESET_B(net573),
    .D(_0204_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_75_),
    .CLK(clknet_leaf_42_clk_i));
 sg13g2_tiehi _3201__161 (.L_HI(net573));
 sg13g2_dfrbpq_1 _3202_ (.RESET_B(net574),
    .D(_0203_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_76_),
    .CLK(clknet_leaf_42_clk_i));
 sg13g2_tiehi _3202__162 (.L_HI(net574));
 sg13g2_dfrbpq_1 _3203_ (.RESET_B(net575),
    .D(_0202_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_77_),
    .CLK(clknet_leaf_43_clk_i));
 sg13g2_tiehi _3203__163 (.L_HI(net575));
 sg13g2_dfrbpq_1 _3204_ (.RESET_B(net576),
    .D(_0201_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_78_),
    .CLK(clknet_leaf_40_clk_i));
 sg13g2_tiehi _3204__164 (.L_HI(net576));
 sg13g2_dfrbpq_1 _3205_ (.RESET_B(net577),
    .D(_0193_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_0_),
    .CLK(clknet_leaf_30_clk_i));
 sg13g2_tiehi _3205__165 (.L_HI(net577));
 sg13g2_dfrbpq_1 _3206_ (.RESET_B(net578),
    .D(_0192_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_1_),
    .CLK(clknet_leaf_28_clk_i));
 sg13g2_tiehi _3206__166 (.L_HI(net578));
 sg13g2_dfrbpq_1 _3207_ (.RESET_B(net579),
    .D(_0191_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_2_),
    .CLK(clknet_leaf_25_clk_i));
 sg13g2_tiehi _3207__167 (.L_HI(net579));
 sg13g2_dfrbpq_1 _3208_ (.RESET_B(net580),
    .D(_0190_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_3_),
    .CLK(clknet_leaf_29_clk_i));
 sg13g2_tiehi _3208__168 (.L_HI(net580));
 sg13g2_dfrbpq_1 _3209_ (.RESET_B(net581),
    .D(_0189_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_4_),
    .CLK(clknet_leaf_28_clk_i));
 sg13g2_tiehi _3209__169 (.L_HI(net581));
 sg13g2_dfrbpq_1 _3210_ (.RESET_B(net582),
    .D(_0188_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_5_),
    .CLK(clknet_leaf_24_clk_i));
 sg13g2_tiehi _3210__170 (.L_HI(net582));
 sg13g2_dfrbpq_1 _3211_ (.RESET_B(net583),
    .D(_0187_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_6_),
    .CLK(clknet_leaf_28_clk_i));
 sg13g2_tiehi _3211__171 (.L_HI(net583));
 sg13g2_dfrbpq_1 _3212_ (.RESET_B(net584),
    .D(_0186_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_8_),
    .CLK(clknet_leaf_30_clk_i));
 sg13g2_tiehi _3212__172 (.L_HI(net584));
 sg13g2_dfrbpq_1 _3213_ (.RESET_B(net585),
    .D(_0185_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_9_),
    .CLK(clknet_leaf_28_clk_i));
 sg13g2_tiehi _3213__173 (.L_HI(net585));
 sg13g2_dfrbpq_1 _3214_ (.RESET_B(net586),
    .D(_0184_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_10_),
    .CLK(clknet_leaf_26_clk_i));
 sg13g2_tiehi _3214__174 (.L_HI(net586));
 sg13g2_dfrbpq_1 _3215_ (.RESET_B(net587),
    .D(_0183_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_11_),
    .CLK(clknet_leaf_28_clk_i));
 sg13g2_tiehi _3215__175 (.L_HI(net587));
 sg13g2_dfrbpq_1 _3216_ (.RESET_B(net588),
    .D(_0182_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_12_),
    .CLK(clknet_leaf_26_clk_i));
 sg13g2_tiehi _3216__176 (.L_HI(net588));
 sg13g2_dfrbpq_1 _3217_ (.RESET_B(net589),
    .D(_0181_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_13_),
    .CLK(clknet_leaf_25_clk_i));
 sg13g2_tiehi _3217__177 (.L_HI(net589));
 sg13g2_dfrbpq_1 _3218_ (.RESET_B(net590),
    .D(_0180_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_14_),
    .CLK(clknet_leaf_28_clk_i));
 sg13g2_tiehi _3218__178 (.L_HI(net590));
 sg13g2_dfrbpq_1 _3219_ (.RESET_B(net591),
    .D(_0179_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_16_),
    .CLK(clknet_leaf_33_clk_i));
 sg13g2_tiehi _3219__179 (.L_HI(net591));
 sg13g2_dfrbpq_1 _3220_ (.RESET_B(net592),
    .D(_0178_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_17_),
    .CLK(clknet_leaf_29_clk_i));
 sg13g2_tiehi _3220__180 (.L_HI(net592));
 sg13g2_dfrbpq_1 _3221_ (.RESET_B(net593),
    .D(_0177_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_18_),
    .CLK(clknet_leaf_34_clk_i));
 sg13g2_tiehi _3221__181 (.L_HI(net593));
 sg13g2_dfrbpq_1 _3222_ (.RESET_B(net594),
    .D(_0176_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_19_),
    .CLK(clknet_leaf_35_clk_i));
 sg13g2_tiehi _3222__182 (.L_HI(net594));
 sg13g2_dfrbpq_1 _3223_ (.RESET_B(net595),
    .D(_0175_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_20_),
    .CLK(clknet_leaf_35_clk_i));
 sg13g2_tiehi _3223__183 (.L_HI(net595));
 sg13g2_dfrbpq_1 _3224_ (.RESET_B(net596),
    .D(_0174_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_21_),
    .CLK(clknet_leaf_34_clk_i));
 sg13g2_tiehi _3224__184 (.L_HI(net596));
 sg13g2_dfrbpq_1 _3225_ (.RESET_B(net597),
    .D(_0173_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_22_),
    .CLK(clknet_leaf_35_clk_i));
 sg13g2_tiehi _3225__185 (.L_HI(net597));
 sg13g2_dfrbpq_1 _3226_ (.RESET_B(net598),
    .D(_0172_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_24_),
    .CLK(clknet_leaf_31_clk_i));
 sg13g2_tiehi _3226__186 (.L_HI(net598));
 sg13g2_dfrbpq_1 _3227_ (.RESET_B(net599),
    .D(_0171_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_25_),
    .CLK(clknet_leaf_29_clk_i));
 sg13g2_tiehi _3227__187 (.L_HI(net599));
 sg13g2_dfrbpq_1 _3228_ (.RESET_B(net600),
    .D(_0170_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_26_),
    .CLK(clknet_leaf_29_clk_i));
 sg13g2_tiehi _3228__188 (.L_HI(net600));
 sg13g2_dfrbpq_1 _3229_ (.RESET_B(net601),
    .D(_0169_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_27_),
    .CLK(clknet_leaf_29_clk_i));
 sg13g2_tiehi _3229__189 (.L_HI(net601));
 sg13g2_dfrbpq_1 _3230_ (.RESET_B(net602),
    .D(_0168_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_28_),
    .CLK(clknet_leaf_29_clk_i));
 sg13g2_tiehi _3230__190 (.L_HI(net602));
 sg13g2_dfrbpq_1 _3231_ (.RESET_B(net603),
    .D(_0167_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_29_),
    .CLK(clknet_leaf_33_clk_i));
 sg13g2_tiehi _3231__191 (.L_HI(net603));
 sg13g2_dfrbpq_1 _3232_ (.RESET_B(net604),
    .D(_0166_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_30_),
    .CLK(clknet_leaf_29_clk_i));
 sg13g2_tiehi _3232__192 (.L_HI(net604));
 sg13g2_dfrbpq_1 _3233_ (.RESET_B(net605),
    .D(_0165_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_32_),
    .CLK(clknet_leaf_30_clk_i));
 sg13g2_tiehi _3233__193 (.L_HI(net605));
 sg13g2_dfrbpq_1 _3234_ (.RESET_B(net606),
    .D(_0164_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_33_),
    .CLK(clknet_leaf_30_clk_i));
 sg13g2_tiehi _3234__194 (.L_HI(net606));
 sg13g2_dfrbpq_1 _3235_ (.RESET_B(net607),
    .D(_0163_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_34_),
    .CLK(clknet_leaf_26_clk_i));
 sg13g2_tiehi _3235__195 (.L_HI(net607));
 sg13g2_dfrbpq_1 _3236_ (.RESET_B(net608),
    .D(_0162_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_35_),
    .CLK(clknet_leaf_27_clk_i));
 sg13g2_tiehi _3236__196 (.L_HI(net608));
 sg13g2_dfrbpq_1 _3237_ (.RESET_B(net609),
    .D(_0161_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_36_),
    .CLK(clknet_leaf_27_clk_i));
 sg13g2_tiehi _3237__197 (.L_HI(net609));
 sg13g2_dfrbpq_1 _3238_ (.RESET_B(net610),
    .D(_0160_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_37_),
    .CLK(clknet_leaf_23_clk_i));
 sg13g2_tiehi _3238__198 (.L_HI(net610));
 sg13g2_dfrbpq_1 _3239_ (.RESET_B(net611),
    .D(_0159_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_38_),
    .CLK(clknet_leaf_29_clk_i));
 sg13g2_tiehi _3239__199 (.L_HI(net611));
 sg13g2_dfrbpq_1 _3240_ (.RESET_B(net612),
    .D(_0158_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_40_),
    .CLK(clknet_leaf_27_clk_i));
 sg13g2_tiehi _3240__200 (.L_HI(net612));
 sg13g2_dfrbpq_1 _3241_ (.RESET_B(net613),
    .D(_0157_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_41_),
    .CLK(clknet_leaf_28_clk_i));
 sg13g2_tiehi _3241__201 (.L_HI(net613));
 sg13g2_dfrbpq_1 _3242_ (.RESET_B(net614),
    .D(_0156_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_42_),
    .CLK(clknet_leaf_26_clk_i));
 sg13g2_tiehi _3242__202 (.L_HI(net614));
 sg13g2_dfrbpq_1 _3243_ (.RESET_B(net615),
    .D(_0155_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_43_),
    .CLK(clknet_leaf_27_clk_i));
 sg13g2_tiehi _3243__203 (.L_HI(net615));
 sg13g2_dfrbpq_1 _3244_ (.RESET_B(net616),
    .D(_0154_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_44_),
    .CLK(clknet_leaf_27_clk_i));
 sg13g2_tiehi _3244__204 (.L_HI(net616));
 sg13g2_dfrbpq_1 _3245_ (.RESET_B(net617),
    .D(_0153_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_45_),
    .CLK(clknet_leaf_25_clk_i));
 sg13g2_tiehi _3245__205 (.L_HI(net617));
 sg13g2_dfrbpq_1 _3246_ (.RESET_B(net618),
    .D(_0152_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_46_),
    .CLK(clknet_leaf_28_clk_i));
 sg13g2_tiehi _3246__206 (.L_HI(net618));
 sg13g2_dfrbpq_1 _3247_ (.RESET_B(net619),
    .D(_0151_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_48_),
    .CLK(clknet_leaf_33_clk_i));
 sg13g2_tiehi _3247__207 (.L_HI(net619));
 sg13g2_dfrbpq_1 _3248_ (.RESET_B(net620),
    .D(_0150_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_49_),
    .CLK(clknet_leaf_35_clk_i));
 sg13g2_tiehi _3248__208 (.L_HI(net620));
 sg13g2_dfrbpq_1 _3249_ (.RESET_B(net621),
    .D(_0149_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_50_),
    .CLK(clknet_leaf_35_clk_i));
 sg13g2_tiehi _3249__209 (.L_HI(net621));
 sg13g2_dfrbpq_1 _3250_ (.RESET_B(net622),
    .D(_0148_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_51_),
    .CLK(clknet_leaf_34_clk_i));
 sg13g2_tiehi _3250__210 (.L_HI(net622));
 sg13g2_dfrbpq_1 _3251_ (.RESET_B(net623),
    .D(_0147_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_52_),
    .CLK(clknet_leaf_34_clk_i));
 sg13g2_tiehi _3251__211 (.L_HI(net623));
 sg13g2_dfrbpq_1 _3252_ (.RESET_B(net624),
    .D(_0146_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_53_),
    .CLK(clknet_leaf_33_clk_i));
 sg13g2_tiehi _3252__212 (.L_HI(net624));
 sg13g2_dfrbpq_1 _3253_ (.RESET_B(net625),
    .D(_0145_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_54_),
    .CLK(clknet_leaf_34_clk_i));
 sg13g2_tiehi _3253__213 (.L_HI(net625));
 sg13g2_dfrbpq_1 _3254_ (.RESET_B(net626),
    .D(_0144_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_56_),
    .CLK(clknet_leaf_34_clk_i));
 sg13g2_tiehi _3254__214 (.L_HI(net626));
 sg13g2_dfrbpq_1 _3255_ (.RESET_B(net627),
    .D(_0143_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_57_),
    .CLK(clknet_leaf_34_clk_i));
 sg13g2_tiehi _3255__215 (.L_HI(net627));
 sg13g2_dfrbpq_1 _3256_ (.RESET_B(net628),
    .D(_0142_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_58_),
    .CLK(clknet_leaf_35_clk_i));
 sg13g2_tiehi _3256__216 (.L_HI(net628));
 sg13g2_dfrbpq_1 _3257_ (.RESET_B(net629),
    .D(_0141_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_59_),
    .CLK(clknet_leaf_30_clk_i));
 sg13g2_tiehi _3257__217 (.L_HI(net629));
 sg13g2_dfrbpq_1 _3258_ (.RESET_B(net630),
    .D(_0140_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_60_),
    .CLK(clknet_leaf_34_clk_i));
 sg13g2_tiehi _3258__218 (.L_HI(net630));
 sg13g2_dfrbpq_1 _3259_ (.RESET_B(net631),
    .D(_0139_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_61_),
    .CLK(clknet_leaf_33_clk_i));
 sg13g2_tiehi _3259__219 (.L_HI(net631));
 sg13g2_dfrbpq_1 _3260_ (.RESET_B(net632),
    .D(_0138_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_62_),
    .CLK(clknet_leaf_35_clk_i));
 sg13g2_tiehi _3260__220 (.L_HI(net632));
 sg13g2_dfrbpq_1 _3261_ (.RESET_B(net1249),
    .D(_0325_),
    .Q(_0037_),
    .CLK(clknet_leaf_19_clk_i));
 sg13g2_dfrbpq_1 _3262_ (.RESET_B(net1248),
    .D(_0324_),
    .Q(_0036_),
    .CLK(clknet_leaf_32_clk_i));
 sg13g2_dfrbpq_1 _3263_ (.RESET_B(net1248),
    .D(_0323_),
    .Q(_0035_),
    .CLK(clknet_leaf_32_clk_i));
 sg13g2_dfrbpq_1 _3264_ (.RESET_B(net1248),
    .D(_0322_),
    .Q(_0034_),
    .CLK(clknet_leaf_32_clk_i));
 sg13g2_dfrbpq_1 _3265_ (.RESET_B(net1248),
    .D(_0321_),
    .Q(_0033_),
    .CLK(clknet_leaf_33_clk_i));
 sg13g2_dfrbpq_1 _3266_ (.RESET_B(net1248),
    .D(_0320_),
    .Q(_0032_),
    .CLK(clknet_leaf_32_clk_i));
 sg13g2_dfrbpq_1 _3267_ (.RESET_B(net1248),
    .D(_0319_),
    .Q(_0031_),
    .CLK(clknet_leaf_33_clk_i));
 sg13g2_dfrbpq_1 _3268_ (.RESET_B(net1248),
    .D(_0318_),
    .Q(_0030_),
    .CLK(clknet_leaf_31_clk_i));
 sg13g2_dfrbpq_1 _3269_ (.RESET_B(net1248),
    .D(_0317_),
    .Q(_0029_),
    .CLK(clknet_leaf_32_clk_i));
 sg13g2_dfrbpq_1 _3270_ (.RESET_B(net1249),
    .D(_0326_),
    .Q(_0038_),
    .CLK(clknet_leaf_32_clk_i));
 sg13g2_dfrbpq_1 _3271_ (.RESET_B(net1236),
    .D(_0327_),
    .Q(net727),
    .CLK(clknet_leaf_22_clk_i));
 sg13g2_dfrbpq_1 _3272_ (.RESET_B(u_uart_core_rx_rst_ni),
    .D(_0316_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_0_),
    .CLK(clknet_leaf_17_clk_i));
 sg13g2_dfrbpq_1 _3273_ (.RESET_B(u_uart_core_rx_rst_ni),
    .D(_0315_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_1_),
    .CLK(clknet_leaf_5_clk_i));
 sg13g2_dfrbpq_1 _3274_ (.RESET_B(net1244),
    .D(_0314_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_),
    .CLK(clknet_leaf_5_clk_i));
 sg13g2_dfrbpq_1 _3275_ (.RESET_B(net1244),
    .D(_0313_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_),
    .CLK(clknet_leaf_5_clk_i));
 sg13g2_dfrbpq_1 _3276_ (.RESET_B(u_uart_core_rx_rst_ni),
    .D(_0328_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .CLK(clknet_leaf_5_clk_i));
 sg13g2_dfrbpq_1 _3277_ (.RESET_B(net1244),
    .D(_0200_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_0_),
    .CLK(clknet_leaf_6_clk_i));
 sg13g2_dfrbpq_1 _3278_ (.RESET_B(net1244),
    .D(_0199_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_),
    .CLK(clknet_leaf_6_clk_i));
 sg13g2_dfrbpq_1 _3279_ (.RESET_B(net1244),
    .D(_0198_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_),
    .CLK(clknet_leaf_5_clk_i));
 sg13g2_dfrbpq_1 _3280_ (.RESET_B(net1244),
    .D(_0197_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_),
    .CLK(clknet_leaf_5_clk_i));
 sg13g2_dfrbpq_1 _3281_ (.RESET_B(u_uart_core_rx_rst_ni),
    .D(_0345_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .CLK(clknet_leaf_6_clk_i));
 sg13g2_dfrbpq_1 _3282_ (.RESET_B(net1250),
    .D(_0196_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .CLK(clknet_leaf_31_clk_i));
 sg13g2_dfrbpq_1 _3283_ (.RESET_B(net1250),
    .D(_0195_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_),
    .CLK(clknet_leaf_31_clk_i));
 sg13g2_dfrbpq_1 _3284_ (.RESET_B(net1250),
    .D(_0194_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_2_),
    .CLK(clknet_leaf_31_clk_i));
 sg13g2_dfrbpq_1 _3285_ (.RESET_B(net1250),
    .D(_0346_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .CLK(clknet_leaf_19_clk_i));
 sg13g2_dfrbpq_1 _3286_ (.RESET_B(net1250),
    .D(_0137_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_0_),
    .CLK(clknet_leaf_20_clk_i));
 sg13g2_tielo _3291__2 (.L_LO(tl_o[2]));
 sg13g2_tielo _3292__3 (.L_LO(tl_o[3]));
 sg13g2_tielo _3293__4 (.L_LO(tl_o[4]));
 sg13g2_tielo _3294__5 (.L_LO(tl_o[5]));
 sg13g2_tielo _3295__6 (.L_LO(tl_o[6]));
 sg13g2_tielo _3296__7 (.L_LO(tl_o[7]));
 sg13g2_tielo _3297__8 (.L_LO(tl_o[8]));
 sg13g2_tielo _3298__9 (.L_LO(tl_o[9]));
 sg13g2_tielo _3299__10 (.L_LO(tl_o[10]));
 sg13g2_tielo _3300__11 (.L_LO(tl_o[11]));
 sg13g2_tielo _3301__12 (.L_LO(tl_o[12]));
 sg13g2_tielo _3302__13 (.L_LO(tl_o[13]));
 sg13g2_tielo _3303__14 (.L_LO(tl_o[14]));
 sg13g2_tielo _3304__15 (.L_LO(tl_o[15]));
 sg13g2_tielo _3337__16 (.L_LO(tl_o[48]));
 sg13g2_tielo _3348__17 (.L_LO(tl_o[59]));
 sg13g2_tielo _3349__18 (.L_LO(tl_o[60]));
 sg13g2_tielo _3350__19 (.L_LO(tl_o[61]));
 sg13g2_tielo _3352__20 (.L_LO(tl_o[63]));
 sg13g2_tielo _3353__21 (.L_LO(tl_o[64]));
 sg13g2_buf_8 clkbuf_0_clk_i (.A(clk_i),
    .X(clknet_0_clk_i));
 sg13g2_buf_8 clkbuf_3_0__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_3_0__leaf_clk_i));
 sg13g2_buf_8 clkbuf_3_1__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_3_1__leaf_clk_i));
 sg13g2_buf_8 clkbuf_3_2__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_3_2__leaf_clk_i));
 sg13g2_buf_8 clkbuf_3_3__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_3_3__leaf_clk_i));
 sg13g2_buf_8 clkbuf_3_4__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_3_4__leaf_clk_i));
 sg13g2_buf_8 clkbuf_3_5__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_3_5__leaf_clk_i));
 sg13g2_buf_8 clkbuf_3_6__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_3_6__leaf_clk_i));
 sg13g2_buf_8 clkbuf_3_7__f_clk_i (.A(clknet_0_clk_i),
    .X(clknet_3_7__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_0_clk_i (.X(clknet_leaf_0_clk_i),
    .A(clknet_3_0__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_10_clk_i (.X(clknet_leaf_10_clk_i),
    .A(clknet_3_2__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_11_clk_i (.X(clknet_leaf_11_clk_i),
    .A(clknet_3_2__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_12_clk_i (.X(clknet_leaf_12_clk_i),
    .A(clknet_3_2__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_13_clk_i (.X(clknet_leaf_13_clk_i),
    .A(clknet_3_3__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_14_clk_i (.X(clknet_leaf_14_clk_i),
    .A(clknet_3_3__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_15_clk_i (.X(clknet_leaf_15_clk_i),
    .A(clknet_3_6__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_16_clk_i (.X(clknet_leaf_16_clk_i),
    .A(clknet_3_6__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_17_clk_i (.X(clknet_leaf_17_clk_i),
    .A(clknet_3_3__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_18_clk_i (.X(clknet_leaf_18_clk_i),
    .A(clknet_3_6__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_19_clk_i (.X(clknet_leaf_19_clk_i),
    .A(clknet_3_4__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_1_clk_i (.X(clknet_leaf_1_clk_i),
    .A(clknet_3_0__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_20_clk_i (.X(clknet_leaf_20_clk_i),
    .A(clknet_3_4__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_21_clk_i (.X(clknet_leaf_21_clk_i),
    .A(clknet_3_6__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_22_clk_i (.X(clknet_leaf_22_clk_i),
    .A(clknet_3_6__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_23_clk_i (.X(clknet_leaf_23_clk_i),
    .A(clknet_3_6__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_24_clk_i (.X(clknet_leaf_24_clk_i),
    .A(clknet_3_7__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_25_clk_i (.X(clknet_leaf_25_clk_i),
    .A(clknet_3_7__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_26_clk_i (.X(clknet_leaf_26_clk_i),
    .A(clknet_3_7__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_27_clk_i (.X(clknet_leaf_27_clk_i),
    .A(clknet_3_7__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_28_clk_i (.X(clknet_leaf_28_clk_i),
    .A(clknet_3_7__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_29_clk_i (.X(clknet_leaf_29_clk_i),
    .A(clknet_3_5__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_2_clk_i (.X(clknet_leaf_2_clk_i),
    .A(clknet_3_0__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_30_clk_i (.X(clknet_leaf_30_clk_i),
    .A(clknet_3_5__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_31_clk_i (.X(clknet_leaf_31_clk_i),
    .A(clknet_3_5__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_32_clk_i (.X(clknet_leaf_32_clk_i),
    .A(clknet_3_4__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_33_clk_i (.X(clknet_leaf_33_clk_i),
    .A(clknet_3_5__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_34_clk_i (.X(clknet_leaf_34_clk_i),
    .A(clknet_3_5__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_35_clk_i (.X(clknet_leaf_35_clk_i),
    .A(clknet_3_5__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_36_clk_i (.X(clknet_leaf_36_clk_i),
    .A(clknet_3_4__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_37_clk_i (.X(clknet_leaf_37_clk_i),
    .A(clknet_3_4__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_38_clk_i (.X(clknet_leaf_38_clk_i),
    .A(clknet_3_4__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_39_clk_i (.X(clknet_leaf_39_clk_i),
    .A(clknet_3_1__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_3_clk_i (.X(clknet_leaf_3_clk_i),
    .A(clknet_3_0__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_40_clk_i (.X(clknet_leaf_40_clk_i),
    .A(clknet_3_1__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_41_clk_i (.X(clknet_leaf_41_clk_i),
    .A(clknet_3_1__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_42_clk_i (.X(clknet_leaf_42_clk_i),
    .A(clknet_3_1__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_43_clk_i (.X(clknet_leaf_43_clk_i),
    .A(clknet_3_1__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_44_clk_i (.X(clknet_leaf_44_clk_i),
    .A(clknet_3_0__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_45_clk_i (.X(clknet_leaf_45_clk_i),
    .A(clknet_3_0__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_4_clk_i (.X(clknet_leaf_4_clk_i),
    .A(clknet_3_1__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_5_clk_i (.X(clknet_leaf_5_clk_i),
    .A(clknet_3_3__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_6_clk_i (.X(clknet_leaf_6_clk_i),
    .A(clknet_3_3__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_7_clk_i (.X(clknet_leaf_7_clk_i),
    .A(clknet_3_2__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_8_clk_i (.X(clknet_leaf_8_clk_i),
    .A(clknet_3_2__leaf_clk_i));
 sg13g2_buf_16 clkbuf_leaf_9_clk_i (.X(clknet_leaf_9_clk_i),
    .A(clknet_3_2__leaf_clk_i));
 sg13g2_buf_16 clkload0 (.A(clknet_3_3__leaf_clk_i));
 sg13g2_buf_16 clkload1 (.A(clknet_3_7__leaf_clk_i));
 sg13g2_buf_16 clkload2 (.A(clknet_leaf_45_clk_i));
 sg13g2_inv_1 clkload3 (.A(clknet_leaf_35_clk_i));
 sg13g2_dlygate4sd3_1 hold841 (.A(tl_i[0]),
    .X(net1253));
 sg13g2_dlygate4sd3_1 hold842 (.A(net635),
    .X(net1254));
 sg13g2_dlygate4sd3_1 hold843 (.A(tl_i[47]),
    .X(net1255));
 sg13g2_dlygate4sd3_1 hold844 (.A(tl_i[50]),
    .X(net1256));
 sg13g2_dlygate4sd3_1 hold845 (.A(tl_i[52]),
    .X(net1257));
 sg13g2_dlygate4sd3_1 hold846 (.A(_1424_),
    .X(net1258));
 sg13g2_dlygate4sd3_1 hold847 (.A(rx_i),
    .X(net1259));
 sg13g2_dlygate4sd3_1 hold848 (.A(tl_i[45]),
    .X(net1260));
 sg13g2_dlygate4sd3_1 hold849 (.A(tl_i[46]),
    .X(net1261));
 sg13g2_dlygate4sd3_1 hold850 (.A(tl_i[53]),
    .X(net1262));
 sg13g2_dlygate4sd3_1 hold851 (.A(_1423_),
    .X(net1263));
 sg13g2_dlygate4sd3_1 hold852 (.A(tl_i[49]),
    .X(net1264));
 sg13g2_dlygate4sd3_1 hold853 (.A(tl_i[100]),
    .X(net1265));
 sg13g2_dlygate4sd3_1 hold854 (.A(tl_i[55]),
    .X(net1266));
 sg13g2_dlygate4sd3_1 hold855 (.A(_0369_),
    .X(net1267));
 sg13g2_dlygate4sd3_1 hold856 (.A(tl_i[96]),
    .X(net1268));
 sg13g2_dlygate4sd3_1 hold857 (.A(tl_i[95]),
    .X(net1269));
 sg13g2_dlygate4sd3_1 hold858 (.A(tl_i[48]),
    .X(net1270));
 sg13g2_dlygate4sd3_1 hold859 (.A(tl_i[94]),
    .X(net1271));
 sg13g2_dlygate4sd3_1 hold860 (.A(tl_i[54]),
    .X(net1272));
 sg13g2_dlygate4sd3_1 hold861 (.A(_1422_),
    .X(net1273));
 sg13g2_dlygate4sd3_1 hold862 (.A(tl_i[51]),
    .X(net1274));
 sg13g2_dlygate4sd3_1 hold863 (.A(tl_i[27]),
    .X(net1275));
 sg13g2_dlygate4sd3_1 hold864 (.A(_1411_),
    .X(net1276));
 sg13g2_dlygate4sd3_1 hold865 (.A(tl_i[92]),
    .X(net1277));
 sg13g2_dlygate4sd3_1 hold866 (.A(tl_i[99]),
    .X(net1278));
 sg13g2_dlygate4sd3_1 hold867 (.A(tl_i[101]),
    .X(net1279));
 sg13g2_dlygate4sd3_1 hold868 (.A(tl_i[93]),
    .X(net1280));
 sg13g2_dlygate4sd3_1 hold869 (.A(tl_i[40]),
    .X(net1281));
 sg13g2_dlygate4sd3_1 hold870 (.A(tl_i[30]),
    .X(net1282));
 sg13g2_dlygate4sd3_1 hold871 (.A(_0053_),
    .X(net1283));
 sg13g2_dlygate4sd3_1 hold872 (.A(tl_i[61]),
    .X(net1284));
 sg13g2_dlygate4sd3_1 hold873 (.A(_1395_),
    .X(net1285));
 sg13g2_dlygate4sd3_1 hold874 (.A(_1419_),
    .X(net1286));
 sg13g2_dlygate4sd3_1 hold875 (.A(net1152),
    .X(net1287));
 sg13g2_dlygate4sd3_1 hold876 (.A(_1288_),
    .X(net1288));
 sg13g2_dlygate4sd3_1 hold877 (.A(tl_i[43]),
    .X(net1289));
 sg13g2_dlygate4sd3_1 hold878 (.A(tl_i[97]),
    .X(net1290));
 sg13g2_dlygate4sd3_1 hold879 (.A(tl_i[28]),
    .X(net1291));
 sg13g2_dlygate4sd3_1 hold880 (.A(tl_i[24]),
    .X(net1292));
 sg13g2_dlygate4sd3_1 hold881 (.A(tl_i[41]),
    .X(net1293));
 sg13g2_dlygate4sd3_1 hold882 (.A(tl_i[25]),
    .X(net1294));
 sg13g2_dlygate4sd3_1 hold883 (.A(tl_i[105]),
    .X(net1295));
 sg13g2_dlygate4sd3_1 hold884 (.A(_1078_),
    .X(net1296));
 sg13g2_dlygate4sd3_1 hold885 (.A(tl_i[60]),
    .X(net1297));
 sg13g2_dlygate4sd3_1 hold886 (.A(tl_i[31]),
    .X(net1298));
 sg13g2_dlygate4sd3_1 hold887 (.A(tl_i[42]),
    .X(net1299));
 sg13g2_dlygate4sd3_1 hold888 (.A(tl_i[98]),
    .X(net1300));
 sg13g2_dlygate4sd3_1 hold889 (.A(tl_i[26]),
    .X(net1301));
 sg13g2_dlygate4sd3_1 hold890 (.A(tl_i[29]),
    .X(net1302));
 sg13g2_dlygate4sd3_1 hold891 (.A(tl_i[62]),
    .X(net1303));
 sg13g2_dlygate4sd3_1 hold892 (.A(_1403_),
    .X(net1304));
 sg13g2_dlygate4sd3_1 hold893 (.A(tl_i[44]),
    .X(net1305));
 sg13g2_dlygate4sd3_1 hold894 (.A(rst_ni),
    .X(net1306));
 sg13g2_dlygate4sd3_1 hold895 (.A(tl_i[108]),
    .X(net1307));
 sg13g2_dlygate4sd3_1 hold896 (.A(_0088_),
    .X(net1308));
 sg13g2_dlygate4sd3_1 hold897 (.A(tl_i[64]),
    .X(net1309));
 sg13g2_dlygate4sd3_1 hold898 (.A(_1385_),
    .X(net1310));
 sg13g2_dlygate4sd3_1 hold899 (.A(tl_i[63]),
    .X(net1311));
 sg13g2_dlygate4sd3_1 hold900 (.A(tl_i[107]),
    .X(net1312));
 sg13g2_dlygate4sd3_1 hold901 (.A(_1399_),
    .X(net1313));
 sg13g2_dlygate4sd3_1 hold902 (.A(_1292_),
    .X(net1314));
 sg13g2_dlygate4sd3_1 hold903 (.A(tl_i[59]),
    .X(net1315));
 sg13g2_dlygate4sd3_1 hold904 (.A(_1394_),
    .X(net1316));
 sg13g2_buf_1 input221 (.A(net1306),
    .X(net633));
 sg13g2_buf_1 input222 (.A(net1259),
    .X(net634));
 sg13g2_buf_1 input223 (.A(net1253),
    .X(net635));
 sg13g2_buf_1 input224 (.A(net1265),
    .X(net636));
 sg13g2_buf_1 input225 (.A(net1279),
    .X(net637));
 sg13g2_buf_1 input226 (.A(net1295),
    .X(net638));
 sg13g2_buf_1 input227 (.A(tl_i[106]),
    .X(net639));
 sg13g2_buf_1 input228 (.A(net1312),
    .X(net640));
 sg13g2_buf_1 input229 (.A(net1307),
    .X(net641));
 sg13g2_buf_1 input230 (.A(net1292),
    .X(net642));
 sg13g2_buf_1 input231 (.A(net1294),
    .X(net643));
 sg13g2_buf_1 input232 (.A(net1301),
    .X(net644));
 sg13g2_buf_1 input233 (.A(net1275),
    .X(net645));
 sg13g2_buf_1 input234 (.A(net1291),
    .X(net646));
 sg13g2_buf_1 input235 (.A(net1302),
    .X(net647));
 sg13g2_buf_1 input236 (.A(net1282),
    .X(net648));
 sg13g2_buf_1 input237 (.A(net1298),
    .X(net649));
 sg13g2_buf_1 input238 (.A(net1281),
    .X(net650));
 sg13g2_buf_1 input239 (.A(net1293),
    .X(net651));
 sg13g2_buf_1 input240 (.A(net1299),
    .X(net652));
 sg13g2_buf_1 input241 (.A(net1289),
    .X(net653));
 sg13g2_buf_1 input242 (.A(net1305),
    .X(net654));
 sg13g2_buf_1 input243 (.A(net1260),
    .X(net655));
 sg13g2_buf_1 input244 (.A(net1261),
    .X(net656));
 sg13g2_buf_1 input245 (.A(net1255),
    .X(net657));
 sg13g2_buf_1 input246 (.A(net1270),
    .X(net658));
 sg13g2_buf_1 input247 (.A(net1264),
    .X(net659));
 sg13g2_buf_1 input248 (.A(net1256),
    .X(net660));
 sg13g2_buf_1 input249 (.A(net1274),
    .X(net661));
 sg13g2_buf_1 input250 (.A(net1257),
    .X(net662));
 sg13g2_buf_1 input251 (.A(net1262),
    .X(net663));
 sg13g2_buf_1 input252 (.A(net1272),
    .X(net664));
 sg13g2_buf_1 input253 (.A(net1266),
    .X(net665));
 sg13g2_buf_1 input254 (.A(tl_i[56]),
    .X(net666));
 sg13g2_buf_1 input255 (.A(tl_i[57]),
    .X(net667));
 sg13g2_buf_1 input256 (.A(tl_i[58]),
    .X(net668));
 sg13g2_buf_1 input257 (.A(net1315),
    .X(net669));
 sg13g2_buf_1 input258 (.A(net1297),
    .X(net670));
 sg13g2_buf_1 input259 (.A(net1284),
    .X(net671));
 sg13g2_buf_1 input260 (.A(net1303),
    .X(net672));
 sg13g2_buf_1 input261 (.A(net1311),
    .X(net673));
 sg13g2_buf_1 input262 (.A(net1309),
    .X(net674));
 sg13g2_buf_1 input263 (.A(net1277),
    .X(net675));
 sg13g2_buf_1 input264 (.A(net1280),
    .X(net676));
 sg13g2_buf_1 input265 (.A(net1271),
    .X(net677));
 sg13g2_buf_1 input266 (.A(net1269),
    .X(net678));
 sg13g2_buf_1 input267 (.A(net1268),
    .X(net679));
 sg13g2_buf_1 input268 (.A(net1290),
    .X(net680));
 sg13g2_buf_1 input269 (.A(net1300),
    .X(net681));
 sg13g2_buf_1 input270 (.A(net1278),
    .X(net682));
 sg13g2_buf_1 output271 (.A(net683),
    .X(tl_o[0]));
 sg13g2_buf_1 output272 (.A(net684),
    .X(tl_o[16]));
 sg13g2_buf_1 output273 (.A(net685),
    .X(tl_o[17]));
 sg13g2_buf_1 output274 (.A(net686),
    .X(tl_o[18]));
 sg13g2_buf_1 output275 (.A(net687),
    .X(tl_o[19]));
 sg13g2_buf_1 output276 (.A(net688),
    .X(tl_o[1]));
 sg13g2_buf_1 output277 (.A(net689),
    .X(tl_o[20]));
 sg13g2_buf_1 output278 (.A(net690),
    .X(tl_o[21]));
 sg13g2_buf_1 output279 (.A(net691),
    .X(tl_o[22]));
 sg13g2_buf_1 output280 (.A(net692),
    .X(tl_o[23]));
 sg13g2_buf_1 output281 (.A(net693),
    .X(tl_o[24]));
 sg13g2_buf_1 output282 (.A(net694),
    .X(tl_o[25]));
 sg13g2_buf_1 output283 (.A(net695),
    .X(tl_o[26]));
 sg13g2_buf_1 output284 (.A(net696),
    .X(tl_o[27]));
 sg13g2_buf_1 output285 (.A(net697),
    .X(tl_o[28]));
 sg13g2_buf_1 output286 (.A(net698),
    .X(tl_o[29]));
 sg13g2_buf_1 output287 (.A(net699),
    .X(tl_o[30]));
 sg13g2_buf_1 output288 (.A(net700),
    .X(tl_o[31]));
 sg13g2_buf_1 output289 (.A(net701),
    .X(tl_o[32]));
 sg13g2_buf_1 output290 (.A(net702),
    .X(tl_o[33]));
 sg13g2_buf_1 output291 (.A(net703),
    .X(tl_o[34]));
 sg13g2_buf_1 output292 (.A(net704),
    .X(tl_o[35]));
 sg13g2_buf_1 output293 (.A(net705),
    .X(tl_o[36]));
 sg13g2_buf_1 output294 (.A(net706),
    .X(tl_o[37]));
 sg13g2_buf_1 output295 (.A(net707),
    .X(tl_o[38]));
 sg13g2_buf_1 output296 (.A(net708),
    .X(tl_o[39]));
 sg13g2_buf_1 output297 (.A(net709),
    .X(tl_o[40]));
 sg13g2_buf_1 output298 (.A(net710),
    .X(tl_o[41]));
 sg13g2_buf_1 output299 (.A(net711),
    .X(tl_o[42]));
 sg13g2_buf_1 output300 (.A(net712),
    .X(tl_o[43]));
 sg13g2_buf_1 output301 (.A(net713),
    .X(tl_o[44]));
 sg13g2_buf_1 output302 (.A(net714),
    .X(tl_o[45]));
 sg13g2_buf_1 output303 (.A(net715),
    .X(tl_o[46]));
 sg13g2_buf_1 output304 (.A(net716),
    .X(tl_o[47]));
 sg13g2_buf_1 output305 (.A(net717),
    .X(tl_o[49]));
 sg13g2_buf_1 output306 (.A(net718),
    .X(tl_o[50]));
 sg13g2_buf_1 output307 (.A(net719),
    .X(tl_o[51]));
 sg13g2_buf_1 output308 (.A(net720),
    .X(tl_o[52]));
 sg13g2_buf_1 output309 (.A(net721),
    .X(tl_o[53]));
 sg13g2_buf_1 output310 (.A(net722),
    .X(tl_o[54]));
 sg13g2_buf_1 output311 (.A(net723),
    .X(tl_o[55]));
 sg13g2_buf_1 output312 (.A(net724),
    .X(tl_o[56]));
 sg13g2_buf_1 output313 (.A(net725),
    .X(tl_o[57]));
 sg13g2_buf_1 output314 (.A(net726),
    .X(tl_o[58]));
 sg13g2_buf_1 output315 (.A(net727),
    .X(tl_o[62]));
 sg13g2_buf_1 output316 (.A(net728),
    .X(tl_o[65]));
 sg13g2_buf_1 output317 (.A(net729),
    .X(tx_o));
 sg13g2_buf_1 place678 (.A(_0896_),
    .X(net1090));
 sg13g2_buf_1 place679 (.A(_0896_),
    .X(net1091));
 sg13g2_buf_1 place680 (.A(_0698_),
    .X(net1092));
 sg13g2_buf_1 place681 (.A(net1094),
    .X(net1093));
 sg13g2_buf_1 place682 (.A(_1050_),
    .X(net1094));
 sg13g2_buf_1 place683 (.A(_1032_),
    .X(net1095));
 sg13g2_buf_1 place684 (.A(_1032_),
    .X(net1096));
 sg13g2_buf_1 place685 (.A(_1006_),
    .X(net1097));
 sg13g2_buf_1 place686 (.A(_1006_),
    .X(net1098));
 sg13g2_buf_1 place687 (.A(_0988_),
    .X(net1099));
 sg13g2_buf_1 place688 (.A(_0988_),
    .X(net1100));
 sg13g2_buf_1 place689 (.A(_0969_),
    .X(net1101));
 sg13g2_buf_1 place690 (.A(_0969_),
    .X(net1102));
 sg13g2_buf_1 place691 (.A(_0950_),
    .X(net1103));
 sg13g2_buf_1 place692 (.A(_0950_),
    .X(net1104));
 sg13g2_buf_1 place693 (.A(net1106),
    .X(net1105));
 sg13g2_buf_1 place694 (.A(_0908_),
    .X(net1106));
 sg13g2_buf_1 place695 (.A(_1068_),
    .X(net1107));
 sg13g2_buf_1 place696 (.A(_1068_),
    .X(net1108));
 sg13g2_buf_1 place697 (.A(net1110),
    .X(net1109));
 sg13g2_buf_1 place698 (.A(_1059_),
    .X(net1110));
 sg13g2_buf_1 place699 (.A(_1041_),
    .X(net1111));
 sg13g2_buf_1 place700 (.A(_1041_),
    .X(net1112));
 sg13g2_buf_1 place701 (.A(_1023_),
    .X(net1113));
 sg13g2_buf_1 place702 (.A(_1023_),
    .X(net1114));
 sg13g2_buf_1 place703 (.A(_0997_),
    .X(net1115));
 sg13g2_buf_1 place704 (.A(_0997_),
    .X(net1116));
 sg13g2_buf_1 place705 (.A(_0978_),
    .X(net1117));
 sg13g2_buf_1 place706 (.A(_0978_),
    .X(net1118));
 sg13g2_buf_1 place707 (.A(_0960_),
    .X(net1119));
 sg13g2_buf_1 place708 (.A(_0960_),
    .X(net1120));
 sg13g2_buf_1 place709 (.A(net1122),
    .X(net1121));
 sg13g2_buf_1 place710 (.A(_0939_),
    .X(net1122));
 sg13g2_buf_1 place711 (.A(_0825_),
    .X(net1123));
 sg13g2_buf_1 place712 (.A(_0825_),
    .X(net1124));
 sg13g2_buf_1 place713 (.A(net1126),
    .X(net1125));
 sg13g2_buf_1 place714 (.A(_0776_),
    .X(net1126));
 sg13g2_buf_1 place715 (.A(_0689_),
    .X(net1127));
 sg13g2_buf_1 place716 (.A(_0860_),
    .X(net1128));
 sg13g2_buf_1 place717 (.A(_0860_),
    .X(net1129));
 sg13g2_buf_1 place718 (.A(net1131),
    .X(net1130));
 sg13g2_buf_1 place719 (.A(_0845_),
    .X(net1131));
 sg13g2_buf_1 place720 (.A(_0816_),
    .X(net1132));
 sg13g2_buf_1 place721 (.A(_0816_),
    .X(net1133));
 sg13g2_buf_1 place722 (.A(net1135),
    .X(net1134));
 sg13g2_buf_1 place723 (.A(_0800_),
    .X(net1135));
 sg13g2_buf_1 place724 (.A(net1137),
    .X(net1136));
 sg13g2_buf_1 place725 (.A(_0834_),
    .X(net1137));
 sg13g2_buf_1 place726 (.A(net1139),
    .X(net1138));
 sg13g2_buf_1 place727 (.A(_0789_),
    .X(net1139));
 sg13g2_buf_1 place728 (.A(_0726_),
    .X(net1140));
 sg13g2_buf_1 place729 (.A(_0686_),
    .X(net1141));
 sg13g2_buf_1 place730 (.A(_0686_),
    .X(net1142));
 sg13g2_buf_1 place731 (.A(_0583_),
    .X(net1143));
 sg13g2_buf_1 place732 (.A(_0729_),
    .X(net1144));
 sg13g2_buf_1 place733 (.A(net1146),
    .X(net1145));
 sg13g2_buf_1 place734 (.A(_1403_),
    .X(net1146));
 sg13g2_buf_1 place735 (.A(_1419_),
    .X(net1147));
 sg13g2_buf_1 place736 (.A(net1149),
    .X(net1148));
 sg13g2_buf_1 place737 (.A(net1150),
    .X(net1149));
 sg13g2_buf_1 place738 (.A(net1286),
    .X(net1150));
 sg13g2_buf_1 place739 (.A(net1152),
    .X(net1151));
 sg13g2_buf_1 place740 (.A(_1419_),
    .X(net1152));
 sg13g2_buf_1 place741 (.A(_1463_),
    .X(net1153));
 sg13g2_buf_1 place742 (.A(net1155),
    .X(net1154));
 sg13g2_buf_1 place743 (.A(net1156),
    .X(net1155));
 sg13g2_buf_1 place744 (.A(_1442_),
    .X(net1156));
 sg13g2_buf_1 place745 (.A(net1158),
    .X(net1157));
 sg13g2_buf_1 place746 (.A(_1238_),
    .X(net1158));
 sg13g2_buf_1 place747 (.A(net1160),
    .X(net1159));
 sg13g2_buf_1 place748 (.A(_0935_),
    .X(net1160));
 sg13g2_buf_1 place749 (.A(net1162),
    .X(net1161));
 sg13g2_buf_1 place750 (.A(_0931_),
    .X(net1162));
 sg13g2_buf_1 place751 (.A(net1164),
    .X(net1163));
 sg13g2_buf_1 place752 (.A(_0927_),
    .X(net1164));
 sg13g2_buf_1 place753 (.A(net1166),
    .X(net1165));
 sg13g2_buf_1 place754 (.A(_0923_),
    .X(net1166));
 sg13g2_buf_1 place755 (.A(net1168),
    .X(net1167));
 sg13g2_buf_1 place756 (.A(_0919_),
    .X(net1168));
 sg13g2_buf_1 place757 (.A(net1170),
    .X(net1169));
 sg13g2_buf_1 place758 (.A(_0915_),
    .X(net1170));
 sg13g2_buf_1 place759 (.A(net1172),
    .X(net1171));
 sg13g2_buf_1 place760 (.A(_0911_),
    .X(net1172));
 sg13g2_buf_1 place761 (.A(net1175),
    .X(net1173));
 sg13g2_buf_1 place762 (.A(net1175),
    .X(net1174));
 sg13g2_buf_1 place763 (.A(_0434_),
    .X(net1175));
 sg13g2_buf_1 place764 (.A(net1177),
    .X(net1176));
 sg13g2_buf_1 place765 (.A(_0434_),
    .X(net1177));
 sg13g2_buf_1 place766 (.A(net1180),
    .X(net1178));
 sg13g2_buf_1 place767 (.A(net1180),
    .X(net1179));
 sg13g2_buf_1 place768 (.A(_0432_),
    .X(net1180));
 sg13g2_buf_1 place769 (.A(_0432_),
    .X(net1181));
 sg13g2_buf_1 place770 (.A(net1183),
    .X(net1182));
 sg13g2_buf_1 place771 (.A(net1184),
    .X(net1183));
 sg13g2_buf_1 place772 (.A(_1397_),
    .X(net1184));
 sg13g2_buf_1 place773 (.A(net1187),
    .X(net1185));
 sg13g2_buf_1 place774 (.A(net1187),
    .X(net1186));
 sg13g2_buf_1 place775 (.A(net1188),
    .X(net1187));
 sg13g2_buf_1 place776 (.A(_1397_),
    .X(net1188));
 sg13g2_buf_1 place777 (.A(_1385_),
    .X(net1189));
 sg13g2_buf_1 place778 (.A(net1191),
    .X(net1190));
 sg13g2_buf_1 place779 (.A(_1385_),
    .X(net1191));
 sg13g2_buf_1 place780 (.A(net1193),
    .X(net1192));
 sg13g2_buf_1 place781 (.A(_0869_),
    .X(net1193));
 sg13g2_buf_1 place782 (.A(_0569_),
    .X(net1194));
 sg13g2_buf_1 place783 (.A(net1197),
    .X(net1195));
 sg13g2_buf_1 place784 (.A(net1197),
    .X(net1196));
 sg13g2_buf_1 place785 (.A(_0426_),
    .X(net1197));
 sg13g2_buf_1 place786 (.A(net1199),
    .X(net1198));
 sg13g2_buf_1 place787 (.A(_0426_),
    .X(net1199));
 sg13g2_buf_1 place788 (.A(_0426_),
    .X(net1200));
 sg13g2_buf_1 place789 (.A(_0386_),
    .X(net1201));
 sg13g2_buf_1 place790 (.A(net1204),
    .X(net1202));
 sg13g2_buf_1 place791 (.A(net1204),
    .X(net1203));
 sg13g2_buf_1 place792 (.A(_1470_),
    .X(net1204));
 sg13g2_buf_1 place793 (.A(_1467_),
    .X(net1205));
 sg13g2_buf_1 place794 (.A(_1467_),
    .X(net1206));
 sg13g2_buf_1 place795 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_2_),
    .X(net1207));
 sg13g2_buf_1 place796 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_),
    .X(net1208));
 sg13g2_buf_1 place797 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_),
    .X(net1209));
 sg13g2_buf_1 place798 (.A(net1211),
    .X(net1210));
 sg13g2_buf_1 place799 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_),
    .X(net1211));
 sg13g2_buf_1 place800 (.A(net1216),
    .X(net1212));
 sg13g2_buf_1 place801 (.A(net1216),
    .X(net1213));
 sg13g2_buf_1 place802 (.A(net1216),
    .X(net1214));
 sg13g2_buf_1 place803 (.A(net1216),
    .X(net1215));
 sg13g2_buf_1 place804 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .X(net1216));
 sg13g2_buf_1 place805 (.A(net1218),
    .X(net1217));
 sg13g2_buf_1 place806 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .X(net1218));
 sg13g2_buf_1 place807 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_),
    .X(net1219));
 sg13g2_buf_1 place808 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_),
    .X(net1220));
 sg13g2_buf_1 place809 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_),
    .X(net1221));
 sg13g2_buf_1 place810 (.A(net1224),
    .X(net1222));
 sg13g2_buf_1 place811 (.A(net1224),
    .X(net1223));
 sg13g2_buf_1 place812 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_1_),
    .X(net1224));
 sg13g2_buf_1 place813 (.A(net1226),
    .X(net1225));
 sg13g2_buf_1 place814 (.A(net1227),
    .X(net1226));
 sg13g2_buf_1 place815 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_0_),
    .X(net1227));
 sg13g2_buf_1 place816 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_0_),
    .X(net1228));
 sg13g2_buf_1 place817 (.A(net1230),
    .X(net1229));
 sg13g2_buf_1 place818 (.A(reg_rst_ni),
    .X(net1230));
 sg13g2_buf_1 place819 (.A(reg_rst_ni),
    .X(net1231));
 sg13g2_buf_1 place820 (.A(reg_rst_ni),
    .X(net1232));
 sg13g2_buf_1 place821 (.A(net1235),
    .X(net1233));
 sg13g2_buf_1 place822 (.A(net1235),
    .X(net1234));
 sg13g2_buf_1 place823 (.A(net1236),
    .X(net1235));
 sg13g2_buf_1 place824 (.A(reg_rst_ni),
    .X(net1236));
 sg13g2_buf_1 place825 (.A(net1239),
    .X(net1237));
 sg13g2_buf_1 place826 (.A(net1239),
    .X(net1238));
 sg13g2_buf_1 place827 (.A(reg_rst_ni),
    .X(net1239));
 sg13g2_buf_1 place828 (.A(net1241),
    .X(net1240));
 sg13g2_buf_1 place829 (.A(u_uart_core_rx_rst_ni),
    .X(net1241));
 sg13g2_buf_1 place830 (.A(net1243),
    .X(net1242));
 sg13g2_buf_1 place831 (.A(u_uart_core_rx_rst_ni),
    .X(net1243));
 sg13g2_buf_1 place832 (.A(u_uart_core_rx_rst_ni),
    .X(net1244));
 sg13g2_buf_1 place833 (.A(u_uart_core_timing_rst_ni),
    .X(net1245));
 sg13g2_buf_1 place834 (.A(u_uart_core_timing_rst_ni),
    .X(net1246));
 sg13g2_buf_1 place835 (.A(u_uart_core_tx_rst_ni),
    .X(net1247));
 sg13g2_buf_1 place836 (.A(net1249),
    .X(net1248));
 sg13g2_buf_1 place837 (.A(u_uart_core_tx_rst_ni),
    .X(net1249));
 sg13g2_buf_1 place838 (.A(u_uart_core_tx_rst_ni),
    .X(net1250));
 sg13g2_buf_1 place839 (.A(reg2hw_39_),
    .X(net1251));
 sg13g2_buf_1 place840 (.A(reg2hw_39_),
    .X(net1252));
endmodule
