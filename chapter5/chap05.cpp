#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iterator>
#include <cstddef>
#include <stdexcept>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::runtime_error;
using std::string;
using std::vector;

void q_5_3()
{
    int value = 0, sum = 0;
    while (value <= 10)
        sum += value, ++value;
    cout << sum << endl;
}

void q_5_5()
{
    const vector<string> score{"F", "D", "C", "B", "A", "A++"};
    int grade = 0;
    string final_grade;
    while (cin >> grade)
    {
        if (grade < 60)
        {
            final_grade = score[0];
        }
        else
        {
            final_grade = score[(grade - 50) / 10];
            if (grade != 100)
            {
                if (grade % 10 > 7)
                {
                    final_grade += '+';
                }
                else if (grade % 10 < 3)
                {
                    final_grade += '-';
                }
            }
        }
        cout << "final grade: " << final_grade << endl;
    }
}

void q_5_6()
{
    const vector<string> score{"F", "D", "C", "B", "A", "A++"};
    int grade = 0;
    string final_grade;
    while (cin >> grade)
    {
        final_grade = (grade < 60) ? score[0] : score[(grade - 50) / 10];
        final_grade += (grade == 100 || grade < 60) ? ' ' : (grade % 10 >= 7) ? '+'
                                                        : (grade % 10 < 3)    ? '-'
                                                                              : ' ';
        cout << "final grade : " << final_grade << endl;
    }
}

void q_5_9()
{
    char ch;
    int vowelCount = 0;
    while (cin >> ch)
    {
        switch (ch)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            vowelCount++;
            break;
        default:
            break;
        }
    }
    cout << "vowel count : " << vowelCount << endl;
}

void q_5_10()
{
    char ch;
    int vowelCount = 0;
    while (cin >> ch)
    {
        switch (ch)
        {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            vowelCount++;
            break;
        default:
            break;
        }
    }
    cout << "vowel count : " << vowelCount << endl;
}

void q_5_11()
{
    char ch;
    int vowelCount = 0, spaceCnt = 0, lineCnt = 0, tabCnt = 0;
    while (cin >> std::noskipws >> ch)
    {
        switch (ch)
        {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            vowelCount++;
            break;
        case '\0':
            spaceCnt++;
            break;
        case '\n':
            lineCnt++;
            break;
        case '\t':
            tabCnt++;
            break;
        default:
            break;
        }
    }
    cout << "vowel count : " << vowelCount << "\n"
         << "space count : " << spaceCnt << "\n"
         << "line count : " << lineCnt << "\n"
         << "tab count : " << tabCnt << endl;
}

void q_5_12()
{
    char ch, prech = '\0';
    unsigned vowelCount = 0, spaceCnt = 0, lineCnt = 0, tabCnt = 0;
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
    while (cin >> std::noskipws >> ch)
    {
        switch (ch)
        {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            vowelCount++;
            break;
        case 'i':
            vowelCount++;
            if (prech == 'f')
            {
                fiCnt++;
                break;
            }
        case '\0':
            spaceCnt++;
            break;
        case '\n':
            lineCnt++;
            break;
        case '\t':
            tabCnt++;
            break;
        case 'f':
            if (prech == 'f')
                ffCnt++;
            break;
        case 'l':
            if (prech == 'f')
            {
                flCnt++;
            }
            break;
        default:
            break;
        }
        prech = ch;
    }
    cout << "vowel count : " << vowelCount << "\n"
         << "space count : " << spaceCnt << "\n"
         << "line count : " << lineCnt << "\n"
         << "tab count : " << tabCnt << "\n"
         << "ff count : " << ffCnt << "\n"
         << "fl count : " << flCnt << "\n"
         << "fi count : " << fiCnt << endl;
}

void q_5_14()
{
    string s, pres, max_s;
    int count = 1, max_count = -1;
    while (cin >> s)
    {
        if (s == pres)
        {
            count++;
        }
        else
        {
            if (max_count < count)
            {
                max_s = pres;
                max_count = count;
            }
            count = 1; // 计数器记1
        }
        pres = s;
    }
    // 最后一个元素
    if (max_count < count)
    {
        max_s = pres;
        max_count = count;
    }
    cout << "max_s: " << max_s << '\n'
         << "max count: " << max_count << endl;
}

void q_5_17()
{
    vector<int> v1;
    vector<int> v2;
    int num;
    cout << "enter v1: " << endl;
    while (cin >> num)
    {
        v1.push_back(num);
    }
    for (auto c : v1)
    {
        cout << c << ' ';
    }
    cout << endl;
    if (!cin)
    {
        cin.clear();
    }
    cout << "enter v2: " << endl;
    while (cin >> num)
    {
        v2.push_back(num);
    }
    for (auto c : v2)
    {
        cout << c << ' ';
    }
    cout << endl;
    for (size_t i = 0, sz1 = v1.size(), sz2 = v2.size(); i != sz1 && i != sz2; ++i)
    {
        if (v1[i] != v2[i])
        {
            cout << "compare false" << endl;
            return;
        }
    }
    cout << "v1 is similar to v2" << endl;
}

void q_5_19()
{
    string s1, s2;
    do
    {
        if (s1.size() <= s2.size())
        {
            cout << s1 << endl;
        }
        else
        {
            cout << s2 << endl;
        }
    } while (cin >> s1 >> s2);
}

void q_5_20()
{
    string s1, s2, repeat_s;
    while (cin >> s1)
    {
        if (s2 == s1)
        {
            repeat_s = s1;
            cout << s1 << endl;
            break;
        }
        s2 = s1;
    }
    if (repeat_s.empty())
    {
        cout << "no repetitive number" << endl;
    }
}

void q_5_21()
{
    string s1, s2, repeat_s;
    while (cin >> s1)
    {
        if (!isupper(s1[0]))
        {
            cout << "s[0] requires upper" << endl;
            continue;
        }
        if (s2 == s1)
        {
            repeat_s = s1;
            cout << s1 << endl;
            break;
        }
        s2 = s1;
    }
    if (repeat_s.empty())
    {
        cout << "no repetitive number" << endl;
    }
}

void q_5_23()
{
    int num1, num2;
    while (cin >> num1 >> num2)
    {
        if (num2 == 0)
        {
            throw runtime_error("num2 can not equal to zero");
        }
        cout << num1 / num2 << endl;
    }
}

void q_5_25()
{
    int num1, num2;
    while (cin >> num1 >> num2)
    {
        try
        {
            if (num2 == 0)
            {
                throw runtime_error("num2 can not equal to zero");
            }
            cout << num1 / num2 << endl;
        }catch(runtime_error err){
            cout << err.what()
                << "\n Try again? Enter y or n" << endl;
            char c;
            cin >> c;
            if(!cin || c == 'n'){
                break;
            }
        }
    }
}

int main()
{
    // q_5_3();
    // q_5_5();
    // q_5_6();
    // q_5_9();
    // q_5_10();
    // q_5_11();
    // q_5_12();
    // q_5_14();
    // q_5_17();
    // q_5_19();
    // q_5_20();
    // q_5_21();
    // q_5_23();
    q_5_25();
    return 0;
}