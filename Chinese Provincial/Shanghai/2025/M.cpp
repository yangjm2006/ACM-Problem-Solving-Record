#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 3e5 + 100;
__int128 ans[N][40];
ll a[N];
void __() {
	ll n, x, y;
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 35; j++) {
			ans[i][j] = x * (__popcount(a[i] % (1ll << j)) + a[i] / (1ll << j));
		}
		for (int j = 1; j <= 35; j++) {
			ans[i][j] = min(ans[i][j - 1], ans[i][j]);
		}
	}
	__int128 tot_res = 1e18;
	for (int j = 0; j <= 35; j++) {
		__int128 res = j * y;
		for (int i = 1; i <= n; i++) res += ans[i][j];
		tot_res = min(tot_res, res);
	}
	cout << (ll)tot_res << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	while (T--) __();
	return 0;
}