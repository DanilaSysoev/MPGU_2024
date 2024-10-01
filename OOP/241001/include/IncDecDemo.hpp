#pragma once
#ifndef INC_DEC_DEMO_HPP
#define INC_DEC_DEMO_HPP

class IncDecDemo
{
public:
    IncDecDemo(int val) : val(val) {}
    IncDecDemo& operator++();
    IncDecDemo& operator--();

    IncDecDemo operator++(int dummy);
    IncDecDemo operator--(int dummy);

private:
    int val;
};

#endif
