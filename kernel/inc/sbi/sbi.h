#ifndef __SBI_H__
#define __SBI_H__
#include <common/stdint.h>

/* sbi */
struct sbiret {
    long error;
    long value;
};

enum SBI_EID {
    EID_SET_TIMER              = 0x00,
    EID_CONSOLE_PUTCHAR        = 0x01,
    EID_CONSOLE_GETCHAR        = 0x02,
    EID_CLEAR_IPI              = 0x03,
    EID_SEND_IPI               = 0x04,
    EID_REMOTE_FENCE_I         = 0x05,
    EID_REMOTE_SFENCE_VMA      = 0x06,
    EID_REMOTE_SFENCE_VMA_ASID = 0x07,
    EID_SHUTDOWN               = 0x08,
    EID_SRST                   = 0x53525354
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

void sbi_call_0(uint64_t EID, uint64_t FID, struct sbiret* ret);
void sbi_call_1(uint64_t EID, uint64_t FID, struct sbiret* ret, uint64_t arg0);
void sbi_call_2(uint64_t EID, uint64_t FID, struct sbiret* ret, uint64_t arg0, uint64_t arg1);
void sbi_call_3(uint64_t EID, uint64_t FID, struct sbiret* ret, uint64_t arg0, uint64_t arg1, uint64_t arg2);

/* legacy */
long sbi_set_timer(uint64_t stime_value);
void sbi_console_putchar(int ch);
long sbi_console_getchar(void);
long sbi_clear_ipi(void);
long sbi_send_ipi(const unsigned long *hart_mask);
long sbi_remote_fence_i(const unsigned long *hart_mask);
long sbi_remote_sfence_vma(const unsigned long *hart_mask,unsigned long start, unsigned long size);
long sbi_remote_sfence_vma_asid(const unsigned long *hart_mask,unsigned long start, unsigned long size, unsigned long asid);
void sbi_shutdown(void);

/* srst */
enum SBI_SRST_FID {
    SRST_SYSTEM_RESET
};

enum SBI_SRST_RESET_TYPE {
    SRST_T_SHUTDOWN,
    SRST_T_CLOD_REBOOT,
    SRST_T_WARM_REBOOT
};

enum SBI_SRST_RESET_RESON {
    SRST_R_NO_REASON,
    SRST_R_SYSTEM_FAILURE
};

void sbi_system_reset(uint32_t reset_type, uint32_t reset_reason);

#endif