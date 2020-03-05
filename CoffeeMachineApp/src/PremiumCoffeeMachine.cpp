#include "PremiumCoffeeMachine.h"
#include "interface/ICoffeeMachine.h"

PremiumCoffeeMachine::PremiumCoffeeMachine(std::map<CoffeeSelection, CoffeeBean>& t_beans)
  : mBeans(t_beans)
{

}

Coffee PremiumCoffeeMachine::brewCoffee(const CoffeeSelection& selection)
{
  switch (selection)
  {
  case CoffeeSelection::ESPRESSO:
    // Code
    break;
  case CoffeeSelection::FILTER_COFFEE:
    // Code
    break;
  default:
    // return nullopt/unexpected
    break;
  }
  return Coffee();
}

Coffee PremiumCoffeeMachine::brewEspresso()
{
  // unimplemented
  return Coffee();
}

Coffee PremiumCoffeeMachine::brewFilterCoffee()
{
  // unimplemented
  return Coffee();
}

