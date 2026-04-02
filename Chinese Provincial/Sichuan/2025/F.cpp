#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    ll n, ans = 0, cntq = 0, cur = 0;
    string s;
    cin >> n >> s;
    s = " " + s;
    ll pre1[n + 10] = {}, suc0[n + 10] = {}, preq[n + 10] = {};
    for (ll i = 1; i <= n; i++)
    {
        if (s[i] == '0')
        {
            suc0[i] = 1;
        }
        if (s[i] == '1')
        {
            pre1[i] = 1;
        }
        if (s[i] == '?')
        {
            preq[i] = 1;
            cntq++;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        pre1[i] += pre1[i - 1];
        preq[i] += preq[i - 1];
    }
    for (ll i = n; i >= 1; i--)
    {
        suc0[i] += suc0[i + 1];
    }
    for (ll i = 1; i <= n; i++)
    {
        if (s[i] != '1')
        {
            cur += pre1[i];
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        if (s[i] == '?')
        {
            cur += (cntq - preq[i]) + suc0[i];
            cur -= (preq[i] - 1) + pre1[i];
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*

4
3
110
3
1?0
4
????
7
1?0?0?1

*/