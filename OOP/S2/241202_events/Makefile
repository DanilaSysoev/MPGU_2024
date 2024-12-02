CC = g++

SRC_DIR = ./src
OUT_DIR = ./out
INCLUDE_DIR = ./include

FLAGS := -Wall -Werror -Wpedantic -I$(INCLUDE_DIR)

MODE = release

ifeq ($(MODE), debug)
FLAGS := $(FLAGS) -g
endif

all: $(OUT_DIR)/Event.o

$(OUT_DIR)/Event.o: $(SRC_DIR)/Event.cpp
	$(CC) -c $(SRC_DIR)/Event.cpp $(FLAGS) -o $(OUT_DIR)/Event.o

.PHONY: all

clean:
	rm $(OUT_DIR)/*

cleano:
	rm $(OUT_DIR)/*.o
