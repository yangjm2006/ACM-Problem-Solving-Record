#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int a[N], pos[N];
void __() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		pos[a[i]] = i;
	}
	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		if (pos[k] < l || pos[k] > r) {
			cout << "-1 ";
			continue;
		}
		int bigger = 0, smaller = 0, need_big = 0, need_small = 0;
		while (l < r) {
			int mid = l + r >> 1;
			if (pos[k] == mid)
				break;
			else if (pos[k] > mid) {
				smaller++;
				if (a[mid] > k) need_small++;
				l = mid + 1;
			} else {
				bigger++;
				if (a[mid] < k) need_big++;
				r = mid - 1;
			}
		}
		if (smaller > k - 1 || bigger > n - k) {
			cout << "-1 ";
			continue;
		}
		cout << min(need_big, need_small) * 2 + abs(need_big - need_small) * 2 << " ";
	}
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