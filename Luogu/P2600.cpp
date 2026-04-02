#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const double eps = 1e-9;
const double INF = 1e20;
int sgn(double x)
{
    if (abs(x) <= eps)
        return 0;
    return x > 0 ? 1 : -1;
}
struct Point
{
    double x, y;
} p[N];
struct Line
{
    double k, b;
} l[N];
Line two_point_line(Point a, Point b)
{
    double k = (a.y - b.y) / (a.x - b.x);
    return (Line){k, a.y - k * a.x};
}
bool two_line_parallel(Line a, Line b)
{
    return a.k == b.k;
}
Point two_line_point(Line a, Line b)
{
    double x = (b.b - a.b) / (a.k - b.k);
    return (Point){x, a.k * x + a.b};
}
int n;
double ans = INF;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x;
    for (int i = 1; i <= n; i++)
        cin >> p[i].y;
    for (int i = 1; i <= n - 1; i++)
    {
        l[i] = two_point_line(p[i], p[i + 1]);
    }
    // for (int i = 1; i <= n - 1; i++)
    //     cout << l[i].k << " " << l[i].b << "++\n";
    for (int i = 1; i <= n; i++)
    {
        double maxx = -INF;
        for (int j = 1; j <= n - 1; j++)
        {
            maxx = max(maxx, l[j].k * p[i].x + l[j].b);
        }
        ans = min(ans, maxx - p[i].y);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n - 1; j++)
        {
            if (two_line_parallel(l[i], l[j]))
                continue;
            Point q = two_line_point(l[i], l[j]);
            if (sgn(p[1].x - q.x) == 1 || sgn(q.x - p[n].x) == 1)
                continue;
            for (int k = 1; k <= n - 1; k++)
            {
                q.y = max(q.y, l[k].k * q.x + l[k].b);
            }
            int l = 1, r = n;
            while (l < r)
            {
                int mid = (l + r >> 1) + 1;
                if (sgn(q.x - p[mid].x) == 1)
                    l = mid;
                else
                    r = mid - 1;
            }
            Line L = two_point_line(p[l], p[l + 1]);
            ans = min(ans, q.y - (L.k * q.x + L.b));
        }
    }
    cout << fixed << setprecision(3) << ans;
    return 0;
}