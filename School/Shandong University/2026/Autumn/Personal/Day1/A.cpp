#include <bits/stdc++.h>
using namespace std;
int x[20], y[20];
map<int, int> mpx, mpy;
bool vis[100][100];
void __() {
	cin >> x[1] >> y[1] >> x[2] >> y[2];
	cin >> x[3] >> y[3] >> x[4] >> y[4];
	cin >> x[5] >> y[5] >> x[6] >> y[6];
	for (int i = 1; i <= 6; i++) {
		x[i] *= 2;
		y[i] *= 2;
	}
	set<int> st;
	int cnt = 0;
	for (int i = 1; i <= 6; i++) {
		st.insert(x[i]);
		st.insert(x[i] + 1);
		st.insert(x[i] - 1);
	}
	for (auto x : st) {
		mpx[x] = ++cnt;
	}
	st.clear();
	cnt = 0;
	for (int i = 1; i <= 6; i++) {
		st.insert(y[i]);
		st.insert(y[i] + 1);
		st.insert(y[i] - 1);
	}
	for (auto x : st) {
		mpy[x] = ++cnt;
	}
	for (int i = mpx[x[3]]; i <= mpx[x[4]]; i++) {
		for (int j = mpy[y[3]]; j <= mpy[y[4]]; j++) {
			vis[i][j] = 1;
		}
	}
	for (int i = mpx[x[5]]; i <= mpx[x[6]]; i++) {
		for (int j = mpy[y[5]]; j <= mpy[y[6]]; j++) {
			vis[i][j] = 1;
		}
	}
	for (int i = mpx[x[1]]; i <= mpx[x[2]]; i++) {
		for (int j = mpy[y[1]]; j <= mpy[y[2]]; j++) {
			if (!vis[i][j]) {
				cout << "YES";
				return;
			}
			// cout << vis[i][j] << " ";
		}
		// cout << '\n';
	}
	cout << "NO";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}