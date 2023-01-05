#include <iostream>
#include "Sales_item.h"

void q_1_2()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2
              << std::endl;
}

void q_1_3() { std::cout << "Hello World" << std::endl; }

void q_1_4()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The multiplication of " << v1 << " and " << v2 << " is "
              << v1 * v2 << std::endl;
}

void q_1_5()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
}

// 注释不能嵌套
void q_1_7()
{
    std::cout << "error /* */";
    /* /* error*/
    // */
}

void q_1_9()
{
    int sum = 0, i = 50;
    while (i < 101)
    {
        sum += i;
        i++;
    }
    std::cout << "the sum of 50 - 100 is " << sum << std::endl;
}

void q_1_10()
{
    int i = 10;
    while (i >= 0)
    {
        std::cout << i << " ";
        i--;
    }
}

void q_1_11()
{
    std::cout << "Enter two number: " << std::endl;
    int val1 = 0, val2 = 0;
    std::cin >> val1 >> val2;
    if (val1 <= val2)
    {
        while (val1 < val2)
        {
            std::cout << val1++ << " ";
        }
    }
    else
    {
        std::cout << "val1 must be smaller than val2" << std::endl;
    }
}

void q_1_16()
{
    int val = 0, sum = 0;
    while (std::cin >> val)
    {
        sum += val;
    }
    std::cout << "The sum of these numbers is " << sum << std::endl;
}

void q_1_17()
{
    int currval = 0, val = 0;
    if (std::cin >> currval)
    {
        int count = 1;
        while (std::cin >> val)
        {
            if (currval == val)
            {
                ++count;
            }
            else
            {
                std::cout << "Current val " << currval << " occurs " << count << " times" << std::endl;
                currval = val;
                count = 1; // 重记计数器
            }
        }
        // 打印最后一个数值出现的次数
        std::cout << "Current val " << currval << " occurs " << count << " times" << std::endl;
    }
}

void q_1_20()
{
    for (Sales_item item; std::cin >> item; std::cout << item << std::endl)
        ;
}

void q_1_21()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    std::cout << "The sum of item1 and item2 is " << item1 + item2 << std::endl;
}

void q_1_22()
{
    Sales_item sum_item, item;
    while (std::cin >> item)
    {
        sum_item += item;
    }
    std::cout << "The sum of sales_item is " << sum_item << std::endl;
}

void q_1_25()
{
    Sales_item totalitem;
    if (std::cin >> totalitem)
    {
        Sales_item item;
        while (std::cin >> item)
        {
            if (totalitem.isbn() == item.isbn())
            {
                totalitem += item;
            }
            else
            {
                std::cout << totalitem << std::endl;
                totalitem = item;
            }
        }
        std::cout << totalitem << std::endl;
    }else{
        std::cout << "no enter"<< std::endl;
        return;
    }
}

int main()
{
    // q_1_2();
    // q_1_3();
    // q_1_4();
    // q_1_5();
    // q_1_7();
    // q_1_9();
    // q_1_10();
    // q_1_11();
    // q_1_16();
    // q_1_17();
    // q_1_20();
    // q_1_21();
    // q_1_22();
    q_1_25();
    return 0;
}
