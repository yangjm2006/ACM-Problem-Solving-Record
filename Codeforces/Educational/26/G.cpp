#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 1e5 + 100;
const int INF = 1e9;

pair<ll, ll>& operator+=(pair<ll, ll>& a, const pair<ll, ll>& b) {
	a.first += b.first;
	a.second += b.second;
	return a;
}

struct Tree {
	struct Node {
		int ls, rs;
		ll a, b;
		Node() : ls(0), rs(0), a(0), b(0) {}
	} tr[N * 30 * 3];
	int root[N];
	int cnt = 0;
	void pushup(int u) {
		tr[u].a = tr[tr[u].ls].a + tr[tr[u].rs].a;
		tr[u].b = tr[tr[u].ls].b + tr[tr[u].rs].b;
	}
	void copy(int& u) {
		tr[++cnt] = tr[u];
		u = cnt;
	}
	void update(int& u, int l, int r, int x, ll a, ll b) {
		copy(u);
		if (l == r) return tr[u].a += a, tr[u].b += b, void();
		int mid = (l + r) / 2;
		if (x <= mid)
			update(tr[u].ls, l, mid, x, a, b);
		else
			update(tr[u].rs, mid + 1, r, x, a, b);
		pushup(u);
	}
	pair<ll, ll> query(int u1, int u2, int l, int r, int L, int R) {
		if (l >= L && r <= R) return make_pair(tr[u1].a - tr[u2].a, tr[u1].b - tr[u2].b);
		int mid = (l + r) / 2;
		pair<ll, ll> res(0, 0);
		if (L <= mid) res += query(tr[u1].ls, tr[u2].ls, l, mid, L, R);
		if (R > mid) res += query(tr[u1].rs, tr[u2].rs, mid + 1, r, L, R);
		return res;
	}
} tree;

void __() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x1, x2, y1, a, b, y2;
		cin >> x1 >> x2 >> y1 >> a >> b >> y2;
		tree.update(tree.root[i] = tree.root[i - 1], 0, INF, 0, 0, y1);
		tree.update(tree.root[i], 0, INF, x1 + 1, a, b - y1);
		tree.update(tree.root[i], 0, INF, x2 + 1, -a, y2 - b);
	}
	cin >> m;
	ll lastans = 0;
	while (m--) {
		pair<ll, ll> pr;
		ll l, r, x;
		cin >> l >> r >> x;
		x = (x + lastans) % INF;
		pr = tree.query(tree.root[r], tree.root[l - 1], 0, INF, 0, x);
		cout << (lastans = pr.first * x + pr.second) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}