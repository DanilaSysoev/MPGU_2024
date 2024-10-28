#pragma once
#include<vector>

class Sorter {
public:
    virtual void sort(std::vector<int>& data) const;

    virtual ~Sorter() = default;
};
