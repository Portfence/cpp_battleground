#pragma once

#include "interface/ICoffeeMachine.h"
#include "util/Configuration.h"
#include "util/CoffeeBean.hpp"
#include "util/CoffeeSelection.hpp"
#include "util/BrewingUnit.hpp"
#include "util/Grinder.hpp"

#include <map>

class PremiumCoffeeMachine : public ICoffeeMachine
{
public:
  explicit PremiumCoffeeMachine(std::map<CoffeeSelection, CoffeeBean>& t_beans);
  ~PremiumCoffeeMachine() = default;
  std::optional<CoffeeDrink> brewCoffee(const CoffeeSelection& selection) override;
  void addCoffee(const CoffeeSelection& sel, const CoffeeBean& newBeans);

private:
  std::map<CoffeeSelection, Configuration> mConfigMap;
  std::map<CoffeeSelection, CoffeeBean> mBeans;
  BrewingUnit mBrewingUnit{};
  Grinder mGrinder{};
};
