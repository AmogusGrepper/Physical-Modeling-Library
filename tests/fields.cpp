#include "../fields.hpp"

#include <gtest/gtest.h>

#include "../body.hpp"

#ifdef TEST_BODY_CONSTRUCT
TEST(Body, Construct) {
  Body b;
  b.mass = Mass{2.0};
  b.position = {Length{1.0}, Length{2.0}};
  b.velocity = {Speed{3.0}, Speed{4.0}};

  EXPECT_DOUBLE_EQ(b.mass.value, 2.0);
  EXPECT_DOUBLE_EQ(b.position.x.value, 1.0);
  EXPECT_DOUBLE_EQ(b.position.y.value, 2.0);
  EXPECT_DOUBLE_EQ(b.velocity.x.value, 3.0);
  EXPECT_DOUBLE_EQ(b.velocity.y.value, 4.0);
}
#endif

#ifdef TEST_BODY_UPDATE
TEST(Body, UpdatePositionVelocity) {
  Body b;
  b.mass = Mass{1.0};
  b.position = {Length{0.0}, Length{0.0}};
  b.velocity = {Speed{1.0}, Speed{0.0}};

  Vector2D<Acceleration> a{Acceleration{2.0}, Acceleration{1.0}};
  Time dt{2.0};

  b.Update(a, dt);

  // Δr = v*dt + a*dt*dt/2
  EXPECT_DOUBLE_EQ(b.position.x.value, 1.0 * 2.0 + 2.0 * 2.0 * 2.0 / 2.0);  // 6
  EXPECT_DOUBLE_EQ(b.position.y.value, 0.0 * 2.0 + 1.0 * 2.0 * 2.0 / 2.0);  // 2

  // Δv = a*dt
  EXPECT_DOUBLE_EQ(b.velocity.x.value, 1.0 + 2.0 * 2.0);  // 5
  EXPECT_DOUBLE_EQ(b.velocity.y.value, 0.0 + 1.0 * 2.0);  // 2
}
#endif

#ifdef TEST_GRAVITY_FIELD
TEST(GravityField, DefaultAndCustom) {
  GravityField g1;
  EXPECT_DOUBLE_EQ(g1.g.x.value, 0.0);
  EXPECT_DOUBLE_EQ(g1.g.y.value, 0.0);

  GravityField g2{
      Vector2D<Acceleration>{Acceleration{0.0}, Acceleration{-9.8}}};
  Body b;
  b.mass = Mass{2.0};
  auto f = g2.GetForce(b);
  EXPECT_DOUBLE_EQ(f.x.value, 0.0);
  EXPECT_DOUBLE_EQ(f.y.value, -19.6);  // F = mg
}
#endif

#ifdef TEST_SPRING_FIELD
TEST(SpringField, DefaultAndHook) {
  SpringField s1;
  EXPECT_DOUBLE_EQ(s1.k.value, 0.0);

  SpringField s2{Vector2D<Length>{Length{0.0}, Length{0.0}}, Elasticity{10.0}};
  Body b;
  b.position = {Length{1.0}, Length{2.0}};
  auto f = s2.GetForce(b);
  EXPECT_DOUBLE_EQ(f.x.value, -10.0);  // -k*(x - 0)
  EXPECT_DOUBLE_EQ(f.y.value, -20.0);  // -k*(y - 0)
}
#endif

#ifdef TEST_FLUID_FRICTION
TEST(FluidFriction, DefaultAndCustom) {
  FluidFriction f1;
  Body b;
  b.velocity = {Speed{3.0}, Speed{-4.0}};
  auto force1 = f1.GetForce(b);
  EXPECT_DOUBLE_EQ(force1.x.value, 0.0);
  EXPECT_DOUBLE_EQ(force1.y.value, 0.0);

  FluidFriction f2{Viscosity{2.0}};
  auto force2 = f2.GetForce(b);
  EXPECT_DOUBLE_EQ(force2.x.value, -6.0);  // -k*v.x
  EXPECT_DOUBLE_EQ(force2.y.value, 8.0);   // -k*v.y
}
#endif
