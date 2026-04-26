#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
const int M = 4e6 + 100;
const int INF = (1u << 31) - 1;
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
vector<int> a[N];
int cnn = 0;
int mp[M * 4];

int head1[M * 4], to1[M * 4], nxt1[M * 4], w1_arr[M * 4];
int tot1;
int head2[M * 4], to2[M * 4], nxt2[M * 4], w2_arr[M * 4];
int tot2;
int head_q[M * 4], to_q[M * 4], nxt_q[M * 4], id_q[M * 4];
int tot_q;

inline void add_e1(int u, int v, int w) {
	to1[++tot1] = v;
	w1_arr[tot1] = w;
	nxt1[tot1] = head1[u];
	head1[u] = tot1;
}
inline void add_e2(int u, int v, int w) {
	to2[++tot2] = v;
	w2_arr[tot2] = w;
	nxt2[tot2] = head2[u];
	head2[u] = tot2;
}
inline void add_q(int u, int v, int id) {
	to_q[++tot_q] = v;
	id_q[tot_q] = id;
	nxt_q[tot_q] = head_q[u];
	head_q[u] = tot_q;
}

void topo() {
	vector<tuple<int, int, int>> st;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int u = mp[find(toid(i, j, 'N'))], v = mp[find(toid(i, j, 'S'))];
			if (u > v) swap(u, v);
			if (u != v) st.push_back(make_tuple(u, v, a[i][j]));
			u = mp[find(toid(i, j, 'E'))], v = mp[find(toid(i, j, 'W'))];
			if (u > v) swap(u, v);
			if (u != v) st.push_back(make_tuple(u, v, a[i][j]));
		}
	}
	sort(st.begin(), st.end());
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
	vector<vector<int>>().swap(e);
	lstu = -1, lstv = -1, lstw = -1;
	for (const auto& [u, v, w] : st) {
		if (lstu == u && lstv == v) continue;
		if (pos[u] < pos[v]) {
			add_e1(u, v, w);
			add_e2(v, u, w);
		} else {
			add_e1(v, u, w);
			add_e2(u, v, w);
		}
		lstu = u;
		lstv = v;
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
		last = x;
	}
	vec.clear();
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
		ans[i] = INF;
		for (auto v : st) {
			if (pos[u] < pos[v]) {
				add_q(u, v, i);
			} else {
				add_q(v, u, i);
			}
		}
	}

	vector<int> dis(cnn + 1, INF);
	for (int S = 1; S <= cnn; S++) {
		if (!head_q[S]) continue;

		auto check_X = [&](int X, int w1) {
			if (dis[X] == INF) vec.push_back(X);
			dis[X] = min(dis[X], w1);
			for (int i = head1[X]; i; i = nxt1[i]) {
				int Y = to1[i], w2 = w1_arr[i];
				if (dis[Y] == INF) vec.push_back(Y);
				dis[Y] = min(dis[Y], w1 + w2);
			}
		};

		for (int i = head1[S]; i; i = nxt1[i]) {
			check_X(to1[i], w1_arr[i]);
		}
		for (int i = head2[S]; i; i = nxt2[i]) {
			check_X(to2[i], w2_arr[i]);
		}

		for (int q_i = head_q[S]; q_i; q_i = nxt_q[q_i]) {
			int T = to_q[q_i], id = id_q[q_i];
			if (S == T) {
				ans[id] = 0;
				continue;
			}
			for (int i1 = head1[S]; i1; i1 = nxt1[i1]) {
				int v1 = to1[i1], w1 = w1_arr[i1];
				for (int i2 = head1[T]; i2; i2 = nxt1[i2]) {
					if (v1 == to1[i2]) {
						ans[id] = min(ans[id], w1 + w1_arr[i2]);
					}
				}
			}
			ans[id] = min(ans[id], dis[T]);
		}
		for (auto x : vec) dis[x] = INF;
		vec.clear();
	}

	for (int i = 1; i <= q; i++) cout << (ans[i] == INF ? -1 : ans[i]) << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}