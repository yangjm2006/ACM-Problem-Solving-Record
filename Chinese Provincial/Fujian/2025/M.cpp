#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
	string ans[] = {"",	   "FZU", "FNU",  "FZU", "FZU", "FAFU",
					"HQU", "MJU", "XMUT", "QNU", "JMU", "FZU"};
	ll t;
	cin >> t;
	cout << ans[t] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}