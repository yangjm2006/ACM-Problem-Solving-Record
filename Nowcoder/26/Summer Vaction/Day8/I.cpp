#include <bits/stdc++.h>

typedef long long ll;
const int N = 1e6 + 10;

using namespace std;

ll a[N];
void __() {
	ll n, m;
	cin >> n >> m;
	for (int i = 1; i <= 2 * n; i++) cin >> a[i];
	ll ans1 = 0, ans2 = 0;
	if (a[2] > a[1] + m) ans1++;
	if (a[2] + m > a[1]) ans2++;
	for (int i = 2; i <= n; i++) {
		if (a[i * 2 - 1] + a[i * 2] > 2 * a[1] + m) {
			if (min(a[i * 2 - 1], a[i * 2]) > a[1] + m)
				ans1 += 2;
			else
				ans1++;
		} else if (max(a[i * 2 - 1], a[i * 2]) > a[1] + m)
			ans1++;
		if (a[i * 2 - 1] + a[i * 2] + m > 2 * a[1]) {
			if (min(a[i * 2 - 1], a[i * 2]) + m > a[1])
				ans2 += 2;
			else
				ans2++;
		} else if (max(a[i * 2 - 1], a[i * 2]) + m > a[1])
			ans2++;
	}
	cout << ans1 << " " << ans2 << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}