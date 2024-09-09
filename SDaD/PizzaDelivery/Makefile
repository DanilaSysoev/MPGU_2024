all: out/delivery

out/delivery: out/main.o out/pizzaRepository.o out/console_ui.o out/orderRepository.o out/entities.o out/outputService.o
	g++ out/pizzaRepository.o out/main.o out/console_ui.o out/orderRepository.o out/entities.o out/outputService.o -o out/delivery

out/main.o: src/main.cpp include/pizzaRepository.hpp include/orderRepository.hpp include/console_ui.hpp include/entities.hpp
	g++ -c -Iinclude src/main.cpp -o out/main.o

out/pizzaRepository.o: include/pizzaRepository.hpp src/pizzaRepository.cpp
	g++ -c -Iinclude src/pizzaRepository.cpp -o out/pizzaRepository.o

out/orderRepository.o: include/orderRepository.hpp src/orderRepository.cpp
	g++ -c -Iinclude src/orderRepository.cpp -o out/orderRepository.o

out/entities.o: include/entities.hpp src/entities.cpp
	g++ -c -Iinclude src/entities.cpp -o out/entities.o

out/outputService.o: include/outputService.hpp src/outputService.cpp
	g++ -c -Iinclude src/outputService.cpp -o out/outputService.o

out/console_ui.o: include/console_ui.hpp src/console_ui.cpp
	g++ -c -Iinclude src/console_ui.cpp -o out/console_ui.o

cleano:
	rm out/*.o

clean:
	rm out/*
