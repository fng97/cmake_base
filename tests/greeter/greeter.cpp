/**
 * @file greeter.cpp
 *
 * @copyright Copyright (c) 2023 fng97
 *
 */

#include "greeter/greeter.hpp"  // for GetGreeting

#include <gtest/gtest.h>

TEST(Greeter, GreetingIsHelloWorld) {
  EXPECT_STREQ("Hello, world!\n", GetGreeting().c_str());
}
