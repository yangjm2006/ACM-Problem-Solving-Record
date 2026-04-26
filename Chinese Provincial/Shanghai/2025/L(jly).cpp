#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;
struct DSU {
	std::vector<int> f, siz;

	DSU() {}
	DSU(int n) { init(n); }

	void init(int n) {
		f.resize(n);
		std::iota(f.begin(), f.end(), 0);
		siz.assign(n, 1);
	}

	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}

	bool same(int x, int y) { return find(x) == find(y); }

	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			return false;
		}
		siz[x] += siz[y];
		f[y] = x;
		return true;
	}

	int size(int x) { return siz[find(x)]; }
};

constexpr int inf = 2E9 + 1;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, q;
	std::cin >> n >> m >> q;

	std::vector<std::string> s(n);
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}

	const int N = n * (m + 1) + (n + 1) * m;
	DSU dsu(N);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '/') {
				dsu.merge(i * (m + 1) + j, n * (m + 1) + i * m + j);
				dsu.merge(i * (m + 1) + j + 1, n * (m + 1) + (i + 1) * m + j);
			} else {
				dsu.merge(i * (m + 1) + j, n * (m + 1) + (i + 1) * m + j);
				dsu.merge(i * (m + 1) + j + 1, n * (m + 1) + i * m + j);
			}
		}
	}

	std::vector A(n, std::vector<int>(m));

	std::vector<std::vector<std::pair<int, int>>> adj(N);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> A[i][j];

			int s = dsu.find(i * (m + 1) + j);
			int t = dsu.find(i * (m + 1) + j + 1);
			if (s != t) {
				adj[s].emplace_back(t, A[i][j]);
				adj[t].emplace_back(s, A[i][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		std::sort(adj[i].begin(), adj[i].end());
		adj[i].erase(std::unique(adj[i].begin(), adj[i].end(),
								 [&](auto a, auto b) { return a.first == b.first; }),
					 adj[i].end());
	}

	std::vector<std::vector<std::pair<int, int>>> qry(N);
	std::vector<int> ans(q, inf);

	auto get = [&](int u, int v) {
		auto it = std::lower_bound(adj[u].begin(), adj[u].end(), std::make_pair(v, 0));
		if (it != adj[u].end() && it->first == v) {
			return it->second;
		}
		return inf;
	};

	for (int i = 0; i < q; i++) {
		int a, b;
		char dir;
		int c, d;
		std::cin >> a >> b >> dir >> c >> d;
		a--;
		b--;
		c--;
		d--;

		int s;
		if (dir == 'N') {
			s = n * (m + 1) + a * m + b;
		} else if (dir == 'S') {
			s = n * (m + 1) + (a + 1) * m + b;
		} else if (dir == 'W') {
			s = a * (m + 1) + b;
		} else {
			s = a * (m + 1) + b + 1;
		}
		s = dsu.find(s);

		std::array<int, 4> cand{n * (m + 1) + c * m + d, n * (m + 1) + (c + 1) * m + d,
								c * (m + 1) + d, c * (m + 1) + d + 1};

		for (auto t : cand) {
			t = dsu.find(t);
			if (s == t) {
				ans[i] = 0;
			} else {
				ans[i] = std::min(ans[i], get(s, t));
				if (adj[s].size() > adj[t].size() || (adj[s].size() == adj[t].size() && s > t)) {
					qry[s].emplace_back(t, i);
				} else {
					qry[t].emplace_back(s, i);
				}
			}
		}
	}

	std::vector<int> vis(N, inf);
	for (int s = 0; s < N; s++) {
		if (qry[s].empty()) {
			continue;
		}
		for (auto [y, w] : adj[s]) {
			vis[y] = w;
		}
		std::sort(qry[s].begin(), qry[s].end());
		int lst = -1;
		int lstans = inf;
		for (auto [t, i] : qry[s]) {
			if (t == lst) {
				ans[i] = std::min(ans[i], lstans);
				continue;
			}
			lst = t;
			lstans = inf;
			for (auto [y, w] : adj[t]) {
				if (vis[y] != inf) {
					lstans = std::min(lstans, vis[y] + w);
				}
			}
			ans[i] = std::min(ans[i], lstans);
		}
		for (auto [y, w] : adj[s]) {
			vis[y] = inf;
		}
	}

	for (int i = 0; i < q; i++) {
		if (ans[i] == inf) {
			ans[i] = -1;
		}
		std::cout << ans[i] << "\n";
	}

	return 0;
}
