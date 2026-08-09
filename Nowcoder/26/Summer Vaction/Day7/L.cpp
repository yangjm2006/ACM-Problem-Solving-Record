#include <bits/stdc++.h>
#define ll long long
using namespace std;
void __() {
	ll n, ans = 0;
	cin >> n;
	for (ll i = 1; i * i <= n; i++) {
		ll tmp = n - (i * i - 1);
		ans += tmp / (i * (i + 1)) * i;
		ans += min(tmp % (i * (i + 1)), i);
	}
	cout << ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}