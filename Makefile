OPENSBI = $(YORIOS_HOME)/opensbi/build/platform/generic/firmware/fw_jump
KERNEL = $(YORIOS_HOME)/kernel/build/kernel
USER = $(YORIOS_HOME)/user/app/hello/build/hello
QEMU = qemu-system-riscv64
QEMU_ARG = \
	-machine virt \
	-bios $(OPENSBI).bin \
	-kernel $(KERNEL).bin \
	-device loader,file=$(USER).bin,addr=0x80400000 \
	-nographic
MAKEFLAGS += -s


$(OPENSBI).bin:
	@make -C opensbi CROSS_COMPILE=riscv64-unknown-elf- PLATFORM=generic FW_JUMP_ADDR=0x80200000

$(KERNEL).bin:
	@cd kernel && make

$(USER).bin:
	@cd user && make
clean:
# @cd opensbi && make clean
	@cd kernel && make clean
	@cd user && make clean-all

run: $(OPENSBI).bin $(KERNEL).bin $(USER).bin
	@$(QEMU) $(QEMU_ARG)

gdbserver: $(OPENSBI).bin $(KERNEL).bin $(USER).bin
	@$(QEMU) $(QEMU_ARG) -s -S

gdbclient:
	@riscv64-unknown-elf-gdb \
		-ex 'file $(KERNEL).elf' -ex 'set arch riscv:rv64' \
		-ex 'target remote localhost:1234' \
		--init-command .gdbinit

.PHONY: $(KERNEL).bin $(USER).bin clean