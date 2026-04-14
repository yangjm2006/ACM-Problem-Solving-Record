#pragma once
#include <utility>

class Buffer {
private:
    unsigned long long capacity;
    char* address;

public:
    Buffer() : capacity(0), address(nullptr) {}
    Buffer(unsigned long long tcapacity) : capacity(tcapacity), address(new char[capacity]()) {}
    Buffer(const Buffer& other) : Buffer(other.capacity) {
        for (unsigned long long i = 0; i < capacity; i++) {
            address[i] = other.address[i];
        }
    }
    Buffer(Buffer&& other) : capacity(other.capacity), address(other.address) {
        other.capacity = 0;
        other.address = nullptr;
    }

    ~Buffer() { delete[] address; }

    unsigned long long size() const { return capacity; }
    char* addr() { return address; }
    const char* addr() const { return address; }

    void swap(Buffer& other) {
        std::swap(capacity, other.capacity);
        std::swap(address, other.address);
    }

    Buffer& operator=(const Buffer& other) {
        Buffer tmp(other);
        this->swap(tmp);
        return *this;
    }
    Buffer& operator=(Buffer&& other) {
        if (this == &other) {
            return *this;
        }
        Buffer tmp;
        this->swap(tmp);
        this->swap(other);
        return *this;
    }
};