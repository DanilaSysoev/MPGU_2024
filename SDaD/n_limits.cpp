#include <limits>
#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    cout << "int: " << numeric_limits<int32_t>::max() << endl;
	cout << "float: " << numeric_limits<float>::max() << endl;
	cout << "double: " << numeric_limits<double>::max() << endl;

    return 0;
}
