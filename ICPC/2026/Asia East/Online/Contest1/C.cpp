#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const ll mod = 998244353;

void solve() {
    ll n, m;
    cin >> n >> m;
    ll in[n + 10] = {}, ans[n + 10] = {}, pos = 0;
    vector<ll> e[n + 10];
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (ll i = 1, l, r, u, v; i <= m; i++) {
        cin >> l >> r >> u;
        for (ll j = l + 1; j <= r; j++) {
            cin >> v;
            e[u].push_back(v);
            in[v]++;
            u = v;
        }
    }
    for (ll i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        ll cur = q.top();
        q.pop();
        ans[cur] = ++pos;
        for (auto to : e[cur]) {
            in[to]--;
            if (in[to] == 0) {
                q.push(to);
            }
        }
    }
    if (pos == n) {
        for (ll i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}