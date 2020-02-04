#include <iostream>
#include <vector>
#include <algorithm>
// #include <ranges>

class Material {
public:
  double getMaxPressure() const {
    return 10.0;
  }
};

class Product {
public:
  double getDensity() const {
    return 5.0;
  }
};

class Box {
public:
  double getVolume() const {
    return 1.0;
  }

  double getSidesSurface() const {
    return 5.0;
  }

  Material getMaterial() const {
    return material_;
  }
private:
  Material material_;
};

class Resists {
public:
  explicit Resists(const Product& product) : product_(product) {}
  bool operator()(const Box& box) {
    const double volume = box.getVolume();
    const double weight = volume * product_.getDensity();
    const double sidesSurface = box.getSidesSurface();
    const double pressure = weight / sidesSurface;
    const double maxPressure = box.getMaterial().getMaxPressure();
    return pressure <= maxPressure;
  }
private:
  Product product_;
};

auto resists(const Product& product)
{
  return [product](const Box& box)
  {
    const double volume = box.getVolume();
    const double weight = volume * product.getDensity();
    const double sidesSurface = box.getSidesSurface();
    const double pressure = weight / sidesSurface;
    const double maxPressure = box.getMaterial().getMaxPressure();
    return pressure <= maxPressure;
  };
}

int main()
{
  Product product;
  std::vector<Box> boxes;

  std::vector<Box> goodBoxes;
  std::copy_if(boxes.begin(), boxes.end(), std::back_inserter(goodBoxes), resists(product));

  // range STL iterator
  // auto goodBoxes = boxes | ranges::view::filter(resists(product));

  return 0;
}
