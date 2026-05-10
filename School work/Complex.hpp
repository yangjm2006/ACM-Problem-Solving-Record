#pragma once

#include <cmath>
#include <iostream>

template <typename T = double>
class Complex {
private:
	T r, i;

public:
	Complex() : r(0), i(0) {}

	T real() const { return r; }
	T imag() const { return i; }

	void real(T r) { this->r = r; }
	void imag(T i) { this->i = i; }

	explicit Complex(T r, T i = T{}) : r(r), i(i) {}

	Complex(const Complex& other) = default;

	Complex& operator=(const Complex& other) {
		r = other.r;
		i = other.i;
		return *this;
	}

	Complex& operator+=(const Complex& other) {
		r += other.r;
		i += other.i;
		return *this;
	}

	Complex operator+(const Complex& other) const {
		return Complex<T>(this->r + other.r, this->i + other.i);
	}

	Complex operator*(const Complex& other) const {
		return Complex<T>(this->r * other.r - this->i * other.i,
						  this->r * other.i + this->i * other.r);
	}

	bool operator==(const Complex& other) const;
	bool operator!=(const Complex& other) const { return !(*this == other); }
};

template <>
inline bool Complex<float>::operator==(const Complex<float>& other) const {
	return std::abs(r - other.r) <= 1e-5f && std::abs(i - other.i) <= 1e-5f;
}
template <>
inline bool Complex<double>::operator==(const Complex<double>& other) const {
	return std::abs(r - other.r) <= 1e-10 && std::abs(i - other.i) <= 1e-10;
}
template <>
inline bool Complex<long double>::operator==(const Complex<long double>& other) const {
	return std::abs(r - other.r) <= 1e-15l && std::abs(i - other.i) <= 1e-15l;
}

template <typename T>
inline std::istream& operator>>(std::istream& is, Complex<T>& c) {
	T r, i;
	char ch;
	is >> r >> i >> ch;
	c.real(r);
	c.imag(i);
	return is;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Complex<T>& c) {
	os << c.real();
	if (c.imag() >= 0) {
		os << "+";
	}
	os << c.imag() << "i";
	return os;
}

template <typename T>
Complex<T> operator+(T r, const Complex<T>& c) {
	return Complex<T>(c.real() + r, c.imag());
}