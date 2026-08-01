#include <bits/stdc++.h>
#define double long double
using namespace std;
const double eps = 1e-6;
const int N = 2e5 + 100;
int sgn(double x) { return abs(x) <= eps ? 0 : (x < 0 ? -1 : 1); }
struct Point {
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	bool operator==(const Point& other) const {
		return sgn(x - other.x) == 0 && sgn(y - other.y) == 0;
	}
	bool operator<(const Point& other) const {
		return sgn(x - other.x) < 0 || (sgn(x - other.x) == 0 && sgn(y - other.y) < 0);
	}
	Point operator-() const { return Point(-x, -y); }
	Point operator+(const Point& other) const { return Point(x + other.x, y + other.y); }
	Point operator-(const Point& other) const { return Point(x - other.x, y - other.y); }
	Point operator*(const double& k) const { return Point(x * k, y * k); }
	Point operator/(const double& k) const { return Point(x / k, y / k); }
	double operator^(const Point& other) const { return x * other.y - y * other.x; }
	double operator*(const Point& other) const { return x * other.x + y * other.y; }
	double len() const { return hypot(x, y); }
	Point ide() const { return Point(x, y) / len(); }
	Point ver() const { return Point(-y, x) / len(); }
};
double distance(const Point& p1, const Point& p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }
struct Line {
	Point start, end;
	double angle;
	Line() {}
	Line(Point s, Point t) : start(s), end(t), angle(atan2(t.y - s.y, t.x - s.x)) {}
	bool operator<(const Line& other) const {
		if (sgn(angle - other.angle) == 0) return ((end - start) ^ (other.end - start)) < 0;
		return angle < other.angle;
	}
	double operator^(const Line& other) const { return (end - start) ^ (other.end - other.start); }
};
Point getPoint(Line l1, Line l2) {
	double s1 = (l2.end - l1.start) ^ (l1.end - l1.start),
		   s2 = (l2.start - l1.start) ^ (l1.end - l1.start);
	return (l2.start * s1 - l2.end * s2) / (s1 - s2);
}
bool isRight(Line l, Point p) { return sgn((l.start - p) ^ (l.end - p)) < 0; }
Line getLine(Line l1, Line l2) {
	Point p1, p2;
	double len1 = (l1.end - l1.start).len(), len2 = (l2.end - l2.start).len();
	if (sgn(l1.angle - l2.angle) == 0 || sgn(l1.angle - Line(l2.end, l2.start).angle) == 0) {
		Point ver = (l1.end - l1.start).ver(), ide = (l1.end - l1.start).ide();
		Line l(l1.start, l1.start + ver);
		Point p = getPoint(l, l2);
		p1 = l1.start + (p - l1.start) * len2 / (len1 + len2);
		p2 = p1 - ide;
		return Line(p1, p2);
	} else {
		p1 = getPoint(l1, l2);
		double angle = (l1.angle + Line(l2.end, l2.start).angle) / 2;
		Point vec = Point(cos(angle), sin(angle)).ver();
		Point pn = (l1.start == p1) ? l1.end : l1.start;
		Line l(pn, pn + vec);
		Point p = getPoint(l, l2);
		p2 = pn + ((p - pn) * len2 / (len1 + len2));
		if ((l1 ^ l2) < 0) swap(p1, p2);
	}
	return Line(p1, p2);
}
Line deq[N];
int Intersection_of_Half_Planes(int n, Line* l, Point* isc) {
	sort(l, l + n);
	int tot = 1;
	for (int i = 1; i < n; i++) {
		if (sgn(l[i].angle - l[i - 1].angle) != 0) {
			l[tot++] = l[i];
		}
	}
	int top = 1, back = 0;
	deq[0] = l[0];
	deq[1] = l[1];
	for (int i = 2; i < tot; i++) {
		while (back < top && isRight(l[i], getPoint(deq[top], deq[top - 1]))) top--;
		while (back < top && isRight(l[i], getPoint(deq[back], deq[back + 1]))) back++;
		deq[++top] = l[i];
	}
	while (back < top && isRight(deq[back], getPoint(deq[top], deq[top - 1]))) top--;
	while (back < top && isRight(deq[top], getPoint(deq[back], deq[back + 1]))) back++;
	for (int i = back; i < top; i++) {
		isc[i - back] = getPoint(deq[i], deq[i + 1]);
	}
	if (top - back > 1) isc[top - back] = getPoint(deq[top], deq[back]);
	return top - back + 1;
}
int n, cnt;
Line l[N];
Point isc[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<Point> vec;
	for (int i = 1; i <= n; i++) {
		double x, y;
		cin >> x >> y;
		double xx = x, yy = y;
		vec.push_back(Point(xx, yy));
	}
	double sum = 0;
	for (int i = 0; i < n; i++) {
		l[cnt++] = Line(vec[i], vec[(i + 1) % n]);
		sum += (vec[i] - vec[0]) ^ (vec[(i + 1) % n] - vec[0]);
	}
	for (int i = 1; i < n; i++) {
		l[cnt++] = getLine(l[0], l[i]);
	}
	cnt = Intersection_of_Half_Planes(cnt, l, isc);
	double ans = 0;
	for (int i = 0; i < cnt; i++) ans += (isc[i] - isc[0]) ^ (isc[(i + 1) % cnt] - isc[0]);
	cout << fixed << setprecision(4) << fabs(ans) / fabs(sum);
	return 0;
}