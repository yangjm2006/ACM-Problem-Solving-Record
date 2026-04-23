#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef long long ll;

using namespace std;
using namespace __gnu_pbds;

const int N = 5e4 + 100;
const double eps = 1e-9;

int sgn(double x) {
	if (fabs(x) <= eps) return 0;
	return x > 0 ? 1 : -1;
}

struct Point {
	ll x, y;
	Point(ll x, ll y) : x(x), y(y) {}
	bool operator<(const Point& other) const { return x < other.x; }
	bool operator==(const Point& other) const { return x == other.x && y == other.y; }
} a[N];

ll X;

struct Line {
	Point p1, p2;
	Line(Point tp1, Point tp2) : p1(min(tp1, tp2)), p2(max(tp1, tp2)) {}
	bool is_point() const { return p1 == p2; }
	bool operator<(const Line& other) const {}
};
class {
private:
	struct SegmentTree {
		int ls, rs;
		tree<Line, null_type, less<Line>, rb_tree_tag, tree_order_statistics_node_update> t;
	} tr[N * 60];
	void insert() {}
	void erase() {}

public:
};

void insert(Point p1, Point p2) {}

void erase(Point p1, Point p2) {}

int query(Point p) {}

const ll RANGE = 1e9;

ll mapping(Point p) { return Point(p.x << 1, p.y); }

ll unmapping(ll x) { return x >> 1; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(nullptr));
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	for (int i = 0; i < n; i++) {
		insert(a[i], a[(i + 1) % n]);
	}
	cin >> m;
	while (m--) {
		int op;
		cin >> op;
	}
	return 0;
}