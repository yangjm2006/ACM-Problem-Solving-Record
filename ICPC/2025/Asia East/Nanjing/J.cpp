#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int n, m;
struct edge {
	int v, nxt;
} e[N];
int _, head[N];
void adde(int u, int v) {
	e[++_].v = v;
	e[_].nxt = head[u];
	head[u] = _;
}
int dfn[N], dn, low[N], stc[N], top, root, in[N], cn;
vector<int> ans[N];
void init() {
	for (int i = 1; i <= n; i++) {
		dfn[i] = low[i] = stc[i] = in[i] = head[i] = 0;
		ans[i].clear();
	}
	cn = dn = top = _ = 0;
}
void tj(int u) {
	dfn[u] = low[u] = ++dn;
	stc[++top] = u;
	if (root == u && head[u] == 0) {
		ans[++cn].push_back(u);
		return;
	}
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (!dfn[v]) {
			tj(v);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				cn++;
				do ans[cn].push_back(stc[top]);
				while (stc[top--] != v);
				ans[cn].push_back(u);
			}
		} else
			low[u] = min(low[u], dfn[v]);
	}
}
void tarjan() {
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) top = dn = 0, root = i, tj(i);
	for (int i = 1; i <= cn; i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			if (ans[i].size() <= 2)
				in[ans[i][j]] = -1e9;
			else
				in[ans[i][j]]++;
		}
	}
}

void __() {
	init();
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		if (u == v) continue;
		adde(u, v);
		adde(v, u);
	}
	tarjan();
	bool flg = 0;
	for (int i = 1; i <= n; i++)
		if (in[i] >= 2) {
			cout << i << " ";
			flg = 1;
		}
	if (!flg) cout << "Empty";
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		__();
	}
	return 0;
}