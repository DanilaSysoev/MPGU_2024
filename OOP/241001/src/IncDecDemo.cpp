#include "IncDecDemo.hpp"

IncDecDemo& IncDecDemo::operator++() {
    ++val;
    return *this;
}
IncDecDemo& IncDecDemo::operator--() {
    --val;
    return *this;
}

IncDecDemo IncDecDemo::operator++(int) {
    IncDecDemo tmp(val);
    ++val;
    return tmp;
}
IncDecDemo IncDecDemo::operator--(int) {
    IncDecDemo tmp(val);
    --val;
    return tmp;
}
