#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k, q;
	cin >> n >> k >> q;
	int a[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int b1[n + 1] = {};
	int b2[n + 1] = {};
	for (int i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] < 0) {
			b1[i] = 1;
		} else {
			b1[i] = 0;
		}
		b1[i] += b1[i - 1];
	}
	for (int i = n - 1; i >= 1; i--) {
		if (a[i] - a[i + 1] < 0) {
			b2[i] = 1;
		} else {
			b2[i] = 0;
		}
		b2[i] += b2[i + 1];
	}

	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (y1 <= a[x1]) {
			y1 = 1;
		} else {
			y1 = (y1 - a[x1] - 1) / k + 1 + 1;
		}
		if (y2 <= a[x2]) {
			y2 = 1;
		} else {
			y2 = (y2 - a[x2] - 1) / k + 1 + 1;
		}
		if (y2 < y1) {
			swap(x1, x2);
			swap(y1, y2);
		}
		// cout << y1 << ' ' << y2;
		int xx = abs(x1 - x2);
		int yy = abs(y1 - y2);
		int sheng;
		if (x2 > x1) {
			sheng = b1[x2] - b1[x1];
		} else {
			sheng = b2[x2] - b2[x1];
		}
		// cout << sheng << endl;
		sheng = min(sheng, yy);
		int ans = xx + yy - sheng;
		cout << ans << endl;
	}
}