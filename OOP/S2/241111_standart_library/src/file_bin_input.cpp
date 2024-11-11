#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }

    std::ifstream fin(argv[1], std::ios_base::binary);
    if(!fin) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    char data[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
    while (fin.read(data, 8)) {
        std::cout << data << std::endl;
    }
    std::cout << data << std::endl;

    fin.close();

    return 0;
}
