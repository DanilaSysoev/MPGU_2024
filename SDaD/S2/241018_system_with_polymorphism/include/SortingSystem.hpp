#pragma once
#include <vector>

class Sorter;

class SortingSystem {
public:
    SortingSystem(Sorter* sorter);

    void storeData(const std::vector<int>& data);
    std::vector<int> getSorted() const;

    ~SortingSystem();

private:
    Sorter* sorter;
    std::vector<int> data;
};
