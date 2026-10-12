CC = riscv32-unknown-elf-gcc
OBJCOPY = riscv32-unknown-elf-objcopy
BUILD_DIR = build
CFLAGS = -march=rv32imc -mabi=ilp32 -static -mcmodel=medany -Wall -g -fvisibility=hidden -ffreestanding
LDFLAGS = -nostdlib -nostartfiles -T link.ld
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/boot.o
all: $(BUILD_DIR)/main.elf $(BUILD_DIR)/main.bin
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
$(BUILD_DIR)/main.o: main.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/boot.o: boot.S | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/main.elf: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
$(BUILD_DIR)/main.bin: $(BUILD_DIR)/main.elf
	$(OBJCOPY) -O binary $< $@
clean:
	rm -rf $(BUILD_DIR)
.PHONY: all clean
