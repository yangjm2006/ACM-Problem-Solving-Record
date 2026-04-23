#pragma once

template <typename T = double>
class Complex {
private:
	T r, i;

public:
	Complex(T r, T i) : r(r), i(i) {}

	T real() const { return r; }
	T imag() const { return i; }

	void real(T r) { this.r = r; }
	void imag(T i) { this.i = i; }

	explicit Complex(T r, T i = 0.0) : r(r), i(i) {}

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
		T tmp = *this;
		tmp += other;
		return tmp;
	}

	Complex operator*(const Complex& other) const {
		T tmp;
		tmp.r = (this->r * other.r - this->i * other.i);
		tmp.i = (this->r * other.i + this->i * other.r);
		return tmp;
	}
};