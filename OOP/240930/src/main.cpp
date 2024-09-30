#include <iostream>

#include "main.hpp"

using namespace std;

void StaicFieldInCreationOfObjects() {
    StaticDemo sd1;
    cout << "Created sd1. createdObjectsCount = "
         << sd1.getCreatedObjectsCount() << endl;

    StaticDemo sd2;
    cout << "Created sd2. createdObjectsCount = "
         << StaticDemo::getCreatedObjectsCount() << endl;

    {
        StaticDemo sd3;
        cout << "Created sd3. createdObjectsCount = "
            << sd3.getCreatedObjectsCount() << endl;
    }

    cout << "destroyedObjectsCount = " << StaticDemo::getDestroyedObjectsCount() << endl;
}

void AreaOfVisibilityDemo() {
    cout << "Top level block start" << endl;

    CreateDestroyWriter cdw1;

    {
        cout << "Inner block start" << endl;

        CreateDestroyWriter cdw2;

        cout << "Inner block end" << endl;
    }

    cout << "Top level block end" << endl;
}

int NameHidingDemo() {
    /*
        Given n arrays of size 5.
        Select the maximal element among them.
    */
    
    const int SIZE = 5;
    int n;
    cin >> n;
    int max = 0;

    for (int i = 0; i < n; i++) {      // <----------------+
        int a[SIZE] = { 0 };           //                  |
        for(int j = 0; j < SIZE; j++)  //                  |
            cin >> a[j];               //                  |
                                       //                  |
        for (int i = 0; i < SIZE; ++i) // <- i hides that -+
            if (a[i] > max)
                max = a[i];
    }

    return max;
}

int main() {
    StaicFieldInCreationOfObjects();

    return 0;
}
