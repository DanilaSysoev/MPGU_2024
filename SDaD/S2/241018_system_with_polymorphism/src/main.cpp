#include <fstream>
#include <iostream>
#include <stdexcept>
#include "main.hpp"

using namespace std;
using namespace nlohmann;

int main() {
    ifstream f("configs/config.json");
    json config = json::parse(f);
    f.close();

    Sorter* sorter = nullptr;
    if(!config.contains("sorter type") || config["sorter type"] == "default")
        sorter = new Sorter();
    else if(config["sorter type"] == "selection")
        sorter = new SelectionSorter();
    else
        throw std::logic_error("Unknown sorter type");

    SortingSystem system(sorter);
    if(!config.contains("data source") || config["data source"] == "console")
        system.storeData(readFromConsole());
    else if(config["data source"] == "file" && config.contains("file name"))
        system.storeData(readFromFile(config["file name"]));
    else
        throw std::logic_error("Unknown data source");

    for(auto& i: system.getSorted())
        cout << i << ' ';
    cout << endl;

    return 0;
}

std::vector<int> readFromConsole() {
    int size;
    cin >> size;
    vector<int> data(size);
    for (int i = 0; i < size; i++)
        cin >> data[i];

    return data;
}

std::vector<int> readFromFile(std::string filename) {
    ifstream f(filename);
    vector<int> data;
    int val;
    while (f >> val)
        data.push_back(val);

    return data;
}
