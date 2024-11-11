#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }

    std::ifstream fin(argv[1]);
    if(!fin) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(fin, line, ' ')) {
        std::cout << line << " * ";
    }

    fin.close();

    return 0;
}
