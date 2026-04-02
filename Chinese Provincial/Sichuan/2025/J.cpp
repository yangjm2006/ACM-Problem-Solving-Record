#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define int long long

vector<int> e[1000005];

int a[1000005];
int num[1000005][5]; // 1 21 121 1121

int fa[1000005];

void dfs(int x, int f)
{
    fa[x] = f;
    for (auto c : e[x])
    {
        if (c == f)
            continue;
        dfs(c, x);
        if (a[c] == 1) // C
        {
            num[x][1]++;
            num[x][3] += num[c][2];
            num[x][4] += num[c][3];
        }
        else if (a[c] == 2) // P
        {
            num[x][2] += num[c][1];
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == 'S')
            a[i] = 0;
        else if (c == 'C')
            a[i] = 1;
        else if (c == 'P')
            a[i] = 2;
        else
            a[i] = 114514;
    }
    for (int i = 1; i <= n; i++)
    {
        e[i].clear();
        num[i][0] = 0;
        num[i][1] = 0;
        num[i][2] = 0;
        num[i][3] = 0;
        num[i][4] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, -1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != 0)
            continue;
        ans += num[i][4];
        int nex = fa[i];
        if (nex >= 1 && a[nex] == 1) // c
        {
            ans += num[nex][3];
            nex = fa[nex];
            if (nex >= 1 && a[nex] == 1) // c
            {
                ans += num[nex][2];
                nex = fa[nex];
                if (nex >= 1 && a[nex] == 2) // P
                {
                    ans += num[nex][1] - 1;
                    nex = fa[nex];
                    if (nex >= 1 && a[nex] == 1) // c
                    {
                        ans += 1;
                    }
                }
            }
        }
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
/*
3
5
SCCPC
1 2
2 3
3 4
4 5
7
SCCPCCC
1 2
2 3
3 4
4 5
4 6
4 7
*/