#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long

void solve() {
    ll n, m, pre = 0, ans = 0;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        ll sum = 0;
        for (ll j = 1, t; j <= m; j++) {
            cin >> t;
            sum += t;
        }
        if (sum < pre) {
            ans++;
        }
        pre = sum;
    }
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