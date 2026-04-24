#include <bits/stdc++.h>
#define ll long long
#define int __int128
using namespace std;
const int N = 1e6 + 100;
ll a[N];
void __() {
	ll n1, x1, y1;
	cin >> n1 >> x1 >> y1;
	int n = n1, x = x1, y = y1;

	for (int i = 1; i <= n; i++) cin >> a[i];
	int sum = 0;
	int ans = 0;
	for (int j = 35; j >= 0; j--) {
		sum *= 2;
		for (int i = 1; i <= n; i++) {
			int bbti = ((a[i] >> j) & 1);
			sum += bbti;
			ans += bbti * x;
		}
		if (sum > 0 && j != 0) {
			ans += min(y, sum * x);
		}
	}

	cout << (ll)ans << '\n';
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	while (T--) __();
	return 0;
}