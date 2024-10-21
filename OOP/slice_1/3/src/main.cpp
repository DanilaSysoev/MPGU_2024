#include <vector>
#include <iostream>
#include <cmath>
#include "main.hpp"

using namespace std;

int main()
{
    Calculator c1(10);
    Calculator c2(20);
    const Calculator c3 = c1 + c2;
    const Calculator c4 = c1 - c2;
    const Calculator c5 = c1 * c2;
    const Calculator c6 = c1 / c2;
    const Calculator c7 = c1 % c2;

    cout << (c3.getValue() == 30 &&
             c4.getValue() == -10 &&
             c5.getValue() == 200 &&
             c6.getValue() == 0 &&
             c7.getValue() == 10) << endl;

    return 0;
}
