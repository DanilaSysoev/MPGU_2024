all: out/oop_demo

out/oop_demo: out/main.o out/MyFirstClass.o
	g++ out/main.o out/MyFirstClass.o -o out/oop_demo

out/main.o: src/main.cpp include/MyFirstClass.hpp
	g++ -c -Iinclude -Wall -Werror src/main.cpp -o out/main.o

out/MyFirstClass.o: src/MyFirstClass.cpp include/MyFirstClass.hpp
	g++ -c -Iinclude -Wall -Werror src/MyFirstClass.cpp -o out/MyFirstClass.o

clean:
	rm out/*

cleano:
	rm out/*.o
