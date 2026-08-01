#include <bits/stdc++.h>
#define For(i, j, k) for (int i = j; i <= k; ++i)
using namespace std;
typedef long long ll;
const ll mod = 998244353;

int read() {
	int x = 0, fh = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar())
		if (ch == '-') fh = -1;
	for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
	return x * fh;
}
ll readll() {
	ll x = 0, fh = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar())
		if (ch == '-') fh = -1;
	for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
	return x * fh;
}
ll ksm(ll x, ll p) {
	ll ans = 1;
	while (p) {
		if (p & 1) ans = ans * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return ans;
}

typedef vector<vector<ll> > mat;

vector<int> getcol(int s, int n) {
	vector<int> a(n);
	a[0] = 0;
	a[1] = 1;
	For(i, 2, n - 1) {
		if ((s >> (i - 2)) & 1)
			a[i] = a[i - 2];
		else
			a[i] = 3 - a[i - 1] - a[i - 2];
	}
	return a;
}
int getstate(const vector<int>& a) {
	int n = a.size(), s = 0;
	For(i, 2, n - 1) if (a[i] == a[i - 2]) s |= 1 << (i - 2);
	return s;
}
void dfs(int p, const vector<int>& a, vector<int>& b, vector<ll>& row) {
	int n = a.size();
	if (p == n) {
		++row[getstate(b)];
		return;
	}
	For(c, 0, 2) {
		if (c == a[p]) continue;
		if (p && c == b[p - 1]) continue;
		b[p] = c;
		dfs(p + 1, a, b, row);
	}
}
mat mul(const mat& a, const mat& b) {
	int n = a.size();
	mat c(n, vector<ll>(n, 0));
	For(i, 0, n - 1) For(k, 0, n - 1) if (a[i][k]) {
		For(j, 0, n - 1) c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
	}
	return c;
}
mat mpow(mat a, ll p) {
	int n = a.size();
	mat ans(n, vector<ll>(n, 0));
	For(i, 0, n - 1) ans[i][i] = 1;
	while (p) {
		if (p & 1) ans = mul(ans, a);
		a = mul(a, a);
		p >>= 1;
	}
	return ans;
}

int main() {
	int n = read();
	ll m = readll();  // mod=readll();
	if (n == 1) {
		printf("%lld\n", 3 * ksm(2, m - 1) % mod);
		return 0;
	}
	int S = 1 << (n - 2);
	mat a(S, vector<ll>(S, 0));
	For(i, 0, S - 1) {
		vector<int> col = getcol(i, n), b(n);
		dfs(0, col, b, a[i]);
	}
	mat res = mpow(a, m - 1);
	ll ans = 0;
	For(i, 0, S - 1) For(j, 0, S - 1) ans = (ans + 6 * res[i][j]) % mod;
	printf("%lld\n", ans);
	return 0;
}