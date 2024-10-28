#include "Sorter.hpp"

class SelectionSorter : public Sorter {
public:
    void sort(std::vector<int>& data) const override;
};
