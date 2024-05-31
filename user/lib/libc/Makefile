ROOT = $(YORIOS_HOME)/user/lib/libc

NEWLIB_DIR = $(ROOT)/newlib-cygwin/newlib/build
INSTALL_DIR = $(ROOT)/build

build:
	@if [ ! -d "$(INSTALL_DIR)" ]; then \
		mkdir -p $(NEWLIB_DIR); \
		cd $(NEWLIB_DIR) && ../configure --host=riscv64-unknown-elf --prefix=$(INSTALL_DIR) --disable-newlib-io-float CFLAGS='-mcmodel=medany -fPIC' > /dev/null && make && make install > /dev/null; \
		if [ ! -d "$(ROOT)/lib" ]; then \
			ln -sf $(ROOT)/build/riscv64-unknown-elf/lib $(ROOT)/lib; \
		fi; \
		if [ ! -d "$(ROOT)/inc" ]; then \
			ln -sf $(ROOT)/build/riscv64-unknown-elf/include $(ROOT)/inc; \
		fi; \
		echo "$(COLOR_G)BUILD$(COLOR_NO)\t$(COLOR_G)libc: libc.a$(COLOR_NO)"; \
	fi

KEEP ?= y

clean:
ifeq ('$(KEEP)', 'y') 
	@echo "$(COLOR_R)KEEP$(COLOR_NO)\t$(COLOR_R)$(notdir $(ROOT)): build$(COLOR_NO)"
else
	@rm -rf $(INSTALL_DIR) $(ROOT)/inc $(ROOT)/lib
	@echo "$(COLOR_R)RM$(COLOR_NO)\t$(COLOR_R)$(notdir $(ROOT)): build$(COLOR_NO)"
endif

.PHONY: build
include $(YORIOS_HOME)/user/lib/lib.mk