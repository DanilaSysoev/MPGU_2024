#include <iostream>
#include "main.hpp"

using namespace std;

int main() {
    {
        Base b1(10, 2.0f);
        Child c1(20, 3.0f, 4.5);

        b1.print();
        cout << endl;

        c1.print();
        cout << endl;
    }

    Base* bp1 = new Base(10, 2.0f);
    bp1->print(); // (*pb1).print()
    cout << endl;
    delete bp1;

    Child* cp1 = new Child(20, 3.0f, 4.5);
    cp1->print(); // (*cp1).print()
    cout << endl;
    delete cp1;

    Base* bp2 = new Child(10, 2.2f, 3.3);
    // Child* cp1 = new Base(20, 3.0f);

    bp2->print();
    cout << endl;
    delete bp2;

    return 0;
}
