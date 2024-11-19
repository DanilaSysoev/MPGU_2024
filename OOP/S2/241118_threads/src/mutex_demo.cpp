#include <thread>
#include <fstream>
#include <string>
#include <vector>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx;

void write_async(const string& filename,
                 const vector<int>& data,
                 int start,
                 int end)
{
    for (int i = start; i < end;) {
        mtx.lock();
        ofstream out(filename, ios::app);
        for (int j = 0; j < 100 && i < end; ++j, ++i)
            out << data[i] << ' ';
        out.close();
        mtx.unlock();
        this_thread::sleep_for(chrono::milliseconds(1000 + rand() % 2000));
    }
}

int main() {
    vector<int> data(100000);
    ofstream out("res/out.txt");
    out.close();
    for (size_t i = 0; i < data.size(); ++i)
        data[i] = i;

    thread t1(write_async, "res/out.txt", data, 0, 25000);
    thread t2(write_async, "res/out.txt", data, 25000, 50000);
    thread t3(write_async, "res/out.txt", data, 50000, 75000);
    thread t4(write_async, "res/out.txt", data, 75000, 100000);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
