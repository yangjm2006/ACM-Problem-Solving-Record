// #pragma o2
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 998244353;
const ll _6 = 166374059;
const int N = 128;
struct Matrix {
	ll a[N + 10][N + 10];
	Matrix() {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) a[i][j] = 0;
	}
	void ide() {
		for (int i = 1; i <= N; i++) a[i][i] = 1;
	}
	Matrix operator*(const Matrix& other) const {
		Matrix ans;
		for (int i = 1; i <= N; i++)
			for (int k = 1; k <= N; k++)
				if (a[i][k])
					for (int j = 1; j <= N; j++) (ans.a[i][j] += a[i][k] * other.a[k][j]) %= mod;
		return ans;
	}
} ans, a;
ll n, m;
unordered_map<ll, int> mp;
vector<ll> vec;
void dfs(int id, int last, ll val) {
	if (id == n + 1) {
		vec.push_back(val);
		return;
	}
	for (int i = 0; i < 3; i++)
		if (i != last) {
			dfs(id + 1, i, val * 10 + i);
		}
}
bool check(ll x, ll y) {
	for (int i = 1; i <= n; i++) {
		if (x % 10 == y % 10) return 0;
		x /= 10;
		y /= 10;
	}
	return 1;
}
int mapping(int id) {
	ll val1 = vec[id - 1], tmp = val1;
	for (int i = 1; i <= n - 2; i++) tmp /= 10;
	ll to1 = tmp % 10, to0 = tmp / 10;
	ll val2 = 0, res = 10;
	for (int i = 1; i <= n; i++) {
		int dig1 = val1 % res / (res / 10);
		int dig2;
		if (dig1 == to0)
			dig2 = 0;
		else if (dig1 == to1)
			dig2 = 1;
		else
			dig2 = 2;
		val2 += dig2 * (res / 10);
		res *= 10;
	}
	return mp[val2];
}
ll ksm(ll a, ll b) {
	ll ans = 1;
	for (; b; b >>= 1, a = a * a % mod)
		if (b & 1) ans = ans * a % mod;
	return ans;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	if (n == 1) {
		ll ans = 1;
		cout << ans * 3 * ksm(2, m - 1) % mod;
		return 0;
	}
	dfs(1, -1, 0);
	int cnt = 0;
	for (auto v : vec) {
		mp[v] = ++cnt;
	}
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= cnt / 6; j++) {
			if (check(vec[i - 1], vec[j - 1])) {
				// a.a[i][j] = 1;
				(a.a[mapping(i)][j] += 1) %= mod;
			}
		}
	}
	ans.ide();
	m--;
	for (; m; m >>= 1, a = a * a) {
		if (m & 1) ans = ans * a;
	}
	// for (int i = 1; i <= cnt; i++) {
	// 	for (int j = 1; j <= cnt; j++) {
	// 		cout << ans.a[i][j] << " ";
	// 	}
	// 	cout << '\n';
	// }
	ll sum = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) (sum += ans.a[i][j]) %= mod;
	cout << sum * 6 % mod;
	return 0;
}