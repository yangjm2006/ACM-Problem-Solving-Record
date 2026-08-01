#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
const int INF = 1e9;
map<int, int> mp;
int dp[N], stc[N];
void __() {
	int n;
	cin >> n;
	n++;
	if (mp.count(n)) {
		cout << mp[n] << '\n';
		return;
	}
	vector<int> vec;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			vec.push_back(i);
			if (i != n / i) vec.push_back(n / i);
		}
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i <= vec.size(); i++) dp[i] = INF;
	dp[0] = 0;
	int top = 0;
	stc[top++] = 0;
	for (int i = 1; i < vec.size(); i++) {
		for (int j = 0; j < top; j++) {
			dp[i] = min(dp[i], dp[stc[j]] + (vec[i] - 1) / vec[stc[j]]);
		}
		while (dp[stc[top - 1]] >= dp[i]) top--;
		stc[top++] = i;
	}
	cout << (mp[n] = dp[vec.size() - 1]) << '\n';
}
int main() {
	cin.tie(0)->ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}