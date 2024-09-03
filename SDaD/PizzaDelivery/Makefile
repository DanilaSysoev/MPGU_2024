all: out/delivery

out/delivery: out/main.o out/logyc.o
	g++ out/logyc.o out/main.o -o out/delivery

out/main.o: src/main.cpp include/logyc.hpp
	g++ -c -Iinclude src/main.cpp -o out/main.o

out/logyc.o: include/logyc.hpp src/logyc.cpp
	g++ -c -Iinclude src/logyc.cpp -o out/logyc.o

cleano:
	rm out/main.o out/logyc.o

clean:
	rm out/main.o out/logyc.o out/delivery
