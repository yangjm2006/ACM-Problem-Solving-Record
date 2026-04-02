#include <bits/stdc++.h>
#define double long double
using namespace std;
const int N = 2e6 + 100;
const double eps = 1e-12;
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
struct Circle
{
    Point o;
    double r;
} q;
Point middle_point(Point a, Point b)
{
    return (Point){(a.x + b.x) / 2, (a.y + b.y) / 2};
}
double distance(Point a, Point b)
{
    return hypot(a.x - b.x, a.y - b.y);
}
bool in_circle(Point a, Circle b)
{
    return sgn(distance(a, b.o) - b.r) != 1;
}
Point circumcenter(Point a, Point b, Point c)
{
    double A1 = b.x - a.x, A2 = c.x - a.x, B1 = b.y - a.y, B2 = c.y - a.y, C1 = (b.x * b.x - a.x * a.x + b.y * b.y - a.y * a.y) / 2, C2 = (c.x * c.x - a.x * a.x + c.y * c.y - a.y * a.y) / 2;
    return (Point){-(B1 * C2 - B2 * C1) / (A1 * B2 - A2 * B1), (A1 * C2 - A2 * C1) / (A1 * B2 - A2 * B1)};
}
Circle three_point_circle(Point a, Point b, Point c)
{
    Point o = circumcenter(a, b, c);
    return (Circle){o, distance(o, a)};
}
int n;
void min_enclosing_circle()
{
    q.o = p[1];
    q.r = 0;
    for (int i = 2; i <= n; i++)
    {
        if (in_circle(p[i], q))
            continue;
        q.o = p[i];
        q.r = 0;
        for (int j = 1; j <= i - 1; j++)
        {
            if (in_circle(p[j], q))
                continue;
            q.o = middle_point(p[i], p[j]);
            q.r = distance(p[i], p[j]) / 2;
            for (int k = 1; k <= j - 1; k++)
            {
                if (in_circle(p[k], q))
                    continue;
                q = three_point_circle(p[i], p[j], p[k]);
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;
    random_shuffle(p + 1, p + 1 + n);
    min_enclosing_circle();
    cout << fixed << setprecision(10) << q.r << '\n'
         << q.o.x << " " << q.o.y;
    return 0;
}