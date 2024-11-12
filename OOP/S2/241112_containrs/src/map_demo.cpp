#include <map>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void fill(auto& v, int cnt) {
    for (int i = 0; i < cnt; i++) {
        v.insert(make_pair("str " + to_string(i), i));
    }
}

void print_v(const auto& v) {
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << i->first << ": " << i->second << endl;
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
    map<string, int> v1;

    fill(v1, 10);
    print_v(v1);

    cout << v1["none"] << endl;

    print_v(v1);

    try {
        cout << v1.at("none 2") << endl;
    } catch (const std::out_of_range& e) {
        cout << "can't find \"none 2\" key" << endl;
    }

    return 0;
}
