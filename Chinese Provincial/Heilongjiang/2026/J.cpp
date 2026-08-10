#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void __() {
	int n, k;
	cin >> n >> k;
	ll sum = 0;
	for (int i = 1; i <= n - 1; i++) {
		ll t;
		cin >> t;
		sum += t;
	}
	cout << sum + k / 4 << "." << k % 4 * 100 / 4 << "0000000\n";
}
int main() {
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}