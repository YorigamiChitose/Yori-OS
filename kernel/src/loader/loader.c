#include <loader/loader.h>
#include <std/stdint.h>
#include <common/printf.h>
#include <sys/syscall.h>


__attribute__((aligned(4096))) uint8_t user_stack[USER_STACK_SIZE];

void new_user_context(void) {
  struct Context* nContext = (struct Context*)(user_stack + USER_STACK_SIZE - sizeof(struct Context));
  nContext->sepc = USER_ADDR;
  nContext->sstatus = 0x8000000200006000;
  nContext->scause = ENVIRONMENT_CALL_FROM_S_MODE;
  nContext->gpr[2] = (uint64_t)(user_stack + USER_STACK_SIZE);
  _goto_user(nContext);
}