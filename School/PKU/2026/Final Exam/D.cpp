#include <bits/stdc++.h>

typedef long long ll;
const int N = 1e6 + 100;

using namespace std;

struct Point {
	ll x, y;
	int id;
	Point() {}
	Point(ll x, ll y) : x(x), y(y) {}
	bool operator<(const Point& other) const {
		return x * x + y * y < other.x * other.x + other.y * other.y;
	}
	bool operator>(const Point& other) const {
		return x * x + y * y > other.x * other.x + other.y * other.y;
	}
	ll operator*(const Point& other) const { return x * other.x + y * other.y; }
	Point operator+(const Point& other) const { return Point(x + other.x, y + other.y); }
	Point operator-(const Point& other) const { return Point(x - other.x, y - other.y); }
} p[N];

int ans[N];

void __() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].id = i;
	}
	sort(p + 1, p + 1 + n, greater<Point>());
	Point sum(0, 0);
	for (int i = 1; i <= n; i++) {
		if (sum * p[i] <= 0) {
			ans[p[i].id] = 1;
			sum = sum + p[i];
		} else {
			ans[p[i].id] = -1;
			sum = sum - p[i];
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}