#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
	ll n;
	cin >> n;
	ll res = 0;
	vector<ll> v;
	while (n) {
		if (n == 1) {
			res++;
			break;
		}
		if (n % 2 == 1) {
			v.push_back((1ll << res));
			n++;
		}
		n /= 2;
		res++;
	}
	if (res % 2 == 0) v.push_back((1ll << (res - 1)));
	cout << v.size() << '\n';
	for (auto x : v) {
		cout << x << " ";
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}