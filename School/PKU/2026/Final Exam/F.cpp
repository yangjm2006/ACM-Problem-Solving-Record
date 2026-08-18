#include <bits/stdc++.h>

const int N = 1e6 + 100;
const int TRY_TIMES = 50;

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

int n;
int ned;
double rmin = 1e20;
vector<double> dis;
Point O;

void make(Point o) {
	for (int i = 0; i < n; i++) {
		dis[i] = (p[i] - o).len();
	}
	nth_element(dis.begin(), dis.begin() + ned - 1, dis.end());
	if (dis[ned - 1] < rmin) {
		rmin = dis[ned - 1];
		O = o;
	}
}

void __() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	for (int i = 0; i < n; i++) dis.push_back(0);
	ned = (n + 1) / 2;
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> pik(0, n - 1);
	for (int t = 0; t < TRY_TIMES; t++) {
		make(p[pik(rng)]);
	}
	Point o = O;
	double delta = rmin / 10;
	for (int i = -10; i <= 10; i++) {
		for (int j = -10; j <= 10; j++) {
			make(Point(o.x + delta * i, o.y + delta * j));
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