#include <bits/stdc++.h>
using namespace std;
int mp[300][300];
bool vis[300][300];
int n, m, cnt;
vector<pair<char, int>> ans;
int get(int op, int mir) {
	if (mir == 1) {
		if (op == 1) return 2;
		if (op == 2) return 1;
		if (op == 3) return 4;
		return 3;
	}
	if (op == 1) return 4;
	if (op == 2) return 3;
	if (op == 3) return 2;
	return 1;
}
int dx[5] = {0, 1, 0, -1, 0}, dy[5] = {0, 0, 1, 0, -1};
bool check(int x, int y, int op) {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			vis[i][j] = 0;
		}
	}
	while (x >= 1 && x <= n && y >= 1 && y <= m) {
		if (mp[x][y] == 0) {
			x += dx[op];
			y += dy[op];
		} else {
			op = get(op, mp[x][y]);
			if (vis[x][y] == 0) {
				res++;
				vis[x][y] = 1;
			}
			x += dx[op];
			y += dy[op];
		}
	}
	return res == cnt;
}

void __() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			if (c == '\\') {
				cnt++;
				mp[i][j] = 1;
			} else if (c == '/') {
				cnt++;
				mp[i][j] = 2;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (check(1, i, 1)) {
			ans.push_back(make_pair('N', i));
		}
		if (check(n, i, 3)) {
			ans.push_back(make_pair('S', i));
		}
	}
	for (int i = 1; i <= n; i++) {
		if (check(i, 1, 2)) {
			ans.push_back(make_pair('W', i));
		}
		if (check(i, m, 4)) {
			ans.push_back(make_pair('E', i));
		}
	}
	cout << ans.size() << '\n';
	for (auto [c, x] : ans) {
		cout << c << x << " ";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}