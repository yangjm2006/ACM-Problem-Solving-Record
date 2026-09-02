#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 20;
const int M = 1e6 + 20;
const ll INF = 1e18;
int n, m;
struct edge {
	int v, nxt;
	ll w;
} e[N];
int _, head[M];
void adde(int u, int v, ll w) {
	e[++_].v = v;
	e[_].w = w;
	e[_].nxt = head[u];
	head[u] = _;
}
struct node {
	int u;
	ll d;
	bool operator<(const node& x) const { return d > x.d; }
};
priority_queue<node> q;
bool vis[N];
ll dis[M];
void dij() {
	for (int i = 1; i <= 2 * n; i++) vis[i] = 0;
	for (int i = 1; i <= n; i++) {
		q.push((node){i, dis[i + n]});
	}
	while (!q.empty()) {
		int u = q.top().u;
		ll d = q.top().d;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].v;
			ll w = e[i].w;
			if (dis[v] > d + w) {
				dis[v] = d + w;
				q.push((node){v, dis[v]});
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) adde(i, i + n, 0ll);
	for (int i = 1, u, v; i <= n - 1; i++) {
		ll w;
		cin >> u >> v >> w;
		adde(u, v, w);
		adde(v, u, w);
		adde(u + n, v + n, w);
		adde(v + n, u + n, w);
	}
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		adde(u, v + n, 0ll);
		adde(v, u + n, 0ll);
	}
	for (int i = 1; i <= 2 * n; i++) dis[i] = INF;
	dis[1] = dis[1 + n] = 0;
	dij();
	ll ans = 0;
	for (int i = 1; i <= n; i++) ans += dis[i];
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		ans = 0;
		for (int i = 1; i <= n; i++) ans += dis[i + n];
		cout << ans << '\n';
		dij();
	}
	return 0;
}