class Counter {
private:
    inline static unsigned long long count = 0;

protected:
    Counter() { count++; }
    ~Counter() { count--; }
    Counter(const Counter& other) { count++; }

public:
    static unsigned long long get_object_count() { return count; }
};