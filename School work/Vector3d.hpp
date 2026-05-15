#pragma once

#include <iostream>

class Vector3d {
public:
	double x, y, z;

	Vector3d() : x(0), y(0), z(0) {}
	Vector3d(double x, double y, double z) : x(x), y(y), z(z) {}
	Vector3d(const Vector3d& other) = default;

	Vector3d& operator=(const Vector3d& other) {
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	double operator[](int id) const {
		if (id == 0) return x;
		if (id == 1) return y;
		return z;
	}
	double& operator[](int id) {
		if (id == 0) return x;
		if (id == 1) return y;
		return z;
	}

	Vector3d operator+(const Vector3d& other) const {
		return Vector3d(x + other.x, y + other.y, z + other.z);
	}
	Vector3d& operator+=(const Vector3d& other) { return *this = (*this + other); }

	Vector3d operator*(double k) const { return Vector3d(x * k, y * k, z * k); }
	Vector3d& operator*=(double k) { return *this = (*this * k); }

	double operator*(const Vector3d& other) const {
		return x * other.x + y * other.y + z * other.z;
	}

	Vector3d operator^(const Vector3d& other) const {
		return Vector3d(y * other.z - z * other.y, z * other.x - x * other.z,
						x * other.y - y * other.x);
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector3d& v) {
		os << "(" << v.x << " " << v.y << " " << v.z << ")";
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Vector3d& v) {
		char c;
		is >> c >> v.x >> v.y >> v.z >> c;
		return is;
	}

	bool operator<(const Vector3d& other) const {
		for (int i = 0; i < 3; i++)
			if ((*this)[i] != other[i]) return (*this)[i] < other[i];
	}
};