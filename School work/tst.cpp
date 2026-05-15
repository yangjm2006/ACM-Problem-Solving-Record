#pragma once

#include <cstring>
#include <utility>

class Buffer {
private:
	unsigned long cap;
	char* buf;

public:
	Buffer() : cap(0), buf(nullptr) {}
	Buffer(unsigned long cap) : cap(cap), buf(new char[cap]()) {}

	unsigned long size() const { return cap; }
	char* addr() { return buf; };
	const char* addr() const { return buf; }

	void swap(Buffer& other) {
		std::swap(buf, other.buf);
		std::swap(cap, other.cap);
	}

	~Buffer() { delete[] buf; }

	Buffer(const Buffer& other) {
		cap = other.cap;
		buf = new char[cap];
		std::memcpy(buf, other.buf, cap);
	}

	Buffer& operator=(const Buffer& other) {
		Buffer tmp(other);
		this->swap(tmp);
		return *this;
	}

	Buffer(Buffer&& other) : cap(other.cap), buf(other.buf) {
		other.cap = 0;
		other.buf = nullptr;
	}

	Buffer& operator=(Buffer&& other) {
		if (&other == this) return *this;
		Buffer tmp(std::move(other));
		this->swap(tmp);
		return *this;
	}
};