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
#include <plog/Log.h>
#include <algorithm>
#include <math.h>

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
  std::cout << std::boolalpha << std::endl;
  std::cout << "areNormsCorrect " << areNormsCorrect << std::endl;
  auto vrange =  myPoints | std::views::transform(norm) ;
  // for (const auto & r : vrange)
  // {
  //   std::cout << r << std::endl;
  // }
  // const auto arNC = (vrange == std::vector<double>{5, 10, 15});
  // const auto areMyNormsCorrect = (myPoints | std::ranges::transform(norm)) == std::vector<double>{5, 10, 15};
  // std::cout << std::boolalpha << std::endl;
  // std::cout << "Are My norms correct? : " << areMyNormsCorrect << std::endl;
  // for (const auto & A : myPoints | std::views::reverse)
  // {
  //   std::cout << A.x << " " << A.y << std::endl;
  // }

  auto numbers = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};

  std::ranges::for_each(numbers | std::views::take_while([](int i){ return i <= 5; }), [](int& i){ i *= 10; });

  for(const auto & n : numbers)
  std::cout << n << std::endl;
  return 0;
}

// auto print(const Point& p)
// {
//   std::cout << p.x << " " << p.y << std::endl;
// }

// auto printInt(const int p)
// {
//   std::cout << p << std::endl;
// }

// auto even(int i)
// {
//   return 0 == i % 2;
// }

// int main() {
//   auto numbers = std::vector<int>{1, 2, 3, 4, 5};
//   auto multiplyWithTwo = [](const int val){ return val*2;};
//   auto range = numbers | std::ranges::views::transform(multiplyWithTwo);

//   std::vector<Point> v{Point(0.0, 1.0), Point(2.0, 3.0), Point(4.0, 5.0)};

//   auto rv = numbers | std::views::reverse | std::views::filter(even);
//   std::ranges::for_each(rv , printInt);
//   std::ranges::for_each(range , printInt);
//   // std::ranges::accumulate();

//   // std::ranges::for_each(numbers | std::views::filter(even), printInt);

//   // std:ranges::copy_if()

//   return 0;
// }
