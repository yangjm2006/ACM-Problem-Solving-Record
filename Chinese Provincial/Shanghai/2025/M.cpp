#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6 + 100;
ll ans[N][40], a[N];
void __() {
	ll n, x, y;
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 35; j++) {
			ans[i][j] = x * (a[i] % (1 << j) + a[i] / (1 << j));
		}
		for (int j = 1; j <= 35; j++) {
			ans[i][j] = min(ans[i][j - 1], ans[i][j]);
		}
	}
	ll tot_res = 1e18;
	for (int j = 0; j <= 35; j++) {
		ll res = j * y;
		for (int i = 1; i <= n; i++) res += ans[i][j];
		cout << j << " " << res << "!!!\n";
		tot_res = min(tot_res, res);
	}
	cout << tot_res << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	while (T--) __();
	return 0;
}