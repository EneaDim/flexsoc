module uart_master (cio_rx_i,
    cio_tx_en_o,
    cio_tx_o,
    clk_i,
    err_i,
    gnt_i,
    req_o,
    rst_ni,
    valid_i,
    we_o,
    addr_o,
    be_o,
    rdata_i,
    tl_i,
    tl_o,
    wdata_o);
 input cio_rx_i;
 output cio_tx_en_o;
 output cio_tx_o;
 input clk_i;
 input err_i;
 input gnt_i;
 output req_o;
 input rst_ni;
 input valid_i;
 output we_o;
 output [31:0] addr_o;
 output [3:0] be_o;
 input [31:0] rdata_i;
 input [108:0] tl_i;
 output [65:0] tl_o;
 output [31:0] wdata_o;

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
 wire _1386_;
 wire _1387_;
 wire _1388_;
 wire _1389_;
 wire _1390_;
 wire net32;
 wire net24;
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
 wire u_uart_master_core_addr_o_10_;
 wire u_uart_master_core_addr_o_11_;
 wire u_uart_master_core_addr_o_12_;
 wire u_uart_master_core_addr_o_13_;
 wire u_uart_master_core_addr_o_14_;
 wire u_uart_master_core_addr_o_15_;
 wire u_uart_master_core_addr_o_16_;
 wire u_uart_master_core_addr_o_17_;
 wire u_uart_master_core_addr_o_18_;
 wire u_uart_master_core_addr_o_19_;
 wire u_uart_master_core_addr_o_20_;
 wire u_uart_master_core_addr_o_21_;
 wire u_uart_master_core_addr_o_22_;
 wire u_uart_master_core_addr_o_23_;
 wire u_uart_master_core_addr_o_24_;
 wire u_uart_master_core_addr_o_25_;
 wire u_uart_master_core_addr_o_26_;
 wire u_uart_master_core_addr_o_27_;
 wire u_uart_master_core_addr_o_28_;
 wire u_uart_master_core_addr_o_29_;
 wire u_uart_master_core_addr_o_2_;
 wire u_uart_master_core_addr_o_30_;
 wire u_uart_master_core_addr_o_31_;
 wire u_uart_master_core_addr_o_3_;
 wire u_uart_master_core_addr_o_4_;
 wire u_uart_master_core_addr_o_5_;
 wire u_uart_master_core_addr_o_6_;
 wire u_uart_master_core_addr_o_7_;
 wire u_uart_master_core_addr_o_8_;
 wire u_uart_master_core_addr_o_9_;
 wire u_uart_master_core_be_o_0_;
 wire u_uart_master_core_be_o_1_;
 wire u_uart_master_core_be_o_2_;
 wire u_uart_master_core_be_o_3_;
 wire u_uart_master_core_host_rst_ni;
 wire u_uart_master_core_u_host_bridge_any_err_q;
 wire u_uart_master_core_u_host_bridge_bebyte_q_0_;
 wire u_uart_master_core_u_host_bridge_bebyte_q_1_;
 wire u_uart_master_core_u_host_bridge_bebyte_q_2_;
 wire u_uart_master_core_u_host_bridge_bebyte_q_3_;
 wire u_uart_master_core_u_host_bridge_bus_rst_ni;
 wire u_uart_master_core_u_host_bridge_idx_q_0_;
 wire u_uart_master_core_u_host_bridge_idx_q_1_;
 wire u_uart_master_core_u_host_bridge_op_q_0_;
 wire u_uart_master_core_u_host_bridge_op_q_1_;
 wire u_uart_master_core_u_host_bridge_op_q_2_;
 wire u_uart_master_core_u_host_bridge_op_q_3_;
 wire u_uart_master_core_u_host_bridge_op_q_4_;
 wire u_uart_master_core_u_host_bridge_op_q_5_;
 wire u_uart_master_core_u_host_bridge_op_q_6_;
 wire u_uart_master_core_u_host_bridge_op_q_7_;
 wire u_uart_master_core_u_host_bridge_parser_rst_ni;
 wire u_uart_master_core_u_host_bridge_rdata_q_0_;
 wire u_uart_master_core_u_host_bridge_rdata_q_10_;
 wire u_uart_master_core_u_host_bridge_rdata_q_11_;
 wire u_uart_master_core_u_host_bridge_rdata_q_12_;
 wire u_uart_master_core_u_host_bridge_rdata_q_13_;
 wire u_uart_master_core_u_host_bridge_rdata_q_14_;
 wire u_uart_master_core_u_host_bridge_rdata_q_15_;
 wire u_uart_master_core_u_host_bridge_rdata_q_16_;
 wire u_uart_master_core_u_host_bridge_rdata_q_17_;
 wire u_uart_master_core_u_host_bridge_rdata_q_18_;
 wire u_uart_master_core_u_host_bridge_rdata_q_19_;
 wire u_uart_master_core_u_host_bridge_rdata_q_1_;
 wire u_uart_master_core_u_host_bridge_rdata_q_20_;
 wire u_uart_master_core_u_host_bridge_rdata_q_21_;
 wire u_uart_master_core_u_host_bridge_rdata_q_22_;
 wire u_uart_master_core_u_host_bridge_rdata_q_23_;
 wire u_uart_master_core_u_host_bridge_rdata_q_24_;
 wire u_uart_master_core_u_host_bridge_rdata_q_25_;
 wire u_uart_master_core_u_host_bridge_rdata_q_26_;
 wire u_uart_master_core_u_host_bridge_rdata_q_27_;
 wire u_uart_master_core_u_host_bridge_rdata_q_28_;
 wire u_uart_master_core_u_host_bridge_rdata_q_29_;
 wire u_uart_master_core_u_host_bridge_rdata_q_2_;
 wire u_uart_master_core_u_host_bridge_rdata_q_30_;
 wire u_uart_master_core_u_host_bridge_rdata_q_31_;
 wire u_uart_master_core_u_host_bridge_rdata_q_3_;
 wire u_uart_master_core_u_host_bridge_rdata_q_4_;
 wire u_uart_master_core_u_host_bridge_rdata_q_5_;
 wire u_uart_master_core_u_host_bridge_rdata_q_6_;
 wire u_uart_master_core_u_host_bridge_rdata_q_7_;
 wire u_uart_master_core_u_host_bridge_rdata_q_8_;
 wire u_uart_master_core_u_host_bridge_rdata_q_9_;
 wire u_uart_master_core_u_host_bridge_response_rst_ni;
 wire u_uart_master_core_u_host_bridge_rxf_st_q_0_;
 wire u_uart_master_core_u_host_bridge_rxf_st_q_1_;
 wire u_uart_master_core_u_host_bridge_rxf_st_q_2_;
 wire u_uart_master_core_u_host_bridge_sh_q_10_;
 wire u_uart_master_core_u_host_bridge_sh_q_11_;
 wire u_uart_master_core_u_host_bridge_sh_q_12_;
 wire u_uart_master_core_u_host_bridge_sh_q_13_;
 wire u_uart_master_core_u_host_bridge_sh_q_14_;
 wire u_uart_master_core_u_host_bridge_sh_q_15_;
 wire u_uart_master_core_u_host_bridge_sh_q_16_;
 wire u_uart_master_core_u_host_bridge_sh_q_17_;
 wire u_uart_master_core_u_host_bridge_sh_q_18_;
 wire u_uart_master_core_u_host_bridge_sh_q_19_;
 wire u_uart_master_core_u_host_bridge_sh_q_20_;
 wire u_uart_master_core_u_host_bridge_sh_q_21_;
 wire u_uart_master_core_u_host_bridge_sh_q_22_;
 wire u_uart_master_core_u_host_bridge_sh_q_23_;
 wire u_uart_master_core_u_host_bridge_sh_q_24_;
 wire u_uart_master_core_u_host_bridge_sh_q_25_;
 wire u_uart_master_core_u_host_bridge_sh_q_26_;
 wire u_uart_master_core_u_host_bridge_sh_q_27_;
 wire u_uart_master_core_u_host_bridge_sh_q_28_;
 wire u_uart_master_core_u_host_bridge_sh_q_29_;
 wire u_uart_master_core_u_host_bridge_sh_q_30_;
 wire u_uart_master_core_u_host_bridge_sh_q_31_;
 wire u_uart_master_core_u_host_bridge_sh_q_8_;
 wire u_uart_master_core_u_host_bridge_sh_q_9_;
 wire u_uart_master_core_u_host_bridge_tx_idx_d_0_;
 wire u_uart_master_core_u_host_bridge_tx_idx_d_1_;
 wire u_uart_master_core_u_host_bridge_tx_idx_d_2_;
 wire u_uart_master_core_u_host_bridge_tx_idx_d_3_;
 wire u_uart_master_core_u_host_bridge_tx_idx_q_0_;
 wire u_uart_master_core_u_host_bridge_tx_idx_q_1_;
 wire u_uart_master_core_u_host_bridge_tx_idx_q_2_;
 wire u_uart_master_core_u_host_bridge_tx_idx_q_3_;
 wire u_uart_master_core_u_host_bridge_tx_st_d_0_;
 wire u_uart_master_core_u_host_bridge_tx_st_q_0_;
 wire u_uart_master_core_u_host_bridge_tx_st_q_1_;
 wire u_uart_master_core_u_host_bridge_wdata_o_0_;
 wire u_uart_master_core_u_host_bridge_wdata_o_10_;
 wire u_uart_master_core_u_host_bridge_wdata_o_11_;
 wire u_uart_master_core_u_host_bridge_wdata_o_12_;
 wire u_uart_master_core_u_host_bridge_wdata_o_13_;
 wire u_uart_master_core_u_host_bridge_wdata_o_14_;
 wire u_uart_master_core_u_host_bridge_wdata_o_15_;
 wire u_uart_master_core_u_host_bridge_wdata_o_16_;
 wire u_uart_master_core_u_host_bridge_wdata_o_17_;
 wire u_uart_master_core_u_host_bridge_wdata_o_18_;
 wire u_uart_master_core_u_host_bridge_wdata_o_19_;
 wire u_uart_master_core_u_host_bridge_wdata_o_1_;
 wire u_uart_master_core_u_host_bridge_wdata_o_20_;
 wire u_uart_master_core_u_host_bridge_wdata_o_21_;
 wire u_uart_master_core_u_host_bridge_wdata_o_22_;
 wire u_uart_master_core_u_host_bridge_wdata_o_23_;
 wire u_uart_master_core_u_host_bridge_wdata_o_24_;
 wire u_uart_master_core_u_host_bridge_wdata_o_25_;
 wire u_uart_master_core_u_host_bridge_wdata_o_26_;
 wire u_uart_master_core_u_host_bridge_wdata_o_27_;
 wire u_uart_master_core_u_host_bridge_wdata_o_28_;
 wire u_uart_master_core_u_host_bridge_wdata_o_29_;
 wire u_uart_master_core_u_host_bridge_wdata_o_2_;
 wire u_uart_master_core_u_host_bridge_wdata_o_30_;
 wire u_uart_master_core_u_host_bridge_wdata_o_31_;
 wire u_uart_master_core_u_host_bridge_wdata_o_3_;
 wire u_uart_master_core_u_host_bridge_wdata_o_4_;
 wire u_uart_master_core_u_host_bridge_wdata_o_5_;
 wire u_uart_master_core_u_host_bridge_wdata_o_6_;
 wire u_uart_master_core_u_host_bridge_wdata_o_7_;
 wire u_uart_master_core_u_host_bridge_wdata_o_8_;
 wire u_uart_master_core_u_host_bridge_wdata_o_9_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_0_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_10_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_11_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_12_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_13_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_14_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_15_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_16_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_1_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_2_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_3_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_4_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_5_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_6_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_7_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_8_;
 wire u_uart_master_core_u_uart_core_nco_sum_q_9_;
 wire u_uart_master_core_u_uart_core_rst_ni;
 wire u_uart_master_core_u_uart_core_rx_fifo_data_0_;
 wire u_uart_master_core_u_uart_core_rx_fifo_data_1_;
 wire u_uart_master_core_u_uart_core_rx_fifo_data_2_;
 wire u_uart_master_core_u_uart_core_rx_fifo_data_3_;
 wire u_uart_master_core_u_uart_core_rx_fifo_data_4_;
 wire u_uart_master_core_u_uart_core_rx_fifo_data_5_;
 wire u_uart_master_core_u_uart_core_rx_fifo_data_6_;
 wire u_uart_master_core_u_uart_core_rx_fifo_data_7_;
 wire u_uart_master_core_u_uart_core_rx_sync;
 wire u_uart_master_core_u_uart_core_rx_sync_q1;
 wire u_uart_master_core_u_uart_core_rx_sync_q2;
 wire u_uart_master_core_u_uart_core_rx_tick_baud;
 wire u_uart_master_core_u_uart_core_rx_valid;
 wire u_uart_master_core_u_uart_core_sync_rx_intq;
 wire u_uart_master_core_u_uart_core_tx_fifo_wdata_0_;
 wire u_uart_master_core_u_uart_core_tx_fifo_wdata_1_;
 wire u_uart_master_core_u_uart_core_tx_fifo_wdata_2_;
 wire u_uart_master_core_u_uart_core_tx_fifo_wdata_3_;
 wire u_uart_master_core_u_uart_core_tx_fifo_wdata_4_;
 wire u_uart_master_core_u_uart_core_tx_fifo_wdata_5_;
 wire u_uart_master_core_u_uart_core_tx_fifo_wdata_6_;
 wire u_uart_master_core_u_uart_core_tx_fifo_wdata_7_;
 wire u_uart_master_core_u_uart_core_tx_out;
 wire u_uart_master_core_u_uart_core_tx_out_q;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_0_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_1_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_0_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_0_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_100_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_101_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_102_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_103_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_104_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_105_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_106_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_107_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_108_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_109_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_10_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_110_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_111_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_112_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_113_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_114_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_115_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_116_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_117_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_118_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_119_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_11_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_120_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_121_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_122_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_123_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_124_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_125_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_126_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_127_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_12_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_13_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_14_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_15_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_16_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_17_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_18_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_19_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_1_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_20_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_21_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_22_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_23_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_24_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_25_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_26_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_27_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_28_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_29_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_2_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_30_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_31_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_32_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_33_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_34_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_35_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_36_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_37_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_38_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_39_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_3_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_40_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_41_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_42_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_43_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_44_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_45_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_46_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_47_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_48_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_49_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_4_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_50_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_51_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_52_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_53_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_54_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_55_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_56_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_57_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_58_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_59_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_5_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_60_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_61_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_62_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_63_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_64_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_65_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_66_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_67_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_68_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_69_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_6_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_70_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_71_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_72_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_73_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_74_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_75_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_76_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_77_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_78_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_79_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_7_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_80_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_81_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_82_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_83_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_84_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_85_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_86_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_87_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_88_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_89_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_8_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_90_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_91_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_92_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_93_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_94_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_95_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_96_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_97_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_98_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_99_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_9_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_;
 wire u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_under_rst;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_2_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_0_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_0_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_10_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_11_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_12_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_13_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_14_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_15_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_16_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_17_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_18_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_19_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_1_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_20_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_21_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_22_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_23_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_24_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_25_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_26_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_27_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_28_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_29_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_2_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_30_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_31_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_32_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_33_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_34_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_35_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_36_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_37_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_38_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_39_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_3_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_40_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_41_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_42_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_43_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_44_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_45_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_46_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_47_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_48_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_49_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_4_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_50_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_51_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_52_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_53_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_54_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_55_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_56_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_57_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_58_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_59_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_5_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_60_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_61_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_62_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_63_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_6_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_7_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_8_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_9_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_;
 wire u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_under_rst;
 wire u_uart_master_core_u_uart_core_uart_rx_baud_div_q_0_;
 wire u_uart_master_core_u_uart_core_uart_rx_baud_div_q_1_;
 wire u_uart_master_core_u_uart_core_uart_rx_baud_div_q_2_;
 wire u_uart_master_core_u_uart_core_uart_rx_baud_div_q_3_;
 wire u_uart_master_core_u_uart_core_uart_rx_bit_cnt_q_0_;
 wire u_uart_master_core_u_uart_core_uart_rx_bit_cnt_q_1_;
 wire u_uart_master_core_u_uart_core_uart_rx_bit_cnt_q_2_;
 wire u_uart_master_core_u_uart_core_uart_rx_bit_cnt_q_3_;
 wire u_uart_master_core_u_uart_core_uart_rx_sreg_q_10_;
 wire u_uart_master_core_u_uart_core_uart_rx_sreg_q_1_;
 wire u_uart_master_core_u_uart_core_uart_rx_sreg_q_2_;
 wire u_uart_master_core_u_uart_core_uart_rx_sreg_q_3_;
 wire u_uart_master_core_u_uart_core_uart_rx_sreg_q_4_;
 wire u_uart_master_core_u_uart_core_uart_rx_sreg_q_5_;
 wire u_uart_master_core_u_uart_core_uart_rx_sreg_q_6_;
 wire u_uart_master_core_u_uart_core_uart_rx_sreg_q_7_;
 wire u_uart_master_core_u_uart_core_uart_rx_sreg_q_8_;
 wire u_uart_master_core_u_uart_core_uart_rx_sreg_q_9_;
 wire u_uart_master_core_u_uart_core_uart_rx_tick_baud_d;
 wire u_uart_master_core_u_uart_core_uart_tx_baud_div_q_0_;
 wire u_uart_master_core_u_uart_core_uart_tx_baud_div_q_1_;
 wire u_uart_master_core_u_uart_core_uart_tx_baud_div_q_2_;
 wire u_uart_master_core_u_uart_core_uart_tx_baud_div_q_3_;
 wire u_uart_master_core_u_uart_core_uart_tx_bit_cnt_q_0_;
 wire u_uart_master_core_u_uart_core_uart_tx_bit_cnt_q_1_;
 wire u_uart_master_core_u_uart_core_uart_tx_bit_cnt_q_2_;
 wire u_uart_master_core_u_uart_core_uart_tx_bit_cnt_q_3_;
 wire u_uart_master_core_u_uart_core_uart_tx_sreg_q_0_;
 wire u_uart_master_core_u_uart_core_uart_tx_sreg_q_1_;
 wire u_uart_master_core_u_uart_core_uart_tx_sreg_q_2_;
 wire u_uart_master_core_u_uart_core_uart_tx_sreg_q_3_;
 wire u_uart_master_core_u_uart_core_uart_tx_sreg_q_4_;
 wire u_uart_master_core_u_uart_core_uart_tx_sreg_q_5_;
 wire u_uart_master_core_u_uart_core_uart_tx_sreg_q_6_;
 wire u_uart_master_core_u_uart_core_uart_tx_sreg_q_7_;
 wire u_uart_master_core_u_uart_core_uart_tx_sreg_q_8_;
 wire u_uart_master_core_u_uart_core_uart_tx_sreg_q_9_;
 wire u_uart_master_core_u_uart_core_uart_tx_tick_baud_q;
 wire u_uart_master_reg_tl_o_0_;
 wire u_uart_master_reg_tl_o_16_;
 wire u_uart_master_reg_tl_o_17_;
 wire u_uart_master_reg_tl_o_18_;
 wire u_uart_master_reg_tl_o_19_;
 wire u_uart_master_reg_tl_o_1_;
 wire u_uart_master_reg_tl_o_20_;
 wire u_uart_master_reg_tl_o_21_;
 wire u_uart_master_reg_tl_o_22_;
 wire u_uart_master_reg_tl_o_23_;
 wire u_uart_master_reg_tl_o_24_;
 wire u_uart_master_reg_tl_o_25_;
 wire u_uart_master_reg_tl_o_26_;
 wire u_uart_master_reg_tl_o_27_;
 wire u_uart_master_reg_tl_o_28_;
 wire u_uart_master_reg_tl_o_29_;
 wire u_uart_master_reg_tl_o_30_;
 wire u_uart_master_reg_tl_o_31_;
 wire u_uart_master_reg_tl_o_32_;
 wire u_uart_master_reg_tl_o_33_;
 wire u_uart_master_reg_tl_o_34_;
 wire u_uart_master_reg_tl_o_35_;
 wire u_uart_master_reg_tl_o_36_;
 wire u_uart_master_reg_tl_o_37_;
 wire u_uart_master_reg_tl_o_38_;
 wire u_uart_master_reg_tl_o_39_;
 wire u_uart_master_reg_tl_o_40_;
 wire u_uart_master_reg_tl_o_41_;
 wire u_uart_master_reg_tl_o_42_;
 wire u_uart_master_reg_tl_o_43_;
 wire u_uart_master_reg_tl_o_44_;
 wire u_uart_master_reg_tl_o_45_;
 wire u_uart_master_reg_tl_o_46_;
 wire u_uart_master_reg_tl_o_47_;
 wire u_uart_master_reg_tl_o_49_;
 wire u_uart_master_reg_tl_o_50_;
 wire u_uart_master_reg_tl_o_51_;
 wire u_uart_master_reg_tl_o_52_;
 wire u_uart_master_reg_tl_o_53_;
 wire u_uart_master_reg_tl_o_54_;
 wire u_uart_master_reg_tl_o_55_;
 wire u_uart_master_reg_tl_o_56_;
 wire u_uart_master_reg_tl_o_57_;
 wire u_uart_master_reg_tl_o_58_;
 wire u_uart_master_reg_tl_o_62_;
 wire u_uart_master_reg_tl_o_65_;
 wire u_uart_master_reg_u_reg_core_fifo_ctrl_flds_we_0_;
 wire u_uart_master_reg_u_reg_core_reg_we_check_3_;
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
 wire net25;
 wire net26;
 wire net27;
 wire net28;
 wire net29;
 wire net30;
 wire net31;
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

 sky130_fd_sc_hd__nor3_1 _1393_ (.A(_0915_),
    .B(_1048_),
    .C(_1062_),
    .Y(_1063_));
 sky130_fd_sc_hd__a21oi_1 _1394_ (.A1(reg2hw_35_),
    .A2(net66),
    .B1(_1063_),
    .Y(_1064_));
 sky130_fd_sc_hd__nor2_1 _1395_ (.A(u_uart_master_reg_tl_o_17_),
    .B(_0945_),
    .Y(_1065_));
 sky130_fd_sc_hd__a31oi_1 _1396_ (.A1(_1059_),
    .A2(_1060_),
    .A3(_1064_),
    .B1(_1065_),
    .Y(_0240_));
 sky130_fd_sc_hd__lpflow_clkinvkapwr_1 _1397_ (.A(net115),
    .Y(_1066_));
 sky130_fd_sc_hd__o22ai_1 _1398_ (.A1(_0336_),
    .A2(_0915_),
    .B1(net81),
    .B2(_0911_),
    .Y(_1067_));
 sky130_fd_sc_hd__o21ai_0 _1399_ (.A1(_1039_),
    .A2(_0339_),
    .B1(net57),
    .Y(_1068_));
 sky130_fd_sc_hd__nor2_1 _1400_ (.A(_1021_),
    .B(_0696_),
    .Y(_1069_));
 sky130_fd_sc_hd__o32a_1 _1401_ (.A1(_1067_),
    .A2(_1068_),
    .A3(_1069_),
    .B1(u_uart_master_reg_tl_o_16_),
    .B2(net60),
    .X(_0241_));
 sky130_fd_sc_hd__nand2_4 _1402_ (.A(_1045_),
    .B(u_uart_master_core_u_uart_core_uart_tx_tick_baud_q),
    .Y(_1070_));
 sky130_fd_sc_hd__inv_2 _1403_ (.A(_1070_),
    .Y(_1071_));
 sky130_fd_sc_hd__nor2_1 _1404_ (.A(net81),
    .B(_1071_),
    .Y(_1072_));
 sky130_fd_sc_hd__inv_2 _1405_ (.A(_1072_),
    .Y(_1073_));
 sky130_fd_sc_hd__nand3_1 _1406_ (.A(_1037_),
    .B(_1038_),
    .C(_1046_),
    .Y(_1074_));
 sky130_fd_sc_hd__inv_2 _1407_ (.A(net56),
    .Y(_1075_));
 sky130_fd_sc_hd__nor2_4 _1408_ (.A(_1073_),
    .B(_1075_),
    .Y(_1076_));
 sky130_fd_sc_hd__inv_2 _1409_ (.A(_1076_),
    .Y(_1077_));
 sky130_fd_sc_hd__nor2_2 _1410_ (.A(net81),
    .B(_1076_),
    .Y(_1078_));
 sky130_fd_sc_hd__inv_1 _1411_ (.A(_1041_),
    .Y(_1079_));
 sky130_fd_sc_hd__nand2_1 _1412_ (.A(_1079_),
    .B(u_uart_master_core_u_uart_core_uart_tx_bit_cnt_q_2_),
    .Y(_1080_));
 sky130_fd_sc_hd__a21oi_1 _1413_ (.A1(_1043_),
    .A2(_1080_),
    .B1(_1075_),
    .Y(_1081_));
 sky130_fd_sc_hd__nand2_1 _1414_ (.A(_1078_),
    .B(_1081_),
    .Y(_1082_));
 sky130_fd_sc_hd__o21ai_0 _1415_ (.A1(_1042_),
    .A2(_1077_),
    .B1(_1082_),
    .Y(_0242_));
 sky130_fd_sc_hd__inv_1 _1416_ (.A(_1078_),
    .Y(_1083_));
 sky130_fd_sc_hd__inv_1 _1417_ (.A(u_uart_master_core_u_uart_core_uart_tx_bit_cnt_q_0_),
    .Y(_1084_));
 sky130_fd_sc_hd__o21ai_0 _1418_ (.A1(net81),
    .A2(_1084_),
    .B1(_1077_),
    .Y(_1085_));
 sky130_fd_sc_hd__nand2_1 _1419_ (.A(_1085_),
    .B(u_uart_master_core_u_uart_core_uart_tx_bit_cnt_q_1_),
    .Y(_1086_));
 sky130_fd_sc_hd__o21ai_0 _1420_ (.A1(_1079_),
    .A2(_1083_),
    .B1(_1086_),
    .Y(_0243_));
 sky130_fd_sc_hd__nor2_1 _1421_ (.A(net81),
    .B(net56),
    .Y(_1087_));
 sky130_fd_sc_hd__inv_1 _1422_ (.A(_1087_),
    .Y(_1088_));
 sky130_fd_sc_hd__nor2_1 _1423_ (.A(_1384_),
    .B(_1088_),
    .Y(_1089_));
 sky130_fd_sc_hd__a21oi_1 _1424_ (.A1(_1084_),
    .A2(_1088_),
    .B1(_1089_),
    .Y(_1090_));
 sky130_fd_sc_hd__o22ai_1 _1425_ (.A1(_1084_),
    .A2(_1077_),
    .B1(_1083_),
    .B2(_1090_),
    .Y(_0244_));
 sky130_fd_sc_hd__nand3_1 _1426_ (.A(u_uart_master_core_u_uart_core_uart_tx_baud_div_q_1_),
    .B(u_uart_master_core_u_uart_core_uart_tx_baud_div_q_0_),
    .C(net99),
    .Y(_1091_));
 sky130_fd_sc_hd__xnor2_1 _1427_ (.A(u_uart_master_core_u_uart_core_uart_tx_baud_div_q_2_),
    .B(_1091_),
    .Y(_0245_));
 sky130_fd_sc_hd__a21oi_1 _1428_ (.A1(u_uart_master_core_u_uart_core_uart_tx_baud_div_q_0_),
    .A2(net99),
    .B1(u_uart_master_core_u_uart_core_uart_tx_baud_div_q_1_),
    .Y(_1092_));
 sky130_fd_sc_hd__inv_1 _1429_ (.A(_1091_),
    .Y(_1093_));
 sky130_fd_sc_hd__nor2_1 _1430_ (.A(_1092_),
    .B(_1093_),
    .Y(_0246_));
 sky130_fd_sc_hd__xor2_1 _1431_ (.A(u_uart_master_core_u_uart_core_uart_tx_baud_div_q_0_),
    .B(net99),
    .X(_0247_));
 sky130_fd_sc_hd__inv_1 _1432_ (.A(u_uart_master_core_u_uart_core_uart_rx_sreg_q_10_),
    .Y(_1094_));
 sky130_fd_sc_hd__inv_1 _1433_ (.A(u_uart_master_core_u_uart_core_rx_tick_baud),
    .Y(_1095_));
 sky130_fd_sc_hd__nor2_1 _1434_ (.A(hw2reg_28_),
    .B(_1095_),
    .Y(_1096_));
 sky130_fd_sc_hd__inv_1 _1435_ (.A(_1096_),
    .Y(_1097_));
 sky130_fd_sc_hd__xor2_1 _1436_ (.A(net117),
    .B(net134),
    .X(_1098_));
 sky130_fd_sc_hd__inv_1 _1437_ (.A(u_uart_master_core_u_uart_core_uart_rx_bit_cnt_q_2_),
    .Y(_1099_));
 sky130_fd_sc_hd__nand3_1 _1438_ (.A(_1099_),
    .B(net133),
    .C(net132),
    .Y(_1100_));
 sky130_fd_sc_hd__inv_1 _1439_ (.A(u_uart_master_core_u_uart_core_rx_sync_q1),
    .Y(_1101_));
 sky130_fd_sc_hd__a21oi_1 _1440_ (.A1(reg2hw_36_),
    .A2(u_uart_master_core_u_uart_core_rx_sync_q2),
    .B1(u_uart_master_core_u_uart_core_rx_sync),
    .Y(_1102_));
 sky130_fd_sc_hd__nor2_1 _1441_ (.A(net124),
    .B(reg2hw_37_),
    .Y(_1103_));
 sky130_fd_sc_hd__inv_1 _1442_ (.A(reg2hw_36_),
    .Y(_1104_));
 sky130_fd_sc_hd__o21ai_0 _1443_ (.A1(u_uart_master_core_u_uart_core_rx_sync_q2),
    .A2(_1104_),
    .B1(u_uart_master_core_u_uart_core_rx_sync),
    .Y(_1105_));
 sky130_fd_sc_hd__o211ai_1 _1444_ (.A1(_1101_),
    .A2(_1102_),
    .B1(_1103_),
    .C1(_1105_),
    .Y(_1106_));
 sky130_fd_sc_hd__o21ai_2 _1445_ (.A1(_1030_),
    .A2(u_uart_master_core_u_uart_core_tx_out),
    .B1(_1106_),
    .Y(_1107_));
 sky130_fd_sc_hd__nor3_2 _1446_ (.A(_1098_),
    .B(_1100_),
    .C(_1107_),
    .Y(_1108_));
 sky130_fd_sc_hd__nor2_2 _1447_ (.A(_1097_),
    .B(_1108_),
    .Y(_1109_));
 sky130_fd_sc_hd__inv_4 _1448_ (.A(_1109_),
    .Y(_1110_));
 sky130_fd_sc_hd__clkinv_1 _1449_ (.A(u_uart_master_core_u_uart_core_uart_rx_sreg_q_9_),
    .Y(_1111_));
 sky130_fd_sc_hd__inv_1 _1450_ (.A(hw2reg_28_),
    .Y(_1112_));
 sky130_fd_sc_hd__clkinv_1 _1451_ (.A(_1107_),
    .Y(_1113_));
 sky130_fd_sc_hd__nor2_4 _1452_ (.A(_1112_),
    .B(_1113_),
    .Y(_1114_));
 sky130_fd_sc_hd__nor2_2 _1453_ (.A(_1096_),
    .B(_1114_),
    .Y(_1115_));
 sky130_fd_sc_hd__nor2_4 _1454_ (.A(_1108_),
    .B(_1115_),
    .Y(_1116_));
 sky130_fd_sc_hd__o22ai_1 _1455_ (.A1(_1094_),
    .A2(_1110_),
    .B1(_1111_),
    .B2(_1116_),
    .Y(_0248_));
 sky130_fd_sc_hd__clkinv_1 _1456_ (.A(net125),
    .Y(_1117_));
 sky130_fd_sc_hd__o22ai_1 _1457_ (.A1(_1111_),
    .A2(_1110_),
    .B1(_1117_),
    .B2(_1116_),
    .Y(_0249_));
 sky130_fd_sc_hd__o22ai_1 _1458_ (.A1(_1117_),
    .A2(_1110_),
    .B1(_0358_),
    .B2(_1116_),
    .Y(_0250_));
 sky130_fd_sc_hd__o22ai_1 _1459_ (.A1(_0358_),
    .A2(_1110_),
    .B1(_0491_),
    .B2(_1116_),
    .Y(_0251_));
 sky130_fd_sc_hd__clkinv_1 _1460_ (.A(net128),
    .Y(_1118_));
 sky130_fd_sc_hd__o22ai_1 _1461_ (.A1(_0491_),
    .A2(_1110_),
    .B1(_1118_),
    .B2(_1116_),
    .Y(_0252_));
 sky130_fd_sc_hd__clkinv_1 _1462_ (.A(net129),
    .Y(_1119_));
 sky130_fd_sc_hd__o22ai_1 _1463_ (.A1(_1118_),
    .A2(_1110_),
    .B1(_1119_),
    .B2(_1116_),
    .Y(_0253_));
 sky130_fd_sc_hd__o22ai_1 _1464_ (.A1(_1119_),
    .A2(_1110_),
    .B1(_0790_),
    .B2(_1116_),
    .Y(_0254_));
 sky130_fd_sc_hd__o22ai_1 _1465_ (.A1(_0790_),
    .A2(_1110_),
    .B1(_0356_),
    .B2(_1116_),
    .Y(_0255_));
 sky130_fd_sc_hd__inv_1 _1466_ (.A(u_uart_master_core_u_uart_core_uart_rx_sreg_q_1_),
    .Y(_1120_));
 sky130_fd_sc_hd__o22ai_1 _1467_ (.A1(_0356_),
    .A2(_1110_),
    .B1(_1120_),
    .B2(_1116_),
    .Y(_0256_));
 sky130_fd_sc_hd__nor2_1 _1468_ (.A(net134),
    .B(net133),
    .Y(_1121_));
 sky130_fd_sc_hd__inv_1 _1469_ (.A(_1121_),
    .Y(_1122_));
 sky130_fd_sc_hd__a21oi_1 _1470_ (.A1(_1109_),
    .A2(_1122_),
    .B1(_1115_),
    .Y(_1123_));
 sky130_fd_sc_hd__nor2_1 _1471_ (.A(u_uart_master_core_u_uart_core_uart_rx_bit_cnt_q_2_),
    .B(_1122_),
    .Y(_1124_));
 sky130_fd_sc_hd__nand2_1 _1472_ (.A(_1109_),
    .B(_1124_),
    .Y(_1125_));
 sky130_fd_sc_hd__o21ai_0 _1473_ (.A1(_1099_),
    .A2(_1123_),
    .B1(_1125_),
    .Y(_0257_));
 sky130_fd_sc_hd__inv_1 _1474_ (.A(net134),
    .Y(_1126_));
 sky130_fd_sc_hd__nor2_1 _1475_ (.A(net133),
    .B(_1126_),
    .Y(_1127_));
 sky130_fd_sc_hd__inv_1 _1476_ (.A(net133),
    .Y(_1128_));
 sky130_fd_sc_hd__nor2_1 _1477_ (.A(net134),
    .B(_1128_),
    .Y(_1129_));
 sky130_fd_sc_hd__a21oi_1 _1478_ (.A1(net133),
    .A2(_1097_),
    .B1(_1114_),
    .Y(_1130_));
 sky130_fd_sc_hd__o31ai_1 _1479_ (.A1(_1127_),
    .A2(_1129_),
    .A3(_1110_),
    .B1(_1130_),
    .Y(_0258_));
 sky130_fd_sc_hd__nand2_1 _1480_ (.A(_1115_),
    .B(net134),
    .Y(_1131_));
 sky130_fd_sc_hd__a22oi_1 _1481_ (.A1(_1114_),
    .A2(net117),
    .B1(_1109_),
    .B2(_1126_),
    .Y(_1132_));
 sky130_fd_sc_hd__nand2_1 _1482_ (.A(_1131_),
    .B(_1132_),
    .Y(_0259_));
 sky130_fd_sc_hd__nand2_1 _1483_ (.A(u_uart_master_core_u_uart_core_uart_rx_baud_div_q_0_),
    .B(net99),
    .Y(_1133_));
 sky130_fd_sc_hd__inv_1 _1484_ (.A(_1133_),
    .Y(_1134_));
 sky130_fd_sc_hd__nand2_1 _1485_ (.A(_1134_),
    .B(u_uart_master_core_u_uart_core_uart_rx_baud_div_q_1_),
    .Y(_1135_));
 sky130_fd_sc_hd__clkinv_1 _1486_ (.A(_1135_),
    .Y(_1136_));
 sky130_fd_sc_hd__a21oi_1 _1487_ (.A1(u_uart_master_core_u_uart_core_uart_rx_baud_div_q_2_),
    .A2(_1136_),
    .B1(_1114_),
    .Y(_1137_));
 sky130_fd_sc_hd__o21a_1 _1488_ (.A1(u_uart_master_core_u_uart_core_uart_rx_baud_div_q_2_),
    .A2(_1136_),
    .B1(_1137_),
    .X(_0260_));
 sky130_fd_sc_hd__nor2_1 _1489_ (.A(u_uart_master_core_u_uart_core_uart_rx_baud_div_q_1_),
    .B(_1134_),
    .Y(_1138_));
 sky130_fd_sc_hd__nor3_1 _1490_ (.A(_1136_),
    .B(_1138_),
    .C(_1114_),
    .Y(_0261_));
 sky130_fd_sc_hd__nor2_1 _1491_ (.A(u_uart_master_core_u_uart_core_uart_rx_baud_div_q_0_),
    .B(net99),
    .Y(_1139_));
 sky130_fd_sc_hd__nor3_1 _1492_ (.A(_1134_),
    .B(_1139_),
    .C(_1114_),
    .Y(_0262_));
 sky130_fd_sc_hd__nor2_1 _1493_ (.A(net135),
    .B(_0343_),
    .Y(_1140_));
 sky130_fd_sc_hd__clkinv_1 _1494_ (.A(reg2hw_3_),
    .Y(_1141_));
 sky130_fd_sc_hd__nor2_2 _1495_ (.A(_1141_),
    .B(_0514_),
    .Y(_1142_));
 sky130_fd_sc_hd__nor3_1 _1496_ (.A(_1140_),
    .B(_1142_),
    .C(_0036_),
    .Y(_0263_));
 sky130_fd_sc_hd__nor2_1 _1497_ (.A(net136),
    .B(_0341_),
    .Y(_1143_));
 sky130_fd_sc_hd__nor3_1 _1498_ (.A(_1142_),
    .B(_1143_),
    .C(_0343_),
    .Y(_0264_));
 sky130_fd_sc_hd__nor2_1 _1499_ (.A(net137),
    .B(_0345_),
    .Y(_1144_));
 sky130_fd_sc_hd__nor3_1 _1500_ (.A(_0341_),
    .B(_1142_),
    .C(_1144_),
    .Y(_0265_));
 sky130_fd_sc_hd__nor2_1 _1501_ (.A(net65),
    .B(_1088_),
    .Y(_1145_));
 sky130_fd_sc_hd__nand2_1 _1502_ (.A(_1145_),
    .B(net139),
    .Y(_1146_));
 sky130_fd_sc_hd__nor2_1 _1503_ (.A(_0325_),
    .B(_1146_),
    .Y(_1147_));
 sky130_fd_sc_hd__inv_1 _1504_ (.A(_1146_),
    .Y(_1148_));
 sky130_fd_sc_hd__nor2_1 _1505_ (.A(net138),
    .B(_1148_),
    .Y(_1149_));
 sky130_fd_sc_hd__nor3_1 _1506_ (.A(_1142_),
    .B(_1147_),
    .C(_1149_),
    .Y(_0266_));
 sky130_fd_sc_hd__nor2_1 _1507_ (.A(net139),
    .B(_1145_),
    .Y(_1150_));
 sky130_fd_sc_hd__nor3_1 _1508_ (.A(_1142_),
    .B(_1150_),
    .C(_1148_),
    .Y(_0267_));
 sky130_fd_sc_hd__nor2_1 _1509_ (.A(net140),
    .B(_1087_),
    .Y(_1151_));
 sky130_fd_sc_hd__nor3_1 _1510_ (.A(_1142_),
    .B(_1151_),
    .C(_1145_),
    .Y(_0268_));
 sky130_fd_sc_hd__nand2_1 _1511_ (.A(net117),
    .B(net129),
    .Y(_1152_));
 sky130_fd_sc_hd__o21ai_2 _1512_ (.A1(net117),
    .A2(_1118_),
    .B1(_1152_),
    .Y(u_uart_master_core_u_uart_core_rx_fifo_data_3_));
 sky130_fd_sc_hd__inv_1 _1513_ (.A(u_uart_master_core_u_uart_core_uart_tx_sreg_q_9_),
    .Y(_1153_));
 sky130_fd_sc_hd__nor2_1 _1514_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_15_),
    .B(net65),
    .Y(_1154_));
 sky130_fd_sc_hd__nor2_1 _1515_ (.A(net139),
    .B(_1154_),
    .Y(_1155_));
 sky130_fd_sc_hd__o21ai_0 _1516_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_7_),
    .B1(_1155_),
    .Y(_1156_));
 sky130_fd_sc_hd__nor2_1 _1517_ (.A(net140),
    .B(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_23_),
    .Y(_1157_));
 sky130_fd_sc_hd__nor2_1 _1518_ (.A(_0330_),
    .B(_1157_),
    .Y(_1158_));
 sky130_fd_sc_hd__o21ai_0 _1519_ (.A1(net65),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_31_),
    .B1(_1158_),
    .Y(_1159_));
 sky130_fd_sc_hd__nor2_1 _1520_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_47_),
    .B(net65),
    .Y(_1160_));
 sky130_fd_sc_hd__nor2_1 _1521_ (.A(net139),
    .B(_1160_),
    .Y(_1161_));
 sky130_fd_sc_hd__o21ai_0 _1522_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_39_),
    .B1(_1161_),
    .Y(_1162_));
 sky130_fd_sc_hd__o21ai_0 _1523_ (.A1(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_55_),
    .A2(net140),
    .B1(net139),
    .Y(_1163_));
 sky130_fd_sc_hd__nor2_1 _1524_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_63_),
    .B(net65),
    .Y(_1164_));
 sky130_fd_sc_hd__nor2_1 _1525_ (.A(_1163_),
    .B(_1164_),
    .Y(_1165_));
 sky130_fd_sc_hd__nor2_1 _1526_ (.A(_0325_),
    .B(_1165_),
    .Y(_1166_));
 sky130_fd_sc_hd__a32oi_1 _1527_ (.A1(_1156_),
    .A2(_0325_),
    .A3(_1159_),
    .B1(_1162_),
    .B2(_1166_),
    .Y(_1167_));
 sky130_fd_sc_hd__inv_1 _1528_ (.A(_1167_),
    .Y(_1168_));
 sky130_fd_sc_hd__a21oi_1 _1529_ (.A1(_1076_),
    .A2(u_uart_master_core_u_uart_core_uart_tx_sreg_q_8_),
    .B1(net81),
    .Y(_1169_));
 sky130_fd_sc_hd__o221ai_1 _1530_ (.A1(_1153_),
    .A2(_1070_),
    .B1(net56),
    .B2(_1168_),
    .C1(_1169_),
    .Y(_0269_));
 sky130_fd_sc_hd__nor2_1 _1531_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_14_),
    .B(net65),
    .Y(_1170_));
 sky130_fd_sc_hd__nor2_1 _1532_ (.A(net139),
    .B(_1170_),
    .Y(_1171_));
 sky130_fd_sc_hd__o21ai_0 _1533_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_6_),
    .B1(_1171_),
    .Y(_1172_));
 sky130_fd_sc_hd__nor2_1 _1534_ (.A(net140),
    .B(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_22_),
    .Y(_1173_));
 sky130_fd_sc_hd__nor2_1 _1535_ (.A(_0330_),
    .B(_1173_),
    .Y(_1174_));
 sky130_fd_sc_hd__o21ai_0 _1536_ (.A1(net65),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_30_),
    .B1(_1174_),
    .Y(_1175_));
 sky130_fd_sc_hd__nor2_1 _1537_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_46_),
    .B(net65),
    .Y(_1176_));
 sky130_fd_sc_hd__nor2_1 _1538_ (.A(net139),
    .B(_1176_),
    .Y(_1177_));
 sky130_fd_sc_hd__o21ai_0 _1539_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_38_),
    .B1(_1177_),
    .Y(_1178_));
 sky130_fd_sc_hd__o21ai_0 _1540_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_54_),
    .B1(net139),
    .Y(_1179_));
 sky130_fd_sc_hd__nor2_1 _1541_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_62_),
    .B(net65),
    .Y(_1180_));
 sky130_fd_sc_hd__nor2_1 _1542_ (.A(_1179_),
    .B(_1180_),
    .Y(_1181_));
 sky130_fd_sc_hd__nor2_1 _1543_ (.A(_0325_),
    .B(_1181_),
    .Y(_1182_));
 sky130_fd_sc_hd__a32oi_1 _1544_ (.A1(_1172_),
    .A2(_0325_),
    .A3(_1175_),
    .B1(_1178_),
    .B2(_1182_),
    .Y(_1183_));
 sky130_fd_sc_hd__inv_1 _1545_ (.A(_1183_),
    .Y(_1184_));
 sky130_fd_sc_hd__nand2_1 _1546_ (.A(net56),
    .B(u_uart_master_core_u_uart_core_uart_tx_sreg_q_7_),
    .Y(_1185_));
 sky130_fd_sc_hd__a21oi_1 _1547_ (.A1(_1071_),
    .A2(u_uart_master_core_u_uart_core_uart_tx_sreg_q_8_),
    .B1(net81),
    .Y(_1186_));
 sky130_fd_sc_hd__o221ai_1 _1548_ (.A1(net56),
    .A2(_1184_),
    .B1(_1073_),
    .B2(_1185_),
    .C1(_1186_),
    .Y(_0270_));
 sky130_fd_sc_hd__nor2_1 _1549_ (.A(net140),
    .B(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_5_),
    .Y(_1187_));
 sky130_fd_sc_hd__nor2_1 _1550_ (.A(net139),
    .B(_1187_),
    .Y(_1188_));
 sky130_fd_sc_hd__o21ai_0 _1551_ (.A1(net65),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_13_),
    .B1(_1188_),
    .Y(_1189_));
 sky130_fd_sc_hd__nor2_1 _1552_ (.A(net140),
    .B(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_21_),
    .Y(_1190_));
 sky130_fd_sc_hd__nor2_1 _1553_ (.A(_0330_),
    .B(_1190_),
    .Y(_1191_));
 sky130_fd_sc_hd__o21ai_0 _1554_ (.A1(net65),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_29_),
    .B1(_1191_),
    .Y(_1192_));
 sky130_fd_sc_hd__o21ai_0 _1555_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_53_),
    .B1(net139),
    .Y(_1193_));
 sky130_fd_sc_hd__nor2_1 _1556_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_61_),
    .B(net65),
    .Y(_1194_));
 sky130_fd_sc_hd__nor2_1 _1557_ (.A(_1193_),
    .B(_1194_),
    .Y(_1195_));
 sky130_fd_sc_hd__nor2_1 _1558_ (.A(_0325_),
    .B(_1195_),
    .Y(_1196_));
 sky130_fd_sc_hd__nor2_1 _1559_ (.A(net140),
    .B(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_37_),
    .Y(_1197_));
 sky130_fd_sc_hd__nor2_1 _1560_ (.A(net139),
    .B(_1197_),
    .Y(_1198_));
 sky130_fd_sc_hd__o21ai_0 _1561_ (.A1(net65),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_45_),
    .B1(_1198_),
    .Y(_1199_));
 sky130_fd_sc_hd__a32oi_1 _1562_ (.A1(_0325_),
    .A2(_1189_),
    .A3(_1192_),
    .B1(_1196_),
    .B2(_1199_),
    .Y(_1200_));
 sky130_fd_sc_hd__nand2_1 _1563_ (.A(_1075_),
    .B(_1200_),
    .Y(_1201_));
 sky130_fd_sc_hd__nor2_1 _1564_ (.A(u_uart_master_core_u_uart_core_uart_tx_sreg_q_6_),
    .B(_1077_),
    .Y(_1202_));
 sky130_fd_sc_hd__a31oi_1 _1565_ (.A1(_1078_),
    .A2(_1185_),
    .A3(_1201_),
    .B1(_1202_),
    .Y(_0271_));
 sky130_fd_sc_hd__nor2_1 _1566_ (.A(net140),
    .B(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_4_),
    .Y(_1203_));
 sky130_fd_sc_hd__o21ai_0 _1567_ (.A1(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_12_),
    .A2(_0334_),
    .B1(_0330_),
    .Y(_1204_));
 sky130_fd_sc_hd__nor2_1 _1568_ (.A(net140),
    .B(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_20_),
    .Y(_1205_));
 sky130_fd_sc_hd__o21ai_0 _1569_ (.A1(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_28_),
    .A2(net65),
    .B1(net139),
    .Y(_1206_));
 sky130_fd_sc_hd__o221ai_1 _1570_ (.A1(_1203_),
    .A2(_1204_),
    .B1(_1205_),
    .B2(_1206_),
    .C1(_0325_),
    .Y(_1207_));
 sky130_fd_sc_hd__nor2_1 _1571_ (.A(net140),
    .B(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_36_),
    .Y(_1208_));
 sky130_fd_sc_hd__o21ai_0 _1572_ (.A1(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_44_),
    .A2(_0334_),
    .B1(_0330_),
    .Y(_1209_));
 sky130_fd_sc_hd__nor2_1 _1573_ (.A(net140),
    .B(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_52_),
    .Y(_1210_));
 sky130_fd_sc_hd__o21ai_0 _1574_ (.A1(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_60_),
    .A2(net65),
    .B1(net139),
    .Y(_1211_));
 sky130_fd_sc_hd__o221ai_1 _1575_ (.A1(_1208_),
    .A2(_1209_),
    .B1(_1210_),
    .B2(_1211_),
    .C1(net138),
    .Y(_1212_));
 sky130_fd_sc_hd__nand3_1 _1576_ (.A(_1037_),
    .B(_1207_),
    .C(_1212_),
    .Y(_1213_));
 sky130_fd_sc_hd__nand2_1 _1577_ (.A(net56),
    .B(u_uart_master_core_u_uart_core_uart_tx_sreg_q_5_),
    .Y(_1214_));
 sky130_fd_sc_hd__a21oi_1 _1578_ (.A1(_1071_),
    .A2(u_uart_master_core_u_uart_core_uart_tx_sreg_q_6_),
    .B1(net81),
    .Y(_1215_));
 sky130_fd_sc_hd__o221ai_1 _1579_ (.A1(net56),
    .A2(_1213_),
    .B1(_1071_),
    .B2(_1214_),
    .C1(_1215_),
    .Y(_0272_));
 sky130_fd_sc_hd__o21ai_0 _1580_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_51_),
    .B1(net139),
    .Y(_1216_));
 sky130_fd_sc_hd__nor2_1 _1581_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_59_),
    .B(net65),
    .Y(_1217_));
 sky130_fd_sc_hd__o21ai_0 _1582_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_35_),
    .B1(_0330_),
    .Y(_1218_));
 sky130_fd_sc_hd__nor2_1 _1583_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_43_),
    .B(net65),
    .Y(_1219_));
 sky130_fd_sc_hd__o221ai_1 _1584_ (.A1(_1216_),
    .A2(_1217_),
    .B1(_1218_),
    .B2(_1219_),
    .C1(net138),
    .Y(_1220_));
 sky130_fd_sc_hd__o21ai_0 _1585_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_19_),
    .B1(net139),
    .Y(_1221_));
 sky130_fd_sc_hd__nor2_1 _1586_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_27_),
    .B(net65),
    .Y(_1222_));
 sky130_fd_sc_hd__o21ai_0 _1587_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_3_),
    .B1(_0330_),
    .Y(_1223_));
 sky130_fd_sc_hd__nor2_1 _1588_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_11_),
    .B(net65),
    .Y(_1224_));
 sky130_fd_sc_hd__o221ai_1 _1589_ (.A1(_1221_),
    .A2(_1222_),
    .B1(_1223_),
    .B2(_1224_),
    .C1(_0325_),
    .Y(_1225_));
 sky130_fd_sc_hd__nand3_1 _1590_ (.A(_1075_),
    .B(_1220_),
    .C(_1225_),
    .Y(_1226_));
 sky130_fd_sc_hd__nor2_1 _1591_ (.A(u_uart_master_core_u_uart_core_uart_tx_sreg_q_4_),
    .B(_1077_),
    .Y(_1227_));
 sky130_fd_sc_hd__a31oi_1 _1592_ (.A1(_1078_),
    .A2(_1214_),
    .A3(_1226_),
    .B1(_1227_),
    .Y(_0273_));
 sky130_fd_sc_hd__o21ai_0 _1593_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_50_),
    .B1(net139),
    .Y(_1228_));
 sky130_fd_sc_hd__nor2_1 _1594_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_58_),
    .B(net65),
    .Y(_1229_));
 sky130_fd_sc_hd__o21ai_0 _1595_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_34_),
    .B1(_0330_),
    .Y(_1230_));
 sky130_fd_sc_hd__nor2_1 _1596_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_42_),
    .B(net65),
    .Y(_1231_));
 sky130_fd_sc_hd__o221ai_1 _1597_ (.A1(_1228_),
    .A2(_1229_),
    .B1(_1230_),
    .B2(_1231_),
    .C1(net138),
    .Y(_1232_));
 sky130_fd_sc_hd__o21ai_0 _1598_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_18_),
    .B1(net139),
    .Y(_1233_));
 sky130_fd_sc_hd__nor2_1 _1599_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_26_),
    .B(net65),
    .Y(_1234_));
 sky130_fd_sc_hd__o21ai_0 _1600_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_2_),
    .B1(_0330_),
    .Y(_1235_));
 sky130_fd_sc_hd__nor2_1 _1601_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_10_),
    .B(net65),
    .Y(_1236_));
 sky130_fd_sc_hd__o221ai_1 _1602_ (.A1(_1233_),
    .A2(_1234_),
    .B1(_1235_),
    .B2(_1236_),
    .C1(_0325_),
    .Y(_1237_));
 sky130_fd_sc_hd__nand2_1 _1603_ (.A(_1232_),
    .B(_1237_),
    .Y(_1238_));
 sky130_fd_sc_hd__nand2_1 _1604_ (.A(net56),
    .B(u_uart_master_core_u_uart_core_uart_tx_sreg_q_3_),
    .Y(_1239_));
 sky130_fd_sc_hd__a21oi_1 _1605_ (.A1(_1071_),
    .A2(u_uart_master_core_u_uart_core_uart_tx_sreg_q_4_),
    .B1(net81),
    .Y(_1240_));
 sky130_fd_sc_hd__o221ai_1 _1606_ (.A1(net56),
    .A2(_1238_),
    .B1(_1073_),
    .B2(_1239_),
    .C1(_1240_),
    .Y(_0274_));
 sky130_fd_sc_hd__nor2_1 _1607_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_9_),
    .B(net65),
    .Y(_1241_));
 sky130_fd_sc_hd__nor2_1 _1608_ (.A(net139),
    .B(_1241_),
    .Y(_1242_));
 sky130_fd_sc_hd__o21ai_0 _1609_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_1_),
    .B1(_1242_),
    .Y(_1243_));
 sky130_fd_sc_hd__inv_1 _1610_ (.A(_1243_),
    .Y(_1244_));
 sky130_fd_sc_hd__nor2_1 _1611_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_25_),
    .B(net65),
    .Y(_1245_));
 sky130_fd_sc_hd__nor2_1 _1612_ (.A(_0330_),
    .B(_1245_),
    .Y(_1246_));
 sky130_fd_sc_hd__o21ai_0 _1613_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_17_),
    .B1(_1246_),
    .Y(_1247_));
 sky130_fd_sc_hd__inv_1 _1614_ (.A(_1247_),
    .Y(_1248_));
 sky130_fd_sc_hd__o21ai_0 _1615_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_49_),
    .B1(net139),
    .Y(_1249_));
 sky130_fd_sc_hd__nor2_1 _1616_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_57_),
    .B(net65),
    .Y(_1250_));
 sky130_fd_sc_hd__o21ai_0 _1617_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_33_),
    .B1(_0330_),
    .Y(_1251_));
 sky130_fd_sc_hd__nor2_1 _1618_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_41_),
    .B(net65),
    .Y(_1252_));
 sky130_fd_sc_hd__o221ai_1 _1619_ (.A1(_1249_),
    .A2(_1250_),
    .B1(_1251_),
    .B2(_1252_),
    .C1(net138),
    .Y(_1253_));
 sky130_fd_sc_hd__o31ai_1 _1620_ (.A1(net138),
    .A2(_1244_),
    .A3(_1248_),
    .B1(_1253_),
    .Y(_1254_));
 sky130_fd_sc_hd__o21a_1 _1621_ (.A1(net56),
    .A2(_1254_),
    .B1(_1239_),
    .X(_1255_));
 sky130_fd_sc_hd__nor2_1 _1622_ (.A(u_uart_master_core_u_uart_core_uart_tx_sreg_q_2_),
    .B(_1077_),
    .Y(_1256_));
 sky130_fd_sc_hd__a21oi_1 _1623_ (.A1(_1078_),
    .A2(_1255_),
    .B1(_1256_),
    .Y(_0275_));
 sky130_fd_sc_hd__o21ai_0 _1624_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_48_),
    .B1(net139),
    .Y(_1257_));
 sky130_fd_sc_hd__nor2_1 _1625_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_56_),
    .B(net65),
    .Y(_1258_));
 sky130_fd_sc_hd__o21ai_0 _1626_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_32_),
    .B1(_0330_),
    .Y(_1259_));
 sky130_fd_sc_hd__nor2_1 _1627_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_40_),
    .B(net65),
    .Y(_1260_));
 sky130_fd_sc_hd__o221ai_1 _1628_ (.A1(_1257_),
    .A2(_1258_),
    .B1(_1259_),
    .B2(_1260_),
    .C1(net138),
    .Y(_1261_));
 sky130_fd_sc_hd__nor2_1 _1629_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_8_),
    .B(net65),
    .Y(_1262_));
 sky130_fd_sc_hd__nor2_1 _1630_ (.A(net139),
    .B(_1262_),
    .Y(_1263_));
 sky130_fd_sc_hd__o21ai_0 _1631_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_0_),
    .B1(_1263_),
    .Y(_1264_));
 sky130_fd_sc_hd__nor2_1 _1632_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_24_),
    .B(net65),
    .Y(_1265_));
 sky130_fd_sc_hd__nor2_1 _1633_ (.A(_0330_),
    .B(_1265_),
    .Y(_1266_));
 sky130_fd_sc_hd__o21ai_0 _1634_ (.A1(net140),
    .A2(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_16_),
    .B1(_1266_),
    .Y(_1267_));
 sky130_fd_sc_hd__nand3_1 _1635_ (.A(_1264_),
    .B(_1267_),
    .C(_0325_),
    .Y(_1268_));
 sky130_fd_sc_hd__nand2_1 _1636_ (.A(_1261_),
    .B(_1268_),
    .Y(_1269_));
 sky130_fd_sc_hd__nand2_1 _1637_ (.A(net56),
    .B(u_uart_master_core_u_uart_core_uart_tx_sreg_q_1_),
    .Y(_1270_));
 sky130_fd_sc_hd__a21oi_1 _1638_ (.A1(_1071_),
    .A2(u_uart_master_core_u_uart_core_uart_tx_sreg_q_2_),
    .B1(net81),
    .Y(_1271_));
 sky130_fd_sc_hd__o221ai_1 _1639_ (.A1(net56),
    .A2(_1269_),
    .B1(_1073_),
    .B2(_1270_),
    .C1(_1271_),
    .Y(_0276_));
 sky130_fd_sc_hd__inv_1 _1640_ (.A(u_uart_master_core_u_uart_core_uart_tx_sreg_q_0_),
    .Y(_1272_));
 sky130_fd_sc_hd__a22oi_1 _1641_ (.A1(_1272_),
    .A2(_1076_),
    .B1(_1078_),
    .B2(_1270_),
    .Y(_0277_));
 sky130_fd_sc_hd__o21ai_0 _1642_ (.A1(_1269_),
    .A2(_1254_),
    .B1(_1037_),
    .Y(_1273_));
 sky130_fd_sc_hd__a21oi_1 _1643_ (.A1(_1254_),
    .A2(_1269_),
    .B1(_1273_),
    .Y(_1274_));
 sky130_fd_sc_hd__xor2_1 _1644_ (.A(net116),
    .B(_1274_),
    .X(_1275_));
 sky130_fd_sc_hd__a21oi_1 _1645_ (.A1(_1168_),
    .A2(_1184_),
    .B1(_1036_),
    .Y(_1276_));
 sky130_fd_sc_hd__o21ai_0 _1646_ (.A1(_1168_),
    .A2(_1184_),
    .B1(_1276_),
    .Y(_1277_));
 sky130_fd_sc_hd__nand2_1 _1647_ (.A(_1220_),
    .B(_1225_),
    .Y(_1278_));
 sky130_fd_sc_hd__a21oi_1 _1648_ (.A1(_1278_),
    .A2(_1238_),
    .B1(_1036_),
    .Y(_1279_));
 sky130_fd_sc_hd__o21ai_0 _1649_ (.A1(_1278_),
    .A2(_1238_),
    .B1(_1279_),
    .Y(_1280_));
 sky130_fd_sc_hd__nand3_1 _1650_ (.A(_1213_),
    .B(_1037_),
    .C(_1200_),
    .Y(_1281_));
 sky130_fd_sc_hd__o21ai_0 _1651_ (.A1(_1200_),
    .A2(_1213_),
    .B1(_1281_),
    .Y(_1282_));
 sky130_fd_sc_hd__xnor2_1 _1652_ (.A(_1280_),
    .B(_1282_),
    .Y(_1283_));
 sky130_fd_sc_hd__xor2_1 _1653_ (.A(_1277_),
    .B(_1283_),
    .X(_1284_));
 sky130_fd_sc_hd__xor2_1 _1654_ (.A(_1275_),
    .B(_1284_),
    .X(_1285_));
 sky130_fd_sc_hd__a22oi_1 _1655_ (.A1(_1153_),
    .A2(_1076_),
    .B1(_1285_),
    .B2(_1089_),
    .Y(_0278_));
 sky130_fd_sc_hd__nor3_2 _1656_ (.A(_0905_),
    .B(_0909_),
    .C(_0923_),
    .Y(u_uart_master_reg_u_reg_core_fifo_ctrl_flds_we_0_));
 sky130_fd_sc_hd__nand2_1 _1657_ (.A(u_uart_master_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .B(tl_i[24]),
    .Y(_1286_));
 sky130_fd_sc_hd__o21ai_0 _1658_ (.A1(_0513_),
    .A2(u_uart_master_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .B1(_1286_),
    .Y(_0279_));
 sky130_fd_sc_hd__nand2_1 _1659_ (.A(u_uart_master_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .B(tl_i[25]),
    .Y(_1287_));
 sky130_fd_sc_hd__o21ai_0 _1660_ (.A1(_1141_),
    .A2(u_uart_master_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .B1(_1287_),
    .Y(_0280_));
 sky130_fd_sc_hd__inv_1 _1661_ (.A(reg2hw_12_),
    .Y(_1288_));
 sky130_fd_sc_hd__nand2_1 _1662_ (.A(net53),
    .B(tl_i[31]),
    .Y(_1289_));
 sky130_fd_sc_hd__o21ai_0 _1663_ (.A1(_1288_),
    .A2(net53),
    .B1(_1289_),
    .Y(_0281_));
 sky130_fd_sc_hd__nand2_1 _1664_ (.A(_1108_),
    .B(u_uart_master_core_u_uart_core_rx_tick_baud),
    .Y(_1290_));
 sky130_fd_sc_hd__nand2_1 _1665_ (.A(_1127_),
    .B(_1099_),
    .Y(_1291_));
 sky130_fd_sc_hd__nor3_1 _1666_ (.A(net132),
    .B(_1095_),
    .C(_1291_),
    .Y(_0000_));
 sky130_fd_sc_hd__nor2_1 _1667_ (.A(hw2reg_28_),
    .B(_0000_),
    .Y(_1292_));
 sky130_fd_sc_hd__a21oi_1 _1668_ (.A1(_1290_),
    .A2(_1292_),
    .B1(_1114_),
    .Y(_0282_));
 sky130_fd_sc_hd__xnor2_1 _1669_ (.A(net132),
    .B(_1124_),
    .Y(_1293_));
 sky130_fd_sc_hd__o21ai_0 _1670_ (.A1(net132),
    .A2(_1114_),
    .B1(_1097_),
    .Y(_1294_));
 sky130_fd_sc_hd__o21ai_0 _1671_ (.A1(_1293_),
    .A2(_1110_),
    .B1(_1294_),
    .Y(_0283_));
 sky130_fd_sc_hd__inv_1 _1672_ (.A(u_uart_master_core_u_host_bridge_tx_st_q_0_),
    .Y(_1295_));
 sky130_fd_sc_hd__o21ai_0 _1673_ (.A1(_0436_),
    .A2(_0496_),
    .B1(_0445_),
    .Y(_1296_));
 sky130_fd_sc_hd__o21ai_0 _1674_ (.A1(_1296_),
    .A2(_0461_),
    .B1(u_uart_master_core_u_host_bridge_tx_st_q_1_),
    .Y(_1297_));
 sky130_fd_sc_hd__o21ai_0 _1675_ (.A1(_1295_),
    .A2(_0509_),
    .B1(_1297_),
    .Y(u_uart_master_core_u_host_bridge_tx_st_d_0_));
 sky130_fd_sc_hd__inv_1 _1676_ (.A(u_uart_master_core_u_uart_core_uart_tx_bit_cnt_q_3_),
    .Y(_1298_));
 sky130_fd_sc_hd__a21oi_1 _1677_ (.A1(net115),
    .A2(_1043_),
    .B1(_1076_),
    .Y(_1299_));
 sky130_fd_sc_hd__o21ai_0 _1678_ (.A1(_1298_),
    .A2(_1299_),
    .B1(_1088_),
    .Y(_0284_));
 sky130_fd_sc_hd__o22ai_1 _1679_ (.A1(_1295_),
    .A2(_0508_),
    .B1(_1296_),
    .B2(_0499_),
    .Y(_0018_));
 sky130_fd_sc_hd__inv_1 _1680_ (.A(u_uart_master_core_u_uart_core_uart_rx_baud_div_q_3_),
    .Y(_1300_));
 sky130_fd_sc_hd__nand3_1 _1681_ (.A(_1136_),
    .B(u_uart_master_core_u_uart_core_uart_rx_baud_div_q_2_),
    .C(u_uart_master_core_u_uart_core_uart_rx_baud_div_q_3_),
    .Y(_1301_));
 sky130_fd_sc_hd__nor2_1 _1682_ (.A(_1301_),
    .B(_1114_),
    .Y(u_uart_master_core_u_uart_core_uart_rx_tick_baud_d));
 sky130_fd_sc_hd__a21oi_1 _1683_ (.A1(_1137_),
    .A2(_1300_),
    .B1(u_uart_master_core_u_uart_core_uart_rx_tick_baud_d),
    .Y(_0285_));
 sky130_fd_sc_hd__o21ai_0 _1684_ (.A1(u_uart_master_reg_tl_o_0_),
    .A2(tl_i[0]),
    .B1(net68),
    .Y(_0286_));
 sky130_fd_sc_hd__a22oi_1 _1685_ (.A1(_0439_),
    .A2(u_uart_master_core_u_host_bridge_rdata_q_31_),
    .B1(_0447_),
    .B2(u_uart_master_core_u_host_bridge_rdata_q_7_),
    .Y(_1302_));
 sky130_fd_sc_hd__o21ai_0 _1686_ (.A1(_0807_),
    .A2(_0442_),
    .B1(_1302_),
    .Y(_1303_));
 sky130_fd_sc_hd__a221oi_1 _1687_ (.A1(u_uart_master_core_u_host_bridge_op_q_7_),
    .A2(_0455_),
    .B1(u_uart_master_core_u_host_bridge_rdata_q_15_),
    .B2(_0451_),
    .C1(_1303_),
    .Y(_1304_));
 sky130_fd_sc_hd__o21ai_2 _1688_ (.A1(_1304_),
    .A2(_0464_),
    .B1(_1288_),
    .Y(u_uart_master_core_u_uart_core_tx_fifo_wdata_7_));
 sky130_fd_sc_hd__o22ai_1 _1689_ (.A1(_1141_),
    .A2(_0514_),
    .B1(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .B2(_1147_),
    .Y(_1305_));
 sky130_fd_sc_hd__a21oi_1 _1690_ (.A1(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .A2(_1147_),
    .B1(_1305_),
    .Y(_0287_));
 sky130_fd_sc_hd__o22ai_1 _1691_ (.A1(_1107_),
    .A2(_1110_),
    .B1(_1094_),
    .B2(_1116_),
    .Y(_0288_));
 sky130_fd_sc_hd__o22ai_1 _1692_ (.A1(_1141_),
    .A2(_0514_),
    .B1(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .B2(_0036_),
    .Y(_1306_));
 sky130_fd_sc_hd__a21oi_1 _1693_ (.A1(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .A2(_0036_),
    .B1(_1306_),
    .Y(_0289_));
 sky130_fd_sc_hd__a21o_1 _1694_ (.A1(u_uart_master_reg_tl_o_62_),
    .A2(net68),
    .B1(_0528_),
    .X(_0290_));
 sky130_fd_sc_hd__nand2_1 _1695_ (.A(net66),
    .B(reg2hw_56_),
    .Y(_1307_));
 sky130_fd_sc_hd__nor2_1 _1696_ (.A(u_uart_master_reg_tl_o_47_),
    .B(_0945_),
    .Y(_1308_));
 sky130_fd_sc_hd__a21oi_1 _1697_ (.A1(net57),
    .A2(_1307_),
    .B1(_1308_),
    .Y(_0291_));
 sky130_fd_sc_hd__nand2_1 _1698_ (.A(net38),
    .B(u_uart_master_core_addr_o_31_),
    .Y(_1309_));
 sky130_fd_sc_hd__o21ai_0 _1699_ (.A1(_0770_),
    .A2(net39),
    .B1(_1309_),
    .Y(_0292_));
 sky130_fd_sc_hd__nor2_4 _1700_ (.A(net72),
    .B(net34),
    .Y(_0023_));
 sky130_fd_sc_hd__nand2_1 _1701_ (.A(net52),
    .B(net115),
    .Y(_1310_));
 sky130_fd_sc_hd__o21ai_0 _1702_ (.A1(_0934_),
    .A2(net52),
    .B1(_1310_),
    .Y(_0293_));
 sky130_fd_sc_hd__a21oi_1 _1703_ (.A1(_1070_),
    .A2(u_uart_master_core_u_uart_core_tx_out),
    .B1(net81),
    .Y(_1311_));
 sky130_fd_sc_hd__o21ai_0 _1704_ (.A1(_1272_),
    .A2(_1070_),
    .B1(_1311_),
    .Y(_0294_));
 sky130_fd_sc_hd__xor2_1 _1705_ (.A(_0401_),
    .B(_0391_),
    .X(_0014_));
 sky130_fd_sc_hd__nand2_1 _1706_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_any_err_q),
    .Y(_1312_));
 sky130_fd_sc_hd__nand2_1 _1707_ (.A(net58),
    .B(err_i),
    .Y(_1313_));
 sky130_fd_sc_hd__nand2_1 _1708_ (.A(_1312_),
    .B(_1313_),
    .Y(_0295_));
 sky130_fd_sc_hd__o22a_1 _1709_ (.A1(u_uart_master_core_be_o_3_),
    .A2(_0590_),
    .B1(u_uart_master_core_u_host_bridge_bebyte_q_3_),
    .B2(net33),
    .X(_0296_));
 sky130_fd_sc_hd__or2_0 _1710_ (.A(reg2hw_37_),
    .B(u_uart_master_core_u_uart_core_tx_out),
    .X(_1389_));
 sky130_fd_sc_hd__nand2_1 _1711_ (.A(net48),
    .B(u_uart_master_core_u_host_bridge_bebyte_q_3_),
    .Y(_1314_));
 sky130_fd_sc_hd__o21ai_0 _1712_ (.A1(net48),
    .A2(_0646_),
    .B1(_1314_),
    .Y(_0297_));
 sky130_fd_sc_hd__o21ai_0 _1713_ (.A1(_0866_),
    .A2(_0852_),
    .B1(_0864_),
    .Y(_1315_));
 sky130_fd_sc_hd__o21ai_0 _1714_ (.A1(_0578_),
    .A2(_0863_),
    .B1(_1315_),
    .Y(_0298_));
 sky130_fd_sc_hd__nand2_1 _1715_ (.A(net49),
    .B(u_uart_master_core_u_host_bridge_op_q_7_),
    .Y(_1316_));
 sky130_fd_sc_hd__o21ai_0 _1716_ (.A1(_0770_),
    .A2(net49),
    .B1(_1316_),
    .Y(_0299_));
 sky130_fd_sc_hd__nand2_1 _1717_ (.A(net52),
    .B(reg2hw_37_),
    .Y(_1317_));
 sky130_fd_sc_hd__o21ai_0 _1718_ (.A1(_0928_),
    .A2(net52),
    .B1(_1317_),
    .Y(_0300_));
 sky130_fd_sc_hd__nand2_1 _1719_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_31_),
    .Y(_1318_));
 sky130_fd_sc_hd__nand2_1 _1720_ (.A(net58),
    .B(rdata_i[31]),
    .Y(_1319_));
 sky130_fd_sc_hd__nand2_1 _1721_ (.A(_1318_),
    .B(_1319_),
    .Y(_0301_));
 sky130_fd_sc_hd__o21a_1 _1722_ (.A1(_0531_),
    .A2(_0749_),
    .B1(net112),
    .X(_1320_));
 sky130_fd_sc_hd__nand2_1 _1723_ (.A(_1320_),
    .B(_0780_),
    .Y(_1321_));
 sky130_fd_sc_hd__nand2_1 _1724_ (.A(_1321_),
    .B(req_o),
    .Y(_1322_));
 sky130_fd_sc_hd__o21ai_0 _1725_ (.A1(_0501_),
    .A2(_0532_),
    .B1(_1322_),
    .Y(_0302_));
 sky130_fd_sc_hd__nand2_1 _1726_ (.A(net52),
    .B(reg2hw_35_),
    .Y(_1323_));
 sky130_fd_sc_hd__o21ai_0 _1727_ (.A1(_0932_),
    .A2(net52),
    .B1(_1323_),
    .Y(_0303_));
 sky130_fd_sc_hd__o21ai_0 _1728_ (.A1(_0588_),
    .A2(_1320_),
    .B1(_0787_),
    .Y(_1324_));
 sky130_fd_sc_hd__nand2_1 _1729_ (.A(_1324_),
    .B(_0781_),
    .Y(_0304_));
 sky130_fd_sc_hd__o22ai_1 _1730_ (.A1(net36),
    .A2(_0770_),
    .B1(_0698_),
    .B2(net32),
    .Y(_0305_));
 sky130_fd_sc_hd__nand2_1 _1731_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_31_),
    .Y(_1325_));
 sky130_fd_sc_hd__o21ai_0 _1732_ (.A1(_0582_),
    .A2(_0770_),
    .B1(_1325_),
    .Y(_0306_));
 sky130_fd_sc_hd__nor2_1 _1733_ (.A(_1361_),
    .B(_0543_),
    .Y(_1326_));
 sky130_fd_sc_hd__o21ai_0 _1734_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .A2(_1326_),
    .B1(_0544_),
    .Y(_1327_));
 sky130_fd_sc_hd__a21oi_1 _1735_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .A2(_1326_),
    .B1(_1327_),
    .Y(_0307_));
 sky130_fd_sc_hd__nand2_1 _1736_ (.A(net117),
    .B(net130),
    .Y(_1328_));
 sky130_fd_sc_hd__o21ai_2 _1737_ (.A1(net117),
    .A2(_1119_),
    .B1(_1328_),
    .Y(u_uart_master_core_u_uart_core_rx_fifo_data_2_));
 sky130_fd_sc_hd__mux2_4 _1738_ (.A0(u_uart_master_core_u_uart_core_tx_out_q),
    .A1(cio_rx_i),
    .S(net124),
    .X(cio_tx_o));
 sky130_fd_sc_hd__nand2_1 _1739_ (.A(net117),
    .B(net125),
    .Y(_1329_));
 sky130_fd_sc_hd__o21ai_2 _1740_ (.A1(net117),
    .A2(_1111_),
    .B1(_1329_),
    .Y(u_uart_master_core_u_uart_core_rx_fifo_data_7_));
 sky130_fd_sc_hd__o21ai_0 _1741_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .A2(_0025_),
    .B1(_0544_),
    .Y(_1330_));
 sky130_fd_sc_hd__a21oi_1 _1742_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .A2(_0025_),
    .B1(_1330_),
    .Y(_0308_));
 sky130_fd_sc_hd__nand2_1 _1743_ (.A(_0746_),
    .B(_0753_),
    .Y(_1331_));
 sky130_fd_sc_hd__nand2_1 _1744_ (.A(_1331_),
    .B(we_o),
    .Y(_1332_));
 sky130_fd_sc_hd__nand2_1 _1745_ (.A(_1332_),
    .B(net33),
    .Y(_0309_));
 sky130_fd_sc_hd__mux2_1 _1746_ (.A0(tl_i[55]),
    .A1(reg2hw_56_),
    .S(net55),
    .X(_0310_));
 sky130_fd_sc_hd__mux2_1 _1747_ (.A0(tl_i[31]),
    .A1(net116),
    .S(net55),
    .X(_0311_));
 sky130_fd_sc_hd__nand2_1 _1748_ (.A(net52),
    .B(net117),
    .Y(_1333_));
 sky130_fd_sc_hd__o21ai_0 _1749_ (.A1(_0924_),
    .A2(net52),
    .B1(_1333_),
    .Y(_0312_));
 sky130_fd_sc_hd__nand2_1 _1750_ (.A(net52),
    .B(reg2hw_36_),
    .Y(_1334_));
 sky130_fd_sc_hd__o21ai_0 _1751_ (.A1(_0930_),
    .A2(net52),
    .B1(_1334_),
    .Y(_0313_));
 sky130_fd_sc_hd__o21bai_1 _1752_ (.A1(_0528_),
    .A2(_0920_),
    .B1_N(_0922_),
    .Y(_1335_));
 sky130_fd_sc_hd__a21oi_1 _1753_ (.A1(_0918_),
    .A2(_0917_),
    .B1(net68),
    .Y(_1336_));
 sky130_fd_sc_hd__nor2_1 _1754_ (.A(u_uart_master_reg_tl_o_1_),
    .B(_0945_),
    .Y(_1337_));
 sky130_fd_sc_hd__a31oi_1 _1755_ (.A1(_0921_),
    .A2(_1335_),
    .A3(_1336_),
    .B1(_1337_),
    .Y(_0314_));
 sky130_fd_sc_hd__nand2_1 _1756_ (.A(net52),
    .B(net124),
    .Y(_1338_));
 sky130_fd_sc_hd__o21ai_0 _1757_ (.A1(_0926_),
    .A2(net52),
    .B1(_1338_),
    .Y(_0315_));
 sky130_fd_sc_hd__and3_1 _1758_ (.A(_1093_),
    .B(u_uart_master_core_u_uart_core_uart_tx_baud_div_q_3_),
    .C(u_uart_master_core_u_uart_core_uart_tx_baud_div_q_2_),
    .X(_1390_));
 sky130_fd_sc_hd__a21oi_1 _1759_ (.A1(_0510_),
    .A2(_0498_),
    .B1(_0463_),
    .Y(u_uart_master_core_u_host_bridge_tx_idx_d_3_));
 sky130_fd_sc_hd__nand2_1 _1760_ (.A(net117),
    .B(net126),
    .Y(_1339_));
 sky130_fd_sc_hd__o21ai_2 _1761_ (.A1(net117),
    .A2(_1117_),
    .B1(_1339_),
    .Y(u_uart_master_core_u_uart_core_rx_fifo_data_6_));
 sky130_fd_sc_hd__a21oi_1 _1762_ (.A1(_1093_),
    .A2(u_uart_master_core_u_uart_core_uart_tx_baud_div_q_2_),
    .B1(u_uart_master_core_u_uart_core_uart_tx_baud_div_q_3_),
    .Y(_1340_));
 sky130_fd_sc_hd__nor2_1 _1763_ (.A(_1340_),
    .B(_1390_),
    .Y(_0316_));
 sky130_fd_sc_hd__xor2_1 _1764_ (.A(net121),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_3_),
    .X(_1341_));
 sky130_fd_sc_hd__xor2_1 _1765_ (.A(_1341_),
    .B(_0361_),
    .X(_0011_));
 sky130_fd_sc_hd__nand2_1 _1766_ (.A(net60),
    .B(tl_i[101]),
    .Y(_1342_));
 sky130_fd_sc_hd__nand2_1 _1767_ (.A(net68),
    .B(u_uart_master_reg_tl_o_58_),
    .Y(_1343_));
 sky130_fd_sc_hd__nand2_1 _1768_ (.A(_1342_),
    .B(_1343_),
    .Y(_0317_));
 sky130_fd_sc_hd__nand2_1 _1769_ (.A(net60),
    .B(tl_i[99]),
    .Y(_1344_));
 sky130_fd_sc_hd__nand2_1 _1770_ (.A(net68),
    .B(u_uart_master_reg_tl_o_56_),
    .Y(_1345_));
 sky130_fd_sc_hd__nand2_1 _1771_ (.A(_1344_),
    .B(_1345_),
    .Y(_0318_));
 sky130_fd_sc_hd__nand2_1 _1772_ (.A(net123),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_0_),
    .Y(_1346_));
 sky130_fd_sc_hd__nor2_1 _1773_ (.A(reg2hw_42_),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_1_),
    .Y(_1347_));
 sky130_fd_sc_hd__nand2_1 _1774_ (.A(reg2hw_42_),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_1_),
    .Y(_1348_));
 sky130_fd_sc_hd__o21ai_1 _1775_ (.A1(_1346_),
    .A2(_1347_),
    .B1(_1348_),
    .Y(_1349_));
 sky130_fd_sc_hd__xor2_1 _1776_ (.A(net122),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_2_),
    .X(_1350_));
 sky130_fd_sc_hd__xor2_1 _1777_ (.A(_1349_),
    .B(_1350_),
    .X(_0010_));
 sky130_fd_sc_hd__inv_1 _1778_ (.A(net106),
    .Y(_1351_));
 sky130_fd_sc_hd__nand2_1 _1779_ (.A(_1351_),
    .B(net107),
    .Y(_1352_));
 sky130_fd_sc_hd__inv_2 _1780_ (.A(net104),
    .Y(_1353_));
 sky130_fd_sc_hd__nand2_1 _1781_ (.A(u_uart_master_core_u_uart_core_uart_rx_sreg_q_10_),
    .B(u_uart_master_core_u_uart_core_rx_valid),
    .Y(_1354_));
 sky130_fd_sc_hd__xnor2_1 _1782_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .B(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .Y(_1355_));
 sky130_fd_sc_hd__xnor2_1 _1783_ (.A(net109),
    .B(net105),
    .Y(_1356_));
 sky130_fd_sc_hd__clkinv_1 _1784_ (.A(_1356_),
    .Y(_1357_));
 sky130_fd_sc_hd__xnor2_1 _1785_ (.A(net110),
    .B(net106),
    .Y(_1358_));
 sky130_fd_sc_hd__clkinv_1 _1786_ (.A(_1358_),
    .Y(_1359_));
 sky130_fd_sc_hd__nor2_1 _1787_ (.A(net108),
    .B(_1353_),
    .Y(_1360_));
 sky130_fd_sc_hd__clkinv_4 _1788_ (.A(net108),
    .Y(_1361_));
 sky130_fd_sc_hd__nor2_1 _1789_ (.A(net104),
    .B(_1361_),
    .Y(_1362_));
 sky130_fd_sc_hd__nor2_1 _1790_ (.A(_1360_),
    .B(_1362_),
    .Y(_1363_));
 sky130_fd_sc_hd__inv_1 _1791_ (.A(_1363_),
    .Y(_1364_));
 sky130_fd_sc_hd__inv_2 _1792_ (.A(net111),
    .Y(_1365_));
 sky130_fd_sc_hd__nor2_1 _1793_ (.A(net107),
    .B(_1365_),
    .Y(_1366_));
 sky130_fd_sc_hd__clkinv_1 _1794_ (.A(net107),
    .Y(_1367_));
 sky130_fd_sc_hd__nor2_1 _1795_ (.A(net111),
    .B(_1367_),
    .Y(_1368_));
 sky130_fd_sc_hd__nor2_1 _1796_ (.A(_1366_),
    .B(_1368_),
    .Y(_1369_));
 sky130_fd_sc_hd__inv_1 _1797_ (.A(_1369_),
    .Y(_1370_));
 sky130_fd_sc_hd__nor4_2 _1798_ (.A(_1357_),
    .B(_1359_),
    .C(_1364_),
    .D(_1370_),
    .Y(_1371_));
 sky130_fd_sc_hd__inv_1 _1799_ (.A(_1371_),
    .Y(_1372_));
 sky130_fd_sc_hd__nor2_1 _1800_ (.A(_1355_),
    .B(_1372_),
    .Y(_1373_));
 sky130_fd_sc_hd__or2_4 _1801_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_under_rst),
    .B(_1373_),
    .X(_1374_));
 sky130_fd_sc_hd__nor2_2 _1802_ (.A(_1354_),
    .B(_1374_),
    .Y(_1375_));
 sky130_fd_sc_hd__xnor2_1 _1803_ (.A(net125),
    .B(u_uart_master_core_u_uart_core_uart_rx_sreg_q_9_),
    .Y(_1376_));
 sky130_fd_sc_hd__xnor2_1 _1804_ (.A(net127),
    .B(net126),
    .Y(_1377_));
 sky130_fd_sc_hd__xor2_1 _1805_ (.A(net131),
    .B(u_uart_master_core_u_uart_core_uart_rx_sreg_q_1_),
    .X(_1378_));
 sky130_fd_sc_hd__xnor2_1 _1806_ (.A(_1377_),
    .B(_1378_),
    .Y(_1379_));
 sky130_fd_sc_hd__xor2_1 _1807_ (.A(_1376_),
    .B(_1379_),
    .X(_1380_));
 sky130_fd_sc_hd__xnor2_1 _1808_ (.A(net130),
    .B(net116),
    .Y(_1381_));
 sky130_fd_sc_hd__xnor2_1 _1809_ (.A(net129),
    .B(net128),
    .Y(_1382_));
 sky130_fd_sc_hd__xnor2_1 _1810_ (.A(_1381_),
    .B(_1382_),
    .Y(_1383_));
 sky130_fd_sc_hd__inv_1 _1811_ (.A(net117),
    .Y(_1384_));
 sky130_fd_sc_hd__a21oi_1 _1812_ (.A1(_1380_),
    .A2(_1383_),
    .B1(_1384_),
    .Y(_1385_));
 sky130_fd_sc_hd__o21ai_2 _1813_ (.A1(_1380_),
    .A2(_1383_),
    .B1(_1385_),
    .Y(_1386_));
 sky130_fd_sc_hd__nand2_4 _1814_ (.A(_1375_),
    .B(_1386_),
    .Y(_1387_));
 sky130_fd_sc_hd__nor2_2 _1815_ (.A(_1353_),
    .B(_1387_),
    .Y(_1388_));
 sky130_fd_sc_hd__inv_1 _1816_ (.A(net105),
    .Y(_0319_));
 sky130_fd_sc_hd__nand2_1 _1817_ (.A(_1388_),
    .B(_0319_),
    .Y(_0320_));
 sky130_fd_sc_hd__nor2_4 _1818_ (.A(net74),
    .B(net35),
    .Y(_0042_));
 sky130_fd_sc_hd__clkinv_1 _1819_ (.A(net135),
    .Y(_0321_));
 sky130_fd_sc_hd__inv_4 _1820_ (.A(net136),
    .Y(_0322_));
 sky130_fd_sc_hd__clkinv_1 _1821_ (.A(net137),
    .Y(_0323_));
 sky130_fd_sc_hd__xnor2_1 _1822_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .B(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .Y(_0324_));
 sky130_fd_sc_hd__inv_4 _1823_ (.A(net138),
    .Y(_0325_));
 sky130_fd_sc_hd__nor2_1 _1824_ (.A(net135),
    .B(_0325_),
    .Y(_0326_));
 sky130_fd_sc_hd__nor2_1 _1825_ (.A(net138),
    .B(net80),
    .Y(_0327_));
 sky130_fd_sc_hd__nor2_1 _1826_ (.A(_0326_),
    .B(_0327_),
    .Y(_0328_));
 sky130_fd_sc_hd__nor2_1 _1827_ (.A(net139),
    .B(_0322_),
    .Y(_0329_));
 sky130_fd_sc_hd__inv_4 _1828_ (.A(net139),
    .Y(_0330_));
 sky130_fd_sc_hd__nor2_1 _1829_ (.A(net136),
    .B(_0330_),
    .Y(_0331_));
 sky130_fd_sc_hd__nor2_1 _1830_ (.A(_0329_),
    .B(_0331_),
    .Y(_0332_));
 sky130_fd_sc_hd__nor2_1 _1831_ (.A(net140),
    .B(_0323_),
    .Y(_0333_));
 sky130_fd_sc_hd__inv_1 _1832_ (.A(net140),
    .Y(_0334_));
 sky130_fd_sc_hd__nor2_1 _1833_ (.A(net137),
    .B(_0334_),
    .Y(_0335_));
 sky130_fd_sc_hd__nor2_1 _1834_ (.A(_0333_),
    .B(_0335_),
    .Y(_0336_));
 sky130_fd_sc_hd__nand3_1 _1835_ (.A(_0328_),
    .B(_0332_),
    .C(_0336_),
    .Y(_0337_));
 sky130_fd_sc_hd__nor2_1 _1836_ (.A(_0324_),
    .B(_0337_),
    .Y(_0338_));
 sky130_fd_sc_hd__nor2_1 _1837_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_under_rst),
    .B(_0338_),
    .Y(_0339_));
 sky130_fd_sc_hd__o21ai_1 _1838_ (.A1(u_uart_master_core_u_host_bridge_tx_st_q_1_),
    .A2(reg2hw_4_),
    .B1(_0339_),
    .Y(_0340_));
 sky130_fd_sc_hd__nor2_2 _1839_ (.A(_0323_),
    .B(_0340_),
    .Y(_0341_));
 sky130_fd_sc_hd__clkinv_2 _1840_ (.A(_0341_),
    .Y(_0342_));
 sky130_fd_sc_hd__nor2_1 _1841_ (.A(_0322_),
    .B(_0342_),
    .Y(_0343_));
 sky130_fd_sc_hd__inv_2 _1842_ (.A(_0343_),
    .Y(_0344_));
 sky130_fd_sc_hd__nor2_4 _1843_ (.A(net80),
    .B(_0344_),
    .Y(_0036_));
 sky130_fd_sc_hd__inv_1 _1844_ (.A(_0340_),
    .Y(_0345_));
 sky130_fd_sc_hd__nand2_1 _1845_ (.A(_0345_),
    .B(_0323_),
    .Y(_0346_));
 sky130_fd_sc_hd__nor3_4 _1846_ (.A(net80),
    .B(_0322_),
    .C(net51),
    .Y(_0033_));
 sky130_fd_sc_hd__nor3_4 _1847_ (.A(net80),
    .B(net136),
    .C(_0342_),
    .Y(_0034_));
 sky130_fd_sc_hd__nor3_4 _1848_ (.A(net80),
    .B(net136),
    .C(net51),
    .Y(_0032_));
 sky130_fd_sc_hd__nor2_4 _1849_ (.A(net135),
    .B(_0344_),
    .Y(_0040_));
 sky130_fd_sc_hd__nor3_4 _1850_ (.A(net135),
    .B(_0322_),
    .C(net51),
    .Y(_0038_));
 sky130_fd_sc_hd__nor3_4 _1851_ (.A(net135),
    .B(net136),
    .C(_0342_),
    .Y(_0039_));
 sky130_fd_sc_hd__nor3_4 _1852_ (.A(net135),
    .B(net136),
    .C(net51),
    .Y(_0035_));
 sky130_fd_sc_hd__nand2_1 _1853_ (.A(_1351_),
    .B(_1367_),
    .Y(_0347_));
 sky130_fd_sc_hd__nor2_4 _1854_ (.A(net73),
    .B(net35),
    .Y(_0041_));
 sky130_fd_sc_hd__nand2_4 _1855_ (.A(net106),
    .B(net107),
    .Y(_0348_));
 sky130_fd_sc_hd__nor2_2 _1856_ (.A(_0348_),
    .B(_1387_),
    .Y(_0349_));
 sky130_fd_sc_hd__nand2_4 _1857_ (.A(_0349_),
    .B(net105),
    .Y(_0350_));
 sky130_fd_sc_hd__nor2_4 _1858_ (.A(net104),
    .B(_0350_),
    .Y(_0037_));
 sky130_fd_sc_hd__nor2_2 _1859_ (.A(net104),
    .B(_1387_),
    .Y(_0351_));
 sky130_fd_sc_hd__nand2_1 _1860_ (.A(_0351_),
    .B(_0319_),
    .Y(_0352_));
 sky130_fd_sc_hd__nor2_4 _1861_ (.A(net73),
    .B(net34),
    .Y(_0031_));
 sky130_fd_sc_hd__nand2_1 _1862_ (.A(_1367_),
    .B(net106),
    .Y(_0353_));
 sky130_fd_sc_hd__nor2_4 _1863_ (.A(net72),
    .B(net35),
    .Y(_0030_));
 sky130_fd_sc_hd__nor2_4 _1864_ (.A(_0348_),
    .B(net35),
    .Y(_0029_));
 sky130_fd_sc_hd__nand2_4 _1865_ (.A(_1388_),
    .B(net105),
    .Y(_0354_));
 sky130_fd_sc_hd__nor2_4 _1866_ (.A(net73),
    .B(_0354_),
    .Y(_0028_));
 sky130_fd_sc_hd__nor2_4 _1867_ (.A(net74),
    .B(_0354_),
    .Y(_0027_));
 sky130_fd_sc_hd__nor2_4 _1868_ (.A(net72),
    .B(_0354_),
    .Y(_0026_));
 sky130_fd_sc_hd__nor2_4 _1869_ (.A(_1353_),
    .B(_0350_),
    .Y(_0025_));
 sky130_fd_sc_hd__nor2_4 _1870_ (.A(net74),
    .B(net34),
    .Y(_0024_));
 sky130_fd_sc_hd__nor2_4 _1871_ (.A(_0348_),
    .B(net34),
    .Y(_0022_));
 sky130_fd_sc_hd__nand2_4 _1872_ (.A(_0351_),
    .B(net105),
    .Y(_0355_));
 sky130_fd_sc_hd__nor2_4 _1873_ (.A(net73),
    .B(_0355_),
    .Y(_0021_));
 sky130_fd_sc_hd__nor2_4 _1874_ (.A(net74),
    .B(_0355_),
    .Y(_0020_));
 sky130_fd_sc_hd__nor2_4 _1875_ (.A(net72),
    .B(_0355_),
    .Y(_0019_));
 sky130_fd_sc_hd__clkinv_1 _1876_ (.A(net131),
    .Y(_0356_));
 sky130_fd_sc_hd__nand2_1 _1877_ (.A(u_uart_master_core_u_uart_core_uart_rx_sreg_q_1_),
    .B(net117),
    .Y(_0357_));
 sky130_fd_sc_hd__o21ai_2 _1878_ (.A1(net117),
    .A2(_0356_),
    .B1(_0357_),
    .Y(u_uart_master_core_u_uart_core_rx_fifo_data_0_));
 sky130_fd_sc_hd__clkinv_1 _1879_ (.A(net126),
    .Y(_0358_));
 sky130_fd_sc_hd__nand2_1 _1880_ (.A(net117),
    .B(net127),
    .Y(_0359_));
 sky130_fd_sc_hd__o21ai_2 _1881_ (.A1(net117),
    .A2(_0358_),
    .B1(_0359_),
    .Y(u_uart_master_core_u_uart_core_rx_fifo_data_5_));
 sky130_fd_sc_hd__xor2_1 _1882_ (.A(net119),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_5_),
    .X(_0360_));
 sky130_fd_sc_hd__maj3_1 _1883_ (.A(net122),
    .B(_1349_),
    .C(u_uart_master_core_u_uart_core_nco_sum_q_2_),
    .X(_0361_));
 sky130_fd_sc_hd__maj3_1 _1884_ (.A(net121),
    .B(_0361_),
    .C(u_uart_master_core_u_uart_core_nco_sum_q_3_),
    .X(_0362_));
 sky130_fd_sc_hd__maj3_1 _1885_ (.A(net120),
    .B(_0362_),
    .C(u_uart_master_core_u_uart_core_nco_sum_q_4_),
    .X(_0363_));
 sky130_fd_sc_hd__xor2_1 _1886_ (.A(_0360_),
    .B(_0363_),
    .X(_0013_));
 sky130_fd_sc_hd__xor2_1 _1887_ (.A(net120),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_4_),
    .X(_0364_));
 sky130_fd_sc_hd__xor2_1 _1888_ (.A(_0364_),
    .B(_0362_),
    .X(_0012_));
 sky130_fd_sc_hd__inv_1 _1889_ (.A(_1348_),
    .Y(_0365_));
 sky130_fd_sc_hd__nor2_1 _1890_ (.A(_1347_),
    .B(_0365_),
    .Y(_0366_));
 sky130_fd_sc_hd__xnor2_1 _1891_ (.A(_1346_),
    .B(_0366_),
    .Y(_0009_));
 sky130_fd_sc_hd__nor2_1 _1892_ (.A(reg2hw_56_),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_15_),
    .Y(_0367_));
 sky130_fd_sc_hd__nand2_1 _1893_ (.A(reg2hw_56_),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_15_),
    .Y(_0368_));
 sky130_fd_sc_hd__inv_1 _1894_ (.A(_0368_),
    .Y(_0369_));
 sky130_fd_sc_hd__nor2_1 _1895_ (.A(_0367_),
    .B(_0369_),
    .Y(_0370_));
 sky130_fd_sc_hd__lpflow_inputiso0n_1 _1896_ (.A(reg2hw_55_),
    .SLEEP_B(u_uart_master_core_u_uart_core_nco_sum_q_14_),
    .X(_0371_));
 sky130_fd_sc_hd__nor2_1 _1897_ (.A(reg2hw_55_),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_14_),
    .Y(_0372_));
 sky130_fd_sc_hd__nor2_1 _1898_ (.A(reg2hw_52_),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_11_),
    .Y(_0373_));
 sky130_fd_sc_hd__inv_1 _1899_ (.A(reg2hw_52_),
    .Y(_0374_));
 sky130_fd_sc_hd__inv_1 _1900_ (.A(u_uart_master_core_u_uart_core_nco_sum_q_11_),
    .Y(_0375_));
 sky130_fd_sc_hd__nor2_1 _1901_ (.A(_0374_),
    .B(_0375_),
    .Y(_0376_));
 sky130_fd_sc_hd__nor2_1 _1902_ (.A(_0373_),
    .B(_0376_),
    .Y(_0377_));
 sky130_fd_sc_hd__xor2_1 _1903_ (.A(net118),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_10_),
    .X(_0378_));
 sky130_fd_sc_hd__nand2_1 _1904_ (.A(_0377_),
    .B(_0378_),
    .Y(_0379_));
 sky130_fd_sc_hd__nor2_1 _1905_ (.A(reg2hw_50_),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_9_),
    .Y(_0380_));
 sky130_fd_sc_hd__inv_1 _1906_ (.A(reg2hw_50_),
    .Y(_0381_));
 sky130_fd_sc_hd__inv_1 _1907_ (.A(u_uart_master_core_u_uart_core_nco_sum_q_9_),
    .Y(_0382_));
 sky130_fd_sc_hd__nor2_1 _1908_ (.A(_0381_),
    .B(_0382_),
    .Y(_0383_));
 sky130_fd_sc_hd__nor2_1 _1909_ (.A(_0380_),
    .B(_0383_),
    .Y(_0384_));
 sky130_fd_sc_hd__nor2_1 _1910_ (.A(reg2hw_49_),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_8_),
    .Y(_0385_));
 sky130_fd_sc_hd__inv_1 _1911_ (.A(reg2hw_49_),
    .Y(_0386_));
 sky130_fd_sc_hd__inv_1 _1912_ (.A(u_uart_master_core_u_uart_core_nco_sum_q_8_),
    .Y(_0387_));
 sky130_fd_sc_hd__nor2_1 _1913_ (.A(_0386_),
    .B(_0387_),
    .Y(_0388_));
 sky130_fd_sc_hd__nor2_1 _1914_ (.A(_0385_),
    .B(_0388_),
    .Y(_0389_));
 sky130_fd_sc_hd__nand2_1 _1915_ (.A(_0384_),
    .B(_0389_),
    .Y(_0390_));
 sky130_fd_sc_hd__maj3_2 _1916_ (.A(net119),
    .B(_0363_),
    .C(u_uart_master_core_u_uart_core_nco_sum_q_5_),
    .X(_0391_));
 sky130_fd_sc_hd__nor2_1 _1917_ (.A(reg2hw_48_),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_7_),
    .Y(_0392_));
 sky130_fd_sc_hd__inv_1 _1918_ (.A(reg2hw_48_),
    .Y(_0393_));
 sky130_fd_sc_hd__inv_1 _1919_ (.A(u_uart_master_core_u_uart_core_nco_sum_q_7_),
    .Y(_0394_));
 sky130_fd_sc_hd__nor2_1 _1920_ (.A(_0393_),
    .B(_0394_),
    .Y(_0395_));
 sky130_fd_sc_hd__nor2_1 _1921_ (.A(_0392_),
    .B(_0395_),
    .Y(_0396_));
 sky130_fd_sc_hd__nor2_1 _1922_ (.A(reg2hw_47_),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_6_),
    .Y(_0397_));
 sky130_fd_sc_hd__inv_1 _1923_ (.A(reg2hw_47_),
    .Y(_0398_));
 sky130_fd_sc_hd__inv_1 _1924_ (.A(u_uart_master_core_u_uart_core_nco_sum_q_6_),
    .Y(_0399_));
 sky130_fd_sc_hd__nor2_1 _1925_ (.A(_0398_),
    .B(_0399_),
    .Y(_0400_));
 sky130_fd_sc_hd__nor2_2 _1926_ (.A(_0397_),
    .B(_0400_),
    .Y(_0401_));
 sky130_fd_sc_hd__nor3_1 _1927_ (.A(_0398_),
    .B(_0399_),
    .C(_0392_),
    .Y(_0402_));
 sky130_fd_sc_hd__a311oi_2 _1928_ (.A1(_0391_),
    .A2(_0396_),
    .A3(_0401_),
    .B1(_0395_),
    .C1(_0402_),
    .Y(_0403_));
 sky130_fd_sc_hd__nand2_1 _1929_ (.A(net118),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_10_),
    .Y(_0404_));
 sky130_fd_sc_hd__nor2_1 _1930_ (.A(_0404_),
    .B(_0373_),
    .Y(_0405_));
 sky130_fd_sc_hd__inv_1 _1931_ (.A(_0380_),
    .Y(_0406_));
 sky130_fd_sc_hd__a21oi_1 _1932_ (.A1(_0388_),
    .A2(_0406_),
    .B1(_0383_),
    .Y(_0407_));
 sky130_fd_sc_hd__nor2_1 _1933_ (.A(_0407_),
    .B(_0379_),
    .Y(_0408_));
 sky130_fd_sc_hd__nor3_1 _1934_ (.A(_0376_),
    .B(_0405_),
    .C(_0408_),
    .Y(_0409_));
 sky130_fd_sc_hd__o31ai_1 _1935_ (.A1(_0379_),
    .A2(_0390_),
    .A3(_0403_),
    .B1(_0409_),
    .Y(_0410_));
 sky130_fd_sc_hd__nor2_1 _1936_ (.A(reg2hw_54_),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_13_),
    .Y(_0411_));
 sky130_fd_sc_hd__inv_1 _1937_ (.A(reg2hw_54_),
    .Y(_0412_));
 sky130_fd_sc_hd__inv_1 _1938_ (.A(u_uart_master_core_u_uart_core_nco_sum_q_13_),
    .Y(_0413_));
 sky130_fd_sc_hd__nor2_1 _1939_ (.A(_0412_),
    .B(_0413_),
    .Y(_0414_));
 sky130_fd_sc_hd__nor2_1 _1940_ (.A(_0411_),
    .B(_0414_),
    .Y(_0415_));
 sky130_fd_sc_hd__nor2_1 _1941_ (.A(reg2hw_53_),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_12_),
    .Y(_0416_));
 sky130_fd_sc_hd__inv_1 _1942_ (.A(reg2hw_53_),
    .Y(_0417_));
 sky130_fd_sc_hd__inv_1 _1943_ (.A(u_uart_master_core_u_uart_core_nco_sum_q_12_),
    .Y(_0418_));
 sky130_fd_sc_hd__nor2_1 _1944_ (.A(_0417_),
    .B(_0418_),
    .Y(_0419_));
 sky130_fd_sc_hd__nor2_1 _1945_ (.A(_0416_),
    .B(_0419_),
    .Y(_0420_));
 sky130_fd_sc_hd__nor2_1 _1946_ (.A(_0414_),
    .B(_0419_),
    .Y(_0421_));
 sky130_fd_sc_hd__nor2_1 _1947_ (.A(_0411_),
    .B(_0421_),
    .Y(_0422_));
 sky130_fd_sc_hd__a31oi_1 _1948_ (.A1(_0410_),
    .A2(_0415_),
    .A3(_0420_),
    .B1(_0422_),
    .Y(_0423_));
 sky130_fd_sc_hd__nor3_1 _1949_ (.A(net79),
    .B(_0372_),
    .C(_0423_),
    .Y(_0424_));
 sky130_fd_sc_hd__nor2_1 _1950_ (.A(net79),
    .B(_0424_),
    .Y(_0425_));
 sky130_fd_sc_hd__xnor2_1 _1951_ (.A(_0370_),
    .B(_0425_),
    .Y(_0008_));
 sky130_fd_sc_hd__o21ai_1 _1952_ (.A1(_0390_),
    .A2(_0403_),
    .B1(_0407_),
    .Y(_0426_));
 sky130_fd_sc_hd__nand2_1 _1953_ (.A(_0426_),
    .B(_0378_),
    .Y(_0427_));
 sky130_fd_sc_hd__nand2_1 _1954_ (.A(_0427_),
    .B(_0404_),
    .Y(_0428_));
 sky130_fd_sc_hd__xor2_1 _1955_ (.A(_0377_),
    .B(_0428_),
    .X(_0004_));
 sky130_fd_sc_hd__xor2_1 _1956_ (.A(_0378_),
    .B(_0426_),
    .X(_0003_));
 sky130_fd_sc_hd__o21a_1 _1957_ (.A1(net79),
    .A2(_0372_),
    .B1(_0423_),
    .X(_0429_));
 sky130_fd_sc_hd__nor2_1 _1958_ (.A(_0424_),
    .B(_0429_),
    .Y(_0007_));
 sky130_fd_sc_hd__a21oi_1 _1959_ (.A1(_0410_),
    .A2(_0420_),
    .B1(_0419_),
    .Y(_0430_));
 sky130_fd_sc_hd__xnor2_1 _1960_ (.A(_0415_),
    .B(_0430_),
    .Y(_0006_));
 sky130_fd_sc_hd__xor2_1 _1961_ (.A(_0420_),
    .B(_0410_),
    .X(_0005_));
 sky130_fd_sc_hd__inv_1 _1962_ (.A(_0389_),
    .Y(_0431_));
 sky130_fd_sc_hd__nor2_1 _1963_ (.A(_0431_),
    .B(_0403_),
    .Y(_0432_));
 sky130_fd_sc_hd__nor2_1 _1964_ (.A(_0388_),
    .B(_0432_),
    .Y(_0433_));
 sky130_fd_sc_hd__xnor2_1 _1965_ (.A(_0384_),
    .B(_0433_),
    .Y(_0017_));
 sky130_fd_sc_hd__xor2_1 _1966_ (.A(_0431_),
    .B(_0403_),
    .X(_0016_));
 sky130_fd_sc_hd__a21oi_1 _1967_ (.A1(_0391_),
    .A2(_0401_),
    .B1(_0400_),
    .Y(_0434_));
 sky130_fd_sc_hd__xnor2_1 _1968_ (.A(_0396_),
    .B(_0434_),
    .Y(_0015_));
 sky130_fd_sc_hd__inv_1 _1969_ (.A(net87),
    .Y(_0435_));
 sky130_fd_sc_hd__nor2_1 _1970_ (.A(net86),
    .B(_0435_),
    .Y(_0436_));
 sky130_fd_sc_hd__nor2_2 _1971_ (.A(net89),
    .B(net88),
    .Y(_0437_));
 sky130_fd_sc_hd__nand2_1 _1972_ (.A(_0436_),
    .B(_0437_),
    .Y(_0438_));
 sky130_fd_sc_hd__clkinv_2 _1973_ (.A(_0438_),
    .Y(_0439_));
 sky130_fd_sc_hd__clkinv_1 _1974_ (.A(net89),
    .Y(_0440_));
 sky130_fd_sc_hd__nor2_1 _1975_ (.A(net88),
    .B(_0440_),
    .Y(_0441_));
 sky130_fd_sc_hd__nand2_1 _1976_ (.A(_0436_),
    .B(_0441_),
    .Y(_0442_));
 sky130_fd_sc_hd__inv_2 _1977_ (.A(_0442_),
    .Y(_0443_));
 sky130_fd_sc_hd__clkinv_1 _1978_ (.A(net88),
    .Y(_0444_));
 sky130_fd_sc_hd__nor2_2 _1979_ (.A(_0440_),
    .B(_0444_),
    .Y(_0445_));
 sky130_fd_sc_hd__nand2_4 _1980_ (.A(_0445_),
    .B(net87),
    .Y(_0446_));
 sky130_fd_sc_hd__nor2_4 _1981_ (.A(net86),
    .B(_0446_),
    .Y(_0447_));
 sky130_fd_sc_hd__nand2_1 _1982_ (.A(_0447_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_6_),
    .Y(_0448_));
 sky130_fd_sc_hd__nor2_1 _1983_ (.A(net89),
    .B(_0444_),
    .Y(_0449_));
 sky130_fd_sc_hd__nand2_1 _1984_ (.A(_0449_),
    .B(_0436_),
    .Y(_0450_));
 sky130_fd_sc_hd__inv_2 _1985_ (.A(_0450_),
    .Y(_0451_));
 sky130_fd_sc_hd__nand2_1 _1986_ (.A(_0451_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_14_),
    .Y(_0452_));
 sky130_fd_sc_hd__nor2_2 _1987_ (.A(net86),
    .B(net87),
    .Y(_0453_));
 sky130_fd_sc_hd__nand2_1 _1988_ (.A(_0449_),
    .B(_0453_),
    .Y(_0454_));
 sky130_fd_sc_hd__inv_2 _1989_ (.A(_0454_),
    .Y(_0455_));
 sky130_fd_sc_hd__nand2_1 _1990_ (.A(_0455_),
    .B(u_uart_master_core_u_host_bridge_op_q_6_),
    .Y(_0456_));
 sky130_fd_sc_hd__nand2_4 _1991_ (.A(_0453_),
    .B(_0437_),
    .Y(_0457_));
 sky130_fd_sc_hd__nand4_1 _1992_ (.A(_0448_),
    .B(_0452_),
    .C(_0456_),
    .D(_0457_),
    .Y(_0458_));
 sky130_fd_sc_hd__a221oi_1 _1993_ (.A1(u_uart_master_core_u_host_bridge_rdata_q_30_),
    .A2(_0439_),
    .B1(u_uart_master_core_u_host_bridge_rdata_q_22_),
    .B2(_0443_),
    .C1(_0458_),
    .Y(_0459_));
 sky130_fd_sc_hd__inv_1 _1994_ (.A(u_uart_master_core_u_host_bridge_tx_st_q_1_),
    .Y(_0460_));
 sky130_fd_sc_hd__inv_1 _1995_ (.A(_0339_),
    .Y(_0461_));
 sky130_fd_sc_hd__nor2_2 _1996_ (.A(_0460_),
    .B(_0461_),
    .Y(_0462_));
 sky130_fd_sc_hd__clkinv_1 _1997_ (.A(net86),
    .Y(_0463_));
 sky130_fd_sc_hd__nand2_4 _1998_ (.A(_0462_),
    .B(_0463_),
    .Y(_0464_));
 sky130_fd_sc_hd__o21bai_1 _1999_ (.A1(_0459_),
    .A2(_0464_),
    .B1_N(reg2hw_11_),
    .Y(u_uart_master_core_u_uart_core_tx_fifo_wdata_6_));
 sky130_fd_sc_hd__inv_1 _2000_ (.A(u_uart_master_core_u_host_bridge_rdata_q_13_),
    .Y(_0465_));
 sky130_fd_sc_hd__a22oi_1 _2001_ (.A1(_0455_),
    .A2(u_uart_master_core_u_host_bridge_op_q_5_),
    .B1(_0447_),
    .B2(u_uart_master_core_u_host_bridge_rdata_q_5_),
    .Y(_0466_));
 sky130_fd_sc_hd__o21ai_0 _2002_ (.A1(_0465_),
    .A2(_0450_),
    .B1(_0466_),
    .Y(_0467_));
 sky130_fd_sc_hd__a221oi_1 _2003_ (.A1(u_uart_master_core_u_host_bridge_rdata_q_29_),
    .A2(_0439_),
    .B1(u_uart_master_core_u_host_bridge_rdata_q_21_),
    .B2(_0443_),
    .C1(_0467_),
    .Y(_0468_));
 sky130_fd_sc_hd__o21bai_1 _2004_ (.A1(_0468_),
    .A2(_0464_),
    .B1_N(reg2hw_10_),
    .Y(u_uart_master_core_u_uart_core_tx_fifo_wdata_5_));
 sky130_fd_sc_hd__a22oi_1 _2005_ (.A1(_0439_),
    .A2(u_uart_master_core_u_host_bridge_rdata_q_28_),
    .B1(u_uart_master_core_u_host_bridge_rdata_q_20_),
    .B2(_0443_),
    .Y(_0469_));
 sky130_fd_sc_hd__nand2_1 _2006_ (.A(_0455_),
    .B(u_uart_master_core_u_host_bridge_op_q_4_),
    .Y(_0470_));
 sky130_fd_sc_hd__nand3_1 _2007_ (.A(_0469_),
    .B(_0457_),
    .C(_0470_),
    .Y(_0471_));
 sky130_fd_sc_hd__a221oi_1 _2008_ (.A1(u_uart_master_core_u_host_bridge_rdata_q_12_),
    .A2(_0451_),
    .B1(u_uart_master_core_u_host_bridge_rdata_q_4_),
    .B2(_0447_),
    .C1(_0471_),
    .Y(_0472_));
 sky130_fd_sc_hd__o21bai_1 _2009_ (.A1(_0472_),
    .A2(_0464_),
    .B1_N(reg2hw_9_),
    .Y(u_uart_master_core_u_uart_core_tx_fifo_wdata_4_));
 sky130_fd_sc_hd__a22oi_1 _2010_ (.A1(_0439_),
    .A2(u_uart_master_core_u_host_bridge_rdata_q_27_),
    .B1(_0447_),
    .B2(u_uart_master_core_u_host_bridge_rdata_q_3_),
    .Y(_0473_));
 sky130_fd_sc_hd__nand2_1 _2011_ (.A(_0451_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_11_),
    .Y(_0474_));
 sky130_fd_sc_hd__nand3_1 _2012_ (.A(_0473_),
    .B(_0457_),
    .C(_0474_),
    .Y(_0475_));
 sky130_fd_sc_hd__a221oi_1 _2013_ (.A1(u_uart_master_core_u_host_bridge_op_q_3_),
    .A2(_0455_),
    .B1(u_uart_master_core_u_host_bridge_rdata_q_19_),
    .B2(_0443_),
    .C1(_0475_),
    .Y(_0476_));
 sky130_fd_sc_hd__o21bai_1 _2014_ (.A1(_0476_),
    .A2(_0464_),
    .B1_N(reg2hw_8_),
    .Y(u_uart_master_core_u_uart_core_tx_fifo_wdata_3_));
 sky130_fd_sc_hd__inv_1 _2015_ (.A(u_uart_master_core_u_host_bridge_rdata_q_18_),
    .Y(_0477_));
 sky130_fd_sc_hd__a22oi_1 _2016_ (.A1(_0439_),
    .A2(u_uart_master_core_u_host_bridge_rdata_q_26_),
    .B1(_0447_),
    .B2(u_uart_master_core_u_host_bridge_rdata_q_2_),
    .Y(_0478_));
 sky130_fd_sc_hd__o21ai_0 _2017_ (.A1(_0477_),
    .A2(_0442_),
    .B1(_0478_),
    .Y(_0479_));
 sky130_fd_sc_hd__a221oi_1 _2018_ (.A1(u_uart_master_core_u_host_bridge_op_q_2_),
    .A2(_0455_),
    .B1(u_uart_master_core_u_host_bridge_rdata_q_10_),
    .B2(_0451_),
    .C1(_0479_),
    .Y(_0480_));
 sky130_fd_sc_hd__o21bai_1 _2019_ (.A1(_0480_),
    .A2(_0464_),
    .B1_N(reg2hw_7_),
    .Y(u_uart_master_core_u_uart_core_tx_fifo_wdata_2_));
 sky130_fd_sc_hd__inv_1 _2020_ (.A(u_uart_master_core_u_host_bridge_rdata_q_9_),
    .Y(_0481_));
 sky130_fd_sc_hd__a22oi_1 _2021_ (.A1(_0439_),
    .A2(u_uart_master_core_u_host_bridge_rdata_q_25_),
    .B1(_0447_),
    .B2(u_uart_master_core_u_host_bridge_rdata_q_1_),
    .Y(_0482_));
 sky130_fd_sc_hd__o211ai_1 _2022_ (.A1(_0481_),
    .A2(_0450_),
    .B1(_0457_),
    .C1(_0482_),
    .Y(_0483_));
 sky130_fd_sc_hd__a221oi_1 _2023_ (.A1(u_uart_master_core_u_host_bridge_op_q_1_),
    .A2(_0455_),
    .B1(u_uart_master_core_u_host_bridge_rdata_q_17_),
    .B2(_0443_),
    .C1(_0483_),
    .Y(_0484_));
 sky130_fd_sc_hd__o21bai_1 _2024_ (.A1(_0484_),
    .A2(_0464_),
    .B1_N(reg2hw_6_),
    .Y(u_uart_master_core_u_uart_core_tx_fifo_wdata_1_));
 sky130_fd_sc_hd__inv_1 _2025_ (.A(u_uart_master_core_u_host_bridge_op_q_0_),
    .Y(_0485_));
 sky130_fd_sc_hd__o211ai_1 _2026_ (.A1(u_uart_master_core_u_host_bridge_any_err_q),
    .A2(_0444_),
    .B1(net89),
    .C1(_0453_),
    .Y(_0486_));
 sky130_fd_sc_hd__nand2_1 _2027_ (.A(_0439_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_24_),
    .Y(_0487_));
 sky130_fd_sc_hd__nand2_1 _2028_ (.A(_0447_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_0_),
    .Y(_0488_));
 sky130_fd_sc_hd__o2111ai_1 _2029_ (.A1(_0485_),
    .A2(_0454_),
    .B1(_0486_),
    .C1(_0487_),
    .D1(_0488_),
    .Y(_0489_));
 sky130_fd_sc_hd__a221oi_1 _2030_ (.A1(u_uart_master_core_u_host_bridge_rdata_q_16_),
    .A2(_0443_),
    .B1(u_uart_master_core_u_host_bridge_rdata_q_8_),
    .B2(_0451_),
    .C1(_0489_),
    .Y(_0490_));
 sky130_fd_sc_hd__o21bai_1 _2031_ (.A1(_0490_),
    .A2(_0464_),
    .B1_N(reg2hw_5_),
    .Y(u_uart_master_core_u_uart_core_tx_fifo_wdata_0_));
 sky130_fd_sc_hd__o21ai_0 _2032_ (.A1(_0367_),
    .A2(_0425_),
    .B1(_0368_),
    .Y(_0001_));
 sky130_fd_sc_hd__clkinv_1 _2033_ (.A(net127),
    .Y(_0491_));
 sky130_fd_sc_hd__nand2_1 _2034_ (.A(net117),
    .B(net128),
    .Y(_0492_));
 sky130_fd_sc_hd__o21ai_2 _2035_ (.A1(net117),
    .A2(_0491_),
    .B1(_0492_),
    .Y(u_uart_master_core_u_uart_core_rx_fifo_data_4_));
 sky130_fd_sc_hd__xor2_1 _2036_ (.A(net123),
    .B(u_uart_master_core_u_uart_core_nco_sum_q_0_),
    .X(_0002_));
 sky130_fd_sc_hd__nor4_1 _2037_ (.A(u_uart_master_core_u_host_bridge_op_q_2_),
    .B(u_uart_master_core_u_host_bridge_op_q_3_),
    .C(u_uart_master_core_u_host_bridge_op_q_1_),
    .D(_0485_),
    .Y(_0493_));
 sky130_fd_sc_hd__nor4_1 _2038_ (.A(u_uart_master_core_u_host_bridge_op_q_6_),
    .B(u_uart_master_core_u_host_bridge_op_q_7_),
    .C(u_uart_master_core_u_host_bridge_op_q_4_),
    .D(u_uart_master_core_u_host_bridge_op_q_5_),
    .Y(_0494_));
 sky130_fd_sc_hd__nand2_1 _2039_ (.A(_0493_),
    .B(_0494_),
    .Y(_0495_));
 sky130_fd_sc_hd__nor3_1 _2040_ (.A(net86),
    .B(net87),
    .C(_0495_),
    .Y(_0496_));
 sky130_fd_sc_hd__nor2_1 _2041_ (.A(net87),
    .B(_0445_),
    .Y(_0497_));
 sky130_fd_sc_hd__nand2_1 _2042_ (.A(_0462_),
    .B(_0446_),
    .Y(_0498_));
 sky130_fd_sc_hd__inv_1 _2043_ (.A(_0462_),
    .Y(_0499_));
 sky130_fd_sc_hd__inv_1 _2044_ (.A(_0495_),
    .Y(_0500_));
 sky130_fd_sc_hd__clkinv_2 _2045_ (.A(net112),
    .Y(_0501_));
 sky130_fd_sc_hd__clkinv_1 _2046_ (.A(valid_i),
    .Y(_0502_));
 sky130_fd_sc_hd__inv_1 _2047_ (.A(net113),
    .Y(_0503_));
 sky130_fd_sc_hd__nor2_1 _2048_ (.A(net114),
    .B(_0503_),
    .Y(_0504_));
 sky130_fd_sc_hd__inv_2 _2049_ (.A(_0504_),
    .Y(_0505_));
 sky130_fd_sc_hd__nor3_4 _2050_ (.A(_0501_),
    .B(_0502_),
    .C(_0505_),
    .Y(_0506_));
 sky130_fd_sc_hd__inv_8 _2051_ (.A(_0506_),
    .Y(_0507_));
 sky130_fd_sc_hd__nor2_1 _2052_ (.A(_0500_),
    .B(_0507_),
    .Y(_0508_));
 sky130_fd_sc_hd__inv_1 _2053_ (.A(_0508_),
    .Y(_0509_));
 sky130_fd_sc_hd__nand2_1 _2054_ (.A(_0499_),
    .B(_0509_),
    .Y(_0510_));
 sky130_fd_sc_hd__o32ai_1 _2055_ (.A1(_0496_),
    .A2(_0497_),
    .A3(_0498_),
    .B1(_0435_),
    .B2(_0510_),
    .Y(u_uart_master_core_u_host_bridge_tx_idx_d_2_));
 sky130_fd_sc_hd__o21ai_0 _2056_ (.A1(_0449_),
    .A2(_0441_),
    .B1(_0462_),
    .Y(_0511_));
 sky130_fd_sc_hd__o21ai_0 _2057_ (.A1(_0444_),
    .A2(_0510_),
    .B1(_0511_),
    .Y(u_uart_master_core_u_host_bridge_tx_idx_d_1_));
 sky130_fd_sc_hd__nand2_1 _2058_ (.A(_0462_),
    .B(_0440_),
    .Y(_0512_));
 sky130_fd_sc_hd__o21ai_0 _2059_ (.A1(_0440_),
    .A2(_0510_),
    .B1(_0512_),
    .Y(u_uart_master_core_u_host_bridge_tx_idx_d_0_));
 sky130_fd_sc_hd__clkinv_1 _2060_ (.A(reg2hw_1_),
    .Y(_0513_));
 sky130_fd_sc_hd__clkinv_2 _2061_ (.A(reg2hw_0_),
    .Y(_0514_));
 sky130_fd_sc_hd__nor2_4 _2062_ (.A(_0513_),
    .B(_0514_),
    .Y(_0515_));
 sky130_fd_sc_hd__inv_1 _2063_ (.A(_0350_),
    .Y(_0516_));
 sky130_fd_sc_hd__nor2_1 _2064_ (.A(net104),
    .B(_0516_),
    .Y(_0517_));
 sky130_fd_sc_hd__nor3_1 _2065_ (.A(_0025_),
    .B(_0515_),
    .C(_0517_),
    .Y(_0043_));
 sky130_fd_sc_hd__nor2_1 _2066_ (.A(net105),
    .B(_0349_),
    .Y(_0518_));
 sky130_fd_sc_hd__nor3_1 _2067_ (.A(_0515_),
    .B(_0518_),
    .C(_0516_),
    .Y(_0044_));
 sky130_fd_sc_hd__nor2_1 _2068_ (.A(_1367_),
    .B(_1387_),
    .Y(_0519_));
 sky130_fd_sc_hd__nor2_1 _2069_ (.A(net106),
    .B(_0519_),
    .Y(_0520_));
 sky130_fd_sc_hd__nor3_1 _2070_ (.A(_0349_),
    .B(_0515_),
    .C(_0520_),
    .Y(_0045_));
 sky130_fd_sc_hd__a21oi_1 _2071_ (.A1(_1375_),
    .A2(_1386_),
    .B1(net107),
    .Y(_0521_));
 sky130_fd_sc_hd__nor3_1 _2072_ (.A(_0515_),
    .B(_0521_),
    .C(_0519_),
    .Y(_0046_));
 sky130_fd_sc_hd__inv_4 _2073_ (.A(net109),
    .Y(_0522_));
 sky130_fd_sc_hd__clkinv_1 _2074_ (.A(net110),
    .Y(_0523_));
 sky130_fd_sc_hd__nor2_1 _2075_ (.A(_0523_),
    .B(_1365_),
    .Y(_0524_));
 sky130_fd_sc_hd__inv_1 _2076_ (.A(_0524_),
    .Y(_0525_));
 sky130_fd_sc_hd__buf_2 _2077_ (.A(_0525_),
    .X(_0526_));
 sky130_fd_sc_hd__inv_1 _2078_ (.A(u_uart_master_reg_tl_o_65_),
    .Y(u_uart_master_reg_tl_o_0_));
 sky130_fd_sc_hd__nand2_1 _2079_ (.A(u_uart_master_reg_tl_o_0_),
    .B(tl_i[108]),
    .Y(_0527_));
 sky130_fd_sc_hd__nor4b_1 _2080_ (.A(tl_i[105]),
    .B(tl_i[106]),
    .C(net68),
    .D_N(tl_i[107]),
    .Y(_0528_));
 sky130_fd_sc_hd__inv_1 _2081_ (.A(tl_i[63]),
    .Y(_0529_));
 sky130_fd_sc_hd__nor3_2 _2082_ (.A(tl_i[64]),
    .B(tl_i[62]),
    .C(_0529_),
    .Y(_0530_));
 sky130_fd_sc_hd__nor2_1 _2083_ (.A(net114),
    .B(net113),
    .Y(_0531_));
 sky130_fd_sc_hd__inv_1 _2084_ (.A(_0531_),
    .Y(_0532_));
 sky130_fd_sc_hd__nor2_1 _2085_ (.A(net112),
    .B(_0532_),
    .Y(_0533_));
 sky130_fd_sc_hd__inv_1 _2086_ (.A(_0533_),
    .Y(_0534_));
 sky130_fd_sc_hd__a21oi_1 _2087_ (.A1(_0528_),
    .A2(_0530_),
    .B1(_0534_),
    .Y(_0535_));
 sky130_fd_sc_hd__nand2_4 _2088_ (.A(_1371_),
    .B(_1355_),
    .Y(_0536_));
 sky130_fd_sc_hd__clkinv_1 _2089_ (.A(_0536_),
    .Y(_0537_));
 sky130_fd_sc_hd__nor2_2 _2090_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_under_rst),
    .B(_0537_),
    .Y(_0538_));
 sky130_fd_sc_hd__inv_2 _2091_ (.A(_0538_),
    .Y(_0539_));
 sky130_fd_sc_hd__nor2_2 _2092_ (.A(_0535_),
    .B(_0539_),
    .Y(_0540_));
 sky130_fd_sc_hd__inv_1 _2093_ (.A(_0540_),
    .Y(_0541_));
 sky130_fd_sc_hd__nor3_1 _2094_ (.A(_0522_),
    .B(net62),
    .C(_0541_),
    .Y(_0542_));
 sky130_fd_sc_hd__inv_1 _2095_ (.A(_0542_),
    .Y(_0543_));
 sky130_fd_sc_hd__inv_1 _2096_ (.A(_0515_),
    .Y(_0544_));
 sky130_fd_sc_hd__o21ai_0 _2097_ (.A1(_1361_),
    .A2(_0543_),
    .B1(_0544_),
    .Y(_0545_));
 sky130_fd_sc_hd__a21oi_1 _2098_ (.A1(_1361_),
    .A2(_0543_),
    .B1(_0545_),
    .Y(_0047_));
 sky130_fd_sc_hd__a21oi_1 _2099_ (.A1(_0540_),
    .A2(_0524_),
    .B1(net109),
    .Y(_0546_));
 sky130_fd_sc_hd__nor3_1 _2100_ (.A(_0515_),
    .B(_0546_),
    .C(_0542_),
    .Y(_0048_));
 sky130_fd_sc_hd__nor2_1 _2101_ (.A(net110),
    .B(net111),
    .Y(_0547_));
 sky130_fd_sc_hd__inv_1 _2102_ (.A(_0547_),
    .Y(_0548_));
 sky130_fd_sc_hd__buf_2 _2103_ (.A(_0548_),
    .X(_0549_));
 sky130_fd_sc_hd__nand3_1 _2104_ (.A(_0540_),
    .B(net62),
    .C(net64),
    .Y(_0550_));
 sky130_fd_sc_hd__o32ai_1 _2105_ (.A1(_0523_),
    .A2(_0515_),
    .A3(_0540_),
    .B1(_0550_),
    .B2(_0545_),
    .Y(_0049_));
 sky130_fd_sc_hd__nand2_1 _2106_ (.A(_0541_),
    .B(net111),
    .Y(_0551_));
 sky130_fd_sc_hd__nand2_1 _2107_ (.A(_0540_),
    .B(_1365_),
    .Y(_0552_));
 sky130_fd_sc_hd__a21oi_1 _2108_ (.A1(_0551_),
    .A2(_0552_),
    .B1(_0515_),
    .Y(_0050_));
 sky130_fd_sc_hd__nor2_1 _2109_ (.A(net111),
    .B(_0523_),
    .Y(_0553_));
 sky130_fd_sc_hd__clkinv_1 _2110_ (.A(_0553_),
    .Y(_0554_));
 sky130_fd_sc_hd__nor2_4 _2111_ (.A(net110),
    .B(_1365_),
    .Y(_0555_));
 sky130_fd_sc_hd__inv_12 _2112_ (.A(_0555_),
    .Y(_0556_));
 sky130_fd_sc_hd__o221a_1 _2113_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_38_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_46_),
    .B2(_0556_),
    .C1(net109),
    .X(_0557_));
 sky130_fd_sc_hd__o221ai_1 _2114_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_54_),
    .A2(net63),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_62_),
    .B2(net62),
    .C1(_0557_),
    .Y(_0558_));
 sky130_fd_sc_hd__nor2_1 _2115_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_22_),
    .B(net63),
    .Y(_0559_));
 sky130_fd_sc_hd__o21ai_0 _2116_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_30_),
    .A2(net62),
    .B1(_0522_),
    .Y(_0560_));
 sky130_fd_sc_hd__nor2_1 _2117_ (.A(_0559_),
    .B(_0560_),
    .Y(_0561_));
 sky130_fd_sc_hd__o221ai_1 _2118_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_6_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_14_),
    .B2(_0556_),
    .C1(_0561_),
    .Y(_0562_));
 sky130_fd_sc_hd__o21ai_0 _2119_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_102_),
    .A2(net64),
    .B1(net109),
    .Y(_0563_));
 sky130_fd_sc_hd__nor2_1 _2120_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_118_),
    .B(net63),
    .Y(_0564_));
 sky130_fd_sc_hd__o22ai_1 _2121_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_110_),
    .A2(_0556_),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_126_),
    .B2(net62),
    .Y(_0565_));
 sky130_fd_sc_hd__nor3_1 _2122_ (.A(_0563_),
    .B(_0564_),
    .C(_0565_),
    .Y(_0566_));
 sky130_fd_sc_hd__nor2_1 _2123_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_86_),
    .B(net63),
    .Y(_0567_));
 sky130_fd_sc_hd__o22ai_1 _2124_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_70_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_78_),
    .B2(_0556_),
    .Y(_0568_));
 sky130_fd_sc_hd__o21ai_0 _2125_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_94_),
    .A2(net62),
    .B1(_0522_),
    .Y(_0569_));
 sky130_fd_sc_hd__nor3_1 _2126_ (.A(_0567_),
    .B(_0568_),
    .C(_0569_),
    .Y(_0570_));
 sky130_fd_sc_hd__nor3_1 _2127_ (.A(_1361_),
    .B(_0566_),
    .C(_0570_),
    .Y(_0571_));
 sky130_fd_sc_hd__a31oi_2 _2128_ (.A1(_1361_),
    .A2(_0558_),
    .A3(_0562_),
    .B1(_0571_),
    .Y(_0572_));
 sky130_fd_sc_hd__nand2_4 _2129_ (.A(_0572_),
    .B(_0536_),
    .Y(_0573_));
 sky130_fd_sc_hd__nand2_1 _2130_ (.A(_0501_),
    .B(net114),
    .Y(_0574_));
 sky130_fd_sc_hd__nor2_1 _2131_ (.A(_0503_),
    .B(_0574_),
    .Y(_0575_));
 sky130_fd_sc_hd__inv_1 _2132_ (.A(_0575_),
    .Y(_0576_));
 sky130_fd_sc_hd__inv_1 _2133_ (.A(u_uart_master_core_u_host_bridge_idx_q_0_),
    .Y(_0577_));
 sky130_fd_sc_hd__clkinv_1 _2134_ (.A(u_uart_master_core_u_host_bridge_idx_q_1_),
    .Y(_0578_));
 sky130_fd_sc_hd__nor2_1 _2135_ (.A(_0577_),
    .B(_0578_),
    .Y(_0579_));
 sky130_fd_sc_hd__nand2_1 _2136_ (.A(_0538_),
    .B(_0579_),
    .Y(_0580_));
 sky130_fd_sc_hd__nor2_1 _2137_ (.A(_0576_),
    .B(_0580_),
    .Y(_0581_));
 sky130_fd_sc_hd__clkinv_1 _2138_ (.A(_0581_),
    .Y(_0582_));
 sky130_fd_sc_hd__buf_2 _2139_ (.A(_0582_),
    .X(_0583_));
 sky130_fd_sc_hd__nor2_1 _2140_ (.A(net112),
    .B(_0505_),
    .Y(_0584_));
 sky130_fd_sc_hd__nor2_1 _2141_ (.A(_0575_),
    .B(_0584_),
    .Y(_0585_));
 sky130_fd_sc_hd__nand2_1 _2142_ (.A(_0500_),
    .B(_0584_),
    .Y(_0586_));
 sky130_fd_sc_hd__inv_1 _2143_ (.A(_0586_),
    .Y(_0587_));
 sky130_fd_sc_hd__nor2_1 _2144_ (.A(_0585_),
    .B(_0587_),
    .Y(_0588_));
 sky130_fd_sc_hd__inv_1 _2145_ (.A(_0588_),
    .Y(_0589_));
 sky130_fd_sc_hd__nor2_2 _2146_ (.A(_0589_),
    .B(_0580_),
    .Y(_0590_));
 sky130_fd_sc_hd__clkinv_1 _2147_ (.A(_0590_),
    .Y(_0591_));
 sky130_fd_sc_hd__nand2_1 _2148_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_30_),
    .Y(_0592_));
 sky130_fd_sc_hd__o21ai_0 _2149_ (.A1(_0573_),
    .A2(net33),
    .B1(_0592_),
    .Y(_0051_));
 sky130_fd_sc_hd__o221a_1 _2150_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_37_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_45_),
    .B2(_0556_),
    .C1(net109),
    .X(_0593_));
 sky130_fd_sc_hd__o221ai_1 _2151_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_53_),
    .A2(net63),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_61_),
    .B2(net62),
    .C1(_0593_),
    .Y(_0594_));
 sky130_fd_sc_hd__nor2_1 _2152_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_21_),
    .B(net63),
    .Y(_0595_));
 sky130_fd_sc_hd__o21ai_0 _2153_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_29_),
    .A2(net62),
    .B1(_0522_),
    .Y(_0596_));
 sky130_fd_sc_hd__nor2_1 _2154_ (.A(_0595_),
    .B(_0596_),
    .Y(_0597_));
 sky130_fd_sc_hd__o221ai_1 _2155_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_5_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_13_),
    .B2(_0556_),
    .C1(_0597_),
    .Y(_0598_));
 sky130_fd_sc_hd__nor2_1 _2156_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_117_),
    .B(net63),
    .Y(_0599_));
 sky130_fd_sc_hd__o22ai_1 _2157_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_101_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_109_),
    .B2(_0556_),
    .Y(_0600_));
 sky130_fd_sc_hd__o21ai_0 _2158_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_125_),
    .A2(net62),
    .B1(net109),
    .Y(_0601_));
 sky130_fd_sc_hd__nor3_1 _2159_ (.A(_0599_),
    .B(_0600_),
    .C(_0601_),
    .Y(_0602_));
 sky130_fd_sc_hd__nor2_1 _2160_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_85_),
    .B(net63),
    .Y(_0603_));
 sky130_fd_sc_hd__o22ai_1 _2161_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_69_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_77_),
    .B2(_0556_),
    .Y(_0604_));
 sky130_fd_sc_hd__o21ai_0 _2162_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_93_),
    .A2(net62),
    .B1(_0522_),
    .Y(_0605_));
 sky130_fd_sc_hd__nor3_1 _2163_ (.A(_0603_),
    .B(_0604_),
    .C(_0605_),
    .Y(_0606_));
 sky130_fd_sc_hd__nor3_1 _2164_ (.A(_1361_),
    .B(_0602_),
    .C(_0606_),
    .Y(_0607_));
 sky130_fd_sc_hd__a31oi_2 _2165_ (.A1(_1361_),
    .A2(_0594_),
    .A3(_0598_),
    .B1(_0607_),
    .Y(_0608_));
 sky130_fd_sc_hd__nand2_4 _2166_ (.A(_0608_),
    .B(_0536_),
    .Y(_0609_));
 sky130_fd_sc_hd__nand2_1 _2167_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_29_),
    .Y(_0610_));
 sky130_fd_sc_hd__o21ai_0 _2168_ (.A1(net33),
    .A2(_0609_),
    .B1(_0610_),
    .Y(_0052_));
 sky130_fd_sc_hd__nor2_1 _2169_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_100_),
    .B(net64),
    .Y(_0611_));
 sky130_fd_sc_hd__nor2_1 _2170_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_124_),
    .B(net62),
    .Y(_0612_));
 sky130_fd_sc_hd__o22ai_1 _2171_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_116_),
    .A2(net63),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_108_),
    .B2(_0556_),
    .Y(_0613_));
 sky130_fd_sc_hd__nor2_1 _2172_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_84_),
    .B(net63),
    .Y(_0614_));
 sky130_fd_sc_hd__o22ai_1 _2173_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_68_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_76_),
    .B2(_0556_),
    .Y(_0615_));
 sky130_fd_sc_hd__o21ai_0 _2174_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_92_),
    .A2(net62),
    .B1(_0522_),
    .Y(_0616_));
 sky130_fd_sc_hd__nor3_1 _2175_ (.A(_0614_),
    .B(_0615_),
    .C(_0616_),
    .Y(_0617_));
 sky130_fd_sc_hd__nor2_1 _2176_ (.A(_1361_),
    .B(_0617_),
    .Y(_0618_));
 sky130_fd_sc_hd__o41ai_1 _2177_ (.A1(_0522_),
    .A2(_0611_),
    .A3(_0612_),
    .A4(_0613_),
    .B1(_0618_),
    .Y(_0619_));
 sky130_fd_sc_hd__o21ai_0 _2178_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_12_),
    .A2(_0556_),
    .B1(_0522_),
    .Y(_0620_));
 sky130_fd_sc_hd__nor2_1 _2179_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_28_),
    .B(net62),
    .Y(_0621_));
 sky130_fd_sc_hd__o22ai_1 _2180_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_4_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_20_),
    .B2(net63),
    .Y(_0622_));
 sky130_fd_sc_hd__o221a_1 _2181_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_36_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_44_),
    .B2(_0556_),
    .C1(net109),
    .X(_0623_));
 sky130_fd_sc_hd__o221ai_1 _2182_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_52_),
    .A2(net63),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_60_),
    .B2(net62),
    .C1(_0623_),
    .Y(_0624_));
 sky130_fd_sc_hd__o311ai_0 _2183_ (.A1(_0620_),
    .A2(_0621_),
    .A3(_0622_),
    .B1(_1361_),
    .C1(_0624_),
    .Y(_0625_));
 sky130_fd_sc_hd__nand3_1 _2184_ (.A(_0619_),
    .B(_0536_),
    .C(_0625_),
    .Y(_0626_));
 sky130_fd_sc_hd__nand2_1 _2185_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_28_),
    .Y(_0627_));
 sky130_fd_sc_hd__o21ai_0 _2186_ (.A1(net33),
    .A2(net50),
    .B1(_0627_),
    .Y(_0053_));
 sky130_fd_sc_hd__nor2_1 _2187_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_83_),
    .B(net63),
    .Y(_0628_));
 sky130_fd_sc_hd__o22ai_1 _2188_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_67_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_75_),
    .B2(_0556_),
    .Y(_0629_));
 sky130_fd_sc_hd__o21ai_0 _2189_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_91_),
    .A2(net62),
    .B1(_0522_),
    .Y(_0630_));
 sky130_fd_sc_hd__nor3_1 _2190_ (.A(_0628_),
    .B(_0629_),
    .C(_0630_),
    .Y(_0631_));
 sky130_fd_sc_hd__nor2_1 _2191_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_99_),
    .B(net64),
    .Y(_0632_));
 sky130_fd_sc_hd__o21ai_0 _2192_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_115_),
    .A2(net63),
    .B1(net109),
    .Y(_0633_));
 sky130_fd_sc_hd__o22ai_1 _2193_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_107_),
    .A2(_0556_),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_123_),
    .B2(net62),
    .Y(_0634_));
 sky130_fd_sc_hd__nor3_1 _2194_ (.A(_0632_),
    .B(_0633_),
    .C(_0634_),
    .Y(_0635_));
 sky130_fd_sc_hd__nor2_1 _2195_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_19_),
    .B(net63),
    .Y(_0636_));
 sky130_fd_sc_hd__o22ai_1 _2196_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_3_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_11_),
    .B2(_0556_),
    .Y(_0637_));
 sky130_fd_sc_hd__o21ai_0 _2197_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_27_),
    .A2(net62),
    .B1(_0522_),
    .Y(_0638_));
 sky130_fd_sc_hd__nor3_1 _2198_ (.A(_0636_),
    .B(_0637_),
    .C(_0638_),
    .Y(_0639_));
 sky130_fd_sc_hd__o21ai_0 _2199_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_35_),
    .A2(net64),
    .B1(net109),
    .Y(_0640_));
 sky130_fd_sc_hd__nor2_1 _2200_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_59_),
    .B(net62),
    .Y(_0641_));
 sky130_fd_sc_hd__o22ai_1 _2201_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_51_),
    .A2(net63),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_43_),
    .B2(_0556_),
    .Y(_0642_));
 sky130_fd_sc_hd__o31ai_1 _2202_ (.A1(_0640_),
    .A2(_0641_),
    .A3(_0642_),
    .B1(_1361_),
    .Y(_0643_));
 sky130_fd_sc_hd__o32ai_1 _2203_ (.A1(_1361_),
    .A2(_0631_),
    .A3(_0635_),
    .B1(_0639_),
    .B2(_0643_),
    .Y(_0644_));
 sky130_fd_sc_hd__nor2_1 _2204_ (.A(_0537_),
    .B(_0644_),
    .Y(_0645_));
 sky130_fd_sc_hd__clkinv_1 _2205_ (.A(_0645_),
    .Y(_0646_));
 sky130_fd_sc_hd__nand2_1 _2206_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_27_),
    .Y(_0647_));
 sky130_fd_sc_hd__o21ai_0 _2207_ (.A1(_0582_),
    .A2(_0646_),
    .B1(_0647_),
    .Y(_0054_));
 sky130_fd_sc_hd__nor2_1 _2208_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_82_),
    .B(net63),
    .Y(_0648_));
 sky130_fd_sc_hd__o22ai_1 _2209_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_66_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_74_),
    .B2(_0556_),
    .Y(_0649_));
 sky130_fd_sc_hd__o21ai_0 _2210_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_90_),
    .A2(net62),
    .B1(net108),
    .Y(_0650_));
 sky130_fd_sc_hd__o221a_1 _2211_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_18_),
    .A2(net63),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_26_),
    .B2(net62),
    .C1(_1361_),
    .X(_0651_));
 sky130_fd_sc_hd__o221ai_1 _2212_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_2_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_10_),
    .B2(_0556_),
    .C1(_0651_),
    .Y(_0652_));
 sky130_fd_sc_hd__o311ai_0 _2213_ (.A1(_0648_),
    .A2(_0649_),
    .A3(_0650_),
    .B1(_0522_),
    .C1(_0652_),
    .Y(_0653_));
 sky130_fd_sc_hd__o21ai_0 _2214_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_122_),
    .A2(net62),
    .B1(net108),
    .Y(_0654_));
 sky130_fd_sc_hd__nor2_1 _2215_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_98_),
    .B(net64),
    .Y(_0655_));
 sky130_fd_sc_hd__o22ai_1 _2216_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_114_),
    .A2(net63),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_106_),
    .B2(_0556_),
    .Y(_0656_));
 sky130_fd_sc_hd__o221a_1 _2217_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_34_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_42_),
    .B2(_0556_),
    .C1(_1361_),
    .X(_0657_));
 sky130_fd_sc_hd__o221ai_1 _2218_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_50_),
    .A2(net63),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_58_),
    .B2(net62),
    .C1(_0657_),
    .Y(_0658_));
 sky130_fd_sc_hd__o311ai_0 _2219_ (.A1(_0654_),
    .A2(_0655_),
    .A3(_0656_),
    .B1(net109),
    .C1(_0658_),
    .Y(_0659_));
 sky130_fd_sc_hd__nand3_1 _2220_ (.A(_0653_),
    .B(_0659_),
    .C(_0536_),
    .Y(_0660_));
 sky130_fd_sc_hd__nand2_1 _2221_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_26_),
    .Y(_0661_));
 sky130_fd_sc_hd__o21ai_0 _2222_ (.A1(_0582_),
    .A2(net54),
    .B1(_0661_),
    .Y(_0055_));
 sky130_fd_sc_hd__nor2_1 _2223_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_17_),
    .B(net63),
    .Y(_0662_));
 sky130_fd_sc_hd__o22ai_1 _2224_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_1_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_9_),
    .B2(_0556_),
    .Y(_0663_));
 sky130_fd_sc_hd__o21ai_0 _2225_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_25_),
    .A2(net62),
    .B1(_0522_),
    .Y(_0664_));
 sky130_fd_sc_hd__nor3_1 _2226_ (.A(_0662_),
    .B(_0663_),
    .C(_0664_),
    .Y(_0665_));
 sky130_fd_sc_hd__nor2_1 _2227_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_41_),
    .B(_0556_),
    .Y(_0666_));
 sky130_fd_sc_hd__o21ai_0 _2228_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_33_),
    .A2(net64),
    .B1(net109),
    .Y(_0667_));
 sky130_fd_sc_hd__o22ai_1 _2229_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_49_),
    .A2(net63),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_57_),
    .B2(net62),
    .Y(_0668_));
 sky130_fd_sc_hd__nor3_1 _2230_ (.A(_0666_),
    .B(_0667_),
    .C(_0668_),
    .Y(_0669_));
 sky130_fd_sc_hd__nor2_1 _2231_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_81_),
    .B(net63),
    .Y(_0670_));
 sky130_fd_sc_hd__o22ai_1 _2232_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_65_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_73_),
    .B2(_0556_),
    .Y(_0671_));
 sky130_fd_sc_hd__o21ai_0 _2233_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_89_),
    .A2(net62),
    .B1(_0522_),
    .Y(_0672_));
 sky130_fd_sc_hd__nor3_1 _2234_ (.A(_0670_),
    .B(_0671_),
    .C(_0672_),
    .Y(_0673_));
 sky130_fd_sc_hd__nor2_1 _2235_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_113_),
    .B(net63),
    .Y(_0674_));
 sky130_fd_sc_hd__o22ai_1 _2236_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_97_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_105_),
    .B2(_0556_),
    .Y(_0675_));
 sky130_fd_sc_hd__o21ai_0 _2237_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_121_),
    .A2(net62),
    .B1(net109),
    .Y(_0676_));
 sky130_fd_sc_hd__o31ai_1 _2238_ (.A1(_0674_),
    .A2(_0675_),
    .A3(_0676_),
    .B1(net108),
    .Y(_0677_));
 sky130_fd_sc_hd__o32ai_1 _2239_ (.A1(net108),
    .A2(_0665_),
    .A3(_0669_),
    .B1(_0673_),
    .B2(_0677_),
    .Y(_0678_));
 sky130_fd_sc_hd__nor2_1 _2240_ (.A(_0537_),
    .B(_0678_),
    .Y(_0679_));
 sky130_fd_sc_hd__clkinv_1 _2241_ (.A(_0679_),
    .Y(_0680_));
 sky130_fd_sc_hd__nand2_1 _2242_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_25_),
    .Y(_0681_));
 sky130_fd_sc_hd__o21ai_0 _2243_ (.A1(_0582_),
    .A2(_0680_),
    .B1(_0681_),
    .Y(_0056_));
 sky130_fd_sc_hd__nor2_1 _2244_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_64_),
    .B(net64),
    .Y(_0682_));
 sky130_fd_sc_hd__o21ai_0 _2245_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_88_),
    .A2(_0525_),
    .B1(net108),
    .Y(_0683_));
 sky130_fd_sc_hd__o22ai_1 _2246_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_80_),
    .A2(net63),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_72_),
    .B2(_0556_),
    .Y(_0684_));
 sky130_fd_sc_hd__nor3_1 _2247_ (.A(_0682_),
    .B(_0683_),
    .C(_0684_),
    .Y(_0685_));
 sky130_fd_sc_hd__nor2_1 _2248_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_16_),
    .B(net63),
    .Y(_0686_));
 sky130_fd_sc_hd__o22ai_1 _2249_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_0_),
    .A2(_0548_),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_8_),
    .B2(_0556_),
    .Y(_0687_));
 sky130_fd_sc_hd__o21ai_0 _2250_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_24_),
    .A2(_0525_),
    .B1(_1361_),
    .Y(_0688_));
 sky130_fd_sc_hd__nor3_1 _2251_ (.A(_0686_),
    .B(_0687_),
    .C(_0688_),
    .Y(_0689_));
 sky130_fd_sc_hd__nor2_1 _2252_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_48_),
    .B(net63),
    .Y(_0690_));
 sky130_fd_sc_hd__o22ai_1 _2253_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_32_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_40_),
    .B2(_0556_),
    .Y(_0691_));
 sky130_fd_sc_hd__o21ai_0 _2254_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_56_),
    .A2(net62),
    .B1(_1361_),
    .Y(_0692_));
 sky130_fd_sc_hd__o221a_1 _2255_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_96_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_104_),
    .B2(_0556_),
    .C1(net108),
    .X(_0693_));
 sky130_fd_sc_hd__o221ai_1 _2256_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_112_),
    .A2(net63),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_120_),
    .B2(net62),
    .C1(_0693_),
    .Y(_0694_));
 sky130_fd_sc_hd__o311ai_0 _2257_ (.A1(_0690_),
    .A2(_0691_),
    .A3(_0692_),
    .B1(net109),
    .C1(_0694_),
    .Y(_0695_));
 sky130_fd_sc_hd__o311ai_2 _2258_ (.A1(net109),
    .A2(_0685_),
    .A3(_0689_),
    .B1(_0536_),
    .C1(_0695_),
    .Y(_0696_));
 sky130_fd_sc_hd__nand2_1 _2259_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_24_),
    .Y(_0697_));
 sky130_fd_sc_hd__o21ai_0 _2260_ (.A1(_0582_),
    .A2(_0696_),
    .B1(_0697_),
    .Y(_0057_));
 sky130_fd_sc_hd__inv_1 _2261_ (.A(u_uart_master_core_u_host_bridge_sh_q_31_),
    .Y(_0698_));
 sky130_fd_sc_hd__nand2_1 _2262_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_23_),
    .Y(_0699_));
 sky130_fd_sc_hd__o21ai_0 _2263_ (.A1(_0698_),
    .A2(net33),
    .B1(_0699_),
    .Y(_0058_));
 sky130_fd_sc_hd__inv_1 _2264_ (.A(u_uart_master_core_u_host_bridge_sh_q_30_),
    .Y(_0700_));
 sky130_fd_sc_hd__nand2_1 _2265_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_22_),
    .Y(_0701_));
 sky130_fd_sc_hd__o21ai_0 _2266_ (.A1(_0700_),
    .A2(net33),
    .B1(_0701_),
    .Y(_0059_));
 sky130_fd_sc_hd__inv_1 _2267_ (.A(u_uart_master_core_u_host_bridge_sh_q_29_),
    .Y(_0702_));
 sky130_fd_sc_hd__nand2_1 _2268_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_21_),
    .Y(_0703_));
 sky130_fd_sc_hd__o21ai_0 _2269_ (.A1(_0702_),
    .A2(net33),
    .B1(_0703_),
    .Y(_0060_));
 sky130_fd_sc_hd__inv_1 _2270_ (.A(u_uart_master_core_u_host_bridge_sh_q_28_),
    .Y(_0704_));
 sky130_fd_sc_hd__nand2_1 _2271_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_20_),
    .Y(_0705_));
 sky130_fd_sc_hd__o21ai_0 _2272_ (.A1(_0704_),
    .A2(net33),
    .B1(_0705_),
    .Y(_0061_));
 sky130_fd_sc_hd__inv_1 _2273_ (.A(u_uart_master_core_u_host_bridge_sh_q_27_),
    .Y(_0706_));
 sky130_fd_sc_hd__nand2_1 _2274_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_19_),
    .Y(_0707_));
 sky130_fd_sc_hd__o21ai_0 _2275_ (.A1(_0706_),
    .A2(net33),
    .B1(_0707_),
    .Y(_0062_));
 sky130_fd_sc_hd__inv_1 _2276_ (.A(u_uart_master_core_u_host_bridge_sh_q_26_),
    .Y(_0708_));
 sky130_fd_sc_hd__nand2_1 _2277_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_18_),
    .Y(_0709_));
 sky130_fd_sc_hd__o21ai_0 _2278_ (.A1(_0708_),
    .A2(net33),
    .B1(_0709_),
    .Y(_0063_));
 sky130_fd_sc_hd__inv_1 _2279_ (.A(u_uart_master_core_u_host_bridge_sh_q_25_),
    .Y(_0710_));
 sky130_fd_sc_hd__nand2_1 _2280_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_17_),
    .Y(_0711_));
 sky130_fd_sc_hd__o21ai_0 _2281_ (.A1(_0710_),
    .A2(net33),
    .B1(_0711_),
    .Y(_0064_));
 sky130_fd_sc_hd__inv_1 _2282_ (.A(u_uart_master_core_u_host_bridge_sh_q_24_),
    .Y(_0712_));
 sky130_fd_sc_hd__nand2_1 _2283_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_16_),
    .Y(_0713_));
 sky130_fd_sc_hd__o21ai_0 _2284_ (.A1(_0712_),
    .A2(net33),
    .B1(_0713_),
    .Y(_0065_));
 sky130_fd_sc_hd__inv_1 _2285_ (.A(u_uart_master_core_u_host_bridge_sh_q_23_),
    .Y(_0714_));
 sky130_fd_sc_hd__nand2_1 _2286_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_15_),
    .Y(_0715_));
 sky130_fd_sc_hd__o21ai_0 _2287_ (.A1(_0714_),
    .A2(net33),
    .B1(_0715_),
    .Y(_0066_));
 sky130_fd_sc_hd__inv_1 _2288_ (.A(u_uart_master_core_u_host_bridge_sh_q_22_),
    .Y(_0716_));
 sky130_fd_sc_hd__nand2_1 _2289_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_14_),
    .Y(_0717_));
 sky130_fd_sc_hd__o21ai_0 _2290_ (.A1(_0716_),
    .A2(net33),
    .B1(_0717_),
    .Y(_0067_));
 sky130_fd_sc_hd__inv_1 _2291_ (.A(u_uart_master_core_u_host_bridge_sh_q_21_),
    .Y(_0718_));
 sky130_fd_sc_hd__nand2_1 _2292_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_13_),
    .Y(_0719_));
 sky130_fd_sc_hd__o21ai_0 _2293_ (.A1(_0718_),
    .A2(net33),
    .B1(_0719_),
    .Y(_0068_));
 sky130_fd_sc_hd__inv_1 _2294_ (.A(u_uart_master_core_u_host_bridge_sh_q_20_),
    .Y(_0720_));
 sky130_fd_sc_hd__nand2_1 _2295_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_12_),
    .Y(_0721_));
 sky130_fd_sc_hd__o21ai_0 _2296_ (.A1(_0720_),
    .A2(net33),
    .B1(_0721_),
    .Y(_0069_));
 sky130_fd_sc_hd__inv_1 _2297_ (.A(u_uart_master_core_u_host_bridge_sh_q_19_),
    .Y(_0722_));
 sky130_fd_sc_hd__nand2_1 _2298_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_11_),
    .Y(_0723_));
 sky130_fd_sc_hd__o21ai_0 _2299_ (.A1(_0722_),
    .A2(net33),
    .B1(_0723_),
    .Y(_0070_));
 sky130_fd_sc_hd__inv_1 _2300_ (.A(u_uart_master_core_u_host_bridge_sh_q_18_),
    .Y(_0724_));
 sky130_fd_sc_hd__nand2_1 _2301_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_10_),
    .Y(_0725_));
 sky130_fd_sc_hd__o21ai_0 _2302_ (.A1(_0724_),
    .A2(net33),
    .B1(_0725_),
    .Y(_0071_));
 sky130_fd_sc_hd__inv_1 _2303_ (.A(u_uart_master_core_u_host_bridge_sh_q_17_),
    .Y(_0726_));
 sky130_fd_sc_hd__nand2_1 _2304_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_9_),
    .Y(_0727_));
 sky130_fd_sc_hd__o21ai_0 _2305_ (.A1(_0726_),
    .A2(net33),
    .B1(_0727_),
    .Y(_0072_));
 sky130_fd_sc_hd__inv_1 _2306_ (.A(u_uart_master_core_u_host_bridge_sh_q_16_),
    .Y(_0728_));
 sky130_fd_sc_hd__nand2_1 _2307_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_8_),
    .Y(_0729_));
 sky130_fd_sc_hd__o21ai_0 _2308_ (.A1(_0728_),
    .A2(net33),
    .B1(_0729_),
    .Y(_0073_));
 sky130_fd_sc_hd__inv_1 _2309_ (.A(u_uart_master_core_u_host_bridge_sh_q_15_),
    .Y(_0730_));
 sky130_fd_sc_hd__nand2_1 _2310_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_7_),
    .Y(_0731_));
 sky130_fd_sc_hd__o21ai_0 _2311_ (.A1(_0730_),
    .A2(net33),
    .B1(_0731_),
    .Y(_0074_));
 sky130_fd_sc_hd__inv_1 _2312_ (.A(u_uart_master_core_u_host_bridge_sh_q_14_),
    .Y(_0732_));
 sky130_fd_sc_hd__nand2_1 _2313_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_6_),
    .Y(_0733_));
 sky130_fd_sc_hd__o21ai_0 _2314_ (.A1(_0732_),
    .A2(net33),
    .B1(_0733_),
    .Y(_0075_));
 sky130_fd_sc_hd__inv_1 _2315_ (.A(u_uart_master_core_u_host_bridge_sh_q_13_),
    .Y(_0734_));
 sky130_fd_sc_hd__nand2_1 _2316_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_5_),
    .Y(_0735_));
 sky130_fd_sc_hd__o21ai_0 _2317_ (.A1(_0734_),
    .A2(net33),
    .B1(_0735_),
    .Y(_0076_));
 sky130_fd_sc_hd__inv_1 _2318_ (.A(u_uart_master_core_u_host_bridge_sh_q_12_),
    .Y(_0736_));
 sky130_fd_sc_hd__nand2_1 _2319_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_4_),
    .Y(_0737_));
 sky130_fd_sc_hd__o21ai_0 _2320_ (.A1(_0736_),
    .A2(net33),
    .B1(_0737_),
    .Y(_0077_));
 sky130_fd_sc_hd__inv_1 _2321_ (.A(u_uart_master_core_u_host_bridge_sh_q_11_),
    .Y(_0738_));
 sky130_fd_sc_hd__nand2_1 _2322_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_3_),
    .Y(_0739_));
 sky130_fd_sc_hd__o21ai_0 _2323_ (.A1(_0738_),
    .A2(net33),
    .B1(_0739_),
    .Y(_0078_));
 sky130_fd_sc_hd__inv_1 _2324_ (.A(u_uart_master_core_u_host_bridge_sh_q_10_),
    .Y(_0740_));
 sky130_fd_sc_hd__nand2_1 _2325_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_2_),
    .Y(_0741_));
 sky130_fd_sc_hd__o21ai_0 _2326_ (.A1(_0740_),
    .A2(net33),
    .B1(_0741_),
    .Y(_0079_));
 sky130_fd_sc_hd__inv_1 _2327_ (.A(u_uart_master_core_u_host_bridge_sh_q_9_),
    .Y(_0742_));
 sky130_fd_sc_hd__nand2_1 _2328_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_1_),
    .Y(_0743_));
 sky130_fd_sc_hd__o21ai_0 _2329_ (.A1(_0742_),
    .A2(net33),
    .B1(_0743_),
    .Y(_0080_));
 sky130_fd_sc_hd__inv_1 _2330_ (.A(u_uart_master_core_u_host_bridge_sh_q_8_),
    .Y(_0744_));
 sky130_fd_sc_hd__nand2_1 _2331_ (.A(net37),
    .B(u_uart_master_core_u_host_bridge_wdata_o_0_),
    .Y(_0745_));
 sky130_fd_sc_hd__o21ai_0 _2332_ (.A1(_0744_),
    .A2(net33),
    .B1(_0745_),
    .Y(_0081_));
 sky130_fd_sc_hd__a21oi_1 _2333_ (.A1(_0539_),
    .A2(net113),
    .B1(net112),
    .Y(_0746_));
 sky130_fd_sc_hd__nand2_1 _2334_ (.A(_0746_),
    .B(net113),
    .Y(_0747_));
 sky130_fd_sc_hd__inv_1 _2335_ (.A(net114),
    .Y(_0748_));
 sky130_fd_sc_hd__nor2_2 _2336_ (.A(net113),
    .B(_0748_),
    .Y(_0749_));
 sky130_fd_sc_hd__lpflow_clkinvkapwr_1 _2337_ (.A(_0746_),
    .Y(_0750_));
 sky130_fd_sc_hd__nor2_1 _2338_ (.A(_0749_),
    .B(_0750_),
    .Y(_0751_));
 sky130_fd_sc_hd__o22ai_1 _2339_ (.A1(_0573_),
    .A2(net36),
    .B1(_0700_),
    .B2(net32),
    .Y(_0082_));
 sky130_fd_sc_hd__o22ai_1 _2340_ (.A1(_0609_),
    .A2(net36),
    .B1(_0702_),
    .B2(net32),
    .Y(_0083_));
 sky130_fd_sc_hd__o22ai_1 _2341_ (.A1(net50),
    .A2(net36),
    .B1(_0704_),
    .B2(net32),
    .Y(_0084_));
 sky130_fd_sc_hd__o22ai_1 _2342_ (.A1(_0646_),
    .A2(net36),
    .B1(_0706_),
    .B2(net32),
    .Y(_0085_));
 sky130_fd_sc_hd__o22ai_1 _2343_ (.A1(net54),
    .A2(net36),
    .B1(_0708_),
    .B2(net32),
    .Y(_0086_));
 sky130_fd_sc_hd__o22ai_1 _2344_ (.A1(_0680_),
    .A2(net36),
    .B1(_0710_),
    .B2(net32),
    .Y(_0087_));
 sky130_fd_sc_hd__o22ai_1 _2345_ (.A1(_0696_),
    .A2(net36),
    .B1(_0712_),
    .B2(net32),
    .Y(_0088_));
 sky130_fd_sc_hd__o22ai_1 _2346_ (.A1(_0698_),
    .A2(net36),
    .B1(_0714_),
    .B2(net32),
    .Y(_0089_));
 sky130_fd_sc_hd__o22ai_1 _2347_ (.A1(_0700_),
    .A2(net36),
    .B1(_0716_),
    .B2(net32),
    .Y(_0090_));
 sky130_fd_sc_hd__o22ai_1 _2348_ (.A1(_0702_),
    .A2(net36),
    .B1(_0718_),
    .B2(net32),
    .Y(_0091_));
 sky130_fd_sc_hd__o22ai_1 _2349_ (.A1(_0704_),
    .A2(net36),
    .B1(_0720_),
    .B2(net32),
    .Y(_0092_));
 sky130_fd_sc_hd__o22ai_1 _2350_ (.A1(_0706_),
    .A2(net36),
    .B1(_0722_),
    .B2(net32),
    .Y(_0093_));
 sky130_fd_sc_hd__o22ai_1 _2351_ (.A1(_0708_),
    .A2(net36),
    .B1(_0724_),
    .B2(net32),
    .Y(_0094_));
 sky130_fd_sc_hd__o22ai_1 _2352_ (.A1(_0710_),
    .A2(net36),
    .B1(_0726_),
    .B2(net32),
    .Y(_0095_));
 sky130_fd_sc_hd__o22ai_1 _2353_ (.A1(_0712_),
    .A2(net36),
    .B1(_0728_),
    .B2(net32),
    .Y(_0096_));
 sky130_fd_sc_hd__o22ai_1 _2354_ (.A1(_0714_),
    .A2(net36),
    .B1(_0730_),
    .B2(net32),
    .Y(_0097_));
 sky130_fd_sc_hd__o22ai_1 _2355_ (.A1(_0716_),
    .A2(net36),
    .B1(_0732_),
    .B2(net32),
    .Y(_0098_));
 sky130_fd_sc_hd__o22ai_1 _2356_ (.A1(_0718_),
    .A2(net36),
    .B1(_0734_),
    .B2(net32),
    .Y(_0099_));
 sky130_fd_sc_hd__o22ai_1 _2357_ (.A1(_0720_),
    .A2(net36),
    .B1(_0736_),
    .B2(net32),
    .Y(_0100_));
 sky130_fd_sc_hd__o22ai_1 _2358_ (.A1(_0722_),
    .A2(net36),
    .B1(_0738_),
    .B2(net32),
    .Y(_0101_));
 sky130_fd_sc_hd__o22ai_1 _2359_ (.A1(_0724_),
    .A2(net36),
    .B1(_0740_),
    .B2(net32),
    .Y(_0102_));
 sky130_fd_sc_hd__o22ai_1 _2360_ (.A1(_0726_),
    .A2(net36),
    .B1(_0742_),
    .B2(net32),
    .Y(_0103_));
 sky130_fd_sc_hd__o22ai_1 _2361_ (.A1(_0728_),
    .A2(net36),
    .B1(_0744_),
    .B2(net32),
    .Y(_0104_));
 sky130_fd_sc_hd__nor2_1 _2362_ (.A(_0579_),
    .B(_0585_),
    .Y(_0752_));
 sky130_fd_sc_hd__nor3_1 _2363_ (.A(_0749_),
    .B(_0752_),
    .C(_0587_),
    .Y(_0753_));
 sky130_fd_sc_hd__nor2_1 _2364_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_47_),
    .B(_0556_),
    .Y(_0754_));
 sky130_fd_sc_hd__o21ai_0 _2365_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_39_),
    .A2(net64),
    .B1(net109),
    .Y(_0755_));
 sky130_fd_sc_hd__o22ai_1 _2366_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_55_),
    .A2(net63),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_63_),
    .B2(net62),
    .Y(_0756_));
 sky130_fd_sc_hd__nor3_1 _2367_ (.A(_0754_),
    .B(_0755_),
    .C(_0756_),
    .Y(_0757_));
 sky130_fd_sc_hd__nor2_1 _2368_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_23_),
    .B(net63),
    .Y(_0758_));
 sky130_fd_sc_hd__o22ai_1 _2369_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_7_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_15_),
    .B2(_0556_),
    .Y(_0759_));
 sky130_fd_sc_hd__o21ai_0 _2370_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_31_),
    .A2(net62),
    .B1(_0522_),
    .Y(_0760_));
 sky130_fd_sc_hd__nor3_1 _2371_ (.A(_0758_),
    .B(_0759_),
    .C(_0760_),
    .Y(_0761_));
 sky130_fd_sc_hd__o22ai_1 _2372_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_71_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_79_),
    .B2(_0556_),
    .Y(_0762_));
 sky130_fd_sc_hd__o221ai_1 _2373_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_87_),
    .A2(net63),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_95_),
    .B2(net62),
    .C1(_0522_),
    .Y(_0763_));
 sky130_fd_sc_hd__nor2_1 _2374_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_119_),
    .B(net63),
    .Y(_0764_));
 sky130_fd_sc_hd__o22ai_1 _2375_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_103_),
    .A2(net64),
    .B1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_111_),
    .B2(_0556_),
    .Y(_0765_));
 sky130_fd_sc_hd__o21ai_0 _2376_ (.A1(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_127_),
    .A2(net62),
    .B1(net109),
    .Y(_0766_));
 sky130_fd_sc_hd__nor3_1 _2377_ (.A(_0764_),
    .B(_0765_),
    .C(_0766_),
    .Y(_0767_));
 sky130_fd_sc_hd__nor2_1 _2378_ (.A(_1361_),
    .B(_0767_),
    .Y(_0768_));
 sky130_fd_sc_hd__o21ai_0 _2379_ (.A1(_0762_),
    .A2(_0763_),
    .B1(_0768_),
    .Y(_0769_));
 sky130_fd_sc_hd__o311ai_2 _2380_ (.A1(net108),
    .A2(_0757_),
    .A3(_0761_),
    .B1(_0536_),
    .C1(_0769_),
    .Y(_0770_));
 sky130_fd_sc_hd__nor2_1 _2381_ (.A(_0696_),
    .B(_0770_),
    .Y(_0771_));
 sky130_fd_sc_hd__nand2_1 _2382_ (.A(_0619_),
    .B(_0625_),
    .Y(_0772_));
 sky130_fd_sc_hd__nand3_1 _2383_ (.A(_0771_),
    .B(_0772_),
    .C(_0644_),
    .Y(_0773_));
 sky130_fd_sc_hd__nor3_1 _2384_ (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_under_rst),
    .B(_0572_),
    .C(net54),
    .Y(_0774_));
 sky130_fd_sc_hd__nand3_1 _2385_ (.A(_0774_),
    .B(_0608_),
    .C(_0678_),
    .Y(_0775_));
 sky130_fd_sc_hd__o221ai_1 _2386_ (.A1(_0539_),
    .A2(_0531_),
    .B1(_0773_),
    .B2(_0775_),
    .C1(_0501_),
    .Y(_0776_));
 sky130_fd_sc_hd__nor2_1 _2387_ (.A(net113),
    .B(_0574_),
    .Y(_0777_));
 sky130_fd_sc_hd__o21ai_1 _2388_ (.A1(u_uart_master_core_u_host_bridge_idx_q_0_),
    .A2(_0578_),
    .B1(_0777_),
    .Y(_0778_));
 sky130_fd_sc_hd__nand2_1 _2389_ (.A(req_o),
    .B(gnt_i),
    .Y(_0779_));
 sky130_fd_sc_hd__nand3_1 _2390_ (.A(_0749_),
    .B(net112),
    .C(_0779_),
    .Y(_0780_));
 sky130_fd_sc_hd__o31a_1 _2391_ (.A1(_0501_),
    .A2(valid_i),
    .A3(_0505_),
    .B1(_0780_),
    .X(_0781_));
 sky130_fd_sc_hd__nand3_1 _2392_ (.A(_0776_),
    .B(_0778_),
    .C(_0781_),
    .Y(_0782_));
 sky130_fd_sc_hd__nand2_1 _2393_ (.A(_0782_),
    .B(net113),
    .Y(_0783_));
 sky130_fd_sc_hd__o21ai_0 _2394_ (.A1(_0753_),
    .A2(_0782_),
    .B1(_0783_),
    .Y(_0105_));
 sky130_fd_sc_hd__nand2_1 _2395_ (.A(_0781_),
    .B(_0778_),
    .Y(_0784_));
 sky130_fd_sc_hd__nor2_1 _2396_ (.A(_0504_),
    .B(_0749_),
    .Y(_0785_));
 sky130_fd_sc_hd__a21oi_1 _2397_ (.A1(_0534_),
    .A2(_0785_),
    .B1(_0776_),
    .Y(_0786_));
 sky130_fd_sc_hd__a2111oi_0 _2398_ (.A1(_0539_),
    .A2(_0575_),
    .B1(_0752_),
    .C1(_0784_),
    .D1(_0786_),
    .Y(_0787_));
 sky130_fd_sc_hd__a21oi_1 _2399_ (.A1(_0574_),
    .A2(_0785_),
    .B1(_0587_),
    .Y(_0788_));
 sky130_fd_sc_hd__nor2_1 _2400_ (.A(net114),
    .B(_0787_),
    .Y(_0789_));
 sky130_fd_sc_hd__a21oi_1 _2401_ (.A1(_0787_),
    .A2(_0788_),
    .B1(_0789_),
    .Y(_0106_));
 sky130_fd_sc_hd__clkinv_1 _2402_ (.A(net130),
    .Y(_0790_));
 sky130_fd_sc_hd__nand2_1 _2403_ (.A(net131),
    .B(net117),
    .Y(_0791_));
 sky130_fd_sc_hd__o21ai_2 _2404_ (.A1(net117),
    .A2(_0790_),
    .B1(_0791_),
    .Y(u_uart_master_core_u_uart_core_rx_fifo_data_1_));
 sky130_fd_sc_hd__nand2_1 _2405_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_30_),
    .Y(_0792_));
 sky130_fd_sc_hd__lpflow_clkbufkapwr_1 _2406_ (.A(_0506_),
    .X(_0793_));
 sky130_fd_sc_hd__nand2_1 _2407_ (.A(net58),
    .B(rdata_i[30]),
    .Y(_0794_));
 sky130_fd_sc_hd__nand2_1 _2408_ (.A(_0792_),
    .B(_0794_),
    .Y(_0107_));
 sky130_fd_sc_hd__nand2_1 _2409_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_29_),
    .Y(_0795_));
 sky130_fd_sc_hd__nand2_1 _2410_ (.A(net58),
    .B(rdata_i[29]),
    .Y(_0796_));
 sky130_fd_sc_hd__nand2_1 _2411_ (.A(_0795_),
    .B(_0796_),
    .Y(_0108_));
 sky130_fd_sc_hd__nand2_1 _2412_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_28_),
    .Y(_0797_));
 sky130_fd_sc_hd__nand2_1 _2413_ (.A(net58),
    .B(rdata_i[28]),
    .Y(_0798_));
 sky130_fd_sc_hd__nand2_1 _2414_ (.A(_0797_),
    .B(_0798_),
    .Y(_0109_));
 sky130_fd_sc_hd__nand2_1 _2415_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_27_),
    .Y(_0799_));
 sky130_fd_sc_hd__nand2_1 _2416_ (.A(net58),
    .B(rdata_i[27]),
    .Y(_0800_));
 sky130_fd_sc_hd__nand2_1 _2417_ (.A(_0799_),
    .B(_0800_),
    .Y(_0110_));
 sky130_fd_sc_hd__nand2_1 _2418_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_26_),
    .Y(_0801_));
 sky130_fd_sc_hd__nand2_1 _2419_ (.A(net58),
    .B(rdata_i[26]),
    .Y(_0802_));
 sky130_fd_sc_hd__nand2_1 _2420_ (.A(_0801_),
    .B(_0802_),
    .Y(_0111_));
 sky130_fd_sc_hd__nand2_1 _2421_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_25_),
    .Y(_0803_));
 sky130_fd_sc_hd__nand2_1 _2422_ (.A(net58),
    .B(rdata_i[25]),
    .Y(_0804_));
 sky130_fd_sc_hd__nand2_1 _2423_ (.A(_0803_),
    .B(_0804_),
    .Y(_0112_));
 sky130_fd_sc_hd__nand2_1 _2424_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_24_),
    .Y(_0805_));
 sky130_fd_sc_hd__nand2_1 _2425_ (.A(net58),
    .B(rdata_i[24]),
    .Y(_0806_));
 sky130_fd_sc_hd__nand2_1 _2426_ (.A(_0805_),
    .B(_0806_),
    .Y(_0113_));
 sky130_fd_sc_hd__inv_1 _2427_ (.A(u_uart_master_core_u_host_bridge_rdata_q_23_),
    .Y(_0807_));
 sky130_fd_sc_hd__nand2_1 _2428_ (.A(net58),
    .B(rdata_i[23]),
    .Y(_0808_));
 sky130_fd_sc_hd__o21ai_0 _2429_ (.A1(_0807_),
    .A2(_0506_),
    .B1(_0808_),
    .Y(_0114_));
 sky130_fd_sc_hd__nand2_1 _2430_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_22_),
    .Y(_0809_));
 sky130_fd_sc_hd__nand2_1 _2431_ (.A(net58),
    .B(rdata_i[22]),
    .Y(_0810_));
 sky130_fd_sc_hd__nand2_1 _2432_ (.A(_0809_),
    .B(_0810_),
    .Y(_0115_));
 sky130_fd_sc_hd__nand2_1 _2433_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_21_),
    .Y(_0811_));
 sky130_fd_sc_hd__nand2_1 _2434_ (.A(net58),
    .B(rdata_i[21]),
    .Y(_0812_));
 sky130_fd_sc_hd__nand2_1 _2435_ (.A(_0811_),
    .B(_0812_),
    .Y(_0116_));
 sky130_fd_sc_hd__nand2_1 _2436_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_20_),
    .Y(_0813_));
 sky130_fd_sc_hd__nand2_1 _2437_ (.A(net58),
    .B(rdata_i[20]),
    .Y(_0814_));
 sky130_fd_sc_hd__nand2_1 _2438_ (.A(_0813_),
    .B(_0814_),
    .Y(_0117_));
 sky130_fd_sc_hd__nand2_1 _2439_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_19_),
    .Y(_0815_));
 sky130_fd_sc_hd__nand2_1 _2440_ (.A(net58),
    .B(rdata_i[19]),
    .Y(_0816_));
 sky130_fd_sc_hd__nand2_1 _2441_ (.A(_0815_),
    .B(_0816_),
    .Y(_0118_));
 sky130_fd_sc_hd__nand2_1 _2442_ (.A(net58),
    .B(rdata_i[18]),
    .Y(_0817_));
 sky130_fd_sc_hd__o21ai_0 _2443_ (.A1(_0477_),
    .A2(_0506_),
    .B1(_0817_),
    .Y(_0119_));
 sky130_fd_sc_hd__nand2_1 _2444_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_17_),
    .Y(_0818_));
 sky130_fd_sc_hd__nand2_1 _2445_ (.A(net58),
    .B(rdata_i[17]),
    .Y(_0819_));
 sky130_fd_sc_hd__nand2_1 _2446_ (.A(_0818_),
    .B(_0819_),
    .Y(_0120_));
 sky130_fd_sc_hd__nand2_1 _2447_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_16_),
    .Y(_0820_));
 sky130_fd_sc_hd__nand2_1 _2448_ (.A(net58),
    .B(rdata_i[16]),
    .Y(_0821_));
 sky130_fd_sc_hd__nand2_1 _2449_ (.A(_0820_),
    .B(_0821_),
    .Y(_0121_));
 sky130_fd_sc_hd__inv_1 _2450_ (.A(u_uart_master_core_u_host_bridge_rdata_q_15_),
    .Y(_0822_));
 sky130_fd_sc_hd__nand2_1 _2451_ (.A(net58),
    .B(rdata_i[15]),
    .Y(_0823_));
 sky130_fd_sc_hd__o21ai_0 _2452_ (.A1(_0822_),
    .A2(_0506_),
    .B1(_0823_),
    .Y(_0122_));
 sky130_fd_sc_hd__nand2_1 _2453_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_14_),
    .Y(_0824_));
 sky130_fd_sc_hd__nand2_1 _2454_ (.A(net58),
    .B(rdata_i[14]),
    .Y(_0825_));
 sky130_fd_sc_hd__nand2_1 _2455_ (.A(_0824_),
    .B(_0825_),
    .Y(_0123_));
 sky130_fd_sc_hd__nand2_1 _2456_ (.A(net58),
    .B(rdata_i[13]),
    .Y(_0826_));
 sky130_fd_sc_hd__o21ai_0 _2457_ (.A1(_0465_),
    .A2(_0506_),
    .B1(_0826_),
    .Y(_0124_));
 sky130_fd_sc_hd__nand2_1 _2458_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_12_),
    .Y(_0827_));
 sky130_fd_sc_hd__nand2_1 _2459_ (.A(net58),
    .B(rdata_i[12]),
    .Y(_0828_));
 sky130_fd_sc_hd__nand2_1 _2460_ (.A(_0827_),
    .B(_0828_),
    .Y(_0125_));
 sky130_fd_sc_hd__nand2_1 _2461_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_11_),
    .Y(_0829_));
 sky130_fd_sc_hd__nand2_1 _2462_ (.A(net58),
    .B(rdata_i[11]),
    .Y(_0830_));
 sky130_fd_sc_hd__nand2_1 _2463_ (.A(_0829_),
    .B(_0830_),
    .Y(_0126_));
 sky130_fd_sc_hd__nand2_1 _2464_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_10_),
    .Y(_0831_));
 sky130_fd_sc_hd__nand2_1 _2465_ (.A(net58),
    .B(rdata_i[10]),
    .Y(_0832_));
 sky130_fd_sc_hd__nand2_1 _2466_ (.A(_0831_),
    .B(_0832_),
    .Y(_0127_));
 sky130_fd_sc_hd__nand2_1 _2467_ (.A(net58),
    .B(rdata_i[9]),
    .Y(_0833_));
 sky130_fd_sc_hd__o21ai_0 _2468_ (.A1(_0481_),
    .A2(_0506_),
    .B1(_0833_),
    .Y(_0128_));
 sky130_fd_sc_hd__nand2_1 _2469_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_8_),
    .Y(_0834_));
 sky130_fd_sc_hd__nand2_1 _2470_ (.A(net58),
    .B(rdata_i[8]),
    .Y(_0835_));
 sky130_fd_sc_hd__nand2_1 _2471_ (.A(_0834_),
    .B(_0835_),
    .Y(_0129_));
 sky130_fd_sc_hd__inv_1 _2472_ (.A(u_uart_master_core_u_host_bridge_rdata_q_7_),
    .Y(_0836_));
 sky130_fd_sc_hd__nand2_1 _2473_ (.A(_0506_),
    .B(rdata_i[7]),
    .Y(_0837_));
 sky130_fd_sc_hd__o21ai_0 _2474_ (.A1(_0836_),
    .A2(_0506_),
    .B1(_0837_),
    .Y(_0130_));
 sky130_fd_sc_hd__nand2_1 _2475_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_6_),
    .Y(_0838_));
 sky130_fd_sc_hd__nand2_1 _2476_ (.A(net58),
    .B(rdata_i[6]),
    .Y(_0839_));
 sky130_fd_sc_hd__nand2_1 _2477_ (.A(_0838_),
    .B(_0839_),
    .Y(_0131_));
 sky130_fd_sc_hd__nand2_1 _2478_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_5_),
    .Y(_0840_));
 sky130_fd_sc_hd__nand2_1 _2479_ (.A(net58),
    .B(rdata_i[5]),
    .Y(_0841_));
 sky130_fd_sc_hd__nand2_1 _2480_ (.A(_0840_),
    .B(_0841_),
    .Y(_0132_));
 sky130_fd_sc_hd__nand2_1 _2481_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_4_),
    .Y(_0842_));
 sky130_fd_sc_hd__nand2_1 _2482_ (.A(net58),
    .B(rdata_i[4]),
    .Y(_0843_));
 sky130_fd_sc_hd__nand2_1 _2483_ (.A(_0842_),
    .B(_0843_),
    .Y(_0133_));
 sky130_fd_sc_hd__nand2_1 _2484_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_3_),
    .Y(_0844_));
 sky130_fd_sc_hd__nand2_1 _2485_ (.A(net58),
    .B(rdata_i[3]),
    .Y(_0845_));
 sky130_fd_sc_hd__nand2_1 _2486_ (.A(_0844_),
    .B(_0845_),
    .Y(_0134_));
 sky130_fd_sc_hd__nand2_1 _2487_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_2_),
    .Y(_0846_));
 sky130_fd_sc_hd__nand2_1 _2488_ (.A(net58),
    .B(rdata_i[2]),
    .Y(_0847_));
 sky130_fd_sc_hd__nand2_1 _2489_ (.A(_0846_),
    .B(_0847_),
    .Y(_0135_));
 sky130_fd_sc_hd__nand2_1 _2490_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_1_),
    .Y(_0848_));
 sky130_fd_sc_hd__nand2_1 _2491_ (.A(net58),
    .B(rdata_i[1]),
    .Y(_0849_));
 sky130_fd_sc_hd__nand2_1 _2492_ (.A(_0848_),
    .B(_0849_),
    .Y(_0136_));
 sky130_fd_sc_hd__nand2_1 _2493_ (.A(_0507_),
    .B(u_uart_master_core_u_host_bridge_rdata_q_0_),
    .Y(_0850_));
 sky130_fd_sc_hd__nand2_1 _2494_ (.A(net58),
    .B(rdata_i[0]),
    .Y(_0851_));
 sky130_fd_sc_hd__nand2_1 _2495_ (.A(_0850_),
    .B(_0851_),
    .Y(_0137_));
 sky130_fd_sc_hd__nor2_1 _2496_ (.A(u_uart_master_core_u_host_bridge_idx_q_1_),
    .B(_0577_),
    .Y(_0852_));
 sky130_fd_sc_hd__nand3_1 _2497_ (.A(_0538_),
    .B(_0777_),
    .C(_0852_),
    .Y(_0853_));
 sky130_fd_sc_hd__nand2_1 _2498_ (.A(net49),
    .B(u_uart_master_core_u_host_bridge_op_q_6_),
    .Y(_0854_));
 sky130_fd_sc_hd__o21ai_0 _2499_ (.A1(_0573_),
    .A2(net49),
    .B1(_0854_),
    .Y(_0138_));
 sky130_fd_sc_hd__nand2_1 _2500_ (.A(net49),
    .B(u_uart_master_core_u_host_bridge_op_q_5_),
    .Y(_0855_));
 sky130_fd_sc_hd__o21ai_0 _2501_ (.A1(net49),
    .A2(_0609_),
    .B1(_0855_),
    .Y(_0139_));
 sky130_fd_sc_hd__nand2_1 _2502_ (.A(net49),
    .B(u_uart_master_core_u_host_bridge_op_q_4_),
    .Y(_0856_));
 sky130_fd_sc_hd__o21ai_0 _2503_ (.A1(net50),
    .A2(net49),
    .B1(_0856_),
    .Y(_0140_));
 sky130_fd_sc_hd__nand2_1 _2504_ (.A(net49),
    .B(u_uart_master_core_u_host_bridge_op_q_3_),
    .Y(_0857_));
 sky130_fd_sc_hd__o21ai_0 _2505_ (.A1(net49),
    .A2(_0646_),
    .B1(_0857_),
    .Y(_0141_));
 sky130_fd_sc_hd__nand2_1 _2506_ (.A(net49),
    .B(u_uart_master_core_u_host_bridge_op_q_2_),
    .Y(_0858_));
 sky130_fd_sc_hd__o21ai_0 _2507_ (.A1(net54),
    .A2(net49),
    .B1(_0858_),
    .Y(_0142_));
 sky130_fd_sc_hd__nand2_1 _2508_ (.A(net49),
    .B(u_uart_master_core_u_host_bridge_op_q_1_),
    .Y(_0859_));
 sky130_fd_sc_hd__o21ai_0 _2509_ (.A1(net49),
    .A2(_0680_),
    .B1(_0859_),
    .Y(_0143_));
 sky130_fd_sc_hd__nand2_1 _2510_ (.A(net49),
    .B(u_uart_master_core_u_host_bridge_op_q_0_),
    .Y(_0860_));
 sky130_fd_sc_hd__o21ai_0 _2511_ (.A1(_0696_),
    .A2(net49),
    .B1(_0860_),
    .Y(_0144_));
 sky130_fd_sc_hd__nand2_1 _2512_ (.A(_0588_),
    .B(_0579_),
    .Y(_0861_));
 sky130_fd_sc_hd__o211ai_1 _2513_ (.A1(_0531_),
    .A2(_0538_),
    .B1(_0501_),
    .C1(_0861_),
    .Y(_0862_));
 sky130_fd_sc_hd__inv_1 _2514_ (.A(_0862_),
    .Y(_0863_));
 sky130_fd_sc_hd__a21oi_1 _2515_ (.A1(_0585_),
    .A2(_0778_),
    .B1(_0862_),
    .Y(_0864_));
 sky130_fd_sc_hd__nand2_1 _2516_ (.A(_0864_),
    .B(_0577_),
    .Y(_0865_));
 sky130_fd_sc_hd__o21ai_0 _2517_ (.A1(_0577_),
    .A2(_0863_),
    .B1(_0865_),
    .Y(_0145_));
 sky130_fd_sc_hd__nor2_1 _2518_ (.A(u_uart_master_core_u_host_bridge_idx_q_0_),
    .B(_0578_),
    .Y(_0866_));
 sky130_fd_sc_hd__nand3_1 _2519_ (.A(_0538_),
    .B(_0777_),
    .C(_0866_),
    .Y(_0867_));
 sky130_fd_sc_hd__nand2_1 _2520_ (.A(net48),
    .B(u_uart_master_core_u_host_bridge_bebyte_q_2_),
    .Y(_0868_));
 sky130_fd_sc_hd__o21ai_0 _2521_ (.A1(net54),
    .A2(net48),
    .B1(_0868_),
    .Y(_0146_));
 sky130_fd_sc_hd__nand2_1 _2522_ (.A(net48),
    .B(u_uart_master_core_u_host_bridge_bebyte_q_1_),
    .Y(_0869_));
 sky130_fd_sc_hd__o21ai_0 _2523_ (.A1(net48),
    .A2(_0680_),
    .B1(_0869_),
    .Y(_0147_));
 sky130_fd_sc_hd__nand2_1 _2524_ (.A(net48),
    .B(u_uart_master_core_u_host_bridge_bebyte_q_0_),
    .Y(_0870_));
 sky130_fd_sc_hd__o21ai_0 _2525_ (.A1(_0696_),
    .A2(net48),
    .B1(_0870_),
    .Y(_0148_));
 sky130_fd_sc_hd__o22a_1 _2526_ (.A1(u_uart_master_core_be_o_2_),
    .A2(_0590_),
    .B1(u_uart_master_core_u_host_bridge_bebyte_q_2_),
    .B2(net33),
    .X(_0149_));
 sky130_fd_sc_hd__nor2_1 _2527_ (.A(u_uart_master_core_be_o_1_),
    .B(_0590_),
    .Y(_0871_));
 sky130_fd_sc_hd__nor2_1 _2528_ (.A(u_uart_master_core_u_host_bridge_bebyte_q_1_),
    .B(net33),
    .Y(_0872_));
 sky130_fd_sc_hd__nor2_1 _2529_ (.A(_0871_),
    .B(_0872_),
    .Y(_0150_));
 sky130_fd_sc_hd__o22a_1 _2530_ (.A1(u_uart_master_core_be_o_0_),
    .A2(_0590_),
    .B1(u_uart_master_core_u_host_bridge_bebyte_q_0_),
    .B2(net33),
    .X(_0151_));
 sky130_fd_sc_hd__nand3_1 _2531_ (.A(_0538_),
    .B(_0579_),
    .C(_0584_),
    .Y(_0873_));
 sky130_fd_sc_hd__lpflow_clkbufkapwr_1 _2532_ (.A(_0873_),
    .X(_0874_));
 sky130_fd_sc_hd__buf_2 _2533_ (.A(_0873_),
    .X(_0875_));
 sky130_fd_sc_hd__nand2_1 _2534_ (.A(net38),
    .B(u_uart_master_core_addr_o_30_),
    .Y(_0876_));
 sky130_fd_sc_hd__o21ai_0 _2535_ (.A1(_0573_),
    .A2(net39),
    .B1(_0876_),
    .Y(_0152_));
 sky130_fd_sc_hd__nand2_1 _2536_ (.A(net38),
    .B(u_uart_master_core_addr_o_29_),
    .Y(_0877_));
 sky130_fd_sc_hd__o21ai_0 _2537_ (.A1(net39),
    .A2(_0609_),
    .B1(_0877_),
    .Y(_0153_));
 sky130_fd_sc_hd__nand2_1 _2538_ (.A(net38),
    .B(u_uart_master_core_addr_o_28_),
    .Y(_0878_));
 sky130_fd_sc_hd__o21ai_0 _2539_ (.A1(net50),
    .A2(net39),
    .B1(_0878_),
    .Y(_0154_));
 sky130_fd_sc_hd__nand2_1 _2540_ (.A(net38),
    .B(u_uart_master_core_addr_o_27_),
    .Y(_0879_));
 sky130_fd_sc_hd__o21ai_0 _2541_ (.A1(net39),
    .A2(_0646_),
    .B1(_0879_),
    .Y(_0155_));
 sky130_fd_sc_hd__nand2_1 _2542_ (.A(net38),
    .B(u_uart_master_core_addr_o_26_),
    .Y(_0880_));
 sky130_fd_sc_hd__o21ai_0 _2543_ (.A1(net54),
    .A2(net39),
    .B1(_0880_),
    .Y(_0156_));
 sky130_fd_sc_hd__nand2_1 _2544_ (.A(net38),
    .B(u_uart_master_core_addr_o_25_),
    .Y(_0881_));
 sky130_fd_sc_hd__o21ai_0 _2545_ (.A1(net39),
    .A2(_0680_),
    .B1(_0881_),
    .Y(_0157_));
 sky130_fd_sc_hd__nand2_1 _2546_ (.A(net38),
    .B(u_uart_master_core_addr_o_24_),
    .Y(_0882_));
 sky130_fd_sc_hd__o21ai_0 _2547_ (.A1(_0696_),
    .A2(net39),
    .B1(_0882_),
    .Y(_0158_));
 sky130_fd_sc_hd__nand2_1 _2548_ (.A(net38),
    .B(u_uart_master_core_addr_o_23_),
    .Y(_0883_));
 sky130_fd_sc_hd__o21ai_0 _2549_ (.A1(_0698_),
    .A2(net39),
    .B1(_0883_),
    .Y(_0159_));
 sky130_fd_sc_hd__nand2_1 _2550_ (.A(net38),
    .B(u_uart_master_core_addr_o_22_),
    .Y(_0884_));
 sky130_fd_sc_hd__o21ai_0 _2551_ (.A1(_0700_),
    .A2(net39),
    .B1(_0884_),
    .Y(_0160_));
 sky130_fd_sc_hd__nand2_1 _2552_ (.A(net38),
    .B(u_uart_master_core_addr_o_21_),
    .Y(_0885_));
 sky130_fd_sc_hd__o21ai_0 _2553_ (.A1(_0702_),
    .A2(net39),
    .B1(_0885_),
    .Y(_0161_));
 sky130_fd_sc_hd__nand2_1 _2554_ (.A(net38),
    .B(u_uart_master_core_addr_o_20_),
    .Y(_0886_));
 sky130_fd_sc_hd__o21ai_0 _2555_ (.A1(_0704_),
    .A2(net39),
    .B1(_0886_),
    .Y(_0162_));
 sky130_fd_sc_hd__nand2_1 _2556_ (.A(net38),
    .B(u_uart_master_core_addr_o_19_),
    .Y(_0887_));
 sky130_fd_sc_hd__o21ai_0 _2557_ (.A1(_0706_),
    .A2(net39),
    .B1(_0887_),
    .Y(_0163_));
 sky130_fd_sc_hd__nand2_1 _2558_ (.A(net38),
    .B(u_uart_master_core_addr_o_18_),
    .Y(_0888_));
 sky130_fd_sc_hd__o21ai_0 _2559_ (.A1(_0708_),
    .A2(net39),
    .B1(_0888_),
    .Y(_0164_));
 sky130_fd_sc_hd__nand2_1 _2560_ (.A(net38),
    .B(u_uart_master_core_addr_o_17_),
    .Y(_0889_));
 sky130_fd_sc_hd__o21ai_0 _2561_ (.A1(_0710_),
    .A2(net39),
    .B1(_0889_),
    .Y(_0165_));
 sky130_fd_sc_hd__nand2_1 _2562_ (.A(net38),
    .B(u_uart_master_core_addr_o_16_),
    .Y(_0890_));
 sky130_fd_sc_hd__o21ai_0 _2563_ (.A1(_0712_),
    .A2(net39),
    .B1(_0890_),
    .Y(_0166_));
 sky130_fd_sc_hd__nand2_1 _2564_ (.A(net38),
    .B(u_uart_master_core_addr_o_15_),
    .Y(_0891_));
 sky130_fd_sc_hd__o21ai_0 _2565_ (.A1(_0714_),
    .A2(net39),
    .B1(_0891_),
    .Y(_0167_));
 sky130_fd_sc_hd__nand2_1 _2566_ (.A(net38),
    .B(u_uart_master_core_addr_o_14_),
    .Y(_0892_));
 sky130_fd_sc_hd__o21ai_0 _2567_ (.A1(_0716_),
    .A2(net39),
    .B1(_0892_),
    .Y(_0168_));
 sky130_fd_sc_hd__nand2_1 _2568_ (.A(net38),
    .B(u_uart_master_core_addr_o_13_),
    .Y(_0893_));
 sky130_fd_sc_hd__o21ai_0 _2569_ (.A1(_0718_),
    .A2(net39),
    .B1(_0893_),
    .Y(_0169_));
 sky130_fd_sc_hd__nand2_1 _2570_ (.A(net38),
    .B(u_uart_master_core_addr_o_12_),
    .Y(_0894_));
 sky130_fd_sc_hd__o21ai_0 _2571_ (.A1(_0720_),
    .A2(net39),
    .B1(_0894_),
    .Y(_0170_));
 sky130_fd_sc_hd__nand2_1 _2572_ (.A(net38),
    .B(u_uart_master_core_addr_o_11_),
    .Y(_0895_));
 sky130_fd_sc_hd__o21ai_0 _2573_ (.A1(_0722_),
    .A2(net39),
    .B1(_0895_),
    .Y(_0171_));
 sky130_fd_sc_hd__nand2_1 _2574_ (.A(net38),
    .B(u_uart_master_core_addr_o_10_),
    .Y(_0896_));
 sky130_fd_sc_hd__o21ai_0 _2575_ (.A1(_0724_),
    .A2(net39),
    .B1(_0896_),
    .Y(_0172_));
 sky130_fd_sc_hd__nand2_1 _2576_ (.A(net38),
    .B(u_uart_master_core_addr_o_9_),
    .Y(_0897_));
 sky130_fd_sc_hd__o21ai_0 _2577_ (.A1(_0726_),
    .A2(net39),
    .B1(_0897_),
    .Y(_0173_));
 sky130_fd_sc_hd__nand2_1 _2578_ (.A(net38),
    .B(u_uart_master_core_addr_o_8_),
    .Y(_0898_));
 sky130_fd_sc_hd__o21ai_0 _2579_ (.A1(_0728_),
    .A2(net39),
    .B1(_0898_),
    .Y(_0174_));
 sky130_fd_sc_hd__nand2_1 _2580_ (.A(net38),
    .B(u_uart_master_core_addr_o_7_),
    .Y(_0899_));
 sky130_fd_sc_hd__o21ai_0 _2581_ (.A1(_0730_),
    .A2(net39),
    .B1(_0899_),
    .Y(_0175_));
 sky130_fd_sc_hd__nand2_1 _2582_ (.A(net38),
    .B(u_uart_master_core_addr_o_6_),
    .Y(_0900_));
 sky130_fd_sc_hd__o21ai_0 _2583_ (.A1(_0732_),
    .A2(net39),
    .B1(_0900_),
    .Y(_0176_));
 sky130_fd_sc_hd__nand2_1 _2584_ (.A(net38),
    .B(u_uart_master_core_addr_o_5_),
    .Y(_0901_));
 sky130_fd_sc_hd__o21ai_0 _2585_ (.A1(_0734_),
    .A2(net39),
    .B1(_0901_),
    .Y(_0177_));
 sky130_fd_sc_hd__nand2_1 _2586_ (.A(net38),
    .B(u_uart_master_core_addr_o_4_),
    .Y(_0902_));
 sky130_fd_sc_hd__o21ai_0 _2587_ (.A1(_0736_),
    .A2(net39),
    .B1(_0902_),
    .Y(_0178_));
 sky130_fd_sc_hd__nand2_1 _2588_ (.A(net38),
    .B(u_uart_master_core_addr_o_3_),
    .Y(_0903_));
 sky130_fd_sc_hd__o21ai_0 _2589_ (.A1(_0738_),
    .A2(net39),
    .B1(_0903_),
    .Y(_0179_));
 sky130_fd_sc_hd__nand2_1 _2590_ (.A(net38),
    .B(u_uart_master_core_addr_o_2_),
    .Y(_0904_));
 sky130_fd_sc_hd__o21ai_0 _2591_ (.A1(_0740_),
    .A2(net39),
    .B1(_0904_),
    .Y(_0180_));
 sky130_fd_sc_hd__clkinv_1 _2592_ (.A(tl_i[64]),
    .Y(_0905_));
 sky130_fd_sc_hd__nand3_1 _2593_ (.A(_0905_),
    .B(tl_i[62]),
    .C(tl_i[63]),
    .Y(_0906_));
 sky130_fd_sc_hd__nor2_1 _2594_ (.A(tl_i[62]),
    .B(tl_i[63]),
    .Y(_0907_));
 sky130_fd_sc_hd__nor2_1 _2595_ (.A(_0905_),
    .B(_0907_),
    .Y(_0908_));
 sky130_fd_sc_hd__inv_1 _2596_ (.A(_0907_),
    .Y(_0909_));
 sky130_fd_sc_hd__nor2_1 _2597_ (.A(tl_i[64]),
    .B(_0909_),
    .Y(_0910_));
 sky130_fd_sc_hd__clkinv_1 _2598_ (.A(net66),
    .Y(_0911_));
 sky130_fd_sc_hd__o22ai_1 _2599_ (.A1(tl_i[56]),
    .A2(_0908_),
    .B1(tl_i[59]),
    .B2(_0911_),
    .Y(_0912_));
 sky130_fd_sc_hd__inv_1 _2600_ (.A(tl_i[62]),
    .Y(_0913_));
 sky130_fd_sc_hd__nor3_1 _2601_ (.A(tl_i[63]),
    .B(_0905_),
    .C(_0913_),
    .Y(_0914_));
 sky130_fd_sc_hd__inv_2 _2602_ (.A(_0914_),
    .Y(_0915_));
 sky130_fd_sc_hd__a32oi_1 _2603_ (.A1(tl_i[58]),
    .A2(tl_i[57]),
    .A3(tl_i[56]),
    .B1(_0911_),
    .B2(_0915_),
    .Y(_0916_));
 sky130_fd_sc_hd__or2_0 _2604_ (.A(tl_i[60]),
    .B(tl_i[61]),
    .X(_0917_));
 sky130_fd_sc_hd__nor3_1 _2605_ (.A(tl_i[107]),
    .B(tl_i[106]),
    .C(net68),
    .Y(_0918_));
 sky130_fd_sc_hd__inv_1 _2606_ (.A(_0918_),
    .Y(_0919_));
 sky130_fd_sc_hd__nor2_1 _2607_ (.A(_0917_),
    .B(_0919_),
    .Y(_0920_));
 sky130_fd_sc_hd__o21ai_1 _2608_ (.A1(_0912_),
    .A2(_0916_),
    .B1(_0920_),
    .Y(_0921_));
 sky130_fd_sc_hd__nand2_1 _2609_ (.A(tl_i[64]),
    .B(tl_i[63]),
    .Y(_0922_));
 sky130_fd_sc_hd__nand3_1 _2610_ (.A(_0921_),
    .B(_0920_),
    .C(_0922_),
    .Y(_0923_));
 sky130_fd_sc_hd__nor2_1 _2611_ (.A(_0906_),
    .B(_0923_),
    .Y(u_uart_master_reg_u_reg_core_reg_we_check_3_));
 sky130_fd_sc_hd__inv_1 _2612_ (.A(tl_i[30]),
    .Y(_0924_));
 sky130_fd_sc_hd__nor2_1 _2613_ (.A(reg2hw_11_),
    .B(net53),
    .Y(_0925_));
 sky130_fd_sc_hd__a21oi_1 _2614_ (.A1(_0924_),
    .A2(net53),
    .B1(_0925_),
    .Y(_0181_));
 sky130_fd_sc_hd__inv_1 _2615_ (.A(tl_i[29]),
    .Y(_0926_));
 sky130_fd_sc_hd__nor2_1 _2616_ (.A(reg2hw_10_),
    .B(net53),
    .Y(_0927_));
 sky130_fd_sc_hd__a21oi_1 _2617_ (.A1(_0926_),
    .A2(net53),
    .B1(_0927_),
    .Y(_0182_));
 sky130_fd_sc_hd__inv_1 _2618_ (.A(tl_i[28]),
    .Y(_0928_));
 sky130_fd_sc_hd__nor2_1 _2619_ (.A(reg2hw_9_),
    .B(net53),
    .Y(_0929_));
 sky130_fd_sc_hd__a21oi_1 _2620_ (.A1(_0928_),
    .A2(net53),
    .B1(_0929_),
    .Y(_0183_));
 sky130_fd_sc_hd__mux2_1 _2621_ (.A0(reg2hw_8_),
    .A1(tl_i[27]),
    .S(net53),
    .X(_0184_));
 sky130_fd_sc_hd__inv_1 _2622_ (.A(tl_i[26]),
    .Y(_0930_));
 sky130_fd_sc_hd__nor2_1 _2623_ (.A(reg2hw_7_),
    .B(net53),
    .Y(_0931_));
 sky130_fd_sc_hd__a21oi_1 _2624_ (.A1(_0930_),
    .A2(net53),
    .B1(_0931_),
    .Y(_0185_));
 sky130_fd_sc_hd__inv_1 _2625_ (.A(tl_i[25]),
    .Y(_0932_));
 sky130_fd_sc_hd__nor2_1 _2626_ (.A(reg2hw_6_),
    .B(net53),
    .Y(_0933_));
 sky130_fd_sc_hd__a21oi_1 _2627_ (.A1(_0932_),
    .A2(net53),
    .B1(_0933_),
    .Y(_0186_));
 sky130_fd_sc_hd__inv_1 _2628_ (.A(tl_i[24]),
    .Y(_0934_));
 sky130_fd_sc_hd__nor2_1 _2629_ (.A(reg2hw_5_),
    .B(net53),
    .Y(_0935_));
 sky130_fd_sc_hd__a21oi_1 _2630_ (.A1(_0934_),
    .A2(net53),
    .B1(_0935_),
    .Y(_0187_));
 sky130_fd_sc_hd__nand4_1 _2631_ (.A(_0921_),
    .B(_0920_),
    .C(_0922_),
    .D(net66),
    .Y(_0936_));
 sky130_fd_sc_hd__buf_2 _2632_ (.A(net55),
    .X(_0937_));
 sky130_fd_sc_hd__mux2_1 _2633_ (.A0(tl_i[54]),
    .A1(reg2hw_55_),
    .S(net52),
    .X(_0188_));
 sky130_fd_sc_hd__nor2_1 _2634_ (.A(tl_i[53]),
    .B(net52),
    .Y(_0938_));
 sky130_fd_sc_hd__a21oi_1 _2635_ (.A1(_0412_),
    .A2(net52),
    .B1(_0938_),
    .Y(_0189_));
 sky130_fd_sc_hd__nor2_1 _2636_ (.A(tl_i[52]),
    .B(net52),
    .Y(_0939_));
 sky130_fd_sc_hd__a21oi_1 _2637_ (.A1(_0417_),
    .A2(net52),
    .B1(_0939_),
    .Y(_0190_));
 sky130_fd_sc_hd__nor2_1 _2638_ (.A(tl_i[51]),
    .B(net52),
    .Y(_0940_));
 sky130_fd_sc_hd__a21oi_1 _2639_ (.A1(_0374_),
    .A2(net52),
    .B1(_0940_),
    .Y(_0191_));
 sky130_fd_sc_hd__mux2_1 _2640_ (.A0(tl_i[50]),
    .A1(net118),
    .S(net52),
    .X(_0192_));
 sky130_fd_sc_hd__nor2_1 _2641_ (.A(tl_i[49]),
    .B(net52),
    .Y(_0941_));
 sky130_fd_sc_hd__a21oi_1 _2642_ (.A1(_0381_),
    .A2(net52),
    .B1(_0941_),
    .Y(_0193_));
 sky130_fd_sc_hd__nor2_1 _2643_ (.A(tl_i[48]),
    .B(net52),
    .Y(_0942_));
 sky130_fd_sc_hd__a21oi_1 _2644_ (.A1(_0386_),
    .A2(net52),
    .B1(_0942_),
    .Y(_0194_));
 sky130_fd_sc_hd__nor2_1 _2645_ (.A(tl_i[47]),
    .B(net52),
    .Y(_0943_));
 sky130_fd_sc_hd__a21oi_1 _2646_ (.A1(_0393_),
    .A2(net52),
    .B1(_0943_),
    .Y(_0195_));
 sky130_fd_sc_hd__nor2_1 _2647_ (.A(tl_i[46]),
    .B(net52),
    .Y(_0944_));
 sky130_fd_sc_hd__a21oi_1 _2648_ (.A1(_0398_),
    .A2(net52),
    .B1(_0944_),
    .Y(_0196_));
 sky130_fd_sc_hd__mux2_1 _2649_ (.A0(tl_i[45]),
    .A1(net119),
    .S(net52),
    .X(_0197_));
 sky130_fd_sc_hd__mux2_1 _2650_ (.A0(tl_i[44]),
    .A1(net120),
    .S(net52),
    .X(_0198_));
 sky130_fd_sc_hd__mux2_1 _2651_ (.A0(tl_i[43]),
    .A1(net121),
    .S(net52),
    .X(_0199_));
 sky130_fd_sc_hd__mux2_1 _2652_ (.A0(tl_i[42]),
    .A1(net122),
    .S(net52),
    .X(_0200_));
 sky130_fd_sc_hd__mux2_1 _2653_ (.A0(tl_i[41]),
    .A1(reg2hw_42_),
    .S(net55),
    .X(_0201_));
 sky130_fd_sc_hd__mux2_1 _2654_ (.A0(tl_i[40]),
    .A1(net123),
    .S(net55),
    .X(_0202_));
 sky130_fd_sc_hd__inv_4 _2655_ (.A(net68),
    .Y(_0945_));
 sky130_fd_sc_hd__lpflow_clkbufkapwr_1 _2656_ (.A(_0945_),
    .X(_0946_));
 sky130_fd_sc_hd__nand2_1 _2657_ (.A(net60),
    .B(tl_i[100]),
    .Y(_0947_));
 sky130_fd_sc_hd__nand2_1 _2658_ (.A(net68),
    .B(u_uart_master_reg_tl_o_57_),
    .Y(_0948_));
 sky130_fd_sc_hd__nand2_1 _2659_ (.A(_0947_),
    .B(_0948_),
    .Y(_0203_));
 sky130_fd_sc_hd__nand2_1 _2660_ (.A(net60),
    .B(tl_i[98]),
    .Y(_0949_));
 sky130_fd_sc_hd__nand2_1 _2661_ (.A(net68),
    .B(u_uart_master_reg_tl_o_55_),
    .Y(_0950_));
 sky130_fd_sc_hd__nand2_1 _2662_ (.A(_0949_),
    .B(_0950_),
    .Y(_0204_));
 sky130_fd_sc_hd__nand2_1 _2663_ (.A(net60),
    .B(tl_i[97]),
    .Y(_0951_));
 sky130_fd_sc_hd__nand2_1 _2664_ (.A(net68),
    .B(u_uart_master_reg_tl_o_54_),
    .Y(_0952_));
 sky130_fd_sc_hd__nand2_1 _2665_ (.A(_0951_),
    .B(_0952_),
    .Y(_0205_));
 sky130_fd_sc_hd__nand2_1 _2666_ (.A(net60),
    .B(tl_i[96]),
    .Y(_0953_));
 sky130_fd_sc_hd__nand2_1 _2667_ (.A(net68),
    .B(u_uart_master_reg_tl_o_53_),
    .Y(_0954_));
 sky130_fd_sc_hd__nand2_1 _2668_ (.A(_0953_),
    .B(_0954_),
    .Y(_0206_));
 sky130_fd_sc_hd__nand2_1 _2669_ (.A(net60),
    .B(tl_i[95]),
    .Y(_0955_));
 sky130_fd_sc_hd__nand2_1 _2670_ (.A(net68),
    .B(u_uart_master_reg_tl_o_52_),
    .Y(_0956_));
 sky130_fd_sc_hd__nand2_1 _2671_ (.A(_0955_),
    .B(_0956_),
    .Y(_0207_));
 sky130_fd_sc_hd__nand2_1 _2672_ (.A(net60),
    .B(tl_i[94]),
    .Y(_0957_));
 sky130_fd_sc_hd__nand2_1 _2673_ (.A(net68),
    .B(u_uart_master_reg_tl_o_51_),
    .Y(_0958_));
 sky130_fd_sc_hd__nand2_1 _2674_ (.A(_0957_),
    .B(_0958_),
    .Y(_0208_));
 sky130_fd_sc_hd__nand2_1 _2675_ (.A(net60),
    .B(tl_i[93]),
    .Y(_0959_));
 sky130_fd_sc_hd__nand2_1 _2676_ (.A(net68),
    .B(u_uart_master_reg_tl_o_50_),
    .Y(_0960_));
 sky130_fd_sc_hd__nand2_1 _2677_ (.A(_0959_),
    .B(_0960_),
    .Y(_0209_));
 sky130_fd_sc_hd__nand2_1 _2678_ (.A(net60),
    .B(tl_i[92]),
    .Y(_0961_));
 sky130_fd_sc_hd__nand2_1 _2679_ (.A(net68),
    .B(u_uart_master_reg_tl_o_49_),
    .Y(_0962_));
 sky130_fd_sc_hd__nand2_1 _2680_ (.A(_0961_),
    .B(_0962_),
    .Y(_0210_));
 sky130_fd_sc_hd__nand2_1 _2681_ (.A(_0919_),
    .B(_0922_),
    .Y(_0963_));
 sky130_fd_sc_hd__nor2_1 _2682_ (.A(net68),
    .B(_0963_),
    .Y(_0964_));
 sky130_fd_sc_hd__nand2_1 _2683_ (.A(net66),
    .B(reg2hw_55_),
    .Y(_0965_));
 sky130_fd_sc_hd__nor2_1 _2684_ (.A(u_uart_master_reg_tl_o_46_),
    .B(net60),
    .Y(_0966_));
 sky130_fd_sc_hd__a21oi_1 _2685_ (.A1(net57),
    .A2(_0965_),
    .B1(_0966_),
    .Y(_0211_));
 sky130_fd_sc_hd__nand2_1 _2686_ (.A(net66),
    .B(reg2hw_54_),
    .Y(_0967_));
 sky130_fd_sc_hd__nor2_1 _2687_ (.A(u_uart_master_reg_tl_o_45_),
    .B(net60),
    .Y(_0968_));
 sky130_fd_sc_hd__a21oi_1 _2688_ (.A1(net57),
    .A2(_0967_),
    .B1(_0968_),
    .Y(_0212_));
 sky130_fd_sc_hd__nand2_1 _2689_ (.A(net66),
    .B(reg2hw_53_),
    .Y(_0969_));
 sky130_fd_sc_hd__nor2_1 _2690_ (.A(u_uart_master_reg_tl_o_44_),
    .B(net60),
    .Y(_0970_));
 sky130_fd_sc_hd__a21oi_1 _2691_ (.A1(net57),
    .A2(_0969_),
    .B1(_0970_),
    .Y(_0213_));
 sky130_fd_sc_hd__nand2_1 _2692_ (.A(net66),
    .B(reg2hw_52_),
    .Y(_0971_));
 sky130_fd_sc_hd__nor2_1 _2693_ (.A(u_uart_master_reg_tl_o_43_),
    .B(net60),
    .Y(_0972_));
 sky130_fd_sc_hd__a21oi_1 _2694_ (.A1(net57),
    .A2(_0971_),
    .B1(_0972_),
    .Y(_0214_));
 sky130_fd_sc_hd__nand2_1 _2695_ (.A(net66),
    .B(net118),
    .Y(_0973_));
 sky130_fd_sc_hd__nor2_1 _2696_ (.A(u_uart_master_reg_tl_o_42_),
    .B(net60),
    .Y(_0974_));
 sky130_fd_sc_hd__a21oi_1 _2697_ (.A1(net57),
    .A2(_0973_),
    .B1(_0974_),
    .Y(_0215_));
 sky130_fd_sc_hd__nand2_1 _2698_ (.A(net66),
    .B(reg2hw_50_),
    .Y(_0975_));
 sky130_fd_sc_hd__nor2_1 _2699_ (.A(u_uart_master_reg_tl_o_41_),
    .B(net60),
    .Y(_0976_));
 sky130_fd_sc_hd__a21oi_1 _2700_ (.A1(net57),
    .A2(_0975_),
    .B1(_0976_),
    .Y(_0216_));
 sky130_fd_sc_hd__nand2_1 _2701_ (.A(net66),
    .B(reg2hw_49_),
    .Y(_0977_));
 sky130_fd_sc_hd__nor2_1 _2702_ (.A(u_uart_master_reg_tl_o_40_),
    .B(net60),
    .Y(_0978_));
 sky130_fd_sc_hd__a21oi_1 _2703_ (.A1(net57),
    .A2(_0977_),
    .B1(_0978_),
    .Y(_0217_));
 sky130_fd_sc_hd__nand2_1 _2704_ (.A(net66),
    .B(reg2hw_48_),
    .Y(_0979_));
 sky130_fd_sc_hd__nor2_1 _2705_ (.A(u_uart_master_reg_tl_o_39_),
    .B(net60),
    .Y(_0980_));
 sky130_fd_sc_hd__a21oi_1 _2706_ (.A1(net57),
    .A2(_0979_),
    .B1(_0980_),
    .Y(_0218_));
 sky130_fd_sc_hd__nand2_1 _2707_ (.A(net66),
    .B(reg2hw_47_),
    .Y(_0981_));
 sky130_fd_sc_hd__nor2_1 _2708_ (.A(u_uart_master_reg_tl_o_38_),
    .B(net60),
    .Y(_0982_));
 sky130_fd_sc_hd__a21oi_1 _2709_ (.A1(net57),
    .A2(_0981_),
    .B1(_0982_),
    .Y(_0219_));
 sky130_fd_sc_hd__nand2_1 _2710_ (.A(net66),
    .B(net119),
    .Y(_0983_));
 sky130_fd_sc_hd__nor2_1 _2711_ (.A(u_uart_master_reg_tl_o_37_),
    .B(net60),
    .Y(_0984_));
 sky130_fd_sc_hd__a21oi_1 _2712_ (.A1(net57),
    .A2(_0983_),
    .B1(_0984_),
    .Y(_0220_));
 sky130_fd_sc_hd__nor2_1 _2713_ (.A(_1366_),
    .B(_1359_),
    .Y(_0985_));
 sky130_fd_sc_hd__a21oi_1 _2714_ (.A1(_0523_),
    .A2(net106),
    .B1(_0985_),
    .Y(_0986_));
 sky130_fd_sc_hd__nor2_1 _2715_ (.A(_1357_),
    .B(_0986_),
    .Y(_0987_));
 sky130_fd_sc_hd__a21oi_1 _2716_ (.A1(_0522_),
    .A2(net105),
    .B1(_0987_),
    .Y(_0988_));
 sky130_fd_sc_hd__nor2_1 _2717_ (.A(_1362_),
    .B(_0988_),
    .Y(_0989_));
 sky130_fd_sc_hd__nor2_1 _2718_ (.A(_1360_),
    .B(_0989_),
    .Y(_0990_));
 sky130_fd_sc_hd__o21ai_0 _2719_ (.A1(_1371_),
    .A2(_1355_),
    .B1(_0990_),
    .Y(_0991_));
 sky130_fd_sc_hd__o21ai_0 _2720_ (.A1(_1355_),
    .A2(_0990_),
    .B1(_0991_),
    .Y(_0992_));
 sky130_fd_sc_hd__nand2_1 _2721_ (.A(_0992_),
    .B(_0914_),
    .Y(_0993_));
 sky130_fd_sc_hd__clkinv_2 _2722_ (.A(net57),
    .Y(_0994_));
 sky130_fd_sc_hd__a21oi_1 _2723_ (.A1(net120),
    .A2(net66),
    .B1(_0994_),
    .Y(_0995_));
 sky130_fd_sc_hd__nor2_1 _2724_ (.A(u_uart_master_reg_tl_o_36_),
    .B(net60),
    .Y(_0996_));
 sky130_fd_sc_hd__a21oi_1 _2725_ (.A1(_0993_),
    .A2(_0995_),
    .B1(_0996_),
    .Y(_0221_));
 sky130_fd_sc_hd__a211oi_1 _2726_ (.A1(_0988_),
    .A2(_1364_),
    .B1(_0915_),
    .C1(_1373_),
    .Y(_0997_));
 sky130_fd_sc_hd__o21ai_0 _2727_ (.A1(_1364_),
    .A2(_0988_),
    .B1(_0997_),
    .Y(_0998_));
 sky130_fd_sc_hd__a21oi_1 _2728_ (.A1(net121),
    .A2(net66),
    .B1(_0994_),
    .Y(_0999_));
 sky130_fd_sc_hd__nor2_1 _2729_ (.A(u_uart_master_reg_tl_o_35_),
    .B(net60),
    .Y(_1000_));
 sky130_fd_sc_hd__a21oi_1 _2730_ (.A1(_0998_),
    .A2(_0999_),
    .B1(_1000_),
    .Y(_0222_));
 sky130_fd_sc_hd__nor2_1 _2731_ (.A(_0915_),
    .B(_1373_),
    .Y(_1001_));
 sky130_fd_sc_hd__nand2_1 _2732_ (.A(_0986_),
    .B(_1357_),
    .Y(_1002_));
 sky130_fd_sc_hd__nand3b_1 _2733_ (.A_N(_0987_),
    .B(_1001_),
    .C(_1002_),
    .Y(_1003_));
 sky130_fd_sc_hd__a21oi_1 _2734_ (.A1(net122),
    .A2(net66),
    .B1(_0994_),
    .Y(_1004_));
 sky130_fd_sc_hd__nor2_1 _2735_ (.A(u_uart_master_reg_tl_o_34_),
    .B(net60),
    .Y(_1005_));
 sky130_fd_sc_hd__a21oi_1 _2736_ (.A1(_1003_),
    .A2(_1004_),
    .B1(_1005_),
    .Y(_0223_));
 sky130_fd_sc_hd__nand2_1 _2737_ (.A(_1359_),
    .B(_1366_),
    .Y(_1006_));
 sky130_fd_sc_hd__nand3b_1 _2738_ (.A_N(_0985_),
    .B(_1001_),
    .C(_1006_),
    .Y(_1007_));
 sky130_fd_sc_hd__a21oi_1 _2739_ (.A1(reg2hw_42_),
    .A2(net66),
    .B1(_0994_),
    .Y(_1008_));
 sky130_fd_sc_hd__nor2_1 _2740_ (.A(u_uart_master_reg_tl_o_33_),
    .B(_0945_),
    .Y(_1009_));
 sky130_fd_sc_hd__a21oi_1 _2741_ (.A1(_1007_),
    .A2(_1008_),
    .B1(_1009_),
    .Y(_0224_));
 sky130_fd_sc_hd__nand2_1 _2742_ (.A(net66),
    .B(net123),
    .Y(_1010_));
 sky130_fd_sc_hd__nand2_1 _2743_ (.A(_1370_),
    .B(_0914_),
    .Y(_1011_));
 sky130_fd_sc_hd__nor2_1 _2744_ (.A(u_uart_master_reg_tl_o_32_),
    .B(_0945_),
    .Y(_1012_));
 sky130_fd_sc_hd__a31oi_1 _2745_ (.A1(net57),
    .A2(_1010_),
    .A3(_1011_),
    .B1(_1012_),
    .Y(_0225_));
 sky130_fd_sc_hd__nor2_1 _2746_ (.A(u_uart_master_reg_tl_o_31_),
    .B(net60),
    .Y(_1013_));
 sky130_fd_sc_hd__nor2_1 _2747_ (.A(_1013_),
    .B(net57),
    .Y(_0226_));
 sky130_fd_sc_hd__nor2_1 _2748_ (.A(u_uart_master_reg_tl_o_30_),
    .B(net60),
    .Y(_1014_));
 sky130_fd_sc_hd__nor2_1 _2749_ (.A(_1014_),
    .B(net57),
    .Y(_0227_));
 sky130_fd_sc_hd__nor2_1 _2750_ (.A(u_uart_master_reg_tl_o_29_),
    .B(net60),
    .Y(_1015_));
 sky130_fd_sc_hd__nor2_1 _2751_ (.A(_1015_),
    .B(net57),
    .Y(_0228_));
 sky130_fd_sc_hd__nor2_1 _2752_ (.A(u_uart_master_reg_tl_o_28_),
    .B(net60),
    .Y(_1016_));
 sky130_fd_sc_hd__nor2_1 _2753_ (.A(_1016_),
    .B(net57),
    .Y(_0229_));
 sky130_fd_sc_hd__nor2_1 _2754_ (.A(u_uart_master_reg_tl_o_27_),
    .B(net60),
    .Y(_1017_));
 sky130_fd_sc_hd__nor2_1 _2755_ (.A(_1017_),
    .B(net57),
    .Y(_0230_));
 sky130_fd_sc_hd__nor2_1 _2756_ (.A(u_uart_master_reg_tl_o_26_),
    .B(net60),
    .Y(_1018_));
 sky130_fd_sc_hd__nor2_1 _2757_ (.A(_1018_),
    .B(net57),
    .Y(_0231_));
 sky130_fd_sc_hd__nor2_1 _2758_ (.A(u_uart_master_reg_tl_o_25_),
    .B(net60),
    .Y(_1019_));
 sky130_fd_sc_hd__nor2_1 _2759_ (.A(_1019_),
    .B(net57),
    .Y(_0232_));
 sky130_fd_sc_hd__nor2_1 _2760_ (.A(u_uart_master_reg_tl_o_24_),
    .B(net60),
    .Y(_1020_));
 sky130_fd_sc_hd__nor2_1 _2761_ (.A(_1020_),
    .B(net57),
    .Y(_0233_));
 sky130_fd_sc_hd__inv_2 _2762_ (.A(_0530_),
    .Y(_1021_));
 sky130_fd_sc_hd__nor2_1 _2763_ (.A(_1021_),
    .B(_0770_),
    .Y(_1022_));
 sky130_fd_sc_hd__a21oi_1 _2764_ (.A1(net116),
    .A2(net66),
    .B1(_1022_),
    .Y(_1023_));
 sky130_fd_sc_hd__nor2_1 _2765_ (.A(u_uart_master_reg_tl_o_23_),
    .B(_0945_),
    .Y(_1024_));
 sky130_fd_sc_hd__a21oi_1 _2766_ (.A1(_1023_),
    .A2(net57),
    .B1(_1024_),
    .Y(_0234_));
 sky130_fd_sc_hd__o22ai_1 _2767_ (.A1(_1384_),
    .A2(_0911_),
    .B1(_1021_),
    .B2(_0573_),
    .Y(_1025_));
 sky130_fd_sc_hd__o22a_1 _2768_ (.A1(u_uart_master_reg_tl_o_22_),
    .A2(_0945_),
    .B1(_0994_),
    .B2(_1025_),
    .X(_0235_));
 sky130_fd_sc_hd__nor3_1 _2769_ (.A(tl_i[64]),
    .B(tl_i[63]),
    .C(_0913_),
    .Y(_1026_));
 sky130_fd_sc_hd__nor2_1 _2770_ (.A(_1021_),
    .B(_0609_),
    .Y(_1027_));
 sky130_fd_sc_hd__a221oi_1 _2771_ (.A1(net124),
    .A2(net66),
    .B1(_0539_),
    .B2(_1026_),
    .C1(_1027_),
    .Y(_1028_));
 sky130_fd_sc_hd__nor2_1 _2772_ (.A(u_uart_master_reg_tl_o_21_),
    .B(_0945_),
    .Y(_1029_));
 sky130_fd_sc_hd__a21oi_1 _2773_ (.A1(_1028_),
    .A2(net57),
    .B1(_1029_),
    .Y(_0236_));
 sky130_fd_sc_hd__inv_1 _2774_ (.A(reg2hw_37_),
    .Y(_1030_));
 sky130_fd_sc_hd__o22ai_1 _2775_ (.A1(_1030_),
    .A2(_0911_),
    .B1(_1021_),
    .B2(net50),
    .Y(_1031_));
 sky130_fd_sc_hd__a21oi_1 _2776_ (.A1(hw2reg_28_),
    .A2(_1026_),
    .B1(_1031_),
    .Y(_1032_));
 sky130_fd_sc_hd__nor2_1 _2777_ (.A(u_uart_master_reg_tl_o_20_),
    .B(_0945_),
    .Y(_1033_));
 sky130_fd_sc_hd__a21oi_1 _2778_ (.A1(_1032_),
    .A2(net57),
    .B1(_1033_),
    .Y(_0237_));
 sky130_fd_sc_hd__nand2_1 _2779_ (.A(_0645_),
    .B(_0530_),
    .Y(_1034_));
 sky130_fd_sc_hd__inv_1 _2780_ (.A(_0324_),
    .Y(_1035_));
 sky130_fd_sc_hd__nor2_1 _2781_ (.A(_1035_),
    .B(_0337_),
    .Y(_1036_));
 sky130_fd_sc_hd__clkinv_1 _2782_ (.A(_1036_),
    .Y(_1037_));
 sky130_fd_sc_hd__inv_1 _2783_ (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_under_rst),
    .Y(_1038_));
 sky130_fd_sc_hd__inv_1 _2784_ (.A(_1026_),
    .Y(_1039_));
 sky130_fd_sc_hd__a21oi_1 _2785_ (.A1(_1037_),
    .A2(_1038_),
    .B1(_1039_),
    .Y(_1040_));
 sky130_fd_sc_hd__nor2_1 _2786_ (.A(u_uart_master_core_u_uart_core_uart_tx_bit_cnt_q_0_),
    .B(u_uart_master_core_u_uart_core_uart_tx_bit_cnt_q_1_),
    .Y(_1041_));
 sky130_fd_sc_hd__inv_1 _2787_ (.A(u_uart_master_core_u_uart_core_uart_tx_bit_cnt_q_2_),
    .Y(_1042_));
 sky130_fd_sc_hd__nand2_1 _2788_ (.A(_1041_),
    .B(_1042_),
    .Y(_1043_));
 sky130_fd_sc_hd__nor2_1 _2789_ (.A(u_uart_master_core_u_uart_core_uart_tx_bit_cnt_q_3_),
    .B(_1043_),
    .Y(_1044_));
 sky130_fd_sc_hd__clkinv_1 _2790_ (.A(_1044_),
    .Y(_1045_));
 sky130_fd_sc_hd__nand2_1 _2791_ (.A(_1045_),
    .B(net115),
    .Y(_1046_));
 sky130_fd_sc_hd__a21oi_1 _2792_ (.A1(_1040_),
    .A2(_1046_),
    .B1(_0994_),
    .Y(_1047_));
 sky130_fd_sc_hd__nor3_1 _2793_ (.A(_0329_),
    .B(_0331_),
    .C(_0335_),
    .Y(_1048_));
 sky130_fd_sc_hd__or2_4 _2794_ (.A(_0329_),
    .B(_1048_),
    .X(_1049_));
 sky130_fd_sc_hd__o21bai_1 _2795_ (.A1(_0327_),
    .A2(_1049_),
    .B1_N(_0326_),
    .Y(_1050_));
 sky130_fd_sc_hd__a31oi_1 _2796_ (.A1(_1050_),
    .A2(_0337_),
    .A3(_1035_),
    .B1(_0915_),
    .Y(_1051_));
 sky130_fd_sc_hd__o21ai_0 _2797_ (.A1(_1035_),
    .A2(_1050_),
    .B1(_1051_),
    .Y(_1052_));
 sky130_fd_sc_hd__nor2_1 _2798_ (.A(u_uart_master_reg_tl_o_19_),
    .B(_0945_),
    .Y(_1053_));
 sky130_fd_sc_hd__a31oi_1 _2799_ (.A1(_1034_),
    .A2(_1047_),
    .A3(_1052_),
    .B1(_1053_),
    .Y(_0238_));
 sky130_fd_sc_hd__xnor2_1 _2800_ (.A(_0328_),
    .B(_1049_),
    .Y(_1054_));
 sky130_fd_sc_hd__a21oi_1 _2801_ (.A1(reg2hw_36_),
    .A2(net66),
    .B1(_1040_),
    .Y(_1055_));
 sky130_fd_sc_hd__nor2_1 _2802_ (.A(_1021_),
    .B(net54),
    .Y(_1056_));
 sky130_fd_sc_hd__nor2_1 _2803_ (.A(_0963_),
    .B(_1056_),
    .Y(_1057_));
 sky130_fd_sc_hd__o311ai_0 _2804_ (.A1(_0338_),
    .A2(_0915_),
    .A3(_1054_),
    .B1(_1055_),
    .C1(_1057_),
    .Y(_1058_));
 sky130_fd_sc_hd__a22o_1 _2805_ (.A1(u_uart_master_reg_tl_o_18_),
    .A2(_0994_),
    .B1(_1058_),
    .B2(_0945_),
    .X(_0239_));
 sky130_fd_sc_hd__a21oi_1 _2806_ (.A1(_1374_),
    .A2(_1026_),
    .B1(_0994_),
    .Y(_1059_));
 sky130_fd_sc_hd__nand2_1 _2807_ (.A(_0679_),
    .B(_0530_),
    .Y(_1060_));
 sky130_fd_sc_hd__buf_2 _2808_ (.A(_0334_),
    .X(_1061_));
 sky130_fd_sc_hd__nor3_1 _2809_ (.A(net65),
    .B(net137),
    .C(_0332_),
    .Y(_1062_));
 sky130_fd_sc_hd__dfstp_1 _2810_ (.D(_0277_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_sreg_q_0_),
    .SET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2811_ (.D(_0276_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_sreg_q_1_),
    .SET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2812_ (.D(_0275_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_sreg_q_2_),
    .SET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2813_ (.D(_0274_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_sreg_q_3_),
    .SET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2814_ (.D(_0273_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_sreg_q_4_),
    .SET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2815_ (.D(_0272_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_sreg_q_5_),
    .SET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2816_ (.D(_0271_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_sreg_q_6_),
    .SET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2817_ (.D(_0270_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_sreg_q_7_),
    .SET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2818_ (.D(_0269_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_sreg_q_8_),
    .SET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2819_ (.D(_0278_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_sreg_q_9_),
    .SET_B(net103),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2820_ (.D(_0290_),
    .Q(u_uart_master_reg_tl_o_62_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2821_ (.D(_0268_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2822_ (.D(_0267_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2823_ (.D(_0266_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_2_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2824_ (.D(_0287_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2825_ (.D(_0265_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_0_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2826_ (.D(_0264_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2827_ (.D(_0263_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2828_ (.D(_0289_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2829_ (.D(_0262_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_baud_div_q_0_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2830_ (.D(_0261_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_baud_div_q_1_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2831_ (.D(_0260_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_baud_div_q_2_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2832_ (.D(_0285_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_baud_div_q_3_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2833_ (.D(_0259_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_bit_cnt_q_0_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2834_ (.D(_0258_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_bit_cnt_q_1_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2835_ (.D(_0257_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_bit_cnt_q_2_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2836_ (.D(_0283_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_bit_cnt_q_3_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2837_ (.D(_0282_),
    .Q(hw2reg_28_),
    .SET_B(net103),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2838_ (.D(_0256_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_sreg_q_1_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2839_ (.D(_0255_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_sreg_q_2_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2840_ (.D(_0254_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_sreg_q_3_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2841_ (.D(_0253_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_sreg_q_4_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2842_ (.D(_0252_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_sreg_q_5_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2843_ (.D(_0251_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_sreg_q_6_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2844_ (.D(_0250_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_sreg_q_7_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2845_ (.D(_0249_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_sreg_q_8_),
    .RESET_B(net100),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2846_ (.D(_0248_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_sreg_q_9_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2847_ (.D(_0288_),
    .Q(u_uart_master_core_u_uart_core_uart_rx_sreg_q_10_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2848_ (.D(_0247_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_baud_div_q_0_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2849_ (.D(_0246_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_baud_div_q_1_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2850_ (.D(_0245_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_baud_div_q_2_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2851_ (.D(_0316_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_baud_div_q_3_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2852_ (.D(_0244_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_bit_cnt_q_0_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2853_ (.D(_0243_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_bit_cnt_q_1_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2854_ (.D(_0242_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_bit_cnt_q_2_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2855_ (.D(_0284_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_bit_cnt_q_3_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2856_ (.D(_0294_),
    .Q(u_uart_master_core_u_uart_core_tx_out),
    .SET_B(net103),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2857_ (.D(_0314_),
    .Q(u_uart_master_reg_tl_o_1_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2858_ (.D(_0286_),
    .Q(u_uart_master_reg_tl_o_65_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2859_ (.D(_0241_),
    .Q(u_uart_master_reg_tl_o_16_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2860_ (.D(_0240_),
    .Q(u_uart_master_reg_tl_o_17_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2861_ (.D(_0239_),
    .Q(u_uart_master_reg_tl_o_18_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2862_ (.D(_0238_),
    .Q(u_uart_master_reg_tl_o_19_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2863_ (.D(_0237_),
    .Q(u_uart_master_reg_tl_o_20_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2864_ (.D(_0236_),
    .Q(u_uart_master_reg_tl_o_21_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2865_ (.D(_0235_),
    .Q(u_uart_master_reg_tl_o_22_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2866_ (.D(_0234_),
    .Q(u_uart_master_reg_tl_o_23_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2867_ (.D(_0233_),
    .Q(u_uart_master_reg_tl_o_24_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2868_ (.D(_0232_),
    .Q(u_uart_master_reg_tl_o_25_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2869_ (.D(_0231_),
    .Q(u_uart_master_reg_tl_o_26_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2870_ (.D(_0230_),
    .Q(u_uart_master_reg_tl_o_27_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2871_ (.D(_0229_),
    .Q(u_uart_master_reg_tl_o_28_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2872_ (.D(_0228_),
    .Q(u_uart_master_reg_tl_o_29_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2873_ (.D(_0227_),
    .Q(u_uart_master_reg_tl_o_30_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2874_ (.D(_0226_),
    .Q(u_uart_master_reg_tl_o_31_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2875_ (.D(_0225_),
    .Q(u_uart_master_reg_tl_o_32_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2876_ (.D(_0224_),
    .Q(u_uart_master_reg_tl_o_33_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2877_ (.D(_0223_),
    .Q(u_uart_master_reg_tl_o_34_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2878_ (.D(_0222_),
    .Q(u_uart_master_reg_tl_o_35_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2879_ (.D(_0221_),
    .Q(u_uart_master_reg_tl_o_36_),
    .RESET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2880_ (.D(_0220_),
    .Q(u_uart_master_reg_tl_o_37_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2881_ (.D(_0219_),
    .Q(u_uart_master_reg_tl_o_38_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2882_ (.D(_0218_),
    .Q(u_uart_master_reg_tl_o_39_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2883_ (.D(_0217_),
    .Q(u_uart_master_reg_tl_o_40_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2884_ (.D(_0216_),
    .Q(u_uart_master_reg_tl_o_41_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2885_ (.D(_0215_),
    .Q(u_uart_master_reg_tl_o_42_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2886_ (.D(_0214_),
    .Q(u_uart_master_reg_tl_o_43_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2887_ (.D(_0213_),
    .Q(u_uart_master_reg_tl_o_44_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2888_ (.D(_0212_),
    .Q(u_uart_master_reg_tl_o_45_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2889_ (.D(_0211_),
    .Q(u_uart_master_reg_tl_o_46_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2890_ (.D(_0291_),
    .Q(u_uart_master_reg_tl_o_47_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2891_ (.D(_0210_),
    .Q(u_uart_master_reg_tl_o_49_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2892_ (.D(_0209_),
    .Q(u_uart_master_reg_tl_o_50_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2893_ (.D(_0208_),
    .Q(u_uart_master_reg_tl_o_51_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2894_ (.D(_0207_),
    .Q(u_uart_master_reg_tl_o_52_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2895_ (.D(_0206_),
    .Q(u_uart_master_reg_tl_o_53_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2896_ (.D(_0205_),
    .Q(u_uart_master_reg_tl_o_54_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2897_ (.D(_0204_),
    .Q(u_uart_master_reg_tl_o_55_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2898_ (.D(_0318_),
    .Q(u_uart_master_reg_tl_o_56_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2899_ (.D(_0203_),
    .Q(u_uart_master_reg_tl_o_57_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2900_ (.D(_0317_),
    .Q(u_uart_master_reg_tl_o_58_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2901_ (.D(_0315_),
    .Q(reg2hw_38_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2902_ (.D(_0202_),
    .Q(reg2hw_41_),
    .SET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2903_ (.D(_0201_),
    .Q(reg2hw_42_),
    .SET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2904_ (.D(_0200_),
    .Q(reg2hw_43_),
    .SET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2905_ (.D(_0199_),
    .Q(reg2hw_44_),
    .SET_B(net85),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2906_ (.D(_0198_),
    .Q(reg2hw_45_),
    .SET_B(net85),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2907_ (.D(_0197_),
    .Q(reg2hw_46_),
    .SET_B(net85),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2908_ (.D(_0196_),
    .Q(reg2hw_47_),
    .SET_B(net85),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2909_ (.D(_0195_),
    .Q(reg2hw_48_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2910_ (.D(_0194_),
    .Q(reg2hw_49_),
    .SET_B(net85),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2911_ (.D(_0193_),
    .Q(reg2hw_50_),
    .SET_B(net85),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2912_ (.D(_0192_),
    .Q(reg2hw_51_),
    .RESET_B(net83),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2913_ (.D(_0191_),
    .Q(reg2hw_52_),
    .SET_B(net85),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2914_ (.D(_0190_),
    .Q(reg2hw_53_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2915_ (.D(_0189_),
    .Q(reg2hw_54_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2916_ (.D(_0188_),
    .Q(reg2hw_55_),
    .SET_B(net85),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2917_ (.D(_0310_),
    .Q(reg2hw_56_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2918_ (.D(_0313_),
    .Q(reg2hw_36_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2919_ (.D(_0312_),
    .Q(reg2hw_39_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2920_ (.D(_0311_),
    .Q(reg2hw_40_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2921_ (.D(_0303_),
    .Q(reg2hw_35_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2922_ (.D(_0300_),
    .Q(reg2hw_37_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2923_ (.D(_0293_),
    .Q(reg2hw_34_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2924_ (.D(_0279_),
    .Q(reg2hw_1_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2925_ (.D(_0280_),
    .Q(reg2hw_3_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2926_ (.D(_0187_),
    .Q(reg2hw_5_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2927_ (.D(_0186_),
    .Q(reg2hw_6_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2928_ (.D(_0185_),
    .Q(reg2hw_7_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2929_ (.D(_0184_),
    .Q(reg2hw_8_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2930_ (.D(_0183_),
    .Q(reg2hw_9_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2931_ (.D(_0182_),
    .Q(reg2hw_10_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2932_ (.D(_0181_),
    .Q(reg2hw_11_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2933_ (.D(_0281_),
    .Q(reg2hw_12_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2934_ (.D(_0180_),
    .Q(u_uart_master_core_addr_o_2_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2935_ (.D(_0179_),
    .Q(u_uart_master_core_addr_o_3_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2936_ (.D(_0178_),
    .Q(u_uart_master_core_addr_o_4_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2937_ (.D(_0177_),
    .Q(u_uart_master_core_addr_o_5_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2938_ (.D(_0176_),
    .Q(u_uart_master_core_addr_o_6_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2939_ (.D(_0175_),
    .Q(u_uart_master_core_addr_o_7_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2940_ (.D(_0174_),
    .Q(u_uart_master_core_addr_o_8_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2941_ (.D(_0173_),
    .Q(u_uart_master_core_addr_o_9_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2942_ (.D(_0172_),
    .Q(u_uart_master_core_addr_o_10_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2943_ (.D(_0171_),
    .Q(u_uart_master_core_addr_o_11_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2944_ (.D(_0170_),
    .Q(u_uart_master_core_addr_o_12_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2945_ (.D(_0169_),
    .Q(u_uart_master_core_addr_o_13_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2946_ (.D(_0168_),
    .Q(u_uart_master_core_addr_o_14_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2947_ (.D(_0167_),
    .Q(u_uart_master_core_addr_o_15_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2948_ (.D(_0166_),
    .Q(u_uart_master_core_addr_o_16_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2949_ (.D(_0165_),
    .Q(u_uart_master_core_addr_o_17_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2950_ (.D(_0164_),
    .Q(u_uart_master_core_addr_o_18_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2951_ (.D(_0163_),
    .Q(u_uart_master_core_addr_o_19_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2952_ (.D(_0162_),
    .Q(u_uart_master_core_addr_o_20_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2953_ (.D(_0161_),
    .Q(u_uart_master_core_addr_o_21_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2954_ (.D(_0160_),
    .Q(u_uart_master_core_addr_o_22_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2955_ (.D(_0159_),
    .Q(u_uart_master_core_addr_o_23_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2956_ (.D(_0158_),
    .Q(u_uart_master_core_addr_o_24_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2957_ (.D(_0157_),
    .Q(u_uart_master_core_addr_o_25_),
    .RESET_B(net90),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2958_ (.D(_0156_),
    .Q(u_uart_master_core_addr_o_26_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2959_ (.D(_0155_),
    .Q(u_uart_master_core_addr_o_27_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2960_ (.D(_0154_),
    .Q(u_uart_master_core_addr_o_28_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2961_ (.D(_0153_),
    .Q(u_uart_master_core_addr_o_29_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2962_ (.D(_0152_),
    .Q(u_uart_master_core_addr_o_30_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2963_ (.D(_0292_),
    .Q(u_uart_master_core_addr_o_31_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2964_ (.D(_0295_),
    .Q(u_uart_master_core_u_host_bridge_any_err_q),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2965_ (.D(_0151_),
    .Q(u_uart_master_core_be_o_0_),
    .SET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2966_ (.D(_0150_),
    .Q(u_uart_master_core_be_o_1_),
    .SET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2967_ (.D(_0149_),
    .Q(u_uart_master_core_be_o_2_),
    .SET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2968_ (.D(_0296_),
    .Q(u_uart_master_core_be_o_3_),
    .SET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2969_ (.D(_0148_),
    .Q(u_uart_master_core_u_host_bridge_bebyte_q_0_),
    .SET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2970_ (.D(_0147_),
    .Q(u_uart_master_core_u_host_bridge_bebyte_q_1_),
    .SET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2971_ (.D(_0146_),
    .Q(u_uart_master_core_u_host_bridge_bebyte_q_2_),
    .SET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2972_ (.D(_0297_),
    .Q(u_uart_master_core_u_host_bridge_bebyte_q_3_),
    .SET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2973_ (.D(_0145_),
    .Q(u_uart_master_core_u_host_bridge_idx_q_0_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2974_ (.D(_0298_),
    .Q(u_uart_master_core_u_host_bridge_idx_q_1_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2975_ (.D(_0144_),
    .Q(u_uart_master_core_u_host_bridge_op_q_0_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2976_ (.D(_0143_),
    .Q(u_uart_master_core_u_host_bridge_op_q_1_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2977_ (.D(_0142_),
    .Q(u_uart_master_core_u_host_bridge_op_q_2_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2978_ (.D(_0141_),
    .Q(u_uart_master_core_u_host_bridge_op_q_3_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2979_ (.D(_0140_),
    .Q(u_uart_master_core_u_host_bridge_op_q_4_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2980_ (.D(_0139_),
    .Q(u_uart_master_core_u_host_bridge_op_q_5_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2981_ (.D(_0138_),
    .Q(u_uart_master_core_u_host_bridge_op_q_6_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2982_ (.D(_0299_),
    .Q(u_uart_master_core_u_host_bridge_op_q_7_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2983_ (.D(_0137_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_0_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2984_ (.D(_0136_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_1_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2985_ (.D(_0135_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_2_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2986_ (.D(_0134_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_3_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2987_ (.D(_0133_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_4_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2988_ (.D(_0132_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_5_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2989_ (.D(_0131_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_6_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2990_ (.D(_0130_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_7_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2991_ (.D(_0129_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_8_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2992_ (.D(_0128_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_9_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2993_ (.D(_0127_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_10_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2994_ (.D(_0126_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_11_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2995_ (.D(_0125_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_12_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2996_ (.D(_0124_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_13_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2997_ (.D(_0123_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_14_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2998_ (.D(_0122_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_15_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2999_ (.D(_0121_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_16_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3000_ (.D(_0120_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_17_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3001_ (.D(_0119_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_18_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3002_ (.D(_0118_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_19_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3003_ (.D(_0117_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_20_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3004_ (.D(_0116_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_21_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3005_ (.D(_0115_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_22_),
    .RESET_B(net96),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3006_ (.D(_0114_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_23_),
    .RESET_B(net97),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3007_ (.D(_0113_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_24_),
    .RESET_B(net97),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3008_ (.D(_0112_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_25_),
    .RESET_B(net97),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3009_ (.D(_0111_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_26_),
    .RESET_B(net97),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3010_ (.D(_0110_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_27_),
    .RESET_B(net97),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3011_ (.D(_0109_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_28_),
    .RESET_B(net97),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3012_ (.D(_0108_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_29_),
    .RESET_B(net97),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3013_ (.D(_0107_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_30_),
    .RESET_B(net97),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3014_ (.D(_0301_),
    .Q(u_uart_master_core_u_host_bridge_rdata_q_31_),
    .RESET_B(net97),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_2 _3015_ (.D(_0302_),
    .Q(req_o),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3016_ (.D(_0106_),
    .Q(u_uart_master_core_u_host_bridge_rxf_st_q_0_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3017_ (.D(_0105_),
    .Q(u_uart_master_core_u_host_bridge_rxf_st_q_1_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3018_ (.D(_0304_),
    .Q(u_uart_master_core_u_host_bridge_rxf_st_q_2_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3019_ (.D(_0104_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_8_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3020_ (.D(_0103_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_9_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3021_ (.D(_0102_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_10_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3022_ (.D(_0101_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_11_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3023_ (.D(_0100_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_12_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3024_ (.D(_0099_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_13_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3025_ (.D(_0098_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_14_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3026_ (.D(_0097_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_15_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3027_ (.D(_0096_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_16_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3028_ (.D(_0095_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_17_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3029_ (.D(_0094_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_18_),
    .RESET_B(net94),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3030_ (.D(_0093_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_19_),
    .RESET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3031_ (.D(_0092_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_20_),
    .RESET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3032_ (.D(_0091_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_21_),
    .RESET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3033_ (.D(_0090_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_22_),
    .RESET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3034_ (.D(_0089_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_23_),
    .RESET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3035_ (.D(_0088_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_24_),
    .RESET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3036_ (.D(_0087_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_25_),
    .RESET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3037_ (.D(_0086_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_26_),
    .RESET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3038_ (.D(_0085_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_27_),
    .RESET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3039_ (.D(_0084_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_28_),
    .RESET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3040_ (.D(_0083_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_29_),
    .RESET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3041_ (.D(_0082_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_30_),
    .RESET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3042_ (.D(_0305_),
    .Q(u_uart_master_core_u_host_bridge_sh_q_31_),
    .RESET_B(net95),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3043_ (.D(_0081_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_0_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3044_ (.D(_0080_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_1_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3045_ (.D(_0079_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_2_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3046_ (.D(_0078_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_3_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3047_ (.D(_0077_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_4_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3048_ (.D(_0076_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_5_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3049_ (.D(_0075_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_6_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3050_ (.D(_0074_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_7_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3051_ (.D(_0073_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_8_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3052_ (.D(_0072_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_9_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3053_ (.D(_0071_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_10_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3054_ (.D(_0070_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_11_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3055_ (.D(_0069_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_12_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3056_ (.D(_0068_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_13_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3057_ (.D(_0067_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_14_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3058_ (.D(_0066_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_15_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3059_ (.D(_0065_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_16_),
    .RESET_B(net91),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3060_ (.D(_0064_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_17_),
    .RESET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3061_ (.D(_0063_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_18_),
    .RESET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3062_ (.D(_0062_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_19_),
    .RESET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3063_ (.D(_0061_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_20_),
    .RESET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3064_ (.D(_0060_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_21_),
    .RESET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3065_ (.D(_0059_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_22_),
    .RESET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3066_ (.D(_0058_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_23_),
    .RESET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3067_ (.D(_0057_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_24_),
    .RESET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3068_ (.D(_0056_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_25_),
    .RESET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3069_ (.D(_0055_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_26_),
    .RESET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3070_ (.D(_0054_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_27_),
    .RESET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3071_ (.D(_0053_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_28_),
    .RESET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3072_ (.D(_0052_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_29_),
    .RESET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3073_ (.D(_0051_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_30_),
    .RESET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3074_ (.D(_0306_),
    .Q(u_uart_master_core_u_host_bridge_wdata_o_31_),
    .RESET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3075_ (.D(_0050_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_0_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3076_ (.D(_0049_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_1_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3077_ (.D(_0048_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3078_ (.D(_0047_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3079_ (.D(_0307_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3080_ (.D(_0046_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_0_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3081_ (.D(_0045_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3082_ (.D(_0044_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3083_ (.D(_0043_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3084_ (.D(_0308_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_2 _3085_ (.D(_0309_),
    .Q(we_o),
    .RESET_B(net92),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _3086_ (.D(_0018_),
    .Q(u_uart_master_core_u_host_bridge_tx_st_q_0_),
    .SET_B(net97),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3087_ (.D(u_uart_master_core_u_host_bridge_tx_st_d_0_),
    .Q(u_uart_master_core_u_host_bridge_tx_st_q_1_),
    .RESET_B(net97),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3088_ (.D(net53),
    .Q(reg2hw_4_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3089_ (.D(u_uart_master_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .Q(reg2hw_0_),
    .RESET_B(net84),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3090_ (.D(net24),
    .Q(u_uart_master_core_u_uart_core_rst_ni),
    .RESET_B(core_rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _3090__25 (.HI(net24));
 sky130_fd_sc_hd__dfrtp_1 _3091_ (.D(_1390_),
    .Q(u_uart_master_core_u_uart_core_uart_tx_tick_baud_q),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3092_ (.D(u_uart_master_core_u_uart_core_uart_rx_tick_baud_d),
    .Q(u_uart_master_core_u_uart_core_rx_tick_baud),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3093_ (.D(_0000_),
    .Q(u_uart_master_core_u_uart_core_rx_valid),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _3094_ (.D(net),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_under_rst),
    .SET_B(net103),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _3094__1 (.LO(net));
 sky130_fd_sc_hd__dfstp_1 _3095_ (.D(net1),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_under_rst),
    .SET_B(net103),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _3095__2 (.LO(net1));
 sky130_fd_sc_hd__dfstp_1 _3096_ (.D(_1389_),
    .Q(u_uart_master_core_u_uart_core_tx_out_q),
    .SET_B(net103),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _3097_ (.D(u_uart_master_core_u_uart_core_sync_rx_intq),
    .Q(u_uart_master_core_u_uart_core_rx_sync),
    .SET_B(net103),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _3098_ (.D(cio_rx_i),
    .Q(u_uart_master_core_u_uart_core_sync_rx_intq),
    .SET_B(net103),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _3099_ (.D(u_uart_master_core_u_uart_core_rx_sync_q1),
    .Q(u_uart_master_core_u_uart_core_rx_sync_q2),
    .SET_B(net103),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _3100_ (.D(u_uart_master_core_u_uart_core_rx_sync),
    .Q(u_uart_master_core_u_uart_core_rx_sync_q1),
    .SET_B(net103),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3101_ (.D(_0002_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_0_),
    .RESET_B(net101),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3102_ (.D(_0009_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_1_),
    .RESET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3103_ (.D(_0010_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_2_),
    .RESET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3104_ (.D(_0011_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_3_),
    .RESET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3105_ (.D(_0012_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_4_),
    .RESET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3106_ (.D(_0013_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_5_),
    .RESET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3107_ (.D(_0014_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_6_),
    .RESET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3108_ (.D(_0015_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_7_),
    .RESET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3109_ (.D(_0016_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_8_),
    .RESET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3110_ (.D(_0017_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_9_),
    .RESET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3111_ (.D(_0003_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_10_),
    .RESET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3112_ (.D(_0004_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_11_),
    .RESET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3113_ (.D(_0005_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_12_),
    .RESET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3114_ (.D(_0006_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_13_),
    .RESET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3115_ (.D(_0007_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_14_),
    .RESET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3116_ (.D(_0008_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_15_),
    .RESET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3117_ (.D(_0001_),
    .Q(u_uart_master_core_u_uart_core_nco_sum_q_16_),
    .RESET_B(net102),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3118_ (.D(net25),
    .Q(u_uart_master_core_host_rst_ni),
    .RESET_B(core_rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _3118__26 (.HI(net25));
 sky130_fd_sc_hd__dfrtp_1 _3119_ (.D(net26),
    .Q(u_uart_master_core_u_host_bridge_response_rst_ni),
    .RESET_B(net98),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _3119__27 (.HI(net26));
 sky130_fd_sc_hd__dfrtp_1 _3120_ (.D(net27),
    .Q(u_uart_master_core_u_host_bridge_parser_rst_ni),
    .RESET_B(net98),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _3120__28 (.HI(net27));
 sky130_fd_sc_hd__dfrtp_1 _3121_ (.D(net28),
    .Q(u_uart_master_core_u_host_bridge_bus_rst_ni),
    .RESET_B(net98),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _3121__29 (.HI(net28));
 sky130_fd_sc_hd__dfrtp_1 _3122_ (.D(u_uart_master_core_u_host_bridge_tx_idx_d_0_),
    .Q(u_uart_master_core_u_host_bridge_tx_idx_q_0_),
    .RESET_B(net97),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3123_ (.D(u_uart_master_core_u_host_bridge_tx_idx_d_1_),
    .Q(u_uart_master_core_u_host_bridge_tx_idx_q_1_),
    .RESET_B(net97),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3124_ (.D(u_uart_master_core_u_host_bridge_tx_idx_d_2_),
    .Q(u_uart_master_core_u_host_bridge_tx_idx_q_2_),
    .RESET_B(net97),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3125_ (.D(u_uart_master_core_u_host_bridge_tx_idx_d_3_),
    .Q(u_uart_master_core_u_host_bridge_tx_idx_q_3_),
    .RESET_B(net97),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3126_ (.D(u_reg_reset_sync_intq),
    .Q(reg_rst_ni),
    .RESET_B(rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3127_ (.D(net29),
    .Q(u_reg_reset_sync_intq),
    .RESET_B(rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _3127__30 (.HI(net29));
 sky130_fd_sc_hd__dfrtp_1 _3128_ (.D(u_core_reset_sync_intq),
    .Q(core_rst_ni),
    .RESET_B(rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _3129_ (.D(net30),
    .Q(u_core_reset_sync_intq),
    .RESET_B(rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _3129__31 (.HI(net30));
 sky130_fd_sc_hd__edfxtp_1 _3130_ (.D(net76),
    .DE(_0019_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_55_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3131_ (.D(net76),
    .DE(_0020_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_47_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3132_ (.D(net76),
    .DE(_0021_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_39_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3133_ (.D(net76),
    .DE(_0022_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_31_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3134_ (.D(net76),
    .DE(_0023_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_23_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3135_ (.D(net76),
    .DE(_0024_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_15_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3136_ (.D(net76),
    .DE(_0025_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_127_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3137_ (.D(net76),
    .DE(_0026_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_119_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3138_ (.D(net76),
    .DE(_0027_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_111_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3139_ (.D(net76),
    .DE(_0028_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_103_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3140_ (.D(net76),
    .DE(_0029_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_95_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3141_ (.D(net76),
    .DE(_0030_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_87_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3142_ (.D(net76),
    .DE(_0031_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_7_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3143_ (.D(u_uart_master_core_u_uart_core_tx_fifo_wdata_7_),
    .DE(_0032_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_39_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3144_ (.D(u_uart_master_core_u_uart_core_tx_fifo_wdata_7_),
    .DE(_0033_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_55_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3145_ (.D(u_uart_master_core_u_uart_core_tx_fifo_wdata_7_),
    .DE(_0034_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_47_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3146_ (.D(u_uart_master_core_u_uart_core_tx_fifo_wdata_7_),
    .DE(_0035_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_7_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3147_ (.D(u_uart_master_core_u_uart_core_tx_fifo_wdata_7_),
    .DE(_0036_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_63_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3148_ (.D(net76),
    .DE(_0037_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_63_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3149_ (.D(u_uart_master_core_u_uart_core_tx_fifo_wdata_7_),
    .DE(_0038_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_23_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3150_ (.D(u_uart_master_core_u_uart_core_tx_fifo_wdata_7_),
    .DE(_0039_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_15_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3151_ (.D(u_uart_master_core_u_uart_core_tx_fifo_wdata_7_),
    .DE(_0040_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_31_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3152_ (.D(net76),
    .DE(_0041_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_71_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3153_ (.D(net76),
    .DE(_0042_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_79_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3154_ (.D(net41),
    .DE(_0035_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_0_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3155_ (.D(net42),
    .DE(_0035_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_1_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3156_ (.D(net43),
    .DE(_0035_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_2_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3157_ (.D(net44),
    .DE(_0035_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_3_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3158_ (.D(net45),
    .DE(_0035_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_4_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3159_ (.D(net46),
    .DE(_0035_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_5_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3160_ (.D(net47),
    .DE(_0035_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_6_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3161_ (.D(net41),
    .DE(_0039_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_8_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3162_ (.D(net42),
    .DE(_0039_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_9_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3163_ (.D(net43),
    .DE(_0039_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_10_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3164_ (.D(net44),
    .DE(_0039_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_11_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3165_ (.D(net45),
    .DE(_0039_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_12_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3166_ (.D(net46),
    .DE(_0039_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_13_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3167_ (.D(net47),
    .DE(_0039_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_14_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3168_ (.D(net41),
    .DE(_0038_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_16_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3169_ (.D(net42),
    .DE(_0038_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_17_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3170_ (.D(net43),
    .DE(_0038_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_18_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3171_ (.D(net44),
    .DE(_0038_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_19_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3172_ (.D(net45),
    .DE(_0038_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_20_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3173_ (.D(net46),
    .DE(_0038_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_21_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3174_ (.D(net47),
    .DE(_0038_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_22_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3175_ (.D(net41),
    .DE(_0040_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_24_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3176_ (.D(net42),
    .DE(_0040_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_25_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3177_ (.D(net43),
    .DE(_0040_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_26_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3178_ (.D(net44),
    .DE(_0040_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_27_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3179_ (.D(net45),
    .DE(_0040_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_28_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3180_ (.D(net46),
    .DE(_0040_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_29_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3181_ (.D(net47),
    .DE(_0040_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_30_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3182_ (.D(net41),
    .DE(_0032_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_32_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3183_ (.D(net42),
    .DE(_0032_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_33_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3184_ (.D(net43),
    .DE(_0032_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_34_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3185_ (.D(net44),
    .DE(_0032_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_35_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3186_ (.D(net45),
    .DE(_0032_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_36_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3187_ (.D(net46),
    .DE(_0032_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_37_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3188_ (.D(net47),
    .DE(_0032_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_38_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3189_ (.D(net41),
    .DE(_0034_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_40_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3190_ (.D(net42),
    .DE(_0034_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_41_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3191_ (.D(net43),
    .DE(_0034_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_42_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3192_ (.D(net44),
    .DE(_0034_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_43_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3193_ (.D(net45),
    .DE(_0034_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_44_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3194_ (.D(net46),
    .DE(_0034_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_45_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3195_ (.D(net47),
    .DE(_0034_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_46_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3196_ (.D(net41),
    .DE(_0033_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_48_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3197_ (.D(net42),
    .DE(_0033_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_49_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3198_ (.D(net43),
    .DE(_0033_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_50_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3199_ (.D(net44),
    .DE(_0033_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_51_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3200_ (.D(net45),
    .DE(_0033_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_52_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3201_ (.D(net46),
    .DE(_0033_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_53_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3202_ (.D(net47),
    .DE(_0033_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_54_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3203_ (.D(net41),
    .DE(_0036_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_56_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3204_ (.D(net42),
    .DE(_0036_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_57_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3205_ (.D(net43),
    .DE(_0036_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_58_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3206_ (.D(net44),
    .DE(_0036_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_59_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3207_ (.D(net45),
    .DE(_0036_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_60_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3208_ (.D(net46),
    .DE(_0036_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_61_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3209_ (.D(net47),
    .DE(_0036_),
    .Q(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_62_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3210_ (.D(net71),
    .DE(_0042_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_72_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3211_ (.D(net67),
    .DE(_0042_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_73_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3212_ (.D(net77),
    .DE(_0042_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_74_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3213_ (.D(net78),
    .DE(_0042_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_75_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3214_ (.D(net69),
    .DE(_0042_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_76_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3215_ (.D(net70),
    .DE(_0042_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_77_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3216_ (.D(net75),
    .DE(_0042_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_78_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3217_ (.D(net71),
    .DE(_0041_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_64_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3218_ (.D(net67),
    .DE(_0041_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_65_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3219_ (.D(net77),
    .DE(_0041_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_66_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3220_ (.D(net78),
    .DE(_0041_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_67_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3221_ (.D(net69),
    .DE(_0041_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_68_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3222_ (.D(net70),
    .DE(_0041_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_69_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3223_ (.D(net75),
    .DE(_0041_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_70_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3224_ (.D(net71),
    .DE(_0037_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_56_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3225_ (.D(net67),
    .DE(_0037_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_57_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3226_ (.D(net77),
    .DE(_0037_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_58_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3227_ (.D(net78),
    .DE(_0037_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_59_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3228_ (.D(net69),
    .DE(_0037_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_60_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3229_ (.D(net70),
    .DE(_0037_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_61_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3230_ (.D(net75),
    .DE(_0037_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_62_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3231_ (.D(net71),
    .DE(_0031_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_0_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3232_ (.D(net67),
    .DE(_0031_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_1_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3233_ (.D(net77),
    .DE(_0031_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_2_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3234_ (.D(net78),
    .DE(_0031_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_3_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3235_ (.D(net69),
    .DE(_0031_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_4_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3236_ (.D(net70),
    .DE(_0031_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_5_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3237_ (.D(net75),
    .DE(_0031_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_6_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3238_ (.D(net71),
    .DE(_0030_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_80_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3239_ (.D(net67),
    .DE(_0030_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_81_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3240_ (.D(net77),
    .DE(_0030_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_82_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3241_ (.D(net78),
    .DE(_0030_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_83_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3242_ (.D(net69),
    .DE(_0030_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_84_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3243_ (.D(net70),
    .DE(_0030_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_85_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3244_ (.D(net75),
    .DE(_0030_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_86_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3245_ (.D(net71),
    .DE(_0029_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_88_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3246_ (.D(net67),
    .DE(_0029_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_89_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3247_ (.D(net77),
    .DE(_0029_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_90_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3248_ (.D(net78),
    .DE(_0029_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_91_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3249_ (.D(net69),
    .DE(_0029_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_92_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3250_ (.D(net70),
    .DE(_0029_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_93_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3251_ (.D(net75),
    .DE(_0029_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_94_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3252_ (.D(net71),
    .DE(_0028_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_96_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3253_ (.D(net67),
    .DE(_0028_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_97_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3254_ (.D(net77),
    .DE(_0028_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_98_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3255_ (.D(net78),
    .DE(_0028_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_99_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3256_ (.D(net69),
    .DE(_0028_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_100_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3257_ (.D(net70),
    .DE(_0028_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_101_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3258_ (.D(net75),
    .DE(_0028_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_102_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3259_ (.D(net71),
    .DE(_0027_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_104_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3260_ (.D(net67),
    .DE(_0027_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_105_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3261_ (.D(net77),
    .DE(_0027_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_106_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3262_ (.D(net78),
    .DE(_0027_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_107_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3263_ (.D(net69),
    .DE(_0027_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_108_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3264_ (.D(net70),
    .DE(_0027_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_109_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3265_ (.D(net75),
    .DE(_0027_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_110_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3266_ (.D(net71),
    .DE(_0026_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_112_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3267_ (.D(net67),
    .DE(_0026_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_113_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3268_ (.D(net77),
    .DE(_0026_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_114_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3269_ (.D(net78),
    .DE(_0026_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_115_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3270_ (.D(net69),
    .DE(_0026_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_116_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3271_ (.D(net70),
    .DE(_0026_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_117_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3272_ (.D(net75),
    .DE(_0026_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_118_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3273_ (.D(net71),
    .DE(_0025_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_120_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3274_ (.D(net67),
    .DE(_0025_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_121_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3275_ (.D(net77),
    .DE(_0025_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_122_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3276_ (.D(net78),
    .DE(_0025_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_123_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3277_ (.D(net69),
    .DE(_0025_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_124_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3278_ (.D(net70),
    .DE(_0025_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_125_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3279_ (.D(net75),
    .DE(_0025_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_126_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3280_ (.D(net71),
    .DE(_0024_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_8_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3281_ (.D(net67),
    .DE(_0024_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_9_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3282_ (.D(net77),
    .DE(_0024_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_10_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3283_ (.D(net78),
    .DE(_0024_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_11_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3284_ (.D(net69),
    .DE(_0024_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_12_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3285_ (.D(net70),
    .DE(_0024_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_13_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3286_ (.D(net75),
    .DE(_0024_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_14_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3287_ (.D(net71),
    .DE(_0023_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_16_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3288_ (.D(net67),
    .DE(_0023_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_17_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3289_ (.D(net77),
    .DE(_0023_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_18_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3290_ (.D(net78),
    .DE(_0023_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_19_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3291_ (.D(net69),
    .DE(_0023_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_20_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3292_ (.D(net70),
    .DE(_0023_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_21_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3293_ (.D(net75),
    .DE(_0023_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_22_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3294_ (.D(net71),
    .DE(_0022_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_24_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3295_ (.D(net67),
    .DE(_0022_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_25_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3296_ (.D(net77),
    .DE(_0022_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_26_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3297_ (.D(net78),
    .DE(_0022_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_27_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3298_ (.D(net69),
    .DE(_0022_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_28_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3299_ (.D(net70),
    .DE(_0022_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_29_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3300_ (.D(net75),
    .DE(_0022_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_30_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3301_ (.D(net71),
    .DE(_0021_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_32_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3302_ (.D(net67),
    .DE(_0021_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_33_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3303_ (.D(net77),
    .DE(_0021_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_34_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3304_ (.D(net78),
    .DE(_0021_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_35_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3305_ (.D(net69),
    .DE(_0021_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_36_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3306_ (.D(net70),
    .DE(_0021_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_37_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3307_ (.D(net75),
    .DE(_0021_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_38_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3308_ (.D(net71),
    .DE(_0020_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_40_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3309_ (.D(net67),
    .DE(_0020_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_41_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3310_ (.D(net77),
    .DE(_0020_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_42_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3311_ (.D(net78),
    .DE(_0020_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_43_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3312_ (.D(net69),
    .DE(_0020_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_44_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3313_ (.D(net70),
    .DE(_0020_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_45_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3314_ (.D(net75),
    .DE(_0020_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_46_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3315_ (.D(net71),
    .DE(_0019_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_48_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3316_ (.D(net67),
    .DE(_0019_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_49_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3317_ (.D(net77),
    .DE(_0019_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_50_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3318_ (.D(net78),
    .DE(_0019_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_51_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3319_ (.D(net69),
    .DE(_0019_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_52_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3320_ (.D(net70),
    .DE(_0019_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_53_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _3321_ (.D(net75),
    .DE(_0019_),
    .Q(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_54_),
    .CLK(clk_i));
 sky130_fd_sc_hd__buf_2 _3324_ (.A(u_uart_master_core_u_host_bridge_wdata_o_0_),
    .X(wdata_o[0]));
 sky130_fd_sc_hd__buf_2 _3325_ (.A(u_uart_master_core_u_host_bridge_wdata_o_1_),
    .X(wdata_o[1]));
 sky130_fd_sc_hd__buf_2 _3326_ (.A(u_uart_master_core_u_host_bridge_wdata_o_2_),
    .X(wdata_o[2]));
 sky130_fd_sc_hd__buf_2 _3327_ (.A(u_uart_master_core_u_host_bridge_wdata_o_3_),
    .X(wdata_o[3]));
 sky130_fd_sc_hd__buf_2 _3328_ (.A(u_uart_master_core_u_host_bridge_wdata_o_4_),
    .X(wdata_o[4]));
 sky130_fd_sc_hd__buf_2 _3329_ (.A(u_uart_master_core_u_host_bridge_wdata_o_5_),
    .X(wdata_o[5]));
 sky130_fd_sc_hd__buf_2 _3330_ (.A(u_uart_master_core_u_host_bridge_wdata_o_6_),
    .X(wdata_o[6]));
 sky130_fd_sc_hd__buf_2 _3331_ (.A(u_uart_master_core_u_host_bridge_wdata_o_7_),
    .X(wdata_o[7]));
 sky130_fd_sc_hd__buf_2 _3332_ (.A(u_uart_master_core_u_host_bridge_wdata_o_8_),
    .X(wdata_o[8]));
 sky130_fd_sc_hd__buf_2 _3333_ (.A(u_uart_master_core_u_host_bridge_wdata_o_9_),
    .X(wdata_o[9]));
 sky130_fd_sc_hd__buf_2 _3334_ (.A(u_uart_master_core_u_host_bridge_wdata_o_10_),
    .X(wdata_o[10]));
 sky130_fd_sc_hd__buf_2 _3335_ (.A(u_uart_master_core_u_host_bridge_wdata_o_11_),
    .X(wdata_o[11]));
 sky130_fd_sc_hd__buf_2 _3336_ (.A(u_uart_master_core_u_host_bridge_wdata_o_12_),
    .X(wdata_o[12]));
 sky130_fd_sc_hd__buf_2 _3337_ (.A(u_uart_master_core_u_host_bridge_wdata_o_13_),
    .X(wdata_o[13]));
 sky130_fd_sc_hd__buf_2 _3338_ (.A(u_uart_master_core_u_host_bridge_wdata_o_14_),
    .X(wdata_o[14]));
 sky130_fd_sc_hd__buf_2 _3339_ (.A(u_uart_master_core_u_host_bridge_wdata_o_15_),
    .X(wdata_o[15]));
 sky130_fd_sc_hd__buf_2 _3340_ (.A(u_uart_master_core_u_host_bridge_wdata_o_16_),
    .X(wdata_o[16]));
 sky130_fd_sc_hd__buf_2 _3341_ (.A(u_uart_master_core_u_host_bridge_wdata_o_17_),
    .X(wdata_o[17]));
 sky130_fd_sc_hd__buf_2 _3342_ (.A(u_uart_master_core_u_host_bridge_wdata_o_18_),
    .X(wdata_o[18]));
 sky130_fd_sc_hd__buf_2 _3343_ (.A(u_uart_master_core_u_host_bridge_wdata_o_19_),
    .X(wdata_o[19]));
 sky130_fd_sc_hd__buf_2 _3344_ (.A(u_uart_master_core_u_host_bridge_wdata_o_20_),
    .X(wdata_o[20]));
 sky130_fd_sc_hd__buf_2 _3345_ (.A(u_uart_master_core_u_host_bridge_wdata_o_21_),
    .X(wdata_o[21]));
 sky130_fd_sc_hd__buf_2 _3346_ (.A(u_uart_master_core_u_host_bridge_wdata_o_22_),
    .X(wdata_o[22]));
 sky130_fd_sc_hd__buf_2 _3347_ (.A(u_uart_master_core_u_host_bridge_wdata_o_23_),
    .X(wdata_o[23]));
 sky130_fd_sc_hd__buf_2 _3348_ (.A(u_uart_master_core_u_host_bridge_wdata_o_24_),
    .X(wdata_o[24]));
 sky130_fd_sc_hd__buf_2 _3349_ (.A(u_uart_master_core_u_host_bridge_wdata_o_25_),
    .X(wdata_o[25]));
 sky130_fd_sc_hd__buf_2 _3350_ (.A(u_uart_master_core_u_host_bridge_wdata_o_26_),
    .X(wdata_o[26]));
 sky130_fd_sc_hd__buf_2 _3351_ (.A(u_uart_master_core_u_host_bridge_wdata_o_27_),
    .X(wdata_o[27]));
 sky130_fd_sc_hd__buf_2 _3352_ (.A(u_uart_master_core_u_host_bridge_wdata_o_28_),
    .X(wdata_o[28]));
 sky130_fd_sc_hd__buf_2 _3353_ (.A(u_uart_master_core_u_host_bridge_wdata_o_29_),
    .X(wdata_o[29]));
 sky130_fd_sc_hd__buf_2 _3354_ (.A(u_uart_master_core_u_host_bridge_wdata_o_30_),
    .X(wdata_o[30]));
 sky130_fd_sc_hd__buf_2 _3355_ (.A(u_uart_master_core_u_host_bridge_wdata_o_31_),
    .X(wdata_o[31]));
 sky130_fd_sc_hd__buf_2 _3356_ (.A(u_uart_master_reg_tl_o_0_),
    .X(tl_o[0]));
 sky130_fd_sc_hd__buf_2 _3357_ (.A(u_uart_master_reg_tl_o_1_),
    .X(tl_o[1]));
 sky130_fd_sc_hd__buf_4 _3358_ (.A(net2),
    .X(tl_o[2]));
 sky130_fd_sc_hd__conb_1 _3358__3 (.LO(net2));
 sky130_fd_sc_hd__buf_4 _3359_ (.A(net3),
    .X(tl_o[3]));
 sky130_fd_sc_hd__conb_1 _3359__4 (.LO(net3));
 sky130_fd_sc_hd__buf_4 _3360_ (.A(net4),
    .X(tl_o[4]));
 sky130_fd_sc_hd__conb_1 _3360__5 (.LO(net4));
 sky130_fd_sc_hd__buf_4 _3361_ (.A(net5),
    .X(tl_o[5]));
 sky130_fd_sc_hd__conb_1 _3361__6 (.LO(net5));
 sky130_fd_sc_hd__buf_4 _3362_ (.A(net6),
    .X(tl_o[6]));
 sky130_fd_sc_hd__conb_1 _3362__7 (.LO(net6));
 sky130_fd_sc_hd__buf_4 _3363_ (.A(net7),
    .X(tl_o[7]));
 sky130_fd_sc_hd__conb_1 _3363__8 (.LO(net7));
 sky130_fd_sc_hd__buf_4 _3364_ (.A(net8),
    .X(tl_o[8]));
 sky130_fd_sc_hd__conb_1 _3364__9 (.LO(net8));
 sky130_fd_sc_hd__buf_4 _3365_ (.A(net9),
    .X(tl_o[9]));
 sky130_fd_sc_hd__conb_1 _3365__10 (.LO(net9));
 sky130_fd_sc_hd__buf_4 _3366_ (.A(net10),
    .X(tl_o[10]));
 sky130_fd_sc_hd__conb_1 _3366__11 (.LO(net10));
 sky130_fd_sc_hd__buf_4 _3367_ (.A(net11),
    .X(tl_o[11]));
 sky130_fd_sc_hd__conb_1 _3367__12 (.LO(net11));
 sky130_fd_sc_hd__buf_4 _3368_ (.A(net12),
    .X(tl_o[12]));
 sky130_fd_sc_hd__conb_1 _3368__13 (.LO(net12));
 sky130_fd_sc_hd__buf_4 _3369_ (.A(net13),
    .X(tl_o[13]));
 sky130_fd_sc_hd__conb_1 _3369__14 (.LO(net13));
 sky130_fd_sc_hd__buf_4 _3370_ (.A(net14),
    .X(tl_o[14]));
 sky130_fd_sc_hd__conb_1 _3370__15 (.LO(net14));
 sky130_fd_sc_hd__buf_4 _3371_ (.A(net15),
    .X(tl_o[15]));
 sky130_fd_sc_hd__conb_1 _3371__16 (.LO(net15));
 sky130_fd_sc_hd__buf_2 _3372_ (.A(u_uart_master_reg_tl_o_16_),
    .X(tl_o[16]));
 sky130_fd_sc_hd__buf_2 _3373_ (.A(u_uart_master_reg_tl_o_17_),
    .X(tl_o[17]));
 sky130_fd_sc_hd__buf_2 _3374_ (.A(u_uart_master_reg_tl_o_18_),
    .X(tl_o[18]));
 sky130_fd_sc_hd__buf_2 _3375_ (.A(u_uart_master_reg_tl_o_19_),
    .X(tl_o[19]));
 sky130_fd_sc_hd__buf_2 _3376_ (.A(u_uart_master_reg_tl_o_20_),
    .X(tl_o[20]));
 sky130_fd_sc_hd__buf_2 _3377_ (.A(u_uart_master_reg_tl_o_21_),
    .X(tl_o[21]));
 sky130_fd_sc_hd__buf_2 _3378_ (.A(u_uart_master_reg_tl_o_22_),
    .X(tl_o[22]));
 sky130_fd_sc_hd__buf_2 _3379_ (.A(u_uart_master_reg_tl_o_23_),
    .X(tl_o[23]));
 sky130_fd_sc_hd__buf_2 _3380_ (.A(u_uart_master_reg_tl_o_24_),
    .X(tl_o[24]));
 sky130_fd_sc_hd__buf_2 _3381_ (.A(u_uart_master_reg_tl_o_25_),
    .X(tl_o[25]));
 sky130_fd_sc_hd__buf_2 _3382_ (.A(u_uart_master_reg_tl_o_26_),
    .X(tl_o[26]));
 sky130_fd_sc_hd__buf_2 _3383_ (.A(u_uart_master_reg_tl_o_27_),
    .X(tl_o[27]));
 sky130_fd_sc_hd__buf_2 _3384_ (.A(u_uart_master_reg_tl_o_28_),
    .X(tl_o[28]));
 sky130_fd_sc_hd__buf_2 _3385_ (.A(u_uart_master_reg_tl_o_29_),
    .X(tl_o[29]));
 sky130_fd_sc_hd__buf_2 _3386_ (.A(u_uart_master_reg_tl_o_30_),
    .X(tl_o[30]));
 sky130_fd_sc_hd__buf_2 _3387_ (.A(u_uart_master_reg_tl_o_31_),
    .X(tl_o[31]));
 sky130_fd_sc_hd__buf_2 _3388_ (.A(u_uart_master_reg_tl_o_32_),
    .X(tl_o[32]));
 sky130_fd_sc_hd__buf_2 _3389_ (.A(u_uart_master_reg_tl_o_33_),
    .X(tl_o[33]));
 sky130_fd_sc_hd__buf_2 _3390_ (.A(u_uart_master_reg_tl_o_34_),
    .X(tl_o[34]));
 sky130_fd_sc_hd__buf_2 _3391_ (.A(u_uart_master_reg_tl_o_35_),
    .X(tl_o[35]));
 sky130_fd_sc_hd__buf_2 _3392_ (.A(u_uart_master_reg_tl_o_36_),
    .X(tl_o[36]));
 sky130_fd_sc_hd__buf_2 _3393_ (.A(u_uart_master_reg_tl_o_37_),
    .X(tl_o[37]));
 sky130_fd_sc_hd__buf_2 _3394_ (.A(u_uart_master_reg_tl_o_38_),
    .X(tl_o[38]));
 sky130_fd_sc_hd__buf_2 _3395_ (.A(u_uart_master_reg_tl_o_39_),
    .X(tl_o[39]));
 sky130_fd_sc_hd__buf_2 _3396_ (.A(u_uart_master_reg_tl_o_40_),
    .X(tl_o[40]));
 sky130_fd_sc_hd__buf_2 _3397_ (.A(u_uart_master_reg_tl_o_41_),
    .X(tl_o[41]));
 sky130_fd_sc_hd__buf_2 _3398_ (.A(u_uart_master_reg_tl_o_42_),
    .X(tl_o[42]));
 sky130_fd_sc_hd__buf_2 _3399_ (.A(u_uart_master_reg_tl_o_43_),
    .X(tl_o[43]));
 sky130_fd_sc_hd__buf_2 _3400_ (.A(u_uart_master_reg_tl_o_44_),
    .X(tl_o[44]));
 sky130_fd_sc_hd__buf_2 _3401_ (.A(u_uart_master_reg_tl_o_45_),
    .X(tl_o[45]));
 sky130_fd_sc_hd__buf_2 _3402_ (.A(u_uart_master_reg_tl_o_46_),
    .X(tl_o[46]));
 sky130_fd_sc_hd__buf_2 _3403_ (.A(u_uart_master_reg_tl_o_47_),
    .X(tl_o[47]));
 sky130_fd_sc_hd__buf_4 _3404_ (.A(net16),
    .X(tl_o[48]));
 sky130_fd_sc_hd__conb_1 _3404__17 (.LO(net16));
 sky130_fd_sc_hd__buf_2 _3405_ (.A(u_uart_master_reg_tl_o_49_),
    .X(tl_o[49]));
 sky130_fd_sc_hd__buf_2 _3406_ (.A(u_uart_master_reg_tl_o_50_),
    .X(tl_o[50]));
 sky130_fd_sc_hd__buf_2 _3407_ (.A(u_uart_master_reg_tl_o_51_),
    .X(tl_o[51]));
 sky130_fd_sc_hd__buf_2 _3408_ (.A(u_uart_master_reg_tl_o_52_),
    .X(tl_o[52]));
 sky130_fd_sc_hd__buf_2 _3409_ (.A(u_uart_master_reg_tl_o_53_),
    .X(tl_o[53]));
 sky130_fd_sc_hd__buf_2 _3410_ (.A(u_uart_master_reg_tl_o_54_),
    .X(tl_o[54]));
 sky130_fd_sc_hd__buf_2 _3411_ (.A(u_uart_master_reg_tl_o_55_),
    .X(tl_o[55]));
 sky130_fd_sc_hd__buf_2 _3412_ (.A(u_uart_master_reg_tl_o_56_),
    .X(tl_o[56]));
 sky130_fd_sc_hd__buf_2 _3413_ (.A(u_uart_master_reg_tl_o_57_),
    .X(tl_o[57]));
 sky130_fd_sc_hd__buf_2 _3414_ (.A(u_uart_master_reg_tl_o_58_),
    .X(tl_o[58]));
 sky130_fd_sc_hd__buf_4 _3415_ (.A(net17),
    .X(tl_o[59]));
 sky130_fd_sc_hd__conb_1 _3415__18 (.LO(net17));
 sky130_fd_sc_hd__buf_4 _3416_ (.A(net18),
    .X(tl_o[60]));
 sky130_fd_sc_hd__conb_1 _3416__19 (.LO(net18));
 sky130_fd_sc_hd__buf_4 _3417_ (.A(net19),
    .X(tl_o[61]));
 sky130_fd_sc_hd__conb_1 _3417__20 (.LO(net19));
 sky130_fd_sc_hd__buf_2 _3418_ (.A(u_uart_master_reg_tl_o_62_),
    .X(tl_o[62]));
 sky130_fd_sc_hd__buf_4 _3419_ (.A(net20),
    .X(tl_o[63]));
 sky130_fd_sc_hd__conb_1 _3419__21 (.LO(net20));
 sky130_fd_sc_hd__buf_4 _3420_ (.A(net21),
    .X(tl_o[64]));
 sky130_fd_sc_hd__conb_1 _3420__22 (.LO(net21));
 sky130_fd_sc_hd__buf_2 _3421_ (.A(u_uart_master_reg_tl_o_65_),
    .X(tl_o[65]));
 sky130_fd_sc_hd__buf_4 _3422_ (.A(net31),
    .X(cio_tx_en_o));
 sky130_fd_sc_hd__conb_1 _3422__32 (.HI(net31));
 sky130_fd_sc_hd__buf_2 _3423_ (.A(u_uart_master_core_be_o_0_),
    .X(be_o[0]));
 sky130_fd_sc_hd__buf_2 _3424_ (.A(u_uart_master_core_be_o_1_),
    .X(be_o[1]));
 sky130_fd_sc_hd__buf_2 _3425_ (.A(u_uart_master_core_be_o_2_),
    .X(be_o[2]));
 sky130_fd_sc_hd__buf_2 _3426_ (.A(u_uart_master_core_be_o_3_),
    .X(be_o[3]));
 sky130_fd_sc_hd__buf_4 _3427_ (.A(net22),
    .X(addr_o[0]));
 sky130_fd_sc_hd__conb_1 _3427__23 (.LO(net22));
 sky130_fd_sc_hd__buf_4 _3428_ (.A(net23),
    .X(addr_o[1]));
 sky130_fd_sc_hd__conb_1 _3428__24 (.LO(net23));
 sky130_fd_sc_hd__buf_2 _3429_ (.A(u_uart_master_core_addr_o_2_),
    .X(addr_o[2]));
 sky130_fd_sc_hd__buf_2 _3430_ (.A(u_uart_master_core_addr_o_3_),
    .X(addr_o[3]));
 sky130_fd_sc_hd__buf_2 _3431_ (.A(u_uart_master_core_addr_o_4_),
    .X(addr_o[4]));
 sky130_fd_sc_hd__buf_2 _3432_ (.A(u_uart_master_core_addr_o_5_),
    .X(addr_o[5]));
 sky130_fd_sc_hd__buf_2 _3433_ (.A(u_uart_master_core_addr_o_6_),
    .X(addr_o[6]));
 sky130_fd_sc_hd__buf_2 _3434_ (.A(u_uart_master_core_addr_o_7_),
    .X(addr_o[7]));
 sky130_fd_sc_hd__buf_2 _3435_ (.A(u_uart_master_core_addr_o_8_),
    .X(addr_o[8]));
 sky130_fd_sc_hd__buf_2 _3436_ (.A(u_uart_master_core_addr_o_9_),
    .X(addr_o[9]));
 sky130_fd_sc_hd__buf_2 _3437_ (.A(u_uart_master_core_addr_o_10_),
    .X(addr_o[10]));
 sky130_fd_sc_hd__buf_2 _3438_ (.A(u_uart_master_core_addr_o_11_),
    .X(addr_o[11]));
 sky130_fd_sc_hd__buf_2 _3439_ (.A(u_uart_master_core_addr_o_12_),
    .X(addr_o[12]));
 sky130_fd_sc_hd__buf_2 _3440_ (.A(u_uart_master_core_addr_o_13_),
    .X(addr_o[13]));
 sky130_fd_sc_hd__buf_2 _3441_ (.A(u_uart_master_core_addr_o_14_),
    .X(addr_o[14]));
 sky130_fd_sc_hd__buf_2 _3442_ (.A(u_uart_master_core_addr_o_15_),
    .X(addr_o[15]));
 sky130_fd_sc_hd__buf_2 _3443_ (.A(u_uart_master_core_addr_o_16_),
    .X(addr_o[16]));
 sky130_fd_sc_hd__buf_2 _3444_ (.A(u_uart_master_core_addr_o_17_),
    .X(addr_o[17]));
 sky130_fd_sc_hd__buf_2 _3445_ (.A(u_uart_master_core_addr_o_18_),
    .X(addr_o[18]));
 sky130_fd_sc_hd__buf_2 _3446_ (.A(u_uart_master_core_addr_o_19_),
    .X(addr_o[19]));
 sky130_fd_sc_hd__buf_2 _3447_ (.A(u_uart_master_core_addr_o_20_),
    .X(addr_o[20]));
 sky130_fd_sc_hd__buf_2 _3448_ (.A(u_uart_master_core_addr_o_21_),
    .X(addr_o[21]));
 sky130_fd_sc_hd__buf_2 _3449_ (.A(u_uart_master_core_addr_o_22_),
    .X(addr_o[22]));
 sky130_fd_sc_hd__buf_2 _3450_ (.A(u_uart_master_core_addr_o_23_),
    .X(addr_o[23]));
 sky130_fd_sc_hd__buf_2 _3451_ (.A(u_uart_master_core_addr_o_24_),
    .X(addr_o[24]));
 sky130_fd_sc_hd__buf_2 _3452_ (.A(u_uart_master_core_addr_o_25_),
    .X(addr_o[25]));
 sky130_fd_sc_hd__buf_2 _3453_ (.A(u_uart_master_core_addr_o_26_),
    .X(addr_o[26]));
 sky130_fd_sc_hd__buf_2 _3454_ (.A(u_uart_master_core_addr_o_27_),
    .X(addr_o[27]));
 sky130_fd_sc_hd__buf_2 _3455_ (.A(u_uart_master_core_addr_o_28_),
    .X(addr_o[28]));
 sky130_fd_sc_hd__buf_2 _3456_ (.A(u_uart_master_core_addr_o_29_),
    .X(addr_o[29]));
 sky130_fd_sc_hd__buf_2 _3457_ (.A(u_uart_master_core_addr_o_30_),
    .X(addr_o[30]));
 sky130_fd_sc_hd__buf_2 _3458_ (.A(u_uart_master_core_addr_o_31_),
    .X(addr_o[31]));
 sky130_fd_sc_hd__buf_2 gain100 (.A(u_uart_master_core_u_uart_core_nco_sum_q_16_),
    .X(net99));
 sky130_fd_sc_hd__buf_12 gain101 (.A(net103),
    .X(net100));
 sky130_fd_sc_hd__buf_12 gain102 (.A(net103),
    .X(net101));
 sky130_fd_sc_hd__buf_12 gain103 (.A(net103),
    .X(net102));
 sky130_fd_sc_hd__buf_12 gain104 (.A(u_uart_master_core_u_uart_core_rst_ni),
    .X(net103));
 sky130_fd_sc_hd__buf_12 gain105 (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_),
    .X(net104));
 sky130_fd_sc_hd__buf_12 gain106 (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_),
    .X(net105));
 sky130_fd_sc_hd__buf_12 gain107 (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_),
    .X(net106));
 sky130_fd_sc_hd__buf_4 gain108 (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_0_),
    .X(net107));
 sky130_fd_sc_hd__buf_12 gain109 (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_),
    .X(net108));
 sky130_fd_sc_hd__buf_12 gain110 (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_),
    .X(net109));
 sky130_fd_sc_hd__buf_4 gain111 (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_1_),
    .X(net110));
 sky130_fd_sc_hd__buf_2 gain112 (.A(u_uart_master_core_u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_0_),
    .X(net111));
 sky130_fd_sc_hd__buf_4 gain113 (.A(u_uart_master_core_u_host_bridge_rxf_st_q_2_),
    .X(net112));
 sky130_fd_sc_hd__buf_4 gain114 (.A(u_uart_master_core_u_host_bridge_rxf_st_q_1_),
    .X(net113));
 sky130_fd_sc_hd__buf_2 gain115 (.A(u_uart_master_core_u_host_bridge_rxf_st_q_0_),
    .X(net114));
 sky130_fd_sc_hd__buf_2 gain116 (.A(reg2hw_34_),
    .X(net115));
 sky130_fd_sc_hd__buf_2 gain117 (.A(reg2hw_40_),
    .X(net116));
 sky130_fd_sc_hd__buf_12 gain118 (.A(reg2hw_39_),
    .X(net117));
 sky130_fd_sc_hd__buf_2 gain119 (.A(reg2hw_51_),
    .X(net118));
 sky130_fd_sc_hd__buf_2 gain120 (.A(reg2hw_46_),
    .X(net119));
 sky130_fd_sc_hd__buf_2 gain121 (.A(reg2hw_45_),
    .X(net120));
 sky130_fd_sc_hd__buf_2 gain122 (.A(reg2hw_44_),
    .X(net121));
 sky130_fd_sc_hd__buf_2 gain123 (.A(reg2hw_43_),
    .X(net122));
 sky130_fd_sc_hd__buf_2 gain124 (.A(reg2hw_41_),
    .X(net123));
 sky130_fd_sc_hd__buf_2 gain125 (.A(reg2hw_38_),
    .X(net124));
 sky130_fd_sc_hd__buf_2 gain126 (.A(u_uart_master_core_u_uart_core_uart_rx_sreg_q_8_),
    .X(net125));
 sky130_fd_sc_hd__buf_2 gain127 (.A(u_uart_master_core_u_uart_core_uart_rx_sreg_q_7_),
    .X(net126));
 sky130_fd_sc_hd__buf_2 gain128 (.A(u_uart_master_core_u_uart_core_uart_rx_sreg_q_6_),
    .X(net127));
 sky130_fd_sc_hd__buf_2 gain129 (.A(u_uart_master_core_u_uart_core_uart_rx_sreg_q_5_),
    .X(net128));
 sky130_fd_sc_hd__buf_2 gain130 (.A(u_uart_master_core_u_uart_core_uart_rx_sreg_q_4_),
    .X(net129));
 sky130_fd_sc_hd__buf_2 gain131 (.A(u_uart_master_core_u_uart_core_uart_rx_sreg_q_3_),
    .X(net130));
 sky130_fd_sc_hd__buf_2 gain132 (.A(u_uart_master_core_u_uart_core_uart_rx_sreg_q_2_),
    .X(net131));
 sky130_fd_sc_hd__buf_2 gain133 (.A(u_uart_master_core_u_uart_core_uart_rx_bit_cnt_q_3_),
    .X(net132));
 sky130_fd_sc_hd__buf_2 gain134 (.A(u_uart_master_core_u_uart_core_uart_rx_bit_cnt_q_1_),
    .X(net133));
 sky130_fd_sc_hd__buf_2 gain135 (.A(u_uart_master_core_u_uart_core_uart_rx_bit_cnt_q_0_),
    .X(net134));
 sky130_fd_sc_hd__buf_12 gain136 (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_),
    .X(net135));
 sky130_fd_sc_hd__buf_12 gain137 (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_),
    .X(net136));
 sky130_fd_sc_hd__buf_2 gain138 (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_0_),
    .X(net137));
 sky130_fd_sc_hd__buf_12 gain139 (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_2_),
    .X(net138));
 sky130_fd_sc_hd__buf_12 gain140 (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_),
    .X(net139));
 sky130_fd_sc_hd__buf_12 gain141 (.A(u_uart_master_core_u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .X(net140));
 sky130_fd_sc_hd__buf_12 gain33 (.A(_0751_),
    .X(net32));
 sky130_fd_sc_hd__buf_12 gain34 (.A(_0583_),
    .X(net33));
 sky130_fd_sc_hd__buf_12 gain35 (.A(_0352_),
    .X(net34));
 sky130_fd_sc_hd__buf_12 gain36 (.A(_0320_),
    .X(net35));
 sky130_fd_sc_hd__buf_12 gain37 (.A(_0747_),
    .X(net36));
 sky130_fd_sc_hd__buf_12 gain38 (.A(_0591_),
    .X(net37));
 sky130_fd_sc_hd__buf_12 gain39 (.A(_0875_),
    .X(net38));
 sky130_fd_sc_hd__buf_12 gain40 (.A(net40),
    .X(net39));
 sky130_fd_sc_hd__buf_2 gain41 (.A(_0874_),
    .X(net40));
 sky130_fd_sc_hd__buf_2 gain42 (.A(u_uart_master_core_u_uart_core_tx_fifo_wdata_0_),
    .X(net41));
 sky130_fd_sc_hd__buf_2 gain43 (.A(u_uart_master_core_u_uart_core_tx_fifo_wdata_1_),
    .X(net42));
 sky130_fd_sc_hd__buf_2 gain44 (.A(u_uart_master_core_u_uart_core_tx_fifo_wdata_2_),
    .X(net43));
 sky130_fd_sc_hd__buf_2 gain45 (.A(u_uart_master_core_u_uart_core_tx_fifo_wdata_3_),
    .X(net44));
 sky130_fd_sc_hd__buf_2 gain46 (.A(u_uart_master_core_u_uart_core_tx_fifo_wdata_4_),
    .X(net45));
 sky130_fd_sc_hd__buf_2 gain47 (.A(u_uart_master_core_u_uart_core_tx_fifo_wdata_5_),
    .X(net46));
 sky130_fd_sc_hd__buf_2 gain48 (.A(u_uart_master_core_u_uart_core_tx_fifo_wdata_6_),
    .X(net47));
 sky130_fd_sc_hd__buf_4 gain49 (.A(_0867_),
    .X(net48));
 sky130_fd_sc_hd__buf_12 gain50 (.A(_0853_),
    .X(net49));
 sky130_fd_sc_hd__buf_2 gain51 (.A(_0626_),
    .X(net50));
 sky130_fd_sc_hd__buf_12 gain52 (.A(_0346_),
    .X(net51));
 sky130_fd_sc_hd__buf_12 gain53 (.A(_0937_),
    .X(net52));
 sky130_fd_sc_hd__buf_12 gain54 (.A(u_uart_master_reg_u_reg_core_reg_we_check_3_),
    .X(net53));
 sky130_fd_sc_hd__buf_2 gain55 (.A(_0660_),
    .X(net54));
 sky130_fd_sc_hd__buf_2 gain56 (.A(_0936_),
    .X(net55));
 sky130_fd_sc_hd__buf_12 gain57 (.A(_1074_),
    .X(net56));
 sky130_fd_sc_hd__buf_12 gain58 (.A(_0964_),
    .X(net57));
 sky130_fd_sc_hd__buf_12 gain59 (.A(net59),
    .X(net58));
 sky130_fd_sc_hd__buf_2 gain60 (.A(_0793_),
    .X(net59));
 sky130_fd_sc_hd__buf_12 gain61 (.A(net61),
    .X(net60));
 sky130_fd_sc_hd__buf_2 gain62 (.A(_0946_),
    .X(net61));
 sky130_fd_sc_hd__buf_12 gain63 (.A(_0526_),
    .X(net62));
 sky130_fd_sc_hd__buf_12 gain64 (.A(_0554_),
    .X(net63));
 sky130_fd_sc_hd__buf_12 gain65 (.A(_0549_),
    .X(net64));
 sky130_fd_sc_hd__buf_12 gain66 (.A(_1061_),
    .X(net65));
 sky130_fd_sc_hd__buf_12 gain67 (.A(_0910_),
    .X(net66));
 sky130_fd_sc_hd__buf_12 gain68 (.A(u_uart_master_core_u_uart_core_rx_fifo_data_1_),
    .X(net67));
 sky130_fd_sc_hd__buf_12 gain69 (.A(_0527_),
    .X(net68));
 sky130_fd_sc_hd__buf_12 gain70 (.A(u_uart_master_core_u_uart_core_rx_fifo_data_4_),
    .X(net69));
 sky130_fd_sc_hd__buf_12 gain71 (.A(u_uart_master_core_u_uart_core_rx_fifo_data_5_),
    .X(net70));
 sky130_fd_sc_hd__buf_12 gain72 (.A(u_uart_master_core_u_uart_core_rx_fifo_data_0_),
    .X(net71));
 sky130_fd_sc_hd__buf_12 gain73 (.A(_0353_),
    .X(net72));
 sky130_fd_sc_hd__buf_12 gain74 (.A(_0347_),
    .X(net73));
 sky130_fd_sc_hd__buf_12 gain75 (.A(_1352_),
    .X(net74));
 sky130_fd_sc_hd__buf_12 gain76 (.A(u_uart_master_core_u_uart_core_rx_fifo_data_6_),
    .X(net75));
 sky130_fd_sc_hd__buf_12 gain77 (.A(u_uart_master_core_u_uart_core_rx_fifo_data_7_),
    .X(net76));
 sky130_fd_sc_hd__buf_12 gain78 (.A(u_uart_master_core_u_uart_core_rx_fifo_data_2_),
    .X(net77));
 sky130_fd_sc_hd__buf_12 gain79 (.A(u_uart_master_core_u_uart_core_rx_fifo_data_3_),
    .X(net78));
 sky130_fd_sc_hd__buf_2 gain80 (.A(_0371_),
    .X(net79));
 sky130_fd_sc_hd__buf_12 gain81 (.A(_0321_),
    .X(net80));
 sky130_fd_sc_hd__buf_12 gain82 (.A(_1066_),
    .X(net81));
 sky130_fd_sc_hd__buf_12 gain83 (.A(net85),
    .X(net82));
 sky130_fd_sc_hd__buf_12 gain84 (.A(net85),
    .X(net83));
 sky130_fd_sc_hd__buf_12 gain85 (.A(net85),
    .X(net84));
 sky130_fd_sc_hd__buf_12 gain86 (.A(reg_rst_ni),
    .X(net85));
 sky130_fd_sc_hd__buf_4 gain87 (.A(u_uart_master_core_u_host_bridge_tx_idx_q_3_),
    .X(net86));
 sky130_fd_sc_hd__buf_4 gain88 (.A(u_uart_master_core_u_host_bridge_tx_idx_q_2_),
    .X(net87));
 sky130_fd_sc_hd__buf_2 gain89 (.A(u_uart_master_core_u_host_bridge_tx_idx_q_1_),
    .X(net88));
 sky130_fd_sc_hd__buf_2 gain90 (.A(u_uart_master_core_u_host_bridge_tx_idx_q_0_),
    .X(net89));
 sky130_fd_sc_hd__buf_12 gain91 (.A(net92),
    .X(net90));
 sky130_fd_sc_hd__buf_12 gain92 (.A(net93),
    .X(net91));
 sky130_fd_sc_hd__buf_12 gain93 (.A(net93),
    .X(net92));
 sky130_fd_sc_hd__buf_4 gain94 (.A(u_uart_master_core_u_host_bridge_bus_rst_ni),
    .X(net93));
 sky130_fd_sc_hd__buf_12 gain95 (.A(net95),
    .X(net94));
 sky130_fd_sc_hd__buf_12 gain96 (.A(u_uart_master_core_u_host_bridge_parser_rst_ni),
    .X(net95));
 sky130_fd_sc_hd__buf_12 gain97 (.A(net97),
    .X(net96));
 sky130_fd_sc_hd__buf_12 gain98 (.A(u_uart_master_core_u_host_bridge_response_rst_ni),
    .X(net97));
 sky130_fd_sc_hd__buf_2 gain99 (.A(u_uart_master_core_host_rst_ni),
    .X(net98));
endmodule
