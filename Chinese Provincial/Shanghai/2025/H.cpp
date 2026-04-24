#include <bits/stdc++.h>
using namespace std;
int main() {
	int x;
	cin >> x;
	double hhh = (double)x / 100;
	double ans = round((50 + (50 * hhh)) * 1000);
	cout << "Vivo " << fixed << setprecision(3) << ans / 1000;
	return 0;
}