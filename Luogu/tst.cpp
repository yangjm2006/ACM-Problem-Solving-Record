#include <algorithm>
#include <cstdio>
#include <initializer_list>
constexpr int N = 35;
int x, y, Ch, a[N][N], p, q, d, i, t;
template <typename T>
inline void r(T& x) {
	while ((Ch = getchar()) < 48);
	x = Ch & 15;
	while ((Ch = getchar()) > 47) x = (x << 1) + (x << 3) + (Ch & 15);
}
template <typename... Ar>
inline void r(Ar&&... x) {
	std::initializer_list<int>{(r(x), 0)...};
}
template <typename T>
inline void w(T x) {
	static char stk[64], *top = stk;
	do {
		*++top = x % 10;
		x /= 10;
	} while (x);
	do putchar(*top-- | 48);
	while (top != stk);
}
inline void w(char x) { putchar(x); }
template <typename... Ar>
inline void w(Ar&&... x) {
	std::initializer_list<int>{(w(x), 0)...};
}
inline void f(const int p, const int q) {
	a[p][q] = 1;
	w(p, ' ', q, '\n');
#ifdef LYH_CPP
	for (int i = 30; i; i--) {
		for (int j = 1; j <= 30; j++) putchar(j == x && i == y ? 'X' : a[j][i] ? '#' : '.');
		putchar('\n');
	}
#endif
	fflush(stdout);
	r(x, y);
	if (!x) __builtin_exit(0);
}
int main() {
	r(x, y);
	f(29, 30);
	f(30, 29);
	f(30, 30);
	while (1) {
		p = x;
		q = y;
		d = 1 << 29;
		for (i = 1; i <= 30; ++i) {
			t = __builtin_abs(i - x) + 30 - y;
			if (!a[i][30] && t < d && (i % 3 != 1 || t < 3)) {
				d = t;
				p = i;
				q = 30;
			}
			t = __builtin_abs(i - y) + 30 - x;
			if (!a[30][i] && t < d && (i % 3 != 1 || t < 3)) {
				d = t;
				q = i;
				p = 30;
			}
		}
		f(p, q);
	}
}