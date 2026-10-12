CC = riscv32-unknown-elf-gcc
OBJCOPY = riscv32-unknown-elf-objcopy
BUILD_DIR = build
RUN_ROOT := $(abspath ../../../../..)
SOC_INCLUDE_DIR := $(RUN_ROOT)/sw/include
UART_DRIVER_DIR := $(RUN_ROOT)/ips/uart/sw/drivers
CFLAGS = -march=rv32imc -mabi=ilp32 -static -mcmodel=medany -Wall -g -fvisibility=hidden -ffreestanding
CFLAGS += -I$(SOC_INCLUDE_DIR) -I$(UART_DRIVER_DIR) -DSYSCLK_FREQ=100000000u -DBAUD_RATE=3125000u
LDFLAGS = -nostdlib -nostartfiles -T link.ld
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/uart.o $(BUILD_DIR)/boot.o
all: $(BUILD_DIR)/main.elf $(BUILD_DIR)/main.bin
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
$(BUILD_DIR)/main.o: main.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/uart.o: $(UART_DRIVER_DIR)/uart.c $(UART_DRIVER_DIR)/uart.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(UART_DRIVER_DIR)/uart.c -o $@
$(BUILD_DIR)/boot.o: boot.S | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/main.elf: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
$(BUILD_DIR)/main.bin: $(BUILD_DIR)/main.elf
	$(OBJCOPY) -O binary $< $@
clean:
	rm -rf $(BUILD_DIR)
.PHONY: all clean
