#include <bits/stdc++.h>
using namespace std;
// #define DEBUG
const int N = 110;
bool a[N][N];
int ans[N], fans[N];
int n;
#define ull unsigned long long

vector<int> inArr = {1, 3, 5, 7, 9, 1, 3, 5, 7, 9};
vector<int> deArr = {1, 3, 4, 6, 1, 6};
int deCnt = 0;

int debug(int pos) {
	int jud = (deArr[pos - 1]) % n + 1;
	deArr[pos - 1] = jud;
	deCnt++;
	for (int i = 0; i <= n - 1; i++) {
		cout << deArr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i <= n - 1; i++) {
		if (deArr[i] == jud && i != pos - 1) {
			return 1;
		}
	}
	return 0;
}

void init(int t) {}

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
	return st.size() != len;
}

void __() {
#ifdef DEBUG
	cin >> n;
#else
	deCnt = 0;
	n = deArr.size();
#endif
	for (int i = 1; i <= n; i++) {
		fans[i] = ans[i] = 0;
		for (int j = 0; j <= n; j++) a[i][j] = 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << "? " << 1 << endl;
#ifdef DEBUG
		cin >> a[1][i % n];
#else
		a[1][i % n] = debug(1);
#endif
	}
	if (check()) {
		char c;
		cout << "? " << 1 << endl;
#ifdef DEBUG
		cin >> c;
#else
		c = debug(1);
#endif
		int b[N];
		for (int i = 0; i < n; i++) b[i] = a[1][(i + 1) % n];
		for (int i = 0; i < n; i++) a[1][i] = b[i];
	}
	a[1][0] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << "? " << i << endl;
#ifdef DEBUG
			cin >> a[i][j % n];
#else
			a[i][j % n] = debug(i);
#endif
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
			char c;
			cout << "? " << i << endl;
#ifdef DEBUG
			cin >> c;
#else
			c = debug(i);
#endif
		}
	}
#ifdef DEBUG
	cout << "!" << endl;
#else
	cout << "! " << deCnt << " " << n * (n + 1) * 3 / 2 << endl;
	if (deCnt > n * (n + 1) * 3 / 2) {
		assert(0);
	}
#endif
}

int main() {
	int t = 6 * 6 * 6 * 6 * 6 * 6;
	cin >> t;
	while (t--) {
#ifndef DEBUG
		init(t);
#endif
		__();
	}
	return 0;
}