#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N], dp[N], n, k;
bool check(int x) {
	dp[0] = a[0] >= x ? 1 : -1;
	for (int i = 1; i < n; i++) {
		int val = a[i] >= x ? 1 : -1;
		if (i % k == 0) {
			dp[i] = max(dp[i - k], val);
		} else {
			dp[i] = dp[i - 1] + val;
			if (i > k) dp[i] = max(dp[i], dp[i - k]);
		}
	}
	return dp[n - 1] > 0;
}
void __() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	int l = 1, r = 1e9;
	while (l < r) {
		int mid = (l + r) / 2 + 1;
		if (check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	cout << l << '\n';
}
int main() {
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}