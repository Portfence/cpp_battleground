#pragma once

#include "interface/ICoffeeMachine.h"
#include "interface/IEspressoMachine.h"
#include "util/Configuration.h"
#include "util/CoffeeBean.hpp"
#include "util/CoffeeSelection.hpp"
#include "util/BrewingUnit.hpp"
#include "util/Grinder.hpp"

#include <map>

class PremiumCoffeeMachine : public ICoffeeMachine, public IEspressoMachine
{
public:
  explicit PremiumCoffeeMachine(std::map<CoffeeSelection, CoffeeBean>& t_beans);
  ~PremiumCoffeeMachine() = default;
  std::optional<CoffeeDrink> brewFilterCoffee() override;
  std::optional<CoffeeDrink> brewEspresso() override;
  void addCoffee(const CoffeeSelection& sel, const CoffeeBean& newBeans);

private:
  std::optional<CoffeeDrink> brewSelectedCoffee(const CoffeeSelection& selection);

private:
  std::map<CoffeeSelection, Configuration> mConfigMap;
  std::map<CoffeeSelection, CoffeeBean> mBeans;
  BrewingUnit mBrewingUnit{};
  Grinder mGrinder{};
};
