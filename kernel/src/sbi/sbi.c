#include <sbi/sbi.h>
#include <common/stdint.h>
#include <common/printf.h>
const uint64_t SBI_SET_TIMER = 0;
const uint64_t SBI_CONSOLE_PUTCHAR = 1;
const uint64_t SBI_CONSOLE_GETCHAR = 2;
const uint64_t SBI_CLEAR_IPI = 3;
const uint64_t SBI_SEND_IPI = 4;
const uint64_t SBI_REMOTE_FENCE_I = 5;
const uint64_t SBI_REMOTE_SFENCE_VMA = 6;
const uint64_t SBI_REMOTE_SFENCE_VMA_ASID = 7;
const uint64_t SBI_SHUTDOWN = 8;

static inline int sbi_call(uint64_t which, uint64_t arg0, uint64_t arg1, uint64_t arg2) {
	register uint64_t a0 asm("a0") = arg0;
	register uint64_t a1 asm("a1") = arg1;
	register uint64_t a2 asm("a2") = arg2;
	register uint64_t a7 asm("a7") = which;
	asm volatile("ecall"
		     : "=r"(a0)
		     : "r"(a0), "r"(a1), "r"(a2), "r"(a7)
		     : "memory");
	return a0;
}

inline void console_putchar(char ch) {
	sbi_call(SBI_CONSOLE_PUTCHAR, ch, 0, 0);
}

inline void shutdown(void) {
	sbi_call(SBI_SHUTDOWN, 0, 0, 0);
}