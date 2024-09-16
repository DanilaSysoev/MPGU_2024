#include <iostream>
#include <gtest/gtest.h>
#include "square_equation_tests.hpp"


using namespace std;


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
