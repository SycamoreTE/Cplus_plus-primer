#include<iostream>

int main() {
int a[2][2][3] = { {{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}} };
int* ptr = (int*)(&a + 1);
printf(" %d %d", *(int*)(a + 1), *(ptr - 1));
printf(" %d %d", *(int*)(*a + 1), *(int*)(*a + 2));
return 0;
}