#include "sys/syscall.h"
#include "sbi/sbi.h"
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

#define case_SYS(x, y) case x: tracef("SYSCALL: " #x "!"); y; break

void syscall_handler(struct Context *ecall_info) {
    switch (ecall_info->SYS_TYPE) {
    case_SYS(SYS_exit,  ecall_info->RET = 0; sbi_system_reset(SRST_T_SHUTDOWN, !!ecall_info->ARG0));
    case_SYS(SYS_yield, ecall_info->RET = 0; infof("Yield!"));
    case_SYS(SYS_write, ecall_info->RET = 1; sbi_console_putchar(*(char *)(ecall_info->ARG1)));
    case_SYS(SYS_brk,   ecall_info->RET = 0);
    case_SYS(SYS_close, ecall_info->RET = 0);
    default: errorf("UNKNOWN SYSCALL: %d!", ecall_info->SYS_TYPE); sbi_system_reset(SRST_T_SHUTDOWN, SRST_R_SYSTEM_FAILURE);
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
