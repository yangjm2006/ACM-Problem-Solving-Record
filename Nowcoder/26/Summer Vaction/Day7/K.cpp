#include <bits/stdc++.h>
using namespace std;
string make(string s, int cnt) {
	string s;
	// for()
}
string ans[30], s[30];
int vis[30];
void __() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		getline(cin, s[i]);
	}
	for (;;) {
		for (int i = 1; i <= n; i++) {
			if (vis[i] != -1) {
				ans[i] = make(s[i], vis[i]);
			}
		}
		for (int i = 1; i <= n; i++) {
			bool f = 0;
			if (vis[i] != -1) {
				for (int j = 1; j <= n; j++) {
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}