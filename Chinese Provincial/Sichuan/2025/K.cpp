#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
const int INF = 1e9;
int fa[N];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
vector<int> e[N];
int ans[N], id1_to_id2[N], id2_to_id1[N];
void __()
{
    int n;
    cin >> n;
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
    ans[id2_to_id1[1]] = 0;
    for (int i = n; i >= 2; i--)
    {
        int maxx = 0;
        for (auto x : e[id2_to_id1[i]])
        {
            int fx = find(id1_to_id2[x]);
            if (fx < i)
            {
                maxx = max(maxx, fx);
            }
        }
        ans[id2_to_id1[i]] = id2_to_id1[maxx];
        fa[find(i)] = maxx;
    }
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