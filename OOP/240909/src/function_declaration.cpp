#include <iostream>
#include "functions.hpp"

using namespace std;

/*
<type> <name> (<parameters>);
<parameters>:
    <empty>
    <type> [<name>][, <parameters>];
*/
int sum(int a, int b);
int sum(int arr[], int size);

int main()
{
    const int maxArrSize = 10;

    int a = 0, b = 0;
    cin >> a >> b;
    cout << sum(a, b) << '\n';

    int arr[maxArrSize];
    int size = 0;
    cout << "enter size of array:\n";
    cin >> size;
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << sum(arr, maxArrSize) << '\n';
    return 0;
}
