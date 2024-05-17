    .section .text.entry
    .globl _start
_start:
    mv s0, zero
    jal call_main
