#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	ll x = 0;
	int f = 0, ch = 0;
	while (ch < 48 || ch > 57) f = (ch == '-'), ch = getchar();
	while (ch > 47 && ch < 58) x = (x << 3) + (x << 1) + (ch & 15), ch = getchar();
	return f ? -x : x;
}
inline void write(ll x, char end = '\n') {
	if (x == 0) {
		putchar('0');
		putchar(end);
		return;
	}
	if (x < 0) putchar('-'), x = -x;
	int ch[40] = {0}, cnt = 0;
	while (x) {
		ch[cnt++] = (int)(x % 10);
		x /= 10;
	}
	while (cnt--) putchar(ch[cnt] + 48);
	putchar(end);
}
const int N = 5e5 + 5;
int n;
int x[N], y[N];
double dis[N];
inline double dist(double x1, double y1, double x2, double y2) {
	double dx = x2 - x1, dy = y2 - y1;
	return sqrt(dx * dx + dy * dy);
}
double calc(double tx, double ty) {
	for (int i = 1; i <= n; ++i) dis[i] = dist(tx, ty, x[i], y[i]);
	nth_element(dis + 1, dis + ((n + 1) >> 1), dis + n + 1);
	return dis[(n + 1) >> 1];
}
int p[N];
void solve2() {
	double ansx = 0, ansy = 0, ansr = 1000000000;
	for (int i = 1; i <= 30; ++i) p[i] = 1;
	random_shuffle(p + 1, p + n + 1);
	double r0 = -1;
	int s0 = 0;
	for (int i = 1; i <= n; ++i) {
		if (p[i]) {
			double dk = calc(x[i], y[i]);
			if (r0 < 0 || dk < r0) {
				r0 = dk;
				s0 = i;
			}
		}
	}
	double nx = x[s0], ny = y[s0];
	double delta = r0 / 10;
	for (int i = -10; i <= 10; ++i) {
		for (int j = -10; j <= 10; ++j) {
			double gx = nx + i * delta, gy = ny + j * delta;
			double R = calc(gx, gy);
			if (R < ansr) {
				ansr = R;
				ansx = gx;
				ansy = gy;
			}
		}
	}
	printf("%.6lf %.6lf %.6lf\n", ansx, ansy, ansr);
}
int main() {
	n = read();
	for (int i = 1; i <= n; ++i) x[i] = read(), y[i] = read();
	solve2();
	return 0;
}