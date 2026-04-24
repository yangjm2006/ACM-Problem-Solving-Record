#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 100;
const ll MOD = 1e9 + 7;
ll ksm(ll a, ll b) {
	ll ans = 1;
	for (; b; b >>= 1, a = a * a % MOD)
		if (b & 1) ans = ans * a % MOD;
	return ans;
}
const ll INV_1000 = ksm(1000, MOD - 2);
ll p, q, r, n, a[N], ans0, ans1, lstans1, ans2, notlose;
void work1(ll x) {
	if (x == 0) return;
	ll P = p * INV_1000 % MOD;
	ll fP = (1 - P + MOD) % MOD;
	ll p0, p1, p2;
	p0 = ksm(fP % MOD, x);
	p1 = x * P % MOD * ksm(fP, x - 1) % MOD;
	ans1 = (ans0 * p1 + ans1 * p0) % MOD;
	ans0 = (ans0 * p0) % MOD;
	ans2 = ((notlose - ans0 - ans1) % MOD + MOD) % MOD;
}
void work2(ll x) {
	if (x == 0) return;
	ll P = (p * INV_1000 % MOD + (1000 - p) * INV_1000 % MOD * q % MOD * INV_1000 % MOD) % MOD;
	ll fP = (1 - P + MOD) % MOD;
	ll p0, p1, p2;
	p0 = ksm(fP % MOD, x);
	p1 = x * P % MOD * ksm(fP, x - 1) % MOD;
	ans1 = (ans0 * p1 + ans1 * p0) % MOD;
	ans0 = (ans0 * p0) % MOD;
	ans2 = ((notlose - ans0 - ans1) % MOD + MOD) % MOD;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> p >> q >> r >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ans0 = notlose = 1;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		ll lost1 = lstans1 * r % MOD * INV_1000 % MOD;
		ans1 = (ans1 - lost1 + MOD) % MOD;
		notlose = (notlose - lost1 + MOD) % MOD;
		sum += a[i];
		if (sum <= 80) {
			work1(a[i]);
		} else if (sum - a[i] < 80) {
			work1(80 - sum + a[i]);
			work2(sum - 80);
		} else {
			work2(a[i]);
		}
		ll lost2 = ans2 % MOD;
		notlose = (notlose - lost2 + MOD) % MOD;
		cout << (lost1 + lost2) % MOD << '\n';
		ans0 = ans0 % MOD;
		ans2 = 0;
		lstans1 = ans1;
	}
	return 0;
}