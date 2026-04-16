template <typename T>
const auto& my_min(const T& a, const T& b) {
    if (a < b) return a;
    return b;
}