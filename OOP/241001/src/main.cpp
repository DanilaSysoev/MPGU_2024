#include <iostream>
#include "main.hpp"

using namespace std;

int main() {
    Vector2 v1(10, 20);
    Vector2 v2(1, 2);
    Vector2 v3 = v1 + v2;
    Vector2 v4 = v1 - v2;
    Vector2 v5 = v4 * 10;
    Vector2 v6 = 10 * v4;
    Vector2 v7 = v1 / 2;
    Vector2 v8 = -v1;
    Vector2 v9;
    cin >> v9;

    cout << v3 << ' ' <<
            v4 << ' ' <<
            v5 << ' ' <<
            v6 << ' ' <<
            v7 << ' ' <<
            v8 << ' ' <<
            v9 << endl;

    int a = 10;
    int b = a++;
    cout << a << ' ' << b << endl;

    a = 10;
    b = ++a;
    cout << a << ' ' << b << endl;

    v7 = v8; // v7.operator=(v8);

    Array a1(4);

    a1[0] = 10;
    a1[1] = 20;
    a1[2] = 30;
    a1[3] = 40;

    a1.print();

    a1 = a1;

    a1.print();

    return 0;
}
