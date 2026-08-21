#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
const ll INF = 1e10;
int fa[N];
ll sum[N], ans[N], S;
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int u, int v, ll w) {
	u = find(u), v = find(v);
	if (u == v) return;
	ans[v] = max(min(ans[u], w - S + sum[u]), min(ans[v], w - S + sum[v]));
	sum[v] += sum[u];
	fa[u] = v;
}
struct Edge {
	int u, v;
	ll w;
	bool operator<(const Edge& other) const { return w > other.w; }
} e[N];
int c[N], n, m;
void kruskal() {
	sort(e + 1, e + 1 + m);
	for (int i = 1; i <= m; i++) {
		merge(e[i].u, e[i].v, e[i].w);
	}
}
void __() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		S += c[i];
	}
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		sum[i] = c[i];
		ans[i] = INF;
	}
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	kruskal();
	cout << ((ans[find(1)] > 0) ? ans[find(1)] : -1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}