#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
multiset<int> f[N];
multiset<int>::iterator it;
int n, w[N], ans;
int h[N], to[N], nxt[N], t;
void add(int u, int v) { to[++t] = v, nxt[t] = h[u], h[u] = t; }
void merge(int u, int v)
{
	if (f[u].size() < f[v].size())
		swap(f[u], f[v]);
	for (it = f[v].begin(); it != f[v].end(); ++it)
		f[u].insert(*it);
}
void dfs(int u)
{
	for (int i = h[u]; i; i = nxt[i])
		dfs(to[i]), merge(u, to[i]);
	f[u].insert(w[u]);
	it = f[u].lower_bound(w[u]);
	if (it != f[u].begin())
		f[u].erase(--it);
	cout << u << "---------------\n";
	for (auto x : f[u])
		cout << x << " ";
	cout << "\n---------------\n";
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &w[i]);
	for (int i = 2; i <= n; ++i)
	{
		int f;
		scanf("%d", &f);
		add(f, i);
	}
	dfs(1);
	printf("%d", f[1].size());
}
