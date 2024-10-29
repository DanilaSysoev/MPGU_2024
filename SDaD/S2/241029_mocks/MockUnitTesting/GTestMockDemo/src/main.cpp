#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "main.hpp"


using namespace std;


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);

  return RUN_ALL_TESTS();
}
