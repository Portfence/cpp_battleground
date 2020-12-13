#pragma once

#include <memory>
class Canvas
{
public:
  Canvas() = default;
};

class Rectangle;

class DrawableRectangle
{
public:
  explicit DrawableRectangle(Rectangle const& rectangle);
  void draw(Canvas& canvas);
private:
  std::unique_ptr<Rectangle> rectangle_;
};
