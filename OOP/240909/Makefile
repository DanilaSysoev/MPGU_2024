all: out/function

out/function: out/main.o out/definition.o
	g++ out/main.o out/definition.o -o out/function

out/main.o: src/main.cpp include/declarations.hpp
	g++ -c -Iinclude src/main.cpp -o out/main.o

out/definition.o: src/definition.cpp
	g++ -c -Iinclude src/definition.cpp -o out/definition.o


clean:
	rm out/*

cleano:
	rm out/*.o

.PHONY: clean cleano
