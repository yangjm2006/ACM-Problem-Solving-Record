#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 100;
const int INF = 2e9;
int n, a[N][N];
map<int, int> mp;
void __() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i][i] != 0) {
			cout << "NOT MAGIC";
			return;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			mp[a[i][j]]++;
			if (a[i][j] != a[j][i]) {
				cout << "NOT MAGIC";
				return;
			}
		}
	}
	if (mp.size() > 2) {
		cout << "NOT MAGIC";
		return;
	}
	int minn = INF, num = 0;
	for (auto [x, k] : mp) {
		if (x < minn) {
			num = k;
			minn = x;
		}
	}
	if (num > 1) {
		cout << "NOT MAGIC";
		return;
	}
	cout << "MAGIC";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}