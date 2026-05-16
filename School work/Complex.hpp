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

	void real(T x) { r = x; }
	void imag(T x) { i = x; }

	explicit Complex(T r, T i = T()) : r(r), i(i) {}
	Complex(const Complex& other) = default;

	const Complex& operator=(const Complex& other) {
		r = other.r;
		i = other.i;
		return *this;
	}

	Complex& operator+=(const Complex& other) {
		r += other.r;
		i += other.i;
		return *this;
	}
	Complex operator+(const Complex& other) const { return Complex(r + other.r, i + other.i); }

	Complex operator*(const Complex& other) const {
		return Complex(r * other.r - i * other.i, r * other.i + i * other.r);
	}

	friend std::istream& operator>>(std::istream& is, Complex<T>& z) {
		T r, i;
		char c;
		is >> r >> i >> c;
		z = Complex(r, i);
		return is;
	}
	friend std::ostream& operator<<(std::ostream& os, const Complex& z) {
		os << z.real();
		if (z.imag() >= 0) {
			os << "+";
		}
		os << z.imag() << "i";
		return os;
	}

	friend Complex operator+(T a, const Complex<T>& b) { return Complex(a + b.real(), b.imag()); }

	bool operator==(const Complex<float>& other) const {
		return std::abs(r - other.r) <= 1e-4f && std::abs(i - other.i) <= 1e-4f;
	}
	bool operator==(const Complex<double>& other) const {
		return std::abs(r - other.r) <= 1e-8 && std::abs(i - other.i) <= 1e-8;
	}
	bool operator==(const Complex<long double>& other) const {
		return std::abs(r - other.r) <= 1e-12l && std::abs(i - other.i) <= 1e-12l;
	}
	bool operator!=(const Complex& other) const { return !(*this == other); }
};