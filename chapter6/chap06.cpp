#include <cstddef>
#include <cstring>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::initializer_list;
using std::runtime_error;
using std::string;
using std::vector;

#define NDEBUG // 能避免检查各种条件所需的运行开销

double fact(int val)
{
    int ret = 1;
    while (val > 1)
    {
        ret *= val--;
    }
    return ret;
}

int count_calls()
{
    // 局部静态变量
    static int call = 0;
    return call++;
}

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

// 引用形参交换数值
void swap_further(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 传引用参数
void reset(int &i) { i = 0; }

bool q_6_17(const string s)
{
    for (auto c : s)
    {
        if (isupper(c))
        {
            return true;
        }
    }
    return false;
}

void q_6_17_1(string &s)
{
    for (auto &c : s)
    {
        if (isupper(c))
        {
            c = tolower(c);
        }
    }
}

void q_6_6()
{
    for (size_t i = 0; i != 10; ++i)
    {
        cout << count_calls() << endl;
    }
}

void q_6_3()
{
    int val;
    while (cin >> val)
    {
        cout << fact(val) << endl;
    }
}

void q_6_10()
{
    int a = 0, b = 0;
    while (cin >> a >> b)
    {
        swap(&a, &b);
        cout << "(a , b) = " << a << ' ' << b << endl;
        swap_further(a, b);
        cout << "(a , b) = " << a << ' ' << b << endl;
    }
    reset(a);
    cout << a << endl;
}

int compare(int a, int *b) { return (a > *b) ? a : *b; }

void q_6_21()
{
    int c = 10;
    cout << compare(3, &c) << endl;
}

// 交换指针
void q_6_22(int *&a, int *&b)
{
    int *temp = a;
    a = b;
    b = temp;
}

void q_6_22_1()
{
    int a = 10, b = 16;
    int *pa = &a, *pb = &b;
    cout << pa << ' ' << pb << endl;
    q_6_22(pa, pb);
    cout << pa << ' ' << pb << endl;
}

void print(const int *a)
{
    cout << *a;
    cout << endl;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
    {
        cout << *beg++ << ' ';
    }
    cout << endl;
}

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        cout << ia[i] << ' ';
    }
    cout << endl;
}

void print(const int (&arr)[2])
{
    for (auto c : arr)
    {
        cout << c << ' ';
    }
    cout << endl;
}

void q_6_23()
{
    int i = 0;
    int j[2]{0, 2};
    print(&i);
    print(begin(j), end(j));
    print(j, end(j) - begin(j));
    print(j);
}

void q_6_27(initializer_list<int> li)
{
    int sum = 0;
    for (auto beg = li.begin(); beg != li.end(); ++beg)
    {
        sum += *beg;
    }
    cout << "sum: " << sum << endl;
}

void q_6_27_1()
{
    q_6_27({1, 3, 5, 7, 9});
    q_6_27({2, 3, 4, 5, 6, 9});
}

void q_5_33(vector<string>::iterator begin, vector<string>::iterator end)
{
    cout << *begin << ' ';
    if (begin != end)
    {
        q_5_33(++begin, end);
    }
    else
    {
        return;
    }
}

void q_5_33_1()
{
    vector<string> vec;
    string s;
    while (cin >> s)
    {
        vec.push_back(s);
    }
    auto beg = vec.begin(), end = vec.end();
    q_5_33(beg, end);
}

string make_plural(size_t sz, const string &s, const string &ending = "s")
{
    cout << s << '\t';
    return (sz > 1) ? s + ending : s;
}

void q_6_42()
{
    cout << make_plural(2, "success", "es") << endl;
    cout << make_plural(2, "failure") << endl;
}

void q_6_47(vector<string>::iterator begin, vector<string>::iterator end)
{
#ifndef NDEBUG
    std::cerr << end - begin << __func__ << " " << __FILE__ << " "
              << __LINE__ << " " << __TIME__ << " " << __DATE__ << std::endl;
#endif
    cout << *begin << ' ';
    if (begin != end)
    {
        q_5_33(++begin, end);
    }
    else
    {
        return;
    }
}

void q_6_47_1()
{
    vector<string> vec;
    string s;
    while (cin >> s)
    {
        vec.push_back(s);
    }
    auto beg = vec.begin(), end = vec.end();
    q_6_47(beg, end);
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if (b == 0)
    {
        throw runtime_error("b can not equal to zero");
    }
    return a / b;
}

void q_6_55()
{
    vector<int (*)(int, int)> vec{add, subtract, multiply, divide};
    for (auto e : vec)
    {
        cout << e(4, 2) << endl;
    }
}

int main()
{
    // q_6_3();
    // q_6_6();
    // q_6_10();
    // q_6_21();
    // q_6_22_1();
    // q_6_23();
    // q_6_27_1();
    // q_5_33_1();
    // q_6_42();
    // q_6_47_1();
    q_6_55();
    return 0;
}