#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
vector<int> e[N];
int n, m, d, ans, maxx[N], max1[N], max2[N], son1[N], maxf[N];
bool vis[N], imp[N];
int root;
void dfs1(int u, int fa, int depth) {
	for (int v : e[u]) {
		if (v == fa) continue;
		dfs1(v, u, depth + 1);
		if (vis[v]) {
			vis[u] = 1;
			if (max1[v] + 1 > max1[u]) {
				max2[u] = max1[u];
				max1[u] = max1[v] + 1;
				son1[u] = v;
			} else if (max1[v] + 1 > max2[u]) {
				max2[u] = max1[v] + 1;
			}
		}
	}
}
void dfs3(int u, int fa) {
	for (int v : e[u]) {
		if (v == fa) continue;
		if (vis[v]) {
			if (v != son1[u]) {
				maxf[v] = max(maxf[u] + 1, max1[u] + 1);
			} else {
				maxf[v] = max(maxf[u] + 1, max2[u] + 1);
			}
			dfs3(v, u);
		}
	}
}
void dfs2(int u, int fa, int dep) {
	if (vis[u] == 0) {
		// cout << u << "++\n";
		ans++;
	}
	if (dep == 0) return;
	for (int v : e[u]) {
		if (v == fa) continue;
		if (vis[v] == 0) dfs2(v, u, dep - 1);
	}
}
void __() {
	cin >> n >> m >> d;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		vis[x] = imp[x] = 1;
		root = x;
	}
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(root, 0, 0);
	dfs3(root, 0);
	for (int i = 1; i <= n; i++) {
		maxx[i] = max(maxf[i], max1[i]);
	}
	// for (int i = 1; i <= n; i++) {
	// 	cout << maxx[i] << "++\n";
	// }
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 1 && d - maxx[i] >= 0) {
			ans++;
			// cout << i << " " << d - maxx[i] << "++\n";
			dfs2(i, 0, d - maxx[i]);
		}
	}
	cout << ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}