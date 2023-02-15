#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
using namespace std;

/*求Sn=a+aa+aaa+…+aa…aaa（有n个a）之值，
其中a是一个数字。 例如：2+22+222+2222+22222（n=5），
输入两个数．第一个为a  ，第二个为n（表示有多少个数相加），
其中a和n都是大于１且小于１０的整数．输出其和*/
int Sum_n()
{
    int number = 0, n = 0;
    cin >> number >> n;
    int sum[n + 1];
    for (int i = 0; i < n; ++i)
    {
        sum[i] = number * pow(10, i) + sum[i - 1];
        cout << sum[i] << ' ';
        sum[n + 1] += sum[i];
    }
    cout << sum[n + 1];
    return 0;
}

int Sum_n_1()
{
    int a, n;
    cin >> a >> n;
    int ak = 0;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        ak = ak * 10 + a;
        sum += ak;
    }
    cout << sum;
    return 0;
}

/*给定一个字符串，反序输出。
输入一个字符串在单独的一行，字符串长度<100。*/
void ReverseString()
{
    string s;
    cin >> s;
    int i = 0;
    char s1[100];
    for (auto &c : s)
    {
        s1[i++] = c;
    }
    while (i--)
    {
        cout << s1[i];
    }
}

/*输出100到1000之间能被5和6同时整除的数，输出格式为每10个数为一行。
按题目意思输出，相邻两个数之间用空格隔开（注意每一行末尾没有空格）*/
void printDisidable()
{
    int count = 0;
    for (int num = 100; num < 1000; ++num)
    {
        if (num % 5 == 0 && num % 6 == 0)
        {
            cout << num << ' ';
            count++;
            if (count == 10)
            {
                cout << endl;
                count = 0;
            }
        }
    }
}

/*请统计某个给定范围[L, R]的所有整数中，数字 2 出现的次数。
比如给定范围[2, 22]，数字 2 在数 2 中出现了 1 次，在数 12 中出现 1 次，在数 20 中出现 1次，
在数 21 中出现 1次，在数 22 中出现 2 次，所以数字 2 在该范围内一共出现了 6次。
2个正整数 L 和 R，之间用一个空格隔开。1≤L≤R≤100000*/
void ComputeCount()
{
    unsigned left, right;
    cin >> left >> right;
    unsigned count = 0;
    for (unsigned i = left; i <= right; ++i)
    {
        if (i / 10000 == 2)
        {
            count++;
        }
        if ((i / 1000) % 10 == 2)
        {
            count++;
        }
        if ((i / 100) % 10 == 2)
        {
            count++;
        }
        if ((i / 10) % 10 == 2)
        {
            count++;
        }
        if (i % 10 == 2)
        {
            count++;
        }
    }
    cout << count << endl;
}

/*输入一个整数n，请你求出1+2+3+4+....+n的和是多少？*/
void Sum()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += i;
    }
    cout << sum;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int *A, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > i; --j)
        {
            if (A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]);
            }
        }
    }
}
/*输入n个数进行排序，要求先按奇偶后按从小到大的顺序排序。
第一行输入一个整数n，表示总共有多少个数，n<=1000。
第二行输入n个整数，用空格隔开。*/
void Sort()
{
    int n, number;
    cin >> n;
    int count = n;
    int b[count], odd[count], even[count];
    for (int i = 0; i < count; ++i, n--)
    {
        cin >> number;
        b[i] = number;
    }
    int i = 0, j = 0, k = 0;
    while (i < count)
    {
        if (b[i] % 2 == 1)
        {
            odd[j++] = b[i++];
        }
        else
        {
            even[k++] = b[i++];
        }
    }
    BubbleSort(odd, j);
    BubbleSort(even, k);
    i = 0;
    while (i < j)
    {
        b[i] = odd[i];
        i++;
    }
    i = 0;
    while (i < k)
    {
        b[j++] = even[i++];
    }
    for (int i = 0; i < count; ++i)
    {
        cout << b[i] << ' ';
    }
}

/*输入一个字符串，将其中的数字字符移动到非数字字符之后，
并保持数字字符和非数字字符输入时的顺序。
例如：输入字符串“ab4f35gr#a6”,输出为“abfgr#a4356”。输入一行字符串，长度小于100。*/
void SortString()
{
    string s;
    cin >> s;
    char sort[100];
    int count = 0;
    for (auto c : s)
    {
        sort[count++] = c;
    }
    int i, j;
    for (i = 0; i < count; i++)
    {
        for (j = count - 1; j > i; --j)
        {
            // 将数字字符移动到非数字字符之后
            if (!isdigit(sort[j]) && isdigit(sort[j - 1]))
            {
                swap(sort[j], sort[j - 1]);
            }
        }
    }
    i = 0;
    for (auto &c : s)
    {
        c = sort[i++];
    }
    cout << s << endl;
}

/*输入一个整数，判断该整数是否为素数，
若是，输出该整数，若否，输出大于该整数的第一个素数。
（例如，输入为14，输出17，因为17是大于14的第一个素数）*/
bool sushu(int num)
{
    for (int i = 2; i < num; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void judgeSushu()
{
    int num;
    cin >> num;
    if (num < 2)
    {
        cout << 2 << endl; // 0和1都不是素数
        return;
    }
    bool flag = sushu(num);
    if (flag == true)
    {
        cout << num << endl;
        return;
    }
    while (++num)
    {
        flag = sushu(num);
        if (flag == true)
        {
            cout << num << endl;
            break;
        }
    }
}

/*企业发放的奖金根据利润提成。利润低于或等于100000元的，奖金可提10%;
利润高于100000元，低于200000元（100000<I≤200000）时，低于100000元的部分按10％提成，高于100000元的部分，可提成 7.5%;
200000<I≤400000时，低于200000元部分仍按上述办法提成，（下同），高于200000元的部分按5％提成；
400000<I≤600000元时，高于400000元的部分按3％提成；600000<I≤1000000时，高于600000元的部分按1.5%提成；
I>1000000时，超过1000000元的部分按1%提成。从键盘输入当月利润I,求应发奖金总数。*/
void bonus()
{
    int profit;
    cin >> profit;
    int bonus = 0;
    if (profit < 0)
    {
        cerr << 0 << endl;
        return;
    }
    else if (profit <= 100000)
    {
        bonus = profit * 0.1;
    }
    else if (profit <= 200000)
    {
        bonus = (profit - 100000) * 0.075 + 10000;
    }
    else if (profit <= 400000)
    {
        bonus = (profit - 200000) * 0.05 + 10000 + 7500;
    }
    else if (profit <= 600000)
    {
        bonus = (profit - 400000) * 0.03 + 10000 + 7500 + 5000;
    }
    else if (profit <= 1000000)
    {
        bonus = (profit - 600000) * 0.015 + 10000 + 7500 + 5000 + 3000;
    }
    else
    {
        bonus = (profit = 1000000) * 0.01 + 10000 + 7500 + 5000 + 3000 + 1500;
    }
    cout << bonus << endl;
    return;
}

int main()
{
    // Sum_n();
    // Sum_n_1();
    // ReverseString();
    // printDisidable();
    // ComputeCount();
    // Sum();
    // Sort();
    // SortString();
    // judgeSushu();
    bonus();
    return 0;
}