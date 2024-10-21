#include <vector>
#include <iostream>
#include <cmath>
#include "main.hpp"

using namespace std;

int main()
{
    vector<int> data = { 1, 4, -2, 3, 5, -8, 2 };
    auto result_1 = count_mean_even(data);

    const vector<int> data_2 = { 1, 4, -2, 3, 5, -8, 6 };
    auto result_2 = count_mean_even(data_2);

    cout << (abs(result_1 - 3) < 0.0001f && abs(result_2 - 5) < 0.0001f) << endl;

    return 0;
}
