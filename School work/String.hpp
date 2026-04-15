#pragma once

#include <climits>
#include <cstring>
#include <utility>

class String {
public:
    using size_type = unsigned long;
    constexpr static size_type npos = ULLONG_MAX;

private:
    size_type m_len, m_cap;
    char* m_buf;
    String(const char* s, size_type len, size_type n) {
        m_cap = n;
        m_len = len;
        m_buf = new char[m_cap + 1];
        std::memcpy(m_buf, s, m_len);
        m_buf[m_len] = '\0';
    }

public:
    String() : m_len(0), m_cap(15), m_buf(new char[m_cap + 1]()) {}

    size_type size() const { return m_len; };
    size_type capacity() const { return m_cap; };
    char* data() { return m_buf; };
    const char* c_str() const { return m_buf; }

    ~String() {
        delete[] m_buf;
        m_buf = nullptr;
        m_len = m_cap = 0;
    }

    String(const char* s) {
        size_type len = static_cast<size_type>(std::strlen(s));
        m_cap = m_len = len;
        m_buf = new char[m_cap + 1]();
        memcpy(m_buf, s, len);
        m_buf[m_len] = '\0';
    }

    void swap(String& other) noexcept {
        std::swap(m_len, other.m_len);
        std::swap(m_cap, other.m_cap);
        std::swap(m_buf, other.m_buf);
    }

    String(const String& other)
        : m_len(other.m_len), m_cap(other.m_cap), m_buf(new char[other.m_cap + 1]) {
        std::memcpy(m_buf, other.m_buf, m_len);
        m_buf[m_len] = '\0';
    }
    String(String&& other) : String() { swap(other); }

    String& operator=(const String& other) {
        if (this == &other) return *this;
        String tmp(other);
        swap(tmp);
        return *this;
    }
    String& operator=(String&& other) {
        if (this == &other) return *this;
        String tmp;
        other.swap(tmp);
        swap(tmp);
        return *this;
    }

    bool empty() const { return m_len == 0; }
    void clear() {
        m_len = 0;
        m_buf[0] = 0;
    }

    String& operator=(char c) {
        m_len = 1;
        m_buf[0] = c;
        m_buf[1] = '\0';
        return *this;
    }
    String& operator=(char* c) {
        m_len = 1;
        m_buf[0] = *c;
        m_buf[1] = '\0';
        return *this;
    }

    String(size_type n, char c) : m_len(n), m_cap(n), m_buf(new char[n + 1]) {
        for (int i = 0; i < n; i++) m_buf[i] = c;
        m_buf[n] = '\0';
    }

    char& operator[](size_type pos) { return m_buf[pos]; }
    const char& operator[](size_type pos) const { return m_buf[pos]; }

    void reserve(size_type n) {
        if (n > m_cap) {
            String tmp(this->m_buf, m_len, n);
            swap(tmp);
        }
    }

    void push_back(char c) {
        if (m_len == m_cap) {
            if (m_cap == 0) {
                reserve(15);
            } else {
                reserve(2 * m_cap);
            }
        }
        m_buf[m_len] = c;
        m_len++;
        m_buf[m_len] = '\0';
    }
    void pop_back() {
        m_len--;
        m_buf[m_len] = '\0';
    }
};