#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 100;
int find[N], maxx[N];
int n, m;
int mapping(int x, int y) { return (x - 1) * m + y; }
void __() {
	cin >> n >> m;
	int a[n + 10][m + 10] = {};
	int q;
	cin >> q;
	int l = 0;
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int x, y, v;
			cin >> x >> y >> v;
			x ^= l;
			y ^= l;
		} else {
			int x, y;
			cin >> x >> y;
			x ^= l;
			y ^= l;
			// l = maxx[find(mapping(x, y))] - a[x][y];
		}
		cout << l << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}