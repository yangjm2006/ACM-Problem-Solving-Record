#include <bits/stdc++.h>
#define ll long long
using namespace std;
void __() {
	ll a, b, x, y;
	cin >> a >> b >> x >> y;
	if (a == x && b == y) {
		cout << "Yes\n";
	} else if (b == y) {
		if ((a & x) == x) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	} else if (a == x) {
		if ((b | y) == y) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	} else {
		cout << "No\n";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}