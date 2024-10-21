#pragma once

#include <vector>

class ArrayExtension {
private:
    std::vector<int> array;
public:
    int& operator[](int index);
    int operator[](int index) const;
    std::vector<int>::size_type size() const;

    ArrayExtension(const std::vector<int>& array);
    int min() const;
    int max() const;
    int sum() const;
    float mean() const;
    float median() const;
};
