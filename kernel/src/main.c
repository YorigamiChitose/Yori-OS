#include <sbi/sbi.h>
#include <common/printf.h>
#include <common/stdbool.h>
#include <common/stdint.h>
#include <common/log.h>

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
        pointer = 0;
    }
}

void display_info(void) {
    printf("Hello, world!\n");
    errorf("text\t[0x%08x-0x%08x]", &stext, &etext);
    warnf("rodata\t[0x%08x-0x%08x]", &srodata, &erodata);
    infof("data\t[0x%08x-0x%08x]", &sdata, &edata);
    debugf("bss\t[0x%08x-0x%08x]", &sbss, &ebss);
    tracef("stack\t[0x%08x-0x%08x]", &sstack, &estack);
}

void main(void) {
    clear_bss();
    display_info();
    // panic("ALL DONE");
    sbi_system_reset(SRST_T_SHUTDOWN, SRST_R_NO_REASON);
}
