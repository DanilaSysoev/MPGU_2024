all: out/function

out/function: out/function_declaration.o out/function_definition.o
	g++ out/function_declaration.o out/function_definition.o -o out/function

out/function_declaration.o: src/function_declaration.cpp include/functions.hpp
	g++ -c -Iinclude src/function_declaration.cpp -o out/function_declaration.o

out/function_definition.o: src/function_definition.cpp
	g++ -c -Iinclude src/function_definition.cpp -o out/function_definition.o


clean:
	rm out/*

cleano:
	rm out/*.o

.PHONY: clean cleano
