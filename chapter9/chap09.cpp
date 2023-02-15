#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <fstream>
#include <stack>

using namespace std;

bool q_9_4(vector<int>::const_iterator begin, vector<int>::const_iterator end, int element)
{
    while (begin != end)
    {
        if (*begin == element)
        {
            return true;
        }
        begin++;
    }
    return false;
}

vector<int>::const_iterator q_9_5(vector<int>::const_iterator begin, vector<int>::const_iterator end, int element)
{
    while (begin != end)
    {
        if (*begin == element)
        {
            return begin;
        }
        ++begin;
    }
    return end;
}

void q_9_13()
{
    list<int> ilst{2, 4, 6, 8, 10};
    vector<int> ivec{1, 3, 5, 7, 9};

    vector<double> dvec(ilst.begin(), ilst.end());
    for (auto &c : dvec)
    {
        cout << c << " ";
    }
    cout << endl;
    vector<double> dvec2(ivec.begin(), ivec.end());
    for (auto &e : dvec2)
    {
        cout << e << " ";
    }
}

void q_9_14()
{
    list<char *> clst{"nice", "good", "brilliant"};
    vector<string> svec;
    svec.assign(clst.begin(), clst.end());
    for (auto &c : svec)
    {
        cout << c << " ";
    }
}

bool q_9_16(vector<int> vec1, vector<int> vec2)
{
    if (vec1 == vec2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void q_9_18()
{
    string s1;
    deque<string> sdq;
    while (cin >> s1)
    {
        sdq.push_back(s1);
    }
    deque<string>::const_iterator it1 = sdq.begin(), it2 = sdq.end();
    while (it1 != it2)
    {
        cout << *it1 << " ";
        ++it1;
    }
}

void q_9_20()
{
    int number;
    list<int> ilst;
    while (cin >> number)
        ilst.push_back(number);
    deque<int> idq1, idq2;
    for (auto c : ilst)
    {
        if (c % 2 == 0)
        {
            idq1.push_back(c);
        }
        else
        {
            idq2.push_back(c);
        }
    }
    for (auto c : idq1)
        cout << c << ' ';
    cout << endl;
    for (auto c : idq2)
        cout << c << ' ';
}

void q_9_21()
{
    list<string> lst;
    vector<string> svec;
    auto iter1 = lst.begin();
    auto iter2 = svec.begin();
    string s1;
    while (cin >> s1)
    {
        iter1 = lst.insert(iter1, s1);
        iter2 = svec.insert(iter2, s1);
    }
    for (auto c : lst)
        cout << c << ' ';
    cout << endl;
    for (auto c : svec)
        cout << c << ' ';
}

void q_9_24()
{
    vector<int> vec;
    cout << vec.at(0) << endl;
    cout << vec[0] << endl;
    cout << vec.front() << endl;
    cout << *vec.begin() << endl;
}

void q_9_26()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> ivec(ia, end(ia));
    list<int> lst(ia, end(ia));
    auto it = ivec.begin();
    auto it1 = lst.begin();
    while (it != ivec.end())
    {
        if (*it % 2 == 1)
        {
            it = ivec.erase(it);
        }
        else
        {
            ++it;
        }
    }
    while (it1 != lst.end())
    {
        if (*it1 % 2 == 0)
        {
            it1 = lst.erase(it1);
        }
        else
        {
            ++it1;
        }
    }
    for (auto c : ivec)
    {
        cout << c << ' ';
    }
    cout << endl;
    for (auto c : lst)
    {
        cout << c << ' ';
    }
}

void q_9_27()
{
    forward_list<int> flst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin();
    auto it = flst.begin();
    while (it != flst.end())
    {
        if (*it % 2 == 1)
        {
            it = flst.erase_after(prev);
        }
        else
        {
            prev = it;
            ++it;
        }
    }
    for (auto c : flst)
    {
        cout << c << ' ';
    }
}

void q_9_28(forward_list<string> &flst, string s1, string s2)
{
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr == s1)
        {
            curr = flst.insert_after(curr, s2);
            return;
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }
    flst.insert_after(prev, s2);
}

void q_9_28_test()
{
    forward_list<string> flst{"hello", "nice", "great"};
    string s1{"ok"};
    string s2{"good"};
    q_9_28(flst, s1, s2);
    for (auto c : flst)
    {
        cout << c << ' ';
    }
}

void q_9_31()
{
    list<int> ilst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = ilst.begin();
    while (iter != ilst.end())
    {
        if (*iter % 2)
        {
            iter = ilst.insert(iter, *iter); // 在指向迭代器的位置之前插入新元素，返回指向新元素的迭代器
            ++iter;
            ++iter;
        }
        else
        {
            iter = ilst.erase(iter); // 删除迭代器指向元素，返回指向被删元素之后的迭代器
        }
    }
    for (auto c : ilst)
    {
        cout << c << ' ';
    }
}

void q_9_31_1()
{
    forward_list<int> flst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin();
    auto it = flst.begin();
    while (it != flst.end())
    {
        if (*it % 2)
        {
            it = flst.insert_after(it, *it); // 在迭代器之后的位置插入新元素，返回指向最后一个插入元素的迭代器
            prev = it;
            ++it;
        }
        else
        {
            it = flst.erase_after(prev); // 删除指向迭代器之后的元素
        }
    }
    for (auto c : flst)
    {
        cout << c << ' ';
    }
}

void q_9_41()
{
    vector<char> cvec;
    char c;
    while (cin >> c)
    {
        cvec.push_back(c);
    }
    string s1{cvec.begin(), cvec.end()};
    cout << s1 << endl;
}

void q_9_43(string &s, const string oldVal, const string newVal)
{
    auto iter = s.begin();
    while (iter != s.end())
    {
        if (oldVal == string(iter, iter + oldVal.size()))
        {
            iter = s.erase(iter, iter + oldVal.size());          // 删除迭代器之间的元素，返回指向被删元素之后的元素的迭代器
            iter = s.insert(iter, newVal.begin(), newVal.end()); // 将迭代器之间的元素插入到迭代器所指元素之前
            iter += newVal.size();
        }
        else
        {
            ++iter;
        }
    }
}

void q_9_44(string &s, const string oldVal, const string newVal)
{
    string::size_type index = 0;
    while (index != s.size())
    {
        if (oldVal == string(s, index, oldVal.size()))
        {
            s.replace(index, oldVal.size(), newVal); // 指定位置和长度替换新字符
        }
        ++index;
    }
}

void q_9_43_test()
{
    string s = "tho this tho that";
    string oldVal = "tho";
    string newVal = "though";
    q_9_43(s, oldVal, newVal);
    cout << s << endl;
}

void q_9_44_test()
{
    string s = "tho this tho that";
    string oldVal = "tho";
    string newVal = "though";
    q_9_44(s, oldVal, newVal);
    cout << s << endl;
}

void q_9_45(string &s, const string prefix, const string suffix)
{
    auto iter = s.begin();
    iter = s.insert(iter, prefix.begin(), prefix.end());
    s.append(suffix);
}

void q_9_46(string &s, const string prefix, const string suffix)
{
    string::size_type index = 0;
    s.insert(index, prefix);
    index += s.size();
    s.insert(index, suffix); // 在pos之前插入指定字符
}

void q_9_45_test()
{
    string s = "Smith";
    string prefix = "Mr.";
    string suffix = "Jr.";
    q_9_45(s, prefix, suffix);
    cout << s << endl;
}

void q_9_46_test()
{
    string s = "Smith";
    string prefix = "Mr.";
    string suffix = "Jr.";
    q_9_46(s, prefix, suffix);
    cout << s << endl;
}

void q_9_47()
{
    const string s{"ab2c3d7R4E6"};
    string numbers{"0123456789"};
    string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    for (string::size_type pos = 0; (pos = s.find_first_of(numbers, pos)) != s.npos; ++pos)
    {
        cout << "number index: " << pos << "The element is: " << s[pos] << endl;
    }
    for (string::size_type pos = 0; (pos = s.find_first_of(alphabet, pos)) != s.npos; ++pos)
    {
        cout << "alphabet index: " << pos << "The element is: " << s[pos] << endl;
    }
    for (string::size_type pos = 0; (pos = s.find_first_not_of(numbers, pos)) != s.npos; ++pos)
    {
        cout << "Not number index: " << pos << "The element is: " << s[pos] << endl;
    }
    for (string::size_type pos = 0; (pos = s.find_first_not_of(alphabet, pos)) != s.npos; ++pos)
    {
        cout << "Not alphabet index: " << pos << "The element is: " << s[pos] << endl;
    }
}

void q_9_49()
{
    const string ascender{"bdfhl"};
    const string desender{"gjpqy"};
    ifstream ifs("letter.txt");
    vector<string> svec;
    string buf;
    if (!ifs)
    {
        cerr << "read file failed" << endl;
        return;
    }
    while (ifs >> buf)
    {
        svec.push_back(buf);
    }
    for (auto c : svec)
    {
        if (c.find_first_of(ascender) == c.npos && c.find_first_of(desender) == c.npos)
        {
            cout << "no ascender and desender words: " << c << endl;
        }
    }
}

void q_9_50()
{
    vector<string> svec(10, "5");
    vector<string> svec1(10, "3.14");
    int sum = 0;
    double sum1 = 0;
    for (const auto c : svec)
    {
        cout << c << ' ';
        sum += stoi(c, 0, 10);
    }
    cout << ", sum: " << sum << endl;
    for (auto c : svec1)
    {
        cout << c << ' ';
        sum1 += stof(c);
    }
    cout << ", sum: " << sum1 << endl;
}

void q_9_52()
{
    string expression{"(a+b)/c-(a*c)"};
    stack<char> cStack;
    for (const auto c : expression)
    {
        if (c == ')')
        {
            char temp;
            while (temp != '(')
            {
                temp = cStack.top();
                cout << temp << ' ';
                cStack.pop();
            }
        }
        else
        {
            cStack.push(c);
        }
    }
    cout << endl;
    while (!cStack.empty())
    {
        char temp = cStack.top();
        cout << temp << ' ';
        cStack.pop();
    }
}

int main()
{
    // vector<int> vec{19, 28, 80, 30, 40};
    // cout << q_9_4(vec.begin(), vec.end(), 30) << endl;
    // vector<int>::const_iterator iter = q_9_5(vec.begin(), vec.end(), 30);
    // cout << *iter << endl;
    // q_9_13();
    // q_9_14();
    // q_9_18();
    // q_9_20();
    // q_9_21();
    // q_9_24();
    // q_9_26();
    // q_9_27();
    // q_9_28_test();
    // q_9_31();
    // q_9_31_1();
    // q_9_41();
    // q_9_43_test();
    // q_9_44_test();
    // q_9_45_test();
    // q_9_46_test();
    // q_9_47();
    // q_9_49();
    // q_9_50();
    q_9_52();
    return 0;
}