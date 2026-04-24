#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 100;
ll tar;
int a[N], n;
bool dfs(int sum, int idx, __int128 tot) {
	if (tot > tar) return 0;
	if (sum == 0 && tot == tar) {
		cout << "Yes\n" << n << '\n';
		for (int i = 1; i < idx; i++) {
			for (int j = 1; j <= a[i]; j++) cout << i << " ";
		}
		return 1;
	}
	for (int i = a[idx - 1]; i <= sum; i++) {
		a[idx] = i;
		if (dfs(sum - i, idx + 1, tot + (1ll << n) - (1ll << (n - i)))) return 1;
	}
	return 0;
}
void __() {
	cin >> tar;
	a[0] = 1;
	for (int i = 1; i <= 60; i++) {
		if ((1ll << i) - 1 <= tar && (__int128)i * (1ll << (i - 1)) >= tar) {
			n = i;
			if (dfs(i, 1, 0)) return;
		}
	}
	cout << "No\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}