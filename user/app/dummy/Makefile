ROOT      = $(YORIOS_HOME)/user/app/dummy
BUILD_DIR = $(ROOT)/build
TEMP_DIR  = $(BUILD_DIR)/temp
SRC_DIR   = $(ROOT)/src
INC_DIR   = $(ROOT)/inc

CFLAGS += -I$(INC_DIR)
SRCS  = $(shell find $(SRC_DIR) -name "*.c" -type f)
OBJS  = $(patsubst $(SRC_DIR)/%.c,$(TEMP_DIR)/%.o,$(filter %.c,$(SRCS)))
TARGET = $(BUILD_DIR)/dummy

include $(YORIOS_HOME)/user/app/user.mk