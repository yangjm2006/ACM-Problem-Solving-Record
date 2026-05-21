#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	string s;
	cin >> s;
	int n = s.length();
	int a[n];
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			a[i] = 0;

		} else {
			a[i] = 1;
		}
	}
	int t1 = 0, t2, cnt1 = 0, f1 = n, f2 = -1;
	int cnt2 = 0;
	if (n % 2 != 0) {
		t2 = t1;
	} else {
		t2 = t1 ^ 1;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != t1) {
			f1 = i;
			break;
		}
		t1 ^= 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (a[i] != t2) {
			f2 = i;
			break;
		}
		t2 ^= 1;
	}
	if (f1 > f2)
		cnt1 = 0;
	else
		cnt1 = f2 - f1 + 1;

	f1 = n, f2 = -1;
	t1 = 1;
	if (n % 2 != 0) {
		t2 = t1;
	} else {
		t2 = t1 ^ 1;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != t1) {
			f1 = i;
			break;
		}
		t1 ^= 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (a[i] != t2) {
			f2 = i;
			break;
		}
		t2 ^= 1;
	}
	if (f1 > f2)
		cnt2 = 0;
	else
		cnt2 = f2 - f1 + 1;

	int ans = min(cnt1, cnt2);
	cout << ans;
}