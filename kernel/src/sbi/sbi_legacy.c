#include <sbi/sbi.h>
#include <common/stdint.h>
#include <common/printf.h>

uint64_t sbi_call_legacy_0(uint64_t EID);
uint64_t sbi_call_legacy_1(uint64_t EID, uint64_t arg0);
uint64_t sbi_call_legacy_3(uint64_t EID, uint64_t arg0, uint64_t arg1, uint64_t arg2);
uint64_t sbi_call_legacy_4(uint64_t EID, uint64_t arg0, uint64_t arg1, uint64_t arg2, uint64_t arg3);

inline uint64_t sbi_call_legacy_0(uint64_t EID) {
    register uint64_t a0 asm("a7") = 0;
    register uint64_t a7 asm("a7") = EID;
    asm volatile("ecall"
                 : "=r"(a0)
                 : "r"(a7)
                 : "memory");
    return a0;
}

inline uint64_t sbi_call_legacy_1(uint64_t EID, uint64_t arg0) {
    register uint64_t a0 asm("a0") = arg0;
    register uint64_t a7 asm("a7") = EID;
    asm volatile("ecall"
                 : "=r"(a0)
                 : "r"(a0), "r"(a7)
                 : "memory");
    return a0;
}

inline uint64_t sbi_call_legacy_3(uint64_t EID, uint64_t arg0, uint64_t arg1, uint64_t arg2) {
	register uint64_t a0 asm("a0") = arg0;
	register uint64_t a1 asm("a1") = arg1;
	register uint64_t a2 asm("a2") = arg2;
	register uint64_t a7 asm("a7") = EID;
	asm volatile("ecall"
		     : "=r"(a0)
		     : "r"(a0), "r"(a1), "r"(a2), "r"(a7)
		     : "memory");
	return a0;
}

inline uint64_t sbi_call_legacy_4(uint64_t EID, uint64_t arg0, uint64_t arg1, uint64_t arg2, uint64_t arg3) {
    register uint64_t a0 asm("a0") = arg0;
    register uint64_t a1 asm("a1") = arg1;
    register uint64_t a2 asm("a2") = arg2;
    register uint64_t a3 asm("a3") = arg3;
    register uint64_t a7 asm("a7") = EID;
    asm volatile("ecall"
                 : "=r"(a0)
                 : "r"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(a7)
                 : "memory");
    return a0;
}

long sbi_set_timer(uint64_t stime_value) {
	return sbi_call_legacy_1(SBI_SET_TIMER, (uint64_t)stime_value);
}

void sbi_console_putchar(int ch) {
	sbi_call_legacy_1(SBI_CONSOLE_PUTCHAR, (uint64_t)ch);
}

long sbi_console_getchar(void) {
	return sbi_call_legacy_0(SBI_CONSOLE_GETCHAR);
}

long sbi_clear_ipi(void) {
	return sbi_call_legacy_0(SBI_CLEAR_IPI);
}

long sbi_send_ipi(const unsigned long *hart_mask) {
	return sbi_call_legacy_1(SBI_SEND_IPI, (uint64_t)hart_mask);
}

long sbi_remote_fence_i(const unsigned long *hart_mask) {
	return sbi_call_legacy_1(SBI_REMOTE_FENCE_I, (uint64_t)hart_mask);
}

long sbi_remote_sfence_vma(const unsigned long *hart_mask,unsigned long start, unsigned long size) {
	return sbi_call_legacy_3(SBI_REMOTE_SFENCE_VMA, (uint64_t)hart_mask, (uint64_t)start, (uint64_t)size);
}

long sbi_remote_sfence_vma_asid(const unsigned long *hart_mask,unsigned long start, unsigned long size, unsigned long asid) {
	return sbi_call_legacy_4(SBI_REMOTE_SFENCE_VMA_ASID, (uint64_t)hart_mask, (uint64_t)start, (uint64_t)size, (uint64_t)asid);
}

void sbi_shutdown(void) {
	sbi_call_legacy_0(SBI_SHUTDOWN);
}