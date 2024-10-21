#include <vector>
#include <iostream>
#include <cmath>
#include "main.hpp"

using namespace std;

int main()
{
    Student s("Name of student", 21, 2023, 2.5f);
    cout << (s.getName() == "Name of student") << endl
         << (s.getAge() == 21) << endl
         << (s.getYear() == 2023) << endl
         << (s.getMeanPoints() == 2.5f) << endl;

    const Student s2("Name of student 2", 22, 2021, 4.0f);
    cout << (s2.getName() == "Name of student 2") << endl
         << (s2.getAge() == 22) << endl
         << (s2.getYear() == 2021) << endl
         << (s2.getMeanPoints() == 4.0f) << endl;

    return 0;
}
