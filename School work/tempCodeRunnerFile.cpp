#pragma once
#include <cmath>

class Point {
private:
    double _x, _y;

public:
    Point() : _x(0.0), _y(0.0) {}
    Point(double tx, double ty) : _x(tx), _y(ty) {}

    double x() const { return _x; }
    double y() const { return _y; }

    void x(double x) { _x = x; }
    void y(double y) { _y = y; }

    void set(double x, double y) {
        _x = x;
        _y = y;
    }

    double polar_radius() const { return std::hypot(_x, _y); }

    double polar_angle() const {
        if (_x == 0 && _y == 0) return 0;
        return std::atan2(_y, _x);
    }

    double distance(Point& _) const { return hypot(_x - _._x, _y - _._y); }

    bool is_near(Point& p, double eps = 1e-8) const {
        return distance(p) <= eps;
    }
};
