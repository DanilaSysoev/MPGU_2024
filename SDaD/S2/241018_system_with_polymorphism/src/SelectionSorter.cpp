#include "SelectionSorter.hpp"
#include <iostream>

void SelectionSorter::sort(std::vector<int>& data) const {
    std::cout << "Selection sorting...\n";
    for (size_t i = 0; i < data.size(); ++i) {
        int min = i;
        for (size_t j = i + 1; j < data.size(); ++j) {
            if (data[j] < data[min]) {
                min = j;
            }
        }
        std::swap(data[i], data[min]);
    }
}
