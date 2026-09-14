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
 wire net27;
 wire net22;
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
 wire u_uart_reg_tl_o_0_;
 wire u_uart_reg_tl_o_16_;
 wire u_uart_reg_tl_o_17_;
 wire u_uart_reg_tl_o_18_;
 wire u_uart_reg_tl_o_19_;
 wire u_uart_reg_tl_o_1_;
 wire u_uart_reg_tl_o_20_;
 wire u_uart_reg_tl_o_21_;
 wire u_uart_reg_tl_o_22_;
 wire u_uart_reg_tl_o_23_;
 wire u_uart_reg_tl_o_24_;
 wire u_uart_reg_tl_o_25_;
 wire u_uart_reg_tl_o_26_;
 wire u_uart_reg_tl_o_27_;
 wire u_uart_reg_tl_o_28_;
 wire u_uart_reg_tl_o_29_;
 wire u_uart_reg_tl_o_30_;
 wire u_uart_reg_tl_o_31_;
 wire u_uart_reg_tl_o_32_;
 wire u_uart_reg_tl_o_33_;
 wire u_uart_reg_tl_o_34_;
 wire u_uart_reg_tl_o_35_;
 wire u_uart_reg_tl_o_36_;
 wire u_uart_reg_tl_o_37_;
 wire u_uart_reg_tl_o_38_;
 wire u_uart_reg_tl_o_39_;
 wire u_uart_reg_tl_o_40_;
 wire u_uart_reg_tl_o_41_;
 wire u_uart_reg_tl_o_42_;
 wire u_uart_reg_tl_o_43_;
 wire u_uart_reg_tl_o_44_;
 wire u_uart_reg_tl_o_45_;
 wire u_uart_reg_tl_o_46_;
 wire u_uart_reg_tl_o_47_;
 wire u_uart_reg_tl_o_49_;
 wire u_uart_reg_tl_o_50_;
 wire u_uart_reg_tl_o_51_;
 wire u_uart_reg_tl_o_52_;
 wire u_uart_reg_tl_o_53_;
 wire u_uart_reg_tl_o_54_;
 wire u_uart_reg_tl_o_55_;
 wire u_uart_reg_tl_o_56_;
 wire u_uart_reg_tl_o_57_;
 wire u_uart_reg_tl_o_58_;
 wire u_uart_reg_tl_o_62_;
 wire u_uart_reg_tl_o_65_;
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
 wire net23;
 wire net24;
 wire net25;
 wire net26;
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

 sky130_fd_sc_hd__clkinv_1 _0984_ (.A(net111),
    .Y(_0674_));
 sky130_fd_sc_hd__inv_4 _0985_ (.A(net59),
    .Y(_0675_));
 sky130_fd_sc_hd__nand2_4 _0986_ (.A(_0675_),
    .B(net112),
    .Y(_0676_));
 sky130_fd_sc_hd__inv_1 _0987_ (.A(net112),
    .Y(_0677_));
 sky130_fd_sc_hd__nor2_1 _0988_ (.A(net61),
    .B(_0677_),
    .Y(_0678_));
 sky130_fd_sc_hd__inv_4 _0989_ (.A(net61),
    .Y(_0679_));
 sky130_fd_sc_hd__nor2_1 _0990_ (.A(net112),
    .B(_0679_),
    .Y(_0680_));
 sky130_fd_sc_hd__nor2_1 _0991_ (.A(_0678_),
    .B(_0680_),
    .Y(_0681_));
 sky130_fd_sc_hd__inv_4 _0992_ (.A(net60),
    .Y(_0682_));
 sky130_fd_sc_hd__nor2_1 _0993_ (.A(net111),
    .B(_0682_),
    .Y(_0683_));
 sky130_fd_sc_hd__nor2_1 _0994_ (.A(net60),
    .B(net58),
    .Y(_0684_));
 sky130_fd_sc_hd__nor2_1 _0995_ (.A(_0683_),
    .B(_0684_),
    .Y(_0685_));
 sky130_fd_sc_hd__inv_1 _0996_ (.A(net62),
    .Y(_0686_));
 sky130_fd_sc_hd__nor2_1 _0997_ (.A(net59),
    .B(_0686_),
    .Y(_0687_));
 sky130_fd_sc_hd__nor2_1 _0998_ (.A(net62),
    .B(_0675_),
    .Y(_0688_));
 sky130_fd_sc_hd__nor2_1 _0999_ (.A(_0687_),
    .B(_0688_),
    .Y(_0689_));
 sky130_fd_sc_hd__nand3_1 _1000_ (.A(_0681_),
    .B(_0685_),
    .C(_0689_),
    .Y(_0690_));
 sky130_fd_sc_hd__inv_1 _1001_ (.A(_0690_),
    .Y(_0691_));
 sky130_fd_sc_hd__xnor2_1 _1002_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .Y(_0692_));
 sky130_fd_sc_hd__inv_1 _1003_ (.A(_0692_),
    .Y(_0693_));
 sky130_fd_sc_hd__nand2_1 _1004_ (.A(_0691_),
    .B(_0693_),
    .Y(_0694_));
 sky130_fd_sc_hd__inv_1 _1005_ (.A(net83),
    .Y(_0695_));
 sky130_fd_sc_hd__nand3_1 _1006_ (.A(_0694_),
    .B(reg2hw_4_),
    .C(_0695_),
    .Y(_0696_));
 sky130_fd_sc_hd__nor3_4 _1007_ (.A(net58),
    .B(_0676_),
    .C(net34),
    .Y(_0019_));
 sky130_fd_sc_hd__nor2_1 _1008_ (.A(reg2hw_52_),
    .B(u_uart_core_nco_sum_q_11_),
    .Y(_0697_));
 sky130_fd_sc_hd__lpflow_inputiso0n_1 _1009_ (.A(reg2hw_52_),
    .SLEEP_B(u_uart_core_nco_sum_q_11_),
    .X(_0698_));
 sky130_fd_sc_hd__nor2_1 _1010_ (.A(_0697_),
    .B(_0698_),
    .Y(_0699_));
 sky130_fd_sc_hd__clkinv_1 _1011_ (.A(_0699_),
    .Y(_0700_));
 sky130_fd_sc_hd__nor2_1 _1012_ (.A(reg2hw_50_),
    .B(u_uart_core_nco_sum_q_9_),
    .Y(_0701_));
 sky130_fd_sc_hd__lpflow_inputiso0n_1 _1013_ (.A(reg2hw_50_),
    .SLEEP_B(u_uart_core_nco_sum_q_9_),
    .X(_0702_));
 sky130_fd_sc_hd__nor2_1 _1014_ (.A(_0701_),
    .B(_0702_),
    .Y(_0703_));
 sky130_fd_sc_hd__nor2_1 _1015_ (.A(reg2hw_49_),
    .B(u_uart_core_nco_sum_q_8_),
    .Y(_0704_));
 sky130_fd_sc_hd__lpflow_inputiso0n_1 _1016_ (.A(reg2hw_49_),
    .SLEEP_B(u_uart_core_nco_sum_q_8_),
    .X(_0705_));
 sky130_fd_sc_hd__nor2_1 _1017_ (.A(_0704_),
    .B(net57),
    .Y(_0706_));
 sky130_fd_sc_hd__nand2_1 _1018_ (.A(_0703_),
    .B(_0706_),
    .Y(_0707_));
 sky130_fd_sc_hd__nor2_1 _1019_ (.A(reg2hw_46_),
    .B(u_uart_core_nco_sum_q_5_),
    .Y(_0708_));
 sky130_fd_sc_hd__xor2_1 _1020_ (.A(net98),
    .B(u_uart_core_nco_sum_q_4_),
    .X(_0709_));
 sky130_fd_sc_hd__inv_1 _1021_ (.A(_0709_),
    .Y(_0710_));
 sky130_fd_sc_hd__lpflow_inputiso0n_1 _1022_ (.A(reg2hw_44_),
    .SLEEP_B(u_uart_core_nco_sum_q_3_),
    .X(_0711_));
 sky130_fd_sc_hd__nor2_1 _1023_ (.A(reg2hw_44_),
    .B(u_uart_core_nco_sum_q_3_),
    .Y(_0712_));
 sky130_fd_sc_hd__nor2_1 _1024_ (.A(reg2hw_43_),
    .B(u_uart_core_nco_sum_q_2_),
    .Y(_0713_));
 sky130_fd_sc_hd__and2_0 _1025_ (.A(reg2hw_43_),
    .B(u_uart_core_nco_sum_q_2_),
    .X(_0714_));
 sky130_fd_sc_hd__nor2_1 _1026_ (.A(_0713_),
    .B(_0714_),
    .Y(_0715_));
 sky130_fd_sc_hd__nand2_1 _1027_ (.A(net99),
    .B(u_uart_core_nco_sum_q_0_),
    .Y(_0716_));
 sky130_fd_sc_hd__nor2_1 _1028_ (.A(reg2hw_42_),
    .B(u_uart_core_nco_sum_q_1_),
    .Y(_0717_));
 sky130_fd_sc_hd__nand2_1 _1029_ (.A(reg2hw_42_),
    .B(u_uart_core_nco_sum_q_1_),
    .Y(_0718_));
 sky130_fd_sc_hd__o21ai_1 _1030_ (.A1(_0716_),
    .A2(_0717_),
    .B1(_0718_),
    .Y(_0719_));
 sky130_fd_sc_hd__a21oi_1 _1031_ (.A1(_0715_),
    .A2(_0719_),
    .B1(_0714_),
    .Y(_0720_));
 sky130_fd_sc_hd__nor2_1 _1032_ (.A(_0712_),
    .B(_0720_),
    .Y(_0721_));
 sky130_fd_sc_hd__nor2_1 _1033_ (.A(net56),
    .B(_0721_),
    .Y(_0722_));
 sky130_fd_sc_hd__nor2_1 _1034_ (.A(_0710_),
    .B(_0722_),
    .Y(_0723_));
 sky130_fd_sc_hd__a21oi_1 _1035_ (.A1(net98),
    .A2(u_uart_core_nco_sum_q_4_),
    .B1(_0723_),
    .Y(_0724_));
 sky130_fd_sc_hd__inv_1 _1036_ (.A(reg2hw_46_),
    .Y(_0725_));
 sky130_fd_sc_hd__inv_1 _1037_ (.A(u_uart_core_nco_sum_q_5_),
    .Y(_0726_));
 sky130_fd_sc_hd__nor2_1 _1038_ (.A(_0725_),
    .B(_0726_),
    .Y(_0727_));
 sky130_fd_sc_hd__o21bai_2 _1039_ (.A1(_0708_),
    .A2(_0724_),
    .B1_N(_0727_),
    .Y(_0728_));
 sky130_fd_sc_hd__nor2_1 _1040_ (.A(reg2hw_48_),
    .B(u_uart_core_nco_sum_q_7_),
    .Y(_0729_));
 sky130_fd_sc_hd__and2_0 _1041_ (.A(reg2hw_48_),
    .B(u_uart_core_nco_sum_q_7_),
    .X(_0730_));
 sky130_fd_sc_hd__nor2_1 _1042_ (.A(_0729_),
    .B(_0730_),
    .Y(_0731_));
 sky130_fd_sc_hd__xor2_1 _1043_ (.A(net97),
    .B(u_uart_core_nco_sum_q_6_),
    .X(_0732_));
 sky130_fd_sc_hd__nand3_1 _1044_ (.A(_0728_),
    .B(_0731_),
    .C(_0732_),
    .Y(_0733_));
 sky130_fd_sc_hd__nand2_1 _1045_ (.A(net97),
    .B(u_uart_core_nco_sum_q_6_),
    .Y(_0734_));
 sky130_fd_sc_hd__nor2_1 _1046_ (.A(_0734_),
    .B(_0729_),
    .Y(_0735_));
 sky130_fd_sc_hd__nor2_1 _1047_ (.A(_0730_),
    .B(_0735_),
    .Y(_0736_));
 sky130_fd_sc_hd__nand2_1 _1048_ (.A(_0733_),
    .B(_0736_),
    .Y(_0737_));
 sky130_fd_sc_hd__inv_1 _1049_ (.A(_0737_),
    .Y(_0738_));
 sky130_fd_sc_hd__inv_1 _1050_ (.A(_0701_),
    .Y(_0739_));
 sky130_fd_sc_hd__a21oi_1 _1051_ (.A1(_0739_),
    .A2(net57),
    .B1(_0702_),
    .Y(_0740_));
 sky130_fd_sc_hd__o21ai_1 _1052_ (.A1(_0707_),
    .A2(_0738_),
    .B1(_0740_),
    .Y(_0741_));
 sky130_fd_sc_hd__nor2_1 _1053_ (.A(reg2hw_51_),
    .B(u_uart_core_nco_sum_q_10_),
    .Y(_0742_));
 sky130_fd_sc_hd__inv_1 _1054_ (.A(reg2hw_51_),
    .Y(_0743_));
 sky130_fd_sc_hd__inv_1 _1055_ (.A(u_uart_core_nco_sum_q_10_),
    .Y(_0744_));
 sky130_fd_sc_hd__nor2_1 _1056_ (.A(_0743_),
    .B(_0744_),
    .Y(_0745_));
 sky130_fd_sc_hd__nor2_1 _1057_ (.A(_0742_),
    .B(_0745_),
    .Y(_0746_));
 sky130_fd_sc_hd__a21oi_1 _1058_ (.A1(_0741_),
    .A2(_0746_),
    .B1(_0745_),
    .Y(_0747_));
 sky130_fd_sc_hd__xor2_1 _1059_ (.A(_0700_),
    .B(_0747_),
    .X(_0004_));
 sky130_fd_sc_hd__nor2_1 _1060_ (.A(reg2hw_54_),
    .B(u_uart_core_nco_sum_q_13_),
    .Y(_0748_));
 sky130_fd_sc_hd__and2_0 _1061_ (.A(reg2hw_54_),
    .B(u_uart_core_nco_sum_q_13_),
    .X(_0749_));
 sky130_fd_sc_hd__nor2_1 _1062_ (.A(_0748_),
    .B(_0749_),
    .Y(_0750_));
 sky130_fd_sc_hd__inv_1 _1063_ (.A(_0746_),
    .Y(_0751_));
 sky130_fd_sc_hd__nor3_1 _1064_ (.A(_0743_),
    .B(_0744_),
    .C(_0697_),
    .Y(_0752_));
 sky130_fd_sc_hd__nor3_1 _1065_ (.A(_0740_),
    .B(_0700_),
    .C(_0751_),
    .Y(_0753_));
 sky130_fd_sc_hd__nor3_1 _1066_ (.A(_0698_),
    .B(_0752_),
    .C(_0753_),
    .Y(_0754_));
 sky130_fd_sc_hd__o41ai_1 _1067_ (.A1(_0707_),
    .A2(_0751_),
    .A3(_0700_),
    .A4(_0738_),
    .B1(_0754_),
    .Y(_0755_));
 sky130_fd_sc_hd__maj3_1 _1068_ (.A(net96),
    .B(_0755_),
    .C(net77),
    .X(_0756_));
 sky130_fd_sc_hd__xor2_1 _1069_ (.A(_0750_),
    .B(_0756_),
    .X(_0006_));
 sky130_fd_sc_hd__nor2_2 _1070_ (.A(_0675_),
    .B(net34),
    .Y(_0757_));
 sky130_fd_sc_hd__clkinv_2 _1071_ (.A(_0757_),
    .Y(_0758_));
 sky130_fd_sc_hd__nor2_1 _1072_ (.A(_0677_),
    .B(_0758_),
    .Y(_0759_));
 sky130_fd_sc_hd__inv_2 _1073_ (.A(_0759_),
    .Y(_0760_));
 sky130_fd_sc_hd__nor2_4 _1074_ (.A(net111),
    .B(_0760_),
    .Y(_0022_));
 sky130_fd_sc_hd__nand2_1 _1075_ (.A(_0728_),
    .B(_0732_),
    .Y(_0761_));
 sky130_fd_sc_hd__nand2_1 _1076_ (.A(_0761_),
    .B(_0734_),
    .Y(_0762_));
 sky130_fd_sc_hd__xor2_1 _1077_ (.A(_0731_),
    .B(_0762_),
    .X(_0015_));
 sky130_fd_sc_hd__xor2_1 _1078_ (.A(net99),
    .B(u_uart_core_nco_sum_q_0_),
    .X(_0002_));
 sky130_fd_sc_hd__nor3_4 _1079_ (.A(net111),
    .B(_0676_),
    .C(net34),
    .Y(_0023_));
 sky130_fd_sc_hd__clkinv_1 _1080_ (.A(net66),
    .Y(_0763_));
 sky130_fd_sc_hd__nand2_1 _1081_ (.A(_0763_),
    .B(net65),
    .Y(_0764_));
 sky130_fd_sc_hd__inv_1 _1082_ (.A(u_uart_core_uart_rx_sreg_q_10_),
    .Y(_0765_));
 sky130_fd_sc_hd__xnor2_1 _1083_ (.A(net64),
    .B(net68),
    .Y(_0766_));
 sky130_fd_sc_hd__inv_1 _1084_ (.A(_0766_),
    .Y(_0767_));
 sky130_fd_sc_hd__xnor2_1 _1085_ (.A(net65),
    .B(net69),
    .Y(_0768_));
 sky130_fd_sc_hd__inv_1 _1086_ (.A(_0768_),
    .Y(_0769_));
 sky130_fd_sc_hd__inv_4 _1087_ (.A(net63),
    .Y(_0770_));
 sky130_fd_sc_hd__nor2_1 _1088_ (.A(net67),
    .B(_0770_),
    .Y(_0771_));
 sky130_fd_sc_hd__inv_4 _1089_ (.A(net67),
    .Y(_0772_));
 sky130_fd_sc_hd__nor2_1 _1090_ (.A(net63),
    .B(_0772_),
    .Y(_0773_));
 sky130_fd_sc_hd__nor2_1 _1091_ (.A(_0771_),
    .B(_0773_),
    .Y(_0774_));
 sky130_fd_sc_hd__inv_1 _1092_ (.A(_0774_),
    .Y(_0775_));
 sky130_fd_sc_hd__inv_1 _1093_ (.A(net70),
    .Y(_0776_));
 sky130_fd_sc_hd__nor2_1 _1094_ (.A(net66),
    .B(_0776_),
    .Y(_0777_));
 sky130_fd_sc_hd__nor2_1 _1095_ (.A(net70),
    .B(_0763_),
    .Y(_0778_));
 sky130_fd_sc_hd__nor2_1 _1096_ (.A(_0777_),
    .B(_0778_),
    .Y(_0779_));
 sky130_fd_sc_hd__inv_1 _1097_ (.A(_0779_),
    .Y(_0780_));
 sky130_fd_sc_hd__nor4_1 _1098_ (.A(_0767_),
    .B(_0769_),
    .C(_0775_),
    .D(_0780_),
    .Y(_0781_));
 sky130_fd_sc_hd__xnor2_1 _1099_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .Y(_0782_));
 sky130_fd_sc_hd__inv_1 _1100_ (.A(_0782_),
    .Y(_0783_));
 sky130_fd_sc_hd__nand2_1 _1101_ (.A(_0781_),
    .B(_0783_),
    .Y(_0784_));
 sky130_fd_sc_hd__inv_1 _1102_ (.A(_0784_),
    .Y(_0785_));
 sky130_fd_sc_hd__nor2_1 _1103_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_under_rst),
    .B(_0785_),
    .Y(_0786_));
 sky130_fd_sc_hd__nand2_1 _1104_ (.A(_0786_),
    .B(u_uart_core_rx_valid),
    .Y(_0787_));
 sky130_fd_sc_hd__nor2_1 _1105_ (.A(_0765_),
    .B(_0787_),
    .Y(_0788_));
 sky130_fd_sc_hd__xnor2_1 _1106_ (.A(net107),
    .B(u_uart_core_uart_rx_sreg_q_1_),
    .Y(_0789_));
 sky130_fd_sc_hd__xnor2_1 _1107_ (.A(net94),
    .B(net106),
    .Y(_0790_));
 sky130_fd_sc_hd__xnor2_1 _1108_ (.A(_0789_),
    .B(_0790_),
    .Y(_0791_));
 sky130_fd_sc_hd__xor2_1 _1109_ (.A(net101),
    .B(u_uart_core_uart_rx_sreg_q_9_),
    .X(_0792_));
 sky130_fd_sc_hd__xnor2_1 _1110_ (.A(net104),
    .B(net105),
    .Y(_0793_));
 sky130_fd_sc_hd__xor2_1 _1111_ (.A(net102),
    .B(net103),
    .X(_0794_));
 sky130_fd_sc_hd__xor2_1 _1112_ (.A(_0793_),
    .B(_0794_),
    .X(_0795_));
 sky130_fd_sc_hd__xor2_1 _1113_ (.A(_0792_),
    .B(_0795_),
    .X(_0796_));
 sky130_fd_sc_hd__inv_1 _1114_ (.A(net95),
    .Y(_0797_));
 sky130_fd_sc_hd__a21oi_1 _1115_ (.A1(_0796_),
    .A2(_0791_),
    .B1(_0797_),
    .Y(_0798_));
 sky130_fd_sc_hd__o21ai_0 _1116_ (.A1(_0791_),
    .A2(_0796_),
    .B1(_0798_),
    .Y(_0799_));
 sky130_fd_sc_hd__nand2_1 _1117_ (.A(_0788_),
    .B(_0799_),
    .Y(_0800_));
 sky130_fd_sc_hd__clkinv_1 _1118_ (.A(_0800_),
    .Y(_0801_));
 sky130_fd_sc_hd__inv_1 _1119_ (.A(net64),
    .Y(_0802_));
 sky130_fd_sc_hd__nand3_1 _1120_ (.A(_0801_),
    .B(_0770_),
    .C(_0802_),
    .Y(_0803_));
 sky130_fd_sc_hd__nor2_4 _1121_ (.A(net53),
    .B(net30),
    .Y(_0033_));
 sky130_fd_sc_hd__nor3_4 _1122_ (.A(net111),
    .B(net112),
    .C(_0758_),
    .Y(_0024_));
 sky130_fd_sc_hd__inv_1 _1123_ (.A(net65),
    .Y(_0804_));
 sky130_fd_sc_hd__nand2_1 _1124_ (.A(_0804_),
    .B(net66),
    .Y(_0805_));
 sky130_fd_sc_hd__nor2_4 _1125_ (.A(net52),
    .B(net30),
    .Y(_0034_));
 sky130_fd_sc_hd__clkinv_1 _1126_ (.A(net34),
    .Y(_0806_));
 sky130_fd_sc_hd__nand2_4 _1127_ (.A(_0806_),
    .B(_0675_),
    .Y(_0807_));
 sky130_fd_sc_hd__nor3_4 _1128_ (.A(net111),
    .B(net112),
    .C(_0807_),
    .Y(_0025_));
 sky130_fd_sc_hd__nor2_2 _1129_ (.A(_0763_),
    .B(_0800_),
    .Y(_0808_));
 sky130_fd_sc_hd__nand2_4 _1130_ (.A(_0808_),
    .B(net65),
    .Y(_0809_));
 sky130_fd_sc_hd__nor2_1 _1131_ (.A(_0802_),
    .B(_0809_),
    .Y(_0810_));
 sky130_fd_sc_hd__inv_2 _1132_ (.A(_0810_),
    .Y(_0811_));
 sky130_fd_sc_hd__nor2_4 _1133_ (.A(_0770_),
    .B(_0811_),
    .Y(_0035_));
 sky130_fd_sc_hd__nand3_1 _1134_ (.A(_0801_),
    .B(net63),
    .C(_0802_),
    .Y(_0812_));
 sky130_fd_sc_hd__nor2_4 _1135_ (.A(net52),
    .B(net29),
    .Y(_0026_));
 sky130_fd_sc_hd__nand3_1 _1136_ (.A(_0801_),
    .B(net63),
    .C(net64),
    .Y(_0813_));
 sky130_fd_sc_hd__nor2_4 _1137_ (.A(net53),
    .B(net28),
    .Y(_0036_));
 sky130_fd_sc_hd__nor2_4 _1138_ (.A(net52),
    .B(net28),
    .Y(_0037_));
 sky130_fd_sc_hd__nand2_1 _1139_ (.A(_0804_),
    .B(_0763_),
    .Y(_0814_));
 sky130_fd_sc_hd__nor2_4 _1140_ (.A(net51),
    .B(net29),
    .Y(_0027_));
 sky130_fd_sc_hd__nor2_4 _1141_ (.A(net51),
    .B(net28),
    .Y(_0038_));
 sky130_fd_sc_hd__nor2_4 _1142_ (.A(net63),
    .B(_0811_),
    .Y(_0028_));
 sky130_fd_sc_hd__nor3_4 _1143_ (.A(_0770_),
    .B(net64),
    .C(_0809_),
    .Y(_0039_));
 sky130_fd_sc_hd__nand3_1 _1144_ (.A(_0801_),
    .B(_0770_),
    .C(net64),
    .Y(_0815_));
 sky130_fd_sc_hd__nor2_4 _1145_ (.A(net53),
    .B(net27),
    .Y(_0029_));
 sky130_fd_sc_hd__nor2_4 _1146_ (.A(net53),
    .B(net29),
    .Y(_0040_));
 sky130_fd_sc_hd__nor2_1 _1147_ (.A(_0706_),
    .B(_0737_),
    .Y(_0816_));
 sky130_fd_sc_hd__nor3_1 _1148_ (.A(net57),
    .B(_0704_),
    .C(_0738_),
    .Y(_0817_));
 sky130_fd_sc_hd__nor2_1 _1149_ (.A(_0816_),
    .B(_0817_),
    .Y(_0016_));
 sky130_fd_sc_hd__nor2_4 _1150_ (.A(net52),
    .B(net27),
    .Y(_0030_));
 sky130_fd_sc_hd__nor2_4 _1151_ (.A(net51),
    .B(net30),
    .Y(_0041_));
 sky130_fd_sc_hd__nor3_4 _1152_ (.A(net58),
    .B(net112),
    .C(_0807_),
    .Y(_0021_));
 sky130_fd_sc_hd__nor2_4 _1153_ (.A(net51),
    .B(net27),
    .Y(_0031_));
 sky130_fd_sc_hd__nor3_4 _1154_ (.A(net63),
    .B(net64),
    .C(_0809_),
    .Y(_0032_));
 sky130_fd_sc_hd__nor3_4 _1155_ (.A(net58),
    .B(net112),
    .C(_0758_),
    .Y(_0020_));
 sky130_fd_sc_hd__nor2_4 _1156_ (.A(net58),
    .B(_0760_),
    .Y(_0018_));
 sky130_fd_sc_hd__nor2_1 _1157_ (.A(reg2hw_56_),
    .B(u_uart_core_nco_sum_q_15_),
    .Y(_0818_));
 sky130_fd_sc_hd__nand2_1 _1158_ (.A(reg2hw_56_),
    .B(u_uart_core_nco_sum_q_15_),
    .Y(_0819_));
 sky130_fd_sc_hd__inv_1 _1159_ (.A(_0819_),
    .Y(_0820_));
 sky130_fd_sc_hd__nor2_1 _1160_ (.A(_0818_),
    .B(_0820_),
    .Y(_0821_));
 sky130_fd_sc_hd__lpflow_inputiso0n_1 _1161_ (.A(reg2hw_55_),
    .SLEEP_B(u_uart_core_nco_sum_q_14_),
    .X(_0822_));
 sky130_fd_sc_hd__nor2_1 _1162_ (.A(reg2hw_55_),
    .B(u_uart_core_nco_sum_q_14_),
    .Y(_0823_));
 sky130_fd_sc_hd__xor2_1 _1163_ (.A(net96),
    .B(net77),
    .X(_0824_));
 sky130_fd_sc_hd__a21oi_1 _1164_ (.A1(net96),
    .A2(net77),
    .B1(_0749_),
    .Y(_0825_));
 sky130_fd_sc_hd__nor2_1 _1165_ (.A(_0748_),
    .B(_0825_),
    .Y(_0826_));
 sky130_fd_sc_hd__a31oi_1 _1166_ (.A1(_0755_),
    .A2(_0824_),
    .A3(_0750_),
    .B1(_0826_),
    .Y(_0827_));
 sky130_fd_sc_hd__nor3_1 _1167_ (.A(net55),
    .B(_0823_),
    .C(_0827_),
    .Y(_0828_));
 sky130_fd_sc_hd__nor2_1 _1168_ (.A(net55),
    .B(_0828_),
    .Y(_0829_));
 sky130_fd_sc_hd__xnor2_1 _1169_ (.A(_0821_),
    .B(_0829_),
    .Y(_0008_));
 sky130_fd_sc_hd__nor2_1 _1170_ (.A(_0708_),
    .B(_0727_),
    .Y(_0830_));
 sky130_fd_sc_hd__xnor2_1 _1171_ (.A(_0830_),
    .B(_0724_),
    .Y(_0013_));
 sky130_fd_sc_hd__o21a_1 _1172_ (.A1(net55),
    .A2(_0823_),
    .B1(_0827_),
    .X(_0831_));
 sky130_fd_sc_hd__nor2_1 _1173_ (.A(_0828_),
    .B(_0831_),
    .Y(_0007_));
 sky130_fd_sc_hd__a21oi_1 _1174_ (.A1(_0829_),
    .A2(_0819_),
    .B1(_0818_),
    .Y(_0001_));
 sky130_fd_sc_hd__clkinv_1 _1175_ (.A(net101),
    .Y(_0832_));
 sky130_fd_sc_hd__nand2_1 _1176_ (.A(net95),
    .B(net102),
    .Y(_0833_));
 sky130_fd_sc_hd__o21ai_2 _1177_ (.A1(net95),
    .A2(_0832_),
    .B1(_0833_),
    .Y(u_uart_core_rx_fifo_data_6_));
 sky130_fd_sc_hd__inv_1 _1178_ (.A(_0718_),
    .Y(_0834_));
 sky130_fd_sc_hd__nor2_1 _1179_ (.A(_0717_),
    .B(_0834_),
    .Y(_0835_));
 sky130_fd_sc_hd__xnor2_1 _1180_ (.A(_0716_),
    .B(_0835_),
    .Y(_0009_));
 sky130_fd_sc_hd__clkinv_1 _1181_ (.A(net102),
    .Y(_0836_));
 sky130_fd_sc_hd__nand2_1 _1182_ (.A(net95),
    .B(net103),
    .Y(_0837_));
 sky130_fd_sc_hd__o21ai_2 _1183_ (.A1(net95),
    .A2(_0836_),
    .B1(_0837_),
    .Y(u_uart_core_rx_fifo_data_5_));
 sky130_fd_sc_hd__clkinv_1 _1184_ (.A(net103),
    .Y(_0838_));
 sky130_fd_sc_hd__nand2_1 _1185_ (.A(net95),
    .B(net104),
    .Y(_0839_));
 sky130_fd_sc_hd__o21ai_2 _1186_ (.A1(net95),
    .A2(_0838_),
    .B1(_0839_),
    .Y(u_uart_core_rx_fifo_data_4_));
 sky130_fd_sc_hd__clkinv_1 _1187_ (.A(net104),
    .Y(_0840_));
 sky130_fd_sc_hd__nand2_1 _1188_ (.A(net95),
    .B(net105),
    .Y(_0841_));
 sky130_fd_sc_hd__o21ai_2 _1189_ (.A1(net95),
    .A2(_0840_),
    .B1(_0841_),
    .Y(u_uart_core_rx_fifo_data_3_));
 sky130_fd_sc_hd__clkinv_1 _1190_ (.A(net105),
    .Y(_0842_));
 sky130_fd_sc_hd__nand2_1 _1191_ (.A(net95),
    .B(net106),
    .Y(_0843_));
 sky130_fd_sc_hd__o21ai_2 _1192_ (.A1(net95),
    .A2(_0842_),
    .B1(_0843_),
    .Y(u_uart_core_rx_fifo_data_2_));
 sky130_fd_sc_hd__clkinv_1 _1193_ (.A(net106),
    .Y(_0844_));
 sky130_fd_sc_hd__nand2_1 _1194_ (.A(net95),
    .B(net107),
    .Y(_0845_));
 sky130_fd_sc_hd__o21ai_2 _1195_ (.A1(net95),
    .A2(_0844_),
    .B1(_0845_),
    .Y(u_uart_core_rx_fifo_data_1_));
 sky130_fd_sc_hd__clkinv_1 _1196_ (.A(net107),
    .Y(_0846_));
 sky130_fd_sc_hd__nand2_1 _1197_ (.A(net95),
    .B(u_uart_core_uart_rx_sreg_q_1_),
    .Y(_0847_));
 sky130_fd_sc_hd__o21ai_2 _1198_ (.A1(net95),
    .A2(_0846_),
    .B1(_0847_),
    .Y(u_uart_core_rx_fifo_data_0_));
 sky130_fd_sc_hd__xor2_1 _1199_ (.A(_0824_),
    .B(_0755_),
    .X(_0005_));
 sky130_fd_sc_hd__clkinv_2 _1200_ (.A(tl_i[64]),
    .Y(_0848_));
 sky130_fd_sc_hd__nand2_1 _1201_ (.A(_0848_),
    .B(tl_i[63]),
    .Y(_0849_));
 sky130_fd_sc_hd__nor2_1 _1202_ (.A(tl_i[60]),
    .B(tl_i[61]),
    .Y(_0850_));
 sky130_fd_sc_hd__inv_1 _1203_ (.A(_0850_),
    .Y(_0851_));
 sky130_fd_sc_hd__clkinv_2 _1204_ (.A(u_uart_reg_tl_o_65_),
    .Y(u_uart_reg_tl_o_0_));
 sky130_fd_sc_hd__nand2_8 _1205_ (.A(u_uart_reg_tl_o_0_),
    .B(tl_i[108]),
    .Y(_0852_));
 sky130_fd_sc_hd__nor2_1 _1206_ (.A(tl_i[106]),
    .B(_0852_),
    .Y(_0853_));
 sky130_fd_sc_hd__inv_1 _1207_ (.A(tl_i[107]),
    .Y(_0854_));
 sky130_fd_sc_hd__nand2_1 _1208_ (.A(_0853_),
    .B(_0854_),
    .Y(_0855_));
 sky130_fd_sc_hd__nor2_2 _1209_ (.A(_0851_),
    .B(_0855_),
    .Y(_0856_));
 sky130_fd_sc_hd__nand2_1 _1210_ (.A(_0856_),
    .B(tl_i[62]),
    .Y(_0857_));
 sky130_fd_sc_hd__nor2_2 _1211_ (.A(tl_i[62]),
    .B(tl_i[63]),
    .Y(_0858_));
 sky130_fd_sc_hd__nor2_1 _1212_ (.A(_0848_),
    .B(_0858_),
    .Y(_0859_));
 sky130_fd_sc_hd__nand2_4 _1213_ (.A(_0858_),
    .B(_0848_),
    .Y(_0860_));
 sky130_fd_sc_hd__inv_8 _1214_ (.A(_0860_),
    .Y(_0861_));
 sky130_fd_sc_hd__inv_1 _1215_ (.A(tl_i[62]),
    .Y(_0862_));
 sky130_fd_sc_hd__nor3_2 _1216_ (.A(tl_i[63]),
    .B(_0848_),
    .C(_0862_),
    .Y(_0863_));
 sky130_fd_sc_hd__nand3_1 _1217_ (.A(tl_i[58]),
    .B(tl_i[57]),
    .C(tl_i[56]),
    .Y(_0864_));
 sky130_fd_sc_hd__nor2_1 _1218_ (.A(tl_i[59]),
    .B(_0860_),
    .Y(_0865_));
 sky130_fd_sc_hd__o22ai_1 _1219_ (.A1(_0863_),
    .A2(_0861_),
    .B1(_0864_),
    .B2(_0865_),
    .Y(_0866_));
 sky130_fd_sc_hd__o31ai_1 _1220_ (.A1(tl_i[56]),
    .A2(_0859_),
    .A3(_0861_),
    .B1(_0866_),
    .Y(_0867_));
 sky130_fd_sc_hd__nor3_1 _1221_ (.A(_0849_),
    .B(_0857_),
    .C(_0867_),
    .Y(_0868_));
 sky130_fd_sc_hd__buf_2 _1222_ (.A(_0868_),
    .X(u_uart_reg_u_reg_core_reg_we_check_3_));
 sky130_fd_sc_hd__inv_1 _1223_ (.A(tl_i[30]),
    .Y(_0869_));
 sky130_fd_sc_hd__nor2_1 _1224_ (.A(net85),
    .B(net31),
    .Y(_0870_));
 sky130_fd_sc_hd__a21oi_1 _1225_ (.A1(_0869_),
    .A2(net31),
    .B1(_0870_),
    .Y(_0042_));
 sky130_fd_sc_hd__inv_1 _1226_ (.A(tl_i[29]),
    .Y(_0871_));
 sky130_fd_sc_hd__nor2_1 _1227_ (.A(net86),
    .B(net31),
    .Y(_0872_));
 sky130_fd_sc_hd__a21oi_1 _1228_ (.A1(_0871_),
    .A2(net31),
    .B1(_0872_),
    .Y(_0043_));
 sky130_fd_sc_hd__inv_1 _1229_ (.A(tl_i[28]),
    .Y(_0873_));
 sky130_fd_sc_hd__nor2_1 _1230_ (.A(net87),
    .B(net31),
    .Y(_0874_));
 sky130_fd_sc_hd__a21oi_1 _1231_ (.A1(_0873_),
    .A2(net31),
    .B1(_0874_),
    .Y(_0044_));
 sky130_fd_sc_hd__mux2_1 _1232_ (.A0(net88),
    .A1(tl_i[27]),
    .S(net31),
    .X(_0045_));
 sky130_fd_sc_hd__inv_1 _1233_ (.A(tl_i[26]),
    .Y(_0875_));
 sky130_fd_sc_hd__nor2_1 _1234_ (.A(net89),
    .B(net31),
    .Y(_0876_));
 sky130_fd_sc_hd__a21oi_1 _1235_ (.A1(_0875_),
    .A2(net31),
    .B1(_0876_),
    .Y(_0046_));
 sky130_fd_sc_hd__inv_1 _1236_ (.A(tl_i[25]),
    .Y(_0877_));
 sky130_fd_sc_hd__nor2_1 _1237_ (.A(net90),
    .B(net31),
    .Y(_0878_));
 sky130_fd_sc_hd__a21oi_1 _1238_ (.A1(_0877_),
    .A2(net31),
    .B1(_0878_),
    .Y(_0047_));
 sky130_fd_sc_hd__inv_1 _1239_ (.A(tl_i[24]),
    .Y(_0879_));
 sky130_fd_sc_hd__nor2_1 _1240_ (.A(net91),
    .B(net31),
    .Y(_0880_));
 sky130_fd_sc_hd__a21oi_1 _1241_ (.A1(_0879_),
    .A2(net31),
    .B1(_0880_),
    .Y(_0048_));
 sky130_fd_sc_hd__nor3_1 _1242_ (.A(_0860_),
    .B(_0864_),
    .C(_0865_),
    .Y(_0881_));
 sky130_fd_sc_hd__nand2_1 _1243_ (.A(_0856_),
    .B(_0881_),
    .Y(_0882_));
 sky130_fd_sc_hd__buf_2 _1244_ (.A(_0882_),
    .X(_0883_));
 sky130_fd_sc_hd__mux2_1 _1245_ (.A0(tl_i[54]),
    .A1(reg2hw_55_),
    .S(net33),
    .X(_0049_));
 sky130_fd_sc_hd__mux2_1 _1246_ (.A0(tl_i[53]),
    .A1(reg2hw_54_),
    .S(net33),
    .X(_0050_));
 sky130_fd_sc_hd__mux2_1 _1247_ (.A0(tl_i[52]),
    .A1(net96),
    .S(net33),
    .X(_0051_));
 sky130_fd_sc_hd__mux2_1 _1248_ (.A0(tl_i[51]),
    .A1(reg2hw_52_),
    .S(net33),
    .X(_0052_));
 sky130_fd_sc_hd__mux2_1 _1249_ (.A0(tl_i[50]),
    .A1(reg2hw_51_),
    .S(net33),
    .X(_0053_));
 sky130_fd_sc_hd__mux2_1 _1250_ (.A0(tl_i[49]),
    .A1(reg2hw_50_),
    .S(net33),
    .X(_0054_));
 sky130_fd_sc_hd__mux2_1 _1251_ (.A0(tl_i[48]),
    .A1(reg2hw_49_),
    .S(net33),
    .X(_0055_));
 sky130_fd_sc_hd__mux2_1 _1252_ (.A0(tl_i[47]),
    .A1(reg2hw_48_),
    .S(net33),
    .X(_0056_));
 sky130_fd_sc_hd__mux2_1 _1253_ (.A0(tl_i[46]),
    .A1(net97),
    .S(net33),
    .X(_0057_));
 sky130_fd_sc_hd__mux2_1 _1254_ (.A0(tl_i[45]),
    .A1(reg2hw_46_),
    .S(net33),
    .X(_0058_));
 sky130_fd_sc_hd__mux2_1 _1255_ (.A0(tl_i[44]),
    .A1(net98),
    .S(net33),
    .X(_0059_));
 sky130_fd_sc_hd__mux2_1 _1256_ (.A0(tl_i[43]),
    .A1(reg2hw_44_),
    .S(net33),
    .X(_0060_));
 sky130_fd_sc_hd__mux2_1 _1257_ (.A0(tl_i[42]),
    .A1(reg2hw_43_),
    .S(net33),
    .X(_0061_));
 sky130_fd_sc_hd__mux2_1 _1258_ (.A0(tl_i[41]),
    .A1(reg2hw_42_),
    .S(net33),
    .X(_0062_));
 sky130_fd_sc_hd__mux2_1 _1259_ (.A0(tl_i[40]),
    .A1(net99),
    .S(net33),
    .X(_0063_));
 sky130_fd_sc_hd__inv_4 _1260_ (.A(_0852_),
    .Y(_0884_));
 sky130_fd_sc_hd__lpflow_clkbufkapwr_1 _1261_ (.A(_0884_),
    .X(_0885_));
 sky130_fd_sc_hd__nand2_1 _1262_ (.A(net36),
    .B(tl_i[100]),
    .Y(_0886_));
 sky130_fd_sc_hd__nand2_1 _1263_ (.A(_0852_),
    .B(u_uart_reg_tl_o_57_),
    .Y(_0887_));
 sky130_fd_sc_hd__nand2_1 _1264_ (.A(_0886_),
    .B(_0887_),
    .Y(_0064_));
 sky130_fd_sc_hd__nand2_1 _1265_ (.A(net36),
    .B(tl_i[98]),
    .Y(_0888_));
 sky130_fd_sc_hd__nand2_1 _1266_ (.A(_0852_),
    .B(u_uart_reg_tl_o_55_),
    .Y(_0889_));
 sky130_fd_sc_hd__nand2_1 _1267_ (.A(_0888_),
    .B(_0889_),
    .Y(_0065_));
 sky130_fd_sc_hd__nand2_1 _1268_ (.A(net36),
    .B(tl_i[97]),
    .Y(_0890_));
 sky130_fd_sc_hd__nand2_1 _1269_ (.A(_0852_),
    .B(u_uart_reg_tl_o_54_),
    .Y(_0891_));
 sky130_fd_sc_hd__nand2_1 _1270_ (.A(_0890_),
    .B(_0891_),
    .Y(_0066_));
 sky130_fd_sc_hd__nand2_1 _1271_ (.A(net36),
    .B(tl_i[96]),
    .Y(_0892_));
 sky130_fd_sc_hd__nand2_1 _1272_ (.A(_0852_),
    .B(u_uart_reg_tl_o_53_),
    .Y(_0893_));
 sky130_fd_sc_hd__nand2_1 _1273_ (.A(_0892_),
    .B(_0893_),
    .Y(_0067_));
 sky130_fd_sc_hd__nand2_1 _1274_ (.A(net36),
    .B(tl_i[95]),
    .Y(_0894_));
 sky130_fd_sc_hd__nand2_1 _1275_ (.A(_0852_),
    .B(u_uart_reg_tl_o_52_),
    .Y(_0895_));
 sky130_fd_sc_hd__nand2_1 _1276_ (.A(_0894_),
    .B(_0895_),
    .Y(_0068_));
 sky130_fd_sc_hd__nand2_1 _1277_ (.A(net36),
    .B(tl_i[94]),
    .Y(_0896_));
 sky130_fd_sc_hd__nand2_1 _1278_ (.A(_0852_),
    .B(u_uart_reg_tl_o_51_),
    .Y(_0897_));
 sky130_fd_sc_hd__nand2_1 _1279_ (.A(_0896_),
    .B(_0897_),
    .Y(_0069_));
 sky130_fd_sc_hd__nand2_1 _1280_ (.A(net36),
    .B(tl_i[93]),
    .Y(_0898_));
 sky130_fd_sc_hd__nand2_1 _1281_ (.A(_0852_),
    .B(u_uart_reg_tl_o_50_),
    .Y(_0899_));
 sky130_fd_sc_hd__nand2_1 _1282_ (.A(_0898_),
    .B(_0899_),
    .Y(_0070_));
 sky130_fd_sc_hd__nand2_1 _1283_ (.A(net36),
    .B(tl_i[92]),
    .Y(_0900_));
 sky130_fd_sc_hd__nand2_1 _1284_ (.A(_0852_),
    .B(u_uart_reg_tl_o_49_),
    .Y(_0901_));
 sky130_fd_sc_hd__nand2_1 _1285_ (.A(_0900_),
    .B(_0901_),
    .Y(_0071_));
 sky130_fd_sc_hd__inv_1 _1286_ (.A(tl_i[63]),
    .Y(_0902_));
 sky130_fd_sc_hd__nor2_1 _1287_ (.A(_0848_),
    .B(_0902_),
    .Y(_0903_));
 sky130_fd_sc_hd__inv_1 _1288_ (.A(_0855_),
    .Y(_0904_));
 sky130_fd_sc_hd__nor3_1 _1289_ (.A(_0852_),
    .B(_0903_),
    .C(_0904_),
    .Y(_0905_));
 sky130_fd_sc_hd__buf_2 _1290_ (.A(_0905_),
    .X(_0906_));
 sky130_fd_sc_hd__nand2_1 _1291_ (.A(_0861_),
    .B(reg2hw_55_),
    .Y(_0907_));
 sky130_fd_sc_hd__nor2_1 _1292_ (.A(u_uart_reg_tl_o_46_),
    .B(net36),
    .Y(_0908_));
 sky130_fd_sc_hd__a21oi_1 _1293_ (.A1(net32),
    .A2(_0907_),
    .B1(_0908_),
    .Y(_0072_));
 sky130_fd_sc_hd__nand2_1 _1294_ (.A(_0861_),
    .B(reg2hw_54_),
    .Y(_0909_));
 sky130_fd_sc_hd__nor2_1 _1295_ (.A(u_uart_reg_tl_o_45_),
    .B(net36),
    .Y(_0910_));
 sky130_fd_sc_hd__a21oi_1 _1296_ (.A1(net32),
    .A2(_0909_),
    .B1(_0910_),
    .Y(_0073_));
 sky130_fd_sc_hd__nand2_1 _1297_ (.A(_0861_),
    .B(net96),
    .Y(_0911_));
 sky130_fd_sc_hd__nor2_1 _1298_ (.A(u_uart_reg_tl_o_44_),
    .B(net36),
    .Y(_0912_));
 sky130_fd_sc_hd__a21oi_1 _1299_ (.A1(net32),
    .A2(_0911_),
    .B1(_0912_),
    .Y(_0074_));
 sky130_fd_sc_hd__nand2_1 _1300_ (.A(_0861_),
    .B(reg2hw_52_),
    .Y(_0913_));
 sky130_fd_sc_hd__nor2_1 _1301_ (.A(u_uart_reg_tl_o_43_),
    .B(net36),
    .Y(_0914_));
 sky130_fd_sc_hd__a21oi_1 _1302_ (.A1(net32),
    .A2(_0913_),
    .B1(_0914_),
    .Y(_0075_));
 sky130_fd_sc_hd__nand2_1 _1303_ (.A(_0861_),
    .B(reg2hw_51_),
    .Y(_0915_));
 sky130_fd_sc_hd__nor2_1 _1304_ (.A(u_uart_reg_tl_o_42_),
    .B(net36),
    .Y(_0916_));
 sky130_fd_sc_hd__a21oi_1 _1305_ (.A1(net32),
    .A2(_0915_),
    .B1(_0916_),
    .Y(_0076_));
 sky130_fd_sc_hd__nand2_1 _1306_ (.A(_0861_),
    .B(reg2hw_50_),
    .Y(_0917_));
 sky130_fd_sc_hd__nor2_1 _1307_ (.A(u_uart_reg_tl_o_41_),
    .B(net36),
    .Y(_0918_));
 sky130_fd_sc_hd__a21oi_1 _1308_ (.A1(net32),
    .A2(_0917_),
    .B1(_0918_),
    .Y(_0077_));
 sky130_fd_sc_hd__nand2_1 _1309_ (.A(_0861_),
    .B(reg2hw_49_),
    .Y(_0919_));
 sky130_fd_sc_hd__nor2_1 _1310_ (.A(u_uart_reg_tl_o_40_),
    .B(net36),
    .Y(_0920_));
 sky130_fd_sc_hd__a21oi_1 _1311_ (.A1(net32),
    .A2(_0919_),
    .B1(_0920_),
    .Y(_0078_));
 sky130_fd_sc_hd__nand2_1 _1312_ (.A(_0861_),
    .B(reg2hw_48_),
    .Y(_0921_));
 sky130_fd_sc_hd__nor2_1 _1313_ (.A(u_uart_reg_tl_o_39_),
    .B(net36),
    .Y(_0922_));
 sky130_fd_sc_hd__a21oi_1 _1314_ (.A1(net32),
    .A2(_0921_),
    .B1(_0922_),
    .Y(_0079_));
 sky130_fd_sc_hd__nand2_1 _1315_ (.A(_0861_),
    .B(net97),
    .Y(_0923_));
 sky130_fd_sc_hd__nor2_1 _1316_ (.A(u_uart_reg_tl_o_38_),
    .B(net36),
    .Y(_0924_));
 sky130_fd_sc_hd__a21oi_1 _1317_ (.A1(net32),
    .A2(_0923_),
    .B1(_0924_),
    .Y(_0080_));
 sky130_fd_sc_hd__nand2_1 _1318_ (.A(_0861_),
    .B(reg2hw_46_),
    .Y(_0925_));
 sky130_fd_sc_hd__nor2_1 _1319_ (.A(u_uart_reg_tl_o_37_),
    .B(net36),
    .Y(_0926_));
 sky130_fd_sc_hd__a21oi_1 _1320_ (.A1(net32),
    .A2(_0925_),
    .B1(_0926_),
    .Y(_0081_));
 sky130_fd_sc_hd__clkinv_4 _1321_ (.A(net68),
    .Y(_0927_));
 sky130_fd_sc_hd__inv_6 _1322_ (.A(net69),
    .Y(_0928_));
 sky130_fd_sc_hd__nor2_1 _1323_ (.A(_0777_),
    .B(_0769_),
    .Y(_0929_));
 sky130_fd_sc_hd__a21oi_1 _1324_ (.A1(net65),
    .A2(_0928_),
    .B1(_0929_),
    .Y(_0930_));
 sky130_fd_sc_hd__nor2_1 _1325_ (.A(_0767_),
    .B(_0930_),
    .Y(_0931_));
 sky130_fd_sc_hd__a21oi_1 _1326_ (.A1(net64),
    .A2(_0927_),
    .B1(_0931_),
    .Y(_0932_));
 sky130_fd_sc_hd__nor2_1 _1327_ (.A(_0773_),
    .B(_0932_),
    .Y(_0933_));
 sky130_fd_sc_hd__nor2_1 _1328_ (.A(_0771_),
    .B(_0933_),
    .Y(_0934_));
 sky130_fd_sc_hd__nor2_1 _1329_ (.A(_0782_),
    .B(_0781_),
    .Y(_0935_));
 sky130_fd_sc_hd__clkinv_1 _1330_ (.A(_0863_),
    .Y(_0936_));
 sky130_fd_sc_hd__a21oi_1 _1331_ (.A1(_0934_),
    .A2(_0935_),
    .B1(_0936_),
    .Y(_0937_));
 sky130_fd_sc_hd__o21ai_0 _1332_ (.A1(_0783_),
    .A2(_0934_),
    .B1(_0937_),
    .Y(_0938_));
 sky130_fd_sc_hd__clkinv_2 _1333_ (.A(net32),
    .Y(_0939_));
 sky130_fd_sc_hd__a21oi_1 _1334_ (.A1(net98),
    .A2(_0861_),
    .B1(_0939_),
    .Y(_0940_));
 sky130_fd_sc_hd__nor2_1 _1335_ (.A(u_uart_reg_tl_o_36_),
    .B(net36),
    .Y(_0941_));
 sky130_fd_sc_hd__a21oi_1 _1336_ (.A1(_0938_),
    .A2(_0940_),
    .B1(_0941_),
    .Y(_0082_));
 sky130_fd_sc_hd__nand2_1 _1337_ (.A(_0861_),
    .B(reg2hw_44_),
    .Y(_0942_));
 sky130_fd_sc_hd__nand2_1 _1338_ (.A(net32),
    .B(_0942_),
    .Y(_0943_));
 sky130_fd_sc_hd__nor2_1 _1339_ (.A(_0936_),
    .B(_0785_),
    .Y(_0944_));
 sky130_fd_sc_hd__o21ai_0 _1340_ (.A1(_0775_),
    .A2(_0932_),
    .B1(_0944_),
    .Y(_0945_));
 sky130_fd_sc_hd__a21oi_1 _1341_ (.A1(_0775_),
    .A2(_0932_),
    .B1(_0945_),
    .Y(_0946_));
 sky130_fd_sc_hd__o22a_1 _1342_ (.A1(u_uart_reg_tl_o_35_),
    .A2(_0884_),
    .B1(_0943_),
    .B2(_0946_),
    .X(_0083_));
 sky130_fd_sc_hd__nand2_1 _1343_ (.A(_0930_),
    .B(_0767_),
    .Y(_0947_));
 sky130_fd_sc_hd__nand3b_1 _1344_ (.A_N(_0931_),
    .B(_0944_),
    .C(_0947_),
    .Y(_0948_));
 sky130_fd_sc_hd__a21oi_1 _1345_ (.A1(reg2hw_43_),
    .A2(_0861_),
    .B1(_0939_),
    .Y(_0949_));
 sky130_fd_sc_hd__nor2_1 _1346_ (.A(u_uart_reg_tl_o_34_),
    .B(net36),
    .Y(_0950_));
 sky130_fd_sc_hd__a21oi_1 _1347_ (.A1(_0948_),
    .A2(_0949_),
    .B1(_0950_),
    .Y(_0084_));
 sky130_fd_sc_hd__nand2_1 _1348_ (.A(_0769_),
    .B(_0777_),
    .Y(_0951_));
 sky130_fd_sc_hd__nand3b_1 _1349_ (.A_N(_0929_),
    .B(_0944_),
    .C(_0951_),
    .Y(_0952_));
 sky130_fd_sc_hd__a21oi_1 _1350_ (.A1(reg2hw_42_),
    .A2(_0861_),
    .B1(_0939_),
    .Y(_0953_));
 sky130_fd_sc_hd__nor2_1 _1351_ (.A(u_uart_reg_tl_o_33_),
    .B(net36),
    .Y(_0954_));
 sky130_fd_sc_hd__a21oi_1 _1352_ (.A1(_0952_),
    .A2(_0953_),
    .B1(_0954_),
    .Y(_0085_));
 sky130_fd_sc_hd__nand2_1 _1353_ (.A(_0780_),
    .B(_0863_),
    .Y(_0955_));
 sky130_fd_sc_hd__nand2_1 _1354_ (.A(_0861_),
    .B(net99),
    .Y(_0956_));
 sky130_fd_sc_hd__nor2_1 _1355_ (.A(u_uart_reg_tl_o_32_),
    .B(_0884_),
    .Y(_0957_));
 sky130_fd_sc_hd__a31oi_1 _1356_ (.A1(net32),
    .A2(_0955_),
    .A3(_0956_),
    .B1(_0957_),
    .Y(_0086_));
 sky130_fd_sc_hd__nor2_1 _1357_ (.A(u_uart_reg_tl_o_31_),
    .B(net36),
    .Y(_0958_));
 sky130_fd_sc_hd__nor2_1 _1358_ (.A(_0958_),
    .B(net32),
    .Y(_0087_));
 sky130_fd_sc_hd__nor2_1 _1359_ (.A(u_uart_reg_tl_o_30_),
    .B(net36),
    .Y(_0959_));
 sky130_fd_sc_hd__nor2_1 _1360_ (.A(_0959_),
    .B(net32),
    .Y(_0088_));
 sky130_fd_sc_hd__nor2_1 _1361_ (.A(u_uart_reg_tl_o_29_),
    .B(net36),
    .Y(_0960_));
 sky130_fd_sc_hd__nor2_1 _1362_ (.A(_0960_),
    .B(net32),
    .Y(_0089_));
 sky130_fd_sc_hd__nor2_1 _1363_ (.A(u_uart_reg_tl_o_28_),
    .B(net36),
    .Y(_0961_));
 sky130_fd_sc_hd__nor2_1 _1364_ (.A(_0961_),
    .B(net32),
    .Y(_0090_));
 sky130_fd_sc_hd__nor2_1 _1365_ (.A(u_uart_reg_tl_o_27_),
    .B(net36),
    .Y(_0962_));
 sky130_fd_sc_hd__nor2_1 _1366_ (.A(_0962_),
    .B(net32),
    .Y(_0091_));
 sky130_fd_sc_hd__nor2_1 _1367_ (.A(u_uart_reg_tl_o_26_),
    .B(net36),
    .Y(_0963_));
 sky130_fd_sc_hd__nor2_1 _1368_ (.A(_0963_),
    .B(net32),
    .Y(_0092_));
 sky130_fd_sc_hd__nor2_1 _1369_ (.A(u_uart_reg_tl_o_25_),
    .B(net36),
    .Y(_0964_));
 sky130_fd_sc_hd__nor2_1 _1370_ (.A(_0964_),
    .B(net32),
    .Y(_0093_));
 sky130_fd_sc_hd__nor2_1 _1371_ (.A(u_uart_reg_tl_o_24_),
    .B(net36),
    .Y(_0965_));
 sky130_fd_sc_hd__nor2_1 _1372_ (.A(_0965_),
    .B(net32),
    .Y(_0094_));
 sky130_fd_sc_hd__a211oi_1 _1373_ (.A1(_0781_),
    .A2(_0782_),
    .B1(tl_i[62]),
    .C1(_0849_),
    .Y(_0966_));
 sky130_fd_sc_hd__o21ai_0 _1374_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_7_),
    .B1(_0928_),
    .Y(_0967_));
 sky130_fd_sc_hd__buf_2 _1375_ (.A(_0776_),
    .X(_0968_));
 sky130_fd_sc_hd__nor2_1 _1376_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_15_),
    .B(net43),
    .Y(_0969_));
 sky130_fd_sc_hd__nor2_1 _1377_ (.A(_0967_),
    .B(_0969_),
    .Y(_0970_));
 sky130_fd_sc_hd__nor2_1 _1378_ (.A(net70),
    .B(_0928_),
    .Y(_0971_));
 sky130_fd_sc_hd__buf_2 _1379_ (.A(_0971_),
    .X(_0972_));
 sky130_fd_sc_hd__nor2_1 _1380_ (.A(_0928_),
    .B(_0776_),
    .Y(_0973_));
 sky130_fd_sc_hd__a22o_1 _1381_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_23_),
    .B1(net42),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_31_),
    .X(_0974_));
 sky130_fd_sc_hd__o21ai_0 _1382_ (.A1(_0970_),
    .A2(_0974_),
    .B1(_0927_),
    .Y(_0975_));
 sky130_fd_sc_hd__nand2_1 _1383_ (.A(net43),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_39_),
    .Y(_0976_));
 sky130_fd_sc_hd__nand2_1 _1384_ (.A(net70),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_47_),
    .Y(_0977_));
 sky130_fd_sc_hd__a21oi_1 _1385_ (.A1(_0976_),
    .A2(_0977_),
    .B1(net69),
    .Y(_0978_));
 sky130_fd_sc_hd__a22o_1 _1386_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_55_),
    .B1(net42),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_63_),
    .X(_0979_));
 sky130_fd_sc_hd__o21ai_0 _1387_ (.A1(_0978_),
    .A2(_0979_),
    .B1(net68),
    .Y(_0176_));
 sky130_fd_sc_hd__nand3_1 _1388_ (.A(_0975_),
    .B(_0176_),
    .C(_0772_),
    .Y(_0177_));
 sky130_fd_sc_hd__o21ai_0 _1389_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_71_),
    .B1(_0928_),
    .Y(_0178_));
 sky130_fd_sc_hd__nor2_1 _1390_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_79_),
    .B(net43),
    .Y(_0179_));
 sky130_fd_sc_hd__nor2_1 _1391_ (.A(_0178_),
    .B(_0179_),
    .Y(_0180_));
 sky130_fd_sc_hd__nand2_1 _1392_ (.A(net38),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_87_),
    .Y(_0181_));
 sky130_fd_sc_hd__nand2_1 _1393_ (.A(_0181_),
    .B(_0927_),
    .Y(_0182_));
 sky130_fd_sc_hd__inv_1 _1394_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_95_),
    .Y(_0183_));
 sky130_fd_sc_hd__inv_2 _1395_ (.A(net42),
    .Y(_0184_));
 sky130_fd_sc_hd__nor2_1 _1396_ (.A(_0183_),
    .B(_0184_),
    .Y(_0185_));
 sky130_fd_sc_hd__o21ai_0 _1397_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_103_),
    .B1(_0928_),
    .Y(_0186_));
 sky130_fd_sc_hd__nor2_1 _1398_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_111_),
    .B(net43),
    .Y(_0187_));
 sky130_fd_sc_hd__nor2_1 _1399_ (.A(_0186_),
    .B(_0187_),
    .Y(_0188_));
 sky130_fd_sc_hd__a22oi_1 _1400_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_119_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_127_),
    .B2(net42),
    .Y(_0189_));
 sky130_fd_sc_hd__nand2_1 _1401_ (.A(_0189_),
    .B(net68),
    .Y(_0190_));
 sky130_fd_sc_hd__o32ai_1 _1402_ (.A1(_0180_),
    .A2(_0182_),
    .A3(_0185_),
    .B1(_0188_),
    .B2(_0190_),
    .Y(_0191_));
 sky130_fd_sc_hd__nand2_1 _1403_ (.A(_0191_),
    .B(net67),
    .Y(_0192_));
 sky130_fd_sc_hd__nand3_1 _1404_ (.A(net35),
    .B(_0177_),
    .C(_0192_),
    .Y(_0193_));
 sky130_fd_sc_hd__a21oi_1 _1405_ (.A1(net94),
    .A2(_0861_),
    .B1(_0939_),
    .Y(_0194_));
 sky130_fd_sc_hd__nor2_1 _1406_ (.A(u_uart_reg_tl_o_23_),
    .B(net36),
    .Y(_0195_));
 sky130_fd_sc_hd__a21oi_1 _1407_ (.A1(_0193_),
    .A2(_0194_),
    .B1(_0195_),
    .Y(_0095_));
 sky130_fd_sc_hd__nand2_1 _1408_ (.A(net43),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_38_),
    .Y(_0196_));
 sky130_fd_sc_hd__nand2_1 _1409_ (.A(net70),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_46_),
    .Y(_0197_));
 sky130_fd_sc_hd__a21oi_1 _1410_ (.A1(_0196_),
    .A2(_0197_),
    .B1(net69),
    .Y(_0198_));
 sky130_fd_sc_hd__a221oi_1 _1411_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_54_),
    .A2(net38),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_62_),
    .B2(net42),
    .C1(_0198_),
    .Y(_0199_));
 sky130_fd_sc_hd__nor2_1 _1412_ (.A(_0927_),
    .B(_0199_),
    .Y(_0200_));
 sky130_fd_sc_hd__o21ai_0 _1413_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_6_),
    .B1(_0928_),
    .Y(_0201_));
 sky130_fd_sc_hd__nor2_1 _1414_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_14_),
    .B(net43),
    .Y(_0202_));
 sky130_fd_sc_hd__nor2_1 _1415_ (.A(_0201_),
    .B(_0202_),
    .Y(_0203_));
 sky130_fd_sc_hd__a221oi_1 _1416_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_22_),
    .A2(net38),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_30_),
    .B2(net42),
    .C1(_0203_),
    .Y(_0204_));
 sky130_fd_sc_hd__o21ai_0 _1417_ (.A1(net68),
    .A2(_0204_),
    .B1(_0772_),
    .Y(_0205_));
 sky130_fd_sc_hd__o21ai_0 _1418_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_102_),
    .B1(_0928_),
    .Y(_0206_));
 sky130_fd_sc_hd__nor2_1 _1419_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_110_),
    .B(net43),
    .Y(_0207_));
 sky130_fd_sc_hd__nor2_1 _1420_ (.A(_0206_),
    .B(_0207_),
    .Y(_0208_));
 sky130_fd_sc_hd__a22o_1 _1421_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_118_),
    .B1(net42),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_126_),
    .X(_0209_));
 sky130_fd_sc_hd__o21ai_0 _1422_ (.A1(_0208_),
    .A2(_0209_),
    .B1(net68),
    .Y(_0210_));
 sky130_fd_sc_hd__nand2_1 _1423_ (.A(net43),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_70_),
    .Y(_0211_));
 sky130_fd_sc_hd__nand2_1 _1424_ (.A(net70),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_78_),
    .Y(_0212_));
 sky130_fd_sc_hd__a21oi_1 _1425_ (.A1(_0211_),
    .A2(_0212_),
    .B1(net69),
    .Y(_0213_));
 sky130_fd_sc_hd__a22o_1 _1426_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_86_),
    .B1(net42),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_94_),
    .X(_0214_));
 sky130_fd_sc_hd__o21ai_0 _1427_ (.A1(_0213_),
    .A2(_0214_),
    .B1(_0927_),
    .Y(_0215_));
 sky130_fd_sc_hd__nand3_1 _1428_ (.A(_0210_),
    .B(_0215_),
    .C(net67),
    .Y(_0216_));
 sky130_fd_sc_hd__o211ai_1 _1429_ (.A1(_0200_),
    .A2(_0205_),
    .B1(_0216_),
    .C1(net35),
    .Y(_0217_));
 sky130_fd_sc_hd__a21oi_1 _1430_ (.A1(net95),
    .A2(_0861_),
    .B1(_0939_),
    .Y(_0218_));
 sky130_fd_sc_hd__nor2_1 _1431_ (.A(u_uart_reg_tl_o_22_),
    .B(_0884_),
    .Y(_0219_));
 sky130_fd_sc_hd__a21oi_1 _1432_ (.A1(_0217_),
    .A2(_0218_),
    .B1(_0219_),
    .Y(_0096_));
 sky130_fd_sc_hd__o21ai_0 _1433_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_5_),
    .B1(_0928_),
    .Y(_0220_));
 sky130_fd_sc_hd__nor2_1 _1434_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_13_),
    .B(net43),
    .Y(_0221_));
 sky130_fd_sc_hd__nor2_1 _1435_ (.A(_0220_),
    .B(_0221_),
    .Y(_0222_));
 sky130_fd_sc_hd__a221oi_1 _1436_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_21_),
    .A2(net38),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_29_),
    .B2(net42),
    .C1(_0222_),
    .Y(_0223_));
 sky130_fd_sc_hd__nor2_1 _1437_ (.A(net68),
    .B(_0223_),
    .Y(_0224_));
 sky130_fd_sc_hd__o21ai_0 _1438_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_37_),
    .B1(_0928_),
    .Y(_0225_));
 sky130_fd_sc_hd__nor2_1 _1439_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_45_),
    .B(net43),
    .Y(_0226_));
 sky130_fd_sc_hd__nor2_1 _1440_ (.A(_0225_),
    .B(_0226_),
    .Y(_0227_));
 sky130_fd_sc_hd__a221oi_1 _1441_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_53_),
    .A2(net38),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_61_),
    .B2(net42),
    .C1(_0227_),
    .Y(_0228_));
 sky130_fd_sc_hd__o21ai_0 _1442_ (.A1(_0927_),
    .A2(_0228_),
    .B1(_0772_),
    .Y(_0229_));
 sky130_fd_sc_hd__o21ai_0 _1443_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_69_),
    .B1(_0928_),
    .Y(_0230_));
 sky130_fd_sc_hd__nor2_1 _1444_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_77_),
    .B(net43),
    .Y(_0231_));
 sky130_fd_sc_hd__nor2_1 _1445_ (.A(_0230_),
    .B(_0231_),
    .Y(_0232_));
 sky130_fd_sc_hd__nand2_1 _1446_ (.A(net38),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_85_),
    .Y(_0233_));
 sky130_fd_sc_hd__nand2_1 _1447_ (.A(_0233_),
    .B(_0927_),
    .Y(_0234_));
 sky130_fd_sc_hd__inv_1 _1448_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_93_),
    .Y(_0235_));
 sky130_fd_sc_hd__nor2_1 _1449_ (.A(_0235_),
    .B(_0184_),
    .Y(_0236_));
 sky130_fd_sc_hd__o21ai_0 _1450_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_101_),
    .B1(_0928_),
    .Y(_0237_));
 sky130_fd_sc_hd__nor2_1 _1451_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_109_),
    .B(net43),
    .Y(_0238_));
 sky130_fd_sc_hd__nor2_1 _1452_ (.A(_0237_),
    .B(_0238_),
    .Y(_0239_));
 sky130_fd_sc_hd__a22oi_1 _1453_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_117_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_125_),
    .B2(net42),
    .Y(_0240_));
 sky130_fd_sc_hd__nand2_1 _1454_ (.A(_0240_),
    .B(net68),
    .Y(_0241_));
 sky130_fd_sc_hd__o32ai_1 _1455_ (.A1(_0232_),
    .A2(_0234_),
    .A3(_0236_),
    .B1(_0239_),
    .B2(_0241_),
    .Y(_0242_));
 sky130_fd_sc_hd__nand2_1 _1456_ (.A(_0242_),
    .B(net67),
    .Y(_0243_));
 sky130_fd_sc_hd__o211ai_1 _1457_ (.A1(_0224_),
    .A2(_0229_),
    .B1(_0243_),
    .C1(net35),
    .Y(_0244_));
 sky130_fd_sc_hd__nand2_1 _1458_ (.A(_0781_),
    .B(_0782_),
    .Y(_0245_));
 sky130_fd_sc_hd__inv_1 _1459_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_under_rst),
    .Y(_0246_));
 sky130_fd_sc_hd__nand2_1 _1460_ (.A(_0245_),
    .B(_0246_),
    .Y(_0247_));
 sky130_fd_sc_hd__nor3_1 _1461_ (.A(tl_i[64]),
    .B(tl_i[63]),
    .C(_0862_),
    .Y(_0248_));
 sky130_fd_sc_hd__a22oi_1 _1462_ (.A1(net100),
    .A2(_0861_),
    .B1(_0247_),
    .B2(_0248_),
    .Y(_0249_));
 sky130_fd_sc_hd__nor2_1 _1463_ (.A(u_uart_reg_tl_o_21_),
    .B(_0884_),
    .Y(_0250_));
 sky130_fd_sc_hd__a31oi_1 _1464_ (.A1(_0244_),
    .A2(_0249_),
    .A3(net32),
    .B1(_0250_),
    .Y(_0097_));
 sky130_fd_sc_hd__o21ai_0 _1465_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_4_),
    .B1(_0928_),
    .Y(_0251_));
 sky130_fd_sc_hd__nor2_1 _1466_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_12_),
    .B(net43),
    .Y(_0252_));
 sky130_fd_sc_hd__nor2_1 _1467_ (.A(_0251_),
    .B(_0252_),
    .Y(_0253_));
 sky130_fd_sc_hd__a22o_1 _1468_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_20_),
    .B1(net42),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_28_),
    .X(_0254_));
 sky130_fd_sc_hd__o21ai_0 _1469_ (.A1(_0253_),
    .A2(_0254_),
    .B1(_0927_),
    .Y(_0255_));
 sky130_fd_sc_hd__nand2_1 _1470_ (.A(net43),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_36_),
    .Y(_0256_));
 sky130_fd_sc_hd__nand2_1 _1471_ (.A(net70),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_44_),
    .Y(_0257_));
 sky130_fd_sc_hd__a21oi_1 _1472_ (.A1(_0256_),
    .A2(_0257_),
    .B1(net69),
    .Y(_0258_));
 sky130_fd_sc_hd__a22o_1 _1473_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_52_),
    .B1(net42),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_60_),
    .X(_0259_));
 sky130_fd_sc_hd__o21ai_0 _1474_ (.A1(_0258_),
    .A2(_0259_),
    .B1(net68),
    .Y(_0260_));
 sky130_fd_sc_hd__nand3_1 _1475_ (.A(_0255_),
    .B(_0260_),
    .C(_0772_),
    .Y(_0261_));
 sky130_fd_sc_hd__o21ai_0 _1476_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_100_),
    .B1(_0928_),
    .Y(_0262_));
 sky130_fd_sc_hd__nor2_1 _1477_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_108_),
    .B(net43),
    .Y(_0263_));
 sky130_fd_sc_hd__nor2_1 _1478_ (.A(_0262_),
    .B(_0263_),
    .Y(_0264_));
 sky130_fd_sc_hd__a22o_1 _1479_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_116_),
    .B1(net42),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_124_),
    .X(_0265_));
 sky130_fd_sc_hd__o21ai_0 _1480_ (.A1(_0264_),
    .A2(_0265_),
    .B1(net68),
    .Y(_0266_));
 sky130_fd_sc_hd__nand2_1 _1481_ (.A(net43),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_68_),
    .Y(_0267_));
 sky130_fd_sc_hd__nand2_1 _1482_ (.A(net70),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_76_),
    .Y(_0268_));
 sky130_fd_sc_hd__a21oi_1 _1483_ (.A1(_0267_),
    .A2(_0268_),
    .B1(net69),
    .Y(_0269_));
 sky130_fd_sc_hd__a22o_1 _1484_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_84_),
    .B1(net42),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_92_),
    .X(_0270_));
 sky130_fd_sc_hd__o21ai_0 _1485_ (.A1(_0269_),
    .A2(_0270_),
    .B1(_0927_),
    .Y(_0271_));
 sky130_fd_sc_hd__nand3_1 _1486_ (.A(_0266_),
    .B(_0271_),
    .C(net67),
    .Y(_0272_));
 sky130_fd_sc_hd__nand3_1 _1487_ (.A(net35),
    .B(_0261_),
    .C(_0272_),
    .Y(_0273_));
 sky130_fd_sc_hd__a22oi_1 _1488_ (.A1(net108),
    .A2(_0248_),
    .B1(_0861_),
    .B2(net93),
    .Y(_0274_));
 sky130_fd_sc_hd__nor2_1 _1489_ (.A(u_uart_reg_tl_o_20_),
    .B(_0884_),
    .Y(_0275_));
 sky130_fd_sc_hd__a31oi_1 _1490_ (.A1(_0273_),
    .A2(net32),
    .A3(_0274_),
    .B1(_0275_),
    .Y(_0098_));
 sky130_fd_sc_hd__inv_1 _1491_ (.A(_0681_),
    .Y(_0276_));
 sky130_fd_sc_hd__nor2_1 _1492_ (.A(_0687_),
    .B(_0276_),
    .Y(_0277_));
 sky130_fd_sc_hd__nor3_1 _1493_ (.A(_0678_),
    .B(_0684_),
    .C(_0277_),
    .Y(_0278_));
 sky130_fd_sc_hd__nor2_1 _1494_ (.A(_0683_),
    .B(_0278_),
    .Y(_0279_));
 sky130_fd_sc_hd__a21oi_1 _1495_ (.A1(_0279_),
    .A2(_0692_),
    .B1(_0936_),
    .Y(_0280_));
 sky130_fd_sc_hd__o31ai_1 _1496_ (.A1(_0691_),
    .A2(_0692_),
    .A3(_0279_),
    .B1(_0280_),
    .Y(_0281_));
 sky130_fd_sc_hd__o21ai_0 _1497_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_35_),
    .B1(_0928_),
    .Y(_0282_));
 sky130_fd_sc_hd__nor2_1 _1498_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_43_),
    .B(net43),
    .Y(_0283_));
 sky130_fd_sc_hd__nor2_1 _1499_ (.A(_0282_),
    .B(_0283_),
    .Y(_0284_));
 sky130_fd_sc_hd__a22o_1 _1500_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_51_),
    .B1(net42),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_59_),
    .X(_0285_));
 sky130_fd_sc_hd__o21ai_0 _1501_ (.A1(_0284_),
    .A2(_0285_),
    .B1(net68),
    .Y(_0286_));
 sky130_fd_sc_hd__nand2_1 _1502_ (.A(net43),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_3_),
    .Y(_0287_));
 sky130_fd_sc_hd__nand2_1 _1503_ (.A(net70),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_11_),
    .Y(_0288_));
 sky130_fd_sc_hd__a21oi_1 _1504_ (.A1(_0287_),
    .A2(_0288_),
    .B1(net69),
    .Y(_0289_));
 sky130_fd_sc_hd__a22o_1 _1505_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_19_),
    .B1(net42),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_27_),
    .X(_0290_));
 sky130_fd_sc_hd__o21ai_0 _1506_ (.A1(_0289_),
    .A2(_0290_),
    .B1(_0927_),
    .Y(_0291_));
 sky130_fd_sc_hd__nand3_1 _1507_ (.A(_0286_),
    .B(_0291_),
    .C(_0772_),
    .Y(_0292_));
 sky130_fd_sc_hd__o21ai_0 _1508_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_99_),
    .B1(_0928_),
    .Y(_0293_));
 sky130_fd_sc_hd__nor2_1 _1509_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_107_),
    .B(net43),
    .Y(_0294_));
 sky130_fd_sc_hd__nor2_1 _1510_ (.A(_0293_),
    .B(_0294_),
    .Y(_0295_));
 sky130_fd_sc_hd__a22o_1 _1511_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_115_),
    .B1(net42),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_123_),
    .X(_0296_));
 sky130_fd_sc_hd__o21ai_0 _1512_ (.A1(_0295_),
    .A2(_0296_),
    .B1(net68),
    .Y(_0297_));
 sky130_fd_sc_hd__nand2_1 _1513_ (.A(net43),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_67_),
    .Y(_0298_));
 sky130_fd_sc_hd__nand2_1 _1514_ (.A(net70),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_75_),
    .Y(_0299_));
 sky130_fd_sc_hd__a21oi_1 _1515_ (.A1(_0298_),
    .A2(_0299_),
    .B1(net69),
    .Y(_0300_));
 sky130_fd_sc_hd__a22o_1 _1516_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_83_),
    .B1(net42),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_91_),
    .X(_0301_));
 sky130_fd_sc_hd__o21ai_0 _1517_ (.A1(_0300_),
    .A2(_0301_),
    .B1(_0927_),
    .Y(_0302_));
 sky130_fd_sc_hd__nand3_1 _1518_ (.A(_0297_),
    .B(_0302_),
    .C(net67),
    .Y(_0303_));
 sky130_fd_sc_hd__nand3_1 _1519_ (.A(net35),
    .B(_0292_),
    .C(_0303_),
    .Y(_0304_));
 sky130_fd_sc_hd__nor2_2 _1520_ (.A(_0693_),
    .B(_0690_),
    .Y(_0305_));
 sky130_fd_sc_hd__inv_2 _1521_ (.A(_0305_),
    .Y(_0306_));
 sky130_fd_sc_hd__inv_1 _1522_ (.A(_0248_),
    .Y(_0307_));
 sky130_fd_sc_hd__a21oi_1 _1523_ (.A1(_0306_),
    .A2(_0695_),
    .B1(_0307_),
    .Y(_0308_));
 sky130_fd_sc_hd__lpflow_clkinvkapwr_1 _1524_ (.A(net92),
    .Y(_0309_));
 sky130_fd_sc_hd__nor2_1 _1525_ (.A(u_uart_core_uart_tx_bit_cnt_q_0_),
    .B(u_uart_core_uart_tx_bit_cnt_q_1_),
    .Y(_0310_));
 sky130_fd_sc_hd__clkinv_1 _1526_ (.A(u_uart_core_uart_tx_bit_cnt_q_2_),
    .Y(_0311_));
 sky130_fd_sc_hd__nand2_1 _1527_ (.A(_0310_),
    .B(_0311_),
    .Y(_0312_));
 sky130_fd_sc_hd__nor2_1 _1528_ (.A(u_uart_core_uart_tx_bit_cnt_q_3_),
    .B(_0312_),
    .Y(_0313_));
 sky130_fd_sc_hd__nor2_2 _1529_ (.A(net54),
    .B(_0313_),
    .Y(_0314_));
 sky130_fd_sc_hd__nand2_1 _1530_ (.A(net32),
    .B(_0314_),
    .Y(_0315_));
 sky130_fd_sc_hd__o21ai_0 _1531_ (.A1(_0939_),
    .A2(_0308_),
    .B1(_0315_),
    .Y(_0316_));
 sky130_fd_sc_hd__nor2_1 _1532_ (.A(u_uart_reg_tl_o_19_),
    .B(_0884_),
    .Y(_0317_));
 sky130_fd_sc_hd__a31oi_1 _1533_ (.A1(_0281_),
    .A2(_0304_),
    .A3(_0316_),
    .B1(_0317_),
    .Y(_0099_));
 sky130_fd_sc_hd__nor2_1 _1534_ (.A(_0678_),
    .B(_0277_),
    .Y(_0318_));
 sky130_fd_sc_hd__xnor2_1 _1535_ (.A(_0685_),
    .B(_0318_),
    .Y(_0319_));
 sky130_fd_sc_hd__nand2_1 _1536_ (.A(_0319_),
    .B(_0863_),
    .Y(_0320_));
 sky130_fd_sc_hd__nor2_1 _1537_ (.A(net70),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_2_),
    .Y(_0321_));
 sky130_fd_sc_hd__nor2_1 _1538_ (.A(net69),
    .B(_0321_),
    .Y(_0322_));
 sky130_fd_sc_hd__o21ai_0 _1539_ (.A1(net43),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_10_),
    .B1(_0322_),
    .Y(_0323_));
 sky130_fd_sc_hd__nand2_1 _1540_ (.A(net38),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_18_),
    .Y(_0324_));
 sky130_fd_sc_hd__a21oi_1 _1541_ (.A1(net42),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_26_),
    .B1(net68),
    .Y(_0325_));
 sky130_fd_sc_hd__a221oi_1 _1542_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_50_),
    .B1(net42),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_58_),
    .C1(_0927_),
    .Y(_0326_));
 sky130_fd_sc_hd__nor2_1 _1543_ (.A(net70),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_34_),
    .Y(_0327_));
 sky130_fd_sc_hd__nor2_1 _1544_ (.A(net69),
    .B(_0327_),
    .Y(_0328_));
 sky130_fd_sc_hd__o21ai_0 _1545_ (.A1(net43),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_42_),
    .B1(_0328_),
    .Y(_0329_));
 sky130_fd_sc_hd__a32oi_1 _1546_ (.A1(_0323_),
    .A2(_0324_),
    .A3(_0325_),
    .B1(_0326_),
    .B2(_0329_),
    .Y(_0330_));
 sky130_fd_sc_hd__o21ai_0 _1547_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_98_),
    .B1(_0928_),
    .Y(_0331_));
 sky130_fd_sc_hd__nor2_1 _1548_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_106_),
    .B(_0776_),
    .Y(_0332_));
 sky130_fd_sc_hd__nor2_1 _1549_ (.A(_0331_),
    .B(_0332_),
    .Y(_0333_));
 sky130_fd_sc_hd__nand2_1 _1550_ (.A(net38),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_114_),
    .Y(_0334_));
 sky130_fd_sc_hd__nand2_1 _1551_ (.A(_0334_),
    .B(net68),
    .Y(_0335_));
 sky130_fd_sc_hd__inv_1 _1552_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_122_),
    .Y(_0336_));
 sky130_fd_sc_hd__nor2_1 _1553_ (.A(_0336_),
    .B(_0184_),
    .Y(_0337_));
 sky130_fd_sc_hd__o21ai_0 _1554_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_66_),
    .B1(_0928_),
    .Y(_0338_));
 sky130_fd_sc_hd__nor2_1 _1555_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_74_),
    .B(net43),
    .Y(_0339_));
 sky130_fd_sc_hd__nor2_1 _1556_ (.A(_0338_),
    .B(_0339_),
    .Y(_0340_));
 sky130_fd_sc_hd__a22oi_1 _1557_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_82_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_90_),
    .B2(net42),
    .Y(_0341_));
 sky130_fd_sc_hd__nand2_1 _1558_ (.A(_0341_),
    .B(_0927_),
    .Y(_0342_));
 sky130_fd_sc_hd__o32ai_1 _1559_ (.A1(_0333_),
    .A2(_0335_),
    .A3(_0337_),
    .B1(_0340_),
    .B2(_0342_),
    .Y(_0343_));
 sky130_fd_sc_hd__nand2_1 _1560_ (.A(_0343_),
    .B(net67),
    .Y(_0344_));
 sky130_fd_sc_hd__o211ai_1 _1561_ (.A1(net67),
    .A2(_0330_),
    .B1(_0344_),
    .C1(net35),
    .Y(_0345_));
 sky130_fd_sc_hd__a211oi_1 _1562_ (.A1(reg2hw_36_),
    .A2(_0861_),
    .B1(_0939_),
    .C1(_0308_),
    .Y(_0346_));
 sky130_fd_sc_hd__nor2_1 _1563_ (.A(u_uart_reg_tl_o_18_),
    .B(_0884_),
    .Y(_0347_));
 sky130_fd_sc_hd__a31oi_1 _1564_ (.A1(_0320_),
    .A2(_0345_),
    .A3(_0346_),
    .B1(_0347_),
    .Y(_0100_));
 sky130_fd_sc_hd__nand2_1 _1565_ (.A(_0276_),
    .B(_0687_),
    .Y(_0348_));
 sky130_fd_sc_hd__nor2_1 _1566_ (.A(_0936_),
    .B(_0277_),
    .Y(_0349_));
 sky130_fd_sc_hd__o21ai_0 _1567_ (.A1(_0307_),
    .A2(_0786_),
    .B1(net32),
    .Y(_0350_));
 sky130_fd_sc_hd__a221oi_1 _1568_ (.A1(reg2hw_35_),
    .A2(_0861_),
    .B1(_0348_),
    .B2(_0349_),
    .C1(_0350_),
    .Y(_0351_));
 sky130_fd_sc_hd__nor2_1 _1569_ (.A(net70),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_65_),
    .Y(_0352_));
 sky130_fd_sc_hd__nor2_1 _1570_ (.A(net69),
    .B(_0352_),
    .Y(_0353_));
 sky130_fd_sc_hd__o21ai_0 _1571_ (.A1(net43),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_73_),
    .B1(_0353_),
    .Y(_0354_));
 sky130_fd_sc_hd__nand2_1 _1572_ (.A(net42),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_89_),
    .Y(_0355_));
 sky130_fd_sc_hd__a21oi_1 _1573_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_81_),
    .B1(net68),
    .Y(_0356_));
 sky130_fd_sc_hd__a221oi_1 _1574_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_113_),
    .B1(net42),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_121_),
    .C1(_0927_),
    .Y(_0357_));
 sky130_fd_sc_hd__nor2_1 _1575_ (.A(net70),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_97_),
    .Y(_0358_));
 sky130_fd_sc_hd__nor2_1 _1576_ (.A(net69),
    .B(_0358_),
    .Y(_0359_));
 sky130_fd_sc_hd__o21ai_0 _1577_ (.A1(net43),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_105_),
    .B1(_0359_),
    .Y(_0360_));
 sky130_fd_sc_hd__a32oi_1 _1578_ (.A1(_0354_),
    .A2(_0355_),
    .A3(_0356_),
    .B1(_0357_),
    .B2(_0360_),
    .Y(_0361_));
 sky130_fd_sc_hd__o21ai_0 _1579_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_33_),
    .B1(_0928_),
    .Y(_0362_));
 sky130_fd_sc_hd__nor2_1 _1580_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_41_),
    .B(net43),
    .Y(_0363_));
 sky130_fd_sc_hd__nor2_1 _1581_ (.A(_0362_),
    .B(_0363_),
    .Y(_0364_));
 sky130_fd_sc_hd__nand2_1 _1582_ (.A(net38),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_49_),
    .Y(_0365_));
 sky130_fd_sc_hd__nand2_1 _1583_ (.A(_0365_),
    .B(net68),
    .Y(_0366_));
 sky130_fd_sc_hd__inv_1 _1584_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_57_),
    .Y(_0367_));
 sky130_fd_sc_hd__nor2_1 _1585_ (.A(_0367_),
    .B(_0184_),
    .Y(_0368_));
 sky130_fd_sc_hd__o21ai_0 _1586_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_1_),
    .B1(_0928_),
    .Y(_0369_));
 sky130_fd_sc_hd__nor2_1 _1587_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_9_),
    .B(net43),
    .Y(_0370_));
 sky130_fd_sc_hd__nor2_1 _1588_ (.A(_0369_),
    .B(_0370_),
    .Y(_0371_));
 sky130_fd_sc_hd__a22oi_1 _1589_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_17_),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_25_),
    .B2(net42),
    .Y(_0372_));
 sky130_fd_sc_hd__nand2_1 _1590_ (.A(_0372_),
    .B(_0927_),
    .Y(_0373_));
 sky130_fd_sc_hd__o32ai_1 _1591_ (.A1(_0364_),
    .A2(_0366_),
    .A3(_0368_),
    .B1(_0371_),
    .B2(_0373_),
    .Y(_0374_));
 sky130_fd_sc_hd__nand2_1 _1592_ (.A(_0374_),
    .B(_0772_),
    .Y(_0375_));
 sky130_fd_sc_hd__o211ai_1 _1593_ (.A1(_0772_),
    .A2(_0361_),
    .B1(_0375_),
    .C1(net35),
    .Y(_0376_));
 sky130_fd_sc_hd__nor2_1 _1594_ (.A(u_uart_reg_tl_o_17_),
    .B(_0884_),
    .Y(_0377_));
 sky130_fd_sc_hd__a21oi_1 _1595_ (.A1(_0351_),
    .A2(_0376_),
    .B1(_0377_),
    .Y(_0101_));
 sky130_fd_sc_hd__o21ai_0 _1596_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_96_),
    .B1(_0928_),
    .Y(_0378_));
 sky130_fd_sc_hd__nor2_1 _1597_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_104_),
    .B(net43),
    .Y(_0379_));
 sky130_fd_sc_hd__nor2_1 _1598_ (.A(_0378_),
    .B(_0379_),
    .Y(_0380_));
 sky130_fd_sc_hd__a221oi_1 _1599_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_112_),
    .A2(net38),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_120_),
    .B2(net42),
    .C1(_0380_),
    .Y(_0381_));
 sky130_fd_sc_hd__nor2_1 _1600_ (.A(_0927_),
    .B(_0381_),
    .Y(_0382_));
 sky130_fd_sc_hd__nand2_1 _1601_ (.A(net43),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_64_),
    .Y(_0383_));
 sky130_fd_sc_hd__nand2_1 _1602_ (.A(net70),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_72_),
    .Y(_0384_));
 sky130_fd_sc_hd__a21oi_1 _1603_ (.A1(_0383_),
    .A2(_0384_),
    .B1(net69),
    .Y(_0385_));
 sky130_fd_sc_hd__a221oi_1 _1604_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_80_),
    .A2(net38),
    .B1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_88_),
    .B2(net42),
    .C1(_0385_),
    .Y(_0386_));
 sky130_fd_sc_hd__o21ai_0 _1605_ (.A1(net68),
    .A2(_0386_),
    .B1(net67),
    .Y(_0387_));
 sky130_fd_sc_hd__o21ai_0 _1606_ (.A1(net70),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_0_),
    .B1(_0928_),
    .Y(_0388_));
 sky130_fd_sc_hd__nor2_1 _1607_ (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_8_),
    .B(net43),
    .Y(_0389_));
 sky130_fd_sc_hd__nor2_1 _1608_ (.A(_0388_),
    .B(_0389_),
    .Y(_0390_));
 sky130_fd_sc_hd__a22o_1 _1609_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_16_),
    .B1(net42),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_24_),
    .X(_0391_));
 sky130_fd_sc_hd__o21ai_0 _1610_ (.A1(_0390_),
    .A2(_0391_),
    .B1(_0927_),
    .Y(_0392_));
 sky130_fd_sc_hd__nand2_1 _1611_ (.A(net43),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_32_),
    .Y(_0393_));
 sky130_fd_sc_hd__nand2_1 _1612_ (.A(net70),
    .B(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_40_),
    .Y(_0394_));
 sky130_fd_sc_hd__a21oi_1 _1613_ (.A1(_0393_),
    .A2(_0394_),
    .B1(net69),
    .Y(_0395_));
 sky130_fd_sc_hd__a22o_1 _1614_ (.A1(net38),
    .A2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_48_),
    .B1(net42),
    .B2(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_56_),
    .X(_0396_));
 sky130_fd_sc_hd__o21ai_0 _1615_ (.A1(_0395_),
    .A2(_0396_),
    .B1(net68),
    .Y(_0397_));
 sky130_fd_sc_hd__nand3_1 _1616_ (.A(_0392_),
    .B(_0397_),
    .C(_0772_),
    .Y(_0398_));
 sky130_fd_sc_hd__o211ai_1 _1617_ (.A1(_0382_),
    .A2(_0387_),
    .B1(_0398_),
    .C1(net35),
    .Y(_0399_));
 sky130_fd_sc_hd__o22ai_1 _1618_ (.A1(net54),
    .A2(_0860_),
    .B1(_0689_),
    .B2(_0936_),
    .Y(_0400_));
 sky130_fd_sc_hd__a21oi_1 _1619_ (.A1(_0694_),
    .A2(_0695_),
    .B1(_0307_),
    .Y(_0401_));
 sky130_fd_sc_hd__nor3_1 _1620_ (.A(_0939_),
    .B(_0400_),
    .C(_0401_),
    .Y(_0402_));
 sky130_fd_sc_hd__nor2_1 _1621_ (.A(u_uart_reg_tl_o_16_),
    .B(_0884_),
    .Y(_0403_));
 sky130_fd_sc_hd__a21oi_1 _1622_ (.A1(_0399_),
    .A2(_0402_),
    .B1(_0403_),
    .Y(_0102_));
 sky130_fd_sc_hd__nor3_4 _1623_ (.A(net83),
    .B(_0314_),
    .C(_0305_),
    .Y(_0404_));
 sky130_fd_sc_hd__xor2_1 _1624_ (.A(_0311_),
    .B(_0310_),
    .X(_0405_));
 sky130_fd_sc_hd__o21ai_1 _1625_ (.A1(u_uart_core_uart_tx_bit_cnt_q_3_),
    .A2(_0312_),
    .B1(u_uart_core_uart_tx_tick_baud_q),
    .Y(_0406_));
 sky130_fd_sc_hd__inv_2 _1626_ (.A(_0406_),
    .Y(_0407_));
 sky130_fd_sc_hd__nor2_1 _1627_ (.A(net54),
    .B(_0407_),
    .Y(_0408_));
 sky130_fd_sc_hd__clkinv_1 _1628_ (.A(_0408_),
    .Y(_0409_));
 sky130_fd_sc_hd__nor2_2 _1629_ (.A(_0409_),
    .B(_0404_),
    .Y(_0410_));
 sky130_fd_sc_hd__nor2_2 _1630_ (.A(net54),
    .B(_0410_),
    .Y(_0411_));
 sky130_fd_sc_hd__inv_1 _1631_ (.A(_0411_),
    .Y(_0412_));
 sky130_fd_sc_hd__inv_2 _1632_ (.A(_0410_),
    .Y(_0413_));
 sky130_fd_sc_hd__o32ai_1 _1633_ (.A1(_0404_),
    .A2(_0405_),
    .A3(_0412_),
    .B1(_0311_),
    .B2(_0413_),
    .Y(_0103_));
 sky130_fd_sc_hd__inv_1 _1634_ (.A(u_uart_core_uart_tx_bit_cnt_q_0_),
    .Y(_0414_));
 sky130_fd_sc_hd__o21ai_0 _1635_ (.A1(_0414_),
    .A2(net54),
    .B1(_0413_),
    .Y(_0415_));
 sky130_fd_sc_hd__a22o_1 _1636_ (.A1(_0310_),
    .A2(_0411_),
    .B1(_0415_),
    .B2(u_uart_core_uart_tx_bit_cnt_q_1_),
    .X(_0104_));
 sky130_fd_sc_hd__inv_2 _1637_ (.A(_0404_),
    .Y(_0416_));
 sky130_fd_sc_hd__nor2_1 _1638_ (.A(net54),
    .B(_0416_),
    .Y(_0417_));
 sky130_fd_sc_hd__inv_1 _1639_ (.A(_0417_),
    .Y(_0418_));
 sky130_fd_sc_hd__nor2_1 _1640_ (.A(_0797_),
    .B(_0418_),
    .Y(_0419_));
 sky130_fd_sc_hd__a21oi_1 _1641_ (.A1(_0414_),
    .A2(_0418_),
    .B1(_0419_),
    .Y(_0420_));
 sky130_fd_sc_hd__o22ai_1 _1642_ (.A1(_0414_),
    .A2(_0413_),
    .B1(_0412_),
    .B2(_0420_),
    .Y(_0105_));
 sky130_fd_sc_hd__nand3_1 _1643_ (.A(u_uart_core_uart_tx_baud_div_q_1_),
    .B(u_uart_core_uart_tx_baud_div_q_0_),
    .C(net76),
    .Y(_0421_));
 sky130_fd_sc_hd__xnor2_1 _1644_ (.A(u_uart_core_uart_tx_baud_div_q_2_),
    .B(_0421_),
    .Y(_0106_));
 sky130_fd_sc_hd__a21oi_1 _1645_ (.A1(u_uart_core_uart_tx_baud_div_q_0_),
    .A2(net76),
    .B1(u_uart_core_uart_tx_baud_div_q_1_),
    .Y(_0422_));
 sky130_fd_sc_hd__inv_1 _1646_ (.A(_0421_),
    .Y(_0423_));
 sky130_fd_sc_hd__nor2_1 _1647_ (.A(_0422_),
    .B(_0423_),
    .Y(_0107_));
 sky130_fd_sc_hd__xor2_1 _1648_ (.A(u_uart_core_uart_tx_baud_div_q_0_),
    .B(net76),
    .X(_0108_));
 sky130_fd_sc_hd__inv_1 _1649_ (.A(net93),
    .Y(_0424_));
 sky130_fd_sc_hd__inv_1 _1650_ (.A(u_uart_core_rx_sync_q2),
    .Y(_0425_));
 sky130_fd_sc_hd__a21oi_1 _1651_ (.A1(reg2hw_36_),
    .A2(u_uart_core_rx_sync_q1),
    .B1(u_uart_core_rx_sync),
    .Y(_0426_));
 sky130_fd_sc_hd__nor2_1 _1652_ (.A(net100),
    .B(net93),
    .Y(_0427_));
 sky130_fd_sc_hd__inv_1 _1653_ (.A(reg2hw_36_),
    .Y(_0428_));
 sky130_fd_sc_hd__o21ai_0 _1654_ (.A1(u_uart_core_rx_sync_q1),
    .A2(_0428_),
    .B1(u_uart_core_rx_sync),
    .Y(_0429_));
 sky130_fd_sc_hd__o211ai_1 _1655_ (.A1(_0425_),
    .A2(_0426_),
    .B1(_0427_),
    .C1(_0429_),
    .Y(_0430_));
 sky130_fd_sc_hd__o21ai_0 _1656_ (.A1(_0424_),
    .A2(u_uart_core_tx_out),
    .B1(_0430_),
    .Y(_0431_));
 sky130_fd_sc_hd__clkinv_2 _1657_ (.A(_0431_),
    .Y(_0432_));
 sky130_fd_sc_hd__inv_1 _1658_ (.A(net109),
    .Y(_0433_));
 sky130_fd_sc_hd__inv_1 _1659_ (.A(u_uart_core_uart_rx_bit_cnt_q_3_),
    .Y(_0434_));
 sky130_fd_sc_hd__xor2_1 _1660_ (.A(net110),
    .B(net95),
    .X(_0435_));
 sky130_fd_sc_hd__nor4_1 _1661_ (.A(u_uart_core_uart_rx_bit_cnt_q_2_),
    .B(_0433_),
    .C(_0434_),
    .D(_0435_),
    .Y(_0436_));
 sky130_fd_sc_hd__nand2_4 _1662_ (.A(_0432_),
    .B(_0436_),
    .Y(_0437_));
 sky130_fd_sc_hd__inv_1 _1663_ (.A(u_uart_core_rx_tick_baud),
    .Y(_0438_));
 sky130_fd_sc_hd__nor2_2 _1664_ (.A(net108),
    .B(_0438_),
    .Y(_0439_));
 sky130_fd_sc_hd__nand2_4 _1665_ (.A(_0437_),
    .B(_0439_),
    .Y(_0440_));
 sky130_fd_sc_hd__clkinv_1 _1666_ (.A(u_uart_core_uart_rx_sreg_q_9_),
    .Y(_0441_));
 sky130_fd_sc_hd__inv_1 _1667_ (.A(_0437_),
    .Y(_0442_));
 sky130_fd_sc_hd__inv_1 _1668_ (.A(net108),
    .Y(_0443_));
 sky130_fd_sc_hd__nor2_4 _1669_ (.A(_0443_),
    .B(_0432_),
    .Y(_0444_));
 sky130_fd_sc_hd__nor2_2 _1670_ (.A(_0439_),
    .B(_0444_),
    .Y(_0445_));
 sky130_fd_sc_hd__nor2_4 _1671_ (.A(_0442_),
    .B(_0445_),
    .Y(_0446_));
 sky130_fd_sc_hd__o22ai_1 _1672_ (.A1(_0765_),
    .A2(_0440_),
    .B1(_0441_),
    .B2(_0446_),
    .Y(_0109_));
 sky130_fd_sc_hd__o22ai_1 _1673_ (.A1(_0441_),
    .A2(_0440_),
    .B1(_0832_),
    .B2(_0446_),
    .Y(_0110_));
 sky130_fd_sc_hd__o22ai_1 _1674_ (.A1(_0832_),
    .A2(_0440_),
    .B1(_0836_),
    .B2(_0446_),
    .Y(_0111_));
 sky130_fd_sc_hd__o22ai_1 _1675_ (.A1(_0836_),
    .A2(_0440_),
    .B1(_0838_),
    .B2(_0446_),
    .Y(_0112_));
 sky130_fd_sc_hd__o22ai_1 _1676_ (.A1(_0838_),
    .A2(_0440_),
    .B1(_0840_),
    .B2(_0446_),
    .Y(_0113_));
 sky130_fd_sc_hd__o22ai_1 _1677_ (.A1(_0840_),
    .A2(_0440_),
    .B1(_0842_),
    .B2(_0446_),
    .Y(_0114_));
 sky130_fd_sc_hd__o22ai_1 _1678_ (.A1(_0842_),
    .A2(_0440_),
    .B1(_0844_),
    .B2(_0446_),
    .Y(_0115_));
 sky130_fd_sc_hd__o22ai_1 _1679_ (.A1(_0844_),
    .A2(_0440_),
    .B1(_0846_),
    .B2(_0446_),
    .Y(_0116_));
 sky130_fd_sc_hd__inv_1 _1680_ (.A(u_uart_core_uart_rx_sreg_q_1_),
    .Y(_0447_));
 sky130_fd_sc_hd__o22ai_1 _1681_ (.A1(_0846_),
    .A2(_0440_),
    .B1(_0447_),
    .B2(_0446_),
    .Y(_0117_));
 sky130_fd_sc_hd__inv_1 _1682_ (.A(_0446_),
    .Y(_0448_));
 sky130_fd_sc_hd__nor4_1 _1683_ (.A(u_uart_core_uart_rx_bit_cnt_q_2_),
    .B(net110),
    .C(net109),
    .D(_0440_),
    .Y(_0449_));
 sky130_fd_sc_hd__inv_1 _1684_ (.A(_0449_),
    .Y(_0450_));
 sky130_fd_sc_hd__inv_1 _1685_ (.A(net110),
    .Y(_0451_));
 sky130_fd_sc_hd__a21oi_1 _1686_ (.A1(_0451_),
    .A2(_0433_),
    .B1(_0440_),
    .Y(_0452_));
 sky130_fd_sc_hd__o21ai_0 _1687_ (.A1(_0445_),
    .A2(_0452_),
    .B1(u_uart_core_uart_rx_bit_cnt_q_2_),
    .Y(_0453_));
 sky130_fd_sc_hd__nand2_1 _1688_ (.A(_0450_),
    .B(_0453_),
    .Y(_0118_));
 sky130_fd_sc_hd__nor2_1 _1689_ (.A(net109),
    .B(_0451_),
    .Y(_0454_));
 sky130_fd_sc_hd__nor2_1 _1690_ (.A(net110),
    .B(_0433_),
    .Y(_0455_));
 sky130_fd_sc_hd__nor2_1 _1691_ (.A(net109),
    .B(_0444_),
    .Y(_0456_));
 sky130_fd_sc_hd__o32ai_1 _1692_ (.A1(_0454_),
    .A2(_0455_),
    .A3(_0440_),
    .B1(_0439_),
    .B2(_0456_),
    .Y(_0119_));
 sky130_fd_sc_hd__inv_1 _1693_ (.A(_0444_),
    .Y(_0457_));
 sky130_fd_sc_hd__nand2_1 _1694_ (.A(_0445_),
    .B(net110),
    .Y(_0458_));
 sky130_fd_sc_hd__o221ai_1 _1695_ (.A1(net110),
    .A2(_0440_),
    .B1(_0797_),
    .B2(_0457_),
    .C1(_0458_),
    .Y(_0120_));
 sky130_fd_sc_hd__nand2_1 _1696_ (.A(u_uart_core_uart_rx_baud_div_q_0_),
    .B(net76),
    .Y(_0459_));
 sky130_fd_sc_hd__inv_1 _1697_ (.A(_0459_),
    .Y(_0460_));
 sky130_fd_sc_hd__nand2_1 _1698_ (.A(_0460_),
    .B(u_uart_core_uart_rx_baud_div_q_1_),
    .Y(_0461_));
 sky130_fd_sc_hd__clkinv_1 _1699_ (.A(_0461_),
    .Y(_0462_));
 sky130_fd_sc_hd__a21oi_1 _1700_ (.A1(u_uart_core_uart_rx_baud_div_q_2_),
    .A2(_0462_),
    .B1(_0444_),
    .Y(_0463_));
 sky130_fd_sc_hd__o21a_1 _1701_ (.A1(u_uart_core_uart_rx_baud_div_q_2_),
    .A2(_0462_),
    .B1(_0463_),
    .X(_0121_));
 sky130_fd_sc_hd__nor2_1 _1702_ (.A(u_uart_core_uart_rx_baud_div_q_1_),
    .B(_0460_),
    .Y(_0464_));
 sky130_fd_sc_hd__nor3_1 _1703_ (.A(_0462_),
    .B(_0464_),
    .C(_0444_),
    .Y(_0122_));
 sky130_fd_sc_hd__nor2_1 _1704_ (.A(u_uart_core_uart_rx_baud_div_q_0_),
    .B(net76),
    .Y(_0465_));
 sky130_fd_sc_hd__nor3_1 _1705_ (.A(_0460_),
    .B(_0465_),
    .C(_0444_),
    .Y(_0123_));
 sky130_fd_sc_hd__nor2_1 _1706_ (.A(net111),
    .B(_0759_),
    .Y(_0466_));
 sky130_fd_sc_hd__clkinv_1 _1707_ (.A(reg2hw_0_),
    .Y(_0467_));
 sky130_fd_sc_hd__clkinv_1 _1708_ (.A(reg2hw_3_),
    .Y(_0468_));
 sky130_fd_sc_hd__nor2_2 _1709_ (.A(_0467_),
    .B(_0468_),
    .Y(_0469_));
 sky130_fd_sc_hd__nor3_1 _1710_ (.A(_0466_),
    .B(_0469_),
    .C(_0018_),
    .Y(_0124_));
 sky130_fd_sc_hd__nor2_1 _1711_ (.A(net112),
    .B(_0757_),
    .Y(_0470_));
 sky130_fd_sc_hd__nor3_1 _1712_ (.A(_0469_),
    .B(_0470_),
    .C(_0759_),
    .Y(_0125_));
 sky130_fd_sc_hd__nor2_1 _1713_ (.A(net59),
    .B(_0806_),
    .Y(_0471_));
 sky130_fd_sc_hd__nor3_1 _1714_ (.A(_0757_),
    .B(_0469_),
    .C(_0471_),
    .Y(_0126_));
 sky130_fd_sc_hd__buf_2 _1715_ (.A(_0686_),
    .X(_0472_));
 sky130_fd_sc_hd__nor2_1 _1716_ (.A(net41),
    .B(_0418_),
    .Y(_0473_));
 sky130_fd_sc_hd__nand2_1 _1717_ (.A(_0473_),
    .B(net61),
    .Y(_0474_));
 sky130_fd_sc_hd__nor2_1 _1718_ (.A(_0682_),
    .B(_0474_),
    .Y(_0475_));
 sky130_fd_sc_hd__inv_1 _1719_ (.A(_0474_),
    .Y(_0476_));
 sky130_fd_sc_hd__nor2_1 _1720_ (.A(net60),
    .B(_0476_),
    .Y(_0477_));
 sky130_fd_sc_hd__nor3_1 _1721_ (.A(_0469_),
    .B(_0475_),
    .C(_0477_),
    .Y(_0127_));
 sky130_fd_sc_hd__nor2_1 _1722_ (.A(net61),
    .B(_0473_),
    .Y(_0478_));
 sky130_fd_sc_hd__nor3_1 _1723_ (.A(_0469_),
    .B(_0478_),
    .C(_0476_),
    .Y(_0128_));
 sky130_fd_sc_hd__nor2_1 _1724_ (.A(net62),
    .B(_0417_),
    .Y(_0479_));
 sky130_fd_sc_hd__nor3_1 _1725_ (.A(_0469_),
    .B(_0479_),
    .C(_0473_),
    .Y(_0129_));
 sky130_fd_sc_hd__nor2_1 _1726_ (.A(net63),
    .B(_0810_),
    .Y(_0480_));
 sky130_fd_sc_hd__nand2_1 _1727_ (.A(reg2hw_1_),
    .B(reg2hw_0_),
    .Y(_0481_));
 sky130_fd_sc_hd__lpflow_clkinvkapwr_1 _1728_ (.A(_0481_),
    .Y(_0482_));
 sky130_fd_sc_hd__nor3_1 _1729_ (.A(_0480_),
    .B(net40),
    .C(_0035_),
    .Y(_0130_));
 sky130_fd_sc_hd__inv_1 _1730_ (.A(_0809_),
    .Y(_0483_));
 sky130_fd_sc_hd__nor2_1 _1731_ (.A(net64),
    .B(_0483_),
    .Y(_0484_));
 sky130_fd_sc_hd__nor3_1 _1732_ (.A(_0810_),
    .B(net40),
    .C(_0484_),
    .Y(_0131_));
 sky130_fd_sc_hd__nor2_1 _1733_ (.A(net65),
    .B(_0808_),
    .Y(_0485_));
 sky130_fd_sc_hd__nor3_1 _1734_ (.A(net40),
    .B(_0485_),
    .C(_0483_),
    .Y(_0132_));
 sky130_fd_sc_hd__nor2_1 _1735_ (.A(net66),
    .B(_0801_),
    .Y(_0486_));
 sky130_fd_sc_hd__nor3_1 _1736_ (.A(_0808_),
    .B(net40),
    .C(_0486_),
    .Y(_0133_));
 sky130_fd_sc_hd__nor4_1 _1737_ (.A(_0854_),
    .B(tl_i[105]),
    .C(tl_i[106]),
    .D(_0852_),
    .Y(_0487_));
 sky130_fd_sc_hd__inv_1 _1738_ (.A(_0487_),
    .Y(_0488_));
 sky130_fd_sc_hd__nor4_1 _1739_ (.A(tl_i[62]),
    .B(_0849_),
    .C(_0488_),
    .D(_0247_),
    .Y(_0489_));
 sky130_fd_sc_hd__inv_1 _1740_ (.A(_0489_),
    .Y(_0490_));
 sky130_fd_sc_hd__nor4_1 _1741_ (.A(_0772_),
    .B(_0927_),
    .C(_0184_),
    .D(_0490_),
    .Y(_0491_));
 sky130_fd_sc_hd__nor3_1 _1742_ (.A(_0927_),
    .B(_0184_),
    .C(_0490_),
    .Y(_0492_));
 sky130_fd_sc_hd__nor2_1 _1743_ (.A(net67),
    .B(_0492_),
    .Y(_0493_));
 sky130_fd_sc_hd__nor3_1 _1744_ (.A(net40),
    .B(_0491_),
    .C(_0493_),
    .Y(_0134_));
 sky130_fd_sc_hd__a21oi_1 _1745_ (.A1(_0489_),
    .A2(net42),
    .B1(net68),
    .Y(_0494_));
 sky130_fd_sc_hd__nor3_1 _1746_ (.A(net40),
    .B(_0494_),
    .C(_0492_),
    .Y(_0135_));
 sky130_fd_sc_hd__nor2_1 _1747_ (.A(_0490_),
    .B(_0491_),
    .Y(_0495_));
 sky130_fd_sc_hd__a21oi_1 _1748_ (.A1(_0928_),
    .A2(net43),
    .B1(net40),
    .Y(_0496_));
 sky130_fd_sc_hd__nand3_1 _1749_ (.A(_0495_),
    .B(_0184_),
    .C(_0496_),
    .Y(_0497_));
 sky130_fd_sc_hd__o31ai_1 _1750_ (.A1(_0928_),
    .A2(net40),
    .A3(_0489_),
    .B1(_0497_),
    .Y(_0136_));
 sky130_fd_sc_hd__nor2_1 _1751_ (.A(net70),
    .B(_0495_),
    .Y(_0498_));
 sky130_fd_sc_hd__a211oi_1 _1752_ (.A1(net70),
    .A2(_0489_),
    .B1(net40),
    .C1(_0498_),
    .Y(_0137_));
 sky130_fd_sc_hd__xor2_1 _1753_ (.A(_0719_),
    .B(_0715_),
    .X(_0010_));
 sky130_fd_sc_hd__nor3_1 _1754_ (.A(_0709_),
    .B(net56),
    .C(_0721_),
    .Y(_0499_));
 sky130_fd_sc_hd__nor2_1 _1755_ (.A(_0499_),
    .B(_0723_),
    .Y(_0012_));
 sky130_fd_sc_hd__nor2_1 _1756_ (.A(_0712_),
    .B(net56),
    .Y(_0500_));
 sky130_fd_sc_hd__xnor2_1 _1757_ (.A(_0500_),
    .B(_0720_),
    .Y(_0011_));
 sky130_fd_sc_hd__inv_1 _1758_ (.A(u_uart_core_uart_tx_sreg_q_9_),
    .Y(_0501_));
 sky130_fd_sc_hd__nor2_1 _1759_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_15_),
    .B(net41),
    .Y(_0502_));
 sky130_fd_sc_hd__nor2_1 _1760_ (.A(net61),
    .B(_0502_),
    .Y(_0503_));
 sky130_fd_sc_hd__o21ai_0 _1761_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_7_),
    .B1(_0503_),
    .Y(_0504_));
 sky130_fd_sc_hd__nor2_1 _1762_ (.A(net62),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_23_),
    .Y(_0505_));
 sky130_fd_sc_hd__nor2_1 _1763_ (.A(_0679_),
    .B(_0505_),
    .Y(_0506_));
 sky130_fd_sc_hd__o21ai_0 _1764_ (.A1(net41),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_31_),
    .B1(_0506_),
    .Y(_0507_));
 sky130_fd_sc_hd__nor2_1 _1765_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_47_),
    .B(net41),
    .Y(_0508_));
 sky130_fd_sc_hd__nor2_1 _1766_ (.A(net61),
    .B(_0508_),
    .Y(_0509_));
 sky130_fd_sc_hd__o21ai_0 _1767_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_39_),
    .B1(_0509_),
    .Y(_0510_));
 sky130_fd_sc_hd__o21ai_0 _1768_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_55_),
    .B1(net61),
    .Y(_0511_));
 sky130_fd_sc_hd__nor2_1 _1769_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_63_),
    .B(net41),
    .Y(_0512_));
 sky130_fd_sc_hd__nor2_1 _1770_ (.A(_0511_),
    .B(_0512_),
    .Y(_0513_));
 sky130_fd_sc_hd__nor2_1 _1771_ (.A(_0682_),
    .B(_0513_),
    .Y(_0514_));
 sky130_fd_sc_hd__a32oi_1 _1772_ (.A1(_0504_),
    .A2(_0682_),
    .A3(_0507_),
    .B1(_0510_),
    .B2(_0514_),
    .Y(_0515_));
 sky130_fd_sc_hd__a22oi_1 _1773_ (.A1(_0404_),
    .A2(_0515_),
    .B1(_0410_),
    .B2(u_uart_core_uart_tx_sreg_q_8_),
    .Y(_0516_));
 sky130_fd_sc_hd__o311ai_0 _1774_ (.A1(_0501_),
    .A2(_0404_),
    .A3(_0406_),
    .B1(net92),
    .C1(_0516_),
    .Y(_0138_));
 sky130_fd_sc_hd__nand2_1 _1775_ (.A(_0416_),
    .B(u_uart_core_uart_tx_sreg_q_7_),
    .Y(_0517_));
 sky130_fd_sc_hd__a21oi_1 _1776_ (.A1(_0407_),
    .A2(u_uart_core_uart_tx_sreg_q_8_),
    .B1(net54),
    .Y(_0518_));
 sky130_fd_sc_hd__nor2_1 _1777_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_14_),
    .B(net41),
    .Y(_0519_));
 sky130_fd_sc_hd__nor2_1 _1778_ (.A(net61),
    .B(_0519_),
    .Y(_0520_));
 sky130_fd_sc_hd__o21ai_0 _1779_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_6_),
    .B1(_0520_),
    .Y(_0521_));
 sky130_fd_sc_hd__nor2_1 _1780_ (.A(net62),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_22_),
    .Y(_0522_));
 sky130_fd_sc_hd__nor2_1 _1781_ (.A(_0679_),
    .B(_0522_),
    .Y(_0523_));
 sky130_fd_sc_hd__o21ai_0 _1782_ (.A1(net41),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_30_),
    .B1(_0523_),
    .Y(_0524_));
 sky130_fd_sc_hd__nor2_1 _1783_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_46_),
    .B(net41),
    .Y(_0525_));
 sky130_fd_sc_hd__nor2_1 _1784_ (.A(net61),
    .B(_0525_),
    .Y(_0526_));
 sky130_fd_sc_hd__o21ai_0 _1785_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_38_),
    .B1(_0526_),
    .Y(_0527_));
 sky130_fd_sc_hd__o21ai_0 _1786_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_54_),
    .B1(net61),
    .Y(_0528_));
 sky130_fd_sc_hd__nor2_1 _1787_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_62_),
    .B(net41),
    .Y(_0529_));
 sky130_fd_sc_hd__nor2_1 _1788_ (.A(_0528_),
    .B(_0529_),
    .Y(_0530_));
 sky130_fd_sc_hd__nor2_1 _1789_ (.A(_0682_),
    .B(_0530_),
    .Y(_0531_));
 sky130_fd_sc_hd__a32oi_1 _1790_ (.A1(_0521_),
    .A2(_0682_),
    .A3(_0524_),
    .B1(_0527_),
    .B2(_0531_),
    .Y(_0532_));
 sky130_fd_sc_hd__nand2_1 _1791_ (.A(_0404_),
    .B(_0532_),
    .Y(_0533_));
 sky130_fd_sc_hd__o211ai_1 _1792_ (.A1(_0409_),
    .A2(_0517_),
    .B1(_0518_),
    .C1(_0533_),
    .Y(_0139_));
 sky130_fd_sc_hd__nor2_1 _1793_ (.A(net62),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_5_),
    .Y(_0534_));
 sky130_fd_sc_hd__nor2_1 _1794_ (.A(net61),
    .B(_0534_),
    .Y(_0535_));
 sky130_fd_sc_hd__o21ai_0 _1795_ (.A1(net41),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_13_),
    .B1(_0535_),
    .Y(_0536_));
 sky130_fd_sc_hd__nor2_1 _1796_ (.A(net62),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_21_),
    .Y(_0537_));
 sky130_fd_sc_hd__nor2_1 _1797_ (.A(_0679_),
    .B(_0537_),
    .Y(_0538_));
 sky130_fd_sc_hd__o21ai_0 _1798_ (.A1(net41),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_29_),
    .B1(_0538_),
    .Y(_0539_));
 sky130_fd_sc_hd__o21ai_0 _1799_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_53_),
    .B1(net61),
    .Y(_0540_));
 sky130_fd_sc_hd__nor2_1 _1800_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_61_),
    .B(net41),
    .Y(_0541_));
 sky130_fd_sc_hd__nor2_1 _1801_ (.A(_0540_),
    .B(_0541_),
    .Y(_0542_));
 sky130_fd_sc_hd__nor2_1 _1802_ (.A(_0682_),
    .B(_0542_),
    .Y(_0543_));
 sky130_fd_sc_hd__nor2_1 _1803_ (.A(net62),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_37_),
    .Y(_0544_));
 sky130_fd_sc_hd__nor2_1 _1804_ (.A(net61),
    .B(_0544_),
    .Y(_0545_));
 sky130_fd_sc_hd__o21ai_0 _1805_ (.A1(net41),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_45_),
    .B1(_0545_),
    .Y(_0546_));
 sky130_fd_sc_hd__a32oi_1 _1806_ (.A1(_0682_),
    .A2(_0536_),
    .A3(_0539_),
    .B1(_0543_),
    .B2(_0546_),
    .Y(_0547_));
 sky130_fd_sc_hd__nand2_1 _1807_ (.A(_0404_),
    .B(_0547_),
    .Y(_0548_));
 sky130_fd_sc_hd__nor2_1 _1808_ (.A(u_uart_core_uart_tx_sreg_q_6_),
    .B(_0413_),
    .Y(_0549_));
 sky130_fd_sc_hd__a31oi_1 _1809_ (.A1(_0411_),
    .A2(_0517_),
    .A3(_0548_),
    .B1(_0549_),
    .Y(_0140_));
 sky130_fd_sc_hd__nor2_1 _1810_ (.A(net62),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_4_),
    .Y(_0550_));
 sky130_fd_sc_hd__o21ai_0 _1811_ (.A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_12_),
    .A2(net41),
    .B1(_0679_),
    .Y(_0551_));
 sky130_fd_sc_hd__nor2_1 _1812_ (.A(net62),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_20_),
    .Y(_0552_));
 sky130_fd_sc_hd__o21ai_0 _1813_ (.A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_28_),
    .A2(net41),
    .B1(net61),
    .Y(_0553_));
 sky130_fd_sc_hd__o221ai_1 _1814_ (.A1(_0550_),
    .A2(_0551_),
    .B1(_0552_),
    .B2(_0553_),
    .C1(_0682_),
    .Y(_0554_));
 sky130_fd_sc_hd__nor2_1 _1815_ (.A(net62),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_36_),
    .Y(_0555_));
 sky130_fd_sc_hd__o21ai_0 _1816_ (.A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_44_),
    .A2(net41),
    .B1(_0679_),
    .Y(_0556_));
 sky130_fd_sc_hd__nor2_1 _1817_ (.A(net62),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_52_),
    .Y(_0557_));
 sky130_fd_sc_hd__o21ai_0 _1818_ (.A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_60_),
    .A2(net41),
    .B1(net61),
    .Y(_0558_));
 sky130_fd_sc_hd__o221ai_1 _1819_ (.A1(_0555_),
    .A2(_0556_),
    .B1(_0557_),
    .B2(_0558_),
    .C1(net60),
    .Y(_0559_));
 sky130_fd_sc_hd__nand3_1 _1820_ (.A(_0306_),
    .B(_0554_),
    .C(_0559_),
    .Y(_0560_));
 sky130_fd_sc_hd__nand2_1 _1821_ (.A(_0416_),
    .B(u_uart_core_uart_tx_sreg_q_5_),
    .Y(_0561_));
 sky130_fd_sc_hd__a21oi_1 _1822_ (.A1(_0407_),
    .A2(u_uart_core_uart_tx_sreg_q_6_),
    .B1(net54),
    .Y(_0562_));
 sky130_fd_sc_hd__o221ai_1 _1823_ (.A1(_0416_),
    .A2(_0560_),
    .B1(_0407_),
    .B2(_0561_),
    .C1(_0562_),
    .Y(_0141_));
 sky130_fd_sc_hd__o21ai_0 _1824_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_19_),
    .B1(net61),
    .Y(_0563_));
 sky130_fd_sc_hd__nor2_1 _1825_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_27_),
    .B(net41),
    .Y(_0564_));
 sky130_fd_sc_hd__o21ai_0 _1826_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_3_),
    .B1(_0679_),
    .Y(_0565_));
 sky130_fd_sc_hd__nor2_1 _1827_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_11_),
    .B(net41),
    .Y(_0566_));
 sky130_fd_sc_hd__o221ai_1 _1828_ (.A1(_0563_),
    .A2(_0564_),
    .B1(_0565_),
    .B2(_0566_),
    .C1(_0682_),
    .Y(_0567_));
 sky130_fd_sc_hd__o21ai_0 _1829_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_51_),
    .B1(net61),
    .Y(_0568_));
 sky130_fd_sc_hd__nor2_1 _1830_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_59_),
    .B(net41),
    .Y(_0569_));
 sky130_fd_sc_hd__o21ai_0 _1831_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_35_),
    .B1(_0679_),
    .Y(_0570_));
 sky130_fd_sc_hd__nor2_1 _1832_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_43_),
    .B(net41),
    .Y(_0571_));
 sky130_fd_sc_hd__o221ai_1 _1833_ (.A1(_0568_),
    .A2(_0569_),
    .B1(_0570_),
    .B2(_0571_),
    .C1(net60),
    .Y(_0572_));
 sky130_fd_sc_hd__nand4_1 _1834_ (.A(_0404_),
    .B(_0306_),
    .C(_0567_),
    .D(_0572_),
    .Y(_0573_));
 sky130_fd_sc_hd__nor2_1 _1835_ (.A(u_uart_core_uart_tx_sreg_q_4_),
    .B(_0413_),
    .Y(_0574_));
 sky130_fd_sc_hd__a31oi_1 _1836_ (.A1(_0411_),
    .A2(_0561_),
    .A3(_0573_),
    .B1(_0574_),
    .Y(_0142_));
 sky130_fd_sc_hd__nand2_1 _1837_ (.A(_0416_),
    .B(u_uart_core_uart_tx_sreg_q_3_),
    .Y(_0575_));
 sky130_fd_sc_hd__nor2_1 _1838_ (.A(net62),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_2_),
    .Y(_0576_));
 sky130_fd_sc_hd__nor2_1 _1839_ (.A(net61),
    .B(_0576_),
    .Y(_0577_));
 sky130_fd_sc_hd__o21ai_0 _1840_ (.A1(net41),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_10_),
    .B1(_0577_),
    .Y(_0578_));
 sky130_fd_sc_hd__nor2_1 _1841_ (.A(net62),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_18_),
    .Y(_0579_));
 sky130_fd_sc_hd__nor2_1 _1842_ (.A(_0679_),
    .B(_0579_),
    .Y(_0580_));
 sky130_fd_sc_hd__o21ai_0 _1843_ (.A1(net41),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_26_),
    .B1(_0580_),
    .Y(_0581_));
 sky130_fd_sc_hd__o21ai_0 _1844_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_50_),
    .B1(net61),
    .Y(_0582_));
 sky130_fd_sc_hd__nor2_1 _1845_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_58_),
    .B(net41),
    .Y(_0583_));
 sky130_fd_sc_hd__nor2_1 _1846_ (.A(_0582_),
    .B(_0583_),
    .Y(_0584_));
 sky130_fd_sc_hd__nor2_1 _1847_ (.A(_0682_),
    .B(_0584_),
    .Y(_0585_));
 sky130_fd_sc_hd__nor2_1 _1848_ (.A(net62),
    .B(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_34_),
    .Y(_0586_));
 sky130_fd_sc_hd__nor2_1 _1849_ (.A(net61),
    .B(_0586_),
    .Y(_0587_));
 sky130_fd_sc_hd__o21ai_0 _1850_ (.A1(net41),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_42_),
    .B1(_0587_),
    .Y(_0588_));
 sky130_fd_sc_hd__a32oi_1 _1851_ (.A1(_0682_),
    .A2(_0578_),
    .A3(_0581_),
    .B1(_0585_),
    .B2(_0588_),
    .Y(_0589_));
 sky130_fd_sc_hd__a221oi_1 _1852_ (.A1(u_uart_core_uart_tx_sreg_q_4_),
    .A2(_0407_),
    .B1(_0404_),
    .B2(_0589_),
    .C1(net54),
    .Y(_0590_));
 sky130_fd_sc_hd__o21ai_0 _1853_ (.A1(_0409_),
    .A2(_0575_),
    .B1(_0590_),
    .Y(_0143_));
 sky130_fd_sc_hd__o21ai_0 _1854_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_49_),
    .B1(net61),
    .Y(_0591_));
 sky130_fd_sc_hd__nor2_1 _1855_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_57_),
    .B(net41),
    .Y(_0592_));
 sky130_fd_sc_hd__o21ai_0 _1856_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_33_),
    .B1(_0679_),
    .Y(_0593_));
 sky130_fd_sc_hd__nor2_1 _1857_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_41_),
    .B(net41),
    .Y(_0594_));
 sky130_fd_sc_hd__o221ai_1 _1858_ (.A1(_0591_),
    .A2(_0592_),
    .B1(_0593_),
    .B2(_0594_),
    .C1(net60),
    .Y(_0595_));
 sky130_fd_sc_hd__nor2_1 _1859_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_9_),
    .B(net41),
    .Y(_0596_));
 sky130_fd_sc_hd__nor2_1 _1860_ (.A(net61),
    .B(_0596_),
    .Y(_0597_));
 sky130_fd_sc_hd__o21ai_0 _1861_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_1_),
    .B1(_0597_),
    .Y(_0598_));
 sky130_fd_sc_hd__nor2_1 _1862_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_25_),
    .B(net41),
    .Y(_0599_));
 sky130_fd_sc_hd__nor2_1 _1863_ (.A(_0679_),
    .B(_0599_),
    .Y(_0600_));
 sky130_fd_sc_hd__o21ai_0 _1864_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_17_),
    .B1(_0600_),
    .Y(_0601_));
 sky130_fd_sc_hd__nand3_1 _1865_ (.A(_0598_),
    .B(_0601_),
    .C(_0682_),
    .Y(_0602_));
 sky130_fd_sc_hd__nand3_1 _1866_ (.A(_0404_),
    .B(_0595_),
    .C(_0602_),
    .Y(_0603_));
 sky130_fd_sc_hd__nor2_1 _1867_ (.A(u_uart_core_uart_tx_sreg_q_2_),
    .B(_0413_),
    .Y(_0604_));
 sky130_fd_sc_hd__a31oi_1 _1868_ (.A1(_0411_),
    .A2(_0575_),
    .A3(_0603_),
    .B1(_0604_),
    .Y(_0144_));
 sky130_fd_sc_hd__o21ai_0 _1869_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_48_),
    .B1(net61),
    .Y(_0605_));
 sky130_fd_sc_hd__nor2_1 _1870_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_56_),
    .B(net41),
    .Y(_0606_));
 sky130_fd_sc_hd__o21ai_0 _1871_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_32_),
    .B1(_0679_),
    .Y(_0607_));
 sky130_fd_sc_hd__nor2_1 _1872_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_40_),
    .B(net41),
    .Y(_0608_));
 sky130_fd_sc_hd__o221ai_1 _1873_ (.A1(_0605_),
    .A2(_0606_),
    .B1(_0607_),
    .B2(_0608_),
    .C1(net60),
    .Y(_0609_));
 sky130_fd_sc_hd__nor2_1 _1874_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_8_),
    .B(net41),
    .Y(_0610_));
 sky130_fd_sc_hd__nor2_1 _1875_ (.A(net61),
    .B(_0610_),
    .Y(_0611_));
 sky130_fd_sc_hd__o21ai_0 _1876_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_0_),
    .B1(_0611_),
    .Y(_0612_));
 sky130_fd_sc_hd__nor2_1 _1877_ (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_24_),
    .B(_0686_),
    .Y(_0613_));
 sky130_fd_sc_hd__nor2_1 _1878_ (.A(_0679_),
    .B(_0613_),
    .Y(_0614_));
 sky130_fd_sc_hd__o21ai_0 _1879_ (.A1(net62),
    .A2(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_16_),
    .B1(_0614_),
    .Y(_0615_));
 sky130_fd_sc_hd__nand3_1 _1880_ (.A(_0612_),
    .B(_0615_),
    .C(_0682_),
    .Y(_0616_));
 sky130_fd_sc_hd__nand2_1 _1881_ (.A(_0609_),
    .B(_0616_),
    .Y(_0617_));
 sky130_fd_sc_hd__nand2_1 _1882_ (.A(_0416_),
    .B(u_uart_core_uart_tx_sreg_q_1_),
    .Y(_0618_));
 sky130_fd_sc_hd__a21oi_1 _1883_ (.A1(_0407_),
    .A2(u_uart_core_uart_tx_sreg_q_2_),
    .B1(net54),
    .Y(_0619_));
 sky130_fd_sc_hd__o221ai_1 _1884_ (.A1(_0416_),
    .A2(_0617_),
    .B1(_0409_),
    .B2(_0618_),
    .C1(_0619_),
    .Y(_0145_));
 sky130_fd_sc_hd__nor2_1 _1885_ (.A(u_uart_core_uart_tx_sreg_q_0_),
    .B(net54),
    .Y(_0620_));
 sky130_fd_sc_hd__o22ai_1 _1886_ (.A1(_0406_),
    .A2(_0618_),
    .B1(_0620_),
    .B2(_0411_),
    .Y(_0146_));
 sky130_fd_sc_hd__a21oi_1 _1887_ (.A1(_0515_),
    .A2(_0532_),
    .B1(_0305_),
    .Y(_0621_));
 sky130_fd_sc_hd__o21ai_0 _1888_ (.A1(_0515_),
    .A2(_0532_),
    .B1(_0621_),
    .Y(_0622_));
 sky130_fd_sc_hd__nand3_1 _1889_ (.A(_0560_),
    .B(_0306_),
    .C(_0547_),
    .Y(_0623_));
 sky130_fd_sc_hd__o21ai_0 _1890_ (.A1(_0547_),
    .A2(_0560_),
    .B1(_0623_),
    .Y(_0624_));
 sky130_fd_sc_hd__xor2_1 _1891_ (.A(_0622_),
    .B(_0624_),
    .X(_0625_));
 sky130_fd_sc_hd__nand3_1 _1892_ (.A(_0306_),
    .B(_0567_),
    .C(_0572_),
    .Y(_0626_));
 sky130_fd_sc_hd__nand3_1 _1893_ (.A(_0626_),
    .B(_0306_),
    .C(_0589_),
    .Y(_0627_));
 sky130_fd_sc_hd__o21ai_0 _1894_ (.A1(_0626_),
    .A2(_0589_),
    .B1(_0627_),
    .Y(_0628_));
 sky130_fd_sc_hd__nand2_1 _1895_ (.A(_0595_),
    .B(_0602_),
    .Y(_0629_));
 sky130_fd_sc_hd__a21oi_1 _1896_ (.A1(_0629_),
    .A2(_0617_),
    .B1(_0305_),
    .Y(_0630_));
 sky130_fd_sc_hd__o21ai_0 _1897_ (.A1(_0629_),
    .A2(_0617_),
    .B1(_0630_),
    .Y(_0631_));
 sky130_fd_sc_hd__xnor2_1 _1898_ (.A(net94),
    .B(_0631_),
    .Y(_0632_));
 sky130_fd_sc_hd__xor2_1 _1899_ (.A(_0628_),
    .B(_0632_),
    .X(_0633_));
 sky130_fd_sc_hd__xor2_1 _1900_ (.A(_0625_),
    .B(_0633_),
    .X(_0634_));
 sky130_fd_sc_hd__a22oi_1 _1901_ (.A1(_0501_),
    .A2(_0410_),
    .B1(_0634_),
    .B2(_0419_),
    .Y(_0147_));
 sky130_fd_sc_hd__nand2_1 _1902_ (.A(_0852_),
    .B(u_uart_reg_tl_o_62_),
    .Y(_0635_));
 sky130_fd_sc_hd__nand2_1 _1903_ (.A(_0488_),
    .B(_0635_),
    .Y(_0148_));
 sky130_fd_sc_hd__nand2_1 _1904_ (.A(net95),
    .B(net101),
    .Y(_0636_));
 sky130_fd_sc_hd__o21ai_2 _1905_ (.A1(net95),
    .A2(_0441_),
    .B1(_0636_),
    .Y(u_uart_core_rx_fifo_data_7_));
 sky130_fd_sc_hd__o21ai_0 _1906_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .A2(_0491_),
    .B1(_0481_),
    .Y(_0637_));
 sky130_fd_sc_hd__a21oi_1 _1907_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .A2(_0491_),
    .B1(_0637_),
    .Y(_0149_));
 sky130_fd_sc_hd__o21ai_0 _1908_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .A2(_0035_),
    .B1(_0481_),
    .Y(_0638_));
 sky130_fd_sc_hd__a21oi_1 _1909_ (.A1(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .A2(_0035_),
    .B1(_0638_),
    .Y(_0150_));
 sky130_fd_sc_hd__o22ai_1 _1910_ (.A1(_0467_),
    .A2(_0468_),
    .B1(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .B2(_0475_),
    .Y(_0639_));
 sky130_fd_sc_hd__a21oi_1 _1911_ (.A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .A2(_0475_),
    .B1(_0639_),
    .Y(_0151_));
 sky130_fd_sc_hd__o22ai_1 _1912_ (.A1(_0467_),
    .A2(_0468_),
    .B1(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .B2(_0018_),
    .Y(_0640_));
 sky130_fd_sc_hd__a21oi_1 _1913_ (.A1(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .A2(_0018_),
    .B1(_0640_),
    .Y(_0152_));
 sky130_fd_sc_hd__inv_1 _1914_ (.A(u_uart_core_uart_rx_baud_div_q_3_),
    .Y(_0641_));
 sky130_fd_sc_hd__nand3_1 _1915_ (.A(_0462_),
    .B(u_uart_core_uart_rx_baud_div_q_3_),
    .C(u_uart_core_uart_rx_baud_div_q_2_),
    .Y(_0642_));
 sky130_fd_sc_hd__nor2_1 _1916_ (.A(_0642_),
    .B(_0444_),
    .Y(u_uart_core_uart_rx_tick_baud_d));
 sky130_fd_sc_hd__a21oi_1 _1917_ (.A1(_0463_),
    .A2(_0641_),
    .B1(u_uart_core_uart_rx_tick_baud_d),
    .Y(_0153_));
 sky130_fd_sc_hd__nor2_1 _1918_ (.A(_0438_),
    .B(_0437_),
    .Y(_0643_));
 sky130_fd_sc_hd__inv_1 _1919_ (.A(_0643_),
    .Y(_0644_));
 sky130_fd_sc_hd__o22ai_1 _1920_ (.A1(net108),
    .A2(_0644_),
    .B1(u_uart_core_uart_rx_bit_cnt_q_3_),
    .B2(_0449_),
    .Y(_0645_));
 sky130_fd_sc_hd__nor2_1 _1921_ (.A(_0434_),
    .B(_0450_),
    .Y(_0646_));
 sky130_fd_sc_hd__o21ai_0 _1922_ (.A1(_0645_),
    .A2(_0646_),
    .B1(_0457_),
    .Y(_0154_));
 sky130_fd_sc_hd__nand2_1 _1923_ (.A(_0454_),
    .B(u_uart_core_rx_tick_baud),
    .Y(_0647_));
 sky130_fd_sc_hd__nor3_1 _1924_ (.A(u_uart_core_uart_rx_bit_cnt_q_2_),
    .B(u_uart_core_uart_rx_bit_cnt_q_3_),
    .C(_0647_),
    .Y(_0000_));
 sky130_fd_sc_hd__nor2_1 _1925_ (.A(net108),
    .B(_0000_),
    .Y(_0648_));
 sky130_fd_sc_hd__a21oi_1 _1926_ (.A1(_0644_),
    .A2(_0648_),
    .B1(_0444_),
    .Y(_0155_));
 sky130_fd_sc_hd__nor2_1 _1927_ (.A(_0432_),
    .B(_0445_),
    .Y(_0649_));
 sky130_fd_sc_hd__a21oi_1 _1928_ (.A1(_0448_),
    .A2(_0765_),
    .B1(_0649_),
    .Y(_0156_));
 sky130_fd_sc_hd__a21oi_1 _1929_ (.A1(_0423_),
    .A2(u_uart_core_uart_tx_baud_div_q_2_),
    .B1(u_uart_core_uart_tx_baud_div_q_3_),
    .Y(_0650_));
 sky130_fd_sc_hd__and3_1 _1930_ (.A(_0423_),
    .B(u_uart_core_uart_tx_baud_div_q_3_),
    .C(u_uart_core_uart_tx_baud_div_q_2_),
    .X(_0981_));
 sky130_fd_sc_hd__nor2_1 _1931_ (.A(_0650_),
    .B(_0981_),
    .Y(_0157_));
 sky130_fd_sc_hd__inv_1 _1932_ (.A(u_uart_core_uart_tx_bit_cnt_q_3_),
    .Y(_0651_));
 sky130_fd_sc_hd__a21oi_1 _1933_ (.A1(net92),
    .A2(_0312_),
    .B1(_0410_),
    .Y(_0652_));
 sky130_fd_sc_hd__o21ai_0 _1934_ (.A1(_0651_),
    .A2(_0652_),
    .B1(_0418_),
    .Y(_0158_));
 sky130_fd_sc_hd__inv_1 _1935_ (.A(u_uart_core_tx_out),
    .Y(_0653_));
 sky130_fd_sc_hd__a22oi_1 _1936_ (.A1(_0407_),
    .A2(_0620_),
    .B1(_0408_),
    .B2(_0653_),
    .Y(_0159_));
 sky130_fd_sc_hd__nand2_1 _1937_ (.A(_0867_),
    .B(_0856_),
    .Y(_0654_));
 sky130_fd_sc_hd__o21ai_0 _1938_ (.A1(_0487_),
    .A2(_0856_),
    .B1(_0903_),
    .Y(_0655_));
 sky130_fd_sc_hd__a21oi_1 _1939_ (.A1(_0904_),
    .A2(_0851_),
    .B1(_0852_),
    .Y(_0656_));
 sky130_fd_sc_hd__nor2_1 _1940_ (.A(u_uart_reg_tl_o_1_),
    .B(_0884_),
    .Y(_0657_));
 sky130_fd_sc_hd__a31oi_1 _1941_ (.A1(_0654_),
    .A2(_0655_),
    .A3(_0656_),
    .B1(_0657_),
    .Y(_0160_));
 sky130_fd_sc_hd__o21ai_0 _1942_ (.A1(u_uart_reg_tl_o_0_),
    .A2(tl_i[0]),
    .B1(_0852_),
    .Y(_0161_));
 sky130_fd_sc_hd__nand2_1 _1943_ (.A(_0861_),
    .B(reg2hw_56_),
    .Y(_0658_));
 sky130_fd_sc_hd__nor2_1 _1944_ (.A(u_uart_reg_tl_o_47_),
    .B(_0884_),
    .Y(_0659_));
 sky130_fd_sc_hd__a21oi_1 _1945_ (.A1(net32),
    .A2(_0658_),
    .B1(_0659_),
    .Y(_0162_));
 sky130_fd_sc_hd__nand2_1 _1946_ (.A(net36),
    .B(tl_i[99]),
    .Y(_0660_));
 sky130_fd_sc_hd__nand2_1 _1947_ (.A(_0852_),
    .B(u_uart_reg_tl_o_56_),
    .Y(_0661_));
 sky130_fd_sc_hd__nand2_1 _1948_ (.A(_0660_),
    .B(_0661_),
    .Y(_0163_));
 sky130_fd_sc_hd__nand2_1 _1949_ (.A(net36),
    .B(tl_i[101]),
    .Y(_0662_));
 sky130_fd_sc_hd__nand2_1 _1950_ (.A(_0852_),
    .B(u_uart_reg_tl_o_58_),
    .Y(_0663_));
 sky130_fd_sc_hd__nand2_1 _1951_ (.A(_0662_),
    .B(_0663_),
    .Y(_0164_));
 sky130_fd_sc_hd__nand2_1 _1952_ (.A(net33),
    .B(net100),
    .Y(_0664_));
 sky130_fd_sc_hd__o21ai_0 _1953_ (.A1(_0871_),
    .A2(net33),
    .B1(_0664_),
    .Y(_0165_));
 sky130_fd_sc_hd__mux2_1 _1954_ (.A0(tl_i[55]),
    .A1(reg2hw_56_),
    .S(net33),
    .X(_0166_));
 sky130_fd_sc_hd__nand2_1 _1955_ (.A(net33),
    .B(reg2hw_36_),
    .Y(_0665_));
 sky130_fd_sc_hd__o21ai_0 _1956_ (.A1(_0875_),
    .A2(net33),
    .B1(_0665_),
    .Y(_0167_));
 sky130_fd_sc_hd__nand2_1 _1957_ (.A(net33),
    .B(net95),
    .Y(_0666_));
 sky130_fd_sc_hd__o21ai_0 _1958_ (.A1(_0869_),
    .A2(net33),
    .B1(_0666_),
    .Y(_0168_));
 sky130_fd_sc_hd__mux2_1 _1959_ (.A0(tl_i[31]),
    .A1(net94),
    .S(net33),
    .X(_0169_));
 sky130_fd_sc_hd__nand2_1 _1960_ (.A(net33),
    .B(reg2hw_35_),
    .Y(_0667_));
 sky130_fd_sc_hd__o21ai_0 _1961_ (.A1(_0877_),
    .A2(net33),
    .B1(_0667_),
    .Y(_0170_));
 sky130_fd_sc_hd__nand2_1 _1962_ (.A(net33),
    .B(net93),
    .Y(_0668_));
 sky130_fd_sc_hd__o21ai_0 _1963_ (.A1(_0873_),
    .A2(net33),
    .B1(_0668_),
    .Y(_0171_));
 sky130_fd_sc_hd__nand2_1 _1964_ (.A(net33),
    .B(net92),
    .Y(_0669_));
 sky130_fd_sc_hd__o21ai_0 _1965_ (.A1(_0879_),
    .A2(net33),
    .B1(_0669_),
    .Y(_0172_));
 sky130_fd_sc_hd__nand3_1 _1966_ (.A(_0856_),
    .B(tl_i[64]),
    .C(_0858_),
    .Y(_0670_));
 sky130_fd_sc_hd__nor2_2 _1967_ (.A(_0867_),
    .B(_0670_),
    .Y(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_));
 sky130_fd_sc_hd__nor2_1 _1968_ (.A(reg2hw_1_),
    .B(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .Y(_0671_));
 sky130_fd_sc_hd__a21oi_1 _1969_ (.A1(_0879_),
    .A2(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .B1(_0671_),
    .Y(_0173_));
 sky130_fd_sc_hd__nand2_1 _1970_ (.A(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .B(tl_i[25]),
    .Y(_0672_));
 sky130_fd_sc_hd__o21ai_0 _1971_ (.A1(_0468_),
    .A2(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .B1(_0672_),
    .Y(_0174_));
 sky130_fd_sc_hd__mux2_1 _1972_ (.A0(net84),
    .A1(tl_i[31]),
    .S(net31),
    .X(_0175_));
 sky130_fd_sc_hd__nand2_1 _1973_ (.A(_0424_),
    .B(_0653_),
    .Y(_0980_));
 sky130_fd_sc_hd__mux2_4 _1974_ (.A0(u_uart_core_tx_out_q),
    .A1(rx_i),
    .S(net100),
    .X(tx_o));
 sky130_fd_sc_hd__xor2_1 _1975_ (.A(_0746_),
    .B(_0741_),
    .X(_0003_));
 sky130_fd_sc_hd__xor2_1 _1976_ (.A(_0732_),
    .B(_0728_),
    .X(_0014_));
 sky130_fd_sc_hd__nor2_1 _1977_ (.A(net57),
    .B(_0817_),
    .Y(_0673_));
 sky130_fd_sc_hd__xnor2_1 _1978_ (.A(_0703_),
    .B(_0673_),
    .Y(_0017_));
 sky130_fd_sc_hd__dfrtp_1 _1979_ (.D(_0125_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1980_ (.D(_0124_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1981_ (.D(_0152_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_3_),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1982_ (.D(_0123_),
    .Q(u_uart_core_uart_rx_baud_div_q_0_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1983_ (.D(_0122_),
    .Q(u_uart_core_uart_rx_baud_div_q_1_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1984_ (.D(_0121_),
    .Q(u_uart_core_uart_rx_baud_div_q_2_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1985_ (.D(_0153_),
    .Q(u_uart_core_uart_rx_baud_div_q_3_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1986_ (.D(_0120_),
    .Q(u_uart_core_uart_rx_bit_cnt_q_0_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1987_ (.D(_0119_),
    .Q(u_uart_core_uart_rx_bit_cnt_q_1_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1988_ (.D(_0118_),
    .Q(u_uart_core_uart_rx_bit_cnt_q_2_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1989_ (.D(_0154_),
    .Q(u_uart_core_uart_rx_bit_cnt_q_3_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _1990_ (.D(_0155_),
    .Q(hw2reg_28_),
    .SET_B(net79),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1991_ (.D(_0117_),
    .Q(u_uart_core_uart_rx_sreg_q_1_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1992_ (.D(_0116_),
    .Q(u_uart_core_uart_rx_sreg_q_2_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1993_ (.D(_0115_),
    .Q(u_uart_core_uart_rx_sreg_q_3_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1994_ (.D(_0114_),
    .Q(u_uart_core_uart_rx_sreg_q_4_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1995_ (.D(_0113_),
    .Q(u_uart_core_uart_rx_sreg_q_5_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1996_ (.D(_0112_),
    .Q(u_uart_core_uart_rx_sreg_q_6_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1997_ (.D(_0111_),
    .Q(u_uart_core_uart_rx_sreg_q_7_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1998_ (.D(_0110_),
    .Q(u_uart_core_uart_rx_sreg_q_8_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _1999_ (.D(_0109_),
    .Q(u_uart_core_uart_rx_sreg_q_9_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2000_ (.D(_0156_),
    .Q(u_uart_core_uart_rx_sreg_q_10_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2001_ (.D(_0108_),
    .Q(u_uart_core_uart_tx_baud_div_q_0_),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2002_ (.D(_0107_),
    .Q(u_uart_core_uart_tx_baud_div_q_1_),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2003_ (.D(_0106_),
    .Q(u_uart_core_uart_tx_baud_div_q_2_),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2004_ (.D(_0157_),
    .Q(u_uart_core_uart_tx_baud_div_q_3_),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2005_ (.D(_0105_),
    .Q(u_uart_core_uart_tx_bit_cnt_q_0_),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2006_ (.D(_0104_),
    .Q(u_uart_core_uart_tx_bit_cnt_q_1_),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2007_ (.D(_0103_),
    .Q(u_uart_core_uart_tx_bit_cnt_q_2_),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2008_ (.D(_0158_),
    .Q(u_uart_core_uart_tx_bit_cnt_q_3_),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2009_ (.D(_0159_),
    .Q(u_uart_core_tx_out),
    .SET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2010_ (.D(_0160_),
    .Q(u_uart_reg_tl_o_1_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2011_ (.D(_0161_),
    .Q(u_uart_reg_tl_o_65_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2012_ (.D(_0102_),
    .Q(u_uart_reg_tl_o_16_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2013_ (.D(_0101_),
    .Q(u_uart_reg_tl_o_17_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2014_ (.D(_0100_),
    .Q(u_uart_reg_tl_o_18_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2015_ (.D(_0099_),
    .Q(u_uart_reg_tl_o_19_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2016_ (.D(_0098_),
    .Q(u_uart_reg_tl_o_20_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2017_ (.D(_0097_),
    .Q(u_uart_reg_tl_o_21_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2018_ (.D(_0096_),
    .Q(u_uart_reg_tl_o_22_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2019_ (.D(_0095_),
    .Q(u_uart_reg_tl_o_23_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2020_ (.D(_0094_),
    .Q(u_uart_reg_tl_o_24_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2021_ (.D(_0093_),
    .Q(u_uart_reg_tl_o_25_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2022_ (.D(_0092_),
    .Q(u_uart_reg_tl_o_26_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2023_ (.D(_0091_),
    .Q(u_uart_reg_tl_o_27_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2024_ (.D(_0090_),
    .Q(u_uart_reg_tl_o_28_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2025_ (.D(_0089_),
    .Q(u_uart_reg_tl_o_29_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2026_ (.D(_0088_),
    .Q(u_uart_reg_tl_o_30_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2027_ (.D(_0087_),
    .Q(u_uart_reg_tl_o_31_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2028_ (.D(_0086_),
    .Q(u_uart_reg_tl_o_32_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2029_ (.D(_0085_),
    .Q(u_uart_reg_tl_o_33_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2030_ (.D(_0084_),
    .Q(u_uart_reg_tl_o_34_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2031_ (.D(_0083_),
    .Q(u_uart_reg_tl_o_35_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2032_ (.D(_0082_),
    .Q(u_uart_reg_tl_o_36_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2033_ (.D(_0081_),
    .Q(u_uart_reg_tl_o_37_),
    .RESET_B(net72),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2034_ (.D(_0080_),
    .Q(u_uart_reg_tl_o_38_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2035_ (.D(_0079_),
    .Q(u_uart_reg_tl_o_39_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2036_ (.D(_0078_),
    .Q(u_uart_reg_tl_o_40_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2037_ (.D(_0077_),
    .Q(u_uart_reg_tl_o_41_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2038_ (.D(_0076_),
    .Q(u_uart_reg_tl_o_42_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2039_ (.D(_0075_),
    .Q(u_uart_reg_tl_o_43_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2040_ (.D(_0074_),
    .Q(u_uart_reg_tl_o_44_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2041_ (.D(_0073_),
    .Q(u_uart_reg_tl_o_45_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2042_ (.D(_0072_),
    .Q(u_uart_reg_tl_o_46_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2043_ (.D(_0162_),
    .Q(u_uart_reg_tl_o_47_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2044_ (.D(_0071_),
    .Q(u_uart_reg_tl_o_49_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2045_ (.D(_0070_),
    .Q(u_uart_reg_tl_o_50_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2046_ (.D(_0069_),
    .Q(u_uart_reg_tl_o_51_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2047_ (.D(_0068_),
    .Q(u_uart_reg_tl_o_52_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2048_ (.D(_0067_),
    .Q(u_uart_reg_tl_o_53_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2049_ (.D(_0066_),
    .Q(u_uart_reg_tl_o_54_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2050_ (.D(_0065_),
    .Q(u_uart_reg_tl_o_55_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2051_ (.D(_0163_),
    .Q(u_uart_reg_tl_o_56_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2052_ (.D(_0064_),
    .Q(u_uart_reg_tl_o_57_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2053_ (.D(_0164_),
    .Q(u_uart_reg_tl_o_58_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2054_ (.D(_0165_),
    .Q(reg2hw_38_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2055_ (.D(_0063_),
    .Q(reg2hw_41_),
    .SET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2056_ (.D(_0062_),
    .Q(reg2hw_42_),
    .SET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2057_ (.D(_0061_),
    .Q(reg2hw_43_),
    .SET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2058_ (.D(_0060_),
    .Q(reg2hw_44_),
    .SET_B(net75),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2059_ (.D(_0059_),
    .Q(reg2hw_45_),
    .SET_B(net75),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2060_ (.D(_0058_),
    .Q(reg2hw_46_),
    .SET_B(net75),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2061_ (.D(_0057_),
    .Q(reg2hw_47_),
    .SET_B(net75),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2062_ (.D(_0056_),
    .Q(reg2hw_48_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2063_ (.D(_0055_),
    .Q(reg2hw_49_),
    .SET_B(net75),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2064_ (.D(_0054_),
    .Q(reg2hw_50_),
    .SET_B(net75),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2065_ (.D(_0053_),
    .Q(reg2hw_51_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2066_ (.D(_0052_),
    .Q(reg2hw_52_),
    .SET_B(net75),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2067_ (.D(_0051_),
    .Q(reg2hw_53_),
    .RESET_B(net73),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2068_ (.D(_0050_),
    .Q(reg2hw_54_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2069_ (.D(_0049_),
    .Q(reg2hw_55_),
    .SET_B(net75),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2070_ (.D(_0166_),
    .Q(reg2hw_56_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2071_ (.D(_0167_),
    .Q(reg2hw_36_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2072_ (.D(_0168_),
    .Q(reg2hw_39_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2073_ (.D(_0169_),
    .Q(reg2hw_40_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2074_ (.D(_0170_),
    .Q(reg2hw_35_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2075_ (.D(_0171_),
    .Q(reg2hw_37_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2076_ (.D(_0172_),
    .Q(reg2hw_34_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2077_ (.D(_0173_),
    .Q(reg2hw_1_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2078_ (.D(_0174_),
    .Q(reg2hw_3_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2079_ (.D(_0048_),
    .Q(reg2hw_5_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2080_ (.D(_0047_),
    .Q(reg2hw_6_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2081_ (.D(_0046_),
    .Q(reg2hw_7_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2082_ (.D(_0045_),
    .Q(reg2hw_8_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2083_ (.D(_0044_),
    .Q(reg2hw_9_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2084_ (.D(_0043_),
    .Q(reg2hw_10_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2085_ (.D(_0042_),
    .Q(reg2hw_11_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2086_ (.D(_0175_),
    .Q(reg2hw_12_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2087_ (.D(net31),
    .Q(reg2hw_4_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2088_ (.D(u_uart_reg_u_reg_core_fifo_ctrl_flds_we_0_),
    .Q(reg2hw_0_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2089_ (.D(_0981_),
    .Q(u_uart_core_uart_tx_tick_baud_q),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2090_ (.D(u_uart_core_uart_rx_tick_baud_d),
    .Q(u_uart_core_rx_tick_baud),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2091_ (.D(_0000_),
    .Q(u_uart_core_rx_valid),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2092_ (.D(net),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_under_rst),
    .SET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _2092__1 (.LO(net));
 sky130_fd_sc_hd__dfstp_1 _2093_ (.D(net1),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_under_rst),
    .SET_B(net79),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _2093__2 (.LO(net1));
 sky130_fd_sc_hd__dfrtp_1 _2094_ (.D(net22),
    .Q(u_uart_core_tx_rst_ni),
    .RESET_B(net71),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _2094__23 (.HI(net22));
 sky130_fd_sc_hd__dfrtp_1 _2095_ (.D(net23),
    .Q(u_uart_core_timing_rst_ni),
    .RESET_B(net71),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _2095__24 (.HI(net23));
 sky130_fd_sc_hd__dfrtp_1 _2096_ (.D(net24),
    .Q(u_uart_core_rx_rst_ni),
    .RESET_B(net71),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _2096__25 (.HI(net24));
 sky130_fd_sc_hd__dfstp_1 _2097_ (.D(_0980_),
    .Q(u_uart_core_tx_out_q),
    .SET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2098_ (.D(u_uart_core_sync_rx_intq),
    .Q(u_uart_core_rx_sync),
    .SET_B(net79),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2099_ (.D(rx_i),
    .Q(u_uart_core_sync_rx_intq),
    .SET_B(net79),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2100_ (.D(u_uart_core_rx_sync_q1),
    .Q(u_uart_core_rx_sync_q2),
    .SET_B(net79),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2101_ (.D(u_uart_core_rx_sync),
    .Q(u_uart_core_rx_sync_q1),
    .SET_B(net79),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2102_ (.D(_0002_),
    .Q(u_uart_core_nco_sum_q_0_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2103_ (.D(_0009_),
    .Q(u_uart_core_nco_sum_q_1_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2104_ (.D(_0010_),
    .Q(u_uart_core_nco_sum_q_2_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2105_ (.D(_0011_),
    .Q(u_uart_core_nco_sum_q_3_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2106_ (.D(_0012_),
    .Q(u_uart_core_nco_sum_q_4_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2107_ (.D(_0013_),
    .Q(u_uart_core_nco_sum_q_5_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2108_ (.D(_0014_),
    .Q(u_uart_core_nco_sum_q_6_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2109_ (.D(_0015_),
    .Q(u_uart_core_nco_sum_q_7_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2110_ (.D(_0016_),
    .Q(u_uart_core_nco_sum_q_8_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2111_ (.D(_0017_),
    .Q(u_uart_core_nco_sum_q_9_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2112_ (.D(_0003_),
    .Q(u_uart_core_nco_sum_q_10_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2113_ (.D(_0004_),
    .Q(u_uart_core_nco_sum_q_11_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2114_ (.D(_0005_),
    .Q(u_uart_core_nco_sum_q_12_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2115_ (.D(_0006_),
    .Q(u_uart_core_nco_sum_q_13_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2116_ (.D(_0007_),
    .Q(u_uart_core_nco_sum_q_14_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2117_ (.D(_0008_),
    .Q(u_uart_core_nco_sum_q_15_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2118_ (.D(_0001_),
    .Q(u_uart_core_nco_sum_q_16_),
    .RESET_B(net80),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2119_ (.D(u_reg_reset_sync_intq),
    .Q(reg_rst_ni),
    .RESET_B(rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2120_ (.D(net25),
    .Q(u_reg_reset_sync_intq),
    .RESET_B(rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _2120__26 (.HI(net25));
 sky130_fd_sc_hd__dfrtp_1 _2121_ (.D(u_core_reset_sync_intq),
    .Q(core_rst_ni),
    .RESET_B(rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2122_ (.D(net26),
    .Q(u_core_reset_sync_intq),
    .RESET_B(rst_ni),
    .CLK(clk_i));
 sky130_fd_sc_hd__conb_1 _2122__27 (.HI(net26));
 sky130_fd_sc_hd__edfxtp_1 _2123_ (.D(net84),
    .DE(_0018_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_63_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2124_ (.D(net84),
    .DE(_0019_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_55_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2125_ (.D(net84),
    .DE(_0020_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_47_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2126_ (.D(net84),
    .DE(_0021_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_39_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2127_ (.D(net84),
    .DE(_0022_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_31_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2128_ (.D(net84),
    .DE(_0023_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_23_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2129_ (.D(net84),
    .DE(_0024_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_15_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2130_ (.D(net84),
    .DE(_0025_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_7_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2131_ (.D(net39),
    .DE(_0026_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_79_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2132_ (.D(net39),
    .DE(_0027_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_71_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2133_ (.D(net39),
    .DE(_0028_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_63_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2134_ (.D(net39),
    .DE(_0029_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_55_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2135_ (.D(net39),
    .DE(_0030_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_47_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2136_ (.D(net39),
    .DE(_0031_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_39_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2137_ (.D(net39),
    .DE(_0032_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_31_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2138_ (.D(net39),
    .DE(_0033_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_23_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2139_ (.D(net39),
    .DE(_0034_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_15_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2140_ (.D(net39),
    .DE(_0035_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_127_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2141_ (.D(net39),
    .DE(_0036_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_119_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2142_ (.D(net39),
    .DE(_0037_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_111_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2143_ (.D(net39),
    .DE(_0038_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_103_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2144_ (.D(net39),
    .DE(_0039_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_95_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2145_ (.D(net39),
    .DE(_0040_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_87_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2146_ (.D(net39),
    .DE(_0041_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_7_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2147_ (.D(net44),
    .DE(_0041_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_0_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2148_ (.D(net45),
    .DE(_0041_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_1_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2149_ (.D(net46),
    .DE(_0041_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_2_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2150_ (.D(net47),
    .DE(_0041_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_3_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2151_ (.D(net48),
    .DE(_0041_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_4_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2152_ (.D(net49),
    .DE(_0041_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_5_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2153_ (.D(net50),
    .DE(_0041_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_6_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2154_ (.D(net44),
    .DE(_0040_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_80_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2155_ (.D(net45),
    .DE(_0040_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_81_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2156_ (.D(net46),
    .DE(_0040_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_82_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2157_ (.D(net47),
    .DE(_0040_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_83_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2158_ (.D(net48),
    .DE(_0040_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_84_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2159_ (.D(net49),
    .DE(_0040_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_85_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2160_ (.D(net50),
    .DE(_0040_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_86_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2161_ (.D(net44),
    .DE(_0039_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_88_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2162_ (.D(net45),
    .DE(_0039_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_89_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2163_ (.D(net46),
    .DE(_0039_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_90_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2164_ (.D(net47),
    .DE(_0039_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_91_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2165_ (.D(net48),
    .DE(_0039_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_92_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2166_ (.D(net49),
    .DE(_0039_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_93_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2167_ (.D(net50),
    .DE(_0039_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_94_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2168_ (.D(net44),
    .DE(_0038_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_96_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2169_ (.D(net45),
    .DE(_0038_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_97_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2170_ (.D(net46),
    .DE(_0038_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_98_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2171_ (.D(net47),
    .DE(_0038_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_99_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2172_ (.D(net48),
    .DE(_0038_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_100_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2173_ (.D(net49),
    .DE(_0038_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_101_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2174_ (.D(net50),
    .DE(_0038_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_102_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2175_ (.D(net44),
    .DE(_0037_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_104_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2176_ (.D(net45),
    .DE(_0037_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_105_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2177_ (.D(net46),
    .DE(_0037_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_106_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2178_ (.D(net47),
    .DE(_0037_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_107_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2179_ (.D(net48),
    .DE(_0037_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_108_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2180_ (.D(net49),
    .DE(_0037_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_109_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2181_ (.D(net50),
    .DE(_0037_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_110_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2182_ (.D(net44),
    .DE(_0036_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_112_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2183_ (.D(net45),
    .DE(_0036_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_113_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2184_ (.D(net46),
    .DE(_0036_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_114_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2185_ (.D(net47),
    .DE(_0036_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_115_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2186_ (.D(net48),
    .DE(_0036_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_116_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2187_ (.D(net49),
    .DE(_0036_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_117_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2188_ (.D(net50),
    .DE(_0036_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_118_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2189_ (.D(net44),
    .DE(_0035_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_120_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2190_ (.D(net45),
    .DE(_0035_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_121_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2191_ (.D(net46),
    .DE(_0035_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_122_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2192_ (.D(net47),
    .DE(_0035_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_123_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2193_ (.D(net48),
    .DE(_0035_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_124_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2194_ (.D(net49),
    .DE(_0035_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_125_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2195_ (.D(net50),
    .DE(_0035_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_126_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2196_ (.D(net44),
    .DE(_0034_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_8_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2197_ (.D(net45),
    .DE(_0034_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_9_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2198_ (.D(net46),
    .DE(_0034_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_10_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2199_ (.D(net47),
    .DE(_0034_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_11_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2200_ (.D(net48),
    .DE(_0034_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_12_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2201_ (.D(net49),
    .DE(_0034_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_13_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2202_ (.D(net50),
    .DE(_0034_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_14_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2203_ (.D(net44),
    .DE(_0033_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_16_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2204_ (.D(net45),
    .DE(_0033_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_17_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2205_ (.D(net46),
    .DE(_0033_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_18_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2206_ (.D(net47),
    .DE(_0033_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_19_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2207_ (.D(net48),
    .DE(_0033_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_20_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2208_ (.D(net49),
    .DE(_0033_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_21_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2209_ (.D(net50),
    .DE(_0033_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_22_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2210_ (.D(net44),
    .DE(_0032_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_24_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2211_ (.D(net45),
    .DE(_0032_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_25_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2212_ (.D(net46),
    .DE(_0032_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_26_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2213_ (.D(net47),
    .DE(_0032_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_27_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2214_ (.D(net48),
    .DE(_0032_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_28_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2215_ (.D(net49),
    .DE(_0032_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_29_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2216_ (.D(net50),
    .DE(_0032_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_30_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2217_ (.D(net44),
    .DE(_0031_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_32_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2218_ (.D(net45),
    .DE(_0031_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_33_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2219_ (.D(net46),
    .DE(_0031_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_34_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2220_ (.D(net47),
    .DE(_0031_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_35_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2221_ (.D(net48),
    .DE(_0031_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_36_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2222_ (.D(net49),
    .DE(_0031_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_37_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2223_ (.D(net50),
    .DE(_0031_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_38_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2224_ (.D(net44),
    .DE(_0030_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_40_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2225_ (.D(net45),
    .DE(_0030_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_41_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2226_ (.D(net46),
    .DE(_0030_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_42_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2227_ (.D(net47),
    .DE(_0030_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_43_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2228_ (.D(net48),
    .DE(_0030_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_44_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2229_ (.D(net49),
    .DE(_0030_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_45_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2230_ (.D(net50),
    .DE(_0030_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_46_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2231_ (.D(net44),
    .DE(_0029_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_48_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2232_ (.D(net45),
    .DE(_0029_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_49_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2233_ (.D(net46),
    .DE(_0029_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_50_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2234_ (.D(net47),
    .DE(_0029_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_51_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2235_ (.D(net48),
    .DE(_0029_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_52_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2236_ (.D(net49),
    .DE(_0029_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_53_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2237_ (.D(net50),
    .DE(_0029_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_54_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2238_ (.D(net44),
    .DE(_0028_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_56_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2239_ (.D(net45),
    .DE(_0028_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_57_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2240_ (.D(net46),
    .DE(_0028_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_58_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2241_ (.D(net47),
    .DE(_0028_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_59_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2242_ (.D(net48),
    .DE(_0028_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_60_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2243_ (.D(net49),
    .DE(_0028_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_61_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2244_ (.D(net50),
    .DE(_0028_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_62_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2245_ (.D(net44),
    .DE(_0027_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_64_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2246_ (.D(net45),
    .DE(_0027_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_65_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2247_ (.D(net46),
    .DE(_0027_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_66_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2248_ (.D(net47),
    .DE(_0027_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_67_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2249_ (.D(net48),
    .DE(_0027_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_68_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2250_ (.D(net49),
    .DE(_0027_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_69_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2251_ (.D(net50),
    .DE(_0027_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_70_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2252_ (.D(net44),
    .DE(_0026_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_72_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2253_ (.D(net45),
    .DE(_0026_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_73_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2254_ (.D(net46),
    .DE(_0026_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_74_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2255_ (.D(net47),
    .DE(_0026_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_75_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2256_ (.D(net48),
    .DE(_0026_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_76_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2257_ (.D(net49),
    .DE(_0026_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_77_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2258_ (.D(net50),
    .DE(_0026_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_storage_78_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2259_ (.D(net91),
    .DE(_0025_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_0_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2260_ (.D(net90),
    .DE(_0025_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_1_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2261_ (.D(net89),
    .DE(_0025_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_2_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2262_ (.D(net88),
    .DE(_0025_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_3_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2263_ (.D(net87),
    .DE(_0025_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_4_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2264_ (.D(net86),
    .DE(_0025_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_5_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2265_ (.D(net85),
    .DE(_0025_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_6_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2266_ (.D(net91),
    .DE(_0024_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_8_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2267_ (.D(net90),
    .DE(_0024_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_9_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2268_ (.D(net89),
    .DE(_0024_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_10_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2269_ (.D(net88),
    .DE(_0024_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_11_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2270_ (.D(net87),
    .DE(_0024_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_12_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2271_ (.D(net86),
    .DE(_0024_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_13_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2272_ (.D(net85),
    .DE(_0024_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_14_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2273_ (.D(net91),
    .DE(_0023_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_16_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2274_ (.D(net90),
    .DE(_0023_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_17_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2275_ (.D(net89),
    .DE(_0023_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_18_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2276_ (.D(net88),
    .DE(_0023_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_19_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2277_ (.D(net87),
    .DE(_0023_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_20_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2278_ (.D(net86),
    .DE(_0023_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_21_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2279_ (.D(net85),
    .DE(_0023_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_22_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2280_ (.D(net91),
    .DE(_0022_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_24_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2281_ (.D(net90),
    .DE(_0022_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_25_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2282_ (.D(net89),
    .DE(_0022_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_26_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2283_ (.D(net88),
    .DE(_0022_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_27_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2284_ (.D(net87),
    .DE(_0022_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_28_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2285_ (.D(net86),
    .DE(_0022_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_29_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2286_ (.D(net85),
    .DE(_0022_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_30_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2287_ (.D(net91),
    .DE(_0021_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_32_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2288_ (.D(net90),
    .DE(_0021_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_33_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2289_ (.D(net89),
    .DE(_0021_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_34_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2290_ (.D(net88),
    .DE(_0021_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_35_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2291_ (.D(net87),
    .DE(_0021_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_36_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2292_ (.D(net86),
    .DE(_0021_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_37_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2293_ (.D(net85),
    .DE(_0021_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_38_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2294_ (.D(net91),
    .DE(_0020_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_40_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2295_ (.D(net90),
    .DE(_0020_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_41_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2296_ (.D(net89),
    .DE(_0020_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_42_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2297_ (.D(net88),
    .DE(_0020_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_43_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2298_ (.D(net87),
    .DE(_0020_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_44_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2299_ (.D(net86),
    .DE(_0020_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_45_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2300_ (.D(net85),
    .DE(_0020_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_46_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2301_ (.D(net91),
    .DE(_0019_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_48_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2302_ (.D(net90),
    .DE(_0019_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_49_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2303_ (.D(net89),
    .DE(_0019_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_50_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2304_ (.D(net88),
    .DE(_0019_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_51_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2305_ (.D(net87),
    .DE(_0019_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_52_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2306_ (.D(net86),
    .DE(_0019_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_53_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2307_ (.D(net85),
    .DE(_0019_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_54_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2308_ (.D(net91),
    .DE(_0018_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_56_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2309_ (.D(net90),
    .DE(_0018_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_57_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2310_ (.D(net89),
    .DE(_0018_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_58_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2311_ (.D(net88),
    .DE(_0018_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_59_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2312_ (.D(net87),
    .DE(_0018_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_60_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2313_ (.D(net86),
    .DE(_0018_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_61_),
    .CLK(clk_i));
 sky130_fd_sc_hd__edfxtp_1 _2314_ (.D(net85),
    .DE(_0018_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_storage_62_),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2315_ (.D(_0146_),
    .Q(u_uart_core_uart_tx_sreg_q_0_),
    .SET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2316_ (.D(_0145_),
    .Q(u_uart_core_uart_tx_sreg_q_1_),
    .SET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2317_ (.D(_0144_),
    .Q(u_uart_core_uart_tx_sreg_q_2_),
    .SET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2318_ (.D(_0143_),
    .Q(u_uart_core_uart_tx_sreg_q_3_),
    .SET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2319_ (.D(_0142_),
    .Q(u_uart_core_uart_tx_sreg_q_4_),
    .SET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2320_ (.D(_0141_),
    .Q(u_uart_core_uart_tx_sreg_q_5_),
    .SET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2321_ (.D(_0140_),
    .Q(u_uart_core_uart_tx_sreg_q_6_),
    .SET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2322_ (.D(_0139_),
    .Q(u_uart_core_uart_tx_sreg_q_7_),
    .SET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2323_ (.D(_0138_),
    .Q(u_uart_core_uart_tx_sreg_q_8_),
    .SET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfstp_1 _2324_ (.D(_0147_),
    .Q(u_uart_core_uart_tx_sreg_q_9_),
    .SET_B(net82),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2325_ (.D(_0148_),
    .Q(u_uart_reg_tl_o_62_),
    .RESET_B(net74),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2326_ (.D(_0137_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_0_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2327_ (.D(_0136_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_1_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2328_ (.D(_0135_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2329_ (.D(_0134_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_),
    .RESET_B(net78),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2330_ (.D(_0149_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_4_),
    .RESET_B(net79),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2331_ (.D(_0133_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_0_),
    .RESET_B(net79),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2332_ (.D(_0132_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_),
    .RESET_B(net79),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2333_ (.D(_0131_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_),
    .RESET_B(net79),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2334_ (.D(_0130_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_),
    .RESET_B(net79),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2335_ (.D(_0150_),
    .Q(u_uart_core_u_uart_rxfifo_gen_normal_fifo_u_fifo_cnt_wptr_wrap_cnt_q_4_),
    .RESET_B(net79),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2336_ (.D(_0129_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2337_ (.D(_0128_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2338_ (.D(_0127_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_2_),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2339_ (.D(_0151_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_u_fifo_cnt_rptr_wrap_cnt_q_3_),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__dfrtp_1 _2340_ (.D(_0126_),
    .Q(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_0_),
    .RESET_B(net81),
    .CLK(clk_i));
 sky130_fd_sc_hd__buf_2 _2343_ (.A(u_uart_reg_tl_o_0_),
    .X(tl_o[0]));
 sky130_fd_sc_hd__buf_2 _2344_ (.A(u_uart_reg_tl_o_1_),
    .X(tl_o[1]));
 sky130_fd_sc_hd__buf_4 _2345_ (.A(net2),
    .X(tl_o[2]));
 sky130_fd_sc_hd__conb_1 _2345__3 (.LO(net2));
 sky130_fd_sc_hd__buf_4 _2346_ (.A(net3),
    .X(tl_o[3]));
 sky130_fd_sc_hd__conb_1 _2346__4 (.LO(net3));
 sky130_fd_sc_hd__buf_4 _2347_ (.A(net4),
    .X(tl_o[4]));
 sky130_fd_sc_hd__conb_1 _2347__5 (.LO(net4));
 sky130_fd_sc_hd__buf_4 _2348_ (.A(net5),
    .X(tl_o[5]));
 sky130_fd_sc_hd__conb_1 _2348__6 (.LO(net5));
 sky130_fd_sc_hd__buf_4 _2349_ (.A(net6),
    .X(tl_o[6]));
 sky130_fd_sc_hd__conb_1 _2349__7 (.LO(net6));
 sky130_fd_sc_hd__buf_4 _2350_ (.A(net7),
    .X(tl_o[7]));
 sky130_fd_sc_hd__conb_1 _2350__8 (.LO(net7));
 sky130_fd_sc_hd__buf_4 _2351_ (.A(net8),
    .X(tl_o[8]));
 sky130_fd_sc_hd__conb_1 _2351__9 (.LO(net8));
 sky130_fd_sc_hd__buf_4 _2352_ (.A(net9),
    .X(tl_o[9]));
 sky130_fd_sc_hd__conb_1 _2352__10 (.LO(net9));
 sky130_fd_sc_hd__buf_4 _2353_ (.A(net10),
    .X(tl_o[10]));
 sky130_fd_sc_hd__conb_1 _2353__11 (.LO(net10));
 sky130_fd_sc_hd__buf_4 _2354_ (.A(net11),
    .X(tl_o[11]));
 sky130_fd_sc_hd__conb_1 _2354__12 (.LO(net11));
 sky130_fd_sc_hd__buf_4 _2355_ (.A(net12),
    .X(tl_o[12]));
 sky130_fd_sc_hd__conb_1 _2355__13 (.LO(net12));
 sky130_fd_sc_hd__buf_4 _2356_ (.A(net13),
    .X(tl_o[13]));
 sky130_fd_sc_hd__conb_1 _2356__14 (.LO(net13));
 sky130_fd_sc_hd__buf_4 _2357_ (.A(net14),
    .X(tl_o[14]));
 sky130_fd_sc_hd__conb_1 _2357__15 (.LO(net14));
 sky130_fd_sc_hd__buf_4 _2358_ (.A(net15),
    .X(tl_o[15]));
 sky130_fd_sc_hd__conb_1 _2358__16 (.LO(net15));
 sky130_fd_sc_hd__buf_2 _2359_ (.A(u_uart_reg_tl_o_16_),
    .X(tl_o[16]));
 sky130_fd_sc_hd__buf_2 _2360_ (.A(u_uart_reg_tl_o_17_),
    .X(tl_o[17]));
 sky130_fd_sc_hd__buf_2 _2361_ (.A(u_uart_reg_tl_o_18_),
    .X(tl_o[18]));
 sky130_fd_sc_hd__buf_2 _2362_ (.A(u_uart_reg_tl_o_19_),
    .X(tl_o[19]));
 sky130_fd_sc_hd__buf_2 _2363_ (.A(u_uart_reg_tl_o_20_),
    .X(tl_o[20]));
 sky130_fd_sc_hd__buf_2 _2364_ (.A(u_uart_reg_tl_o_21_),
    .X(tl_o[21]));
 sky130_fd_sc_hd__buf_2 _2365_ (.A(u_uart_reg_tl_o_22_),
    .X(tl_o[22]));
 sky130_fd_sc_hd__buf_2 _2366_ (.A(u_uart_reg_tl_o_23_),
    .X(tl_o[23]));
 sky130_fd_sc_hd__buf_2 _2367_ (.A(u_uart_reg_tl_o_24_),
    .X(tl_o[24]));
 sky130_fd_sc_hd__buf_2 _2368_ (.A(u_uart_reg_tl_o_25_),
    .X(tl_o[25]));
 sky130_fd_sc_hd__buf_2 _2369_ (.A(u_uart_reg_tl_o_26_),
    .X(tl_o[26]));
 sky130_fd_sc_hd__buf_2 _2370_ (.A(u_uart_reg_tl_o_27_),
    .X(tl_o[27]));
 sky130_fd_sc_hd__buf_2 _2371_ (.A(u_uart_reg_tl_o_28_),
    .X(tl_o[28]));
 sky130_fd_sc_hd__buf_2 _2372_ (.A(u_uart_reg_tl_o_29_),
    .X(tl_o[29]));
 sky130_fd_sc_hd__buf_2 _2373_ (.A(u_uart_reg_tl_o_30_),
    .X(tl_o[30]));
 sky130_fd_sc_hd__buf_2 _2374_ (.A(u_uart_reg_tl_o_31_),
    .X(tl_o[31]));
 sky130_fd_sc_hd__buf_2 _2375_ (.A(u_uart_reg_tl_o_32_),
    .X(tl_o[32]));
 sky130_fd_sc_hd__buf_2 _2376_ (.A(u_uart_reg_tl_o_33_),
    .X(tl_o[33]));
 sky130_fd_sc_hd__buf_2 _2377_ (.A(u_uart_reg_tl_o_34_),
    .X(tl_o[34]));
 sky130_fd_sc_hd__buf_2 _2378_ (.A(u_uart_reg_tl_o_35_),
    .X(tl_o[35]));
 sky130_fd_sc_hd__buf_2 _2379_ (.A(u_uart_reg_tl_o_36_),
    .X(tl_o[36]));
 sky130_fd_sc_hd__buf_2 _2380_ (.A(u_uart_reg_tl_o_37_),
    .X(tl_o[37]));
 sky130_fd_sc_hd__buf_2 _2381_ (.A(u_uart_reg_tl_o_38_),
    .X(tl_o[38]));
 sky130_fd_sc_hd__buf_2 _2382_ (.A(u_uart_reg_tl_o_39_),
    .X(tl_o[39]));
 sky130_fd_sc_hd__buf_2 _2383_ (.A(u_uart_reg_tl_o_40_),
    .X(tl_o[40]));
 sky130_fd_sc_hd__buf_2 _2384_ (.A(u_uart_reg_tl_o_41_),
    .X(tl_o[41]));
 sky130_fd_sc_hd__buf_2 _2385_ (.A(u_uart_reg_tl_o_42_),
    .X(tl_o[42]));
 sky130_fd_sc_hd__buf_2 _2386_ (.A(u_uart_reg_tl_o_43_),
    .X(tl_o[43]));
 sky130_fd_sc_hd__buf_2 _2387_ (.A(u_uart_reg_tl_o_44_),
    .X(tl_o[44]));
 sky130_fd_sc_hd__buf_2 _2388_ (.A(u_uart_reg_tl_o_45_),
    .X(tl_o[45]));
 sky130_fd_sc_hd__buf_2 _2389_ (.A(u_uart_reg_tl_o_46_),
    .X(tl_o[46]));
 sky130_fd_sc_hd__buf_2 _2390_ (.A(u_uart_reg_tl_o_47_),
    .X(tl_o[47]));
 sky130_fd_sc_hd__buf_4 _2391_ (.A(net16),
    .X(tl_o[48]));
 sky130_fd_sc_hd__conb_1 _2391__17 (.LO(net16));
 sky130_fd_sc_hd__buf_2 _2392_ (.A(u_uart_reg_tl_o_49_),
    .X(tl_o[49]));
 sky130_fd_sc_hd__buf_2 _2393_ (.A(u_uart_reg_tl_o_50_),
    .X(tl_o[50]));
 sky130_fd_sc_hd__buf_2 _2394_ (.A(u_uart_reg_tl_o_51_),
    .X(tl_o[51]));
 sky130_fd_sc_hd__buf_2 _2395_ (.A(u_uart_reg_tl_o_52_),
    .X(tl_o[52]));
 sky130_fd_sc_hd__buf_2 _2396_ (.A(u_uart_reg_tl_o_53_),
    .X(tl_o[53]));
 sky130_fd_sc_hd__buf_2 _2397_ (.A(u_uart_reg_tl_o_54_),
    .X(tl_o[54]));
 sky130_fd_sc_hd__buf_2 _2398_ (.A(u_uart_reg_tl_o_55_),
    .X(tl_o[55]));
 sky130_fd_sc_hd__buf_2 _2399_ (.A(u_uart_reg_tl_o_56_),
    .X(tl_o[56]));
 sky130_fd_sc_hd__buf_2 _2400_ (.A(u_uart_reg_tl_o_57_),
    .X(tl_o[57]));
 sky130_fd_sc_hd__buf_2 _2401_ (.A(u_uart_reg_tl_o_58_),
    .X(tl_o[58]));
 sky130_fd_sc_hd__buf_4 _2402_ (.A(net17),
    .X(tl_o[59]));
 sky130_fd_sc_hd__conb_1 _2402__18 (.LO(net17));
 sky130_fd_sc_hd__buf_4 _2403_ (.A(net18),
    .X(tl_o[60]));
 sky130_fd_sc_hd__conb_1 _2403__19 (.LO(net18));
 sky130_fd_sc_hd__buf_4 _2404_ (.A(net19),
    .X(tl_o[61]));
 sky130_fd_sc_hd__conb_1 _2404__20 (.LO(net19));
 sky130_fd_sc_hd__buf_2 _2405_ (.A(u_uart_reg_tl_o_62_),
    .X(tl_o[62]));
 sky130_fd_sc_hd__buf_4 _2406_ (.A(net20),
    .X(tl_o[63]));
 sky130_fd_sc_hd__conb_1 _2406__21 (.LO(net20));
 sky130_fd_sc_hd__buf_4 _2407_ (.A(net21),
    .X(tl_o[64]));
 sky130_fd_sc_hd__conb_1 _2407__22 (.LO(net21));
 sky130_fd_sc_hd__buf_2 _2408_ (.A(u_uart_reg_tl_o_65_),
    .X(tl_o[65]));
 sky130_fd_sc_hd__buf_2 gain100 (.A(reg2hw_41_),
    .X(net99));
 sky130_fd_sc_hd__buf_2 gain101 (.A(reg2hw_38_),
    .X(net100));
 sky130_fd_sc_hd__buf_2 gain102 (.A(u_uart_core_uart_rx_sreg_q_8_),
    .X(net101));
 sky130_fd_sc_hd__buf_2 gain103 (.A(u_uart_core_uart_rx_sreg_q_7_),
    .X(net102));
 sky130_fd_sc_hd__buf_2 gain104 (.A(u_uart_core_uart_rx_sreg_q_6_),
    .X(net103));
 sky130_fd_sc_hd__buf_2 gain105 (.A(u_uart_core_uart_rx_sreg_q_5_),
    .X(net104));
 sky130_fd_sc_hd__buf_2 gain106 (.A(u_uart_core_uart_rx_sreg_q_4_),
    .X(net105));
 sky130_fd_sc_hd__buf_2 gain107 (.A(u_uart_core_uart_rx_sreg_q_3_),
    .X(net106));
 sky130_fd_sc_hd__buf_2 gain108 (.A(u_uart_core_uart_rx_sreg_q_2_),
    .X(net107));
 sky130_fd_sc_hd__buf_2 gain109 (.A(hw2reg_28_),
    .X(net108));
 sky130_fd_sc_hd__buf_2 gain110 (.A(u_uart_core_uart_rx_bit_cnt_q_1_),
    .X(net109));
 sky130_fd_sc_hd__buf_4 gain111 (.A(u_uart_core_uart_rx_bit_cnt_q_0_),
    .X(net110));
 sky130_fd_sc_hd__buf_12 gain112 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_2_),
    .X(net111));
 sky130_fd_sc_hd__buf_12 gain113 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_1_),
    .X(net112));
 sky130_fd_sc_hd__buf_12 gain28 (.A(_0815_),
    .X(net27));
 sky130_fd_sc_hd__buf_12 gain29 (.A(_0813_),
    .X(net28));
 sky130_fd_sc_hd__buf_12 gain30 (.A(_0812_),
    .X(net29));
 sky130_fd_sc_hd__buf_12 gain31 (.A(_0803_),
    .X(net30));
 sky130_fd_sc_hd__buf_12 gain32 (.A(u_uart_reg_u_reg_core_reg_we_check_3_),
    .X(net31));
 sky130_fd_sc_hd__buf_12 gain33 (.A(_0906_),
    .X(net32));
 sky130_fd_sc_hd__buf_12 gain34 (.A(_0883_),
    .X(net33));
 sky130_fd_sc_hd__buf_12 gain35 (.A(_0696_),
    .X(net34));
 sky130_fd_sc_hd__buf_4 gain36 (.A(_0966_),
    .X(net35));
 sky130_fd_sc_hd__buf_12 gain37 (.A(net37),
    .X(net36));
 sky130_fd_sc_hd__buf_2 gain38 (.A(_0885_),
    .X(net37));
 sky130_fd_sc_hd__buf_12 gain39 (.A(_0972_),
    .X(net38));
 sky130_fd_sc_hd__buf_12 gain40 (.A(u_uart_core_rx_fifo_data_7_),
    .X(net39));
 sky130_fd_sc_hd__buf_12 gain41 (.A(_0482_),
    .X(net40));
 sky130_fd_sc_hd__buf_12 gain42 (.A(_0472_),
    .X(net41));
 sky130_fd_sc_hd__buf_12 gain43 (.A(_0973_),
    .X(net42));
 sky130_fd_sc_hd__buf_12 gain44 (.A(_0968_),
    .X(net43));
 sky130_fd_sc_hd__buf_12 gain45 (.A(u_uart_core_rx_fifo_data_0_),
    .X(net44));
 sky130_fd_sc_hd__buf_12 gain46 (.A(u_uart_core_rx_fifo_data_1_),
    .X(net45));
 sky130_fd_sc_hd__buf_12 gain47 (.A(u_uart_core_rx_fifo_data_2_),
    .X(net46));
 sky130_fd_sc_hd__buf_12 gain48 (.A(u_uart_core_rx_fifo_data_3_),
    .X(net47));
 sky130_fd_sc_hd__buf_12 gain49 (.A(u_uart_core_rx_fifo_data_4_),
    .X(net48));
 sky130_fd_sc_hd__buf_12 gain50 (.A(u_uart_core_rx_fifo_data_5_),
    .X(net49));
 sky130_fd_sc_hd__buf_12 gain51 (.A(u_uart_core_rx_fifo_data_6_),
    .X(net50));
 sky130_fd_sc_hd__buf_12 gain52 (.A(_0814_),
    .X(net51));
 sky130_fd_sc_hd__buf_12 gain53 (.A(_0805_),
    .X(net52));
 sky130_fd_sc_hd__buf_12 gain54 (.A(_0764_),
    .X(net53));
 sky130_fd_sc_hd__buf_12 gain55 (.A(_0309_),
    .X(net54));
 sky130_fd_sc_hd__buf_2 gain56 (.A(_0822_),
    .X(net55));
 sky130_fd_sc_hd__buf_2 gain57 (.A(_0711_),
    .X(net56));
 sky130_fd_sc_hd__buf_2 gain58 (.A(_0705_),
    .X(net57));
 sky130_fd_sc_hd__buf_12 gain59 (.A(_0674_),
    .X(net58));
 sky130_fd_sc_hd__buf_2 gain60 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_wptr_0_),
    .X(net59));
 sky130_fd_sc_hd__buf_12 gain61 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_2_),
    .X(net60));
 sky130_fd_sc_hd__buf_12 gain62 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_1_),
    .X(net61));
 sky130_fd_sc_hd__buf_12 gain63 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_fifo_rptr_0_),
    .X(net62));
 sky130_fd_sc_hd__buf_12 gain64 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_3_),
    .X(net63));
 sky130_fd_sc_hd__buf_12 gain65 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_2_),
    .X(net64));
 sky130_fd_sc_hd__buf_12 gain66 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_1_),
    .X(net65));
 sky130_fd_sc_hd__buf_2 gain67 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_wptr_0_),
    .X(net66));
 sky130_fd_sc_hd__buf_12 gain68 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_3_),
    .X(net67));
 sky130_fd_sc_hd__buf_12 gain69 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_2_),
    .X(net68));
 sky130_fd_sc_hd__buf_12 gain70 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_1_),
    .X(net69));
 sky130_fd_sc_hd__buf_12 gain71 (.A(u_uart_core_u_uart_rxfifo_gen_normal_fifo_fifo_rptr_0_),
    .X(net70));
 sky130_fd_sc_hd__buf_2 gain72 (.A(core_rst_ni),
    .X(net71));
 sky130_fd_sc_hd__buf_12 gain73 (.A(net75),
    .X(net72));
 sky130_fd_sc_hd__buf_12 gain74 (.A(net75),
    .X(net73));
 sky130_fd_sc_hd__buf_12 gain75 (.A(net75),
    .X(net74));
 sky130_fd_sc_hd__buf_12 gain76 (.A(reg_rst_ni),
    .X(net75));
 sky130_fd_sc_hd__buf_2 gain77 (.A(u_uart_core_nco_sum_q_16_),
    .X(net76));
 sky130_fd_sc_hd__buf_2 gain78 (.A(u_uart_core_nco_sum_q_12_),
    .X(net77));
 sky130_fd_sc_hd__buf_12 gain79 (.A(net79),
    .X(net78));
 sky130_fd_sc_hd__buf_12 gain80 (.A(u_uart_core_rx_rst_ni),
    .X(net79));
 sky130_fd_sc_hd__buf_12 gain81 (.A(u_uart_core_timing_rst_ni),
    .X(net80));
 sky130_fd_sc_hd__buf_12 gain82 (.A(net82),
    .X(net81));
 sky130_fd_sc_hd__buf_12 gain83 (.A(u_uart_core_tx_rst_ni),
    .X(net82));
 sky130_fd_sc_hd__buf_2 gain84 (.A(u_uart_core_u_uart_txfifo_gen_normal_fifo_under_rst),
    .X(net83));
 sky130_fd_sc_hd__buf_4 gain85 (.A(reg2hw_12_),
    .X(net84));
 sky130_fd_sc_hd__buf_4 gain86 (.A(reg2hw_11_),
    .X(net85));
 sky130_fd_sc_hd__buf_4 gain87 (.A(reg2hw_10_),
    .X(net86));
 sky130_fd_sc_hd__buf_4 gain88 (.A(reg2hw_9_),
    .X(net87));
 sky130_fd_sc_hd__buf_4 gain89 (.A(reg2hw_8_),
    .X(net88));
 sky130_fd_sc_hd__buf_4 gain90 (.A(reg2hw_7_),
    .X(net89));
 sky130_fd_sc_hd__buf_4 gain91 (.A(reg2hw_6_),
    .X(net90));
 sky130_fd_sc_hd__buf_4 gain92 (.A(reg2hw_5_),
    .X(net91));
 sky130_fd_sc_hd__buf_2 gain93 (.A(reg2hw_34_),
    .X(net92));
 sky130_fd_sc_hd__buf_2 gain94 (.A(reg2hw_37_),
    .X(net93));
 sky130_fd_sc_hd__buf_2 gain95 (.A(reg2hw_40_),
    .X(net94));
 sky130_fd_sc_hd__buf_12 gain96 (.A(reg2hw_39_),
    .X(net95));
 sky130_fd_sc_hd__buf_2 gain97 (.A(reg2hw_53_),
    .X(net96));
 sky130_fd_sc_hd__buf_2 gain98 (.A(reg2hw_47_),
    .X(net97));
 sky130_fd_sc_hd__buf_2 gain99 (.A(reg2hw_45_),
    .X(net98));
endmodule
