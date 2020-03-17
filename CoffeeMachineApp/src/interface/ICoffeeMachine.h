#pragma once

#include "util/CoffeeDrink.hpp"

#include <optional>

class ICoffeeMachine
{
public:
  virtual ~ICoffeeMachine() = default;
  virtual std::optional<CoffeeDrink> brewFilterCoffee() = 0;
};
