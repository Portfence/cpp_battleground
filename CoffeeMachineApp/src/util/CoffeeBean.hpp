#pragma once

#include <string>

class CoffeeBean
{
public:
  CoffeeBean(const std::string& description, int quantity) {}
  std::string getName() const { return "Name"; }
  void setQuantity(int newQuantity) {}
  int getQuantity() const { return 5; }
};
