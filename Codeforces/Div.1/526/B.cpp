#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;
typedef long long ll;

bool vis1[N], vis2[N];

void __() {
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == 'b') vis1[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == 'b') vis2[i] = 1;
	}
	ll cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt2 - cnt1 + 1 < k) {
			cnt1 <<= 1;
			cnt2 <<= 1;
			if (vis1[i]) cnt1++;
			if (vis2[i]) cnt2++;
		}
		ans += min(cnt2 - cnt1 + 1, k);
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}