#include <iostream>

#include "CreateDestroyWriter.hpp"

CreateDestroyWriter::CreateDestroyWriter() {
    std::cout << "Create object of CreateDestroyWriter!" << std::endl;
}

CreateDestroyWriter::~CreateDestroyWriter() {
    std::cout << "Destroy object of CreateDestroyWriter!" << std::endl;
}
