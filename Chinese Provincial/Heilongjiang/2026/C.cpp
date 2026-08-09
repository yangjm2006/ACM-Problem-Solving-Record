#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int a[N];
void make(int n) {
	for (int i = 1; i <= n / 3; i++) {
		a[i * 3 - 2] = i;
		a[i * 3 - 1] = i + n / 3;
		a[i * 3] = i + n / 3 * 2;
	}
}
void __() {
	int n;
	cin >> n;
	// cout << n << '\n';
	if (n % 3 == 0) {
		make(n);
		for (int i = 1; i <= n; i++) cout << a[i] << " ";
	} else if (n % 3 == 1) {
		make(n - 1);
		for (int i = 1; i <= n - 1; i++) cout << a[i] << " ";
		cout << n << " ";
	} else {
		make(n - 2);
		for (int i = 1; i <= n - 2; i++) cout << a[i] << " ";
		cout << n - 1 << " " << n << " ";
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