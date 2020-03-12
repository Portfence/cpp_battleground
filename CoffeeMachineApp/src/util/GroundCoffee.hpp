#pragma once

#include <string>

class GroundCoffee
{
public:
  GroundCoffee(const std::string& details, int quantity) : mDetails(details) {}
  std::string getName() const { return mDetails; }
  void setQuantity(int newQuantity) {}
  int getQuantity() const { return 5; }
private:
  std::string mDetails;
};
