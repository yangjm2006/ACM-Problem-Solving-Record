#include <bits/stdc++.h>
typedef long long ll;
const ll mod = 998244353;
using namespace std;
const int N = 1e6 + 100;
ll tr[N << 2];
void pushup(int u) { tr[u] = tr[u << 1] + tr[u << 1 | 1]; }
void update(int u, int l, int r, int x) {
    if (l == r) return tr[u]++, void();
    int mid = l + r >> 1;
    if (x <= mid)
        update(u << 1, l, mid, x);
    else
        update(u << 1 | 1, mid + 1, r, x);
    pushup(u);
}
ll query(int u, int l, int r, int L, int R) {
    if (l >= L && r <= R) return tr[u];
    int mid = l + r >> 1;
    ll res = 0;
    if (L <= mid) res += query(u << 1, l, mid, L, R);
    if (R > mid) res += query(u << 1 | 1, mid + 1, r, L, R);
    return res;
}
ll n, a[N], fac[N], s[N], ans = 1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
    for (int i = n; i >= 1; i--) {
        (ans += query(1, 1, n, 1, a[i]) * fac[n - i] % mod) %= mod;
        update(1, 1, n, a[i]);
    }
    cout << ans;
    return 0;
}