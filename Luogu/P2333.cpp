#include <bits/stdc++.h>
using namespace std;
const int N = 250;
const double PI = acos(-1.0);
struct Point {
	double x, y;
	Point() {}
	Point(double tx, double ty) : x(tx), y(ty) {}
	Point operator+(const Point& other) const { return Point(x + other.x, y + other.y); }
	Point operator-(const Point& other) const { return Point(x - other.x, y - other.y); }
	Point operator*(const double k) const { return Point(x * k, y * k); }
	double operator*(const Point& other) const { return x * other.x + y * other.y; }
	double distance() { return hypot(x, y); }
	double distance(const Point& other) const { return hypot(x - other.x, y - other.y); }
	bool operator==(const Point& other) const { return x == other.x && y == other.y; }
	double operator^(const Point& other) const { return x * other.y - y * other.x; }
};
typedef Point Vector;
double len_distance(Point a, Point b) { return fabs(a ^ b) / a.distance(b); }
double angle(Point p1, Point p2) {
	double a = p1.distance(), b = p2.distance(), c = (p1 - p2).distance();
	return acos((a * a + b * b - c * c) / (2 * a * b));
}
void ident(Vector& v) {
	double dis = v.distance();
	v.x /= dis;
	v.y /= dis;
}
Vector vertical(Vector v) { return Vector(-v.y, v.x); }
double area(double angle, double r) { return angle / 2 * r * r; }
double area(Point a, Point b) { return abs(a ^ b) / 2; }
Point get_point(Point a, Point b, double r, int op) {
	double dis = len_distance(a, b);
	double d = sqrt(r * r - dis * dis);
	Vector v1 = b - a;
	ident(v1);
	Vector v2 = vertical(v1);
	Point q = v2 * dis;
	if (op == 1) {
		return q - v1 * d;
	} else {
		return q + v1 * d;
	}
}
bool outofline(Point p1, Point p2, Point a) {
	Vector v1 = p2 - p1, v2 = a - p1;
	return v1 * v2 <= 0 || v2.distance() >= v1.distance();
}
int n;
Point p[N];
double cal(double r) {
	double res = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] == p[(i + 1) % n]) continue;
		double dis1 = p[i].distance(), dis2 = p[(i + 1) % n].distance();
		if (dis1 <= r && dis2 <= r) {
			res += area(p[i], p[(i + 1) % n]);
			continue;
		}
		double dis3 = len_distance(p[i], p[(i + 1) % n]);
		Point a = get_point(p[i], p[(i + 1) % n], r, 1), b = get_point(p[i], p[(i + 1) % n], r, 2);
		if (dis3 >= r) {
			res += area(angle(p[i], p[(i + 1) % n]), r);
			continue;
		} else if (outofline(p[i], p[(i + 1) % n], a) && outofline(p[i], p[(i + 1) % n], b)) {
			res += area(angle(p[i], p[(i + 1) % n]), r);
			continue;
		}
		if (dis1 > r && dis2 > r) {
			res += area(a, b);
			res += area(angle(p[i], a), r);
			res += area(angle(b, p[(i + 1) % n]), r);
		} else if (dis1 > r) {
			res += area(angle(p[i], a), r);
			res += area(a, p[(i + 1) % n]);
		} else {
			res += area(angle(b, p[(i + 1) % n]), r);
			res += area(p[i], b);
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	double target;
	cin >> target;
	double L = 0, R = 0;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		R = max(R, p[i].distance());
	}
	if ((p[0] ^ p[1]) > 0) {
		for (int i = 0; i < n / 2; i++) swap(p[i], p[n - 1 - i]);
	}
	for (int i = 1; i <= 50; i++) {
		double mid = (L + R) / 2;
		if (cal(mid) >= target)
			R = mid;
		else
			L = mid;
	}
	cout << fixed << setprecision(2) << L;
	return 0;
}