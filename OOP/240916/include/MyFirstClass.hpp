#include <string>
#include <iostream>

class MyFirstClass
{
    // Class members are located here
private:  // class members are only accessible within the class
    // 1. Fields
    // <type> <name>;
    int iField;
    float fField;
    std::string sField;

public: // class members are accessible everywhere outside the class
    int piField;          // public fields for demonstration. Don't do that!
    float pfField;        // public fields for demonstration. Don't do that!
    std::string psField;  // public fields for demonstration. Don't do that!

    // 2. Constructor
    // <class_name>(<args_lis>);  <-- declaration
    // <full_class_name>::<class_name>(<args_lis>) { <body> }  <-- definition
    MyFirstClass()  // <-- default constructor (constructor without args)
    {
        iField = 10;
        fField = 5.0f;
        sField = "Default constructor";

        std::cout << "called MyFirstClass() constructor" << std::endl;
    }
    MyFirstClass(int i, float f, const std::string& s);
};