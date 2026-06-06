#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const long double PI = acos(-1);
struct Point {
	long double x, y;
	Point() {}
	Point(long double x, long double y) : x(x), y(y) {}
	Point operator+(const Point& other) const { return Point(x + other.x, y + other.y); }
	Point operator-(const Point& other) const { return Point(x - other.x, y - other.y); }
	bool operator<(const Point& other) const {
		return x < other.x || (x == other.x && y < other.y);
	}
	long double operator*(const Point& other) const { return x * other.x + y * other.y; }
	long double operator^(const Point& other) const { return x * other.y - y * other.x; }
	long double len() const { return hypot(x, y); }
};
long double gradient(Point a, Point b) { return (b.y - a.y) / (b.x - a.x); }
void rolling(Point& p, long double R = 2) {
	p = Point(p.x * cos(R) - p.y * sin(R), p.y * cos(R) + p.x * sin(R));
}
long double rolling(long double k, long double O) {
	Point p(1, k);
	rolling(p, O);
	return p.y / p.x;
}
void convex_hull(Point p[], int n, Point ch1[], Point ch2[], int& cnt1, int& cnt2) {
	sort(p, p + n);
	cnt1 = 0;
	for (int i = 0; i < n; i++) {
		while (cnt1 > 1 && ((ch1[cnt1 - 1] - ch1[cnt1 - 2]) ^ (p[i] - ch1[cnt1 - 1])) <= 0) cnt1--;
		ch1[cnt1++] = p[i];
	}
	cnt2 = 0;
	for (int i = n - 1; i >= 0; i--) {
		while (cnt2 > 1 && ((ch2[cnt2 - 1] - ch2[cnt2 - 2]) ^ (p[i] - ch2[cnt2 - 1])) <= 0) cnt2--;
		ch2[cnt2++] = p[i];
	}
}
Point p[N], q[N], ch1[N], ch2[N];
int n, m, aph, cnt1, cnt2;
struct Line {
	long double a, b, c;
	Line(Point p, double k) : a(k), b(-1), c(p.y - p.x * k) {}
	Point get_point(const Line& other) const {
		return Point((b * other.c - c * other.b) / (a * other.b - b * other.a),
					 (a * other.c - c * other.a) / (b * other.a - a * other.b));
	}
	Line(Point p1, Point p2) : Line(p1, gradient(p1, p2)) {}
};
Point getPoint1(long double k, Line L) {
	int l = 1, r = cnt1 - 1;
	if (cnt1 == 1 || gradient(ch1[1], ch1[0]) > k)
		l = 0;
	else {
		while (l < r) {
			int mid = (l + r >> 1) + 1;
			if (gradient(ch1[mid], ch1[mid - 1]) <= k)
				l = mid;
			else
				r = mid - 1;
		}
	}
	return L.get_point(Line(ch1[l], k));
}
Point getPoint2(long double k, Line L) {
	int l = 1, r = cnt2 - 1;
	if (cnt2 == 1 || gradient(ch2[1], ch2[0]) > k)
		l = 0;
	else {
		while (l < r) {
			int mid = (l + r >> 1) + 1;
			if (gradient(ch2[mid], ch2[mid - 1]) <= k)
				l = mid;
			else
				r = mid - 1;
		}
	}
	return L.get_point(Line(ch2[l], k));
}
void __() {
	cin >> n >> m >> aph;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		rolling(p[i]);
	}
	for (int i = 0; i < m; i++) {
		cin >> q[i].x >> q[i].y;
		rolling(q[i]);
	}
	convex_hull(q, m, ch1, ch2, cnt1, cnt2);
	long double ans = 0;
	for (int i = 0; i < n; i++) {
		Line L(p[i], p[(i + 1) % n]);
		long double k = gradient(p[i], p[(i + 1) % n]);
		long double k1 = rolling(k, aph * PI / 180), k2 = rolling(k, -aph * PI / 180);
		Point v = p[(i + 1) % n] - p[i];
		v.x /= (p[(i + 1) % n] - p[i]).len();
		v.y /= (p[(i + 1) % n] - p[i]).len();
		long double ans1 = min((getPoint1(k1, L) - p[i]) * v, (getPoint2(k1, L) - p[i]) * v);
		long double ans2 = min((getPoint1(k2, L) - p[i]) * v, (getPoint2(k2, L) - p[i]) * v);
		ans += min(max(0.0l, min(ans1, ans2)), (p[(i + 1) % n] - p[i]).len());
	}
	cout << fixed << setprecision(10) << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}