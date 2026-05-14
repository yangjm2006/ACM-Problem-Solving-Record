#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll cnt0, cnt1, maxx, minn;
void solve() {
	ll n;
	cin >> n;
	maxx = -1;
	minn = 2e9;
	cnt0 = cnt1 = 0;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		if (x > maxx) {
			maxx = x;
			cnt1 = 0;
		}
		if (x == maxx) cnt1++;
		if (x < minn) {
			minn = x;
			cnt0 = 0;
		}
		if (x == minn) cnt0++;
		if (cnt0 + cnt1 == i) {
			if (cnt0 == 1) {
				cout << maxx * 2 << " ";
			} else {
				cout << maxx + minn << " ";
			}
		} else {
			cout << maxx + minn << " ";
		}
	}
	cout << '\n';
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}