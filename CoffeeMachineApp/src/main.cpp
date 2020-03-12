#include "BasicCoffeeMachine.h"
#include "PremiumCoffeeMachine.h"

#include <plog/Log.h>
#include <plog/Appenders/ConsoleAppender.h>

class CoffeeApp
{
public:
  CoffeeApp(ICoffeeMachine& t_coffeeMachine) : mCoffeeMachine(t_coffeeMachine)
  {

  }

  std::optional<CoffeeDrink> prepareCoffee(const CoffeeSelection& selection)
  {
    std::optional<CoffeeDrink> coffee = mCoffeeMachine.brewCoffee(selection);
    if (coffee)
    {
      PLOGI << "CoffeeDrink is ready!";
      return coffee;
    }
    return std::nullopt;
  }
private:
  ICoffeeMachine& mCoffeeMachine;
};

int main(int argc, char ** argv)
{
  static plog::ConsoleAppender<plog::TxtFormatter> consoleAppender;
  plog::init(plog::debug, "").addAppender(&consoleAppender);

  PLOGI << "Starting CoffeeMachineApp";
  // auto groundCoffee = std::map<CoffeeSelection, GroundCoffee>{ {CoffeeSelection::FILTER_COFFEE, GroundCoffee("My favorite filter coffee bean", 1000)} };
  auto beans = std::map<CoffeeSelection, CoffeeBean>{ {CoffeeSelection::FILTER_COFFEE, CoffeeBean("My favorite filter coffee bean", 1000)},
                                                      {CoffeeSelection::ESPRESSO, CoffeeBean("My favorite espresso coffee bean", 1000)} };

  // BasicCoffeeMachine machine(groundCoffee);
  PremiumCoffeeMachine machine(beans);

  CoffeeApp app(machine);

  app.prepareCoffee(CoffeeSelection::FILTER_COFFEE);

  return EXIT_SUCCESS;
}
