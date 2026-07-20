#include <bits/stdc++.h>
#define double long double
using namespace std;
const int N = 2e5 + 100;
const double PI = acos(-1.0);
const double sqrt3 = sqrt(3);
const double eps = 1e-9;
int sgn(double x) { return abs(x) < eps ? 0 : (x < 0 ? -1 : 1); }
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
	bool operator<(const Point& other) const {
		return sgn(x - other.x) == 0 ? y < other.y : x < other.x;
	}
};
double distance(Point a, Point b) { return hypot(a.x - b.x, a.y - b.y); }
int Convex_hull(Point* p, int n, Point* ch) {
	sort(p, p + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		while (cnt > 1 && sgn((ch[cnt - 1] - ch[cnt - 2]) ^ (p[i] - ch[cnt - 1])) <= 0) cnt--;
		ch[cnt++] = p[i];
	}
	int tmp = cnt;
	for (int i = n - 2; i >= 0; i--) {
		while (cnt > tmp && sgn((ch[cnt - 1] - ch[cnt - 2]) ^ (p[i] - ch[cnt - 1])) <= 0) cnt--;
		ch[cnt++] = p[i];
	}
	if (cnt > 1) cnt--;
	return cnt;
}
int a[100];
Point p[N], ch[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == 'S')
			a[i] = 1;
		else if (c == 'C')
			a[i] = 2;
		else
			a[i] = 3;
	}
	int minn = n + 1, maxx = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= 2) {
			minn = min(minn, i);
			maxx = max(maxx, i);
		}
	}
	for (int i = minn + 1; i <= maxx - 1; i++) a[i] = 1;
	int cnt = 0;
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			p[cnt++] = Point(i - 1, 0);
			p[cnt++] = Point(i - 1, 1);
			p[cnt++] = Point(i, 0);
			p[cnt++] = Point(i, 1);
		} else if (a[i] == 2) {
			Point o(i - 0.5, 0.5);
			if (i == 1) {
				ans += PI / 2 - 1;
				for (int i = -1500; i <= 1500; i++) {
					p[cnt++] = o + Point(cos(i / 3000.0 * PI), sin(i / 3000.0 * PI)) * 0.5;
				}
			} else if (i == n) {
				ans += PI / 2 - 1;
				for (int i = 1500; i <= 4500; i++) {
					p[cnt++] = o + Point(cos(i / 3000.0 * PI), sin(i / 3000.0 * PI)) * 0.5;
				}
			} else {
				for (int i = 0; i <= 6000; i++) {
					p[cnt++] = o + Point(cos(i / 3000.0 * PI), sin(i / 3000.0 * PI)) * 0.5;
				}
			}
		} else {
			p[cnt++] = Point(i - 1, 0);
			p[cnt++] = Point(i, 0);
			p[cnt++] = Point(i - 0.5, sqrt3 / 2);
		}
	}
	cnt = Convex_hull(p, cnt, ch);
	for (int i = 0; i < cnt; i++) {
		ans += distance(ch[i], ch[(i + 1) % cnt]);
	}
	cout << fixed << setprecision(10) << ans;
	return 0;
}