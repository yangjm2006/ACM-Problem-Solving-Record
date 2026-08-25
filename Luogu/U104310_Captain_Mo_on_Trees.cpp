#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
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
const int B = 500;
struct Query {
	int l, r, extra, id;
	Query() {}
	Query(int l, int r, int extra, int id) : l(l), r(r), extra(extra), id(id) {}
	bool operator<(const Query& other) const {
		if (l / B == other.l / B) return r < other.r;
		return l < other.l;
	}
} q[N];
bool vis[N];
int cnt[N], col[N], curans;
void update(int x) {
	int u = euler[x];
	vis[u] ^= 1;
	if (vis[u]) {
		if (cnt[col[u]] == 0) curans++;
		cnt[col[u]]++;
	} else {
		cnt[col[u]]--;
		if (cnt[col[u]] == 0) curans--;
	}
}
int ans[N];
int n, m;
void Captain_Mo() {
	for (int o = 1; o <= m; o++) {
		int u, v;
		cin >> u >> v;
		if (dfn[u] > dfn[v]) {
			swap(u, v);
		}
		if (u == lca(u, v)) {
			q[o] = Query(ste[u], ste[v], -1, o);
		} else {
			q[o] = Query(ede[u], ste[v], lca(u, v), o);
		}
	}
	sort(q + 1, q + 1 + m);
	int curl = 1, curr = 0;
	for (int o = 1; o <= m; o++) {
		while (curr < q[o].r) update(++curr);
		while (curl > q[o].l) update(--curl);
		while (curr > q[o].r) update(curr--);
		while (curl < q[o].l) update(curl++);
		ans[q[o].id] = curans;
		if (q[o].extra != -1 && cnt[col[q[o].extra]] == 0) ans[q[o].id]++;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
}
void __() {
	cin >> n >> m;
	set<int> st1;
	for (int i = 1; i <= n; i++) {
		cin >> col[i];
		st1.insert(col[i]);
	}
	int cnt = 0;
	map<int, int> mp;
	for (auto x : st1) {
		mp[x] = ++cnt;
	}
	for (int i = 1; i <= n; i++) col[i] = mp[col[i]];
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
	for (int k = 1; k <= lg[n]; k++) {
		for (int i = 1; i <= n - (1 << k - 1); i++) {
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