module uart (clk_i,
    rst_ni,
    rx_i,
    tx_o,
    axi_lite_i,
    axi_lite_o);
 input clk_i;
 input rst_ni;
 input rx_i;
 output tx_o;
 input [56:0] axi_lite_i;
 output [40:0] axi_lite_o;

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
 wire _0048_;
 wire _0049_;
 wire _0050_;
 wire _0051_;
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
 wire _0395_;
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
 wire _0427_;
 wire _0428_;
 wire _0429_;
 wire _0430_;
 wire _0431_;
 wire _0432_;
 wire _0433_;
 wire _0434_;
 wire _0435_;
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
 wire _0687_;
 wire _0688_;
 wire _0689_;
 wire _0690_;
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
 wire _0727_;
 wire _0728_;
 wire _0729_;
 wire _0730_;
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
 wire _0775_;
 wire _0776_;
 wire _0777_;
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
 wire _0790_;
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
 wire _0801_;
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
 wire _0817_;
 wire _0818_;
 wire _0819_;
 wire _0820_;
 wire _0821_;
 wire _0822_;
 wire _0823_;
 wire _0824_;
 wire _0825_;
 wire _0826_;
 wire _0827_;
 wire _0828_;
 wire _0829_;
 wire _0830_;
 wire _0831_;
 wire _0832_;
 wire _0833_;
 wire _0834_;
 wire _0835_;
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
 wire _0846_;
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
 wire _0861_;
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
 wire _0897_;
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
 wire _0909_;
 wire _0910_;
 wire _0911_;
 wire _0912_;
 wire _0913_;
 wire _0914_;
 wire _0915_;
 wire _0916_;
 wire _0917_;
 wire _0918_;
 wire _0919_;
 wire _0920_;
 wire _0921_;
 wire _0922_;
 wire _0923_;
 wire _0924_;
 wire _0925_;
 wire _0926_;
 wire _0927_;
 wire _0928_;
 wire _0929_;
 wire _0930_;
 wire _0931_;
 wire _0932_;
 wire _0933_;
 wire _0934_;
 wire _0935_;
 wire _0936_;
 wire _0937_;
 wire _0938_;
 wire _0939_;
 wire _0940_;
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
 wire _0951_;
 wire _0952_;
 wire _0953_;
 wire _0954_;
 wire _0955_;
 wire _0956_;
 wire _0957_;
 wire _0958_;
 wire _0959_;
 wire _0960_;
 wire _0961_;
 wire _0962_;
 wire _0963_;
 wire _0964_;
 wire _0965_;
 wire _0966_;
 wire _0967_;
 wire _0968_;
 wire _0969_;
 wire _0970_;
 wire _0971_;
 wire _0972_;
 wire _0973_;
 wire _0974_;
 wire _0975_;
 wire _0976_;
 wire _0977_;
 wire _0978_;
 wire _0979_;
 wire _0980_;
 wire _0981_;
 wire _0982_;
 wire _0983_;
 wire _0984_;
 wire _0985_;
 wire _0986_;
 wire _0987_;
 wire _0988_;
 wire _0989_;
 wire _0990_;
 wire _0991_;
 wire _0992_;
 wire _0993_;
 wire _0994_;
 wire _0995_;
 wire _0996_;
 wire _0997_;
 wire _0998_;
 wire _0999_;
 wire _1000_;
 wire _1001_;
 wire _1002_;
 wire _1003_;
 wire _1004_;
 wire _1005_;
 wire _1006_;
 wire _1007_;
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
 wire _1024_;
 wire _1025_;
 wire _1026_;
 wire _1027_;
 wire _1028_;
 wire _1029_;
 wire _1030_;
 wire _1031_;
 wire _1032_;
 wire _1033_;
 wire _1034_;
 wire _1035_;
 wire _1036_;
 wire _1037_;
 wire _1038_;
 wire _1039_;
 wire _1040_;
 wire _1041_;
 wire _1042_;
 wire _1043_;
 wire _1044_;
 wire _1045_;
 wire _1046_;
 wire _1047_;
 wire _1048_;
 wire _1049_;
 wire _1050_;
 wire _1051_;
 wire _1052_;
 wire _1053_;
 wire _1054_;
 wire _1055_;
 wire _1056_;
 wire _1057_;
 wire _1058_;
 wire _1059_;
 wire _1060_;
 wire _1061_;
 wire _1062_;
 wire _1063_;
 wire _1064_;
 wire _1065_;
 wire _1066_;
 wire _1067_;
 wire _1068_;
 wire _1069_;
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
 wire _1239_;
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
 wire net9;
 wire net4;
 wire core_rst_ni;
 wire hw2reg_28_;
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
 wire reg2hw_41_;
 wire reg2hw_42_;
 wire reg2hw_43_;
 wire reg2hw_44_;
 wire reg2hw_45_;
 wire reg2hw_46_;
 wire reg2hw_47_;
 wire reg2hw_48_;
 wire reg2hw_49_;
 wire reg2hw_4_;
 wire reg2hw_50_;
 wire reg2hw_51_;
 wire reg2hw_52_;
 wire reg2hw_53_;
 wire reg2hw_54_;
 wire reg2hw_55_;
 wire reg2hw_56_;
 wire reg2hw_5_;
 wire reg2hw_6_;
 wire reg2hw_7_;
 wire reg2hw_8_;
 wire reg2hw_9_;
 wire reg_rst_ni;
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
 wire u_uart_core_rx_fifo_data_0_;
 wire u_uart_core_rx_fifo_data_1_;
 wire u_uart_core_rx_fifo_data_2_;
 wire u_uart_core_rx_fifo_data_3_;
 wire u_uart_core_rx_fifo_data_4_;
 wire u_uart_core_rx_fifo_data_5_;
 wire u_uart_core_rx_fifo_data_6_;
 wire u_uart_core_rx_fifo_data_7_;
 wire u_uart_core_rx_rst_ni;
 wire u_uart_core_rx_sync;
 wire u_uart_core_rx_sync_q1;
 wire u_uart_core_rx_sync_q2;
 wire u_uart_core_rx_tick_baud;
 wire u_uart_core_rx_valid;
 wire u_uart_core_sync_rx_intq;
 wire u_uart_core_timing_rst_ni;
 wire u_uart_core_tx_out;
 wire u_uart_core_tx_out_q;
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
 wire u_uart_core_u_uart_rxfifo_gen_normal_fifo_under_rst;
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
 wire u_uart_core_u_uart_txfifo_gen_normal_fifo_under_rst;
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
 wire u_uart_core_uart_tx_sreg_q_0_;
 wire u_uart_core_uart_tx_sreg_q_1_;
 wire u_uart_core_uart_tx_sreg_q_2_;
 wire u_uart_core_uart_tx_sreg_q_3_;
 wire u_uart_core_uart_tx_sreg_q_4_;
 wire u_uart_core_uart_tx_sreg_q_5_;
 wire u_uart_core_uart_tx_sreg_q_6_;
 wire u_uart_core_uart_tx_sreg_q_7_;
 wire u_uart_core_uart_tx_sreg_q_8_;
 wire u_uart_core_uart_tx_sreg_q_9_;
 wire u_uart_core_uart_tx_tick_baud_q;
 wire u_uart_reg_axi_lite_o_0_;
 wire u_uart_reg_axi_lite_o_10_;
 wire u_uart_reg_axi_lite_o_11_;
 wire u_uart_reg_axi_lite_o_12_;
 wire u_uart_reg_axi_lite_o_13_;
 wire u_uart_reg_axi_lite_o_14_;
 wire u_uart_reg_axi_lite_o_15_;
 wire u_uart_reg_axi_lite_o_16_;
 wire u_uart_reg_axi_lite_o_17_;
 wire u_uart_reg_axi_lite_o_18_;
 wire u_uart_reg_axi_lite_o_19_;
 wire u_uart_reg_axi_lite_o_20_;
 wire u_uart_reg_axi_lite_o_21_;
 wire u_uart_reg_axi_lite_o_22_;
 wire u_uart_reg_axi_lite_o_23_;
 wire u_uart_reg_axi_lite_o_24_;
 wire u_uart_reg_axi_lite_o_25_;
 wire u_uart_reg_axi_lite_o_26_;
 wire u_uart_reg_axi_lite_o_27_;
 wire u_uart_reg_axi_lite_o_28_;
 wire u_uart_reg_axi_lite_o_29_;
 wire u_uart_reg_axi_lite_o_2_;
 wire u_uart_reg_axi_lite_o_30_;
 wire u_uart_reg_axi_lite_o_31_;
 wire u_uart_reg_axi_lite_o_32_;
 wire u_uart_reg_axi_lite_o_33_;
 wire u_uart_reg_axi_lite_o_34_;
 wire u_uart_reg_axi_lite_o_35_;
 wire u_uart_reg_axi_lite_o_36_;
 wire u_uart_reg_axi_lite_o_38_;
 wire u_uart_reg_axi_lite_o_39_;
 wire u_uart_reg_axi_lite_o_3_;
 wire u_uart_reg_axi_lite_o_4_;
 wire u_uart_reg_axi_lite_o_5_;
 wire u_uart_reg_axi_lite_o_6_;
 wire u_uart_reg_axi_lite_o_7_;
 wire u_uart_reg_axi_lite_o_8_;
 wire u_uart_reg_axi_lite_o_9_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_0_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_1_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_2_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_3_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_4_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_5_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_6_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_7_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_8_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_9_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_read_pointer_q;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_0_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_10_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_11_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_12_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_13_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_14_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_15_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_16_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_17_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_18_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_19_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_1_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_20_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_21_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_22_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_23_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_24_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_25_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_26_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_27_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_28_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_29_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_2_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_30_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_31_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_32_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_33_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_34_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_35_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_36_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_37_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_38_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_39_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_3_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_40_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_41_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_42_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_43_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_44_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_45_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_46_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_47_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_48_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_49_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_4_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_50_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_51_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_52_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_53_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_54_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_55_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_56_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_57_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_58_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_59_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_5_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_60_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_61_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_62_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_63_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_64_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_65_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_6_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_7_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_8_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_9_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_read_pointer_q;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_status_cnt_q_0_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_status_cnt_q_1_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_write_pointer_q;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_status_cnt_q_0_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_status_cnt_q_1_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_write_pointer_q;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_0_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_10_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_11_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_1_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_20_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_21_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_22_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_23_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_24_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_25_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_26_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_27_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_28_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_29_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_2_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_30_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_31_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_32_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_33_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_34_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_35_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_36_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_37_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_38_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_39_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_3_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_40_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_41_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_42_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_43_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_44_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_45_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_46_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_47_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_48_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_49_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_4_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_50_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_51_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_52_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_5_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_61_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_62_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_63_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_64_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_65_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_66_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_67_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_68_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_69_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_6_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_70_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_71_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_72_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_73_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_74_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_75_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_76_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_77_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_78_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_79_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_7_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_80_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_81_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_8_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_9_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_read_pointer_q;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_status_cnt_q_0_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_status_cnt_q_1_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_write_pointer_q;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_mem_q_0_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_mem_q_1_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_read_pointer_q;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_status_cnt_q_0_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_status_cnt_q_1_;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_write_pointer_q;
 wire u_uart_reg_u_flexsoc_axi_to_reg_i_stream_arbiter_i_arb_gen_rr_arb_i_arbiter_gen_arbiter_rr_q;
 wire u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_;
 wire u_uart_reg_u_reg_core_reg_we_check_3_;
 wire net;
 wire net1;
 wire net2;
 wire net3;
 wire net5;
 wire net6;
 wire net7;
 wire net8;
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
 wire net110;
 wire net111;
 wire net112;
 wire net113;
 wire net114;
 wire net115;
 wire net116;

 sky130_fd_sc_hd__nand2_1 _1375_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_31_),
    .Y(_0942_));
 sky130_fd_sc_hd__o21ai_0 _1376_ (.A1(net16),
    .A2(_0638_),
    .B1(_0942_),
    .Y(_0159_));
 sky130_fd_sc_hd__nand2_1 _1377_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_30_),
    .Y(_0943_));
 sky130_fd_sc_hd__o21ai_0 _1378_ (.A1(net16),
    .A2(_0644_),
    .B1(_0943_),
    .Y(_0160_));
 sky130_fd_sc_hd__nand2_1 _1379_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_29_),
    .Y(_0944_));
 sky130_fd_sc_hd__o21ai_0 _1380_ (.A1(net16),
    .A2(_0646_),
    .B1(_0944_),
    .Y(_0161_));
 sky130_fd_sc_hd__nand2_1 _1381_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_28_),
    .Y(_0945_));
 sky130_fd_sc_hd__o21ai_0 _1382_ (.A1(net16),
    .A2(_0648_),
    .B1(_0945_),
    .Y(_0162_));
 sky130_fd_sc_hd__nand2_1 _1383_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_27_),
    .Y(_0946_));
 sky130_fd_sc_hd__o21ai_0 _1384_ (.A1(net16),
    .A2(_0650_),
    .B1(_0946_),
    .Y(_0163_));
 sky130_fd_sc_hd__nand2_1 _1385_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_26_),
    .Y(_0947_));
 sky130_fd_sc_hd__o21ai_0 _1386_ (.A1(net16),
    .A2(_0652_),
    .B1(_0947_),
    .Y(_0164_));
 sky130_fd_sc_hd__nand2_1 _1387_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_25_),
    .Y(_0948_));
 sky130_fd_sc_hd__o21ai_0 _1388_ (.A1(net16),
    .A2(_0654_),
    .B1(_0948_),
    .Y(_0165_));
 sky130_fd_sc_hd__nand2_1 _1389_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_24_),
    .Y(_0949_));
 sky130_fd_sc_hd__o21ai_0 _1390_ (.A1(net16),
    .A2(_0656_),
    .B1(_0949_),
    .Y(_0166_));
 sky130_fd_sc_hd__nand2_1 _1391_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_23_),
    .Y(_0950_));
 sky130_fd_sc_hd__o21ai_0 _1392_ (.A1(_0940_),
    .A2(_0658_),
    .B1(_0950_),
    .Y(_0167_));
 sky130_fd_sc_hd__nand2_1 _1393_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_22_),
    .Y(_0951_));
 sky130_fd_sc_hd__o21ai_0 _1394_ (.A1(_0940_),
    .A2(_0660_),
    .B1(_0951_),
    .Y(_0168_));
 sky130_fd_sc_hd__nand2_1 _1395_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_21_),
    .Y(_0952_));
 sky130_fd_sc_hd__o21ai_0 _1396_ (.A1(_0940_),
    .A2(_0674_),
    .B1(_0952_),
    .Y(_0169_));
 sky130_fd_sc_hd__nand2_1 _1397_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_20_),
    .Y(_0953_));
 sky130_fd_sc_hd__o21ai_0 _1398_ (.A1(_0940_),
    .A2(_0678_),
    .B1(_0953_),
    .Y(_0170_));
 sky130_fd_sc_hd__nand2_1 _1399_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_19_),
    .Y(_0954_));
 sky130_fd_sc_hd__o21ai_0 _1400_ (.A1(_0940_),
    .A2(_0681_),
    .B1(_0954_),
    .Y(_0171_));
 sky130_fd_sc_hd__nand2_1 _1401_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_18_),
    .Y(_0955_));
 sky130_fd_sc_hd__o21ai_0 _1402_ (.A1(_0940_),
    .A2(_0685_),
    .B1(_0955_),
    .Y(_0172_));
 sky130_fd_sc_hd__nand2_1 _1403_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_17_),
    .Y(_0956_));
 sky130_fd_sc_hd__o21ai_0 _1404_ (.A1(_0940_),
    .A2(_0688_),
    .B1(_0956_),
    .Y(_0173_));
 sky130_fd_sc_hd__nand2_4 _1405_ (.A(_0637_),
    .B(_0939_),
    .Y(_0957_));
 sky130_fd_sc_hd__o21ai_0 _1406_ (.A1(_0334_),
    .A2(_0939_),
    .B1(_0957_),
    .Y(_0174_));
 sky130_fd_sc_hd__o21ai_0 _1407_ (.A1(_0336_),
    .A2(_0939_),
    .B1(_0957_),
    .Y(_0175_));
 sky130_fd_sc_hd__o21ai_0 _1408_ (.A1(_0338_),
    .A2(_0939_),
    .B1(_0957_),
    .Y(_0176_));
 sky130_fd_sc_hd__o21ai_0 _1409_ (.A1(_0340_),
    .A2(_0939_),
    .B1(_0957_),
    .Y(_0177_));
 sky130_fd_sc_hd__o21ai_0 _1410_ (.A1(_0342_),
    .A2(_0939_),
    .B1(_0957_),
    .Y(_0178_));
 sky130_fd_sc_hd__o21ai_0 _1411_ (.A1(_0344_),
    .A2(_0939_),
    .B1(_0957_),
    .Y(_0179_));
 sky130_fd_sc_hd__o21ai_0 _1412_ (.A1(_0346_),
    .A2(_0939_),
    .B1(_0957_),
    .Y(_0180_));
 sky130_fd_sc_hd__o21ai_0 _1413_ (.A1(_0348_),
    .A2(_0939_),
    .B1(_0957_),
    .Y(_0181_));
 sky130_fd_sc_hd__nand2_1 _1414_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_8_),
    .Y(_0958_));
 sky130_fd_sc_hd__o21ai_0 _1415_ (.A1(_0940_),
    .A2(_0728_),
    .B1(_0958_),
    .Y(_0182_));
 sky130_fd_sc_hd__nand2_1 _1416_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_7_),
    .Y(_0959_));
 sky130_fd_sc_hd__o21ai_0 _1417_ (.A1(_0940_),
    .A2(_0752_),
    .B1(_0959_),
    .Y(_0183_));
 sky130_fd_sc_hd__nand2_1 _1418_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_6_),
    .Y(_0960_));
 sky130_fd_sc_hd__o21ai_0 _1419_ (.A1(_0940_),
    .A2(_0781_),
    .B1(_0960_),
    .Y(_0184_));
 sky130_fd_sc_hd__nand2_1 _1420_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_5_),
    .Y(_0961_));
 sky130_fd_sc_hd__o21ai_0 _1421_ (.A1(_0940_),
    .A2(_0813_),
    .B1(_0961_),
    .Y(_0185_));
 sky130_fd_sc_hd__nand2_1 _1422_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_4_),
    .Y(_0962_));
 sky130_fd_sc_hd__o21ai_0 _1423_ (.A1(_0940_),
    .A2(_0856_),
    .B1(_0962_),
    .Y(_0186_));
 sky130_fd_sc_hd__nand2_1 _1424_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_3_),
    .Y(_0963_));
 sky130_fd_sc_hd__o21ai_0 _1425_ (.A1(_0940_),
    .A2(_0883_),
    .B1(_0963_),
    .Y(_0187_));
 sky130_fd_sc_hd__nand2_1 _1426_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_2_),
    .Y(_0964_));
 sky130_fd_sc_hd__o21ai_0 _1427_ (.A1(_0940_),
    .A2(_0912_),
    .B1(_0964_),
    .Y(_0188_));
 sky130_fd_sc_hd__nand2_1 _1428_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_1_),
    .Y(_0965_));
 sky130_fd_sc_hd__o21ai_0 _1429_ (.A1(_0940_),
    .A2(_0937_),
    .B1(_0965_),
    .Y(_0189_));
 sky130_fd_sc_hd__nand2_4 _1430_ (.A(u_uart_reg_axi_lite_o_35_),
    .B(axi_lite_i[1]),
    .Y(_0966_));
 sky130_fd_sc_hd__nor2_1 _1431_ (.A(_0966_),
    .B(_0632_),
    .Y(_0967_));
 sky130_fd_sc_hd__inv_1 _1432_ (.A(_0967_),
    .Y(_0968_));
 sky130_fd_sc_hd__nand2_1 _1433_ (.A(_0632_),
    .B(_0966_),
    .Y(_0969_));
 sky130_fd_sc_hd__nand2_1 _1434_ (.A(_0968_),
    .B(_0969_),
    .Y(_0970_));
 sky130_fd_sc_hd__xor2_1 _1435_ (.A(net91),
    .B(_0970_),
    .X(_0190_));
 sky130_fd_sc_hd__inv_1 _1436_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_write_pointer_q),
    .Y(_0971_));
 sky130_fd_sc_hd__nor2_4 _1437_ (.A(_0971_),
    .B(_0966_),
    .Y(_0972_));
 sky130_fd_sc_hd__nand2_1 _1438_ (.A(_0972_),
    .B(axi_lite_i[8]),
    .Y(_0973_));
 sky130_fd_sc_hd__o21ai_0 _1439_ (.A1(_0458_),
    .A2(_0972_),
    .B1(_0973_),
    .Y(_0191_));
 sky130_fd_sc_hd__nand2_1 _1440_ (.A(_0972_),
    .B(axi_lite_i[7]),
    .Y(_0974_));
 sky130_fd_sc_hd__o21ai_0 _1441_ (.A1(_0462_),
    .A2(_0972_),
    .B1(_0974_),
    .Y(_0192_));
 sky130_fd_sc_hd__mux2_1 _1442_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_6_),
    .A1(axi_lite_i[6]),
    .S(_0972_),
    .X(_0193_));
 sky130_fd_sc_hd__mux2_1 _1443_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_5_),
    .A1(axi_lite_i[5]),
    .S(_0972_),
    .X(_0194_));
 sky130_fd_sc_hd__nor2_2 _1444_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_write_pointer_q),
    .B(_0966_),
    .Y(_0975_));
 sky130_fd_sc_hd__inv_2 _1445_ (.A(_0975_),
    .Y(_0976_));
 sky130_fd_sc_hd__nand2_1 _1446_ (.A(_0976_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_3_),
    .Y(_0977_));
 sky130_fd_sc_hd__nand2_1 _1447_ (.A(_0975_),
    .B(axi_lite_i[8]),
    .Y(_0978_));
 sky130_fd_sc_hd__nand2_1 _1448_ (.A(_0977_),
    .B(_0978_),
    .Y(_0195_));
 sky130_fd_sc_hd__nand2_1 _1449_ (.A(_0976_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_2_),
    .Y(_0979_));
 sky130_fd_sc_hd__nand2_1 _1450_ (.A(_0975_),
    .B(axi_lite_i[7]),
    .Y(_0980_));
 sky130_fd_sc_hd__nand2_1 _1451_ (.A(_0979_),
    .B(_0980_),
    .Y(_0196_));
 sky130_fd_sc_hd__nand2_1 _1452_ (.A(_0976_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_1_),
    .Y(_0981_));
 sky130_fd_sc_hd__nand2_1 _1453_ (.A(_0975_),
    .B(axi_lite_i[6]),
    .Y(_0982_));
 sky130_fd_sc_hd__nand2_1 _1454_ (.A(_0981_),
    .B(_0982_),
    .Y(_0197_));
 sky130_fd_sc_hd__nand2_1 _1455_ (.A(_0976_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_0_),
    .Y(_0983_));
 sky130_fd_sc_hd__nand2_1 _1456_ (.A(_0975_),
    .B(axi_lite_i[5]),
    .Y(_0984_));
 sky130_fd_sc_hd__nand2_1 _1457_ (.A(_0983_),
    .B(_0984_),
    .Y(_0198_));
 sky130_fd_sc_hd__nand2_1 _1458_ (.A(_0817_),
    .B(_0824_),
    .Y(_0985_));
 sky130_fd_sc_hd__nand2_1 _1459_ (.A(_0823_),
    .B(u_uart_core_uart_tx_tick_baud_q),
    .Y(_0986_));
 sky130_fd_sc_hd__clkinv_2 _1460_ (.A(_0986_),
    .Y(_0987_));
 sky130_fd_sc_hd__nor2_2 _1461_ (.A(net44),
    .B(_0987_),
    .Y(_0988_));
 sky130_fd_sc_hd__nand2_4 _1462_ (.A(net21),
    .B(_0988_),
    .Y(_0989_));
 sky130_fd_sc_hd__clkinv_2 _1463_ (.A(_0989_),
    .Y(_0990_));
 sky130_fd_sc_hd__nor2_1 _1464_ (.A(net44),
    .B(_0990_),
    .Y(_0991_));
 sky130_fd_sc_hd__o21ai_0 _1465_ (.A1(u_uart_core_uart_tx_bit_cnt_q_1_),
    .A2(u_uart_core_uart_tx_bit_cnt_q_0_),
    .B1(u_uart_core_uart_tx_bit_cnt_q_2_),
    .Y(_0992_));
 sky130_fd_sc_hd__inv_1 _1466_ (.A(net21),
    .Y(_0993_));
 sky130_fd_sc_hd__a21oi_1 _1467_ (.A1(_0821_),
    .A2(_0992_),
    .B1(_0993_),
    .Y(_0994_));
 sky130_fd_sc_hd__nand2_1 _1468_ (.A(_0991_),
    .B(_0994_),
    .Y(_0995_));
 sky130_fd_sc_hd__o21ai_0 _1469_ (.A1(_0820_),
    .A2(_0989_),
    .B1(_0995_),
    .Y(_0199_));
 sky130_fd_sc_hd__inv_1 _1470_ (.A(u_uart_core_uart_tx_bit_cnt_q_1_),
    .Y(_0996_));
 sky130_fd_sc_hd__inv_1 _1471_ (.A(u_uart_core_uart_tx_bit_cnt_q_0_),
    .Y(_0997_));
 sky130_fd_sc_hd__o21ai_0 _1472_ (.A1(_0996_),
    .A2(_0997_),
    .B1(net21),
    .Y(_0998_));
 sky130_fd_sc_hd__o21ai_0 _1473_ (.A1(_0819_),
    .A2(_0998_),
    .B1(_0991_),
    .Y(_0999_));
 sky130_fd_sc_hd__o21ai_0 _1474_ (.A1(_0996_),
    .A2(_0989_),
    .B1(_0999_),
    .Y(_0200_));
 sky130_fd_sc_hd__inv_1 _1475_ (.A(_0991_),
    .Y(_1000_));
 sky130_fd_sc_hd__nor2_1 _1476_ (.A(net44),
    .B(net21),
    .Y(_1001_));
 sky130_fd_sc_hd__inv_1 _1477_ (.A(_1001_),
    .Y(_1002_));
 sky130_fd_sc_hd__nor2_1 _1478_ (.A(_0378_),
    .B(_1002_),
    .Y(_1003_));
 sky130_fd_sc_hd__a21oi_1 _1479_ (.A1(_0997_),
    .A2(_1002_),
    .B1(_1003_),
    .Y(_1004_));
 sky130_fd_sc_hd__o22ai_1 _1480_ (.A1(_0997_),
    .A2(_0989_),
    .B1(_1000_),
    .B2(_1004_),
    .Y(_0201_));
 sky130_fd_sc_hd__nand3_1 _1481_ (.A(u_uart_core_uart_tx_baud_div_q_1_),
    .B(u_uart_core_uart_tx_baud_div_q_0_),
    .C(net59),
    .Y(_1005_));
 sky130_fd_sc_hd__xnor2_1 _1482_ (.A(u_uart_core_uart_tx_baud_div_q_2_),
    .B(_1005_),
    .Y(_0202_));
 sky130_fd_sc_hd__a21oi_1 _1483_ (.A1(u_uart_core_uart_tx_baud_div_q_0_),
    .A2(net59),
    .B1(u_uart_core_uart_tx_baud_div_q_1_),
    .Y(_1006_));
 sky130_fd_sc_hd__inv_1 _1484_ (.A(_1005_),
    .Y(_1007_));
 sky130_fd_sc_hd__nor2_1 _1485_ (.A(_1006_),
    .B(_1007_),
    .Y(_0203_));
 sky130_fd_sc_hd__xor2_1 _1486_ (.A(u_uart_core_uart_tx_baud_div_q_0_),
    .B(net59),
    .X(_0204_));
 sky130_fd_sc_hd__inv_1 _1487_ (.A(u_uart_core_rx_tick_baud),
    .Y(_1008_));
 sky130_fd_sc_hd__nor2_1 _1488_ (.A(hw2reg_28_),
    .B(_1008_),
    .Y(_1009_));
 sky130_fd_sc_hd__inv_1 _1489_ (.A(_1009_),
    .Y(_1010_));
 sky130_fd_sc_hd__xor2_1 _1490_ (.A(net102),
    .B(net76),
    .X(_1011_));
 sky130_fd_sc_hd__inv_1 _1491_ (.A(u_uart_core_uart_rx_bit_cnt_q_2_),
    .Y(_1012_));
 sky130_fd_sc_hd__nand3_1 _1492_ (.A(_1012_),
    .B(net101),
    .C(net100),
    .Y(_1013_));
 sky130_fd_sc_hd__inv_1 _1493_ (.A(u_uart_core_rx_sync_q2),
    .Y(_1014_));
 sky130_fd_sc_hd__a21oi_1 _1494_ (.A1(reg2hw_36_),
    .A2(u_uart_core_rx_sync_q1),
    .B1(u_uart_core_rx_sync),
    .Y(_1015_));
 sky130_fd_sc_hd__o21ai_0 _1495_ (.A1(u_uart_core_rx_sync_q1),
    .A2(_0878_),
    .B1(u_uart_core_rx_sync),
    .Y(_1016_));
 sky130_fd_sc_hd__o2111ai_1 _1496_ (.A1(_1014_),
    .A2(_1015_),
    .B1(_0776_),
    .C1(_0810_),
    .D1(_1016_),
    .Y(_1017_));
 sky130_fd_sc_hd__o21ai_2 _1497_ (.A1(_0810_),
    .A2(u_uart_core_tx_out),
    .B1(_1017_),
    .Y(_1018_));
 sky130_fd_sc_hd__nor3_2 _1498_ (.A(_1011_),
    .B(_1013_),
    .C(_1018_),
    .Y(_1019_));
 sky130_fd_sc_hd__nor2_2 _1499_ (.A(_1010_),
    .B(_1019_),
    .Y(_1020_));
 sky130_fd_sc_hd__inv_4 _1500_ (.A(_1020_),
    .Y(_1021_));
 sky130_fd_sc_hd__clkinv_1 _1501_ (.A(u_uart_core_uart_rx_sreg_q_9_),
    .Y(_1022_));
 sky130_fd_sc_hd__clkinv_1 _1502_ (.A(_1018_),
    .Y(_1023_));
 sky130_fd_sc_hd__nor2_4 _1503_ (.A(_0811_),
    .B(_1023_),
    .Y(_1024_));
 sky130_fd_sc_hd__nor2_2 _1504_ (.A(_1009_),
    .B(_1024_),
    .Y(_1025_));
 sky130_fd_sc_hd__nor2_4 _1505_ (.A(_1019_),
    .B(_1025_),
    .Y(_1026_));
 sky130_fd_sc_hd__o22ai_1 _1506_ (.A1(_0381_),
    .A2(_1021_),
    .B1(_1022_),
    .B2(_1026_),
    .Y(_0205_));
 sky130_fd_sc_hd__o22ai_1 _1507_ (.A1(_1022_),
    .A2(_1021_),
    .B1(_0411_),
    .B2(_1026_),
    .Y(_0206_));
 sky130_fd_sc_hd__o22ai_1 _1508_ (.A1(_0411_),
    .A2(_1021_),
    .B1(_0414_),
    .B2(_1026_),
    .Y(_0207_));
 sky130_fd_sc_hd__o22ai_1 _1509_ (.A1(_0414_),
    .A2(_1021_),
    .B1(_0416_),
    .B2(_1026_),
    .Y(_0208_));
 sky130_fd_sc_hd__o22ai_1 _1510_ (.A1(_0416_),
    .A2(_1021_),
    .B1(_0418_),
    .B2(_1026_),
    .Y(_0209_));
 sky130_fd_sc_hd__o22ai_1 _1511_ (.A1(_0418_),
    .A2(_1021_),
    .B1(_0420_),
    .B2(_1026_),
    .Y(_0210_));
 sky130_fd_sc_hd__o22ai_1 _1512_ (.A1(_0420_),
    .A2(_1021_),
    .B1(_0422_),
    .B2(_1026_),
    .Y(_0211_));
 sky130_fd_sc_hd__o22ai_1 _1513_ (.A1(_0422_),
    .A2(_1021_),
    .B1(_0424_),
    .B2(_1026_),
    .Y(_0212_));
 sky130_fd_sc_hd__inv_1 _1514_ (.A(u_uart_core_uart_rx_sreg_q_1_),
    .Y(_1027_));
 sky130_fd_sc_hd__o22ai_1 _1515_ (.A1(_0424_),
    .A2(_1021_),
    .B1(_1027_),
    .B2(_1026_),
    .Y(_0213_));
 sky130_fd_sc_hd__nor2_1 _1516_ (.A(net102),
    .B(net101),
    .Y(_1028_));
 sky130_fd_sc_hd__inv_1 _1517_ (.A(_1028_),
    .Y(_1029_));
 sky130_fd_sc_hd__a21oi_1 _1518_ (.A1(_1020_),
    .A2(_1029_),
    .B1(_1025_),
    .Y(_1030_));
 sky130_fd_sc_hd__nor2_1 _1519_ (.A(u_uart_core_uart_rx_bit_cnt_q_2_),
    .B(_1029_),
    .Y(_1031_));
 sky130_fd_sc_hd__nand2_1 _1520_ (.A(_1020_),
    .B(_1031_),
    .Y(_1032_));
 sky130_fd_sc_hd__o21ai_0 _1521_ (.A1(_1012_),
    .A2(_1030_),
    .B1(_1032_),
    .Y(_0214_));
 sky130_fd_sc_hd__inv_1 _1522_ (.A(net102),
    .Y(_1033_));
 sky130_fd_sc_hd__nor2_1 _1523_ (.A(net101),
    .B(_1033_),
    .Y(_1034_));
 sky130_fd_sc_hd__inv_1 _1524_ (.A(net101),
    .Y(_1035_));
 sky130_fd_sc_hd__nor2_1 _1525_ (.A(net102),
    .B(_1035_),
    .Y(_1036_));
 sky130_fd_sc_hd__a21oi_1 _1526_ (.A1(net101),
    .A2(_1010_),
    .B1(_1024_),
    .Y(_1037_));
 sky130_fd_sc_hd__o31ai_1 _1527_ (.A1(_1034_),
    .A2(_1036_),
    .A3(_1021_),
    .B1(_1037_),
    .Y(_0215_));
 sky130_fd_sc_hd__nand2_1 _1528_ (.A(_1025_),
    .B(net102),
    .Y(_1038_));
 sky130_fd_sc_hd__a22oi_1 _1529_ (.A1(_1024_),
    .A2(net76),
    .B1(_1020_),
    .B2(_1033_),
    .Y(_1039_));
 sky130_fd_sc_hd__nand2_1 _1530_ (.A(_1038_),
    .B(_1039_),
    .Y(_0216_));
 sky130_fd_sc_hd__nand2_1 _1531_ (.A(u_uart_core_uart_rx_baud_div_q_0_),
    .B(net59),
    .Y(_1040_));
 sky130_fd_sc_hd__inv_1 _1532_ (.A(_1040_),
    .Y(_1041_));
 sky130_fd_sc_hd__nand2_1 _1533_ (.A(_1041_),
    .B(u_uart_core_uart_rx_baud_div_q_1_),
    .Y(_1042_));
 sky130_fd_sc_hd__clkinv_1 _1534_ (.A(_1042_),
    .Y(_1043_));
 sky130_fd_sc_hd__a21oi_1 _1535_ (.A1(u_uart_core_uart_rx_baud_div_q_2_),
    .A2(_1043_),
    .B1(_1024_),
    .Y(_1044_));
 sky130_fd_sc_hd__o21a_1 _1536_ (.A1(u_uart_core_uart_rx_baud_div_q_2_),
    .A2(_1043_),
    .B1(_1044_),
    .X(_0217_));
 sky130_fd_sc_hd__nor2_1 _1537_ (.A(u_uart_core_uart_rx_baud_div_q_1_),
    .B(_1041_),
    .Y(_1045_));
 sky130_fd_sc_hd__nor3_1 _1538_ (.A(_1043_),
    .B(_1045_),
    .C(_1024_),
    .Y(_0218_));
 sky130_fd_sc_hd__nor2_1 _1539_ (.A(u_uart_core_uart_rx_baud_div_q_0_),
    .B(net59),
    .Y(_1046_));
 sky130_fd_sc_hd__nor3_1 _1540_ (.A(_1041_),
    .B(_1046_),
    .C(_1024_),
    .Y(_0219_));
 sky130_fd_sc_hd__nor2_1 _1541_ (.A(net103),
    .B(_0296_),
    .Y(_1047_));
 sky130_fd_sc_hd__inv_2 _1542_ (.A(reg2hw_3_),
    .Y(_1048_));
 sky130_fd_sc_hd__inv_2 _1543_ (.A(reg2hw_0_),
    .Y(_1049_));
 sky130_fd_sc_hd__nor2_2 _1544_ (.A(_1048_),
    .B(_1049_),
    .Y(_1050_));
 sky130_fd_sc_hd__nor3_1 _1545_ (.A(_1047_),
    .B(_1050_),
    .C(_0018_),
    .Y(_0220_));
 sky130_fd_sc_hd__nor2_1 _1546_ (.A(net104),
    .B(_0294_),
    .Y(_1051_));
 sky130_fd_sc_hd__nor3_1 _1547_ (.A(_1050_),
    .B(_1051_),
    .C(_0296_),
    .Y(_0221_));
 sky130_fd_sc_hd__o21ai_0 _1548_ (.A1(_1048_),
    .A2(_1049_),
    .B1(_0295_),
    .Y(_1052_));
 sky130_fd_sc_hd__a21oi_1 _1549_ (.A1(_1355_),
    .A2(net27),
    .B1(_1052_),
    .Y(_0222_));
 sky130_fd_sc_hd__nor2_1 _1550_ (.A(net29),
    .B(_1002_),
    .Y(_1053_));
 sky130_fd_sc_hd__nand2_1 _1551_ (.A(_1053_),
    .B(net107),
    .Y(_1054_));
 sky130_fd_sc_hd__nor2_1 _1552_ (.A(net47),
    .B(_1054_),
    .Y(_1055_));
 sky130_fd_sc_hd__inv_1 _1553_ (.A(_1054_),
    .Y(_1056_));
 sky130_fd_sc_hd__nor2_1 _1554_ (.A(net106),
    .B(_1056_),
    .Y(_1057_));
 sky130_fd_sc_hd__nor3_1 _1555_ (.A(_1050_),
    .B(_1055_),
    .C(_1057_),
    .Y(_0223_));
 sky130_fd_sc_hd__nor2_1 _1556_ (.A(net107),
    .B(_1053_),
    .Y(_1058_));
 sky130_fd_sc_hd__nor3_1 _1557_ (.A(_1050_),
    .B(_1058_),
    .C(_1056_),
    .Y(_0224_));
 sky130_fd_sc_hd__nor2_1 _1558_ (.A(net108),
    .B(_1001_),
    .Y(_1059_));
 sky130_fd_sc_hd__nor3_1 _1559_ (.A(_1050_),
    .B(_1059_),
    .C(_1053_),
    .Y(_0225_));
 sky130_fd_sc_hd__inv_1 _1560_ (.A(reg2hw_1_),
    .Y(_1060_));
 sky130_fd_sc_hd__nor2_2 _1561_ (.A(_1060_),
    .B(_1049_),
    .Y(_1061_));
 sky130_fd_sc_hd__nor2_1 _1562_ (.A(_0393_),
    .B(net14),
    .Y(_1062_));
 sky130_fd_sc_hd__nor2_1 _1563_ (.A(net109),
    .B(_1062_),
    .Y(_1063_));
 sky130_fd_sc_hd__nor3_1 _1564_ (.A(_0035_),
    .B(_1061_),
    .C(_1063_),
    .Y(_0226_));
 sky130_fd_sc_hd__inv_1 _1565_ (.A(net14),
    .Y(_1064_));
 sky130_fd_sc_hd__nor2_1 _1566_ (.A(net110),
    .B(_1064_),
    .Y(_1065_));
 sky130_fd_sc_hd__nor3_1 _1567_ (.A(_1062_),
    .B(_1061_),
    .C(_1065_),
    .Y(_0227_));
 sky130_fd_sc_hd__nor2_1 _1568_ (.A(net111),
    .B(_0406_),
    .Y(_1066_));
 sky130_fd_sc_hd__nor3_1 _1569_ (.A(_1061_),
    .B(_1066_),
    .C(_1064_),
    .Y(_0228_));
 sky130_fd_sc_hd__nor2_1 _1570_ (.A(net112),
    .B(_0401_),
    .Y(_1067_));
 sky130_fd_sc_hd__nor3_1 _1571_ (.A(_0406_),
    .B(_1061_),
    .C(_1067_),
    .Y(_0229_));
 sky130_fd_sc_hd__nand3_1 _1572_ (.A(_0779_),
    .B(_0778_),
    .C(_0632_),
    .Y(_1068_));
 sky130_fd_sc_hd__nor2_1 _1573_ (.A(_1068_),
    .B(_0700_),
    .Y(_1069_));
 sky130_fd_sc_hd__nand2_1 _1574_ (.A(_1069_),
    .B(net116),
    .Y(_1070_));
 sky130_fd_sc_hd__nor2_1 _1575_ (.A(_0664_),
    .B(_1070_),
    .Y(_1071_));
 sky130_fd_sc_hd__nand2_1 _1576_ (.A(_1071_),
    .B(net114),
    .Y(_1072_));
 sky130_fd_sc_hd__inv_1 _1577_ (.A(_1061_),
    .Y(_1073_));
 sky130_fd_sc_hd__o21ai_0 _1578_ (.A1(_0388_),
    .A2(_1072_),
    .B1(_1073_),
    .Y(_1074_));
 sky130_fd_sc_hd__a21oi_1 _1579_ (.A1(_0388_),
    .A2(_1072_),
    .B1(_1074_),
    .Y(_0230_));
 sky130_fd_sc_hd__o21ai_0 _1580_ (.A1(net114),
    .A2(_1071_),
    .B1(_1073_),
    .Y(_1075_));
 sky130_fd_sc_hd__a21oi_1 _1581_ (.A1(net114),
    .A2(_1071_),
    .B1(_1075_),
    .Y(_0231_));
 sky130_fd_sc_hd__inv_1 _1582_ (.A(_1070_),
    .Y(_1076_));
 sky130_fd_sc_hd__nor2_1 _1583_ (.A(net115),
    .B(_1076_),
    .Y(_1077_));
 sky130_fd_sc_hd__nor3_1 _1584_ (.A(_1061_),
    .B(_1071_),
    .C(_1077_),
    .Y(_0232_));
 sky130_fd_sc_hd__nor2_1 _1585_ (.A(net116),
    .B(_1069_),
    .Y(_1078_));
 sky130_fd_sc_hd__nor3_1 _1586_ (.A(_1076_),
    .B(_1078_),
    .C(_1074_),
    .Y(_0233_));
 sky130_fd_sc_hd__xor2_1 _1587_ (.A(_1311_),
    .B(_1307_),
    .X(_0010_));
 sky130_fd_sc_hd__inv_1 _1588_ (.A(_1294_),
    .Y(_1079_));
 sky130_fd_sc_hd__xor2_1 _1589_ (.A(_1079_),
    .B(_1329_),
    .X(_0016_));
 sky130_fd_sc_hd__nor3_1 _1590_ (.A(_1297_),
    .B(_1301_),
    .C(_1313_),
    .Y(_1080_));
 sky130_fd_sc_hd__nor2_1 _1591_ (.A(_1080_),
    .B(_1315_),
    .Y(_0012_));
 sky130_fd_sc_hd__o21ai_0 _1592_ (.A1(_1348_),
    .A2(_1352_),
    .B1(_1349_),
    .Y(_0001_));
 sky130_fd_sc_hd__nand2_1 _1593_ (.A(_1320_),
    .B(_1326_),
    .Y(_1081_));
 sky130_fd_sc_hd__nand2_1 _1594_ (.A(_1081_),
    .B(_1327_),
    .Y(_1082_));
 sky130_fd_sc_hd__xor2_1 _1595_ (.A(_1325_),
    .B(_1082_),
    .X(_0015_));
 sky130_fd_sc_hd__nand2_1 _1596_ (.A(_0300_),
    .B(_1283_),
    .Y(_1083_));
 sky130_fd_sc_hd__nand2_1 _1597_ (.A(_1083_),
    .B(_1330_),
    .Y(_1084_));
 sky130_fd_sc_hd__xor2_1 _1598_ (.A(_1282_),
    .B(_1084_),
    .X(_0004_));
 sky130_fd_sc_hd__clkinv_2 _1599_ (.A(_0816_),
    .Y(_1085_));
 sky130_fd_sc_hd__o21ai_0 _1600_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_23_),
    .B1(net107),
    .Y(_1086_));
 sky130_fd_sc_hd__nor2_1 _1601_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_31_),
    .B(net29),
    .Y(_1087_));
 sky130_fd_sc_hd__o21ai_0 _1602_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_7_),
    .B1(_1359_),
    .Y(_1088_));
 sky130_fd_sc_hd__nor2_1 _1603_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_15_),
    .B(net29),
    .Y(_1089_));
 sky130_fd_sc_hd__o221ai_1 _1604_ (.A1(_1086_),
    .A2(_1087_),
    .B1(_1088_),
    .B2(_1089_),
    .C1(net47),
    .Y(_1090_));
 sky130_fd_sc_hd__o21ai_0 _1605_ (.A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_55_),
    .A2(net108),
    .B1(net107),
    .Y(_1091_));
 sky130_fd_sc_hd__nor2_1 _1606_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_63_),
    .B(net29),
    .Y(_1092_));
 sky130_fd_sc_hd__o21ai_0 _1607_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_39_),
    .B1(_1359_),
    .Y(_1093_));
 sky130_fd_sc_hd__nor2_1 _1608_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_47_),
    .B(net29),
    .Y(_1094_));
 sky130_fd_sc_hd__o221ai_1 _1609_ (.A1(_1091_),
    .A2(_1092_),
    .B1(_1093_),
    .B2(_1094_),
    .C1(net106),
    .Y(_1095_));
 sky130_fd_sc_hd__nand3_1 _1610_ (.A(_1085_),
    .B(_1090_),
    .C(_1095_),
    .Y(_1096_));
 sky130_fd_sc_hd__a21oi_1 _1611_ (.A1(_0987_),
    .A2(u_uart_core_uart_tx_sreg_q_9_),
    .B1(net44),
    .Y(_1097_));
 sky130_fd_sc_hd__nand2_1 _1612_ (.A(_0990_),
    .B(u_uart_core_uart_tx_sreg_q_8_),
    .Y(_1098_));
 sky130_fd_sc_hd__o211ai_1 _1613_ (.A1(net21),
    .A2(_1096_),
    .B1(_1097_),
    .C1(_1098_),
    .Y(_0234_));
 sky130_fd_sc_hd__o21ai_0 _1614_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_22_),
    .B1(net107),
    .Y(_1099_));
 sky130_fd_sc_hd__nor2_1 _1615_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_30_),
    .B(net29),
    .Y(_1100_));
 sky130_fd_sc_hd__o21ai_0 _1616_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_6_),
    .B1(_1359_),
    .Y(_1101_));
 sky130_fd_sc_hd__nor2_1 _1617_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_14_),
    .B(net29),
    .Y(_1102_));
 sky130_fd_sc_hd__o221ai_1 _1618_ (.A1(_1099_),
    .A2(_1100_),
    .B1(_1101_),
    .B2(_1102_),
    .C1(net47),
    .Y(_1103_));
 sky130_fd_sc_hd__o21ai_0 _1619_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_54_),
    .B1(net107),
    .Y(_1104_));
 sky130_fd_sc_hd__nor2_1 _1620_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_62_),
    .B(net29),
    .Y(_1105_));
 sky130_fd_sc_hd__o21ai_0 _1621_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_38_),
    .B1(_1359_),
    .Y(_1106_));
 sky130_fd_sc_hd__nor2_1 _1622_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_46_),
    .B(net29),
    .Y(_1107_));
 sky130_fd_sc_hd__o221ai_1 _1623_ (.A1(_1104_),
    .A2(_1105_),
    .B1(_1106_),
    .B2(_1107_),
    .C1(net106),
    .Y(_1108_));
 sky130_fd_sc_hd__nand3_1 _1624_ (.A(_1085_),
    .B(_1103_),
    .C(_1108_),
    .Y(_1109_));
 sky130_fd_sc_hd__nand3_1 _1625_ (.A(net21),
    .B(u_uart_core_uart_tx_sreg_q_8_),
    .C(_0987_),
    .Y(_1110_));
 sky130_fd_sc_hd__nand2_1 _1626_ (.A(_0990_),
    .B(u_uart_core_uart_tx_sreg_q_7_),
    .Y(_1111_));
 sky130_fd_sc_hd__o2111ai_1 _1627_ (.A1(net21),
    .A2(_1109_),
    .B1(net74),
    .C1(_1110_),
    .D1(_1111_),
    .Y(_0235_));
 sky130_fd_sc_hd__o21ai_0 _1628_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_21_),
    .B1(net107),
    .Y(_1112_));
 sky130_fd_sc_hd__nor2_1 _1629_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_29_),
    .B(_1362_),
    .Y(_1113_));
 sky130_fd_sc_hd__o21ai_0 _1630_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_5_),
    .B1(_1359_),
    .Y(_1114_));
 sky130_fd_sc_hd__nor2_1 _1631_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_13_),
    .B(net29),
    .Y(_1115_));
 sky130_fd_sc_hd__o221ai_1 _1632_ (.A1(_1112_),
    .A2(_1113_),
    .B1(_1114_),
    .B2(_1115_),
    .C1(net47),
    .Y(_1116_));
 sky130_fd_sc_hd__o21ai_0 _1633_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_53_),
    .B1(net107),
    .Y(_1117_));
 sky130_fd_sc_hd__nor2_1 _1634_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_61_),
    .B(_1362_),
    .Y(_1118_));
 sky130_fd_sc_hd__o21ai_0 _1635_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_37_),
    .B1(_1359_),
    .Y(_1119_));
 sky130_fd_sc_hd__nor2_1 _1636_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_45_),
    .B(net29),
    .Y(_1120_));
 sky130_fd_sc_hd__o221ai_1 _1637_ (.A1(_1117_),
    .A2(_1118_),
    .B1(_1119_),
    .B2(_1120_),
    .C1(net106),
    .Y(_1121_));
 sky130_fd_sc_hd__nand3_1 _1638_ (.A(_1085_),
    .B(_1116_),
    .C(_1121_),
    .Y(_1122_));
 sky130_fd_sc_hd__nand2_1 _1639_ (.A(_1001_),
    .B(_1122_),
    .Y(_1123_));
 sky130_fd_sc_hd__o311ai_0 _1640_ (.A1(u_uart_core_uart_tx_sreg_q_7_),
    .A2(net44),
    .A3(_0993_),
    .B1(_0989_),
    .C1(_1123_),
    .Y(_1124_));
 sky130_fd_sc_hd__nand2_1 _1641_ (.A(_0990_),
    .B(u_uart_core_uart_tx_sreg_q_6_),
    .Y(_1125_));
 sky130_fd_sc_hd__nand2_1 _1642_ (.A(_1124_),
    .B(_1125_),
    .Y(_0236_));
 sky130_fd_sc_hd__o21ai_0 _1643_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_20_),
    .B1(net107),
    .Y(_1126_));
 sky130_fd_sc_hd__nor2_1 _1644_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_28_),
    .B(net29),
    .Y(_1127_));
 sky130_fd_sc_hd__o21ai_0 _1645_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_4_),
    .B1(_1359_),
    .Y(_1128_));
 sky130_fd_sc_hd__nor2_1 _1646_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_12_),
    .B(net29),
    .Y(_1129_));
 sky130_fd_sc_hd__o221ai_1 _1647_ (.A1(_1126_),
    .A2(_1127_),
    .B1(_1128_),
    .B2(_1129_),
    .C1(net47),
    .Y(_1130_));
 sky130_fd_sc_hd__o21ai_0 _1648_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_52_),
    .B1(net107),
    .Y(_1131_));
 sky130_fd_sc_hd__nor2_1 _1649_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_60_),
    .B(net29),
    .Y(_1132_));
 sky130_fd_sc_hd__o21ai_0 _1650_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_36_),
    .B1(_1359_),
    .Y(_1133_));
 sky130_fd_sc_hd__nor2_1 _1651_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_44_),
    .B(net29),
    .Y(_1134_));
 sky130_fd_sc_hd__o221ai_1 _1652_ (.A1(_1131_),
    .A2(_1132_),
    .B1(_1133_),
    .B2(_1134_),
    .C1(net106),
    .Y(_1135_));
 sky130_fd_sc_hd__nand3_1 _1653_ (.A(_1085_),
    .B(_1130_),
    .C(_1135_),
    .Y(_1136_));
 sky130_fd_sc_hd__a21oi_1 _1654_ (.A1(_0987_),
    .A2(u_uart_core_uart_tx_sreg_q_6_),
    .B1(net44),
    .Y(_1137_));
 sky130_fd_sc_hd__nand2_1 _1655_ (.A(_0990_),
    .B(u_uart_core_uart_tx_sreg_q_5_),
    .Y(_1138_));
 sky130_fd_sc_hd__o211ai_1 _1656_ (.A1(net21),
    .A2(_1136_),
    .B1(_1137_),
    .C1(_1138_),
    .Y(_0237_));
 sky130_fd_sc_hd__o21ai_0 _1657_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_19_),
    .B1(net107),
    .Y(_1139_));
 sky130_fd_sc_hd__nor2_1 _1658_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_27_),
    .B(net29),
    .Y(_1140_));
 sky130_fd_sc_hd__o21ai_0 _1659_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_3_),
    .B1(_1359_),
    .Y(_1141_));
 sky130_fd_sc_hd__nor2_1 _1660_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_11_),
    .B(net29),
    .Y(_1142_));
 sky130_fd_sc_hd__o221ai_1 _1661_ (.A1(_1139_),
    .A2(_1140_),
    .B1(_1141_),
    .B2(_1142_),
    .C1(net47),
    .Y(_1143_));
 sky130_fd_sc_hd__o21ai_0 _1662_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_51_),
    .B1(net107),
    .Y(_1144_));
 sky130_fd_sc_hd__nor2_1 _1663_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_59_),
    .B(net29),
    .Y(_1145_));
 sky130_fd_sc_hd__o21ai_0 _1664_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_35_),
    .B1(_1359_),
    .Y(_1146_));
 sky130_fd_sc_hd__nor2_1 _1665_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_43_),
    .B(net29),
    .Y(_1147_));
 sky130_fd_sc_hd__o221ai_1 _1666_ (.A1(_1144_),
    .A2(_1145_),
    .B1(_1146_),
    .B2(_1147_),
    .C1(net106),
    .Y(_1148_));
 sky130_fd_sc_hd__nand3_1 _1667_ (.A(_1085_),
    .B(_1143_),
    .C(_1148_),
    .Y(_1149_));
 sky130_fd_sc_hd__nand2_1 _1668_ (.A(net21),
    .B(u_uart_core_uart_tx_sreg_q_5_),
    .Y(_1150_));
 sky130_fd_sc_hd__o21ai_0 _1669_ (.A1(net21),
    .A2(_1149_),
    .B1(_1150_),
    .Y(_1151_));
 sky130_fd_sc_hd__o22a_1 _1670_ (.A1(u_uart_core_uart_tx_sreg_q_4_),
    .A2(_0989_),
    .B1(_1151_),
    .B2(_1000_),
    .X(_0238_));
 sky130_fd_sc_hd__o21ai_0 _1671_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_18_),
    .B1(net107),
    .Y(_1152_));
 sky130_fd_sc_hd__nor2_1 _1672_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_26_),
    .B(net29),
    .Y(_1153_));
 sky130_fd_sc_hd__o21ai_0 _1673_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_2_),
    .B1(_1359_),
    .Y(_1154_));
 sky130_fd_sc_hd__nor2_1 _1674_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_10_),
    .B(net29),
    .Y(_1155_));
 sky130_fd_sc_hd__o221ai_1 _1675_ (.A1(_1152_),
    .A2(_1153_),
    .B1(_1154_),
    .B2(_1155_),
    .C1(net47),
    .Y(_1156_));
 sky130_fd_sc_hd__o21ai_0 _1676_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_50_),
    .B1(net107),
    .Y(_1157_));
 sky130_fd_sc_hd__nor2_1 _1677_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_58_),
    .B(net29),
    .Y(_1158_));
 sky130_fd_sc_hd__o21ai_0 _1678_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_34_),
    .B1(_1359_),
    .Y(_1159_));
 sky130_fd_sc_hd__nor2_1 _1679_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_42_),
    .B(net29),
    .Y(_1160_));
 sky130_fd_sc_hd__o221ai_1 _1680_ (.A1(_1157_),
    .A2(_1158_),
    .B1(_1159_),
    .B2(_1160_),
    .C1(net106),
    .Y(_1161_));
 sky130_fd_sc_hd__nand3_1 _1681_ (.A(_1085_),
    .B(_1156_),
    .C(_1161_),
    .Y(_1162_));
 sky130_fd_sc_hd__a21oi_1 _1682_ (.A1(_0987_),
    .A2(u_uart_core_uart_tx_sreg_q_4_),
    .B1(net44),
    .Y(_1163_));
 sky130_fd_sc_hd__nand2_1 _1683_ (.A(_0990_),
    .B(u_uart_core_uart_tx_sreg_q_3_),
    .Y(_1164_));
 sky130_fd_sc_hd__o211ai_1 _1684_ (.A1(net21),
    .A2(_1162_),
    .B1(_1163_),
    .C1(_1164_),
    .Y(_0239_));
 sky130_fd_sc_hd__o21ai_0 _1685_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_17_),
    .B1(net107),
    .Y(_1165_));
 sky130_fd_sc_hd__nor2_1 _1686_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_25_),
    .B(net29),
    .Y(_1166_));
 sky130_fd_sc_hd__o21ai_0 _1687_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_1_),
    .B1(_1359_),
    .Y(_1167_));
 sky130_fd_sc_hd__nor2_1 _1688_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_9_),
    .B(net29),
    .Y(_1168_));
 sky130_fd_sc_hd__o221ai_1 _1689_ (.A1(_1165_),
    .A2(_1166_),
    .B1(_1167_),
    .B2(_1168_),
    .C1(net47),
    .Y(_1169_));
 sky130_fd_sc_hd__o21ai_0 _1690_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_49_),
    .B1(net107),
    .Y(_1170_));
 sky130_fd_sc_hd__nor2_1 _1691_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_57_),
    .B(net29),
    .Y(_1171_));
 sky130_fd_sc_hd__o21ai_0 _1692_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_33_),
    .B1(_1359_),
    .Y(_1172_));
 sky130_fd_sc_hd__nor2_1 _1693_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_41_),
    .B(net29),
    .Y(_1173_));
 sky130_fd_sc_hd__o221ai_1 _1694_ (.A1(_1170_),
    .A2(_1171_),
    .B1(_1172_),
    .B2(_1173_),
    .C1(net106),
    .Y(_1174_));
 sky130_fd_sc_hd__nand3_1 _1695_ (.A(_1085_),
    .B(_1169_),
    .C(_1174_),
    .Y(_1175_));
 sky130_fd_sc_hd__nand3_1 _1696_ (.A(net21),
    .B(u_uart_core_uart_tx_sreg_q_3_),
    .C(_0987_),
    .Y(_1176_));
 sky130_fd_sc_hd__nand2_1 _1697_ (.A(_0990_),
    .B(u_uart_core_uart_tx_sreg_q_2_),
    .Y(_1177_));
 sky130_fd_sc_hd__o2111ai_1 _1698_ (.A1(net21),
    .A2(_1175_),
    .B1(net74),
    .C1(_1176_),
    .D1(_1177_),
    .Y(_0240_));
 sky130_fd_sc_hd__o21ai_0 _1699_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_16_),
    .B1(net107),
    .Y(_1178_));
 sky130_fd_sc_hd__nor2_1 _1700_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_24_),
    .B(net29),
    .Y(_1179_));
 sky130_fd_sc_hd__o21ai_0 _1701_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_0_),
    .B1(_1359_),
    .Y(_1180_));
 sky130_fd_sc_hd__nor2_1 _1702_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_8_),
    .B(net29),
    .Y(_1181_));
 sky130_fd_sc_hd__o221ai_1 _1703_ (.A1(_1178_),
    .A2(_1179_),
    .B1(_1180_),
    .B2(_1181_),
    .C1(net47),
    .Y(_1182_));
 sky130_fd_sc_hd__o21ai_0 _1704_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_48_),
    .B1(net107),
    .Y(_1183_));
 sky130_fd_sc_hd__nor2_1 _1705_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_56_),
    .B(net29),
    .Y(_1184_));
 sky130_fd_sc_hd__o21ai_0 _1706_ (.A1(net108),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_32_),
    .B1(_1359_),
    .Y(_1185_));
 sky130_fd_sc_hd__nor2_1 _1707_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_40_),
    .B(net29),
    .Y(_1186_));
 sky130_fd_sc_hd__o221ai_1 _1708_ (.A1(_1183_),
    .A2(_1184_),
    .B1(_1185_),
    .B2(_1186_),
    .C1(net106),
    .Y(_1187_));
 sky130_fd_sc_hd__nand3_1 _1709_ (.A(_1085_),
    .B(_1182_),
    .C(_1187_),
    .Y(_1188_));
 sky130_fd_sc_hd__nor2_1 _1710_ (.A(u_uart_core_uart_tx_sreg_q_1_),
    .B(_0989_),
    .Y(_1189_));
 sky130_fd_sc_hd__a21oi_1 _1711_ (.A1(u_uart_core_uart_tx_sreg_q_2_),
    .A2(net21),
    .B1(_1000_),
    .Y(_1190_));
 sky130_fd_sc_hd__o22ai_1 _1712_ (.A1(net21),
    .A2(_1188_),
    .B1(_1189_),
    .B2(_1190_),
    .Y(_0241_));
 sky130_fd_sc_hd__nor2_1 _1713_ (.A(u_uart_core_uart_tx_sreg_q_0_),
    .B(net44),
    .Y(_1191_));
 sky130_fd_sc_hd__nand3_1 _1714_ (.A(net21),
    .B(u_uart_core_uart_tx_sreg_q_1_),
    .C(_0987_),
    .Y(_1192_));
 sky130_fd_sc_hd__o21ai_0 _1715_ (.A1(_1191_),
    .A2(_0991_),
    .B1(_1192_),
    .Y(_0242_));
 sky130_fd_sc_hd__xnor2_1 _1716_ (.A(_1096_),
    .B(_1109_),
    .Y(_1193_));
 sky130_fd_sc_hd__xor2_1 _1717_ (.A(_1122_),
    .B(_1136_),
    .X(_1194_));
 sky130_fd_sc_hd__xnor2_1 _1718_ (.A(_1193_),
    .B(_1194_),
    .Y(_1195_));
 sky130_fd_sc_hd__xnor2_1 _1719_ (.A(_1149_),
    .B(_1162_),
    .Y(_1196_));
 sky130_fd_sc_hd__xor2_1 _1720_ (.A(_1175_),
    .B(_1188_),
    .X(_1197_));
 sky130_fd_sc_hd__xnor2_1 _1721_ (.A(_1196_),
    .B(_1197_),
    .Y(_1198_));
 sky130_fd_sc_hd__xnor2_1 _1722_ (.A(_1195_),
    .B(_1198_),
    .Y(_1199_));
 sky130_fd_sc_hd__xor2_1 _1723_ (.A(net75),
    .B(_1199_),
    .X(_1200_));
 sky130_fd_sc_hd__nor2_1 _1724_ (.A(u_uart_core_uart_tx_sreg_q_9_),
    .B(_0989_),
    .Y(_1201_));
 sky130_fd_sc_hd__a21oi_1 _1725_ (.A1(_1200_),
    .A2(_1003_),
    .B1(_1201_),
    .Y(_0243_));
 sky130_fd_sc_hd__nor2_1 _1726_ (.A(_1296_),
    .B(_1319_),
    .Y(_1202_));
 sky130_fd_sc_hd__xnor2_1 _1727_ (.A(_1202_),
    .B(_1316_),
    .Y(_0013_));
 sky130_fd_sc_hd__maj3_1 _1728_ (.A(net78),
    .B(_1336_),
    .C(net60),
    .X(_1203_));
 sky130_fd_sc_hd__xor2_1 _1729_ (.A(_1341_),
    .B(_1203_),
    .X(_0006_));
 sky130_fd_sc_hd__nand2_1 _1730_ (.A(_0776_),
    .B(u_uart_core_tx_out_q),
    .Y(_1204_));
 sky130_fd_sc_hd__nand2_1 _1731_ (.A(reg2hw_38_),
    .B(rx_i),
    .Y(_1205_));
 sky130_fd_sc_hd__nand2_4 _1732_ (.A(_1204_),
    .B(_1205_),
    .Y(tx_o));
 sky130_fd_sc_hd__nor2_1 _1733_ (.A(_0388_),
    .B(_1072_),
    .Y(_1206_));
 sky130_fd_sc_hd__o21ai_0 _1734_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .A2(_1206_),
    .B1(_1073_),
    .Y(_1207_));
 sky130_fd_sc_hd__a21oi_1 _1735_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .A2(_1206_),
    .B1(_1207_),
    .Y(_0244_));
 sky130_fd_sc_hd__o21ai_0 _1736_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .A2(_0035_),
    .B1(_1073_),
    .Y(_1208_));
 sky130_fd_sc_hd__a21oi_1 _1737_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .A2(_0035_),
    .B1(_1208_),
    .Y(_0245_));
 sky130_fd_sc_hd__o22ai_1 _1738_ (.A1(_1048_),
    .A2(_1049_),
    .B1(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .B2(_1055_),
    .Y(_1209_));
 sky130_fd_sc_hd__a21oi_1 _1739_ (.A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .A2(_1055_),
    .B1(_1209_),
    .Y(_0246_));
 sky130_fd_sc_hd__o22ai_1 _1740_ (.A1(_1048_),
    .A2(_1049_),
    .B1(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .B2(_0018_),
    .Y(_1210_));
 sky130_fd_sc_hd__a21oi_1 _1741_ (.A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .A2(_0018_),
    .B1(_1210_),
    .Y(_0247_));
 sky130_fd_sc_hd__inv_1 _1742_ (.A(u_uart_core_uart_rx_baud_div_q_3_),
    .Y(_1211_));
 sky130_fd_sc_hd__nand3_1 _1743_ (.A(_1043_),
    .B(u_uart_core_uart_rx_baud_div_q_2_),
    .C(u_uart_core_uart_rx_baud_div_q_3_),
    .Y(_1212_));
 sky130_fd_sc_hd__nor2_1 _1744_ (.A(_1212_),
    .B(_1024_),
    .Y(u_uart_core_uart_rx_tick_baud_d));
 sky130_fd_sc_hd__a21oi_1 _1745_ (.A1(_1044_),
    .A2(_1211_),
    .B1(u_uart_core_uart_rx_tick_baud_d),
    .Y(_0248_));
 sky130_fd_sc_hd__xnor2_1 _1746_ (.A(net100),
    .B(_1031_),
    .Y(_1213_));
 sky130_fd_sc_hd__o21ai_0 _1747_ (.A1(net100),
    .A2(_1024_),
    .B1(_1010_),
    .Y(_1214_));
 sky130_fd_sc_hd__o21ai_0 _1748_ (.A1(_1213_),
    .A2(_1021_),
    .B1(_1214_),
    .Y(_0249_));
 sky130_fd_sc_hd__nand2_1 _1749_ (.A(_1019_),
    .B(u_uart_core_rx_tick_baud),
    .Y(_1215_));
 sky130_fd_sc_hd__nand2_1 _1750_ (.A(_1034_),
    .B(_1012_),
    .Y(_1216_));
 sky130_fd_sc_hd__nor3_1 _1751_ (.A(net100),
    .B(_1008_),
    .C(_1216_),
    .Y(_0000_));
 sky130_fd_sc_hd__nor2_1 _1752_ (.A(hw2reg_28_),
    .B(_0000_),
    .Y(_1217_));
 sky130_fd_sc_hd__a21oi_1 _1753_ (.A1(_1215_),
    .A2(_1217_),
    .B1(_1024_),
    .Y(_0250_));
 sky130_fd_sc_hd__o22ai_1 _1754_ (.A1(_1018_),
    .A2(_1021_),
    .B1(_0381_),
    .B2(_1026_),
    .Y(_0251_));
 sky130_fd_sc_hd__a21oi_1 _1755_ (.A1(_1007_),
    .A2(u_uart_core_uart_tx_baud_div_q_2_),
    .B1(u_uart_core_uart_tx_baud_div_q_3_),
    .Y(_1218_));
 sky130_fd_sc_hd__and3_1 _1756_ (.A(_1007_),
    .B(u_uart_core_uart_tx_baud_div_q_2_),
    .C(u_uart_core_uart_tx_baud_div_q_3_),
    .X(_1372_));
 sky130_fd_sc_hd__nor2_1 _1757_ (.A(_1218_),
    .B(_1372_),
    .Y(_0252_));
 sky130_fd_sc_hd__inv_1 _1758_ (.A(u_uart_core_uart_tx_bit_cnt_q_3_),
    .Y(_1219_));
 sky130_fd_sc_hd__a21oi_1 _1759_ (.A1(net74),
    .A2(_0821_),
    .B1(_0990_),
    .Y(_1220_));
 sky130_fd_sc_hd__o21ai_0 _1760_ (.A1(_1219_),
    .A2(_1220_),
    .B1(_1002_),
    .Y(_0253_));
 sky130_fd_sc_hd__inv_1 _1761_ (.A(u_uart_core_tx_out),
    .Y(_1221_));
 sky130_fd_sc_hd__a22oi_1 _1762_ (.A1(_0987_),
    .A2(_1191_),
    .B1(_0988_),
    .B2(_1221_),
    .Y(_0254_));
 sky130_fd_sc_hd__nand2_1 _1763_ (.A(_0976_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_4_),
    .Y(_1222_));
 sky130_fd_sc_hd__nand2_1 _1764_ (.A(_0975_),
    .B(axi_lite_i[9]),
    .Y(_1223_));
 sky130_fd_sc_hd__nand2_1 _1765_ (.A(_1222_),
    .B(_1223_),
    .Y(_0255_));
 sky130_fd_sc_hd__nand2_1 _1766_ (.A(_0972_),
    .B(axi_lite_i[9]),
    .Y(_1224_));
 sky130_fd_sc_hd__o21ai_0 _1767_ (.A1(_0436_),
    .A2(_0972_),
    .B1(_1224_),
    .Y(_0256_));
 sky130_fd_sc_hd__xor2_1 _1768_ (.A(net92),
    .B(_0632_),
    .X(_0257_));
 sky130_fd_sc_hd__nand2_1 _1769_ (.A(_0967_),
    .B(net91),
    .Y(_1225_));
 sky130_fd_sc_hd__o21ai_0 _1770_ (.A1(net91),
    .A2(_0969_),
    .B1(_1225_),
    .Y(_1226_));
 sky130_fd_sc_hd__xor2_1 _1771_ (.A(net90),
    .B(_1226_),
    .X(_0258_));
 sky130_fd_sc_hd__nand2_1 _1772_ (.A(_0966_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_write_pointer_q),
    .Y(_1227_));
 sky130_fd_sc_hd__nand2_1 _1773_ (.A(_0976_),
    .B(_1227_),
    .Y(_0259_));
 sky130_fd_sc_hd__a21oi_1 _1774_ (.A1(_0491_),
    .A2(net77),
    .B1(_0637_),
    .Y(_1228_));
 sky130_fd_sc_hd__nand2_1 _1775_ (.A(net16),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_32_),
    .Y(_1229_));
 sky130_fd_sc_hd__o21ai_0 _1776_ (.A1(_0940_),
    .A2(_1228_),
    .B1(_1229_),
    .Y(_0260_));
 sky130_fd_sc_hd__o21ai_0 _1777_ (.A1(_0366_),
    .A2(_0939_),
    .B1(_0957_),
    .Y(_0261_));
 sky130_fd_sc_hd__nor2_1 _1778_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_65_),
    .B(net18),
    .Y(_1230_));
 sky130_fd_sc_hd__a21oi_1 _1779_ (.A1(_1228_),
    .A2(net17),
    .B1(_1230_),
    .Y(_0262_));
 sky130_fd_sc_hd__o21ai_0 _1780_ (.A1(net45),
    .A2(_0640_),
    .B1(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_33_),
    .Y(_1231_));
 sky130_fd_sc_hd__nand2_1 _1781_ (.A(_0690_),
    .B(_1231_),
    .Y(_0263_));
 sky130_fd_sc_hd__nand2_1 _1782_ (.A(u_uart_reg_axi_lite_o_0_),
    .B(axi_lite_i[0]),
    .Y(_1232_));
 sky130_fd_sc_hd__xor2_1 _1783_ (.A(_0303_),
    .B(_1232_),
    .X(_0264_));
 sky130_fd_sc_hd__o211ai_1 _1784_ (.A1(net87),
    .A2(_0635_),
    .B1(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_status_cnt_q_1_),
    .C1(_0636_),
    .Y(_1233_));
 sky130_fd_sc_hd__o21ai_0 _1785_ (.A1(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_status_cnt_q_1_),
    .A2(_0636_),
    .B1(_1233_),
    .Y(_0265_));
 sky130_fd_sc_hd__nor2_1 _1786_ (.A(net86),
    .B(_0632_),
    .Y(_1234_));
 sky130_fd_sc_hd__nor2_1 _1787_ (.A(_1234_),
    .B(net17),
    .Y(_0266_));
 sky130_fd_sc_hd__nand2_1 _1788_ (.A(_0589_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_40_),
    .Y(_1235_));
 sky130_fd_sc_hd__nand2_1 _1789_ (.A(net24),
    .B(axi_lite_i[56]),
    .Y(_1236_));
 sky130_fd_sc_hd__nand2_1 _1790_ (.A(_1235_),
    .B(_1236_),
    .Y(_0267_));
 sky130_fd_sc_hd__nand2_1 _1791_ (.A(_0589_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_35_),
    .Y(_1237_));
 sky130_fd_sc_hd__nand2_1 _1792_ (.A(net24),
    .B(axi_lite_i[47]),
    .Y(_1238_));
 sky130_fd_sc_hd__nand2_1 _1793_ (.A(_1237_),
    .B(_1238_),
    .Y(_0268_));
 sky130_fd_sc_hd__nand2_1 _1794_ (.A(net28),
    .B(axi_lite_i[15]),
    .Y(_1239_));
 sky130_fd_sc_hd__o21ai_0 _1795_ (.A1(_0494_),
    .A2(net28),
    .B1(_1239_),
    .Y(_0269_));
 sky130_fd_sc_hd__nand2_1 _1796_ (.A(net25),
    .B(axi_lite_i[56]),
    .Y(_1240_));
 sky130_fd_sc_hd__o21ai_0 _1797_ (.A1(_0439_),
    .A2(net25),
    .B1(_1240_),
    .Y(_0270_));
 sky130_fd_sc_hd__mux2_1 _1798_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_76_),
    .A1(axi_lite_i[47]),
    .S(_0581_),
    .X(_0271_));
 sky130_fd_sc_hd__nand2_1 _1799_ (.A(net25),
    .B(axi_lite_i[15]),
    .Y(_1241_));
 sky130_fd_sc_hd__o21ai_0 _1800_ (.A1(_0496_),
    .A2(net25),
    .B1(_1241_),
    .Y(_0272_));
 sky130_fd_sc_hd__xor2_1 _1801_ (.A(net85),
    .B(net26),
    .X(_0273_));
 sky130_fd_sc_hd__nand2_1 _1802_ (.A(_0473_),
    .B(_0577_),
    .Y(_1242_));
 sky130_fd_sc_hd__nand2_1 _1803_ (.A(_0578_),
    .B(_1242_),
    .Y(_1243_));
 sky130_fd_sc_hd__xnor2_1 _1804_ (.A(net84),
    .B(_1243_),
    .Y(_0274_));
 sky130_fd_sc_hd__nor2_1 _1805_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_write_pointer_q),
    .B(u_uart_reg_axi_lite_o_39_),
    .Y(_1244_));
 sky130_fd_sc_hd__nor2_1 _1806_ (.A(_1244_),
    .B(net25),
    .Y(_0275_));
 sky130_fd_sc_hd__inv_1 _1807_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_write_pointer_q),
    .Y(_1245_));
 sky130_fd_sc_hd__nor2_1 _1808_ (.A(_1245_),
    .B(_0473_),
    .Y(_1246_));
 sky130_fd_sc_hd__nor2_1 _1809_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_mem_q_1_),
    .B(_1246_),
    .Y(_1247_));
 sky130_fd_sc_hd__a21oi_1 _1810_ (.A1(_0500_),
    .A2(_1246_),
    .B1(_1247_),
    .Y(_0276_));
 sky130_fd_sc_hd__xnor2_1 _1811_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_read_pointer_q),
    .B(_0572_),
    .Y(_0277_));
 sky130_fd_sc_hd__nand2_1 _1812_ (.A(_0573_),
    .B(net83),
    .Y(_1248_));
 sky130_fd_sc_hd__xnor2_1 _1813_ (.A(axi_lite_i[10]),
    .B(_1248_),
    .Y(_1249_));
 sky130_fd_sc_hd__nor2_1 _1814_ (.A(axi_lite_i[10]),
    .B(_1248_),
    .Y(_1250_));
 sky130_fd_sc_hd__nor2_1 _1815_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_status_cnt_q_1_),
    .B(_1250_),
    .Y(_1251_));
 sky130_fd_sc_hd__a31oi_1 _1816_ (.A1(_1249_),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_status_cnt_q_1_),
    .A3(_0573_),
    .B1(_1251_),
    .Y(_0278_));
 sky130_fd_sc_hd__nor2_1 _1817_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_write_pointer_q),
    .B(net26),
    .Y(_1252_));
 sky130_fd_sc_hd__nor2_1 _1818_ (.A(_1252_),
    .B(_1246_),
    .Y(_0279_));
 sky130_fd_sc_hd__nand2_1 _1819_ (.A(_0433_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_stream_arbiter_i_arb_gen_rr_arb_i_arbiter_gen_arbiter_rr_q),
    .Y(_1253_));
 sky130_fd_sc_hd__o21ai_0 _1820_ (.A1(u_uart_reg_u_flexsoc_axi_to_reg_i_stream_arbiter_i_arb_gen_rr_arb_i_arbiter_gen_arbiter_rr_q),
    .A2(_0430_),
    .B1(_1253_),
    .Y(_0280_));
 sky130_fd_sc_hd__nand2_1 _1821_ (.A(net9),
    .B(_0507_),
    .Y(_1254_));
 sky130_fd_sc_hd__o21ai_0 _1822_ (.A1(_0776_),
    .A2(net9),
    .B1(_1254_),
    .Y(_0281_));
 sky130_fd_sc_hd__nand2_1 _1823_ (.A(net85),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_76_),
    .Y(_1255_));
 sky130_fd_sc_hd__nand2_1 _1824_ (.A(net46),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_35_),
    .Y(_1256_));
 sky130_fd_sc_hd__nor2_1 _1825_ (.A(net77),
    .B(net9),
    .Y(_1257_));
 sky130_fd_sc_hd__a31oi_1 _1826_ (.A1(net9),
    .A2(_1255_),
    .A3(_1256_),
    .B1(_1257_),
    .Y(_0282_));
 sky130_fd_sc_hd__nand2_1 _1827_ (.A(net9),
    .B(_0517_),
    .Y(_1258_));
 sky130_fd_sc_hd__o21ai_0 _1828_ (.A1(_0878_),
    .A2(net9),
    .B1(_1258_),
    .Y(_0283_));
 sky130_fd_sc_hd__nand2_1 _1829_ (.A(net9),
    .B(_0504_),
    .Y(_1259_));
 sky130_fd_sc_hd__o21ai_0 _1830_ (.A1(_0378_),
    .A2(net9),
    .B1(_1259_),
    .Y(_0284_));
 sky130_fd_sc_hd__nand2_1 _1831_ (.A(net85),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_52_),
    .Y(_1260_));
 sky130_fd_sc_hd__o21ai_0 _1832_ (.A1(net85),
    .A2(_0617_),
    .B1(_1260_),
    .Y(_1261_));
 sky130_fd_sc_hd__mux2_1 _1833_ (.A0(net75),
    .A1(_1261_),
    .S(_0524_),
    .X(_0285_));
 sky130_fd_sc_hd__nand2_1 _1834_ (.A(net9),
    .B(_0520_),
    .Y(_1262_));
 sky130_fd_sc_hd__o21ai_0 _1835_ (.A1(_0907_),
    .A2(_0524_),
    .B1(_1262_),
    .Y(_0286_));
 sky130_fd_sc_hd__nand2_1 _1836_ (.A(net9),
    .B(_0510_),
    .Y(_1263_));
 sky130_fd_sc_hd__o21ai_0 _1837_ (.A1(_0810_),
    .A2(_0524_),
    .B1(_1263_),
    .Y(_0287_));
 sky130_fd_sc_hd__nand2_1 _1838_ (.A(net9),
    .B(_0523_),
    .Y(_1264_));
 sky130_fd_sc_hd__o21ai_0 _1839_ (.A1(net44),
    .A2(_0524_),
    .B1(_1264_),
    .Y(_0288_));
 sky130_fd_sc_hd__nor2_2 _1840_ (.A(_0475_),
    .B(_0501_),
    .Y(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_));
 sky130_fd_sc_hd__nand2_1 _1841_ (.A(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .B(_0523_),
    .Y(_1265_));
 sky130_fd_sc_hd__o21ai_0 _1842_ (.A1(_1060_),
    .A2(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .B1(_1265_),
    .Y(_0289_));
 sky130_fd_sc_hd__nand2_1 _1843_ (.A(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .B(_0520_),
    .Y(_1266_));
 sky130_fd_sc_hd__o21ai_0 _1844_ (.A1(_1048_),
    .A2(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .B1(_1266_),
    .Y(_0290_));
 sky130_fd_sc_hd__mux2_1 _1845_ (.A0(net66),
    .A1(_1261_),
    .S(u_uart_reg_u_reg_core_reg_we_check_3_),
    .X(_0291_));
 sky130_fd_sc_hd__nor2_1 _1846_ (.A(_1079_),
    .B(_1329_),
    .Y(_1267_));
 sky130_fd_sc_hd__nor2_1 _1847_ (.A(_1293_),
    .B(_1267_),
    .Y(_1268_));
 sky130_fd_sc_hd__xnor2_1 _1848_ (.A(_1289_),
    .B(_1268_),
    .Y(_0017_));
 sky130_fd_sc_hd__nand2_1 _1849_ (.A(_0810_),
    .B(_1221_),
    .Y(_1371_));
 sky130_fd_sc_hd__nand2_1 _1850_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_32_),
    .Y(_1269_));
 sky130_fd_sc_hd__nand2_1 _1851_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_65_),
    .Y(_1270_));
 sky130_fd_sc_hd__nand2_1 _1852_ (.A(_1269_),
    .B(_1270_),
    .Y(u_uart_reg_axi_lite_o_34_));
 sky130_fd_sc_hd__inv_1 _1853_ (.A(_1310_),
    .Y(_1271_));
 sky130_fd_sc_hd__nor2_1 _1854_ (.A(_1309_),
    .B(_1271_),
    .Y(_1272_));
 sky130_fd_sc_hd__xnor2_1 _1855_ (.A(_1308_),
    .B(_1272_),
    .Y(_0009_));
 sky130_fd_sc_hd__mux2_1 _1856_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_mem_q_0_),
    .A1(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_mem_q_1_),
    .S(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_read_pointer_q),
    .X(u_uart_reg_axi_lite_o_38_));
 sky130_fd_sc_hd__nand2_1 _1857_ (.A(net76),
    .B(net93),
    .Y(_1273_));
 sky130_fd_sc_hd__o21ai_2 _1858_ (.A1(net76),
    .A2(_1022_),
    .B1(_1273_),
    .Y(u_uart_core_rx_fifo_data_7_));
 sky130_fd_sc_hd__inv_1 _1859_ (.A(reg2hw_55_),
    .Y(_1274_));
 sky130_fd_sc_hd__inv_1 _1860_ (.A(u_uart_core_nco_sum_q_14_),
    .Y(_1275_));
 sky130_fd_sc_hd__nor2_1 _1861_ (.A(_1274_),
    .B(_1275_),
    .Y(_1276_));
 sky130_fd_sc_hd__nor2_1 _1862_ (.A(reg2hw_55_),
    .B(u_uart_core_nco_sum_q_14_),
    .Y(_1277_));
 sky130_fd_sc_hd__nor2_1 _1863_ (.A(reg2hw_52_),
    .B(u_uart_core_nco_sum_q_11_),
    .Y(_1278_));
 sky130_fd_sc_hd__inv_1 _1864_ (.A(reg2hw_52_),
    .Y(_1279_));
 sky130_fd_sc_hd__inv_1 _1865_ (.A(u_uart_core_nco_sum_q_11_),
    .Y(_1280_));
 sky130_fd_sc_hd__nor2_1 _1866_ (.A(_1279_),
    .B(_1280_),
    .Y(_1281_));
 sky130_fd_sc_hd__nor2_1 _1867_ (.A(_1278_),
    .B(_1281_),
    .Y(_1282_));
 sky130_fd_sc_hd__xor2_1 _1868_ (.A(net79),
    .B(u_uart_core_nco_sum_q_10_),
    .X(_1283_));
 sky130_fd_sc_hd__nand2_1 _1869_ (.A(_1282_),
    .B(_1283_),
    .Y(_1284_));
 sky130_fd_sc_hd__nor2_1 _1870_ (.A(reg2hw_50_),
    .B(u_uart_core_nco_sum_q_9_),
    .Y(_1285_));
 sky130_fd_sc_hd__inv_1 _1871_ (.A(reg2hw_50_),
    .Y(_1286_));
 sky130_fd_sc_hd__inv_1 _1872_ (.A(u_uart_core_nco_sum_q_9_),
    .Y(_1287_));
 sky130_fd_sc_hd__nor2_1 _1873_ (.A(_1286_),
    .B(_1287_),
    .Y(_1288_));
 sky130_fd_sc_hd__nor2_1 _1874_ (.A(_1285_),
    .B(_1288_),
    .Y(_1289_));
 sky130_fd_sc_hd__nor2_1 _1875_ (.A(reg2hw_49_),
    .B(u_uart_core_nco_sum_q_8_),
    .Y(_1290_));
 sky130_fd_sc_hd__inv_1 _1876_ (.A(reg2hw_49_),
    .Y(_1291_));
 sky130_fd_sc_hd__inv_1 _1877_ (.A(u_uart_core_nco_sum_q_8_),
    .Y(_1292_));
 sky130_fd_sc_hd__nor2_1 _1878_ (.A(_1291_),
    .B(_1292_),
    .Y(_1293_));
 sky130_fd_sc_hd__nor2_1 _1879_ (.A(_1290_),
    .B(_1293_),
    .Y(_1294_));
 sky130_fd_sc_hd__nand2_1 _1880_ (.A(_1289_),
    .B(_1294_),
    .Y(_1295_));
 sky130_fd_sc_hd__nor2_1 _1881_ (.A(reg2hw_46_),
    .B(u_uart_core_nco_sum_q_5_),
    .Y(_1296_));
 sky130_fd_sc_hd__xor2_1 _1882_ (.A(net81),
    .B(u_uart_core_nco_sum_q_4_),
    .X(_1297_));
 sky130_fd_sc_hd__inv_1 _1883_ (.A(_1297_),
    .Y(_1298_));
 sky130_fd_sc_hd__inv_1 _1884_ (.A(reg2hw_44_),
    .Y(_1299_));
 sky130_fd_sc_hd__inv_1 _1885_ (.A(u_uart_core_nco_sum_q_3_),
    .Y(_1300_));
 sky130_fd_sc_hd__nor2_1 _1886_ (.A(_1299_),
    .B(_1300_),
    .Y(_1301_));
 sky130_fd_sc_hd__nor2_1 _1887_ (.A(reg2hw_44_),
    .B(u_uart_core_nco_sum_q_3_),
    .Y(_1302_));
 sky130_fd_sc_hd__nor2_1 _1888_ (.A(reg2hw_43_),
    .B(u_uart_core_nco_sum_q_2_),
    .Y(_1303_));
 sky130_fd_sc_hd__inv_1 _1889_ (.A(reg2hw_43_),
    .Y(_1304_));
 sky130_fd_sc_hd__inv_1 _1890_ (.A(u_uart_core_nco_sum_q_2_),
    .Y(_1305_));
 sky130_fd_sc_hd__nor2_1 _1891_ (.A(_1304_),
    .B(_1305_),
    .Y(_1306_));
 sky130_fd_sc_hd__nor2_1 _1892_ (.A(_1303_),
    .B(_1306_),
    .Y(_1307_));
 sky130_fd_sc_hd__nand2_1 _1893_ (.A(net82),
    .B(u_uart_core_nco_sum_q_0_),
    .Y(_1308_));
 sky130_fd_sc_hd__nor2_1 _1894_ (.A(reg2hw_42_),
    .B(u_uart_core_nco_sum_q_1_),
    .Y(_1309_));
 sky130_fd_sc_hd__nand2_1 _1895_ (.A(reg2hw_42_),
    .B(u_uart_core_nco_sum_q_1_),
    .Y(_1310_));
 sky130_fd_sc_hd__o21ai_1 _1896_ (.A1(_1308_),
    .A2(_1309_),
    .B1(_1310_),
    .Y(_1311_));
 sky130_fd_sc_hd__a21oi_1 _1897_ (.A1(_1307_),
    .A2(_1311_),
    .B1(_1306_),
    .Y(_1312_));
 sky130_fd_sc_hd__nor2_1 _1898_ (.A(_1302_),
    .B(_1312_),
    .Y(_1313_));
 sky130_fd_sc_hd__nor2_1 _1899_ (.A(_1301_),
    .B(_1313_),
    .Y(_1314_));
 sky130_fd_sc_hd__nor2_1 _1900_ (.A(_1298_),
    .B(_1314_),
    .Y(_1315_));
 sky130_fd_sc_hd__a21oi_1 _1901_ (.A1(net81),
    .A2(u_uart_core_nco_sum_q_4_),
    .B1(_1315_),
    .Y(_1316_));
 sky130_fd_sc_hd__inv_1 _1902_ (.A(reg2hw_46_),
    .Y(_1317_));
 sky130_fd_sc_hd__inv_1 _1903_ (.A(u_uart_core_nco_sum_q_5_),
    .Y(_1318_));
 sky130_fd_sc_hd__nor2_1 _1904_ (.A(_1317_),
    .B(_1318_),
    .Y(_1319_));
 sky130_fd_sc_hd__o21bai_2 _1905_ (.A1(_1296_),
    .A2(_1316_),
    .B1_N(_1319_),
    .Y(_1320_));
 sky130_fd_sc_hd__nor2_1 _1906_ (.A(reg2hw_48_),
    .B(u_uart_core_nco_sum_q_7_),
    .Y(_1321_));
 sky130_fd_sc_hd__inv_1 _1907_ (.A(reg2hw_48_),
    .Y(_1322_));
 sky130_fd_sc_hd__inv_1 _1908_ (.A(u_uart_core_nco_sum_q_7_),
    .Y(_1323_));
 sky130_fd_sc_hd__nor2_1 _1909_ (.A(_1322_),
    .B(_1323_),
    .Y(_1324_));
 sky130_fd_sc_hd__nor2_1 _1910_ (.A(_1321_),
    .B(_1324_),
    .Y(_1325_));
 sky130_fd_sc_hd__xor2_1 _1911_ (.A(net80),
    .B(u_uart_core_nco_sum_q_6_),
    .X(_1326_));
 sky130_fd_sc_hd__nand2_1 _1912_ (.A(net80),
    .B(u_uart_core_nco_sum_q_6_),
    .Y(_1327_));
 sky130_fd_sc_hd__nor2_1 _1913_ (.A(_1327_),
    .B(_1321_),
    .Y(_1328_));
 sky130_fd_sc_hd__a311oi_2 _1914_ (.A1(_1320_),
    .A2(_1325_),
    .A3(_1326_),
    .B1(_1324_),
    .C1(_1328_),
    .Y(_1329_));
 sky130_fd_sc_hd__nand2_1 _1915_ (.A(net79),
    .B(u_uart_core_nco_sum_q_10_),
    .Y(_1330_));
 sky130_fd_sc_hd__nor2_1 _1916_ (.A(_1330_),
    .B(_1278_),
    .Y(_1331_));
 sky130_fd_sc_hd__inv_1 _1917_ (.A(_1285_),
    .Y(_1332_));
 sky130_fd_sc_hd__a21oi_1 _1918_ (.A1(_1293_),
    .A2(_1332_),
    .B1(_1288_),
    .Y(_1333_));
 sky130_fd_sc_hd__nor2_1 _1919_ (.A(_1333_),
    .B(_1284_),
    .Y(_1334_));
 sky130_fd_sc_hd__nor3_1 _1920_ (.A(_1281_),
    .B(_1331_),
    .C(_1334_),
    .Y(_1335_));
 sky130_fd_sc_hd__o31ai_1 _1921_ (.A1(_1284_),
    .A2(_1295_),
    .A3(_1329_),
    .B1(_1335_),
    .Y(_1336_));
 sky130_fd_sc_hd__nor2_1 _1922_ (.A(reg2hw_54_),
    .B(u_uart_core_nco_sum_q_13_),
    .Y(_1337_));
 sky130_fd_sc_hd__inv_1 _1923_ (.A(reg2hw_54_),
    .Y(_1338_));
 sky130_fd_sc_hd__inv_1 _1924_ (.A(u_uart_core_nco_sum_q_13_),
    .Y(_1339_));
 sky130_fd_sc_hd__nor2_1 _1925_ (.A(_1338_),
    .B(_1339_),
    .Y(_1340_));
 sky130_fd_sc_hd__nor2_1 _1926_ (.A(_1337_),
    .B(_1340_),
    .Y(_1341_));
 sky130_fd_sc_hd__xor2_1 _1927_ (.A(net78),
    .B(net60),
    .X(_1342_));
 sky130_fd_sc_hd__a21oi_1 _1928_ (.A1(net78),
    .A2(net60),
    .B1(_1340_),
    .Y(_1343_));
 sky130_fd_sc_hd__nor2_1 _1929_ (.A(_1337_),
    .B(_1343_),
    .Y(_1344_));
 sky130_fd_sc_hd__a31oi_1 _1930_ (.A1(_1336_),
    .A2(_1341_),
    .A3(_1342_),
    .B1(_1344_),
    .Y(_1345_));
 sky130_fd_sc_hd__nor3_1 _1931_ (.A(_1276_),
    .B(_1277_),
    .C(_1345_),
    .Y(_1346_));
 sky130_fd_sc_hd__o21a_1 _1932_ (.A1(_1276_),
    .A2(_1277_),
    .B1(_1345_),
    .X(_1347_));
 sky130_fd_sc_hd__nor2_1 _1933_ (.A(_1346_),
    .B(_1347_),
    .Y(_0007_));
 sky130_fd_sc_hd__nor2_1 _1934_ (.A(net77),
    .B(u_uart_core_nco_sum_q_15_),
    .Y(_1348_));
 sky130_fd_sc_hd__nand2_1 _1935_ (.A(net77),
    .B(u_uart_core_nco_sum_q_15_),
    .Y(_1349_));
 sky130_fd_sc_hd__inv_1 _1936_ (.A(_1349_),
    .Y(_1350_));
 sky130_fd_sc_hd__nor2_1 _1937_ (.A(_1348_),
    .B(_1350_),
    .Y(_1351_));
 sky130_fd_sc_hd__nor2_1 _1938_ (.A(_1276_),
    .B(_1346_),
    .Y(_1352_));
 sky130_fd_sc_hd__xnor2_1 _1939_ (.A(_1351_),
    .B(_1352_),
    .Y(_0008_));
 sky130_fd_sc_hd__inv_4 _1940_ (.A(net103),
    .Y(_1353_));
 sky130_fd_sc_hd__inv_1 _1941_ (.A(net104),
    .Y(_1354_));
 sky130_fd_sc_hd__inv_2 _1942_ (.A(net105),
    .Y(_1355_));
 sky130_fd_sc_hd__xnor2_1 _1943_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .Y(_1356_));
 sky130_fd_sc_hd__inv_1 _1944_ (.A(_1356_),
    .Y(_1357_));
 sky130_fd_sc_hd__nor2_1 _1945_ (.A(net107),
    .B(_1354_),
    .Y(_1358_));
 sky130_fd_sc_hd__inv_4 _1946_ (.A(net107),
    .Y(_1359_));
 sky130_fd_sc_hd__nor2_1 _1947_ (.A(net104),
    .B(_1359_),
    .Y(_1360_));
 sky130_fd_sc_hd__nor2_1 _1948_ (.A(_1358_),
    .B(_1360_),
    .Y(_1361_));
 sky130_fd_sc_hd__inv_1 _1949_ (.A(net108),
    .Y(_1362_));
 sky130_fd_sc_hd__nor2_1 _1950_ (.A(net105),
    .B(_1362_),
    .Y(_1363_));
 sky130_fd_sc_hd__nor2_1 _1951_ (.A(net108),
    .B(_1355_),
    .Y(_1364_));
 sky130_fd_sc_hd__nor2_1 _1952_ (.A(_1363_),
    .B(_1364_),
    .Y(_1365_));
 sky130_fd_sc_hd__lpflow_clkinvkapwr_1 _1953_ (.A(net106),
    .Y(_1366_));
 sky130_fd_sc_hd__nor2_1 _1954_ (.A(net103),
    .B(net47),
    .Y(_1367_));
 sky130_fd_sc_hd__nor2_1 _1955_ (.A(net106),
    .B(_1353_),
    .Y(_1368_));
 sky130_fd_sc_hd__nor2_1 _1956_ (.A(_1367_),
    .B(_1368_),
    .Y(_1369_));
 sky130_fd_sc_hd__nand4_1 _1957_ (.A(_1357_),
    .B(_1361_),
    .C(_1365_),
    .D(_1369_),
    .Y(_1370_));
 sky130_fd_sc_hd__inv_1 _1958_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_under_rst),
    .Y(_0292_));
 sky130_fd_sc_hd__nand3_1 _1959_ (.A(_1370_),
    .B(reg2hw_4_),
    .C(_0292_),
    .Y(_0293_));
 sky130_fd_sc_hd__nor2_2 _1960_ (.A(_1355_),
    .B(net27),
    .Y(_0294_));
 sky130_fd_sc_hd__inv_4 _1961_ (.A(_0294_),
    .Y(_0295_));
 sky130_fd_sc_hd__nor2_1 _1962_ (.A(_1354_),
    .B(_0295_),
    .Y(_0296_));
 sky130_fd_sc_hd__inv_2 _1963_ (.A(_0296_),
    .Y(_0297_));
 sky130_fd_sc_hd__nor2_4 _1964_ (.A(_1353_),
    .B(_0297_),
    .Y(_0018_));
 sky130_fd_sc_hd__nand2_4 _1965_ (.A(_1355_),
    .B(net104),
    .Y(_0298_));
 sky130_fd_sc_hd__nor3_4 _1966_ (.A(_1353_),
    .B(_0298_),
    .C(net27),
    .Y(_0019_));
 sky130_fd_sc_hd__nor3_4 _1967_ (.A(_1353_),
    .B(net104),
    .C(_0295_),
    .Y(_0020_));
 sky130_fd_sc_hd__nor4_1 _1968_ (.A(net105),
    .B(_1353_),
    .C(net104),
    .D(net27),
    .Y(_0021_));
 sky130_fd_sc_hd__nor2_4 _1969_ (.A(net103),
    .B(_0297_),
    .Y(_0022_));
 sky130_fd_sc_hd__inv_1 _1970_ (.A(net91),
    .Y(_0299_));
 sky130_fd_sc_hd__nand2_4 _1971_ (.A(_0299_),
    .B(net90),
    .Y(u_uart_reg_axi_lite_o_35_));
 sky130_fd_sc_hd__nor3_4 _1972_ (.A(net103),
    .B(_0298_),
    .C(net27),
    .Y(_0023_));
 sky130_fd_sc_hd__o21ai_1 _1973_ (.A1(_1295_),
    .A2(_1329_),
    .B1(_1333_),
    .Y(_0300_));
 sky130_fd_sc_hd__xor2_1 _1974_ (.A(_1283_),
    .B(_0300_),
    .X(_0003_));
 sky130_fd_sc_hd__inv_1 _1975_ (.A(net87),
    .Y(_0301_));
 sky130_fd_sc_hd__inv_1 _1976_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_status_cnt_q_1_),
    .Y(_0302_));
 sky130_fd_sc_hd__nand2_1 _1977_ (.A(_0301_),
    .B(_0302_),
    .Y(u_uart_reg_axi_lite_o_0_));
 sky130_fd_sc_hd__inv_8 _1978_ (.A(net89),
    .Y(_0303_));
 sky130_fd_sc_hd__nand2_1 _1979_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_31_),
    .Y(_0304_));
 sky130_fd_sc_hd__nand2_1 _1980_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_64_),
    .B(net89),
    .Y(_0305_));
 sky130_fd_sc_hd__nand2_1 _1981_ (.A(_0304_),
    .B(_0305_),
    .Y(u_uart_reg_axi_lite_o_33_));
 sky130_fd_sc_hd__nand2_1 _1982_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_30_),
    .Y(_0306_));
 sky130_fd_sc_hd__nand2_1 _1983_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_63_),
    .Y(_0307_));
 sky130_fd_sc_hd__nand2_1 _1984_ (.A(_0306_),
    .B(_0307_),
    .Y(u_uart_reg_axi_lite_o_32_));
 sky130_fd_sc_hd__nand2_1 _1985_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_29_),
    .Y(_0308_));
 sky130_fd_sc_hd__nand2_1 _1986_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_62_),
    .Y(_0309_));
 sky130_fd_sc_hd__nand2_1 _1987_ (.A(_0308_),
    .B(_0309_),
    .Y(u_uart_reg_axi_lite_o_31_));
 sky130_fd_sc_hd__nand2_1 _1988_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_28_),
    .Y(_0310_));
 sky130_fd_sc_hd__nand2_1 _1989_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_61_),
    .Y(_0311_));
 sky130_fd_sc_hd__nand2_1 _1990_ (.A(_0310_),
    .B(_0311_),
    .Y(u_uart_reg_axi_lite_o_30_));
 sky130_fd_sc_hd__nand2_1 _1991_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_27_),
    .Y(_0312_));
 sky130_fd_sc_hd__nand2_1 _1992_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_60_),
    .Y(_0313_));
 sky130_fd_sc_hd__nand2_1 _1993_ (.A(_0312_),
    .B(_0313_),
    .Y(u_uart_reg_axi_lite_o_29_));
 sky130_fd_sc_hd__nand2_1 _1994_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_26_),
    .Y(_0314_));
 sky130_fd_sc_hd__nand2_1 _1995_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_59_),
    .Y(_0315_));
 sky130_fd_sc_hd__nand2_1 _1996_ (.A(_0314_),
    .B(_0315_),
    .Y(u_uart_reg_axi_lite_o_28_));
 sky130_fd_sc_hd__nand2_1 _1997_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_25_),
    .Y(_0316_));
 sky130_fd_sc_hd__nand2_1 _1998_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_58_),
    .Y(_0317_));
 sky130_fd_sc_hd__nand2_1 _1999_ (.A(_0316_),
    .B(_0317_),
    .Y(u_uart_reg_axi_lite_o_27_));
 sky130_fd_sc_hd__nand2_1 _2000_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_24_),
    .Y(_0318_));
 sky130_fd_sc_hd__nand2_1 _2001_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_57_),
    .Y(_0319_));
 sky130_fd_sc_hd__nand2_1 _2002_ (.A(_0318_),
    .B(_0319_),
    .Y(u_uart_reg_axi_lite_o_26_));
 sky130_fd_sc_hd__nand2_1 _2003_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_23_),
    .Y(_0320_));
 sky130_fd_sc_hd__nand2_1 _2004_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_56_),
    .Y(_0321_));
 sky130_fd_sc_hd__nand2_1 _2005_ (.A(_0320_),
    .B(_0321_),
    .Y(u_uart_reg_axi_lite_o_25_));
 sky130_fd_sc_hd__nand2_1 _2006_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_22_),
    .Y(_0322_));
 sky130_fd_sc_hd__nand2_1 _2007_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_55_),
    .Y(_0323_));
 sky130_fd_sc_hd__nand2_1 _2008_ (.A(_0322_),
    .B(_0323_),
    .Y(u_uart_reg_axi_lite_o_24_));
 sky130_fd_sc_hd__nand2_1 _2009_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_21_),
    .Y(_0324_));
 sky130_fd_sc_hd__nand2_1 _2010_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_54_),
    .Y(_0325_));
 sky130_fd_sc_hd__nand2_1 _2011_ (.A(_0324_),
    .B(_0325_),
    .Y(u_uart_reg_axi_lite_o_23_));
 sky130_fd_sc_hd__nand2_1 _2012_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_20_),
    .Y(_0326_));
 sky130_fd_sc_hd__nand2_1 _2013_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_53_),
    .Y(_0327_));
 sky130_fd_sc_hd__nand2_1 _2014_ (.A(_0326_),
    .B(_0327_),
    .Y(u_uart_reg_axi_lite_o_22_));
 sky130_fd_sc_hd__nand2_1 _2015_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_19_),
    .Y(_0328_));
 sky130_fd_sc_hd__nand2_1 _2016_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_52_),
    .Y(_0329_));
 sky130_fd_sc_hd__nand2_1 _2017_ (.A(_0328_),
    .B(_0329_),
    .Y(u_uart_reg_axi_lite_o_21_));
 sky130_fd_sc_hd__nand2_1 _2018_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_18_),
    .Y(_0330_));
 sky130_fd_sc_hd__nand2_1 _2019_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_51_),
    .Y(_0331_));
 sky130_fd_sc_hd__nand2_1 _2020_ (.A(_0330_),
    .B(_0331_),
    .Y(u_uart_reg_axi_lite_o_20_));
 sky130_fd_sc_hd__nand2_1 _2021_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_17_),
    .Y(_0332_));
 sky130_fd_sc_hd__nand2_1 _2022_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_50_),
    .Y(_0333_));
 sky130_fd_sc_hd__nand2_1 _2023_ (.A(_0332_),
    .B(_0333_),
    .Y(u_uart_reg_axi_lite_o_19_));
 sky130_fd_sc_hd__inv_1 _2024_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_16_),
    .Y(_0334_));
 sky130_fd_sc_hd__nand2_1 _2025_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_49_),
    .Y(_0335_));
 sky130_fd_sc_hd__o21ai_0 _2026_ (.A1(net88),
    .A2(_0334_),
    .B1(_0335_),
    .Y(u_uart_reg_axi_lite_o_18_));
 sky130_fd_sc_hd__inv_1 _2027_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_15_),
    .Y(_0336_));
 sky130_fd_sc_hd__nand2_1 _2028_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_48_),
    .Y(_0337_));
 sky130_fd_sc_hd__o21ai_0 _2029_ (.A1(net88),
    .A2(_0336_),
    .B1(_0337_),
    .Y(u_uart_reg_axi_lite_o_17_));
 sky130_fd_sc_hd__inv_1 _2030_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_14_),
    .Y(_0338_));
 sky130_fd_sc_hd__nand2_1 _2031_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_47_),
    .Y(_0339_));
 sky130_fd_sc_hd__o21ai_0 _2032_ (.A1(net88),
    .A2(_0338_),
    .B1(_0339_),
    .Y(u_uart_reg_axi_lite_o_16_));
 sky130_fd_sc_hd__inv_1 _2033_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_13_),
    .Y(_0340_));
 sky130_fd_sc_hd__nand2_1 _2034_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_46_),
    .Y(_0341_));
 sky130_fd_sc_hd__o21ai_0 _2035_ (.A1(net88),
    .A2(_0340_),
    .B1(_0341_),
    .Y(u_uart_reg_axi_lite_o_15_));
 sky130_fd_sc_hd__inv_1 _2036_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_12_),
    .Y(_0342_));
 sky130_fd_sc_hd__nand2_1 _2037_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_45_),
    .Y(_0343_));
 sky130_fd_sc_hd__o21ai_0 _2038_ (.A1(net88),
    .A2(_0342_),
    .B1(_0343_),
    .Y(u_uart_reg_axi_lite_o_14_));
 sky130_fd_sc_hd__inv_1 _2039_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_11_),
    .Y(_0344_));
 sky130_fd_sc_hd__nand2_1 _2040_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_44_),
    .Y(_0345_));
 sky130_fd_sc_hd__o21ai_0 _2041_ (.A1(net88),
    .A2(_0344_),
    .B1(_0345_),
    .Y(u_uart_reg_axi_lite_o_13_));
 sky130_fd_sc_hd__inv_1 _2042_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_10_),
    .Y(_0346_));
 sky130_fd_sc_hd__nand2_1 _2043_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_43_),
    .Y(_0347_));
 sky130_fd_sc_hd__o21ai_0 _2044_ (.A1(net88),
    .A2(_0346_),
    .B1(_0347_),
    .Y(u_uart_reg_axi_lite_o_12_));
 sky130_fd_sc_hd__inv_1 _2045_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_9_),
    .Y(_0348_));
 sky130_fd_sc_hd__nand2_1 _2046_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_42_),
    .Y(_0349_));
 sky130_fd_sc_hd__o21ai_0 _2047_ (.A1(net88),
    .A2(_0348_),
    .B1(_0349_),
    .Y(u_uart_reg_axi_lite_o_11_));
 sky130_fd_sc_hd__nand2_1 _2048_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_8_),
    .Y(_0350_));
 sky130_fd_sc_hd__nand2_1 _2049_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_41_),
    .Y(_0351_));
 sky130_fd_sc_hd__nand2_1 _2050_ (.A(_0350_),
    .B(_0351_),
    .Y(u_uart_reg_axi_lite_o_10_));
 sky130_fd_sc_hd__nand2_1 _2051_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_7_),
    .Y(_0352_));
 sky130_fd_sc_hd__nand2_1 _2052_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_40_),
    .Y(_0353_));
 sky130_fd_sc_hd__nand2_1 _2053_ (.A(_0352_),
    .B(_0353_),
    .Y(u_uart_reg_axi_lite_o_9_));
 sky130_fd_sc_hd__nand2_1 _2054_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_6_),
    .Y(_0354_));
 sky130_fd_sc_hd__nand2_1 _2055_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_39_),
    .Y(_0355_));
 sky130_fd_sc_hd__nand2_1 _2056_ (.A(_0354_),
    .B(_0355_),
    .Y(u_uart_reg_axi_lite_o_8_));
 sky130_fd_sc_hd__nand2_1 _2057_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_5_),
    .Y(_0356_));
 sky130_fd_sc_hd__nand2_1 _2058_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_38_),
    .Y(_0357_));
 sky130_fd_sc_hd__nand2_1 _2059_ (.A(_0356_),
    .B(_0357_),
    .Y(u_uart_reg_axi_lite_o_7_));
 sky130_fd_sc_hd__nand2_1 _2060_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_4_),
    .Y(_0358_));
 sky130_fd_sc_hd__nand2_1 _2061_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_37_),
    .Y(_0359_));
 sky130_fd_sc_hd__nand2_1 _2062_ (.A(_0358_),
    .B(_0359_),
    .Y(u_uart_reg_axi_lite_o_6_));
 sky130_fd_sc_hd__nand2_1 _2063_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_3_),
    .Y(_0360_));
 sky130_fd_sc_hd__nand2_1 _2064_ (.A(net89),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_36_),
    .Y(_0361_));
 sky130_fd_sc_hd__nand2_1 _2065_ (.A(_0360_),
    .B(_0361_),
    .Y(u_uart_reg_axi_lite_o_5_));
 sky130_fd_sc_hd__nand2_1 _2066_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_2_),
    .Y(_0362_));
 sky130_fd_sc_hd__nand2_1 _2067_ (.A(net89),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_35_),
    .Y(_0363_));
 sky130_fd_sc_hd__nand2_1 _2068_ (.A(_0362_),
    .B(_0363_),
    .Y(u_uart_reg_axi_lite_o_4_));
 sky130_fd_sc_hd__nand2_1 _2069_ (.A(_0303_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_1_),
    .Y(_0364_));
 sky130_fd_sc_hd__nand2_1 _2070_ (.A(net89),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_34_),
    .Y(_0365_));
 sky130_fd_sc_hd__nand2_1 _2071_ (.A(_0364_),
    .B(_0365_),
    .Y(u_uart_reg_axi_lite_o_3_));
 sky130_fd_sc_hd__inv_1 _2072_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_0_),
    .Y(_0366_));
 sky130_fd_sc_hd__nand2_1 _2073_ (.A(net88),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_33_),
    .Y(_0367_));
 sky130_fd_sc_hd__o21ai_0 _2074_ (.A1(net88),
    .A2(_0366_),
    .B1(_0367_),
    .Y(u_uart_reg_axi_lite_o_2_));
 sky130_fd_sc_hd__nor3_4 _2075_ (.A(net103),
    .B(net104),
    .C(_0295_),
    .Y(_0024_));
 sky130_fd_sc_hd__nor4_1 _2076_ (.A(net105),
    .B(net103),
    .C(net104),
    .D(net27),
    .Y(_0025_));
 sky130_fd_sc_hd__inv_1 _2077_ (.A(net111),
    .Y(_0368_));
 sky130_fd_sc_hd__nand2_1 _2078_ (.A(_0368_),
    .B(net112),
    .Y(_0369_));
 sky130_fd_sc_hd__xnor2_1 _2079_ (.A(u_uart_core_uart_rx_sreg_q_1_),
    .B(net75),
    .Y(_0370_));
 sky130_fd_sc_hd__xnor2_1 _2080_ (.A(net98),
    .B(net99),
    .Y(_0371_));
 sky130_fd_sc_hd__xnor2_1 _2081_ (.A(_0370_),
    .B(_0371_),
    .Y(_0372_));
 sky130_fd_sc_hd__xor2_1 _2082_ (.A(net93),
    .B(u_uart_core_uart_rx_sreg_q_9_),
    .X(_0373_));
 sky130_fd_sc_hd__xnor2_1 _2083_ (.A(net96),
    .B(net97),
    .Y(_0374_));
 sky130_fd_sc_hd__xor2_1 _2084_ (.A(net94),
    .B(net95),
    .X(_0375_));
 sky130_fd_sc_hd__xor2_1 _2085_ (.A(_0374_),
    .B(_0375_),
    .X(_0376_));
 sky130_fd_sc_hd__xor2_1 _2086_ (.A(_0373_),
    .B(_0376_),
    .X(_0377_));
 sky130_fd_sc_hd__inv_1 _2087_ (.A(net76),
    .Y(_0378_));
 sky130_fd_sc_hd__a21oi_1 _2088_ (.A1(_0377_),
    .A2(_0372_),
    .B1(_0378_),
    .Y(_0379_));
 sky130_fd_sc_hd__o21ai_0 _2089_ (.A1(_0372_),
    .A2(_0377_),
    .B1(_0379_),
    .Y(_0380_));
 sky130_fd_sc_hd__inv_1 _2090_ (.A(u_uart_core_uart_rx_sreg_q_10_),
    .Y(_0381_));
 sky130_fd_sc_hd__xnor2_1 _2091_ (.A(net116),
    .B(net112),
    .Y(_0382_));
 sky130_fd_sc_hd__xnor2_1 _2092_ (.A(net111),
    .B(net115),
    .Y(_0383_));
 sky130_fd_sc_hd__nand2_1 _2093_ (.A(_0382_),
    .B(_0383_),
    .Y(_0384_));
 sky130_fd_sc_hd__xnor2_1 _2094_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .Y(_0385_));
 sky130_fd_sc_hd__inv_4 _2095_ (.A(net109),
    .Y(_0386_));
 sky130_fd_sc_hd__nor2_1 _2096_ (.A(net113),
    .B(_0386_),
    .Y(_0387_));
 sky130_fd_sc_hd__inv_4 _2097_ (.A(net113),
    .Y(_0388_));
 sky130_fd_sc_hd__nor2_1 _2098_ (.A(net109),
    .B(_0388_),
    .Y(_0389_));
 sky130_fd_sc_hd__nor2_1 _2099_ (.A(_0387_),
    .B(_0389_),
    .Y(_0390_));
 sky130_fd_sc_hd__inv_6 _2100_ (.A(net114),
    .Y(_0391_));
 sky130_fd_sc_hd__nand2_1 _2101_ (.A(_0391_),
    .B(net110),
    .Y(_0392_));
 sky130_fd_sc_hd__inv_4 _2102_ (.A(net110),
    .Y(_0393_));
 sky130_fd_sc_hd__nand2_1 _2103_ (.A(_0393_),
    .B(net114),
    .Y(_0394_));
 sky130_fd_sc_hd__nand3_1 _2104_ (.A(_0390_),
    .B(_0392_),
    .C(_0394_),
    .Y(_0395_));
 sky130_fd_sc_hd__nor3_1 _2105_ (.A(_0384_),
    .B(_0385_),
    .C(_0395_),
    .Y(_0396_));
 sky130_fd_sc_hd__nor2_1 _2106_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_under_rst),
    .B(_0396_),
    .Y(_0397_));
 sky130_fd_sc_hd__nand2_1 _2107_ (.A(_0397_),
    .B(u_uart_core_rx_valid),
    .Y(_0398_));
 sky130_fd_sc_hd__nor2_1 _2108_ (.A(_0381_),
    .B(_0398_),
    .Y(_0399_));
 sky130_fd_sc_hd__nand2_1 _2109_ (.A(_0380_),
    .B(_0399_),
    .Y(_0400_));
 sky130_fd_sc_hd__inv_2 _2110_ (.A(_0400_),
    .Y(_0401_));
 sky130_fd_sc_hd__nand3_1 _2111_ (.A(_0401_),
    .B(_0393_),
    .C(net109),
    .Y(_0402_));
 sky130_fd_sc_hd__nor2_4 _2112_ (.A(net42),
    .B(net15),
    .Y(_0026_));
 sky130_fd_sc_hd__clkinv_1 _2113_ (.A(net112),
    .Y(_0403_));
 sky130_fd_sc_hd__nand2_1 _2114_ (.A(_0403_),
    .B(_0368_),
    .Y(_0404_));
 sky130_fd_sc_hd__nor2_4 _2115_ (.A(net41),
    .B(net15),
    .Y(_0027_));
 sky130_fd_sc_hd__nand2_4 _2116_ (.A(_0386_),
    .B(net110),
    .Y(_0405_));
 sky130_fd_sc_hd__nor2_1 _2117_ (.A(_0403_),
    .B(_0400_),
    .Y(_0406_));
 sky130_fd_sc_hd__nand2_1 _2118_ (.A(_0406_),
    .B(net111),
    .Y(_0407_));
 sky130_fd_sc_hd__nor2_4 _2119_ (.A(_0405_),
    .B(net14),
    .Y(_0028_));
 sky130_fd_sc_hd__nand3_1 _2120_ (.A(_0401_),
    .B(_0403_),
    .C(net111),
    .Y(_0408_));
 sky130_fd_sc_hd__nor2_4 _2121_ (.A(_0405_),
    .B(net13),
    .Y(_0029_));
 sky130_fd_sc_hd__nand3_1 _2122_ (.A(_0401_),
    .B(net110),
    .C(_0386_),
    .Y(_0409_));
 sky130_fd_sc_hd__nor2_4 _2123_ (.A(net42),
    .B(net12),
    .Y(_0030_));
 sky130_fd_sc_hd__nor2_4 _2124_ (.A(net41),
    .B(net12),
    .Y(_0031_));
 sky130_fd_sc_hd__nand2_4 _2125_ (.A(_0393_),
    .B(_0386_),
    .Y(_0410_));
 sky130_fd_sc_hd__nor2_4 _2126_ (.A(_0410_),
    .B(net14),
    .Y(_0032_));
 sky130_fd_sc_hd__nor2_4 _2127_ (.A(_0410_),
    .B(net13),
    .Y(_0033_));
 sky130_fd_sc_hd__clkinv_1 _2128_ (.A(net93),
    .Y(_0411_));
 sky130_fd_sc_hd__nand2_1 _2129_ (.A(net76),
    .B(net94),
    .Y(_0412_));
 sky130_fd_sc_hd__o21ai_2 _2130_ (.A1(net76),
    .A2(_0411_),
    .B1(_0412_),
    .Y(u_uart_core_rx_fifo_data_6_));
 sky130_fd_sc_hd__nand3_1 _2131_ (.A(_0401_),
    .B(_0393_),
    .C(_0386_),
    .Y(_0413_));
 sky130_fd_sc_hd__nor2_4 _2132_ (.A(net42),
    .B(net11),
    .Y(_0034_));
 sky130_fd_sc_hd__clkinv_1 _2133_ (.A(net94),
    .Y(_0414_));
 sky130_fd_sc_hd__nand2_1 _2134_ (.A(net76),
    .B(net95),
    .Y(_0415_));
 sky130_fd_sc_hd__o21ai_2 _2135_ (.A1(net76),
    .A2(_0414_),
    .B1(_0415_),
    .Y(u_uart_core_rx_fifo_data_5_));
 sky130_fd_sc_hd__clkinv_1 _2136_ (.A(net95),
    .Y(_0416_));
 sky130_fd_sc_hd__nand2_1 _2137_ (.A(net76),
    .B(net96),
    .Y(_0417_));
 sky130_fd_sc_hd__o21ai_2 _2138_ (.A1(net76),
    .A2(_0416_),
    .B1(_0417_),
    .Y(u_uart_core_rx_fifo_data_4_));
 sky130_fd_sc_hd__clkinv_1 _2139_ (.A(net96),
    .Y(_0418_));
 sky130_fd_sc_hd__nand2_1 _2140_ (.A(net76),
    .B(net97),
    .Y(_0419_));
 sky130_fd_sc_hd__o21ai_2 _2141_ (.A1(net76),
    .A2(_0418_),
    .B1(_0419_),
    .Y(u_uart_core_rx_fifo_data_3_));
 sky130_fd_sc_hd__clkinv_1 _2142_ (.A(net97),
    .Y(_0420_));
 sky130_fd_sc_hd__nand2_1 _2143_ (.A(net76),
    .B(net98),
    .Y(_0421_));
 sky130_fd_sc_hd__o21ai_2 _2144_ (.A1(net76),
    .A2(_0420_),
    .B1(_0421_),
    .Y(u_uart_core_rx_fifo_data_2_));
 sky130_fd_sc_hd__clkinv_1 _2145_ (.A(net98),
    .Y(_0422_));
 sky130_fd_sc_hd__nand2_1 _2146_ (.A(net76),
    .B(net99),
    .Y(_0423_));
 sky130_fd_sc_hd__o21ai_2 _2147_ (.A1(net76),
    .A2(_0422_),
    .B1(_0423_),
    .Y(u_uart_core_rx_fifo_data_1_));
 sky130_fd_sc_hd__clkinv_1 _2148_ (.A(net99),
    .Y(_0424_));
 sky130_fd_sc_hd__nand2_1 _2149_ (.A(net76),
    .B(u_uart_core_uart_rx_sreg_q_1_),
    .Y(_0425_));
 sky130_fd_sc_hd__o21ai_2 _2150_ (.A1(net76),
    .A2(_0424_),
    .B1(_0425_),
    .Y(u_uart_core_rx_fifo_data_0_));
 sky130_fd_sc_hd__nand2_4 _2151_ (.A(net110),
    .B(net109),
    .Y(_0426_));
 sky130_fd_sc_hd__nor2_4 _2152_ (.A(_0426_),
    .B(net14),
    .Y(_0035_));
 sky130_fd_sc_hd__nor2_4 _2153_ (.A(_0426_),
    .B(net13),
    .Y(_0036_));
 sky130_fd_sc_hd__nand3_1 _2154_ (.A(_0401_),
    .B(net110),
    .C(net109),
    .Y(_0427_));
 sky130_fd_sc_hd__nor2_4 _2155_ (.A(net42),
    .B(net10),
    .Y(_0037_));
 sky130_fd_sc_hd__nor2_4 _2156_ (.A(net41),
    .B(net10),
    .Y(_0038_));
 sky130_fd_sc_hd__nand2_4 _2157_ (.A(_0393_),
    .B(net109),
    .Y(_0428_));
 sky130_fd_sc_hd__nor2_4 _2158_ (.A(_0428_),
    .B(net14),
    .Y(_0039_));
 sky130_fd_sc_hd__nor2_4 _2159_ (.A(_0428_),
    .B(net13),
    .Y(_0040_));
 sky130_fd_sc_hd__nor2_4 _2160_ (.A(net41),
    .B(net11),
    .Y(_0041_));
 sky130_fd_sc_hd__xor2_1 _2161_ (.A(net82),
    .B(u_uart_core_nco_sum_q_0_),
    .X(_0002_));
 sky130_fd_sc_hd__nor2_1 _2162_ (.A(_1302_),
    .B(_1301_),
    .Y(_0429_));
 sky130_fd_sc_hd__xnor2_1 _2163_ (.A(_0429_),
    .B(_1312_),
    .Y(_0011_));
 sky130_fd_sc_hd__xor2_1 _2164_ (.A(_1342_),
    .B(_1336_),
    .X(_0005_));
 sky130_fd_sc_hd__xor2_1 _2165_ (.A(_1326_),
    .B(_1320_),
    .X(_0014_));
 sky130_fd_sc_hd__o22ai_1 _2166_ (.A1(net91),
    .A2(net90),
    .B1(net87),
    .B2(_0302_),
    .Y(_0430_));
 sky130_fd_sc_hd__inv_1 _2167_ (.A(_0430_),
    .Y(_0431_));
 sky130_fd_sc_hd__inv_1 _2168_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_status_cnt_q_1_),
    .Y(_0432_));
 sky130_fd_sc_hd__o22ai_1 _2169_ (.A1(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_status_cnt_q_0_),
    .A2(net84),
    .B1(net83),
    .B2(_0432_),
    .Y(_0433_));
 sky130_fd_sc_hd__a21oi_1 _2170_ (.A1(_0431_),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_stream_arbiter_i_arb_gen_rr_arb_i_arbiter_gen_arbiter_rr_q),
    .B1(_0433_),
    .Y(_0434_));
 sky130_fd_sc_hd__buf_2 _2171_ (.A(_0434_),
    .X(_0435_));
 sky130_fd_sc_hd__inv_1 _2172_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_9_),
    .Y(_0436_));
 sky130_fd_sc_hd__nand2_1 _2173_ (.A(_0436_),
    .B(net92),
    .Y(_0437_));
 sky130_fd_sc_hd__o21ai_0 _2174_ (.A1(net92),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_4_),
    .B1(_0437_),
    .Y(_0438_));
 sky130_fd_sc_hd__inv_1 _2175_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_81_),
    .Y(_0439_));
 sky130_fd_sc_hd__nand2_1 _2176_ (.A(_0439_),
    .B(net85),
    .Y(_0440_));
 sky130_fd_sc_hd__o211ai_1 _2177_ (.A1(net85),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_40_),
    .B1(_0440_),
    .C1(net26),
    .Y(_0441_));
 sky130_fd_sc_hd__o21a_1 _2178_ (.A1(net26),
    .A2(_0438_),
    .B1(_0441_),
    .X(_0442_));
 sky130_fd_sc_hd__nor2_1 _2179_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_1_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_0_),
    .Y(_0443_));
 sky130_fd_sc_hd__o21ai_0 _2180_ (.A1(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_6_),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_5_),
    .B1(net92),
    .Y(_0444_));
 sky130_fd_sc_hd__o21ai_1 _2181_ (.A1(net92),
    .A2(_0443_),
    .B1(_0444_),
    .Y(_0445_));
 sky130_fd_sc_hd__clkinv_1 _2182_ (.A(net85),
    .Y(_0446_));
 sky130_fd_sc_hd__inv_1 _2183_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_37_),
    .Y(_0447_));
 sky130_fd_sc_hd__inv_1 _2184_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_36_),
    .Y(_0448_));
 sky130_fd_sc_hd__nand4_1 _2185_ (.A(net26),
    .B(net46),
    .C(_0447_),
    .D(_0448_),
    .Y(_0449_));
 sky130_fd_sc_hd__inv_1 _2186_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_78_),
    .Y(_0450_));
 sky130_fd_sc_hd__inv_1 _2187_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_77_),
    .Y(_0451_));
 sky130_fd_sc_hd__nand4_1 _2188_ (.A(net26),
    .B(net85),
    .C(_0450_),
    .D(_0451_),
    .Y(_0452_));
 sky130_fd_sc_hd__o211ai_4 _2189_ (.A1(net26),
    .A2(_0445_),
    .B1(_0449_),
    .C1(_0452_),
    .Y(_0453_));
 sky130_fd_sc_hd__nand2_4 _2190_ (.A(net20),
    .B(_0453_),
    .Y(_0454_));
 sky130_fd_sc_hd__inv_1 _2191_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_80_),
    .Y(_0455_));
 sky130_fd_sc_hd__nor2_1 _2192_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_39_),
    .B(net85),
    .Y(_0456_));
 sky130_fd_sc_hd__a21oi_1 _2193_ (.A1(_0455_),
    .A2(net85),
    .B1(_0456_),
    .Y(_0457_));
 sky130_fd_sc_hd__inv_1 _2194_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_8_),
    .Y(_0458_));
 sky130_fd_sc_hd__nor2_1 _2195_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_3_),
    .B(net92),
    .Y(_0459_));
 sky130_fd_sc_hd__a211oi_1 _2196_ (.A1(_0458_),
    .A2(net92),
    .B1(_0459_),
    .C1(net26),
    .Y(_0460_));
 sky130_fd_sc_hd__a21oi_4 _2197_ (.A1(net26),
    .A2(_0457_),
    .B1(_0460_),
    .Y(_0461_));
 sky130_fd_sc_hd__inv_1 _2198_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_7_),
    .Y(_0462_));
 sky130_fd_sc_hd__nand2_1 _2199_ (.A(_0462_),
    .B(net92),
    .Y(_0463_));
 sky130_fd_sc_hd__o21ai_0 _2200_ (.A1(net92),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_2_),
    .B1(_0463_),
    .Y(_0464_));
 sky130_fd_sc_hd__inv_1 _2201_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_79_),
    .Y(_0465_));
 sky130_fd_sc_hd__nand2_1 _2202_ (.A(_0465_),
    .B(net85),
    .Y(_0466_));
 sky130_fd_sc_hd__o211ai_1 _2203_ (.A1(net85),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_38_),
    .B1(_0466_),
    .C1(net26),
    .Y(_0467_));
 sky130_fd_sc_hd__o21a_1 _2204_ (.A1(net26),
    .A2(_0464_),
    .B1(_0467_),
    .X(_0468_));
 sky130_fd_sc_hd__inv_1 _2205_ (.A(_0433_),
    .Y(_0469_));
 sky130_fd_sc_hd__nor2_2 _2206_ (.A(_0469_),
    .B(_0431_),
    .Y(_0470_));
 sky130_fd_sc_hd__nand2_4 _2207_ (.A(_0461_),
    .B(_0453_),
    .Y(_0471_));
 sky130_fd_sc_hd__nand2_4 _2208_ (.A(_0471_),
    .B(_0454_),
    .Y(_0472_));
 sky130_fd_sc_hd__clkinv_1 _2209_ (.A(net26),
    .Y(_0473_));
 sky130_fd_sc_hd__inv_1 _2210_ (.A(net20),
    .Y(_0474_));
 sky130_fd_sc_hd__nand4_1 _2211_ (.A(_0474_),
    .B(_0453_),
    .C(_0461_),
    .D(net19),
    .Y(_0475_));
 sky130_fd_sc_hd__nor2_1 _2212_ (.A(net19),
    .B(_0471_),
    .Y(_0476_));
 sky130_fd_sc_hd__inv_1 _2213_ (.A(_0476_),
    .Y(_0477_));
 sky130_fd_sc_hd__nor2_1 _2214_ (.A(_0474_),
    .B(_0477_),
    .Y(_0478_));
 sky130_fd_sc_hd__inv_2 _2215_ (.A(_0478_),
    .Y(_0479_));
 sky130_fd_sc_hd__o211ai_1 _2216_ (.A1(_0454_),
    .A2(_0461_),
    .B1(_0475_),
    .C1(_0479_),
    .Y(_0480_));
 sky130_fd_sc_hd__inv_1 _2217_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_41_),
    .Y(_0481_));
 sky130_fd_sc_hd__nand2_1 _2218_ (.A(_0481_),
    .B(net85),
    .Y(_0482_));
 sky130_fd_sc_hd__o21ai_0 _2219_ (.A1(net85),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_0_),
    .B1(_0482_),
    .Y(_0483_));
 sky130_fd_sc_hd__nand3_1 _2220_ (.A(net46),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_2_),
    .C(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_1_),
    .Y(_0484_));
 sky130_fd_sc_hd__nand3_1 _2221_ (.A(net85),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_43_),
    .C(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_42_),
    .Y(_0485_));
 sky130_fd_sc_hd__a21oi_1 _2222_ (.A1(_0484_),
    .A2(_0485_),
    .B1(_0483_),
    .Y(_0486_));
 sky130_fd_sc_hd__nor2_1 _2223_ (.A(net20),
    .B(_0477_),
    .Y(_0487_));
 sky130_fd_sc_hd__inv_2 _2224_ (.A(_0487_),
    .Y(_0488_));
 sky130_fd_sc_hd__lpflow_clkinvkapwr_1 _2225_ (.A(net19),
    .Y(_0489_));
 sky130_fd_sc_hd__nor3_1 _2226_ (.A(_0474_),
    .B(_0489_),
    .C(_0471_),
    .Y(_0490_));
 sky130_fd_sc_hd__buf_12 _2227_ (.A(_0490_),
    .X(_0491_));
 sky130_fd_sc_hd__inv_4 _2228_ (.A(_0491_),
    .Y(_0492_));
 sky130_fd_sc_hd__o21ai_0 _2229_ (.A1(_0486_),
    .A2(_0488_),
    .B1(_0492_),
    .Y(_0493_));
 sky130_fd_sc_hd__inv_1 _2230_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_3_),
    .Y(_0494_));
 sky130_fd_sc_hd__nor2_1 _2231_ (.A(net85),
    .B(_0494_),
    .Y(_0495_));
 sky130_fd_sc_hd__inv_1 _2232_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_44_),
    .Y(_0496_));
 sky130_fd_sc_hd__nor2_1 _2233_ (.A(net46),
    .B(_0496_),
    .Y(_0497_));
 sky130_fd_sc_hd__o21ai_0 _2234_ (.A1(_0495_),
    .A2(_0497_),
    .B1(_0486_),
    .Y(_0498_));
 sky130_fd_sc_hd__a22oi_1 _2235_ (.A1(_0480_),
    .A2(_0483_),
    .B1(_0493_),
    .B2(_0498_),
    .Y(_0499_));
 sky130_fd_sc_hd__o22a_4 _2236_ (.A1(_0470_),
    .A2(_0472_),
    .B1(_0473_),
    .B2(_0499_),
    .X(_0500_));
 sky130_fd_sc_hd__nand2_4 _2237_ (.A(_0500_),
    .B(net26),
    .Y(_0501_));
 sky130_fd_sc_hd__nor4_4 _2238_ (.A(_0454_),
    .B(_0461_),
    .C(net19),
    .D(_0501_),
    .Y(u_uart_reg_u_reg_core_reg_we_check_3_));
 sky130_fd_sc_hd__inv_1 _2239_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_10_),
    .Y(_0502_));
 sky130_fd_sc_hd__nand2_1 _2240_ (.A(net85),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_51_),
    .Y(_0503_));
 sky130_fd_sc_hd__o21ai_0 _2241_ (.A1(net85),
    .A2(_0502_),
    .B1(_0503_),
    .Y(_0504_));
 sky130_fd_sc_hd__mux2_1 _2242_ (.A0(net67),
    .A1(_0504_),
    .S(u_uart_reg_u_reg_core_reg_we_check_3_),
    .X(_0042_));
 sky130_fd_sc_hd__inv_1 _2243_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_9_),
    .Y(_0505_));
 sky130_fd_sc_hd__nand2_1 _2244_ (.A(net85),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_50_),
    .Y(_0506_));
 sky130_fd_sc_hd__o21ai_0 _2245_ (.A1(net85),
    .A2(_0505_),
    .B1(_0506_),
    .Y(_0507_));
 sky130_fd_sc_hd__mux2_1 _2246_ (.A0(net68),
    .A1(_0507_),
    .S(u_uart_reg_u_reg_core_reg_we_check_3_),
    .X(_0043_));
 sky130_fd_sc_hd__inv_1 _2247_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_8_),
    .Y(_0508_));
 sky130_fd_sc_hd__nand2_1 _2248_ (.A(net85),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_49_),
    .Y(_0509_));
 sky130_fd_sc_hd__o21ai_0 _2249_ (.A1(net85),
    .A2(_0508_),
    .B1(_0509_),
    .Y(_0510_));
 sky130_fd_sc_hd__mux2_1 _2250_ (.A0(net69),
    .A1(_0510_),
    .S(u_uart_reg_u_reg_core_reg_we_check_3_),
    .X(_0044_));
 sky130_fd_sc_hd__inv_1 _2251_ (.A(net70),
    .Y(_0511_));
 sky130_fd_sc_hd__inv_1 _2252_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_7_),
    .Y(_0512_));
 sky130_fd_sc_hd__nand2_1 _2253_ (.A(net46),
    .B(_0512_),
    .Y(_0513_));
 sky130_fd_sc_hd__o211ai_1 _2254_ (.A1(net46),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_48_),
    .B1(_0513_),
    .C1(u_uart_reg_u_reg_core_reg_we_check_3_),
    .Y(_0514_));
 sky130_fd_sc_hd__o21ai_0 _2255_ (.A1(_0511_),
    .A2(u_uart_reg_u_reg_core_reg_we_check_3_),
    .B1(_0514_),
    .Y(_0045_));
 sky130_fd_sc_hd__inv_1 _2256_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_6_),
    .Y(_0515_));
 sky130_fd_sc_hd__nand2_1 _2257_ (.A(net85),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_47_),
    .Y(_0516_));
 sky130_fd_sc_hd__o21ai_0 _2258_ (.A1(net85),
    .A2(_0515_),
    .B1(_0516_),
    .Y(_0517_));
 sky130_fd_sc_hd__mux2_1 _2259_ (.A0(net71),
    .A1(_0517_),
    .S(u_uart_reg_u_reg_core_reg_we_check_3_),
    .X(_0046_));
 sky130_fd_sc_hd__inv_1 _2260_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_5_),
    .Y(_0518_));
 sky130_fd_sc_hd__nand2_1 _2261_ (.A(net85),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_46_),
    .Y(_0519_));
 sky130_fd_sc_hd__o21ai_0 _2262_ (.A1(net85),
    .A2(_0518_),
    .B1(_0519_),
    .Y(_0520_));
 sky130_fd_sc_hd__mux2_1 _2263_ (.A0(net72),
    .A1(_0520_),
    .S(u_uart_reg_u_reg_core_reg_we_check_3_),
    .X(_0047_));
 sky130_fd_sc_hd__inv_1 _2264_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_4_),
    .Y(_0521_));
 sky130_fd_sc_hd__nand2_1 _2265_ (.A(net85),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_45_),
    .Y(_0522_));
 sky130_fd_sc_hd__o21ai_0 _2266_ (.A1(net85),
    .A2(_0521_),
    .B1(_0522_),
    .Y(_0523_));
 sky130_fd_sc_hd__mux2_1 _2267_ (.A0(net73),
    .A1(_0523_),
    .S(u_uart_reg_u_reg_core_reg_we_check_3_),
    .X(_0048_));
 sky130_fd_sc_hd__nor2_4 _2268_ (.A(_0492_),
    .B(_0501_),
    .Y(_0524_));
 sky130_fd_sc_hd__buf_2 _2269_ (.A(_0524_),
    .X(_0525_));
 sky130_fd_sc_hd__inv_1 _2270_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_34_),
    .Y(_0526_));
 sky130_fd_sc_hd__nand2_1 _2271_ (.A(net46),
    .B(_0526_),
    .Y(_0527_));
 sky130_fd_sc_hd__o211ai_1 _2272_ (.A1(net46),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_75_),
    .B1(_0527_),
    .C1(_0524_),
    .Y(_0528_));
 sky130_fd_sc_hd__o21ai_0 _2273_ (.A1(_1274_),
    .A2(net9),
    .B1(_0528_),
    .Y(_0049_));
 sky130_fd_sc_hd__inv_1 _2274_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_33_),
    .Y(_0529_));
 sky130_fd_sc_hd__nand2_1 _2275_ (.A(net46),
    .B(_0529_),
    .Y(_0530_));
 sky130_fd_sc_hd__o211ai_1 _2276_ (.A1(net46),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_74_),
    .B1(_0530_),
    .C1(_0524_),
    .Y(_0531_));
 sky130_fd_sc_hd__o21ai_0 _2277_ (.A1(_1338_),
    .A2(net9),
    .B1(_0531_),
    .Y(_0050_));
 sky130_fd_sc_hd__nand2_1 _2278_ (.A(net85),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_73_),
    .Y(_0532_));
 sky130_fd_sc_hd__nand2_1 _2279_ (.A(net46),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_32_),
    .Y(_0533_));
 sky130_fd_sc_hd__nor2_1 _2280_ (.A(net78),
    .B(net9),
    .Y(_0534_));
 sky130_fd_sc_hd__a31oi_1 _2281_ (.A1(net9),
    .A2(_0532_),
    .A3(_0533_),
    .B1(_0534_),
    .Y(_0051_));
 sky130_fd_sc_hd__inv_1 _2282_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_31_),
    .Y(_0535_));
 sky130_fd_sc_hd__nand2_1 _2283_ (.A(net46),
    .B(_0535_),
    .Y(_0536_));
 sky130_fd_sc_hd__o211ai_1 _2284_ (.A1(net46),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_72_),
    .B1(_0536_),
    .C1(_0524_),
    .Y(_0537_));
 sky130_fd_sc_hd__o21ai_0 _2285_ (.A1(_1279_),
    .A2(net9),
    .B1(_0537_),
    .Y(_0052_));
 sky130_fd_sc_hd__nand2_1 _2286_ (.A(net85),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_71_),
    .Y(_0538_));
 sky130_fd_sc_hd__nand2_1 _2287_ (.A(net46),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_30_),
    .Y(_0539_));
 sky130_fd_sc_hd__nor2_1 _2288_ (.A(net79),
    .B(net9),
    .Y(_0540_));
 sky130_fd_sc_hd__a31oi_1 _2289_ (.A1(net9),
    .A2(_0538_),
    .A3(_0539_),
    .B1(_0540_),
    .Y(_0053_));
 sky130_fd_sc_hd__inv_1 _2290_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_29_),
    .Y(_0541_));
 sky130_fd_sc_hd__nand2_1 _2291_ (.A(net46),
    .B(_0541_),
    .Y(_0542_));
 sky130_fd_sc_hd__o211ai_1 _2292_ (.A1(net46),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_70_),
    .B1(_0542_),
    .C1(_0524_),
    .Y(_0543_));
 sky130_fd_sc_hd__o21ai_0 _2293_ (.A1(_1286_),
    .A2(net9),
    .B1(_0543_),
    .Y(_0054_));
 sky130_fd_sc_hd__inv_1 _2294_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_28_),
    .Y(_0544_));
 sky130_fd_sc_hd__nand2_1 _2295_ (.A(net46),
    .B(_0544_),
    .Y(_0545_));
 sky130_fd_sc_hd__o211ai_1 _2296_ (.A1(net46),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_69_),
    .B1(_0545_),
    .C1(_0524_),
    .Y(_0546_));
 sky130_fd_sc_hd__o21ai_0 _2297_ (.A1(_1291_),
    .A2(net9),
    .B1(_0546_),
    .Y(_0055_));
 sky130_fd_sc_hd__inv_1 _2298_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_27_),
    .Y(_0547_));
 sky130_fd_sc_hd__nand2_1 _2299_ (.A(net46),
    .B(_0547_),
    .Y(_0548_));
 sky130_fd_sc_hd__o211ai_1 _2300_ (.A1(net46),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_68_),
    .B1(_0548_),
    .C1(_0524_),
    .Y(_0549_));
 sky130_fd_sc_hd__o21ai_0 _2301_ (.A1(_1322_),
    .A2(net9),
    .B1(_0549_),
    .Y(_0056_));
 sky130_fd_sc_hd__nand2_1 _2302_ (.A(net85),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_67_),
    .Y(_0550_));
 sky130_fd_sc_hd__nand2_1 _2303_ (.A(net46),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_26_),
    .Y(_0551_));
 sky130_fd_sc_hd__nor2_1 _2304_ (.A(net80),
    .B(net9),
    .Y(_0552_));
 sky130_fd_sc_hd__a31oi_1 _2305_ (.A1(net9),
    .A2(_0550_),
    .A3(_0551_),
    .B1(_0552_),
    .Y(_0057_));
 sky130_fd_sc_hd__inv_1 _2306_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_25_),
    .Y(_0553_));
 sky130_fd_sc_hd__nand2_1 _2307_ (.A(net46),
    .B(_0553_),
    .Y(_0554_));
 sky130_fd_sc_hd__o211ai_1 _2308_ (.A1(net46),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_66_),
    .B1(_0554_),
    .C1(_0524_),
    .Y(_0555_));
 sky130_fd_sc_hd__o21ai_0 _2309_ (.A1(_1317_),
    .A2(net9),
    .B1(_0555_),
    .Y(_0058_));
 sky130_fd_sc_hd__nand2_1 _2310_ (.A(net85),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_65_),
    .Y(_0556_));
 sky130_fd_sc_hd__nand2_1 _2311_ (.A(net46),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_24_),
    .Y(_0557_));
 sky130_fd_sc_hd__nor2_1 _2312_ (.A(net81),
    .B(net9),
    .Y(_0558_));
 sky130_fd_sc_hd__a31oi_1 _2313_ (.A1(net9),
    .A2(_0556_),
    .A3(_0557_),
    .B1(_0558_),
    .Y(_0059_));
 sky130_fd_sc_hd__inv_1 _2314_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_23_),
    .Y(_0559_));
 sky130_fd_sc_hd__nand2_1 _2315_ (.A(net46),
    .B(_0559_),
    .Y(_0560_));
 sky130_fd_sc_hd__o211ai_1 _2316_ (.A1(net46),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_64_),
    .B1(_0560_),
    .C1(_0524_),
    .Y(_0561_));
 sky130_fd_sc_hd__o21ai_0 _2317_ (.A1(_1299_),
    .A2(net9),
    .B1(_0561_),
    .Y(_0060_));
 sky130_fd_sc_hd__inv_1 _2318_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_22_),
    .Y(_0562_));
 sky130_fd_sc_hd__nand2_1 _2319_ (.A(net46),
    .B(_0562_),
    .Y(_0563_));
 sky130_fd_sc_hd__o211ai_1 _2320_ (.A1(net46),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_63_),
    .B1(_0563_),
    .C1(_0524_),
    .Y(_0564_));
 sky130_fd_sc_hd__o21ai_0 _2321_ (.A1(_1304_),
    .A2(net9),
    .B1(_0564_),
    .Y(_0061_));
 sky130_fd_sc_hd__nand2_1 _2322_ (.A(net85),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_62_),
    .Y(_0565_));
 sky130_fd_sc_hd__nand2_1 _2323_ (.A(net46),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_21_),
    .Y(_0566_));
 sky130_fd_sc_hd__nor2_1 _2324_ (.A(reg2hw_42_),
    .B(net9),
    .Y(_0567_));
 sky130_fd_sc_hd__a31oi_1 _2325_ (.A1(net9),
    .A2(_0565_),
    .A3(_0566_),
    .B1(_0567_),
    .Y(_0062_));
 sky130_fd_sc_hd__inv_1 _2326_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_20_),
    .Y(_0568_));
 sky130_fd_sc_hd__nand2_1 _2327_ (.A(net46),
    .B(_0568_),
    .Y(_0569_));
 sky130_fd_sc_hd__o21ai_0 _2328_ (.A1(net46),
    .A2(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_61_),
    .B1(_0569_),
    .Y(_0570_));
 sky130_fd_sc_hd__nor2_1 _2329_ (.A(net82),
    .B(net9),
    .Y(_0571_));
 sky130_fd_sc_hd__a21oi_1 _2330_ (.A1(net9),
    .A2(_0570_),
    .B1(_0571_),
    .Y(_0063_));
 sky130_fd_sc_hd__or2_0 _2331_ (.A(net83),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_status_cnt_q_1_),
    .X(u_uart_reg_axi_lite_o_36_));
 sky130_fd_sc_hd__nand2_1 _2332_ (.A(u_uart_reg_axi_lite_o_36_),
    .B(axi_lite_i[10]),
    .Y(_0572_));
 sky130_fd_sc_hd__xnor2_1 _2333_ (.A(_0572_),
    .B(net26),
    .Y(_0573_));
 sky130_fd_sc_hd__xor2_1 _2334_ (.A(net83),
    .B(_0573_),
    .X(_0064_));
 sky130_fd_sc_hd__nor2_1 _2335_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_write_pointer_q),
    .B(_0473_),
    .Y(_0574_));
 sky130_fd_sc_hd__nor2_1 _2336_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_mem_q_0_),
    .B(_0574_),
    .Y(_0575_));
 sky130_fd_sc_hd__a21oi_1 _2337_ (.A1(_0500_),
    .A2(_0574_),
    .B1(_0575_),
    .Y(_0065_));
 sky130_fd_sc_hd__inv_1 _2338_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_status_cnt_q_0_),
    .Y(_0576_));
 sky130_fd_sc_hd__nand2_1 _2339_ (.A(axi_lite_i[48]),
    .B(axi_lite_i[11]),
    .Y(_0577_));
 sky130_fd_sc_hd__a21oi_2 _2340_ (.A1(_0576_),
    .A2(net84),
    .B1(_0577_),
    .Y(u_uart_reg_axi_lite_o_39_));
 sky130_fd_sc_hd__xor2_1 _2341_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_status_cnt_q_0_),
    .B(net26),
    .X(_0578_));
 sky130_fd_sc_hd__xor2_1 _2342_ (.A(u_uart_reg_axi_lite_o_39_),
    .B(_0578_),
    .X(_0066_));
 sky130_fd_sc_hd__inv_1 _2343_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_write_pointer_q),
    .Y(_0579_));
 sky130_fd_sc_hd__clkinv_1 _2344_ (.A(u_uart_reg_axi_lite_o_39_),
    .Y(_0580_));
 sky130_fd_sc_hd__nor2_4 _2345_ (.A(_0579_),
    .B(_0580_),
    .Y(_0581_));
 sky130_fd_sc_hd__buf_2 _2346_ (.A(_0581_),
    .X(_0582_));
 sky130_fd_sc_hd__mux2_1 _2347_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_43_),
    .A1(axi_lite_i[14]),
    .S(net25),
    .X(_0067_));
 sky130_fd_sc_hd__mux2_1 _2348_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_42_),
    .A1(axi_lite_i[13]),
    .S(net25),
    .X(_0068_));
 sky130_fd_sc_hd__nand2_1 _2349_ (.A(net25),
    .B(axi_lite_i[12]),
    .Y(_0583_));
 sky130_fd_sc_hd__o21ai_0 _2350_ (.A1(_0481_),
    .A2(net25),
    .B1(_0583_),
    .Y(_0069_));
 sky130_fd_sc_hd__mux2_1 _2351_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_75_),
    .A1(axi_lite_i[46]),
    .S(net25),
    .X(_0070_));
 sky130_fd_sc_hd__mux2_1 _2352_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_74_),
    .A1(axi_lite_i[45]),
    .S(net25),
    .X(_0071_));
 sky130_fd_sc_hd__mux2_1 _2353_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_73_),
    .A1(axi_lite_i[44]),
    .S(net25),
    .X(_0072_));
 sky130_fd_sc_hd__mux2_1 _2354_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_72_),
    .A1(axi_lite_i[43]),
    .S(net25),
    .X(_0073_));
 sky130_fd_sc_hd__mux2_1 _2355_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_71_),
    .A1(axi_lite_i[42]),
    .S(net25),
    .X(_0074_));
 sky130_fd_sc_hd__mux2_1 _2356_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_70_),
    .A1(axi_lite_i[41]),
    .S(net25),
    .X(_0075_));
 sky130_fd_sc_hd__mux2_1 _2357_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_69_),
    .A1(axi_lite_i[40]),
    .S(net25),
    .X(_0076_));
 sky130_fd_sc_hd__mux2_1 _2358_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_68_),
    .A1(axi_lite_i[39]),
    .S(net25),
    .X(_0077_));
 sky130_fd_sc_hd__mux2_1 _2359_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_67_),
    .A1(axi_lite_i[38]),
    .S(net25),
    .X(_0078_));
 sky130_fd_sc_hd__mux2_1 _2360_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_66_),
    .A1(axi_lite_i[37]),
    .S(net25),
    .X(_0079_));
 sky130_fd_sc_hd__mux2_1 _2361_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_65_),
    .A1(axi_lite_i[36]),
    .S(net25),
    .X(_0080_));
 sky130_fd_sc_hd__mux2_1 _2362_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_64_),
    .A1(axi_lite_i[35]),
    .S(net25),
    .X(_0081_));
 sky130_fd_sc_hd__mux2_1 _2363_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_63_),
    .A1(axi_lite_i[34]),
    .S(net25),
    .X(_0082_));
 sky130_fd_sc_hd__mux2_1 _2364_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_62_),
    .A1(axi_lite_i[33]),
    .S(net25),
    .X(_0083_));
 sky130_fd_sc_hd__mux2_1 _2365_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_61_),
    .A1(axi_lite_i[32]),
    .S(_0582_),
    .X(_0084_));
 sky130_fd_sc_hd__mux2_1 _2366_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_52_),
    .A1(axi_lite_i[23]),
    .S(_0581_),
    .X(_0085_));
 sky130_fd_sc_hd__mux2_1 _2367_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_51_),
    .A1(axi_lite_i[22]),
    .S(_0581_),
    .X(_0086_));
 sky130_fd_sc_hd__mux2_1 _2368_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_50_),
    .A1(axi_lite_i[21]),
    .S(_0581_),
    .X(_0087_));
 sky130_fd_sc_hd__mux2_1 _2369_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_49_),
    .A1(axi_lite_i[20]),
    .S(_0581_),
    .X(_0088_));
 sky130_fd_sc_hd__mux2_1 _2370_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_48_),
    .A1(axi_lite_i[19]),
    .S(_0581_),
    .X(_0089_));
 sky130_fd_sc_hd__mux2_1 _2371_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_47_),
    .A1(axi_lite_i[18]),
    .S(_0581_),
    .X(_0090_));
 sky130_fd_sc_hd__mux2_1 _2372_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_46_),
    .A1(axi_lite_i[17]),
    .S(_0581_),
    .X(_0091_));
 sky130_fd_sc_hd__mux2_1 _2373_ (.A0(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_45_),
    .A1(axi_lite_i[16]),
    .S(_0581_),
    .X(_0092_));
 sky130_fd_sc_hd__nand2_1 _2374_ (.A(net25),
    .B(axi_lite_i[55]),
    .Y(_0584_));
 sky130_fd_sc_hd__o21ai_0 _2375_ (.A1(_0455_),
    .A2(net25),
    .B1(_0584_),
    .Y(_0093_));
 sky130_fd_sc_hd__nand2_1 _2376_ (.A(net25),
    .B(axi_lite_i[54]),
    .Y(_0585_));
 sky130_fd_sc_hd__o21ai_0 _2377_ (.A1(_0465_),
    .A2(net25),
    .B1(_0585_),
    .Y(_0094_));
 sky130_fd_sc_hd__nand2_1 _2378_ (.A(net25),
    .B(axi_lite_i[53]),
    .Y(_0586_));
 sky130_fd_sc_hd__o21ai_0 _2379_ (.A1(_0450_),
    .A2(net25),
    .B1(_0586_),
    .Y(_0095_));
 sky130_fd_sc_hd__nand2_1 _2380_ (.A(net25),
    .B(axi_lite_i[52]),
    .Y(_0587_));
 sky130_fd_sc_hd__o21ai_0 _2381_ (.A1(_0451_),
    .A2(net25),
    .B1(_0587_),
    .Y(_0096_));
 sky130_fd_sc_hd__nor2_1 _2382_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_write_pointer_q),
    .B(_0580_),
    .Y(_0588_));
 sky130_fd_sc_hd__inv_4 _2383_ (.A(net28),
    .Y(_0589_));
 sky130_fd_sc_hd__nand2_1 _2384_ (.A(_0589_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_2_),
    .Y(_0590_));
 sky130_fd_sc_hd__buf_2 _2385_ (.A(net28),
    .X(_0591_));
 sky130_fd_sc_hd__nand2_1 _2386_ (.A(net24),
    .B(axi_lite_i[14]),
    .Y(_0592_));
 sky130_fd_sc_hd__nand2_1 _2387_ (.A(_0590_),
    .B(_0592_),
    .Y(_0097_));
 sky130_fd_sc_hd__nand2_1 _2388_ (.A(_0589_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_1_),
    .Y(_0593_));
 sky130_fd_sc_hd__nand2_1 _2389_ (.A(net24),
    .B(axi_lite_i[13]),
    .Y(_0594_));
 sky130_fd_sc_hd__nand2_1 _2390_ (.A(_0593_),
    .B(_0594_),
    .Y(_0098_));
 sky130_fd_sc_hd__nand2_1 _2391_ (.A(_0589_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_0_),
    .Y(_0595_));
 sky130_fd_sc_hd__nand2_1 _2392_ (.A(net24),
    .B(axi_lite_i[12]),
    .Y(_0596_));
 sky130_fd_sc_hd__nand2_1 _2393_ (.A(_0595_),
    .B(_0596_),
    .Y(_0099_));
 sky130_fd_sc_hd__nand2_1 _2394_ (.A(net24),
    .B(axi_lite_i[46]),
    .Y(_0597_));
 sky130_fd_sc_hd__o21ai_0 _2395_ (.A1(_0526_),
    .A2(net28),
    .B1(_0597_),
    .Y(_0100_));
 sky130_fd_sc_hd__nand2_1 _2396_ (.A(net24),
    .B(axi_lite_i[45]),
    .Y(_0598_));
 sky130_fd_sc_hd__o21ai_0 _2397_ (.A1(_0529_),
    .A2(net28),
    .B1(_0598_),
    .Y(_0101_));
 sky130_fd_sc_hd__nand2_1 _2398_ (.A(_0589_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_32_),
    .Y(_0599_));
 sky130_fd_sc_hd__nand2_1 _2399_ (.A(net24),
    .B(axi_lite_i[44]),
    .Y(_0600_));
 sky130_fd_sc_hd__nand2_1 _2400_ (.A(_0599_),
    .B(_0600_),
    .Y(_0102_));
 sky130_fd_sc_hd__nand2_1 _2401_ (.A(net24),
    .B(axi_lite_i[43]),
    .Y(_0601_));
 sky130_fd_sc_hd__o21ai_0 _2402_ (.A1(_0535_),
    .A2(net28),
    .B1(_0601_),
    .Y(_0103_));
 sky130_fd_sc_hd__nand2_1 _2403_ (.A(_0589_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_30_),
    .Y(_0602_));
 sky130_fd_sc_hd__nand2_1 _2404_ (.A(net24),
    .B(axi_lite_i[42]),
    .Y(_0603_));
 sky130_fd_sc_hd__nand2_1 _2405_ (.A(_0602_),
    .B(_0603_),
    .Y(_0104_));
 sky130_fd_sc_hd__nand2_1 _2406_ (.A(net24),
    .B(axi_lite_i[41]),
    .Y(_0604_));
 sky130_fd_sc_hd__o21ai_0 _2407_ (.A1(_0541_),
    .A2(net28),
    .B1(_0604_),
    .Y(_0105_));
 sky130_fd_sc_hd__nand2_1 _2408_ (.A(net24),
    .B(axi_lite_i[40]),
    .Y(_0605_));
 sky130_fd_sc_hd__o21ai_0 _2409_ (.A1(_0544_),
    .A2(net28),
    .B1(_0605_),
    .Y(_0106_));
 sky130_fd_sc_hd__nand2_1 _2410_ (.A(net24),
    .B(axi_lite_i[39]),
    .Y(_0606_));
 sky130_fd_sc_hd__o21ai_0 _2411_ (.A1(_0547_),
    .A2(net28),
    .B1(_0606_),
    .Y(_0107_));
 sky130_fd_sc_hd__nand2_1 _2412_ (.A(_0589_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_26_),
    .Y(_0607_));
 sky130_fd_sc_hd__nand2_1 _2413_ (.A(net24),
    .B(axi_lite_i[38]),
    .Y(_0608_));
 sky130_fd_sc_hd__nand2_1 _2414_ (.A(_0607_),
    .B(_0608_),
    .Y(_0108_));
 sky130_fd_sc_hd__nand2_1 _2415_ (.A(net24),
    .B(axi_lite_i[37]),
    .Y(_0609_));
 sky130_fd_sc_hd__o21ai_0 _2416_ (.A1(_0553_),
    .A2(net28),
    .B1(_0609_),
    .Y(_0109_));
 sky130_fd_sc_hd__nand2_1 _2417_ (.A(_0589_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_24_),
    .Y(_0610_));
 sky130_fd_sc_hd__nand2_1 _2418_ (.A(net24),
    .B(axi_lite_i[36]),
    .Y(_0611_));
 sky130_fd_sc_hd__nand2_1 _2419_ (.A(_0610_),
    .B(_0611_),
    .Y(_0110_));
 sky130_fd_sc_hd__nand2_1 _2420_ (.A(net24),
    .B(axi_lite_i[35]),
    .Y(_0612_));
 sky130_fd_sc_hd__o21ai_0 _2421_ (.A1(_0559_),
    .A2(net28),
    .B1(_0612_),
    .Y(_0111_));
 sky130_fd_sc_hd__nand2_1 _2422_ (.A(net24),
    .B(axi_lite_i[34]),
    .Y(_0613_));
 sky130_fd_sc_hd__o21ai_0 _2423_ (.A1(_0562_),
    .A2(net28),
    .B1(_0613_),
    .Y(_0112_));
 sky130_fd_sc_hd__nand2_1 _2424_ (.A(_0589_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_21_),
    .Y(_0614_));
 sky130_fd_sc_hd__nand2_1 _2425_ (.A(net24),
    .B(axi_lite_i[33]),
    .Y(_0615_));
 sky130_fd_sc_hd__nand2_1 _2426_ (.A(_0614_),
    .B(_0615_),
    .Y(_0113_));
 sky130_fd_sc_hd__nand2_1 _2427_ (.A(net24),
    .B(axi_lite_i[32]),
    .Y(_0616_));
 sky130_fd_sc_hd__o21ai_0 _2428_ (.A1(_0568_),
    .A2(net28),
    .B1(_0616_),
    .Y(_0114_));
 sky130_fd_sc_hd__inv_1 _2429_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_11_),
    .Y(_0617_));
 sky130_fd_sc_hd__nand2_1 _2430_ (.A(net24),
    .B(axi_lite_i[23]),
    .Y(_0618_));
 sky130_fd_sc_hd__o21ai_0 _2431_ (.A1(_0617_),
    .A2(net28),
    .B1(_0618_),
    .Y(_0115_));
 sky130_fd_sc_hd__nand2_1 _2432_ (.A(net24),
    .B(axi_lite_i[22]),
    .Y(_0619_));
 sky130_fd_sc_hd__o21ai_0 _2433_ (.A1(_0502_),
    .A2(net28),
    .B1(_0619_),
    .Y(_0116_));
 sky130_fd_sc_hd__nand2_1 _2434_ (.A(net28),
    .B(axi_lite_i[21]),
    .Y(_0620_));
 sky130_fd_sc_hd__o21ai_0 _2435_ (.A1(_0505_),
    .A2(net28),
    .B1(_0620_),
    .Y(_0117_));
 sky130_fd_sc_hd__nand2_1 _2436_ (.A(net28),
    .B(axi_lite_i[20]),
    .Y(_0621_));
 sky130_fd_sc_hd__o21ai_0 _2437_ (.A1(_0508_),
    .A2(net28),
    .B1(_0621_),
    .Y(_0118_));
 sky130_fd_sc_hd__nand2_1 _2438_ (.A(net28),
    .B(axi_lite_i[19]),
    .Y(_0622_));
 sky130_fd_sc_hd__o21ai_0 _2439_ (.A1(_0512_),
    .A2(net28),
    .B1(_0622_),
    .Y(_0119_));
 sky130_fd_sc_hd__nand2_1 _2440_ (.A(net28),
    .B(axi_lite_i[18]),
    .Y(_0623_));
 sky130_fd_sc_hd__o21ai_0 _2441_ (.A1(_0515_),
    .A2(net28),
    .B1(_0623_),
    .Y(_0120_));
 sky130_fd_sc_hd__nand2_1 _2442_ (.A(net28),
    .B(axi_lite_i[17]),
    .Y(_0624_));
 sky130_fd_sc_hd__o21ai_0 _2443_ (.A1(_0518_),
    .A2(net28),
    .B1(_0624_),
    .Y(_0121_));
 sky130_fd_sc_hd__nand2_1 _2444_ (.A(net28),
    .B(axi_lite_i[16]),
    .Y(_0625_));
 sky130_fd_sc_hd__o21ai_0 _2445_ (.A1(_0521_),
    .A2(net28),
    .B1(_0625_),
    .Y(_0122_));
 sky130_fd_sc_hd__nand2_1 _2446_ (.A(_0589_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_39_),
    .Y(_0626_));
 sky130_fd_sc_hd__nand2_1 _2447_ (.A(net24),
    .B(axi_lite_i[55]),
    .Y(_0627_));
 sky130_fd_sc_hd__nand2_1 _2448_ (.A(_0626_),
    .B(_0627_),
    .Y(_0123_));
 sky130_fd_sc_hd__nand2_1 _2449_ (.A(_0589_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_38_),
    .Y(_0628_));
 sky130_fd_sc_hd__nand2_1 _2450_ (.A(net24),
    .B(axi_lite_i[54]),
    .Y(_0629_));
 sky130_fd_sc_hd__nand2_1 _2451_ (.A(_0628_),
    .B(_0629_),
    .Y(_0124_));
 sky130_fd_sc_hd__nand2_1 _2452_ (.A(net28),
    .B(axi_lite_i[53]),
    .Y(_0630_));
 sky130_fd_sc_hd__o21ai_0 _2453_ (.A1(_0447_),
    .A2(net28),
    .B1(_0630_),
    .Y(_0125_));
 sky130_fd_sc_hd__nand2_1 _2454_ (.A(net28),
    .B(axi_lite_i[52]),
    .Y(_0631_));
 sky130_fd_sc_hd__o21ai_0 _2455_ (.A1(_0448_),
    .A2(net28),
    .B1(_0631_),
    .Y(_0126_));
 sky130_fd_sc_hd__nor2_4 _2456_ (.A(_0470_),
    .B(net26),
    .Y(_0632_));
 sky130_fd_sc_hd__nand3_1 _2457_ (.A(_0301_),
    .B(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_status_cnt_q_1_),
    .C(axi_lite_i[0]),
    .Y(_0633_));
 sky130_fd_sc_hd__o21ai_0 _2458_ (.A1(_0301_),
    .A2(axi_lite_i[0]),
    .B1(_0633_),
    .Y(_0634_));
 sky130_fd_sc_hd__inv_1 _2459_ (.A(axi_lite_i[0]),
    .Y(_0635_));
 sky130_fd_sc_hd__nand3_1 _2460_ (.A(_0632_),
    .B(net87),
    .C(_0635_),
    .Y(_0636_));
 sky130_fd_sc_hd__o21a_1 _2461_ (.A1(_0632_),
    .A2(_0634_),
    .B1(_0636_),
    .X(_0127_));
 sky130_fd_sc_hd__inv_8 _2462_ (.A(_0472_),
    .Y(_0637_));
 sky130_fd_sc_hd__a21oi_1 _2463_ (.A1(_0491_),
    .A2(reg2hw_55_),
    .B1(_0637_),
    .Y(_0638_));
 sky130_fd_sc_hd__lpflow_clkinvkapwr_1 _2464_ (.A(net86),
    .Y(_0639_));
 sky130_fd_sc_hd__inv_4 _2465_ (.A(_0632_),
    .Y(_0640_));
 sky130_fd_sc_hd__nor2_1 _2466_ (.A(net45),
    .B(_0640_),
    .Y(_0641_));
 sky130_fd_sc_hd__buf_2 _2467_ (.A(net18),
    .X(_0642_));
 sky130_fd_sc_hd__nor2_1 _2468_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_64_),
    .B(net17),
    .Y(_0643_));
 sky130_fd_sc_hd__a21oi_1 _2469_ (.A1(_0638_),
    .A2(net17),
    .B1(_0643_),
    .Y(_0128_));
 sky130_fd_sc_hd__a21oi_1 _2470_ (.A1(_0491_),
    .A2(reg2hw_54_),
    .B1(_0637_),
    .Y(_0644_));
 sky130_fd_sc_hd__nor2_1 _2471_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_63_),
    .B(net17),
    .Y(_0645_));
 sky130_fd_sc_hd__a21oi_1 _2472_ (.A1(_0644_),
    .A2(net17),
    .B1(_0645_),
    .Y(_0129_));
 sky130_fd_sc_hd__a21oi_1 _2473_ (.A1(_0491_),
    .A2(net78),
    .B1(_0637_),
    .Y(_0646_));
 sky130_fd_sc_hd__nor2_1 _2474_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_62_),
    .B(net17),
    .Y(_0647_));
 sky130_fd_sc_hd__a21oi_1 _2475_ (.A1(_0646_),
    .A2(net17),
    .B1(_0647_),
    .Y(_0130_));
 sky130_fd_sc_hd__a21oi_1 _2476_ (.A1(_0491_),
    .A2(reg2hw_52_),
    .B1(_0637_),
    .Y(_0648_));
 sky130_fd_sc_hd__nor2_1 _2477_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_61_),
    .B(net17),
    .Y(_0649_));
 sky130_fd_sc_hd__a21oi_1 _2478_ (.A1(_0648_),
    .A2(net17),
    .B1(_0649_),
    .Y(_0131_));
 sky130_fd_sc_hd__a21oi_1 _2479_ (.A1(_0491_),
    .A2(net79),
    .B1(_0637_),
    .Y(_0650_));
 sky130_fd_sc_hd__nor2_1 _2480_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_60_),
    .B(net17),
    .Y(_0651_));
 sky130_fd_sc_hd__a21oi_1 _2481_ (.A1(_0650_),
    .A2(net17),
    .B1(_0651_),
    .Y(_0132_));
 sky130_fd_sc_hd__a21oi_1 _2482_ (.A1(_0491_),
    .A2(reg2hw_50_),
    .B1(_0637_),
    .Y(_0652_));
 sky130_fd_sc_hd__nor2_1 _2483_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_59_),
    .B(net17),
    .Y(_0653_));
 sky130_fd_sc_hd__a21oi_1 _2484_ (.A1(_0652_),
    .A2(net17),
    .B1(_0653_),
    .Y(_0133_));
 sky130_fd_sc_hd__a21oi_1 _2485_ (.A1(_0491_),
    .A2(reg2hw_49_),
    .B1(_0637_),
    .Y(_0654_));
 sky130_fd_sc_hd__nor2_1 _2486_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_58_),
    .B(net17),
    .Y(_0655_));
 sky130_fd_sc_hd__a21oi_1 _2487_ (.A1(_0654_),
    .A2(net17),
    .B1(_0655_),
    .Y(_0134_));
 sky130_fd_sc_hd__a21oi_1 _2488_ (.A1(_0491_),
    .A2(reg2hw_48_),
    .B1(_0637_),
    .Y(_0656_));
 sky130_fd_sc_hd__nor2_1 _2489_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_57_),
    .B(net18),
    .Y(_0657_));
 sky130_fd_sc_hd__a21oi_1 _2490_ (.A1(_0656_),
    .A2(net17),
    .B1(_0657_),
    .Y(_0135_));
 sky130_fd_sc_hd__a21oi_1 _2491_ (.A1(_0491_),
    .A2(net80),
    .B1(_0637_),
    .Y(_0658_));
 sky130_fd_sc_hd__nor2_1 _2492_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_56_),
    .B(net18),
    .Y(_0659_));
 sky130_fd_sc_hd__a21oi_1 _2493_ (.A1(_0658_),
    .A2(net17),
    .B1(_0659_),
    .Y(_0136_));
 sky130_fd_sc_hd__a21oi_1 _2494_ (.A1(_0491_),
    .A2(reg2hw_46_),
    .B1(_0637_),
    .Y(_0660_));
 sky130_fd_sc_hd__nor2_1 _2495_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_55_),
    .B(net18),
    .Y(_0661_));
 sky130_fd_sc_hd__a21oi_1 _2496_ (.A1(_0660_),
    .A2(net17),
    .B1(_0661_),
    .Y(_0137_));
 sky130_fd_sc_hd__nor2_1 _2497_ (.A(_0384_),
    .B(_0395_),
    .Y(_0662_));
 sky130_fd_sc_hd__nand2_1 _2498_ (.A(_0392_),
    .B(_0394_),
    .Y(_0663_));
 sky130_fd_sc_hd__inv_8 _2499_ (.A(net115),
    .Y(_0664_));
 sky130_fd_sc_hd__inv_1 _2500_ (.A(_0383_),
    .Y(_0665_));
 sky130_fd_sc_hd__a21oi_1 _2501_ (.A1(net116),
    .A2(_0403_),
    .B1(_0665_),
    .Y(_0666_));
 sky130_fd_sc_hd__a21oi_1 _2502_ (.A1(net111),
    .A2(_0664_),
    .B1(_0666_),
    .Y(_0667_));
 sky130_fd_sc_hd__o21ai_0 _2503_ (.A1(_0663_),
    .A2(_0667_),
    .B1(_0392_),
    .Y(_0668_));
 sky130_fd_sc_hd__inv_1 _2504_ (.A(_0668_),
    .Y(_0669_));
 sky130_fd_sc_hd__nor2_1 _2505_ (.A(_0389_),
    .B(_0669_),
    .Y(_0670_));
 sky130_fd_sc_hd__nor4_1 _2506_ (.A(_0387_),
    .B(_0662_),
    .C(_0385_),
    .D(_0670_),
    .Y(_0671_));
 sky130_fd_sc_hd__o21a_1 _2507_ (.A1(_0387_),
    .A2(_0670_),
    .B1(_0385_),
    .X(_0672_));
 sky130_fd_sc_hd__o31ai_1 _2508_ (.A1(_0671_),
    .A2(_0672_),
    .A3(_0488_),
    .B1(_0472_),
    .Y(_0673_));
 sky130_fd_sc_hd__a21oi_1 _2509_ (.A1(net81),
    .A2(_0491_),
    .B1(_0673_),
    .Y(_0674_));
 sky130_fd_sc_hd__nor2_1 _2510_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_54_),
    .B(net18),
    .Y(_0675_));
 sky130_fd_sc_hd__a21oi_1 _2511_ (.A1(_0674_),
    .A2(net17),
    .B1(_0675_),
    .Y(_0138_));
 sky130_fd_sc_hd__nor2_1 _2512_ (.A(_0396_),
    .B(_0488_),
    .Y(_0676_));
 sky130_fd_sc_hd__xor2_1 _2513_ (.A(_0390_),
    .B(_0668_),
    .X(_0677_));
 sky130_fd_sc_hd__a221oi_1 _2514_ (.A1(reg2hw_44_),
    .A2(_0491_),
    .B1(_0676_),
    .B2(_0677_),
    .C1(_0637_),
    .Y(_0678_));
 sky130_fd_sc_hd__nor2_1 _2515_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_53_),
    .B(net18),
    .Y(_0679_));
 sky130_fd_sc_hd__a21oi_1 _2516_ (.A1(_0678_),
    .A2(net17),
    .B1(_0679_),
    .Y(_0139_));
 sky130_fd_sc_hd__xor2_1 _2517_ (.A(_0663_),
    .B(_0667_),
    .X(_0680_));
 sky130_fd_sc_hd__a221oi_1 _2518_ (.A1(reg2hw_43_),
    .A2(_0491_),
    .B1(_0676_),
    .B2(_0680_),
    .C1(_0637_),
    .Y(_0681_));
 sky130_fd_sc_hd__nor2_1 _2519_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_52_),
    .B(net18),
    .Y(_0682_));
 sky130_fd_sc_hd__a21oi_1 _2520_ (.A1(_0681_),
    .A2(net17),
    .B1(_0682_),
    .Y(_0140_));
 sky130_fd_sc_hd__nor3_1 _2521_ (.A(_0396_),
    .B(_0666_),
    .C(_0488_),
    .Y(_0683_));
 sky130_fd_sc_hd__nand3_1 _2522_ (.A(_0665_),
    .B(net116),
    .C(_0403_),
    .Y(_0684_));
 sky130_fd_sc_hd__a221oi_1 _2523_ (.A1(reg2hw_42_),
    .A2(_0491_),
    .B1(_0683_),
    .B2(_0684_),
    .C1(_0637_),
    .Y(_0685_));
 sky130_fd_sc_hd__nor2_1 _2524_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_51_),
    .B(net18),
    .Y(_0686_));
 sky130_fd_sc_hd__a21oi_1 _2525_ (.A1(_0685_),
    .A2(net17),
    .B1(_0686_),
    .Y(_0141_));
 sky130_fd_sc_hd__o21ai_0 _2526_ (.A1(_0382_),
    .A2(_0488_),
    .B1(_0472_),
    .Y(_0687_));
 sky130_fd_sc_hd__a21oi_1 _2527_ (.A1(net82),
    .A2(_0491_),
    .B1(_0687_),
    .Y(_0688_));
 sky130_fd_sc_hd__nor2_1 _2528_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_50_),
    .B(net18),
    .Y(_0689_));
 sky130_fd_sc_hd__a21oi_1 _2529_ (.A1(_0688_),
    .A2(net17),
    .B1(_0689_),
    .Y(_0142_));
 sky130_fd_sc_hd__nand2_4 _2530_ (.A(_0637_),
    .B(net18),
    .Y(_0690_));
 sky130_fd_sc_hd__o21ai_0 _2531_ (.A1(net45),
    .A2(_0640_),
    .B1(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_49_),
    .Y(_0691_));
 sky130_fd_sc_hd__nand2_1 _2532_ (.A(_0690_),
    .B(_0691_),
    .Y(_0143_));
 sky130_fd_sc_hd__o21ai_0 _2533_ (.A1(net45),
    .A2(_0640_),
    .B1(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_48_),
    .Y(_0692_));
 sky130_fd_sc_hd__nand2_1 _2534_ (.A(_0690_),
    .B(_0692_),
    .Y(_0144_));
 sky130_fd_sc_hd__o21ai_0 _2535_ (.A1(net45),
    .A2(_0640_),
    .B1(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_47_),
    .Y(_0693_));
 sky130_fd_sc_hd__nand2_1 _2536_ (.A(_0690_),
    .B(_0693_),
    .Y(_0145_));
 sky130_fd_sc_hd__o21ai_0 _2537_ (.A1(net45),
    .A2(_0640_),
    .B1(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_46_),
    .Y(_0694_));
 sky130_fd_sc_hd__nand2_1 _2538_ (.A(_0690_),
    .B(_0694_),
    .Y(_0146_));
 sky130_fd_sc_hd__o21ai_0 _2539_ (.A1(net45),
    .A2(_0640_),
    .B1(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_45_),
    .Y(_0695_));
 sky130_fd_sc_hd__nand2_1 _2540_ (.A(_0690_),
    .B(_0695_),
    .Y(_0147_));
 sky130_fd_sc_hd__o21ai_0 _2541_ (.A1(net45),
    .A2(_0640_),
    .B1(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_44_),
    .Y(_0696_));
 sky130_fd_sc_hd__nand2_1 _2542_ (.A(_0690_),
    .B(_0696_),
    .Y(_0148_));
 sky130_fd_sc_hd__o21ai_0 _2543_ (.A1(net45),
    .A2(_0640_),
    .B1(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_43_),
    .Y(_0697_));
 sky130_fd_sc_hd__nand2_1 _2544_ (.A(_0690_),
    .B(_0697_),
    .Y(_0149_));
 sky130_fd_sc_hd__o21ai_0 _2545_ (.A1(net45),
    .A2(_0640_),
    .B1(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_42_),
    .Y(_0698_));
 sky130_fd_sc_hd__nand2_1 _2546_ (.A(_0690_),
    .B(_0698_),
    .Y(_0150_));
 sky130_fd_sc_hd__nor2_1 _2547_ (.A(_0461_),
    .B(_0454_),
    .Y(_0699_));
 sky130_fd_sc_hd__nand2_1 _2548_ (.A(_0699_),
    .B(net19),
    .Y(_0700_));
 sky130_fd_sc_hd__a21oi_2 _2549_ (.A1(_0662_),
    .A2(_0385_),
    .B1(_0700_),
    .Y(_0701_));
 sky130_fd_sc_hd__nor2_1 _2550_ (.A(net116),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_39_),
    .Y(_0702_));
 sky130_fd_sc_hd__inv_1 _2551_ (.A(net116),
    .Y(_0703_));
 sky130_fd_sc_hd__lpflow_clkbufkapwr_1 _2552_ (.A(_0703_),
    .X(_0704_));
 sky130_fd_sc_hd__o21ai_0 _2553_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_47_),
    .A2(net32),
    .B1(_0664_),
    .Y(_0705_));
 sky130_fd_sc_hd__nor2_1 _2554_ (.A(net116),
    .B(_0664_),
    .Y(_0706_));
 sky130_fd_sc_hd__nor2_1 _2555_ (.A(_0703_),
    .B(_0664_),
    .Y(_0707_));
 sky130_fd_sc_hd__a221oi_1 _2556_ (.A1(net31),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_55_),
    .B1(net30),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_63_),
    .C1(_0391_),
    .Y(_0708_));
 sky130_fd_sc_hd__o21ai_0 _2557_ (.A1(_0702_),
    .A2(_0705_),
    .B1(_0708_),
    .Y(_0709_));
 sky130_fd_sc_hd__nor2_1 _2558_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_15_),
    .B(net32),
    .Y(_0710_));
 sky130_fd_sc_hd__o21ai_0 _2559_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_7_),
    .B1(_0664_),
    .Y(_0711_));
 sky130_fd_sc_hd__a22oi_1 _2560_ (.A1(net31),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_23_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_31_),
    .B2(net30),
    .Y(_0712_));
 sky130_fd_sc_hd__o211ai_1 _2561_ (.A1(_0710_),
    .A2(_0711_),
    .B1(_0391_),
    .C1(_0712_),
    .Y(_0713_));
 sky130_fd_sc_hd__nand2_1 _2562_ (.A(_0709_),
    .B(_0713_),
    .Y(_0714_));
 sky130_fd_sc_hd__nor2_1 _2563_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_79_),
    .B(net32),
    .Y(_0715_));
 sky130_fd_sc_hd__nor2_1 _2564_ (.A(net115),
    .B(_0715_),
    .Y(_0716_));
 sky130_fd_sc_hd__o21ai_0 _2565_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_71_),
    .B1(_0716_),
    .Y(_0717_));
 sky130_fd_sc_hd__nand2_1 _2566_ (.A(net31),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_87_),
    .Y(_0718_));
 sky130_fd_sc_hd__nand2_1 _2567_ (.A(net30),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_95_),
    .Y(_0719_));
 sky130_fd_sc_hd__nand4_1 _2568_ (.A(_0717_),
    .B(_0391_),
    .C(_0718_),
    .D(_0719_),
    .Y(_0720_));
 sky130_fd_sc_hd__nor2_1 _2569_ (.A(net116),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_103_),
    .Y(_0721_));
 sky130_fd_sc_hd__nor2_1 _2570_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_111_),
    .B(net32),
    .Y(_0722_));
 sky130_fd_sc_hd__nand2_1 _2571_ (.A(net30),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_127_),
    .Y(_0723_));
 sky130_fd_sc_hd__a21oi_1 _2572_ (.A1(net31),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_119_),
    .B1(_0391_),
    .Y(_0724_));
 sky130_fd_sc_hd__o311ai_0 _2573_ (.A1(net115),
    .A2(_0721_),
    .A3(_0722_),
    .B1(_0723_),
    .C1(_0724_),
    .Y(_0725_));
 sky130_fd_sc_hd__a21oi_1 _2574_ (.A1(_0720_),
    .A2(_0725_),
    .B1(_0388_),
    .Y(_0726_));
 sky130_fd_sc_hd__a21oi_1 _2575_ (.A1(_0714_),
    .A2(_0388_),
    .B1(_0726_),
    .Y(_0727_));
 sky130_fd_sc_hd__a221oi_1 _2576_ (.A1(net75),
    .A2(_0491_),
    .B1(_0701_),
    .B2(_0727_),
    .C1(_0637_),
    .Y(_0728_));
 sky130_fd_sc_hd__nor2_1 _2577_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_41_),
    .B(net18),
    .Y(_0729_));
 sky130_fd_sc_hd__a21oi_1 _2578_ (.A1(_0728_),
    .A2(net17),
    .B1(_0729_),
    .Y(_0151_));
 sky130_fd_sc_hd__nor2_1 _2579_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_14_),
    .B(net32),
    .Y(_0730_));
 sky130_fd_sc_hd__o21ai_0 _2580_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_6_),
    .B1(_0664_),
    .Y(_0731_));
 sky130_fd_sc_hd__a22oi_1 _2581_ (.A1(net31),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_22_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_30_),
    .B2(net30),
    .Y(_0732_));
 sky130_fd_sc_hd__o211ai_1 _2582_ (.A1(_0730_),
    .A2(_0731_),
    .B1(_0391_),
    .C1(_0732_),
    .Y(_0733_));
 sky130_fd_sc_hd__nor2_1 _2583_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_46_),
    .B(net32),
    .Y(_0734_));
 sky130_fd_sc_hd__o21ai_0 _2584_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_38_),
    .B1(_0664_),
    .Y(_0735_));
 sky130_fd_sc_hd__nand2_1 _2585_ (.A(net31),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_54_),
    .Y(_0736_));
 sky130_fd_sc_hd__nand2_1 _2586_ (.A(net30),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_62_),
    .Y(_0737_));
 sky130_fd_sc_hd__o2111ai_1 _2587_ (.A1(_0734_),
    .A2(_0735_),
    .B1(net114),
    .C1(_0736_),
    .D1(_0737_),
    .Y(_0738_));
 sky130_fd_sc_hd__nand3_1 _2588_ (.A(_0733_),
    .B(_0388_),
    .C(_0738_),
    .Y(_0739_));
 sky130_fd_sc_hd__nor2_1 _2589_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_110_),
    .B(net32),
    .Y(_0740_));
 sky130_fd_sc_hd__o21ai_0 _2590_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_102_),
    .B1(_0664_),
    .Y(_0741_));
 sky130_fd_sc_hd__nand2_1 _2591_ (.A(net31),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_118_),
    .Y(_0742_));
 sky130_fd_sc_hd__nand2_1 _2592_ (.A(net30),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_126_),
    .Y(_0743_));
 sky130_fd_sc_hd__o2111ai_1 _2593_ (.A1(_0740_),
    .A2(_0741_),
    .B1(net114),
    .C1(_0742_),
    .D1(_0743_),
    .Y(_0744_));
 sky130_fd_sc_hd__nor2_1 _2594_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_78_),
    .B(net32),
    .Y(_0745_));
 sky130_fd_sc_hd__o21ai_0 _2595_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_70_),
    .B1(_0664_),
    .Y(_0746_));
 sky130_fd_sc_hd__nand2_1 _2596_ (.A(net31),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_86_),
    .Y(_0747_));
 sky130_fd_sc_hd__nand2_1 _2597_ (.A(net30),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_94_),
    .Y(_0748_));
 sky130_fd_sc_hd__o2111ai_1 _2598_ (.A1(_0745_),
    .A2(_0746_),
    .B1(_0391_),
    .C1(_0747_),
    .D1(_0748_),
    .Y(_0749_));
 sky130_fd_sc_hd__nand3_1 _2599_ (.A(_0744_),
    .B(_0749_),
    .C(net113),
    .Y(_0750_));
 sky130_fd_sc_hd__nand2_1 _2600_ (.A(_0739_),
    .B(_0750_),
    .Y(_0751_));
 sky130_fd_sc_hd__a221oi_1 _2601_ (.A1(net76),
    .A2(_0491_),
    .B1(_0701_),
    .B2(_0751_),
    .C1(_0637_),
    .Y(_0752_));
 sky130_fd_sc_hd__nor2_1 _2602_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_40_),
    .B(net18),
    .Y(_0753_));
 sky130_fd_sc_hd__a21oi_1 _2603_ (.A1(_0752_),
    .A2(net17),
    .B1(_0753_),
    .Y(_0152_));
 sky130_fd_sc_hd__nor2_1 _2604_ (.A(net116),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_101_),
    .Y(_0754_));
 sky130_fd_sc_hd__nor2_1 _2605_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_109_),
    .B(net32),
    .Y(_0755_));
 sky130_fd_sc_hd__nor3_1 _2606_ (.A(net115),
    .B(_0754_),
    .C(_0755_),
    .Y(_0756_));
 sky130_fd_sc_hd__a221o_1 _2607_ (.A1(net31),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_117_),
    .B1(net30),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_125_),
    .C1(_0391_),
    .X(_0757_));
 sky130_fd_sc_hd__nor2_1 _2608_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_77_),
    .B(net32),
    .Y(_0758_));
 sky130_fd_sc_hd__o21ai_0 _2609_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_69_),
    .B1(_0664_),
    .Y(_0759_));
 sky130_fd_sc_hd__nand2_1 _2610_ (.A(net31),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_85_),
    .Y(_0760_));
 sky130_fd_sc_hd__nand2_1 _2611_ (.A(net30),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_93_),
    .Y(_0761_));
 sky130_fd_sc_hd__o2111ai_1 _2612_ (.A1(_0758_),
    .A2(_0759_),
    .B1(_0391_),
    .C1(_0760_),
    .D1(_0761_),
    .Y(_0762_));
 sky130_fd_sc_hd__o21ai_0 _2613_ (.A1(_0756_),
    .A2(_0757_),
    .B1(_0762_),
    .Y(_0763_));
 sky130_fd_sc_hd__nor2_1 _2614_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_13_),
    .B(net32),
    .Y(_0764_));
 sky130_fd_sc_hd__o21ai_0 _2615_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_5_),
    .B1(_0664_),
    .Y(_0765_));
 sky130_fd_sc_hd__nand2_1 _2616_ (.A(net31),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_21_),
    .Y(_0766_));
 sky130_fd_sc_hd__nand2_1 _2617_ (.A(net30),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_29_),
    .Y(_0767_));
 sky130_fd_sc_hd__o2111ai_1 _2618_ (.A1(_0764_),
    .A2(_0765_),
    .B1(_0391_),
    .C1(_0766_),
    .D1(_0767_),
    .Y(_0768_));
 sky130_fd_sc_hd__nor2_1 _2619_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_45_),
    .B(net32),
    .Y(_0769_));
 sky130_fd_sc_hd__o21ai_0 _2620_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_37_),
    .B1(_0664_),
    .Y(_0770_));
 sky130_fd_sc_hd__nand2_1 _2621_ (.A(net31),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_53_),
    .Y(_0771_));
 sky130_fd_sc_hd__nand2_1 _2622_ (.A(net30),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_61_),
    .Y(_0772_));
 sky130_fd_sc_hd__o2111ai_1 _2623_ (.A1(_0769_),
    .A2(_0770_),
    .B1(net114),
    .C1(_0771_),
    .D1(_0772_),
    .Y(_0773_));
 sky130_fd_sc_hd__a21oi_1 _2624_ (.A1(_0768_),
    .A2(_0773_),
    .B1(net113),
    .Y(_0774_));
 sky130_fd_sc_hd__a21oi_1 _2625_ (.A1(_0763_),
    .A2(net113),
    .B1(_0774_),
    .Y(_0775_));
 sky130_fd_sc_hd__inv_1 _2626_ (.A(reg2hw_38_),
    .Y(_0776_));
 sky130_fd_sc_hd__nor2_1 _2627_ (.A(_0776_),
    .B(_0492_),
    .Y(_0777_));
 sky130_fd_sc_hd__inv_1 _2628_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_under_rst),
    .Y(_0778_));
 sky130_fd_sc_hd__nand2_1 _2629_ (.A(_0662_),
    .B(_0385_),
    .Y(_0779_));
 sky130_fd_sc_hd__a21oi_1 _2630_ (.A1(_0778_),
    .A2(_0779_),
    .B1(_0479_),
    .Y(_0780_));
 sky130_fd_sc_hd__a2111oi_0 _2631_ (.A1(_0701_),
    .A2(_0775_),
    .B1(_0637_),
    .C1(_0777_),
    .D1(_0780_),
    .Y(_0781_));
 sky130_fd_sc_hd__nor2_1 _2632_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_39_),
    .B(net18),
    .Y(_0782_));
 sky130_fd_sc_hd__a21oi_1 _2633_ (.A1(_0781_),
    .A2(net17),
    .B1(_0782_),
    .Y(_0153_));
 sky130_fd_sc_hd__o21ai_0 _2634_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_4_),
    .B1(_0664_),
    .Y(_0783_));
 sky130_fd_sc_hd__nor2_1 _2635_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_12_),
    .B(net32),
    .Y(_0784_));
 sky130_fd_sc_hd__nor2_1 _2636_ (.A(_0783_),
    .B(_0784_),
    .Y(_0785_));
 sky130_fd_sc_hd__nand2_1 _2637_ (.A(net30),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_28_),
    .Y(_0786_));
 sky130_fd_sc_hd__nand2_1 _2638_ (.A(_0786_),
    .B(_0391_),
    .Y(_0787_));
 sky130_fd_sc_hd__inv_1 _2639_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_20_),
    .Y(_0788_));
 sky130_fd_sc_hd__inv_1 _2640_ (.A(net31),
    .Y(_0789_));
 sky130_fd_sc_hd__nor2_1 _2641_ (.A(_0788_),
    .B(_0789_),
    .Y(_0790_));
 sky130_fd_sc_hd__o21ai_0 _2642_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_36_),
    .B1(_0664_),
    .Y(_0791_));
 sky130_fd_sc_hd__nor2_1 _2643_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_44_),
    .B(net32),
    .Y(_0792_));
 sky130_fd_sc_hd__nor2_1 _2644_ (.A(_0791_),
    .B(_0792_),
    .Y(_0793_));
 sky130_fd_sc_hd__a22oi_1 _2645_ (.A1(net31),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_52_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_60_),
    .B2(net30),
    .Y(_0794_));
 sky130_fd_sc_hd__nand2_1 _2646_ (.A(_0794_),
    .B(net114),
    .Y(_0795_));
 sky130_fd_sc_hd__o32ai_1 _2647_ (.A1(_0785_),
    .A2(_0787_),
    .A3(_0790_),
    .B1(_0793_),
    .B2(_0795_),
    .Y(_0796_));
 sky130_fd_sc_hd__nand2_1 _2648_ (.A(_0796_),
    .B(_0388_),
    .Y(_0797_));
 sky130_fd_sc_hd__o21ai_0 _2649_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_68_),
    .B1(_0664_),
    .Y(_0798_));
 sky130_fd_sc_hd__nor2_1 _2650_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_76_),
    .B(net32),
    .Y(_0799_));
 sky130_fd_sc_hd__nor2_1 _2651_ (.A(_0798_),
    .B(_0799_),
    .Y(_0800_));
 sky130_fd_sc_hd__a221oi_1 _2652_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_84_),
    .A2(net31),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_92_),
    .B2(net30),
    .C1(_0800_),
    .Y(_0801_));
 sky130_fd_sc_hd__inv_1 _2653_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_116_),
    .Y(_0802_));
 sky130_fd_sc_hd__nor2_1 _2654_ (.A(_0802_),
    .B(_0789_),
    .Y(_0803_));
 sky130_fd_sc_hd__nor2_1 _2655_ (.A(net116),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_100_),
    .Y(_0804_));
 sky130_fd_sc_hd__o21ai_0 _2656_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_108_),
    .A2(net32),
    .B1(_0664_),
    .Y(_0805_));
 sky130_fd_sc_hd__nand2_1 _2657_ (.A(net30),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_124_),
    .Y(_0806_));
 sky130_fd_sc_hd__o21ai_0 _2658_ (.A1(_0804_),
    .A2(_0805_),
    .B1(_0806_),
    .Y(_0807_));
 sky130_fd_sc_hd__o21ai_0 _2659_ (.A1(_0803_),
    .A2(_0807_),
    .B1(net114),
    .Y(_0808_));
 sky130_fd_sc_hd__o211ai_1 _2660_ (.A1(net114),
    .A2(_0801_),
    .B1(net113),
    .C1(_0808_),
    .Y(_0809_));
 sky130_fd_sc_hd__inv_2 _2661_ (.A(reg2hw_37_),
    .Y(_0810_));
 sky130_fd_sc_hd__clkinv_1 _2662_ (.A(hw2reg_28_),
    .Y(_0811_));
 sky130_fd_sc_hd__o22ai_1 _2663_ (.A1(_0810_),
    .A2(_0492_),
    .B1(_0811_),
    .B2(_0479_),
    .Y(_0812_));
 sky130_fd_sc_hd__a311oi_1 _2664_ (.A1(_0701_),
    .A2(_0797_),
    .A3(_0809_),
    .B1(_0637_),
    .C1(_0812_),
    .Y(_0813_));
 sky130_fd_sc_hd__nor2_1 _2665_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_38_),
    .B(net18),
    .Y(_0814_));
 sky130_fd_sc_hd__a21oi_1 _2666_ (.A1(_0813_),
    .A2(net17),
    .B1(_0814_),
    .Y(_0154_));
 sky130_fd_sc_hd__nand3_1 _2667_ (.A(_1361_),
    .B(_1369_),
    .C(_1365_),
    .Y(_0815_));
 sky130_fd_sc_hd__nor2_1 _2668_ (.A(_1357_),
    .B(_0815_),
    .Y(_0816_));
 sky130_fd_sc_hd__nor2_1 _2669_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_under_rst),
    .B(_0816_),
    .Y(_0817_));
 sky130_fd_sc_hd__nor2_1 _2670_ (.A(_0817_),
    .B(_0479_),
    .Y(_0818_));
 sky130_fd_sc_hd__nor2_1 _2671_ (.A(u_uart_core_uart_tx_bit_cnt_q_1_),
    .B(u_uart_core_uart_tx_bit_cnt_q_0_),
    .Y(_0819_));
 sky130_fd_sc_hd__inv_1 _2672_ (.A(u_uart_core_uart_tx_bit_cnt_q_2_),
    .Y(_0820_));
 sky130_fd_sc_hd__nand2_1 _2673_ (.A(_0819_),
    .B(_0820_),
    .Y(_0821_));
 sky130_fd_sc_hd__nor2_1 _2674_ (.A(u_uart_core_uart_tx_bit_cnt_q_3_),
    .B(_0821_),
    .Y(_0822_));
 sky130_fd_sc_hd__inv_1 _2675_ (.A(_0822_),
    .Y(_0823_));
 sky130_fd_sc_hd__nand2_1 _2676_ (.A(_0823_),
    .B(net74),
    .Y(_0824_));
 sky130_fd_sc_hd__a22oi_1 _2677_ (.A1(net31),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_51_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_59_),
    .B2(net30),
    .Y(_0825_));
 sky130_fd_sc_hd__nor2_1 _2678_ (.A(net116),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_35_),
    .Y(_0826_));
 sky130_fd_sc_hd__nor2_1 _2679_ (.A(net115),
    .B(_0826_),
    .Y(_0827_));
 sky130_fd_sc_hd__o21ai_0 _2680_ (.A1(net32),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_43_),
    .B1(_0827_),
    .Y(_0828_));
 sky130_fd_sc_hd__a21oi_1 _2681_ (.A1(_0825_),
    .A2(_0828_),
    .B1(_0391_),
    .Y(_0829_));
 sky130_fd_sc_hd__o21ai_0 _2682_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_3_),
    .B1(_0664_),
    .Y(_0830_));
 sky130_fd_sc_hd__nor2_1 _2683_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_11_),
    .B(net32),
    .Y(_0831_));
 sky130_fd_sc_hd__nor2_1 _2684_ (.A(_0830_),
    .B(_0831_),
    .Y(_0832_));
 sky130_fd_sc_hd__a221oi_1 _2685_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_19_),
    .A2(net31),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_27_),
    .B2(net30),
    .C1(_0832_),
    .Y(_0833_));
 sky130_fd_sc_hd__o21ai_0 _2686_ (.A1(net114),
    .A2(_0833_),
    .B1(_0388_),
    .Y(_0834_));
 sky130_fd_sc_hd__o21ai_0 _2687_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_99_),
    .B1(_0664_),
    .Y(_0835_));
 sky130_fd_sc_hd__nor2_1 _2688_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_107_),
    .B(net32),
    .Y(_0836_));
 sky130_fd_sc_hd__nor2_1 _2689_ (.A(_0835_),
    .B(_0836_),
    .Y(_0837_));
 sky130_fd_sc_hd__a221oi_1 _2690_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_115_),
    .A2(net31),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_123_),
    .B2(net30),
    .C1(_0837_),
    .Y(_0838_));
 sky130_fd_sc_hd__inv_1 _2691_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_83_),
    .Y(_0839_));
 sky130_fd_sc_hd__nor2_1 _2692_ (.A(_0839_),
    .B(_0789_),
    .Y(_0840_));
 sky130_fd_sc_hd__nor2_1 _2693_ (.A(net116),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_67_),
    .Y(_0841_));
 sky130_fd_sc_hd__o21ai_0 _2694_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_75_),
    .A2(net32),
    .B1(_0664_),
    .Y(_0842_));
 sky130_fd_sc_hd__nand2_1 _2695_ (.A(net30),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_91_),
    .Y(_0843_));
 sky130_fd_sc_hd__o21ai_0 _2696_ (.A1(_0841_),
    .A2(_0842_),
    .B1(_0843_),
    .Y(_0844_));
 sky130_fd_sc_hd__o21ai_0 _2697_ (.A1(_0840_),
    .A2(_0844_),
    .B1(_0391_),
    .Y(_0845_));
 sky130_fd_sc_hd__o211ai_1 _2698_ (.A1(_0391_),
    .A2(_0838_),
    .B1(net113),
    .C1(_0845_),
    .Y(_0846_));
 sky130_fd_sc_hd__o211ai_1 _2699_ (.A1(_0829_),
    .A2(_0834_),
    .B1(_0846_),
    .C1(_0701_),
    .Y(_0847_));
 sky130_fd_sc_hd__nand2_1 _2700_ (.A(_0847_),
    .B(_0472_),
    .Y(_0848_));
 sky130_fd_sc_hd__inv_1 _2701_ (.A(_1361_),
    .Y(_0849_));
 sky130_fd_sc_hd__nor2_1 _2702_ (.A(_1363_),
    .B(_0849_),
    .Y(_0850_));
 sky130_fd_sc_hd__nor2_1 _2703_ (.A(_1358_),
    .B(_0850_),
    .Y(_0851_));
 sky130_fd_sc_hd__nor2_1 _2704_ (.A(_1367_),
    .B(_0851_),
    .Y(_0852_));
 sky130_fd_sc_hd__nor2_1 _2705_ (.A(_1368_),
    .B(_0852_),
    .Y(_0853_));
 sky130_fd_sc_hd__o21ai_0 _2706_ (.A1(_1357_),
    .A2(_0853_),
    .B1(_0487_),
    .Y(_0854_));
 sky130_fd_sc_hd__a21oi_1 _2707_ (.A1(_1357_),
    .A2(_0853_),
    .B1(_0854_),
    .Y(_0855_));
 sky130_fd_sc_hd__a211oi_1 _2708_ (.A1(_0818_),
    .A2(_0824_),
    .B1(_0848_),
    .C1(_0855_),
    .Y(_0856_));
 sky130_fd_sc_hd__nor2_1 _2709_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_37_),
    .B(net18),
    .Y(_0857_));
 sky130_fd_sc_hd__a21oi_1 _2710_ (.A1(_0856_),
    .A2(net17),
    .B1(_0857_),
    .Y(_0155_));
 sky130_fd_sc_hd__nor2_1 _2711_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_106_),
    .B(net32),
    .Y(_0858_));
 sky130_fd_sc_hd__o21ai_0 _2712_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_98_),
    .B1(_0664_),
    .Y(_0859_));
 sky130_fd_sc_hd__nand2_1 _2713_ (.A(net31),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_114_),
    .Y(_0860_));
 sky130_fd_sc_hd__o211ai_1 _2714_ (.A1(_0858_),
    .A2(_0859_),
    .B1(net114),
    .C1(_0860_),
    .Y(_0861_));
 sky130_fd_sc_hd__a21oi_1 _2715_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_122_),
    .A2(net30),
    .B1(_0861_),
    .Y(_0862_));
 sky130_fd_sc_hd__nor2_1 _2716_ (.A(net116),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_66_),
    .Y(_0863_));
 sky130_fd_sc_hd__o21ai_0 _2717_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_74_),
    .A2(net32),
    .B1(_0664_),
    .Y(_0864_));
 sky130_fd_sc_hd__a22oi_1 _2718_ (.A1(net31),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_82_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_90_),
    .B2(net30),
    .Y(_0865_));
 sky130_fd_sc_hd__o211a_1 _2719_ (.A1(_0863_),
    .A2(_0864_),
    .B1(_0391_),
    .C1(_0865_),
    .X(_0866_));
 sky130_fd_sc_hd__nor2_1 _2720_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_42_),
    .B(net32),
    .Y(_0867_));
 sky130_fd_sc_hd__o21ai_0 _2721_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_34_),
    .B1(_0664_),
    .Y(_0868_));
 sky130_fd_sc_hd__a22oi_1 _2722_ (.A1(net31),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_50_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_58_),
    .B2(net30),
    .Y(_0869_));
 sky130_fd_sc_hd__o211ai_1 _2723_ (.A1(_0867_),
    .A2(_0868_),
    .B1(net114),
    .C1(_0869_),
    .Y(_0870_));
 sky130_fd_sc_hd__nor2_1 _2724_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_10_),
    .B(net32),
    .Y(_0871_));
 sky130_fd_sc_hd__o21ai_0 _2725_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_2_),
    .B1(_0664_),
    .Y(_0872_));
 sky130_fd_sc_hd__nand2_1 _2726_ (.A(net31),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_18_),
    .Y(_0873_));
 sky130_fd_sc_hd__nand2_1 _2727_ (.A(net30),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_26_),
    .Y(_0874_));
 sky130_fd_sc_hd__o2111ai_1 _2728_ (.A1(_0871_),
    .A2(_0872_),
    .B1(_0391_),
    .C1(_0873_),
    .D1(_0874_),
    .Y(_0875_));
 sky130_fd_sc_hd__nand3_1 _2729_ (.A(_0870_),
    .B(_0875_),
    .C(_0388_),
    .Y(_0876_));
 sky130_fd_sc_hd__o31ai_1 _2730_ (.A1(_0388_),
    .A2(_0862_),
    .A3(_0866_),
    .B1(_0876_),
    .Y(_0877_));
 sky130_fd_sc_hd__inv_1 _2731_ (.A(reg2hw_36_),
    .Y(_0878_));
 sky130_fd_sc_hd__o21ai_0 _2732_ (.A1(_1358_),
    .A2(_0850_),
    .B1(_1369_),
    .Y(_0879_));
 sky130_fd_sc_hd__o21ai_0 _2733_ (.A1(_1367_),
    .A2(_1368_),
    .B1(_0851_),
    .Y(_0880_));
 sky130_fd_sc_hd__nand3_1 _2734_ (.A(_0487_),
    .B(_0879_),
    .C(_0880_),
    .Y(_0881_));
 sky130_fd_sc_hd__o21ai_0 _2735_ (.A1(_0878_),
    .A2(_0492_),
    .B1(_0881_),
    .Y(_0882_));
 sky130_fd_sc_hd__a2111oi_0 _2736_ (.A1(_0701_),
    .A2(_0877_),
    .B1(_0637_),
    .C1(_0882_),
    .D1(_0818_),
    .Y(_0883_));
 sky130_fd_sc_hd__nor2_1 _2737_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_36_),
    .B(net18),
    .Y(_0884_));
 sky130_fd_sc_hd__a21oi_1 _2738_ (.A1(_0883_),
    .A2(net17),
    .B1(_0884_),
    .Y(_0156_));
 sky130_fd_sc_hd__nor2_1 _2739_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_105_),
    .B(net32),
    .Y(_0885_));
 sky130_fd_sc_hd__o21ai_0 _2740_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_97_),
    .B1(_0664_),
    .Y(_0886_));
 sky130_fd_sc_hd__a22oi_1 _2741_ (.A1(net31),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_113_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_121_),
    .B2(net30),
    .Y(_0887_));
 sky130_fd_sc_hd__o211ai_1 _2742_ (.A1(_0885_),
    .A2(_0886_),
    .B1(net114),
    .C1(_0887_),
    .Y(_0888_));
 sky130_fd_sc_hd__nor2_1 _2743_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_73_),
    .B(net32),
    .Y(_0889_));
 sky130_fd_sc_hd__o21ai_0 _2744_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_65_),
    .B1(_0664_),
    .Y(_0890_));
 sky130_fd_sc_hd__nand2_1 _2745_ (.A(net31),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_81_),
    .Y(_0891_));
 sky130_fd_sc_hd__nand2_1 _2746_ (.A(net30),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_89_),
    .Y(_0892_));
 sky130_fd_sc_hd__o2111ai_1 _2747_ (.A1(_0889_),
    .A2(_0890_),
    .B1(_0391_),
    .C1(_0891_),
    .D1(_0892_),
    .Y(_0893_));
 sky130_fd_sc_hd__nand3_1 _2748_ (.A(_0888_),
    .B(net113),
    .C(_0893_),
    .Y(_0894_));
 sky130_fd_sc_hd__nor2_1 _2749_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_41_),
    .B(net32),
    .Y(_0895_));
 sky130_fd_sc_hd__o21ai_0 _2750_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_33_),
    .B1(_0664_),
    .Y(_0896_));
 sky130_fd_sc_hd__nand2_1 _2751_ (.A(net31),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_49_),
    .Y(_0897_));
 sky130_fd_sc_hd__nand2_1 _2752_ (.A(net30),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_57_),
    .Y(_0898_));
 sky130_fd_sc_hd__o2111ai_1 _2753_ (.A1(_0895_),
    .A2(_0896_),
    .B1(net114),
    .C1(_0897_),
    .D1(_0898_),
    .Y(_0899_));
 sky130_fd_sc_hd__nor2_1 _2754_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_9_),
    .B(net32),
    .Y(_0900_));
 sky130_fd_sc_hd__o21ai_0 _2755_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_1_),
    .B1(_0664_),
    .Y(_0901_));
 sky130_fd_sc_hd__nand2_1 _2756_ (.A(net31),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_17_),
    .Y(_0902_));
 sky130_fd_sc_hd__nand2_1 _2757_ (.A(net30),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_25_),
    .Y(_0903_));
 sky130_fd_sc_hd__o2111ai_1 _2758_ (.A1(_0900_),
    .A2(_0901_),
    .B1(_0391_),
    .C1(_0902_),
    .D1(_0903_),
    .Y(_0904_));
 sky130_fd_sc_hd__nand3_1 _2759_ (.A(_0899_),
    .B(_0904_),
    .C(_0388_),
    .Y(_0905_));
 sky130_fd_sc_hd__nand2_1 _2760_ (.A(_0894_),
    .B(_0905_),
    .Y(_0906_));
 sky130_fd_sc_hd__inv_1 _2761_ (.A(reg2hw_35_),
    .Y(_0907_));
 sky130_fd_sc_hd__o22ai_1 _2762_ (.A1(_0907_),
    .A2(_0492_),
    .B1(_0397_),
    .B2(_0479_),
    .Y(_0908_));
 sky130_fd_sc_hd__buf_2 _2763_ (.A(_1362_),
    .X(_0909_));
 sky130_fd_sc_hd__nor3_1 _2764_ (.A(net29),
    .B(net105),
    .C(_1361_),
    .Y(_0910_));
 sky130_fd_sc_hd__nor3_1 _2765_ (.A(_0850_),
    .B(_0910_),
    .C(_0488_),
    .Y(_0911_));
 sky130_fd_sc_hd__a2111oi_0 _2766_ (.A1(_0701_),
    .A2(_0906_),
    .B1(_0637_),
    .C1(_0908_),
    .D1(_0911_),
    .Y(_0912_));
 sky130_fd_sc_hd__nor2_1 _2767_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_35_),
    .B(net18),
    .Y(_0913_));
 sky130_fd_sc_hd__a21oi_1 _2768_ (.A1(_0912_),
    .A2(net17),
    .B1(_0913_),
    .Y(_0157_));
 sky130_fd_sc_hd__nor2_1 _2769_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_72_),
    .B(net32),
    .Y(_0914_));
 sky130_fd_sc_hd__o21ai_0 _2770_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_64_),
    .B1(_0664_),
    .Y(_0915_));
 sky130_fd_sc_hd__a21oi_1 _2771_ (.A1(net30),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_88_),
    .B1(net114),
    .Y(_0916_));
 sky130_fd_sc_hd__o21ai_0 _2772_ (.A1(_0914_),
    .A2(_0915_),
    .B1(_0916_),
    .Y(_0917_));
 sky130_fd_sc_hd__a21oi_1 _2773_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_80_),
    .A2(net31),
    .B1(_0917_),
    .Y(_0918_));
 sky130_fd_sc_hd__nor2_1 _2774_ (.A(net116),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_96_),
    .Y(_0919_));
 sky130_fd_sc_hd__o21ai_0 _2775_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_104_),
    .A2(net32),
    .B1(_0664_),
    .Y(_0920_));
 sky130_fd_sc_hd__a221oi_1 _2776_ (.A1(net31),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_112_),
    .B1(net30),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_120_),
    .C1(_0391_),
    .Y(_0921_));
 sky130_fd_sc_hd__o21a_1 _2777_ (.A1(_0919_),
    .A2(_0920_),
    .B1(_0921_),
    .X(_0922_));
 sky130_fd_sc_hd__nor2_1 _2778_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_8_),
    .B(net32),
    .Y(_0923_));
 sky130_fd_sc_hd__o21ai_0 _2779_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_0_),
    .B1(_0664_),
    .Y(_0924_));
 sky130_fd_sc_hd__a22oi_1 _2780_ (.A1(net31),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_16_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_24_),
    .B2(net30),
    .Y(_0925_));
 sky130_fd_sc_hd__o211ai_1 _2781_ (.A1(_0923_),
    .A2(_0924_),
    .B1(_0391_),
    .C1(_0925_),
    .Y(_0926_));
 sky130_fd_sc_hd__nor2_1 _2782_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_40_),
    .B(net32),
    .Y(_0927_));
 sky130_fd_sc_hd__o21ai_0 _2783_ (.A1(net116),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_32_),
    .B1(_0664_),
    .Y(_0928_));
 sky130_fd_sc_hd__nand2_1 _2784_ (.A(net31),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_48_),
    .Y(_0929_));
 sky130_fd_sc_hd__nand2_1 _2785_ (.A(net30),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_56_),
    .Y(_0930_));
 sky130_fd_sc_hd__o2111ai_1 _2786_ (.A1(_0927_),
    .A2(_0928_),
    .B1(net114),
    .C1(_0929_),
    .D1(_0930_),
    .Y(_0931_));
 sky130_fd_sc_hd__nand3_1 _2787_ (.A(_0926_),
    .B(_0931_),
    .C(_0388_),
    .Y(_0932_));
 sky130_fd_sc_hd__o31ai_1 _2788_ (.A1(_0388_),
    .A2(_0918_),
    .A3(_0922_),
    .B1(_0932_),
    .Y(_0933_));
 sky130_fd_sc_hd__a21oi_1 _2789_ (.A1(_0292_),
    .A2(_1370_),
    .B1(_0479_),
    .Y(_0934_));
 sky130_fd_sc_hd__lpflow_clkinvkapwr_1 _2790_ (.A(net74),
    .Y(_0935_));
 sky130_fd_sc_hd__o22ai_1 _2791_ (.A1(net44),
    .A2(_0492_),
    .B1(_1365_),
    .B2(_0488_),
    .Y(_0936_));
 sky130_fd_sc_hd__a2111oi_0 _2792_ (.A1(_0701_),
    .A2(_0933_),
    .B1(_0637_),
    .C1(_0934_),
    .D1(_0936_),
    .Y(_0937_));
 sky130_fd_sc_hd__nor2_1 _2793_ (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_34_),
    .B(net18),
    .Y(_0938_));
 sky130_fd_sc_hd__a21oi_1 _2794_ (.A1(_0937_),
    .A2(net17),
    .B1(_0938_),
    .Y(_0158_));
 sky130_fd_sc_hd__nor2_4 _2795_ (.A(net86),
    .B(_0640_),
    .Y(_0939_));
 sky130_fd_sc_hd__inv_4 _2796_ (.A(_0939_),
    .Y(_0940_));
 sky130_fd_sc_hd__buf_2 _2797_ (.A(_0940_),
    .X(_0941_));
 sky130_fd_sc_hd__dfstp_1 _2798_ (.D(_0242_),
    .Q(u_uart_core_uart_tx_sreg_q_0_),
    .SET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2799_ (.D(_0241_),
    .Q(u_uart_core_uart_tx_sreg_q_1_),
    .SET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2800_ (.D(_0240_),
    .Q(u_uart_core_uart_tx_sreg_q_2_),
    .SET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2801_ (.D(_0239_),
    .Q(u_uart_core_uart_tx_sreg_q_3_),
    .SET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2802_ (.D(_0238_),
    .Q(u_uart_core_uart_tx_sreg_q_4_),
    .SET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2803_ (.D(_0237_),
    .Q(u_uart_core_uart_tx_sreg_q_5_),
    .SET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2804_ (.D(_0236_),
    .Q(u_uart_core_uart_tx_sreg_q_6_),
    .SET_B(net65),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2805_ (.D(_0235_),
    .Q(u_uart_core_uart_tx_sreg_q_7_),
    .SET_B(net65),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2806_ (.D(_0234_),
    .Q(u_uart_core_uart_tx_sreg_q_8_),
    .SET_B(net65),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2807_ (.D(_0243_),
    .Q(u_uart_core_uart_tx_sreg_q_9_),
    .SET_B(net65),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2808_ (.D(_0233_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_0_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2809_ (.D(_0232_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_1_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2810_ (.D(_0231_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2811_ (.D(_0230_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2812_ (.D(_0244_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2813_ (.D(_0229_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_0_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2814_ (.D(_0228_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2815_ (.D(_0227_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2816_ (.D(_0226_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2817_ (.D(_0245_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2818_ (.D(_0225_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2819_ (.D(_0224_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2820_ (.D(_0223_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_2_),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2821_ (.D(_0246_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2822_ (.D(_0222_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_0_),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2823_ (.D(_0221_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2824_ (.D(_0220_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2825_ (.D(_0247_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2826_ (.D(_0219_),
    .Q(u_uart_core_uart_rx_baud_div_q_0_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2827_ (.D(_0218_),
    .Q(u_uart_core_uart_rx_baud_div_q_1_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2828_ (.D(_0217_),
    .Q(u_uart_core_uart_rx_baud_div_q_2_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2829_ (.D(_0248_),
    .Q(u_uart_core_uart_rx_baud_div_q_3_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2830_ (.D(_0216_),
    .Q(u_uart_core_uart_rx_bit_cnt_q_0_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2831_ (.D(_0215_),
    .Q(u_uart_core_uart_rx_bit_cnt_q_1_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2832_ (.D(_0214_),
    .Q(u_uart_core_uart_rx_bit_cnt_q_2_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2833_ (.D(_0249_),
    .Q(u_uart_core_uart_rx_bit_cnt_q_3_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2834_ (.D(_0250_),
    .Q(hw2reg_28_),
    .SET_B(net62),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2835_ (.D(_0213_),
    .Q(u_uart_core_uart_rx_sreg_q_1_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2836_ (.D(_0212_),
    .Q(u_uart_core_uart_rx_sreg_q_2_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2837_ (.D(_0211_),
    .Q(u_uart_core_uart_rx_sreg_q_3_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2838_ (.D(_0210_),
    .Q(u_uart_core_uart_rx_sreg_q_4_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2839_ (.D(_0209_),
    .Q(u_uart_core_uart_rx_sreg_q_5_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2840_ (.D(_0208_),
    .Q(u_uart_core_uart_rx_sreg_q_6_),
    .RESET_B(net61),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2841_ (.D(_0207_),
    .Q(u_uart_core_uart_rx_sreg_q_7_),
    .RESET_B(net62),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2842_ (.D(_0206_),
    .Q(u_uart_core_uart_rx_sreg_q_8_),
    .RESET_B(net62),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2843_ (.D(_0205_),
    .Q(u_uart_core_uart_rx_sreg_q_9_),
    .RESET_B(net62),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2844_ (.D(_0251_),
    .Q(u_uart_core_uart_rx_sreg_q_10_),
    .RESET_B(net62),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2845_ (.D(_0204_),
    .Q(u_uart_core_uart_tx_baud_div_q_0_),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2846_ (.D(_0203_),
    .Q(u_uart_core_uart_tx_baud_div_q_1_),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2847_ (.D(_0202_),
    .Q(u_uart_core_uart_tx_baud_div_q_2_),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2848_ (.D(_0252_),
    .Q(u_uart_core_uart_tx_baud_div_q_3_),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2849_ (.D(_0201_),
    .Q(u_uart_core_uart_tx_bit_cnt_q_0_),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2850_ (.D(_0200_),
    .Q(u_uart_core_uart_tx_bit_cnt_q_1_),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2851_ (.D(_0199_),
    .Q(u_uart_core_uart_tx_bit_cnt_q_2_),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2852_ (.D(_0253_),
    .Q(u_uart_core_uart_tx_bit_cnt_q_3_),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2853_ (.D(_0254_),
    .Q(u_uart_core_tx_out),
    .SET_B(net65),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2854_ (.D(_0257_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_read_pointer_q),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2855_ (.D(_0190_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_status_cnt_q_0_),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2856_ (.D(_0258_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_status_cnt_q_1_),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2857_ (.D(_0259_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_write_pointer_q),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2858_ (.D(_0264_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_read_pointer_q),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2859_ (.D(_0127_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_status_cnt_q_0_),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2860_ (.D(_0265_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_status_cnt_q_1_),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2861_ (.D(_0266_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_write_pointer_q),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2862_ (.D(_0273_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_read_pointer_q),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2863_ (.D(_0066_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_status_cnt_q_0_),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2864_ (.D(_0274_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_status_cnt_q_1_),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2865_ (.D(_0275_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_write_pointer_q),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2866_ (.D(_0277_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_read_pointer_q),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2867_ (.D(_0064_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_status_cnt_q_0_),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2868_ (.D(_0278_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_status_cnt_q_1_),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2869_ (.D(_0279_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_write_pointer_q),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2870_ (.D(_0280_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_stream_arbiter_i_arb_gen_rr_arb_i_arbiter_gen_arbiter_rr_q),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2871_ (.D(_0281_),
    .Q(reg2hw_38_),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2872_ (.D(_0063_),
    .Q(reg2hw_41_),
    .SET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2873_ (.D(_0062_),
    .Q(reg2hw_42_),
    .SET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2874_ (.D(_0061_),
    .Q(reg2hw_43_),
    .SET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2875_ (.D(_0060_),
    .Q(reg2hw_44_),
    .SET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2876_ (.D(_0059_),
    .Q(reg2hw_45_),
    .SET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2877_ (.D(_0058_),
    .Q(reg2hw_46_),
    .SET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2878_ (.D(_0057_),
    .Q(reg2hw_47_),
    .SET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2879_ (.D(_0056_),
    .Q(reg2hw_48_),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2880_ (.D(_0055_),
    .Q(reg2hw_49_),
    .SET_B(net57),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2881_ (.D(_0054_),
    .Q(reg2hw_50_),
    .SET_B(net57),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2882_ (.D(_0053_),
    .Q(reg2hw_51_),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2883_ (.D(_0052_),
    .Q(reg2hw_52_),
    .SET_B(net57),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2884_ (.D(_0051_),
    .Q(reg2hw_53_),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2885_ (.D(_0050_),
    .Q(reg2hw_54_),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2886_ (.D(_0049_),
    .Q(reg2hw_55_),
    .SET_B(net57),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2887_ (.D(_0282_),
    .Q(reg2hw_56_),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2888_ (.D(_0283_),
    .Q(reg2hw_36_),
    .RESET_B(net49),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2889_ (.D(_0284_),
    .Q(reg2hw_39_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2890_ (.D(_0285_),
    .Q(reg2hw_40_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2891_ (.D(_0286_),
    .Q(reg2hw_35_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2892_ (.D(_0287_),
    .Q(reg2hw_37_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2893_ (.D(_0288_),
    .Q(reg2hw_34_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2894_ (.D(_0289_),
    .Q(reg2hw_1_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2895_ (.D(_0290_),
    .Q(reg2hw_3_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2896_ (.D(_0048_),
    .Q(reg2hw_5_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2897_ (.D(_0047_),
    .Q(reg2hw_6_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2898_ (.D(_0046_),
    .Q(reg2hw_7_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2899_ (.D(_0045_),
    .Q(reg2hw_8_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2900_ (.D(_0044_),
    .Q(reg2hw_9_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2901_ (.D(_0043_),
    .Q(reg2hw_10_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2902_ (.D(_0042_),
    .Q(reg2hw_11_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2903_ (.D(_0291_),
    .Q(reg2hw_12_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2904_ (.D(u_uart_reg_u_reg_core_reg_we_check_3_),
    .Q(reg2hw_4_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2905_ (.D(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .Q(reg2hw_0_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2906_ (.D(_1372_),
    .Q(u_uart_core_uart_tx_tick_baud_q),
    .RESET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2907_ (.D(u_uart_core_uart_rx_tick_baud_d),
    .Q(u_uart_core_rx_tick_baud),
    .RESET_B(net62),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2908_ (.D(_0000_),
    .Q(u_uart_core_rx_valid),
    .RESET_B(net62),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2909_ (.D(net),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_under_rst),
    .SET_B(net65),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _2909__1 (.LO(net));
 sky130_fd_sc_hd__dfstp_1 _2910_ (.D(net1),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_under_rst),
    .SET_B(net62),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _2910__2 (.LO(net1));
 sky130_fd_sc_hd__dfrtp_1 _2911_ (.D(net4),
    .Q(u_uart_core_tx_rst_ni),
    .RESET_B(net48),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _2911__5 (.HI(net4));
 sky130_fd_sc_hd__dfrtp_1 _2912_ (.D(net5),
    .Q(u_uart_core_timing_rst_ni),
    .RESET_B(net48),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _2912__6 (.HI(net5));
 sky130_fd_sc_hd__dfrtp_1 _2913_ (.D(net6),
    .Q(u_uart_core_rx_rst_ni),
    .RESET_B(net48),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _2913__7 (.HI(net6));
 sky130_fd_sc_hd__dfstp_1 _2914_ (.D(_1371_),
    .Q(u_uart_core_tx_out_q),
    .SET_B(net64),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2915_ (.D(u_uart_core_sync_rx_intq),
    .Q(u_uart_core_rx_sync),
    .SET_B(net62),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2916_ (.D(rx_i),
    .Q(u_uart_core_sync_rx_intq),
    .SET_B(net62),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2917_ (.D(u_uart_core_rx_sync_q1),
    .Q(u_uart_core_rx_sync_q2),
    .SET_B(net62),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2918_ (.D(u_uart_core_rx_sync),
    .Q(u_uart_core_rx_sync_q1),
    .SET_B(net62),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2919_ (.D(_0002_),
    .Q(u_uart_core_nco_sum_q_0_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2920_ (.D(_0009_),
    .Q(u_uart_core_nco_sum_q_1_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2921_ (.D(_0010_),
    .Q(u_uart_core_nco_sum_q_2_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2922_ (.D(_0011_),
    .Q(u_uart_core_nco_sum_q_3_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2923_ (.D(_0012_),
    .Q(u_uart_core_nco_sum_q_4_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2924_ (.D(_0013_),
    .Q(u_uart_core_nco_sum_q_5_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2925_ (.D(_0014_),
    .Q(u_uart_core_nco_sum_q_6_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2926_ (.D(_0015_),
    .Q(u_uart_core_nco_sum_q_7_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2927_ (.D(_0016_),
    .Q(u_uart_core_nco_sum_q_8_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2928_ (.D(_0017_),
    .Q(u_uart_core_nco_sum_q_9_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2929_ (.D(_0003_),
    .Q(u_uart_core_nco_sum_q_10_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2930_ (.D(_0004_),
    .Q(u_uart_core_nco_sum_q_11_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2931_ (.D(_0005_),
    .Q(u_uart_core_nco_sum_q_12_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2932_ (.D(_0006_),
    .Q(u_uart_core_nco_sum_q_13_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2933_ (.D(_0007_),
    .Q(u_uart_core_nco_sum_q_14_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2934_ (.D(_0008_),
    .Q(u_uart_core_nco_sum_q_15_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2935_ (.D(_0001_),
    .Q(u_uart_core_nco_sum_q_16_),
    .RESET_B(net63),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2936_ (.D(u_reg_reset_sync_intq),
    .Q(reg_rst_ni),
    .RESET_B(rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2937_ (.D(net7),
    .Q(u_reg_reset_sync_intq),
    .RESET_B(rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _2937__8 (.HI(net7));
 sky130_fd_sc_hd__dfrtp_1 _2938_ (.D(u_core_reset_sync_intq),
    .Q(core_rst_ni),
    .RESET_B(rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2939_ (.D(net8),
    .Q(u_core_reset_sync_intq),
    .RESET_B(rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _2939__9 (.HI(net8));
 sky130_fd_sc_hd__dfrtp_1 _2940_ (.D(_0276_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_mem_q_1_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2941_ (.D(_0272_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_44_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2942_ (.D(_0271_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_76_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2943_ (.D(_0270_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_81_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2944_ (.D(_0269_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_3_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2945_ (.D(_0268_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_35_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2946_ (.D(_0267_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_40_),
    .RESET_B(net50),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2947_ (.D(_0263_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_33_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2948_ (.D(_0262_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_65_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2949_ (.D(_0261_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_0_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2950_ (.D(_0260_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_32_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2951_ (.D(_0256_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_9_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2952_ (.D(_0255_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_4_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2953_ (.D(net66),
    .DE(_0018_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_63_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2954_ (.D(net66),
    .DE(_0019_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_55_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2955_ (.D(net66),
    .DE(_0020_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_47_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2956_ (.D(net66),
    .DE(net23),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_39_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2957_ (.D(net66),
    .DE(_0022_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_31_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2958_ (.D(net66),
    .DE(_0023_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_23_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2959_ (.D(net66),
    .DE(_0024_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_15_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2960_ (.D(net66),
    .DE(net22),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_7_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2961_ (.D(net43),
    .DE(_0026_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_79_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2962_ (.D(net43),
    .DE(_0027_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_71_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2963_ (.D(net43),
    .DE(_0028_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_63_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2964_ (.D(net43),
    .DE(_0029_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_55_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2965_ (.D(net43),
    .DE(_0030_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_47_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2966_ (.D(net43),
    .DE(_0031_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_39_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2967_ (.D(net43),
    .DE(_0032_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_31_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2968_ (.D(net43),
    .DE(_0033_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_23_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2969_ (.D(net43),
    .DE(_0034_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_15_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2970_ (.D(net43),
    .DE(_0035_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_127_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2971_ (.D(net43),
    .DE(_0036_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_119_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2972_ (.D(net43),
    .DE(_0037_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_111_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2973_ (.D(net43),
    .DE(_0038_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_103_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2974_ (.D(net43),
    .DE(_0039_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_95_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2975_ (.D(net43),
    .DE(_0040_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_87_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2976_ (.D(net43),
    .DE(_0041_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_7_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2977_ (.D(net34),
    .DE(_0041_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_0_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2978_ (.D(net35),
    .DE(_0041_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_1_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2979_ (.D(net36),
    .DE(_0041_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_2_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2980_ (.D(net37),
    .DE(_0041_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_3_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2981_ (.D(net38),
    .DE(_0041_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_4_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2982_ (.D(net39),
    .DE(_0041_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_5_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2983_ (.D(net40),
    .DE(_0041_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_6_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2984_ (.D(net34),
    .DE(_0040_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_80_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2985_ (.D(net35),
    .DE(_0040_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_81_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2986_ (.D(net36),
    .DE(_0040_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_82_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2987_ (.D(net37),
    .DE(_0040_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_83_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2988_ (.D(net38),
    .DE(_0040_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_84_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2989_ (.D(net39),
    .DE(_0040_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_85_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2990_ (.D(net40),
    .DE(_0040_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_86_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2991_ (.D(net34),
    .DE(_0039_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_88_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2992_ (.D(net35),
    .DE(_0039_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_89_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2993_ (.D(net36),
    .DE(_0039_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_90_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2994_ (.D(net37),
    .DE(_0039_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_91_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2995_ (.D(net38),
    .DE(_0039_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_92_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2996_ (.D(net39),
    .DE(_0039_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_93_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2997_ (.D(net40),
    .DE(_0039_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_94_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2998_ (.D(net34),
    .DE(_0038_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_96_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2999_ (.D(net35),
    .DE(_0038_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_97_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3000_ (.D(net36),
    .DE(_0038_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_98_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3001_ (.D(net37),
    .DE(_0038_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_99_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3002_ (.D(net38),
    .DE(_0038_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_100_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3003_ (.D(net39),
    .DE(_0038_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_101_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3004_ (.D(net40),
    .DE(_0038_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_102_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3005_ (.D(net34),
    .DE(_0037_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_104_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3006_ (.D(net35),
    .DE(_0037_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_105_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3007_ (.D(net36),
    .DE(_0037_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_106_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3008_ (.D(net37),
    .DE(_0037_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_107_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3009_ (.D(net38),
    .DE(_0037_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_108_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3010_ (.D(net39),
    .DE(_0037_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_109_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3011_ (.D(net40),
    .DE(_0037_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_110_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3012_ (.D(net34),
    .DE(_0036_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_112_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3013_ (.D(net35),
    .DE(_0036_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_113_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3014_ (.D(net36),
    .DE(_0036_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_114_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3015_ (.D(net37),
    .DE(_0036_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_115_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3016_ (.D(net38),
    .DE(_0036_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_116_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3017_ (.D(net39),
    .DE(_0036_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_117_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3018_ (.D(net40),
    .DE(_0036_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_118_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3019_ (.D(net34),
    .DE(_0035_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_120_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3020_ (.D(net35),
    .DE(_0035_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_121_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3021_ (.D(net36),
    .DE(_0035_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_122_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3022_ (.D(net37),
    .DE(_0035_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_123_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3023_ (.D(net38),
    .DE(_0035_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_124_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3024_ (.D(net39),
    .DE(_0035_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_125_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3025_ (.D(net40),
    .DE(_0035_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_126_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3026_ (.D(net34),
    .DE(_0034_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_8_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3027_ (.D(net35),
    .DE(_0034_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_9_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3028_ (.D(net36),
    .DE(_0034_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_10_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3029_ (.D(net37),
    .DE(_0034_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_11_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3030_ (.D(net38),
    .DE(_0034_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_12_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3031_ (.D(net39),
    .DE(_0034_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_13_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3032_ (.D(net40),
    .DE(_0034_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_14_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3033_ (.D(net34),
    .DE(_0033_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_16_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3034_ (.D(net35),
    .DE(_0033_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_17_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3035_ (.D(net36),
    .DE(_0033_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_18_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3036_ (.D(net37),
    .DE(_0033_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_19_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3037_ (.D(net38),
    .DE(_0033_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_20_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3038_ (.D(net39),
    .DE(_0033_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_21_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3039_ (.D(net40),
    .DE(_0033_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_22_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3040_ (.D(net34),
    .DE(_0032_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_24_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3041_ (.D(net35),
    .DE(_0032_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_25_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3042_ (.D(net36),
    .DE(_0032_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_26_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3043_ (.D(net37),
    .DE(_0032_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_27_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3044_ (.D(net38),
    .DE(_0032_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_28_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3045_ (.D(net39),
    .DE(_0032_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_29_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3046_ (.D(net40),
    .DE(_0032_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_30_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3047_ (.D(net34),
    .DE(_0031_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_32_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3048_ (.D(net35),
    .DE(_0031_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_33_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3049_ (.D(net36),
    .DE(_0031_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_34_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3050_ (.D(net37),
    .DE(_0031_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_35_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3051_ (.D(net38),
    .DE(_0031_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_36_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3052_ (.D(net39),
    .DE(_0031_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_37_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3053_ (.D(net40),
    .DE(_0031_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_38_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3054_ (.D(net34),
    .DE(_0030_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_40_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3055_ (.D(net35),
    .DE(_0030_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_41_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3056_ (.D(net36),
    .DE(_0030_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_42_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3057_ (.D(net37),
    .DE(_0030_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_43_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3058_ (.D(net38),
    .DE(_0030_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_44_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3059_ (.D(net39),
    .DE(_0030_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_45_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3060_ (.D(net40),
    .DE(_0030_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_46_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3061_ (.D(net34),
    .DE(_0029_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_48_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3062_ (.D(net35),
    .DE(_0029_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_49_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3063_ (.D(net36),
    .DE(_0029_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_50_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3064_ (.D(net37),
    .DE(_0029_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_51_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3065_ (.D(net38),
    .DE(_0029_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_52_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3066_ (.D(net39),
    .DE(_0029_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_53_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3067_ (.D(net40),
    .DE(_0029_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_54_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3068_ (.D(net34),
    .DE(_0028_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_56_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3069_ (.D(net35),
    .DE(_0028_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_57_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3070_ (.D(net36),
    .DE(_0028_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_58_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3071_ (.D(net37),
    .DE(_0028_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_59_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3072_ (.D(net38),
    .DE(_0028_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_60_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3073_ (.D(net39),
    .DE(_0028_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_61_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3074_ (.D(net40),
    .DE(_0028_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_62_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3075_ (.D(net34),
    .DE(_0027_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_64_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3076_ (.D(net35),
    .DE(_0027_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_65_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3077_ (.D(net36),
    .DE(_0027_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_66_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3078_ (.D(net37),
    .DE(_0027_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_67_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3079_ (.D(net38),
    .DE(_0027_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_68_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3080_ (.D(net39),
    .DE(_0027_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_69_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3081_ (.D(net40),
    .DE(_0027_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_70_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3082_ (.D(net34),
    .DE(_0026_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_72_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3083_ (.D(net35),
    .DE(_0026_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_73_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3084_ (.D(net36),
    .DE(_0026_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_74_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3085_ (.D(net37),
    .DE(_0026_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_75_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3086_ (.D(net38),
    .DE(_0026_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_76_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3087_ (.D(net39),
    .DE(_0026_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_77_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3088_ (.D(net40),
    .DE(_0026_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_78_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3089_ (.D(net73),
    .DE(net22),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_0_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3090_ (.D(net72),
    .DE(net22),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_1_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3091_ (.D(net71),
    .DE(net22),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_2_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3092_ (.D(net70),
    .DE(net22),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_3_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3093_ (.D(net69),
    .DE(net22),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_4_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3094_ (.D(net68),
    .DE(net22),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_5_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3095_ (.D(net67),
    .DE(net22),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_6_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3096_ (.D(net73),
    .DE(_0024_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_8_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3097_ (.D(net72),
    .DE(_0024_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_9_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3098_ (.D(net71),
    .DE(_0024_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_10_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3099_ (.D(net70),
    .DE(_0024_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_11_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3100_ (.D(net69),
    .DE(_0024_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_12_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3101_ (.D(net68),
    .DE(_0024_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_13_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3102_ (.D(net67),
    .DE(_0024_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_14_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3103_ (.D(net73),
    .DE(_0023_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_16_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3104_ (.D(net72),
    .DE(_0023_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_17_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3105_ (.D(net71),
    .DE(_0023_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_18_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3106_ (.D(net70),
    .DE(_0023_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_19_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3107_ (.D(net69),
    .DE(_0023_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_20_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3108_ (.D(net68),
    .DE(_0023_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_21_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3109_ (.D(net67),
    .DE(_0023_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_22_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3110_ (.D(net73),
    .DE(_0022_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_24_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3111_ (.D(net72),
    .DE(_0022_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_25_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3112_ (.D(net71),
    .DE(_0022_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_26_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3113_ (.D(net70),
    .DE(_0022_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_27_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3114_ (.D(net69),
    .DE(_0022_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_28_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3115_ (.D(net68),
    .DE(_0022_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_29_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3116_ (.D(net67),
    .DE(_0022_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_30_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3117_ (.D(net73),
    .DE(net23),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_32_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3118_ (.D(net72),
    .DE(net23),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_33_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3119_ (.D(net71),
    .DE(net23),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_34_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3120_ (.D(net70),
    .DE(net23),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_35_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3121_ (.D(net69),
    .DE(net23),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_36_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3122_ (.D(net68),
    .DE(net23),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_37_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3123_ (.D(net67),
    .DE(net23),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_38_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3124_ (.D(net73),
    .DE(_0020_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_40_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3125_ (.D(net72),
    .DE(_0020_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_41_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3126_ (.D(net71),
    .DE(_0020_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_42_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3127_ (.D(net70),
    .DE(_0020_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_43_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3128_ (.D(net69),
    .DE(_0020_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_44_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3129_ (.D(net68),
    .DE(_0020_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_45_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3130_ (.D(net67),
    .DE(_0020_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_46_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3131_ (.D(net73),
    .DE(_0019_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_48_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3132_ (.D(net72),
    .DE(_0019_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_49_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3133_ (.D(net71),
    .DE(_0019_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_50_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3134_ (.D(net70),
    .DE(_0019_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_51_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3135_ (.D(net69),
    .DE(_0019_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_52_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3136_ (.D(net68),
    .DE(_0019_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_53_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3137_ (.D(net67),
    .DE(_0019_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_54_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3138_ (.D(net73),
    .DE(_0018_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_56_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3139_ (.D(net72),
    .DE(_0018_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_57_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3140_ (.D(net71),
    .DE(_0018_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_58_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3141_ (.D(net70),
    .DE(_0018_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_59_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3142_ (.D(net69),
    .DE(_0018_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_60_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3143_ (.D(net68),
    .DE(_0018_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_61_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3144_ (.D(net67),
    .DE(_0018_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_62_),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3145_ (.D(_0198_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_0_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3146_ (.D(_0197_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_1_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3147_ (.D(_0196_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_2_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3148_ (.D(_0195_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_3_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3149_ (.D(_0194_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_5_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3150_ (.D(_0193_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_6_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3151_ (.D(_0192_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_7_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3152_ (.D(_0191_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_mem_q_8_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3153_ (.D(_0189_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_1_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3154_ (.D(_0188_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_2_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3155_ (.D(_0187_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_3_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3156_ (.D(_0186_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_4_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3157_ (.D(_0185_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_5_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3158_ (.D(_0184_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_6_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3159_ (.D(_0183_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_7_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3160_ (.D(_0182_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_8_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3161_ (.D(_0181_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_9_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3162_ (.D(_0180_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_10_),
    .RESET_B(net51),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3163_ (.D(_0179_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_11_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3164_ (.D(_0178_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_12_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3165_ (.D(_0177_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_13_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3166_ (.D(_0176_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_14_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3167_ (.D(_0175_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_15_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3168_ (.D(_0174_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_16_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3169_ (.D(_0173_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_17_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3170_ (.D(_0172_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_18_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3171_ (.D(_0171_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_19_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3172_ (.D(_0170_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_20_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3173_ (.D(_0169_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_21_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3174_ (.D(_0168_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_22_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3175_ (.D(_0167_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_23_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3176_ (.D(_0166_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_24_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3177_ (.D(_0165_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_25_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3178_ (.D(_0164_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_26_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3179_ (.D(_0163_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_27_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3180_ (.D(_0162_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_28_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3181_ (.D(_0161_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_29_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3182_ (.D(_0160_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_30_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3183_ (.D(_0159_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_31_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3184_ (.D(_0158_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_34_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3185_ (.D(_0157_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_35_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3186_ (.D(_0156_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_36_),
    .RESET_B(net52),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3187_ (.D(_0155_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_37_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3188_ (.D(_0154_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_38_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3189_ (.D(_0153_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_39_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3190_ (.D(_0152_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_40_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3191_ (.D(_0151_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_41_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3192_ (.D(_0150_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_42_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3193_ (.D(_0149_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_43_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3194_ (.D(_0148_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_44_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3195_ (.D(_0147_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_45_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3196_ (.D(_0146_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_46_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3197_ (.D(_0145_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_47_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3198_ (.D(_0144_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_48_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3199_ (.D(_0143_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_49_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3200_ (.D(_0142_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_50_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3201_ (.D(_0141_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_51_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3202_ (.D(_0140_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_52_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3203_ (.D(_0139_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_53_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3204_ (.D(_0138_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_54_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3205_ (.D(_0137_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_55_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3206_ (.D(_0136_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_56_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3207_ (.D(_0135_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_57_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3208_ (.D(_0134_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_58_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3209_ (.D(_0133_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_59_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3210_ (.D(_0132_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_60_),
    .RESET_B(net53),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3211_ (.D(_0131_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_61_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3212_ (.D(_0130_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_62_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3213_ (.D(_0129_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_63_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3214_ (.D(_0128_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_mem_q_64_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3215_ (.D(_0126_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_36_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3216_ (.D(_0125_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_37_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3217_ (.D(_0124_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_38_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3218_ (.D(_0123_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_39_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3219_ (.D(_0122_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_4_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3220_ (.D(_0121_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_5_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3221_ (.D(_0120_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_6_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3222_ (.D(_0119_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_7_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3223_ (.D(_0118_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_8_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3224_ (.D(_0117_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_9_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3225_ (.D(_0116_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_10_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3226_ (.D(_0115_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_11_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3227_ (.D(_0114_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_20_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3228_ (.D(_0113_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_21_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3229_ (.D(_0112_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_22_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3230_ (.D(_0111_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_23_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3231_ (.D(_0110_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_24_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3232_ (.D(_0109_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_25_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3233_ (.D(_0108_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_26_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3234_ (.D(_0107_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_27_),
    .RESET_B(net54),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3235_ (.D(_0106_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_28_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3236_ (.D(_0105_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_29_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3237_ (.D(_0104_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_30_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3238_ (.D(_0103_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_31_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3239_ (.D(_0102_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_32_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3240_ (.D(_0101_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_33_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3241_ (.D(_0100_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_34_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3242_ (.D(_0099_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_0_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3243_ (.D(_0098_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_1_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3244_ (.D(_0097_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_2_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3245_ (.D(_0096_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_77_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3246_ (.D(_0095_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_78_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3247_ (.D(_0094_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_79_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3248_ (.D(_0093_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_80_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3249_ (.D(_0092_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_45_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3250_ (.D(_0091_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_46_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3251_ (.D(_0090_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_47_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3252_ (.D(_0089_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_48_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3253_ (.D(_0088_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_49_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3254_ (.D(_0087_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_50_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3255_ (.D(_0086_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_51_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3256_ (.D(_0085_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_52_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3257_ (.D(_0084_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_61_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3258_ (.D(_0083_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_62_),
    .RESET_B(net55),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3259_ (.D(_0082_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_63_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3260_ (.D(_0081_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_64_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3261_ (.D(_0080_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_65_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3262_ (.D(_0079_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_66_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3263_ (.D(_0078_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_67_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3264_ (.D(_0077_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_68_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3265_ (.D(_0076_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_69_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3266_ (.D(_0075_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_70_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3267_ (.D(_0074_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_71_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3268_ (.D(_0073_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_72_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3269_ (.D(_0072_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_73_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3270_ (.D(_0071_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_74_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3271_ (.D(_0070_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_75_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3272_ (.D(_0069_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_41_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3273_ (.D(_0068_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_42_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3274_ (.D(_0067_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_mem_q_43_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3275_ (.D(_0065_),
    .Q(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_mem_q_0_),
    .RESET_B(net56),
    .CLK(clk_i));
 sky130_fd_sc_hd__buf_2 _3278_ (.A(u_uart_reg_axi_lite_o_0_),
    .X(axi_lite_o[0]));
 sky130_fd_sc_hd__buf_4 _3279_ (.A(net2),
    .X(axi_lite_o[1]));
 sky130_fd_sc_hd__conb_1 _3279__3 (.LO(net2));
 sky130_fd_sc_hd__buf_2 _3280_ (.A(u_uart_reg_axi_lite_o_2_),
    .X(axi_lite_o[2]));
 sky130_fd_sc_hd__buf_2 _3281_ (.A(u_uart_reg_axi_lite_o_3_),
    .X(axi_lite_o[3]));
 sky130_fd_sc_hd__buf_2 _3282_ (.A(u_uart_reg_axi_lite_o_4_),
    .X(axi_lite_o[4]));
 sky130_fd_sc_hd__buf_2 _3283_ (.A(u_uart_reg_axi_lite_o_5_),
    .X(axi_lite_o[5]));
 sky130_fd_sc_hd__buf_2 _3284_ (.A(u_uart_reg_axi_lite_o_6_),
    .X(axi_lite_o[6]));
 sky130_fd_sc_hd__buf_2 _3285_ (.A(u_uart_reg_axi_lite_o_7_),
    .X(axi_lite_o[7]));
 sky130_fd_sc_hd__buf_2 _3286_ (.A(u_uart_reg_axi_lite_o_8_),
    .X(axi_lite_o[8]));
 sky130_fd_sc_hd__buf_2 _3287_ (.A(u_uart_reg_axi_lite_o_9_),
    .X(axi_lite_o[9]));
 sky130_fd_sc_hd__buf_2 _3288_ (.A(u_uart_reg_axi_lite_o_10_),
    .X(axi_lite_o[10]));
 sky130_fd_sc_hd__buf_2 _3289_ (.A(u_uart_reg_axi_lite_o_11_),
    .X(axi_lite_o[11]));
 sky130_fd_sc_hd__buf_2 _3290_ (.A(u_uart_reg_axi_lite_o_12_),
    .X(axi_lite_o[12]));
 sky130_fd_sc_hd__buf_2 _3291_ (.A(u_uart_reg_axi_lite_o_13_),
    .X(axi_lite_o[13]));
 sky130_fd_sc_hd__buf_2 _3292_ (.A(u_uart_reg_axi_lite_o_14_),
    .X(axi_lite_o[14]));
 sky130_fd_sc_hd__buf_2 _3293_ (.A(u_uart_reg_axi_lite_o_15_),
    .X(axi_lite_o[15]));
 sky130_fd_sc_hd__buf_2 _3294_ (.A(u_uart_reg_axi_lite_o_16_),
    .X(axi_lite_o[16]));
 sky130_fd_sc_hd__buf_2 _3295_ (.A(u_uart_reg_axi_lite_o_17_),
    .X(axi_lite_o[17]));
 sky130_fd_sc_hd__buf_2 _3296_ (.A(u_uart_reg_axi_lite_o_18_),
    .X(axi_lite_o[18]));
 sky130_fd_sc_hd__buf_2 _3297_ (.A(u_uart_reg_axi_lite_o_19_),
    .X(axi_lite_o[19]));
 sky130_fd_sc_hd__buf_2 _3298_ (.A(u_uart_reg_axi_lite_o_20_),
    .X(axi_lite_o[20]));
 sky130_fd_sc_hd__buf_2 _3299_ (.A(u_uart_reg_axi_lite_o_21_),
    .X(axi_lite_o[21]));
 sky130_fd_sc_hd__buf_2 _3300_ (.A(u_uart_reg_axi_lite_o_22_),
    .X(axi_lite_o[22]));
 sky130_fd_sc_hd__buf_2 _3301_ (.A(u_uart_reg_axi_lite_o_23_),
    .X(axi_lite_o[23]));
 sky130_fd_sc_hd__buf_2 _3302_ (.A(u_uart_reg_axi_lite_o_24_),
    .X(axi_lite_o[24]));
 sky130_fd_sc_hd__buf_2 _3303_ (.A(u_uart_reg_axi_lite_o_25_),
    .X(axi_lite_o[25]));
 sky130_fd_sc_hd__buf_2 _3304_ (.A(u_uart_reg_axi_lite_o_26_),
    .X(axi_lite_o[26]));
 sky130_fd_sc_hd__buf_2 _3305_ (.A(u_uart_reg_axi_lite_o_27_),
    .X(axi_lite_o[27]));
 sky130_fd_sc_hd__buf_2 _3306_ (.A(u_uart_reg_axi_lite_o_28_),
    .X(axi_lite_o[28]));
 sky130_fd_sc_hd__buf_2 _3307_ (.A(u_uart_reg_axi_lite_o_29_),
    .X(axi_lite_o[29]));
 sky130_fd_sc_hd__buf_2 _3308_ (.A(u_uart_reg_axi_lite_o_30_),
    .X(axi_lite_o[30]));
 sky130_fd_sc_hd__buf_2 _3309_ (.A(u_uart_reg_axi_lite_o_31_),
    .X(axi_lite_o[31]));
 sky130_fd_sc_hd__buf_2 _3310_ (.A(u_uart_reg_axi_lite_o_32_),
    .X(axi_lite_o[32]));
 sky130_fd_sc_hd__buf_2 _3311_ (.A(u_uart_reg_axi_lite_o_33_),
    .X(axi_lite_o[33]));
 sky130_fd_sc_hd__buf_2 _3312_ (.A(u_uart_reg_axi_lite_o_34_),
    .X(axi_lite_o[34]));
 sky130_fd_sc_hd__buf_2 _3313_ (.A(u_uart_reg_axi_lite_o_35_),
    .X(axi_lite_o[35]));
 sky130_fd_sc_hd__buf_2 _3314_ (.A(u_uart_reg_axi_lite_o_36_),
    .X(axi_lite_o[36]));
 sky130_fd_sc_hd__buf_4 _3315_ (.A(net3),
    .X(axi_lite_o[37]));
 sky130_fd_sc_hd__conb_1 _3315__4 (.LO(net3));
 sky130_fd_sc_hd__buf_2 _3316_ (.A(u_uart_reg_axi_lite_o_38_),
    .X(axi_lite_o[38]));
 sky130_fd_sc_hd__buf_2 _3317_ (.A(u_uart_reg_axi_lite_o_39_),
    .X(axi_lite_o[39]));
 sky130_fd_sc_hd__buf_2 _3318_ (.A(u_uart_reg_axi_lite_o_39_),
    .X(axi_lite_o[40]));
 sky130_fd_sc_hd__buf_12 gain10 (.A(_0525_),
    .X(net9));
 sky130_fd_sc_hd__buf_2 gain100 (.A(u_uart_core_uart_rx_sreg_q_2_),
    .X(net99));
 sky130_fd_sc_hd__buf_2 gain101 (.A(u_uart_core_uart_rx_bit_cnt_q_3_),
    .X(net100));
 sky130_fd_sc_hd__buf_2 gain102 (.A(u_uart_core_uart_rx_bit_cnt_q_1_),
    .X(net101));
 sky130_fd_sc_hd__buf_2 gain103 (.A(u_uart_core_uart_rx_bit_cnt_q_0_),
    .X(net102));
 sky130_fd_sc_hd__buf_12 gain104 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_),
    .X(net103));
 sky130_fd_sc_hd__buf_12 gain105 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_),
    .X(net104));
 sky130_fd_sc_hd__buf_2 gain106 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_0_),
    .X(net105));
 sky130_fd_sc_hd__buf_12 gain107 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_2_),
    .X(net106));
 sky130_fd_sc_hd__buf_12 gain108 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_),
    .X(net107));
 sky130_fd_sc_hd__buf_12 gain109 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .X(net108));
 sky130_fd_sc_hd__buf_4 gain11 (.A(_0427_),
    .X(net10));
 sky130_fd_sc_hd__buf_12 gain110 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_),
    .X(net109));
 sky130_fd_sc_hd__buf_12 gain111 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_),
    .X(net110));
 sky130_fd_sc_hd__buf_4 gain112 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_),
    .X(net111));
 sky130_fd_sc_hd__buf_2 gain113 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_0_),
    .X(net112));
 sky130_fd_sc_hd__buf_12 gain114 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_),
    .X(net113));
 sky130_fd_sc_hd__buf_12 gain115 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_),
    .X(net114));
 sky130_fd_sc_hd__buf_12 gain116 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_1_),
    .X(net115));
 sky130_fd_sc_hd__buf_12 gain117 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_0_),
    .X(net116));
 sky130_fd_sc_hd__buf_4 gain12 (.A(_0413_),
    .X(net11));
 sky130_fd_sc_hd__buf_4 gain13 (.A(_0409_),
    .X(net12));
 sky130_fd_sc_hd__buf_12 gain14 (.A(_0408_),
    .X(net13));
 sky130_fd_sc_hd__buf_12 gain15 (.A(_0407_),
    .X(net14));
 sky130_fd_sc_hd__buf_4 gain16 (.A(_0402_),
    .X(net15));
 sky130_fd_sc_hd__buf_12 gain17 (.A(_0941_),
    .X(net16));
 sky130_fd_sc_hd__buf_12 gain18 (.A(_0642_),
    .X(net17));
 sky130_fd_sc_hd__buf_12 gain19 (.A(_0641_),
    .X(net18));
 sky130_fd_sc_hd__buf_4 gain20 (.A(_0468_),
    .X(net19));
 sky130_fd_sc_hd__buf_2 gain21 (.A(_0442_),
    .X(net20));
 sky130_fd_sc_hd__buf_12 gain22 (.A(_0985_),
    .X(net21));
 sky130_fd_sc_hd__buf_12 gain23 (.A(_0025_),
    .X(net22));
 sky130_fd_sc_hd__buf_12 gain24 (.A(_0021_),
    .X(net23));
 sky130_fd_sc_hd__buf_12 gain25 (.A(_0591_),
    .X(net24));
 sky130_fd_sc_hd__buf_12 gain26 (.A(_0582_),
    .X(net25));
 sky130_fd_sc_hd__buf_12 gain27 (.A(_0435_),
    .X(net26));
 sky130_fd_sc_hd__buf_12 gain28 (.A(_0293_),
    .X(net27));
 sky130_fd_sc_hd__buf_12 gain29 (.A(_0588_),
    .X(net28));
 sky130_fd_sc_hd__buf_12 gain30 (.A(_0909_),
    .X(net29));
 sky130_fd_sc_hd__buf_12 gain31 (.A(_0707_),
    .X(net30));
 sky130_fd_sc_hd__buf_12 gain32 (.A(_0706_),
    .X(net31));
 sky130_fd_sc_hd__buf_12 gain33 (.A(net33),
    .X(net32));
 sky130_fd_sc_hd__buf_2 gain34 (.A(_0704_),
    .X(net33));
 sky130_fd_sc_hd__buf_12 gain35 (.A(u_uart_core_rx_fifo_data_0_),
    .X(net34));
 sky130_fd_sc_hd__buf_12 gain36 (.A(u_uart_core_rx_fifo_data_1_),
    .X(net35));
 sky130_fd_sc_hd__buf_12 gain37 (.A(u_uart_core_rx_fifo_data_2_),
    .X(net36));
 sky130_fd_sc_hd__buf_12 gain38 (.A(u_uart_core_rx_fifo_data_3_),
    .X(net37));
 sky130_fd_sc_hd__buf_12 gain39 (.A(u_uart_core_rx_fifo_data_4_),
    .X(net38));
 sky130_fd_sc_hd__buf_12 gain40 (.A(u_uart_core_rx_fifo_data_5_),
    .X(net39));
 sky130_fd_sc_hd__buf_12 gain41 (.A(u_uart_core_rx_fifo_data_6_),
    .X(net40));
 sky130_fd_sc_hd__buf_12 gain42 (.A(_0404_),
    .X(net41));
 sky130_fd_sc_hd__buf_12 gain43 (.A(_0369_),
    .X(net42));
 sky130_fd_sc_hd__buf_12 gain44 (.A(u_uart_core_rx_fifo_data_7_),
    .X(net43));
 sky130_fd_sc_hd__buf_12 gain45 (.A(_0935_),
    .X(net44));
 sky130_fd_sc_hd__buf_4 gain46 (.A(_0639_),
    .X(net45));
 sky130_fd_sc_hd__buf_12 gain47 (.A(_0446_),
    .X(net46));
 sky130_fd_sc_hd__buf_12 gain48 (.A(_1366_),
    .X(net47));
 sky130_fd_sc_hd__buf_2 gain49 (.A(core_rst_ni),
    .X(net48));
 sky130_fd_sc_hd__buf_12 gain50 (.A(net57),
    .X(net49));
 sky130_fd_sc_hd__buf_12 gain51 (.A(net57),
    .X(net50));
 sky130_fd_sc_hd__buf_12 gain52 (.A(net57),
    .X(net51));
 sky130_fd_sc_hd__buf_12 gain53 (.A(net57),
    .X(net52));
 sky130_fd_sc_hd__buf_12 gain54 (.A(net57),
    .X(net53));
 sky130_fd_sc_hd__buf_12 gain55 (.A(net57),
    .X(net54));
 sky130_fd_sc_hd__buf_12 gain56 (.A(net57),
    .X(net55));
 sky130_fd_sc_hd__buf_12 gain57 (.A(net58),
    .X(net56));
 sky130_fd_sc_hd__buf_12 gain58 (.A(net58),
    .X(net57));
 sky130_fd_sc_hd__buf_4 gain59 (.A(reg_rst_ni),
    .X(net58));
 sky130_fd_sc_hd__buf_2 gain60 (.A(u_uart_core_nco_sum_q_16_),
    .X(net59));
 sky130_fd_sc_hd__buf_2 gain61 (.A(u_uart_core_nco_sum_q_12_),
    .X(net60));
 sky130_fd_sc_hd__buf_12 gain62 (.A(net62),
    .X(net61));
 sky130_fd_sc_hd__buf_12 gain63 (.A(u_uart_core_rx_rst_ni),
    .X(net62));
 sky130_fd_sc_hd__buf_12 gain64 (.A(u_uart_core_timing_rst_ni),
    .X(net63));
 sky130_fd_sc_hd__buf_12 gain65 (.A(net65),
    .X(net64));
 sky130_fd_sc_hd__buf_12 gain66 (.A(u_uart_core_tx_rst_ni),
    .X(net65));
 sky130_fd_sc_hd__buf_4 gain67 (.A(reg2hw_12_),
    .X(net66));
 sky130_fd_sc_hd__buf_4 gain68 (.A(reg2hw_11_),
    .X(net67));
 sky130_fd_sc_hd__buf_4 gain69 (.A(reg2hw_10_),
    .X(net68));
 sky130_fd_sc_hd__buf_4 gain70 (.A(reg2hw_9_),
    .X(net69));
 sky130_fd_sc_hd__buf_4 gain71 (.A(reg2hw_8_),
    .X(net70));
 sky130_fd_sc_hd__buf_4 gain72 (.A(reg2hw_7_),
    .X(net71));
 sky130_fd_sc_hd__buf_4 gain73 (.A(reg2hw_6_),
    .X(net72));
 sky130_fd_sc_hd__buf_4 gain74 (.A(reg2hw_5_),
    .X(net73));
 sky130_fd_sc_hd__buf_2 gain75 (.A(reg2hw_34_),
    .X(net74));
 sky130_fd_sc_hd__buf_2 gain76 (.A(reg2hw_40_),
    .X(net75));
 sky130_fd_sc_hd__buf_12 gain77 (.A(reg2hw_39_),
    .X(net76));
 sky130_fd_sc_hd__buf_2 gain78 (.A(reg2hw_56_),
    .X(net77));
 sky130_fd_sc_hd__buf_2 gain79 (.A(reg2hw_53_),
    .X(net78));
 sky130_fd_sc_hd__buf_2 gain80 (.A(reg2hw_51_),
    .X(net79));
 sky130_fd_sc_hd__buf_2 gain81 (.A(reg2hw_47_),
    .X(net80));
 sky130_fd_sc_hd__buf_2 gain82 (.A(reg2hw_45_),
    .X(net81));
 sky130_fd_sc_hd__buf_2 gain83 (.A(reg2hw_41_),
    .X(net82));
 sky130_fd_sc_hd__buf_2 gain84 (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_resp_status_cnt_q_0_),
    .X(net83));
 sky130_fd_sc_hd__buf_2 gain85 (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_status_cnt_q_1_),
    .X(net84));
 sky130_fd_sc_hd__buf_12 gain86 (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_write_req_read_pointer_q),
    .X(net85));
 sky130_fd_sc_hd__buf_2 gain87 (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_write_pointer_q),
    .X(net86));
 sky130_fd_sc_hd__buf_2 gain88 (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_status_cnt_q_0_),
    .X(net87));
 sky130_fd_sc_hd__buf_12 gain89 (.A(net89),
    .X(net88));
 sky130_fd_sc_hd__buf_12 gain90 (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_resp_read_pointer_q),
    .X(net89));
 sky130_fd_sc_hd__buf_4 gain91 (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_status_cnt_q_1_),
    .X(net90));
 sky130_fd_sc_hd__buf_2 gain92 (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_status_cnt_q_0_),
    .X(net91));
 sky130_fd_sc_hd__buf_4 gain93 (.A(u_uart_reg_u_flexsoc_axi_to_reg_i_fifo_read_read_pointer_q),
    .X(net92));
 sky130_fd_sc_hd__buf_2 gain94 (.A(u_uart_core_uart_rx_sreg_q_8_),
    .X(net93));
 sky130_fd_sc_hd__buf_2 gain95 (.A(u_uart_core_uart_rx_sreg_q_7_),
    .X(net94));
 sky130_fd_sc_hd__buf_2 gain96 (.A(u_uart_core_uart_rx_sreg_q_6_),
    .X(net95));
 sky130_fd_sc_hd__buf_2 gain97 (.A(u_uart_core_uart_rx_sreg_q_5_),
    .X(net96));
 sky130_fd_sc_hd__buf_2 gain98 (.A(u_uart_core_uart_rx_sreg_q_4_),
    .X(net97));
 sky130_fd_sc_hd__buf_2 gain99 (.A(u_uart_core_uart_rx_sreg_q_3_),
    .X(net98));
endmodule
