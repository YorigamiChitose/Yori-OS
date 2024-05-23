ROOT = $(PWD)

NEWLIB_DIR = $(ROOT)/newlib-cygwin/newlib/build
INSTALL_DIR = $(ROOT)/build

install:
	@if [ ! -d "$(INSTALL_DIR)" ]; then \
		echo "$(COLOR_G)AR$(COLOR_NO)\t$(COLOR_G)libc: libc.a$(COLOR_NO)"; \
		mkdir -p $(NEWLIB_DIR); \
		cd $(NEWLIB_DIR) && ../configure --host=riscv64-unknown-elf --prefix=$(INSTALL_DIR) --disable-newlib-io-float CFLAGS='-mcmodel=medany -fPIC' && make && make install; \
		ln -sf $(ROOT)/build/riscv64-unknown-elf/include $(ROOT)/inc; \
		ln -sf $(ROOT)/build/riscv64-unknown-elf/lib $(ROOT)/lib; \
		ln -sf /dev/null $(ROOT)/src; \
	fi

KEEP ?= n

clean:
ifeq ('$(KEEP)', 'y')
	@echo "$(COLOR_R)KEEP$(COLOR_NO)\t$(COLOR_R)$(notdir $(ROOT)): build$(COLOR_NO)"
else
	@rm -rf $(INSTALL_DIR)
	@echo "$(COLOR_R)RM$(COLOR_NO)\t$(COLOR_R)$(notdir $(ROOT)): build$(COLOR_NO)"
endif

.PHONY: install

include ../Makefile