#pragma once

#include "CoffeeDrink.hpp"
#include "GroundCoffee.hpp"
#include "WaterQuantity.hpp"

class BrewingUnit
{
public:
  CoffeeDrink brew(CoffeeSelection t_coffeeSelection, GroundCoffee t_groundCoffee, WaterQuantity t_waterQuantity)
  {
    CoffeeDrink coffee;
    return coffee;
  }
};
