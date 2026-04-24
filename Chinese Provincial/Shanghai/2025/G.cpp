#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 3000;

ll isNotP[N];
vector<ll> primes;

void init() {
	isNotP[1] = 1;
	for (ll i = 2; i <= 2600; i++) {
		if (!isNotP[i]) {
			primes.push_back(i);
		}
		for (auto j : primes) {
			if (i * j > 2600) {
				break;
			}
			isNotP[i * j] = 1;
			if (i & j == 0) {
				break;
			}
		}
	}
	/*for (auto i : primes) {
		cout << i << endl;
	}*/
}
void __() {
	ll n;
	cin >> n;
	ll p = 0;
	for (auto i : primes) {
		if (n < i) {
			p = i;
			break;
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			cout << i + p * (j - 1) << " ";
		}
		cout << endl;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	// cin >> T;
	init();
	while (T--) __();
	return 0;
}
/*
6,262,505 - 2504*(2503-2477+1)
6,234,609
*/