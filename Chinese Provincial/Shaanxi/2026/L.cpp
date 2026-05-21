#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int x;
	cin >> x;
	int num = 1;
	int high = x;
	while (high > 9) {
		high /= 10;
		num *= 10;
	}
	if (high == 1) {
		cout << x - high * num + 1 + num / 10;
	} else {
		cout << x - high * num + 1 + num;
	}
}