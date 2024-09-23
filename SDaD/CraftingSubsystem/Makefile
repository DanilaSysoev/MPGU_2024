CC = g++

SRC_DIR = ./src
OUT_DIR = ./out
INCLUDE_DIR = ./include
TESTS_DIR = ./tests

FLAGS := -Wall -Werror -c -I$(INCLUDE_DIR) -I$(TESTS_DIR)
LIBS := -lgtest -lgmock -pthread

MODE = release

ifeq ($(MODE), debug)
FLAGS := $(FLAGS) -g
endif

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OUT := $(SRC:$(SRC_DIR)/%.cpp=$(OUT_DIR)/%.o)

SRC := $(subst $(SRC_DIR)/run_tests.cpp,,$(SRC))
INCLUDE = $(SRC:$(SRC_DIR)/%.cpp=$(INCLUDE_DIR)/%.hpp)



TESTS = $(SRC:$(SRC_DIR)/%.cpp=$(TESTS_DIR)/%_Tests.hpp)
TESTS := $(subst $(TESTS_DIR)/run_tests_Tests.hpp,,$(TESTS))

RES = $(OUT_DIR)/run_tests

all: $(RES)
	$(RES)

$(RES): $(OUT) $(TESTS) $(OUT_DIR)/run_tests.o
	$(CC) $(OUT) $(OUT_DIR)/run_tests.o $(LIBS) -o $(RES)

.PHONY: all

$(OUT_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/%.hpp
	$(CC) $(FLAGS) $< -o $@

$(OUT_DIR)/run_tests.o: $(TESTS_DIR)/run_tests.cpp $(TESTS_DIR)/run_tests.hpp $(TESTS)	
	$(CC) $(FLAGS) $(TESTS_DIR)/run_tests.cpp -o $(OUT_DIR)/run_tests.o

clean:
	rm $(OUT_DIR)/*

cleano:
	rm $(OUT_DIR)/*.o
