#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define PII pair<ll, ll>

const ll inf = 1e17;

bool cmp(PII a, PII b) { return a.first > b.first; }

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<PII> all, posi;
	ll ans[n + 10], cnt = 0, maxn = -inf;
	for (ll i = 1, t; i <= n; i++) {
		cin >> t;
		all.push_back({t, i});
		if (i == n) {
			cnt += t;
		} else {
			maxn = max(maxn, t);
		}
	}
	sort(all.begin(), all.end(), cmp);
	for (auto i : all) {
		if (i.first > 0 && i.second != n) {
			posi.push_back(i);
		} else {
			ans[i.second] = 1;
		}
	}
	ll index = 1, len = posi.size();
	if (len >= 2 * k - 1) {
		for (ll i = 0; i <= 2 * k - 3; i++) {  // 2k-2
			if (i % 2 == 0) {
				index++;
			}
			ans[posi[i].second] = index;
			cnt += posi[i].first;
		}
		for (ll i = 2 * k - 2; i <= len - 1; i++) {
			ans[posi[i].second] = 1;
		}
		cnt += posi[2 * k - 2].first;  // 2k-1
	} else if (len > 0 && len % 2 == 1) {
		for (ll i = 0; i <= len - 2; i++) {	 // len-1
			if (i % 2 == 0) {
				index++;
			}
			ans[posi[i].second] = index;
			cnt += posi[i].first;
		}
		ans[posi[len - 1].second] = 1;	// len
		cnt += posi[len - 1].first;
	} else if (len > 0 && len % 2 == 0) {
		for (ll i = 0; i <= len - 3; i++) {	 // len-2
			if (i % 2 == 0) {
				index++;
			}
			ans[posi[i].second] = index;
			cnt += posi[i].first;
		}
		ans[posi[len - 2].second] = ++index;  // len-1
		cnt += posi[len - 2].first;
		ans[posi[len - 1].second] = 1;	// len
		cnt += posi[len - 1].first;
	} else {
		for (ll i = 1; i <= n; i++) {
			ans[i] = 1;
		}
		cnt += maxn;
	}
	cout << cnt << endl;
	for (ll i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
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