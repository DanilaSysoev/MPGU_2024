#include <iostream>
#include "BubbleSorter.hpp"

void BubbleSorter::sort(std::vector<int>& data) const {
    std::cout << "Bubble sorting... \n";

    for(auto i = data.size(); i > 1; --i) {
        int cnt = 0;
        for(std::vector<int>::size_type cur = 0; cur < i - 1; ++cur) {
            if(data[cur] > data[cur + 1]) {
                std::swap(data[cur], data[cur + 1]);
                ++cnt;
            }
        }
        if(cnt == 0)
            break;
    }
}
