#pragma once
#include "ICoffeeMachine.h"
#include "CoffeeDrink.hpp"
#include "CoffeeSelection.hpp"

#include <optional>

class IFilterCoffeeMachine : public ICoffeeMachine
{
public:
  virtual ~IFilterCoffeeMachine() = default;
  virtual std::optional<CoffeeDrink> brewFilterCoffee() = 0;
};
