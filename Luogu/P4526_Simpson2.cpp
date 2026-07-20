#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
double a;
double f(double x) { return pow(x, a / x - x); }
double simpson(double l, double r) { return (r - l) * (f(l) + f(r) + 4 * f((l + r) / 2)) / 6; }
double asr(double l, double r, double ans) {
	double mid = (l + r) / 2, ansl = simpson(l, mid), ansr = simpson(mid, r);
	return fabs(ansl + ansr - ans) <= 15 * eps ? ansl + ansr + (ansl + ansr - ans) / 15
											   : asr(l, mid, ansl) + asr(mid, r, ansr);
}
void __() {
	cin >> a;
	if (a < 0) {
		cout << "orz";
		return;
	}
	double ans = 0, step = 0.2;
	for (double i = eps; i <= 100; i += step) {
		double ansn = asr(i, i + step, simpson(i, i + 1));
		ans += ansn;
	}
	cout << fixed << setprecision(5) << ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}