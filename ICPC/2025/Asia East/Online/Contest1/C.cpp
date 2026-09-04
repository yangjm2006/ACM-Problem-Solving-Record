#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
struct node {
	int l, r;
	bool operator<(const node& other) const { return r > other.r; }
} p[N];
bool cmp(const node& x, const node& y) {
	if (x.l == y.l) return x.r < y.r;
	return x.l < y.l;
}
void __() {
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].l >> p[i].r;
	}
	sort(p + 1, p + 1 + n, cmp);
	int L = -1;
	priority_queue<node> q;
	for (int i = 1;;) {
		if (q.empty()) {
			if (i <= n) {
				q.push(p[i]);
				i++;
			} else
				break;
		}
		int l = q.top().l, r = q.top().r;
		q.pop();
		L = max(L, l + 1);
		if (L <= r) {
			cnt++;
			L++;
		}
		while (p[i].l + 1 <= L && i <= n) {
			q.push(p[i]);
			i++;
		}
	}
	cout << m - cnt << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}