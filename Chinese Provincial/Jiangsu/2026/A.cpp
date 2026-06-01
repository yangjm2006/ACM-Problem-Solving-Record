#include <bits/stdc++.h>
using namespace std;
#define int long long
// 二分模板
#define PII pair<int, int>

bool cmp(PII a, PII b) { return a.second < b.second; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<PII> a;
	for (int i = 1; i <= n; i++) {
		int x1, x2;
		cin >> x1 >> x2;
		a.push_back({x1, x2});
	}
	sort(a.begin(), a.end(), cmp);
	int l = 0, r = 2 * k + 100;
	while (l < r) {
		int mid = (l + r) >> 1;
		int tar = 0;
		int flag = 0;
		for (auto [t, pos] : a) {
			if (t > mid) continue;
			if (pos - (mid - t) <= tar) {
				tar = max(tar, pos + (mid - t) + 1);
			}
		}
		if (tar > k) {
			flag = 1;
		}
		if (flag == 0) {
			// 首先要让l过来的条件
			// 使得mid必不是答案的条件
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	cout << l;
	return 0;
}