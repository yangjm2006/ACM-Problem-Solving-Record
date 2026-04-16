#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 100;
struct Point {
	ll x, y;
	int id;
	Point() {}
	Point(ll x, ll y) : x(x), y(y), id(0) {}
	Point operator+(const Point& _) { return Point(x + _.x, y + _.y); }
	Point operator-(const Point& _) { return Point(x - _.x, y - _.y); }
	bool operator<(const Point& _) { return x < _.x || (x == _.x && y < _.y); }
	ll operator*(const Point& _) { return x * _.x + y * _.y; }
	ll operator^(const Point& _) { return x * _.y - y * _.x; }
};
typedef Point Vector;
ll len2(Vector v) { return v * v; }
ll dist(Point A, Point B, Point C) { return abs((A - B) ^ (A - C)); }
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
Point p[N], ch[N];
void __() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].id = i;
	}
	n = Convex_hull(p, n, ch);
	int tp = 1;
	ll ans = -1;
	int id1 = 0, id2 = 1;
	for (int i = 0; i < n; i++) {
		while (dist(ch[tp % n], ch[i], ch[(i + 1) % n]) <
			   dist(ch[(tp + 1) % n], ch[i], ch[(i + 1) % n])) {
			tp++;
		}
		ll ans1 = len2(ch[tp % n] - ch[i]), ans2 = len2(ch[tp % n] - ch[(i + 1) % n]);
		if (ans < ans1) {
			id1 = ch[tp % n].id;
			id2 = ch[i].id;
			ans = ans1;
		}
		if (ans < ans2) {
			id1 = ch[tp % n].id;
			id2 = ch[(i + 1) % n].id;
			ans = ans2;
		}
	}
	cout << id1 << " " << id2 << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}