#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

bool cmp(PII a, PII b) { return a.first > b.first; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	int a[n + 1];
	vector<PII> b;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == n) break;
		b.push_back({a[i], i});
	}
	multiset<int> s;
	s.insert(n);
	int spe = 0;
	sort(b.begin(), b.end(), cmp);
	s.insert(b[0].second);
	for (int i = 1; i + 1 < b.size(); i += 2) {
		if (s.size() >= 2 * k) break;
		if (b[i].first > 0) {
			s.insert(b[i].second);
		} else {
			break;
		}
		if (b[i + 1].first >= 0) {
			s.insert(b[i + 1].second);
		} else {
			spe = 1;
			break;
		}
	}
	int ind = 1;
	int cnt = 0;
	int sum = 0;
	for (int c : s) {
		sum += a[c];
	}
	cout << sum << endl;
	if (spe) {
		ind = 1, cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (s.find(i) != s.end()) {
				cout << ind << ' ';
				cnt++;
				s.erase(i);
				if (cnt >= 2) {
					ind++;
					cnt = 0;
				}
			} else {
				cout << 1 << ' ';
			}
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << ind << ' ';
		if (s.find(i) != s.end()) {
			cnt++;
			s.erase(i);
			if (cnt >= 2) {
				ind++;
				cnt = 0;
			}
		}
	}
}