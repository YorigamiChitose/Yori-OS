ROOT      = $(YORIOS_HOME)/user/lib/libos
CFLAGS    += -I$(ROOT)/../libc/inc
CFLAGS    += -I$(ROOT)/inc
SRC_DIR   = $(ROOT)/src
LIB_DIR   = $(ROOT)/lib
BUILD_DIR = $(ROOT)/build

build:
	@echo "There is no custom compilation"

KEEP ?= y

clean:
ifeq ('$(KEEP)', 'y')
	@echo "$(COLOR_R)KEEP$(COLOR_NO)\t$(COLOR_R)user: $(notdir $(ROOT))$(COLOR_NO)"
else
	@rm -rf $(PWD)/build $(PWD)/lib
	@echo "$(COLOR_R)RM$(COLOR_NO)\t$(COLOR_R)user: $(notdir $(ROOT))$(COLOR_NO)"
endif

.PHONY: build
include $(YORIOS_HOME)/user/lib/lib.mk