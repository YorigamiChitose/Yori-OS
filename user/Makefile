# Tools
TOOLPREFIX  = riscv64-unknown-elf-
CC          = $(TOOLPREFIX)gcc
AS          = $(TOOLPREFIX)as
LD          = $(TOOLPREFIX)ld
OBJCOPY     = $(TOOLPREFIX)objcopy
OBJDUMP     = $(TOOLPREFIX)objdump
GDB         = gdb-multiarch

# Path
ROOT      = $(PWD)
BUILD_DIR = $(ROOT)/build
TEMP_DIR  = $(BUILD_DIR)/temp
SRC_DIR   = $(PWD)/src
INC_DIR   = $(PWD)/inc $(foreach lib, $(ALL_LIB), $(LIB_DIR)/$(lib)/inc)
LIB_DIR   = $(PWD)/lib

# Other
CFLAGS      += -Wall -Werror -no-pie -ggdb
CFLAGS      += -MMD
CFLAGS      += -nostdlib
CFLAGS      += -mcmodel=medany -mstrict-align -march=rv64gc -mno-relax
CFLAGS      += -ffreestanding -fno-common -fno-stack-protector -fno-omit-frame-pointer -fno-pie -fno-asynchronous-unwind-tables -fno-builtin
CFLAGS      += $(patsubst %, -I%, $(INC_DIR))
AS_CFLAGS   ?= $()
LDFLAGS      = -z max-page-size=4096 -Tsrc/other/linker.ld

ALL_LIB = libos libtest

LIBS  = $(foreach lib, $(ALL_LIB), $(LIB_DIR)/$(lib)/lib/$(lib).a)
SRCS  = $(shell find $(SRC_DIR) -name "*.c" -type f) $(shell find $(SRC_DIR) -name "*.s" -type f)
OBJS  = $(patsubst $(SRC_DIR)/%.c,$(TEMP_DIR)/%.o,$(filter %.c,$(SRCS))) \
    	$(patsubst $(SRC_DIR)/%.s,$(TEMP_DIR)/%.o,$(filter %.s,$(SRCS)))

TARGET = $(BUILD_DIR)/user

COLOR_R  := \e[31m
COLOR_G  := \e[32m
COLOR_Y  := \e[33m
COLOR_B  := \e[34m
COLOR_P  := \e[35m
COLOR_NO := \e[0m

.PHONY: libs

all: $(TARGET).elf

libs:
	@for lib in $(ALL_LIB); do \
		cd $(LIB_DIR)/$$lib && $(MAKE); \
	done


$(TEMP_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(COLOR_Y)CC$(COLOR_NO)\t$(COLOR_R)$(patsubst $(TEMP_DIR)/%, user: %, $@)$(COLOR_NO)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(TEMP_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(dir $@)
	@echo "$(COLOR_Y)AS$(COLOR_NO)\t$(COLOR_R)$(patsubst $(TEMP_DIR)/%, user: %, $@)$(COLOR_NO)"
	@$(AS) $(AS_CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJS) libs
	@mkdir -p $(dir $@)
	@echo "$(COLOR_G)LD$(COLOR_NO)\t$(COLOR_G)$(patsubst $(BUILD_DIR)/%, user: %, $@)$(COLOR_NO)"
	@$(LD) $(LDFLAGS) -o $(TARGET).elf $(OBJS) $(LIBS) $(LIBS)
	@$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin
	@$(OBJDUMP) -d $(TARGET).elf > $(TARGET).txt

clean:
	@rm -rf $(BUILD_DIR)
	@echo "$(COLOR_R)RM$(COLOR_NO)\t$(COLOR_R)user: build$(COLOR_NO)"
	@for lib in $(ALL_LIB); do \
		cd $(LIB_DIR)/$$lib && $(MAKE) clean; \
	done