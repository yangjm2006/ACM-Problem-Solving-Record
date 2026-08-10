#include <bits/stdc++.h>
using namespace std;
int match(string a, string b) {
	int res = 0;
	for (int i = 0; i < 4; i++) res += (a[i] == b[i]);
	return res;
}
vector<string> queries[10];
struct Hash {
	size_t operator()(const vector<string>& v) const {
		size_t h = 0;
		for (auto& s : v) {
			for (char c : s) {
				h = h * 131 + c;
			}
		}
		return h;
	}
};
unordered_map<vector<string>, string, Hash> solution;
// map<vector<string>, string> solution;
int cnt;
bool dfs(const vector<string>& state, int depth, int opt) {
	if (state.size() == 1) return 1;
	if (depth == 0) return 0;
	cnt++;
	for (const string& query : queries[opt]) {
		vector<string> nxt[5];
		for (const string& answer : state) {
			int ret = match(query, answer);
			nxt[ret].push_back(answer);
		}
		bool ok = 1;
		for (int ret = 0; ret <= 4; ret++) {
			if (!nxt[ret].empty()) {
				if (!dfs(nxt[ret], depth - 1, opt)) {
					ok = 0;
					break;
				}
			}
		}
		if (ok) {
			if (!solution.count(state)) solution[state] = query;
			return 1;
		}
	}
	return 0;
}
vector<string> start_state[10];
void init() {
	string s = "0000";
	for (s[0] = '1'; s[0] <= '4'; s[0]++) {
		for (s[1] = '1'; s[1] <= '4'; s[1]++) {
			for (s[2] = '1'; s[2] <= '4'; s[2]++) {
				for (s[3] = '1'; s[3] <= '4'; s[3]++) {
					if (s[0] == s[1] && s[0] == s[2] && s[0] == s[3]) continue;
					queries[4].push_back(s);
				}
			}
		}
	}
	for (s[0] = '1'; s[0] <= '3'; s[0]++) {
		for (s[1] = '1'; s[1] <= '3'; s[1]++) {
			for (s[2] = '1'; s[2] <= '3'; s[2]++) {
				for (s[3] = '1'; s[3] <= '3'; s[3]++) {
					if (s[0] == s[1] && s[0] == s[2] && s[0] == s[3]) continue;
					queries[3].push_back(s);
				}
			}
		}
	}
	for (s[0] = '1'; s[0] <= '2'; s[0]++) {
		for (s[1] = '1'; s[1] <= '2'; s[1]++) {
			for (s[2] = '1'; s[2] <= '2'; s[2]++) {
				for (s[3] = '1'; s[3] <= '2'; s[3]++) {
					if (s[0] == s[1] && s[0] == s[2] && s[0] == s[3]) continue;
					queries[2].push_back(s);
				}
			}
		}
	}
	for (s[0] = '1'; s[0] <= '1'; s[0]++) {
		for (s[1] = '1'; s[1] <= '1'; s[1]++) {
			for (s[2] = '1'; s[2] <= '1'; s[2]++) {
				for (s[3] = '1'; s[3] <= '1'; s[3]++) {
					if (s[0] == s[1] && s[0] == s[2] && s[0] == s[3]) continue;
					queries[1].push_back(s);
				}
			}
		}
	}
	set<string> st[10];
	s = "1234";
	do {
		start_state[1].push_back(s);
	} while (next_permutation(s.begin(), s.end()));
	s = "1233";
	do {
		start_state[2].push_back(s);
	} while (next_permutation(s.begin(), s.end()));
	s = "1222";
	do {
		start_state[3].push_back(s);
	} while (next_permutation(s.begin(), s.end()));
	s = "1122";
	do {
		start_state[4].push_back(s);
	} while (next_permutation(s.begin(), s.end()));
	s = "1111";
	do {
		start_state[5].push_back(s);
	} while (next_permutation(s.begin(), s.end()));
	dfs(start_state[1], 3, 4);
	dfs(start_state[2], 3, 3);
	dfs(start_state[3], 3, 2);
	dfs(start_state[4], 3, 2);
	dfs(start_state[5], 3, 1);
}
int a[20];
char nota[300];
void output(string s) {
	for (int i = 0; i < 4; i++) {
		cout << nota[s[i]];
	}
	cout << '\n';
}
void dfs2(const vector<string>& state) {
	if (state.size() == 1) {
		cout << "! ";
		output(state[0]);
		return;
	}
	string s = solution[state];
	cout << "? ";
	output(s);
	int ret;
	cin >> ret;
	vector<string> nxt;
	for (string answer : state) {
		if (ret == match(answer, s)) nxt.push_back(answer);
	}
	dfs2(nxt);
}
void __() {
	int sum = 0;
	vector<pair<int, char>> vec;
	for (int i = 1; i <= 9; i++) {
		cout << "? " << i << i << i << i << '\n';
		cin >> a[i];
		sum += a[i];
		if (a[i]) {
			vec.push_back(make_pair(a[i], i + '0'));
		}
	}
	a[0] = 4 - sum;
	if (a[0]) {
		vec.push_back(make_pair(a[0], '0'));
	}
	sort(vec.begin(), vec.end());
	string S;
	for (int i = 0; i < vec.size(); i++) {
		nota[i + '1'] = vec[i].second;
		S += char(vec[i].first + '0');
	}
	vector<string> this_state;
	if (S == "1111") {
		this_state = start_state[1];
	} else if (S == "112") {
		this_state = start_state[2];
	} else if (S == "13") {
		this_state = start_state[3];
	} else if (S == "22") {
		this_state = start_state[4];
	} else {
		this_state = start_state[5];
	}
	dfs2(this_state);
}
int main() {
	init();
	// cout << solution.size() << "!!!!!!!!!!\n";
	// cout << cnt << "!!!!!!!!!\n";
	int T;
	cin >> T;
	while (T--) __();
	return 0;
}