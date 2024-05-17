#ifndef __LOADER_H__
#define __LOADER_H__

#include <std/stdint.h>
#define USER_STACK_SIZE (0x1000)
#define USER_ADDR 0x80400000
void new_user_context(void);
extern uint8_t user_stack[USER_STACK_SIZE];
#endif