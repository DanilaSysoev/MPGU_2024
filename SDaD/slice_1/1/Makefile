tests: out/tests_main
	out/tests_main

out/tests_main: out/tests_main.o out/ArrayExtension.o
	g++ out/tests_main.o out/ArrayExtension.o -o out/tests_main -lgtest -lgmock -pthread

out/tests_main.o: include/ArrayExtensionTests.hpp src/tests_main.cpp
	g++ -c -g src/tests_main.cpp -Wall -Werror -Iinclude -o out/tests_main.o

out/ArrayExtension.o: include/ArrayExtension.hpp src/ArrayExtension.cpp
	g++ -c -g src/ArrayExtension.cpp -Wall -Werror -Iinclude -o out/ArrayExtension.o

clean:
	rm out/*

cleano:
	rm out/*.o
