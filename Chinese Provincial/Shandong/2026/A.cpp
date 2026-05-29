#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 100;
int n, m;
int mapping(int x, int y) { return (x - 1) * m + y; }
int de[N];
bitset<N> vis[N];
vector<int> e[N];
vector<char> mp[N];
void init() {
	for (int i = 1; i <= n * m; i++) {
		e[i].clear();
		vis[i] = 0;
		de[i] = 0;
		vis[i][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		mp[i].clear();
		for (int j = 1; j <= m + 1; j++) mp[i].push_back(0);
	}
}
void topo() {
	queue<int> q;
	for (int i = 1; i <= n * m; i++) {
		if (de[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : e[u]) {
			vis[v] |= vis[u];
			de[v]--;
			if (de[v] == 0) {
				q.push(v);
			}
		}
	}
}
void __() {
	cin >> n >> m;
	init();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> mp[i][j];
		}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int dx, dy;
			if (mp[i][j] == 'R')
				dx = 0, dy = 1;
			else if (mp[i][j] == 'L')
				dx = 0, dy = -1;
			else if (mp[i][j] == 'U')
				dx = -1, dy = 0;
			else
				dx = 1, dy = 0;
			int x = i + dx, y = j + dy;
			while (x > 0 && x <= n && y > 0 && y <= m) {
				e[mapping(x, y)].push_back(mapping(i, j));
				de[mapping(i, j)]++;
				if (mp[x][y] == mp[i][j]) break;
				x += dx;
				y += dy;
			}
		}
	}
	topo();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (de[mapping(i, j)] != 0)
				cout << "-1 ";
			else
				cout << vis[mapping(i, j)].count() << " ";
		}
		cout << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}