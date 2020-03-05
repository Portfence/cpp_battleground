#pragma once

#include "Coffee.hpp"
#include "CoffeeSelection.hpp"

class ICoffeeMachine
{
public:
  virtual ~ICoffeeMachine() = default;
  virtual Coffee brewCoffee(const CoffeeSelection& selection) = 0;
};