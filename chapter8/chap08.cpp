#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

std::istream &iofunction(std::istream &is)
{
    string s1;
    while (is >> s1)
    {
        cout << s1 << endl;
    }
    is.clear();
    return is;
}

void q_8_2()
{
    iofunction(cin);
}

void q_8_4()
{
    std::ifstream ifs("input.txt");
    vector<string> vec;
    string buf;
    if (ifs)
    {
        while (getline(ifs, buf))
        {
            vec.push_back(buf);
        }
    }
    for (auto c : vec)
    {
        cout << c << endl;
    }
}

void q_8_5()
{
    std::ifstream ifs("input.txt");
    vector<string> vec;
    string buf;
    if (ifs)
    {
        while (ifs >> buf)
        {
            vec.push_back(buf);
        }
    }
    for (auto c : vec)
    {
        cout << c << endl;
    }
}

void q_8_9()
{
    std::istringstream s("aa\nbb\ncc");
    iofunction(s);
}

void q_8_10()
{
    vector<string> vec;
    string buf;
    ifstream ifs("input.txt");
    if (!ifs)
    {
        cerr << "open file failed" << endl;
        return;
    }
    while (getline(ifs, buf))
    {
        vec.push_back(buf);
    }
    for (auto &c : vec)
    {
        istringstream s(c);
        while (s >> buf)
        {
            cout << buf << endl;
        }
    }
}

struct PersonInfo
{
    string name;
    vector<string> phones;
};

void q_8_11()
{
    string line, word;         // 保存来自输入的一行和单词
    vector<PersonInfo> people; // 保存来自输入的所有记录
    ifstream ifs("personInfo.txt");
    if (!ifs)
    {
        cerr << "open file failed" << endl;
        return;
    }
    // 逐行从输入读入数据
    while (getline(ifs, line))
    {
        PersonInfo info;            // 创建保存此数据的对象
        istringstream record(line); // 将记录绑定到读入的行
        record >> info.name;        // 读取名字
        while (record >> word)      // 读取电话号码
        {
            info.phones.push_back(word); // 保持它们
        }
        people.push_back(info); // 将此记录追加到people末尾
    }

    for (const auto &c : people)
    {
        cout << c.name << "\t";
        for (const auto &number : c.phones)
        {
            cout << number << " ";
        }
        cout << endl;
    }
}

void q_8_12()
{
    string line, word;
    vector<PersonInfo> people;
    ifstream ifs("personInfo.txt");
    istringstream record;
    if (!ifs)
    {
        cerr << "open file failed" << endl;
        return;
    }
    while (getline(ifs, line))
    {
        record.str(line); // 将line拷贝到record
        PersonInfo info;
        record >> info.name;
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        record.clear(); // 清空本轮istringstream
        people.push_back(info);
    }
    for (auto &c : people)
    {
        cout << c.name << "\t";
        for (auto &number : c.phones)
        {
            cout << number << " ";
        }
        cout << endl;
    }
}

bool valid(const string &s)
{
    for (const auto &c : s)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

string format(const string s)
{
    return s;
}

void q_8_13()
{
    string line, word;
    vector<PersonInfo> people;
    ifstream ifs("personInfo.txt");
    ofstream ofs("personInfo_new.txt");
    istringstream record;
    if (!ifs)
    {
        cerr << "open file failed" << endl;
        return;
    }
    while (getline(ifs, line))
    {
        record.str(line); // 将line拷贝到record
        PersonInfo info;
        record >> info.name;
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        record.clear(); // 清空本轮istringstream
        people.push_back(info);
    }

    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
        {
            if (!valid(nums))
            {
                badNums << " " << nums;
            }
            else
            {
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty())
        {
            ofs << entry.name << " " << formatted.str() << endl;
        }
        else
        {
            cerr << "input error: " << entry.name << " invalid numbers: " << badNums.str() << endl;
        }
    }
}
int main()
{
    // q_8_2();
    // q_8_4();
    // q_8_5();
    // q_8_9();
    // q_8_10();
    // q_8_11();
    // q_8_12();
    q_8_13();
    return 0;
}