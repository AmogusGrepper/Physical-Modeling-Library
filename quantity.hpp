template <int T, int L, int M>
struct Quantity {
	double value;
};

// Common types
using Time = Quantity<1, 0, 0>;
using Length = Quantity<0, 1, 0>;
using Mass = Quantity<0, 0, 1>;

// +
template <int T, int L, int M>
Quantity<T, L, M> operator+(Quantity<T, L, M> lhs, Quantity<T, L, M> rhs) {
	return {lhs.value + rhs.value};
}

// -
template <int T, int L, int M>
Quantity<T, L, M> operator-(Quantity<T, L, M> lhs, Quantity<T, L, M> rhs) {
	return {lhs.value - rhs.value};
}

// +=
template <int T, int L, int M>
Quantity<T, L, M> &operator+=(Quantity<T, L, M>& lhs, Quantity<T, L, M> rhs) {
  lhs.value += rhs.value;
  return lhs;
}

// -=
template <int T, int L, int M>
Quantity<T, L, M> &operator-=(Quantity<T, L, M> &lhs, Quantity<T, L, M> rhs) {
  lhs.value -= rhs.value;
  return lhs;
}

// -
template <int T, int L, int M>
Quantity<T, L, M> operator-(Quantity<T, L, M> rhs) {
  return {-rhs.value};
}

// +
template <int T, int L, int M>
Quantity<T, L, M> operator+(Quantity<T, L, M> rhs) {
  return {+rhs.value};
}

