#pragma once

#include <string>

class Student {
private:
    std::string name;
    int age;
    int year;
    float mean_points;

public:
    Student(const std::string& name, int age, int year, float mean_points);
    std::string getName() const { return name; }
    int getAge() const { return age; }
    int getYear() const { return year; }
    float getMeanPoints() const { return mean_points; }
};
