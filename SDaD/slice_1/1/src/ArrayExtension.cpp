#include <algorithm>
#include "ArrayExtension.hpp"

int& ArrayExtension::operator[](int index) {
    return array[index];
}
int ArrayExtension::operator[](int index) const {
    return array[index];
}
std::vector<int>::size_type ArrayExtension::size() const {
    return (int)array.size();
}

ArrayExtension::ArrayExtension(const std::vector<int>& array)
    : array(array)
{}

int ArrayExtension::min() const {
    int minValue = array[0];
    for (std::vector<int>::size_type i = 1; i < array.size(); i++) {
        if (array[i] < minValue)
            minValue = array[i];
    }
    return minValue;
}
int ArrayExtension::max() const {
    int maxValue = array[0];
    for (std::vector<int>::size_type i = 1; i < array.size(); i++) {
        if (array[i] > maxValue)
            maxValue = array[i];
    }
    return maxValue;
}
int ArrayExtension::sum() const {
    int sum = 0;
    for (std::vector<int>::size_type i = 0; i < array.size(); i++) {
        sum += array[i];
    }
    return sum;
}
float ArrayExtension::mean() const {
    return (float)sum() / size();
}
float ArrayExtension::median() const {
    float median = 0;
    std::vector<int> sortedArray = array;
    std::sort(sortedArray.begin(), sortedArray.end());
    if (size() % 2 == 0) {
        median = (sortedArray[size() / 2 - 1] + sortedArray[size() / 2]) / 2.0f;
    }
    else {
        median = sortedArray[size() / 2];
    }
    return median;
}
