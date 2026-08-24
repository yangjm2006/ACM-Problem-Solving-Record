#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 100;
const int INF = 2e9;
int dfn[N], dn, st[30][N], depth[N], id[N];
vector<int> e[N];
void dfs(int u, int fa) {
	st[0][dfn[u] = ++dn] = fa;
	id[dn] = u;
	depth[u] = depth[fa] + 1;
	for (int v : e[u]) {
		if (v == fa) continue;
		dfs(v, u);
	}
}
int get(int x, int y) { return dfn[x] < dfn[y] ? x : y; }
int n, q, lg[N];
int lca(int u, int v) {
	if (u == v) return u;
	u = dfn[u];
	v = dfn[v];
	if (u > v) swap(u, v);
	u++;
	int k = lg[v - u + 1];
	return get(st[k][u], st[k][v - (1 << k) + 1]);
}
int len(int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }
struct Tree {
	int u, v;
} tr[N << 2];
int vec[10];
void pushup(int u) {
	vec[1] = tr[u << 1].u;
	vec[2] = tr[u << 1].v;
	vec[3] = tr[u << 1 | 1].u;
	vec[4] = tr[u << 1 | 1].v;
	int maxlen = -1;
	int ansu = -1, ansv = -1;
	for (int i = 1; i <= 4; i++)
		if (vec[i] != -1) {
			for (int j = i; j <= 4; j++)
				if (vec[j] != -1) {
					if (len(vec[i], vec[j]) > maxlen) {
						ansu = vec[i];
						ansv = vec[j];
						maxlen = len(vec[i], vec[j]);
					}
				}
		}
	tr[u].u = ansu;
	tr[u].v = ansv;
}
bool c[N];
void build(int u, int l, int r) {
	if (l == r) {
		if (c[id[l]])
			tr[u].u = tr[u].v = id[l];
		else
			tr[u].u = tr[u].v = -1;
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void update(int u, int l, int r, int x) {
	if (l == r) {
		c[id[l]] ^= 1;
		if (c[id[l]]) {
			tr[u].u = tr[u].v = id[l];
		} else {
			tr[u].u = tr[u].v = -1;
		}
		return;
	}
	int mid = l + r >> 1;
	if (x <= mid)
		update(u << 1, l, mid, x);
	else
		update(u << 1 | 1, mid + 1, r, x);
	pushup(u);
}
set<pair<int, int>> stt;
ll cal1, cal2, cal3;
void del(int u) {
	pair<int, int> pr(dfn[u], u);
	if (stt.size() == 1) {
		stt.erase(pr);
		cal1 = 0;
		return;
	}
	auto it = stt.lower_bound(pr);
	int x = (*(next(it) == stt.end() ? stt.begin() : next(it))).second;
	int y = (*(it == stt.begin() ? prev(stt.end()) : prev(it))).second;
	cal1 += len(x, y);
	cal1 -= len(x, u) + len(y, u);
	stt.erase(pr);
}
void add(int u) {
	pair<int, int> pr(dfn[u], u);
	if (stt.empty()) {
		stt.insert(pr);
		return;
	}
	auto it = stt.lower_bound(pr);
	int x = (*(it == stt.end() ? stt.begin() : it)).second;
	int y = (*(it == stt.begin() ? prev(stt.end()) : prev(it))).second;
	cal1 -= len(x, y);
	cal1 += len(x, u) + len(y, u);
	stt.insert(pr);
}
void __() {
	cin >> n >> q;
	dn = cal1 = cal2 = cal3 = 0;
	stt.clear();
	for (int i = 1; i <= n; i++) {
		e[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	for (int k = 1; k <= lg[n]; k++) {
		for (int i = 1; i <= n - (1 << k - 1); i++) {
			st[k][i] = get(st[k - 1][i], st[k - 1][i + (1 << k - 1)]);
		}
	}
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		if (c[i]) {
			add(i);
			cal3++;
		}
	}
	while (q--) {
		int u;
		cin >> u;
		update(1, 1, n, dfn[u]);
		if (tr[1].u == -1) {
			cal2 = 0;
		} else {
			cal2 = len(tr[1].u, tr[1].v);
		}
		// cout << cal1 << " " << cal2 << "++\n";
		if (c[u]) {
			add(u);
			cal3++;
		} else {
			del(u);
			cal3--;
		}
		if (cal3 == 0) {
			cout << "No\n";
		} else if (cal3 == 1 || (cal1 == cal2 * 2 && cal2 == cal3 - 1)) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
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