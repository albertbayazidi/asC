CC := gcc
SRC := src
INC := lib
PROJECT_NAME := main

SRC_FILES := $(shell find $(SRC) -name '*.c')
LIB_FILES := $(shell find $(INC) -name '*.h')

inc := -I inc -lm -Ilib

CFLAGS := -Wall
OPTIMLEVEL := -O1


all:
	$(CC) $(CFLAGS) $(inc) $(SRC_FILES) $(OPTIMLEVEL) -o  $(PROJECT_NAME) 

.PHONY: clean
clean:
	rm -rf $(PROJECT_NAME)
