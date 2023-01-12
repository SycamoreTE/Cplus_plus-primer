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

void q_4_21()
{
    vector<int> vec;
    int num;
    while (cin >> num)
    {
        vec.push_back(num);
    }
    for (auto &c : vec)
    {
        if (c % 2 == 1)
        {
            c = c * 2;
        }
    }
    for (auto c : vec)
    {
        cout << c << ' ';
    }
}

void q_4_22()
{
    int grade = 0;
    string finalgrade{};
    cout << "enter grade: 0~100" << endl;
    while (cin >> grade)
    {
        finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail"
                                              : (grade < 75)   ? "low pass"
                                                               : "pass";
        cout << finalgrade << endl;
    }
}

void q_4_22_1()
{
    int grade = 0;
    string finalgrade{};
    cout << "enter grade: 0~100" << endl;
    while (cin >> grade)
    {
        if (grade > 90)
        {
            finalgrade = "high pass";
        }
        else if (grade > 75)
        {
            finalgrade = "pass";
        }
        else if (grade > 60)
        {
            finalgrade = "low pass";
        }
        else
        {
            finalgrade = "fail";
        }
        cout << finalgrade << endl;
    }
}

#include <iostream> // high level input/output operations.

void q_4_23()
{
    // void type
    cout << "void: nullptr_t\t" << sizeof(std::nullptr_t) << " bytes" << endl << endl;
    
    // boolean type
    cout << "bool:\t\t" << sizeof(bool) << " bytes" << endl << endl;
    
    // charactor type
    cout << "char:\t\t" << sizeof(char) << " bytes" << endl;
    cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << endl;
    cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << endl;
    cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << endl << endl;
    
    // integers type
    cout << "short:\t\t" << sizeof(short) << " bytes" << endl;
    cout << "int:\t\t" << sizeof(int) << " bytes" << endl;
    cout << "long:\t\t" << sizeof(long) << " bytes" << endl;
    cout << "long long:\t" << sizeof(long long) << " bytes" << endl << endl;
    
    // floating point type
    cout << "float:\t\t" << sizeof(float) << " bytes" << endl;
    cout << "double:\t\t" << sizeof(double) << " bytes" << endl;
    cout << "long double:\t" << sizeof(long double) << " bytes" << endl << endl;
	
    // Fixed width integers
    cout << "int8_t:\t\t" << sizeof(int8_t) << " bytes" << endl;
    cout << "uint8_t:\t" << sizeof(uint8_t) << " bytes" << endl;
    cout << "int16_t:\t" << sizeof(int16_t) << " bytes" << endl;
    cout << "uint16_t:\t" << sizeof(uint16_t) << " bytes" << endl;
    cout << "int32_t:\t" << sizeof(int32_t) << " bytes" << endl;
    cout << "uint32_t:\t" << sizeof(uint32_t) << " bytes" << endl;
    cout << "int64_t:\t" << sizeof(int64_t) << " bytes" << endl;
    cout << "uint64_t:\t" << sizeof(uint64_t) << " bytes" << endl;
}


int main()
{
    // q_4_21();
    // q_4_22();
    // q_4_22_1();
    q_4_23();
    return 0;
}