#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long

map<string, ll> a;

void solve() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        string s;
        cin >> s;
        a[s]++;
    }
    for (ll i = 1; i <= m; i++) {
        string s;
        cin >> s;
        if (a[s] > 1) {
            cout << "REPEAT" << endl;
        } else if (a[s] == 1) {
            cout << "OK" << endl;
            a[s]++;
        } else {
            cout << "WRONG" << endl;
        }
    }
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