OUTPUT_ARCH(riscv)
MEMORY
{
    ram         : ORIGIN = 0x00100000, LENGTH = 0x1EFFC
    test_status : ORIGIN = 0x0011EFFC, LENGTH = 0x4
    stack       : ORIGIN = 0x0011F000, LENGTH = 0x1000
}
_min_stack = 0x1000;
_stack_start = ORIGIN(stack) + LENGTH(stack);
_entry_point = _vectors_start;
ENTRY(_entry_point)
PROVIDE(__flexsoc_test_status = ORIGIN(test_status));
SECTIONS
{
    .text : { . = ALIGN(4); _vectors_start = .; KEEP(*(.vectors)) *(.text) *(.text.*) . = ALIGN(4); } > ram
    .rodata : { . = ALIGN(4); *(.srodata*) *(.rodata*) . = ALIGN(4); } > ram
    .data : { . = ALIGN(4); *(.sdata*) *(.data*) . = ALIGN(4); } > ram
    .bss : { . = ALIGN(4); _bss_start = .; *(.sbss*) *(.bss*) *(COMMON) _bss_end = .; . = ALIGN(4); } > ram
    .stack (NOLOAD): { . = ALIGN(4); . = . + _min_stack; . = ALIGN(4); } > stack
}
