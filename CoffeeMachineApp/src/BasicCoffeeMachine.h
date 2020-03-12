#pragma once

#include "interface/IFilterCoffeeMachine.h"
#include "util/CoffeeDrink.hpp"
#include "util/Configuration.h"
#include "util/GroundCoffee.hpp"
#include "util/CoffeeSelection.hpp"
#include "util/BrewingUnit.hpp"

#include <map>

class BasicCoffeeMachine : public IFilterCoffeeMachine
{
public:
  explicit BasicCoffeeMachine(std::map<CoffeeSelection, GroundCoffee>& t_coffee);
  ~BasicCoffeeMachine() = default;
  std::optional<CoffeeDrink> brewFilterCoffee() override;
  void addCoffee(const CoffeeSelection& sel, const GroundCoffee& newCoffee);

private:
  std::map<CoffeeSelection, Configuration> mConfigMap;
  std::map<CoffeeSelection, GroundCoffee> mGroundCoffee;
  BrewingUnit mBrewingUnit{};
};
