#pragma once
#include <ctime>
#include <iomanip>
#include <ostream>
class Date {
private:
	int _yyyymmdd;

	static bool is_leap(int y) {
		return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
	}

	static int day_of_month(int y, int m) {
		static constexpr int days[13] = {0,	 31, 28, 31, 30, 31, 30,
										 31, 31, 30, 31, 30, 31};
		if (is_leap(y) && m == 2) return 29;
		return days[m];
	}

public:
	Date(void) {
		time_t now = time(nullptr);
		tm* t = localtime(&now);
		int _y = t->tm_year + 1900, _m = t->tm_mon + 1, _d = t->tm_mday;
		_yyyymmdd = _y * 10000 + _m * 100 + _d;
	}
	Date(int y, int m, int d) : Date() {
		if (check(y, m, d) == 0) _yyyymmdd = y * 10000 + m * 100 + d;
	}

	int year() const { return _yyyymmdd / 10000; }
	int month() const { return _yyyymmdd % 10000 / 100; }
	int day() const { return _yyyymmdd % 100; }

	bool is_leap_year() const { return is_leap(year()); }

	void print(std::ostream& os) const {
		os << std::setw(4) << std::setfill('0') << year() << "-" << std::setw(2)
		   << std::setfill('0') << month() << "-" << std::setw(2)
		   << std::setfill('0') << day();
	}
	static int check(int y, int m, int d) {
		if (y < 1800 || y > 9999) return -1;
		if (m < 1 || m > 12) return -2;
		if (d < 1 || d > day_of_month(y, m)) return -3;
		return 0;
	}

	int set(int y, int m, int d) {
		int op = check(y, m, d);
		if (op != 0) return op;
		_yyyymmdd = y * 10000 + m * 100 + d;
		return 0;
	}
};