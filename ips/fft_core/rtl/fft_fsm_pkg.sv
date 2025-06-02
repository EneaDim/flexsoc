package fft_fsm_pkg;
  typedef enum logic [2:0] { IDLE, ACTIVE_WRITE, READ_1, READ_2, COMPUTE, WRITE_RESULT, DONE } state_fsm ;
  state_fsm current_state, next_state; 

endpackage
