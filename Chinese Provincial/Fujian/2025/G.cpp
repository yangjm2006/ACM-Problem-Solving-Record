#include <iostream>
#define ll long long
using namespace std;
#define int long long
const int N = 1e5 + 9;
ll tr[N << 2], tag[N << 2], n, m, b[N];
void push_up(ll u) { tr[u] = tr[u << 1] + tr[u << 1 | 1]; }
void build(ll u, ll l, ll r) {
	if (l == r) return tr[u] = b[l], void();
	ll mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	push_up(u);
}
void push_down(ll u, ll l, ll r) {
	ll mid = l + r >> 1;
	tag[u << 1] += tag[u];
	tag[u << 1 | 1] += tag[u];
	tr[u << 1] += tag[u] * (mid - l + 1);
	tr[u << 1 | 1] += tag[u] * (r - mid);
	tag[u] = 0;
}
void add(ll u, ll l, ll r, ll L, ll R, ll x) {
	if (l >= L && r <= R) return tr[u] += (r - l + 1) * x, tag[u] += x, void();
	push_down(u, l, r);
	ll mid = l + r >> 1;
	if (mid >= L) add(u << 1, l, mid, L, R, x);
	if (mid + 1 <= R) add(u << 1 | 1, mid + 1, r, L, R, x);
	push_up(u);
}
ll query(ll u, ll l, ll r, ll L, ll R) {
	if (l >= L && r <= R) return tr[u];
	push_down(u, l, r);
	ll mid = l + r >> 1, res = 0;
	if (mid >= L) res += query(u << 1, l, mid, L, R);
	if (mid + 1 <= R) res += query(u << 1 | 1, mid + 1, r, L, R);
	push_up(u);
	return res;
}

void solve() {
	cin >> n >> m;
	int a[n + 1];
	for (int i = 1; i <= n; i++) cin >> a[i];
	int k;
	int s[m + 1];
	int t[m + 1];
	// for (int i = 1; i <= m; i++) {
	cin >> k;
	// }
	for (int i = 1; i <= m; i++) {
		cin >> s[i] >> t[i];
	}
	for (int i = 1; i < n; i++) {
		b[i] = max(0ll, a[i + 1] - a[i]);
	}
	b[n] = 0;
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		if (s[i] == t[i])
			cout << k << '\n';
		else
			cout << k + query(1, 1, n, s[i], t[i] - 1) << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}