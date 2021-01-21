/**
 * @file main.cpp
 * @brief Changing key in a map
 * @version 0.1
 * @date 2020-04-25
 *
 *
 */
#include <iostream>
#include <map>
#include <concepts>

template <class T>
concept SignedIntegral = std::is_integral_v<T> && std::is_signed_v<T>;

template <SignedIntegral T>
void signedIntsOnly(T val)
{

}

#include "DrawableRectangle.h"
int main()
{
  // std::map<std::string, int> myMap{ {"one", 1}, {"two", 2}, {"three", 3} };

  // const auto node = myMap.extract("one");
  // if (!node.empty())
  // {
  //   node.key() = "uno";
  //   myMap.insert(std::move(node));
  // }
  // Rectangle r;
  // DrawableRectangle dr(r);
  // Canvas c;
  // dr.draw(c);
}
