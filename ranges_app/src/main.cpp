/**
 * @file main.cpp
 * @brief Testing ranges-v3 library with C++20
 * @version 0.1
 * @date 2020-02-07
 *
 *
 */
#include <iostream>

#include <range/v3/view.hpp>

struct Point
{
    double x;
    double y;
};

double norm(const Point& point)
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

  for (const auto & A : myPoints | ranges::view::reverse)
  {
    std::cout << A.x << " " << A.y << std::endl;
  }

  auto numbers = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};

  ranges::view::for_each(numbers | ranges::view::take_while([](int i){ return i <= 5; }), [](int& i){ i *= 10; });
  return 0;
}
