class FixedCapacityIntStack {
private:
	const unsigned int cap;
	unsigned int len;
	int* buf;

public:
	FixedCapacityIntStack(unsigned int capacity) : cap(capacity), len(0), buf(new int[capacity]) {}

	~FixedCapacityIntStack() { delete[] buf; }

	unsigned int capacity() const { return cap; }
	unsigned int size() const { return len; }

	bool empty() const { return len == 0; }
	bool full() const { return len == cap; }

	void push(int x) { buf[len++] = x; }
	void pop() { len--; }
	int top() const { return buf[len - 1]; }

	FixedCapacityIntStack(const FixedCapacityIntStack& other)
		: cap(other.capacity()), len(other.size()), buf(new int[cap]) {
		for (int i = 0; i < len; i++) buf[i] = other.buf[i];
	}
};