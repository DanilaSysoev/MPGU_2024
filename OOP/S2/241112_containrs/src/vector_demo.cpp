#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void fill(vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        v[i] = i;
    }
}

void print_v(const vector<int>& v) {
    for (auto i = v.cbegin(); i != v.cend(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 1);

    fill(v2);

    print_v(v3);
    
    v3.push_back(2);
    print_v(v2);

    v2.erase(v2.begin() + 5);
    print_v(v2);

    v2.insert(v2.begin() + 5, v3.begin(), v3.end());
    print_v(v2);

    v2.erase(v2.begin() + 5, v2.begin() + 10);
    print_v(v2);

    sort(v2.begin(), v2.end());
    print_v(v2);

    return 0;
}
