#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e6 + 100;
const ll INF = 1e16;
vector<int> e[N];
ll a[N], f[N][4], F[N][4];
void dfs(int u, int fa) {
	f[u][0] = 0;
	f[u][1] = a[u];
	f[u][2] = -a[u];
	f[u][3] = 0;
	for (int v : e[u]) {
		if (v == fa) continue;
		dfs(v, u);
		F[u][0] = F[u][1] = F[u][2] = F[u][3] = -INF;
		for (int k1 = 0; k1 <= 3; k1++)
			for (int k2 = 0; k2 <= 3; k2++)
				if ((k1 & k2) == 0) F[u][k1 | k2] = max(F[u][k1 | k2], f[u][k1] + f[v][k2]);
		for (int i = 0; i <= 3; i++) f[u][i] = F[u][i];
	}
	f[u][0] = max(f[u][0], f[u][3]);
}
void __() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1, u, v; i <= n - 1; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	cout << f[1][0];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}