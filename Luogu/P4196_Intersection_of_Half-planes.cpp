#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int N = 1e4 + 100;
int sgn(double x) { return abs(x) <= eps ? 0 : (x < 0 ? -1 : 1); }
struct Point {
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	bool operator==(const Point& other) const {
		return sgn(x - other.x) == 0 && sgn(y - other.y) == 0;
	}
	bool operator<(const Point& other) const {
		return sgn(x - other.x) < 0 || (sgn(x - other.x) == 0 && sgn(y - other.y) < 0);
	}
	Point operator-(const Point& other) const { return Point(x - other.x, y - other.y); }
	Point operator*(const double& k) const { return Point(x * k, y * k); }
	Point operator/(const double& k) const { return Point(x / k, y / k); }
	double operator^(const Point& other) const { return x * other.y - y * other.x; }
};
struct Line {
	Point start, end;
	double angle;
	Line() {}
	Line(Point s, Point t) : start(s), end(t), angle(atan2(t.y - s.y, t.x - s.x)) {}
	bool operator<(const Line& other) const {
		if (sgn(angle - other.angle) == 0) return ((end - start) ^ (other.end - start)) > 0;
		return angle < other.angle;
	}
};
Point getPoint(Line l1, Line l2) {
	double s1 = (l2.end - l1.start) ^ (l1.end - l1.start),
		   s2 = (l2.start - l1.start) ^ (l1.end - l1.start);
	return (l2.start * s1 - l2.end * s2) / (s1 - s2);
}
int Intersection_of_Half_Planes(int n, Line* l, Point* isc) {
	sort(l, l + n);
	int tot = 1;
	for (int i = 1; i < n; i++) {
		if (sgn(l[i].angle - l[i - 1].angle) != 0) {
			l[tot++] = l[i];
		}
	}
	Line deq[N];
	int top = 1, back = 0;
	deq[0] = l[0];
	deq[1] = l[1];
	for (int i = 2; i < tot; i++) {
		while (back < top&&) }
}
int n, cnt;
Line l[N];
Point isc[N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		vector<Point> vec;
		for (int j = 1; j <= m; j++) {
			double x, y;
			cin >> x >> y;
			vec.push_back(Point(x, y));
		}
		for (int i = 0; i < m; i++) {
			l[cnt++] = Line(vec[i], vec[(i + 1) % m]);
		}
	}
	cnt = Intersection_of_Half_Planes(cnt, l, isc);
	double ans = 0;
	for (int i = 0; i < cnt; i++) ans += isc[i] ^ isc[(i + 1) % cnt];
	cout << fixed << setprecision(3) << ans / 2;
	return 0;
}