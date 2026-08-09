#include <bits/stdc++.h>
using namespace std;
bool isp(int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return 0;
	return 1;
}
void __() {
	int n;
	cin >> n;
	if (n == 2) {
		cout << "1 2";
	} else if (n == 3) {
		cout << "-1";
	} else {
		if (isp(n - 1)) {
			if (n == 4 || n == 6)
				cout << "-1";
			else {
				for (int i = 1; i <= n - 4; i++) cout << i << " ";
				cout << n << " " << n - 1 << " " << n - 2 << " " << n - 3;
			}
		} else {
			for (int i = 1; i <= n; i++) cout << i << " ";
		}
	}
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}