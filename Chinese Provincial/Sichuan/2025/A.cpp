#include <bits/stdc++.h>
typedef long long ll;
#define PII pair<ll, ll>
using namespace std;

const ll N = 400, MAX_M = 200 * 300 + 10, inf = 1e17;

struct Data
{
    ll a, b, v;
};

struct CompareMin
{
    bool operator()(const Data &a, const Data &b) const
    {
        return a.b > b.b;
    }
};

ll n, m, suma, sumb, curans;
vector<Data> e[N];
ll dis[N][MAX_M], vis[N][MAX_M], mdis[N];
priority_queue<Data, vector<Data>, CompareMin> q;

void dij()
{
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= suma; j++)
        {
            dis[i][j] = inf;
            vis[i][j] = 0;
        }
    }
    dis[1][0] = 0;
    q.push((Data){0, 0, 1});
    while (!q.empty())
    {
        auto [cura, curb, now] = q.top();
        q.pop();
        if (vis[now][cura])
            continue;
        if (now == n)
        {
            curans = min(curans, dis[now][cura] * cura);
        }
        for (auto [nxta, nxtb, to] : e[now])
        {
            if (cura + nxta > suma)
            {
                continue;
            }
            if (vis[to][cura + nxta])
                continue;
            if (curans <= (dis[now][cura] + nxtb) * (cura + nxta))
                continue;
            if (dis[to][cura + nxta] > dis[now][cura] + nxtb)
            {
                dis[to][cura + nxta] = dis[now][cura] + nxtb;
                q.push((Data){cura + nxta, dis[to][cura + nxta], to});
            }
        }
    }
}

void solve()
{
    vector<ll> tmp;
    cin >> n >> m;
    suma = 0;
    sumb = 0;
    curans = inf;
    for (ll i = 1; i <= n; i++)
    {
        e[i].clear();
    }
    for (ll i = 1, u, v, a, b; i <= m; i++)
    {
        cin >> u >> v >> a >> b;
        tmp.push_back(a);
        suma += a;
        sumb += b;
        e[u].push_back((Data){a, b, v});
    }
    sort(tmp.begin(), tmp.end());
    ll tmplen = tmp.size();
    for (ll i = tmplen - 1; i >= max(0ll, tmplen - n); i--)
    {
        suma += tmp[i];
    }
    dij();
    ll ans = inf, ansa = -1, ansb = -1;
    for (ll i = 1; i <= suma; i++)
    {
        if (dis[n][i] > sumb)
        {
            continue;
        }
        if (dis[n][i] * i < ans)
        {
            ans = dis[n][i] * i;
            ansa = i, ansb = dis[n][i];
        }
    }
    cout << ansa << " " << ansb << endl;
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
1
300 4
1 2 1 1
2 3 1 1
3 2 1 1
3 300 1 1

*/