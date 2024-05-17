# Tools
TOOLPREFIX  = riscv64-unknown-elf-
CC          = $(TOOLPREFIX)gcc
AS          = $(TOOLPREFIX)as
AR          = $(TOOLPREFIX)ar
LD          = $(TOOLPREFIX)ld
OBJCOPY     = $(TOOLPREFIX)objcopy
OBJDUMP     = $(TOOLPREFIX)objdump

# Path
ROOT       ?= deadbeef
BUILD_DIR   = $(ROOT)/build
LIB_DIR     = $(ROOT)/lib
SRC_DIR     = $(PWD)/src
INC_DIR     = $(PWD)/inc

# Other
CFLAGS  += -Wall -Werror -no-pie -ggdb
CFLAGS  += -MD -static
CFLAGS  += -nostdlib
CFLAGS  += -mcmodel=medany -mstrict-align -march=rv64gc -mno-relax
CFLAGS  += -ffreestanding -fno-common -fno-stack-protector -fno-omit-frame-pointer -fno-pie -fno-asynchronous-unwind-tables

SRCS  = $(shell find $(SRC_DIR) -name "*.c" -type f) $(shell find $(SRC_DIR) -name "*.s" -type f)
OBJS  = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(filter %.c,$(SRCS))) \
    	$(patsubst $(SRC_DIR)/%.s,$(BUILD_DIR)/%.o,$(filter %.s,$(SRCS)))

TARGET = $(LIB_DIR)/$(notdir $(ROOT))

COLOR_R  := \e[31m
COLOR_G  := \e[32m
COLOR_Y  := \e[33m
COLOR_B  := \e[34m
COLOR_P  := \e[35m
COLOR_NO := \e[0m

all: $(TARGET).a

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOR_Y)CC$(COLOR_NO)\t$(COLOR_R)$(patsubst $(BUILD_DIR)/%, $(notdir $(ROOT)): %, $@)$(COLOR_NO)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(dir $@)
	@$(CC) $(AS_CFLAGS) -c $< -o $@
	@echo "$(COLOR_Y)AS$(COLOR_NO)\t$(COLOR_R)$(patsubst $(BUILD_DIR)/%, $(notdir $(ROOT)): %, $@)$(COLOR_NO)"

$(TARGET).a: $(OBJS)
	@mkdir -p $(dir $@)
	@$(AR) rcsT $(TARGET).a $(OBJS)
	@echo "$(COLOR_G)AR$(COLOR_NO)\t$(COLOR_G)$(patsubst $(LIB_DIR)/%, $(notdir $(ROOT)): %, $@)$(COLOR_NO)"
	@$(OBJDUMP) -d $(TARGET).a > $(TARGET).txt

clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf $(LIB_DIR)
	@echo "$(COLOR_R)RM$(COLOR_NO)\t$(COLOR_R)$(notdir $(ROOT)): build$(COLOR_NO)"