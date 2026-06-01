#include <bits/stdc++.h>
using namespace std;
#define int long long

void __() {
	string s, t;
	cin >> s >> t;
	// unordered_map<char, unordered_map<char, int>> ss;
	// unordered_map<char, unordered_map<char, int>> tt;
	// unordered_map<char, int> m1;
	// unordered_map<char, int> m2;
	int ss[30][30] = {};
	int tt[30][30] = {};
	int m1[30] = {};
	int m2[30] = {};
	int tmp = s.length();
	for (int i = 0; i < tmp; i++) {
		for (int j = 0; j < 26; j++) {
			if (m1[j] == 0) continue;
			ss[j][s[i] - 'a'] = 1;
		}
		m1[s[i] - 'a'] = 1;
	}
	tmp = t.length();
	for (int i = 0; i < tmp; i++) {
		for (int j = 0; j < 26; j++) {
			if (m2[j] == 0) continue;
			tt[j][t[i] - 'a'] = 1;
		}
		m2[t[i] - 'a'] = 1;
	}
	for (int i = 0; i <= 25; i++) {
		for (int j = 0; j <= 25; j++) {
			if (ss[i][j] >= 1 && tt[i][j] >= 1) {
				cout << char('a' + i) << char('a' + j) << endl;
				return;
			}
		}
	}
	cout << "HENG!" << endl;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		__();
	}
	return 0;
}