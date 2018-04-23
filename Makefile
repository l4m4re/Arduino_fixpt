# Makefile for BeagleBone
#Project settings
PROJECT = libfixmath
LIB =
SRC = .
INC =

#Install settings
PREFIX?=/usr/local
TARGET_INC_DIR?=$(DESTDIR)$(PREFIX)/include/
TARGET_LIB_DIR?=$(DESTDIR)$(PREFIX)/lib//

#Compiler settings
CPP = gcc
CC = gcc
AS = gcc
LD = gcc
AR = ar
CPP_FLAGS = -O2 $(INC) -Wall -Wextra -c
CC_FLAGS  = -O2 $(INC) -Wall -Wextra -c
AS_FLAGS  = $(CC_FLAGS) -D_ASSEMBLER_
LD_FLAGS = -Wall

# Find all source files
SRC_CPP = $(foreach dir, $(SRC), $(wildcard $(dir)/*.cpp))
SRC_C   = $(foreach dir, $(SRC), $(wildcard $(dir)/*.c))
SRC_S   = $(foreach dir, $(SRC), $(wildcard $(dir)/*.S))
OBJ_CPP = $(patsubst %.cpp, %.o, $(SRC_CPP))
OBJ_C   = $(patsubst %.c, %.o, $(SRC_C))
OBJ_S   = $(patsubst %.S, %.o, $(SRC_S))
OBJ     = $(OBJ_CPP) $(OBJ_C) $(OBJ_S)

# Compile rules.
.PHONY : all
all: $(PROJECT).a

$(PROJECT).a: $(OBJ)
	$(AR) rcs $(PROJECT).a $(OBJ)

$(OBJ_CPP) : %.o : %.cpp
	$(CPP) $(CPP_FLAGS) -o $@ $<

$(OBJ_C) : %.o : %.c
	$(CC) $(CC_FLAGS) -o $@ $<

$(OBJ_S) : %.o : %.S
	$(AS) $(AS_FLAGS) -o $@ $<

install:
	install -m 0755 -d $(TARGET_LIB_DIR)
	install -m 0755 -d $(TARGET_INC_DIR)
	install -m 0644 *.a $(TARGET_LIB_DIR) 
	install -m 0644 fix16.h fix16.hpp libfixmath_conf.h $(TARGET_INC_DIR) 


# Clean rules
.PHONY : clean
clean:
	rm -f $(PROJECT).a $(OBJ)
