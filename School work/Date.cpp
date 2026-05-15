#pragma once

#include <ctime>
#include <iomanip>
#include <ostream>

class Date {
private:
	unsigned int date;
	inline static int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	static bool is_leap(int y) { return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0); }
	static bool check_day(int y, int m, int d) {
		int day_max = days[m];
		if (m == 2 && is_leap(y)) day_max = 29;
		if (d < 1 || d > day_max) return 0;
		return 1;
	}

public:
	Date() {
		time_t now = time(nullptr);
		tm* t = localtime(&now);
		int y = t->tm_year + 1900, m = t->tm_mon + 1, d = t->tm_mday;
		date = y * 10000 + m * 100 + d;
	}
	Date(int y, int m, int d) : Date() {
		if (check(y, m, d) == 0) date = y * 10000 + m * 100 + d;
	}

	int year() const { return date / 10000; }
	int month() const { return date / 100 % 100; }
	int day() const { return date % 100; }

	bool is_leap_year() const { return is_leap(year()); }

	void print(std::ostream& os) const {
		os << std::setfill('0') << std::setw(4) << year() << "-" << std::setw(2) << month() << "-"
		   << std::setw(2) << day();
	}

	static int check(int y, int m, int d) {
		if (y < 1800 || y > 9999) return -1;
		if (m < 1 || m > 12) return -2;
		if (check_day(y, m, d)) return 0;
		return -3;
	}

	int set(int y, int m, int d) {
		int flag = check(y, m, d);
		if (flag != 0) return flag;
		date = y * 10000 + m * 100 + d;
		return 0;
	}
};