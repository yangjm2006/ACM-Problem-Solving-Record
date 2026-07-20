#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
double a, b, c, d;
double f(double x) { return (c * x + d) / (a * x + b); }
double simpson(double l, double r) { return (r - l) * (f(l) + f(r) + 4 * f((l + r) / 2)) / 6; }
double asr(double l, double r, double ans) {
	double mid = (l + r) / 2, ansl = simpson(l, mid), ansr = simpson(mid, r);
	return fabs(ansl + ansr - ans) <= 15 * eps ? ansl + ansr + (ansl + ansr - ans) / 15
											   : asr(l, mid, ansl) + asr(mid, r, ansr);
}
void __() {
	cin >> a >> b >> c >> d;
	double L, R;
	cin >> L >> R;
	cout << fixed << setprecision(6) << asr(L, R, simpson(L, R));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}