#pragma once
#include <istream>
#include <ostream>

class Vector3d {
public:
    double x, y, z;
    Vector3d(void) : x(0), y(0), z(0) {}
    Vector3d(double tx, double ty, double tz) : x(tx), y(ty), z(tz) {}
    Vector3d(const Vector3d& other) = default;

    Vector3d& operator=(const Vector3d& other) = default;
    double operator[](int idx) const {
        if (idx == 0) return x;
        if (idx == 1) return y;
        return z;
    }
    double& operator[](int idx) {
        if (idx == 0) return x;
        if (idx == 1) return y;
        return z;
    }

    Vector3d operator+(const Vector3d& other) const {
        return Vector3d{x + other.x, y + other.y, z + other.z};
    }
    Vector3d& operator+=(const Vector3d& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }
    Vector3d operator*(const double k) const { return Vector3d{x * k, y * k, z * k}; }
    Vector3d& operator*=(const double k) {
        x *= k;
        y *= k;
        z *= k;
        return *this;
    }
    double operator*(const Vector3d& other) const {
        return x * other.x + y * other.y + z * other.z;
    }
    Vector3d operator^(const Vector3d& other) const {
        return Vector3d{y * other.z - z * other.y, z * other.x - x * other.z,
                        x * other.y - y * other.x};
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector3d& v) {
        os << "(" << v.x << " " << v.y << " " << v.z << ")";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Vector3d& v) {
        char ch;
        is >> ch >> v.x >> v.y >> v.z >> ch;
        return is;
    }

    bool operator<(const Vector3d& other) const {
        if (x == other.x) {
            if (y == other.y) return z < other.z;
            return y < other.y;
        }
        return x < other.x;
    }
};