#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
const int INF = 1e9;
int a[N];
struct node {
	int col, len;
	node(int c, int l) : col(c), len(l) {}
	bool operator==(const node& other) { return col == other.col && len == other.len; }
};
int n;
bool check(int k) {
	vector<node> v;
	for (int i = 1; i <= n; i++) {
		int x = a[i] >= k ? 1 : 0;
		if (v.size() && v[v.size() - 1].col == x) {
			v[v.size() - 1].len++;
			if (x == 0) {
				++((--v[v.size() - 1].len) %= 2);
			}
		} else {
			v.push_back(node(x, 1));
		}
	}
	vector<node> vec;
	for (auto x : v) {
		if (vec.size() >= 2 && x == node(0, 2) && vec[vec.size() - 1] == node(1, 1) &&
			vec[vec.size() - 2] == node(0, 2)) {
			vec.pop_back();
			vec.pop_back();
			vec.push_back(node(0, 1));
		} else if (vec.size() >= 1 && x == node(0, 1) && vec[vec.size() - 1] == node(1, 1)) {
			vec.pop_back();
		} else {
			vec.push_back(x);
		}
	}
	int cnt1 = 0, cnt0 = 0;
	for (auto [col, len] : vec) {
		if (col)
			cnt1 += len;
		else
			cnt0 += len;
	}
	return cnt1 > cnt0;
}
void __() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 1, r = INF;
	while (l < r) {
		int mid = (l + r >> 1) + 1;
		if (check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	cout << l << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}