#include <bits/stdc++.h>
using namespace std;
bool check(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }
void __() {
	string s;
	cin >> s;
	if (s.size() != 8) {
		cout << "Well-Being\n";
		return;
	}
	for (int i = 0; i < 8; i += 2) {
		if (check(s[i])) {
			cout << "Well-Being\n";
			return;
		}
	}
	for (int i = 1; i < 8; i += 2) {
		if (!check(s[i])) {
			cout << "Well-Being\n";
			return;
		}
	}
	cout << "Suspected Virus\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}