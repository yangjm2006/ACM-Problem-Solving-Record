#include <bits/stdc++.h>

typedef long long ll;
const int N = 110;

using namespace std;

ll s1[N], s2[N];

void __() {
	int n, m, d;
	cin >> n >> m >> d;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= d; j++) {
			ll x;
			cin >> x;
			s1[j] += x;
			s2[j] += x * x;
		}
	}
	while (m--) {
		ll ans = 0;
		for (int i = 1; i <= d; i++) {
			ll x;
			cin >> x;
			ans += n * x * x + s2[i] - 2 * x * s1[i];
		}
		cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}