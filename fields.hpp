#pragma once

#include "body.hpp"
#include "quantity.hpp"
#include "vector2d.hpp"

struct GravityField {
  Vector2D<Acceleration> g;

  GravityField() = default;

  explicit GravityField(Vector2D<Acceleration> a) : g(a) {};

  Vector2D<Force> GetForce(const Body& body) const {
    return body.mass * g;
  }
};

struct SpringField {
  Vector2D<Length> start;
  Elasticity k;

  SpringField() = default;

  explicit SpringField(Vector2D<Length> start_position, Elasticity k_value) :
      start(start_position), k(k_value) {};

  Vector2D<Force> GetForce(const Body& body) const {
    return -k * (body.position - start);
  }
};

struct FluidFriction {
  Viscosity k;

  FluidFriction() = default;

  explicit FluidFriction(Viscosity viscosity) : k(viscosity) {};
  explicit FluidFriction(const double viscosity) : k(Viscosity{viscosity}) {};

  Vector2D<Force> GetForce(const Body& body) const {
    return -k * body.velocity;
  }
};
