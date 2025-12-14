#include "../quantity.hpp"
#include <gtest/gtest.h>

#ifdef TEST_QUANTITY_CONSTRUCT
TEST(Quantity, Construct) {
  Time t{5.0};
  Length l{3.0};
  Mass m{2.0};
  EXPECT_DOUBLE_EQ(t.value, 5.0);
  EXPECT_DOUBLE_EQ(l.value, 3.0);
  EXPECT_DOUBLE_EQ(m.value, 2.0);
}
#endif

#ifdef TEST_QUANTITY_ADD_SUB
TEST(Quantity, AddSameDimension) {
  Length a{5.0}, b{3.0};
  auto c = a + b;
  EXPECT_DOUBLE_EQ(c.value, 8.0);
}

TEST(Quantity, SubSameDimension) {
  Mass a{5.0}, b{3.0};
  auto c = a - b;
  EXPECT_DOUBLE_EQ(c.value, 2.0);
}

TEST(Quantity, AddAssignSameDimension) {
  Time a{5.0}, b{3.0};
  a += b;
  EXPECT_DOUBLE_EQ(a.value, 8.0);
}

TEST(Quantity, SubAssignSameDimension) {
  Time a{5.0}, b{2.0};
  a -= b;
  EXPECT_DOUBLE_EQ(a.value, 3.0);
}
#endif

#ifdef TEST_QUANTITY_UNARY
TEST(Quantity, UnaryPlus) {
  Length l{5.0};
  auto r = +l;
  EXPECT_DOUBLE_EQ(r.value, 5.0);
}

TEST(Quantity, UnaryMinus) {
  Mass m{5.0};
  auto r = -m;
  EXPECT_DOUBLE_EQ(r.value, -5.0);
}
#endif

#ifdef TEST_QUANTITY_DIM_MUL_DIV
TEST(Quantity, MultiplyDims) {
  Length l{10.0};
  Time t{2.0};
  auto speed = l / t;
  EXPECT_DOUBLE_EQ(speed.value, 5.0);
}

TEST(Quantity, MultiplyDimsComplex) {
  Speed v{4.0};
  Time t{3.0};
  auto l = v * t;
  EXPECT_DOUBLE_EQ(l.value, 12.0);
}

TEST(Quantity, DivideDims) {
  Force f{20.0};
  Acceleration a{10.0};
  auto m = f / a;
  EXPECT_DOUBLE_EQ(m.value, 2.0);
}
#endif

#ifdef TEST_QUANTITY_SCALAR_OPS
TEST(Quantity, MultiplyScalar) {
  Length l{3.0};
  auto r = l * 2.0;
  EXPECT_DOUBLE_EQ(r.value, 6.0);
}

TEST(Quantity, DivideScalar) {
  Time t{10.0};
  auto r = t / 2.0;
  EXPECT_DOUBLE_EQ(r.value, 5.0);
}

TEST(Quantity, MultiplyAssignScalar) {
  Mass m{4.0};
  m *= 3.0;
  EXPECT_DOUBLE_EQ(m.value, 12.0);
}

TEST(Quantity, DivideAssignScalar) {
  Speed s{8.0};
  s /= 2.0;
  EXPECT_DOUBLE_EQ(s.value, 4.0);
}
#endif

#ifdef TEST_QUANTITY_COMPARISONS
TEST(Quantity, Comparisons) {
  Length a{5.0}, b{5.0}, c{7.0};
  EXPECT_TRUE(a == b);
  EXPECT_FALSE(a == c);
  EXPECT_TRUE(c > a);
  EXPECT_TRUE(a < c);
  EXPECT_TRUE(c >= b);
  EXPECT_TRUE(a <= b);
}
#endif

#ifdef TEST_QUANTITY_COMPILETIME
TEST(QuantityCompile, SpeedType) {
  Length l{10.0};
  Time t{2.0};
  Speed v = l / t;
  (void)v;
}

TEST(QuantityCompile, ForceType) {
  Mass m{5.0};
  Acceleration a{2.0};
  Force f = m * a;
  (void)f;
}

TEST(QuantityCompile, EnergyType) {
  Force f{10.0};
  Length l{3.0};
  Energy e = f * l;
  (void)e;
}
#endif

#ifdef TEST_QUANTITY_LITERALS
TEST(QuantityLiterals, LengthLiteral) {
  auto l = 5.0_m;
  EXPECT_DOUBLE_EQ(l.value, 5.0);
}

TEST(QuantityLiterals, TimeLiteral) {
  auto t = 3.0_s;
  EXPECT_DOUBLE_EQ(t.value, 3.0);
}

TEST(QuantityLiterals, MassLiteral) {
  auto m = 7.0_kg;
  EXPECT_DOUBLE_EQ(m.value, 7.0);
}

TEST(QuantityLiterals, SpeedLiteral) {
  auto s = 10.0_mps;
  EXPECT_DOUBLE_EQ(s.value, 10.0);
}

TEST(QuantityLiterals, AccLiteral) {
  auto a = 9.8_mps2;
  EXPECT_DOUBLE_EQ(a.value, 9.8);
}

TEST(QuantityLiterals, ForceLiteral) {
  auto f = 10.0_N;
  EXPECT_DOUBLE_EQ(f.value, 10.0);
}

TEST(QuantityLiterals, EnergyLiteral) {
  auto e = 100.0_J;
  EXPECT_DOUBLE_EQ(e.value, 100.0);
}
#endif
