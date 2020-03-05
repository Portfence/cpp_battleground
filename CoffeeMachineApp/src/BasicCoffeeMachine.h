#include "interface/ICoffeeMachine.h"
#include "util/Coffee.hpp"
#include "util/Configuration.h"
#include "util/GroundCoffee.hpp"
#include "util/CoffeeSelection.hpp"
#include "util/BrewingUnit.hpp"

#include <map>

class BasicCoffeeMachine : public ICoffeeMachine
{
public:
  BasicCoffeeMachine(std::map<CoffeeSelection, GroundCoffee>& t_coffee);
  Coffee brewCoffee(const CoffeeSelection& selection) override;

private:
  std::map<CoffeeSelection, Configuration> mConfigMap;
  std::map<CoffeeSelection, GroundCoffee> mGroundCoffee;
  BrewingUnit mBrewingUnit{};
};
