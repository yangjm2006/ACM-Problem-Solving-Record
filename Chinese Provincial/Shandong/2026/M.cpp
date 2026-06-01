#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e5 + 100;
struct Point {
	ll x, y;
	Point() {}
	Point(ll x, ll y) : x(x), y(y) {}
	Point operator+(const Point& other) const { return Point(x + other.x, y + other.y); }
	Point operator-(const Point& other) const { return Point(x - other.x, y - other.y); }
	bool operator<(const Point& other) const {
		return x < other.x || (x == other.x && y < other.y);
	}
	ll operator*(const Point& other) const { return x * other.x + y * other.y; }
	ll operator^(const Point& other) const { return x * other.y - y * other.x; }
};
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
struct double_Point {
	double x, y;
	double_Point(double x, double y) : x(x), y(y) {}
};
struct Line {
	double a, b, c;
	double_Point get_point(const Line& other) const {
		return double_Point((b * other.c - c * other.b) / (a * other.b - b * other.a),
							(a * other.c - c * other.a) / (b * other.a - a * other.b));
	}
};
double dis(double_Point a, double_Point b) { return hypot(a.x - b.x, a.y - b.y); }
double_Point getPoint1() {
	int l = 0, r = cnt1;
	while (l < r) {
	}
}
double_Point getPoint2() {}
void __() {
	cin >> n >> m >> aph;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	for (int i = 0; i < m; i++) {
		cin >> q[i].x >> q[i].y;
	}
	convex_hull(q, m, ch1, ch2, cnt1, cnt2);
	double ans = 0;
	for (int i = 0; i < m; i++) {
		double_Point P = double_Point(p[i].x, p[i].y);
		double ans1 = min(dis(P, getPoint1()), dis(P, getPoint2()));
		double ans2 = min(dis(P, getPoint1()), dis(P, getPoint2()));
		ans += min(ans1, ans2);
	}
	cout << fixed << setprecision(10) << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}