#include "MyFirstClass.hpp"

MyFirstClass::MyFirstClass(int i, float f, const std::string& s)
{
    iField = i;
    fField = f;
    sField = s;

    std::cout << "called MyFirstClass(int i, float f, std::string s) constructor" << std::endl;
    std::cout << iField << std::endl;
    std::cout << fField << std::endl;
    std::cout << sField << std::endl;
}

void MyFirstClass::printPublic() const
{
    std::cout << "piField = " << piField << std::endl;
    std::cout << "pfField = " << pfField << std::endl;
    std::cout << "psField = " << psField << std::endl;
}

void MyFirstClass::reset(int i, float f, const std::string& s)
{
    iField = i;
    fField = f;
    sField = s;

    std::cout << "called MyFirstClass::update(int i, float f, std::string s) method" << std::endl;
    std::cout << iField << std::endl;
    std::cout << fField << std::endl;
    std::cout << sField << std::endl;
}