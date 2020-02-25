/**
 * @file main.cpp
 * @brief Testing strong types
 * @version 0.1
 * @date 2020-02-07
 *
 * @copyright Copyright (c) 2020
 *
 */
#include <iostream>

class Diameter
{
public:
  explicit Diameter(const double & value) : mValue(value) {}
  double get() const { return mValue; }
private:
  double mValue;
};

class Radius
{
public:
  explicit Radius(const double & value) : mValue(value) {}
  double get() const { return mValue; }
private:
  double mValue;
};

class Circle
{
public:
  explicit Circle() = default;
  explicit Circle(const Radius& radius) : mRadius(radius.get()) {}
  explicit Circle(const Diameter& diameter) : mRadius(diameter.get() / 2.0) {}
  double get() const { return mRadius; }
  void set(const Radius& radius) { mRadius = radius.get(); }
  void set(const Diameter& diameter) { mRadius = diameter.get() / 2.0; }
private:
  double mRadius;
};


/**
 * @brief Defines s strong type
 * @details Strong types reinforce interfaces by making them more expressive,
 * especially at call site, and less error-prone by forcing the right order of arguments.
 *  They can be implemented by the following thin wrapper:
 *
 * @tparam T
 */
template <typename T, typename Parameter>
class NamedType
{
public:
  explicit NamedType(const T& value) : mValue(value) {}
  explicit NamedType(T&& value) : mValue(std::move(value)) {}
  T& get() { return mValue; }
  T const& get() const { return mValue; }
private:
  T mValue;
};

using Meter = NamedType<double, struct MeterParameter>;
using Width = NamedType<Meter, struct WidthParameter>;
using Height = NamedType<Meter, struct HeightParameter>;

Meter operator"" _meter(const unsigned long long length)
{
  return Meter(length);
}

Meter operator"" _meter(const long double length)
{
  return Meter(length);
}

class Rectangle
{
public:
  Rectangle(Width s, Height d) :a(s), b(d) {};
  Width a;
  Height b;
private:
};

int main()
{
  {
    Circle a1(Diameter(4.0));
    Circle a2(Radius(3.0));
    Circle a3;
    a3.set(Radius(1.0));
    Circle a4;
    a4.set(Diameter(1.0));
    std::cout << "a1 Radius size: " << a1.get() << " -  a2 Radius size: " << a2.get() << " a3 Radius size: " << a3.get() << " a4 Radius size: " << a4.get() << std::endl;
  }

  Rectangle rect(Width(10_meter), Height(20_meter));
  std::cout << rect.a.get().get() << std::endl;
  return EXIT_SUCCESS;
}
