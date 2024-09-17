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


    // 3. Methods
    // <type> <class_name>::<method_name>(<args_lis>)  <-- declaration
    // <type> <full_class_name>::<method_name>(<args_lis>) { <body> }  <-- definition
    void print() const
    {
        std::cout << "iField = " << iField << std::endl;
        std::cout << "fField = " << fField << std::endl;
        std::cout << "sField = " << sField << std::endl;
    }

    void printPublic() const;

    int getIField() const;
    float getFField() const       { return fField; }  // <-- inline
    std::string getSField() const { return sField; }  // <-- inline

    void setIField(int i)                { iField = i; }  // <-- inline
    void setFField(float f)              { fField = f; }  // <-- inline
    void setSField(const std::string& s) { sField = s; }  // <-- inline

    void reset(int i = 0, float f = 0.0, const std::string& s = "");
};

int inline MyFirstClass::getIField() const { return iField; }
