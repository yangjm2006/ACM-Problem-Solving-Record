#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 100;
int fa[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void __() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) fa[i] = i;
	vector<pair<int, int>> v1, v2;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		if (c)
			v1.push_back(make_pair(u, v));
		else
			v2.push_back(make_pair(u, v));
	}
	for (const auto& [u, v] : v1) {
		fa[find(u)] = find(v);
	}
	int ans = 0;
	for (const auto& [u, v] : v2) {
		if (find(u) == find(v))
			ans++;
		else
			fa[find(u)] = find(v);
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}