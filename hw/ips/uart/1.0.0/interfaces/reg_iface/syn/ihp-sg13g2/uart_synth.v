module uart (clk_i,
    rst_ni,
    rx_i,
    tx_o,
    reg_req_i,
    reg_rsp_o);
 input clk_i;
 input rst_ni;
 input rx_i;
 output tx_o;
 input [42:0] reg_req_i;
 output [33:0] reg_rsp_o;

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
 wire net200;
 wire core_rst_ni;
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
 wire u_uart_reg_reg_rsp_o_10_;
 wire u_uart_reg_reg_rsp_o_18_;
 wire u_uart_reg_reg_rsp_o_19_;
 wire u_uart_reg_reg_rsp_o_1_;
 wire u_uart_reg_reg_rsp_o_20_;
 wire u_uart_reg_reg_rsp_o_21_;
 wire u_uart_reg_reg_rsp_o_22_;
 wire u_uart_reg_reg_rsp_o_23_;
 wire u_uart_reg_reg_rsp_o_24_;
 wire u_uart_reg_reg_rsp_o_25_;
 wire u_uart_reg_reg_rsp_o_26_;
 wire u_uart_reg_reg_rsp_o_27_;
 wire u_uart_reg_reg_rsp_o_28_;
 wire u_uart_reg_reg_rsp_o_29_;
 wire u_uart_reg_reg_rsp_o_2_;
 wire u_uart_reg_reg_rsp_o_30_;
 wire u_uart_reg_reg_rsp_o_31_;
 wire u_uart_reg_reg_rsp_o_32_;
 wire u_uart_reg_reg_rsp_o_33_;
 wire u_uart_reg_reg_rsp_o_3_;
 wire u_uart_reg_reg_rsp_o_4_;
 wire u_uart_reg_reg_rsp_o_5_;
 wire u_uart_reg_reg_rsp_o_6_;
 wire u_uart_reg_reg_rsp_o_7_;
 wire u_uart_reg_reg_rsp_o_8_;
 wire u_uart_reg_reg_rsp_o_9_;
 wire u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_;
 wire u_uart_reg_u_reg_core_reg_we_check_3_;
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
 wire net191;
 wire net192;
 wire net193;
 wire net194;
 wire net195;
 wire net196;
 wire net197;
 wire net198;
 wire net199;
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
 wire net211;
 wire net212;
 wire net213;
 wire net214;
 wire net215;
 wire net216;
 wire net217;
 wire net218;
 wire net219;
 wire net220;
 wire net221;
 wire net222;
 wire net223;
 wire net224;
 wire net225;
 wire net226;
 wire net227;
 wire net228;
 wire net229;
 wire net230;
 wire net231;
 wire net232;
 wire net233;
 wire net234;
 wire net235;
 wire net236;
 wire net237;
 wire net238;
 wire net239;
 wire net240;
 wire net241;
 wire net242;
 wire net243;
 wire net244;
 wire net245;
 wire net246;
 wire net247;
 wire net248;
 wire net249;
 wire net250;
 wire net251;
 wire net252;
 wire net253;
 wire net254;
 wire net255;
 wire net256;
 wire net257;
 wire net258;
 wire net259;
 wire net260;
 wire net261;
 wire net262;
 wire net263;
 wire net264;
 wire net265;
 wire net266;
 wire net267;
 wire net268;
 wire net269;
 wire net270;
 wire net271;
 wire net272;
 wire net273;
 wire net274;
 wire net275;
 wire net276;
 wire net277;
 wire net278;
 wire net279;
 wire net280;
 wire net281;
 wire net282;
 wire net283;
 wire net284;
 wire net285;
 wire net286;
 wire net287;
 wire net288;
 wire net289;
 wire net290;
 wire net291;
 wire net292;
 wire net293;
 wire net294;
 wire net295;
 wire net296;
 wire net297;
 wire net298;
 wire net299;
 wire net300;
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
 wire net368;
 wire net369;
 wire net370;
 wire net371;
 wire net372;
 wire net373;
 wire net374;
 wire net375;
 wire net376;
 wire net377;
 wire net378;
 wire net379;
 wire net380;
 wire net381;
 wire net382;
 wire net383;
 wire net384;
 wire net385;
 wire net386;
 wire net387;

 sg13g2_inv_1 _1352_ (.Y(_1087_),
    .A(_0047_));
 sg13g2_nor2_1 _1353_ (.A(reg2hw_37_),
    .B(_1087_),
    .Y(_0052_));
 sg13g2_buf_1 _1354_ (.A(_0041_),
    .X(_0051_));
 sg13g2_inv_1 _1355_ (.Y(_0050_),
    .A(rx_i));
 sg13g2_buf_1 _1356_ (.A(_0039_),
    .X(_0049_));
 sg13g2_buf_1 _1357_ (.A(_0042_),
    .X(_0048_));
 sg13g2_xnor2_1 _1358_ (.Y(_0002_),
    .A(_0028_),
    .B(u_uart_core_nco_sum_q_0_));
 sg13g2_nor2_1 _1359_ (.A(reg_req_i[36]),
    .B(reg_req_i[37]),
    .Y(_1088_));
 sg13g2_inv_1 _1360_ (.Y(_1089_),
    .A(reg_req_i[39]));
 sg13g2_nand2_1 _1361_ (.Y(_1090_),
    .A(_1088_),
    .B(_1089_));
 sg13g2_nor3_1 _1362_ (.A(reg_req_i[40]),
    .B(reg_req_i[38]),
    .C(_1090_),
    .Y(_1091_));
 sg13g2_buf_4 _1363_ (.X(_1092_),
    .A(_1091_));
 sg13g2_inv_4 _1364_ (.A(_1092_),
    .Y(_1093_));
 sg13g2_inv_2 _1365_ (.Y(_1094_),
    .A(_1090_));
 sg13g2_inv_1 _1366_ (.Y(_1095_),
    .A(reg_req_i[40]));
 sg13g2_nand3_1 _1367_ (.B(_1095_),
    .C(reg_req_i[39]),
    .A(_1088_),
    .Y(_1096_));
 sg13g2_inv_1 _1368_ (.Y(_1097_),
    .A(_1096_));
 sg13g2_nor2_1 _1369_ (.A(_1094_),
    .B(_1097_),
    .Y(_1098_));
 sg13g2_buf_1 _1370_ (.A(_1098_),
    .X(u_uart_reg_reg_rsp_o_10_));
 sg13g2_inv_1 _1371_ (.Y(_1099_),
    .A(u_uart_reg_reg_rsp_o_10_));
 sg13g2_o21ai_1 _1372_ (.B1(net263),
    .Y(u_uart_reg_reg_rsp_o_32_),
    .A1(net386),
    .A2(net287));
 sg13g2_inv_2 _1373_ (.Y(_1100_),
    .A(reg2hw_54_));
 sg13g2_o21ai_1 _1374_ (.B1(net263),
    .Y(u_uart_reg_reg_rsp_o_31_),
    .A1(_1100_),
    .A2(net287));
 sg13g2_inv_1 _1375_ (.Y(_1101_),
    .A(reg2hw_53_));
 sg13g2_o21ai_1 _1376_ (.B1(net263),
    .Y(u_uart_reg_reg_rsp_o_30_),
    .A1(_1101_),
    .A2(net287));
 sg13g2_nor2_1 _1377_ (.A(reg2hw_56_),
    .B(u_uart_core_nco_sum_q_15_),
    .Y(_1102_));
 sg13g2_nand2_1 _1378_ (.Y(_1103_),
    .A(reg2hw_56_),
    .B(u_uart_core_nco_sum_q_15_));
 sg13g2_nor2b_1 _1379_ (.A(_1102_),
    .B_N(_1103_),
    .Y(_1104_));
 sg13g2_inv_1 _1380_ (.Y(_1105_),
    .A(u_uart_core_nco_sum_q_13_));
 sg13g2_nor2_1 _1381_ (.A(_1100_),
    .B(_1105_),
    .Y(_1106_));
 sg13g2_nand2_1 _1382_ (.Y(_1107_),
    .A(_1100_),
    .B(_1105_));
 sg13g2_nor2b_1 _1383_ (.A(_1106_),
    .B_N(_1107_),
    .Y(_1108_));
 sg13g2_xor2_1 _1384_ (.B(u_uart_core_nco_sum_q_12_),
    .A(reg2hw_53_),
    .X(_1109_));
 sg13g2_nand2_1 _1385_ (.Y(_1110_),
    .A(_1108_),
    .B(_1109_));
 sg13g2_inv_1 _1386_ (.Y(_1111_),
    .A(_0023_));
 sg13g2_nor2_1 _1387_ (.A(u_uart_core_nco_sum_q_5_),
    .B(_1111_),
    .Y(_1112_));
 sg13g2_inv_1 _1388_ (.Y(_1113_),
    .A(_0024_));
 sg13g2_inv_1 _1389_ (.Y(_1114_),
    .A(_0026_));
 sg13g2_nor2b_1 _1390_ (.A(_0027_),
    .B_N(u_uart_core_nco_sum_q_1_),
    .Y(_1115_));
 sg13g2_inv_1 _1391_ (.Y(_1116_),
    .A(_0027_));
 sg13g2_nor2_1 _1392_ (.A(u_uart_core_nco_sum_q_1_),
    .B(_1116_),
    .Y(_1117_));
 sg13g2_nor2_1 _1393_ (.A(_1115_),
    .B(_1117_),
    .Y(_1118_));
 sg13g2_inv_1 _1394_ (.Y(_1119_),
    .A(_0028_));
 sg13g2_nand2_1 _1395_ (.Y(_1120_),
    .A(_1119_),
    .B(u_uart_core_nco_sum_q_0_));
 sg13g2_inv_1 _1396_ (.Y(_1121_),
    .A(_1120_));
 sg13g2_a21oi_1 _1397_ (.A1(_1118_),
    .A2(_1121_),
    .Y(_1122_),
    .B1(_1115_));
 sg13g2_xnor2_1 _1398_ (.Y(_1123_),
    .A(_0026_),
    .B(u_uart_core_nco_sum_q_2_));
 sg13g2_nor2b_1 _1399_ (.A(_1122_),
    .B_N(_1123_),
    .Y(_1124_));
 sg13g2_a21o_1 _1400_ (.A2(u_uart_core_nco_sum_q_2_),
    .A1(_1114_),
    .B1(_1124_),
    .X(_1125_));
 sg13g2_inv_1 _1401_ (.Y(_1126_),
    .A(u_uart_core_nco_sum_q_3_));
 sg13g2_nand2_1 _1402_ (.Y(_1127_),
    .A(_1126_),
    .B(_0025_));
 sg13g2_nor2_1 _1403_ (.A(_0025_),
    .B(_1126_),
    .Y(_1128_));
 sg13g2_a21oi_1 _1404_ (.A1(_1125_),
    .A2(_1127_),
    .Y(_1129_),
    .B1(_1128_));
 sg13g2_xnor2_1 _1405_ (.Y(_1130_),
    .A(_0024_),
    .B(u_uart_core_nco_sum_q_4_));
 sg13g2_nor2b_1 _1406_ (.A(_1129_),
    .B_N(_1130_),
    .Y(_1131_));
 sg13g2_a21oi_1 _1407_ (.A1(_1113_),
    .A2(u_uart_core_nco_sum_q_4_),
    .Y(_1132_),
    .B1(_1131_));
 sg13g2_nand2_1 _1408_ (.Y(_1133_),
    .A(_1111_),
    .B(u_uart_core_nco_sum_q_5_));
 sg13g2_o21ai_1 _1409_ (.B1(_1133_),
    .Y(_1134_),
    .A1(_1112_),
    .A2(_1132_));
 sg13g2_nor2_1 _1410_ (.A(reg2hw_48_),
    .B(u_uart_core_nco_sum_q_7_),
    .Y(_1135_));
 sg13g2_inv_1 _1411_ (.Y(_1136_),
    .A(reg2hw_48_));
 sg13g2_nor2b_1 _1412_ (.A(_1136_),
    .B_N(u_uart_core_nco_sum_q_7_),
    .Y(_1137_));
 sg13g2_nor2_1 _1413_ (.A(_1135_),
    .B(_1137_),
    .Y(_1138_));
 sg13g2_xnor2_1 _1414_ (.Y(_1139_),
    .A(_0022_),
    .B(u_uart_core_nco_sum_q_6_));
 sg13g2_nand3_1 _1415_ (.B(_1138_),
    .C(_1139_),
    .A(_1134_),
    .Y(_1140_));
 sg13g2_inv_1 _1416_ (.Y(_1141_),
    .A(_0022_));
 sg13g2_nand2_1 _1417_ (.Y(_1142_),
    .A(_1141_),
    .B(u_uart_core_nco_sum_q_6_));
 sg13g2_inv_1 _1418_ (.Y(_1143_),
    .A(_1142_));
 sg13g2_inv_1 _1419_ (.Y(_1144_),
    .A(_1135_));
 sg13g2_a21oi_1 _1420_ (.A1(_1143_),
    .A2(_1144_),
    .Y(_1145_),
    .B1(_1137_));
 sg13g2_nand2_2 _1421_ (.Y(_1146_),
    .A(_1140_),
    .B(_1145_));
 sg13g2_inv_1 _1422_ (.Y(_1147_),
    .A(u_uart_core_nco_sum_q_11_));
 sg13g2_nor2_1 _1423_ (.A(_0019_),
    .B(_1147_),
    .Y(_1148_));
 sg13g2_nand2_1 _1424_ (.Y(_1149_),
    .A(_1147_),
    .B(_0019_));
 sg13g2_nor2b_2 _1425_ (.A(_1148_),
    .B_N(_1149_),
    .Y(_1150_));
 sg13g2_xor2_1 _1426_ (.B(u_uart_core_nco_sum_q_10_),
    .A(reg2hw_51_),
    .X(_1151_));
 sg13g2_nor2b_1 _1427_ (.A(_0020_),
    .B_N(u_uart_core_nco_sum_q_9_),
    .Y(_1152_));
 sg13g2_inv_1 _1428_ (.Y(_1153_),
    .A(_0020_));
 sg13g2_nor2_1 _1429_ (.A(u_uart_core_nco_sum_q_9_),
    .B(_1153_),
    .Y(_1154_));
 sg13g2_xnor2_1 _1430_ (.Y(_1155_),
    .A(_0021_),
    .B(u_uart_core_nco_sum_q_8_));
 sg13g2_inv_1 _1431_ (.Y(_1156_),
    .A(_1155_));
 sg13g2_nor3_1 _1432_ (.A(_1152_),
    .B(_1154_),
    .C(_1156_),
    .Y(_1157_));
 sg13g2_nand4_1 _1433_ (.B(_1150_),
    .C(_1151_),
    .A(_1146_),
    .Y(_1158_),
    .D(_1157_));
 sg13g2_inv_1 _1434_ (.Y(_1159_),
    .A(_1154_));
 sg13g2_inv_1 _1435_ (.Y(_1160_),
    .A(_0021_));
 sg13g2_nand2_1 _1436_ (.Y(_1161_),
    .A(_1160_),
    .B(u_uart_core_nco_sum_q_8_));
 sg13g2_inv_1 _1437_ (.Y(_1162_),
    .A(_1161_));
 sg13g2_a21oi_1 _1438_ (.A1(_1159_),
    .A2(_1162_),
    .Y(_1163_),
    .B1(_1152_));
 sg13g2_inv_1 _1439_ (.Y(_1164_),
    .A(_1163_));
 sg13g2_nand3_1 _1440_ (.B(_1150_),
    .C(_1151_),
    .A(_1164_),
    .Y(_1165_));
 sg13g2_inv_1 _1441_ (.Y(_1166_),
    .A(reg2hw_51_));
 sg13g2_nor2b_1 _1442_ (.A(_1166_),
    .B_N(u_uart_core_nco_sum_q_10_),
    .Y(_1167_));
 sg13g2_a21oi_1 _1443_ (.A1(_1167_),
    .A2(_1149_),
    .Y(_1168_),
    .B1(_1148_));
 sg13g2_and3_1 _1444_ (.X(_1169_),
    .A(_1158_),
    .B(_1165_),
    .C(_1168_));
 sg13g2_nor2b_1 _1445_ (.A(_1101_),
    .B_N(u_uart_core_nco_sum_q_12_),
    .Y(_1170_));
 sg13g2_o21ai_1 _1446_ (.B1(_1107_),
    .Y(_1171_),
    .A1(_1170_),
    .A2(_1106_));
 sg13g2_o21ai_1 _1447_ (.B1(_1171_),
    .Y(_1172_),
    .A1(_1110_),
    .A2(net204));
 sg13g2_xnor2_1 _1448_ (.Y(_1173_),
    .A(net386),
    .B(u_uart_core_nco_sum_q_14_));
 sg13g2_nor2b_1 _1449_ (.A(net386),
    .B_N(u_uart_core_nco_sum_q_14_),
    .Y(_1174_));
 sg13g2_a21oi_1 _1450_ (.A1(_1172_),
    .A2(_1173_),
    .Y(_1175_),
    .B1(_1174_));
 sg13g2_xnor2_1 _1451_ (.Y(_0008_),
    .A(_1104_),
    .B(_1175_));
 sg13g2_o21ai_1 _1452_ (.B1(net263),
    .Y(u_uart_reg_reg_rsp_o_29_),
    .A1(_0019_),
    .A2(net287));
 sg13g2_nor2b_1 _1453_ (.A(net204),
    .B_N(_1109_),
    .Y(_1176_));
 sg13g2_nor2_1 _1454_ (.A(_1170_),
    .B(_1176_),
    .Y(_1177_));
 sg13g2_xnor2_1 _1455_ (.Y(_0006_),
    .A(_1108_),
    .B(_1177_));
 sg13g2_xor2_1 _1456_ (.B(_1172_),
    .A(_1173_),
    .X(_0007_));
 sg13g2_o21ai_1 _1457_ (.B1(net263),
    .Y(u_uart_reg_reg_rsp_o_28_),
    .A1(_1166_),
    .A2(net287));
 sg13g2_a21oi_1 _1458_ (.A1(_1146_),
    .A2(_1157_),
    .Y(_1178_),
    .B1(_1164_));
 sg13g2_nor2b_1 _1459_ (.A(_1178_),
    .B_N(_1151_),
    .Y(_1179_));
 sg13g2_nor2_1 _1460_ (.A(_1167_),
    .B(_1179_),
    .Y(_1180_));
 sg13g2_xnor2_1 _1461_ (.Y(_0004_),
    .A(_1150_),
    .B(_1180_));
 sg13g2_xnor2_1 _1462_ (.Y(_0005_),
    .A(_1109_),
    .B(net204));
 sg13g2_o21ai_1 _1463_ (.B1(net263),
    .Y(u_uart_reg_reg_rsp_o_27_),
    .A1(_0020_),
    .A2(net287));
 sg13g2_nor2_1 _1464_ (.A(_1152_),
    .B(_1154_),
    .Y(_1181_));
 sg13g2_a21oi_1 _1465_ (.A1(_1146_),
    .A2(_1155_),
    .Y(_1182_),
    .B1(_1162_));
 sg13g2_xnor2_1 _1466_ (.Y(_0017_),
    .A(_1181_),
    .B(_1182_));
 sg13g2_xnor2_1 _1467_ (.Y(_0003_),
    .A(_1151_),
    .B(_1178_));
 sg13g2_o21ai_1 _1468_ (.B1(net263),
    .Y(u_uart_reg_reg_rsp_o_26_),
    .A1(_0021_),
    .A2(net287));
 sg13g2_a21oi_1 _1469_ (.A1(_1134_),
    .A2(_1139_),
    .Y(_1183_),
    .B1(_1143_));
 sg13g2_xnor2_1 _1470_ (.Y(_0015_),
    .A(_1138_),
    .B(_1183_));
 sg13g2_xnor2_1 _1471_ (.Y(_0016_),
    .A(_1156_),
    .B(_1146_));
 sg13g2_nand2b_1 _1472_ (.Y(_1184_),
    .B(_1127_),
    .A_N(_1128_));
 sg13g2_xnor2_1 _1473_ (.Y(_0011_),
    .A(_1184_),
    .B(_1125_));
 sg13g2_nor2b_1 _1474_ (.A(_1112_),
    .B_N(_1133_),
    .Y(_1185_));
 sg13g2_xnor2_1 _1475_ (.Y(_0013_),
    .A(_1185_),
    .B(_1132_));
 sg13g2_xnor2_1 _1476_ (.Y(_0012_),
    .A(_1130_),
    .B(_1129_));
 sg13g2_xor2_1 _1477_ (.B(_1134_),
    .A(_1139_),
    .X(_0014_));
 sg13g2_o21ai_1 _1478_ (.B1(net264),
    .Y(u_uart_reg_reg_rsp_o_24_),
    .A1(_0022_),
    .A2(_1093_));
 sg13g2_xnor2_1 _1479_ (.Y(_0009_),
    .A(_1120_),
    .B(_1118_));
 sg13g2_xnor2_1 _1480_ (.Y(_0010_),
    .A(_1123_),
    .B(_1122_));
 sg13g2_o21ai_1 _1481_ (.B1(net264),
    .Y(u_uart_reg_reg_rsp_o_23_),
    .A1(_0023_),
    .A2(_1093_));
 sg13g2_inv_1 _1482_ (.Y(_1186_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_));
 sg13g2_nor2_1 _1483_ (.A(net341),
    .B(_1186_),
    .Y(_1187_));
 sg13g2_xnor2_1 _1484_ (.Y(_1188_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_));
 sg13g2_xnor2_1 _1485_ (.Y(_1189_),
    .A(net346),
    .B(net338));
 sg13g2_inv_1 _1486_ (.Y(_1190_),
    .A(_1189_));
 sg13g2_xnor2_1 _1487_ (.Y(_1191_),
    .A(net344),
    .B(net337));
 sg13g2_inv_2 _1488_ (.Y(_1192_),
    .A(_1191_));
 sg13g2_xnor2_1 _1489_ (.Y(_1193_),
    .A(net353),
    .B(net339));
 sg13g2_inv_1 _1490_ (.Y(_1194_),
    .A(_1193_));
 sg13g2_inv_2 _1491_ (.Y(_1195_),
    .A(net341));
 sg13g2_nor2_1 _1492_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_),
    .B(_1195_),
    .Y(_1196_));
 sg13g2_nor2_1 _1493_ (.A(_1187_),
    .B(_1196_),
    .Y(_1197_));
 sg13g2_inv_1 _1494_ (.Y(_1198_),
    .A(_1197_));
 sg13g2_nor4_1 _1495_ (.A(_1190_),
    .B(_1192_),
    .C(_1194_),
    .D(_1198_),
    .Y(_1199_));
 sg13g2_inv_1 _1496_ (.Y(_1200_),
    .A(net344));
 sg13g2_inv_1 _1497_ (.Y(_1201_),
    .A(net346));
 sg13g2_buf_1 _1498_ (.A(_1201_),
    .X(_1202_));
 sg13g2_inv_1 _1499_ (.Y(_1203_),
    .A(net339));
 sg13g2_a21oi_1 _1500_ (.A1(net352),
    .A2(_1203_),
    .Y(_1204_),
    .B1(_1190_));
 sg13g2_a21oi_1 _1501_ (.A1(net297),
    .A2(net338),
    .Y(_1205_),
    .B1(_1204_));
 sg13g2_nor2_1 _1502_ (.A(_1192_),
    .B(_1205_),
    .Y(_1206_));
 sg13g2_a21oi_1 _1503_ (.A1(net303),
    .A2(net337),
    .Y(_1207_),
    .B1(_1206_));
 sg13g2_nor2_1 _1504_ (.A(_1196_),
    .B(_1207_),
    .Y(_1208_));
 sg13g2_nor4_1 _1505_ (.A(_1187_),
    .B(_1188_),
    .C(_1199_),
    .D(_1208_),
    .Y(_1209_));
 sg13g2_inv_1 _1506_ (.Y(_1210_),
    .A(_1188_));
 sg13g2_nor2_1 _1507_ (.A(_1187_),
    .B(_1208_),
    .Y(_1211_));
 sg13g2_nand3_1 _1508_ (.B(reg_req_i[40]),
    .C(reg_req_i[38]),
    .A(_1094_),
    .Y(_1212_));
 sg13g2_inv_2 _1509_ (.Y(_1213_),
    .A(net288));
 sg13g2_o21ai_1 _1510_ (.B1(_1213_),
    .Y(_1214_),
    .A1(_1210_),
    .A2(_1211_));
 sg13g2_a21oi_1 _1511_ (.A1(net289),
    .A2(_1113_),
    .Y(_1215_),
    .B1(net286));
 sg13g2_o21ai_1 _1512_ (.B1(_1215_),
    .Y(u_uart_reg_reg_rsp_o_22_),
    .A1(_1209_),
    .A2(_1214_));
 sg13g2_nand2_1 _1513_ (.Y(_1216_),
    .A(_1199_),
    .B(_1210_));
 sg13g2_nand2_1 _1514_ (.Y(_1217_),
    .A(_1216_),
    .B(_1213_));
 sg13g2_xnor2_1 _1515_ (.Y(_1218_),
    .A(_1198_),
    .B(_1207_));
 sg13g2_inv_1 _1516_ (.Y(_1219_),
    .A(_0025_));
 sg13g2_a21oi_1 _1517_ (.A1(net289),
    .A2(_1219_),
    .Y(_1220_),
    .B1(net286));
 sg13g2_o21ai_1 _1518_ (.B1(_1220_),
    .Y(u_uart_reg_reg_rsp_o_21_),
    .A1(_1217_),
    .A2(_1218_));
 sg13g2_xnor2_1 _1519_ (.Y(_1221_),
    .A(_1192_),
    .B(_1205_));
 sg13g2_a21oi_1 _1520_ (.A1(net289),
    .A2(_1114_),
    .Y(_1222_),
    .B1(net286));
 sg13g2_o21ai_1 _1521_ (.B1(_1222_),
    .Y(u_uart_reg_reg_rsp_o_20_),
    .A1(_1217_),
    .A2(_1221_));
 sg13g2_inv_1 _1522_ (.Y(_1223_),
    .A(net353));
 sg13g2_buf_1 _1523_ (.A(_1223_),
    .X(_1224_));
 sg13g2_nor3_1 _1524_ (.A(net291),
    .B(net339),
    .C(_1189_),
    .Y(_1225_));
 sg13g2_nor3_1 _1525_ (.A(_1204_),
    .B(_1225_),
    .C(_1217_),
    .Y(_1226_));
 sg13g2_nor2_1 _1526_ (.A(net286),
    .B(_1226_),
    .Y(_1227_));
 sg13g2_o21ai_1 _1527_ (.B1(_1227_),
    .Y(u_uart_reg_reg_rsp_o_19_),
    .A1(_0027_),
    .A2(_1093_));
 sg13g2_a21oi_1 _1528_ (.A1(net289),
    .A2(_1119_),
    .Y(_1228_),
    .B1(net286));
 sg13g2_o21ai_1 _1529_ (.B1(_1228_),
    .Y(u_uart_reg_reg_rsp_o_18_),
    .A1(_1193_),
    .A2(net288));
 sg13g2_inv_1 _1530_ (.Y(_1229_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_78_));
 sg13g2_o21ai_1 _1531_ (.B1(net296),
    .Y(_1230_),
    .A1(net349),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_70_));
 sg13g2_a21oi_1 _1532_ (.A1(net348),
    .A2(_1229_),
    .Y(_1231_),
    .B1(_1230_));
 sg13g2_nor2_1 _1533_ (.A(net353),
    .B(_1202_),
    .Y(_1232_));
 sg13g2_buf_1 _1534_ (.A(_1232_),
    .X(_1233_));
 sg13g2_inv_1 _1535_ (.Y(_1234_),
    .A(_1233_));
 sg13g2_nor2b_1 _1536_ (.A(net261),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_86_),
    .Y(_1235_));
 sg13g2_nor2_1 _1537_ (.A(_1202_),
    .B(net294),
    .Y(_1236_));
 sg13g2_buf_1 _1538_ (.A(_1236_),
    .X(_1237_));
 sg13g2_inv_2 _1539_ (.Y(_1238_),
    .A(_1237_));
 sg13g2_nor2b_1 _1540_ (.A(net259),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_94_),
    .Y(_1239_));
 sg13g2_nor4_1 _1541_ (.A(net342),
    .B(_1231_),
    .C(_1235_),
    .D(_1239_),
    .Y(_1240_));
 sg13g2_inv_1 _1542_ (.Y(_1241_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_102_));
 sg13g2_o21ai_1 _1543_ (.B1(net295),
    .Y(_1242_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_110_),
    .A2(net293));
 sg13g2_a21oi_1 _1544_ (.A1(net291),
    .A2(_1241_),
    .Y(_1243_),
    .B1(_1242_));
 sg13g2_nor2b_1 _1545_ (.A(net260),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_126_),
    .Y(_1244_));
 sg13g2_nor2b_1 _1546_ (.A(net261),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_118_),
    .Y(_1245_));
 sg13g2_nor4_1 _1547_ (.A(net302),
    .B(_1243_),
    .C(_1244_),
    .D(_1245_),
    .Y(_1246_));
 sg13g2_o21ai_1 _1548_ (.B1(net340),
    .Y(_1247_),
    .A1(_1240_),
    .A2(_1246_));
 sg13g2_nand2b_1 _1549_ (.Y(_1248_),
    .B(net291),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_38_));
 sg13g2_inv_1 _1550_ (.Y(_1249_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_46_));
 sg13g2_a21oi_1 _1551_ (.A1(_1249_),
    .A2(net348),
    .Y(_1250_),
    .B1(net345));
 sg13g2_a21o_1 _1552_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_54_),
    .A1(net283),
    .B1(net303),
    .X(_1251_));
 sg13g2_a221oi_1 _1553_ (.B2(_1250_),
    .C1(_1251_),
    .B1(_1248_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_62_),
    .Y(_1252_),
    .A2(net281));
 sg13g2_inv_1 _1554_ (.Y(_1253_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_14_));
 sg13g2_o21ai_1 _1555_ (.B1(net295),
    .Y(_1254_),
    .A1(net350),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_6_));
 sg13g2_a21oi_1 _1556_ (.A1(net348),
    .A2(_1253_),
    .Y(_1255_),
    .B1(_1254_));
 sg13g2_nor2b_1 _1557_ (.A(net261),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_22_),
    .Y(_1256_));
 sg13g2_nor2b_1 _1558_ (.A(net259),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_30_),
    .Y(_1257_));
 sg13g2_nor4_1 _1559_ (.A(net342),
    .B(_1255_),
    .C(_1256_),
    .D(_1257_),
    .Y(_1258_));
 sg13g2_o21ai_1 _1560_ (.B1(net304),
    .Y(_1259_),
    .A1(_1252_),
    .A2(_1258_));
 sg13g2_inv_1 _1561_ (.Y(_1260_),
    .A(reg_req_i[38]));
 sg13g2_nand2_1 _1562_ (.Y(_1261_),
    .A(_1097_),
    .B(_1260_));
 sg13g2_a21oi_1 _1563_ (.A1(_1199_),
    .A2(_1188_),
    .Y(_1262_),
    .B1(_1261_));
 sg13g2_nand3_1 _1564_ (.B(_1259_),
    .C(net258),
    .A(_1247_),
    .Y(_1263_));
 sg13g2_a21oi_1 _1565_ (.A1(net289),
    .A2(net385),
    .Y(_1264_),
    .B1(net286));
 sg13g2_nand2_1 _1566_ (.Y(u_uart_reg_reg_rsp_o_8_),
    .A(_1263_),
    .B(_1264_));
 sg13g2_inv_1 _1567_ (.Y(_1265_),
    .A(net321));
 sg13g2_nor2_1 _1568_ (.A(net317),
    .B(_1265_),
    .Y(_1266_));
 sg13g2_inv_2 _1569_ (.Y(_1267_),
    .A(net317));
 sg13g2_nor2_1 _1570_ (.A(net321),
    .B(_1267_),
    .Y(_1268_));
 sg13g2_nor2_1 _1571_ (.A(_1266_),
    .B(_1268_),
    .Y(_1269_));
 sg13g2_xnor2_1 _1572_ (.Y(_1270_),
    .A(net318),
    .B(net324));
 sg13g2_xnor2_1 _1573_ (.Y(_1271_),
    .A(net319),
    .B(net334));
 sg13g2_nand3_1 _1574_ (.B(_1270_),
    .C(_1271_),
    .A(_1269_),
    .Y(_1272_));
 sg13g2_xnor2_1 _1575_ (.Y(_1273_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_));
 sg13g2_inv_2 _1576_ (.Y(_1274_),
    .A(_1273_));
 sg13g2_nand2b_1 _1577_ (.Y(_1275_),
    .B(_1274_),
    .A_N(_1272_));
 sg13g2_nand2_1 _1578_ (.Y(_1276_),
    .A(_1275_),
    .B(_0045_));
 sg13g2_nand3_1 _1579_ (.B(_1095_),
    .C(reg_req_i[38]),
    .A(_1094_),
    .Y(_1277_));
 sg13g2_inv_2 _1580_ (.Y(_1278_),
    .A(_1277_));
 sg13g2_o21ai_1 _1581_ (.B1(_1099_),
    .Y(_1279_),
    .A1(net288),
    .A2(_1271_));
 sg13g2_a221oi_1 _1582_ (.B2(_1278_),
    .C1(_1279_),
    .B1(_1276_),
    .A1(net382),
    .Y(_1280_),
    .A2(_1092_));
 sg13g2_inv_1 _1583_ (.Y(_1281_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_104_));
 sg13g2_o21ai_1 _1584_ (.B1(net296),
    .Y(_1282_),
    .A1(net350),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_96_));
 sg13g2_a21oi_1 _1585_ (.A1(net348),
    .A2(_1281_),
    .Y(_1283_),
    .B1(_1282_));
 sg13g2_nor2b_1 _1586_ (.A(net261),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_112_),
    .Y(_1284_));
 sg13g2_nor2b_1 _1587_ (.A(net259),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_120_),
    .Y(_1285_));
 sg13g2_nor4_1 _1588_ (.A(net302),
    .B(_1283_),
    .C(_1284_),
    .D(_1285_),
    .Y(_1286_));
 sg13g2_inv_1 _1589_ (.Y(_1287_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_64_));
 sg13g2_o21ai_1 _1590_ (.B1(net295),
    .Y(_1288_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_72_),
    .A2(net293));
 sg13g2_a21oi_1 _1591_ (.A1(net292),
    .A2(_1287_),
    .Y(_1289_),
    .B1(_1288_));
 sg13g2_nor2b_1 _1592_ (.A(net261),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_80_),
    .Y(_1290_));
 sg13g2_nor2b_1 _1593_ (.A(net259),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_88_),
    .Y(_1291_));
 sg13g2_nor4_1 _1594_ (.A(net342),
    .B(_1289_),
    .C(_1290_),
    .D(_1291_),
    .Y(_1292_));
 sg13g2_o21ai_1 _1595_ (.B1(net340),
    .Y(_1293_),
    .A1(_1286_),
    .A2(_1292_));
 sg13g2_inv_1 _1596_ (.Y(_1294_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_40_));
 sg13g2_o21ai_1 _1597_ (.B1(net296),
    .Y(_1295_),
    .A1(net351),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_32_));
 sg13g2_a21oi_1 _1598_ (.A1(net349),
    .A2(_1294_),
    .Y(_1296_),
    .B1(_1295_));
 sg13g2_nor2b_1 _1599_ (.A(net262),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_48_),
    .Y(_1297_));
 sg13g2_nor2b_1 _1600_ (.A(net259),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_56_),
    .Y(_1298_));
 sg13g2_nor4_1 _1601_ (.A(net302),
    .B(_1296_),
    .C(_1297_),
    .D(_1298_),
    .Y(_1299_));
 sg13g2_inv_1 _1602_ (.Y(_1300_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_0_));
 sg13g2_o21ai_1 _1603_ (.B1(net296),
    .Y(_1301_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_8_),
    .A2(net293));
 sg13g2_a21oi_1 _1604_ (.A1(net292),
    .A2(_1300_),
    .Y(_1302_),
    .B1(_1301_));
 sg13g2_nor2b_1 _1605_ (.A(net261),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_16_),
    .Y(_1303_));
 sg13g2_nor2b_1 _1606_ (.A(net259),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_24_),
    .Y(_1304_));
 sg13g2_nor4_1 _1607_ (.A(net343),
    .B(_1302_),
    .C(_1303_),
    .D(_1304_),
    .Y(_1305_));
 sg13g2_o21ai_1 _1608_ (.B1(net304),
    .Y(_1306_),
    .A1(_1299_),
    .A2(_1305_));
 sg13g2_nand3_1 _1609_ (.B(_1306_),
    .C(net258),
    .A(_1293_),
    .Y(_1307_));
 sg13g2_nand2_1 _1610_ (.Y(u_uart_reg_reg_rsp_o_2_),
    .A(_1280_),
    .B(_1307_));
 sg13g2_a221oi_1 _1611_ (.B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_92_),
    .C1(net343),
    .B1(net282),
    .A1(net284),
    .Y(_1308_),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_84_));
 sg13g2_nand2b_1 _1612_ (.Y(_1309_),
    .B(net292),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_68_));
 sg13g2_nand2b_1 _1613_ (.Y(_1310_),
    .B(net348),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_76_));
 sg13g2_nand3_1 _1614_ (.B(_1310_),
    .C(net295),
    .A(_1309_),
    .Y(_1311_));
 sg13g2_nand2b_1 _1615_ (.Y(_1312_),
    .B(net292),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_100_));
 sg13g2_nand2b_1 _1616_ (.Y(_1313_),
    .B(net347),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_108_));
 sg13g2_nand3_1 _1617_ (.B(_1313_),
    .C(net295),
    .A(_1312_),
    .Y(_1314_));
 sg13g2_a221oi_1 _1618_ (.B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_124_),
    .C1(net302),
    .B1(net282),
    .A1(net283),
    .Y(_1315_),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_116_));
 sg13g2_a22oi_1 _1619_ (.Y(_1316_),
    .B1(_1314_),
    .B2(_1315_),
    .A2(_1311_),
    .A1(_1308_));
 sg13g2_nand2b_1 _1620_ (.Y(_1317_),
    .B(net340),
    .A_N(_1316_));
 sg13g2_inv_1 _1621_ (.Y(_1318_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_44_));
 sg13g2_o21ai_1 _1622_ (.B1(net296),
    .Y(_1319_),
    .A1(net351),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_36_));
 sg13g2_a21oi_1 _1623_ (.A1(net349),
    .A2(_1318_),
    .Y(_1320_),
    .B1(_1319_));
 sg13g2_nor2b_1 _1624_ (.A(net262),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_52_),
    .Y(_1321_));
 sg13g2_nor2b_1 _1625_ (.A(net260),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_60_),
    .Y(_1322_));
 sg13g2_nor4_1 _1626_ (.A(net302),
    .B(_1320_),
    .C(_1321_),
    .D(_1322_),
    .Y(_1323_));
 sg13g2_inv_1 _1627_ (.Y(_1324_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_4_));
 sg13g2_o21ai_1 _1628_ (.B1(net296),
    .Y(_1325_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_12_),
    .A2(net294));
 sg13g2_a21oi_1 _1629_ (.A1(net293),
    .A2(_1324_),
    .Y(_1326_),
    .B1(_1325_));
 sg13g2_nor2b_1 _1630_ (.A(_1238_),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_28_),
    .Y(_1327_));
 sg13g2_nor2b_1 _1631_ (.A(net261),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_20_),
    .Y(_1328_));
 sg13g2_nor4_1 _1632_ (.A(net343),
    .B(_1326_),
    .C(_1327_),
    .D(_1328_),
    .Y(_1329_));
 sg13g2_o21ai_1 _1633_ (.B1(net304),
    .Y(_1330_),
    .A1(_1323_),
    .A2(_1329_));
 sg13g2_nand3_1 _1634_ (.B(_1330_),
    .C(net258),
    .A(_1317_),
    .Y(_1331_));
 sg13g2_inv_2 _1635_ (.Y(_1332_),
    .A(_0046_));
 sg13g2_a22oi_1 _1636_ (.Y(_1333_),
    .B1(_1332_),
    .B2(_1278_),
    .A2(reg2hw_37_),
    .A1(_1092_));
 sg13g2_nand3_1 _1637_ (.B(net264),
    .C(_1333_),
    .A(_1331_),
    .Y(u_uart_reg_reg_rsp_o_6_));
 sg13g2_nand2_2 _1638_ (.Y(_1334_),
    .A(reg_req_i[41]),
    .B(reg_req_i[42]));
 sg13g2_nor2_1 _1639_ (.A(_1097_),
    .B(_1278_),
    .Y(_1335_));
 sg13g2_nand3_1 _1640_ (.B(reg_req_i[40]),
    .C(_1260_),
    .A(_1094_),
    .Y(_1336_));
 sg13g2_a21oi_1 _1641_ (.A1(_1335_),
    .A2(_1336_),
    .Y(_1337_),
    .B1(reg_req_i[0]));
 sg13g2_nand3_1 _1642_ (.B(reg_req_i[1]),
    .C(reg_req_i[0]),
    .A(reg_req_i[2]),
    .Y(_1338_));
 sg13g2_o21ai_1 _1643_ (.B1(_1338_),
    .Y(_1339_),
    .A1(_1092_),
    .A2(_1213_));
 sg13g2_o21ai_1 _1644_ (.B1(_1339_),
    .Y(_1340_),
    .A1(reg_req_i[3]),
    .A2(_1093_));
 sg13g2_o21ai_1 _1645_ (.B1(reg_req_i[41]),
    .Y(_1341_),
    .A1(_1337_),
    .A2(_1340_));
 sg13g2_nand2_2 _1646_ (.Y(_1342_),
    .A(_1341_),
    .B(net263));
 sg13g2_nor4_1 _1647_ (.A(_1260_),
    .B(_1096_),
    .C(_1334_),
    .D(_1342_),
    .Y(_1343_));
 sg13g2_buf_1 _1648_ (.A(_1343_),
    .X(u_uart_reg_u_reg_core_reg_we_check_3_));
 sg13g2_mux2_1 _1649_ (.A0(net375),
    .A1(reg_req_i[10]),
    .S(net253),
    .X(_0053_));
 sg13g2_mux2_1 _1650_ (.A0(net376),
    .A1(reg_req_i[9]),
    .S(net253),
    .X(_0054_));
 sg13g2_mux2_1 _1651_ (.A0(net377),
    .A1(reg_req_i[8]),
    .S(net253),
    .X(_0055_));
 sg13g2_mux2_1 _1652_ (.A0(net378),
    .A1(reg_req_i[7]),
    .S(net253),
    .X(_0056_));
 sg13g2_mux2_1 _1653_ (.A0(net379),
    .A1(reg_req_i[6]),
    .S(net253),
    .X(_0057_));
 sg13g2_mux2_1 _1654_ (.A0(net380),
    .A1(reg_req_i[5]),
    .S(net254),
    .X(_0058_));
 sg13g2_mux2_1 _1655_ (.A0(net381),
    .A1(reg_req_i[4]),
    .S(net254),
    .X(_0059_));
 sg13g2_inv_1 _1656_ (.Y(_1344_),
    .A(net386));
 sg13g2_nor3_1 _1657_ (.A(net287),
    .B(_1334_),
    .C(_1342_),
    .Y(_1345_));
 sg13g2_buf_1 _1658_ (.A(_1345_),
    .X(_1346_));
 sg13g2_buf_2 _1659_ (.A(_1346_),
    .X(_1347_));
 sg13g2_nand2b_1 _1660_ (.Y(_1348_),
    .B(net251),
    .A_N(reg_req_i[34]));
 sg13g2_o21ai_1 _1661_ (.B1(_1348_),
    .Y(_0060_),
    .A1(_1344_),
    .A2(net238));
 sg13g2_nand2_1 _1662_ (.Y(_1349_),
    .A(net240),
    .B(reg_req_i[33]));
 sg13g2_o21ai_1 _1663_ (.B1(_1349_),
    .Y(_0061_),
    .A1(_1100_),
    .A2(net238));
 sg13g2_nand2_1 _1664_ (.Y(_0334_),
    .A(net240),
    .B(reg_req_i[32]));
 sg13g2_o21ai_1 _1665_ (.B1(_0334_),
    .Y(_0062_),
    .A1(_1101_),
    .A2(net238));
 sg13g2_inv_1 _1666_ (.Y(_0335_),
    .A(_0019_));
 sg13g2_nand2b_1 _1667_ (.Y(_0336_),
    .B(net252),
    .A_N(reg_req_i[31]));
 sg13g2_o21ai_1 _1668_ (.B1(_0336_),
    .Y(_0063_),
    .A1(_0335_),
    .A2(net238));
 sg13g2_nand2_1 _1669_ (.Y(_0337_),
    .A(_1347_),
    .B(reg_req_i[30]));
 sg13g2_o21ai_1 _1670_ (.B1(_0337_),
    .Y(_0064_),
    .A1(_1166_),
    .A2(net238));
 sg13g2_nand2b_1 _1671_ (.Y(_0338_),
    .B(net252),
    .A_N(reg_req_i[29]));
 sg13g2_o21ai_1 _1672_ (.B1(_0338_),
    .Y(_0065_),
    .A1(_1153_),
    .A2(net238));
 sg13g2_nand2b_1 _1673_ (.Y(_0339_),
    .B(net252),
    .A_N(reg_req_i[28]));
 sg13g2_o21ai_1 _1674_ (.B1(_0339_),
    .Y(_0066_),
    .A1(_1160_),
    .A2(net238));
 sg13g2_nand2_1 _1675_ (.Y(_0340_),
    .A(_1347_),
    .B(reg_req_i[27]));
 sg13g2_o21ai_1 _1676_ (.B1(_0340_),
    .Y(_0067_),
    .A1(_1136_),
    .A2(net238));
 sg13g2_nand2b_1 _1677_ (.Y(_0341_),
    .B(net252),
    .A_N(reg_req_i[26]));
 sg13g2_o21ai_1 _1678_ (.B1(_0341_),
    .Y(_0068_),
    .A1(_1141_),
    .A2(net239));
 sg13g2_nand2b_1 _1679_ (.Y(_0342_),
    .B(net252),
    .A_N(reg_req_i[25]));
 sg13g2_o21ai_1 _1680_ (.B1(_0342_),
    .Y(_0069_),
    .A1(_1111_),
    .A2(net239));
 sg13g2_nand2b_1 _1681_ (.Y(_0343_),
    .B(net252),
    .A_N(reg_req_i[24]));
 sg13g2_o21ai_1 _1682_ (.B1(_0343_),
    .Y(_0070_),
    .A1(_1113_),
    .A2(net239));
 sg13g2_nand2b_1 _1683_ (.Y(_0344_),
    .B(net252),
    .A_N(reg_req_i[23]));
 sg13g2_o21ai_1 _1684_ (.B1(_0344_),
    .Y(_0071_),
    .A1(_1219_),
    .A2(net239));
 sg13g2_nand2b_1 _1685_ (.Y(_0345_),
    .B(net252),
    .A_N(reg_req_i[22]));
 sg13g2_o21ai_1 _1686_ (.B1(_0345_),
    .Y(_0072_),
    .A1(_1114_),
    .A2(net239));
 sg13g2_nand2b_1 _1687_ (.Y(_0346_),
    .B(_1346_),
    .A_N(reg_req_i[21]));
 sg13g2_o21ai_1 _1688_ (.B1(_0346_),
    .Y(_0073_),
    .A1(_1116_),
    .A2(net239));
 sg13g2_nand2b_1 _1689_ (.Y(_0347_),
    .B(_1346_),
    .A_N(reg_req_i[20]));
 sg13g2_o21ai_1 _1690_ (.B1(_0347_),
    .Y(_0074_),
    .A1(_1119_),
    .A2(net239));
 sg13g2_inv_2 _1691_ (.Y(_0348_),
    .A(u_uart_core_uart_tx_bit_cnt_q_2_));
 sg13g2_inv_2 _1692_ (.Y(_0349_),
    .A(net382));
 sg13g2_nor2_2 _1693_ (.A(net306),
    .B(u_uart_core_uart_tx_bit_cnt_q_1_),
    .Y(_0350_));
 sg13g2_inv_1 _1694_ (.Y(_0351_),
    .A(u_uart_core_uart_tx_bit_cnt_q_3_));
 sg13g2_nand3_1 _1695_ (.B(_0348_),
    .C(_0351_),
    .A(_0350_),
    .Y(_0352_));
 sg13g2_nand2_1 _1696_ (.Y(_0353_),
    .A(_0352_),
    .B(u_uart_core_uart_tx_tick_baud_q));
 sg13g2_inv_1 _1697_ (.Y(_0354_),
    .A(_0353_));
 sg13g2_nor2_1 _1698_ (.A(_0349_),
    .B(_0354_),
    .Y(_0355_));
 sg13g2_inv_1 _1699_ (.Y(_0356_),
    .A(_0355_));
 sg13g2_nor2_2 _1700_ (.A(_1274_),
    .B(_1272_),
    .Y(_0357_));
 sg13g2_inv_2 _1701_ (.Y(_0358_),
    .A(_0357_));
 sg13g2_nand2_1 _1702_ (.Y(_0359_),
    .A(_0352_),
    .B(net382));
 sg13g2_nand3_1 _1703_ (.B(_0045_),
    .C(_0359_),
    .A(_0358_),
    .Y(_0360_));
 sg13g2_buf_4 _1704_ (.X(_0361_),
    .A(_0360_));
 sg13g2_inv_2 _1705_ (.Y(_0362_),
    .A(_0361_));
 sg13g2_nor2_1 _1706_ (.A(_0356_),
    .B(_0362_),
    .Y(_0363_));
 sg13g2_inv_4 _1707_ (.A(net250),
    .Y(_0364_));
 sg13g2_nor2_1 _1708_ (.A(_0349_),
    .B(net250),
    .Y(_0365_));
 sg13g2_xnor2_1 _1709_ (.Y(_0366_),
    .A(_0348_),
    .B(_0350_));
 sg13g2_nand3_1 _1710_ (.B(net257),
    .C(_0366_),
    .A(net237),
    .Y(_0367_));
 sg13g2_o21ai_1 _1711_ (.B1(_0367_),
    .Y(_0075_),
    .A1(_0348_),
    .A2(_0364_));
 sg13g2_inv_1 _1712_ (.Y(_0368_),
    .A(u_uart_core_uart_tx_bit_cnt_q_1_));
 sg13g2_a21oi_1 _1713_ (.A1(net306),
    .A2(net382),
    .Y(_0369_),
    .B1(net250));
 sg13g2_nand2_1 _1714_ (.Y(_0370_),
    .A(net237),
    .B(_0350_));
 sg13g2_o21ai_1 _1715_ (.B1(_0370_),
    .Y(_0076_),
    .A1(_0368_),
    .A2(_0369_));
 sg13g2_inv_2 _1716_ (.Y(_0371_),
    .A(_0365_));
 sg13g2_inv_1 _1717_ (.Y(_0372_),
    .A(net306));
 sg13g2_nor2_1 _1718_ (.A(_0349_),
    .B(_0361_),
    .Y(_0373_));
 sg13g2_inv_2 _1719_ (.Y(_0374_),
    .A(_0373_));
 sg13g2_inv_1 _1720_ (.Y(_0375_),
    .A(net385));
 sg13g2_nor2_1 _1721_ (.A(_0375_),
    .B(_0374_),
    .Y(_0376_));
 sg13g2_a21oi_1 _1722_ (.A1(_0372_),
    .A2(_0374_),
    .Y(_0377_),
    .B1(_0376_));
 sg13g2_nand2_1 _1723_ (.Y(_0378_),
    .A(net250),
    .B(net306));
 sg13g2_o21ai_1 _1724_ (.B1(_0378_),
    .Y(_0077_),
    .A1(_0371_),
    .A2(_0377_));
 sg13g2_nand2_1 _1725_ (.Y(_0379_),
    .A(u_uart_core_uart_tx_baud_div_q_0_),
    .B(net360));
 sg13g2_nor2b_1 _1726_ (.A(_0379_),
    .B_N(u_uart_core_uart_tx_baud_div_q_1_),
    .Y(_0380_));
 sg13g2_xor2_1 _1727_ (.B(_0380_),
    .A(u_uart_core_uart_tx_baud_div_q_2_),
    .X(_0078_));
 sg13g2_xnor2_1 _1728_ (.Y(_0079_),
    .A(u_uart_core_uart_tx_baud_div_q_1_),
    .B(_0379_));
 sg13g2_xor2_1 _1729_ (.B(net360),
    .A(u_uart_core_uart_tx_baud_div_q_0_),
    .X(_0080_));
 sg13g2_inv_1 _1730_ (.Y(_0381_),
    .A(net307));
 sg13g2_inv_1 _1731_ (.Y(_0382_),
    .A(u_uart_core_rx_tick_baud));
 sg13g2_nor2_1 _1732_ (.A(_1332_),
    .B(_0382_),
    .Y(_0383_));
 sg13g2_inv_1 _1733_ (.Y(_0384_),
    .A(reg2hw_37_));
 sg13g2_inv_1 _1734_ (.Y(_0385_),
    .A(reg2hw_36_));
 sg13g2_o21ai_1 _1735_ (.B1(_0042_),
    .Y(_0386_),
    .A1(_0039_),
    .A2(_0385_));
 sg13g2_nand2b_1 _1736_ (.Y(_0387_),
    .B(_0386_),
    .A_N(_0040_));
 sg13g2_inv_1 _1737_ (.Y(_0388_),
    .A(net387));
 sg13g2_a21o_1 _1738_ (.A2(_0039_),
    .A1(reg2hw_36_),
    .B1(_0042_),
    .X(_0389_));
 sg13g2_nand4_1 _1739_ (.B(_0388_),
    .C(_0384_),
    .A(_0387_),
    .Y(_0390_),
    .D(_0389_));
 sg13g2_o21ai_1 _1740_ (.B1(_0390_),
    .Y(_0391_),
    .A1(_1087_),
    .A2(_0384_));
 sg13g2_nand2_1 _1741_ (.Y(_0392_),
    .A(_0391_),
    .B(_1332_));
 sg13g2_inv_2 _1742_ (.Y(_0393_),
    .A(_0392_));
 sg13g2_nor2_1 _1743_ (.A(_0383_),
    .B(_0393_),
    .Y(_0394_));
 sg13g2_inv_1 _1744_ (.Y(_0395_),
    .A(net315));
 sg13g2_inv_2 _1745_ (.Y(_0396_),
    .A(u_uart_core_uart_rx_bit_cnt_q_3_));
 sg13g2_xor2_1 _1746_ (.B(net385),
    .A(net316),
    .X(_0397_));
 sg13g2_nor4_1 _1747_ (.A(u_uart_core_uart_rx_bit_cnt_q_2_),
    .B(_0395_),
    .C(_0396_),
    .D(_0397_),
    .Y(_0398_));
 sg13g2_nand2b_1 _1748_ (.Y(_0399_),
    .B(_0398_),
    .A_N(_0391_));
 sg13g2_nor2b_1 _1749_ (.A(_0394_),
    .B_N(_0399_),
    .Y(_0400_));
 sg13g2_buf_1 _1750_ (.A(_0400_),
    .X(_0401_));
 sg13g2_inv_1 _1751_ (.Y(_0402_),
    .A(_0383_));
 sg13g2_nor2b_1 _1752_ (.A(_0402_),
    .B_N(_0399_),
    .Y(_0403_));
 sg13g2_buf_1 _1753_ (.A(_0403_),
    .X(_0404_));
 sg13g2_nand2_1 _1754_ (.Y(_0405_),
    .A(net255),
    .B(u_uart_core_uart_rx_sreg_q_10_));
 sg13g2_o21ai_1 _1755_ (.B1(_0405_),
    .Y(_0081_),
    .A1(_0381_),
    .A2(net249));
 sg13g2_inv_1 _1756_ (.Y(_0406_),
    .A(net308));
 sg13g2_nand2_1 _1757_ (.Y(_0407_),
    .A(net255),
    .B(net307));
 sg13g2_o21ai_1 _1758_ (.B1(_0407_),
    .Y(_0082_),
    .A1(_0406_),
    .A2(net249));
 sg13g2_inv_1 _1759_ (.Y(_0408_),
    .A(net309));
 sg13g2_nand2_1 _1760_ (.Y(_0409_),
    .A(net255),
    .B(net308));
 sg13g2_o21ai_1 _1761_ (.B1(_0409_),
    .Y(_0083_),
    .A1(_0408_),
    .A2(net249));
 sg13g2_inv_1 _1762_ (.Y(_0410_),
    .A(net310));
 sg13g2_nand2_1 _1763_ (.Y(_0411_),
    .A(net255),
    .B(net309));
 sg13g2_o21ai_1 _1764_ (.B1(_0411_),
    .Y(_0084_),
    .A1(_0410_),
    .A2(net249));
 sg13g2_inv_1 _1765_ (.Y(_0412_),
    .A(net311));
 sg13g2_nand2_1 _1766_ (.Y(_0413_),
    .A(net255),
    .B(net310));
 sg13g2_o21ai_1 _1767_ (.B1(_0413_),
    .Y(_0085_),
    .A1(_0412_),
    .A2(net249));
 sg13g2_inv_1 _1768_ (.Y(_0414_),
    .A(net312));
 sg13g2_nand2_1 _1769_ (.Y(_0415_),
    .A(net255),
    .B(net311));
 sg13g2_o21ai_1 _1770_ (.B1(_0415_),
    .Y(_0086_),
    .A1(_0414_),
    .A2(net249));
 sg13g2_inv_1 _1771_ (.Y(_0416_),
    .A(net313));
 sg13g2_nand2_1 _1772_ (.Y(_0417_),
    .A(net255),
    .B(net312));
 sg13g2_o21ai_1 _1773_ (.B1(_0417_),
    .Y(_0087_),
    .A1(_0416_),
    .A2(net249));
 sg13g2_inv_1 _1774_ (.Y(_0418_),
    .A(net314));
 sg13g2_nand2_1 _1775_ (.Y(_0419_),
    .A(net255),
    .B(net313));
 sg13g2_o21ai_1 _1776_ (.B1(_0419_),
    .Y(_0088_),
    .A1(_0418_),
    .A2(net249));
 sg13g2_inv_1 _1777_ (.Y(_0420_),
    .A(u_uart_core_uart_rx_sreg_q_1_));
 sg13g2_nand2_1 _1778_ (.Y(_0421_),
    .A(net256),
    .B(net314));
 sg13g2_o21ai_1 _1779_ (.B1(_0421_),
    .Y(_0089_),
    .A1(_0420_),
    .A2(_0401_));
 sg13g2_inv_1 _1780_ (.Y(_0422_),
    .A(u_uart_core_uart_rx_bit_cnt_q_2_));
 sg13g2_inv_1 _1781_ (.Y(_0423_),
    .A(_0394_));
 sg13g2_nor3_1 _1782_ (.A(u_uart_core_uart_rx_bit_cnt_q_2_),
    .B(net315),
    .C(net316),
    .Y(_0424_));
 sg13g2_inv_2 _1783_ (.Y(_0425_),
    .A(net316));
 sg13g2_a21oi_1 _1784_ (.A1(_0395_),
    .A2(_0425_),
    .Y(_0426_),
    .B1(_0422_));
 sg13g2_o21ai_1 _1785_ (.B1(net256),
    .Y(_0427_),
    .A1(_0424_),
    .A2(_0426_));
 sg13g2_o21ai_1 _1786_ (.B1(_0427_),
    .Y(_0090_),
    .A1(_0422_),
    .A2(_0423_));
 sg13g2_nor2_1 _1787_ (.A(net315),
    .B(_0425_),
    .Y(_0428_));
 sg13g2_inv_1 _1788_ (.Y(_0429_),
    .A(_0428_));
 sg13g2_nand2_1 _1789_ (.Y(_0430_),
    .A(_0425_),
    .B(net315));
 sg13g2_nand3_1 _1790_ (.B(_0429_),
    .C(_0430_),
    .A(net256),
    .Y(_0431_));
 sg13g2_a21oi_1 _1791_ (.A1(net315),
    .A2(_0402_),
    .Y(_0432_),
    .B1(_0393_));
 sg13g2_nand2_1 _1792_ (.Y(_0091_),
    .A(_0431_),
    .B(_0432_));
 sg13g2_a22oi_1 _1793_ (.Y(_0433_),
    .B1(_0425_),
    .B2(net256),
    .A2(_0393_),
    .A1(net383));
 sg13g2_o21ai_1 _1794_ (.B1(_0433_),
    .Y(_0092_),
    .A1(_0425_),
    .A2(_0423_));
 sg13g2_inv_1 _1795_ (.Y(_0434_),
    .A(u_uart_core_uart_rx_baud_div_q_2_));
 sg13g2_and2_1 _1796_ (.A(u_uart_core_uart_rx_baud_div_q_0_),
    .B(net360),
    .X(_0435_));
 sg13g2_nand2_2 _1797_ (.Y(_0436_),
    .A(net300),
    .B(u_uart_core_uart_rx_baud_div_q_1_));
 sg13g2_nor2_1 _1798_ (.A(_0434_),
    .B(_0436_),
    .Y(_0437_));
 sg13g2_nor2_1 _1799_ (.A(_0437_),
    .B(_0393_),
    .Y(_0438_));
 sg13g2_inv_1 _1800_ (.Y(_0439_),
    .A(_0438_));
 sg13g2_a21oi_1 _1801_ (.A1(_0434_),
    .A2(_0436_),
    .Y(_0093_),
    .B1(_0439_));
 sg13g2_inv_1 _1802_ (.Y(_0440_),
    .A(_0436_));
 sg13g2_nor2_1 _1803_ (.A(u_uart_core_uart_rx_baud_div_q_1_),
    .B(net300),
    .Y(_0441_));
 sg13g2_nor3_1 _1804_ (.A(_0440_),
    .B(_0441_),
    .C(_0393_),
    .Y(_0094_));
 sg13g2_nor2_1 _1805_ (.A(u_uart_core_uart_rx_baud_div_q_0_),
    .B(net360),
    .Y(_0442_));
 sg13g2_nor3_1 _1806_ (.A(net300),
    .B(_0442_),
    .C(_0393_),
    .Y(_0095_));
 sg13g2_inv_2 _1807_ (.Y(_0443_),
    .A(net318));
 sg13g2_nor2b_2 _1808_ (.A(_1276_),
    .B_N(reg2hw_4_),
    .Y(_0444_));
 sg13g2_nand2_2 _1809_ (.Y(_0445_),
    .A(_0444_),
    .B(net319));
 sg13g2_nor2_1 _1810_ (.A(_0443_),
    .B(_0445_),
    .Y(_0446_));
 sg13g2_nor2_1 _1811_ (.A(net317),
    .B(_0446_),
    .Y(_0447_));
 sg13g2_inv_1 _1812_ (.Y(_0448_),
    .A(reg2hw_3_));
 sg13g2_inv_1 _1813_ (.Y(_0449_),
    .A(reg2hw_0_));
 sg13g2_nor2_1 _1814_ (.A(_0448_),
    .B(_0449_),
    .Y(_0450_));
 sg13g2_nand2_1 _1815_ (.Y(_0451_),
    .A(_0446_),
    .B(net317));
 sg13g2_buf_1 _1816_ (.A(_0451_),
    .X(_0452_));
 sg13g2_inv_1 _1817_ (.Y(_0453_),
    .A(_0452_));
 sg13g2_nor3_1 _1818_ (.A(_0447_),
    .B(net290),
    .C(_0453_),
    .Y(_0096_));
 sg13g2_inv_1 _1819_ (.Y(_0454_),
    .A(_0445_));
 sg13g2_nor2_1 _1820_ (.A(net318),
    .B(_0454_),
    .Y(_0455_));
 sg13g2_nor3_1 _1821_ (.A(_0446_),
    .B(net290),
    .C(_0455_),
    .Y(_0097_));
 sg13g2_nor2_1 _1822_ (.A(net319),
    .B(_0444_),
    .Y(_0456_));
 sg13g2_nor3_1 _1823_ (.A(net290),
    .B(_0456_),
    .C(_0454_),
    .Y(_0098_));
 sg13g2_inv_1 _1824_ (.Y(_0457_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_62_));
 sg13g2_nor2_1 _1825_ (.A(reg2hw_11_),
    .B(net236),
    .Y(_0458_));
 sg13g2_a21oi_1 _1826_ (.A1(_0457_),
    .A2(net235),
    .Y(_0099_),
    .B1(_0458_));
 sg13g2_inv_1 _1827_ (.Y(_0459_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_61_));
 sg13g2_nor2_1 _1828_ (.A(reg2hw_10_),
    .B(net236),
    .Y(_0460_));
 sg13g2_a21oi_1 _1829_ (.A1(_0459_),
    .A2(net235),
    .Y(_0100_),
    .B1(_0460_));
 sg13g2_inv_1 _1830_ (.Y(_0461_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_60_));
 sg13g2_nor2_1 _1831_ (.A(reg2hw_9_),
    .B(net236),
    .Y(_0462_));
 sg13g2_a21oi_1 _1832_ (.A1(_0461_),
    .A2(net235),
    .Y(_0101_),
    .B1(_0462_));
 sg13g2_inv_1 _1833_ (.Y(_0463_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_59_));
 sg13g2_nor2_1 _1834_ (.A(reg2hw_8_),
    .B(net236),
    .Y(_0464_));
 sg13g2_a21oi_1 _1835_ (.A1(_0463_),
    .A2(net235),
    .Y(_0102_),
    .B1(_0464_));
 sg13g2_inv_1 _1836_ (.Y(_0465_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_58_));
 sg13g2_nor2_1 _1837_ (.A(reg2hw_7_),
    .B(net236),
    .Y(_0466_));
 sg13g2_a21oi_1 _1838_ (.A1(_0465_),
    .A2(net235),
    .Y(_0103_),
    .B1(_0466_));
 sg13g2_inv_1 _1839_ (.Y(_0467_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_57_));
 sg13g2_nor2_1 _1840_ (.A(reg2hw_6_),
    .B(net236),
    .Y(_0468_));
 sg13g2_a21oi_1 _1841_ (.A1(_0467_),
    .A2(net235),
    .Y(_0104_),
    .B1(_0468_));
 sg13g2_inv_1 _1842_ (.Y(_0469_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_56_));
 sg13g2_nor2_1 _1843_ (.A(reg2hw_5_),
    .B(net236),
    .Y(_0470_));
 sg13g2_a21oi_1 _1844_ (.A1(_0469_),
    .A2(net235),
    .Y(_0105_),
    .B1(_0470_));
 sg13g2_inv_1 _1845_ (.Y(_0471_),
    .A(net319));
 sg13g2_nand2_1 _1846_ (.Y(_0472_),
    .A(_0444_),
    .B(_0471_));
 sg13g2_nor2_1 _1847_ (.A(_1267_),
    .B(_0472_),
    .Y(_0473_));
 sg13g2_nand2_1 _1848_ (.Y(_0474_),
    .A(_0473_),
    .B(net318));
 sg13g2_buf_1 _1849_ (.A(_0474_),
    .X(_0475_));
 sg13g2_mux2_1 _1850_ (.A0(net375),
    .A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_54_),
    .S(net234),
    .X(_0106_));
 sg13g2_mux2_1 _1851_ (.A0(net376),
    .A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_53_),
    .S(net234),
    .X(_0107_));
 sg13g2_mux2_1 _1852_ (.A0(net377),
    .A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_52_),
    .S(net234),
    .X(_0108_));
 sg13g2_mux2_1 _1853_ (.A0(net378),
    .A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_51_),
    .S(net234),
    .X(_0109_));
 sg13g2_mux2_1 _1854_ (.A0(net379),
    .A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_50_),
    .S(net234),
    .X(_0110_));
 sg13g2_mux2_1 _1855_ (.A0(net380),
    .A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_49_),
    .S(net234),
    .X(_0111_));
 sg13g2_mux2_1 _1856_ (.A0(net381),
    .A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_48_),
    .S(_0475_),
    .X(_0112_));
 sg13g2_inv_1 _1857_ (.Y(_0476_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_46_));
 sg13g2_nor3_1 _1858_ (.A(_1267_),
    .B(net318),
    .C(_0445_),
    .Y(_0477_));
 sg13g2_buf_1 _1859_ (.A(_0477_),
    .X(_0478_));
 sg13g2_nand2_1 _1860_ (.Y(_0479_),
    .A(net248),
    .B(net375));
 sg13g2_o21ai_1 _1861_ (.B1(_0479_),
    .Y(_0113_),
    .A1(_0476_),
    .A2(net247));
 sg13g2_inv_1 _1862_ (.Y(_0480_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_45_));
 sg13g2_nand2_1 _1863_ (.Y(_0481_),
    .A(net248),
    .B(net376));
 sg13g2_o21ai_1 _1864_ (.B1(_0481_),
    .Y(_0114_),
    .A1(_0480_),
    .A2(net247));
 sg13g2_inv_1 _1865_ (.Y(_0482_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_44_));
 sg13g2_nand2_1 _1866_ (.Y(_0483_),
    .A(net248),
    .B(net377));
 sg13g2_o21ai_1 _1867_ (.B1(_0483_),
    .Y(_0115_),
    .A1(_0482_),
    .A2(net247));
 sg13g2_inv_1 _1868_ (.Y(_0484_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_43_));
 sg13g2_nand2_1 _1869_ (.Y(_0485_),
    .A(net248),
    .B(net378));
 sg13g2_o21ai_1 _1870_ (.B1(_0485_),
    .Y(_0116_),
    .A1(_0484_),
    .A2(net247));
 sg13g2_inv_1 _1871_ (.Y(_0486_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_42_));
 sg13g2_nand2_1 _1872_ (.Y(_0487_),
    .A(net248),
    .B(net379));
 sg13g2_o21ai_1 _1873_ (.B1(_0487_),
    .Y(_0117_),
    .A1(_0486_),
    .A2(net247));
 sg13g2_inv_1 _1874_ (.Y(_0488_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_41_));
 sg13g2_nand2_1 _1875_ (.Y(_0489_),
    .A(net248),
    .B(net380));
 sg13g2_o21ai_1 _1876_ (.B1(_0489_),
    .Y(_0118_),
    .A1(_0488_),
    .A2(net247));
 sg13g2_inv_1 _1877_ (.Y(_0490_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_40_));
 sg13g2_nand2_1 _1878_ (.Y(_0491_),
    .A(net248),
    .B(net381));
 sg13g2_o21ai_1 _1879_ (.B1(_0491_),
    .Y(_0119_),
    .A1(_0490_),
    .A2(net247));
 sg13g2_nand2_1 _1880_ (.Y(_0492_),
    .A(_0473_),
    .B(_0443_));
 sg13g2_buf_1 _1881_ (.A(_0492_),
    .X(_0493_));
 sg13g2_mux2_1 _1882_ (.A0(net375),
    .A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_38_),
    .S(net233),
    .X(_0120_));
 sg13g2_mux2_1 _1883_ (.A0(net376),
    .A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_37_),
    .S(net233),
    .X(_0121_));
 sg13g2_mux2_1 _1884_ (.A0(net377),
    .A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_36_),
    .S(net233),
    .X(_0122_));
 sg13g2_mux2_1 _1885_ (.A0(net378),
    .A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_35_),
    .S(net233),
    .X(_0123_));
 sg13g2_mux2_1 _1886_ (.A0(net379),
    .A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_34_),
    .S(net233),
    .X(_0124_));
 sg13g2_mux2_1 _1887_ (.A0(net380),
    .A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_33_),
    .S(net233),
    .X(_0125_));
 sg13g2_mux2_1 _1888_ (.A0(net381),
    .A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_32_),
    .S(_0493_),
    .X(_0126_));
 sg13g2_inv_1 _1889_ (.Y(_0494_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_30_));
 sg13g2_nand2_1 _1890_ (.Y(_0495_),
    .A(_1267_),
    .B(net318));
 sg13g2_nor2_1 _1891_ (.A(_0495_),
    .B(_0445_),
    .Y(_0496_));
 sg13g2_buf_1 _1892_ (.A(_0496_),
    .X(_0497_));
 sg13g2_nand2_1 _1893_ (.Y(_0498_),
    .A(net246),
    .B(net375));
 sg13g2_o21ai_1 _1894_ (.B1(_0498_),
    .Y(_0127_),
    .A1(_0494_),
    .A2(net245));
 sg13g2_inv_1 _1895_ (.Y(_0499_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_29_));
 sg13g2_nand2_1 _1896_ (.Y(_0500_),
    .A(net246),
    .B(net376));
 sg13g2_o21ai_1 _1897_ (.B1(_0500_),
    .Y(_0128_),
    .A1(_0499_),
    .A2(net245));
 sg13g2_inv_1 _1898_ (.Y(_0501_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_28_));
 sg13g2_nand2_1 _1899_ (.Y(_0502_),
    .A(net246),
    .B(net377));
 sg13g2_o21ai_1 _1900_ (.B1(_0502_),
    .Y(_0129_),
    .A1(_0501_),
    .A2(net245));
 sg13g2_inv_1 _1901_ (.Y(_0503_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_27_));
 sg13g2_nand2_1 _1902_ (.Y(_0504_),
    .A(net246),
    .B(net378));
 sg13g2_o21ai_1 _1903_ (.B1(_0504_),
    .Y(_0130_),
    .A1(_0503_),
    .A2(net245));
 sg13g2_inv_1 _1904_ (.Y(_0505_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_26_));
 sg13g2_nand2_1 _1905_ (.Y(_0506_),
    .A(net246),
    .B(net379));
 sg13g2_o21ai_1 _1906_ (.B1(_0506_),
    .Y(_0131_),
    .A1(_0505_),
    .A2(net245));
 sg13g2_inv_1 _1907_ (.Y(_0507_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_25_));
 sg13g2_nand2_1 _1908_ (.Y(_0508_),
    .A(net246),
    .B(net380));
 sg13g2_o21ai_1 _1909_ (.B1(_0508_),
    .Y(_0132_),
    .A1(_0507_),
    .A2(net245));
 sg13g2_inv_1 _1910_ (.Y(_0509_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_24_));
 sg13g2_nand2_1 _1911_ (.Y(_0510_),
    .A(net246),
    .B(net381));
 sg13g2_o21ai_1 _1912_ (.B1(_0510_),
    .Y(_0133_),
    .A1(_0509_),
    .A2(net245));
 sg13g2_nor2_1 _1913_ (.A(_0495_),
    .B(_0472_),
    .Y(_0511_));
 sg13g2_buf_1 _1914_ (.A(_0511_),
    .X(_0512_));
 sg13g2_mux2_1 _1915_ (.A0(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_22_),
    .A1(net375),
    .S(net244),
    .X(_0134_));
 sg13g2_mux2_1 _1916_ (.A0(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_21_),
    .A1(net376),
    .S(net244),
    .X(_0135_));
 sg13g2_mux2_1 _1917_ (.A0(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_20_),
    .A1(net377),
    .S(net244),
    .X(_0136_));
 sg13g2_mux2_1 _1918_ (.A0(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_19_),
    .A1(net378),
    .S(net244),
    .X(_0137_));
 sg13g2_mux2_1 _1919_ (.A0(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_18_),
    .A1(net379),
    .S(net244),
    .X(_0138_));
 sg13g2_mux2_1 _1920_ (.A0(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_17_),
    .A1(net380),
    .S(net244),
    .X(_0139_));
 sg13g2_mux2_1 _1921_ (.A0(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_16_),
    .A1(net381),
    .S(_0512_),
    .X(_0140_));
 sg13g2_inv_1 _1922_ (.Y(_0513_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_14_));
 sg13g2_nand2_1 _1923_ (.Y(_0514_),
    .A(_1267_),
    .B(_0443_));
 sg13g2_nor2_1 _1924_ (.A(_0514_),
    .B(_0445_),
    .Y(_0515_));
 sg13g2_buf_1 _1925_ (.A(_0515_),
    .X(_0516_));
 sg13g2_nand2_1 _1926_ (.Y(_0517_),
    .A(net243),
    .B(net375));
 sg13g2_o21ai_1 _1927_ (.B1(_0517_),
    .Y(_0141_),
    .A1(_0513_),
    .A2(net242));
 sg13g2_inv_1 _1928_ (.Y(_0518_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_13_));
 sg13g2_nand2_1 _1929_ (.Y(_0519_),
    .A(net243),
    .B(net376));
 sg13g2_o21ai_1 _1930_ (.B1(_0519_),
    .Y(_0142_),
    .A1(_0518_),
    .A2(net242));
 sg13g2_inv_1 _1931_ (.Y(_0520_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_12_));
 sg13g2_nand2_1 _1932_ (.Y(_0521_),
    .A(net243),
    .B(net377));
 sg13g2_o21ai_1 _1933_ (.B1(_0521_),
    .Y(_0143_),
    .A1(_0520_),
    .A2(net242));
 sg13g2_inv_1 _1934_ (.Y(_0522_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_11_));
 sg13g2_nand2_1 _1935_ (.Y(_0523_),
    .A(net243),
    .B(net378));
 sg13g2_o21ai_1 _1936_ (.B1(_0523_),
    .Y(_0144_),
    .A1(_0522_),
    .A2(net242));
 sg13g2_inv_1 _1937_ (.Y(_0524_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_10_));
 sg13g2_nand2_1 _1938_ (.Y(_0525_),
    .A(net243),
    .B(net379));
 sg13g2_o21ai_1 _1939_ (.B1(_0525_),
    .Y(_0145_),
    .A1(_0524_),
    .A2(net242));
 sg13g2_inv_1 _1940_ (.Y(_0526_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_9_));
 sg13g2_nand2_1 _1941_ (.Y(_0527_),
    .A(net243),
    .B(net380));
 sg13g2_o21ai_1 _1942_ (.B1(_0527_),
    .Y(_0146_),
    .A1(_0526_),
    .A2(net242));
 sg13g2_inv_1 _1943_ (.Y(_0528_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_8_));
 sg13g2_nand2_1 _1944_ (.Y(_0529_),
    .A(net243),
    .B(net381));
 sg13g2_o21ai_1 _1945_ (.B1(_0529_),
    .Y(_0147_),
    .A1(_0528_),
    .A2(net242));
 sg13g2_nor2_1 _1946_ (.A(_0514_),
    .B(_0472_),
    .Y(_0530_));
 sg13g2_buf_1 _1947_ (.A(_0530_),
    .X(_0531_));
 sg13g2_mux2_1 _1948_ (.A0(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_6_),
    .A1(net375),
    .S(net241),
    .X(_0148_));
 sg13g2_mux2_1 _1949_ (.A0(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_5_),
    .A1(net376),
    .S(net241),
    .X(_0149_));
 sg13g2_mux2_1 _1950_ (.A0(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_4_),
    .A1(net377),
    .S(net241),
    .X(_0150_));
 sg13g2_mux2_1 _1951_ (.A0(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_3_),
    .A1(net378),
    .S(net241),
    .X(_0151_));
 sg13g2_mux2_1 _1952_ (.A0(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_2_),
    .A1(net379),
    .S(net241),
    .X(_0152_));
 sg13g2_mux2_1 _1953_ (.A0(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_1_),
    .A1(net380),
    .S(net241),
    .X(_0153_));
 sg13g2_mux2_1 _1954_ (.A0(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_0_),
    .A1(net381),
    .S(_0531_),
    .X(_0154_));
 sg13g2_nor2b_1 _1955_ (.A(_0374_),
    .B_N(net325),
    .Y(_0532_));
 sg13g2_nand2_1 _1956_ (.Y(_0533_),
    .A(_0532_),
    .B(net322));
 sg13g2_nor2_1 _1957_ (.A(net301),
    .B(_0533_),
    .Y(_0534_));
 sg13g2_inv_1 _1958_ (.Y(_0535_),
    .A(_0533_));
 sg13g2_nor2_1 _1959_ (.A(net320),
    .B(_0535_),
    .Y(_0536_));
 sg13g2_nor3_1 _1960_ (.A(net290),
    .B(_0534_),
    .C(_0536_),
    .Y(_0155_));
 sg13g2_nor2_1 _1961_ (.A(net322),
    .B(_0532_),
    .Y(_0537_));
 sg13g2_nor3_1 _1962_ (.A(net290),
    .B(_0537_),
    .C(_0535_),
    .Y(_0156_));
 sg13g2_nor2_1 _1963_ (.A(net325),
    .B(_0373_),
    .Y(_0538_));
 sg13g2_nor3_1 _1964_ (.A(net290),
    .B(_0538_),
    .C(_0532_),
    .Y(_0157_));
 sg13g2_inv_1 _1965_ (.Y(_0539_),
    .A(net338));
 sg13g2_nand4_1 _1966_ (.B(u_uart_core_uart_rx_sreg_q_10_),
    .C(u_uart_core_rx_valid),
    .A(_1216_),
    .Y(_0540_),
    .D(_0044_));
 sg13g2_xnor2_1 _1967_ (.Y(_0541_),
    .A(u_uart_core_uart_rx_sreg_q_1_),
    .B(reg2hw_40_));
 sg13g2_xor2_1 _1968_ (.B(net314),
    .A(net313),
    .X(_0542_));
 sg13g2_xor2_1 _1969_ (.B(_0542_),
    .A(_0541_),
    .X(_0543_));
 sg13g2_xor2_1 _1970_ (.B(net307),
    .A(net308),
    .X(_0544_));
 sg13g2_xnor2_1 _1971_ (.Y(_0545_),
    .A(net311),
    .B(net312));
 sg13g2_xnor2_1 _1972_ (.Y(_0546_),
    .A(net309),
    .B(net310));
 sg13g2_xor2_1 _1973_ (.B(_0546_),
    .A(_0545_),
    .X(_0547_));
 sg13g2_xnor2_1 _1974_ (.Y(_0548_),
    .A(_0544_),
    .B(_0547_));
 sg13g2_a21oi_1 _1975_ (.A1(_0548_),
    .A2(_0543_),
    .Y(_0549_),
    .B1(_0375_));
 sg13g2_o21ai_1 _1976_ (.B1(_0549_),
    .Y(_0550_),
    .A1(_0543_),
    .A2(_0548_));
 sg13g2_nand2b_2 _1977_ (.Y(_0551_),
    .B(_0550_),
    .A_N(_0540_));
 sg13g2_nor2_1 _1978_ (.A(_1203_),
    .B(_0551_),
    .Y(_0552_));
 sg13g2_inv_2 _1979_ (.Y(_0553_),
    .A(_0552_));
 sg13g2_nor2_2 _1980_ (.A(_0539_),
    .B(_0553_),
    .Y(_0554_));
 sg13g2_nand2_1 _1981_ (.Y(_0555_),
    .A(_0554_),
    .B(net337));
 sg13g2_nor2_1 _1982_ (.A(_1186_),
    .B(_0555_),
    .Y(_0556_));
 sg13g2_buf_1 _1983_ (.A(_0556_),
    .X(_0557_));
 sg13g2_inv_1 _1984_ (.Y(_0558_),
    .A(reg2hw_1_));
 sg13g2_nor2_2 _1985_ (.A(_0449_),
    .B(_0558_),
    .Y(_0559_));
 sg13g2_inv_1 _1986_ (.Y(_0560_),
    .A(_0555_));
 sg13g2_nor2_1 _1987_ (.A(net335),
    .B(_0560_),
    .Y(_0561_));
 sg13g2_nor3_1 _1988_ (.A(net203),
    .B(_0559_),
    .C(_0561_),
    .Y(_0158_));
 sg13g2_inv_2 _1989_ (.Y(_0562_),
    .A(_0559_));
 sg13g2_o21ai_1 _1990_ (.B1(_0562_),
    .Y(_0563_),
    .A1(net336),
    .A2(_0554_));
 sg13g2_nor2_1 _1991_ (.A(_0563_),
    .B(_0560_),
    .Y(_0159_));
 sg13g2_nor2_1 _1992_ (.A(net338),
    .B(_0552_),
    .Y(_0564_));
 sg13g2_nor3_1 _1993_ (.A(_0559_),
    .B(_0564_),
    .C(_0554_),
    .Y(_0160_));
 sg13g2_nand2_1 _1994_ (.Y(_0565_),
    .A(_0553_),
    .B(_0562_));
 sg13g2_a21oi_1 _1995_ (.A1(_1203_),
    .A2(_0551_),
    .Y(_0161_),
    .B1(_0565_));
 sg13g2_nor2_1 _1996_ (.A(net338),
    .B(_0553_),
    .Y(_0566_));
 sg13g2_inv_4 _1997_ (.A(net336),
    .Y(_0567_));
 sg13g2_nand3_1 _1998_ (.B(net335),
    .C(_0567_),
    .A(_0566_),
    .Y(_0568_));
 sg13g2_buf_1 _1999_ (.A(_0568_),
    .X(_0569_));
 sg13g2_nand2_1 _2000_ (.Y(_0570_),
    .A(_0408_),
    .B(net384));
 sg13g2_o21ai_1 _2001_ (.B1(_0570_),
    .Y(_0571_),
    .A1(net308),
    .A2(net383));
 sg13g2_buf_1 _2002_ (.A(_0571_),
    .X(_0572_));
 sg13g2_nand2_1 _2003_ (.Y(_0573_),
    .A(net216),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_78_));
 sg13g2_o21ai_1 _2004_ (.B1(_0573_),
    .Y(_0162_),
    .A1(net215),
    .A2(net279));
 sg13g2_nand2_1 _2005_ (.Y(_0574_),
    .A(_0410_),
    .B(net384));
 sg13g2_o21ai_1 _2006_ (.B1(_0574_),
    .Y(_0575_),
    .A1(net309),
    .A2(net383));
 sg13g2_buf_1 _2007_ (.A(_0575_),
    .X(_0576_));
 sg13g2_nand2_1 _2008_ (.Y(_0577_),
    .A(net216),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_77_));
 sg13g2_o21ai_1 _2009_ (.B1(_0577_),
    .Y(_0163_),
    .A1(net215),
    .A2(net277));
 sg13g2_nand2_1 _2010_ (.Y(_0578_),
    .A(_0412_),
    .B(net384));
 sg13g2_o21ai_1 _2011_ (.B1(_0578_),
    .Y(_0579_),
    .A1(net383),
    .A2(net310));
 sg13g2_buf_1 _2012_ (.A(_0579_),
    .X(_0580_));
 sg13g2_nand2_1 _2013_ (.Y(_0581_),
    .A(net216),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_76_));
 sg13g2_o21ai_1 _2014_ (.B1(_0581_),
    .Y(_0164_),
    .A1(net215),
    .A2(net275));
 sg13g2_nand2_1 _2015_ (.Y(_0582_),
    .A(_0414_),
    .B(net384));
 sg13g2_o21ai_1 _2016_ (.B1(_0582_),
    .Y(_0583_),
    .A1(net383),
    .A2(net311));
 sg13g2_buf_1 _2017_ (.A(_0583_),
    .X(_0584_));
 sg13g2_nand2_1 _2018_ (.Y(_0585_),
    .A(net216),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_75_));
 sg13g2_o21ai_1 _2019_ (.B1(_0585_),
    .Y(_0165_),
    .A1(net215),
    .A2(net273));
 sg13g2_nand2_1 _2020_ (.Y(_0586_),
    .A(_0416_),
    .B(net384));
 sg13g2_o21ai_1 _2021_ (.B1(_0586_),
    .Y(_0587_),
    .A1(net383),
    .A2(net312));
 sg13g2_buf_1 _2022_ (.A(_0587_),
    .X(_0588_));
 sg13g2_nand2_1 _2023_ (.Y(_0589_),
    .A(net216),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_74_));
 sg13g2_o21ai_1 _2024_ (.B1(_0589_),
    .Y(_0166_),
    .A1(net215),
    .A2(net271));
 sg13g2_nand2_1 _2025_ (.Y(_0590_),
    .A(_0418_),
    .B(net384));
 sg13g2_o21ai_1 _2026_ (.B1(_0590_),
    .Y(_0591_),
    .A1(net383),
    .A2(net313));
 sg13g2_buf_1 _2027_ (.A(_0591_),
    .X(_0592_));
 sg13g2_nand2_1 _2028_ (.Y(_0593_),
    .A(net216),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_73_));
 sg13g2_o21ai_1 _2029_ (.B1(_0593_),
    .Y(_0167_),
    .A1(net215),
    .A2(net269));
 sg13g2_nand2_1 _2030_ (.Y(_0594_),
    .A(_0420_),
    .B(net385));
 sg13g2_o21ai_1 _2031_ (.B1(_0594_),
    .Y(_0595_),
    .A1(net384),
    .A2(net314));
 sg13g2_buf_1 _2032_ (.A(_0595_),
    .X(_0596_));
 sg13g2_nand2_1 _2033_ (.Y(_0597_),
    .A(net216),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_72_));
 sg13g2_o21ai_1 _2034_ (.B1(_0597_),
    .Y(_0168_),
    .A1(net215),
    .A2(net267));
 sg13g2_nor3_1 _2035_ (.A(net339),
    .B(net338),
    .C(_0551_),
    .Y(_0598_));
 sg13g2_nand3_1 _2036_ (.B(net335),
    .C(_0567_),
    .A(_0598_),
    .Y(_0599_));
 sg13g2_buf_1 _2037_ (.A(_0599_),
    .X(_0600_));
 sg13g2_nand2_1 _2038_ (.Y(_0601_),
    .A(net232),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_70_));
 sg13g2_o21ai_1 _2039_ (.B1(_0601_),
    .Y(_0169_),
    .A1(net279),
    .A2(net231));
 sg13g2_nand2_1 _2040_ (.Y(_0602_),
    .A(net232),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_69_));
 sg13g2_o21ai_1 _2041_ (.B1(_0602_),
    .Y(_0170_),
    .A1(net277),
    .A2(net231));
 sg13g2_nand2_1 _2042_ (.Y(_0603_),
    .A(net232),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_68_));
 sg13g2_o21ai_1 _2043_ (.B1(_0603_),
    .Y(_0171_),
    .A1(net275),
    .A2(net231));
 sg13g2_nand2_1 _2044_ (.Y(_0604_),
    .A(net232),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_67_));
 sg13g2_o21ai_1 _2045_ (.B1(_0604_),
    .Y(_0172_),
    .A1(net273),
    .A2(net231));
 sg13g2_nand2_1 _2046_ (.Y(_0605_),
    .A(net232),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_66_));
 sg13g2_o21ai_1 _2047_ (.B1(_0605_),
    .Y(_0173_),
    .A1(net271),
    .A2(net231));
 sg13g2_nand2_1 _2048_ (.Y(_0606_),
    .A(net232),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_65_));
 sg13g2_o21ai_1 _2049_ (.B1(_0606_),
    .Y(_0174_),
    .A1(net269),
    .A2(net231));
 sg13g2_nand2_1 _2050_ (.Y(_0607_),
    .A(net232),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_64_));
 sg13g2_o21ai_1 _2051_ (.B1(_0607_),
    .Y(_0175_),
    .A1(net267),
    .A2(net231));
 sg13g2_nand2_1 _2052_ (.Y(_0608_),
    .A(_0560_),
    .B(net305));
 sg13g2_buf_1 _2053_ (.A(_0608_),
    .X(_0609_));
 sg13g2_nand2_1 _2054_ (.Y(_0610_),
    .A(net201),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_62_));
 sg13g2_o21ai_1 _2055_ (.B1(_0610_),
    .Y(_0176_),
    .A1(net280),
    .A2(net200));
 sg13g2_nand2_1 _2056_ (.Y(_0611_),
    .A(net201),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_61_));
 sg13g2_o21ai_1 _2057_ (.B1(_0611_),
    .Y(_0177_),
    .A1(net278),
    .A2(net200));
 sg13g2_nand2_1 _2058_ (.Y(_0612_),
    .A(net201),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_60_));
 sg13g2_o21ai_1 _2059_ (.B1(_0612_),
    .Y(_0178_),
    .A1(net276),
    .A2(net200));
 sg13g2_nand2_1 _2060_ (.Y(_0613_),
    .A(net201),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_59_));
 sg13g2_o21ai_1 _2061_ (.B1(_0613_),
    .Y(_0179_),
    .A1(net274),
    .A2(net200));
 sg13g2_nand2_1 _2062_ (.Y(_0614_),
    .A(net201),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_58_));
 sg13g2_o21ai_1 _2063_ (.B1(_0614_),
    .Y(_0180_),
    .A1(net272),
    .A2(net200));
 sg13g2_nand2_1 _2064_ (.Y(_0615_),
    .A(net201),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_57_));
 sg13g2_o21ai_1 _2065_ (.B1(_0615_),
    .Y(_0181_),
    .A1(net270),
    .A2(net200));
 sg13g2_nand2_1 _2066_ (.Y(_0616_),
    .A(net201),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_56_));
 sg13g2_o21ai_1 _2067_ (.B1(_0616_),
    .Y(_0182_),
    .A1(net268),
    .A2(net200));
 sg13g2_nor3_1 _2068_ (.A(net339),
    .B(_0539_),
    .C(_0551_),
    .Y(_0617_));
 sg13g2_nand3_1 _2069_ (.B(net305),
    .C(net336),
    .A(_0617_),
    .Y(_0618_));
 sg13g2_buf_1 _2070_ (.A(_0618_),
    .X(_0619_));
 sg13g2_nand2_1 _2071_ (.Y(_0620_),
    .A(net230),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_54_));
 sg13g2_o21ai_1 _2072_ (.B1(_0620_),
    .Y(_0183_),
    .A1(net279),
    .A2(net229));
 sg13g2_nand2_1 _2073_ (.Y(_0621_),
    .A(net230),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_53_));
 sg13g2_o21ai_1 _2074_ (.B1(_0621_),
    .Y(_0184_),
    .A1(net277),
    .A2(net229));
 sg13g2_nand2_1 _2075_ (.Y(_0622_),
    .A(net230),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_52_));
 sg13g2_o21ai_1 _2076_ (.B1(_0622_),
    .Y(_0185_),
    .A1(net275),
    .A2(net229));
 sg13g2_nand2_1 _2077_ (.Y(_0623_),
    .A(net230),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_51_));
 sg13g2_o21ai_1 _2078_ (.B1(_0623_),
    .Y(_0186_),
    .A1(net273),
    .A2(net229));
 sg13g2_nand2_1 _2079_ (.Y(_0624_),
    .A(net230),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_50_));
 sg13g2_o21ai_1 _2080_ (.B1(_0624_),
    .Y(_0187_),
    .A1(net271),
    .A2(net229));
 sg13g2_nand2_1 _2081_ (.Y(_0625_),
    .A(net230),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_49_));
 sg13g2_o21ai_1 _2082_ (.B1(_0625_),
    .Y(_0188_),
    .A1(net269),
    .A2(net229));
 sg13g2_nand2_1 _2083_ (.Y(_0626_),
    .A(net230),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_48_));
 sg13g2_o21ai_1 _2084_ (.B1(_0626_),
    .Y(_0189_),
    .A1(net267),
    .A2(net229));
 sg13g2_nand3_1 _2085_ (.B(net305),
    .C(net336),
    .A(_0566_),
    .Y(_0627_));
 sg13g2_buf_1 _2086_ (.A(_0627_),
    .X(_0628_));
 sg13g2_nand2_1 _2087_ (.Y(_0629_),
    .A(net214),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_46_));
 sg13g2_o21ai_1 _2088_ (.B1(_0629_),
    .Y(_0190_),
    .A1(net279),
    .A2(net213));
 sg13g2_nand2_1 _2089_ (.Y(_0630_),
    .A(net214),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_45_));
 sg13g2_o21ai_1 _2090_ (.B1(_0630_),
    .Y(_0191_),
    .A1(net277),
    .A2(net213));
 sg13g2_nand2_1 _2091_ (.Y(_0631_),
    .A(net214),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_44_));
 sg13g2_o21ai_1 _2092_ (.B1(_0631_),
    .Y(_0192_),
    .A1(net275),
    .A2(net213));
 sg13g2_nand2_1 _2093_ (.Y(_0632_),
    .A(net214),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_43_));
 sg13g2_o21ai_1 _2094_ (.B1(_0632_),
    .Y(_0193_),
    .A1(net273),
    .A2(net213));
 sg13g2_nand2_1 _2095_ (.Y(_0633_),
    .A(net214),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_42_));
 sg13g2_o21ai_1 _2096_ (.B1(_0633_),
    .Y(_0194_),
    .A1(net271),
    .A2(net213));
 sg13g2_nand2_1 _2097_ (.Y(_0634_),
    .A(net214),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_41_));
 sg13g2_o21ai_1 _2098_ (.B1(_0634_),
    .Y(_0195_),
    .A1(net269),
    .A2(net213));
 sg13g2_nand2_1 _2099_ (.Y(_0635_),
    .A(net214),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_40_));
 sg13g2_o21ai_1 _2100_ (.B1(_0635_),
    .Y(_0196_),
    .A1(net267),
    .A2(net213));
 sg13g2_nand3_1 _2101_ (.B(net305),
    .C(net336),
    .A(_0598_),
    .Y(_0636_));
 sg13g2_buf_1 _2102_ (.A(_0636_),
    .X(_0637_));
 sg13g2_nand2_1 _2103_ (.Y(_0638_),
    .A(net228),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_38_));
 sg13g2_o21ai_1 _2104_ (.B1(_0638_),
    .Y(_0197_),
    .A1(net279),
    .A2(net227));
 sg13g2_nand2_1 _2105_ (.Y(_0639_),
    .A(net228),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_37_));
 sg13g2_o21ai_1 _2106_ (.B1(_0639_),
    .Y(_0198_),
    .A1(net277),
    .A2(net227));
 sg13g2_nand2_1 _2107_ (.Y(_0640_),
    .A(net228),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_36_));
 sg13g2_o21ai_1 _2108_ (.B1(_0640_),
    .Y(_0199_),
    .A1(net275),
    .A2(net227));
 sg13g2_nand2_1 _2109_ (.Y(_0641_),
    .A(net228),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_35_));
 sg13g2_o21ai_1 _2110_ (.B1(_0641_),
    .Y(_0200_),
    .A1(net273),
    .A2(net227));
 sg13g2_nand2_1 _2111_ (.Y(_0642_),
    .A(net228),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_34_));
 sg13g2_o21ai_1 _2112_ (.B1(_0642_),
    .Y(_0201_),
    .A1(net271),
    .A2(net227));
 sg13g2_nand2_1 _2113_ (.Y(_0643_),
    .A(net228),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_33_));
 sg13g2_o21ai_1 _2114_ (.B1(_0643_),
    .Y(_0202_),
    .A1(net269),
    .A2(net227));
 sg13g2_nand2_1 _2115_ (.Y(_0644_),
    .A(net228),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_32_));
 sg13g2_o21ai_1 _2116_ (.B1(_0644_),
    .Y(_0203_),
    .A1(net267),
    .A2(net227));
 sg13g2_nand3_1 _2117_ (.B(net305),
    .C(_0567_),
    .A(_0554_),
    .Y(_0645_));
 sg13g2_buf_1 _2118_ (.A(_0645_),
    .X(_0646_));
 sg13g2_nand2_1 _2119_ (.Y(_0647_),
    .A(net212),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_30_));
 sg13g2_o21ai_1 _2120_ (.B1(_0647_),
    .Y(_0204_),
    .A1(net279),
    .A2(net211));
 sg13g2_nand2_1 _2121_ (.Y(_0648_),
    .A(net212),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_29_));
 sg13g2_o21ai_1 _2122_ (.B1(_0648_),
    .Y(_0205_),
    .A1(net277),
    .A2(net211));
 sg13g2_nand2_1 _2123_ (.Y(_0649_),
    .A(net212),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_28_));
 sg13g2_o21ai_1 _2124_ (.B1(_0649_),
    .Y(_0206_),
    .A1(net275),
    .A2(net211));
 sg13g2_nand2_1 _2125_ (.Y(_0650_),
    .A(net212),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_27_));
 sg13g2_o21ai_1 _2126_ (.B1(_0650_),
    .Y(_0207_),
    .A1(net273),
    .A2(net211));
 sg13g2_nand2_1 _2127_ (.Y(_0651_),
    .A(net212),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_26_));
 sg13g2_o21ai_1 _2128_ (.B1(_0651_),
    .Y(_0208_),
    .A1(net271),
    .A2(net211));
 sg13g2_nand2_1 _2129_ (.Y(_0652_),
    .A(net212),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_25_));
 sg13g2_o21ai_1 _2130_ (.B1(_0652_),
    .Y(_0209_),
    .A1(net269),
    .A2(net211));
 sg13g2_nand2_1 _2131_ (.Y(_0653_),
    .A(net212),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_24_));
 sg13g2_o21ai_1 _2132_ (.B1(_0653_),
    .Y(_0210_),
    .A1(net267),
    .A2(net211));
 sg13g2_nand3_1 _2133_ (.B(net305),
    .C(_0567_),
    .A(_0617_),
    .Y(_0654_));
 sg13g2_buf_1 _2134_ (.A(_0654_),
    .X(_0655_));
 sg13g2_nand2_1 _2135_ (.Y(_0656_),
    .A(net226),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_22_));
 sg13g2_o21ai_1 _2136_ (.B1(_0656_),
    .Y(_0211_),
    .A1(net279),
    .A2(net225));
 sg13g2_nand2_1 _2137_ (.Y(_0657_),
    .A(net226),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_21_));
 sg13g2_o21ai_1 _2138_ (.B1(_0657_),
    .Y(_0212_),
    .A1(net277),
    .A2(net225));
 sg13g2_nand2_1 _2139_ (.Y(_0658_),
    .A(net226),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_20_));
 sg13g2_o21ai_1 _2140_ (.B1(_0658_),
    .Y(_0213_),
    .A1(net275),
    .A2(net225));
 sg13g2_nand2_1 _2141_ (.Y(_0659_),
    .A(net226),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_19_));
 sg13g2_o21ai_1 _2142_ (.B1(_0659_),
    .Y(_0214_),
    .A1(net273),
    .A2(net225));
 sg13g2_nand2_1 _2143_ (.Y(_0660_),
    .A(net226),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_18_));
 sg13g2_o21ai_1 _2144_ (.B1(_0660_),
    .Y(_0215_),
    .A1(net271),
    .A2(net225));
 sg13g2_nand2_1 _2145_ (.Y(_0661_),
    .A(net226),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_17_));
 sg13g2_o21ai_1 _2146_ (.B1(_0661_),
    .Y(_0216_),
    .A1(net269),
    .A2(net225));
 sg13g2_nand2_1 _2147_ (.Y(_0662_),
    .A(net226),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_16_));
 sg13g2_o21ai_1 _2148_ (.B1(_0662_),
    .Y(_0217_),
    .A1(net267),
    .A2(net225));
 sg13g2_nand3_1 _2149_ (.B(net305),
    .C(_0567_),
    .A(_0566_),
    .Y(_0663_));
 sg13g2_buf_1 _2150_ (.A(_0663_),
    .X(_0664_));
 sg13g2_nand2_1 _2151_ (.Y(_0665_),
    .A(net210),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_14_));
 sg13g2_o21ai_1 _2152_ (.B1(_0665_),
    .Y(_0218_),
    .A1(net279),
    .A2(net209));
 sg13g2_nand2_1 _2153_ (.Y(_0666_),
    .A(net210),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_13_));
 sg13g2_o21ai_1 _2154_ (.B1(_0666_),
    .Y(_0219_),
    .A1(net277),
    .A2(net209));
 sg13g2_nand2_1 _2155_ (.Y(_0667_),
    .A(net210),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_12_));
 sg13g2_o21ai_1 _2156_ (.B1(_0667_),
    .Y(_0220_),
    .A1(net275),
    .A2(net209));
 sg13g2_nand2_1 _2157_ (.Y(_0668_),
    .A(net210),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_11_));
 sg13g2_o21ai_1 _2158_ (.B1(_0668_),
    .Y(_0221_),
    .A1(net273),
    .A2(net209));
 sg13g2_nand2_1 _2159_ (.Y(_0669_),
    .A(net210),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_10_));
 sg13g2_o21ai_1 _2160_ (.B1(_0669_),
    .Y(_0222_),
    .A1(net271),
    .A2(net209));
 sg13g2_nand2_1 _2161_ (.Y(_0670_),
    .A(net210),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_9_));
 sg13g2_o21ai_1 _2162_ (.B1(_0670_),
    .Y(_0223_),
    .A1(net269),
    .A2(net209));
 sg13g2_nand2_1 _2163_ (.Y(_0671_),
    .A(net210),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_8_));
 sg13g2_o21ai_1 _2164_ (.B1(_0671_),
    .Y(_0224_),
    .A1(net267),
    .A2(net209));
 sg13g2_nor2_1 _2165_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_126_),
    .B(net203),
    .Y(_0672_));
 sg13g2_a21oi_1 _2166_ (.A1(net202),
    .A2(net280),
    .Y(_0225_),
    .B1(_0672_));
 sg13g2_nor2_1 _2167_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_125_),
    .B(net203),
    .Y(_0673_));
 sg13g2_a21oi_1 _2168_ (.A1(net202),
    .A2(net278),
    .Y(_0226_),
    .B1(_0673_));
 sg13g2_nor2_1 _2169_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_124_),
    .B(net203),
    .Y(_0674_));
 sg13g2_a21oi_1 _2170_ (.A1(net202),
    .A2(net276),
    .Y(_0227_),
    .B1(_0674_));
 sg13g2_nor2_1 _2171_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_123_),
    .B(net203),
    .Y(_0675_));
 sg13g2_a21oi_1 _2172_ (.A1(net202),
    .A2(net274),
    .Y(_0228_),
    .B1(_0675_));
 sg13g2_nor2_1 _2173_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_122_),
    .B(net203),
    .Y(_0676_));
 sg13g2_a21oi_1 _2174_ (.A1(net202),
    .A2(net272),
    .Y(_0229_),
    .B1(_0676_));
 sg13g2_nor2_1 _2175_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_121_),
    .B(net203),
    .Y(_0677_));
 sg13g2_a21oi_1 _2176_ (.A1(net202),
    .A2(net270),
    .Y(_0230_),
    .B1(_0677_));
 sg13g2_nor2_1 _2177_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_120_),
    .B(_0557_),
    .Y(_0678_));
 sg13g2_a21oi_1 _2178_ (.A1(net202),
    .A2(net268),
    .Y(_0231_),
    .B1(_0678_));
 sg13g2_nand3_1 _2179_ (.B(net335),
    .C(net336),
    .A(_0617_),
    .Y(_0679_));
 sg13g2_buf_1 _2180_ (.A(_0679_),
    .X(_0680_));
 sg13g2_nand2_1 _2181_ (.Y(_0681_),
    .A(net224),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_118_));
 sg13g2_o21ai_1 _2182_ (.B1(_0681_),
    .Y(_0232_),
    .A1(net280),
    .A2(net223));
 sg13g2_nand2_1 _2183_ (.Y(_0682_),
    .A(net224),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_117_));
 sg13g2_o21ai_1 _2184_ (.B1(_0682_),
    .Y(_0233_),
    .A1(net278),
    .A2(net223));
 sg13g2_nand2_1 _2185_ (.Y(_0683_),
    .A(net224),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_116_));
 sg13g2_o21ai_1 _2186_ (.B1(_0683_),
    .Y(_0234_),
    .A1(net276),
    .A2(net223));
 sg13g2_nand2_1 _2187_ (.Y(_0684_),
    .A(net224),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_115_));
 sg13g2_o21ai_1 _2188_ (.B1(_0684_),
    .Y(_0235_),
    .A1(net274),
    .A2(net223));
 sg13g2_nand2_1 _2189_ (.Y(_0685_),
    .A(net224),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_114_));
 sg13g2_o21ai_1 _2190_ (.B1(_0685_),
    .Y(_0236_),
    .A1(net272),
    .A2(net223));
 sg13g2_nand2_1 _2191_ (.Y(_0686_),
    .A(net224),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_113_));
 sg13g2_o21ai_1 _2192_ (.B1(_0686_),
    .Y(_0237_),
    .A1(net270),
    .A2(net223));
 sg13g2_nand2_1 _2193_ (.Y(_0687_),
    .A(net224),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_112_));
 sg13g2_o21ai_1 _2194_ (.B1(_0687_),
    .Y(_0238_),
    .A1(net268),
    .A2(net223));
 sg13g2_nand3_1 _2195_ (.B(net335),
    .C(net336),
    .A(_0566_),
    .Y(_0688_));
 sg13g2_buf_1 _2196_ (.A(_0688_),
    .X(_0689_));
 sg13g2_nand2_1 _2197_ (.Y(_0690_),
    .A(net208),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_110_));
 sg13g2_o21ai_1 _2198_ (.B1(_0690_),
    .Y(_0239_),
    .A1(net280),
    .A2(net207));
 sg13g2_nand2_1 _2199_ (.Y(_0691_),
    .A(net208),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_109_));
 sg13g2_o21ai_1 _2200_ (.B1(_0691_),
    .Y(_0240_),
    .A1(net278),
    .A2(net207));
 sg13g2_nand2_1 _2201_ (.Y(_0692_),
    .A(net208),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_108_));
 sg13g2_o21ai_1 _2202_ (.B1(_0692_),
    .Y(_0241_),
    .A1(net276),
    .A2(net207));
 sg13g2_nand2_1 _2203_ (.Y(_0693_),
    .A(net208),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_107_));
 sg13g2_o21ai_1 _2204_ (.B1(_0693_),
    .Y(_0242_),
    .A1(net274),
    .A2(net207));
 sg13g2_nand2_1 _2205_ (.Y(_0694_),
    .A(net208),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_106_));
 sg13g2_o21ai_1 _2206_ (.B1(_0694_),
    .Y(_0243_),
    .A1(net272),
    .A2(net207));
 sg13g2_nand2_1 _2207_ (.Y(_0695_),
    .A(net208),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_105_));
 sg13g2_o21ai_1 _2208_ (.B1(_0695_),
    .Y(_0244_),
    .A1(net270),
    .A2(net207));
 sg13g2_nand2_1 _2209_ (.Y(_0696_),
    .A(net208),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_104_));
 sg13g2_o21ai_1 _2210_ (.B1(_0696_),
    .Y(_0245_),
    .A1(net268),
    .A2(net207));
 sg13g2_nand3_1 _2211_ (.B(net335),
    .C(net336),
    .A(_0598_),
    .Y(_0697_));
 sg13g2_buf_1 _2212_ (.A(_0697_),
    .X(_0698_));
 sg13g2_nand2_1 _2213_ (.Y(_0699_),
    .A(net222),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_102_));
 sg13g2_o21ai_1 _2214_ (.B1(_0699_),
    .Y(_0246_),
    .A1(net280),
    .A2(net221));
 sg13g2_nand2_1 _2215_ (.Y(_0700_),
    .A(net222),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_101_));
 sg13g2_o21ai_1 _2216_ (.B1(_0700_),
    .Y(_0247_),
    .A1(net278),
    .A2(net221));
 sg13g2_nand2_1 _2217_ (.Y(_0701_),
    .A(net222),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_100_));
 sg13g2_o21ai_1 _2218_ (.B1(_0701_),
    .Y(_0248_),
    .A1(net276),
    .A2(net221));
 sg13g2_nand2_1 _2219_ (.Y(_0702_),
    .A(net222),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_99_));
 sg13g2_o21ai_1 _2220_ (.B1(_0702_),
    .Y(_0249_),
    .A1(net274),
    .A2(net221));
 sg13g2_nand2_1 _2221_ (.Y(_0703_),
    .A(net222),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_98_));
 sg13g2_o21ai_1 _2222_ (.B1(_0703_),
    .Y(_0250_),
    .A1(net272),
    .A2(net221));
 sg13g2_nand2_1 _2223_ (.Y(_0704_),
    .A(net222),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_97_));
 sg13g2_o21ai_1 _2224_ (.B1(_0704_),
    .Y(_0251_),
    .A1(net270),
    .A2(net221));
 sg13g2_nand2_1 _2225_ (.Y(_0705_),
    .A(net222),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_96_));
 sg13g2_o21ai_1 _2226_ (.B1(_0705_),
    .Y(_0252_),
    .A1(net268),
    .A2(net221));
 sg13g2_nand3_1 _2227_ (.B(net335),
    .C(_0567_),
    .A(_0554_),
    .Y(_0706_));
 sg13g2_buf_1 _2228_ (.A(_0706_),
    .X(_0707_));
 sg13g2_nand2_1 _2229_ (.Y(_0708_),
    .A(net206),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_94_));
 sg13g2_o21ai_1 _2230_ (.B1(_0708_),
    .Y(_0253_),
    .A1(net280),
    .A2(net205));
 sg13g2_nand2_1 _2231_ (.Y(_0709_),
    .A(net206),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_93_));
 sg13g2_o21ai_1 _2232_ (.B1(_0709_),
    .Y(_0254_),
    .A1(net278),
    .A2(net205));
 sg13g2_nand2_1 _2233_ (.Y(_0710_),
    .A(net206),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_92_));
 sg13g2_o21ai_1 _2234_ (.B1(_0710_),
    .Y(_0255_),
    .A1(net276),
    .A2(net205));
 sg13g2_nand2_1 _2235_ (.Y(_0711_),
    .A(net206),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_91_));
 sg13g2_o21ai_1 _2236_ (.B1(_0711_),
    .Y(_0256_),
    .A1(net274),
    .A2(net205));
 sg13g2_nand2_1 _2237_ (.Y(_0712_),
    .A(net206),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_90_));
 sg13g2_o21ai_1 _2238_ (.B1(_0712_),
    .Y(_0257_),
    .A1(net272),
    .A2(net205));
 sg13g2_nand2_1 _2239_ (.Y(_0713_),
    .A(net206),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_89_));
 sg13g2_o21ai_1 _2240_ (.B1(_0713_),
    .Y(_0258_),
    .A1(net270),
    .A2(net205));
 sg13g2_nand2_1 _2241_ (.Y(_0714_),
    .A(net206),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_88_));
 sg13g2_o21ai_1 _2242_ (.B1(_0714_),
    .Y(_0259_),
    .A1(net268),
    .A2(net205));
 sg13g2_nand3_1 _2243_ (.B(net335),
    .C(_0567_),
    .A(_0617_),
    .Y(_0715_));
 sg13g2_buf_1 _2244_ (.A(_0715_),
    .X(_0716_));
 sg13g2_nand2_1 _2245_ (.Y(_0717_),
    .A(net220),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_86_));
 sg13g2_o21ai_1 _2246_ (.B1(_0717_),
    .Y(_0260_),
    .A1(net280),
    .A2(net219));
 sg13g2_nand2_1 _2247_ (.Y(_0718_),
    .A(net220),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_85_));
 sg13g2_o21ai_1 _2248_ (.B1(_0718_),
    .Y(_0261_),
    .A1(net278),
    .A2(net219));
 sg13g2_nand2_1 _2249_ (.Y(_0719_),
    .A(net220),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_84_));
 sg13g2_o21ai_1 _2250_ (.B1(_0719_),
    .Y(_0262_),
    .A1(net276),
    .A2(net219));
 sg13g2_nand2_1 _2251_ (.Y(_0720_),
    .A(net220),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_83_));
 sg13g2_o21ai_1 _2252_ (.B1(_0720_),
    .Y(_0263_),
    .A1(net274),
    .A2(net219));
 sg13g2_nand2_1 _2253_ (.Y(_0721_),
    .A(net220),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_82_));
 sg13g2_o21ai_1 _2254_ (.B1(_0721_),
    .Y(_0264_),
    .A1(net272),
    .A2(net219));
 sg13g2_nand2_1 _2255_ (.Y(_0722_),
    .A(net220),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_81_));
 sg13g2_o21ai_1 _2256_ (.B1(_0722_),
    .Y(_0265_),
    .A1(net270),
    .A2(net219));
 sg13g2_nand2_1 _2257_ (.Y(_0723_),
    .A(net220),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_80_));
 sg13g2_o21ai_1 _2258_ (.B1(_0723_),
    .Y(_0266_),
    .A1(net268),
    .A2(net219));
 sg13g2_nand3_1 _2259_ (.B(net305),
    .C(_0567_),
    .A(_0598_),
    .Y(_0724_));
 sg13g2_buf_1 _2260_ (.A(_0724_),
    .X(_0725_));
 sg13g2_nand2_1 _2261_ (.Y(_0726_),
    .A(net218),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_6_));
 sg13g2_o21ai_1 _2262_ (.B1(_0726_),
    .Y(_0267_),
    .A1(net280),
    .A2(net217));
 sg13g2_nand2_1 _2263_ (.Y(_0727_),
    .A(net218),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_5_));
 sg13g2_o21ai_1 _2264_ (.B1(_0727_),
    .Y(_0268_),
    .A1(net278),
    .A2(net217));
 sg13g2_nand2_1 _2265_ (.Y(_0728_),
    .A(net218),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_4_));
 sg13g2_o21ai_1 _2266_ (.B1(_0728_),
    .Y(_0269_),
    .A1(net276),
    .A2(net217));
 sg13g2_nand2_1 _2267_ (.Y(_0729_),
    .A(net218),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_3_));
 sg13g2_o21ai_1 _2268_ (.B1(_0729_),
    .Y(_0270_),
    .A1(net274),
    .A2(net217));
 sg13g2_nand2_1 _2269_ (.Y(_0730_),
    .A(net218),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_2_));
 sg13g2_o21ai_1 _2270_ (.B1(_0730_),
    .Y(_0271_),
    .A1(net272),
    .A2(net217));
 sg13g2_nand2_1 _2271_ (.Y(_0731_),
    .A(net218),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_1_));
 sg13g2_o21ai_1 _2272_ (.B1(_0731_),
    .Y(_0272_),
    .A1(net270),
    .A2(net217));
 sg13g2_nand2_1 _2273_ (.Y(_0732_),
    .A(net218),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_0_));
 sg13g2_o21ai_1 _2274_ (.B1(_0732_),
    .Y(_0273_),
    .A1(net268),
    .A2(net217));
 sg13g2_inv_1 _2275_ (.Y(_0733_),
    .A(reg_req_i[42]));
 sg13g2_inv_1 _2276_ (.Y(_0734_),
    .A(_1199_));
 sg13g2_o21ai_1 _2277_ (.B1(_0044_),
    .Y(_0735_),
    .A1(_1210_),
    .A2(_0734_));
 sg13g2_nor4_1 _2278_ (.A(reg_req_i[41]),
    .B(_0733_),
    .C(_1261_),
    .D(_0735_),
    .Y(_0736_));
 sg13g2_inv_1 _2279_ (.Y(_0737_),
    .A(_0736_));
 sg13g2_nor2_1 _2280_ (.A(net259),
    .B(_0737_),
    .Y(_0738_));
 sg13g2_nand2_1 _2281_ (.Y(_0739_),
    .A(_0738_),
    .B(net342));
 sg13g2_nor2_1 _2282_ (.A(net304),
    .B(_0739_),
    .Y(_0740_));
 sg13g2_inv_1 _2283_ (.Y(_0741_),
    .A(_0739_));
 sg13g2_nor2_1 _2284_ (.A(net340),
    .B(_0741_),
    .Y(_0742_));
 sg13g2_nor3_1 _2285_ (.A(_0559_),
    .B(_0740_),
    .C(_0742_),
    .Y(_0274_));
 sg13g2_nor2_1 _2286_ (.A(net342),
    .B(_0738_),
    .Y(_0743_));
 sg13g2_nor3_1 _2287_ (.A(_0559_),
    .B(_0743_),
    .C(_0741_),
    .Y(_0275_));
 sg13g2_nand2_1 _2288_ (.Y(_0744_),
    .A(net295),
    .B(net291));
 sg13g2_nand3_1 _2289_ (.B(_0562_),
    .C(_0744_),
    .A(net259),
    .Y(_0745_));
 sg13g2_o21ai_1 _2290_ (.B1(_0736_),
    .Y(_0746_),
    .A1(net304),
    .A2(_0739_));
 sg13g2_nand3_1 _2291_ (.B(net345),
    .C(_0562_),
    .A(_0737_),
    .Y(_0747_));
 sg13g2_o21ai_1 _2292_ (.B1(_0747_),
    .Y(_0276_),
    .A1(_0745_),
    .A2(_0746_));
 sg13g2_o21ai_1 _2293_ (.B1(_0562_),
    .Y(_0748_),
    .A1(net291),
    .A2(_0737_));
 sg13g2_a21oi_1 _2294_ (.A1(_0746_),
    .A2(net291),
    .Y(_0277_),
    .B1(_0748_));
 sg13g2_a21oi_1 _2295_ (.A1(_1175_),
    .A2(_1103_),
    .Y(_0001_),
    .B1(_1102_));
 sg13g2_inv_1 _2296_ (.Y(_0749_),
    .A(_0029_));
 sg13g2_inv_1 _2297_ (.Y(_0750_),
    .A(_0038_));
 sg13g2_nor2_1 _2298_ (.A(_0750_),
    .B(_0362_),
    .Y(_0751_));
 sg13g2_inv_1 _2299_ (.Y(_0752_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_47_));
 sg13g2_a21oi_1 _2300_ (.A1(_0752_),
    .A2(net328),
    .Y(_0753_),
    .B1(net323));
 sg13g2_o21ai_1 _2301_ (.B1(_0753_),
    .Y(_0754_),
    .A1(net327),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_39_));
 sg13g2_inv_1 _2302_ (.Y(_0755_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_63_));
 sg13g2_inv_1 _2303_ (.Y(_0756_),
    .A(net324));
 sg13g2_a21oi_1 _2304_ (.A1(_0755_),
    .A2(net329),
    .Y(_0757_),
    .B1(net299));
 sg13g2_o21ai_1 _2305_ (.B1(_0757_),
    .Y(_0758_),
    .A1(net328),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_55_));
 sg13g2_nand3_1 _2306_ (.B(_0758_),
    .C(net320),
    .A(_0754_),
    .Y(_0759_));
 sg13g2_inv_1 _2307_ (.Y(_0760_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_15_));
 sg13g2_a21oi_1 _2308_ (.A1(_0760_),
    .A2(net329),
    .Y(_0761_),
    .B1(net323));
 sg13g2_o21ai_1 _2309_ (.B1(_0761_),
    .Y(_0762_),
    .A1(net327),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_7_));
 sg13g2_inv_1 _2310_ (.Y(_0763_),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_31_));
 sg13g2_a21oi_1 _2311_ (.A1(_0763_),
    .A2(net330),
    .Y(_0764_),
    .B1(net299));
 sg13g2_o21ai_1 _2312_ (.B1(_0764_),
    .Y(_0765_),
    .A1(net328),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_23_));
 sg13g2_nand3_1 _2313_ (.B(_0765_),
    .C(net301),
    .A(_0762_),
    .Y(_0766_));
 sg13g2_nand2_1 _2314_ (.Y(_0767_),
    .A(_0759_),
    .B(_0766_));
 sg13g2_inv_1 _2315_ (.Y(_0768_),
    .A(_0767_));
 sg13g2_nor2_1 _2316_ (.A(_0768_),
    .B(_0361_),
    .Y(_0769_));
 sg13g2_o21ai_1 _2317_ (.B1(net237),
    .Y(_0770_),
    .A1(_0751_),
    .A2(_0769_));
 sg13g2_o21ai_1 _2318_ (.B1(_0770_),
    .Y(_0278_),
    .A1(_0749_),
    .A2(_0364_));
 sg13g2_a21oi_1 _2319_ (.A1(_0513_),
    .A2(net329),
    .Y(_0771_),
    .B1(net323));
 sg13g2_o21ai_1 _2320_ (.B1(_0771_),
    .Y(_0772_),
    .A1(net326),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_6_));
 sg13g2_a21oi_1 _2321_ (.A1(_0494_),
    .A2(net331),
    .Y(_0773_),
    .B1(net298));
 sg13g2_o21ai_1 _2322_ (.B1(_0773_),
    .Y(_0774_),
    .A1(net326),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_22_));
 sg13g2_nand3_1 _2323_ (.B(_0774_),
    .C(net301),
    .A(_0772_),
    .Y(_0775_));
 sg13g2_a21oi_1 _2324_ (.A1(_0476_),
    .A2(net330),
    .Y(_0776_),
    .B1(net323));
 sg13g2_o21ai_1 _2325_ (.B1(_0776_),
    .Y(_0777_),
    .A1(net326),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_38_));
 sg13g2_a21oi_1 _2326_ (.A1(_0457_),
    .A2(net331),
    .Y(_0778_),
    .B1(net298));
 sg13g2_o21ai_1 _2327_ (.B1(_0778_),
    .Y(_0779_),
    .A1(net327),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_54_));
 sg13g2_nand3_1 _2328_ (.B(_0779_),
    .C(net320),
    .A(_0777_),
    .Y(_0780_));
 sg13g2_nand3_1 _2329_ (.B(_0775_),
    .C(_0780_),
    .A(_0358_),
    .Y(_0781_));
 sg13g2_nand2_1 _2330_ (.Y(_0782_),
    .A(net257),
    .B(_0749_));
 sg13g2_o21ai_1 _2331_ (.B1(_0782_),
    .Y(_0783_),
    .A1(net257),
    .A2(_0781_));
 sg13g2_nand2_1 _2332_ (.Y(_0784_),
    .A(net250),
    .B(_0030_));
 sg13g2_o21ai_1 _2333_ (.B1(_0784_),
    .Y(_0279_),
    .A1(_0783_),
    .A2(_0371_));
 sg13g2_inv_1 _2334_ (.Y(_0785_),
    .A(_0031_));
 sg13g2_nor2b_1 _2335_ (.A(_0362_),
    .B_N(_0030_),
    .Y(_0786_));
 sg13g2_a21oi_1 _2336_ (.A1(_0480_),
    .A2(net328),
    .Y(_0787_),
    .B1(net322));
 sg13g2_o21ai_1 _2337_ (.B1(_0787_),
    .Y(_0788_),
    .A1(net325),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_37_));
 sg13g2_a21oi_1 _2338_ (.A1(_0459_),
    .A2(net329),
    .Y(_0789_),
    .B1(net298));
 sg13g2_o21ai_1 _2339_ (.B1(_0789_),
    .Y(_0790_),
    .A1(net325),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_53_));
 sg13g2_nand3_1 _2340_ (.B(_0790_),
    .C(net320),
    .A(_0788_),
    .Y(_0791_));
 sg13g2_a21oi_1 _2341_ (.A1(_0518_),
    .A2(net328),
    .Y(_0792_),
    .B1(net322));
 sg13g2_o21ai_1 _2342_ (.B1(_0792_),
    .Y(_0793_),
    .A1(net325),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_5_));
 sg13g2_a21oi_1 _2343_ (.A1(_0499_),
    .A2(net330),
    .Y(_0794_),
    .B1(net298));
 sg13g2_o21ai_1 _2344_ (.B1(_0794_),
    .Y(_0795_),
    .A1(net326),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_21_));
 sg13g2_nand3_1 _2345_ (.B(_0795_),
    .C(net301),
    .A(_0793_),
    .Y(_0796_));
 sg13g2_nand2_1 _2346_ (.Y(_0797_),
    .A(_0791_),
    .B(_0796_));
 sg13g2_nor2b_1 _2347_ (.A(net257),
    .B_N(_0797_),
    .Y(_0798_));
 sg13g2_o21ai_1 _2348_ (.B1(net237),
    .Y(_0799_),
    .A1(_0786_),
    .A2(_0798_));
 sg13g2_o21ai_1 _2349_ (.B1(_0799_),
    .Y(_0280_),
    .A1(_0785_),
    .A2(_0364_));
 sg13g2_inv_1 _2350_ (.Y(_0800_),
    .A(_0032_));
 sg13g2_nor2_1 _2351_ (.A(_0785_),
    .B(_0362_),
    .Y(_0801_));
 sg13g2_a21oi_1 _2352_ (.A1(_0482_),
    .A2(net328),
    .Y(_0802_),
    .B1(net322));
 sg13g2_o21ai_1 _2353_ (.B1(_0802_),
    .Y(_0803_),
    .A1(net326),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_36_));
 sg13g2_a21oi_1 _2354_ (.A1(_0461_),
    .A2(net330),
    .Y(_0804_),
    .B1(net298));
 sg13g2_o21ai_1 _2355_ (.B1(_0804_),
    .Y(_0805_),
    .A1(net326),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_52_));
 sg13g2_nand3_1 _2356_ (.B(_0805_),
    .C(net320),
    .A(_0803_),
    .Y(_0806_));
 sg13g2_a21oi_1 _2357_ (.A1(_0520_),
    .A2(net329),
    .Y(_0807_),
    .B1(net322));
 sg13g2_o21ai_1 _2358_ (.B1(_0807_),
    .Y(_0808_),
    .A1(net326),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_4_));
 sg13g2_a21oi_1 _2359_ (.A1(_0501_),
    .A2(net330),
    .Y(_0809_),
    .B1(net298));
 sg13g2_o21ai_1 _2360_ (.B1(_0809_),
    .Y(_0810_),
    .A1(net327),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_20_));
 sg13g2_nand3_1 _2361_ (.B(_0810_),
    .C(net301),
    .A(_0808_),
    .Y(_0811_));
 sg13g2_nand2_1 _2362_ (.Y(_0812_),
    .A(_0806_),
    .B(_0811_));
 sg13g2_nor2b_1 _2363_ (.A(_0361_),
    .B_N(_0812_),
    .Y(_0813_));
 sg13g2_o21ai_1 _2364_ (.B1(net237),
    .Y(_0814_),
    .A1(_0801_),
    .A2(_0813_));
 sg13g2_o21ai_1 _2365_ (.B1(_0814_),
    .Y(_0281_),
    .A1(_0800_),
    .A2(_0364_));
 sg13g2_inv_1 _2366_ (.Y(_0815_),
    .A(_0033_));
 sg13g2_nor2_1 _2367_ (.A(_0800_),
    .B(_0362_),
    .Y(_0816_));
 sg13g2_a21oi_1 _2368_ (.A1(_0484_),
    .A2(net328),
    .Y(_0817_),
    .B1(net323));
 sg13g2_o21ai_1 _2369_ (.B1(_0817_),
    .Y(_0818_),
    .A1(net327),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_35_));
 sg13g2_a21oi_1 _2370_ (.A1(_0463_),
    .A2(net329),
    .Y(_0819_),
    .B1(net299));
 sg13g2_o21ai_1 _2371_ (.B1(_0819_),
    .Y(_0820_),
    .A1(net327),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_51_));
 sg13g2_nand3_1 _2372_ (.B(_0820_),
    .C(net320),
    .A(_0818_),
    .Y(_0821_));
 sg13g2_a21oi_1 _2373_ (.A1(_0522_),
    .A2(net328),
    .Y(_0822_),
    .B1(net323));
 sg13g2_o21ai_1 _2374_ (.B1(_0822_),
    .Y(_0823_),
    .A1(net327),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_3_));
 sg13g2_a21oi_1 _2375_ (.A1(_0503_),
    .A2(net330),
    .Y(_0824_),
    .B1(net299));
 sg13g2_o21ai_1 _2376_ (.B1(_0824_),
    .Y(_0825_),
    .A1(net327),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_19_));
 sg13g2_nand3_1 _2377_ (.B(_0825_),
    .C(net301),
    .A(_0823_),
    .Y(_0826_));
 sg13g2_nand2_1 _2378_ (.Y(_0827_),
    .A(_0821_),
    .B(_0826_));
 sg13g2_nor2b_1 _2379_ (.A(_0361_),
    .B_N(_0827_),
    .Y(_0828_));
 sg13g2_o21ai_1 _2380_ (.B1(net237),
    .Y(_0829_),
    .A1(_0816_),
    .A2(_0828_));
 sg13g2_o21ai_1 _2381_ (.B1(_0829_),
    .Y(_0282_),
    .A1(_0815_),
    .A2(_0364_));
 sg13g2_a21oi_1 _2382_ (.A1(_0524_),
    .A2(net329),
    .Y(_0830_),
    .B1(net322));
 sg13g2_o21ai_1 _2383_ (.B1(_0830_),
    .Y(_0831_),
    .A1(net325),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_2_));
 sg13g2_a21oi_1 _2384_ (.A1(_0505_),
    .A2(net330),
    .Y(_0832_),
    .B1(net298));
 sg13g2_o21ai_1 _2385_ (.B1(_0832_),
    .Y(_0833_),
    .A1(net325),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_18_));
 sg13g2_nand3_1 _2386_ (.B(_0833_),
    .C(net301),
    .A(_0831_),
    .Y(_0834_));
 sg13g2_a21oi_1 _2387_ (.A1(_0486_),
    .A2(net329),
    .Y(_0835_),
    .B1(net322));
 sg13g2_o21ai_1 _2388_ (.B1(_0835_),
    .Y(_0836_),
    .A1(net325),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_34_));
 sg13g2_a21oi_1 _2389_ (.A1(_0465_),
    .A2(net330),
    .Y(_0837_),
    .B1(net298));
 sg13g2_o21ai_1 _2390_ (.B1(_0837_),
    .Y(_0838_),
    .A1(net326),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_50_));
 sg13g2_nand3_1 _2391_ (.B(_0838_),
    .C(net320),
    .A(_0836_),
    .Y(_0839_));
 sg13g2_nand3_1 _2392_ (.B(_0834_),
    .C(_0839_),
    .A(_0358_),
    .Y(_0840_));
 sg13g2_nand2_1 _2393_ (.Y(_0841_),
    .A(net257),
    .B(_0815_));
 sg13g2_o21ai_1 _2394_ (.B1(_0841_),
    .Y(_0842_),
    .A1(net257),
    .A2(_0840_));
 sg13g2_nand2_1 _2395_ (.Y(_0843_),
    .A(net250),
    .B(_0034_));
 sg13g2_o21ai_1 _2396_ (.B1(_0843_),
    .Y(_0283_),
    .A1(_0842_),
    .A2(_0371_));
 sg13g2_inv_1 _2397_ (.Y(_0844_),
    .A(_0035_));
 sg13g2_nor2b_1 _2398_ (.A(_0362_),
    .B_N(_0034_),
    .Y(_0845_));
 sg13g2_a21oi_1 _2399_ (.A1(_0488_),
    .A2(net333),
    .Y(_0846_),
    .B1(net324));
 sg13g2_o21ai_1 _2400_ (.B1(_0846_),
    .Y(_0847_),
    .A1(net333),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_33_));
 sg13g2_nor2b_1 _2401_ (.A(_1265_),
    .B_N(_0847_),
    .Y(_0848_));
 sg13g2_a21oi_1 _2402_ (.A1(_0467_),
    .A2(net331),
    .Y(_0849_),
    .B1(net299));
 sg13g2_o21ai_1 _2403_ (.B1(_0849_),
    .Y(_0850_),
    .A1(net331),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_49_));
 sg13g2_a21oi_1 _2404_ (.A1(_0526_),
    .A2(net331),
    .Y(_0851_),
    .B1(net324));
 sg13g2_o21ai_1 _2405_ (.B1(_0851_),
    .Y(_0852_),
    .A1(net331),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_1_));
 sg13g2_a21oi_1 _2406_ (.A1(_0507_),
    .A2(net333),
    .Y(_0853_),
    .B1(_0756_));
 sg13g2_o21ai_1 _2407_ (.B1(_0853_),
    .Y(_0854_),
    .A1(net333),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_17_));
 sg13g2_nor2b_1 _2408_ (.A(net321),
    .B_N(_0854_),
    .Y(_0855_));
 sg13g2_a22oi_1 _2409_ (.Y(_0856_),
    .B1(_0852_),
    .B2(_0855_),
    .A2(_0850_),
    .A1(_0848_));
 sg13g2_nor2_1 _2410_ (.A(_0856_),
    .B(_0361_),
    .Y(_0857_));
 sg13g2_o21ai_1 _2411_ (.B1(net237),
    .Y(_0858_),
    .A1(_0845_),
    .A2(_0857_));
 sg13g2_o21ai_1 _2412_ (.B1(_0858_),
    .Y(_0284_),
    .A1(_0844_),
    .A2(_0364_));
 sg13g2_a21oi_1 _2413_ (.A1(_0528_),
    .A2(net332),
    .Y(_0859_),
    .B1(net323));
 sg13g2_o21ai_1 _2414_ (.B1(_0859_),
    .Y(_0860_),
    .A1(net331),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_0_));
 sg13g2_a21oi_1 _2415_ (.A1(_0509_),
    .A2(net332),
    .Y(_0861_),
    .B1(net299));
 sg13g2_o21ai_1 _2416_ (.B1(_0861_),
    .Y(_0862_),
    .A1(net332),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_16_));
 sg13g2_nand3_1 _2417_ (.B(_0862_),
    .C(net301),
    .A(_0860_),
    .Y(_0863_));
 sg13g2_a21oi_1 _2418_ (.A1(_0490_),
    .A2(net332),
    .Y(_0864_),
    .B1(net323));
 sg13g2_o21ai_1 _2419_ (.B1(_0864_),
    .Y(_0865_),
    .A1(net331),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_32_));
 sg13g2_a21oi_1 _2420_ (.A1(_0469_),
    .A2(net333),
    .Y(_0866_),
    .B1(net299));
 sg13g2_o21ai_1 _2421_ (.B1(_0866_),
    .Y(_0867_),
    .A1(net332),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_48_));
 sg13g2_nand3_1 _2422_ (.B(_0867_),
    .C(net320),
    .A(_0865_),
    .Y(_0868_));
 sg13g2_nand3_1 _2423_ (.B(_0863_),
    .C(_0868_),
    .A(_0358_),
    .Y(_0869_));
 sg13g2_nand2_1 _2424_ (.Y(_0870_),
    .A(net257),
    .B(_0844_));
 sg13g2_o21ai_1 _2425_ (.B1(_0870_),
    .Y(_0871_),
    .A1(net257),
    .A2(_0869_));
 sg13g2_nand2_1 _2426_ (.Y(_0872_),
    .A(net250),
    .B(_0036_));
 sg13g2_o21ai_1 _2427_ (.B1(_0872_),
    .Y(_0285_),
    .A1(_0871_),
    .A2(_0371_));
 sg13g2_inv_1 _2428_ (.Y(_0873_),
    .A(_0037_));
 sg13g2_o21ai_1 _2429_ (.B1(net237),
    .Y(_0874_),
    .A1(_0036_),
    .A2(_0362_));
 sg13g2_o21ai_1 _2430_ (.B1(_0874_),
    .Y(_0286_),
    .A1(_0873_),
    .A2(_0364_));
 sg13g2_nor2_1 _2431_ (.A(_0357_),
    .B(_0827_),
    .Y(_0875_));
 sg13g2_nor2b_1 _2432_ (.A(_0840_),
    .B_N(_0827_),
    .Y(_0876_));
 sg13g2_a21oi_1 _2433_ (.A1(_0840_),
    .A2(_0875_),
    .Y(_0877_),
    .B1(_0876_));
 sg13g2_inv_1 _2434_ (.Y(_0878_),
    .A(reg2hw_40_));
 sg13g2_nand3_1 _2435_ (.B(_0358_),
    .C(_0856_),
    .A(_0869_),
    .Y(_0879_));
 sg13g2_o21ai_1 _2436_ (.B1(_0879_),
    .Y(_0880_),
    .A1(_0856_),
    .A2(_0869_));
 sg13g2_xnor2_1 _2437_ (.Y(_0881_),
    .A(_0878_),
    .B(_0880_));
 sg13g2_xor2_1 _2438_ (.B(_0881_),
    .A(_0877_),
    .X(_0882_));
 sg13g2_a21oi_1 _2439_ (.A1(_0797_),
    .A2(_0812_),
    .Y(_0883_),
    .B1(_0357_));
 sg13g2_o21ai_1 _2440_ (.B1(_0883_),
    .Y(_0884_),
    .A1(_0797_),
    .A2(_0812_));
 sg13g2_nor2_1 _2441_ (.A(_0357_),
    .B(_0767_),
    .Y(_0885_));
 sg13g2_nor2_1 _2442_ (.A(_0768_),
    .B(_0781_),
    .Y(_0886_));
 sg13g2_a21oi_1 _2443_ (.A1(_0885_),
    .A2(_0781_),
    .Y(_0887_),
    .B1(_0886_));
 sg13g2_xor2_1 _2444_ (.B(_0887_),
    .A(_0884_),
    .X(_0888_));
 sg13g2_o21ai_1 _2445_ (.B1(_0376_),
    .Y(_0889_),
    .A1(_0888_),
    .A2(_0882_));
 sg13g2_a21o_1 _2446_ (.A2(_0888_),
    .A1(_0882_),
    .B1(_0889_),
    .X(_0890_));
 sg13g2_o21ai_1 _2447_ (.B1(_0890_),
    .Y(_0287_),
    .A1(_0750_),
    .A2(_0364_));
 sg13g2_nor4_1 _2448_ (.A(u_uart_core_uart_rx_bit_cnt_q_2_),
    .B(u_uart_core_uart_rx_bit_cnt_q_3_),
    .C(_0382_),
    .D(_0429_),
    .Y(_0000_));
 sg13g2_nor3_2 _2449_ (.A(_1336_),
    .B(_1334_),
    .C(_1342_),
    .Y(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_));
 sg13g2_nand2_1 _2450_ (.Y(_0891_),
    .A(rx_i),
    .B(net387));
 sg13g2_o21ai_1 _2451_ (.B1(_0891_),
    .Y(tx_o),
    .A1(net387),
    .A2(_0043_));
 sg13g2_o21ai_1 _2452_ (.B1(_0562_),
    .Y(_0892_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .A2(_0740_));
 sg13g2_a21oi_1 _2453_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .A2(_0740_),
    .Y(_0288_),
    .B1(_0892_));
 sg13g2_nand2_1 _2454_ (.Y(_0893_),
    .A(_0406_),
    .B(net384));
 sg13g2_o21ai_1 _2455_ (.B1(_0893_),
    .Y(_0894_),
    .A1(net383),
    .A2(net307));
 sg13g2_buf_1 _2456_ (.A(_0894_),
    .X(_0895_));
 sg13g2_nand2_1 _2457_ (.Y(_0896_),
    .A(net218),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_7_));
 sg13g2_o21ai_1 _2458_ (.B1(_0896_),
    .Y(_0289_),
    .A1(net217),
    .A2(net265));
 sg13g2_nand2_1 _2459_ (.Y(_0897_),
    .A(net220),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_87_));
 sg13g2_o21ai_1 _2460_ (.B1(_0897_),
    .Y(_0290_),
    .A1(net219),
    .A2(net265));
 sg13g2_nand2_1 _2461_ (.Y(_0898_),
    .A(net206),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_95_));
 sg13g2_o21ai_1 _2462_ (.B1(_0898_),
    .Y(_0291_),
    .A1(net205),
    .A2(net265));
 sg13g2_nand2_1 _2463_ (.Y(_0899_),
    .A(net222),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_103_));
 sg13g2_o21ai_1 _2464_ (.B1(_0899_),
    .Y(_0292_),
    .A1(net221),
    .A2(net265));
 sg13g2_nand2_1 _2465_ (.Y(_0900_),
    .A(net208),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_111_));
 sg13g2_o21ai_1 _2466_ (.B1(_0900_),
    .Y(_0293_),
    .A1(net207),
    .A2(net265));
 sg13g2_nand2_1 _2467_ (.Y(_0901_),
    .A(net224),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_119_));
 sg13g2_o21ai_1 _2468_ (.B1(_0901_),
    .Y(_0294_),
    .A1(net223),
    .A2(net265));
 sg13g2_nor2_1 _2469_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_127_),
    .B(_0557_),
    .Y(_0902_));
 sg13g2_a21oi_1 _2470_ (.A1(net202),
    .A2(net266),
    .Y(_0295_),
    .B1(_0902_));
 sg13g2_nand2_1 _2471_ (.Y(_0903_),
    .A(net210),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_15_));
 sg13g2_o21ai_1 _2472_ (.B1(_0903_),
    .Y(_0296_),
    .A1(net209),
    .A2(net265));
 sg13g2_nand2_1 _2473_ (.Y(_0904_),
    .A(net226),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_23_));
 sg13g2_o21ai_1 _2474_ (.B1(_0904_),
    .Y(_0297_),
    .A1(net225),
    .A2(net265));
 sg13g2_nand2_1 _2475_ (.Y(_0905_),
    .A(net212),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_31_));
 sg13g2_o21ai_1 _2476_ (.B1(_0905_),
    .Y(_0298_),
    .A1(net211),
    .A2(net266));
 sg13g2_nand2_1 _2477_ (.Y(_0906_),
    .A(net228),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_39_));
 sg13g2_o21ai_1 _2478_ (.B1(_0906_),
    .Y(_0299_),
    .A1(net227),
    .A2(net266));
 sg13g2_nand2_1 _2479_ (.Y(_0907_),
    .A(net214),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_47_));
 sg13g2_o21ai_1 _2480_ (.B1(_0907_),
    .Y(_0300_),
    .A1(net213),
    .A2(net266));
 sg13g2_nand2_1 _2481_ (.Y(_0908_),
    .A(net230),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_55_));
 sg13g2_o21ai_1 _2482_ (.B1(_0908_),
    .Y(_0301_),
    .A1(net229),
    .A2(net266));
 sg13g2_nand2_1 _2483_ (.Y(_0909_),
    .A(net201),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_63_));
 sg13g2_o21ai_1 _2484_ (.B1(_0909_),
    .Y(_0302_),
    .A1(net200),
    .A2(net266));
 sg13g2_nand2_1 _2485_ (.Y(_0910_),
    .A(net232),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_71_));
 sg13g2_o21ai_1 _2486_ (.B1(_0910_),
    .Y(_0303_),
    .A1(net231),
    .A2(net266));
 sg13g2_nand2_1 _2487_ (.Y(_0911_),
    .A(net216),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_79_));
 sg13g2_o21ai_1 _2488_ (.B1(_0911_),
    .Y(_0304_),
    .A1(net215),
    .A2(net266));
 sg13g2_o21ai_1 _2489_ (.B1(_0562_),
    .Y(_0912_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .A2(_0557_));
 sg13g2_a21oi_1 _2490_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .A2(net203),
    .Y(_0305_),
    .B1(_0912_));
 sg13g2_nor2_1 _2491_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .B(_0534_),
    .Y(_0913_));
 sg13g2_and2_1 _2492_ (.A(_0534_),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .X(_0914_));
 sg13g2_nor3_1 _2493_ (.A(net290),
    .B(_0913_),
    .C(_0914_),
    .Y(_0306_));
 sg13g2_inv_2 _2494_ (.Y(_0915_),
    .A(net374));
 sg13g2_nor2_1 _2495_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_7_),
    .B(net241),
    .Y(_0916_));
 sg13g2_a21oi_1 _2496_ (.A1(_0915_),
    .A2(net241),
    .Y(_0307_),
    .B1(_0916_));
 sg13g2_nand2_1 _2497_ (.Y(_0917_),
    .A(net243),
    .B(net374));
 sg13g2_o21ai_1 _2498_ (.B1(_0917_),
    .Y(_0308_),
    .A1(_0760_),
    .A2(net242));
 sg13g2_nor2_1 _2499_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_23_),
    .B(net244),
    .Y(_0918_));
 sg13g2_a21oi_1 _2500_ (.A1(_0915_),
    .A2(net244),
    .Y(_0309_),
    .B1(_0918_));
 sg13g2_nand2_1 _2501_ (.Y(_0919_),
    .A(net246),
    .B(net374));
 sg13g2_o21ai_1 _2502_ (.B1(_0919_),
    .Y(_0310_),
    .A1(_0763_),
    .A2(net245));
 sg13g2_nand2_1 _2503_ (.Y(_0920_),
    .A(net233),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_39_));
 sg13g2_o21ai_1 _2504_ (.B1(_0920_),
    .Y(_0311_),
    .A1(_0915_),
    .A2(net233));
 sg13g2_nand2_1 _2505_ (.Y(_0921_),
    .A(net248),
    .B(net374));
 sg13g2_o21ai_1 _2506_ (.B1(_0921_),
    .Y(_0312_),
    .A1(_0752_),
    .A2(net247));
 sg13g2_nand2_1 _2507_ (.Y(_0922_),
    .A(net234),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_55_));
 sg13g2_o21ai_1 _2508_ (.B1(_0922_),
    .Y(_0313_),
    .A1(_0915_),
    .A2(net234));
 sg13g2_nand2_1 _2509_ (.Y(_0923_),
    .A(net236),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_63_));
 sg13g2_o21ai_1 _2510_ (.B1(_0923_),
    .Y(_0314_),
    .A1(_0915_),
    .A2(net235));
 sg13g2_nor2b_1 _2511_ (.A(_0452_),
    .B_N(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .Y(_0924_));
 sg13g2_nor2_1 _2512_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .B(_0453_),
    .Y(_0925_));
 sg13g2_nor3_1 _2513_ (.A(net290),
    .B(_0924_),
    .C(_0925_),
    .Y(_0315_));
 sg13g2_inv_1 _2514_ (.Y(_0926_),
    .A(u_uart_core_uart_rx_baud_div_q_3_));
 sg13g2_nor4_1 _2515_ (.A(_0434_),
    .B(_0926_),
    .C(_0436_),
    .D(_0393_),
    .Y(u_uart_core_uart_rx_tick_baud_d));
 sg13g2_a21oi_1 _2516_ (.A1(_0926_),
    .A2(_0438_),
    .Y(_0316_),
    .B1(u_uart_core_uart_rx_tick_baud_d));
 sg13g2_xnor2_1 _2517_ (.Y(_0927_),
    .A(_0396_),
    .B(_0424_));
 sg13g2_a21oi_1 _2518_ (.A1(_0392_),
    .A2(_0396_),
    .Y(_0928_),
    .B1(_0383_));
 sg13g2_a21o_1 _2519_ (.A2(_0927_),
    .A1(net256),
    .B1(_0928_),
    .X(_0317_));
 sg13g2_nor2_1 _2520_ (.A(_1332_),
    .B(_0000_),
    .Y(_0929_));
 sg13g2_o21ai_1 _2521_ (.B1(_0929_),
    .Y(_0930_),
    .A1(_0382_),
    .A2(_0399_));
 sg13g2_nand2_1 _2522_ (.Y(_0318_),
    .A(_0930_),
    .B(_0392_));
 sg13g2_inv_1 _2523_ (.Y(_0931_),
    .A(u_uart_core_uart_rx_sreg_q_10_));
 sg13g2_nand2b_1 _2524_ (.Y(_0932_),
    .B(net256),
    .A_N(_0391_));
 sg13g2_o21ai_1 _2525_ (.B1(_0932_),
    .Y(_0319_),
    .A1(_0931_),
    .A2(_0401_));
 sg13g2_nand2_1 _2526_ (.Y(_0933_),
    .A(_0380_),
    .B(u_uart_core_uart_tx_baud_div_q_2_));
 sg13g2_xnor2_1 _2527_ (.Y(_0320_),
    .A(u_uart_core_uart_tx_baud_div_q_3_),
    .B(_0933_));
 sg13g2_a21oi_1 _2528_ (.A1(_0350_),
    .A2(_0348_),
    .Y(_0934_),
    .B1(_0349_));
 sg13g2_o21ai_1 _2529_ (.B1(u_uart_core_uart_tx_bit_cnt_q_3_),
    .Y(_0935_),
    .A1(_0934_),
    .A2(net250));
 sg13g2_nand2_1 _2530_ (.Y(_0321_),
    .A(_0935_),
    .B(_0374_));
 sg13g2_nand3_1 _2531_ (.B(_0037_),
    .C(net382),
    .A(_0354_),
    .Y(_0936_));
 sg13g2_o21ai_1 _2532_ (.B1(_0936_),
    .Y(_0322_),
    .A1(_1087_),
    .A2(_0356_));
 sg13g2_nand2_1 _2533_ (.Y(_0937_),
    .A(net251),
    .B(reg_req_i[9]));
 sg13g2_o21ai_1 _2534_ (.B1(_0937_),
    .Y(_0323_),
    .A1(_0388_),
    .A2(net239));
 sg13g2_inv_1 _2535_ (.Y(_0938_),
    .A(reg2hw_56_));
 sg13g2_nand2_1 _2536_ (.Y(_0939_),
    .A(net251),
    .B(reg_req_i[35]));
 sg13g2_o21ai_1 _2537_ (.B1(_0939_),
    .Y(_0324_),
    .A1(_0938_),
    .A2(net240));
 sg13g2_nand2_1 _2538_ (.Y(_0940_),
    .A(net251),
    .B(reg_req_i[6]));
 sg13g2_o21ai_1 _2539_ (.B1(_0940_),
    .Y(_0325_),
    .A1(_0385_),
    .A2(net240));
 sg13g2_nand2_1 _2540_ (.Y(_0941_),
    .A(net251),
    .B(reg_req_i[10]));
 sg13g2_o21ai_1 _2541_ (.B1(_0941_),
    .Y(_0326_),
    .A1(_0375_),
    .A2(net240));
 sg13g2_nand2_1 _2542_ (.Y(_0942_),
    .A(net251),
    .B(reg_req_i[11]));
 sg13g2_o21ai_1 _2543_ (.B1(_0942_),
    .Y(_0327_),
    .A1(_0878_),
    .A2(net240));
 sg13g2_mux2_1 _2544_ (.A0(reg2hw_35_),
    .A1(reg_req_i[5]),
    .S(_1347_),
    .X(_0328_));
 sg13g2_nand2_1 _2545_ (.Y(_0943_),
    .A(net251),
    .B(reg_req_i[8]));
 sg13g2_o21ai_1 _2546_ (.B1(_0943_),
    .Y(_0329_),
    .A1(_0384_),
    .A2(net240));
 sg13g2_nand2_1 _2547_ (.Y(_0944_),
    .A(net251),
    .B(reg_req_i[4]));
 sg13g2_o21ai_1 _2548_ (.B1(_0944_),
    .Y(_0330_),
    .A1(_0349_),
    .A2(net240));
 sg13g2_nand2_1 _2549_ (.Y(_0945_),
    .A(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .B(reg_req_i[4]));
 sg13g2_o21ai_1 _2550_ (.B1(_0945_),
    .Y(_0331_),
    .A1(_0558_),
    .A2(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_));
 sg13g2_nand2_1 _2551_ (.Y(_0946_),
    .A(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .B(reg_req_i[5]));
 sg13g2_o21ai_1 _2552_ (.B1(_0946_),
    .Y(_0332_),
    .A1(_0448_),
    .A2(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_));
 sg13g2_nand2_1 _2553_ (.Y(_0947_),
    .A(net253),
    .B(reg_req_i[11]));
 sg13g2_o21ai_1 _2554_ (.B1(_0947_),
    .Y(_0333_),
    .A1(_0915_),
    .A2(net253));
 sg13g2_a21oi_1 _2555_ (.A1(_1341_),
    .A2(net264),
    .Y(u_uart_reg_reg_rsp_o_1_),
    .B1(_0733_));
 sg13g2_o21ai_1 _2556_ (.B1(net264),
    .Y(u_uart_reg_reg_rsp_o_33_),
    .A1(_0938_),
    .A2(_1093_));
 sg13g2_nor2b_1 _2557_ (.A(_0933_),
    .B_N(u_uart_core_uart_tx_baud_div_q_3_),
    .Y(_1350_));
 sg13g2_o21ai_1 _2558_ (.B1(net264),
    .Y(u_uart_reg_reg_rsp_o_25_),
    .A1(_1136_),
    .A2(_1093_));
 sg13g2_a22oi_1 _2559_ (.Y(_0948_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_63_),
    .B2(net281),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_55_),
    .A1(net283));
 sg13g2_inv_1 _2560_ (.Y(_0949_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_47_));
 sg13g2_a21oi_1 _2561_ (.A1(_0949_),
    .A2(net347),
    .Y(_0950_),
    .B1(net345));
 sg13g2_o21ai_1 _2562_ (.B1(_0950_),
    .Y(_0951_),
    .A1(net347),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_39_));
 sg13g2_a21oi_1 _2563_ (.A1(_0948_),
    .A2(_0951_),
    .Y(_0952_),
    .B1(net302));
 sg13g2_a22oi_1 _2564_ (.Y(_0953_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_31_),
    .B2(net281),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_23_),
    .A1(net283));
 sg13g2_inv_1 _2565_ (.Y(_0954_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_15_));
 sg13g2_a21oi_1 _2566_ (.A1(_0954_),
    .A2(net347),
    .Y(_0955_),
    .B1(net345));
 sg13g2_o21ai_1 _2567_ (.B1(_0955_),
    .Y(_0956_),
    .A1(net347),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_7_));
 sg13g2_a21oi_1 _2568_ (.A1(_0953_),
    .A2(_0956_),
    .Y(_0957_),
    .B1(net342));
 sg13g2_nor3_1 _2569_ (.A(net340),
    .B(_0952_),
    .C(_0957_),
    .Y(_0958_));
 sg13g2_nand2b_1 _2570_ (.Y(_0959_),
    .B(net291),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_103_));
 sg13g2_inv_1 _2571_ (.Y(_0960_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_111_));
 sg13g2_a21oi_1 _2572_ (.A1(_0960_),
    .A2(net348),
    .Y(_0961_),
    .B1(net345));
 sg13g2_a21o_1 _2573_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_119_),
    .A1(net283),
    .B1(net303),
    .X(_0962_));
 sg13g2_a221oi_1 _2574_ (.B2(_0961_),
    .C1(_0962_),
    .B1(_0959_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_127_),
    .Y(_0963_),
    .A2(net281));
 sg13g2_inv_1 _2575_ (.Y(_0964_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_79_));
 sg13g2_o21ai_1 _2576_ (.B1(net296),
    .Y(_0965_),
    .A1(net351),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_71_));
 sg13g2_a21oi_1 _2577_ (.A1(net348),
    .A2(_0964_),
    .Y(_0966_),
    .B1(_0965_));
 sg13g2_nor2b_1 _2578_ (.A(net261),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_87_),
    .Y(_0967_));
 sg13g2_nor2b_1 _2579_ (.A(net260),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_95_),
    .Y(_0968_));
 sg13g2_nor4_1 _2580_ (.A(net343),
    .B(_0966_),
    .C(_0967_),
    .D(_0968_),
    .Y(_0969_));
 sg13g2_o21ai_1 _2581_ (.B1(net340),
    .Y(_0970_),
    .A1(_0963_),
    .A2(_0969_));
 sg13g2_nand2_1 _2582_ (.Y(_0971_),
    .A(_0970_),
    .B(net258));
 sg13g2_a21oi_1 _2583_ (.A1(net289),
    .A2(reg2hw_40_),
    .Y(_0972_),
    .B1(net286));
 sg13g2_o21ai_1 _2584_ (.B1(_0972_),
    .Y(u_uart_reg_reg_rsp_o_9_),
    .A1(_0958_),
    .A2(_0971_));
 sg13g2_a21oi_1 _2585_ (.A1(_0358_),
    .A2(_0045_),
    .Y(_0973_),
    .B1(_1277_));
 sg13g2_a21oi_1 _2586_ (.A1(_0973_),
    .A2(_0359_),
    .Y(_0974_),
    .B1(u_uart_reg_reg_rsp_o_10_));
 sg13g2_a221oi_1 _2587_ (.B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_27_),
    .C1(net342),
    .B1(net282),
    .A1(net283),
    .Y(_0975_),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_19_));
 sg13g2_nand2b_1 _2588_ (.Y(_0976_),
    .B(net293),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_3_));
 sg13g2_nand2b_1 _2589_ (.Y(_0977_),
    .B(net348),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_11_));
 sg13g2_nand3_1 _2590_ (.B(_0977_),
    .C(net295),
    .A(_0976_),
    .Y(_0978_));
 sg13g2_nand2b_1 _2591_ (.Y(_0979_),
    .B(net291),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_35_));
 sg13g2_nand2b_1 _2592_ (.Y(_0980_),
    .B(net347),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_43_));
 sg13g2_nand3_1 _2593_ (.B(_0980_),
    .C(net295),
    .A(_0979_),
    .Y(_0981_));
 sg13g2_a221oi_1 _2594_ (.B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_59_),
    .C1(net302),
    .B1(net282),
    .A1(net283),
    .Y(_0982_),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_51_));
 sg13g2_a221oi_1 _2595_ (.B2(_0982_),
    .C1(net341),
    .B1(_0981_),
    .A1(_0975_),
    .Y(_0983_),
    .A2(_0978_));
 sg13g2_nand2b_1 _2596_ (.Y(_0984_),
    .B(net293),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_67_));
 sg13g2_inv_1 _2597_ (.Y(_0985_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_75_));
 sg13g2_a21oi_1 _2598_ (.A1(_0985_),
    .A2(net351),
    .Y(_0986_),
    .B1(net346));
 sg13g2_a21o_1 _2599_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_83_),
    .A1(net284),
    .B1(net344),
    .X(_0987_));
 sg13g2_a221oi_1 _2600_ (.B2(_0986_),
    .C1(_0987_),
    .B1(_0984_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_91_),
    .Y(_0988_),
    .A2(net282));
 sg13g2_nand2b_1 _2601_ (.Y(_0989_),
    .B(net293),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_99_));
 sg13g2_inv_1 _2602_ (.Y(_0990_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_107_));
 sg13g2_a21oi_1 _2603_ (.A1(_0990_),
    .A2(net351),
    .Y(_0991_),
    .B1(net346));
 sg13g2_a21o_1 _2604_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_115_),
    .A1(net284),
    .B1(_1200_),
    .X(_0992_));
 sg13g2_a221oi_1 _2605_ (.B2(_0991_),
    .C1(_0992_),
    .B1(_0989_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_123_),
    .Y(_0993_),
    .A2(net282));
 sg13g2_nor3_1 _2606_ (.A(_1195_),
    .B(_0988_),
    .C(_0993_),
    .Y(_0994_));
 sg13g2_o21ai_1 _2607_ (.B1(net258),
    .Y(_0995_),
    .A1(_0983_),
    .A2(_0994_));
 sg13g2_nand2_1 _2608_ (.Y(_0996_),
    .A(_0471_),
    .B(net334));
 sg13g2_nand2_1 _2609_ (.Y(_0997_),
    .A(_1270_),
    .B(_0996_));
 sg13g2_o21ai_1 _2610_ (.B1(_0997_),
    .Y(_0998_),
    .A1(_0443_),
    .A2(net324));
 sg13g2_nor2_1 _2611_ (.A(_1268_),
    .B(_0998_),
    .Y(_0999_));
 sg13g2_nor3_1 _2612_ (.A(_1266_),
    .B(_1274_),
    .C(_0999_),
    .Y(_1000_));
 sg13g2_o21ai_1 _2613_ (.B1(_1274_),
    .Y(_1001_),
    .A1(_1266_),
    .A2(_0999_));
 sg13g2_nand3b_1 _2614_ (.B(_1001_),
    .C(_1213_),
    .Y(_1002_),
    .A_N(_1000_));
 sg13g2_nand3_1 _2615_ (.B(_0995_),
    .C(_1002_),
    .A(_0974_),
    .Y(u_uart_reg_reg_rsp_o_5_));
 sg13g2_inv_1 _2616_ (.Y(_1003_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_42_));
 sg13g2_o21ai_1 _2617_ (.B1(net297),
    .Y(_1004_),
    .A1(net350),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_34_));
 sg13g2_a21oi_1 _2618_ (.A1(net350),
    .A2(_1003_),
    .Y(_1005_),
    .B1(_1004_));
 sg13g2_nor2b_1 _2619_ (.A(net262),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_50_),
    .Y(_1006_));
 sg13g2_nor2b_1 _2620_ (.A(net260),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_58_),
    .Y(_1007_));
 sg13g2_nor4_1 _2621_ (.A(net303),
    .B(_1005_),
    .C(_1006_),
    .D(_1007_),
    .Y(_1008_));
 sg13g2_inv_1 _2622_ (.Y(_1009_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_10_));
 sg13g2_o21ai_1 _2623_ (.B1(net296),
    .Y(_1010_),
    .A1(net349),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_2_));
 sg13g2_a21oi_1 _2624_ (.A1(net349),
    .A2(_1009_),
    .Y(_1011_),
    .B1(_1010_));
 sg13g2_nor2b_1 _2625_ (.A(net262),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_18_),
    .Y(_1012_));
 sg13g2_nor2b_1 _2626_ (.A(net260),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_26_),
    .Y(_1013_));
 sg13g2_nor4_1 _2627_ (.A(net343),
    .B(_1011_),
    .C(_1012_),
    .D(_1013_),
    .Y(_1014_));
 sg13g2_o21ai_1 _2628_ (.B1(net304),
    .Y(_1015_),
    .A1(_1008_),
    .A2(_1014_));
 sg13g2_nand2b_1 _2629_ (.Y(_1016_),
    .B(net292),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_98_));
 sg13g2_inv_1 _2630_ (.Y(_1017_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_106_));
 sg13g2_a21oi_1 _2631_ (.A1(_1017_),
    .A2(net350),
    .Y(_1018_),
    .B1(net345));
 sg13g2_a21o_1 _2632_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_114_),
    .A1(net284),
    .B1(net303),
    .X(_1019_));
 sg13g2_a221oi_1 _2633_ (.B2(_1018_),
    .C1(_1019_),
    .B1(_1016_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_122_),
    .Y(_1020_),
    .A2(net281));
 sg13g2_inv_1 _2634_ (.Y(_1021_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_74_));
 sg13g2_o21ai_1 _2635_ (.B1(net297),
    .Y(_1022_),
    .A1(net351),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_66_));
 sg13g2_a21oi_1 _2636_ (.A1(net350),
    .A2(_1021_),
    .Y(_1023_),
    .B1(_1022_));
 sg13g2_nor2b_1 _2637_ (.A(net262),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_82_),
    .Y(_1024_));
 sg13g2_nor2b_1 _2638_ (.A(net260),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_90_),
    .Y(_1025_));
 sg13g2_nor4_1 _2639_ (.A(net343),
    .B(_1023_),
    .C(_1024_),
    .D(_1025_),
    .Y(_1026_));
 sg13g2_o21ai_1 _2640_ (.B1(net340),
    .Y(_1027_),
    .A1(_1020_),
    .A2(_1026_));
 sg13g2_nand3_1 _2641_ (.B(_1027_),
    .C(net258),
    .A(_1015_),
    .Y(_1028_));
 sg13g2_inv_1 _2642_ (.Y(_1029_),
    .A(_0973_));
 sg13g2_xor2_1 _2643_ (.B(_0998_),
    .A(_1269_),
    .X(_1030_));
 sg13g2_nand3_1 _2644_ (.B(_1213_),
    .C(_1275_),
    .A(_1030_),
    .Y(_1031_));
 sg13g2_a21oi_1 _2645_ (.A1(net289),
    .A2(reg2hw_36_),
    .Y(_1032_),
    .B1(u_uart_reg_reg_rsp_o_10_));
 sg13g2_nand4_1 _2646_ (.B(_1029_),
    .C(_1031_),
    .A(_1028_),
    .Y(u_uart_reg_reg_rsp_o_4_),
    .D(_1032_));
 sg13g2_nand2b_1 _2647_ (.Y(_1033_),
    .B(net292),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_1_));
 sg13g2_inv_1 _2648_ (.Y(_1034_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_9_));
 sg13g2_a21oi_1 _2649_ (.A1(_1034_),
    .A2(net350),
    .Y(_1035_),
    .B1(net345));
 sg13g2_a21o_1 _2650_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_17_),
    .A1(net284),
    .B1(net344),
    .X(_1036_));
 sg13g2_a221oi_1 _2651_ (.B2(_1035_),
    .C1(_1036_),
    .B1(_1033_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_25_),
    .Y(_1037_),
    .A2(net282));
 sg13g2_inv_1 _2652_ (.Y(_1038_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_41_));
 sg13g2_o21ai_1 _2653_ (.B1(net297),
    .Y(_1039_),
    .A1(net349),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_33_));
 sg13g2_a21oi_1 _2654_ (.A1(net349),
    .A2(_1038_),
    .Y(_1040_),
    .B1(_1039_));
 sg13g2_nor2b_1 _2655_ (.A(net262),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_49_),
    .Y(_1041_));
 sg13g2_nor2b_1 _2656_ (.A(net260),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_57_),
    .Y(_1042_));
 sg13g2_nor4_1 _2657_ (.A(net303),
    .B(_1040_),
    .C(_1041_),
    .D(_1042_),
    .Y(_1043_));
 sg13g2_o21ai_1 _2658_ (.B1(net304),
    .Y(_1044_),
    .A1(_1037_),
    .A2(_1043_));
 sg13g2_nand2b_1 _2659_ (.Y(_1045_),
    .B(net292),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_97_));
 sg13g2_inv_1 _2660_ (.Y(_1046_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_105_));
 sg13g2_a21oi_1 _2661_ (.A1(_1046_),
    .A2(net350),
    .Y(_1047_),
    .B1(net346));
 sg13g2_a21o_1 _2662_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_113_),
    .A1(net284),
    .B1(net303),
    .X(_1048_));
 sg13g2_a221oi_1 _2663_ (.B2(_1047_),
    .C1(_1048_),
    .B1(_1045_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_121_),
    .Y(_1049_),
    .A2(net281));
 sg13g2_nand2b_1 _2664_ (.Y(_1050_),
    .B(net292),
    .A_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_65_));
 sg13g2_inv_1 _2665_ (.Y(_1051_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_73_));
 sg13g2_a21oi_1 _2666_ (.A1(_1051_),
    .A2(net349),
    .Y(_1052_),
    .B1(net345));
 sg13g2_a21o_1 _2667_ (.A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_81_),
    .A1(net284),
    .B1(net343),
    .X(_1053_));
 sg13g2_a221oi_1 _2668_ (.B2(_1052_),
    .C1(_1053_),
    .B1(_1050_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_89_),
    .Y(_1054_),
    .A2(net281));
 sg13g2_o21ai_1 _2669_ (.B1(net340),
    .Y(_1055_),
    .A1(_1049_),
    .A2(_1054_));
 sg13g2_nand3_1 _2670_ (.B(_1055_),
    .C(net258),
    .A(_1044_),
    .Y(_1056_));
 sg13g2_a21o_1 _2671_ (.A2(_0044_),
    .A1(_1216_),
    .B1(_1277_),
    .X(_1057_));
 sg13g2_nor2b_1 _2672_ (.A(net288),
    .B_N(_0997_),
    .Y(_1058_));
 sg13g2_o21ai_1 _2673_ (.B1(_1058_),
    .Y(_1059_),
    .A1(_1270_),
    .A2(_0996_));
 sg13g2_a21oi_1 _2674_ (.A1(_1092_),
    .A2(reg2hw_35_),
    .Y(_1060_),
    .B1(u_uart_reg_reg_rsp_o_10_));
 sg13g2_nand4_1 _2675_ (.B(_1057_),
    .C(_1059_),
    .A(_1056_),
    .Y(u_uart_reg_reg_rsp_o_3_),
    .D(_1060_));
 sg13g2_a22oi_1 _2676_ (.Y(_1061_),
    .B1(_1278_),
    .B2(_0735_),
    .A2(net289),
    .A1(net387));
 sg13g2_a22oi_1 _2677_ (.Y(_1062_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_93_),
    .B2(net282),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_85_),
    .A1(net284));
 sg13g2_inv_1 _2678_ (.Y(_1063_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_77_));
 sg13g2_a21oi_1 _2679_ (.A1(_1063_),
    .A2(net352),
    .Y(_1064_),
    .B1(net346));
 sg13g2_o21ai_1 _2680_ (.B1(_1064_),
    .Y(_1065_),
    .A1(net347),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_69_));
 sg13g2_a21oi_1 _2681_ (.A1(_1062_),
    .A2(_1065_),
    .Y(_1066_),
    .B1(net342));
 sg13g2_a22oi_1 _2682_ (.Y(_1067_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_125_),
    .B2(net281),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_117_),
    .A1(net283));
 sg13g2_inv_1 _2683_ (.Y(_1068_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_109_));
 sg13g2_a21oi_1 _2684_ (.A1(_1068_),
    .A2(net351),
    .Y(_1069_),
    .B1(net346));
 sg13g2_o21ai_1 _2685_ (.B1(_1069_),
    .Y(_1070_),
    .A1(net347),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_101_));
 sg13g2_a21oi_1 _2686_ (.A1(_1067_),
    .A2(_1070_),
    .Y(_1071_),
    .B1(net302));
 sg13g2_nor3_1 _2687_ (.A(_1195_),
    .B(_1066_),
    .C(_1071_),
    .Y(_1072_));
 sg13g2_inv_1 _2688_ (.Y(_1073_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_45_));
 sg13g2_o21ai_1 _2689_ (.B1(net297),
    .Y(_1074_),
    .A1(net352),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_37_));
 sg13g2_a21oi_1 _2690_ (.A1(net351),
    .A2(_1073_),
    .Y(_1075_),
    .B1(_1074_));
 sg13g2_nor2b_1 _2691_ (.A(net262),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_53_),
    .Y(_1076_));
 sg13g2_nor2b_1 _2692_ (.A(_1238_),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_61_),
    .Y(_1077_));
 sg13g2_nor4_1 _2693_ (.A(net303),
    .B(_1075_),
    .C(_1076_),
    .D(_1077_),
    .Y(_1078_));
 sg13g2_inv_1 _2694_ (.Y(_1079_),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_5_));
 sg13g2_o21ai_1 _2695_ (.B1(net297),
    .Y(_1080_),
    .A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_13_),
    .A2(net294));
 sg13g2_a21oi_1 _2696_ (.A1(net293),
    .A2(_1079_),
    .Y(_1081_),
    .B1(_1080_));
 sg13g2_nor2b_1 _2697_ (.A(net262),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_21_),
    .Y(_1082_));
 sg13g2_nor2b_1 _2698_ (.A(net260),
    .B_N(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_29_),
    .Y(_1083_));
 sg13g2_nor4_1 _2699_ (.A(net343),
    .B(_1081_),
    .C(_1082_),
    .D(_1083_),
    .Y(_1084_));
 sg13g2_o21ai_1 _2700_ (.B1(net304),
    .Y(_1085_),
    .A1(_1078_),
    .A2(_1084_));
 sg13g2_nand3b_1 _2701_ (.B(_1085_),
    .C(net258),
    .Y(_1086_),
    .A_N(_1072_));
 sg13g2_nand3_1 _2702_ (.B(net264),
    .C(_1086_),
    .A(_1061_),
    .Y(u_uart_reg_reg_rsp_o_7_));
 sg13g2_dfrbpq_1 _2703_ (.RESET_B(net369),
    .D(_0322_),
    .Q(_0047_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2704_ (.RESET_B(net355),
    .D(_0323_),
    .Q(reg2hw_38_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2705_ (.RESET_B(net355),
    .D(_0074_),
    .Q(_0028_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2706_ (.RESET_B(net355),
    .D(_0073_),
    .Q(_0027_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2707_ (.RESET_B(net355),
    .D(_0072_),
    .Q(_0026_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2708_ (.RESET_B(net355),
    .D(_0071_),
    .Q(_0025_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2709_ (.RESET_B(net355),
    .D(_0070_),
    .Q(_0024_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2710_ (.RESET_B(net355),
    .D(_0069_),
    .Q(_0023_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2711_ (.RESET_B(net355),
    .D(_0068_),
    .Q(_0022_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2712_ (.RESET_B(net356),
    .D(_0067_),
    .Q(reg2hw_48_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2713_ (.RESET_B(net356),
    .D(_0066_),
    .Q(_0021_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2714_ (.RESET_B(net356),
    .D(_0065_),
    .Q(_0020_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2715_ (.RESET_B(net356),
    .D(_0064_),
    .Q(reg2hw_51_),
    .CLK(clk_i));
 sg13g2_dfrbpq_2 _2716_ (.RESET_B(net356),
    .D(_0063_),
    .Q(_0019_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2717_ (.RESET_B(net356),
    .D(_0062_),
    .Q(reg2hw_53_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2718_ (.RESET_B(net356),
    .D(_0061_),
    .Q(reg2hw_54_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2719_ (.RESET_B(net356),
    .D(_0060_),
    .Q(_0018_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2720_ (.RESET_B(net357),
    .D(_0324_),
    .Q(reg2hw_56_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2721_ (.RESET_B(net357),
    .D(_0325_),
    .Q(reg2hw_36_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2722_ (.RESET_B(net357),
    .D(_0326_),
    .Q(reg2hw_39_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2723_ (.RESET_B(net357),
    .D(_0327_),
    .Q(reg2hw_40_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2724_ (.RESET_B(net357),
    .D(_0328_),
    .Q(reg2hw_35_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2725_ (.RESET_B(net357),
    .D(_0329_),
    .Q(reg2hw_37_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2726_ (.RESET_B(net357),
    .D(_0330_),
    .Q(reg2hw_34_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2727_ (.RESET_B(net357),
    .D(_0331_),
    .Q(reg2hw_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2728_ (.RESET_B(net358),
    .D(_0332_),
    .Q(reg2hw_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2729_ (.RESET_B(net358),
    .D(_0059_),
    .Q(reg2hw_5_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2730_ (.RESET_B(net358),
    .D(_0058_),
    .Q(reg2hw_6_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2731_ (.RESET_B(net358),
    .D(_0057_),
    .Q(reg2hw_7_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2732_ (.RESET_B(net358),
    .D(_0056_),
    .Q(reg2hw_8_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2733_ (.RESET_B(net358),
    .D(_0055_),
    .Q(reg2hw_9_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2734_ (.RESET_B(net358),
    .D(_0054_),
    .Q(reg2hw_10_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2735_ (.RESET_B(net358),
    .D(_0053_),
    .Q(reg2hw_11_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2736_ (.RESET_B(net359),
    .D(_0333_),
    .Q(reg2hw_12_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2737_ (.RESET_B(net359),
    .D(net253),
    .Q(reg2hw_4_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2738_ (.RESET_B(net359),
    .D(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .Q(reg2hw_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2739_ (.RESET_B(net369),
    .D(_1350_),
    .Q(u_uart_core_uart_tx_tick_baud_q),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2740_ (.RESET_B(net361),
    .D(u_uart_core_uart_rx_tick_baud_d),
    .Q(u_uart_core_rx_tick_baud),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2741_ (.RESET_B(net361),
    .D(_0000_),
    .Q(u_uart_core_rx_valid),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2742_ (.RESET_B(net369),
    .D(net),
    .Q(_0045_),
    .CLK(clk_i));
 sg13g2_tiehi _2742__1 (.L_HI(net));
 sg13g2_dfrbpq_1 _2743_ (.RESET_B(net361),
    .D(net1),
    .Q(_0044_),
    .CLK(clk_i));
 sg13g2_tiehi _2743__2 (.L_HI(net1));
 sg13g2_dfrbpq_1 _2744_ (.RESET_B(net354),
    .D(net2),
    .Q(u_uart_core_tx_rst_ni),
    .CLK(clk_i));
 sg13g2_tiehi _2744__3 (.L_HI(net2));
 sg13g2_dfrbpq_1 _2745_ (.RESET_B(net354),
    .D(net3),
    .Q(u_uart_core_timing_rst_ni),
    .CLK(clk_i));
 sg13g2_tiehi _2745__4 (.L_HI(net3));
 sg13g2_dfrbpq_1 _2746_ (.RESET_B(net354),
    .D(net4),
    .Q(u_uart_core_rx_rst_ni),
    .CLK(clk_i));
 sg13g2_tiehi _2746__5 (.L_HI(net4));
 sg13g2_dfrbpq_1 _2747_ (.RESET_B(net369),
    .D(_0052_),
    .Q(_0043_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2748_ (.RESET_B(net361),
    .D(_0051_),
    .Q(_0042_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2749_ (.RESET_B(net361),
    .D(_0050_),
    .Q(_0041_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2750_ (.RESET_B(net361),
    .D(_0049_),
    .Q(_0040_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2751_ (.RESET_B(net361),
    .D(_0048_),
    .Q(_0039_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2752_ (.RESET_B(net366),
    .D(_0002_),
    .Q(u_uart_core_nco_sum_q_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2753_ (.RESET_B(net366),
    .D(_0009_),
    .Q(u_uart_core_nco_sum_q_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2754_ (.RESET_B(net366),
    .D(_0010_),
    .Q(u_uart_core_nco_sum_q_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2755_ (.RESET_B(net366),
    .D(_0011_),
    .Q(u_uart_core_nco_sum_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2756_ (.RESET_B(net366),
    .D(_0012_),
    .Q(u_uart_core_nco_sum_q_4_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2757_ (.RESET_B(net366),
    .D(_0013_),
    .Q(u_uart_core_nco_sum_q_5_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2758_ (.RESET_B(net366),
    .D(_0014_),
    .Q(u_uart_core_nco_sum_q_6_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2759_ (.RESET_B(net366),
    .D(_0015_),
    .Q(u_uart_core_nco_sum_q_7_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2760_ (.RESET_B(net367),
    .D(_0016_),
    .Q(u_uart_core_nco_sum_q_8_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2761_ (.RESET_B(net367),
    .D(_0017_),
    .Q(u_uart_core_nco_sum_q_9_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2762_ (.RESET_B(net367),
    .D(_0003_),
    .Q(u_uart_core_nco_sum_q_10_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2763_ (.RESET_B(net367),
    .D(_0004_),
    .Q(u_uart_core_nco_sum_q_11_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2764_ (.RESET_B(net367),
    .D(_0005_),
    .Q(u_uart_core_nco_sum_q_12_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2765_ (.RESET_B(net367),
    .D(_0006_),
    .Q(u_uart_core_nco_sum_q_13_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2766_ (.RESET_B(net367),
    .D(_0007_),
    .Q(u_uart_core_nco_sum_q_14_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2767_ (.RESET_B(net367),
    .D(_0008_),
    .Q(u_uart_core_nco_sum_q_15_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2768_ (.RESET_B(net368),
    .D(_0001_),
    .Q(u_uart_core_nco_sum_q_16_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2769_ (.RESET_B(rst_ni),
    .D(u_reg_reset_sync_intq),
    .Q(reg_rst_ni),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2770_ (.RESET_B(rst_ni),
    .D(net5),
    .Q(u_reg_reset_sync_intq),
    .CLK(clk_i));
 sg13g2_tiehi _2770__6 (.L_HI(net5));
 sg13g2_dfrbpq_1 _2771_ (.RESET_B(rst_ni),
    .D(u_core_reset_sync_intq),
    .Q(core_rst_ni),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2772_ (.RESET_B(rst_ni),
    .D(net6),
    .Q(u_core_reset_sync_intq),
    .CLK(clk_i));
 sg13g2_tiehi _2772__7 (.L_HI(net6));
 sg13g2_dfrbpq_1 _2773_ (.RESET_B(net7),
    .D(_0314_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_63_),
    .CLK(clk_i));
 sg13g2_tiehi _2773__8 (.L_HI(net7));
 sg13g2_dfrbpq_1 _2774_ (.RESET_B(net8),
    .D(_0313_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_55_),
    .CLK(clk_i));
 sg13g2_tiehi _2774__9 (.L_HI(net8));
 sg13g2_dfrbpq_1 _2775_ (.RESET_B(net9),
    .D(_0312_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_47_),
    .CLK(clk_i));
 sg13g2_tiehi _2775__10 (.L_HI(net9));
 sg13g2_dfrbpq_1 _2776_ (.RESET_B(net10),
    .D(_0311_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_39_),
    .CLK(clk_i));
 sg13g2_tiehi _2776__11 (.L_HI(net10));
 sg13g2_dfrbpq_1 _2777_ (.RESET_B(net11),
    .D(_0310_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_31_),
    .CLK(clk_i));
 sg13g2_tiehi _2777__12 (.L_HI(net11));
 sg13g2_dfrbpq_1 _2778_ (.RESET_B(net12),
    .D(_0309_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_23_),
    .CLK(clk_i));
 sg13g2_tiehi _2778__13 (.L_HI(net12));
 sg13g2_dfrbpq_1 _2779_ (.RESET_B(net13),
    .D(_0308_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_15_),
    .CLK(clk_i));
 sg13g2_tiehi _2779__14 (.L_HI(net13));
 sg13g2_dfrbpq_1 _2780_ (.RESET_B(net14),
    .D(_0307_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_7_),
    .CLK(clk_i));
 sg13g2_tiehi _2780__15 (.L_HI(net14));
 sg13g2_dfrbpq_1 _2781_ (.RESET_B(net15),
    .D(_0304_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_79_),
    .CLK(clk_i));
 sg13g2_tiehi _2781__16 (.L_HI(net15));
 sg13g2_dfrbpq_1 _2782_ (.RESET_B(net16),
    .D(_0303_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_71_),
    .CLK(clk_i));
 sg13g2_tiehi _2782__17 (.L_HI(net16));
 sg13g2_dfrbpq_1 _2783_ (.RESET_B(net17),
    .D(_0302_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_63_),
    .CLK(clk_i));
 sg13g2_tiehi _2783__18 (.L_HI(net17));
 sg13g2_dfrbpq_1 _2784_ (.RESET_B(net18),
    .D(_0301_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_55_),
    .CLK(clk_i));
 sg13g2_tiehi _2784__19 (.L_HI(net18));
 sg13g2_dfrbpq_1 _2785_ (.RESET_B(net19),
    .D(_0300_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_47_),
    .CLK(clk_i));
 sg13g2_tiehi _2785__20 (.L_HI(net19));
 sg13g2_dfrbpq_1 _2786_ (.RESET_B(net20),
    .D(_0299_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_39_),
    .CLK(clk_i));
 sg13g2_tiehi _2786__21 (.L_HI(net20));
 sg13g2_dfrbpq_1 _2787_ (.RESET_B(net21),
    .D(_0298_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_31_),
    .CLK(clk_i));
 sg13g2_tiehi _2787__22 (.L_HI(net21));
 sg13g2_dfrbpq_1 _2788_ (.RESET_B(net22),
    .D(_0297_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_23_),
    .CLK(clk_i));
 sg13g2_tiehi _2788__23 (.L_HI(net22));
 sg13g2_dfrbpq_1 _2789_ (.RESET_B(net23),
    .D(_0296_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_15_),
    .CLK(clk_i));
 sg13g2_tiehi _2789__24 (.L_HI(net23));
 sg13g2_dfrbpq_1 _2790_ (.RESET_B(net24),
    .D(_0295_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_127_),
    .CLK(clk_i));
 sg13g2_tiehi _2790__25 (.L_HI(net24));
 sg13g2_dfrbpq_1 _2791_ (.RESET_B(net25),
    .D(_0294_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_119_),
    .CLK(clk_i));
 sg13g2_tiehi _2791__26 (.L_HI(net25));
 sg13g2_dfrbpq_1 _2792_ (.RESET_B(net26),
    .D(_0293_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_111_),
    .CLK(clk_i));
 sg13g2_tiehi _2792__27 (.L_HI(net26));
 sg13g2_dfrbpq_1 _2793_ (.RESET_B(net27),
    .D(_0292_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_103_),
    .CLK(clk_i));
 sg13g2_tiehi _2793__28 (.L_HI(net27));
 sg13g2_dfrbpq_1 _2794_ (.RESET_B(net28),
    .D(_0291_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_95_),
    .CLK(clk_i));
 sg13g2_tiehi _2794__29 (.L_HI(net28));
 sg13g2_dfrbpq_1 _2795_ (.RESET_B(net29),
    .D(_0290_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_87_),
    .CLK(clk_i));
 sg13g2_tiehi _2795__30 (.L_HI(net29));
 sg13g2_dfrbpq_1 _2796_ (.RESET_B(net30),
    .D(_0289_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_7_),
    .CLK(clk_i));
 sg13g2_tiehi _2796__31 (.L_HI(net30));
 sg13g2_dfrbpq_1 _2797_ (.RESET_B(net31),
    .D(_0273_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_0_),
    .CLK(clk_i));
 sg13g2_tiehi _2797__32 (.L_HI(net31));
 sg13g2_dfrbpq_1 _2798_ (.RESET_B(net32),
    .D(_0272_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_1_),
    .CLK(clk_i));
 sg13g2_tiehi _2798__33 (.L_HI(net32));
 sg13g2_dfrbpq_1 _2799_ (.RESET_B(net33),
    .D(_0271_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_2_),
    .CLK(clk_i));
 sg13g2_tiehi _2799__34 (.L_HI(net33));
 sg13g2_dfrbpq_1 _2800_ (.RESET_B(net34),
    .D(_0270_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_3_),
    .CLK(clk_i));
 sg13g2_tiehi _2800__35 (.L_HI(net34));
 sg13g2_dfrbpq_1 _2801_ (.RESET_B(net35),
    .D(_0269_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_4_),
    .CLK(clk_i));
 sg13g2_tiehi _2801__36 (.L_HI(net35));
 sg13g2_dfrbpq_1 _2802_ (.RESET_B(net36),
    .D(_0268_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_5_),
    .CLK(clk_i));
 sg13g2_tiehi _2802__37 (.L_HI(net36));
 sg13g2_dfrbpq_1 _2803_ (.RESET_B(net37),
    .D(_0267_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_6_),
    .CLK(clk_i));
 sg13g2_tiehi _2803__38 (.L_HI(net37));
 sg13g2_dfrbpq_1 _2804_ (.RESET_B(net38),
    .D(_0266_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_80_),
    .CLK(clk_i));
 sg13g2_tiehi _2804__39 (.L_HI(net38));
 sg13g2_dfrbpq_1 _2805_ (.RESET_B(net39),
    .D(_0265_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_81_),
    .CLK(clk_i));
 sg13g2_tiehi _2805__40 (.L_HI(net39));
 sg13g2_dfrbpq_1 _2806_ (.RESET_B(net40),
    .D(_0264_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_82_),
    .CLK(clk_i));
 sg13g2_tiehi _2806__41 (.L_HI(net40));
 sg13g2_dfrbpq_1 _2807_ (.RESET_B(net41),
    .D(_0263_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_83_),
    .CLK(clk_i));
 sg13g2_tiehi _2807__42 (.L_HI(net41));
 sg13g2_dfrbpq_1 _2808_ (.RESET_B(net42),
    .D(_0262_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_84_),
    .CLK(clk_i));
 sg13g2_tiehi _2808__43 (.L_HI(net42));
 sg13g2_dfrbpq_1 _2809_ (.RESET_B(net43),
    .D(_0261_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_85_),
    .CLK(clk_i));
 sg13g2_tiehi _2809__44 (.L_HI(net43));
 sg13g2_dfrbpq_1 _2810_ (.RESET_B(net44),
    .D(_0260_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_86_),
    .CLK(clk_i));
 sg13g2_tiehi _2810__45 (.L_HI(net44));
 sg13g2_dfrbpq_1 _2811_ (.RESET_B(net45),
    .D(_0259_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_88_),
    .CLK(clk_i));
 sg13g2_tiehi _2811__46 (.L_HI(net45));
 sg13g2_dfrbpq_1 _2812_ (.RESET_B(net46),
    .D(_0258_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_89_),
    .CLK(clk_i));
 sg13g2_tiehi _2812__47 (.L_HI(net46));
 sg13g2_dfrbpq_1 _2813_ (.RESET_B(net47),
    .D(_0257_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_90_),
    .CLK(clk_i));
 sg13g2_tiehi _2813__48 (.L_HI(net47));
 sg13g2_dfrbpq_1 _2814_ (.RESET_B(net48),
    .D(_0256_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_91_),
    .CLK(clk_i));
 sg13g2_tiehi _2814__49 (.L_HI(net48));
 sg13g2_dfrbpq_1 _2815_ (.RESET_B(net49),
    .D(_0255_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_92_),
    .CLK(clk_i));
 sg13g2_tiehi _2815__50 (.L_HI(net49));
 sg13g2_dfrbpq_1 _2816_ (.RESET_B(net50),
    .D(_0254_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_93_),
    .CLK(clk_i));
 sg13g2_tiehi _2816__51 (.L_HI(net50));
 sg13g2_dfrbpq_1 _2817_ (.RESET_B(net51),
    .D(_0253_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_94_),
    .CLK(clk_i));
 sg13g2_tiehi _2817__52 (.L_HI(net51));
 sg13g2_dfrbpq_1 _2818_ (.RESET_B(net52),
    .D(_0252_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_96_),
    .CLK(clk_i));
 sg13g2_tiehi _2818__53 (.L_HI(net52));
 sg13g2_dfrbpq_1 _2819_ (.RESET_B(net53),
    .D(_0251_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_97_),
    .CLK(clk_i));
 sg13g2_tiehi _2819__54 (.L_HI(net53));
 sg13g2_dfrbpq_1 _2820_ (.RESET_B(net54),
    .D(_0250_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_98_),
    .CLK(clk_i));
 sg13g2_tiehi _2820__55 (.L_HI(net54));
 sg13g2_dfrbpq_1 _2821_ (.RESET_B(net55),
    .D(_0249_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_99_),
    .CLK(clk_i));
 sg13g2_tiehi _2821__56 (.L_HI(net55));
 sg13g2_dfrbpq_1 _2822_ (.RESET_B(net56),
    .D(_0248_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_100_),
    .CLK(clk_i));
 sg13g2_tiehi _2822__57 (.L_HI(net56));
 sg13g2_dfrbpq_1 _2823_ (.RESET_B(net57),
    .D(_0247_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_101_),
    .CLK(clk_i));
 sg13g2_tiehi _2823__58 (.L_HI(net57));
 sg13g2_dfrbpq_1 _2824_ (.RESET_B(net58),
    .D(_0246_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_102_),
    .CLK(clk_i));
 sg13g2_tiehi _2824__59 (.L_HI(net58));
 sg13g2_dfrbpq_1 _2825_ (.RESET_B(net59),
    .D(_0245_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_104_),
    .CLK(clk_i));
 sg13g2_tiehi _2825__60 (.L_HI(net59));
 sg13g2_dfrbpq_1 _2826_ (.RESET_B(net60),
    .D(_0244_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_105_),
    .CLK(clk_i));
 sg13g2_tiehi _2826__61 (.L_HI(net60));
 sg13g2_dfrbpq_1 _2827_ (.RESET_B(net61),
    .D(_0243_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_106_),
    .CLK(clk_i));
 sg13g2_tiehi _2827__62 (.L_HI(net61));
 sg13g2_dfrbpq_1 _2828_ (.RESET_B(net62),
    .D(_0242_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_107_),
    .CLK(clk_i));
 sg13g2_tiehi _2828__63 (.L_HI(net62));
 sg13g2_dfrbpq_1 _2829_ (.RESET_B(net63),
    .D(_0241_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_108_),
    .CLK(clk_i));
 sg13g2_tiehi _2829__64 (.L_HI(net63));
 sg13g2_dfrbpq_1 _2830_ (.RESET_B(net64),
    .D(_0240_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_109_),
    .CLK(clk_i));
 sg13g2_tiehi _2830__65 (.L_HI(net64));
 sg13g2_dfrbpq_1 _2831_ (.RESET_B(net65),
    .D(_0239_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_110_),
    .CLK(clk_i));
 sg13g2_tiehi _2831__66 (.L_HI(net65));
 sg13g2_dfrbpq_1 _2832_ (.RESET_B(net66),
    .D(_0238_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_112_),
    .CLK(clk_i));
 sg13g2_tiehi _2832__67 (.L_HI(net66));
 sg13g2_dfrbpq_1 _2833_ (.RESET_B(net67),
    .D(_0237_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_113_),
    .CLK(clk_i));
 sg13g2_tiehi _2833__68 (.L_HI(net67));
 sg13g2_dfrbpq_1 _2834_ (.RESET_B(net68),
    .D(_0236_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_114_),
    .CLK(clk_i));
 sg13g2_tiehi _2834__69 (.L_HI(net68));
 sg13g2_dfrbpq_1 _2835_ (.RESET_B(net69),
    .D(_0235_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_115_),
    .CLK(clk_i));
 sg13g2_tiehi _2835__70 (.L_HI(net69));
 sg13g2_dfrbpq_1 _2836_ (.RESET_B(net70),
    .D(_0234_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_116_),
    .CLK(clk_i));
 sg13g2_tiehi _2836__71 (.L_HI(net70));
 sg13g2_dfrbpq_1 _2837_ (.RESET_B(net71),
    .D(_0233_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_117_),
    .CLK(clk_i));
 sg13g2_tiehi _2837__72 (.L_HI(net71));
 sg13g2_dfrbpq_1 _2838_ (.RESET_B(net72),
    .D(_0232_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_118_),
    .CLK(clk_i));
 sg13g2_tiehi _2838__73 (.L_HI(net72));
 sg13g2_dfrbpq_1 _2839_ (.RESET_B(net73),
    .D(_0231_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_120_),
    .CLK(clk_i));
 sg13g2_tiehi _2839__74 (.L_HI(net73));
 sg13g2_dfrbpq_1 _2840_ (.RESET_B(net74),
    .D(_0230_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_121_),
    .CLK(clk_i));
 sg13g2_tiehi _2840__75 (.L_HI(net74));
 sg13g2_dfrbpq_1 _2841_ (.RESET_B(net75),
    .D(_0229_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_122_),
    .CLK(clk_i));
 sg13g2_tiehi _2841__76 (.L_HI(net75));
 sg13g2_dfrbpq_1 _2842_ (.RESET_B(net76),
    .D(_0228_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_123_),
    .CLK(clk_i));
 sg13g2_tiehi _2842__77 (.L_HI(net76));
 sg13g2_dfrbpq_1 _2843_ (.RESET_B(net77),
    .D(_0227_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_124_),
    .CLK(clk_i));
 sg13g2_tiehi _2843__78 (.L_HI(net77));
 sg13g2_dfrbpq_1 _2844_ (.RESET_B(net78),
    .D(_0226_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_125_),
    .CLK(clk_i));
 sg13g2_tiehi _2844__79 (.L_HI(net78));
 sg13g2_dfrbpq_1 _2845_ (.RESET_B(net79),
    .D(_0225_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_126_),
    .CLK(clk_i));
 sg13g2_tiehi _2845__80 (.L_HI(net79));
 sg13g2_dfrbpq_1 _2846_ (.RESET_B(net80),
    .D(_0224_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_8_),
    .CLK(clk_i));
 sg13g2_tiehi _2846__81 (.L_HI(net80));
 sg13g2_dfrbpq_1 _2847_ (.RESET_B(net81),
    .D(_0223_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_9_),
    .CLK(clk_i));
 sg13g2_tiehi _2847__82 (.L_HI(net81));
 sg13g2_dfrbpq_1 _2848_ (.RESET_B(net82),
    .D(_0222_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_10_),
    .CLK(clk_i));
 sg13g2_tiehi _2848__83 (.L_HI(net82));
 sg13g2_dfrbpq_1 _2849_ (.RESET_B(net83),
    .D(_0221_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_11_),
    .CLK(clk_i));
 sg13g2_tiehi _2849__84 (.L_HI(net83));
 sg13g2_dfrbpq_1 _2850_ (.RESET_B(net84),
    .D(_0220_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_12_),
    .CLK(clk_i));
 sg13g2_tiehi _2850__85 (.L_HI(net84));
 sg13g2_dfrbpq_1 _2851_ (.RESET_B(net85),
    .D(_0219_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_13_),
    .CLK(clk_i));
 sg13g2_tiehi _2851__86 (.L_HI(net85));
 sg13g2_dfrbpq_1 _2852_ (.RESET_B(net86),
    .D(_0218_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_14_),
    .CLK(clk_i));
 sg13g2_tiehi _2852__87 (.L_HI(net86));
 sg13g2_dfrbpq_1 _2853_ (.RESET_B(net87),
    .D(_0217_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_16_),
    .CLK(clk_i));
 sg13g2_tiehi _2853__88 (.L_HI(net87));
 sg13g2_dfrbpq_1 _2854_ (.RESET_B(net88),
    .D(_0216_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_17_),
    .CLK(clk_i));
 sg13g2_tiehi _2854__89 (.L_HI(net88));
 sg13g2_dfrbpq_1 _2855_ (.RESET_B(net89),
    .D(_0215_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_18_),
    .CLK(clk_i));
 sg13g2_tiehi _2855__90 (.L_HI(net89));
 sg13g2_dfrbpq_1 _2856_ (.RESET_B(net90),
    .D(_0214_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_19_),
    .CLK(clk_i));
 sg13g2_tiehi _2856__91 (.L_HI(net90));
 sg13g2_dfrbpq_1 _2857_ (.RESET_B(net91),
    .D(_0213_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_20_),
    .CLK(clk_i));
 sg13g2_tiehi _2857__92 (.L_HI(net91));
 sg13g2_dfrbpq_1 _2858_ (.RESET_B(net92),
    .D(_0212_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_21_),
    .CLK(clk_i));
 sg13g2_tiehi _2858__93 (.L_HI(net92));
 sg13g2_dfrbpq_1 _2859_ (.RESET_B(net93),
    .D(_0211_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_22_),
    .CLK(clk_i));
 sg13g2_tiehi _2859__94 (.L_HI(net93));
 sg13g2_dfrbpq_1 _2860_ (.RESET_B(net94),
    .D(_0210_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_24_),
    .CLK(clk_i));
 sg13g2_tiehi _2860__95 (.L_HI(net94));
 sg13g2_dfrbpq_1 _2861_ (.RESET_B(net95),
    .D(_0209_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_25_),
    .CLK(clk_i));
 sg13g2_tiehi _2861__96 (.L_HI(net95));
 sg13g2_dfrbpq_1 _2862_ (.RESET_B(net96),
    .D(_0208_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_26_),
    .CLK(clk_i));
 sg13g2_tiehi _2862__97 (.L_HI(net96));
 sg13g2_dfrbpq_1 _2863_ (.RESET_B(net97),
    .D(_0207_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_27_),
    .CLK(clk_i));
 sg13g2_tiehi _2863__98 (.L_HI(net97));
 sg13g2_dfrbpq_1 _2864_ (.RESET_B(net98),
    .D(_0206_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_28_),
    .CLK(clk_i));
 sg13g2_tiehi _2864__99 (.L_HI(net98));
 sg13g2_dfrbpq_1 _2865_ (.RESET_B(net99),
    .D(_0205_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_29_),
    .CLK(clk_i));
 sg13g2_tiehi _2865__100 (.L_HI(net99));
 sg13g2_dfrbpq_1 _2866_ (.RESET_B(net100),
    .D(_0204_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_30_),
    .CLK(clk_i));
 sg13g2_tiehi _2866__101 (.L_HI(net100));
 sg13g2_dfrbpq_1 _2867_ (.RESET_B(net101),
    .D(_0203_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_32_),
    .CLK(clk_i));
 sg13g2_tiehi _2867__102 (.L_HI(net101));
 sg13g2_dfrbpq_1 _2868_ (.RESET_B(net102),
    .D(_0202_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_33_),
    .CLK(clk_i));
 sg13g2_tiehi _2868__103 (.L_HI(net102));
 sg13g2_dfrbpq_1 _2869_ (.RESET_B(net103),
    .D(_0201_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_34_),
    .CLK(clk_i));
 sg13g2_tiehi _2869__104 (.L_HI(net103));
 sg13g2_dfrbpq_1 _2870_ (.RESET_B(net104),
    .D(_0200_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_35_),
    .CLK(clk_i));
 sg13g2_tiehi _2870__105 (.L_HI(net104));
 sg13g2_dfrbpq_1 _2871_ (.RESET_B(net105),
    .D(_0199_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_36_),
    .CLK(clk_i));
 sg13g2_tiehi _2871__106 (.L_HI(net105));
 sg13g2_dfrbpq_1 _2872_ (.RESET_B(net106),
    .D(_0198_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_37_),
    .CLK(clk_i));
 sg13g2_tiehi _2872__107 (.L_HI(net106));
 sg13g2_dfrbpq_1 _2873_ (.RESET_B(net107),
    .D(_0197_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_38_),
    .CLK(clk_i));
 sg13g2_tiehi _2873__108 (.L_HI(net107));
 sg13g2_dfrbpq_1 _2874_ (.RESET_B(net108),
    .D(_0196_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_40_),
    .CLK(clk_i));
 sg13g2_tiehi _2874__109 (.L_HI(net108));
 sg13g2_dfrbpq_1 _2875_ (.RESET_B(net109),
    .D(_0195_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_41_),
    .CLK(clk_i));
 sg13g2_tiehi _2875__110 (.L_HI(net109));
 sg13g2_dfrbpq_1 _2876_ (.RESET_B(net110),
    .D(_0194_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_42_),
    .CLK(clk_i));
 sg13g2_tiehi _2876__111 (.L_HI(net110));
 sg13g2_dfrbpq_1 _2877_ (.RESET_B(net111),
    .D(_0193_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_43_),
    .CLK(clk_i));
 sg13g2_tiehi _2877__112 (.L_HI(net111));
 sg13g2_dfrbpq_1 _2878_ (.RESET_B(net112),
    .D(_0192_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_44_),
    .CLK(clk_i));
 sg13g2_tiehi _2878__113 (.L_HI(net112));
 sg13g2_dfrbpq_1 _2879_ (.RESET_B(net113),
    .D(_0191_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_45_),
    .CLK(clk_i));
 sg13g2_tiehi _2879__114 (.L_HI(net113));
 sg13g2_dfrbpq_1 _2880_ (.RESET_B(net114),
    .D(_0190_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_46_),
    .CLK(clk_i));
 sg13g2_tiehi _2880__115 (.L_HI(net114));
 sg13g2_dfrbpq_1 _2881_ (.RESET_B(net115),
    .D(_0189_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_48_),
    .CLK(clk_i));
 sg13g2_tiehi _2881__116 (.L_HI(net115));
 sg13g2_dfrbpq_1 _2882_ (.RESET_B(net116),
    .D(_0188_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_49_),
    .CLK(clk_i));
 sg13g2_tiehi _2882__117 (.L_HI(net116));
 sg13g2_dfrbpq_1 _2883_ (.RESET_B(net117),
    .D(_0187_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_50_),
    .CLK(clk_i));
 sg13g2_tiehi _2883__118 (.L_HI(net117));
 sg13g2_dfrbpq_1 _2884_ (.RESET_B(net118),
    .D(_0186_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_51_),
    .CLK(clk_i));
 sg13g2_tiehi _2884__119 (.L_HI(net118));
 sg13g2_dfrbpq_1 _2885_ (.RESET_B(net119),
    .D(_0185_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_52_),
    .CLK(clk_i));
 sg13g2_tiehi _2885__120 (.L_HI(net119));
 sg13g2_dfrbpq_1 _2886_ (.RESET_B(net120),
    .D(_0184_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_53_),
    .CLK(clk_i));
 sg13g2_tiehi _2886__121 (.L_HI(net120));
 sg13g2_dfrbpq_1 _2887_ (.RESET_B(net121),
    .D(_0183_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_54_),
    .CLK(clk_i));
 sg13g2_tiehi _2887__122 (.L_HI(net121));
 sg13g2_dfrbpq_1 _2888_ (.RESET_B(net122),
    .D(_0182_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_56_),
    .CLK(clk_i));
 sg13g2_tiehi _2888__123 (.L_HI(net122));
 sg13g2_dfrbpq_1 _2889_ (.RESET_B(net123),
    .D(_0181_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_57_),
    .CLK(clk_i));
 sg13g2_tiehi _2889__124 (.L_HI(net123));
 sg13g2_dfrbpq_1 _2890_ (.RESET_B(net124),
    .D(_0180_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_58_),
    .CLK(clk_i));
 sg13g2_tiehi _2890__125 (.L_HI(net124));
 sg13g2_dfrbpq_1 _2891_ (.RESET_B(net125),
    .D(_0179_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_59_),
    .CLK(clk_i));
 sg13g2_tiehi _2891__126 (.L_HI(net125));
 sg13g2_dfrbpq_1 _2892_ (.RESET_B(net126),
    .D(_0178_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_60_),
    .CLK(clk_i));
 sg13g2_tiehi _2892__127 (.L_HI(net126));
 sg13g2_dfrbpq_1 _2893_ (.RESET_B(net127),
    .D(_0177_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_61_),
    .CLK(clk_i));
 sg13g2_tiehi _2893__128 (.L_HI(net127));
 sg13g2_dfrbpq_1 _2894_ (.RESET_B(net128),
    .D(_0176_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_62_),
    .CLK(clk_i));
 sg13g2_tiehi _2894__129 (.L_HI(net128));
 sg13g2_dfrbpq_1 _2895_ (.RESET_B(net129),
    .D(_0175_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_64_),
    .CLK(clk_i));
 sg13g2_tiehi _2895__130 (.L_HI(net129));
 sg13g2_dfrbpq_1 _2896_ (.RESET_B(net130),
    .D(_0174_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_65_),
    .CLK(clk_i));
 sg13g2_tiehi _2896__131 (.L_HI(net130));
 sg13g2_dfrbpq_1 _2897_ (.RESET_B(net131),
    .D(_0173_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_66_),
    .CLK(clk_i));
 sg13g2_tiehi _2897__132 (.L_HI(net131));
 sg13g2_dfrbpq_1 _2898_ (.RESET_B(net132),
    .D(_0172_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_67_),
    .CLK(clk_i));
 sg13g2_tiehi _2898__133 (.L_HI(net132));
 sg13g2_dfrbpq_1 _2899_ (.RESET_B(net133),
    .D(_0171_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_68_),
    .CLK(clk_i));
 sg13g2_tiehi _2899__134 (.L_HI(net133));
 sg13g2_dfrbpq_1 _2900_ (.RESET_B(net134),
    .D(_0170_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_69_),
    .CLK(clk_i));
 sg13g2_tiehi _2900__135 (.L_HI(net134));
 sg13g2_dfrbpq_1 _2901_ (.RESET_B(net135),
    .D(_0169_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_70_),
    .CLK(clk_i));
 sg13g2_tiehi _2901__136 (.L_HI(net135));
 sg13g2_dfrbpq_1 _2902_ (.RESET_B(net136),
    .D(_0168_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_72_),
    .CLK(clk_i));
 sg13g2_tiehi _2902__137 (.L_HI(net136));
 sg13g2_dfrbpq_1 _2903_ (.RESET_B(net137),
    .D(_0167_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_73_),
    .CLK(clk_i));
 sg13g2_tiehi _2903__138 (.L_HI(net137));
 sg13g2_dfrbpq_1 _2904_ (.RESET_B(net138),
    .D(_0166_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_74_),
    .CLK(clk_i));
 sg13g2_tiehi _2904__139 (.L_HI(net138));
 sg13g2_dfrbpq_1 _2905_ (.RESET_B(net139),
    .D(_0165_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_75_),
    .CLK(clk_i));
 sg13g2_tiehi _2905__140 (.L_HI(net139));
 sg13g2_dfrbpq_1 _2906_ (.RESET_B(net140),
    .D(_0164_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_76_),
    .CLK(clk_i));
 sg13g2_tiehi _2906__141 (.L_HI(net140));
 sg13g2_dfrbpq_1 _2907_ (.RESET_B(net141),
    .D(_0163_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_77_),
    .CLK(clk_i));
 sg13g2_tiehi _2907__142 (.L_HI(net141));
 sg13g2_dfrbpq_1 _2908_ (.RESET_B(net142),
    .D(_0162_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_78_),
    .CLK(clk_i));
 sg13g2_tiehi _2908__143 (.L_HI(net142));
 sg13g2_dfrbpq_1 _2909_ (.RESET_B(net143),
    .D(_0154_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_0_),
    .CLK(clk_i));
 sg13g2_tiehi _2909__144 (.L_HI(net143));
 sg13g2_dfrbpq_1 _2910_ (.RESET_B(net144),
    .D(_0153_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_1_),
    .CLK(clk_i));
 sg13g2_tiehi _2910__145 (.L_HI(net144));
 sg13g2_dfrbpq_1 _2911_ (.RESET_B(net145),
    .D(_0152_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_2_),
    .CLK(clk_i));
 sg13g2_tiehi _2911__146 (.L_HI(net145));
 sg13g2_dfrbpq_1 _2912_ (.RESET_B(net146),
    .D(_0151_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_3_),
    .CLK(clk_i));
 sg13g2_tiehi _2912__147 (.L_HI(net146));
 sg13g2_dfrbpq_1 _2913_ (.RESET_B(net147),
    .D(_0150_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_4_),
    .CLK(clk_i));
 sg13g2_tiehi _2913__148 (.L_HI(net147));
 sg13g2_dfrbpq_1 _2914_ (.RESET_B(net148),
    .D(_0149_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_5_),
    .CLK(clk_i));
 sg13g2_tiehi _2914__149 (.L_HI(net148));
 sg13g2_dfrbpq_1 _2915_ (.RESET_B(net149),
    .D(_0148_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_6_),
    .CLK(clk_i));
 sg13g2_tiehi _2915__150 (.L_HI(net149));
 sg13g2_dfrbpq_1 _2916_ (.RESET_B(net150),
    .D(_0147_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_8_),
    .CLK(clk_i));
 sg13g2_tiehi _2916__151 (.L_HI(net150));
 sg13g2_dfrbpq_1 _2917_ (.RESET_B(net151),
    .D(_0146_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_9_),
    .CLK(clk_i));
 sg13g2_tiehi _2917__152 (.L_HI(net151));
 sg13g2_dfrbpq_1 _2918_ (.RESET_B(net152),
    .D(_0145_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_10_),
    .CLK(clk_i));
 sg13g2_tiehi _2918__153 (.L_HI(net152));
 sg13g2_dfrbpq_1 _2919_ (.RESET_B(net153),
    .D(_0144_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_11_),
    .CLK(clk_i));
 sg13g2_tiehi _2919__154 (.L_HI(net153));
 sg13g2_dfrbpq_1 _2920_ (.RESET_B(net154),
    .D(_0143_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_12_),
    .CLK(clk_i));
 sg13g2_tiehi _2920__155 (.L_HI(net154));
 sg13g2_dfrbpq_1 _2921_ (.RESET_B(net155),
    .D(_0142_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_13_),
    .CLK(clk_i));
 sg13g2_tiehi _2921__156 (.L_HI(net155));
 sg13g2_dfrbpq_1 _2922_ (.RESET_B(net156),
    .D(_0141_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_14_),
    .CLK(clk_i));
 sg13g2_tiehi _2922__157 (.L_HI(net156));
 sg13g2_dfrbpq_1 _2923_ (.RESET_B(net157),
    .D(_0140_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_16_),
    .CLK(clk_i));
 sg13g2_tiehi _2923__158 (.L_HI(net157));
 sg13g2_dfrbpq_1 _2924_ (.RESET_B(net158),
    .D(_0139_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_17_),
    .CLK(clk_i));
 sg13g2_tiehi _2924__159 (.L_HI(net158));
 sg13g2_dfrbpq_1 _2925_ (.RESET_B(net159),
    .D(_0138_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_18_),
    .CLK(clk_i));
 sg13g2_tiehi _2925__160 (.L_HI(net159));
 sg13g2_dfrbpq_1 _2926_ (.RESET_B(net160),
    .D(_0137_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_19_),
    .CLK(clk_i));
 sg13g2_tiehi _2926__161 (.L_HI(net160));
 sg13g2_dfrbpq_1 _2927_ (.RESET_B(net161),
    .D(_0136_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_20_),
    .CLK(clk_i));
 sg13g2_tiehi _2927__162 (.L_HI(net161));
 sg13g2_dfrbpq_1 _2928_ (.RESET_B(net162),
    .D(_0135_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_21_),
    .CLK(clk_i));
 sg13g2_tiehi _2928__163 (.L_HI(net162));
 sg13g2_dfrbpq_1 _2929_ (.RESET_B(net163),
    .D(_0134_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_22_),
    .CLK(clk_i));
 sg13g2_tiehi _2929__164 (.L_HI(net163));
 sg13g2_dfrbpq_1 _2930_ (.RESET_B(net164),
    .D(_0133_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_24_),
    .CLK(clk_i));
 sg13g2_tiehi _2930__165 (.L_HI(net164));
 sg13g2_dfrbpq_1 _2931_ (.RESET_B(net165),
    .D(_0132_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_25_),
    .CLK(clk_i));
 sg13g2_tiehi _2931__166 (.L_HI(net165));
 sg13g2_dfrbpq_1 _2932_ (.RESET_B(net166),
    .D(_0131_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_26_),
    .CLK(clk_i));
 sg13g2_tiehi _2932__167 (.L_HI(net166));
 sg13g2_dfrbpq_1 _2933_ (.RESET_B(net167),
    .D(_0130_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_27_),
    .CLK(clk_i));
 sg13g2_tiehi _2933__168 (.L_HI(net167));
 sg13g2_dfrbpq_1 _2934_ (.RESET_B(net168),
    .D(_0129_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_28_),
    .CLK(clk_i));
 sg13g2_tiehi _2934__169 (.L_HI(net168));
 sg13g2_dfrbpq_1 _2935_ (.RESET_B(net169),
    .D(_0128_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_29_),
    .CLK(clk_i));
 sg13g2_tiehi _2935__170 (.L_HI(net169));
 sg13g2_dfrbpq_1 _2936_ (.RESET_B(net170),
    .D(_0127_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_30_),
    .CLK(clk_i));
 sg13g2_tiehi _2936__171 (.L_HI(net170));
 sg13g2_dfrbpq_1 _2937_ (.RESET_B(net171),
    .D(_0126_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_32_),
    .CLK(clk_i));
 sg13g2_tiehi _2937__172 (.L_HI(net171));
 sg13g2_dfrbpq_1 _2938_ (.RESET_B(net172),
    .D(_0125_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_33_),
    .CLK(clk_i));
 sg13g2_tiehi _2938__173 (.L_HI(net172));
 sg13g2_dfrbpq_1 _2939_ (.RESET_B(net173),
    .D(_0124_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_34_),
    .CLK(clk_i));
 sg13g2_tiehi _2939__174 (.L_HI(net173));
 sg13g2_dfrbpq_1 _2940_ (.RESET_B(net174),
    .D(_0123_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_35_),
    .CLK(clk_i));
 sg13g2_tiehi _2940__175 (.L_HI(net174));
 sg13g2_dfrbpq_1 _2941_ (.RESET_B(net175),
    .D(_0122_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_36_),
    .CLK(clk_i));
 sg13g2_tiehi _2941__176 (.L_HI(net175));
 sg13g2_dfrbpq_1 _2942_ (.RESET_B(net176),
    .D(_0121_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_37_),
    .CLK(clk_i));
 sg13g2_tiehi _2942__177 (.L_HI(net176));
 sg13g2_dfrbpq_1 _2943_ (.RESET_B(net177),
    .D(_0120_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_38_),
    .CLK(clk_i));
 sg13g2_tiehi _2943__178 (.L_HI(net177));
 sg13g2_dfrbpq_1 _2944_ (.RESET_B(net178),
    .D(_0119_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_40_),
    .CLK(clk_i));
 sg13g2_tiehi _2944__179 (.L_HI(net178));
 sg13g2_dfrbpq_1 _2945_ (.RESET_B(net179),
    .D(_0118_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_41_),
    .CLK(clk_i));
 sg13g2_tiehi _2945__180 (.L_HI(net179));
 sg13g2_dfrbpq_1 _2946_ (.RESET_B(net180),
    .D(_0117_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_42_),
    .CLK(clk_i));
 sg13g2_tiehi _2946__181 (.L_HI(net180));
 sg13g2_dfrbpq_1 _2947_ (.RESET_B(net181),
    .D(_0116_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_43_),
    .CLK(clk_i));
 sg13g2_tiehi _2947__182 (.L_HI(net181));
 sg13g2_dfrbpq_1 _2948_ (.RESET_B(net182),
    .D(_0115_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_44_),
    .CLK(clk_i));
 sg13g2_tiehi _2948__183 (.L_HI(net182));
 sg13g2_dfrbpq_1 _2949_ (.RESET_B(net183),
    .D(_0114_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_45_),
    .CLK(clk_i));
 sg13g2_tiehi _2949__184 (.L_HI(net183));
 sg13g2_dfrbpq_1 _2950_ (.RESET_B(net184),
    .D(_0113_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_46_),
    .CLK(clk_i));
 sg13g2_tiehi _2950__185 (.L_HI(net184));
 sg13g2_dfrbpq_1 _2951_ (.RESET_B(net185),
    .D(_0112_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_48_),
    .CLK(clk_i));
 sg13g2_tiehi _2951__186 (.L_HI(net185));
 sg13g2_dfrbpq_1 _2952_ (.RESET_B(net186),
    .D(_0111_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_49_),
    .CLK(clk_i));
 sg13g2_tiehi _2952__187 (.L_HI(net186));
 sg13g2_dfrbpq_1 _2953_ (.RESET_B(net187),
    .D(_0110_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_50_),
    .CLK(clk_i));
 sg13g2_tiehi _2953__188 (.L_HI(net187));
 sg13g2_dfrbpq_1 _2954_ (.RESET_B(net188),
    .D(_0109_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_51_),
    .CLK(clk_i));
 sg13g2_tiehi _2954__189 (.L_HI(net188));
 sg13g2_dfrbpq_1 _2955_ (.RESET_B(net189),
    .D(_0108_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_52_),
    .CLK(clk_i));
 sg13g2_tiehi _2955__190 (.L_HI(net189));
 sg13g2_dfrbpq_1 _2956_ (.RESET_B(net190),
    .D(_0107_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_53_),
    .CLK(clk_i));
 sg13g2_tiehi _2956__191 (.L_HI(net190));
 sg13g2_dfrbpq_1 _2957_ (.RESET_B(net191),
    .D(_0106_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_54_),
    .CLK(clk_i));
 sg13g2_tiehi _2957__192 (.L_HI(net191));
 sg13g2_dfrbpq_1 _2958_ (.RESET_B(net192),
    .D(_0105_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_56_),
    .CLK(clk_i));
 sg13g2_tiehi _2958__193 (.L_HI(net192));
 sg13g2_dfrbpq_1 _2959_ (.RESET_B(net193),
    .D(_0104_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_57_),
    .CLK(clk_i));
 sg13g2_tiehi _2959__194 (.L_HI(net193));
 sg13g2_dfrbpq_1 _2960_ (.RESET_B(net194),
    .D(_0103_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_58_),
    .CLK(clk_i));
 sg13g2_tiehi _2960__195 (.L_HI(net194));
 sg13g2_dfrbpq_1 _2961_ (.RESET_B(net195),
    .D(_0102_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_59_),
    .CLK(clk_i));
 sg13g2_tiehi _2961__196 (.L_HI(net195));
 sg13g2_dfrbpq_1 _2962_ (.RESET_B(net196),
    .D(_0101_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_60_),
    .CLK(clk_i));
 sg13g2_tiehi _2962__197 (.L_HI(net196));
 sg13g2_dfrbpq_1 _2963_ (.RESET_B(net197),
    .D(_0100_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_61_),
    .CLK(clk_i));
 sg13g2_tiehi _2963__198 (.L_HI(net197));
 sg13g2_dfrbpq_1 _2964_ (.RESET_B(net198),
    .D(_0099_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_62_),
    .CLK(clk_i));
 sg13g2_tiehi _2964__199 (.L_HI(net198));
 sg13g2_dfrbpq_1 _2965_ (.RESET_B(net369),
    .D(_0286_),
    .Q(_0037_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2966_ (.RESET_B(net369),
    .D(_0285_),
    .Q(_0036_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2967_ (.RESET_B(net369),
    .D(_0284_),
    .Q(_0035_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2968_ (.RESET_B(net369),
    .D(_0283_),
    .Q(_0034_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2969_ (.RESET_B(net370),
    .D(_0282_),
    .Q(_0033_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2970_ (.RESET_B(net370),
    .D(_0281_),
    .Q(_0032_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2971_ (.RESET_B(net370),
    .D(_0280_),
    .Q(_0031_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2972_ (.RESET_B(net370),
    .D(_0279_),
    .Q(_0030_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2973_ (.RESET_B(net370),
    .D(_0278_),
    .Q(_0029_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2974_ (.RESET_B(net370),
    .D(_0287_),
    .Q(_0038_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2975_ (.RESET_B(net361),
    .D(_0277_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2976_ (.RESET_B(net362),
    .D(_0276_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2977_ (.RESET_B(net362),
    .D(_0275_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2978_ (.RESET_B(net362),
    .D(_0274_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2979_ (.RESET_B(net362),
    .D(_0288_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2980_ (.RESET_B(net362),
    .D(_0161_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2981_ (.RESET_B(net362),
    .D(_0160_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2982_ (.RESET_B(net362),
    .D(_0159_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2983_ (.RESET_B(net362),
    .D(_0158_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2984_ (.RESET_B(net363),
    .D(_0305_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2985_ (.RESET_B(net370),
    .D(_0157_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2986_ (.RESET_B(net370),
    .D(_0156_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2987_ (.RESET_B(net371),
    .D(_0155_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2988_ (.RESET_B(net371),
    .D(_0306_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2989_ (.RESET_B(net371),
    .D(_0098_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2990_ (.RESET_B(net371),
    .D(_0097_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2991_ (.RESET_B(net371),
    .D(_0096_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2992_ (.RESET_B(net371),
    .D(_0315_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2993_ (.RESET_B(net363),
    .D(_0095_),
    .Q(u_uart_core_uart_rx_baud_div_q_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2994_ (.RESET_B(net363),
    .D(_0094_),
    .Q(u_uart_core_uart_rx_baud_div_q_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2995_ (.RESET_B(net363),
    .D(_0093_),
    .Q(u_uart_core_uart_rx_baud_div_q_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2996_ (.RESET_B(net363),
    .D(_0316_),
    .Q(u_uart_core_uart_rx_baud_div_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2997_ (.RESET_B(net363),
    .D(_0092_),
    .Q(u_uart_core_uart_rx_bit_cnt_q_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2998_ (.RESET_B(net363),
    .D(_0091_),
    .Q(u_uart_core_uart_rx_bit_cnt_q_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _2999_ (.RESET_B(net363),
    .D(_0090_),
    .Q(u_uart_core_uart_rx_bit_cnt_q_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3000_ (.RESET_B(net364),
    .D(_0317_),
    .Q(u_uart_core_uart_rx_bit_cnt_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3001_ (.RESET_B(net364),
    .D(_0318_),
    .Q(_0046_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3002_ (.RESET_B(net364),
    .D(_0089_),
    .Q(u_uart_core_uart_rx_sreg_q_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3003_ (.RESET_B(net364),
    .D(_0088_),
    .Q(u_uart_core_uart_rx_sreg_q_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3004_ (.RESET_B(net364),
    .D(_0087_),
    .Q(u_uart_core_uart_rx_sreg_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3005_ (.RESET_B(net364),
    .D(_0086_),
    .Q(u_uart_core_uart_rx_sreg_q_4_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3006_ (.RESET_B(net364),
    .D(_0085_),
    .Q(u_uart_core_uart_rx_sreg_q_5_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3007_ (.RESET_B(net364),
    .D(_0084_),
    .Q(u_uart_core_uart_rx_sreg_q_6_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3008_ (.RESET_B(net365),
    .D(_0083_),
    .Q(u_uart_core_uart_rx_sreg_q_7_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3009_ (.RESET_B(net365),
    .D(_0082_),
    .Q(u_uart_core_uart_rx_sreg_q_8_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3010_ (.RESET_B(net365),
    .D(_0081_),
    .Q(u_uart_core_uart_rx_sreg_q_9_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3011_ (.RESET_B(net365),
    .D(_0319_),
    .Q(u_uart_core_uart_rx_sreg_q_10_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3012_ (.RESET_B(net371),
    .D(_0080_),
    .Q(u_uart_core_uart_tx_baud_div_q_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3013_ (.RESET_B(net371),
    .D(_0079_),
    .Q(u_uart_core_uart_tx_baud_div_q_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3014_ (.RESET_B(net372),
    .D(_0078_),
    .Q(u_uart_core_uart_tx_baud_div_q_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3015_ (.RESET_B(net372),
    .D(_0320_),
    .Q(u_uart_core_uart_tx_baud_div_q_3_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3016_ (.RESET_B(net372),
    .D(_0077_),
    .Q(u_uart_core_uart_tx_bit_cnt_q_0_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3017_ (.RESET_B(net372),
    .D(_0076_),
    .Q(u_uart_core_uart_tx_bit_cnt_q_1_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3018_ (.RESET_B(net372),
    .D(_0075_),
    .Q(u_uart_core_uart_tx_bit_cnt_q_2_),
    .CLK(clk_i));
 sg13g2_dfrbpq_1 _3019_ (.RESET_B(net372),
    .D(_0321_),
    .Q(u_uart_core_uart_tx_bit_cnt_q_3_),
    .CLK(clk_i));
 sg13g2_buf_1 _3021_ (.A(net199),
    .X(reg_rsp_o[0]));
 sg13g2_tiehi _3021__200 (.L_HI(net199));
 sg13g2_buf_1 _3022_ (.A(u_uart_reg_reg_rsp_o_1_),
    .X(reg_rsp_o[1]));
 sg13g2_buf_1 _3023_ (.A(u_uart_reg_reg_rsp_o_2_),
    .X(reg_rsp_o[2]));
 sg13g2_buf_1 _3024_ (.A(u_uart_reg_reg_rsp_o_3_),
    .X(reg_rsp_o[3]));
 sg13g2_buf_1 _3025_ (.A(u_uart_reg_reg_rsp_o_4_),
    .X(reg_rsp_o[4]));
 sg13g2_buf_1 _3026_ (.A(u_uart_reg_reg_rsp_o_5_),
    .X(reg_rsp_o[5]));
 sg13g2_buf_1 _3027_ (.A(u_uart_reg_reg_rsp_o_6_),
    .X(reg_rsp_o[6]));
 sg13g2_buf_1 _3028_ (.A(u_uart_reg_reg_rsp_o_7_),
    .X(reg_rsp_o[7]));
 sg13g2_buf_1 _3029_ (.A(u_uart_reg_reg_rsp_o_8_),
    .X(reg_rsp_o[8]));
 sg13g2_buf_1 _3030_ (.A(u_uart_reg_reg_rsp_o_9_),
    .X(reg_rsp_o[9]));
 sg13g2_buf_1 _3031_ (.A(net285),
    .X(reg_rsp_o[10]));
 sg13g2_buf_1 _3032_ (.A(net285),
    .X(reg_rsp_o[11]));
 sg13g2_buf_1 _3033_ (.A(net285),
    .X(reg_rsp_o[12]));
 sg13g2_buf_1 _3034_ (.A(net285),
    .X(reg_rsp_o[13]));
 sg13g2_buf_1 _3035_ (.A(net285),
    .X(reg_rsp_o[14]));
 sg13g2_buf_1 _3036_ (.A(net285),
    .X(reg_rsp_o[15]));
 sg13g2_buf_1 _3037_ (.A(net285),
    .X(reg_rsp_o[16]));
 sg13g2_buf_1 _3038_ (.A(net285),
    .X(reg_rsp_o[17]));
 sg13g2_buf_1 _3039_ (.A(u_uart_reg_reg_rsp_o_18_),
    .X(reg_rsp_o[18]));
 sg13g2_buf_1 _3040_ (.A(u_uart_reg_reg_rsp_o_19_),
    .X(reg_rsp_o[19]));
 sg13g2_buf_1 _3041_ (.A(u_uart_reg_reg_rsp_o_20_),
    .X(reg_rsp_o[20]));
 sg13g2_buf_1 _3042_ (.A(u_uart_reg_reg_rsp_o_21_),
    .X(reg_rsp_o[21]));
 sg13g2_buf_1 _3043_ (.A(u_uart_reg_reg_rsp_o_22_),
    .X(reg_rsp_o[22]));
 sg13g2_buf_1 _3044_ (.A(u_uart_reg_reg_rsp_o_23_),
    .X(reg_rsp_o[23]));
 sg13g2_buf_1 _3045_ (.A(u_uart_reg_reg_rsp_o_24_),
    .X(reg_rsp_o[24]));
 sg13g2_buf_1 _3046_ (.A(u_uart_reg_reg_rsp_o_25_),
    .X(reg_rsp_o[25]));
 sg13g2_buf_1 _3047_ (.A(u_uart_reg_reg_rsp_o_26_),
    .X(reg_rsp_o[26]));
 sg13g2_buf_1 _3048_ (.A(u_uart_reg_reg_rsp_o_27_),
    .X(reg_rsp_o[27]));
 sg13g2_buf_1 _3049_ (.A(u_uart_reg_reg_rsp_o_28_),
    .X(reg_rsp_o[28]));
 sg13g2_buf_1 _3050_ (.A(u_uart_reg_reg_rsp_o_29_),
    .X(reg_rsp_o[29]));
 sg13g2_buf_1 _3051_ (.A(u_uart_reg_reg_rsp_o_30_),
    .X(reg_rsp_o[30]));
 sg13g2_buf_1 _3052_ (.A(u_uart_reg_reg_rsp_o_31_),
    .X(reg_rsp_o[31]));
 sg13g2_buf_1 _3053_ (.A(u_uart_reg_reg_rsp_o_32_),
    .X(reg_rsp_o[32]));
 sg13g2_buf_1 _3054_ (.A(u_uart_reg_reg_rsp_o_33_),
    .X(reg_rsp_o[33]));
 sg13g2_buf_4 gain201 (.X(net200),
    .A(_0609_));
 sg13g2_buf_4 gain202 (.X(net201),
    .A(_0609_));
 sg13g2_buf_4 gain203 (.X(net202),
    .A(_0557_));
 sg13g2_buf_4 gain204 (.X(net203),
    .A(_0557_));
 sg13g2_buf_1 gain205 (.A(_1169_),
    .X(net204));
 sg13g2_buf_4 gain206 (.X(net205),
    .A(_0707_));
 sg13g2_buf_4 gain207 (.X(net206),
    .A(_0707_));
 sg13g2_buf_4 gain208 (.X(net207),
    .A(_0689_));
 sg13g2_buf_4 gain209 (.X(net208),
    .A(_0689_));
 sg13g2_buf_4 gain210 (.X(net209),
    .A(_0664_));
 sg13g2_buf_4 gain211 (.X(net210),
    .A(_0664_));
 sg13g2_buf_4 gain212 (.X(net211),
    .A(_0646_));
 sg13g2_buf_4 gain213 (.X(net212),
    .A(_0646_));
 sg13g2_buf_4 gain214 (.X(net213),
    .A(_0628_));
 sg13g2_buf_4 gain215 (.X(net214),
    .A(_0628_));
 sg13g2_buf_4 gain216 (.X(net215),
    .A(_0569_));
 sg13g2_buf_4 gain217 (.X(net216),
    .A(_0569_));
 sg13g2_buf_4 gain218 (.X(net217),
    .A(_0725_));
 sg13g2_buf_4 gain219 (.X(net218),
    .A(_0725_));
 sg13g2_buf_4 gain220 (.X(net219),
    .A(_0716_));
 sg13g2_buf_4 gain221 (.X(net220),
    .A(_0716_));
 sg13g2_buf_4 gain222 (.X(net221),
    .A(_0698_));
 sg13g2_buf_4 gain223 (.X(net222),
    .A(_0698_));
 sg13g2_buf_4 gain224 (.X(net223),
    .A(_0680_));
 sg13g2_buf_4 gain225 (.X(net224),
    .A(_0680_));
 sg13g2_buf_4 gain226 (.X(net225),
    .A(_0655_));
 sg13g2_buf_4 gain227 (.X(net226),
    .A(_0655_));
 sg13g2_buf_4 gain228 (.X(net227),
    .A(_0637_));
 sg13g2_buf_4 gain229 (.X(net228),
    .A(_0637_));
 sg13g2_buf_4 gain230 (.X(net229),
    .A(_0619_));
 sg13g2_buf_4 gain231 (.X(net230),
    .A(_0619_));
 sg13g2_buf_4 gain232 (.X(net231),
    .A(_0600_));
 sg13g2_buf_4 gain233 (.X(net232),
    .A(_0600_));
 sg13g2_buf_8 gain234 (.A(_0493_),
    .X(net233));
 sg13g2_buf_8 gain235 (.A(_0475_),
    .X(net234));
 sg13g2_buf_4 gain236 (.X(net235),
    .A(_0452_));
 sg13g2_buf_4 gain237 (.X(net236),
    .A(_0452_));
 sg13g2_buf_4 gain238 (.X(net237),
    .A(_0365_));
 sg13g2_buf_4 gain239 (.X(net238),
    .A(_1347_));
 sg13g2_buf_4 gain240 (.X(net239),
    .A(_1347_));
 sg13g2_buf_4 gain241 (.X(net240),
    .A(_1347_));
 sg13g2_buf_8 gain242 (.A(_0531_),
    .X(net241));
 sg13g2_buf_4 gain243 (.X(net242),
    .A(_0516_));
 sg13g2_buf_4 gain244 (.X(net243),
    .A(_0516_));
 sg13g2_buf_8 gain245 (.A(_0512_),
    .X(net244));
 sg13g2_buf_4 gain246 (.X(net245),
    .A(_0497_));
 sg13g2_buf_4 gain247 (.X(net246),
    .A(_0497_));
 sg13g2_buf_4 gain248 (.X(net247),
    .A(_0478_));
 sg13g2_buf_4 gain249 (.X(net248),
    .A(_0478_));
 sg13g2_buf_4 gain250 (.X(net249),
    .A(_0401_));
 sg13g2_buf_8 gain251 (.A(_0363_),
    .X(net250));
 sg13g2_buf_4 gain252 (.X(net251),
    .A(_1346_));
 sg13g2_buf_4 gain253 (.X(net252),
    .A(_1346_));
 sg13g2_buf_8 gain254 (.A(net254),
    .X(net253));
 sg13g2_buf_1 gain255 (.A(u_uart_reg_u_reg_core_reg_we_check_3_),
    .X(net254));
 sg13g2_buf_4 gain256 (.X(net255),
    .A(net256));
 sg13g2_buf_2 gain257 (.A(_0404_),
    .X(net256));
 sg13g2_buf_4 gain258 (.X(net257),
    .A(_0361_));
 sg13g2_buf_4 gain259 (.X(net258),
    .A(_1262_));
 sg13g2_buf_4 gain260 (.X(net259),
    .A(_1238_));
 sg13g2_buf_4 gain261 (.X(net260),
    .A(_1238_));
 sg13g2_buf_4 gain262 (.X(net261),
    .A(_1234_));
 sg13g2_buf_4 gain263 (.X(net262),
    .A(_1234_));
 sg13g2_buf_4 gain264 (.X(net263),
    .A(net264));
 sg13g2_buf_4 gain265 (.X(net264),
    .A(_1099_));
 sg13g2_buf_4 gain266 (.X(net265),
    .A(_0895_));
 sg13g2_buf_4 gain267 (.X(net266),
    .A(_0895_));
 sg13g2_buf_4 gain268 (.X(net267),
    .A(_0596_));
 sg13g2_buf_4 gain269 (.X(net268),
    .A(_0596_));
 sg13g2_buf_4 gain270 (.X(net269),
    .A(_0592_));
 sg13g2_buf_4 gain271 (.X(net270),
    .A(_0592_));
 sg13g2_buf_4 gain272 (.X(net271),
    .A(_0588_));
 sg13g2_buf_4 gain273 (.X(net272),
    .A(_0588_));
 sg13g2_buf_4 gain274 (.X(net273),
    .A(_0584_));
 sg13g2_buf_4 gain275 (.X(net274),
    .A(_0584_));
 sg13g2_buf_4 gain276 (.X(net275),
    .A(_0580_));
 sg13g2_buf_4 gain277 (.X(net276),
    .A(_0580_));
 sg13g2_buf_4 gain278 (.X(net277),
    .A(_0576_));
 sg13g2_buf_4 gain279 (.X(net278),
    .A(_0576_));
 sg13g2_buf_4 gain280 (.X(net279),
    .A(_0572_));
 sg13g2_buf_4 gain281 (.X(net280),
    .A(_0572_));
 sg13g2_buf_4 gain282 (.X(net281),
    .A(_1237_));
 sg13g2_buf_4 gain283 (.X(net282),
    .A(_1237_));
 sg13g2_buf_4 gain284 (.X(net283),
    .A(_1233_));
 sg13g2_buf_2 gain285 (.A(_1233_),
    .X(net284));
 sg13g2_buf_1 gain286 (.A(net286),
    .X(net285));
 sg13g2_buf_4 gain287 (.X(net286),
    .A(u_uart_reg_reg_rsp_o_10_));
 sg13g2_buf_4 gain288 (.X(net287),
    .A(_1093_));
 sg13g2_buf_1 gain289 (.A(_1212_),
    .X(net288));
 sg13g2_buf_4 gain290 (.X(net289),
    .A(_1092_));
 sg13g2_buf_4 gain291 (.X(net290),
    .A(_0450_));
 sg13g2_buf_4 gain292 (.X(net291),
    .A(net294));
 sg13g2_buf_4 gain293 (.X(net292),
    .A(net294));
 sg13g2_buf_4 gain294 (.X(net293),
    .A(net294));
 sg13g2_buf_2 gain295 (.A(_1224_),
    .X(net294));
 sg13g2_buf_4 gain296 (.X(net295),
    .A(net297));
 sg13g2_buf_4 gain297 (.X(net296),
    .A(net297));
 sg13g2_buf_4 gain298 (.X(net297),
    .A(_1202_));
 sg13g2_buf_4 gain299 (.X(net298),
    .A(net299));
 sg13g2_buf_4 gain300 (.X(net299),
    .A(_0756_));
 sg13g2_buf_1 gain301 (.A(_0435_),
    .X(net300));
 sg13g2_buf_4 gain302 (.X(net301),
    .A(_1265_));
 sg13g2_buf_4 gain303 (.X(net302),
    .A(_1200_));
 sg13g2_buf_4 gain304 (.X(net303),
    .A(_1200_));
 sg13g2_buf_4 gain305 (.X(net304),
    .A(_1195_));
 sg13g2_buf_4 gain306 (.X(net305),
    .A(_1186_));
 sg13g2_buf_1 gain307 (.A(u_uart_core_uart_tx_bit_cnt_q_0_),
    .X(net306));
 sg13g2_buf_1 gain308 (.A(u_uart_core_uart_rx_sreg_q_9_),
    .X(net307));
 sg13g2_buf_1 gain309 (.A(u_uart_core_uart_rx_sreg_q_8_),
    .X(net308));
 sg13g2_buf_1 gain310 (.A(u_uart_core_uart_rx_sreg_q_7_),
    .X(net309));
 sg13g2_buf_1 gain311 (.A(u_uart_core_uart_rx_sreg_q_6_),
    .X(net310));
 sg13g2_buf_1 gain312 (.A(u_uart_core_uart_rx_sreg_q_5_),
    .X(net311));
 sg13g2_buf_1 gain313 (.A(u_uart_core_uart_rx_sreg_q_4_),
    .X(net312));
 sg13g2_buf_1 gain314 (.A(u_uart_core_uart_rx_sreg_q_3_),
    .X(net313));
 sg13g2_buf_1 gain315 (.A(u_uart_core_uart_rx_sreg_q_2_),
    .X(net314));
 sg13g2_buf_1 gain316 (.A(u_uart_core_uart_rx_bit_cnt_q_1_),
    .X(net315));
 sg13g2_buf_1 gain317 (.A(u_uart_core_uart_rx_bit_cnt_q_0_),
    .X(net316));
 sg13g2_buf_1 gain318 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_),
    .X(net317));
 sg13g2_buf_4 gain319 (.X(net318),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_));
 sg13g2_buf_1 gain320 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_0_),
    .X(net319));
 sg13g2_buf_4 gain321 (.X(net320),
    .A(net321));
 sg13g2_buf_1 gain322 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_2_),
    .X(net321));
 sg13g2_buf_4 gain323 (.X(net322),
    .A(net324));
 sg13g2_buf_4 gain324 (.X(net323),
    .A(net324));
 sg13g2_buf_4 gain325 (.X(net324),
    .A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_));
 sg13g2_buf_4 gain326 (.X(net325),
    .A(net332));
 sg13g2_buf_4 gain327 (.X(net326),
    .A(net332));
 sg13g2_buf_4 gain328 (.X(net327),
    .A(net332));
 sg13g2_buf_4 gain329 (.X(net328),
    .A(net333));
 sg13g2_buf_4 gain330 (.X(net329),
    .A(net333));
 sg13g2_buf_4 gain331 (.X(net330),
    .A(net333));
 sg13g2_buf_4 gain332 (.X(net331),
    .A(net334));
 sg13g2_buf_4 gain333 (.X(net332),
    .A(net334));
 sg13g2_buf_4 gain334 (.X(net333),
    .A(net334));
 sg13g2_buf_1 gain335 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .X(net334));
 sg13g2_buf_4 gain336 (.X(net335),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_));
 sg13g2_buf_8 gain337 (.A(net337),
    .X(net336));
 sg13g2_buf_1 gain338 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_),
    .X(net337));
 sg13g2_buf_2 gain339 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_),
    .X(net338));
 sg13g2_buf_1 gain340 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_0_),
    .X(net339));
 sg13g2_buf_4 gain341 (.X(net340),
    .A(net341));
 sg13g2_buf_1 gain342 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_),
    .X(net341));
 sg13g2_buf_4 gain343 (.X(net342),
    .A(net344));
 sg13g2_buf_4 gain344 (.X(net343),
    .A(net344));
 sg13g2_buf_2 gain345 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_),
    .X(net344));
 sg13g2_buf_4 gain346 (.X(net345),
    .A(net346));
 sg13g2_buf_4 gain347 (.X(net346),
    .A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_1_));
 sg13g2_buf_4 gain348 (.X(net347),
    .A(net352));
 sg13g2_buf_4 gain349 (.X(net348),
    .A(net352));
 sg13g2_buf_4 gain350 (.X(net349),
    .A(net352));
 sg13g2_buf_4 gain351 (.X(net350),
    .A(net352));
 sg13g2_buf_4 gain352 (.X(net351),
    .A(net352));
 sg13g2_buf_4 gain353 (.X(net352),
    .A(net353));
 sg13g2_buf_1 gain354 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_0_),
    .X(net353));
 sg13g2_buf_1 gain355 (.A(core_rst_ni),
    .X(net354));
 sg13g2_buf_8 gain356 (.A(net359),
    .X(net355));
 sg13g2_buf_8 gain357 (.A(net359),
    .X(net356));
 sg13g2_buf_8 gain358 (.A(net359),
    .X(net357));
 sg13g2_buf_8 gain359 (.A(net359),
    .X(net358));
 sg13g2_buf_8 gain360 (.A(reg_rst_ni),
    .X(net359));
 sg13g2_buf_1 gain361 (.A(u_uart_core_nco_sum_q_16_),
    .X(net360));
 sg13g2_buf_8 gain362 (.A(net365),
    .X(net361));
 sg13g2_buf_8 gain363 (.A(net365),
    .X(net362));
 sg13g2_buf_8 gain364 (.A(net365),
    .X(net363));
 sg13g2_buf_8 gain365 (.A(net365),
    .X(net364));
 sg13g2_buf_8 gain366 (.A(u_uart_core_rx_rst_ni),
    .X(net365));
 sg13g2_buf_8 gain367 (.A(net368),
    .X(net366));
 sg13g2_buf_8 gain368 (.A(net368),
    .X(net367));
 sg13g2_buf_2 gain369 (.A(u_uart_core_timing_rst_ni),
    .X(net368));
 sg13g2_buf_8 gain370 (.A(net372),
    .X(net369));
 sg13g2_buf_8 gain371 (.A(net372),
    .X(net370));
 sg13g2_buf_8 gain372 (.A(net373),
    .X(net371));
 sg13g2_buf_8 gain373 (.A(net373),
    .X(net372));
 sg13g2_buf_1 gain374 (.A(u_uart_core_tx_rst_ni),
    .X(net373));
 sg13g2_buf_1 gain375 (.A(reg2hw_12_),
    .X(net374));
 sg13g2_buf_4 gain376 (.X(net375),
    .A(reg2hw_11_));
 sg13g2_buf_4 gain377 (.X(net376),
    .A(reg2hw_10_));
 sg13g2_buf_4 gain378 (.X(net377),
    .A(reg2hw_9_));
 sg13g2_buf_4 gain379 (.X(net378),
    .A(reg2hw_8_));
 sg13g2_buf_4 gain380 (.X(net379),
    .A(reg2hw_7_));
 sg13g2_buf_4 gain381 (.X(net380),
    .A(reg2hw_6_));
 sg13g2_buf_4 gain382 (.X(net381),
    .A(reg2hw_5_));
 sg13g2_buf_1 gain383 (.A(reg2hw_34_),
    .X(net382));
 sg13g2_buf_4 gain384 (.X(net383),
    .A(net385));
 sg13g2_buf_4 gain385 (.X(net384),
    .A(net385));
 sg13g2_buf_2 gain386 (.A(reg2hw_39_),
    .X(net385));
 sg13g2_buf_1 gain387 (.A(_0018_),
    .X(net386));
 sg13g2_buf_1 gain388 (.A(reg2hw_38_),
    .X(net387));
endmodule
