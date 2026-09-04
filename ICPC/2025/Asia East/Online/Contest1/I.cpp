#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const int INF = 1e9;
struct Edge {
	int v, w;
};
vector<Edge> e[N];
int n, m, V, T;
struct Dis {
	int D, d;
	bool operator>(const Dis& other) const {
		if (D == other.D) return d > other.d;
		return D > other.D;
	}
	Dis operator+(int w) const {
		if (d + w > V) return Dis{D + 1, w};
		return Dis{D, d + w};
	}
} dis[N];
struct Node {
	int u;
	Dis dis;
	bool operator<(const Node& other) const { return dis > other.dis; }
};
void dijkstra() {
	for (int i = 1; i <= n; i++) dis[i].D = dis[i].d = INF;
	dis[T].D = 1;
	dis[T].d = 0;
	priority_queue<Node> q;
	q.push(Node{T, Dis{1, 0}});
	while (!q.empty()) {
		int u = q.top().u;
		Dis dist = q.top().dis;
		q.pop();
		for (auto& [v, w] : e[u]) {
			if (dis[v] > dist + w) {
				dis[v] = dist + w;
				q.push(Node{v, dis[v]});
			}
		}
	}
}
void __() {
	cin >> n >> m >> V >> T;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		e[u].push_back(Edge{v, w});
		e[v].push_back(Edge{u, w});
	}
	dijkstra();
	for (int i = 1; i <= n; i++) cout << (dis[i].D >= INF ? -1 : dis[i].D) << " ";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}