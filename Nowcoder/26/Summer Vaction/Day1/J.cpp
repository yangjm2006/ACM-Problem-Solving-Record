#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll hashing(ll* a) {
	ll res = 0;
	for (int i = 1; i <= 5; i++) res = res * 20 + a[i] % 13;
	return res;
}
ll isflush(ll* a) {
	if (a[1] / 13 == a[2] / 13 && a[1] / 13 == a[3] / 13 && a[1] / 13 == a[4] / 13 &&
		a[1] / 13 == a[5] / 13) {
		return hashing(a);
	}
	return 0;
}
ll isstraight(ll* a) {
	if (a[1] % 13 >= 4 && a[2] % 13 == a[1] % 13 - 1 && a[3] % 13 == a[1] % 13 - 2 &&
		a[4] % 13 == a[1] % 13 - 3 && a[5] % 13 == a[1] % 13 - 4) {
		return a[1] % 13;
	}
	if (a[1] % 13 == 12 && a[2] % 13 == 3 && a[3] % 13 == 2 && a[4] % 13 == 1 && a[5] % 13 == 0)
		return a[2] % 13;
	return 0;
}
int num[20];
int make(ll* a) {
	for (int i = 0; i <= 13; i++) num[i] = 0;
	for (int i = 1; i <= 5; i++) num[a[i] % 13]++;
	int f3 = 0, f2 = 0;
	for (int i = 0; i < 13; i++) {
		if (num[i] == 4) return 4;
		if (num[i] == 3) f3++;
		if (num[i] == 2) f2++;
	}
	if (f3 == 1) {
		if (f2 == 1) return 32;
		return 3;
	}
	if (f2 == 2) return 22;
	if (f2 == 1) return 2;
	return 1;
}
pair<ll, ll> vec[10];
ll makehaxi(ll* a) {
	int cnt = 0;
	for (int i = 0; i <= 13; i++) num[i] = 0;
	for (int i = 1; i <= 5; i++) num[a[i] % 13]++;
	for (int i = 0; i < 13; i++) {
		if (num[i]) vec[cnt++] = make_pair(num[i], i);
	}
	sort(vec, vec + cnt, greater<pair<ll, ll>>());
	ll res = 0;
	for (int i = 0; i < cnt; i++) {
		res = res * 20 + vec[i].second;
	}
	return res;
}
const ll IE = 1e12;
ll cal(ll* a) {
	ll straight = isstraight(a), flush = isflush(a);
	if (straight != 0 && flush != 0) {
		return IE * 9 + straight;
	}
	int mk = make(a);
	ll hx = makehaxi(a);
	if (mk == 4) {
		return IE * 8 + hx;
	}
	if (mk == 32) {
		return IE * 7 + hx;
	}
	if (flush != 0) {
		return IE * 6 + flush;
	}
	if (straight != 0) {
		return IE * 5 + straight;
	}
	if (mk == 3) {
		return IE * 4 + hx;
	}
	if (mk == 22) {
		return IE * 3 + hx;
	}
	if (mk == 2) {
		return IE * 2 + hx;
	}
	return IE * 1 + hashing(a);
}
int a[10], b[10];
ll v1[10], v2[10];
bool cmp(ll x, ll y) {
	if (x % 13 == y % 13) return x > y;
	return x % 13 > y % 13;
}
int check() {
	for (int i = 1; i <= 5; i++) {
		v1[i] = a[i];
		v2[i] = b[i];
	}
	sort(v1 + 1, v1 + 6, cmp);
	sort(v2 + 1, v2 + 6, cmp);
	ll val1 = cal(v1), val2 = cal(v2);
	if (val1 > val2) {
		return 0;
	}
	if (val1 < val2) return 2;
	return 1;
}
int mapping1(char c) {
	if (c == 'A') return 12;
	if (c == 'K') return 11;
	if (c == 'Q') return 10;
	if (c == 'J') return 9;
	if (c == 'T') return 8;
	return c - '2';
}
int mapping2(char c) {
	if (c == 'C') return 0;
	if (c == 'D') return 1;
	if (c == 'H') return 2;
	return 3;
}
bool vis[60];
void __() {
	for (int i = 0; i < 55; i++) vis[i] = 0;
	for (int i = 1; i <= 4; i++) {
		char c1, c2;
		cin >> c1 >> c2;
		int x = mapping1(c1), y = mapping2(c2);
		b[i] = x + y * 13;
		vis[b[i]] = 1;
	}
	for (int i = 1; i <= 4; i++) {
		char c1, c2;
		cin >> c1 >> c2;
		int x = mapping1(c1), y = mapping2(c2);
		a[i] = x + y * 13;
		vis[a[i]] = 1;
	}
	int f1 = 2;
	for (int i = 0; i < 52; i++)
		if (vis[i] == 0) {
			vis[i] = 1;
			a[5] = i;
			int f2 = 0;
			for (int j = 0; j < 52; j++)
				if (vis[j] == 0) {
					b[5] = j;
					f2 = max(f2, check());
					if (f2 == 2) break;
				}
			vis[i] = 0;
			f1 = min(f1, f2);
			if (f1 == 0) break;
		}
	if (f1 == 0) {
		cout << "GeiWoCaPiXie\n";
	} else if (f1 == 1) {
		cout << "PaiMeiYouWenTi\n";
	} else {
		cout << "WoYaoYanPai\n";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}