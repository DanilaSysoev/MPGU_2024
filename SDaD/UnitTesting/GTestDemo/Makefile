tests: out/tests_main
	out/tests_main

out/tests_main: out/tests_main.o out/square_equation.o
	g++ out/tests_main.o out/square_equation.o -o out/tests_main -lgtest -lgmock -pthread

out/tests_main.o: include/square_equation_tests.hpp src/tests_main.cpp include/assert_demo.hpp
	g++ -c src/tests_main.cpp -Wall -Werror -Iinclude -o out/tests_main.o

out/square_equation.o: include/square_equation.hpp src/square_equation.cpp
	g++ -c src/square_equation.cpp -Wall -Werror -Iinclude -o out/square_equation.o

clean:
	rm out/*

cleano:
	rm out/*.o
