#ifndef __SBI_H__
#define __SBI_H__
#include <common/stdint.h>

/* sbi */
struct sbiret {
    long error;
    long value;
};

enum SBI_RET_STATUS {
    SBI_SUCCESS = 0,
    SBI_ERR_FAILED = -1,
    SBI_ERR_NOT_SUPPORTED = -2,
    SBI_ERR_INVALID_PARAM = -3,
    SBI_ERR_DENIED = -4,
    SBI_ERR_INVALID_ADDRESS = -5,
    SBI_ERR_ALREADY_AVAILABLE = -6,
    SBI_ERR_ALREADY_STARTED = -7,
    SBI_ERR_ALREADY_STOPPED = -8,
    SBI_ERR_NO_SHMEM = -9
};

/* legacy */

enum SBI_LEGACY_EID {
    SBI_SET_TIMER               = 0,
    SBI_CONSOLE_PUTCHAR         = 1,
    SBI_CONSOLE_GETCHAR         = 2,
    SBI_CLEAR_IPI               = 3,
    SBI_SEND_IPI                = 4,
    SBI_REMOTE_FENCE_I          = 5,
    SBI_REMOTE_SFENCE_VMA       = 6,
    SBI_REMOTE_SFENCE_VMA_ASID  = 7,
    SBI_SHUTDOWN                = 8
};

long sbi_set_timer(uint64_t stime_value);
void sbi_console_putchar(int ch);
long sbi_console_getchar(void);
long sbi_clear_ipi(void);
long sbi_send_ipi(const unsigned long *hart_mask);
long sbi_remote_fence_i(const unsigned long *hart_mask);
long sbi_remote_sfence_vma(const unsigned long *hart_mask,unsigned long start, unsigned long size);
long sbi_remote_sfence_vma_asid(const unsigned long *hart_mask,unsigned long start, unsigned long size, unsigned long asid);
void sbi_shutdown(void);

#endif