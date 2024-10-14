#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void h() {
    cout << "run h before error" << endl;
    int a;
    cin >> a;
    if(a > 0)
        throw "error inside h(): a > 0";
    else if(a < 0)
        throw a;
    else
        throw 'a';
    cout << "run h after error (not reached)" << endl;
}

void g() {
    cout << "run g before calling h()" << endl;
    h();
    cout << "run g after calling h() (not reached)" << endl;
}

void f() {
    cout << "run f before calling g()" << endl;
    try {
        g();
    } catch(const char* e) {
        cout << "run f catch block" << endl;
        cout << "error: " << e << endl;
    } catch(int e) {
        cout << "run f catch block" << endl;
        cout << "integr error: " << e << endl;
    } catch(...) {
        cout << "run f catch block" << endl;
        cout << "unknown error" << endl;
    }
    cout << "run f after calling g()" << endl;
}

void print_bad_demo(const vector<int>& data, int index) {
    try {
        cout << data.at(index) << ' ';
    } catch(const out_of_range& e) {
        // cout << "out of range" << endl;
    }
}

void print_right_demo(const vector<int>& data, int index) {
    if(index >= 0 && index < (int)data.size()) {
        cout << data.at(index) << ' ';
    } else {
        // cout << "out of range" << endl;
    }
}

int main() {
    // cout << "run main before calling f()" << endl;
    // f();
    // cout << "run main after calling f()" << endl;

    vector<int> data = {1, 2, 3, 4, 5};
    
    auto start = high_resolution_clock::now();
    for (int i = 0; i < 10000000; ++i)
        print_right_demo(data, 5);
    cout << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() / 1000.0 << endl;


    start = high_resolution_clock::now();
    for (int i = 0; i < 10000000; ++i)
        print_bad_demo(data, 5);
    cout << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() / 1000.0 << endl;
    return 0;
}
