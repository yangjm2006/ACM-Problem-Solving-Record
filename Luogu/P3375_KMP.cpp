#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 100;
string s, p;
int pi[N];
void __() {
	cin >> s >> p;
	for (int i = 1, j = 0; i < p.size(); i++) {
		while (j != 0 && p[i] != p[j]) j = pi[j - 1];
		if (p[i] == p[j]) j++;
		pi[i] = j;
	}
	for (int i = 0, j = 0; i < s.size(); i++) {
		while (j != 0 && s[i] != p[j]) j = pi[j - 1];
		if (s[i] == p[j]) j++;
		if (j == p.size()) {
			cout << i + 1 - (j - 1) << '\n';
			j = pi[j - 1];
		}
	}
	for (int i = 0; i < p.size(); i++) {
		cout << pi[i] << " ";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}