#include "../vector2d.hpp"
#include "../quantity.hpp"
#include <gtest/gtest.h>

#ifdef TEST_VECTOR_QUANTITY_ADD
TEST(Vector2DQuantity, AddSameDimension) {
  Vector2D<Length> a{{1.0}, {2.0}};
  Vector2D<Length> b{{3.0}, {4.0}};
  auto c = a + b;
  EXPECT_DOUBLE_EQ(c.x.value, 4.0);
  EXPECT_DOUBLE_EQ(c.y.value, 6.0);
}
#endif

#ifdef TEST_VECTOR_QUANTITY_SCALAR
TEST(Vector2DQuantity, MultiplyScalar) {
  Vector2D<Speed> v{{2.0}, {3.0}};
  auto r = v * 2.0;
  EXPECT_DOUBLE_EQ(r.x.value, 4.0);
  EXPECT_DOUBLE_EQ(r.y.value, 6.0);
}
#endif

#ifdef TEST_VECTOR_QUANTITY_DIM
TEST(Vector2DQuantity, MultiplyByTime) {
  Vector2D<Speed> v{{3.0}, {4.0}};
  Time t{2.0};
  auto r = v * t;
  EXPECT_DOUBLE_EQ(r.x.value, 6.0);
  EXPECT_DOUBLE_EQ(r.y.value, 8.0);
}
#endif

#ifdef TEST_VECTOR_QUANTITY_DOT
TEST(Vector2DQuantity, DotProduct) {
  Vector2D<Force> f{{2.0}, {3.0}};
  Vector2D<Length> l{{4.0}, {5.0}};
  auto e = Dot(f, l);
  EXPECT_DOUBLE_EQ(e.value, 23.0);
}
#endif

#ifdef TEST_VECTOR_QUANTITY_COMPILETIME
TEST(Vector2DQuantityCompile, ResultType) {
  Vector2D<Speed> v{{1.0}, {2.0}};
  Time t{3.0};
  Vector2D<Length> l = v * t;
  (void)l;
}
#endif
