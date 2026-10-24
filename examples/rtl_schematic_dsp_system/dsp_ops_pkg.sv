// Reusable DSP control encodings; this file is compiled as an SV package.
package dsp_ops_pkg;
  typedef enum logic [1:0] {OP_PASS = 2'b00, OP_ADD = 2'b01,
                            OP_SUB = 2'b10, OP_NEG = 2'b11} dsp_op_e;
  typedef enum logic [1:0] {IDLE, FILL, ACTIVE, DRAIN} ctrl_state_e;
endpackage
