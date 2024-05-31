MAKEFLAGS += -s
LIB_DIR   = $(YORIOS_HOME)/user/lib
APP_DIR   = $(YORIOS_HOME)/user/app

ALL_LIB = libos libc
ALL_APP = hello dummy

LIBS  = $(foreach lib, $(ALL_LIB), $(LIB_DIR)/$(lib)/lib/$(lib).a)
APPS  = $(foreach app, $(ALL_APP), $(APP_DIR)/$(app)/build/$(app).elf)

COLOR_R  := \e[31m
COLOR_G  := \e[32m
COLOR_Y  := \e[33m
COLOR_B  := \e[34m
COLOR_P  := \e[35m
COLOR_NO := \e[0m

.PHONY: libs apps clean

apps: libs
	@for app in $(ALL_APP); do \
		cd $(APP_DIR)/$$app && $(MAKE) all; \
	done

libs:
	@for lib in $(ALL_LIB); do \
		cd $(LIB_DIR)/$$lib && $(MAKE) all; \
	done

clean-all:
	@for lib in $(ALL_LIB); do \
		cd $(LIB_DIR)/$$lib && $(MAKE) clean; \
	done
	@for app in $(ALL_APP); do \
		cd $(APP_DIR)/$$app && $(MAKE) clean; \
	done