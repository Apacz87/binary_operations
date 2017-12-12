#include "gtest/gtest.h"
#include "binary_operations.hpp"

TEST(bit_state, bitstate)
{
   EXPECT_TRUE(bopr::bitstate(0x0FDA0910, 8));
   EXPECT_FALSE(bopr::bitstate(0x0FDA0910, 16));
}
