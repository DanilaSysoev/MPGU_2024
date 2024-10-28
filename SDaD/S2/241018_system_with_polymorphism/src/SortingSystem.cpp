#include "Sorter.hpp"
#include "SortingSystem.hpp"

SortingSystem::SortingSystem(Sorter* sorter)
    : sorter(sorter)
{}

void SortingSystem::storeData(const std::vector<int>& data) {
    this->data = data;
}
std::vector<int> SortingSystem::getSorted() const {
    auto copy = this->data;
    sorter->sort(copy);
    return copy;
}

SortingSystem::~SortingSystem() {
    delete sorter;
}
