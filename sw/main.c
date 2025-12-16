#include "pwm.h"
#include "spi_host.h"
#include "uart.h"

int main(void) {
  spi_host_init((spi_host_t) SPI_HOST_BASE);
  uart_init((uart_t) UART_BASE);
  pwm_init((pwm_t) PWM_BASE);

  spi_host_puts("a5a");
  spi_host_puts("5a5");
  uart_puts("Hello World!\n");

  int a = 0;
  for (int i = 0; i < 650; i++ ) {
    a += i;
  }

  pwm_deinit((pwm_t) PWM_BASE);
  
  return 0;
}

