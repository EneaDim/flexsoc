// removed package "prim_count_pkg"
// removed package "prim_mubi_pkg"
// removed package "prim_secded_pkg"
// removed package "prim_subreg_pkg"
// removed package "prim_util_pkg"
// removed package "tlul_pkg"
// removed package "top_pkg"
module prim_arbiter_ppc (
	clk_i,
	rst_ni,
	req_chk_i,
	req_i,
	data_i,
	gnt_o,
	idx_o,
	valid_o,
	data_o,
	ready_i
);
	reg _sv2v_0;
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:28:13
	parameter [31:0] N = 8;
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:29:13
	parameter [31:0] DW = 32;
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:33:13
	parameter [0:0] EnDataPort = 1;
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:36:14
	localparam signed [31:0] IdxW = $clog2(N);
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:38:3
	input clk_i;
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:39:3
	input rst_ni;
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:41:3
	input req_chk_i;
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:43:3
	input [N - 1:0] req_i;
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:44:3
	input [(N * DW) - 1:0] data_i;
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:45:3
	output wire [N - 1:0] gnt_o;
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:46:3
	output reg [IdxW - 1:0] idx_o;
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:48:3
	output wire valid_o;
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:49:3
	output reg [DW - 1:0] data_o;
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:50:3
	input ready_i;
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:54:3
	wire unused_req_chk;
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:55:3
	assign unused_req_chk = req_chk_i;
	// Trace: macro expansion of ASSERT_INIT at ips/prim_opentitan/prim_arbiter_ppc.sv:57:378
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/prim_opentitan/prim_arbiter_ppc.sv:57:466
		begin : CheckNGreaterZero_A
			
		end
	end
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:60:3
	generate
		if (N == 1) begin : gen_degenerate_case
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:62:5
			assign valid_o = req_i[0];
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:63:5
			wire [DW:1] sv2v_tmp_9E8F4;
			assign sv2v_tmp_9E8F4 = data_i[(N - 1) * DW+:DW];
			always @(*) data_o = sv2v_tmp_9E8F4;
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:64:5
			assign gnt_o[0] = valid_o & ready_i;
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:65:5
			wire [IdxW:1] sv2v_tmp_8C7A7;
			assign sv2v_tmp_8C7A7 = 1'sb0;
			always @(*) idx_o = sv2v_tmp_8C7A7;
		end
		else begin : gen_normal_case
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:69:5
			wire [N - 1:0] masked_req;
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:70:5
			reg [N - 1:0] ppc_out;
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:71:5
			wire [N - 1:0] arb_req;
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:72:5
			reg [N - 1:0] mask;
			wire [N - 1:0] mask_next;
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:73:5
			wire [N - 1:0] winner;
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:75:5
			assign masked_req = mask & req_i;
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:76:5
			assign arb_req = (|masked_req ? masked_req : req_i);
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:81:5
			always @(*) begin
				if (_sv2v_0)
					;
				// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:82:7
				ppc_out[0] = arb_req[0];
				// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:83:7
				begin : sv2v_autoblock_1
					// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:83:12
					reg signed [31:0] i;
					// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:83:12
					for (i = 1; i < N; i = i + 1)
						begin
							// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:84:9
							ppc_out[i] = ppc_out[i - 1] | arb_req[i];
						end
				end
			end
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:89:5
			assign winner = ppc_out ^ {ppc_out[N - 2:0], 1'b0};
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:90:5
			assign gnt_o = (ready_i ? winner : {N {1'sb0}});
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:92:5
			assign valid_o = |req_i;
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:94:5
			assign mask_next = {ppc_out[N - 2:0], 1'b0};
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:95:5
			always @(posedge clk_i or negedge rst_ni)
				// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:96:7
				if (!rst_ni)
					// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:97:9
					mask <= 1'sb0;
				else if (valid_o && ready_i)
					// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:100:9
					mask <= mask_next;
				else if (valid_o && !ready_i)
					// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:103:9
					mask <= ppc_out;
			if (EnDataPort == 1) begin : gen_datapath
				// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:108:7
				always @(*) begin
					if (_sv2v_0)
						;
					// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:109:9
					data_o = 1'sb0;
					// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:110:9
					begin : sv2v_autoblock_2
						// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:110:14
						reg signed [31:0] i;
						// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:110:14
						for (i = 0; i < N; i = i + 1)
							begin
								// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:111:11
								if (winner[i])
									// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:112:13
									data_o = data_i[((N - 1) - i) * DW+:DW];
							end
					end
				end
			end
			else begin : gen_nodatapath
				// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:117:7
				wire [DW:1] sv2v_tmp_116D0;
				assign sv2v_tmp_116D0 = 1'sb1;
				always @(*) data_o = sv2v_tmp_116D0;
				// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:119:7
				wire [(N * DW) - 1:0] unused_data;
				// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:120:7
				assign unused_data = data_i;
			end
			// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:123:5
			always @(*) begin
				if (_sv2v_0)
					;
				// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:124:7
				idx_o = 1'sb0;
				// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:125:7
				begin : sv2v_autoblock_3
					// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:125:12
					reg [31:0] i;
					// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:125:12
					for (i = 0; i < N; i = i + 1)
						begin
							// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:126:9
							if (winner[i])
								// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:127:11
								idx_o = i[IdxW - 1:0];
						end
				end
			end
		end
	endgenerate
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_arbiter_ppc.sv:139:169
	// removed an assertion item
	// ValidKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(valid_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_arbiter_ppc.sv:139:724
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_arbiter_ppc.sv", 139, "ValidKnown_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_arbiter_ppc.sv:140:167
	// removed an assertion item
	// GrantKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(gnt_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_arbiter_ppc.sv:140:722
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_arbiter_ppc.sv", 140, "GrantKnown_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_arbiter_ppc.sv:141:165
	// removed an assertion item
	// IdxKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(idx_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_arbiter_ppc.sv:141:720
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_arbiter_ppc.sv", 141, "IdxKnown_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_arbiter_ppc.sv:147:24
	// removed an assertion item
	// RoundRobin_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(##(1) (((valid_o && ready_i) && $past(ready_i)) && $past(valid_o)) && |(req_i & ~((N'(1) << ($past(idx_o) + 1)) - 1)) |-> idx_o > $past(idx_o))
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_arbiter_ppc.sv:147:579
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_arbiter_ppc.sv", 147, "RoundRobin_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_arbiter_ppc.sv:149:38
	// removed an assertion item
	// CheckHotOne_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	$onehot0(gnt_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_arbiter_ppc.sv:149:593
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_arbiter_ppc.sv", 149, "CheckHotOne_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_arbiter_ppc.sv:151:45
	// removed an assertion item
	// GntImpliesReady_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(|gnt_o |-> ready_i)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_arbiter_ppc.sv:151:600
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_arbiter_ppc.sv", 151, "GntImpliesReady_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_arbiter_ppc.sv:153:45
	// removed an assertion item
	// GntImpliesValid_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(|gnt_o |-> valid_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_arbiter_ppc.sv:153:600
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_arbiter_ppc.sv", 153, "GntImpliesValid_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_arbiter_ppc.sv:155:61
	// removed an assertion item
	// ReqAndReadyImplyGrant_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(|req_i && ready_i |-> |gnt_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_arbiter_ppc.sv:155:616
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_arbiter_ppc.sv", 155, "ReqAndReadyImplyGrant_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_arbiter_ppc.sv:157:45
	// removed an assertion item
	// ReqImpliesValid_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(|req_i |-> valid_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_arbiter_ppc.sv:157:600
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_arbiter_ppc.sv", 157, "ReqImpliesValid_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_arbiter_ppc.sv:159:64
	// removed an assertion item
	// ReadyAndValidImplyGrant_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(ready_i && valid_o |-> |gnt_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_arbiter_ppc.sv:159:619
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_arbiter_ppc.sv", 159, "ReadyAndValidImplyGrant_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_arbiter_ppc.sv:161:67
	// removed an assertion item
	// NoReadyValidNoGrant_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(!(ready_i || valid_o) |-> gnt_o == 0)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_arbiter_ppc.sv:161:622
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_arbiter_ppc.sv", 161, "NoReadyValidNoGrant_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_arbiter_ppc.sv:163:77
	// removed an assertion item
	// IndexIsCorrect_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(ready_i && valid_o |-> gnt_o[idx_o] && req_i[idx_o])
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_arbiter_ppc.sv:163:632
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_arbiter_ppc.sv", 163, "IndexIsCorrect_A");
	// end
	// Trace: ips/prim_opentitan/prim_arbiter_ppc.sv:165:1
	generate
		if (EnDataPort) begin : gen_data_port_assertion
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_arbiter_ppc.sv:167:66
			// removed an assertion item
			// DataFlow_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
			// 	(ready_i && valid_o |-> data_o == data_i[idx_o])
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_arbiter_ppc.sv:167:621
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_arbiter_ppc.sv", 167, "DataFlow_A");
			// end
		end
	endgenerate
	// Trace: macro expansion of ASSUME at ips/prim_opentitan/prim_arbiter_ppc.sv:172:72
	// removed an assertion item
	// ReqStaysHighUntilGranted0_M : assume property (@(posedge clk_i) disable iff ((!rst_ni || !req_chk_i) !== '0)
	// 	(|req_i && !ready_i |=> (req_i & $past(req_i)) == $past(req_i))
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_arbiter_ppc.sv:172:627
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_arbiter_ppc.sv", 172, "ReqStaysHighUntilGranted0_M");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_arbiter_ppc.sv:175:32
	// removed an assertion item
	// LockArbDecision_A : assert property (@(posedge clk_i) disable iff ((!rst_ni || !req_chk_i) !== '0)
	// 	(|req_i && !ready_i |=> idx_o == $past(idx_o))
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_arbiter_ppc.sv:175:587
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_arbiter_ppc.sv", 175, "LockArbDecision_A");
	// end
	initial _sv2v_0 = 0;
endmodule
module prim_cdc_rand_delay (
	clk_i,
	rst_ni,
	prev_data_i,
	src_data_i,
	dst_data_o
);
	// Trace: ips/prim_opentitan/prim_cdc_rand_delay.sv:18:15
	parameter signed [31:0] DataWidth = 1;
	// Trace: ips/prim_opentitan/prim_cdc_rand_delay.sv:19:15
	parameter [0:0] Enable = 1;
	// Trace: ips/prim_opentitan/prim_cdc_rand_delay.sv:21:5
	input wire clk_i;
	// Trace: ips/prim_opentitan/prim_cdc_rand_delay.sv:22:5
	input wire rst_ni;
	// Trace: ips/prim_opentitan/prim_cdc_rand_delay.sv:23:5
	input wire [DataWidth - 1:0] prev_data_i;
	// Trace: ips/prim_opentitan/prim_cdc_rand_delay.sv:24:5
	input wire [DataWidth - 1:0] src_data_i;
	// Trace: ips/prim_opentitan/prim_cdc_rand_delay.sv:25:5
	output wire [DataWidth - 1:0] dst_data_o;
	// Trace: ips/prim_opentitan/prim_cdc_rand_delay.sv:65:5
	assign dst_data_o = src_data_i;
endmodule
module prim_count (
	clk_i,
	rst_ni,
	clr_i,
	set_i,
	set_cnt_i,
	incr_en_i,
	decr_en_i,
	step_i,
	commit_i,
	cnt_o,
	cnt_after_commit_o,
	err_o
);
	// removed import prim_count_pkg::*;
	// Trace: ips/prim_opentitan/prim_count.sv:31:13
	parameter signed [31:0] Width = 2;
	// Trace: ips/prim_opentitan/prim_count.sv:34:13
	parameter [Width - 1:0] ResetValue = 1'sb0;
	// Trace: ips/prim_opentitan/prim_count.sv:37:13
	parameter [0:0] EnableAlertTriggerSVA = 1;
	// Trace: ips/prim_opentitan/prim_count.sv:47:13
	// removed localparam type prim_count_pkg_action_mask_t
	parameter [3:0] PossibleActions = {4 {1'b1}};
	// Trace: ips/prim_opentitan/prim_count.sv:49:3
	input clk_i;
	// Trace: ips/prim_opentitan/prim_count.sv:50:3
	input rst_ni;
	// Trace: ips/prim_opentitan/prim_count.sv:51:3
	input clr_i;
	// Trace: ips/prim_opentitan/prim_count.sv:52:3
	input set_i;
	// Trace: ips/prim_opentitan/prim_count.sv:53:3
	input [Width - 1:0] set_cnt_i;
	// Trace: ips/prim_opentitan/prim_count.sv:54:3
	input incr_en_i;
	// Trace: ips/prim_opentitan/prim_count.sv:55:3
	input decr_en_i;
	// Trace: ips/prim_opentitan/prim_count.sv:56:3
	input [Width - 1:0] step_i;
	// Trace: ips/prim_opentitan/prim_count.sv:57:3
	input commit_i;
	// Trace: ips/prim_opentitan/prim_count.sv:58:3
	output wire [Width - 1:0] cnt_o;
	// Trace: ips/prim_opentitan/prim_count.sv:59:3
	output wire [Width - 1:0] cnt_after_commit_o;
	// Trace: ips/prim_opentitan/prim_count.sv:60:3
	output wire err_o;
	// Trace: ips/prim_opentitan/prim_count.sv:68:3
	localparam signed [31:0] NumCnt = 2;
	// Trace: ips/prim_opentitan/prim_count.sv:69:3
	localparam [(NumCnt * Width) - 1:0] ResetValues = {{Width {1'b1}} - ResetValue, ResetValue};
	// Trace: ips/prim_opentitan/prim_count.sv:72:3
	wire [(NumCnt * Width) - 1:0] cnt_d;
	wire [(NumCnt * Width) - 1:0] cnt_d_committed;
	wire [(NumCnt * Width) - 1:0] cnt_q;
	// Trace: ips/prim_opentitan/prim_count.sv:78:3
	wire [(NumCnt * Width) - 1:0] fpv_force;
	// Trace: ips/prim_opentitan/prim_count.sv:80:3
	assign fpv_force = 1'sb0;
	// Trace: ips/prim_opentitan/prim_count.sv:83:3
	genvar _gv_k_1;
	generate
		for (_gv_k_1 = 0; _gv_k_1 < NumCnt; _gv_k_1 = _gv_k_1 + 1) begin : gen_cnts
			localparam k = _gv_k_1;
			// Trace: ips/prim_opentitan/prim_count.sv:85:5
			wire incr_en;
			wire decr_en;
			// Trace: ips/prim_opentitan/prim_count.sv:86:5
			wire [Width - 1:0] set_val;
			if (k == 0) begin : gen_up_cnt
				// Trace: ips/prim_opentitan/prim_count.sv:88:7
				assign incr_en = incr_en_i;
				// Trace: ips/prim_opentitan/prim_count.sv:89:7
				assign decr_en = decr_en_i;
				// Trace: ips/prim_opentitan/prim_count.sv:90:7
				assign set_val = set_cnt_i;
			end
			else begin : gen_dn_cnt
				// Trace: ips/prim_opentitan/prim_count.sv:92:7
				assign incr_en = decr_en_i;
				// Trace: ips/prim_opentitan/prim_count.sv:93:7
				assign decr_en = incr_en_i;
				// Trace: ips/prim_opentitan/prim_count.sv:95:7
				assign set_val = {Width {1'b1}} - set_cnt_i;
			end
			// Trace: ips/prim_opentitan/prim_count.sv:99:5
			wire [Width:0] ext_cnt;
			// Trace: ips/prim_opentitan/prim_count.sv:100:5
			assign ext_cnt = (decr_en ? {1'b0, cnt_q[k * Width+:Width]} - {1'b0, step_i} : (incr_en ? {1'b0, cnt_q[k * Width+:Width]} + {1'b0, step_i} : {1'b0, cnt_q[k * Width+:Width]}));
			// Trace: ips/prim_opentitan/prim_count.sv:104:5
			wire uflow;
			wire oflow;
			// Trace: ips/prim_opentitan/prim_count.sv:105:5
			assign oflow = incr_en && ext_cnt[Width];
			// Trace: ips/prim_opentitan/prim_count.sv:106:5
			assign uflow = decr_en && ext_cnt[Width];
			// Trace: ips/prim_opentitan/prim_count.sv:107:5
			wire [Width - 1:0] cnt_sat;
			// Trace: ips/prim_opentitan/prim_count.sv:108:5
			assign cnt_sat = (uflow ? {Width {1'sb0}} : (oflow ? {Width {1'b1}} : ext_cnt[Width - 1:0]));
			// Trace: ips/prim_opentitan/prim_count.sv:113:5
			wire cnt_en;
			// Trace: ips/prim_opentitan/prim_count.sv:114:5
			assign cnt_en = (incr_en ^ decr_en) && ((incr_en && !(&cnt_q[k * Width+:Width])) || (decr_en && (cnt_q[k * Width+:Width] != {Width * 1 {1'sb0}})));
			// Trace: ips/prim_opentitan/prim_count.sv:119:5
			assign cnt_d[k * Width+:Width] = (clr_i ? ResetValues[k * Width+:Width] : (set_i ? set_val : (cnt_en ? cnt_sat : cnt_q[k * Width+:Width])));
			// Trace: ips/prim_opentitan/prim_count.sv:123:5
			assign cnt_d_committed[k * Width+:Width] = (commit_i ? cnt_d[k * Width+:Width] : cnt_q[k * Width+:Width]);
			// Trace: ips/prim_opentitan/prim_count.sv:125:5
			wire [Width - 1:0] cnt_unforced_q;
			// Trace: ips/prim_opentitan/prim_count.sv:126:5
			prim_flop #(
				.Width(Width),
				.ResetValue(ResetValues[k * Width+:Width])
			) u_cnt_flop(
				.clk_i(clk_i),
				.rst_ni(rst_ni),
				.d_i(cnt_d_committed[k * Width+:Width]),
				.q_o(cnt_unforced_q)
			);
			// Trace: ips/prim_opentitan/prim_count.sv:137:5
			assign cnt_q[k * Width+:Width] = fpv_force[k * Width+:Width] + cnt_unforced_q;
		end
	endgenerate
	// Trace: ips/prim_opentitan/prim_count.sv:141:3
	wire [Width:0] sum;
	// Trace: ips/prim_opentitan/prim_count.sv:142:3
	assign sum = cnt_q[0+:Width] + cnt_q[Width+:Width];
	// Trace: ips/prim_opentitan/prim_count.sv:145:3
	wire err_d;
	reg err_q;
	// Trace: ips/prim_opentitan/prim_count.sv:146:3
	assign err_d = sum != {1'b0, {Width {1'b1}}};
	// Trace: ips/prim_opentitan/prim_count.sv:147:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: ips/prim_opentitan/prim_count.sv:148:5
		if (!rst_ni)
			// Trace: ips/prim_opentitan/prim_count.sv:149:7
			err_q <= 1'b0;
		else
			// Trace: ips/prim_opentitan/prim_count.sv:151:7
			err_q <= err_d;
	// Trace: ips/prim_opentitan/prim_count.sv:154:3
	assign err_o = err_q;
	// Trace: ips/prim_opentitan/prim_count.sv:157:3
	assign cnt_o = cnt_q[0+:Width];
	// Trace: ips/prim_opentitan/prim_count.sv:158:3
	assign cnt_after_commit_o = cnt_d[0+:Width];
	// Trace: ips/prim_opentitan/prim_count.sv:170:3
	wire fpv_err_present;
	// Trace: ips/prim_opentitan/prim_count.sv:171:3
	assign fpv_err_present = |fpv_force;
	// Trace: ips/prim_opentitan/prim_count.sv:174:3
	function automatic signed [Width + 1:0] max;
		// Trace: ips/prim_opentitan/prim_count.sv:174:51
		input reg signed [Width + 1:0] a;
		// Trace: ips/prim_opentitan/prim_count.sv:175:51
		input reg signed [Width + 1:0] b;
		// Trace: ips/prim_opentitan/prim_count.sv:176:5
		max = (a > b ? a : b);
	endfunction
	// Trace: ips/prim_opentitan/prim_count.sv:179:3
	function automatic signed [Width + 1:0] min;
		// Trace: ips/prim_opentitan/prim_count.sv:179:51
		input reg signed [Width + 1:0] a;
		// Trace: ips/prim_opentitan/prim_count.sv:180:51
		input reg signed [Width + 1:0] b;
		// Trace: ips/prim_opentitan/prim_count.sv:181:5
		min = (a < b ? a : b);
	endfunction
	// Trace: ips/prim_opentitan/prim_count.sv:186:3
	// removed localparam type _sv2v_keep_enum_for_params
	generate
		if (!(PossibleActions & 4'h1)) begin : g_check_no_clr
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:187:40
			// removed an assertion item
			// ClrNeverTrue_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
			// 	clr_i !== 1'b1
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:187:595
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 187, "ClrNeverTrue_A");
			// end
		end
	endgenerate
	// Trace: ips/prim_opentitan/prim_count.sv:189:3
	generate
		if (!(PossibleActions & 4'h2)) begin : g_check_no_set
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:190:40
			// removed an assertion item
			// SetNeverTrue_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
			// 	set_i !== 1'b1
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:190:595
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 190, "SetNeverTrue_A");
			// end
		end
	endgenerate
	// Trace: ips/prim_opentitan/prim_count.sv:192:3
	generate
		if (!(PossibleActions & 4'h4)) begin : g_check_no_incr
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:193:45
			// removed an assertion item
			// IncrNeverTrue_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
			// 	incr_en_i !== 1'b1
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:193:600
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 193, "IncrNeverTrue_A");
			// end
		end
	endgenerate
	// Trace: ips/prim_opentitan/prim_count.sv:195:3
	generate
		if (!(PossibleActions & 4'h8)) begin : g_check_no_decr
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:196:45
			// removed an assertion item
			// DecrNeverTrue_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
			// 	decr_en_i !== 1'b1
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:196:600
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 196, "DecrNeverTrue_A");
			// end
		end
	endgenerate
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:204:46
	// removed an assertion item
	// CntNext_A : assert property (@(posedge clk_i) disable iff (((err_d || fpv_err_present) || !rst_ni) !== '0)
	// 	(rst_ni |=> $past(!commit_i) || (cnt_o == $past(cnt_after_commit_o)))
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:204:601
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 204, "CntNext_A");
	// end
	// Trace: ips/prim_opentitan/prim_count.sv:207:3
	generate
		if (PossibleActions & 4'h1) begin : g_check_clr_fwd_a
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:213:52
			// removed an assertion item
			// ClrFwd_A : assert property (@(posedge clk_i) disable iff (((err_d || fpv_err_present) || !rst_ni) !== '0)
			// 	((rst_ni && commit_i) && clr_i |=> (cnt_o == ResetValue) && (cnt_q[1] == ({Width {1'b1}} - ResetValue)))
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:213:607
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 213, "ClrFwd_A");
			// end
		end
	endgenerate
	// Trace: ips/prim_opentitan/prim_count.sv:217:3
	generate
		if (PossibleActions & 4'h2) begin : g_check_set_fwd_a
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:223:48
			// removed an assertion item
			// SetFwd_A : assert property (@(posedge clk_i) disable iff (((err_d || fpv_err_present) || !rst_ni) !== '0)
			// 	(((rst_ni && commit_i) && set_i) && !clr_i |=> (cnt_o == $past(set_cnt_i)) && (cnt_q[1] == ({Width {1'b1}} - $past(set_cnt_i))))
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:223:603
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 223, "SetFwd_A");
			// end
		end
	endgenerate
	// Trace: ips/prim_opentitan/prim_count.sv:227:3
	generate
		if ((PossibleActions & 4'h4) && (PossibleActions & 4'h8)) begin : g_check_inc_and_dec
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:232:48
			// removed an assertion item
			// IncrDecrUpDnCnt_A : assert property (@(posedge clk_i) disable iff (((err_d || fpv_err_present) || !rst_ni) !== '0)
			// 	(((rst_ni && incr_en_i) && decr_en_i) && !(clr_i || set_i) |=> $stable(cnt_o) && $stable(cnt_q[1]))
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:232:603
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 232, "IncrDecrUpDnCnt_A");
			// end
		end
	endgenerate
	// Trace: ips/prim_opentitan/prim_count.sv:236:3
	generate
		if (PossibleActions & 4'h4) begin : g_check_incr
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:241:48
			// removed an assertion item
			// IncrUpCnt_A : assert property (@(posedge clk_i) disable iff (((err_d || fpv_err_present) || !rst_ni) !== '0)
			// 	(((rst_ni && incr_en_i) && !((clr_i || set_i) || decr_en_i)) && commit_i |=> cnt_o == min($past(cnt_o) + $past({2'b00, step_i}), {2'b00, {Width {1'b1}}}))
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:241:603
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 241, "IncrUpCnt_A");
			// end
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:246:48
			// removed an assertion item
			// IncrDnCnt_A : assert property (@(posedge clk_i) disable iff (((err_d || fpv_err_present) || !rst_ni) !== '0)
			// 	(((rst_ni && incr_en_i) && !((clr_i || set_i) || decr_en_i)) && commit_i |=> cnt_q[1] == max($past(signed'({2'b00, cnt_q[1]})) - $past({2'b00, step_i}), '0))
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:246:603
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 246, "IncrDnCnt_A");
			// end
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:252:48
			// removed an assertion item
			// UpCntIncrStable_A : assert property (@(posedge clk_i) disable iff (((err_d || fpv_err_present) || !rst_ni) !== '0)
			// 	((incr_en_i && !((clr_i || set_i) || decr_en_i)) && (cnt_o == {Width {1'b1}}) |=> $stable(cnt_o))
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:252:603
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 252, "UpCntIncrStable_A");
			// end
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:258:48
			// removed an assertion item
			// DnCntIncrStable_A : assert property (@(posedge clk_i) disable iff (((err_d || fpv_err_present) || !rst_ni) !== '0)
			// 	(((rst_ni && incr_en_i) && !((clr_i || set_i) || decr_en_i)) && (cnt_q[1] == '0) |=> $stable(cnt_q[1]))
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:258:603
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 258, "DnCntIncrStable_A");
			// end
		end
	endgenerate
	// Trace: ips/prim_opentitan/prim_count.sv:262:3
	generate
		if (PossibleActions & 4'h8) begin : g_check_decr
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:267:48
			// removed an assertion item
			// DecrUpCnt_A : assert property (@(posedge clk_i) disable iff (((err_d || fpv_err_present) || !rst_ni) !== '0)
			// 	(((rst_ni && decr_en_i) && !((clr_i || set_i) || incr_en_i)) && commit_i |=> cnt_o == max($past(signed'({2'b00, cnt_o})) - $past({2'b00, step_i}), '0))
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:267:603
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 267, "DecrUpCnt_A");
			// end
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:272:48
			// removed an assertion item
			// DecrDnCnt_A : assert property (@(posedge clk_i) disable iff (((err_d || fpv_err_present) || !rst_ni) !== '0)
			// 	(((rst_ni && decr_en_i) && !((clr_i || set_i) || incr_en_i)) && commit_i |=> cnt_q[1] == min($past(cnt_q[1]) + $past({2'b00, step_i}), {2'b00, {Width {1'b1}}}))
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:272:603
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 272, "DecrDnCnt_A");
			// end
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:278:48
			// removed an assertion item
			// UpCntDecrStable_A : assert property (@(posedge clk_i) disable iff (((err_d || fpv_err_present) || !rst_ni) !== '0)
			// 	((decr_en_i && !((clr_i || set_i) || incr_en_i)) && (cnt_o == '0) |=> $stable(cnt_o))
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:278:603
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 278, "UpCntDecrStable_A");
			// end
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:284:48
			// removed an assertion item
			// DnCntDecrStable_A : assert property (@(posedge clk_i) disable iff (((err_d || fpv_err_present) || !rst_ni) !== '0)
			// 	(((rst_ni && decr_en_i) && !((clr_i || set_i) || incr_en_i)) && (cnt_q[1] == {Width {1'b1}}) |=> $stable(cnt_q[1]))
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:284:603
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 284, "DnCntDecrStable_A");
			// end
		end
	endgenerate
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:293:50
	// removed an assertion item
	// ChangeBackward_A : assert property (@(posedge clk_i) disable iff (((err_d || fpv_err_present) || !rst_ni) !== '0)
	// 	(rst_ni ##(1) $changed(cnt_o) && $changed(cnt_q[1]) |-> $past((clr_i || set_i) || (commit_i && (incr_en_i || decr_en_i))))
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:293:605
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 293, "ChangeBackward_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_count.sv:300:84
	// removed an assertion item
	// CntErrReported_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	##(1) $past((cnt_q[1] + cnt_q[0]) != {Width {1'b1}}) == err_o
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_count.sv:300:639
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_count.sv", 300, "CntErrReported_A");
	// end
	// Trace: ips/prim_opentitan/prim_count.sv:308:3
	wire unused_assert_connected;
	// Trace: macro expansion of ASSERT_INIT_NET at ips/prim_opentitan/prim_count.sv:310:85
	initial begin
		// Trace: macro expansion of ASSERT_INIT_NET at ips/prim_opentitan/prim_count.sv:310:188
		#(1ps)
			;
		begin : AssertConnected_A
			
		end
	end
endmodule
module prim_fifo_async (
	clk_wr_i,
	rst_wr_ni,
	wvalid_i,
	wready_o,
	wdata_i,
	wdepth_o,
	clk_rd_i,
	rst_rd_ni,
	rvalid_o,
	rready_i,
	rdata_o,
	rdepth_o
);
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:10:14
	parameter [31:0] Width = 16;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:11:14
	parameter [31:0] Depth = 4;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:12:14
	parameter [0:0] OutputZeroIfEmpty = 1'b0;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:13:14
	parameter [0:0] OutputZeroIfInvalid = 1'b0;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:14:14
	localparam [31:0] DepthW = $clog2(Depth + 1);
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:17:3
	input wire clk_wr_i;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:18:3
	input wire rst_wr_ni;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:19:3
	input wire wvalid_i;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:20:3
	output wire wready_o;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:21:3
	input wire [Width - 1:0] wdata_i;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:22:3
	output wire [DepthW - 1:0] wdepth_o;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:25:3
	input wire clk_rd_i;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:26:3
	input wire rst_rd_ni;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:27:3
	output wire rvalid_o;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:28:3
	input wire rready_i;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:29:3
	output wire [Width - 1:0] rdata_o;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:30:3
	output wire [DepthW - 1:0] rdepth_o;
	// Trace: macro expansion of ASSERT_INIT at ips/prim_opentitan/prim_fifo_async.sv:34:398
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/prim_opentitan/prim_fifo_async.sv:34:486
		begin : ParamCheckDepth_A
			
		end
	end
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:36:3
	localparam [31:0] PTRV_W = (Depth == 1 ? 1 : $clog2(Depth));
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:37:3
	localparam [31:0] PTR_WIDTH = (Depth == 1 ? 1 : PTRV_W + 1);
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:39:3
	reg [PTR_WIDTH - 1:0] fifo_wptr_q;
	wire [PTR_WIDTH - 1:0] fifo_wptr_d;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:40:3
	reg [PTR_WIDTH - 1:0] fifo_rptr_q;
	wire [PTR_WIDTH - 1:0] fifo_rptr_d;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:41:3
	wire [PTR_WIDTH - 1:0] fifo_wptr_sync_combi;
	wire [PTR_WIDTH - 1:0] fifo_rptr_sync_combi;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:42:3
	wire [PTR_WIDTH - 1:0] fifo_wptr_gray_sync;
	wire [PTR_WIDTH - 1:0] fifo_rptr_gray_sync;
	reg [PTR_WIDTH - 1:0] fifo_rptr_sync_q;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:43:3
	reg [PTR_WIDTH - 1:0] fifo_wptr_gray_q;
	wire [PTR_WIDTH - 1:0] fifo_wptr_gray_d;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:44:3
	reg [PTR_WIDTH - 1:0] fifo_rptr_gray_q;
	wire [PTR_WIDTH - 1:0] fifo_rptr_gray_d;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:45:3
	wire fifo_incr_wptr;
	wire fifo_incr_rptr;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:46:3
	wire full_wclk;
	wire full_rclk;
	wire empty_rclk;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:47:3
	reg [Width - 1:0] storage [0:Depth - 1];
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:53:3
	assign fifo_incr_wptr = wvalid_i & wready_o;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:56:3
	function automatic [PTR_WIDTH - 1:0] sv2v_cast_62A53;
		input reg [PTR_WIDTH - 1:0] inp;
		sv2v_cast_62A53 = inp;
	endfunction
	assign fifo_wptr_d = fifo_wptr_q + sv2v_cast_62A53(1'b1);
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:58:3
	always @(posedge clk_wr_i or negedge rst_wr_ni)
		// Trace: ips/prim_opentitan/prim_fifo_async.sv:59:5
		if (!rst_wr_ni)
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:60:7
			fifo_wptr_q <= 1'sb0;
		else if (fifo_incr_wptr)
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:62:7
			fifo_wptr_q <= fifo_wptr_d;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:67:3
	always @(posedge clk_wr_i or negedge rst_wr_ni)
		// Trace: ips/prim_opentitan/prim_fifo_async.sv:68:5
		if (!rst_wr_ni)
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:69:7
			fifo_wptr_gray_q <= 1'sb0;
		else if (fifo_incr_wptr)
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:71:7
			fifo_wptr_gray_q <= fifo_wptr_gray_d;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:76:3
	prim_flop_2sync #(.Width(PTR_WIDTH)) sync_wptr(
		.clk_i(clk_rd_i),
		.rst_ni(rst_rd_ni),
		.d_i(fifo_wptr_gray_q),
		.q_o(fifo_wptr_gray_sync)
	);
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:86:3
	assign fifo_incr_rptr = rvalid_o & rready_i;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:89:3
	assign fifo_rptr_d = fifo_rptr_q + sv2v_cast_62A53(1'b1);
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:91:3
	always @(posedge clk_rd_i or negedge rst_rd_ni)
		// Trace: ips/prim_opentitan/prim_fifo_async.sv:92:5
		if (!rst_rd_ni)
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:93:7
			fifo_rptr_q <= 1'sb0;
		else if (fifo_incr_rptr)
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:95:7
			fifo_rptr_q <= fifo_rptr_d;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:100:3
	always @(posedge clk_rd_i or negedge rst_rd_ni)
		// Trace: ips/prim_opentitan/prim_fifo_async.sv:101:5
		if (!rst_rd_ni)
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:102:7
			fifo_rptr_gray_q <= 1'sb0;
		else if (fifo_incr_rptr)
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:104:7
			fifo_rptr_gray_q <= fifo_rptr_gray_d;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:109:3
	prim_flop_2sync #(.Width(PTR_WIDTH)) sync_rptr(
		.clk_i(clk_wr_i),
		.rst_ni(rst_wr_ni),
		.d_i(fifo_rptr_gray_q),
		.q_o(fifo_rptr_gray_sync)
	);
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:116:3
	always @(posedge clk_wr_i or negedge rst_wr_ni)
		// Trace: ips/prim_opentitan/prim_fifo_async.sv:117:5
		if (!rst_wr_ni)
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:118:7
			fifo_rptr_sync_q <= 1'sb0;
		else
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:120:7
			fifo_rptr_sync_q <= fifo_rptr_sync_combi;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:128:3
	wire [PTR_WIDTH - 1:0] xor_mask;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:129:3
	assign xor_mask = sv2v_cast_62A53(1'b1) << (PTR_WIDTH - 1);
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:130:3
	assign full_wclk = fifo_wptr_q == (fifo_rptr_sync_q ^ xor_mask);
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:131:3
	assign full_rclk = fifo_wptr_sync_combi == (fifo_rptr_q ^ xor_mask);
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:132:3
	assign empty_rclk = fifo_wptr_sync_combi == fifo_rptr_q;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:134:3
	function automatic [DepthW - 1:0] sv2v_cast_2DA09;
		input reg [DepthW - 1:0] inp;
		sv2v_cast_2DA09 = inp;
	endfunction
	generate
		if (Depth > 1) begin : g_depth_calc
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:137:5
			wire wptr_msb;
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:138:5
			wire rptr_sync_msb;
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:139:5
			wire [PTRV_W - 1:0] wptr_value;
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:140:5
			wire [PTRV_W - 1:0] rptr_sync_value;
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:142:5
			assign wptr_msb = fifo_wptr_q[PTR_WIDTH - 1];
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:143:5
			assign rptr_sync_msb = fifo_rptr_sync_q[PTR_WIDTH - 1];
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:144:5
			assign wptr_value = fifo_wptr_q[0+:PTRV_W];
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:145:5
			assign rptr_sync_value = fifo_rptr_sync_q[0+:PTRV_W];
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:146:5
			assign wdepth_o = (full_wclk ? sv2v_cast_2DA09(Depth) : (wptr_msb == rptr_sync_msb ? sv2v_cast_2DA09(wptr_value) - sv2v_cast_2DA09(rptr_sync_value) : (sv2v_cast_2DA09(Depth) - sv2v_cast_2DA09(rptr_sync_value)) + sv2v_cast_2DA09(wptr_value)));
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:151:5
			wire rptr_msb;
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:152:5
			wire wptr_sync_msb;
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:153:5
			wire [PTRV_W - 1:0] rptr_value;
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:154:5
			wire [PTRV_W - 1:0] wptr_sync_value;
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:156:5
			assign wptr_sync_msb = fifo_wptr_sync_combi[PTR_WIDTH - 1];
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:157:5
			assign rptr_msb = fifo_rptr_q[PTR_WIDTH - 1];
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:158:5
			assign wptr_sync_value = fifo_wptr_sync_combi[0+:PTRV_W];
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:159:5
			assign rptr_value = fifo_rptr_q[0+:PTRV_W];
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:160:5
			assign rdepth_o = (full_rclk ? sv2v_cast_2DA09(Depth) : (wptr_sync_msb == rptr_msb ? sv2v_cast_2DA09(wptr_sync_value) - sv2v_cast_2DA09(rptr_value) : (sv2v_cast_2DA09(Depth) - sv2v_cast_2DA09(rptr_value)) + sv2v_cast_2DA09(wptr_sync_value)));
		end
		else begin : g_no_depth_calc
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:166:5
			assign rdepth_o = full_rclk;
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:167:5
			assign wdepth_o = full_wclk;
		end
	endgenerate
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:171:3
	assign wready_o = ~full_wclk;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:172:3
	assign rvalid_o = ~empty_rclk;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:178:3
	wire [Width - 1:0] rdata_int;
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:179:3
	generate
		if (Depth > 1) begin : g_storage_mux
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:181:5
			always @(posedge clk_wr_i)
				// Trace: ips/prim_opentitan/prim_fifo_async.sv:182:7
				if (fifo_incr_wptr)
					// Trace: ips/prim_opentitan/prim_fifo_async.sv:183:9
					storage[fifo_wptr_q[PTRV_W - 1:0]] <= wdata_i;
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:187:5
			assign rdata_int = storage[fifo_rptr_q[PTRV_W - 1:0]];
		end
		else begin : g_storage_simple
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:191:5
			always @(posedge clk_wr_i)
				// Trace: ips/prim_opentitan/prim_fifo_async.sv:192:7
				if (fifo_incr_wptr)
					// Trace: ips/prim_opentitan/prim_fifo_async.sv:193:9
					storage[0] <= wdata_i;
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:197:5
			assign rdata_int = storage[0];
		end
	endgenerate
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:202:3
	generate
		if (OutputZeroIfEmpty == 1'b1) begin : gen_output_zero
			if (OutputZeroIfInvalid == 1'b1) begin : gen_invalid_zero
				// Trace: ips/prim_opentitan/prim_fifo_async.sv:204:7
				assign rdata_o = (empty_rclk ? {Width {1'sb0}} : (rvalid_o ? rdata_int : {Width {1'sb0}}));
			end
			else begin : gen_invalid_non_zero
				// Trace: ips/prim_opentitan/prim_fifo_async.sv:207:7
				assign rdata_o = (empty_rclk ? {Width {1'sb0}} : rdata_int);
			end
		end
		else begin : gen_no_output_zero
			if (OutputZeroIfInvalid == 1'b1) begin : gen_invalid_zero
				// Trace: ips/prim_opentitan/prim_fifo_async.sv:211:9
				assign rdata_o = (rvalid_o ? rdata_int : {Width {1'sb0}});
			end
			else begin : gen_invalid_non_zero
				// Trace: ips/prim_opentitan/prim_fifo_async.sv:214:9
				assign rdata_o = rdata_int;
			end
		end
	endgenerate
	// Trace: ips/prim_opentitan/prim_fifo_async.sv:223:3
	generate
		if (Depth > 2) begin : g_full_gray_conversion
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:225:5
			function automatic [PTR_WIDTH - 1:0] dec2gray;
				// Trace: ips/prim_opentitan/prim_fifo_async.sv:225:49
				input reg [PTR_WIDTH - 1:0] decval;
				// Trace: ips/prim_opentitan/prim_fifo_async.sv:226:7
				reg [PTR_WIDTH - 1:0] decval_sub;
				// Trace: ips/prim_opentitan/prim_fifo_async.sv:227:7
				reg [PTR_WIDTH - 1:0] decval_in;
				// Trace: ips/prim_opentitan/prim_fifo_async.sv:228:7
				reg unused_decval_msb;
				begin
					// Trace: ips/prim_opentitan/prim_fifo_async.sv:230:7
					decval_sub = (sv2v_cast_62A53(Depth) - {1'b0, decval[PTR_WIDTH - 2:0]}) - 1'b1;
					// Trace: ips/prim_opentitan/prim_fifo_async.sv:232:7
					decval_in = (decval[PTR_WIDTH - 1] ? decval_sub : decval);
					// Trace: ips/prim_opentitan/prim_fifo_async.sv:235:7
					unused_decval_msb = decval_in[PTR_WIDTH - 1];
					// Trace: ips/prim_opentitan/prim_fifo_async.sv:236:7
					decval_in[PTR_WIDTH - 1] = 1'b0;
					// Trace: ips/prim_opentitan/prim_fifo_async.sv:239:7
					dec2gray = decval_in;
					// Trace: ips/prim_opentitan/prim_fifo_async.sv:240:7
					dec2gray = dec2gray ^ (decval_in >> 1);
					// Trace: ips/prim_opentitan/prim_fifo_async.sv:243:7
					dec2gray[PTR_WIDTH - 1] = decval[PTR_WIDTH - 1];
				end
			endfunction
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:247:5
			function automatic [PTR_WIDTH - 1:0] gray2dec;
				// Trace: ips/prim_opentitan/prim_fifo_async.sv:247:49
				input reg [PTR_WIDTH - 1:0] grayval;
				// Trace: ips/prim_opentitan/prim_fifo_async.sv:248:7
				reg [PTR_WIDTH - 1:0] dec_tmp;
				reg [PTR_WIDTH - 1:0] dec_tmp_sub;
				// Trace: ips/prim_opentitan/prim_fifo_async.sv:249:7
				reg unused_decsub_msb;
				begin
					// Trace: ips/prim_opentitan/prim_fifo_async.sv:251:7
					dec_tmp = 1'sb0;
					// Trace: ips/prim_opentitan/prim_fifo_async.sv:252:7
					begin : sv2v_autoblock_1
						// Trace: ips/prim_opentitan/prim_fifo_async.sv:252:12
						reg signed [31:0] i;
						// Trace: ips/prim_opentitan/prim_fifo_async.sv:252:12
						for (i = PTR_WIDTH - 2; i >= 0; i = i - 1)
							begin
								// Trace: ips/prim_opentitan/prim_fifo_async.sv:253:9
								dec_tmp[i] = dec_tmp[i + 1] ^ grayval[i];
							end
					end
					// Trace: ips/prim_opentitan/prim_fifo_async.sv:255:7
					dec_tmp_sub = (sv2v_cast_62A53(Depth) - dec_tmp) - 1'b1;
					if (grayval[PTR_WIDTH - 1]) begin
						// Trace: ips/prim_opentitan/prim_fifo_async.sv:257:9
						gray2dec = dec_tmp_sub;
						// Trace: ips/prim_opentitan/prim_fifo_async.sv:259:9
						gray2dec[PTR_WIDTH - 1] = 1'b1;
						// Trace: ips/prim_opentitan/prim_fifo_async.sv:260:9
						unused_decsub_msb = dec_tmp_sub[PTR_WIDTH - 1];
					end
					else
						// Trace: ips/prim_opentitan/prim_fifo_async.sv:262:9
						gray2dec = dec_tmp;
				end
			endfunction
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:267:5
			assign fifo_rptr_sync_combi = gray2dec(fifo_rptr_gray_sync);
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:269:5
			assign fifo_wptr_sync_combi = gray2dec(fifo_wptr_gray_sync);
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:271:5
			assign fifo_rptr_gray_d = dec2gray(fifo_rptr_d);
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:272:5
			assign fifo_wptr_gray_d = dec2gray(fifo_wptr_d);
		end
		else if (Depth == 2) begin : g_simple_gray_conversion
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:276:5
			assign fifo_rptr_sync_combi = {fifo_rptr_gray_sync[PTR_WIDTH - 1], ^fifo_rptr_gray_sync};
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:277:5
			assign fifo_wptr_sync_combi = {fifo_wptr_gray_sync[PTR_WIDTH - 1], ^fifo_wptr_gray_sync};
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:279:5
			assign fifo_rptr_gray_d = {fifo_rptr_d[PTR_WIDTH - 1], ^fifo_rptr_d};
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:280:5
			assign fifo_wptr_gray_d = {fifo_wptr_d[PTR_WIDTH - 1], ^fifo_wptr_d};
		end
		else begin : g_no_gray_conversion
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:284:5
			assign fifo_rptr_sync_combi = fifo_rptr_gray_sync;
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:285:5
			assign fifo_wptr_sync_combi = fifo_wptr_gray_sync;
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:287:5
			assign fifo_rptr_gray_d = fifo_rptr_d;
			// Trace: ips/prim_opentitan/prim_fifo_async.sv:288:5
			assign fifo_wptr_gray_d = fifo_wptr_d;
		end
	endgenerate
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_fifo_async.sv:294:28
	// removed an assertion item
	// GrayWptr_A : assert property (@(posedge clk_wr_i) disable iff (!rst_wr_ni !== '0)
	// 	##(1) $countones(fifo_wptr_gray_q ^ $past(fifo_wptr_gray_q)) <= 1
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_async.sv:294:583
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_async.sv", 294, "GrayWptr_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_fifo_async.sv:296:28
	// removed an assertion item
	// GrayRptr_A : assert property (@(posedge clk_rd_i) disable iff (!rst_rd_ni !== '0)
	// 	##(1) $countones(fifo_rptr_gray_q ^ $past(fifo_rptr_gray_q)) <= 1
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_async.sv:296:583
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_async.sv", 296, "GrayRptr_A");
	// end
endmodule
module prim_fifo_async_simple (
	clk_wr_i,
	rst_wr_ni,
	wvalid_i,
	wready_o,
	wdata_i,
	clk_rd_i,
	rst_rd_ni,
	rvalid_o,
	rready_i,
	rdata_o
);
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:9:13
	parameter [31:0] Width = 16;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:10:13
	parameter [0:0] EnRstChks = 1'b0;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:12:13
	parameter [0:0] EnRzHs = 1'b0;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:17:3
	input wire clk_wr_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:18:3
	input wire rst_wr_ni;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:19:3
	input wire wvalid_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:20:3
	output wire wready_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:21:3
	input wire [Width - 1:0] wdata_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:24:3
	input wire clk_rd_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:25:3
	input wire rst_rd_ni;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:26:3
	output wire rvalid_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:27:3
	input wire rready_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:28:3
	output wire [Width - 1:0] rdata_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:36:3
	wire wr_en;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:37:3
	wire src_req;
	wire src_ack;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:38:3
	wire pending_d;
	reg pending_q;
	reg not_in_reset_q;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:39:3
	assign wready_o = !pending_q && not_in_reset_q;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:40:3
	assign wr_en = wvalid_i && wready_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:41:3
	assign src_req = pending_q || wvalid_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:43:3
	assign pending_d = (src_ack ? 1'b0 : (wr_en ? 1'b1 : pending_q));
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:46:3
	wire dst_req;
	wire dst_ack;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:47:3
	assign rvalid_o = dst_req;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:48:3
	assign dst_ack = dst_req && rready_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:50:3
	always @(posedge clk_wr_i or negedge rst_wr_ni)
		// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:51:5
		if (!rst_wr_ni) begin
			// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:52:7
			pending_q <= 1'b0;
			// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:53:7
			not_in_reset_q <= 1'b0;
		end
		else begin
			// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:55:7
			pending_q <= pending_d;
			// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:56:7
			not_in_reset_q <= 1'b1;
		end
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:64:3
	prim_sync_reqack #(
		.EnRstChks(EnRstChks),
		.EnRzHs(EnRzHs)
	) u_prim_sync_reqack(
		.clk_src_i(clk_wr_i),
		.rst_src_ni(rst_wr_ni),
		.clk_dst_i(clk_rd_i),
		.rst_dst_ni(rst_rd_ni),
		.req_chk_i(1'b0),
		.src_req_i(src_req),
		.src_ack_o(src_ack),
		.dst_req_o(dst_req),
		.dst_ack_i(dst_ack)
	);
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:83:3
	reg [Width - 1:0] data_q;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:84:3
	always @(posedge clk_wr_i)
		// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:85:5
		if (wr_en)
			// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:86:7
			data_q <= wdata_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_simple.sv:89:3
	assign rdata_o = data_q;
endmodule
module prim_fifo_async_sram_adapter (
	clk_wr_i,
	rst_wr_ni,
	wvalid_i,
	wready_o,
	wdata_i,
	wdepth_o,
	clk_rd_i,
	rst_rd_ni,
	rvalid_o,
	rready_i,
	rdata_o,
	rdepth_o,
	r_full_o,
	r_notempty_o,
	w_full_o,
	w_sram_req_o,
	w_sram_gnt_i,
	w_sram_write_o,
	w_sram_addr_o,
	w_sram_wdata_o,
	w_sram_wmask_o,
	w_sram_rvalid_i,
	w_sram_rdata_i,
	w_sram_rerror_i,
	r_sram_req_o,
	r_sram_gnt_i,
	r_sram_write_o,
	r_sram_addr_o,
	r_sram_wdata_o,
	r_sram_wmask_o,
	r_sram_rvalid_i,
	r_sram_rdata_i,
	r_sram_rerror_i
);
	reg _sv2v_0;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:10:13
	parameter [31:0] Width = 32;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:11:13
	parameter [31:0] Depth = 16;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:14:13
	parameter [31:0] SramAw = 16;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:17:13
	parameter [31:0] SramDw = 32;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:18:13
	parameter [SramAw - 1:0] SramBaseAddr = 'h0;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:21:14
	localparam [31:0] DepthW = $clog2(Depth + 1);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:24:3
	input clk_wr_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:25:3
	input rst_wr_ni;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:26:3
	input wvalid_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:27:3
	output wire wready_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:28:3
	input [Width - 1:0] wdata_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:29:3
	output wire [DepthW - 1:0] wdepth_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:32:3
	input clk_rd_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:33:3
	input rst_rd_ni;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:34:3
	output wire rvalid_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:35:3
	input rready_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:36:3
	output wire [Width - 1:0] rdata_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:37:3
	output wire [DepthW - 1:0] rdepth_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:39:3
	output wire r_full_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:40:3
	output wire r_notempty_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:42:3
	output wire w_full_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:48:3
	output wire w_sram_req_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:49:3
	input w_sram_gnt_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:50:3
	output wire w_sram_write_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:51:3
	output wire [SramAw - 1:0] w_sram_addr_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:52:3
	output wire [SramDw - 1:0] w_sram_wdata_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:53:3
	output wire [SramDw - 1:0] w_sram_wmask_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:54:3
	input w_sram_rvalid_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:55:3
	input [SramDw - 1:0] w_sram_rdata_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:56:3
	input [1:0] w_sram_rerror_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:59:3
	output reg r_sram_req_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:60:3
	input r_sram_gnt_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:61:3
	output wire r_sram_write_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:62:3
	output wire [SramAw - 1:0] r_sram_addr_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:63:3
	output wire [SramDw - 1:0] r_sram_wdata_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:64:3
	output wire [SramDw - 1:0] r_sram_wmask_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:65:3
	input r_sram_rvalid_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:66:3
	input [SramDw - 1:0] r_sram_rdata_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:67:3
	input [1:0] r_sram_rerror_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:77:3
	localparam [31:0] PtrVW = $clog2(Depth);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:79:3
	localparam [31:0] PtrW = PtrVW + 1;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:85:3
	reg [PtrW - 1:0] w_wptr_q;
	wire [PtrW - 1:0] w_wptr_d;
	wire [PtrW - 1:0] w_wptr_gray_d;
	reg [PtrW - 1:0] w_wptr_gray_q;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:86:3
	wire [PtrW - 1:0] r_wptr_gray;
	wire [PtrW - 1:0] r_wptr;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:87:3
	wire [PtrVW - 1:0] w_wptr_v;
	wire [PtrVW - 1:0] r_wptr_v;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:88:3
	wire w_wptr_p;
	wire r_wptr_p;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:90:3
	reg [PtrW - 1:0] r_rptr_q;
	wire [PtrW - 1:0] r_rptr_d;
	wire [PtrW - 1:0] r_rptr_gray_d;
	reg [PtrW - 1:0] r_rptr_gray_q;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:91:3
	wire [PtrW - 1:0] w_rptr_gray;
	wire [PtrW - 1:0] w_rptr;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:92:3
	wire [PtrVW - 1:0] r_rptr_v;
	wire [PtrVW - 1:0] w_rptr_v;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:93:3
	wire r_rptr_p;
	wire w_rptr_p;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:95:3
	wire w_wptr_inc;
	wire r_rptr_inc;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:97:3
	wire w_full;
	wire r_full;
	wire r_empty;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:101:3
	reg stored;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:102:3
	reg [Width - 1:0] rdata_q;
	wire [Width - 1:0] rdata_d;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:106:3
	wire r_sram_rptr_inc;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:107:3
	reg [PtrW - 1:0] r_sram_rptr;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:111:3
	wire r_sramrptr_empty;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:113:3
	wire rfifo_ack;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:114:3
	wire rsram_ack;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:121:3
	assign w_wptr_inc = wvalid_i & wready_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:123:3
	function automatic signed [PtrW - 1:0] sv2v_cast_09B00_signed;
		input reg signed [PtrW - 1:0] inp;
		sv2v_cast_09B00_signed = inp;
	endfunction
	assign w_wptr_d = w_wptr_q + sv2v_cast_09B00_signed(1);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:125:3
	always @(posedge clk_wr_i or negedge rst_wr_ni)
		// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:126:5
		if (!rst_wr_ni) begin
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:127:7
			w_wptr_q <= sv2v_cast_09B00_signed(0);
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:128:7
			w_wptr_gray_q <= sv2v_cast_09B00_signed(0);
		end
		else if (w_wptr_inc) begin
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:130:7
			w_wptr_q <= w_wptr_d;
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:131:7
			w_wptr_gray_q <= w_wptr_gray_d;
		end
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:135:3
	assign w_wptr_v = w_wptr_q[0+:PtrVW];
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:136:3
	assign w_wptr_p = w_wptr_q[PtrW - 1];
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:138:3
	function automatic [PtrW - 1:0] sv2v_cast_09B00;
		input reg [PtrW - 1:0] inp;
		sv2v_cast_09B00 = inp;
	endfunction
	function automatic [PtrW - 1:0] dec2gray;
		// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:342:42
		input reg [PtrW - 1:0] decval;
		// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:343:5
		reg [PtrW - 1:0] decval_sub;
		// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:344:5
		reg [PtrW - 1:0] decval_in;
		// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:345:5
		reg unused_decval_msb;
		begin
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:347:5
			decval_sub = (sv2v_cast_09B00(Depth) - {1'b0, decval[PtrW - 2:0]}) - 1'b1;
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:349:5
			decval_in = (decval[PtrW - 1] ? decval_sub : decval);
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:352:5
			unused_decval_msb = decval_in[PtrW - 1];
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:353:5
			decval_in[PtrW - 1] = 1'b0;
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:356:5
			dec2gray = decval_in;
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:357:5
			dec2gray = dec2gray ^ (decval_in >> 1);
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:360:5
			dec2gray[PtrW - 1] = decval[PtrW - 1];
		end
	endfunction
	assign w_wptr_gray_d = dec2gray(w_wptr_d);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:140:3
	prim_flop_2sync #(.Width(PtrW)) u_sync_wptr_gray(
		.clk_i(clk_rd_i),
		.rst_ni(rst_rd_ni),
		.d_i(w_wptr_gray_q),
		.q_o(r_wptr_gray)
	);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:149:3
	function automatic [PtrW - 1:0] gray2dec;
		// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:364:42
		input reg [PtrW - 1:0] grayval;
		// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:365:5
		reg [PtrW - 1:0] dec_tmp;
		reg [PtrW - 1:0] dec_tmp_sub;
		// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:366:5
		reg unused_decsub_msb;
		begin
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:368:5
			dec_tmp = 1'sb0;
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:369:5
			begin : sv2v_autoblock_1
				// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:369:10
				reg signed [31:0] i;
				// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:369:10
				for (i = PtrW - 2; i >= 0; i = i - 1)
					begin
						// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:370:7
						dec_tmp[i] = dec_tmp[i + 1] ^ grayval[i];
					end
			end
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:372:5
			dec_tmp_sub = (sv2v_cast_09B00(Depth) - dec_tmp) - 1'b1;
			if (grayval[PtrW - 1]) begin
				// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:374:7
				gray2dec = dec_tmp_sub;
				// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:376:7
				gray2dec[PtrW - 1] = 1'b1;
				// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:377:7
				unused_decsub_msb = dec_tmp_sub[PtrW - 1];
			end
			else
				// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:379:7
				gray2dec = dec_tmp;
		end
	endfunction
	assign r_wptr = gray2dec(r_wptr_gray);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:150:3
	assign r_wptr_p = r_wptr[PtrW - 1];
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:151:3
	assign r_wptr_v = r_wptr[0+:PtrVW];
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:153:3
	function automatic [DepthW - 1:0] sv2v_cast_2DA09;
		input reg [DepthW - 1:0] inp;
		sv2v_cast_2DA09 = inp;
	endfunction
	assign wdepth_o = (w_wptr_p == w_rptr_p ? sv2v_cast_2DA09(w_wptr_v - w_rptr_v) : sv2v_cast_2DA09({1'b1, w_wptr_v} - {1'b0, w_rptr_v}));
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:163:3
	assign r_rptr_inc = rfifo_ack;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:165:3
	assign r_rptr_d = r_rptr_q + sv2v_cast_09B00_signed(1);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:167:3
	always @(posedge clk_rd_i or negedge rst_rd_ni)
		// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:168:5
		if (!rst_rd_ni) begin
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:169:7
			r_rptr_q <= sv2v_cast_09B00_signed(0);
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:170:7
			r_rptr_gray_q <= sv2v_cast_09B00_signed(0);
		end
		else if (r_rptr_inc) begin
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:172:7
			r_rptr_q <= r_rptr_d;
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:173:7
			r_rptr_gray_q <= r_rptr_gray_d;
		end
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:177:3
	assign r_rptr_v = r_rptr_q[0+:PtrVW];
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:178:3
	assign r_rptr_p = r_rptr_q[PtrW - 1];
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:180:3
	assign r_rptr_gray_d = dec2gray(r_rptr_d);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:182:3
	prim_flop_2sync #(.Width(PtrW)) u_sync_rptr_gray(
		.clk_i(clk_wr_i),
		.rst_ni(rst_wr_ni),
		.d_i(r_rptr_gray_q),
		.q_o(w_rptr_gray)
	);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:191:3
	assign w_rptr = gray2dec(w_rptr_gray);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:192:3
	assign w_rptr_p = w_rptr[PtrW - 1];
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:193:3
	assign w_rptr_v = w_rptr[0+:PtrVW];
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:195:3
	assign rdepth_o = (r_wptr_p == r_rptr_p ? sv2v_cast_2DA09(r_wptr_v - r_rptr_v) : sv2v_cast_2DA09({1'b1, r_wptr_v} - {1'b0, r_rptr_v}));
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:201:3
	assign r_sram_rptr_inc = rsram_ack;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:203:3
	always @(posedge clk_rd_i or negedge rst_rd_ni)
		// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:204:5
		if (!rst_rd_ni)
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:205:7
			r_sram_rptr <= sv2v_cast_09B00_signed(0);
		else if (r_sram_rptr_inc)
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:207:7
			r_sram_rptr <= r_sram_rptr + sv2v_cast_09B00_signed(1);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:211:3
	assign r_sramrptr_empty = r_wptr == r_sram_rptr;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:216:3
	localparam [PtrW - 1:0] XorMask = {1'b1, {PtrW - 1 {1'b0}}};
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:217:3
	assign w_full = w_wptr_q == (w_rptr ^ XorMask);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:218:3
	assign r_full = r_wptr == (r_rptr_q ^ XorMask);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:219:3
	assign r_empty = r_wptr == r_rptr_q;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:221:3
	wire unused_r_empty;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:222:3
	assign unused_r_empty = r_empty;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:224:3
	assign r_full_o = r_full;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:225:3
	assign w_full_o = w_full;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:245:3
	assign r_notempty_o = rvalid_o;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:247:3
	assign rsram_ack = r_sram_req_o && r_sram_gnt_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:248:3
	assign rfifo_ack = rvalid_o && rready_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:251:3
	assign w_sram_req_o = wvalid_i && !w_full;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:252:3
	assign wready_o = !w_full && w_sram_gnt_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:253:3
	assign w_sram_write_o = 1'b1;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:254:3
	function automatic [SramAw - 1:0] sv2v_cast_55648;
		input reg [SramAw - 1:0] inp;
		sv2v_cast_55648 = inp;
	endfunction
	assign w_sram_addr_o = SramBaseAddr + sv2v_cast_55648(w_wptr_v);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:256:3
	function automatic [SramDw - 1:0] sv2v_cast_A12ED;
		input reg [SramDw - 1:0] inp;
		sv2v_cast_A12ED = inp;
	endfunction
	assign w_sram_wdata_o = sv2v_cast_A12ED(wdata_i);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:257:3
	assign w_sram_wmask_o = sv2v_cast_A12ED({Width {1'b1}});
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:259:3
	wire unused_w_sram;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:260:3
	assign unused_w_sram = ^{w_sram_rvalid_i, w_sram_rdata_i, w_sram_rerror_i};
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:269:3
	always @(*) begin : r_sram_req
		if (_sv2v_0)
			;
		// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:270:5
		r_sram_req_o = 1'b0;
		// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:279:5
		if (stored)
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:282:7
			r_sram_req_o = !r_sramrptr_empty && rfifo_ack;
		else
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:287:7
			r_sram_req_o = !r_sramrptr_empty && !(r_sram_rvalid_i ^ rfifo_ack);
	end
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:291:3
	assign rvalid_o = stored || r_sram_rvalid_i;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:292:3
	assign r_sram_write_o = 1'b0;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:293:3
	assign r_sram_wdata_o = 1'sb0;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:294:3
	assign r_sram_wmask_o = 1'sb0;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:297:3
	assign r_sram_addr_o = SramBaseAddr + sv2v_cast_55648(r_sram_rptr[0+:PtrVW]);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:299:3
	function automatic signed [Width - 1:0] sv2v_cast_62596_signed;
		input reg signed [Width - 1:0] inp;
		sv2v_cast_62596_signed = inp;
	endfunction
	assign rdata_d = (r_sram_rvalid_i ? r_sram_rdata_i[0+:Width] : sv2v_cast_62596_signed(0));
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:301:3
	assign rdata_o = (stored ? rdata_q : rdata_d);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:303:3
	wire unused_rsram;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:304:3
	assign unused_rsram = ^{r_sram_rerror_i};
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:306:3
	generate
		if (Width < SramDw) begin : g_unused_rdata
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:307:5
			wire unused_rdata;
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:308:5
			assign unused_rdata = ^r_sram_rdata_i[SramDw - 1:Width];
		end
	endgenerate
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:312:3
	wire store_en;
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:321:3
	assign store_en = r_sram_rvalid_i && !(stored ^ rfifo_ack);
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:323:3
	always @(posedge clk_rd_i or negedge rst_rd_ni)
		// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:324:5
		if (!rst_rd_ni) begin
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:325:7
			stored <= 1'b0;
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:326:7
			rdata_q <= sv2v_cast_62596_signed(0);
		end
		else if (store_en) begin
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:328:7
			stored <= 1'b1;
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:329:7
			rdata_q <= rdata_d;
		end
		else if (!r_sram_rvalid_i && rfifo_ack) begin
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:332:7
			stored <= 1'b0;
			// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:333:7
			rdata_q <= sv2v_cast_62596_signed(0);
		end
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:342:3
	// Trace: ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:364:3
	// Trace: macro expansion of ASSERT_INIT at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:387:398
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:387:486
		begin : ParamCheckDepth_A
			
		end
	end
	// Trace: macro expansion of ASSERT_INIT at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:390:374
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:390:462
		begin : MinDepth_A
			
		end
	end
	// Trace: macro expansion of ASSERT_INIT at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:393:381
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:393:469
		begin : WidthMatch_A
			
		end
	end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:398:28
	// removed an assertion item
	// RptrIncDataValid_A : assert property (@(posedge clk_rd_i) disable iff (!rst_rd_ni !== '0)
	// 	(r_rptr_inc |-> stored || r_sram_rvalid_i)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:398:583
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_async_sram_adapter.sv", 398, "RptrIncDataValid_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:401:28
	// removed an assertion item
	// SramRvalid_A : assert property (@(posedge clk_rd_i) disable iff (!rst_rd_ni !== '0)
	// 	(r_sram_rvalid_i |-> !stored || r_rptr_inc)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:401:583
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_async_sram_adapter.sv", 401, "SramRvalid_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:405:28
	// removed an assertion item
	// NoWAckInFull_A : assert property (@(posedge clk_wr_i) disable iff (!rst_wr_ni !== '0)
	// 	(w_wptr_inc |-> !w_full)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:405:583
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_async_sram_adapter.sv", 405, "NoWAckInFull_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:409:28
	// removed an assertion item
	// WptrIncrease_A : assert property (@(posedge clk_wr_i) disable iff (!rst_wr_ni !== '0)
	// 	(w_wptr_inc |=> w_wptr_v == PtrVW'($past(w_wptr_v, 2) + 1))
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:409:583
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_async_sram_adapter.sv", 409, "WptrIncrease_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:412:28
	// removed an assertion item
	// WptrGrayOneBitAtATime_A : assert property (@(posedge clk_wr_i) disable iff (!rst_wr_ni !== '0)
	// 	(w_wptr_inc |=> $countones(w_wptr_gray_q ^ $past(w_wptr_gray_q, 2)) == 1)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:412:583
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_async_sram_adapter.sv", 412, "WptrGrayOneBitAtATime_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:415:28
	// removed an assertion item
	// NoRAckInEmpty_A : assert property (@(posedge clk_rd_i) disable iff (!rst_rd_ni !== '0)
	// 	(r_rptr_inc |-> !r_empty)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:415:583
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_async_sram_adapter.sv", 415, "NoRAckInEmpty_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:419:28
	// removed an assertion item
	// RptrIncrease_A : assert property (@(posedge clk_rd_i) disable iff (!rst_rd_ni !== '0)
	// 	(r_rptr_inc |=> PtrVW'($past(r_rptr_v) + 1) == r_rptr_v)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:419:583
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_async_sram_adapter.sv", 419, "RptrIncrease_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:422:28
	// removed an assertion item
	// RptrGrayOneBitAtATime_A : assert property (@(posedge clk_rd_i) disable iff (!rst_rd_ni !== '0)
	// 	(r_rptr_inc |=> $countones(r_rptr_gray_q ^ $past(r_rptr_gray_q)) == 1)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:422:583
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_async_sram_adapter.sv", 422, "RptrGrayOneBitAtATime_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:425:61
	// removed an assertion item
	// WSramRvalid_A : assert property (@(posedge clk_wr_i) disable iff (!rst_wr_ni !== '0)
	// 	!w_sram_rvalid_i
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:425:616
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_async_sram_adapter.sv", 425, "WSramRvalid_A");
	// end
	// Trace: macro expansion of ASSUME at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:431:28
	// removed an assertion item
	// RSramRvalidOneCycle_M : assume property (@(posedge clk_rd_i) disable iff (!rst_rd_ni !== '0)
	// 	(r_sram_req_o && r_sram_gnt_i |=> r_sram_rvalid_i)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_async_sram_adapter.sv:431:583
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_async_sram_adapter.sv", 431, "RSramRvalidOneCycle_M");
	// end
	initial _sv2v_0 = 0;
endmodule
module prim_fifo_sync (
	clk_i,
	rst_ni,
	clr_i,
	wvalid_i,
	wready_o,
	wdata_i,
	rvalid_o,
	rready_i,
	rdata_o,
	full_o,
	depth_o,
	err_o
);
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:10:13
	parameter [31:0] Width = 16;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:11:13
	parameter [0:0] Pass = 1'b1;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:12:13
	parameter [31:0] Depth = 4;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:13:13
	parameter [0:0] OutputZeroIfEmpty = 1'b1;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:14:13
	parameter [0:0] Secure = 1'b0;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:16:14
	function automatic integer prim_util_pkg_vbits;
		// Trace: ips/pkgs/prim_util_pkg.sv:74:36
		input integer value;
		// Trace: ips/pkgs/prim_util_pkg.sv:85:5
		prim_util_pkg_vbits = (value == 1 ? 1 : $clog2(value));
	endfunction
	localparam signed [31:0] DepthW = prim_util_pkg_vbits(Depth + 1);
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:18:3
	input clk_i;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:19:3
	input rst_ni;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:21:3
	input clr_i;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:23:3
	input wvalid_i;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:24:3
	output wire wready_o;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:25:3
	input [Width - 1:0] wdata_i;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:27:3
	output wire rvalid_o;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:28:3
	input rready_i;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:29:3
	output wire [Width - 1:0] rdata_o;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:31:3
	output wire full_o;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:32:3
	output wire [DepthW - 1:0] depth_o;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:33:3
	output wire err_o;
	// Trace: ips/prim_opentitan/prim_fifo_sync.sv:38:3
	function automatic signed [Width - 1:0] sv2v_cast_62596_signed;
		input reg signed [Width - 1:0] inp;
		sv2v_cast_62596_signed = inp;
	endfunction
	generate
		if (Depth == 0) begin : gen_passthru_fifo
			// Trace: macro expansion of ASSERT_INIT at ips/prim_opentitan/prim_fifo_sync.sv:39:379
			initial begin
				// Trace: macro expansion of ASSERT_INIT at ips/prim_opentitan/prim_fifo_sync.sv:39:467
				begin : paramCheckPass
					
				end
			end
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:41:5
			assign depth_o = 1'b0;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:44:5
			assign rvalid_o = wvalid_i;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:45:5
			assign rdata_o = wdata_i;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:48:5
			assign wready_o = rready_i;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:49:5
			assign full_o = rready_i;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:52:5
			wire unused_clr;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:53:5
			assign unused_clr = clr_i;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:56:5
			assign err_o = 1'b0;
		end
		else begin : gen_normal_fifo
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:61:5
			localparam [31:0] PtrW = prim_util_pkg_vbits(Depth);
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:63:5
			wire [PtrW - 1:0] fifo_wptr;
			wire [PtrW - 1:0] fifo_rptr;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:64:5
			wire fifo_incr_wptr;
			wire fifo_incr_rptr;
			wire fifo_empty;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:67:5
			reg under_rst;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:68:5
			always @(posedge clk_i or negedge rst_ni)
				// Trace: ips/prim_opentitan/prim_fifo_sync.sv:69:7
				if (!rst_ni)
					// Trace: ips/prim_opentitan/prim_fifo_sync.sv:70:9
					under_rst <= 1'b1;
				else if (under_rst)
					// Trace: ips/prim_opentitan/prim_fifo_sync.sv:72:9
					under_rst <= ~under_rst;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:76:5
			wire empty;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:81:5
			assign wready_o = ~full_o & ~under_rst;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:82:5
			assign rvalid_o = ~empty & ~under_rst;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:84:5
			prim_fifo_sync_cnt #(
				.Depth(Depth),
				.Secure(Secure)
			) u_fifo_cnt(
				.clk_i(clk_i),
				.rst_ni(rst_ni),
				.clr_i(clr_i),
				.incr_wptr_i(fifo_incr_wptr),
				.incr_rptr_i(fifo_incr_rptr),
				.wptr_o(fifo_wptr),
				.rptr_o(fifo_rptr),
				.full_o(full_o),
				.empty_o(fifo_empty),
				.depth_o(depth_o),
				.err_o(err_o)
			);
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:100:5
			assign fifo_incr_wptr = (wvalid_i & wready_o) & ~under_rst;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:101:5
			assign fifo_incr_rptr = (rvalid_o & rready_i) & ~under_rst;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:105:5
			reg [(Depth * Width) - 1:0] storage;
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:106:5
			wire [Width - 1:0] storage_rdata;
			if (Depth == 1) begin : gen_depth_eq1
				// Trace: ips/prim_opentitan/prim_fifo_sync.sv:108:7
				assign storage_rdata = storage[0+:Width];
				// Trace: ips/prim_opentitan/prim_fifo_sync.sv:110:7
				always @(posedge clk_i)
					if (fifo_incr_wptr)
						// Trace: ips/prim_opentitan/prim_fifo_sync.sv:112:11
						storage[0+:Width] <= wdata_i;
				// Trace: ips/prim_opentitan/prim_fifo_sync.sv:115:7
				wire unused_ptrs;
				// Trace: ips/prim_opentitan/prim_fifo_sync.sv:116:7
				assign unused_ptrs = ^{fifo_wptr, fifo_rptr};
			end
			else begin : gen_depth_gt1
				// Trace: ips/prim_opentitan/prim_fifo_sync.sv:120:7
				assign storage_rdata = storage[fifo_rptr * Width+:Width];
				// Trace: ips/prim_opentitan/prim_fifo_sync.sv:122:7
				always @(posedge clk_i)
					if (fifo_incr_wptr)
						// Trace: ips/prim_opentitan/prim_fifo_sync.sv:124:11
						storage[fifo_wptr * Width+:Width] <= wdata_i;
			end
			// Trace: ips/prim_opentitan/prim_fifo_sync.sv:128:5
			wire [Width - 1:0] rdata_int;
			if (Pass == 1'b1) begin : gen_pass
				// Trace: ips/prim_opentitan/prim_fifo_sync.sv:130:7
				assign rdata_int = (fifo_empty && wvalid_i ? wdata_i : storage_rdata);
				// Trace: ips/prim_opentitan/prim_fifo_sync.sv:131:7
				assign empty = fifo_empty & ~wvalid_i;
			end
			else begin : gen_nopass
				// Trace: ips/prim_opentitan/prim_fifo_sync.sv:133:7
				assign rdata_int = storage_rdata;
				// Trace: ips/prim_opentitan/prim_fifo_sync.sv:134:7
				assign empty = fifo_empty;
			end
			if (OutputZeroIfEmpty == 1'b1) begin : gen_output_zero
				// Trace: ips/prim_opentitan/prim_fifo_sync.sv:138:7
				assign rdata_o = (empty ? sv2v_cast_62596_signed(0) : rdata_int);
			end
			else begin : gen_no_output_zero
				// Trace: ips/prim_opentitan/prim_fifo_sync.sv:140:7
				assign rdata_o = rdata_int;
			end
			// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_fifo_sync.sv:143:77
			// removed an assertion item
			// depthShallNotExceedParamDepth : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
			// 	(!empty |-> depth_o <= DepthW'(Depth))
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_sync.sv:143:632
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_sync.sv", 143, "depthShallNotExceedParamDepth");
			// end
		end
	endgenerate
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_fifo_sync.sv:151:54
	// removed an assertion item
	// DataKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(rvalid_o |-> !$isunknown(rdata_o))
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_sync.sv:151:609
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_sync.sv", 151, "DataKnown_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_fifo_sync.sv:152:169
	// removed an assertion item
	// DepthKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(depth_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_sync.sv:152:724
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_sync.sv", 152, "DepthKnown_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_fifo_sync.sv:153:171
	// removed an assertion item
	// RvalidKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(rvalid_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_sync.sv:153:726
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_sync.sv", 153, "RvalidKnown_A");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_fifo_sync.sv:154:171
	// removed an assertion item
	// WreadyKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(wready_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_fifo_sync.sv:154:726
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_fifo_sync.sv", 154, "WreadyKnown_A");
	// end
endmodule
module prim_fifo_sync_cnt (
	clk_i,
	rst_ni,
	clr_i,
	incr_wptr_i,
	incr_rptr_i,
	wptr_o,
	rptr_o,
	full_o,
	empty_o,
	depth_o,
	err_o
);
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:11:13
	parameter [31:0] Depth = 4;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:13:13
	parameter [0:0] Secure = 1'b0;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:15:14
	function automatic integer prim_util_pkg_vbits;
		// Trace: ips/pkgs/prim_util_pkg.sv:74:36
		input integer value;
		// Trace: ips/pkgs/prim_util_pkg.sv:85:5
		prim_util_pkg_vbits = (value == 1 ? 1 : $clog2(value));
	endfunction
	localparam [31:0] PtrW = prim_util_pkg_vbits(Depth);
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:17:14
	localparam [31:0] DepthW = prim_util_pkg_vbits(Depth + 1);
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:19:3
	input clk_i;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:20:3
	input rst_ni;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:21:3
	input clr_i;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:22:3
	input incr_wptr_i;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:23:3
	input incr_rptr_i;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:25:3
	output wire [PtrW - 1:0] wptr_o;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:26:3
	output wire [PtrW - 1:0] rptr_o;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:27:3
	output wire full_o;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:28:3
	output wire empty_o;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:31:3
	output wire [DepthW - 1:0] depth_o;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:32:3
	output wire err_o;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:36:3
	localparam [31:0] WrapPtrW = PtrW + 1;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:37:3
	reg [WrapPtrW - 1:0] wptr_wrap_cnt_q;
	wire [WrapPtrW - 1:0] wptr_wrap_set_cnt;
	reg [WrapPtrW - 1:0] rptr_wrap_cnt_q;
	wire [WrapPtrW - 1:0] rptr_wrap_set_cnt;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:41:3
	assign wptr_o = wptr_wrap_cnt_q[PtrW - 1:0];
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:42:3
	assign rptr_o = rptr_wrap_cnt_q[PtrW - 1:0];
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:45:3
	wire wptr_wrap_msb;
	wire rptr_wrap_msb;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:46:3
	assign wptr_wrap_msb = wptr_wrap_cnt_q[WrapPtrW - 1];
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:47:3
	assign rptr_wrap_msb = rptr_wrap_cnt_q[WrapPtrW - 1];
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:50:3
	wire wptr_wrap_set;
	wire rptr_wrap_set;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:51:3
	function automatic [PtrW - 1:0] sv2v_cast_09B00;
		input reg [PtrW - 1:0] inp;
		sv2v_cast_09B00 = inp;
	endfunction
	assign wptr_wrap_set = incr_wptr_i & (wptr_o == sv2v_cast_09B00(Depth - 1));
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:52:3
	assign rptr_wrap_set = incr_rptr_i & (rptr_o == sv2v_cast_09B00(Depth - 1));
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:55:3
	assign wptr_wrap_set_cnt = {~wptr_wrap_msb, {WrapPtrW - 1 {1'b0}}};
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:56:3
	assign rptr_wrap_set_cnt = {~rptr_wrap_msb, {WrapPtrW - 1 {1'b0}}};
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:59:3
	assign full_o = wptr_wrap_cnt_q == (rptr_wrap_cnt_q ^ {1'b1, {WrapPtrW - 1 {1'b0}}});
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:61:3
	assign empty_o = wptr_wrap_cnt_q == rptr_wrap_cnt_q;
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:68:3
	function automatic [DepthW - 1:0] sv2v_cast_2DA09;
		input reg [DepthW - 1:0] inp;
		sv2v_cast_2DA09 = inp;
	endfunction
	assign depth_o = (full_o ? sv2v_cast_2DA09(Depth) : (wptr_wrap_msb == rptr_wrap_msb ? sv2v_cast_2DA09(wptr_o) - sv2v_cast_2DA09(rptr_o) : (sv2v_cast_2DA09(Depth) - sv2v_cast_2DA09(rptr_o)) + sv2v_cast_2DA09(wptr_o)));
	// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:72:3
	function automatic [WrapPtrW - 1:0] sv2v_cast_00CF8;
		input reg [WrapPtrW - 1:0] inp;
		sv2v_cast_00CF8 = inp;
	endfunction
	generate
		if (Secure) begin : gen_secure_ptrs
			// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:73:5
			wire wptr_err;
			// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:74:5
			// rewrote reg-to-output bindings
			wire [WrapPtrW:1] sv2v_tmp_u_wptr_cnt_o;
			always @(*) wptr_wrap_cnt_q = sv2v_tmp_u_wptr_cnt_o;
			prim_count #(.Width(WrapPtrW)) u_wptr(
				.clk_i(clk_i),
				.rst_ni(rst_ni),
				.clr_i(clr_i),
				.set_i(wptr_wrap_set),
				.set_cnt_i(wptr_wrap_set_cnt),
				.incr_en_i(incr_wptr_i),
				.decr_en_i(1'b0),
				.step_i(sv2v_cast_00CF8(1'b1)),
				.commit_i(1'b1),
				.cnt_o(sv2v_tmp_u_wptr_cnt_o),
				.cnt_after_commit_o(),
				.err_o(wptr_err)
			);
			// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:91:5
			wire rptr_err;
			// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:92:5
			// rewrote reg-to-output bindings
			wire [WrapPtrW:1] sv2v_tmp_u_rptr_cnt_o;
			always @(*) rptr_wrap_cnt_q = sv2v_tmp_u_rptr_cnt_o;
			prim_count #(.Width(WrapPtrW)) u_rptr(
				.clk_i(clk_i),
				.rst_ni(rst_ni),
				.clr_i(clr_i),
				.set_i(rptr_wrap_set),
				.set_cnt_i(rptr_wrap_set_cnt),
				.incr_en_i(incr_rptr_i),
				.decr_en_i(1'b0),
				.step_i(sv2v_cast_00CF8(1'b1)),
				.commit_i(1'b1),
				.cnt_o(sv2v_tmp_u_rptr_cnt_o),
				.cnt_after_commit_o(),
				.err_o(rptr_err)
			);
			// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:109:5
			assign err_o = wptr_err | rptr_err;
		end
		else begin : gen_normal_ptrs
			// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:112:5
			always @(posedge clk_i or negedge rst_ni)
				// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:113:7
				if (!rst_ni)
					// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:114:9
					wptr_wrap_cnt_q <= {WrapPtrW {1'b0}};
				else if (clr_i)
					// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:116:9
					wptr_wrap_cnt_q <= {WrapPtrW {1'b0}};
				else if (wptr_wrap_set)
					// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:118:9
					wptr_wrap_cnt_q <= wptr_wrap_set_cnt;
				else if (incr_wptr_i)
					// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:120:9
					wptr_wrap_cnt_q <= wptr_wrap_cnt_q + {{WrapPtrW - 1 {1'b0}}, 1'b1};
			// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:124:5
			always @(posedge clk_i or negedge rst_ni)
				// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:125:7
				if (!rst_ni)
					// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:126:9
					rptr_wrap_cnt_q <= {WrapPtrW {1'b0}};
				else if (clr_i)
					// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:128:9
					rptr_wrap_cnt_q <= {WrapPtrW {1'b0}};
				else if (rptr_wrap_set)
					// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:130:9
					rptr_wrap_cnt_q <= rptr_wrap_set_cnt;
				else if (incr_rptr_i)
					// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:132:9
					rptr_wrap_cnt_q <= rptr_wrap_cnt_q + {{WrapPtrW - 1 {1'b0}}, 1'b1};
			// Trace: ips/prim_opentitan/prim_fifo_sync_cnt.sv:136:5
			assign err_o = 1'sb0;
		end
	endgenerate
endmodule
module prim_filter (
	clk_i,
	rst_ni,
	enable_i,
	filter_i,
	filter_o
);
	// Trace: ips/prim_opentitan/prim_filter.sv:16:13
	parameter [0:0] AsyncOn = 0;
	// Trace: ips/prim_opentitan/prim_filter.sv:17:13
	parameter [31:0] Cycles = 4;
	// Trace: ips/prim_opentitan/prim_filter.sv:19:3
	input clk_i;
	// Trace: ips/prim_opentitan/prim_filter.sv:20:3
	input rst_ni;
	// Trace: ips/prim_opentitan/prim_filter.sv:21:3
	input enable_i;
	// Trace: ips/prim_opentitan/prim_filter.sv:22:3
	input filter_i;
	// Trace: ips/prim_opentitan/prim_filter.sv:23:3
	output wire filter_o;
	// Trace: ips/prim_opentitan/prim_filter.sv:26:3
	reg [Cycles - 1:0] stored_vector_q;
	wire [Cycles - 1:0] stored_vector_d;
	// Trace: ips/prim_opentitan/prim_filter.sv:27:3
	reg stored_value_q;
	wire update_stored_value;
	// Trace: ips/prim_opentitan/prim_filter.sv:28:3
	wire unused_stored_vector_q_msb;
	// Trace: ips/prim_opentitan/prim_filter.sv:30:3
	wire filter_synced;
	// Trace: ips/prim_opentitan/prim_filter.sv:32:3
	generate
		if (AsyncOn) begin : gen_async
			// Trace: ips/prim_opentitan/prim_filter.sv:35:5
			prim_flop_2sync #(.Width(1)) prim_flop_2sync(
				.clk_i(clk_i),
				.rst_ni(rst_ni),
				.d_i(filter_i),
				.q_o(filter_synced)
			);
		end
		else begin : gen_sync
			// Trace: ips/prim_opentitan/prim_filter.sv:44:5
			assign filter_synced = filter_i;
		end
	endgenerate
	// Trace: ips/prim_opentitan/prim_filter.sv:47:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: ips/prim_opentitan/prim_filter.sv:48:5
		if (!rst_ni)
			// Trace: ips/prim_opentitan/prim_filter.sv:49:7
			stored_value_q <= 1'b0;
		else if (update_stored_value)
			// Trace: ips/prim_opentitan/prim_filter.sv:51:7
			stored_value_q <= filter_synced;
	// Trace: ips/prim_opentitan/prim_filter.sv:55:3
	assign stored_vector_d = {stored_vector_q[Cycles - 2:0], filter_synced};
	// Trace: ips/prim_opentitan/prim_filter.sv:56:3
	assign unused_stored_vector_q_msb = stored_vector_q[Cycles - 1];
	// Trace: ips/prim_opentitan/prim_filter.sv:58:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: ips/prim_opentitan/prim_filter.sv:59:5
		if (!rst_ni)
			// Trace: ips/prim_opentitan/prim_filter.sv:60:7
			stored_vector_q <= 1'sb0;
		else
			// Trace: ips/prim_opentitan/prim_filter.sv:62:7
			stored_vector_q <= stored_vector_d;
	// Trace: ips/prim_opentitan/prim_filter.sv:66:3
	assign update_stored_value = (stored_vector_d == {Cycles {1'b0}}) | (stored_vector_d == {Cycles {1'b1}});
	// Trace: ips/prim_opentitan/prim_filter.sv:70:3
	assign filter_o = (enable_i ? stored_value_q : filter_synced);
endmodule
module prim_filter_ctr (
	clk_i,
	rst_ni,
	enable_i,
	filter_i,
	thresh_i,
	filter_o
);
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:18:13
	parameter [0:0] AsyncOn = 0;
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:19:13
	parameter [31:0] CntWidth = 2;
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:21:3
	input clk_i;
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:22:3
	input rst_ni;
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:23:3
	input enable_i;
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:24:3
	input filter_i;
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:25:3
	input [CntWidth - 1:0] thresh_i;
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:26:3
	output wire filter_o;
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:29:3
	reg [CntWidth - 1:0] diff_ctr_q;
	wire [CntWidth - 1:0] diff_ctr_d;
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:30:3
	reg filter_q;
	reg stored_value_q;
	wire update_stored_value;
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:32:3
	wire filter_synced;
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:34:3
	generate
		if (AsyncOn) begin : gen_async
			// Trace: ips/prim_opentitan/prim_filter_ctr.sv:37:5
			prim_flop_2sync #(.Width(1)) prim_flop_2sync(
				.clk_i(clk_i),
				.rst_ni(rst_ni),
				.d_i(filter_i),
				.q_o(filter_synced)
			);
		end
		else begin : gen_sync
			// Trace: ips/prim_opentitan/prim_filter_ctr.sv:46:5
			assign filter_synced = filter_i;
		end
	endgenerate
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:49:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: ips/prim_opentitan/prim_filter_ctr.sv:50:5
		if (!rst_ni)
			// Trace: ips/prim_opentitan/prim_filter_ctr.sv:51:7
			filter_q <= 1'b0;
		else
			// Trace: ips/prim_opentitan/prim_filter_ctr.sv:53:7
			filter_q <= filter_synced;
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:57:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: ips/prim_opentitan/prim_filter_ctr.sv:58:5
		if (!rst_ni)
			// Trace: ips/prim_opentitan/prim_filter_ctr.sv:59:7
			stored_value_q <= 1'b0;
		else if (update_stored_value)
			// Trace: ips/prim_opentitan/prim_filter_ctr.sv:61:7
			stored_value_q <= filter_synced;
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:65:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: ips/prim_opentitan/prim_filter_ctr.sv:66:5
		if (!rst_ni)
			// Trace: ips/prim_opentitan/prim_filter_ctr.sv:67:7
			diff_ctr_q <= 1'sb0;
		else
			// Trace: ips/prim_opentitan/prim_filter_ctr.sv:69:7
			diff_ctr_q <= diff_ctr_d;
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:74:3
	assign update_stored_value = diff_ctr_d == thresh_i;
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:75:3
	assign diff_ctr_d = (filter_synced != filter_q ? {CntWidth {1'sb0}} : (diff_ctr_q >= thresh_i ? thresh_i : diff_ctr_q + 1'b1));
	// Trace: ips/prim_opentitan/prim_filter_ctr.sv:79:3
	assign filter_o = (enable_i ? stored_value_q : filter_synced);
endmodule
module prim_flop (
	clk_i,
	rst_ni,
	d_i,
	q_o
);
	// Trace: ips/prim_opentitan/prim_flop.sv:8:13
	parameter signed [31:0] Width = 1;
	// Trace: ips/prim_opentitan/prim_flop.sv:9:13
	parameter [Width - 1:0] ResetValue = 0;
	// Trace: ips/prim_opentitan/prim_flop.sv:11:3
	input clk_i;
	// Trace: ips/prim_opentitan/prim_flop.sv:12:3
	input rst_ni;
	// Trace: ips/prim_opentitan/prim_flop.sv:13:3
	input [Width - 1:0] d_i;
	// Trace: ips/prim_opentitan/prim_flop.sv:14:3
	output reg [Width - 1:0] q_o;
	// Trace: ips/prim_opentitan/prim_flop.sv:17:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: ips/prim_opentitan/prim_flop.sv:18:5
		if (!rst_ni)
			// Trace: ips/prim_opentitan/prim_flop.sv:19:7
			q_o <= ResetValue;
		else
			// Trace: ips/prim_opentitan/prim_flop.sv:21:7
			q_o <= d_i;
endmodule
module prim_flop_2sync (
	clk_i,
	rst_ni,
	d_i,
	q_o
);
	reg _sv2v_0;
	// Trace: ips/prim_opentitan/prim_flop_2sync.sv:2:13
	parameter signed [31:0] Width = 16;
	// Trace: ips/prim_opentitan/prim_flop_2sync.sv:3:13
	parameter [Width - 1:0] ResetValue = 1'sb0;
	// Trace: ips/prim_opentitan/prim_flop_2sync.sv:4:13
	parameter [0:0] EnablePrimCdcRand = 1;
	// Trace: ips/prim_opentitan/prim_flop_2sync.sv:6:3
	input clk_i;
	// Trace: ips/prim_opentitan/prim_flop_2sync.sv:7:3
	input rst_ni;
	// Trace: ips/prim_opentitan/prim_flop_2sync.sv:8:3
	input [Width - 1:0] d_i;
	// Trace: ips/prim_opentitan/prim_flop_2sync.sv:9:3
	output wire [Width - 1:0] q_o;
	// Trace: ips/prim_opentitan/prim_flop_2sync.sv:12:3
	reg [Width - 1:0] d_o;
	// Trace: ips/prim_opentitan/prim_flop_2sync.sv:13:3
	wire [Width - 1:0] intq;
	// Trace: ips/prim_opentitan/prim_flop_2sync.sv:28:3
	wire unused_sig;
	// Trace: ips/prim_opentitan/prim_flop_2sync.sv:29:3
	assign unused_sig = EnablePrimCdcRand;
	// Trace: ips/prim_opentitan/prim_flop_2sync.sv:30:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: ips/prim_opentitan/prim_flop_2sync.sv:30:15
		d_o = d_i;
	end
	// Trace: ips/prim_opentitan/prim_flop_2sync.sv:33:3
	prim_flop #(
		.Width(Width),
		.ResetValue(ResetValue)
	) u_sync_1(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.d_i(d_o),
		.q_o(intq)
	);
	// Trace: ips/prim_opentitan/prim_flop_2sync.sv:43:3
	prim_flop #(
		.Width(Width),
		.ResetValue(ResetValue)
	) u_sync_2(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.d_i(intq),
		.q_o(q_o)
	);
	initial _sv2v_0 = 0;
endmodule
module prim_secded_inv_39_32_dec (
	data_i,
	data_o,
	syndrome_o,
	err_o
);
	reg _sv2v_0;
	// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:8:3
	input [38:0] data_i;
	// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:9:3
	output reg [31:0] data_o;
	// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:10:3
	output reg [6:0] syndrome_o;
	// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:11:3
	output reg [1:0] err_o;
	// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:14:3
	always @(*) begin : p_encode
		if (_sv2v_0)
			;
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:16:5
		syndrome_o[0] = ^((data_i ^ 39'h2a00000000) & 39'h012606bd25);
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:17:5
		syndrome_o[1] = ^((data_i ^ 39'h2a00000000) & 39'h02deba8050);
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:18:5
		syndrome_o[2] = ^((data_i ^ 39'h2a00000000) & 39'h04413d89aa);
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:19:5
		syndrome_o[3] = ^((data_i ^ 39'h2a00000000) & 39'h0831234ed1);
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:20:5
		syndrome_o[4] = ^((data_i ^ 39'h2a00000000) & 39'h10c2c1323b);
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:21:5
		syndrome_o[5] = ^((data_i ^ 39'h2a00000000) & 39'h202dcc624c);
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:22:5
		syndrome_o[6] = ^((data_i ^ 39'h2a00000000) & 39'h4098505586);
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:25:5
		data_o[0] = (syndrome_o == 7'h19) ^ data_i[0];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:26:5
		data_o[1] = (syndrome_o == 7'h54) ^ data_i[1];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:27:5
		data_o[2] = (syndrome_o == 7'h61) ^ data_i[2];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:28:5
		data_o[3] = (syndrome_o == 7'h34) ^ data_i[3];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:29:5
		data_o[4] = (syndrome_o == 7'h1a) ^ data_i[4];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:30:5
		data_o[5] = (syndrome_o == 7'h15) ^ data_i[5];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:31:5
		data_o[6] = (syndrome_o == 7'h2a) ^ data_i[6];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:32:5
		data_o[7] = (syndrome_o == 7'h4c) ^ data_i[7];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:33:5
		data_o[8] = (syndrome_o == 7'h45) ^ data_i[8];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:34:5
		data_o[9] = (syndrome_o == 7'h38) ^ data_i[9];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:35:5
		data_o[10] = (syndrome_o == 7'h49) ^ data_i[10];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:36:5
		data_o[11] = (syndrome_o == 7'h0d) ^ data_i[11];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:37:5
		data_o[12] = (syndrome_o == 7'h51) ^ data_i[12];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:38:5
		data_o[13] = (syndrome_o == 7'h31) ^ data_i[13];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:39:5
		data_o[14] = (syndrome_o == 7'h68) ^ data_i[14];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:40:5
		data_o[15] = (syndrome_o == 7'h07) ^ data_i[15];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:41:5
		data_o[16] = (syndrome_o == 7'h1c) ^ data_i[16];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:42:5
		data_o[17] = (syndrome_o == 7'h0b) ^ data_i[17];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:43:5
		data_o[18] = (syndrome_o == 7'h25) ^ data_i[18];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:44:5
		data_o[19] = (syndrome_o == 7'h26) ^ data_i[19];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:45:5
		data_o[20] = (syndrome_o == 7'h46) ^ data_i[20];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:46:5
		data_o[21] = (syndrome_o == 7'h0e) ^ data_i[21];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:47:5
		data_o[22] = (syndrome_o == 7'h70) ^ data_i[22];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:48:5
		data_o[23] = (syndrome_o == 7'h32) ^ data_i[23];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:49:5
		data_o[24] = (syndrome_o == 7'h2c) ^ data_i[24];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:50:5
		data_o[25] = (syndrome_o == 7'h13) ^ data_i[25];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:51:5
		data_o[26] = (syndrome_o == 7'h23) ^ data_i[26];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:52:5
		data_o[27] = (syndrome_o == 7'h62) ^ data_i[27];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:53:5
		data_o[28] = (syndrome_o == 7'h4a) ^ data_i[28];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:54:5
		data_o[29] = (syndrome_o == 7'h29) ^ data_i[29];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:55:5
		data_o[30] = (syndrome_o == 7'h16) ^ data_i[30];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:56:5
		data_o[31] = (syndrome_o == 7'h52) ^ data_i[31];
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:59:5
		err_o[0] = ^syndrome_o;
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_dec.sv:60:5
		err_o[1] = ~err_o[0] & |syndrome_o;
	end
	initial _sv2v_0 = 0;
endmodule
module prim_secded_inv_39_32_enc (
	data_i,
	data_o
);
	reg _sv2v_0;
	// Trace: ips/prim_opentitan/prim_secded_inv_39_32_enc.sv:8:3
	input [31:0] data_i;
	// Trace: ips/prim_opentitan/prim_secded_inv_39_32_enc.sv:9:3
	output reg [38:0] data_o;
	// Trace: ips/prim_opentitan/prim_secded_inv_39_32_enc.sv:12:3
	function automatic [38:0] sv2v_cast_39;
		input reg [38:0] inp;
		sv2v_cast_39 = inp;
	endfunction
	always @(*) begin : p_encode
		if (_sv2v_0)
			;
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_enc.sv:13:5
		data_o = sv2v_cast_39(data_i);
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_enc.sv:14:5
		data_o[32] = ^(data_o & 39'h002606bd25);
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_enc.sv:15:5
		data_o[33] = ^(data_o & 39'h00deba8050);
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_enc.sv:16:5
		data_o[34] = ^(data_o & 39'h00413d89aa);
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_enc.sv:17:5
		data_o[35] = ^(data_o & 39'h0031234ed1);
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_enc.sv:18:5
		data_o[36] = ^(data_o & 39'h00c2c1323b);
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_enc.sv:19:5
		data_o[37] = ^(data_o & 39'h002dcc624c);
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_enc.sv:20:5
		data_o[38] = ^(data_o & 39'h0098505586);
		// Trace: ips/prim_opentitan/prim_secded_inv_39_32_enc.sv:21:5
		data_o = data_o ^ 39'h2a00000000;
	end
	initial _sv2v_0 = 0;
endmodule
module prim_secded_inv_64_57_dec (
	data_i,
	data_o,
	syndrome_o,
	err_o
);
	reg _sv2v_0;
	// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:8:3
	input [63:0] data_i;
	// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:9:3
	output reg [56:0] data_o;
	// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:10:3
	output reg [6:0] syndrome_o;
	// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:11:3
	output reg [1:0] err_o;
	// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:14:3
	always @(*) begin : p_encode
		if (_sv2v_0)
			;
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:16:5
		syndrome_o[0] = ^((data_i ^ 64'h5400000000000000) & 64'h0303fff800007fff);
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:17:5
		syndrome_o[1] = ^((data_i ^ 64'h5400000000000000) & 64'h057c1ff801ff801f);
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:18:5
		syndrome_o[2] = ^((data_i ^ 64'h5400000000000000) & 64'h09bde1f87e0781e1);
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:19:5
		syndrome_o[3] = ^((data_i ^ 64'h5400000000000000) & 64'h11deee3b8e388e22);
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:20:5
		syndrome_o[4] = ^((data_i ^ 64'h5400000000000000) & 64'h21ef76cdb2c93244);
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:21:5
		syndrome_o[5] = ^((data_i ^ 64'h5400000000000000) & 64'h41f7bb56d5525488);
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:22:5
		syndrome_o[6] = ^((data_i ^ 64'h5400000000000000) & 64'h81fbdda769a46910);
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:25:5
		data_o[0] = (syndrome_o == 7'h07) ^ data_i[0];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:26:5
		data_o[1] = (syndrome_o == 7'h0b) ^ data_i[1];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:27:5
		data_o[2] = (syndrome_o == 7'h13) ^ data_i[2];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:28:5
		data_o[3] = (syndrome_o == 7'h23) ^ data_i[3];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:29:5
		data_o[4] = (syndrome_o == 7'h43) ^ data_i[4];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:30:5
		data_o[5] = (syndrome_o == 7'h0d) ^ data_i[5];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:31:5
		data_o[6] = (syndrome_o == 7'h15) ^ data_i[6];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:32:5
		data_o[7] = (syndrome_o == 7'h25) ^ data_i[7];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:33:5
		data_o[8] = (syndrome_o == 7'h45) ^ data_i[8];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:34:5
		data_o[9] = (syndrome_o == 7'h19) ^ data_i[9];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:35:5
		data_o[10] = (syndrome_o == 7'h29) ^ data_i[10];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:36:5
		data_o[11] = (syndrome_o == 7'h49) ^ data_i[11];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:37:5
		data_o[12] = (syndrome_o == 7'h31) ^ data_i[12];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:38:5
		data_o[13] = (syndrome_o == 7'h51) ^ data_i[13];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:39:5
		data_o[14] = (syndrome_o == 7'h61) ^ data_i[14];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:40:5
		data_o[15] = (syndrome_o == 7'h0e) ^ data_i[15];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:41:5
		data_o[16] = (syndrome_o == 7'h16) ^ data_i[16];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:42:5
		data_o[17] = (syndrome_o == 7'h26) ^ data_i[17];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:43:5
		data_o[18] = (syndrome_o == 7'h46) ^ data_i[18];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:44:5
		data_o[19] = (syndrome_o == 7'h1a) ^ data_i[19];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:45:5
		data_o[20] = (syndrome_o == 7'h2a) ^ data_i[20];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:46:5
		data_o[21] = (syndrome_o == 7'h4a) ^ data_i[21];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:47:5
		data_o[22] = (syndrome_o == 7'h32) ^ data_i[22];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:48:5
		data_o[23] = (syndrome_o == 7'h52) ^ data_i[23];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:49:5
		data_o[24] = (syndrome_o == 7'h62) ^ data_i[24];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:50:5
		data_o[25] = (syndrome_o == 7'h1c) ^ data_i[25];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:51:5
		data_o[26] = (syndrome_o == 7'h2c) ^ data_i[26];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:52:5
		data_o[27] = (syndrome_o == 7'h4c) ^ data_i[27];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:53:5
		data_o[28] = (syndrome_o == 7'h34) ^ data_i[28];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:54:5
		data_o[29] = (syndrome_o == 7'h54) ^ data_i[29];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:55:5
		data_o[30] = (syndrome_o == 7'h64) ^ data_i[30];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:56:5
		data_o[31] = (syndrome_o == 7'h38) ^ data_i[31];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:57:5
		data_o[32] = (syndrome_o == 7'h58) ^ data_i[32];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:58:5
		data_o[33] = (syndrome_o == 7'h68) ^ data_i[33];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:59:5
		data_o[34] = (syndrome_o == 7'h70) ^ data_i[34];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:60:5
		data_o[35] = (syndrome_o == 7'h1f) ^ data_i[35];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:61:5
		data_o[36] = (syndrome_o == 7'h2f) ^ data_i[36];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:62:5
		data_o[37] = (syndrome_o == 7'h4f) ^ data_i[37];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:63:5
		data_o[38] = (syndrome_o == 7'h37) ^ data_i[38];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:64:5
		data_o[39] = (syndrome_o == 7'h57) ^ data_i[39];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:65:5
		data_o[40] = (syndrome_o == 7'h67) ^ data_i[40];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:66:5
		data_o[41] = (syndrome_o == 7'h3b) ^ data_i[41];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:67:5
		data_o[42] = (syndrome_o == 7'h5b) ^ data_i[42];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:68:5
		data_o[43] = (syndrome_o == 7'h6b) ^ data_i[43];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:69:5
		data_o[44] = (syndrome_o == 7'h73) ^ data_i[44];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:70:5
		data_o[45] = (syndrome_o == 7'h3d) ^ data_i[45];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:71:5
		data_o[46] = (syndrome_o == 7'h5d) ^ data_i[46];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:72:5
		data_o[47] = (syndrome_o == 7'h6d) ^ data_i[47];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:73:5
		data_o[48] = (syndrome_o == 7'h75) ^ data_i[48];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:74:5
		data_o[49] = (syndrome_o == 7'h79) ^ data_i[49];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:75:5
		data_o[50] = (syndrome_o == 7'h3e) ^ data_i[50];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:76:5
		data_o[51] = (syndrome_o == 7'h5e) ^ data_i[51];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:77:5
		data_o[52] = (syndrome_o == 7'h6e) ^ data_i[52];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:78:5
		data_o[53] = (syndrome_o == 7'h76) ^ data_i[53];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:79:5
		data_o[54] = (syndrome_o == 7'h7a) ^ data_i[54];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:80:5
		data_o[55] = (syndrome_o == 7'h7c) ^ data_i[55];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:81:5
		data_o[56] = (syndrome_o == 7'h7f) ^ data_i[56];
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:84:5
		err_o[0] = ^syndrome_o;
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_dec.sv:85:5
		err_o[1] = ~err_o[0] & |syndrome_o;
	end
	initial _sv2v_0 = 0;
endmodule
module prim_secded_inv_64_57_enc (
	data_i,
	data_o
);
	reg _sv2v_0;
	// Trace: ips/prim_opentitan/prim_secded_inv_64_57_enc.sv:8:3
	input [56:0] data_i;
	// Trace: ips/prim_opentitan/prim_secded_inv_64_57_enc.sv:9:3
	output reg [63:0] data_o;
	// Trace: ips/prim_opentitan/prim_secded_inv_64_57_enc.sv:12:3
	function automatic [63:0] sv2v_cast_64;
		input reg [63:0] inp;
		sv2v_cast_64 = inp;
	endfunction
	always @(*) begin : p_encode
		if (_sv2v_0)
			;
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_enc.sv:13:5
		data_o = sv2v_cast_64(data_i);
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_enc.sv:14:5
		data_o[57] = ^(data_o & 64'h0103fff800007fff);
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_enc.sv:15:5
		data_o[58] = ^(data_o & 64'h017c1ff801ff801f);
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_enc.sv:16:5
		data_o[59] = ^(data_o & 64'h01bde1f87e0781e1);
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_enc.sv:17:5
		data_o[60] = ^(data_o & 64'h01deee3b8e388e22);
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_enc.sv:18:5
		data_o[61] = ^(data_o & 64'h01ef76cdb2c93244);
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_enc.sv:19:5
		data_o[62] = ^(data_o & 64'h01f7bb56d5525488);
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_enc.sv:20:5
		data_o[63] = ^(data_o & 64'h01fbdda769a46910);
		// Trace: ips/prim_opentitan/prim_secded_inv_64_57_enc.sv:21:5
		data_o = data_o ^ 64'h5400000000000000;
	end
	initial _sv2v_0 = 0;
endmodule
module prim_subreg (
	clk_i,
	rst_ni,
	we,
	wd,
	de,
	d,
	qe,
	q,
	ds,
	qs
);
	// removed import prim_subreg_pkg::*;
	// Trace: ips/prim_opentitan/prim_subreg.sv:10:13
	parameter signed [31:0] DW = 32;
	// Trace: ips/prim_opentitan/prim_subreg.sv:11:13
	// removed localparam type prim_subreg_pkg_sw_access_e
	parameter [2:0] SwAccess = 3'd0;
	// Trace: ips/prim_opentitan/prim_subreg.sv:12:13
	parameter [DW - 1:0] RESVAL = 1'sb0;
	// Trace: ips/prim_opentitan/prim_subreg.sv:13:13
	parameter [0:0] Mubi = 1'b0;
	// Trace: ips/prim_opentitan/prim_subreg.sv:15:3
	input clk_i;
	// Trace: ips/prim_opentitan/prim_subreg.sv:16:3
	input rst_ni;
	// Trace: ips/prim_opentitan/prim_subreg.sv:20:3
	input we;
	// Trace: ips/prim_opentitan/prim_subreg.sv:21:3
	input [DW - 1:0] wd;
	// Trace: ips/prim_opentitan/prim_subreg.sv:24:3
	input de;
	// Trace: ips/prim_opentitan/prim_subreg.sv:25:3
	input [DW - 1:0] d;
	// Trace: ips/prim_opentitan/prim_subreg.sv:28:3
	output wire qe;
	// Trace: ips/prim_opentitan/prim_subreg.sv:29:3
	output reg [DW - 1:0] q;
	// Trace: ips/prim_opentitan/prim_subreg.sv:34:3
	output wire [DW - 1:0] ds;
	// Trace: ips/prim_opentitan/prim_subreg.sv:35:3
	output wire [DW - 1:0] qs;
	// Trace: ips/prim_opentitan/prim_subreg.sv:38:3
	wire wr_en;
	// Trace: ips/prim_opentitan/prim_subreg.sv:39:3
	wire [DW - 1:0] wr_data;
	// Trace: ips/prim_opentitan/prim_subreg.sv:41:3
	prim_subreg_arb #(
		.DW(DW),
		.SwAccess(SwAccess),
		.Mubi(Mubi)
	) wr_en_data_arb(
		.we(we),
		.wd(wd),
		.de(de),
		.d(d),
		.q(q),
		.wr_en(wr_en),
		.wr_data(wr_data)
	);
	// Trace: ips/prim_opentitan/prim_subreg.sv:55:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: ips/prim_opentitan/prim_subreg.sv:56:5
		if (!rst_ni)
			// Trace: ips/prim_opentitan/prim_subreg.sv:57:7
			q <= RESVAL;
		else if (wr_en)
			// Trace: ips/prim_opentitan/prim_subreg.sv:59:7
			q <= wr_data;
	// Trace: ips/prim_opentitan/prim_subreg.sv:64:3
	assign ds = (wr_en ? wr_data : qs);
	// Trace: ips/prim_opentitan/prim_subreg.sv:65:3
	assign qe = wr_en;
	// Trace: ips/prim_opentitan/prim_subreg.sv:67:3
	generate
		if (SwAccess == 3'd6) begin : gen_rc
			// Trace: ips/prim_opentitan/prim_subreg.sv:70:5
			assign qs = (de && we ? d : q);
		end
		else begin : gen_no_rc
			// Trace: ips/prim_opentitan/prim_subreg.sv:72:5
			assign qs = q;
		end
	endgenerate
endmodule
module prim_subreg_arb (
	we,
	wd,
	de,
	d,
	q,
	wr_en,
	wr_data
);
	// removed import prim_subreg_pkg::*;
	// Trace: ips/prim_opentitan/prim_subreg_arb.sv:10:13
	parameter signed [31:0] DW = 32;
	// Trace: ips/prim_opentitan/prim_subreg_arb.sv:11:13
	// removed localparam type prim_subreg_pkg_sw_access_e
	parameter [2:0] SwAccess = 3'd0;
	// Trace: ips/prim_opentitan/prim_subreg_arb.sv:12:13
	parameter [0:0] Mubi = 1'b0;
	// Trace: ips/prim_opentitan/prim_subreg_arb.sv:16:3
	input we;
	// Trace: ips/prim_opentitan/prim_subreg_arb.sv:17:3
	input [DW - 1:0] wd;
	// Trace: ips/prim_opentitan/prim_subreg_arb.sv:20:3
	input de;
	// Trace: ips/prim_opentitan/prim_subreg_arb.sv:21:3
	input [DW - 1:0] d;
	// Trace: ips/prim_opentitan/prim_subreg_arb.sv:24:3
	input [DW - 1:0] q;
	// Trace: ips/prim_opentitan/prim_subreg_arb.sv:27:3
	output wire wr_en;
	// Trace: ips/prim_opentitan/prim_subreg_arb.sv:28:3
	output wire [DW - 1:0] wr_data;
	// Trace: ips/prim_opentitan/prim_subreg_arb.sv:30:3
	// removed import prim_mubi_pkg::*;
	// Trace: ips/prim_opentitan/prim_subreg_arb.sv:32:3
	localparam signed [31:0] prim_mubi_pkg_MuBi12Width = 12;
	// removed localparam type prim_mubi_pkg_mubi12_t
	localparam signed [31:0] prim_mubi_pkg_MuBi16Width = 16;
	// removed localparam type prim_mubi_pkg_mubi16_t
	localparam signed [31:0] prim_mubi_pkg_MuBi4Width = 4;
	// removed localparam type prim_mubi_pkg_mubi4_t
	localparam signed [31:0] prim_mubi_pkg_MuBi8Width = 8;
	// removed localparam type prim_mubi_pkg_mubi8_t
	function automatic [11:0] sv2v_cast_9D81C;
		input reg [11:0] inp;
		sv2v_cast_9D81C = inp;
	endfunction
	function automatic [11:0] prim_mubi_pkg_mubi12_and;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:370:42
		input reg [11:0] a;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:370:54
		input reg [11:0] b;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:370:66
		input reg [11:0] act;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:371:5
		reg [11:0] a_in;
		reg [11:0] b_in;
		reg [11:0] act_in;
		reg [11:0] out;
		begin
			// Trace: ips/pkgs/prim_mubi_pkg.sv:372:5
			a_in = a;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:373:5
			b_in = b;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:374:5
			act_in = act;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:375:5
			begin : sv2v_autoblock_1
				// Trace: ips/pkgs/prim_mubi_pkg.sv:375:10
				reg signed [31:0] k;
				// Trace: ips/pkgs/prim_mubi_pkg.sv:375:10
				for (k = 0; k < prim_mubi_pkg_MuBi12Width; k = k + 1)
					begin
						// Trace: ips/pkgs/prim_mubi_pkg.sv:376:7
						if (act_in[k])
							// Trace: ips/pkgs/prim_mubi_pkg.sv:377:9
							out[k] = a_in[k] && b_in[k];
						else
							// Trace: ips/pkgs/prim_mubi_pkg.sv:379:9
							out[k] = a_in[k] || b_in[k];
					end
			end
			prim_mubi_pkg_mubi12_and = sv2v_cast_9D81C(out);
		end
	endfunction
	function automatic [11:0] prim_mubi_pkg_mubi12_and_hi;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:395:45
		input reg [11:0] a;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:395:57
		input reg [11:0] b;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:396:5
		prim_mubi_pkg_mubi12_and_hi = prim_mubi_pkg_mubi12_and(a, b, sv2v_cast_9D81C(12'h696));
	endfunction
	function automatic [11:0] prim_mubi_pkg_mubi12_or;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:344:41
		input reg [11:0] a;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:344:53
		input reg [11:0] b;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:344:65
		input reg [11:0] act;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:345:5
		reg [11:0] a_in;
		reg [11:0] b_in;
		reg [11:0] act_in;
		reg [11:0] out;
		begin
			// Trace: ips/pkgs/prim_mubi_pkg.sv:346:5
			a_in = a;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:347:5
			b_in = b;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:348:5
			act_in = act;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:349:5
			begin : sv2v_autoblock_2
				// Trace: ips/pkgs/prim_mubi_pkg.sv:349:10
				reg signed [31:0] k;
				// Trace: ips/pkgs/prim_mubi_pkg.sv:349:10
				for (k = 0; k < prim_mubi_pkg_MuBi12Width; k = k + 1)
					begin
						// Trace: ips/pkgs/prim_mubi_pkg.sv:350:7
						if (act_in[k])
							// Trace: ips/pkgs/prim_mubi_pkg.sv:351:9
							out[k] = a_in[k] || b_in[k];
						else
							// Trace: ips/pkgs/prim_mubi_pkg.sv:353:9
							out[k] = a_in[k] && b_in[k];
					end
			end
			prim_mubi_pkg_mubi12_or = sv2v_cast_9D81C(out);
		end
	endfunction
	function automatic [11:0] prim_mubi_pkg_mubi12_or_hi;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:388:44
		input reg [11:0] a;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:388:56
		input reg [11:0] b;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:389:5
		prim_mubi_pkg_mubi12_or_hi = prim_mubi_pkg_mubi12_or(a, b, sv2v_cast_9D81C(12'h696));
	endfunction
	function automatic [15:0] sv2v_cast_B8818;
		input reg [15:0] inp;
		sv2v_cast_B8818 = inp;
	endfunction
	function automatic [15:0] prim_mubi_pkg_mubi16_and;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:502:42
		input reg [15:0] a;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:502:54
		input reg [15:0] b;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:502:66
		input reg [15:0] act;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:503:5
		reg [15:0] a_in;
		reg [15:0] b_in;
		reg [15:0] act_in;
		reg [15:0] out;
		begin
			// Trace: ips/pkgs/prim_mubi_pkg.sv:504:5
			a_in = a;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:505:5
			b_in = b;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:506:5
			act_in = act;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:507:5
			begin : sv2v_autoblock_3
				// Trace: ips/pkgs/prim_mubi_pkg.sv:507:10
				reg signed [31:0] k;
				// Trace: ips/pkgs/prim_mubi_pkg.sv:507:10
				for (k = 0; k < prim_mubi_pkg_MuBi16Width; k = k + 1)
					begin
						// Trace: ips/pkgs/prim_mubi_pkg.sv:508:7
						if (act_in[k])
							// Trace: ips/pkgs/prim_mubi_pkg.sv:509:9
							out[k] = a_in[k] && b_in[k];
						else
							// Trace: ips/pkgs/prim_mubi_pkg.sv:511:9
							out[k] = a_in[k] || b_in[k];
					end
			end
			prim_mubi_pkg_mubi16_and = sv2v_cast_B8818(out);
		end
	endfunction
	function automatic [15:0] prim_mubi_pkg_mubi16_and_hi;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:527:45
		input reg [15:0] a;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:527:57
		input reg [15:0] b;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:528:5
		prim_mubi_pkg_mubi16_and_hi = prim_mubi_pkg_mubi16_and(a, b, sv2v_cast_B8818(16'h9696));
	endfunction
	function automatic [15:0] prim_mubi_pkg_mubi16_or;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:476:41
		input reg [15:0] a;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:476:53
		input reg [15:0] b;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:476:65
		input reg [15:0] act;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:477:5
		reg [15:0] a_in;
		reg [15:0] b_in;
		reg [15:0] act_in;
		reg [15:0] out;
		begin
			// Trace: ips/pkgs/prim_mubi_pkg.sv:478:5
			a_in = a;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:479:5
			b_in = b;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:480:5
			act_in = act;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:481:5
			begin : sv2v_autoblock_4
				// Trace: ips/pkgs/prim_mubi_pkg.sv:481:10
				reg signed [31:0] k;
				// Trace: ips/pkgs/prim_mubi_pkg.sv:481:10
				for (k = 0; k < prim_mubi_pkg_MuBi16Width; k = k + 1)
					begin
						// Trace: ips/pkgs/prim_mubi_pkg.sv:482:7
						if (act_in[k])
							// Trace: ips/pkgs/prim_mubi_pkg.sv:483:9
							out[k] = a_in[k] || b_in[k];
						else
							// Trace: ips/pkgs/prim_mubi_pkg.sv:485:9
							out[k] = a_in[k] && b_in[k];
					end
			end
			prim_mubi_pkg_mubi16_or = sv2v_cast_B8818(out);
		end
	endfunction
	function automatic [15:0] prim_mubi_pkg_mubi16_or_hi;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:520:44
		input reg [15:0] a;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:520:56
		input reg [15:0] b;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:521:5
		prim_mubi_pkg_mubi16_or_hi = prim_mubi_pkg_mubi16_or(a, b, sv2v_cast_B8818(16'h9696));
	endfunction
	function automatic [3:0] sv2v_cast_EECFA;
		input reg [3:0] inp;
		sv2v_cast_EECFA = inp;
	endfunction
	function automatic [3:0] prim_mubi_pkg_mubi4_and;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:106:40
		input reg [3:0] a;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:106:51
		input reg [3:0] b;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:106:62
		input reg [3:0] act;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:107:5
		reg [3:0] a_in;
		reg [3:0] b_in;
		reg [3:0] act_in;
		reg [3:0] out;
		begin
			// Trace: ips/pkgs/prim_mubi_pkg.sv:108:5
			a_in = a;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:109:5
			b_in = b;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:110:5
			act_in = act;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:111:5
			begin : sv2v_autoblock_5
				// Trace: ips/pkgs/prim_mubi_pkg.sv:111:10
				reg signed [31:0] k;
				// Trace: ips/pkgs/prim_mubi_pkg.sv:111:10
				for (k = 0; k < prim_mubi_pkg_MuBi4Width; k = k + 1)
					begin
						// Trace: ips/pkgs/prim_mubi_pkg.sv:112:7
						if (act_in[k])
							// Trace: ips/pkgs/prim_mubi_pkg.sv:113:9
							out[k] = a_in[k] && b_in[k];
						else
							// Trace: ips/pkgs/prim_mubi_pkg.sv:115:9
							out[k] = a_in[k] || b_in[k];
					end
			end
			prim_mubi_pkg_mubi4_and = sv2v_cast_EECFA(out);
		end
	endfunction
	function automatic [3:0] prim_mubi_pkg_mubi4_and_hi;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:131:43
		input reg [3:0] a;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:131:54
		input reg [3:0] b;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:132:5
		prim_mubi_pkg_mubi4_and_hi = prim_mubi_pkg_mubi4_and(a, b, sv2v_cast_EECFA(4'h6));
	endfunction
	function automatic [3:0] prim_mubi_pkg_mubi4_or;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:80:39
		input reg [3:0] a;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:80:50
		input reg [3:0] b;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:80:61
		input reg [3:0] act;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:81:5
		reg [3:0] a_in;
		reg [3:0] b_in;
		reg [3:0] act_in;
		reg [3:0] out;
		begin
			// Trace: ips/pkgs/prim_mubi_pkg.sv:82:5
			a_in = a;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:83:5
			b_in = b;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:84:5
			act_in = act;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:85:5
			begin : sv2v_autoblock_6
				// Trace: ips/pkgs/prim_mubi_pkg.sv:85:10
				reg signed [31:0] k;
				// Trace: ips/pkgs/prim_mubi_pkg.sv:85:10
				for (k = 0; k < prim_mubi_pkg_MuBi4Width; k = k + 1)
					begin
						// Trace: ips/pkgs/prim_mubi_pkg.sv:86:7
						if (act_in[k])
							// Trace: ips/pkgs/prim_mubi_pkg.sv:87:9
							out[k] = a_in[k] || b_in[k];
						else
							// Trace: ips/pkgs/prim_mubi_pkg.sv:89:9
							out[k] = a_in[k] && b_in[k];
					end
			end
			prim_mubi_pkg_mubi4_or = sv2v_cast_EECFA(out);
		end
	endfunction
	function automatic [3:0] prim_mubi_pkg_mubi4_or_hi;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:124:42
		input reg [3:0] a;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:124:53
		input reg [3:0] b;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:125:5
		prim_mubi_pkg_mubi4_or_hi = prim_mubi_pkg_mubi4_or(a, b, sv2v_cast_EECFA(4'h6));
	endfunction
	function automatic [7:0] sv2v_cast_FA5F6;
		input reg [7:0] inp;
		sv2v_cast_FA5F6 = inp;
	endfunction
	function automatic [7:0] prim_mubi_pkg_mubi8_and;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:238:40
		input reg [7:0] a;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:238:51
		input reg [7:0] b;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:238:62
		input reg [7:0] act;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:239:5
		reg [7:0] a_in;
		reg [7:0] b_in;
		reg [7:0] act_in;
		reg [7:0] out;
		begin
			// Trace: ips/pkgs/prim_mubi_pkg.sv:240:5
			a_in = a;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:241:5
			b_in = b;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:242:5
			act_in = act;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:243:5
			begin : sv2v_autoblock_7
				// Trace: ips/pkgs/prim_mubi_pkg.sv:243:10
				reg signed [31:0] k;
				// Trace: ips/pkgs/prim_mubi_pkg.sv:243:10
				for (k = 0; k < prim_mubi_pkg_MuBi8Width; k = k + 1)
					begin
						// Trace: ips/pkgs/prim_mubi_pkg.sv:244:7
						if (act_in[k])
							// Trace: ips/pkgs/prim_mubi_pkg.sv:245:9
							out[k] = a_in[k] && b_in[k];
						else
							// Trace: ips/pkgs/prim_mubi_pkg.sv:247:9
							out[k] = a_in[k] || b_in[k];
					end
			end
			prim_mubi_pkg_mubi8_and = sv2v_cast_FA5F6(out);
		end
	endfunction
	function automatic [7:0] prim_mubi_pkg_mubi8_and_hi;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:263:43
		input reg [7:0] a;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:263:54
		input reg [7:0] b;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:264:5
		prim_mubi_pkg_mubi8_and_hi = prim_mubi_pkg_mubi8_and(a, b, sv2v_cast_FA5F6(8'h96));
	endfunction
	function automatic [7:0] prim_mubi_pkg_mubi8_or;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:212:39
		input reg [7:0] a;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:212:50
		input reg [7:0] b;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:212:61
		input reg [7:0] act;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:213:5
		reg [7:0] a_in;
		reg [7:0] b_in;
		reg [7:0] act_in;
		reg [7:0] out;
		begin
			// Trace: ips/pkgs/prim_mubi_pkg.sv:214:5
			a_in = a;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:215:5
			b_in = b;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:216:5
			act_in = act;
			// Trace: ips/pkgs/prim_mubi_pkg.sv:217:5
			begin : sv2v_autoblock_8
				// Trace: ips/pkgs/prim_mubi_pkg.sv:217:10
				reg signed [31:0] k;
				// Trace: ips/pkgs/prim_mubi_pkg.sv:217:10
				for (k = 0; k < prim_mubi_pkg_MuBi8Width; k = k + 1)
					begin
						// Trace: ips/pkgs/prim_mubi_pkg.sv:218:7
						if (act_in[k])
							// Trace: ips/pkgs/prim_mubi_pkg.sv:219:9
							out[k] = a_in[k] || b_in[k];
						else
							// Trace: ips/pkgs/prim_mubi_pkg.sv:221:9
							out[k] = a_in[k] && b_in[k];
					end
			end
			prim_mubi_pkg_mubi8_or = sv2v_cast_FA5F6(out);
		end
	endfunction
	function automatic [7:0] prim_mubi_pkg_mubi8_or_hi;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:256:42
		input reg [7:0] a;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:256:53
		input reg [7:0] b;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:257:5
		prim_mubi_pkg_mubi8_or_hi = prim_mubi_pkg_mubi8_or(a, b, sv2v_cast_FA5F6(8'h96));
	endfunction
	generate
		if (|{SwAccess == 3'd0, SwAccess == 3'd2}) begin : gen_w
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:33:5
			assign wr_en = we | de;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:34:5
			assign wr_data = (we == 1'b1 ? wd : d);
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:36:5
			wire [DW - 1:0] unused_q;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:39:5
			assign unused_q = q;
		end
		else if (SwAccess == 3'd1) begin : gen_ro
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:43:5
			assign wr_en = de;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:44:5
			assign wr_data = d;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:46:5
			wire unused_we;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:47:5
			wire [DW - 1:0] unused_wd;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:48:5
			wire [DW - 1:0] unused_q;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:51:5
			assign unused_we = we;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:52:5
			assign unused_wd = wd;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:53:5
			assign unused_q = q;
		end
		else if (SwAccess == 3'd4) begin : gen_w1s
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:60:5
			assign wr_en = we | de;
			if (Mubi) begin : gen_mubi
				if (DW == 4) begin : gen_mubi4
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:63:9
					assign wr_data = prim_mubi_pkg_mubi4_or_hi(sv2v_cast_EECFA((de ? d : q)), (we ? sv2v_cast_EECFA(wd) : sv2v_cast_EECFA(4'h9)));
				end
				else if (DW == 8) begin : gen_mubi8
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:67:9
					assign wr_data = prim_mubi_pkg_mubi8_or_hi(sv2v_cast_FA5F6((de ? d : q)), (we ? sv2v_cast_FA5F6(wd) : sv2v_cast_FA5F6(8'h69)));
				end
				else if (DW == 12) begin : gen_mubi12
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:71:9
					assign wr_data = prim_mubi_pkg_mubi12_or_hi(sv2v_cast_9D81C((de ? d : q)), (we ? sv2v_cast_9D81C(wd) : sv2v_cast_9D81C(12'h969)));
				end
				else if (DW == 16) begin : gen_mubi16
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:75:9
					assign wr_data = prim_mubi_pkg_mubi16_or_hi(sv2v_cast_B8818((de ? d : q)), (we ? sv2v_cast_B8818(wd) : sv2v_cast_B8818(16'h6969)));
				end
				else begin : gen_invalid_mubi
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:79:9
					initial $display("Error [elaboration] ips/prim_opentitan/prim_subreg_arb.sv:79:9 - prim_subreg_arb.gen_w1s.gen_mubi.gen_invalid_mubi\n msg: ", "%m: Invalid width for MuBi");
				end
			end
			else begin : gen_non_mubi
				// Trace: ips/prim_opentitan/prim_subreg_arb.sv:82:7
				assign wr_data = (de ? d : q) | (we ? wd : {DW {1'sb0}});
			end
		end
		else if (SwAccess == 3'd3) begin : gen_w1c
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:88:5
			assign wr_en = we | de;
			if (Mubi) begin : gen_mubi
				if (DW == 4) begin : gen_mubi4
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:91:9
					assign wr_data = prim_mubi_pkg_mubi4_and_hi(sv2v_cast_EECFA((de ? d : q)), (we ? sv2v_cast_EECFA(~wd) : sv2v_cast_EECFA(4'h6)));
				end
				else if (DW == 8) begin : gen_mubi8
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:95:9
					assign wr_data = prim_mubi_pkg_mubi8_and_hi(sv2v_cast_FA5F6((de ? d : q)), (we ? sv2v_cast_FA5F6(~wd) : sv2v_cast_FA5F6(8'h96)));
				end
				else if (DW == 12) begin : gen_mubi12
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:99:9
					assign wr_data = prim_mubi_pkg_mubi12_and_hi(sv2v_cast_9D81C((de ? d : q)), (we ? sv2v_cast_9D81C(~wd) : sv2v_cast_9D81C(12'h696)));
				end
				else if (DW == 16) begin : gen_mubi16
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:103:9
					assign wr_data = prim_mubi_pkg_mubi16_and_hi(sv2v_cast_B8818((de ? d : q)), (we ? sv2v_cast_B8818(~wd) : sv2v_cast_B8818(16'h9696)));
				end
				else begin : gen_invalid_mubi
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:107:9
					initial $display("Error [elaboration] ips/prim_opentitan/prim_subreg_arb.sv:107:9 - prim_subreg_arb.gen_w1c.gen_mubi.gen_invalid_mubi\n msg: ", "%m: Invalid width for MuBi");
				end
			end
			else begin : gen_non_mubi
				// Trace: ips/prim_opentitan/prim_subreg_arb.sv:110:7
				assign wr_data = (de ? d : q) & (we ? ~wd : {DW {1'sb1}});
			end
		end
		else if (SwAccess == 3'd5) begin : gen_w0c
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:113:5
			assign wr_en = we | de;
			if (Mubi) begin : gen_mubi
				if (DW == 4) begin : gen_mubi4
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:116:9
					assign wr_data = prim_mubi_pkg_mubi4_and_hi(sv2v_cast_EECFA((de ? d : q)), (we ? sv2v_cast_EECFA(wd) : sv2v_cast_EECFA(4'h6)));
				end
				else if (DW == 8) begin : gen_mubi8
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:120:9
					assign wr_data = prim_mubi_pkg_mubi8_and_hi(sv2v_cast_FA5F6((de ? d : q)), (we ? sv2v_cast_FA5F6(wd) : sv2v_cast_FA5F6(8'h96)));
				end
				else if (DW == 12) begin : gen_mubi12
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:124:9
					assign wr_data = prim_mubi_pkg_mubi12_and_hi(sv2v_cast_9D81C((de ? d : q)), (we ? sv2v_cast_9D81C(wd) : sv2v_cast_9D81C(12'h696)));
				end
				else if (DW == 16) begin : gen_mubi16
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:128:9
					assign wr_data = prim_mubi_pkg_mubi16_and_hi(sv2v_cast_B8818((de ? d : q)), (we ? sv2v_cast_B8818(wd) : sv2v_cast_B8818(16'h9696)));
				end
				else begin : gen_invalid_mubi
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:132:9
					initial $display("Error [elaboration] ips/prim_opentitan/prim_subreg_arb.sv:132:9 - prim_subreg_arb.gen_w0c.gen_mubi.gen_invalid_mubi\n msg: ", "%m: Invalid width for MuBi");
				end
			end
			else begin : gen_non_mubi
				// Trace: ips/prim_opentitan/prim_subreg_arb.sv:135:7
				assign wr_data = (de ? d : q) & (we ? wd : {DW {1'sb1}});
			end
		end
		else if (SwAccess == 3'd6) begin : gen_rc
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:140:5
			assign wr_en = we | de;
			if (Mubi) begin : gen_mubi
				if (DW == 4) begin : gen_mubi4
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:143:9
					assign wr_data = prim_mubi_pkg_mubi4_and_hi(sv2v_cast_EECFA((de ? d : q)), (we ? sv2v_cast_EECFA(4'h9) : sv2v_cast_EECFA(4'h6)));
				end
				else if (DW == 8) begin : gen_mubi8
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:147:9
					assign wr_data = prim_mubi_pkg_mubi8_and_hi(sv2v_cast_FA5F6((de ? d : q)), (we ? sv2v_cast_FA5F6(8'h69) : sv2v_cast_FA5F6(8'h96)));
				end
				else if (DW == 12) begin : gen_mubi12
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:151:9
					assign wr_data = prim_mubi_pkg_mubi12_and_hi(sv2v_cast_9D81C((de ? d : q)), (we ? sv2v_cast_9D81C(12'h969) : sv2v_cast_9D81C(12'h696)));
				end
				else if (DW == 16) begin : gen_mubi16
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:155:9
					assign wr_data = prim_mubi_pkg_mubi16_and_hi(sv2v_cast_B8818((de ? d : q)), (we ? sv2v_cast_B8818(wd) : sv2v_cast_B8818(16'h9696)));
				end
				else begin : gen_invalid_mubi
					// Trace: ips/prim_opentitan/prim_subreg_arb.sv:159:9
					initial $display("Error [elaboration] ips/prim_opentitan/prim_subreg_arb.sv:159:9 - prim_subreg_arb.gen_rc.gen_mubi.gen_invalid_mubi\n msg: ", "%m: Invalid width for MuBi");
				end
			end
			else begin : gen_non_mubi
				// Trace: ips/prim_opentitan/prim_subreg_arb.sv:162:7
				assign wr_data = (de ? d : q) & (we ? {DW {1'sb0}} : {DW {1'sb1}});
			end
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:165:5
			wire [DW - 1:0] unused_wd;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:168:5
			assign unused_wd = wd;
		end
		else begin : gen_hw
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:172:5
			assign wr_en = de;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:173:5
			assign wr_data = d;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:175:5
			wire unused_we;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:176:5
			wire [DW - 1:0] unused_wd;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:177:5
			wire [DW - 1:0] unused_q;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:180:5
			assign unused_we = we;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:181:5
			assign unused_wd = wd;
			// Trace: ips/prim_opentitan/prim_subreg_arb.sv:182:5
			assign unused_q = q;
		end
	endgenerate
endmodule
module prim_subreg_ext (
	re,
	we,
	wd,
	d,
	qe,
	qre,
	q,
	ds,
	qs
);
	// Trace: ips/prim_opentitan/prim_subreg_ext.sv:8:13
	parameter [31:0] DW = 32;
	// Trace: ips/prim_opentitan/prim_subreg_ext.sv:10:3
	input re;
	// Trace: ips/prim_opentitan/prim_subreg_ext.sv:11:3
	input we;
	// Trace: ips/prim_opentitan/prim_subreg_ext.sv:12:3
	input [DW - 1:0] wd;
	// Trace: ips/prim_opentitan/prim_subreg_ext.sv:14:3
	input [DW - 1:0] d;
	// Trace: ips/prim_opentitan/prim_subreg_ext.sv:17:3
	output wire qe;
	// Trace: ips/prim_opentitan/prim_subreg_ext.sv:18:3
	output wire qre;
	// Trace: ips/prim_opentitan/prim_subreg_ext.sv:19:3
	output wire [DW - 1:0] q;
	// Trace: ips/prim_opentitan/prim_subreg_ext.sv:20:3
	output wire [DW - 1:0] ds;
	// Trace: ips/prim_opentitan/prim_subreg_ext.sv:21:3
	output wire [DW - 1:0] qs;
	// Trace: ips/prim_opentitan/prim_subreg_ext.sv:26:3
	assign ds = d;
	// Trace: ips/prim_opentitan/prim_subreg_ext.sv:27:3
	assign qs = d;
	// Trace: ips/prim_opentitan/prim_subreg_ext.sv:28:3
	assign q = wd;
	// Trace: ips/prim_opentitan/prim_subreg_ext.sv:29:3
	assign qe = we;
	// Trace: ips/prim_opentitan/prim_subreg_ext.sv:30:3
	assign qre = re;
endmodule
module prim_sync_reqack (
	clk_src_i,
	rst_src_ni,
	clk_dst_i,
	rst_dst_ni,
	req_chk_i,
	src_req_i,
	src_ack_o,
	dst_req_o,
	dst_ack_i
);
	reg _sv2v_0;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:35:13
	parameter [0:0] EnRstChks = 1'b0;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:36:13
	parameter [0:0] EnRzHs = 1'b0;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:40:3
	input clk_src_i;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:41:3
	input rst_src_ni;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:42:3
	input clk_dst_i;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:43:3
	input rst_dst_ni;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:45:3
	input wire req_chk_i;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:47:3
	input wire src_req_i;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:48:3
	output reg src_ack_o;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:49:3
	output reg dst_req_o;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:50:3
	input wire dst_ack_i;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:54:3
	wire unused_req_chk;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:55:3
	assign unused_req_chk = req_chk_i;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:57:3
	generate
		if (EnRzHs) begin : gen_rz_hs_protocol
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:63:5
			// removed localparam type rz_fsm_e
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:68:5
			reg src_fsm_d;
			reg src_fsm_q;
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:69:5
			reg dst_fsm_d;
			reg dst_fsm_q;
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:70:5
			wire src_ack;
			reg dst_ack;
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:71:5
			reg src_req;
			wire dst_req;
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:74:5
			always @(*) begin : src_fsm
				if (_sv2v_0)
					;
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:75:7
				src_fsm_d = src_fsm_q;
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:76:7
				src_ack_o = 1'b0;
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:77:7
				src_req = 1'b0;
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:79:7
				(* full_case, parallel_case *)
				case (src_fsm_q)
					1'd0:
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:83:11
						if (!src_ack && src_req_i)
							// Trace: ips/prim_opentitan/prim_sync_reqack.sv:84:13
							src_fsm_d = 1'd1;
					1'd1: begin
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:88:11
						src_req = 1'b1;
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:90:11
						src_ack_o = src_ack;
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:93:11
						if (!src_req_i || src_ack)
							// Trace: ips/prim_opentitan/prim_sync_reqack.sv:94:13
							src_fsm_d = 1'd0;
					end
					default:
						;
				endcase
			end
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:106:5
			prim_flop_2sync #(.Width(1)) ack_sync(
				.clk_i(clk_src_i),
				.rst_ni(rst_src_ni),
				.d_i(dst_ack),
				.q_o(src_ack)
			);
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:116:5
			always @(posedge clk_src_i or negedge rst_src_ni)
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:117:7
				if (!rst_src_ni)
					// Trace: ips/prim_opentitan/prim_sync_reqack.sv:118:9
					src_fsm_q <= 1'd0;
				else
					// Trace: ips/prim_opentitan/prim_sync_reqack.sv:120:9
					src_fsm_q <= src_fsm_d;
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:125:5
			always @(*) begin : dst_fsm
				if (_sv2v_0)
					;
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:126:7
				dst_fsm_d = dst_fsm_q;
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:127:7
				dst_req_o = 1'b0;
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:128:7
				dst_ack = 1'b0;
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:130:7
				(* full_case, parallel_case *)
				case (dst_fsm_q)
					1'd0:
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:132:11
						if (dst_req) begin
							// Trace: ips/prim_opentitan/prim_sync_reqack.sv:134:13
							dst_req_o = 1'b1;
							// Trace: ips/prim_opentitan/prim_sync_reqack.sv:137:13
							if (dst_ack_i)
								// Trace: ips/prim_opentitan/prim_sync_reqack.sv:138:15
								dst_fsm_d = 1'd1;
						end
					1'd1: begin
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:143:11
						dst_ack = 1'b1;
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:145:11
						if (!dst_req)
							// Trace: ips/prim_opentitan/prim_sync_reqack.sv:146:13
							dst_fsm_d = 1'd0;
					end
					default:
						;
				endcase
			end
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:158:5
			prim_flop_2sync #(.Width(1)) req_sync(
				.clk_i(clk_dst_i),
				.rst_ni(rst_dst_ni),
				.d_i(src_req),
				.q_o(dst_req)
			);
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:168:5
			always @(posedge clk_dst_i or negedge rst_dst_ni)
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:169:7
				if (!rst_dst_ni)
					// Trace: ips/prim_opentitan/prim_sync_reqack.sv:170:9
					dst_fsm_q <= 1'd0;
				else
					// Trace: ips/prim_opentitan/prim_sync_reqack.sv:172:9
					dst_fsm_q <= dst_fsm_d;
		end
		else begin : gen_nrz_hs_protocol
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:182:5
			// removed localparam type sync_reqack_fsm_e
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:187:5
			reg src_fsm_ns;
			reg src_fsm_cs;
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:188:5
			reg dst_fsm_ns;
			reg dst_fsm_cs;
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:190:5
			reg src_req_d;
			reg src_req_q;
			wire src_ack;
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:191:5
			reg dst_ack_d;
			reg dst_ack_q;
			wire dst_req;
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:192:5
			wire src_handshake;
			wire dst_handshake;
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:194:5
			assign src_handshake = src_req_i & src_ack_o;
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:195:5
			assign dst_handshake = dst_req_o & dst_ack_i;
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:198:5
			prim_flop_2sync #(.Width(1)) req_sync(
				.clk_i(clk_dst_i),
				.rst_ni(rst_dst_ni),
				.d_i(src_req_q),
				.q_o(dst_req)
			);
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:208:5
			prim_flop_2sync #(.Width(1)) ack_sync(
				.clk_i(clk_src_i),
				.rst_ni(rst_src_ni),
				.d_i(dst_ack_q),
				.q_o(src_ack)
			);
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:218:5
			always @(*) begin : src_fsm
				if (_sv2v_0)
					;
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:219:7
				src_fsm_ns = src_fsm_cs;
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:222:7
				src_req_d = src_req_q;
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:223:7
				src_ack_o = 1'b0;
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:225:7
				(* full_case, parallel_case *)
				case (src_fsm_cs)
					1'd0: begin
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:229:11
						src_req_d = src_req_i;
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:230:11
						src_ack_o = src_ack;
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:233:11
						if (src_handshake)
							// Trace: ips/prim_opentitan/prim_sync_reqack.sv:234:13
							src_fsm_ns = 1'd1;
					end
					1'd1: begin
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:241:11
						src_req_d = ~src_req_i;
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:242:11
						src_ack_o = ~src_ack;
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:245:11
						if (src_handshake)
							// Trace: ips/prim_opentitan/prim_sync_reqack.sv:246:13
							src_fsm_ns = 1'd0;
					end
					default:
						;
				endcase
			end
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:262:5
			always @(*) begin : dst_fsm
				if (_sv2v_0)
					;
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:263:7
				dst_fsm_ns = dst_fsm_cs;
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:266:7
				dst_req_o = 1'b0;
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:267:7
				dst_ack_d = dst_ack_q;
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:269:7
				(* full_case, parallel_case *)
				case (dst_fsm_cs)
					1'd0: begin
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:273:11
						dst_req_o = dst_req;
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:274:11
						dst_ack_d = dst_ack_i;
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:277:11
						if (dst_handshake)
							// Trace: ips/prim_opentitan/prim_sync_reqack.sv:278:13
							dst_fsm_ns = 1'd1;
					end
					1'd1: begin
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:285:11
						dst_req_o = ~dst_req;
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:286:11
						dst_ack_d = ~dst_ack_i;
						// Trace: ips/prim_opentitan/prim_sync_reqack.sv:289:11
						if (dst_handshake)
							// Trace: ips/prim_opentitan/prim_sync_reqack.sv:290:13
							dst_fsm_ns = 1'd0;
					end
					default:
						;
				endcase
			end
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:306:5
			always @(posedge clk_src_i or negedge rst_src_ni)
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:307:7
				if (!rst_src_ni) begin
					// Trace: ips/prim_opentitan/prim_sync_reqack.sv:308:9
					src_fsm_cs <= 1'd0;
					// Trace: ips/prim_opentitan/prim_sync_reqack.sv:309:9
					src_req_q <= 1'b0;
				end
				else begin
					// Trace: ips/prim_opentitan/prim_sync_reqack.sv:311:9
					src_fsm_cs <= src_fsm_ns;
					// Trace: ips/prim_opentitan/prim_sync_reqack.sv:312:9
					src_req_q <= src_req_d;
				end
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:315:5
			always @(posedge clk_dst_i or negedge rst_dst_ni)
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:316:7
				if (!rst_dst_ni) begin
					// Trace: ips/prim_opentitan/prim_sync_reqack.sv:317:9
					dst_fsm_cs <= 1'd0;
					// Trace: ips/prim_opentitan/prim_sync_reqack.sv:318:9
					dst_ack_q <= 1'b0;
				end
				else begin
					// Trace: ips/prim_opentitan/prim_sync_reqack.sv:320:9
					dst_fsm_cs <= dst_fsm_ns;
					// Trace: ips/prim_opentitan/prim_sync_reqack.sv:321:9
					dst_ack_q <= dst_ack_d;
				end
		end
	endgenerate
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:334:5
	wire effective_rst_n;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:335:5
	assign effective_rst_n = rst_src_ni && rst_dst_ni;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:337:5
	reg chk_flag;
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:338:5
	always @(posedge clk_src_i or negedge effective_rst_n)
		// Trace: ips/prim_opentitan/prim_sync_reqack.sv:339:7
		if (!effective_rst_n)
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:340:9
			chk_flag <= 1'sb0;
		else if (src_req_i && !chk_flag)
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:342:9
			chk_flag <= 1'b1;
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_sync_reqack.sv:350:88
	// removed an assertion item
	// SyncReqAckHoldReq : assert property (@(posedge clk_src_i) disable iff ((((!rst_src_ni || !rst_dst_ni) || !req_chk_i) || !chk_flag) !== '0)
	// 	(($fell(src_req_i) && req_chk_i) && chk_flag |-> $fell(src_ack_o))
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_sync_reqack.sv:350:643
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_sync_reqack.sv", 350, "SyncReqAckHoldReq");
	// end
	// Trace: macro expansion of ASSERT at ips/prim_opentitan/prim_sync_reqack.sv:355:52
	// removed an assertion item
	// SyncReqAckAckNeedsReq : assert property (@(posedge clk_dst_i) disable iff ((!rst_src_ni || !rst_dst_ni) !== '0)
	// 	(dst_ack_i |-> dst_req_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/prim_opentitan/prim_sync_reqack.sv:355:607
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/prim_opentitan/prim_sync_reqack.sv", 355, "SyncReqAckAckNeedsReq");
	// end
	// Trace: ips/prim_opentitan/prim_sync_reqack.sv:357:3
	generate
		if (EnRstChks) begin : gen_assert_en_rst_chks
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:371:5
			reg src_reset_flag;
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:372:5
			always @(posedge clk_src_i or negedge rst_src_ni)
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:373:7
				if (!rst_src_ni)
					// Trace: ips/prim_opentitan/prim_sync_reqack.sv:374:9
					src_reset_flag <= 1'sb0;
				else if (src_req_i)
					// Trace: ips/prim_opentitan/prim_sync_reqack.sv:376:9
					src_reset_flag <= 1'b1;
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:380:5
			reg dst_reset_flag;
			// Trace: ips/prim_opentitan/prim_sync_reqack.sv:381:5
			always @(posedge clk_dst_i or negedge rst_dst_ni)
				// Trace: ips/prim_opentitan/prim_sync_reqack.sv:382:7
				if (!rst_dst_ni)
					// Trace: ips/prim_opentitan/prim_sync_reqack.sv:383:9
					dst_reset_flag <= 1'sb0;
				else if (dst_req_o)
					// Trace: ips/prim_opentitan/prim_sync_reqack.sv:385:9
					dst_reset_flag <= 1'b1;
		end
	endgenerate
	initial _sv2v_0 = 0;
endmodule
module sram2tlul (
	clk_i,
	rst_ni,
	tl_o,
	tl_i,
	mem_req_i,
	mem_write_i,
	mem_addr_i,
	mem_wdata_i,
	mem_rvalid_o,
	mem_rdata_o,
	mem_error_o
);
	// Trace: ips/tlul/sram2tlul.sv:13:13
	parameter signed [31:0] SramAw = 12;
	// Trace: ips/tlul/sram2tlul.sv:14:13
	parameter signed [31:0] SramDw = 32;
	// Trace: ips/tlul/sram2tlul.sv:15:13
	localparam signed [31:0] top_pkg_TL_AW = 32;
	parameter [31:0] TlBaseAddr = 'h0;
	// Trace: ips/tlul/sram2tlul.sv:17:3
	input clk_i;
	// Trace: ips/tlul/sram2tlul.sv:18:3
	input rst_ni;
	// Trace: ips/tlul/sram2tlul.sv:20:3
	// removed localparam type tlul_pkg_tl_a_op_e
	localparam signed [31:0] prim_mubi_pkg_MuBi4Width = 4;
	// removed localparam type prim_mubi_pkg_mubi4_t
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	localparam signed [31:0] tlul_pkg_H2DCmdIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_a_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_DW = 32;
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_h2d_t
	output wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_o;
	// Trace: ips/tlul/sram2tlul.sv:21:3
	// removed localparam type tlul_pkg_tl_d_op_e
	localparam signed [31:0] tlul_pkg_D2HRspIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_d_user_t
	localparam signed [31:0] top_pkg_TL_DIW = 1;
	// removed localparam type tlul_pkg_tl_d2h_t
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_i;
	// Trace: ips/tlul/sram2tlul.sv:24:3
	input mem_req_i;
	// Trace: ips/tlul/sram2tlul.sv:25:3
	input mem_write_i;
	// Trace: ips/tlul/sram2tlul.sv:26:3
	input [SramAw - 1:0] mem_addr_i;
	// Trace: ips/tlul/sram2tlul.sv:27:3
	input [SramDw - 1:0] mem_wdata_i;
	// Trace: ips/tlul/sram2tlul.sv:28:3
	output wire mem_rvalid_o;
	// Trace: ips/tlul/sram2tlul.sv:29:3
	output wire [SramDw - 1:0] mem_rdata_o;
	// Trace: ips/tlul/sram2tlul.sv:30:3
	output wire [1:0] mem_error_o;
	// Trace: ips/tlul/sram2tlul.sv:33:3
	// removed import tlul_pkg::*;
	// Trace: macro expansion of ASSERT_INIT at ips/tlul/sram2tlul.sv:35:389
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/tlul/sram2tlul.sv:35:477
		begin : wrongSramDw
			
		end
	end
	// Trace: ips/tlul/sram2tlul.sv:37:3
	localparam [31:0] SRAM_DWB = $clog2(SramDw / 8);
	// Trace: ips/tlul/sram2tlul.sv:39:3
	assign tl_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] = mem_req_i;
	// Trace: ips/tlul/sram2tlul.sv:40:3
	assign tl_o[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] = (mem_write_i ? 3'h0 : 3'h4);
	// Trace: ips/tlul/sram2tlul.sv:41:3
	assign tl_o[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] = 1'sb0;
	// Trace: ips/tlul/sram2tlul.sv:42:3
	function automatic [top_pkg_TL_SZW - 1:0] sv2v_cast_FDEB5;
		input reg [top_pkg_TL_SZW - 1:0] inp;
		sv2v_cast_FDEB5 = inp;
	endfunction
	assign tl_o[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)] = sv2v_cast_FDEB5(SRAM_DWB);
	// Trace: ips/tlul/sram2tlul.sv:43:3
	assign tl_o[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)] = 1'sb0;
	// Trace: ips/tlul/sram2tlul.sv:44:3
	assign tl_o[top_pkg_TL_AW + (top_pkg_TL_DBW + 55)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)] = TlBaseAddr | {{(top_pkg_TL_AW - SramAw) - SRAM_DWB {1'b0}}, mem_addr_i, {SRAM_DWB {1'b0}}};
	// Trace: ips/tlul/sram2tlul.sv:46:3
	assign tl_o[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))] = 1'sb1;
	// Trace: ips/tlul/sram2tlul.sv:47:3
	assign tl_o[55-:32] = mem_wdata_i;
	// Trace: ips/tlul/sram2tlul.sv:48:3
	assign tl_o[23-:23] = 1'sb0;
	// Trace: ips/tlul/sram2tlul.sv:50:3
	assign tl_o[0] = 1'b1;
	// Trace: ips/tlul/sram2tlul.sv:52:3
	assign mem_rvalid_o = tl_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))] && (tl_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((6 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)] == 3'h1);
	// Trace: ips/tlul/sram2tlul.sv:53:3
	assign mem_rdata_o = tl_i[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)];
	// Trace: ips/tlul/sram2tlul.sv:54:3
	assign mem_error_o = {2 {tl_i[1]}};
	// Trace: macro expansion of ASSERT at ips/tlul/sram2tlul.sv:58:52
	// removed an assertion item
	// validNotReady : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(tl_o.a_valid |-> tl_i.a_ready)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/sram2tlul.sv:58:607
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/sram2tlul.sv", 58, "validNotReady");
	// end
endmodule
module tlul_adapter_host (
	clk_i,
	rst_ni,
	req_i,
	gnt_o,
	addr_i,
	we_i,
	wdata_i,
	wdata_intg_i,
	be_i,
	instr_type_i,
	valid_o,
	rdata_o,
	rdata_intg_o,
	err_o,
	intg_err_o,
	tl_o,
	tl_i
);
	reg _sv2v_0;
	// removed import tlul_pkg::*;
	// removed import prim_mubi_pkg::mubi4_t;
	// Trace: ips/tlul/tlul_adapter_host.sv:28:13
	parameter [31:0] MAX_REQS = 2;
	// Trace: ips/tlul/tlul_adapter_host.sv:29:13
	parameter [0:0] EnableCmdIntgGen = 0;
	// Trace: ips/tlul/tlul_adapter_host.sv:30:13
	parameter [0:0] EnableDataIntgGen = 0;
	// Trace: ips/tlul/tlul_adapter_host.sv:31:13
	parameter [0:0] EnableRspIntgCheck = 0;
	// Trace: ips/tlul/tlul_adapter_host.sv:32:13
	parameter [0:0] EnableRspDataIntgCheck = 0;
	// Trace: ips/tlul/tlul_adapter_host.sv:34:3
	input clk_i;
	// Trace: ips/tlul/tlul_adapter_host.sv:35:3
	input rst_ni;
	// Trace: ips/tlul/tlul_adapter_host.sv:37:3
	input req_i;
	// Trace: ips/tlul/tlul_adapter_host.sv:38:3
	output wire gnt_o;
	// Trace: ips/tlul/tlul_adapter_host.sv:39:3
	localparam signed [31:0] top_pkg_TL_AW = 32;
	input wire [31:0] addr_i;
	// Trace: ips/tlul/tlul_adapter_host.sv:40:3
	input wire we_i;
	// Trace: ips/tlul/tlul_adapter_host.sv:41:3
	localparam signed [31:0] top_pkg_TL_DW = 32;
	input wire [31:0] wdata_i;
	// Trace: ips/tlul/tlul_adapter_host.sv:42:3
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	input wire [6:0] wdata_intg_i;
	// Trace: ips/tlul/tlul_adapter_host.sv:43:3
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	input wire [top_pkg_TL_DBW - 1:0] be_i;
	// Trace: ips/tlul/tlul_adapter_host.sv:44:3
	localparam signed [31:0] prim_mubi_pkg_MuBi4Width = 4;
	// removed localparam type prim_mubi_pkg_mubi4_t
	input wire [3:0] instr_type_i;
	// Trace: ips/tlul/tlul_adapter_host.sv:46:3
	output wire valid_o;
	// Trace: ips/tlul/tlul_adapter_host.sv:47:3
	output wire [31:0] rdata_o;
	// Trace: ips/tlul/tlul_adapter_host.sv:48:3
	output wire [6:0] rdata_intg_o;
	// Trace: ips/tlul/tlul_adapter_host.sv:49:3
	output wire err_o;
	// Trace: ips/tlul/tlul_adapter_host.sv:50:3
	output wire intg_err_o;
	// Trace: ips/tlul/tlul_adapter_host.sv:52:3
	// removed localparam type tlul_pkg_tl_a_op_e
	localparam signed [31:0] tlul_pkg_H2DCmdIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_a_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_h2d_t
	output wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_o;
	// Trace: ips/tlul/tlul_adapter_host.sv:53:3
	// removed localparam type tlul_pkg_tl_d_op_e
	localparam signed [31:0] tlul_pkg_D2HRspIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_d_user_t
	localparam signed [31:0] top_pkg_TL_DIW = 1;
	// removed localparam type tlul_pkg_tl_d2h_t
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_i;
	// Trace: ips/tlul/tlul_adapter_host.sv:55:3
	localparam signed [31:0] WordSize = $clog2(top_pkg_TL_DBW);
	// Trace: ips/tlul/tlul_adapter_host.sv:57:3
	wire [7:0] tl_source;
	// Trace: ips/tlul/tlul_adapter_host.sv:58:3
	wire [top_pkg_TL_DBW - 1:0] tl_be;
	// Trace: ips/tlul/tlul_adapter_host.sv:59:3
	wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_out;
	// Trace: ips/tlul/tlul_adapter_host.sv:61:3
	function automatic [7:0] sv2v_cast_8;
		input reg [7:0] inp;
		sv2v_cast_8 = inp;
	endfunction
	generate
		if (MAX_REQS == 1) begin : g_single_req
			// Trace: ips/tlul/tlul_adapter_host.sv:62:5
			assign tl_source = 1'sb0;
		end
		else begin : g_multiple_reqs
			// Trace: ips/tlul/tlul_adapter_host.sv:64:5
			localparam signed [31:0] ReqNumW = $clog2(MAX_REQS);
			// Trace: ips/tlul/tlul_adapter_host.sv:65:5
			localparam [31:0] MaxSource = MAX_REQS - 1;
			// Trace: ips/tlul/tlul_adapter_host.sv:66:5
			localparam [ReqNumW - 1:0] ReqNumOne = 'd1;
			// Trace: ips/tlul/tlul_adapter_host.sv:68:5
			reg [ReqNumW - 1:0] source_d;
			// Trace: ips/tlul/tlul_adapter_host.sv:69:5
			reg [ReqNumW - 1:0] source_q;
			// Trace: ips/tlul/tlul_adapter_host.sv:71:5
			always @(posedge clk_i or negedge rst_ni)
				// Trace: ips/tlul/tlul_adapter_host.sv:72:7
				if (!rst_ni)
					// Trace: ips/tlul/tlul_adapter_host.sv:73:9
					source_q <= 1'sb0;
				else
					// Trace: ips/tlul/tlul_adapter_host.sv:75:9
					source_q <= source_d;
			// Trace: ips/tlul/tlul_adapter_host.sv:79:5
			always @(*) begin
				if (_sv2v_0)
					;
				// Trace: ips/tlul/tlul_adapter_host.sv:80:7
				source_d = source_q;
				// Trace: ips/tlul/tlul_adapter_host.sv:82:7
				if (req_i && gnt_o) begin
					begin
						// Trace: ips/tlul/tlul_adapter_host.sv:83:9
						if (source_q == MaxSource[ReqNumW - 1:0])
							// Trace: ips/tlul/tlul_adapter_host.sv:84:11
							source_d = 1'sb0;
						else
							// Trace: ips/tlul/tlul_adapter_host.sv:86:11
							source_d = source_q + ReqNumOne;
					end
				end
			end
			// Trace: ips/tlul/tlul_adapter_host.sv:91:5
			assign tl_source = sv2v_cast_8(source_q);
		end
	endgenerate
	// Trace: ips/tlul/tlul_adapter_host.sv:96:3
	assign tl_be = (~we_i ? {top_pkg_TL_DBW {1'b1}} : be_i);
	// Trace: ips/tlul/tlul_adapter_host.sv:98:3
	function automatic signed [top_pkg_TL_SZW - 1:0] sv2v_cast_FDEB5_signed;
		input reg signed [top_pkg_TL_SZW - 1:0] inp;
		sv2v_cast_FDEB5_signed = inp;
	endfunction
	function automatic [3:0] sv2v_cast_EECFA;
		input reg [3:0] inp;
		sv2v_cast_EECFA = inp;
	endfunction
	function automatic [6:0] sv2v_cast_8CACC;
		input reg [6:0] inp;
		sv2v_cast_8CACC = inp;
	endfunction
	function automatic [6:0] sv2v_cast_83AAC;
		input reg [6:0] inp;
		sv2v_cast_83AAC = inp;
	endfunction
	function automatic [top_pkg_TL_SZW - 1:0] sv2v_cast_FDEB5;
		input reg [top_pkg_TL_SZW - 1:0] inp;
		sv2v_cast_FDEB5 = inp;
	endfunction
	function automatic [7:0] sv2v_cast_15E34;
		input reg [7:0] inp;
		sv2v_cast_15E34 = inp;
	endfunction
	function automatic [31:0] sv2v_cast_D591E;
		input reg [31:0] inp;
		sv2v_cast_D591E = inp;
	endfunction
	function automatic [top_pkg_TL_DBW - 1:0] sv2v_cast_B0D6A;
		input reg [top_pkg_TL_DBW - 1:0] inp;
		sv2v_cast_B0D6A = inp;
	endfunction
	function automatic [31:0] sv2v_cast_9783B;
		input reg [31:0] inp;
		sv2v_cast_9783B = inp;
	endfunction
	function automatic [22:0] sv2v_cast_EDEFC;
		input reg [22:0] inp;
		sv2v_cast_EDEFC = inp;
	endfunction
	assign tl_out = {req_i, (~we_i ? 3'h4 : (&be_i ? 3'h0 : 3'h1)), 3'h0, sv2v_cast_FDEB5(sv2v_cast_FDEB5_signed(WordSize)), sv2v_cast_15E34(tl_source), sv2v_cast_D591E({addr_i[31:WordSize], {WordSize {1'b0}}}), sv2v_cast_B0D6A(tl_be), sv2v_cast_9783B(wdata_i), sv2v_cast_EDEFC({5'b00000, sv2v_cast_EECFA(instr_type_i), sv2v_cast_8CACC(1'sb0), sv2v_cast_83AAC(wdata_intg_i)}), 1'b1};
	// Trace: ips/tlul/tlul_adapter_host.sv:113:3
	tlul_cmd_intg_gen #(
		.EnableCmdIntgGen(EnableCmdIntgGen),
		.EnableDataIntgGen(EnableDataIntgGen)
	) u_cmd_intg_gen(
		.tl_i(tl_out),
		.tl_o(tl_o)
	);
	// Trace: ips/tlul/tlul_adapter_host.sv:121:3
	assign gnt_o = tl_i[0];
	// Trace: ips/tlul/tlul_adapter_host.sv:123:3
	assign valid_o = tl_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))];
	// Trace: ips/tlul/tlul_adapter_host.sv:124:3
	assign rdata_o = tl_i[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)];
	// Trace: ips/tlul/tlul_adapter_host.sv:125:3
	assign rdata_intg_o = tl_i[((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) - 7)-:tlul_pkg_DataIntgWidth];
	// Trace: ips/tlul/tlul_adapter_host.sv:128:3
	reg intg_err_q;
	// Trace: ips/tlul/tlul_adapter_host.sv:129:3
	wire intg_err;
	// Trace: ips/tlul/tlul_adapter_host.sv:130:3
	generate
		if (EnableRspIntgCheck) begin : gen_rsp_intg_check
			// Trace: ips/tlul/tlul_adapter_host.sv:131:5
			tlul_rsp_intg_chk #(.EnableRspDataIntgCheck(EnableRspDataIntgCheck)) u_rsp_chk(
				.tl_i(tl_i),
				.err_o(intg_err)
			);
			// Trace: ips/tlul/tlul_adapter_host.sv:138:5
			always @(posedge clk_i or negedge rst_ni)
				// Trace: ips/tlul/tlul_adapter_host.sv:139:7
				if (!rst_ni)
					// Trace: ips/tlul/tlul_adapter_host.sv:140:9
					intg_err_q <= 1'sb0;
				else if (intg_err)
					// Trace: ips/tlul/tlul_adapter_host.sv:142:9
					intg_err_q <= 1'b1;
		end
		else begin : gen_no_rsp_intg_check
			// Trace: ips/tlul/tlul_adapter_host.sv:146:5
			assign intg_err = 1'b0;
			// Trace: ips/tlul/tlul_adapter_host.sv:147:5
			wire [1:1] sv2v_tmp_E222D;
			assign sv2v_tmp_E222D = 1'b0;
			always @(*) intg_err_q = sv2v_tmp_E222D;
		end
	endgenerate
	// Trace: ips/tlul/tlul_adapter_host.sv:152:3
	assign err_o = tl_i[1] | intg_err;
	// Trace: ips/tlul/tlul_adapter_host.sv:156:3
	assign intg_err_o = intg_err_q | intg_err;
	// Trace: ips/tlul/tlul_adapter_host.sv:159:3
	wire unused_addr_bottom_bits;
	// Trace: ips/tlul/tlul_adapter_host.sv:160:3
	assign unused_addr_bottom_bits = ^addr_i[WordSize - 1:0];
	// Trace: ips/tlul/tlul_adapter_host.sv:163:3
	wire unused_tl_i_fields;
	// Trace: ips/tlul/tlul_adapter_host.sv:164:3
	assign unused_tl_i_fields = ^{tl_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((6 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)], tl_i[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)], tl_i[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))-:((top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)))) >= (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) + 1)], tl_i[top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))-:((32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))) >= ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) + 1 : ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) + 1)], tl_i[top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))-:(((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)) >= (32'sd32 + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) + 1 : ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) + 1)], tl_i[(tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1-:(((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) >= 2 ? (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 0 : 3 - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))]};
	// Trace: ips/tlul/tlul_adapter_host.sv:171:3
	localparam signed [31:0] OutstandingReqCntW = (MAX_REQS == (2 ** $clog2(MAX_REQS)) ? $clog2(MAX_REQS) + 1 : $clog2(MAX_REQS));
	// Trace: ips/tlul/tlul_adapter_host.sv:173:3
	function automatic [OutstandingReqCntW - 1:0] sv2v_cast_D6E3D;
		input reg [OutstandingReqCntW - 1:0] inp;
		sv2v_cast_D6E3D = inp;
	endfunction
	localparam [OutstandingReqCntW - 1:0] OutstandingReqCntOne = sv2v_cast_D6E3D(1'b1);
	// Trace: ips/tlul/tlul_adapter_host.sv:175:3
	reg [OutstandingReqCntW - 1:0] outstanding_reqs_q;
	// Trace: ips/tlul/tlul_adapter_host.sv:176:3
	reg [OutstandingReqCntW - 1:0] outstanding_reqs_d;
	// Trace: ips/tlul/tlul_adapter_host.sv:178:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: ips/tlul/tlul_adapter_host.sv:179:5
		outstanding_reqs_d = outstanding_reqs_q;
		// Trace: ips/tlul/tlul_adapter_host.sv:181:5
		if ((req_i && gnt_o) && !valid_o)
			// Trace: ips/tlul/tlul_adapter_host.sv:182:7
			outstanding_reqs_d = outstanding_reqs_q + OutstandingReqCntOne;
		else if (!(req_i && gnt_o) && valid_o)
			// Trace: ips/tlul/tlul_adapter_host.sv:184:7
			outstanding_reqs_d = outstanding_reqs_q - OutstandingReqCntOne;
	end
	// Trace: ips/tlul/tlul_adapter_host.sv:188:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: ips/tlul/tlul_adapter_host.sv:189:5
		if (!rst_ni)
			// Trace: ips/tlul/tlul_adapter_host.sv:190:7
			outstanding_reqs_q <= 1'sb0;
		else
			// Trace: ips/tlul/tlul_adapter_host.sv:192:7
			outstanding_reqs_q <= outstanding_reqs_d;
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_adapter_host.sv:198:68
	// removed an assertion item
	// DontExceeedMaxReqs : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(req_i |-> outstanding_reqs_d <= MAX_REQS)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_adapter_host.sv:198:623
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_adapter_host.sv", 198, "DontExceeedMaxReqs");
	// end
	initial _sv2v_0 = 0;
endmodule
module tlul_adapter_reg (
	clk_i,
	rst_ni,
	tl_i,
	tl_o,
	en_ifetch_i,
	intg_error_o,
	re_o,
	we_o,
	addr_o,
	wdata_o,
	be_o,
	busy_i,
	rdata_i,
	error_i
);
	reg _sv2v_0;
	// removed import tlul_pkg::*;
	// removed import prim_mubi_pkg::mubi4_t;
	// Trace: ips/tlul/tlul_adapter_reg.sv:23:14
	parameter [0:0] CmdIntgCheck = 0;
	// Trace: ips/tlul/tlul_adapter_reg.sv:24:14
	parameter [0:0] EnableRspIntgGen = 0;
	// Trace: ips/tlul/tlul_adapter_reg.sv:25:14
	parameter [0:0] EnableDataIntgGen = 0;
	// Trace: ips/tlul/tlul_adapter_reg.sv:26:14
	parameter signed [31:0] RegAw = 8;
	// Trace: ips/tlul/tlul_adapter_reg.sv:27:14
	parameter signed [31:0] RegDw = 32;
	// Trace: ips/tlul/tlul_adapter_reg.sv:28:14
	parameter signed [31:0] AccessLatency = 0;
	// Trace: ips/tlul/tlul_adapter_reg.sv:29:14
	localparam signed [31:0] RegBw = RegDw / 8;
	// Trace: ips/tlul/tlul_adapter_reg.sv:31:3
	input clk_i;
	// Trace: ips/tlul/tlul_adapter_reg.sv:32:3
	input rst_ni;
	// Trace: ips/tlul/tlul_adapter_reg.sv:35:3
	// removed localparam type tlul_pkg_tl_a_op_e
	localparam signed [31:0] prim_mubi_pkg_MuBi4Width = 4;
	// removed localparam type prim_mubi_pkg_mubi4_t
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	localparam signed [31:0] tlul_pkg_H2DCmdIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_a_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_AW = 32;
	localparam signed [31:0] top_pkg_TL_DW = 32;
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_h2d_t
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_i;
	// Trace: ips/tlul/tlul_adapter_reg.sv:36:3
	// removed localparam type tlul_pkg_tl_d_op_e
	localparam signed [31:0] tlul_pkg_D2HRspIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_d_user_t
	localparam signed [31:0] top_pkg_TL_DIW = 1;
	// removed localparam type tlul_pkg_tl_d2h_t
	output wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_o;
	// Trace: ips/tlul/tlul_adapter_reg.sv:39:3
	input wire [3:0] en_ifetch_i;
	// Trace: ips/tlul/tlul_adapter_reg.sv:40:3
	output wire intg_error_o;
	// Trace: ips/tlul/tlul_adapter_reg.sv:43:3
	output wire re_o;
	// Trace: ips/tlul/tlul_adapter_reg.sv:44:3
	output wire we_o;
	// Trace: ips/tlul/tlul_adapter_reg.sv:45:3
	output wire [RegAw - 1:0] addr_o;
	// Trace: ips/tlul/tlul_adapter_reg.sv:46:3
	output wire [RegDw - 1:0] wdata_o;
	// Trace: ips/tlul/tlul_adapter_reg.sv:47:3
	output wire [RegBw - 1:0] be_o;
	// Trace: ips/tlul/tlul_adapter_reg.sv:48:3
	input busy_i;
	// Trace: ips/tlul/tlul_adapter_reg.sv:51:3
	input [RegDw - 1:0] rdata_i;
	// Trace: ips/tlul/tlul_adapter_reg.sv:53:3
	input error_i;
	// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_adapter_reg.sv:56:397
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_adapter_reg.sv:56:485
		begin : AllowedLatency_A
			
		end
	end
	// Trace: ips/tlul/tlul_adapter_reg.sv:58:3
	localparam signed [31:0] IW = top_pkg_TL_AIW;
	// Trace: ips/tlul/tlul_adapter_reg.sv:59:3
	localparam signed [31:0] SZW = top_pkg_TL_SZW;
	// Trace: ips/tlul/tlul_adapter_reg.sv:61:3
	reg outstanding_q;
	// Trace: ips/tlul/tlul_adapter_reg.sv:62:3
	wire a_ack;
	wire d_ack;
	// Trace: ips/tlul/tlul_adapter_reg.sv:64:3
	wire [RegDw - 1:0] rdata;
	reg [RegDw - 1:0] rdata_q;
	// Trace: ips/tlul/tlul_adapter_reg.sv:65:3
	reg error_q;
	wire error;
	wire err_internal;
	wire instr_error;
	wire intg_error;
	// Trace: ips/tlul/tlul_adapter_reg.sv:67:3
	reg addr_align_err;
	// Trace: ips/tlul/tlul_adapter_reg.sv:68:3
	wire malformed_meta_err;
	// Trace: ips/tlul/tlul_adapter_reg.sv:69:3
	wire tl_err;
	// Trace: ips/tlul/tlul_adapter_reg.sv:71:3
	reg [7:0] reqid_q;
	// Trace: ips/tlul/tlul_adapter_reg.sv:72:3
	reg [SZW - 1:0] reqsz_q;
	// Trace: ips/tlul/tlul_adapter_reg.sv:73:3
	reg [2:0] rspop_q;
	// Trace: ips/tlul/tlul_adapter_reg.sv:75:3
	wire rd_req;
	wire wr_req;
	// Trace: ips/tlul/tlul_adapter_reg.sv:77:3
	assign a_ack = tl_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] & tl_o[0];
	// Trace: ips/tlul/tlul_adapter_reg.sv:78:3
	assign d_ack = tl_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))] & tl_i[0];
	// Trace: ips/tlul/tlul_adapter_reg.sv:80:3
	assign wr_req = a_ack & ((tl_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] == 3'h0) | (tl_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] == 3'h1));
	// Trace: ips/tlul/tlul_adapter_reg.sv:81:3
	assign rd_req = a_ack & (tl_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] == 3'h4);
	// Trace: ips/tlul/tlul_adapter_reg.sv:83:3
	assign we_o = wr_req & ~err_internal;
	// Trace: ips/tlul/tlul_adapter_reg.sv:84:3
	assign re_o = rd_req & ~err_internal;
	// Trace: ips/tlul/tlul_adapter_reg.sv:85:3
	assign wdata_o = tl_i[55-:32];
	// Trace: ips/tlul/tlul_adapter_reg.sv:86:3
	assign be_o = tl_i[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))];
	// Trace: ips/tlul/tlul_adapter_reg.sv:88:3
	generate
		if (RegAw <= 2) begin : gen_only_one_reg
			// Trace: ips/tlul/tlul_adapter_reg.sv:89:5
			assign addr_o = 1'sb0;
		end
		else begin : gen_more_regs
			// Trace: ips/tlul/tlul_adapter_reg.sv:91:5
			assign addr_o = {tl_i[(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (32 - RegAw):(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - 29], 2'b00};
		end
	endgenerate
	// Trace: ips/tlul/tlul_adapter_reg.sv:94:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: ips/tlul/tlul_adapter_reg.sv:95:5
		if (!rst_ni)
			// Trace: ips/tlul/tlul_adapter_reg.sv:95:21
			outstanding_q <= 1'b0;
		else if (a_ack)
			// Trace: ips/tlul/tlul_adapter_reg.sv:96:21
			outstanding_q <= 1'b1;
		else if (d_ack)
			// Trace: ips/tlul/tlul_adapter_reg.sv:97:21
			outstanding_q <= 1'b0;
	// Trace: ips/tlul/tlul_adapter_reg.sv:100:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: ips/tlul/tlul_adapter_reg.sv:101:5
		if (!rst_ni) begin
			// Trace: ips/tlul/tlul_adapter_reg.sv:102:7
			reqid_q <= 1'sb0;
			// Trace: ips/tlul/tlul_adapter_reg.sv:103:7
			reqsz_q <= 1'sb0;
			// Trace: ips/tlul/tlul_adapter_reg.sv:104:7
			rspop_q <= 3'h0;
		end
		else if (a_ack) begin
			// Trace: ips/tlul/tlul_adapter_reg.sv:106:7
			reqid_q <= tl_i[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)];
			// Trace: ips/tlul/tlul_adapter_reg.sv:107:7
			reqsz_q <= tl_i[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)];
			// Trace: ips/tlul/tlul_adapter_reg.sv:109:7
			rspop_q <= (rd_req ? 3'h1 : 3'h0);
		end
	// Trace: ips/tlul/tlul_adapter_reg.sv:113:3
	generate
		if (AccessLatency == 1) begin : gen_access_latency1
			// Trace: ips/tlul/tlul_adapter_reg.sv:114:5
			reg wr_req_q;
			reg rd_req_q;
			// Trace: ips/tlul/tlul_adapter_reg.sv:115:5
			always @(posedge clk_i or negedge rst_ni)
				// Trace: ips/tlul/tlul_adapter_reg.sv:116:7
				if (!rst_ni) begin
					// Trace: ips/tlul/tlul_adapter_reg.sv:117:9
					rdata_q <= 1'sb0;
					// Trace: ips/tlul/tlul_adapter_reg.sv:118:9
					error_q <= 1'b0;
					// Trace: ips/tlul/tlul_adapter_reg.sv:119:9
					wr_req_q <= 1'b0;
					// Trace: ips/tlul/tlul_adapter_reg.sv:120:9
					rd_req_q <= 1'b0;
				end
				else begin
					// Trace: ips/tlul/tlul_adapter_reg.sv:122:9
					rd_req_q <= rd_req;
					// Trace: ips/tlul/tlul_adapter_reg.sv:123:9
					wr_req_q <= wr_req;
					// Trace: ips/tlul/tlul_adapter_reg.sv:125:9
					if (a_ack)
						// Trace: ips/tlul/tlul_adapter_reg.sv:126:11
						error_q <= err_internal;
					else begin
						// Trace: ips/tlul/tlul_adapter_reg.sv:129:11
						error_q <= error;
						// Trace: ips/tlul/tlul_adapter_reg.sv:130:11
						rdata_q <= rdata;
					end
				end
			// Trace: ips/tlul/tlul_adapter_reg.sv:134:5
			assign rdata = ((error_i || error_q) || wr_req_q ? {RegDw {1'sb1}} : (rd_req_q ? rdata_i : rdata_q));
			// Trace: ips/tlul/tlul_adapter_reg.sv:137:5
			assign error = (rd_req_q || wr_req_q ? error_q || error_i : error_q);
		end
		else begin : gen_access_latency0
			// Trace: ips/tlul/tlul_adapter_reg.sv:140:5
			always @(posedge clk_i or negedge rst_ni)
				// Trace: ips/tlul/tlul_adapter_reg.sv:141:7
				if (!rst_ni) begin
					// Trace: ips/tlul/tlul_adapter_reg.sv:142:9
					rdata_q <= 1'sb0;
					// Trace: ips/tlul/tlul_adapter_reg.sv:143:9
					error_q <= 1'b0;
				end
				else if (a_ack) begin
					// Trace: ips/tlul/tlul_adapter_reg.sv:145:9
					rdata_q <= ((error_i || err_internal) || wr_req ? {RegDw {1'sb1}} : rdata_i);
					// Trace: ips/tlul/tlul_adapter_reg.sv:146:9
					error_q <= error_i || err_internal;
				end
			// Trace: ips/tlul/tlul_adapter_reg.sv:149:5
			assign rdata = rdata_q;
			// Trace: ips/tlul/tlul_adapter_reg.sv:150:5
			assign error = error_q;
		end
	endgenerate
	// Trace: ips/tlul/tlul_adapter_reg.sv:153:3
	wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_o_pre;
	// Trace: ips/tlul/tlul_adapter_reg.sv:154:3
	function automatic [top_pkg_TL_SZW - 1:0] sv2v_cast_FDEB5;
		input reg [top_pkg_TL_SZW - 1:0] inp;
		sv2v_cast_FDEB5 = inp;
	endfunction
	function automatic [7:0] sv2v_cast_15E34;
		input reg [7:0] inp;
		sv2v_cast_15E34 = inp;
	endfunction
	function automatic [0:0] sv2v_cast_17D81;
		input reg [0:0] inp;
		sv2v_cast_17D81 = inp;
	endfunction
	function automatic [31:0] sv2v_cast_9783B;
		input reg [31:0] inp;
		sv2v_cast_9783B = inp;
	endfunction
	function automatic [(tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) - 1:0] sv2v_cast_11E70;
		input reg [(tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) - 1:0] inp;
		sv2v_cast_11E70 = inp;
	endfunction
	function automatic [0:0] sv2v_cast_1;
		input reg [0:0] inp;
		sv2v_cast_1 = inp;
	endfunction
	assign tl_o_pre = {outstanding_q, rspop_q, 3'b000, sv2v_cast_FDEB5(reqsz_q), sv2v_cast_15E34(reqid_q), sv2v_cast_17D81(1'sb0), sv2v_cast_9783B(rdata), sv2v_cast_11E70(1'sb0), error, sv2v_cast_1(~(outstanding_q | (tl_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] & busy_i)))};
	// Trace: ips/tlul/tlul_adapter_reg.sv:170:3
	tlul_rsp_intg_gen #(
		.EnableRspIntgGen(EnableRspIntgGen),
		.EnableDataIntgGen(EnableDataIntgGen)
	) u_rsp_intg_gen(
		.tl_i(tl_o_pre),
		.tl_o(tl_o)
	);
	// Trace: ips/tlul/tlul_adapter_reg.sv:178:3
	generate
		if (CmdIntgCheck) begin : gen_cmd_intg_check
			// Trace: ips/tlul/tlul_adapter_reg.sv:179:5
			reg intg_error_q;
			// Trace: ips/tlul/tlul_adapter_reg.sv:180:5
			tlul_cmd_intg_chk u_cmd_intg_chk(
				.tl_i(tl_i),
				.err_o(intg_error)
			);
			// Trace: ips/tlul/tlul_adapter_reg.sv:185:5
			always @(posedge clk_i or negedge rst_ni)
				// Trace: ips/tlul/tlul_adapter_reg.sv:186:7
				if (!rst_ni)
					// Trace: ips/tlul/tlul_adapter_reg.sv:187:9
					intg_error_q <= 1'b0;
				else if (intg_error)
					// Trace: ips/tlul/tlul_adapter_reg.sv:189:9
					intg_error_q <= 1'b1;
			// Trace: ips/tlul/tlul_adapter_reg.sv:192:5
			assign intg_error_o = intg_error_q;
		end
		else begin : gen_no_cmd_intg_check
			// Trace: ips/tlul/tlul_adapter_reg.sv:194:5
			assign intg_error = 1'b0;
			// Trace: ips/tlul/tlul_adapter_reg.sv:195:5
			assign intg_error_o = 1'b0;
		end
	endgenerate
	// Trace: ips/tlul/tlul_adapter_reg.sv:204:3
	function automatic [3:0] sv2v_cast_EECFA;
		input reg [3:0] inp;
		sv2v_cast_EECFA = inp;
	endfunction
	function automatic prim_mubi_pkg_mubi4_test_false_loose;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:64:51
		input reg [3:0] val;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:65:5
		prim_mubi_pkg_mubi4_test_false_loose = sv2v_cast_EECFA(4'h6) != val;
	endfunction
	function automatic prim_mubi_pkg_mubi4_test_invalid;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:31:47
		input reg [3:0] val;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:32:5
		prim_mubi_pkg_mubi4_test_invalid = ~(|{((sv2v_cast_EECFA(4'h6) ^ (val ^ val)) === (val ^ (sv2v_cast_EECFA(4'h6) ^ sv2v_cast_EECFA(4'h6)))) & ((((val ^ val) ^ (sv2v_cast_EECFA(4'h6) ^ sv2v_cast_EECFA(4'h6))) === (sv2v_cast_EECFA(4'h6) ^ sv2v_cast_EECFA(4'h6))) | 1'bx), ((sv2v_cast_EECFA(4'h9) ^ (val ^ val)) === (val ^ (sv2v_cast_EECFA(4'h9) ^ sv2v_cast_EECFA(4'h9)))) & ((((val ^ val) ^ (sv2v_cast_EECFA(4'h9) ^ sv2v_cast_EECFA(4'h9))) === (sv2v_cast_EECFA(4'h9) ^ sv2v_cast_EECFA(4'h9))) | 1'bx)});
	endfunction
	function automatic prim_mubi_pkg_mubi4_test_true_strict;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:43:51
		input reg [3:0] val;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:44:5
		prim_mubi_pkg_mubi4_test_true_strict = sv2v_cast_EECFA(4'h6) == val;
	endfunction
	assign instr_error = prim_mubi_pkg_mubi4_test_invalid(tl_i[18-:4]) | (prim_mubi_pkg_mubi4_test_true_strict(tl_i[18-:4]) & prim_mubi_pkg_mubi4_test_false_loose(en_ifetch_i));
	// Trace: ips/tlul/tlul_adapter_reg.sv:209:3
	assign err_internal = addr_align_err;
	// Trace: ips/tlul/tlul_adapter_reg.sv:212:3
	function automatic tlul_pkg_tl_a_user_chk;
		// Trace: ips/pkgs/tlul_pkg.sv:139:42
		input reg [22:0] user;
		// Trace: ips/pkgs/tlul_pkg.sv:140:5
		reg malformed_err;
		// Trace: ips/pkgs/tlul_pkg.sv:141:5
		reg unused_user;
		begin
			// Trace: ips/pkgs/tlul_pkg.sv:142:5
			unused_user = |user;
			// Trace: ips/pkgs/tlul_pkg.sv:143:5
			malformed_err = prim_mubi_pkg_mubi4_test_invalid(user[17-:4]);
			// Trace: ips/pkgs/tlul_pkg.sv:144:5
			tlul_pkg_tl_a_user_chk = malformed_err;
		end
	endfunction
	assign malformed_meta_err = tlul_pkg_tl_a_user_chk(tl_i[23-:23]);
	// Trace: ips/tlul/tlul_adapter_reg.sv:218:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: ips/tlul/tlul_adapter_reg.sv:219:5
		if (wr_req)
			// Trace: ips/tlul/tlul_adapter_reg.sv:221:7
			addr_align_err = |tl_i[(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - 30:(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - 31];
		else
			// Trace: ips/tlul/tlul_adapter_reg.sv:224:7
			addr_align_err = 1'b0;
	end
	// Trace: ips/tlul/tlul_adapter_reg.sv:229:3
	tlul_err u_err(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.tl_i(tl_i),
		.err_o(tl_err)
	);
	// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_adapter_reg.sv:236:395
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_adapter_reg.sv:236:483
		begin : MatchedWidthAssert
			
		end
	end
	initial _sv2v_0 = 0;
endmodule
module tlul_adapter_sram (
	clk_i,
	rst_ni,
	tl_i,
	tl_o,
	en_ifetch_i,
	req_o,
	req_type_o,
	gnt_i,
	we_o,
	addr_o,
	wdata_o,
	wmask_o,
	intg_error_o,
	rdata_i,
	rvalid_i,
	rerror_i,
	compound_txn_in_progress_o,
	readback_en_i,
	readback_error_o,
	wr_collision_i,
	write_pending_i
);
	reg _sv2v_0;
	// removed import tlul_pkg::*;
	// removed import prim_mubi_pkg::mubi4_t;
	// Trace: ips/tlul/tlul_adapter_sram.sv:24:13
	parameter signed [31:0] SramAw = 12;
	// Trace: ips/tlul/tlul_adapter_sram.sv:25:13
	parameter signed [31:0] SramDw = 32;
	// Trace: ips/tlul/tlul_adapter_sram.sv:26:13
	parameter signed [31:0] Outstanding = 1;
	// Trace: ips/tlul/tlul_adapter_sram.sv:27:13
	parameter signed [31:0] SramBusBankAW = 12;
	// Trace: ips/tlul/tlul_adapter_sram.sv:29:13
	parameter [0:0] ByteAccess = 1;
	// Trace: ips/tlul/tlul_adapter_sram.sv:32:13
	parameter [0:0] ErrOnWrite = 0;
	// Trace: ips/tlul/tlul_adapter_sram.sv:33:13
	parameter [0:0] ErrOnRead = 0;
	// Trace: ips/tlul/tlul_adapter_sram.sv:34:13
	parameter [0:0] CmdIntgCheck = 0;
	// Trace: ips/tlul/tlul_adapter_sram.sv:35:13
	parameter [0:0] EnableRspIntgGen = 0;
	// Trace: ips/tlul/tlul_adapter_sram.sv:36:13
	parameter [0:0] EnableDataIntgGen = 0;
	// Trace: ips/tlul/tlul_adapter_sram.sv:37:13
	parameter [0:0] EnableDataIntgPt = 0;
	// Trace: ips/tlul/tlul_adapter_sram.sv:38:13
	parameter [0:0] SecFifoPtr = 0;
	// Trace: ips/tlul/tlul_adapter_sram.sv:39:13
	parameter [0:0] EnableReadback = 0;
	// Trace: ips/tlul/tlul_adapter_sram.sv:40:13
	parameter [0:0] DataXorAddr = 0;
	// Trace: ips/tlul/tlul_adapter_sram.sv:41:14
	localparam signed [31:0] top_pkg_TL_DW = 32;
	localparam signed [31:0] WidthMult = SramDw / top_pkg_TL_DW;
	// Trace: ips/tlul/tlul_adapter_sram.sv:42:14
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	localparam signed [31:0] IntgWidth = tlul_pkg_DataIntgWidth * WidthMult;
	// Trace: ips/tlul/tlul_adapter_sram.sv:43:14
	localparam signed [31:0] DataOutW = (EnableDataIntgPt ? SramDw + IntgWidth : SramDw);
	// Trace: ips/tlul/tlul_adapter_sram.sv:45:3
	input clk_i;
	// Trace: ips/tlul/tlul_adapter_sram.sv:46:3
	input rst_ni;
	// Trace: ips/tlul/tlul_adapter_sram.sv:49:3
	// removed localparam type tlul_pkg_tl_a_op_e
	localparam signed [31:0] prim_mubi_pkg_MuBi4Width = 4;
	// removed localparam type prim_mubi_pkg_mubi4_t
	localparam signed [31:0] tlul_pkg_H2DCmdIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_a_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_AW = 32;
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_h2d_t
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_i;
	// Trace: ips/tlul/tlul_adapter_sram.sv:50:3
	// removed localparam type tlul_pkg_tl_d_op_e
	localparam signed [31:0] tlul_pkg_D2HRspIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_d_user_t
	localparam signed [31:0] top_pkg_TL_DIW = 1;
	// removed localparam type tlul_pkg_tl_d2h_t
	output wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_o;
	// Trace: ips/tlul/tlul_adapter_sram.sv:53:3
	input wire [3:0] en_ifetch_i;
	// Trace: ips/tlul/tlul_adapter_sram.sv:56:3
	output wire req_o;
	// Trace: ips/tlul/tlul_adapter_sram.sv:57:3
	output wire [3:0] req_type_o;
	// Trace: ips/tlul/tlul_adapter_sram.sv:58:3
	input gnt_i;
	// Trace: ips/tlul/tlul_adapter_sram.sv:59:3
	output wire we_o;
	// Trace: ips/tlul/tlul_adapter_sram.sv:60:3
	output wire [SramAw - 1:0] addr_o;
	// Trace: ips/tlul/tlul_adapter_sram.sv:61:3
	output wire [DataOutW - 1:0] wdata_o;
	// Trace: ips/tlul/tlul_adapter_sram.sv:62:3
	output wire [DataOutW - 1:0] wmask_o;
	// Trace: ips/tlul/tlul_adapter_sram.sv:63:3
	output wire intg_error_o;
	// Trace: ips/tlul/tlul_adapter_sram.sv:64:3
	input [DataOutW - 1:0] rdata_i;
	// Trace: ips/tlul/tlul_adapter_sram.sv:65:3
	input rvalid_i;
	// Trace: ips/tlul/tlul_adapter_sram.sv:66:3
	input [1:0] rerror_i;
	// Trace: ips/tlul/tlul_adapter_sram.sv:67:3
	output wire compound_txn_in_progress_o;
	// Trace: ips/tlul/tlul_adapter_sram.sv:68:3
	input wire [3:0] readback_en_i;
	// Trace: ips/tlul/tlul_adapter_sram.sv:69:3
	output wire readback_error_o;
	// Trace: ips/tlul/tlul_adapter_sram.sv:70:3
	input wire wr_collision_i;
	// Trace: ips/tlul/tlul_adapter_sram.sv:71:3
	input wire write_pending_i;
	// Trace: ips/tlul/tlul_adapter_sram.sv:74:3
	localparam signed [31:0] SramByte = SramDw / 8;
	// Trace: ips/tlul/tlul_adapter_sram.sv:75:3
	function automatic integer prim_util_pkg_vbits;
		// Trace: ips/pkgs/prim_util_pkg.sv:74:36
		input integer value;
		// Trace: ips/pkgs/prim_util_pkg.sv:85:5
		prim_util_pkg_vbits = (value == 1 ? 1 : $clog2(value));
	endfunction
	localparam signed [31:0] DataBitWidth = prim_util_pkg_vbits(SramByte);
	// Trace: ips/tlul/tlul_adapter_sram.sv:76:3
	localparam signed [31:0] WoffsetWidth = (SramByte == top_pkg_TL_DBW ? 1 : DataBitWidth - prim_util_pkg_vbits(top_pkg_TL_DBW));
	// Trace: ips/tlul/tlul_adapter_sram.sv:79:3
	wire error_det;
	// Trace: ips/tlul/tlul_adapter_sram.sv:80:3
	wire error_internal;
	// Trace: ips/tlul/tlul_adapter_sram.sv:81:3
	wire wr_attr_error;
	// Trace: ips/tlul/tlul_adapter_sram.sv:82:3
	wire instr_error;
	// Trace: ips/tlul/tlul_adapter_sram.sv:83:3
	wire wr_vld_error;
	// Trace: ips/tlul/tlul_adapter_sram.sv:84:3
	wire rd_vld_error;
	// Trace: ips/tlul/tlul_adapter_sram.sv:85:3
	wire rsp_fifo_error;
	// Trace: ips/tlul/tlul_adapter_sram.sv:86:3
	wire sramreqfifo_error;
	// Trace: ips/tlul/tlul_adapter_sram.sv:87:3
	wire reqfifo_error;
	// Trace: ips/tlul/tlul_adapter_sram.sv:88:3
	wire intg_error;
	// Trace: ips/tlul/tlul_adapter_sram.sv:89:3
	wire tlul_error;
	// Trace: ips/tlul/tlul_adapter_sram.sv:90:3
	wire readback_error;
	// Trace: ips/tlul/tlul_adapter_sram.sv:91:3
	wire sram_byte_readback_error;
	// Trace: ips/tlul/tlul_adapter_sram.sv:94:3
	reg readback_error_q;
	// Trace: ips/tlul/tlul_adapter_sram.sv:95:3
	generate
		if (EnableReadback) begin : gen_cmd_readback_check
			// Trace: ips/tlul/tlul_adapter_sram.sv:96:5
			assign readback_error = sram_byte_readback_error;
			// Trace: ips/tlul/tlul_adapter_sram.sv:98:5
			always @(posedge clk_i or negedge rst_ni)
				// Trace: ips/tlul/tlul_adapter_sram.sv:99:7
				if (!rst_ni)
					// Trace: ips/tlul/tlul_adapter_sram.sv:100:9
					readback_error_q <= 1'sb0;
				else if (readback_error)
					// Trace: ips/tlul/tlul_adapter_sram.sv:102:9
					readback_error_q <= 1'b1;
		end
		else begin : gen_no_readback_check
			// Trace: ips/tlul/tlul_adapter_sram.sv:106:5
			wire unused_sram_byte_readback_error;
			// Trace: ips/tlul/tlul_adapter_sram.sv:107:5
			assign unused_sram_byte_readback_error = sram_byte_readback_error;
			// Trace: ips/tlul/tlul_adapter_sram.sv:108:5
			assign readback_error = 1'sb0;
			// Trace: ips/tlul/tlul_adapter_sram.sv:109:5
			wire [1:1] sv2v_tmp_EC2B7;
			assign sv2v_tmp_EC2B7 = 1'sb0;
			always @(*) readback_error_q = sv2v_tmp_EC2B7;
		end
	endgenerate
	// Trace: ips/tlul/tlul_adapter_sram.sv:114:3
	assign readback_error_o = readback_error | readback_error_q;
	// Trace: ips/tlul/tlul_adapter_sram.sv:117:3
	generate
		if (CmdIntgCheck) begin : gen_cmd_intg_check
			// Trace: ips/tlul/tlul_adapter_sram.sv:118:5
			tlul_cmd_intg_chk u_cmd_intg_chk(
				.tl_i(tl_i),
				.err_o(intg_error)
			);
		end
		else begin : gen_no_cmd_intg_check
			// Trace: ips/tlul/tlul_adapter_sram.sv:123:5
			assign intg_error = 1'sb0;
		end
	endgenerate
	// Trace: ips/tlul/tlul_adapter_sram.sv:127:3
	reg intg_error_q;
	// Trace: ips/tlul/tlul_adapter_sram.sv:128:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: ips/tlul/tlul_adapter_sram.sv:129:5
		if (!rst_ni)
			// Trace: ips/tlul/tlul_adapter_sram.sv:130:7
			intg_error_q <= 1'sb0;
		else if (((intg_error || rsp_fifo_error) || sramreqfifo_error) || reqfifo_error)
			// Trace: ips/tlul/tlul_adapter_sram.sv:132:7
			intg_error_q <= 1'b1;
	// Trace: ips/tlul/tlul_adapter_sram.sv:138:3
	assign intg_error_o = (((intg_error | rsp_fifo_error) | sramreqfifo_error) | reqfifo_error) | intg_error_q;
	// Trace: ips/tlul/tlul_adapter_sram.sv:144:3
	assign wr_attr_error = ((tl_i[6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) - (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))))) + 1 : ((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) - (6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))))) + 1)] == 3'h0) || (tl_i[6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) - (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))))) + 1 : ((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) - (6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))))) + 1)] == 3'h1) ? (ByteAccess == 0 ? (tl_i[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))] != {((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55)) * 1 {1'sb1}}) || (tl_i[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)] != 2'h2) : 1'b0) : 1'b0);
	// Trace: ips/tlul/tlul_adapter_sram.sv:151:3
	function automatic [3:0] sv2v_cast_EECFA;
		input reg [3:0] inp;
		sv2v_cast_EECFA = inp;
	endfunction
	function automatic prim_mubi_pkg_mubi4_test_false_loose;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:64:51
		input reg [3:0] val;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:65:5
		prim_mubi_pkg_mubi4_test_false_loose = sv2v_cast_EECFA(4'h6) != val;
	endfunction
	function automatic prim_mubi_pkg_mubi4_test_invalid;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:31:47
		input reg [3:0] val;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:32:5
		prim_mubi_pkg_mubi4_test_invalid = ~(|{((sv2v_cast_EECFA(4'h6) ^ (val ^ val)) === (val ^ (sv2v_cast_EECFA(4'h6) ^ sv2v_cast_EECFA(4'h6)))) & ((((val ^ val) ^ (sv2v_cast_EECFA(4'h6) ^ sv2v_cast_EECFA(4'h6))) === (sv2v_cast_EECFA(4'h6) ^ sv2v_cast_EECFA(4'h6))) | 1'bx), ((sv2v_cast_EECFA(4'h9) ^ (val ^ val)) === (val ^ (sv2v_cast_EECFA(4'h9) ^ sv2v_cast_EECFA(4'h9)))) & ((((val ^ val) ^ (sv2v_cast_EECFA(4'h9) ^ sv2v_cast_EECFA(4'h9))) === (sv2v_cast_EECFA(4'h9) ^ sv2v_cast_EECFA(4'h9))) | 1'bx)});
	endfunction
	function automatic prim_mubi_pkg_mubi4_test_true_strict;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:43:51
		input reg [3:0] val;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:44:5
		prim_mubi_pkg_mubi4_test_true_strict = sv2v_cast_EECFA(4'h6) == val;
	endfunction
	assign instr_error = prim_mubi_pkg_mubi4_test_invalid(tl_i[18-:4]) | (prim_mubi_pkg_mubi4_test_true_strict(tl_i[18-:4]) & prim_mubi_pkg_mubi4_test_false_loose(en_ifetch_i));
	// Trace: ips/tlul/tlul_adapter_sram.sv:155:3
	generate
		if (ErrOnWrite == 1) begin : gen_no_writes
			// Trace: ips/tlul/tlul_adapter_sram.sv:156:5
			assign wr_vld_error = tl_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] != 3'h4;
		end
		else begin : gen_writes_allowed
			// Trace: ips/tlul/tlul_adapter_sram.sv:158:5
			assign wr_vld_error = 1'b0;
		end
	endgenerate
	// Trace: ips/tlul/tlul_adapter_sram.sv:161:3
	generate
		if (ErrOnRead == 1) begin : gen_no_reads
			// Trace: ips/tlul/tlul_adapter_sram.sv:162:5
			assign rd_vld_error = tl_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] == 3'h4;
		end
		else begin : gen_reads_allowed
			// Trace: ips/tlul/tlul_adapter_sram.sv:164:5
			assign rd_vld_error = 1'b0;
		end
	endgenerate
	// Trace: ips/tlul/tlul_adapter_sram.sv:168:3
	tlul_err u_err(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.tl_i(tl_i),
		.err_o(tlul_error)
	);
	// Trace: ips/tlul/tlul_adapter_sram.sv:176:3
	assign error_det = ((((wr_attr_error | wr_vld_error) | rd_vld_error) | instr_error) | tlul_error) | intg_error;
	// Trace: ips/tlul/tlul_adapter_sram.sv:180:3
	wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_i_int;
	// Trace: ips/tlul/tlul_adapter_sram.sv:182:3
	wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_o_int;
	// Trace: ips/tlul/tlul_adapter_sram.sv:184:3
	wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_out;
	// Trace: ips/tlul/tlul_adapter_sram.sv:187:3
	wire unused_tl_i_int;
	// Trace: ips/tlul/tlul_adapter_sram.sv:188:3
	assign unused_tl_i_int = ^tl_i_int;
	// Trace: ips/tlul/tlul_adapter_sram.sv:190:3
	tlul_rsp_intg_gen #(
		.EnableRspIntgGen(EnableRspIntgGen),
		.EnableDataIntgGen(EnableDataIntgGen)
	) u_rsp_gen(
		.tl_i(tl_out),
		.tl_o(tl_o)
	);
	// Trace: ips/tlul/tlul_adapter_sram.sv:199:3
	tlul_sram_byte #(
		.EnableIntg((ByteAccess & EnableDataIntgPt) & !ErrOnWrite),
		.Outstanding(Outstanding),
		.EnableReadback(EnableReadback)
	) u_sram_byte(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.tl_i(tl_i),
		.tl_o(tl_out),
		.tl_sram_o(tl_i_int),
		.tl_sram_i(tl_o_int),
		.error_i(error_det),
		.error_o(error_internal),
		.alert_o(sram_byte_readback_error),
		.compound_txn_in_progress_o(compound_txn_in_progress_o),
		.readback_en_i(readback_en_i),
		.wr_collision_i(wr_collision_i),
		.write_pending_i(write_pending_i)
	);
	// Trace: ips/tlul/tlul_adapter_sram.sv:219:3
	// removed localparam type sram_req_t
	// Trace: ips/tlul/tlul_adapter_sram.sv:224:3
	// removed localparam type sram_req_addr_t
	// Trace: ips/tlul/tlul_adapter_sram.sv:228:3
	// removed localparam type req_op_e
	// Trace: ips/tlul/tlul_adapter_sram.sv:234:3
	// removed localparam type req_t
	// Trace: ips/tlul/tlul_adapter_sram.sv:242:3
	// removed localparam type rsp_t
	// Trace: ips/tlul/tlul_adapter_sram.sv:248:3
	localparam signed [31:0] SramReqFifoWidth = top_pkg_TL_DBW + WoffsetWidth;
	// Trace: ips/tlul/tlul_adapter_sram.sv:249:3
	localparam signed [31:0] ReqFifoWidth = (7 + top_pkg_TL_SZW) + top_pkg_TL_AIW;
	// Trace: ips/tlul/tlul_adapter_sram.sv:250:3
	localparam signed [31:0] RspFifoWidth = (((top_pkg_TL_DW + tlul_pkg_DataIntgWidth) + 0) >= 0 ? (top_pkg_TL_DW + tlul_pkg_DataIntgWidth) + 1 : 1 - ((top_pkg_TL_DW + tlul_pkg_DataIntgWidth) + 0));
	// Trace: ips/tlul/tlul_adapter_sram.sv:256:3
	wire reqfifo_wvalid;
	wire reqfifo_wready;
	// Trace: ips/tlul/tlul_adapter_sram.sv:257:3
	wire reqfifo_rvalid;
	wire reqfifo_rready;
	// Trace: ips/tlul/tlul_adapter_sram.sv:258:3
	wire [((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) - 1:0] reqfifo_wdata;
	wire [((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) - 1:0] reqfifo_rdata;
	// Trace: ips/tlul/tlul_adapter_sram.sv:260:3
	wire sramreqfifo_wvalid;
	wire sramreqfifo_wready;
	// Trace: ips/tlul/tlul_adapter_sram.sv:261:3
	wire sramreqfifo_rready;
	// Trace: ips/tlul/tlul_adapter_sram.sv:262:3
	wire [(top_pkg_TL_DBW + WoffsetWidth) - 1:0] sramreqfifo_wdata;
	wire [(top_pkg_TL_DBW + WoffsetWidth) - 1:0] sramreqfifo_rdata;
	// Trace: ips/tlul/tlul_adapter_sram.sv:264:3
	wire sramreqaddrfifo_wready;
	// Trace: ips/tlul/tlul_adapter_sram.sv:265:3
	wire [SramBusBankAW - 1:0] sramreqaddrfifo_wdata;
	wire [SramBusBankAW - 1:0] sramreqaddrfifo_rdata;
	// Trace: ips/tlul/tlul_adapter_sram.sv:267:3
	wire rspfifo_wvalid;
	wire rspfifo_wready;
	// Trace: ips/tlul/tlul_adapter_sram.sv:268:3
	wire rspfifo_rvalid;
	wire rspfifo_rready;
	// Trace: ips/tlul/tlul_adapter_sram.sv:269:3
	wire [(top_pkg_TL_DW + tlul_pkg_DataIntgWidth) + 0:0] rspfifo_wdata;
	wire [(top_pkg_TL_DW + tlul_pkg_DataIntgWidth) + 0:0] rspfifo_rdata;
	// Trace: ips/tlul/tlul_adapter_sram.sv:271:3
	wire a_ack;
	wire d_ack;
	wire sram_ack;
	// Trace: ips/tlul/tlul_adapter_sram.sv:272:3
	assign a_ack = tl_i_int[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] & tl_o_int[0];
	// Trace: ips/tlul/tlul_adapter_sram.sv:273:3
	assign d_ack = tl_o_int[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))] & tl_i_int[0];
	// Trace: ips/tlul/tlul_adapter_sram.sv:274:3
	assign sram_ack = req_o & gnt_i;
	// Trace: ips/tlul/tlul_adapter_sram.sv:277:3
	reg d_valid;
	reg d_error;
	// Trace: ips/tlul/tlul_adapter_sram.sv:278:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: ips/tlul/tlul_adapter_sram.sv:279:5
		d_valid = 1'b0;
		// Trace: ips/tlul/tlul_adapter_sram.sv:281:5
		if (reqfifo_rvalid) begin
			begin
				// Trace: ips/tlul/tlul_adapter_sram.sv:282:7
				if (reqfifo_rdata[1 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7))])
					// Trace: ips/tlul/tlul_adapter_sram.sv:284:9
					d_valid = 1'b1;
				else if (reqfifo_rdata[3 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7))-:((7 + (top_pkg_TL_SZW + 7)) >= (5 + (top_pkg_TL_SZW + 8)) ? ((3 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7))) - (1 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 8)))) + 1 : ((1 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 8))) - (3 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7)))) + 1)] == 2'd1)
					// Trace: ips/tlul/tlul_adapter_sram.sv:286:9
					d_valid = rspfifo_rvalid;
				else
					// Trace: ips/tlul/tlul_adapter_sram.sv:289:9
					d_valid = 1'b1;
			end
		end
		else
			// Trace: ips/tlul/tlul_adapter_sram.sv:292:7
			d_valid = 1'b0;
	end
	// Trace: ips/tlul/tlul_adapter_sram.sv:298:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: ips/tlul/tlul_adapter_sram.sv:299:5
		d_error = 1'b0;
		// Trace: ips/tlul/tlul_adapter_sram.sv:301:5
		if (reqfifo_rvalid) begin
			begin
				// Trace: ips/tlul/tlul_adapter_sram.sv:302:7
				if (reqfifo_rdata[3 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7))-:((7 + (top_pkg_TL_SZW + 7)) >= (5 + (top_pkg_TL_SZW + 8)) ? ((3 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7))) - (1 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 8)))) + 1 : ((1 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 8))) - (3 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7)))) + 1)] == 2'd1)
					// Trace: ips/tlul/tlul_adapter_sram.sv:303:9
					d_error = rspfifo_rdata[0] | reqfifo_rdata[1 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7))];
				else
					// Trace: ips/tlul/tlul_adapter_sram.sv:305:9
					d_error = reqfifo_rdata[1 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7))];
			end
		end
		else
			// Trace: ips/tlul/tlul_adapter_sram.sv:308:7
			d_error = 1'b0;
	end
	// Trace: ips/tlul/tlul_adapter_sram.sv:312:3
	wire vld_rd_rsp;
	// Trace: ips/tlul/tlul_adapter_sram.sv:313:3
	assign vld_rd_rsp = ((d_valid & reqfifo_rvalid) & rspfifo_rvalid) & (reqfifo_rdata[3 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7))-:((7 + (top_pkg_TL_SZW + 7)) >= (5 + (top_pkg_TL_SZW + 8)) ? ((3 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7))) - (1 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 8)))) + 1 : ((1 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 8))) - (3 + (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7)))) + 1)] == 2'd1);
	// Trace: ips/tlul/tlul_adapter_sram.sv:316:3
	wire [31:0] error_blanking_data;
	// Trace: ips/tlul/tlul_adapter_sram.sv:317:3
	localparam [31:0] tlul_pkg_DataWhenError = {top_pkg_TL_DW {1'b1}};
	localparam [31:0] tlul_pkg_DataWhenInstrError = 1'sb0;
	assign error_blanking_data = (prim_mubi_pkg_mubi4_test_true_strict(reqfifo_rdata[prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7)-:((prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7)) >= (top_pkg_TL_SZW + 8) ? ((prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7)) - (top_pkg_TL_SZW + 8)) + 1 : ((top_pkg_TL_SZW + 8) - (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7))) + 1)]) ? tlul_pkg_DataWhenInstrError : tlul_pkg_DataWhenError);
	// Trace: ips/tlul/tlul_adapter_sram.sv:324:3
	wire [31:0] unused_instr;
	wire [31:0] unused_data;
	// Trace: ips/tlul/tlul_adapter_sram.sv:325:3
	wire [6:0] error_instr_integ;
	wire [6:0] error_data_integ;
	// Trace: ips/tlul/tlul_adapter_sram.sv:326:3
	localparam signed [31:0] tlul_pkg_DataMaxWidth = 32;
	function automatic [31:0] sv2v_cast_32;
		input reg [31:0] inp;
		sv2v_cast_32 = inp;
	endfunction
	tlul_data_integ_enc u_tlul_data_integ_enc_instr(
		.data_i(sv2v_cast_32(tlul_pkg_DataWhenInstrError)),
		.data_intg_o({error_instr_integ, unused_instr})
	);
	// Trace: ips/tlul/tlul_adapter_sram.sv:330:3
	tlul_data_integ_enc u_tlul_data_integ_enc_data(
		.data_i(sv2v_cast_32(tlul_pkg_DataWhenError)),
		.data_intg_o({error_data_integ, unused_data})
	);
	// Trace: ips/tlul/tlul_adapter_sram.sv:335:3
	wire [6:0] error_blanking_integ;
	// Trace: ips/tlul/tlul_adapter_sram.sv:336:3
	assign error_blanking_integ = (prim_mubi_pkg_mubi4_test_true_strict(reqfifo_rdata[prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7)-:((prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7)) >= (top_pkg_TL_SZW + 8) ? ((prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7)) - (top_pkg_TL_SZW + 8)) + 1 : ((top_pkg_TL_SZW + 8) - (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_SZW + 7))) + 1)]) ? error_instr_integ : error_data_integ);
	// Trace: ips/tlul/tlul_adapter_sram.sv:340:3
	wire [31:0] d_data;
	// Trace: ips/tlul/tlul_adapter_sram.sv:341:3
	assign d_data = (vld_rd_rsp & ~d_error ? rspfifo_rdata[39-:32] : error_blanking_data);
	// Trace: ips/tlul/tlul_adapter_sram.sv:346:3
	wire [6:0] data_intg;
	// Trace: ips/tlul/tlul_adapter_sram.sv:347:3
	localparam [6:0] prim_secded_pkg_SecdedInv3932ZeroEcc = 7'h2a;
	assign data_intg = (vld_rd_rsp && reqfifo_rdata[5 + (top_pkg_TL_SZW + 7)] ? error_blanking_integ : (vld_rd_rsp ? rspfifo_rdata[7-:7] : prim_secded_pkg_SecdedInv3932ZeroEcc));
	// Trace: ips/tlul/tlul_adapter_sram.sv:356:3
	wire missed_err_gnt_d;
	reg missed_err_gnt_q;
	// Trace: ips/tlul/tlul_adapter_sram.sv:359:3
	assign missed_err_gnt_d = (error_internal & tl_i_int[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))]) & ~tl_o_int[0];
	// Trace: ips/tlul/tlul_adapter_sram.sv:361:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: ips/tlul/tlul_adapter_sram.sv:362:5
		if (!rst_ni)
			// Trace: ips/tlul/tlul_adapter_sram.sv:363:7
			missed_err_gnt_q <= 1'b0;
		else
			// Trace: ips/tlul/tlul_adapter_sram.sv:365:7
			missed_err_gnt_q <= missed_err_gnt_d;
	// Trace: ips/tlul/tlul_adapter_sram.sv:369:3
	function automatic [6:0] sv2v_cast_71F0A;
		input reg [6:0] inp;
		sv2v_cast_71F0A = inp;
	endfunction
	function automatic [6:0] sv2v_cast_83AAC;
		input reg [6:0] inp;
		sv2v_cast_83AAC = inp;
	endfunction
	function automatic [top_pkg_TL_SZW - 1:0] sv2v_cast_FDEB5;
		input reg [top_pkg_TL_SZW - 1:0] inp;
		sv2v_cast_FDEB5 = inp;
	endfunction
	function automatic [7:0] sv2v_cast_15E34;
		input reg [7:0] inp;
		sv2v_cast_15E34 = inp;
	endfunction
	function automatic [0:0] sv2v_cast_17D81;
		input reg [0:0] inp;
		sv2v_cast_17D81 = inp;
	endfunction
	function automatic [31:0] sv2v_cast_9783B;
		input reg [31:0] inp;
		sv2v_cast_9783B = inp;
	endfunction
	function automatic [(tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) - 1:0] sv2v_cast_11E70;
		input reg [(tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) - 1:0] inp;
		sv2v_cast_11E70 = inp;
	endfunction
	function automatic [0:0] sv2v_cast_1;
		input reg [0:0] inp;
		sv2v_cast_1 = inp;
	endfunction
	assign tl_o_int = {d_valid, (d_valid && (reqfifo_rdata[7 + (top_pkg_TL_SZW + 7)-:((7 + (top_pkg_TL_SZW + 7)) >= (5 + (top_pkg_TL_SZW + 8)) ? ((7 + (top_pkg_TL_SZW + 7)) - (5 + (top_pkg_TL_SZW + 8))) + 1 : ((5 + (top_pkg_TL_SZW + 8)) - (7 + (top_pkg_TL_SZW + 7))) + 1)] != 2'd1) ? 3'h0 : 3'h1), 3'b000, sv2v_cast_FDEB5((d_valid ? reqfifo_rdata[top_pkg_TL_SZW + 7-:((top_pkg_TL_SZW + 7) >= 8 ? top_pkg_TL_SZW : 9 - (top_pkg_TL_SZW + 7))] : {((top_pkg_TL_SZW + 7) >= 8 ? top_pkg_TL_SZW : 9 - (top_pkg_TL_SZW + 7)) * 1 {1'sb0}})), sv2v_cast_15E34((d_valid ? reqfifo_rdata[7-:top_pkg_TL_AIW] : {8 {1'sb0}})), sv2v_cast_17D81(1'b0), sv2v_cast_9783B(d_data), sv2v_cast_11E70({sv2v_cast_71F0A(1'sb0), sv2v_cast_83AAC(data_intg)}), d_valid && d_error, sv2v_cast_1((((gnt_i | missed_err_gnt_q) & reqfifo_wready) & sramreqfifo_wready) & sramreqaddrfifo_wready)};
	// Trace: ips/tlul/tlul_adapter_sram.sv:390:3
	assign req_o = (tl_i_int[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] & reqfifo_wready) & ~error_internal;
	// Trace: ips/tlul/tlul_adapter_sram.sv:391:3
	assign req_type_o = tl_i_int[18-:4];
	// Trace: ips/tlul/tlul_adapter_sram.sv:392:3
	assign we_o = tl_i_int[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] & |{tl_i_int[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] == 3'h0, tl_i_int[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] == 3'h1};
	// Trace: ips/tlul/tlul_adapter_sram.sv:393:3
	assign addr_o = (tl_i_int[7 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))] ? tl_i_int[(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (31 - DataBitWidth)+:SramAw] : {SramAw {1'sb0}});
	// Trace: ips/tlul/tlul_adapter_sram.sv:398:3
	wire [WoffsetWidth - 1:0] woffset;
	// Trace: ips/tlul/tlul_adapter_sram.sv:399:3
	generate
		if (top_pkg_TL_DW != SramDw) begin : gen_wordwidthadapt
			// Trace: ips/tlul/tlul_adapter_sram.sv:400:5
			assign woffset = tl_i_int[(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (32 - DataBitWidth):(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (31 - prim_util_pkg_vbits(top_pkg_TL_DBW))];
		end
		else begin : gen_no_wordwidthadapt
			// Trace: ips/tlul/tlul_adapter_sram.sv:402:5
			assign woffset = 1'sb0;
		end
	endgenerate
	// Trace: ips/tlul/tlul_adapter_sram.sv:408:3
	localparam signed [31:0] DataWidth = (EnableDataIntgPt ? top_pkg_TL_DW + tlul_pkg_DataIntgWidth : top_pkg_TL_DW);
	// Trace: ips/tlul/tlul_adapter_sram.sv:411:3
	wire [(WidthMult * DataWidth) - 1:0] wmask_combined;
	// Trace: ips/tlul/tlul_adapter_sram.sv:412:3
	wire [(WidthMult * DataWidth) - 1:0] wdata_combined;
	// Trace: ips/tlul/tlul_adapter_sram.sv:415:3
	reg [(WidthMult * top_pkg_TL_DW) - 1:0] wmask_int;
	// Trace: ips/tlul/tlul_adapter_sram.sv:416:3
	reg [(WidthMult * top_pkg_TL_DW) - 1:0] wdata_int;
	// Trace: ips/tlul/tlul_adapter_sram.sv:419:3
	reg [(WidthMult * tlul_pkg_DataIntgWidth) - 1:0] wmask_intg;
	// Trace: ips/tlul/tlul_adapter_sram.sv:420:3
	reg [(WidthMult * tlul_pkg_DataIntgWidth) - 1:0] wdata_intg;
	// Trace: ips/tlul/tlul_adapter_sram.sv:422:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: ips/tlul/tlul_adapter_sram.sv:423:5
		wmask_int = 1'sb0;
		// Trace: ips/tlul/tlul_adapter_sram.sv:424:5
		wdata_int = 1'sb0;
		// Trace: ips/tlul/tlul_adapter_sram.sv:426:5
		if (tl_i_int[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))])
			// Trace: ips/tlul/tlul_adapter_sram.sv:427:7
			begin : sv2v_autoblock_1
				// Trace: ips/tlul/tlul_adapter_sram.sv:427:12
				reg signed [31:0] i;
				// Trace: ips/tlul/tlul_adapter_sram.sv:427:12
				for (i = 0; i < 4; i = i + 1)
					begin
						// Trace: ips/tlul/tlul_adapter_sram.sv:428:9
						wmask_int[(woffset * top_pkg_TL_DW) + (8 * i)+:8] = {8 {tl_i_int[(top_pkg_TL_DBW + 55) - ((top_pkg_TL_DBW - 1) - i)]}};
						// Trace: ips/tlul/tlul_adapter_sram.sv:429:9
						wdata_int[(woffset * top_pkg_TL_DW) + (8 * i)+:8] = (tl_i_int[(top_pkg_TL_DBW + 55) - ((top_pkg_TL_DBW - 1) - i)] && we_o ? tl_i_int[24 + (8 * i)+:8] : {8 {1'sb0}});
					end
			end
	end
	// Trace: ips/tlul/tlul_adapter_sram.sv:434:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: ips/tlul/tlul_adapter_sram.sv:435:5
		wmask_intg = 1'sb0;
		// Trace: ips/tlul/tlul_adapter_sram.sv:436:5
		wdata_intg = 1'sb0;
		// Trace: ips/tlul/tlul_adapter_sram.sv:438:5
		if (tl_i_int[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))]) begin
			// Trace: ips/tlul/tlul_adapter_sram.sv:439:7
			wmask_intg[woffset * tlul_pkg_DataIntgWidth+:tlul_pkg_DataIntgWidth] = {tlul_pkg_DataIntgWidth {1'b1}};
			// Trace: ips/tlul/tlul_adapter_sram.sv:440:7
			wdata_intg[woffset * tlul_pkg_DataIntgWidth+:tlul_pkg_DataIntgWidth] = tl_i_int[7-:tlul_pkg_DataIntgWidth];
		end
	end
	// Trace: ips/tlul/tlul_adapter_sram.sv:444:3
	genvar _gv_i_1;
	generate
		for (_gv_i_1 = 0; _gv_i_1 < WidthMult; _gv_i_1 = _gv_i_1 + 1) begin : gen_write_output
			localparam i = _gv_i_1;
			if (EnableDataIntgPt) begin : gen_combined_output
				// Trace: ips/tlul/tlul_adapter_sram.sv:446:7
				assign wmask_combined[i * DataWidth+:DataWidth] = {wmask_intg[i * tlul_pkg_DataIntgWidth+:tlul_pkg_DataIntgWidth], wmask_int[i * top_pkg_TL_DW+:top_pkg_TL_DW]};
				// Trace: ips/tlul/tlul_adapter_sram.sv:447:7
				assign wdata_combined[i * DataWidth+:DataWidth] = {wdata_intg[i * tlul_pkg_DataIntgWidth+:tlul_pkg_DataIntgWidth], wdata_int[i * top_pkg_TL_DW+:top_pkg_TL_DW]};
			end
			else begin : gen_ft_output
				// Trace: ips/tlul/tlul_adapter_sram.sv:449:7
				wire unused_w;
				// Trace: ips/tlul/tlul_adapter_sram.sv:450:7
				assign wmask_combined[i * DataWidth+:DataWidth] = wmask_int[i * top_pkg_TL_DW+:top_pkg_TL_DW];
				// Trace: ips/tlul/tlul_adapter_sram.sv:451:7
				assign wdata_combined[i * DataWidth+:DataWidth] = wdata_int[i * top_pkg_TL_DW+:top_pkg_TL_DW];
				// Trace: ips/tlul/tlul_adapter_sram.sv:452:7
				assign unused_w = |wmask_intg & |wdata_intg;
			end
		end
	endgenerate
	// Trace: ips/tlul/tlul_adapter_sram.sv:456:3
	assign wmask_o = wmask_combined;
	// Trace: ips/tlul/tlul_adapter_sram.sv:457:3
	assign wdata_o = wdata_combined;
	// Trace: ips/tlul/tlul_adapter_sram.sv:459:3
	assign reqfifo_wvalid = a_ack;
	// Trace: ips/tlul/tlul_adapter_sram.sv:460:3
	assign reqfifo_wdata = {(tl_i_int[6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) - (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))))) + 1 : ((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) - (6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))))) + 1)] != 3'h4 ? 2'd0 : 2'd1), error_internal, sv2v_cast_EECFA(tl_i_int[18-:4]), sv2v_cast_FDEB5(tl_i_int[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)]), sv2v_cast_15E34(tl_i_int[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)])};
	// Trace: ips/tlul/tlul_adapter_sram.sv:467:3
	assign reqfifo_rready = d_ack;
	// Trace: ips/tlul/tlul_adapter_sram.sv:470:3
	function automatic [top_pkg_TL_DBW - 1:0] sv2v_cast_B0D6A;
		input reg [top_pkg_TL_DBW - 1:0] inp;
		sv2v_cast_B0D6A = inp;
	endfunction
	function automatic [WoffsetWidth - 1:0] sv2v_cast_A1535;
		input reg [WoffsetWidth - 1:0] inp;
		sv2v_cast_A1535 = inp;
	endfunction
	assign sramreqfifo_wdata = {sv2v_cast_B0D6A(tl_i_int[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))]), sv2v_cast_A1535(woffset)};
	// Trace: ips/tlul/tlul_adapter_sram.sv:474:3
	assign sramreqfifo_wvalid = sram_ack & ~we_o;
	// Trace: ips/tlul/tlul_adapter_sram.sv:475:3
	assign sramreqfifo_rready = rspfifo_wvalid;
	// Trace: ips/tlul/tlul_adapter_sram.sv:477:3
	assign rspfifo_wvalid = rvalid_i & reqfifo_rvalid;
	// Trace: ips/tlul/tlul_adapter_sram.sv:479:3
	assign sramreqaddrfifo_wdata = tl_i_int[(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (31 - DataBitWidth)+:SramBusBankAW];
	// Trace: ips/tlul/tlul_adapter_sram.sv:482:3
	wire [(WidthMult * DataWidth) - 1:0] rdata_reshaped;
	// Trace: ips/tlul/tlul_adapter_sram.sv:483:3
	reg [DataWidth - 1:0] rdata_tlword;
	// Trace: ips/tlul/tlul_adapter_sram.sv:486:3
	assign rdata_reshaped = rdata_i;
	// Trace: ips/tlul/tlul_adapter_sram.sv:488:3
	localparam [38:0] prim_secded_pkg_SecdedInv3932ZeroWord = 39'h2a00000000;
	generate
		if (EnableDataIntgPt) begin : gen_no_rmask
			// Trace: ips/tlul/tlul_adapter_sram.sv:489:5
			always @(*) begin
				if (_sv2v_0)
					;
				// Trace: ips/tlul/tlul_adapter_sram.sv:492:7
				rdata_tlword = prim_secded_pkg_SecdedInv3932ZeroWord;
				// Trace: ips/tlul/tlul_adapter_sram.sv:496:7
				if (|sramreqfifo_rdata[top_pkg_TL_DBW + (WoffsetWidth - 1)-:((top_pkg_TL_DBW + (WoffsetWidth - 1)) >= (WoffsetWidth + 0) ? ((top_pkg_TL_DBW + (WoffsetWidth - 1)) - (WoffsetWidth + 0)) + 1 : ((WoffsetWidth + 0) - (top_pkg_TL_DBW + (WoffsetWidth - 1))) + 1)]) begin
					begin
						// Trace: ips/tlul/tlul_adapter_sram.sv:498:9
						if (DataXorAddr) begin : gen_data_xor_addr
							// Trace: ips/tlul/tlul_adapter_sram.sv:504:11
							rdata_tlword = {rdata_reshaped[(sramreqfifo_rdata[WoffsetWidth - 1-:WoffsetWidth] * DataWidth) + ((DataWidth - 1) >= top_pkg_TL_DW ? DataWidth - 1 : ((DataWidth - 1) + ((DataWidth - 1) >= top_pkg_TL_DW ? ((DataWidth - 1) - top_pkg_TL_DW) + 1 : (top_pkg_TL_DW - (DataWidth - 1)) + 1)) - 1)-:((DataWidth - 1) >= top_pkg_TL_DW ? ((DataWidth - 1) - top_pkg_TL_DW) + 1 : (top_pkg_TL_DW - (DataWidth - 1)) + 1)], rdata_reshaped[(sramreqfifo_rdata[WoffsetWidth - 1-:WoffsetWidth] * DataWidth) + 31-:top_pkg_TL_DW] ^ {{top_pkg_TL_DW - SramBusBankAW {1'b0}}, sramreqaddrfifo_rdata}};
						end
						else begin : gen_no_data_xor_addr
							// Trace: ips/tlul/tlul_adapter_sram.sv:510:11
							rdata_tlword = rdata_reshaped[sramreqfifo_rdata[WoffsetWidth - 1-:WoffsetWidth] * DataWidth+:DataWidth];
						end
					end
				end
			end
		end
		else begin : gen_rmask
			// Trace: ips/tlul/tlul_adapter_sram.sv:515:5
			reg [DataWidth - 1:0] rmask;
			// Trace: ips/tlul/tlul_adapter_sram.sv:516:5
			always @(*) begin
				if (_sv2v_0)
					;
				// Trace: ips/tlul/tlul_adapter_sram.sv:517:7
				rmask = 1'sb0;
				// Trace: ips/tlul/tlul_adapter_sram.sv:518:7
				begin : sv2v_autoblock_2
					// Trace: ips/tlul/tlul_adapter_sram.sv:518:12
					reg signed [31:0] i;
					// Trace: ips/tlul/tlul_adapter_sram.sv:518:12
					for (i = 0; i < 4; i = i + 1)
						begin
							// Trace: ips/tlul/tlul_adapter_sram.sv:519:9
							rmask[8 * i+:8] = {8 {sramreqfifo_rdata[(top_pkg_TL_DBW + (WoffsetWidth - 1)) - ((top_pkg_TL_DBW - 1) - i)]}};
						end
				end
			end
			// Trace: ips/tlul/tlul_adapter_sram.sv:523:5
			wire [DataWidth:1] sv2v_tmp_44C61;
			assign sv2v_tmp_44C61 = rdata_reshaped[sramreqfifo_rdata[WoffsetWidth - 1-:WoffsetWidth] * DataWidth+:DataWidth] & rmask;
			always @(*) rdata_tlword = sv2v_tmp_44C61;
		end
	endgenerate
	// Trace: ips/tlul/tlul_adapter_sram.sv:526:3
	assign rspfifo_wdata = {rdata_tlword[31:0], sv2v_cast_83AAC((EnableDataIntgPt ? rdata_tlword[DataWidth - 1-:tlul_pkg_DataIntgWidth] : {7 {1'sb0}})), rerror_i[1]};
	// Trace: ips/tlul/tlul_adapter_sram.sv:531:3
	assign rspfifo_rready = ((reqfifo_rdata[7 + (top_pkg_TL_SZW + 7)-:((7 + (top_pkg_TL_SZW + 7)) >= (5 + (top_pkg_TL_SZW + 8)) ? ((7 + (top_pkg_TL_SZW + 7)) - (5 + (top_pkg_TL_SZW + 8))) + 1 : ((5 + (top_pkg_TL_SZW + 8)) - (7 + (top_pkg_TL_SZW + 7))) + 1)] == 2'd1) & ~reqfifo_rdata[5 + (top_pkg_TL_SZW + 7)] ? reqfifo_rready : 1'b0);
	// Trace: ips/tlul/tlul_adapter_sram.sv:535:3
	wire unused_rerror;
	// Trace: ips/tlul/tlul_adapter_sram.sv:536:3
	assign unused_rerror = rerror_i[0];
	// Trace: ips/tlul/tlul_adapter_sram.sv:548:3
	prim_fifo_sync #(
		.Width(ReqFifoWidth),
		.Pass(1'b0),
		.Depth(Outstanding),
		.Secure(SecFifoPtr)
	) u_reqfifo(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.clr_i(1'b0),
		.wvalid_i(reqfifo_wvalid),
		.wready_o(reqfifo_wready),
		.wdata_i(reqfifo_wdata),
		.rvalid_o(reqfifo_rvalid),
		.rready_i(reqfifo_rready),
		.rdata_o(reqfifo_rdata),
		.full_o(),
		.depth_o(),
		.err_o(reqfifo_error)
	);
	// Trace: ips/tlul/tlul_adapter_sram.sv:572:3
	prim_fifo_sync #(
		.Width(SramReqFifoWidth),
		.Pass(1'b0),
		.Depth(Outstanding),
		.Secure(SecFifoPtr)
	) u_sramreqfifo(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.clr_i(1'b0),
		.wvalid_i(sramreqfifo_wvalid),
		.wready_o(sramreqfifo_wready),
		.wdata_i(sramreqfifo_wdata),
		.rvalid_o(),
		.rready_i(sramreqfifo_rready),
		.rdata_o(sramreqfifo_rdata),
		.full_o(),
		.depth_o(),
		.err_o(sramreqfifo_error)
	);
	// Trace: ips/tlul/tlul_adapter_sram.sv:594:3
	generate
		if (DataXorAddr) begin : gen_data_xor_addr_fifo
			// Trace: ips/tlul/tlul_adapter_sram.sv:595:5
			prim_fifo_sync #(
				.Width(SramBusBankAW),
				.Pass(1'b0),
				.Depth(Outstanding),
				.OutputZeroIfEmpty(1)
			) u_sramreqaddrfifo(
				.clk_i(clk_i),
				.rst_ni(rst_ni),
				.clr_i(1'b0),
				.wvalid_i(sramreqfifo_wvalid),
				.wready_o(sramreqaddrfifo_wready),
				.wdata_i(sramreqaddrfifo_wdata),
				.rvalid_o(),
				.rready_i(sramreqfifo_rready),
				.rdata_o(sramreqaddrfifo_rdata),
				.full_o(),
				.depth_o(),
				.err_o()
			);
		end
		else begin : gen_no_data_xor_addr_fifo
			// Trace: ips/tlul/tlul_adapter_sram.sv:615:5
			assign sramreqaddrfifo_wready = 1'b1;
			// Trace: ips/tlul/tlul_adapter_sram.sv:616:5
			assign sramreqaddrfifo_rdata = 1'sb0;
			// Trace: ips/tlul/tlul_adapter_sram.sv:619:5
			wire unused_sramreqaddrfifo;
			// Trace: ips/tlul/tlul_adapter_sram.sv:620:5
			assign unused_sramreqaddrfifo = ^{sramreqaddrfifo_wdata, sramreqaddrfifo_rdata};
		end
	endgenerate
	// Trace: ips/tlul/tlul_adapter_sram.sv:629:3
	prim_fifo_sync #(
		.Width(RspFifoWidth),
		.Pass(1'b1),
		.Depth(Outstanding),
		.Secure(SecFifoPtr)
	) u_rspfifo(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.clr_i(1'b0),
		.wvalid_i(rspfifo_wvalid),
		.wready_o(rspfifo_wready),
		.wdata_i(rspfifo_wdata),
		.rvalid_o(rspfifo_rvalid),
		.rready_i(rspfifo_rready),
		.rdata_o(rspfifo_rdata),
		.full_o(),
		.depth_o(),
		.err_o(rsp_fifo_error)
	);
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_adapter_sram.sv:650:59
	// removed an assertion item
	// rvalidHighReqFifoEmpty : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(rvalid_i |-> reqfifo_rvalid)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_adapter_sram.sv:650:614
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_adapter_sram.sv", 650, "rvalidHighReqFifoEmpty");
	// end
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_adapter_sram.sv:654:62
	// removed an assertion item
	// rvalidHighWhenRspFifoFull : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(rvalid_i |-> rspfifo_wready)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_adapter_sram.sv:654:617
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_adapter_sram.sv", 654, "rvalidHighWhenRspFifoFull");
	// end
	// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_adapter_sram.sv:657:403
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_adapter_sram.sv:657:491
		begin : adapterNoReadOrWrite
			
		end
	end
	// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_adapter_sram.sv:659:395
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_adapter_sram.sv:659:483
		begin : SramDwHasByteGranularity_A
			
		end
	end
	// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_adapter_sram.sv:660:411
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_adapter_sram.sv:660:499
		begin : SramDwIsMultipleOfTlulWidth_A
			
		end
	end
	// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_adapter_sram.sv:663:410
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_adapter_sram.sv:663:498
		begin : DataIntgOptions_A
			
		end
	end
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_adapter_sram.sv:666:172
	// removed an assertion item
	// ReqOutKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(req_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_adapter_sram.sv:666:727
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_adapter_sram.sv", 666, "ReqOutKnown_A");
	// end
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_adapter_sram.sv:667:172
	// removed an assertion item
	// WeOutKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(we_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_adapter_sram.sv:667:727
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_adapter_sram.sv", 667, "WeOutKnown_A");
	// end
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_adapter_sram.sv:668:172
	// removed an assertion item
	// AddrOutKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(addr_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_adapter_sram.sv:668:727
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_adapter_sram.sv", 668, "AddrOutKnown_A");
	// end
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_adapter_sram.sv:669:172
	// removed an assertion item
	// WdataOutKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(wdata_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_adapter_sram.sv:669:727
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_adapter_sram.sv", 669, "WdataOutKnown_A");
	// end
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_adapter_sram.sv:670:172
	// removed an assertion item
	// WmaskOutKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(wmask_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_adapter_sram.sv:670:727
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_adapter_sram.sv", 670, "WmaskOutKnown_A");
	// end
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_adapter_sram.sv:680:179
	// removed an assertion item
	// TlOutValidKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(tl_o.d_valid)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_adapter_sram.sv:680:734
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_adapter_sram.sv", 680, "TlOutValidKnown_A");
	// end
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_adapter_sram.sv:681:80
	// removed an assertion item
	// TlOutKnownIfFifoKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(rspfifo_rdata) -> !$isunknown(tl_o)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_adapter_sram.sv:681:635
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_adapter_sram.sv", 681, "TlOutKnownIfFifoKnown_A");
	// end
	initial _sv2v_0 = 0;
endmodule
module tlul_assert (
	clk_i,
	rst_ni,
	h2d,
	d2h
);
	// Trace: ips/tlul/tlul_assert.sv:11:13
	parameter EndpointType = "Device";
	// Trace: ips/tlul/tlul_assert.sv:13:3
	input clk_i;
	// Trace: ips/tlul/tlul_assert.sv:14:3
	input rst_ni;
	// Trace: ips/tlul/tlul_assert.sv:17:3
	// removed localparam type tlul_pkg_tl_a_op_e
	localparam signed [31:0] prim_mubi_pkg_MuBi4Width = 4;
	// removed localparam type prim_mubi_pkg_mubi4_t
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	localparam signed [31:0] tlul_pkg_H2DCmdIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_a_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_AW = 32;
	localparam signed [31:0] top_pkg_TL_DW = 32;
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_h2d_t
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] h2d;
	// Trace: ips/tlul/tlul_assert.sv:18:3
	// removed localparam type tlul_pkg_tl_d_op_e
	localparam signed [31:0] tlul_pkg_D2HRspIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_d_user_t
	localparam signed [31:0] top_pkg_TL_DIW = 1;
	// removed localparam type tlul_pkg_tl_d2h_t
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] d2h;
	// Trace: ips/tlul/tlul_assert.sv:27:3
	// removed import tlul_pkg::*;
	// Trace: ips/tlul/tlul_assert.sv:28:3
	// removed import top_pkg::*;
	// Trace: ips/tlul/tlul_assert.sv:40:3
	// removed localparam type pend_req_t
	// Trace: ips/tlul/tlul_assert.sv:47:3
	reg [(256 * ((4 + top_pkg_TL_SZW) + top_pkg_TL_DBW)) - 1:0] pend_req;
	// Trace: ips/tlul/tlul_assert.sv:52:3
	reg disable_sva;
	// Trace: ips/tlul/tlul_assert.sv:58:3
	reg disable_d_error_sva;
	// Trace: ips/tlul/tlul_assert.sv:60:3
	wire [7:0] a_mask;
	wire [7:0] d_mask;
	// Trace: ips/tlul/tlul_assert.sv:61:3
	wire [63:0] a_data;
	wire [63:0] d_data;
	// Trace: ips/tlul/tlul_assert.sv:62:3
	function automatic [7:0] sv2v_cast_8;
		input reg [7:0] inp;
		sv2v_cast_8 = inp;
	endfunction
	assign a_mask = sv2v_cast_8(h2d[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))]);
	// Trace: ips/tlul/tlul_assert.sv:63:3
	function automatic [63:0] sv2v_cast_64;
		input reg [63:0] inp;
		sv2v_cast_64 = inp;
	endfunction
	assign a_data = sv2v_cast_64(h2d[55-:32]);
	// Trace: ips/tlul/tlul_assert.sv:64:3
	assign d_mask = sv2v_cast_8(pend_req[(d2h[top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))-:((32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))) >= ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) + 1 : ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) + 1)] * ((4 + top_pkg_TL_SZW) + top_pkg_TL_DBW)) + (top_pkg_TL_DBW - 1)-:top_pkg_TL_DBW]);
	// Trace: ips/tlul/tlul_assert.sv:65:3
	assign d_data = sv2v_cast_64(d2h[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)]);
	// Trace: ips/tlul/tlul_assert.sv:72:3
	always @(negedge clk_i or negedge rst_ni)
		// Trace: ips/tlul/tlul_assert.sv:73:5
		if (!rst_ni)
			// Trace: ips/tlul/tlul_assert.sv:74:7
			pend_req <= 1'sb0;
		else begin
			// Trace: ips/tlul/tlul_assert.sv:76:7
			if (h2d[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))]) begin
				begin
					// Trace: ips/tlul/tlul_assert.sv:80:9
					if (d2h[0]) begin
						// Trace: ips/tlul/tlul_assert.sv:81:11
						pend_req[(h2d[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)] * ((4 + top_pkg_TL_SZW) + top_pkg_TL_DBW)) + (4 + (top_pkg_TL_SZW + (top_pkg_TL_DBW - 1)))] <= 1;
						// Trace: ips/tlul/tlul_assert.sv:82:11
						pend_req[(h2d[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)] * ((4 + top_pkg_TL_SZW) + top_pkg_TL_DBW)) + (3 + (top_pkg_TL_SZW + (top_pkg_TL_DBW - 1)))-:((3 + (top_pkg_TL_SZW + (top_pkg_TL_DBW - 1))) >= (top_pkg_TL_SZW + (top_pkg_TL_DBW + 0)) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_DBW - 1))) - (top_pkg_TL_SZW + (top_pkg_TL_DBW + 0))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_DBW + 0)) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_DBW - 1)))) + 1)] <= h2d[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)];
						// Trace: ips/tlul/tlul_assert.sv:83:11
						pend_req[(h2d[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)] * ((4 + top_pkg_TL_SZW) + top_pkg_TL_DBW)) + (top_pkg_TL_SZW + (top_pkg_TL_DBW - 1))-:((top_pkg_TL_SZW + (top_pkg_TL_DBW - 1)) >= (top_pkg_TL_DBW + 0) ? ((top_pkg_TL_SZW + (top_pkg_TL_DBW - 1)) - (top_pkg_TL_DBW + 0)) + 1 : ((top_pkg_TL_DBW + 0) - (top_pkg_TL_SZW + (top_pkg_TL_DBW - 1))) + 1)] <= h2d[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)];
						// Trace: ips/tlul/tlul_assert.sv:84:11
						pend_req[(h2d[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)] * ((4 + top_pkg_TL_SZW) + top_pkg_TL_DBW)) + (top_pkg_TL_DBW - 1)-:top_pkg_TL_DBW] <= h2d[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))];
					end
				end
			end
			if (d2h[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))]) begin
				begin
					// Trace: ips/tlul/tlul_assert.sv:90:9
					if (h2d[0])
						// Trace: ips/tlul/tlul_assert.sv:91:11
						pend_req[(d2h[top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))-:((32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))) >= ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) + 1 : ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) + 1)] * ((4 + top_pkg_TL_SZW) + top_pkg_TL_DBW)) + (4 + (top_pkg_TL_SZW + (top_pkg_TL_DBW - 1)))] <= 0;
				end
			end
		end
	// Trace: ips/tlul/tlul_assert.sv:101:3
	// removed an assertion item
	// sequence h2d_pre_S;
	// 	h2d.a_valid
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:106:3
	// removed an assertion item
	// sequence legalAOpcode_S;
	// 	((h2d.a_opcode === tlul_pkg_PutFullData) || (h2d.a_opcode === tlul_pkg_Get)) || (h2d.a_opcode === tlul_pkg_PutPartialData)
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:113:3
	// removed an assertion item
	// sequence legalAParam_S;
	// 	h2d.a_param === '0
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:122:3
	// removed an assertion item
	// sequence sizeGTEMask_S;
	// 	(h2d.a_opcode == tlul_pkg_PutFullData) || ((1 << h2d.a_size) >= $countones(h2d.a_mask))
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:127:3
	// removed an assertion item
	// sequence sizeMatchesMask_S;
	// 	(h2d.a_opcode inside { tlul_pkg_PutPartialData, tlul_pkg_Get }) || ((1 << h2d.a_size) === $countones(h2d.a_mask))
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:133:3
	// removed an assertion item
	// sequence pendingReqPerSrc_S;
	// 	pend_req[h2d.a_source].pend == 0
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:138:3
	// removed an assertion item
	// sequence addrSizeAligned_S;
	// 	(h2d.a_address & ((1 << h2d.a_size) - 1)) == '0
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:146:3
	// removed an assertion item
	// sequence contigMask_pre_S;
	// 	h2d.a_opcode != tlul_pkg_PutPartialData
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:150:3
	// removed an assertion item
	// sequence contigMask_S;
	// 	$countones(h2d.a_mask ^ {h2d.a_mask[$bits(h2d.a_mask) - 2:0], 1'b0}) <= 2
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:155:3
	// removed an assertion item
	// sequence aDataKnown_pre_S;
	// 	h2d.a_opcode != tlul_pkg_Get
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:159:3
	// removed an assertion item
	// sequence aDataKnown_S;
	// 	(((((((!a_mask[0] || (a_mask[0] && !$isunknown(a_data[8 * 0+:8]))) && (!a_mask[1] || (a_mask[1] && !$isunknown(a_data[8 * 1+:8])))) && (!a_mask[2] || (a_mask[2] && !$isunknown(a_data[8 * 2+:8])))) && (!a_mask[3] || (a_mask[3] && !$isunknown(a_data[8 * 3+:8])))) && (!a_mask[4] || (a_mask[4] && !$isunknown(a_data[8 * 4+:8])))) && (!a_mask[5] || (a_mask[5] && !$isunknown(a_data[8 * 5+:8])))) && (!a_mask[6] || (a_mask[6] && !$isunknown(a_data[8 * 6+:8])))) && (!a_mask[7] || (a_mask[7] && !$isunknown(a_data[8 * 7+:8])))
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:175:3
	// removed an assertion item
	// sequence d2h_pre_S;
	// 	d2h.d_valid
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:180:3
	// removed an assertion item
	// sequence respOpcode_S;
	// 	d2h.d_opcode === (pend_req[d2h.d_source].opcode == tlul_pkg_Get ? tlul_pkg_AccessAckData : tlul_pkg_AccessAck)
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:185:3
	// removed an assertion item
	// sequence legalDParam_S;
	// 	d2h.d_param === '0
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:190:3
	// removed an assertion item
	// sequence respSzEqReqSz_S;
	// 	d2h.d_size === pend_req[d2h.d_source].size
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:195:3
	// removed an assertion item
	// sequence respMustHaveReq_S;
	// 	pend_req[d2h.d_source].pend
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:200:3
	// removed an assertion item
	// sequence dDataKnown_pre_S;
	// 	d2h.d_opcode == tlul_pkg_AccessAckData
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:204:3
	// removed an assertion item
	// sequence dDataKnown_S;
	// 	(((((((!d_mask[0] || (d_mask[0] && !$isunknown(d_data[8 * 0+:8]))) && (!d_mask[1] || (d_mask[1] && !$isunknown(d_data[8 * 1+:8])))) && (!d_mask[2] || (d_mask[2] && !$isunknown(d_data[8 * 2+:8])))) && (!d_mask[3] || (d_mask[3] && !$isunknown(d_data[8 * 3+:8])))) && (!d_mask[4] || (d_mask[4] && !$isunknown(d_data[8 * 4+:8])))) && (!d_mask[5] || (d_mask[5] && !$isunknown(d_data[8 * 5+:8])))) && (!d_mask[6] || (d_mask[6] && !$isunknown(d_data[8 * 6+:8])))) && (!d_mask[7] || (d_mask[7] && !$isunknown(d_data[8 * 7+:8])))
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:220:3
	// removed an assertion item
	// sequence d_error_pre_S;
	// 	h2d.a_valid && d2h.a_ready
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:224:3
	// removed an assertion item
	// sequence legalAOpcodeErr_S;
	// 	!(h2d.a_opcode inside { tlul_pkg_PutFullData, tlul_pkg_Get, tlul_pkg_PutPartialData })
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:228:3
	// removed an assertion item
	// sequence sizeGTEMaskErr_S;
	// 	(1 << h2d.a_size) < $countones(h2d.a_mask)
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:232:3
	// removed an assertion item
	// sequence sizeMatchesMaskErr_S;
	// 	(h2d.a_opcode == tlul_pkg_PutFullData) && ((1 << h2d.a_size) != $countones(h2d.a_mask))
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:236:3
	// removed an assertion item
	// sequence addrSizeAlignedErr_S;
	// 	(h2d.a_address & ((1 << h2d.a_size) - 1)) != '0
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:246:3
	generate
		if (EndpointType == "Host") begin : gen_host
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:248:94
			// removed an assertion item
			// legalAOpcode_A : assert property (@(posedge !clk_i) disable iff ((!rst_ni || disable_sva) !== '0)
			// 	(h2d_pre_S |-> legalAOpcode_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:248:649
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 248, "legalAOpcode_A");
			// end
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:249:79
			// removed an assertion item
			// legalAParam_A : assert property (@(posedge !clk_i) disable iff (!rst_ni !== '0)
			// 	(h2d_pre_S |-> legalAParam_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:249:634
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 249, "legalAParam_A");
			// end
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:250:94
			// removed an assertion item
			// sizeGTEMask_A : assert property (@(posedge !clk_i) disable iff ((!rst_ni || disable_sva) !== '0)
			// 	(h2d_pre_S |-> sizeGTEMask_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:250:649
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 250, "sizeGTEMask_A");
			// end
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:251:94
			// removed an assertion item
			// sizeMatchesMask_A : assert property (@(posedge !clk_i) disable iff ((!rst_ni || disable_sva) !== '0)
			// 	(h2d_pre_S |-> sizeMatchesMask_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:251:649
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 251, "sizeMatchesMask_A");
			// end
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:252:79
			// removed an assertion item
			// pendingReqPerSrc_A : assert property (@(posedge !clk_i) disable iff (!rst_ni !== '0)
			// 	(h2d_pre_S |-> pendingReqPerSrc_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:252:634
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 252, "pendingReqPerSrc_A");
			// end
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:253:94
			// removed an assertion item
			// addrSizeAligned_A : assert property (@(posedge !clk_i) disable iff ((!rst_ni || disable_sva) !== '0)
			// 	(h2d_pre_S |-> addrSizeAligned_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:253:649
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 253, "addrSizeAligned_A");
			// end
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:255:38
			// removed an assertion item
			// contigMask_A : assert property (@(posedge !clk_i) disable iff ((!rst_ni || disable_sva) !== '0)
			// 	((h2d_pre_S and contigMask_pre_S) |-> contigMask_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:255:593
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 255, "contigMask_A");
			// end
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:256:94
			// removed an assertion item
			// aDataKnown_A : assert property (@(posedge !clk_i) disable iff (!rst_ni !== '0)
			// 	((h2d_pre_S and aDataKnown_pre_S) |-> aDataKnown_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:256:649
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 256, "aDataKnown_A");
			// end
			// Trace: macro expansion of ASSUME at ips/tlul/tlul_assert.sv:258:79
			// removed an assertion item
			// respOpcode_M : assume property (@(posedge !clk_i) disable iff (!rst_ni !== '0)
			// 	(d2h_pre_S |-> respOpcode_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:258:634
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 258, "respOpcode_M");
			// end
			// Trace: macro expansion of ASSUME at ips/tlul/tlul_assert.sv:259:79
			// removed an assertion item
			// legalDParam_M : assume property (@(posedge !clk_i) disable iff (!rst_ni !== '0)
			// 	(d2h_pre_S |-> legalDParam_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:259:634
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 259, "legalDParam_M");
			// end
			// Trace: macro expansion of ASSUME at ips/tlul/tlul_assert.sv:260:79
			// removed an assertion item
			// respSzEqReqSz_M : assume property (@(posedge !clk_i) disable iff (!rst_ni !== '0)
			// 	(d2h_pre_S |-> respSzEqReqSz_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:260:634
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 260, "respSzEqReqSz_M");
			// end
			// Trace: macro expansion of ASSUME at ips/tlul/tlul_assert.sv:261:79
			// removed an assertion item
			// respMustHaveReq_M : assume property (@(posedge !clk_i) disable iff (!rst_ni !== '0)
			// 	(d2h_pre_S |-> respMustHaveReq_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:261:634
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 261, "respMustHaveReq_M");
			// end
			// Trace: macro expansion of ASSUME at ips/tlul/tlul_assert.sv:263:38
			// removed an assertion item
			// dDataKnown_M : assume property (@(posedge !clk_i) disable iff ((!rst_ni || disable_sva) !== '0)
			// 	((d2h_pre_S and dDataKnown_pre_S) |-> dDataKnown_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:263:593
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 263, "dDataKnown_M");
			// end
		end
		else if (EndpointType == "Device") begin : gen_device
			// Trace: macro expansion of ASSUME at ips/tlul/tlul_assert.sv:267:80
			// removed an assertion item
			// legalAParam_M : assume property (@(posedge !clk_i) disable iff (!rst_ni !== '0)
			// 	(h2d_pre_S |-> legalAParam_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:267:635
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 267, "legalAParam_M");
			// end
			// Trace: macro expansion of ASSUME at ips/tlul/tlul_assert.sv:268:80
			// removed an assertion item
			// pendingReqPerSrc_M : assume property (@(posedge !clk_i) disable iff (!rst_ni !== '0)
			// 	(h2d_pre_S |-> pendingReqPerSrc_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:268:635
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 268, "pendingReqPerSrc_M");
			// end
			// Trace: macro expansion of ASSUME at ips/tlul/tlul_assert.sv:269:95
			// removed an assertion item
			// aDataKnown_M : assume property (@(posedge !clk_i) disable iff (!rst_ni !== '0)
			// 	((h2d_pre_S and aDataKnown_pre_S) |-> aDataKnown_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:269:650
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 269, "aDataKnown_M");
			// end
			// Trace: macro expansion of ASSUME at ips/tlul/tlul_assert.sv:271:40
			// removed an assertion item
			// contigMask_M : assume property (@(posedge !clk_i) disable iff ((!rst_ni || disable_sva) !== '0)
			// 	((h2d_pre_S and contigMask_pre_S) |-> contigMask_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:271:595
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 271, "contigMask_M");
			// end
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:273:80
			// removed an assertion item
			// respOpcode_A : assert property (@(posedge !clk_i) disable iff (!rst_ni !== '0)
			// 	(d2h_pre_S |-> respOpcode_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:273:635
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 273, "respOpcode_A");
			// end
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:274:80
			// removed an assertion item
			// legalDParam_A : assert property (@(posedge !clk_i) disable iff (!rst_ni !== '0)
			// 	(d2h_pre_S |-> legalDParam_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:274:635
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 274, "legalDParam_A");
			// end
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:275:80
			// removed an assertion item
			// respSzEqReqSz_A : assert property (@(posedge !clk_i) disable iff (!rst_ni !== '0)
			// 	(d2h_pre_S |-> respSzEqReqSz_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:275:635
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 275, "respSzEqReqSz_A");
			// end
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:276:80
			// removed an assertion item
			// respMustHaveReq_A : assert property (@(posedge !clk_i) disable iff (!rst_ni !== '0)
			// 	(d2h_pre_S |-> respMustHaveReq_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:276:635
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 276, "respMustHaveReq_A");
			// end
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:278:38
			// removed an assertion item
			// dDataKnown_A : assert property (@(posedge !clk_i) disable iff ((!rst_ni || disable_sva) !== '0)
			// 	((d2h_pre_S and dDataKnown_pre_S) |-> dDataKnown_S)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:278:593
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 278, "dDataKnown_A");
			// end
		end
		else begin : gen_unknown
			// Trace: ips/tlul/tlul_assert.sv:289:5
			initial begin : p_unknonw
				// Trace: macro expansion of ASSERT_I at ips/tlul/tlul_assert.sv:290:35
				begin : unknownConfig_A
					
				end
			end
		end
	endgenerate
	// Trace: ips/tlul/tlul_assert.sv:294:3
	initial begin : p_dbw
		// Trace: macro expansion of ASSERT_I at ips/tlul/tlul_assert.sv:296:30
		begin : TlDbw_A
			
		end
	end
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:312:300
	// removed an assertion item
	// aKnown_AKnownEnable : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(h2d.a_valid)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:312:855
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 312, "aKnown_AKnownEnable");
	// end
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:312:325
	// removed an assertion item
	// aKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(h2d.a_valid |-> !$isunknown({h2d.a_size, h2d.a_source, h2d.a_address, h2d.a_mask, h2d.a_user}))
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:312:880
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 312, "aKnown_A");
	// end
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:316:378
	// removed an assertion item
	// dKnown_AKnownEnable : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(d2h.d_valid)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:316:933
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 316, "dKnown_AKnownEnable");
	// end
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:316:403
	// removed an assertion item
	// dKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(d2h.d_valid |-> !$isunknown({d2h.d_source, d2h.d_sink, d2h.d_error, d2h.d_user}))
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:316:958
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 316, "dKnown_A");
	// end
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:319:174
	// removed an assertion item
	// aReadyKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(d2h.a_ready)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:319:729
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 319, "aReadyKnown_A");
	// end
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_assert.sv:320:174
	// removed an assertion item
	// dReadyKnown_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	!$isunknown(h2d.d_ready)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_assert.sv:320:729
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_assert.sv", 320, "dReadyKnown_A");
	// end
	// Trace: ips/tlul/tlul_assert.sv:328:3
	// removed an assertion item
	// sequence b2bReq_S;
	// 	h2d.a_valid && d2h.a_ready ##(1) h2d.a_valid
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:333:3
	// removed an assertion item
	// sequence b2bRsp_S;
	// 	d2h.d_valid && h2d.d_ready ##(1) d2h.d_valid
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:346:3
	// removed an assertion item
	// sequence aValidNotAccepted_S;
	// 	h2d.a_valid && !d2h.a_ready ##(1) !h2d.a_valid
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:351:3
	// removed an assertion item
	// sequence dValidNotAccepted_S;
	// 	d2h.d_valid && !h2d.d_ready ##(1) !d2h.d_valid
	// endsequence
	// Trace: ips/tlul/tlul_assert.sv:380:3
	generate
		if (EndpointType == "Host") begin : gen_host_cov
			// Trace: macro expansion of COVER at ips/tlul/tlul_assert.sv:381:70
			// removed an assertion item
			// b2bRsp_C : cover property (@(posedge !clk_i) disable iff ((!rst_ni || disable_sva) !== '0)
			// 	b2bRsp_S
			// );
			// Trace: macro expansion of COVER at ips/tlul/tlul_assert.sv:382:81
			// removed an assertion item
			// dValidNotAccepted_C : cover property (@(posedge !clk_i) disable iff ((!rst_ni || disable_sva) !== '0)
			// 	dValidNotAccepted_S
			// );
		end
		else if (EndpointType == "Device") begin : gen_device_cov
			// Trace: macro expansion of COVER at ips/tlul/tlul_assert.sv:390:70
			// removed an assertion item
			// b2bReq_C : cover property (@(posedge !clk_i) disable iff ((!rst_ni || disable_sva) !== '0)
			// 	b2bReq_S
			// );
			// Trace: macro expansion of COVER at ips/tlul/tlul_assert.sv:391:82
			// removed an assertion item
			// b2bReqWithSameAddr_C : cover property (@(posedge !clk_i) disable iff ((!rst_ni || disable_sva) !== '0)
			// 	b2bReqWithSameAddr_S
			// );
			// Trace: macro expansion of COVER at ips/tlul/tlul_assert.sv:392:81
			// removed an assertion item
			// aValidNotAccepted_C : cover property (@(posedge !clk_i) disable iff ((!rst_ni || disable_sva) !== '0)
			// 	aValidNotAccepted_S
			// );
			// Trace: macro expansion of COVER at ips/tlul/tlul_assert.sv:393:77
			// removed an assertion item
			// b2bSameSource_C : cover property (@(posedge !clk_i) disable iff ((!rst_ni || disable_sva) !== '0)
			// 	b2bSameSource_S
			// );
		end
		else begin : gen_unknown_cov
			// Trace: ips/tlul/tlul_assert.sv:401:5
			initial begin : p_unknonw_cov
				// Trace: macro expansion of ASSERT_I at ips/tlul/tlul_assert.sv:402:35
				begin : unknownConfig_A
					
				end
			end
		end
	endgenerate
	// Trace: ips/tlul/tlul_assert.sv:425:5
	always @(posedge clk_i or negedge rst_ni)
		// Trace: ips/tlul/tlul_assert.sv:426:7
		if (!rst_ni) begin
			// Trace: ips/tlul/tlul_assert.sv:427:9
			disable_sva <= 0;
			// Trace: ips/tlul/tlul_assert.sv:428:9
			disable_d_error_sva <= 0;
		end
endmodule
module tlul_assert_multiple (
	clk_i,
	rst_ni,
	h2d,
	d2h
);
	// Trace: ips/tlul/tlul_assert_multiple.sv:8:13
	parameter [31:0] N = 2;
	// Trace: ips/tlul/tlul_assert_multiple.sv:9:13
	parameter EndpointType = "Device";
	// Trace: ips/tlul/tlul_assert_multiple.sv:11:3
	input clk_i;
	// Trace: ips/tlul/tlul_assert_multiple.sv:12:3
	input rst_ni;
	// Trace: ips/tlul/tlul_assert_multiple.sv:15:3
	// removed localparam type tlul_pkg_tl_a_op_e
	localparam signed [31:0] prim_mubi_pkg_MuBi4Width = 4;
	// removed localparam type prim_mubi_pkg_mubi4_t
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	localparam signed [31:0] tlul_pkg_H2DCmdIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_a_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_AW = 32;
	localparam signed [31:0] top_pkg_TL_DW = 32;
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_h2d_t
	input wire [(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (N * ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24)) - 1 : (N * (1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 22)):(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 0 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23)] h2d;
	// Trace: ips/tlul/tlul_assert_multiple.sv:16:3
	// removed localparam type tlul_pkg_tl_d_op_e
	localparam signed [31:0] tlul_pkg_D2HRspIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_d_user_t
	localparam signed [31:0] top_pkg_TL_DIW = 1;
	// removed localparam type tlul_pkg_tl_d2h_t
	input wire [((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? (N * ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 2)) - 1 : (N * (1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1))) + ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 0)):((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? 0 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1)] d2h;
	// Trace: ips/tlul/tlul_assert_multiple.sv:20:3
	genvar _gv_ii_1;
	generate
		for (_gv_ii_1 = 0; _gv_ii_1 < N; _gv_ii_1 = _gv_ii_1 + 1) begin : gen_assert
			localparam ii = _gv_ii_1;
			// Trace: ips/tlul/tlul_assert_multiple.sv:21:5
			tlul_assert #(.EndpointType(EndpointType)) tlul_assert(
				.clk_i(clk_i),
				.rst_ni(rst_ni),
				.h2d(h2d[(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 0 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) + (((N - 1) - ii) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23)))+:(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))]),
				.d2h(d2h[((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? 0 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1) + (((N - 1) - ii) * ((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 2 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1)))+:((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 2 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1))])
			);
		end
	endgenerate
endmodule
module tlul_cmd_intg_chk (
	tl_i,
	err_o
);
	// removed import tlul_pkg::*;
	// Trace: ips/tlul/tlul_cmd_intg_chk.sv:13:3
	// removed localparam type tlul_pkg_tl_a_op_e
	localparam signed [31:0] prim_mubi_pkg_MuBi4Width = 4;
	// removed localparam type prim_mubi_pkg_mubi4_t
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	localparam signed [31:0] tlul_pkg_H2DCmdIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_a_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_AW = 32;
	localparam signed [31:0] top_pkg_TL_DW = 32;
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_h2d_t
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_i;
	// Trace: ips/tlul/tlul_cmd_intg_chk.sv:16:3
	output wire err_o;
	// Trace: ips/tlul/tlul_cmd_intg_chk.sv:19:3
	wire [1:0] err;
	// Trace: ips/tlul/tlul_cmd_intg_chk.sv:20:3
	wire data_err;
	// Trace: ips/tlul/tlul_cmd_intg_chk.sv:21:3
	// removed localparam type tlul_pkg_tl_h2d_cmd_intg_t
	wire [(((prim_mubi_pkg_MuBi4Width + top_pkg_TL_AW) + 3) + top_pkg_TL_DBW) - 1:0] cmd;
	// Trace: ips/tlul/tlul_cmd_intg_chk.sv:22:3
	function automatic [(((prim_mubi_pkg_MuBi4Width + top_pkg_TL_AW) + 3) + top_pkg_TL_DBW) - 1:0] tlul_pkg_extract_h2d_cmd_intg;
		// Trace: ips/pkgs/tlul_pkg.sv:148:61
		input reg [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl;
		// Trace: ips/pkgs/tlul_pkg.sv:149:5
		reg [(((prim_mubi_pkg_MuBi4Width + top_pkg_TL_AW) + 3) + top_pkg_TL_DBW) - 1:0] payload;
		// Trace: ips/pkgs/tlul_pkg.sv:150:5
		reg unused_tlul;
		begin
			// Trace: ips/pkgs/tlul_pkg.sv:151:5
			unused_tlul = ^tl;
			// Trace: ips/pkgs/tlul_pkg.sv:152:5
			payload[top_pkg_TL_AW + (top_pkg_TL_DBW + 2)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 2)) >= (3 + (top_pkg_TL_DBW + 0)) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 2)) - (3 + (top_pkg_TL_DBW + 0))) + 1 : ((3 + (top_pkg_TL_DBW + 0)) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 2))) + 1)] = tl[top_pkg_TL_AW + (top_pkg_TL_DBW + 55)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)];
			// Trace: ips/pkgs/tlul_pkg.sv:153:5
			payload[top_pkg_TL_DBW + 2-:((top_pkg_TL_DBW + 2) >= (top_pkg_TL_DBW + 0) ? ((top_pkg_TL_DBW + 2) - (top_pkg_TL_DBW + 0)) + 1 : ((top_pkg_TL_DBW + 0) - (top_pkg_TL_DBW + 2)) + 1)] = tl[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)];
			// Trace: ips/pkgs/tlul_pkg.sv:154:5
			payload[top_pkg_TL_DBW - 1-:top_pkg_TL_DBW] = tl[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))];
			// Trace: ips/pkgs/tlul_pkg.sv:155:5
			payload[prim_mubi_pkg_MuBi4Width + (top_pkg_TL_AW + (top_pkg_TL_DBW + 2))-:(((32'sd4 + 32'sd32) + (top_pkg_TL_DBW + 2)) >= (35 + (top_pkg_TL_DBW + 0)) ? ((prim_mubi_pkg_MuBi4Width + (top_pkg_TL_AW + (top_pkg_TL_DBW + 2))) - (top_pkg_TL_AW + (3 + (top_pkg_TL_DBW + 0)))) + 1 : ((top_pkg_TL_AW + (3 + (top_pkg_TL_DBW + 0))) - (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_AW + (top_pkg_TL_DBW + 2)))) + 1)] = tl[18-:4];
			// Trace: ips/pkgs/tlul_pkg.sv:156:5
			tlul_pkg_extract_h2d_cmd_intg = payload;
		end
	endfunction
	assign cmd = tlul_pkg_extract_h2d_cmd_intg(tl_i);
	// Trace: ips/tlul/tlul_cmd_intg_chk.sv:24:3
	localparam signed [31:0] tlul_pkg_H2DCmdMaxWidth = 57;
	function automatic [56:0] sv2v_cast_57;
		input reg [56:0] inp;
		sv2v_cast_57 = inp;
	endfunction
	prim_secded_inv_64_57_dec u_chk(
		.data_i({tl_i[14-:7], sv2v_cast_57(cmd)}),
		.data_o(),
		.syndrome_o(),
		.err_o(err)
	);
	// Trace: ips/tlul/tlul_cmd_intg_chk.sv:31:3
	localparam signed [31:0] tlul_pkg_DataMaxWidth = 32;
	function automatic [31:0] sv2v_cast_32;
		input reg [31:0] inp;
		sv2v_cast_32 = inp;
	endfunction
	tlul_data_integ_dec u_tlul_data_integ_dec(
		.data_intg_i({tl_i[7-:tlul_pkg_DataIntgWidth], sv2v_cast_32(tl_i[55-:32])}),
		.data_err_o(data_err)
	);
	// Trace: ips/tlul/tlul_cmd_intg_chk.sv:44:3
	assign err_o = tl_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] & (|err | (|data_err));
	// Trace: ips/tlul/tlul_cmd_intg_chk.sv:48:3
	wire unused_tl;
	// Trace: ips/tlul/tlul_cmd_intg_chk.sv:49:3
	assign unused_tl = |tl_i;
	// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_cmd_intg_chk.sv:51:413
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_cmd_intg_chk.sv:51:501
		begin : PayLoadWidthCheck
			
		end
	end
endmodule
module tlul_cmd_intg_gen (
	tl_i,
	tl_o
);
	reg _sv2v_0;
	// removed import tlul_pkg::*;
	// Trace: ips/tlul/tlul_cmd_intg_gen.sv:12:13
	parameter [0:0] EnableCmdIntgGen = 1'b1;
	// Trace: ips/tlul/tlul_cmd_intg_gen.sv:13:13
	parameter [0:0] EnableDataIntgGen = 1'b1;
	// Trace: ips/tlul/tlul_cmd_intg_gen.sv:16:3
	// removed localparam type tlul_pkg_tl_a_op_e
	localparam signed [31:0] prim_mubi_pkg_MuBi4Width = 4;
	// removed localparam type prim_mubi_pkg_mubi4_t
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	localparam signed [31:0] tlul_pkg_H2DCmdIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_a_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_AW = 32;
	localparam signed [31:0] top_pkg_TL_DW = 32;
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_h2d_t
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_i;
	// Trace: ips/tlul/tlul_cmd_intg_gen.sv:17:3
	output reg [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_o;
	// Trace: ips/tlul/tlul_cmd_intg_gen.sv:20:3
	wire [6:0] cmd_intg;
	// Trace: ips/tlul/tlul_cmd_intg_gen.sv:22:3
	localparam signed [31:0] tlul_pkg_H2DCmdMaxWidth = 57;
	// removed localparam type tlul_pkg_tl_h2d_cmd_intg_t
	function automatic [(((prim_mubi_pkg_MuBi4Width + top_pkg_TL_AW) + 3) + top_pkg_TL_DBW) - 1:0] tlul_pkg_extract_h2d_cmd_intg;
		// Trace: ips/pkgs/tlul_pkg.sv:148:61
		input reg [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl;
		// Trace: ips/pkgs/tlul_pkg.sv:149:5
		reg [(((prim_mubi_pkg_MuBi4Width + top_pkg_TL_AW) + 3) + top_pkg_TL_DBW) - 1:0] payload;
		// Trace: ips/pkgs/tlul_pkg.sv:150:5
		reg unused_tlul;
		begin
			// Trace: ips/pkgs/tlul_pkg.sv:151:5
			unused_tlul = ^tl;
			// Trace: ips/pkgs/tlul_pkg.sv:152:5
			payload[top_pkg_TL_AW + (top_pkg_TL_DBW + 2)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 2)) >= (3 + (top_pkg_TL_DBW + 0)) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 2)) - (3 + (top_pkg_TL_DBW + 0))) + 1 : ((3 + (top_pkg_TL_DBW + 0)) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 2))) + 1)] = tl[top_pkg_TL_AW + (top_pkg_TL_DBW + 55)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)];
			// Trace: ips/pkgs/tlul_pkg.sv:153:5
			payload[top_pkg_TL_DBW + 2-:((top_pkg_TL_DBW + 2) >= (top_pkg_TL_DBW + 0) ? ((top_pkg_TL_DBW + 2) - (top_pkg_TL_DBW + 0)) + 1 : ((top_pkg_TL_DBW + 0) - (top_pkg_TL_DBW + 2)) + 1)] = tl[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)];
			// Trace: ips/pkgs/tlul_pkg.sv:154:5
			payload[top_pkg_TL_DBW - 1-:top_pkg_TL_DBW] = tl[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))];
			// Trace: ips/pkgs/tlul_pkg.sv:155:5
			payload[prim_mubi_pkg_MuBi4Width + (top_pkg_TL_AW + (top_pkg_TL_DBW + 2))-:(((32'sd4 + 32'sd32) + (top_pkg_TL_DBW + 2)) >= (35 + (top_pkg_TL_DBW + 0)) ? ((prim_mubi_pkg_MuBi4Width + (top_pkg_TL_AW + (top_pkg_TL_DBW + 2))) - (top_pkg_TL_AW + (3 + (top_pkg_TL_DBW + 0)))) + 1 : ((top_pkg_TL_AW + (3 + (top_pkg_TL_DBW + 0))) - (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_AW + (top_pkg_TL_DBW + 2)))) + 1)] = tl[18-:4];
			// Trace: ips/pkgs/tlul_pkg.sv:156:5
			tlul_pkg_extract_h2d_cmd_intg = payload;
		end
	endfunction
	function automatic [56:0] sv2v_cast_57;
		input reg [56:0] inp;
		sv2v_cast_57 = inp;
	endfunction
	generate
		if (EnableCmdIntgGen) begin : gen_cmd_intg
			// Trace: ips/tlul/tlul_cmd_intg_gen.sv:23:5
			wire [(((prim_mubi_pkg_MuBi4Width + top_pkg_TL_AW) + 3) + top_pkg_TL_DBW) - 1:0] cmd;
			// Trace: ips/tlul/tlul_cmd_intg_gen.sv:24:5
			assign cmd = tlul_pkg_extract_h2d_cmd_intg(tl_i);
			// Trace: ips/tlul/tlul_cmd_intg_gen.sv:25:5
			wire [56:0] unused_cmd_payload;
			// Trace: ips/tlul/tlul_cmd_intg_gen.sv:27:5
			prim_secded_inv_64_57_enc u_cmd_gen(
				.data_i(sv2v_cast_57(cmd)),
				.data_o({cmd_intg, unused_cmd_payload})
			);
		end
		else begin : gen_no_cmd_intg
			// Trace: ips/tlul/tlul_cmd_intg_gen.sv:32:5
			assign cmd_intg = tl_i[14-:7];
		end
	endgenerate
	// Trace: ips/tlul/tlul_cmd_intg_gen.sv:35:3
	wire [31:0] data_final;
	// Trace: ips/tlul/tlul_cmd_intg_gen.sv:36:3
	wire [6:0] data_intg;
	// Trace: ips/tlul/tlul_cmd_intg_gen.sv:38:3
	localparam signed [31:0] tlul_pkg_DataMaxWidth = 32;
	function automatic [31:0] sv2v_cast_32;
		input reg [31:0] inp;
		sv2v_cast_32 = inp;
	endfunction
	generate
		if (EnableDataIntgGen) begin : gen_data_intg
			// Trace: ips/tlul/tlul_cmd_intg_gen.sv:39:5
			assign data_final = tl_i[55-:32];
			// Trace: ips/tlul/tlul_cmd_intg_gen.sv:41:5
			wire [31:0] unused_data;
			// Trace: ips/tlul/tlul_cmd_intg_gen.sv:42:5
			prim_secded_inv_39_32_enc u_data_gen(
				.data_i(sv2v_cast_32(data_final)),
				.data_o({data_intg, unused_data})
			);
		end
		else begin : gen_passthrough_data_intg
			// Trace: ips/tlul/tlul_cmd_intg_gen.sv:47:5
			assign data_final = tl_i[55-:32];
			// Trace: ips/tlul/tlul_cmd_intg_gen.sv:48:5
			assign data_intg = tl_i[7-:tlul_pkg_DataIntgWidth];
		end
	endgenerate
	// Trace: ips/tlul/tlul_cmd_intg_gen.sv:51:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: ips/tlul/tlul_cmd_intg_gen.sv:52:5
		tl_o = tl_i;
		// Trace: ips/tlul/tlul_cmd_intg_gen.sv:53:5
		tl_o[55-:32] = data_final;
		// Trace: ips/tlul/tlul_cmd_intg_gen.sv:54:5
		tl_o[14-:7] = cmd_intg;
		// Trace: ips/tlul/tlul_cmd_intg_gen.sv:55:5
		tl_o[7-:tlul_pkg_DataIntgWidth] = data_intg;
	end
	// Trace: ips/tlul/tlul_cmd_intg_gen.sv:59:3
	wire unused_tl;
	// Trace: ips/tlul/tlul_cmd_intg_gen.sv:60:3
	assign unused_tl = ^tl_i;
	// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_cmd_intg_gen.sv:62:414
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_cmd_intg_gen.sv:62:502
		begin : PayMaxWidthCheck_A
			
		end
	end
	initial _sv2v_0 = 0;
endmodule
module tlul_data_integ_dec (
	data_intg_i,
	data_err_o
);
	// removed import tlul_pkg::*;
	// Trace: ips/tlul/tlul_data_integ_dec.sv:13:3
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	localparam signed [31:0] tlul_pkg_DataMaxWidth = 32;
	input [(tlul_pkg_DataMaxWidth + tlul_pkg_DataIntgWidth) - 1:0] data_intg_i;
	// Trace: ips/tlul/tlul_data_integ_dec.sv:14:3
	output wire data_err_o;
	// Trace: ips/tlul/tlul_data_integ_dec.sv:17:3
	wire [1:0] data_err;
	// Trace: ips/tlul/tlul_data_integ_dec.sv:18:3
	prim_secded_inv_39_32_dec u_data_chk(
		.data_i(data_intg_i),
		.data_o(),
		.syndrome_o(),
		.err_o(data_err)
	);
	// Trace: ips/tlul/tlul_data_integ_dec.sv:25:3
	assign data_err_o = |data_err;
endmodule
module tlul_data_integ_enc (
	data_i,
	data_intg_o
);
	// removed import tlul_pkg::*;
	// Trace: ips/tlul/tlul_data_integ_enc.sv:13:3
	localparam signed [31:0] tlul_pkg_DataMaxWidth = 32;
	input [31:0] data_i;
	// Trace: ips/tlul/tlul_data_integ_enc.sv:14:3
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	output wire [(tlul_pkg_DataMaxWidth + tlul_pkg_DataIntgWidth) - 1:0] data_intg_o;
	// Trace: ips/tlul/tlul_data_integ_enc.sv:17:3
	prim_secded_inv_39_32_enc u_data_gen(
		.data_i(data_i),
		.data_o(data_intg_o)
	);
endmodule
module tlul_err (
	clk_i,
	rst_ni,
	tl_i,
	err_o
);
	reg _sv2v_0;
	// removed import tlul_pkg::*;
	// Trace: ips/tlul/tlul_err.sv:9:3
	input clk_i;
	// Trace: ips/tlul/tlul_err.sv:10:3
	input rst_ni;
	// Trace: ips/tlul/tlul_err.sv:12:3
	// removed localparam type tlul_pkg_tl_a_op_e
	localparam signed [31:0] prim_mubi_pkg_MuBi4Width = 4;
	// removed localparam type prim_mubi_pkg_mubi4_t
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	localparam signed [31:0] tlul_pkg_H2DCmdIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_a_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_AW = 32;
	localparam signed [31:0] top_pkg_TL_DW = 32;
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_h2d_t
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_i;
	// Trace: ips/tlul/tlul_err.sv:14:3
	output wire err_o;
	// Trace: ips/tlul/tlul_err.sv:17:3
	localparam signed [31:0] IW = top_pkg_TL_AIW;
	// Trace: ips/tlul/tlul_err.sv:18:3
	localparam signed [31:0] SZW = top_pkg_TL_SZW;
	// Trace: ips/tlul/tlul_err.sv:19:3
	localparam signed [31:0] DW = top_pkg_TL_DW;
	// Trace: ips/tlul/tlul_err.sv:20:3
	localparam signed [31:0] MW = top_pkg_TL_DBW;
	// Trace: ips/tlul/tlul_err.sv:21:3
	localparam signed [31:0] SubAW = 2;
	// Trace: ips/tlul/tlul_err.sv:23:3
	wire opcode_allowed;
	wire a_config_allowed;
	// Trace: ips/tlul/tlul_err.sv:25:3
	wire op_full;
	wire op_partial;
	wire op_get;
	// Trace: ips/tlul/tlul_err.sv:26:3
	assign op_full = tl_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] == 3'h0;
	// Trace: ips/tlul/tlul_err.sv:27:3
	assign op_partial = tl_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] == 3'h1;
	// Trace: ips/tlul/tlul_err.sv:28:3
	assign op_get = tl_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] == 3'h4;
	// Trace: ips/tlul/tlul_err.sv:31:3
	wire instr_wr_err;
	// Trace: ips/tlul/tlul_err.sv:32:3
	function automatic [3:0] sv2v_cast_EECFA;
		input reg [3:0] inp;
		sv2v_cast_EECFA = inp;
	endfunction
	function automatic prim_mubi_pkg_mubi4_test_true_strict;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:43:51
		input reg [3:0] val;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:44:5
		prim_mubi_pkg_mubi4_test_true_strict = sv2v_cast_EECFA(4'h6) == val;
	endfunction
	assign instr_wr_err = prim_mubi_pkg_mubi4_test_true_strict(tl_i[18-:4]) & (op_full | op_partial);
	// Trace: ips/tlul/tlul_err.sv:35:3
	wire instr_type_err;
	// Trace: ips/tlul/tlul_err.sv:36:3
	function automatic prim_mubi_pkg_mubi4_test_invalid;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:31:47
		input reg [3:0] val;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:32:5
		prim_mubi_pkg_mubi4_test_invalid = ~(|{((sv2v_cast_EECFA(4'h6) ^ (val ^ val)) === (val ^ (sv2v_cast_EECFA(4'h6) ^ sv2v_cast_EECFA(4'h6)))) & ((((val ^ val) ^ (sv2v_cast_EECFA(4'h6) ^ sv2v_cast_EECFA(4'h6))) === (sv2v_cast_EECFA(4'h6) ^ sv2v_cast_EECFA(4'h6))) | 1'bx), ((sv2v_cast_EECFA(4'h9) ^ (val ^ val)) === (val ^ (sv2v_cast_EECFA(4'h9) ^ sv2v_cast_EECFA(4'h9)))) & ((((val ^ val) ^ (sv2v_cast_EECFA(4'h9) ^ sv2v_cast_EECFA(4'h9))) === (sv2v_cast_EECFA(4'h9) ^ sv2v_cast_EECFA(4'h9))) | 1'bx)});
	endfunction
	assign instr_type_err = prim_mubi_pkg_mubi4_test_invalid(tl_i[18-:4]);
	// Trace: ips/tlul/tlul_err.sv:39:3
	assign err_o = (~(opcode_allowed & a_config_allowed) | instr_wr_err) | instr_type_err;
	// Trace: ips/tlul/tlul_err.sv:42:3
	assign opcode_allowed = ((tl_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] == 3'h0) | (tl_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] == 3'h1)) | (tl_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] == 3'h4);
	// Trace: ips/tlul/tlul_err.sv:47:3
	reg addr_sz_chk;
	// Trace: ips/tlul/tlul_err.sv:48:3
	reg mask_chk;
	// Trace: ips/tlul/tlul_err.sv:49:3
	reg fulldata_chk;
	// Trace: ips/tlul/tlul_err.sv:51:3
	localparam [MW - 1:0] MaskOne = 1;
	// Trace: ips/tlul/tlul_err.sv:52:3
	wire [MW - 1:0] mask;
	// Trace: ips/tlul/tlul_err.sv:54:3
	assign mask = MaskOne << tl_i[(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - 30:(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - 31];
	// Trace: ips/tlul/tlul_err.sv:56:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: ips/tlul/tlul_err.sv:57:5
		addr_sz_chk = 1'b0;
		// Trace: ips/tlul/tlul_err.sv:58:5
		mask_chk = 1'b0;
		// Trace: ips/tlul/tlul_err.sv:59:5
		fulldata_chk = 1'b0;
		// Trace: ips/tlul/tlul_err.sv:61:5
		if (tl_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))])
			// Trace: ips/tlul/tlul_err.sv:62:7
			(* full_case, parallel_case *)
			case (tl_i[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)])
				'h0: begin
					// Trace: ips/tlul/tlul_err.sv:64:11
					addr_sz_chk = 1'b1;
					// Trace: ips/tlul/tlul_err.sv:65:11
					mask_chk = ~|(tl_i[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))] & ~mask);
					// Trace: ips/tlul/tlul_err.sv:66:11
					fulldata_chk = |(tl_i[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))] & mask);
				end
				'h1: begin
					// Trace: ips/tlul/tlul_err.sv:70:11
					addr_sz_chk = ~tl_i[(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - 31];
					// Trace: ips/tlul/tlul_err.sv:72:11
					mask_chk = (tl_i[(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - 30] ? ~|(tl_i[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))] & 4'b0011) : ~|(tl_i[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))] & 4'b1100));
					// Trace: ips/tlul/tlul_err.sv:74:11
					fulldata_chk = (tl_i[(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - 30] ? &tl_i[(top_pkg_TL_DBW + 55) - (top_pkg_TL_DBW - 4):(top_pkg_TL_DBW + 55) - (top_pkg_TL_DBW - 3)] : &tl_i[(top_pkg_TL_DBW + 55) - (top_pkg_TL_DBW - 2):(top_pkg_TL_DBW + 55) - (top_pkg_TL_DBW - 1)]);
				end
				'h2: begin
					// Trace: ips/tlul/tlul_err.sv:78:11
					addr_sz_chk = ~|tl_i[(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - 30:(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - 31];
					// Trace: ips/tlul/tlul_err.sv:79:11
					mask_chk = 1'b1;
					// Trace: ips/tlul/tlul_err.sv:80:11
					fulldata_chk = &tl_i[(top_pkg_TL_DBW + 55) - (top_pkg_TL_DBW - 4):(top_pkg_TL_DBW + 55) - (top_pkg_TL_DBW - 1)];
				end
				default: begin
					// Trace: ips/tlul/tlul_err.sv:84:11
					addr_sz_chk = 1'b0;
					// Trace: ips/tlul/tlul_err.sv:85:11
					mask_chk = 1'b0;
					// Trace: ips/tlul/tlul_err.sv:86:11
					fulldata_chk = 1'b0;
				end
			endcase
		else begin
			// Trace: ips/tlul/tlul_err.sv:90:7
			addr_sz_chk = 1'b0;
			// Trace: ips/tlul/tlul_err.sv:91:7
			mask_chk = 1'b0;
			// Trace: ips/tlul/tlul_err.sv:92:7
			fulldata_chk = 1'b0;
		end
	end
	// Trace: ips/tlul/tlul_err.sv:96:3
	assign a_config_allowed = (addr_sz_chk & mask_chk) & ((op_get | op_partial) | fulldata_chk);
	// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_err.sv:101:379
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_err.sv:101:467
		begin : dataWidthOnly32_A
			
		end
	end
	initial _sv2v_0 = 0;
endmodule
module tlul_err_resp (
	clk_i,
	rst_ni,
	tl_h_i,
	tl_h_o
);
	// Trace: ips/tlul/tlul_err_resp.sv:10:3
	input clk_i;
	// Trace: ips/tlul/tlul_err_resp.sv:11:3
	input rst_ni;
	// Trace: ips/tlul/tlul_err_resp.sv:12:3
	// removed localparam type tlul_pkg_tl_a_op_e
	localparam signed [31:0] prim_mubi_pkg_MuBi4Width = 4;
	// removed localparam type prim_mubi_pkg_mubi4_t
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	localparam signed [31:0] tlul_pkg_H2DCmdIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_a_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_AW = 32;
	localparam signed [31:0] top_pkg_TL_DW = 32;
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_h2d_t
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_h_i;
	// Trace: ips/tlul/tlul_err_resp.sv:13:3
	// removed localparam type tlul_pkg_tl_d_op_e
	localparam signed [31:0] tlul_pkg_D2HRspIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_d_user_t
	localparam signed [31:0] top_pkg_TL_DIW = 1;
	// removed localparam type tlul_pkg_tl_d2h_t
	output wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_h_o;
	// Trace: ips/tlul/tlul_err_resp.sv:15:3
	// removed import tlul_pkg::*;
	// Trace: ips/tlul/tlul_err_resp.sv:16:3
	// removed import prim_mubi_pkg::*;
	// Trace: ips/tlul/tlul_err_resp.sv:18:3
	reg [2:0] err_opcode;
	// Trace: ips/tlul/tlul_err_resp.sv:19:3
	reg [7:0] err_source;
	// Trace: ips/tlul/tlul_err_resp.sv:20:3
	reg [top_pkg_TL_SZW - 1:0] err_size;
	// Trace: ips/tlul/tlul_err_resp.sv:21:3
	reg err_rsp_pending;
	// Trace: ips/tlul/tlul_err_resp.sv:22:3
	reg [3:0] err_instr_type;
	// Trace: ips/tlul/tlul_err_resp.sv:23:3
	wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_h_o_int;
	// Trace: ips/tlul/tlul_err_resp.sv:25:3
	tlul_rsp_intg_gen #(
		.EnableRspIntgGen(0),
		.EnableDataIntgGen(0)
	) u_intg_gen(
		.tl_i(tl_h_o_int),
		.tl_o(tl_h_o)
	);
	// Trace: ips/tlul/tlul_err_resp.sv:33:3
	function automatic [3:0] sv2v_cast_EECFA;
		input reg [3:0] inp;
		sv2v_cast_EECFA = inp;
	endfunction
	always @(posedge clk_i or negedge rst_ni)
		// Trace: ips/tlul/tlul_err_resp.sv:34:5
		if (!rst_ni) begin
			// Trace: ips/tlul/tlul_err_resp.sv:35:7
			err_rsp_pending <= 1'b0;
			// Trace: ips/tlul/tlul_err_resp.sv:36:7
			err_source <= {top_pkg_TL_AIW {1'b0}};
			// Trace: ips/tlul/tlul_err_resp.sv:37:7
			err_opcode <= 3'h4;
			// Trace: ips/tlul/tlul_err_resp.sv:38:7
			err_size <= 1'sb0;
			// Trace: ips/tlul/tlul_err_resp.sv:39:7
			err_instr_type <= sv2v_cast_EECFA(4'h9);
		end
		else if (err_rsp_pending && tl_h_i[0])
			// Trace: ips/tlul/tlul_err_resp.sv:41:7
			err_rsp_pending <= 1'b0;
		else if (tl_h_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] && tl_h_o_int[0]) begin
			// Trace: ips/tlul/tlul_err_resp.sv:43:7
			err_rsp_pending <= 1'b1;
			// Trace: ips/tlul/tlul_err_resp.sv:44:7
			err_source <= tl_h_i[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)];
			// Trace: ips/tlul/tlul_err_resp.sv:45:7
			err_opcode <= tl_h_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)];
			// Trace: ips/tlul/tlul_err_resp.sv:46:7
			err_size <= tl_h_i[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)];
			// Trace: ips/tlul/tlul_err_resp.sv:47:7
			err_instr_type <= tl_h_i[18-:4];
		end
	// Trace: ips/tlul/tlul_err_resp.sv:51:3
	assign tl_h_o_int[0] = ~err_rsp_pending;
	// Trace: ips/tlul/tlul_err_resp.sv:52:3
	assign tl_h_o_int[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))] = err_rsp_pending;
	// Trace: ips/tlul/tlul_err_resp.sv:53:3
	function automatic prim_mubi_pkg_mubi4_test_true_strict;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:43:51
		input reg [3:0] val;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:44:5
		prim_mubi_pkg_mubi4_test_true_strict = sv2v_cast_EECFA(4'h6) == val;
	endfunction
	localparam [31:0] tlul_pkg_DataWhenError = {top_pkg_TL_DW {1'b1}};
	localparam [31:0] tlul_pkg_DataWhenInstrError = 1'sb0;
	assign tl_h_o_int[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)] = (prim_mubi_pkg_mubi4_test_true_strict(err_instr_type) ? tlul_pkg_DataWhenInstrError : tlul_pkg_DataWhenError);
	// Trace: ips/tlul/tlul_err_resp.sv:55:3
	assign tl_h_o_int[top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))-:((32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))) >= ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) + 1 : ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) + 1)] = err_source;
	// Trace: ips/tlul/tlul_err_resp.sv:56:3
	assign tl_h_o_int[top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))-:(((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)) >= (32'sd32 + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) + 1 : ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) + 1)] = 1'sb0;
	// Trace: ips/tlul/tlul_err_resp.sv:57:3
	assign tl_h_o_int[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)] = 1'sb0;
	// Trace: ips/tlul/tlul_err_resp.sv:58:3
	assign tl_h_o_int[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))-:((top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)))) >= (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) + 1)] = err_size;
	// Trace: ips/tlul/tlul_err_resp.sv:59:3
	assign tl_h_o_int[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((6 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)] = (err_opcode == 3'h4 ? 3'h1 : 3'h0);
	// Trace: ips/tlul/tlul_err_resp.sv:60:3
	assign tl_h_o_int[(tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1-:(((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) >= 2 ? (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 0 : 3 - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))] = 1'sb0;
	// Trace: ips/tlul/tlul_err_resp.sv:61:3
	assign tl_h_o_int[1] = 1'b1;
	// Trace: ips/tlul/tlul_err_resp.sv:64:3
	wire unused_tl_h;
	// Trace: ips/tlul/tlul_err_resp.sv:65:3
	assign unused_tl_h = ^tl_h_i;
endmodule
module tlul_fifo_async (
	clk_h_i,
	rst_h_ni,
	clk_d_i,
	rst_d_ni,
	tl_h_i,
	tl_h_o,
	tl_d_o,
	tl_d_i
);
	// Trace: ips/tlul/tlul_fifo_async.sv:12:13
	parameter [31:0] ReqDepth = 4;
	// Trace: ips/tlul/tlul_fifo_async.sv:13:13
	parameter [31:0] RspDepth = 4;
	// Trace: ips/tlul/tlul_fifo_async.sv:15:3
	input clk_h_i;
	// Trace: ips/tlul/tlul_fifo_async.sv:16:3
	input rst_h_ni;
	// Trace: ips/tlul/tlul_fifo_async.sv:17:3
	input clk_d_i;
	// Trace: ips/tlul/tlul_fifo_async.sv:18:3
	input rst_d_ni;
	// Trace: ips/tlul/tlul_fifo_async.sv:19:3
	// removed localparam type tlul_pkg_tl_a_op_e
	localparam signed [31:0] prim_mubi_pkg_MuBi4Width = 4;
	// removed localparam type prim_mubi_pkg_mubi4_t
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	localparam signed [31:0] tlul_pkg_H2DCmdIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_a_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_AW = 32;
	localparam signed [31:0] top_pkg_TL_DW = 32;
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_h2d_t
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_h_i;
	// Trace: ips/tlul/tlul_fifo_async.sv:20:3
	// removed localparam type tlul_pkg_tl_d_op_e
	localparam signed [31:0] tlul_pkg_D2HRspIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_d_user_t
	localparam signed [31:0] top_pkg_TL_DIW = 1;
	// removed localparam type tlul_pkg_tl_d2h_t
	output wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_h_o;
	// Trace: ips/tlul/tlul_fifo_async.sv:21:3
	output wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_d_o;
	// Trace: ips/tlul/tlul_fifo_async.sv:22:3
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_d_i;
	// Trace: ips/tlul/tlul_fifo_async.sv:26:3
	localparam [31:0] REQFIFO_WIDTH = (1 * ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24)) - 2;
	// Trace: ips/tlul/tlul_fifo_async.sv:28:3
	prim_fifo_async #(
		.Width(REQFIFO_WIDTH),
		.Depth(ReqDepth),
		.OutputZeroIfInvalid(1)
	) reqfifo(
		.clk_wr_i(clk_h_i),
		.rst_wr_ni(rst_h_ni),
		.clk_rd_i(clk_d_i),
		.rst_rd_ni(rst_d_ni),
		.wvalid_i(tl_h_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))]),
		.wready_o(tl_h_o[0]),
		.wdata_i({tl_h_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)], tl_h_i[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)], tl_h_i[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)], tl_h_i[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)], tl_h_i[top_pkg_TL_AW + (top_pkg_TL_DBW + 55)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)], tl_h_i[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))], tl_h_i[55-:32], tl_h_i[23-:23]}),
		.rvalid_o(tl_d_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))]),
		.rready_i(tl_d_i[0]),
		.rdata_o({tl_d_o[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)], tl_d_o[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)], tl_d_o[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)], tl_d_o[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)], tl_d_o[top_pkg_TL_AW + (top_pkg_TL_DBW + 55)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)], tl_d_o[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))], tl_d_o[55-:32], tl_d_o[23-:23]}),
		.wdepth_o(),
		.rdepth_o()
	);
	// Trace: ips/tlul/tlul_fifo_async.sv:63:3
	localparam [31:0] RSPFIFO_WIDTH = (1 * ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 2)) - 2;
	// Trace: ips/tlul/tlul_fifo_async.sv:65:3
	prim_fifo_async #(
		.Width(RSPFIFO_WIDTH),
		.Depth(RspDepth),
		.OutputZeroIfInvalid(1)
	) rspfifo(
		.clk_wr_i(clk_d_i),
		.rst_wr_ni(rst_d_ni),
		.clk_rd_i(clk_h_i),
		.rst_rd_ni(rst_h_ni),
		.wvalid_i(tl_d_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))]),
		.wready_o(tl_d_o[0]),
		.wdata_i({tl_d_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((6 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)], tl_d_i[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)], tl_d_i[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))-:((top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)))) >= (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) + 1)], tl_d_i[top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))-:((32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))) >= ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) + 1 : ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) + 1)], tl_d_i[top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))-:(((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)) >= (32'sd32 + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) + 1 : ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) + 1)], tl_d_i[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)], tl_d_i[(tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1-:(((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) >= 2 ? (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 0 : 3 - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))], tl_d_i[1]}),
		.rvalid_o(tl_h_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))]),
		.rready_i(tl_h_i[0]),
		.rdata_o({tl_h_o[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((6 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)], tl_h_o[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)], tl_h_o[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))-:((top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)))) >= (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) + 1)], tl_h_o[top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))-:((32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))) >= ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) + 1 : ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) + 1)], tl_h_o[top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))-:(((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)) >= (32'sd32 + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) + 1 : ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) + 1)], tl_h_o[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)], tl_h_o[(tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1-:(((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) >= 2 ? (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 0 : 3 - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))], tl_h_o[1]}),
		.wdepth_o(),
		.rdepth_o()
	);
endmodule
module tlul_fifo_sync (
	clk_i,
	rst_ni,
	tl_h_i,
	tl_h_o,
	tl_d_o,
	tl_d_i,
	spare_req_i,
	spare_req_o,
	spare_rsp_i,
	spare_rsp_o
);
	// Trace: ips/tlul/tlul_fifo_sync.sv:10:13
	parameter [0:0] ReqPass = 1'b1;
	// Trace: ips/tlul/tlul_fifo_sync.sv:11:13
	parameter [0:0] RspPass = 1'b1;
	// Trace: ips/tlul/tlul_fifo_sync.sv:12:13
	parameter [31:0] ReqDepth = 2;
	// Trace: ips/tlul/tlul_fifo_sync.sv:13:13
	parameter [31:0] RspDepth = 2;
	// Trace: ips/tlul/tlul_fifo_sync.sv:14:13
	parameter [31:0] SpareReqW = 1;
	// Trace: ips/tlul/tlul_fifo_sync.sv:15:13
	parameter [31:0] SpareRspW = 1;
	// Trace: ips/tlul/tlul_fifo_sync.sv:17:3
	input clk_i;
	// Trace: ips/tlul/tlul_fifo_sync.sv:18:3
	input rst_ni;
	// Trace: ips/tlul/tlul_fifo_sync.sv:19:3
	// removed localparam type tlul_pkg_tl_a_op_e
	localparam signed [31:0] prim_mubi_pkg_MuBi4Width = 4;
	// removed localparam type prim_mubi_pkg_mubi4_t
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	localparam signed [31:0] tlul_pkg_H2DCmdIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_a_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_AW = 32;
	localparam signed [31:0] top_pkg_TL_DW = 32;
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_h2d_t
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_h_i;
	// Trace: ips/tlul/tlul_fifo_sync.sv:20:3
	// removed localparam type tlul_pkg_tl_d_op_e
	localparam signed [31:0] tlul_pkg_D2HRspIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_d_user_t
	localparam signed [31:0] top_pkg_TL_DIW = 1;
	// removed localparam type tlul_pkg_tl_d2h_t
	output wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_h_o;
	// Trace: ips/tlul/tlul_fifo_sync.sv:21:3
	output wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_d_o;
	// Trace: ips/tlul/tlul_fifo_sync.sv:22:3
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_d_i;
	// Trace: ips/tlul/tlul_fifo_sync.sv:23:3
	input [SpareReqW - 1:0] spare_req_i;
	// Trace: ips/tlul/tlul_fifo_sync.sv:24:3
	output wire [SpareReqW - 1:0] spare_req_o;
	// Trace: ips/tlul/tlul_fifo_sync.sv:25:3
	input [SpareRspW - 1:0] spare_rsp_i;
	// Trace: ips/tlul/tlul_fifo_sync.sv:26:3
	output wire [SpareRspW - 1:0] spare_rsp_o;
	// Trace: ips/tlul/tlul_fifo_sync.sv:30:3
	localparam [31:0] REQFIFO_WIDTH = ((1 * ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24)) - 2) + SpareReqW;
	// Trace: ips/tlul/tlul_fifo_sync.sv:32:3
	prim_fifo_sync #(
		.Width(REQFIFO_WIDTH),
		.Pass(ReqPass),
		.Depth(ReqDepth)
	) reqfifo(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.clr_i(1'b0),
		.wvalid_i(tl_h_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))]),
		.wready_o(tl_h_o[0]),
		.wdata_i({tl_h_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)], tl_h_i[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)], tl_h_i[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)], tl_h_i[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)], tl_h_i[top_pkg_TL_AW + (top_pkg_TL_DBW + 55)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)], tl_h_i[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))], tl_h_i[55-:32], tl_h_i[23-:23], spare_req_i}),
		.rvalid_o(tl_d_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))]),
		.rready_i(tl_d_i[0]),
		.rdata_o({tl_d_o[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)], tl_d_o[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)], tl_d_o[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)], tl_d_o[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)], tl_d_o[top_pkg_TL_AW + (top_pkg_TL_DBW + 55)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)], tl_d_o[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))], tl_d_o[55-:32], tl_d_o[23-:23], spare_req_o}),
		.full_o(),
		.depth_o(),
		.err_o()
	);
	// Trace: ips/tlul/tlul_fifo_sync.sv:64:3
	localparam [31:0] RSPFIFO_WIDTH = ((1 * ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 2)) - 2) + SpareRspW;
	// Trace: ips/tlul/tlul_fifo_sync.sv:66:3
	prim_fifo_sync #(
		.Width(RSPFIFO_WIDTH),
		.Pass(RspPass),
		.Depth(RspDepth)
	) rspfifo(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.clr_i(1'b0),
		.wvalid_i(tl_d_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))]),
		.wready_o(tl_d_o[0]),
		.wdata_i({tl_d_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((6 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)], tl_d_i[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)], tl_d_i[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))-:((top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)))) >= (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) + 1)], tl_d_i[top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))-:((32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))) >= ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) + 1 : ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) + 1)], tl_d_i[top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))-:(((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)) >= (32'sd32 + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) + 1 : ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) + 1)], (tl_d_i[6 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))-:((6 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))))) ? ((6 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) - (3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)))))) + 1 : ((3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))))) - (6 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)))))) + 1)] == 3'h1 ? tl_d_i[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)] : {top_pkg_TL_DW {1'b0}}), tl_d_i[(tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1-:(((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) >= 2 ? (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 0 : 3 - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))], tl_d_i[1], spare_rsp_i}),
		.rvalid_o(tl_h_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))]),
		.rready_i(tl_h_i[0]),
		.rdata_o({tl_h_o[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((6 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)], tl_h_o[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)], tl_h_o[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))-:((top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)))) >= (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) + 1)], tl_h_o[top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))-:((32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))) >= ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) + 1 : ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) + 1)], tl_h_o[top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))-:(((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)) >= (32'sd32 + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) + 1 : ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) + 1)], tl_h_o[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)], tl_h_o[(tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1-:(((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) >= 2 ? (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 0 : 3 - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))], tl_h_o[1], spare_rsp_o}),
		.full_o(),
		.depth_o(),
		.err_o()
	);
endmodule
module tlul_rsp_intg_chk (
	tl_i,
	err_o
);
	// removed import tlul_pkg::*;
	// Trace: ips/tlul/tlul_rsp_intg_chk.sv:12:13
	parameter [0:0] EnableRspDataIntgCheck = 0;
	// Trace: ips/tlul/tlul_rsp_intg_chk.sv:15:3
	// removed localparam type tlul_pkg_tl_d_op_e
	localparam signed [31:0] tlul_pkg_D2HRspIntgWidth = 7;
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_d_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_DIW = 1;
	localparam signed [31:0] top_pkg_TL_DW = 32;
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_d2h_t
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_i;
	// Trace: ips/tlul/tlul_rsp_intg_chk.sv:18:3
	output wire err_o;
	// Trace: ips/tlul/tlul_rsp_intg_chk.sv:21:3
	wire [1:0] rsp_err;
	// Trace: ips/tlul/tlul_rsp_intg_chk.sv:22:3
	// removed localparam type tlul_pkg_tl_d2h_rsp_intg_t
	wire [(3 + top_pkg_TL_SZW) + 0:0] rsp;
	// Trace: ips/tlul/tlul_rsp_intg_chk.sv:23:3
	function automatic [(3 + top_pkg_TL_SZW) + 0:0] tlul_pkg_extract_d2h_rsp_intg;
		// Trace: ips/pkgs/tlul_pkg.sv:160:61
		input reg [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl;
		// Trace: ips/pkgs/tlul_pkg.sv:161:5
		reg [(3 + top_pkg_TL_SZW) + 0:0] payload;
		// Trace: ips/pkgs/tlul_pkg.sv:162:5
		reg unused_tlul;
		begin
			// Trace: ips/pkgs/tlul_pkg.sv:163:5
			unused_tlul = ^tl;
			// Trace: ips/pkgs/tlul_pkg.sv:164:5
			payload[3 + (top_pkg_TL_SZW + 0)-:((3 + (top_pkg_TL_SZW + 0)) >= (top_pkg_TL_SZW + 1) ? ((3 + (top_pkg_TL_SZW + 0)) - (top_pkg_TL_SZW + 1)) + 1 : ((top_pkg_TL_SZW + 1) - (3 + (top_pkg_TL_SZW + 0))) + 1)] = tl[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((6 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)];
			// Trace: ips/pkgs/tlul_pkg.sv:165:5
			payload[top_pkg_TL_SZW + 0-:((top_pkg_TL_SZW + 0) >= 1 ? top_pkg_TL_SZW + 0 : 2 - (top_pkg_TL_SZW + 0))] = tl[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))-:((top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)))) >= (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) + 1)];
			// Trace: ips/pkgs/tlul_pkg.sv:167:5
			payload[0] = tl[1];
			// Trace: ips/pkgs/tlul_pkg.sv:168:5
			tlul_pkg_extract_d2h_rsp_intg = payload;
		end
	endfunction
	assign rsp = tlul_pkg_extract_d2h_rsp_intg(tl_i);
	// Trace: ips/tlul/tlul_rsp_intg_chk.sv:25:3
	localparam signed [31:0] tlul_pkg_D2HRspMaxWidth = 57;
	function automatic [56:0] sv2v_cast_57;
		input reg [56:0] inp;
		sv2v_cast_57 = inp;
	endfunction
	prim_secded_inv_64_57_dec u_chk(
		.data_i({tl_i[((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) - 14)-:7], sv2v_cast_57(rsp)}),
		.data_o(),
		.syndrome_o(),
		.err_o(rsp_err)
	);
	// Trace: ips/tlul/tlul_rsp_intg_chk.sv:32:3
	wire rsp_data_err;
	// Trace: ips/tlul/tlul_rsp_intg_chk.sv:33:3
	localparam signed [31:0] tlul_pkg_DataMaxWidth = 32;
	function automatic [31:0] sv2v_cast_32;
		input reg [31:0] inp;
		sv2v_cast_32 = inp;
	endfunction
	generate
		if (EnableRspDataIntgCheck) begin : gen_rsp_data_intg_check
			// Trace: ips/tlul/tlul_rsp_intg_chk.sv:34:5
			tlul_data_integ_dec u_tlul_data_integ_dec(
				.data_intg_i({tl_i[((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) - 7)-:tlul_pkg_DataIntgWidth], sv2v_cast_32(tl_i[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)])}),
				.data_err_o(rsp_data_err)
			);
		end
		else begin : gen_no_rsp_data_intg_check
			// Trace: ips/tlul/tlul_rsp_intg_chk.sv:39:5
			assign rsp_data_err = 1'b0;
		end
	endgenerate
	// Trace: ips/tlul/tlul_rsp_intg_chk.sv:47:3
	assign err_o = tl_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))] & (|rsp_err | rsp_data_err);
	// Trace: ips/tlul/tlul_rsp_intg_chk.sv:49:3
	wire unused_tl;
	// Trace: ips/tlul/tlul_rsp_intg_chk.sv:50:3
	assign unused_tl = |tl_i;
	// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_rsp_intg_chk.sv:52:413
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_rsp_intg_chk.sv:52:501
		begin : PayLoadWidthCheck
			
		end
	end
endmodule
module tlul_rsp_intg_gen (
	tl_i,
	tl_o
);
	reg _sv2v_0;
	// removed import tlul_pkg::*;
	// Trace: ips/tlul/tlul_rsp_intg_gen.sv:12:13
	parameter [0:0] EnableRspIntgGen = 1'b1;
	// Trace: ips/tlul/tlul_rsp_intg_gen.sv:13:13
	parameter [0:0] EnableDataIntgGen = 1'b1;
	// Trace: ips/tlul/tlul_rsp_intg_gen.sv:16:3
	// removed localparam type tlul_pkg_tl_d_op_e
	localparam signed [31:0] tlul_pkg_D2HRspIntgWidth = 7;
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_d_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_DIW = 1;
	localparam signed [31:0] top_pkg_TL_DW = 32;
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_d2h_t
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_i;
	// Trace: ips/tlul/tlul_rsp_intg_gen.sv:17:3
	output reg [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_o;
	// Trace: ips/tlul/tlul_rsp_intg_gen.sv:20:3
	localparam signed [31:0] tlul_pkg_D2HRspMaxWidth = 57;
	localparam signed [31:0] tlul_pkg_DataMaxWidth = 32;
	// removed localparam type tlul_pkg_tl_d2h_rsp_intg_t
	function automatic [(3 + top_pkg_TL_SZW) + 0:0] tlul_pkg_extract_d2h_rsp_intg;
		// Trace: ips/pkgs/tlul_pkg.sv:160:61
		input reg [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl;
		// Trace: ips/pkgs/tlul_pkg.sv:161:5
		reg [(3 + top_pkg_TL_SZW) + 0:0] payload;
		// Trace: ips/pkgs/tlul_pkg.sv:162:5
		reg unused_tlul;
		begin
			// Trace: ips/pkgs/tlul_pkg.sv:163:5
			unused_tlul = ^tl;
			// Trace: ips/pkgs/tlul_pkg.sv:164:5
			payload[3 + (top_pkg_TL_SZW + 0)-:((3 + (top_pkg_TL_SZW + 0)) >= (top_pkg_TL_SZW + 1) ? ((3 + (top_pkg_TL_SZW + 0)) - (top_pkg_TL_SZW + 1)) + 1 : ((top_pkg_TL_SZW + 1) - (3 + (top_pkg_TL_SZW + 0))) + 1)] = tl[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((6 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)];
			// Trace: ips/pkgs/tlul_pkg.sv:165:5
			payload[top_pkg_TL_SZW + 0-:((top_pkg_TL_SZW + 0) >= 1 ? top_pkg_TL_SZW + 0 : 2 - (top_pkg_TL_SZW + 0))] = tl[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))-:((top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)))) >= (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) + 1)];
			// Trace: ips/pkgs/tlul_pkg.sv:167:5
			payload[0] = tl[1];
			// Trace: ips/pkgs/tlul_pkg.sv:168:5
			tlul_pkg_extract_d2h_rsp_intg = payload;
		end
	endfunction
	function automatic [56:0] sv2v_cast_57;
		input reg [56:0] inp;
		sv2v_cast_57 = inp;
	endfunction
	function automatic [31:0] sv2v_cast_32;
		input reg [31:0] inp;
		sv2v_cast_32 = inp;
	endfunction
	generate
		if (EnableRspIntgGen) begin : gen_rsp_intg
			// Trace: ips/tlul/tlul_rsp_intg_gen.sv:21:5
			wire [6:0] rsp_intg;
			// Trace: ips/tlul/tlul_rsp_intg_gen.sv:22:5
			wire [(3 + top_pkg_TL_SZW) + 0:0] rsp;
			// Trace: ips/tlul/tlul_rsp_intg_gen.sv:23:5
			wire [56:0] unused_payload;
			// Trace: ips/tlul/tlul_rsp_intg_gen.sv:25:5
			assign rsp = tlul_pkg_extract_d2h_rsp_intg(tl_i);
			// Trace: ips/tlul/tlul_rsp_intg_gen.sv:27:5
			prim_secded_inv_64_57_enc u_rsp_gen(
				.data_i(sv2v_cast_57(rsp)),
				.data_o({rsp_intg, unused_payload})
			);
			// Trace: ips/tlul/tlul_rsp_intg_gen.sv:31:5
			wire [6:0] data_intg;
			if (EnableDataIntgGen) begin : gen_data_intg
				// Trace: ips/tlul/tlul_rsp_intg_gen.sv:33:7
				wire [31:0] unused_data;
				// Trace: ips/tlul/tlul_rsp_intg_gen.sv:34:7
				tlul_data_integ_enc u_tlul_data_integ_enc(
					.data_i(sv2v_cast_32(tl_i[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)])),
					.data_intg_o({data_intg, unused_data})
				);
			end
			else begin : gen_passthrough_data_intg
				// Trace: ips/tlul/tlul_rsp_intg_gen.sv:39:7
				assign data_intg = tl_i[((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) - 7)-:tlul_pkg_DataIntgWidth];
			end
			// Trace: ips/tlul/tlul_rsp_intg_gen.sv:42:5
			always @(*) begin
				if (_sv2v_0)
					;
				// Trace: ips/tlul/tlul_rsp_intg_gen.sv:43:7
				tl_o = tl_i;
				// Trace: ips/tlul/tlul_rsp_intg_gen.sv:44:7
				tl_o[((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) - 14)-:7] = rsp_intg;
				// Trace: ips/tlul/tlul_rsp_intg_gen.sv:45:7
				tl_o[((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) - 7)-:tlul_pkg_DataIntgWidth] = data_intg;
			end
		end
		else begin : gen_passthrough_rsp_intg
			// Trace: ips/tlul/tlul_rsp_intg_gen.sv:48:5
			wire [((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 2 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1)):1] sv2v_tmp_48555;
			assign sv2v_tmp_48555 = tl_i;
			always @(*) tl_o = sv2v_tmp_48555;
		end
	endgenerate
	// Trace: ips/tlul/tlul_rsp_intg_gen.sv:51:3
	wire unused_tl;
	// Trace: ips/tlul/tlul_rsp_intg_gen.sv:52:3
	assign unused_tl = ^tl_i;
	// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_rsp_intg_gen.sv:54:413
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_rsp_intg_gen.sv:54:501
		begin : PayLoadWidthCheck
			
		end
	end
	// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_rsp_intg_gen.sv:55:404
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_rsp_intg_gen.sv:55:492
		begin : DataWidthCheck_A
			
		end
	end
	initial _sv2v_0 = 0;
endmodule
module tlul_socket_1n (
	clk_i,
	rst_ni,
	tl_h_i,
	tl_h_o,
	tl_d_o,
	tl_d_i,
	dev_select_i
);
	reg _sv2v_0;
	// Trace: ips/tlul/tlul_socket_1n.sv:45:13
	parameter [31:0] N = 4;
	// Trace: ips/tlul/tlul_socket_1n.sv:46:13
	parameter [0:0] HReqPass = 1'b1;
	// Trace: ips/tlul/tlul_socket_1n.sv:47:13
	parameter [0:0] HRspPass = 1'b1;
	// Trace: ips/tlul/tlul_socket_1n.sv:48:13
	parameter [N - 1:0] DReqPass = {N {1'b1}};
	// Trace: ips/tlul/tlul_socket_1n.sv:49:13
	parameter [N - 1:0] DRspPass = {N {1'b1}};
	// Trace: ips/tlul/tlul_socket_1n.sv:50:13
	parameter [3:0] HReqDepth = 4'h1;
	// Trace: ips/tlul/tlul_socket_1n.sv:51:13
	parameter [3:0] HRspDepth = 4'h1;
	// Trace: ips/tlul/tlul_socket_1n.sv:52:13
	parameter [(N * 4) - 1:0] DReqDepth = {N {4'h1}};
	// Trace: ips/tlul/tlul_socket_1n.sv:53:13
	parameter [(N * 4) - 1:0] DRspDepth = {N {4'h1}};
	// Trace: ips/tlul/tlul_socket_1n.sv:54:13
	parameter [0:0] ExplicitErrs = 1'b1;
	// Trace: ips/tlul/tlul_socket_1n.sv:59:14
	localparam [31:0] NWD = $clog2((ExplicitErrs ? N + 1 : N));
	// Trace: ips/tlul/tlul_socket_1n.sv:61:3
	input clk_i;
	// Trace: ips/tlul/tlul_socket_1n.sv:62:3
	input rst_ni;
	// Trace: ips/tlul/tlul_socket_1n.sv:63:3
	// removed localparam type tlul_pkg_tl_a_op_e
	localparam signed [31:0] prim_mubi_pkg_MuBi4Width = 4;
	// removed localparam type prim_mubi_pkg_mubi4_t
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	localparam signed [31:0] tlul_pkg_H2DCmdIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_a_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_AW = 32;
	localparam signed [31:0] top_pkg_TL_DW = 32;
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_h2d_t
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_h_i;
	// Trace: ips/tlul/tlul_socket_1n.sv:64:3
	// removed localparam type tlul_pkg_tl_d_op_e
	localparam signed [31:0] tlul_pkg_D2HRspIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_d_user_t
	localparam signed [31:0] top_pkg_TL_DIW = 1;
	// removed localparam type tlul_pkg_tl_d2h_t
	output wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_h_o;
	// Trace: ips/tlul/tlul_socket_1n.sv:65:3
	output wire [(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (N * ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24)) - 1 : (N * (1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 22)):(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 0 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23)] tl_d_o;
	// Trace: ips/tlul/tlul_socket_1n.sv:66:3
	input wire [((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? (N * ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 2)) - 1 : (N * (1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1))) + ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 0)):((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? 0 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1)] tl_d_i;
	// Trace: ips/tlul/tlul_socket_1n.sv:67:3
	input [NWD - 1:0] dev_select_i;
	// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_socket_1n.sv:70:364
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_socket_1n.sv:70:452
		begin : maxN
			
		end
	end
	// Trace: ips/tlul/tlul_socket_1n.sv:78:3
	wire [NWD - 1:0] dev_select_t;
	// Trace: ips/tlul/tlul_socket_1n.sv:80:3
	wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_t_o;
	// Trace: ips/tlul/tlul_socket_1n.sv:81:3
	wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_t_i;
	// Trace: ips/tlul/tlul_socket_1n.sv:83:3
	tlul_fifo_sync #(
		.ReqPass(HReqPass),
		.RspPass(HRspPass),
		.ReqDepth(HReqDepth),
		.RspDepth(HRspDepth),
		.SpareReqW(NWD)
	) fifo_h(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.tl_h_i(tl_h_i),
		.tl_h_o(tl_h_o),
		.tl_d_o(tl_t_o),
		.tl_d_i(tl_t_i),
		.spare_req_i(dev_select_i),
		.spare_req_o(dev_select_t),
		.spare_rsp_i(1'b0),
		.spare_rsp_o()
	);
	// Trace: ips/tlul/tlul_socket_1n.sv:105:3
	localparam signed [31:0] MaxOutstanding = 256;
	// Trace: ips/tlul/tlul_socket_1n.sv:106:3
	localparam signed [31:0] OutstandingW = 9;
	// Trace: ips/tlul/tlul_socket_1n.sv:107:3
	reg [8:0] num_req_outstanding;
	// Trace: ips/tlul/tlul_socket_1n.sv:108:3
	reg [NWD - 1:0] dev_select_outstanding;
	// Trace: ips/tlul/tlul_socket_1n.sv:109:3
	wire hold_all_requests;
	// Trace: ips/tlul/tlul_socket_1n.sv:110:3
	wire accept_t_req;
	wire accept_t_rsp;
	// Trace: ips/tlul/tlul_socket_1n.sv:112:3
	assign accept_t_req = tl_t_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] & tl_t_i[0];
	// Trace: ips/tlul/tlul_socket_1n.sv:113:3
	assign accept_t_rsp = tl_t_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))] & tl_t_o[0];
	// Trace: ips/tlul/tlul_socket_1n.sv:115:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: ips/tlul/tlul_socket_1n.sv:116:5
		if (!rst_ni) begin
			// Trace: ips/tlul/tlul_socket_1n.sv:117:7
			num_req_outstanding <= 1'sb0;
			// Trace: ips/tlul/tlul_socket_1n.sv:118:7
			dev_select_outstanding <= 1'sb0;
		end
		else if (accept_t_req) begin
			// Trace: ips/tlul/tlul_socket_1n.sv:120:7
			if (!accept_t_rsp)
				// Trace: ips/tlul/tlul_socket_1n.sv:121:9
				num_req_outstanding <= num_req_outstanding + 1'b1;
			// Trace: ips/tlul/tlul_socket_1n.sv:123:7
			dev_select_outstanding <= dev_select_t;
		end
		else if (accept_t_rsp)
			// Trace: ips/tlul/tlul_socket_1n.sv:125:7
			num_req_outstanding <= num_req_outstanding - 1'b1;
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_socket_1n.sv:130:78
	// removed an assertion item
	// NotOverflowed_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(accept_t_req && !accept_t_rsp) -> (num_req_outstanding <= MaxOutstanding)
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_socket_1n.sv:130:633
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_socket_1n.sv", 130, "NotOverflowed_A");
	// end
	// Trace: ips/tlul/tlul_socket_1n.sv:132:3
	assign hold_all_requests = (num_req_outstanding != {9 {1'sb0}}) & (dev_select_t != dev_select_outstanding);
	// Trace: ips/tlul/tlul_socket_1n.sv:139:3
	wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_u_o [0:N + 0];
	// Trace: ips/tlul/tlul_socket_1n.sv:140:3
	wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_u_i [0:N + 0];
	// Trace: ips/tlul/tlul_socket_1n.sv:144:3
	wire [22:0] blanked_auser;
	// Trace: ips/tlul/tlul_socket_1n.sv:145:3
	localparam [31:0] tlul_pkg_BlankedAData = {top_pkg_TL_DW {1'b1}};
	function automatic [63:0] sv2v_cast_64;
		input reg [63:0] inp;
		sv2v_cast_64 = inp;
	endfunction
	function automatic [63:0] prim_secded_pkg_prim_secded_inv_64_57_enc;
		// Trace: ips/pkgs/prim_secded_pkg.sv:1212:34
		input reg [56:0] data_i;
		// Trace: ips/pkgs/prim_secded_pkg.sv:1213:5
		reg [63:0] data_o;
		begin
			// Trace: ips/pkgs/prim_secded_pkg.sv:1214:5
			data_o = sv2v_cast_64(data_i);
			// Trace: ips/pkgs/prim_secded_pkg.sv:1215:5
			data_o[57] = ^(data_o & 64'h0103fff800007fff);
			// Trace: ips/pkgs/prim_secded_pkg.sv:1216:5
			data_o[58] = ^(data_o & 64'h017c1ff801ff801f);
			// Trace: ips/pkgs/prim_secded_pkg.sv:1217:5
			data_o[59] = ^(data_o & 64'h01bde1f87e0781e1);
			// Trace: ips/pkgs/prim_secded_pkg.sv:1218:5
			data_o[60] = ^(data_o & 64'h01deee3b8e388e22);
			// Trace: ips/pkgs/prim_secded_pkg.sv:1219:5
			data_o[61] = ^(data_o & 64'h01ef76cdb2c93244);
			// Trace: ips/pkgs/prim_secded_pkg.sv:1220:5
			data_o[62] = ^(data_o & 64'h01f7bb56d5525488);
			// Trace: ips/pkgs/prim_secded_pkg.sv:1221:5
			data_o[63] = ^(data_o & 64'h01fbdda769a46910);
			// Trace: ips/pkgs/prim_secded_pkg.sv:1222:5
			data_o = data_o ^ 64'h5400000000000000;
			// Trace: ips/pkgs/prim_secded_pkg.sv:1223:5
			prim_secded_pkg_prim_secded_inv_64_57_enc = data_o;
		end
	endfunction
	localparam signed [31:0] tlul_pkg_H2DCmdMaxWidth = 57;
	// removed localparam type tlul_pkg_tl_h2d_cmd_intg_t
	function automatic [(((prim_mubi_pkg_MuBi4Width + top_pkg_TL_AW) + 3) + top_pkg_TL_DBW) - 1:0] tlul_pkg_extract_h2d_cmd_intg;
		// Trace: ips/pkgs/tlul_pkg.sv:148:61
		input reg [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl;
		// Trace: ips/pkgs/tlul_pkg.sv:149:5
		reg [(((prim_mubi_pkg_MuBi4Width + top_pkg_TL_AW) + 3) + top_pkg_TL_DBW) - 1:0] payload;
		// Trace: ips/pkgs/tlul_pkg.sv:150:5
		reg unused_tlul;
		begin
			// Trace: ips/pkgs/tlul_pkg.sv:151:5
			unused_tlul = ^tl;
			// Trace: ips/pkgs/tlul_pkg.sv:152:5
			payload[top_pkg_TL_AW + (top_pkg_TL_DBW + 2)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 2)) >= (3 + (top_pkg_TL_DBW + 0)) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 2)) - (3 + (top_pkg_TL_DBW + 0))) + 1 : ((3 + (top_pkg_TL_DBW + 0)) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 2))) + 1)] = tl[top_pkg_TL_AW + (top_pkg_TL_DBW + 55)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)];
			// Trace: ips/pkgs/tlul_pkg.sv:153:5
			payload[top_pkg_TL_DBW + 2-:((top_pkg_TL_DBW + 2) >= (top_pkg_TL_DBW + 0) ? ((top_pkg_TL_DBW + 2) - (top_pkg_TL_DBW + 0)) + 1 : ((top_pkg_TL_DBW + 0) - (top_pkg_TL_DBW + 2)) + 1)] = tl[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)];
			// Trace: ips/pkgs/tlul_pkg.sv:154:5
			payload[top_pkg_TL_DBW - 1-:top_pkg_TL_DBW] = tl[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))];
			// Trace: ips/pkgs/tlul_pkg.sv:155:5
			payload[prim_mubi_pkg_MuBi4Width + (top_pkg_TL_AW + (top_pkg_TL_DBW + 2))-:(((32'sd4 + 32'sd32) + (top_pkg_TL_DBW + 2)) >= (35 + (top_pkg_TL_DBW + 0)) ? ((prim_mubi_pkg_MuBi4Width + (top_pkg_TL_AW + (top_pkg_TL_DBW + 2))) - (top_pkg_TL_AW + (3 + (top_pkg_TL_DBW + 0)))) + 1 : ((top_pkg_TL_AW + (3 + (top_pkg_TL_DBW + 0))) - (prim_mubi_pkg_MuBi4Width + (top_pkg_TL_AW + (top_pkg_TL_DBW + 2)))) + 1)] = tl[18-:4];
			// Trace: ips/pkgs/tlul_pkg.sv:156:5
			tlul_pkg_extract_h2d_cmd_intg = payload;
		end
	endfunction
	function automatic [56:0] sv2v_cast_57;
		input reg [56:0] inp;
		sv2v_cast_57 = inp;
	endfunction
	function automatic [6:0] tlul_pkg_get_cmd_intg;
		// Trace: ips/pkgs/tlul_pkg.sv:172:63
		input reg [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl;
		// Trace: ips/pkgs/tlul_pkg.sv:173:5
		reg [6:0] cmd_intg;
		// Trace: ips/pkgs/tlul_pkg.sv:174:5
		reg [56:0] unused_cmd_payload;
		// Trace: ips/pkgs/tlul_pkg.sv:175:5
		reg [(((prim_mubi_pkg_MuBi4Width + top_pkg_TL_AW) + 3) + top_pkg_TL_DBW) - 1:0] cmd;
		begin
			// Trace: ips/pkgs/tlul_pkg.sv:176:5
			cmd = tlul_pkg_extract_h2d_cmd_intg(tl);
			// Trace: ips/pkgs/tlul_pkg.sv:177:5
			{cmd_intg, unused_cmd_payload} = prim_secded_pkg_prim_secded_inv_64_57_enc(sv2v_cast_57(cmd));
			// Trace: ips/pkgs/tlul_pkg.sv:179:4
			tlul_pkg_get_cmd_intg = cmd_intg;
		end
	endfunction
	function automatic [6:0] tlul_pkg_get_bad_cmd_intg;
		// Trace: ips/pkgs/tlul_pkg.sv:194:67
		input reg [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl;
		// Trace: ips/pkgs/tlul_pkg.sv:195:5
		reg [6:0] cmd_intg;
		begin
			// Trace: ips/pkgs/tlul_pkg.sv:196:5
			cmd_intg = tlul_pkg_get_cmd_intg(tl);
			// Trace: ips/pkgs/tlul_pkg.sv:197:5
			tlul_pkg_get_bad_cmd_intg = ~cmd_intg;
		end
	endfunction
	function automatic [38:0] sv2v_cast_39;
		input reg [38:0] inp;
		sv2v_cast_39 = inp;
	endfunction
	function automatic [38:0] prim_secded_pkg_prim_secded_inv_39_32_enc;
		// Trace: ips/pkgs/prim_secded_pkg.sv:1135:34
		input reg [31:0] data_i;
		// Trace: ips/pkgs/prim_secded_pkg.sv:1136:5
		reg [38:0] data_o;
		begin
			// Trace: ips/pkgs/prim_secded_pkg.sv:1137:5
			data_o = sv2v_cast_39(data_i);
			// Trace: ips/pkgs/prim_secded_pkg.sv:1138:5
			data_o[32] = ^(data_o & 39'h002606bd25);
			// Trace: ips/pkgs/prim_secded_pkg.sv:1139:5
			data_o[33] = ^(data_o & 39'h00deba8050);
			// Trace: ips/pkgs/prim_secded_pkg.sv:1140:5
			data_o[34] = ^(data_o & 39'h00413d89aa);
			// Trace: ips/pkgs/prim_secded_pkg.sv:1141:5
			data_o[35] = ^(data_o & 39'h0031234ed1);
			// Trace: ips/pkgs/prim_secded_pkg.sv:1142:5
			data_o[36] = ^(data_o & 39'h00c2c1323b);
			// Trace: ips/pkgs/prim_secded_pkg.sv:1143:5
			data_o[37] = ^(data_o & 39'h002dcc624c);
			// Trace: ips/pkgs/prim_secded_pkg.sv:1144:5
			data_o[38] = ^(data_o & 39'h0098505586);
			// Trace: ips/pkgs/prim_secded_pkg.sv:1145:5
			data_o = data_o ^ 39'h2a00000000;
			// Trace: ips/pkgs/prim_secded_pkg.sv:1146:5
			prim_secded_pkg_prim_secded_inv_39_32_enc = data_o;
		end
	endfunction
	function automatic [6:0] tlul_pkg_get_data_intg;
		// Trace: ips/pkgs/tlul_pkg.sv:183:62
		input reg [31:0] data;
		// Trace: ips/pkgs/tlul_pkg.sv:184:5
		reg [6:0] data_intg;
		// Trace: ips/pkgs/tlul_pkg.sv:185:5
		reg [31:0] unused_data;
		// Trace: ips/pkgs/tlul_pkg.sv:186:5
		reg [(tlul_pkg_DataIntgWidth + top_pkg_TL_DW) - 1:0] enc_data;
		begin
			// Trace: ips/pkgs/tlul_pkg.sv:187:5
			enc_data = prim_secded_pkg_prim_secded_inv_39_32_enc(data);
			// Trace: ips/pkgs/tlul_pkg.sv:188:5
			data_intg = enc_data[(tlul_pkg_DataIntgWidth + top_pkg_TL_DW) - 1:top_pkg_TL_DW];
			// Trace: ips/pkgs/tlul_pkg.sv:189:5
			unused_data = enc_data[31:0];
			// Trace: ips/pkgs/tlul_pkg.sv:190:5
			tlul_pkg_get_data_intg = data_intg;
		end
	endfunction
	function automatic [6:0] tlul_pkg_get_bad_data_intg;
		// Trace: ips/pkgs/tlul_pkg.sv:201:68
		input reg [31:0] data;
		// Trace: ips/pkgs/tlul_pkg.sv:202:5
		reg [6:0] data_intg;
		begin
			// Trace: ips/pkgs/tlul_pkg.sv:203:5
			data_intg = tlul_pkg_get_data_intg(data);
			// Trace: ips/pkgs/tlul_pkg.sv:204:5
			tlul_pkg_get_bad_data_intg = ~data_intg;
		end
	endfunction
	function automatic [4:0] sv2v_cast_5;
		input reg [4:0] inp;
		sv2v_cast_5 = inp;
	endfunction
	function automatic [3:0] sv2v_cast_EECFA;
		input reg [3:0] inp;
		sv2v_cast_EECFA = inp;
	endfunction
	function automatic [6:0] sv2v_cast_FE1F6;
		input reg [6:0] inp;
		sv2v_cast_FE1F6 = inp;
	endfunction
	function automatic [6:0] sv2v_cast_83AAC;
		input reg [6:0] inp;
		sv2v_cast_83AAC = inp;
	endfunction
	assign blanked_auser = {sv2v_cast_5(tl_t_o[23-:5]), sv2v_cast_EECFA(tl_t_o[18-:4]), sv2v_cast_FE1F6(tlul_pkg_get_bad_cmd_intg(tl_t_o)), sv2v_cast_83AAC(tlul_pkg_get_bad_data_intg(tlul_pkg_BlankedAData))};
	// Trace: ips/tlul/tlul_socket_1n.sv:153:3
	genvar _gv_i_2;
	function automatic signed [NWD - 1:0] sv2v_cast_1D9BB_signed;
		input reg signed [NWD - 1:0] inp;
		sv2v_cast_1D9BB_signed = inp;
	endfunction
	generate
		for (_gv_i_2 = 0; _gv_i_2 < N; _gv_i_2 = _gv_i_2 + 1) begin : gen_u_o
			localparam i = _gv_i_2;
			// Trace: ips/tlul/tlul_socket_1n.sv:154:5
			wire dev_select;
			// Trace: ips/tlul/tlul_socket_1n.sv:155:5
			assign dev_select = (dev_select_t == sv2v_cast_1D9BB_signed(i)) & ~hold_all_requests;
			// Trace: ips/tlul/tlul_socket_1n.sv:157:5
			assign tl_u_o[i][7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] = tl_t_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] & dev_select;
			// Trace: ips/tlul/tlul_socket_1n.sv:158:5
			assign tl_u_o[i][6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] = tl_t_o[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)];
			// Trace: ips/tlul/tlul_socket_1n.sv:159:5
			assign tl_u_o[i][3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] = tl_t_o[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)];
			// Trace: ips/tlul/tlul_socket_1n.sv:160:5
			assign tl_u_o[i][top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)] = tl_t_o[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)];
			// Trace: ips/tlul/tlul_socket_1n.sv:161:5
			assign tl_u_o[i][top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)] = tl_t_o[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)];
			// Trace: ips/tlul/tlul_socket_1n.sv:162:5
			assign tl_u_o[i][top_pkg_TL_AW + (top_pkg_TL_DBW + 55)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)] = tl_t_o[top_pkg_TL_AW + (top_pkg_TL_DBW + 55)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)];
			// Trace: ips/tlul/tlul_socket_1n.sv:163:5
			assign tl_u_o[i][top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))] = tl_t_o[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))];
			// Trace: ips/tlul/tlul_socket_1n.sv:164:5
			assign tl_u_o[i][55-:32] = (dev_select ? tl_t_o[55-:32] : tlul_pkg_BlankedAData);
			// Trace: ips/tlul/tlul_socket_1n.sv:167:5
			assign tl_u_o[i][23-:23] = (dev_select ? tl_t_o[23-:23] : blanked_auser);
			// Trace: ips/tlul/tlul_socket_1n.sv:171:5
			assign tl_u_o[i][0] = tl_t_o[0];
		end
	endgenerate
	// Trace: ips/tlul/tlul_socket_1n.sv:175:3
	reg [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_t_p;
	// Trace: ips/tlul/tlul_socket_1n.sv:178:3
	reg hfifo_reqready;
	// Trace: ips/tlul/tlul_socket_1n.sv:179:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: ips/tlul/tlul_socket_1n.sv:180:5
		hfifo_reqready = tl_u_i[N][0];
		// Trace: ips/tlul/tlul_socket_1n.sv:181:5
		begin : sv2v_autoblock_1
			// Trace: ips/tlul/tlul_socket_1n.sv:181:10
			reg signed [31:0] idx;
			// Trace: ips/tlul/tlul_socket_1n.sv:181:10
			for (idx = 0; idx < N; idx = idx + 1)
				begin
					// Trace: ips/tlul/tlul_socket_1n.sv:183:7
					if (dev_select_t == sv2v_cast_1D9BB_signed(idx))
						// Trace: ips/tlul/tlul_socket_1n.sv:183:38
						hfifo_reqready = tl_u_i[idx][0];
				end
		end
		if (hold_all_requests)
			// Trace: ips/tlul/tlul_socket_1n.sv:185:28
			hfifo_reqready = 1'b0;
	end
	// Trace: ips/tlul/tlul_socket_1n.sv:189:3
	assign tl_t_i[0] = tl_t_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] & hfifo_reqready;
	// Trace: ips/tlul/tlul_socket_1n.sv:191:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: ips/tlul/tlul_socket_1n.sv:192:5
		tl_t_p = tl_u_i[N];
		// Trace: ips/tlul/tlul_socket_1n.sv:193:5
		begin : sv2v_autoblock_2
			// Trace: ips/tlul/tlul_socket_1n.sv:193:10
			reg signed [31:0] idx;
			// Trace: ips/tlul/tlul_socket_1n.sv:193:10
			for (idx = 0; idx < N; idx = idx + 1)
				begin
					// Trace: ips/tlul/tlul_socket_1n.sv:194:7
					if (dev_select_outstanding == sv2v_cast_1D9BB_signed(idx))
						// Trace: ips/tlul/tlul_socket_1n.sv:194:48
						tl_t_p = tl_u_i[idx];
				end
		end
	end
	// Trace: ips/tlul/tlul_socket_1n.sv:197:3
	assign tl_t_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))] = tl_t_p[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))];
	// Trace: ips/tlul/tlul_socket_1n.sv:198:3
	assign tl_t_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((6 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)] = tl_t_p[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((6 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)];
	// Trace: ips/tlul/tlul_socket_1n.sv:199:3
	assign tl_t_i[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)] = tl_t_p[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)];
	// Trace: ips/tlul/tlul_socket_1n.sv:200:3
	assign tl_t_i[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))-:((top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)))) >= (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) + 1)] = tl_t_p[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))-:((top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)))) >= (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) + 1)];
	// Trace: ips/tlul/tlul_socket_1n.sv:201:3
	assign tl_t_i[top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))-:((32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))) >= ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) + 1 : ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) + 1)] = tl_t_p[top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))-:((32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))) >= ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) + 1 : ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) + 1)];
	// Trace: ips/tlul/tlul_socket_1n.sv:202:3
	assign tl_t_i[top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))-:(((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)) >= (32'sd32 + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) + 1 : ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) + 1)] = tl_t_p[top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))-:(((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)) >= (32'sd32 + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) + 1 : ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) + 1)];
	// Trace: ips/tlul/tlul_socket_1n.sv:203:3
	assign tl_t_i[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)] = tl_t_p[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)];
	// Trace: ips/tlul/tlul_socket_1n.sv:204:3
	assign tl_t_i[(tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1-:(((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) >= 2 ? (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 0 : 3 - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))] = tl_t_p[(tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1-:(((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) >= 2 ? (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 0 : 3 - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))];
	// Trace: ips/tlul/tlul_socket_1n.sv:205:3
	assign tl_t_i[1] = tl_t_p[1];
	// Trace: ips/tlul/tlul_socket_1n.sv:208:3
	genvar _gv_i_3;
	generate
		for (_gv_i_3 = 0; _gv_i_3 < N; _gv_i_3 = _gv_i_3 + 1) begin : gen_dfifo
			localparam i = _gv_i_3;
			// Trace: ips/tlul/tlul_socket_1n.sv:209:5
			tlul_fifo_sync #(
				.ReqPass(DReqPass[i]),
				.RspPass(DRspPass[i]),
				.ReqDepth(DReqDepth[i * 4+:4]),
				.RspDepth(DRspDepth[i * 4+:4])
			) fifo_d(
				.clk_i(clk_i),
				.rst_ni(rst_ni),
				.tl_h_i(tl_u_o[i]),
				.tl_h_o(tl_u_i[i]),
				.tl_d_o(tl_d_o[(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 0 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) + (((N - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23)))+:(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))]),
				.tl_d_i(tl_d_i[((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? 0 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1) + (((N - 1) - i) * ((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 2 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1)))+:((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 2 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1))]),
				.spare_req_i(1'b0),
				.spare_req_o(),
				.spare_rsp_i(1'b0),
				.spare_rsp_o()
			);
		end
	endgenerate
	// Trace: ips/tlul/tlul_socket_1n.sv:229:3
	function automatic [NWD - 1:0] sv2v_cast_1D9BB;
		input reg [NWD - 1:0] inp;
		sv2v_cast_1D9BB = inp;
	endfunction
	generate
		if ($clog2(N + 1) <= NWD) begin : gen_err_resp
			// Trace: ips/tlul/tlul_socket_1n.sv:230:5
			assign tl_u_o[N][0] = tl_t_o[0];
			// Trace: ips/tlul/tlul_socket_1n.sv:231:5
			assign tl_u_o[N][7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] = (tl_t_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] & (dev_select_t >= sv2v_cast_1D9BB(N))) & ~hold_all_requests;
			// Trace: ips/tlul/tlul_socket_1n.sv:234:5
			assign tl_u_o[N][6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] = tl_t_o[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)];
			// Trace: ips/tlul/tlul_socket_1n.sv:235:5
			assign tl_u_o[N][3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] = tl_t_o[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)];
			// Trace: ips/tlul/tlul_socket_1n.sv:236:5
			assign tl_u_o[N][top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)] = tl_t_o[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)];
			// Trace: ips/tlul/tlul_socket_1n.sv:237:5
			assign tl_u_o[N][top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)] = tl_t_o[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)];
			// Trace: ips/tlul/tlul_socket_1n.sv:238:5
			assign tl_u_o[N][top_pkg_TL_AW + (top_pkg_TL_DBW + 55)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)] = tl_t_o[top_pkg_TL_AW + (top_pkg_TL_DBW + 55)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)];
			// Trace: ips/tlul/tlul_socket_1n.sv:239:5
			assign tl_u_o[N][top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))] = tl_t_o[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))];
			// Trace: ips/tlul/tlul_socket_1n.sv:240:5
			assign tl_u_o[N][55-:32] = tl_t_o[55-:32];
			// Trace: ips/tlul/tlul_socket_1n.sv:241:5
			assign tl_u_o[N][23-:23] = tl_t_o[23-:23];
			// Trace: ips/tlul/tlul_socket_1n.sv:242:5
			tlul_err_resp err_resp(
				.clk_i(clk_i),
				.rst_ni(rst_ni),
				.tl_h_i(tl_u_o[N]),
				.tl_h_o(tl_u_i[N])
			);
		end
		else begin : gen_no_err_resp
			// Trace: ips/tlul/tlul_socket_1n.sv:249:5
			assign tl_u_o[N] = 1'sb0;
			// Trace: ips/tlul/tlul_socket_1n.sv:250:5
			assign tl_u_i[N] = 1'sb0;
			// Trace: ips/tlul/tlul_socket_1n.sv:251:5
			wire unused_sig;
			// Trace: ips/tlul/tlul_socket_1n.sv:252:5
			assign unused_sig = ^tl_u_o[N];
		end
	endgenerate
	initial _sv2v_0 = 0;
endmodule
module tlul_socket_m1 (
	clk_i,
	rst_ni,
	tl_h_i,
	tl_h_o,
	tl_d_o,
	tl_d_i
);
	// Trace: ips/tlul/tlul_socket_m1.sv:26:13
	parameter [31:0] M = 4;
	// Trace: ips/tlul/tlul_socket_m1.sv:27:13
	parameter [M - 1:0] HReqPass = {M {1'b1}};
	// Trace: ips/tlul/tlul_socket_m1.sv:28:13
	parameter [M - 1:0] HRspPass = {M {1'b1}};
	// Trace: ips/tlul/tlul_socket_m1.sv:29:13
	parameter [(M * 4) - 1:0] HReqDepth = {M {4'h1}};
	// Trace: ips/tlul/tlul_socket_m1.sv:30:13
	parameter [(M * 4) - 1:0] HRspDepth = {M {4'h1}};
	// Trace: ips/tlul/tlul_socket_m1.sv:31:13
	parameter [0:0] DReqPass = 1'b1;
	// Trace: ips/tlul/tlul_socket_m1.sv:32:13
	parameter [0:0] DRspPass = 1'b1;
	// Trace: ips/tlul/tlul_socket_m1.sv:33:13
	parameter [3:0] DReqDepth = 4'h1;
	// Trace: ips/tlul/tlul_socket_m1.sv:34:13
	parameter [3:0] DRspDepth = 4'h1;
	// Trace: ips/tlul/tlul_socket_m1.sv:36:3
	input clk_i;
	// Trace: ips/tlul/tlul_socket_m1.sv:37:3
	input rst_ni;
	// Trace: ips/tlul/tlul_socket_m1.sv:39:3
	// removed localparam type tlul_pkg_tl_a_op_e
	localparam signed [31:0] prim_mubi_pkg_MuBi4Width = 4;
	// removed localparam type prim_mubi_pkg_mubi4_t
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	localparam signed [31:0] tlul_pkg_H2DCmdIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_a_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_AW = 32;
	localparam signed [31:0] top_pkg_TL_DW = 32;
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_h2d_t
	input wire [(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (M * ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24)) - 1 : (M * (1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 22)):(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 0 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23)] tl_h_i;
	// Trace: ips/tlul/tlul_socket_m1.sv:40:3
	// removed localparam type tlul_pkg_tl_d_op_e
	localparam signed [31:0] tlul_pkg_D2HRspIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_d_user_t
	localparam signed [31:0] top_pkg_TL_DIW = 1;
	// removed localparam type tlul_pkg_tl_d2h_t
	output wire [((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? (M * ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 2)) - 1 : (M * (1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1))) + ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 0)):((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? 0 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1)] tl_h_o;
	// Trace: ips/tlul/tlul_socket_m1.sv:42:3
	output wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_d_o;
	// Trace: ips/tlul/tlul_socket_m1.sv:43:3
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_d_i;
	// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_socket_m1.sv:46:364
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_socket_m1.sv:46:452
		begin : maxM
			
		end
	end
	// Trace: ips/tlul/tlul_socket_m1.sv:72:3
	localparam [31:0] IDW = top_pkg_TL_AIW;
	// Trace: ips/tlul/tlul_socket_m1.sv:73:3
	localparam [31:0] STIDW = $clog2(M);
	// Trace: ips/tlul/tlul_socket_m1.sv:75:3
	wire [(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (M * ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24)) - 1 : (M * (1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 22)):(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 0 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23)] hreq_fifo_o;
	// Trace: ips/tlul/tlul_socket_m1.sv:76:3
	wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] hrsp_fifo_i [0:M - 1];
	// Trace: ips/tlul/tlul_socket_m1.sv:78:3
	wire [M - 1:0] hrequest;
	// Trace: ips/tlul/tlul_socket_m1.sv:79:3
	wire [M - 1:0] hgrant;
	// Trace: ips/tlul/tlul_socket_m1.sv:81:3
	wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] dreq_fifo_i;
	// Trace: ips/tlul/tlul_socket_m1.sv:82:3
	wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] drsp_fifo_o;
	// Trace: ips/tlul/tlul_socket_m1.sv:84:3
	wire arb_valid;
	// Trace: ips/tlul/tlul_socket_m1.sv:85:3
	wire arb_ready;
	// Trace: ips/tlul/tlul_socket_m1.sv:86:3
	wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] arb_data;
	// Trace: ips/tlul/tlul_socket_m1.sv:89:3
	genvar _gv_i_4;
	function automatic [2:0] sv2v_cast_3;
		input reg [2:0] inp;
		sv2v_cast_3 = inp;
	endfunction
	function automatic [top_pkg_TL_SZW - 1:0] sv2v_cast_FDEB5;
		input reg [top_pkg_TL_SZW - 1:0] inp;
		sv2v_cast_FDEB5 = inp;
	endfunction
	function automatic [7:0] sv2v_cast_15E34;
		input reg [7:0] inp;
		sv2v_cast_15E34 = inp;
	endfunction
	function automatic [31:0] sv2v_cast_D591E;
		input reg [31:0] inp;
		sv2v_cast_D591E = inp;
	endfunction
	function automatic [top_pkg_TL_DBW - 1:0] sv2v_cast_B0D6A;
		input reg [top_pkg_TL_DBW - 1:0] inp;
		sv2v_cast_B0D6A = inp;
	endfunction
	function automatic [31:0] sv2v_cast_9783B;
		input reg [31:0] inp;
		sv2v_cast_9783B = inp;
	endfunction
	function automatic [22:0] sv2v_cast_EDEFC;
		input reg [22:0] inp;
		sv2v_cast_EDEFC = inp;
	endfunction
	generate
		for (_gv_i_4 = 0; _gv_i_4 < M; _gv_i_4 = _gv_i_4 + 1) begin : gen_host_fifo
			localparam i = _gv_i_4;
			// Trace: ips/tlul/tlul_socket_m1.sv:90:5
			wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] hreq_fifo_i;
			// Trace: ips/tlul/tlul_socket_m1.sv:93:5
			wire [STIDW - 1:0] reqid_sub;
			// Trace: ips/tlul/tlul_socket_m1.sv:94:5
			wire [7:0] shifted_id;
			// Trace: ips/tlul/tlul_socket_m1.sv:95:5
			assign reqid_sub = i;
			// Trace: ips/tlul/tlul_socket_m1.sv:96:5
			assign shifted_id = {tl_h_i[(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - 7 : ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) - ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - 7)) : (((((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - 7 : ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) - ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - 7))) - (IDW - STIDW)) + 1)+:IDW - STIDW], reqid_sub};
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_socket_m1.sv:101:80
			// removed an assertion item
			// idInRange : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
			// 	(tl_h_i[i].a_valid |-> tl_h_i[i].a_source[IDW - 1-:STIDW] == '0)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_socket_m1.sv:101:635
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_socket_m1.sv", 101, "idInRange");
			// end
			// Trace: ips/tlul/tlul_socket_m1.sv:104:5
			wire [7:IDW - STIDW] unused_tl_h_source;
			// Trace: ips/tlul/tlul_socket_m1.sv:105:5
			assign unused_tl_h_source = tl_h_i[(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) : ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) : (((((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) : ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + STIDW) - 1)-:STIDW];
			// Trace: ips/tlul/tlul_socket_m1.sv:108:5
			assign hreq_fifo_i = {tl_h_i[(((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) : ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) - (7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))))], sv2v_cast_3(tl_h_i[(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) : ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) : (((((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) : ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))))) + ((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)) - 1)-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)]), sv2v_cast_3(tl_h_i[(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) : ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) : (((((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) : ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))))) + ((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)) - 1)-:((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)]), sv2v_cast_FDEB5(tl_h_i[(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) : ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) : (((((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) : ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + ((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)) - 1)-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)]), sv2v_cast_15E34(shifted_id), sv2v_cast_D591E(tl_h_i[(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? top_pkg_TL_AW + (top_pkg_TL_DBW + 55) : ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) : (((((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? top_pkg_TL_AW + (top_pkg_TL_DBW + 55) : ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)) - 1)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)]), sv2v_cast_B0D6A(tl_h_i[(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? top_pkg_TL_DBW + 55 : ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) - (top_pkg_TL_DBW + 55)) : (((((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? top_pkg_TL_DBW + 55 : ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) - (top_pkg_TL_DBW + 55))) + ((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))) - 1)-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))]), sv2v_cast_9783B(tl_h_i[(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 55 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) - 32) : ((((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 55 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) - 32)) + 31)-:32]), sv2v_cast_EDEFC(tl_h_i[(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 23 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 0) : ((((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 23 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 0)) + 22)-:23]), tl_h_i[(((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 0 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23)]};
			// Trace: ips/tlul/tlul_socket_m1.sv:121:5
			tlul_fifo_sync #(
				.ReqPass(HReqPass[i]),
				.RspPass(HRspPass[i]),
				.ReqDepth(HReqDepth[i * 4+:4]),
				.RspDepth(HRspDepth[i * 4+:4]),
				.SpareReqW(1)
			) u_hostfifo(
				.clk_i(clk_i),
				.rst_ni(rst_ni),
				.tl_h_i(hreq_fifo_i),
				.tl_h_o(tl_h_o[((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? 0 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1) + (((M - 1) - i) * ((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 2 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1)))+:((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 2 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1))]),
				.tl_d_o(hreq_fifo_o[(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 0 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) + (((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23)))+:(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))]),
				.tl_d_i(hrsp_fifo_i[i]),
				.spare_req_i(1'b0),
				.spare_req_o(),
				.spare_rsp_i(1'b0),
				.spare_rsp_o()
			);
		end
	endgenerate
	// Trace: ips/tlul/tlul_socket_m1.sv:142:3
	tlul_fifo_sync #(
		.ReqPass(DReqPass),
		.RspPass(DRspPass),
		.ReqDepth(DReqDepth),
		.RspDepth(DRspDepth),
		.SpareReqW(1)
	) u_devicefifo(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.tl_h_i(dreq_fifo_i),
		.tl_h_o(drsp_fifo_o),
		.tl_d_o(tl_d_o),
		.tl_d_i(tl_d_i),
		.spare_req_i(1'b0),
		.spare_req_o(),
		.spare_rsp_i(1'b0),
		.spare_rsp_o()
	);
	// Trace: ips/tlul/tlul_socket_m1.sv:162:3
	genvar _gv_i_5;
	generate
		for (_gv_i_5 = 0; _gv_i_5 < M; _gv_i_5 = _gv_i_5 + 1) begin : gen_arbreqgnt
			localparam i = _gv_i_5;
			// Trace: ips/tlul/tlul_socket_m1.sv:163:5
			assign hrequest[i] = hreq_fifo_o[(((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) : ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23) - (7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))))];
		end
	endgenerate
	// Trace: ips/tlul/tlul_socket_m1.sv:166:3
	assign arb_ready = drsp_fifo_o[0];
	// Trace: ips/tlul/tlul_socket_m1.sv:168:3
	localparam tlul_pkg_ArbiterImpl = "PPC";
	generate
		if (tlul_pkg_ArbiterImpl == "PPC") begin : gen_arb_ppc
			// Trace: ips/tlul/tlul_socket_m1.sv:169:5
			prim_arbiter_ppc #(
				.N(M),
				.DW(1 * ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24))
			) u_reqarb(
				.clk_i(clk_i),
				.rst_ni(rst_ni),
				.req_chk_i(1'b0),
				.req_i(hrequest),
				.data_i(hreq_fifo_o),
				.gnt_o(hgrant),
				.idx_o(),
				.valid_o(arb_valid),
				.data_o(arb_data),
				.ready_i(arb_ready)
			);
		end
		else if (tlul_pkg_ArbiterImpl == "BINTREE") begin : gen_tree_arb
			// Trace: ips/tlul/tlul_socket_m1.sv:185:5
			prim_arbiter_tree #(
				.N(M),
				.DW(1 * ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24))
			) u_reqarb(
				.clk_i(clk_i),
				.rst_ni(rst_ni),
				.req_chk_i(1'b0),
				.req_i(hrequest),
				.data_i(hreq_fifo_o),
				.gnt_o(hgrant),
				.idx_o(),
				.valid_o(arb_valid),
				.data_o(arb_data),
				.ready_i(arb_ready)
			);
		end
		else begin : gen_unknown
			// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_socket_m1.sv:201:373
			initial begin
				// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_socket_m1.sv:201:461
				begin : UnknownArbImpl_A
					
				end
			end
		end
	endgenerate
	// Trace: ips/tlul/tlul_socket_m1.sv:204:3
	wire [M - 1:0] hfifo_rspvalid;
	// Trace: ips/tlul/tlul_socket_m1.sv:205:3
	wire [M - 1:0] dfifo_rspready;
	// Trace: ips/tlul/tlul_socket_m1.sv:206:3
	wire [7:0] hfifo_rspid;
	// Trace: ips/tlul/tlul_socket_m1.sv:207:3
	wire dfifo_rspready_merged;
	// Trace: ips/tlul/tlul_socket_m1.sv:212:3
	assign dfifo_rspready_merged = |dfifo_rspready;
	// Trace: ips/tlul/tlul_socket_m1.sv:213:3
	assign dreq_fifo_i = {arb_valid, sv2v_cast_3(arb_data[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)]), sv2v_cast_3(arb_data[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)]), sv2v_cast_FDEB5(arb_data[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)]), sv2v_cast_15E34(arb_data[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)]), sv2v_cast_D591E(arb_data[top_pkg_TL_AW + (top_pkg_TL_DBW + 55)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)]), sv2v_cast_B0D6A(arb_data[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))]), sv2v_cast_9783B(arb_data[55-:32]), sv2v_cast_EDEFC(arb_data[23-:23]), dfifo_rspready_merged};
	// Trace: ips/tlul/tlul_socket_m1.sv:231:3
	assign hfifo_rspid = {{STIDW {1'b0}}, drsp_fifo_o[top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))):(top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) - (7 - STIDW)]};
	// Trace: ips/tlul/tlul_socket_m1.sv:235:3
	genvar _gv_i_6;
	function automatic [0:0] sv2v_cast_17D81;
		input reg [0:0] inp;
		sv2v_cast_17D81 = inp;
	endfunction
	function automatic [(tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) - 1:0] sv2v_cast_11E70;
		input reg [(tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) - 1:0] inp;
		sv2v_cast_11E70 = inp;
	endfunction
	generate
		for (_gv_i_6 = 0; _gv_i_6 < M; _gv_i_6 = _gv_i_6 + 1) begin : gen_idrouting
			localparam i = _gv_i_6;
			// Trace: ips/tlul/tlul_socket_m1.sv:236:5
			assign hfifo_rspvalid[i] = drsp_fifo_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))] & (drsp_fifo_o[(top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) - 7+:STIDW] == i);
			// Trace: ips/tlul/tlul_socket_m1.sv:238:5
			assign dfifo_rspready[i] = (hreq_fifo_o[(((M - 1) - i) * (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23))) + (((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? 0 : (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23)] & (drsp_fifo_o[(top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) - 7+:STIDW] == i)) & drsp_fifo_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))];
			// Trace: ips/tlul/tlul_socket_m1.sv:242:5
			assign hrsp_fifo_i[i] = {hfifo_rspvalid[i], sv2v_cast_3(drsp_fifo_o[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((6 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)]), sv2v_cast_3(drsp_fifo_o[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))-:((3 + (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1))))) >= (top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2)))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))))) + 1)]), sv2v_cast_FDEB5(drsp_fifo_o[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))-:((top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)))) >= (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) + 1)]), sv2v_cast_15E34(hfifo_rspid), sv2v_cast_17D81(drsp_fifo_o[top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))-:(((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)) >= (32'sd32 + ((32'sd7 + 32'sd7) + 2)) ? ((top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))) + 1 : ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) - (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))) + 1)]), sv2v_cast_9783B(drsp_fifo_o[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)]), sv2v_cast_11E70(drsp_fifo_o[(tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1-:(((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) >= 2 ? (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 0 : 3 - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))]), drsp_fifo_o[1], hgrant[i]};
		end
	endgenerate
	// Trace: macro expansion of ASSERT at ips/tlul/tlul_socket_m1.sv:258:77
	// removed an assertion item
	// rspIdInRange : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
	// 	(drsp_fifo_o.d_valid |-> (drsp_fifo_o.d_source[0+:STIDW] >= 0) && (drsp_fifo_o.d_source[0+:STIDW] < M))
	// ) else begin
	// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_socket_m1.sv:258:632
	// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_socket_m1.sv", 258, "rspIdInRange");
	// end
endmodule
module tlul_sram_byte (
	clk_i,
	rst_ni,
	tl_i,
	tl_o,
	tl_sram_o,
	tl_sram_i,
	error_i,
	error_o,
	alert_o,
	compound_txn_in_progress_o,
	readback_en_i,
	wr_collision_i,
	write_pending_i
);
	reg _sv2v_0;
	// removed import tlul_pkg::*;
	// Trace: ips/tlul/tlul_sram_byte.sv:19:13
	parameter [0:0] EnableIntg = 0;
	// Trace: ips/tlul/tlul_sram_byte.sv:20:13
	parameter signed [31:0] Outstanding = 1;
	// Trace: ips/tlul/tlul_sram_byte.sv:21:13
	parameter [0:0] EnableReadback = 0;
	// Trace: ips/tlul/tlul_sram_byte.sv:24:3
	input clk_i;
	// Trace: ips/tlul/tlul_sram_byte.sv:25:3
	input rst_ni;
	// Trace: ips/tlul/tlul_sram_byte.sv:27:3
	// removed localparam type tlul_pkg_tl_a_op_e
	localparam signed [31:0] prim_mubi_pkg_MuBi4Width = 4;
	// removed localparam type prim_mubi_pkg_mubi4_t
	localparam signed [31:0] tlul_pkg_DataIntgWidth = 7;
	localparam signed [31:0] tlul_pkg_H2DCmdIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_a_user_t
	localparam signed [31:0] top_pkg_TL_AIW = 8;
	localparam signed [31:0] top_pkg_TL_AW = 32;
	localparam signed [31:0] top_pkg_TL_DW = 32;
	localparam signed [31:0] top_pkg_TL_DBW = top_pkg_TL_DW >> 3;
	localparam signed [31:0] top_pkg_TL_SZW = $clog2($clog2(top_pkg_TL_DBW) + 1);
	// removed localparam type tlul_pkg_tl_h2d_t
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_i;
	// Trace: ips/tlul/tlul_sram_byte.sv:28:3
	// removed localparam type tlul_pkg_tl_d_op_e
	localparam signed [31:0] tlul_pkg_D2HRspIntgWidth = 7;
	// removed localparam type tlul_pkg_tl_d_user_t
	localparam signed [31:0] top_pkg_TL_DIW = 1;
	// removed localparam type tlul_pkg_tl_d2h_t
	output reg [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_o;
	// Trace: ips/tlul/tlul_sram_byte.sv:30:3
	output reg [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23:0] tl_sram_o;
	// Trace: ips/tlul/tlul_sram_byte.sv:31:3
	input wire [(((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1:0] tl_sram_i;
	// Trace: ips/tlul/tlul_sram_byte.sv:37:3
	input error_i;
	// Trace: ips/tlul/tlul_sram_byte.sv:38:3
	output wire error_o;
	// Trace: ips/tlul/tlul_sram_byte.sv:39:3
	output reg alert_o;
	// Trace: ips/tlul/tlul_sram_byte.sv:41:3
	output wire compound_txn_in_progress_o;
	// Trace: ips/tlul/tlul_sram_byte.sv:43:3
	input wire [3:0] readback_en_i;
	// Trace: ips/tlul/tlul_sram_byte.sv:45:3
	input wire wr_collision_i;
	// Trace: ips/tlul/tlul_sram_byte.sv:46:3
	input wire write_pending_i;
	// Trace: ips/tlul/tlul_sram_byte.sv:49:3
	// removed import prim_mubi_pkg::mubi4_t;
	// Trace: ips/tlul/tlul_sram_byte.sv:50:3
	// removed import prim_mubi_pkg::mubi4_test_true_loose;
	// Trace: ips/tlul/tlul_sram_byte.sv:51:3
	// removed import prim_mubi_pkg::mubi4_test_false_strict;
	// Trace: ips/tlul/tlul_sram_byte.sv:52:3
	// removed import prim_mubi_pkg::MuBi4True;
	// Trace: ips/tlul/tlul_sram_byte.sv:53:3
	// removed import prim_mubi_pkg::MuBi4False;
	// Trace: ips/tlul/tlul_sram_byte.sv:54:3
	// removed import prim_mubi_pkg::MuBi4Width;
	// Trace: ips/tlul/tlul_sram_byte.sv:77:3
	localparam signed [31:0] StateWidth = 8;
	// Trace: ips/tlul/tlul_sram_byte.sv:78:3
	// removed localparam type state_e
	// Trace: ips/tlul/tlul_sram_byte.sv:92:3
	function automatic [3:0] sv2v_cast_EECFA;
		input reg [3:0] inp;
		sv2v_cast_EECFA = inp;
	endfunction
	function automatic prim_mubi_pkg_mubi4_test_false_strict;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:50:52
		input reg [3:0] val;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:51:5
		prim_mubi_pkg_mubi4_test_false_strict = sv2v_cast_EECFA(4'h9) == val;
	endfunction
	function automatic prim_mubi_pkg_mubi4_test_true_loose;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:57:50
		input reg [3:0] val;
		// Trace: ips/pkgs/prim_mubi_pkg.sv:58:5
		prim_mubi_pkg_mubi4_test_true_loose = sv2v_cast_EECFA(4'h9) != val;
	endfunction
	function automatic integer prim_util_pkg_vbits;
		// Trace: ips/pkgs/prim_util_pkg.sv:74:36
		input integer value;
		// Trace: ips/pkgs/prim_util_pkg.sv:85:5
		prim_util_pkg_vbits = (value == 1 ? 1 : $clog2(value));
	endfunction
	function automatic [7:0] sv2v_cast_288BE;
		input reg [7:0] inp;
		sv2v_cast_288BE = inp;
	endfunction
	function automatic [3:0] sv2v_cast_4;
		input reg [3:0] inp;
		sv2v_cast_4 = inp;
	endfunction
	function automatic [top_pkg_TL_SZW - 1:0] sv2v_cast_FDEB5;
		input reg [top_pkg_TL_SZW - 1:0] inp;
		sv2v_cast_FDEB5 = inp;
	endfunction
	function automatic [2:0] sv2v_cast_3;
		input reg [2:0] inp;
		sv2v_cast_3 = inp;
	endfunction
	function automatic [7:0] sv2v_cast_15E34;
		input reg [7:0] inp;
		sv2v_cast_15E34 = inp;
	endfunction
	function automatic [31:0] sv2v_cast_D591E;
		input reg [31:0] inp;
		sv2v_cast_D591E = inp;
	endfunction
	function automatic [top_pkg_TL_DBW - 1:0] sv2v_cast_B0D6A;
		input reg [top_pkg_TL_DBW - 1:0] inp;
		sv2v_cast_B0D6A = inp;
	endfunction
	function automatic [31:0] sv2v_cast_9783B;
		input reg [31:0] inp;
		sv2v_cast_9783B = inp;
	endfunction
	function automatic [22:0] sv2v_cast_EDEFC;
		input reg [22:0] inp;
		sv2v_cast_EDEFC = inp;
	endfunction
	generate
		if (EnableIntg) begin : gen_integ_handling
			// Trace: ips/tlul/tlul_sram_byte.sv:94:5
			reg stall_host;
			// Trace: ips/tlul/tlul_sram_byte.sv:95:5
			reg wait_phase;
			// Trace: ips/tlul/tlul_sram_byte.sv:96:5
			reg rd_phase;
			// Trace: ips/tlul/tlul_sram_byte.sv:97:5
			reg rd_wait;
			// Trace: ips/tlul/tlul_sram_byte.sv:98:5
			reg wr_phase;
			// Trace: ips/tlul/tlul_sram_byte.sv:99:5
			reg rdback_phase;
			// Trace: ips/tlul/tlul_sram_byte.sv:100:5
			reg rdback_phase_wrreadback;
			// Trace: ips/tlul/tlul_sram_byte.sv:101:5
			reg rdback_wait;
			// Trace: ips/tlul/tlul_sram_byte.sv:102:5
			reg [7:0] state_d;
			reg [7:0] state_q;
			// Trace: ips/tlul/tlul_sram_byte.sv:104:5
			always @(posedge clk_i or negedge rst_ni)
				// Trace: ips/tlul/tlul_sram_byte.sv:105:7
				if (!rst_ni)
					// Trace: ips/tlul/tlul_sram_byte.sv:106:9
					state_q <= sv2v_cast_288BE(8'b01111110);
				else
					// Trace: ips/tlul/tlul_sram_byte.sv:108:9
					state_q <= state_d;
			// Trace: ips/tlul/tlul_sram_byte.sv:113:5
			wire a_ack;
			// Trace: ips/tlul/tlul_sram_byte.sv:114:5
			wire d_ack;
			// Trace: ips/tlul/tlul_sram_byte.sv:115:5
			wire sram_a_ack;
			// Trace: ips/tlul/tlul_sram_byte.sv:116:5
			wire sram_d_ack;
			// Trace: ips/tlul/tlul_sram_byte.sv:117:5
			wire wr_txn;
			// Trace: ips/tlul/tlul_sram_byte.sv:118:5
			wire byte_wr_txn;
			// Trace: ips/tlul/tlul_sram_byte.sv:119:5
			wire byte_req_ack;
			// Trace: ips/tlul/tlul_sram_byte.sv:120:5
			reg hold_tx_data;
			// Trace: ips/tlul/tlul_sram_byte.sv:122:5
			localparam [31:0] PendingTxnCntW = prim_util_pkg_vbits(Outstanding + 1);
			// Trace: ips/tlul/tlul_sram_byte.sv:123:5
			wire [PendingTxnCntW - 1:0] pending_txn_cnt;
			// Trace: ips/tlul/tlul_sram_byte.sv:126:5
			// removed localparam type tl_txn_data_t
			// Trace: ips/tlul/tlul_sram_byte.sv:136:5
			wire [(((((3 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 22:0] held_data;
			// Trace: ips/tlul/tlul_sram_byte.sv:138:5
			assign a_ack = tl_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] & tl_o[0];
			// Trace: ips/tlul/tlul_sram_byte.sv:139:5
			assign d_ack = tl_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))] & tl_i[0];
			// Trace: ips/tlul/tlul_sram_byte.sv:140:5
			assign sram_a_ack = tl_sram_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] & tl_sram_i[0];
			// Trace: ips/tlul/tlul_sram_byte.sv:141:5
			assign sram_d_ack = tl_sram_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))] & tl_sram_o[0];
			// Trace: ips/tlul/tlul_sram_byte.sv:142:5
			assign wr_txn = (tl_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] == 3'h0) | (tl_i[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] == 3'h1);
			// Trace: ips/tlul/tlul_sram_byte.sv:144:5
			assign byte_req_ack = (byte_wr_txn & a_ack) & ~error_i;
			// Trace: ips/tlul/tlul_sram_byte.sv:145:5
			assign byte_wr_txn = (tl_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] & ~&tl_i[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))]) & wr_txn;
			// Trace: ips/tlul/tlul_sram_byte.sv:147:5
			wire rdback_chk_ok;
			// Trace: ips/tlul/tlul_sram_byte.sv:148:5
			wire [3:0] rdback_check_q;
			reg [3:0] rdback_check_d;
			// Trace: ips/tlul/tlul_sram_byte.sv:149:5
			wire [3:0] rdback_en_q;
			reg [3:0] rdback_en_d;
			// Trace: ips/tlul/tlul_sram_byte.sv:150:5
			wire [31:0] rdback_data_exp_q;
			reg [31:0] rdback_data_exp_d;
			// Trace: ips/tlul/tlul_sram_byte.sv:151:5
			wire [6:0] rdback_data_exp_intg_q;
			reg [6:0] rdback_data_exp_intg_d;
			if (EnableReadback) begin : gen_readback_logic
				// Trace: ips/tlul/tlul_sram_byte.sv:154:7
				wire rdback_chk_ok_unbuf;
				// Trace: ips/tlul/tlul_sram_byte.sv:156:7
				assign rdback_chk_ok_unbuf = rdback_data_exp_q == tl_sram_i[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)];
				// Trace: ips/tlul/tlul_sram_byte.sv:158:7
				prim_sec_anchor_buf #(.Width(1)) u_rdback_chk_ok_buf(
					.in_i(rdback_chk_ok_unbuf),
					.out_o(rdback_chk_ok)
				);
				// Trace: ips/tlul/tlul_sram_byte.sv:165:7
				prim_flop #(
					.Width(prim_mubi_pkg_MuBi4Width),
					.ResetValue(sv2v_cast_4(sv2v_cast_EECFA(4'h9)))
				) u_rdback_check_flop(
					.clk_i(clk_i),
					.rst_ni(rst_ni),
					.d_i(sv2v_cast_4(rdback_check_d)),
					.q_o({rdback_check_q})
				);
				// Trace: ips/tlul/tlul_sram_byte.sv:176:7
				prim_flop #(
					.Width(prim_mubi_pkg_MuBi4Width),
					.ResetValue(sv2v_cast_4(sv2v_cast_EECFA(4'h9)))
				) u_rdback_en_flop(
					.clk_i(clk_i),
					.rst_ni(rst_ni),
					.d_i(sv2v_cast_4(rdback_en_d)),
					.q_o({rdback_en_q})
				);
				// Trace: ips/tlul/tlul_sram_byte.sv:187:7
				prim_flop #(
					.Width(32),
					.ResetValue(0)
				) u_rdback_data_exp(
					.clk_i(clk_i),
					.rst_ni(rst_ni),
					.d_i(rdback_data_exp_d),
					.q_o(rdback_data_exp_q)
				);
				// Trace: ips/tlul/tlul_sram_byte.sv:198:7
				prim_flop #(
					.Width(tlul_pkg_DataIntgWidth),
					.ResetValue(0)
				) u_rdback_data_exp_intg(
					.clk_i(clk_i),
					.rst_ni(rst_ni),
					.d_i(rdback_data_exp_intg_d),
					.q_o(rdback_data_exp_intg_q)
				);
				// Trace: macro expansion of ASSERT at ips/tlul/tlul_sram_byte.sv:214:60
				// removed an assertion item
				// WRCollisionDuringReadBack_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
				// 	((rdback_phase | rdback_phase_wrreadback) & prim_mubi_pkg_mubi4_test_true_loose(rdback_en_q) |-> !wr_collision_i)
				// ) else begin
				// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_sram_byte.sv:214:615
				// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_sram_byte.sv", 214, "WRCollisionDuringReadBack_A");
				// end
				// Trace: macro expansion of ASSERT at ips/tlul/tlul_sram_byte.sv:222:25
				// removed an assertion item
				// NoPendingWriteAfterWrite_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
				// 	(wr_phase & prim_mubi_pkg_mubi4_test_true_loose(rdback_en_q) |=> write_pending_i)
				// ) else begin
				// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_sram_byte.sv:222:580
				// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_sram_byte.sv", 222, "NoPendingWriteAfterWrite_A");
				// end
			end
			else begin : gen_no_readback_logic
				// Trace: ips/tlul/tlul_sram_byte.sv:226:7
				assign rdback_chk_ok = 1'b0;
				// Trace: ips/tlul/tlul_sram_byte.sv:227:7
				assign rdback_check_q = sv2v_cast_EECFA(4'h9);
				// Trace: ips/tlul/tlul_sram_byte.sv:228:7
				assign rdback_en_q = sv2v_cast_EECFA(4'h9);
				// Trace: ips/tlul/tlul_sram_byte.sv:229:7
				assign rdback_data_exp_q = 1'b0;
				// Trace: ips/tlul/tlul_sram_byte.sv:230:7
				assign rdback_data_exp_intg_q = 1'b0;
				// Trace: ips/tlul/tlul_sram_byte.sv:232:7
				wire unused_rdback;
				// Trace: ips/tlul/tlul_sram_byte.sv:234:7
				assign unused_rdback = ^{rdback_check_d, rdback_data_exp_d, rdback_data_exp_intg_d};
			end
			// Trace: ips/tlul/tlul_sram_byte.sv:238:5
			always @(*) begin
				if (_sv2v_0)
					;
				// Trace: ips/tlul/tlul_sram_byte.sv:239:7
				rd_wait = 1'b0;
				// Trace: ips/tlul/tlul_sram_byte.sv:240:7
				wait_phase = 1'b0;
				// Trace: ips/tlul/tlul_sram_byte.sv:241:7
				stall_host = 1'b0;
				// Trace: ips/tlul/tlul_sram_byte.sv:242:7
				wr_phase = 1'b0;
				// Trace: ips/tlul/tlul_sram_byte.sv:243:7
				rd_phase = 1'b0;
				// Trace: ips/tlul/tlul_sram_byte.sv:244:7
				rdback_phase = 1'b0;
				// Trace: ips/tlul/tlul_sram_byte.sv:245:7
				rdback_phase_wrreadback = 1'b0;
				// Trace: ips/tlul/tlul_sram_byte.sv:246:7
				rdback_wait = 1'b0;
				// Trace: ips/tlul/tlul_sram_byte.sv:247:7
				state_d = state_q;
				// Trace: ips/tlul/tlul_sram_byte.sv:248:7
				hold_tx_data = 1'b0;
				// Trace: ips/tlul/tlul_sram_byte.sv:249:7
				alert_o = 1'b0;
				// Trace: ips/tlul/tlul_sram_byte.sv:250:7
				rdback_check_d = rdback_check_q;
				// Trace: ips/tlul/tlul_sram_byte.sv:251:7
				rdback_en_d = rdback_en_q;
				// Trace: ips/tlul/tlul_sram_byte.sv:252:7
				rdback_data_exp_d = rdback_data_exp_q;
				// Trace: ips/tlul/tlul_sram_byte.sv:253:7
				rdback_data_exp_intg_d = rdback_data_exp_intg_q;
				// Trace: ips/tlul/tlul_sram_byte.sv:255:7
				(* full_case, parallel_case *)
				case (state_q)
					sv2v_cast_288BE(8'b01111110): begin
						// Trace: ips/tlul/tlul_sram_byte.sv:257:11
						if (prim_mubi_pkg_mubi4_test_true_loose(rdback_en_q) && prim_mubi_pkg_mubi4_test_true_loose(rdback_check_q)) begin
							// Trace: ips/tlul/tlul_sram_byte.sv:262:13
							rdback_wait = 1'b1;
							// Trace: ips/tlul/tlul_sram_byte.sv:263:13
							rdback_check_d = sv2v_cast_EECFA(4'h9);
							// Trace: ips/tlul/tlul_sram_byte.sv:266:13
							if (!rdback_chk_ok)
								// Trace: ips/tlul/tlul_sram_byte.sv:267:15
								alert_o = 1'b1;
						end
						if (byte_wr_txn) begin
							// Trace: ips/tlul/tlul_sram_byte.sv:272:13
							rd_phase = 1'b1;
							// Trace: ips/tlul/tlul_sram_byte.sv:273:13
							if (byte_req_ack)
								// Trace: ips/tlul/tlul_sram_byte.sv:274:15
								state_d = sv2v_cast_288BE(8'b00000010);
						end
						else if ((a_ack && prim_mubi_pkg_mubi4_test_true_loose(rdback_en_q)) && !error_i) begin
							// Trace: ips/tlul/tlul_sram_byte.sv:280:13
							hold_tx_data = 1'b1;
							// Trace: ips/tlul/tlul_sram_byte.sv:281:13
							state_d = (wr_txn ? sv2v_cast_288BE(8'b10011001) : sv2v_cast_288BE(8'b10101100));
						end
						if ((!tl_sram_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] && !tl_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))]) && prim_mubi_pkg_mubi4_test_false_strict(rdback_check_q))
							// Trace: ips/tlul/tlul_sram_byte.sv:287:13
							rdback_en_d = readback_en_i;
					end
					sv2v_cast_288BE(8'b00000010): begin
						// Trace: ips/tlul/tlul_sram_byte.sv:295:11
						rd_phase = 1'b1;
						// Trace: ips/tlul/tlul_sram_byte.sv:296:11
						stall_host = 1'b1;
						// Trace: ips/tlul/tlul_sram_byte.sv:297:11
						begin : sv2v_autoblock_1
							reg signed [PendingTxnCntW - 1:0] sv2v_tmp_cast;
							sv2v_tmp_cast = 1;
							if (pending_txn_cnt == sv2v_tmp_cast) begin
								// Trace: ips/tlul/tlul_sram_byte.sv:298:13
								rd_wait = 1'b1;
								// Trace: ips/tlul/tlul_sram_byte.sv:299:13
								if (sram_d_ack)
									// Trace: ips/tlul/tlul_sram_byte.sv:300:15
									state_d = sv2v_cast_288BE(8'b11110001);
							end
						end
					end
					sv2v_cast_288BE(8'b11110001): begin
						// Trace: ips/tlul/tlul_sram_byte.sv:306:11
						stall_host = 1'b1;
						// Trace: ips/tlul/tlul_sram_byte.sv:307:11
						wr_phase = 1'b1;
						// Trace: ips/tlul/tlul_sram_byte.sv:309:11
						if (sram_a_ack) begin
							// Trace: ips/tlul/tlul_sram_byte.sv:310:13
							state_d = (prim_mubi_pkg_mubi4_test_true_loose(rdback_en_q) ? sv2v_cast_288BE(8'b01010111) : sv2v_cast_288BE(8'b01111110));
							// Trace: ips/tlul/tlul_sram_byte.sv:311:13
							rdback_check_d = (prim_mubi_pkg_mubi4_test_true_loose(rdback_en_q) ? sv2v_cast_EECFA(4'h6) : sv2v_cast_EECFA(4'h9));
							// Trace: ips/tlul/tlul_sram_byte.sv:312:13
							rdback_data_exp_d = tl_sram_o[55-:32];
							// Trace: ips/tlul/tlul_sram_byte.sv:313:13
							rdback_data_exp_intg_d = tl_sram_o[7-:tlul_pkg_DataIntgWidth];
						end
					end
					sv2v_cast_288BE(8'b10011001): begin
						// Trace: ips/tlul/tlul_sram_byte.sv:320:11
						if (EnableReadback == 0) begin : gen_inv_state_StWrReadBackInit
							// Trace: ips/tlul/tlul_sram_byte.sv:322:13
							alert_o = 1'b1;
						end
						// Trace: ips/tlul/tlul_sram_byte.sv:326:11
						stall_host = 1'b1;
						begin : sv2v_autoblock_2
							reg signed [PendingTxnCntW - 1:0] sv2v_tmp_cast;
							sv2v_tmp_cast = 1;
							if (pending_txn_cnt == sv2v_tmp_cast) begin
								// Trace: ips/tlul/tlul_sram_byte.sv:331:13
								wait_phase = 1'b1;
								// Trace: ips/tlul/tlul_sram_byte.sv:334:13
								rdback_check_d = (prim_mubi_pkg_mubi4_test_true_loose(rdback_en_q) ? sv2v_cast_EECFA(4'h6) : sv2v_cast_EECFA(4'h9));
								// Trace: ips/tlul/tlul_sram_byte.sv:335:13
								rdback_data_exp_d = held_data[54-:32];
								// Trace: ips/tlul/tlul_sram_byte.sv:336:13
								rdback_data_exp_intg_d = held_data[6-:tlul_pkg_DataIntgWidth];
								// Trace: ips/tlul/tlul_sram_byte.sv:337:13
								if (d_ack)
									// Trace: ips/tlul/tlul_sram_byte.sv:340:15
									state_d = sv2v_cast_288BE(8'b00001111);
								else
									// Trace: ips/tlul/tlul_sram_byte.sv:343:15
									state_d = sv2v_cast_288BE(8'b00110000);
							end
						end
					end
					sv2v_cast_288BE(8'b00001111): begin
						// Trace: ips/tlul/tlul_sram_byte.sv:350:11
						if (EnableReadback == 0) begin : gen_inv_state_StWrReadBack
							// Trace: ips/tlul/tlul_sram_byte.sv:352:13
							alert_o = 1'b1;
						end
						// Trace: ips/tlul/tlul_sram_byte.sv:355:11
						stall_host = 1'b1;
						// Trace: ips/tlul/tlul_sram_byte.sv:357:11
						rdback_phase = 1'b1;
						// Trace: ips/tlul/tlul_sram_byte.sv:359:11
						state_d = sv2v_cast_288BE(8'b01111110);
					end
					sv2v_cast_288BE(8'b00110000): begin
						// Trace: ips/tlul/tlul_sram_byte.sv:365:11
						if (EnableReadback == 0) begin : gen_inv_state_StWrReadBackDWait
							// Trace: ips/tlul/tlul_sram_byte.sv:367:13
							alert_o = 1'b1;
						end
						// Trace: ips/tlul/tlul_sram_byte.sv:371:11
						wait_phase = 1'b1;
						// Trace: ips/tlul/tlul_sram_byte.sv:373:11
						stall_host = 1'b1;
						if (d_ack)
							// Trace: ips/tlul/tlul_sram_byte.sv:378:13
							state_d = sv2v_cast_288BE(8'b00001111);
					end
					sv2v_cast_288BE(8'b01010111): begin
						// Trace: ips/tlul/tlul_sram_byte.sv:385:11
						if (EnableReadback == 0) begin : gen_inv_state_StByteWrReadBackInit
							// Trace: ips/tlul/tlul_sram_byte.sv:387:13
							alert_o = 1'b1;
						end
						// Trace: ips/tlul/tlul_sram_byte.sv:392:11
						stall_host = 1'b1;
						begin : sv2v_autoblock_3
							reg signed [PendingTxnCntW - 1:0] sv2v_tmp_cast;
							sv2v_tmp_cast = 1;
							if (pending_txn_cnt == sv2v_tmp_cast) begin
								// Trace: ips/tlul/tlul_sram_byte.sv:398:13
								wait_phase = 1'b1;
								// Trace: ips/tlul/tlul_sram_byte.sv:400:13
								if (d_ack)
									// Trace: ips/tlul/tlul_sram_byte.sv:403:15
									state_d = sv2v_cast_288BE(8'b11100111);
								else
									// Trace: ips/tlul/tlul_sram_byte.sv:409:15
									state_d = sv2v_cast_288BE(8'b11111111);
							end
						end
					end
					sv2v_cast_288BE(8'b11100111): begin
						// Trace: ips/tlul/tlul_sram_byte.sv:417:11
						if (EnableReadback == 0) begin : gen_inv_state_StByteWrReadBack
							// Trace: ips/tlul/tlul_sram_byte.sv:419:13
							alert_o = 1'b1;
						end
						// Trace: ips/tlul/tlul_sram_byte.sv:422:11
						stall_host = 1'b1;
						// Trace: ips/tlul/tlul_sram_byte.sv:424:11
						rdback_phase_wrreadback = 1'b1;
						// Trace: ips/tlul/tlul_sram_byte.sv:426:11
						state_d = sv2v_cast_288BE(8'b01111110);
					end
					sv2v_cast_288BE(8'b11111111): begin
						// Trace: ips/tlul/tlul_sram_byte.sv:430:11
						if (EnableReadback == 0) begin : gen_inv_state_StByteWrReadBackDWait
							// Trace: ips/tlul/tlul_sram_byte.sv:432:13
							alert_o = 1'b1;
						end
						// Trace: ips/tlul/tlul_sram_byte.sv:435:11
						stall_host = 1'b1;
						// Trace: ips/tlul/tlul_sram_byte.sv:438:11
						wait_phase = 1'b1;
						if (d_ack)
							// Trace: ips/tlul/tlul_sram_byte.sv:443:13
							state_d = sv2v_cast_288BE(8'b11100111);
					end
					sv2v_cast_288BE(8'b10101100): begin
						// Trace: ips/tlul/tlul_sram_byte.sv:448:11
						if (EnableReadback == 0) begin : gen_inv_state_StRdReadBack
							// Trace: ips/tlul/tlul_sram_byte.sv:450:13
							alert_o = 1'b1;
						end
						// Trace: ips/tlul/tlul_sram_byte.sv:455:11
						stall_host = 1'b1;
						begin : sv2v_autoblock_4
							reg signed [PendingTxnCntW - 1:0] sv2v_tmp_cast;
							sv2v_tmp_cast = 1;
							if (pending_txn_cnt == sv2v_tmp_cast) begin
								// Trace: ips/tlul/tlul_sram_byte.sv:460:13
								rdback_phase = 1'b1;
								// Trace: ips/tlul/tlul_sram_byte.sv:462:13
								if (d_ack) begin
									// Trace: ips/tlul/tlul_sram_byte.sv:463:15
									state_d = sv2v_cast_288BE(8'b01111110);
									// Trace: ips/tlul/tlul_sram_byte.sv:465:15
									rdback_check_d = (prim_mubi_pkg_mubi4_test_true_loose(rdback_en_q) ? sv2v_cast_EECFA(4'h6) : sv2v_cast_EECFA(4'h9));
									// Trace: ips/tlul/tlul_sram_byte.sv:466:15
									rdback_data_exp_d = tl_o[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)];
									// Trace: ips/tlul/tlul_sram_byte.sv:467:15
									rdback_data_exp_intg_d = tl_o[((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) - 7)-:tlul_pkg_DataIntgWidth];
								end
								else
									// Trace: ips/tlul/tlul_sram_byte.sv:470:15
									state_d = sv2v_cast_288BE(8'b11000000);
							end
						end
					end
					sv2v_cast_288BE(8'b11000000): begin
						// Trace: ips/tlul/tlul_sram_byte.sv:476:11
						if (EnableReadback == 0) begin : gen_inv_state_StRdReadBackDWait
							// Trace: ips/tlul/tlul_sram_byte.sv:478:13
							alert_o = 1'b1;
						end
						// Trace: ips/tlul/tlul_sram_byte.sv:481:11
						stall_host = 1'b1;
						if (d_ack) begin
							// Trace: ips/tlul/tlul_sram_byte.sv:486:13
							state_d = sv2v_cast_288BE(8'b01111110);
							// Trace: ips/tlul/tlul_sram_byte.sv:488:13
							rdback_check_d = (prim_mubi_pkg_mubi4_test_true_loose(rdback_en_q) ? sv2v_cast_EECFA(4'h6) : sv2v_cast_EECFA(4'h9));
							// Trace: ips/tlul/tlul_sram_byte.sv:489:13
							rdback_data_exp_d = tl_o[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)];
							// Trace: ips/tlul/tlul_sram_byte.sv:490:13
							rdback_data_exp_intg_d = tl_o[((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) - 7)-:tlul_pkg_DataIntgWidth];
						end
					end
					default:
						// Trace: ips/tlul/tlul_sram_byte.sv:495:11
						alert_o = 1'b1;
				endcase
			end
			// Trace: ips/tlul/tlul_sram_byte.sv:501:5
			wire [(((((3 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 22:0] txn_data;
			// Trace: ips/tlul/tlul_sram_byte.sv:502:5
			wire fifo_rdy;
			// Trace: ips/tlul/tlul_sram_byte.sv:503:5
			wire txn_data_wr;
			// Trace: ips/tlul/tlul_sram_byte.sv:504:5
			localparam signed [31:0] TxnDataWidth = 1 * ((((((3 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23);
			// Trace: ips/tlul/tlul_sram_byte.sv:506:5
			assign txn_data = {sv2v_cast_3(tl_i[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)]), sv2v_cast_FDEB5(tl_i[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)]), sv2v_cast_15E34(tl_i[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)]), sv2v_cast_D591E(tl_i[top_pkg_TL_AW + (top_pkg_TL_DBW + 55)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)]), sv2v_cast_B0D6A(tl_i[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))]), sv2v_cast_9783B(tl_i[55-:32]), sv2v_cast_EDEFC(tl_i[23-:23])};
			// Trace: ips/tlul/tlul_sram_byte.sv:517:5
			assign txn_data_wr = hold_tx_data | byte_req_ack;
			// Trace: ips/tlul/tlul_sram_byte.sv:519:5
			prim_fifo_sync #(
				.Width(TxnDataWidth),
				.Pass(1'b0),
				.Depth(1),
				.OutputZeroIfEmpty(1'b0)
			) u_sync_fifo(
				.clk_i(clk_i),
				.rst_ni(rst_ni),
				.clr_i(1'b0),
				.wvalid_i(txn_data_wr),
				.wready_o(fifo_rdy),
				.wdata_i(txn_data),
				.rvalid_o(),
				.rready_i(sram_a_ack),
				.rdata_o(held_data),
				.full_o(),
				.depth_o(),
				.err_o()
			);
			// Trace: ips/tlul/tlul_sram_byte.sv:540:5
			reg [31:0] rsp_data;
			// Trace: ips/tlul/tlul_sram_byte.sv:541:5
			always @(posedge clk_i)
				// Trace: ips/tlul/tlul_sram_byte.sv:542:7
				if (sram_d_ack && rd_wait)
					// Trace: ips/tlul/tlul_sram_byte.sv:543:9
					rsp_data <= tl_sram_i[top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)-:((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) >= ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) ? ((top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)) - ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)) + 1 : (((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2) - (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))) + 1)];
			// Trace: ips/tlul/tlul_sram_byte.sv:551:5
			reg [31:0] combined_data;
			wire [31:0] unused_data;
			// Trace: ips/tlul/tlul_sram_byte.sv:552:5
			always @(*) begin
				if (_sv2v_0)
					;
				// Trace: ips/tlul/tlul_sram_byte.sv:553:7
				begin : sv2v_autoblock_5
					// Trace: ips/tlul/tlul_sram_byte.sv:553:12
					reg signed [31:0] i;
					// Trace: ips/tlul/tlul_sram_byte.sv:553:12
					for (i = 0; i < top_pkg_TL_DBW; i = i + 1)
						begin
							// Trace: ips/tlul/tlul_sram_byte.sv:554:9
							combined_data[i * 8+:8] = (held_data[(top_pkg_TL_DBW + 54) - ((top_pkg_TL_DBW - 1) - i)] ? held_data[23 + (i * 8)+:8] : rsp_data[i * 8+:8]);
						end
				end
			end
			// Trace: ips/tlul/tlul_sram_byte.sv:563:5
			wire [6:0] data_intg;
			// Trace: ips/tlul/tlul_sram_byte.sv:565:5
			tlul_data_integ_enc u_tlul_data_integ_enc(
				.data_i(combined_data),
				.data_intg_o({data_intg, unused_data})
			);
			// Trace: ips/tlul/tlul_sram_byte.sv:570:5
			reg [22:0] combined_user;
			// Trace: ips/tlul/tlul_sram_byte.sv:571:5
			always @(*) begin
				if (_sv2v_0)
					;
				// Trace: ips/tlul/tlul_sram_byte.sv:572:7
				combined_user = held_data[22-:23];
				// Trace: ips/tlul/tlul_sram_byte.sv:573:7
				combined_user[6-:tlul_pkg_DataIntgWidth] = data_intg;
			end
			// Trace: ips/tlul/tlul_sram_byte.sv:576:5
			localparam [31:0] AccessSize = $clog2(top_pkg_TL_DBW);
			// Trace: ips/tlul/tlul_sram_byte.sv:577:5
			always @(*) begin
				if (_sv2v_0)
					;
				// Trace: ips/tlul/tlul_sram_byte.sv:579:7
				tl_sram_o = tl_i;
				// Trace: ips/tlul/tlul_sram_byte.sv:581:7
				tl_sram_o[0] = (tl_i[0] | rd_wait) | rdback_wait;
				// Trace: ips/tlul/tlul_sram_byte.sv:590:7
				if ((wr_phase | rdback_phase) | rdback_phase_wrreadback) begin
					// Trace: ips/tlul/tlul_sram_byte.sv:591:9
					tl_sram_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] = 1'b1;
					// Trace: ips/tlul/tlul_sram_byte.sv:593:9
					tl_sram_o[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] = (wr_phase ? 3'h0 : 3'h4);
					// Trace: ips/tlul/tlul_sram_byte.sv:596:9
					tl_sram_o[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)] = (wr_phase | rdback_phase_wrreadback ? sv2v_cast_FDEB5(AccessSize) : held_data[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 54)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 54))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 54)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 54))))) + 1)]);
					// Trace: ips/tlul/tlul_sram_byte.sv:598:9
					tl_sram_o[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))] = (wr_phase | rdback_phase_wrreadback ? {top_pkg_TL_DBW {1'b1}} : held_data[top_pkg_TL_DBW + 54-:((top_pkg_TL_DBW + 54) >= 55 ? top_pkg_TL_DBW : 56 - (top_pkg_TL_DBW + 54))]);
					// Trace: ips/tlul/tlul_sram_byte.sv:602:9
					tl_sram_o[top_pkg_TL_AW + (top_pkg_TL_DBW + 55)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) >= (top_pkg_TL_DBW + 56) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_DBW + 56)) + 1 : ((top_pkg_TL_DBW + 56) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1)] = held_data[top_pkg_TL_AW + (top_pkg_TL_DBW + 54)-:((top_pkg_TL_AW + (top_pkg_TL_DBW + 54)) >= (top_pkg_TL_DBW + 55) ? ((top_pkg_TL_AW + (top_pkg_TL_DBW + 54)) - (top_pkg_TL_DBW + 55)) + 1 : ((top_pkg_TL_DBW + 55) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 54))) + 1)];
					// Trace: ips/tlul/tlul_sram_byte.sv:603:9
					tl_sram_o[(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (32 - AccessSize):(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - 31] = (wr_phase | rdback_phase_wrreadback ? {(((32'sd32 + (top_pkg_TL_DBW + 55)) - (32 - AccessSize)) >= ((32'sd32 + (top_pkg_TL_DBW + 55)) - 31) ? (((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (32 - AccessSize)) - ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - 31)) + 1 : (((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - 31) - ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (32 - AccessSize))) + 1) * 1 {1'sb0}} : held_data[(top_pkg_TL_AW + (top_pkg_TL_DBW + 54)) - (32 - AccessSize):(top_pkg_TL_AW + (top_pkg_TL_DBW + 54)) - 31]);
					// Trace: ips/tlul/tlul_sram_byte.sv:605:9
					tl_sram_o[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)) >= (32'sd32 + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 56)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) + 1)] = held_data[top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 54))-:(((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 54)) >= (32'sd32 + (top_pkg_TL_DBW + 55)) ? ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 54))) - (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))) + 1 : ((top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 54)))) + 1)];
					// Trace: ips/tlul/tlul_sram_byte.sv:606:9
					tl_sram_o[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] = held_data[3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 54))))-:((3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 54)))) >= (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) ? ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 54))))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1 : ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 54)))))) + 1)];
					// Trace: ips/tlul/tlul_sram_byte.sv:607:9
					tl_sram_o[55-:32] = (wr_phase ? combined_data : {32 {1'sb0}});
					// Trace: ips/tlul/tlul_sram_byte.sv:608:9
					tl_sram_o[23-:23] = (wr_phase ? combined_user : {23 {1'sb0}});
				end
				else if (rd_phase) begin
					// Trace: ips/tlul/tlul_sram_byte.sv:612:9
					tl_sram_o[(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - (32 - AccessSize):(top_pkg_TL_AW + (top_pkg_TL_DBW + 55)) - 31] = 1'sb0;
					// Trace: ips/tlul/tlul_sram_byte.sv:614:9
					if (!error_i || stall_host) begin
						// Trace: ips/tlul/tlul_sram_byte.sv:617:11
						tl_sram_o[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)] = sv2v_cast_FDEB5(AccessSize);
						// Trace: ips/tlul/tlul_sram_byte.sv:618:11
						tl_sram_o[top_pkg_TL_DBW + 55-:((top_pkg_TL_DBW + 55) >= 56 ? top_pkg_TL_DBW : 57 - (top_pkg_TL_DBW + 55))] = {top_pkg_TL_DBW {1'b1}};
						// Trace: ips/tlul/tlul_sram_byte.sv:620:11
						tl_sram_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] = tl_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] & ~stall_host;
						// Trace: ips/tlul/tlul_sram_byte.sv:621:11
						tl_sram_o[6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))-:((6 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55)))) >= (3 + (top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)))) ? ((6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) - (3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))))) + 1 : ((3 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))))) - (6 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))))) + 1)] = 3'h4;
					end
				end
				else if (wait_phase)
					// Trace: ips/tlul/tlul_sram_byte.sv:626:9
					tl_sram_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))] = 1'b0;
			end
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_sram_byte.sv:631:73
			// removed an assertion item
			// TlulSramByteTlSize_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
			// 	top_pkg_TL_SZW >= $clog2(AccessSize + 1)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_sram_byte.sv:631:628
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_sram_byte.sv", 631, "TlulSramByteTlSize_A");
			// end
			// Trace: ips/tlul/tlul_sram_byte.sv:633:5
			assign error_o = error_i & ~stall_host;
			// Trace: ips/tlul/tlul_sram_byte.sv:635:5
			wire size_fifo_rdy;
			// Trace: ips/tlul/tlul_sram_byte.sv:636:5
			wire [top_pkg_TL_SZW - 1:0] a_size;
			// Trace: ips/tlul/tlul_sram_byte.sv:637:5
			prim_fifo_sync #(
				.Width(top_pkg_TL_SZW),
				.Pass(1'b0),
				.Depth(Outstanding),
				.OutputZeroIfEmpty(1'b1)
			) u_sync_fifo_a_size(
				.clk_i(clk_i),
				.rst_ni(rst_ni),
				.clr_i(1'b0),
				.wvalid_i(a_ack),
				.wready_o(size_fifo_rdy),
				.wdata_i(tl_i[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))-:((top_pkg_TL_SZW + ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 55))) >= ((32'sd8 + 32'sd32) + (top_pkg_TL_DBW + 56)) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55)))) - (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56)))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 56))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_AW + (top_pkg_TL_DBW + 55))))) + 1)]),
				.rvalid_o(),
				.rready_i(d_ack),
				.rdata_o(a_size),
				.full_o(),
				.depth_o(pending_txn_cnt),
				.err_o()
			);
			// Trace: ips/tlul/tlul_sram_byte.sv:657:5
			always @(*) begin
				if (_sv2v_0)
					;
				// Trace: ips/tlul/tlul_sram_byte.sv:658:7
				tl_o = tl_sram_i;
				// Trace: ips/tlul/tlul_sram_byte.sv:661:7
				tl_o[0] = ((tl_sram_i[0] & ~stall_host) & fifo_rdy) & size_fifo_rdy;
				// Trace: ips/tlul/tlul_sram_byte.sv:665:7
				tl_o[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))] = (tl_sram_i[7 + (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))] & ~rd_wait) & ~rdback_wait;
				// Trace: ips/tlul/tlul_sram_byte.sv:670:7
				tl_o[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))-:((top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)))) >= (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) + 1)] = a_size;
			end
			// Trace: ips/tlul/tlul_sram_byte.sv:675:5
			wire unused_tl;
			// Trace: ips/tlul/tlul_sram_byte.sv:676:5
			assign unused_tl = |tl_sram_i[top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))-:((top_pkg_TL_SZW + (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 1)))) >= (32'sd8 + ((32'sd1 + 32'sd32) + ((32'sd7 + 32'sd7) + 2))) ? ((top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1))))) - (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2))))) + 1 : ((top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 2)))) - (top_pkg_TL_SZW + (top_pkg_TL_AIW + (top_pkg_TL_DIW + (top_pkg_TL_DW + ((tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth) + 1)))))) + 1)];
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_sram_byte.sv:680:29
			// removed an assertion item
			// ByteAccessStateChange_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
			// 	(((a_ack & wr_txn) & ~&tl_i.a_mask) & ~error_i |=> (state_q inside { StWaitRd }))
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_sram_byte.sv:680:584
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_sram_byte.sv", 680, "ByteAccessStateChange_A");
			// end
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_sram_byte.sv:683:93
			// removed an assertion item
			// ReadCompleteStateChange_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
			// 	(((state_q == StWaitRd) && (pending_txn_cnt == 1)) && sram_d_ack |=> state_q == StWriteCmd)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_sram_byte.sv:683:648
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_sram_byte.sv", 683, "ReadCompleteStateChange_A");
			// end
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_sram_byte.sv:691:25
			// removed an assertion item
			// ReadbackAccessAlwaysGranted_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
			// 	((rdback_phase | rdback_phase_wrreadback) && !error_i |-> tl_sram_i.a_ready)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_sram_byte.sv:691:580
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_sram_byte.sv", 691, "ReadbackAccessAlwaysGranted_A");
			// end
			// Trace: macro expansion of ASSERT at ips/tlul/tlul_sram_byte.sv:697:33
			// removed an assertion item
			// ReadbackDataImmediatelyAvailable_A : assert property (@(posedge clk_i) disable iff (!rsts_ni !== '0)
			// 	((((state_q == StPassThru) && prim_mubi_pkg_mubi4_test_true_loose(rdback_en_q)) && prim_mubi_pkg_mubi4_test_true_loose(rdback_check_q)) && !error_i |-> tl_sram_i.d_valid)
			// ) else begin
			// 	// Trace: macro expansion of ASSERT_ERROR at ips/tlul/tlul_sram_byte.sv:697:588
			// 	$error("%0t: (%0s:%0d) [%m] [ASSERT FAILED] %0s", $time, "ips/tlul/tlul_sram_byte.sv", 697, "ReadbackDataImmediatelyAvailable_A");
			// end
			// Trace: ips/tlul/tlul_sram_byte.sv:699:5
			assign compound_txn_in_progress_o = (wr_phase | rdback_phase) | rdback_phase_wrreadback;
		end
		else begin : gen_no_integ_handling
			// Trace: ips/tlul/tlul_sram_byte.sv:702:5
			wire [(((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd32)) + top_pkg_TL_DBW) + 55) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 24 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_AW) + top_pkg_TL_DBW) + top_pkg_TL_DW) + 23)):1] sv2v_tmp_3714C;
			assign sv2v_tmp_3714C = tl_i;
			always @(*) tl_sram_o = sv2v_tmp_3714C;
			// Trace: ips/tlul/tlul_sram_byte.sv:703:5
			wire [((((((7 + top_pkg_TL_SZW) + (32'sd8 + 32'sd1)) + 32'sd32) + (32'sd7 + 32'sd7)) + 1) >= 0 ? (((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 2 : 1 - ((((((7 + top_pkg_TL_SZW) + top_pkg_TL_AIW) + top_pkg_TL_DIW) + top_pkg_TL_DW) + (tlul_pkg_D2HRspIntgWidth + tlul_pkg_DataIntgWidth)) + 1)):1] sv2v_tmp_EF4AC;
			assign sv2v_tmp_EF4AC = tl_sram_i;
			always @(*) tl_o = sv2v_tmp_EF4AC;
			// Trace: ips/tlul/tlul_sram_byte.sv:704:5
			assign error_o = error_i;
			// Trace: ips/tlul/tlul_sram_byte.sv:705:5
			wire [1:1] sv2v_tmp_C54BC;
			assign sv2v_tmp_C54BC = 1'b0;
			always @(*) alert_o = sv2v_tmp_C54BC;
			// Trace: ips/tlul/tlul_sram_byte.sv:706:5
			assign compound_txn_in_progress_o = 1'b0;
			// Trace: ips/tlul/tlul_sram_byte.sv:709:5
			wire [3:0] unused_readback_en;
			// Trace: ips/tlul/tlul_sram_byte.sv:710:5
			assign unused_readback_en = readback_en_i;
		end
	endgenerate
	// Trace: ips/tlul/tlul_sram_byte.sv:715:3
	wire unused_write_pending;
	wire unused_wr_collision;
	// Trace: ips/tlul/tlul_sram_byte.sv:716:3
	assign unused_write_pending = write_pending_i;
	// Trace: ips/tlul/tlul_sram_byte.sv:717:3
	assign unused_wr_collision = wr_collision_i;
	// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_sram_byte.sv:722:425
	initial begin
		// Trace: macro expansion of ASSERT_INIT at ips/tlul/tlul_sram_byte.sv:722:513
		begin : SramReadbackAndIntg
			
		end
	end
	initial _sv2v_0 = 0;
endmodule
module controller (
	clk_i,
	rst_ni,
	lvds_i,
	pwm_dc_i,
	adc_value_o,
	clear_pwm_count_o
);
	// Trace: rtl/controller.sv:2:13
	parameter NBITS = 8;
	// Trace: rtl/controller.sv:4:3
	input wire clk_i;
	// Trace: rtl/controller.sv:5:3
	input wire rst_ni;
	// Trace: rtl/controller.sv:6:3
	input wire lvds_i;
	// Trace: rtl/controller.sv:7:3
	input wire [NBITS - 1:0] pwm_dc_i;
	// Trace: rtl/controller.sv:8:3
	output reg [NBITS - 1:0] adc_value_o;
	// Trace: rtl/controller.sv:9:3
	output reg clear_pwm_count_o;
	// Trace: rtl/controller.sv:12:3
	reg lvds_q;
	// Trace: rtl/controller.sv:14:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: rtl/controller.sv:15:5
		if (!rst_ni) begin
			// Trace: rtl/controller.sv:16:7
			lvds_q <= 0;
			// Trace: rtl/controller.sv:17:7
			adc_value_o <= 0;
			// Trace: rtl/controller.sv:18:7
			clear_pwm_count_o <= 0;
		end
		else begin
			// Trace: rtl/controller.sv:20:7
			lvds_q <= lvds_i;
			// Trace: rtl/controller.sv:21:7
			clear_pwm_count_o <= 0;
			// Trace: rtl/controller.sv:23:7
			if (lvds_i && !lvds_q) begin
				// Trace: rtl/controller.sv:24:9
				adc_value_o <= pwm_dc_i;
				// Trace: rtl/controller.sv:25:9
				clear_pwm_count_o <= 1;
			end
		end
endmodule
module multiple_pwm_ramp (
	clk_i,
	rst_ni,
	enable_i,
	step_i,
	lvds_0_i,
	lvds_1_i,
	pwm_0_o,
	pwm_1_o,
	adc_value_o,
	adc_valid_o
);
	// Trace: rtl/multiple_pwm_ramp.sv:2:13
	parameter signed [31:0] NBITS = 8;
	// Trace: rtl/multiple_pwm_ramp.sv:4:3
	input wire clk_i;
	// Trace: rtl/multiple_pwm_ramp.sv:5:3
	input wire rst_ni;
	// Trace: rtl/multiple_pwm_ramp.sv:6:3
	input wire enable_i;
	// Trace: rtl/multiple_pwm_ramp.sv:7:3
	input wire [NBITS - 1:0] step_i;
	// Trace: rtl/multiple_pwm_ramp.sv:8:3
	input wire lvds_0_i;
	// Trace: rtl/multiple_pwm_ramp.sv:9:3
	input wire lvds_1_i;
	// Trace: rtl/multiple_pwm_ramp.sv:10:3
	output wire pwm_0_o;
	// Trace: rtl/multiple_pwm_ramp.sv:11:3
	output wire pwm_1_o;
	// Trace: rtl/multiple_pwm_ramp.sv:12:3
	output wire [NBITS - 1:0] adc_value_o;
	// Trace: rtl/multiple_pwm_ramp.sv:13:3
	output wire adc_valid_o;
	// Trace: rtl/multiple_pwm_ramp.sv:17:3
	localparam signed [31:0] MAX_CNT = (2 ** NBITS) - 1;
	// Trace: rtl/multiple_pwm_ramp.sv:18:3
	localparam signed [31:0] HNBITS = NBITS - 1;
	// Trace: rtl/multiple_pwm_ramp.sv:21:3
	wire [NBITS - 1:0] adc_value_0;
	wire [NBITS - 1:0] adc_value_1;
	// Trace: rtl/multiple_pwm_ramp.sv:22:3
	wire adc_valid_0;
	wire adc_valid_1;
	// Trace: rtl/multiple_pwm_ramp.sv:25:3
	wire lvds;
	wire lvds_rise;
	// Trace: rtl/multiple_pwm_ramp.sv:27:3
	pwm_ramp #(
		.NBITS(NBITS),
		.ResetValue('d0)
	) u_pwm_ramp_0(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.enable_i(enable_i),
		.reverse_i(1'b0),
		.step_i('d1),
		.lvds_i(lvds_0_i),
		.pwm_o(pwm_0_o),
		.adc_value_o(adc_value_0),
		.adc_valid_o(adc_valid_0)
	);
	// Trace: rtl/multiple_pwm_ramp.sv:38:3
	pwm_ramp #(
		.NBITS(NBITS),
		.ResetValue({1'b0, {HNBITS {1'b1}}})
	) u_pwm_ramp_1(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.enable_i(enable_i),
		.reverse_i(1'b0),
		.step_i('d1),
		.lvds_i(lvds_1_i),
		.pwm_o(pwm_1_o),
		.adc_value_o(adc_value_1),
		.adc_valid_o(adc_valid_1)
	);
endmodule
module prim_deglitch (
	clk_i,
	rst_ni,
	en_i,
	d_i,
	q_o
);
	reg _sv2v_0;
	// Trace: rtl/prim_deglitch.sv:7:13
	parameter [0:0] AsyncOn = 0;
	// Trace: rtl/prim_deglitch.sv:8:13
	parameter [31:0] SIZE = 4;
	// Trace: rtl/prim_deglitch.sv:10:3
	input wire clk_i;
	// Trace: rtl/prim_deglitch.sv:11:3
	input wire rst_ni;
	// Trace: rtl/prim_deglitch.sv:12:3
	input wire en_i;
	// Trace: rtl/prim_deglitch.sv:13:3
	input wire d_i;
	// Trace: rtl/prim_deglitch.sv:14:3
	output reg q_o;
	// Trace: rtl/prim_deglitch.sv:18:3
	localparam [31:0] COUNT_WIDTH = $clog2(SIZE + 1);
	// Trace: rtl/prim_deglitch.sv:20:3
	reg [COUNT_WIDTH - 1:0] count_q;
	// Trace: rtl/prim_deglitch.sv:21:3
	wire d_s;
	// Trace: rtl/prim_deglitch.sv:23:3
	generate
		if (AsyncOn) begin : gen_async
			// Trace: rtl/prim_deglitch.sv:26:5
			prim_ff_2sync #(
				.Width(1),
				.ResetValue(1'sb0)
			) prim_flop_2sync(
				.clk_i(clk_i),
				.rst_ni(rst_ni),
				.d_i(d_i),
				.q_o(d_s)
			);
		end
		else begin : gen_sync
			// Trace: rtl/prim_deglitch.sv:36:5
			assign d_s = d_i;
		end
	endgenerate
	// Trace: rtl/prim_deglitch.sv:40:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: rtl/prim_deglitch.sv:41:5
		if (~rst_ni)
			// Trace: rtl/prim_deglitch.sv:42:7
			count_q <= 1'sb0;
		else if (en_i) begin
			begin
				// Trace: rtl/prim_deglitch.sv:45:7
				if (d_s && (count_q < SIZE[COUNT_WIDTH - 1:0]))
					// Trace: rtl/prim_deglitch.sv:46:9
					count_q <= count_q + 1;
				else if (~d_s && (count_q > 0))
					// Trace: rtl/prim_deglitch.sv:49:9
					count_q <= count_q - 1;
			end
		end
	// Trace: rtl/prim_deglitch.sv:54:3
	always @(*) begin
		if (_sv2v_0)
			;
		// Trace: rtl/prim_deglitch.sv:55:5
		q_o = 1'b0;
		// Trace: rtl/prim_deglitch.sv:56:5
		if (count_q == SIZE[COUNT_WIDTH - 1:0])
			// Trace: rtl/prim_deglitch.sv:57:7
			q_o = 1'b1;
		else if (count_q == 0)
			// Trace: rtl/prim_deglitch.sv:59:7
			q_o = 1'b0;
	end
	initial _sv2v_0 = 0;
endmodule
module prim_edge_detect (
	clk_i,
	rst_ni,
	en_i,
	serial_i,
	r_edge_o,
	f_edge_o
);
	// Trace: rtl/prim_edge_detect.sv:2:3
	input wire clk_i;
	// Trace: rtl/prim_edge_detect.sv:3:3
	input wire rst_ni;
	// Trace: rtl/prim_edge_detect.sv:4:3
	input wire en_i;
	// Trace: rtl/prim_edge_detect.sv:5:3
	input wire serial_i;
	// Trace: rtl/prim_edge_detect.sv:6:3
	output wire r_edge_o;
	// Trace: rtl/prim_edge_detect.sv:7:3
	output wire f_edge_o;
	// Trace: rtl/prim_edge_detect.sv:10:3
	wire serial_q;
	// Trace: rtl/prim_edge_detect.sv:12:3
	prim_flop #(
		.Width(1),
		.ResetValue(0)
	) u_sync_1(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.d_i(serial_i),
		.q_o(serial_q)
	);
	// Trace: rtl/prim_edge_detect.sv:22:3
	assign f_edge_o = ~serial_i & serial_q;
	// Trace: rtl/prim_edge_detect.sv:23:3
	assign r_edge_o = serial_i & ~serial_q;
endmodule
module prim_ff_2sync (
	clk_i,
	rst_ni,
	d_i,
	q_o
);
	// Trace: rtl/prim_ff_2sync.sv:2:13
	parameter signed [31:0] Width = 16;
	// Trace: rtl/prim_ff_2sync.sv:3:13
	parameter [Width - 1:0] ResetValue = 1'sb0;
	// Trace: rtl/prim_ff_2sync.sv:5:3
	input wire clk_i;
	// Trace: rtl/prim_ff_2sync.sv:6:3
	input wire rst_ni;
	// Trace: rtl/prim_ff_2sync.sv:7:3
	input wire [Width - 1:0] d_i;
	// Trace: rtl/prim_ff_2sync.sv:8:3
	output wire [Width - 1:0] q_o;
	// Trace: rtl/prim_ff_2sync.sv:11:3
	wire [Width - 1:0] d_o;
	// Trace: rtl/prim_ff_2sync.sv:12:3
	wire [Width - 1:0] intq;
	// Trace: rtl/prim_ff_2sync.sv:14:3
	prim_flop #(
		.Width(Width),
		.ResetValue(ResetValue)
	) u_sync_1(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.d_i(d_i),
		.q_o(intq)
	);
	// Trace: rtl/prim_ff_2sync.sv:24:3
	prim_flop #(
		.Width(Width),
		.ResetValue(ResetValue)
	) u_sync_2(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.d_i(intq),
		.q_o(q_o)
	);
endmodule
module pwm_ramp (
	clk_i,
	rst_ni,
	enable_i,
	reverse_i,
	step_i,
	lvds_i,
	pwm_o,
	adc_value_o,
	adc_valid_o
);
	// Trace: rtl/pwm_ramp.sv:2:13
	parameter signed [31:0] NBITS = 8;
	// Trace: rtl/pwm_ramp.sv:3:13
	parameter [NBITS - 1:0] ResetValue = 0;
	// Trace: rtl/pwm_ramp.sv:5:3
	input wire clk_i;
	// Trace: rtl/pwm_ramp.sv:6:3
	input wire rst_ni;
	// Trace: rtl/pwm_ramp.sv:7:3
	input wire enable_i;
	// Trace: rtl/pwm_ramp.sv:8:3
	input wire reverse_i;
	// Trace: rtl/pwm_ramp.sv:9:3
	input wire [NBITS - 1:0] step_i;
	// Trace: rtl/pwm_ramp.sv:10:3
	input wire lvds_i;
	// Trace: rtl/pwm_ramp.sv:11:3
	output wire pwm_o;
	// Trace: rtl/pwm_ramp.sv:12:3
	output reg [NBITS - 1:0] adc_value_o;
	// Trace: rtl/pwm_ramp.sv:13:3
	output reg adc_valid_o;
	// Trace: rtl/pwm_ramp.sv:17:3
	localparam signed [31:0] MAX_CNT = (2 ** NBITS) - 1;
	// Trace: rtl/pwm_ramp.sv:20:3
	reg [NBITS - 1:0] duty_cycle;
	// Trace: rtl/pwm_ramp.sv:21:3
	reg [NBITS - 1:0] counter;
	// Trace: rtl/pwm_ramp.sv:23:3
	reg clear;
	// Trace: rtl/pwm_ramp.sv:24:3
	wire pwm_drive_w;
	// Trace: rtl/pwm_ramp.sv:27:3
	wire lvds;
	wire lvds_rise;
	// Trace: rtl/pwm_ramp.sv:30:3
	prim_deglitch #(
		.AsyncOn(1),
		.SIZE(3)
	) u_prim_deglitch(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.en_i(enable_i),
		.d_i(lvds_i),
		.q_o(lvds)
	);
	// Trace: rtl/pwm_ramp.sv:40:3
	wire f_edge_o;
	prim_edge_detect u_prim_edge_detect(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.en_i(enable_i),
		.serial_i(lvds),
		.r_edge_o(lvds_rise),
		.f_edge_o(f_edge_o)
	);
	// Trace: rtl/pwm_ramp.sv:51:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: rtl/pwm_ramp.sv:52:5
		if (!rst_ni) begin
			// Trace: rtl/pwm_ramp.sv:53:7
			clear <= 1'b0;
			// Trace: rtl/pwm_ramp.sv:54:7
			adc_valid_o <= 1'b0;
			// Trace: rtl/pwm_ramp.sv:55:7
			adc_value_o <= 1'b0;
		end
		else if (lvds_rise) begin
			// Trace: rtl/pwm_ramp.sv:57:7
			clear <= 1'b1;
			// Trace: rtl/pwm_ramp.sv:58:7
			adc_valid_o <= 1'b1;
			// Trace: rtl/pwm_ramp.sv:59:7
			if (reverse_i)
				// Trace: rtl/pwm_ramp.sv:60:9
				adc_value_o <= {NBITS {1'b1}} - duty_cycle;
			else
				// Trace: rtl/pwm_ramp.sv:62:9
				adc_value_o <= duty_cycle;
		end
		else if (clear) begin
			// Trace: rtl/pwm_ramp.sv:65:7
			clear <= 1'b0;
			// Trace: rtl/pwm_ramp.sv:66:7
			adc_valid_o <= 1'b0;
		end
	// Trace: rtl/pwm_ramp.sv:71:3
	always @(posedge clk_i or negedge rst_ni)
		// Trace: rtl/pwm_ramp.sv:72:5
		if (!rst_ni) begin
			// Trace: rtl/pwm_ramp.sv:73:7
			counter <= 1'sb0;
			// Trace: rtl/pwm_ramp.sv:74:7
			duty_cycle <= ResetValue;
		end
		else if (clear) begin
			// Trace: rtl/pwm_ramp.sv:76:9
			counter <= 1'sb0;
			// Trace: rtl/pwm_ramp.sv:77:9
			duty_cycle <= ResetValue;
		end
		else if (enable_i) begin
			begin
				// Trace: rtl/pwm_ramp.sv:80:7
				if (counter == MAX_CNT) begin
					// Trace: rtl/pwm_ramp.sv:81:9
					duty_cycle <= duty_cycle + step_i;
					// Trace: rtl/pwm_ramp.sv:82:9
					counter <= 1'sb0;
				end
				else
					// Trace: rtl/pwm_ramp.sv:84:9
					counter <= counter + 1;
			end
		end
	// Trace: rtl/pwm_ramp.sv:89:3
	assign pwm_drive_w = (reverse_i ? counter > duty_cycle : counter < duty_cycle);
	// Trace: rtl/pwm_ramp.sv:90:3
	assign pwm_o = (pwm_drive_w ? 1'b1 : 1'b0);
endmodule
