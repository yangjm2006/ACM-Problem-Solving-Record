#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> st;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		if (u == v - 1) st.insert(make_pair(u, v));
	}
	cout << (st.size() == n - 1 ? "Yes" : "No");
	return 0;
}