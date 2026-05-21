#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int fa[N], a[N], b[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n + 1; i++) fa[i] = i;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			fa[find(i)] = find(i + 1);
		}
	}
	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int o = 1; o <= m; o++) {
		int ans = 0, tmp = b[o];
		while (tmp <= n) {
			if (find(tmp) != tmp) {
				ans += find(tmp) - tmp;
				tmp = find(tmp);
			} else {
				ans++;
				a[tmp]--;
				if (a[tmp] == 1) {
					fa[find(tmp)] = find(tmp + 1);
				}
				tmp += a[tmp] + 1;
			}
			// cout << ans << " " << tmp << "!!\n";
		}
		cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}