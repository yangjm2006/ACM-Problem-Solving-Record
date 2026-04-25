#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF = 2e9;
const int N = 1e5 + 100;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return a % b == 0 ? b : gcd(b, a % b);
}
struct node {
	ll s, g, l, tag;
} tr[N << 2];
void pushup(int u) {
	tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
	tr[u].g = gcd(tr[u << 1].g, tr[u << 1 | 1].g);
	tr[u].l = tr[u << 1].l * tr[u << 1 | 1].l / gcd(tr[u << 1].l, tr[u << 1 | 1].l);
	if (tr[u].l > INF) tr[u].l = INF;
}
ll a[N];
void build(int u, int l, int r) {
	tr[u].tag = 0;
	if (l == r) return tr[u].s = tr[u].l = tr[u].g = a[l], void();
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void pushdown(int u, int l, int r) {
	if (tr[u].tag) {
		int mid = l + r >> 1;
		tr[u << 1].tag = tr[u << 1].l = tr[u << 1].g = tr[u].tag;
		tr[u << 1].s = tr[u].tag * (mid - l + 1);
		tr[u << 1 | 1].tag = tr[u << 1 | 1].l = tr[u << 1 | 1].g = tr[u].tag;
		tr[u << 1 | 1].s = tr[u].tag * (r - mid);
		tr[u].tag = 0;
	}
}
void update1(int u, int l, int r, int L, int R, ll x) {
	if (l >= L && r <= R) {
		tr[u].tag = tr[u].l = tr[u].g = x;
		tr[u].s = (r - l + 1) * x;
		return;
	}
	pushdown(u, l, r);
	int mid = l + r >> 1;
	if (L <= mid) update1(u << 1, l, mid, L, R, x);
	if (R > mid) update1(u << 1 | 1, mid + 1, r, L, R, x);
	pushup(u);
}
void update2(int u, int l, int r, int L, int R, ll x) {
	if (x % tr[u].l == 0) return;
	if (l == r) {
		tr[u].tag = 0;
		tr[u].l = tr[u].s = tr[u].g = gcd(x, tr[u].s);
		return;
	}
	if (l >= L && r <= R && tr[u].l == tr[u].g) {
		ll y = gcd(x, tr[u].g);
		tr[u].tag = y;
		tr[u].l = tr[u].g = y;
		tr[u].s = (r - l + 1) * y;
		return;
	}
	pushdown(u, l, r);
	int mid = l + r >> 1;
	if (L <= mid) update2(u << 1, l, mid, L, R, x);
	if (R > mid) update2(u << 1 | 1, mid + 1, r, L, R, x);
	pushup(u);
}
ll query(int u, int l, int r, int L, int R) {
	if (l >= L && r <= R) {
		return tr[u].s;
	}
	pushdown(u, l, r);
	int mid = l + r >> 1;
	ll res = 0;
	if (L <= mid) res += query(u << 1, l, mid, L, R);
	if (R > mid) res += query(u << 1 | 1, mid + 1, r, L, R);
	pushup(u);
	return res;
}
void __() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	while (m--) {
		int op, l, r, x;
		cin >> op >> l >> r >> x;
		if (op) {
			update2(1, 1, n, l, r, x);
			cout << query(1, 1, n, l, r) << '\n';
		} else {
			update1(1, 1, n, l, r, x);
		}
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