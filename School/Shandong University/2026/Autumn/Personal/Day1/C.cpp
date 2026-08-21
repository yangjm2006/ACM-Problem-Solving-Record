#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 100;
ll tr[N];
void pushup(int u) { tr[u] = tr[u << 1] + tr[u << 1 | 1]; }
void build(int u, int l, int r) {
	if (l == r) return tr[u] = 0, void();
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void update(int u, int l, int r, int x) {
	if (l == r) return tr[u]++, void();
	int mid = l + r >> 1;
	if (x <= mid)
		update(u << 1, l, mid, x);
	else
		update(u << 1 | 1, mid + 1, r, x);
	pushup(u);
}
ll query(int u, int l, int r, int L, int R) {
	if (l >= L && r <= R) return tr[u];
	int mid = l + r >> 1;
	ll res = 0;
	if (L <= mid) res += query(u << 1, l, mid, L, R);
	if (R > mid) res += query(u << 1 | 1, mid + 1, r, L, R);
	return res;
}
int ans[N];
vector<int> vec1;
vector<int> vec2;
void __() {
	int n;
	cin >> n;
	vec1.clear();
	vec2.clear();
	ll cal1 = 0, cal2 = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (i & 1)
			vec1.push_back(x);
		else
			vec2.push_back(x);
	}
	build(1, 1, n);
	for (int i = 0; i < vec1.size(); i++) {
		cal1 += query(1, 1, n, vec1[i], n);
		update(1, 1, n, vec1[i]);
	}
	build(1, 1, n);
	for (int i = 0; i < vec2.size(); i++) {
		cal2 += query(1, 1, n, vec2[i], n);
		update(1, 1, n, vec2[i]);
	}
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());
	for (int i = 0; i < n / 2; i++) {
		ans[i * 2 + 1] = vec1[i];
		ans[i * 2 + 2] = vec2[i];
	}
	if (n & 1) ans[n] = vec1[vec1.size() - 1];
	// cout << cal1 << " " << cal2 << "++\n";
	if (abs(cal1 - cal2) % 2 == 1) {
		swap(ans[n], ans[n - 2]);
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
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