#pragma once

#include "Vector3d.hpp"

class Matrix3d {
public:
	Vector3d row[3];

	Matrix3d() { row[0] = row[1] = row[2] = Vector3d{0, 0, 0}; }
	Matrix3d(const double a[]) {
		row[0] = {a[0], a[1], a[2]};
		row[1] = {a[3], a[4], a[5]};
		row[2] = {a[6], a[7], a[8]};
	}

	const Vector3d& operator[](int id) const { return row[id]; }
	Vector3d& operator[](int id) { return row[id]; }

	Matrix3d& operator+=(const Matrix3d& other) {
		for (int i = 0; i < 3; i++) row[i] += other.row[i];
		return *this;
	}
	Matrix3d operator+(const Matrix3d& other) const {
		Matrix3d tmp(*this);
		tmp += other;
		return tmp;
	}

	Matrix3d& operator*=(double k) {
		for (int i = 0; i < 3; i++) row[i] *= k;
		return *this;
	}
	Matrix3d operator*(double k) const {
		Matrix3d tmp(*this);
		tmp *= k;
		return tmp;
	}

	Matrix3d operator*(const Matrix3d& other) const {
		Matrix3d tmp;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++) tmp.row[i][j] += row[i][k] * other.row[k][j];
		return tmp;
	}

	static Matrix3d identity() { return Matrix3d((double[]){1, 0, 0, 0, 1, 0, 0, 0, 1}); }

	static Matrix3d scale(double sx, double sy, double sz) {
		return Matrix3d((double[]){sx, 0, 0, 0, sy, 0, 0, 0, sz});
	}

	friend Vector3d operator*(const Matrix3d& m, const Vector3d& v) {
		return Vector3d(m.row[0] * v, m.row[1] * v, m.row[2] * v);
	}
};