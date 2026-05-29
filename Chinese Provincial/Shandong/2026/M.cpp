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
int convex_hull(Point p[], int n, Point ch[]) {
	sort(p, p + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		while (cnt > 1 && ((ch[cnt - 1] - ch[cnt - 2]) ^ (p[i] - ch[cnt - 1])) <= 0) cnt--;
		ch[cnt++] = p[i];
	}
	int tmp = cnt;
	for (int i = n - 2; i >= 0; i--) {
		while (cnt > tmp && ((ch[cnt - 1] - ch[cnt - 2]) ^ (p[i] - ch[cnt - 1])) <= 0) cnt--;
		ch[cnt++] = p[i];
	}
	if (cnt > 1) cnt--;
	return cnt;
}
Point p[N], q[N], ch[N];
int n, m, aph;
struct double_Point {
	double x, y;
	double_Point(double x, double y) : x(x), y(y) {}
};
struct Line {
	double a, b, c;
	double_Point get_point(const Line& other) const { return }
};
double dis(double_Point a, double_Point b) { return hypot(a.x - b.x, a.y - b.y); }

void __() {
	cin >> n >> m >> aph;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	for (int i = 0; i < m; i++) {
		cin >> q[i].x >> q[i].y;
	}
	m = convex_hull(q, m, ch);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}