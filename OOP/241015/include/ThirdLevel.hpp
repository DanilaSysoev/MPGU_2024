#pragma once
#include "SecondLevelOne.hpp"
#include "SecondLevelTwo.hpp"

class ThirdLevel : public SecondLevelOne,
                   public SecondLevelTwo
{
public:
    ThirdLevel(int iField, float fField, float dField, bool flag);

    bool ifFlag() const { return flag; }

private:
    bool flag;
};
