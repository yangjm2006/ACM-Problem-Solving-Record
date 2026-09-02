#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
struct node {
	int time, tpe;
	string team, prob;
	bool operator<(const node& x) const { return time < x.time; }
} p[N];
struct Node {
	string team, prob;
	bool operator<(const Node& x) const {
		if (team == x.team) return prob < x.prob;
		return team < x.team;
	}
};
map<string, int> pena;
map<string, int> ac;
map<string, int> ac_max;
map<string, int> pena_max;
map<Node, bool> ac_ed;
map<Node, int> try_ed;
set<string> tem;
int ac_maxx, pen_min;
int T, n, tot;
string ans[N];
int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		pena.clear();
		ac.clear();
		ac_max.clear();
		pena_max.clear();
		ac_ed.clear();
		try_ed.clear();
		tem.clear();
		ac_maxx = pen_min = tot = 0;
		for (int i = 1; i <= n; i++) {
			cin >> p[i].team >> p[i].prob >> p[i].time;
			tem.insert(p[i].team);
			string S;
			cin >> S;
			if (S == "Accepted")
				p[i].tpe = 1;
			else if (S == "Rejected")
				p[i].tpe = 2;
			else
				p[i].tpe = 3;
		}
		sort(p + 1, p + 1 + n);
		for (int i = 1; i <= n; i++) {
			Node tp = (Node){p[i].team, p[i].prob};
			if (p[i].tpe == 1) {
				if (!ac_ed[tp]) {
					ac_ed[tp] = 1;
					ac[p[i].team]++;
					ac_max[p[i].team]++;
					pena[p[i].team] += try_ed[tp] * 20 + p[i].time;
					pena_max[p[i].team] += try_ed[tp] * 20 + p[i].time;
					if (ac_maxx < ac[p[i].team]) {
						ac_maxx = ac[p[i].team];
						pen_min = pena[p[i].team];
					} else if (ac_maxx == ac[p[i].team]) {
						pen_min = min(pen_min, pena[p[i].team]);
					}
				}
			} else if (p[i].tpe == 2) {
				try_ed[tp]++;
			} else {
				if (!ac_ed[tp]) {
					ac_ed[tp] = 1;
					ac_max[p[i].team]++;
					pena_max[p[i].team] += try_ed[tp] * 20 + p[i].time;
				}
			}
		}
		for (set<string>::iterator it = tem.begin(); it != tem.end(); it++) {
			if (ac_max[*it] > ac_maxx || (ac_max[*it] == ac_maxx && pen_min >= pena_max[*it]))
				ans[++tot] = *it;
		}
		sort(ans + 1, ans + 1 + tot);
		for (int i = 1; i <= tot; i++) cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}