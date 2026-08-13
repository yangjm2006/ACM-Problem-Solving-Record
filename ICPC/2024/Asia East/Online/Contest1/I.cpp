#include <bits/stdc++.h>

typedef long long ll;
const int N = 3e3 + 10;

using namespace std;

struct Point {
	ll x, y, z;
	Point() {}
	Point(ll x, ll y, ll z) : x(x), y(y), z(z) {}
	Point operator-(const Point& other) const {
		return Point(x - other.x, y - other.y, z - other.z);
	}
	Point operator+(const Point& other) const {
		return Point(x + other.x, y + other.y, z + other.z);
	}
	ll operator*(const Point& other) const { return x * other.x + y * other.y + z * other.z; }
	Point operator^(const Point& other) const {
		return Point(y * other.z - z * other.y, z * other.x - x * other.z,
					 x * other.y - y * other.x);
	}
};

Point p[N * 2];

struct Plane {
	int id[3];
	Plane() {}
	Plane(int id1, int id2, int id3) { id[0] = id1, id[1] = id2, id[2] = id3; }
	Point normal() const { return (p[id[1]] - p[id[0]]) ^ (p[id[2]] - p[id[0]]); }
};

bool is_above(Point pt, Plane f) { return (pt - p[f.id[0]]) * f.normal() > 0; }

int vis[N][N], vistim;

Plane res[N * 2], del[N * 2];
int convex_hull(int n, Plane fact[]) {
	int cnt = 0;
	fact[cnt++] = Plane(0, 1, 2);
	fact[cnt++] = Plane(0, 2, 1);
	for (int i = 3; i < n; i++) {
		vistim++;
		int cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < cnt; j++) {
			if (is_above(p[i], fact[j])) {
				del[cnt2++] = fact[j];
				for (int k = 0; k < 3; k++) vis[fact[j].id[k]][fact[j].id[(k + 1) % 3]] = vistim;
			} else {
				res[cnt1++] = fact[j];
			}
		}
		for (int j = 0; j < cnt2; j++) {
			Plane f = del[j];
			for (int k = 0; k < 3; k++) {
				if (vis[f.id[k]][f.id[(k + 1) % 3]] == vistim &&
					vis[f.id[(k + 1) % 3]][f.id[k]] != vistim)
					res[cnt1++] = Plane(f.id[k], f.id[(k + 1) % 3], i);
			}
		}
		cnt = cnt1;
		for (int j = 0; j < cnt; j++) fact[j] = res[j];
	}
	return cnt;
}

Plane fact[N * 2];

bool used[N * 2];

void print(__int128 x) {
	if (x == 0) return cout << '0', void();
	string s;
	while (x) {
		s += char('0' + x % 10);
		x /= 10;
	}
	reverse(s.begin(), s.end());
	cout << s;
}

void __() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y >> p[i].z;
	}
	random_shuffle(p, p + n);
	__int128 ans = 0;
	while (n > 3) {
		int m = convex_hull(n, fact);
		for (int i = 0; i < m; i++) {
			ans += abs((p[fact[i].id[0]] - p[0]) * ((p[fact[i].id[1]] - p[fact[i].id[0]]) ^
													(p[fact[i].id[2]] - p[fact[i].id[0]])));
			used[fact[i].id[0]] = used[fact[i].id[1]] = used[fact[i].id[2]] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (!used[i]) p[cnt++] = p[i];
		for (int i = 0; i < n; i++) used[i] = 0;
		n = cnt;
	}
	print(ans);
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}