#include "PremiumCoffeeMachine.h"
#include "helper/try_find.hpp"

#include <plog/Log.h>
#include <dry-comparisons/dry-comparisons.hpp>

using rollbear::all_of;

PremiumCoffeeMachine::PremiumCoffeeMachine(std::map<CoffeeSelection, CoffeeBean>& t_beans)
  : mBeans(t_beans)
{
  mConfigMap.insert(std::pair<CoffeeSelection, Configuration>(CoffeeSelection::FILTER_COFFEE, Configuration(30, 48, 0)));
  mConfigMap.insert(std::pair<CoffeeSelection, Configuration>(CoffeeSelection::ESPRESSO, Configuration(30, 48, 0)));
}

std::optional<CoffeeDrink> PremiumCoffeeMachine::brewFilterCoffee()
{
  return brewSelectedCoffee(CoffeeSelection::FILTER_COFFEE);
}

std::optional<CoffeeDrink> PremiumCoffeeMachine::brewEspresso()
{
  return brewSelectedCoffee(CoffeeSelection::ESPRESSO);
}

void PremiumCoffeeMachine::addCoffee(const CoffeeSelection& sel, const CoffeeBean& newBeans)
{

  if (auto it = mBeans.find(sel); it != mBeans.end())
  {
    CoffeeBean& existingBeans = it->second;
    if (existingBeans.getName() == newBeans.getName())
    {
      existingBeans.setQuantity(existingBeans.getQuantity() + newBeans.getQuantity());
    }
    else
    {
      throw std::invalid_argument("Only one kind of coffee supported for each CoffeeSelection");
    }
  }
  else
  {
    mBeans.insert(std::pair<CoffeeSelection, CoffeeBean>(sel, newBeans));
  }
}

std::optional<CoffeeDrink> PremiumCoffeeMachine::brewSelectedCoffee(const CoffeeSelection& selection)
{
  std::optional<Configuration> config = helper::try_find(selection, mConfigMap);

  std::optional<CoffeeBean> coffeeBean = helper::try_find(selection, mBeans);

  if (config && coffeeBean)
  {
    GroundCoffee groundCoffee = mGrinder.grind(coffeeBean.value(), config.value().getCoffeeQuantity());

    return mBrewingUnit.brew(selection, groundCoffee, config.value().getQuantityWater());
  }
  return std::nullopt;
}
