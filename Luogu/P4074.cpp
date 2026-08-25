#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
typedef long long ll;
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
const int B = 3000;
struct Query {
	int l, r, t, extra, id;
	Query() {}
	Query(int l, int r, int t, int extra, int id) : l(l), r(r), t(t), extra(extra), id(id) {}
	bool operator<(const Query& other) const {
		if (l / B == other.l / B) {
			if (r / B == other.r / B) return ((r / B) & 1) ? (t > other.t) : (t < other.t);
			return ((l / B) & 1) ? (r > other.r) : (r < other.r);
		}
		return l < other.l;
	}
} q[N];
bool vis[N];
ll cnt[N], curans, v[N], w[N];
int curl = 1, curr = 0, curt = 0, col[N];
void update(int x) {
	int u = euler[x];
	vis[u] ^= 1;
	if (vis[u]) {
		cnt[col[u]]++;
		curans += v[col[u]] * w[cnt[col[u]]];
	} else {
		curans -= v[col[u]] * w[cnt[col[u]]];
		cnt[col[u]]--;
	}
}
int change_id[N], change_col[N];
void change(int t) {
	int u = change_id[t], c = change_col[t];
	if (vis[u]) {
		curans -= v[col[u]] * w[cnt[col[u]]];
		cnt[col[u]]--;
		cnt[c]++;
		curans += v[c] * w[cnt[c]];
	}
	swap(change_col[t], col[u]);
}
ll ans[N];
int n, m, p;
void Captain_Mo() {
	int tcnt = 0, qcnt = 0;
	for (int o = 1; o <= p; o++) {
		int op;
		cin >> op;
		if (op == 1) {
			qcnt++;
			int u, v;
			cin >> u >> v;
			if (dfn[u] > dfn[v]) swap(u, v);
			if (u == lca(u, v))
				q[qcnt] = Query(ste[u], ste[v], tcnt, -1, qcnt);
			else
				q[qcnt] = Query(ede[u], ste[v], tcnt, lca(u, v), qcnt);
		} else {
			tcnt++;
			cin >> change_id[tcnt] >> change_col[tcnt];
		}
	}
	sort(q + 1, q + 1 + qcnt);
	for (int o = 1; o <= qcnt; o++) {
		while (curr < q[o].r) update(++curr);
		while (curl > q[o].l) update(--curl);
		while (curr > q[o].r) update(curr--);
		while (curl < q[o].l) update(curl++);
		while (curt < q[o].t) change(++curt);
		while (curt > q[o].t) change(curt--);
		ans[q[o].id] = curans;
		if (q[o].extra != -1) ans[q[o].id] += v[col[q[o].extra]] * w[cnt[col[q[o].extra]] + 1];
	}
	for (int i = 1; i <= qcnt; i++) cout << ans[i] << '\n';
}
void __() {
	cin >> n >> m >> p;
	for (int i = 1; i <= m; i++) cin >> v[i];
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) cin >> col[i];
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