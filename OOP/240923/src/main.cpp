#include <iostream>
#include "main.hpp"

using namespace std;

int main()
{
    MyFirstClass mfcVar;  // <-- call default constructor implicitly
    MyFirstClass mfcVar2 = MyFirstClass();  // <-- call default constructor obviously

    MyFirstClass mfcVar3(1, 1.0, "Some string");  // <-- call parametrized constructor implicitly
    MyFirstClass mfcVar4 = MyFirstClass(2, 2.0, "Some string 2");  // <-- call parametrized constructor obviously

    cout << mfcVar.piField << endl;
    cout << mfcVar.pfField << endl;
    cout << mfcVar.psField << endl;

    // cout << mfcVar.iField << endl;  -- no access
    // cout << mfcVar.fField << endl;  -- no access
    // cout << mfcVar.sField << endl;  -- no access

    mfcVar.psField = "Hello";
    cout << mfcVar.psField << endl;

    mfcVar.print();
    mfcVar.printPublic();

    mfcVar.reset(10, 100.0, "New string");
    mfcVar.reset(20, 100.0);
    mfcVar.reset(30);
    mfcVar.reset();

    return 0;
}
