#include <bits/stdc++.h>  
using namespace std;  

int main(){
    int a[6] = {};
    for(int i = 0; i < 64; ++i){
        a[0] = (i/32)%2;
        a[1] = (i/16)%2;
        a[2] = (i/8)%2;
        a[3] = (i/4)%2;
        a[4] = (i/2)%2;
        a[5] = i%2;
        cout << a[0] << a[1] << a[2] << a[3] << a[4] << a[5] << endl;
    }
    return 0;
}