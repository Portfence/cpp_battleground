#pragma once

#include "WaterQuantity.hpp"
#include "CoffeeQuantity.hpp"

class Configuration
{
public:
  Configuration(int a, int b, int c){}
  WaterQuantity getQuantityWater()
  {
    WaterQuantity w;
    return w;
  }

  CoffeeQuantity getCoffeeQuantity()
  {
    CoffeeQuantity q;
    return q;
  }
};