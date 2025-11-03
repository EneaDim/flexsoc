module lvds (
    input  real lp,    // LVDS positive voltage
    input  real ln,    // LVDS negative voltage
    output logic lvds_o  // Digital output
);

    always_comb begin
        if (lp > ln)
            lvds_o = 1'b1;
        else
            lvds_o = 1'b0;
    end

endmodule

