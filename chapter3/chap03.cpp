#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iterator>
#include <cstddef>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::vector;

void q_3_1()
{

    cout << "Enter numbers" << endl;
    int val = 0, sum = 0;
    while (cin >> val)
    {
        sum += val;
    }
    cout << "The sum of these number is " << sum << endl;
}

void q_3_2()
{
    string word;
    while (cin >> word)
    {
        cout << word << endl;
    }
}

void q_3_3()
{
    string line;
    while (getline(cin, line))
    {
        cout << line << endl;
    }
}

void q_3_4()
{
    string s1, s2;
    cout << "Enter two string" << endl;
    cin >> s1 >> s2;
    if (s1 == s2)
    {
        cout << "==" << endl;
    }
    else if (s1 < s2)
    {
        cout << s2 << endl;
    }
    else
    {
        cout << s1 << endl;
    }
}

void q_3_5()
{
    string sum, s1;
    while (cin >> s1)
    {
        sum = sum + " " + s1;
    }
    cout << sum << endl;
}

// 所有字符串修改为x
void q_3_6()
{
    string s1;
    cin >> s1;
    for (auto &c : s1)
    {
        c = 'X';
    }
    cout << s1 << endl;
}

void q_3_8_1()
{
    string s1;
    cin >> s1;
    for (string::size_type index = 0; index <= s1.size(); ++index)
    {
        s1[index] = 'X';
    }
    cout << s1 << endl;
}

void q_3_8_2()
{
    string s1;
    cin >> s1;
    string::size_type index = 0;
    while (s1[index] != '\0')
    {
        s1[index] = 'x';
        index++;
    }
    cout << s1 << endl;
}

void q_3_10()
{
    string s1, str;
    cin >> s1;
    for (auto &c : s1)
    {
        if (!ispunct(c))
        {
            str = str + c;
        }
    }
    cout << str << endl;
}

void q_3_14()
{
    int number;
    vector<int> svec;
    while (cin >> number)
    {
        svec.push_back(number);
        cout << number << endl;
    }
}

void q_3_15()
{
    vector<string> v1;
    string s1;
    while (cin >> s1)
    {
        v1.push_back(s1);
        cout << s1 << endl;
    }
}

void q_3_16()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    cout << v1.size() << endl;
    for (auto c : v1)
    {
        cout << c << ' ';
    }
    cout << endl;

    cout << v2.size() << endl;
    for (auto c : v2)
    {
        cout << c << ' ';
    }
    cout << endl;

    cout << v3.size() << endl;
    for (auto c : v3)
    {
        cout << c << ' ';
    }
    cout << endl;

    cout << v4.size() << endl;
    for (auto c : v4)
    {
        cout << c << ' ';
    }
    cout << endl;

    cout << v5.size() << endl;
    for (auto c : v5)
    {
        cout << c << ' ';
    }
    cout << endl;

    cout << v6.size() << endl;
    for (auto c : v6)
    {
        cout << c << ' ';
    }
    cout << endl;

    cout << v7.size() << endl;
    for (auto c : v7)
    {
        cout << c << ' ';
    }
    cout << endl;
}

void q_3_17()
{
    vector<string> v1;
    string str;
    while (cin >> str)
    {
        v1.push_back(str);
    }
    for (auto &c1 : v1)
    {
        for (auto &c2 : c1)
        {
            c2 = toupper(c2);
        }
    }
    for (auto c : v1)
    {
        cout << c << endl;
    }
}

void q_3_19()
{
    vector<int> v1(10, 42);
    vector<int> v2{42, 42, 42, 42, 42};
    vector<int> v3;
    for (int i = 0; i < 10; ++i)
    {
        v3.push_back(42);
    }
    for (auto c : v3)
    {
        cout << c << ' ';
    }
}

void q_3_20()
{
    vector<int> v;
    int number;
    while (cin >> number)
    {
        v.push_back(number);
    }
    for (int i = 0; i != v.size(); ++i)
    {
        cout << v[i] + v[i + 1] << endl;
    }
    for (int j = 0; j != v.size() / 2; ++j)
    {
        cout << v[j] + v[v.size() - j - 1] << endl;
    }
}

void q_3_21()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    cout << v1.size() << endl;
    for (auto it = v1.begin(); it != v1.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << v2.size() << endl;
    for (auto it = v2.begin(); it != v2.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << v3.size() << endl;
    for (auto it = v3.begin(); it != v3.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << v7.size() << endl;
    for (auto it = v7.begin(); it != v7.end(); ++it)
    {
        cout << *it << ' ';
    }
}

void q_3_22()
{
    vector<string> v{"some string", "text"};
    auto it = v.begin();
    for (auto &c : *it)
    {
        c = toupper(c);
    }

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << endl;
    }
}

void q_3_23()
{
    vector<int> v1(10, 3);
    for (auto it = v1.begin(); it != v1.end(); ++it)
    {
        *it = (*it) * 2;
        cout << *it << ' ';
    }
}

void q_3_24()
{
    vector<int> v1;
    int num;
    while (cin >> num)
    {
        v1.push_back(num);
    }
    for (auto it = v1.begin(); it != v1.end(); ++it)
    {
        cout << *it + *(it + 1) << ' ';
    }
    vector<int> sum;
    for (auto it1 = v1.begin(), it2 = v1.end() - 1; it1 < v1.begin() + (v1.end() - v1.begin()) / 2; ++it1, --it2)
    {
        sum.push_back(*it1 + *it2);
    }
    for (auto c : sum)
    {
        cout << c << " ";
    }
}

void q_3_25()
{
    vector<unsigned> score(11, 0);
    unsigned grade;
    auto it = score.begin();
    while (cin >> grade)
    {
        ++(*(it + grade / 10));
    }
    for (auto c : score)
    {
        cout << c << ' ';
    }
}

void q_3_31()
{
    int sq[10];
    for (size_t i = 0; i < 10; ++i)
    {
        sq[i] = i;
    }
    for (auto c : sq)
    {
        cout << c << ' ';
    }
}

void q_3_32()
{
    vector<int> v1;
    for (int index = 0; index < 10; ++index)
    {
        v1.push_back(index);
    }
    vector<int> v2(v1);
    for (auto c : v2)
    {
        cout << c << ' ';
    }
}

void q_3_35()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto c : a)
    {
        cout << c << " ";
    }
    cout << endl;
    int *beg = a, *end = &a[10];
    while (beg != end)
    {
        *beg = 0;
        ++beg;
    }
    for (auto c : a)
    {
        cout << c << " ";
    }
}

void q_3_36()
{
    int a1[] = {0, 1, 2, 3, 4, 5};
    int a2[] = {0, 1, 2, 3, 5, 6};
    int *begin1 = a1, *begin2 = a2;
    int *end1 = end(a1), *end2 = end(a2);
    while (begin1 != end1 && begin2 != end2)
    {
        if (*begin1 == *begin2)
        {
            begin1++;
            begin2++;
        }
        else
        {
            cout << "a1 != a2" << endl;
            return;
        }
    }
}

void q_3_36_1()
{
    vector<int> v1;
    vector<int> v2;
    int num1, num2;
    cout << "enter v1" << endl;
    while (cin >> num1)
    {
        v1.push_back(num1);
    }
    cout << "enter v2" << endl;
    while (cin >> num2)
    {
        v2.push_back(num2);
    }
    if (v1 == v2)
    {
        cout << "v1 == v2" << endl;
    }
    else
    {
        cout << "v1 != v2" << endl;
    }
}

void q_3_39()
{
    string s1 = "hello";
    string s2 = "Hello";
    const char cha1[] = "A string example";
    const char cha2[] = "A different string";
    if (s1 < s2)
    {
        cout << "s1 < s2" << endl;
    }
    else if (s1 == s2)
    {
        cout << "s1 == s2" << endl;
    }
    else
    {
        cout << "s1 > s2" << endl;
    }
    if (strcmp(cha1, cha2))
    {
        cout << "cha1 >= cha2" << endl;
    }
    else
    {
        cout << "cha1 < cha2" << endl;
    }
}

void q_3_40()
{
    char ca1[] = "Happy new year";
    char ca2[] = ", miss li";
    char ca3[20];
    strcpy(ca3, ca1);
    strcat(ca3, ca2);
    cout << ca3 << endl;
}

void q_3_41()
{
    int arr[] = {0, 1, 1, 2, 1, 3, 3};
    int arr1[10];
    vector<int> vec(begin(arr), end(arr));
    for (auto c : vec)
    {
        cout << c << ' ';
    }
    cout << endl;
    int i = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        arr1[i++] = *it;
    }
    for (int j = 0; j < i; ++j)
    {
        cout << arr1[j] << ' ';
    }
}

void q_3_43()
{
    int arr[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
    // 范围for语句遍历
    for (int(&row)[4] : arr)
    {
        for (int colomn : row)
        {
            cout << colomn << ' ';
        }
    }
    cout << endl;
    // 下标运算符
    for (size_t i = 0; i != 3; ++i)
    {
        for (size_t j = 0; j != 4; ++j)
        {
            cout << arr[i][j] << ' ';
        }
    }
    cout << endl;
    // 使用指针
    for (int(*p)[4] = begin(arr); p != end(arr); ++p)
    {
        for (int *q = begin(*p); q != end(*p); ++q)
        {
            cout << *q << ' ';
        }
    }
}

void q_3_44()
{
    int arr[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
    using int_array = int[4];
    // 范围for语句遍历
    for (int_array &row : arr)
    {
        for (int colomn : row)
        {
            cout << colomn << ' ';
        }
    }
    cout << endl;
    // 下标运算符
    for (size_t i = 0; i != 3; ++i)
    {
        for (size_t j = 0; j != 4; ++j)
        {
            cout << arr[i][j] << ' ';
        }
    }
    cout << endl;
    // 使用指针
    for (int_array *p = arr; p != end(arr); ++p)
    {
        for (int *q = begin(*p); q != end(*p); ++q)
        {
            cout << *q << ' ';
        }
    }
}

void q_3_45()
{
    int arr[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
    // 范围for语句遍历
    for (auto &row : arr)
    {
        for (int colomn : row)
        {
            cout << colomn << ' ';
        }
    }
    cout << endl;
    // 下标运算符
    for (auto i = 0; i != 3; ++i)
    {
        for (auto j = 0; j != 4; ++j)
        {
            cout << arr[i][j] << ' ';
        }
    }
    cout << endl;
    // 使用指针
    for (auto *p = begin(arr); p != end(arr); ++p)
    {
        for (auto *q = begin(*p); q != end(*p); ++q)
        {
            cout << *q << ' ';
        }
    }
}

int main()
{
    // q_3_1();
    // q_3_2();
    // q_3_3();
    // q_3_4();
    // q_3_5();
    // q_3_6();
    // q_3_8_1();
    // q_3_8_2();
    // q_3_10();
    // q_3_14();
    // q_3_15();
    // q_3_16();
    // q_3_17();
    // q_3_19();
    // q_3_20();
    // q_3_21();
    // q_3_22();
    // q_3_23();
    // q_3_24();
    // q_3_25();
    // q_3_31();
    // q_3_32();
    // q_3_35();
    // q_3_36();
    // q_3_36_1();
    // q_3_39();
    // q_3_40();
    // q_3_41();
    // q_3_43();
    // q_3_44();
    q_3_45();
    return 0;
}
