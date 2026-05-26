#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 9;
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
vector<int> ans[N];
int dfn[N], dn, low[N], stc[N], top, cn, root;
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
	cout << cn << '\n';
	for (int i = 1; i <= cn; i++) {
		cout << ans[i].size() << " ";
		for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
		cout << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		if (u == v) continue;
		adde(u, v);
		adde(v, u);
	}
	tarjan();
	return 0;
}