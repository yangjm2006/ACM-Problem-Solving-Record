#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
	ll n;
	string s;
	cin >> n >> s;
	vector<ll> ge, noge;
	for (ll i = 0; i <= n - 3; i++) {
		ll id = i + 2;
		if (s[i] == '1') {
			ge.push_back(id);
		} else {
			noge.push_back(id);
		}
	}
	ll geL = ge.size(), nogeL = noge.size();
	if (nogeL >= 2) {
		cout << n << endl;
		cout << 1 << " " << noge[0] << endl;
		for (ll i = 1; i <= nogeL - 1; i++) {
			cout << noge[i - 1] << " " << noge[i] << endl;
		}
		cout << 1 << " " << noge[nogeL - 1] << endl;
		if (geL >= 1) {
			cout << 1 << " " << ge[0] << endl;
			for (ll i = 1; i <= geL - 1; i++) {
				cout << ge[i - 1] << " " << ge[i] << endl;
			}
			cout << n << " " << ge[geL - 1] << endl;
		} else {
			cout << 1 << " " << n << endl;
		}
	} else if (nogeL == 1 && noge[0] == n - 1) {
		cout << n - 1 << endl;
		cout << 1 << " " << noge[0] << endl;
		if (geL >= 1) {
			cout << 1 << " " << ge[0] << endl;
			for (ll i = 1; i <= geL - 1; i++) {
				cout << ge[i - 1] << " " << ge[i] << endl;
			}
			cout << n << " " << ge[geL - 1] << endl;
		} else {
			cout << 1 << " " << n << endl;
		}
	} else {
		cout << -1 << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}