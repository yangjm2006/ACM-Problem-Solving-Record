#include <bits/stdc++.h>
using namespace std;
void __() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == '1') cnt++;
	}
	for (int i = 1; i <= n - 2; i++) cout << "&";
	if (cnt == n)
		cout << "^";
	else
		cout << "&";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}