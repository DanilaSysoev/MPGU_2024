#pragma once

class TopLevel {
public:
    TopLevel(int iField);
    int getIField() const { return iField; }

private:
    int iField;
};
