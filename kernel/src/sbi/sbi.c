#include <sbi/sbi.h>
#include <std/stdint.h>

inline void sbi_call_0(uint64_t EID, uint64_t FID, struct sbiret* ret) {
    register uint64_t a0 asm("a0") = 0;
    register uint64_t a1 asm("a1") = 0;
    register uint64_t a6 asm("a6") = FID;
    register uint64_t a7 asm("a7") = EID;
    asm volatile("ecall"
                 : "=r"(a0), "=r"(a1)
                 : "r"(a6), "r"(a7)
                 : "memory");
    ret->error = a0;
    ret->value = a1;
}

inline void sbi_call_1(uint64_t EID, uint64_t FID, struct sbiret* ret, uint64_t arg0) {
    register uint64_t a0 asm("a0") = arg0;
    register uint64_t a1 asm("a1") = 0;
    register uint64_t a6 asm("a6") = FID;
    register uint64_t a7 asm("a7") = EID;
    asm volatile("ecall"
                 : "=r"(a0), "=r"(a1)
                 : "r"(a0), "r"(a6), "r"(a7)
                 : "memory");
    ret->error = a0;
    ret->value = a1;
}

inline void sbi_call_2(uint64_t EID, uint64_t FID, struct sbiret* ret, uint64_t arg0, uint64_t arg1) {
    register uint64_t a0 asm("a0") = arg0;
    register uint64_t a1 asm("a1") = arg1;
    register uint64_t a6 asm("a6") = FID;
    register uint64_t a7 asm("a7") = EID;
    asm volatile("ecall"
                 : "=r"(a0), "=r"(a1)
                 : "r"(a0), "r"(a1), "r"(a6), "r"(a7)
                 : "memory");
    ret->error = a0;
    ret->value = a1;
}

inline void sbi_call_3(uint64_t EID, uint64_t FID, struct sbiret* ret, uint64_t arg0, uint64_t arg1, uint64_t arg2) {
    register uint64_t a0 asm("a0") = arg0;
    register uint64_t a1 asm("a1") = arg1;
    register uint64_t a2 asm("a2") = arg2;
    register uint64_t a6 asm("a6") = FID;
    register uint64_t a7 asm("a7") = EID;
    asm volatile("ecall"
                 : "=r"(a0), "=r"(a1), "=r"(a2)
                 : "r"(a0), "r"(a1), "r"(a2), "r"(a6), "r"(a7)
                 : "memory");
    ret->error = a0;
    ret->value = a1;
}