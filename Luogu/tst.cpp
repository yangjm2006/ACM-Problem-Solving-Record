#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class int_t, class sqr_t = int_t>
struct vec2d {
	int_t x, y;
	vec2d() : x(0), y(0) {}
	vec2d(int_t x, int_t y) : x(x), y(y) {}
	int quad() const {
		if (x > 0 && y >= 0) return 0;
		if (x <= 0 && y > 0) return 1;
		if (x < 0 && y <= 0) return 2;
		if (x >= 0 && y < 0) return 3;
		assert(false);
	}
	bool operator<(const vec2d& rhs) const {
		return quad() < rhs.quad() || (quad() == rhs.quad() && (*this) % rhs > 0);
	}
	vec2d operator+(const vec2d& rhs) const { return vec2d(x + rhs.x, y + rhs.y); }
	vec2d operator-(const vec2d& rhs) const { return vec2d(x - rhs.x, y - rhs.y); }
	sqr_t operator*(const vec2d& rhs) const { return (sqr_t)x * rhs.x + (sqr_t)y * rhs.y; }
	sqr_t operator%(const vec2d& rhs) const { return (sqr_t)x * rhs.y - (sqr_t)rhs.x * y; }
	vec2d& operator+=(const vec2d& rhs) { return *this = *this + rhs; }
	vec2d& operator-=(const vec2d& rhs) { return *this = *this - rhs; }
	vec2d operator-() const { return vec2d(-x, -y); }
	sqr_t sqr() const { return (sqr_t)x * x + (sqr_t)y * y; }
};
typedef vec2d<int, int64_t> vec;
constexpr int MAXN = 50005;
int X;
struct Line {
	vec L, R;
	Line(vec A, vec B) : L(A), R(B) {
		if (assert(A.x != B.x), A.x > B.x) swap(L, R);
	}
	friend bool operator<(const Line& m, const Line& n) {
		int mDx = m.R.x - m.L.x, nDx = n.R.x - n.L.x;
		return (__int128)(X - m.L.x) * (m.R.y - m.L.y) * nDx + (__int128)m.L.y * mDx * nDx <
			   (__int128)(X - n.L.x) * (n.R.y - n.L.y) * mDx + (__int128)n.L.y * mDx * nDx;
	}
};
vector<int> Vx;
struct SegTree {
	SegTree *ls, *rs;
	tree<Line, null_type, less<Line>, rb_tree_tag, tree_order_statistics_node_update> T;
	SegTree(int l = 0, int r = Vx.size() - 1) : ls(nullptr), rs(nullptr) {
		if (r - l > 1) {
			int mid = (l + r) >> 1;
			ls = new SegTree(l, mid);
			rs = new SegTree(mid, r);
		}
	}
	int query(int id, const Line& m, int l = 0, int r = Vx.size() - 1) {
		auto it = T.lower_bound(m);
		if (it != T.end() && !(*it < m) && !(m < *it)) return 0;
		int res = 1 - (T.order_of_key(m) & 1) * 2;
		if (r - l == 1) {
			return res;
		}
		int mid = (l + r) >> 1;
		if (id < mid)
			return res * ls->query(id, m, l, mid);
		else
			return res * rs->query(id, m, mid, r);
	}
	void insert(int l_, int r_, const Line& m, int l = 0, int r = Vx.size() - 1) {
		if (l_ >= r || r_ <= l) return;
		if (l_ <= l && r_ >= r) {
			X = (Vx[l] + Vx[r]) >> 1, T.insert(m);
			return;
		}
		int mid = (l + r) >> 1;
		ls->insert(l_, r_, m, l, mid);
		rs->insert(l_, r_, m, mid, r);
	}
	void erase(int l_, int r_, const Line& m, int l = 0, int r = Vx.size() - 1) {
		if (l_ >= r || r_ <= l) return;
		if (l_ <= l && r_ >= r) {
			X = (Vx[l] + Vx[r]) >> 1, T.erase(m);
			return;
		}
		int mid = (l + r) >> 1;
		ls->erase(l_, r_, m, l, mid);
		rs->erase(l_, r_, m, mid, r);
	}
}* T;
constexpr int MOD = 1000000000;
inline vec reduce(vec& A) { return A = (A - vec(MOD >> 1, MOD >> 1)), A += A; }
inline vec unduce(vec& A) { return A = vec(A.x >> 1, A.y >> 1) + vec(MOD >> 1, MOD >> 1); }
int n, m, Ans, O[MAXN], R[MAXN], LstX, LstY;
vec A[MAXN], Q[MAXN][3];
void add(const vec& A, const vec& B) {
	if (A.x != B.x) {
		Line h(A, B);
		int l = lower_bound(Vx.begin(), Vx.end(), h.L.x) - Vx.begin();
		int r = lower_bound(Vx.begin(), Vx.end(), h.R.x) - Vx.begin();
		return T->insert(l, r, h);
	}
}
void del(const vec& A, const vec& B) {
	if (A.x != B.x) {
		Line h(A, B);
		int l = lower_bound(Vx.begin(), Vx.end(), h.L.x) - Vx.begin();
		int r = lower_bound(Vx.begin(), Vx.end(), h.R.x) - Vx.begin();
		return T->erase(l, r, h);
	}
}
int query(const vec& A) {
	if (A.x < Vx.front() || A.x > Vx.back()) return 1;
	int id = max<int>(lower_bound(Vx.begin(), Vx.end(), X = A.x) - Vx.begin(), 1) - 1;
	int res = T->query(id, Line(vec(-MOD, A.y), vec(MOD, A.y)));
	return res;
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i].x >> A[i].y, Vx.push_back(reduce(A[i]).x);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> O[i];
		if (!O[i]) cin >> R[i];
		for (int j = 0; j < 3; j++) cin >> Q[i][j].x >> Q[i][j].y;
		if (O[i]) reduce(Q[i][0]), reduce(Q[i][1]), Vx.push_back(reduce(Q[i][2]).x);
	}
	sort(Vx.begin(), Vx.end());
	assert(unique(Vx.begin(), Vx.end()) == Vx.end());
	T = new SegTree;
	for (int i = 1; i <= n; i++) add(A[i], A[i % n + 1]);
	vec P0(0, 0);
	switch (query(reduce(P0))) {
		case -1:
			Ans = 0;
			break;
		case 0:
			Ans = 2;
			break;
		case 1:
			Ans = 1;
			break;
	}
	for (int i = 1; i <= m; i++)
		if (!O[i]) {
			LstX = ((int64_t)R[i] * LstX + Q[i][Ans].x) % MOD;
			LstY = ((int64_t)R[i] * LstY + Q[i][Ans].y) % MOD;
			vec P(LstX, LstY);
			reduce(P);
			switch (query(P)) {
				case -1:
					Ans = 0, cout << "in\n";
					break;
				case 0:
					Ans = 2, cout << "bd\n";
					break;
				case 1:
					Ans = 1, cout << "out\n";
					break;
			}
		} else
			del(Q[i][0], Q[i][1]), add(Q[i][0], Q[i][2]), add(Q[i][1], Q[i][2]);
	return 0;
}
