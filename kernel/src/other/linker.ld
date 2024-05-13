OUTPUT_ARCH(riscv)
ENTRY(_start)
BASE_ADDRESS = 0x80200000;

SECTIONS
{
    . = BASE_ADDRESS;
    skernel = .;

# text
    stext = .;
    .text : {
        *(.text.entry)
        *(.text .text.*)
    }
    etext = .;

# rodata
    srodata = .;
    .rodata : {
        *(.rodata .rodata.*)
        *(.srodata .srodata.*)
    }
    erodata = .;

# data
    sdata = .;
    .data : {
        *(.data .data.*)
    }
    edata = .;

# bss
    sbss = .;
    .bss : {
        *(.bss .bss.*)
        *(.sbss .sbss.*)
    }
    ebss = .;

# stack
    sstack = .;
    .stack : {
        *(.kernel_stack)
    }
    estack = .;

    ekernel = .;

    /DISCARD/ : {
        *(.eh_frame)
    }
}