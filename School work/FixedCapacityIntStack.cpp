class FixedCapacityIntStack {
private:
    unsigned int _capacity, _size;
    int* _buffer;

public:
    FixedCapacityIntStack(unsigned int capacity)
        : _capacity(capacity), _size(0), _buffer(new int[capacity]) {}
    FixedCapacityIntStack(const FixedCapacityIntStack& other)
        : _capacity(other._capacity), _size(other._size), _buffer(nullptr) {
        _buffer = new int[_capacity];
        for (int i = 0; i < _size; i++) _buffer[i] = other._buffer[i];
    }
    ~FixedCapacityIntStack() { delete[] _buffer; }

    unsigned int capacity() const { return _capacity; }
    unsigned int size() const { return _size; }

    bool empty() const { return _size == 0; }
    bool full() const { return _size == _capacity; }

    void push(int x) {
        _buffer[_size] = x;
        _size++;
    }
    void pop() { _size--; }
    int top() const { return _buffer[_size - 1]; }
};