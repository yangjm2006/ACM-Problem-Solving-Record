#pragma once
#include "Vector3d.hpp"

class Matrix3d {
public:
    Vector3d row[3];

    Matrix3d() { row[0] = row[1] = row[2] = Vector3d(0.0, 0.0, 0.0); }
    Matrix3d(const double x[]) {
        row[0] = Vector3d{x[0], x[1], x[2]};
        row[1] = Vector3d(x[3], x[4], x[5]);
        row[2] = Vector3d(x[6], x[7], x[8]);
    }
    Matrix3d(const Matrix3d& other) = default;

    Matrix3d& operator=(const Matrix3d& other) = default;
    const Vector3d& operator[](int idx) const { return row[idx]; }
    Vector3d& operator[](int idx) { return row[idx]; }

    const Matrix3d& operator+=(const Matrix3d& other) {
        row[0] += other.row[0];
        row[1] += other.row[1];
        row[2] += other.row[2];
        return *this;
    }
    Matrix3d operator+(const Matrix3d& other) const { return Matrix3d(*this) += other; }
    const Matrix3d& operator*=(const double k) {
        row[0] *= k;
        row[1] *= k;
        row[2] *= k;
        return *this;
    }
    Matrix3d operator*(const double k) const { return Matrix3d(*this) *= k; }
    Matrix3d operator*(const Matrix3d other) const {
        Matrix3d ans;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    ans.row[i][j] += row[i][k] * other.row[k][j];
                }
            }
        }
        return ans;
    }

    static Matrix3d identity(void) { return Matrix3d((double[]){1, 0, 0, 0, 1, 0, 0, 0, 1}); }
    static Matrix3d scale(double sx, double sy, double sz) {
        return Matrix3d((double[]){sx, 0, 0, 0, sy, 0, 0, 0, sz});
    }

    friend Vector3d operator*(const Matrix3d& m, const Vector3d& v) {
        Vector3d ans;
        for (int i = 0; i < 3; i++) {
            ans[i] = m.row[i] * v;
        }
        return ans;
    }
};