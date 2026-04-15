#include <climits>  // for ULLONG_MAX
#include <cstring>  // for std::strlen, std::memcpy
#include <utility>  // for std::swap

class String {
public:
    // 0. 长度类型别名
    using size_type = unsigned long;

    // 1. npos：位置/容量上限常量
    static constexpr size_type npos = ULLONG_MAX;

private:
    // 2. 三个私有数据成员：长度、容量、缓冲区指针
    size_type m_len;  // 当前串长度
    size_type m_cap;  // 当前缓冲区容量（不含结尾 '\0'）
    char* m_buf;      // 指向长度为 m_cap + 1 的字符数组（最后一个为 '\0'）

    // 私有：根据给定长度和容量构造（帮助 reserve 等）
    String(size_type len, size_type cap, const char* src) : m_len(len), m_cap(cap), m_buf(nullptr) {
        if (m_cap < m_len) {
            m_cap = m_len;
        }
        // 分配 m_cap + 1，全部填 '\0'
        m_buf = new char[m_cap + 1]();
        if (src && m_len > 0) {
            std::memcpy(m_buf, src, m_len);
        }
        m_buf[m_len] = '\0';
        // 注意：m_buf[m_len..m_cap] 都是 '\0'
    }

public:
    // 3. 默认构造：长度0，容量15，缓冲区全是 '\0'
    String() : m_len(0), m_cap(15), m_buf(new char[m_cap + 1]()) {
        m_buf[0] = '\0';
        // new[]() 已将其余都置为 0
    }

    // 4. size(): 获取长度
    size_type size() const { return m_len; }

    // 5. capacity(): 获取容量
    size_type capacity() const { return m_cap; }

    // 6. data(): 获取串数据指针（可写）
    char* data() { return m_buf; }

    // 7. c_str(): 获取 C 风格字符串指针（只读）
    const char* c_str() const { return m_buf; }

    // 8. 析构：释放缓冲区
    ~String() {
        delete[] m_buf;
        m_buf = nullptr;
        m_len = 0;
        m_cap = 0;
    }

    // 9. 指定 C 字符串内容的构造函数
    explicit String(const char* s) {
        if (!s) {
            // 视作空串
            m_len = 0;
            m_cap = 15;
            m_buf = new char[m_cap + 1]();
            m_buf[0] = '\0';
            return;
        }
        size_type len = static_cast<size_type>(std::strlen(s));
        m_len = len;
        // 容量至少为长度；也可以做点策略，这里直接等于长度
        m_cap = (len > 15 ? len : 15UL);
        m_buf = new char[m_cap + 1]();
        if (len > 0) {
            std::memcpy(m_buf, s, len);
        }
        m_buf[m_len] = '\0';
    }

    // 10. 交换成员函数
    void swap(String& other) noexcept {
        using std::swap;
        swap(m_len, other.m_len);
        swap(m_cap, other.m_cap);
        swap(m_buf, other.m_buf);
    }

    // 11. 拷贝构造：深拷贝
    String(const String& other)
        : m_len(other.m_len), m_cap(other.m_cap), m_buf(new char[other.m_cap + 1]()) {
        if (m_len > 0) {
            std::memcpy(m_buf, other.m_buf, m_len);
        }
        m_buf[m_len] = '\0';
        // 尽量保持剩余部分也为 '\0'，new[]() 初始化已保证
    }

    // 12. 移动构造：委托默认构造再交换
    String(String&& other) noexcept
        : String()  // 先构造一个空串（长度0、容量15、缓冲区非空）
    {
        // 交换后：this 拿到 other 的缓冲区及长度/容量
        // other 变成长度0、容量15、有自己的小缓冲区
        swap(other);
        // 题目要求：参数对象移动后长度置零。此时 other.m_len 已为 0（来自默认构造）。
    }

    // 13. 拷贝赋值运算符
    String& operator=(const String& other) {
        if (this == &other) {
            return *this;  // 自赋值
        }
        // 参考实现：拷贝构造临时对象，再与当前对象交换
        String tmp(other);
        swap(tmp);
        // tmp 析构时释放原有缓冲区
        return *this;
    }

    // 14. 移动赋值运算符
    String& operator=(String&& other) noexcept {
        if (this == &other) {
            return *this;  // 自赋值
        }
        // 参考实现：
        // 1) 创建空临时对象
        String tmp;  // 默认构造，空串
        // 2) 当前对象与临时对象交换，当前对象变空，tmp 持有原数据
        swap(tmp);
        // 3) 当前对象与参数对象交换，当前对象获得参数数据，参数清空
        swap(other);
        // 4) tmp 析构时释放当前对象原来的内存
        return *this;
    }

    // 15. empty(): 判断是否空串
    bool empty() const { return m_len == 0; }

    // 16. clear(): 置为空串
    void clear() {
        m_len = 0;
        if (m_buf) {
            m_buf[0] = '\0';
        }
        // 其余部分保持原样（通常仍为 '\0'）
    }

    // 17. 字符赋值：operator=(char)
    String& operator=(char c) {
        // 如有必要可缩容/扩容，但题目只要求结果
        if (m_cap < 1) {
            // 至少要能放一个字符
            reserve(1);
        }
        m_len = 1;
        m_buf[0] = c;
        m_buf[1] = '\0';
        return *this;
    }

    // 18. C 风格串赋值：operator=(const char*)
    String& operator=(const char* s) {
        if (!s) {
            clear();
            return *this;
        }
        size_type len = static_cast<size_type>(std::strlen(s));
        if (m_cap < len) {
            reserve(len);
        }
        m_len = len;
        if (len > 0) {
            std::memcpy(m_buf, s, len);
        }
        m_buf[m_len] = '\0';
        return *this;
    }

    // 19. 指定长度和填充字符的构造函数
    String(size_type n, char c) : m_len(n), m_cap(n > 15 ? n : 15UL), m_buf(new char[m_cap + 1]()) {
        for (size_type i = 0; i < m_len; ++i) {
            m_buf[i] = c;
        }
        m_buf[m_len] = '\0';
        // 其余部分保持 '\0'
    }

    // 20. 下标运算符（可写）：返回字符引用
    char& operator[](size_type i) {
        // 题目保证 i 不超过当前长度，这里不做边界检查
        return m_buf[i];
    }

    // 21. 下标运算符（常量）：返回字符常量引用
    const char& operator[](size_type i) const { return m_buf[i]; }

    // 22. reserve(): 保留指定容量（不小于 n），长度和内容不变
    void reserve(size_type n) {
        if (n <= m_cap) {
            return;  // 原容量已足够
        }
        // 用当前串和更大的容量构造一个新串，然后交换
        String tmp(m_len, n, m_buf);  // 私有构造：复制前 m_len 个字符
        swap(tmp);
        // tmp 析构时释放旧缓冲区
    }

    // 23. push_back(): 末尾添加一个字符
    void push_back(char c) {
        if (m_len >= m_cap) {
            // 容量不足，先扩容（通常加倍）
            size_type new_cap = (m_cap == 0 ? 1 : m_cap * 2);
            if (new_cap < m_len + 1) {
                new_cap = m_len + 1;
            }
            reserve(new_cap);
        }
        m_buf[m_len] = c;
        ++m_len;
        m_buf[m_len] = '\0';
    }

    // 24. pop_back(): 删除最后一个字符（前置条件：非空）
    void pop_back() {
        if (m_len == 0) {
            return;  // 按题意测试环境不会调用到这里
        }
        --m_len;
        m_buf[m_len] = '\0';
    }
};