OUTPUT_ARCH(riscv)
ENTRY(_start)
BASE_ADDRESS = 0x80400000;

PHDRS
{
    text PT_LOAD FLAGS(5);    /* R_X */
    rodata PT_LOAD FLAGS(4);  /* R */
    data PT_LOAD FLAGS(6);    /* R_W */
    stack PT_GNU_STACK FLAGS(6); /* R_W */
}

SECTIONS
{
    . = BASE_ADDRESS;
    suser = .;

# text
    stext = .;
    .text : {
        *(.text.entry)
        *(.text*)
    } : text
    etext = .;

# rodata
    srodata = .;
    .rodata : {
        *(.rodata*)
        *(.srodata*)
    } : rodata
    erodata = .;

# data
    sdata = .;
    .data : {
        *(.data*)
        *(.sdata*)
    } : data
    edata = .;

# bss
    sbss = .;
    .bss : {
        *(.bss*)
        *(.sbss*)
    }
    ebss = .;

    _end = .;
    PROVIDE(_end = .);

    euser = .;

    /DISCARD/ : {
        *(.eh_frame)
    }
}