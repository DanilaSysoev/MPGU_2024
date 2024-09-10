#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include "declarations.hpp"

using namespace std;

/*
<type> <name> (<parameters>);
<parameters>:
    <empty>
    <type> [<name>][, <parameters>];
*/

int main()
{
    // const int maxArrSize = 10;

    // int a = 0, b = 0;
    // cin >> a >> b;
    // cout << sum(a, b) << '\n';

    // int arr[maxArrSize];
    // int size = 0;
    // cout << "enter size of array:\n";
    // cin >> size;
    // for (int i = 0; i < size; i++)
    //     cin >> arr[i];

    // cout << sum(arr, maxArrSize) << '\n';

    // int a = 10;
    // int* pa = &a;
    // // int a, b, c;
    // // int* pa, *b, *c; // pa - pointer, b - int, c - int

    // int b = *pa;
    // cout << b << '\n';    // const int maxArrSize = 10;
    // array<int, maxArrSize> arr = { 0 };
    // for(int i = 0; i < maxArrSize; ++i)
    //     cin >> arr[i];

    // for(int i = 0; i < maxArrSize; ++i)
    //     cout << arr[i] << ' ';
    // return 0;

    // *pa = 100;
    // cout << a << '\n';
    // cout << hex << setfill('0') << setw(16) << (long long)pa << '\n';



    // int size = 0;
    // cin >> size;
    // int arr2[10] = { 0 };

    // int* arr = new int[size];
    // for(int i = 0; i < size; i++)
    //     cin >> arr[i];
    // // ...
    // delete[] arr;

    // int* data_unit = new int(10);
    // delete data_unit;

    // const int maxArrSize = 10;
    // array<int, maxArrSize> arr = { 0 };
    // for(int i = 0; i < maxArrSize; ++i)
    //     cin >> arr[i];

    // for(int i = 0; i < maxArrSize; ++i)
    //     cout << arr[i] << ' ';

    vector<int> vec = { 1, 2, 3, 4, 5 };
    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << ' ';
    cout << '\n' << vec.capacity() << '\n';

    vec.push_back(6);
    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << ' ';
    cout << '\n' << vec.capacity() << '\n';

    vec.pop_back();
    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << ' ';
    cout << '\n' << vec.capacity() << '\n';

    vec.insert(vec.begin() + 2, 7);
    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << ' ';
    cout << '\n' << vec.capacity() << '\n';

    vec.erase(vec.begin() + 2);
    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << ' ';
    cout << '\n' << vec.capacity() << '\n';

    vec.erase(vec.begin() + 2, vec.begin() + 4);
    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << ' ';
    cout << '\n' << vec.capacity() << '\n';

    return 0;
}
