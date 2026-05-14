#include <bits/stdc++.h>

#define ll long long
using namespace std;
#define int long long
#define PII pair<int, int>

struct node {
	int x;
	int y;
	int t;
};

const ll N = 4e18;

void solve() {
	int n, m, l, r;
	cin >> n >> m >> l >> r;

	string a[n + 2];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = " " + a[i];
	}
	int nex[8][2] = {0, 1, 1, 0, -1, 0, 0, -1, 1, 1, -1, -1, 1, -1, -1, 1};
	int dis[n + 2][m + 2][2];
	int b[n + 2][m + 2][2] = {};
	dis[1][1][0] = 0;
	dis[n][m][0] = -1;
	dis[n][m][1] = -1;
	queue<node> q;
	q.push({1, 1, 0});

	while (!q.empty()) {
		auto [x, y, t] = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + nex[i][0];
			int ny = y + nex[i][1];
			if (nx <= 0 || ny <= 0 || nx > n || ny > m || a[nx][ny] == '0') {
				continue;
			}
			int nt = t ^ 1;
			if (b[nx][ny][nt] == 1) {
				continue;
			}
			dis[nx][ny][nt] = dis[x][y][t] + 1;
			b[nx][ny][nt] = 1;
			q.push({nx, ny, nt});
		}
	}
	int sum1 = dis[n][m][1];
	int sum2 = dis[n][m][0];
	// cout << sum1 << ' ' << sum2 << ' ';
	if (sum1 == -1 && sum2 == -1) {
		cout << -1;
		return;
	}
	if (sum1 == -1) sum1 = N;
	if (sum2 == -1) sum2 = N;
	int ans;
	if (l < r) {
		ans = (min(sum1, sum2) - 1) / r + 1;
	} else {
		if (r % 2 == 1) {
			// int ans1 = (sum1 - 1) / r + 1;
			// if ((ans1 * r - sum1) % 2 == 1) ans1++;
			// int ans2 = (sum2 - 1) / r + 1;
			// if ((ans2 * r - sum2) % 2 == 1) ans2++;
			int ans1, ans2;
			if (sum1 == N)
				ans1 = N;
			else
				ans1 = (((sum1 - 1) / r + 1) * r - sum1) % 2 + (sum1 - 1) / r + 1;

			if (sum2 == N)
				ans2 = N;
			else
				ans2 = (((sum2 - 1) / r + 1) * r - sum2) % 2 + (sum2 - 1) / r + 1;

			ans = min(ans1, ans2);
		} else {
			if (sum2 == N) {
				cout << -1;
				return;
			}
			ans = (sum2 - 1) / r + 1;
		}
	}
	cout << ans;
}

signed main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
		cout << endl;
	}
	return 0;
}