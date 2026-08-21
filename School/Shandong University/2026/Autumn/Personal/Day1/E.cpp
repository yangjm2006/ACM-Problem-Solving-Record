#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int a[N], ans[N];
void __() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ans[i] = 0;
	}
	int R = n, L = 1, cnt = 0;
	for (int k = 1; cnt < n - 1; k++) {
		int pos;
		for (int i = 1; i <= n; i++) {
			if (a[i] == k) {
				pos = i;
				break;
			}
		}
		bool flg = 1;
		for (int i = 1; i < pos; i++) {
			if (a[i] > k || a[i] == -1) flg = 0;
		}
		if (flg == 1) {
			int i;
			for (i = pos; i <= n; i++) {
				if (a[i] > k || a[i] == -1) break;
				if (a[i] == k) {
					if (k & 1)
						ans[i] = R--;
					else
						ans[i] = L++;
					cnt++;
				}
			}
			for (int j = n; j >= i; j--) {
				if (a[j] == k) {
					if (k & 1)
						ans[j] = R--;
					else
						ans[j] = L++;
					cnt++;
				}
			}
		} else {
			for (int j = n; j >= 1; j--) {
				if (a[j] == k) {
					if (k & 1)
						ans[j] = R--;
					else
						ans[j] = L++;
					cnt++;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << (ans[i] == 0 ? L : ans[i]) << " ";
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}