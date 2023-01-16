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

int main_1(int argc, char *argv[])
{
    const string s1 = argv[1];
    const string s2 = argv[2];

    cout << s1 + s2 << endl;

    return 0;
}

int main(int argc, char *argv[])
{
    string s;
    for (size_t i = 0; i != argc; ++i)
    {
        s += argv[i];
    }
    cout << s << endl;
    return 0;
}
