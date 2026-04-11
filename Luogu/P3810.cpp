#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;

struct Node {
    int x, y, z;
    bool operator<(const Node& _) const {
        if (x == _.x) {
            if (y == _.y) return z < _.z;
            return y < _.y;
        }
        return x < _.x;
    }
    bool operator==(const Node& _) const {
        return x == _.x && y == _.y && z == _.z;
    }
} a[N];
int n, k, ans[N];

struct In_Tree {
    int sum, ls, rs;
} in_tree[N * 400];
int in_tot;
void in_pushup(int u) {
    in_tree[u].sum = in_tree[in_tree[u].ls].sum + in_tree[in_tree[u].rs].sum;
}
void in_update(int& u, int l, int r, int x, int num) {
    if (!u) u = ++in_tot;
    if (l == r) return in_tree[u].sum += num, void();
    int mid = l + r >> 1;
    if (x <= mid)
        in_update(in_tree[u].ls, l, mid, x, num);
    else
        in_update(in_tree[u].rs, mid + 1, r, x, num);
    in_pushup(u);
}
int in_query(int u, int l, int r, int L, int R) {
    if (!u) return 0;
    if (l >= L && r <= R) return in_tree[u].sum;
    int mid = l + r >> 1, res = 0;
    if (L <= mid) res += in_query(in_tree[u].ls, l, mid, L, R);
    if (R > mid) res += in_query(in_tree[u].rs, mid + 1, r, L, R);
    return res;
}

struct Out_Tree {
    int in_root, ls, rs;
} out_tree[N * 20];
int out_tot;
void out_update(int& u, int l, int r, int x, int y, int num) {
    if (!u) u = ++out_tot;
    in_update(out_tree[u].in_root, 1, k, y, num);
    if (l == r) return;
    int mid = l + r >> 1;
    if (x <= mid)
        out_update(out_tree[u].ls, l, mid, x, y, num);
    else
        out_update(out_tree[u].rs, mid + 1, r, x, y, num);
}
int out_query(int u, int l, int r, int out_L, int out_R, int in_L, int in_R) {
    if (!u) return 0;
    if (l >= out_L && r <= out_R)
        return in_query(out_tree[u].in_root, 1, k, in_L, in_R);
    int mid = l + r >> 1, res = 0;
    if (out_L <= mid)
        res += out_query(out_tree[u].ls, l, mid, out_L, out_R, in_L, in_R);
    if (out_R > mid)
        res += out_query(out_tree[u].rs, mid + 1, r, out_L, out_R, in_L, in_R);
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y >> a[i].z;
    sort(a + 1, a + 1 + n);
    int root = 0;
    for (int i = 1; i <= n;) {
        int num = 1;
        while (i < n && a[i] == a[i + 1]) {
            i++;
            num++;
        }
        out_update(root, 1, k, a[i].y, a[i].z, num);
        ans[out_query(root, 1, k, 1, a[i].y, 1, a[i].z)] += num;
        i++;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
    return 0;
}