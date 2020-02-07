/**
 * @file main.cpp
 * @brief Testing ranges-v3 library with C++20
 * @version 0.1
 * @date 2020-02-07
 *
 * @copyright Copyright (c) 2020
 *
 */
#include <iostream>

#include <range/v3/view.hpp>

struct Point
{
    double x;
    double y;
};

double norm(Point const& point)
{
    return sqrt(point.x * point.x + point.y * point.y);
}

int main()
{
  const auto myPoints = std::vector<Point>{ {3,4}, {6,8}, {9,12} };
  auto myNorms = std::vector<double>{};
  std::transform(std::begin(myPoints), std::end(myPoints), std::back_inserter(myNorms), norm);
  const auto areNormsCorrect = myNorms == std::vector<double>{5, 10, 15};

  const auto areMyNormsCorrect = (myPoints | ranges::view::transform(norm) | ranges::to_vector) == std::vector<double>{5, 10, 15};
  return 0;
}
