#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

bool cmp(int a, int b) { return a < b; }

int n;
vector<int> a;
set<int> hasx;
// map<int, int> nex;
// map<int, int> nex2;
int rec(int x) {
	// cout << x << ' ';
	int ind = lower_bound(a.begin(), a.end(), x, less<int>()) - a.begin();
	int cnt = n - ind;
	// cnt = 0;
	if (cnt == 0) {
		return 0;
	} else if (cnt % 2 == 1) {
		if (hasx.find(x) != hasx.end()) {
			return 1;
		} else {
			int tar;
			if (hasx.find(x) != hasx.end()) {
				tar = x + 2;
			} else {
				tar = a[ind];
				if ((tar - x) % 2 != 0) {
					tar++;
				}
			}
			return rec(tar);
		}
	} else {
		int tar;
		if (hasx.find(x) != hasx.end()) {
			tar = x + 1;
		} else {
			tar = a[ind];
		}
		return rec(tar);
	}
}

void __() {
	hasx.clear();
	a.clear();
	// nex.clear();
	// nex2.clear();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
		hasx.insert(x);
	}
	sort(a.begin(), a.end(), cmp);
	// int las = -1;
	// for (int x : a) {
	// 	if (x == las) continue;
	// 	nex[las] = x;
	// 	las = x;
	// }
	// nex[las] = las + 1;
	// las = -1;
	// for (int x : a) {
	// 	if (x % 2 == 1) continue;
	// 	if (x == las) continue;
	// 	nex2[las] = x;
	// 	las = x;
	// }
	// nex2[las] = las + 2;
	// las = -1;
	// for (int x : a) {
	// 	if (x % 2 == 0) continue;
	// 	if (x == las) continue;
	// 	nex2[las] = x;
	// 	las = x;
	// }
	// nex2[las] = las + 2;

	int ans = rec(1);
	if (ans == 1) {
		cout << "Insight" << endl;
	} else {
		cout << "Maya" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}