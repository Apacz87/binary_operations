#include "gtest/gtest.h"
#include "binary_operations.hpp"

TEST(binary_operations, setbiton)
{
   auto res = bopr::setbiton(0x00000000, 1);
   EXPECT_EQ(0x00000002, res);
}

TEST(binary_operations, setbitoff)
{
   auto res = bopr::setbitoff(0xFFFFFFFF, 1);
   EXPECT_EQ(0xFFFFFFFD, res);
}
