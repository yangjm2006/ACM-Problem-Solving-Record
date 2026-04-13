#include <iostream>

#include "Matrix3d.hpp"
int main() {
    const double v[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix3d a;         // 应默认构造为零阵。
    Matrix3d b{v};      // b的三个行向量应为{1,2,3}, {4,5,6}, {7,8,9}
    Matrix3d c{b};      // 拷贝构造
    std::cout << c[0];  // {1,2,3}
    c[1];               // {4,5,6}
    c[2];               // {7,8,9}
    c[2][2];            // 第一个[]由矩阵类重载，第二个则是向量类重载，元素值应为9。
    a = b;              // 拷贝赋值操作符
    a += b;             // 矩阵自加
    a = b + c;          // 矩阵相加
    a *= 2.0;           // 矩阵自乘
    a = b * 2.0;        // 矩阵数乘
    a = b * c;          // 矩阵乘法
    const auto U = Matrix3d::identity();  // u应当是单位矩阵
    Vector3d w{2.0, 1.0, 3.0};
    auto m = Matrix3d::scale(0.5, 2, 3);  // auto是C++11的类型自动推导
    auto p = m * w;                       // 矩阵乘以向量。结果w应为Vector3d{1.0, 2.0, 9.0}
    return 0;
}