#pragma once

#include <climits>
#include <cstring>
#include <utility>

class String {
public:
	using size_type = unsigned long;
	constexpr static size_type npos = ULONG_MAX;

private:
	size_type m_len, m_cap;
	char* m_buf;

public:
	String() : m_len(0), m_cap(15), m_buf(new char[16]()) {}

	size_type size() const { return m_len; }
	size_type capacity() const { return m_cap; }
	char* data() { return m_buf; }
	const char* c_str() const { return m_buf; }

	~String() { delete[] m_buf; }

	String(const char* p) : m_len(std::strlen(p)), m_cap(m_len), m_buf(new char[m_cap + 1]) {
		std::memcpy(m_buf, p, m_len + 1);
	}

	void swap(String& other) {
		std::swap(m_len, other.m_len);
		std::swap(m_cap, other.m_cap);
		std::swap(m_buf, other.m_buf);
	}

	String(const String& other)
		: m_len(other.m_len), m_cap(other.m_cap), m_buf(new char[m_cap + 1]()) {
		std::memcpy(m_buf, other.m_buf, m_len + 1);
	}
	String(String&& other) : String() { this->swap(other); }

	String& operator=(const String& other) {
		String tmp(other);
		this->swap(tmp);
		return *this;
	}
	String& operator=(String&& other) {
		String tmp(std::move(other));
		this->swap(tmp);
		return *this;
	}

	bool empty() const { return m_len == 0; }

	void clear() {
		m_len = 0;
		m_buf[0] = '\0';
	}

	String& operator=(char c) {
		m_len = 1;
		m_buf[0] = c;
		m_buf[1] = '\0';
		return *this;
	}
	String& operator=(const char* p) { return *this = String(p); }

	String(size_type n, char c) : m_len(n), m_cap(n), m_buf(new char[n + 1]) {
		for (int i = 0; i < n; i++) m_buf[i] = c;
		m_buf[n] = '\0';
	}

	char& operator[](size_type i) { return m_buf[i]; }
	const char& operator[](size_type i) const { return m_buf[i]; }

private:
	String(const String& other, size_type n)
		: m_len(other.m_len), m_cap(n), m_buf(new char[n + 1]()) {
		std::memcpy(m_buf, other.m_buf, m_len);
	}

public:
	void reserve(size_type n) {
		if (m_cap < n) *this = String(*this, n);
	}

	void push_back(char c) {
		if (m_len == m_cap) {
			if (m_cap == 0)
				reserve(2);
			else
				reserve(2 * m_cap);
		}
		m_buf[m_len++] = c;
		m_buf[m_len] = '\0';
	}
	void pop_back() { m_buf[--m_len] = '\0'; }
};