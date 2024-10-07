#pragma once

class NumberService {
private:
    int number;
public:
    explicit NumberService(int number);

    int getNumber() const { return number; }
    void setNumber(int number) { this->number = number; }

    void add(int number);
    void sub(int number);
    void mul(int number);
    void div(int number);

    void print() const;
};
