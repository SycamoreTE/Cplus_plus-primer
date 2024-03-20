#include <iostream>
using namespace std;

void add(int* p, int& r, int num) {
*p += num;     //指针所指的变量x + num
r += num;      //引用的x + num , 所以会翻倍
}
int main() {
int x = 10;
int* p = &x;
int& r = x;
std::cout << *p << " " << r << std::endl;
add(p, r, 1);
std::cout << *p << " " << r << std::endl;
cout << x << endl;
double nn = 0;
double& inf = nn;
double *ptr = &nn;
std::cout << sizeof(nn) << sizeof(inf) << sizeof(ptr) << std::endl;// 8 8 4
return 0;
}