#include <bits/stdc++.h>

const int N = 1e6 + 100;
const int TRY_TIMES = 100;

using namespace std;

struct Point {
	double x, y;
	int id;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	bool operator<(const Point& other) const {
		return x * x + y * y < other.x * other.x + other.y * other.y;
	}
	bool operator>(const Point& other) const {
		return x * x + y * y > other.x * other.x + other.y * other.y;
	}
	double operator*(const Point& other) const { return x * other.x + y * other.y; }
	Point operator+(const Point& other) const { return Point(x + other.x, y + other.y); }
	Point operator-(const Point& other) const { return Point(x - other.x, y - other.y); }
	double len() const { return hypot(x, y); }
} p[N];

void __() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	// random_shuffle(p, p + n);
	int ned = (n + 1) / 2;
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> pik(0, n - 1);
	vector<double> dis(n);
	double rmin = 1e20;
	Point O;
	for (int t = 0; t < TRY_TIMES; t++) {
		Point o(0, 0);
		for (int tt = 0; tt < 2; tt++) {
			int id = pik(rng);
			o.x += p[id].x / 2;
			o.y += p[id].y / 2;
		}
		for (int i = 0; i < n; i++) {
			dis[i] = (p[i] - o).len();
		}
		nth_element(dis.begin(), dis.begin() + ned - 1, dis.end());
		if (dis[ned - 1] < rmin) {
			rmin = dis[ned - 1];
			O = o;
		}
	}
	cout << fixed << setprecision(7) << O.x << " " << O.y << " " << rmin << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}