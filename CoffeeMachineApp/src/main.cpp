#include "models/BasicCoffeeMachine.h"
#include "models/PremiumCoffeeMachine.h"

#include <plog/Log.h>
#include <plog/Appenders/ConsoleAppender.h>

class CoffeeApp
{
public:
  CoffeeApp(IEspressoMachine& t_coffeeMachine) : mCoffeeMachine(t_coffeeMachine)
  {

  }

  void prepareCoffee()
  {
    std::optional<CoffeeDrink> coffee = mCoffeeMachine.brewEspresso();
    if (coffee)
    {
      PLOGI << "CoffeeDrink is ready!";
    }
  }
private:
  IEspressoMachine& mCoffeeMachine;
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

  app.prepareCoffee();

  return EXIT_SUCCESS;
}
