#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N = 2e5 + 100;
const ll INF = 1e18;
ll a[N], s[N];
void __() {
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> a[i];
		a[i] *= 2;
		if (i % 2) {
			s[i] = s[i - 1] + a[i];
		} else {
			s[i] = s[i - 1] - a[i];
		}
		sum += a[i];
	}
	set<ll> val1, val2;
	ll ans = abs(s[2 * n]) / 2, tar = s[2 * n];
	val1.insert(INF);
	val1.insert(-INF);
	val2.insert(INF);
	val2.insert(-INF);
	for (int i = 1; i <= n; i++) {
		ll R = s[i * 2 - 1];
		ans = min(ans, abs(R - *val1.lower_bound(R - tar / 2) - tar / 2));
		ans = min(ans, abs(R - *prev(val1.upper_bound(R - tar / 2)) - tar / 2));
		val1.insert(R);
		R = s[i * 2];
		ans = min(ans, abs(R - *val2.lower_bound(R - tar / 2) - tar / 2));
		ans = min(ans, abs(R - *prev(val2.upper_bound(R - tar / 2)) - tar / 2));
		val2.insert(R);
	}
	cout << (sum / 2 - ans) / 2 << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll T = 1;
	cin >> T;
	while (T--) {
		__();
	}
	return 0;
}