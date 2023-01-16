#include <iostream>

void q_2_3()
{
    unsigned u1 = 10, u2 = 42;
    // 32
    std::cout << u2 - u1 << std::endl;
    // 2^32
    std::cout << u1 - u2 << std::endl;

    int i1 = 10, i2 = 42;
    // 32 -32
    std::cout << i2 - i1 << std::endl;
    std::cout << i1 - i2 << std::endl;
    // 0
    std::cout << i1 - u1 << std::endl;
    std::cout << u1 - i1 << std::endl;
}

void q_2_8()
{
    std::cout << 2 << "\x4d\12" << std::endl;
    std::cout << 2 << "\t\115\12" << std::endl;
}

void q_2_17()
{
    int i = 12, &ref_i = i;
    double d = 13, &ref_d = d;
    ref_i = d;
    std::cout << i << " " << ref_i << std::endl;
    ref_d = 20;
    std::cout << d << " " << ref_d << std::endl;
}

void q_2_18()
{
    int val = 1024, b = 1;
    int *pval = &val, *p2 = pval;
    std::cout << *pval << " " << pval << std::endl;
    // change the value of a pointer
    pval = &b;
    std::cout << *pval << " " << pval << " " << val << std::endl;
    // change the value to which the pointer points
    *p2 = b;
    std::cout << *pval << " " << val << std::endl;
}

void q_2_20()
{
    const int v2 = 1024;
    int v1 = v2;
    int *p1 = &v1, &r1 = v1;
    //从右往左阅读，p2是个指针，p2是常量的指针； 底层const
    //p3是个常量，p3是个常量指针；顶层const
    const int *p2 = &v2, *const p3 = &v1, &r2 = v2;

    std::cout << *p2 << " " << p2 << " " << p1 << std::endl;
    std::cout << *p3 << " " << p3 << " " << r2 << std::endl;
    p2 = p1;
    std::cout << *p2 << " " << p2 << " " << p1 << std::endl;
    p2 = p3;
    std::cout << *p2 << " " << p2 << " " << p1 << std::endl;
}

int main()
{
    // q_2_3();
    // q_2_8();
    // q_2_17();
    q_2_18();
    q_2_20();
    return 0;
}