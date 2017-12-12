#include "gtest/gtest.h"
#include "binary_operations.hpp"

TEST(setting_bits, setbiton)
{
   auto res = bopr::setbiton(0x00000000, 1);
   EXPECT_EQ(0x00000002, res);
}

TEST(setting_bits, setbitoff)
{
   auto res = bopr::setbitoff(0xFFFFFFFF, 1);
   EXPECT_EQ(0xFFFFFFFD, res);
}
