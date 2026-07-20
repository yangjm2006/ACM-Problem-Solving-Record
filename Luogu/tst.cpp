#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
const int M = 330, N = 220000;
#define eps 1e-6
#define inf 0x3f3f3f3f

int n, S, T, idx = 1, op;
double in1, in2, in3, in4, cx, cy;
int to[N], nxt[N], head[N], w[N];
int cur[N], d[N];

void add(int u, int v, int c) {
	// cout << u << " " << v << "++\n";
	idx++;
	to[idx] = v;
	nxt[idx] = head[u];
	head[u] = idx;
	w[idx] = c;
	idx++;
	to[idx] = u;
	nxt[idx] = head[v];
	head[v] = idx;
	w[idx] = 0;
}

queue<int> q;

bool bfs() {
	memset(d, -1, sizeof d);
	while (!q.empty()) q.pop();
	cur[S] = head[S];
	q.push(S);
	d[S] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = head[now]; i; i = nxt[i]) {
			int v = to[i];
			if (~d[v] || !w[i]) continue;
			d[v] = d[now] + 1;
			cur[v] = head[v];
			if (v == T) return 1;
			q.push(v);
		}
	}
	return 0;
}

int dfs(int s, int lim) {
	if (s == T) return lim;
	int flow = 0;
	for (int& i = cur[s]; i && flow < lim; i = nxt[i]) {
		int v = to[i];
		if (d[v] != d[s] + 1 || !w[i]) continue;
		int t = dfs(v, min(w[i], lim - flow));
		if (!t) d[v] = -1;
		w[i] -= t;
		w[i ^ 1] += t;
		flow += t;
	}
	return flow;
}

int dinic() {  // dinic 板子
	int ans = 0, flow = 0;
	while (bfs() && (flow = dfs(S, inf))) {
		ans += flow;
		// cout << flow << "!!\n";
	}
	return ans;
}

struct Node {
	int type;  // 1代表圆，2代表矩形，3表示线段
	double x1, y1, x2, y2, r;
} a[M];

double dis_two_points(double x1, double y1, double x2, double y2) {	 // 计算两点距离
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool Point_Rec(double x1, double y1, Node a) {	// 判断点是否在矩形内
	return (x1 > a.x1 - eps) && (x1 < a.x2 + eps) && (y1 > a.y1 - eps) && (y1 < a.y2 + eps);
}

bool Lin_Int(Node a, Node b) {	// 判断特定直线是否相交
	return (a.x1 <= b.x1 && b.x1 <= a.x2) && (b.y1 <= a.y1 && a.y1 <= b.y2);
}

bool Cyc_Int(Node a, Node b) {	// 判断圆是否相交
	return dis_two_points(a.x1, a.y1, b.x1, b.y1) < a.r + b.r + eps;
}

bool Rec_Int(Node a, Node b) {	// 判断两个矩形是否相交
	bool res1 = Point_Rec(a.x1, a.y1, b);
	bool res2 = Point_Rec(a.x2, a.y2, b);
	bool res3 = Point_Rec(a.x1, a.y2, b);
	bool res4 = Point_Rec(a.x2, a.y1, b);  // 判点
	Node line1 = Node{3, a.x1, a.y1, a.x2, a.y1};
	Node line2 = Node{3, a.x1, a.y1, a.x1, a.y2};
	Node line3 = Node{3, a.x2, a.y1, a.x2, a.y2};
	Node line4 = Node{3, a.x1, a.y2, a.x2, a.y2};
	Node line5 = Node{3, b.x1, b.y1, b.x2, b.y1};
	Node line6 = Node{3, b.x1, b.y1, b.x1, b.y2};
	Node line7 = Node{3, b.x2, b.y1, b.x2, b.y2};
	Node line8 = Node{3, b.x1, b.y2, b.x2, b.y2};  // 两个矩形八条线
	bool res5 = Lin_Int(line1, line6) || Lin_Int(line1, line7);
	bool res6 = Lin_Int(line2, line5) || Lin_Int(line2, line8);
	bool res7 = Lin_Int(line3, line5) || Lin_Int(line3, line8);
	bool res8 = Lin_Int(line4, line6) || Lin_Int(line4, line8);	 // 线是否相交
	return res1 || res2 || res3 || res4 || res5 || res6 || res7 || res8;
}

bool check(Node a, Node b) {
	if (a.type == 1 && b.type == 1) return Cyc_Int(a, b);
	if (a.type == 2 && b.type == 2)
		return Rec_Int(a, b) || Rec_Int(b, a);	// 考虑一个矩形在另一个矩形内的情况
	if (a.type != b.type) {
		if (a.type == 2) swap(a, b);
		Node point = Node{1, a.x1, a.y1, 0, 0, 0};
		bool res1 = Cyc_Int(point, Node{1, b.x1, b.y1, 0, 0, a.r});
		bool res2 = Cyc_Int(point, Node{1, b.x2, b.y2, 0, 0, a.r});
		bool res3 = Cyc_Int(point, Node{1, b.x1, b.y2, 0, 0, a.r});
		bool res4 = Cyc_Int(point, Node{1, b.x2, b.y1, 0, 0, a.r});	 // 视为四个圆和两个矩形
		bool res5 = Point_Rec(a.x1, a.y1, Node{2, b.x1 - a.r, b.y1, b.x2 + a.r, b.y2});
		bool res6 = Point_Rec(a.x1, a.y1, Node{2, b.x1, b.y1 - a.r, b.x2, b.y2 + a.r});
		return res1 || res2 || res3 || res4 || res5 || res6;
	}
	return 0;
}

int main() {
	scanf("%lf%lf%d", &cx, &cy, &n);
	a[n + 2] = Node{2, -inf, cy, inf, inf};	 // 上下边界可以当作两个无穷大的矩形
	a[n + 1] = Node{2, -inf, -inf, inf, 0};
	S = 2 * n + 1;
	T = S + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d%lf%lf%lf", &op, &in1, &in2, &in3);
		if (op == 2) scanf("%lf", &in4);
		if (op == 1) a[i] = Node{1, in1, in2, 0, 0, in3};
		if (op == 2) a[i] = Node{2, in1, in2, in3, in4};
		add(2 * i - 1, 2 * i, 1);  // 入点和出点
		if (check(a[n + 1], a[i])) add(S, 2 * i - 1, 1);
		if (check(a[n + 2], a[i])) add(2 * i, T, 1);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++)  // 暴力加边即可
			if (check(a[i], a[j])) {
				add(2 * i, 2 * j - 1, 1);
				add(2 * j, 2 * i - 1, 1);
			}
	}
	// cout << idx << "!!!\n";
	cout << dinic() << '\n';
	return 0;
}
