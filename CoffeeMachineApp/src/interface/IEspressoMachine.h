#pragma once
#include "ICoffeeMachine.h"
#include "CoffeeDrink.hpp"
#include "CoffeeSelection.hpp"

#include <optional>

class IEspressoMachine : public ICoffeeMachine
{
public:
  virtual ~IEspressoMachine() = default;
  virtual std::optional<CoffeeDrink> brewEspresso() = 0;
};
