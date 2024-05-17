#include "sys/syscall.h"
#include "common/log.h"
#include <std/stdint.h>
#include <std/stddef.h>
#include <std/stdbool.h>

#define SYS_TYPE gpr[17]
#define ARG0 gpr[10]
#define ARG1 gpr[11]
#define ARG2 gpr[12]
#define RET gpr[10]

void trap_init(void) {
    asm volatile("csrw stvec, %0" : : "r"(_trap_ecall));
}

void syscall_handler(struct Context *ecall_info) {
    // infof("SYSCALL: %d!", ecall_info->SYS_TYPE);
    switch (ecall_info->SYS_TYPE) {
    case SYS_yield: debugf("Get yield\n"); break;
    case SYS_exit: sbi_system_reset(SRST_T_SHUTDOWN, !!ecall_info->ARG0); break;
    case SYS_write: ecall_info->RET = 1; printf("%c", *(char *)(ecall_info->ARG1)); break;
    case SYS_brk: ecall_info->RET = 0; break;
    default: sbi_system_reset(SRST_T_SHUTDOWN, SRST_R_SYSTEM_FAILURE);
    }
}

struct Context * ecall_handler(struct Context *ecall_info) {
    // debugf("ECALL scause: %d", ecall_info->scause);
    switch (ecall_info->scause) {
    case ENVIRONMENT_CALL_FROM_U_MODE:
        // infof("ECALL FROM U MOD!");
        syscall_handler(ecall_info);
        ecall_info->sepc += 4;
        break;
    default: sbi_system_reset(SRST_T_SHUTDOWN, SRST_R_SYSTEM_FAILURE);
    }
    return ecall_info;
}
