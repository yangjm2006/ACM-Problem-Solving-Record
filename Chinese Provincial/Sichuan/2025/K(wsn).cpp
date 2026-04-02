#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
const int INF = 1e9;
int fa[N];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void __()
{
    int n;
    cin >> n;
    vector<int> e[n + 1];
    int id1_to_id2[n + 1], id2_to_id1[n + 1], ans[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int id;
        cin >> id;
        id1_to_id2[id] = i;
        id2_to_id1[i] = id;
        e[i].clear();
    }
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = n; i >= 1; i--)
    {
        int maxx = 0;
        for (auto x : e[id2_to_id1[i]])
        {
            x = id1_to_id2[x];
            if (x > i)
            {
                ans[id2_to_id1[find(x)]] = id2_to_id1[i];
                fa[find(x)] = i;
            }
        }
    }
    ans[id2_to_id1[1]] = 0;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        __();
    return 0;
}
/*
3
3
2 3 1
1 2
2 3
5
2 1 4 5 3
1 2
1 3
2 4
2 5
5
1 2 3 4 5
1 2
1 3
2 4
2 5


*/