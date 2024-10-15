#include "ThirdLevel.hpp"

ThirdLevel::ThirdLevel(int iField, float fField, float dField, bool flag)
    : TopLevel(iField)
    , SecondLevelOne(iField, fField)
    , SecondLevelTwo(iField, dField)
    , flag(flag)
{}
