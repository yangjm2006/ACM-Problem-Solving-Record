#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e3 + 10;
int n;
ll a[N], k[N], ans = 1e18;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int o = 1; o <= n; o++) {
		for (int i = 1; i <= o; i++) {
			k[i] = 2 * (o - i + 1) + n - o;
		}
		for (int i = o + 1; i <= n; i++) {
			k[i] = 2 * (n - i + 1);
		}
		sort(k + 1, k + 1 + n);
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += a[i] * k[n - i + 1];
		}
		ans = min(ans, sum);
	}
	cout << ans / 2 << (ans % 2 == 1 ? ".5" : ".0");
	return 0;
}