#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll unsigned long long
const ll mod = 998244353;

const int N = 110;

vector<int> e[N];
int dis[N];
int n, m, C;
int bfs() {
    for (int i = 1; i <= n; i++)
        dis[i] = 100000000;
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : e[u]) {
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[n];
}

struct Matrix {
    ll val[N][N];
    Matrix() {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                val[i][j] = 0;
    }
    void IE() {
        for (int i = 0; i < N; i++)
            val[i][i] = 1;
    }
    Matrix operator+(const Matrix &other) const {
        Matrix ans;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                ans.val[i][j] = val[i][j] + other.val[i][j];
        return ans;
    }
    Matrix operator*(const Matrix &other) const {
        Matrix ans;
        for (int i = 0; i < N; i++)
            for (int k = 0; k < N; k++)
                for (int j = 0; j < N; j++)
                    ans.val[i][j] += val[i][k] * other.val[k][j];
        return ans;
    }
};
int c[N];
map<ll, Matrix> O, mp;
void solve() {
    cin >> n >> m >> C;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    C -= c[1];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        O[c[v]].val[u][v]++;
        e[u].push_back(v);
    }
    int N = bfs();
    mp = O;
    for (int i = 1; i <= N - 1; i++) {
        map<ll, Matrix> now;
        for (auto &[d1, m1] : O) {
            for (auto &[d2, m2] : mp) {
                if (d1 + d2 <= C)
                    now[d1 + d2] = now[d1 + d2] + m1 * m2;
            }
        }
        mp = now;
    }
    ll ans = 0;
    for (auto &[d, m] : mp) {
        ans += m.val[1][n];
        cout << d + c[1] << ":\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                if (m.val[i][j]) {
                    cout << i << "-" << j << ":" << m.val[i][j] << "   ";
                }
        }
        cout << '\n';
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}