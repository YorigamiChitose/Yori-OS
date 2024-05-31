MAKEFLAGS += -s
# Tools
TOOLPREFIX  = riscv64-unknown-elf-
CC          = $(TOOLPREFIX)gcc
AS          = $(TOOLPREFIX)as
LD          = $(TOOLPREFIX)ld
OBJCOPY     = $(TOOLPREFIX)objcopy
OBJDUMP     = $(TOOLPREFIX)objdump
GDB         = gdb-multiarch

# lib include
LIB_INC = $(foreach lib, $(ALL_LIB), $(LIB_DIR)/$(lib)/inc)

# Other
CFLAGS  += -Wall -Werror -no-pie -ggdb
CFLAGS  += -MMD
CFLAGS  += -nostdlib
CFLAGS  += -mcmodel=medany -mstrict-align -march=rv64gc -mno-relax
CFLAGS  += -ffreestanding -fno-common -fno-stack-protector -fno-omit-frame-pointer -fno-pie -fno-asynchronous-unwind-tables -fno-builtin
CFLAGS  += $(patsubst %, -I%, $(LIB_INC))
LDFLAGS += -z max-page-size=4096 -T$(YORIOS_HOME)/user/other/linker.ld

all: $(TARGET).elf

$(TEMP_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOR_Y)CC$(COLOR_NO)\t$(COLOR_R)$(patsubst $(TEMP_DIR)/%, user: %, $@)$(COLOR_NO)"

$(TEMP_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(dir $@)
	@$(AS) $(AS_CFLAGS) -c $< -o $@
	@echo "$(COLOR_Y)AS$(COLOR_NO)\t$(COLOR_R)$(patsubst $(TEMP_DIR)/%, user: %, $@)$(COLOR_NO)"

$(TARGET).elf: $(OBJS)
	@mkdir -p $(dir $@)
	@$(LD) $(LDFLAGS) -o $(TARGET).elf $(OBJS) $(LIBS) $(LIBS)
	@echo "$(COLOR_G)LD$(COLOR_NO)\t$(COLOR_G)$(patsubst $(BUILD_DIR)/%, user: %, $@)$(COLOR_NO)"
	@$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin
	@$(OBJDUMP) -d $(TARGET).elf > $(TARGET).txt

clean:
	@rm -rf $(BUILD_DIR)
	@echo "$(COLOR_R)RM$(COLOR_NO)\t$(COLOR_R)user: $(notdir $(ROOT))$(COLOR_NO)"

include $(YORIOS_HOME)/user/Makefile