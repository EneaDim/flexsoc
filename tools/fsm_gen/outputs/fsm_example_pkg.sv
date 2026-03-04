package fsm_example_pkg;

typedef enum logic [3:0] 
{
  RESET = 4'b0000,
  IDLE = 4'b0001,
  WAIT_CMD = 4'b0010,
  PREFETCH = 4'b0011,
  EXECUTE = 4'b0100,
  WRITEBACK = 4'b0101,
  FLUSH = 4'b0110,
  ERROR = 4'b0111,
  LOW_POWER = 4'b1000,
  SHUTDOWN = 4'b1001
} state_fsm;

endpackage;
