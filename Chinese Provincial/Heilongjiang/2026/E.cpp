#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 100;
const int INF = 1e9;
vector<int> e[N];
int fat[N], dn, dfn[N], ded[N], a[N], tr1[N], tr2[N], tag[N], w[N];
void dfs(int u, int depth) {
	dfn[u] = ++dn;
	a[dn] = depth;
	for (int v : e[u]) {
		if (v == fat[u]) continue;
		fat[v] = u;
		dfs(v, depth + 1);
	}
	ded[u] = dn;
}
void pushup(int u) {
	tr1[u] = min(tr1[u << 1], tr1[u << 1 | 1]);
	tr2[u] = min(tr2[u << 1], tr2[u << 1 | 1]);
}
void build(int u, int l, int r) {
	if (l == r) return tr1[u] = INF * 2, tr2[u] = a[l], void();
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void pushdown(int u) {
	tag[u << 1] += tag[u];
	tag[u << 1 | 1] += tag[u];
	tr1[u << 1] += tag[u];
	tr1[u << 1 | 1] += tag[u];
	tr2[u << 1] += tag[u];
	tr2[u << 1 | 1] += tag[u];
	tag[u] = 0;
}
void update(int u, int l, int r, int L, int R, int x) {
	if (l >= L && r <= R) {
		tag[u] += x;
		tr1[u] += x;
		tr2[u] += x;
		return;
	}
	int mid = l + r >> 1;
	pushdown(u);
	if (L <= mid) update(u << 1, l, mid, L, R, x);
	if (R > mid) update(u << 1 | 1, mid + 1, r, L, R, x);
	pushup(u);
}
void update(int u, int l, int r, int x, int op) {
	if (l == r) {
		if (op == 1)
			tr1[u] = tr2[u];
		else
			tr1[u] = INF * 2;
		return;
	}
	int mid = l + r >> 1;
	pushdown(u);
	if (x <= mid)
		update(u << 1, l, mid, x, op);
	else
		update(u << 1 | 1, mid + 1, r, x, op);
	pushup(u);
}
void __() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	build(1, 1, n);
	int now = 1;
	for (int i = 1; i <= m; i++) {
		int op, x;
		cin >> op >> x;
		if (op == 1) {
			w[x]++;
			update(1, 1, n, dfn[x], w[x] % 2);
		} else {
			if (x == fat[now]) {
				update(1, 1, n, 1, n, -1);
				update(1, 1, n, dfn[now], ded[now], 2);
			} else {
				update(1, 1, n, 1, n, 1);
				update(1, 1, n, dfn[x], ded[x], -2);
			}
			now = x;
		}
		if (tr1[1] >= INF)
			cout << "2147483648\n";
		else
			cout << tr1[1] << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}