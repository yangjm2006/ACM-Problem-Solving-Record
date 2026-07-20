#include <bits/stdc++.h>
template <class... Ts>
struct overloaded : Ts... {
	using Ts::operator()...;
};
template <class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;
using namespace std;
const int N = 2e6 + 100;
const int INF = 1e9;
const double eps = 1e-9;
struct Edge {
	int v, c, nxt;
} e[N];
int _ = 1, head[N];
void adde(int u, int v, int c) {
	e[++_].v = v;
	e[_].c = c;
	e[_].nxt = head[u];
	head[u] = _;
	e[++_].v = u;
	e[_].c = 0;
	e[_].nxt = head[v];
	head[v] = _;
}
int dis[N], S, T, cur[N];
bool bfs() {
	for (int i = 1; i <= T; i++) {
		dis[i] = INF;
		cur[i] = head[i];
	}
	queue<int> q;
	q.push(S);
	dis[S] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].v, c = e[i].c;
			if (c > 0 && dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	return dis[T] != INF;
}
int dfs(int u, int flow) {
	if (u == T) return flow;
	int res = 0;
	for (int& i = cur[u]; i && flow; i = e[i].nxt) {
		int v = e[i].v, c = e[i].c;
		if (c > 0 && dis[v] == dis[u] + 1) {
			int fw = dfs(v, min(c, flow));
			flow -= fw;
			res += fw;
			e[i].c -= fw;
			e[i ^ 1].c += fw;
		}
	}
	return res;
}
int dinic() {
	int res = 0, tmp;
	while (bfs() && (tmp = dfs(S, INF))) res += tmp;
	return res;
}
struct Point {
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	Point operator-(const Point& other) const { return Point(x - other.x, y - other.y); }
};
struct Line {
	double a, b;
	Line() {}
	Line(double a, double b) : a(a), b(b) {}
};
bool is_Cross(Line a, Line b) { return max(a.a, b.a) <= min(a.b, b.b) + eps; }
double distance(Point a, Point b) { return hypot(a.x - b.x, a.y - b.y); }
struct Circle {
	Point o;
	double r;
	Circle() {}
	Circle(double x, double y, double r) : o(x, y), r(r) {}
};
struct Rectangle {
	double x1, x2, y1, y2;
	Rectangle() {}
	Rectangle(double x1, double x2, double y1, double y2) : x1(x1), x2(x2), y1(y1), y2(y2) {}
};
bool is_Cross(Circle a, Circle b) { return distance(a.o, b.o) <= a.r + b.r + eps; }
bool is_Cross(Rectangle a, Rectangle b) {
	return is_Cross(Line(a.x1, a.x2), Line(b.x1, b.x2)) &&
		   is_Cross(Line(a.y1, a.y2), Line(b.y1, b.y2));
}
bool is_Cross(Circle a, Rectangle b) {
	Point p = a.o - Point((b.x1 + b.x2) / 2, (b.y1 + b.y2) / 2);
	p.x = abs(p.x);
	p.y = abs(p.y);
	double rx = (b.x2 - b.x1) / 2, ry = (b.y2 - b.y1) / 2, r = a.r;
	if (p.x <= rx) return p.y <= ry + r + eps;
	if (p.x > rx + r) return 0;
	return p.y <= sqrt(r * r - (p.x - rx) * (p.x - rx)) + ry + eps;
}
bool is_Cross(Rectangle a, Circle b) { return is_Cross(b, a); }
int n;
double X, Y;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> X >> Y >> n;
	S = n * 2 + 1;
	T = S + 1;
	vector<variant<Circle, Rectangle>> vec;
	for (int i = 1; i <= n; i++) {
		int op;
		cin >> op;
		int u1 = i * 2 - 1, u2 = i * 2;
		adde(u1, u2, 1);
		if (op == 1) {
			double x, y, r;
			cin >> x >> y >> r;
			vec.push_back(Circle(x, y, r));
			if (is_Cross(Rectangle(-INF, INF, -INF, 0), Circle(x, y, r))) {
				adde(S, u1, 1);
			}
			if (is_Cross(Rectangle(-INF, INF, Y, INF), Circle(x, y, r))) {
				adde(u2, T, 1);
			}
		} else {
			double x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			vec.push_back(Rectangle(x1, x2, y1, y2));
			if (is_Cross(Rectangle(-INF, INF, -INF, 0), Rectangle(x1, x2, y1, y2))) {
				adde(S, u1, 1);
			}
			if (is_Cross(Rectangle(-INF, INF, Y, INF), Rectangle(x1, x2, y1, y2))) {
				adde(u2, T, 1);
			}
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		for (int j = i + 1; j < vec.size(); j++) {
			if (std::visit(
					overloaded{[](Circle a, Circle b) -> bool { return is_Cross(a, b); },
							   [](Rectangle a, Rectangle b) -> bool { return is_Cross(a, b); },
							   [](Circle a, Rectangle b) -> bool { return is_Cross(a, b); },
							   [](Rectangle a, Circle b) -> bool { return is_Cross(a, b); }},
					vec[i], vec[j])) {
				int u1 = i * 2 + 1, u2 = i * 2 + 2, v1 = j * 2 + 1, v2 = j * 2 + 2;
				adde(u2, v1, 1);
				adde(v2, u1, 1);
			}
		}
	}
	cout << dinic();
	return 0;
}