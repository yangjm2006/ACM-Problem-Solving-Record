#include <bits/stdc++.h>

const int N = 3e3 + 10;
const double eps = 1e-8;

using namespace std;

int sgn(double x) { return abs(x) <= eps ? 0 : (x < 0 ? -1 : 1); }

struct Point {
	double x, y, z;
	Point() {}
	Point(double x, double y, double z) : x(x), y(y), z(z) {}
	Point operator-(const Point& other) const {
		return Point(x - other.x, y - other.y, z - other.z);
	}
	Point operator+(const Point& other) const {
		return Point(x + other.x, y + other.y, z + other.z);
	}
	bool operator<(const Point& other) const {
		return sgn(x - other.x) < 0 || (sgn(x - other.x) == 0 && sgn(y - other.y) < 0) ||
			   (sgn(x - other.x) == 0 && sgn(y - other.y) == 0 && sgn(z - other.z) < 0);
	}
	double operator*(const Point& other) const { return x * other.x + y * other.y + z * other.z; }
	Point operator^(const Point& other) const {
		return Point(y * other.z - z * other.y, z * other.x - x * other.z,
					 x * other.y - y * other.x);
	}
	double len() const { return hypot(x, y, z); }
	double rnd() const { return rand() % 2 ? eps : -eps; }
	void shake() {
		x += rnd();
		y += rnd();
		z += rnd();
	}
};

Point p[N * 2];

struct Plane {
	int id[3];
	Plane() {}
	Plane(int id1, int id2, int id3) { id[0] = id1, id[1] = id2, id[2] = id3; }
	Point normal() const { return (p[id[1]] - p[id[0]]) ^ (p[id[2]] - p[id[0]]); }
};

bool is_above(Point pt, Plane f) { return sgn((pt - p[f.id[0]]) * f.normal()) > 0; }

int vis[N][N];

int convex_hull(int n, Plane fact[]) {
	int cnt = 0;
	fact[cnt++] = Plane(0, 1, 2);
	fact[cnt++] = Plane(0, 2, 1);
	Plane res[N * 2], del[N * 2];
	for (int i = 3; i < n; i++) {
		int cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < cnt; j++) {
			if (is_above(p[i], fact[j])) {
				del[cnt2++] = fact[j];
				for (int k = 0; k < 3; k++) vis[fact[j].id[k]][fact[j].id[(k + 1) % 3]] = i;
			} else {
				res[cnt1++] = fact[j];
			}
		}
		for (int j = 0; j < cnt2; j++) {
			Plane f = del[j];
			for (int k = 0; k < 3; k++) {
				if (vis[f.id[k]][f.id[(k + 1) % 3]] == i && vis[f.id[(k + 1) % 3]][f.id[k]] != i)
					res[cnt1++] = Plane(f.id[k], f.id[(k + 1) % 3], i);
			}
		}
		cnt = cnt1;
		for (int j = 0; j < cnt; j++) fact[j] = res[j];
	}
	return cnt;
}

Plane fact[N * 2];

void __() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y >> p[i].z;
		p[i].shake();
	}
	n = convex_hull(n, fact);
	double ans = 0;
	for (int i = 0; i < n; i++) {
		ans +=
			((p[fact[i].id[1]] - p[fact[i].id[0]]) ^ (p[fact[i].id[2]] - p[fact[i].id[0]])).len() /
			2;
	}
	cout << fixed << setprecision(3) << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}