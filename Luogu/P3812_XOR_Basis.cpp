#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct XOR_Basis {
	ll p[70]{};
	bool insert(ll x) {
		for (int i = 62; i >= 0; i--) {
			if (!(x >> i & 1)) continue;
			if (!p[i]) {
				p[i] = x;
				return 1;
			}
			x ^= p[i];
		}
		return 0;
	}
	bool contain(ll x) {
		for (int i = 62; i >= 0; i--) {
			if (!(x >> i & 1)) continue;
			if (!p[i]) return 0;
			x ^= p[i];
		}
		return 1;
	}
	ll getmax() {
		ll ans = 0;
		for (int i = 62; i >= 0; i--) {
			ans = max(ans, ans ^ p[i]);
		}
		return ans;
	}
} B;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		if (!B.contain(x)) {
			B.insert(x);
		}
	}
	cout << B.getmax();
	return 0;
}