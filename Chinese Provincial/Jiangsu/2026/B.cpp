#include <bits/stdc++.h>
#define ll long long
using namespace std;
void __() {
	ll x;
	cin >> x;
	ll l = sqrt(x);
	ll minn = LLONG_MAX;
	for (ll i = 0;; i++) {
		while (l * (l + i) > x) {
			l--;
		}
		ll c = x - l * (l + i);
		minn = min(minn, max(abs(l - c), abs(l + i - c)));
		if ((c >= l && c <= l + i) || minn == i) {
			cout << i << '\n';
			return;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}