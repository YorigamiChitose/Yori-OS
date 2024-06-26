#ifndef __SYSCALL_H__
#define __SYSCALL_H__


#include <stdint.h>
enum {
  SYS_exit,
  SYS_yield,
  SYS_open,
  SYS_read,
  SYS_write,
  SYS_kill,
  SYS_getpid,
  SYS_close,
  SYS_lseek,
  SYS_brk,
  SYS_fstat,
  SYS_time,
  SYS_signal,
  SYS_execve,
  SYS_fork,
  SYS_link,
  SYS_unlink,
  SYS_wait,
  SYS_times,
  SYS_gettimeofday
};

struct Event {
    enum {
        EVENT_YIELD, EVENT_SYSCALL
    } event;
};

enum {
    INSTRUCTION_ADDRESS_MISALIGNED = 0,
    INSTRUCTION_ACCESS_FAULT = 1,
    ILLEGAL_INSTRUCTION = 2,
    BREAKPOINT = 3,
    LOAD_ADDRESS_MISALIGNED = 4,
    LOAD_ACCESS_FAULT = 5,
    STORE_ADDRESS_MISALIGNED = 6,
    STORE_ACCESS_FAULT = 7,
    ENVIRONMENT_CALL_FROM_U_MODE = 8,
    ENVIRONMENT_CALL_FROM_S_MODE = 9,
    RESERVED10 = 10,
    ENVIRONMENT_CALL_FROM_M_MODE = 11,
    INSTRUCTION_PAGE_FAULT = 12,
    LOAD_PAGE_FAULT = 13,
    RESERVED14 = 14,
    STORE_PAGE_FAULT = 15,
    USER_SOFTWARE_INTERRUPT = 0x80000000,
    SUPERVISOR_SOFTWARE_INTERRUPT = 0x80000001,
    RESERVED2 = 0x80000002,
    MACHINE_SOFTWARE_INTERRUPT = 0x80000003,
    USER_TIMER_INTERRUPT = 0x80000004,
    SUPERVISOR_TIMER_INTERRUPT = 0x80000005,
    RESERVED6 = 0x80000006,
    MACHINE_TIMER_INTERRUPT = 0x80000007,
    USER_EXTERNAL_INTERRUPT = 0x80000008,
    SUPERVISOR_EXTERNAL_INTERRUPT = 0x80000009,
    RESERVED10_INTERRUPT = 0x8000000A,
    MACHINE_EXTERNAL_INTERRUPT = 0x8000000B,
};

struct Context {
    uint64_t gpr[32], scause, sstatus, sepc;
};



void trap_init(void);
extern void _trap_ecall(void);
extern void _goto_user(struct Context*);

#endif