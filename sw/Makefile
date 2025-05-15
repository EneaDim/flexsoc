# sw/Makefile

CC = riscv32-unknown-elf-gcc
CFLAGS = -march=rv32imc -mabi=ilp32 -static -mcmodel=medany -Wall -g -fvisibility=hidden -ffreestanding
LDFLAGS = -nostdlib -nostartfiles -T link.ld
BUILD_DIR = build

OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/uart.o $(BUILD_DIR)/spi_host.o $(BUILD_DIR)/boot.o

all: $(BUILD_DIR)/main.elf

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/boot.o: boot.S | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/main.elf: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean

