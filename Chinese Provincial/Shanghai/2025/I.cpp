#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e3 + 100;
const ll mod = 998244353;
vector<ll> e[N];
ll ans[N][N];
ll sz[N];
bool cmp(int x, int y) { return sz[x] < sz[y]; }
ll a[N];
ll n;
int tmp[N][N];
void pre_dfs(ll u, ll fa) {
	for (auto v : e[u]) {
		if (v == fa) continue;
		pre_dfs(v, u);
		sz[u] += sz[v];
	}
	sz[u]++;
}
void dfs(ll u, ll fa) {
	for (ll i = 0; i <= n; i++) tmp[u][i] = 0;
	tmp[u][0] = 1;
	for (auto v : e[u]) {
		if (v == fa) continue;
		dfs(v, u);
		vector<pair<int, ll>> v1, v2;
		ll res[N] = {};
		for (int i = 0; i <= n; ++i)
			if (tmp[u][i]) v1.emplace_back(make_pair(i, tmp[u][i]));
		for (int i = 0; i <= n; ++i)
			if (ans[v][i]) v2.emplace_back(make_pair(i, ans[v][i]));
		for (auto& x : v1) {
			for (auto& y : v2) {
				(res[x.first + y.first] += x.second * y.second % mod) %= mod;
			}
		}
		for (int i = 0; i <= n; ++i) tmp[u][i] = res[i];
	}
	for (ll i = 0; i <= n; i++) {
		if (i == a[u] - 1) (ans[u][i + 1] += tmp[u][i]) %= mod;
		if (i != a[u]) (ans[u][i] += tmp[u][i]) %= mod;
	}
}
void __() {
	cin >> n;
	for (ll i = 0; i <= n; i++) {
		sz[i] = 0;
		e[i].clear();
		for (ll j = 0; j <= n; j++) ans[i][j] = 0;
	}
	for (ll i = 1; i <= n; i++) cin >> a[i];
	for (ll i = 1; i <= n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	pre_dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		sort(e[i].begin(), e[i].end(), cmp);
	}
	dfs(1, 0);
	ll res = 0;
	for (ll i = 0; i <= n; i++) (res += ans[1][i]) %= mod;
	cout << res << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll T;
	cin >> T;
	while (T--) __();
	return 0;
}