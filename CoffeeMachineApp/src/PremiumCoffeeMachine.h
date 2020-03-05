#pragma once

#include "interface/ICoffeeMachine.h"
#include "util/CoffeeBean.hpp"
#include "util/CoffeeSelection.hpp"

#include <map>

class PremiumCoffeeMachine : public ICoffeeMachine
{
public:
  PremiumCoffeeMachine(std::map<CoffeeSelection, CoffeeBean>& t_beans);
  ~PremiumCoffeeMachine() = default;
  Coffee brewCoffee(const CoffeeSelection& selection) override;
private:
  Coffee brewEspresso();
  Coffee brewFilterCoffee();

private:
  std::map<CoffeeSelection, CoffeeBean> mBeans;
};
