#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 100;
struct Point {
	ll x, y;
	Point() {}
	Point(ll x, ll y) : x(x), y(y) {}
	bool operator<(const Point& other) const {
		return x < other.x || (x == other.x && y < other.y);
	}
	Point operator-(const Point& other) const { return Point(x - other.x, y - other.y); }
	ll operator^(const Point& other) const { return x * other.y - y * other.x; }
	double len() const { return hypot(x, y); }
} p[N];
int Convex_hull(Point* p, int n, Point* ch) {
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
Point ch[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, L;
	cin >> n >> L;
	for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
	n = Convex_hull(p + 1, n, ch);
	double ans = 0;
	for (int i = 0; i < n; i++) ans += (ch[i] - ch[(i + 1) % n]).len();
	ans += L * acos(-1) * 2;
	cout << ll(ans + 0.5);
	return 0;
}