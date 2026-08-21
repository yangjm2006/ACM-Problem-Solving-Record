#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t i128;
const int N = 1e5 + 10;
const int M = 1e2 + 10;
const ll INF = 1e16;
int n, m, p;
ll a[N], dp[M][N], d[N], s[N], k;
ll cal(ll j, ll x) { return -j * x + dp[k - 1][j] + s[j]; }
bool check(ll x, ll y, ll z) {
	ll Bx = dp[k - 1][x] + s[x], By = dp[k - 1][y] + s[y], Bz = dp[k - 1][z] + s[z];
	return (i128)(Bx - By) * (x - z) >= (i128)(Bx - Bz) * (x - y);
}
void __() {
	cin >> n >> m >> p;
	for (int i = 2; i <= n; i++) {
		ll x;
		cin >> x;
		d[i] = d[i - 1] + x;
	}
	for (int i = 1; i <= m; i++) {
		ll h, t;
		cin >> h >> t;
		a[i] = t - d[h];
	}
	sort(a + 1, a + 1 + m);
	for (int i = 1; i <= m; i++) {
		s[i] = s[i - 1] + a[i];
		dp[0][i] = INF;
	}
	deque<int> deq;
	for (k = 1; k <= p; k++) {
		deq.clear();
		deq.push_back(0);
		for (int i = 1; i <= m; i++) {
			while (deq.size() >= 2 && cal(deq[0], a[i]) >= cal(deq[1], a[i])) {
				deq.pop_front();
			}
			int j = deq.front();
			if (dp[k - 1][j] == INF)
				dp[k][i] = INF;
			else
				dp[k][i] = i * a[i] - s[i] + cal(j, a[i]);
			if (dp[k - 1][i] != INF) {
				while (deq.size() >= 2 && check(deq[deq.size() - 2], deq[deq.size() - 1], i)) {
					deq.pop_back();
				}
				deq.push_back(i);
			}
		}
	}
	cout << dp[p][m];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}