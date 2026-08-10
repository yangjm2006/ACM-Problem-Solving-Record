#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int a[N];
void __() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	set<int> st;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		v.push_back(a[i]);
		v.push_back(a[(i + 1) % n]);
		v.push_back(a[(i + 2) % n]);
		sort(v.begin(), v.end());
		st.insert(v[1]);
	}
	cout << st.size() << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}