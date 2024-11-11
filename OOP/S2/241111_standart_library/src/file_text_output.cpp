#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
    if(argc != 3) {
        std::cout << "Usage: " << argv[0] << " <output file> <text>" << std::endl;
        return 1;
    }

    std::ofstream fout(argv[1]);
    if(!fout) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    fout << argv[2] << std::endl;

    fout.close();


    std::ofstream fout_a(argv[1], std::ios_base::app);
    if(!fout_a) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    fout_a << argv[2] << std::endl;

    fout_a.close();

    return 0;
}