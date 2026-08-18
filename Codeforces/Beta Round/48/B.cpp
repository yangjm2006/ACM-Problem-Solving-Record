#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
int stc[N], top;
vector<int> vec;
void work(string s) {
	int lst;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '<')
			lst = i;
		else if (s[i] == '>') {
			string sub = s.substr(lst + 1, i - (lst + 1));
			if (sub == "table")
				stc[++top] = 0;
			else if (sub == "/table") {
				vec.push_back(stc[top]);
				top--;
			} else if (sub == "/td") {
				stc[top]++;
			}
		}
	}
}
void __() {
	string sum, s;
	while (cin >> s) {
		sum += s;
	}
	work(sum);
	sort(vec.begin(), vec.end());
	for (auto x : vec) {
		cout << x << " ";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	__();
	return 0;
}