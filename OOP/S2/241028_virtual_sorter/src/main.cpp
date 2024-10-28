#include <iostream>
#include <vector>
#include "main.hpp"

using namespace std;

int main() {
    vector<int> data = { 4, 1, 3, 7, 8, 2, 5 };
    Sorter* sorter = new Sorter();
    sorter->sort(data);

    for(std::vector<int>::size_type i = 0; i < data.size(); ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    delete sorter;

    vector<int> data2 = { 4, 1, 3, 7, 8, 2, 5 };
    Sorter* sorter2 = new SelectionSorter();
    sorter2->sort(data2);

    for(std::vector<int>::size_type i = 0; i < data2.size(); ++i) {
        cout << data2[i] << " ";
    }
    cout << endl;

    delete sorter2;

    return 0;
}
