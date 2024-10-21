CC = g++

SRC_DIR = ./src
OUT_DIR = ./out
INCLUDE_DIR = ./include

FLAGS := -Wall -Werror -Wpedantic -c -I$(INCLUDE_DIR)

MODE = release

ifeq ($(MODE), debug)
FLAGS := $(FLAGS) -g
endif

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OUT := $(SRC:$(SRC_DIR)/%.cpp=$(OUT_DIR)/%.o)

SRC := $(SRC:$(SRC_DIR)/main.cpp=)
INCLUDE := $(SRC:$(SRC_DIR)/%.cpp=$(INCLUDE_DIR)/%.hpp)

RES = $(OUT_DIR)/program

all: $(RES)

$(RES): $(OUT)
	$(CC) $(OUT) -lm -o $(RES)

.PHONY: all

$(OUT_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/%.hpp
	$(CC) $(FLAGS) $< -o $@

clean:
	rm $(OUT_DIR)/*

cleano:
	rm $(OUT_DIR)/*.o
