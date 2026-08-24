#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 100;
int n, a[N];
void __() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j < i; j++)
			if (a[j] > a[i]) cnt++;
		ans += min(cnt, n - a[i] - cnt);
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}