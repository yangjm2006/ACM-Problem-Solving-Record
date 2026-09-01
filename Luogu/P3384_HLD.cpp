#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 100;
ll mod;
struct Segment_Tree {
	ll a[N], tr[N << 2], tag[N << 2];

	void pushup(int u) { tr[u] = (tr[u << 1] + tr[u << 1 | 1]) % mod; }

	void build(int u, int l, int r) {
		if (l == r) return tr[u] = a[l] % mod, void();
		int mid = l + r >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}

	void pushdown(int u, int l, int r) {
		int mid = l + r >> 1;
		(tr[u << 1] += (mid - l + 1) * tag[u]) %= mod;
		(tag[u << 1] += tag[u]) %= mod;
		(tr[u << 1 | 1] += (r - mid) * tag[u]) %= mod;
		(tag[u << 1 | 1] += tag[u]) %= mod;
		tag[u] = 0;
	}

	void update(int u, int l, int r, int L, int R, ll x) {
		if (l >= L && r <= R) {
			(tag[u] += x) %= mod;
			(tr[u] += (r - l + 1) * x) %= mod;
			return;
		}
		int mid = l + r >> 1;
		pushdown(u, l, r);
		if (mid >= L) update(u << 1, l, mid, L, R, x);
		if (mid < R) update(u << 1 | 1, mid + 1, r, L, R, x);
		pushup(u);
	}

	ll query(int u, int l, int r, int L, int R) {
		if (l >= L && r <= R) return tr[u];
		int mid = l + r >> 1;
		ll res = 0;
		pushdown(u, l, r);
		if (mid >= L) (res += query(u << 1, l, mid, L, R)) %= mod;
		if (mid < R) (res += query(u << 1 | 1, mid + 1, r, L, R)) %= mod;
		pushup(u);
		return res;
	}
} tree;
vector<int> e[N];
int sz[N], son[N], dep[N], fat[N];
void dfs1(int u, int fa) {
	fat[u] = fa;
	sz[u]++;
	dep[u] = dep[fa] + 1;
	int maxx = -1;
	for (int v : e[u]) {
		if (v == fa) continue;
		dfs1(v, u);
		sz[u] += sz[v];
		if (sz[v] > maxx) {
			son[u] = v;
			maxx = sz[v];
		}
	}
}
int dn, dfn[N], top[N];
void dfs2(int u, int tp) {
	dfn[u] = ++dn;
	top[u] = tp;
	if (son[u]) dfs2(son[u], tp);
	for (int v : e[u]) {
		if (v == fat[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}
int n, m, root, a[N];
void update1(int u, int v, ll x) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		tree.update(1, 1, n, dfn[top[u]], dfn[u], x);
		u = fat[top[u]];
	}
	if (dep[u] > dep[v]) swap(u, v);
	tree.update(1, 1, n, dfn[u], dfn[v], x);
}
void update2(int u, ll x) { tree.update(1, 1, n, dfn[u], dfn[u] + sz[u] - 1, x); }
ll query1(int u, int v) {
	ll res = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		(res += tree.query(1, 1, n, dfn[top[u]], dfn[u])) %= mod;
		u = fat[top[u]];
	}
	if (dep[u] > dep[v]) swap(u, v);
	(res += tree.query(1, 1, n, dfn[u], dfn[v])) %= mod;
	return res;
}
ll query2(int u) { return tree.query(1, 1, n, dfn[u], dfn[u] + sz[u] - 1); }
void __() {
	cin >> n >> m >> root >> mod;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1, u, v; i <= n - 1; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(root, 0);
	dfs2(root, root);
	for (int i = 1; i <= n; i++) {
		tree.a[dfn[i]] = a[i];
	}
	tree.build(1, 1, n);
	while (m--) {
		int op, u, v;
		ll x;
		cin >> op;
		if (op == 1) {
			cin >> u >> v >> x;
			update1(u, v, x);
		} else if (op == 2) {
			cin >> u >> v;
			cout << query1(u, v) << '\n';
		} else if (op == 3) {
			cin >> u >> x;
			update2(u, x);
		} else {
			cin >> u;
			cout << query2(u) << '\n';
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}