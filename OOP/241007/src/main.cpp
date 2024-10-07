#include <iostream>

#include "main.hpp"

int useServiceAdd(NumberService service, int arg) {
    service.add(arg);
    return service.getNumber();
}

int useServiceAdd(NumberService service, const SomeConvertable& arg) {
    // service.add(static_cast<int>(arg));
    service.add(static_cast<int>(arg));
    return service.getNumber();
}

Movable build(int size) {
    auto m = Movable(size);
    m[0] = 10;
    return m;
}

int main() {
    // Action action(10);

    // action();
    // std::cout << action(10) << std::endl;

    // NumberService service(0);
    // std::cout << useServiceAdd(service, 10) << std::endl;

    // std::cout << useServiceAdd(NumberService(10), 10) << std::endl;

    // SomeConvertable convertable(2.5, 10);

    // std::cout << "SomeConvertable as int: " << int(convertable)
    //           << " \nSomeConvertable as double: " << double(convertable)
    //           << std::endl;

    // std::cout << "SomeConvertable as int: " << static_cast<int>(convertable)
    //           << " \nSomeConvertable as double: " << static_cast<double>(convertable)
    //           << std::endl;

    // std::cout << useServiceAdd(NumberService(10), convertable) << std::endl;

    Movable m1(10);
    Movable m2(10);
    m2 = build(10);

    Movable m3(20);
    m3 = std::move(m1);

    // std::cout << m1.getSize() << std::endl;
    std::cout << m2.getSize() << std::endl;
    std::cout << m3.getSize() << std::endl;

    return 0;
}
