CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Werror
SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)
EXECUTABLE = $(BIN_DIR)/main

# Garante que a pasta bin exista
$(shell mkdir -p $(BIN_DIR))

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR)/*.o $(EXECUTABLE)