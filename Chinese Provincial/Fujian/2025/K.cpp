#include <bits/stdc++.h>
typedef long long ll;
#define PII pair<ll, ll>
using namespace std;

const ll N = 2e5 + 10, inf = 1e17;

ll n, a[N], d[N], mino = inf, minj = inf, add = 0;
vector<PII> e[N];

void dfs(ll root, ll dad) {
	d[root] = d[dad] + 1;
	if (d[root] % 2 == 0) {
		mino = min(mino, a[root]);
	} else {
		minj = min(minj, a[root]);
	}
	for (auto [son, w] : e[root]) {
		if (son == dad) {
			continue;
		}
		a[son] = w - a[root];
		dfs(son, root);
	}
}

void solve() {
	cin >> n;
	for (ll i = 1, u, v, w; i <= n - 1; i++) {
		cin >> u >> v >> w;
		e[u].push_back((PII){v, w});
		e[v].push_back((PII){u, w});
	}
	a[1] = 1, d[1] = 0;
	dfs(1, 1);
	while (mino >= 1) {
		// cout << mino << " " << minj << endl;
		if (minj >= 1) {
			cout << "YES" << endl;
			for (ll i = 1; i <= n; i++) {
				cout << a[i] + add * (-1 + 2 * (d[i] % 2)) << " ";
			}
			cout << endl;
			return;
		}
		mino--, minj++, add++;
	}
	cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
/*
5
1 2 5
1 3 4
2 5 7
3 4 2
*/