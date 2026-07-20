#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 100;
int n;
struct Point {
	long long x, y, val;
	Point() {}
	Point(long long x, long long y) : x(x), y(y) {}
	Point operator-(const Point& other) const { return Point(x - other.x, y - other.y); }
	long long operator^(const Point& other) const { return x * other.y - y * other.x; }
	bool operator<(const Point& other) const {
		if ((*this ^ other) == 0) return val > other.val;
		return (*this ^ other) > 0;
	}
} p[N];
struct Line {
	long long x1, x2, y;
	Line() {}
} l[N];
long long cal(Point o) {
	long long ans = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (l[i].y == o.y) continue;
		Point a, b;
		if (l[i].y > o.y) {
			a = Point(l[i].x1, l[i].y) - o;
			b = Point(l[i].x2, l[i].y) - o;
		} else {
			a = o - Point(l[i].x1, l[i].y);
			b = o - Point(l[i].x2, l[i].y);
		}
		if (a.x < b.x) {
			swap(a, b);
		}
		a.val = a.x - b.x;
		b.val = b.x - a.x;
		p[++cnt] = a;
		p[++cnt] = b;
	}
	sort(p + 1, p + 1 + cnt);
	long long s = 0;
	for (int i = 1; i <= cnt; i++) {
		s += p[i].val;
		ans = max(ans, s);
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> l[i].x1 >> l[i].x2 >> l[i].y;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, max(cal(Point(l[i].x1, l[i].y)), cal(Point(l[i].x2, l[i].y))) +
						   abs(l[i].x1 - l[i].x2));
	}
	cout << ans;
	return 0;
}