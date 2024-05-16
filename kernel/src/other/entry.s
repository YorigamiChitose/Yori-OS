    .section .text.entry
    .globl _start
    .extern _estack
_start:
    la sp, _estack
    call main

    .section .kernel_stack
    .globl boot_stack_bottom
boot_stack_bottom:
    .space 4096 * 16
    .globl boot_stack_top
boot_stack_top:
