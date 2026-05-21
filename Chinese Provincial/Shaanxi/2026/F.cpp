#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

void solve() {
	ll day[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
	ll t0, d, t1;
	cin >> d >> t0;
	t1 = (t0 + d) % 24;
	for (ll i = 0; i <= 24; i++) {
		if (day[(t0 + i) % 24] == 1 && day[(t1 + i) % 24] == 0) {
			cout << i << endl;
			return;
		}
	}
	cout << -1 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}