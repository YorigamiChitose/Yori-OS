#include "loader/loader.h"
#include "sys/syscall.h"
#include <sbi/sbi.h>
#include <common/printf.h>
#include <std/stdbool.h>
#include <std/stdint.h>
#include <common/log.h>
#include <common/logo.h>

extern uint8_t stext;
extern uint8_t etext;
extern uint8_t srodata;
extern uint8_t erodata;
extern uint8_t sstack;
extern uint8_t estack;
extern uint8_t sdata;
extern uint8_t edata;
extern uint8_t sbss;
extern uint8_t ebss;

void clear_bss(void) {
    for (uint8_t *pointer = &sbss; pointer < &ebss; pointer++) {
        *pointer = 0;
    }
}

void display_info(void) {
    printf("\33[1;35m%s\33[0m", logo);
    infof("Hello, Yori OS!");
    infof("text\t[0x%08x-0x%08x]", &stext, &etext);
    infof("rodata\t[0x%08x-0x%08x]", &srodata, &erodata);
    infof("data\t[0x%08x-0x%08x]", &sdata, &edata);
    infof("bss\t[0x%08x-0x%08x]", &sbss, &ebss);
    infof("stack\t[0x%08x-0x%08x]", &sstack, &estack);
}

void main(void) {
    clear_bss();
    trap_init();
    display_info();
    new_user_context();
    
    // panic("Should not reach here");
    sbi_system_reset(SRST_T_SHUTDOWN, SRST_R_NO_REASON);
}
