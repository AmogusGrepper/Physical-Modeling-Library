#include <compare>

template <int T, int L, int M> struct Quantity {
  double value{};

  auto operator<=>(const Quantity &) const = default;
};

// ==== ADD SUB ====
// +
template <int T, int L, int M>
Quantity<T, L, M> operator+(const Quantity<T, L, M> lhs,
                            const Quantity<T, L, M> rhs) {
  return {lhs.value + rhs.value};
}

// -
template <int T, int L, int M>
Quantity<T, L, M> operator-(const Quantity<T, L, M> lhs,
                            const Quantity<T, L, M> rhs) {
  return {lhs.value - rhs.value};
}

// +=
template <int T, int L, int M>
Quantity<T, L, M> &operator+=(Quantity<T, L, M> &lhs,
                              const Quantity<T, L, M> rhs) {
  lhs.value += rhs.value;
  return lhs;
}

// -=
template <int T, int L, int M>
Quantity<T, L, M> &operator-=(Quantity<T, L, M> &lhs,
                              const Quantity<T, L, M> rhs) {
  lhs.value -= rhs.value;
  return lhs;
}

// - unary
template <int T, int L, int M>
Quantity<T, L, M> operator-(const Quantity<T, L, M> rhs) {
  return {-rhs.value};
}

// + unary
template <int T, int L, int M>
Quantity<T, L, M> operator+(const Quantity<T, L, M> rhs) {
  return {+rhs.value};
}

// ==== MUL DIV ====
// *
template <int T1, int L1, int M1, int T2, int L2, int M2>
Quantity<T1 + T2, L1 + L2, M1 + M2> operator*(const Quantity<T1, L1, M1> lhs,
                                              const Quantity<T2, L2, M2> rhs) {
  return {lhs.value * rhs.value};
}

// /
template <int T1, int L1, int M1, int T2, int L2, int M2>
Quantity<T1 - T2, L1 - L2, M1 - M2> operator/(const Quantity<T1, L1, M1> lhs,
                                              const Quantity<T2, L2, M2> rhs) {
  return {lhs.value / rhs.value};
}

// * double
template <int T, int L, int M>
Quantity<T, L, M> operator*(const Quantity<T, L, M> lhs, const double rhs) {
  return {lhs.value * rhs};
}

// / double
template <int T, int L, int M>
Quantity<T, L, M> operator/(const Quantity<T, L, M> lhs, const double rhs) {
  return {lhs.value / rhs};
}

// *= double
template <int T, int L, int M>
Quantity<T, L, M> &operator*=(Quantity<T, L, M> &lhs, const double rhs) {
  lhs.value *= rhs;
  return lhs;
}

// /= double
template <int T, int L, int M>
Quantity<T, L, M> &operator/=(Quantity<T, L, M> &lhs, const double rhs) {
  lhs.value /= rhs;
  return lhs;
}

// ==== Common types ====
using Time = Quantity<1, 0, 0>;
using Length = Quantity<0, 1, 0>;
using Mass = Quantity<0, 0, 1>;
using Speed = decltype(Length() / Time());
using Acceleration = decltype(Speed() / Time());
using Force = decltype(Mass() * Acceleration());
using Energy = decltype(Mass() * Speed() * Speed() / 2);
