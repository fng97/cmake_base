/**
 * @file main.cpp
 *
 * @copyright Copyright (c) 2023 fng97
 *
 */

#include <spdlog/spdlog.h>

#include "greeter/greeter.hpp"  // for GetGreeting

int main() {
  spdlog::info(GetGreeting());
  return 0;
}
