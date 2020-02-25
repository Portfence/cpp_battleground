/**
 * @file main.cpp
 * @brief Testing fmt library with C++20
 * @version 0.1
 * @date 2020-02-18
 *
 *
 */
#include <iostream>
#include <fmt/format.h>

int main()
{
  std::string s = fmt::format(FMT_STRING("{:d}"), 42); // check string format index at compile time
  std::string s2 = fmt::format(FMT_STRING("this string {}, is cool {}"), 42, 43); // check string format index at compile time
  std::cout << s << std::endl;
  std::cout << s2 << std::endl;
  return 0;
}
