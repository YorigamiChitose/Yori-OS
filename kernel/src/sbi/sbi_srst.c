#include <sbi/sbi.h>
#include <common/printf.h>

void sbi_system_reset(uint32_t reset_type, uint32_t reset_reason) {
    struct sbiret ret_info;
    sbi_call_2(EID_SRST, SRST_SYSTEM_RESET, &ret_info, reset_type, reset_reason);
}