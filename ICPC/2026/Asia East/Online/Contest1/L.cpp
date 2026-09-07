#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const ll mod = 998244353;
#define PII pair<int, int>

const ll N = 2e6 + 100;

ll ans, maxx[N];

ll mp[400];

struct Trie {
    int ch[30], dep, cnt;
} tr[N];
int tot;
int res;
int insert(string str) {
    int u = 0;
    for (int i = 0; i < str.size(); i++) {
        int c = mp[str[i]];
        if (!tr[u].ch[c]) {
            tr[u].ch[c] = ++tot;
        }
        int v = tr[u].ch[c];
        tr[v].cnt++;
        tr[v].dep = tr[u].dep + 1;
        u = v;
        if (maxx[tr[v].cnt] < tr[v].dep) {
            ans += (tr[v].dep ^ tr[v].cnt) - (maxx[tr[v].cnt] ^ tr[v].cnt);
            maxx[tr[v].cnt] = tr[v].dep;
        }
    }
    return u;
}
void solve() {
    for (int i = 'a'; i <= 'z'; i++) {
        mp[i] = i - 'a' + 1;
    }
    int n;
    cin >> n;
    for (res = 1; res <= n; res++) {
        string s;
        cin >> s;
        insert(s);
        ans += res;
        cout << ans << '\n';
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