#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

void fill(list<int>& v) {
    int val = 0;
    for (auto i = v.begin(); i != v.end(); i++, ++val) {
        *i = val;
    }
}

void print_v(const list<int>& v) {
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

int main() {
    list<int> v1;
    list<int> v2(10);
    list<int> v3(10, 1);

    fill(v2);

    print_v(v3);
    
    v3.push_back(2);
    print_v(v2);

    v2.erase(offset(v2.begin(), 5));
    print_v(v2);

    v2.insert(offset(v2.begin(), 5), v3.begin(), v3.end());
    print_v(v2);

    v2.erase(offset(v2.begin(), 5), offset(v2.begin(), 10));
    print_v(v2);

    return 0;
}
