#include <cmath>
#include <cstdio>
#include <cstdlib>

const int MAXN = 2500;

/*------------------------------Computational geometry------------------------------*/

const double eps = 1e-8;

struct vect {
	double x, y, z;
	vect() {}
	vect(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {}
	vect operator-(vect v) { return vect(x - v.x, y - v.y, z - v.z); }
	vect operator/(vect v) { return vect(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }
	double operator*(vect v) { return x * v.x + y * v.y + z * v.z; }
	double m() { return sqrt(x * x + y * y + z * z); }
	double rd() { return (rand() % 2) ? eps : -eps; }
	void shake() { x += rd(), y += rd(), z += rd(); }
} pts[MAXN];

struct plane {
	int v[3]; /*节省空间*/
	plane() {}
	plane(int uu, int vv, int ww) { v[0] = uu, v[1] = vv, v[2] = ww; }
	vect normal() { return (pts[v[1]] - pts[v[0]]) / (pts[v[2]] - pts[v[0]]); }
};

inline bool gtr(double a, double b) { return (a - b > eps); }

inline bool eq(double a, double b) { return (a - b > -eps && a - b < eps); }

inline double dist(vect x, vect y) { return (x - y).m(); }

inline double dist(vect v, vect f1, vect f2) { return ((f2 - f1) / (v - f1)).m() / (f2 - f1).m(); }

inline bool isabove(vect v, plane p) { return gtr((v - pts[p.v[0]]) * p.normal(), 0); }

/*------------------------------Convex Hulls------------------------------*/

int vise[MAXN][MAXN];
plane res[MAXN << 1], del[MAXN << 1];

inline int getConvexHulls(int totp, plane facets[]) {
	int s[3];
	s[0] = 0, s[1] = 1, s[2] = 2;
	int totf = 0;
	facets[totf++] = plane(s[0], s[1], s[2]);
	facets[totf++] = plane(s[0], s[2], s[1]);
	for (int i = 0; i < totp; ++i) {
		/*重复的点不会产生贡献*/
		int totr = 0, totd = 0;
		for (int j = 0; j < totf; ++j) {
			if (!isabove(pts[i], facets[j]))
				res[totr++] = facets[j]; /*这里保存不需要删除的面*/
			else {
				del[totd++] = facets[j];
				/*由于每个点只会循环一次，所以这个 i+1 就相当于一个时间戳*/
				for (int k = 0; k < 3; ++k) vise[facets[j].v[k]][facets[j].v[(k + 1) % 3]] = i + 1;
			}
		}
		for (int j = 0; j < totd; ++j) {
			plane f = del[j];
			for (int k = 0; k < 3; ++k)
				if (vise[f.v[k]][f.v[(k + 1) % 3]] == i + 1 &&
					vise[f.v[(k + 1) % 3]][f.v[k]] != i + 1)
					res[totr++] = plane(f.v[k], f.v[(k + 1) % 3], i);
		}
		totf = totr;
		for (int j = 0; j < totr; ++j) facets[j] = res[j];
	}
	return totf;
}

/*------------------------------Main------------------------------*/

plane facets[MAXN << 1];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lf%lf%lf", &pts[i].x, &pts[i].y, &pts[i].z), pts[i].shake(); /*扰动点*/
	int h = getConvexHulls(n, facets);
	double area = 0;
	for (int i = 0; i < h; ++i) area += facets[i].normal().m() / 2;
	printf("%.3lf", area);
}
