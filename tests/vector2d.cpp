#include "../vector2d.hpp"
#include <gtest/gtest.h>

#ifdef TEST_VECTOR2D_CONSTRUCT
TEST(Vector2D, Construct) {
  Vector2D<int> v{1, 2};
  EXPECT_EQ(v.x, 1);
  EXPECT_EQ(v.y, 2);
}
#endif

#ifdef TEST_VECTOR2D_ADD_SUB
TEST(Vector2D, AddSameType) {
  Vector2D<double> a{1.0, 2.0};
  Vector2D<double> b{3.0, 4.0};
  auto c = a + b;
  EXPECT_DOUBLE_EQ(c.x, 4.0);
  EXPECT_DOUBLE_EQ(c.y, 6.0);
}

TEST(Vector2D, SubSameType) {
  Vector2D<double> a{5.0, 7.0};
  Vector2D<double> b{2.0, 3.0};
  auto c = a - b;
  EXPECT_DOUBLE_EQ(c.x, 3.0);
  EXPECT_DOUBLE_EQ(c.y, 4.0);
}

TEST(Vector2D, AddAssign) {
  Vector2D<int> a{1, 2};
  Vector2D<int> b{3, 4};
  a += b;
  EXPECT_EQ(a.x, 4);
  EXPECT_EQ(a.y, 6);
}

TEST(Vector2D, SubAssign) {
  Vector2D<int> a{5, 7};
  Vector2D<int> b{2, 3};
  a -= b;
  EXPECT_EQ(a.x, 3);
  EXPECT_EQ(a.y, 4);
}
#endif

#ifdef TEST_VECTOR2D_UNARY
TEST(Vector2D, UnaryPlus) {
  Vector2D<double> v{1.0, -2.0};
  auto r = +v;
  EXPECT_DOUBLE_EQ(r.x, 1.0);
  EXPECT_DOUBLE_EQ(r.y, -2.0);
}

TEST(Vector2D, UnaryMinus) {
  Vector2D<double> v{1.0, -2.0};
  auto r = -v;
  EXPECT_DOUBLE_EQ(r.x, -1.0);
  EXPECT_DOUBLE_EQ(r.y, 2.0);
}
#endif

#ifdef TEST_VECTOR2D_SCALAR_OPS
TEST(Vector2D, MultiplyScalarRight) {
  Vector2D<double> v{1.0, -2.0};
  auto r = v * 2.0;
  EXPECT_DOUBLE_EQ(r.x, 2.0);
  EXPECT_DOUBLE_EQ(r.y, -4.0);
}

TEST(Vector2D, MultiplyScalarLeft) {
  Vector2D<double> v{1.0, -2.0};
  auto r = 0.5 * v;
  EXPECT_DOUBLE_EQ(r.x, 0.5);
  EXPECT_DOUBLE_EQ(r.y, -1.0);
}

TEST(Vector2D, DivideScalar) {
  Vector2D<double> v{4.0, -2.0};
  auto r = v / 2.0;
  EXPECT_DOUBLE_EQ(r.x, 2.0);
  EXPECT_DOUBLE_EQ(r.y, -1.0);
}

TEST(Vector2D, MultiplyAssignScalar) {
  Vector2D<int> v{1, -2};
  v *= 3;
  EXPECT_EQ(v.x, 3);
  EXPECT_EQ(v.y, -6);
}

TEST(Vector2D, DivideAssignScalar) {
  Vector2D<double> v{4.0, -2.0};
  v /= 2.0;
  EXPECT_DOUBLE_EQ(v.x, 2.0);
  EXPECT_DOUBLE_EQ(v.y, -1.0);
}
#endif

#ifdef TEST_VECTOR2D_DOT
TEST(Vector2D, DotSameType) {
  Vector2D<double> a{1.0, 2.0};
  Vector2D<double> b{3.0, 4.0};
  auto r = Dot(a, b);
  EXPECT_DOUBLE_EQ(r, 11.0);
}

TEST(Vector2D, DotDifferentTypes) {
  Vector2D<int> a{1, 2};
  Vector2D<double> b{0.5, 1.5};
  auto r = Dot(a, b);
  EXPECT_DOUBLE_EQ(r, 3.5);
}
#endif

#ifdef TEST_VECTOR2D_COMPARISONS
TEST(Vector2D, Equality) {
  Vector2D<int> a{1, 2};
  Vector2D<int> b{1, 2};
  Vector2D<int> c{2, 3};
  EXPECT_TRUE(a == b);
  EXPECT_FALSE(a == c);
}

TEST(Vector2D, Inequality) {
  Vector2D<int> a{1, 2};
  Vector2D<int> b{2, 3};
  EXPECT_TRUE(a != b);
}
#endif
