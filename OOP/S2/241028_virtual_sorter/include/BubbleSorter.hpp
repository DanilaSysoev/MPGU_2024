#pragma once

#include "Sorter.hpp"

class BubbleSorter : public Sorter {
public:
    void sort(std::vector<int>& data) const override;
};
