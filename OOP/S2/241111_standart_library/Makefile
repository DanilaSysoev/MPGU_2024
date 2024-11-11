CC = g++

SRC_DIR = ./src
OUT_DIR = ./out
INCLUDE_DIR = ./include

FLAGS := -Wall -Werror -Wpedantic -I$(INCLUDE_DIR)

MODE = release

ifeq ($(MODE), debug)
FLAGS := $(FLAGS) -g
endif

all: $(OUT_DIR)/file_text_output $(OUT_DIR)/file_bin_output $(OUT_DIR)/file_text_input $(OUT_DIR)/file_bin_input

$(OUT_DIR)/file_text_output: $(SRC_DIR)/file_text_output.cpp
	$(CC) $(SRC_DIR)/file_text_output.cpp $(FLAGS) -o $(OUT_DIR)/file_text_output

$(OUT_DIR)/file_bin_output: $(SRC_DIR)/file_bin_output.cpp
	$(CC) $(SRC_DIR)/file_bin_output.cpp $(FLAGS) -o $(OUT_DIR)/file_bin_output

$(OUT_DIR)/file_text_input: $(SRC_DIR)/file_text_input.cpp
	$(CC) $(SRC_DIR)/file_text_input.cpp $(FLAGS) -o $(OUT_DIR)/file_text_input

$(OUT_DIR)/file_bin_input: $(SRC_DIR)/file_bin_input.cpp
	$(CC) $(SRC_DIR)/file_bin_input.cpp $(FLAGS) -o $(OUT_DIR)/file_bin_input

.PHONY: all

clean:
	rm $(OUT_DIR)/*

cleano:
	rm $(OUT_DIR)/*.o
