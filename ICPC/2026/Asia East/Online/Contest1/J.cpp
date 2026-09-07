#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll unsigned long long
const ll mod = 998244353;
const int N = 4e6 + 100;

int tr[N], tag[N], a[N];
void pushup(int u) { tr[u] = tr[u << 1] + tr[u << 1 | 1]; }

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = a[l];
        tag[u] = 0;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void pushdown(int u, int l, int r) {
    tag[u << 1] ^= tag[u];
    tag[u << 1 | 1] ^= tag[u];
    int mid = l + r >> 1;
    tr[u << 1] = (mid - l + 1) - tr[u << 1];
    tr[u << 1 | 1] = (r - mid) - tr[u << 1 | 1];
    tag[u] = 0;
}

void update(int u, int l, int r, int L, int R) {
    // cout << u << " " << l << " " << r << " " << L << " " << R << "!!!\n";
    if (l >= L && r <= R) {
        tag[u] ^= 1;
        tr[u] = r - l + 1 - tr[u];
        return;
    }
    pushdown(u, l, r);
    int mid = l + r >> 1;
    if (L <= mid)
        update(u << 1, l, mid, L, R);
    if (R > mid)
        update(u << 1 | 1, mid + 1, r, L, R);
    pushup(u);
}

int query(int u, int l, int r, int L, int R) {
    // cout << u << " " << l << " " << r << "???\n";
    if (l >= L && r <= R) {
        return tr[u];
    }
    int mid = l + r >> 1, res = 0;
    pushdown(u, l, r);
    if (L <= mid)
        res += query(u << 1, l, mid, L, R);
    if (R > mid)
        res += query(u << 1 | 1, mid + 1, r, L, R);
    pushup(u);
    return res;
}

int n, m;
int findR(int pos) {
    int l = pos - 1, r = n;
    while (l < r) {
        int mid = (l + r >> 1) + 1;
        if (query(1, 1, n, pos, mid) == mid - pos + 1)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int findL(int pos) {
    int l = 1, r = pos + 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (query(1, 1, n, mid, pos) == pos - mid + 1)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c == 'N') {
            a[i] = 0;
        } else {
            a[i] = 1;
        }
    }
    build(1, 1, n);
    while (m--) {
        for (int i = 1; i <= n; i++) {
            if (query(1, 1, n, i, i) == 1) {
                cout << "N";
            } else
                cout << "H";
        }
        cout << '\n';
        int op, p, k;
        cin >> op >> p >> k;
        if (op == 1) {
            for (; p <= n && k; p++) {
                if (k & 1) {
                    update(1, 1, n, p, min(n, findR(p) + 1));
                }
                k /= 2;
            }
        } else if (op == 2) {
            update(1, 1, n, 1, n);
            for (; p <= n && k; p++) {
                if (k & 1) {
                    update(1, 1, n, p, min(n, findR(p) + 1));
                }
                k /= 2;
            }
            update(1, 1, n, 1, n);
        } else if (op == 3) {
            for (; p >= 1 && k; p--) {
                if (k & 1) {
                    update(1, 1, n, max(1ll, findL(p) - 1), p);
                }
                k /= 2;
            }
        } else {
            update(1, 1, n, 1, n);
            for (; p >= 1 && k; p--) {
                if (k & 1) {
                    update(1, 1, n, max(1ll, findL(p) - 1), p);
                }
                k /= 2;
            }
            update(1, 1, n, 1, n);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (query(1, 1, n, i, i) == 1) {
            cout << "N";
        } else
            cout << "H";
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}