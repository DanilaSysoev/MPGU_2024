#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

void fill(auto& v, int cnt) {
    for (int i = 0; i < cnt; i++) {
        v.insert(i);
    }
}

void print_v(const auto& v) {
    for (auto i = v.cbegin(); i != v.cend(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

auto offset(auto iter, int offset) {
    for(int i = 0; i < offset; i++) {
        iter++;
    }
    return iter;
}

class second_digit_comp {
public:
    bool operator()(const int& a, const int& b) const {
        return (a % 10) < (b % 10);
    }
};

int main() {
    //set<int> v1;
    set<int, second_digit_comp> v1;

    fill(v1, 15);

    print_v(v1);

    v1.erase(offset(v1.begin(), 5));
    print_v(v1);

    v1.erase(offset(v1.begin(), 5), offset(v1.begin(), 10));
    print_v(v1);

    auto lb11 = v1.lower_bound(11);
    cout << *lb11 << endl;

    auto ub11 = v1.upper_bound(11);
    cout << *ub11 << endl;

    v1.emplace(6);
    print_v(v1);

    return 0;
}
