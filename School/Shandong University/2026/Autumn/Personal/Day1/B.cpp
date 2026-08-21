#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 100;
bool vis[N];
void __() {
	ll maxx = 0;
	int n;
	cin >> n;
	ll now1 = 0, now2 = 0;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == '1')
			vis[i] = 1;
		else
			vis[i] = 0;
		if (vis[i] == 1) {
			if (vis[i - 1] == 1) {
				maxx = max(maxx, now1);
				now1 = 1;
				now2 = 0;
			} else {
				now1 = now2 + 1;
				now2 = 0;
			}
		} else {
			if (vis[i - 1] == 1) {
				now1 += i - 1;
				now2 += n - i;
			} else {
				now1 += i - 1;
				now2 += n - i;
			}
		}
		maxx = max(maxx, max(now1, now2));
	}
	cout << maxx << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}