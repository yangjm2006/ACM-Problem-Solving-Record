#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const ll mod = 998244353;

ll n, p[100000 + 10];

void init() {
    ll b[n + 10] = {};
    for (ll i = 1; i <= n; i++) {
        b[p[i]]++;
    }
    memset(p, 0, sizeof(p));
    ll fill = 0, cur0 = 0;
    for (ll i = 1; i <= n; i++) {
        if (b[fill]) {
            p[i] = fill;
            b[fill]--;
            cur0++;
        } else {
            p[i] = cur0;
            b[cur0]--;
            fill++;
        }
        // cout << p[i] << " ";
    }
    // cout << endl;
}

void solve() {
    ll ans = 1;
    cin >> n;
    ll cur0, cur1;
    for (ll i = 1; i <= n; i++) {
        cin >> p[i];
    }
    init();
    if (p[1] != 0) {
        cout << 0 << endl;
        return;
    }
    cur0 = 1;
    for (ll i = 2; i <= n; i++) {
        cur1 = i - 1 - cur0;
        if (p[i] == cur0 || p[i] == cur1) {
            if (cur0 == cur1) {
                ans = ans * 2 % mod;
                cur0++;
            } else if (p[i] == cur0) {
            } else {
                cur0++;
            }
        } else {
            ans = 0;
            break;
        }
    }
    ans = ans * 2 % mod;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}