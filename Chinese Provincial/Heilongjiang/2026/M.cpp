#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cout << (i + n / 2 - 1) % n + 1 << " ";
	}
	return 0;
}