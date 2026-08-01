#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 3e5 + 10;
int n, m, s;
ll a[N], b[N];
map<int, ll> mp[N];
struct node {
	int id;
	bool operator<(const node& other) const {
		if (a[id] == a[other.id]) return id > other.id;
		return a[id] > a[other.id];
	}
};
bool vis[N];
void __() {
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
		vis[i] = 0;
		mp[i].clear();
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		mp[u][v] = max(mp[u][v], w);
	}
	for (int i = 1; i <= n; i++) {
		if (mp[i].count(i)) {
			b[i] += mp[i][i];
		}
	}
	ll w = -1;
	int wid;
	priority_queue<node> q;
	q.push(node{s});
	while (!q.empty()) {
		int u = q.top().id;
		q.pop();
		vis[u] = 1;
		if (a[u] > w) {
			w = a[u];
			wid = u;
		} else if (a[u] == w) {
			wid = max(wid, u);
		}
		if (u == s) {
			for (int i = 1; i <= n; i++)
				if (i != s) {
					q.push(node{i});
				}
		}
		for (auto [key, value] : mp[u]) {
			b[key] += value;
			if (!vis[key]) q.push(node{key});
		}
		while (!q.empty() &&
			   (vis[q.top().id] || (b[q.top().id] < w || (b[q.top().id] == w && q.top().id < wid))))
			q.pop();
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
}
int main() {
	cin.tie(0)->ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}