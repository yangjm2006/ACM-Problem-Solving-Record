#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const ll inf = 1e17;

void __() {
	ll n, len = -inf;
	cin >> n;
	map<ll, ll> b;
	for (ll i = 1, a; i <= n; i++) {
		cin >> a;
		b[a]++;
		len = max(len, a);
	}
	ll base = inf, mex = 0;
	for (ll i = 0; i <= n; i++) {
		if (b.count(i)) {
			mex++;
		} else {
			break;
		}
	}
	if (len >= mex) {
		base = 0;
	}
	for (ll i = 0; i <= mex - 1; i++) {
		base = min(base, b[i]);
	}
	// cout << base << " " << mex << endl;
	ll ans = 0;
	for (ll i = 0; i <= len - 1; i++) {
		b[i] -= base;
		if (b[i] >= 1) {
			ans++;
		} else {
			break;
		}
	}
	cout << ans + base * mex + 1 << endl;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) {
		__();
	}
	return 0;
}