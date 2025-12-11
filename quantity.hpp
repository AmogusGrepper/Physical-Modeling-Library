

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
Quantity<T, L, M> operator+(Quantity<T, L, M> x, Quantity<T, L, M> y) {
	return {x.value + y.value};
}

// -
template <int T, int L, int M>
Quantity<T, L, M> operator-(Quantity<T, L, M> x, Quantity<T, L, M> y) {
	return {x.value - y.value};
}

// +=
template <int T, int L, int M>
Quantity<T, L, M> operator+=(Quantity<T, L, M> x, Quantity<T, L, M> y) {
	return {x.value + y.value};
}

// -=
template <int T, int L, int M>
Quantity<T, L, M> operator-=(Quantity<T, L, M> x, Quantity<T, L, M> y) {
	return {x.value - y.value};
}
