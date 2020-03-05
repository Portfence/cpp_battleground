#include "BasicCoffeeMachine.h"


#include <map>

BasicCoffeeMachine::BasicCoffeeMachine(std::map<CoffeeSelection, GroundCoffee>& t_coffee)
  : mGroundCoffee(t_coffee)
{
  mConfigMap.insert(std::pair<CoffeeSelection, Configuration>(CoffeeSelection::FILTER_COFFEE, Configuration(30, 48, 0)));
}

Coffee BasicCoffeeMachine::brewCoffee(const CoffeeSelection& selection)
{
  auto it1 = mConfigMap.find(selection);
  Configuration config = it1->second;
  auto it2 = mGroundCoffee.find(selection);
  GroundCoffee groundCoffee = it2->second;
  return mBrewingUnit.brew(selection, groundCoffee, config.getQuantityWater());
}
