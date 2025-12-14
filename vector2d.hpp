#pragma once

#include <utility>

template <class T>
struct Vector2D {
  T x;
  T y;

  bool operator==(const Vector2D<T> &other) const = default;
  bool operator!=(const Vector2D<T> &other) const = default;
};

// +
template <class T>
Vector2D<T> operator+(const Vector2D<T> &lhs, const Vector2D<T> &rhs) {
  return {lhs.x + rhs.x, lhs.y + rhs.y};
}

// -
template <class T>
Vector2D<T> operator-(const Vector2D<T> &lhs, const Vector2D<T> &rhs) {
  return {lhs.x - rhs.x, lhs.y - rhs.y};
}

// +=
template <class T>
Vector2D<T> &operator+=(Vector2D<T> &lhs, const Vector2D<T> &rhs) {
  lhs.x += rhs.x;
  lhs.y += rhs.y;
  return lhs;
}

// -=
template <class T>
Vector2D<T> &operator-=(Vector2D<T> &lhs, const Vector2D<T> &rhs) {
  lhs.x -= rhs.x;
  lhs.y -= rhs.y;
  return lhs;
}

// unary +
template <class T>
Vector2D<T> operator+(const Vector2D<T> &other) {
  return {+other.x, +other.y};
}

// unary -
template <class T>
Vector2D<T> operator-(const Vector2D<T> &other) {
  return {-other.x, -other.y};
}

// * const
template <class T, class U>
Vector2D<decltype(std::declval<T>() * std::declval<U>())>
operator*(const Vector2D<T> &lhs, const U rhs) {
  return {lhs.x * rhs, lhs.y * rhs};
}

// const *
template <class T, class U>
Vector2D<decltype(std::declval<U>() * std::declval<T>())>
operator*(const U lhs, const Vector2D<T> &rhs) {
  return {rhs.x * lhs, rhs.y * lhs};
}

// / const
template <class T, class U>
Vector2D<decltype(std::declval<T>() / std::declval<U>())>
operator/(const Vector2D<T> &lhs, const U rhs) {
  return {lhs.x / rhs, lhs.y / rhs};
}

// *= const
template <class T, class U>
Vector2D<T> &operator*=(Vector2D<T> &lhs, const U rhs) {
  lhs.x *= rhs;
  lhs.y *= rhs;
  return lhs;
}

// / const
template <class T, class U>
Vector2D<T> &operator/=(Vector2D<T> &lhs, const U rhs) {
  lhs.x /= rhs;
  lhs.y /= rhs;
  return lhs;
}

// Dot
template <class T, class U>
decltype(std::declval<T>() * std::declval<U>())
Dot(const Vector2D<T> &lhs, const Vector2D<U> &rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y;
}
