#include <bits/stdc++.h>
using namespace std;
const int N = 110;
bool a[N][N];
int ans[N], fans[N];
#define ull unsigned long long
int n;
bool check() {
	vector<int> v;
	v.push_back(0);
	for (int i = 1; i < n; i++) {
		if (a[1][i]) v.push_back(i);
	}
	v.push_back(n);
	vector<int> vec;
	for (int i = 1; i < v.size(); i++) {
		vec.push_back(v[i] - v[i - 1]);
	}
	set<pair<ull, ull>> st;
	int len = vec.size();
	for (int i = 0; i < len; i++) {
		ull p = 1e9 + 7;
		ull h1 = 0, h2 = 0;
		for (int j = 0; j < len; j++) {
			h1 = h1 * 233 + vec[(i + j) % len];
			h2 = h2 * 131 + vec[(i + j) % len];
			h2 %= p;
		}
		st.insert(make_pair(h1, h2));
	}
	return st.size() <= len / 2;
}
void __() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		fans[i] = ans[i] = 0;
		for (int j = 0; j <= n; j++) a[i][j] = 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << "? " << 1 << endl;
		cin >> a[1][i % n];
	}
	while (check()) {
		cout << "? " << 1 << endl;
		char c;
		cin >> c;
		int b[N];
		for (int i = 0; i < n; i++) b[i] = a[1][(i + 1) % n];
		for (int i = 0; i < n; i++) a[1][i] = b[i];
	}
	a[1][0] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << "? " << i << endl;
			cin >> a[i][j % n];
		}
		a[i][0] = 1;
		for (int k = 0; k < n; k++) {
			bool f = 1;
			for (int j = 0; j < n; j++) {
				if (a[1][j] != a[i][(j + k) % n]) f = 0;
			}
			if (f) fans[i] = ans[i] = k;
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j < n; j++) cout << a[i][j] << " ";
	// 	cout << '\n';
	// }
	// for (int i = 1; i <= n; i++) cout << ans[i] << "@@\n";
	int minn = 0;
	for (int i = 1; i <= n; i++) minn += ans[i];
	for (int k = 1; k < n; k++) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += (ans[i] + k) % n;
		}
		if (sum < minn) {
			minn = sum;
			for (int i = 1; i <= n; i++) fans[i] = (ans[i] + k) % n;
		}
	}
	// for (int i = 1; i <= n; i++) cout << ans[i] << "!!\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= fans[i]; j++) {
			cout << "? " << i << endl;
			char c;
			cin >> c;
		}
	}
	cout << "!" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		__();
	}
	return 0;
}