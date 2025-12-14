#pragma once

template <class T>
struct Vector2D {
  T x;
  T y;
}

template <class T>
Vector2D<T> operator+(Vector2D<T> lhs, Vector2D<T> rhs) {
  return {lhs.x + rhs.x, lhs.y + rhs.y};
}

template <class T>
Vector2D<T> operator-(Vector2D<T> lhs, Vector2D<T> rhs) {
  return {lhs.x - rhs.x, lhs.y - rhs.y};
}

