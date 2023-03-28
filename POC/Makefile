CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lgsl -lgslcblas -lm

SRC_DIR = ./lib
BUILD_DIR = ./

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

all: main

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

main: $(OBJ) $(BUILD_DIR)/main.o
	$(CC) $(CFLAGS) $(OBJ) $(BUILD_DIR)/main.o -o $@ $(LDFLAGS)

clean:
	rm -f main $(OBJ) $(BUILD_DIR)/main.o

.PHONY: all clean

