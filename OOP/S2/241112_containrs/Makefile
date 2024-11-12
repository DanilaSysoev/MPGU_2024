CC = g++ -std=c++20

SRC_DIR = ./src
OUT_DIR = ./out
INCLUDE_DIR = ./include

FLAGS := -Wall -Werror -Wpedantic -I$(INCLUDE_DIR)

MODE = release

ifeq ($(MODE), debug)
FLAGS := $(FLAGS) -g
endif

all: $(OUT_DIR)/map_demo $(OUT_DIR)/vector_demo $(OUT_DIR)/set_demo $(OUT_DIR)/list_demo

$(OUT_DIR)/map_demo: $(SRC_DIR)/map_demo.cpp
	$(CC) $(SRC_DIR)/map_demo.cpp $(FLAGS) -o $(OUT_DIR)/map_demo

$(OUT_DIR)/vector_demo: $(SRC_DIR)/vector_demo.cpp
	$(CC) $(SRC_DIR)/vector_demo.cpp $(FLAGS) -o $(OUT_DIR)/vector_demo

$(OUT_DIR)/set_demo: $(SRC_DIR)/set_demo.cpp
	$(CC) $(SRC_DIR)/set_demo.cpp $(FLAGS) -o $(OUT_DIR)/set_demo

$(OUT_DIR)/list_demo: $(SRC_DIR)/list_demo.cpp
	$(CC) $(SRC_DIR)/list_demo.cpp $(FLAGS) -o $(OUT_DIR)/list_demo

.PHONY: all

clean:
	rm $(OUT_DIR)/*

cleano:
	rm $(OUT_DIR)/*.o
