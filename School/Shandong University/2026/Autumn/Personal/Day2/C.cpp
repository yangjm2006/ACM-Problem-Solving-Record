#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n, m, tot, num00, num01, num10, num11;
ll get(ll x) {
	for (ll i = 0; i * (i - 1) / 2 <= x; i++) {
		if (i * (i - 1) / 2 == x) return i;
	}
	return -1;
}
string ans;
bool make() {
	tot = n + m;
	if (tot * (tot - 1) / 2 != num00 + num01 + num10 + num11) {
		return 0;
	}
	if (n == 0) {
		if (num00 != 0 || num01 != 0 || num10 != 0) return 0;
		for (int i = 1; i <= m; i++) ans += '1';
		return 1;
	}
	if (m == 0) {
		if (num11 != 0 || num01 != 0 || num10 != 0) return 0;
		for (int i = 1; i <= n; i++) ans += '0';
		return 1;
	}
	ll tar = num10;
	if (tar == n * m) {
		for (int i = 1; i <= m; i++) ans += '1';
		for (int i = 1; i <= n; i++) ans += '0';
		return 1;
	}
	for (int i = 1; i <= tar / n; i++) ans += '1';
	for (int i = 1; i <= n - tar % n; i++) ans += '0';
	ans += '1';
	for (int i = 1; i <= tar % n; i++) ans += '0';
	for (int i = 1; i <= m - tar / n - 1; i++) ans += '1';
	return 1;
}
void __() {
	cin >> num00 >> num01 >> num10 >> num11;
	n = get(num00);
	m = get(num11);
	if (n == -1 || m == -1) {
		cout << "Impossible";
		return;
	}
	vector<ll> vec1, vec2;
	vec1.push_back(n);
	vec2.push_back(m);
	if (n == 0) vec1.push_back(1);
	if (m == 0) vec2.push_back(1);
	for (ll x : vec1) {
		for (ll y : vec2) {
			if (x != 0 || y != 0) {
				n = x;
				m = y;
				if (make()) {
					cout << ans;
					return;
				}
			}
		}
	}
	cout << "Impossible";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}