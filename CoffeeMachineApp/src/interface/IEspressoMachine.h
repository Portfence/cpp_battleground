#pragma once

#include "util/CoffeeDrink.hpp"

#include <optional>

class IEspressoMachine
{
public:
  virtual ~IEspressoMachine() = default;
  virtual std::optional<CoffeeDrink> brewEspresso() = 0;
};
