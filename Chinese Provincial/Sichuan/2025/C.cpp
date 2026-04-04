#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
double dp[N];
vector<int> d[N];
void work()
{
    for (int i = 1; i <= 100000; i++)
    {
        double sum = 0;
        for (auto j : d[i])
        {
            sum += dp[j - 1];
        }
        dp[i] = min(dp[i - 1], sum / d[i].size()) + 1;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= 100000; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                d[i].push_back(j);
                if (j * j != i)
                {
                    d[i].push_back(i / j);
                }
            }
        }
        for (int j = 2 * i; j <= n; j += i)
        {
            d[i].push_back(j);
        }
    }
    for (int i = 1; i <= 100000; i++)
        dp[i] = i;
    for (int i = 1; i <= 200; i++)
    {
        work();
    }
    cout << fixed << setprecision(7);
    while (q--)
    {
        int x;
        cin >> x;
        cout << dp[x] << '\n';
    }
    return 0;
}