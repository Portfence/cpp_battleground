/**
 * @file main.cpp
 * @brief Testing proposed error handling with tl::expected. Also expressive push_back to vector and comparison with rollbear::any_of etc.
 * @version 0.1
 * @date 2020-02-04
 *
 * @copyright Copyright (c) 2020
 *
 */
#include <iostream>
#include <boost/assign/std/vector.hpp>
#include <dry-comparisons.hpp>
#include <optional>
#include <tl/expected.hpp>

#define NUMBER_OF_CHIPS 3
#define NUMBER_OF_CHANNELS 8

using namespace boost::assign;

using rollbear::any_of;
using rollbear::all_of;
using rollbear::none_of;

std::optional<std::string> find_path(uint32_t input)
{
  if (input == 0)
    return std::nullopt;
  else
  {
    return "An address";
  }
}

tl::expected<int, std::string> find_solution(int input)
{
  if (input < 0 )
  {
    return tl::make_unexpected(std::string("No solution"));
  }
  else
  {
    return input;
  }
}

constexpr int multiply_with_two(const int input)
{
  return input*3;
}

constexpr int multiply_with_three(const int input)
{
  return input*3;
}

struct Output{
  int a, b, c;
};
struct Input
{
  int x, y, z;
};
enum Error
{
  UNKNOWN,
  FAILED
};

/**
 * @brief Maybe compute an output
 *
 * @param input data
 * @return tl::expected<Output, Error> Output if successful, Error otherwise
 */
tl::expected<Output, Error> maybe_compute(const Input& input)
{
  if (any_of{input.x, input.y, input.z} < 0)
  {
    return tl::unexpected(Error::FAILED);
  }
  else
  {
    return Output{input.x, input.y, input.z};
  }
}

int main()
{
  { // Expressive push_back to boost::assign operator+ to vector
    std::vector<int> v;

    int offset = 4;
    for (int i = 0; i < NUMBER_OF_CHIPS; i++)
    {
      for (int j = 0; j < NUMBER_OF_CHANNELS; j++)
      {
        v += offset++;
      }
    }

    for (const auto& num : v)
    {
      std::cout << num <<std::endl;
    }
  }

  { // Expressive check of multiple variables with rollbear::any_of, all_of, none_of
    int x = 10;
    int y = 1;
    int z = 5;

    if ((x>0) || (y>0) || (z>0))
    {

    }

    if (any_of{x,y,z} > 0)
    {

    }
  }

  { // tl::expected proposed to std -> std::optional on steroids (returns error type instead of just std::nullopt)
    tl::expected<int, std::string> a;

    std::optional<std::string> output1 = find_path(0);
    std::cout << output1.value_or("gtfo") << std::endl;

    std::optional<std::string> output2 = find_path(1);
    std::cout << output2.value_or("nothing") << std::endl;
    std::optional<std::string> output3 = find_path(1);
    if(output3.has_value())
    std::cout << output3.value() << std::endl;

    Input in;
    tl::expected<Output, Error> out = maybe_compute(in);
  }

  { // tl::expected: map() and_then() performs a series of task and result is valid if all succedes
    auto result = find_solution(12)         // Try to find solution for input argument. Error and return unexpected if it fails.
                  .map(multiply_with_two)   // If successful, pass the returned value as argument to 'multiply_with_two'.
                  .map(multiply_with_three) // Pass returned value from previous function as argument to 'multiply_with_three'.
                  .and_then(find_solution); // Try to find a solution with returned value from previous function. Return result it successfull. Return unexpected otherwise

    // A single error handling case for all function calls above
    if (result)
    {
      std::cout << result.value() << std::endl;
    }
    else
    {
      std::cout << result.error() << std::endl;
    }
  }
  return 0;
}
