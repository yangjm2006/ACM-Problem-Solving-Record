#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
const double eps = 1e-9;
const long long INF = 1e9;
int curx;
struct half_circle
{
    long long type, x, y, r, id;
    double f(long long _) const
    {
        if (type == 1)
            return y - sqrt(r * r - (x - _) * (x - _));
        return y + sqrt(r * r - (x - _) * (x - _));
    }
    bool operator<(const half_circle &_) const
    {
        if (x == _.x && y == _.y && r == _.r)
            return this->type == 1 && _.type == 2;
        return f(curx) < _.f(curx) + eps;
    }
} o[N];
bool cmp(half_circle a, half_circle b)
{
    if (a.x - a.r == b.x - b.r)
        return a.id < b.id;
    return a.x - a.r < b.x - b.r;
}
int n, depth[N];
long long R[N];
map<long long, vector<half_circle>> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y, r;
        cin >> x >> y >> r;
        R[i] = r;
        o[2 * i - 1].x = o[2 * i].x = x;
        o[2 * i - 1].y = o[2 * i].y = y;
        o[2 * i - 1].r = o[2 * i].r = r;
        o[2 * i - 1].type = 1;
        o[2 * i - 1].id = 2 * i - 1;
        o[2 * i].type = 2;
        o[2 * i].id = 2 * i;
        mp[x + r].push_back(o[2 * i - 1]);
        mp[x + r].push_back(o[2 * i]);
    }
    sort(o + 1, o + 2 * n + 1, cmp);
    set<half_circle> st;
    st.insert((half_circle){1, 0, -INF, INF, 0});
    for (int i = 1; i <= n; i++)
    {
        while (mp.size() && mp.begin()->first <= o[2 * i].x - o[2 * i].r)
        {
            vector<half_circle> vec = mp.begin()->second;
            for (auto v : vec)
                st.erase(v);
            mp.erase(mp.begin());
        }
        curx = o[2 * i].x - o[2 * i].r;
        half_circle u = *prev(st.lower_bound(o[2 * i]));
        if (u.type == 1)
            depth[(o[2 * i].id + 1) / 2] = depth[(u.id + 1) / 2] + 1;
        else
            depth[(o[2 * i].id + 1) / 2] = depth[(u.id + 1) / 2];
        st.insert(o[2 * i - 1]);
        st.insert(o[2 * i]);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] % 2 == 1)
            ans += R[i] * R[i];
        else
            ans -= R[i] * R[i];
    }
    cout << ans;
    return 0;
}