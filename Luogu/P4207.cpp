#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
double sqt(double x, double y) { return sqrt(x * x - y * y); }
struct node {
	int op;
	double x1, x2, o, r, k, b;
	node(int op, double x1, double x2, double a1, double a2) : op(op), x1(x1), x2(x2) {
		if (op == 1) {
			o = a1;
			r = a2;
		} else {
			k = a1;
			b = a2;
		}
	}
};
vector<node> vec;
double f(double x) {
	double ans = 0;
	for (auto v : vec) {
		if (x >= v.x1 && x <= v.x2) ans = max(ans, v.op == 1 ? sqt(v.r, x - v.o) : v.k * x + v.b);
	}
	return ans;
}
double simpson(double l, double r) { return (r - l) * (f(l) + f(r) + 4 * f((l + r) / 2)) / 6; }
double asr(double l, double r, double ans) {
	double mid = (l + r) / 2, ansl = simpson(l, mid), ansr = simpson(mid, r);
	return fabs(ansl + ansr - ans) <= 15 * eps ? ansl + ansr + (ansl + ansr - ans) / 15
											   : asr(l, mid, ansl) + asr(mid, r, ansr);
}
int n;
double alpha, h[10000], r[10000], o[10000];
void __() {
	cin >> n >> alpha;
	for (int i = 0; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> r[i];
	r[n + 1] = 0;
	for (int i = 1; i <= n + 1; i++) {
		o[i] = o[i - 1] + h[i - 1] / tan(alpha);
	}
	for (int i = 1; i <= n + 1; i++) {
		vec.push_back(node(1, o[i] - r[i], o[i] + r[i], o[i], r[i]));
	}
	double L = o[1] - r[1], R = o[1] + r[1];
	for (int i = 1; i <= n; i++) {
		L = min(L, o[i + 1] - r[i + 1]);
		R = max(R, o[i + 1] + r[i + 1]);
		if (abs(r[i + 1] - r[i]) >= o[i + 1] - o[i]) continue;
		double sinn = (r[i + 1] - r[i]) / (o[i + 1] - o[i]), x1 = o[i] - sinn * r[i],
			   x2 = o[i + 1] - sinn * r[i + 1];
		double y1 = sqt(r[i], x1 - o[i]), y2 = sqt(r[i + 1], x2 - o[i + 1]),
			   k = (y2 - y1) / (x2 - x1), b = y1 - k * x1;
		if (x2 >= x1) vec.push_back(node(2, x1, x2, k, b));
	}
	cout << fixed << setprecision(2) << 2 * asr(L, R, simpson(L, R));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}