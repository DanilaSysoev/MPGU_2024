#include <thread>
#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

void sum(int from, int to, int mod, int* res) {
    ifstream in("res/res.dat", ios::binary);

    if(!in)
        return;

    int sum = 0;
    in.seekg(from * sizeof(int));
    for (int i = from; i < to; i++) {
        int x;
        in.read(reinterpret_cast<char *>(&x), sizeof(int));
        sum += x;
        sum %= mod;
    }
    in.close();
    *res = sum;
}

int main(int argc, char** argv)
{
    int num_threads = 2;

    if (argc == 2) {
        num_threads = atoi(argv[1]);
    }

    vector<int> res(num_threads);

    int block_size = 1000000000 / num_threads;
    vector<thread> threads;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < num_threads; i++) {
        threads.push_back(thread(sum, i * block_size, (i + 1) * block_size, 997, &res[i]));
    }
    for (int i = 0; i < num_threads; i++) {
        threads[i].join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    int sum = 0;
    for (int i = 0; i < num_threads; i++) {
        sum += res[i];
        sum %= 997;
    }
    cout << sum << endl;
    auto fs = end - start;
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(fs);

    cout << duration.count() / 1000.0 << endl;

    return 0;
}
