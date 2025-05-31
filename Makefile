OS:=$(shell uname -s)

ifeq ($(OS), Linux)
    LIB_EXT=.so
else
    LIB_EXT=.dll
endif

CC=gcc
CFLAGS=-Wall -Wextra -fPIC -g
LDFLAGS=-shared

BUILD_DIR=build
SRC_DIR=src
INCLUDE_DIR=include
LIB_NAME=tt_data_structures
LIB_FILE=$(BUILD_DIR)/$(LIB_NAME)$(LIB_EXT)

SRC=$(wildcard $(SRC_DIR)/*.c)
OBJ=$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

all:$(LIB_FILE)

$(LIB_FILE):$(OBJ)
	$(CC) $(LDFLAGS) -o $(LIB_FILE) $(OBJ)

$(BUILD_DIR)/%.o:$(SRC_DIR)/%.c
	@[ -d $(BUILD_DIR) ] || mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -r $(BUILD_DIR)