#pragma once

#include "CoffeeDrink.hpp"
#include "CoffeeSelection.hpp"

#include <optional>

class ICoffeeMachine
{
public:
  virtual ~ICoffeeMachine() = default;
  virtual std::optional<CoffeeDrink> brewCoffee(const CoffeeSelection& selection) = 0;
};