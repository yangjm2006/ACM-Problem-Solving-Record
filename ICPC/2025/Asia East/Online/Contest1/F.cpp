#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
bool vis[1010][1010];
int n = 30, X, Y;
bool work1() {
	int x = -1, y = -1, minn = INF;
	for (int i = 1; i <= n; i++) {
		int dis = abs(i - X) + abs(n - Y);
		if (vis[i][n] == 0 && (i % 3 != 0 || dis <= 2)) {
			if (dis < minn) {
				minn = dis;
				x = i;
				y = n;
			}
		}
		dis = abs(n - X) + abs(i - Y);
		if (vis[n][i] == 0 && (i % 3 != 0 || dis <= 2)) {
			if (dis < minn) {
				minn = dis;
				x = n;
				y = i;
			}
		}
	}
	if (x == -1) return 0;
	cout << x << " " << y << endl;
	vis[x][y] = 1;
	return 1;
}
bool work2() {
	int x = -1, y = -1, minn = INF;
	for (int i = 1; i <= n; i++) {
		int dis = abs(i - X) + abs(n - Y);
		if (vis[i][n] == 0) {
			if (dis < minn) {
				minn = dis;
				x = i;
				y = n;
			}
		}
		dis = abs(n - X) + abs(i - Y);
		if (vis[n][i] == 0) {
			if (dis < minn) {
				minn = dis;
				x = n;
				y = i;
			}
		}
	}
	if (x == -1) return 0;
	cout << x << " " << y << endl;
	vis[x][y] = 1;
	return 1;
}
bool read() {
	cin >> X >> Y;
	return X == 0 && Y == 0;
}
int main() {
	cin >> X >> Y;
	cout << n << " " << n << endl;
	if (read()) return 0;
	cout << n - 1 << " " << n << endl;
	if (read()) return 0;
	cout << n << " " << n - 1 << endl;
	if (read()) return 0;
	cout << n - 2 << " " << n << endl;
	if (read()) return 0;
	cout << n << " " << n - 2 << endl;
	if (read()) return 0;
	while (work1()) {
		if (read()) return 0;
	}
	while (work2()) {
		if (read()) return 0;
	}
	int x1 = 1, x2 = n - 1, y1 = 1, y2 = n - 1;
	for (;;) {
		if (x2 - x1 > y2 - y1) {
			int xmid = (x1 + x2) / 2;
			for (int i = y1; i <= y2; i++) {
				if (vis[xmid][i] == 0) {
					cout << xmid << " " << i << endl;
					vis[xmid][i] = 1;
					if (read()) return 0;
				}
			}
			if (X > xmid)
				x1 = xmid + 1;
			else
				x2 = xmid - 1;
		} else {
			int ymid = (y1 + y2) / 2;
			for (int i = x1; i <= x2; i++) {
				if (vis[i][ymid] == 0) {
					cout << i << " " << ymid << endl;
					vis[i][ymid] = 1;
					if (read()) return 0;
				}
			}
			if (Y > ymid)
				y1 = ymid + 1;
			else
				y2 = ymid - 1;
		}
	}
	return 0;
}