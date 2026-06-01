#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<ll, ll>

const ll inf = 1e17, N = 1e5 + 10;

ll n, k, a[N], b[N];

bool cmp(PII a, PII b) { return a.first < b.first; }

ll check(ll t) {
	PII s[n + 10];
	for (ll i = 1; i <= n; i++) {
		if (t < a[i]) {
			continue;
		}
		s[i].first = b[i] - (t - a[i]);
		s[i].second = b[i] + (t - a[i]);
	}
	sort(s + 1, s + 1 + n, cmp);
	ll tar = -1;
	for (ll i = 1; i <= n; i++) {
		if (s[i].first <= tar + 1) {
			tar = max(tar, s[i].second);
		}
	}
	if (tar >= k) {
		return 1;
	}
	return 0;
}

void __() {
	cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}

	ll l = 0, r = 3e12 + 100, ans = inf;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}