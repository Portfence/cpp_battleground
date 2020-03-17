#include "BasicCoffeeMachine.h"
#include "helper/try_find.hpp"

#include <plog/Log.h>
#include <dry-comparisons.hpp>
#include <optional>

using rollbear::all_of;

BasicCoffeeMachine::BasicCoffeeMachine(std::map<CoffeeSelection, GroundCoffee>& t_coffee)
 : mGroundCoffee(t_coffee)
{
  mConfigMap.insert(std::pair<CoffeeSelection, Configuration>(CoffeeSelection::FILTER_COFFEE, Configuration(30, 48, 0)));
}

std::optional<CoffeeDrink> BasicCoffeeMachine::brewFilterCoffee()
{
  std::optional<Configuration> config = helper::try_find(CoffeeSelection::FILTER_COFFEE, mConfigMap);

  std::optional<GroundCoffee> groundCoffee = helper::try_find(CoffeeSelection::FILTER_COFFEE, mGroundCoffee);

  if (all_of{config.has_value(), groundCoffee.has_value()})
  {
    return mBrewingUnit.brew(CoffeeSelection::FILTER_COFFEE, groundCoffee.value(), config.value().getQuantityWater());
  }
  return std::nullopt;
}

void BasicCoffeeMachine::addCoffee(const CoffeeSelection& sel, const GroundCoffee& newCoffee)
{
  if (auto it = mGroundCoffee.find(sel); it != mGroundCoffee.end())
  {
    GroundCoffee& existingCoffee = it->second;
    if (existingCoffee.getName() == newCoffee.getName())
    {
      existingCoffee.setQuantity(existingCoffee.getQuantity() + newCoffee.getQuantity());
    }
    else
    {
      throw std::invalid_argument("Only one kind of coffee supported for each CoffeeSelection");
    }
  }
  else
  {
    mGroundCoffee.insert(std::pair<CoffeeSelection, GroundCoffee>(sel, newCoffee));
  }
}
