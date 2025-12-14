#pragma once

#include "quantity.hpp"
#include "vector2d.hpp"

struct Body {
  Mass mass;
  Vector2D<Length> position;
  Vector2D<Speed> velocity;

  void Update(Vector2D<Acceleration> a, Time t) {
    position += velocity * t + a * t * t / 2;
    velocity += a * t;
  }
};
