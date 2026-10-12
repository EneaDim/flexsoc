#include "soc_memory_map.h"
#include "uart.h"

extern volatile unsigned int __flexsoc_test_status;

enum {
  TEST_READY_RX = 0x52584459u,
  TEST_READY_TX = 0x54584459u,
  TEST_PASS = 0x55415254u,
};

static void test_event(unsigned int value) {
  __flexsoc_test_status = value;
  __asm__ volatile ("fence rw, rw" ::: "memory");
}

int main(void) {
  uart_t uart = (uart_t)SOC_UART_BASE_ADDR;
  int value;

  uart_init(uart);
  test_event(TEST_READY_RX);
  do {
    value = uart_in(uart);
  } while (value < 0);
  test_event(TEST_READY_TX);
  uart_out(uart, (char)value);
  test_event(TEST_PASS);

  for (;;) __asm__ volatile ("wfi");
}
