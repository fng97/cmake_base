/**
 * @file greeter.cpp
 *
 * @copyright Copyright (c) 2023 fng97
 *
 */

#include "greeter/greeter.hpp"  // for GetGreeting

#include <fmt/core.h>  // for fmt::format

#include <string>  // for std::string

std::string GetGreeting() { return fmt::format("{}, {}!\n", "Hello", "world"); }
