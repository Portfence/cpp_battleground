#pragma once

#include "Coffee.hpp"
#include "GroundCoffee.hpp"
#include "WaterQuantity.hpp"

class BrewingUnit
{
public:
  Coffee brew(CoffeeSelection t_coffeeSelection, GroundCoffee t_groundCoffee, WaterQuantity t_waterQuantity)
  {
    Coffee coffee;
    return coffee;
  }
};