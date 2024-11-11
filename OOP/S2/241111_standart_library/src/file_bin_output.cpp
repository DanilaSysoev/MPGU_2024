#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout << "Usage: " << argv[0] << " <output file>" << std::endl;
        return 1;
    }

    std::ofstream fout(argv[1], std::ios_base::binary);
    if(!fout) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    char data[] = "Hello world\r\n";

    fout.write(data, sizeof(data));

    fout.close();

    return 0;
}
