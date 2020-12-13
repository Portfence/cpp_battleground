/**
 * @file main.cpp
 * @brief Testing std::ranges C++20
 * @version 0.1
 * @date 2020-02-07
 *
 *
 */
#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>

struct Point
{
    double x;
    double y;
};

// double norm(const Point& point)
// {
//     return sqrt(point.x * point.x + point.y * point.y);
// }

// int main()
// {
//   const auto myPoints = std::vector<Point>{ {3,4}, {6,8}, {9,12} };
//   auto myNorms = std::vector<double>{};
//   std::transform(std::begin(myPoints), std::end(myPoints), std::back_inserter(myNorms), norm);
//   const auto areNormsCorrect = myNorms == std::vector<double>{5, 10, 15};

//   const auto areMyNormsCorrect = (myPoints | std::view::transform(norm) | std::view::to_vector) == std::vector<double>{5, 10, 15};

//   for (const auto & A : myPoints | std::view::reverse)
//   {
//     std::cout << A.x << " " << A.y << std::endl;
//   }

//   auto numbers = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};

//   std::view::for_each(numbers | std::view::take_while([](int i){ return i <= 5; }), [](int& i){ i *= 10; });
//   return 0;
// }

int main() {
  const auto myPoints = std::vector<Point>{ {3,4}, {6,8}, {9,12} };
  for (const auto & A : myPoints | std::views::reverse)
  {
    std::cout << A.x << " " << A.y << std::endl;
  }
  return 0;
}
