#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 100;
const int INF = 1e9;
ll v[N], s[N];
struct Tree {
	ll min, val;
} tr[N << 2];
int n, m;
set<int> st;
vector<int> vec[N];
void init() {
	st.clear();
	for (int i = 1; i <= max(n, m); i++) {
		s[i] = 0;
		vec[i].clear();
	}
}
void pushdown(int u) {
	tr[u << 1].val += tr[u].val;
	tr[u << 1 | 1].val += tr[u].val;
	tr[u << 1].min += tr[u].val;
	tr[u << 1 | 1].min += tr[u].val;
	tr[u].val = 0;
}
void pushup(int u) { tr[u].min = min(tr[u << 1].min, tr[u << 1 | 1].min); }
void build(int u, int l, int r) {
	if (l == r) {
		tr[u].min = tr[u].val = s[l];
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
	tr[u].val = 0;
}
void update(int u, int l, int r, int L, int R, int x) {
	if (l >= L && r <= R) {
		tr[u].val += x;
		tr[u].min += x;
		return;
	}
	pushdown(u);
	int mid = l + r >> 1;
	if (mid >= L) update(u << 1, l, mid, L, R, x);
	if (mid < R) update(u << 1 | 1, mid + 1, r, L, R, x);
	pushup(u);
}
void work(int u, int l, int r) {
	if (tr[u].min != 0) return;
	if (l == r) {
		st.insert(l);
		tr[u].val = tr[u].min = INF;
		return;
	}
	pushdown(u);
	int mid = l + r >> 1;
	work(u << 1, l, mid);
	work(u << 1 | 1, mid + 1, r);
	pushup(u);
}
int query(int u, int l, int r, int pos) {
	if (l == r) {
		return tr[u].val;
	}
	int mid = l + r >> 1;
	pushdown(u);
	int tmp;
	if (pos <= mid) {
		tmp = query(u << 1, l, mid, pos);
	} else {
		tmp = query(u << 1 | 1, mid + 1, r, pos);
	}
	pushup(u);
	return tmp;
}
struct Query {
	int val, id;
	bool operator<(const Query& other) const { return val > other.val; }
} b[N], tmp[N];
ll fans[N];
void __() {
	ll a;
	cin >> n >> a;
	init();
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		tmp[i].val = v[i];
		tmp[i].id = i;
	}
	sort(tmp + 1, tmp + 1 + n);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1];
		if (v[i] <= a) {
			s[i]++;
			ans -= v[i];
		}
	}
	ans += s[n] * v[n];
	s[n] = 0;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> b[i].val;
		b[i].id = i;
	}
	sort(b + 1, b + 1 + m);
	int tp = 1;
	for (int i = 1; i <= m; i++) {
		while (tp <= n && tmp[tp].val >= b[i].val) {
			if (s[tmp[tp].id]) vec[i].push_back(tmp[tp].id);
			tp++;
		}
		sort(vec[i].begin(), vec[i].end());
	}
	build(1, 1, n);
	work(1, 1, n);
	for (int i = 1; i <= m; i++) {
		for (int x : vec[i]) {
			if (query(1, 1, n, x) <= 0) continue;
			int y = *st.lower_bound(x);
			ans += v[x] - v[y];
			update(1, 1, n, x, y - 1, -1);
			work(1, 1, n);
		}
		fans[b[i].id] = ans;
	}
	for (int i = 1; i <= m; i++) cout << fans[i] << " ";
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}