OPENSBI = opensbi/build/platform/generic/firmware/fw_jump
KERNEL = kernel/build/kernel
QEMU = qemu-system-riscv64
QEMU_ARG = -M virt -bios $(OPENSBI).elf -device loader,file=$(KERNEL).bin,addr=0x80200000 -nographic
MAKEFLAGS += --no-print-directory


$(OPENSBI).elf:
	@make -C opensbi CROSS_COMPILE=riscv64-linux-gnu- PLATFORM=generic FW_JUMP_ADDR=0x80200000

$(KERNEL).elf:
	@cd kernel && make

clean:
	@cd kernel && make clean
# @cd opensbi && make clean

run: $(OPENSBI).elf $(KERNEL).elf
	@$(QEMU) $(QEMU_ARG)

gdbserver: $(OPENSBI).elf $(KERNEL).elf
	@$(QEMU) $(QEMU_ARG) -s -S

gdbclient:
	@gdb-multiarch -ex 'file $(KERNEL).elf' -ex 'set arch riscv:rv64' -ex 'target remote localhost:1234' --init-command .gdbinit

.PHONY: $(KERNEL).elf clean