    .section .text.entry
    .globl _start
    .extern _estack
_start:
    la sp, _estack
    call main
