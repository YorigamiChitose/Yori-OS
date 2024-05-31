# Tools
TOOLPREFIX  = riscv64-unknown-elf-
CC          = $(TOOLPREFIX)gcc
AS          = $(TOOLPREFIX)as
LD          = $(TOOLPREFIX)ld
OBJCOPY     = $(TOOLPREFIX)objcopy
OBJDUMP     = $(TOOLPREFIX)objdump
GDB         = gdb-multiarch

# Path
ROOT      = $(YORIOS_HOME)/kernel
BUILD_DIR = $(ROOT)/build
TEMP_DIR  = $(BUILD_DIR)/temp
SRC_DIR   = $(ROOT)/src
INC_DIR   = $(ROOT)/inc

# Other
CFLAGS      += -Wall -Werror -no-pie -ggdb
CFLAGS      += -MD
CFLAGS      += -nostdlib
CFLAGS      += -mcmodel=medany -mstrict-align -march=rv64gc -mno-relax
CFLAGS      += -ffreestanding -fno-common -fno-stack-protector -fno-omit-frame-pointer -fno-pie -fno-asynchronous-unwind-tables
CFLAGS      += -I$(INC_DIR)
AS_CFLAGS   ?= $()
LDFLAGS      = -z max-page-size=4096 -Tsrc/other/linker.ld

SRCS  = $(shell find $(SRC_DIR) -name "*.c" -type f) $(shell find $(SRC_DIR) -name "*.s" -type f)
OBJS  = $(patsubst $(SRC_DIR)/%.c,$(TEMP_DIR)/%.o,$(filter %.c,$(SRCS))) \
    	$(patsubst $(SRC_DIR)/%.s,$(TEMP_DIR)/%.o,$(filter %.s,$(SRCS)))

TARGET = $(BUILD_DIR)/kernel

COLOR_R  := \e[31m
COLOR_G  := \e[32m
COLOR_Y  := \e[33m
COLOR_B  := \e[34m
COLOR_P  := \e[35m
COLOR_NO := \e[0m

all: $(TARGET).elf

$(TEMP_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOR_Y)CC$(COLOR_NO)\t$(COLOR_R)$(patsubst $(TEMP_DIR)/%, kernel: %, $@)$(COLOR_NO)"

$(TEMP_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(dir $@)
	@$(CC) $(AS_CFLAGS) -c $< -o $@
	@echo "$(COLOR_Y)AS$(COLOR_NO)\t$(COLOR_R)$(patsubst $(TEMP_DIR)/%, kernel: %, $@)$(COLOR_NO)"

$(TARGET).elf: $(OBJS)
	@mkdir -p $(dir $@)
	@$(LD) $(LDFLAGS) -o $(TARGET).elf $(OBJS)
	@echo "$(COLOR_G)LD$(COLOR_NO)\t$(COLOR_G)$(patsubst $(BUILD_DIR)/%, kernel: %, $@)$(COLOR_NO)"
	@$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin
	@$(OBJDUMP) -d $(TARGET).elf > $(TARGET).txt

clean:
	@rm -rf $(BUILD_DIR)
	@echo "$(COLOR_R)RM$(COLOR_NO)\t$(COLOR_R)kernel: elf$(COLOR_NO)"