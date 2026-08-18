#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;
const int INF = 1e9;

struct Tree {
	struct Node {
		int ls, rs, sum;
		Node() : ls(0), rs(0), sum(0) {}
	} tr[N * 40];
	int root[N];
	int cnt = 0;
	void pushup(int u) { tr[u].sum = tr[tr[u].ls].sum + tr[tr[u].rs].sum; }
	void copy(int& u) {
		tr[++cnt] = tr[u];
		u = cnt;
	}
	void update(int& u, int l, int r, int x, int y) {
		copy(u);
		if (l == r) return tr[u].sum += y, void();
		int mid = (l + r) / 2;
		if (x <= mid)
			update(tr[u].ls, l, mid, x, y);
		else
			update(tr[u].rs, mid + 1, r, x, y);
		pushup(u);
	}
	int query(int u1, int u2, int l, int r, int k) {
		if (l == r) return l;
		int x = tr[tr[u1].ls].sum - tr[tr[u2].ls].sum, mid = (l + r) / 2;
		if (x >= k) return query(tr[u1].ls, tr[u2].ls, l, mid, k);
		return query(tr[u1].rs, tr[u2].rs, mid + 1, r, k - x);
	}
} tree;

void __() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		tree.update(tree.root[i] = tree.root[i - 1], 0, INF, x, 1);
	}
	for (int i = 1; i <= m; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << tree.query(tree.root[r], tree.root[l - 1], 0, INF, k) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}