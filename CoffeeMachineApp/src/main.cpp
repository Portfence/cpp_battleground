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

  Coffee prepareCoffee(const CoffeeSelection& selection)
  {
    Coffee coffee = mCoffeeMachine.brewCoffee(selection);
    PLOGI << "Coffee is ready!";
    return coffee;
  }
private:
  ICoffeeMachine& mCoffeeMachine;
};

int main(int argc, char ** argv)
{
  static plog::ConsoleAppender<plog::TxtFormatter> consoleAppender;
  plog::init(plog::debug, "").addAppender(&consoleAppender);

  PLOGI << "Starting CoffeeMachineApp";
  // auto beans = std::map<CoffeeSelection, GroundCoffee>{ {CoffeeSelection::FILTER_COFFEE, GroundCoffee("My favorite filter coffee bean", 1000)} };
  auto beans = std::map<CoffeeSelection, CoffeeBean>{ {CoffeeSelection::FILTER_COFFEE, CoffeeBean("My favorite filter coffee bean", 1000)} };

  // BasicCoffeeMachine machine(beans);
  PremiumCoffeeMachine machine(beans);

  CoffeeApp app(machine);

  app.prepareCoffee(CoffeeSelection::FILTER_COFFEE);

  return EXIT_SUCCESS;
}
