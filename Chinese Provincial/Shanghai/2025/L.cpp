#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
const int M = 4e6 + 100;
int n, m, q;
int toid(int x, int y, char c) {
	if (c == 'N') return (m + 1) * 2 * (x - 1) + y;
	if (c == 'S') return (m + 1) * 2 * x + y;
	if (c == 'W') return (m + 1) * 2 * (x - 1) + y + m + 1;
	if (c == 'E') return (m + 1) * 2 * (x - 1) + y + m + 1 + 1;
}
int fa[M * 4];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
vector<int> deg, pos;
int cntpos;
bool vis[M * 4];
vector<vector<int>> e;
vector<vector<pair<int, int>>> e1, e2;
vector<int> a[N];
int cnn = 0;
int mp[M * 4];
void topo() {
	set<tuple<int, int, int>> st;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int u = mp[find(toid(i, j, 'N'))], v = mp[find(toid(i, j, 'S'))];
			if (u > v) swap(u, v);
			if (u != v) st.insert(make_tuple(u, v, a[i][j]));
			u = mp[find(toid(i, j, 'E'))], v = mp[find(toid(i, j, 'W'))];
			if (u > v) swap(u, v);
			if (u != v) st.insert(make_tuple(u, v, a[i][j]));
		}
	}
	int lstu = -1, lstv = -1, lstw = -1;
	for (const auto& [u, v, w] : st) {
		if (lstu == u && lstv == v) continue;
		e[u].push_back(v);
		e[v].push_back(u);
		deg[u]++;
		deg[v]++;
		lstu = u;
		lstv = v;
	}
	queue<int> q;
	for (int i = 1; i <= cnn; i++) {
		if (deg[i] <= 5) {
			pos[i] = ++cntpos;
			q.push(i);
			vis[i] = 1;
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : e[u]) {
			deg[v]--;
			if (deg[v] <= 5 && vis[v] == 0) {
				pos[v] = ++cntpos;
				q.push(v);
				vis[v] = 1;
			}
		}
	}
	lstu = -1, lstv = -1, lstw = -1;
	for (const auto& [u, v, w] : st) {
		if (lstu == u && lstv == v) continue;
		if (pos[u] < pos[v]) {
			e1[u].push_back(make_pair(v, w));
		} else {
			e1[v].push_back(make_pair(u, w));
		}
		lstu = u;
		lstv = v;
	}
	for (int u = 1; u <= cnn; u++) {
		for (auto& [v1, w1] : e1[u]) {
			for (auto& [v2, w2] : e1[u]) {
				if (pos[v1] < pos[v2]) {
					e2[v1].push_back(make_pair(v2, w1 + w2));
				}
			}
		}
	}
	for (int u = 1; u <= cnn; u++) {
		sort(e2[u].begin(), e2[u].end());
		vector<pair<int, int>> vec;
		int lstv = -1;
		for (auto& [v1, w1] : e2[u]) {
			if (v1 == lstv) continue;
			vec.push_back(make_pair(v1, w1));
			lstv = v1;
		}
		e2[u] = vec;
	}
}
int ans[M];
void __() {
	cin >> n >> m >> q;
	for (int i = 1; i < 4 * M; i++) fa[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			if (c == '/') {
				fa[find(toid(i, j, 'S'))] = find(toid(i, j, 'E'));
				fa[find(toid(i, j, 'W'))] = find(toid(i, j, 'N'));
			} else {
				fa[find(toid(i, j, 'S'))] = find(toid(i, j, 'W'));
				fa[find(toid(i, j, 'E'))] = find(toid(i, j, 'N'));
			}
		}
	}
	vector<int> vec;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			vec.push_back(find(toid(i, j, 'S')));
			vec.push_back(find(toid(i, j, 'N')));
			vec.push_back(find(toid(i, j, 'W')));
			vec.push_back(find(toid(i, j, 'E')));
		}
	}
	sort(vec.begin(), vec.end());
	int last = -1;
	for (auto x : vec) {
		if (x == last) continue;
		mp[x] = ++cnn;
	}
	e1.resize(cnn + 1);
	e2.resize(cnn + 1);
	e.resize(cnn + 1);
	deg.resize(cnn + 1);
	pos.resize(cnn + 1);
	for (int i = 1; i <= n; i++) {
		a[i].push_back(0);
		for (int j = 1; j <= m; j++) {
			int val;
			cin >> val;
			a[i].push_back(val);
		}
	}
	topo();
	vector<tuple<int, int, int>> qry;
	for (int i = 1; i <= q; i++) {
		int sx, sy, tx, ty;
		char c;
		cin >> sx >> sy >> c >> tx >> ty;
		set<int> st;
		st.insert(mp[find(toid(tx, ty, 'N'))]);
		st.insert(mp[find(toid(tx, ty, 'S'))]);
		st.insert(mp[find(toid(tx, ty, 'E'))]);
		st.insert(mp[find(toid(tx, ty, 'W'))]);
		int u = mp[find(toid(sx, sy, c))];
		ans[i] = (1u << 31) - 1;
		for (auto v : st) {
			if (pos[u] < pos[v]) {
				qry.push_back(make_tuple(u, v, i));
			} else {
				qry.push_back(make_tuple(v, u, i));
			}
		}
	}
	for (const auto& [S, T, id] : qry) {
		if (S == T) {
			ans[id] = 0;
			continue;
		}
		for (const auto& [v1, w1] : e1[S]) {
			if (v1 == T) ans[id] = min(ans[id], w1);
			for (const auto& [v2, w2] : e1[T]) {
				if (v1 == v2) ans[id] = min(ans[id], w1 + w2);
			}
		}
		for (const auto& [v1, w1] : e1[S]) {
			if (v1 == T) ans[id] = min(ans[id], w1);
			for (const auto& [v2, w2] : e1[v1]) {
				if (v2 == T) ans[id] = min(ans[id], w1 + w2);
			}
		}
		auto it = lower_bound(e2[S].begin(), e2[S].end(), make_pair(T, -1));
		if (it != e2[S].end() && it->first == T) {
			ans[id] = min(ans[id], it->second);
		}
	}
	for (int i = 1; i <= q; i++) cout << ((ans[i] == ((1u << 31) - 1)) ? -1 : ans[i]) << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}