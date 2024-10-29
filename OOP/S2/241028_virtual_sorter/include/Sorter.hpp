#pragma once
#include<vector>

class Sorter {
public:
    virtual void sort(std::vector<int>& data) const = 0;

    virtual ~Sorter() = default;
};
