ROOT = $(PWD)
CFLAGS += -I$(ROOT)/../libc/inc
CFLAGS += -I$(ROOT)/inc
include ../Makefile

clean:
	@rm -rf $(PWD)/build
	@rm -rf $(PWD)/lib
	@echo "$(COLOR_R)RM$(COLOR_NO)\t$(COLOR_R)$(notdir $(ROOT)): build$(COLOR_NO)"