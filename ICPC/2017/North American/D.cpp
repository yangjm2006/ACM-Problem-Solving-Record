#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const int INF = 1e9;
int fa[N], sz[N];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
set<pair<int, int>> st[N];
void merge(int u, int v)
{
    if (find(u) == find(v))
        return;
    if (sz[fa[u]] < sz[fa[v]])
        swap(u, v);
    for (auto x : st[fa[v]])
    {
        if (st[fa[u]].lower_bound(make_pair(x.first + 1, 0)) == st[fa[u]].begin() || (*prev(st[fa[u]].lower_bound(make_pair(x.first + 1, 0)))).second < x.second)
        {
            while (st[fa[u]].lower_bound(make_pair(x.first, 0)) != st[fa[u]].end() && (*st[fa[u]].lower_bound(make_pair(x.first, 0))).second <= x.second)
            {
                st[fa[u]].erase(st[fa[u]].lower_bound(make_pair(x.first, 0)));
            }
            st[fa[u]].insert(x);
        }
    }
    sz[fa[u]] += sz[fa[v]];
    fa[fa[v]] = fa[u];
}
int n, w[N], ans;
vector<int> e[N];
void dfs(int u)
{
    int cnt1 = 0, cnt2 = 0, fv = 0, w2 = 0;
    fa[0] = sz[0] = 0;
    for (auto v : e[u])
    {
        dfs(v);
        if ((*prev(st[find(v)].lower_bound(make_pair(w[u], 0)))).first < w[u])
        {
            cnt1 += (*prev(st[find(v)].lower_bound(make_pair(w[u], 0)))).second;
        }
        cnt2 += (*prev(st[find(v)].end())).second;
        w2 = max(w2, (*prev(st[find(v)].end())).first);
        merge(fv, v);
    }
    pair<int, int> p1 = make_pair(w[u], cnt1 + 1), p2 = make_pair(w2, cnt2);
    if (p1 > p2)
        swap(p1, p2);
    if (p1.first == p2.first)
    {
        st[u].insert(p2);
    }
    else
    {
        if (p1.second >= p2.second)
            st[u].insert(p1);
        else
        {
            st[u].insert(p1);
            st[u].insert(p2);
        }
    }
    merge(find(fv), u);
    ans = max(ans, max(cnt1 + 1, cnt2));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        int v;
        cin >> v;
        e[v].push_back(i);
    }
    dfs(1);
    cout << ans;
    return 0;
}