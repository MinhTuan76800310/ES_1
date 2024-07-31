#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here>
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM ?= DHOST

TARGET = c1m2
OUTFILE = $(TARGET).o

# General Flags
COMMON_FLAGS = -Wall -Werror -g -O0 -std=c99

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = -mcpu=cortex-m4
ARCH = -march=armv7e-m
FLOAT_ABI = -mfloat-abi=hard
FPU = -mfpu=fpv4-sp-d16
SPECS = --specs=nosys.specs

ifeq ($(PLATFORM), HOST)
	CC = gcc
	LD = gcc
	PLATFORM_FLAGS = -DHOST
	INCLUDE_PATHS = -I./../include/common
else ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc 
	LD = arm-none-eabi-ld
	PLATFORM_FLAGS = -DMSP432 $(CPU) $(ARCH) $(FLOAT_ABI) $(FPU) $(SPECS)
	LDFLAGS = -T $(LINKER_FILE)
	INCLUDE_PATHS = -I./../include/common
endif

# Compiler Flags and Defines
LDFLAGS += $(COMMON_FLAGS)
CFLAGS = $(COMMON_FLAGS) $(PLATFORM_FLAGS) $(INCLUDE_PATHS)
CPPFLAGS = 

# Object files
OBJS = $(SOURCES:.c=.o)

# Build Targets
.PHONY: build clean

# default build target
build: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) *.i *.d *.asm *.map
	@echo "Clean complete"
