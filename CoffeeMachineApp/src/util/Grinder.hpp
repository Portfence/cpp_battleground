#pragma once

#include "CoffeeBean.hpp"
#include "CoffeeQuantity.hpp"
#include "GroundCoffee.hpp"

class Grinder
{
public:
  GroundCoffee grind(const CoffeeBean& coffeeBean, CoffeeQuantity CoffeeQuantity)
  {
    return GroundCoffee("My favorite...", 10); // unimplemented
  }
};
