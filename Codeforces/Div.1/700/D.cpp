#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
vector<int> e[N];
int dn, dfn[N], st[30][N];
int elr, euler[N], ste[N], ede[N];
void dfs(int u, int fa) {
	st[0][dfn[u] = ++dn] = fa;
	euler[ste[u] = ++elr] = u;
	for (int v : e[u]) {
		if (v == fa) continue;
		dfs(v, u);
	}
	euler[ede[u] = ++elr] = u;
}
int get(int x, int y) { return dfn[x] < dfn[y] ? x : y; }
int lg[N];
int lca(int u, int v) {
	if (u == v) return u;
	u = dfn[u];
	v = dfn[v];
	if (u > v) swap(u, v);
	u++;
	int k = lg[v - u + 1];
	return get(st[k][u], st[k][v - (1 << k) + 1]);
}
const int B = 1000;
struct Query {
	int l, r, extra, L, R, id;
	Query() {}
	Query(int l, int r, int extra, int L, int R, int id)
		: l(l), r(r), extra(extra), L(L), R(R), id(id) {}
	bool operator<(const Query& other) const {
		if (l / B == other.l / B) {
			return (r < other.r) ^ (l / B % 2);
		}
		return l < other.l;
	}
} q[N];
bool vis[N];
int col[N], cnt[N];
const int S = 600;
void update(int x) {
	int c = col[euler[x]];
	vis[c] ^= 1;
	if (vis[c]) {
		cnt[c / S]++;
	} else {
		cnt[c / S]--;
	}
}
int n, m;
int ask(int l, int r) {
	for (int b = l / S; b <= r / S; b++) {
		if (cnt[b]) {
			for (int i = max(l, b * S); i <= min(r, (b + 1) * S - 1); i++) {
				if (vis[i]) return i;
			}
		}
	}
	return -1;
}
int ans[N];
void Captain_Mo() {
	for (int o = 1; o <= m; o++) {
		int u, v, L, R;
		cin >> u >> v >> L >> R;
		if (dfn[u] > dfn[v]) {
			swap(u, v);
		}
		if (u == lca(u, v)) {
			q[o] = Query(ste[u], ste[v], -1, L, R, o);
		} else {
			q[o] = Query(ede[u], ste[v], lca(u, v), L, R, o);
		}
	}
	sort(q + 1, q + 1 + m);
	int curl = 1, curr = 0;
	for (int o = 1; o <= m; o++) {
		while (curr < q[o].r) update(++curr);
		while (curl > q[o].l) update(--curl);
		while (curr > q[o].r) update(curr--);
		while (curl < q[o].l) update(curl++);
		if (q[o].extra != -1) {
			update(ste[q[o].extra]);
			ans[q[o].id] = ask(q[o].L, q[o].R);
			update(ste[q[o].extra]);
		} else {
			ans[q[o].id] = ask(q[o].L, q[o].R);
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
}
void __() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> col[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
	for (int k = 1; k <= lg[n]; k++) {
		for (int i = 1; i + (1 << k) - 1 <= n; i++) {
			st[k][i] = get(st[k - 1][i], st[k - 1][i + (1 << k - 1)]);
		}
	}
	Captain_Mo();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}