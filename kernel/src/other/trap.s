.align 3
.globl _trap_ecall
_trap_ecall:
    addi sp, sp, -((32 + 3 + 1) * 8)

    sd  x0, (8 *  0)(sp)
    sd  x1, (8 *  1)(sp)
    sd  x2, (8 *  2)(sp)
    sd  x3, (8 *  3)(sp)
    sd  x4, (8 *  4)(sp)
    sd  x5, (8 *  5)(sp)
    sd  x6, (8 *  6)(sp)
    sd  x7, (8 *  7)(sp)
    sd  x8, (8 *  8)(sp)
    sd  x9, (8 *  9)(sp)
    sd x10, (8 * 10)(sp)
    sd x11, (8 * 11)(sp)
    sd x12, (8 * 12)(sp)
    sd x13, (8 * 13)(sp)
    sd x14, (8 * 14)(sp)
    sd x15, (8 * 15)(sp)
    sd x16, (8 * 16)(sp)
    sd x17, (8 * 17)(sp)
    sd x18, (8 * 18)(sp)
    sd x19, (8 * 19)(sp)
    sd x20, (8 * 20)(sp)
    sd x21, (8 * 21)(sp)
    sd x22, (8 * 22)(sp)
    sd x23, (8 * 23)(sp)
    sd x24, (8 * 24)(sp)
    sd x25, (8 * 25)(sp)
    sd x26, (8 * 26)(sp)
    sd x27, (8 * 27)(sp)
    sd x28, (8 * 28)(sp)
    sd x29, (8 * 29)(sp)
    sd x30, (8 * 30)(sp)
    sd x31, (8 * 31)(sp)

    csrr t0, scause
    csrr t1, sstatus
    csrr t2, sepc

    sd t0, (8 * (32 + 0))(sp)
    sd t1, (8 * (32 + 1))(sp)
    sd t2, (8 * (32 + 2))(sp)

    mv a0, sp
    jal ecall_handler
    mv sp, a0

    ld t2, (8 * (32 + 2))(sp)
    ld t1, (8 * (32 + 1))(sp)
    ld t0, (8 * (32 + 0))(sp)

    csrw sepc, t2
    csrw sstatus, t1
    csrw scause, t0

    ld  x0, (8 *  0)(sp)
    ld  x1, (8 *  1)(sp)
    ld  x2, (8 *  2)(sp)
    ld  x3, (8 *  3)(sp)
    ld  x4, (8 *  4)(sp)
    ld  x5, (8 *  5)(sp)
    ld  x6, (8 *  6)(sp)
    ld  x7, (8 *  7)(sp)
    ld  x8, (8 *  8)(sp)
    ld  x9, (8 *  9)(sp)
    ld x10, (8 * 10)(sp)
    ld x11, (8 * 11)(sp)
    ld x12, (8 * 12)(sp)
    ld x13, (8 * 13)(sp)
    ld x14, (8 * 14)(sp)
    ld x15, (8 * 15)(sp)
    ld x16, (8 * 16)(sp)
    ld x17, (8 * 17)(sp)
    ld x18, (8 * 18)(sp)
    ld x19, (8 * 19)(sp)
    ld x20, (8 * 20)(sp)
    ld x21, (8 * 21)(sp)
    ld x22, (8 * 22)(sp)
    ld x23, (8 * 23)(sp)
    ld x24, (8 * 24)(sp)
    ld x25, (8 * 25)(sp)
    ld x26, (8 * 26)(sp)
    ld x27, (8 * 27)(sp)
    ld x28, (8 * 28)(sp)
    ld x29, (8 * 29)(sp)
    ld x30, (8 * 30)(sp)
    ld x31, (8 * 31)(sp)

    addi sp, sp, ((32 + 3 + 1) * 8)
    sret
    

.globl _goto_user
_goto_user:
    mv t6, a0

    ld t2, (8 * (32 + 2))(t6)
    ld t1, (8 * (32 + 1))(t6)
    ld t0, (8 * (32 + 0))(t6)

    csrw sepc, t2
    csrw sstatus, t1
    csrw scause, t0

    ld  x0, (8 *  0)(t6)
    ld  x1, (8 *  1)(t6)
    ld  x2, (8 *  2)(t6)
    ld  x3, (8 *  3)(t6)
    ld  x4, (8 *  4)(t6)
    ld  x5, (8 *  5)(t6)
    ld  x6, (8 *  6)(t6)
    ld  x7, (8 *  7)(t6)
    ld  x8, (8 *  8)(t6)
    ld  x9, (8 *  9)(t6)
    ld x10, (8 * 10)(t6)
    ld x11, (8 * 11)(t6)
    ld x12, (8 * 12)(t6)
    ld x13, (8 * 13)(t6)
    ld x14, (8 * 14)(t6)
    ld x15, (8 * 15)(t6)
    ld x16, (8 * 16)(t6)
    ld x17, (8 * 17)(t6)
    ld x18, (8 * 18)(t6)
    ld x19, (8 * 19)(t6)
    ld x20, (8 * 20)(t6)
    ld x21, (8 * 21)(t6)
    ld x22, (8 * 22)(t6)
    ld x23, (8 * 23)(t6)
    ld x24, (8 * 24)(t6)
    ld x25, (8 * 25)(t6)
    ld x26, (8 * 26)(t6)
    ld x27, (8 * 27)(t6)
    ld x28, (8 * 28)(t6)
    ld x29, (8 * 29)(t6)
    ld x30, (8 * 30)(t6)
    ld x31, (8 * 31)(t6)

    addi sp, sp, ((32 + 3 + 1) * 8)
    sret

#csrw sscratch, sp
